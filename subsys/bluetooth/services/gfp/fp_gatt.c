/**
 *******************************************************************************
 *
 * @file fp_gatt.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Gatt Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <zephyr/sys/base64.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gatt.h>
#include "fp_adv.h"
#include "fp_common.h"
#include "fp_conn.h"
#include "fp_gatt.h"
#include "fp_mode.h"
#include "fp_storage.h"
#include "gfp_crypto.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn_adv.h"
#include "fp_fmdn_gatt.h"
#endif

LOG_MODULE_DECLARE(fp, CONFIG_ATM_FP_LOG_LEVEL);

// Fast Pair data id type.
enum fp_msg_type {
	// Key-based Pairing Request
	FP_MSG_KEY_BASED_PAIRING_REQ = 0x00,
	// Key-based Pairing Response.
	FP_MSG_KEY_BASED_PAIRING_RSP = 0x01,
	// Seeker's Passkey.
	FP_MSG_SEEKERS_PASSKEY = 0x02,
	// Provider's Passkey.
	FP_MSG_PROVIDERS_PASSKEY = 0x03,
	// Action request.
	FP_MSG_ACTION_REQ = 0x10,
};

#define KBP_ACTION_REQ_ADDITIONAL_DATA_MAX_LEN 5

typedef struct {
	// Anti-Spoofing AES key
	uint8_t as_aes[FP_AS_AES_KEY_LEN];
	// Passkey (Seeker)
	uint32_t psk_s;
	// Passkey (Provider)
	uint32_t psk_p;
	// Account key available for writing
	bool en_acnt_write;
} fp_key_store_t;

static fp_key_store_t gfp_key;

/// Key-based Pairing request
typedef struct fp_pair_req_s {
	/// Seeker’s address
	uint8_t seeker_addr[BT_ADDR_SIZE];
	/// Random value (salt)
	uint8_t salt[2];
} fp_pair_req_t;

/// Action request
typedef struct fp_action_req_s {
	/// Message group
	uint8_t group;
	/// Message code
	uint8_t code;
	/// Depends on Flags
	uint8_t depend;
	/// Additional data
	uint8_t addition[KBP_ACTION_REQ_ADDITIONAL_DATA_MAX_LEN];
} fp_action_req_t;

/// Key-based Pairing raw request
typedef struct fp_kbp_raw_req_s {
	/// Message type
	uint8_t type;
	/// Flags
	uint8_t flags;
	/// Provider’s address
	uint8_t prov_addr[BT_ADDR_SIZE];
	union {
		/// Key-based Pairing request
		fp_pair_req_t pr;
		/// Action request
		fp_action_req_t ar;
	};
} fp_kbp_raw_req_t;

static uint8_t fp_as_key[FP_AS_BASE64_KEY_LEN];
static gfp_crypto_ecp_curve_intf_t ecp_256r1_intf;

static bool fp_kbp_process(uint8_t const *public_key, const uint8_t *enc_req,
			   fp_kbp_raw_req_t *parsed_req)
{
	int priv_key_size = ecp_256r1_intf.curve_private_key_size();
	uint8_t aes_1b[priv_key_size];
	uint8_t sha_aes_1b[priv_key_size];

	if (!ecp_256r1_intf.shared_secret(public_key, fp_as_key, aes_1b)) {
		LOG_WRN("Key Base Pair: shared_secret secp256r1 failed");
		return false;
	}
	if (!gfp_crypto_sha256(aes_1b, priv_key_size, sha_aes_1b)) {
		LOG_WRN("Key Base Pair: gfp_crypto_sha256 failed");
		return false;
	}
	memcpy(gfp_key.as_aes, sha_aes_1b, FP_AS_AES_KEY_LEN);
	memset(aes_1b, 0x00, priv_key_size);
	if (!gfp_crypto_aes_ecb_dec(aes_1b, enc_req, priv_key_size, gfp_key.as_aes,
				    GFP_CRYPTO_AES_ECB_128)) {
		LOG_WRN("Key Base Pair: tc_aes_decrypt fail");
		return false;
	}
	memcpy(parsed_req, aes_1b, sizeof(fp_kbp_raw_req_t));
	return true;
}

static int fp_kbp_req_handler(struct bt_conn *conn, struct net_buf_simple *rsp,
			      fp_kbp_raw_req_t const *req, uint8_t *do_addi_act)
{
	int err = 0;
	LOG_DBG("+ Message Type=%#x", req->type);
	LOG_DBG("+ Flags=%#x", req->flags);
	uint8_t const *tmp = req->prov_addr;
	LOG_DBG("+ Prov. addr=%02x:%02x:%02x:%02x:%02x:%02x", tmp[0], tmp[1], tmp[2], tmp[3],
		tmp[4], tmp[5]);
	if (req->type == FP_MSG_KEY_BASED_PAIRING_REQ) {
		bool pairing_req = false;
		tmp = req->pr.seeker_addr;
		LOG_DBG("+ Seek. addr=%02x:%02x:%02x:%02x:%02x:%02x", tmp[0], tmp[1], tmp[2],
			tmp[3], tmp[4], tmp[5]);
#define REQ_INITIALING_BONDING             0b00000001
#define REQ_ADDTION_NAME_NOTIFY            0b00000010
#define REQ_ETROACTIVELY_WRITE_ACCOUNT_KEY 0b00000100
		if (req->flags & REQ_INITIALING_BONDING) {
			LOG_DBG("Subsequece paring not support");
			pairing_req = false;
		}
		if (req->flags & REQ_ADDTION_NAME_NOTIFY) {
			LOG_DBG("Addition Name Notify not support");
			*do_addi_act = false;
		}
		if (req->flags & REQ_ETROACTIVELY_WRITE_ACCOUNT_KEY) {
			LOG_DBG("Retroactively write account key unsupported");
		}

	} else if (req->type == FP_MSG_ACTION_REQ) {
		LOG_DBG("+ Message group=%#x", req->ar.group);
		LOG_DBG("+ Message code=%#x", req->ar.code);
		LOG_DBG("+ depends=%#x", req->ar.depend);
		tmp = req->ar.addition;
		LOG_DBG("+ addition=%02x:%02x:%02x:%02x:%02x:", tmp[0], tmp[1], tmp[2], tmp[3],
			tmp[4]);
	}
#define KBP_RAW_RESP_LEN  16
#define TYPE_PAIR_RESP    0x01
#define TYPE_PAIR_RESP_LE 0x02
#define FLAGS_LE_ONLY     0x80
#define FLAGS_LE_BOND     0x40
	struct bt_conn_info conn_info;
	err = bt_conn_get_info(conn, &conn_info);
	if (err) {
		LOG_ERR("Failed to get local conn info %d", err);
		return err;
	}
	net_buf_simple_add_u8(rsp, FP_MSG_KEY_BASED_PAIRING_RSP);
	net_buf_simple_add_mem(rsp, &conn_info.le.local->a.val, BT_ADDR_SIZE);
	uint8_t *local_addr = net_buf_simple_add_mem(rsp, &conn_info.le.local->a.val, BT_ADDR_SIZE);
	sys_mem_swap(local_addr, BT_ADDR_SIZE);
	return 0;
}

static void fp_drop_keys(void)
{
	memset(gfp_key.as_aes, 0, FP_AS_AES_KEY_LEN);
	gfp_key.psk_s = 0;
	gfp_key.en_acnt_write = false;
}

static int fp_gatt_rsp_notify(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			      struct net_buf_simple *rsp)
{
	uint8_t rsp_enc[GFP_CRYPTO_AES_BLOCK_LEN_BYTES];
	uint8_t *salt;
	size_t salt_len;
	int err = 0;

	if (net_buf_simple_max_len(rsp) != GFP_CRYPTO_AES_BLOCK_LEN_BYTES) {
		LOG_ERR("Unsupported response size %zu", net_buf_simple_max_len(rsp));
		return -ENOTSUP;
	}

	salt_len = net_buf_simple_tailroom(rsp);
	salt = net_buf_simple_add(rsp, salt_len);
	/* Fill remaining part of the response with random salt. */
	err = sys_csrand_get(salt, salt_len);
	if (err) {
		LOG_WRN("Failed to generate salt for GATT response: err=%d", err);
		return err;
	}
	bool ret = gfp_crypto_aes_ecb_enc(
		rsp_enc, net_buf_simple_pull_mem(rsp, GFP_CRYPTO_AES_BLOCK_LEN_BYTES),
		GFP_CRYPTO_AES_BLOCK_LEN_BYTES, gfp_key.as_aes, GFP_CRYPTO_AES_ECB_128);
	if (!ret) {
		LOG_WRN("GATT response encrypt failed");
		return -EINVAL;
	}
	err = bt_gatt_notify(conn, attr, rsp_enc, sizeof(rsp_enc));
	if (err) {
		LOG_ERR("GATT response notify failed: err=%d", err);
	}
	return err;
}

static ssize_t fp_read_model_id(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				uint16_t len, uint16_t offset)
{
	ssize_t res;

	if (!fp_mode_is_pairing()) {
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		LOG_INF("Model ID read: res=%zd conn=%p, "
			"Return error because Fast Pair is in pairing mode",
			res, (void *)conn);
		return res;
	}
	static uint8_t const model_id[] = {FP_APP_MODEL_ID};
	res = bt_gatt_attr_read(conn, attr, buf, len, offset, model_id, sizeof(model_id));

	LOG_DBG("Model ID read: res=%zd conn=%p", res, (void *)conn);

	return res;
}

enum additional_action {
	ADDITIONAL_ACTION_NOTIFY_PN_BIT_POS,
	ADDITIONAL_ACTION_COUNT,
};

static ssize_t fp_kbp_write(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf,
			    uint16_t len, uint16_t offset, uint8_t flags)
{
	ssize_t res = len;

	if (!fp_mode_is_pairing()) {
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		LOG_INF("Key-based Pairing write: res=%zd conn=%p, "
			"Return error because Fast Pair is in pairing mode",
			res, (void *)conn);
		goto finish;
	}
	if (offset != 0) {
		LOG_WRN("Invalid offset: off=%" PRIu16 " (Key-based Pairing)", offset);
		res = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
		goto finish;
	}
	int public_key_len = ecp_256r1_intf.curve_public_key_size();
	if ((len != (GFP_CRYPTO_AES_BLOCK_LEN_BYTES + public_key_len)) &&
	    (len != GFP_CRYPTO_AES_BLOCK_LEN_BYTES)) {
		LOG_WRN("Invalid length: len=%" PRIu16 " (Key-based Pairing)", len);
		res = BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		goto finish;
	}
	fp_mode_update(FP_MODE_PAIRING_PROCESSING);
	struct net_buf_simple gatt_write;
	net_buf_simple_init_with_data(&gatt_write, (void *)buf, len);
	uint8_t *enc_req = net_buf_simple_pull_mem(&gatt_write, GFP_CRYPTO_AES_BLOCK_LEN_BYTES);
	uint8_t *public_key = NULL;
	if (net_buf_simple_max_len(&gatt_write) == public_key_len) {
		public_key = net_buf_simple_pull_mem(&gatt_write, public_key_len);
	}

	fp_kbp_raw_req_t parsed_req;
	if (!fp_kbp_process(public_key, enc_req, &parsed_req)) {
		LOG_WRN("Generating keys failed: (Key-based Pairing)");
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		goto finish;
	}

	NET_BUF_SIMPLE_DEFINE(rsp, GFP_CRYPTO_AES_BLOCK_LEN_BYTES);
	uint8_t do_addi_act;
	int err = fp_kbp_req_handler(conn, &rsp, &parsed_req, &do_addi_act);
	if (err) {
		LOG_WRN("Handling request failed: err=%d (Key-based Pairing)", err);
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		goto finish;
	}

	err = fp_gatt_rsp_notify(conn, attr, &rsp);
	if (err) {
		LOG_WRN("Failed to send response: err=%d (Key-based Pairing)", err);
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		goto finish;
	}

	if (do_addi_act) {
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		goto finish;
	}
finish:
	if (res < 0) {
		fp_drop_keys();
	}
	LOG_DBG("Key-based Pairing write done: res=%zd conn=%p", res, (void *)conn);
	return res;
}

static ssize_t fp_write_account_key(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				    const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	LOG_DBG("Account key write: conn=%p", (void *)conn);

	uint8_t account_key[FP_ACCOUNT_KEY_LEN];
	ssize_t res = len;
	if (!fp_mode_is_pairing()) {
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		LOG_INF("Account key write: res=%zd conn=%p, "
			"Return error because Fast Pair is in pairing mode",
			res, (void *)conn);
		return res;
	}
	if (offset != 0) {
		LOG_WRN("Invalid offset: off=%" PRIu16 " (Account Key)", offset);
		res = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
		goto finish;
	}

	if (len != FP_ACCOUNT_KEY_LEN) {
		LOG_WRN("Invalid length: len=%" PRIu16 " (Account Key)", len);
		res = BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		goto finish;
	}

	if (!gfp_crypto_aes_ecb_dec(account_key, buf, FP_ACCOUNT_KEY_LEN, gfp_key.as_aes,
				    GFP_CRYPTO_AES_ECB_128)) {
		LOG_WRN("Decrypt failed (Account Key)");
		res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		goto finish;
	}
	fp_storage_account_key_save(account_key);
	fp_mode_update(FP_MODE_PAIRED);
finish:
	if (res < 0) {
		fp_drop_keys();
	}
	LOG_DBG("Account Key write done: res=%zd conn=%p", res, (void *)conn);
	return res;
}

/// Fast Pair Service UUID value
#define FP_UUID_FPS_VAL (0xFE2C)
/// Fast Pair Service UUID
#define FP_UUID_FPS     BT_UUID_DECLARE_16(FP_UUID_FPS_VAL)

/// Fast Pair Model ID Characteristic UUID value
#define FP_UUID_MODEL_ID_VAL BT_UUID_128_ENCODE(0xFE2C1233, 0x8366, 0x4814, 0x8EB0, 0x01DE32100BEA)
/// Fast Pair Model ID Characteristic UUID
#define FP_UUID_MODEL_ID     BT_UUID_DECLARE_128(FP_UUID_MODEL_ID_VAL)

/// Fast Pair Key-based Pairing Characteristic UUID value
#define FP_UUID_KEY_BASED_PAIRING_VAL                                                              \
	BT_UUID_128_ENCODE(0xFE2C1234, 0x8366, 0x4814, 0x8EB0, 0x01DE32100BEA)
/// Fast Pair Key-based Pairing Characteristic UUID
#define FP_UUID_KEY_BASED_PAIRING BT_UUID_DECLARE_128(FP_UUID_KEY_BASED_PAIRING_VAL)

/// Fast Pair Account Key Characteristic UUID value
#define FP_UUID_ACCOUNT_KEY_VAL                                                                    \
	BT_UUID_128_ENCODE(0xFE2C1236, 0x8366, 0x4814, 0x8EB0, 0x01DE32100BEA)
/// Fast Pair Account Key Characteristic UUID
#define FP_UUID_ACCOUNT_KEY BT_UUID_DECLARE_128(FP_UUID_ACCOUNT_KEY_VAL)

/// Fast Pair Additional Data Characteristic UUID value
#define FP_UUID_ADDITIONAL_DATA_VAL                                                                \
	BT_UUID_128_ENCODE(0xFE2C1237, 0x8366, 0x4814, 0x8EB0, 0x01DE32100BEA)
/// Fast Pair Additional Data Characteristic UUID
#define FP_UUID_ADDITIONAL_DATA BT_UUID_DECLARE_128(FP_UUID_ADDITIONAL_DATA_VAL)

BT_GATT_SERVICE_DEFINE(fast_pair_svc, BT_GATT_PRIMARY_SERVICE(FP_UUID_FPS),
		       BT_GATT_CHARACTERISTIC(FP_UUID_MODEL_ID, BT_GATT_CHRC_READ,
					      BT_GATT_PERM_READ, fp_read_model_id, NULL, NULL),
		       BT_GATT_CHARACTERISTIC(FP_UUID_KEY_BASED_PAIRING,
					      BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
					      BT_GATT_PERM_WRITE, NULL, fp_kbp_write, NULL),
		       BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
		       BT_GATT_CHARACTERISTIC(FP_UUID_ACCOUNT_KEY, BT_GATT_CHRC_WRITE,
					      BT_GATT_PERM_WRITE, NULL, fp_write_account_key, NULL),
#ifdef CONFIG_FAST_PAIR_FMDN
		       FP_FMDN_BEACON_ACTIONS_CHARACTERISTIC,
#endif
);

static void fp_gatt_disconnected(struct bt_conn *conn, uint8_t reason)
{
	if (!fp_conn_validate(conn)) {
		return;
	}
	LOG_DBG("FP Gatt Disconnect");
	fp_adv_recreate();
}

BT_CONN_CB_DEFINE(fp_gatt_conn_callbacks) = {
	.disconnected = fp_gatt_disconnected,
};

static struct bt_gatt_attr *fp_gatt_get_attr(const struct bt_uuid *uuid)
{
	return bt_gatt_find_by_uuid(fast_pair_svc.attrs, fast_pair_svc.attr_count, uuid);
}

void fp_gatt_init(void)
{
	size_t fp_key_len;
	int ret = base64_decode(fp_as_key, FP_AS_BASE64_KEY_LEN, &fp_key_len, FP_APP_AS_KEY,
				strlen(FP_APP_AS_KEY));
	if (ret != 0) {
		__ASSERT(0, "Failed to decode FP_AS_BASE64_KEY");
	}
	gfp_crypto_ecp_curve_intf_secp256r1(&ecp_256r1_intf);
#ifdef CONFIG_FAST_PAIR_FMDN
	fp_fmdn_gatt_init(fp_gatt_get_attr(FP_FMDN_UUID_BEACON_ACTIONS));
#endif
}

void fp_gatt_deinit(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN
	fp_fmdn_gatt_deinit();
#endif
}
