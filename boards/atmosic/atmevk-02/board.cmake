# Copyright (c) Atmosic 2021
#
# SPDX-License-Identifier: Apache-2.0

board_runner_args(atmisp "--atm_plat=atm2" "--openocd_config=${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATMx2xx-x1x/openocd/atm2x_openocd.cfg" "--gdb_config=${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATMx2xx-x1x/gdb/atmx2.gdb")
include(${ZEPHYR_OPENAIR_MODULE_DIR}/boards/common/atmisp.board.cmake)
