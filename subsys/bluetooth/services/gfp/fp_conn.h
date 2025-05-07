/**
 *******************************************************************************
 *
 * @file fp_conn.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Connection Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Connection Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief FP conn init
 */
void fp_conn_init(void);

/**
 * @brief fp conn disconnect all
 */
void fp_conn_disconnect_all(void);

/**
 * @brief fp conn validate for ap
 * @param[in] conn bluetooth conn pointer
 */
bool fp_conn_validate(struct bt_conn *conn);

#ifdef __cplusplus
}
#endif

///@}
