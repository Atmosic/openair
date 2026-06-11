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
#include "at_cmd_event.h"

#define CMD_NAME          "BLEGATTMTUEXCHGREQ"
#define CMD_PARM_FMT      "B(0~" STRINGIFY(CONN_IDX_MAX) ")"
#define CMD_PARM_DESC     "<conn_idx>"
#define CMD_PARM_NUM      1
#define RSP_PARM_PAIR_FMT NULL
#define RSP_PARM_NUM      0

LOG_MODULE_REGISTER(blegattmtuexchgreq, CONFIG_AT_CMD_SET_LOG_LEVEL);

static struct bt_gatt_exchange_params mtu_params[CONFIG_BT_MAX_CONN];

static void mtu_exchange_cb(struct bt_conn *conn, uint8_t err,
			    struct bt_gatt_exchange_params *params)
{
	if (err) {
		LOG_ERR("MTU exchange failed (err %u)", err);
	} else {
		LOG_DBG("MTU exchange complete, MTU: %" PRIu16, bt_gatt_get_uatt_mtu(conn));
	}

#ifdef CONFIG_AT_EVT_BLEGATTMTUEXCHGREQ
	uint8_t idx = (uint8_t)(params - mtu_params);
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (ctx && (ctx->ch != AT_CMD_INVALID_CH)) {
		at_cmd_evt_mtuexchgreq(ctx->ch, idx, err);
	}
#else
	ARG_UNUSED(params);
#endif
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

	mtu_params[idx].func = mtu_exchange_cb;

	int err = bt_gatt_exchange_mtu(conn, &mtu_params[idx]);

	if (err) {
		LOG_ERR("bt_gatt_exchange_mtu failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_PAIR_FMT,
	   RSP_PARM_NUM);
