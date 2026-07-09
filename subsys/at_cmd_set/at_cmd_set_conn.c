/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "at_cmd_set.h"
#include "at_cmd_set_common.h"
#include "at_cmd_gatt.h"
#ifdef CONFIG_AT_CMD_GATT_CLIENT
#include "at_cmd_gatt_client.h"
#endif
#include "at_cmd_event.h"
#include <string.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(at_cmd_set, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Find the slot index of a connection in ctx->conns[]; returns UINT8_MAX if not found. */
static uint8_t conn_find_idx(const at_cmd_ctx_t *ctx, const struct bt_conn *conn)
{
	for (uint8_t i = 0; i < ctx->conn_count; i++) {
		if (ctx->conns[i] == conn) {
			return i;
		}
	}
	return UINT8_MAX;
}

static void at_cmd_set_connected(struct bt_conn *conn, uint8_t err)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (!ctx) {
		LOG_ERR("AT command context not initialized");
		return;
	}

	if (err) {
		LOG_WRN("Connection failed (err %u)", err);
		return;
	}

	/* Check if connection already registered (pre-registered by BLEGAPCREATECONN in
	 * CONNECTING state).  Emit the CONN event now — the slot index is already known
	 * so skip re-insertion.
	 */
	for (uint8_t i = 0; i < ctx->conn_count; i++) {
		if (ctx->conns[i] == conn) {
			LOG_INF("Connection at index %u established", i);
#ifdef CONFIG_AT_EVT_BLEGAPCONN
			if (ctx->ch != AT_CMD_INVALID_CH) {
				struct bt_conn_info info;

				if (!bt_conn_get_info(conn, &info)) {
					at_cmd_evt_conn(ctx->ch, i, &info);
				}
			}
#endif /* CONFIG_AT_EVT_BLEGAPCONN */
			return;
		}
	}

	/* Find empty slot */
	if (ctx->conn_count >= CONFIG_BT_MAX_CONN) {
		LOG_ERR("No space for new connection (max %u)", CONFIG_BT_MAX_CONN);
		return;
	}

	uint8_t idx = ctx->conn_count;

	ctx->conns[idx] = bt_conn_ref(conn);
	ctx->conn_count++;
	LOG_INF("Connection registered at index %u", idx);

#ifdef CONFIG_AT_EVT_BLEGAPCONN
	if (ctx->ch != AT_CMD_INVALID_CH) {
		struct bt_conn_info info;

		if (!bt_conn_get_info(conn, &info)) {
			at_cmd_evt_conn(ctx->ch, idx, &info);
		}
	}
#endif /* CONFIG_AT_EVT_BLEGAPCONN */
}

static void at_cmd_set_disconnected(struct bt_conn *conn, uint8_t reason)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (!ctx) {
		LOG_ERR("AT command context not initialized");
		return;
	}

	for (uint8_t i = 0; i < ctx->conn_count; i++) {
		if (ctx->conns[i] != conn) {
			continue;
		}

#ifdef CONFIG_AT_EVT_BLEGAPDISCONN
		if (ctx->ch != AT_CMD_INVALID_CH) {
			at_cmd_evt_disconn(ctx->ch, i, reason);
		}
#endif /* CONFIG_AT_EVT_BLEGAPDISCONN */

		bt_conn_unref(ctx->conns[i]);

		uint8_t tail = ctx->conn_count - i - 1;

#ifdef CONFIG_AT_CMD_GATT_CLIENT
		at_cmd_gatt_client_on_conn_removed(i, tail);
#endif

		memmove(&ctx->conns[i], &ctx->conns[i + 1], tail * sizeof(ctx->conns[0]));

		ctx->conns[--ctx->conn_count] = NULL;

		LOG_INF("Connection unregistered from index %u, reason 0x%02x", i, reason);

#ifdef CONFIG_AT_CMD_BLEGATTDFTSERVER
		if (ctx->conn_count == 0) {
			at_cmd_gatt_dft_on_all_disconnected();
		}
#endif
#ifdef CONFIG_AT_CMD_GATT_CLIENT
		at_cmd_gatt_client_on_disconnected(i);
#endif
		return;
	}
}

#ifdef CONFIG_AT_EVT_BLEGAPLINKINFO
static void at_cmd_set_remote_info(struct bt_conn *conn, struct bt_conn_remote_info *remote_info)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (!ctx || (ctx->ch == AT_CMD_INVALID_CH)) {
		return;
	}

	uint8_t idx = conn_find_idx(ctx, conn);

	if (idx == UINT8_MAX) {
		return;
	}

	at_cmd_evt_linkinfo(ctx->ch, idx, remote_info);
}
#endif /* CONFIG_AT_EVT_BLEGAPLINKINFO */

#ifdef CONFIG_AT_EVT_BLEGAPPAR
static void at_cmd_set_le_param_updated(struct bt_conn *conn, uint16_t interval, uint16_t latency,
					uint16_t timeout)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (!ctx || (ctx->ch == AT_CMD_INVALID_CH)) {
		return;
	}

	uint8_t idx = conn_find_idx(ctx, conn);

	if (idx == UINT8_MAX) {
		return;
	}

	at_cmd_evt_par(ctx->ch, idx, interval, latency, timeout);
}
#endif /* CONFIG_AT_EVT_BLEGAPPAR */

BT_CONN_CB_DEFINE(at_cmd_set_conn_callbacks) = {
	.connected = at_cmd_set_connected,
	.disconnected = at_cmd_set_disconnected,
#ifdef CONFIG_AT_EVT_BLEGAPLINKINFO
	.remote_info_available = at_cmd_set_remote_info,
#endif
#ifdef CONFIG_AT_EVT_BLEGAPPAR
	.le_param_updated = at_cmd_set_le_param_updated,
#endif
};

struct bt_conn *at_cmd_conn_get(uint8_t idx)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (!ctx || (idx >= ctx->conn_count)) {
		return NULL;
	}

	return ctx->conns[idx];
}

uint8_t at_cmd_conn_slot(const struct bt_conn *conn)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	return ctx ? conn_find_idx(ctx, conn) : UINT8_MAX;
}

#ifdef CONFIG_ZTEST
/*
 * Test hooks: expose the static BT_CONN_CB handlers so ZTests can invoke them
 * directly with controlled inputs.  Real BT stack callbacks remain the only
 * production caller; these wrappers exist purely to drive coverage in unit
 * tests where no real peer is available.
 */
void at_cmd_set_conn_test_connected(struct bt_conn *conn, uint8_t err)
{
	at_cmd_set_connected(conn, err);
}

void at_cmd_set_conn_test_disconnected(struct bt_conn *conn, uint8_t reason)
{
	at_cmd_set_disconnected(conn, reason);
}

#ifdef CONFIG_AT_EVT_BLEGAPLINKINFO
void at_cmd_set_conn_test_remote_info(struct bt_conn *conn, struct bt_conn_remote_info *remote_info)
{
	at_cmd_set_remote_info(conn, remote_info);
}
#endif /* CONFIG_AT_EVT_BLEGAPLINKINFO */

#ifdef CONFIG_AT_EVT_BLEGAPPAR
void at_cmd_set_conn_test_le_param_updated(struct bt_conn *conn, uint16_t interval,
					   uint16_t latency, uint16_t timeout)
{
	at_cmd_set_le_param_updated(conn, interval, latency, timeout);
}
#endif /* CONFIG_AT_EVT_BLEGAPPAR */

uint8_t at_cmd_set_conn_test_slot(const struct bt_conn *conn)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	return ctx ? conn_find_idx(ctx, conn) : UINT8_MAX;
}
#endif /* CONFIG_ZTEST */
