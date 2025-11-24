/*
 * Copyright (C) Atmosic 2021-2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT atmosic_atm_i2c

#include <zephyr/logging/log.h>
#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif

LOG_MODULE_REGISTER(i2c_atm, CONFIG_I2C_LOG_LEVEL);

#include <soc.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/drivers/pinctrl.h>
#include <zephyr/sys/util.h>
#include "at_clkrstgen.h"

#include "arch.h"
#include "i2c-priv.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "at_apb_i2c_regs_core_macro.h"
#include "pinmux.h"

#ifndef __I2C_TRANSACTION_SETUP_MACRO__
#define I2C(DEF) (I2C0_##DEF)
#else
#define I2C(DEF) (I2C_##DEF)
#endif

#if defined(CONFIG_SOC_SERIES_ATM33)
#define I2C_GPIO_REQUIRED 1
#endif

#ifdef CONFIG_SOC_ATM34XX_2
#define I2C_CLK_STRETCH_CHECK_REQUIRED 1
#define I2C_MAX_WAIT_MS	5
#define I2C_ATM_RETRY_COUNT 3
#endif

#ifdef I2C_CLOCK_CONTROL__CLK_STRETCH_EN__MASK
#define I2C_CLK_STRETCH_SUPPORTED 1
#endif

typedef enum i2c_head_e {
	I2C_HEAD_START = 0,
	I2C_HEAD_STALL
} i2c_head_t;

typedef enum i2c_rw_e {
	I2C_WRITE = 0,
	I2C_READ
} i2c_rw_t;

typedef enum i2c_ack_e {
	/* ACK is active low */
	I2C_ACK = 0,
	I2C_NACK
} i2c_ack_t;

typedef enum i2c_tail_e {
	I2C_TAIL_STOP = 0,
	I2C_TAIL_STALL,
	I2C_TAIL_RESTART
} i2c_tail_t;

struct i2c_atm_data {
	uint32_t config;
	struct k_sem xfer_sem;
	struct k_sem completion_sem;
};

typedef void (*set_callback_t)(void);

struct i2c_atm_config {
	int instance;
	CMSDK_AT_APB_I2C_TypeDef *base;
	const struct pinctrl_dev_config *pcfg;
	bool sda_pullup;
	set_callback_t enable_clocks;
#if defined(I2C_GPIO_REQUIRED) && defined(CONFIG_PM)
	set_callback_t suspend_device;
#endif
	uint32_t mode;
	uint32_t bitrate;
#ifdef I2C_CLK_STRETCH_SUPPORTED
	bool clk_stretch_enabled;
#endif
#ifdef I2C_CLK_STRETCH_CHECK_REQUIRED
	bool (*check_clk_stretch)(void);
#endif
	void (*irq_connect)(void);
};

static int i2c_atm_set_speed(struct device const *dev, uint32_t speed)
{
	static uint32_t const s2f_tbl[] = {[I2C_SPEED_STANDARD] = KHZ(100),
					   [I2C_SPEED_FAST] = KHZ(400),
					   [I2C_SPEED_FAST_PLUS] = MHZ(1),
					   [I2C_SPEED_HIGH] = 0,
					   [I2C_SPEED_ULTRA] = 0};

	uint32_t hertz = s2f_tbl[speed];

	if (!hertz) {
		LOG_ERR("I2C speed not supported. Received: %" PRIu32, speed);
		return -ENOTSUP;
	}
	// freq_scl = f_pclk / (4 * (clkdiv + 1))
	uint32_t clkdiv = (at_clkrstgen_get_bp() / (hertz * 4)) - 1;
	struct i2c_atm_config const *config = dev->config;
	config->base->CLOCK_CONTROL = I2C(CLOCK_CONTROL__CLKDIV__WRITE(clkdiv));
#ifdef I2C_CLK_STRETCH_SUPPORTED
	if (config->clk_stretch_enabled) {
		config->base->CLOCK_CONTROL |= I2C_CLOCK_CONTROL__CLK_STRETCH_EN__WRITE(1);
	}
#endif

	return 0;
}

#ifdef CONFIG_PM
static bool pm_constraint_on;
static void i2c_atm_pm_constraint_set(const struct device *dev)
{
	if (!pm_constraint_on) {
		pm_constraint_on = true;
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}

static void i2c_atm_pm_constraint_release(const struct device *dev)
{
	if (pm_constraint_on) {
		pm_constraint_on = false;
		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}
#endif /* CONFIG_PM */

static inline void i2c_atm_enter_transfer_session(struct device const *dev)
{
	struct i2c_atm_data *data = dev->data;
#ifdef CONFIG_PM
	i2c_atm_pm_constraint_set(dev);
#endif
	k_sem_take(&data->xfer_sem, K_FOREVER);
}

static inline void i2c_atm_exit_transfer_session(struct device const *dev)
{
	struct i2c_atm_data *data = dev->data;
	k_sem_give(&data->xfer_sem);
#ifdef CONFIG_PM
	i2c_atm_pm_constraint_release(dev);
#endif
}

static void i2c_atm_isr(const struct device *dev)
{
	struct i2c_atm_config const *config = dev->config;
	config->base->INTERRUPT_MASK = 0;

	struct i2c_atm_data *data = dev->data;
	k_sem_give(&data->completion_sem);
}

static int i2c_out_sync(struct device const *dev, i2c_head_t head, uint8_t val, i2c_tail_t tail)
{
	struct i2c_atm_config const *config = dev->config;

	/* Master drives all 8 data bits */
	config->base->OUTGOING_DATA = (config->sda_pullup ? I2C(OUTGOING_DATA__DATA_PU__MASK) : 0) |
				      I2C(OUTGOING_DATA__DATA_OE__WRITE(~val)) |
				      I2C(OUTGOING_DATA__DATA_O__WRITE(val));

	config->base->RESET_INTERRUPT = I2C(RESET_INTERRUPT__RESET_INTERRUPT0__MASK);
	config->base->RESET_INTERRUPT = 0;

	/* Assert GO */
	config->base->TRANSACTION_SETUP = I2C(TRANSACTION_SETUP__GO__MASK) |
					  I2C(TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__MASK) |
#ifdef I2C_TRANSACTION_SETUP__MSTR__MASK
					  I2C(TRANSACTION_SETUP__MSTR__WRITE(1)) |
#endif
					  I2C(TRANSACTION_SETUP__TAIL__WRITE(tail)) |
					  I2C(TRANSACTION_SETUP__HEAD__WRITE(head));

	struct i2c_atm_data *data = dev->data;
	k_sem_reset(&data->completion_sem);
	config->base->INTERRUPT_MASK = I2C(INTERRUPT_MASK__PASSTHRU0__MASK);
	int ret = k_sem_take(&data->completion_sem, K_USEC(CONFIG_I2C_ATM_TIMEOUT));
	if (ret) {
		config->base->TRANSACTION_SETUP = 0;
		LOG_ERR("I2C communication timed out: %#x", config->base->TRANSACTION_STATUS);
		return -EIO;
	}

	/* ACK is active low */
	ret = (config->base->TRANSACTION_STATUS & I2C(TRANSACTION_STATUS__ACK_VALUE__MASK)) ?
	    -EIO : 0;

	/* Deassert GO */
	config->base->TRANSACTION_SETUP =
#ifdef I2C_TRANSACTION_SETUP__MSTR__MASK
		I2C(TRANSACTION_SETUP__MSTR__WRITE(1)) |
#endif
		I2C(TRANSACTION_SETUP__GO__WRITE(0));

	return ret;
}

static int i2c_in_sync(struct device const *dev, i2c_ack_t ack, i2c_tail_t tail)
{
	struct i2c_atm_config const *config = dev->config;

	/* Master listens all 8 data bits */
	config->base->OUTGOING_DATA = (config->sda_pullup ? I2C(OUTGOING_DATA__DATA_PU__MASK) : 0);

	config->base->RESET_INTERRUPT = I2C(RESET_INTERRUPT__RESET_INTERRUPT0__MASK);
	config->base->RESET_INTERRUPT = 0;

	/* Assert GO */
	config->base->TRANSACTION_SETUP = I2C(TRANSACTION_SETUP__GO__MASK) |
					  I2C(TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__WRITE(ack)) |
					  I2C(TRANSACTION_SETUP__MASTER_DRIVES_ACK__MASK) |
#ifdef I2C_TRANSACTION_SETUP__MSTR__MASK
					  I2C(TRANSACTION_SETUP__MSTR__WRITE(1)) |
#endif
					  I2C(TRANSACTION_SETUP__TAIL__WRITE(tail)) |
					  I2C(TRANSACTION_SETUP__HEAD__WRITE(I2C_HEAD_STALL));

	struct i2c_atm_data *data = dev->data;
	k_sem_reset(&data->completion_sem);
	config->base->INTERRUPT_MASK = I2C(INTERRUPT_MASK__PASSTHRU0__MASK);
	int ret = k_sem_take(&data->completion_sem, K_USEC(CONFIG_I2C_ATM_TIMEOUT));
	if (ret) {
		config->base->TRANSACTION_SETUP = 0;
		LOG_ERR("I2C communication timed out: %#x", config->base->TRANSACTION_STATUS);
		return -EIO;
	}

	ret = config->base->INCOMING_DATA;

	/* Deassert GO */
	config->base->TRANSACTION_SETUP =
#ifdef I2C_TRANSACTION_SETUP__MSTR__MASK
		I2C(TRANSACTION_SETUP__MSTR__WRITE(1)) |
#endif
		I2C(TRANSACTION_SETUP__GO__WRITE(0));

	return ret;
}

static int i2c_atm_read_msg(struct device const *dev, uint16_t addr, struct i2c_msg msg)
{
	if (!msg.len) {
		LOG_ERR("Invalid message length. Received: %d", msg.len);
		return -EINVAL;
	}

	int ret = i2c_out_sync(dev, I2C_HEAD_START, (addr << 1) | I2C_READ, I2C_TAIL_STALL);
	if (ret < 0) {
		return ret;
	}

	/* Compensate for last read being outside of loop */
	for (int i = 0; i < msg.len - 1; i++) {
		int val = i2c_in_sync(dev, I2C_ACK, I2C_TAIL_STALL);
		if (val < 0) {
			return val;
		}
		msg.buf[i] = val;
	}
	/* Last read */
	{
		bool stop = (msg.flags & I2C_MSG_STOP) ? true : false;
		int val = i2c_in_sync(dev, I2C_NACK, stop ? I2C_TAIL_STOP : I2C_TAIL_RESTART);
		if (val < 0) {
			return val;
		}
		msg.buf[msg.len - 1] = val;
	}

	return 0;
}

static int i2c_atm_write_msg(struct device const *dev, uint16_t addr, struct i2c_msg msg,
			     uint8_t msg_idx, bool restart)
{
	if (!msg.len && (msg.flags != I2C_MSG_STOP)) {
		LOG_ERR("Invalid message length. Received: %d flags %08x\n", msg.len, msg.flags);
		return -EINVAL;
	}

	// msg_idx == 0 implies first txn to the specified device
	// head = I2C_HEAD_START for the first txn and I2C_HEAD_STALL for rest
	if (!msg_idx) {
		int ret = i2c_out_sync(dev, I2C_HEAD_START, (addr << 1) | I2C_WRITE,
				       (msg.len) ? I2C_TAIL_STALL : I2C_TAIL_STOP);
		if (ret < 0) {
			return ret;
		}

		/* Handle zero length writes */
		if (!msg.len) {
			return ret;
		}
	}

	/* Compensate for last write being outside of loop */
	for (int i = 0; i < msg.len - 1; i++) {
		int ret = i2c_out_sync(dev, I2C_HEAD_STALL, msg.buf[i], I2C_TAIL_STALL);
		if (ret < 0) {
			return ret;
		}
	}

	/* Last write */
	// In the absence of STOP, tail = RESTART or STALL based on the subsequent transaction
	i2c_tail_t tail = (msg.flags & I2C_MSG_STOP) ? I2C_TAIL_STOP : (restart ? I2C_TAIL_RESTART :
	    I2C_TAIL_STALL);
	return i2c_out_sync(dev, I2C_HEAD_STALL, msg.buf[msg.len - 1], tail);
}

static int i2c_atm_transfer(struct device const *dev, struct i2c_msg *msgs, uint8_t num_msgs,
			    uint16_t addr)
{
	struct i2c_atm_data *data = dev->data;
	uint8_t attempts = 1;

	if (data->config & I2C_ADDR_10_BITS) {
		LOG_ERR("10-bit I2C address not supported. Received: %#x", addr);
		return -ENOTSUP;
	}

	i2c_atm_enter_transfer_session(dev);

#ifdef I2C_CLK_STRETCH_CHECK_REQUIRED
	struct i2c_atm_config const *config = dev->config;
	if (config->clk_stretch_enabled) {
		if (!config->check_clk_stretch()) {
			LOG_ERR("I2C clock stretch check failed");
			i2c_atm_exit_transfer_session(dev);
			return -EIO;
		}
		attempts = I2C_ATM_RETRY_COUNT;
	}
#endif

	/* Mask out unused address bits, and make room for R/W bit */
	int ret = 0;
	uint8_t retry = 0;
	do {
	    for (uint8_t i = 0; i < num_msgs; i++) {
		if ((msgs[i].flags & I2C_MSG_RW_MASK) == I2C_MSG_WRITE) {
			// Peak into the next message
			bool restart = false;
			if (i < (num_msgs - 1)) {
			    restart = msgs[i+1].flags & I2C_MSG_RESTART;
			}
			ret = i2c_atm_write_msg(dev, addr, msgs[i], i, restart);
		} else {
			ret = i2c_atm_read_msg(dev, addr, msgs[i]);
		}

		if (ret < 0) {
			LOG_ERR("Transaction failed with status: %d", ret);
#ifdef I2C_CLK_STRETCH_CHECK_REQUIRED
			if (config->clk_stretch_enabled) {
				WRPR_CTRL_SET(config->base, WRPR_CTRL__SRESET);
				WRPR_CTRL_SET(config->base, WRPR_CTRL__CLK_ENABLE);
				uint32_t speed = I2C_SPEED_GET(i2c_map_dt_bitrate(config->bitrate));
				i2c_atm_set_speed(dev, speed);
			}
#endif
			break;
		}
	    }
	} while ((ret < 0) && (++retry < attempts));

	i2c_atm_exit_transfer_session(dev);

	return ret;
}

#ifdef PSEQ_CTRL0__I2C_LATCH_OPEN__MASK
static void i2c_atm_pseq_latch_close(void)
{
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
	{
		PSEQ_CTRL0__I2C_LATCH_OPEN__CLR(CMSDK_PSEQ->CTRL0);
	}
	WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
}
#endif

#ifdef CONFIG_PM
#ifdef I2C_GPIO_REQUIRED
static void suspend_i2c_device(const struct device *dev)
{
	if (!device_is_ready(dev)) {
		LOG_ERR("I2C device %s is not ready", dev->name);
		return;
	}

	struct i2c_atm_config const *config = dev->config;
	config->suspend_device();
}

static void resume_i2c_device(const struct device *dev)
{
	if (!device_is_ready(dev)) {
		LOG_ERR("I2C device %s is not ready", dev->name);
		return;
	}

	struct i2c_atm_config const *config = dev->config;
	int ret = pinctrl_apply_state(config->pcfg, PINCTRL_STATE_DEFAULT);
	if (ret) {
		LOG_ERR("Unable to configure I2C pins");
	}
}

static void notify_pm_state_entry(enum pm_state state)
{
	if (state != PM_STATE_SUSPEND_TO_RAM) {
		return;
	}

#define SUSPEND_I2C(inst) suspend_i2c_device(DEVICE_DT_GET(DT_DRV_INST(inst)))
	DT_INST_FOREACH_STATUS_OKAY(SUSPEND_I2C);
#undef SUSPEND_I2C
}
#endif // I2C_GPIO_REQUIRED

static void notify_pm_state_exit(enum pm_state state)
{
	if (state != PM_STATE_SUSPEND_TO_RAM) {
		return;
	}

#ifdef I2C_GPIO_REQUIRED
#define RESUME_I2C(inst) resume_i2c_device(DEVICE_DT_GET(DT_DRV_INST(inst)))
	DT_INST_FOREACH_STATUS_OKAY(RESUME_I2C);
#undef RESUME_I2C
#endif

#ifdef PSEQ_CTRL0__I2C_LATCH_OPEN__MASK
	i2c_atm_pseq_latch_close();
#endif
}

static struct pm_notifier notifier = {
#ifdef I2C_GPIO_REQUIRED
	.state_entry = notify_pm_state_entry,
#endif
	.state_exit = notify_pm_state_exit,
};
#endif // CONFIG_PM

static int i2c_atm_configure(struct device const *dev, uint32_t cfg)
{
	struct i2c_atm_config const *config = dev->config;
	struct i2c_atm_data *data = dev->data;

	if (!(cfg & I2C_MODE_CONTROLLER)) {
		LOG_ERR("I2C slave mode not supported. Received: %#x", cfg);
		return -ENOTSUP;
	}

	data->config = cfg;
	config->enable_clocks();
	int err = pinctrl_apply_state(config->pcfg, PINCTRL_STATE_DEFAULT);
	if (err) {
		LOG_ERR("Unable to configure I2C pins");
		return err;
	}

#ifdef PSEQ_CTRL0__I2C_LATCH_OPEN__MASK
	i2c_atm_pseq_latch_close();
#endif

#ifdef CONFIG_PM
	static bool inited;
	if (!inited) {
		pm_notifier_register(&notifier);
		inited = true;
	}
#endif

	return i2c_atm_set_speed(dev, I2C_SPEED_GET(cfg));
}

static struct i2c_driver_api const i2c_atm_driver_api = {
	.configure = i2c_atm_configure,
	.transfer = i2c_atm_transfer,
};

static int i2c_atm_init(struct device const *dev)
{
	struct i2c_atm_config const *config = dev->config;
	uint32_t cfgspeed = i2c_map_dt_bitrate(config->bitrate);
	struct i2c_atm_data *data = dev->data;

	k_sem_init(&data->xfer_sem, 1, 1);
	k_sem_init(&data->completion_sem, 0, 1);

	config->irq_connect();

	return i2c_atm_configure(dev, config->mode | cfgspeed);
}

#define I2C_SCK(n)  CONCAT(CONCAT(I2C, DT_INST_PROP(n, instance)), _SCK)
#define I2C_SDA(n)  CONCAT(CONCAT(I2C, DT_INST_PROP(n, instance)), _SDA)
#define I2C_BASE(n) CONCAT(CMSDK_I2C, DT_INST_PROP(n, instance))
#define I2C_IRQ(n) DT_INST_IRQN(n)
#define I2C_IRQ_PRI(n) DT_INST_IRQ(n, priority)
/*
 * Expects SDA to be index 0 and SCL to be index 1 in the DTS config
 *
 * ex:
 * &i2cN {
 *         pinctrl-0 = <&i2c_sda &i2c_scl>;
 *         ...
 * };
 */
#define SDA_PINCTRL_IDX 0
#define SCL_PINCTRL_IDX 1
#define I2C_GET_PULL(n, idx) DT_PROP_OR(DT_INST_PINCTRL_0(n, idx), bias_pull_up, 0)
#define I2C_GET_PIN(n, idx) DT_PROP_BY_IDX(DT_INST_PINCTRL_0(n, idx), pinmux, 0)
#define I2C_DEVICE_INIT(n)                                                                         \
	PINCTRL_DT_INST_DEFINE(n);                                                                 \
	static void i2c_atm_enable_clocks_##n(void)                                                \
	{                                                                                          \
		WRPR_CTRL_SET(I2C_BASE(n), WRPR_CTRL__CLK_ENABLE);                                 \
	}                                                                                          \
	IF_ENABLED(I2C_GPIO_REQUIRED, (                                                            \
	IF_ENABLED(CONFIG_PM, (                                                                    \
	static void i2c_atm_suspend_device_##n(void)                                               \
	{                                                                                          \
		GPIO_SET_INPUT_PULLUP(PIN2GPIO(I2C_GET_PIN(n, SCL_PINCTRL_IDX)));                  \
		PIN_SELECT(I2C_GET_PIN(n, SCL_PINCTRL_IDX), GPIO);                                 \
		GPIO_SET_INPUT_PULLUP(PIN2GPIO(I2C_GET_PIN(n, SDA_PINCTRL_IDX)));                  \
		PIN_SELECT(I2C_GET_PIN(n, SDA_PINCTRL_IDX), GPIO);                                 \
	}                                                                                          \
	)) /* CONFIG_PM */                                                                         \
	)) /* I2C_GPIO_REQUIRED */                                                                 \
	IF_ENABLED(I2C_CLK_STRETCH_CHECK_REQUIRED, (                                               \
	static bool i2c_atm_check_clk_stretch_##n(void)                                            \
	{                                                                                          \
		GPIO_SET_INPUT_PULLUP(PIN2GPIO(I2C_GET_PIN(n, SCL_PINCTRL_IDX)));                  \
		PIN_SELECT(I2C_GET_PIN(n, SCL_PINCTRL_IDX), GPIO);                                 \
		int64_t start_time = k_uptime_get();                                               \
		while (!GPIO_READ_DATA(PIN2GPIO(I2C_GET_PIN(n, SCL_PINCTRL_IDX)))) {               \
			if (k_uptime_get() - start_time > I2C_MAX_WAIT_MS) {                       \
				return false;                                                      \
			}                                                                          \
			k_sleep(K_MSEC(1));                                                        \
		}                                                                                  \
		PIN_SELECT(I2C_GET_PIN(n, SCL_PINCTRL_IDX), I2C_SCK(n));                           \
		return true;                                                                       \
	}                                                                                          \
	))                                                                                         \
	ISR_DIRECT_DECLARE(i2c_atm_isr##n)                                                         \
	{                                                                                          \
		struct device const *dev = DEVICE_DT_INST_GET(n);                                  \
		i2c_atm_isr(dev);                                                                  \
		return 1;                                                                          \
	}                                                                                          \
	static void i2c_atm_config_irq_##n(void)						   \
	{ 											   \
		IRQ_DIRECT_CONNECT(I2C_IRQ(n), I2C_IRQ_PRI(n), i2c_atm_isr##n, 0);                 \
		irq_enable(I2C_IRQ(n)); 							   \
	} 											   \
	static struct i2c_atm_config const i2c_atm_config_##n = {                                  \
		.instance = n,                                                                     \
		.base = I2C_BASE(n),                                                               \
		.sda_pullup = I2C_GET_PULL(n, SDA_PINCTRL_IDX),                                    \
		.pcfg = PINCTRL_DT_INST_DEV_CONFIG_GET(n),                                         \
		.enable_clocks = i2c_atm_enable_clocks_##n,                                        \
	        IF_ENABLED(I2C_GPIO_REQUIRED, (                                                    \
		IF_ENABLED(CONFIG_PM, (                                                            \
		.suspend_device = i2c_atm_suspend_device_##n,                                      \
		)) /* CONFIG_PM */                                                                 \
		)) /* I2C_GPIO_REQUIRED */                                                         \
		.mode = I2C_MODE_CONTROLLER,                                                       \
		.bitrate = DT_INST_PROP(n, clock_frequency),                                       \
		IF_ENABLED(I2C_CLK_STRETCH_SUPPORTED, (                                            \
		.clk_stretch_enabled = DT_INST_PROP(n, clk_stretch),                               \
		))                                                                                 \
		IF_ENABLED(I2C_CLK_STRETCH_CHECK_REQUIRED, (                                       \
		.check_clk_stretch = i2c_atm_check_clk_stretch_##n,                                \
		))                                                                                 \
		.irq_connect = i2c_atm_config_irq_##n,						   \
	};                                                                                         \
	static struct i2c_atm_data i2c_atm_data_##n;                                               \
	DEVICE_DT_INST_DEFINE(n, &i2c_atm_init, NULL, &i2c_atm_data_##n, &i2c_atm_config_##n,      \
			      POST_KERNEL, CONFIG_I2C_INIT_PRIORITY, &i2c_atm_driver_api);         \
	IF_DISABLED(I2C_CLK_STRETCH_SUPPORTED, (                                                   \
	BUILD_ASSERT(!DT_INST_PROP(n, clk_stretch));                                               \
	));

DT_INST_FOREACH_STATUS_OKAY(I2C_DEVICE_INIT)
