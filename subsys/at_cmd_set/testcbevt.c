/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>

#include "arch.h"
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_event.h"

LOG_MODULE_REGISTER(testcbevt, CONFIG_AT_CMD_SET_LOG_LEVEL);

#define CMD_NAME      "TESTCBEVT"
#define CMD_PARM_FMT  "B"
#define CMD_PARM_DESC "<action>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  NULL
#define RSP_PARM_NUM  0

/**
 * @brief Sample callback function
 */
static void sample_callback(uint8_t ch)
{
	at_cmd_evt_test(ch, NULL, 0);
}

/**
 * Actions:
 * 0 - Register callback via at_cmd_set_callbacks_register()
 * 1 - Invoke registered callback
 */
static void testcb_handler(at_cmd_param_t *param)
{

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type != at_cmd_type_exec) {
		param->err = AT_CMD_ERR_WRONG_EXECUTE_TYPE;
		return;
	}

	uint8_t action = AT_PASR_GET_PARAM(param, u8, 0);
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	switch (action) {
	case 0: {
		/* Register callback */
		at_cmd_set_callbacks_t callbacks = {
			.test_cb = sample_callback,
		};
		at_cmd_set_callbacks_register(&callbacks);
		break;
	}

	case 1: {
		if (ctx && ctx->callbacks.test_cb) {
			uint8_t test_data[] = {0x01, 0x02, 0x03, 0x04};
			ctx->callbacks.test_cb(param->ch);
			at_cmd_evt_test(param->ch, test_data, sizeof(test_data));
		} else {
			LOG_ERR("test_cb not registered");
			param->err = AT_CMD_ERR_SPECIFIC_ERR;
		}
		break;
	}

	default:
		param->err = AT_CMD_ERR_WRONG_ARGU_CONTENT;
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, testcb_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
