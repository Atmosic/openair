/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <string.h>

#include "beacon_adv.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(beacon_adv_at_cmd, CONFIG_SENSOR_BEACON_LOG_LEVEL);

/* Settings keys for persistent storage */
#define SETTINGS_KEY_DEV_NAME     "sensor_beacon/dev_name"
#define SETTINGS_KEY_ADV_INTERVAL "sensor_beacon/adv_interval"

int beacon_adv_set_interval(uint32_t interval)
{
	int err = settings_save_one(SETTINGS_KEY_ADV_INTERVAL, &interval, sizeof(interval));

	if (err) {
		LOG_WRN("Failed to save adv interval (err %" PRId32 ")", err);
	}

	return beacon_adv_update_interval(interval);
}

int beacon_adv_set_device_name(const char *name)
{
	if (!name) {
		return -EINVAL;
	}

	size_t name_len = strlen(name);

	if (name_len == 0 || name_len > CONFIG_BT_DEVICE_NAME_MAX) {
		return -EINVAL;
	}

	int err = settings_save_one(SETTINGS_KEY_DEV_NAME, name, name_len + 1);

	if (err) {
		LOG_WRN("Failed to save device name (err %" PRId32 ")", err);
	}

	return beacon_adv_update_device_name(name);
}

static int beacon_adv_settings_set(const char *name, size_t len, settings_read_cb read_cb,
				   void *cb_arg)
{
	if (!name) {
		LOG_ERR("Settings: Invalid name parameter");
		return -ENOENT;
	}

	const char *next;
	ssize_t name_len = settings_name_next(name, &next);

	if (!strncmp(name, "adv_interval", name_len)) {
		uint32_t interval = 0;
		ssize_t read_len = read_cb(cb_arg, &interval, sizeof(interval));

		if (read_len == sizeof(interval)) {
			return beacon_adv_set_interval_value(interval);
		}
		return 0;
	}

	if (!strncmp(name, "dev_name", name_len)) {
		char buf[CONFIG_BT_DEVICE_NAME_MAX + 1] = {0};
		ssize_t read_len = read_cb(cb_arg, buf, CONFIG_BT_DEVICE_NAME_MAX);

		if (read_len > 0) {
			if (read_len >= CONFIG_BT_DEVICE_NAME_MAX) {
				read_len = CONFIG_BT_DEVICE_NAME_MAX - 1;
			}
			buf[read_len] = '\0';
			return beacon_adv_set_device_name_buffer(buf);
		}
		return beacon_adv_set_device_name_buffer(CONFIG_BT_DEVICE_NAME);
	}

	return -ENOENT;
}

static int beacon_adv_settings_commit(void)
{
	LOG_DBG("Settings: Beacon advertising settings committed");
	return 0;
}

SETTINGS_STATIC_HANDLER_DEFINE(beacon_adv, "sensor_beacon", NULL, beacon_adv_settings_set,
			       beacon_adv_settings_commit, NULL);
