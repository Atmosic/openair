# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR samples/bluetooth/periodic_sync_rsp)

# Ensure that APPLICATION_CONFIG_DIR does not have path errors during
# cross-platform compilation.
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(periodic_sync_rsp)

add_subdirectory(${ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
