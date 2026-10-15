/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file fp_auth.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Authentication Middleware
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "compiler.h" /* __NONNULL_ALL */

#ifdef __cplusplus
extern "C" {
#endif

// Bluetooth passkey range (6-digit decimal numbers)
#define FP_PASSKEY_MIN 0      // Minimum passkey value (000000)
#define FP_PASSKEY_MAX 999999 // Maximum passkey value (999999)

// Fast Pair spec pairing timeout (10 s). Used by both the passkey-confirmation
// timer (fp_auth) and the post-KBP / post-pairing K-discard timer (fp_gatt).
#define FP_PAIRING_TIMEOUT_MS (10 * MSEC_PER_SEC)

/**
 * @brief Initialize Fast Pair authentication
 *
 * Registers Bluetooth authentication callbacks for Fast Pair integration
 *
 * @return 0 on success, negative error code on failure
 */
int fp_auth_init(void);

/**
 * @brief Deinitialize Fast Pair authentication
 *
 * Unregisters authentication callbacks and cleans up resources
 */
void fp_auth_deinit(void);

/**
 * @brief Get current passkey for verification
 *
 * @param conn Bluetooth connection
 * @param passkey Pointer to store the current passkey
 * @return true if passkey is valid and available, false otherwise
 */
bool fp_auth_get_passkey(struct bt_conn *conn, uint32_t *passkey);

/**
 * @brief Validate a received passkey against the stored passkey
 *
 * @param conn Bluetooth connection
 * @param received_passkey The passkey received from the peer device
 * @return true if passkey matches and is valid, false otherwise
 */
bool fp_auth_validate_passkey(struct bt_conn *conn, uint32_t received_passkey);

/**
 * @brief Mark KBP as verified for a connection
 *
 * Called after successful Key-based Pairing crypto verification.
 * Enables pairing_accept to accept the subsequent SMP pairing request
 * regardless of the current global FP mode (handles both initial and
 * subsequent pairing without changing the global mode to PAIRING_PROCESSING).
 *
 * @param conn Bluetooth connection
 *
 * @return 0 on success (overlay registered, or gate already active in global
 *         mode, or overlay already set / CAS lost to latch with -EALREADY).
 * @return -EINVAL if the connection is not a Fast Pair connection.
 * @return -ENOMEM if no connection data slot is available.
 * @return Negative errno from bt_conn_auth_cb_overlay on overlay failures other
 *         than -EALREADY (e.g. -EINVAL from a torn-down SMP channel); the
 *         pairing_accept gate is not active.
 */
int fp_auth_allow_pairing(struct bt_conn *conn);

/**
 * @brief Check if the Seeker has proven account key knowledge on this connection
 *
 * Returns true if a preceding operation on this connection successfully
 * verified the Seeker's knowledge of an account key (KBP crypto passed).
 * This is used to gate Firmware Revision reads for non-bonded Seekers per spec:
 * "operations proved the Seeker's knowledge of the account key".
 *
 * @param conn Bluetooth connection
 * @return true if account key has been proven on this connection
 */
bool fp_auth_is_account_key_proven(struct bt_conn *conn);

/**
 * @brief Callback type: BLE pairing has started (SMP pairing accepted).
 *
 * Registered by fp_gatt to cancel the post-KBP K discard timer (spec step 4).
 */
typedef void (*fp_auth_pairing_started_cb_t)(void);

/**
 * @brief Callback type: BLE pairing has completed.
 *
 * @param success true if bonding succeeded, false on failure.
 *
 * Registered by fp_gatt to manage K lifetime after pairing (spec step 10).
 */
typedef void (*fp_auth_pairing_complete_cb_t)(bool success);

/**
 * @brief Register the pairing-started callback.
 *
 * @param cb Callback invoked when SMP pairing is accepted.
 */
__NONNULL_ALL
void fp_auth_pairing_started_cb_reg(fp_auth_pairing_started_cb_t cb);

/**
 * @brief Register the pairing-complete callback.
 *
 * @param cb Callback invoked when pairing succeeds or fails.
 */
__NONNULL_ALL
void fp_auth_pairing_complete_cb_reg(fp_auth_pairing_complete_cb_t cb);

/**
 * @brief BT bond-deleted callback (also used directly in tests)
 * @param id BT identity index
 * @param peer Peer address (may be NULL)
 */
void fp_auth_bond_deleted(uint8_t id, const bt_addr_le_t *peer);

#ifdef __cplusplus
}
#endif

#if defined(CONFIG_ZTEST)
#include <zephyr/bluetooth/conn.h>

void fp_auth_test_pairing_complete(struct bt_conn *conn, bool bonded);
void fp_auth_test_pairing_failed(struct bt_conn *conn, enum bt_security_err reason);
void fp_auth_test_cancel(struct bt_conn *conn);
void fp_auth_test_passkey_timeout(void);
void fp_auth_test_passkey_timeout_handler(void);
void fp_auth_test_passkey_display(struct bt_conn *conn, unsigned int passkey);
void fp_auth_test_passkey_confirm(struct bt_conn *conn, unsigned int passkey);
void fp_auth_test_allow_pairing_conn(struct bt_conn *conn);
enum bt_security_err fp_auth_test_pairing_accept(struct bt_conn *conn);
void fp_auth_test_connected(struct bt_conn *conn, uint8_t err);
void fp_auth_test_disconnected(struct bt_conn *conn, uint8_t reason);
#endif /* CONFIG_ZTEST */
