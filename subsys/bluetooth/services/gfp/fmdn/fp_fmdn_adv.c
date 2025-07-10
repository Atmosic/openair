/**
 *******************************************************************************
 *
 * @file fp_fmdn_adv.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Advertisement Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <stdlib.h>
#include "app_work_q.h"
#include "fp_fmdn_adv.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn_gatt.h"
#include "fp_fmdn_key.h"
#endif
#include "fp_conn.h"
#include "fp_common.h"
#include "fp_mode.h"
#include "fp_storage.h"
#include "gfp_crypto.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

#ifdef CONFIG_FP_FMDN_VALIDATOR_TEST
// Advertising interval within 500 ms to test in open air
#define FP_FMDN_ADV_DISCOVER_MS 500
#else
// Advertising interval within 2 seconds
#define FP_FMDN_ADV_DISCOVER_MS 2000
#endif
#define FMDN_ADV_NONDISCOVER_MS_MIN ((uint32_t)(FP_FMDN_ADV_DISCOVER_MS - 20) * 1000 / 625)
#define FMDN_ADV_NONDISCOVER_MS_MAX ((uint32_t)FP_FMDN_ADV_DISCOVER_MS * 1000 / 625)

#define FMDN_MAX_CONN CONFIG_FMDN_MAX_CONN
static bool fmdn_conns[CONFIG_BT_MAX_CONN];
static struct bt_le_ext_adv *fmdn_adv_set = NULL;
static struct bt_le_adv_param fmdn_adv_param = {
	.id = 1,
	.sid = 0,
	.secondary_max_skip = 0,
	.options =
#ifdef CONFIG_FMDN_ECC_SECP256R1
		BT_LE_ADV_OPT_EXT_ADV |
#endif
		BT_LE_ADV_OPT_CONN,
	.peer = NULL,
};

#define FMDN_UUID_SERVICE 0xFEAA
typedef struct fmdn_adv_s {
	uint16_t uuid;
	uint8_t type;
	uint8_t fmdn_eid[FP_FMDN_STATE_EID_LEN];
#ifdef CONFIG_FMDN_HASH_FLAGS
	uint8_t flag;
#endif
} fmdn_adv_t;
static fmdn_adv_t fmdn_adv_data;
static struct bt_data fmdn_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, BT_LE_AD_NO_BREDR),
	BT_DATA(BT_DATA_SVC_DATA16, (uint8_t *)&fmdn_adv_data, sizeof(fmdn_adv_t)),
};

static void fp_fmdn_adv_data(void)
{
	fmdn_adv_data.uuid = FMDN_UUID_SERVICE;
	fmdn_adv_data.type = fp_storage_utp_mode_get();
	(void)fp_fmdn_key_get_eid(fmdn_adv_data.fmdn_eid);
#ifdef CONFIG_FMDN_HASH_FLAGS
	fmdn_adv_data.flag = fp_fmdn_key_get_eid_hashed_flags();
#endif
	LOG_HEXDUMP_DBG((uint8_t *)&fmdn_adv_data, sizeof(fmdn_adv_data), "fmdn_adv_data: ");
}

static void fp_fmdn_release_adv(void)
{
	if (!fmdn_adv_set) {
		return;
	}
	bt_le_ext_adv_delete(fmdn_adv_set);
	fmdn_adv_set = NULL;
}

static int fp_fmdn_adv_adv_start(void)
{
	int err = bt_le_ext_adv_start(fmdn_adv_set, BT_LE_EXT_ADV_START_DEFAULT);
	if (err && (err != -EALREADY)) {
		LOG_ERR("Failed to start advertising (err %d)", err);
		return err;
	}
	LOG_INF("FMDN Advertising successfully started");
	return 0;
}

static uint8_t fp_fmdn_get_conn_cnt(void)
{
	int cnt = 0;
	for (uint32_t i = 0; i < CONFIG_BT_MAX_CONN; i++) {
		if (fmdn_conns[i]) {
			cnt++;
		}
	}
	return cnt;
}

static void fp_fmdn_adv_connected(struct bt_le_ext_adv *instance,
				  struct bt_le_ext_adv_connected_info *info)
{
	fmdn_conns[bt_conn_index(info->conn)] = true;
	uint8_t fmdn_conn_cnt = fp_fmdn_get_conn_cnt();

	if (fmdn_conn_cnt < FMDN_MAX_CONN && fmdn_adv_set) {
		fp_fmdn_adv_adv_start();
	} else {
		LOG_WRN("Connection %u exceed %d", fmdn_conn_cnt, FMDN_MAX_CONN);
	}
}

static int fp_fmdn_adv_set_payload(void)
{
	fp_fmdn_adv_data();
	LOG_DBG("fp_fmdn_adv_set_payload %p fmdn_ad", (void *)fmdn_adv_set);
	int err = bt_le_ext_adv_set_data(fmdn_adv_set, fmdn_ad, ARRAY_SIZE(fmdn_ad), NULL, 0);
	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)", err);
		return err;
	}
	return 0;
}

static bool fp_fmdn_adv_rpa_expired(struct bt_le_ext_adv *adv)
{
	/* It is assumed that the callback executes in the cooperative
	 * thread context as it interacts with the FMDN operations.
	 */
	__ASSERT_NO_MSG(!k_is_preempt_thread());
	__ASSERT_NO_MSG(!k_is_in_isr());
	bool rpa_expired = true;
	LOG_DBG("FMDN: RPA expired");
	if (adv != fmdn_adv_set) {
		LOG_WRN("FMDN: RPA expired ignore due to adv != fmdn_adv_set");
	}
	static int64_t uptime;
	if (!uptime) {
		uptime = k_uptime_get();
	} else {
		LOG_DBG("FMDN: the last timeout has occurred %" PRId64 " [s] ago",
			(k_uptime_delta(&uptime) / MSEC_PER_SEC));
	}
	uint16_t next_timeout = fp_mode_rpa_timeout();
	int err = bt_le_set_rpa_timeout(next_timeout);
	if (err) {
		LOG_ERR("FMDN: bt_le_set_rpa_timeout failed: %d for %u [s]", err, next_timeout);
	} else {
		LOG_DBG("FMDN: setting RPA timeout to %u [s]", next_timeout);
	}
	if (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON) {
		LOG_DBG("FMDN: UTP_MODE enabled, skip rotate the current RPA");
		rpa_expired = false;
	}

	LOG_DBG("FMDN: update adv payload");
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	fp_fmdn_key_update_eid();
#endif
	fp_fmdn_adv_set_payload();

	LOG_DBG("FMDN: RPA rotate %u", rpa_expired);
	return rpa_expired;
}

static const struct bt_le_ext_adv_cb adv_cb = {
	.connected = fp_fmdn_adv_connected,
	.rpa_expired = fp_fmdn_adv_rpa_expired,
};

static void fp_fmdn_adv_stop(void)
{
	if (!fmdn_adv_set) {
		return;
	}
	LOG_INF("FMDN Advertising Stop");
	bt_le_ext_adv_stop(fmdn_adv_set);
	fp_fmdn_release_adv();
}

static void fp_fmdn_adv_start(void)
{
	int err;
	if (!fmdn_adv_set) {
		fmdn_adv_param.id = fp_storage_bt_id_base_get() + FP_FMDN_ADV_BT_ID;
		fmdn_adv_param.interval_min = FMDN_ADV_NONDISCOVER_MS_MIN;
		fmdn_adv_param.interval_max = FMDN_ADV_NONDISCOVER_MS_MIN;
		uint16_t rpa_timeout = fp_mode_rpa_timeout();
		int err = bt_le_set_rpa_timeout(rpa_timeout);
		if (err) {
			LOG_ERR("FMDN create ADV set_rpa_timeout failed: %d for %u [s]", err,
				rpa_timeout);
		} else {
			LOG_DBG("FMDN create ADV: setting RPA timeout to %u [s]", rpa_timeout);
		}
		err = bt_le_ext_adv_create(&fmdn_adv_param, &adv_cb, &fmdn_adv_set);
		if (err) {
			LOG_ERR("Failed to create advertising set (err %d)", err);
			return;
		}
	}

	err = fp_fmdn_adv_set_payload();
	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)", err);
		return;
	}

	fp_fmdn_adv_adv_start();
}

static void fp_fmdn_disconnected(struct bt_conn *conn, uint8_t reason)
{
	if (!fmdn_conns[bt_conn_index(conn)]) {
		return;
	}

	fmdn_conns[bt_conn_index(conn)] = false;
}

BT_CONN_CB_DEFINE(fmdn_conn_callbacks) = {
	.disconnected = fp_fmdn_disconnected,
};

static void fp_fmdn_adv_invoke_start(struct k_work *work)
{
	fp_fmdn_adv_start();
}
K_WORK_DEFINE(fp_fmdn_adv_start_action, fp_fmdn_adv_invoke_start);

static void fp_fmdn_adv_invoke_stop(struct k_work *work)
{
	fp_fmdn_adv_stop();
}
K_WORK_DEFINE(fp_fmdn_adv_stop_action, fp_fmdn_adv_invoke_stop);

void fp_fmdn_adv_recreate(bool force_stop)
{
	if (!fp_mode_is_provisioned() || force_stop) {
		atm_work_submit_to_app_work_q(&fp_fmdn_adv_stop_action);
	}
	if (fp_mode_is_provisioned()) {
		atm_work_submit_to_app_work_q(&fp_fmdn_adv_start_action);
	}
}
