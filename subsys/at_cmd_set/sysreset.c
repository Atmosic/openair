/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/sys/reboot.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "SYSRESET"
#define CMD_PARM_FMT  "B(0~1)"
#define CMD_PARM_DESC "<type: 0=warm, 1=cold>"
#define CMD_PARM_NUM  1

LOG_MODULE_REGISTER(sysreset, CONFIG_AT_CMD_SET_LOG_LEVEL);

__weak void at_cmd_sys_reset(uint8_t type)
{
	LOG_INF("Resetting device (type=%u)", type);
	log_flush();
	sys_reboot(type == SYS_REBOOT_WARM ? SYS_REBOOT_WARM : SYS_REBOOT_COLD);
}

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if ((param->err != AT_CMD_ERR_NO_ERROR) || (param->type != at_cmd_type_exec)) {
		return;
	}

	uint8_t type = AT_PASR_GET_PARAM(param, u8, 0);

	at_cmd_sys_reset(type);
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, NULL, 0);
