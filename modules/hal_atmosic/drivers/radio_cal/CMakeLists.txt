# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_RADIO_CAL)
  zephyr_include_directories(.)
  zephyr_sources(radio_cal.c)
endif()
