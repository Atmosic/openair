# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_APP_BATT)
    zephyr_include_directories(.)
    zephyr_sources(app_batt.c)
endif()
