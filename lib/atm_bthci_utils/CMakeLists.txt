# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories_ifdef(CONFIG_ATM_BTHCI_UTILS .)
zephyr_sources_ifdef(CONFIG_ATM_BTHCI_UTILS_DUMP_PKTS atm_bthci_utils_dump.c)
