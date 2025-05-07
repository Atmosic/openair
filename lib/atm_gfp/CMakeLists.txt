# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_GFP)
  zephyr_include_directories(.)
  zephyr_sources(atm_gfp.c)
endif()
