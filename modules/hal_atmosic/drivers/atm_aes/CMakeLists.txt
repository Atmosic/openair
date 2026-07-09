# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

zephyr_include_directories_ifdef(CONFIG_ATM_AES .)
zephyr_sources_ifdef(CONFIG_ATM_AES_ATM_CORE atm_aes.c)

if(CONFIG_ATM_AES_HW)
  zephyr_sources(psa_aes.c)
  zephyr_link_libraries(
    -Wl,--wrap=mbedtls_psa_cipher_encrypt
    -Wl,--wrap=mbedtls_psa_cipher_decrypt
  )
endif()
