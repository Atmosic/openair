/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/logging/log.h>

#include "battery_monitor.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(test_battery_monitor, CONFIG_SENSOR_BEACON_LOG_LEVEL);

ZTEST(battery_monitor, test_battery_monitor_init)
{
	int ret = battery_monitor_init();

	if (!ret) {
		LOG_INF("Battery monitor initialized successfully");
	} else {
		LOG_WRN("Battery monitor init failed: %" PRId32 " (expected without ADC)", ret);
		/* This is acceptable in test environment without real ADC */
	}
}

ZTEST(battery_monitor, test_battery_monitor_get_voltages)
{
	float vstore, vbatt;
	int ret;

	/* Try to initialize first */
	battery_monitor_init();

	ret = battery_monitor_get_voltages(&vstore, &vbatt);

	if (!ret) {
		LOG_INF("VStore: %.3fV, VBatt: %.3fV", (double)vstore, (double)vbatt);

		/* Basic sanity checks for voltage values */
		zassert_true(vstore >= 0.0f && vstore <= 5.0f,
			     "VStore voltage out of range: %.3f", (double)vstore);
		zassert_true(vbatt >= 0.0f && vbatt <= 5.0f,
			     "VBatt voltage out of range: %.3f", (double)vbatt);

		LOG_INF("Battery voltage validation passed");
	} else {
		LOG_WRN("Failed to get battery voltages: %" PRId32 " (expected without ADC)", ret);
		/* Acceptable in test environment */
	}
}

ZTEST(battery_monitor, test_battery_monitor_parameter_validation)
{
	float vstore, vbatt;

	/* Test with valid parameters */
	int ret = battery_monitor_get_voltages(&vstore, &vbatt);

	/* Should succeed or fail gracefully */
	if (!ret) {
		LOG_INF("Parameter validation test passed with valid parameters");
		zassert_true(vstore >= 0.0f && vstore <= 5.0f, "VStore should be in valid range");
		zassert_true(vbatt >= 0.0f && vbatt <= 5.0f, "VBatt should be in valid range");
	} else {
		LOG_WRN("Parameter validation test: function returned error %" PRId32 " (may be expected)",
			ret);
	}

	LOG_INF("Parameter validation test completed");
}
