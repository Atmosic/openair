/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "BLEGAPGETRSSI"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) ")"
#define CMD_PARM_DESC "<conn_idx>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "b"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(blegapgetrssi, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	uint16_t conn_hdl;
	int err = bt_hci_get_conn_handle(conn, &conn_hdl);

	if (err) {
		LOG_ERR("Failed to get HCI handle (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}

	struct net_buf *buf = bt_hci_cmd_alloc(K_FOREVER);

	if (!buf) {
		LOG_ERR("Failed to allocate HCI command buffer");
		AT_CMD_ERRNO_TO_PARAM(-ENOBUFS, param);
		return;
	}

	struct bt_hci_cp_read_rssi *cp = net_buf_add(buf, sizeof(*cp));

	cp->handle = sys_cpu_to_le16(conn_hdl);

	struct net_buf *rsp;

	err = bt_hci_cmd_send_sync(BT_HCI_OP_READ_RSSI, buf, &rsp);
	if (err) {
		LOG_ERR("Read RSSI failed (err %d)", err);
		AT_CMD_ERRNO_TO_PARAM(err, param);
		return;
	}

	struct bt_hci_rp_read_rssi *rp = (void *)rsp->data;
	int8_t rssi = rp->rssi;

	net_buf_unref(rsp);

	LOG_DBG("Connection[%u] RSSI = %d dBm", idx, rssi);

	at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, rssi);
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
