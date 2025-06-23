# Copyright (c) Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_VERSION)
  zephyr_include_directories(.)
  zephyr_sources(atm_version.c)
endif()
