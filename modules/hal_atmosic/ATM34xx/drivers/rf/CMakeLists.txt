# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_RF)
    zephyr_include_directories(.)
    zephyr_sources(rf.c)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/rf_core.c")
        zephyr_sources(rf_core.c)
    else ()
        zephyr_link_libraries(
            ${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/rf/rf_core.po"
        )
    endif ()
endif ()
