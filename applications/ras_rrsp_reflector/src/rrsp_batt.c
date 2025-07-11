/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "rrsp_batt.h"

LOG_MODULE_REGISTER(rrsp_bat, CONFIG_RRSP_BAT_LOG_LEVEL);

static int32_t last_batt_mv = 3000;

#ifdef CONFIG_BATT_MODEL
#include <zephyr/init.h>
#include "batt_model.h"
static void rrsp_batt_cb(uint16_t lvl, int32_t mvolt)
{
	last_batt_mv = mvolt;
	LOG_DBG("update last_battery_vol to %d (lvl: %u)", last_batt_mv, lvl);
}

static int rrsp_batt_init(void)
{
	batt_model()->init(NULL);
	return 0;
}

SYS_INIT(rrsp_batt_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);
#endif // CONFIG_BATT_MODEL

int32_t rrsp_batt_status_get(void)
{
#ifdef CONFIG_BATT_MODEL
	batt_model()->sample(rrsp_batt_cb);
#endif
	return last_batt_mv;
}
