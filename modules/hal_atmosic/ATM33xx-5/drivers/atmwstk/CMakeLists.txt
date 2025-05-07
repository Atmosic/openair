# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_USE_ATMWSTK)
  zephyr_include_directories(.)
  zephyr_sources(atmwstk.c)
endif ()
