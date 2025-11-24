/**
 *******************************************************************************
 *
 * @file fp_auth.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Authentication Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/addr.h>

#include "fp_auth.h"
#include "fp_conn.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(fp, CONFIG_ATM_FP_LOG_LEVEL);

// Optimized: Define common log prefixes to save flash
#define FP_AUTH_LOG_PREFIX "FP Auth: "

// Per-connection passkey storage
#define FP_AUTH_MAX_CONNECTIONS CONFIG_FP_MAX_CONNECTIONS

struct fp_auth_conn_data {
	struct bt_conn *conn;
	uint32_t passkey: 20;  // 20 bits for passkey (max 999999)
	uint32_t valid: 1;     // 1 bit for validity flag
	uint32_t reserved: 11; // 11 bits reserved for future use
};

static struct fp_auth_conn_data fp_auth_connections[FP_AUTH_MAX_CONNECTIONS];
static bool fp_auth_init_done;

// Find connection data by connection pointer
static struct fp_auth_conn_data *fp_auth_find_conn_data(struct bt_conn *conn)
{
	if (!conn) {
		return NULL;
	}

	for (int i = 0; i < FP_AUTH_MAX_CONNECTIONS; i++) {
		if (fp_auth_connections[i].conn == conn) {
			return &fp_auth_connections[i];
		}
	}
	return NULL;
}

// Find or create connection data
static struct fp_auth_conn_data *fp_auth_get_conn_data(struct bt_conn *conn)
{
	if (!conn) {
		return NULL;
	}

	// First try to find existing entry
	struct fp_auth_conn_data *data = fp_auth_find_conn_data(conn);

	if (data) {
		return data;
	}

	// Find empty slot
	for (int i = 0; i < FP_AUTH_MAX_CONNECTIONS; i++) {
		if (fp_auth_connections[i].conn == NULL) {
			fp_auth_connections[i].conn = bt_conn_ref(conn);
			fp_auth_connections[i].passkey = 0;
			fp_auth_connections[i].valid = 0;
			LOG_DBG(FP_AUTH_LOG_PREFIX "Created slot %d for %p", i, (void *)conn);
			return &fp_auth_connections[i];
		}
	}

	LOG_ERR(FP_AUTH_LOG_PREFIX "No free connection slots available");
	return NULL;
}

static void fp_auth_clear_passkey(struct bt_conn *conn)
{
	struct fp_auth_conn_data *data = fp_auth_find_conn_data(conn);

	if (!data) {
		LOG_DBG(FP_AUTH_LOG_PREFIX "No connection data found for passkey clear");
		return;
	}

	data->passkey = 0;
	data->valid = 0;
	LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey cleared for conn %p", (void *)conn);
}

// Clean up connection data and release connection reference
static void fp_auth_cleanup_conn_data(struct bt_conn *conn)
{
	for (int i = 0; i < FP_AUTH_MAX_CONNECTIONS; i++) {
		if (fp_auth_connections[i].conn == conn) {
			LOG_DBG(FP_AUTH_LOG_PREFIX "Cleanup slot %d for %p", i, (void *)conn);
			bt_conn_unref(fp_auth_connections[i].conn);
			fp_auth_connections[i].conn = NULL;
			fp_auth_connections[i].passkey = 0;
			fp_auth_connections[i].valid = 0;
			return;
		}
	}
}

// Fast Pair 10-second passkey timeout as per specification
#define FP_PASSKEY_TIMEOUT_MS (10 * 1000) // 10 seconds
static struct bt_conn *fp_auth_passkey_timeout_conn = NULL;
static bool fp_auth_waiting_for_passkey;

// Fast Pair passkey timeout handler
static void fp_auth_passkey_timeout_handler(struct k_work *work)
{
	LOG_WRN(FP_AUTH_LOG_PREFIX "Passkey timeout");

	if (fp_auth_passkey_timeout_conn) {
		fp_auth_clear_passkey(fp_auth_passkey_timeout_conn);
		// Disconnect the connection as per Fast Pair specification
		int err = bt_conn_disconnect(fp_auth_passkey_timeout_conn, BT_HCI_ERR_AUTH_FAIL);
		if (err) {
			LOG_ERR(FP_AUTH_LOG_PREFIX "Disconnect failed: %d", err);
		}
		// Release connection reference
		bt_conn_unref(fp_auth_passkey_timeout_conn);
		fp_auth_passkey_timeout_conn = NULL;
	}

	fp_auth_waiting_for_passkey = false;
	LOG_INF(FP_AUTH_LOG_PREFIX "Passkey timeout exit");
}
K_WORK_DELAYABLE_DEFINE(fp_auth_passkey_timeout_work, fp_auth_passkey_timeout_handler);

// Start the 10-second passkey timeout
static void fp_auth_passkey_timeout_start(struct bt_conn *conn)
{
	// Cancel any existing timeout
	k_work_cancel_delayable(&fp_auth_passkey_timeout_work);

	// Store connection reference for timeout handler
	if (fp_auth_passkey_timeout_conn) {
		bt_conn_unref(fp_auth_passkey_timeout_conn);
	}
	fp_auth_passkey_timeout_conn = bt_conn_ref(conn);
	fp_auth_waiting_for_passkey = true;

	k_work_reschedule(&fp_auth_passkey_timeout_work, K_MSEC(FP_PASSKEY_TIMEOUT_MS));
	LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey timeout started");
}

// Cancel the passkey timeout (called when pairing completes successfully)
static void fp_auth_passkey_timeout_cancel(void)
{
	k_work_cancel_delayable(&fp_auth_passkey_timeout_work);

	if (fp_auth_passkey_timeout_conn) {
		bt_conn_unref(fp_auth_passkey_timeout_conn);
		fp_auth_passkey_timeout_conn = NULL;
	}

	fp_auth_waiting_for_passkey = false;
	LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey timeout cancelled");
}

static void fp_auth_set_passkey(struct bt_conn *conn, uint32_t passkey)
{
	struct fp_auth_conn_data *data = fp_auth_get_conn_data(conn);

	if (!data) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Failed to get connection data for passkey set");
		return;
	}

	if (passkey <= FP_PASSKEY_MAX) {
		data->passkey = passkey;
		data->valid = 1;
		LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey set for conn %p: %06u", (void *)conn, passkey);
		return;
	}
	LOG_ERR(FP_AUTH_LOG_PREFIX "Invalid passkey: %u (max %u)", passkey, FP_PASSKEY_MAX);
	data->valid = 0;
	// Clean up connection data if passkey validation fails
	fp_auth_cleanup_conn_data(conn);
}

bool fp_auth_get_passkey(struct bt_conn *conn, uint32_t *passkey)
{
	if (!passkey) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Invalid passkey pointer");
		return false;
	}

	struct fp_auth_conn_data *data = fp_auth_find_conn_data(conn);
	if (!data) {
		LOG_DBG(FP_AUTH_LOG_PREFIX "No connection data found");
		return false;
	}

	if (!data->valid) {
		LOG_DBG(FP_AUTH_LOG_PREFIX "No valid passkey available for conn %p", (void *)conn);
		return false;
	}

	*passkey = data->passkey;
	LOG_DBG(FP_AUTH_LOG_PREFIX "Return passkey for %p: %06u", (void *)conn, data->passkey);
	return true;
}

bool fp_auth_validate_passkey(struct bt_conn *conn, uint32_t received_passkey)
{
	struct fp_auth_conn_data *data = fp_auth_find_conn_data(conn);
	if (!data) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "No connection data found for passkey validation");
		return false;
	}

	if (!data->valid) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "No valid passkey available for validation");
		return false;
	}

	if (received_passkey > FP_PASSKEY_MAX) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Passkey %u exceeds max %u", received_passkey,
			FP_PASSKEY_MAX);
		return false;
	}

	if (received_passkey != data->passkey) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Passkey mismatch conn %p - exp %06u, got %06u",
			(void *)conn, data->passkey, received_passkey);
		bt_conn_auth_cancel(conn);
		return false;
	}

	bt_conn_auth_passkey_confirm(conn);
	LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey valid for conn %p: %06u", (void *)conn,
		received_passkey);
	return true;
}

// Bluetooth authentication callbacks for Fast Pair passkey integration
static void fp_auth_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey display for %s : %06u", addr, passkey);
}

static void fp_auth_passkey_confirm(struct bt_conn *conn, unsigned int passkey)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey confirm for %s: %06u", addr, passkey);

	// Set passkey for Fast Pair verification
	fp_auth_set_passkey(conn, passkey);

	LOG_INF(FP_AUTH_LOG_PREFIX "Passkey confirm for %s should be done in %d ms", addr,
		FP_PASSKEY_TIMEOUT_MS);

	// Start 10-second timeout as per Fast Pair specification
	// "Wait up to 10 seconds for a pairing request. If none is received, exit"
	fp_auth_passkey_timeout_start(conn);
}

static void fp_auth_pairing_complete(struct bt_conn *conn, bool bonded)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	if (bonded) {
		LOG_INF(FP_AUTH_LOG_PREFIX "Pairing successful");
	} else {
		LOG_WRN(FP_AUTH_LOG_PREFIX "Pairing failed");
		fp_auth_clear_passkey(conn);
	}
	fp_auth_passkey_timeout_cancel();
}

static void fp_auth_pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	LOG_INF(FP_AUTH_LOG_PREFIX "Pairing failed, reason: %d", reason);
	fp_auth_clear_passkey(conn);
	fp_auth_passkey_timeout_cancel();
}

static void fp_auth_cancel(struct bt_conn *conn)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	LOG_INF(FP_AUTH_LOG_PREFIX "Authentication cancelled");
	fp_auth_clear_passkey(conn);
	fp_auth_passkey_timeout_cancel();
}

void fp_auth_bond_deleted(uint8_t id, const bt_addr_le_t *peer)
{
	if (!fp_conn_id_validate(id)) {
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];

	// Check if peer address is valid (not null/uninitialized)
	if (peer && !bt_addr_le_eq(peer, BT_ADDR_LE_ANY)) {
		bt_addr_le_to_str(peer, addr, sizeof(addr));
		LOG_INF(FP_AUTH_LOG_PREFIX "Bond deleted for %s, id %u", addr, id);
	} else {
		LOG_INF(FP_AUTH_LOG_PREFIX "Bond deleted for invalid addr, id %u", id);
	}
}

static struct bt_conn_auth_cb fp_auth_pairing_callbacks = {
	// Fast Pair requires DisplayYesNo IO capability for proper passkey verification
	.passkey_display = fp_auth_passkey_display, // Display passkey to user
	.passkey_confirm = fp_auth_passkey_confirm, // Confirm passkey matches
	.cancel = fp_auth_cancel,
};

static struct bt_conn_auth_info_cb fp_auth_info_callbacks = {
	.pairing_complete = fp_auth_pairing_complete,
	.pairing_failed = fp_auth_pairing_failed,
	.bond_deleted = fp_auth_bond_deleted,
};

static void fp_auth_disconnected(struct bt_conn *conn, uint8_t reason)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_DBG(FP_AUTH_LOG_PREFIX "Disconnected from %s, reason: 0x%02x", addr, reason);

	fp_auth_passkey_timeout_cancel();
	fp_auth_cleanup_conn_data(conn);
}

// Connection callbacks for disconnect handling
BT_CONN_CB_DEFINE(fp_auth_conn_callbacks) = {
	.disconnected = fp_auth_disconnected,
};

int fp_auth_set_pairing(struct bt_conn *conn)
{
	if (!fp_conn_validate(conn)) {
		return 0;
	}
	LOG_DBG("FP: Set pairing for conn %p", (void *)conn);
	int err = bt_conn_auth_cb_overlay(conn, &fp_auth_pairing_callbacks);
	if (err) {
		LOG_ERR("FP: Failed to register overlay auth callbacks: %d", err);
		return err;
	}
	return 0;
}

int fp_auth_init(void)
{
	if (fp_auth_init_done) {
		return 0;
	}

	// Register Bluetooth authentication info callbacks for pairing status
	int auth_info_err = bt_conn_auth_info_cb_register(&fp_auth_info_callbacks);
	if (auth_info_err) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Auth info callback reg failed: %d", auth_info_err);
		// Clean up auth callbacks on failure
		bt_conn_auth_cb_register(NULL);
		return auth_info_err;
	}

	LOG_DBG(FP_AUTH_LOG_PREFIX "Auth info callbacks registered successfully");

	fp_auth_init_done = true;
	return 0;
}

void fp_auth_deinit(void)
{
	if (!fp_auth_init_done) {
		return;
	}

	// Clean up all connection data and release references
	for (int i = 0; i < FP_AUTH_MAX_CONNECTIONS; i++) {
		if (fp_auth_connections[i].conn) {
			LOG_DBG(FP_AUTH_LOG_PREFIX "Cleaning up conn data slot %d during deinit",
				i);
			bt_conn_unref(fp_auth_connections[i].conn);
			fp_auth_connections[i].conn = NULL;
			fp_auth_connections[i].passkey = 0;
			fp_auth_connections[i].valid = 0;
		}
	}

	// Unregister authentication info callbacks
	bt_conn_auth_info_cb_unregister(&fp_auth_info_callbacks);

	fp_auth_passkey_timeout_cancel();

	fp_auth_init_done = false;
	LOG_DBG(FP_AUTH_LOG_PREFIX "Auth deinit completed");
}
