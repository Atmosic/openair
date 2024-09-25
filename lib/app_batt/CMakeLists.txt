# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_APP_BATT)
    zephyr_include_directories(.)
    zephyr_sources(app_batt.c)
endif ()
