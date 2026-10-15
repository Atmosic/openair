/**
 *******************************************************************************
 *
 * @file fp_fmdn_persistent_conn.h
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Persistent Connection Management
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#ifndef FP_FMDN_PERSISTENT_CONN_H
#define FP_FMDN_PERSISTENT_CONN_H

#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Persistent Connection configuration request flags
typedef enum {
	PC_FLAG_FORCE = 0x01,     ///< Force disconnect existing persistent connection
	PC_FLAG_NEGOTIATE = 0x02, ///< Provider should negotiate connection interval
} pc_config_flags_t;

/// Persistent Connection response result codes
typedef enum {
	PC_RESULT_SUCCESS = 0x00,        ///< Configuration successful
	PC_RESULT_ANOTHER_EXISTS = 0x01, ///< Another Seeker owns the persistent connection
	PC_RESULT_OEM_OWNS = 0x02,       ///< OEM companion app owns the persistent connection
} pc_result_t;

/// Special client ID sentinel values (Table v2.4)
/// Default value indicating that no persistent connection is in use by Find Hub or OEM.
#define PC_CLIENT_ID_NONE 0xFF
/// Value indicating the OEM companion app currently owns persistent connection management.
#define PC_CLIENT_ID_OEM  0xFE

/// Persistent Connection type values (2 LSBs of connection type byte)
typedef enum {
	PC_CONN_TYPE_NON_PERSISTENT = 0x00,          ///< Non-persistent
	PC_CONN_TYPE_PERSISTENT_INTERACTIVE = 0x01,  ///< Persistent Interactive
	PC_CONN_TYPE_PERSISTENT_CONNECTABLE = 0x02,  ///< Persistent Connectable
	PC_CONN_TYPE_PERSISTENT_DETECTABLE = 0x03,   ///< Persistent Detectable
	PC_CONN_TYPE_PERSISTENT_UNDETECTABLE = 0x04, ///< Persistent Undetectable
} pc_conn_type_t;

/// Persistent Connection state
typedef struct {
	struct bt_conn *conn; ///< Connection handle for persistent connection
	uint8_t client_id;    ///< Client ID of the persistent connection
	uint8_t conn_type; ///< Connection type (controls interval, advertisement, connectable mode)
	bool is_active;    ///< Whether persistent connection is active
	bool negotiate_interval;  ///< Whether to negotiate connection interval (Bit 2 of flags)
	bool negotiation_pending; ///< Set before sending param update; cleared in le_param_updated
} fp_fmdn_persistent_conn_state_t;

/// Initialize persistent connection module
int fp_fmdn_persistent_conn_init(void);

/// Deinitialize persistent connection module
void fp_fmdn_persistent_conn_deinit(void);

/// Handle persistent connection configuration request
/// @param conn BLE connection
/// @param flags Configuration flags (force, negotiate)
/// @param client_id Client ID from the request
/// @param conn_type Connection type from the request
/// @return Result code (success or failure reason)
__NONNULL(1)
pc_result_t fp_fmdn_persistent_conn_configure(struct bt_conn *conn, uint8_t flags,
					      uint8_t client_id, uint8_t conn_type);

/// Get current persistent connection state
/// @return Pointer to persistent connection state
const fp_fmdn_persistent_conn_state_t *fp_fmdn_persistent_conn_get_state(void);

/// Acquire OEM ownership of persistent connection management.
/// May only succeed when client_id is currently PC_CLIENT_ID_NONE (0xFF), meaning neither
/// Find Hub nor another OEM instance is using persistent connection features.
/// On success the reported client_id is updated to PC_CLIENT_ID_OEM (0xFE).
/// @return 0 on success, -EBUSY if persistent connection is already owned by Find Hub or OEM.
int fp_fmdn_persistent_conn_oem_acquire(void);

/// Release OEM ownership of persistent connection management.
/// Resets the reported client_id back to PC_CLIENT_ID_NONE (0xFF).
/// Must be called when the OEM app disables all features that require a persistent connection.
void fp_fmdn_persistent_conn_oem_release(void);

/// Handle connection parameter negotiation completion
/// @param conn BLE connection
/// @param status Negotiation status (0 = success, non-zero = failure)
__NONNULL(1)
void fp_fmdn_persistent_conn_param_nego_complete(struct bt_conn *conn, int status);

/// Handle connection disconnection
/// @param conn BLE connection
void fp_fmdn_persistent_conn_disconnected(struct bt_conn *conn);

/// Get connection parameters for a given connection type
/// @param conn_type Connection type (2 LSBs: 0=non-persistent, 1=interactive, 2=connectable,
/// 3=detectable, 4=undetectable)
/// @param param Output parameter structure to fill with connection parameters
/// @return 0 on success, negative error code on failure
__NONNULL(2)
int fp_fmdn_persistent_conn_get_conn_param(uint8_t conn_type, struct bt_le_conn_param *param);

/// Advertisement parameters for persistent connection
typedef struct {
	uint16_t interval_ms; ///< Advertisement interval in milliseconds
	bool connectable;     ///< Whether advertisements should be connectable
} fp_fmdn_pc_adv_param_t;

/// Get advertisement parameters for a given connection type
/// @param conn_type Connection type (2 LSBs: 0=non-persistent, 1=interactive, 2=connectable,
/// 3=detectable, 4=undetectable)
/// @param adv_param Output parameter structure to fill with advertisement parameters
/// @return 0 on success, negative error code on failure
__NONNULL(2)
int fp_fmdn_persistent_conn_get_adv_param(uint8_t conn_type, fp_fmdn_pc_adv_param_t *adv_param);

/// PC state change notification (configure, interactive-revert, or disconnect).
///
/// @param is_active  true if a PC is now active.
/// @param conn_type  New connection type (3 LSBs meaningful).
typedef void (*fp_fmdn_pc_state_cb_t)(bool is_active, uint8_t conn_type);

/// Register a listener for PC state changes.
/// @param cb Callback, or NULL to unregister.
void fp_fmdn_persistent_conn_register_state_cb(fp_fmdn_pc_state_cb_t cb);

#ifdef __cplusplus
}
#endif

#endif /* FP_FMDN_PERSISTENT_CONN_H */
