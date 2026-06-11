/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/bluetooth/att.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include "at_cmd.h"
#include "at_cmd_event.h"
#include "at_cmd_gatt_client.h"
#include "at_cmd_set_common.h"

LOG_MODULE_REGISTER(at_cmd_gatt_client, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Discovery unlimited results indicator */
#define DISC_UNLIMITED 0

/* Per-connection context array */
static at_cmd_gatt_client_conn_t s_conns[CONFIG_BT_MAX_CONN];

/* Subscribe slot pool */
static at_cmd_gatt_sub_slot_t s_sub_pool[CONFIG_BT_MAX_CONN * CONFIG_AT_CMD_GATT_CLIENT_SUBS_MAX];

/**
 * @brief Convert a Zephyr UUID (LE byte-order) to AT MSB-first bytes.
 *
 * @param uuid  Zephyr UUID pointer
 * @param out   Output buffer (must be >= BT_UUID_SIZE_128 bytes)
 * @return Number of bytes written (2 or 16), or 0 on unsupported type.
 */
static uint8_t uuid_to_at_bytes(const struct bt_uuid *uuid, uint8_t *out)
{
	if (uuid->type == BT_UUID_TYPE_16) {
		sys_put_be16(BT_UUID_16(uuid)->val, out);
		return 2;
	}
	if (uuid->type == BT_UUID_TYPE_128) {
		sys_memcpy_swap(out, BT_UUID_128(uuid)->val, BT_UUID_SIZE_128);
		return BT_UUID_SIZE_128;
	}
	return 0;
}

static uint8_t gattc_disc_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     struct bt_gatt_discover_params *params)
{
	at_cmd_gatt_client_conn_t *ctx = CONTAINER_OF(params, at_cmd_gatt_client_conn_t, disc);
	uint8_t conidx = (uint8_t)(ctx - s_conns);
	uint8_t ch = at_cmd_ctx_get()->ch;

	if (!attr) {
		/* Discovery complete - no callback needed, command will return OK */
		ctx->disc_busy = false;
		return BT_GATT_ITER_STOP;
	}

	uint8_t uuid_buf[BT_UUID_SIZE_128];

	if (ctx->disc_cmd == AT_GATTC_DISC_SVC || ctx->disc_cmd == AT_GATTC_DISC_SVCS) {
		const struct bt_gatt_service_val *svc = attr->user_data;
		uint8_t uuid_len = uuid_to_at_bytes(svc->uuid, uuid_buf);

		/* Call the appropriate callback based on the command type */
		if (ctx->disc_cmd == AT_GATTC_DISC_SVCS) {
#ifdef CONFIG_AT_CMD_BLEGATTDISCSVCS
			blegattdiscsvcs_result_cb(ch, conidx, attr->handle, svc->end_handle,
						  uuid_buf, uuid_len);
#endif
		} else { /* AT_GATTC_DISC_SVC */
#ifdef CONFIG_AT_CMD_BLEGATTDISCSVC
			blegattdiscsvc_result_cb(ch, conidx, attr->handle, svc->end_handle,
						 uuid_buf, uuid_len);
#endif
		}

	} else if (ctx->disc_cmd == AT_GATTC_DISC_CHAR || ctx->disc_cmd == AT_GATTC_DISC_CHARS) {
		const struct bt_gatt_chrc *chrc = attr->user_data;
		uint8_t uuid_len = uuid_to_at_bytes(chrc->uuid, uuid_buf);

		/* Call the appropriate callback based on the command type */
		if (ctx->disc_cmd == AT_GATTC_DISC_CHARS) {
#ifdef CONFIG_AT_CMD_BLEGATTDISCCHARS
			blegattdiscchars_result_cb(ch, conidx, attr->handle, chrc->value_handle,
						   chrc->properties, uuid_buf, uuid_len);
#endif
		} else { /* AT_GATTC_DISC_CHAR */
#ifdef CONFIG_AT_CMD_BLEGATTDISCCHAR
			blegattdiscchar_result_cb(ch, conidx, attr->handle, chrc->value_handle,
						  chrc->properties, uuid_buf, uuid_len);
#endif
		}

	} else if (ctx->disc_cmd == AT_GATTC_DISC_DESCS) {
		uint8_t uuid_len = uuid_to_at_bytes(attr->uuid, uuid_buf);

#ifdef CONFIG_AT_CMD_BLEGATTDISCDESCS
		blegattdiscdescs_result_cb(ch, conidx, attr->handle, uuid_buf, uuid_len);
#endif
	}

	/* Check max_number limit (DISC_UNLIMITED = unlimited) */
	if (ctx->disc_max > DISC_UNLIMITED) {
		ctx->disc_count++;
		if (ctx->disc_count >= ctx->disc_max) {
			/* Max results reached - stop discovery, command will return OK */
			ctx->disc_busy = false;
			return BT_GATT_ITER_STOP;
		}
	}

	return BT_GATT_ITER_CONTINUE;
}

static uint8_t gattc_read_cb(struct bt_conn *conn, uint8_t att_err,
			     struct bt_gatt_read_params *params, const void *data, uint16_t length)
{
	ARG_UNUSED(conn);

	at_cmd_gatt_client_conn_t *ctx = CONTAINER_OF(params, at_cmd_gatt_client_conn_t, rd);
	uint8_t conidx = (uint8_t)(ctx - s_conns);
	at_cmd_ctx_t *at_ctx = at_cmd_ctx_get();
	uint8_t ch = at_ctx->ch;

	if (att_err) {
		LOG_ERR("Read error: att_err=0x%02x", att_err);
		/* Emit zero-length read result so the host knows the operation
		 * completed (with error); avoids indefinite host-side timeout. */

#ifdef CONFIG_AT_CMD_BLEGATTRD
		blegattrd_result_cb(ch, conidx, params->single.handle, NULL, 0);
#endif
		ctx->rd_busy = false;
		return BT_GATT_ITER_STOP;
	}

	if (!data) {
		/* Read complete (no more data, success) */
		ctx->rd_busy = false;
		return BT_GATT_ITER_STOP;
	}

#ifdef CONFIG_AT_CMD_BLEGATTRD
	uint16_t capped = MIN(length, (uint16_t)CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN);
	blegattrd_result_cb(ch, conidx, params->single.handle, data, capped);
#endif

	ctx->rd_busy = false;
	return BT_GATT_ITER_STOP;
}

static void gattc_write_cb(struct bt_conn *conn, uint8_t att_err,
			   struct bt_gatt_write_params *params)
{
	ARG_UNUSED(conn);

	at_cmd_gatt_client_conn_t *ctx = CONTAINER_OF(params, at_cmd_gatt_client_conn_t, wr);
	uint8_t conidx = (uint8_t)(ctx - s_conns);
	at_cmd_ctx_t *at_ctx = at_cmd_ctx_get();
	uint8_t ch = at_ctx->ch;

	ctx->wr_busy = false;

#ifdef CONFIG_AT_CMD_BLEGATTWR
	blegattwr_result_cb(ch, conidx, params->handle, att_err);
#endif
}

static uint8_t gattc_notify_cb(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
			       const void *data, uint16_t length)
{
	ARG_UNUSED(conn);

	if (!data) {
		/* Subscription cancelled (e.g., peer disconnected) */
		at_cmd_gatt_sub_slot_t *slot = CONTAINER_OF(params, at_cmd_gatt_sub_slot_t, params);
		slot->in_use = false;
		return BT_GATT_ITER_STOP;
	}

	at_cmd_gatt_sub_slot_t *slot = CONTAINER_OF(params, at_cmd_gatt_sub_slot_t, params);
	uint8_t conidx = slot->conidx;
	uint8_t ch = at_cmd_ctx_get()->ch;

#ifdef CONFIG_AT_EVT_BLEGATTNOTI
	if (params->value == BT_GATT_CCC_NOTIFY) {
		at_cmd_evt_blegattnoti(ch, conidx, params->value_handle, data, length);
	}
#endif

#ifdef CONFIG_AT_EVT_BLEGATTINDI
	if (params->value == BT_GATT_CCC_INDICATE) {
		at_cmd_evt_blegattindi(ch, conidx, params->value_handle, data, length);
	}
#endif

	return BT_GATT_ITER_CONTINUE;
}

at_cmd_gatt_client_conn_t *at_cmd_gatt_client_conn_get(uint8_t conidx)
{
	if (conidx >= CONFIG_BT_MAX_CONN) {
		return NULL;
	}
	return &s_conns[conidx];
}

at_cmd_gatt_sub_slot_t *at_cmd_gatt_client_sub_alloc(uint8_t conidx)
{
	for (int i = 0; i < ARRAY_SIZE(s_sub_pool); i++) {
		if (!s_sub_pool[i].in_use) {
			memset(&s_sub_pool[i], 0, sizeof(s_sub_pool[i]));
			s_sub_pool[i].in_use = true;
			s_sub_pool[i].conidx = conidx;
			s_sub_pool[i].params.notify = gattc_notify_cb;
			return &s_sub_pool[i];
		}
	}
	return NULL;
}

at_cmd_gatt_sub_slot_t *at_cmd_gatt_client_sub_find(uint8_t conidx, uint16_t value_handle)
{
	for (int i = 0; i < ARRAY_SIZE(s_sub_pool); i++) {
		if (s_sub_pool[i].in_use && (s_sub_pool[i].conidx == conidx) &&
		    (s_sub_pool[i].params.value_handle == value_handle)) {
			return &s_sub_pool[i];
		}
	}
	return NULL;
}

void at_cmd_gatt_client_sub_free(at_cmd_gatt_sub_slot_t *slot)
{
	if (slot) {
		slot->in_use = false;
	}
}

void at_cmd_gatt_client_on_disconnected(uint8_t conidx)
{
	if (conidx >= CONFIG_BT_MAX_CONN) {
		return;
	}

	at_cmd_gatt_client_conn_t *ctx = &s_conns[conidx];

	ctx->disc_busy = false;
	ctx->rd_busy = false;
	ctx->wr_busy = false;

	for (int i = 0; i < ARRAY_SIZE(s_sub_pool); i++) {
		if (s_sub_pool[i].in_use && (s_sub_pool[i].conidx == conidx)) {
			s_sub_pool[i].in_use = false;
		}
	}
}

void at_cmd_gatt_client_on_conn_removed(uint8_t removed_idx, uint8_t tail)
{
	if (removed_idx >= CONFIG_BT_MAX_CONN) {
		return;
	}

	/* 1. Free resources for the disconnected connection */
	at_cmd_gatt_client_on_disconnected(removed_idx);

	/* 2. Shift s_conns[] down to match ctx->conns[] after memmove */
	memmove(&s_conns[removed_idx], &s_conns[removed_idx + 1], tail * sizeof(s_conns[0]));
	memset(&s_conns[removed_idx + tail], 0, sizeof(s_conns[0]));

	/* 3. Patch sub_pool conidx for connections that shifted down */
	for (int i = 0; i < ARRAY_SIZE(s_sub_pool); i++) {
		if (s_sub_pool[i].in_use && (s_sub_pool[i].conidx > removed_idx)) {
			s_sub_pool[i].conidx--;
		}
	}
}

int at_cmd_gatt_client_uuid_set(at_cmd_gatt_client_conn_t *ctx, const uint8_t *uuid_bytes,
				uint16_t uuid_len)
{
	if (uuid_len == 2) {
		ctx->disc_uuid.u16.uuid.type = BT_UUID_TYPE_16;
		ctx->disc_uuid.u16.val = sys_get_be16(uuid_bytes);
	} else if (uuid_len == BT_UUID_SIZE_128) {
		ctx->disc_uuid.u128.uuid.type = BT_UUID_TYPE_128;
		sys_memcpy_swap(ctx->disc_uuid.u128.val, uuid_bytes, BT_UUID_SIZE_128);
	} else {
		return -EINVAL;
	}
	ctx->disc.uuid = &ctx->disc_uuid.base;
	return 0;
}

/* ── Test-mode BT mock ──────────────────────────────────────────────────────
 * When CONFIG_ZTEST is active the discover/read/write wrappers consult these
 * variables instead of calling the real BT GATT APIs.  This allows unit tests
 * to exercise every code path in the AT command handlers without requiring a
 * live BLE connection.
 */
#ifdef CONFIG_ZTEST
static bool s_test_bt_mock;
static int s_test_discover_ret = -ENOTCONN;
static int s_test_read_ret = -ENOTCONN;
static int s_test_write_ret = -ENOTCONN;
static int s_test_wrwo_ret = -ENOTCONN;
static int s_test_subscribe_ret = -ENOTCONN;
static int s_test_unsubscribe_ret = -ENOTCONN;
#endif /* CONFIG_ZTEST */

int at_cmd_gatt_client_discover(struct bt_conn *conn, at_cmd_gatt_client_conn_t *ctx)
{
	ctx->disc_count = 0;
	ctx->disc.func = gattc_disc_cb;
#ifdef CONFIG_ZTEST
	int err = s_test_bt_mock ? s_test_discover_ret : bt_gatt_discover(conn, &ctx->disc);
#else
	int err = bt_gatt_discover(conn, &ctx->disc);
#endif
	if (!err) {
		ctx->disc_busy = true;
	}
	return err;
}

int at_cmd_gatt_client_read(struct bt_conn *conn, at_cmd_gatt_client_conn_t *ctx)
{
	ctx->rd.func = gattc_read_cb;
#ifdef CONFIG_ZTEST
	int err = s_test_bt_mock ? s_test_read_ret : bt_gatt_read(conn, &ctx->rd);
#else
	int err = bt_gatt_read(conn, &ctx->rd);
#endif
	if (!err) {
		ctx->rd_busy = true;
	}
	return err;
}

int at_cmd_gatt_client_write(struct bt_conn *conn, at_cmd_gatt_client_conn_t *ctx)
{
	ctx->wr.func = gattc_write_cb;
#ifdef CONFIG_ZTEST
	int err = s_test_bt_mock ? s_test_write_ret : bt_gatt_write(conn, &ctx->wr);
#else
	int err = bt_gatt_write(conn, &ctx->wr);
#endif
	if (!err) {
		ctx->wr_busy = true;
	}
	return err;
}

int at_cmd_gatt_client_write_without_response(struct bt_conn *conn, uint16_t handle,
					      const void *data, uint16_t length)
{
#ifdef CONFIG_ZTEST
	if (s_test_bt_mock) {
		return s_test_wrwo_ret;
	}
#endif
	return bt_gatt_write_without_response(conn, handle, data, length, false);
}

int at_cmd_gatt_client_subscribe(struct bt_conn *conn, at_cmd_gatt_sub_slot_t *slot)
{
#ifdef CONFIG_ZTEST
	if (s_test_bt_mock) {
		return s_test_subscribe_ret;
	}
#endif
	return bt_gatt_subscribe(conn, &slot->params);
}

int at_cmd_gatt_client_unsubscribe(struct bt_conn *conn, at_cmd_gatt_sub_slot_t *slot)
{
#ifdef CONFIG_ZTEST
	if (s_test_bt_mock) {
		return s_test_unsubscribe_ret;
	}
#endif
	return bt_gatt_unsubscribe(conn, &slot->params);
}

#ifdef CONFIG_ZTEST
void at_cmd_gatt_client_test_enable_bt_mock(bool enable)
{
	s_test_bt_mock = enable;
}

void at_cmd_gatt_client_test_set_bt_ret(int discover_ret, int read_ret, int write_ret)
{
	s_test_discover_ret = discover_ret;
	s_test_read_ret = read_ret;
	s_test_write_ret = write_ret;
}

void at_cmd_gatt_client_test_set_wrwo_ret(int ret)
{
	s_test_wrwo_ret = ret;
}

void at_cmd_gatt_client_test_set_sub_ret(int subscribe_ret, int unsubscribe_ret)
{
	s_test_subscribe_ret = subscribe_ret;
	s_test_unsubscribe_ret = unsubscribe_ret;
}

uint8_t at_cmd_gatt_client_test_disc_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					struct bt_gatt_discover_params *params)
{
	return gattc_disc_cb(conn, attr, params);
}

uint8_t at_cmd_gatt_client_test_read_cb(struct bt_conn *conn, uint8_t att_err,
					struct bt_gatt_read_params *params, const void *data,
					uint16_t length)
{
	return gattc_read_cb(conn, att_err, params, data, length);
}

void at_cmd_gatt_client_test_write_cb(struct bt_conn *conn, uint8_t att_err,
				      struct bt_gatt_write_params *params)
{
	gattc_write_cb(conn, att_err, params);
}

uint8_t at_cmd_gatt_client_test_notify_cb(struct bt_conn *conn,
					  struct bt_gatt_subscribe_params *params, const void *data,
					  uint16_t length)
{
	return gattc_notify_cb(conn, params, data, length);
}
#endif /* CONFIG_ZTEST */
