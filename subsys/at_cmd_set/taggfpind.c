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
  AT+TAGGFPIND=<action>
Parameters:
  action: 1 = single press
              - Unpaired: Start FHN Discoverable advertising (Model ID)
              - Provisioned: Stop "Play Sound" triggered by app
              - Reverse Ringing active: Stop reverse ringing
          2 = double press
              - Unpaired: Not used
              - Provisioned: Enable "Identifier Read State" for DULT (5-min window)
              - Reverse Ringing inactive: Start reverse ringing
              - Reverse Ringing active: Stop reverse ringing
*/

#define CMD_NAME      "TAGGFPIND"
#define CMD_PARM_FMT  "B(1~2)"
#define CMD_PARM_DESC "<1: single press|2: double press>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(taggfpind, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	if (!ctx->callbacks.tag_cb.gfp_ind_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	at_cmd_tag_gfp_ind_action_t action =
		(at_cmd_tag_gfp_ind_action_t)AT_PASR_GET_PARAM(param, u8, 0);

	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.gfp_ind_cb(action);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
