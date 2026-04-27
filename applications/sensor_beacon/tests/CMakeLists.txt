# SPDX-License-Identifier: LicenseRef-Atmosic
# Copyright (c) 2025-2026 Atmosic

cmake_minimum_required(VERSION 3.20.0)

# Use CMAKE_CURRENT_LIST_DIR to find the sensor beacon application directory
# Navigate from applications/sensor_beacon/tests to applications/sensor_beacon (1 level up)
get_filename_component(SB_APP_DIR "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

# Set the Kconfig root to include the sensor beacon application's Kconfig
set(KCONFIG_ROOT ${SB_APP_DIR}/Kconfig)

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
  ${SB_APP_DIR}/src/sensor_beacon.c
  ${SB_APP_DIR}/src/sensor_data.c
  ${SB_APP_DIR}/src/battery_monitor.c
  ${SB_APP_DIR}/src/beacon_adv.c
  ${SB_APP_DIR}/src/led_button_ctrl.c
)

# Conditionally include sensor sources
if(CONFIG_SENSOR)
  target_sources(app PRIVATE ${SB_APP_DIR}/src/sensor_interface.c)
endif()

# Include directories
target_include_directories(app PRIVATE
  ${SB_APP_DIR}/src/
  src/
)
