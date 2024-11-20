# Copyright (c) 2022-2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(drivers)
add_subdirectory(src)

zephyr_include_directories(
    include
)

zephyr_linker_sources(NOINIT noinit.ld)
zephyr_linker_sources(RAMFUNC_SECTION ramfunc-section.ld)
