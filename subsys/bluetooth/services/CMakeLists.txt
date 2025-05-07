# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_GFPS)
  add_subdirectory(gfp)
  if(CONFIG_FAST_PAIR_FMDN_DULT)
    add_subdirectory(dult)
  endif()
endif()
