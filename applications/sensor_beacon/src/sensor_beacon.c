/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/logging/log.h>

#include "sensor_beacon.h"
#include "sensor_interface.h"
#include "battery_monitor.h"
#include "beacon_adv.h"
#include "sensor_data.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(sensor_beacon, CONFIG_SENSOR_BEACON_LOG_LEVEL);

static bool initialized;
static bool started;

int sensor_beacon_init(void)
{
	if (initialized) {
		LOG_WRN("Sensor beacon already initialized");
		return 0;
	}

	LOG_INF("Initializing sensor beacon");

	int ret = battery_monitor_init();
	if (ret) {
		LOG_ERR("Battery monitor init failed: %" PRId32, ret);
		return ret;
	}

	ret = sensor_interface_init();
	if (ret) {
		LOG_WRN("Sensor interface init failed: %" PRId32 " - continuing without sensors",
			ret);
	}

	ret = beacon_adv_init();
	if (ret) {
		LOG_ERR("Beacon advertising init failed: %" PRId32, ret);
		return ret;
	}

	ret = sensor_data_init();
	if (ret) {
		LOG_ERR("Sensor data system init failed: %" PRId32, ret);
		return ret;
	}

	initialized = true;
	LOG_INF("Sensor beacon initialized successfully");
	return 0;
}

int sensor_beacon_start(void)
{
	if (!initialized) {
		LOG_ERR("Sensor beacon not initialized");
		return -EINVAL;
	}

	if (started) {
		LOG_WRN("Sensor beacon already started");
		return 0;
	}

	LOG_INF("Starting sensor beacon");

	int ret = beacon_adv_start();
	if (ret) {
		LOG_ERR("Failed to start beacon advertising: %" PRId32, ret);
		return ret;
	}

	ret = sensor_data_start();
	if (ret) {
		LOG_ERR("Failed to start sensor data collection: %" PRId32, ret);
		beacon_adv_stop();
		return ret;
	}

	started = true;
	LOG_INF("Sensor beacon started successfully");
	return 0;
}

int sensor_beacon_stop(void)
{
	if (!started) {
		LOG_WRN("Sensor beacon not started");
		return 0;
	}

	LOG_INF("Stopping sensor beacon");

	int ret = sensor_data_stop();
	if (ret) {
		LOG_ERR("Failed to stop sensor data collection: %" PRId32, ret);
	}

	ret = beacon_adv_stop();
	if (ret) {
		LOG_ERR("Failed to stop beacon advertising: %" PRId32, ret);
	}

	started = false;
	LOG_INF("Sensor beacon stopped");
	return 0;
}

int sensor_beacon_get_data(sensor_beacon_data_t *data)
{
	if (!data) {
		return -EINVAL;
	}

	if (!initialized) {
		LOG_ERR("Sensor beacon not initialized");
		return -EINVAL;
	}

	return sensor_data_collect_and_update();
}
