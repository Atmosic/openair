# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_PC_CTR_SLEEP)
  zephyr_include_directories(.)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/pc_ctr_sleep_core.c")
    zephyr_sources(pc_ctr_sleep_core.c)
  else()
    zephyr_link_libraries(
      ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/pc_ctr_sleep/pc_ctr_sleep_core.po"
    )
  endif()
endif()
