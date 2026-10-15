# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_BT_ESLS)
  zephyr_include_directories(include)
  zephyr_sources(esls.c)
endif()
