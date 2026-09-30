# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_CS)
  zephyr_include_directories(.)
  zephyr_sources(atm_cs.c)
  # Expose BT host internals so test hooks can access struct bt_conn.ref
  zephyr_include_directories_ifdef(CONFIG_ZTEST ${ZEPHYR_BASE}/subsys/bluetooth/host)
endif()
