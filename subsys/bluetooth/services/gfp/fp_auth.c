/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file fp_auth.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Authentication Middleware
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/addr.h>

#include "fp_auth.h"
#include "fp_conn.h"
#include "fp_mode.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(fp, CONFIG_ATM_FP_LOG_LEVEL);

// Optimized: Define common log prefixes to save flash
#define FP_AUTH_LOG_PREFIX "FP Auth: "

// Per-connection passkey storage
#define FP_AUTH_MAX_CONNECTIONS CONFIG_FP_MAX_CONNECTIONS

struct fp_auth_conn_data {
	struct bt_conn *conn;
	uint32_t passkey: 20;     // 20 bits for passkey (max 999999)
	uint32_t valid: 1;        // 1 bit for validity flag
	uint32_t kbp_verified: 1; // 1 bit: KBP crypto verified on this connection
	uint32_t reserved: 10;    // 10 bits reserved for future use
};

static struct fp_auth_conn_data fp_auth_connections[FP_AUTH_MAX_CONNECTIONS];
static bool fp_auth_init_done;

// Callbacks registered by fp_gatt to manage K lifetime without a back-include.
static fp_auth_pairing_started_cb_t fp_auth_on_pairing_started;
static fp_auth_pairing_complete_cb_t fp_auth_on_pairing_complete;

void fp_auth_pairing_started_cb_reg(fp_auth_pairing_started_cb_t cb)
{
	fp_auth_on_pairing_started = cb;
}

void fp_auth_pairing_complete_cb_reg(fp_auth_pairing_complete_cb_t cb)
{
	fp_auth_on_pairing_complete = cb;
}

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
			fp_auth_connections[i].kbp_verified = 0;
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
			fp_auth_connections[i].kbp_verified = 0;
			return;
		}
	}
}

// Fast Pair 10-second passkey timeout as per specification
#define FP_PASSKEY_TIMEOUT_MS FP_PAIRING_TIMEOUT_MS
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
	if (!fp_conn_validate(conn)) {
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_DBG(FP_AUTH_LOG_PREFIX "Passkey display for %s : %06u", addr, passkey);
}

static void fp_auth_passkey_confirm(struct bt_conn *conn, unsigned int passkey)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

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

	fp_auth_passkey_timeout_cancel();

	if (bonded) {
		LOG_INF(FP_AUTH_LOG_PREFIX "Pairing successful");
	} else {
		LOG_WRN(FP_AUTH_LOG_PREFIX "Pairing failed (not bonded)");
		fp_auth_clear_passkey(conn);
	}

	// Spec step 10: reschedule K discard for the account key write window
	if (fp_auth_on_pairing_complete) {
		fp_auth_on_pairing_complete(bonded);
	}
}

static void fp_auth_pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	LOG_INF(FP_AUTH_LOG_PREFIX "Pairing failed, reason: %d", reason);
	fp_auth_clear_passkey(conn);
	fp_auth_passkey_timeout_cancel();
	// Spec step 10: discard K immediately on pairing failure
	if (fp_auth_on_pairing_complete) {
		fp_auth_on_pairing_complete(false);
	}
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

#if defined(CONFIG_BT_SMP_APP_PAIRING_ACCEPT)
/**
 * @brief Unified pairing accept callback for all Fast Pair connections.
 *
 * - Rejects NoInput/NoOutput Seekers to avoid Just Works (spec "During pairing").
 * - Accepts only when KBP crypto has been verified on this connection (covers
 *   both initial and subsequent pairing).
 * - Cancels the post-KBP K discard timer (spec step 4).
 *
 * Re-encryption of existing bonds does NOT trigger this callback.
 */
static enum bt_security_err fp_auth_pairing_accept(struct bt_conn *conn,
						   const struct bt_conn_pairing_feat *const feat)
{
	if (!fp_conn_validate(conn)) {
		return BT_SECURITY_ERR_SUCCESS;
	}

	// Reject NoInput/NoOutput to prevent Just Works pairing (spec "During pairing")
	if (feat && (feat->io_capability == BT_IO_NO_INPUT_OUTPUT)) {
		LOG_WRN(FP_AUTH_LOG_PREFIX
			"Reject pairing: Seeker has NoInput/NoOutput capability");
		return BT_SECURITY_ERR_PAIR_NOT_ALLOWED;
	}

	struct fp_auth_conn_data *data = fp_auth_find_conn_data(conn);

	if (!data || !data->kbp_verified) {
		LOG_WRN(FP_AUTH_LOG_PREFIX "Reject pairing: KBP not verified (mode=%d)",
			fp_mode_get());
		return BT_SECURITY_ERR_PAIR_NOT_ALLOWED;
	}

	// Pairing has started — cancel the post-KBP K discard timer (spec step 4)
	if (fp_auth_on_pairing_started) {
		fp_auth_on_pairing_started();
	}

	LOG_DBG(FP_AUTH_LOG_PREFIX "Accept pairing: KBP verified for conn %p", (void *)conn);
	return BT_SECURITY_ERR_SUCCESS;
}
#endif /* CONFIG_BT_SMP_APP_PAIRING_ACCEPT */

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

// Single unified auth callback set for all FP connections.
// pairing_accept gates on the per-connection kbp_verified flag, so it handles
// both initial pairing and subsequent pairing without needing to re-register.
static struct bt_conn_auth_cb fp_auth_pairing_callbacks = {
#ifdef CONFIG_BT_SMP_APP_PAIRING_ACCEPT
	.pairing_accept = fp_auth_pairing_accept,
#endif
	// Fast Pair requires DisplayYesNo IO capability for passkey confirmation
	.passkey_display = fp_auth_passkey_display,
	.passkey_confirm = fp_auth_passkey_confirm,
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

static void fp_auth_connected(struct bt_conn *conn, uint8_t err)
{
	if (!fp_conn_validate(conn)) {
		return;
	}

	if (err) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Connection failed, err %u", err);
		return;
	}

	LOG_DBG(FP_AUTH_LOG_PREFIX "Connected");

	// In global mode the pairing_accept gate is installed once at init time
	// via bt_conn_auth_cb_register, so no per-connection overlay is needed.
#ifndef CONFIG_FAST_PAIR_AUTH_CB_GLOBAL
	// Overlay mode: attempt overlay at connect time so that pairing_accept
	// gates any pairing attempt (including rogue ones) before KBP is
	// triggered. May fail (-EALREADY) if bt_smp_connected has not yet
	// initialized smp->auth_cb; fp_auth_allow_pairing recovers the race when
	// KBP completes, before the application calls bt_conn_set_security.
	int overlay_err = bt_conn_auth_cb_overlay(conn, &fp_auth_pairing_callbacks);
	if (overlay_err == -EALREADY) {
		// Race: bt_smp_connected has not yet set smp->auth_cb to
		// BT_SMP_AUTH_CB_UNINITIALIZED. fp_auth_allow_pairing will
		// retry after the KBP write, by which time L2CAP is settled.
		LOG_DBG(FP_AUTH_LOG_PREFIX "Overlay deferred for conn %p", (void *)conn);
	} else if (overlay_err) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Overlay failed for conn %p: %d", (void *)conn,
			overlay_err);
	}
#endif
}

// Connection callbacks for disconnect handling
BT_CONN_CB_DEFINE(fp_auth_conn_callbacks) = {
	.disconnected = fp_auth_disconnected,
	.connected = fp_auth_connected,
};

int fp_auth_allow_pairing(struct bt_conn *conn)
{
	if (!fp_conn_validate(conn)) {
		return -EINVAL;
	}

	struct fp_auth_conn_data *data = fp_auth_get_conn_data(conn);
	if (!data) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Failed to get conn data for pairing accept");
		return -ENOMEM;
	}

	// In global mode the gate is already active via bt_conn_auth_cb_register;
	// no per-connection overlay is needed. Just mark KBP verified.
#ifndef CONFIG_FAST_PAIR_AUTH_CB_GLOBAL
	int overlay_err = bt_conn_auth_cb_overlay(conn, &fp_auth_pairing_callbacks);
	if (overlay_err && (overlay_err != -EALREADY)) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Overlay failed for conn %p: %d (fail-closed)",
			(void *)conn, overlay_err);
		return overlay_err;
	}
#endif

	data->kbp_verified = 1;
	LOG_DBG(FP_AUTH_LOG_PREFIX "Pairing accepted for conn %p", (void *)conn);
	return 0;
}

bool fp_auth_is_account_key_proven(struct bt_conn *conn)
{
	struct fp_auth_conn_data *data = fp_auth_find_conn_data(conn);

	return data && data->kbp_verified;
}

int fp_auth_init(void)
{
	if (fp_auth_init_done) {
		return 0;
	}

	// In global mode, install the pairing_accept gate once for all connections
	// via the global auth-cb slot. latch_auth_cb will then latch our callbacks
	// for every connection, eliminating the per-connection overlay race.
#ifdef CONFIG_FAST_PAIR_AUTH_CB_GLOBAL
	int auth_cb_err = bt_conn_auth_cb_register(&fp_auth_pairing_callbacks);
	if (auth_cb_err) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Global auth cb reg failed: %d", auth_cb_err);
		return auth_cb_err;
	}
	LOG_DBG(FP_AUTH_LOG_PREFIX "Global auth callbacks registered");
#endif

	// Register Bluetooth authentication info callbacks for pairing status
	int auth_info_err = bt_conn_auth_info_cb_register(&fp_auth_info_callbacks);
	if (auth_info_err) {
		LOG_ERR(FP_AUTH_LOG_PREFIX "Auth info callback reg failed: %d", auth_info_err);
		// Clean up auth callbacks on failure
#ifdef CONFIG_FAST_PAIR_AUTH_CB_GLOBAL
		bt_conn_auth_cb_register(NULL);
#endif
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
			fp_auth_connections[i].kbp_verified = 0;
		}
	}

	// Unregister authentication info callbacks
	bt_conn_auth_info_cb_unregister(&fp_auth_info_callbacks);

	// In global mode, release the global auth-cb slot.
#ifdef CONFIG_FAST_PAIR_AUTH_CB_GLOBAL
	bt_conn_auth_cb_register(NULL);
#endif

	fp_auth_passkey_timeout_cancel();

	fp_auth_init_done = false;
	LOG_DBG(FP_AUTH_LOG_PREFIX "Auth deinit completed");
}

#if defined(CONFIG_ZTEST)
void fp_auth_test_pairing_complete(struct bt_conn *conn, bool bonded)
{
	fp_auth_pairing_complete(conn, bonded);
}

void fp_auth_test_pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	fp_auth_pairing_failed(conn, reason);
}

void fp_auth_test_cancel(struct bt_conn *conn)
{
	fp_auth_cancel(conn);
}

void fp_auth_test_passkey_timeout(void)
{
	fp_auth_passkey_timeout_handler(NULL);
}

void fp_auth_test_passkey_timeout_handler(void)
{
	fp_auth_passkey_timeout_handler(NULL);
}

void fp_auth_test_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
	fp_auth_passkey_display(conn, passkey);
}

void fp_auth_test_passkey_confirm(struct bt_conn *conn, unsigned int passkey)
{
	fp_auth_passkey_confirm(conn, passkey);
}

void fp_auth_test_allow_pairing_conn(struct bt_conn *conn)
{
	fp_auth_allow_pairing(conn);
}

enum bt_security_err fp_auth_test_pairing_accept(struct bt_conn *conn)
{
	return fp_auth_pairing_accept(conn, NULL);
}

void fp_auth_test_connected(struct bt_conn *conn, uint8_t err)
{
	fp_auth_connected(conn, err);
}

void fp_auth_test_disconnected(struct bt_conn *conn, uint8_t reason)
{
	fp_auth_disconnected(conn, reason);
}
#endif /* CONFIG_ZTEST */
