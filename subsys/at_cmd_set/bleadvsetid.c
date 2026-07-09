/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "BLEADVSETID"
#define CMD_PARM_FMT      "B,B"
#define CMD_PARM_DESC     "<adv_idx>,<bt_id>"
#define CMD_PARM_NUM      2
#define RSP_PARM_PAIR_FMT "B,B"
#define RSP_PARM_PAIR_NUM 2
#define RSP_PARM_FMT      AT_CMD_RSP_FMT_REPEAT(RSP_PARM_PAIR_FMT)
#define RSP_PARM_NUM      AT_CMD_RSP_PARM_NUM_REPEAT(RSP_PARM_PAIR_NUM)

LOG_MODULE_REGISTER(bleadvsetid, CONFIG_AT_CMD_SET_LOG_LEVEL);

/**
 * AT COMMAND HANDLER
 *******************************************************************************
 */
static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (param->type == at_cmd_type_exec) {
		uint8_t idx = AT_PASR_GET_PARAM(param, u8, 0);
		uint8_t bt_id = AT_PASR_GET_PARAM(param, u8, 1);
		if (idx >= AT_CMD_ADV_MAX_INST) {
			LOG_ERR("Invalid advertising index %u, max %u", idx, AT_CMD_ADV_MAX_INST);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ADV_INVALID_INDEX, param);
			return;
		}

		if (ctx->adv_enabled[idx]) {
			LOG_ERR("Cannot change bt_id while advertising on instance %u", idx);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ADV_ALREADY_ENABLED, param);
			return;
		}

		ctx->adv_bt_id[idx] = bt_id;
		LOG_INF("Set bt_id %u for adv instance %u", bt_id, idx);

#ifdef CONFIG_BT_EXT_ADV
		/* Delete the existing advertising set so a new one can be created with the new
		 * bt_id */
		if (ctx->adv_set[idx]) {
			int err = bt_le_ext_adv_delete(ctx->adv_set[idx]);
			if (err) {
				LOG_ERR("Failed to delete advertising set (err %d)", err);
				AT_CMD_ERRNO_TO_PARAM(err, param);
				return;
			}
			ctx->adv_set[idx] = NULL;
		}
#endif
	} else if (param->type == at_cmd_type_query) {
		for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, i, AT_CMD_ADV_MAX_INST, 2, i,
					  ctx->adv_bt_id[i]);
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
