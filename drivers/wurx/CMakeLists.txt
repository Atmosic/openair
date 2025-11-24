# Copyright (c) 2025 Atmosic
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_WURX)
    zephyr_library()
    zephyr_library_sources(wurx_atm.c)
    zephyr_include_directories(.)
endif()
