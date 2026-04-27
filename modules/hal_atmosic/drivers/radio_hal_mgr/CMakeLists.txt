# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

zephyr_include_directories(.)

if(CONFIG_ATM_RADIO_HAL_MGR)
  zephyr_compile_definitions(
    RADIO_HAL_MGR_OMIT=0
  )
  zephyr_sources(radio_hal_mgr.c)
  atm_source_core_file(radio_hal_mgr_core radio_hal_mgr FAST)
endif()
