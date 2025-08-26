/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/logging/log.h>
#include <inttypes.h>

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

	/* Run all test suites */
	ztest_run_test_suites(NULL, false, 1, 1);
}
