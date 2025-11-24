# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_FMNA_TAG fmna_tag_platform.c)
zephyr_sources_ifdef(CONFIG_FHN_TAG fp_tag_platform.c)
zephyr_sources_ifdef(CONFIG_STF_TAG stf_tag_platform.c)
zephyr_sources(platform.c)
zephyr_sources(platform_ctrl_battery.c)
zephyr_sources(platform_ctrl_button.c)
zephyr_sources(platform_ctrl_buzzer.c)
zephyr_sources(platform_ctrl_led.c)
zephyr_sources(platform_ctrl_motion_detect.c)
zephyr_sources_ifdef(CONFIG_TAG_BTN_OTA_MODE platform_ctrl_ota.c)
zephyr_sources(platform_ctrl_wdt.c)
if(CONFIG_FHN_TAG AND CONFIG_FMDN_PRECISION_FINDING)
  zephyr_sources(fp_tag_platform_ranging.c)
endif()
