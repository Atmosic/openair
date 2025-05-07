# Copyright (c) Atmosic 2024-2025
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_HCI_UART)
    zephyr_include_directories(.)
    zephyr_sources(atm_hci_uart.c)
endif()
