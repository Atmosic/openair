/**
 *******************************************************************************
 *
 * @file radio_status.h
 *
 * @brief Unified header for all Atmosic radio statuses
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_STATUS RADIO_STATUS
 * @ingroup DRIVERS
 * @brief Radio status enum module
 *
 * This module has a collection of all possible radio statuses. Any radio
 * function that can error will return an enum of this type.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Radio status
 */
typedef enum {
    ATM_MAC_STATUS_SUCCESS, /*!< Success */
    ATM_MAC_154_RX_COMPLETE_STATUS_SUCCESS = ATM_MAC_STATUS_SUCCESS,
    ATM_MAC_154_TX_COMPLETE_STATUS_SUCCESS = ATM_MAC_STATUS_SUCCESS,
    ATM_MAC_MGR_STATUS_SUCCESS = ATM_MAC_STATUS_SUCCESS,
    ATM_MAC_154_RX_COMPLETE_STATUS_FAIL, /*!< 802.15.4 RX general failure */
    ATM_MAC_154_RX_COMPLETE_STATUS_FAIL_TIMEOUT, /*!< 802.15.4 RX timed out */
    ATM_MAC_154_RX_COMPLETE_STATUS_FAIL_PAST, /*!< Event scheduled in past */
    ATM_MAC_154_RX_COMPLETE_STATUS_STOPPED, /*!< RX forced to stop */
    ATM_MAC_154_TX_COMPLETE_STATUS_FAIL, /*!< 802.15.4 TX general failure */
    ATM_MAC_154_TX_COMPLETE_STATUS_FAIL_CCA, /*!< All CCA attempts failed */
    ATM_MAC_154_TX_COMPLETE_STATUS_FAIL_NO_ACK, /*!< All retries failed */
    ATM_MAC_154_TX_COMPLETE_STATUS_FAIL_PAST, /*!< Event scheduled in past */
    ATM_MAC_UMAC_TRANSMIT_ONGOING, /*!< Not possible during another transmit */
    ATM_MAC_MGR_STATUS_ERROR, /*!< Unspecified error */
    ATM_MAC_MGR_STATUS_ABORT, /*!< Operation aborted based on priority */
    ATM_MAC_MGR_STATUS_PAST, /*!< Operation was attempted too late */
    ATM_MAC_MGR_STATUS_BUSY, /*!< Operation not scheduled */
    ATM_MAC_STATUS_NUM
} atm_mac_status_t;

typedef atm_mac_status_t atm_mac_154_tx_complete_status_t;
typedef atm_mac_status_t atm_mac_154_rx_complete_status_t;
typedef atm_mac_status_t atm_mac_mgr_status_t;

/**
 * @brief 15.4 address filtering result
 */
typedef enum {
    ATM_MAC_154_FILTER_PASS = 0, /*!< Passed */
    ATM_MAC_154_FILTER_DATA, /*!< Not enough data in header */
    ATM_MAC_154_FILTER_INVALID, /*!< Invalid dest/source address mode */
    ATM_MAC_154_FILTER_2003_SECURITY, /*!< Security with 2003 frame version */
    ATM_MAC_154_FILTER_DEST_LONG_ADDR, /*!< Dest long address no match */
    ATM_MAC_154_FILTER_DEST_SHORT_ADDR, /*!< Dest short address not match */
    ATM_MAC_154_FILTER_DEST_PAN, /*!< Dest PAN ID no match */
    ATM_MAC_154_FILTER_BEACON, /*!< Beacon type frame without a PAN ID match */
    ATM_MAC_154_FILTER_COORD_ONLY, /*!< Coordinator only packet mismatch */
    ATM_MAC_154_FILTER_NUM
} atm_mac_154_filter_result_t;

#ifdef __cplusplus
}
#endif

/// @} RADIO_STATUS
