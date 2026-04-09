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

#ifdef __cplusplus
}
#endif

/// @} ATM_DTM
