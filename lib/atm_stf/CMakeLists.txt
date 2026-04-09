# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

# This is a wrapper module for the Samsung TagSDK.
# The actual TagSDK sources are in vendor/TagSDK.

if(CONFIG_ATM_STF)
  set(TAGSDK_PATH ${ZEPHYR_OPENAIR_MODULE_DIR}/../vendor/TagSDK)

  # TagSDK API include for applications
  zephyr_include_directories(${TAGSDK_PATH}/inc)

  # TagSDK TLS configuration (for mbedtls user config)
  zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tls_config)

  # Compile TagSDK sources
  add_subdirectory(${TAGSDK_PATH}/example/atmosic_zephyr ${CMAKE_CURRENT_BINARY_DIR}/atmosic_zephyr)
endif()
