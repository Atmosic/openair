/*
 * Copyright (c) 2025, Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(atm_buzzer, CONFIG_ATM_BUZZER_LOG_LEVEL);

#include "at_wrpr.h"
#include "atm_utils_math.h"
#include "atm_buzzer.h"
#ifndef PWM_PWM0_CTRL__TOT_DUR__READ
#define SYS_CLK_IN_KHZ (PCLK_ALT_FREQ / 1000) // PWM block runs on 16MHz clock domain
#endif
#define SYS_CLK_IN_HZ (SYS_CLK_IN_KHZ * 1000)

static bool atm_buzzer_cal_hi_lo_duration(atm_buzzer_t *buzzer, uint32_t freq_hz, uint8_t duty_percent)
{
	if ((freq_hz < buzzer->min_frequency) || (freq_hz > buzzer->max_frequency)) {
		LOG_ERR("freq out of range, freq_hz:%d, min:%d, max:%d", freq_hz, buzzer->min_frequency, buzzer->max_frequency);
		return false;
	}
	if (duty_percent > 100) {
		LOG_ERR("duty_percent out of range, duty_percent:%d", duty_percent);
		return false;
	}

	uint64_t period_ns = PWM_HZ(freq_hz);
	uint64_t pulse_ns = (period_ns * duty_percent) / 100;

	buzzer->pwm_dt.period = (uint32_t)period_ns;
	buzzer->pulse = (uint32_t)pulse_ns;
	return true;
}

static bool atm_buzzer_check_valid(atm_buzzer_t *buzzer)
{
	if (!buzzer) {
		LOG_ERR("buzzer is NULL");
		return false;
	}

	if (!device_is_ready(buzzer->pwm_dt.dev)) {
		LOG_ERR("PWM device not ready");
		return false;
	}

	if (!buzzer->pulse) {
		LOG_ERR("Pulse width is zero");
		return false;
	}

	if (buzzer->max_frequency < buzzer->min_frequency) {
		LOG_ERR("Max frequency is less than min frequency");
		return false;
	}

	return true;
}

atm_buzzer_error_t atm_buzzer_onoff(atm_buzzer_t *buzzer, bool action_on)
{
	LOG_DBG("buzzer onoff:%d", action_on);
	if (!atm_buzzer_check_valid(buzzer)) {
		return BUZ_PARAM_INCORRECT;
	}
#ifdef CONFIG_ATM_BUZZER_TIMEOUT
	k_work_cancel_delayable(&buzzer->stop_work);
#endif
	if (action_on) {
		pwm_set_pulse_dt(&buzzer->pwm_dt, buzzer->pulse);
		buzzer->active = true;
	} else {
		pwm_set_pulse_dt(&buzzer->pwm_dt, 0);
		buzzer->active = false;
	}
	return BUZ_NO_ERROR;
}

atm_buzzer_error_t atm_buzzer_configure(atm_buzzer_t *buzzer, uint32_t freq_hz, uint32_t duty_percent)
{
	LOG_DBG("buzzer cfg, ch:%d, freq_hz:%d, duty:%d", buzzer->pwm_dt.channel, freq_hz, duty_percent);
	if (!atm_buzzer_check_valid(buzzer)) {
		return BUZ_PARAM_INCORRECT;
	}
	if (!atm_buzzer_cal_hi_lo_duration(buzzer, freq_hz, duty_percent)) {
		LOG_ERR("Failed to calculate hi/lo duration");
		return BUZ_PARAM_INCORRECT;
	}
	return BUZ_NO_ERROR;
}

atm_buzzer_error_t atm_buzzer_beep(atm_buzzer_t *buzzer, uint32_t freq_hz, uint32_t duty_percent)
{
	if (atm_buzzer_configure(buzzer, freq_hz, duty_percent)) {
		LOG_ERR("Failed to configure buzzer");
		return BUZ_PARAM_INCORRECT;
	}
	pwm_set_pulse_dt(&buzzer->pwm_dt, buzzer->pulse);
	buzzer->active = true;
	return BUZ_NO_ERROR;
}

#ifdef CONFIG_ATM_BUZZER_TIMEOUT
atm_buzzer_error_t atm_buzzer_beep_time(atm_buzzer_t *buzzer, uint32_t freq_hz, uint8_t duty_percent, uint32_t duration_ms)
{
	if (atm_buzzer_beep(buzzer, freq_hz, duty_percent)) {
		LOG_ERR("Failed to configure buzzer");
		return BUZ_PARAM_INCORRECT;
	}

	buzzer->active = true;

	// Cancel any previous stop_work
	k_work_cancel_delayable(&buzzer->stop_work);

	// Schedule auto-stop
	if (duration_ms) {
		k_work_schedule(&buzzer->stop_work, K_MSEC(duration_ms));
	}

	return BUZ_NO_ERROR;
}

static void atm_buzzer_stop_handler(struct k_work *work)
{
	struct k_work_delayable *dwork = k_work_delayable_from_work(work);
	atm_buzzer_t *buzzer = CONTAINER_OF(dwork, atm_buzzer_t, stop_work);

	pwm_set_pulse_dt(&buzzer->pwm_dt, 0);
	buzzer->active = false;

	if (buzzer->stop_cb) {
		buzzer->stop_cb(buzzer);
	}
}

atm_buzzer_error_t atm_buzzer_cb_reg(atm_buzzer_t *buzzer)
{
	if (!buzzer || !buzzer->stop_cb) {
		LOG_ERR("Invalid buzzer or callback function");
		return BUZ_PARAM_INCORRECT;
	}
	k_work_init_delayable(&buzzer->stop_work, atm_buzzer_stop_handler);
	buzzer->active = false;
	return BUZ_NO_ERROR;
}
#endif
