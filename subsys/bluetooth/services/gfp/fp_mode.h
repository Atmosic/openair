/**
 *******************************************************************************
 *
 * @file fp_mode.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Mode Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Mode Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief FP mode init
 */
void fp_mode_init(void);

/**
 * @brief fp get current fp mode
 *
 * @return current fp mode
 */
fp_mode_t fp_mode_get(void);

/**
 * @brief fp update current fp mode
 * @param[in] mode fp mode
 */
void fp_mode_update(fp_mode_t mode);

/**
 * @brief fp current fp mode is provisioned
 *
 * @return true if current fp mode is provisioned
 */
bool fp_mode_is_provisioned(void);

/**
 * @brief fp current fp mode is paired
 *
 * @return true if current fp mode is paired
 */
bool fp_mode_is_paired(void);

/**
 * @brief fp current fp mode is pairing
 *
 * @return true if current fp mode is pairing
 */
bool fp_mode_is_pairing(void);

/**
 * @brief The callback function of mode switch notify
 * @param[in] mode fast paring mode
 */
typedef void (*fp_mode_switch_cb)(fp_mode_t mode);

/**
 * @brief gfps fp mode switch handler register
 * @param[in] hdlr fp mode switch handler structure
 */
__NONNULL_ALL
void fp_mode_switch_reg(fp_mode_switch_cb const hdlr);

/**
 * @brief fp current fp mode rap timeout calculate
 *
 * @return rap timeout
 */
uint16_t fp_mode_rpa_timeout(void);

#ifdef __cplusplus
}
#endif

///@}
