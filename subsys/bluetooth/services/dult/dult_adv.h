/**
 *******************************************************************************
 *
 * @file dult_adv.h
 *
 * @brief Atmosic Detecting Unwanted Location Trackers (DULT) advertisement
 * Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @addtogroup ATM_BTDULTS Detecting Unwanted Location Trackers Service
 * @brief advertisement Middleware of Detecting Unwanted Location Trackers
 * Service
 *
 * @{
 */

#include "dult_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief dult adv enable with near owner mode
 * @param[in] mode dult mode
 */
void dult_adv_enable(dult_mode_t mode);

/**
 * @brief dult adv disable
 */
void dult_adv_disable(void);

/**
 * @brief dult adv bt id
 * @param[in] bt_id dult bt_id
 */
void dult_adv_bt_id_set(uint8_t bt_id);

#ifdef __cplusplus
}
#endif

///@}
