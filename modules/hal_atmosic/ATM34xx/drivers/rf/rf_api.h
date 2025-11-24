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

typedef uint32_t atm_txpwr_ovr_key;

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
 * @return opaque value to be used during restore operation
 */
atm_txpwr_ovr_key rf_set_txpwr_override(int8_t txpwr_dbm);

/**
 *******************************************************************************
 * @brief Restore tx_power override settings
 * @param[in] key opaque value obtained from rf_set_txpwr_override API
 *******************************************************************************
 */
void rf_restore_txpwr_override(atm_txpwr_ovr_key key);

/**
 * @brief Set the tx power for the cs idx.
 * @param[in] conhdl connection handle.
 * @param[in] txpwr_dbm Tx power in dbm.
 * @return Tx power in dbm.
 */
int8_t rf_set_cs_txpwr_val(uint16_t conhdl, int8_t txpwr_dbm);
