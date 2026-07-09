/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"
#include "at_cmd_sysdfu_proc.h"
#include "atm_vendor_dfu.h"

#define CMD_NAME      "SYSDFU"
#define CMD_PARM_FMT  "B(0~1),D(1~),B(0~1)"
#define CMD_PARM_DESC "<type: 0=FW>,<length>,<crc_en: 0~1>"
#define CMD_PARM_NUM  3
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

LOG_MODULE_REGISTER(sysdfu, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	uint8_t type = AT_PASR_GET_PARAM(param, u8, 0);

	if (type) {
		/* Only firmware (type=0) is supported; atm_vendor_dfu does not
		 * handle NVDS or other partition types. */
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	uint32_t total_len = AT_PASR_GET_PARAM(param, u32, 1);
	bool crc_en = (bool)AT_PASR_GET_PARAM(param, u8, 2);

	int ret = atm_vendor_dfu_init();

	if (ret) {
		LOG_ERR("atm_vendor_dfu_init failed: %d", ret);
		AT_CMD_ERRNO_TO_PARAM(ret, param);
		return;
	}
	atm_vendor_dfu_reset();

	ret = at_cmd_sysdfu_proc_start(param->ch, total_len, crc_en);
	if (ret) {
		AT_CMD_ERRNO_TO_PARAM(ret, param);
		return;
	}

	/* Return OK — UART bytes are now routed to the RDP layer by the
	 * application until at_cmd_sysdfu_is_active() becomes false. */
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
