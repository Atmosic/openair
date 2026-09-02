# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if (CONFIG_ATM_RADIO_HAL_BURST)
    zephyr_include_directories(.)
    atm_source_core_file(radio_hal_burst_core radio_hal_burst)
endif ()
