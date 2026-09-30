# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

include(${ZEPHYR_OPENAIR_MODULE_DIR}/cmake/common.cmake)

add_subdirectory(lib)
add_subdirectory(drivers)
add_subdirectory(modules/hal_atmosic)
add_subdirectory(subsys)

zephyr_include_directories(include)

if(CONFIG_UU_TEST_OPENAIR)
  file(GLOB_RECURSE OPENAIR_FILES
    ${CMAKE_CURRENT_LIST_DIR}/*.c
  )
  set_coverage_properties_for_files(OPENAIR_FILES CONFIG_UU_TEST_OPENAIR)
endif()
