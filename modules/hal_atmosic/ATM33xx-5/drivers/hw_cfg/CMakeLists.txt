# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_HW_CFG)
  zephyr_include_directories(.)
  zephyr_sources(hw_cfg.c)
  atm_source_core_file(hw_cfg_core hw_cfg)
endif()
