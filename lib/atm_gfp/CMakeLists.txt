# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_GFP)
  zephyr_include_directories(.)
  zephyr_sources(atm_gfp.c)
endif()
