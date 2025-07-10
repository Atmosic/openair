/**
 *******************************************************************************
 *
 * @file fp_adv.c
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
#include <zephyr/random/random.h>
#include <stdlib.h>
#include "app_work_q.h"
#include "atm_utils_c.h"
#include "fp_adv.h"
#include "fp_conn.h"
#include "fp_common.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn_adv.h"
#endif
#include "fp_mode.h"
#include "fp_storage.h"
#include "gfp_crypto.h"

LOG_MODULE_REGISTER(fp, CONFIG_ATM_FP_LOG_LEVEL);

// Advertising interval in discoverable
#define FP_ADV_DISCOVER_MS     100
#define FP_ADV_DISCOVER_MS_MIN ((uint32_t)(FP_ADV_DISCOVER_MS - 20) * 1000 / 625)
#define FP_ADV_DISCOVER_MS_MAX ((uint32_t)FP_ADV_DISCOVER_MS * 1000 / 625)

// Advertising interval in non-discoverable
#define FP_ADV_NONDISCOVER_MS     250
#define FP_ADV_NONDISCOVER_MS_MIN ((uint32_t)(FP_ADV_NONDISCOVER_MS - 20) * 1000 / 625)
#define FP_ADV_NONDISCOVER_MS_MAX ((uint32_t)FP_ADV_NONDISCOVER_MS * 1000 / 625)

static struct bt_le_ext_adv *fp_adv_set = NULL;

static struct bt_le_adv_param adv_param = {
	.id = 1,
	.sid = 0,
	.secondary_max_skip = 0,
	.options = BT_LE_ADV_OPT_CONN,
	.peer = NULL,
};

#define FP_UUID_SERVICE 0xFE2C
typedef struct fp_disc_adv_s {
	uint16_t uuid;
	uint8_t model_id[FP_APP_MODEL_ID_LEN];
} __packed fp_disc_adv_t;
static fp_disc_adv_t fp_disc_adv_data;
static const struct bt_data fp_disc_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_TX_POWER, FP_APP_TX_PWR),
	BT_DATA(BT_DATA_SVC_DATA16, (uint8_t *)&fp_disc_adv_data, sizeof(fp_disc_adv_data)),
};

#define FMDN_ACCOUNT_FILTER_LEN 4
#ifdef CONFIG_BATT_NOTI
#define FP_GAP_BATT_IE_SIZE 4
#endif
typedef struct fp_non_disc_adv_s {
	uint16_t uuid;
	uint8_t ver_flag;
	uint8_t account_key_num;
	uint8_t act_filter_type;
	uint8_t act_filter[FMDN_ACCOUNT_FILTER_LEN];
	uint8_t salt_type;
	uint16_t salt;
#ifdef CONFIG_BATT_NOTI
	uint8_t batt_data[FP_GAP_BATT_IE_SIZE];
#endif
} __packed fp_non_disc_adv_t;
static fp_non_disc_adv_t fp_non_disc_adv_data;
static struct bt_data fp_non_disc_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_TX_POWER, FP_APP_TX_PWR),
	BT_DATA(BT_DATA_SVC_DATA16, (uint8_t *)&fp_non_disc_adv_data, sizeof(fp_non_disc_adv_t)),
};

uint16_t fp_adv_salt;
static void fp_adv_data_salt_update(void)
{
	sys_csrand_get((uint8_t *)&fp_adv_salt, sizeof(fp_adv_salt));
}
static uint16_t fp_adv_data_salt(void)
{
	if (!fp_adv_salt) {
		fp_adv_data_salt_update();
	}
	return fp_adv_salt;
}

static void fp_disc_fp_adv_data(void)
{
	fp_disc_adv_data.uuid = FP_UUID_SERVICE;
	uint8_t const model_id[] = {FP_APP_MODEL_ID};
	memcpy(fp_disc_adv_data.model_id, model_id, sizeof(model_id));
	LOG_HEXDUMP_DBG((uint8_t *)&fp_disc_adv_data, sizeof(fp_disc_adv_data), "fp_disc_adv_data");
}

static bool fp_non_disc_fp_adv_data(void)
{
	// process account data
	size_t ak_num = fp_storage_account_key_count_get();
	fp_non_disc_adv_data.uuid = FP_UUID_SERVICE;
	fp_non_disc_adv_data.ver_flag = 0x00;
	fp_non_disc_adv_data.account_key_num = ak_num;
	static gfp_crypto_acct_key_fl_info_t gfp_fl;
	if (!gfp_fl.data) {
		gfp_fl.max_data_len = fp_storage_account_key_filter_size(ak_num);
		gfp_fl.data = calloc(gfp_fl.max_data_len, sizeof(uint8_t));
	}
	uint16_t adv_salt = fp_adv_data_salt();
	uint8_t key_list[FP_ACCOUNT_KEY_LEN];
	fp_storage_account_key_list_get(key_list);
	static gfp_crypto_acct_key_fl_ctx_t tv_gbf;
	tv_gbf.acct_key_num = ak_num;
	tv_gbf.acct_key_list = &key_list[0];
	tv_gbf.salt = adv_salt;
#ifdef CONFIG_BATT_NOTI
	static uint8_t gfp_batti[FP_GAP_BATT_IE_SIZE] = {0x33, 0x40, 0x40, 0x40};
	tv_gbf.batt_data = &gfp_batti;
	tv_gbf.batt_data_len = FP_GAP_BATT_IE_SIZE;
	if (!gfp_crypto_acct_key_fl_gen(&gfp_fl, adv_salt, gfp_batti, FP_GAP_BATT_IE_SIZE,
					&tv_gbf)) {
		LOG_WRN("Gen account key filter failed");
		return false;
	}
#else
	if (!gfp_crypto_acct_key_fl_gen(&gfp_fl, adv_salt, NULL, 0, &tv_gbf)) {
		LOG_WRN("Gen account key filter failed");
		return false;
	}
#endif
#define FP_FIELD_TYPE_SHOW_PAIRING_UI_INDICATION 0b0000
#define FP_FIELD_TYPE_SALT                       0b0001
#define FP_FIELD_TYPE_HIDE_PAIRING_UI_INDICATION 0b0010
#define FP_FIELD_TYPE_SHOW_BATTERY_UI_INDICATION 0b0011
#define FP_FIELD_TYPE_HIDE_BATTERY_UI_INDICATION 0b0100

#define TYPE_BITS                        4
#define ENCODE_FIELD_LEN_TYPE(len, type) (((len) << TYPE_BITS) | (type))
	fp_non_disc_adv_data.act_filter_type = ENCODE_FIELD_LEN_TYPE(
		gfp_fl.max_data_len, FP_FIELD_TYPE_HIDE_PAIRING_UI_INDICATION);
	memcpy(fp_non_disc_adv_data.act_filter, gfp_fl.data, gfp_fl.max_data_len);
	fp_non_disc_adv_data.salt_type =
		ENCODE_FIELD_LEN_TYPE(sizeof(adv_salt), FP_FIELD_TYPE_SALT);
	atm_set_be16(&fp_non_disc_adv_data.salt, adv_salt);
#ifdef CONFIG_BATT_NOTI
	memcpy(fp_non_disc_adv_data.batt_data, gfp_gap_batti, FP_GAP_BATT_IE_SIZE);
#endif
	LOG_HEXDUMP_DBG((uint8_t *)&fp_non_disc_adv_data, sizeof(fp_non_disc_adv_data),
			"fp_non_disc_adv_data ");
	return true;
}

static void fp_adv_release_adv(void)
{
	if (!fp_adv_set) {
		return;
	}
	bt_le_ext_adv_delete(fp_adv_set);
	fp_adv_set = NULL;
}

static void fp_adv_adv_sent(struct bt_le_ext_adv *instance, struct bt_le_ext_adv_sent_info *info)
{
	fp_adv_release_adv();
}

static void fp_adv_connected(struct bt_le_ext_adv *instance,
			     struct bt_le_ext_adv_connected_info *info)
{
	fp_adv_release_adv();
}

static int fp_adv_set_payload(void)
{
	int err;
	fp_mode_t mode = fp_mode_get();
	if (mode == FP_MODE_PAIRING) {
		fp_disc_fp_adv_data();
		LOG_DBG("fp_adv_set_payload %p fp_disc_ad", (void *)fp_adv_set);
		err = bt_le_ext_adv_set_data(fp_adv_set, fp_disc_ad, ARRAY_SIZE(fp_disc_ad), NULL,
					     0);
	} else {
		fp_non_disc_fp_adv_data();
		LOG_DBG("fp_adv_set_payload %p fp_non_disc_ad", (void *)fp_adv_set);
		err = bt_le_ext_adv_set_data(fp_adv_set, fp_non_disc_ad, ARRAY_SIZE(fp_non_disc_ad),
					     NULL, 0);
	}
	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)", err);
		return err;
	}
	return 0;
}

static bool fp_adv_rpa_expired(struct bt_le_ext_adv *adv)
{
	/* It is assumed that the callback executes in the cooperative
	 * thread context as it interacts with the FMDN operations.
	 */
	__ASSERT_NO_MSG(!k_is_preempt_thread());
	__ASSERT_NO_MSG(!k_is_in_isr());

	LOG_DBG("RPA expired");
	if (adv != fp_adv_set) {
		LOG_WRN("RPA expired ignore due to adv != fp_adv_set");
	}
	bool rpa_expired = true;
	static int64_t uptime;
	if (!uptime) {
		uptime = k_uptime_get();
	} else {
		LOG_DBG("the last timeout has occurred %" PRId64 " [s] ago",
			(k_uptime_delta(&uptime) / MSEC_PER_SEC));
	}
	if (!fp_mode_is_provisioned()) {
		uint16_t next_timeout = fp_mode_rpa_timeout();
		int err = bt_le_set_rpa_timeout(next_timeout);
		if (err) {
			LOG_ERR("bt_le_set_rpa_timeout failed: %d for %u [s]", err, next_timeout);
		} else {
			LOG_DBG("setting RPA timeout to %u [s]", next_timeout);
		}
	}
	//  BLE address shall not be rotated before paired
	if (fp_mode_get() < FP_MODE_PAIRED) {
		LOG_DBG("fp_adv_rpa_expired expire_rpa false");
		rpa_expired = false;
	}

	LOG_DBG("update adv payload");
	fp_adv_data_salt_update();
	fp_adv_set_payload();

	LOG_DBG("RPA rotate %u", rpa_expired);
	return rpa_expired;
}

static const struct bt_le_ext_adv_cb adv_cb = {
	.sent = fp_adv_adv_sent,
	.connected = fp_adv_connected,
	.rpa_expired = fp_adv_rpa_expired,
};

static void fp_adv_stop(void)
{
	if (!fp_adv_set) {
		return;
	}
	LOG_INF("FP Advertising Stop");
	bt_le_ext_adv_stop(fp_adv_set);
	fp_adv_release_adv();
}

static void fp_adv_start(fp_mode_t mode)
{
	adv_param.id = fp_storage_bt_id_base_get() + FP_ADV_BT_ID;
	if (mode == FP_MODE_PAIRING) {
		adv_param.interval_min = FP_ADV_DISCOVER_MS_MIN;
		adv_param.interval_max = FP_ADV_DISCOVER_MS_MAX;
	} else {
		adv_param.interval_min = FP_ADV_NONDISCOVER_MS_MIN;
		adv_param.interval_max = FP_ADV_NONDISCOVER_MS_MAX;
	}

	if (mode != FP_MODE_PROVISIONED) {
		adv_param.options |= BT_LE_ADV_OPT_USE_IDENTITY;
	}

	int err = bt_le_ext_adv_create(&adv_param, &adv_cb, &fp_adv_set);
	if (err) {
		LOG_ERR("Failed to create advertising set (err %d)", err);
		return;
	}

	err = fp_adv_set_payload();
	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)", err);
		return;
	}

	err = bt_le_ext_adv_start(fp_adv_set, BT_LE_EXT_ADV_START_DEFAULT);
	if (err) {
		LOG_ERR("Failed to start advertising (err %d)", err);
		return;
	}
	LOG_INF("FP %s Advertising successfully started",
		(mode == FP_MODE_PAIRING) ? "Discoverable" : "Paired");
}

static void fp_adv_invoke_recreate(struct k_work *work)
{
	fp_mode_t mode = fp_mode_get();
	fp_adv_stop();
	if (mode == FP_MODE_PAIRING) {
		fp_adv_start(FP_MODE_PAIRING);
#ifdef CONFIG_FP_FMDN_PROVISION_EN_FP_ADV
	} else if (mode >= FP_MODE_PAIRED) {
#else
	} else if (mode == FP_MODE_PAIRED) {
#endif
		fp_adv_start(FP_MODE_PAIRED);
	}
}

K_WORK_DEFINE(fp_adv_action, fp_adv_invoke_recreate);

void fp_adv_recreate(void)
{
	atm_work_submit_to_app_work_q(&fp_adv_action);
}
