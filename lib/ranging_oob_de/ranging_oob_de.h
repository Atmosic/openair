/**
 *******************************************************************************
 *
 * @file ranging_oob_de.h
 * @brief Ranging Capability Out-of-Band (OOB) Data Element definitions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

/**
 * @defgroup ATM_BTFM_RANGING_OOB_DE Ranging OOB DE API
 * @ingroup ATM_BTFM_API
 * @brief ATM Ranging OOB DE API
 *
 * This module contains the definitions for the Ranging OOB DE
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Ensure structures are packed for wire protocol compatibility */
#ifndef __PACKED
#define __PACKED __attribute__((packed))
#endif

/// Ranging Message ID
typedef enum {
	/// Ranging Capability Request message
	RANGING_MSG_ID_CAP_REQ = 0x00,
	/// Ranging Capability Response message
	RANGING_MSG_ID_CAP_RESP,
	/// Ranging Configuration message
	RANGING_MSG_ID_CONF,
	/// Ranging Configuration Response message
	RANGING_MSG_ID_CONF_RESP,
	/// Start Ranging message
	RANGING_MSG_ID_START_RANGING,
	/// Start Ranging Response message
	RANGING_MSG_ID_START_RANGING_RESP,
	/// Stop Ranging message
	RANGING_MSG_ID_STOP_RANGING,
	/// Stop Ranging Response message
	RANGING_MSG_ID_STOP_RANGING_RESP,
	/// 0xFF Reserved for future use
	RANGING_MSG_ID_RFU = 0xFF
} ranging_msg_id_t;

/// Ranging Technology ID
typedef enum {
	/// UWB
	RT_TECH_ID_UWB = 0x00,
	/// BLE Channel Sounding
	RT_TECH_ID_CS,
	/// WiFi NAN RTT
	RT_TECH_ID_WIFI_NAN_RTT,
	/// BLE RSSI
	RT_TECH_ID_RSSI,
	/// 0x4 - 0xFF Reserved for future use
	RT_TECH_ID_RFU,
} rt_id_t;

/// Ranging Technology Bitfield - Generated from rt_id_t values
#define RT_TECH_BF_UWB          (1U << RT_TECH_ID_UWB)
#define RT_TECH_BF_CS           (1U << RT_TECH_ID_CS)
#define RT_TECH_BF_WIFI_NAN_RTT (1U << RT_TECH_ID_WIFI_NAN_RTT)
#define RT_TECH_BF_RSSI         (1U << RT_TECH_ID_RSSI)

/// Helper macro to convert rt_id_t to bitfield value
#define RT_ID_TO_BITFIELD(id) (1U << (id))

/// Status bitmap bit positions for configuration responses
#define RANGING_STATUS_BIT_UWB          0 // Bit 0 - UWB
#define RANGING_STATUS_BIT_BLE_CS       1 // Bit 1 - BLE Channel Sounding
#define RANGING_STATUS_BIT_WIFI_NAN_RTT 2 // Bit 2 - WiFi NAN RTT
#define RANGING_STATUS_BIT_BLE_RSSI     3 // Bit 3 - BLE RSSI

// CS LE Flag definitions (direct values, not bit positions)
#define CS_LE_FLAG_LIMITED_DISCOVERY_MODE  0 // Value 0
#define CS_LE_FLAG_GENERAL_DISCOVERY_MODE  1 // Value 1
#define CS_LE_FLAG_BREDR_NOT_SUPPORTED     2 // Value 2
#define CS_LE_FLAG_SIMULTANEOUS_CONTROLLER 3 // Value 3
#define CS_LE_FLAG_SIMULTANEOUS_HOST       4 // Value 4
// Values 5-7: Reserved

/// BLE Channel Sounding Security Level
typedef enum {
	/// Security Level 1 (no security)
	RANGING_RESP_DE_CS_SEC_LEVEL_ONE = 0x01,
	/// Security Level 2 (authenticated)
	RANGING_RESP_DE_CS_SEC_LEVEL_TWO = 0x02,
	/// Security Level 3 (authenticated and encrypted)
	RANGING_RESP_DE_CS_SEC_LEVEL_THREE = 0x08,
	/// Security Level 4 (authenticated, encrypted, and key size >= 7)
	RANGING_RESP_DE_CS_SEC_LEVEL_FOUR = 0x10,
} ranging_de_cs_sec_level_t;

typedef struct {
	/// Ranging version
	uint8_t version;
	/// Ranging message ID
	ranging_msg_id_t msg_id;
} __PACKED ranging_oob_de_header_t;

/// Ranging Capability Request Data Element structure
typedef struct {
	/// Ranging OOB DE header
	ranging_oob_de_header_t header;
	/// Ranging technologies requested bitfield (2 bytes, little endian)
	uint16_t bitfield;
} __PACKED ranging_cap_req_de_t;

/// UWB Capabilities Data Element
typedef struct {
	/// Ranging technology ID
	rt_id_t id;
	/// Total size of UWB capabilities payload
	uint8_t size;
	/// Device UWB Address (2 bytes)
	uint8_t addr[2];
	/// Supported Channel Mask
	uint32_t channel_mask;
	/// Supported Preamble Index mask (1 to 32)
	uint32_t preamble_mask;
	/// Supported Config IDs mask
	uint32_t config_id_mask;
	/// Supported Minimum Ranging Interval
	uint16_t min_ranging_int;
	/// Supported Minimum Slot Duration
	uint8_t min_slot_dur;
	/// Supported Device Role Bitmap
	uint8_t device_role;
} __PACKED ranging_cap_de_uwb_t;

/// BLE Channel Sounding Capabilities Data Element
typedef struct {
	/// Ranging technology ID
	rt_id_t id;
	/// Size of CS capabilities payload (1 byte)
	uint8_t size;
	/// Security Type (1 byte)
	ranging_de_cs_sec_level_t sec_type;
	/// Device Address (6 bytes, big endian)
	uint8_t addr[6];
	/// LE Appearance (2 bytes, little endian)
	uint16_t appearance;
	/// LE Flags (1 byte)
	uint8_t flags;
} __PACKED ranging_cap_de_cs_t;

/// Ranging Capability Response Data Element structure
typedef struct {
	/// Ranging OOB DE header
	ranging_oob_de_header_t header;
	/// Ranging technologies supported bitfield
	uint16_t bitfield;
	/// technology-specific data
	union {
		ranging_cap_de_uwb_t ubw;
		ranging_cap_de_cs_t cs;
	} tech_data;
} __PACKED ranging_cap_resp_de_t;

typedef struct {
	uint16_t vendor_id;
	uint8_t static_sts_iv[6];
} __PACKED s_sts_data_t;

typedef struct {
	uint8_t session_key[32];
} __PACKED p_sts_data_t;

/// UWB TWR Configuration Data Element
typedef struct {
	/// Ranging technology ID
	rt_id_t id;
	/// Total size of UWB capabilities payload
	uint8_t size;
	/// Device UWB MAC Address (2 bytes)
	uint8_t addr[2];
	/// Session ID
	uint32_t session;
	/// Selected Config ID
	uint8_t config_id;
	/// Selected Channel
	uint8_t channel;
	/// Selected Preamble Index
	uint8_t preamble_idx;
	/// Selected Ranging Rate
	uint16_t ranging_rate;
	/// Selected Slot Duration
	uint8_t slot_dur;
	/// Session Key Length
	uint8_t session_key_len;
	/// Session Key (variable length, up to 32 bytes)
	union {
		s_sts_data_t s_sts_data;
		p_sts_data_t p_sts_data;
	} session_key;
	/// Country Code (2 bytes)
	uint16_t country_code;
	/// Device Role
	uint8_t device_role;
	/// Device Mode
	uint8_t device_mode;
} __PACKED ranging_conf_de_uwb_t;

/// BLE Channel Sounding Configuration Data Element
typedef struct {
	/// Ranging technology ID
	rt_id_t id;
	/// Total size of CS configuration payload
	uint8_t size;
#ifdef CONFIG_RANGING_OOB_DE_TYPE_BLE_CS_CONFIG_SEC_TYPE
	/// Security Type (1 byte)
	ranging_de_cs_sec_level_t sec_type;
#endif
} __PACKED ranging_conf_de_cs_t;

/// Ranging Configuration Data Element structure
typedef struct {
	/// Ranging OOB DE header
	ranging_oob_de_header_t header;
	/// Ranging technologies to configure bitfield (16 bits)
	uint16_t bitfield;
	/// Ranging technologies to start immediately bitfield (16 bits)
	/// If corresponding ranging technology bit is set to 1, ranging should start
	/// right away after setting the configuration. If set to 0, peripheral should
	/// wait for the Start Ranging DE for that technology.
	uint16_t start_bitfield;
	/// technology-specific data
	union {
		ranging_conf_de_uwb_t uwb;
		ranging_conf_de_cs_t cs;
	} tech_data;
} __PACKED ranging_conf_de_t;

/// Start Ranging Data Element structure
typedef struct {
	/// Ranging OOB DE header
	ranging_oob_de_header_t header;
	/// Ranging technologies to start bitfield
	uint16_t bitfield;
} __PACKED ranging_start_de_t;

/// Stop Ranging Data Element structure
typedef struct {
	ranging_oob_de_header_t header;
	/// Ranging technologies to stop bitfield
	uint16_t bitfield;
} __PACKED ranging_stop_de_t;

/// Ranging Common Response Data Element structure
typedef struct {
	/// Status bitmap (16 bits)
	ranging_oob_de_header_t header;
	uint16_t status_bitmap;
} __PACKED ranging_common_resp_de_t;

/* ========================================================================
 * Protocol Constants
 * ======================================================================== */

/// Current protocol version
#define RANGING_PROTOCOL_VERSION_CURRENT 0x01

/// Minimum supported protocol version
#define RANGING_PROTOCOL_VERSION_MIN 0x01

/// Maximum supported protocol version
#define RANGING_PROTOCOL_VERSION_MAX 0x01

/// Validation macros for enum ranges
#define IS_VALID_RANGING_MSG_ID(id) ((id) <= RANGING_MSG_ID_STOP_RANGING_RESP)
#define IS_VALID_RT_TECH_ID(id)     ((id) <= RT_TECH_ID_RSSI)
#define IS_VALID_RANGING_RESP_DE_CS_SEC_LEVEL(level)                                               \
	((level) >= RANGING_RESP_DE_CS_SEC_LEVEL_ONE &&                                            \
	 (level) <= RANGING_RESP_DE_CS_SEC_LEVEL_FOUR)

/// Protocol version support macro
#define RANGING_OOB_DE_SUPPORT_VERSION(version_id)                                                 \
	(((version_id) > RANGING_PROTOCOL_VERSION_CURRENT) ? RANGING_PROTOCOL_VERSION_CURRENT      \
							   : (version_id))

/// Configuration flags for CS
#define RANGING_CONF_CS_FLAG_START_IMMEDIATELY 0x01

/* ========================================================================
 * Public API Functions
 * ======================================================================== */

/**
 * @brief Get supported ranging protocol version (now a macro)
 *
 * This macro returns the supported ranging protocol version based on the
 * requested version. If the requested version is higher than the current
 * supported version, it returns the current supported version.
 *
 * This provides version negotiation capability for ranging protocols,
 * ensuring compatibility between devices with different protocol versions.
 *
 * @param version_id Requested ranging protocol version
 * @return Supported ranging protocol version (clamped to current maximum)
 *
 * @note This macro is used during ranging capability negotiation
 * @see RANGING_PROTOCOL_VERSION_CURRENT for the current supported version
 * @see RANGING_OOB_DE_SUPPORT_VERSION() for the macro implementation
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
