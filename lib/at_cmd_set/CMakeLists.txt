# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../at_cmd)
zephyr_sources_ifdef(CONFIG_ATM_AT_CMD_SET
  at_cmd_callbacks.c
  at_cmd_setdevicename.c
  at_cmd_setadvinterval.c
  at_cmd_setadvdata.c
  at_cmd_sysreset.c
  at_cmd_unlock.c
)

