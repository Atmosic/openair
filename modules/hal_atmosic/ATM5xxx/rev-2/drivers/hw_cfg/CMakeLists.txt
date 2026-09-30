# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
if(CONFIG_ATM_HW_CFG)
  zephyr_sources(hw_cfg.c)
  atm_source_core_file(hw_cfg_core hw_cfg)
endif()
