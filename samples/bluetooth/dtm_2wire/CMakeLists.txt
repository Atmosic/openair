# DTM 2-wire sample application
# Copyright (C) Atmosic 2025

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(dtm_2wire)

target_sources(app PRIVATE src/main.c)
