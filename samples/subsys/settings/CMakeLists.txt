#
# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(atm_settings)

target_sources(app PRIVATE src/main.c)
