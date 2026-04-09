# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/subsys/debug/coredump_backends)
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})
set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/common.overlay)
set(KCONFIG_ROOT ${APPLICATION_CONFIG_DIR}/Kconfig)
set(CONF_FILE ${APPLICATION_CONFIG_DIR}/prj_flash_partition.conf)

find_package(Zephyr REQUIRED HINTS ${OA_ZEPHYR_BASE})
project(coredump_backends)

add_subdirectory(${OA_ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
