/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file fp_fmdn_adv.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Advertisement Middleware
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

#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
/**
 * @brief PC state-change listener for the FMDN adv set.
 *
 * Caches PC adv params and triggers an adv recreate on the app work queue.
 *
 * @param is_active  true if a persistent connection is now active.
 * @param conn_type  New connection type (3 LSBs meaningful).
 */
void fp_fmdn_adv_pc_state_cb(bool is_active, uint8_t conn_type);
#endif

/**
 * @brief Get the current advertising address from the FMDN advertising set
 *
 * Returns the live address the controller is advertising with (RPA when
 * privacy is active, identity address otherwise).
 *
 * @param[out] addr Pointer to receive the current advertising address
 * @return 0 on success, -ENODEV if the advertising set has not been created
 *         yet, or another negative errno forwarded from bt_le_ext_adv_get_info()
 */
__NONNULL_ALL
int fp_fmdn_adv_get_adv_set_addr(bt_addr_le_t *addr);

#ifdef __cplusplus
}
#endif

///@}
