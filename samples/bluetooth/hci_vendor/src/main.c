/**
 *******************************************************************************
 *
 * @file main.c
 *
 * @brief HCI vendor command sample
 *
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from Atmosic.
 *
 * Copyright (C) Atmosic 2025
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from Atmosic.
 *
 *******************************************************************************
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
LOG_MODULE_REGISTER(LOG_HCI_VENDOR_MODULE_NAME, CONFIG_ATM_HCI_VENDOR_LOG_LEVEL);

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
