/**
 ******************************************************************************
 *
 * @file radio_hal_burst.h
 *
 * @brief proprietary radio interface based on ATLC
 *
 * Copyright (C) Atmosic 2023-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#pragma once

#include "arch.h"
#include <stdint.h>
#include "at_lc.h"

/**
 * @defgroup RADIO_HAL_BURST RADIO_HAL_BURST
 * @ingroup DRIVERS
 * @brief Radio burst mode driver interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Maximum payload length */
#ifndef CFG_BURST_MAX_PAYLOAD_LENGTH
#define CFG_BURST_MAX_PAYLOAD_LENGTH 32
#endif
/* Max supported pipe number */
#define ATM_BURST_MAX_PIPE_NUM 8
/* Invalid rssi value */
#define ATM_BURST_INVALID_RSSI_VAL 127

/**
 * @brief Burst mode role
 */
typedef enum {
    ATM_MAC_BURST_ROLE_TX, /*!< TX role to tx pkt and rx ack */
    ATM_MAC_BURST_ROLE_RX /*!< RX role to rx pkt and tx ack */
} atm_mac_burst_role_t;

/**
 * @brief Radio phy rate
 */
typedef enum {
    ATM_MAC_BURST_BLE_1M, /*!< BLE 1M */
    ATM_MAC_BURST_BLE_2M, /*!< BLE 2M */
    ATM_MAC_BURST_BURST_1M, /*!< proprietary 1M */
    ATM_MAC_BURST_BURST_2M, /*!< proprietary 2M */
    ATM_MAC_BURST_PHY_NUM,
} atm_mac_burst_phy_t;

/**
 * @brief Packet CRC length
 */
typedef enum {
    ATM_MAC_BURST_1B_CRC, /*!< 1 byte CRC */
    ATM_MAC_BURST_2B_CRC /*!< 2 byte CRC */
} atm_mac_burst_crc_len_t;

/**
 * @brief Burst mode event type
 */
typedef enum {
    ATM_MAC_BURST_EVT_TX_SUCCESS, /*!< TX data success */
    ATM_MAC_BUTST_EVT_TX_FAILED, /*!< TX data failed */
    ATM_MAC_BUTST_EVT_RX_DATA, /*!< RX data success */
} atm_mac_burst_evt_type_t;

/**
 * @brief Burst packet format
 */
typedef enum {
    ATM_MAC_BURST_FIXED_PAYLOAD, /*!< Use fixed payload size */
    ATM_MAC_BURST_DYNAMIC_PAYLOAD, /*!< Use dynamic payload size */
} atm_mac_burst_pkt_format_t;

/**
 * @brief Burst mode command status
 */
typedef enum {
    ATM_MAC_BURST_SUCCESS, /*!< Success */
    ATM_MAC_BURST_BUSY, /*!< HW resource busy */
    ATM_MAC_BURST_TX_BUF_EMPTY, /*!< Buffer empty */
    ATM_MAC_BURST_RX_NO_DATA, /*!< No data to receive */
} atm_mac_burst_status_t;

/**
 * @brief Burst TX mode
 */
typedef enum {
    ATM_MAC_BURST_TX_MODE_AUTO, /*!< Auto start packet transmission */
    ATM_MAC_BURST_TX_MODE_MANUAL_START, /*!< Manually start transmission */
} atm_mac_burst_tx_mode_t;

/**
 * @brief Burst event context
 */
typedef struct {
    /// event type
    atm_mac_burst_evt_type_t evt_type;
    /// packet transmission times
    uint16_t tx_attempts;
} atm_mac_burst_evt_t;

/**
 * @brief Callback to report burst mode events
 * @Note The callback is called from interrupt context
 */
typedef void (*burst_evt_handler_t)(atm_mac_burst_evt_t const *evt);

/**
 * @brief Callback to report average rssi after energy detect is done
 * @Note The callback is called from interrupt context
 */
typedef void (*burst_energy_detect_handler_t)(int8_t avg_rssi);

/**
 * @brief Payload structure for Tx and Rx
 */
typedef struct {
    /// pipe to carry the payload
    uint8_t pipe_id;
    /// ACK is not required
    bool no_ack;
    /// data length
    uint8_t length;
    /// value of rssi received
    int8_t rssi;
    /// packet id received
    uint8_t pkt_id;
    /// 1B header before length. Only populated when header0_en is configured
    uint8_t hdr0;
    /// data payload
    uint8_t data[CFG_BURST_MAX_PAYLOAD_LENGTH];
} atm_mac_burst_payload_t;

/**
 * @brief Burst mode initialization parameters
 */
typedef struct {
    /// Event handler
    burst_evt_handler_t evt_handler;
    /// Retransmit delay (in unit micro second)
    uint16_t retransmit_delay;
    /// Retransmission count
    uint16_t retransmit_cnt;
    /// Burst mode role
    atm_mac_burst_role_t role;
    /// Burst mode radio phy
    atm_mac_burst_phy_t phy;
    /// CRC length used in the packet
    atm_mac_burst_crc_len_t crc;
    /// Burst mode packet format
    atm_mac_burst_pkt_format_t pkt_format;
    /// Tx mode of a TX role
    atm_mac_burst_tx_mode_t tx_mode;
    /// Maximum payload length
    uint8_t max_payload_len;
    /// Fixed payload length when ATM_MAC_BURST_FIXED_PAYLOAD packet format is
    /// used.
    uint8_t payload_len;
    /// Radio Tx power
    int8_t tx_power;
    /// Enable header0. When enabled, adds a 1-byte header before the length
    bool header0_en;
} atm_mac_burst_cfg_t;

/**
 *******************************************************************************
 * @brief Initialize burst mode.
 * @param[in] init_cfg burst mode initialization configuration.
 *******************************************************************************
 */
__NONNULL(1)
void atm_mac_burst_init(atm_mac_burst_cfg_t const *init_cfg);

/**
 *******************************************************************************
 * @brief Disable burst mode.
 *******************************************************************************
 */
void atm_mac_burst_disable(void);

/**
 *******************************************************************************
 * @brief Check if HW is in idle state.
 * @return TRUE if HW is in idle state.
 *******************************************************************************
 */
bool atm_mac_burst_is_idle(void);

/**
 *******************************************************************************
 * @brief Start to transmit burst mode packets for a TX role.
 *******************************************************************************
 */
void atm_mac_burst_start_tx(void);

/**
 *******************************************************************************
 * @brief Stop current tx operation.
 *******************************************************************************
 */
void atm_mac_burst_stop_tx(void);

/**
 *******************************************************************************
 * @brief Flush TX FIFO for a TX role.
 *******************************************************************************
 */
void atm_mac_burst_flush_tx(void);

/**
 *******************************************************************************
 * @brief Start to receive burst mode packets for a RX role.
 *******************************************************************************
 */
void atm_mac_burst_start_rx(void);

/**
 *******************************************************************************
 * @brief Stop current rx operation.
 *******************************************************************************
 */
void atm_mac_burst_stop_rx(void);

/**
 *******************************************************************************
 * @brief Write tx payload.
 * @param[in] payload the pointer of payload data to send.
 * @return command status.
 *******************************************************************************
 */
__NONNULL(1)
atm_mac_burst_status_t atm_mac_burst_write_tx_payload(
    atm_mac_burst_payload_t const *payload);

/**
 *******************************************************************************
 * @brief Get rx payload.
 * @param[in] payload the pointer of payload buffer to fill.
 * @return command status.
 * @Note should be called after receiving a ATM_MAC_BUTST_EVT_RX_DATA event
 *******************************************************************************
 */
__NONNULL(1)
atm_mac_burst_status_t atm_mac_burst_get_rx_payload(
    atm_mac_burst_payload_t *payload);

/**
 *******************************************************************************
 * @brief Set the length of address.
 * @param[in] length address length. (base_addr_len + 1 byte prefix, should be
 * in range of 3~5 bytes)
 *******************************************************************************
 */
void atm_mac_burst_set_addr_len(uint8_t length);

/**
 *******************************************************************************
 * @brief Set base address 0.
 * @param[in] addr value of base address 0. (4 bytes array)
 * @Note Append zero if base address is less than 4 bytes. For example, 3 bytes
 * address with 2 bytes base addr and 1 byte prefix, set base_addr =
 * [0x11, 0x22, 0x00, 0x00]
 *******************************************************************************
 */
__NONNULL(1)
void atm_mac_burst_set_base_addr_0(uint8_t const *addr);

/**
 *******************************************************************************
 * @brief Set base address 1.
 * @param[in] addr value of base address 1. (4 bytes array)
 * @Note Append zero if base address is less than 4 bytes. For example, 3 bytes
 * address with 2 bytes base addr and 1 byte prefix, set base_addr =
 * [0x11, 0x22, 0x00, 0x00]
 *******************************************************************************
 */
__NONNULL(1)
void atm_mac_burst_set_base_addr_1(uint8_t const *addr);

/**
 *******************************************************************************
 * @brief Set prefix address.
 * @param[in] prefix_list pointer of a prefix list.
 * @param[in] num_pipes number of burst pipe. (max num:8)
 *******************************************************************************
 */
__NONNULL(1)
void atm_mac_burst_set_prefixes(uint8_t const *prefix_list, uint8_t num_pipes);

/**
 *******************************************************************************
 * @brief Set radio channel.
 * @param[in] ch radio channel. (in range 0~99, 2400Mhz to 2499Mhz)
 *******************************************************************************
 */
void atm_mac_burst_set_rf_channel(uint32_t ch);

/**
 *******************************************************************************
 * @brief Set radio channel 2360Mhz.
 *******************************************************************************
 */
void atm_mac_burst_set_rf_channel_2360(void);

/**
 *******************************************************************************
 * @brief Set radio tx power.
 * @param[in] tx_power tx power in dbm.
 *******************************************************************************
 */
void atm_mac_burst_set_tx_power(int8_t tx_power);

/**
 *******************************************************************************
 * @brief Set retransmit delay for a TX role.
 * @param[in] delay retransmit delay.
 *******************************************************************************
 */
void atm_mac_burst_set_retransmit_delay(uint16_t delay);

/**
 *******************************************************************************
 * @brief Set retransmit count for a TX role.
 * @param[in] count number to retransmit.
 *******************************************************************************
 */
void atm_mac_burst_set_retransmit_count(uint8_t count);

/**
 *******************************************************************************
 * @brief Reuse the packet id for a TX role.
 * @param[in] pipe pipe id.
 *******************************************************************************
 */
void atm_mac_burst_reuse_pid(uint8_t pipe);

/**
 *******************************************************************************
 * @brief Perform engergy detection
 * @param[in] rx_timeout_us rx timeout in micro second.
 * @param[in] energy_detect_cb callback to report rssi after energy detect is
 * done.
 * @Note The callback reports the average RSSI value in 128us. If the timeout is
 * larger than 128us, it will pick the maximum average RSSI every 128us duration
 * . Prefer to set a timeout value which is the multiple of 128.
 *******************************************************************************
 */
__NONNULL(2)
void atm_mac_burst_energy_detect(uint32_t rx_timeout_us,
    burst_energy_detect_handler_t energy_detect_cb);

#ifdef __cplusplus
}
#endif

/// @}
