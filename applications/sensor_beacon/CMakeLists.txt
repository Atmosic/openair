# SPDX-License-Identifier: LicenseRef-Atmosic
# Copyright (c) 2025-2026 Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(EXTRA_DTC_OVERLAY_FILE "app.overlay")
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(sensor_beacon)

# Base application sources
set(app_sources
  src/main.c
  src/sensor_beacon.c
  src/sensor_data.c
  src/sensor_interface.c
  src/battery_monitor.c
  src/beacon_adv.c
  src/led_button_ctrl.c
  src/at_gatt.c
  src/at_cmd_manager.c
  src/beacon_adv_at_cmd.c
)

target_sources(app PRIVATE
  ${app_sources}
)

# Include directories
target_include_directories(app PRIVATE
  src/
)
