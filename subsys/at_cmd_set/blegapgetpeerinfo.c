/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/conn.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLEGAPGETPEERINFO"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) ")"
#define CMD_PARM_DESC "<conn_idx>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "B,A(6~6),B,B"
#define RSP_PARM_NUM  4

LOG_MODULE_REGISTER(blegapgetpeerinfo, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	struct bt_conn_info info;
	int err = bt_conn_get_info(conn, &info);

	if (err) {
		LOG_ERR("bt_conn_get_info failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}

	/* Reverse byte order for display (stack stores addresses LE) */
	uint8_t peer_addr[BT_ADDR_SIZE];

	sys_memcpy_swap(peer_addr, info.le.dst->a.val, BT_ADDR_SIZE);

	at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, (uint8_t)info.le.dst->type,
		    peer_addr, (uint16_t)BT_ADDR_SIZE, (uint8_t)info.security.level,
		    (uint8_t)info.security.enc_key_size);
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
