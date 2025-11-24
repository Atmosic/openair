/**
 *******************************************************************************
 *
 * @file radio_hal_prof.h
 *
 * @brief Radio Profile Driver Interface
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_HAL_PROF RADIO_HAL_PROF
 * @ingroup DRIVERS
 * @brief Radio Profile Driver Interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "radio_hal_log.h"

#ifndef RADIO_HAL_PROF_TRACKING
#define RADIO_HAL_PROF_TRACKING 1
#endif

/** Default threshold to use for latency measurement */
#define ATM_MAC_PROF_DEFAULT_LATENCY_THRESHOLD 30

typedef bool (*atm_mac_prof_check_callback_t)(uint16_t latency);

/**
 * @brief Latency profiling information
 *
 * Allocate a struct for each latency result to measure
 */
typedef struct {
    uint16_t max_latency; /*!< Maximum observed latency, in microseconds */
    uint16_t min_latency; /*!< Minimum observed latency, in microseconds */
    uint16_t threshold; /*!< Assert when above this value, in microseconds */
    atm_mac_log_type_t log_type; /*!< Type to use when logging errors */
    atm_mac_prof_check_callback_t check_callback; /*!< Callback to decide if
						     check profile failure */
} atm_mac_prof_t;

/** Constructor for measurement type with custom threshold */
#define ATM_MAC_PROF_WITH_THRESHOLD(latency_threshold, logging_type) { \
    .max_latency = 0, \
    .min_latency = UINT16_MAX, \
    .threshold = (latency_threshold), \
    .log_type = (logging_type), \
    .check_callback = atm_mac_prof_default_check_callback, \
}

/** Constructor for measurement type with default threshold */
#define ATM_MAC_PROF_DEFAULT(logging_type) \
    ATM_MAC_PROF_WITH_THRESHOLD(ATM_MAC_PROF_DEFAULT_LATENCY_THRESHOLD, \
	logging_type)

/**
 * @brief Update latency value
 *
 * @param[in] prof Current profiling data
 * @param[in] latency New latency value to insert
 */
void atm_mac_prof_latency_update(atm_mac_prof_t *prof, uint16_t latency);

/**
 * @brief Default profile check callback
 *
 * @param[in] latency New latency value to insert
 * @return True to check profile failure
 */
__STATIC_INLINE
bool atm_mac_prof_default_check_callback(uint16_t latency)
{
    return true;
}

/**
 * @brief Register profile check callback
 *
 * @param[in] prof Current profiling data
 * @param[in] callback Profile check callback
 */
__STATIC_INLINE __NONNULL_ALL
void atm_mac_prof_register_check_callback(atm_mac_prof_t *prof,
    atm_mac_prof_check_callback_t callback)
{
    prof->check_callback = callback;
}

#ifdef __cplusplus
}
#endif

/// @}
