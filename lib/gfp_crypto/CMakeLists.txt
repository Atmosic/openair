# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_GFP_CRYPTO)
  zephyr_include_directories(.)
  zephyr_sources(gfp_crypto.c)
endif()

if(CONFIG_ATM_GFP_DIRECT_UECC_INTERFACE)
  zephyr_compile_options(-DuECC_ENABLE_VLI_API=1)
  zephyr_compile_options(-DuECC_SUPPORTS_secp160r1=1)
endif()
