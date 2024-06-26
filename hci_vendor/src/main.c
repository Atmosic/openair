/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief main
 *
 * Copyright (C) Atmosic 2024
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "arch.h"
#include "atm_vendor.h"

#define LOG_HCI_VENDOR_MODULE_NAME hci_vendor
LOG_MODULE_REGISTER(LOG_HCI_VENDOR_MODULE_NAME, CONFIG_ATM_LOG_DEFAULT_LEVEL);

void hci_vendor_init(void)
{
#ifdef CONFIG_RUNTIME_EN_HCI_VENDOR
    if (!atm_vendor_get_hci_vendor_en()) {
	atm_vendor_enter_hci_vendor_mode();
    }
#endif
    atm_vendor_init();
}

int main(void)
{
    hci_vendor_init();
    return 0;
}
