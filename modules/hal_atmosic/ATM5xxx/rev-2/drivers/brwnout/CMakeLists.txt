# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_BROWNOUT)
  zephyr_include_directories(.)
  zephyr_sources(brwnout.c)
  atm_source_core_file(brwnout_core brwnout)
endif()
