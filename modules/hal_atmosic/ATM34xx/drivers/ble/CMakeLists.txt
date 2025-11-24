# Copyright (c) 2023-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_ATLC OR CONFIG_PM)
  zephyr_sources(
    src/ble_driver.c
  )
endif()

if(CONFIG_ATM_ATLC)
  zephyr_include_directories(
    include
  )
endif()
