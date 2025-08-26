# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources(fmna_tag_platform.c)
zephyr_sources(fp_tag_platform.c)
zephyr_sources(platform.c)
zephyr_sources(platform_ctrl_battery.c)
zephyr_sources(platform_ctrl_button.c)
zephyr_sources(platform_ctrl_buzzer.c)
zephyr_sources(platform_ctrl_led.c)
zephyr_sources(platform_ctrl_motion_detect.c)
