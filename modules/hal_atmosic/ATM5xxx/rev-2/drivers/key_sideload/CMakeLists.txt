# Copyright (c) 2024 Atmosic-2025
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_KEY_SIDELOAD)
    zephyr_include_directories(.)
    zephyr_sources(key_sideload.c)
endif ()
