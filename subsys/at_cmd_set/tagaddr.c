/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/util.h>
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME      "TAGADDR"
#define CMD_PARM_FMT  "B(1~7)"
#define CMD_PARM_DESC "<0x01: fmna|0x02: fhn|0x04: stf>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "B,A(6~6)"
#define RSP_PARM_NUM  2

LOG_MODULE_REGISTER(tagaddr, CONFIG_AT_CMD_SET_LOG_LEVEL);

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

	if (!ctx->callbacks.tag_cb.addr_cb) {
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	}

	uint8_t protocol = AT_PASR_GET_PARAM(param, u8, 0);

	/* Only a single protocol bit is valid (not a combination) */
	if (!IS_POWER_OF_TWO(protocol)) {
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}

	bt_addr_le_t addr = {0};
	at_cmd_tag_err_t ret = ctx->callbacks.tag_cb.addr_cb(protocol, &addr);

	if (ret != AT_CMD_TAG_NO_ERR) {
		param->err = AT_CMD_ERR_SPECIFIC_ERR;
		param->app_err = ret;
		return;
	}

	/* Convert to big-endian for display (MSB first) */
	uint8_t addr_be[BT_ADDR_SIZE];

	sys_memcpy_swap(addr_be, addr.a.val, sizeof(addr_be));
	at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, protocol, addr_be,
		    sizeof(addr_be));
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
