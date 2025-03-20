# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR samples/sensor/bme280)
set(APPLICATION_CONFIG_DIR $ENV{ZEPHYR_BASE}/${OA_APP_DIR})
set(APPLICATION_BOARD_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(KCONFIG_ROOT $ENV{ZEPHYR_BASE}/${OA_APP_DIR}/Kconfig)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(bme280)

add_subdirectory($ENV{ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
