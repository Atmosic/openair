# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_GFP_CRYPTO)
  zephyr_include_directories(.)
  zephyr_sources(gfp_crypto.c)
endif()
