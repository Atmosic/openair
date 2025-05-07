/**
 *******************************************************************************
 *
 * @file fp_conn.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Connection Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <stdlib.h>
#include "fp_conn.h"
#include "fp_adv.h"
#include "fp_mode.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(fp, CONFIG_ATM_FP_LOG_LEVEL);

static struct bt_conn *active_conn[CONFIG_BT_MAX_CONN];

void fp_conn_init(void)
{
	uint8_t bt_id_base = fp_storage_bt_id_base_get();
	if (bt_id_base) {
		return;
	}
	int err;
	bt_addr_le_t addr[CONFIG_BT_ID_MAX];
	memset(addr, 0, sizeof(addr));
	size_t count = CONFIG_BT_ID_MAX;
	bt_id_get(addr, &count);
	LOG_INF("bt id count %zd", count);
	__ASSERT((CONFIG_FP_BT_ID_NUM + count) < CONFIG_BT_ID_MAX,
		 "CONFIG_BT_ID_MAX should be greater than CONFIG_FP_BT_ID_NUM");
	bt_id_base = count;
	bt_addr_le_t static_addr;
#ifdef CONFIG_FAST_PAIR_USER_PAIR_BT_ADDR
#define FP_DEFAULT_BDADDR CONFIG_FAST_PAIR_PAIR_BT_ADDR
	err = bt_addr_le_from_str(FP_DEFAULT_BDADDR, "random", &static_addr);
	if (err) {
		LOG_ERR("Invalid Bluetooth address format");
		return;
	}
#else
	memcpy(&static_addr, &addr[BT_ID_DEFAULT], sizeof(bt_addr_le_t));
	// increment the first byte of the address to avoid collision
	static_addr.a.val[0] += count;
	static_addr.type = BT_ADDR_LE_RANDOM;
#endif
	// FP BT base ID with expected BT address
	BT_ADDR_SET_STATIC(&static_addr.a);
	LOG_HEXDUMP_INF(static_addr.a.val, sizeof(static_addr.a.val),
			"FP Static Random BT Address:");
	err = bt_id_create(&static_addr, NULL);
	if (err < 0) {
		LOG_ERR("Failed to create bt id [%u] (err: %d)", bt_id_base, err);
		return;
	}
	LOG_INF("FP BT ID [%u] created", bt_id_base);
	fp_storage_bt_id_base_save(bt_id_base);
	for (size_t i = count + 1; i < (CONFIG_FP_BT_ID_NUM + count); i++) {
		err = bt_id_create(NULL, NULL);
		if (err < 0) {
			LOG_ERR("Failed to create bt id (err: %d)", err);
			return;
		}
		LOG_INF("FP BT ID [%zd] created", i);
	}
}

void fp_conn_disconnect_all(void)
{
	for (uint8_t i = 0; i < CONFIG_BT_MAX_CONN; i++) {
		if (active_conn[i]) {
			bt_conn_disconnect(active_conn[i], BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		}
	}
}

static void fp_conn_connected(struct bt_conn *conn, uint8_t err)
{
	if (!fp_conn_validate(conn)) {
		// Not a fp connection
		return;
	}
	uint8_t bt_idx = bt_conn_index(conn);
	active_conn[bt_idx] = conn;
	LOG_DBG("Connected from bt_idx:%#x", bt_idx);
}

static void fp_conn_disconnected(struct bt_conn *conn, uint8_t reason)
{
	if (!fp_conn_validate(conn)) {
		// Not a fp connection
		return;
	}
	uint8_t bt_idx = bt_conn_index(conn);
	active_conn[bt_idx] = NULL;
	LOG_DBG("Discon res(0x%02x) from bt_idx:%#x", reason, bt_idx);
}

BT_CONN_CB_DEFINE(fp_conn_callbacks) = {
	.connected = fp_conn_connected,
	.disconnected = fp_conn_disconnected,
};

bool fp_conn_validate(struct bt_conn *conn)
{
	struct bt_conn_info info;
	uint8_t bt_id_base = fp_storage_bt_id_base_get();
	bt_conn_get_info(conn, &info);
	if (info.id < bt_id_base || info.id >= (bt_id_base + CONFIG_FP_BT_ID_NUM)) {
		return false;
	}
	return true;
}
