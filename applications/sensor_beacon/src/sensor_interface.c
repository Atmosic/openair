/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/__assert.h>
#include <zephyr/sys/util.h>
#include <math.h>

#include "sensor_interface.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(sensor_interface, CONFIG_SENSOR_BEACON_LOG_LEVEL);

static const struct device *const ens_dev = DEVICE_DT_GET_ONE(ams_ens210);
static const struct device *const lis_dev = DEVICE_DT_GET_ANY(st_lis2dh);

int sensor_interface_init(void)
{
	__ASSERT(ens_dev, "Cannot get ENS210 device");
	if (!device_is_ready(ens_dev)) {
		LOG_ERR("ENS210 device %s is not ready", ens_dev->name);
		return -ENODEV;
	}
	LOG_INF("ENS210 sensor initialized");

	/* Give ENS210 time to stabilize after initialization */
	k_sleep(K_MSEC(50));

	__ASSERT(lis_dev, "Cannot get LIS2DH device");
	if (!device_is_ready(lis_dev)) {
		LOG_ERR("LIS2DH device %s is not ready", lis_dev->name);
		return -ENODEV;
	}

	/* Set output data rate to 100Hz for responsive motion detection */
	struct sensor_value odr;
	odr.val1 = 100;
	odr.val2 = 0;
	int ret = sensor_attr_set(lis_dev, SENSOR_CHAN_ACCEL_XYZ, SENSOR_ATTR_SAMPLING_FREQUENCY,
		&odr);
	if (ret) {
		LOG_WRN("Failed to set LIS2DH ODR to 100Hz: %" PRId32, ret);
	} else {
		LOG_INF("LIS2DH ODR set to 100Hz");
	}

	/* Set full scale range to ±16g for higher sensitivity and larger values */
	struct sensor_value range;
	range.val1 = 16;
	range.val2 = 0;
	ret = sensor_attr_set(lis_dev, SENSOR_CHAN_ACCEL_XYZ, SENSOR_ATTR_FULL_SCALE, &range);
	if (ret) {
		LOG_WRN("Failed to set LIS2DH range to ±16g: %" PRId32, ret);
	} else {
		LOG_INF("LIS2DH range set to ±16g");
	}

	LOG_INF("LIS2DH accelerometer initialized and configured");

	return 0;
}

int sensor_interface_get_temp_humidity(uint16_t *temp, uint16_t *humidity)
{
	struct sensor_value temperature, humidity_val;
	int retry_count = 0;
	const int max_retries = 3;

	/* Retry logic for ENS210 sensor stability */
	do {
		int ret = sensor_sample_fetch(ens_dev);
		if (ret) {
			LOG_WRN("Failed to fetch ENS210 sample (attempt %d/%d): %" PRId32,
				retry_count + 1, max_retries, ret);
			if (retry_count < max_retries - 1) {
				k_sleep(K_MSEC(20));  /* Wait before retry */
				retry_count++;
				continue;
			}
			LOG_ERR("Failed to fetch ENS210 sample after %d attempts", max_retries);
			return ret;
		}

		ret = sensor_channel_get(ens_dev, SENSOR_CHAN_AMBIENT_TEMP, &temperature);
		if (ret) {
			LOG_ERR("Failed to get temperature: %" PRId32, ret);
			return ret;
		}

		ret = sensor_channel_get(ens_dev, SENSOR_CHAN_HUMIDITY, &humidity_val);
		if (ret) {
			LOG_ERR("Failed to get humidity: %" PRId32, ret);
			return ret;
		}

		/* Success - break out of retry loop */
		break;

	} while (retry_count < max_retries);

	LOG_DBG("Raw temp: %" PRId32 ".%06d C, humidity: %" PRId32 ".%06d%%",
		temperature.val1, temperature.val2,
		humidity_val.val1, humidity_val.val2);

	/*
	 * Zephyr: val1 + val2/1000000 (floating point)
	 */
	float temp_celsius = temperature.val1 + (temperature.val2 / 1000000.0f);
	float humidity_percent = humidity_val.val1 + (humidity_val.val2 / 1000000.0f);
	*temp = (uint16_t)roundf(temp_celsius * CONFIG_SENSOR_BEACON_TEMP_SCALING_FACTOR);
	*humidity = (uint16_t)roundf(humidity_percent *
		CONFIG_SENSOR_BEACON_HUMIDITY_SCALING_FACTOR);

	LOG_INF("Scaled temp: %" PRIu16 ", humidity: %" PRIu16, *temp, *humidity);

	return 0;
}

int sensor_interface_get_accel(uint16_t *accel_x, uint16_t *accel_y, uint16_t *accel_z)
{
	struct sensor_value accel[3];

	int ret = sensor_sample_fetch(lis_dev);
	if (ret) {
		LOG_ERR("Failed to fetch LIS2DH sample: %" PRId32, ret);
		return ret;
	}

	ret = sensor_channel_get(lis_dev, SENSOR_CHAN_ACCEL_XYZ, accel);
	if (ret) {
		LOG_ERR("Failed to get accelerometer data: %" PRId32, ret);
		return ret;
	}

	LOG_DBG("Raw accel X: %" PRId32 ".%06" PRId32 ", Y: %" PRId32 ".%06" PRId32 ", Z: %" PRId32 ".%06" PRId32 " m/s²",
		accel[0].val1, accel[0].val2,
		accel[1].val1, accel[1].val2,
		accel[2].val1, accel[2].val2);

	int32_t mg_x = sensor_ms2_to_mg(&accel[0]);
	int32_t mg_y = sensor_ms2_to_mg(&accel[1]);
	int32_t mg_z = sensor_ms2_to_mg(&accel[2]);

	LOG_DBG("Accel in milli-g: X: %" PRId32 ", Y: %" PRId32 ", Z: %" PRId32, mg_x, mg_y, mg_z);

	/* Handle signed values properly - clamp to valid int16_t range before casting */
	int32_t scaled_x = mg_x * CONFIG_SENSOR_BEACON_ACCEL_SCALING_FACTOR / 1000;
	int32_t scaled_y = mg_y * CONFIG_SENSOR_BEACON_ACCEL_SCALING_FACTOR / 1000;
	int32_t scaled_z = mg_z * CONFIG_SENSOR_BEACON_ACCEL_SCALING_FACTOR / 1000;

	/* Clamp to int16_t range to prevent overflow/saturation */
	scaled_x = CLAMP(scaled_x, INT16_MIN, INT16_MAX);
	scaled_y = CLAMP(scaled_y, INT16_MIN, INT16_MAX);
	scaled_z = CLAMP(scaled_z, INT16_MIN, INT16_MAX);

	/* Cast signed values to uint16_t (preserves bit pattern for negative values) */
	*accel_x = (uint16_t)scaled_x;
	*accel_y = (uint16_t)scaled_y;
	*accel_z = (uint16_t)scaled_z;

	LOG_INF("Scaled accel X: %" PRId16 ", Y: %" PRId16 ", Z: %" PRId16, (int16_t)*accel_x, (int16_t)*accel_y,
		(int16_t)*accel_z);

	return 0;
}
