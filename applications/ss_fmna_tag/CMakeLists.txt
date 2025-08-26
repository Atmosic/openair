# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

add_definitions(-w)
project(ss_fmna_tag)

SET(TAGSDK_PATH "../../../vendor/TagSDK")

include_directories(.)
include_directories(${TAGSDK_PATH}/inc)
include_directories(${TAGSDK_PATH}/conf)
include_directories(${TAGSDK_PATH}/port/inc)
include_directories(${TAGSDK_PATH}/port/atmosic_zephyr)
include_directories(${TAGSDK_PATH}/example/atmosic_zephyr)

add_subdirectory(${TAGSDK_PATH}/example/atmosic_zephyr ./atmosic_zephyr)

target_sources(app PRIVATE
    src/battery.c
    src/main.c
    src/motion.c
    src/sound.c
    )

add_definitions(-DMBEDTLS_ALLOW_PRIVATE_ACCESS -Dmbedtls_sha256_ret=mbedtls_sha256)
zephyr_library_include_directories(${ZEPHYR_BASE}/samples/bluetooth)
zephyr_include_directories(${APPLICATION_SOURCE_DIR}/src/tls_config)
