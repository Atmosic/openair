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

#define CMD_NAME      "BLEGATTDISCCHAR"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),A(2~16)"
#define CMD_PARM_DESC "<conn_idx>,<uuid>"
#define CMD_PARM_NUM  2
#define RSP_PARM_FMT  "B,W,W,B,A(2~16)"
#define RSP_PARM_NUM  5

LOG_MODULE_REGISTER(blegattdiscchar, CONFIG_AT_CMD_SET_LOG_LEVEL);

void blegattdiscchar_result_cb(uint8_t ch, uint8_t conidx, uint16_t decl_handle,
			       uint16_t val_handle, uint8_t props, const uint8_t *uuid,
			       uint8_t uuid_len)
{
	const at_cmd_t *cmd = AT_CMD_EVT_DEF(CMD_NAME, RSP_PARM_FMT, RSP_PARM_NUM);

	at_cmd_resp(ch, at_all, cmd, 0, RSP_PARM_NUM, conidx, decl_handle, val_handle, props, uuid,
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

	const uint8_t *uuid_bytes = AT_PASR_GET_PARAM(param, array, 1);
	uint16_t uuid_len = AT_PASR_GET_PARAM_LEN(param, 1);

	if (at_cmd_gatt_client_uuid_set(ctx, uuid_bytes, uuid_len)) {
		LOG_ERR("Invalid UUID length %u", uuid_len);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	ctx->disc_cmd = AT_GATTC_DISC_CHAR;
	ctx->disc_max = 0;
	ctx->disc.start_handle = BT_ATT_FIRST_ATTRIBUTE_HANDLE;
	ctx->disc.end_handle = BT_ATT_LAST_ATTRIBUTE_HANDLE;
	ctx->disc.type = BT_GATT_DISCOVER_CHARACTERISTIC;

	int err = at_cmd_gatt_client_discover(conn, ctx);

	if (err) {
		LOG_ERR("at_cmd_gatt_client_discover failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
