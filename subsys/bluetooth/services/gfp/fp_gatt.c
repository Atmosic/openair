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
#include "fp_auth.h"
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
#ifdef CONFIG_ATM_SEC_JRNL_PRESENT
#include "sec_jrnl.h"
#endif

LOG_MODULE_DECLARE(fp, CONFIG_ATM_FP_LOG_LEVEL);

/**
 * @brief Fast Pair error types for consistent error handling
 */
typedef enum {
	FP_ERR_INVALID_OFFSET,    /* Non-zero offset not supported */
	FP_ERR_INVALID_LENGTH,    /* Invalid data length */
	FP_ERR_CRYPTO_FAILED,     /* Cryptographic operation failed */
	FP_ERR_AUTH_FAILED,       /* Authentication/verification failed */
	FP_ERR_STORAGE_FAILED,    /* Storage operation failed */
	FP_ERR_INVALID_STATE,     /* Invalid Fast Pair state */
	FP_ERR_INVALID_VALUE,     /* Invalid parameter value */
	FP_ERR_INSUFFICIENT_DATA, /* Not enough data provided */
} fp_error_type_t;

static const struct {
	fp_error_type_t type;
	uint8_t att_err;
} fp_error_map[] = {
	{FP_ERR_INVALID_OFFSET, BT_ATT_ERR_INVALID_OFFSET},
	{FP_ERR_INVALID_LENGTH, BT_ATT_ERR_INVALID_ATTRIBUTE_LEN},
	{FP_ERR_CRYPTO_FAILED, BT_ATT_ERR_UNLIKELY},
	{FP_ERR_AUTH_FAILED, BT_ATT_ERR_INSUFFICIENT_ENCRYPTION},
	{FP_ERR_STORAGE_FAILED, BT_ATT_ERR_UNLIKELY},
	{FP_ERR_INVALID_STATE, BT_ATT_ERR_UNLIKELY},
	{FP_ERR_INVALID_VALUE, BT_ATT_ERR_UNLIKELY},
	{FP_ERR_INSUFFICIENT_DATA, BT_ATT_ERR_INVALID_ATTRIBUTE_LEN},
};

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
static const struct bt_gatt_attr *additional_data_attr;

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
static bool fp_as_key_loaded;
static gfp_crypto_ecp_curve_intf_t ecp_256r1_intf;

/**
 * @brief Fast Pair error mapping
 * @param error_type Fast Pair specific error type
 * @return Appropriate BT_GATT_ERR code
 */
static ssize_t fp_map_error(fp_error_type_t error_type)
{
	for (int i = 0; i < ARRAY_SIZE(fp_error_map); i++) {
		if (fp_error_map[i].type == error_type) {
			return BT_GATT_ERR(fp_error_map[i].att_err);
		}
	}
	return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
}

/**
 * @brief Handle Action Request (Type 0x10)
 *
 * According to Fast Pair specification Table 1.2.2, this handles:
 * - Device actions
 * - Additional data requests
 * - Message stream operations
 *
 * @param conn BLE connection
 * @param rsp Response buffer to fill
 * @param req Parsed KBP request
 * @param do_addi_act Output flag for additional actions needed
 * @return 0 on success, negative error code on failure
 */
static int fp_handle_action_request(struct bt_conn *conn, struct net_buf_simple *rsp,
				    fp_kbp_raw_req_t const *req, uint8_t *do_addi_act)
{
	LOG_INF("FP KBP: Action Req G=0x%02x C=0x%02x D=0x%02x", req->ar.group, req->ar.code,
		req->ar.depend);

// Action Request flags (Table 1.2.2)
#define FP_ACTION_FLAG_DEVICE_ACTION   0x01 // Bit 0: Device Action
#define FP_ACTION_FLAG_ADDITIONAL_DATA 0x02 // Bit 1: Additional Data follows
	// Bits 2-7: reserved for future use

	if (req->flags & FP_ACTION_FLAG_DEVICE_ACTION) {
		LOG_INF("FP KBP: Device Action req");
		// Handle device-specific actions based on group and code
		// This would typically involve device-specific functionality
		// For now, we'll just log the request
	}

	if (req->flags & FP_ACTION_FLAG_ADDITIONAL_DATA) {
		LOG_INF("FP KBP: Additional Data req");
		*do_addi_act = true; // Signal that additional data characteristic will be used
	}

	// For Action Requests, typically no immediate response is generated
	// The response depends on the specific action being requested
	// For now, return success to indicate the request was processed

	LOG_INF("FP KBP: Action Req processed");
	return 0;
}

/**
 * @brief Handle Key-based Pairing Request (Type 0x00)
 *
 * According to Fast Pair specification Table 1.2.1, this handles:
 * - Provider address validation
 * - Flag processing (bonding, name notification, retroactive account key)
 * - Response generation with Provider's BR/EDR address
 *
 * @param conn BLE connection
 * @param rsp Response buffer to fill
 * @param req Parsed KBP request
 * @param do_addi_act Output flag for additional actions needed
 * @return 0 on success, negative error code on failure
 */
static int fp_handle_key_based_pairing_request(struct bt_conn *conn, struct net_buf_simple *rsp,
					       fp_kbp_raw_req_t const *req, uint8_t *do_addi_act)
{
	int err = 0;

	const uint8_t *seeker_addr = req->pr.seeker_addr;
	LOG_DBG("FP KBP: Seeker %02x:%02x:%02x:%02x:%02x:%02x", seeker_addr[0], seeker_addr[1],
		seeker_addr[2], seeker_addr[3], seeker_addr[4], seeker_addr[5]);

// Fast Pair Key-based Pairing Request flags (Table 1.2.1)
// Bit numbering: Bit 0 = LSB (rightmost bit)
#define FP_FLAG_DEPRECATED           0x01 // Bit 0: deprecated, ignored by Seeker
#define FP_FLAG_INITIATE_BONDING     0x02 // Bit 1: Provider shall initiate bonding
#define FP_FLAG_NOTIFY_EXISTING_NAME 0x04 // Bit 2: Provider shall notify existing name
#define FP_FLAG_RETROACTIVE_ACCT_KEY 0x08 // Bit 3: Retroactively writing account key
	// Bits 4-7: reserved for future use

	// Process flags according to Fast Pair specification
	if (req->flags & FP_FLAG_INITIATE_BONDING) {
		LOG_INF("FP KBP: Bonding");
		err = bt_conn_set_security(conn, BT_SECURITY_L2);
		if (err) {
			LOG_WRN("FP KBP: Bonding failed: %d", err);
		}
	}

	if (req->flags & FP_FLAG_NOTIFY_EXISTING_NAME) {
		LOG_INF("FP KBP: Name notify req");
		*do_addi_act = true;
	}

	if (req->flags & FP_FLAG_RETROACTIVE_ACCT_KEY) {
		LOG_INF("FP KBP: Retroactive key ignored");
	}

	// Enable account key writing after successful KBP
	gfp_key.en_acnt_write = true;
	LOG_DBG("FP KBP: Account key enabled");

	// Generate Key-based Pairing Response (Table 1.3)
	// Response format: [Message Type][Provider BR/EDR Address][Random Salt]

	// Get connection info for Provider's address
	struct bt_conn_info conn_info;
	err = bt_conn_get_info(conn, &conn_info);
	if (err) {
		LOG_ERR("FP KBP: Get conn info failed: %d", err);
		return err;
	}

	// Build response according to Table 1.3
	net_buf_simple_add_u8(rsp, FP_MSG_KEY_BASED_PAIRING_RSP); // Message Type = 0x01

	// Add Provider's BR/EDR address (6 bytes)
	// For BLE-only devices, use the BLE address as BR/EDR address
	uint8_t *provider_addr = net_buf_simple_add(rsp, BT_ADDR_SIZE);
	memcpy(provider_addr, &conn_info.le.local->a.val, BT_ADDR_SIZE);

	// Swap byte order for BR/EDR format (big-endian)
	sys_mem_swap(provider_addr, BT_ADDR_SIZE);

	// Add random salt (9 bytes) to fill remaining space in 16-byte response
	uint8_t *salt = net_buf_simple_add(rsp, 9);
	err = sys_csrand_get(salt, 9);
	if (err) {
		LOG_ERR("FP KBP: Salt gen failed: %d", err);
		return err;
	}

	LOG_DBG("FP KBP: Response generated");
	// Set IO Capability to DisplayYesNo for Fast Pair pairing
	return fp_auth_set_pairing(conn);
}
/**
 * @brief Notify device name via Additional Data characteristic
 *
 * According to Fast Pair specification Table 3.1 and 3.2, this sends
 * the device name through the Additional Data characteristic using
 * AES-CTR encryption and HMAC-SHA256 authentication.
 *
 * @param conn BLE connection
 * @return 0 on success, negative error code on failure
 */
static int fp_notify_device_name(struct bt_conn *conn)
{
	const char *device_name = fp_storage_get_effective_name();
	if (!device_name) {
		LOG_ERR("FP: Get device name failed");
		return -ENODATA;
	}

	size_t name_len = strlen(device_name);
	if (!name_len) {
		LOG_INF("FP: Empty name, skip notify");
		return 0;
	}

	LOG_INF("FP: Notify name: '%s'", device_name);

	// According to Fast Pair spec Table 3.1, Additional Data packet format:
	// [HMAC-SHA256 (8 bytes)][Nonce (8 bytes)][Encrypted Data (variable)]
#define FP_ADDITIONAL_DATA_NOTI_MAX_LEN (8 + 8 + FP_PERSONALIZED_NAME_MAX_LEN)
	uint8_t work_buffer[FP_ADDITIONAL_DATA_NOTI_MAX_LEN]; // Single buffer for all operations
	size_t notification_len = 0;

	// Generate 8-byte nonce
	uint8_t nonce[8];
	int err = sys_csrand_get(nonce, sizeof(nonce));
	if (err) {
		LOG_ERR("FP: Nonce gen failed: %d", err);
		return err;
	}

	// According to Fast Pair spec Table 3.2, for personalized name (Data ID 0x01):
	// Raw data format: [Data ID 0x01][UTF-8 name string]

	// Use work_buffer for raw data (reuse for encrypted data later)
	uint8_t *raw_data = work_buffer;
	size_t raw_data_len = 0;

	// Add Data ID for personalized name (0x01)
	raw_data[raw_data_len++] = 0x01;

	// Add device name (UTF-8 string) with explicit size validation
	size_t available_space = sizeof(raw_data) - raw_data_len;
	size_t copy_len = MIN(name_len, available_space);

	if (copy_len < name_len) {
		LOG_WRN("FP: Name truncated %zu->%zu", name_len, copy_len);
	}

	if (!copy_len) {
		LOG_ERR("FP: No space for name");
		return -ENOBUFS;
	}

	memcpy(raw_data + raw_data_len, device_name, copy_len);
	raw_data_len += copy_len;

	// Implement proper AES-CTR encryption and HMAC-SHA256 authentication
	// according to Fast Pair specification Table 3.1

	// Encrypt raw data using AES-CTR (reuse work_buffer for encrypted data)
	uint8_t *encrypted_data = work_buffer; // Reuse same buffer
	gfp_crypto_aes_ctr_ctx_t aes_ctx = {
		.pt = raw_data,
		.pt_len = raw_data_len,
		.secret_key = gfp_key.as_aes, // Use the shared secret from KBP
		.nonce = nonce};

	if (!gfp_crypto_aes_ctr(encrypted_data, raw_data_len, &aes_ctx)) {
		LOG_ERR("FP: AES encrypt failed");
		return -ENOEXEC;
	}

	// Calculate HMAC-SHA256 for authentication
	gfp_crypto_ctx_t hmac_ctx = {.pt = encrypted_data,
				     .pt_len = raw_data_len,
				     .secret_key = gfp_key.as_aes,
				     .secret_key_len = FP_AS_AES_KEY_LEN,
				     .nonce = nonce};

	uint8_t hmac_full[GFP_CRYPTO_SHA256_DIG_LEN];
	if (!gfp_crypto_gfps_hmac_sha256(hmac_full, sizeof(hmac_full), &hmac_ctx)) {
		LOG_ERR("FP: HMAC failed");
		return -ENOEXEC;
	}

	// Build notification packet according to Table 3.1:
	// [HMAC-SHA256 first 8 bytes][Nonce 8 bytes][Encrypted Data]
	// Note: encrypted_data is already in work_buffer, so we need to reorganize

	// Validate notification buffer has enough space
	if (notification_len + raw_data_len > sizeof(work_buffer)) {
		LOG_ERR("FP: Notify data too large: %zu", notification_len + raw_data_len);
		return -ENOMEM;
	}

	// Move encrypted data to make room for HMAC and nonce at the beginning
	memmove(work_buffer + 16, encrypted_data, raw_data_len);

	// Add first 8 bytes of HMAC-SHA256
	memcpy(work_buffer, hmac_full, 8);
	notification_len += 8;

	// Add nonce (8 bytes)
	memcpy(work_buffer + notification_len, nonce, 8);
	notification_len += 8;

	// Encrypted data is already in place at work_buffer + 16
	notification_len += raw_data_len;

	// Send notification via Additional Data characteristic
	if (!additional_data_attr) {
		LOG_ERR("FP: Additional Data attr not init");
		return -ENODEV;
	}

	err = bt_gatt_notify(conn, additional_data_attr, work_buffer, notification_len);
	if (err) {
		LOG_ERR("FP: Notify failed: %d", err);
		return err;
	}

	LOG_INF("FP: Name notify sent (len=%zu)", notification_len);
	return 0;
}

static bool fp_kbp_process(uint8_t const *public_key, const uint8_t *enc_req,
			   fp_kbp_raw_req_t *parsed_req)
{
	int priv_key_size = ecp_256r1_intf.curve_private_key_size();
	uint8_t aes_1b[priv_key_size];
	uint8_t sha_aes_1b[priv_key_size];

	if (!ecp_256r1_intf.shared_secret(public_key, fp_as_key, aes_1b)) {
		LOG_WRN("KBP: shared_secret failed");
		return false;
	}
	if (!gfp_crypto_sha256(aes_1b, priv_key_size, sha_aes_1b)) {
		LOG_WRN("KBP: SHA256 failed");
		return false;
	}
	memcpy(gfp_key.as_aes, sha_aes_1b, FP_AS_AES_KEY_LEN);
	memset(aes_1b, 0x00, priv_key_size);
	if (!gfp_crypto_aes_ecb_dec(aes_1b, enc_req, priv_key_size, gfp_key.as_aes,
				    GFP_CRYPTO_AES_ECB_128)) {
		LOG_WRN("Key Base Pair: AES decryption failed");
		return false;
	}
	memcpy(parsed_req, aes_1b, sizeof(fp_kbp_raw_req_t));
	return true;
}

static int fp_kbp_req_handler(struct bt_conn *conn, struct net_buf_simple *rsp,
			      fp_kbp_raw_req_t const *req, uint8_t *do_addi_act)
{
	int err = 0;
	*do_addi_act = false; // Initialize to false

	LOG_DBG("FP KBP: Type=0x%02x, Flags=0x%02x", req->type, req->flags);

	// Get connection info for address validation
	struct bt_conn_info conn_info;
	err = bt_conn_get_info(conn, &conn_info);
	if (err) {
		LOG_ERR("FP KBP: Failed to get connection info: %d", err);
		return err;
	}

	// Check provider address (normal and reversed byte order)
	bool addr_match_normal =
		(memcmp(req->prov_addr, &conn_info.le.local->a.val, BT_ADDR_SIZE) == 0);
	uint8_t reversed_local[BT_ADDR_SIZE];
	for (int i = 0; i < BT_ADDR_SIZE; i++) {
		reversed_local[i] = conn_info.le.local->a.val[BT_ADDR_SIZE - 1 - i];
	}
	bool addr_match_reversed = (memcmp(req->prov_addr, reversed_local, BT_ADDR_SIZE) == 0);

	if (!addr_match_normal && !addr_match_reversed) {
		char req_addr_str[BT_ADDR_STR_LEN];
		char local_addr_str[BT_ADDR_STR_LEN];

		// Format addresses for logging
		snprintf(req_addr_str, sizeof(req_addr_str), "%02X:%02X:%02X:%02X:%02X:%02X",
			 req->prov_addr[0], req->prov_addr[1], req->prov_addr[2], req->prov_addr[3],
			 req->prov_addr[4], req->prov_addr[5]);
		snprintf(local_addr_str, sizeof(local_addr_str), "%02X:%02X:%02X:%02X:%02X:%02X",
			 conn_info.le.local->a.val[0], conn_info.le.local->a.val[1],
			 conn_info.le.local->a.val[2], conn_info.le.local->a.val[3],
			 conn_info.le.local->a.val[4], conn_info.le.local->a.val[5]);

		LOG_ERR("FP KBP: Provider address mismatch - rejecting request");
		LOG_ERR("FP KBP: Expected: %s, Received: %s", local_addr_str, req_addr_str);
		return -EACCES;
	}

	switch (req->type) {
	case FP_MSG_KEY_BASED_PAIRING_REQ:
		return fp_handle_key_based_pairing_request(conn, rsp, req, do_addi_act);

	case FP_MSG_ACTION_REQ:
		return fp_handle_action_request(conn, rsp, req, do_addi_act);

	default:
		LOG_ERR("FP KBP: Unsupported message type: 0x%02x", req->type);
		return -ENOTSUP;
	}
}

/**
 * @brief Additional Data characteristic write handler
 *
 * According to Fast Pair specification, this characteristic is used for
 * bidirectional communication of additional data like personalized names.
 *
 * @param conn BLE connection
 * @param attr GATT attribute
 * @param buf Data buffer
 * @param len Data length
 * @param offset Write offset
 * @param flags Write flags
 * @return Number of bytes written or BT_GATT_ERR
 */
static ssize_t fp_additional_data_write(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					const void *buf, uint16_t len, uint16_t offset,
					uint8_t flags)
{
	int err;

	if (!offset) {
		return fp_map_error(FP_ERR_INVALID_OFFSET);
	}
#define FP_ADDITIONAL_DATA_HMAC_LEN  8
#define FP_ADDITIONAL_DATA_NONCE_LEN 8
#define FP_ADDITIONAL_DATA_MIN_LEN   (FP_ADDITIONAL_DATA_HMAC_LEN + FP_ADDITIONAL_DATA_NONCE_LEN)
	if (len < FP_ADDITIONAL_DATA_MIN_LEN) {
		LOG_ERR("FP: Additional Data too short: %u (minimum 16 bytes)", len);
		return fp_map_error(FP_ERR_INSUFFICIENT_DATA);
	}

	// [HMAC-SHA256 (8 bytes)][Nonce (8 bytes)][Encrypted Data (variable)]

	const uint8_t *data = (const uint8_t *)buf;
	const uint8_t *hmac = data;                                        // First 8 bytes
	const uint8_t *nonce = data + FP_ADDITIONAL_DATA_HMAC_LEN;         // Next 8 bytes
	const uint8_t *encrypted_data = data + FP_ADDITIONAL_DATA_MIN_LEN; // Remaining bytes
	size_t encrypted_len = len - FP_ADDITIONAL_DATA_MIN_LEN;
	LOG_HEXDUMP_DBG(hmac, FP_ADDITIONAL_DATA_HMAC_LEN, "FP: Additional Data HMAC:");
	LOG_HEXDUMP_DBG(nonce, FP_ADDITIONAL_DATA_NONCE_LEN, "FP: Additional Data Nonce:");
	LOG_HEXDUMP_DBG(encrypted_data, encrypted_len, "FP: Additional Data Encrypted:");

	// Step 1: Verify HMAC-SHA256 authentication and decrypt
	uint8_t decrypted_data[GFP_CRYPTO_SHA256_DIG_LEN];

	if (encrypted_len > sizeof(decrypted_data)) {
		LOG_ERR("FP: Additional Data encrypted length too large: %zu", encrypted_len);
		return fp_map_error(FP_ERR_INVALID_LENGTH);
	}

	// Verify HMAC with shared secret from Key-based Pairing
	gfp_crypto_ctx_t hmac_ctx = {.pt = (uint8_t *)encrypted_data,
				     .pt_len = encrypted_len,
				     .secret_key = gfp_key.as_aes,
				     .secret_key_len = FP_AS_AES_KEY_LEN,
				     .nonce = (uint8_t *)nonce};

	uint8_t calculated_hmac[GFP_CRYPTO_SHA256_DIG_LEN];
	if (!gfp_crypto_gfps_hmac_sha256(calculated_hmac, sizeof(calculated_hmac), &hmac_ctx)) {
		return fp_map_error(FP_ERR_CRYPTO_FAILED);
	}

	// Compare first 8 bytes of calculated HMAC with received HMAC
	if (memcmp(hmac, calculated_hmac, FP_ADDITIONAL_DATA_HMAC_LEN) != 0) {
		LOG_HEXDUMP_ERR(hmac, FP_ADDITIONAL_DATA_HMAC_LEN, "Received HMAC:");
		LOG_HEXDUMP_ERR(calculated_hmac, FP_ADDITIONAL_DATA_HMAC_LEN, "Calculated HMAC:");
		return fp_map_error(FP_ERR_AUTH_FAILED);
	}

	// Step 2: Decrypt the encrypted data using AES-CTR
	gfp_crypto_aes_ctr_ctx_t aes_ctx = {.pt = (uint8_t *)encrypted_data,
					    .pt_len = encrypted_len,
					    .secret_key = gfp_key.as_aes,
					    .nonce = (uint8_t *)nonce};

	if (!gfp_crypto_aes_ctr_dec(decrypted_data, encrypted_len, &aes_ctx)) {
		return fp_map_error(FP_ERR_CRYPTO_FAILED);
	}

	LOG_HEXDUMP_DBG(decrypted_data, encrypted_len, "FP: Additional Data decrypted:");

	// Step 3: Process decrypted data according to Table 3.2
	// Note: For incoming Additional Data writes, the Data ID is typically communicated
	// via the Action Request (Table 1.2.2), not embedded in the encrypted data.
	// The encrypted data contains only the actual payload (e.g., personalized name string).

	if (encrypted_len < 1) {
		LOG_ERR("FP: Additional Data payload too short");
		return fp_map_error(FP_ERR_INSUFFICIENT_DATA);
	}

	// For now, assume this is a personalized name (Data ID 0x01) since that's the most common
	// case
	// TODO: Get actual Data ID from the preceding Action Request if available
	const uint8_t *payload = decrypted_data;
	size_t payload_len = encrypted_len;

	LOG_DBG("FP: Additional Data - Assuming personalized name, payload_len=%zu", payload_len);
	LOG_HEXDUMP_DBG(payload, payload_len, "FP: Additional Data payload:");

	// Process as personalized name
	{
		// Ensure null termination for string processing
		char name_buffer[FP_PERSONALIZED_NAME_MAX_LEN];
		size_t copy_len = MIN(payload_len, sizeof(name_buffer) - 1);
		memcpy(name_buffer, payload, copy_len);
		name_buffer[copy_len] = '\0';

		LOG_INF("FP: Received personalized name: '%s'", name_buffer);

		// Save the personalized name in persistent storage
		err = fp_storage_personalized_name_save(name_buffer);
		if (err) {
			LOG_ERR("FP: Failed to save personalized name: %d", err);
			return fp_map_error(FP_ERR_STORAGE_FAILED);
		}

		LOG_INF("FP: Personalized name saved successfully");
	}

	LOG_DBG("FP: Additional Data write processed successfully");
	return len;
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
		res = fp_map_error(FP_ERR_INVALID_STATE);
		goto finish;
	}
	if (offset != 0) {
		res = fp_map_error(FP_ERR_INVALID_OFFSET);
		goto finish;
	}
	int public_key_len = ecp_256r1_intf.curve_public_key_size();
	if ((len != (GFP_CRYPTO_AES_BLOCK_LEN_BYTES + public_key_len)) &&
	    (len != GFP_CRYPTO_AES_BLOCK_LEN_BYTES)) {
		LOG_WRN("Invalid length: len=%" PRIu16 " (Key-based Pairing)", len);
		res = fp_map_error(FP_ERR_INVALID_LENGTH);
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
		res = fp_map_error(FP_ERR_CRYPTO_FAILED);
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
		// Send device name notification via Additional Data characteristic
		err = fp_notify_device_name(conn);
		if (err) {
			LOG_WRN("Failed to notify device name: err=%d", err);
			// Don't fail the entire operation for notification failure
		}
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

static ssize_t fp_passkey_write(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	if (len != 16) {
		LOG_ERR("FP Passkey: Invalid length %u, expected 16", len);
		return fp_map_error(FP_ERR_INVALID_LENGTH);
	}

	// Fast Pair specification: Passkey verification
	// The 16-byte encrypted data contains the raw passkey block (Table 2.2)
	uint8_t decrypted_data[16];

	// Decrypt using AES-ECB with the shared secret from Key-based Pairing
	if (!gfp_crypto_aes_ecb_dec(decrypted_data, (const uint8_t *)buf, len, gfp_key.as_aes,
				    GFP_CRYPTO_AES_ECB_128)) {
		return fp_map_error(FP_ERR_CRYPTO_FAILED);
	}

// Fast Pair message types (Table 2.2: Raw Passkey Block)
#define FP_MSG_TYPE_SEEKER_PASSKEY   0x02 // Seeker's passkey confirmation
#define FP_MSG_TYPE_PROVIDER_PASSKEY 0x03 // Provider's passkey confirmation

	// Verify message type (Table 2.2: Raw Passkey Block)
	// For Passkey characteristic: Seeker sends passkey confirmation to Provider
	uint8_t message_type = decrypted_data[0];
	if (message_type != FP_MSG_TYPE_SEEKER_PASSKEY) {
		LOG_ERR("FP Passkey: Invalid message type: 0x%02x (expected 0x%02x = Seeker "
			"Passkey)",
			message_type, FP_MSG_TYPE_SEEKER_PASSKEY);
		return fp_map_error(FP_ERR_INVALID_VALUE);
	}

	LOG_DBG("FP Passkey: Received Seeker passkey confirmation (message type 0x%02x)",
		FP_MSG_TYPE_SEEKER_PASSKEY);

	// Extract 6-digit passkey from bytes 1-3 (Table 2.2: unit32, but only 3 bytes used)
	// Fast Pair specification Table 2.2: "1-3 unit32 6-digit passkey"
	uint32_t received_passkey =
		(decrypted_data[1] << 16) | (decrypted_data[2] << 8) | decrypted_data[3];

	LOG_DBG("FP Passkey: Received passkey: %06u", received_passkey);

	// Verify passkey format (Bluetooth specification: 6-digit decimal numbers)
	if (received_passkey > FP_PASSKEY_MAX) {
		LOG_ERR("FP Passkey: Invalid passkey value: %u (max: %u)", received_passkey,
			FP_PASSKEY_MAX);
		return fp_map_error(FP_ERR_INVALID_VALUE);
	}

	bool ret = fp_auth_validate_passkey(conn, received_passkey);

	if (!ret) {
		return fp_map_error(FP_ERR_AUTH_FAILED);
	}

	LOG_INF("FP Passkey: Passkey verification successful");

	// According to Fast Pair specification Table 2.2: Raw Passkey Block format
	// [Message Type (1 byte)][Passkey (3 bytes)][Reserved (12 bytes)]
	uint8_t raw_passkey_block[16] = {0};

	// Message Type = 0x03 (Provider's Passkey)
	raw_passkey_block[0] = FP_MSG_PROVIDERS_PASSKEY;

	// Passkey (3 bytes, big-endian format)
	raw_passkey_block[1] = (received_passkey >> 16) & 0xFF;
	raw_passkey_block[2] = (received_passkey >> 8) & 0xFF;
	raw_passkey_block[3] = received_passkey & 0xFF;

	// Encrypt using AES-ECB with the shared secret from Key-based Pairing
	uint8_t rsp_enc[16];

	if (!gfp_crypto_aes_ecb_enc(rsp_enc, raw_passkey_block, 16, gfp_key.as_aes,
				    GFP_CRYPTO_AES_ECB_128)) {
		LOG_WRN("FP Passkey: response encrypt failed");
		return -EINVAL;
	}

	int err = bt_gatt_notify(conn, attr, rsp_enc, sizeof(rsp_enc));
	if (err) {
		LOG_ERR("FP Passkey: Failed to notify passkey: %d", err);
		return err;
	}
	LOG_INF("FP Passkey: Provider passkey notification sent successfully");

	return len;
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

/// Fast Pair Passkey Characteristic UUID value
#define FP_UUID_PASSKEY_VAL BT_UUID_128_ENCODE(0xFE2C1235, 0x8366, 0x4814, 0x8EB0, 0x01DE32100BEA)
/// Fast Pair Passkey Characteristic UUID
#define FP_UUID_PASSKEY     BT_UUID_DECLARE_128(FP_UUID_PASSKEY_VAL)

BT_GATT_SERVICE_DEFINE(
	fast_pair_svc, BT_GATT_PRIMARY_SERVICE(FP_UUID_FPS),
	BT_GATT_CHARACTERISTIC(FP_UUID_MODEL_ID, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       fp_read_model_id, NULL, NULL),
	BT_GATT_CHARACTERISTIC(FP_UUID_KEY_BASED_PAIRING, BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_WRITE, NULL, fp_kbp_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
	BT_GATT_CHARACTERISTIC(FP_UUID_ACCOUNT_KEY, BT_GATT_CHRC_WRITE, BT_GATT_PERM_WRITE, NULL,
			       fp_write_account_key, NULL),
	BT_GATT_CHARACTERISTIC(FP_UUID_ADDITIONAL_DATA, BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_WRITE, NULL, fp_additional_data_write, NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
	BT_GATT_CHARACTERISTIC(FP_UUID_PASSKEY, BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, NULL, fp_passkey_write,
			       NULL),
	BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
#ifdef CONFIG_FAST_PAIR_FMDN
	FP_FMDN_BEACON_ACTIONS_CHARACTERISTIC,
#endif
);

/**
 * @brief Initialize GATT attribute references using UUID-based lookup
 *
 * This function finds GATT attributes by UUID instead of using hardcoded indices.
 * This approach is robust against service definition changes and provides
 * compile-time and runtime validation.
 */
static void fp_gatt_init_attr_refs(void)
{
	// Runtime validation: ensure service has attributes
	if (!fast_pair_svc.attr_count) {
		LOG_ERR("FP: Fast Pair service has no attributes");
		__ASSERT(0, "Fast Pair service must have attributes");
		return;
	}

	// Find Additional Data characteristic attribute by write callback
	// This approach is more reliable than UUID matching
	additional_data_attr = NULL;
	for (size_t i = 0; i < fast_pair_svc.attr_count; i++) {
		if (fast_pair_svc.attrs[i].write == fp_additional_data_write) {
			additional_data_attr = &fast_pair_svc.attrs[i];
			break;
		}
	}

	if (!additional_data_attr) {
		LOG_ERR("FP: Additional Data attribute not found in service definition");
		__ASSERT(0, "Critical: Additional Data attribute not found - check service "
			    "definition");
	} else {
		uint16_t handle = bt_gatt_attr_get_handle(additional_data_attr);

		LOG_DBG("FP: Additional Data attribute initialized successfully at handle 0x%04x",
			handle);

		// Validate that the attribute has the expected properties
		if (additional_data_attr->write != fp_additional_data_write) {
			LOG_WRN("FP: Additional Data attribute write handler mismatch - possible "
				"service definition error");
		}
	}
}

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

static void fp_as_key_load(void)
{

#ifdef CONFIG_ATM_SEC_JRNL_PRESENT
	uint8_t as_key_sec_jrnl[FP_AS_BASE64_KEY_LEN];
	uint16_t len_as_key_sec_jrnl = FP_AS_BASE64_KEY_LEN;
	if (nsc_sec_jrnl_get(CONFIG_FAST_PAIR_AS_KEY_TAG, &len_as_key_sec_jrnl, as_key_sec_jrnl) ==
	    SEC_JRNL_OK) {
		if (len_as_key_sec_jrnl == FP_AS_BASE64_KEY_LEN) {
			// Binary key - use directly
			memcpy(fp_as_key, as_key_sec_jrnl, FP_AS_BASE64_KEY_LEN);
			LOG_INF("Model ID [0x%06X] AS Key loaded from Secure Journal",
				CONFIG_FAST_PAIR_MODEL_ID);
			fp_as_key_loaded = true;
			return;
		}
		LOG_WRN("Invalid secure journal data length: %u ", len_as_key_sec_jrnl);
		LOG_INF("Using Kconfig fallback");
	} else {
		LOG_INF("Secure journal AS Key not found, using Kconfig default");
	}
#endif

	size_t fp_key_len;
	int ret = base64_decode(fp_as_key, FP_AS_BASE64_KEY_LEN, &fp_key_len,
				CONFIG_FAST_PAIR_AS_KEY, strlen(CONFIG_FAST_PAIR_AS_KEY));

	if (ret) {
		LOG_ERR("Failed to decode Base64 from Kconfig default: %d", ret);
		__ASSERT(0, "Failed to decode Base64 from Kconfig default: %d", ret);
	}
	LOG_INF("Model ID [0x%06X] AS Key loaded from Kconfig default", CONFIG_FAST_PAIR_MODEL_ID);
	fp_as_key_loaded = true;
}

void fp_gatt_init(void)
{
	if (!fp_as_key_loaded) {
		fp_as_key_load();
	}
	gfp_crypto_ecp_curve_intf_secp256r1(&ecp_256r1_intf);

	// Initialize GATT attribute references
	fp_gatt_init_attr_refs();

	// Initialize Fast Pair authentication
	int auth_err = fp_auth_init();
	if (auth_err) {
		LOG_ERR("FP: Failed to initialize authentication: %d", auth_err);
	}

#ifdef CONFIG_FAST_PAIR_FMDN
	fp_fmdn_gatt_init(fp_gatt_get_attr(FP_FMDN_UUID_BEACON_ACTIONS));
#endif
}

void fp_gatt_deinit(void)
{
	fp_auth_deinit();

#ifdef CONFIG_FAST_PAIR_FMDN
	fp_fmdn_gatt_deinit();
#endif
}
