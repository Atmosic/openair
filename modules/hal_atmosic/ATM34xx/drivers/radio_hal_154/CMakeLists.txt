# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_RADIO_HAL_154)
    zephyr_include_directories(.)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/radio_hal_154_core.c")
	zephyr_sources(radio_hal_154_core.c)
    else ()
	zephyr_link_libraries(
	    ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/radio_hal_154/radio_hal_154_core.po"
	)
    endif ()
endif ()
