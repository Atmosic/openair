# Copyright (c) 2021-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(
    include
)

zephyr_library_sources_ifdef(CONFIG_POWEROFF common/poweroff.c)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SOC_SERIES})
  add_subdirectory(${SOC_SERIES})
endif()
