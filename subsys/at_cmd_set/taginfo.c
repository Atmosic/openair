/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME      "TAGINFO"
#define CMD_PARM_FMT  ""
#define CMD_PARM_DESC NULL
#define CMD_PARM_NUM  0
#define VERSION_LEN   32
#define ADDR_LEN      13
/* Response format: version (S), protocol mask (B) */
#define RSP_PARM_FMT  "S,B"
#define RSP_PARM_NUM  2

LOG_MODULE_REGISTER(taginfo, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	char version[VERSION_LEN];
	at_cmd_tag_info_t info = {
		.version = version,
		.version_len = sizeof(version),
		.protocol_mask = 0,
	};
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_query) {
		param->err = AT_CMD_ERR_WRONG_EXECUTE_TYPE;
		return;
	}

	if (!ctx->callbacks.tag_cb.get_info_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.get_info_cb(&info);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
		return;
	}

	at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, version, info.protocol_mask);
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
