# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)

target_sources_ifdef(CONFIG_AT_CMD_TAG_SET app PRIVATE at_cmd_uart.c)
