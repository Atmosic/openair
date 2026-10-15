# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_UTILS_REG atm_utils_reg.c)
