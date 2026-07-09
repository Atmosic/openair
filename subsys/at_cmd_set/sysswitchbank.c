/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/reboot.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_sysdfu_proc.h"
#include "atm_vendor_dfu.h"

#define CMD_NAME     "SYSSWITCHBANK"
#define CMD_PARM_NUM 0
#define RSP_PARM_NUM 0

LOG_MODULE_REGISTER(sysswitchbank, CONFIG_AT_CMD_SET_LOG_LEVEL);

__weak void at_cmd_sys_switch_bank_reboot(void)
{
	LOG_INF("Rebooting to apply new firmware");
	sys_reboot(SYS_REBOOT_COLD);
}

static void reboot_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	at_cmd_sys_switch_bank_reboot();
}

static K_WORK_DEFINE(reboot_work, reboot_work_handler);

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		param->err = AT_CMD_ERR_WRONG_EXECUTE_TYPE;
		return;
	}

	if (!at_cmd_sysdfu_switch_bank_en()) {
		LOG_ERR("DFU transfer not complete");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_SYS_NOT_READY, param);
		return;
	}

	int ret = atm_vendor_dfu_request_upgrade();

	if (ret) {
		LOG_ERR("atm_vendor_dfu_request_upgrade failed: %d", ret);
		AT_CMD_ERRNO_TO_PARAM(ret, param);
		return;
	}

	/* Defer reboot so the OK response is transmitted first. */
	k_work_submit(&reboot_work);
}

AT_COMMAND(CMD_NAME, NULL, CMD_PARM_NUM, fn_cmd_handler, NULL, NULL, RSP_PARM_NUM);
