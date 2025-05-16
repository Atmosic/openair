/*
 * Copyright (C) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <zephyr/drivers/flash.h>

#ifdef CONFIG_FLASH_EX_OP_ENABLED

enum atm_ex_ops {
	/*
	 * ATM read unique ID.
	 */
	FLASH_ATM_EX_OP_RUID = FLASH_EX_OP_VENDOR_BASE,

	/*
	 * Prevent/allow high latency operations on flash, such as erases.
	 */
	FLASH_ATM_EX_OP_LATENCY_LOCK,
};

#ifdef CONFIG_FLASH_ATM_RUID
struct flash_atm_ex_op_uid_out {
	union {
		uint32_t uid[4];
		uint8_t uid8[16];
	};
};
#endif

struct flash_atm_ex_op_latency_lock_in {
	bool get;	// true to acquire, false to release
};

#endif // CONFIG_FLASH_EX_OP_ENABLED
