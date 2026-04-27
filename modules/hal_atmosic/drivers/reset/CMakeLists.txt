# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if (CONFIG_ATM_RESET)
    zephyr_include_directories(.)
    zephyr_sources(reset.c)
endif ()
