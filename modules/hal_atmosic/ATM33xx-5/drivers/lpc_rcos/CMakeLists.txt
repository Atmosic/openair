# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_LPC_RCOS)
  zephyr_include_directories(.)
  zephyr_sources(lpc_rcos.c)
endif ()

zephyr_compile_definitions_ifdef(CONFIG_ATM_FORCE_LPC_RCOS FORCE_LPC_RCOS)
