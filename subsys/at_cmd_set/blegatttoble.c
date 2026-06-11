/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt.h"

#define CMD_NAME      "BLEGATTTOBLE"
#define CMD_PARM_FMT  "B,W(0~65535),B,A(0~1024)"
#define CMD_PARM_DESC "<conidx>,<handle>,<action(AT_GATT_ACT_*)>,<data>"
#define CMD_PARM_NUM  4

LOG_MODULE_REGISTER(blegatttoble, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_exec) {
		uint8_t conidx = AT_PASR_GET_PARAM(param, u8, 0);
		uint16_t handle = AT_PASR_GET_PARAM(param, u16, 1);
		at_cmd_gatt_act_t action = (at_cmd_gatt_act_t)AT_PASR_GET_PARAM(param, u8, 2);
		uint16_t data_len = AT_PASR_GET_PARAM_LEN(param, 3);
		uint8_t *data = AT_PASR_GET_PARAM(param, array, 3);

		/* Validate connection index */
		struct bt_conn *conn = at_cmd_conn_get(conidx);
		if (!conn) {
			LOG_ERR("Invalid connection index: %u", conidx);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_BLE_EINVAL, param);
			return;
		}

		/* Send GATT notification or indication */
		at_cmd_result_t result = at_cmd_gatt_to_ble(conidx, handle, action, data, data_len);
		if (result.err || result.app_err) {
			AT_CMD_RESULT_TO_PARAM(result, param);
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, NULL, 0);
