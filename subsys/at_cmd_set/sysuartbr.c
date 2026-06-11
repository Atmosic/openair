/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "SYSUARTBR"
#define CMD_PARM_FMT  "D,B(1~255)"
#define CMD_PARM_DESC "<baud_rate>,<defer_apply_cs>"
#define CMD_PARM_NUM  2
#define RSP_PARM_FMT  "D"
#define RSP_PARM_NUM  1

LOG_MODULE_REGISTER(sysuartbr, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Allowed baud rates per specification */
static const uint32_t valid_baud_rates[] = {
	19200, 38400, 57600, 115200, 230400, 460800,
};

/* Stored baud rate (initialised from hardware in sysuartbr_init) */
static uint32_t g_baud_rate;

static struct k_work_delayable g_apply_work;

static void apply_baud_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	struct uart_config cfg;

	int ret = uart_config_get(uart_dev, &cfg);

	if (ret) {
		LOG_ERR("uart_config_get failed: %d", ret);
		return;
	}

	cfg.baudrate = g_baud_rate;
	ret = uart_configure(uart_dev, &cfg);
	if (ret) {
		LOG_ERR("uart_configure to %" PRIu32 " failed: %d", g_baud_rate, ret);
	} else {
		LOG_INF("Baud rate applied: %" PRIu32, g_baud_rate);
	}
}

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, g_baud_rate);
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint32_t baud_rate = AT_PASR_GET_PARAM(param, u32, 0);
	uint8_t defer_apply = AT_PASR_GET_PARAM(param, u8, 1);

	/* Validate baud rate against the allowed set */
	bool valid = false;

	for (size_t i = 0; i < ARRAY_SIZE(valid_baud_rates); i++) {
		if (baud_rate == valid_baud_rates[i]) {
			valid = true;
			break;
		}
	}
	if (!valid) {
		LOG_ERR("Invalid baud rate: %" PRIu32, baud_rate);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}

	const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));

	if (!device_is_ready(uart_dev)) {
		LOG_ERR("UART device not ready");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_SYS_UART_NOT_READY, param);
		return;
	}

	g_baud_rate = baud_rate;

	/* Schedule the apply after defer_apply centiseconds (1 cs = 10 ms).
	 * OK is returned at the current baud rate first; the host has the full
	 * defer window to switch its serial port before the device follows.
	 */
	k_work_reschedule(&g_apply_work, K_MSEC((uint32_t)defer_apply * 10U));

	LOG_INF("Baud rate %" PRIu32 " scheduled in %" PRIu8 " cs", baud_rate, defer_apply);
}

static int sysuartbr_init(void)
{
	k_work_init_delayable(&g_apply_work, apply_baud_work_handler);

	const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	struct uart_config cfg;

	if (device_is_ready(uart_dev) && !uart_config_get(uart_dev, &cfg)) {
		g_baud_rate = cfg.baudrate;
	} else {
		g_baud_rate = 115200U;
	}

	return 0;
}

SYS_INIT(sysuartbr_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
