# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

zephyr_include_directories_ifdef(CONFIG_ATM_RADIO_HAL_PROF .)
zephyr_sources_ifdef(CONFIG_ATM_RADIO_HAL_PROF radio_hal_prof.c)
