# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_DTM_2WIRE)

    zephyr_sources(
        dtm_hci_bridge.c
        dtm_mgr.c
        dtm_mgr_proc.c
    )

    zephyr_include_directories(
        include
    )

endif()
