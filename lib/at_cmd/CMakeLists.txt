# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_AT_CMD
  at_cmd.c
  at_cmd_pasr.c
)

zephyr_linker_sources(RODATA rodata.ld)
