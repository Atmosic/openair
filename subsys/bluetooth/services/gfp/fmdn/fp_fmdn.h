/**
 *******************************************************************************
 *
 * @file fp_fmdn.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @defgroup ATM_BTFMDN Google Fast Pair Find My Device Network Extention
 * @brief Gatt Service of Google Fast Pair Find My Device Network Extention
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief FP FMDN is utp enabled
 *
 * @return true if enabled
 */
bool fp_fmdn_is_utp_en(void);

/**
 * @brief Set FMDN clock to a specific value at startup
 *
 * Pre-initializes the FMDN clock so the provided value is already in effect
 * when the FMDN service starts. Must be called before atm_gfp_init().
 *
 * @param[in] clock_value FMDN clock value in seconds to apply
 */
void fp_fmdn_clock_set(uint32_t clock_value);

/**
 * @brief Get the current FMDN clock value
 *
 * @return current FMDN clock value in seconds
 */
uint32_t fp_fmdn_clock_get(void);

/**
 * @brief FP FMDN clock save to NVM
 *
 * @return 0 if successful, otherwise a (negative) error code is returned
 */
int fp_fmdn_clock_save(void);

/**
 * @brief FP FMDN clock reset to 0
 *
 * Resets the FMDN clock value to 0 and deletes it from NVM.
 * This should be called during factory reset so new provisioning
 * can start with clock value of 0.
 */
void fp_fmdn_clock_reset(void);

#ifdef __cplusplus
}
#endif

///@}
