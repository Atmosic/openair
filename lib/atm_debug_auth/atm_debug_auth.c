/**
 *******************************************************************************
 *
 * @file atm_debug_auth.c
 *
 * @brief Secure debug authentication library
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */
#include "arch.h"
#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/sys/base64.h>
#else
#include "atm_base64.h"
#include "timer.h"
#endif
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "atm_sha2.h"
#include "atm_debug_auth.h"
#include "sec_assert.h"
#include "uECC.h"

#ifdef DEBUG_AUTH_STATIC_CHALLENGE
#include "sec_jrnl.h"
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_ATM_SEC_COUNTER)
#include "sec_counter.h"
// counter value will be included in the static challenge
#define STATIC_CHALLENGE_INCLUDE_SEC_CTR
#endif // !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_ATM_SEC_COUNTER)
#ifdef CONFIG_SOC_FAMILY_ATM
#define SEC_JRNL_START DT_REG_ADDR(DT_NODELABEL(sec_jrnl))
#define SEC_JRNL_SIZE DT_REG_SIZE(DT_NODELABEL(sec_jrnl))
#else
#define SEC_JRNL_START 0x1008f800
#define SEC_JRNL_SIZE 1776
#endif // CONFIG_SOC_FAMILY_ATM
#endif // DEBUG_AUTH_STATIC_CHALLENGE

#define CHALLENGE_WORDS 16
#define ENCODED_CHALLENGE_LEN \
    atm_debug_auth_b64_encode_len(CHALLENGE_WORDS * sizeof(uint32_t))
#define ECC_BYTES 32
#define ECC_SIG_SIZE (ECC_BYTES * 2)
#define ECC_KEY_SIZE (ECC_BYTES * 2)
#define ENCODED_SIG_LEN atm_debug_auth_b64_encode_len(ECC_BYTES * 2)
#define OUT_BUF_SIZE 150

#define INITIAL_ENTROPY_WORDS (SHA256_DIG_WORDS * 3 / 2)
#define CHECK_SHA_OP(cond) \
    do { \
	if (!(cond)) { \
	    atm_sha256_disable(); \
	    SEC_ASSERT(false); \
	} \
    } while (0)

#define SHELL_PREFIX "DBG "
#define SHELL_PREFIX_LEN (sizeof(SHELL_PREFIX) - 1)
#define SHELL_COMMAND(_cmd, _handler) \
    { \
	.command = #_cmd, .command_len = sizeof(#_cmd) - 1, \
	.handler = _handler \
    }

typedef struct {
    char const *command;
    size_t const command_len;
    atm_debug_auth_result_t (*handler)(char const *, size_t const);
} handler_entry_t;

static char uart_buf[OUT_BUF_SIZE];
static uint8_t const *public_key;
static bool unlocked;
static bool stay_in_serial;
static debug_write_t uart_write_cb;
#ifdef DEBUG_AUTH_STATIC_CHALLENGE
static uint8_t static_challenge[SHA256_DIG_LEN];
static bool static_challenge_valid;
#else
static debug_trng_get_t trng_get_entropy_cb;
static uint8_t hmac_key[HMAC_KEY_LEN];
static uint8_t hmac_value[SHA256_DIG_LEN];
static size_t output_left;
static size_t reseed;
static uint32_t challenge[CHALLENGE_WORDS];
static bool challenge_valid;
#endif

static inline int atm_debug_auth_b64_encode_len(size_t len)
{
#ifdef CONFIG_SOC_FAMILY_ATM
    int encode_len;
    base64_encode(NULL, 0, &encode_len, NULL, len);
    return encode_len;
#else
    return atm_base64_encode_len(len);
#endif
}

/**
 * @brief Encode data in base64 format
 * @param[in] input pointer to input buffer
 * @param[in] input_len size of input
 * @param[out] output pointer to output base64 buffer
 * @param[in] output_len size of output base64 buffer, including null terminator
 * @return number of bytes encoded, or negative on error
 */
static inline int atm_debug_auth_b64_encode(const void *input,
    const size_t input_len, char *output, const size_t output_len)
{
#ifdef CONFIG_SOC_FAMILY_ATM
    size_t olen;
    int ret = base64_encode(output, output_len, &olen, input, input_len);
    // base64_encode returns 0 on success
    if (ret < 0) {
	return ret;
    }
    return olen;
#else
    return atm_base64_encode(input, input_len, output, output_len);
#endif
}

/**
 * @brief Decode data in base64 format
 * @param[in] input pointer to input buffer
 * @param[in] input_len size of input
 * @param[out] output pointer to output base64 buffer
 * @param[in] output_len size of output base64 buffer, including null terminator
 * @return number of bytes decoded, or negative on error
 */
static inline int atm_debug_auth_b64_decode(const void *input,
    const size_t input_len, char *output, const size_t output_len)
{
#ifdef CONFIG_SOC_FAMILY_ATM
    size_t olen;
    int ret = base64_decode(output, output_len, &olen, input, input_len);
    if (ret < 0) {
	return ret;
    }
    return olen;
#else
    return atm_base64_decode(input, input_len, output, output_len);
#endif
}

#ifndef DEBUG_AUTH_STATIC_CHALLENGE
static void hmac_drbg_update(uint8_t const *seed, size_t const seed_len)
{
    atm_sha256_params_t params = {
	.mode = ATM_SHA256_HMAC_MODE,
	.key = (uint8_t *)hmac_key,
    };
    uint8_t byte = 0;
    // first update key with an HMAC of (key, (value bytes, single 0 byte, seed
    // bytes (if extant)))
    CHECK_SHA_OP(atm_sha256_init(&params) == ATM_SHA256_RES_SUCCESS);
    CHECK_SHA_OP(atm_sha256_update_pio(hmac_value, SHA256_DIG_LEN) ==
	ATM_SHA256_RES_SUCCESS);
    CHECK_SHA_OP(atm_sha256_update_pio(&byte, 1) == ATM_SHA256_RES_SUCCESS);
    if (seed) {
	CHECK_SHA_OP(
	    atm_sha256_update_pio(seed, seed_len) == ATM_SHA256_RES_SUCCESS);
    }
    atm_sha256_final(hmac_key);
    atm_sha256_disable();
    // second update value with an HMAC of (key, value bytes)
    CHECK_SHA_OP(atm_sha256_init(&params) == ATM_SHA256_RES_SUCCESS);
    CHECK_SHA_OP(atm_sha256_update_pio(hmac_value, SHA256_DIG_LEN) ==
	ATM_SHA256_RES_SUCCESS);
    atm_sha256_final(hmac_value);
    atm_sha256_disable();
    if (seed) {
	// third update key with an HMAC of (key, (value bytes, single 1 bytes,
	// seed bytes))
	CHECK_SHA_OP(atm_sha256_init(&params) == ATM_SHA256_RES_SUCCESS);
	CHECK_SHA_OP(atm_sha256_update_pio(hmac_value, SHA256_DIG_LEN) ==
	    ATM_SHA256_RES_SUCCESS);
	byte = 1;
	CHECK_SHA_OP(atm_sha256_update_pio(&byte, 1) == ATM_SHA256_RES_SUCCESS);
	CHECK_SHA_OP(
	    atm_sha256_update_pio(seed, seed_len) == ATM_SHA256_RES_SUCCESS);
	atm_sha256_final(hmac_key);
	atm_sha256_disable();
	// fourth update value with an HMAC of (key, value bytes)
	CHECK_SHA_OP(atm_sha256_init(&params) == ATM_SHA256_RES_SUCCESS);
	CHECK_SHA_OP(atm_sha256_update_pio(hmac_value, SHA256_DIG_LEN) ==
	    ATM_SHA256_RES_SUCCESS);
	atm_sha256_final(hmac_value);
	atm_sha256_disable();
    }
    reseed = 0x1000000;
    output_left = SHA256_DIG_LEN;
}

static void hmac_drbg_reseed(void)
{
    uint32_t entropy[INITIAL_ENTROPY_WORDS];
    for (size_t i = 0; i < INITIAL_ENTROPY_WORDS; i++) {
	entropy[i] = trng_get_entropy_cb();
    }
    hmac_drbg_update((uint8_t *)entropy,
	INITIAL_ENTROPY_WORDS * sizeof(uint32_t));
}

static void hmac_drbg_init(void)
{
    memset(hmac_key, 0, HMAC_KEY_LEN);
    memset(hmac_value, 1, SHA256_DIG_LEN);
    hmac_drbg_reseed();
}

static void hmac_drbg_generate(void *buf, size_t len)
{
    size_t offset = 0;
    while (offset < len) {
	if (output_left) {
	    size_t copy_len = len > output_left ? output_left : len;
	    memcpy((uint8_t *)buf + offset,
		hmac_value + SHA256_DIG_LEN - output_left, copy_len);
	    output_left -= copy_len;
	    offset += copy_len;
	} else {
	    if (reseed > SHA256_DIG_LEN) {
		hmac_drbg_update(NULL, 0);
		output_left = SHA256_DIG_LEN;
		reseed -= SHA256_DIG_LEN;
	    } else {
		hmac_drbg_reseed();
	    }
	}
    }
}
#endif

static void output_response(char const *fmt, ...)
{
    if (uart_write_cb) {
	va_list args;
	va_start(args, fmt);
	int res = vsnprintf(uart_buf, sizeof(uart_buf), fmt, args);
	va_end(args);
	if (res > 0) {
	    uart_write_cb(uart_buf, res);
	}
    }
}

#ifndef DEBUG_AUTH_STATIC_CHALLENGE
static bool generate_challenge(void)
{
    hmac_drbg_generate(challenge, CHALLENGE_WORDS * sizeof(uint32_t));
    challenge_valid = true;
    return true;
}
#endif

static bool check_signature(uint8_t const *signature, void const *chall,
    size_t const chall_len)
{
    bool result = false;
    // hash the challenge
    uint8_t digest[SHA256_DIG_LEN];
    atm_sha256_params_t sha_params = {.mode = ATM_SHA256_SHA_MODE,
	.byte_endianess = ATM_SHA256_ENDIANESS_BIG,
	.digest_endianess = ATM_SHA256_ENDIANESS_BIG};
    if (atm_sha256_init(&sha_params) != ATM_SHA256_RES_SUCCESS) {
	atm_sha256_final(digest);
	goto cleanup;
    }
    if (atm_sha256_update_pio(chall, chall_len) != ATM_SHA256_RES_SUCCESS) {
	atm_sha256_final(digest);
	goto cleanup;
    }
    atm_sha256_final(digest);

    result = uECC_verify(public_key, digest, SHA256_DIG_LEN, signature,
	uECC_secp256r1());
cleanup:
    atm_sha256_disable();
    return result;
}

static atm_debug_auth_result_t status_handler(__UNUSED char const *args,
    __UNUSED size_t const length)
{
    if (unlocked) {
	output_response("Debug unlocked\n");
    } else {
	output_response("Debug locked\n");
    }
    return ATM_DEBUG_AUTH_RESULT_OK;
}

#ifndef DEBUG_AUTH_STATIC_CHALLENGE
static atm_debug_auth_result_t request_handler(__UNUSED char const *args,
    __UNUSED size_t const length)
{
    // always generate a new challenge
    if (!generate_challenge()) {
	output_response("Internal failure\n");
	return ATM_DEBUG_AUTH_RESULT_INTERNAL_FAILURE;
    }
    char b64_challenge[atm_debug_auth_b64_encode_len(
	CHALLENGE_WORDS * sizeof(uint32_t))];
    atm_debug_auth_b64_encode(challenge, CHALLENGE_WORDS * sizeof(uint32_t),
	b64_challenge, ENCODED_CHALLENGE_LEN);
    output_response("Challenge: %s\n", b64_challenge);
    return ATM_DEBUG_AUTH_RESULT_OK;
}
#endif

#ifdef DEBUG_AUTH_STATIC_CHALLENGE
static void generate_static_challenge(void)
{
    // start sha enginge
    // for each area in static_challenge, add to sha engine
    bool success = true;
    atm_sha256_params_t sha_params = {.mode = ATM_SHA256_SHA_MODE,
	.byte_endianess = ATM_SHA256_ENDIANESS_BIG,
	.digest_endianess = ATM_SHA256_ENDIANESS_BIG};
    success =
	success && (atm_sha256_init(&sha_params) == ATM_SHA256_RES_SUCCESS);
    // don't sha the first word of ROM to avoid a null pointer compile time
    // error
    success = success &&
	(atm_sha256_update_pio((void *)(CMSDK_FLASH_BASE + sizeof(uint32_t)),
	     ROM_SIZE - sizeof(uint32_t)) == ATM_SHA256_RES_SUCCESS);
    success = success &&
	(atm_sha256_update_pio((void *)SEC_JRNL_START, SEC_JRNL_SIZE) ==
	    ATM_SHA256_RES_SUCCESS);

#ifdef STATIC_CHALLENGE_INCLUDE_SEC_CTR
    uint16_t counter;
#ifdef SECURE_MODE
    success = success && (sec_counter_read(7, &counter) == SEC_CNTR_OK);
#else
    success = success && (nsc_sec_counter_read(7, &counter) == SEC_CNTR_OK);
#endif
    success = success &&
	(atm_sha256_update_pio(&counter, sizeof(uint16_t)) ==
	    ATM_SHA256_RES_SUCCESS);
#endif // STATIC_CHALLENGE_INCLUDE_SEC_CTR

    if (success) {
	atm_sha256_final(static_challenge);
	static_challenge_valid = true;
    }
    atm_sha256_disable();
}

static atm_debug_auth_result_t static_request_handler(__UNUSED char const *args,
    __UNUSED size_t const length)
{
    // always generate a new challenge
    if (!static_challenge_valid) {
	generate_static_challenge();
    }
    if (static_challenge_valid) {
	char b64_challenge[atm_debug_auth_b64_encode_len(SHA256_DIG_LEN)];
	atm_debug_auth_b64_encode(static_challenge, SHA256_DIG_LEN,
	    b64_challenge, atm_debug_auth_b64_encode_len(SHA256_DIG_LEN));
	output_response("Static Challenge: %s\n", b64_challenge);
	return ATM_DEBUG_AUTH_RESULT_OK;
    } else {
	output_response("Internal failure\n");
	return ATM_DEBUG_AUTH_RESULT_INTERNAL_FAILURE;
    }
}

static atm_debug_auth_result_t static_response_handler(char const *arguments,
    size_t const length)
{
    uint8_t signature[ECC_SIG_SIZE];
    size_t sig_len = strcspn(arguments, " \r\n");
    int decoded_len = atm_debug_auth_b64_decode(arguments, sig_len,
	(char *)signature, ECC_SIG_SIZE);
    if (decoded_len != ECC_SIG_SIZE) {
	output_response("Signature decode bad\n");
	return ATM_DEBUG_AUTH_RESULT_FAILURE;
    }
    if (!static_challenge_valid) {
	generate_static_challenge();
    }
    if (!static_challenge_valid) {
	output_response("Internal failure\n");
	return ATM_DEBUG_AUTH_RESULT_INTERNAL_FAILURE;
    }
    if (check_signature(signature, static_challenge, SHA256_DIG_LEN)) {
	output_response("Debug unlocked\n");
	unlocked = true;
	return ATM_DEBUG_AUTH_RESULT_AUTHENTICATED;
    } else {
	output_response("Bad signature\n");
	return ATM_DEBUG_AUTH_RESULT_FAILURE;
    }
}
#else

static atm_debug_auth_result_t response_handler(char const *arguments,
    size_t const length)
{
    uint8_t signature[ECC_SIG_SIZE];
    size_t sig_len = strcspn(arguments, " \r\n");
    int decoded_len = atm_debug_auth_b64_decode(arguments, sig_len,
	(char *)signature, ECC_SIG_SIZE);
    if (decoded_len != ECC_SIG_SIZE) {
	output_response("Signature decode bad\n");
	return ATM_DEBUG_AUTH_RESULT_FAILURE;
    }
    if (challenge_valid &&
	check_signature(signature, challenge,
	    CHALLENGE_WORDS * sizeof(uint32_t))) {
	output_response("Debug unlocked\n");
	unlocked = true;
	return ATM_DEBUG_AUTH_RESULT_AUTHENTICATED;
    } else {
	output_response("Bad signature\n");
	challenge_valid = false;
	return ATM_DEBUG_AUTH_RESULT_FAILURE;
    }
}
#endif

static const handler_entry_t handlers[] = {
    SHELL_COMMAND(STATUS, status_handler),
#ifdef DEBUG_AUTH_STATIC_CHALLENGE
    SHELL_COMMAND(REQUEST, static_request_handler),
    SHELL_COMMAND(STATIC_RESPONSE, static_response_handler),
#else
    SHELL_COMMAND(REQUEST, request_handler),
    SHELL_COMMAND(RESPONSE, response_handler),
#endif
};

void atm_debug_auth_init(uint8_t const *key, debug_write_t write_cb
#ifndef DEBUG_AUTH_STATIC_CHALLENGE
    , debug_trng_get_t trng_get_cb
#endif
)
{
    public_key = key;
    uart_write_cb = write_cb;
#ifndef DEBUG_AUTH_STATIC_CHALLENGE
    trng_get_entropy_cb = trng_get_cb;
    hmac_drbg_init();
#endif
}

atm_debug_auth_result_t atm_debug_auth_parse(char const *input,
    size_t const length)
{
    atm_debug_auth_result_t ret = ATM_DEBUG_AUTH_RESULT_INVALID;
    bool valid_command = false;
    if (length > SHELL_PREFIX_LEN &&
	!strncmp(input, SHELL_PREFIX, SHELL_PREFIX_LEN)) {
	char const *command = input + SHELL_PREFIX_LEN;
	size_t command_len = strcspn(command, " \r\n");
	for (size_t i = 0; i < sizeof(handlers) / sizeof(handlers[0]); i++) {
	    // only test strncmp if the length is a match
	    if (command_len == handlers[i].command_len) {
		// Don't compare delimiter/newline char
		if (strncmp(command, handlers[i].command, command_len - 1) ==
		    0) {
		    // pass args, don't include delimiter
		    valid_command = true;
		    stay_in_serial = true;
		    ret = handlers[i].handler(command + command_len + 1,
			length - command_len - 1);
		    break;
		}
	    }
	}
	if (!valid_command) {
	    output_response("Unknown command\n");
	}
    }
    return ret;
}
