/**
 *******************************************************************************
 *
 * @file radio_req_154.h
 *
 * @brief 15.4 Radio Request Handler
 *
 * This driver handles request for 15.4 radio operations. It will coordinate
 * with the Radio Manager and the 15.4 LMAC to ensure that operations occur when
 * possible, and will return an error when that is not possible. When calling
 * the 15.4 Request Driver, all calls should go here, and no calls should go
 * directly to the 15.4 LMAC directly.
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_REQ_154 RADIO_REQ_154
 * @ingroup DRIVERS
 * @brief 15.4 Radio Request Interface Driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "arch.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "radio_hal_154.h"
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
 * @brief Signature of callback function issued when receive completes.
 *
 * The request handler will call a function of this type to signal that a
 * completion event has occurred for a receive operation
 *
 * @param[in] status Radio management completion status for this operation.
 * @param[in] radio_status @ref atm_mac_154_rx_complete_status_t completion
 * status for this receive operation.
 * @param[in] info pointer to @ref atm_mac_154_rx_complete_info_t struct for
 * this receive operation.
 */
typedef void (*atm_req_154_rx_request_callback_t)(atm_mac_status_t status,
    atm_mac_154_rx_complete_info_t const *info);

/**
 * @brief Signature of callback function issued when transmit completes.
 *
 * The request handler will call a function of this type to signal that a
 * completion event has occurred for a transmit operation
 *
 * @param[in] status Radio management completion status for this operation.
 * @param[in] radio_status @ref atm_mac_154_tx_complete_status_t completion
 * status for this receive operation.
 * @param[in] info pointer to @ref atm_mac_154_tx_complete_info_t struct for
 * this transmit operation.
 */
typedef void (*atm_req_154_tx_request_callback_t)(atm_mac_status_t status,
    atm_mac_154_tx_complete_info_t const *info);

/**
 * @brief Signature of callback function issued when energy detection completes.
 *
 * The request handler will call a function of this type to signal that a
 * completion event has occurred for an energy detection operation
 *
 * @param[in] status Radio management completion status for this operation.
 * @param[in] rssi The measured RSSI. A value of @ref ATM_MAC_154_RSSI_INVALID
 * will be provided if the measurement was unsuccessful.
 */
typedef void (*atm_req_154_ed_request_callback_t)(atm_mac_status_t status,
    int8_t rssi);

// This struct is opaque to callers, with members only used in the
// radio_req_154.c implementation file
struct atm_req_154_interface_data;
typedef struct atm_req_154_interface_data *atm_req_154_interface_t;

// There is currently one public 15.4 interface to be used to access the radio
extern atm_req_154_interface_t atm_154_iface;

/**
 * @brief Initialize 15.4 resources.
 * This function will perform any one-time initialization of resources
 * required for 15.4 activity. The first time this function is called, it will
 * initialize the request handler.
 *
 * @note This function must be called before any other function in this module.
 * @param[in] interface The request interface to use.
 */
void atm_req_154_init(atm_req_154_interface_t interface);

/**
 * @brief Register callback function for receive completion events.
 *
 * The driver will call the registered callback function to signal
 * completion events related to earlier receive API calls.
 *
 * @param[in] interface The request interface to use.
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(2)
void atm_req_154_register_rx_complete_callback(
    atm_req_154_interface_t interface,
    atm_req_154_rx_request_callback_t handler);

/**
 * @brief Register callback function for transmit completion events.
 *
 * The driver will call the registered callback function to signal
 * completion events related to earlier transmit API calls.
 *
 * @param[in] interface The request interface to use.
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(2)
void atm_req_154_register_tx_complete_callback(
    atm_req_154_interface_t interface,
    atm_req_154_tx_request_callback_t handler);

/**
 * @brief Register callback function for energy detection completion events.
 *
 * The driver will call the registered callback function to signal
 * completion events related to earlier energy detection API calls.
 *
 * @param[in] interface The request interface to use.
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(2)
void atm_req_154_register_ed_complete_callback(
    atm_req_154_interface_t interface,
    atm_req_154_ed_request_callback_t handler);

/**
 * @brief Receives a packet using the current radio configuration.
 *
 * This function will initiate reception of a packet using the
 * current radio configuration as defined by previous calls to PHY and MAC
 * configuration functions. See @ref atm_mac_154_receive_packet for details
 * of how the receive is handled, with the parameters of that function
 * corresponding to the members of the rx_data parameter.
 *
 * The receive will be scheduled with the radio manager, and may fail to start
 * or be aborted depending on other protocols using the radio. This function
 * will report status by calling rx_data's callback function unless interface
 * is stopped by a call to @ref atm_req_154_stop.
 *
 * @param[in] interface The request interface to use.
 * @param[in,out] packet The packet data. Caller must ensure there are
 * @ref MAX_154_PACKET_LEN bytes available. Note that the maximum length will
 * be less two CRC bytes unless disabled with @ref atm_mac_154_disable_auto_crc
 * @param[in] start_time The earliest time at which to expect SFD. If @p
 * start_time is specified as 0, the receive operation will be started
 * immediately
 * @param[in] duration The duration to wait for SFD. If @p duration is
 * specified as 0, the receive operation will continue indefinitely until
 * a packet is successfully received or the operation is stopped using
 * @ref atm_mac_154_stop.
 * @param[in] priority Priority to use for radio management
 */
__NONNULL(2)
void atm_req_154_receive_packet(atm_req_154_interface_t interface,
    uint8_t *packet, uint32_t start_time, uint32_t duration,
    atm_mac_mgr_priority_t priority);

/**
 * @brief Transmits a packet using the current radio configuration.
 *
 * This function will initiate transmission of a packet using the
 * current configuration as defined by previous calls to PHY and MAC
 * configuration functions. See @ref atm_mac_154_transmit_packet for details
 * of how the receive is handled, with the parameters of that function
 * corresponding to the members of the rx_data parameter.
 *
 * The transmit will be scheduled with the radio manager, and may fail to start
 * or be aborted depending on other protocols using the radio. This function
 * will report status by calling tx_data's callback function unless interface
 * is stopped by a call to @ref atm_req_154_stop.
 *
 * @param[in] interface The request interface to use.
 * @param[in] packet The packet data.
 * @param[in] csma_mode Transmit CSMA mode
 * @param[in] delay Start the transmit at the provided start_time if true.
 * @param[in] start_time The time to start the transmit. Ignored if delay
 *   is false.
 * @param[in] priority Priority to use for radio management
 */
__NONNULL(2)
void atm_req_154_transmit_packet(atm_req_154_interface_t interface,
    uint8_t const *packet, atm_mac_154_tx_csma_mode_t csma_mode, bool delay,
    uint32_t start_time, atm_mac_mgr_priority_t priority);

/**
 * @brief Transmits a packet using the current radio configuration.
 *
 * This function behaves just like @ref atm_req_154_transmit_packet, but
 * handles the length byte of the packet separate from the data. The PHR
 * should not be included in the packet parameter
 *
 * @param[in] interface The request interface to use.
 * @param[in] packet_len The length of the packet parameter
 * @param[in] packet The packet data, without a length byte
 * @param[in] csma_mode Transmit CSMA mode
 * @param[in] delay Start the transmit at the provided start_time if true.
 * @param[in] start_time The time to start the transmit. Ignored if delay
 *   is false.
 * @param[in] priority Priority to use for radio management
 */
__NONNULL(3)
void atm_req_154_transmit_packet_with_len(atm_req_154_interface_t interface,
    uint8_t packet_len, uint8_t const *packet,
    atm_mac_154_tx_csma_mode_t csma_mode, bool delay, uint32_t start_time,
    atm_mac_mgr_priority_t priority);

/**
 * @brief Performs an energy detection reading on the current channel.
 *
 * This function will enter a receive mode where no packets can be received.
 * After ATM_MAC_154_CCA_WINDOW_TIME_US of sampling the channel, the radio will
 * return to an idle state. The registered handler will then be called from
 * interrupt context with the detected energy over the window.
 * @note This function is called from interrupt context.
 *
 * This operation will be scheduled with the radio manager, and may fail to
 * start or be aborted depending on other protocols using the radio. This
 * will report status by calling ed_data's callback function unless interface
 * is stopped by a call to @ref atm_req_154_stop.
 *
 * @param[in] interface The request interface to use.
 * @param[in] window_us Duration in microseconds.  Must not be 0.
 * @param[in] priority Priority to use for radio management
 */
void atm_req_154_energy_detect(atm_req_154_interface_t interface,
    uint32_t window_us, atm_mac_mgr_priority_t priority);

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
void atm_req_154_stop(__UNUSED atm_req_154_interface_t interface);

/**
 * @brief Get 15.4 Request Handler state
 *
 * This function will return a radio state as if the manager was not active. If
 * there is a transmit scheduled with the manager, or an active transmit is
 * running in the driver, this will return \ref ATM_MAC_154_STATE_TX. The same
 * logic applies for receives and energy detections.
 *
 * @param[in] interface The request interface to use.
 * @return Enumerated driver state.
 */
atm_mac_154_state_t atm_req_154_get_state(
    __UNUSED atm_req_154_interface_t interface);

/******************************************************************************
 For all functions which do not need 15.4 to be active, provide an API layer
 that simply maps to the underlying 15.4 LMAC function.

 Functions and documentation below this block are copied from radio_hal_154.h
 as a few examples for now.
 *****************************************************************************/

/**
 * @brief Set 15.4 protocol version
 * This function will perform configure the driver to operate as a specific
 * version of 15.4. If this function is not called, the driver will behave
 * as if ATM_MAC_154_VERSION_IEEE_2006 was configured.
 * @param[in] interface The request interface to use.
 * @param[in] version The specification used for radio behavior
 */
__STATIC_INLINE
void atm_req_154_set_version(__UNUSED atm_req_154_interface_t interface,
    atm_mac_154_version_t version)
{
    atm_mac_154_set_version(version);
}

/**
 * @brief De-initialize 15.4 resources.
 * This function will clean up and de-initialize any resources required
 * for 15.4 activity.
 * @param[in] interface The request interface to use.
 */
__STATIC_INLINE
void atm_req_154_deinit(__UNUSED atm_req_154_interface_t interface)
{
    atm_mac_154_deinit();
}

/**
 * @brief Disable 15.4 mode of radio operation.
 * This function will disable the radio for 15.4 operations.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 */
__STATIC_INLINE
void atm_req_154_disable(__UNUSED atm_req_154_interface_t interface)
{
    atm_mac_154_disable();
}

/**
 * @brief Register callback function for long address received event.
 * @note This function is used to register a callback function.
 * @par
 * @note The driver will call the registered callback function to signal
 * that the long address field has been received.
 * @par
 * @note This function is called from interrupt context.
 * @par
 * @note The callback function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] handler The callback function to be registered.
 */
__STATIC_INLINE __NONNULL(2)
void atm_req_154_register_rx_long_addr_callback(
    __UNUSED atm_req_154_interface_t interface,
    atm_mac_154_rx_long_addr_pend_handler_t handler)
{
    atm_mac_154_register_rx_long_addr_callback(handler);
}

/**
 * @brief Register callback function for short address received event.
 * @note This function is used to register a callback function.
 * @par
 * @note The driver will call the registered callback function to signal
 * that the short address field has been received.
 * @par
 * @note This function is called from interrupt context.
 * @par
 * @note The callback function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] handler The callback function to be registered.
 */
__STATIC_INLINE __NONNULL(2)
void atm_req_154_register_rx_short_addr_callback(
    __UNUSED atm_req_154_interface_t interface,
    atm_mac_154_rx_short_addr_pend_handler_t handler)
{
    atm_mac_154_register_rx_short_addr_callback(handler);
}

/**@}*/

/** @name PHY configuration functions
 * Functions related to configuration and state of the Physical Layer.
 */

/**@{*/

/**
 * @brief Provides the currently configured 15.4 channel.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The currently configured 15.4 2.4GHz channel (11-26).
 */
__STATIC_INLINE
uint8_t atm_req_154_get_channel(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_channel();
}

/**
 * @brief Provides the currently configured tx power level.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The currently configured tx power level in dBm.
 */

__STATIC_INLINE
int8_t atm_req_154_get_tx_power(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_tx_power();
}

/**
 * @brief Configures the radio to operate on a standard 15.4 channel.
 * @note Invalid channels are ignored.
 * @note This function will defer changes until radio is idle.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] channel A standard 15.4 channel (11-26) in the 2.4 GHz band.
 */
__STATIC_INLINE
void atm_req_154_set_channel(__UNUSED atm_req_154_interface_t interface,
    uint8_t channel)
{
    atm_mac_154_set_channel(channel);
}

/**
 * @brief Configures the radio to operate at an available tx power.
 * @note If an exact power level is not available, the closest lower
 * power level will be selected.
 * @note This function will defer changes until radio is idle.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] tx_power A power level in dBm.
 */
__STATIC_INLINE
void atm_req_154_set_tx_power(__UNUSED atm_req_154_interface_t interface,
    int8_t tx_power)
{
    atm_mac_154_set_tx_power(tx_power);
}

/**@}*/

/** @name MAC configuration functions - Address Filtering
 * Functions related to configuration and state of the MAC Layer
 * address filtering capabilities.
 */

/**@{*/

/**
 * @brief Indicates which mode is being operated in
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The mode being operated in
 */
__STATIC_INLINE
atm_mac_154_device_mode_t atm_req_154_get_device_mode(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_device_mode();
}

/**
 * @brief Operate in the given mode for address filtering and FP checks
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] mode Mode to operate in
 */
__STATIC_INLINE
void atm_req_154_set_device_mode(__UNUSED atm_req_154_interface_t interface,
    atm_mac_154_device_mode_t mode)
{
    atm_mac_154_set_device_mode(mode);
}

/**
 * @brief Gets the long address to be used in MAC address filtering.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The long address.
 */
__STATIC_INLINE
uint64_t atm_req_154_get_long_addr(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_long_addr();
}

/**
 * @brief Gets the short address to be used in MAC address filtering.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The short address.
 */
__STATIC_INLINE
uint16_t atm_req_154_get_short_addr(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_short_addr();
}

/**
 * @brief Gets the PAN Id to be used in MAC address filtering.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The PAN identifier.
 */
__STATIC_INLINE
uint16_t atm_req_154_get_pan_id(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_pan_id();
}

/**
 * @brief Sets the long address to be used in MAC address filtering.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] long_addr The long address.
 */
__STATIC_INLINE
void atm_req_154_set_long_addr(__UNUSED atm_req_154_interface_t interface,
    uint64_t long_addr)
{
    atm_mac_154_set_long_addr(long_addr);
}

/**
 * @brief Sets the short address to be used in MAC address filtering.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] short_addr The short address.
 */
__STATIC_INLINE
void atm_req_154_set_short_addr(__UNUSED atm_req_154_interface_t interface,
    uint16_t short_addr)
{
    atm_mac_154_set_short_addr(short_addr);
}

/**
 * @brief Sets the PAN Id to be used in MAC address filtering.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] pan_id The PAN identifier.
 */
__STATIC_INLINE
void atm_req_154_set_pan_id(__UNUSED atm_req_154_interface_t interface,
    uint16_t pan_id)
{
    atm_mac_154_set_pan_id(pan_id);
}

/**@}*/

/** @name MAC configuration functions - Channel Access
 * Functions related to configuration and state of the MAC Layer CSMA
 * and retry subsytems.
 */

/**@{*/

/**
 * @brief Gets the threshold for the MAC CCA transmit operation.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The CCA threshold in dBm.
 */
__STATIC_INLINE
int8_t atm_req_154_get_cca_threshold(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_cca_threshold();
}

/**
 * @brief Gets the maximum CSMA MAC backoff exponent.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The maximum backoff exponent.
 */
__STATIC_INLINE
int8_t atm_req_154_get_max_csma_backoff_exponent(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_max_csma_backoff_exponent();
}

/**
 * @brief Gets the maximum number of CSMA transmit attempts.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The maximum number CSMA transmit attempts.
 */
__STATIC_INLINE
int8_t atm_req_154_get_max_csma_attempts(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_max_csma_attempts();
}

/**
 * @brief Gets the number of MAC transmit retries.
 * This quantity is the total number of times a packet will be
 * retransmitted in an effort to receive a requested Ack.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return The maximum number of MAC tx retries.
 */
__STATIC_INLINE
int8_t atm_req_154_get_max_transmit_retries(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_max_transmit_retries();
}

/**
 * @brief Gets the minimum CSMA MAC backoff exponent.
 * @param[in] interface The request interface to use.
 * @return The minimum backoff exponent.
 */
__STATIC_INLINE
int8_t atm_req_154_get_min_csma_backoff_exponent(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_get_min_csma_backoff_exponent();
}

/**
 * @brief Sets the threshold for the MAC CCA transmit operation.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] cca_threshold_dbm The CCA threshold in dBm.
 */
__STATIC_INLINE
void atm_req_154_set_cca_threshold(__UNUSED atm_req_154_interface_t interface,
    int8_t cca_threshold_dbm)
{
    atm_mac_154_set_cca_threshold(cca_threshold_dbm);
}

/**
 * @brief Sets the maximum CSMA MAC backoff exponent.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] max_be The maximum backoff exponent.
 */
__STATIC_INLINE
void atm_req_154_set_max_csma_backoff_exponent(
    __UNUSED atm_req_154_interface_t interface, int8_t max_be)
{
    atm_mac_154_set_max_csma_backoff_exponent(max_be);
}

/**
 * @brief Sets the maximum number of CSMA transmit attempts.
 * @note This quantity is separate from MAC retries.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] max_csma_attempts The maximum number CSMA transmit attempts.
 */
__STATIC_INLINE
void atm_req_154_set_max_csma_attempts(
    __UNUSED atm_req_154_interface_t interface, int8_t max_csma_attempts)
{
    atm_mac_154_set_max_csma_attempts(max_csma_attempts);
}

/**
 * @brief Sets the number of MAC transmit retries.
 * @note This quantity is separate from CCA attempts.
 * @note This function will defer changes until radio is idle.
 * This quantity is the total number of times a packet will be
 * retransmitted in an effort to receive a requested Ack.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] max_tx_retries The maximum number of MAC tx retries.
 */
__STATIC_INLINE
void atm_req_154_set_max_transmit_retries(
    __UNUSED atm_req_154_interface_t interface, int8_t max_tx_retries)
{
    atm_mac_154_set_max_transmit_retries(max_tx_retries);
}

/**
 * @brief Sets the minimum CSMA MAC backoff exponent.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] min_be The minimum backoff exponent.
 */
__STATIC_INLINE
void atm_req_154_set_min_csma_backoff_exponent(
    __UNUSED atm_req_154_interface_t interface, int8_t min_be)
{
    atm_mac_154_set_min_csma_backoff_exponent(min_be);
}

/**@}*/

/** @name Transmit and receive functions.
 * Functions related to transmit and receive activity.
 */

/**@{*/

/**
 * @brief Provides the Link Quality Indication based on the RSSI.
 *
 * This function performs an RSSI to LQI conversion according to the known
 * characteristics of the radio.
 * @param[in] interface The request interface to use.
 * @param[in] rssi The RSSI on which to base the conversion, in dBm.
 * @return 0 for worst link quality, 0xff for best link quality, and
 * proportionally spaced values in between.
 */
__STATIC_INLINE
uint8_t atm_req_154_map_rssi_to_lqi(__UNUSED atm_req_154_interface_t interface,
    int8_t rssi)
{
    return atm_mac_154_map_rssi_to_lqi(rssi);
}

/**@}*/

/** @name Diagnostic functions.
 * Functions related to diagnostic and non-standard operating modes.
 */

/**@{*/

/**
 * @brief Starts transmission of unmodulated carrier.
 * @note In normal MAC operation, this function is not called.
 * @par
 * @note The function @ref atm_mac_154_get_state will return
 * @ref ATM_MAC_154_STATE_TX_CARRIER_WAVE while this mode is active.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] activate tx of carrier if true, deactivate if false.
 */
__STATIC_INLINE
void atm_req_154_activate_carrier_wave(
    __UNUSED atm_req_154_interface_t interface, bool activate)
{
    // Note: This diagnostic function bypasses the Radio Manager
    if (atm_mac_154_get_state() == ATM_MAC_154_STATE_DISABLE) {
	atm_mac_154_enable();
    }
    atm_mac_154_activate_carrier_wave(activate);
}

/**
 * @brief Starts transmission of modulated symbol stream.
 * @note In normal MAC operation, this function is not called.
 * @par
 * @note The function @ref atm_mac_154_get_state will return
 * @ref ATM_MAC_154_STATE_TX_SYMBOL_STREAM while this mode is active.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] activate tx of symbols if true, dectivate if false.
 */
__STATIC_INLINE
void atm_req_154_activate_symbol_stream(
    __UNUSED atm_req_154_interface_t interface, bool activate)
{
    // Note: This diagnostic function bypasses the Radio Manager
    if (atm_mac_154_get_state() == ATM_MAC_154_STATE_DISABLE) {
	atm_mac_154_enable();
    }
    atm_mac_154_activate_symbol_stream(activate);
}

/**
 * @brief Indicates status of MAC address filtering.
 * @param[in] interface The request interface to use.
 * @return true if MAC address filtering is disabled,
 * false otherwise.
 * @note This function is called from interrupt context.
 */
__STATIC_INLINE
bool atm_req_154_address_filtering_disabled(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_address_filtering_disabled();
}

/**
 * @brief Indicates status of automatic MAC transmission of requested Acks.
 * @param[in] interface The request interface to use.
 * @return true if automatic MAC Ack tx is disabled,
 * false otherwise.
 * @note This function is called from interrupt context.
 */
__STATIC_INLINE
bool atm_req_154_auto_ack_disabled(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_auto_ack_disabled();
}

/**
 * @brief Controls MAC address filtering.
 * @note In normal MAC operation, this function is not called.
 * This function allows receive processing of raw packets.
 * @param[in] interface The request interface to use.
 * @param[in] disable Disables MAC address filtering if true,
 * enables same if false.
 * @note This function is called from interrupt context.
 */
__STATIC_INLINE
void atm_req_154_disable_address_filtering(
    __UNUSED atm_req_154_interface_t interface, bool disable)
{
    atm_mac_154_disable_address_filtering(disable);
}

/**
 * @brief Controls automatic MAC transmission of requested Acks.
 * This function allows receive processing of raw packets.
 * @note In normal MAC operation, this function is not called.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] disable Disables automatic MAC Ack tx if true,
 * enables same if false.
 */
__STATIC_INLINE
void atm_req_154_disable_auto_ack(__UNUSED atm_req_154_interface_t interface,
    bool disable)
{
    atm_mac_154_disable_auto_ack(disable);
}

/**
 * @brief Controls automatic transmit and receive of CRC. This
 * function allows the system to transmit and receive raw packets
 * without including an appended CRC.
 * @note In normal MAC operation, this function is not called.
 * @par
 * @note This function is called from interrupt context.
 * @par
 * @param[in] interface The request interface to use.
 * @param[in] disable Disables auto-calculate and insert CRC in tx/rx
 * packet if true, enables same if false.
 */
__STATIC_INLINE
void atm_req_154_disable_auto_crc(__UNUSED atm_req_154_interface_t interface,
    bool disable)
{
    atm_mac_154_disable_auto_crc(disable);
}

/**
 * @brief Controls automatic MAC receive of requested Acks.
 * @note In normal MAC operation, this function is not called.
 * This function allows the system to ignore requests for Acks.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @param[in] disable Disables automatic MAC wait for Ack tx if true,
 * enables same if false.
 */
__STATIC_INLINE
void atm_req_154_disable_wait_for_ack(
    __UNUSED atm_req_154_interface_t interface, bool disable)
{
    atm_mac_154_disable_wait_for_ack(disable);
}

/**
 * @brief Indicates status of automatic transmit and receive of CRC.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return true if auto-calculate and insert CRC in tx/rx packet is disabled,
 * false otherwise.
 */
__STATIC_INLINE
bool atm_req_154_auto_crc_disabled(__UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_auto_crc_disabled();
}

/**
 * @brief Indicates status of manual transmit of CRC.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return true if insert manual CRC in tx packet is enabled,
 * false otherwise.
 */
__STATIC_INLINE
bool atm_req_154_manual_tx_crc_enabled(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_manual_tx_crc_enabled();
}

/**
 * @brief Controls transmit of manually-defined CRC value.
 * @note In normal MAC operation, this function is not called.
 * @note This function is called from interrupt context.
 * @note This function can only be called when automatic MAC Ack tx is
 * disabled AND automatic CRC insertion is disabled. API will assert
 * otherwise.
 * @par
 * @param[in] interface The request interface to use.
 * @param override Manually write CRC with provided value when true,
 * don't write when false.
 * @param value The value to insert for CRC in tx packet.
 */
__STATIC_INLINE
void atm_req_154_enable_manual_tx_crc(
    __UNUSED atm_req_154_interface_t interface, bool override, uint16_t value)
{
    atm_mac_154_enable_manual_tx_crc(override, value);
}

/**
 * @brief Indicates status of automatic MAC receive of requested Acks.
 * @note This function is called from interrupt context.
 * @param[in] interface The request interface to use.
 * @return true if automatic MAC wait for Ack tx is disabled,
 * false otherwise.
 */
__STATIC_INLINE
bool atm_req_154_wait_for_ack_disabled(
    __UNUSED atm_req_154_interface_t interface)
{
    return atm_mac_154_wait_for_ack_disabled();
}

/**
 * @brief Enable Enhanced Acknowledgements
 *
 * @note Calling this function will overwrite the data associated with any
 * prior call to this function. This can only be used to enable the CSL IE in
 * Enhanced Acks.
 *
 * The data provided in enh_ack_data will be added to any ack sent in response
 * to a packet with a source address matching long_addr or short_addr.
 *
 * When calling this function with the CSL IE, CSL Phase will be autonomously
 * populated based on the data provided to @ref atm_mac_154_set_csl_ie_period
 * and @ref atm_mac_154_set_csl_ie_rx_time, as well as the actual packet's
 * receive time.
 *
 * @param[in] interface The request interface to use.
 * @param[in] long_addr The long_addr to reply to with this data
 * @param[in] short_addr The short_addr to reply to with this data
 * @param[in] enh_ack_data The IE. Certain fields may be filled in later
 * @param[in] enh_ack_len The length of enh_ack_data
 */
__STATIC_INLINE __NONNULL(4)
void atm_req_154_enable_enhanced_ack(
    __UNUSED atm_req_154_interface_t interface, uint64_t long_addr,
    uint16_t short_addr, uint8_t const *enh_ack_data, uint8_t enh_ack_len)
{
    atm_mac_154_enable_enhanced_ack(long_addr, short_addr, enh_ack_data,
	enh_ack_len);
}

/**
 * @brief Provide CSL period for the CSL IE
 *
 * This data is used to determine the CSL Phase of the CSL IE configured in
 * @ref atm_mac_154_enable_enhanced_ack. This must match the data in
 * enh_ack_data for proper operation.
 *
 * @param[in] interface The request interface to use.
 * @param[in] csl_period_10symbols The CSL period in units of 10 symbols
 */
__STATIC_INLINE
void atm_req_154_set_csl_ie_period(__UNUSED atm_req_154_interface_t interface,
    uint16_t csl_period_10symbols)
{
    atm_mac_154_set_csl_ie_period(csl_period_10symbols);
}

/**
 * @brief Provide CSL RX start time for the CSL IE
 *
 * This data is used to determine the CSL Phase of the CSL IE configured in
 * @ref atm_mac_154_enable_enhanced_ack. Receives are expected to start at
 * csl_rx_time_us + n * csl_period_10symbols, for each integer n.
 *
 * @param[in] interface The request interface to use.
 * @param[in] csl_rx_time_us The start time of the CSL receive, in microseconds
 */
__STATIC_INLINE
void atm_req_154_set_csl_ie_rx_time(__UNUSED atm_req_154_interface_t interface,
    uint32_t csl_rx_time_us)
{
    atm_mac_154_set_csl_ie_rx_time(csl_rx_time_us);
}
/**@}*/

#ifdef __cplusplus
}
#endif

/// @}
