# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)

if (CONFIG_ATM_RADIO_HAL_MGR)
    zephyr_compile_definitions(
	RADIO_HAL_MGR_OMIT=0
    )
    zephyr_sources(radio_hal_mgr.c)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/radio_hal_mgr_core.c")
	zephyr_sources(radio_hal_mgr_core.c)
    else ()
	zephyr_link_libraries(
	    ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/radio_hal_mgr/radio_hal_mgr_core.po"
	)
    endif ()
endif ()
