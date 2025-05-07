/**
 *******************************************************************************
 *
 * @file fp_tag_platform_ctrl.h
 *
 * @brief Platform control For fp tag
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
 * @brief Platform motion detect of DULT
 * @param[in] action enable or disable
 */
void fp_tag_platform_ctrl_motion_detect_action(bool action);

/**
 * @brief Platform sound play control of DULT
 * @param[in] action enable or disable
 */
void fp_tag_platform_ctrl_buzzer_action(bool action);

/**
 * @brief Platform battery status get
 *
 * @return battery status in percentage
 */
uint8_t fp_tag_platform_battery_status_get(void);

/**
 * @brief Platform control init
 */
void fp_tag_platform_ctrl_init(void);

/**
 * @brief Platform control deinit
 */
void fp_tag_platform_ctrl_reset(void);

#ifdef __cplusplus
}
#endif

///@}
