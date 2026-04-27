/**
 *******************************************************************************
 *
 * @file fp_fmdn_adv.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Advertisement Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>
#include <stdlib.h>
#include "app_work_q.h"
#include "fp_adv.h"
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
// Advertising interval to test in open air
#define FP_FMDN_ADV_DISCOVER_MS CONFIG_FP_FMDN_VALIDATOR_TEST_ADV_INT
#else
// Advertising interval within 2 seconds
#define FP_FMDN_ADV_DISCOVER_MS 2000
#endif
// Advertising interval range to allow controller randomness (advDelay)
#define FMDN_ADV_INTERVAL_RANGE_MS 20
#define FMDN_ADV_NONDISCOVER_INT_MIN                                                               \
	BT_GAP_MS_TO_ADV_INTERVAL(FP_FMDN_ADV_DISCOVER_MS - FMDN_ADV_INTERVAL_RANGE_MS)
#define FMDN_ADV_NONDISCOVER_INT_MAX BT_GAP_MS_TO_ADV_INTERVAL(FP_FMDN_ADV_DISCOVER_MS)

#define FMDN_MAX_CONN CONFIG_FMDN_MAX_CONN
static bool fmdn_conns[CONFIG_BT_MAX_CONN];
static struct bt_le_ext_adv *fmdn_adv_set = NULL;
static struct bt_le_adv_param fmdn_adv_param = {
	.id = 0, // Will be set dynamically in fp_fmdn_adv_start()
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
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_SVC_DATA16, (uint8_t *)&fmdn_adv_data, sizeof(fmdn_adv_t)),
};

#ifdef CONFIG_FAST_PAIR_FMDN_MERGED_ADV
/* Indices into fmdn_merged_ad[] */
#define FMDN_MERGED_AD_IDX_FP_SVC_DATA   2
#define FMDN_MERGED_AD_IDX_FMDN_SVC_DATA 3
static struct bt_data fmdn_merged_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_TX_POWER, FP_APP_TX_PWR_ADV),
	BT_DATA(BT_DATA_SVC_DATA16, NULL, 0),
	BT_DATA(BT_DATA_SVC_DATA16, (uint8_t *)&fmdn_adv_data, sizeof(fmdn_adv_t)),
};
#endif

static bool fp_fmdn_use_merged_adv(void)
{
	return IS_ENABLED(CONFIG_FAST_PAIR_FMDN_MERGED_ADV) && fp_mode_is_provisioned();
}

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

static void fp_fmdn_adv_refresh_payload(bool rotate_eid)
{
	/* EID rotation is a core FMDN requirement, independent of DULT.
	 * fp_fmdn_key_update_eid() checks the 2^K clock window internally
	 * and is a no-op when the window has not advanced — safe to call
	 * unconditionally whenever the payload needs refreshing.
	 */
	if (rotate_eid) {
		fp_fmdn_key_update_eid();
	}
	fp_fmdn_adv_data();
}

#ifdef CONFIG_FAST_PAIR_FMDN_MERGED_ADV
static void fp_fmdn_adv_get_service_data(struct bt_data *ad)
{
	ad->type = fmdn_ad[1].type;
	ad->data_len = sizeof(fmdn_adv_data);
	ad->data = (uint8_t *)&fmdn_adv_data;
}
#endif /* CONFIG_FAST_PAIR_FMDN_MERGED_ADV */

static void fp_fmdn_adv_notify_connected(struct bt_conn *conn)
{
	__ASSERT_NO_MSG(conn);

	fmdn_conns[bt_conn_index(conn)] = true;
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
	if (!fmdn_adv_set) {
		LOG_ERR("Cannot start advertising: adv_set is NULL!");
		return -EINVAL;
	}

	int err = bt_le_ext_adv_start(fmdn_adv_set, BT_LE_EXT_ADV_START_DEFAULT);
	if (err == -EALREADY) {
		LOG_DBG("Advertising already running");
		return 0;
	} else if (err) {
		LOG_ERR("Failed to start advertising (err %d)", err);
		return err;
	}

	if (fp_fmdn_use_merged_adv()) {
		power_loss_recovery_state_t plr_state = fp_mode_power_loss_recovery_state_get();
		if (plr_state != POWER_LOSS_RECOVERY_IDLE) {
			LOG_INF("FMDN merged Fast Pair Advertising successfully started (PLR "
				"state: %d)",
				plr_state);
		} else {
			LOG_INF("FMDN merged Fast Pair Advertising successfully started");
		}
	} else {
		LOG_INF("FMDN Advertising successfully started");
	}
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
	fp_fmdn_adv_notify_connected(info->conn);
	uint8_t fmdn_conn_cnt = fp_fmdn_get_conn_cnt();

	/* Only restart advertising after a connection if we can accept more connections.
	 * With FMDN_MAX_CONN == 1, attempting to restart advertising on connect can
	 * confuse some controllers and lead to advertising not being discoverable after
	 * a subsequent disconnect.
	 */
	if (fmdn_conn_cnt < FMDN_MAX_CONN && fmdn_adv_set) {
		fp_fmdn_adv_adv_start();
	} else {
		LOG_WRN("Connection %u exceed %d", fmdn_conn_cnt, FMDN_MAX_CONN);
	}
}

static int fp_fmdn_adv_set_payload(bool rotate_eid)
{
	int err;

	fp_fmdn_adv_refresh_payload(rotate_eid);

	if (fp_fmdn_use_merged_adv()) {
#ifdef CONFIG_FAST_PAIR_FMDN_MERGED_ADV
		fp_fmdn_adv_get_service_data(&fmdn_merged_ad[FMDN_MERGED_AD_IDX_FMDN_SVC_DATA]);

		struct bt_data fp_ad;

		if (!fp_adv_refresh_non_disc_payload(rotate_eid)) {
			/* FP payload build failed. If we already have a valid FP
			 * service-data pointer from the last successful build, push
			 * the new FMDN EID to the controller with the stale (but
			 * structurally valid) FP data rather than skipping the
			 * controller update entirely.
			 */
			if (!fmdn_merged_ad[FMDN_MERGED_AD_IDX_FP_SVC_DATA].data) {
				LOG_ERR("No FP service data available; skipping adv update");
				return -EINVAL;
			}
			LOG_WRN("FP payload build failed; keeping previous FP data");
		} else {
			fp_adv_get_non_disc_service_data(&fp_ad);
			fmdn_merged_ad[FMDN_MERGED_AD_IDX_FP_SVC_DATA] = fp_ad;
		}

		LOG_DBG("fp_fmdn_adv_set_payload %p fmdn_merged_ad", (void *)fmdn_adv_set);
		err = bt_le_ext_adv_set_data(fmdn_adv_set, fmdn_merged_ad,
					     ARRAY_SIZE(fmdn_merged_ad), NULL, 0);
#else
		err = -EINVAL;
#endif
	} else {
		LOG_DBG("fp_fmdn_adv_set_payload %p fmdn_ad", (void *)fmdn_adv_set);
		err = bt_le_ext_adv_set_data(fmdn_adv_set, fmdn_ad, ARRAY_SIZE(fmdn_ad), NULL, 0);
	}

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

	/*
	 * FMDN owns the RPA timeout once provisioned, including during PLR.
	 * The FHN spec (ID rotation) requires ~1024s average rotation for both
	 * FHN frames and the corresponding BLE address. Since FMDN drives the
	 * EID clock, it is the authoritative owner of this timeout.
	 *
	 * fp_adv_rpa_expired() only sets the timeout before provisioning, when
	 * FMDN is not yet active. Once provisioned, it defers here.
	 *
	 * When sharing BT_ID with Fast Pair (CONFIG_FAST_PAIR_FMDN_USE_BT_ID_OF_FAST_PAIR),
	 * both rpa_expired callbacks fire on the same expiration event. FMDN sets
	 * the timeout and FP skips it, ensuring exactly one HCI command is issued
	 * with a single consistent random value from fp_mode_rpa_timeout().
	 */
	uint16_t next_timeout = fp_mode_rpa_timeout();
	int err = bt_le_set_rpa_timeout(next_timeout);
	if (err) {
		LOG_ERR("FMDN: bt_le_set_rpa_timeout failed: %d for %u [s]", err, next_timeout);
	} else {
		LOG_DBG("FMDN: setting RPA timeout to %u [s]", next_timeout);
	}

	if (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON) {
		static int64_t last_utp_rotation;
		int64_t current_time = k_uptime_get();
		if (current_time - last_utp_rotation < (SEC_PER_DAY * MSEC_PER_SEC)) {
			LOG_DBG("FMDN: UTP_MODE enabled, skip rotate the current RPA "
			"(24h not elapsed)");
			rpa_expired = false;
		} else {
			LOG_DBG("FMDN: UTP_MODE enabled, allowing RPA rotation after 24h");
			last_utp_rotation = current_time;
		}
	}

	LOG_DBG("FMDN: update adv payload");

	if (fp_fmdn_adv_set_payload(true)) {
		LOG_ERR("Failed to refresh FMDN advertising payload");
	}

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

	LOG_DBG("FMDN Advertising Stop");
	int err = bt_le_ext_adv_stop(fmdn_adv_set);
	if (err) {
		LOG_ERR("Failed to stop advertising (err %d)", err);
	}
	fp_fmdn_release_adv();
}

static void fp_fmdn_adv_start(void)
{
	int err;
	if (!fmdn_adv_set) {
		fmdn_adv_param.id = fp_conn_get_bt_id(FP_FMDN_ADV_BT_ID);
		LOG_INF("%s advertising on BT_ID %u",
			fp_fmdn_use_merged_adv() ? "FMDN merged" : "FMDN", fmdn_adv_param.id);

		/* Set advertising intervals based on PLR state when merged advertising is enabled
		 */
#ifdef CONFIG_FAST_PAIR_FMDN_MERGED_ADV
		power_loss_recovery_state_t plr_state = fp_mode_power_loss_recovery_state_get();
		if (plr_state == POWER_LOSS_RECOVERY_CONTINUOUS) {
			/* PLR continuous mode: use faster intervals (250ms) for quick discovery */
			fmdn_adv_param.interval_min = FP_ADV_PLR_CONTINUOUS_INT_MIN;
			fmdn_adv_param.interval_max = FP_ADV_PLR_CONTINUOUS_INT_MAX;
			LOG_DBG("FMDN: PLR continuous intervals (250ms)");
		} else {
			/* PLR periodic mode and normal provisioned mode: use FMDN spec intervals
			 * (2000ms) */
			fmdn_adv_param.interval_min = FMDN_ADV_NONDISCOVER_INT_MIN;
			fmdn_adv_param.interval_max = FMDN_ADV_NONDISCOVER_INT_MAX;
			LOG_DBG("FMDN: %s intervals (2000ms)",
				plr_state == POWER_LOSS_RECOVERY_PERIODIC ? "PLR periodic"
									  : "Normal provisioned");
		}
#else
		fmdn_adv_param.interval_min = FMDN_ADV_NONDISCOVER_INT_MIN;
		fmdn_adv_param.interval_max = FMDN_ADV_NONDISCOVER_INT_MAX;
#endif

		/* Reset options to base state before setting mode-specific flags */
		fmdn_adv_param.options = BT_LE_ADV_OPT_CONN;

		if (fp_fmdn_use_merged_adv()) {
			/* Merged advertising: Extended + Connectable (no scannable) */
			fmdn_adv_param.options |= BT_LE_ADV_OPT_EXT_ADV;
		} else {
#ifdef CONFIG_FMDN_ECC_SECP256R1
			/* Non-merged with SECP256R1: Extended + Connectable */
			fmdn_adv_param.options |= BT_LE_ADV_OPT_EXT_ADV;
#else
			/* Non-merged without SECP256R1: Legacy connectable advertising */
			/* BT_LE_ADV_OPT_EXT_ADV not set */
#endif
		}

		/* Set RPA timeout */
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

	err = fp_fmdn_adv_set_payload(false);
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

void fp_fmdn_adv_recreate(bool force_stop, bool stop_only)
{
	if (!fp_mode_is_provisioned() || force_stop) {
		fp_fmdn_adv_stop();
	}
	if (fp_mode_is_provisioned() && !stop_only) {
		atm_work_submit_to_app_work_q(&fp_fmdn_adv_start_action);
	}
}
