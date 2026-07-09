/**
 *******************************************************************************
 *
 * @file gfp_crypto.c
 *
 * @brief Atmosic Google Fast Pair Secure Crypto Middleware
 * This secure Crypto Middleware for Google Fast Pair with mbedtls/uECC.
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/random/random.h>
#else
#include "trng.h"
#endif
#include <string.h>
#include "arch.h"
#include "atm_utils_c.h"
#include "atm_utils_endian.h"
#include "atm_utils_math.h"
#include "gfp_crypto.h"

#ifdef CONFIG_ATM_GFP_DIRECT_UECC_INTERFACE
#include "uECC_vli.h"
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
#include "atm_log.h"
ATM_LOG_LOCAL_SETTING("gfp_crypto", N);
#else
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(gfp_crypto, CONFIG_GFP_CRYPTO_LOG_LEVEL);
#undef ATM_LOG
#define ATM_LOG(MSK, fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#endif

#ifndef HMAC_KEY_LEN
// HMAC key length in bytes
#define HMAC_KEY_LEN 32
#endif
#ifndef HMAC_KEY_WORDS
// HMAC key length in words
#define HMAC_KEY_WORDS (HMAC_KEY_LEN / sizeof(uint32_t))
#endif

#define UECC_MAX_WORDS_SECP160R1 6
#define UECC_MAX_WORDS_SECP256R1 8

#ifndef CONFIG_SOC_FAMILY_ATM
#define AES_KEY_LEN(type)                                                                          \
	((type == GFP_CRYPTO_AES_ECB_128) ? ATM_AES_KEY_LEN_128 : ATM_AES_KEY_LEN_256)
#else
#define AES_KEY_BITS(type) ((type == GFP_CRYPTO_AES_ECB_128) ? 128 : 256)
#endif

static bool gfp_crypto_do_aes_ecb(uint8_t *out, uint8_t const *in, uint16_t in_len,
				  uint8_t const *key, bool en, gfp_crypto_aes_ecb_type_t type)
{
#ifdef CONFIG_SOC_FAMILY_ATM

	// Ensure PSA crypto is initialized
	psa_status_t status = psa_crypto_init();
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_crypto_init failed: %d", status);
		return false;
	}

	// Set up key attributes
	psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
	psa_set_key_usage_flags(&attributes, PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT);
	psa_set_key_algorithm(&attributes, PSA_ALG_ECB_NO_PADDING);
	psa_set_key_type(&attributes, PSA_KEY_TYPE_AES);
	psa_set_key_bits(&attributes, AES_KEY_BITS(type));

	// Import the key
	psa_key_id_t key_id = 0;
	status = psa_import_key(&attributes, key, AES_KEY_BITS(type) / 8, &key_id);
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_import_key failed: %d", status);
		return false;
	}

	// Perform encryption or decryption
	size_t output_length;
	if (en) {
		status = psa_cipher_encrypt(key_id, PSA_ALG_ECB_NO_PADDING, in, in_len, out, in_len,
					    &output_length);
	} else {
		status = psa_cipher_decrypt(key_id, PSA_ALG_ECB_NO_PADDING, in, in_len, out, in_len,
					    &output_length);
	}

	// Clean up the key
	psa_destroy_key(key_id);

	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_cipher_%s failed: %d", en ? "encrypt" : "decrypt", status);
		return false;
	}

	return true;
#else  // CONFIG_SOC_FAMILY_ATM
       // Use ATM hardware acceleration
	atm_aes_params_t const params = {
		.mode = ATM_AES_MODE_ECB,
		.key_len = AES_KEY_LEN(type),
		.encrypt = en,
		.key = key,
		.iv = NULL,
	};
	if (atm_aes_init(&params) != ATM_AES_RES_SUCCESS) {
		ATM_LOG(W, "atm_aes_init failed");
		return false;
	}
	if (atm_aes_update(out, in, in_len) != ATM_AES_RES_SUCCESS) {
		ATM_LOG(W, "atm_aes_update failed");
		return false;
	}
	atm_aes_disable();
	return true;
#endif // CONFIG_SOC_FAMILY_ATM
}

bool gfp_crypto_aes_ecb_enc(uint8_t *enc_data, uint8_t const *data, uint16_t data_len,
			    uint8_t const *key, gfp_crypto_aes_ecb_type_t type)
{
	return gfp_crypto_do_aes_ecb(enc_data, data, data_len, key, true, type);
}

bool gfp_crypto_aes_ecb_dec(uint8_t *dec_data, uint8_t const *data, uint16_t data_len,
			    uint8_t const *key, gfp_crypto_aes_ecb_type_t type)
{
	return gfp_crypto_do_aes_ecb(dec_data, data, data_len, key, false, type);
}

#ifndef CONFIG_SOC_FAMILY_ATM
static void gfp_crypto_hmac_key(uint8_t *hmac_key, uint8_t const *key, uint16_t key_len)
{
	memset(hmac_key, 0, HMAC_KEY_LEN);
	memcpy(hmac_key, key, key_len);
	for (int i = 0; i < HMAC_KEY_WORDS; i++) {
		atm_reverse(hmac_key + (i * sizeof(uint32_t)), sizeof(uint32_t));
	}
}
#endif

bool gfp_crypto_sha256(uint8_t const *data_in, uint16_t data_len, uint8_t *data_out)
{
#ifdef CONFIG_SOC_FAMILY_ATM

	// Ensure PSA crypto is initialized
	psa_status_t status = psa_crypto_init();
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_crypto_init failed: %d", status);
		return false;
	}

	// Compute SHA256 hash using one-shot API
	size_t hash_length;
	status = psa_hash_compute(PSA_ALG_SHA_256, data_in, data_len, data_out,
				  PSA_HASH_LENGTH(PSA_ALG_SHA_256), &hash_length);

	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_hash_compute failed: %d", status);
		return false;
	}

	return true;
#else  // CONFIG_SOC_FAMILY_ATM
	atm_sha256_params_t const sha256_params = {.mode = ATM_SHA256_SHA_MODE,
						   .byte_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .digest_endianess = ATM_SHA256_ENDIANESS_BIG};
	if (atm_sha256_digest(&sha256_params, data_in, data_len, data_out) !=
	    ATM_SHA256_RES_SUCCESS) {
		ATM_LOG(W, "atm_sha256_digest FAILED");
		return false;
	}
	return true;
#endif // CONFIG_SOC_FAMILY_ATM
}

bool gfp_crypto_hmac_sha256(uint8_t const *data_in, uint16_t data_len, uint8_t *data_out,
			    uint8_t const *key, uint16_t key_len)
{
#ifdef CONFIG_SOC_FAMILY_ATM

	// Ensure PSA crypto is initialized
	psa_status_t status = psa_crypto_init();
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_crypto_init failed: %d", status);
		return false;
	}

	// Set up key attributes for HMAC
	psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
	psa_set_key_usage_flags(&attributes, PSA_KEY_USAGE_SIGN_MESSAGE);
	psa_set_key_algorithm(&attributes, PSA_ALG_HMAC(PSA_ALG_SHA_256));
	psa_set_key_type(&attributes, PSA_KEY_TYPE_HMAC);

	// Import the HMAC key
	psa_key_id_t key_id = 0;
	status = psa_import_key(&attributes, key, key_len, &key_id);
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_import_key failed: %d", status);
		return false;
	}

	// Compute HMAC-SHA256 using one-shot API
	size_t mac_length;
	status = psa_mac_compute(
		key_id, PSA_ALG_HMAC(PSA_ALG_SHA_256), data_in, data_len, data_out,
		PSA_MAC_LENGTH(PSA_KEY_TYPE_HMAC, 256, PSA_ALG_HMAC(PSA_ALG_SHA_256)), &mac_length);

	// Clean up the key
	psa_destroy_key(key_id);

	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_mac_compute failed: %d", status);
		return false;
	}

	return true;
#else  // CONFIG_SOC_FAMILY_ATM
       // Use ATM hardware acceleration
	uint8_t hmac_key[HMAC_KEY_LEN];
	gfp_crypto_hmac_key(hmac_key, key, key_len);
	atm_sha256_params_t const sha256_params = {.mode = ATM_SHA256_HMAC_MODE,
						   .byte_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .digest_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .key = hmac_key};
	if (atm_sha256_digest(&sha256_params, data_in, data_len, data_out) !=
	    ATM_SHA256_RES_SUCCESS) {
		ATM_LOG(W, "atm_sha256_digest FAILED");
		return false;
	}
	return true;
#endif // CONFIG_SOC_FAMILY_ATM
}

void gfp_crypto_sha256_init(gfp_crypto_sha256_ctx_t *ctx)
{
#ifdef CONFIG_SOC_FAMILY_ATM

	// Ensure PSA crypto is initialized
	psa_status_t status = psa_crypto_init();
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_crypto_init failed: %d", status);
		return;
	}

	// Initialize hash operation
	*ctx = psa_hash_operation_init();
	status = psa_hash_setup(ctx, PSA_ALG_SHA_256);
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_hash_setup failed: %d", status);
		return;
	}
#else  // CONFIG_SOC_FAMILY_ATM
	UNUSED(ctx);
	atm_sha256_params_t const sha256_params = {.mode = ATM_SHA256_SHA_MODE,
						   .byte_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .digest_endianess = ATM_SHA256_ENDIANESS_BIG};
	atm_sha256_init(&sha256_params);
#endif // CONFIG_SOC_FAMILY_ATM
}

bool gfp_crypto_sha256_update(gfp_crypto_sha256_ctx_t *ctx, uint8_t const *data, uint16_t data_len)
{
#ifdef CONFIG_SOC_FAMILY_ATM
	psa_status_t status = psa_hash_update(ctx, data, data_len);
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_hash_update failed: %d", status);
		return false;
	}
#else  // CONFIG_SOC_FAMILY_ATM
	UNUSED(ctx);
	if (atm_sha256_update_pio(data, data_len) != ATM_SHA256_RES_SUCCESS) {
		ATM_LOG(W, "atm_sha256_update_pio FAILED");
		return false;
	}
#endif // CONFIG_SOC_FAMILY_ATM
	return true;
}

void gfp_crypto_sha256_deinit(gfp_crypto_sha256_ctx_t *ctx, uint8_t *out)
{
#ifdef CONFIG_SOC_FAMILY_ATM
	size_t hash_length;
	psa_status_t status =
		psa_hash_finish(ctx, out, PSA_HASH_LENGTH(PSA_ALG_SHA_256), &hash_length);
	if (status != PSA_SUCCESS) {
		ATM_LOG(W, "psa_hash_finish failed: %d", status);
		psa_hash_abort(ctx);
		return;
	}
#else  // CONFIG_SOC_FAMILY_ATM
	UNUSED(ctx);
	atm_sha256_final(out);
	atm_sha256_disable();
#endif // CONFIG_SOC_FAMILY_ATM
}

void gfp_crypto_reverse_array(uint8_t *array, size_t length)
{
	for (size_t i = 0; i < (length / 2); ++i) {
		uint8_t temp = array[i];
		array[i] = array[length - 1 - i];
		array[length - 1 - i] = temp;
	}
}

#ifdef CONFIG_ATM_GFP_DIRECT_UECC_INTERFACE
#define CURVE_SECP256R1 uECC_secp256r1()
#define CURVE_SECP160R1 uECC_secp160r1()

static void gfp_crypto_uECC_vli_mmod(uint8_t const *data_in, uint8_t data_in_len, uint8_t *data_out,
				     uint16_t data_out_len, struct uECC_Curve_t const *curve,
				     int max_words)
{
	uECC_word_t product[max_words * 2]; // 2x curve order size
	uECC_word_t result[max_words];      // curve order size
	// Ensure data_in is correctly aligned to the curve's size (truncate or
	// pad if necessary)
	uint8_t tmp_data_in[data_in_len];
	memcpy(tmp_data_in, data_in, data_in_len);
	gfp_crypto_reverse_array(tmp_data_in, data_in_len);
	memset(product, 0, sizeof(uECC_word_t) * max_words * 2);
	memcpy(product, tmp_data_in, data_in_len);
	uECC_vli_mmod(result, product, uECC_curve_n(curve), uECC_curve_num_n_words(curve));
	memcpy(data_out, result, data_out_len);
}

static void gfp_crypto_uECC_vli_mmod_secp160r1(uint8_t const *data_in, uint16_t data_in_len,
					       uint8_t *data_out, uint16_t data_out_len)
{
	return gfp_crypto_uECC_vli_mmod(data_in, data_in_len, data_out, data_out_len,
					CURVE_SECP160R1, UECC_MAX_WORDS_SECP160R1);
}

static void gfp_crypto_uECC_vli_mmod_secp256r1(uint8_t const *data_in, uint16_t data_in_len,
					       uint8_t *data_out, uint16_t data_out_len)
{
	return gfp_crypto_uECC_vli_mmod(data_in, data_in_len, data_out, data_out_len,
					CURVE_SECP256R1, UECC_MAX_WORDS_SECP256R1);
}

static int gfp_crypto_uECC_order_size_secp160r1(void)
{
	return (UECC_MAX_WORDS_SECP160R1 * sizeof(uECC_word_t));
}

static int gfp_crypto_uECC_order_size_secp256r1(void)
{
	return (UECC_MAX_WORDS_SECP256R1 * sizeof(uECC_word_t));
}

static int gfp_crypto_uECC_shared_secret_secp160r1(const uint8_t *public_key,
						   const uint8_t *private_key, uint8_t *secret)
{
	return uECC_shared_secret(public_key, private_key, secret, CURVE_SECP160R1);
}

static int gfp_crypto_uECC_shared_secret_secp256r1(const uint8_t *public_key,
						   const uint8_t *private_key, uint8_t *secret)
{
	return uECC_shared_secret(public_key, private_key, secret, CURVE_SECP256R1);
}

static int gfp_crypto_uECC_compute_public_key_secp160r1(uint8_t const *private_key,
							uint8_t *public_key)
{
	return uECC_compute_public_key(private_key, public_key, CURVE_SECP160R1);
}

static int gfp_crypto_uECC_compute_public_key_secp256r1(uint8_t const *private_key,
							uint8_t *public_key)
{
	return uECC_compute_public_key(private_key, public_key, CURVE_SECP256R1);
}

static int gfp_crypto_uECC_curve_private_key_size_secp160r1(void)
{
	return uECC_curve_private_key_size(CURVE_SECP160R1);
}

static int gfp_crypto_uECC_curve_private_key_size_secp256r1(void)
{
	return uECC_curve_private_key_size(CURVE_SECP256R1);
}

static int gfp_crypto_uECC_curve_public_key_size_secp160r1(void)
{
	return uECC_curve_public_key_size(CURVE_SECP160R1);
}

static int gfp_crypto_uECC_curve_public_key_size_secp256r1(void)
{
	return uECC_curve_public_key_size(CURVE_SECP256R1);
}
#endif

#ifdef CONFIG_ATM_GFP_DIRECT_UECC_INTERFACE
void gfp_crypto_ecp_curve_intf_secp160r1(gfp_crypto_ecp_curve_intf_t *intf)
{
	intf->shared_secret = gfp_crypto_uECC_shared_secret_secp160r1;
	intf->order_size = gfp_crypto_uECC_order_size_secp160r1;
	intf->curve_private_key_size = gfp_crypto_uECC_curve_private_key_size_secp160r1;
	intf->curve_public_key_size = gfp_crypto_uECC_curve_public_key_size_secp160r1;
	intf->vli_mmod = gfp_crypto_uECC_vli_mmod_secp160r1;
	intf->compute_public_key = gfp_crypto_uECC_compute_public_key_secp160r1;
}
#endif

void gfp_crypto_ecp_curve_intf_secp256r1(gfp_crypto_ecp_curve_intf_t *intf)
{
#ifdef CONFIG_ATM_GFP_DIRECT_UECC_INTERFACE
	intf->shared_secret = gfp_crypto_uECC_shared_secret_secp256r1;
	intf->order_size = gfp_crypto_uECC_order_size_secp256r1;
	intf->curve_private_key_size = gfp_crypto_uECC_curve_private_key_size_secp256r1;
	intf->curve_public_key_size = gfp_crypto_uECC_curve_public_key_size_secp256r1;
	intf->vli_mmod = gfp_crypto_uECC_vli_mmod_secp256r1;
	intf->compute_public_key = gfp_crypto_uECC_compute_public_key_secp256r1;
#else
#error "No ECP 256r1 curve interface is defined"
#endif
}

size_t gfp_crypto_acct_key_filter_size(size_t n)
{
	return n ? (1.2 * n + 3) : 0;
}

bool gfp_crypto_acct_key_fl_gen(gfp_crypto_acct_key_fl_info_t *info, uint16_t salt,
				uint8_t const *bati, uint8_t batl, void const *ctx)
{
	memset(info->data, 0x00, info->max_data_len);
	uint8_t const *account_key_list = NULL;
	size_t acct_key_num = 0;
	if (ctx) {
		gfp_crypto_acct_key_fl_ctx_t const *gakf;
		gakf = ctx;
		salt = gakf->salt;
		bati = gakf->batt_data;
		batl = gakf->batt_data_len;
		account_key_list = gakf->acct_key_list;
		acct_key_num = (size_t)gakf->acct_key_num;
	} else {
		ATM_LOG(W, "ctx is null");
		return false;
	}
	size_t s = gfp_crypto_acct_key_filter_size(acct_key_num);
	uint8_t h[GFP_CRYPTO_SHA256_DIG_LEN];
	for (size_t i = 0; i < acct_key_num; i++) {
		uint8_t v[GFP_CRYPTO_ACTK_LEN + sizeof(salt) + batl];
		size_t pos = 0;
		memcpy(v, &account_key_list[i * GFP_CRYPTO_ACTK_LEN], GFP_CRYPTO_ACTK_LEN);
		pos += GFP_CRYPTO_ACTK_LEN;
		v[pos++] = salt >> 8;
		v[pos++] = salt;
		if (bati && batl) {
			memcpy(&v[pos], bati, batl);
			pos += batl;
		}
		gfp_crypto_sha256(v, pos, h);
		// Divide H into eight 4-byte unsigned integers
		uint32_t X[8];
		for (int index = 0; index < 8; index++) {
			X[index] = (((uint32_t)(h[index * 4])) << 24) |
				   (((uint32_t)(h[index * 4 + 1])) << 16) |
				   (((uint32_t)(h[index * 4 + 2])) << 8) |
				   (((uint32_t)(h[index * 4 + 3])) << 0);
		}
		// Update the Bloom filter
		for (int index = 0; index < 8; index++) {
			uint32_t M = X[index] % (s * 8);
			info->data[M / 8] = info->data[M / 8] | (1 << (M % 8));
		}
	}
	return true;
}

bool gfp_crypto_aes_ctr(uint8_t *ct, uint16_t ct_len, gfp_crypto_aes_ctr_ctx_t const *gac)
{
	if ((ct_len < gac->pt_len) || !gac->pt) {
		ATM_LOG(V, "%s: insufficient resource!", __func__);
		return false;
	}

	uint8_t buffer[ATM_AES_BLOCK_LEN_BYTES];
	uint8_t iv[ATM_AES_BLOCK_LEN_BYTES];
	uint8_t const *plaintext = gac->pt;

	_Static_assert(ATM_AES_BLOCK_LEN_BYTES <= GFP_CRYPTO_AES_BLOCK_LEN_BYTES,
		       "Wrong AES block size");

	memset(iv, 0x00, ATM_AES_BLOCK_LEN_BYTES);
	memcpy(&iv[GFP_CRYPTO_HMAC_NONCE_LEN], gac->nonce, GFP_CRYPTO_HMAC_NONCE_LEN);
	uint16_t block_idx = 0;
	for (uint16_t idx = 0; idx < gac->pt_len; idx++) {
		if (!(idx % GFP_CRYPTO_AES_BLOCK_LEN_BYTES)) {
			gfp_crypto_aes_ecb_enc(buffer, iv, ATM_AES_BLOCK_LEN_BYTES, gac->secret_key,
					       GFP_CRYPTO_AES_ECB_128);
			iv[0] = ++block_idx;
		}

		*ct++ = buffer[idx % (GFP_CRYPTO_AES_BLOCK_LEN_BYTES)] ^ *plaintext++;
	}

	return true;
}

bool gfp_crypto_aes_ctr_dec(uint8_t *ct, uint16_t ct_len, gfp_crypto_aes_ctr_ctx_t const *gac)
{
	if ((ct_len < gac->pt_len) || !gac->pt) {
		ATM_LOG(W, "%s: insufficient resource!", __func__);
		return false;
	}

	uint8_t counter[ATM_AES_BLOCK_LEN_BYTES];
	uint8_t keystream[ATM_AES_BLOCK_LEN_BYTES];

	for (size_t i = 0; i < ATM_AES_BLOCK_LEN_BYTES; ++i) {
		// Prepare the counter block
		memset(counter, 0, ATM_AES_BLOCK_LEN_BYTES);
		// Set block index
		counter[0] = (uint8_t)i;
		// Set nonce
		memcpy(counter + 8, gac->nonce, 8);
		// // Generate keystream
		gfp_crypto_aes_ecb_enc(keystream, counter, ATM_AES_BLOCK_LEN_BYTES, gac->secret_key,
				       GFP_CRYPTO_AES_ECB_128);
		// Decrypt block
		for (size_t j = 0; j < 16 && i * 16 + j < gac->pt_len; ++j) {
			ct[i * 16 + j] = gac->pt[i * 16 + j] ^ keystream[j];
		}
	}

	return true;
}

bool gfp_crypto_gfps_hmac_sha256(uint8_t *ct, uint16_t ct_len, gfp_crypto_ctx_t const *gc)
{
	if (ct_len < GFP_CRYPTO_SHA256_DIG_LEN) {
		ATM_LOG(V, "Resource insufficient!");
		return false;
	}

#define GFPS_HMAC_SHA256_K_SIZE 64

	static uint16_t const tsize = GFPS_HMAC_SHA256_K_SIZE + GFP_CRYPTO_SHA256_DIG_LEN;
	uint8_t *buf = calloc(tsize, sizeof(uint8_t));
	if (!buf) {
		ATM_LOG(V, "Allocate memory fail!");
		ASSERT_ERR(0);
		return false;
	}

#define GFPS_HMAC_SHA256_IPAD 0x36

	// K ^ ipad
	memcpy(buf, gc->secret_key, gc->secret_key_len);
	for (uint8_t idx = 0; idx < GFPS_HMAC_SHA256_K_SIZE; idx++) {
		buf[idx] = buf[idx] ^ GFPS_HMAC_SHA256_IPAD;
	}

	// cipher_a = concat((K ^ ipad), concat(nonce, encrypted_data))
	uint16_t offset = GFPS_HMAC_SHA256_K_SIZE;
	memcpy(&buf[offset], gc->nonce, GFP_CRYPTO_HMAC_NONCE_LEN);
	offset += GFP_CRYPTO_HMAC_NONCE_LEN;

	gfp_crypto_sha256_ctx_t ctx;
	gfp_crypto_sha256_init(&ctx);
	if (!gfp_crypto_sha256_update(&ctx, buf, offset)) {
		ATM_LOG(W, "gfp_crypto_sha256_update failed");
		goto cleanup;
	}

	if (!gfp_crypto_sha256_update(&ctx, gc->pt, gc->pt_len)) {
		ATM_LOG(W, "gfp_crypto_sha256_update failed");
		goto cleanup;
	}
	gfp_crypto_sha256_deinit(&ctx, ct);

#define GFPS_HMAC_SHA256_OPAD 0x5C

	// K ^ opad
	memset(buf, 0x00, tsize);
	memcpy(buf, gc->secret_key, GFP_CRYPTO_HMAC_SECRET_KEY_LEN);
	for (uint8_t idx = 0; idx < GFPS_HMAC_SHA256_K_SIZE; idx++) {
		buf[idx] = buf[idx] ^ GFPS_HMAC_SHA256_OPAD;
	}

	// concat((K ^ opad), cipher_a)
	memcpy(&buf[GFPS_HMAC_SHA256_K_SIZE], ct, GFP_CRYPTO_SHA256_DIG_LEN);
	gfp_crypto_sha256(buf, tsize, ct);
	memset(buf, 0x00, tsize);
	free(buf);

	return true;
cleanup:
#ifdef CONFIG_SOC_FAMILY_ATM
	psa_hash_abort(&ctx);
#endif // CONFIG_SOC_FAMILY_ATM
	memset(buf, 0x00, tsize);
	free(buf);
	return false;
}
