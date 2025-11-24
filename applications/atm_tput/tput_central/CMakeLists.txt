# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
set(EXTRA_DTC_OVERLAY_FILE "app.overlay")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(tput_central)

include_directories(
  src
)

set(app_sources
  src/main.c
)

target_sources(app PRIVATE
  ${app_sources}
)
