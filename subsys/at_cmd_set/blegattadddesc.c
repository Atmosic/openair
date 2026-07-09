/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt_dyn.h"

#define CMD_NAME      "BLEGATTADDDESC"
#define CMD_PARM_FMT  "A(2~2)"
#define CMD_PARM_DESC "<uuid>"
#define CMD_PARM_NUM  1

LOG_MODULE_REGISTER(blegattadddesc, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	/* uuid16: A(2~2) = 2-byte MSB-first 16-bit UUID */
	uint8_t *uuid16_be2 = AT_PASR_GET_PARAM(param, array, 0);

	at_cmd_result_t result = at_cmd_gatt_dyn_add_desc(uuid16_be2);

	if (result.err || result.app_err) {
		AT_CMD_RESULT_TO_PARAM(result, param);
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, "", 0);
