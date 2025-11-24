# Copyright (c) 2022-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_RWLC OR CONFIG_PM)
  zephyr_include_directories(
    ../../include/reg_ble
  )
  zephyr_sources(
    src/ble_driver.c
  )
endif()

if(CONFIG_ATM_RWLC)
  zephyr_include_directories(
    ../../include/ble
  )

  set(BLE_CPD200_STACK_C_FLAGS
    -DCFG_ACT=12
    -DCFG_ADV_CH_IDX
    -DCFG_AOA
    -DCFG_AOD
    -DCFG_BLE_EMB
    -DCFG_BROADCASTER
    -DCFG_CENTRAL
    -DCFG_CON_CTE_REQ
    -DCFG_CON_CTE_RSP
    -DCFG_CONLESS_CTE_RX
    -DCFG_CONLESS_CTE_TX
    -DCFG_ECC_P256_SUPPORT
    -DCFG_H4TL
    -DCFG_HCITL
    -DCFG_HCI_C2H_FLOW_CTRL
    -DCFG_HL_ACT=9
    -DCFG_ISO_CON=0
    -DCFG_LE_PWR_CTRL
    -DCFG_MODEM_NONE
    -DCFG_OBSERVER
    -DCFG_PAST
    -DCFG_PER_ADV
    -DCFG_PERIPHERAL
    -DCFG_RAL=3
    -DCFG_RF_PARIS
    -DCFG_RTOS
    -DCFG_STATIC
    -DCFG_SYSTEM_MEM_SAFETY_MARGIN_SIZE=1000
  )

  set(BLE_PD50_STACK_C_FLAGS
    -DCFG_ACT=6
    -DCFG_ADV_CH_IDX
    -DCFG_BLE_EMB
    -DCFG_ECC_P256_SUPPORT
    -DCFG_H4TL
    -DCFG_HCITL
    -DCFG_HCI_C2H_FLOW_CTRL
    -DCFG_HL_ACT=9
    -DCFG_ISO_CON=0
    -DCFG_MODEM_NONE
    -DCFG_PERIPHERAL
    -DCFG_RAL=3
    -DCFG_RF_PARIS
    -DCFG_RTOS
    -DCFG_STATIC
    -DCFG_SYSTEM_MEM_SAFETY_MARGIN_SIZE=1000
  )

  set(ATMWSTKLIB_C_FLAGS
    -DCFG_STATIC_HEAP
    -DCFG_ATMWSTKLIB
  )

  if(CONFIG_USE_FIXED_ATMWSTK)
    if(CONFIG_ATMWSTK_CPD200)
      zephyr_compile_definitions(${BLE_CPD200_STACK_C_FLAGS})
      zephyr_link_libraries(
        ${LINKERFLAGPREFIX},-R${CMAKE_CURRENT_SOURCE_DIR}/atmwstk_CPD200.elf
      )
    else()
      message(FATAL_ERROR "Fixed BLE stack only supports CPD200 for atm33. Please set CONFIG_ATMWSTK_CPD200=y.")
    endif()
  else()
    if(CONFIG_ATMWSTK_PD50)
      zephyr_compile_definitions(${BLE_PD50_STACK_C_FLAGS})
      zephyr_compile_definitions(${ATMWSTKLIB_C_FLAGS})
      zephyr_link_libraries(
        -L${CMAKE_CURRENT_SOURCE_DIR}
      )
      zephyr_link_libraries(blellPD50)
    else()
      message(FATAL_ERROR "BLE stack library only supports PD50 for atm33. Please set CONFIG_ATMWSTK_PD50=y.")
    endif()
  endif()
endif()
