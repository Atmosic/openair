# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_RADIO_CAL AND (CONFIG_ATM_RADIO_CAL_REPEAT_MS GREATER 0))
  zephyr_sources(radio_cal.c)
endif()

if(CONFIG_ATM_DC_OFFSET_CAL)
  zephyr_include_directories(.)
  zephyr_sources(dc_offset_cal.c)
endif()
