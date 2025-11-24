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
	uint16_t temp;     /**< Temperature reading */
	uint16_t humidity; /**< Humidity reading */
	uint16_t x_axis;   /**< X-axis acceleration */
	uint16_t y_axis;   /**< Y-axis acceleration */
	uint16_t z_axis;   /**< Z-axis acceleration */
	float vstore;      /**< Storage voltage */
	float vbatt;       /**< Battery voltage */
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
 * This function stops both advertising and sensor data collection.
 * Must be called from thread context (not ISR).
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

/**
 * @brief Notify beacon transmission for LED status indication
 *
 * This should be called every time a beacon is transmitted to enable
 * the LED status indication (blink every 10 beacons).
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_beacon_notify_beacon_tx(void);

#ifdef CONFIG_PM
/**
 * @brief Unlock PM_STATE_SOFT_OFF state with appropriate substate
 *
 * This function unlocks the PM_STATE_SOFT_OFF state. When CONFIG_WURX is set,
 * it unlocks only the hibernate substate to allow WURX hibernation mode.
 * Otherwise, it unlocks all substates including soc off (if enabled).
 */
void sensor_beacon_unlock_soft_off_state(void);
#endif

#ifdef __cplusplus
}
#endif
