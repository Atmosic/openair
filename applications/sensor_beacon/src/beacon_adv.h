/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
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
 * @brief Get current device name
 *
 * Returns the current device name used in advertising data.
 *
 * @return Current device name string
 */
const char *beacon_adv_get_device_name(void);

#ifdef __cplusplus
}
#endif
