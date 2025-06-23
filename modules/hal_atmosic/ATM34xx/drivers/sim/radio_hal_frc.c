/**
 ******************************************************************************
 *
 * @file radio_hal_frc.c
 *
 * @brief Simulated Radio FRC Driver Interface
 *
 * Copyright (C) Atmosic 2024
 *
 ******************************************************************************
 */

#include <zephyr/ztest.h>
#include "radio_hal_frc.h"

// Store the current FRC time
static uint32_t frc_current_us;

// Keep the needed state variables for each of the existing FRC HW timers
static uint32_t timer_expiration_us[ATM_MAC_FRC_NUM_TIMERS];
static bool timer_running[ATM_MAC_FRC_NUM_TIMERS];
static atm_mac_frc_callback_t timer_callback[ATM_MAC_FRC_NUM_TIMERS];

uint32_t atm_mac_frc_get_current_time(void)
{
    return frc_current_us;
}

atm_mac_frc_error_t atm_mac_frc_get_timer_remaining(atm_mac_frc_timer_t timer,
    uint32_t current_time_us, uint32_t *time_us)
{
    zassert_true(timer < ATM_MAC_FRC_NUM_TIMERS);
    if (!timer_running[timer]) {
	return ATM_MAC_FRC_ERROR_INACTIVE;
    }
    *time_us =
	ATM_MAC_FRC_DELTA_US(current_time_us, timer_expiration_us[timer]);
    return ATM_MAC_FRC_ERROR_NONE;
}

void atm_mac_frc_stop_timer(atm_mac_frc_timer_t timer)
{
    zassert_true(timer < ATM_MAC_FRC_NUM_TIMERS);
    zassert_true(timer_running[timer]);
    timer_running[timer] = false;
}

atm_mac_frc_error_t atm_mac_frc_set_timer(atm_mac_frc_timer_t timer,
    uint32_t timeout_us, atm_mac_frc_callback_t callback)
{
    zassert_true(timer < ATM_MAC_FRC_NUM_TIMERS);
    if (timer_running[timer]) {
	return ATM_MAC_FRC_ERROR_BUSY;
    }
    timer_callback[timer] = callback;
    timer_expiration_us[timer] = timeout_us;
    timer_running[timer] = true;
    return ATM_MAC_FRC_ERROR_NONE;
}

void atm_mac_frc_advance_sim_time(uint32_t new_time_us)
{
    uint32_t old_time_us = frc_current_us;
    frc_current_us = new_time_us;

    // Check each timer and call the callback if it expired
    for (atm_mac_frc_timer_t t = 0; t < ATM_MAC_FRC_NUM_TIMERS; t++) {
	if (timer_running[t] &&
	    (ATM_MAC_FRC_DELTA_US(old_time_us, timer_expiration_us[t]) <=
		ATM_MAC_FRC_DELTA_US(old_time_us, new_time_us))) {
	    timer_callback[t]();
	}
    }
}
