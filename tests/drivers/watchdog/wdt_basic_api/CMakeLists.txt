# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/drivers/watchdog/wdt_basic_api)

# Ensure that APPLICATION_CONFIG_DIR does not have path errors during
# cross-platform compilation.
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})

set(APPLICATION_BOARD_DIR ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND DTS_ROOT $ENV{ZEPHYR_BASE}/${OA_APP_DIR})
# this app requires an extra overlay
set(EXTRA_DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/extra_app.overlay)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(wdt_basic_api)

add_subdirectory(${ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
