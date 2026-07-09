/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME      "TAGRESET"
#define CMD_PARM_FMT  "B(0~1)"
#define CMD_PARM_DESC "<0=cold reboot|1=factory reset>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(tagreset, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	at_cmd_tag_reset_reason_t reason =
		(at_cmd_tag_reset_reason_t)AT_PASR_GET_PARAM(param, u8, 0);
	if ((reason != AT_CMD_TAG_RESET_REASON_COLD_REBOOT) &&
	    (reason != AT_CMD_TAG_RESET_REASON_FACTORY_RESET)) {
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}

	if (!ctx->callbacks.tag_cb.reset_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.reset_cb(reason);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
