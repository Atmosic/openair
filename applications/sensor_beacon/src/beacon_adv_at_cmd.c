/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2025-2026 Atmosic
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <string.h>

#include "beacon_adv.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(beacon_adv_at_cmd, CONFIG_SENSOR_BEACON_LOG_LEVEL);

/* Settings keys for persistent storage */
#define SETTINGS_KEY_DEV_NAME "sensor_beacon/dev_name"

int beacon_adv_set_interval(uint32_t interval)
{
	return beacon_adv_update_interval(interval);
}

int beacon_adv_set_device_name(const char *name)
{
	if (!name) {
		LOG_ERR("Invalid device name pointer");
		return -EINVAL;
	}

	size_t name_len = strlen(name);
	if (name_len == 0 || name_len > CONFIG_BT_DEVICE_NAME_MAX) {
		LOG_ERR("Invalid device name length: %zu", name_len);
		return -EINVAL;
	}

	/* Save device name to persistent storage (include null terminator) */
	int err = settings_save_one(SETTINGS_KEY_DEV_NAME, name, name_len + 1);
	if (err) {
		LOG_WRN("Failed to save device name to settings (err %" PRId32 ")", err);
		/* Continue anyway - the name change will work for this session */
	} else {
		LOG_INF("Device name saved to persistent storage: %s (len=%zu)", name, name_len);
	}

	err = beacon_adv_update_device_name(name);
	if (err) {
		LOG_ERR("Failed to update device name in advertising: %" PRId32, err);
		return err;
	}

	return 0;
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

	if (!strncmp(name, "dev_name", name_len)) {
		char temp_buffer[CONFIG_BT_DEVICE_NAME_MAX + 1] = {0};

		ssize_t read_len = read_cb(cb_arg, temp_buffer, CONFIG_BT_DEVICE_NAME_MAX);
		if (read_len > 0) {
			if (read_len >= CONFIG_BT_DEVICE_NAME_MAX) {
				read_len = CONFIG_BT_DEVICE_NAME_MAX - 1;
			}
			temp_buffer[read_len] = '\0';

			int err = beacon_adv_set_device_name_buffer(temp_buffer);
			if (err) {
				LOG_ERR("Settings: Failed to set device name buffer: %" PRId32,
					err);
				return err;
			}
			LOG_INF("Settings: Loaded device name: %s (len=%zd)", temp_buffer,
				read_len);
		} else {
			LOG_INF("Settings: No custom device name found, using default");
			int err = beacon_adv_set_device_name_buffer(CONFIG_BT_DEVICE_NAME);
			if (err) {
				LOG_ERR("Settings: Failed to set default device name: %" PRId32,
					err);
				return err;
			}
		}
		return 0;
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
