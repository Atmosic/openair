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

/* ── SBA TLV write frame layouts ───────────────────────────────────────── */

struct __packed sba_pc_req {
	uint8_t data_id;
	uint8_t length;
	uint8_t flags;
	uint8_t client_id;
	uint8_t conn_type;
};

struct __packed sba_rr_config_req {
	uint8_t data_id;
	uint8_t length;
	uint8_t flags;
};

struct __packed sba_rr_state_req {
	uint8_t data_id;
	uint8_t length;
	uint8_t state;
};

/// Per-connection context for Secure Beacon Actions
typedef struct {
	struct bt_conn *conn;
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

	/* Read returns: [Protocol version (0x02), Client ID]
	 * client_id reflects the current ownership state:
	 *   PC_CLIENT_ID_NONE (0xFF) - no persistent connection in use
	 *   PC_CLIENT_ID_OEM  (0xFE) - OEM companion app owns persistent connection
	 *   other             - active Find Hub Seeker client ID
	 */
#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	const fp_fmdn_persistent_conn_state_t *pc_state = fp_fmdn_persistent_conn_get_state();
	uint8_t client_id = pc_state ? pc_state->client_id : PC_CLIENT_ID_NONE;
	LOG_DBG("SBA: Read returning client ID: 0x%02x", client_id);
#else
	uint8_t client_id = PC_CLIENT_ID_NONE;
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

	switch (data_id) {
#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	case SBA_DATA_ID_PERSISTENT_CONNECTION: {
		LOG_INF("SBA: Persistent Connection request");

		const struct sba_pc_req *req = (const struct sba_pc_req *)data;
		if (len < sizeof(*req) || req->length != 3) {
			LOG_WRN("SBA: Invalid PC request length: %u (payload_len=%u)", len,
				(len >= 2) ? req->length : 0);
			return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		}

		pc_result_t result = fp_fmdn_persistent_conn_configure(
			conn, req->flags, req->client_id, req->conn_type);

		if (result == PC_RESULT_OEM_OWNS) {
			LOG_WRN("SBA: PC configure rejected - OEM app owns connection");
			return BT_GATT_ERR(SBA_PC_ERR_OEM_APP_OWNS);
		}
		if (result != PC_RESULT_SUCCESS) {
			LOG_WRN("SBA: PC configure failed: result=%u", (uint8_t)result);
			return BT_GATT_ERR(SBA_PC_ERR_ANOTHER_SEEKER_OWNS);
		}
		break;
	}
#endif
#ifdef CONFIG_FMDN_REVERSE_RINGING
	case SBA_DATA_ID_REVERSE_RINGING_CONFIG: {
		LOG_INF("SBA: Reverse Ringing Configuration");

		/* Format: [data_id(0x11), length(0x01), flags]
		 * flags: bit 0 = enable/disable, 0xFF = ignore
		 */
		const struct sba_rr_config_req *req = (const struct sba_rr_config_req *)data;
		if (len < sizeof(*req) || req->length != 1) {
			LOG_WRN("SBA: Invalid RR config request length: %u (payload_len=%u)", len,
				(len >= 2) ? req->length : 0);
			return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		}

		int err = fp_fmdn_reverse_ringing_configure(conn, req->flags);
		if (err) {
			LOG_ERR("SBA: Failed to configure RR: %d", err);
			return BT_GATT_ERR(SBA_RR_ERR_UNAVAILABLE);
		}

		break;
	}

	case SBA_DATA_ID_REVERSE_RINGING: {
		LOG_INF("SBA: Reverse Ringing state update from Seeker");

		/* Format: [data_id(0x12), length(0x01), state(0x00-0x04)] */
		const struct sba_rr_state_req *req = (const struct sba_rr_state_req *)data;
		if (len < sizeof(*req) || req->length != 1) {
			LOG_WRN("SBA: Invalid RR state update length: %u (payload_len=%u)", len,
				(len >= 2) ? req->length : 0);
			return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		}

		int err = fp_fmdn_reverse_ringing_state_update(conn, req->state);
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
	ARG_UNUSED(attr);
	LOG_INF("SBA Indicate: %s", (value & BT_GATT_CCC_INDICATE) ? "enabled" : "disabled");
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
