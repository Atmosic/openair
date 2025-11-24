# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_DULT)
  zephyr_include_directories(.)
  zephyr_sources(dult.c)
  if(CONFIG_DULT_ADV_SUPPORT)
    zephyr_sources(dult_adv.c)
  endif()
endif()
