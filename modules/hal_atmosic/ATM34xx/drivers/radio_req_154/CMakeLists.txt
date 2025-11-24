# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_RADIO_REQ_154)
  zephyr_include_directories(.)
  atm_source_core_file(radio_req_154_core radio_req_154)
endif()
