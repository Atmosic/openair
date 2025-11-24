# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/subsys/debug/coredump_backends)
set(APPLICATION_CONFIG_DIR $ENV{ZEPHYR_BASE}/${OA_APP_DIR})
set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/common.overlay)
set(KCONFIG_ROOT $ENV{ZEPHYR_BASE}/${OA_APP_DIR}/Kconfig)
set(CONF_FILE $ENV{ZEPHYR_BASE}/${OA_APP_DIR}/prj_flash_partition.conf)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(coredump_backends)

add_subdirectory($ENV{ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
