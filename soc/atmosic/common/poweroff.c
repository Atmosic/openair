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
	atm_pseq_soc_off(IDLE_FOREVER);

	CODE_UNREACHABLE;
}
