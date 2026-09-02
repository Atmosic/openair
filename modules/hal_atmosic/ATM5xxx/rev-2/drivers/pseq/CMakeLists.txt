# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_PSEQ)
  zephyr_include_directories(.)
  atm_source_core_file(pseq_core pseq FAST)
endif()
