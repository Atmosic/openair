# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_FMDN)
  zephyr_include_directories(.)
  zephyr_sources(fp_fmdn.c)
  zephyr_sources(fp_fmdn_adv.c)
  zephyr_sources(fp_fmdn_gatt.c)
  zephyr_sources(fp_fmdn_key.c)
endif()
