/**
 *******************************************************************************
 *
 * @file power.h
 *
 * @brief Power mode api
 *
 * Copyright (C) Atmosic 2024
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

#ifdef __cplusplus
}
#endif

/// @} POWER
