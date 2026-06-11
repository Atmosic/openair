/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/gatt.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include "at_cmd.h"
#include "at_cmd_gatt_client.h"
#include "at_cmd_set_common.h"

/*
 * AT+BLEGATTWRCCCD=<conn_idx>,<value_handle>,<ccc_handle>,<ccc_value>
 *
 * Subscribe or unsubscribe from GATT notifications/indications.
 *
 * Parameters:
 *   conn_idx      - Connection index
 *   value_handle  - Characteristic value handle (where notifications come from)
 *   ccc_handle    - CCCD (Client Characteristic Configuration Descriptor) handle
 *   ccc_value     - 1 (NOTIFY), 2 (INDICATE), 0 (unsubscribe)
 */

#define CMD_NAME      "BLEGATTWRCCCD"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),W,W,W"
#define CMD_PARM_DESC "<conn_idx>,<value_handle>,<ccc_handle>,<ccc_value>"
#define CMD_PARM_NUM  4
#define RSP_PARM_FMT  "B,W,B"
#define RSP_PARM_NUM  3

LOG_MODULE_REGISTER(blegattwrcccd, CONFIG_AT_CMD_SET_LOG_LEVEL);

static int handle_subscribe(struct bt_conn *conn, uint8_t conidx, uint16_t value_handle,
			    uint16_t ccc_handle, uint16_t ccc_val)
{
	if (!ccc_val) {
		/* Unsubscribe: locate the active slot and call bt_gatt_unsubscribe */
		at_cmd_gatt_sub_slot_t *slot = at_cmd_gatt_client_sub_find(conidx, value_handle);

		if (!slot) {
			/* No active subscription — already unsubscribed, treat as success */
			LOG_INF("No active subscription for conn %u handle 0x%04x (already "
				"unsubscribed)",
				conidx, value_handle);
			return 0;
		}

		int err = at_cmd_gatt_client_unsubscribe(conn, slot);

		if (err) {
			LOG_ERR("bt_gatt_unsubscribe failed (err %d)", err);
			/* Free slot even on error to avoid memory leak.
			 * The slot is no longer usable if unsubscribe fails
			 * (e.g., connection lost, invalid handle).
			 */
			at_cmd_gatt_client_sub_free(slot);
			return err;
		}

		at_cmd_gatt_client_sub_free(slot);
		return 0;
	}

	/* Reject duplicate subscription to prevent pool exhaustion */
	if (at_cmd_gatt_client_sub_find(conidx, value_handle)) {
		LOG_WRN("Already subscribed: conn %u handle 0x%04x", conidx, value_handle);
		return -EALREADY;
	}

	at_cmd_gatt_sub_slot_t *slot = at_cmd_gatt_client_sub_alloc(conidx);

	if (!slot) {
		LOG_ERR("Subscribe pool full for conn %u", conidx);
		return -ENOMEM;
	}

	slot->params.value_handle = value_handle;
	slot->params.ccc_handle = ccc_handle;
	slot->params.value = ccc_val;

	int err = at_cmd_gatt_client_subscribe(conn, slot);

	if (err && err != -EALREADY) {
		LOG_ERR("bt_gatt_subscribe failed (err %d)", err);
		at_cmd_gatt_client_sub_free(slot);
		return err;
	}

	return 0;
}

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t idx = AT_PASR_GET_PARAM(param, u8, 0);
	struct bt_conn *conn = at_cmd_conn_get(idx);

	if (!conn) {
		LOG_ERR("Connection index %u not found", idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	uint16_t value_handle = AT_PASR_GET_PARAM(param, u16, 1);
	uint16_t ccc_handle = AT_PASR_GET_PARAM(param, u16, 2);
	uint16_t ccc_val = AT_PASR_GET_PARAM(param, u16, 3);

	/* Validate CCC value */
	if (ccc_val != BT_GATT_CCC_NOTIFY && ccc_val != BT_GATT_CCC_INDICATE && ccc_val != 0) {
		LOG_ERR("Invalid CCC value %u (expected 1, 2, or 0)", ccc_val);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	int err = handle_subscribe(conn, idx, value_handle, ccc_handle, ccc_val);

	if (err) {
		AT_CMD_ERRNO_TO_PARAM(err, param);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
