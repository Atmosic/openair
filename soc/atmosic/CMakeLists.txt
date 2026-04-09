# Copyright (c) 2021-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(
    include
)

zephyr_library_sources_ifdef(CONFIG_POWEROFF common/poweroff.c)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SOC_SERIES})
  add_subdirectory(${SOC_SERIES})
endif()
