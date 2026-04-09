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
#define SETTINGS_KEY_DEV_NAME  "sensor_beacon/dev_name"
#define SETTINGS_KEY_USER_DATA "sensor_beacon/user_data"

/* Maximum sizes for user data */
#define ADV_USER_DATA_MAX_SIZE    27 /* Maximum space available for user data element */
#define ADV_USER_DATA_MAX_PAYLOAD 25 /* Maximum user data payload (excluding length/type) */

/* Local storage for user data */
static uint8_t user_data[ADV_USER_DATA_MAX_SIZE];
static bool user_data_valid = false;

/* Static helper functions for internal use within this file */

static int beacon_adv_validate_tlv_data(const uint8_t *data, uint16_t len)
{
	if (!data || len == 0) {
		LOG_ERR("Invalid data parameters");
		return -EINVAL;
	}

	if (len < 2) {
		LOG_ERR("TLV data too short: %d bytes (minimum 2)", len);
		return -EINVAL;
	}

	uint8_t tlv_len = data[0];
	uint8_t tlv_type = data[1];

	/* Validate TLV length field */
	if (tlv_len == 0) {
		LOG_ERR("TLV length cannot be zero");
		return -EINVAL;
	}

	if (tlv_len != len - 1) {
		LOG_ERR("TLV length mismatch: expected %d, got %d", len - 1, tlv_len);
		return -EINVAL;
	}

	/* Validate total length doesn't exceed maximum */
	if (len > ADV_USER_DATA_MAX_SIZE) {
		LOG_ERR("User data too large: %d bytes (max %d)", len, ADV_USER_DATA_MAX_SIZE);
		return -EINVAL;
	}

	LOG_DBG("TLV data valid: len=%d, type=0x%02x, payload=%d bytes", tlv_len, tlv_type,
		tlv_len - 1);
	return 0;
}

static int beacon_adv_set_user_data_internal(const uint8_t *data, uint16_t len)
{
	if (!data || len == 0) {
		LOG_ERR("Invalid user data parameters");
		return -EINVAL;
	}

	/* Store user data locally */
	memset(user_data, 0, sizeof(user_data));
	memcpy(user_data, data, len);
	user_data_valid = true;

	/* Refresh advertising data to include the new user data */
	int ret = beacon_set_adv_data();
	if (ret) {
		LOG_ERR("Failed to refresh advertising data: %" PRId32, ret);
		return ret;
	}

	LOG_DBG("User data set internally: %d bytes", len);
	return 0;
}

static int beacon_adv_clear_user_data_internal(void)
{
	/* Clear user data locally */
	memset(user_data, 0, sizeof(user_data));
	user_data_valid = false;

	/* Refresh advertising data to remove user data */
	int ret = beacon_set_adv_data();
	if (ret) {
		LOG_ERR("Failed to refresh advertising data: %" PRId32, ret);
		return ret;
	}

	LOG_DBG("User data cleared internally");
	return 0;
}

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

int beacon_adv_set_user_data(const uint8_t *data, uint16_t len)
{
	/* Handle NULL/0 as clear operation */
	if (!data || len == 0) {
		LOG_INF("Clearing user data (NULL or zero length)");

		if (!user_data_valid) {
			LOG_DBG("No user data to clear");
			return 0;
		}

		/* Clear local user data */
		memset(user_data, 0, sizeof(user_data));
		user_data_valid = false;

		/* Clear from persistent storage */
		int ret = settings_delete(SETTINGS_KEY_USER_DATA);
		if (ret) {
			LOG_WRN("Failed to delete user data from settings (err %" PRId32 ")", ret);
		} else {
			LOG_INF("User data cleared from persistent storage");
		}

		ret = beacon_adv_clear_user_data_internal();
		if (ret) {
			LOG_ERR("Failed to update advertising data after clearing user data: "
				"%" PRId32,
				ret);
			return ret;
		}

		LOG_INF("User data cleared successfully - reverted to sensor-only advertising");
		return 0;
	}

	/* Validate TLV format */
	int ret = beacon_adv_validate_tlv_data(data, len);
	if (ret) {
		LOG_ERR("User data validation failed: %" PRId32, ret);
		return ret;
	}

	/* Store user data locally */
	memset(user_data, 0, sizeof(user_data));
	memcpy(user_data, data, len);
	user_data_valid = true;

	/* Save to persistent storage */
	ret = settings_save_one(SETTINGS_KEY_USER_DATA, user_data, len);
	if (ret) {
		LOG_WRN("Failed to save user data to settings (err %" PRId32 ")", ret);
		/* Continue anyway - the data will work for this session */
	} else {
		LOG_INF("User data saved to persistent storage: %d bytes", len);
	}

	ret = beacon_adv_set_user_data_internal(data, len);
	if (ret) {
		LOG_ERR("Failed to update advertising data with user data: %" PRId32, ret);
		return ret;
	}

	LOG_INF("User data set successfully: type=0x%02x, payload=%d bytes", data[1], data[0] - 1);
	LOG_HEXDUMP_DBG(data, len, "User data");

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

	if (!strncmp(name, "user_data", name_len)) {
		memset(user_data, 0, sizeof(user_data));
		user_data_valid = false;

		ssize_t read_len = read_cb(cb_arg, user_data, sizeof(user_data));
		if (read_len > 0) {
			if (beacon_adv_validate_tlv_data(user_data, read_len) == 0) {
				user_data_valid = true;
				LOG_INF("Settings: Loaded user data: %d bytes", (int)read_len);
				LOG_HEXDUMP_DBG(user_data, read_len, "User data");

				/* Apply loaded user data to advertising */
				beacon_adv_set_user_data_internal(user_data, read_len);
			} else {
				LOG_WRN("Settings: Invalid user data loaded, ignoring");
				memset(user_data, 0, sizeof(user_data));
			}
		} else {
			LOG_DBG("Settings: No user data found");
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
