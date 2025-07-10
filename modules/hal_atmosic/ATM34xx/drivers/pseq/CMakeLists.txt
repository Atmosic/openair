# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_PSEQ)
  zephyr_include_directories(.)
  zephyr_link_libraries(
    ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/pseq/pseq_core.po"
  )
endif()
