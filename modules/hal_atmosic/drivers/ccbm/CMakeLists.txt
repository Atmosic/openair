# Coin Cell Battery Management (CCBM) Driver
#
# Copyright (C) Atmosic 2025
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_CCBM)
  zephyr_library()
  zephyr_library_sources(ccbm.c)
  zephyr_include_directories(.)
endif()

