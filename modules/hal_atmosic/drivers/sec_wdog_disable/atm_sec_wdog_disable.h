/**
 ******************************************************************************
 *
 * @file atm_sec_wdog_disable.h
 *
 * @brief Atmosic Secure Watchdog Disable Driver
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Magic value used to unlock the secure watchdog registers
 *
 * This magic value must be written to the LOCK register before any
 * modifications can be made to the secure watchdog control registers.
 */
#define ATM_WATCHDOG_LOCK_MAGIC 0x1ACCE551

/**
 * @brief Disable the secure watchdog timer
 *
 * This function disables the secure watchdog timer by:
 * 1. Unlocking the watchdog registers using the magic value
 * 2. Setting the control register to 0 to disable the watchdog
 * 3. Locking the registers again by clearing the lock register
 *
 * @note This function is conditionally compiled based on TrustZone
 * configuration:
 *       - In secure execution mode: Directly accesses hardware registers
 *       - In non-secure mode: Use Non-Secure Callable (NSC) functions in SPE to
 * access hardware
 */
void atm_disable_secure_watchdog(void);

#ifdef __cplusplus
}
#endif
