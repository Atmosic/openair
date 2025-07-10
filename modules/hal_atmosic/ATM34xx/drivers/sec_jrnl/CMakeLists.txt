# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories_ifdef(CONFIG_ATM_SEC_JRNL_PRESENT .)
zephyr_sources_ifdef(CONFIG_ATM_SEC_JRNL sec_jrnl.c)
