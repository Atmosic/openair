/**
 *******************************************************************************
 *
 * @file platform_ctrl_buzzer.h
 *
 * @brief Platform control buzzer For Multimode Consumer Tag
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
 * @brief Configure buzzer frequency and duty cycle
 * @param[in] freq_hz     Buzzer tone frequency in Hz
 * @param[in] duty_percent PWM duty cycle percentage (0–100)
 */
void platform_ctrl_buzzer_config(uint32_t freq_hz, uint32_t duty_percent);

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
