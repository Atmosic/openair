# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_VENDOR_DRIVER)
  zephyr_include_directories(.)
  zephyr_link_libraries(
    ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/atm_vendor_drv/atm_vendor_drv_core.po"
  )
endif()
