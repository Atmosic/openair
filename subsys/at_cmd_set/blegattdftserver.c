/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt.h"

#define CMD_NAME      "BLEGATTDFTSERVER"
#define CMD_PARM_FMT  "S"
#define CMD_PARM_DESC "<" PARAM_ON "|" PARAM_OFF ">"
#define CMD_PARM_NUM  1
#define CMD_RSP_FMT   "S"
#define CMD_RSP_NUM   1

LOG_MODULE_REGISTER(blegattdftserver, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_exec) {
		const char *action_str = AT_PASR_GET_PARAM(param, string, 0);
		size_t action_len = AT_PASR_GET_PARAM_LEN(param, 0);
		bool enable;

		if ((action_len == strlen(PARAM_ON)) && !memcmp(action_str, PARAM_ON, action_len)) {
			enable = true;
		} else if ((action_len == strlen(PARAM_OFF)) &&
			   !memcmp(action_str, PARAM_OFF, action_len)) {
			enable = false;
		} else {
			LOG_ERR("Invalid parameter: expected ON or OFF");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}

		at_cmd_result_t result = at_cmd_gatt_dft_server_set(enable);
		if (result.err || result.app_err) {
			AT_CMD_RESULT_TO_PARAM(result, param);
		}

	} else if (param->type == at_cmd_type_query) {
		bool enabled = at_cmd_gatt_dft_server_get();
		at_cmd_resp(param->ch, at_all, param->cmd, 0, 1, enabled ? PARAM_ON : PARAM_OFF);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, CMD_RSP_FMT,
	   CMD_RSP_NUM);
