/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/att.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>

#include "atm_vendor_api.h"
#include "atm_ble_headers.h"
#if defined(CONFIG_BT_PER_ADV_SYNC)
#include "periodic_sync.h"
#endif

LOG_MODULE_REGISTER(atm_ble_central, CONFIG_ATM_BT_APP_CENTRAL_LOG_LEVEL);

/* RSSI threshold for connection filtering - only connect to nearby devices */
#define ATM_THRESHOLD_RSSI -50

static void start_scan(void);

static struct bt_conn *default_conn;
static struct bt_uuid_128 service_uuid;
static const struct bt_uuid *ccc_uuid = BT_UUID_GATT_CCC;
static struct bt_gatt_discover_params discover_params;
static struct bt_gatt_subscribe_params subscribe_params;
static struct bt_gatt_write_params write_params;

/* Connection data and handles */
static char write_data[] = STR_CENTRAL_TO_PERIPHERAL;
static uint16_t write_characteristic_handle;
static uint16_t conn_hdl;

static bt_gatt_notify_func_t notify_cb;

/* State tracking flags for synchronization */
static bool phy_updated;
static bool discovery_complete;

/**
 * @brief Callback function for GATT write operations
 *
 * @param conn Connection handle for the BLE connection
 * @param err Error code (0 for success, non-zero for various failure conditions)
 * @param params Write parameters used in the operation, contains handle and data info
 */
static void write_cb(struct bt_conn *conn, uint8_t err, struct bt_gatt_write_params *params)
{
	if (err) {
		LOG_ERR("Write callback: error %u", err);
	} else {
		LOG_INF("Write callback: success");
	}
}

/**
 * @brief Write data to the remote GATT characteristic
 *
 * @param conn Connection handle for the active BLE connection
 * @param data Null-terminated string data to write to the characteristic
 *
 * @return None, but logs success/failure and calls write_cb() on completion
 */
static void write_func(struct bt_conn *conn, char *data)
{
	if (write_characteristic_handle == 0) {
		LOG_WRN("Write handle not discovered..");
		return;
	}

	LOG_INF("Write operation...");
	write_params.handle = write_characteristic_handle;
	write_params.offset = 0;
	write_params.data = data;
	write_params.length = strlen(data);
	write_params.func = write_cb;

	int err = bt_gatt_write(conn, &write_params);
	if (err) {
		LOG_ERR("Failed to write (err %d)", err);
	} else {
		LOG_INF("Sent data successfully: %s", data);
	}
}

/**
 * @brief Attempt initial write operation if both PHY update and discovery are complete
 *
 * @param conn Connection handle for the BLE connection
 *
 * This function checks if both the PHY update and service discovery have completed.
 * If both conditions are met, it performs the initial write operation.
 */
static void try_initial_write(struct bt_conn *conn)
{
	if (phy_updated && discovery_complete) {
		LOG_INF("Both PHY update and discovery complete - initiating write...");
		write_func(conn, write_data);
	} else {
		LOG_INF("One of PHY update or discovery is still pending...");
	}
}

/**
 * @brief GATT notification callback function
 *
 * @param conn Connection handle for the BLE connection
 * @param params Subscription parameters, contains value_handle and other info
 * @param data Pointer to notification data (NULL indicates unsubscription)
 * @param length Length of the notification data in bytes
 *
 * @return BT_GATT_ITER_STOP for unsubscription, BT_GATT_ITER_CONTINUE otherwise
 */
static uint8_t notify_func(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
			   const void *data, uint16_t length)
{
	if (!data) {
		LOG_INF("Unsubscribed to notification");
		params->value_handle = 0U;
		return BT_GATT_ITER_STOP;
	}

	LOG_INF("[NOTIFICATION] data: %s", (const char *)data);

	if (notify_cb != NULL) {
		notify_cb(conn, params, data, length);
	}

	LOG_INF("Change the TX power in central...");

	int err = atm_vendor_set_con_tx_power(conn_hdl, CONFIG_ATM_DYN_TX_POWER_DBM);
	if (err) {
		LOG_ERR("Failed to set connection TX power level %d", CONFIG_ATM_DYN_TX_POWER_DBM);
	} else {
		LOG_INF("Successfully set connection TX power level %d",
			CONFIG_ATM_DYN_TX_POWER_DBM);
	}

	/* Notify peripheral to complete the test */
	char msg[] = STR_TEST_COMPLETE;
	write_func(conn, msg);

	return BT_GATT_ITER_CONTINUE;
}

/**
 * @brief GATT service and characteristic discovery callback
 *
 * @param conn Connection handle for the BLE connection
 * @param attr GATT attribute found during discovery (NULL when discovery complete)
 * @param params Discovery parameters containing UUID, handles, and type info
 *
 * @return BT_GATT_ITER_STOP to end discovery, BT_GATT_ITER_CONTINUE to continue
 */
static uint8_t discover_func(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     struct bt_gatt_discover_params *params)
{
	int err;

	if (!attr) {
		LOG_INF("Discover complete");
		(void)memset(params, 0, sizeof(*params));
		return BT_GATT_ITER_STOP;
	}

	if (!bt_uuid_cmp(discover_params.uuid, ATM_BLE_TEST_SERVICE_UUID)) {
		memcpy(&service_uuid, ATM_WRITE_TEST_CHAR_UUID, sizeof(service_uuid));
		discover_params.uuid = &service_uuid.uuid;
		discover_params.start_handle = attr->handle + 1;
		discover_params.type = BT_GATT_DISCOVER_CHARACTERISTIC;

		err = bt_gatt_discover(conn, &discover_params);
		if (err) {
			LOG_ERR("Failed to discover characteristic (err %d)", err);
		}
	} else if (!bt_uuid_cmp(discover_params.uuid, ATM_WRITE_TEST_CHAR_UUID)) {
		write_characteristic_handle = bt_gatt_attr_value_handle(attr);
		discover_params.uuid = ccc_uuid;
		discover_params.start_handle = attr->handle + 2;
		discover_params.type = BT_GATT_DISCOVER_DESCRIPTOR;
		subscribe_params.value_handle = bt_gatt_attr_value_handle(attr);

		err = bt_gatt_discover(conn, &discover_params);
		if (err) {
			LOG_ERR("Discover failed (err %d)", err);
		}
	} else {
		subscribe_params.notify = notify_func;
		subscribe_params.value = BT_GATT_CCC_NOTIFY;
		subscribe_params.ccc_handle = attr->handle;

		err = bt_gatt_subscribe(conn, &subscribe_params);
		if (err && err != -EALREADY) {
			LOG_WRN("Subscribe failed (err %d)", err);
		} else {
			LOG_INF("Subscribed to notification");
		}

		/* Mark discovery as complete and attempt initial write if PHY is ready */
		discovery_complete = true;
		try_initial_write(conn);

		return BT_GATT_ITER_STOP;
	}

	return BT_GATT_ITER_STOP;
}

/**
 * @brief Callback for BLE device discovery during scanning
 *
 * @param addr Bluetooth LE address of the discovered device
 * @param rssi Received Signal Strength Indicator in dBm
 * @param type Advertisement type (ADV_IND, ADV_DIRECT_IND, etc.)
 * @param ad Advertisement data buffer (currently unused)
 */
static void device_found(const bt_addr_le_t *addr, int8_t rssi, uint8_t type,
			 struct net_buf_simple *ad)
{
	char addr_str[BT_ADDR_LE_STR_LEN];
	int err;

	if (default_conn) {
		return;
	}

	/* We're only interested in connectable events */
	if (type != BT_GAP_ADV_TYPE_ADV_IND && type != BT_GAP_ADV_TYPE_ADV_DIRECT_IND) {
		return;
	}

	bt_addr_le_to_str(addr, addr_str, sizeof(addr_str));
	LOG_INF("Device found: %s (RSSI %d)", addr_str, rssi);

	/* Connect only to devices in close proximity (RSSI filter) */
	if (rssi < ATM_THRESHOLD_RSSI) {
		return;
	}

	if (bt_le_scan_stop()) {
		LOG_ERR("Stop scan failed");
		return;
	}

	err = bt_conn_le_create(addr, BT_CONN_LE_CREATE_CONN, BT_LE_CONN_PARAM_DEFAULT,
				&default_conn);
	if (err) {
		LOG_ERR("Create conn to %s failed (%u)", addr_str, err);
		start_scan();
	}
}

/**
 * @brief Start BLE scanning for peripheral devices
 */
static void start_scan(void)
{
	int err;

	err = bt_le_scan_start(BT_LE_SCAN_PASSIVE, device_found);
	if (err) {
		LOG_ERR("Scanning failed to start (err %d)", err);
		return;
	}

	LOG_INF("Scanning successfully started");
}

/**
 * @brief Callback for MTU exchange completion
 *
 * @param conn Connection handle for the BLE connection
 * @param err Error code (0 for success, non-zero for failure)
 * @param params MTU exchange parameters (currently unused)
 */
static void mtu_exchange_cb(struct bt_conn *conn, uint8_t err,
			    struct bt_gatt_exchange_params *params)
{
	LOG_INF("%s: MTU exchange %s (%u)", __func__, err == 0U ? "successful" : "failed",
		bt_gatt_get_mtu(conn));
}

static struct bt_gatt_exchange_params mtu_exchange_params = {.func = mtu_exchange_cb};

/**
 * @brief Initiate MTU exchange with the connected device
 *
 * @param conn Connection handle for the BLE connection
 *
 * @return 0 on success, negative error code on failure
 */
static int mtu_exchange(struct bt_conn *conn)
{
	int err;

	LOG_INF("%s: Current MTU = %u", __func__, bt_gatt_get_mtu(conn));

	LOG_INF("%s: Exchange MTU...", __func__);
	err = bt_gatt_exchange_mtu(conn, &mtu_exchange_params);
	if (err) {
		LOG_ERR("%s: MTU exchange failed (err %d)", __func__, err);
	}

	return err;
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

	/* Mark PHY update as complete and attempt initial write if discovery is ready */
	phy_updated = true;
	try_initial_write(conn);
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

#if !defined(CONFIG_BT_PER_ADV_SYNC)
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
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (err) {
		LOG_WRN("Failed to connect to %s %u %s", addr, err, bt_hci_err_to_str(err));

		bt_conn_unref(default_conn);
		default_conn = NULL;

		start_scan();
		return;
	}

	/* Reset state flags for new connection */
	phy_updated = false;
	discovery_complete = false;

	if (conn == default_conn) {
		memcpy(&service_uuid, ATM_BLE_TEST_SERVICE_UUID, sizeof(service_uuid));
		discover_params.uuid = &service_uuid.uuid;
		discover_params.func = discover_func;
		discover_params.start_handle = BT_ATT_FIRST_ATTRIBUTE_HANDLE;
		discover_params.end_handle = BT_ATT_LAST_ATTRIBUTE_HANDLE;
		discover_params.type = BT_GATT_DISCOVER_PRIMARY;

		err = bt_gatt_discover(default_conn, &discover_params);
		if (err) {
			LOG_ERR("Discover failed(err %d)", err);
			return;
		}
	}

	(void)mtu_exchange(conn);

	err = bt_hci_get_conn_handle(default_conn, &conn_hdl);
	if (err) {
		LOG_ERR("No connection handle (err %d)", err);
		return;
	}

	err = atm_vendor_set_con_tx_power(conn_hdl, CONFIG_ATM_CONN_TX_POWER_DBM);
	if (err) {
		LOG_WRN("Failed to set conn TX power level %d", CONFIG_ATM_CONN_TX_POWER_DBM);
	} else {
		LOG_INF("Successfully set conn TX power level %d", CONFIG_ATM_CONN_TX_POWER_DBM);
	}

/*
 * PHY Update: Configure the physical layer based on Kconfig selection
 * - 1M PHY: Standard BLE PHY with 1 Mbps data rate
 * - 2M PHY: Enhanced PHY with 2 Mbps data rate (better throughput)
 * - Coded PHY S2/S8: Long-range PHY with error correction (better range)
 */
#if defined(CONFIG_ATM_BT_PHY_CODED_S2) || defined(CONFIG_ATM_BT_PHY_CODED_S8)
	static struct bt_conn_le_phy_param update_phy;
#endif

#if defined(CONFIG_ATM_BT_PHY_1M)
	err = bt_conn_le_phy_update(default_conn, BT_CONN_LE_PHY_PARAM_1M);
#elif defined(CONFIG_ATM_BT_PHY_2M)
	err = bt_conn_le_phy_update(default_conn, BT_CONN_LE_PHY_PARAM_2M);
#elif defined(CONFIG_ATM_BT_PHY_CODED_S2)
	update_phy.options = BT_CONN_LE_PHY_OPT_CODED_S2;
	update_phy.pref_rx_phy = BT_GAP_LE_PHY_CODED;
	update_phy.pref_tx_phy = BT_GAP_LE_PHY_CODED;
	err = bt_conn_le_phy_update(default_conn, &update_phy);
#elif defined(CONFIG_ATM_BT_PHY_CODED_S8)
	update_phy.options = BT_CONN_LE_PHY_OPT_CODED_S8;
	update_phy.pref_rx_phy = BT_GAP_LE_PHY_CODED;
	update_phy.pref_tx_phy = BT_GAP_LE_PHY_CODED;
	err = bt_conn_le_phy_update(default_conn, &update_phy);
#else
	LOG_INF("PHY mode not set in Kconfig");
	return;
#endif
	if (err) {
		LOG_ERR("PHY update failed: %d", err);
	}
	struct bt_conn_info conn_info;

	err = bt_conn_get_info(conn, &conn_info);
	if (err) {
		LOG_ERR("Failed to retrieve connection info, err = %d", err);
	} else {
		LOG_INF("Connection parameters: type = %d, role = %d, id = %d", conn_info.type,
			conn_info.role, conn_info.id);
		LOG_INF("interval = %d, latency = %d, timeout = %d", conn_info.le.interval,
			conn_info.le.latency, conn_info.le.timeout);
	}

	/*
	 * BLE 5.3 Connection Subrating: Allows reducing connection event frequency
	 * to save power while maintaining the connection. The peripheral can skip
	 * connection events based on the subrate factor.
	 */
	struct bt_conn_le_subrate_param params = {
		.subrate_min = CONFIG_ATM_SUBRATE_MIN,
		.subrate_max = CONFIG_ATM_SUBRATE_MAX,
		.max_latency = CONFIG_ATM_MAX_LATENCY,
		.continuation_number = CONFIG_ATM_CONTINUATION_NUMBER,
		.supervision_timeout = CONFIG_ATM_SUPERVISION_TIMEOUT,
	};

	err = bt_conn_le_subrate_request(conn, &params);
	if (err) {
		LOG_ERR("Failure in setting subrate params, err = %d", err);
	} else {
		LOG_INF("Success in setting subrate params");
	}

	LOG_INF("Connected to %s successfully ", addr);
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

	bt_conn_unref(default_conn);
	default_conn = NULL;

	start_scan();
}

/**
 * @brief Callback for BLE connection subrating changes
 *
 * @param conn Connection handle for the BLE connection
 * @param params Subrating parameters containing status, factor, latency, etc.
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

#if defined(CONFIG_BT_PER_ADV_SYNC)
	periodic_sync();
#else
	bt_gatt_cb_register(&gatt_callbacks);

	LOG_INF("Bluetooth initialized");

	start_scan();
#endif
	return 0;
}
