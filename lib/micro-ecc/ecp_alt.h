/**
 *******************************************************************************
 *
 * @file ecp_alt.h
 *
 * @brief Lightweight ECP group structure for MBEDTLS_ECP_ALT
 *
 * When MBEDTLS_ECP_ALT is defined, this header replaces the default
 * mbedtls_ecp_group structure with a minimal version that only stores
 * the curve identifier and bit sizes. The supported ECP operations are
 * delegated to the micro-ecc (uECC) library in ecp_alt.c.
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#ifndef ECP_ALT_H
#define ECP_ALT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Only define mbedtls_ecp_group if MBEDTLS_ECP_ALT is defined */
#ifdef MBEDTLS_ECP_ALT

/**
 * Lightweight ECP group - only stores the curve ID and bit sizes.
 * The supported ECP operations are implemented via uECC in ecp_alt.c.
 */
typedef struct mbedtls_ecp_group {
	mbedtls_ecp_group_id id; /*!< Internal group identifier. */
	mbedtls_mpi A;           /*!< Curve parameter A (kept zero-init for
				      inline mbedtls_ecp_group_a_is_minus_3). */
	size_t pbits;            /*!< Number of bits in the prime P. */
	size_t nbits;            /*!< Number of bits in the group order N. */
} mbedtls_ecp_group;

#endif /* MBEDTLS_ECP_ALT */

#ifdef __cplusplus
}
#endif

#endif /* ECP_ALT_H */
