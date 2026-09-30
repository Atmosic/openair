/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME      "TAGRANGINGCAPCS"
#define CMD_PARM_FMT  "B(1~4)"
#define CMD_PARM_DESC "<sec_type: 1|2|3|4>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "B"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(tagrangingcapcs, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}
	if (!ctx->callbacks.tag_cb.ranging_cap_cs_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}
	if (param->type == at_cmd_type_query) {
		at_cmd_tag_ranging_cap_cs_t cap = {0};
		at_cmd_tag_err_t ret =
			ctx->callbacks.tag_cb.ranging_cap_cs_cb(AT_CMD_TAG_OP_GET, &cap);
		if (ret != AT_CMD_TAG_NO_ERR) {
			param->err = AT_CMD_ERR_SPECIFIC_ERR;
			param->app_err = ret;
			return;
		}
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, cap.sec_type);
		return;
	}
	if (param->type != at_cmd_type_exec) {
		param->err = AT_CMD_ERR_WRONG_EXECUTE_TYPE;
		return;
	}

	at_cmd_tag_ranging_cap_cs_t cap = {
		.sec_type = AT_PASR_GET_PARAM(param, u8, 0),
	};
	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.ranging_cap_cs_cb(AT_CMD_TAG_OP_SET, &cap);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
