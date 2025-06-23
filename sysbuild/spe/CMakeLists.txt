# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

set(image spe)

if(DEFINED BOARD_REVISION)
  set(board_str ${BOARD}@${BOARD_REVISION})
else()
  set(board_str ${BOARD})
endif()

# if SB_CONFIG_BOOTLOADER_MCUBOOT, the binary of application will be merged with spe eventually, so that bypass flash spe
set(build_only ${SB_CONFIG_BOOTLOADER_MCUBOOT})

ExternalZephyrProject_Add(
  APPLICATION ${image}
  SOURCE_DIR ${ZEPHYR_OPENAIR_MODULE_DIR}/samples/spe
  BUILD_ONLY ${build_only}
  BOARD ${board_str}
)

# Place spe first in list to ensure it is configured and flashed before other images.
add_dependencies(${DEFAULT_IMAGE} ${image})
sysbuild_add_dependencies(CONFIGURE ${DEFAULT_IMAGE} ${image})

if(NOT build_only)
  sysbuild_add_dependencies(FLASH ${image} ${DEFAULT_IMAGE})
endif()

set_config_bool(${image} CONFIG_BOOTLOADER_MCUBOOT "${SB_CONFIG_BOOTLOADER_MCUBOOT}")
if(SB_CONFIG_BOOTLOADER_MCUBOOT)
    set_config_bool(${image} CONFIG_MCUBOOT_GENERATE_UNSIGNED_IMAGE "n")
endif()