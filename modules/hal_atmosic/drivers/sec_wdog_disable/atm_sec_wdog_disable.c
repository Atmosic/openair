/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/init.h>
#include <errno.h>

#include "atm_sec_wdog_disable.h"
#include "arch.h"

#ifdef CONFIG_TRUSTED_EXECUTION_SECURE
#include "sec_service.h"
#endif

#ifdef CONFIG_TRUSTED_EXECUTION_SECURE
#ifndef CONFIG_ATM_NO_SPE
__SPE_NSC
#endif
void atm_disable_secure_watchdog(void)
{
    SECURE_WATCHDOG->LOCK = ATM_WATCHDOG_LOCK_MAGIC;
    SECURE_WATCHDOG->CTRL = 0;
    SECURE_WATCHDOG->LOCK = 0;
}
#endif /* CONFIG_TRUSTED_EXECUTION_SECURE */

#if defined(CONFIG_ATM_NO_SPE) || defined(CONFIG_TRUSTED_EXECUTION_NONSECURE)
static int atm_disable_sec_wdog_wrapper(void)
{
    atm_disable_secure_watchdog();

    return 0;
}

SYS_INIT(atm_disable_sec_wdog_wrapper, APPLICATION, 32);
#endif
