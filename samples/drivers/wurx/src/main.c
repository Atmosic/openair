/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/policy.h>
#include <zephyr/shell/shell.h>
#include <inttypes.h>
#include "reset.h"
#include "wurx.h"

LOG_MODULE_REGISTER(wurx_sample, LOG_LEVEL_INF);

#define WURX_NODE DT_NODELABEL(wurx)

static const struct device *wurx_dev = DEVICE_DT_GET(WURX_NODE);

static void check_wurx_wakeup(void)
{
	boot_status_t status = boot_status();

	/* Check for any WuRx wake-up events */
	if (status &
	    (BOOT_STATUS_HIB_WKUP_WURX0 | BOOT_STATUS_HIB_WKUP_WURX1 | BOOT_STATUS_HIB_WKUP_WURX)) {
		LOG_INF("WuRx wake-up event detected!");
		LOG_INF("Boot status: 0x%08" PRIx32, status);

		if (status & BOOT_STATUS_HIB_WKUP_WURX0) {
			LOG_INF("  - WuRx0 algorithm triggered");
		}
		if (status & BOOT_STATUS_HIB_WKUP_WURX1) {
			LOG_INF("  - WuRx1 algorithm triggered");
		}
		if (status & BOOT_STATUS_HIB_WKUP_WURX) {
			LOG_INF("  - General WuRx triggered");
		}
	}
}

static int wurx_sample_init(void)
{
	if (!device_is_ready(wurx_dev)) {
		LOG_ERR("WuRx device not ready");
		return -ENODEV;
	}

	LOG_INF("WuRx device ready");

	return 0;
}

int main(void)
{
	LOG_INF("WuRx Sample Application Starting");

	/* Check if we woke up from a WuRx event */
	check_wurx_wakeup();

	int ret = wurx_sample_init();
	if (ret < 0) {
		LOG_ERR("WuRx initialization failed: %d", ret);
		return ret;
	}

	LOG_INF("WuRx driver initialized and ready for wake-up detection");
	LOG_INF("Entering low power mode - will only wake on WuRx events");

	/* Enter low power mode permanently - only WuRx events will wake the system */
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);

	return 0;
}
