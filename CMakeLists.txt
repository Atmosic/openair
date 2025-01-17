# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(drivers)
add_subdirectory(lib)
add_subdirectory(modules/hal_atmosic)
add_subdirectory(subsys)

if(CONFIG_UU_TEST_OPENAIR)
  file(GLOB_RECURSE OPENAIR_FILES
    ${CMAKE_CURRENT_LIST_DIR}/*.c
  )
  set_coverage_properties_for_files(OPENAIR_FILES CONFIG_UU_TEST_OPENAIR)
endif()
