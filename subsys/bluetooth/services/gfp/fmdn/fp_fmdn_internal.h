/**
 *******************************************************************************
 *
 * @file fp_fmdn_internal.h
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Internal definitions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Find My Device Network Extention
 * @brief Internal definitions of Google Fast Pair Find My Device Network
 * Extention
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Length of FMDN Beacon Action Randon nonce
#define BCNA_RNDM_NONCE_LEN   8
/// FMDN Beacon Action Major version
#define BCNA_MJR_VER          0x01
/// Length of FMDN Beacon Action Major version
#define BCNA_MJR_VER_LEN      1
/// Length of FMDN Beacon Action read response
#define BCNA_READ_RESP_LEN    (BCNA_MJR_VER_LEN + BCNA_RNDM_NONCE_LEN)
/// Maximun Length of FMDN Beacon Action additional data
#define BCNA_ADD_DATA_MAX_LEN 40
/// Length of FMDN Beacon Action authentication data
#define BCNA_AUTH_DATA_LEN    128
/// Length of FMDN Beacon Action read parameter
#define BCNA_READ_PARAM_LEN   16
#define BCNA_AUTH_DATA_LEN    128
/// Length of FMDN Beacon Action authentication key
#define BCNA_AUTH_KEY_LEN     8
/// Maximun Length of FMDN Beacon Action authentication key
#define BCNA_AUTH_KEY_MAX_LEN 16
/// Length of FMDN EID key
#define BCNA_EID_KEY_AUTH_LEN (FP_FMDN_EID_KEY_LEN + BCNA_RNDM_NONCE_LEN)

#define BCNA_RING_COMPONENTS_ALL 0x03
/// 0x01: Ringing volume selection available. If set, the Provider must accept
/// and handle 3 volume levels as indicated in Ring operation
#define BCNA_RING_SEL_AVAILABLE  0x01

/// Gatt Beacon Action operation id
typedef enum {
	/// read parameters
	BCNA_OP_READ_PARAMMETERS = 0x00,
	/// read provision state
	BCNA_OP_READ_PROVISION_STATE,
	/// set eid key
	BCNA_OP_SET_EID_KEY,
	/// clear eid key
	BCNA_OP_CLEAR_EID_KEY,
	/// read eid key
	BCNA_OP_READ_EID_KEY,
	/// ring sate change
	BCNA_OP_RING_STATE_CHANGE,
	/// read ring state
	BCNA_OP_READ_RINGING_STATE,
	/// utp mode activate
	BCNA_OP_ACTIVATE_UTP,
	/// utp mode deactivate
	BCNA_OP_DEACTIVATE_UTP,
} bcna_operation_id_t;

/// Gatt Beacon Action error id
typedef enum {
	/// write request when authentication fails
	BCNA_ERR_UNAUTHENTICATED = 0x80,
	/// when any invalid value is provided or the data received has an
	/// unexpected number of bytes.
	BCNA_ERR_INVALID_VALUE = 0x81,
	/// write request with data ID 0x04: Read ephemeral identity key with user
	/// consent when the device isn't in pairing mode.
	BCNA_ERR_NO_USER_CONSENT = 0x82,
} bcna_error_id_t;

/// FP FMDN authentication key type
typedef enum {
	/// Recovery Key type
	FP_FMDN_AUTH_KEY_TYPE_RECOVERY,
	/// Ring Key type
	FP_FMDN_AUTH_KEY_TYPE_RING,
	/// Unwanted Tracking Protection (UTP) Key type
	FP_FMDN_AUTH_KEY_TYPE_UTP,
} fp_fmdn_auth_key_type_t;

/// FP FMDN authentication data type
typedef enum {
	/// Requst data
	FP_FMDN_AUTH_DATA_REQ,
	/// EID read requst data
	FP_FMDN_AUTH_DATA_EID_READ_REQ,
	/// Response data
	FP_FMDN_AUTH_DATA_RES,
} fp_fmdn_auth_data_type_t;

/// FP FMDN provision state
typedef enum {
	/// eid key has been set
	FP_FMDN_PROVISION_STATE_EIDK_SET = 0x01,
	/// authenticated
	FP_FMDN_PROVISION_STATE_AUTHED,
} fp_fmdn_provision_state_t;

/// FP FMDN ring state
typedef enum {
	/// ring started
	FP_FMDN_RING_STATE_STARTED = 0x00,
	/// ring failed on start or stop
	FP_FMDN_RING_STATE_FAILED_START_STOP,
	/// ring stoped by timeout
	FP_FMDN_RING_STATE_STOPED_TIMEOUT,
	/// ring stopped by button pressed
	FP_FMDN_RING_STATE_STOPED_BUTTON_PRESS,
	/// ring stopped by gatt request
	FP_FMDN_RING_STATE_STOPED_GATT_REQUEST,
} fp_fmdn_ring_state_t;

/// FP FMND ring valume level
typedef enum {
	/// default
	FP_FMDN_RING_VOL_DEFAULT = 0x00,
	/// low level
	FP_FMDN_RING_VOL_LOW,
	/// medium level
	FP_FMDN_RING_VOL_MEDIUM,
	/// high level
	FP_FMDN_RING_VOL_HIGH,
} fp_fmdn_ring_vol_level_t;

/// GATT Beacon Action connect context structure
typedef struct {
	/// randon nonce
	uint8_t random_nonce[BCNA_RNDM_NONCE_LEN];
	/// challenge valid
	bool is_challenge_valid;
	/// secret key
	uint8_t secret_key[BCNA_AUTH_KEY_MAX_LEN];
	/// secret key len
	uint16_t secret_key_len;
} bcna_conn_ctx_t;

/// GATT Beacon Action write data header structure
typedef struct {
	/// Data ID
	uint8_t data_id;
	/// Data length
	uint8_t data_len;
} bcna_write_data_header_t;

/// GATT Beacon Action write data structure
typedef struct {
	bcna_write_data_header_t header;
	/// One-time authentication key
	uint8_t auth_key[BCNA_AUTH_KEY_LEN];
	/// Additional data
	uint8_t addition_data[BCNA_ADD_DATA_MAX_LEN];
} bcna_write_data_t;

#ifdef __cplusplus
}
#endif

///@}
