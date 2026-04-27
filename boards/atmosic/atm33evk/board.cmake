# Copyright (c) Atmosic 2022-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

set(PLAT_DIR "${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATM33xx-5")
board_runner_args(atmisp "--rram")
board_runner_args(atmisp "--atm_openocd_search=${PLAT_DIR}/openocd")
board_runner_args(atmisp "--fast_load_bin=${PLAT_DIR}/openocd/fast_load/fast_load.bin")
board_runner_args(atmisp "--gdb_config=${PLAT_DIR}/gdb/perth.gdb")

if(CONFIG_USE_FIXED_ATMWSTK)
  if(CONFIG_ATMWSTK_CPD200)
    set(atmwstk_prefix_path "${ZEPHYR_BINARY_DIR}/atmwstk_CPD200")
  else()
    message(FATAL_ERROR "Fixed BLE stack only supports CPD200 for atm33, please set CONFIG_ATMWSTK_CPD200=y.")
  endif()
  board_runner_args(atmisp "--atmwstk=${atmwstk_prefix_path}")
endif()
if(CONFIG_ATM_SETTINGS)
  board_runner_args(atmisp "--factory_data_file")
endif()
include(${ZEPHYR_OPENAIR_MODULE_DIR}/boards/common/atmisp.board.cmake)
