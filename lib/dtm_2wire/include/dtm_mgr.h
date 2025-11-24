/**
 *******************************************************************************
 *
 * @file dtm_mgr.h
 *
 * @brief DTM manager interface definitions
 *
 * Copyright (C) Atmosic 2025
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

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize DTM manager
 * @return 0 if successfully initialized
 */
int dtm_mgr_init(void);

#ifdef __cplusplus
}
#endif

/// @} ATM_DTM
