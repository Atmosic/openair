# Copyright (c) Atmosic 2024-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hci_vendor)

target_sources(app PRIVATE src/main.c)
