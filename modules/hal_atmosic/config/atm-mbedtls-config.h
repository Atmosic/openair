/**
 *******************************************************************************
 *
 * @file atm-mbedtls-config.h
 *
 * @brief mbedtls glue for Atmosic HW engines
 *
 * Copyright (C) Atmosic 2023-2026
 *
 *******************************************************************************
 */

#pragma once

#ifdef CONFIG_ATM_UECC_PSA_NO_FALLBACK

/*
 * In NO_FALLBACK builds the PSA wrapper in lib/micro-ecc/psa_ecc.c
 * returns PSA_ERROR_NOT_SUPPORTED for any curve uECC does not implement,
 * and the Mbed TLS software ECDSA backend is omitted from the link.
 * Strip the curve constants and modular-arithmetic code for those curves
 * out of tf-psa-crypto/drivers/builtin/src/ecp_curves.c so they do not
 * get pulled in via PSA's transitive selects.
 *
 * Do NOT do this in the default (with-fallback) ATM_UECC_PSA build:
 * undef'ing these macros would leave the software fallback unable to
 * service callers that legitimately request these curves through PSA.
 */
#undef MBEDTLS_ECP_DP_SECP384R1_ENABLED
#undef MBEDTLS_ECP_DP_SECP521R1_ENABLED
#undef MBEDTLS_ECP_DP_SECP192K1_ENABLED
#undef MBEDTLS_ECP_DP_SECP224K1_ENABLED
#undef MBEDTLS_ECP_DP_BP256R1_ENABLED
#undef MBEDTLS_ECP_DP_BP384R1_ENABLED
#undef MBEDTLS_ECP_DP_BP512R1_ENABLED
#undef MBEDTLS_ECP_DP_CURVE25519_ENABLED
#undef MBEDTLS_ECP_DP_CURVE448_ENABLED

#endif
