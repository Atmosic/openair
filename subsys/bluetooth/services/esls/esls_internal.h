/**
 *******************************************************************************
 *
 * @file esls_internal.h
 *
 * @brief Electronic Shelf Label Service Internal Header File
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>

#ifdef __cplusplus
extern "C" {
#endif

/// ESL ID for Broadcast Address in ESL Address
#define ESL_ADDR_ID_BROADCAST_ADDR 0xFF
/// ESL ID Mask in ESL Address
#define ESL_ADDR_ID_MASK           0x00FF
/// Group ID Mask in ESL Address
#define ESL_ADDR_GROUP_ID_MASK     0x7F00
/// Reserved for Future Use Mask in ESL Address
#define ESL_ADDR_RFU_MASK          0x8000
/// Valid Mask in ESL Address
#define ESL_ADDR_VALID_MASK        (ESL_ADDR_ID_MASK | ESL_ADDR_GROUP_ID_MASK)

/// ESL Address Length
#define ESL_ADDR_LEN             2
/// AP Sync Key Material Length
#define AP_SYNC_KEY_MATERIAL_LEN (BT_EAD_KEY_SIZE + BT_EAD_IV_SIZE)
/// ESL Response Key Material Length
#define ESL_RSP_KEY_MATERIAL_LEN (BT_EAD_KEY_SIZE + BT_EAD_IV_SIZE)
/// ESL Current Absolute Time Length
#define ESL_CURRENT_ABS_TIME_LEN 4

/// ESL Service UUID value
#define BT_UUID_ESLS_VAL 0x1857

/// ESL Service
#define BT_UUID_ESLS BT_UUID_DECLARE_16(BT_UUID_ESLS_VAL)

/// ESL Address Characteristic UUID value
#define BT_UUID_ESL_ADDRESS_VAL 0x2BF6

/// ESL Address Characteristic
#define BT_UUID_ESL_ADDRESS BT_UUID_DECLARE_16(BT_UUID_ESL_ADDRESS_VAL)

/// AP Sync Key Material Characteristic UUID value
#define BT_UUID_AP_SYNC_KEY_MATERIAL_VAL 0x2BF7

/// AP Sync Key Material Characteristic
#define BT_UUID_AP_SYNC_KEY_MATERIAL BT_UUID_DECLARE_16(BT_UUID_AP_SYNC_KEY_MATERIAL_VAL)

/// ESL Response Key Material Characteristic UUID value
#define BT_UUID_ESL_RSP_KEY_MATERIAL_VAL 0x2BF8

/// ESL Response Key Material Characteristic
#define BT_UUID_ESL_RSP_KEY_MATERIAL BT_UUID_DECLARE_16(BT_UUID_ESL_RSP_KEY_MATERIAL_VAL)

/// ESL Current Absolute Characteristic UUID value
#define BT_UUID_ESL_CURRENT_ABSOLUTE_TIME_VAL 0x2BF9

/// ESL Current Absolute Characteristic
#define BT_UUID_ESL_CURRENT_ABSOLUTE_TIME BT_UUID_DECLARE_16(BT_UUID_ESL_CURRENT_ABSOLUTE_TIME_VAL)

/// ESL Display Information Characteristic UUID value
#define BT_UUID_ESL_DISPLAY_INFO_VAL 0x2BFA

/// ESL Display Information Characteristic
#define BT_UUID_ESL_DISPLAY_INFO BT_UUID_DECLARE_16(BT_UUID_ESL_DISPLAY_INFO_VAL)

/// ESL Image Information Characteristic UUID value
#define BT_UUID_ESL_IMAGE_INFO_VAL 0x2BFB

/// ESL Image Information Characteristic
#define BT_UUID_ESL_IMAGE_INFO BT_UUID_DECLARE_16(BT_UUID_ESL_IMAGE_INFO_VAL)

/// ESL Sensor Information Characteristic UUID value
#define BT_UUID_ESL_SENSOR_INFO_VAL 0x2BFC

/// ESL Sensor Information Characteristic
#define BT_UUID_ESL_SENSOR_INFO BT_UUID_DECLARE_16(BT_UUID_ESL_SENSOR_INFO_VAL)

/// ESL LED Characteristic UUID value
#define BT_UUID_ESL_LED_VAL 0x2BFD

/// ESL LED Characteristic
#define BT_UUID_ESL_LED BT_UUID_DECLARE_16(BT_UUID_ESL_LED_VAL)

/// ESL Control Point Characteristic UUID value
#define BT_UUID_ESL_CONTROL_POINT_VAL 0x2BFE

/// ESL Control Point Characteristic
#define BT_UUID_ESL_CONTROL_POINT BT_UUID_DECLARE_16(BT_UUID_ESL_CONTROL_POINT_VAL)

/// Does nothing but solicits a response
#define ESLS_OPCODE_PING                0x00
/// Requests the ESL to disassociate from the AP with which it was associated
#define ESLS_OPCODE_UNASSOCIATE         0x01
/// Sets the Service Needed flag to False
#define ESLS_OPCODE_SERVICE_RESET       0x02
/// Requests the ESL to disassociate from the AP and revert to its original
/// state
#define ESLS_OPCODE_FACTORY_RESET       0x03
/// Requests that the ESL return to the Synchronized state once synchronized
#define ESLS_OPCODE_UPDATE_COMPLETE     0x04
/// Requests a response with sensor data, or an indication that data is not yet
/// available
#define ESLS_OPCODE_READ_SENSOR_DATA    0x10
/// Refreshes the current displayed image to keep the displayed image fresh on
/// the display
#define ESLS_OPCODE_REFRESH_DISPLAY     0x11
/// Displays a pre-stored image on an ESL display
#define ESLS_OPCODE_DISPLAY_IMAGE       0x20
/// Displays a pre-stored image on an ESL display at a specified time
#define ESLS_OPCODE_DISPLAY_TIMED_IMAGE 0x60
/// Turn on/off an LED with a color/flashing pattern
#define ESLS_OPCODE_LED_CONTROL         0xB0
/// Turn on/off an LED with a color/flashing pattern at a specified time
#define ESLS_OPCODE_LED_TIMED_CONTROL   0xF0
/// Allow vendors to specify their own commands
#define ESLS_OPCODE_VENDOR_SPECIFIC_TAG 0x0F

/// The ESL has detected a condition that needs service
#define ESLS_BASIC_STATE_SERVICE_NEEDED         0x01
/// The ESL is synchronized to the AP
#define ESLS_BASIC_STATE_SYNCHRONIZED           0x02
/// The ESL has one or more active LEDs
#define ESLS_BASIC_STATE_ACTIVE_LED             0x04
/// The ESL has a timed LED update
#define ESLS_BASIC_STATE_PENDING_LED_UPDATE     0x08
/// The ESL has a timed display update
#define ESLS_BASIC_STATE_PENDING_DISPLAY_UPDATE 0x10

/// The command could not be processed successfully
#define ESLS_RSP_OPCODE_ERROR               0x00
/// Acknowledgment of a request to control an LED
#define ESLS_RSP_OPCODE_LED_STATE           0x01
/// General acknowledgment containing ESL status data
#define ESLS_RSP_OPCODE_BASIC_STATE         0x10
/// Acknowledgment of a request to display an image
#define ESLS_RSP_OPCODE_DISPLAY_STATE       0x11
/// Sensor report
#define ESLS_RSP_OPCODE_SENSOR_VALUE        0x0E
/// Response data as specified by the vendor of the ESL
#define ESLS_RSP_OPCODE_VENDOR_SPECIFIC_RSP 0x0F

/// Reserved for Future Use
#define ESLS_ERR_RFU                 0x00
/// Any error condition that is not covered by a specific error code below
#define ESLS_ERR_UNSPECIFIC          0x01
/// The opcode was not recognized
#define ESLS_ERR_INVALID_OPCODE      0x02
/// The request was not valid for the present ESL state
#define ESLS_ERR_INVALID_STATE       0x03
/// The Image_Index value was out of range
#define ESLS_ERR_INVALID_IMAGE_IDX   0x04
/// The requested image contained no image data
#define ESLS_ERR_IMAGE_NOT_AVAILABLE 0x05
/// The parameter value(s) or length did not match the opcode
#define ESLS_ERR_INVALID_PARAM       0x06
/// The required response could not be sent as it would exceed the payload size
/// limit
#define ESLS_ERR_CAPACITY_LIMIT      0x07
/// The request could not be processed because of a lack of battery charge
#define ESLS_ERR_INSUFF_BATTERY      0x08
/// The request could not be processed because of a lack of resources. This may
/// be a temporary condition.
#define ESLS_ERR_INSUFF_RESOURCES    0x09
/// The ESL is temporarily unable to give a full response (e.g., because the
/// required sensor hardware was asleep) and the AP is asked to try the same
/// command again
#define ESLS_ERR_RETRY               0x0A
/// The ESL is temporarily unable to add a further timed command to the queue of
/// pending commands-the queue has reached its limit
#define ESLS_ERR_QUEUE_FULL          0x0B
//// The Absolute Time parameter value in the command is implausible
#define ESLS_IMPL_ABS_TIME           0x0C
/// Reserved for Future Use, 0x0D-0xEF
#define ESLS_ERR_RFU_MORE            0x0D
/// Error codes defined by a vendor, 0xF0-0xFF
#define ESLS_ERR_VENDOR_SPECIFIC     0xF0

/* ESLS state-machine states (also used by test accessors in esls_test_internal.h) */
enum esls_state {
	ESLS_STATE_UNASSOCIATED,
	ESLS_STATE_CONFIGURING,
	ESLS_STATE_SYNCHRONIZED,
	ESLS_STATE_UPDATING,
	ESLS_STATE_UNSYNCHRONIZED,

	ESLS_STATE_IDX_MAX
};

/* ESLS state-machine events (also used by test accessors in esls_test_internal.h) */
enum esls_evt {
	ESLS_EVT_ENCRYPTED,
	ESLS_EVT_DISCONNECTED,
	ESLS_EVT_UPDATE_COMPLETE,
	ESLS_EVT_PAST_SYNCED,
	ESLS_EVT_PA_SYNC_TERM,
	ESLS_EVT_STATE_TIMEOUT,
	ESLS_EVT_RCV_VALID_MSG,
};

#ifdef __cplusplus
}
#endif
