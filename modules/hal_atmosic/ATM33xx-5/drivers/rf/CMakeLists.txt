# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_RF)
    zephyr_include_directories(.)
    zephyr_sources(rf.c)
    zephyr_link_libraries(
	${LINKERFLAGPREFIX},${CMAKE_CURRENT_SOURCE_DIR}/rf_core.po
    )
endif ()
