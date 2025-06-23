# Copyright (c) Atmosic 2024-2025
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_ATM34XX_5)
set(CHIP_REV rev-5)
endif()

board_runner_args(atmisp "--atm_plat=atmx3" "--openocd_config=${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATM34xx/${CHIP_REV}/openocd/atmx3_openocd.cfg" "--gdb_config=${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATM34xx/gdb/perth.gdb")
if(CONFIG_ATM_SETTINGS)
  board_runner_args(atmisp "--factory_data_file")
endif()

include(${ZEPHYR_OPENAIR_MODULE_DIR}/boards/common/atmisp.board.cmake)
