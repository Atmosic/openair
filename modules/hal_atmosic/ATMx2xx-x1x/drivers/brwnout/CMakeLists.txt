# Copyright (c) 2024 Atmosic
#
# SPFX-License-Identifier: Apache-2.0

if (CONFIG_ATM_BROWNOUT)
    zephyr_include_directories(.)
    zephyr_sources(brwnout.c)
endif ()
