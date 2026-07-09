/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/att.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include "at_cmd.h"
#include "at_cmd_gatt_client.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLEGATTDISCSVCS"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),W,W,B"
#define CMD_PARM_DESC "<conn_idx>,<start_handle>,<end_handle>,<max_number>"
#define CMD_PARM_NUM  4
#define RSP_PARM_FMT  "B,W,W,A(2~16)"
#define RSP_PARM_NUM  4

LOG_MODULE_REGISTER(blegattdiscsvcs, CONFIG_AT_CMD_SET_LOG_LEVEL);

void blegattdiscsvcs_result_cb(uint8_t ch, uint8_t conidx, uint16_t start_handle,
			       uint16_t end_handle, const uint8_t *uuid, uint8_t uuid_len)
{
	const at_cmd_t *cmd = AT_CMD_EVT_DEF(CMD_NAME, RSP_PARM_FMT, RSP_PARM_NUM);

	at_cmd_resp(ch, at_all, cmd, 0, RSP_PARM_NUM, conidx, start_handle, end_handle, uuid,
		    (uint16_t)uuid_len);
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

	at_cmd_gatt_client_conn_t *ctx = at_cmd_gatt_client_conn_get(idx);

	if (!ctx) {
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	if (ctx->disc_busy) {
		LOG_WRN("Discovery already in progress on conn %u", idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	uint16_t start_handle = AT_PASR_GET_PARAM(param, u16, 1);
	uint16_t end_handle = AT_PASR_GET_PARAM(param, u16, 2);
	uint8_t max_number = AT_PASR_GET_PARAM(param, u8, 3);

	if (start_handle < BT_ATT_FIRST_ATTRIBUTE_HANDLE ||
	    end_handle > BT_ATT_LAST_ATTRIBUTE_HANDLE || start_handle > end_handle) {
		LOG_ERR("Invalid handle range 0x%04x-0x%04x", start_handle, end_handle);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}

	ctx->disc_cmd = AT_GATTC_DISC_SVCS;
	ctx->disc_max = max_number;
	ctx->disc.uuid = NULL;
	ctx->disc.start_handle = start_handle;
	ctx->disc.end_handle = end_handle;
	ctx->disc.type = BT_GATT_DISCOVER_PRIMARY;

	int err = at_cmd_gatt_client_discover(conn, ctx);

	if (err) {
		LOG_ERR("at_cmd_gatt_client_discover failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
