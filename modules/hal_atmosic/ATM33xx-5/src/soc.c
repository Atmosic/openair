/*
 * Copyright (c) 2021-2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <soc.h>

#ifdef CONFIG_PLATFORM_SPECIFIC_INIT
#include "sec_hw_cfg.h"

void z_arm_platform_init(void)
{
	sec_hw_cfg_init();
}
#endif
