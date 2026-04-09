# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_GFP_DIS)
  zephyr_include_directories(.)
  zephyr_library_sources(dis.c)
endif()

