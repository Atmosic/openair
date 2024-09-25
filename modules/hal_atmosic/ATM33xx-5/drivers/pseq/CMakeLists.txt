# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_PSEQ)
    zephyr_include_directories(.)
    zephyr_link_libraries(
	${LINKERFLAGPREFIX},${CMAKE_CURRENT_SOURCE_DIR}/pseq_core.po
    )
endif ()
