# Coin Cell Battery Management (CCBM) Driver
#
# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_CCBM)
  zephyr_library()
  zephyr_library_sources(ccbm.c)
  zephyr_include_directories(.)
endif()

