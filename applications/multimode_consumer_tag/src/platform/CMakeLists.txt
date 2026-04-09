# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
target_sources_ifdef(CONFIG_FMNA_TAG app PRIVATE fmna_tag_platform.c)
target_sources_ifdef(CONFIG_FHN_TAG app PRIVATE fp_tag_platform.c)
target_sources_ifdef(CONFIG_STF_TAG app PRIVATE stf_tag_platform.c)
target_sources(app PRIVATE platform.c)
target_sources(app PRIVATE platform_ctrl_battery.c)
target_sources(app PRIVATE platform_ctrl_button.c)
target_sources(app PRIVATE platform_ctrl_buzzer.c)
target_sources(app PRIVATE platform_ctrl_led.c)
target_sources(app PRIVATE platform_ctrl_motion_detect.c)
target_sources_ifdef(CONFIG_TAG_BTN_OTA_MODE app PRIVATE platform_ctrl_ota.c)
target_sources(app PRIVATE platform_ctrl_wdt.c)
if(CONFIG_FHN_TAG AND CONFIG_FMDN_PRECISION_FINDING)
  target_sources(app PRIVATE fp_tag_platform_ranging.c)
endif()
