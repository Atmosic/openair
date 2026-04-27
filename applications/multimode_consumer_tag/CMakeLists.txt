# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(multimode_consumer_tag)

target_sources(app PRIVATE
  src/main.c
)

add_subdirectory(src/platform)
