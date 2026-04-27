/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2025-2026 Atmosic
 */

#pragma once

#include <zephyr/kernel.h>
#include "sensor_beacon.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the beacon advertising
 *
 * This initializes the Bluetooth subsystem and creates the advertising set
 * with the standard beacon format for client compatibility.
 *
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_init(void);

/**
 * @brief Start beacon advertising
 *
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_start(void);

/**
 * @brief Stop beacon advertising
 *
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_stop(void);

/**
 * @brief Update beacon advertisement data
 *
 * @param data Pointer to sensor data to include in advertisement
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_update_data(const sensor_beacon_data_t *data);

/**
 * @brief Set advertising data
 *
 * Sets the standard advertising data with fixed elements (sensor data only).
 * This function updates the advertising data for the current advertising set.
 *
 * @return 0 on success, negative error code on failure
 */
int beacon_set_adv_data(void);

/**
 * @brief Update advertising interval
 *
 * Stops advertising, updates interval parameters, and restarts advertising.
 *
 * @param interval Advertising interval in units of 0.625ms (400-16384)
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_update_interval(uint32_t interval);

/**
 * @brief Update device name in advertising data
 *
 * Updates the device name in both main beacon and connection advertising sets.
 * Handles stopping/restarting advertising as needed.
 *
 * @param name New device name (null-terminated string)
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_update_device_name(const char *name);

/**
 * @brief Set device name buffer without updating advertising
 *
 * Updates only the internal device name buffer without affecting active
 * advertising. This is intended for use during initialization (e.g., settings
 * loading) when advertising is not yet active.
 *
 * @param name New device name (null-terminated string)
 * @return 0 on success, negative error code on failure
 */
int beacon_adv_set_device_name_buffer(const char *name);

#ifdef __cplusplus
}
#endif
