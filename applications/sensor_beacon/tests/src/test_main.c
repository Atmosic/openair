/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2025-2026 Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/settings/settings.h>
#include <inttypes.h>

#include "beacon_adv.h"

LOG_MODULE_REGISTER(test_main, CONFIG_SENSOR_BEACON_LOG_LEVEL);

/* Test suite declarations */
extern void test_sensor_interface_suite(void);
extern void test_battery_monitor_suite(void);
extern void test_beacon_adv_suite(void);
extern void test_sensor_data_suite(void);

static void *sensor_beacon_setup(void)
{
	LOG_INF("Setting up sensor beacon tests");
	return NULL;
}

static void sensor_beacon_teardown(void *fixture)
{
	LOG_INF("Tearing down sensor beacon tests");

	/* Clean up advertising set to prevent resource conflicts between tests */
	beacon_adv_stop();
}

/* Test suites */
ZTEST_SUITE(sensor_interface, NULL, sensor_beacon_setup, NULL, NULL, sensor_beacon_teardown);
ZTEST_SUITE(battery_monitor, NULL, sensor_beacon_setup, NULL, NULL, sensor_beacon_teardown);
ZTEST_SUITE(beacon_adv, NULL, sensor_beacon_setup, NULL, NULL, sensor_beacon_teardown);
ZTEST_SUITE(sensor_data, NULL, sensor_beacon_setup, NULL, NULL, sensor_beacon_teardown);

/* Main test entry point */
void test_main(void)
{
	LOG_INF("Starting sensor beacon test suite");

	/* Initialize Bluetooth subsystem once for all test suites */
	int ret = bt_enable(NULL);
	if (ret) {
		LOG_ERR("Bluetooth init failed: %d", ret);
	} else {
		LOG_INF("Bluetooth initialized for all test suites");
	}

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		ret = settings_load();
		if (ret) {
			LOG_ERR("Settings load failed: %d", ret);
		} else {
			LOG_INF("Settings loaded");
		}
	}

	/* Run all test suites */
	ztest_run_test_suites(NULL, false, 1, 1);
}
