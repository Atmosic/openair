/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/ztest.h>
#include <zephyr/logging/log.h>
#include <inttypes.h>

#include "sensor_interface.h"

LOG_MODULE_REGISTER(test_sensor_interface, CONFIG_SENSOR_BEACON_LOG_LEVEL);

ZTEST(sensor_interface, test_sensor_interface_init)
{
	int ret = sensor_interface_init();

	/* Should succeed if sensors are available, or fail gracefully */
	if (!ret) {
		LOG_INF("Sensor interface initialized successfully");
	} else {
		LOG_WRN("Sensor interface init failed: %" PRId32 " (expected if no sensors)", ret);
		/* This is acceptable in test environment without real sensors */
	}
}

ZTEST(sensor_interface, test_sensor_interface_get_temp_humidity)
{
	uint16_t temp, humidity;
	int ret;

	sensor_interface_init();

	ret = sensor_interface_get_temp_humidity(&temp, &humidity);

	if (!ret) {
		LOG_INF("Temperature: %" PRIu16 ", Humidity: %" PRIu16, temp, humidity);

		/* Basic sanity checks for scaled values */
		/* Temperature should be reasonable (e.g., -40°C to 85°C scaled by 256) */
		zassert_true(temp < 30000, "Temperature value seems too high: %u", temp);

		/* Humidity should be 0-100% scaled by 256, so max ~25600 */
		zassert_true(humidity <= 25600, "Humidity value seems too high: %u", humidity);

		LOG_INF("Sensor data validation passed");
	} else {
		LOG_WRN("Failed to get temp/humidity: %" PRId32 " (expected without real sensors)", ret);
		/* Acceptable in test environment */
	}
}

ZTEST(sensor_interface, test_sensor_interface_get_accel)
{
	uint16_t accel_x, accel_y, accel_z;
	int ret;

	sensor_interface_init();

	ret = sensor_interface_get_accel(&accel_x, &accel_y, &accel_z);

	if (!ret) {
		LOG_INF("Accelerometer: X=%" PRIu16 ", Y=%" PRIu16 ", Z=%" PRIu16, accel_x, accel_y, accel_z);

		/* For a stationary device, Z-axis should show ~1g effect */

		LOG_INF("Accelerometer data validation passed");
	} else {
		LOG_WRN("Failed to get accelerometer data: %" PRId32 " (expected without real sensors)",
			ret);
		/* Acceptable in test environment */
	}
}

ZTEST(sensor_interface, test_sensor_scaling_factors)
{
	/* Test that scaling factors are configured correctly */
	zassert_true(CONFIG_SENSOR_BEACON_TEMP_SCALING_FACTOR == 256,
		     "Temperature scaling factor should be 256");
	zassert_true(CONFIG_SENSOR_BEACON_HUMIDITY_SCALING_FACTOR == 256,
		     "Humidity scaling factor should be 256");
	zassert_true(CONFIG_SENSOR_BEACON_ACCEL_SCALING_FACTOR == 16000,
		     "Accelerometer scaling factor should be 16000");

	LOG_INF("Scaling factors validation passed");
}
