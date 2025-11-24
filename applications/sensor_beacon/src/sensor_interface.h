/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#pragma once

#include <zephyr/kernel.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the sensor interface
 *
 * This initializes the temperature/humidity sensor (ENS210) and
 * accelerometer (LIS2DH) interfaces.
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_interface_init(void);

/**
 * @brief Get temperature and humidity readings
 *
 * Reads temperature and humidity from the ENS210 sensor and applies
 * scaling for fixed-point format.
 *
 * @param temp Pointer to store temperature reading (scaled)
 * @param humidity Pointer to store humidity reading (scaled)
 * @return 0 on success, negative error code on failure
 */
int sensor_interface_get_temp_humidity(uint16_t *temp, uint16_t *humidity);

/**
 * @brief Get accelerometer readings
 *
 * Reads accelerometer data from the LIS2DH sensor and applies
 * scaling for fixed-point format.
 *
 * @param accel_x Pointer to store X-axis acceleration (scaled)
 * @param accel_y Pointer to store Y-axis acceleration (scaled)
 * @param accel_z Pointer to store Z-axis acceleration (scaled)
 * @return 0 on success, negative error code on failure
 */
int sensor_interface_get_accel(uint16_t *accel_x, uint16_t *accel_y, uint16_t *accel_z);

#ifdef __cplusplus
}
#endif
