/**
 *******************************************************************************
 *
 * @file fp_fmdn_gatt.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Gatt Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "app_work_q.h"
#include "atm_utils_c.h"
#include "fp_conn.h"
#include "fp_fmdn_adv.h"
#include "fp_fmdn_gatt.h"
#include "fp_fmdn_internal.h"
#include "fp_fmdn_key.h"
#include "fp_fmdn_persistent_conn.h"
#include "fp_mode.h"
#include "fp_storage.h"
#include "gfp_crypto.h"
#ifdef CONFIG_FMDN_PRECISION_FINDING
#include "fp_fhpf_gatt.h"
#endif
#ifdef CONFIG_FMDN_REVERSE_RINGING
#include "fp_fmdn_reverse_ringing.h"
#endif

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

#define FMDN_CONN_INTERVAL_MIN 760
#define FMDN_CONN_INTERVAL_MAX 800
#define FMDN_CONN_LATENCY      0
#define FMDN_CONN_TIMEOUT      800

/// Calibrated RSSI at 0m when CONFIG_MAX_TX_PWR = 0 dBm
#define FP_CALIBRATED_TX_PWR_0M ((int8_t)CONFIG_FAST_PAIR_TX_PWR_CALIBRATION_0M)

/// FMDN Read Beacon Parameters TX Power (RSSI@0m adjusted for CONFIG_MAX_TX_PWR)
#define FP_APP_TX_PWR_0M ((uint8_t)(int8_t)(FP_CALIBRATED_TX_PWR_0M + (int8_t)CONFIG_MAX_TX_PWR))

static struct bt_le_conn_param const fmdn_conn_params = BT_LE_CONN_PARAM_INIT(
	FMDN_CONN_INTERVAL_MIN, FMDN_CONN_INTERVAL_MAX, FMDN_CONN_LATENCY, FMDN_CONN_TIMEOUT);

static fp_fmdn_utp_mode_cb utp_mode_cb;
static fp_fmdn_ring_action_cb ring_action_cb;
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
static fp_fmdn_update_id_cb update_id_cb;
static fp_fmdn_utp_owner_conn_cb utp_owner_conn_cb;
#endif
static bcna_conn_ctx_t conn_contexts[CONFIG_BT_MAX_CONN];

static void fp_fmdn_provision_cleanup(void);
static bool delay_provision_cleanup;

static struct bt_gatt_attr *fmdn_attr;

// Work item for deferred FMDN crypto operations (EID/DULT generation)
typedef struct {
	struct k_work work;
} fp_fmdn_provision_work_item_t;

static int fp_fmdn_bcna_resp_send(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				  const uint8_t *rsp, uint16_t rsp_len)
{
	LOG_HEXDUMP_DBG(rsp, rsp_len, "BCNA response:");
	int err = bt_gatt_notify(conn, attr, rsp, rsp_len);
	if (err) {
		return err;
	}
	return 0;
}

static bool bcna_is_op_auth_gen(uint8_t data_id)
{
	return (data_id == BCNA_OP_READ_EID_KEY || data_id == BCNA_OP_RING_STATE_CHANGE ||
		data_id == BCNA_OP_READ_RINGING_STATE || data_id == BCNA_OP_ACTIVATE_UTP ||
		data_id == BCNA_OP_DEACTIVATE_UTP);
}

static bool bcna_auth_key_gen(uint8_t data_id, uint8_t *secret_key, uint16_t *secret_key_len)
{
	if (!fp_storage_eid_key_valid()) {
		LOG_INF("BCNA EID invalid");
		return false;
	}
	uint8_t eid_key[FP_FMDN_EID_KEY_LEN];
	fp_storage_eid_key_get(eid_key);
	fp_fmdn_auth_key_type_t key_type;
	switch (data_id) {
	case BCNA_OP_READ_EID_KEY:
		key_type = FP_FMDN_AUTH_KEY_TYPE_RECOVERY;
		break;
	case BCNA_OP_RING_STATE_CHANGE:
	case BCNA_OP_READ_RINGING_STATE:
		key_type = FP_FMDN_AUTH_KEY_TYPE_RING;
		break;
	case BCNA_OP_ACTIVATE_UTP:
	case BCNA_OP_DEACTIVATE_UTP:
		key_type = FP_FMDN_AUTH_KEY_TYPE_UTP;
		break;
	default:
		return false;
	}
	if (!fp_fmdn_key_generate(eid_key, key_type, secret_key, BCNA_AUTH_KEY_LEN)) {
		return false;
	}
	*secret_key_len = BCNA_AUTH_KEY_LEN;
	return true;
}

static void bcna_auth_data_gen(uint8_t *auth_data, uint16_t *auth_data_len,
			       bcna_write_data_t const *data, fp_fmdn_auth_data_type_t data_type,
			       bcna_conn_ctx_t const *conn_context)
{
	uint8_t constant_end = 0x01;
	uint8_t major_ver = BCNA_MJR_VER;
	uint16_t add_len = data->header.data_len - BCNA_AUTH_KEY_LEN;
	if ((data_type == FP_FMDN_AUTH_DATA_RES) || (data_type == FP_FMDN_AUTH_DATA_MOTION_NOTI)) {
		/* The first 8 bytes of HMAC-SHA256(account key, protocol major version
		 * number || nonce || data ID || data length || additional data || 0x1)
		 * Motion notifications use the Ranging Configuration base nonce instead
		 * of the most-recently-read nonce (handled in the nonce selection below).
		 */
		*auth_data_len = BCNA_MJR_VER_LEN + BCNA_RNDM_NONCE_LEN +
				 sizeof(data->header.data_id) + sizeof(data->header.data_len) +
				 add_len + sizeof(constant_end);
	} else if (data_type == FP_FMDN_AUTH_DATA_EID_READ_REQ) {
		/* The first 8 bytes of HMAC-SHA256(account key, protocol major version
		 * number || the last nonce read from the characteristic || data ID ||
		 * data length)
		 */
		*auth_data_len = BCNA_MJR_VER_LEN + BCNA_RNDM_NONCE_LEN +
				 sizeof(data->header.data_id) + sizeof(data->header.data_len);
	} else {
		/* The first 8 bytes of HMAC-SHA256(account key, protocol major version
		 * number || the last nonce read from the characteristic || data ID ||
		 * data length || additional data)
		 */
		*auth_data_len = BCNA_MJR_VER_LEN + BCNA_RNDM_NONCE_LEN +
				 +sizeof(data->header.data_id) + sizeof(data->header.data_len) +
				 add_len;
	}
	size_t offset = 0;
	/* Motion notifications use the nonce from the Ranging Configuration (base nonce),
	 * not the most-recently-read nonce, per the spec nonce validation rules.
	 */
	const uint8_t *nonce = (data_type == FP_FMDN_AUTH_DATA_MOTION_NOTI)
				       ? conn_context->motion_base_nonce
				       : conn_context->random_nonce;
	FP_UTIL_MEMCPY_SHIFT(auth_data, &major_ver, sizeof(major_ver), offset);
	FP_UTIL_MEMCPY_SHIFT(auth_data, nonce, BCNA_RNDM_NONCE_LEN, offset);
	FP_UTIL_MEMCPY_SHIFT(auth_data, &data->header.data_id, sizeof(data->header.data_id),
			     offset);
	FP_UTIL_MEMCPY_SHIFT(auth_data, &data->header.data_len, sizeof(data->header.data_len),
			     offset);
	if (data_type != FP_FMDN_AUTH_DATA_EID_READ_REQ) {
		FP_UTIL_MEMCPY_SHIFT(auth_data, data->addition_data, add_len, offset);
	}
	if ((data_type == FP_FMDN_AUTH_DATA_RES) || (data_type == FP_FMDN_AUTH_DATA_MOTION_NOTI)) {
		FP_UTIL_MEMCPY_SHIFT(auth_data, &constant_end, sizeof(constant_end), offset);
	}
}

static bool bcna_auth_seg_gen(bcna_conn_ctx_t const *conn_context, bcna_write_data_t const *data,
			      uint8_t *auth_seg, fp_fmdn_auth_data_type_t data_type)
{
	uint8_t auth_data[BCNA_AUTH_DATA_LEN];
	uint16_t auth_data_len;
	bcna_auth_data_gen(auth_data, &auth_data_len, data, data_type, conn_context);
	if (!gfp_crypto_hmac_sha256(auth_data, auth_data_len, auth_seg, conn_context->secret_key,
				    conn_context->secret_key_len)) {
		LOG_WRN("Generic HMAC sha256 failed");
		return false;
	}
	return true;
}

static uint16_t bcna_auth_seg_gen_validate(bcna_conn_ctx_t const *conn_context,
					   bcna_write_data_t const *req)
{
	uint8_t auth_seg[GFP_CRYPTO_SHA256_DIG_LEN];
	uint8_t data_type = FP_FMDN_AUTH_DATA_REQ;
	if (req->header.data_id == BCNA_OP_READ_EID_KEY) {
		data_type = FP_FMDN_AUTH_DATA_EID_READ_REQ;
	}
	if (!bcna_auth_seg_gen(conn_context, req, auth_seg, data_type)) {
		return BCNA_ERR_INVALID_VALUE;
	}
	if (memcmp(req->auth_key, auth_seg, BCNA_AUTH_KEY_LEN)) {
		return BCNA_ERR_UNAUTHENTICATED;
	}
	LOG_DBG("BCNA auth_validate passed (Request ID %#x)", req->header.data_id);
	return 0;
}

static uint16_t bcna_auth_validate(bcna_conn_ctx_t *conn_context, bcna_write_data_t const *req)
{
	if (bcna_is_op_auth_gen(req->header.data_id)) {
		if (!bcna_auth_key_gen(req->header.data_id, conn_context->secret_key,
				       &conn_context->secret_key_len)) {
			return BCNA_ERR_INVALID_VALUE;
		}
		if ((req->header.data_id == BCNA_OP_RING_STATE_CHANGE) &&
		    (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON) &&
		    fp_storage_utp_ignore_ring_auth_get()) {
			LOG_INF("BCNA UTP ignore ring auth");
			return 0;
		}
		return bcna_auth_seg_gen_validate(conn_context, req);
	}

#ifdef CONFIG_FMDN_PRECISION_FINDING
	/* Per Google FMDN spec: Skip authentication for Precision Finding in UTP mode
	 * https://developers.google.com/nearby/fast-pair/specifications/extensions/fmdn
	 * #unwanted_tracking_protection_with_precision_finding
	 */
	if (((req->header.data_id == BCNA_OP_RANGING_CAPABILITY) ||
	     (req->header.data_id == BCNA_OP_RANGING_CAPABILITY_CONFIG) ||
	     (req->header.data_id == BCNA_OP_RANGING_CAPABILITY_START) ||
	     (req->header.data_id == BCNA_OP_RANGING_CAPABILITY_STOP)) &&
	    (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON) &&
	    fp_storage_utp_ignore_ring_auth_get()) {
		LOG_INF("BCNA UTP ignore Precision Finding auth");
		return 0;
	}
#endif
	// check with all accout keys
	conn_context->secret_key_len = FP_ACCOUNT_KEY_LEN;
	uint8_t account_key_list[FP_ACCOUNT_KEY_CNT * FP_ACCOUNT_KEY_LEN];
	uint8_t acnt_key_len = fp_storage_account_key_list_get(account_key_list);
	for (uint8_t i = 0; i < acnt_key_len; i += FP_ACCOUNT_KEY_LEN) {
		memcpy(conn_context->secret_key, account_key_list + i, FP_ACCOUNT_KEY_LEN);
		if (!bcna_auth_seg_gen_validate(conn_context, req)) {
			return 0;
		}
	}
	return BCNA_ERR_UNAUTHENTICATED;
}

#ifdef CONFIG_FAST_PAIR_FMDN_DULT
static uint8_t fmdn_dult_id[FP_FMDN_DULT_ID_LEN];
#endif

// Deferred FMDN crypto operations (EID/DULT generation)
/* Apply provisioned state: generate EID/DULT IDs from stored key and start
 * the periodic clock save. Called both at boot (when already provisioned) and
 * after runtime provisioning completes.
 */
static void fp_fmdn_apply_provisioned_state(void)
{
	uint8_t eidk[FP_FMDN_EID_KEY_LEN];
	fp_storage_eid_key_get(eidk);
	fp_fmdn_key_gen_eid(eidk, true);
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	fp_fmdn_key_gen_dult_id(eidk, fmdn_dult_id);
	if (update_id_cb) {
		update_id_cb(fmdn_dult_id, FP_FMDN_DULT_ID_LEN);
	}
#endif
	fp_fmdn_key_clock_periodic_save_start();
}

static void fp_fmdn_provision_work_handler(struct k_work *work)
{
	/* Save clock immediately on first provisioning so a power loss before
	 * the first periodic fire does not lose the clock value.
	 */
	fp_fmdn_key_clock_save();

	fp_fmdn_apply_provisioned_state();

	// Finalize provisioning
	fp_mode_update(FP_MODE_PROVISIONED);
	LOG_INF("FMDN provisioned");

	fp_fmdn_provision_work_item_t *item =
		CONTAINER_OF(work, fp_fmdn_provision_work_item_t, work);
	k_free(item);
}

static void fp_fmdn_provision_done(uint8_t const *eidk)
{
	// Save EID key to storage (fast, non-blocking operation)
	fp_storage_eid_key_save(eidk);

	// Allocate and schedule deferred crypto work
	fp_fmdn_provision_work_item_t *work_item = k_malloc(sizeof(*work_item));
	if (!work_item) {
		LOG_ERR("FMDN: Failed to allocate work item");
		return;
	}

	work_item->work = (struct k_work)Z_WORK_INITIALIZER(fp_fmdn_provision_work_handler);
	int err = atm_work_submit_to_app_work_q(&work_item->work);
	if (err < 0) {
		LOG_ERR("FMDN: Failed to submit work: err=%d", err);
		k_free(work_item);
		return;
	}
}

static void fp_fmdn_provision_cleanup(void)
{
	LOG_INF("FMDN provision cleanup");
	if (fp_mode_is_provisioned()) {
		/* Stop the periodic clock save — no longer needed once unprovisioned */
		fp_fmdn_key_clock_periodic_save_stop();
		fp_fmdn_adv_recreate(true, true);
		fp_storage_eid_reset();
#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
		/* Delete Client ID from NVS and reset runtime state */
		fp_storage_pc_client_id_delete();
		fp_fmdn_persistent_conn_deinit();
#endif
#ifdef CONFIG_FMDN_REVERSE_RINGING
		/* Delete persisted enable flag and reset runtime state */
		fp_storage_rr_enabled_delete();
		fp_fmdn_reverse_ringing_deinit();
#endif
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
		memset(fmdn_dult_id, 0, FP_FMDN_DULT_ID_LEN);
		if (update_id_cb) {
			update_id_cb(fmdn_dult_id, FP_FMDN_DULT_ID_LEN);
		}
#endif
		return;
	}
	fp_storage_cur_account_key_clear();
}

ssize_t fp_fmdn_bcna_read(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			  uint16_t len, uint16_t offset)
{
	ssize_t res = len;
	uint8_t rsp[BCNA_READ_RESP_LEN];

	bcna_conn_ctx_t *conn_context = &conn_contexts[bt_conn_index(conn)];

	BUILD_ASSERT((sizeof(conn_context->random_nonce) + BCNA_MJR_VER_LEN) == BCNA_READ_RESP_LEN);

	LOG_DBG("BCNA GATT Read Request");
	int err = sys_csrand_get(conn_context->random_nonce, sizeof(conn_context->random_nonce));
	if (err) {
		LOG_ERR("BCNA: failed to generate random nonce: err=%d", err);
		return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
	}
	/* Each nonce read marks the start of a new session — reset the base nonce
	 * so the 1st Set Configuration of this session re-captures it.
	 */
	conn_context->motion_base_nonce_set = false;
	rsp[0] = BCNA_MJR_VER;
	memcpy(rsp + BCNA_MJR_VER_LEN, conn_context->random_nonce,
	       sizeof(conn_context->random_nonce));
	res = bt_gatt_attr_read(conn, attr, buf, len, offset, rsp, sizeof(rsp));
	if (res == sizeof(rsp)) {
		conn_context->is_challenge_valid = true;
		LOG_HEXDUMP_DBG(conn_context->random_nonce, sizeof(conn_context->random_nonce),
				"BCNA: challenge-response enabled for the next write:");
	}
	LOG_DBG("BCNA read: res=%zd conn=%p", res, (void *)conn);
	return res;
}

static size_t fp_fmdn_bcna_parameter_read_handle(bcna_conn_ctx_t const *conn_context,
						 bcna_write_data_t *resp, uint16_t *resp_len)
{
	uint8_t addition_data[BCNA_READ_PARAM_LEN];
	uint8_t *dst_ptr = addition_data;
	size_t offset = 0;
	uint8_t power = FP_APP_TX_PWR_0M;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &power, sizeof(power), offset);

	/* The current clock value in seconds (big endian).
	 * This provides clock synchronization as recommended by FMDN spec.
	 * The Seeker can use this to synchronize its clock with the Provider.
	 */
	uint32_t clock = fp_fmdn_key_clock_read();
	atm_set_be32(dst_ptr + offset, clock);
	offset += sizeof(clock);
	// The elliptic curve being used for encryption
	uint8_t curve_sel = FP_FMDN_CURVE_SEL;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &curve_sel, sizeof(curve_sel), offset);
	uint8_t components = CONFIG_FMDN_RING_COMPONENTS;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &components, sizeof(components), offset);
	uint8_t ring_cap = IS_ENABLED(CONFIG_FMDN_RING_VOL_SEL) ? 0x01 : 0x00;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &ring_cap, sizeof(ring_cap), offset);

	// Reserved (octets 8-9) + capabilities (octet 10) + zero padding (octets 11-15)
	uint8_t pad[8];
	memset(pad, 0, sizeof(pad));
	/* FHN v2: Capabilities bitmap (octet 10)
	 * Dynamically calculated based on enabled features using FP_FMDN_V2_CAPABILITIES_BITMAP
	 * Bit 0: Persistent Connection support
	 * Bit 1: Reverse Ringing support
	 * Bits 2-7: Reserved (must be zero)
	 *
	 * NOTE: Only send capabilities bitmap when protocol version is 0x02
	 * For v1 compatibility (protocol version 0x01), send 0x00 (padding)
	 */
	pad[2] = (BCNA_MJR_VER == 0x02) ? FP_FMDN_V2_CAPABILITIES_BITMAP : 0x00;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, pad, sizeof(pad), offset);

	if (BCNA_READ_PARAM_LEN != offset) {
		LOG_WRN("BCNA parameter read addition_data (%zu) not expected %d", offset,
			BCNA_READ_PARAM_LEN);
		return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}
	resp->header.data_len = BCNA_AUTH_KEY_LEN + offset;
	uint8_t enc_data[BCNA_READ_PARAM_LEN];
	if (!gfp_crypto_aes_ecb_enc(enc_data, addition_data, offset, conn_context->secret_key,
				    GFP_CRYPTO_AES_ECB_128)) {
		return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}
	memcpy(resp->addition_data, enc_data, BCNA_READ_PARAM_LEN);
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

static size_t fp_fmdn_bcna_provision_status_read_handle(bcna_conn_ctx_t const *conn_context,
							bcna_write_data_t *resp, uint16_t *resp_len)
{
	uint8_t *dst_ptr = resp->addition_data;
	uint8_t status = 0;
	if (fp_storage_check_is_owner_key(conn_context->secret_key)) {
		status |= FP_FMDN_PROVISION_STATE_AUTHED;
	}
	if (fp_storage_eid_key_valid()) {
		status |= FP_FMDN_PROVISION_STATE_EIDK_SET;
	}
	size_t offset = 0;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &status, sizeof(status), offset);
	// to do copy eid
	uint8_t fmdn_eid[FP_FMDN_STATE_EID_LEN];
	uint8_t len = fp_fmdn_key_get_eid(fmdn_eid);
	if (len) {
		FP_UTIL_MEMCPY_SHIFT(dst_ptr, fmdn_eid, len, offset);
	}
	resp->header.data_len = BCNA_AUTH_KEY_LEN + offset;
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

bool fp_fmdn_bcna_eik_auth_seg_gen(bcna_conn_ctx_t const *conn_context, uint8_t *curr_eidk,
				   uint8_t *auth_seg)
{
	uint8_t auth_data[BCNA_EID_KEY_AUTH_LEN];
	size_t offset = 0;
	/* the first 8 bytes of SHA256(current ephemeral identity key ||
	 * the last nonce read from the characteristic)
	 */
	FP_UTIL_MEMCPY_SHIFT(auth_data, curr_eidk, FP_FMDN_EID_KEY_LEN, offset);
	FP_UTIL_MEMCPY_SHIFT(auth_data, conn_context->random_nonce, BCNA_RNDM_NONCE_LEN, offset);
	/// SHA256(ephemeral identity key || the last nonce read from the
	/// characteristic)
	gfp_crypto_sha256(auth_data, BCNA_EID_KEY_AUTH_LEN, auth_seg);
	return true;
}

static bool fp_fmdn_bcna_is_eidk_check(bcna_conn_ctx_t const *conn_context, uint8_t const *data,
				       uint16_t data_len)
{
	if (!fp_storage_eid_key_valid()) {
		LOG_WRN("No valid eid key");
		return BT_GATT_ERR(BCNA_ERR_UNAUTHENTICATED);
	}
	uint8_t auth_data_offset = 0;
	if (data_len == (BCNA_AUTH_KEY_LEN + FP_FMDN_EID_KEY_LEN)) {
		auth_data_offset = FP_FMDN_EID_KEY_LEN;
	}
	uint8_t curr_eidk[FP_FMDN_EID_KEY_LEN];
	fp_storage_eid_key_get(curr_eidk);
	uint8_t auth_seg[GFP_CRYPTO_SHA256_DIG_LEN];
	fp_fmdn_bcna_eik_auth_seg_gen(conn_context, curr_eidk, auth_seg);
	if (memcmp(data + auth_data_offset, auth_seg, BCNA_AUTH_KEY_LEN)) {
		LOG_WRN("EIDK auth not match");
		return false;
	}
	LOG_DBG("BCNA EIDK auth validate passed");
	return true;
}

static bool fp_fmdn_bcna_set_clear_eik_check(bcna_conn_ctx_t const *conn_context,
					     bcna_write_data_t const *data)
{
	/// check if provision authed
	if (!fp_storage_check_is_owner_key(conn_context->secret_key)) {
		LOG_WRN("Set/Clear EIK owner key not match");
		return false;
	}
	/// check if EIK valid
	uint8_t addition_data_len = data->header.data_len - BCNA_AUTH_KEY_LEN;
	if ((addition_data_len == BCNA_AUTH_KEY_LEN) ||
	    (addition_data_len == (BCNA_AUTH_KEY_LEN + FP_FMDN_EID_KEY_LEN))) {
		return fp_fmdn_bcna_is_eidk_check(conn_context, data->addition_data,
						  addition_data_len);
	}
	if (fp_mode_is_provisioned()) {
		LOG_WRN("Set/Clear alreay provisioned");
		return false;
	}
	return true;
}

static size_t fp_fmdn_bcna_set_eid_key_handle(bcna_conn_ctx_t const *conn_context,
					      bcna_write_data_t *resp, uint16_t *resp_len)
{
	if (!fp_fmdn_bcna_set_clear_eik_check(conn_context, resp)) {
		return BT_GATT_ERR(BCNA_ERR_UNAUTHENTICATED);
	}
	uint8_t eidk[FP_FMDN_EID_KEY_LEN];
	gfp_crypto_aes_ecb_dec(eidk, resp->addition_data, GFP_CRYPTO_AES_BLOCK_LEN_BYTES,
			       conn_context->secret_key, GFP_CRYPTO_AES_ECB_128);
	gfp_crypto_aes_ecb_dec(eidk + GFP_CRYPTO_AES_BLOCK_LEN_BYTES,
			       resp->addition_data + GFP_CRYPTO_AES_BLOCK_LEN_BYTES,
			       GFP_CRYPTO_AES_BLOCK_LEN_BYTES, conn_context->secret_key,
			       GFP_CRYPTO_AES_ECB_128);
	fp_fmdn_provision_done(eidk);
	memset(resp->addition_data, 0, sizeof(resp->addition_data));
	resp->header.data_len = BCNA_AUTH_KEY_LEN;
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

static size_t fp_fmdn_bcna_clear_eid_key_handle(bcna_conn_ctx_t const *conn_context,
						bcna_write_data_t *resp, uint16_t *resp_len)
{
	if (!fp_fmdn_bcna_set_clear_eik_check(conn_context, resp)) {
		return BT_GATT_ERR(BCNA_ERR_UNAUTHENTICATED);
	}
	fp_fmdn_provision_cleanup();
	delay_provision_cleanup = true;
	memset(resp->addition_data, 0, sizeof(resp->addition_data));
	resp->header.data_len = BCNA_AUTH_KEY_LEN;
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

static size_t fp_fmdn_bcna_read_eid_key_handle(bcna_conn_ctx_t const *conn_context,
					       bcna_write_data_t *resp, uint16_t *resp_len)
{
	if (!fp_storage_eid_key_valid()) {
		LOG_WRN("eid_key not valid");
		return BT_GATT_ERR(BCNA_ERR_NO_USER_CONSENT);
	}
	size_t offset = 0;
	uint8_t addition_data[FP_EIK_LEN];
	static uint8_t eid_key[FP_EIK_LEN];
	fp_storage_eid_key_get(eid_key);
	FP_UTIL_MEMCPY_SHIFT(addition_data, eid_key, FP_EIK_LEN, offset);
	resp->header.data_len = BCNA_AUTH_KEY_LEN + offset;
	uint8_t enc_data[FP_EIK_LEN];
	if (!gfp_crypto_aes_ecb_enc(enc_data, addition_data, offset, conn_context->secret_key,
				    GFP_CRYPTO_AES_ECB_128)) {
		return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}
	memcpy(resp->addition_data, enc_data, FP_EIK_LEN);
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

static uint8_t cur_ring_state;
static uint16_t cur_ring_to_ds;
static uint32_t ring_start_time_ms;
static bool gatt_ring_en;
typedef struct {
	struct bt_conn *conn;
} ring_noti_info_t;
static ring_noti_info_t *ring_info;

static uint16_t fp_fmdn_bcna_ring_state_resp_handler(bcna_write_data_t *resp, uint16_t *resp_len,
						     uint8_t ring_state, uint16_t ring_to_ds)
{
	uint8_t addition_data[FP_FMDN_EID_KEY_LEN];
	uint8_t *dst_ptr = addition_data;
	size_t add_len = 0;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &ring_state, sizeof(ring_state), add_len);
	uint8_t components = CONFIG_FMDN_RING_COMPONENTS;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &components, sizeof(components), add_len);
	uint16_t tmp_ring_to_ds;
	atm_set_be16(&tmp_ring_to_ds, ring_to_ds);
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &tmp_ring_to_ds, sizeof(tmp_ring_to_ds), add_len);
	resp->header.data_len = BCNA_AUTH_KEY_LEN + add_len;
	memcpy(resp->addition_data, addition_data, add_len);
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

static void fp_fmdn_gatt_ring_stop_noti_send(struct k_work *work)
{
	if (!ring_info || !fmdn_attr) {
		return;
	}
	bcna_conn_ctx_t *conn_context = &conn_contexts[bt_conn_index(ring_info->conn)];
	bcna_write_data_t ring_noti;
	uint16_t ring_noti_len = 0;
	ring_noti.header.data_id = BCNA_OP_RING_STATE_CHANGE;
	fp_fmdn_bcna_ring_state_resp_handler(&ring_noti, &ring_noti_len, cur_ring_state,
					     cur_ring_to_ds);
	if (!ring_noti_len) {
		return;
	}
	/// update auth key from resp data
	uint8_t auth_seg_resp[GFP_CRYPTO_SHA256_DIG_LEN];
	if (!bcna_auth_seg_gen(conn_context, &ring_noti, auth_seg_resp, FP_FMDN_AUTH_DATA_RES)) {
		LOG_WRN("BCNA ring notify bcna_auth_seg_gen failed");
		return;
	}
	memcpy(ring_noti.auth_key, auth_seg_resp, BCNA_AUTH_KEY_LEN);
	LOG_INF("BCNA ring stop send notify");
	fp_fmdn_bcna_resp_send(ring_info->conn, fmdn_attr, (uint8_t *)&ring_noti, ring_noti_len);
	k_free(ring_info);
	ring_info = NULL;
}
K_WORK_DEFINE(fp_fmdn_gatt_ring_stop_noti, fp_fmdn_gatt_ring_stop_noti_send);

static void fp_fmdn_ring_state_stop(uint8_t state)
{
	cur_ring_state = state;
	cur_ring_to_ds = 0;
	ring_start_time_ms = 0;
	gatt_ring_en = false;
	if (ring_action_cb) {
		ring_action_cb(cur_ring_state == FP_FMDN_RING_STATE_STARTED, FMDN_RING_OP_RING_ALL,
			       FP_FMDN_RING_VOL_DEFAULT, cur_ring_to_ds);
	}
	atm_work_submit_to_app_work_q(&fp_fmdn_gatt_ring_stop_noti);
}

static void fp_fmdn_ring_timeout_handler(struct k_work *work)
{
	LOG_INF("BCNA Ring Timeout");
	fp_fmdn_ring_state_stop(FP_FMDN_RING_STATE_STOPED_TIMEOUT);
}
K_WORK_DELAYABLE_DEFINE(fp_fmdn_ring_timer_id, fp_fmdn_ring_timeout_handler);

static void fp_fmnd_gatt_ring_update(bool en, uint16_t to_ds, uint8_t ring_op, uint8_t ring_vol_lvl)
{
	if (ring_action_cb) {
		ring_action_cb(en, ring_op, ring_vol_lvl, to_ds);
	}
	if (en && to_ds) {
		uint16_t to_s = to_ds / 10;
		atm_work_reschedule_for_app_work_q(&fp_fmdn_ring_timer_id, K_SECONDS(to_s));
	} else {
		k_work_cancel_delayable(&fp_fmdn_ring_timer_id);
	}
}

static size_t fp_fmdn_bcna_ring_read_ringing_state_handle(bcna_write_data_t *resp,
							  uint16_t *resp_len)
{
	uint8_t addition_data[FP_FMDN_EID_KEY_LEN];
	uint8_t *dst_ptr = addition_data;
	size_t offset = 0;
	uint8_t components = CONFIG_FMDN_RING_COMPONENTS;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &components, sizeof(components), offset);
	uint16_t ring_to_ds = 0x0;
	if (cur_ring_to_ds && ring_start_time_ms) {
		uint32_t ring_diff = k_uptime_get() - ring_start_time_ms;
#define MSEC_PER_DEC_SEC (MSEC_PER_SEC / 10) // 100 ms per decisecond
		ring_diff /= MSEC_PER_DEC_SEC;
		ring_to_ds = (cur_ring_to_ds > ring_diff) ? (cur_ring_to_ds - ring_diff) : 0;
		atm_set_be16(&ring_to_ds, ring_to_ds);
	}
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &ring_to_ds, sizeof(ring_to_ds), offset);
	resp->header.data_len = BCNA_AUTH_KEY_LEN + offset;
	memcpy(resp->addition_data, addition_data, offset);
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

static size_t fp_fmdn_bcna_ring_state_change_handle(bcna_write_data_t *resp, uint16_t *resp_len)
{
	uint8_t ring_op;
	uint8_t ring_vol_lvl;
	uint8_t offset = 0;
	memcpy(&ring_op, resp->addition_data + offset, sizeof(ring_op));
	offset += sizeof(ring_op);
	cur_ring_to_ds = atm_get_be16(resp->addition_data + offset);
	offset += sizeof(cur_ring_to_ds);
	memcpy(&ring_vol_lvl, resp->addition_data + offset, sizeof(ring_vol_lvl));
	offset += sizeof(ring_vol_lvl);
	gatt_ring_en = (ring_op != FMDN_RING_OP_RING_STOP);
	cur_ring_state = (ring_op == FMDN_RING_OP_RING_STOP)
				 ? FP_FMDN_RING_STATE_STOPED_GATT_REQUEST
				 : FP_FMDN_RING_STATE_STARTED;
	fp_fmnd_gatt_ring_update(cur_ring_state == FP_FMDN_RING_STATE_STARTED, cur_ring_to_ds,
				 ring_op, ring_vol_lvl);
	if (cur_ring_state == FP_FMDN_RING_STATE_STARTED) {
		ring_start_time_ms = k_uptime_get();
	} else {
		ring_start_time_ms = 0;
	}
	return fp_fmdn_bcna_ring_state_resp_handler(resp, resp_len, cur_ring_state, cur_ring_to_ds);
}

static size_t fp_fmdn_bcna_set_utp_handle(bcna_write_data_t *resp, uint16_t *resp_len,
					  fp_fmdn_utp_mode_t utp_mode)
{
	if ((utp_mode == FP_FMDN_UTP_MODE_ON) && (resp->header.data_len > BCNA_AUTH_KEY_LEN)) {
		// UTP ON with control flags provided - check bit 0 for skip authentication
		LOG_INF("BCNA UTP control flags 0x%02X", resp->addition_data[0]);
		fp_storage_utp_ignore_ring_auth_save(resp->addition_data[0] & 0x01);
	} else if (utp_mode == FP_FMDN_UTP_MODE_OFF) {
		// UTP OFF: Clear the flag (deactivated)
		fp_storage_utp_ignore_ring_auth_save(false);
	}
	fp_storage_utp_mode_save(utp_mode);
	fp_fmdn_adv_recreate(false, false);
	if (utp_mode_cb) {
		utp_mode_cb(utp_mode);
	}
	resp->header.data_len = BCNA_AUTH_KEY_LEN;
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

#ifdef CONFIG_FMDN_PRECISION_FINDING
static size_t fp_fhpf_gatt_bcna_ranging_handle(struct bt_conn *conn, uint8_t data_id,
					       bcna_write_data_t *req, uint16_t *resp_len)
{
	size_t err = 0;
	uint16_t response_size = 0;
	uint8_t add_data_len = req->header.data_len - BCNA_AUTH_KEY_LEN;
	if (add_data_len == 0) {
		LOG_ERR("BCNA RC: No additional data provided for RC request");
		return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}
	LOG_HEXDUMP_DBG(req->addition_data, add_data_len, "BCNA RC: Request Ranging DE:");
	if (add_data_len < sizeof(ranging_oob_de_header_t)) {
		LOG_ERR("BCNA RC: No version and msg_id for RC request");
		return BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}
	switch (data_id) {
	case BCNA_OP_RANGING_CAPABILITY:
		err = fp_fhpf_gatt_bcna_ranging_cap_handle(conn, req->addition_data, add_data_len,
							   &response_size);
		break;
	case BCNA_OP_RANGING_CAPABILITY_CONFIG:
		err = fp_fhpf_gatt_bcna_ranging_conf_handle(conn, req->addition_data, add_data_len,
							    &response_size);
		break;
	case BCNA_OP_RANGING_CAPABILITY_START:
		err = fp_fhpf_gatt_bcna_ranging_start_handle(conn, req->addition_data, add_data_len,
							     &response_size);
		break;
	case BCNA_OP_RANGING_CAPABILITY_STOP:
		err = fp_fhpf_gatt_bcna_ranging_stop_handle(conn, req->addition_data, add_data_len,
							    &response_size);
		break;
	default:
		LOG_WRN("BCNA: unrecognized request: data_id=%#x", data_id);
		err = BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
	}
	if (err) {
		return err;
	}
	// Keep the same data_id, just update data_len to include the response data
	req->header.data_len = BCNA_AUTH_KEY_LEN + response_size;

	// Set total response length (header + auth key + additional data)
	*resp_len = req->header.data_len + 2; // +2 for data_id and data_len fields
	LOG_DBG("BCNA RC: Created Ranging response, size: %zu bytes", response_size);
	LOG_HEXDUMP_DBG(req->addition_data, response_size, "BCNA RC: Response Ranging DE:");
	return 0;
}
#endif

ssize_t fp_fmdn_bcna_write(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf,
			   uint16_t len, uint16_t offset, uint8_t flags)
{
	ssize_t res = len;
	size_t err = 0;

	LOG_HEXDUMP_DBG(buf, len, "BCNA GATT Write Request:");

	/* Do not perform any action if Fast Pair is not ready. */
	fp_mode_t mode = fp_mode_get();
	if (mode < FP_MODE_PAIRED) {
		err = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		LOG_INF("BCNA write: res=%zd conn=%p, "
			"Return error because Fast Pair Mode %u not allow",
			res, (void *)conn, mode);
		goto finish;
	}

	bcna_conn_ctx_t *conn_context = &conn_contexts[bt_conn_index(conn)];

	if (conn_context->is_challenge_valid) {
		LOG_DBG("BCNA: consuming random nonce read operation");
		conn_context->is_challenge_valid = false;
	} else {
		LOG_ERR("BCNA: failed to enable challenge-response");
		err = BT_GATT_ERR(BCNA_ERR_UNAUTHENTICATED);
		goto finish;
	}

	if (len < sizeof(bcna_write_data_header_t)) {
		LOG_ERR("BCNA: request header too short: len=%u", len);
		err = BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
		goto finish;
	}

	struct net_buf_simple bcna_buf;
	net_buf_simple_init_with_data(&bcna_buf, (void *)buf, len);
	bcna_write_data_t bcna_w_req;
	bcna_w_req.header.data_id = net_buf_simple_pull_u8(&bcna_buf);
	bcna_w_req.header.data_len = net_buf_simple_pull_u8(&bcna_buf);

	if (bcna_w_req.header.data_len != net_buf_simple_max_len(&bcna_buf)) {
		LOG_ERR("BCNA: request with incorrect length: %u!=%u", bcna_w_req.header.data_len,
			net_buf_simple_max_len(&bcna_buf));
		err = BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
		goto finish;
	}

	memcpy(bcna_w_req.auth_key, net_buf_simple_pull_mem(&bcna_buf, BCNA_AUTH_KEY_LEN),
	       BCNA_AUTH_KEY_LEN);
	uint8_t add_data_len = bcna_w_req.header.data_len - BCNA_AUTH_KEY_LEN;
	if (add_data_len) {
		memcpy(bcna_w_req.addition_data, net_buf_simple_pull_mem(&bcna_buf, add_data_len),
		       add_data_len);
	}

	if (bcna_auth_validate(conn_context, &bcna_w_req)) {
		LOG_WRN("BCNA request auth_validate failed (request ID %#x)",
			bcna_w_req.header.data_id);
		res = BT_GATT_ERR(BCNA_ERR_UNAUTHENTICATED);
		goto finish;
	}

	uint16_t resp_len = 0;
	switch (bcna_w_req.header.data_id) {
	case BCNA_OP_READ_PARAMMETERS:
		if (fp_mode_is_provisioned()) {
			LOG_INF("BCNA: read params, stop PLR");
			fp_mode_power_loss_recovery_stop();
			fp_fmdn_key_clock_save_immediate();
		}
		err = fp_fmdn_bcna_parameter_read_handle(conn_context, &bcna_w_req, &resp_len);
		break;
	case BCNA_OP_READ_PROVISION_STATE:
		err = fp_fmdn_bcna_provision_status_read_handle(conn_context, &bcna_w_req,
								&resp_len);
		break;
	case BCNA_OP_SET_EID_KEY:
		err = fp_fmdn_bcna_set_eid_key_handle(conn_context, &bcna_w_req, &resp_len);
		break;
	case BCNA_OP_CLEAR_EID_KEY:
		err = fp_fmdn_bcna_clear_eid_key_handle(conn_context, &bcna_w_req, &resp_len);
		break;
	case BCNA_OP_READ_EID_KEY:
		err = fp_fmdn_bcna_read_eid_key_handle(conn_context, &bcna_w_req, &resp_len);
		break;
	case BCNA_OP_READ_RINGING_STATE:
		err = fp_fmdn_bcna_ring_read_ringing_state_handle(&bcna_w_req, &resp_len);
		break;
	case BCNA_OP_RING_STATE_CHANGE:
		err = fp_fmdn_bcna_ring_state_change_handle(&bcna_w_req, &resp_len);
		if (gatt_ring_en) {
			ring_info = k_malloc(sizeof(ring_noti_info_t));
			__ASSERT(ring_info, "malloc ring_info failed");
			ring_info->conn = conn;
		}
		break;
	case BCNA_OP_ACTIVATE_UTP:
		err = fp_fmdn_bcna_set_utp_handle(&bcna_w_req, &resp_len, FP_FMDN_UTP_MODE_ON);
		break;
	case BCNA_OP_DEACTIVATE_UTP:
		err = fp_fmdn_bcna_set_utp_handle(&bcna_w_req, &resp_len, FP_FMDN_UTP_MODE_OFF);
		break;
#ifdef CONFIG_FMDN_PRECISION_FINDING
	case BCNA_OP_RANGING_CAPABILITY:
	case BCNA_OP_RANGING_CAPABILITY_CONFIG:
		/* Capture the base nonce for motion notification auth from the 1st
		 * Set Configuration only. OOB v2+ allows multiple Set Configuration
		 * messages per session (technology transitioning), but the nonce used
		 * for all motion notification HMAC calculations must always be the one
		 * read before the very first Set Configuration in the session.
		 */
		if ((bcna_w_req.header.data_id == BCNA_OP_RANGING_CAPABILITY_CONFIG) &&
		    !conn_context->motion_base_nonce_set) {
			memcpy(conn_context->motion_base_nonce, conn_context->random_nonce,
			       BCNA_RNDM_NONCE_LEN);
			conn_context->motion_base_nonce_set = true;
		}
		/* fall through */
	case BCNA_OP_RANGING_CAPABILITY_START:
	case BCNA_OP_RANGING_CAPABILITY_STOP:
		err = fp_fhpf_gatt_bcna_ranging_handle(conn, bcna_w_req.header.data_id, &bcna_w_req,
						       &resp_len);
		break;
#endif
	default:
		LOG_WRN("BCNA: unrecognized request: data_id=%#x", bcna_w_req.header.data_id);
		err = BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
		goto finish;
	}
	if (resp_len && !err) {
		/// update auth key from resp data
		uint8_t auth_seg_resp[GFP_CRYPTO_SHA256_DIG_LEN];
		if (!bcna_auth_seg_gen(conn_context, &bcna_w_req, auth_seg_resp,
				       FP_FMDN_AUTH_DATA_RES)) {
			LOG_WRN("BCNA response bcna_auth_seg_gen failed");
			err = BT_GATT_ERR(BCNA_ERR_INVALID_VALUE);
			goto finish;
		}
		memcpy(bcna_w_req.auth_key, auth_seg_resp, BCNA_AUTH_KEY_LEN);
		fp_fmdn_bcna_resp_send(conn, attr, (uint8_t *)&bcna_w_req, resp_len);
	}
finish:
	if (err) {
		res = err;
	}
	LOG_DBG("BCNA write: res=%zd conn=%p", res, (void *)conn);
	return res;
}

void fp_fmdn_bcna_ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_DBG("BCNA CCCD write, handle: %u, value: 0x%04X", attr->handle, value);
}

static void fp_fmdn_gatt_conn_invoke_action(struct k_work *work)
{
	ARG_UNUSED(work);
	/* Do not restart advertising on connect.
	 *
	 * In merged mode, starting advertising again while a connection is being
	 * established can leave the advertising state unstable on some controllers.
	 * If multiple connections are desired, fp_fmdn_adv.c handles the "restart to
	 * accept more" policy from the advertising set callback.
	 */
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	if (utp_owner_conn_cb) {
		utp_owner_conn_cb(true);
	}
#endif
}
K_WORK_DEFINE(fp_fmdn_gatt_conn_action, fp_fmdn_gatt_conn_invoke_action);

static void fp_fmdn_gatt_disconn_invoke_action(struct k_work *work)
{
	ARG_UNUSED(work);
	if (delay_provision_cleanup) {
		delay_provision_cleanup = false;
		fp_storge_account_key_reset();
		fp_mode_update(FP_MODE_NONE);
	} else {
		/* BT_LE_ADV_OPT_EXT_ADV is used by merged adv and non-merged adv
		 * with CONFIG_FMDN_ECC_SECP256R1.  When a connectable extended adv
		 * set establishes a connection the controller stops it automatically,
		 * and on disconnect has no way to know the set should resume —
		 * bt_le_ext_adv_start() on the same handle is unreliable on some
		 * controllers and the adv becomes invisible.  Delete and recreate
		 * the set to recover cleanly.  Legacy (non-extended) advertising
		 * does not have this problem and can simply resume.
		 */
		bool use_ext_adv = IS_ENABLED(CONFIG_FAST_PAIR_FMDN_MERGED_ADV) ||
				   IS_ENABLED(CONFIG_FMDN_ECC_SECP256R1);
		fp_fmdn_adv_recreate(use_ext_adv, false);
	}
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	if (utp_owner_conn_cb) {
		utp_owner_conn_cb(false);
	}
#endif
}
K_WORK_DEFINE(fp_fmdn_gatt_disconn_action, fp_fmdn_gatt_disconn_invoke_action);

static void fp_fmdn_gatt_connected(struct bt_conn *conn, uint8_t err)
{
	LOG_DBG("Connected conn(%p) err(0x%02x) ", (void *)conn, err);
	if (!fp_conn_validate(conn)) {
		return;
	}
	LOG_DBG("FMDN Gatt connect");
	if (!fp_mode_is_provisioned()) {
		return;
	}

#ifdef CONFIG_FMDN_PRECISION_FINDING
	// Handle precision finding connection event
	fp_fhpf_gatt_conn_event(conn, true);
#endif

	atm_work_submit_to_app_work_q(&fp_fmdn_gatt_conn_action);
}

static void fp_fmdn_gatt_disconnected(struct bt_conn *conn, uint8_t reason)
{
	LOG_DBG("Discon conn(%p) res(0x%02x) ", (void *)conn, reason);
	if (!fp_conn_validate(conn)) {
		return;
	}
	LOG_DBG("FMDN Gatt Disconnect");
	if (!fp_mode_is_provisioned()) {
		return;
	}

#ifdef CONFIG_FMDN_PRECISION_FINDING
	// Handle precision finding disconnection event
	fp_fhpf_gatt_conn_event(conn, false);
#endif

#ifdef CONFIG_FMDN_PERSISTENT_CONNECTION
	// Handle persistent connection disconnection
	fp_fmdn_persistent_conn_disconnected(conn);
#endif

#ifdef CONFIG_FMDN_REVERSE_RINGING
	// Handle reverse ringing disconnection
	fp_fmdn_reverse_ringing_disconnected(conn);
#endif

	atm_work_submit_to_app_work_q(&fp_fmdn_gatt_disconn_action);
}

static void fp_fmdn_security_changed(struct bt_conn *conn, bt_security_t level,
				     enum bt_security_err err)
{
	if (!fp_conn_validate(conn)) {
		return;
	}
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (err) {
		LOG_ERR("Security failed: %s level:%u err:%d", addr, level, err);
		return;
	}

	struct bt_conn_info info;
	bt_conn_get_info(conn, &info);

	LOG_INF("Security changed: %s level:%u ID:%d", addr, level, info.id);

#ifdef CONFIG_FMDN_PRECISION_FINDING
	// Handle precision finding security change event
	fp_fhpf_gatt_security_changed(conn, level, err);
#endif

	// Log successful pairing for FMDN connection
	if (level >= BT_SECURITY_L2) {
		LOG_INF("FMDN connection secured: %s level:%u", addr, level);
		if (fp_mode_is_provisioned()) {
			bt_conn_le_param_update(conn, &fmdn_conn_params);
		}

#ifdef CONFIG_FMDN_REVERSE_RINGING
		// Handle reverse ringing encryption enabled
		fp_fmdn_reverse_ringing_encryption_enabled(conn);
#endif
	}
}

BT_CONN_CB_DEFINE(fp_fmdn_gatt_conn_callbacks) = {
	.connected = fp_fmdn_gatt_connected,
	.disconnected = fp_fmdn_gatt_disconnected,
	.security_changed = fp_fmdn_security_changed,
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	.le_cs_procedure_enable_complete = fp_fhpf_gatt_cs_procedure_enabled_cb,
	.le_cs_config_complete = fp_fhpf_gatt_cs_config_created_cb,
#endif
};

#ifdef CONFIG_FAST_PAIR_FMDN_DULT
void fp_fmdn_gatt_utp_mode_reg(fp_fmdn_utp_mode_cb const hdlr)
{
	if (!utp_mode_cb) {
		utp_mode_cb = hdlr;
	}
}

void fp_fmdn_gatt_ring_action_reg(fp_fmdn_ring_action_cb const hdlr)
{
	if (!ring_action_cb) {
		ring_action_cb = hdlr;
	}
}

void fp_fmdn_gatt_update_id_reg(fp_fmdn_update_id_cb const hdlr)
{
	if (!update_id_cb) {
		update_id_cb = hdlr;
	}
}

void fp_fmdn_gatt_utp_owner_conn_reg(fp_fmdn_utp_owner_conn_cb const hdlr)
{
	if (!utp_owner_conn_cb) {
		utp_owner_conn_cb = hdlr;
	}
}
#endif

#ifdef CONFIG_FMDN_PRECISION_FINDING
/**
 * @brief Send a BCNA motion status notification to the seeker
 *
 * Builds a BCNA notification frame (opcode + auth + motion status) and
 * delivers it via bt_gatt_notify to the connection that requested motion.
 * In UTP mode with auth bypassed, the auth bytes are left as zero.
 */
static void fp_fmdn_bcna_motion_notify_send(struct bt_conn *conn, uint8_t nego_version,
					    uint8_t seq_num, ranging_de_motion_status_t st)
{
	if (!fmdn_attr) {
		LOG_WRN("BCNA motion notify: no GATT attr");
		return;
	}

	bcna_conn_ctx_t *conn_context = &conn_contexts[bt_conn_index(conn)];
	bcna_write_data_t noti;
	memset(&noti, 0, sizeof(noti));

	noti.header.data_id = BCNA_OP_RANGING_MOTION_NOTIFICATION;
	noti.header.data_len = BCNA_AUTH_KEY_LEN + sizeof(uint8_t) +
			       sizeof(ranging_oob_de_header_t) + sizeof(uint8_t);
	/* Build additional_data per Table 8:
	 *   [0]     sequential number (number of previously sent motion notifications)
	 *   [1..2]  OOB DE header (version | msg_id=0x08)
	 *   [3]     motion status
	 */
	noti.addition_data[0] = seq_num;
	ranging_oob_de_header_t motion_hdr = {
		.version = nego_version,
		.msg_id = RANGING_MSG_ID_MOTION_NOTIFICATION,
	};
	memcpy(&noti.addition_data[1], &motion_hdr, sizeof(motion_hdr));
	noti.addition_data[1 + sizeof(motion_hdr)] = (uint8_t)st;
	uint16_t noti_len = sizeof(noti.header) + noti.header.data_len;

	/* Skip auth in UTP mode (per FMDN UTP precision finding spec) */
	bool skip_auth = ((fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON) &&
			  fp_storage_utp_ignore_ring_auth_get());
	if (!skip_auth) {
		uint8_t auth_seg[GFP_CRYPTO_SHA256_DIG_LEN];
		if (!bcna_auth_seg_gen(conn_context, &noti, auth_seg,
				       FP_FMDN_AUTH_DATA_MOTION_NOTI)) {
			LOG_WRN("BCNA motion notify: auth gen failed");
			return;
		}
		memcpy(noti.auth_key, auth_seg, BCNA_AUTH_KEY_LEN);
	}

	LOG_INF("BCNA motion notify: status=%d conn=%p", st, (void *)conn);
	fp_fmdn_bcna_resp_send(conn, fmdn_attr, (uint8_t *)&noti, noti_len);
}
#endif

void fp_fmdn_gatt_init(struct bt_gatt_attr *attr)
{
	fmdn_attr = attr;

	/* Initialize FMDN clock from NVM for power-loss recovery */
	fp_fmdn_key_clock_init();

	if (fp_storage_eid_key_valid()) {
		fp_fmdn_apply_provisioned_state();
	}
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	if (utp_mode_cb) {
		utp_mode_cb(fp_storage_utp_mode_get());
	}
#endif
#ifdef CONFIG_FMDN_PRECISION_FINDING
	fp_fhpf_gatt_motion_notify_fn_reg(fp_fmdn_bcna_motion_notify_send);
#endif
}

void fp_fmdn_gatt_deinit(void)
{
	/* Stop periodic clock saving */
	fp_fmdn_key_clock_periodic_save_stop();

	fp_fmdn_key_clear_eid();
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	memset(fmdn_dult_id, 0, FP_FMDN_DULT_ID_LEN);
	if (update_id_cb) {
		update_id_cb(fmdn_dult_id, FP_FMDN_DULT_ID_LEN);
	}
#endif
#ifdef CONFIG_FMDN_PRECISION_FINDING
	fp_fhpf_gatt_motion_notify_fn_reg(NULL);
#endif
	fmdn_attr = NULL;
}

void fp_fmdn_button_notify(void)
{
	if (cur_ring_state == FP_FMDN_RING_STATE_STARTED) {
		k_work_cancel_delayable(&fp_fmdn_ring_timer_id);
		fp_fmdn_ring_state_stop(FP_FMDN_RING_STATE_STOPED_BUTTON_PRESS);
	}
}

#ifdef CONFIG_FMDN_PRECISION_FINDING
void fp_fmdn_ranging_handler_register(fp_fmdn_ranging_handler_t const *handler)
{
	// Forward to FHPF module
	fp_fhpf_gatt_ranging_handler_register(handler);
}
#endif
