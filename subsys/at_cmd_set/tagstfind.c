/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

/*
Command:
  AT+TAGSTFIND=<times>
Parameters:
  times : Number of button presses (only 1 is valid)
        1 = single press:
            - If tag is ringing: stops the ring (priority behavior, no further action).
            - If tag is not ringing: confirms STF pairing (OOB onboarding).
*/

#define CMD_NAME      "TAGSTFIND"
#define CMD_PARM_FMT  "B(1~1)"
#define CMD_PARM_DESC "<1: single press — stop ring if ringing, else confirm pairing>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(tagstfind, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		param->err = AT_CMD_ERR_WRONG_EXECUTE_TYPE;
		return;
	}

	if (!ctx->callbacks.tag_cb.stfind_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	uint8_t times = AT_PASR_GET_PARAM(param, u8, 0);

	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.stfind_cb(times);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
