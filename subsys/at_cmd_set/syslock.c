/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "SYSLOCK"
#define CMD_PARM_FMT  "S(2)"
#define CMD_PARM_DESC "<" PARAM_ON ">"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "S"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(syslock, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		const char *state = at_cmd_is_locked(param->ch) ? PARAM_ON : PARAM_OFF;

		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, state);
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t len = AT_PASR_GET_PARAM_LEN(param, 0);
	const char *val = AT_PASR_GET_PARAM(param, string, 0);

	if (len == sizeof(PARAM_ON) - 1 && strncmp(val, PARAM_ON, len) == 0) {
		at_cmd_lock(param->ch, true);
		LOG_INF("Channel %u locked", param->ch);
	} else {
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
	}
}

AT_COMMAND_LOCK_EXEMPT(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC,
		       RSP_PARM_FMT, RSP_PARM_NUM);
