/**
 *******************************************************************************
 *
 * @file fp_fmdn_sba_gatt.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Secure Beacon Actions GATT Characteristic Implementation
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include "fp_fmdn_sba_gatt.h"
#include "fp_fmdn_internal.h"
#include "fp_fmdn_persistent_conn.h"
#include "fp_fmdn_reverse_ringing.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

/// Per-connection context for Secure Beacon Actions
typedef struct {
	struct bt_conn *conn;
	bool notify_enabled;
	bool indicate_enabled;
} sba_conn_ctx_t;

static sba_conn_ctx_t sba_conn_contexts[CONFIG_BT_MAX_CONN];

/// Stored SBA characteristic attribute pointer for spontaneous indications
static const struct bt_gatt_attr *sba_char_attr;

ssize_t fp_fmdn_sba_read(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			 uint16_t len, uint16_t offset)
{
	LOG_DBG("SBA GATT Read Request");

	if (offset) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}

	/* Read returns: [Protocol version (0x02), Client ID] */
	uint8_t client_id = 0;

#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	const fp_fmdn_persistent_conn_state_t *pc_state = fp_fmdn_persistent_conn_get_state();
	if (pc_state && (pc_state->is_active)) {
		client_id = pc_state->client_id;
		LOG_DBG("SBA: Read returning current client ID: %u", client_id);
	}
#endif

	uint8_t rsp[2] = {
		BCNA_MJR_VER,
		client_id,
	};

	return bt_gatt_attr_read(conn, attr, buf, len, offset, rsp, sizeof(rsp));
}

ssize_t fp_fmdn_sba_write(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf,
			  uint16_t len, uint16_t offset, uint8_t flags)
{
	LOG_DBG("SBA GATT Write Request: len=%u offset=%u", len, offset);

	if (offset) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}

	if (len < 1) {
		LOG_WRN("SBA: Empty write request");
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
	}

	const uint8_t *data = (const uint8_t *)buf;
	uint8_t data_id = data[0];

	LOG_DBG("SBA Data ID: 0x%02x", data_id);

#if (defined(CONFIG_FMDN_PERSISTENT_CONNECTION) || defined(CONFIG_FMDN_REVERSE_RINGING))
	int err;
#endif
	switch (data_id) {
#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	case SBA_DATA_ID_PERSISTENT_CONNECTION: {
		LOG_INF("SBA: Persistent Connection request");

		/* Request format: [data_id, flags, client_id, conn_type] */
		if (len < 4) {
			LOG_WRN("SBA: Invalid PC request length: %u", len);
			return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		}
		uint8_t flags = data[1];
		uint8_t client_id = data[2];
		uint8_t conn_type = data[3];

		pc_result_t result =
			fp_fmdn_persistent_conn_configure(conn, flags, client_id, conn_type);

		uint8_t response[2] = {SBA_DATA_ID_PERSISTENT_CONNECTION, (uint8_t)result};
		err = bt_gatt_notify(conn, attr, response, sizeof(response));
		if (err) {
			LOG_ERR("SBA: Failed to send PC response: %d", err);
		}
		break;
	}
#endif
#ifdef CONFIG_FMDN_REVERSE_RINGING
	case SBA_DATA_ID_REVERSE_RINGING_CONFIG: {
		LOG_INF("SBA: Reverse Ringing Configuration");

		/* Validate request length: minimum 2 bytes (data_id, flags)
		 * Format per spec:
		 * Byte 0: Data ID (0x11)
		 * Byte 1: Flags (bit 0=enable/disable, 0xFF=ignore)
		 */
		if (len < 2) {
			LOG_WRN("SBA: Invalid RR config request length: %u", len);
			return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		}

		uint8_t flags = data[1];
		err = fp_fmdn_reverse_ringing_configure(conn, flags);
		if (err) {
			LOG_ERR("SBA: Failed to configure RR: %d", err);
			return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		}

		/* Send response via GATT notification
		 * Response format: Data ID 0x11 + current configuration byte
		 */
		const fp_fmdn_reverse_ringing_state_t *rr_state =
			fp_fmdn_reverse_ringing_get_state();
		uint8_t response[2] = {SBA_DATA_ID_REVERSE_RINGING_CONFIG,
				       rr_state->enabled ? 0x01 : 0x00};
		err = bt_gatt_notify(conn, attr, response, sizeof(response));
		if (err) {
			LOG_ERR("SBA: Failed to send RR config response: %d", err);
		}
		break;
	}

	case SBA_DATA_ID_REVERSE_RINGING: {
		LOG_INF("SBA: Reverse Ringing state update from Seeker");

		/* Validate request length: minimum 2 bytes (data_id, state)
		 * Format per spec line 264:
		 * "Seeker sends GATT write requests with data ID 0x12 to communicate
		 * the updated ringing state"
		 * Byte 0: Data ID (0x12)
		 * Byte 1: Ringing state (0x00-0x04)
		 */
		if (len < 2) {
			LOG_WRN("SBA: Invalid RR state update length: %u", len);
			return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		}

		uint8_t state = data[1];

		/* Process the reverse ringing state update from Seeker
		 * Per spec line 264: "Whenever the Seeker starts or stops ringing --
		 * whether triggered by reverse ringing termination request, a timeout
		 * or a manual user action on Seeker's side -- it sends GATT write
		 * requests with data ID 0x12 to communicate the updated ringing state."
		 *
		 * This will:
		 * 1. Validate the state value (0x00-0x04)
		 * 2. Update internal tracking
		 * 3. Notify application via event callback
		 */
		err = fp_fmdn_reverse_ringing_state_update(conn, state);
		if (err) {
			LOG_ERR("SBA: Failed to process RR state update: %d", err);
			return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		}
		break;
	}
#endif
	default:
		LOG_WRN("SBA: Unknown data ID 0x%02x", data_id);
		return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
	}
	return len;
}

void fp_fmdn_sba_ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_DBG("SBA CCC changed: value=0x%04x", value);

	LOG_INF("SBA Notify: %s, Indicate: %s",
		(value & BT_GATT_CCC_NOTIFY) ? "enabled" : "disabled",
		(value & BT_GATT_CCC_INDICATE) ? "enabled" : "disabled");
}

void fp_fmdn_sba_gatt_init(struct bt_gatt_attr *attr)
{
	LOG_INF("SBA GATT initialized");

	/* Store the SBA characteristic attribute pointer for spontaneous indications
	 * This is needed when the Provider initiates reverse ringing via button press
	 */
	sba_char_attr = attr;
	if (!sba_char_attr) {
		LOG_ERR("SBA: NULL attribute pointer provided to init");
	}

	memset(sba_conn_contexts, 0, sizeof(sba_conn_contexts));
#if (defined(CONFIG_FMDN_PERSISTENT_CONNECTION) || defined(CONFIG_FMDN_REVERSE_RINGING))
	int err;
#endif

#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	// Initialize persistent connection module
	err = fp_fmdn_persistent_conn_init();
	if (err) {
		LOG_ERR("SBA: Failed to initialize persistent connection module: %d", err);
	}
#endif

#ifdef CONFIG_FMDN_REVERSE_RINGING
	// Initialize reverse ringing module
	err = fp_fmdn_reverse_ringing_init();
	if (err) {
		LOG_ERR("SBA: Failed to initialize reverse ringing module: %d", err);
	}
#endif
}

void fp_fmdn_sba_gatt_deinit(void)
{
	LOG_INF("SBA GATT deinitialized");
	sba_char_attr = NULL;
	memset(sba_conn_contexts, 0, sizeof(sba_conn_contexts));

#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	// Deinitialize persistent connection module
	fp_fmdn_persistent_conn_deinit();
#endif

#ifdef CONFIG_FMDN_REVERSE_RINGING
	// Deinitialize reverse ringing module
	fp_fmdn_reverse_ringing_deinit();
#endif
}

const struct bt_gatt_attr *fp_fmdn_sba_gatt_get_attr(void)
{
	return sba_char_attr;
}
