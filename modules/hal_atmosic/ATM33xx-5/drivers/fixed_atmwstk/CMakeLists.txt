# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_USE_FIXED_ATMWSTK)
  zephyr_include_directories(.)
  zephyr_sources(fixed_atmwstk.c)
endif ()
