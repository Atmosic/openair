/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "BLEGAPCREATECONN"
#define CMD_PARM_FMT      "B(0~1),A(6~6),B(1~255)"
#define CMD_PARM_DESC     "<addr_type>,<addr>,<timeout_sec>"
#define CMD_PARM_NUM      3
#define RSP_PARM_PAIR_FMT NULL
#define RSP_PARM_NUM      0

LOG_MODULE_REGISTER(blegapcreateconn, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t addr_type = AT_PASR_GET_PARAM(param, u8, 0);
	uint8_t *addr_bytes = AT_PASR_GET_PARAM(param, array, 1);
	uint16_t addr_len = AT_PASR_GET_PARAM_LEN(param, 1);

	if (addr_len != BT_ADDR_SIZE) {
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}

	if (addr_type > BT_ADDR_LE_RANDOM) {
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}

	bt_addr_le_t peer;

	peer.type = addr_type;
	sys_memcpy_swap(peer.a.val, addr_bytes, BT_ADDR_SIZE);

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

#ifdef CONFIG_AT_CMD_SET_CONN_TRACKING
	if (ctx->conn_count >= CONFIG_BT_MAX_CONN) {
		LOG_WRN("No free slot for central connection");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_ENOMEM, param);
		return;
	}
#endif

	if (ctx->scan_enabled) {
		int err = bt_le_scan_stop();

		if (err) {
			LOG_ERR("bt_le_scan_stop before create failed (err %d)", err);
			AT_CMD_RESULT_TO_PARAM(at_cmd_result_err_from_errno(err), param);
			return;
		}

		ctx->scan_enabled = false;
	}

	/* bt_conn_le_create() automatically uses LE_Extended_Create_Connection
	 * when CONFIG_BT_EXT_ADV is enabled and the controller supports it.
	 * Use continuous scan (interval == window) with the caller-supplied timeout
	 * to give the controller enough time to catch the peripheral's advertising window.
	 */
	static const struct bt_conn_le_create_param create_param = BT_CONN_LE_CREATE_PARAM_INIT(
		BT_CONN_LE_OPT_NONE, BT_GAP_SCAN_FAST_INTERVAL, BT_GAP_SCAN_FAST_INTERVAL);
	struct bt_conn_le_create_param cp = create_param;

	uint8_t timeout_sec = AT_PASR_GET_PARAM(param, u8, 2);

	cp.timeout = timeout_sec * 100; /* N × 10 ms per unit */

	/* Use a configurable supervision timeout so platforms with a faster
	 * baseband clock (e.g. INIT_BP_FREQ=64000000, which fires timers at
	 * 0.75× nominal speed) can be given enough headroom for SMP key
	 * exchange to complete before the supervision timer expires.
	 */
	static const struct bt_le_conn_param conn_param =
		BT_LE_CONN_PARAM_INIT(BT_GAP_INIT_CONN_INT_MIN, BT_GAP_INIT_CONN_INT_MAX, 0,
				      CONFIG_AT_CMD_BLEGAPCREATECONN_INIT_TIMEOUT);

	struct bt_conn *conn = NULL;
	int err = bt_conn_le_create(&peer, &cp, &conn_param, &conn);

	if (err) {
		LOG_ERR("bt_conn_le_create failed (err %d)", err);
		AT_CMD_RESULT_TO_PARAM(at_cmd_result_err_from_errno(err), param);
		return;
	}

#ifdef CONFIG_AT_CMD_SET_CONN_TRACKING
	/* Pre-register the conn while it is still in BT_CONN_STATE_CONNECTING so
	 * that AT+BLEGAPCANCELCREATECONN can find and cancel it before the link is
	 * established.  at_cmd_set_connected() skips re-insertion via its duplicate
	 * check; at_cmd_set_disconnected() handles bt_conn_unref() and removal for
	 * both the success and the cancel/fail paths.
	 * No bt_conn_ref() here — bt_conn_le_create() already gives us one
	 * reference that is released by bt_conn_unref() in at_cmd_set_disconnected().
	 */
	ctx->conns[ctx->conn_count++] = conn;
	LOG_INF("Central connection initiated at idx %u", ctx->conn_count - 1);
#endif
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_PAIR_FMT,
	   RSP_PARM_NUM);
