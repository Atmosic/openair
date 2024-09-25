# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_SEC_DEBUG_AUTH)
    zephyr_include_directories(.)
    zephyr_sources(atm_debug_auth.c)
endif ()

