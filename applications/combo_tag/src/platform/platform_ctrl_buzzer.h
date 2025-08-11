/**
 *******************************************************************************
 *
 * @file platform_ctrl_buzzer.h
 *
 * @brief Platform control buzzer For FMNA and FMDN Combo Tag
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
 * @brief Platform sound play control
 * @param[in] action enable or disable
 */
void platform_ctrl_buzzer_action(bool action);

/**
 * @brief Platform sound play control init
 */
void platform_ctrl_buzzer_init(void);

#ifdef __cplusplus
}
#endif

///@}
