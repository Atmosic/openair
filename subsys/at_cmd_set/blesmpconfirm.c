/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/conn.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLESMPCONFIRM"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),B(0~1)"
#define CMD_PARM_DESC "<conn_idx>,<accept>"
#define CMD_PARM_NUM  2

LOG_MODULE_REGISTER(blesmpconfirm, CONFIG_AT_CMD_SET_LOG_LEVEL);

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
	uint8_t accept = AT_PASR_GET_PARAM(param, u8, 1);

	struct bt_conn *conn = at_cmd_conn_get(idx);

	if (!conn) {
		LOG_ERR("Connection index %u not found", idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	int err;

	if (accept) {
		err = bt_conn_auth_passkey_confirm(conn);
		if (err) {
			LOG_ERR("bt_conn_auth_passkey_confirm failed (err %d)", err);
			AT_CMD_ERRNO_TO_PARAM(err, param);
		}
	} else {
		err = bt_conn_auth_cancel(conn);
		if (err) {
			LOG_ERR("bt_conn_auth_cancel failed (err %d)", err);
			AT_CMD_ERRNO_TO_PARAM(err, param);
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, NULL, 0);
