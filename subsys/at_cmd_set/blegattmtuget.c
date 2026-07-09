/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLEGATTMTUGET"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) ")"
#define CMD_PARM_DESC "<conn_idx>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "W"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(blegattmtuget, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	uint16_t mtu = bt_gatt_get_uatt_mtu(conn);

	LOG_DBG("Connection[%" PRIu8 "] UATT MTU = %" PRIu16, idx, mtu);

	at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, mtu);
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
