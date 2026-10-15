# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_UECC)
    zephyr_include_directories(
      ${ZEPHYR_BASE}/../modules/crypto/micro-ecc
      .
    )
    if(CONFIG_ATM_UECC_VLI_API)
      zephyr_compile_options(-DuECC_ENABLE_VLI_API=1)
    endif()
    if(CONFIG_ATM_UECC_SUPPORTS_SECP160R1)
      zephyr_compile_options(-DuECC_SUPPORTS_secp160r1=1)
    else()
      zephyr_compile_options(-DuECC_SUPPORTS_secp160r1=0)
    endif()
    if(CONFIG_ATM_UECC_SUPPORTS_SECP192R1 OR CONFIG_PSA_WANT_ECC_SECP_R1_192)
      zephyr_compile_options(-DuECC_SUPPORTS_secp192r1=1)
    else()
      zephyr_compile_options(-DuECC_SUPPORTS_secp192r1=0)
    endif()
    if(CONFIG_ATM_UECC_SUPPORTS_SECP224R1 OR CONFIG_PSA_WANT_ECC_SECP_R1_224)
      zephyr_compile_options(-DuECC_SUPPORTS_secp224r1=1)
    else()
      zephyr_compile_options(-DuECC_SUPPORTS_secp224r1=0)
    endif()
    if(CONFIG_ATM_UECC_SUPPORTS_SECP256R1 OR CONFIG_PSA_WANT_ECC_SECP_R1_256)
      zephyr_compile_options(-DuECC_SUPPORTS_secp256r1=1)
    else()
      zephyr_compile_options(-DuECC_SUPPORTS_secp256r1=0)
    endif()
    if(CONFIG_ATM_UECC_SUPPORTS_SECP256K1 OR CONFIG_PSA_WANT_ECC_SECP_K1_256)
      zephyr_compile_options(-DuECC_SUPPORTS_secp256k1=1)
    else()
      zephyr_compile_options(-DuECC_SUPPORTS_secp256k1=0)
    endif()
    if(CONFIG_ATM_UECC_SUPPORT_COMPRESSED_POINT)
      zephyr_compile_options(-DuECC_SUPPORT_COMPRESSED_POINT=1)
    else()
      zephyr_compile_options(-DuECC_SUPPORT_COMPRESSED_POINT=0)
    endif()
    if(CONFIG_ATM_UECC_SUPPORT_POINT_ADD)
      zephyr_compile_options(-DuECC_SUPPORT_POINT_ADD)
    endif()
    if(CONFIG_ATM_UECC_PSA)
      # psa_ecc.c #include's uECC.c so its symbols are emitted from this TU;
      # do not also compile the upstream uECC.c or the link will be a multiple
      # definition error.
      zephyr_sources(psa_ecc.c)
      zephyr_link_libraries(
        -Wl,--wrap=mbedtls_psa_ecdsa_sign_hash
        -Wl,--wrap=mbedtls_psa_ecdsa_verify_hash
        -Wl,--wrap=mbedtls_psa_key_agreement_ecdh
      )
      if(CONFIG_ATM_UECC_PSA_NO_FALLBACK)
        # Without this wrap, psa_import_key() for ECC keys reaches
        # mbedtls_psa_ecp_import_key, which transitively pulls in the
        # whole software ecp / bignum / ecdsa stack -- defeating the
        # NO_FALLBACK code-size win.
        zephyr_link_libraries(
          -Wl,--wrap=mbedtls_psa_ecp_import_key
        )
      endif()
    else()
      zephyr_sources(${ZEPHYR_BASE}/../modules/crypto/micro-ecc/uECC.c)
    endif()

endif()
