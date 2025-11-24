# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories_ifdef(CONFIG_ATM_SEC_COUNTER_PRESENT .)
zephyr_sources_ifdef(CONFIG_ATM_SEC_COUNTER sec_counter.c)

