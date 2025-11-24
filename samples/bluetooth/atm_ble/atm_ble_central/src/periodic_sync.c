/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>

#include "periodic_sync.h"

#define TIMEOUT_SYNC_CREATE K_SECONDS(10)
#define NAME_LEN            30

LOG_MODULE_REGISTER(periodic_sync, LOG_LEVEL_INF);

static bool per_adv_found;
static bt_addr_le_t per_addr;
static uint16_t per_adv_sync_timeout;
static uint8_t per_sid;

static K_SEM_DEFINE(sem_per_adv, 0, 1);
static K_SEM_DEFINE(sem_per_sync, 0, 1);
static K_SEM_DEFINE(sem_per_sync_lost, 0, 1);

static bool data_cb(struct bt_data *data, void *user_data)
{
	char *name = user_data;
	uint8_t len;

	switch (data->type) {
	case BT_DATA_NAME_SHORTENED:
	case BT_DATA_NAME_COMPLETE:
		len = MIN(data->data_len, NAME_LEN - 1);
		memcpy(name, data->data, len);
		name[len] = '\0';
		return false;
	default:
		return true;
	}
}

static const char *phy2str(uint8_t phy)
{
	switch (phy) {
	case 0:
		return "No packets";
	case BT_GAP_LE_PHY_1M:
		return "LE 1M";
	case BT_GAP_LE_PHY_2M:
		return "LE 2M";
	case BT_GAP_LE_PHY_CODED:
		return "LE Coded";
	default:
		return "Unknown";
	}
}

static void scan_recv(const struct bt_le_scan_recv_info *info, struct net_buf_simple *buf)
{
	char le_addr[BT_ADDR_LE_STR_LEN];
	char name[NAME_LEN];

	(void)memset(name, 0, sizeof(name));

	bt_data_parse(buf, data_cb, name);
	if (strlen(CONFIG_ATM_PER_ADV_NAME) > 0 && strcmp(name, CONFIG_ATM_PER_ADV_NAME) != 0) {
		/* Silently ignore name mismatches to avoid log flooding */
		return;
	}

	bt_addr_le_to_str(info->addr, le_addr, sizeof(le_addr));
	LOG_INF("[DEVICE]: %s, AD evt type %u, Tx Pwr: %i, RSSI %i %s "
		"C:%u S:%u D:%u SR:%u E:%u Prim: %s, Secn: %s, "
		"Interval: 0x%04x (%u ms), SID: %u\n",
		le_addr, info->adv_type, info->tx_power, info->rssi, name,
		(info->adv_props & BT_GAP_ADV_PROP_CONNECTABLE) != 0,
		(info->adv_props & BT_GAP_ADV_PROP_SCANNABLE) != 0,
		(info->adv_props & BT_GAP_ADV_PROP_DIRECTED) != 0,
		(info->adv_props & BT_GAP_ADV_PROP_SCAN_RESPONSE) != 0,
		(info->adv_props & BT_GAP_ADV_PROP_EXT_ADV) != 0, phy2str(info->primary_phy),
		phy2str(info->secondary_phy), info->interval, info->interval * 5 / 4, info->sid);

	if (!per_adv_found && info->interval) {
		uint32_t interval_us;
		uint32_t timeout;

		per_adv_found = true;

		/* Add retries and convert to unit in 10's of ms */
		interval_us = BT_GAP_PER_ADV_INTERVAL_TO_US(info->interval);

		timeout = BT_GAP_US_TO_PER_ADV_SYNC_TIMEOUT(interval_us);

		/* 10 attempts */
		timeout *= 10;

		/* Enforce restraints */
		per_adv_sync_timeout =
			CLAMP(timeout, BT_GAP_PER_ADV_MIN_TIMEOUT, BT_GAP_PER_ADV_MAX_TIMEOUT);

		per_sid = info->sid;
		bt_addr_le_copy(&per_addr, info->addr);

		k_sem_give(&sem_per_adv);
	}
}

static struct bt_le_scan_cb scan_callbacks = {
	.recv = scan_recv,
};

static void sync_cb(struct bt_le_per_adv_sync *sync, struct bt_le_per_adv_sync_synced_info *info)
{
	char le_addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(info->addr, le_addr, sizeof(le_addr));

	LOG_INF("PER_ADV_SYNC[%u]: [DEVICE]: %s synced, "
		"Interval 0x%04x (%u ms), PHY %s\n",
		bt_le_per_adv_sync_get_index(sync), le_addr, info->interval, info->interval * 5 / 4,
		phy2str(info->phy));

	k_sem_give(&sem_per_sync);
}

static void term_cb(struct bt_le_per_adv_sync *sync,
		    const struct bt_le_per_adv_sync_term_info *info)
{
	char le_addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(info->addr, le_addr, sizeof(le_addr));

	LOG_INF("PER_ADV_SYNC[%u]: [DEVICE]: %s sync terminated\n",
		bt_le_per_adv_sync_get_index(sync), le_addr);

	k_sem_give(&sem_per_sync_lost);
}

static void recv_cb(struct bt_le_per_adv_sync *sync,
		    const struct bt_le_per_adv_sync_recv_info *info, struct net_buf_simple *buf)
{
	char le_addr[BT_ADDR_LE_STR_LEN];
	char data_str[129];

	bt_addr_le_to_str(info->addr, le_addr, sizeof(le_addr));
	bin2hex(buf->data, buf->len, data_str, sizeof(data_str));

	LOG_INF("PER_ADV_SYNC[%u]: [DEVICE]: %s, tx_power %i, "
		"RSSI %i, CTE %u, data length %u, data: %s\n",
		bt_le_per_adv_sync_get_index(sync), le_addr, info->tx_power, info->rssi,
		info->cte_type, buf->len, data_str);
}

static struct bt_le_per_adv_sync_cb sync_callbacks = {
	.synced = sync_cb, .term = term_cb, .recv = recv_cb};

int periodic_sync(void)
{
	struct bt_le_per_adv_sync_param sync_create_param;
	struct bt_le_per_adv_sync *sync;
	int err;

	LOG_INF("Starting Periodic Advertising Synchronization Demo\n");

	LOG_INF("Scan callbacks register...");
	bt_le_scan_cb_register(&scan_callbacks);
	LOG_INF("Success");

	LOG_INF("Periodic Advertising callbacks register...");
	bt_le_per_adv_sync_cb_register(&sync_callbacks);
	LOG_INF("Success");

	LOG_INF("Start scanning...");
	err = bt_le_scan_start(BT_LE_SCAN_ACTIVE, NULL);
	if (err) {
		LOG_ERR("Failed (err %d)", err);
		return 0;
	}
	LOG_INF("Success");

	do {
		LOG_INF("Waiting for periodic advertising...");
		per_adv_found = false;
		err = k_sem_take(&sem_per_adv, K_FOREVER);
		if (err) {
			LOG_ERR("Failed (err %d)", err);
			return 0;
		}
		LOG_INF("Found periodic advertising");

		LOG_INF("Creating Periodic Advertising Sync...");
		bt_addr_le_copy(&sync_create_param.addr, &per_addr);
		sync_create_param.options = 0;
		sync_create_param.sid = per_sid;
		sync_create_param.skip = 0;
		sync_create_param.timeout = per_adv_sync_timeout;
		err = bt_le_per_adv_sync_create(&sync_create_param, &sync);
		if (err) {
			LOG_ERR("Failed (err %d)", err);
			return 0;
		}
		LOG_INF("Success");

		LOG_INF("Waiting for periodic sync...");
		err = k_sem_take(&sem_per_sync, TIMEOUT_SYNC_CREATE);
		if (err) {
			LOG_ERR("Failed (err %d)", err);

			LOG_ERR("Deleting Periodic Advertising Sync...");
			err = bt_le_per_adv_sync_delete(sync);
			if (err) {
				LOG_ERR("Failed (err %d)", err);
				return 0;
			}
			continue;
		}
		LOG_INF("Periodic sync established");

		LOG_INF("Waiting for periodic sync lost...");
		err = k_sem_take(&sem_per_sync_lost, K_FOREVER);
		if (err) {
			LOG_ERR("Failed (err %d)", err);
			return 0;
		}
		LOG_INF("Periodic sync lost");
	} while (true);
}
