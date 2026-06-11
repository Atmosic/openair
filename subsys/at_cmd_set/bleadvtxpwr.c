/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <string.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "BLEADVTXPWR"
#define CMD_PARM_FMT      "B,b"
#define CMD_PARM_DESC     "<adv_idx>,<dBm>"
#define CMD_PARM_NUM      2
#define RSP_PARM_PAIR_FMT "B,b"
#define RSP_PARM_PAIR_NUM 2
#define RSP_PARM_FMT      AT_CMD_RSP_FMT_REPEAT(RSP_PARM_PAIR_FMT)
#define RSP_PARM_NUM      AT_CMD_RSP_PARM_NUM_REPEAT(RSP_PARM_PAIR_NUM)

LOG_MODULE_REGISTER(bleadvtxpwr, CONFIG_AT_CMD_SET_LOG_LEVEL);

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
		LOG_ERR("TX power setting not supported");
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
	} else if (param->type == at_cmd_type_query) {
#ifdef CONFIG_BT_EXT_ADV
		bool reported = false;
		uint8_t rsp_total = 0;
		uint8_t rsp_idx = 0;

		for (uint8_t idx = 0; idx < AT_CMD_ADV_MAX_INST; idx++) {
			if (ctx->adv_set[idx]) {
				rsp_total++;
			}
		}

		if (!rsp_total) {
			LOG_ERR("No advertising set created yet");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_ADV_SET_NOT_CREATED, param);
			return;
		}

		/* Query TX power from Zephyr BLE extended advertising info */
		for (uint8_t idx = 0; idx < AT_CMD_ADV_MAX_INST; idx++) {
			struct bt_le_ext_adv_info info;

			if (!ctx->adv_set[idx]) {
				LOG_DBG("Adv[%u] not created yet", idx);
				continue;
			}

			int err = bt_le_ext_adv_get_info(ctx->adv_set[idx], &info);
			if (err) {
				LOG_ERR("Failed to get adv[%u] info (err %d)", idx, err);
				AT_CMD_ERRNO_TO_PARAM(err, param);
				return;
			}

			LOG_DBG("Adv[%u] TX power: %d dBm", idx, info.tx_power);
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, rsp_idx, rsp_total, 2, idx,
					  info.tx_power);
			rsp_idx++;
			reported = true;
		}

		ARG_UNUSED(reported);
#else
		LOG_WRN("TX power query requires CONFIG_BT_EXT_ADV"
			" (legacy API does not expose TX power)");
		param->err = AT_CMD_ERR_NOT_SUPPORT;
		return;
#endif
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
