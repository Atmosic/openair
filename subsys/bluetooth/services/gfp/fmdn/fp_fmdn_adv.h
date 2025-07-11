/**
 *******************************************************************************
 *
 * @file fp_fmdn_adv.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Advertisement Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Find My Device Network Extention
 * @brief Advertisement Middleware of Google Fast Pair Find My Device Network
 * Extention
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief FP FMDN adv recreate
 *
 * @param [in] force_stop forcely stop before start
 * @param [in] stop_only stop only do not start
 */
void fp_fmdn_adv_recreate(bool force_stop, bool stop_only);

#ifdef __cplusplus
}
#endif

///@}
