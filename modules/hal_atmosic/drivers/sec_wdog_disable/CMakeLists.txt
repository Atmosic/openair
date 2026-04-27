# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_SEC_WDOG_DISABLE atm_sec_wdog_disable.c)
