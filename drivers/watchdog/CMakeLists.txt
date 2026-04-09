# SPDX-License-Identifier: Apache-2.0
# Copyright (c) 2025 Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_WDT_ATM_UNIFIED wdt_atm_unified.c)
