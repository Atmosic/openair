/*
 * Copyright (c) 2025-2026, Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/pwm.h>
LOG_MODULE_REGISTER(atm_buzzer, CONFIG_ATM_BUZZER_LOG_LEVEL);

#include "at_wrpr.h"
#include "atm_buzzer.h"

#define DT_DRV_COMPAT atmosic_atm3x_pwm_buzzer

#ifndef PWM_PWM0_CTRL__TOT_DUR__READ
#define SYS_CLK_IN_KHZ (PCLK_ALT_FREQ / 1000) // PWM block runs on 16MHz clock domain
#endif
#define SYS_CLK_IN_HZ (SYS_CLK_IN_KHZ * 1000)

/* Device runtime data (RAM) */
struct atm_buzzer_data {
	const struct device *dev; /* Back pointer to device */
	struct k_mutex lock;
	uint32_t period;
	uint32_t pulse;
	bool active;
#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	struct k_work_delayable stop_work;
	atm_buzzer_stop_cb_t stop_cb;
#endif
};

/* Device configuration (ROM) */
struct atm_buzzer_config {
	struct pwm_dt_spec pwm_dt;
	uint32_t min_frequency;
	uint32_t max_frequency;
};

static bool atm_buzzer_cal_hi_lo_duration(const struct device *dev, uint32_t freq_hz,
					  uint8_t duty_percent, uint32_t *period_out,
					  uint32_t *pulse_out)
{
	const struct atm_buzzer_config *config = dev->config;

	if ((freq_hz < config->min_frequency) || (freq_hz > config->max_frequency)) {
		LOG_ERR("freq out of range, freq_hz:%d, min:%d, max:%d", freq_hz,
			config->min_frequency, config->max_frequency);
		return false;
	}
	if (duty_percent > 100) {
		LOG_ERR("duty_percent out of range, duty_percent:%d", duty_percent);
		return false;
	}

	uint64_t period_ns = PWM_HZ(freq_hz);
	uint64_t pulse_ns = (period_ns * duty_percent) / 100;

	*period_out = (uint32_t)period_ns;
	*pulse_out = (uint32_t)pulse_ns;
	return true;
}

static bool atm_buzzer_check_valid(const struct device *dev)
{
	const struct atm_buzzer_config *config = dev->config;

	if (!dev) {
		LOG_ERR("device is NULL");
		return false;
	}

	if (!device_is_ready(config->pwm_dt.dev)) {
		LOG_ERR("PWM device not ready");
		return false;
	}

	if (config->max_frequency < config->min_frequency) {
		LOG_ERR("Max frequency is less than min frequency");
		return false;
	}

	return true;
}

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
static void atm_buzzer_stop_handler(struct k_work *work)
{
	struct k_work_delayable *dwork = k_work_delayable_from_work(work);
	struct atm_buzzer_data *data = CONTAINER_OF(dwork, struct atm_buzzer_data, stop_work);
	const struct device *dev = data->dev;
	const struct atm_buzzer_config *config = dev->config;

	k_mutex_lock(&data->lock, K_FOREVER);

	pwm_set_pulse_dt(&config->pwm_dt, 0);
	data->active = false;

	if (data->stop_cb) {
		data->stop_cb(dev);
	}

	k_mutex_unlock(&data->lock);
}
#endif

/* Internal configure function - caller must hold the mutex */
static atm_buzzer_error_t atm_buzzer_configure_locked(const struct device *dev, uint32_t freq_hz,
						      uint32_t duty_percent)
{
	struct atm_buzzer_data *data = dev->data;
	const struct atm_buzzer_config *config = dev->config;

	LOG_DBG("buzzer cfg, ch:%d, freq_hz:%d, duty:%d", config->pwm_dt.channel, freq_hz,
		duty_percent);

	if (!atm_buzzer_check_valid(dev)) {
		return BUZ_PARAM_INCORRECT;
	}

	if (!atm_buzzer_cal_hi_lo_duration(dev, freq_hz, duty_percent, &data->period,
					   &data->pulse)) {
		LOG_ERR("Failed to calculate hi/lo duration");
		return BUZ_PARAM_INCORRECT;
	}

	return BUZ_NO_ERROR;
}

static atm_buzzer_error_t atm_buzzer_onoff_impl(const struct device *dev, bool action_on)
{
	struct atm_buzzer_data *data = dev->data;
	const struct atm_buzzer_config *config = dev->config;

	LOG_DBG("buzzer onoff:%d", action_on);

	k_mutex_lock(&data->lock, K_FOREVER);

	atm_buzzer_error_t ret = BUZ_NO_ERROR;

	if (!atm_buzzer_check_valid(dev)) {
		ret = BUZ_PARAM_INCORRECT;
	} else {
#ifdef CONFIG_ATM_BUZZER_TIMEOUT
		k_work_cancel_delayable(&data->stop_work);
#endif

		if (action_on) {
			pwm_set_dt(&config->pwm_dt, data->period, data->pulse);
			data->active = true;
		} else {
			pwm_set_pulse_dt(&config->pwm_dt, 0);
			data->active = false;
		}
	}

	k_mutex_unlock(&data->lock);

	return ret;
}

static atm_buzzer_error_t atm_buzzer_configure_impl(const struct device *dev, uint32_t freq_hz,
						    uint32_t duty_percent)
{
	struct atm_buzzer_data *data = dev->data;

	k_mutex_lock(&data->lock, K_FOREVER);
	atm_buzzer_error_t ret = atm_buzzer_configure_locked(dev, freq_hz, duty_percent);
	k_mutex_unlock(&data->lock);

	return ret;
}

static atm_buzzer_error_t atm_buzzer_beep_impl(const struct device *dev, uint32_t freq_hz,
					       uint32_t duty_percent)
{
	struct atm_buzzer_data *data = dev->data;
	const struct atm_buzzer_config *config = dev->config;

	k_mutex_lock(&data->lock, K_FOREVER);

	atm_buzzer_error_t ret = atm_buzzer_configure_locked(dev, freq_hz, duty_percent);

	if (ret != BUZ_NO_ERROR) {
		LOG_ERR("Failed to configure buzzer");
	} else {
		pwm_set_dt(&config->pwm_dt, data->period, data->pulse);
		data->active = true;
	}

	k_mutex_unlock(&data->lock);

	return ret;
}

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
static atm_buzzer_error_t atm_buzzer_beep_time_impl(const struct device *dev, uint32_t freq_hz,
						    uint8_t duty_percent, uint32_t duration_ms)
{
	struct atm_buzzer_data *data = dev->data;
	const struct atm_buzzer_config *config = dev->config;

	k_mutex_lock(&data->lock, K_FOREVER);

	atm_buzzer_error_t ret = atm_buzzer_configure_locked(dev, freq_hz, duty_percent);

	if (ret != BUZ_NO_ERROR) {
		LOG_ERR("Failed to configure buzzer");
	} else {
		/* Cancel any previous stop_work */
		k_work_cancel_delayable(&data->stop_work);

		pwm_set_dt(&config->pwm_dt, data->period, data->pulse);
		data->active = true;

		/* Schedule auto-stop */
		if (duration_ms) {
			k_work_schedule(&data->stop_work, K_MSEC(duration_ms));
		}
	}

	k_mutex_unlock(&data->lock);

	return ret;
}

static int atm_buzzer_set_stop_callback_impl(const struct device *dev,
					     atm_buzzer_stop_cb_t callback)
{
	struct atm_buzzer_data *data = dev->data;

	k_mutex_lock(&data->lock, K_FOREVER);
	data->stop_cb = callback;
	k_mutex_unlock(&data->lock);

	return 0;
}
#endif

/* Driver API structure */
static const struct atm_buzzer_api atm_buzzer_driver_api = {
	.onoff = atm_buzzer_onoff_impl,
	.configure = atm_buzzer_configure_impl,
	.beep = atm_buzzer_beep_impl,
#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	.beep_time = atm_buzzer_beep_time_impl,
	.set_stop_callback = atm_buzzer_set_stop_callback_impl,
#endif
};

/* Device initialization function */
static int atm_buzzer_init(const struct device *dev)
{
	struct atm_buzzer_data *data = dev->data;
	const struct atm_buzzer_config *config = dev->config;

	/* Store back pointer to device */
	data->dev = dev;

	/* Check if PWM device is ready */
	if (!device_is_ready(config->pwm_dt.dev)) {
		LOG_ERR("PWM device %s is not ready", config->pwm_dt.dev->name);
		return -ENODEV;
	}

	/* Validate configuration */
	if (config->max_frequency < config->min_frequency) {
		LOG_ERR("Max frequency (%u) is less than min frequency (%u)", config->max_frequency,
			config->min_frequency);
		return -EINVAL;
	}

	/* Initialize mutex */
	k_mutex_init(&data->lock);

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	/* Initialize delayed work for auto-stop */
	k_work_init_delayable(&data->stop_work, atm_buzzer_stop_handler);
#endif

	LOG_DBG("Buzzer initialized: PWM %s, freq range %u-%u Hz", config->pwm_dt.dev->name,
		config->min_frequency, config->max_frequency);

	return 0;
}

/* Device instantiation macro */
#define ATM_BUZZER_DEFINE(inst)                                                                    \
	static struct atm_buzzer_data atm_buzzer_data_##inst;                                      \
                                                                                                   \
	static const struct atm_buzzer_config atm_buzzer_config_##inst = {                         \
		.pwm_dt = PWM_DT_SPEC_INST_GET(inst),                                              \
		.min_frequency = DT_INST_PROP(inst, min_frequency),                                \
		.max_frequency = DT_INST_PROP(inst, max_frequency),                                \
	};                                                                                         \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(inst, atm_buzzer_init, NULL, &atm_buzzer_data_##inst,                \
			      &atm_buzzer_config_##inst, POST_KERNEL,                              \
			      CONFIG_KERNEL_INIT_PRIORITY_DEVICE, &atm_buzzer_driver_api);

/* Create device instances for all enabled nodes in devicetree */
DT_INST_FOREACH_STATUS_OKAY(ATM_BUZZER_DEFINE)
