/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2021-2026 Atmosic
 */

#include "at_cmd.h"
#include "at_cmd_internal.h"
#include <zephyr/logging/log.h>
#include <inttypes.h>

#define CMD_NAME      "SYSRESET"
#define CMD_PARM_FMT  "B(1)"
#define CMD_PARM_DESC "<reason>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(at_cmd_sysreset, CONFIG_ATM_AT_CMD_SET_LOG_LEVEL);

/*
 * AT COMMAND HANDLER
 */
static void fn_cmd_handler(at_cmd_param_t *par)
{
	LOG_INF("sysreset: at_type (%" PRId32 "), err (%" PRId32 ")", par->type, par->err);

	if (par->type == at_cmd_type_exec && par->err == AT_CMD_ERR_NO_ERROR) {
		if (!g_callbacks_initialized || !g_at_callbacks.reset_device) {
			LOG_ERR("Reset device callback not registered");
			par->app_err = AT_CMD_EXT_ERR_WRITE_FAILED;
		} else {
			par->app_err = g_at_callbacks.reset_device();
		}

		if (par->app_err != AT_CMD_EXT_ERR_SUCCESS) {
			par->err = AT_CMD_ERR_SPECIFIC_ERR;
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
