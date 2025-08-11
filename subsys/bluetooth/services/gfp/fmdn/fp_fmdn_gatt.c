/**
 *******************************************************************************
 *
 * @file fp_fmdn_gatt.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Gatt Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <zephyr/bluetooth/bluetooth.h>
#include "app_work_q.h"
#include "atm_utils_c.h"
#include "fp_conn.h"
#include "fp_fmdn_adv.h"
#include "fp_fmdn_gatt.h"
#include "fp_fmdn_internal.h"
#include "fp_fmdn_key.h"
#include "fp_mode.h"
#include "fp_storage.h"
#include "gfp_crypto.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

static fp_fmdn_utp_mode_cb utp_mode_cb;
static fp_fmdn_ring_action_cb ring_action_cb;
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
static fp_fmdn_update_id_cb update_id_cb;
static fp_fmdn_utp_owner_conn_cb utp_owner_conn_cb;
#endif
static bcna_conn_ctx_t conn_contexts[CONFIG_BT_MAX_CONN];

static void fp_fmdn_provision_cleanup(void);
static bool delay_provision_cleanup;
static uint8_t utp_ignore_ring_auth;
static struct bt_gatt_attr *fmdn_attr;

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
	if (data_type == FP_FMDN_AUTH_DATA_RES) {
		/* The first 8 bytes of HMAC-SHA256(account key, protocol major version
		 * number || the last nonce read from the characteristic || data ID ||
		 * data length || additional data || 0x1)
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
	FMDN_MEMCPY_SHIFT(auth_data, &major_ver, sizeof(major_ver), offset);
	FMDN_MEMCPY_SHIFT(auth_data, conn_context->random_nonce, BCNA_RNDM_NONCE_LEN, offset);
	FMDN_MEMCPY_SHIFT(auth_data, &data->header.data_id, sizeof(data->header.data_id), offset);
	FMDN_MEMCPY_SHIFT(auth_data, &data->header.data_len, sizeof(data->header.data_len), offset);
	if (data_type != FP_FMDN_AUTH_DATA_EID_READ_REQ) {
		FMDN_MEMCPY_SHIFT(auth_data, data->addition_data, add_len, offset);
	}
	if (data_type == FP_FMDN_AUTH_DATA_RES) {
		FMDN_MEMCPY_SHIFT(auth_data, &constant_end, sizeof(constant_end), offset);
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
		    (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON) && utp_ignore_ring_auth) {
			LOG_INF("BCNA UTP ignore ring auth");
			return 0;
		}
		return bcna_auth_seg_gen_validate(conn_context, req);
	}
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
static void fp_fmdn_provision_done(uint8_t const *eidk)
{
	uint8_t account_key[FP_ACCOUNT_KEY_LEN];
	fp_storage_cur_account_key_get(account_key);
	fp_storage_eid_key_save(eidk);
	fp_fmdn_key_gen_eid(eidk, true);
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	fp_fmdn_key_gen_dult_id(eidk, fmdn_dult_id);
	if (update_id_cb) {
		update_id_cb(fmdn_dult_id, FP_FMDN_DULT_ID_LEN);
	}
#endif
	fp_mode_update(FP_MODE_PROVISIONED);
	LOG_INF("FMDN provisioned");
}

static void fp_fmdn_provision_cleanup(void)
{
	LOG_INF("FMDN provision cleanup");
	if (fp_mode_is_provisioned()) {
		fp_fmdn_adv_recreate(true, true);
		fp_storage_eid_reset();
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
	uint8_t power = FP_APP_TX_PWR;
	FMDN_MEMCPY_SHIFT(dst_ptr, &power, sizeof(power), offset);

	// The current clock value in seconds (big endian).
	uint32_t clock = fp_fmdn_key_clock_read();
	atm_set_be32(dst_ptr + offset, fp_fmdn_key_clock_read());
	offset += sizeof(clock);
	// The elliptic curve being used for encryption
	uint8_t curve_sel = FP_FMDN_CURVE_SEL;
	FMDN_MEMCPY_SHIFT(dst_ptr, &curve_sel, sizeof(curve_sel), offset);

	uint8_t components = BCNA_RING_COMPONENTS_ALL;
	FMDN_MEMCPY_SHIFT(dst_ptr, &components, sizeof(components), offset);
	uint8_t ring_cap = BCNA_RING_SEL_AVAILABLE;
	FMDN_MEMCPY_SHIFT(dst_ptr, &ring_cap, sizeof(ring_cap), offset);
	// Zero padding for AES encryption
	uint8_t pad[8];
	memset(pad, 0, sizeof(pad));
	FMDN_MEMCPY_SHIFT(dst_ptr, pad, sizeof(pad), offset);
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
	FMDN_MEMCPY_SHIFT(dst_ptr, &status, sizeof(status), offset);
	// to do copy eid
	uint8_t fmdn_eid[FP_FMDN_STATE_EID_LEN];
	uint8_t len = fp_fmdn_key_get_eid(fmdn_eid);
	if (len) {
		FMDN_MEMCPY_SHIFT(dst_ptr, fmdn_eid, len, offset);
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
	FMDN_MEMCPY_SHIFT(auth_data, curr_eidk, FP_FMDN_EID_KEY_LEN, offset);
	FMDN_MEMCPY_SHIFT(auth_data, conn_context->random_nonce, BCNA_RNDM_NONCE_LEN, offset);
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
	FMDN_MEMCPY_SHIFT(addition_data, eid_key, FP_EIK_LEN, offset);
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
static uint16_t cur_ring_to;
static uint32_t ring_start_time_ms;
static bool gatt_ring_en;
typedef struct {
	struct bt_conn *conn;
} ring_noti_info_t;
static ring_noti_info_t *ring_info;

static uint16_t fp_fmdn_bcna_ring_state_resp_handler(bcna_write_data_t *resp, uint16_t *resp_len,
						     uint8_t ring_state, uint16_t ring_to)
{
	uint8_t addition_data[FP_FMDN_EID_KEY_LEN];
	uint8_t *dst_ptr = addition_data;
	size_t add_len = 0;
	FMDN_MEMCPY_SHIFT(dst_ptr, &ring_state, sizeof(ring_state), add_len);
	uint8_t components = BCNA_RING_COMPONENTS_ALL;
	FMDN_MEMCPY_SHIFT(dst_ptr, &components, sizeof(components), add_len);
	uint16_t tmp_ring_to;
	atm_set_be16(&tmp_ring_to, ring_to);
	FMDN_MEMCPY_SHIFT(dst_ptr, &tmp_ring_to, sizeof(tmp_ring_to), add_len);
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
					     cur_ring_to);
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
	cur_ring_to = 0;
	ring_start_time_ms = 0;
	gatt_ring_en = false;
	if (ring_action_cb) {
		ring_action_cb(cur_ring_state == FP_FMDN_RING_STATE_STARTED);
	}
	atm_work_submit_to_app_work_q(&fp_fmdn_gatt_ring_stop_noti);
}

static void fp_fmdn_ring_timeout_handler(struct k_work *work)
{
	LOG_INF("BCNA Ring Timeout");
	fp_fmdn_ring_state_stop(FP_FMDN_RING_STATE_STOPED_TIMEOUT);
}
K_WORK_DELAYABLE_DEFINE(fp_fmdn_ring_timer_id, fp_fmdn_ring_timeout_handler);

static void fp_fmnd_gatt_ring_update(bool en, uint16_t to)
{
	if (ring_action_cb) {
		ring_action_cb(en);
	}
	if (en && to) {
		uint16_t to_s = to / 10;
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
	uint8_t components = BCNA_RING_COMPONENTS_ALL;
	FMDN_MEMCPY_SHIFT(dst_ptr, &components, sizeof(components), offset);
	uint16_t ring_to = 0x0;
	if (cur_ring_to && ring_start_time_ms) {
		uint32_t ring_diff = k_uptime_get() - ring_start_time_ms;
#define MSEC_PER_DEC_SEC (MSEC_PER_SEC / 10) // 100 ms per decisecond
		ring_diff /= MSEC_PER_DEC_SEC;
		ring_to = (cur_ring_to > ring_diff) ? (cur_ring_to - ring_diff) : 0;
		atm_set_be16(&ring_to, ring_to);
	}
	FMDN_MEMCPY_SHIFT(dst_ptr, &ring_to, sizeof(ring_to), offset);
	resp->header.data_len = BCNA_AUTH_KEY_LEN + offset;
	memcpy(resp->addition_data, addition_data, offset);
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

static size_t fp_fmdn_bcna_ring_state_change_handle(bcna_write_data_t *resp, uint16_t *resp_len)
{
	uint8_t ring_op;
	uint8_t ring_vol;
	uint8_t offset = 0;
	memcpy(&ring_op, resp->addition_data + offset, sizeof(ring_op));
	offset += sizeof(ring_op);
	cur_ring_to = atm_get_be16(resp->addition_data + offset);
	offset += sizeof(cur_ring_to);
	memcpy(&ring_vol, resp->addition_data + offset, sizeof(ring_vol));
	offset += sizeof(ring_vol);
#define FMDN_RING_OP_RING_RIGHT 0x01
#define FMDN_RING_OP_RING_LEFT  0x02
#define FMDN_RING_OP_RING_CASE  0x04
#define FMDN_RING_OP_RING_ALL   0xFF
#define FMDN_RING_OP_RING_STOP  0x00
	gatt_ring_en = (ring_op != FMDN_RING_OP_RING_STOP);
	cur_ring_state = (ring_op == FMDN_RING_OP_RING_STOP)
				 ? FP_FMDN_RING_STATE_STOPED_GATT_REQUEST
				 : FP_FMDN_RING_STATE_STARTED;
	fp_fmnd_gatt_ring_update(cur_ring_state == FP_FMDN_RING_STATE_STARTED, cur_ring_to);
	if (cur_ring_state == FP_FMDN_RING_STATE_STARTED) {
		ring_start_time_ms = k_uptime_get();
	} else {
		ring_start_time_ms = 0;
	}
	return fp_fmdn_bcna_ring_state_resp_handler(resp, resp_len, cur_ring_state, cur_ring_to);
}

static size_t fp_fmdn_bcna_set_utp_handle(bcna_write_data_t *resp, uint16_t *resp_len,
					  fp_fmdn_utp_mode_t utp_mode)
{
	if ((utp_mode == FP_FMDN_UTP_MODE_ON) && (resp->header.data_len > BCNA_AUTH_KEY_LEN)) {
		utp_ignore_ring_auth = resp->addition_data[0];
	}
	fp_storage_utp_mode_save(utp_mode);
	fp_fmdn_adv_recreate(true, false);
	if (utp_mode_cb) {
		utp_mode_cb(utp_mode);
	}
	resp->header.data_len = BCNA_AUTH_KEY_LEN;
	// data_id and data_len
	*resp_len = resp->header.data_len + 2;
	return 0;
}

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
	if (fp_mode_is_provisioned()) {
		fp_fmdn_adv_recreate(false, false);
	}
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	if (utp_owner_conn_cb) {
		utp_owner_conn_cb(true);
	}
#endif
}
K_WORK_DEFINE(fp_fmdn_gatt_conn_action, fp_fmdn_gatt_conn_invoke_action);

static void fp_fmdn_gatt_disconn_invoke_action(struct k_work *work)
{
	if (delay_provision_cleanup) {
		delay_provision_cleanup = false;
		fp_storge_account_key_reset();
		fp_mode_update(FP_MODE_NONE);
	} else {
		fp_fmdn_adv_recreate(false, false);
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
	atm_work_submit_to_app_work_q(&fp_fmdn_gatt_disconn_action);
}

BT_CONN_CB_DEFINE(fp_fmdn_gatt_conn_callbacks) = {
	.connected = fp_fmdn_gatt_connected,
	.disconnected = fp_fmdn_gatt_disconnected,
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

void fp_fmdn_gatt_init(struct bt_gatt_attr *attr)
{
	fmdn_attr = attr;
	if (fp_storage_eid_key_valid()) {
		uint8_t eidk[FP_FMDN_EID_KEY_LEN];
		fp_storage_eid_key_get(eidk);
		fp_fmdn_key_gen_eid(eidk, true);
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
		fp_fmdn_key_gen_dult_id(eidk, fmdn_dult_id);
		if (update_id_cb) {
			update_id_cb(fmdn_dult_id, FP_FMDN_DULT_ID_LEN);
		}
#endif
	}
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	if (utp_mode_cb) {
		utp_mode_cb(fp_storage_utp_mode_get());
	}
#endif
}

void fp_fmdn_gatt_deinit(void)
{
	fp_fmdn_key_clear_eid();
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
	memset(fmdn_dult_id, 0, FP_FMDN_DULT_ID_LEN);
	if (update_id_cb) {
		update_id_cb(fmdn_dult_id, FP_FMDN_DULT_ID_LEN);
	}
#endif
	fmdn_attr = NULL;
}

void fp_fmdn_button_notify(void)
{
	if (cur_ring_state == FP_FMDN_RING_STATE_STARTED) {
		fp_fmdn_ring_state_stop(FP_FMDN_RING_STATE_STOPED_BUTTON_PRESS);
	}
}