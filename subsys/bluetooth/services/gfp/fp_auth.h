/**
 *******************************************************************************
 *
 * @file fp_auth.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Authentication Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>

// Bluetooth passkey range (6-digit decimal numbers)
#define FP_PASSKEY_MIN 0      // Minimum passkey value (000000)
#define FP_PASSKEY_MAX 999999 // Maximum passkey value (999999)

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
 */
void fp_auth_allow_pairing(struct bt_conn *conn);

#ifdef __cplusplus
}
#endif
