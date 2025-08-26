# SPDX-License-Identifier: Apache-2.0
# Copyright (c) 2025 Atmosic

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(sensor_beacon)

# Application sources
set(app_sources
  src/main.c
  src/sensor_beacon.c
  src/sensor_data.c
  src/sensor_interface.c
  src/battery_monitor.c
  src/beacon_adv.c
)

target_sources(app PRIVATE
  ${app_sources}
)

# Include directories
target_include_directories(app PRIVATE
  src/
)
