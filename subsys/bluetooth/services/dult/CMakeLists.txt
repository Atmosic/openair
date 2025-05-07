# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_DULT)
  zephyr_include_directories(.)
  zephyr_sources(dult.c)
  zephyr_sources(dult_adv.c)
endif()
