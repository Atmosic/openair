/*
 * Copyright (c) 2025 Atmosic
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/poweroff.h>
#include <zephyr/toolchain.h>
#include <zephyr/kernel.h>

#include "power.h"

void z_sys_poweroff(void)
{
	atm_pseq_soc_off(K_TICKS_FOREVER);

	CODE_UNREACHABLE;
}
