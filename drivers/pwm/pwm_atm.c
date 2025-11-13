/*
 * Copyright (c) 2021-2025, Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(pwm_atm, CONFIG_PWM_LOG_LEVEL);

#include <errno.h>
#include <inttypes.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>
#ifdef CONFIG_PWM_ATM_FIFO
#include <zephyr/drivers/pwm_atm_fifo.h>
#endif
#ifdef CONFIG_PM
#include <zephyr/pm/policy.h>
#include <zephyr/kernel.h>
#endif
#include <soc.h>

#include "arch.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "at_apb_pwm_regs_core_macro.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "dma.h"

#define DT_DRV_COMPAT atmosic_atm3x_pwm
#define SYS_CLK_IN_KHZ (PCLK_ALT_FREQ / 1000) // PWM block runs on 16MHz clock domain
#define PWM_CLK_CTRL (WRPR_CTRL__CLK_ENABLE | WRPR_CTRL__CLK_SEL)
#define PWM_IRQ PWM_IRQn
#define PWM0_TOT_WIDTH (PWM_PWM0_DUR__LO_DUR__WIDTH + PWM_PWM0_DUR__HI_DUR__WIDTH)
#define PWM_SET_DURATION(I, hi_dur, lo_dur)                                                        \
	do {                                                                                       \
		CMSDK_PWM->PWM##I##_DUR = PWM_PWM##I##_DUR__HI_DUR__WRITE((hi_dur)) |              \
					  PWM_PWM##I##_DUR__LO_DUR__WRITE((lo_dur));               \
	} while (0)

#define PWM_SET_PARAMS(I, polarity, mode)                                                          \
	do {                                                                                       \
		CMSDK_PWM->PWM##I##_CTRL = PWM_PWM##I##_CTRL__INVERT__WRITE(polarity) |            \
					   PWM_PWM##I##_CTRL__MODE__WRITE(mode) |                  \
					   PWM_PWM##I##_CTRL__OK_TO_RUN__WRITE(0);                 \
	} while (0)

#define PWM_UNSET_PARAMS(I)                                                                        \
	do {                                                                                       \
		CMSDK_PWM->PWM##I##_CTRL = 0;                                                      \
		CMSDK_PWM->PWM##I##_DUR = 0;                                                       \
	} while (0)
#define PWM(n) CONCAT(PWM, DT_INST_PROP(n, channel))

#define SYS_CLK_IN_HZ (SYS_CLK_IN_KHZ * 1000)

#define PWM_TOT_DUR_ADJ 1
#define MAX_PWM_INST 8

typedef enum {
	PWM_CONTINUOUS_MODE,
	PWM_COUNTING_MODE,
	PWM_IR_MODE,
	PWM_IR_FIFO_MODE,
} pwm_mode_t;

#define DEV_CFG(dev) ((struct pwm_atm_config const *)(dev)->config)
#define DEV_DATA(dev) ((struct pwm_atm_data *)(dev)->data)

typedef void (*set_callback_t)(void);

struct pwm_atm_config {
	uint32_t volatile *ctrl;
	set_callback_t config_pins;
	uint32_t max_freq;
	uint32_t min_freq;
#ifdef PWM_PWM0_CTRL__TOT_DUR__READ
	uint8_t max_duty_cycle;
	uint8_t min_duty_cycle;
#endif
};

#ifdef CONFIG_PWM_ATM_FIFO
struct pwm_atm_fifo_data {
	const struct pwm_atm_fifo_config *config;
	uint8_t instance;
	bool initialized;
};
#endif

struct pwm_atm_data {
	uint32_t period_cycles[MAX_PWM_INST];  /* Track period for each PWM channel */
#ifdef CONFIG_PWM_ATM_FIFO
	struct pwm_atm_fifo_data fifo_data[MAX_PWM_INST];
#endif
};

#ifdef PSEQ_CTRL0__PWM_LATCH_OPEN__CLR
__FAST
static void pwm_pseq_latch_close(void)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		PSEQ_CTRL0__PWM_LATCH_OPEN__CLR(CMSDK_PSEQ->CTRL0);
	}
	WRPR_CTRL_POP();
}
#endif

static void pwm_disable(uint8_t instance)
{
	switch (instance) {
	case 0:
		PWM_PWM0_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM0_CTRL);
		break;
	case 1:
		PWM_PWM1_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM1_CTRL);
		break;
	case 2:
		PWM_PWM2_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM2_CTRL);
		break;
	case 3:
		PWM_PWM3_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM3_CTRL);
		break;
	case 4:
		PWM_PWM4_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM4_CTRL);
		break;
	case 5:
		PWM_PWM5_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM5_CTRL);
		break;
	case 6:
		PWM_PWM6_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM6_CTRL);
		break;
	case 7:
		PWM_PWM7_CTRL__OK_TO_RUN__CLR(CMSDK_PWM->PWM7_CTRL);
		break;
	default:
		ASSERT_INFO(0, instance, 0);
		break;
	}
	return;
}

#ifdef CONFIG_PWM_ATM_FIFO
/* Global FIFO state - only one channel can use FIFO mode at a time */
static const struct device *fifo_dev;
static uint32_t fifo_channel;
static const struct pwm_atm_fifo_config *fifo_config;

/* Mutex to protect global FIFO state for thread safety */
static K_MUTEX_DEFINE(fifo_mutex);

/**
 * @brief Validate FIFO ownership and initialization
 *
 * @param dev Device pointer
 * @param channel PWM channel
 * @param data Device data pointer
 * @return true if valid, false otherwise
 */
static inline bool pwm_atm_fifo_validate(const struct device *dev, uint32_t channel,
					 struct pwm_atm_data *data)
{
	return (fifo_dev == dev && fifo_channel == channel && data->fifo_data[channel].initialized);
}

static void pwm_atm_fifo_isr(void)
{
	uint32_t intr_mask = CMSDK_PWM->INTERRUPTS;

	if (PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__READ(intr_mask)) {
		/* FIFO low water mark hit - call alert handler */
		if (fifo_config && fifo_config->fifo_alert_callback) {
			fifo_config->fifo_alert_callback(fifo_dev, fifo_channel, 0);
		}
		CMSDK_PWM->INTERRUPTS_CLEAR = PWM_INTERRUPTS_MASK__MASK_INTRPT1__MASK;
	}

	if (PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__READ(intr_mask)) {
		/* All FIFO commands completed */
		pwm_disable(fifo_channel);
		if (fifo_config && fifo_config->fifo_done_callback) {
			fifo_config->fifo_done_callback(fifo_dev, fifo_channel, 0);
		}
		CMSDK_PWM->INTERRUPTS_CLEAR = PWM_INTERRUPTS_MASK__MASK_INTRPT3__MASK;
	}

	if (PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__READ(intr_mask)) {
		LOG_ERR("PWM FIFO overflow");
		/* Call alert callback with overflow error */
		if (fifo_config && fifo_config->fifo_alert_callback) {
			fifo_config->fifo_alert_callback(fifo_dev, fifo_channel, -EOVERFLOW);
		}
		CMSDK_PWM->INTERRUPTS_CLEAR = PWM_INTERRUPTS_MASK__MASK_INTRPT2__MASK;
	}

	CMSDK_PWM->INTERRUPTS_CLEAR = 0x0;
}
#endif

#ifdef CONFIG_PM
static atomic_t pm_constraint_mask;
static void pwm_atm_pm_constraint_set(const struct device *dev, uint8_t channel)
{
	atomic_t old_mask = atomic_or(&pm_constraint_mask, BIT(channel));

	if (!old_mask) {
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}

static void pwm_atm_pm_constraint_release(const struct device *dev, uint8_t channel)
{
	struct pwm_atm_data *data = DEV_DATA(dev);
	atomic_t old_mask = atomic_and(&pm_constraint_mask, ~BIT(channel));

	if (old_mask && !pm_constraint_mask) {
		/* Calculate frame duration based on stored period for the channel being disabled */
		if (data->period_cycles[channel]) {
			/*
			 * Frame duration with 20% safety margin in microseconds
			 */
			uint32_t delay_us = data->period_cycles[channel] /
					    ((SYS_CLK_IN_KHZ * 100) / (MSEC_PER_SEC * 120));

			LOG_DBG("PWM channel %d: period=%" PRIu32 " cycles, delay=%" PRIu32 " µs",
				channel, data->period_cycles[channel], delay_us);

			/*
			 * Hardware Timing Requirement:
			 * PWM OK_TO_RUN bit clears immediately, but the hardware stops
			 * "at the end of the next frame" per register documentation.
			 */
			k_usleep(delay_us);
		}

		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}
#endif

static void pinmux_config(uint8_t instance, uint8_t polarity, pwm_mode_t mode)
{
	switch (instance) {
	case 0: {
		PWM_SET_PARAMS(0, polarity, mode);
	} break;
	case 1: {
		PWM_SET_PARAMS(1, polarity, mode);
	} break;
	case 2: {
		PWM_SET_PARAMS(2, polarity, mode);
	} break;
	case 3: {
		PWM_SET_PARAMS(3, polarity, mode);
	} break;
	case 4: {
		PWM_SET_PARAMS(4, polarity, mode);
	} break;
	case 5: {
		PWM_SET_PARAMS(5, polarity, mode);
	} break;
	case 6: {
		PWM_SET_PARAMS(6, polarity, mode);
	} break;
	case 7: {
		PWM_SET_PARAMS(7, polarity, mode);
	} break;
	default: {
		ASSERT_INFO(0, instance, 0);
	} break;
	}

#ifdef PSEQ_CTRL0__PWM_LATCH_OPEN__CLR
	pwm_pseq_latch_close();
#endif
}

static void pwm_set_duration(uint8_t instance, uint32_t hi_dur, uint32_t lo_dur)
{
	switch (instance) {
	case 0:
		PWM_SET_DURATION(0, hi_dur, lo_dur);
		break;
	case 1:
		PWM_SET_DURATION(1, hi_dur, lo_dur);
		break;
	case 2:
		PWM_SET_DURATION(2, hi_dur, lo_dur);
		break;
	case 3:
		PWM_SET_DURATION(3, hi_dur, lo_dur);
		break;
	case 4:
		PWM_SET_DURATION(4, hi_dur, lo_dur);
		break;
	case 5:
		PWM_SET_DURATION(5, hi_dur, lo_dur);
		break;
	case 6:
		PWM_SET_DURATION(6, hi_dur, lo_dur);
		break;
	case 7:
		PWM_SET_DURATION(7, hi_dur, lo_dur);
		break;
	default:
		ASSERT_INFO(0, instance, 0);
		break;
	}
}

static void pwm_enable(uint8_t instance)
{
	switch (instance) {
	case 0:
		PWM_PWM0_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM0_CTRL);
		break;
	case 1:
		PWM_PWM1_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM1_CTRL);
		break;
	case 2:
		PWM_PWM2_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM2_CTRL);
		break;
	case 3:
		PWM_PWM3_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM3_CTRL);
		break;
	case 4:
		PWM_PWM4_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM4_CTRL);
		break;
	case 5:
		PWM_PWM5_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM5_CTRL);
		break;
	case 6:
		PWM_PWM6_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM6_CTRL);
		break;
	case 7:
		PWM_PWM7_CTRL__OK_TO_RUN__SET(CMSDK_PWM->PWM7_CTRL);
		break;
	default:
		ASSERT_INFO(0, instance, 0);
		break;
	}
	return;
}

static int pwm_atm_get_cycles_per_sec(struct device const *dev, uint32_t pwm, uint64_t *cycles)
{
	ARG_UNUSED(dev);
	ARG_UNUSED(pwm);
	*cycles = SYS_CLK_IN_HZ;

	return 0;
}

static int pwm_atm_set_cycles(struct device const *dev, uint32_t channel, uint32_t period_cycles,
			      uint32_t pulse_cycles, pwm_flags_t flags)
{
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST) {
		LOG_ERR("Invalid channel. Received (%d)", channel);
		return -EINVAL;
	}

	if (!pulse_cycles) {
		pwm_set_duration(channel, 0, 0);
		pwm_disable(channel);
#ifdef CONFIG_PM
		pwm_atm_pm_constraint_release(dev, channel);
#endif
		data->period_cycles[channel] = 0;
		return 0;
	}

	if (pulse_cycles > period_cycles) {
		LOG_ERR("Invalid combination of pulse and period cycles. Received: %d %d",
			pulse_cycles, period_cycles);
		return -EINVAL;
	}

#ifdef PWM_PWM0_CTRL__TOT_DUR__READ
	uint32_t duty_cycle = (pulse_cycles * 100) / period_cycles;
	uint32_t max_duty_cycle = DEV_CFG(dev)->max_duty_cycle;
	uint32_t min_duty_cycle = DEV_CFG(dev)->min_duty_cycle;

	if (duty_cycle > max_duty_cycle) {
		/* fallback to minimum duty cycle */
		LOG_WRN("Unsupported duty cycle %d, falling back to max duty cycle %d\n",
			duty_cycle, max_duty_cycle);
		duty_cycle = max_duty_cycle;
	}

	if (duty_cycle < min_duty_cycle) {
		/* fallback to minimum duty cycle */
		LOG_WRN("Unsupported duty cycle %d, falling back to min duty cycle %d\n",
			duty_cycle, min_duty_cycle);
		duty_cycle = min_duty_cycle;
	}
#endif // PWM_PWM0_CTRL__TOT_DUR__READ

	/* Scale the input to maintain the duty cycle if the exact timing cannot be accomodated  */
	uint32_t max_cycles = DEV_CFG(dev)->max_freq;

	if (period_cycles > max_cycles) {
#ifdef PWM_PWM0_CTRL__TOT_DUR__READ
		pulse_cycles = PULSE_CYCLES_FROM_DUTY_CYCLE(max_cycles, max_duty_cycle);
#else
		pulse_cycles *= ((float)max_cycles / (float)period_cycles);
#endif // PWM_PWM0_CTRL__TOT_DUR__READ
		period_cycles = max_cycles;
	}

	uint32_t min_cycles = DEV_CFG(dev)->min_freq;

	if (period_cycles < min_cycles) {
#ifdef PWM_PWM0_CTRL__TOT_DUR__READ
		pulse_cycles = PULSE_CYCLES_FROM_DUTY_CYCLE(min_cycles, min_duty_cycle);
#else
		pulse_cycles *= ((float)min_cycles / (float)period_cycles);
#endif // PWM_PWM0_CTRL__TOT_DUR__READ
		period_cycles = min_cycles;
	}

#ifdef PWM_PWM0_CTRL__TOT_DUR__READ
	/* Convert to period cycles to kilohertz */
	period_cycles = period_cycles / 1000;

	/* Convert to MPC Clock Cycles */
	uint32_t mpc_clk_period_cycles = (SYS_CLK_IN_KHZ / period_cycles);
	uint32_t mpc_clk_pulse_cycles = (mpc_clk_period_cycles * duty_cycle) / 100;
	uint32_t tot_dur = mpc_clk_period_cycles - PWM_TOT_DUR_ADJ;
	uint16_t hi_dur = mpc_clk_pulse_cycles - PWM_TOT_DUR_ADJ;
	uint16_t lo_dur = tot_dur - hi_dur;
#else
	uint32_t tot_dur = period_cycles - PWM_TOT_DUR_ADJ;
	uint16_t lo_dur = tot_dur - (((float)pulse_cycles / (float)period_cycles) * tot_dur);
	uint16_t hi_dur = tot_dur - lo_dur;
#endif // PWM_PMW0_CTRL__TOT_DUR__READ

	data->period_cycles[channel] = period_cycles;

#ifdef CONFIG_PM
	pwm_atm_pm_constraint_set(dev, channel);
#endif

	pinmux_config(channel, 0, PWM_CONTINUOUS_MODE);
	pwm_set_duration(channel, hi_dur, lo_dur);

	pwm_enable(channel);

	return 0;
}

#ifdef CONFIG_PWM_ATM_FIFO
static void pwm_cal_hi_lo_duration(uint32_t freq_Hz, uint8_t duty_cycle, uint16_t *hi_dur,
				   uint16_t *lo_dur)
{
	if (freq_Hz > (SYS_CLK_IN_HZ / 2)) {
		LOG_ERR("Invalid frequency: %u Hz", freq_Hz);
		*hi_dur = 0;
		*lo_dur = 0;
		return;
	}

	uint32_t tot_dur = SYS_CLK_IN_HZ / freq_Hz;
	*hi_dur = (tot_dur * duty_cycle) / 100;
	*lo_dur = tot_dur - *hi_dur;
}

static void pinmux_deconfig(uint8_t instance)
{
	switch (instance) {
	case 0: {
		PWM_UNSET_PARAMS(0);
	} break;
	case 1: {
		PWM_UNSET_PARAMS(1);
	} break;
	case 2: {
		PWM_UNSET_PARAMS(2);
	} break;
	case 3: {
		PWM_UNSET_PARAMS(3);
	} break;
	case 4: {
		PWM_UNSET_PARAMS(4);
	} break;
	case 5: {
		PWM_UNSET_PARAMS(5);
	} break;
	case 6: {
		PWM_UNSET_PARAMS(6);
	} break;
	case 7: {
		PWM_UNSET_PARAMS(7);
	} break;
	default: {
		ASSERT_INFO(0, instance, 0);
	} break;
	}
}

int pwm_atm_fifo_init(const struct device *dev, uint32_t channel,
		      const struct pwm_atm_fifo_config *config)
{
	if (channel >= MAX_PWM_INST) {
		LOG_ERR("Invalid channel: %u", channel);
		return -EINVAL;
	}

	if (!config) {
		return -EINVAL;
	}

	/* Thread-safe check and acquisition of FIFO mode */
	k_mutex_lock(&fifo_mutex, K_FOREVER);

	/* Only one channel can use FIFO mode at a time */
	if (fifo_dev && (fifo_dev != dev || fifo_channel != channel)) {
		k_mutex_unlock(&fifo_mutex);
		LOG_ERR("FIFO mode already in use by another channel");
		return -EBUSY;
	}

	/* Validate carrier configuration - at least one carrier must be configured */
	if (!config->carrier1 && !config->carrier2) {
		k_mutex_unlock(&fifo_mutex);
		LOG_ERR("At least one carrier must be configured");
		return -EINVAL;
	}

	/* Warn about missing carriers */
	if (!config->carrier1) {
		LOG_WRN("Carrier 1 not configured - commands using carrier=0 will fail");
	}
	if (!config->carrier2) {
		LOG_WRN("Carrier 2 not configured - commands using carrier=1 will fail");
	}

	/* Initialize PWM clock if not already done */
	WRPR_CTRL_SET(CMSDK_PWM, PWM_CLK_CTRL);

	uint16_t hi_dur, lo_dur;
	/* Configure carrier 1 if provided */
	if (config->carrier1) {
		pwm_cal_hi_lo_duration(config->carrier1->freq_hz, config->carrier1->duty_cycle,
				       &hi_dur, &lo_dur);
		CMSDK_PWM->FIFO_CARRIER1_DUR = PWM_FIFO_CARRIER1_DUR__HI_DUR__WRITE(hi_dur) |
					       PWM_FIFO_CARRIER1_DUR__LO_DUR__WRITE(lo_dur);
	}

	/* Configure carrier 2 if provided */
	if (config->carrier2) {
		pwm_cal_hi_lo_duration(config->carrier2->freq_hz, config->carrier2->duty_cycle,
				       &hi_dur, &lo_dur);
		CMSDK_PWM->FIFO_CARRIER2_DUR = PWM_FIFO_CARRIER2_DUR__HI_DUR__WRITE(hi_dur) |
					       PWM_FIFO_CARRIER2_DUR__LO_DUR__WRITE(lo_dur);
	}

	/* Configure FIFO settings */
	CMSDK_PWM->FIFO_CFG = PWM_FIFO_CFG__LWM__WRITE(config->fifo_alert_threshold) |
			      PWM_FIFO_CFG__CH_STOP__WRITE(1);

	/* Configure PWM channel for FIFO mode */
	pinmux_config(channel, config->polarity, PWM_IR_FIFO_MODE);

	/* Enable interrupts */
	CMSDK_PWM->INTERRUPTS_MASK = PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__MASK |
				     PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__MASK |
				     PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__MASK;

	/* Clear any existing interrupt status */
	CMSDK_PWM->INTERRUPTS_CLEAR = CMSDK_PWM->INTERRUPTS_MASK;
	CMSDK_PWM->INTERRUPTS_CLEAR = 0;

	/* Install interrupt handler */
	IRQ_CONNECT(PWM_IRQ, 0, pwm_atm_fifo_isr, 0, 0);
	irq_enable(PWM_IRQ);

	/* Store global FIFO state */
	fifo_dev = dev;
	fifo_channel = channel;
	fifo_config = config;

	/* Release mutex after successful initialization */
	k_mutex_unlock(&fifo_mutex);

	struct pwm_atm_data *data = DEV_DATA(dev);
	/* Store per-device FIFO data */
	data->fifo_data[channel].config = config;
	data->fifo_data[channel].instance = channel;
	data->fifo_data[channel].initialized = true;

	return 0;
}

int pwm_atm_fifo_deinit(const struct device *dev, uint32_t channel)
{
	if (channel >= MAX_PWM_INST) {
		return -EINVAL;
	}

	struct pwm_atm_data *data = DEV_DATA(dev);
	if (!data->fifo_data[channel].initialized) {
		LOG_WRN("FIFO mode not initialized for channel %u", channel);
		return -ENODEV;
	}

	/* Stop PWM and disable interrupts */
	pwm_disable(channel);
	irq_disable(PWM_IRQ);

	/* Clear FIFO to prevent stale commands */
	PWM_FIFO_CFG__FLUSH__SET(CMSDK_PWM->FIFO_CFG);
	PWM_FIFO_CFG__FLUSH__CLR(CMSDK_PWM->FIFO_CFG);

	pinmux_deconfig(channel);

	/* Thread-safe clearing of global FIFO state */
	k_mutex_lock(&fifo_mutex, K_FOREVER);

	/* Clear global FIFO state if this device/channel owns it */
	if (fifo_dev == dev && fifo_channel == channel) {
		/* Use irq_lock for ISR safety when clearing config */
		unsigned int key = irq_lock();
		fifo_config = NULL; /* Clear this first for ISR safety */
		irq_unlock(key);

		fifo_dev = NULL;
		fifo_channel = 0;
	} else if (fifo_dev != NULL) {
		k_mutex_unlock(&fifo_mutex);
		LOG_ERR("Cannot deinit - FIFO owned by different device/channel (dev=%p, "
			"channel=%u)",
			(void *)fifo_dev, fifo_channel);
		return -ENODEV;
	}

	k_mutex_unlock(&fifo_mutex);

	/* Clear per-channel FIFO data */
	data->fifo_data[channel].initialized = false;
	data->fifo_data[channel].config = NULL;
	data->fifo_data[channel].instance = 0;

#ifdef CONFIG_PM
	pwm_atm_pm_constraint_release(dev, channel);
#endif

	return 0;
}

int pwm_atm_fifo_write_cmd(const struct device *dev, uint32_t channel,
			   const struct pwm_atm_fifo_cmd *cmd)
{
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST) {
		return -EINVAL;
	}

	/* Validate ownership and initialization */
	if (!pwm_atm_fifo_validate(dev, channel, data)) {
		return -ENODEV;
	}

	if (!cmd || cmd->carrier_count == 0 || cmd->carrier_count > 16384) {
		return -EINVAL;
	}

	/* Validate carrier is configured */
	if (cmd->carrier == 0 && !fifo_config->carrier1) {
		LOG_ERR("Command uses carrier 0 but carrier1 is not configured");
		return -ENODEV;
	}

	if (cmd->carrier == 1 && !fifo_config->carrier2) {
		LOG_ERR("Command uses carrier 1 but carrier2 is not configured");
		return -ENODEV;
	}

	/* Check if FIFO is full */
	if (PWM_FIFO_STAT__FULL__READ(CMSDK_PWM->FIFO_STAT)) {
		return -ENOSPC;
	}

	/* Adjust count (hardware expects count-1) */
	uint16_t carrier_cnt = cmd->carrier_count - 1;

	/* Write command to FIFO */
	CMSDK_PWM->FIFO_DATA = (cmd->carrier << 15) | (cmd->carrier_on << 14) | carrier_cnt;

	return 0;
}

int pwm_atm_fifo_write_cmds(const struct device *dev, uint32_t channel,
			    const struct pwm_atm_fifo_cmd *cmds, size_t count)
{
	for (size_t i = 0; i < count; i++) {
		int ret = pwm_atm_fifo_write_cmd(dev, channel, &cmds[i]);
		if (ret < 0) {
			return ret;
		}
	}

	return 0;
}

int pwm_atm_fifo_start(const struct device *dev, uint32_t channel)
{
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST) {
		return -EINVAL;
	}

	/* Validate ownership and initialization */
	if (!pwm_atm_fifo_validate(dev, channel, data)) {
		return -ENODEV;
	}

#ifdef CONFIG_PM
	pwm_atm_pm_constraint_set(dev, channel);
#endif

	pwm_enable(channel);
	return 0;
}

int pwm_atm_fifo_stop(const struct device *dev, uint32_t channel)
{
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST) {
		return -EINVAL;
	}

	/* Validate ownership and initialization */
	if (!pwm_atm_fifo_validate(dev, channel, data)) {
		return -ENODEV;
	}

	pwm_disable(channel);

#ifdef CONFIG_PM
	pwm_atm_pm_constraint_release(dev, channel);
#endif

	return 0;
}

int pwm_atm_fifo_run_dma(const struct device *dev, uint32_t channel, const uint16_t *fifo_cmds,
			 size_t cmd_count)
{
#ifndef CONFIG_ATM_DMA
#error "PWM FIFO mode requires CONFIG_ATM_DMA to be enabled"
#endif
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST || !fifo_cmds || cmd_count == 0) {
		return -EINVAL;
	}

	/* Validate ownership and initialization */
	if (!pwm_atm_fifo_validate(dev, channel, data)) {
		return -ENODEV;
	}

#ifdef CONFIG_PM
	pwm_atm_pm_constraint_set(dev, channel);
#endif

	pwm_enable(channel);

	/* Use DMA for efficient bulk transfer */
#define PWM_FIFO_CMD_LEN 2
	dma_fifo_tx_async(DMA_FIFO_TX_PWM, fifo_cmds, PWM_FIFO_CMD_LEN * cmd_count, NULL, NULL);

	return 0;
}

int pwm_atm_fifo_get_free_slots(const struct device *dev, uint32_t channel)
{
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST) {
		return -EINVAL;
	}

	/* Validate ownership and initialization */
	if (!pwm_atm_fifo_validate(dev, channel, data)) {
		return -ENODEV;
	}

	return PWM_FIFO_STAT1__NUM_OPEN_SLOTS__READ(CMSDK_PWM->FIFO_STAT1);
}

bool pwm_atm_fifo_is_empty(const struct device *dev, uint32_t channel)
{
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST || !data->fifo_data[channel].initialized) {
		return false;
	}

	return PWM_FIFO_STAT__EMPTY__READ(CMSDK_PWM->FIFO_STAT);
}

bool pwm_atm_fifo_is_full(const struct device *dev, uint32_t channel)
{
	struct pwm_atm_data *data = DEV_DATA(dev);

	if (channel >= MAX_PWM_INST || !data->fifo_data[channel].initialized) {
		return true;
	}

	return PWM_FIFO_STAT__FULL__READ(CMSDK_PWM->FIFO_STAT);
}
#endif /* CONFIG_PWM_ATM_FIFO */

static int pwm_atm_init(struct device const *dev)
{
	struct pwm_atm_config const *config = DEV_CFG(dev);

	WRPR_CTRL_SET(CMSDK_PWM, PWM_CLK_CTRL);
	config->config_pins();

	return 0;
}

static struct pwm_driver_api const pwm_atm_driver_api = {
	.set_cycles = pwm_atm_set_cycles,
	.get_cycles_per_sec = pwm_atm_get_cycles_per_sec,
};

#define PWM_CTRL(n) CONCAT(CONCAT(&CMSDK_PWM->PWM, DT_INST_PROP(n, channel)), _CTRL)
#define PWM_MAX_FREQ(n) DT_PROP(DT_NODELABEL(pwm##n), max_frequency)
#define PWM_MIN_FREQ(n) DT_PROP(DT_NODELABEL(pwm##n), min_frequency)
#define PWM_MAX_DUTY_CYCLE(n) DT_PROP(DT_NODELABEL(pwm##n), max_duty_cycle)
#define PWM_MIN_DUTY_CYCLE(n) DT_PROP(DT_NODELABEL(pwm##n), min_duty_cycle)
#define PWM_DEVICE_INIT(n)                                                                         \
	static void pwm_atm_config_pins_##n(void)                                                  \
	{                                                                                          \
		PIN_SELECT(DT_INST_PROP(n, pin), PWM(n));                                          \
	}                                                                                          \
	static struct pwm_atm_data pwm_atm_data_##n;                                               \
	static struct pwm_atm_config const pwm_atm_config_##n = {                                  \
		.ctrl = PWM_CTRL(n),                                                               \
		.config_pins = pwm_atm_config_pins_##n,                                            \
		.max_freq = PWM_MAX_FREQ(n),                                                       \
		.min_freq = PWM_MIN_FREQ(n),                                                       \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(n, max_duty_cycle),                               \
		           (.max_duty_cycle = PWM_MAX_DUTY_CYCLE(n),))                             \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(n, min_duty_cycle),                               \
		           (.min_duty_cycle = PWM_MIN_DUTY_CYCLE(n),))                             \
	};                                                                                         \
	static struct pwm_atm_data pwm_atm_data_##n = {                                            \
		.period_cycles = {0},  /* Initialize all period tracking to 0 */                   \
	};                                                                                         \
	DEVICE_DT_INST_DEFINE(n, &pwm_atm_init, NULL, &pwm_atm_data_##n, &pwm_atm_config_##n,      \
		POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE, &pwm_atm_driver_api);

DT_INST_FOREACH_STATUS_OKAY(PWM_DEVICE_INIT)
