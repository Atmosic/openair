/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "SYSUARTFC"
#define CMD_PARM_FMT  "B(0~1)"
#define CMD_PARM_DESC "<0=off|1=RTS/CTS>"
#define CMD_PARM_NUM  1
#define RSP_PARM_FMT  "B"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(sysuartfc, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Stored flow control state (0 = off, 1 = RTS/CTS on) */
static uint8_t g_flow_ctrl;

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, g_flow_ctrl);
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t action = AT_PASR_GET_PARAM(param, u8, 0);

	const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));

	if (!device_is_ready(uart_dev)) {
		LOG_ERR("UART device not ready");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_SYS_UART_NOT_READY, param);
		return;
	}

	struct uart_config cfg;
	int ret = uart_config_get(uart_dev, &cfg);

	if (ret) {
		LOG_ERR("uart_config_get failed: %d", ret);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_SYS_UART_CONFIG, param);
		return;
	}

	cfg.flow_ctrl = action ? UART_CFG_FLOW_CTRL_RTS_CTS : UART_CFG_FLOW_CTRL_NONE;
	ret = uart_configure(uart_dev, &cfg);
	if (ret) {
		LOG_ERR("uart_configure flow_ctrl=%" PRIu8 " failed: %d", action, ret);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_SYS_UART_CONFIG, param);
		return;
	}

	g_flow_ctrl = action;
	LOG_INF("Flow control %s", action ? "ON" : "OFF");
}

static int sysuartfc_init(void)
{
	const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	struct uart_config cfg;

	if (device_is_ready(uart_dev) && !uart_config_get(uart_dev, &cfg)) {
		g_flow_ctrl = (cfg.flow_ctrl != UART_CFG_FLOW_CTRL_NONE) ? 1U : 0U;
	}

	return 0;
}

SYS_INIT(sysuartfc_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
