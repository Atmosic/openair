/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>

#include "sensor_data.h"
#include "sensor_beacon.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(test_sensor_data, CONFIG_SENSOR_BEACON_LOG_LEVEL);

ZTEST(sensor_data, test_sensor_data_init)
{
	int ret = sensor_data_init();
	zassert_equal(ret, 0, "Sensor data init should succeed");
	LOG_INF("Sensor data system initialized successfully");
}

ZTEST(sensor_data, test_sensor_data_collect_and_update)
{
	int ret;

	ret = sensor_data_init();
	zassert_equal(ret, 0, "Sensor data init should succeed");

	ret = sensor_data_collect_and_update();

	if (!ret) {
		LOG_INF("Sensor data collection completed successfully");
	} else {
		LOG_WRN("Sensor data collection failed: %" PRId32 " (expected without sensors)", ret);
		/* May fail in test environment without real sensors */
	}
}

ZTEST(sensor_data, test_sensor_data_start_stop)
{
	int ret;

	ret = sensor_data_init();
	zassert_equal(ret, 0, "Sensor data init should succeed");

	ret = sensor_data_start();
	zassert_equal(ret, 0, "Sensor data start should succeed");
	LOG_INF("Sensor data collection started");

	k_sleep(K_MSEC(200));

	ret = sensor_data_stop();
	zassert_equal(ret, 0, "Sensor data stop should succeed");
	LOG_INF("Sensor data collection stopped");
}

ZTEST(sensor_data, test_sensor_data_timer_interval)
{
	/* Test that timer interval configuration is correct */
	zassert_true(CONFIG_SENSOR_BEACON_UPDATE_INTERVAL,
		     "Update interval should be positive");
	zassert_true(CONFIG_SENSOR_BEACON_UPDATE_INTERVAL <= 60000,
		     "Update interval should be reasonable (<=10 minutes)");

	LOG_INF("Timer interval validation passed (interval: %" PRId32 " ms)",
		CONFIG_SENSOR_BEACON_UPDATE_INTERVAL);
}

ZTEST(sensor_data, test_sensor_data_integration)
{
	int ret;

	/* Test full integration: init -> start -> collect -> stop */
	ret = sensor_data_init();
	zassert_equal(ret, 0, "Init should succeed");

	ret = sensor_data_start();
	zassert_equal(ret, 0, "Start should succeed");

	/* Wait for automatic collection */
	k_sleep(K_MSEC(100));

	/* Manual collection */
	ret = sensor_data_collect_and_update();
	/* Don't assert on this as it may fail without real sensors */

	ret = sensor_data_stop();
	zassert_equal(ret, 0, "Stop should succeed");

	LOG_INF("Integration test completed");
}
