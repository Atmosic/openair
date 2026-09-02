/**
 *******************************************************************************
 *
 * @file ble_driver.h
 *
 * @brief Atmosic ATLC power management driver
 *
 * Copyright (C) Atmosic 2023-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#include <stdint.h>

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

/**
 * @brief Get the current remaining timed ATLC sleep duration in Zephyr ticks.
 *
 * @return Remaining sleep duration in Zephyr ticks, or K_TICKS_FOREVER when no
 *         timed ATLC sleep is active.
 */
int64_t atm_ble_sleep_remaining_ticks(void);

#ifdef __cplusplus
}
#endif
