# Copyright (c) 2021-2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATMx2_ROM)
    zephyr_link_libraries(
        ${LINKERFLAGPREFIX},-R${CMAKE_CURRENT_SOURCE_DIR}/drivers/ble/rom/rom.elf
        ${LINKERFLAGPREFIX},--just-symbols=${CMAKE_CURRENT_SOURCE_DIR}/drivers/ble/rom/romsymdef
    )

    add_subdirectory(drivers)
endif ()

add_subdirectory(src)

zephyr_include_directories(
    include
)
