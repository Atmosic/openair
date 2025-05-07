# Copyright (c) 2022-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_RWLC)
  zephyr_include_directories(
    ../../include/ble
    ../../include/reg_ble
  )
  zephyr_sources(
    src/ble_driver.c
  )

  set(BLE_FULL_STACK_C_FLAGS
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

  if(CONFIG_USE_ATMWSTK)
    if(CONFIG_ATMWSTK_PD50)
      zephyr_compile_definitions(${BLE_PD50_STACK_C_FLAGS})
      set(ATMWSTK_FLAVOR "PD50LL")
    elseif(CONFIG_ATMWSTK_FULL)
      zephyr_compile_definitions(${BLE_FULL_STACK_C_FLAGS})
      set(ATMWSTK_FLAVOR "LL")
    elseif(CONFIG_ATMWSTK STREQUAL "LL")
      zephyr_compile_definitions(${BLE_FULL_STACK_C_FLAGS})
      set(ATMWSTK_FLAVOR "LL")
    elseif(CONFIG_ATMWSTK STREQUAL "PD50LL")
      zephyr_compile_definitions(${BLE_PD50_STACK_C_FLAGS})
      set(ATMWSTK_FLAVOR "PD50LL")
    else()
      message(FATAL_ERROR "Invalid CONFIG_ATMWSTK.")
    endif()
    zephyr_link_libraries(
      ${LINKERFLAGPREFIX},-R${CMAKE_CURRENT_SOURCE_DIR}/atmwstk_${ATMWSTK_FLAVOR}.elf
    )
  else()
    if(CONFIG_ATMWSTK_PD50)
      zephyr_compile_definitions(${BLE_PD50_STACK_C_FLAGS})
      zephyr_compile_definitions(${ATMWSTKLIB_C_FLAGS})
      zephyr_link_libraries(
        -L${CMAKE_CURRENT_SOURCE_DIR}
      )
      zephyr_link_libraries(blellPD50)
    elseif(CONFIG_ATMWSTK_FULL)
      message(FATAL_ERROR "CONFIG_ATMWSTK_FULL only supports fixed wireless stack image for atm33. Set CONFIG_USE_ATMWSTK=y to use fixed wireless stack image.")
    elseif(CONFIG_ATMWSTKLIB STREQUAL "PD50")
      message(DEPRECATION "CONFIG_ATMWSTKLIB will be deprecated in the future, please choose one of CONFIG_ATMWSTK_PD50 or CONFIG_ATMWSTK_FULL.")
      zephyr_compile_definitions(${BLE_PD50_STACK_C_FLAGS})
      zephyr_compile_definitions(${ATMWSTKLIB_C_FLAGS})
      zephyr_link_libraries(
        -L${CMAKE_CURRENT_SOURCE_DIR}
      )
      zephyr_link_libraries(blellPD50)
    else()
      message(DEPRECATION "CONFIG_ATMWSTKLIB will be deprecated in the future, please choose one of CONFIG_ATMWSTK_PD50 or CONFIG_ATMWSTK_FULL.")
      message(FATAL_ERROR "Invalid CONFIG_ATMWSTKLIB. \"PD50\" is the only option for CONFIG_ATMWSTKLIB for ATM33.")
    endif()
  endif()
endif()
