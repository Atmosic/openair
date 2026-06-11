/**
 *******************************************************************************
 *
 * @file fp_fmdn_reverse_ringing_adv.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Reverse Ringing - Advertisement-based Implementation
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include "fp_fmdn_reverse_ringing_adv.h"
#include "fp_fmdn_reverse_ringing.h"
#include "fp_fmdn_persistent_conn.h"
#include "fp_fmdn_key.h"
#include "fp_storage.h"
#include "gfp_crypto.h"
#include "fp_common.h"
#include "fp_conn.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

#define EDDYSTONE_UUID_SERVICE 0xFEAA

/// Reverse Ringing advertisement service data (Eddystone format)
typedef struct adv_ringing_svc_data_s {
	uint16_t uuid;                                ///< Eddystone UUID (0xFEAA)
	uint8_t frame_type;                           ///< Frame Type (ADV_RINGING_FRAME_TYPE)
	uint8_t nonce;                                ///< Action nonce
	uint8_t action_type;                          ///< Action type (0x01)
	uint8_t signature[ADV_RINGING_SIGNATURE_LEN]; ///< HMAC-SHA256 signature (first 8 bytes)
} adv_ringing_svc_data_t;

static adv_ringing_svc_data_t adv_ringing_svc_data;
static struct bt_data adv_ringing_ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_SVC_DATA16, (uint8_t *)&adv_ringing_svc_data,
		sizeof(adv_ringing_svc_data_t)),
};

static fp_fmdn_reverse_ringing_adv_state_t adv_ringing_state;

/* Track EID for nonce validity (nonce must be unique per EID) */
static uint8_t current_eid[FP_FMDN_STATE_EID_LEN];

static struct bt_le_ext_adv *adv_ringing_set;
static struct bt_le_adv_param adv_ringing_param = {
	.id = 0,
	.sid = 1,
	.secondary_max_skip = 0,
	/* Reverse ringing advertisement payload is only 18 bytes total:
	 * This fits comfortably in legacy advertising (31 byte limit)
	 */
	.options = BT_LE_ADV_OPT_CONN,
	.interval_min = BT_GAP_MS_TO_ADV_INTERVAL(ADV_RINGING_INTERVAL_MS),
	.interval_max = BT_GAP_MS_TO_ADV_INTERVAL(ADV_RINGING_INTERVAL_MS),
	.peer = NULL,
};

static void fp_fmdn_reverse_ringing_adv_connected(struct bt_le_ext_adv *adv,
						  struct bt_le_ext_adv_connected_info *info);
static bool fp_fmdn_reverse_ringing_adv_rpa_expired(struct bt_le_ext_adv *adv);

static const struct bt_le_ext_adv_cb adv_ringing_cb = {
	.connected = fp_fmdn_reverse_ringing_adv_connected,
	.rpa_expired = fp_fmdn_reverse_ringing_adv_rpa_expired,
};

int fp_fmdn_reverse_ringing_adv_init(void)
{
	LOG_INF("RR_ADV: Advertisement-based Ringing module initialized");
	memset(&adv_ringing_state, 0, sizeof(adv_ringing_state));
	return 0;
}

void fp_fmdn_reverse_ringing_adv_deinit(void)
{
	LOG_INF("RR_ADV: Advertisement-based Ringing module deinitialized");
	fp_fmdn_reverse_ringing_adv_stop();
	if (adv_ringing_set) {
		bt_le_ext_adv_delete(adv_ringing_set);
		adv_ringing_set = NULL;
	}
	memset(&adv_ringing_state, 0, sizeof(adv_ringing_state));
}

static void fp_fmdn_reverse_ringing_adv_release_adv(void)
{
	if (!adv_ringing_set) {
		return;
	}
	bt_le_ext_adv_delete(adv_ringing_set);
	adv_ringing_set = NULL;
}

static int fp_fmdn_reverse_ringing_adv_data(void)
{
	uint8_t eik[FP_EIK_LEN];

	/* Get EIK. current_eid was captured at session start in
	 * fp_fmdn_reverse_ringing_adv_start() and is used for all signatures.
	 * Per FHN v2 spec: if the EID rotates while advertising Reverse Ringing,
	 * the signature must keep using the previous (session-start) EID.
	 * Nonce uniqueness is relative to current_eid, so it simply increments
	 * for the lifetime of the session regardless of EID rotation.
	 */
	if (fp_storage_eid_key_get(eik)) {
		LOG_ERR("RR_ADV: Failed to get EIK");
		return -EIO;
	}

	/* Increment nonce for this request */
	adv_ringing_state.current_nonce++;

	/* Build HMAC-SHA256 input: protocol_version || EID || nonce || action_type || client_id */
	uint8_t protocol_version = BCNA_MJR_VER;
	uint8_t action_type = ADV_RINGING_ACTION_TYPE;
	uint8_t hmac_input[1 + FP_FMDN_STATE_EID_LEN + 1 + 1 + 1];
	uint8_t hmac_offset = 0;

	hmac_input[hmac_offset++] = protocol_version;
	memcpy(&hmac_input[hmac_offset], current_eid, FP_FMDN_STATE_EID_LEN);
	hmac_offset += FP_FMDN_STATE_EID_LEN;
	hmac_input[hmac_offset++] = adv_ringing_state.current_nonce;
	hmac_input[hmac_offset++] = action_type;
	hmac_input[hmac_offset++] = PC_CLIENT_ID_NONE;

	/* Compute HMAC-SHA256 signature */
	uint8_t hmac_full[GFP_CRYPTO_SHA256_DIG_LEN];
	if (!gfp_crypto_hmac_sha256(hmac_input, sizeof(hmac_input), hmac_full, eik, FP_EIK_LEN)) {
		LOG_ERR("RR_ADV: HMAC-SHA256 failed");
		return -EIO;
	}

	/* Build service data structure */
	adv_ringing_svc_data.uuid = EDDYSTONE_UUID_SERVICE;
	adv_ringing_svc_data.frame_type = ADV_RINGING_FRAME_TYPE;
	adv_ringing_svc_data.nonce = adv_ringing_state.current_nonce;
	adv_ringing_svc_data.action_type = action_type;
	memcpy(adv_ringing_svc_data.signature, hmac_full, ADV_RINGING_SIGNATURE_LEN);

	LOG_HEXDUMP_DBG((uint8_t *)&adv_ringing_svc_data, sizeof(adv_ringing_svc_data),
			"adv_ringing_svc_data: ");
	return 0;
}

static int fp_fmdn_reverse_ringing_adv_set_payload(void)
{
	int err = fp_fmdn_reverse_ringing_adv_data();
	if (err) {
		LOG_ERR("RR_ADV: Failed to build advertisement data (err %d)", err);
		return err;
	}
	LOG_DBG("fp_fmdn_reverse_ringing_adv_set_payload %p adv_ringing_ad",
		(void *)adv_ringing_set);
	err = bt_le_ext_adv_set_data(adv_ringing_set, adv_ringing_ad, ARRAY_SIZE(adv_ringing_ad),
				     NULL, 0);
	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)", err);
		return err;
	}
	return 0;
}

static void fp_fmdn_reverse_ringing_adv_connected(struct bt_le_ext_adv *adv,
						  struct bt_le_ext_adv_connected_info *info)
{
	LOG_INF("RR_ADV: Seeker connected in response to reverse ringing advertisement");

	/* Notify reverse ringing module about the connection */
	struct bt_conn *conn = info->conn;
	if (conn) {
		fp_fmdn_reverse_ringing_connected(conn);
	}
}

static bool fp_fmdn_reverse_ringing_adv_rpa_expired(struct bt_le_ext_adv *adv)
{
	/* It is assumed that the callback executes in the cooperative
	 * thread context as it interacts with the FMDN operations.
	 */
	__ASSERT_NO_MSG(!k_is_preempt_thread());
	__ASSERT_NO_MSG(!k_is_in_isr());

	LOG_DBG("RR_ADV: RPA expired");

	if (adv != adv_ringing_set) {
		LOG_WRN("RR_ADV: RPA expired ignore due to adv != adv_ringing_set");
		return true;
	}

	/* Update advertisement payload with new nonce
	 * Note: The nonce will be incremented in fp_fmdn_reverse_ringing_adv_data()
	 * if the EID hasn't rotated
	 */
	LOG_DBG("RR_ADV: Update adv payload on RPA rotation");
	fp_fmdn_reverse_ringing_adv_set_payload();

	/* Allow RPA rotation
	 * Note: For reverse ringing, we allow RPA rotation since the advertisement
	 * is short-lived (15-20 seconds) and privacy is important
	 */
	LOG_DBG("RR_ADV: RPA rotate allowed");
	return true;
}

static int fp_fmdn_reverse_ringing_adv_adv_start(void)
{
	int err = bt_le_ext_adv_start(adv_ringing_set, BT_LE_EXT_ADV_START_DEFAULT);
	if (err && (err != -EALREADY)) {
		LOG_ERR("Failed to start advertising (err %d)", err);
		return err;
	}
	return 0;
}

static void fp_fmdn_reverse_ringing_adv_adv_stop(void)
{
	if (!adv_ringing_set) {
		return;
	}
	LOG_DBG("RR_ADV: Advertising Stop");
	bt_le_ext_adv_stop(adv_ringing_set);
	fp_fmdn_reverse_ringing_adv_release_adv();
}

int fp_fmdn_reverse_ringing_adv_start(void)
{
	int err;

	LOG_INF("RR_ADV: Starting Reverse Ringing advertisement");

	if (adv_ringing_state.active) {
		LOG_WRN("RR_ADV: Already active");
		return -EALREADY;
	}

	/* Capture the EID at session start — this is the EID used for signing
	 * throughout the entire ringing session, even if EID rotates mid-session.
	 * Reset nonce to 0 so the new session starts a fresh unique nonce sequence
	 * (1, 2, 3, ...) relative to this EID, as required by the spec.
	 */
	(void)fp_fmdn_key_get_eid(current_eid);
	adv_ringing_state.current_nonce = 0;

	if (!adv_ringing_set) {
		adv_ringing_param.id = fp_conn_get_bt_id(FP_FMDN_ADV_BT_ID);
		LOG_INF("RR_ADV: advertising on BT_ID %u", adv_ringing_param.id);

		err = bt_le_ext_adv_create(&adv_ringing_param, &adv_ringing_cb, &adv_ringing_set);
		if (err) {
			LOG_ERR("Failed to create advertising set (err %d)", err);
			return err;
		}
	}

	err = fp_fmdn_reverse_ringing_adv_set_payload();
	if (err) {
		LOG_ERR("Failed to set payload (err %d)", err);
		return err;
	}

	err = fp_fmdn_reverse_ringing_adv_adv_start();
	if (err) {
		return err;
	}

	adv_ringing_state.active = true;
	adv_ringing_state.start_time_ms = k_uptime_get();

	LOG_INF("RR_ADV: Advertisement started (interval=%ums, nonce=0x%02x)",
		ADV_RINGING_INTERVAL_MS, adv_ringing_state.current_nonce);

	return 0;
}

void fp_fmdn_reverse_ringing_adv_stop(void)
{
	if (!adv_ringing_state.active) {
		return;
	}

	LOG_INF("RR_ADV: Stopping Reverse Ringing advertisement");
	fp_fmdn_reverse_ringing_adv_adv_stop();

	adv_ringing_state.active = false;
	adv_ringing_state.start_time_ms = 0;
}

const fp_fmdn_reverse_ringing_adv_state_t *fp_fmdn_reverse_ringing_adv_get_state(void)
{
	return &adv_ringing_state;
}
