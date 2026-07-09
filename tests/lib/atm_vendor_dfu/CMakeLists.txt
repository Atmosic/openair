# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(atm_vendor_dfu_test)

target_sources(app PRIVATE src/main.c)
target_sources_ifdef(CONFIG_ZTEST app PRIVATE src/test_atm_vendor_dfu.c)
target_sources_ifndef(CONFIG_ZTEST app PRIVATE src/dfu_test_app.c)
