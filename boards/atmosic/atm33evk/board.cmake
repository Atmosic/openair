# Copyright (c) Atmosic 2022-2025
#
# SPDX-License-Identifier: Apache-2.0

board_runner_args(atmisp "--atm_plat=atmx3" "--openocd_config=${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATM33xx-5/openocd/atmx3_openocd.cfg" "--gdb_config=${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATM33xx-5/gdb/paris.gdb")
if(CONFIG_USE_FIXED_ATMWSTK)
  if(CONFIG_ATMWSTK_FULL)
    set(atmwstk_prefix_path "${ZEPHYR_BINARY_DIR}/atmwstk_FULL")
  else()
    message(FATAL_ERROR "Fixed BLE stack only supports FULL for atm33, please set CONFIG_ATMWSTK_FULL=y.")
  endif()
  board_runner_args(atmisp "--atmwstk=${atmwstk_prefix_path}")
endif()
if(CONFIG_ATM_SETTINGS)
  board_runner_args(atmisp "--factory_data_file")
endif()
include(${ZEPHYR_OPENAIR_MODULE_DIR}/boards/common/atmisp.board.cmake)
