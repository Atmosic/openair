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
#include "led_button_ctrl.h"
#include <inttypes.h>

#ifdef CONFIG_PM
#include "power.h"
#include <zephyr/pm/policy.h>
#endif

LOG_MODULE_REGISTER(sensor_beacon, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#ifdef CONFIG_PM
void sensor_beacon_unlock_soft_off_state(void)
{
#ifdef CONFIG_WURX
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_SUBSTATE_HIBERNATE);
#else
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
}
#endif

static bool initialized;
static bool started;

/* Button event callback */
static void button_event_handler(bool pressed, uint32_t duration_ms)
{
	LOG_DBG("Button event: %s, duration: %" PRIu32 "ms", pressed ? "pressed" : "released",
		duration_ms);
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

	/* Check device state - only start if device is ON or in EVK mode */
	device_state_t state = led_button_ctrl_get_device_state();
	if (state == DEVICE_STATE_OFF && IS_ENABLED(CONFIG_SENSOR_BEACON_BUTTON_POWER_CONTROL)) {
		LOG_INF("Device is OFF - not starting beacon");
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

int sensor_beacon_notify_beacon_tx(void)
{
	/* Notify LED/Button controller about beacon transmission */
	return led_button_ctrl_notify_beacon_tx();
}

/* Device state change callback */
static void device_state_changed(device_state_t new_state)
{
	LOG_INF("Device state changed to: %s", new_state == DEVICE_STATE_ON ? "ON" : "OFF");

	if (new_state == DEVICE_STATE_ON) {
#ifdef CONFIG_PM
		/* Lock SOC_OFF state to prevent deep sleep during active operation */
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
		LOG_INF("SOC_OFF state locked - device will remain active");
#endif
		/* Start sensor beacon when device turns ON */
		if (!started) {
			int ret = sensor_beacon_start();
			if (ret) {
				LOG_ERR("Failed to start sensor beacon: %" PRId32, ret);
			}
		}
	} else {
		/* Stop sensor beacon when device turns OFF */
		if (started) {
			int ret = sensor_beacon_stop();
			if (ret) {
				LOG_ERR("Failed to stop sensor beacon: %" PRId32, ret);
			}
		}

#ifdef CONFIG_PM
		/* Unlock SOC_OFF state to allow automatic power management */
		atm_socoff_wakeup_gpio_set(true);
		sensor_beacon_unlock_soft_off_state();
		LOG_INF("SOC_OFF state unlocked - device will enter deep sleep when idle");
#endif
	}
}

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

	ret = led_button_ctrl_init();
	if (ret) {
		LOG_ERR("LED/Button control init failed: %" PRId32, ret);
		return ret;
	}

	/* Register callbacks for LED/Button events */
	led_button_ctrl_register_state_cb(device_state_changed);
	led_button_ctrl_register_button_cb(button_event_handler);

	initialized = true;
	LOG_INF("Sensor beacon initialized successfully");
	return 0;
}
