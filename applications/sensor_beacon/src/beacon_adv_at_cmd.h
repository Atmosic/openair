/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2025-2026 Atmosic
 */

#pragma once

#include <zephyr/kernel.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file beacon_adv_at_cmd.h
 * @brief AT command extensions for beacon advertising
 *
 * This header declares the AT command-specific beacon advertising functions
 * that provide settings persistence and enhanced functionality for AT command
 * interfaces.
 */

/**
 * @brief Set advertising interval with settings persistence
 *
 * Updates the advertising interval and saves it to persistent storage.
 * This function is used by AT command handlers.
 *
 * @param interval Advertising interval in units of 0.625ms (400-16384)
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_set_interval(uint32_t interval);

/**
 * @brief Set device name with settings persistence
 *
 * Updates the device name in advertising data and saves it to persistent storage.
 * This function is used by AT command handlers.
 *
 * @param name New device name (null-terminated string)
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_set_device_name(const char *name);

/**
 * @brief Set or clear user data with settings persistence
 *
 * Sets user data in TLV format in the advertising and saves it to persistent storage.
 * Pass NULL or 0 length to clear user data and revert to sensor-only advertising.
 * This function is used by AT command handlers.
 *
 * @param data User data in TLV format, or NULL to clear
 * @param len Length of user data, or 0 to clear
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_set_user_data(const uint8_t *data, uint16_t len);

#ifdef __cplusplus
}
#endif
