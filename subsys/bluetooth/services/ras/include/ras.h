/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "compiler.h"
#include <zephyr/bluetooth/uuid.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Ranging Service UUID value
#define BT_UUID_RAS_VAL 0x185B

/// Ranging Service UUID
#define BT_UUID_RAS BT_UUID_DECLARE_16(BT_UUID_RAS_VAL)

/// RAS Features Characteristic UUID value
#define BT_UUID_RAS_FEATURES_VAL 0x2C14

/// RAS Features Characteristic UUID
#define BT_UUID_RAS_FEATURES BT_UUID_DECLARE_16(BT_UUID_RAS_FEATURES_VAL)

/// Real-time Ranging Data Characteristic UUID value
#define BT_UUID_RAS_REALTIME_RD_VAL 0x2C15

/// Real-time Ranging Data Characteristic UUID
#define BT_UUID_RAS_REALTIME_RD BT_UUID_DECLARE_16(BT_UUID_RAS_REALTIME_RD_VAL)

/// On-demand Ranging Data Characteristic UUID value
#define BT_UUID_RAS_ONDEMAND_RD_VAL 0x2C16

/// On-demand Ranging Data Characteristic UUID
#define BT_UUID_RAS_ONDEMAND_RD BT_UUID_DECLARE_16(BT_UUID_RAS_ONDEMAND_RD_VAL)

/// RAS Control Point Characteristic UUID value
#define BT_UUID_RAS_CP_VAL 0x2C17

/// RAS Control Point Characteristic UUID
#define BT_UUID_RAS_CP BT_UUID_DECLARE_16(BT_UUID_RAS_CP_VAL)

/// Ranging Data Ready Characteristic UUID value
#define BT_UUID_RAS_RD_READY_VAL 0x2C18

/// Ranging Data Ready Characteristic UUID
#define BT_UUID_RAS_RD_READY BT_UUID_DECLARE_16(BT_UUID_RAS_RD_READY_VAL)

/// Ranging Data Overwritten Characteristic UUID value
#define BT_UUID_RAS_RD_OVERWRITTEN_VAL 0x2C19

/// Ranging Data Overwritten Characteristic UUID
#define BT_UUID_RAS_RD_OVERWRITTEN BT_UUID_DECLARE_16(BT_UUID_RAS_RD_OVERWRITTEN_VAL)

/// Max subevents amount per cs procedure
#define BT_RAS_MAX_SUBEVENTS_PER_PROCEDURE 32
/// Max steps amount per cs procedure
#define BT_RAS_MAX_STEPS_PER_PROCEDURE     256
/// Max steps amount per cs subevent
#define BT_RAS_MAX_STEPS_PER_SUBEVENT      160

struct bt_ras_client_cb {
	/**
	 * @brief Callback function for bt_ras_discover
	 *
	 * This callback is called when discovery procedure is complete.
	 *
	 * @param conn Bluetooth connection object.
	 * @param err Zero in case of success and error code in case of error.
	 */
	void (*discovery_done)(const struct bt_conn *conn, int err);
};

/**
 * @brief Discover Ranging Service
 *
 * @param conn Bluetooth connection object.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_discover(struct bt_conn *conn);

/**
 * @brief Register Ranging Service Client callbacks
 *
 * @param cb The callback structure.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_cb_register(const struct bt_ras_client_cb *cb);

/// Ranging data ready callback function
typedef void (*bt_ras_client_ranging_data_ready_cb)(struct bt_conn *conn, uint16_t ranging_counter,
						    int err);

/// Ranging data overwritten callback function
typedef void (*bt_ras_client_ranging_data_overwritten_cb)(struct bt_conn *conn,
							  uint16_t ranging_counter);

/// Get ranging data complete callback function
typedef void (*bt_ras_client_get_ranging_data_cmpl_cb)(struct bt_conn *conn,
						       uint16_t ranging_counter, int err);

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
/// Get realtime ranging data complete callback function
typedef void (*bt_ras_client_get_realtime_ranging_data_cmpl_cb)(struct bt_conn *conn, int err);
#endif

/**
 * @brief Subscribe to ranging data ready notification. Required to be called
 * after @ref bt_ras_client_discover
 *
 * @param conn Bluetooth connection object.
 *
 * @param cb Notification callback function.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_ranging_data_ready_subscribe(struct bt_conn *conn,
					       const bt_ras_client_ranging_data_ready_cb cb);

/**
 * @brief Subscribe to ranging data overwritten notification. Required to be
 * called after @ref bt_ras_client_discover
 *
 * @param conn Bluetooth connection object.
 *
 * @param cb Notification callback function.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_ranging_data_overwritten_subscribe(
	struct bt_conn *conn, const bt_ras_client_ranging_data_overwritten_cb cb);

/**
 * @brief Subscribe to on-demand ranging data notification. Required to be
 * called after @ref bt_ras_client_discover
 *
 * @param conn Bluetooth connection object.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_on_demand_ranging_data_subscribe(struct bt_conn *conn);

/**
 * @brief Unsubscribe to on-demand ranging data notification. Required to be
 * called after @ref bt_ras_client_on_demand_ranging_data_subscribe
 *
 * @param conn Bluetooth connection object.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_on_demand_ranging_data_unsubscribe(struct bt_conn *conn);

/**
 * @brief Subscribe to RAS control point notification. Required to be
 * called after @ref bt_ras_client_discover
 *
 * @param conn Bluetooth connection object.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_cp_subscribe(struct bt_conn *conn);

/**
 * @brief Get ranging data for given ranging counter. Required to be called
 * after @ref bt_ras_client_cp_subscribe
 *
 * @param conn Bluetooth connection object.
 *
 * @param ranging_counter Counter identifier for the request.
 *
 * @param ranging_data_out Buffer that will store the returned ranging data
 * from the remote device.
 *
 * @param cb Callback function to handle the result, which will be called upon
 * completion of the ranging data retrieval.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_cp_get_ranging_data(struct bt_conn *conn, uint16_t ranging_counter,
				      struct net_buf_simple *ranging_data_out,
				      const bt_ras_client_get_ranging_data_cmpl_cb cb);

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
/**
 * @brief Subscribe to realtime ranging data notification. Required to be called
 * after @ref bt_ras_client_discover
 *
 * @param conn Bluetooth connection object.
 *
 * @param ranging_data_out Buffer that will store the returned realtime ranging data
 * from the remote device.
 *
 * @param cb Callback function to handle the result, which will be called upon
 * completion of the ranging data retrieval.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_realtime_ranging_data_subscribe(
	struct bt_conn *conn, struct net_buf_simple *ranging_data_out,
	const bt_ras_client_get_realtime_ranging_data_cmpl_cb cb);

/**
 * @brief Unsubscribe to realtime ranging data notification. Required to be called
 * after @ref bt_ras_client_realtime_ranging_data_subscribe
 *
 * @param conn Bluetooth connection object.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_realtime_ranging_data_unsubscribe(struct bt_conn *conn);
#endif

/**
 * @brief Parse the ranging data and remove the ranging header from the buffer
 *
 * @param ranging_data_buf pointer to the buffer that contains the ranging data
 * with the header included.
 *
 * @param ranging_counter_out pointer to the ranging count. The ranging counter is lower 12-bits of
 * CS procedure counter.
 *
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_ras_client_ranging_data_parse(struct net_buf_simple *ranging_data_buf,
				     uint16_t *ranging_counter_out);

#ifdef __cplusplus
}
#endif
