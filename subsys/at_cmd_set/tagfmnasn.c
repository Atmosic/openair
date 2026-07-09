/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME      "TAGFMNASN"
#define CMD_PARM_FMT  "B(1)"
#define CMD_PARM_DESC "<1=enable SN lookup>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(tagfmnasn, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	uint8_t enable = AT_PASR_GET_PARAM(param, u8, 0);
	if (enable != 1) {
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}

	if (!ctx->callbacks.tag_cb.fmna_sn_lookup_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.fmna_sn_lookup_cb();
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
