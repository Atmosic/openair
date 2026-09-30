/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "SYSUNLOCK"
#define CMD_PARM_FMT  "S"
#define CMD_PARM_DESC "<key>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(sysunlock, CONFIG_AT_CMD_SET_LOG_LEVEL);

BUILD_ASSERT(sizeof(CONFIG_AT_CMD_SYSUNLOCKKEY_VALUE) > 1,
	     "CONFIG_AT_CMD_SYSUNLOCKKEY_VALUE must not be empty");

static const char expected_key[] = CONFIG_AT_CMD_SYSUNLOCKKEY_VALUE;

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t len = AT_PASR_GET_PARAM_LEN(param, 0);
	const char *key = AT_PASR_GET_PARAM(param, string, 0);

	if (len != (sizeof(expected_key) - 1) || memcmp(key, expected_key, len)) {
		LOG_WRN("Channel %u unlock failed: invalid key", param->ch);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ACCESS_INVALID_KEY, param);
		return;
	}

	at_cmd_lock(param->ch, false);
	LOG_INF("Channel %u unlocked", param->ch);
}

AT_COMMAND_LOCK_EXEMPT(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC,
		       RSP_PARM_FMT, RSP_PARM_NUM);
