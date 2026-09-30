# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_DULT)
  zephyr_library()
  zephyr_include_directories(.)
  zephyr_library_sources(dult.c)
  zephyr_library_sources_ifdef(CONFIG_DULT_ADV_SUPPORT dult_adv.c)
  zephyr_library_sources_ifdef(CONFIG_DULT_MOTION_DETECT dult_ut.c)
endif()
