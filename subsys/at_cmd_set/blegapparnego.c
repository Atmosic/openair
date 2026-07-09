/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLEGAPPARNEGO"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),W,W,W,W"
#define CMD_PARM_DESC "<conn_idx>,<interval_min>,<interval_max>,<latency>,<timeout>"
#define CMD_PARM_NUM  5
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(blegapparnego, CONFIG_AT_CMD_SET_LOG_LEVEL);

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
		LOG_ERR("Connection index %" PRIu8 " not found", idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	uint16_t interval_min = AT_PASR_GET_PARAM(param, u16, 1);
	uint16_t interval_max = AT_PASR_GET_PARAM(param, u16, 2);
	uint16_t latency = AT_PASR_GET_PARAM(param, u16, 3);
	uint16_t timeout = AT_PASR_GET_PARAM(param, u16, 4);

	const struct bt_le_conn_param conn_params =
		BT_LE_CONN_PARAM_INIT(interval_min, interval_max, latency, timeout);

	int err = bt_conn_le_param_update(conn, &conn_params);

	if (err) {
		LOG_ERR("bt_conn_le_param_update failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
