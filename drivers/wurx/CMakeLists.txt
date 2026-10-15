# Copyright (c) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_WURX)
    zephyr_library()
    zephyr_library_sources(wurx_atm.c)
    zephyr_include_directories(.)
endif()
