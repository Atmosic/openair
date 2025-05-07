/**
 *******************************************************************************
 *
 * @file fp_tag_platform_ctrl.c
 *
 * @brief Platform control For fp tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "fp_tag_platform_ctrl.h"

LOG_MODULE_DECLARE(fp_tag, CONFIG_FP_TAG_LOG_LEVEL);

static uint8_t last_battery_percentage = 100;

#ifdef CONFIG_PWM_BUZZER
#include <zephyr/drivers/pwm.h>
#define BUZZER_NODE DT_NODELABEL(buzzer)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");
#endif

#ifdef CONFIG_BATT_MODEL
#include <zephyr/init.h>
#include "batt_model.h"
static void fp_tag_platform_ctrl_batt_cb(uint16_t lvl, int32_t mvolt)
{
	last_battery_percentage = lvl / 100;
	LOG_DBG("update last_battery_percentage to %u (lvl: %u)", last_battery_percentage, lvl);
}

static int fp_tag_platform_ctrl_batt_init(void)
{
	batt_model()->init(NULL);
	return 0;
}

SYS_INIT(fp_tag_platform_ctrl_batt_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);
#endif // CONFIG_BATT_MODEL

void fp_tag_platform_ctrl_motion_detect_action(bool action)
{
	LOG_DBG("motion_detect action %u", action);
}

void fp_tag_platform_ctrl_buzzer_action(bool action)
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

uint8_t fp_tag_platform_battery_status_get(void)
{
#ifdef CONFIG_BATT_MODEL
	batt_model()->sample(fp_tag_platform_ctrl_batt_cb);
#endif
	return last_battery_percentage;
}

void fp_tag_platform_ctrl_init(void)
{
	// todo something here
}

void fp_tag_platform_ctrl_reset(void)
{
	// todo something here
}
