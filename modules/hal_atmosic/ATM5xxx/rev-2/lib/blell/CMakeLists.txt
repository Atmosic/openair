# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

set(BLE_LCROM_C_FLAGS
    -DATM53xx_dev
    -DBB_CLK_RATE_HZ=1000000
    -DBB_ENABLE_INLINE_DEC_RX=1
    -DBB_ENABLE_INLINE_ENC_TX=1
    -DBOARD_CAIRO_FPGA=1
    -DBT_VER=17
    -DCHCI_TR_CUSTOM=1
    -DENABLE_UECC=1
    -DINIT_BROADCASTER
    -DINIT_CENTRAL
    -DINIT_ENCRYPTED
    -DLL_FEAT_BIS=1
    -DLL_FEAT_CIS=1
    -DLL_FEAT_DELAY_CHM_UPD_IN_LATENCY=1
    -DLL_FEAT_ECU=1
    -DLL_FEAT_ISO=1
    -DLL_FEAT_LINK_ALT_PROC=1
    -DLL_FEAT_PAST=1
    -DLL_FEAT_PAST_SYNC_ASAP=1
    -DLL_FEAT_PAWR=1
    -DLL_FEAT_PC=1
    -DLL_FEAT_SLV_PER_ADV=1
    -DLL_FEAT_CS=1
    -DINIT_OBSERVER
    -DINIT_PERIPHERAL
    -DLHCI_ENABLE_VS=1
    -DLL_MAX_CONN=5
    -DPAL_LED_LOGIC_ENA=0
    -DPOWER_CTRL_MON_USE_BB_SCHED=0
    -DSCH_CHECK_LIST_INTEGRITY=1
    -DUART_BAUD=2000000
    -DUART_HWFC=1
    -DWSF_TOKEN_ENABLED=0
)

set(BLE_DEBUG_STACK_C_FLAGS
    -DLL_TRACE_ENABLED=1
    -DTRACE
    -DWSF_ASSERT_ENABLED=1
    -DWSF_BUF_FREE_CHECK_ASSERT=true
    -DWSF_BUF_STATS=true
    -DWSF_TRACE_ENABLED=1
    -DWSF_TRACE_LEVEL=1
    -DWSF_TRACE_LF_DISABLE=1
)

if(CONFIG_ATM_BLE)
    zephyr_link_libraries(
	${CMAKE_CURRENT_SOURCE_DIR}/libblell.o
    )
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libblell_patch.o")
	zephyr_link_libraries(
	    ${CMAKE_CURRENT_SOURCE_DIR}/libblell_patch.o
	)
    endif()
endif()

if(CONFIG_ATM_BLE OR CONFIG_ATM_PC_CTR_SLEEP)
    zephyr_include_directories(
	.
	controller/include/ble
	controller/include/common
	platform/include
	wsf/include
	wsf/include/util
    )
    zephyr_compile_definitions(${BLE_LCROM_C_FLAGS})
    zephyr_compile_definitions(${BLE_DEBUG_STACK_C_FLAGS})
endif()

# Stubs provided by pc_ll_cfg when not used
zephyr_include_directories(thirdparty/uecc)
if(CONFIG_ATM_LL_ECC_SUPPORT)
    zephyr_sources(
	thirdparty/uecc/uECC_ll.c
    )
endif()
