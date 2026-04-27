# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if (CONFIG_ATM_SEC_DEBUG)
    zephyr_include_directories(.)
    zephyr_sources(sec_debug.c)
endif ()

