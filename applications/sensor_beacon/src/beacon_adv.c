/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2021-2025 Atmosic
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/__assert.h>
#include <string.h>

#include "beacon_adv.h"
#include <inttypes.h>

LOG_MODULE_REGISTER(beacon_adv, CONFIG_SENSOR_BEACON_LOG_LEVEL);

#define ATMOSIC_COMPANY_ID  0x0A24
#define BT_ADV_DATA_LEN_MAX 96

/* Advertisement data structure for sensor beacon */
#define ADV_SENSOR_HEADER_SIZE 3
#define ADV_SENSOR_DATA_SIZE   sizeof(sensor_beacon_data_t)

static struct bt_le_ext_adv *adv_set;
static struct bt_le_adv_param adv_params;

static uint8_t dev_name[] = CONFIG_BT_DEVICE_NAME;

static uint8_t sensor_data[ADV_SENSOR_DATA_SIZE + ADV_SENSOR_HEADER_SIZE] = {
	ATMOSIC_COMPANY_ID & 0xFF,
	(ATMOSIC_COMPANY_ID >> 8) & 0xFF,
	0x00  /* Type field */
};

#define ADV_DATA_FIXED                                                                             \
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),                      \
	BT_DATA(BT_DATA_NAME_COMPLETE, dev_name, sizeof(dev_name) - 1),                            \
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),                                             \
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe, /* Eddystone UUID */                         \
		      0x10,                           /* Eddystone-URL frame type */               \
		      0x00,                           /* Calibrated Tx power at 0m */              \
		      0x01,                           /* URL Scheme Prefix https://www. */         \
		      'a', 't', 'm', 'o', 's', 'i', 'c', 0x07), /* .com */                         \
	BT_DATA(BT_DATA_MANUFACTURER_DATA, sensor_data, sizeof(sensor_data))

static int beacon_set_adv_data(void)
{
	/* Standard advertising: fixed elements only */
	const struct bt_data adata[] = { ADV_DATA_FIXED };
	int err = bt_le_ext_adv_set_data(adv_set, adata, ARRAY_SIZE(adata), NULL, 0);
	if (err) {
		LOG_ERR("Failed to set advertising data (err %" PRId32 ")", err);
		return err;
	}

	LOG_DBG("Set standard advertising data (sensor only)");
	return 0;
}

int beacon_adv_init(void)
{
	int err = bt_enable(NULL);
	if (err) {
		LOG_ERR("Bluetooth init failed (err %" PRId32 ")", err);
		return err;
	}

	LOG_INF("Bluetooth initialized");

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
	err = bt_le_ext_adv_create(&adv_params, NULL, &adv_set);
	if (err) {
		LOG_ERR("Failed to create advertising set (err %" PRId32 ")", err);
		return err;
	}

	/* Set initial advertising data */
	err = beacon_set_adv_data();
	if (err) {
		return err;
	}

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

	LOG_INF("Beacon advertising started");

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

	return 0;
}

const char *beacon_adv_get_device_name(void)
{
	return (const char *)dev_name;
}
