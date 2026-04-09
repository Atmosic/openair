# Copyright (c) Atmosic 2024-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_SOC_ATM34XX_5)
set(CHIP_REV rev-5)
endif()

set(PLAT_DIR "${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATM34xx")
board_runner_args(atmisp "--rram")
board_runner_args(atmisp "--atm_openocd_search=${PLAT_DIR}/${CHIP_REV}/openocd")
board_runner_args(atmisp "--fast_load_bin=${PLAT_DIR}/${CHIP_REV}/openocd/fast_load/fast_load.bin")
board_runner_args(atmisp "--gdb_config=${PLAT_DIR}/gdb/perth.gdb")
if(CONFIG_ATM_SETTINGS)
  board_runner_args(atmisp "--factory_data_file")
endif()

include(${ZEPHYR_OPENAIR_MODULE_DIR}/boards/common/atmisp.board.cmake)
