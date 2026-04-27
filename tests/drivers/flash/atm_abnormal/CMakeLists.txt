# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(DTC_OVERLAY_FILE boards/common.overlay)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(test_flash_atm_abnormal)

target_sources(app PRIVATE
  src/main.c
)
