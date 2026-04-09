/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2021-2026 Atmosic
 */

#include "at_cmd.h"
#include "at_cmd_internal.h"
#include <zephyr/logging/log.h>
#include <zephyr/sys/__assert.h>
#include <inttypes.h>
#include "arch.h"

#define CMD_NAME      "NAME"
#define CMD_PARM_FMT  "S(~32)"
#define CMD_PARM_DESC "<device name>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(at_cmd_setdevicename, CONFIG_ATM_AT_CMD_SET_LOG_LEVEL);

/*
 * AT COMMAND HANDLER
 */
static void fn_cmd_handler(at_cmd_param_t *par)
{
	LOG_INF("setdevicename: at_type (%" PRId32 ")", par->type);

	if (par->type == at_cmd_type_exec && par->err == AT_CMD_ERR_NO_ERROR) {
		uint16_t len = AT_PASR_GET_PARAM_LEN(par, 0);
		char *dname = AT_PASR_GET_PARAM(par, string, 0);

		if (!g_callbacks_initialized || !g_at_callbacks.set_device_name) {
			LOG_ERR("Set device name callback not registered");
			par->app_err = AT_CMD_EXT_ERR_WRITE_FAILED;
		} else {
			par->app_err = g_at_callbacks.set_device_name((uint8_t *)dname, len);
		}

		if (par->app_err != AT_CMD_EXT_ERR_SUCCESS) {
			par->err = AT_CMD_ERR_SPECIFIC_ERR;
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
