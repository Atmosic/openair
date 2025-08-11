/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize motion detection
 */
void motion_init(void);

/**
 * @brief Deinitialize motion detection
 */
void motion_deinit(void);

/**
 * @brief Check if motion is detected
 * @return true if motion is detected
 */
bool motion_detected(void);

#ifdef __cplusplus
}
#endif
