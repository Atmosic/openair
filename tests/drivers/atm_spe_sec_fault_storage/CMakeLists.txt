# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(test_atm_spe_sec_fault_storage)

target_sources(app PRIVATE
  src/main.c
)

zephyr_sources_ifdef(CONFIG_TEST_LOG_PANIC src/test_log_backend.c)
