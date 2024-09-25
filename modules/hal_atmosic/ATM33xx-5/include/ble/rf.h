/**
 ****************************************************************************************
 *
 * @file rf.h
 *
 * @brief Common header file for all radios.
 *
 * Copyright (C) RivieraWaves 2009-2024
 * Release Identifier: dc6acdca
 *
 *
 ****************************************************************************************
 */

#ifndef RF_H_
#define RF_H_

/**
 ****************************************************************************************
 * @addtogroup RF
 * @ingroup DRIVERS
 * @brief Common definitions for radio modules.
 *
 * This module declares the functions and constants that have to be defined for all RF.
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#if defined(CFG_RF_AU50XX)
#include "rf_au50xx.h"
#elif defined(CFG_CAL_HPMDM_BYPASS)
#include "rf_cal_hpmdm_bypass.h"
#elif defined(CFG_CAL_HPMDM_BYPASS_CHSD)
#include "rf_cal_hpmdm_bypass_chsd.h"
#elif defined(CFG_RF_EXTRC_HPMDM)
#include "rf_extrc_hpmdm.h"
#elif defined(CFG_RF_EXTRC)
#include "rf_extrc.h"
#elif defined(CFG_ICYTRX_V2)
#include "rf_icytrx_v2.h"
#elif defined(CFG_RF_ICYTRXDM)
#include "rf_icytrxdm.h"
#elif defined(CFG_RF_PARIS)
#include "rf_paris.h"
#elif defined(CFG_RF_RIPPLE)
#include "rf_ripple.h"
#else
#error unrecognized radio driver
#endif

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

struct rwip_rf_api;  // forward declaration to avoid including rw.h

/**
 *****************************************************************************************
 * @brief Initialization of RF.
 *
 * This function initializes the RF and fills the structure containing the function
 * pointers and parameters required by the RW BT stack.
 *
 * @param[out]  api  Pointer to the BT RF API structure
 *
 *****************************************************************************************
 */
void rf_init(struct rwip_rf_api *api);

/// @} RF

#endif // RF_H_
