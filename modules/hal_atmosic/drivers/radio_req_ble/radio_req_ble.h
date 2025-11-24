/**
 *******************************************************************************
 *
 * @file radio_req_ble.h
 *
 * @brief BLE Radio Request Handler
 *
 * This driver handles request for BLE radio operations. It will coordinate
 * with the Radio Manager and the BLE HAL to ensure that operations occur when
 * possible, and will return an error when that is not possible. When calling
 * the BLE Request Driver, all calls should go here, and no calls should go
 * directly to the BLE HAL directly.
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_REQ_BLE RADIO_REQ_BLE
 * @ingroup DRIVERS
 * @brief BLE Radio Request Interface Driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "arch.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "radio_hal_ble.h"
#include "radio_hal_ble_cs.h"
#include "radio_hal_frc.h"
#include "radio_status.h"

#ifndef RADIO_HAL_MGR_OMIT
#define RADIO_HAL_MGR_OMIT 1
#endif

#if RADIO_HAL_MGR_OMIT
typedef uint32_t atm_mac_mgr_priority_t;
#else
#include "radio_hal_mgr.h"
#endif

/**
 * @brief Reference time for BLE operation
 */
typedef enum {
    /** Do not use a reference time */
    ATM_REQ_BLE_AT_ABSOLUTE_TIME,
    /** Use time as a delta from the start of the last operation scheduled with
     * ATM_REQ_BLE_AT_ABOSOLUTE_TIME */
    ATM_REQ_BLE_OFFSET_FROM_PRIOR_ABSOLUTE_TIME,
    /** Use time as a delta from the end of the last TX or RX packet */
    ATM_REQ_BLE_OFFSET_FROM_PRIOR_END_TIME,
} atm_req_ble_time_reference_t;

/**
 * @brief Signature of callback function issued when RX operation completes.
 *
 * The request handler will call a function of this type to signal that a
 * receive operation has completed.
 *
 * @param[in] status Radio management completion status for this operation.
 * @param[in] radio_status Completion status from the BLE driver
 * @param[in] start_offset Difference between the start_time of the last
 *   operation scheduled with ATM_REQ_BLE_AT_ABSOLUTE_TIME and the first bit
 *   time on-air of the current packet
 * @param[in] rssi Received Signal Strength Indicator of the current packet
 */
typedef void (*atm_req_ble_rx_request_callback_t)(atm_mac_status_t status,
    atm_mac_status_t radio_status, uint32_t start_offset, int8_t rssi);

/**
 * @brief Signature of callback function issued when TX operation completes.
 *
 * The request handler will call a function of this type to signal that a
 * transmit operation has completed.
 *
 * @param[in] status Radio management completion status for this operation.
 * @param[in] radio_status Completion status from the BLE driver
 */
typedef void (*atm_req_ble_tx_request_callback_t)(atm_mac_status_t status,
    atm_mac_status_t radio_status);

// This struct is opaque to callers, with members only used in the
// radio_req_ble.c implementation file
struct atm_req_ble_interface_data;
typedef struct atm_req_ble_interface_data *atm_req_ble_interface_t;

// There is currently one public BLE interface to be used to access the radio
extern atm_req_ble_interface_t atm_ble_iface;

/**
 * @brief Initialize BLE resources.
 * This function will perform any one-time initialization of resources
 * required for BLE activity. The first time this function is called, it will
 * initialize the request handler.
 *
 * @note This function must be called before any other function in this module.
 * @param[in] interface The request interface to use.
 */
void atm_req_ble_init(atm_req_ble_interface_t interface);

/**
 * @brief Register callback functions for completion events.
 *
 * The driver will call the registered callback functions to signal
 * completion events related to earlier receive API calls.
 *
 * @note The callback functions are called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] rx_complete_callback The callback function for receive completion
 * @param[in] tx_complete_callback The callback function for transmit completion
 */
__NONNULL(2, 3)
void atm_req_ble_register_complete_callbacks(atm_req_ble_interface_t interface,
    atm_req_ble_rx_request_callback_t rx_complete_callback,
    atm_req_ble_tx_request_callback_t tx_complete_callback);

/**
 * @brief Enable BLE mode of radio operation.
 *
 * This function will enable the radio for BLE operations, but has no
 * effect when the radio manager is in use
 * @param[in] interface The request interface to use.
 */
void atm_req_ble_enable(__UNUSED atm_req_ble_interface_t interface);

/**
 * @brief Receives a packet using the current radio configuration.
 *
 * This function will initiate reception of a packet using the
 * current radio configuration as defined by previous calls to PHY and MAC
 * configuration functions.
 *
 * The receive will be scheduled with the radio manager, and may fail to start
 * or be aborted depending on other protocols using the radio. This function
 * will report status by calling the configured RX callback function unless
 * the BLE interface is stopped by a call to @ref atm_req_ble_stop.
 *
 * @param[in] interface The request interface to use.
 * @param[in] ref Time basis to use to interpret start_time
 * @param[in] start_time Provides the time for the beginning of the receive
 * @param[in] timeout Amount of time to wait in RX
 * @param[in] priority Priority to use for radio management
 */
void atm_req_ble_sched_rx_at(atm_req_ble_interface_t interface,
    atm_req_ble_time_reference_t ref, uint32_t start_time, uint32_t timeout,
    atm_mac_mgr_priority_t priority);

/**
 * @brief Transmits a packet using the current radio configuration.
 *
 * This function will initiate transmission of a packet using the
 * current configuration as defined by previous calls to PHY and MAC
 * configuration functions.
 *
 * The transmit will be scheduled with the radio manager, and may fail to start
 * or be aborted depending on other protocols using the radio. This function
 * will report status by calling the configured TX callback function unless
 * the BLE interface is stopped by a call to @ref atm_req_ble_stop.
 *
 * @param[in] interface The request interface to use.
 * @param[in] ref Time basis to use to interpret start_time
 * @param[in] start_time Provides the time for the beginning of the transmit
 * @param[in] priority Priority to use for radio management
 */
void atm_req_ble_sched_tx_at(atm_req_ble_interface_t interface,
    atm_req_ble_time_reference_t ref, uint32_t start_time,
    atm_mac_mgr_priority_t priority);

/**
 * @brief Stops current radio activity.
 *
 * This function will stop any ongoing receive or transmit operation.
 *
 * @note This function might block for a period of time to allow the radio
 * to return an idle state.
 *
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 */
void atm_req_ble_stop(atm_req_ble_interface_t interface);

/**
 * @brief Provide the transmit packet
 *
 * This function may be called either before or after
 * \ref atm_req_ble_sched_tx_at. This must be a valid BLE packet to avoid
 * transmit underflows. Underflows will be reported as a
 * \ref atm_mac_status_t in the transmit complete callback.
 *
 * @param[in] interface The request interface to use.
 * @param[in] packet The data to transmit
 * @param[in] length The length of packet
 */
__NONNULL(2)
void atm_req_ble_tx_scheduled_packet(__UNUSED atm_req_ble_interface_t interface,
    uint8_t const *packet, uint16_t length);

/**
 * @brief Provide the receive buffer
 *
 * This function may be called either before or after
 * \ref atm_req_ble_sched_rx_at. The buffer should be long enough to receive
 * any valid BLE packet, to avoid a buffer overflow. Overflows will be reported
 * as a \ref atm_mac_status_t in the receive complete callback.
 *
 * @param[in] interface The request interface to use.
 * @param[in, out] packet The buffer to receive in
 * @param[in] length The length of packet
 */
__NONNULL(2)
void atm_req_ble_rx_scheduled_packet(__UNUSED atm_req_ble_interface_t interface,
    uint8_t *packet, uint16_t length);

/**
 * @brief Set ATLC FRC Timer for BLE operation
 *
 * This function is used to set a timer using the FRC. It will also inform the
 * radio manager of the intent to start a BLE operation at the given time, in
 * order to precisely schedule radio activities.
 *
 * @note Timer must be stopped first. Calling this function on an active timer
 * will not overwrite the current timer configuration.
 * @par
 * @note This function and @ref atm_req_ble_stop_timer should both be called
 * within the same priority context
 *
 * @param[in]    timer       Timer number
 * @param[in]    timeout_us  Timeout in microseconds
 * @param[in]    callback    Callback on timeout
 * @return       Error value @ref atm_mac_frc_error_t
 */
__NONNULL(3)
atm_mac_frc_error_t atm_req_ble_set_timer(atm_mac_frc_timer_t timer,
    uint32_t timeout_us, atm_mac_frc_callback_t callback);

/**
 * @brief Stop ATLC FRC Timer for BLE operation
 *
 * This function is used to stop an FRC timer. It will also inform the radio
 * manager that there are no longer BLE operations pending based on the timer.
 *
 * @note This function and @ref atm_req_ble_set_timer should both be called
 * within the same priority context
 *
 * @param[in]    timer       Timer number
 */
void atm_req_ble_stop_timer(atm_mac_frc_timer_t timer);

/******************************************************************************
 For all functions which do not need access to the radio, provide an API layer
 that simply maps to the underlying BLE driver function.

 Functions and documentation below this block are copied from radio_hal_ble.h
 as a few examples for now.
 *****************************************************************************/

// Initialization
__STATIC_INLINE
void atm_req_ble_deinit(__UNUSED atm_req_ble_interface_t interface)
{
    atm_mac_ble_deinit();
}

// Control and Status
__STATIC_INLINE
atm_mac_ble_state_t atm_req_ble_get_state(
    __UNUSED atm_req_ble_interface_t interface)
{
    return atm_mac_ble_get_state();
}
__STATIC_INLINE
void atm_req_ble_set_access_address(__UNUSED atm_req_ble_interface_t interface,
    uint32_t addr)
{
    atm_mac_ble_set_access_address(addr);
}
__STATIC_INLINE
void atm_req_ble_set_crc_init(__UNUSED atm_req_ble_interface_t interface,
    uint32_t crc_init)
{
    atm_mac_ble_set_crc_init(crc_init);
}
__STATIC_INLINE
void atm_req_ble_set_channel(__UNUSED atm_req_ble_interface_t interface,
    uint8_t channel)
{
    atm_mac_ble_set_channel(channel);
}
__STATIC_INLINE
void atm_req_ble_set_tx_power(__UNUSED atm_req_ble_interface_t interface,
    int8_t power_level)
{
    atm_mac_ble_set_tx_power(power_level);
}
__STATIC_INLINE
int8_t atm_req_ble_get_tx_power(__UNUSED atm_req_ble_interface_t interface)
{
    return atm_mac_ble_get_tx_power();
}

/**
 * @brief Get BLE Tx phy
 *
 * @param[in] interface The request interface to use.
 * @return Currently configured BLE phy
 */
__STATIC_INLINE
atm_mac_ble_phy_t atm_req_ble_get_phy(
    __UNUSED atm_req_ble_interface_t interface)
{
    return atm_mac_ble_get_phy();
}

/**
 * @brief Set BLE Tx phy
 *
 * @param[in] interface The request interface to use.
 * @param[in] atm_tx_phy value of ble phy
 */
__STATIC_INLINE
void atm_req_ble_set_tx_phy(__UNUSED atm_req_ble_interface_t interface,
    atm_mac_ble_phy_t atm_tx_phy)
{
    atm_mac_ble_set_tx_phy(atm_tx_phy);
}

/**
 * @brief Set BLE Rx phy
 *
 * @param[in] interface The request interface to use.
 * @param[in] atm_rx_phy value of ble phy
 */
__STATIC_INLINE
void atm_req_ble_set_rx_phy(__UNUSED atm_req_ble_interface_t interface,
    atm_mac_ble_phy_t atm_rx_phy)
{
    atm_mac_ble_set_rx_phy(atm_rx_phy);
}

/**
 * @brief Enable/Disable ble data whitening
 *
 * @param[in] interface The request interface to use.
 * @param[in] ena true/false for enable/disable ble data whitening
 */
__STATIC_INLINE
void atm_req_ble_set_data_whitening(__UNUSED atm_req_ble_interface_t interface,
    bool ena)
{
    atm_mac_ble_set_data_whitening(ena);
}

/**
 * @brief Set Tx test settings
 *
 * @param[in] interface The request interface to use.
 * @param[in] continuous_tx transmitting an endless packet
 * @param[in] type payload type for transmitting
 * @param[in] forced_hdr fixed header value (type=ATM_BLE_PAYLOAD_FORCED)
 * @param[in] forced_bytes fixed payload value (type=ATM_BLE_PAYLOAD_FORCED)
 */
__STATIC_INLINE
void atm_req_ble_tx_test_settings(__UNUSED atm_req_ble_interface_t interface,
    bool continuous_tx, atm_mac_ble_payload_type_t type, uint16_t forced_hdr,
    uint8_t forced_bytes)
{
    atm_mac_ble_tx_test_settings(continuous_tx, type, forced_hdr, forced_bytes);
}

// Misc
__STATIC_INLINE
uint32_t atm_req_ble_get_start_bit_time(
    __UNUSED atm_req_ble_interface_t interface)
{
    return atm_mac_ble_get_start_bit_time();
}
__STATIC_INLINE
uint32_t atm_req_ble_get_end_bit_time(
    __UNUSED atm_req_ble_interface_t interface)
{
    return atm_mac_ble_get_end_bit_time();
}

/**
 * @brief Enable or disable ble ll encryption engine
 *
 * @param[in] interface The request interface to use.
 * @param[in] enable true/false for enable/disable ble ll encryption engine
 */
__STATIC_INLINE
void atm_req_ble_enc_enable(__UNUSED atm_req_ble_interface_t interface,
    bool enable)
{
    atm_mac_ble_enc_enable(enable);
}

/**
 * @brief Set the initial vector of ble ll encryption
 *
 * @param[in] interface The request interface to use
 * @param[in] iv the address of the initial vector
 */
__STATIC_INLINE __NONNULL(2)
void atm_req_ble_set_iv(__UNUSED atm_req_ble_interface_t interface,
    uint8_t const *iv)
{
    atm_mac_ble_set_iv(iv);
}

/**
 * @brief Set the session key of ble ll encryption
 *
 * @param[in] interface The request interface to use
 * @param[in] sk the address of the session key
 */
__STATIC_INLINE __NONNULL(2)
void atm_req_ble_set_session_key(__UNUSED atm_req_ble_interface_t interface,
    uint8_t const *sk)
{
    atm_mac_ble_set_session_key(sk);
}

/**
 * @brief Set the direction bit of ble ll encryption
 *
 * @param[in] interface The request interface to use
 * @param[in] dir the value of the direction bit, true for 1 and false for 0
 *                defined in Vol6,PartE,2.1 of core spec ver 5.3
 */
__STATIC_INLINE
void atm_req_ble_set_enc_dir(__UNUSED atm_req_ble_interface_t interface,
    bool dir)
{
    atm_mac_ble_set_enc_dir(dir);
}

/**
 * @brief Set the packet counter of ble ll encryption
 *
 * @param[in] interface The request interface to use
 * @param[in] cntr the value of the packet counter
 */
__STATIC_INLINE
void atm_req_ble_set_enc_pkt_cntr(__UNUSED atm_req_ble_interface_t interface,
    uint64_t cntr)
{
    atm_mac_ble_set_enc_pkt_cntr(cntr);
}

/**
 * @brief Get currently rx packet phy information.
 *
 * @param[in] interface The request interface to use
 * @return current rx pkt phy information
 */
__STATIC_INLINE
atm_mac_ble_phy_t atm_req_ble_get_curr_rx_pkt_phy(
    __UNUSED atm_req_ble_interface_t interface)
{
    return atm_mac_ble_get_curr_rx_pkt_phy();
}

/**
 * @brief Kick CS step
 *
 * @param[in] interface The request interface to use
 * @param[in] due_time target anchor time
 * @param[in] priority Priority to use for radio management
 */
void atm_req_ble_cs_kick_step(atm_req_ble_interface_t interface,
    uint32_t start_time, atm_mac_mgr_priority_t priority);

/**
 * @brief Enable or disable channel sounding
 *
 * @param[in] interface The request interface to use
 * @param[in] param cs enable parameters
 */
void atm_req_ble_cs_enable_cs(atm_req_ble_interface_t interface,
    cs_enable_t *param);
#ifdef __cplusplus
}
#endif

/// @}
