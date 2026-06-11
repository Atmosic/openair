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
  AT+TAGMOTIONRPT=<x>,<y>,<z>
Parameters:
  x : X-axis acceleration in cm/s² (signed 16-bit) reported by host sensor.
  y : Y-axis acceleration in cm/s² (signed 16-bit) reported by host sensor.
  z : Z-axis acceleration in cm/s² (signed 16-bit) reported by host sensor.
      Each protocol on the tag converts to its own unit independently,
      e.g. FHN Ranging classifies tilt angle derived from horizontal magnitude.
*/

#define CMD_NAME      "TAGMOTIONRPT"
#define CMD_PARM_FMT  "w,w,w"
#define CMD_PARM_DESC "<x: X-axis cm/s²>,<y: Y-axis cm/s²>,<z: Z-axis cm/s²>"
#define CMD_PARM_NUM  3
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(tagmotionrpt, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	if (!ctx->callbacks.tag_cb.motionrpt_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	int16_t x_cs2 = AT_PASR_GET_PARAM(param, i16, 0);
	int16_t y_cs2 = AT_PASR_GET_PARAM(param, i16, 1);
	int16_t z_cs2 = AT_PASR_GET_PARAM(param, i16, 2);

	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.motionrpt_cb(x_cs2, y_cs2, z_cs2);
	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
