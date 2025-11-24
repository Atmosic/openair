/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "atm_bt_tput.h"

LOG_MODULE_REGISTER(ble_tput_test, CONFIG_ATM_BT_TPUTP_LOG_LEVEL);

#define INTERVAL_UNIT_TO_MS_X100 125 /*  1 unit = 1.25 1.25*100 */
#define TIMEOUT_UNIT_TO_MS       10
#define ADV_RESTART_DELAY_MS     100 /* Delay before restarting advertising */
#define ADV_RETRY_MAX_ATTEMPTS   5   /* Maximum retry attempts */

static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN),
};

struct bt_conn *default_conn;
static int adv_retry_count = 0;

/* Forward declaration needed for work queue definition as function needs the work queue defined */
static void adv_restart_work_handler(struct k_work *work);

/* Work queue for delayed advertising restart */
static K_WORK_DELAYABLE_DEFINE(adv_restart_work, adv_restart_work_handler);

static int adv_start(void)
{
	int err = bt_le_adv_start(BT_LE_ADV_CONN_FAST_2, ad, ARRAY_SIZE(ad), NULL, 0);
	if (err) {
		LOG_ERR("Advertising failed to start (err %d)", err);
		return err;
	}

	LOG_INF("Advertising successfully started");
	return 0;
}

static void adv_restart_work_handler(struct k_work *work)
{
	LOG_DBG("Attempting to restart advertising (attempt %d/%d)", adv_retry_count + 1,
		ADV_RETRY_MAX_ATTEMPTS);

	int err = adv_start();
	if (err) {
		adv_retry_count++;
		LOG_WRN("Advertising restart failed (err %d), attempt %d/%d", err, adv_retry_count,
			ADV_RETRY_MAX_ATTEMPTS);

		if (adv_retry_count < ADV_RETRY_MAX_ATTEMPTS) {
			/* Exponential backoff: double the delay for each retry */
			uint32_t delay_ms = ADV_RESTART_DELAY_MS * (1 << adv_retry_count);
			k_work_schedule(&adv_restart_work, K_MSEC(delay_ms));
			LOG_DBG("Scheduling retry in %" PRIu32 " ms", delay_ms);
		} else {
			LOG_ERR("Failed to restart advertising after %d attempts, giving up",
				ADV_RETRY_MAX_ATTEMPTS);
		}
		return;
	}

	LOG_INF("Advertising successfully restarted after disconnect");
	adv_retry_count = 0;
}

void mtu_updated(struct bt_conn *conn, uint16_t tx, uint16_t rx)
{
	LOG_INF("Updated MTU: TX: %" PRIu16 " RX: %" PRIu16 " bytes", tx, rx);
}

static struct bt_gatt_cb gatt_callbacks = {
	.att_mtu_updated = mtu_updated,
};

static void connected_cb(struct bt_conn *conn, uint8_t conn_err)
{
	int err = 0;

	if (conn_err) {
		LOG_ERR("Connection failed (err %" PRIu8 ")", conn_err);
		bt_conn_unref(default_conn);
		default_conn = NULL;
		return;
	}

	LOG_INF("Connected");
	default_conn = bt_conn_ref(conn);

	/* Cancel any pending advertising restart work */
	k_work_cancel_delayable(&adv_restart_work);

	/* Start discovery after connection */
	if (conn != default_conn) {
		LOG_INF("Connection is not the default. Skipping discovery.");
		return;
	}

	struct bt_conn_info info;
	err = bt_conn_get_info(conn, &info);
	if (err) {
		LOG_ERR("bt_conn_get_info() returned %d", err);
		return;
	}

	uint32_t interval_ms_x100 = info.le.interval * INTERVAL_UNIT_TO_MS_X100;
	uint16_t timeout_ms = info.le.timeout * TIMEOUT_UNIT_TO_MS;

	LOG_INF("Current conn params: interval %" PRIu32 ".%02" PRIu32 " ms, latency %" PRIu16
		" intervals, timeout %" PRIu16 " ms",
		interval_ms_x100 / 100, interval_ms_x100 % 100, info.le.latency, timeout_ms);
}

static void disconnected_cb(struct bt_conn *conn, uint8_t reason)
{
	LOG_INF("Disconnected (reason %" PRIu8 ")", reason);
	if (default_conn) {
		bt_conn_unref(default_conn);
		default_conn = NULL;
	}

	/* Reset retry count and schedule delayed advertising restart */
	adv_retry_count = 0;
	k_work_schedule(&adv_restart_work, K_MSEC(ADV_RESTART_DELAY_MS));
	LOG_DBG("Scheduled advertising restart in %" PRIu32 " ms", ADV_RESTART_DELAY_MS);
}

static void le_phy_updated_cb(struct bt_conn *conn, struct bt_conn_le_phy_info *param)
{
	LOG_INF("LE PHY updated: TX PHY %" PRIu8 ", RX PHY %" PRIu8, param->tx_phy, param->rx_phy);
}

static void le_data_len_updated_cb(struct bt_conn *conn, struct bt_conn_le_data_len_info *info)
{
	LOG_INF("LE Data Length updated: TX [octets %" PRIu16 ", time %" PRIu16
		"] RX [octets %" PRIu16 ", time %" PRIu16 "]",
		info->tx_max_len, info->tx_max_time, info->rx_max_len, info->rx_max_time);
}

static void le_param_updated_cb(struct bt_conn *conn, uint16_t interval, uint16_t latency,
				uint16_t timeout)
{
	uint32_t interval_ms_x100 = interval * INTERVAL_UNIT_TO_MS_X100;
	uint16_t timeout_ms = timeout * 10;

	LOG_INF("Conn params updated: interval %" PRIu32 ".%02" PRIu32 " ms, latency %" PRIu16
		" intervals, timeout %" PRIu16 " ms",
		interval_ms_x100 / 100, interval_ms_x100 % 100, latency, timeout_ms);
}

static struct bt_conn_cb conn_callbacks = {
	.connected = connected_cb,
	.disconnected = disconnected_cb,
	.le_phy_updated = le_phy_updated_cb,
	.le_data_len_updated = le_data_len_updated_cb,
	.le_param_updated = le_param_updated_cb,
};

int main(void)
{
	LOG_INF("Starting BLE Throughput");

	int err = bt_enable(NULL);
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
		return err;
	}

	bt_conn_cb_register(&conn_callbacks);
	bt_gatt_cb_register(&gatt_callbacks);

	err = adv_start();
	if (err) {
		LOG_ERR("Initial advertising failed (err %d)", err);
		return err;
	}

	return 0;
}
