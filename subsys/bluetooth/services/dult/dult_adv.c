/**
 *******************************************************************************
 *
 * @file dult_adv.c
 *
 * @brief Atmosic Detecting Unwanted Location Trackers (DULT) Advertisment
 * Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <stdlib.h>
#include "app_work_q.h"
#include "dult_adv.h"

LOG_MODULE_DECLARE(dult, CONFIG_ATM_DULT_LOG_LEVEL);

// Advertising interval in discoverable
#define DULT_ADV_MS     2000
#define DULT_ADV_MS_MIN ((uint32_t)(DULT_ADV_MS - 20) * 1000 / 625)
#define DULT_ADV_MS_MAX ((uint32_t)DULT_ADV_MS * 1000 / 625)

static struct bt_le_ext_adv *dult_adv_set = NULL;
static dult_mode_t dult_mode;
static uint8_t dult_adv_bt_id;
static struct bt_le_adv_param adv_param = {
	.id = 1,
	.sid = 0,
	.secondary_max_skip = 0,
	.options = BT_LE_ADV_OPT_CONN,
	.peer = NULL,
};

#define DULT_UUID_SERVICE 0xFEB2
typedef struct dult_adv_s {
	uint16_t uuid;
	uint8_t networkid;
	uint8_t no_mode;
} __packed dult_adv_t;
static dult_adv_t dult_adv_data;
static const struct bt_data dult_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_SVC_DATA16, (uint8_t *)&dult_adv_data, sizeof(dult_adv_t)),
};

static void dult_adv_data_update(void)
{
	dult_adv_data.uuid = DULT_UUID_SERVICE;
	dult_adv_data.networkid = CONFIG_DULT_NETWORK_ID;
	dult_adv_data.no_mode = dult_mode;
}

static void dult_adv_release_adv(void)
{
	if (!dult_adv_set) {
		return;
	}
	bt_le_ext_adv_delete(dult_adv_set);
	dult_adv_set = NULL;
}

static void dult_adv_adv_sent(struct bt_le_ext_adv *instance, struct bt_le_ext_adv_sent_info *info)
{
	dult_adv_release_adv();
}

static void dult_adv_connected(struct bt_le_ext_adv *instance,
			       struct bt_le_ext_adv_connected_info *info)
{
	dult_adv_release_adv();
}

static int64_t last_rotate;
static bool dult_adv_rpa_expired(struct bt_le_ext_adv *adv)
{
	/* It is assumed that the callback executes in the cooperative
	 * thread context as it interacts with the FMDN operations.
	 */
	__ASSERT_NO_MSG(!k_is_preempt_thread());
	__ASSERT_NO_MSG(!k_is_in_isr());
	bool rpa_expired = true;

	LOG_DBG("DULT: RPA expired");
	static int64_t uptime;
	if (!uptime) {
		uptime = k_uptime_get();
	} else {
		LOG_DBG("DULT: the last timeout has occurred %" PRId64 " [s] "
			"ago",
			(k_uptime_delta(&uptime) / MSEC_PER_SEC));
	}

	if (dult_mode == DULT_NO_MODE_SEPERATED) {
		if (!last_rotate) {
			last_rotate = uptime;
		}
		int64_t time_diff = k_uptime_delta(&uptime) - last_rotate;
		if (time_diff) {
			time_diff /= MSEC_PER_SEC;
		}
#define SEPERATE_TIMEOUT_SEC (24 * 60 * 60)
		if (time_diff < SEPERATE_TIMEOUT_SEC) {
			rpa_expired = false;
			LOG_INF(" Seperated Mode: time_diff %" PRId64 " [s], not achieved %d yet",
				time_diff, SEPERATE_TIMEOUT_SEC);
		}
	}
	LOG_DBG("DULT: RPA rotate %u", rpa_expired);
	return rpa_expired;
}

static const struct bt_le_ext_adv_cb dult_adv_cb = {
	.sent = dult_adv_adv_sent,
	.connected = dult_adv_connected,
	.rpa_expired = dult_adv_rpa_expired,
};

static void dult_adv_stop(void)
{
	if (!dult_adv_set) {
		return;
	}
	LOG_INF("DULT Advertising Stop");
	bt_le_ext_adv_stop(dult_adv_set);
	dult_adv_release_adv();
}

static void dult_adv_start(void)
{
	int err;
	if (!dult_adv_set) {
		adv_param.id = dult_adv_bt_id;
		adv_param.interval_min = DULT_ADV_MS_MIN;
		adv_param.interval_max = DULT_ADV_MS_MAX;

		err = bt_le_ext_adv_create(&adv_param, &dult_adv_cb, &dult_adv_set);
		if (err) {
			LOG_ERR("Failed to create advertising set (err %d)", err);
			return;
		}
	}
	dult_adv_data_update();
	err = bt_le_ext_adv_set_data(dult_adv_set, dult_ad, ARRAY_SIZE(dult_ad), NULL, 0);
	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)", err);
		return;
	}
	err = bt_le_ext_adv_start(dult_adv_set, BT_LE_EXT_ADV_START_DEFAULT);
	if (err && (err != -EALREADY)) {
		LOG_ERR("Failed to start advertising (err %d)", err);
		return;
	}
	LOG_INF("DULT Advertising successfully started");
}

static void dult_adv_invoke_action(struct k_work *work)
{
	dult_adv_start();
}
K_WORK_DEFINE(dult_adv_action, dult_adv_invoke_action);

void dult_adv_enable(dult_mode_t mode)
{
	if (dult_mode != mode) {
		LOG_INF("DULT adv create for mode [%u]", mode);
	}
	dult_mode = mode;
	atm_work_submit_to_app_work_q(&dult_adv_action);
}

void dult_adv_disable(void)
{
	dult_adv_stop();
}

void dult_adv_bt_id_set(uint8_t bt_id)
{
	dult_adv_bt_id = bt_id;
}
