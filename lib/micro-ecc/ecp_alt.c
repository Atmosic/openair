/**
 *******************************************************************************
 *
 * @file ecp_alt.c
 *
 * @brief Lightweight ECP implementation backed by micro-ecc (uECC).
 *
 * Provides the mbedTLS ECP functions that are compiled out when
 * MBEDTLS_ECP_ALT is defined.  Only short-Weierstrass curves
 * supported by uECC (secp192r1 / secp224r1 / secp256r1 / secp256k1)
 * are handled; everything else returns MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE.
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#include "mbedtls/ecp.h"
#include "mbedtls/error.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#include <zephyr/sys/util.h>
#include "uECC.h"

/* ------------------------------------------------------------------ */
/*  Constants                                                         */
/* ------------------------------------------------------------------ */

/** Uncompressed point format indicator (0x04) per SEC1 §2.3.3 */
#define ECP_POINT_FORMAT_UNCOMPRESSED 0x04

/** Offset of point format byte in binary representation */
#define ECP_POINT_FORMAT_OFFSET 0

/** Size of point format header in bytes */
#define ECP_POINT_HEADER_SIZE 1

/** Number of coordinates in an affine point (X, Y) */
#define ECP_AFFINE_COORDS 2

/** Z coordinate value for affine representation */
#define ECP_AFFINE_Z_VALUE 1

/* ------------------------------------------------------------------ */
/*  Curve helpers                                                     */
/* ------------------------------------------------------------------ */

static uECC_Curve grp_id_to_curve(mbedtls_ecp_group_id id)
{
	switch (id) {
#ifdef MBEDTLS_ECP_DP_SECP192R1_ENABLED
	case MBEDTLS_ECP_DP_SECP192R1:
		return uECC_secp192r1();
#endif
#ifdef MBEDTLS_ECP_DP_SECP224R1_ENABLED
	case MBEDTLS_ECP_DP_SECP224R1:
		return uECC_secp224r1();
#endif
#ifdef MBEDTLS_ECP_DP_SECP256R1_ENABLED
	case MBEDTLS_ECP_DP_SECP256R1:
		return uECC_secp256r1();
#endif
#ifdef MBEDTLS_ECP_DP_SECP256K1_ENABLED
	case MBEDTLS_ECP_DP_SECP256K1:
		return uECC_secp256k1();
#endif
	default:
		return NULL;
	}
}

/* ------------------------------------------------------------------ */
/*  Group                                                             */
/* ------------------------------------------------------------------ */

void mbedtls_ecp_group_init(mbedtls_ecp_group *grp)
{
	if (grp) {
		memset(grp, 0, sizeof(*grp));
	}
}

void mbedtls_ecp_group_free(mbedtls_ecp_group *grp)
{
	if (grp) {
		mbedtls_mpi_free(&grp->A);
		mbedtls_platform_zeroize(grp, sizeof(*grp));
	}
}

int mbedtls_ecp_group_load(mbedtls_ecp_group *grp, mbedtls_ecp_group_id id)
{
	uECC_Curve curve = grp_id_to_curve(id);
	if (!curve) {
		return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
	}
	grp->id = id;
	grp->pbits = (size_t)uECC_curve_private_key_size(curve) * BITS_PER_BYTE;
	grp->nbits = grp->pbits;
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Point                                                             */
/* ------------------------------------------------------------------ */

void mbedtls_ecp_point_init(mbedtls_ecp_point *pt)
{
	mbedtls_mpi_init(&pt->X);
	mbedtls_mpi_init(&pt->Y);
	mbedtls_mpi_init(&pt->Z);
}

void mbedtls_ecp_point_free(mbedtls_ecp_point *pt)
{
	if (!pt) {
		return;
	}
	mbedtls_mpi_free(&pt->X);
	mbedtls_mpi_free(&pt->Y);
	mbedtls_mpi_free(&pt->Z);
}

int mbedtls_ecp_point_read_binary(const mbedtls_ecp_group *grp, mbedtls_ecp_point *P,
				  const unsigned char *buf, size_t ilen)
{
	size_t plen = grp->pbits / BITS_PER_BYTE;

	if (ilen != ECP_POINT_HEADER_SIZE + ECP_AFFINE_COORDS * plen ||
	    buf[ECP_POINT_FORMAT_OFFSET] != ECP_POINT_FORMAT_UNCOMPRESSED) {
		return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
	}

	int ret = mbedtls_mpi_read_binary(&P->X, buf + ECP_POINT_HEADER_SIZE, plen);
	if (ret) {
		return ret;
	}

	ret = mbedtls_mpi_read_binary(&P->Y, buf + ECP_POINT_HEADER_SIZE + plen, plen);
	if (ret) {
		return ret;
	}

	return mbedtls_mpi_lset(&P->Z, ECP_AFFINE_Z_VALUE);
}

int mbedtls_ecp_check_pubkey(const mbedtls_ecp_group *grp, const mbedtls_ecp_point *pt)
{
	uECC_Curve curve = grp_id_to_curve(grp->id);
	if (!curve) {
		return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
	}

	size_t plen = grp->pbits / BITS_PER_BYTE;
	uint8_t q_buf[plen * ECP_AFFINE_COORDS];

	int ret = mbedtls_mpi_write_binary(&pt->X, q_buf, plen);
	if (ret) {
		return ret;
	}

	ret = mbedtls_mpi_write_binary(&pt->Y, q_buf + plen, plen);
	if (ret) {
		return ret;
	}

	if (!uECC_valid_public_key(q_buf, curve)) {
		return MBEDTLS_ERR_ECP_INVALID_KEY;
	}
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Keypair                                                           */
/* ------------------------------------------------------------------ */

void mbedtls_ecp_keypair_init(mbedtls_ecp_keypair *key)
{
	mbedtls_ecp_group_init(&key->grp);
	mbedtls_mpi_init(&key->d);
	mbedtls_ecp_point_init(&key->Q);
}

void mbedtls_ecp_keypair_free(mbedtls_ecp_keypair *key)
{
	if (!key) {
		return;
	}
	mbedtls_ecp_group_free(&key->grp);
	mbedtls_mpi_free(&key->d);
	mbedtls_ecp_point_free(&key->Q);
}
