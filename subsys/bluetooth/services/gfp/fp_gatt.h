/**
 *******************************************************************************
 *
 * @file fp_gatt.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Gatt Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Gatt Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief FP gatt init
 */
void fp_gatt_init(void);

/**
 * @brief FP gatt deinit
 */
void fp_gatt_deinit(void);

#ifdef __cplusplus
}
#endif

///@}
