# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_BROWNOUT)
  zephyr_include_directories(.)
  zephyr_sources(brwnout.c)
  atm_source_core_file(brwnout_core brwnout)
endif()
