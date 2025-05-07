/**
 *******************************************************************************
 *
 * @file gfp_crypto.c
 *
 * @brief Atmosic Google Fast Pair Secure Crypto Middleware
 * This secure Crypto Middleware for Google Fast Pair with mbedtls/uECC.
 *
 * Copyright (C) Atmosic 2025
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
#else
#include "mbedtls/ecdh.h"
#include "mbedtls/ecdsa.h"
#include "mbedtls/ecp.h"
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
#define CHECK_RV_GOTO_RET(_rv_, _label_, _val_)                                                    \
	if (_rv_) {                                                                                \
		_rv_ = _val_;                                                                      \
		goto _label_;                                                                      \
	}
#endif

static bool gfp_crypto_do_aes_ecb(uint8_t *out, uint8_t const *in, uint16_t in_len,
				  uint8_t const *key, bool en, gfp_crypto_aes_ecb_type_t type)
{
#ifdef CONFIG_SOC_FAMILY_ATM
	mbedtls_aes_context aes;
	mbedtls_aes_init(&aes);
	int ret;
	int mode;
	if (en) {
		mode = MBEDTLS_AES_ENCRYPT;
		ret = mbedtls_aes_setkey_enc(&aes, key, AES_KEY_BITS(type));
	} else {
		mode = MBEDTLS_AES_DECRYPT;
		ret = mbedtls_aes_setkey_dec(&aes, key, AES_KEY_BITS(type));
	}
	CHECK_RV_GOTO_RET(ret, cleanup, -1);
	ret = mbedtls_aes_crypt_ecb(&aes, mode, in, out);
	CHECK_RV_GOTO_RET(ret, cleanup, -2);
cleanup:
	mbedtls_aes_free(&aes);
	return ret ? false : true;
#else
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
#endif
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
	mbedtls_sha256_context ctx;
	mbedtls_sha256_init(&ctx);
	int ret;
	ret = mbedtls_sha256_starts(&ctx, false);
	CHECK_RV_GOTO_RET(ret, cleanup, -1);
	ret = mbedtls_sha256_update(&ctx, data_in, data_len);
	CHECK_RV_GOTO_RET(ret, cleanup, -2);
	ret = mbedtls_sha256_finish(&ctx, data_out);
	CHECK_RV_GOTO_RET(ret, cleanup, -3);
cleanup:
	mbedtls_sha256_free(&ctx);
	return ret ? false : true;
#else
	atm_sha256_params_t const sha256_params = {.mode = ATM_SHA256_SHA_MODE,
						   .byte_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .digest_endianess = ATM_SHA256_ENDIANESS_BIG};
	if (atm_sha256_digest(&sha256_params, data_in, data_len, data_out) !=
	    ATM_SHA256_RES_SUCCESS) {
		ATM_LOG(W, "atm_sha256_digest FAILED");
		return false;
	}
	return true;
#endif
}

bool gfp_crypto_hmac_sha256(uint8_t const *data_in, uint16_t data_len, uint8_t *data_out,
			    uint8_t const *key, uint16_t key_len)
{
#ifdef CONFIG_SOC_FAMILY_ATM
	int res;
	mbedtls_md_type_t const alg = MBEDTLS_MD_SHA256;
	mbedtls_md_info_t const *info = mbedtls_md_info_from_type(alg);
	mbedtls_md_context_t ctx;
	mbedtls_md_init(&ctx);
	res = mbedtls_md_setup(&ctx, info, true);
	CHECK_RV_GOTO_RET(res, cleanup, -1);
	res = mbedtls_md_hmac_starts(&ctx, key, key_len);
	CHECK_RV_GOTO_RET(res, cleanup, -2);
	res = mbedtls_md_hmac_update(&ctx, data_in, data_len);
	CHECK_RV_GOTO_RET(res, cleanup, -3);
	res = mbedtls_md_hmac_finish(&ctx, data_out);
	CHECK_RV_GOTO_RET(res, cleanup, -4);
cleanup:
	mbedtls_md_free(&ctx);
	return res ? false : true;
#else
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
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
void gfp_crypto_sha256_init(mbedtls_sha256_context *ctx)
#else
void gfp_crypto_sha256_init(void)
#endif
{
#ifdef CONFIG_SOC_FAMILY_ATM
	mbedtls_sha256_init(ctx);
	mbedtls_sha256_starts(ctx, false);
#else
	atm_sha256_params_t const sha256_params = {.mode = ATM_SHA256_SHA_MODE,
						   .byte_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .digest_endianess = ATM_SHA256_ENDIANESS_BIG};
	atm_sha256_init(&sha256_params);
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
bool gfp_crypto_hmac_sha256_init(mbedtls_md_context_t *ctx, uint8_t const *key, uint16_t key_len)
#else
void gfp_crypto_hmac_sha256_init(uint8_t const *key, uint16_t key_len)
#endif
{
#if CONFIG_SOC_FAMILY_ATM
	mbedtls_md_type_t const alg = MBEDTLS_MD_SHA256;
	mbedtls_md_info_t const *info = mbedtls_md_info_from_type(alg);
	mbedtls_md_init(ctx);
	if (mbedtls_md_setup(ctx, info, true)) {
		ATM_LOG(W, "mbedtls_md_setup FAILED");
		return false;
	}
	if (mbedtls_md_hmac_starts(ctx, key, sizeof(key_len))) {
		ATM_LOG(W, "mbedtls_md_hmac_starts FAILED");
		return false;
	}
	return true;
#else
	uint8_t hmac_key[HMAC_KEY_LEN];
	gfp_crypto_hmac_key(hmac_key, key, key_len);
	atm_sha256_params_t const sha256_params = {.mode = ATM_SHA256_HMAC_MODE,
						   .byte_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .digest_endianess = ATM_SHA256_ENDIANESS_BIG,
						   .key = hmac_key};
	atm_sha256_init(&sha256_params);
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
bool gfp_crypto_sha256_update(mbedtls_sha256_context *ctx, uint8_t const *data, uint16_t data_len)
#else
bool gfp_crypto_sha256_update(uint8_t const *data, uint16_t data_len)
#endif
{
#ifdef CONFIG_SOC_FAMILY_ATM
	if (mbedtls_sha256_update(ctx, data, data_len)) {
		ATM_LOG(W, "sha256 update error");
		return false;
	}
#else
	if (atm_sha256_update_pio(data, data_len) != ATM_SHA256_RES_SUCCESS) {
		ATM_LOG(W, "atm_sha256_update_pio FAILED");
		return false;
	}
#endif
	return true;
}

#ifdef CONFIG_SOC_FAMILY_ATM
void gfp_crypto_sha256_deinit(mbedtls_sha256_context *ctx, uint8_t *out)
#else
void gfp_crypto_sha256_deinit(uint8_t *out)
#endif
{
#ifdef CONFIG_SOC_FAMILY_ATM
	if (mbedtls_sha256_finish(ctx, out)) {
		ATM_LOG(W, "sha256 finish error");
	}
	mbedtls_sha256_free(ctx);
#else
	atm_sha256_final(out);
	atm_sha256_disable();
#endif
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

#else

static int mbedtls_csrng(void *state, uint8_t *dest, unsigned size)
{
	return sys_csrand_get(dest, size);
}

static int gfp_crypto_mbedtls_public_key_size_secp256r1(void)
{
	return MBEDTLS_ECP_MAX_PT_LEN - 1;
}

static int gfp_crypto_mbedtls_private_key_size_secp256r1(void)
{
	return MBEDTLS_ECP_MAX_BYTES;
}

static int gfp_crypto_mbedtls_order_size_secp256r1(void)
{
	return MBEDTLS_ECP_MAX_BYTES;
}

static void gfp_crypto_mbedtls_vli_mmod_secp256r1(uint8_t const *data_in, uint16_t data_in_len,
						  uint8_t *data_out, uint16_t data_out_len)
{
	mbedtls_ecp_group ecp_grp;
	mbedtls_ecp_group_init(&ecp_grp);
	mbedtls_mpi mpi_in;
	mbedtls_mpi_init(&mpi_in);
	mbedtls_mpi mpi_out;
	mbedtls_mpi_init(&mpi_out);

	int rv = mbedtls_ecp_group_load(&ecp_grp, MBEDTLS_ECP_DP_SECP256R1);
	CHECK_RV_GOTO_RET(rv, cleanup, -1);
	rv = mbedtls_mpi_read_binary(&mpi_in, data_in, data_in_len);
	CHECK_RV_GOTO_RET(rv, cleanup, -2);
	rv = mbedtls_mpi_mod_mpi(&mpi_out, &mpi_in, &ecp_grp.N);
	CHECK_RV_GOTO_RET(rv, cleanup, -3);
	rv = mbedtls_mpi_write_binary(&mpi_out, data_out, data_out_len);
	CHECK_RV_GOTO_RET(rv, cleanup, -4);
	gfp_crypto_reverse_array(data_out, data_out_len);
cleanup:
	mbedtls_ecp_group_free(&ecp_grp);
	mbedtls_mpi_free(&mpi_in);
	mbedtls_mpi_free(&mpi_out);
	return;
}

static int gfp_crypto_mbedtls_compute_public_key_secp256r1(uint8_t const *private_key,
							   uint8_t *public_key)
{
	uint8_t m_public_key[MBEDTLS_ECP_MAX_PT_LEN];
	mbedtls_ecp_group ecp_grp;
	mbedtls_ecp_group_init(&ecp_grp);
	mbedtls_ecp_keypair ecp_keypair;
	mbedtls_ecp_keypair_init(&ecp_keypair);
	mbedtls_ecp_point ecp_pubkey;
	mbedtls_ecp_point_init(&ecp_pubkey);

	int rv = mbedtls_ecp_group_load(&ecp_grp, MBEDTLS_ECP_DP_SECP256R1);
	CHECK_RV_GOTO_RET(rv, cleanup, -1);
	rv = mbedtls_ecp_read_key(MBEDTLS_ECP_DP_SECP256R1, &ecp_keypair, private_key,
				  gfp_crypto_mbedtls_private_key_size_secp256r1());
	CHECK_RV_GOTO_RET(rv, cleanup, -2);
	rv = mbedtls_ecp_keypair_calc_public(&ecp_keypair, mbedtls_csrng, NULL);
	CHECK_RV_GOTO_RET(rv, cleanup, -3);
	rv = mbedtls_ecp_export(&ecp_keypair, NULL, NULL, &ecp_pubkey);
	CHECK_RV_GOTO_RET(rv, cleanup, -4);
	size_t length;
	rv = mbedtls_ecp_point_write_binary(&ecp_grp, &ecp_pubkey, MBEDTLS_ECP_PF_UNCOMPRESSED,
					    &length, m_public_key, sizeof(m_public_key));
	CHECK_RV_GOTO_RET(rv, cleanup, -4);
	memcpy(public_key, m_public_key + 1, gfp_crypto_mbedtls_public_key_size_secp256r1());
cleanup:
	mbedtls_ecp_group_free(&ecp_grp);
	mbedtls_ecp_point_free(&ecp_pubkey);
	mbedtls_ecp_keypair_free(&ecp_keypair);
	return !rv ? 1 : 0;
}

static int gfp_crypto_mbedtls_shared_secret_secp256r1(const uint8_t *public_key,
						      const uint8_t *private_key, uint8_t *secret)
{
	uint8_t m_public_key[MBEDTLS_ECP_MAX_PT_LEN];
	mbedtls_ecp_group ecp_grp;
	mbedtls_ecp_group_init(&ecp_grp);
	mbedtls_mpi mpi_secret;
	mbedtls_mpi_init(&mpi_secret);
	mbedtls_ecp_point ecp_pubkey;
	mbedtls_ecp_point_init(&ecp_pubkey);
	mbedtls_mpi ecp_privkey;
	mbedtls_mpi_init(&ecp_privkey);

	int rv = mbedtls_ecp_group_load(&ecp_grp, MBEDTLS_ECP_DP_SECP256R1);
	CHECK_RV_GOTO_RET(rv, cleanup, -1);
	m_public_key[0] = 0x04;
	memcpy(m_public_key + 1, public_key, gfp_crypto_mbedtls_public_key_size_secp256r1());
	rv = mbedtls_ecp_point_read_binary(&ecp_grp, &ecp_pubkey, m_public_key,
					   sizeof(m_public_key));
	CHECK_RV_GOTO_RET(rv, cleanup, -2);
	rv = mbedtls_mpi_read_binary(&ecp_privkey, private_key,
				     gfp_crypto_mbedtls_private_key_size_secp256r1());
	CHECK_RV_GOTO_RET(rv, cleanup, -3);
	rv = mbedtls_ecdh_compute_shared(&ecp_grp, &mpi_secret, &ecp_pubkey, &ecp_privkey,
					 mbedtls_csrng, NULL);
	CHECK_RV_GOTO_RET(rv, cleanup, -4);
	rv = mbedtls_mpi_write_binary(&mpi_secret, secret,
				      gfp_crypto_mbedtls_private_key_size_secp256r1());
	CHECK_RV_GOTO_RET(rv, cleanup, -5);
cleanup:
	mbedtls_ecp_group_free(&ecp_grp);
	mbedtls_ecp_point_free(&ecp_pubkey);
	mbedtls_mpi_free(&mpi_secret);
	mbedtls_mpi_free(&ecp_privkey);
	return !rv ? 1 : 0;
}

#endif // CONFIG_ATM_GFP_DIRECT_UECC_INTERFACE

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
	intf->shared_secret = gfp_crypto_mbedtls_shared_secret_secp256r1;
	intf->order_size = gfp_crypto_mbedtls_order_size_secp256r1;
	intf->curve_private_key_size = gfp_crypto_mbedtls_private_key_size_secp256r1;
	intf->curve_public_key_size = gfp_crypto_mbedtls_public_key_size_secp256r1;
	intf->vli_mmod = gfp_crypto_mbedtls_vli_mmod_secp256r1;
	intf->compute_public_key = gfp_crypto_mbedtls_compute_public_key_secp256r1;
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

	STATIC_ASSERT(ATM_AES_BLOCK_LEN_BYTES <= GFP_CRYPTO_AES_BLOCK_LEN_BYTES,
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
	mbedtls_sha256_context ctx;
	gfp_crypto_sha256_init(&ctx);
	gfp_crypto_sha256_update(&ctx, buf, offset);
	gfp_crypto_sha256_update(&ctx, gc->pt, gc->pt_len);
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
}
