# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../)
set(SHIELD pervasive_epaper_e2266qs0f1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(peripheral_esl)


if(CONFIG_BT_ESLS_DISPLAY_NUM)
  target_sources(app PRIVATE
    display/esl_display.c
    display/esl_image.c
  )
  zephyr_include_directories(display)
endif()

target_sources(app PRIVATE
  src/main.c
)
