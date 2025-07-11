/**
 *******************************************************************************
 *
 * @file platform_ctrl_battery.c
 *
 * @brief Platform control battery For FMNA and FMDN Combo Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "platform_ctrl_battery.h"

LOG_MODULE_DECLARE(combo_tag, CONFIG_COMBO_TAG_LOG_LEVEL);

static uint8_t last_battery_percentage = 100;

#ifdef CONFIG_BATT_MODEL
#include <zephyr/init.h>
#include "batt_model.h"
static void platform_ctrl_batt_cb(uint16_t lvl, int32_t mvolt)
{
	last_battery_percentage = lvl / 100;
	LOG_DBG("update last_battery_percentage to %u (lvl: %u)", last_battery_percentage, lvl);
}

static int platform_ctrl_batt_init(void)
{
	batt_model()->init(NULL);
	return 0;
}

SYS_INIT(platform_ctrl_batt_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);
#endif // CONFIG_BATT_MODEL

uint8_t platform_ctrl_batt_status_get(void)
{
#ifdef CONFIG_BATT_MODEL
	batt_model()->sample(platform_ctrl_batt_cb);
#endif
	return last_battery_percentage;
}
