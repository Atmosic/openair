# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_PLF_DEBUG)
  zephyr_compile_definitions(CFG_PLF_DEBUG)
  zephyr_sources(user_debug.c)
endif()
