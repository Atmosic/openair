/**
 *******************************************************************************
 *
 * @file ble_driver.h
 *
 * @brief Atmosic ATLC power management driver
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Ensure that ATLC is awake before directly invoking mac APIs.
 * Should be symmetrically paired with a call to unlock when the requirement
 * has cleared.  Internal operation is thread safe.
 *
 * @note MUST NOT be invoked from interrupt context.
 */
void atm_mac_lock_sync(void);

/**
 * @brief Release lock.  Internal operation is thread safe.
 */
void atm_mac_unlock(void);

#ifdef __cplusplus
}
#endif
