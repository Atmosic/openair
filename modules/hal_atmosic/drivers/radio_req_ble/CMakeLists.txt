# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_RADIO_REQ_BLE)
  zephyr_include_directories(.)
  atm_source_core_file(radio_req_ble_core radio_req_ble FAST)
endif()
