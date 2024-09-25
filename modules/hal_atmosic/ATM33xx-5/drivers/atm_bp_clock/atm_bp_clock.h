/**
 *******************************************************************************
 *
 * @file atm_bp_clock.h
 *
 * @brief Wrapper for backplane clock related functions
 *
 * Copyright (C) Atmosic 2023
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_BP_CLOCK Atmosic BP clock wrapper
 * @ingroup DRIVERS
 * @brief Wrapper for bp clocking related functions for use where inlines are
 * not needed.
 * @{
 */

#include "arch.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CFG_ATM_BP_CLOCK_DEBUG
#define ATM_BP_CLOCK_DEBUG 1
#else
#define ATM_BP_CLOCK_DEBUG 0
#endif

#define ATM_BP_CLOCK_ENTER_CRITICAL_SECTION(_bp_freq) \
    do { \
	uint32_t bp_saved = atm_bp_clock_get(); \
	if (bp_saved > _bp_freq) { \
	    DEBUG_TRACE_COND(ATM_BP_CLOCK_DEBUG, "BP adjust from: %" PRIu32, \
		bp_saved); \
	    __disable_irq(); \
	    atm_bp_clock_set(_bp_freq); \
	} else { \
	    bp_saved = 0; \
	}

#define ATM_BP_CLOCK_LEAVE_CRITICAL_SECTION() \
	if (bp_saved) { \
	    DEBUG_TRACE_COND(ATM_BP_CLOCK_DEBUG, "BP restore to: %" PRIu32, \
		bp_saved); \
	    atm_bp_clock_set(bp_saved); \
	    __enable_irq(); \
	} \
    } while (0)

#define ATM_BP_XTAL_FREQ 16000000U

/**
 * @brief Get current backplane frequency
 *
 * @return current frequency in hertz
 */
uint32_t atm_bp_clock_get(void);

#if PLF_DEBUG
/**
 * @brief Get maximal backplane frequency
 *
 * @return current frequency in hertz
 */
uint32_t atm_bp_clock_max_get(void);
#endif

/**
 * @brief Set the backplane clock
 *
 * @param[in] freq Frequency in hertz
 */
void atm_bp_clock_set(uint32_t freq);

/**
 * @brief Set the backplane clock
 *
 * @param[in] freq Frequency in hertz
 * @param[in] set true to set clock change
 * @param[in] commit true to commit clock change
 */
void atm_bp_clock_set_hint(uint32_t freq, bool set, bool commit);

/**
 * @brief Check if bp clock can be lowered safely
 *
 * @param[in] freq desired frequency for backplane clock
 *
 * @return true if lowering bp clock can be enabled safely
 */
bool atm_bp_clock_critical_section_allowed(uint32_t freq);
#ifdef __cplusplus
}
#endif

/// @}
