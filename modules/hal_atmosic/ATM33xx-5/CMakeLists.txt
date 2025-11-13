# Copyright (c) 2022-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

set(PRECOMPILED_DRIVER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/drivers" CACHE
    PATH "Directory containing precompiled files")

# Use soc/atmosic/ATM33/linker.ld to locate any core.po file into RRAM
function(atm_relocate_fast_core_file po_folder fast_po_base)
  zephyr_link_libraries(
    ${LINKERFLAGPREFIX},${PRECOMPILED_DRIVER_DIR}/${po_folder}/${fast_po_base})
endfunction()

add_subdirectory(drivers)
add_subdirectory(src)

zephyr_include_directories(
    include
    include/arm
    include/armgcc
    include/reg
)

zephyr_linker_sources(NOINIT noinit.ld)
zephyr_linker_sources(RAMFUNC_SECTION ramfunc-section.ld)

# relocate HAL NSC functions and cache management into RAM
zephyr_compile_options_ifdef(CONFIG_ATM_HAL_ENABLE_NSC_IN_RAM -DATM_NSC_ENTRY_IN_RAM -DATM_CACHE_FUNC_IN_RAM)
