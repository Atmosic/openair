# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(DEFINED BOARD_REVISION)
  set(board_str ${BOARD}@${BOARD_REVISION})
else()
  set(board_str ${BOARD})
endif()
ExternalZephyrProject_Add(
  APPLICATION spe
  SOURCE_DIR ${ZEPHYR_BASE}/../openair/samples/spe
  BOARD ${board_str}
)

# Place spe first in list to ensure it is configured and flashed before other images.
add_dependencies(${DEFAULT_IMAGE} spe)
sysbuild_add_dependencies(CONFIGURE ${DEFAULT_IMAGE} spe)
sysbuild_add_dependencies(FLASH ${DEFAULT_IMAGE} spe)
