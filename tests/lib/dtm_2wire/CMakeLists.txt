# Copyright (c) 2025 Atmosic
# 
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

# common overlay file
set(DTC_OVERLAY_FILE boards/common.overlay)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(dtm_2wire_test)

target_sources(app PRIVATE
  src/main.c
  src/test_dtm_hci_bridge.c
  src/test_dtm_message_processing.c
  src/test_dtm_state_machine.c
)
