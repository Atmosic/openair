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
 * @brief Sensor data structure for beacon advertising
 *
 * This structure defines the sensor data format used in beacon advertisements
 * to ensure compatibility with existing client applications.
 */
typedef struct {
	uint16_t temp;      /**< Temperature reading */
	uint16_t humidity;  /**< Humidity reading */
	uint16_t x_axis;    /**< X-axis acceleration */
	uint16_t y_axis;    /**< Y-axis acceleration */
	uint16_t z_axis;    /**< Z-axis acceleration */
	float vstore;       /**< Storage voltage */
	float vbatt;        /**< Battery voltage */
} __packed sensor_beacon_data_t;

/**
 * @brief Initialize the sensor beacon application
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_beacon_init(void);

/**
 * @brief Start the sensor beacon operation
 *
 * This starts the periodic sensor reading and beacon advertising.
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_beacon_start(void);

/**
 * @brief Stop the sensor beacon operation
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_beacon_stop(void);

/**
 * @brief Get the current sensor data
 *
 * @param data Pointer to store the sensor data
 * @return 0 on success, negative error code on failure
 */
int sensor_beacon_get_data(sensor_beacon_data_t *data);

#ifdef __cplusplus
}
#endif
