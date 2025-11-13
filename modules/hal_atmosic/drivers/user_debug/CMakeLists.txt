# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_PLF_DEBUG)
  zephyr_compile_definitions(CFG_PLF_DEBUG)
  zephyr_sources(user_debug.c)
endif()
