/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/conn.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLESMPPAIRREQ"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),B(0~4),B(0~1),B(0~1),B(1~4)"
#define CMD_PARM_DESC "<conn_idx>,<io_cap>,<oob>,<bond>,<sec_level>"
#define CMD_PARM_NUM  5

LOG_MODULE_REGISTER(blesmppairreq, CONFIG_AT_CMD_SET_LOG_LEVEL);

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
	uint8_t io_cap = AT_PASR_GET_PARAM(param, u8, 1);
	uint8_t oob = AT_PASR_GET_PARAM(param, u8, 2);
	uint8_t bond = AT_PASR_GET_PARAM(param, u8, 3);
	uint8_t sec_level = AT_PASR_GET_PARAM(param, u8, 4);

	ARG_UNUSED(oob);

	struct bt_conn *conn = at_cmd_conn_get(idx);

	if (!conn) {
		LOG_ERR("Connection index %u not found", idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	const struct bt_conn_auth_cb *auth_cb = at_cmd_smp_get_auth_cb(io_cap);

	if (!auth_cb) {
		LOG_ERR("Invalid io_cap %u", io_cap);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	int err = bt_conn_auth_cb_overlay(conn, auth_cb);

	if (err) {
		LOG_ERR("bt_conn_auth_cb_overlay failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}

	/* Set per-connection bondable mode; -EALREADY means already in the
	 * requested state, which is acceptable.
	 */
	err = bt_conn_set_bondable(conn, bond);
	if (err && (err != -EALREADY)) {
		LOG_ERR("bt_conn_set_bondable failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}

	err = bt_conn_set_security(conn, (bt_security_t)sec_level);
	if (err) {
		LOG_ERR("bt_conn_set_security failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, NULL, 0);
