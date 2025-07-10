/**
 *******************************************************************************
 *
 * @file atm_vendor_api.h
 *
 * @brief Atmosic Vendor API Command Core
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */
#pragma once

/**
 * @defgroup ATM_BTFM_VEND_API HCI Vendor API
 * @ingroup ATM_BTFM_PROC
 * @brief HCI Vendor API
 *
 * This module contains the necessary API to deal with vendor command.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define TX_POWER_10_DBM 10
#define TX_POWER_8_DBM 8
#define TX_POWER_6_DBM 6
#define TX_POWER_4_DBM 4
#define TX_POWER_2_DBM 2
#define TX_POWER_0_DBM 0
#define TX_POWER_MINUS_2_DBM -2
#define TX_POWER_MINUS_4_DBM -4
#define TX_POWER_MINUS_6_DBM -6
#define TX_POWER_MINUS_8_DBM -8
#define TX_POWER_MINUS_10_DBM -10
#define TX_POWER_MINUS_20_DBM -20

enum {
	TX_POWER_VALUE_ADJUST_SUCCESS,
	TX_POWER_VALUE_ADJUST_FAIL,
};

#ifdef CFG_VND_API_SET_PREF_SLAVE_LAT
/**
 * @brief Set Prefer Slave Latency
 *
 * @param conhdl Connection Handle
 * @param latency Prefer slave latency value
 *
 * @return the status of set prefer slave latency
 */
int atm_vendor_set_pref_slave_lat(uint16_t conhdl, uint16_t latency);
#endif

#ifdef CFG_VND_API_SET_MAX_TX_POWER
/**
 * @brief Set Maximum TX power
 *
 * @note The RF driver will select the closest available value as the new TX
 * power. The supported TX power levels are: -20, -10, -8, -4, -2, 0, 2, 4, 6,
 * 8, and 10 dBm.
 *
 * @param tx_pwr transmitter power in dBm
 *
 * @return 0 on success, non-zero on failure.
 */
uint8_t atm_vendor_set_max_tx_power(int8_t tx_pwr);
#endif

#ifdef CFG_VND_API_SET_ADV_TX_POWER
/**
 * @brief Set Advertising Transmitter Power
 *
 * @note The RF driver will select the closest available value as the new TX
 * power. The supported TX power levels are: -20, -10, -8, -4, -2, 0, 2, 4, 6,
 * 8, and 10 dBm.
 *
 * @param tx_pwr Transmitter Power
 *
 * @return 0 on success, non-zero on failure.
 */
uint8_t atm_vendor_set_adv_tx_power(int8_t tx_pwr);
#endif

#ifdef CFG_VND_API_SET_CON_TX_POWER
/**
 * @brief Set Connection Transmitter Power
 *
 * @note The RF driver will select the closest available value as the new TX
 * power. The supported TX power levels are: -20, -10, -8, -4, -2, 0, 2, 4, 6,
 * 8, and 10 dBm.
 *
 * @param conhdl Connection Handle
 * @param tx_pwr Transmitter Power
 *
 * @return 0 on success, non-zero on failure.
 */
uint8_t atm_vendor_set_con_tx_power(uint16_t conhdl, int8_t tx_pwr);
#endif

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
