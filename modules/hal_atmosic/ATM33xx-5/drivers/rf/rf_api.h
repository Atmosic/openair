/**
 *******************************************************************************
 *
 * @file rf_api.h
 *
 * @brief Radio related api
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h"
#include <stdbool.h>
#include <stdint.h>

/// Set advertising channel 37 enable
#define RF_ADV_CH_37 0x1
/// Set advertising channel 38 enable
#define RF_ADV_CH_38 0x2
/// Set advertising channel 39 enable
#define RF_ADV_CH_39 0x4

/**
 *******************************************************************************
 * @brief Set the maximum tx power for all of the rf activities.
 * @param[in] txpwr_dbm Tx power in dbm.
 * @return Tx power in dbm.
 *******************************************************************************
 */
int8_t rf_set_txpwr_maximum_val(int8_t txpwr_dbm);

/**
 *******************************************************************************
 * @brief Override tx_power index value from LC.
 * @param[in] txpwr_dbm Tx power in dbm.
 *******************************************************************************
 */
void rf_set_txpwr_override(int8_t txpwr_dbm);

/**
 *******************************************************************************
 * @brief Set the tx power for the cs idx.
 * @param[in] cs_idx control structure index.
 * @param[in] txpwr_dbm Tx power in dbm.
 * @return Tx power in dbm.
 *******************************************************************************
 */
int8_t rf_set_cs_txpwr_val(uint8_t cs_idx, int8_t txpwr_dbm);

/**
 *******************************************************************************
 * @brief Set the offset of the given advertising channel(s)
 * @param[in] mask advertising channel mask
 * @param[in] offset_mhz frequency offset from 2400 MHz
 *******************************************************************************
 */
void rf_set_adv_channel(uint8_t mask, uint8_t offset_mhz);

/**
 *******************************************************************************
 * @brief Initialize the RF channel offsets
 *******************************************************************************
 */
void rf_reset_ch_offsets(void);

/**
 *******************************************************************************
 * @brief Set External PA receive control pins
 * @param[in] pin The receive pin
 * @return false: invalid pin argument
 *******************************************************************************
 */
bool rf_set_pin_xparx(uint8_t pin);
