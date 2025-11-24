# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.1)

set(EXTRA_DTC_OVERLAY_FILE "app.overlay")
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(multimode_consumer_tag)

target_sources(app PRIVATE
  src/main.c
)

if(CONFIG_STF_TAG)
  add_definitions(-w)

  SET(TAGSDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/TagSDK)

  zephyr_include_directories(${TAGSDK_PATH}/inc)

  include_directories(
    ${TAGSDK_PATH}/inc
    ${TAGSDK_PATH}/conf
    ${TAGSDK_PATH}/port/inc
    ${TAGSDK_PATH}/port/atmosic_zephyr
    ${TAGSDK_PATH}/example/atmosic_zephyr
  )

  add_subdirectory(${TAGSDK_PATH}/example/atmosic_zephyr ./atmosic_zephyr)

  add_definitions(-DMBEDTLS_ALLOW_PRIVATE_ACCESS -Dmbedtls_sha256_ret=mbedtls_sha256)
  zephyr_library_include_directories(${ZEPHYR_BASE}/samples/bluetooth)
  zephyr_include_directories(${APPLICATION_SOURCE_DIR}/src/tls_config)
endif()

add_subdirectory(src/platform)
