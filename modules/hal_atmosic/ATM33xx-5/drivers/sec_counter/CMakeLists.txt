# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_SEC_COUNTER)
    zephyr_include_directories(.)
    zephyr_sources(sec_counter.c)
endif ()

