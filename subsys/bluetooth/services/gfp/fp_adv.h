/**
 *******************************************************************************
 *
 * @file fp_adv.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Advertisement Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/addr.h>
#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Advertisement Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief fp adv recreate with fp mode
 */
void fp_adv_recreate(void);

#ifdef __cplusplus
}
#endif

///@}
