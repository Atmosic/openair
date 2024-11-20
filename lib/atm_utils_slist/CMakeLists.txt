# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories_ifdef(CONFIG_ATM_UTILS_SLIST .)
zephyr_sources_ifdef(CONFIG_ATM_UTILS_SLIST atm_utils_slist.c)
