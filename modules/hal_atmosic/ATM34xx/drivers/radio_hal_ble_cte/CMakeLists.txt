# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_RADIO_HAL_BLE_CTE)
    zephyr_include_directories(.)
    zephyr_sources(radio_hal_ble_cte.c)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/radio_hal_ble_cte_core.c")
	zephyr_sources(radio_hal_ble_cte_core.c)
    else ()
	zephyr_link_libraries(
	    ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/radio_hal_ble_cte/radio_hal_ble_cte_core.po"
	)
    endif ()
endif ()
