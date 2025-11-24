# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)

if(CONFIG_ATM_RADIO_HAL_BLE_CS)
  zephyr_sources(radio_hal_ble_cs.c)
  atm_source_core_file(radio_hal_ble_cs_core radio_hal_ble_cs FAST)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_LDO_MODE LDO_MODE_EN)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_REF_PHS_CORR_SUPP REF_PHS_CORR_SUPP)
  zephyr_compile_definitions_ifdef(CONFIG_ATM_RF_DELAY_ONE_EIGHTH_NS
    CONFIG_RF_DELAY_ONE_EIGHTH_NS=CONFIG_ATM_RF_DELAY_ONE_EIGHTH_NS
  )
endif()
