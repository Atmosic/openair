# Copyright (c) 2021-2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(brwnout)
add_subdirectory(hw_cfg)
add_subdirectory(pmu)
add_subdirectory(pseq)
add_subdirectory(wurx)

if (CONFIG_ATM_PLF_DEBUG)
    zephyr_compile_definitions(
	CFG_DBG
    )
    zephyr_sources(
	debug.c
    )
endif ()

if (CONFIG_BT)
    add_subdirectory(ble)
endif ()
