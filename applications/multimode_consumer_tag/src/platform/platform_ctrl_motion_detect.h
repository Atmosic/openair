/**
 *******************************************************************************
 *
 * @file platform_ctrl_motion_detect.h
 *
 * @brief Platform control motion detect For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Platform motion detect init
 * @return 0 on success, negative errno on failure
 */
int platform_ctrl_motion_detect_init(void);

/**
 * @brief Platform motion detect action
 * @param[in] action enable or disable
 * @return 0 on success, negative errno on failure
 */
int platform_ctrl_motion_detect_action(bool action);

/**
 * @brief Platform motion detect get status
 *
 * @return true if motion detected
 */
bool platform_ctrl_motion_detect_get_status(void);

/** Unit selector for platform_ctrl_motion_detect_get_raw_data(). */
typedef enum {
	/** Tilt angle in whole degrees (0–90). Used by motion_raw_to_status(). */
	MOTION_RAW_UNIT_DEG,
	/** Horizontal acceleration in 0.01 m/s² (cm/s²) units (0–255). */
	MOTION_RAW_UNIT_CS2,
} motion_raw_unit_t;

/**
 * @brief Sample the motion sensor and return a scalar reading.
 *
 * @param unit  Selects the output unit — degrees or cm/s².
 * @return      Reading in the requested unit, 0 if sensor unavailable.
 */
uint8_t platform_ctrl_motion_detect_get_raw_data(motion_raw_unit_t unit);

#ifdef CONFIG_AT_CMD_TAGMOTIONRPT
/**
 * @brief Inject XYZ acceleration from the host sensor.
 *
 * @param x_cs2  X-axis acceleration in cm/s² (signed).
 * @param y_cs2  Y-axis acceleration in cm/s² (signed).
 * @param z_cs2  Z-axis acceleration in cm/s² (signed).
 */
void platform_ctrl_motion_detect_inject(int16_t x_cs2, int16_t y_cs2, int16_t z_cs2);
#endif

#ifdef __cplusplus
}
#endif
