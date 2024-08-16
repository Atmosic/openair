/**
 *******************************************************************************
 *
 * @file ecdsa_alt.c
 *
 * @brief mbedtls glue for uECC library
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/random/random.h>

static int default_RNG(uint8_t *dest, unsigned size)
{
    // use cryptographically secure rand
    return !sys_csrand_get(dest, size);
}

#define default_RNG_defined 1
#endif // CONFIG_SOC_FAMILY_ATM

#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#include "mbedtls/ecdsa.h"

#define uECC_OPTIMIZATION_LEVEL 4
#define uECC_SUPPORTS_secp160r1 0
#ifndef MBEDTLS_ECP_DP_SECP192R1_ENABLED
#define uECC_SUPPORTS_secp192r1 0
#endif
#ifndef MBEDTLS_ECP_DP_SECP224R1_ENABLED
#define uECC_SUPPORTS_secp224r1 0
#endif
#ifndef MBEDTLS_ECP_DP_SECP256R1_ENABLED
#define uECC_SUPPORTS_secp256r1 0
#endif
#ifndef MBEDTLS_ECP_DP_SECP256K1_ENABLED
#define uECC_SUPPORTS_secp256k1 0
#endif
#define uECC_SUPPORT_COMPRESSED_POINT 0

#include "uECC.c"

#ifdef MBEDTLS_ECDSA_GENKEY_ALT
int mbedtls_ecdsa_genkey(mbedtls_ecdsa_context *ctx, mbedtls_ecp_group_id gid,
    int (*f_rng)(void *, unsigned char *, size_t), void *p_rng)
{
    int ret = mbedtls_ecp_group_load(&ctx->grp, gid);
    if (ret) {
	return ret;
    }

    uECC_Curve curve;

    switch (gid) {
#ifdef MBEDTLS_ECP_DP_SECP192R1_ENABLED
	case MBEDTLS_ECP_DP_SECP192R1:
	    curve = uECC_secp192r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP224R1_ENABLED
	case MBEDTLS_ECP_DP_SECP224R1:
	    curve = uECC_secp224r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256R1_ENABLED
	case MBEDTLS_ECP_DP_SECP256R1:
	    curve = uECC_secp256r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256K1_ENABLED
	case MBEDTLS_ECP_DP_SECP256K1:
	    curve = uECC_secp256k1();
	    break;
#endif
	default:
	    return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
    }

    size_t plen = ctx->grp.nbits / 8U;
    uint8_t q_buf[plen * 2U];
    uint8_t d_buf[plen];

    if (!uECC_make_key(q_buf, d_buf, curve)) {
	return MBEDTLS_ERR_ECP_RANDOM_FAILED;
    }

    ret = mbedtls_mpi_read_binary(&ctx->d, d_buf, plen);
    if (ret) {
	return ret;
    }

    ret = mbedtls_mpi_read_binary(&(ctx->Q.X), q_buf, plen);
    if (ret) {
	return ret;
    }

    ret = mbedtls_mpi_read_binary(&(ctx->Q.Y), q_buf + plen, plen);
    if (ret) {
	return ret;
    }

    ret = mbedtls_mpi_lset(&(ctx->Q.Z), 1);
    if (ret) {
	return ret;
    }

    return 0;
}
#endif

#ifdef MBEDTLS_ECDSA_SIGN_ALT
int mbedtls_ecdsa_can_do(mbedtls_ecp_group_id gid)
{
    switch (gid) {
#ifdef MBEDTLS_ECP_DP_SECP192R1_ENABLED
	case MBEDTLS_ECP_DP_SECP192R1:
	    return 1;
#endif
#ifdef MBEDTLS_ECP_DP_SECP224R1_ENABLED
	case MBEDTLS_ECP_DP_SECP224R1:
	    return 1;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256R1_ENABLED
	case MBEDTLS_ECP_DP_SECP256R1:
	    return 1;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256K1_ENABLED
	case MBEDTLS_ECP_DP_SECP256K1:
	    return 1;
#endif
	default:
	    break;
    }

    return 0;
}

int mbedtls_ecdsa_sign(mbedtls_ecp_group *grp, mbedtls_mpi *r, mbedtls_mpi *s,
    const mbedtls_mpi *d, const unsigned char *buf, size_t blen,
    int (*f_rng)(void *, unsigned char *, size_t), void *p_rng)
{
    uECC_Curve curve;

    switch (grp->id) {
#ifdef MBEDTLS_ECP_DP_SECP192R1_ENABLED
	case MBEDTLS_ECP_DP_SECP192R1:
	    curve = uECC_secp192r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP224R1_ENABLED
	case MBEDTLS_ECP_DP_SECP224R1:
	    curve = uECC_secp224r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256R1_ENABLED
	case MBEDTLS_ECP_DP_SECP256R1:
	    curve = uECC_secp256r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256K1_ENABLED
	case MBEDTLS_ECP_DP_SECP256K1:
	    curve = uECC_secp256k1();
	    break;
#endif
	default:
	    return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
    }

    size_t plen = grp->nbits / 8U;
    uint8_t d_buf[plen];
    uint8_t sig_buf[plen * 2U];

    int ret = mbedtls_mpi_write_binary(d, d_buf, plen);
    if (ret) {
	return ret;
    }

    if (!uECC_sign(d_buf, buf, blen, sig_buf, curve)) {
	return MBEDTLS_ERR_ECP_RANDOM_FAILED;
    }

    ret = mbedtls_mpi_read_binary(r, sig_buf, plen);
    if (ret) {
	return ret;
    }

    ret = mbedtls_mpi_read_binary(s, sig_buf + plen, plen);
    if (ret) {
	return ret;
    }

    return 0;
}
#endif // MBEDTLS_ECDSA_SIGN_ALT

#ifdef MBEDTLS_ECDSA_VERIFY_ALT
int mbedtls_ecdsa_verify(mbedtls_ecp_group *grp, const unsigned char *buf,
    size_t blen, const mbedtls_ecp_point *Q, const mbedtls_mpi *r,
    const mbedtls_mpi *s)
{
    uECC_Curve curve;

    switch (grp->id) {
#ifdef MBEDTLS_ECP_DP_SECP192R1_ENABLED
	case MBEDTLS_ECP_DP_SECP192R1:
	    curve = uECC_secp192r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP224R1_ENABLED
	case MBEDTLS_ECP_DP_SECP224R1:
	    curve = uECC_secp224r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256R1_ENABLED
	case MBEDTLS_ECP_DP_SECP256R1:
	    curve = uECC_secp256r1();
	    break;
#endif
#ifdef MBEDTLS_ECP_DP_SECP256K1_ENABLED
	case MBEDTLS_ECP_DP_SECP256K1:
	    curve = uECC_secp256k1();
	    break;
#endif
	default:
	    return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
    }

    size_t plen = grp->nbits / 8U;
    uint8_t q_buf[plen * 2U];
    uint8_t sig_buf[plen * 2U];

    int ret = mbedtls_mpi_write_binary(&(Q->X), q_buf, plen);
    if (ret) {
	return ret;
    }

    ret = mbedtls_mpi_write_binary(&(Q->Y), q_buf + plen, plen);
    if (ret) {
	return ret;
    }

    ret = mbedtls_mpi_write_binary(r, sig_buf, plen);
    if (ret) {
	return ret;
    }

    ret = mbedtls_mpi_write_binary(s, sig_buf + plen, plen);
    if (ret) {
	return ret;
    }

    if (!uECC_verify(q_buf, buf, blen, sig_buf, curve)) {
	return MBEDTLS_ERR_ECP_VERIFY_FAILED;
    }

    return 0;
}
#endif // MBEDTLS_ECDSA_VERIFY_ALT
