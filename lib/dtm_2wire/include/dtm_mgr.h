/**
 *******************************************************************************
 *
 * @file dtm_mgr.h
 *
 * @brief DTM manager interface definitions
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_DTM_MGR  DTM manager
 * @ingroup ATM_DTM
 * @brief  DTM manager interface
 * @{
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize DTM manager
 * @return 0 if successfully initialized
 */
int dtm_mgr_init(void);

/**
 * @brief Send DTM message from the manager
 * @param[IN] message message to send
 */
void dtm_mgr_send(uint16_t message);

/**
 * @brief process a 2-wire DTM message
 * @param[in] msg  message with command and options
 */
void dtm_process_message(uint16_t msg);

/**
 * @brief Callback function type for DTM TX power level changes.
 *
 * This callback is invoked whenever the DTM TX power level is set or updated
 * via the DTM_CTRL_SET_TX_PWR_LVL command. It allows applications to apply
 * platform-specific power configurations.
 *
 * @param[in] pwr_dbm TX power level in dBm that was just set.
 */
typedef void (*dtm_tx_pwr_callback_t)(int8_t pwr_dbm);

/**
 * @brief Register a callback for DTM TX power level changes.
 *
 * Allows an application to register a callback that will be invoked
 * whenever the DTM TX power level is set via DTM_CTRL_SET_TX_PWR_LVL.
 * Only one callback can be registered at a time.
 *
 * @param[in] callback Function to call when TX power is set, or NULL to unregister.
 */
void dtm_mgr_register_tx_pwr_callback(dtm_tx_pwr_callback_t callback);

#ifdef __cplusplus
}
#endif

/// @} ATM_DTM
