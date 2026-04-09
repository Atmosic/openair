/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2021-2026 Atmosic
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/__assert.h>
#include <string.h>

#include "beacon_adv.h"
#include "sensor_beacon.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(beacon_adv, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#define ATMOSIC_COMPANY_ID  0x0A24
#define BT_ADV_DATA_LEN_MAX 96

/* Advertisement data structure for sensor beacon */
#define ADV_SENSOR_HEADER_SIZE 3
#define ADV_SENSOR_DATA_SIZE   sizeof(sensor_beacon_data_t)

static struct bt_le_ext_adv *adv_set;
static struct bt_le_adv_param adv_params;

#if defined(CONFIG_BT_EXT_ADV_MAX_ADV_SET) && (CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1)
static struct bt_le_ext_adv *conn_adv_set;
static struct bt_le_adv_param conn_adv_params;
#endif

static uint8_t dev_name[] = CONFIG_BT_DEVICE_NAME;

static uint8_t sensor_data[ADV_SENSOR_DATA_SIZE + ADV_SENSOR_HEADER_SIZE] = {
	ATMOSIC_COMPANY_ID & 0xFF, (ATMOSIC_COMPANY_ID >> 8) & 0xFF, 0x00 /* Type field */
};

#define ADV_DATA_FIXED                                                                             \
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),                      \
		BT_DATA(BT_DATA_NAME_COMPLETE, dev_name, sizeof(dev_name) - 1),                    \
		BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),                                     \
		BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe, /* Eddystone UUID */                 \
			      0x10,                           /* Eddystone-URL frame type */       \
			      0x00,                           /* Calibrated Tx power at 0m */      \
			      0x01,                           /* URL Scheme Prefix https://www. */ \
			      'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */                 \
		BT_DATA(BT_DATA_MANUFACTURER_DATA, sensor_data, sizeof(sensor_data))

#if defined(CONFIG_BT_EXT_ADV_MAX_ADV_SET) && (CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1)
static const struct bt_data conn_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_NAME_COMPLETE, dev_name, sizeof(dev_name) - 1),
};
#endif

int beacon_set_adv_data(void)
{
	/* Standard advertising: fixed elements only */
	const struct bt_data adata[] = {ADV_DATA_FIXED};
	int err = bt_le_ext_adv_set_data(adv_set, adata, ARRAY_SIZE(adata), NULL, 0);
	LOG_DBG("Set standard advertising data (sensor only)");

	if (err) {
		LOG_ERR("Failed to set advertising data (err %" PRId32 ")", err);
	}

	return err;
}

int beacon_adv_init(void)
{
	/* Bluetooth should already be initialized from main() */
	if (!bt_is_ready()) {
		LOG_ERR("Bluetooth not ready");
		return -EAGAIN;
	}

	/* Check if already initialized */
	if (adv_set) {
		LOG_DBG("Advertising already initialized");
		return -EALREADY;
	}

	LOG_INF("Bluetooth is ready, initializing advertising");

	adv_params.id = BT_ID_DEFAULT;
	adv_params.sid = 0U;
	adv_params.secondary_max_skip = 0U;
	adv_params.options = BT_LE_ADV_OPT_EXT_ADV;

#ifdef CONFIG_SENSOR_BEACON_FAST_ADV
	adv_params.interval_min = BT_GAP_ADV_FAST_INT_MIN_2; /* 100 ms */
	adv_params.interval_max = BT_GAP_ADV_FAST_INT_MAX_2; /* 150 ms */
	LOG_INF("Advertising mode: Fast (100-150 ms)");
#else
	adv_params.interval_min = BT_GAP_ADV_SLOW_INT_MIN; /* 1 s */
	adv_params.interval_max = BT_GAP_ADV_SLOW_INT_MAX; /* 1.2 s */
	LOG_INF("Advertising mode: Normal (1-1.2 s)");
#endif
	adv_params.peer = NULL;

	/* Create advertising set */
	int err = bt_le_ext_adv_create(&adv_params, NULL, &adv_set);
	if (err) {
		LOG_ERR("Failed to create advertising set (err %" PRId32 ")", err);
		return err;
	}

	/* Set initial advertising data */
	err = beacon_set_adv_data();
	if (err) {
		return err;
	}

#if defined(CONFIG_BT_EXT_ADV_MAX_ADV_SET) && (CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1)
	conn_adv_params.id = BT_ID_DEFAULT;
	conn_adv_params.sid = 1U; /* Different SID */
	conn_adv_params.secondary_max_skip = 0U;
	conn_adv_params.options = BT_LE_ADV_OPT_EXT_ADV | BT_LE_ADV_OPT_CONN;
	conn_adv_params.interval_min = BT_GAP_ADV_SLOW_INT_MIN; /* Slower for connections */
	conn_adv_params.interval_max = BT_GAP_ADV_SLOW_INT_MAX;
	conn_adv_params.peer = NULL;

	err = bt_le_ext_adv_create(&conn_adv_params, NULL, &conn_adv_set);
	if (err) {
		LOG_WRN("Failed to create connection advertising set (err %" PRId32 ")", err);
		conn_adv_set = NULL; /* Mark as unavailable */
	} else {
		LOG_INF("Connection advertising set created (not started)");

		/* Set advertising data for connection set (minimal data) */
		err = bt_le_ext_adv_set_data(conn_adv_set, conn_ad, ARRAY_SIZE(conn_ad), NULL, 0);
		if (err) {
			LOG_WRN("Failed to set connection advertising data (err %" PRId32 ")", err);
		} else {
			LOG_INF("Connection advertising data set (ready to start)");
		}
	}
#endif /* CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1 */

	return 0;
}

int beacon_adv_start(void)
{
	if (!adv_set) {
		LOG_ERR("Advertising set not created");
		return -EINVAL;
	}

	int err = bt_le_ext_adv_start(adv_set, BT_LE_EXT_ADV_START_DEFAULT);
	if (err) {
		LOG_ERR("Failed to start beacon advertising (err %" PRId32 ")", err);
		return err;
	}

	LOG_INF("Beacon advertising started (scannable set)");

#if defined(CONFIG_BT_EXT_ADV_MAX_ADV_SET) && (CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1)
	if (conn_adv_set) {
		err = bt_le_ext_adv_start(conn_adv_set, BT_LE_EXT_ADV_START_DEFAULT);
		if (err) {
			LOG_WRN("Failed to start connection advertising (err %" PRId32 ")", err);
		} else {
			LOG_INF("Connection advertising started");
		}
	}
#endif

	return 0;
}

int beacon_adv_stop(void)
{
	if (!adv_set) {
		LOG_ERR("Advertising set not created");
		return -EINVAL;
	}

	int err = bt_le_ext_adv_stop(adv_set);
	if (err) {
		LOG_ERR("Failed to stop advertising (err %" PRId32 ")", err);
		return err;
	}

	LOG_INF("Beacon advertising stopped");
	return 0;
}

int beacon_adv_update_data(const sensor_beacon_data_t *data)
{
	if (!adv_set) {
		LOG_ERR("Advertising set not created");
		return -EINVAL;
	}

	if (!data) {
		LOG_ERR("Invalid sensor data pointer");
		return -EINVAL;
	}

	memcpy(&sensor_data[ADV_SENSOR_HEADER_SIZE], data, sizeof(*data));

	int err = beacon_set_adv_data();
	if (err) {
		LOG_ERR("Failed to update advertisement data (err %" PRId32 ")", err);
		return err;
	}

	LOG_DBG("Advertisement data updated using live update method");

	/* Notify sensor beacon about beacon transmission for LED indication */
	sensor_beacon_notify_beacon_tx();

	return 0;
}

int beacon_adv_update_interval(uint32_t interval)
{
	if (!adv_set) {
		LOG_ERR("Advertising set not created");
		return -EINVAL;
	}

	if (interval < 400 || interval > 16384) {
		LOG_ERR("Invalid advertising interval: %" PRIu32, interval);
		return -EINVAL;
	}

	int err = bt_le_ext_adv_stop(adv_set);
	if (err) {
		LOG_ERR("Failed to stop advertising for interval update (err %" PRId32 ")", err);
		return err;
	}

	adv_params.interval_min = interval;
	adv_params.interval_max = interval;

	err = bt_le_ext_adv_delete(adv_set);
	if (err) {
		LOG_ERR("Failed to delete advertising set (err %" PRId32 ")", err);
		return err;
	}

	err = bt_le_ext_adv_create(&adv_params, NULL, &adv_set);
	if (err) {
		LOG_ERR("Failed to recreate advertising set (err %" PRId32 ")", err);
		return err;
	}

	err = beacon_set_adv_data();
	if (err) {
		LOG_ERR("Failed to set advertising data (err %" PRId32 ")", err);
		return err;
	}

	err = bt_le_ext_adv_start(adv_set, BT_LE_EXT_ADV_START_DEFAULT);
	if (err) {
		LOG_ERR("Failed to restart advertising after interval update (err %" PRId32 ")",
			err);
		return err;
	}

	LOG_INF("Advertising interval updated to %" PRIu32 " (%.1f ms)", interval,
		interval * 0.625);
	return 0;
}

int beacon_adv_update_device_name(const char *name)
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

	/* Update the local device name buffer used in advertising data */
	memset(dev_name, 0, sizeof(dev_name));
	memcpy(dev_name, name, name_len);

	LOG_INF("Device name updated in advertising data: %s", dev_name);

	/* Stop main beacon advertising if running */
	bool main_adv_was_running = false;
	if (adv_set) {
		int err = bt_le_ext_adv_stop(adv_set);
		if (err == 0) {
			main_adv_was_running = true;
			LOG_DBG("Main advertising stopped for name update");
		} else if (err != -EALREADY) {
			LOG_WRN("Failed to stop main advertising (err %" PRId32 ")", err);
		}
	}

	/* Stop connection advertising if running */
#if defined(CONFIG_BT_EXT_ADV_MAX_ADV_SET) && (CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1)
	bool conn_adv_was_running = false;
	if (conn_adv_set) {
		int err = bt_le_ext_adv_stop(conn_adv_set);
		if (err == 0) {
			conn_adv_was_running = true;
			LOG_DBG("Connection advertising stopped for name update");
		} else if (err != -EALREADY) {
			LOG_WRN("Failed to stop connection advertising (err %" PRId32 ")", err);
		}
	}
#endif

	/* Update advertising data for main beacon set */
	if (adv_set) {
		int err = beacon_set_adv_data();
		if (err) {
			LOG_ERR("Failed to update main advertising data (err %" PRId32 ")", err);
			return err;
		}
		LOG_DBG("Main advertising data updated with new device name");
	}

	/* Update advertising data for connection set */
#if defined(CONFIG_BT_EXT_ADV_MAX_ADV_SET) && (CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1)
	if (conn_adv_set) {
		const struct bt_data conn_ad_local[] = {
			BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
			BT_DATA(BT_DATA_NAME_COMPLETE, dev_name, sizeof(dev_name) - 1),
		};
		int err = bt_le_ext_adv_set_data(conn_adv_set, conn_ad_local,
						 ARRAY_SIZE(conn_ad_local), NULL, 0);
		if (err) {
			LOG_ERR("Failed to update connection advertising data (err %" PRId32 ")",
				err);
			return err;
		}
		LOG_DBG("Connection advertising data updated with new device name");
	}
#endif

	/* Restart main beacon advertising if it was running */
	if (main_adv_was_running && adv_set) {
		int err = bt_le_ext_adv_start(adv_set, BT_LE_EXT_ADV_START_DEFAULT);
		if (err) {
			LOG_ERR("Failed to restart main advertising (err %" PRId32 ")", err);
			return err;
		}
		LOG_INF("Main beacon advertising restarted with new device name");
	}

	/* Restart connection advertising if it was running */
#if defined(CONFIG_BT_EXT_ADV_MAX_ADV_SET) && (CONFIG_BT_EXT_ADV_MAX_ADV_SET > 1)
	if (conn_adv_was_running && conn_adv_set) {
		int err = bt_le_ext_adv_start(conn_adv_set, BT_LE_EXT_ADV_START_DEFAULT);
		if (err) {
			LOG_ERR("Failed to restart connection advertising (err %" PRId32 ")", err);
			return err;
		}
		LOG_INF("Connection advertising restarted with new device name");
	}
#endif

	return 0;
}

int beacon_adv_set_device_name_buffer(const char *name)
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

	memset(dev_name, 0, sizeof(dev_name));
	memcpy(dev_name, name, name_len);

	LOG_DBG("Device name buffer updated: %s", dev_name);
	return 0;
}
