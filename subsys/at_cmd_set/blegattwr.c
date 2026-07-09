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
 * AT+BLEGATTWR=<conn_idx>,<handle>,<data>
 *
 * Write characteristic value with response.
 * For CCCD subscribe/unsubscribe operations, use AT+BLEGATTWRCCCD instead.
 */

#define CMD_NAME "BLEGATTWR"
#define CMD_PARM_FMT                                                                               \
	"B(0~" STRINGIFY(CONN_IDX_MAX) "),W,A(1~" STRINGIFY( \
		CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN) ")"
#define CMD_PARM_DESC "<conn_idx>,<handle>,<data_array>"
#define CMD_PARM_NUM  3
#define RSP_PARM_FMT  "B,W,B"
#define RSP_PARM_NUM  3

LOG_MODULE_REGISTER(blegattwr, CONFIG_AT_CMD_SET_LOG_LEVEL);

void blegattwr_result_cb(uint8_t ch, uint8_t conidx, uint16_t handle, uint8_t att_err)
{
	const at_cmd_t *cmd = AT_CMD_EVT_DEF(CMD_NAME, RSP_PARM_FMT, RSP_PARM_NUM);

	at_cmd_resp(ch, at_all, cmd, 0, RSP_PARM_NUM, conidx, handle, att_err);
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

	uint16_t handle = AT_PASR_GET_PARAM(param, u16, 1);
	const uint8_t *data = AT_PASR_GET_PARAM(param, array, 2);
	uint16_t data_len = AT_PASR_GET_PARAM_LEN(param, 2);

	/* Plain write with response */
	if (ctx->wr_busy) {
		LOG_WRN("Write already in progress on conn %u", idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	uint16_t capped = MIN(data_len, (uint16_t)CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN);

	memcpy(ctx->wr_buf, data, capped);

	ctx->wr.handle = handle;
	ctx->wr.offset = 0;
	ctx->wr.data = ctx->wr_buf;
	ctx->wr.length = capped;

	int err = at_cmd_gatt_client_write(conn, ctx);

	if (err) {
		LOG_ERR("at_cmd_gatt_client_write failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
