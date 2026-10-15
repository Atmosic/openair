# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_GME_OLED)
    zephyr_include_directories(.)
    zephyr_sources(display_gme.c)
endif()
