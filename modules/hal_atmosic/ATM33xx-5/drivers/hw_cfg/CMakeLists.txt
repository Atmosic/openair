# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_HW_CFG)
    zephyr_include_directories(.)
    zephyr_sources(hw_cfg.c)
    zephyr_link_libraries(
	${LINKERFLAGPREFIX},${CMAKE_CURRENT_SOURCE_DIR}/hw_cfg_core.po
    )
endif ()
