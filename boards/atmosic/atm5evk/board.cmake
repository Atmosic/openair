# Copyright (c) Atmosic 2025-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_SOC_ATM5XXX_2)
  set(PLAT_DIR "${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/ATM5xxx/rev-2")
endif()
board_runner_args(atmisp "--atm_openocd_search=${PLAT_DIR}/openocd")
board_runner_args(atmisp "--fast_load_bin=${PLAT_DIR}/openocd/fast_load/fast_load.bin")
board_runner_args(atmisp "--ext_flash_base_addr=0x202000")
board_runner_args(atmisp "--gdb_config=${PLAT_DIR}/gdb/cairo.gdb")
board_runner_args(atmisp "--memory_space=FLASH,0x10200000,0x200000")

if(CONFIG_ATM_SETTINGS)
  board_runner_args(atmisp "--factory_data_file")
endif()
include(${ZEPHYR_OPENAIR_MODULE_DIR}/boards/common/atmisp.board.cmake)
