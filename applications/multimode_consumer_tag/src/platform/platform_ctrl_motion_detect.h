/**
 *******************************************************************************
 *
 * @file platform_ctrl_motion detect.h
 *
 * @brief Platform control motion detect For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Platform motion detect action
 * @param[in] action enable or disable
 */
void platform_ctrl_motion_detect_action(bool action);

/**
 * @brief Platform motion detect init
 */
void platform_ctrl_motion_detect_init(void);

/**
 * @brief Platform motion detect get status
 *
 * @return true if motion detected
 */
bool platform_ctrl_motion_detect_get_status(void);

#ifdef __cplusplus
}
#endif

///@}
