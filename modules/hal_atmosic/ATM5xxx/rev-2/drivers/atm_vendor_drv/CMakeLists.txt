# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_VENDOR_DRIVER)
  zephyr_include_directories(.)
  atm_source_core_file(atm_vendor_drv_core atm_vendor_drv)
endif()
