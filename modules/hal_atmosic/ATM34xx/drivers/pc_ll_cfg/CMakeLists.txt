# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_PC_LL_CFG)
  zephyr_include_directories(.)
  zephyr_sources(pc_ll_cfg.c)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_PC
    ENA_LL_FEAT_PC)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_CS
    ENA_LL_FEAT_CS)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_ENA_LL_FEAT_ISO
    ENA_LL_FEAT_ISO)
endif()
