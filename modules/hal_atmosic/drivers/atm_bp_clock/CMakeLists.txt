# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_BP_CLOCK atm_bp_clock.c)
