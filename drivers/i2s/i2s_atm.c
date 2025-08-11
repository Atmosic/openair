/*
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT atmosic_atm_i2s

#include <stdio.h>
#include <zephyr/drivers/i2s.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/ring_buffer.h>

#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif

#include "arch.h"
#include "at_clkrstgen.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "at_i2s_regs_core_macro.h"
#include "atm_utils_math.h"
#include "i2s_atm.h"
#include "dma.h"
LOG_MODULE_REGISTER(i2s_atm, CONFIG_I2S_LOG_LEVEL);

BUILD_ASSERT(IS_ENABLED(CONFIG_ATM_DMA), "I2S requires ATM DMA");

#define PINGPONG_BUF_SIZE 16
#define SRC_CNT_DEFAULT   1
#define SNK_CNT_DEFAULT   1

enum {
	PINGPONG_BUF0,
	PINGPONG_BUF1,
	PINGPONG_BUF2,
	PINGPONG_BUF,
	PINGPONG_BUF_NUM,
};

enum {
	SRC_SNK_PCM,
	SRC_SNK_AHB,
	SRC_SNK_LPBK,
};

#define I2S_TX_BIT  0
#define I2S_RX_BIT  1
#define I2S_TX_MASK (1 << I2S_TX_BIT)
#define I2S_RX_MASK (1 << I2S_RX_BIT)

typedef enum {
	I2S_MODE_PCM,
	I2S_MODE_LEFT_JUSTIFIED,
	I2S_MODE_RIGHT_JUSTIFIED,
} i2s_mode_t;

#define IRQ_SOURCE_UF                                                                              \
	(ATI2S_I2S_IRQM0__PP0_UF__MASK | ATI2S_I2S_IRQM0__PP1_UF__MASK |                           \
	 ATI2S_I2S_IRQM0__PP2_UF__MASK | ATI2S_I2S_IRQM0__PP3_UF__MASK)

#define IRQ_SOURCE_EP_THRSHLD ATI2S_I2S_IRQM0__PP_EP_THRSHLD__MASK

#define IRQ_SOURCE_TX IRQ_SOURCE_UF

#define IRQ_STATUS_UF                                                                              \
	(ATI2S_I2S_IRQ0__PP0_UF__MASK | ATI2S_I2S_IRQ0__PP1_UF__MASK |                             \
	 ATI2S_I2S_IRQ0__PP2_UF__MASK | ATI2S_I2S_IRQ0__PP3_UF__MASK)

#define IRQ_STATUS_EP_THRSHLD ATI2S_I2S_IRQ0__PP_EP_THRSHLD__MASK

#define IRQ_STATUS_TX IRQ_STATUS_UF
typedef struct i2s_cfg_txrx_s {
	uint16_t sck2ws_rt; // serial clock (sck) to word select (ws) ratio
	uint16_t ck2sck_rt; // clock to serial clock ratio
	bool ws_nedge_st;   // tx/rx starts on negative edge of word select
	bool sck_nedge_sd;  // drive/latch tx/rx sd on positive/negative edge of sd
	bool ws_init;       // ws is (de)asserted at starting half of justified mode
	bool mstr_sckws;    // sck and ws (master = 1, slave = 0)
	bool sck_nedge_ws;  // drive/latch tx/rx sd on positive/negative edge of ws
	uint8_t sdw;        // width of valid serial data (1 to 32)
	uint8_t sd_offset;  // cycles (0 to 15) after ws edge to wait before data
} i2s_cfg_txrx_t;

typedef struct i2s_cfg_s {
	i2s_cfg_txrx_t trx;
	i2s_mode_t mode;
	uint8_t sck_init_cnt;
	uint32_t aud_ctrl_i2s;
} i2s_cfg_t;

struct trx_block {
	void *buffer;
	size_t size;
};
struct i2s_atm_stream {
	enum i2s_state state;
	struct k_mem_slab *mem_slab;
	struct ring_buf *act_q; // Queue of data blocks currently being transmitted.
#ifdef CONFIG_ATM_FIFO_TX_ISR
	struct ring_buf *rdy_q;
#endif
	struct trx_block cur_block;
	bool stop_drain;
};

struct i2s_atm_config {
	void (*fn_cfg_tx_pin)(void);
	uint32_t sys_clk_freq;
};
struct i2s_atm_data {
	i2s_cfg_t cfg;
	struct i2s_config const *i2s_cfg;
	struct i2s_atm_stream tx;
	struct device const *dev;
	struct k_work tx_work;
	bool dma_stop;
	bool uf_err;
	void (*tx_write_cb)(struct device const *dev, void *arg);
	void *tx_write_cb_arg;
	bool in_write_cb;
	uint16_t uf_err_count;
#ifdef CONFIG_PM
	bool pm_tx_constraint_on;
#endif
};

#define RING_BUF_GET(ring, out) ring_buf_get((ring), (uint8_t *)&out, sizeof(out))
#define RING_BUF_PUT(ring, in)  ring_buf_put((ring), (uint8_t *)&(in), sizeof(in))

#ifdef CONFIG_PM
static void i2s_atm_pm_tx_constraint_set(struct device const *dev)
{
	struct i2s_atm_data *data = dev->data;

	if (!data->pm_tx_constraint_on) {
		data->pm_tx_constraint_on = true;
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}

static void i2s_atm_pm_tx_constraint_release(struct device const *dev)
{
	struct i2s_atm_data *data = dev->data;

	if (data->pm_tx_constraint_on) {
		data->pm_tx_constraint_on = false;
		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}
#endif

RING_BUF_DECLARE(tx_act_q, sizeof(struct trx_block) * CONFIG_I2S_TX_BLOCK_NUM);
#ifdef CONFIG_ATM_FIFO_TX_ISR
RING_BUF_DECLARE(tx_rdy_q, sizeof(void *) * CONFIG_I2S_TX_BLOCK_NUM);
static __noinit char __aligned(WB_UP(32)) _k_mem_slab_buf_tx_0_mem[(CONFIG_I2S_TX_BLOCK_NUM)
    * WB_UP(CONFIG_I2S_BLOCK_SIZE)];
static STRUCT_SECTION_ITERABLE(k_mem_slab, tx_0_mem_slab) = Z_MEM_SLAB_INITIALIZER(
	tx_0_mem_slab, _k_mem_slab_buf_tx_0_mem, WB_UP(CONFIG_I2S_BLOCK_SIZE),
	CONFIG_I2S_TX_BLOCK_NUM);
#endif

static int i2s_config_convert(struct device const *dev, const struct i2s_config *cfg,
			      i2s_cfg_t *cfg_atm)
{
	i2s_cfg_txrx_t *trx = &cfg_atm->trx;

	switch (cfg->format & I2S_FMT_DATA_FORMAT_MASK) {
	case I2S_FMT_DATA_FORMAT_I2S: {
		trx->ws_nedge_st = true;
		trx->sck_nedge_sd = false;
		trx->sck_nedge_ws = false;
		trx->sd_offset = 1;
		cfg_atm->mode = I2S_MODE_LEFT_JUSTIFIED;
	} break;
	case I2S_FMT_DATA_FORMAT_PCM_SHORT:
	case I2S_FMT_DATA_FORMAT_PCM_LONG: {
		trx->ws_nedge_st = false;
		trx->sck_nedge_sd = true;
		trx->sck_nedge_ws = true;
		trx->ws_init = true;
		trx->sd_offset = 1;
		cfg_atm->mode = I2S_MODE_PCM;
	} break;
	case I2S_FMT_DATA_FORMAT_LEFT_JUSTIFIED: {
		trx->ws_nedge_st = false;
		trx->sck_nedge_sd = false;
		trx->sck_nedge_ws = false;
		trx->ws_init = false;
		cfg_atm->mode = I2S_MODE_LEFT_JUSTIFIED;
	} break;
	case I2S_FMT_DATA_FORMAT_RIGHT_JUSTIFIED: {
		trx->ws_nedge_st = false;
		trx->sck_nedge_sd = false;
		trx->sck_nedge_ws = false;
		trx->ws_init = false;
		cfg_atm->mode = I2S_MODE_RIGHT_JUSTIFIED;
	} break;
	default:
		LOG_ERR("Unsupported data format");
		return -EINVAL;
	}

	trx->sdw = cfg->word_size;
	if (cfg->word_size != 16) {
		LOG_ERR("Unsupported word size");
		return -EINVAL;
	}
	trx->mstr_sckws = !(cfg->options & I2S_OPT_FRAME_CLK_SLAVE);

#define I2S_16M_CLK 0
#define I2S_32M_CLK 1
	uint32_t i2s_clks[] = {
		[I2S_16M_CLK] = 16000000,
		[I2S_32M_CLK] = 32000000,
	};
	int i2s_clk_cnt = ARRAY_SIZE(i2s_clks);
	if (((struct i2s_atm_config *)dev->config)->sys_clk_freq < 32000000) {
		i2s_clk_cnt = 1;
	}

	uint16_t ws_cnt[] = {
#if CONFIG_I2S_WSCNT
		CONFIG_I2S_WSCNT
#else
		16, 24, 32
#endif
	};

	uint32_t nearest_diff = 0xffffffff;
	for (int i = 0; i < i2s_clk_cnt; i++) {
		for (int j = 0; j < ARRAY_SIZE(ws_cnt); j++) {
			if (ws_cnt[j] < trx->sd_offset + trx->sdw) {
				continue;
			}
			uint16_t ck2sck = DIV_ROUND_CLOSEST(i2s_clks[i] / (ws_cnt[j] * 2),
							    cfg->frame_clk_freq);
			uint32_t real_frame_freq = i2s_clks[i] / ck2sck / (ws_cnt[j] * 2);
			uint32_t diff = ATM_ABS(real_frame_freq - cfg->frame_clk_freq);
			LOG_DBG("i2s_clks[%d] = %" PRIu32 ", ws_cnt[%d] = %" PRIu16
				", ck2sck = %" PRIu16 ", real_frame_freq = %" PRIu32
				", diff = %" PRIu32,
				i, i2s_clks[i], j, ws_cnt[j], ck2sck, real_frame_freq, diff);
			if (diff < nearest_diff) {
				nearest_diff = diff;
				trx->sck2ws_rt = ws_cnt[j];
				trx->ck2sck_rt = ck2sck;
				cfg_atm->aud_ctrl_i2s = i;
			}
		}
	}
	LOG_DBG("ck2ws_rt = %" PRIu16 ", ck2sck_rt = %" PRIu16 ", aud_ctrl_i2s = %" PRIu32,
		trx->sck2ws_rt, trx->ck2sck_rt, cfg_atm->aud_ctrl_i2s);

	if (nearest_diff == 0xffffffff) {
		LOG_ERR("Unsupported frame clock frequency");
		return -EINVAL;
	}
	return 0;
}

static int i2s_atm_configure(struct device const *dev, enum i2s_dir dir,
			     const struct i2s_config *cfg)
{

	struct i2s_atm_config const *i2s_config = dev->config;
	struct i2s_atm_data *i2s_data = dev->data;
	i2s_cfg_t *cfg_atm = &i2s_data->cfg;
	// Support TX currently
	if ((dir != I2S_DIR_TX) || i2s_data->i2s_cfg || i2s_config_convert(dev, cfg, cfg_atm) < 0) {
		return -EINVAL;
	}

	i2s_data->i2s_cfg = cfg;

	CMSDK_CLKRSTGEN_NONSECURE->CLK_AUD_CTRL =
		CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__WRITE(cfg_atm->aud_ctrl_i2s) |
		CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__WRITE(1);

	WRPR_CTRL_SET(CMSDK_I2S, WRPR_CTRL__CLK_ENABLE | WRPR_CTRL__SRESET);
	WRPR_CTRL_SET(CMSDK_I2S, WRPR_CTRL__CLK_ENABLE);

	CMSDK_I2S_NONSECURE->I2S_CTRL0 =
		ATI2S_I2S_CTRL0__SCK_INIT_CNT__WRITE(cfg_atm->sck_init_cnt) |
		ATI2S_I2S_CTRL0__SRC_SNK__WRITE(SRC_SNK_AHB);

	if (dir == I2S_DIR_TX) {

		CMSDK_I2S_NONSECURE->I2S_CTRL0 |=
			(ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__WRITE(cfg_atm->trx.ws_nedge_st) |
			 ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__WRITE(cfg_atm->trx.sck_nedge_sd) |
			 ATI2S_I2S_CTRL0__WS_INIT_TX__WRITE(cfg_atm->trx.ws_init) |
			 ATI2S_I2S_CTRL0__SRC_CNT__WRITE(SRC_CNT_DEFAULT) |
			 ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__WRITE(cfg_atm->trx.mstr_sckws) |
			 ATI2S_I2S_CTRL0__DMA_EN__WRITE(true) |
			 ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__WRITE(cfg_atm->trx.sck_nedge_ws));

		CMSDK_I2S_NONSECURE->I2S_CTRL1_TX =
			ATI2S_I2S_CTRL1_TX__SCK2WS_RT__WRITE(cfg_atm->trx.sck2ws_rt) |
			ATI2S_I2S_CTRL1_TX__CK2SCK_RT__WRITE(cfg_atm->trx.ck2sck_rt);

		ASSERT_ERR((cfg_atm->trx.sdw <= cfg_atm->trx.sck2ws_rt) &&
			   (cfg_atm->trx.sdw >= 1) && (cfg_atm->trx.sdw <= 32));
		uint8_t pb_cnt1 = (cfg_atm->mode == I2S_MODE_RIGHT_JUSTIFIED)
					  ? (cfg_atm->trx.sck2ws_rt - cfg_atm->trx.sdw)
					  : 0;
		CMSDK_I2S_NONSECURE->I2S_CTRL2_TX =
			ATI2S_I2S_CTRL2_TX__PB_CNT__WRITE(pb_cnt1) |
			ATI2S_I2S_CTRL2_TX__SDW__WRITE(cfg_atm->trx.sdw) |
			ATI2S_I2S_CTRL2_TX__SD_OFFST__WRITE(cfg_atm->trx.sd_offset) |
			ATI2S_I2S_CTRL2_TX__WSSD_MD__WRITE(cfg_atm->mode);

		ATI2S_I2S_CTRL3__USE_MSB_SMPL__CLR(CMSDK_I2S_NONSECURE->I2S_CTRL3);
		CMSDK_I2S_NONSECURE->I2S_IRQM1 = 0;

		i2s_config->fn_cfg_tx_pin();

		i2s_data->tx.state = I2S_STATE_READY;

#ifdef CONFIG_ATM_FIFO_TX_ISR
		if (cfg->mem_slab) {
			LOG_ERR("Set mem_slab to NULL and use i2s_get_tx_buffer() instead.");
			ASSERT_ERR(0);
			return -EINVAL;
		}
		i2s_data->tx.mem_slab = &tx_0_mem_slab;
#else
		ASSERT_ERR(cfg->mem_slab);
		ASSERT_ERR(cfg->mem_slab->info.num_blocks <= CONFIG_I2S_TX_BLOCK_NUM);
		i2s_data->tx.mem_slab = cfg->mem_slab;
#endif
		ASSERT_ERR(!ring_buf_size_get(i2s_data->tx.act_q));

		if (i2s_data->uf_err_count) {
			LOG_INF("last uf_cnt = %" PRIu32, i2s_data->uf_err_count);
		}

		i2s_data->uf_err = true;
		i2s_data->uf_err_count = 0;
		i2s_data->dma_stop = true;

#ifdef CONFIG_ATM_FIFO_TX_ISR
		/* preallocate and put into rdy_q */
		void *mem_block;
		while (!k_mem_slab_alloc(i2s_data->tx.mem_slab, &mem_block, K_NO_WAIT)) {
			uint32_t write_bytes = RING_BUF_PUT(i2s_data->tx.rdy_q, mem_block);
			ASSERT_ERR(sizeof(mem_block) == write_bytes);
		}
#endif
	}

	return 0;
}

static bool is_mem_in_slab(struct k_mem_slab *slab, void *mem)
{
	uintptr_t base = (uintptr_t)slab->buffer;
	uintptr_t end = base + (slab->info.num_blocks * slab->info.block_size);
	uintptr_t ptr = (uintptr_t)mem;

	return (ptr >= base) && (ptr < end);
}

static void i2s_queue_drop(struct device const *dev)
{
	struct i2s_atm_data *i2s_data = dev->data;
	struct i2s_atm_stream *stream = &i2s_data->tx;
	struct trx_block block;
	int ret;
	while ((ret = RING_BUF_GET(stream->act_q, block))) {
		ASSERT_ERR(ret == sizeof(struct trx_block));
		if (is_mem_in_slab(stream->mem_slab, block.buffer)) {
#ifdef CONFIG_ATM_FIFO_TX_ISR
			RING_BUF_PUT(stream->rdy_q, block.buffer);
#else
			k_mem_slab_free(stream->mem_slab, block.buffer);
#endif
		}
	}
}

static void i2s_back_to_ready(struct device const *dev);

static void arrange_queue_for_stop(struct i2s_atm_data *i2s_data)
{
	struct i2s_atm_stream *stream = &i2s_data->tx;

	if (stream->stop_drain) {
		while (!ring_buf_is_empty(i2s_data->tx.act_q)) {
			k_yield();
		}
	}
	i2s_back_to_ready(i2s_data->dev);
}

static bool dma_tx_get_buffer(void **src, size_t *len, void const *ctx)
{
	struct device const *dev = ctx;
	struct i2s_atm_data *i2s_data = dev->data;
	struct i2s_atm_stream *stream = &i2s_data->tx;

	/* put to ready queue*/
	if (stream->cur_block.buffer) {
		if (is_mem_in_slab(stream->mem_slab, stream->cur_block.buffer)) {
#ifdef CONFIG_ATM_FIFO_TX_ISR
			int ret = RING_BUF_PUT(i2s_data->tx.rdy_q, stream->cur_block.buffer);
			ASSERT_INFO(ret == sizeof(void *), ret, stream->cur_block.buffer);
#else
			k_mem_slab_free(stream->mem_slab, stream->cur_block.buffer);
#endif
			stream->cur_block.buffer = NULL;
		}
	}

#ifdef CONFIG_ATM_FIFO_TX_ISR
	/* Ask application for data*/
	if (ring_buf_is_empty(stream->act_q)) {
		if (i2s_data->tx_write_cb) {
			i2s_data->in_write_cb = true;
			i2s_data->tx_write_cb(i2s_data->dev, i2s_data->tx_write_cb_arg);
			i2s_data->in_write_cb = false;
		}
	}
#endif

	/* get next block */
	if (!src || !len || !RING_BUF_GET(stream->act_q, stream->cur_block)) {
		return false;
	}

	/* return the block to DMA ISR */
	*src = stream->cur_block.buffer;
	*len = stream->cur_block.size;

	if (i2s_data->uf_err) {
		i2s_data->uf_err = false;
		CMSDK_I2S_NONSECURE->I2S_IRQM0 = IRQ_SOURCE_TX;
	}
	return true;
}

static void dma_i2s_tx_callback(void const *ctx)
{
	struct device const *dev = ctx;
	struct i2s_atm_data *i2s_data = dev->data;
	i2s_data->dma_stop = true;

#ifndef CONFIG_ATM_FIFO_TX_ISR
	k_work_submit(&i2s_data->tx_work);
}

static void dma_i2s_tx_callback_work(struct k_work *work)
{
	struct i2s_atm_data *i2s_data = CONTAINER_OF(work, struct i2s_atm_data, tx_work);
	struct device const *dev = i2s_data->dev;
#endif
	void *src;
	size_t len;
	if (dma_tx_get_buffer(&src, &len, dev)) {
#ifdef CONFIG_ATM_FIFO_TX_ISR
		if (i2s_data->dma_stop) {
			i2s_data->dma_stop = false;
		}
#else
		i2s_data->dma_stop = false;
#endif
		dma_fifo_tx_async(DMA_FIFO_TX_I2S, src, len, dma_i2s_tx_callback, dev);
		return;
	}
#ifdef CONFIG_ATM_FIFO_TX_ISR
	if (i2s_data->tx.state == I2S_STATE_STOPPING) {
		ASSERT_ERR(ring_buf_is_empty(i2s_data->tx.act_q));
		i2s_back_to_ready(i2s_data->dev);
	}
#else
	if (i2s_data->tx.state == I2S_STATE_STOPPING) {
		arrange_queue_for_stop(i2s_data);
	} else if(!ring_buf_is_empty(i2s_data->tx.act_q)) {
		k_work_submit(&i2s_data->tx_work);
	}
#endif
}

static int i2s_tx_start_transfer(struct device const *dev)
{
	dma_i2s_tx_callback(dev);

	NVIC_ClearPendingIRQ(I2S_IRQn);
	CMSDK_I2S_NONSECURE->I2S_CTRL0 |= ATI2S_I2S_CTRL0__SRC_SNK_EN__WRITE(I2S_TX_MASK);
	NVIC_EnableIRQ(I2S_IRQn);
#ifdef CONFIG_PM
	i2s_atm_pm_tx_constraint_set(dev);
#endif
	return 0;
}

static int i2s_tx_stop_transfer(struct device const *dev)
{
	NVIC_DisableIRQ(I2S_IRQn);
	CMSDK_I2S_NONSECURE->I2S_CTRL0 &= ~ATI2S_I2S_CTRL0__SRC_SNK_EN__WRITE(I2S_TX_MASK);
#ifdef CONFIG_PM
	i2s_atm_pm_tx_constraint_release(dev);
#endif
	return 0;
}

static void i2s_back_to_ready(struct device const *dev)
{
	struct i2s_atm_data *i2s_data = dev->data;
	struct i2s_atm_stream *stream = &i2s_data->tx;
	i2s_queue_drop(dev);
#ifdef CONFIG_ATM_FIFO_TX_ISR
	void *mem_block;
	int size;
	/* free all mem_slab */
	while ((size = RING_BUF_GET(stream->rdy_q, mem_block))) {
		ASSERT_ERR(size == sizeof(void *));
		k_mem_slab_free(stream->mem_slab, mem_block);
	}
#endif
	i2s_data->i2s_cfg = NULL;
	i2s_tx_stop_transfer(i2s_data->dev);
	stream->state = I2S_STATE_READY;
}

static int i2s_atm_trigger(struct device const *dev, enum i2s_dir dir, enum i2s_trigger_cmd cmd)
{
	struct i2s_atm_data *i2s_data = dev->data;
	struct i2s_atm_stream *stream;
	switch (dir) {
	case I2S_DIR_TX:
		stream = &i2s_data->tx;
		break;
	default:
		LOG_ERR("Unsupported direction");
		return -EINVAL;
	}
	switch (cmd) {
	case I2S_TRIGGER_START:
		if (stream->state != I2S_STATE_READY) {
			LOG_ERR("START - Invalid state: %u", stream->state);
			return -EIO;
		}
		stream->state = I2S_STATE_RUNNING;
		stream->stop_drain = false;
		int ret = i2s_tx_start_transfer(dev);
		if (ret < 0) {
			stream->state = I2S_STATE_READY;
			LOG_ERR("Failed to start TX transfer: %d", ret);
			return ret;
		}
		break;
	case I2S_TRIGGER_STOP:
	case I2S_TRIGGER_DRAIN:
		if (stream->state != I2S_STATE_RUNNING) {
			LOG_ERR("Invalid state: %u", stream->state);
			return -EIO;
		}
		if (ring_buf_size_get(stream->act_q) && (cmd == I2S_TRIGGER_DRAIN)) {
			stream->stop_drain = true;
		}
		stream->state = I2S_STATE_STOPPING;
		if (i2s_data->dma_stop) {
			arrange_queue_for_stop(i2s_data);
		}
		break;
	case I2S_TRIGGER_DROP:
		if (stream->state == I2S_STATE_NOT_READY) {
			LOG_ERR("DROP - invalid state: %u", stream->state);
			return -EIO;
		}
		stream->state = I2S_STATE_STOPPING;
		break;
	case I2S_TRIGGER_PREPARE:
		if ((stream->state != I2S_STATE_ERROR) && (stream->state != I2S_STATE_READY) &&
		    (stream->state != I2S_STATE_RUNNING)) {
			return -EIO;
		}
		/* The I2S_TRIGGER_PREPARE clears the error. */
		i2s_data->uf_err_count = 0;
		i2s_back_to_ready(dev);
	}
	return 0;
}

static int i2s_atm_read(struct device const *dev, void **mem_block, size_t *size)
{
	return -ENOTSUP;
}

static int i2s_atm_write(struct device const *dev, void *mem_block, size_t size)
{
	struct i2s_atm_data *dev_data = dev->data;

	if ((dev_data->tx.state != I2S_STATE_RUNNING) && (dev_data->tx.state != I2S_STATE_READY)) {
		LOG_ERR("invalid state %u", dev_data->tx.state);
		return -EINVAL;
	}

	struct trx_block entry = {.buffer = mem_block, .size = size};

	if (!is_mem_in_slab(dev_data->tx.mem_slab, mem_block)) {
		if (!ring_buf_is_empty(dev_data->tx.act_q)) {
			LOG_ERR("Self memory only supports when ring buf is empty.");
			ASSERT_ERR(0);
			return -EINVAL;
		}
	} else if (IS_ENABLED(CONFIG_ATM_FIFO_TX_ISR)) {
		if (dev_data->tx.state == I2S_STATE_READY) {
			LOG_ERR("i2s_write in CONFIG_ATM_FIFO_TX_ISR mode should happen after "
				"i2s trigger start, through the tx_write_cb callback.");
			ASSERT_ERR(0);
			return -EINVAL;
		}
		if (!dev_data->in_write_cb) {
			LOG_ERR("i2s_write in high prio mode should be in write cb");
			ASSERT_ERR(0);
			return -EINVAL;
		}
	}

	if (RING_BUF_PUT(dev_data->tx.act_q, entry) != sizeof(entry)) {
		return -ENOBUFS;
	}

#ifndef CONFIG_ATM_FIFO_TX_ISR
	// If the DMA is not running, start it
	if (dev_data->tx.state == I2S_STATE_RUNNING && dev_data->dma_stop) {
		dma_i2s_tx_callback(dev);
	}
#endif
	return 0;
}

static struct i2s_config const *i2s_atm_config_get(struct device const *dev, enum i2s_dir dir)
{
	struct i2s_atm_data *i2s_data = dev->data;

	return i2s_data->i2s_cfg;
}

#ifdef CONFIG_ATM_FIFO_TX_ISR
const int i2s_atm_get_tx_buffer_size(struct device const *dev)
{
	return CONFIG_I2S_BLOCK_SIZE;
}

void *i2s_atm_get_tx_buffer(struct device const *dev)
{
	struct i2s_atm_data *i2s_data = dev->data;
	void *mem_block;

	return RING_BUF_GET(i2s_data->tx.rdy_q, mem_block) == sizeof(mem_block) ? mem_block : NULL;
}

void i2s_atm_reg_tx_write_cb(struct device const *dev,
			     void (*cb)(struct device const *dev, void *ctx), void *ctx)
{
	struct i2s_atm_data *i2s_data = dev->data;

	i2s_data->tx_write_cb = cb;
	i2s_data->tx_write_cb_arg = ctx;
}
#endif

static struct i2s_driver_api const i2s_atm_driver_api = {
	.config_get = i2s_atm_config_get,
	.configure = i2s_atm_configure,
	.trigger = i2s_atm_trigger,
	.read = i2s_atm_read,
	.write = i2s_atm_write,
};

#define I2S_DATA_INIT(n) static struct i2s_atm_data atm_data;

DT_INST_FOREACH_STATUS_OKAY(I2S_DATA_INIT)
static void I2S_Handler(void)
{
	struct i2s_atm_stream *stream = &atm_data.tx;
	uint32_t irq_status_tx = CMSDK_I2S_NONSECURE->I2S_IRQ0;
	if (irq_status_tx & IRQ_STATUS_UF) {
		if ((stream->state == I2S_STATE_RUNNING) || (stream->state == I2S_STATE_STOPPING)) {
			CMSDK_I2S_NONSECURE->I2S_IRQM0 = 0;
			atm_data.uf_err = true;
#ifdef CONFIG_ATM_FIFO_TX_ISR
			if (stream->cur_block.size == CONFIG_I2S_BLOCK_SIZE) {
#else
			if (stream->cur_block.size == atm_data.i2s_cfg->block_size) {
#endif
				atm_data.uf_err_count++;
			}
		}
		if (irq_status_tx & ATI2S_I2S_IRQ0__PP0_UF__MASK) {
			ATI2S_I2S_IRQC0__PP0_UF__SET(CMSDK_I2S_NONSECURE->I2S_IRQC0);
			ATI2S_I2S_IRQC0__PP0_UF__CLR(CMSDK_I2S_NONSECURE->I2S_IRQC0);
		} else if (irq_status_tx & ATI2S_I2S_IRQ0__PP1_UF__MASK) {
			ATI2S_I2S_IRQC0__PP1_UF__SET(CMSDK_I2S_NONSECURE->I2S_IRQC0);
			ATI2S_I2S_IRQC0__PP1_UF__CLR(CMSDK_I2S_NONSECURE->I2S_IRQC0);
		} else if (irq_status_tx & ATI2S_I2S_IRQ0__PP2_UF__MASK) {
			ATI2S_I2S_IRQC0__PP2_UF__SET(CMSDK_I2S_NONSECURE->I2S_IRQC0);
			ATI2S_I2S_IRQC0__PP2_UF__CLR(CMSDK_I2S_NONSECURE->I2S_IRQC0);
		} else if (irq_status_tx & ATI2S_I2S_IRQ0__PP3_UF__MASK) {
			ATI2S_I2S_IRQC0__PP3_UF__SET(CMSDK_I2S_NONSECURE->I2S_IRQC0);
			ATI2S_I2S_IRQC0__PP3_UF__CLR(CMSDK_I2S_NONSECURE->I2S_IRQC0);
		}
	}
}

static int i2s_atm_init(struct device const *dev)
{
	struct i2s_atm_data *i2s_data = dev->data;
	i2s_data->tx.act_q = &tx_act_q;
#ifdef CONFIG_ATM_FIFO_TX_ISR
	i2s_data->tx.rdy_q = &tx_rdy_q;
#endif
	i2s_data->dev = dev;
	Z_ISR_DECLARE(I2S_IRQn, 0, I2S_Handler, NULL);
#ifndef CONFIG_ATM_FIFO_TX_ISR
	k_work_init(&i2s_data->tx_work, dma_i2s_tx_callback_work);
#endif
	LOG_INF("I2S ATM initialized\n");
	return 0;
}

#define I2S_BASE(n) CMSDK_I2S

#define I2S_DEVICE_INIT(n)                                                                         \
	static void i2s_atm_config_tx_pins(void)                                                   \
	{                                                                                          \
		PIN_SELECT(DT_INST_PROP(n, sck_out_pin), I2S0_SCK_OUT);                            \
		PIN_SELECT(DT_INST_PROP(n, ws_out_pin), I2S0_WS_OUT);                              \
		PIN_SELECT(DT_INST_PROP(n, sd_out_pin), I2S0_SD_OUT);                              \
	}                                                                                          \
	static struct i2s_atm_config const config = {                                              \
		.fn_cfg_tx_pin = i2s_atm_config_tx_pins,                                           \
		.sys_clk_freq = DT_INST_PROP_BY_PHANDLE(n, clocks, clock_frequency),               \
	};                                                                                         \
	DEVICE_DT_INST_DEFINE(n, &i2s_atm_init, NULL, &atm_data, &config, POST_KERNEL,             \
			      CONFIG_I2S_INIT_PRIORITY, &i2s_atm_driver_api);

BUILD_ASSERT(I2S_BASE(n) == (CMSDK_AT_I2S_TypeDef *)DT_REG_ADDR(DT_NODELABEL(i2s)));
BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) == 1, "one instance supported");

DT_INST_FOREACH_STATUS_OKAY(I2S_DEVICE_INIT)
