/**
 ******************************************************************************
 *
 * @file rf_internal.h
 *
 * @brief Radio internal APIs
 *
 * Copyright (C) Atmosic 2024
 *
 ******************************************************************************
 */

#pragma once

#ifndef RF_INTERNAL_GUARD
#error "rf_internal.h should only be included in rf source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum {
    RF_POWER_MINUS_20_DBM,
    RF_POWER_MINUS_10_DBM,
    RF_POWER_MINUS_8_DBM,
    RF_POWER_MINUS_6_DBM,
    RF_POWER_MINUS_4_DBM,
    RF_POWER_MINUS_2_DBM,
    RF_POWER_0_DBM,
    RF_POWER_2_DBM,
    RF_POWER_4_DBM,
    RF_POWER_6_DBM,
    RF_POWER_8_DBM,
    RF_POWER_10_DBM,
    RF_POWER_LVL_NUM
};

void rf_core_set_txpwr_override(uint8_t gain_index);
void rf_enable_whitening(uint8_t seed);
void rf_core_reset_ch_offsets(void);
bool rf_core_set_pin_xparx(uint8_t pin);

#ifdef __cplusplus
}
#endif
