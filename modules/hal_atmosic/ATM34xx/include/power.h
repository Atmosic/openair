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

#ifdef __cplusplus
}
#endif

/// @} POWER
