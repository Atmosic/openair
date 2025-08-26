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

#ifdef CONFIG_ATM_BUZZER
#include <zephyr/drivers/pwm.h>
#include "atm_buzzer.h"

#define BUZZER_NODE DT_NODELABEL(buzzer)
#define BUZZER_PWM_NODE DT_PHANDLE(BUZZER_NODE, pwms)
BUILD_ASSERT(DT_NODE_EXISTS(BUZZER_NODE), "BUZZER_NODE does not exist in the Device Tree!");

static atm_buzzer_t buzzer_cfg = {
	.pwm_dt = PWM_DT_SPEC_GET(BUZZER_NODE),
	.pulse = DT_PROP(BUZZER_NODE, pulse),
	.min_frequency = DT_PROP(BUZZER_PWM_NODE, min_frequency),
	.max_frequency = DT_PROP(BUZZER_PWM_NODE, max_frequency),
};
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
#ifdef CONFIG_ATM_BUZZER
	atm_buzzer_onoff(&buzzer_cfg, action);
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
