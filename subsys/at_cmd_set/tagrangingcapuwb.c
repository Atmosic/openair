/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME     "TAGRANGINGCAPUWB"
#define CMD_PARM_FMT "A(2~2),D,D,D,W,B,B"
#define CMD_PARM_DESC                                                                              \
	"<addr>,<channel_mask>,<preamble_mask>,<config_id_mask>,<min_ranging_int>,<min_slot_dur>," \
	"<device_role>"
#define CMD_PARM_NUM 7
#define RSP_PARM_FMT "A(2~2),D,D,D,W,B,B"
#define RSP_PARM_NUM 7

LOG_MODULE_REGISTER(tagrangingcapuwb, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}
	if (!ctx->callbacks.tag_cb.ranging_cap_uwb_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}
	if (param->type == at_cmd_type_query) {
		at_cmd_tag_ranging_cap_uwb_t cap = {0};
		at_cmd_tag_err_t ret =
			ctx->callbacks.tag_cb.ranging_cap_uwb_cb(AT_CMD_TAG_OP_GET, &cap);
		if (ret != AT_CMD_TAG_NO_ERR) {
			param->err = AT_CMD_ERR_SPECIFIC_ERR;
			param->app_err = ret;
			return;
		}

		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, cap.addr,
			    sizeof(cap.addr), cap.channel_mask, cap.preamble_mask,
			    cap.config_id_mask, cap.min_ranging_int, cap.min_slot_dur,
			    cap.device_role);
		return;
	}
	if (param->type != at_cmd_type_exec) {
		param->err = AT_CMD_ERR_WRONG_EXECUTE_TYPE;
		return;
	}

	at_cmd_tag_ranging_cap_uwb_t cap;
	memset(&cap, 0, sizeof(cap));
	if (AT_PASR_GET_PARAM_LEN(param, 0) != sizeof(cap.addr)) {
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}
	memcpy(cap.addr, AT_PASR_GET_PARAM(param, array, 0), sizeof(cap.addr));
	cap.channel_mask = AT_PASR_GET_PARAM(param, u32, 1);
	cap.preamble_mask = AT_PASR_GET_PARAM(param, u32, 2);
	cap.config_id_mask = AT_PASR_GET_PARAM(param, u32, 3);
	cap.min_ranging_int = AT_PASR_GET_PARAM(param, u16, 4);
	cap.min_slot_dur = AT_PASR_GET_PARAM(param, u8, 5);
	cap.device_role = AT_PASR_GET_PARAM(param, u8, 6);

	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.ranging_cap_uwb_cb(AT_CMD_TAG_OP_SET, &cap);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
