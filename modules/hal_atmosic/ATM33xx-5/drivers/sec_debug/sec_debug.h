/**
 ******************************************************************************
 *
 * @file sec_debug.h
 *
 * @brief Secure Debug driver
 *
 * Copyright (C) Atmosic 2023
 *
 ******************************************************************************
 */

#pragma once
#include "stdbool.h"

/**
 * @defgroup SEC_DEBUG Secure Debug
 * @ingroup DRIVERS
 * @brief Secure Debug driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SECURE_MODE
#error "sec_debug is a secure-only driver"
#endif

typedef enum {
    /// Debug is disabled but can be enabled
    SEC_DEBUG_SOFT_DISABLED = 1,
    /// Debug is disabled this boot
    SEC_DEBUG_STICKY_DISABLED = 2,
    /// Debug permanently disabled
    SEC_DEBUG_HARD_DISABLED = 3,
    /// Debug is enabled,
    SEC_DEBUG_ENABLED = 4,
    /// Debug state is unknown
    SEC_DEBUG_UNKNOWN,

    SEC_DEBUG_STATUS_MIN = SEC_DEBUG_SOFT_DISABLED,
    SEC_DEBUG_STATUS_MAX = SEC_DEBUG_ENABLED
} sec_debug_status_t;

/**
 * @brief check current status of secure debug
 *
 * @return current state of debug
 */
sec_debug_status_t sec_debug_status(void);

/**
 * @brief Sticky disable secure debug until the next reboot
 *
 * @note Requires the current state to be SEC_DEBUG_SOFT_ENABLED
 *
 * @return true if state changed successfully
 */
bool sec_debug_sticky_disable(void);

/**
 * @brief Unlock the debug port
 *
 * @note Requires the current state to be SEC_DEBUG_SOFT_ENABLED
 *
 * @return true if state changed successfully
 */
bool sec_debug_unlock(void);

#ifdef __cplusplus
}
#endif

/// @}
