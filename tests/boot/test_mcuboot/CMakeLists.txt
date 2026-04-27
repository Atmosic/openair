# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/boot/test_mcuboot)
# Point to the original test location for configuration files (prj.conf, etc.)
set(APPLICATION_CONFIG_DIR $ENV{ZEPHYR_BASE}/${OA_APP_DIR}
    CACHE PATH "Application configuration directory")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(test_mcuboot)

target_sources(app PRIVATE ${ZEPHYR_BASE}/${OA_APP_DIR}/src/main.c)
