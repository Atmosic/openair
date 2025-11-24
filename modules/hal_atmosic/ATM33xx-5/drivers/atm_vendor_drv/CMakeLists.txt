# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_VENDOR_DRIVER)
  zephyr_include_directories(.)
  atm_source_core_file(atm_vendor_drv_core atm_vendor_drv)
endif()
