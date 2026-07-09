# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_SHA2)
  zephyr_include_directories(.)
  zephyr_sources(atm_sha2.c)

  zephyr_compile_options_ifdef(CONFIG_ATM_SHA2_API_MULTI -DATM_SHA2_API=2)
  zephyr_compile_options_ifdef(CONFIG_ATM_SHA2_KEY_SIDELOAD -DENABLE_HMAC_SIDELOAD)
endif()

if(CONFIG_ATM_SHA2_HW)
  zephyr_sources(psa_sha256.c)
  zephyr_link_libraries(
    -Wl,--wrap=mbedtls_psa_hash_setup
    -Wl,--wrap=mbedtls_psa_hash_update
    -Wl,--wrap=mbedtls_psa_hash_finish
    -Wl,--wrap=mbedtls_psa_hash_abort
    -Wl,--wrap=mbedtls_psa_hash_clone
    -Wl,--wrap=mbedtls_psa_hash_compute
  )
endif()
