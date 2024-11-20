# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_BP_CLOCK atm_bp_clock.c)
