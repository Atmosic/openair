/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>

#include "atm_vendor_api.h"
#include "atm_ble_headers.h"
#if defined(CONFIG_BT_PER_ADV)
#include "periodic_adv.h"
#endif

LOG_MODULE_REGISTER(atm_ble_peripheral, CONFIG_ATM_BT_APP_PERIPHERAL_LOG_LEVEL);

/* Buffer size for received data from central device */
#define DATA_BUF_SIZE    64

#if !defined(CONFIG_BT_PER_ADV)
static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID128_ALL, ATM_BLE_TEST_SERVICE_UUID_VAL),
};

static const struct bt_data sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};
#endif

static struct bt_conn *default_conn;

/* GATT notification management */
static struct bt_gatt_attr *notify_crch;
static bool notify_enabled;

/* Connection handle for vendor API calls */
static uint16_t conn_hdl;

static void ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value);
static ssize_t custom_write_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			       const void *buf, uint16_t len, uint16_t offset, uint8_t flags);

BT_GATT_SERVICE_DEFINE(atm_ble_test, BT_GATT_PRIMARY_SERVICE(ATM_BLE_TEST_SERVICE_UUID),
		       BT_GATT_CHARACTERISTIC(ATM_WRITE_TEST_CHAR_UUID,
					      BT_GATT_CHRC_NOTIFY | BT_GATT_CHRC_WRITE,
					      BT_GATT_PERM_WRITE, NULL, custom_write_cb, NULL),
		       BT_GATT_CCC(ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

/**
 * @brief Callback for Client Characteristic Configuration changes
 *
 * @param attr GATT attribute that changed (the CCC descriptor)
 * @param value New CCC value (BT_GATT_CCC_NOTIFY=1 for enabled, 0 for disabled)
 */
static void ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	ARG_UNUSED(attr);

	notify_enabled = (value == BT_GATT_CCC_NOTIFY);

	LOG_INF("MTU Test Update: notifications %s", notify_enabled ? "enabled" : "disabled");

	if (!notify_crch) {
		notify_crch =
			bt_gatt_find_by_uuid(atm_ble_test.attrs, 0xffff, ATM_WRITE_TEST_CHAR_UUID);
	}
}

/**
 * @brief GATT write callback for the custom characteristic
 *
 * @param conn Connection handle for the BLE connection
 * @param attr GATT attribute being written (the custom characteristic)
 * @param buf Data buffer received from central device
 * @param len Length of received data in bytes
 * @param offset Write offset (unused in this implementation)
 * @param flags Write flags (unused in this implementation)
 *
 * @return Number of bytes processed (always returns len)
 */
static ssize_t custom_write_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			       const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	char data[DATA_BUF_SIZE] = {0};
	char notify_data[] = STR_PERIPHERAL_TO_CENTRAL;

	memcpy(data, buf, len);
	data[len] = '\0';
	LOG_INF("Received from central:%s", data);

	if (strncmp(data, STR_TEST_COMPLETE, len) == 0) {
		LOG_INF("All process are done...");
		return len;
	}

	LOG_INF("Change the TX power in peripheral...");

	int err = atm_vendor_set_con_tx_power(conn_hdl, CONFIG_ATM_DYN_TX_POWER_DBM);
	if (err) {
		LOG_ERR("Failed to set connection TX power level %d", CONFIG_ATM_DYN_TX_POWER_DBM);
	} else {
		LOG_INF("Successfully set connection TX power level %d",
			CONFIG_ATM_DYN_TX_POWER_DBM);
	}

	/* Send notification back to central with confirmation message */
	bt_gatt_notify(default_conn, &atm_ble_test.attrs[2], notify_data, sizeof(notify_data));

	return len;
}

/**
 * @brief Callback for MTU update notification
 *
 * @param conn Connection handle for the BLE connection
 * @param tx Maximum transmission unit for TX direction in bytes
 * @param rx Maximum transmission unit for RX direction in bytes
 */
void mtu_updated(struct bt_conn *conn, uint16_t tx, uint16_t rx)
{
	LOG_INF("Updated MTU: TX: %d RX: %d bytes", tx, rx);
}

#if !defined(CONFIG_BT_PER_ADV)
static struct bt_gatt_cb gatt_callbacks = {
	.att_mtu_updated = mtu_updated,
};
#endif

/**
 * @brief Callback for BLE connection establishment
 *
 * @param conn Connection handle for the new BLE connection
 * @param err Error code (0 for success, non-zero for connection failure)
 */
static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err != 0) {
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (default_conn) {
		bt_conn_unref(default_conn);
	}
	default_conn = bt_conn_ref(conn);

	err = bt_hci_get_conn_handle(default_conn, &conn_hdl);
	if (err) {
		LOG_ERR("No connection handle (err %d)", err);
		return;
	}

	err = atm_vendor_set_con_tx_power(conn_hdl, CONFIG_ATM_CONN_TX_POWER_DBM);
	if (err) {
		LOG_ERR("Failed to set conn TX power level %d", CONFIG_ATM_CONN_TX_POWER_DBM);
	} else {
		LOG_INF("Successfully set conn TX power level %d", CONFIG_ATM_CONN_TX_POWER_DBM);
	}

	struct bt_conn_info conn_info;

	err = bt_conn_get_info(conn, &conn_info);
	if (err) {
		LOG_ERR("Failed to retrieve connection info, err = %d", err);
	} else {
		LOG_INF("connection parameters: type = %d, role = %d, id = %d", conn_info.type,
			conn_info.role, conn_info.id);
		LOG_INF("interval = %d, latency = %d, timeout = %d", conn_info.le.interval,
			conn_info.le.latency, conn_info.le.timeout);
	}

	LOG_INF("Connected: %s", addr);
}

/**
 * @brief Callback for BLE connection termination
 *
 * @param conn Connection handle for the terminated connection
 * @param reason HCI reason code for disconnection (see BT spec)
 */
static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	char addr[BT_ADDR_LE_STR_LEN];

	if (conn != default_conn) {
		return;
	}

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_INF("Disconnected: %s, reason 0x%02x %s", addr, reason, bt_hci_err_to_str(reason));

	bt_conn_unref(conn);
	default_conn = NULL;
}

/**
 * @brief Callback for BLE PHY update completion
 *
 * @param conn Connection handle for the BLE connection
 * @param param PHY information containing new RX and TX PHY values
 */
static void le_phy_updated(struct bt_conn *conn, struct bt_conn_le_phy_info *param)
{
	LOG_INF("PHY UPDATED RX PHY %d, TX PHY %d", param->rx_phy, param->tx_phy);
}

/**
 * @brief Callback for BLE connection subrating changes
 *
 * @param conn Connection handle for the BLE connection
 * @param params Subrating parameters containing status, factor, latency, etc.
 *
 * @note BLE 5.3 feature - not supported on ATM33xx (BLE 5.2)
 */
static void subrate_changed_cb(struct bt_conn *conn,
			       const struct bt_conn_le_subrate_changed *params)
{
	LOG_INF("Subrate changed: ");
	LOG_INF("status = %d, factor = %d, continuation_number = %d, peri_latency = %d, "
		"sup_timeout = %d",
		params->status, params->factor, params->continuation_number,
		params->peripheral_latency, params->supervision_timeout);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {.connected = connected,
				     .disconnected = disconnected,
				     .le_phy_updated = le_phy_updated,
				     .subrate_changed = subrate_changed_cb};

int main(void)
{
	int err;

	err = bt_enable(NULL);
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
		return 0;
	}

#if defined(CONFIG_BT_PER_ADV)
	periodic_adv();
#else
	bt_gatt_cb_register(&gatt_callbacks);

#if CONFIG_SOC_SERIES_ATM34
	err = atm_vendor_set_adv_tx_power(CONFIG_ATM_ADV_TX_POWER_DBM);
	if (err) {
		LOG_ERR("Failed to set adv TX power level %d", CONFIG_ATM_ADV_TX_POWER_DBM);
	} else {
		LOG_INF("Successfully set adv TX power level to %d", CONFIG_ATM_ADV_TX_POWER_DBM);
	}
#endif
	err = bt_le_adv_start(BT_LE_ADV_CONN_FAST_1, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
	if (err) {
		LOG_ERR("Advertising failed to start (err %d)", err);
		return 0;
	}

	LOG_INF("Advertising successfully started");
#endif
	return 0;
}
