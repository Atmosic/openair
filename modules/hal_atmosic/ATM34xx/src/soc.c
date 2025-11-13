/*
 * Copyright (c) 2021-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/sys/reboot.h>
#include <soc.h>

#include "arch.h"
#include "at_wrpr.h"

#ifdef CONFIG_SOC_RESET_HOOK
#include "sec_hw_cfg.h"

void soc_reset_hook(void)
{
	ICACHE->ICCTRL = ICACHE_ICCTRL_CACHEEN_Msk;
	sec_hw_cfg_init();
}
#endif

void sys_arch_reboot(int type)
{
	switch (type) {
	case SYS_REBOOT_COLD:
		WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__SET(CMSDK_WRPR0_NONSECURE->DBG_CTRL);
		while(1);
		// wait for reset and this should be unreachable.
		break;
	case SYS_REBOOT_WARM:
		NVIC_SystemReset();
		break;
	default:
		/* Do nothing */
		break;
	}
}
