# Copyright (c) Atmosic 2024-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_HCI_UART)
    zephyr_include_directories(.)
    zephyr_sources(atm_hci_uart.c)
endif()
