#
# Copyright (c) 2022 Atmosic
#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(bootloader)

target_sources(app PRIVATE
    src/main.c
)

target_sources_ifdef(CONFIG_ATM_ENABLE_NSC_EXAMPLE app PRIVATE src/cust_sec_func/cust_sec_func.c)

zephyr_compile_options(
    -DSECURE_PROC_ENV=1
)
