/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci_types.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "BLEGAPCANCELCREATECONN"
#define CMD_PARM_FMT      ""
#define CMD_PARM_DESC     ""
#define CMD_PARM_NUM      0
#define RSP_PARM_PAIR_FMT NULL
#define RSP_PARM_NUM      0

LOG_MODULE_REGISTER(blegapcancelcreateconn, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	/* Find the connection that is still in CONNECTING state */
	struct bt_conn *connecting = NULL;

	for (uint8_t i = 0; i < ctx->conn_count; i++) {
		struct bt_conn_info info;

		if (!bt_conn_get_info(ctx->conns[i], &info) &&
		    (info.state == BT_CONN_STATE_CONNECTING)) {
			connecting = ctx->conns[i];
			break;
		}
	}

	if (!connecting) {
		LOG_WRN("No pending connection creation to cancel");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
		return;
	}

	/* bt_conn_disconnect() on a CONNECTING-state conn causes the BT host
	 * to issue an HCI LE Create Connection Cancel to the controller.
	 */
	int err = bt_conn_disconnect(connecting, BT_HCI_ERR_REMOTE_USER_TERM_CONN);

	if (err) {
		LOG_ERR("Cancel create-conn failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_PAIR_FMT,
	   RSP_PARM_NUM);
