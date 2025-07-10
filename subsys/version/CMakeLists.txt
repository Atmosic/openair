# Copyright (c) Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_VERSION)
  zephyr_include_directories(.)
  zephyr_sources(atm_version.c)

  file(READ "${CMAKE_CURRENT_LIST_DIR}/../../SDK_VERSION" ATMOSIC_SDK_VERSION_RAW)
  string(STRIP "${ATMOSIC_SDK_VERSION_RAW}" ATMOSIC_SDK_VERSION)

  zephyr_library_compile_definitions(
    -DATMOSIC_SDK_VERSION="OpenAir v${ATMOSIC_SDK_VERSION}"
  )
endif()
