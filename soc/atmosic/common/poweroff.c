/*
 * Copyright (c) 2025-2026 Atmosic
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/sys/poweroff.h>
#include <zephyr/toolchain.h>
#include <zephyr/kernel.h>

#include "power.h"

void z_sys_poweroff(void)
{
	atm_pseq_soc_off(0, ATM_PD_URGENCY_GRACEFUL);

	CODE_UNREACHABLE;
}
