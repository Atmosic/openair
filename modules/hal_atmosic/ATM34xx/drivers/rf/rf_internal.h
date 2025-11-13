/**
 *******************************************************************************
 *
 * @file rf_internal.h
 *
 * @brief Radio Initialization and specific functions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <stdint.h>


#ifndef RF_INTERNAL_GUARD
#error "rf_internal.h should only be included in rf source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

atm_txpwr_ovr_key rf_core_set_txpwr_override(uint8_t gain_index);
void rf_core_restore_txpwr_override(atm_txpwr_ovr_key key);

#ifdef __cplusplus
}
#endif

