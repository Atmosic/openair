/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include "at_cmd.h"
#include "at_cmd_gatt_client.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLEGATTRD"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),W,W"
#define CMD_PARM_DESC "<conn_idx>,<handle>,<offset>"
#define CMD_PARM_NUM  3
#define RSP_PARM_FMT  "B,W,A(0~" AT_CMD_XSTR(CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN) ")"
#define RSP_PARM_NUM  3

LOG_MODULE_REGISTER(blegattrd, CONFIG_AT_CMD_SET_LOG_LEVEL);

void blegattrd_result_cb(uint8_t ch, uint8_t conidx, uint16_t handle, const uint8_t *data,
			 uint16_t len)
{
	const at_cmd_t *cmd = AT_CMD_EVT_DEF(CMD_NAME, RSP_PARM_FMT, RSP_PARM_NUM);

	at_cmd_resp(ch, at_all, cmd, 0, RSP_PARM_NUM, conidx, handle, data, len);
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

	if (ctx->rd_busy) {
		LOG_WRN("Read already in progress on conn %u", idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	uint16_t handle = AT_PASR_GET_PARAM(param, u16, 1);
	uint16_t offset = AT_PASR_GET_PARAM(param, u16, 2);

	ctx->rd.handle_count = 1;
	ctx->rd.single.handle = handle;
	ctx->rd.single.offset = offset;

	int err = at_cmd_gatt_client_read(conn, ctx);

	if (err) {
		LOG_ERR("at_cmd_gatt_client_read failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
