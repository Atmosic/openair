/**
 *******************************************************************************
 *
 * @file fp_fmdn_persistent_conn.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Persistent Connection Management Implementation
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "fp_fmdn_persistent_conn.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

/// Persistent connection state (only one allowed at a time)
static fp_fmdn_persistent_conn_state_t pc_state = {
	.conn = NULL,
	.client_id = 0,
	.conn_type = 0,
	.is_active = false,
	.negotiate_interval = false,
};

static void fp_fmdn_persistent_conn_reset(void)
{
	pc_state.conn = NULL;
	pc_state.client_id = 0;
	pc_state.conn_type = 0;
	pc_state.is_active = false;
	pc_state.negotiate_interval = false;
}

int fp_fmdn_persistent_conn_init(void)
{
	/* Load saved client ID from NVS (if any)
	 * This enforces ownership across power cycles - only the Seeker that
	 * configured persistent connection with force bit can reconnect,
	 * or a new Seeker must use force bit to take over.
	 */
	uint8_t saved_client_id;
	if (!fp_storage_pc_client_id_get(&saved_client_id)) {
		pc_state.client_id = saved_client_id;
		LOG_INF("PC: Loaded saved client ID from NVS: %u", saved_client_id);
	} else {
		LOG_DBG("PC: No saved client ID in NVS");
	}

	LOG_DBG("Persistent Connection module initialized");
	return 0;
}

void fp_fmdn_persistent_conn_deinit(void)
{
	LOG_DBG("Persistent Connection module deinitialized");
	fp_fmdn_persistent_conn_reset();
}

pc_result_t fp_fmdn_persistent_conn_configure(struct bt_conn *conn, uint8_t flags,
					      uint8_t client_id, uint8_t conn_type)
{
	LOG_INF("PC: Configure request - flags=0x%02x, client_id=%u, conn_type=0x%02x", flags,
		client_id, conn_type);

	/* Use only 2 LSBs of connection type */
	uint8_t conn_type_lsb = conn_type & 0x03;

	/* Check if we have a saved client ID from a previous session (power cycle protection)
	 * Per Google's clarification: "We do expect the Provider to remember the client ID
	 * of the last Seeker that configured a persistent connection with the force bit and
	 * reject such connections from other Seekers unless they also set this bit"
	 */
	bool has_saved_client_id = fp_storage_pc_client_id_valid();
	uint8_t saved_client_id = 0;
	if (has_saved_client_id) {
		fp_storage_pc_client_id_get(&saved_client_id);
	}

	bool save_client_id = false;
	bool reconfigure_only = false;

	if (pc_state.is_active && (pc_state.conn == conn)) {
		/* Current connection already persistent, reconfigure
		 * Per spec: "If the current connection is already persistent, Provider will
		 * configure the current connection according to the second byte of the request."
		 */
		LOG_INF("PC: Current connection is already persistent, reconfiguring");

		/* Per spec: Only check client ID if it's different from saved one
		 * Same client ID can reconfigure without force bit
		 */
		if (has_saved_client_id && (saved_client_id != client_id)) {
			/* Different client ID - force bit required */
			if (!(flags & PC_FLAG_FORCE)) {
				LOG_WRN("PC: Client ID mismatch (%u != %u), force bit required",
					saved_client_id, client_id);
				return PC_RESULT_ANOTHER_EXISTS;
			}
			/* Force bit set, save new client ID */
			LOG_INF("PC: Force bit set, updating client ID %u -> %u", saved_client_id,
				client_id);
			save_client_id = true;
		}
		reconfigure_only = true;
	} else if (pc_state.is_active && (pc_state.conn != conn)) {
		/* Another persistent connection exists */
		if (!(flags & PC_FLAG_FORCE)) {
			LOG_WRN("PC: Another persistent connection exists, rejecting");
			return PC_RESULT_ANOTHER_EXISTS;
		}

		/* Force flag set, disconnect existing */
		LOG_INF("PC: Force flag set, disconnecting existing persistent connection");
		if (pc_state.conn) {
			bt_conn_disconnect(pc_state.conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		}
		save_client_id = true;
	} else {
		/* No active persistent connection, but check if we have a saved client ID
		 * from a previous session (after power loss/restart)
		 */
		if (has_saved_client_id) {
			/* We have a saved client ID - enforce ownership */
			if (!(flags & PC_FLAG_FORCE)) {
				LOG_WRN("PC: Saved client ID exists (%u), but force bit not set, "
					"rejecting",
					saved_client_id);
				return PC_RESULT_ANOTHER_EXISTS;
			}
			LOG_INF("PC: Force bit set, accepting new client ID %u (replacing saved "
				"client ID %u)",
				client_id, saved_client_id);
			save_client_id = true;
		} else if (flags & PC_FLAG_FORCE) {
			/* First time configuration with force bit */
			save_client_id = true;
		}
	}

	/* Update persistent connection state (common for all paths) */
	if (!reconfigure_only) {
		pc_state.conn = conn;
		pc_state.is_active = true;
	}
	pc_state.client_id = client_id;
	pc_state.conn_type = conn_type;
	pc_state.negotiate_interval = (flags & PC_FLAG_NEGOTIATE) != 0;

	/* If connection type is non-persistent, clear NVS client ID to release ownership.
	 * This allows any Seeker to reclaim persistent connection without the force bit.
	 * Otherwise, save the client ID if a force-bit upgrade was requested.
	 */
	if (conn_type_lsb == PC_CONN_TYPE_NON_PERSISTENT) {
		fp_storage_pc_client_id_delete();
	} else if (save_client_id) {
		fp_storage_pc_client_id_save(client_id);
	}

	LOG_INF("PC: Configured as persistent - client_id=%u, conn_type_lsb=0x%02x, negotiate=%s",
		client_id, conn_type_lsb, pc_state.negotiate_interval ? "yes" : "no");

	/* Per FHN v2 spec: "When Bit 2 of the first request byte is set, the Provider is
	 * responsible for negotiating the configured connection interval with the Seeker
	 * immediately after a persistent connection is established or reconfigured. If
	 * negotiation fails, the Provider should disconnect from the Seeker. If both Provider
	 * and Seeker support BLE Connection Subrating, the negotiation of the connection
	 * interval should be skipped."
	 */
	if (pc_state.negotiate_interval) {
		/* Check if both Provider and Seeker support BLE Connection Subrating.
		 * If so, skip connection interval negotiation.
		 */
#ifdef CONFIG_BT_SUBRATING
		struct bt_conn_remote_info remote_info;
		int err = bt_conn_get_remote_info(conn, &remote_info);

		if (!err && BT_FEAT_LE_CONN_SUBRATING(remote_info.le.features)) {
			/* Both Provider and Seeker support BLE Connection Subrating.
			 * Skip connection interval negotiation per spec.
			 */
			LOG_INF("PC: Both sides support BLE Connection Subrating, skipping "
				"negotiation");
			return PC_RESULT_SUCCESS;
		} else if (err) {
			LOG_DBG("PC: Could not get remote info (err=%d), proceeding with "
				"negotiation",
				err);
		}
#endif

		struct bt_le_conn_param pc_conn_params;

		// Get connection parameters for this connection type
		int err = fp_fmdn_persistent_conn_get_conn_param(conn_type, &pc_conn_params);
		if (err) {
			LOG_ERR("PC: Failed to get connection parameters: %d", err);
			/* Per FHN v2 spec: "If negotiation fails, the Provider should disconnect
			 * from the Seeker." Configuration was accepted, but negotiation will fail.
			 */
			bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
			pc_state.is_active = false;
			pc_state.conn = NULL;
			return PC_RESULT_SUCCESS;
		}

		LOG_INF("PC: Initiating connection parameter update - type=0x%02x, interval=%u-%u",
			conn_type_lsb, pc_conn_params.interval_min, pc_conn_params.interval_max);
		err = bt_conn_le_param_update(conn, &pc_conn_params);
		if (err) {
			LOG_ERR("PC: Failed to initiate parameter update: %d", err);
			/* Per FHN v2 spec: "If negotiation fails, the Provider should disconnect
			 * from the Seeker." Configuration was accepted, but negotiation failed.
			 */
			bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
			pc_state.is_active = false;
			pc_state.conn = NULL;
			return PC_RESULT_SUCCESS;
		}
	}

	return PC_RESULT_SUCCESS;
}

const fp_fmdn_persistent_conn_state_t *fp_fmdn_persistent_conn_get_state(void)
{
	return &pc_state;
}

void fp_fmdn_persistent_conn_param_nego_complete(struct bt_conn *conn, int status)
{
	if (!pc_state.is_active) {
		return;
	}

	LOG_DBG("PC: Param negotiation complete - status=%d", status);

	if (status) {
		// Negotiation failed, disconnect
		LOG_WRN("PC: Parameter negotiation failed, disconnecting");
		bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		pc_state.is_active = false;
		pc_state.conn = NULL;
	}
}

void fp_fmdn_persistent_conn_disconnected(struct bt_conn *conn)
{
	if (pc_state.is_active && (pc_state.conn == conn)) {
		LOG_INF("PC: Persistent connection disconnected");
		pc_state.is_active = false;
		pc_state.conn = NULL;
	}
}

int fp_fmdn_persistent_conn_get_conn_param(uint8_t conn_type, struct bt_le_conn_param *param)
{
	/* Per FHN v2 spec: "The Provider should ignore the 6 most significant bits of the
	 * connection type value. Only the 2 least significant bits are used."
	 */
	uint8_t conn_type_lsb = conn_type & 0x03;

	/* Per FHN v2 spec: "In all cases, the peripheral latency should be 0. This is because
	 * higher latency would result in slow performance of GATT operations sent to the
	 * peripheral when using large connection interval"
	 */
	param->latency = 0;   // No latency per spec
	param->timeout = 800; // 8 seconds supervision timeout

	// Set interval based on connection type per FHN v2 spec table
	switch (conn_type_lsb) {
	case PC_CONN_TYPE_NON_PERSISTENT: // 30-100ms
		param->interval_min = 24; // 30ms (24 * 1.25ms)
		param->interval_max = 80; // 100ms (80 * 1.25ms)
		LOG_DBG("PC: Non-persistent connection params: 30-100ms");
		break;
	case PC_CONN_TYPE_PERSISTENT_INTERACTIVE: // 30-100ms
		param->interval_min = 24;         // 30ms (24 * 1.25ms)
		param->interval_max = 80;         // 100ms (80 * 1.25ms)
		LOG_DBG("PC: Persistent Interactive connection params: 30-100ms");
		break;
	case PC_CONN_TYPE_PERSISTENT_CONNECTABLE: // up to 800ms
		param->interval_min = 640;        // 800ms (640 * 1.25ms)
		param->interval_max = 640;        // 800ms
		LOG_DBG("PC: Persistent Connectable connection params: 800ms");
		break;
	case PC_CONN_TYPE_PERSISTENT_DETECTABLE: // up to 800ms
		param->interval_min = 640;       // 800ms (640 * 1.25ms)
		param->interval_max = 640;       // 800ms
		LOG_DBG("PC: Persistent Detectable connection params: 800ms");
		break;
	default:
		// Should not reach here due to LSB masking
		param->interval_min = 640;
		param->interval_max = 640;
		break;
	}

	return 0;
}

int fp_fmdn_persistent_conn_get_adv_param(uint8_t conn_type, fp_fmdn_pc_adv_param_t *adv_param)
{
	// Use only 2 LSBs of connection type
	uint8_t conn_type_lsb = conn_type & 0x03;

	// Set advertisement parameters based on connection type
	switch (conn_type_lsb) {
	case PC_CONN_TYPE_NON_PERSISTENT: // default frequency (at least once every 2 seconds per
					  // FHN spec)
		adv_param->interval_ms = 2000;
		adv_param->connectable = true;
		LOG_DBG("PC: Non-persistent adv params: 2000ms, connectable=true");
		break;
	case PC_CONN_TYPE_PERSISTENT_INTERACTIVE: // at least once every 30 seconds, connectable
		adv_param->interval_ms = 30000;
		adv_param->connectable = true;
		LOG_DBG("PC: Persistent Interactive adv params: 30000ms, connectable=true");
		break;
	case PC_CONN_TYPE_PERSISTENT_CONNECTABLE: // at least once every 3 seconds, connectable
		adv_param->interval_ms = 3000;
		adv_param->connectable = true;
		LOG_DBG("PC: Persistent Connectable adv params: 3000ms, connectable=true");
		break;
	case PC_CONN_TYPE_PERSISTENT_DETECTABLE: // at least once every 30 seconds, NOT connectable
		adv_param->interval_ms = 30000;
		adv_param->connectable = false;
		LOG_DBG("PC: Persistent Detectable adv params: 30000ms, connectable=false");
		break;
	case PC_CONN_TYPE_PERSISTENT_UNDETECTABLE: // NO advertisements
		adv_param->interval_ms = 0;
		adv_param->connectable = false;
		LOG_DBG("PC: Persistent Undetectable adv params: no advertisements");
		break;
	default:
		// Should not reach here due to LSB masking
		adv_param->interval_ms = 0;
		adv_param->connectable = false;
		break;
	}

	return 0;
}
