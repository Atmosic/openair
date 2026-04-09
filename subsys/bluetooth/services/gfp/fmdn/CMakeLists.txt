# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_FMDN)
  zephyr_include_directories(.)
  zephyr_library_sources(fp_fmdn.c)
  zephyr_library_sources(fp_fmdn_adv.c)
  zephyr_library_sources(fp_fmdn_gatt.c)
  zephyr_library_sources(fp_fmdn_key.c)
  zephyr_library_sources_ifdef(CONFIG_FMDN_PRECISION_FINDING fp_fhpf_gatt.c)
  if(CONFIG_FAST_PAIR_FMDN_V2)
    zephyr_library_sources(fp_fmdn_sba_gatt.c)
    zephyr_library_sources_ifdef(CONFIG_FMDN_PERSISTENT_CONNECTION fp_fmdn_persistent_conn.c)
    zephyr_library_sources_ifdef(CONFIG_FMDN_REVERSE_RINGING fp_fmdn_reverse_ringing.c)
    zephyr_library_sources_ifdef(CONFIG_FMDN_REVERSE_RINGING fp_fmdn_reverse_ringing_adv.c)
  endif()
endif()
