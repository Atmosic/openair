# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

# Use configuration files (prj.conf) from the original Zephyr swapped_app
set(APPLICATION_CONFIG_DIR $ENV{ZEPHYR_BASE}/tests/boot/test_mcuboot/swapped_app
    CACHE PATH "Application configuration directory")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(test_mcuboot_multikey_swapped)

# Build sources from the original Zephyr swapped_app
FILE(GLOB app_sources $ENV{ZEPHYR_BASE}/tests/boot/test_mcuboot/swapped_app/src/*.c)
target_sources(app PRIVATE ${app_sources})

