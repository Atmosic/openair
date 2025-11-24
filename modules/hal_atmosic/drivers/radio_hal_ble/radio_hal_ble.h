/**
 ******************************************************************************
 *
 * @file radio_hal_ble.h
 *
 * @brief Radio init, config, medium access.
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#pragma once

#include "arch.h"
#include "at_lc.h"
#include "at_lc_regs_core_macro.h"
#include "radio_hal_common.h"
#include "radio_status.h"

/**
 * @defgroup RADIO_HAL RADIO_HAL
 * @ingroup DRIVERS
 * @brief Radio driver interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

// BLE-specific configuration
#define NUM_SYNC_BYTES 4
#define NUM_ADDR_BYTES 0
#define NUM_CRC_BYTES 3
#define BLE_CRC_POLYNOMIAL 0x0000065b
#define BLE_LEN_BYTE_INDEX 1
#define BLE_SK_LEN_IN_BYTE 16

#define MIN_RX_WR_PTR 2
#define BLE_HEADER_LEN 2

#define ATLC_RX_INBAND_STATUS_WIDTH 2
#define ATLC_RX_FIFO_RSSI_REV_INDEX 2
#define ATLC_RX_FIFO_STATUS_REV_INDEX 1

#define BLE_TX_DESCRIPTOR_SIZE 8

#define BLE_UNCODED_PHY_1MBPS_ACCESS_ADDRESS_DURATION_US 32
#define BLE_UNCODED_PHY_1MBPS_PREAMBLE_DURATION_US 8
#define BLE_UNCODED_PHY_1MBPS_BYTE_DURATION_US 8
#define BLE_UNCODED_PHY_2MBPS_ACCESS_ADDRESS_DURATION_US 16
#define BLE_UNCODED_PHY_2MBPS_PREAMBLE_DURATION_US 8
#define BLE_UNCODED_PHY_2MBPS_BYTE_DURATION_US 4
#define BLE_CODED_PHY_FEC_BLOCK_1_DURATION_US 296
#define BLE_CODED_PHY_PREAMBLE_DURATION_US 80
#define BLE_CODED_PHY_500KBPS_BYTE_DURATION_US 16
#define BLE_CODED_PHY_125KBPS_BYTE_DURATION_US 64

// ATLC Appended Rx Status
#define APPENDED_STATUS_CRC_BIT_MASK 0x01
#define APPENDED_STATUS_MIC_BIT_MASK 0x08
#define APPENDED_STATUS_RX_PHY_MASK 0x30
#define APPENDED_STATUS_RX_PHY_POS 4

typedef enum {
    ATM_MAC_BLE_STATE_UNINIT = 0,
    ATM_MAC_BLE_STATE_ERROR,
    ATM_MAC_BLE_STATE_SLEEP,
    ATM_MAC_BLE_STATE_IDLE,
    ATM_MAC_BLE_STATE_TX,
    ATM_MAC_BLE_STATE_RX,
    ATM_MAC_BLE_STATE_DIAG
} atm_mac_ble_state_t;

typedef enum {
    ATM_MAC_BLE_PHY_1M = AT_LC_PRTCL_BLE_1M,
    ATM_MAC_BLE_PHY_2M = AT_LC_PRTCL_BLE_2M,
    ATM_MAC_BLE_PHY_CODED_S2 = AT_LC_PRTCL_BLE_500K,
    ATM_MAC_BLE_PHY_CODED_S8 = AT_LC_PRTCL_BLE_125K,
} atm_mac_ble_phy_t;

typedef struct {
    uint8_t byte0;
    uint8_t len;
} __PACKED ble_pdu_hdr_type;

typedef struct {
    ble_pdu_hdr_type hdr;
    uint8_t payload[];
} __PACKED ble_pdu_type;

typedef enum {
    ATM_MAC_BLE_PAYLOAD_TX_BUFFER,
    ATM_MAC_BLE_PAYLOAD_PRBS9,
    ATM_MAC_BLE_PAYLOAD_PRBS15,
    ATM_MAC_BLE_PAYLOAD_FORCED,
} atm_mac_ble_payload_type_t;

/**
 * @brief Type for BLE TX complete callback.
 *
 * @param[in] status TX completion status
 */
typedef void (*atm_mac_ble_tx_cpl_cb)(atm_mac_status_t status);

/**
 * @brief Type for BLE RX complete callback.
 *
 * @param[in] status RX completion status
 * @param[in] start_offset Offset between start bit and due time of RX packet
 * @param[in] rssi RSSI of RX packet
 */
typedef void (*atm_mac_ble_rx_cpl_cb)(atm_mac_status_t status,
    uint32_t start_offset, int8_t rssi);

/** BLE TX complete callback */
extern atm_mac_ble_tx_cpl_cb atm_mac_ble_tx_complete_callback;

/** BLE RX complete callback */
extern atm_mac_ble_rx_cpl_cb atm_mac_ble_rx_complete_callback;

// Initialization
void atm_mac_ble_init(void);
void atm_mac_ble_ldo_init(void);
void atm_mac_ble_deinit(void);
void atm_mac_ble_enable(void);

// Control and Status
atm_mac_ble_state_t atm_mac_ble_get_state(void);
void atm_mac_ble_set_state(atm_mac_ble_state_t state);
void atm_mac_ble_set_access_address(uint32_t addr);
void atm_mac_ble_set_crc_init(uint32_t crc_init);
void atm_mac_ble_set_channel(uint8_t channel);
void atm_mac_ble_set_tx_power(int8_t power_level);
int8_t atm_mac_ble_get_tx_power(void);

/**
 * @brief Get BLE Tx phy
 *
 * @return Currently configured BLE phy
 */
atm_mac_ble_phy_t atm_mac_ble_get_phy(void);

/**
 * @brief Set BLE Tx phy
 *
 * @param[in] atm_tx_phy value of ble phy
 */
void atm_mac_ble_set_tx_phy(atm_mac_ble_phy_t atm_tx_phy);

/**
 * @brief Set BLE Rx phy
 *
 * @param[in] atm_rx_phy value of ble phy
 */
void atm_mac_ble_set_rx_phy(atm_mac_ble_phy_t atm_rx_phy);

/**
 * @brief Enable/Disable ble data whitening
 *
 * @param[in] ena true/false for enable/disable ble data whitening
 */
void atm_mac_ble_set_data_whitening(bool ena);

/**
 * @brief Set Tx test settings
 *
 * @param[in] continuous_tx transmitting an endless packet
 * @param[in] type payload type for transmitting
 * @param[in] forced_hdr fixed header value (type=ATM_BLE_PAYLOAD_FORCED)
 * @param[in] forced_bytes fixed payload value (type=ATM_BLE_PAYLOAD_FORCED)
 */
void atm_mac_ble_tx_test_settings(bool continuous_tx,
    atm_mac_ble_payload_type_t type, uint16_t forced_hdr, uint8_t forced_bytes);

// Data Transfer - tx
void atm_mac_ble_sched_tx_at_absolute_time(uint32_t time);
void atm_mac_ble_sched_tx_at_offset_from_prior_end_time(uint16_t offset);
void atm_mac_ble_sched_tx_at_offset_from_prior_absolute_time(uint32_t offset);
__NONNULL(1)
void atm_mac_ble_tx_scheduled_packet(uint8_t const *packet, uint16_t length);

// Data Transfer - rx
void atm_mac_ble_sched_rx_at_absolute_time(uint32_t time, uint32_t timeout);
void atm_mac_ble_sched_rx_at_offset_from_prior_end_time(uint16_t offset,
    uint32_t timeout);
void atm_mac_ble_sched_rx_at_offset_from_prior_absolute_time(uint32_t offset,
    uint32_t timeout);
void atm_mac_ble_rx_scheduled_packet(uint8_t *packet, uint16_t length);

// Misc
void atm_mac_ble_stop(void);
uint32_t atm_mac_ble_get_start_bit_time(void);
uint32_t atm_mac_ble_get_end_bit_time(void);
uint32_t atm_mac_ble_get_last_due_time(void);

/**
 * @brief Enable or disable ble ll encryption engine
 *
 * @param[in] enable true/false for enable/disable ble ll encryption engine
 */
void atm_mac_ble_enc_enable(bool enable);

/**
 * @brief Set the initial vector of ble ll encryption
 *
 * @param[in] iv the address of the initial vector
 */
__NONNULL(1)
void atm_mac_ble_set_iv(uint8_t const *iv);

/**
 * @brief Set the session key of ble ll encryption
 *
 * @param[in] sk the address of the session key
 */
__NONNULL(1)
void atm_mac_ble_set_session_key(uint8_t const *sk);

/**
 * @brief Set the direction bit of ble ll encryption
 *
 * @param[in] dir the value of the direction bit, true for 1 and false for 0
 *                defined in Vol6,PartE,2.1 of core spec ver 5.3
 */
void atm_mac_ble_set_enc_dir(bool dir);

/**
 * @brief Set the packet counter of ble ll encryption
 *
 * @param[in] cntr the value of the packet counter
 */
void atm_mac_ble_set_enc_pkt_cntr(uint64_t cntr);

/**
 * @brief Get currently rx packet phy information.
 *
 * @return current rx pkt phy information
 */
atm_mac_ble_phy_t atm_mac_ble_get_curr_rx_pkt_phy(void);

/**
 * @brief register ble tx complete callback.
 *
 * @param[in] tx_cpl_cb tx complete callback
 */
__NONNULL(1)
void atm_mac_ble_register_tx_cpl_cb(atm_mac_ble_tx_cpl_cb tx_cpl_cb);

/**
 * @brief register ble rx complete callback.
 *
 * @param[in] rx_cpl_cb rx complete callback
 */
__NONNULL(1)
void atm_mac_ble_register_rx_cpl_cb(atm_mac_ble_rx_cpl_cb rx_cpl_cb);

/**
 * @brief Register ble cs callback.
 *
 * @param[in] cs_cb cs callback. NULL to restore normal BLE callback
 */
void atm_mac_ble_register_cs_cb(atm_mac_irq_handler_t cs_cb);

/**
 * @brief Set the cmd_err_status of the ATLC
 *
 * @param[in] status the value of the cmd_err_status
 */
void atm_mac_ble_set_cmd_err_status(ATLC_LC_IRQ__TYPE status);

/**
 * @brief Weak function which will be called when platform supports
 * the channel sounding feature
 *
 * @param[in] enable ldo enable
 */
__attribute__((weak)) void atm_mac_ble_ldo_enable(bool enable);

/**
 * @brief Weak function to enable LDO mode for CS
 *
 * @param[in] enable enable LDO mode
 */
__attribute__((weak)) void atm_mac_ble_enable_cs_ldo(bool enable);

/**
 * @brief Whether to enable antenna switching
 *
 * return True if feature should be enabled
 */
bool atm_mac_ble_antenna_switching_by_id(void);
#ifdef __cplusplus
}
#endif

/// @}
