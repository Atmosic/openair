# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)

if(CONFIG_ATM_SEC_HW_CFG)
  zephyr_sources(sec_hw_cfg.c)
  zephyr_link_libraries(
    ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/sec_hw_cfg/sec_hw_cfg_core.po"
  )
endif()
