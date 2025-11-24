/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2021-2025 Atmosic
 */

#pragma once

#include <zephyr/kernel.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the battery monitoring interface
 *
 * This initializes the ADC channels for VStore and VBatt monitoring.
 *
 * @return 0 on success, negative error code on failure
 */
int battery_monitor_init(void);

/**
 * @brief Get battery and storage voltages
 *
 * Reads the VStore and VBatt voltages using ADC.
 *
 * @param vstore Pointer to store VStore voltage in volts
 * @param vbatt Pointer to store VBatt voltage in volts
 * @return 0 on success, negative error code on failure
 */
int battery_monitor_get_voltages(float *vstore, float *vbatt);

#ifdef __cplusplus
}
#endif
