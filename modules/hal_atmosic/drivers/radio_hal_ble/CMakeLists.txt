# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_RADIO_HAL_BLE)
  zephyr_include_directories(.)
  zephyr_sources(radio_hal_ble.c)
  atm_source_core_file(radio_hal_ble_core radio_hal_ble FAST)
endif()
