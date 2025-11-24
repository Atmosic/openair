/**
 *******************************************************************************
 *
 * @file platform_ctrl_ota.h
 *
 * @brief Platform control OTA For Multimode Consumer Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief Initialize OTA control module
 *
 * This function should be called during system initialization.
 * It loads the OTA flag from settings and starts OTA advertising if needed.
 *
 * @return true if OTA mode is active, false otherwise
 */
bool platform_ctrl_ota_init(void);

/**
 * @brief Enter OTA mode
 *
 * This function sets the OTA flag in settings and triggers a system reboot.
 * After reboot, the system will automatically start OTA advertising.
 *
 * @note This function does not return (triggers reboot)
 */
void platform_ctrl_ota_enter(void);

#ifdef __cplusplus
}
#endif

///@}
