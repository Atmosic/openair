# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ras_rreq_initiator)

include_directories(
  src
)

set(app_sources
  src/main.c
  src/rreq_smf.c
)

target_sources(app PRIVATE
  ${app_sources}
)
