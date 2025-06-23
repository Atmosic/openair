# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_PMU)
    zephyr_include_directories(.)
    zephyr_sources(pmu.c)
    zephyr_link_libraries(
	${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/pmu/pmu_core.po"
    )
endif ()
