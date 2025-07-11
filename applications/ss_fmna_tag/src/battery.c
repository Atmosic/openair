/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <zephyr/logging/log.h>
#include <stdbool.h>
#include "fmna_api.h"
#include "battery.h"

LOG_MODULE_REGISTER(battery, LOG_LEVEL_DBG);

static fmna_bat_state_level_t last_lvl = BAT_STATE_FULL;

#ifdef CONFIG_BATT_MODEL
#include <zephyr/device.h>
#include <zephyr/init.h>
#include "batt_model.h"

static void batt_sample_cb(uint16_t lvl, int32_t mvolt)
{
    ARG_UNUSED(mvolt);
    if (lvl > 8500) {
	last_lvl = BAT_STATE_FULL;
    } else if (lvl > 3000) {
	last_lvl = BAT_STATE_MEDIUM;
    } else if (lvl > 1000) {
	last_lvl = BAT_STATE_LOW;
    } else {
	last_lvl = BAT_STATE_CRITICALLY_LOW;
    }
}

static int batt_model_init(void)
{
    batt_model()->init(NULL);
    return 0;
}

SYS_INIT(batt_model_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);
#endif

fmna_bat_state_level_t battery_level_get(void)
{
#ifdef CONFIG_BATT_MODEL
    batt_model()->sample(batt_sample_cb);
#endif
    LOG_DBG("Battery level: %d\n", last_lvl);
    return last_lvl;
}
