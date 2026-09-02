# SPDX-License-Identifier: LicenseRef-Atmosic
# Copyright (c) 2025-2026 Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_WDOG_ATMOSIC_CMSDK wdt_atmosic_cmsdk.c)
zephyr_library_sources_ifdef(CONFIG_WDT_ATM_UNIFIED wdt_atm_unified.c)
