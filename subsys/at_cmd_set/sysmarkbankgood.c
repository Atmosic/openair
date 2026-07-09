/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <bootutil/bootutil.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME     "SYSMKBANKGOOD"
#define CMD_PARM_NUM 0
#define RSP_PARM_NUM 0

LOG_MODULE_REGISTER(sysmarkbankgood, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	for (int i = 0; i < CONFIG_UPDATEABLE_IMAGE_NUMBER; i++) {
		if (boot_swap_type_multi(i) != BOOT_SWAP_TYPE_REVERT) {
			continue;
		}

		LOG_INF("Image%d needs confirmation to prevent revert", i);

		int err = boot_set_confirmed_multi(i);

		if (err) {
			LOG_ERR("Failed to confirm image%d: %d", i, err);
			AT_CMD_ERRNO_TO_PARAM(err, param);
			return;
		}

		LOG_INF("Image%d confirmed successfully", i);
	}
}

AT_COMMAND(CMD_NAME, NULL, CMD_PARM_NUM, fn_cmd_handler, NULL, NULL, RSP_PARM_NUM);
