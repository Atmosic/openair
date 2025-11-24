/**
 ******************************************************************************
 *
 * @file radio_hal_frc.h
 *
 * @brief Radio FRC Driver Interface
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#pragma once

#ifdef CONFIG_BOARD_UNIT_TESTING
#define __NONNULL(...)
#else
#include "arch.h"
#include <stdint.h>
#endif

/**
 * @defgroup RADIO_HAL_FRC RADIO_HAL_FRC
 * @ingroup DRIVERS
 * @brief Radio FRC Driver Interface
 *
 * This module provides access to the ATLC (Atmosic Link Controller) Free
 * Running Counter (FRC) and its associated hardware timers. The FRC is a
 * microsecond-resolution counter used for precise timing and scheduling in
 * radio operations.
 *
 * @warning The ATLC must be awake to call the functions in this module
 *
 * @par Preventing ATLC Sleep
 * To ensure the ATLC remains awake while using FRC functions, use the sleep
 * lock mechanism provided by atm_mac_lock_sync() and atm_mac_unlock() from
 * ble_driver.h. The FRC continues to run during ATLC sleep, but its registers
 * cannot be accessed. Hardware-configured timers will still expire and
 * generate interrupts that wake the ATLC
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define ATM_MAC_FRC_MS_TO_TICKS(time_ms) (1000 * (time_ms))
#define ATM_MAC_FRC_DELTA_MS(start_tick, end_tick) \
    (((end_tick) - (start_tick)) / 1000)
#define ATM_MAC_FRC_DELTA_US(start_tick, end_tick) ((end_tick) - (start_tick))
#define ATM_MAC_FRC_SIGNED_DELTA_US(start_tick, end_tick) \
    ((int32_t)((end_tick) - (start_tick)))

typedef enum {
    ATM_MAC_FRC_TIMER0,
    ATM_MAC_FRC_TIMER1,
    ATM_MAC_FRC_TIMER2,
    ATM_MAC_FRC_NUM_TIMERS
} atm_mac_frc_timer_t;

/**
 * @brief FRC errors
 * - ATM_MAC_FRC_ERROR_NONE - success
 * - ATM_MAC_FRC_ERROR_INVALID - invalid parameters
 * - ATM_MAC_FRC_ERROR_BUSY - timer is busy
 * - ATM_MAC_FRC_ERROR_INACTIVE - timer(s) inactive
 * - ATM_MAC_FRC_ERROR_EXPIRED - timer has expired, interrupt is pending
 */
typedef enum {
    ATM_MAC_FRC_ERROR_NONE,
    ATM_MAC_FRC_ERROR_INVALID,
    ATM_MAC_FRC_ERROR_BUSY,
    ATM_MAC_FRC_ERROR_INACTIVE,
    ATM_MAC_FRC_ERROR_EXPIRED,
} atm_mac_frc_error_t;

typedef void (*atm_mac_frc_callback_t)(void);

/**
 * @brief Get Current ATLC FRC Timer Value.
 *
 * This function is used the current time from FRC.
 *
 * @return       Time in microseconds
 */
uint32_t atm_mac_frc_get_current_time(void);

/**
 * @brief Check if ATLC FRC Timer is active
 *
 * @param[in]    timer       Timer number
 * @return       True if timer is active, false if inactive
 */
bool atm_mac_frc_get_timer_active(atm_mac_frc_timer_t timer);

/**
 * @brief Get Next ATLC FRC Timer Expiration.
 *
 * This function is used to get the next FRC timeout value.
 * ATM_MAC_FRC_ERROR_INACTIVE will be returned if all timers are inactive.
 * ATM_MAC_FRC_ERROR_EXPIRED will be returned if a timer has expired and is
 * pending interrupt handling. The timeout_us paramter will only be valid
 * if return value is ATM_MAC_FRC_ERROR_NONE.
 * @note This function should be called with interrupts disabled
 *
 * @param[in]    current_time_us  Current time in microseconds
 * @param[in]    timeout_us  Timeout in microseconds - may be NULL
 * @return       Error value @ref atm_mac_frc_error_t
 */
atm_mac_frc_error_t atm_mac_frc_get_next_expiration(uint32_t current_time_us,
    uint32_t *timeout_us);

/**
 * @brief Get ATLC FRC Timer Expiration.
 *
 * This function is used to get the timeout value of a given FRC timer.
 * ATM_MAC_FRC_ERROR_INACTIVE will be returned if the timer is inactive.
 * ATM_MAC_FRC_ERROR_EXPIRED will be returned if a timer has expired and is
 * pending interrupt handling. The timeout_us paramter will only be valid
 * if return value is ATM_MAC_FRC_ERROR_NONE.
 *
 * @param[in]    timer       Timer number
 * @param[in]    timeout_us  Timeout in microseconds
 * @return       Error value @ref atm_mac_frc_error_t
 */
__NONNULL(2)
atm_mac_frc_error_t atm_mac_frc_get_timer_expiration(atm_mac_frc_timer_t timer,
    uint32_t *timeout_us);

/**
 * @brief Get Remaining Time on ATLC FRC Timer.
 *
 * This function is used to get the remaining time on a given FRC timer.
 * ATM_MAC_FRC_ERROR_INACTIVE will be returned if the timer is inactive.
 * ATM_MAC_FRC_ERROR_EXPIRED will be returned if a timer has expired and is
 * pending interrupt handling. The time_us paramter will only be valid
 * if return value is ATM_MAC_FRC_ERROR_NONE.
 *
 * @param[in]    timer       Timer number
 * @param[in]    current_time_us  Current time in microseconds
 * @param[in]    time_us  Delta from current time to timeout in microseconds
 * @return       Error value @ref atm_mac_frc_error_t
 */
__NONNULL(3)
atm_mac_frc_error_t atm_mac_frc_get_timer_remaining(atm_mac_frc_timer_t timer,
    uint32_t current_time_us, uint32_t *time_us);

/**
 * @brief Set ATLC FRC Timer.
 *
 * This function is used to set a timer using the FRC.
 * @note Timer must be stopped first. Calling this function on an active timer
 * will not overwrite the current timer configuration.
 * @par
 * @note This function and @ref atm_mac_frc_stop_timer should both be called
 * within the same priority context
 *
 * @param[in]    timer       Timer number
 * @param[in]    timeout_us  Timeout in microseconds
 * @param[in]    callback    Callback on timeout
 * @return       Error value @ref atm_mac_frc_error_t
 */
__NONNULL(3)
atm_mac_frc_error_t atm_mac_frc_set_timer(atm_mac_frc_timer_t timer,
    uint32_t timeout_us, atm_mac_frc_callback_t callback);

/**
 * @brief Stop ATLC FRC Timer.
 *
 * This function is used to stop an FRC timer.
 * @note This function and @ref atm_mac_frc_set_timer should both be called
 * within the same priority context
 *
 * @param[in]    timer       Timer number
 */
void atm_mac_frc_stop_timer(atm_mac_frc_timer_t timer);

#ifdef CONFIG_BOARD_UNIT_TESTING
/**
 * @brief Advance simulated ATLC FRC Timer.
 *
 * When running unit tests, there is no hardware that steps time forward. This
 * function is called to advance the time to a new value. Using this function
 * will trigger any pending timers, and change the results of future calls
 * to @ref atm_mac_frc_get_current_time.
 *
 * @param[in]    new_time    The new value for the FRC time
 */
void atm_mac_frc_advance_sim_time(uint32_t new_time);
#endif

#ifdef __cplusplus
}
#endif

/// @}
