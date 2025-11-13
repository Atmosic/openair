# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

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
