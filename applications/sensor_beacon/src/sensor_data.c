/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <string.h>

#include "sensor_data.h"
#include "sensor_interface.h"
#include "battery_monitor.h"
#include "beacon_adv.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(sensor_data, CONFIG_SENSOR_BEACON_LOG_LEVEL);

/* Timer for periodic sensor data collection */
static struct k_timer sensor_timer;
static bool timer_active = false;

/* Work item for sensor data collection */
static struct k_work sensor_work;

static sensor_beacon_data_t current_data;

static void sensor_timer_handler(struct k_timer *timer)
{
	k_work_submit(&sensor_work);
}

static void sensor_work_handler(struct k_work *work)
{
	LOG_DBG("Collecting sensor data");

	int ret = sensor_data_collect_and_update();
	if (ret) {
		LOG_ERR("Failed to collect sensor data: %" PRId32, ret);
	}
}

int sensor_data_init(void)
{
	k_timer_init(&sensor_timer, sensor_timer_handler, NULL);
	k_work_init(&sensor_work, sensor_work_handler);
	memset(&current_data, 0, sizeof(current_data));

	LOG_INF("Sensor data system initialized");
	return 0;
}

int sensor_data_start(void)
{
	if (!CONFIG_SENSOR_BEACON_UPDATE_INTERVAL) {
		LOG_INF("Periodic updates disabled (interval = 0)");
		return 0;
	}

	if (timer_active) {
		LOG_WRN("Timer already active");
		return 0;
	}

	k_timer_start(&sensor_timer, K_MSEC(CONFIG_SENSOR_BEACON_UPDATE_INTERVAL * 10),
		K_MSEC(CONFIG_SENSOR_BEACON_UPDATE_INTERVAL * 10));

	timer_active = true;
	LOG_INF("Periodic sensor data collection started (interval: %" PRId32 " ms)",
		CONFIG_SENSOR_BEACON_UPDATE_INTERVAL);

	/* Collect initial data immediately */
	k_work_submit(&sensor_work);

	return 0;
}

int sensor_data_stop(void)
{
	if (!timer_active) {
		LOG_WRN("Timer not active");
		return 0;
	}

	k_timer_stop(&sensor_timer);
	timer_active = false;
	k_work_cancel(&sensor_work);

	LOG_INF("Periodic sensor data collection stopped");
	return 0;
}

int sensor_data_collect_and_update(void)
{
	uint16_t temp = 0, humidity = 0;
	int ret = sensor_interface_get_temp_humidity(&temp, &humidity);
	if (ret) {
		LOG_ERR("Failed to get temperature/humidity: %" PRId32, ret);
		/* Set to invalid/error values when sensor fails */
		temp = 0xFFFF;
		humidity = 0xFFFF;
	}
	current_data.temp = temp;
	current_data.humidity = humidity;

	int16_t x_axis, y_axis, z_axis;
	ret = sensor_interface_get_accel(&x_axis, &y_axis, &z_axis);
	if (ret) {
		LOG_ERR("Failed to get accelerometer data: %" PRId32, ret);
	}
	current_data.x_axis = x_axis;
	current_data.y_axis = y_axis;
	current_data.z_axis = z_axis;

	float vstore, vbatt;
	ret = battery_monitor_get_voltages(&vstore, &vbatt);
	if (ret) {
		LOG_ERR("Failed to get battery voltages: %" PRId32, ret);
		vstore = 0.0f;
		vbatt = 0.0f;
	}
	current_data.vstore = vstore;
	current_data.vbatt = vbatt;

	ret = beacon_adv_update_data(&current_data);
	if (ret) {
		LOG_ERR("Failed to update beacon advertisement: %" PRId32, ret);
		return ret;
	}

	LOG_INF("Sensor - Temp: %" PRIu16 ", Humidity: %" PRIu16 ", "
		"Accel: [%" PRIu16 ", %" PRIu16 ", %" PRIu16 "], "
		"VStore: %.3fV, VBatt: %.3fV",
		current_data.temp, current_data.humidity,
		current_data.x_axis, current_data.y_axis, current_data.z_axis,
		(double)current_data.vstore, (double)current_data.vbatt);

	return 0;
}
