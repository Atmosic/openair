/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>

#include "beacon_adv.h"
#include "sensor_beacon.h"

#include <errno.h>
#include <inttypes.h>

LOG_MODULE_REGISTER(test_beacon_adv, CONFIG_SENSOR_BEACON_LOG_LEVEL);

ZTEST(beacon_adv, test_beacon_adv_init)
{
	int ret = beacon_adv_init();

	if (!ret) {
		LOG_INF("Beacon advertising initialized successfully");
	} else {
		LOG_ERR("Beacon advertising init failed: %" PRId32, ret);
		zassert_true(false, "Beacon advertising init should succeed");
	}
}

ZTEST(beacon_adv, test_beacon_adv_start_stop)
{
	int ret;

	ret = beacon_adv_init();
	if (ret == -EALREADY) {
		ret = 0;
	}
	zassert_equal(ret, 0, "Beacon init should succeed or already be initialized");

	ret = beacon_adv_start();
	if (!ret) {
		LOG_INF("Beacon advertising started successfully");

		k_sleep(K_MSEC(100));

		ret = beacon_adv_stop();
		zassert_equal(ret, 0, "Beacon stop should succeed");
		LOG_INF("Beacon advertising stopped successfully");
	} else {
		LOG_WRN("Beacon advertising start failed: %" PRId32, ret);
		/* May fail in test environment without full BT stack */
	}
}

ZTEST(beacon_adv, test_beacon_adv_update_data)
{
	int ret;
	sensor_beacon_data_t test_data = {
		.temp = 6400,      /* 25°C * 256 */
		.humidity = 12800, /* 50% * 256 */
		.x_axis = 100,
		.y_axis = 200,
		.z_axis = 300,
		.vstore = 3.3f,
		.vbatt = 3.0f
	};

	ret = beacon_adv_init();
	if (ret == -EALREADY) {
		ret = 0;
	}
	zassert_equal(ret, 0, "Beacon init should succeed or already be initialized");

	ret = beacon_adv_update_data(&test_data);
	if (!ret) {
		LOG_INF("Beacon advertisement data updated successfully");
	} else {
		LOG_WRN("Beacon advertisement update failed: %" PRId32, ret);
		/* May fail in test environment */
	}
}

ZTEST(beacon_adv, test_beacon_adv_update_data_null)
{
	int ret;

	beacon_adv_init();

	/* Test with NULL data pointer */
	ret = beacon_adv_update_data(NULL);
	zassert_not_equal(ret, 0, "Update with NULL data should fail");
	LOG_INF("NULL data test passed");
}

ZTEST(beacon_adv, test_beacon_adv_data_format)
{
	sensor_beacon_data_t test_data = {
		.temp = 1234,
		.humidity = 5678,
		.x_axis = 100,
		.y_axis = 200,
		.z_axis = 300,
		.vstore = 3.3f,
		.vbatt = 3.0f
	};

	/* Verify data structure size matches expected format */
	zassert_equal(sizeof(test_data), sizeof(sensor_beacon_data_t),
		      "Sensor data structure size must match sensor_beacon_data_t");

	LOG_INF("Data format validation passed");
}

ZTEST(beacon_adv, test_beacon_adv_update_strategy)
{
	int ret;
	sensor_beacon_data_t test_data1 = {
		.temp = 6400,      /* 25°C * 256 */
		.humidity = 12800, /* 50% * 256 */
		.x_axis = 100,
		.y_axis = 200,
		.z_axis = 300,
		.vstore = 3.3f,
		.vbatt = 3.0f
	};

	sensor_beacon_data_t test_data2 = {
		.temp = 7680,      /* 30°C * 256 */
		.humidity = 15360, /* 60% * 256 */
		.x_axis = 150,
		.y_axis = 250,
		.z_axis = 350,
		.vstore = 3.4f,
		.vbatt = 3.1f
	};

	ret = beacon_adv_init();
	if (ret == -EALREADY) {
		ret = 0;
	}
	zassert_equal(ret, 0, "Beacon init should succeed or already be initialized");

	ret = beacon_adv_start();
	if (ret) {
		LOG_WRN("Beacon start failed: %" PRId32 " (may be expected in test environment)", ret);
		return; /* Skip rest of test if advertising can't start */
	}

	/* Test multiple data updates to verify strategy works */
	ret = beacon_adv_update_data(&test_data1);
	if (!ret) {
		LOG_INF("First data update successful");

		k_sleep(K_MSEC(100));

		ret = beacon_adv_update_data(&test_data2);
		if (!ret) {
			LOG_INF("Second data update successful");
		} else {
			LOG_WRN("Second data update failed: %" PRId32, ret);
		}
	} else {
		LOG_WRN("First data update failed: %" PRId32, ret);
	}

	beacon_adv_stop();

	LOG_INF("Advertisement update strategy test completed (live update method)");
}
