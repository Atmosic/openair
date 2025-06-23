/**
 *******************************************************************************
 *
 * @file rf_api.h
 *
 * @brief Radio related api
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#define INVALID_TX_POWER_VALUE 0xFF

/**
 * @brief Set the maximum tx power for all of the rf activities.
 * @param[in] txpwr_dbm Tx power in dbm.
 * @return Tx power in dbm.
 */
int8_t rf_set_txpwr_maximum_val(int8_t txpwr_dbm);

/**
 * @brief Set the advertising tx power.
 * @param[in] txpwr_dbm Tx power in dbm.
 * @return True on success.
 */
bool rf_set_txpwr_advertising_val(int8_t txpwr_dbm);

#ifndef CONFIG_SOC_FAMILY_ATM
/**
 * @brief Get the advertising tx power.
 * @return Tx power in dbm.
 */
int rf_get_txpwr_advertising_val(void);
#endif

/**
 * @brief Override tx_power index value from LC.
 * @param[in] txpwr_dbm Tx power in dbm.
 */
void rf_set_txpwr_override(int8_t txpwr_dbm);

/**
 * @brief Set the tx power for the cs idx.
 * @param[in] conhdl connection handle.
 * @param[in] txpwr_dbm Tx power in dbm.
 * @return Tx power in dbm.
 */
int8_t rf_set_cs_txpwr_val(uint16_t conhdl, int8_t txpwr_dbm);
