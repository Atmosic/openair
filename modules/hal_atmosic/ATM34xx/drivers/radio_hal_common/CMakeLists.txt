# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_RADIO_HAL_COMMON)
    zephyr_include_directories(.)
    zephyr_sources(radio_hal_common.c)
    zephyr_link_libraries(
	${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/radio_hal_common/radio_hal_common_core.po"
    )
endif ()
