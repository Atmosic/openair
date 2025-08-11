/**
 *******************************************************************************
 *
 * @file radio_hal_154.h
 *
 * @brief IEEE 802.15.4 Lower-MAC processing
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */

#pragma once

#include "arch.h"
#include "at_lc.h"
#include "radio_status.h"

/**
 * @defgroup RADIO_HAL_154 RADIO_HAL_154
 * @ingroup DRIVERS
 * @brief IEEE 802.15.4 Lower-MAC handling module
 *
 * This module implements the lower-MAC portions of IEEE 802.15.4. The lower-MAC
 * includes functionality that is typically time-critical, hardware-intensive,
 * and power-sensitive.  Implementations for some hardware targets will include
 * usage of hardware accelerators.  In other cases software will implement
 * portions of required functionality.  This module is intended to be used by
 * corresponding upper-MAC software which is responsible for providing a
 * complete IEEE 802.15.4 implementation, to the extent required by
 * applications.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @name Standard 15.4 constants
 * @{
 */
/** Start of frame delimiter length */
#define ATM_MAC_154_SFD_LEN 1
/** Start of frame delimiter value */
#define ATM_MAC_154_SFD_VALUE 0xa7
/** PHY header length */
#define ATM_MAC_154_PHR_LEN 1
/** Frame check sequence length */
#define ATM_MAC_154_FCS_LEN 2
/** Appended status length */
#define ATM_MAC_154_STATUS_LEN 2
/** Frame length mask */
#define ATM_MAC_154_FRAME_LEN_MASK 0x7f
/** Frame length read */
#define ATM_MAC_154_FRAME_LEN_READ(src) \
    ((uint8_t)((src)&ATM_MAC_154_FRAME_LEN_MASK))
/** Frame control field length */
#define ATM_MAC_154_FRAME_CONTROL_LEN 2
/** Sequence number length */
#define ATM_MAC_154_SEQ_NUM_LEN 1
/** PAN ID length */
#define ATM_MAC_154_PAN_ID_LEN 2
/** Long address length */
#define ATM_MAC_154_LONG_ADDR_LEN 8
/** Short address length */
#define ATM_MAC_154_SHORT_ADDR_LEN 2
/** Length byte packet offset */
#define ATM_MAC_154_LENGTH_OFFSET 0U
/** Frame control field lower byte packet offset */
#define ATM_MAC_154_FCF_LOWER_OFFSET (ATM_MAC_154_PHR_LEN)
/** Frame control field upper byte packet offset */
#define ATM_MAC_154_FCF_UPPER_OFFSET (ATM_MAC_154_PHR_LEN + 1)
/** Sequence number packet offset */
#define ATM_MAC_154_SEQ_OFFSET \
    (ATM_MAC_154_PHR_LEN + ATM_MAC_154_FRAME_CONTROL_LEN)
/** Max packet length */
#define MAX_154_PACKET_LEN 128 // phy header (1) + phy payload (127)
/** Broadcast PAN ID */
#define ATM_MAC_154_BROADCAST_PAN_ID 0xFFFF
/** Broadcast Address */
#define ATM_MAC_154_BROADCAST_ADDR 0xFFFF
/** Data Request command byte */
#define ATM_MAC_154_DATA_REQUEST_COMMAND 4
/**@}*/

/** @name 15.4 driver defaults
 * @{
 */
/** Default CCA Threshold */
#define ATM_MAC_154_DEFAULT_CCA_THRESHOLD_DBM (-75)
/** Max CSMA Attempts*/
#define ATM_MAC_154_DEFAULT_MAX_CSMA_ATTEMPTS 4
/** Max CSMA Backoff Exponent */
#define ATM_MAC_154_DEFAULT_MAX_CSMA_BACKOFF_EXPONENT 5
/** Min CSMA Backoff Exponent */
#define ATM_MAC_154_DEFAULT_MIN_CSMA_BACKOFF_EXPONENT 3
/** Max Transmit Retries */
#define ATM_MAC_154_DEFAULT_MAX_TRANSMIT_RETRIES 3
/**@}*/

/** @name 15.4 driver limits
 * @{
 */
/** Min Channel */
#define ATM_MAC_154_MIN_CHANNEL 11
/** Max Channel */
#define ATM_MAC_154_MAX_CHANNEL 26
/** Max CSMA Attempts - Maximum */
#define ATM_MAC_154_MAX_MAX_CSMA_ATTEMPTS 5
/** Max CSMA Attempts - Minimum */
#define ATM_MAC_154_MIN_MAX_CSMA_ATTEMPTS 0
/** Max CSMA Backoff Exponent - Maximum */
#define ATM_MAC_154_MAX_MAX_CSMA_BACKOFF_EXPONENT 8
/** Max CSMA Backoff Exponent - Minimum */
#define ATM_MAC_154_MIN_MAX_CSMA_BACKOFF_EXPONENT 3
/** Min CSMA Backoff Exponent - Maximum */
#define ATM_MAC_154_MAX_MIN_CSMA_BACKOFF_EXPONENT 8
/** Min CSMA Backoff Exponent - Minimum */
#define ATM_MAC_154_MIN_MIN_CSMA_BACKOFF_EXPONENT 0
/** Transmit retry initial backoff exponent for Thread links */
#define ATM_MAC_154_INIT_RETRY_BACKOFF_EXPONENT 0
/** Transmit retry max backoff exponent for Thread links */
#define ATM_MAC_154_MAX_RETRY_BACKOFF_EXPONENT 5
/** Transmit retry backoff increment for Thread links */
#define ATM_MAC_154_RETRY_BACKOFF_INCREMENT 2
/** Max Transmit Retries - Maximum */
#define ATM_MAC_154_MAX_MAX_TRANSMIT_RETRIES 7
/** Max Transmit Retries - Minimum */
#define ATM_MAC_154_MIN_MAX_TRANSMIT_RETRIES 0
/** Transmit Retries for Thread links */
#define ATM_MAC_154_THREAD_TRANSMIT_RETRIES 15
/**@}*/

/** @name 15.4 timing constants
 * @{
 */
/** Microseconds per symbol */
#define ATM_MAC_154_SYMBOL_TIME_US 16
/** Symbols per byte */
#define ATM_MAC_154_SYMBOLS_PER_BYTE 2
/** Microseconds per byte */
#define ATM_MAC_154_BYTE_TIME_US \
    (ATM_MAC_154_SYMBOL_TIME_US * ATM_MAC_154_SYMBOLS_PER_BYTE)
/** Backoff period in symbols */
#define ATM_MAC_154_SYMBOLS_PER_BACKOFF_PERIOD 20
/** Backoff period in microseconds */
#define ATM_MAC_154_BACKOFF_PERIOD_TIME_US \
    (ATM_MAC_154_SYMBOL_TIME_US * ATM_MAC_154_SYMBOLS_PER_BACKOFF_PERIOD)
/** Turnaround time in symbols */
#define ATM_MAC_154_SYMBOLS_PER_TURNAROUND 12
/** Turnaround time in microseconds */
#define ATM_MAC_154_TURNAROUND_TIME_US \
    (ATM_MAC_154_SYMBOL_TIME_US * ATM_MAC_154_SYMBOLS_PER_TURNAROUND)
/** Preamble time in symbols */
#define ATM_MAC_154_SYMBOLS_PER_PREAMBLE 8
/** Preamble time in microseconds */
#define ATM_MAC_154_PREAMBLE_TIME_US \
    (ATM_MAC_154_SYMBOL_TIME_US * ATM_MAC_154_SYMBOLS_PER_PREAMBLE)
/** Start of frame delimiter time in symbols */
#define ATM_MAC_154_SYMBOLS_PER_SFD 2
/** Start of frame delimiter time in microseconds */
#define ATM_MAC_154_SFD_TIME_US \
    (ATM_MAC_154_SYMBOL_TIME_US * ATM_MAC_154_SYMBOLS_PER_SFD)
/** Synchronization header time in symbols */
#define ATM_MAC_154_SYMBOLS_PER_SHR \
    (ATM_MAC_154_SYMBOLS_PER_PREAMBLE + ATM_MAC_154_SYMBOLS_PER_SFD)
/** Synchronization header time in microseconds */
#define ATM_MAC_154_SHR_TIME_US \
    (ATM_MAC_154_SYMBOL_TIME_US * ATM_MAC_154_SYMBOLS_PER_SHR)
/** ACK wait time in microseconds*/
#define ATM_MAC_154_ACK_WAIT_TIME_US \
    (ATM_MAC_154_BACKOFF_PERIOD_TIME_US + ATM_MAC_154_SHR_TIME_US)
/** CCA window in symbols */
#define ATM_MAC_154_SYMBOLS_PER_CCA_WINDOW 8
/** CCA window in microseconds */
#define ATM_MAC_154_CCA_WINDOW_TIME_US \
    (ATM_MAC_154_SYMBOL_TIME_US * ATM_MAC_154_SYMBOLS_PER_CCA_WINDOW)
/** Minimum margin to rearm RX in microseconds */
#define ATM_MAC_154_REARM_MARGIN_US 10
/**@}*/

/** @name ATLC Specific constants
 * @{
 */
/* Offset after RX packet to RSSI value */
#define ATM_MAC_154_RSSI_OFFSET 0
/* Invalid RSSI value */
#define ATM_MAC_154_RSSI_INVALID 127
/* Offset after RX packet to appended status byte */
#define ATM_MAC_154_APPENDED_STATUS_OFFSET 1
/** RX power up time in microseconds */
#define ATM_MAC_154_RX_PWRUP_US \
    ATLC_PWRUD_250KBPS_154__RX_PWRUP__READ( \
	CMSDK_ATLC_NONSECURE->PWRUD_250KBPS_154)
/** RX sync word delay in microseconds */
#define ATM_MAC_154_RX_SFD_PTHDLY_US \
    ATLC_PTHDLY_SW_154__RX_250KBPS__READ(CMSDK_ATLC_NONSECURE->PTHDLY_SW_154)
/** TX power up time in microseconds */
#define ATM_MAC_154_TX_PWRUP_US \
    ATLC_PWRUD_250KBPS_154__TX_PWRUP__READ( \
	CMSDK_ATLC_NONSECURE->PWRUD_250KBPS_154)
/** TX power down time in microseconds */
#define ATM_MAC_154_TX_PWRDN_US \
    ATLC_PWRUD_250KBPS_154__TX_PWRDN__READ( \
	CMSDK_ATLC_NONSECURE->PWRUD_250KBPS_154)
/** Convert RX timestamp from FRC to ATLC timebase */
#define ATM_MAC_154_RX_FRC_TO_ATLC_US(x) ((x) + ATM_MAC_154_RX_PWRUP_US)
/** Convert RX timestamp from ATLC to FRC timebase */
#define ATM_MAC_154_RX_ATLC_TO_FRC_US(x) ((x) - ATM_MAC_154_RX_PWRUP_US)
/** Convert RX timestamp from FRC to ATLC timebase */
#define ATM_MAC_154_RX_FRC_TO_ATLC_US_CACHED(x, delays) \
    ((x) + ATLC_PWRUD_250KBPS_154__RX_PWRUP__READ(delays))
/** Convert RX timestamp from ATLC to FRC timebase */
#define ATM_MAC_154_RX_ATLC_TO_FRC_US_CACHED(x, delays) \
    ((x) - ATLC_PWRUD_250KBPS_154__RX_PWRUP__READ(delays))
/** Convert TX timestamp from FRC to ATLC timebase */
#define ATM_MAC_154_TX_FRC_TO_ATLC_US(x) ((x) + ATM_MAC_154_TX_PWRUP_US)
/** Convert TX timestamp from ATLC to FRC timebase */
#define ATM_MAC_154_TX_ATLC_TO_FRC_US(x) ((x) - ATM_MAC_154_TX_PWRUP_US)
/** Convert TX timestamp from FRC to ATLC timebase */
#define ATM_MAC_154_TX_FRC_TO_ATLC_US_CACHED(x, delays) \
    ((x) + ATLC_PWRUD_250KBPS_154__TX_PWRUP__READ(delays))
/** Convert TX timestamp from ATLC to FRC timebase */
#define ATM_MAC_154_TX_ATLC_TO_FRC_US_CACHED(x, delays) \
    ((x) - ATLC_PWRUD_250KBPS_154__TX_PWRUP__READ(delays))
/**@}*/

/** @name ACK constants
 * @{
 */
/** Acknowledgement (Imm-Ack) frame length */
#define ATM_MAC_154_ACK_LEN \
    (ATM_MAC_154_FRAME_CONTROL_LEN + ATM_MAC_154_SEQ_NUM_LEN + \
	ATM_MAC_154_FCS_LEN)
/** Acknowledgement (Imm-Ack) frame buffer length */
#define ATM_MAC_154_ACK_BUFFER_LEN \
    (ATM_MAC_154_FRAME_CONTROL_LEN + ATM_MAC_154_SEQ_NUM_LEN + \
	ATM_MAC_154_PHR_LEN)
/** Acknowledgement TX descriptor - points to ACK TCM adddress */
#define ATM_MAC_154_ACK_TX_DESCRIPTOR \
    ((ACK_154_BUFFER_TCM_OFFSET << 16) | ATM_MAC_154_ACK_BUFFER_LEN)
/** Acknowledgement frame control field without frame pending */
#define ATM_MAC_154_ACK_FCF_NO_FRAME_PENDING 0x02U
/** Acknowledgement frame control field with frame pending */
#define ATM_MAC_154_ACK_FCF_FRAME_PENDING 0x12U

/** Enhanced Ack Information Element (IE) overhead length */
#define ATM_MAC_154_ENH_ACK_IE_HEADER_LEN 2
/** Enhanced Ack Coordinated Sampled Listening (CSL) IE content length */
#define ATM_MAC_154_ENH_ACK_IE_CSL_CONTENT_LEN 4
/** Enhanced Ack CSL IE total length */
#define ATM_MAC_154_ENH_ACK_IE_CSL_LEN \
    (ATM_MAC_154_ENH_ACK_IE_HEADER_LEN + ATM_MAC_154_ENH_ACK_IE_CSL_CONTENT_LEN)
/** Enhanced Ack offset for CSL phase when Ack only contains the CSL IE */
#define ATM_MAC_154_ENH_ACK_IE_CSL_PHASE_OFFSET \
    (ATM_MAC_154_ACK_LEN + ATM_MAC_154_ENH_ACK_IE_HEADER_LEN)
/** Enhanced Ack total length when Ack only contains the CSL IE */
#define ATM_MAC_154_ENH_ACK_LEN \
    (ATM_MAC_154_ACK_LEN + ATM_MAC_154_ENH_ACK_IE_CSL_LEN)
/** Enhanced Ack buffer length when Ack only contains the CSL IE */
#define ATM_MAC_154_ENH_ACK_BUFFER_LEN \
    (ATM_MAC_154_ACK_BUFFER_LEN + ATM_MAC_154_ENH_ACK_IE_CSL_LEN)

/**@}*/

/**
 * @brief RX complete info
 *
 * Contains relevant information about a RX transaction
 *
 * @note In situations with elevated latency, it is possible for fp_set to
 * be false when the ACK packet did go out with frame pending set
 */
typedef struct {
    uint32_t timestamp; /*!< The arrival time of the SFD in us */
    int8_t rssi; /*!< The receive signal strength indication for the packet */
    uint8_t lqi; /*!< The link quality indication for the packet */
    bool ack_sent; /*!< True if ack was sent */
    bool fp_set; /*!< True if ack was sent with frame pending set */
} atm_mac_154_rx_complete_info_t;

/**
 * @brief TX complete info
 *
 * Contains relevant information about a TX transaction
 */
typedef struct {
    uint8_t const *ack_buffer; /*!< Pointer to ack buffer */
    uint32_t timestamp; /*!< The start time of the preamble in microseconds */
    uint32_t ack_timestamp; /*!< The arrival time of the ack SFD in us */
    bool ack_received; /*!< True if ack was received */
    int8_t ack_rssi; /*!< The receive signal strength indication for the ack */
    uint8_t ack_lqi; /*!< The link quality indication for the ack */
} atm_mac_154_tx_complete_info_t;

/**
 * @brief 15.4 Driver State
 */
typedef enum {
    ATM_MAC_154_STATE_UNINIT = 0, /*!< Driver uninitialized */
    ATM_MAC_154_STATE_ERROR, /*!< Driver has errored */
    ATM_MAC_154_STATE_DISABLE_AND_SLEEP, /*!< Both DISABLE and SLEEP apply */
    ATM_MAC_154_STATE_SLEEP, /*!< ATLC is asleep */
    // ATLC registers may only be accessed when state is greater than SLEEP
    ATM_MAC_154_STATE_DISABLE, /*!< Initialized, but not enabled */
    ATM_MAC_154_STATE_IDLE, /*!< Idle */
    ATM_MAC_154_STATE_TX, /*!< In TX transaction */
    ATM_MAC_154_STATE_TX_WAITING_FOR_ACK, /*!< Waiting for ACK after TX */
    ATM_MAC_154_STATE_TX_CARRIER_WAVE, /*!< Transmitting carrier wave */
    ATM_MAC_154_STATE_TX_SYMBOL_STREAM, /*!< Transmitting symbol stream */
    ATM_MAC_154_STATE_RX, /*!< In RX transaction */
    ATM_MAC_154_STATE_RX_WAITING_FOR_ADDR, /*!< Currently unused */
    ATM_MAC_154_STATE_RX_WAITING_FOR_CRC, /*!< Currently unused */
    ATM_MAC_154_STATE_RX_SENDING_ACK, /*!< Currently unused */
    ATM_MAC_154_STATE_RX_ENERGY_DETECT, /*!< In energy detect mode */
} atm_mac_154_state_t;

/**
 * @brief 15.4 Frame Control Field - Frame Type
 */
typedef enum {
    ATM_MAC_154_FRAME_TYPE_BEACON = 0, /*!< Beacon type */
    ATM_MAC_154_FRAME_TYPE_DATA = 1, /*!< Data type */
    ATM_MAC_154_FRAME_TYPE_ACK = 2, /*!< Acknowledgement type */
    ATM_MAC_154_FRAME_TYPE_CMD = 3, /*!< Command type */
    ATM_MAC_154_FRAME_TYPE_MULTIPURPOSE = 5, /*!< Multipurpose type */
    ATM_MAC_154_FRAME_TYPE_FRAGMENT = 6, /*!< Fragment or Frak type */
    ATM_MAC_154_FRAME_TYPE_EXTENDED = 7, /*!< Extended type */
} atm_mac_154_frame_type_t;

/**
 * @brief 15.4 Frame Control Field - Frame Version
 */
typedef enum {
    ATM_MAC_154_FRAME_VERSION_2003 = 0, /*!< 2003 Version */
    ATM_MAC_154_FRAME_VERSION_2006 = 1, /*!< 2006 Version */
    ATM_MAC_154_FRAME_VERSION_2015 = 2, /*!< 2015 Version */
} atm_mac_154_frame_version_t;

/**
 * @brief 15.4 Frame Control Field - Frame Version
 */
typedef enum {
    ATM_MAC_154_VERSION_IEEE_2006, /* IEEE 802.15.4 2006 */
    ATM_MAC_154_VERSION_IEEE_2015, /* IEEE 802.15.4 2015 */
    ATM_MAC_154_VERSION_THREAD_1_3_TL1, /* Thread 1.3.0 Link Type 1 */
    ATM_MAC_154_VERSION_THREAD_1_3_TL2, /* Thread 1.3.0 Link Type 2 */
} atm_mac_154_version_t;

/**
 * @brief 15.4 Frame Control Field - Addressing mode
 */
typedef enum {
    ATM_MAC_154_ADDR_MODE_NONE = 0, /*!< No address */
    ATM_MAC_154_ADDR_MODE_INVALID = 1, /*!< Invalid addr mode field */
    ATM_MAC_154_ADDR_MODE_SHORT = 2, /*!< Short address */
    ATM_MAC_154_ADDR_MODE_LONG = 3, /*!< Long address */
} atm_mac_154_addr_mode_t;

/**
 * @brief 15.4 Frame Control Field structure
 *
 * Struct must be packed to be contained within 2 byte length
 */
typedef struct __PACKED {
    atm_mac_154_frame_type_t frame_type : 3;
    uint8_t security_enabled : 1;
    uint8_t frame_pending : 1;
    uint8_t ack_request : 1;
    uint8_t pan_id_compression : 1;
    uint8_t rsvd_1 : 1;
    uint8_t rsvd_2 : 1;
    uint8_t ie_present : 1;
    atm_mac_154_addr_mode_t dest_addr_mode : 2;
    atm_mac_154_frame_version_t frame_version : 2;
    atm_mac_154_addr_mode_t source_addr_mode : 2;
} atm_mac_154_frame_control_t;

/**
 * @brief 15.4 header information
 *
 * This packed structure is laid out carefully so that all of the members are
 * aligned on 32-bit platforms, and so that it can be populated with the
 * information from the packet in at most 2 contiguous copies.
 */
typedef struct __PACKED __ALIGN4 {
    uint16_t padding_0;
    uint8_t len;
    atm_mac_154_frame_control_t frame_control;
    uint8_t seq_num;
    uint16_t dest_pan;
    union {
	uint64_t long_addr;
	uint16_t short_addr;
    } dest_addr;
    uint16_t padding_1;
    uint16_t source_pan;
    union {
	uint64_t long_addr;
	uint16_t short_addr;
    } source_addr;
} atm_mac_154_header_t;

/**
 * @brief 15.4 device mode
 *
 * A full-function device (FFD) can operate in any of these modes. A reduced-
 * function device (RFD) may only operate in device mode.
 */
typedef enum {
    ATM_MAC_154_MODE_DEVICE = 0, /*!< A device, either FFD or RFD */
    ATM_MAC_154_MODE_COORDINATOR, /*!< A coordinator, must be FFD */
    ATM_MAC_154_MODE_PAN_COORDINATOR, /*!< A PAN coordinator, must be FFD */
    ATM_MAC_154_MODE_NUM,
} atm_mac_154_device_mode_t;

/**
 * @brief Transmit CSMA mode
 */
typedef enum {
    ATM_MAC_154_TX_CSMA_MODE_DISABLED = 0, /*!< No CSMA or CCA */
    ATM_MAC_154_TX_CSMA_MODE_CCA_ONLY, /*!< Use CCA */
    ATM_MAC_154_TX_CSMA_MODE_ENABLED, /*!< Use CSMA */
    ATM_MAC_154_TX_CSMA_MODE_NUM /*!< CSMA mode count */
} atm_mac_154_tx_csma_mode_t;

/** @name Callback definitions
 * Callbacks related to TX/RX completion, frame pending check,
 * and energy detect.
 */

/**@{*/
/**
 * @brief Signature of callback function for energy detect complete event.
 * The driver will call a function of this type to signal that a
 * completion event associated with an energy detect operation has occurred.
 *
 * @note This function is called from interrupt context.
 * @param[in] rssi The measured RSSI. A value of @ref ATM_MAC_154_RSSI_INVALID
 * will be provided if the measurement was unsuccessful.
 */
typedef void (*atm_mac_154_energy_detection_complete_handler_t)(int8_t rssi);

/**
 * @brief Signature of callback function issued at receive transaction
 * completion.
 *
 * The driver will call a function of this type to signal that a
 * completion event associated with a receive transaction has occurred.
 *
 * When the function of this type is called, the packet data will
 * already have been copied to the address provided in the earlier
 * call to atm_mac_154_receive_packet().
 *
 * @note This function is called from interrupt context.
 *
 * @param[in] status @ref atm_mac_status_t completion status
 * for this receive transaction.
 * @param[in] info pointer to @ref atm_mac_154_rx_complete_info_t struct for
 * this receive transaction.
 */
typedef void (*atm_mac_154_rx_complete_handler_t)(atm_mac_status_t status,
    atm_mac_154_rx_complete_info_t const *info);

/**
 * @brief Signature of callback function for long address received event.
 * The driver will call a function of this type to signal
 * that the long address field has been received.
 *
 * The callee is expected to perform a lookup operation to determine
 * if there is data pending for the device with this address.
 *
 * @note This function is called from interrupt context.
 * @param[in] address The long address of the device.
 * @return true if data is pending for device with address,
 * false otherwise.
 */
typedef bool (*atm_mac_154_rx_long_addr_pend_handler_t)(uint64_t address);

/**
 * @brief Signature of callback function for short address received event.
 * The driver will call a function of this type to signal
 * that the short address field has been received.
 *
 * The callee is expected to perform a lookup operation to determine
 * if there is data pending for the device with this address.
 *
 * @note This function is called from interrupt context.
 * @param[in] address The short address of the device.
 * @return true if data is pending for device with address,
 * false otherwise.
 */
typedef bool (*atm_mac_154_rx_short_addr_pend_handler_t)(uint16_t address);

/**
 * @brief Signature of callback function issued at transmit transaction
 * completion.
 *
 * The driver will call a function of this type to signal that a
 * completion event associated with a transmit transaction has occurred.
 *
 * @note This function is called from interrupt context.
 * @param[in] status @ref atm_mac_status_t completion status
 * for this transmit transaction.
 * @param[in] info pointer to @ref atm_mac_154_tx_complete_info_t struct for
 * this transmit transaction.
 */
typedef void (*atm_mac_154_tx_complete_handler_t)(atm_mac_status_t status,
    atm_mac_154_tx_complete_info_t const *info);
/**@}*/

/** @name General functions
 * Functions related to inititalizion, general configuration, and state.
 */

/**@{*/

/**
 * @brief De-initialize 15.4 resources.
 * This function will clean up and de-initialize any resources required
 * for 15.4 activity.
 */
void atm_mac_154_deinit(void);

/**
 * @brief Disable 15.4 mode of radio operation.
 * This function will disable the radio for 15.4 operations.
 * @note This function is called from interrupt context.
 */
void atm_mac_154_disable(void);

/**
 * @brief Enable 15.4 mode of radio operation.
 * This function will enable the radio for 15.4 operations.
 * @note This function is called from interrupt context.
 */
void atm_mac_154_enable(void);

/**
 * @brief Initialize 15.4 resources.
 * This function will perform any one-time initialization of resources
 * required for 15.4 activity.
 * @note This function must be called before any other function in this module.
 * @note This function is called from interrupt context.
 */
void atm_mac_154_init(void);

/**
 * @brief Set 15.4 protocol version
 * This function will perform configure the driver to operate as a specific
 * version of 15.4. If this function is not called, the driver will behave
 * as if ATM_MAC_154_VERSION_IEEE_2006 was configured.
 * @param[in] version The specification used for radio behavior
 */
void atm_mac_154_set_version(atm_mac_154_version_t version);

/**
 * @brief Get radio driver state.
 * @note This function is called from interrupt context.
 * @return Enumerated driver state.
 */
atm_mac_154_state_t atm_mac_154_get_state(void);

/**
 * @brief Register callback function for receive completion events.
 * @par
 * @note This function is used to register a callback function.
 * @par
 * @note The driver will call the registered callback function to signal
 * completion events related to earlier receive API calls.
 * @par
 * @note This function is called from interrupt context.
 * @par
 * @note The callback function is called from interrupt context.
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(1)
void atm_mac_154_register_rx_complete_callback(
    atm_mac_154_rx_complete_handler_t handler);

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
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(1)
void atm_mac_154_register_rx_long_addr_callback(
    atm_mac_154_rx_long_addr_pend_handler_t handler);

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
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(1)
void atm_mac_154_register_rx_short_addr_callback(
    atm_mac_154_rx_short_addr_pend_handler_t handler);

/**
 * @brief Register callback function for transmit completion events.
 * @note This function is used to register a callback function.
 * @par
 * @note The driver will call the registered callback function to signal
 * completion events related to earlier transmit API calls.
 * @par
 * @note This function is called from interrupt context.
 * @par
 * @note The callback function is called from interrupt context.
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(1)
void atm_mac_154_register_tx_complete_callback(
    atm_mac_154_tx_complete_handler_t handler);

/**
 * @brief Register callback function for energy detection completion events.
 * @note This function is used to register a callback function.
 * @par
 * @note The driver will call the registered callback function to signal
 * completion events related to earlier energy detection API calls.
 * @par
 * @note This function is called from interrupt context.
 * @par
 * @note The callback function is called from interrupt context.
 * @param[in] handler The callback function to be registered.
 */
__NONNULL(1)
void atm_mac_154_register_energy_detection_complete_callback(
    atm_mac_154_energy_detection_complete_handler_t handler);

/**@}*/

/** @name PHY configuration functions
 * Functions related to configuration and state of the Physical Layer.
 */

/**@{*/

/**
 * @brief Provides the currently configured 15.4 channel.
 * @note This function is called from interrupt context.
 * @return The currently configured 15.4 2.4GHz channel (11-26).
 */
uint8_t atm_mac_154_get_channel(void);

/**
 * @brief Provides the currently configured tx power level.
 * @note This function is called from interrupt context.
 * @return The currently configured tx power level in dBm.
 */

int8_t atm_mac_154_get_tx_power(void);

/**
 * @brief Configures the radio to operate on a standard 15.4 channel.
 * @note Invalid channels are ignored.
 * @note This function will defer changes until radio is idle.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] channel A standard 15.4 channel (11-26) in the 2.4 GHz band.
 */
void atm_mac_154_set_channel(uint8_t channel);

/**
 * @brief Configures the radio to operate at an available tx power.
 * @note If an exact power level is not available, the closest lower
 * power level will be selected.
 * @note This function will defer changes until radio is idle.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] tx_power A power level in dBm.
 */
void atm_mac_154_set_tx_power(int8_t tx_power);

/**@}*/

/** @name MAC configuration functions - Address Filtering
 * Functions related to configuration and state of the MAC Layer
 * address filtering capabilities.
 */

/**@{*/

/**
 * @brief Indicates which mode is being operated in
 * @note This function is called from interrupt context.
 * @return The mode being operated in
 */
atm_mac_154_device_mode_t atm_mac_154_get_device_mode(void);

/**
 * @brief Operate in the given mode for address filtering and FP checks
 * @note This function is called from interrupt context.
 * @param[in] mode Mode to operate in
 */
void atm_mac_154_set_device_mode(atm_mac_154_device_mode_t mode);

/**
 * @brief Gets the long address to be used in MAC address filtering.
 * @note This function is called from interrupt context.
 * @return The long address.
 */
uint64_t atm_mac_154_get_long_addr(void);

/**
 * @brief Gets the short address to be used in MAC address filtering.
 * @note This function is called from interrupt context.
 * @return The short address.
 */
uint16_t atm_mac_154_get_short_addr(void);

/**
 * @brief Gets the PAN Id to be used in MAC address filtering.
 * @note This function is called from interrupt context.
 * @return The PAN identifier.
 */
uint16_t atm_mac_154_get_pan_id(void);

/**
 * @brief Sets the long address to be used in MAC address filtering.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] long_addr The long address.
 */
void atm_mac_154_set_long_addr(uint64_t long_addr);

/**
 * @brief Sets the short address to be used in MAC address filtering.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] short_addr The short address.
 */
void atm_mac_154_set_short_addr(uint16_t short_addr);

/**
 * @brief Sets the PAN Id to be used in MAC address filtering.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] pan_id The PAN identifier.
 */
void atm_mac_154_set_pan_id(uint16_t pan_id);

/**@}*/

/** @name MAC configuration functions - Channel Access
 * Functions related to configuration and state of the MAC Layer CSMA
 * and retry subsytems.
 */

/**@{*/

/**
 * @brief Gets the threshold for the MAC CCA transmit operation.
 * @note This function is called from interrupt context.
 * @return The CCA threshold in dBm.
 */
int8_t atm_mac_154_get_cca_threshold(void);

/**
 * @brief Gets the maximum CSMA MAC backoff exponent.
 * @note This function is called from interrupt context.
 * @return The maximum backoff exponent.
 */
int8_t atm_mac_154_get_max_csma_backoff_exponent(void);

/**
 * @brief Gets the maximum number of CSMA transmit attempts.
 * @note This function is called from interrupt context.
 * @return The maximum number CSMA transmit attempts.
 */
int8_t atm_mac_154_get_max_csma_attempts(void);

/**
 * @brief Gets the number of MAC transmit retries.
 * This quantity is the total number of times a packet will be
 * retransmitted in an effort to receive a requested Ack.
 * @note This function is called from interrupt context.
 * @return The maximum number of MAC tx retries.
 */
int8_t atm_mac_154_get_max_transmit_retries(void);

/**
 * @brief Gets the minimum CSMA MAC backoff exponent.
 * @return The minimum backoff exponent.
 */
int8_t atm_mac_154_get_min_csma_backoff_exponent(void);

/**
 * @brief Sets the threshold for the MAC CCA transmit operation.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] cca_threshold_dbm The CCA threshold in dBm.
 */
void atm_mac_154_set_cca_threshold(int8_t cca_threshold_dbm);

/**
 * @brief Sets the maximum CSMA MAC backoff exponent.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] max_be The maximum backoff exponent.
 */
void atm_mac_154_set_max_csma_backoff_exponent(int8_t max_be);

/**
 * @brief Sets the maximum number of CSMA transmit attempts.
 * @note This quantity is separate from MAC retries.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] max_csma_attempts The maximum number CSMA transmit attempts.
 */
void atm_mac_154_set_max_csma_attempts(int8_t max_csma_attempts);

/**
 * @brief Sets the number of MAC transmit retries.
 * @note This quantity is separate from CCA attempts.
 * @note This function will defer changes until radio is idle.
 * This quantity is the total number of times a packet will be
 * retransmitted in an effort to receive a requested Ack.
 * @note This function is called from interrupt context.
 * @param[in] max_tx_retries The maximum number of MAC tx retries.
 */
void atm_mac_154_set_max_transmit_retries(int8_t max_tx_retries);

/**
 * @brief Sets the minimum CSMA MAC backoff exponent.
 * @note This function will defer changes until radio is idle.
 * @note This function is called from interrupt context.
 * @param[in] min_be The minimum backoff exponent.
 */
void atm_mac_154_set_min_csma_backoff_exponent(int8_t min_be);

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
 * @param[in] rssi The RSSI on which to base the conversion, in dBm.
 * @return 0 for worst link quality, 0xff for best link quality, and
 * proportionally spaced values in between.
 */
uint8_t atm_mac_154_map_rssi_to_lqi(int8_t rssi);

/**
 * @brief Performs an energy detection reading on the current channel.
 *
 * This function will enter a receive mode where no packets can be received.
 * After ATM_MAC_154_CCA_WINDOW_TIME_US of sampling the channel, the radio will
 * return to an idle state. The registered handler will then be called from
 * interrupt context with the detected energy over the window.
 * @note This function is called from interrupt context.
 */
void atm_mac_154_perform_energy_detection(void);

/**
 * @brief Performs an energy detection reading on the current channel.
 *
 * Same as atm_mac_154_perform_energy_detection() but with the sampling
 * duration specified by the caller.
 * @note This function is called from interrupt context.
 * @param[in] window_us Duration in microseconds.  Must not be 0.
 */
void atm_mac_154_perform_energy_detection_timed(uint32_t window_us);

/**
 * @brief Receives a packet using the current radio configuration.
 *
 * This function will initiate reception of a packet using the
 * current radio configuration as defined by previous calls to PHY and MAC
 * configuration functions. Portions of the processing described here occur
 * outside of the scope of this function, either handled by hardware or by
 * software triggered by asynchronous timer and radio events.
 *
 * The system will schedule a window during which reception is possible,
 * starting at @p start_time microseconds and remaining open for @p duration
 * microseconds.
 *
 * The system will automatically calculate the 16-bit CRC for the received
 * packet and compare it to the value appended, unless non-standard
 * configuration has been applied via @ref atm_mac_154_disable_auto_crc.
 * Packets which do not have correct CRC value are discarded and receive
 * processing is automatically continued by the system for the remainder
 * of the @p duration.
 *
 * The system will perform address filtering on received packets, unless
 * non-standard configuration has been applied via @ref
 * atm_mac_154_disable_address_filtering. The system will perform address
 * filtering according to the configuration defined by previous calls to
 * @ref atm_mac_154_set_pan_id, @ref atm_mac_154_set_short_addr,
 * @ref atm_mac_154_set_long_addr, and @ref
 * atm_mac_154_set_device_mode. Packets which do not satisfy
 * address filtering requirements are discarded and receive processing
 * is automatically continued by the system for the remainder of the
 * @p duration.
 *
 * For certain packets which have passed active address filtering, and
 * which have requested an acknowledgement, the system will
 * query the higher layer of the stack for frame pending information via
 * either the function previously registered using @ref
 * atm_mac_154_register_rx_short_addr_callback or the function previously
 * registered using @ref atm_mac_154_register_rx_long_addr_callback.
 * The system will call the appropriate function based on which destination
 * address field is present in the packet.
 * The return value from the callback function will be used in the
 * eventual acknowledgement, if it is sent.
 *
 * If the packet has requested an acknowledgement, passed address filtering,
 * and passed CRC, the system will generate and transit an appropriate
 * acknowledgement, unless non-standard configuration has been applied
 * via @ref atm_mac_154_disable_auto_ack.
 *
 * @note The system will not attempt to manage receiver power status beyond
 * the active receive window.
 *
 * If the receive window @p duration expires without a packet being
 * successfully received (fully satisfying all applicable filtering,
 * checksum, and acknowledgement requirements), the completion status will
 * be @ref ATM_MAC_154_RX_COMPLETE_STATUS_FAIL_TIMEOUT.
 *
 * If a packet is successfully received (fully satisfying all applicable
 * filtering, checksum, and acknowledgement requirements), the completion
 * status will be @ref ATM_MAC_154_RX_COMPLETE_STATUS_SUCCESS.
 *
 * If the receive  @p start_time is scheduled in the past, the completion
 * handler will be called immediately with status
 * @ref ATM_MAC_154_RX_COMPLETE_STATUS_FAIL_PAST.
 *
 * The completion status of the receive event initiated by this function
 * will be reported asynchronously (and in interrupt context) by the
 * @ref atm_mac_status_t parameter of the callback function
 * registered via @ref atm_mac_154_register_rx_complete_callback. If the
 * receive transaction is successful, the @ref atm_mac_154_rx_complete_info_t
 * parameter will contain additional information such as rssi and start time.
 *
 * @note This function is called from interrupt context.
 *
 * @param[in,out] packet The packet data. Caller must ensure there are
 * @ref MAX_154_PACKET_LEN bytes available. Note that under normal
 * operation the maximum length will be less two CRC bytes unless disabled
 * with @ref atm_mac_154_disable_auto_crc
 * @param[in] start_time The earliest time at which to expect SFD. If @p
 * start_time is specified as 0, the receive operation will be started
 * immediately
 * @param[in] duration The duration to wait for SFD. If @p duration is
 * specified as 0, the receive operation will continue indefinitely until
 * a packet is successfully received or the operation is stopped using
 * @ref atm_mac_154_stop.
 */
__NONNULL(1)
void atm_mac_154_receive_packet(uint8_t *packet, uint32_t start_time,
    uint32_t duration);

/**
 * @brief Stops current radio activity.
 *
 * This function will stop any ongoing receive or transmit operation.
 *
 * @note This function might block for a period of time to allow the radio
 * to return an idle state.
 *
 * @note This function is called from interrupt context.
 */
void atm_mac_154_stop(void);

/**
 * @brief Fill in TX packet header
 *
 * This function will assemble the MAC header.
 *
 * @param[out] packet The buffer to place the header into
 * @param[in] packet_len The length of packet. Will stop writing once full
 * @param[in] fc The frame control fields for the outgoing packet
 * @param[in] seq_num The sequence number for the outgoing packet
 * @param[in] dest_addr The address of the destination node
 * @param[in] dest_pan_id The PAN ID of the destination node
 * @param[in] source_addr The address of the source node
 * @param[in] source_pan_id The PAN ID of the source node
 */
__NONNULL(1, 5, 6, 7, 8)
uint8_t atm_mac_154_gen_packet_header(uint8_t *packet, uint8_t packet_len,
    atm_mac_154_frame_control_t fc, uint8_t seq_num, uint8_t const *dest_addr,
    uint8_t const *dest_pan_id, uint8_t const *source_addr,
    uint8_t const *source_pan_id);

/**
 * @brief Alternate method to fill in TX packet header
 *
 * This function will assemble the MAC header. It will add the PAN IDs based
 * on whether the pointers are non-NULL, allowing odd and invalid combinations
 * of frame version, addressing modes, and PAN ID compression to be specified.
 *
 * @param[out] packet The buffer to place the header into
 * @param[in] packet_len The length of packet. Will stop writing once full
 * @param[in] fc The frame control fields for the outgoing packet
 * @param[in] seq_num The sequence number for the outgoing packet
 * @param[in] dest_addr The address of the destination node
 * @param[in] dest_pan_id The PAN ID of the destination node. NULL to omit.
 * @param[in] source_addr The address of the source node
 * @param[in] source_pan_id The PAN ID of the source node. NULL to omit.
 */
__NONNULL(1)
uint8_t atm_mac_154_populate_packet_header(uint8_t *packet, uint8_t packet_len,
    atm_mac_154_frame_control_t fc, uint8_t seq_num, uint8_t const *dest_addr,
    uint8_t const *dest_pan_id, uint8_t const *source_addr,
    uint8_t const *source_pan_id);

/**
 * @brief Transmits a packet using the current radio configuration.
 *
 * This function will initiate transmission of a packet using the
 * current configuration as defined by previous calls to PHY and MAC
 * configuration functions. Portions of the processing described here occur
 * outside of the scope of this function, either handled by hardware or by
 * software triggered by asynchronous timer and radio events.
 *
 * The system will automatically calculate and append a 16-bit CRC, unless
 * non-standard configuration has been applied via
 * @ref atm_mac_154_disable_auto_crc.
 *
 * If @p csma_mode is disabled and @p delay is false, the system will transmit
 * the packet immediately.
 *
 * If the @p delay parameter is true, the system will transmit the
 * packet at the provided @p start_time.
 *
 * If the @p csma_mode parameter is @ref ATM_MAC_154_TX_CSMA_MODE_ENABLED,
 * the system will perform the CSMA algorithm in an attempt to access the
 * channel.
 * The system will perform the CSMA algorithm starting from the backoff
 * exponent set via @ref atm_mac_154_set_min_csma_backoff_exponent.
 * If CCA is reported busy,
 * the system will repeatedly continue the CSMA algorithm as necessary
 * until either CCA is reported clear, or the attempt limit set via
 * @ref atm_mac_154_set_max_csma_attempts is reached.
 * During this process the backoff exponent used will not exceeed the value
 * set via @ref atm_mac_154_set_max_csma_backoff_exponent. If the system
 * is unable to access the channel due to CCA busy on all attempts,
 * the completion status will be @ref ATM_MAC_154_TX_COMPLETE_STATUS_FAIL_CCA.
 *
 * If the @p csma_mode parameter is @ref ATM_MAC_154_TX_CSMA_MODE_CCA_ONLY,
 * the system will only perform a CCA check prior to transmit. If the CCA check
 * fails, the completion status will be
 * @ref ATM_MAC_154_TX_COMPLETE_STATUS_FAIL_CCA.
 *
 * If the @p csma_mode and @p delay parameters are both enabled, the system
 * will perform the CSMA/CCA algorithm as above, starting at the provided
 * @p start_time.
 *
 * If a 15.4 acknowledgement is requested in the @p packet, the system
 * will enable the receiver and wait for the acknowledgement to arrive,
 * unless non-standard configuration has been applied via
 * @ref atm_mac_154_disable_wait_for_ack.
 * If an expected 15.4 acknowledgement is not received, the system will
 * retry the transmission up to the limit defined via @ref
 * atm_mac_154_set_max_transmit_retries. If the system does not receive
 * a requested acknowledgement after using all retries, the completion
 * status will be @ref ATM_MAC_154_TX_COMPLETE_STATUS_FAIL_NO_ACK.
 *
 * If any other general problems are encountered in transmitting the packet,
 * the completion status will be @ref ATM_MAC_154_TX_COMPLETE_STATUS_FAIL.
 *
 * If the packet is transmitted successfully, including all optional CSMA
 * and acknowledgement processing, the completion status will be
 * @ref ATM_MAC_154_TX_COMPLETE_STATUS_SUCCESS.
 *
 * The completion status of the transmit event initiated by this function
 * will be reported asynchronously (and in interrupt context) by the
 * atm_mac_status_t parameter of the callback function
 * registered via @ref atm_mac_154_register_tx_complete_callback. If the
 * transmit transaction is successful, the @ref atm_mac_154_tx_complete_info_t
 * parameter will contain additional information such as start time and a
 * pointer to the ack buffer.
 *
 * @note This function is called from interrupt context.
 *
 * @param[in] packet The packet data.
 * @param[in] csma_mode Transmit CSMA mode
 * @param[in] delay Start the transmit at the provided start_time if true.
 * @param[in] start_time The time to start the transmit. Ignored if delay
 *   is false.
 */
__NONNULL(1)
void atm_mac_154_transmit_packet(uint8_t const *packet,
    atm_mac_154_tx_csma_mode_t csma_mode, bool delay, uint32_t start_time);

/**
 * @brief Sets up a packet to be transmitted with manual retries available
 *
 * This function sets up the hardware for a transmit, without actually
 * triggering the transmit. See @ref atm_mac_154_retry_transmit for the
 * function to start the transmit after setting it up here, and
 * @ref atm_mac_154_transmit_packet for more information on the driver
 * settings which can affect transmits.
 *
 * @param[in] packet_len The length of the packet parameter
 * @param[in] packet The packet data.
 * @param[in] csma_mode Transmit CSMA mode
 * @param[in] delay Start the transmit at the provided start_time if true.
 * @param[in] start_time The time to start the transmit. Ignored if delay
 *   is false.
 */
__NONNULL(2)
void atm_mac_154_setup_transmit(uint8_t packet_len, uint8_t const *packet,
    atm_mac_154_tx_csma_mode_t csma_mode, bool delay, uint32_t start_time);

/**
 * @brief Triggers a manual transmit retry
 *
 * This function will initiate transmission of a packet using the
 * current configuration as defined by previous calls to PHY and MAC
 * configuration functions, as well as a prior call to
 * @ref atm_mac_154_setup_transmit. Portions of the processing described here
 * occur outside of the scope of this function, either handled by hardware or
 * by software triggered by asynchronous timer and radio events.
 *
 * While this transmit is ongoing, higher levels can consume a MAC retry by
 * calling @ref atm_mac_154_stop, and then calling this function again. This
 * should be done in cases where the higher level knows that there will be
 * interference on the air during the transmit window.
 *
 * The completion status of the transmit event initiated by this function
 * will be reported asynchronously (and in interrupt context) by the
 * atm_mac_status_t parameter of the callback function
 * registered via @ref atm_mac_154_register_tx_complete_callback. If the
 * transmit transaction is successful, the @ref atm_mac_154_tx_complete_info_t
 * parameter will contain additional information such as start time and a
 * pointer to the ack buffer.
 *
 * For more details see documentation of @ref atm_mac_154_transmit_packet, and
 * @ref atm_mac_154_setup_transmit.
 *
 * @return True if a transmit was initiated, false if no more retries remain.
 */
bool atm_mac_154_retry_transmit(void);

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
 * @param[in] activate tx of carrier if true, deactivate if false.
 */
void atm_mac_154_activate_carrier_wave(bool activate);

/**
 * @brief Starts transmission of modulated symbol stream.
 * @note In normal MAC operation, this function is not called.
 * @par
 * @note The function @ref atm_mac_154_get_state will return
 * @ref ATM_MAC_154_STATE_TX_SYMBOL_STREAM while this mode is active.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] activate tx of symbols if true, dectivate if false.
 */
void atm_mac_154_activate_symbol_stream(bool activate);

/**
 * @brief Indicates status of MAC address filtering.
 * @return true if MAC address filtering is disabled,
 * false otherwise.
 * @note This function is called from interrupt context.
 */
bool atm_mac_154_address_filtering_disabled(void);

/**
 * @brief Indicates status of automatic MAC transmission of requested Acks.
 * @return true if automatic MAC Ack tx is disabled,
 * false otherwise.
 * @note This function is called from interrupt context.
 */
bool atm_mac_154_auto_ack_disabled(void);

/**
 * @brief Controls MAC address filtering.
 * @note In normal MAC operation, this function is not called.
 * This function allows receive processing of raw packets.
 * @param[in] disable Disables MAC address filtering if true,
 * enables same if false.
 * @note This function is called from interrupt context.
 */
void atm_mac_154_disable_address_filtering(bool disable);

/**
 * @brief Controls automatic MAC transmission of requested Acks.
 * This function allows receive processing of raw packets.
 * @note In normal MAC operation, this function is not called.
 * @par
 * @note This function is called from interrupt context.
 * @param[in] disable Disables automatic MAC Ack tx if true,
 * enables same if false.
 */
void atm_mac_154_disable_auto_ack(bool disable);

/**
 * @brief Controls automatic transmit and receive of CRC. This
 * function allows the system to transmit and receive raw packets
 * without including an appended CRC.
 * @note In normal MAC operation, this function is not called.
 * @par
 * @note This function is called from interrupt context.
 * @par
 * @param[in] disable Disables auto-calculate and insert CRC in tx/rx
 * packet if true, enables same if false.
 */
void atm_mac_154_disable_auto_crc(bool disable);

/**
 * @brief Controls automatic MAC receive of requested Acks.
 * @note In normal MAC operation, this function is not called.
 * This function allows the system to ignore requests for Acks.
 * @note This function is called from interrupt context.
 * @param[in] disable Disables automatic MAC wait for Ack tx if true,
 * enables same if false.
 */
void atm_mac_154_disable_wait_for_ack(bool disable);

/**
 * @brief Indicates status of automatic transmit and receive of CRC.
 * @note This function is called from interrupt context.
 * @return true if auto-calculate and insert CRC in tx/rx packet is disabled,
 * false otherwise.
 */
bool atm_mac_154_auto_crc_disabled(void);

/**
 * @brief Indicates status of manual transmit of CRC.
 * @note This function is called from interrupt context.
 * @return true if insert manual CRC in tx packet is enabled,
 * false otherwise.
 */
bool atm_mac_154_manual_tx_crc_enabled(void);

/**
 * @brief Controls transmit of manually-defined CRC value.
 * @note In normal MAC operation, this function is not called.
 * @note This function is called from interrupt context.
 * @note This function can only be called when automatic MAC Ack tx is
 * disabled AND automatic CRC insertion is disabled. API will assert
 * otherwise.
 * @par
 * @param override Manually write CRC with provided value when true,
 * don't write when false.
 * @param value The value to insert for CRC in tx packet.
 */
void atm_mac_154_enable_manual_tx_crc(bool override, uint16_t value);

/**
 * @brief Indicates status of automatic MAC receive of requested Acks.
 * @note This function is called from interrupt context.
 * @return true if automatic MAC wait for Ack tx is disabled,
 * false otherwise.
 */
bool atm_mac_154_wait_for_ack_disabled(void);

/**
 * @brief Enable Enhanced Acknowledgements
 *
 * @note Calling this function will overwrite the data associated with any
 * prior call to this function. This can only be used to enable the CSL IE in
 * Enhanced Acks to a single peer.
 *
 * The data provided in enh_ack_data will be added to any ack sent in response
 * to a packet with a source address matching long_addr or short_addr.
 *
 * When calling this function with the CSL IE, CSL Phase will be autonomously
 * populated based on the data provided to @ref atm_mac_154_set_csl_ie_period
 * and @ref atm_mac_154_set_csl_ie_rx_time, as well as the actual packet's
 * receive time.
 *
 * @param[in] long_addr The long_addr to reply to with this data
 * @param[in] short_addr The short_addr to reply to with this data
 * @param[in] enh_ack_data The IE. Certain fields may be filled in later
 * @param[in] enh_ack_len The length of enh_ack_data. Set to 0 to disable
 */
__NONNULL(3)
void atm_mac_154_enable_enhanced_ack(uint64_t long_addr, uint16_t short_addr,
    uint8_t const *enh_ack_data, uint8_t enh_ack_len);

/**
 * @brief Provide CSL period for the CSL IE
 *
 * This data is used to determine the CSL Phase of the CSL IE configured in
 * @ref atm_mac_154_enable_enhanced_ack. This must match the data in
 * enh_ack_data for proper operation.
 *
 * @param[in] csl_period_10symbols The CSL period in units of 10 symbols
 */
void atm_mac_154_set_csl_ie_period(uint16_t csl_period_10symbols);

/**
 * @brief Provide CSL RX start time for the CSL IE
 *
 * This data is used to determine the CSL Phase of the CSL IE configured in
 * @ref atm_mac_154_enable_enhanced_ack. Receives are expected to start at
 * csl_rx_time_us + n * csl_period_10symbols, for each integer n.
 *
 * @param[in] csl_rx_time_us The start time of the CSL receive, in microseconds
 */
void atm_mac_154_set_csl_ie_rx_time(uint32_t csl_rx_time_us);
/**@}*/

#ifdef RADIO_HAL_TEST
/** @name Internal test functions.
 * Functions related to internal testing of the driver.
 */

/**@{*/

/**
 * @brief Controls forcing backoff period to maximum value.
 * @note In normal MAC operation, this function is not called.
 * This function allows the system to supply the maximum posible value
 * for every backoff period, rather than a random value.
 * @note This function is called from interrupt context.
 * @param[in] force Forces use of maximum backoff period if true,
 * enables normal random backoff periods if false.
 */
void atm_mac_154_force_csma_max_backoff_period(bool force);

/**
 * @brief Indicates the total number of CSMA attempts used in the
 * most recent transmit operation.  The count is automatically reset to
 * zero at the start of each transmit during @ref atm_mac_154_transmit_packet.
 * @note This function is called from interrupt context.
 * @return the total number of backoffs.
 */
int8_t atm_mac_154_get_csma_attempt_count(void);

/**
 * @brief Indicates the total number of backoff periods used in the
 * most recent transmit operation.  The count is automatically reset to
 * zero at the start of each transmit during @ref atm_mac_154_transmit_packet.
 * @note This function is called from interrupt context.
 * @return the total number of backoff periods.
 */
int16_t atm_mac_154_get_csma_backoff_period_count(void);

/**
 * @brief Indicates the number of times a zero backoff period was used in the
 * most recent transmit operation.  The count is automatically reset to
 * zero at the start of each transmit during @ref atm_mac_154_transmit_packet.
 * @note This function is called from interrupt context.
 * @return the total number of zero backoff periods.
 */
int8_t atm_mac_154_get_csma_zero_backoff_period_count(void);

/**
 * @brief Indicates the total number of retry backoff periods used in the
 * most recent transmit operation.  The count is automatically reset to
 * zero at the start of each transmit during @ref atm_mac_154_transmit_packet.
 * @note This function is called from interrupt context.
 * @return the total number of backoff periods.
 */
int16_t atm_mac_154_get_retry_backoff_period_count(void);

/**
 * @brief Process a packet header.
 * @param[in] packet Pointer to packet data
 * @param[in] len_remaining Number of bytes of packet data available
 * @param[in/out] header Pointer to header data
 * @return filter result @ref atm_mac_154_filter_result_t
 */
atm_mac_154_filter_result_t atm_mac_154_process_header(uint8_t const *packet,
    uint8_t len_remaining, atm_mac_154_header_t *header);

/**
 * @brief Get last received packet header.
 * @return pointer to @ref atm_mac_154_header_t
 */
atm_mac_154_header_t *atm_mac_154_get_rx_header(void);
/**@}*/
#endif

#ifdef RADIO_HAL_PROFILE_TEST
/** @name Profiling functions.
 * Functions related to profiling of the driver.
 */

/**@{*/
typedef enum {
    PROFILE_TX_START, /*!< atm_mac_154_transmit function start */
    PROFILE_TX_CMD, /*!< TX command issued to CMD_VL */
    PROFILE_TX_ST, /*!< TX_ST HW timestamp at TX packet start */
    PROFILE_TX_ED, /*!< TX_ED HW timestamp at TX packet end */
    PROFILE_TX_IRQ, /*!< IRQ entry after initial TX */
    PROFILE_TX_ACK_CMD, /*!< RX command for ack issued to CMD_VL */
    PROFILE_TX_ACK_PRMBL_ST, /*!< RX_PRMBL_ST HW timestamp at ACK RX packet
				    start */
    PROFILE_TX_ACK_ED, /*!< RX_ED HW timestamp at ACK RX packet end */
    PROFILE_TX_ACK_IRQ, /*!< IRQ entry after initial ACK RX */
    PROFILE_TX_ACK_REARM_CMD, /*!< RX commmand for ack rearm issued to
				    CMD_VL */
    PROFILE_TX_ACK_REARM_PRMBL_ST, /*!< RX_PRMBL_ST HW timestamp at ACK
					rearm RX packet start */
    PROFILE_TX_ACK_REARM_ED, /*!< RX_ED HW timestamp at ACK rearm RX
				    packet end */
    PROFILE_TX_ACK_REARM_IRQ, /*!< IRQ entry after rearm ACK RX */
    PROFILE_TX_COMPLETE, /*!< TX operation complete */
    PROFILE_TX_NUM,
} atm_mac_154_profile_event_transmit_t;

typedef enum {
    PROFILE_RX_START, /*!< atm_mac_154_receive function start */
    PROFILE_RX_CMD, /*!< RX command issued to CMD_VL */
    PROFILE_RX_PRMBL_ST, /*!< RX_PRMBL_ST HW timestamp at RX packet start */
    PROFILE_RX_PROCESS, /*!< RX header processing completed */
    PROFILE_RX_ED, /*!< RX_ED HW timestamp at RX packet end */
    PROFILE_RX_IRQ, /*!< IRQ entry after initial RX */
    PROFILE_RX_REARM_CMD, /*!< RX command for rearm issued to CMD_VL */
    PROFILE_RX_REARM_PRMBL_ST, /*!< RX_PRMBL_ST HW timestamp at rearmed
				    RX packet start */
    PROFILE_RX_REARM_PROCESS, /*!< Rearmed RX packet header processing
				    completed */
    PROFILE_RX_REARM_ED, /*!< RX_ED HW timestamp at rearmed RX packet end */
    PROFILE_RX_REARM_IRQ, /*!< IRQ entry after rearmed RX */
    PROFILE_RX_ACK_CMD, /*!< TX command for ack issued to CMD_VL */
    PROFILE_RX_FP, /*!< Frame pending bit written */
    PROFILE_RX_ACK_ST, /*!< TX_ST HW timestamp at ack packet start */
    PROFILE_RX_ACK_ED, /*!< TX_ED HW timestamp at ack packet end */
    PROFILE_RX_ACK_IRQ, /*!< IRQ entry after ack TX */
    PROFILE_RX_COMPLETE, /*!< RX operation complete */
    PROFILE_RX_NUM,
} atm_mac_154_profile_event_receive_t;

/**
 * @brief Get profile for last transmit operation
 *
 * @note each profile save event adds 3 instructions (LDR, LDR, STR) which
 * equates to 15 clock cycles of instructions or 235ns at 64MHz. In total,
 * this will add a minimum of 3 save events (~700ns) and up to 14 save
 * events (~33us), before accounting for TX retries.
 *
 * @return uint32_t pointer to array of
 *         @ref atm_mac_154_profile_event_transmit_t timestamps
 */
uint32_t *atm_mac_154_get_transmit_profile(void);

/**
 * @brief Get profile for last receive operation
 *
 * @note each profile save event adds 3 instructions (LDR, LDR, STR) which
 * equates to 15 clock cycles of instructions or 235ns at 64MHz. In total,
 * this will add a minimum of 3 save events (~700ns). On the upper end, a
 * full receive profile consists of 12 save events (~30us) plus 5 (~1us) for
 * each successful RX rearm.
 *
 * @return uint32_t pointer to array of
 *         @ref atm_mac_154_profile_event_receive_t timestamps
 */
uint32_t *atm_mac_154_get_receive_profile(void);
/**@}*/
#endif

#ifdef __cplusplus
}
#endif

/// @} RADIO_HAL_154
