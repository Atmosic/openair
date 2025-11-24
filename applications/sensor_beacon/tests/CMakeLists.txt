# SPDX-License-Identifier: Apache-2.0
# Copyright (c) 2025 Atmosic

cmake_minimum_required(VERSION 3.20.0)

# Set the Kconfig root to include the parent application's Kconfig
set(KCONFIG_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../Kconfig)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(sensor_beacon_tests)

# Test sources
target_sources(app PRIVATE
  src/test_main.c
  src/test_sensor_interface.c
  src/test_battery_monitor.c
  src/test_beacon_adv.c
  src/test_sensor_data.c
)

# Include application sources for testing
target_sources(app PRIVATE
  ../src/sensor_beacon.c
  ../src/sensor_data.c
  ../src/battery_monitor.c
  ../src/beacon_adv.c
  ../src/led_button_ctrl.c
)

# Conditionally include sensor sources
if(CONFIG_SENSOR)
  target_sources(app PRIVATE ../src/sensor_interface.c)
endif()

# Include directories
target_include_directories(app PRIVATE
  ../src/
  src/
)
