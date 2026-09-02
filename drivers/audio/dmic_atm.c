/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/*
 * Atmosic PDM/DMIC driver
 *
 * Implements the Zephyr DMIC API (zephyr/include/zephyr/audio/dmic.h).
 *
 * Hardware overview:
 *   - APB registers at DT reg[0]  (CMSDK_AT_APB_PDM_TypeDef layout)
 *   - Ping-pong SRAM  at DT reg[1]  (4 × PP_BUFFER_WORDS × int32_t)
 *   - Single IRQ: fires per locked ping-pong buffer (A/B/C/D)
 *   - PP_BUFFER_WORDS = 16 (read-only BUFFER_DEPTH reset value)
 *   - 16-bit mode packs two PCM samples into each buffer word
 *
 * Supported configurations:
 *   - PCM rate : 8 kHz or 16 kHz
 *   - PCM width: 16-bit, 20-bit, or 24-bit
 *   - Channels : mono (LEFT) only
 */

#define DT_DRV_COMPAT atmosic_atm_pdm

#include <zephyr/audio/dmic.h>
#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/policy.h>
#include <zephyr/drivers/pinctrl.h>
#include <zephyr/drivers/gpio.h>
#include <string.h>

#include "arch.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "at_apb_pdm_regs_core_macro.h"
#include "at_apb_clkrstgen_regs_core_macro.h"

LOG_MODULE_REGISTER(dmic_atm, CONFIG_AUDIO_DMIC_LOG_LEVEL);

#define ATM_PDM_HAS_MIC_BIAS_GPIO DT_INST_NODE_HAS_PROP(0, mic_bias_gpios)

/* One ping-pong buffer depth in 32-bit words (hardware fixed at 16). */
#define PP_BUFFER_WORDS 16

/* I2S_SEL register values (shared with I2S driver) */
#define I2S_SEL_16MHZ   0U
#define I2S_SEL_32MHZ   1U
#define I2S_SEL_HZ(sel) ((sel) == I2S_SEL_16MHZ ? 16000000U : 32000000U)

/*
 * PCM_RATE_SEL encoding from the hardware register field description:
 *   0 = 6 kHz, 1 = 8 kHz, 2 = 12 kHz, 3 = 16 kHz, …
 */
#define PCM_RATE_SEL_8KHZ  1
#define PCM_RATE_SEL_16KHZ 3

/* PCM_BIT_WIDTH encoding from the hardware register field description:
 *   0 = 16-bit, 1 = 20-bit, 2/3 = 24-bit
 */
#define PCM_BIT_WIDTH_SEL_16BIT 0
#define PCM_BIT_WIDTH_SEL_20BIT 1
#define PCM_BIT_WIDTH_SEL_24BIT 2

#define PCM_WIDTH_16BIT 16
#define PCM_WIDTH_20BIT 20
#define PCM_WIDTH_24BIT 24

/* Interrupt mask bits for the four ping-pong ready signals */
#define PP_RDY_MASK                                                                                \
	(PDM_INTERRUPTS__INTRPT7__MASK | PDM_INTERRUPTS__INTRPT6__MASK |                           \
	 PDM_INTERRUPTS__INTRPT3__MASK | PDM_INTERRUPTS__INTRPT2__MASK)

/* Interrupt mask bits for overflow/error signals */
#define PP_ERR_MASK                                                                                \
	(PDM_INTERRUPTS__INTRPT9__MASK | PDM_INTERRUPTS__INTRPT8__MASK |                           \
	 PDM_INTERRUPTS__INTRPT5__MASK | PDM_INTERRUPTS__INTRPT4__MASK)

/* Interrupt clear bits for all PP signals */
#define PP_CLEAR_MASK (PP_RDY_MASK | PP_ERR_MASK)

#define PDM_GAIN_STEP_MDB 500 /* 0.5 dB per LUT step */

BUILD_ASSERT(CONFIG_ATM_DMIC_GAIN_DB % PDM_GAIN_STEP_MDB == 0,
	     "CONFIG_ATM_DMIC_GAIN_DB must be in 0.5 dB steps (multiples of 500 mB)");

/* Register struct mapped to DT reg[0] base address */
struct atm_pdm_regs {
	uint32_t CONTROL;
	uint32_t FILTER_CONFIG;
	uint32_t FILTER_CONFIG1;
	uint32_t GAIN_CONTROL_CONFIG;
	uint32_t PCM_SAMPLE;
	uint32_t FIFO_DEBUG;
	uint32_t INTERRUPTS;
	uint32_t INTERRUPT_MASK;
	uint32_t INTERRUPT_CLEAR;
	uint32_t BUFFER_ACCESS_MODE;
	uint32_t AUTO_COUNTER;
	uint32_t BUFFER_DEPTH;
};

/* Ping-pong SRAM layout at DT reg[1] base address */
struct atm_pdm_pp {
	volatile int32_t buf_a[PP_BUFFER_WORDS];
	volatile int32_t buf_b[PP_BUFFER_WORDS];
	volatile int32_t buf_c[PP_BUFFER_WORDS];
	volatile int32_t buf_d[PP_BUFFER_WORDS];
};

/* Compile-time configuration (from DT) */
struct atm_pdm_cfg {
	struct atm_pdm_regs *regs;
	struct atm_pdm_pp *pp;
	unsigned int irq;
	unsigned int irq_prio;
	uint32_t aud_clk_hz;
	uint32_t clk_freq_hz;
	void (*irq_config_fn)(void);
	/* Pin configuration via the pinctrl driver */
	const struct pinctrl_dev_config *pcfg;
	/* Releasing pins to GPIO for power saving needs compile-time pin
	 * constants, so it stays a per-instance function (the pins are derived
	 * from the pinctrl-0 entries). */
	void (*pin_release_fn)(void);
#if ATM_PDM_HAS_MIC_BIAS_GPIO
	const struct gpio_dt_spec mic_bias;
#endif
};

/* Runtime state */
struct atm_pdm_data {
	enum dmic_state state;
	struct k_mem_slab *slab;
	struct k_msgq rx_queue;
	void *rx_queue_buf[CONFIG_ATM_DMIC_RX_QUEUE_SIZE];
	uint8_t pcm_rate_sel;
	uint8_t pcm_width;
	uint8_t pcm_bit_width_sel;
	uint32_t block_size;
};

/* -------------------------------------------------------------------------
 * Helpers
 * -----------------------------------------------------------------------*/

static int rate_to_sel(uint32_t rate_hz, uint8_t *sel)
{
	switch (rate_hz) {
	case 8000:
		*sel = PCM_RATE_SEL_8KHZ;
		return 0;
	case 16000:
		*sel = PCM_RATE_SEL_16KHZ;
		return 0;
	default:
		return -ENOTSUP;
	}
}

/*
 * Copy the current PP window buffer to a mem_slab block and enqueue it.
 * Called from ISR context.
 *
 * In NSPE, the hardware always maps the currently-ready PP
 * buffer to the NS base address (reg[1], buf_a slot).  Reading any
 * other offset hangs the AHB bus.  Always read from buf_a regardless
 * of which INTRPT fired.
 */
static void pp_deliver(struct atm_pdm_data *drv_data, const volatile int32_t *pp_buf)
{
	void *block;

	if (k_mem_slab_alloc(drv_data->slab, &block, K_NO_WAIT) != 0) {
		return;
	}

	if (drv_data->pcm_width == PCM_WIDTH_16BIT) {
		int16_t *dst = block;

		for (int i = 0; i < PP_BUFFER_WORDS; i++) {
			/* DMA_MODE exposes a FIFO-like alias at buf_a.  Each read from
			 * buf_a[0] advances the hardware auto-counter; each word contains
			 * two 16-bit samples.  SWAP_SAMPLES is enabled below, so the
			 * earlier sample is in the upper half and the later sample is in
			 * the lower half. */
			uint32_t packed = (uint32_t)pp_buf[0];
			dst[2 * i] = (int16_t)(packed >> 16);
			dst[2 * i + 1] = (int16_t)(packed & 0xffff);
		}
	} else {
		/* 20-bit or 24-bit: use the same FIFO read semantics. */
		int32_t *dst = block;

		for (int i = 0; i < PP_BUFFER_WORDS; i++) {
			dst[i] = pp_buf[0];
		}
	}

	if (k_msgq_put(&drv_data->rx_queue, &block, K_NO_WAIT) != 0) {
		k_mem_slab_free(drv_data->slab, block);
	}
}

/* -------------------------------------------------------------------------
 * ISR
 * -----------------------------------------------------------------------*/

static void dmic_atm_isr(const struct device *dev)
{
	const struct atm_pdm_cfg *cfg = dev->config;
	struct atm_pdm_data *drv_data = dev->data;
	struct atm_pdm_regs *regs = cfg->regs;

	uint32_t raw = regs->INTERRUPTS;
	uint32_t status = raw & (PP_RDY_MASK | PP_ERR_MASK);
	uint32_t ready = status & PP_RDY_MASK;
	uint32_t clear = raw & ~PP_RDY_MASK;

	if (status & PP_ERR_MASK) {
		clear |= PP_CLEAR_MASK;
	} else if (ready == PP_RDY_MASK) {
		/* All four ping-pong buffers ready at once means the ISR fell
		 * far enough behind that the whole ring is stale.
		 * Drop and re-sync rather than
		 * deliver corrupted/out-of-order audio. */
		clear |= PP_CLEAR_MASK;
	} else if (ready) {
		/* Deliver exactly one buffer and clear ONLY the single lowest
		 * ready bit. Any other ready bit stays pending and keeps the
		 * IRQ asserted, so the ISR re-enters and delivers that buffer
		 * too - nothing is dropped.
		 * In NSPE the hardware maps the next ready buffer into the
		 * buf_a window, so every delivery reads buf_a. */
		pp_deliver(drv_data, cfg->pp->buf_a);
		clear |= ready & (~ready + 1U);
	}

	regs->INTERRUPT_CLEAR = clear;
	regs->INTERRUPT_CLEAR = 0;
	(void)regs->INTERRUPTS;
}

/* -------------------------------------------------------------------------
 * DMIC API: configure
 * -----------------------------------------------------------------------*/

static int dmic_atm_configure(const struct device *dev, struct dmic_cfg *config)
{
	struct atm_pdm_data *drv_data = dev->data;

	if (drv_data->state == DMIC_STATE_ACTIVE) {
		LOG_ERR("Cannot reconfigure while active");
		return -EBUSY;
	}

	if (config->channel.req_num_chan != 1) {
		LOG_ERR("Only mono (1 channel) supported");
		return -ENOTSUP;
	}

	if (config->streams == NULL) {
		return -EINVAL;
	}

	struct pcm_stream_cfg *stream = &config->streams[0];

	if (stream->pcm_width != PCM_WIDTH_16BIT && stream->pcm_width != PCM_WIDTH_20BIT &&
	    stream->pcm_width != PCM_WIDTH_24BIT) {
		LOG_ERR("Only 16-bit, 20-bit, or 24-bit PCM supported");
		return -ENOTSUP;
	}

	uint8_t rate_sel;

	if (rate_to_sel(stream->pcm_rate, &rate_sel) != 0) {
		LOG_ERR("Unsupported PCM rate %u Hz (8000 or 16000 only)", stream->pcm_rate);
		return -ENOTSUP;
	}

	if (stream->mem_slab == NULL) {
		return -EINVAL;
	}

	uint32_t expected_block_size = (stream->pcm_width == PCM_WIDTH_16BIT)
					       ? (PP_BUFFER_WORDS * 2U * sizeof(int16_t))
					       : (PP_BUFFER_WORDS * sizeof(int32_t));
	if (stream->block_size != expected_block_size) {
		LOG_ERR("Invalid block_size=%u for %u-bit PCM; expected %u", stream->block_size,
			stream->pcm_width, expected_block_size);
		return -EINVAL;
	}

	drv_data->pcm_rate_sel = rate_sel;
	drv_data->pcm_width = stream->pcm_width;
	drv_data->pcm_bit_width_sel =
		(stream->pcm_width == PCM_WIDTH_16BIT)   ? PCM_BIT_WIDTH_SEL_16BIT
		: (stream->pcm_width == PCM_WIDTH_20BIT) ? PCM_BIT_WIDTH_SEL_20BIT
							 : PCM_BIT_WIDTH_SEL_24BIT;
	drv_data->block_size = stream->block_size;
	drv_data->slab = stream->mem_slab;

	k_msgq_init(&drv_data->rx_queue, (char *)drv_data->rx_queue_buf, sizeof(void *),
		    CONFIG_ATM_DMIC_RX_QUEUE_SIZE);

	config->channel.act_num_chan = 1;
	config->channel.act_num_streams = 1;

	drv_data->state = DMIC_STATE_CONFIGURED;
	return 0;
}

/* -------------------------------------------------------------------------
 * DMIC API: trigger
 * -----------------------------------------------------------------------*/

static int dmic_atm_trigger(const struct device *dev, enum dmic_trigger cmd)
{
	const struct atm_pdm_cfg *cfg = dev->config;
	struct atm_pdm_data *drv_data = dev->data;
	struct atm_pdm_regs *regs = cfg->regs;

	switch (cmd) {
	case DMIC_TRIGGER_START:
		if (drv_data->state != DMIC_STATE_CONFIGURED &&
		    drv_data->state != DMIC_STATE_PAUSED) {
			return -EIO;
		}

		/* Prevent deep sleep while PDM is capturing; the PDM clock is
		 * gated in SUSPEND_TO_RAM which stops PP buffers from filling. */
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);

#if ATM_PDM_HAS_MIC_BIAS_GPIO
		bool was_paused = drv_data->state == DMIC_STATE_PAUSED;
		/* Power on the external PDM microphone via MIC_BIAS GPIO before
		 * starting the clock, so the mic is ready when CLK begins. */
		int mic_ret = gpio_pin_set_dt(&cfg->mic_bias, 1);
		if (mic_ret) {
			LOG_ERR("MIC_BIAS enable failed (%d)", mic_ret);
			pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
			return mic_ret;
		}
		if (!was_paused && CONFIG_ATM_DMIC_MIC_POWERUP_DELAY_MS > 0) {
			k_sleep(K_MSEC(CONFIG_ATM_DMIC_MIC_POWERUP_DELAY_MS));
		}
#endif

		/* Enable PDM peripheral APB register clock and release soft-reset.
		 */
		WRPR_CTRL_SET(CMSDK_PDM0_NONSECURE, WRPR_CTRL__CLK_ENABLE);

		/* Enable PDM digital-processor clock via CLK_AUD_CTRL.
		 * The WRPR clock only gates the APB register bus; the PDM DP
		 * (digital processor) is clocked separately through CLK_AUD_CTRL.
		 * Without PDM_CLK_ENABLE=1 the DP never runs and PP buffers never
		 * fill, so INTERRUPTS stays 0 indefinitely.
		 * Matches bare metal pdm_ctrl_start for CLKRSTGEN index=0 (ASIC),
		 * pcm_rate % 2 == 1 (8 kHz / 16 kHz) branch.
		 */
		uint32_t i2s_sel = CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__READ(
			CMSDK_CLKRSTGEN_NONSECURE->CLK_AUD_CTRL);
		uint32_t actual_ref_hz = I2S_SEL_HZ(i2s_sel);
		uint32_t expected_ref_hz = cfg->aud_clk_hz;

		/* Auto-select PDM_SEL: ÷1 if refs match, ÷2 if actual is 2× expected. */
		uint8_t pdm_sel;
		if (actual_ref_hz == expected_ref_hz) {
			pdm_sel = 0U; /* ÷1 */
		} else if (actual_ref_hz == (expected_ref_hz * 2U)) {
			pdm_sel = 1U; /* ÷2 */
		} else {
			LOG_ERR("audio ref %u Hz (I2S_SEL=%u) is not 1x or 2x of DT "
				"clocks phandle %u Hz - cannot adapt",
				actual_ref_hz, i2s_sel, expected_ref_hz);
			pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
			return -EINVAL;
		}

		/* Enable PDM DP clock via CLK_AUD_CTRL. I2S_SEL is shared with the
		 * I2S driver — read-modify-write to preserve it. PDM_SEL is set
		 * based on the comparison above. I2S_CLK_ENABLE must be set
		 * (gates the reference clock for PDM DP). Per field docs,
		 * selection only when disabled: disable first, then enable.
		 */
		{
			uint32_t aud = CMSDK_CLKRSTGEN_NONSECURE->CLK_AUD_CTRL;
			CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__MODIFY(aud, pdm_sel);
			CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__CLR(aud);
			CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__CLR(aud);
			CMSDK_CLKRSTGEN_NONSECURE->CLK_AUD_CTRL = aud;
			CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__SET(aud);
			CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__SET(aud);
			CMSDK_CLKRSTGEN_NONSECURE->CLK_AUD_CTRL = aud;
		}

		/* Configure PDM clock and data pins via pinctrl */
		{
			int perr = pinctrl_apply_state(cfg->pcfg, PINCTRL_STATE_DEFAULT);
			if (perr) {
				LOG_ERR("PDM pinctrl apply failed (%d)", perr);
				pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
				return perr;
			}
		}

		/* PDM clock divider: f_pclk is the current backplane clock.
		 * Bare metal always sets bp=16MHz before this, but in Zephyr we
		 * read the live value so we work at any bp rate.
		 * pdm_clk_sel = (f_pclk / target_clk) - 1; valid range 3–31.
		 */
		uint32_t f_pclk_hz = actual_ref_hz / (pdm_sel + 1U);
		uint32_t f_pclk_khz = f_pclk_hz / 1000U;
		uint32_t clk_khz = cfg->clk_freq_hz / 1000U;
		uint32_t pdm_clk_u = ((f_pclk_khz + clk_khz / 2U) / clk_khz) - 1U;

		if (pdm_clk_u > 31U) {
			/* bp clock too fast for requested PDM rate; use slowest valid
			 * divider (sel=31 → f_pdm = f_pclk/32). */
			pdm_clk_u = 31U;
			LOG_WRN("PDM CLK_SEL clamped to 31 (f_pclk %u kHz, "
				"actual %u kHz, requested %u kHz)",
				f_pclk_khz, f_pclk_khz / 32U, clk_khz);
		} else if (pdm_clk_u < 3U) {
			LOG_ERR("PDM CLK_SEL %u below minimum 3 "
				"(f_pclk %u kHz, target %u kHz)",
				pdm_clk_u, f_pclk_khz, clk_khz);
			cfg->pin_release_fn();
			pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
			return -ENOTSUP;
		}
		uint8_t pdm_clk = (uint8_t)pdm_clk_u;

		uint32_t ctrl_val = PDM_CONTROL__ENABLE_DP__MASK | PDM_CONTROL__SWAP_SAMPLES__MASK |
				    PDM_CONTROL__PDM_CLK_SEL__WRITE(pdm_clk) |
				    PDM_CONTROL__PCM_RATE_SEL__WRITE(drv_data->pcm_rate_sel) |
				    PDM_CONTROL__PCM_BIT_WIDTH__WRITE(drv_data->pcm_bit_width_sel);

		IF_ENABLED(CONFIG_ATM_DMIC_CAPTURE_ON_RISING,
			   (ctrl_val |= PDM_CONTROL__CAPTURE_ON_RISING__MASK;))

		PDM_FILTER_CONFIG__HPF_ORD__MODIFY(regs->FILTER_CONFIG,
						   CONFIG_ATM_DMIC_HPF_ORDER_SEL);
		PDM_FILTER_CONFIG__HPF_BW__MODIFY(regs->FILTER_CONFIG, CONFIG_ATM_DMIC_HPF_BW_SEL);

		int gain_code = (int)PDM_GAIN_CONTROL_CONFIG__CODE__RESET_VALUE +
				(CONFIG_ATM_DMIC_GAIN_DB / PDM_GAIN_STEP_MDB);
		PDM_GAIN_CONTROL_CONFIG__CODE__MODIFY(regs->GAIN_CONTROL_CONFIG,
						      (uint32_t)gain_code);

		regs->INTERRUPT_MASK = PP_RDY_MASK | PP_ERR_MASK;

		/* Enable FIFO-like DMA access mode: the hardware maps the current
		 * ready buffer to pp->buf_a[0..PP_BUFFER_WORDS-1] on every PP_RDY ISR,
		 * and auto-clears the PP_RDY interrupt after the last sample read.
		 * Without dma_mode=1 the NS PP SRAM window at 0x40300000 is not
		 * properly armed and reads stall the AHB bus. */
		PDM_BUFFER_ACCESS_MODE__DMA_MODE__SET(regs->BUFFER_ACCESS_MODE);

		NVIC_ClearPendingIRQ(cfg->irq);
		/* Enable the datapath and arm the IRQ without an intervening log. */
		regs->CONTROL = ctrl_val;

		drv_data->state = DMIC_STATE_ACTIVE;
		irq_enable(cfg->irq);
		return 0;

	case DMIC_TRIGGER_STOP:
		if (drv_data->state != DMIC_STATE_ACTIVE && drv_data->state != DMIC_STATE_PAUSED) {
			return -EIO;
		}
		irq_disable(cfg->irq);
		regs->CONTROL = 0;
		regs->INTERRUPT_MASK = 0;

		/* Release pins and clock */
		cfg->pin_release_fn();
		WRPR_CTRL_SET(CMSDK_PDM0_NONSECURE, WRPR_CTRL__SRESET);
		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);

#if ATM_PDM_HAS_MIC_BIAS_GPIO
		/* Power off the external PDM microphone to save energy. */
		gpio_pin_set_dt(&cfg->mic_bias, 0);
#endif

		/* Flush the receive queue, freeing all blocks */
		void *block;

		while (k_msgq_get(&drv_data->rx_queue, &block, K_NO_WAIT) == 0) {
			k_mem_slab_free(drv_data->slab, block);
		}

		drv_data->state = DMIC_STATE_CONFIGURED;
		return 0;

	case DMIC_TRIGGER_PAUSE:
		if (drv_data->state != DMIC_STATE_ACTIVE) {
			return -EIO;
		}
		regs->INTERRUPT_MASK = PP_ERR_MASK;
		drv_data->state = DMIC_STATE_PAUSED;
		return 0;

	case DMIC_TRIGGER_RELEASE:
		if (drv_data->state != DMIC_STATE_PAUSED) {
			return -EIO;
		}
		regs->INTERRUPT_MASK = PP_RDY_MASK | PP_ERR_MASK;
		drv_data->state = DMIC_STATE_ACTIVE;
		return 0;

	case DMIC_TRIGGER_RESET:
		drv_data->state = DMIC_STATE_INITIALIZED;
		return 0;

	default:
		return -EINVAL;
	}
}

/* -------------------------------------------------------------------------
 * DMIC API: read
 * -----------------------------------------------------------------------*/

static int dmic_atm_read(const struct device *dev, uint8_t stream, void **buffer, size_t *size,
			 int32_t timeout)
{
	struct atm_pdm_data *drv_data = dev->data;
	void *block;
	int ret;

	ARG_UNUSED(stream);

	if (drv_data->state != DMIC_STATE_ACTIVE && drv_data->state != DMIC_STATE_PAUSED) {
		return -EIO;
	}

	ret = k_msgq_get(&drv_data->rx_queue, &block,
			 timeout == SYS_FOREVER_MS ? K_FOREVER : K_MSEC(timeout));
	if (ret != 0) {
		return ret;
	}

	*buffer = block;
	*size = drv_data->block_size;
	return 0;
}

/* -------------------------------------------------------------------------
 * Driver init
 * -----------------------------------------------------------------------*/

static int dmic_atm_init(const struct device *dev)
{
	const struct atm_pdm_cfg *cfg = dev->config;
	struct atm_pdm_data *drv_data = dev->data;

	drv_data->state = DMIC_STATE_INITIALIZED;

	cfg->irq_config_fn();
	irq_disable(cfg->irq);

#if ATM_PDM_HAS_MIC_BIAS_GPIO
	if (!gpio_is_ready_dt(&cfg->mic_bias)) {
		LOG_ERR("MIC_BIAS GPIO device not ready");
		return -ENODEV;
	}
	gpio_pin_configure_dt(&cfg->mic_bias, GPIO_OUTPUT_INACTIVE);
#endif

	return 0;
}

/* -------------------------------------------------------------------------
 * Driver ops
 * -----------------------------------------------------------------------*/

static const struct _dmic_ops dmic_atm_ops = {
	.configure = dmic_atm_configure,
	.trigger = dmic_atm_trigger,
	.read = dmic_atm_read,
};

/* -------------------------------------------------------------------------
 * Device instantiation (single instance — DT has one pdm0 node)
 * -----------------------------------------------------------------------*/

#define ATM_PDM_IRQ_CONFIG_FN(n)                                                                   \
	static void irq_config_##n(void)                                                           \
	{                                                                                          \
		IRQ_CONNECT(DT_INST_IRQN(n), DT_INST_IRQ(n, priority), dmic_atm_isr,               \
			    DEVICE_DT_INST_GET(n), 0);                                             \
	}

/*
 * The pinctrl-0 entries provide the pins: clock group at index 0, data group
 * at index 1 (cell 0 of each pinmux is the pin number). Releasing the pins to
 * GPIO for power saving needs compile-time pin constants, so it stays a
 * per-instance function — mirroring the Atmosic SPI/I2C pinctrl drivers.
 */
#define PDM_CLK_PINCTRL_IDX  0
#define PDM_DATA_PINCTRL_IDX 1
#define PDM_GET_PIN(n, idx)  DT_PROP_BY_IDX(DT_INST_PINCTRL_0(n, idx), pinmux, 0)
#define ATM_PDM_PIN_FNS(n)                                                                         \
	static void pin_release_##n(void)                                                          \
	{                                                                                          \
		PIN_SELECT(PDM_GET_PIN(n, PDM_CLK_PINCTRL_IDX), GPIO);                             \
		PIN_SELECT(PDM_GET_PIN(n, PDM_DATA_PINCTRL_IDX), GPIO);                            \
	}

#define ATM_PDM_INIT(n)                                                                            \
	ATM_PDM_IRQ_CONFIG_FN(n)                                                                   \
	PINCTRL_DT_INST_DEFINE(n);                                                                 \
	ATM_PDM_PIN_FNS(n)                                                                         \
                                                                                                   \
	static struct atm_pdm_data atm_pdm_data_##n;                                               \
                                                                                                   \
	static const struct atm_pdm_cfg atm_pdm_cfg_##n = {                                        \
		.regs = (struct atm_pdm_regs *)DT_INST_REG_ADDR_BY_IDX(n, 0),                      \
		.pp = (struct atm_pdm_pp *)DT_INST_REG_ADDR_BY_IDX(n, 1),                          \
		.irq = DT_INST_IRQN(n),                                                            \
		.irq_prio = DT_INST_IRQ(n, priority),                                              \
		.aud_clk_hz = DT_INST_PROP_BY_PHANDLE(n, clocks, clock_frequency),                 \
		.clk_freq_hz = DT_INST_PROP(n, clock_frequency),                                   \
		.irq_config_fn = irq_config_##n,                                                   \
		.pcfg = PINCTRL_DT_INST_DEV_CONFIG_GET(n),                                         \
		.pin_release_fn = pin_release_##n,                                                 \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(n, mic_bias_gpios),                               \
			   (.mic_bias = GPIO_DT_SPEC_INST_GET(n, mic_bias_gpios),)) };             \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(n, dmic_atm_init, NULL, &atm_pdm_data_##n, &atm_pdm_cfg_##n,         \
			      POST_KERNEL, CONFIG_AUDIO_DMIC_INIT_PRIORITY, &dmic_atm_ops);

DT_INST_FOREACH_STATUS_OKAY(ATM_PDM_INIT)
