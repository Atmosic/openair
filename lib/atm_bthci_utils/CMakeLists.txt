# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories_ifdef(CONFIG_ATM_BTHCI_UTILS .)
zephyr_sources_ifdef(CONFIG_ATM_BTHCI_UTILS_DUMP_PKTS atm_bthci_utils_dump.c)
