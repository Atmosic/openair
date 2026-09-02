/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/pwm_atm_fifo.h>
#include <zephyr/drivers/ir_nec.h>

LOG_MODULE_REGISTER(ir_nec, CONFIG_IR_NEC_LOG_LEVEL);

#define DT_DRV_COMPAT atmosic_ir_nec

/*
 * NEC protocol constants (standard NEC, 38 kHz carrier, 25% duty cycle).
 *
 * All durations in microseconds; carrier_count = duration_us * 38000 / 1e6.
 * The 16-bit FIFO command word is:  bit[15]=carrier(0), bit[14]=on, bit[13:0]=count-1.
 */
#define NEC_CARRIER_HZ 38000U
#define NEC_DUTY_CYCLE CONFIG_IR_NEC_DUTY_CYCLE

/* NEC frame timing (microseconds) */
#define NEC_LEADER_MARK_US   9000U /* Leader burst */
#define NEC_LEADER_SPACE_US  4500U /* Leader space */
#define NEC_BIT_MARK_US      562U  /* Bit pulse and '0' space */
#define NEC_BIT_ONE_SPACE_US 1687U /* '1' bit space */

/* NEC frame structure */
#define NEC_DATA_BITS 32U /* Bits per frame: addr + ~addr + cmd + ~cmd */
/* leader ON + leader OFF + 32 × (pulse + space) + end pulse */
#define NEC_FRAME_LEN (2U + (NEC_DATA_BITS) * 2U + 1U)

/* NEC repeat code: leader mark + shorter leader space + end pulse */
#define NEC_REPEAT_FRAME_LEN       3U
#define NEC_REPEAT_LEADER_SPACE_US 2250U /* Repeat leader space */
/* Scheduling delays to maintain the 110 ms repeat interval */
#define NEC_REPEAT_INTERVAL_MS     110U
#define NEC_FRAME_DURATION_MS      68U /* Standard NEC frame duration */
#define NEC_REPEAT_DURATION_MS     12U /* Repeat code duration */

/* PWM FIFO driver parameters */
#define NEC_CMD_ON_BIT           BIT(14) /* Carrier-on flag in FIFO command word */
#define NEC_PWM_POLARITY         0U      /* Active-high */
#define NEC_FIFO_ALERT_THRESHOLD 4U

/* Duration → carrier cycle count */
#define NEC_USEC_PER_SEC 1000000UL
#define NEC_CYCLES(us)   ((uint32_t)(us) * NEC_CARRIER_HZ / NEC_USEC_PER_SEC)

/* 16-bit FIFO command word */
#define NEC_CMD(on, us) ((uint16_t)(((on) ? NEC_CMD_ON_BIT : 0U) | (uint16_t)(NEC_CYCLES(us) - 1U)))

struct ir_nec_data {
	const struct device *dev; /* back-pointer for work handler */
	volatile bool busy;
	volatile bool repeating;
	bool sending_repeat; /* current DMA is a repeat code, not a full frame */
	void (*done_cb)(void);
	uint16_t frame[NEC_FRAME_LEN];
	uint16_t repeat_frame[NEC_REPEAT_FRAME_LEN];
	struct pwm_atm_carrier_config carrier;
	struct pwm_atm_fifo_config fifo_cfg;
	struct k_work_delayable repeat_work;
};

struct ir_nec_cfg {
	struct pwm_dt_spec pwm;
};

/* One FIFO mode user at a time — use file-static to bridge ISR→device. */
static const struct device *current_ir_dev;

static void repeat_work_handler(struct k_work *work); /* forward declaration */

static void ir_complete(struct ir_nec_data *data)
{
	data->busy = false;
	current_ir_dev = NULL;
	void (*cb)(void) = data->done_cb;
	data->done_cb = NULL;
	if (cb) {
		cb();
	}
}

static void fifo_done_cb(const struct device *pwm_dev, uint32_t channel, int error)
{
	ARG_UNUSED(pwm_dev);
	ARG_UNUSED(channel);

	if (error) {
		LOG_ERR("IR TX error %d", error);
	} else {
		LOG_INF("IR TX done");
	}

	const struct device *dev = current_ir_dev;
	if (!dev) {
		return;
	}
	struct ir_nec_data *data = dev->data;

	if (error) {
		data->repeating = false; /* abort repeat sequence on error */
	}

	if (data->repeating) {
		k_timeout_t delay =
			data->sending_repeat
				? K_MSEC(NEC_REPEAT_INTERVAL_MS - NEC_REPEAT_DURATION_MS)
				: K_MSEC(NEC_REPEAT_INTERVAL_MS - NEC_FRAME_DURATION_MS);
		data->sending_repeat = false;
		k_work_schedule(&data->repeat_work, delay);
		return;
	}

	ir_complete(data);
}

static void repeat_work_handler(struct k_work *work)
{
	struct k_work_delayable *dwork = k_work_delayable_from_work(work);
	struct ir_nec_data *data = CONTAINER_OF(dwork, struct ir_nec_data, repeat_work);
	const struct device *dev = data->dev;
	const struct ir_nec_cfg *cfg = dev->config;

	if (!data->repeating) {
		/* ir_nec_stop() was called before this work fired. */
		ir_complete(data);
		return;
	}

	data->sending_repeat = true;
	int ret = pwm_atm_fifo_run_dma(cfg->pwm.dev, cfg->pwm.channel, data->repeat_frame,
				       NEC_REPEAT_FRAME_LEN);
	if (ret) {
		LOG_ERR("repeat DMA err %d", ret);
		data->repeating = false;
		ir_complete(data);
	}
}

/* Build the pre-formatted 16-bit FIFO command array for one NEC frame.
 *
 * Standard NEC (addr <= 0xFF): addr_low | ~addr_low | cmd | ~cmd
 * Extended NEC (addr > 0xFF):  addr_low |  addr_high | cmd | ~cmd
 */
static void build_frame(uint16_t *cmds, uint16_t addr, uint8_t cmd_byte)
{
	int i = 0;
	uint8_t addr_low = (uint8_t)addr;
	uint8_t addr_byte2 = (addr > 0xFF) ? (uint8_t)(addr >> 8) : (uint8_t)~addr_low;

	/* Leader */
	cmds[i++] = NEC_CMD(true, NEC_LEADER_MARK_US);
	cmds[i++] = NEC_CMD(false, NEC_LEADER_SPACE_US);

	/* 32 data bits, transmitted LSB-first */
	uint32_t bits = (uint32_t)addr_low | ((uint32_t)addr_byte2 << 8) |
			((uint32_t)cmd_byte << 16) | ((uint32_t)((uint8_t)~cmd_byte) << 24);

	for (int b = 0; b < (int)NEC_DATA_BITS; b++) {
		cmds[i++] = NEC_CMD(true, NEC_BIT_MARK_US);
		cmds[i++] =
			NEC_CMD(false, ((bits >> b) & 1U) ? NEC_BIT_ONE_SPACE_US : NEC_BIT_MARK_US);
	}

	/* End pulse */
	cmds[i++] = NEC_CMD(true, NEC_BIT_MARK_US);
}

int ir_nec_send(const struct device *dev, uint16_t addr, uint8_t cmd_byte, void (*done_cb)(void))
{
	struct ir_nec_data *data = dev->data;
	const struct ir_nec_cfg *cfg = dev->config;

	if (data->busy) {
		return -EBUSY;
	}

	data->busy = true;
	data->done_cb = done_cb;
	current_ir_dev = dev;

	build_frame(data->frame, addr, cmd_byte);

	int ret = pwm_atm_fifo_run_dma(cfg->pwm.dev, cfg->pwm.channel, data->frame, NEC_FRAME_LEN);
	if (ret) {
		LOG_ERR("pwm_atm_fifo_run_dma err %d", ret);
		data->busy = false;
		data->done_cb = NULL;
		current_ir_dev = NULL;
	}
	return ret;
}

int ir_nec_send_repeat(const struct device *dev, uint16_t addr, uint8_t cmd_byte,
		       void (*done_cb)(void))
{
	struct ir_nec_data *data = dev->data;
	const struct ir_nec_cfg *cfg = dev->config;

	if (data->busy) {
		return -EBUSY;
	}

	data->busy = true;
	data->repeating = true;
	data->sending_repeat = false;
	data->done_cb = done_cb;
	current_ir_dev = dev;

	build_frame(data->frame, addr, cmd_byte);

	int ret = pwm_atm_fifo_run_dma(cfg->pwm.dev, cfg->pwm.channel, data->frame, NEC_FRAME_LEN);
	if (ret) {
		LOG_ERR("pwm_atm_fifo_run_dma err %d", ret);
		data->repeating = false;
		data->busy = false;
		data->done_cb = NULL;
		current_ir_dev = NULL;
	}
	return ret;
}

void ir_nec_stop(const struct device *dev)
{
	struct ir_nec_data *data = dev->data;

	/* Setting repeating=false is sufficient: if DMA is in flight,
	 * fifo_done_cb will complete the sequence; if the work item fires
	 * next, repeat_work_handler will complete it. */
	data->repeating = false;
}

bool ir_nec_busy(const struct device *dev)
{
	const struct ir_nec_data *data = dev->data;
	return data->busy;
}

static int ir_nec_init(const struct device *dev)
{
	struct ir_nec_data *data = dev->data;
	const struct ir_nec_cfg *cfg = dev->config;

	if (!device_is_ready(cfg->pwm.dev)) {
		LOG_ERR("PWM device not ready");
		return -ENODEV;
	}

	data->dev = dev;

	data->repeat_frame[0] = NEC_CMD(true, NEC_LEADER_MARK_US);
	data->repeat_frame[1] = NEC_CMD(false, NEC_REPEAT_LEADER_SPACE_US);
	data->repeat_frame[2] = NEC_CMD(true, NEC_BIT_MARK_US);
	k_work_init_delayable(&data->repeat_work, repeat_work_handler);

	data->carrier.freq_hz = NEC_CARRIER_HZ;
	data->carrier.duty_cycle = NEC_DUTY_CYCLE;

	data->fifo_cfg.carrier1 = &data->carrier;
	data->fifo_cfg.carrier2 = NULL;
	data->fifo_cfg.polarity = NEC_PWM_POLARITY;
	data->fifo_cfg.fifo_alert_threshold = NEC_FIFO_ALERT_THRESHOLD;
	data->fifo_cfg.fifo_alert_callback = NULL;
	data->fifo_cfg.fifo_done_callback = fifo_done_cb;

	int ret = pwm_atm_fifo_init(cfg->pwm.dev, cfg->pwm.channel, &data->fifo_cfg);
	if (ret) {
		LOG_ERR("pwm_atm_fifo_init err %d", ret);
		return ret;
	}

	LOG_INF("ir_nec init: PWM ch%u", cfg->pwm.channel);
	return 0;
}

#define IR_NEC_DEFINE(n)                                                                           \
	static struct ir_nec_data ir_nec_data_##n;                                                 \
	static const struct ir_nec_cfg ir_nec_cfg_##n = {                                          \
		.pwm = PWM_DT_SPEC_INST_GET(n),                                                    \
	};                                                                                         \
	DEVICE_DT_INST_DEFINE(n, ir_nec_init, NULL, &ir_nec_data_##n, &ir_nec_cfg_##n,             \
			      POST_KERNEL, CONFIG_PWM_INIT_PRIORITY, NULL);

DT_INST_FOREACH_STATUS_OKAY(IR_NEC_DEFINE)

#ifdef CONFIG_ZTEST
/*
 * Test helper: directly invoke fifo_done_cb with a caller-supplied device
 * pointer and error code.  Allows unit tests to exercise paths that require
 * an ISR-level DMA-done event without actually running a full NEC frame.
 */
void ir_nec_test_simulate_done(const struct device *dev, int error)
{
	current_ir_dev = dev;
	fifo_done_cb(NULL, 0, error);
}

/*
 * Test helper: synthetically place the device into repeat state without
 * starting any DMA.  Allows unit tests to exercise fifo_done_cb and
 * repeat_work_handler branches that require an active repeat sequence.
 */
void ir_nec_test_set_repeat_state(const struct device *dev, bool repeating, bool sending_repeat,
				  void (*done_cb)(void))
{
	struct ir_nec_data *data = dev->data;

	current_ir_dev = dev;
	data->busy = true;
	data->repeating = repeating;
	data->sending_repeat = sending_repeat;
	data->done_cb = done_cb;
}
#endif
