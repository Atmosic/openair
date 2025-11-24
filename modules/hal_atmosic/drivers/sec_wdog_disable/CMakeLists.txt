# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_SEC_WDOG_DISABLE atm_sec_wdog_disable.c)
