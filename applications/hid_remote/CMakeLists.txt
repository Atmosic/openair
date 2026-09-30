# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)
set(EXTRA_DTC_OVERLAY_FILE "app.overlay")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hid_remote)

include_directories(
  src
  src/bt
)

target_sources(app PRIVATE
  src/main.c
  src/rc_mmi.c
  src/rc_mmi_timer.c
  src/rc_input.c
  src/bt/rc_gap.c
  src/bt/rc_hids.c
)

if(CONFIG_RC_VOICE)
  target_sources(app PRIVATE src/rc_audio.c)
endif()

if(CONFIG_RC_LED)
  target_sources(app PRIVATE src/rc_led.c)
endif()

if(CONFIG_IR_NEC)
  target_sources(app PRIVATE src/rc_ir.c)
endif()

if(CONFIG_BT_IAS)
  target_sources(app PRIVATE src/rc_fmp.c)
endif()
