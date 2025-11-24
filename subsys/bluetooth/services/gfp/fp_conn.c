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
	int err;
	bt_addr_le_t addr[CONFIG_BT_ID_MAX];
	memset(addr, 0, sizeof(addr));
	size_t count = CONFIG_BT_ID_MAX;
	bt_id_get(addr, &count);
	LOG_INF("bt id count %zd", count);

	/*
	 * FMDN BT_ID Configuration:
	 *
	 * CONFIG_FAST_PAIR_USE_BT_ID_DEFAULT=y:
	 *   - Uses BT_ID_DEFAULT for Fast Pair advertising
	 *   - Supports public addresses (requires CONFIG_BT_HCI_SET_PUBLIC_ADDR=y)
	 *   - Additional BT IDs created for FMDN/DULT
	 *
	 * CONFIG_FAST_PAIR_USE_BT_ID_DEFAULT=n (default):
	 *   - Creates dedicated BT IDs starting from next available ID
	 *   - Only supports static random addresses
	 *   - Traditional Fast Pair implementation
	 *
	 * CONFIG_FAST_PAIR_FMDN_USE_BT_ID_OF_FAST_PAIR=y (default):
	 *   - FMDN shares the same BT_ID as Fast Pair (bt_id_base + 0)
	 *   - Reduces total BT_ID usage but may impact advertising flexibility
	 *
	 * CONFIG_FAST_PAIR_FMDN_USE_BT_ID_OF_FAST_PAIR=n:
	 *   - FMDN uses dedicated BT_ID (bt_id_base + 1)
	 *   - Better isolation between Fast Pair and FMDN operations
	 */
	uint8_t bt_id_base;
	if (fp_storage_bt_id_base_valid()) {
		bt_id_base = fp_storage_bt_id_base_get();
	} else {
		bt_id_base = count;
		LOG_INF("FP Save BT ID base [%u]", bt_id_base);
		fp_storage_bt_id_base_save(bt_id_base);
	}
	LOG_INF("FP BT ID base [%u]", bt_id_base);

	/* Verify we have enough BT IDs available */
	__ASSERT((bt_id_base + CONFIG_FP_BT_ID_NUM - 1) < CONFIG_BT_ID_MAX,
		 "CONFIG_BT_ID_MAX must accommodate bt_id_base + CONFIG_FP_BT_ID_NUM");
#ifdef CONFIG_FAST_PAIR_USE_BT_ID_DEFAULT
	/* Use existing BT_ID_DEFAULT for Fast Pair (supports public addresses) */
	LOG_INF("Using BT_ID_DEFAULT [%u] for Fast Pair", BT_ID_DEFAULT);
#else
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
	/* increment the first byte of the address to avoid collision */
	static_addr.a.val[0] += bt_id_base;
	static_addr.type = BT_ADDR_LE_RANDOM;
#endif
	/* FP BT base ID with expected BT address */
	BT_ADDR_SET_STATIC(&static_addr.a);
	LOG_HEXDUMP_INF(static_addr.a.val, sizeof(static_addr.a.val),
			"FP Static Random BT Address:");
	if (count <= bt_id_base) {
		/* BT_ID doesn't exist - create it */
		err = bt_id_create(&static_addr, NULL);
		if (err < 0) {
			LOG_ERR("Failed to create bt id [%u] (err: %d)", bt_id_base, err);
			return;
		}
		LOG_INF("FP BT ID [%u] created", bt_id_base);
		count++;
	} else {
		/* BT_ID exists - check if it has correct address */
		if (!bt_addr_le_eq(&addr[bt_id_base], &static_addr)) {
			/* BT_ID exists but with wrong address - reset it */
			err = bt_id_reset(bt_id_base, &static_addr, NULL);
			if (err < 0) {
				LOG_ERR("Failed to reset bt id [%u] (err: %d)", bt_id_base, err);
				return;
			}
			LOG_INF("FP BT ID [%u] reset to expected address", bt_id_base);
		} else {
			LOG_DBG("FP BT ID [%u] already exists with expected address", bt_id_base);
		}
	}
	bt_id_base += 1;
#endif // CONFIG_FAST_PAIR_USE_BT_ID_DEFAULT
	/* Create additional BT IDs for FMDN/DULT (these will be random static) */
	for (size_t i = bt_id_base; i < (bt_id_base + CONFIG_FP_BT_ID_NUM - 1); i++) {
		if (count <= i) {
			// BT_ID doesn't exist - create it
			err = bt_id_create(NULL, NULL);
			if (err < 0) {
				LOG_ERR("Failed to create bt id (err: %d)", err);
				return;
			}
			LOG_INF("FP BT ID [%zd] created", i);
			count++;
			continue;
		}
		if (addr[i].type == BT_ADDR_LE_RANDOM) {
			LOG_DBG("BT_ID %u already exists with expected random address", i);
		} else {
			// BT_ID already exists - reset it to ensure correct address
			LOG_INF("BT_ID %u not random, reset it", i);
			err = bt_id_reset(i, NULL, NULL);
			if (err < 0) {
				LOG_ERR("Failed to reset bt id [%zd] (err: %d)", i, err);
				return;
			}
			LOG_INF("FP BT ID [%zd] reset to random address", i);
		}
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

static void fp_conn_le_param_updated(struct bt_conn *conn, uint16_t interval, uint16_t latency,
				     uint16_t timeout)
{
	if (!fp_conn_validate(conn)) {
		// Not a Fast Pair connection
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_DBG("FP Conn: LE param updated: %s interval %u , latency %u, timeout %u (ms)", addr,
		interval, latency, timeout);
}

BT_CONN_CB_DEFINE(fp_conn_callbacks) = {
	.connected = fp_conn_connected,
	.disconnected = fp_conn_disconnected,
	.le_param_updated = fp_conn_le_param_updated,
};

bool fp_conn_id_validate(uint8_t id)
{
	uint8_t bt_id_base = fp_storage_bt_id_base_get();

#ifdef CONFIG_FAST_PAIR_USE_BT_ID_DEFAULT
	/* When using BT_ID_DEFAULT, accept connections on BT_ID_DEFAULT */
	if (id == BT_ID_DEFAULT) {
		return true;
	}
	/* Also accept connections on FMDN/DULT BT IDs (bt_id_base + 1 onwards) */
	if ((id >= (bt_id_base + 1)) && (id < (bt_id_base + CONFIG_FP_BT_ID_NUM))) {
		return true;
	}
#else
	/* Traditional validation: accept connections within the allocated BT ID range */
	if ((id >= bt_id_base) && (id < (bt_id_base + CONFIG_FP_BT_ID_NUM))) {
		return true;
	}
#endif

	return false;
}

bool fp_conn_validate(struct bt_conn *conn)
{
	struct bt_conn_info info;
	bt_conn_get_info(conn, &info);
	return fp_conn_id_validate(info.id);
}

static uint8_t fp_conn_get_fp_bt_id(uint8_t id)
{
#ifdef CONFIG_FAST_PAIR_USE_BT_ID_DEFAULT
	ARG_UNUSED(id);
	return BT_ID_DEFAULT;
#else
	return fp_storage_bt_id_base_get() + id;
#endif
}

uint8_t fp_conn_get_bt_id(uint8_t idx)
{
	switch (idx) {
	case FP_ADV_BT_ID:
		return fp_conn_get_fp_bt_id(FP_ADV_BT_ID);
	case FP_FMDN_ADV_BT_ID:
#ifdef CONFIG_FAST_PAIR_FMDN_USE_BT_ID_OF_FAST_PAIR
		return fp_conn_get_fp_bt_id(FP_ADV_BT_ID);
#else
		return fp_conn_get_fp_bt_id(FP_FMDN_ADV_BT_ID);
#endif
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	case FP_DULT_ADV_BT_ID:
#ifdef CONFIG_FAST_PAIR_FMDN_USE_BT_ID_OF_FAST_PAIR
		return fp_conn_get_fp_bt_id(FP_DULT_ADV_BT_ID - 1);
#else
		return fp_conn_get_fp_bt_id(FP_DULT_ADV_BT_ID);
#endif
#endif
	default:
		__ASSERT(0, "Invalid BT ID index %u", idx);
	}
	return -1;
}
