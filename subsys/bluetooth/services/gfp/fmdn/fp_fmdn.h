/**
 *******************************************************************************
 *
 * @file fp_fmdn.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Middleware
 *
 * Copyright (C) Atmosic 2025
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

#ifdef __cplusplus
}
#endif

///@}
