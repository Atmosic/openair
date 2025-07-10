# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_GFPS)
  zephyr_include_directories(.)
  zephyr_sources(gfps.c)
  zephyr_sources(fp_adv.c)
  zephyr_sources(fp_conn.c)
  zephyr_sources(fp_gatt.c)
  zephyr_sources(fp_mode.c)
  zephyr_sources(fp_storage.c)
  add_subdirectory(fmdn)

  # Check config when FP_FMDN_PROVISION_EN_FP_ADV enabled
  if(NOT DEFINED CONFIG_BT_MAX_CONN)
    message(FATAL_ERROR "CONFIG_BT_MAX_CONN is not defined.")
  elseif(CONFIG_FP_FMDN_PROVISION_EN_FP_ADV AND CONFIG_BT_MAX_CONN LESS 4)
    message(FATAL_ERROR "CONFIG_BT_MAX_CONN must greater than 3")
  endif()
  if(NOT DEFINED CONFIG_BT_EXT_ADV_MAX_ADV_SET)
    message(FATAL_ERROR "CONFIG_BT_EXT_ADV_MAX_ADV_SET is not defined.")
  elseif(CONFIG_FP_FMDN_PROVISION_EN_FP_ADV AND CONFIG_BT_EXT_ADV_MAX_ADV_SET LESS 3)
    message(FATAL_ERROR "CONFIG_BT_EXT_ADV_MAX_ADV_SET must greater than 2")
  endif()
endif()
