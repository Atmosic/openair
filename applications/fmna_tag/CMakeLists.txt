# Copyright (c) 2025 Atmosic
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(fmna_tag)

target_sources(app PRIVATE
  src/battery.c
  src/main.c
  src/motion.c
  src/sound.c
)
