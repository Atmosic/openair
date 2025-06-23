/**
 ******************************************************************************
 *
 * @file sec_counter.h
 *
 * @brief Secure Counter driver
 *
 * Copyright (C) Atmosic 2022
 *
 ******************************************************************************
 */

#pragma once
#include "arch.h"
#include "stdbool.h"

/**
 * @defgroup SEC_CNTR Secure Counter
 * @ingroup DRIVERS
 * @brief Secure Counter driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Number of counters
#define SEC_CNTR_NUM_CNTR 8

/// Max value security counter can be
#define SEC_CNTR_SATURATION_VAL 2047

/// Secure Counter return values
typedef enum {
    /// OK
    SEC_CNTR_OK,
    /// Counter has saturated at max value
    SEC_CNTR_SATURATED,
    /// Directly setting counter failed
    SEC_CNTR_SET_FAILED,
    /// Increment failed
    SEC_CNTR_INCR_FAILED,
    /// Invalid Counter value
    SEC_CNTR_INVALID_CNTR,
    /// Invalid set val value
    SEC_CNTR_INVALID_SET_VAL,
    /// Caller doesnt have access to passed buffer
    SEC_CNTR_NO_ACCESS,
} sec_counter_ret_status_t;

#if (defined(SECURE_MODE) || defined(CFG_NO_SPE))
/**
 * @brief check if secure counters are enabled.
 *
 * @return true if enabled
 * @return false otherwise
 */
bool sec_counters_enabled(void);

/**
 * @brief read current value of secure counter by index
 *
 * @param[in] counter_idx index of requested counter.
 * @param[out] out value of counter
 * @return sec_counter_ret_status_t SEC_CNTR_OK on success
 */
sec_counter_ret_status_t sec_counter_read(uint8_t counter_idx, uint16_t *out);

/**
 * @brief increment secure counter by index and return value
 *
 * @param[in] counter_idx index of requested counter.
 * @param[out] out value of counter
 * @return sec_counter_ret_status_t SEC_CNTR_OK on success
 */
sec_counter_ret_status_t sec_counter_incr(uint8_t counter_idx, uint16_t *out);

/**
 * @brief directly set counter value, only available if counters are enabled
 * @note returns SEC_CNTR_SET_FAILED if counters are enabled
 *
 * @param[in] counter_idx index of requested counter.
 * @param[in] value value to set counter to
 * @return sec_counter_ret_status_t SEC_CNTR_OK on success
 */
sec_counter_ret_status_t sec_counter_set(uint8_t counter_idx, uint16_t value);

#endif

/**
 * @brief NS-callable function of sec_counters_enabled
 */
bool nsc_sec_counters_enabled(void);

/**
 * @brief NS-callable function of sec_counter_read
 */
sec_counter_ret_status_t nsc_sec_counter_read(uint8_t counter_idx,
    uint16_t *out);

/**
 * @brief NS-callable function of sec_counter_incr
 */
sec_counter_ret_status_t nsc_sec_counter_incr(uint8_t counter_idx,
    uint16_t *out);

/**
 * @brief NS-callable function of sec_counter_set
 */
sec_counter_ret_status_t nsc_sec_counter_set(uint8_t counter_idx,
    uint16_t value);

#ifdef __cplusplus
}
#endif

/// @}
