/*
 * Copyright (c) 2021-2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <soc.h>

#ifdef CONFIG_SOC_RESET_HOOK
#include "sec_hw_cfg.h"

void soc_reset_hook(void)
{
	sec_hw_cfg_init();
}
#endif
