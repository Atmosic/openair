/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt_dyn.h"

#define CMD_NAME      "BLEGATTSVCACTIVE"
#define CMD_PARM_FMT  "A(1)"
#define CMD_PARM_DESC "<reason>"
#define CMD_PARM_NUM  1

LOG_MODULE_REGISTER(blegattsvcactive, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_exec) {
		uint8_t reason = AT_PASR_GET_PARAM(param, array, 0)[0];

		at_cmd_result_t result =
			at_cmd_gatt_dyn_svc_activate((at_cmd_gatt_dyn_svc_reason_t)reason);

		if (result.err || result.app_err) {
			AT_CMD_RESULT_TO_PARAM(result, param);
		}

	} else if (param->type == at_cmd_type_query) {
		/* Return the only currently defined reason value */
		uint8_t reason = (uint8_t)AT_GATT_DYN_SVC_REASON_APPLY;

		at_cmd_resp(param->ch, at_all, param->cmd, 0, 1, &reason, 1);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, "A(1)", 1);
