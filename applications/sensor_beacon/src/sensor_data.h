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
 * @brief Initialize the sensor data collection system
 *
 * This initializes the periodic timer for sensor data collection
 * and beacon advertisement updates.
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_data_init(void);

/**
 * @brief Start periodic sensor data collection
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_data_start(void);

/**
 * @brief Stop periodic sensor data collection
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_data_stop(void);

/**
 * @brief Collect sensor data immediately
 *
 * This function collects all sensor data (temperature, humidity,
 * accelerometer, battery voltages) and updates the beacon advertisement.
 *
 * @return 0 on success, negative error code on failure
 */
int sensor_data_collect_and_update(void);

#ifdef __cplusplus
}
#endif
