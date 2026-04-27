# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_SPE_FAULT_STORAGE)
    zephyr_include_directories(.)

    zephyr_sources_ifdef(CONFIG_TRUSTED_EXECUTION_SECURE atm_spe_sec_fault_storage.c)
endif()
