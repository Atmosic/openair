# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_PMU)
    zephyr_include_directories(.)
    zephyr_sources(pmu.c)
    zephyr_link_libraries(
	${LINKERFLAGPREFIX},${CMAKE_CURRENT_SOURCE_DIR}/pmu_core.po
    )
endif ()
