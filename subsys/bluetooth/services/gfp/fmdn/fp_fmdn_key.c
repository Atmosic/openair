/**
 *******************************************************************************
 *
 * @file fp_fmdn_key.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Key Process Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <zephyr/sys/util.h>
#include "fp_fmdn_key.h"
#include "fp_storage.h"
#include "gfp_crypto.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

static uint8_t fmdn_eid[FP_FMDN_STATE_EID_LEN] = {0};
static bool is_eid_generated;
static uint8_t latest_eid_hash_sig;
static fp_fmdn_battery_cb battery_cb;

bool fp_fmdn_key_generate(uint8_t const *eid_key, fp_fmdn_auth_key_type_t key_type,
			  uint8_t *auth_key, size_t auth_key_len)
{
	uint8_t key_data[FP_FMDN_EID_KEY_LEN + 1];
	uint8_t *dst_ptr = key_data;
	enum {
		KEY_SEED_END_BYTE_RECOVERY = 0x01,
		KEY_SEED_END_BYTE_RING,
		KEY_SEED_END_BYTE_UTP,
	};
	uint8_t seed_end_byte;
	switch (key_type) {
	case FP_FMDN_AUTH_KEY_TYPE_RECOVERY:
		seed_end_byte = KEY_SEED_END_BYTE_RECOVERY;
		break;
	case FP_FMDN_AUTH_KEY_TYPE_RING:
		seed_end_byte = KEY_SEED_END_BYTE_RING;
		break;
	case FP_FMDN_AUTH_KEY_TYPE_UTP:
		seed_end_byte = KEY_SEED_END_BYTE_UTP;
		break;
	default:
		LOG_WRN("Authentication: key generation: unsupported key type");
		return false;
	}
	size_t offset = 0;
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, eid_key, FP_FMDN_EID_KEY_LEN, offset);
	FP_UTIL_MEMCPY_SHIFT(dst_ptr, &seed_end_byte, sizeof(seed_end_byte), offset);
	uint8_t hash[GFP_CRYPTO_SHA256_DIG_LEN];
	gfp_crypto_sha256(key_data, sizeof(key_data), hash);
	memcpy(auth_key, hash, auth_key_len);
	return true;
}

void fp_fmdn_key_eik_auth_data(bcna_conn_ctx_t *conn_context, uint8_t *eid_key, uint8_t *auth_data)
{
	/* the first 8 bytes of SHA256(current ephemeral identity key ||
	 * the last nonce read from the characteristic)
	 */
	size_t offset = 0;
	FP_UTIL_MEMCPY_SHIFT(auth_data, eid_key, FP_FMDN_EID_KEY_LEN, offset);
	FP_UTIL_MEMCPY_SHIFT(auth_data, conn_context->random_nonce, BCNA_RNDM_NONCE_LEN, offset);
}

static void fp_fmdn_key_eid_construct_data(uint8_t *data, uint32_t fmdn_clock, uint8_t kbits)
{
#define FMDN_EID_SEED_PADDING_LEN 11
	memset(data, 0xFF, FMDN_EID_SEED_PADDING_LEN); // Padding with 0xFF
	data[11] = kbits;
	fmdn_clock &= ~((1 << kbits) - 1); // Clear lowest K bits
	data[12] = (fmdn_clock >> 24) & 0xFF;
	data[13] = (fmdn_clock >> 16) & 0xFF;
	data[14] = (fmdn_clock >> 8) & 0xFF;
	data[15] = fmdn_clock & 0xFF;
	memset(data + 16, 0x00, FMDN_EID_SEED_PADDING_LEN); // Padding with 0x00
	data[27] = kbits;
	data[28] = (fmdn_clock >> 24) & 0xFF;
	data[29] = (fmdn_clock >> 16) & 0xFF;
	data[30] = (fmdn_clock >> 8) & 0xFF;
	data[31] = fmdn_clock & 0xFF;
}

static void fp_fmdn_key_eid_encrypt_data(uint8_t *data, uint8_t const *key, uint8_t *encrypted_data)
{
	// Encrypt the first 16 bytes
	gfp_crypto_aes_ecb_enc(encrypted_data, data, GFP_CRYPTO_AES_BLOCK_LEN_BYTES, key,
			       ATM_AES_KEY_LEN_256);
	// Encrypt the next 16 bytes
	gfp_crypto_aes_ecb_enc(encrypted_data + GFP_CRYPTO_AES_BLOCK_LEN_BYTES,
			       data + GFP_CRYPTO_AES_BLOCK_LEN_BYTES,
			       GFP_CRYPTO_AES_BLOCK_LEN_BYTES, key, ATM_AES_KEY_LEN_256);
}

static void fp_fmdn_key_eid_compute(uint8_t const *r_prime, uint8_t *eid, uint8_t *secp_mod_res)
{
	gfp_crypto_ecp_curve_intf_t uECC_intf;
#ifdef CFG_FMDN_ECC_SECP256R1
	gfp_crypto_ecp_curve_intf_secp256r1(&uECC_intf);
#else
	gfp_crypto_ecp_curve_intf_secp160r1(&uECC_intf);
#endif
	int order_size = uECC_intf.order_size();
	int private_key_size = uECC_intf.curve_private_key_size();
	int public_key_size = uECC_intf.curve_public_key_size();
	uint8_t r[private_key_size];
	uint8_t R[public_key_size];
	uint8_t result[order_size];

	// Compute r = r' mod n using uECC_vli_mmod
	uECC_intf.vli_mmod(r_prime, FP_EIK_LEN, result, order_size);
	memcpy(secp_mod_res, result, FP_FMDN_STATE_EID_LEN);
	gfp_crypto_reverse_array(secp_mod_res, FP_FMDN_STATE_EID_LEN);
	memcpy(r, result, private_key_size);
	gfp_crypto_reverse_array((uint8_t *)r, private_key_size);
	// Compute EID (r projected to finite field and then compute R = r * G)
	if (!uECC_intf.compute_public_key(r, R)) {
		LOG_WRN("Failed to compute public key");
	}
	// Copy the x-coordinate of R to eid
	memcpy(eid, R, FP_FMDN_STATE_EID_LEN);
}

static fp_fmdn_battery_level_t fp_fmdn_battery_level(void)
{
	uint8_t battery_percentage = FP_FMDN_BATTERY_LEVEL_NONE;
	if (battery_cb) {
		battery_percentage = battery_cb();
	}
	if (battery_percentage == FP_FMDN_BATTERY_LEVEL_NONE) {
		return FP_FMDN_BATTERY_LEVEL_NOT_SUPPORT;
	}
	if (battery_percentage <= 10) {
		return FP_FMDN_BATTERY_LEVEL_CRITICAL;
	} else if (battery_percentage <= 30) {
		return FP_FMDN_BATTERY_LEVEL_LOW;
	} else {
		return FP_FMDN_BATTERY_LEVEL_NORMAL;
	}
}

#ifdef CONFIG_FAST_PAIR_FMDN_DULT
void fp_fmdn_key_gen_dult_id(uint8_t const *eid_key, uint8_t *fmdn_dult_id)
{
	if (!is_eid_generated) {
		LOG_WRN("EID not generated");
		return;
	}
	static uint8_t recovery_key[BCNA_AUTH_KEY_MAX_LEN];
	if (!fp_fmdn_key_generate(eid_key, FP_FMDN_AUTH_KEY_TYPE_RECOVERY, recovery_key,
				  BCNA_AUTH_KEY_LEN)) {
		LOG_WRN("dult_id generated recovery_key failed");
		return;
	}
	uint8_t hsha[GFP_CRYPTO_SHA256_DIG_LEN];
	gfp_crypto_hmac_sha256(fmdn_eid, FP_FMDN_EID_DATA_LEN, hsha, recovery_key,
			       BCNA_AUTH_KEY_LEN);
	memcpy(fmdn_dult_id, fmdn_eid, FP_FMDN_EID_DATA_LEN);
	memcpy(fmdn_dult_id + FP_FMDN_EID_DATA_LEN, hsha, FP_FMDN_EID_DATA_SHA_LEN);
}
#endif // CONFIG_FAST_PAIR_FMDN_DULT

uint32_t fp_fmdn_key_clock_read(void)
{
	uint32_t fmdn_clock = k_uptime_seconds();
	LOG_DBG("FMDN Clock: reading the last value: %#x [s]", fmdn_clock);
	return fmdn_clock;
}

static uint32_t fmdn_eid_clock_checkpoint;
void fp_fmdn_key_gen_eid(uint8_t const *fmdn_eid_key, bool force)
{
#define FMDN_EID_SEED_ROT_PERIOD_EXP   10 // to be update with utp mode
#define FMDN_EID_SEED_PADDING_TYPE_ONE 0xFF
#define FMDN_EID_SEED_PADDING_TYPE_TWO 0x00
	uint8_t eid_seed_data[FP_EIK_LEN] = {0};
	uint8_t encrypted_data[FP_EIK_LEN] = {0};
	uint8_t secp_mod_res[FP_FMDN_STATE_EID_LEN] = {0};
	uint8_t const uninitialized_eid[FP_FMDN_STATE_EID_LEN] = {0};
	uint8_t rotation_period_exponent = FMDN_EID_SEED_ROT_PERIOD_EXP;
	/* Prepare the FMDN Clock value. */
	uint32_t fmdn_clock = fp_fmdn_key_clock_read();

	if (!force) {
		/* Clear the K lowest bits in the clock value. */
		fmdn_clock &= ~BIT_MASK(FMDN_EID_SEED_ROT_PERIOD_EXP);
	}

	LOG_DBG("Prepare the FMDN Clock %#x", fmdn_clock);

	/* Check if the EID seed or EIK has changed since the last call. */
	if (memcmp(fmdn_eid, uninitialized_eid, sizeof(uninitialized_eid))) {
		if (fmdn_clock == fmdn_eid_clock_checkpoint) {
			LOG_INF("FMDN State: EID does not require recalculation");
			return;
		}
	}
	fmdn_eid_clock_checkpoint = fmdn_clock;

	/* Prepare the EID seed data. */
	fp_fmdn_key_eid_construct_data(eid_seed_data, fmdn_clock, rotation_period_exponent);
	/* Encrypt the EID seed data with the Ephemeral Identity Key using the
	 * AES-ECB-256 scheme. */
	fp_fmdn_key_eid_encrypt_data(eid_seed_data, fmdn_eid_key, encrypted_data);
	// Compute EID (r projected to finite field and then compute R = r * G)
	fp_fmdn_key_eid_compute(encrypted_data, fmdn_eid, secp_mod_res);
	is_eid_generated = true;
	// Compute hashed flags
	uint8_t hash[GFP_CRYPTO_SHA256_DIG_LEN];
	gfp_crypto_sha256(secp_mod_res, FP_FMDN_STATE_EID_LEN, hash);
	latest_eid_hash_sig = hash[31];
}

uint8_t fp_fmdn_key_get_eid(uint8_t *eid)
{
	if (!is_eid_generated) {
		return 0;
	}
	memcpy(eid, fmdn_eid, FP_FMDN_STATE_EID_LEN);
	return FP_FMDN_STATE_EID_LEN;
}

uint8_t fp_fmdn_key_get_eid_hashed_flags(void)
{
	if (!is_eid_generated) {
		LOG_WRN("EID not generated");
		return 0;
	}
	uint8_t battery_level = fp_fmdn_battery_level();
	bool unwanted_tracking = (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON);
#define FMDN_FRAME_UTP_BIT_OFFSET     0
#define FMDN_FRAME_BATTERY_BIT_OFFSET 1
	uint8_t flags_seed = 0;
	WRITE_BIT(flags_seed, FMDN_FRAME_UTP_BIT_OFFSET, unwanted_tracking);
	flags_seed |= (battery_level << FMDN_FRAME_BATTERY_BIT_OFFSET);
	return (flags_seed ^ latest_eid_hash_sig);
}

void fp_fmdn_key_clear_eid(void)
{
	fmdn_eid_clock_checkpoint = 0;
	latest_eid_hash_sig = 0;
	memset(fmdn_eid, 0, FP_FMDN_STATE_EID_LEN);
	is_eid_generated = false;
}

void fp_fmdn_key_update_eid(void)
{
	if (fp_storage_eid_key_valid()) {
		uint8_t eidk[FP_FMDN_EID_KEY_LEN];
		fp_storage_eid_key_get(eidk);
		fp_fmdn_key_gen_eid(eidk, false);
	}
}

void fp_fmdn_key_battery_reg(fp_fmdn_battery_cb const hdlr)
{
	if (!battery_cb) {
		battery_cb = hdlr;
	}
}
