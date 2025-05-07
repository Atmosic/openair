/**
 *******************************************************************************
 *
 * @file gfp_crypto.h
 *
 * @brief Atmosic Google Fast Pair Secure Crypto Middleware
 * This secure Crypto Middleware for Google Fast Pair with mbedtls/uECC.
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h" // __NORETURN inline functions

/**
 * @defgroup ATM_BTFM_GFPCRYPTO Atmosic Google fast pair API
 * @ingroup ATM_BTFM_API
 * @brief ATM bluetooth framework Google fast pair API
 *
 * This module contains the necessary API to create service through Google
 * Fast Pair of Atmosic
 *
 * @{
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include "mbedtls/ecdsa.h"
#include "mbedtls/aes.h"
#include "mbedtls/sha256.h"
#else
#include "atm_aes.h"
#include "atm_sha2.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
#ifndef ATM_AES_BLOCK_LEN_BYTES
#define ATM_AES_BLOCK_LEN_BYTES 16
#endif
#ifndef SHA256_DIG_LEN
#define SHA256_DIG_LEN 32
#endif
#ifndef GFP_CRYPTO_ACTK_LEN
#define GFP_CRYPTO_ACTK_LEN 16
#endif

/// ATM AES Key length
typedef enum {
	/// 128-bit key length
	ATM_AES_KEY_LEN_128 = 16,
	/// 256-bit key length
	ATM_AES_KEY_LEN_256 = 32,
} atm_aes_key_len_t;
#endif

/// AES block length in bytes
#define GFP_CRYPTO_AES_BLOCK_LEN_BYTES ATM_AES_BLOCK_LEN_BYTES
/// ShA256 Digest length
#define GFP_CRYPTO_SHA256_DIG_LEN      SHA256_DIG_LEN
/// Anti-Spoofing AES key length
#define GFP_CRYPTO_AS_AES_KEY_LEN      16
/// The nonce length of HMAC-SHA256/AES-CTR
#define GFP_CRYPTO_HMAC_NONCE_LEN      8
/// The secret key size of GFPS
#define GFP_CRYPTO_HMAC_SECRET_KEY_LEN 16

/// AES ECB Type
typedef enum {
	/// AES ECB 128
	GFP_CRYPTO_AES_ECB_128,
	// AES ECB 256
	GFP_CRYPTO_AES_ECB_256,
} gfp_crypto_aes_ecb_type_t;

/// ecp curve interfaces
typedef struct gfp_crypto_ecp_curve_intf_s {
	/// shared secret api
	int (*shared_secret)(const uint8_t *public_key, const uint8_t *private_key,
			     uint8_t *secret);
	/// get uECC order size
	int (*order_size)(void);
	/// get uECC curve private key size
	int (*curve_private_key_size)(void);
	/// get uECC curve public key size
	int (*curve_public_key_size)(void);
	/// uECC vli mmod api
	void (*vli_mmod)(uint8_t const *data_in, uint16_t data_in_len, uint8_t *data_out,
			 uint16_t data_out_len);
	/// uECC compute public key
	int (*compute_public_key)(uint8_t const *private_key, uint8_t *public_key);
} gfp_crypto_ecp_curve_intf_t;

/**
 * @brief AES_ECB encrypt
 * @param[out] enc_data encrypted data
 * @param[in] data to be encrypted data
 * @param[in] data_len length of to be encrypted data
 * @param[in] key encryption key
 * @param[in] type #gfp_crypto_aes_ecb_type_t value enum
 *
 * @return true if succeed
 */
__NONNULL_ALL
bool gfp_crypto_aes_ecb_enc(uint8_t *enc_data, uint8_t const *data, uint16_t data_len,
			    uint8_t const *key, gfp_crypto_aes_ecb_type_t type);

/**
 * @brief AES_ECB decrypt
 * @param[out] dec_data decrypted data
 * @param[in] data data to be decrypted
 * @param[in] data_len length of to be decrypted data
 * @param[in] key decryption key
 * @param[in] type #gfp_crypto_aes_ecb_type_t value enum
 *
 * @return true if succeed
 */
__NONNULL_ALL
bool gfp_crypto_aes_ecb_dec(uint8_t *dec_data, uint8_t const *data, uint16_t data_len,
			    uint8_t const *key, gfp_crypto_aes_ecb_type_t type);

/**
 * @brief Perform SHA-256 calculation on single contiguous memory chunk using
 * @param[in] data_in data to be crypto hashed
 * @param[in] data_len data length of be crypto hashed
 * @param[in] data_out digest of SHA256 calculation
 *
 * @return true if succeed
 */
__NONNULL_ALL
bool gfp_crypto_sha256(uint8_t const *data_in, uint16_t data_len, uint8_t *data_out);

/**
 * @brief Perform HMAC SHA-256 calculation on single contiguous memory chunk
 * using
 * @param[in] data_in data to be crypto hashed
 * @param[in] data_len data length of be crypto hashed
 * @param[in] data_out digest of SHA256 calculation
 * @param[in] key key of HMAC SHA256
 * @param[in] key_len length of key
 *
 * @return true if succeed
 */
__NONNULL_ALL
bool gfp_crypto_hmac_sha256(uint8_t const *data_in, uint16_t data_len, uint8_t *data_out,
			    uint8_t const *key, uint16_t key_len);

#ifdef CONFIG_SOC_FAMILY_ATM
/**
 * @brief Initialize SHA-256 module
 * @param[in] ctx mbedtls sha256 context
 */
__NONNULL_ALL
void gfp_crypto_sha256_init(mbedtls_sha256_context *ctx);
#else
/**
 * @brief Initialize SHA-256 module
 */
void gfp_crypto_sha256_init(void);
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
/**
 * @brief Initialize HMAC SHA-256 module
 * @param[in] ctx mbedtls md context
 * @param[in] key key of HMAC SHA256
 * @param[in] key_len length of key
 *
 * @return true if succeed
 */
__NONNULL_ALL
bool gfp_crypto_hmac_sha256_init(mbedtls_md_context_t *ctx, uint8_t const *key, uint16_t key_len);
#else
/**
 * @brief Initialize HMAC SHA-256 module
 * @param[in] key key of HMAC SHA256
 * @param[in] key_len length of key
 */
__NONNULL_ALL
void gfp_crypto_hmac_sha256_init(uint8_t const *key, uint16_t key_len);
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
/**
 * @brief Stream more input data for an on-going SHA-256 calculation
 * @param[in] ctx mbedtls md context
 * @param[in] data data to be crypto hashed
 * @param[in] data_len data length of be crypto hashed
 *
 * @return true if succeed
 */
__NONNULL_ALL
bool gfp_crypto_sha256_update(mbedtls_sha256_context *ctx, uint8_t const *data, uint16_t data_len);
#else
/**
 * @brief Stream more input data for an on-going SHA-256 calculation
 * @param[in] data data to be crypto hashed
 * @param[in] data_len data length of be crypto hashed
 *
 * @return true if succeed
 */
__NONNULL_ALL
bool gfp_crypto_sha256_update(uint8_t const *data, uint16_t data_len);
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
/**
 * @brief de-initialize SHA256 module
 * @param[in] ctx mbedtls md context
 * @param[out] out digest of SHA256 calculation
 */
__NONNULL_ALL
void gfp_crypto_sha256_deinit(mbedtls_sha256_context *ctx, uint8_t *out);
#else
/**
 * @brief de-initialize SHA256 module
 * @param[out] out digest of SHA256 calculation
 */
__NONNULL_ALL
void gfp_crypto_sha256_deinit(uint8_t *out);
#endif

/**
 * @brief array reverse
 * @param[in] array array to be reversed
 * @param[in] length length of array
 */
__NONNULL_ALL
void gfp_crypto_reverse_array(uint8_t *array, size_t length);

#ifdef CONFIG_ATM_GFP_DIRECT_UECC_INTERFACE
/**
 * @brief get uECC secp160r1 interface
 * @param[out] intf uECC secp160r1 interface
 */
__NONNULL_ALL
void gfp_crypto_ecp_curve_intf_secp160r1(gfp_crypto_ecp_curve_intf_t *intf);
#endif

/**
 * @brief get uECC secp256r1 interface
 * @param[out] intf uECC secp256r1 interface
 */
__NONNULL_ALL
void gfp_crypto_ecp_curve_intf_secp256r1(gfp_crypto_ecp_curve_intf_t *intf);

/// The context of generate account key filter for Google fast pair
typedef struct {
	/// Account key number
	uint8_t acct_key_num;
	/// Account key list
	uint8_t const *acct_key_list;
	/// Salt
	uint16_t salt;
	/// Battery data length
	uint8_t batt_data_len;
	/// Battery data
	uint8_t const *batt_data;
} gfp_crypto_acct_key_fl_ctx_t;

/// Store the account key filter information
typedef struct {
	/// Maximum account keys
	uint8_t max_data_len;
	/// Store account key filter
	uint8_t *data;
} gfp_crypto_acct_key_fl_info_t;

/**
 * @brief Get account key filter size
 * @param[in] n Account key number
 *
 * @return Length of account key filter size
 */
size_t gfp_crypto_acct_key_filter_size(size_t n);

/**
 * @brief Generate account key filter
 * @param[in] info Account key filter information
 * @param[in] salt Salt
 * @param[in] bati Battery information
 * @param[in] batl The length of battery information
 * @param[in] ctx The context for unit test
 *
 * @return true if succeed
 */
__NONNULL(1)
bool gfp_crypto_acct_key_fl_gen(gfp_crypto_acct_key_fl_info_t *info, uint16_t salt,
				uint8_t const *bati, uint8_t batl, void const *ctx);

typedef struct {
	/// Plaintext
	uint8_t const *pt;
	/// Plaintext length
	uint16_t pt_len;
	/// Security key
	uint8_t const *secret_key;
	/// Nonce
	uint8_t const *nonce;
} gfp_crypto_aes_ctr_ctx_t;

/**
 * @brief Encrypt data using AES-CTR
 * @param[out] ct Cipertext
 * @param[in] ct_len The length of cipertext
 * @param[in] gac The context for AES-CTR
 *
 * @return true if successful
 */
__NONNULL(1, 3)
bool gfp_crypto_aes_ctr(uint8_t *ct, uint16_t ct_len, gfp_crypto_aes_ctr_ctx_t const *gac);

/**
 * @brief Encrypt data using AES-CTR
 * @param[out] ct Cipertext
 * @param[in] ct_len The length of cipertext
 * @param[in] gac The context for AES-CTR
 *
 * @return true if successful
 */
__NONNULL(1, 3)
bool gfp_crypto_aes_ctr_dec(uint8_t *ct, uint16_t ct_len, gfp_crypto_aes_ctr_ctx_t const *gac);

typedef struct {
	/// Plaintext
	uint8_t const *pt;
	/// Plaintext length
	uint16_t pt_len;
	/// Security key
	uint8_t const *secret_key;
	/// Security key length
	uint16_t secret_key_len;
	/// Nonce
	uint8_t const *nonce;
} gfp_crypto_ctx_t;

/**
 * @brief Encrypt data using SHA256
 * @param[out] ct Cipertext
 * @param[in] ct_len The length of cipertext
 * @param[in] gc The context for crypto for GPFS
 *
 * @return true if successful
 */
__NONNULL(1, 3)
bool gfp_crypto_gfps_hmac_sha256(uint8_t *ct, uint16_t ct_len, gfp_crypto_ctx_t const *gc);

#ifdef __cplusplus
}
#endif

///@}
