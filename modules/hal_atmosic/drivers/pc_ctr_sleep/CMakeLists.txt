# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_PC_CTR_SLEEP)
  zephyr_include_directories(.)
  atm_source_core_file(pc_ctr_sleep_core pc_ctr_sleep FAST)
endif()
