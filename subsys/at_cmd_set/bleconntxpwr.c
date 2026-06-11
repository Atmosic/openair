/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#ifdef CONFIG_VND_API_SET_CON_TX_POWER
#include "atm_vendor_api.h"
#endif

#define CMD_NAME          "BLECONNTXPWR"
#define CMD_PARM_FMT      "B(0~" STRINGIFY(CONN_IDX_MAX) "),b(-20~10)"
#define CMD_PARM_DESC     "<conn_idx>,<dBm>"
#define CMD_PARM_NUM      2
#define RSP_PARM_PAIR_FMT "B,b,b"
#define RSP_PARM_PAIR_NUM 3
#define RSP_PARM_FMT      LISTIFY(CONFIG_BT_MAX_CONN, _AT_CMD_FMT_ITEM, (), RSP_PARM_PAIR_FMT)
#define RSP_PARM_NUM      (CONFIG_BT_MAX_CONN * RSP_PARM_PAIR_NUM)

LOG_MODULE_REGISTER(bleconntxpwr, CONFIG_AT_CMD_SET_LOG_LEVEL);

/**
 * AT COMMAND HANDLER
 *******************************************************************************
 */
static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_exec) {
		uint8_t idx = AT_PASR_GET_PARAM(param, u8, 0);
		int8_t dbm = AT_PASR_GET_PARAM(param, i8, 1);

		struct bt_conn *conn = at_cmd_conn_get(idx);

		if (!conn) {
			LOG_ERR("Connection index %u not found", idx);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
			return;
		}

#ifdef CONFIG_VND_API_SET_CON_TX_POWER
		uint16_t conn_hdl;
		int err = bt_hci_get_conn_handle(conn, &conn_hdl);

		if (err) {
			LOG_ERR("Failed to get HCI handle (err %d)", err);
			AT_CMD_ERRNO_TO_PARAM(err, param);
			return;
		}

		uint8_t result = atm_vendor_set_con_tx_power(conn_hdl, dbm);

		if (result != TX_POWER_VALUE_ADJUST_SUCCESS) {
			LOG_ERR("Failed to set connection TX power to %" PRId8 " dBm", dbm);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_ENOTSUP, param);
			return;
		}

		LOG_INF("Connection[%" PRIu8 "] TX power set to %" PRId8 " dBm", idx, dbm);
#else
		ARG_UNUSED(dbm);
		LOG_WRN("CONFIG_VND_API_SET_CON_TX_POWER not enabled");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_ENOTSUP, param);
#endif
	} else if (param->type == at_cmd_type_query) {
		uint8_t rsp_idx = 0;
		uint8_t rsp_total = 0;

		for (uint8_t i = 0; i < CONFIG_BT_MAX_CONN; i++) {
			if (at_cmd_conn_get(i)) {
				rsp_total++;
			}
		}

		if (!rsp_total) {
			LOG_ERR("No active connections");
			return;
		}

		for (uint8_t i = 0; i < CONFIG_BT_MAX_CONN; i++) {
			struct bt_conn *conn = at_cmd_conn_get(i);

			if (!conn) {
				continue;
			}

			struct bt_conn_le_tx_power tx_pwr = {0};
			int err = bt_conn_le_get_tx_power_level(conn, &tx_pwr);

			if (err) {
				LOG_ERR("Failed to get TX power for conn[%u] (err %d)", i, err);
				AT_CMD_ERRNO_TO_PARAM(err, param);
				return;
			}

			LOG_DBG("Connection[%" PRIu8 "] TX power: current=%" PRId8
				" dBm max=%" PRId8 " dBm",
				i, tx_pwr.current_level, tx_pwr.max_level);
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, rsp_idx, rsp_total,
					  RSP_PARM_PAIR_NUM, i, tx_pwr.current_level,
					  tx_pwr.max_level);
			rsp_idx++;
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
