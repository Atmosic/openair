# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_TEST_UTIL atm_test_util.c)
