# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_AT_CMD
  at_cmd.c
  at_cmd_pasr.c
)

zephyr_sources_ifdef(CONFIG_ATM_AT_CMD_UART_TRANSPORT at_cmd_uart_transport.c)

zephyr_linker_sources(RODATA rodata.ld)
