#
# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nsc_hello_world)

if(CONFIG_ATM_ENABLE_NSC_EXAMPLE)
    zephyr_include_directories(
	../spe/src/cust_sec_func
    )
endif()

target_sources(app PRIVATE src/main.c)
