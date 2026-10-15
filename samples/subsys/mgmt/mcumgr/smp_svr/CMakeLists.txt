# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR samples/subsys/mgmt/mcumgr/smp_svr)

# Ensure that APPLICATION_CONFIG_DIR does not have path errors during
# cross-platform compilation.
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})

set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/app.overlay)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(smp_svr)

add_subdirectory(${ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})

# This sample doesn't set an explicit LittleFS block_size for
# storage_partition, so LittleFS auto-detects it -- which defaults to 4096 on
# RRAM (no-explicit-erase) when other explicit-erase flash devices are also
# present, mounting storage_partition with the wrong block size. See
# src/littlefs_block_size_fix.c for details.
target_sources_ifdef(CONFIG_FILE_SYSTEM_LITTLEFS app PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/littlefs_block_size_fix.c)
zephyr_ld_option_ifdef(CONFIG_FILE_SYSTEM_LITTLEFS -Wl,--wrap=fs_mount)
