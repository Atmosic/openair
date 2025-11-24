# SPDX-License-Identifier: Apache-2.0
# Copyright (c) 2025 Atmosic

if (CONFIG_ATM_BT_TPUTP)
  zephyr_include_directories(include)
  zephyr_sources(atm_bt_tput.c)
endif ()
