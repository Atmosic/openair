/**
 *******************************************************************************
 *
 * @file platform_ctrl_battery.c
 *
 * @brief Platform control battery For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "platform_ctrl_battery.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

static uint8_t last_battery_percentage = 100;

#ifdef CONFIG_BATT_MODEL
#include <zephyr/init.h>
#include "batt_model.h"
static void platform_ctrl_batt_cb(uint16_t lvl_bp, int32_t mvolt)
{
	last_battery_percentage = lvl_bp / 100;
	LOG_DBG("update last_battery_percentage to %u (lvl_bp: %u)", last_battery_percentage,
		lvl_bp);
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
