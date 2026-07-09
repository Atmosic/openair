/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <inttypes.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/ring_buffer.h>
#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_set_common.h"

#define CMD_NAME      "SYSUARTRAW"
#define CMD_PARM_FMT  "B(0~" STRINGIFY(CONN_IDX_MAX) "),W,B(0~1),W"
#define CMD_PARM_DESC "<conn_idx>,<att_idx>,<direction>,<length>"
#define CMD_PARM_NUM  4
#define RSP_PARM_FMT  "B,W,B,W"
#define RSP_PARM_NUM  4

LOG_MODULE_REGISTER(sysuartraw, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Active transfer state */
static bool g_active;
static uint8_t g_conn_idx;
static uint16_t g_att_handle;
static uint8_t g_direction;
static uint16_t g_length;
static uint16_t g_count;

/* UART device used for BLE→UART output */
static const struct device *g_uart_dev;

/* Ring buffer for ISR → work-queue data path (direction=0: UART→BLE) */
RING_BUF_DECLARE(raw_ring, CONFIG_AT_CMD_SYSUARTRAW_BUF_SIZE);

/* Work items for TX transmission and graceful transfer exit */
static struct k_work raw_tx_work;
static struct k_work raw_exit_work;

static uint8_t find_attr_cb(const struct bt_gatt_attr *attr, uint16_t handle, void *user_data)
{
	ARG_UNUSED(handle);
	*(const struct bt_gatt_attr **)user_data = attr;
	return BT_GATT_ITER_STOP;
}

static const struct bt_gatt_attr *lookup_attr_by_handle(uint16_t handle)
{
	const struct bt_gatt_attr *attr = NULL;

	bt_gatt_foreach_attr(handle, handle, find_attr_cb, &attr);
	return attr;
}

/* ============================================================
 * Exit work handler: called (deferred) when the bounded transfer is complete.
 * Resets transfer state and returns the system to AT command mode.
 * ============================================================ */

static void raw_exit_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	g_active = false;
	ring_buf_reset(&raw_ring);
	LOG_INF("transfer complete: %" PRIu16 " bytes, returning to AT mode", g_length);
}

/* ============================================================
 * TX work handler: drains the ring buffer and sends data to the
 * connected BLE peer via GATT notification (direction=0: UART→BLE).
 *
 * A single BLE notification payload is limited to ATT_MTU - 3 bytes.
 * This handler drains at most that many bytes per invocation and
 * resubmits itself when more data remains and the transfer is not done.
 * ============================================================ */

/* ATT notification overhead: 1 byte opcode + 2 bytes handle */
#define ATT_NOTIFY_OVERHEAD 3

static void raw_tx_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	struct bt_conn *conn = at_cmd_conn_get(g_conn_idx);

	if (!conn) {
		uint32_t pending = ring_buf_size_get(&raw_ring);

		if (pending) {
			LOG_WRN("conn_idx %" PRIu8 " not active — dropping %" PRIu32 " bytes",
				g_conn_idx, pending);
			ring_buf_reset(&raw_ring);
		}
		return;
	}

	const struct bt_gatt_attr *attr = lookup_attr_by_handle(g_att_handle);

	if (!attr) {
		LOG_WRN("att_handle %" PRIu16 " not found — dropping data", g_att_handle);
		ring_buf_reset(&raw_ring);
		return;
	}

	/* Clamp drain size to what fits in one notification (ATT_MTU - 3). */
	uint16_t mtu = bt_gatt_get_uatt_mtu(conn);
	uint16_t max_send = (mtu > ATT_NOTIFY_OVERHEAD) ? (mtu - ATT_NOTIFY_OVERHEAD) : 1U;

	/* Also cap at the remaining bytes to avoid over-sending. */
	uint16_t remaining = g_length - g_count;

	if (remaining < max_send) {
		max_send = remaining;
	}

	uint8_t buf[CONFIG_AT_CMD_SYSUARTRAW_BUF_SIZE];
	uint32_t len = ring_buf_get(&raw_ring, buf, max_send);

	if (!len) {
		return;
	}

	int ret = bt_gatt_notify(conn, attr, buf, (uint16_t)len);

	if (ret) {
		LOG_WRN("BLE notify failed: %d", ret);
		return;
	}

	g_count += (uint16_t)len;

	if (g_count >= g_length) {
		k_work_submit(&raw_exit_work);
		return;
	}

	/* If more data remains, resubmit so the next chunk is sent. */
	if (ring_buf_size_get(&raw_ring)) {
		k_work_submit(&raw_tx_work);
	}
}

/* ============================================================
 * Public API
 * ============================================================ */

bool at_cmd_sysuartraw_is_active(void)
{
	return g_active && (g_direction == 0);
}

void at_cmd_sysuartraw_rx_byte(uint8_t byte)
{
	ring_buf_put(&raw_ring, &byte, 1);
	k_work_submit(&raw_tx_work);
}

/*
 * BLE → UART (direction=1): call this from the application's GATT write handler
 * when the peer writes data to the characteristic identified by g_att_handle.
 * Outputs received bytes to UART and submits raw_exit_work once g_length bytes
 * have been received.
 */
void at_cmd_sysuartraw_rx_ble_data(const uint8_t *data, uint16_t len)
{
	if (!g_uart_dev || !g_active || (g_direction != 1)) {
		return;
	}

	uint16_t remaining = g_length - g_count;
	uint16_t to_write = (len < remaining) ? (uint16_t)len : remaining;

	for (uint16_t i = 0; i < to_write; i++) {
		uart_poll_out(g_uart_dev, data[i]);
	}

	g_count += to_write;

	if (g_count >= g_length) {
		k_work_submit(&raw_exit_work);
	}
}

/* ============================================================
 * AT command handler
 * ============================================================ */

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, g_conn_idx,
			    g_att_handle, g_direction, g_length);
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	uint8_t conn_idx = AT_PASR_GET_PARAM(param, u8, 0);
	uint16_t att_handle = AT_PASR_GET_PARAM(param, u16, 1);
	uint8_t direction = AT_PASR_GET_PARAM(param, u8, 2);
	uint16_t length = AT_PASR_GET_PARAM(param, u16, 3);

	struct bt_conn *conn = at_cmd_conn_get(conn_idx);

	if (!conn) {
		LOG_ERR("invalid conn_idx %" PRIu8, conn_idx);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}

	if (!lookup_attr_by_handle(att_handle)) {
		LOG_ERR("att_handle %" PRIu16 " not found", att_handle);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}

	g_conn_idx = conn_idx;
	g_att_handle = att_handle;
	g_direction = direction;
	g_length = length;
	g_count = 0;
	g_active = true;
	LOG_INF("raw transfer: conn=%" PRIu8 " att=%" PRIu16 " dir=%" PRIu8 " len=%" PRIu16,
		conn_idx, att_handle, direction, length);
}

static int sysuartraw_init(void)
{
	g_uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	if (!device_is_ready(g_uart_dev)) {
		LOG_WRN("console UART not ready");
		g_uart_dev = NULL;
	}
	k_work_init(&raw_tx_work, raw_tx_handler);
	k_work_init(&raw_exit_work, raw_exit_handler);
	return 0;
}

SYS_INIT(sysuartraw_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
