# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_RADIO_HAL_154)
  zephyr_include_directories(.)
  atm_source_core_file(radio_hal_154_core radio_hal_154)
endif()
