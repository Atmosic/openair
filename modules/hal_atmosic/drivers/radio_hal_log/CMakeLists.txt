# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if (CONFIG_ATM_RADIO_HAL_LOG)
    zephyr_include_directories(.)
    zephyr_sources(radio_hal_log.c)
endif ()
