# Copyright (c) 2023-2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_ATM34XX_5)
    set(PRECOMPILED_DRIVER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rev-5/drivers")
    zephyr_include_directories(
	rev-5/include
	rev-5/include/arm
	rev-5/include/armgcc
	rev-5/include/reg
    )
    add_subdirectory(rev-5/lib)
endif()

zephyr_include_directories(
    include
)

add_subdirectory(drivers)
add_subdirectory(src)

zephyr_linker_sources(NOINIT noinit.ld)
zephyr_linker_sources(RAMFUNC_SECTION ramfunc-section.ld)
