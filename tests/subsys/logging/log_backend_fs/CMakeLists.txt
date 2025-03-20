# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/subsys/logging/log_backend_fs)
set(APPLICATION_CONFIG_DIR $ENV{ZEPHYR_BASE}/${OA_APP_DIR})
list(APPEND BOARD_EXTENSION_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/boards)
set(KCONFIG_ROOT $ENV{ZEPHYR_BASE}/${OA_APP_DIR}/Kconfig)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(log_backend_fs)

add_subdirectory($ENV{ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
