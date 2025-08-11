/**
 *******************************************************************************
 *
 * @file radio_hal_ble_cte.c
 *
 * @brief BLE CTE driver
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif
#include "arch.h"
#include "radio_hal_ble_cte.h"

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static int atm_mac_ble_cte_sys_init(void)
{
    atm_mac_ble_cte_init();
    return 0;
}

#ifdef CONFIG_SOC_FAMILY_ATM
SYS_INIT(atm_mac_ble_cte_sys_init, PRE_KERNEL_2, 10);
#endif
