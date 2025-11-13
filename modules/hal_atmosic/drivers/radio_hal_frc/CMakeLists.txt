# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_RADIO_HAL_FRC)
    zephyr_include_directories(.)
    zephyr_sources(radio_hal_frc.c)
endif ()
