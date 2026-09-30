/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME      "TAGRANGING"
#define CMD_PARM_FMT  "B(0~1),B"
#define CMD_PARM_DESC "<0: disable|1: enable>,<0x01: UWB|0x02: BLE CS|0x03: all>"
#define CMD_PARM_NUM  2
#define RSP_PARM_FMT  "B"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(tagranging, CONFIG_AT_CMD_SET_LOG_LEVEL);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}
	if (!ctx->callbacks.tag_cb.ranging_gate_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}
	if (param->type == at_cmd_type_query) {
		uint8_t tech_mask = 0;
		at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.ranging_gate_cb(
			AT_CMD_TAG_OP_GET, AT_CMD_TAG_RANGING_GATE_OFF, &tech_mask);
		if (ret != AT_CMD_TAG_NO_ERR) {
			param->err = AT_CMD_ERR_SPECIFIC_ERR;
			param->app_err = ret;
			return;
		}
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, tech_mask);
		return;
	}
	if (param->type != at_cmd_type_exec) {
		param->err = AT_CMD_ERR_WRONG_EXECUTE_TYPE;
		return;
	}

	at_cmd_tag_ranging_gate_action_t action = AT_PASR_GET_PARAM(param, u8, 0)
							  ? AT_CMD_TAG_RANGING_GATE_ON
							  : AT_CMD_TAG_RANGING_GATE_OFF;
	uint8_t tech_mask = AT_PASR_GET_PARAM(param, u8, 1);
	if (tech_mask == 0 || (tech_mask & ~AT_CMD_TAG_RANGING_TECH_MASK_ALL)) {
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}

	at_cmd_tag_err_t ret =
		ctx->callbacks.tag_cb.ranging_gate_cb(AT_CMD_TAG_OP_SET, action, &tech_mask);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
