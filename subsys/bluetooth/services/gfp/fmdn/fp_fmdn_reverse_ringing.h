/**
 *******************************************************************************
 *
 * @file fp_fmdn_reverse_ringing.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Reverse Ringing Management
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#ifndef FP_FMDN_REVERSE_RINGING_H
#define FP_FMDN_REVERSE_RINGING_H

#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include "compiler.h"
#include "fp_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Reverse Ringing configuration flags
typedef enum {
	RR_FLAG_ENABLE = 0x01,   ///< Enable reverse ringing if set, disable if cleared
	RR_FLAG_RESERVED = 0xFE, ///< Reserved bits for future use
} rr_config_flags_t;

/// Reverse Ringing request values (Provider sends to Seeker via Data ID 0x12)
typedef enum {
	RR_REQUEST_STOP = 0x00,  ///< Stop ringing
	RR_REQUEST_START = 0x01, ///< Start ringing
} rr_request_t;

/// Reverse Ringing state values (Seeker sends to Provider via Data ID 0x12)
typedef enum {
	RR_STATE_STARTED = 0x00,          ///< Ringing started
	RR_STATE_FAILED_TO_START = 0x01,  ///< Failed to start ringing
	RR_STATE_STOPPED_TIMEOUT = 0x02,  ///< Stopped due to timeout
	RR_STATE_STOPPED_USER = 0x03,     ///< Stopped by user action on Seeker
	RR_STATE_STOPPED_PROVIDER = 0x04, ///< Stopped by Provider request
} rr_state_t;

/// Reverse Ringing connection type
typedef enum {
	RR_CONN_TYPE_NONE = 0,      ///< No active connection
	RR_CONN_TYPE_PERSISTENT,    ///< Persistent connection (can send START indication)
	RR_CONN_TYPE_ADVERTISEMENT, ///< Advertisement-based connection (cannot send START)
} rr_conn_type_t;

/// Reverse Ringing state
typedef struct {
	bool enabled;                ///< Whether reverse ringing is enabled
	struct bt_conn *active_conn; ///< Active connection for reverse ringing (if any)
	bool ringing;                ///< Whether currently ringing
	rr_conn_type_t conn_type;    ///< Type of active connection
	bool encryption_enabled;     ///< Whether encryption is enabled on connection
} fp_fmdn_reverse_ringing_state_t;

/// Reverse Ringing event types
/// These events inform the application about the status of the phone (Seeker) ringing,
/// NOT about the tag ringing (the tag doesn't ring in reverse ringing!)
typedef enum {
	RR_EVENT_PHONE_FAILED,           ///< Phone failed to start ringing (STATE 0x01)
	RR_EVENT_PHONE_STARTED,          ///< Phone confirmed ringing started (STATE 0x00)
	RR_EVENT_PHONE_STOPPED_PROVIDER, ///< Phone stopped ringing, tag requested (STATE 0x04)
	RR_EVENT_PHONE_STOPPED_TIMEOUT,  ///< Phone stopped ringing, timeout (STATE 0x02)
	RR_EVENT_PHONE_STOPPED_USER,     ///< Phone stopped ringing, user dismissed (STATE 0x03)
	RR_EVENT_RR_ADV_CONNECTED,       ///< Encryption enabled on adv-based connection
	RR_EVENT_RR_ADV_STARTED,         ///< Advertisement started for adv-based ringing
	RR_EVENT_RR_ADV_START_FAILED,    ///< Advertisement failed to start for adv-based ringing
	RR_EVENT_RR_ADV_TIMEOUT,         ///< ADV window expired with no Seeker connection (15-20s)
	RR_EVENT_TIMEOUT_LOCAL,          ///< Provider 60s timeout; ADV path, no stop WRITE received
	RR_EVENT_PHONE_START_TIMEOUT,    ///< Provider 60s timeout; persistent path after START ACK
	RR_EVENT_START_INDICATION_CONFIRMED, ///< START indication ACKed on persistent connection
	RR_EVENT_STOP_INDICATION_CONFIRMED,  ///< STOP indication ACKed on persistent connection
	RR_EVENT_PHONE_STOPPED_DISCONNECTED, ///< Connection dropped while phone was ringing
} fp_fmdn_reverse_ringing_event_t;

/// Callback function for reverse ringing events
/// This callback informs the application about phone ringing status, NOT tag ringing!
/// Application should use this to show LED patterns/feedback to user about phone's state.
/// @param event The reverse ringing event indicating what happened on the phone
typedef void (*fp_fmdn_reverse_ringing_event_cb)(fp_fmdn_reverse_ringing_event_t event);

/// Initialize reverse ringing module
int fp_fmdn_reverse_ringing_init(void);

/// Deinitialize reverse ringing module
void fp_fmdn_reverse_ringing_deinit(void);

/// Handle reverse ringing configuration request (Data ID 0x11)
/// @param conn BLE connection
/// @param flags Configuration flags (0x01=enable, 0xFF=ignore)
/// @return 0 on success, negative error code on failure
__NONNULL(1)
int fp_fmdn_reverse_ringing_configure(struct bt_conn *conn, uint8_t flags);

/// Handle reverse ringing state update from Seeker (Data ID 0x12 write request)
/// @param conn BLE connection
/// @param state Ringing state from Seeker (0x00-0x04)
/// @return 0 on success, negative error code on failure
__NONNULL(1)
int fp_fmdn_reverse_ringing_state_update(struct bt_conn *conn, uint8_t state);

/// Get current reverse ringing state
/// @return Pointer to reverse ringing state
const fp_fmdn_reverse_ringing_state_t *fp_fmdn_reverse_ringing_get_state(void);

/// Check whether reverse ringing is enabled (configured by Seeker)
/// @return true if enabled
bool fp_fmdn_is_reverse_ringing_enabled(void);

/// Check whether reverse ringing is currently active (phone is ringing)
/// @return true if ringing is in progress
bool fp_fmdn_is_reverse_ringing_started(void);

/// Handle connection disconnection
/// @param conn BLE connection
__NONNULL(1)
void fp_fmdn_reverse_ringing_disconnected(struct bt_conn *conn);

/// Handle connection established (for advertisement-based reverse ringing)
/// @param conn BLE connection
__NONNULL(1)
void fp_fmdn_reverse_ringing_connected(struct bt_conn *conn);

/// Handle encryption enabled on connection (for advertisement-based reverse ringing)
/// @param conn BLE connection
__NONNULL(1)
void fp_fmdn_reverse_ringing_encryption_enabled(struct bt_conn *conn);

/// Handle button press to stop reverse ringing
/// Called when user presses button to stop ringing
/// @param tap_type Button tap type
void fp_fmdn_reverse_ringing_button_press(fp_tap_type_t tap_type);

/// Register reverse ringing event callback
/// @param hdlr Callback function to be called when reverse ringing events occur
__NONNULL_ALL
void fp_fmdn_reverse_ringing_event_reg(fp_fmdn_reverse_ringing_event_cb const hdlr);

#ifdef __cplusplus
}
#endif

#endif /* FP_FMDN_REVERSE_RINGING_H */
