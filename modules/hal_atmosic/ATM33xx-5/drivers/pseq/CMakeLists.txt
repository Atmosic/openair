# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_PSEQ)
  zephyr_include_directories(.)
  atm_source_core_file(pseq_core pseq)
endif()
