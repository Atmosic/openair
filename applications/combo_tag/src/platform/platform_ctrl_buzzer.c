/**
 *******************************************************************************
 *
 * @file platform_ctrl_buzzer.c
 *
 * @brief Platform control buzzer For FMNA and FMDN Combo Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include "platform_ctrl_buzzer.h"

LOG_MODULE_DECLARE(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

#ifdef CONFIG_PWM_BUZZER
#include <zephyr/drivers/pwm.h>
#define BUZZER_NODE DT_NODELABEL(buzzer)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");
#endif

void platform_ctrl_buzzer_action(bool action)
{
	LOG_DBG("buzzer action %u", action);
#ifdef CONFIG_PWM_BUZZER
	static const struct pwm_dt_spec pwm_dt = PWM_DT_SPEC_GET(BUZZER_NODE);
	if (action) {
		pwm_set_pulse_dt(&pwm_dt, DT_PROP(BUZZER_NODE, pulse));
		LOG_DBG("Buzzer Started");
	} else {
		pwm_set_pulse_dt(&pwm_dt, 0);
		LOG_DBG("Buzzer Stopped");
	}
#endif
}

void platform_ctrl_buzzer_init(void)
{
	// todo something here
}
