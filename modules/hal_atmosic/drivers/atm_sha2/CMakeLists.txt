# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_SHA2)
  zephyr_include_directories(.)
  zephyr_sources(atm_sha2.c)

  zephyr_compile_options_ifdef(CONFIG_ATM_SHA2_API_MULTI -DATM_SHA2_API=2)
  zephyr_compile_options_ifdef(CONFIG_ATM_SHA2_KEY_SIDELOAD -DENABLE_HMAC_SIDELOAD)
endif()

zephyr_sources_ifdef(CONFIG_ATM_SHA2_HW sha256_alt.c)
