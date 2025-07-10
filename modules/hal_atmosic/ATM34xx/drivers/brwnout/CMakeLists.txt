# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_BROWNOUT)
    zephyr_include_directories(.)
    zephyr_sources(brwnout.c)
    zephyr_link_libraries(
	${LINKERFLAGPREFIX},"${PRECOMPILED_DRIVER_DIR}/brwnout/brwnout_core.po"
    )
endif ()
