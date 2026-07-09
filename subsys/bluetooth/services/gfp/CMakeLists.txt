# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_GFPS)
  zephyr_library()
  zephyr_include_directories(.)
  zephyr_library_sources(gfps.c)
  zephyr_library_sources(fp_adv.c)
  zephyr_library_sources(fp_auth.c)
  zephyr_library_sources(fp_conn.c)
  zephyr_library_sources(fp_gatt.c)
  zephyr_library_sources(fp_mode.c)
  zephyr_library_sources(fp_storage.c)
  add_subdirectory(fmdn)

  # Check config when FP_FMDN_PROVISION_EN_FP_ADV enabled
  if(NOT DEFINED CONFIG_BT_MAX_CONN)
    message(FATAL_ERROR "CONFIG_BT_MAX_CONN is not defined.")
  elseif(CONFIG_FP_FMDN_PROVISION_EN_FP_ADV)
    if(NOT CONFIG_FAST_PAIR_FMDN_MERGED_ADV)
      if(CONFIG_BT_MAX_CONN LESS 4)
        message(FATAL_ERROR "CONFIG_BT_MAX_CONN must greater than 3")
      endif()
    endif()
  endif()
  if(NOT DEFINED CONFIG_BT_EXT_ADV_MAX_ADV_SET)
    message(FATAL_ERROR "CONFIG_BT_EXT_ADV_MAX_ADV_SET is not defined.")
  elseif(CONFIG_FP_FMDN_PROVISION_EN_FP_ADV)
    if(NOT CONFIG_FAST_PAIR_FMDN_MERGED_ADV)
      if(CONFIG_BT_EXT_ADV_MAX_ADV_SET LESS 3)
        message(FATAL_ERROR "CONFIG_BT_EXT_ADV_MAX_ADV_SET must greater than 2")
      endif()
    endif()
  endif()

  # Check BT_MAX_PAIRED when FAST_PAIR_FMDN_V2 is enabled
  # FHN v2 (upcoming spec) requires at least 8 bonded devices; 16 is recommended.
  # Maximum supported is 16 due to NVS setting size.
  if(CONFIG_FAST_PAIR_FMDN_V2)
    if(NOT DEFINED CONFIG_BT_MAX_PAIRED)
      message(FATAL_ERROR "CONFIG_BT_MAX_PAIRED is not defined. FHN v2 requires CONFIG_BT_MAX_PAIRED in range [8, 16]")
    elseif(CONFIG_BT_MAX_PAIRED LESS 8)
      message(FATAL_ERROR "CONFIG_BT_MAX_PAIRED must be >= 8 for FHN v2 (currently ${CONFIG_BT_MAX_PAIRED})")
    elseif(CONFIG_BT_MAX_PAIRED GREATER 16)
      message(FATAL_ERROR "CONFIG_BT_MAX_PAIRED must be <= 16 for FHN v2 (currently ${CONFIG_BT_MAX_PAIRED})")
    endif()
  endif()
endif()

if(CONFIG_ATM_GFP_DIS)
  add_subdirectory(dis)
endif()
