# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if (CONFIG_ATM_RADIO_HAL_FRC)
    zephyr_include_directories(.)
    zephyr_sources(radio_hal_frc.c)
endif ()
