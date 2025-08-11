# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_RADIO_HAL_BLE_CS)
  zephyr_include_directories(.)
  zephyr_sources(radio_hal_ble_cs.c)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/radio_hal_ble_cs_core.c")
    zephyr_sources(radio_hal_ble_cs_core.c)
  else()
    zephyr_link_libraries(
      ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/radio_hal_ble_cs/radio_hal_ble_cs_core.po"
    )
  endif()
  zephyr_compile_definitions_ifdef(CONFIG_ATM_LDO_MODE LDO_MODE_EN)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_RF_DELAY_ONE_EIGHTH_NS
    CONFIG_RF_DELAY_ONE_EIGHTH_NS=CONFIG_ATM_RF_DELAY_ONE_EIGHTH_NS
  )
endif()
