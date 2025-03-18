# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/drivers/gpio/gpio_basic_api)
set(APPLICATION_CONFIG_DIR $ENV{ZEPHYR_BASE}/${OA_APP_DIR})
list(APPEND BOARD_EXTENSION_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/boards)
list(APPEND DTS_ROOT $ENV{ZEPHYR_BASE}/${OA_APP_DIR})
set(KCONFIG_ROOT $ENV{ZEPHYR_BASE}/${OA_APP_DIR}/Kconfig)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(gpio_basic_api)

add_subdirectory($ENV{ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
