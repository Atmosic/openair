# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
if(CONFIG_ATM_SEC_HW_CFG)
  zephyr_sources(sec_hw_cfg.c)
  atm_source_core_file(sec_hw_cfg_core sec_hw_cfg)
endif()
