# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_RF)
  zephyr_include_directories(.)
  zephyr_sources(rf.c)
  atm_source_core_file(rf_core rf)
endif()
