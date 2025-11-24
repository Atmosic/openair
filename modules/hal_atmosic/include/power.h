/**
 *******************************************************************************
 *
 * @file power.h
 *
 * @brief Power mode api
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup POWER POWER
 * @ingroup DRIVERS
 * @brief Power mode interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define PM_SUBSTATE_HIBERNATE DT_PROP(DT_NODELABEL(hibernate), substate_id)
#define PM_SUBSTATE_SOC_OFF DT_PROP(DT_NODELABEL(soc_off), substate_id)

/**
 * @brief Move the device to 'SOC off' state for specified duration
 * @param[in] ticks Duration
 */
void atm_pseq_soc_off(uint32_t ticks);

/**
 * @brief Move the device to 'Hibernate' state for specified duration
 * @param[in] ticks Duration
 */
void atm_pseq_hibernate(uint32_t ticks);

/**
 * @brief Set GPIO wakeup from SOC off state
 *
 * Uses GPIO pin 5 which is the only supported GPIO wakeup pin.
 * The pin will be configured for high-level wakeup when enabled.
 *
 * @param enable true to enable GPIO wakeup, false to disable
 */
void atm_socoff_wakeup_gpio_set(bool enable);

/**
 * @brief WuRx algorithm enable state global variables
 *
 * These global variables control the WuRx algorithm enable state that is used
 * by the power management system during hibernation and retention modes. The
 * power management system reads these states to configure wake-up sources when
 * entering low-power modes.
 *
 * wurx0_enabled: true to enable WuRx algorithm 0 for wake-up, false to disable
 * wurx1_enabled: true to enable WuRx algorithm 1 for wake-up, false to disable
 */
extern bool wurx0_enabled, wurx1_enabled;

#ifdef __cplusplus
}
#endif

/// @} POWER
