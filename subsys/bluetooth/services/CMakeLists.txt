# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_GFPS)
  add_subdirectory(gfp)
endif()

if(CONFIG_ATM_DULT)
  add_subdirectory(dult)
endif()

if((CONFIG_BT_RAS) OR (CONFIG_BT_RAS_CLIENT))
  add_subdirectory(ras)
endif()

if(CONFIG_ATM_BT_TPUTP)
  add_subdirectory(atm_bt_tput)
endif()
