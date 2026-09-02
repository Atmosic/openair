/*
 * Copyright (C) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/drivers/flash.h>

#ifdef CONFIG_SOC_FLASH_ATM_BRINGUP_API
/**
 * @brief Bring the external flash up from an unknown state.
 *
 * Resets the QSPI controller and the flash device, configures the pinmux,
 * probes the device and programs the AHB bridge. Intended for images that
 * cannot rely on the ROM or a bootloader having done so, such as RAM resident
 * programming agents. Must complete before the flash driver initializes, which
 * then only recovers the discovered state.
 *
 * @param[in] init_pinmux Callback that assigns the QSPI signals to pins, or
 * NULL to use the device tree pins.
 *
 * @retval 0 on success
 * @retval -ENODEV when no flash device responds
 */
int flash_atm_bringup(void (*init_pinmux)(void));
#endif

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

	/*
	 * ATM read flash manufacturer ID.
	 */
	FLASH_ATM_EX_OP_MAN_ID,
};

#ifdef CONFIG_FLASH_ATM_RUID
struct flash_atm_ex_op_uid_out {
	union {
		uint32_t uid[4];
		uint8_t uid8[16];
	};
};
#endif

#ifdef CONFIG_FLASH_ATM_MAN_ID
/// SPI flash manufacturer IDs
#define FLASH_ATM_MAN_ID_MICRON   0x20
#define FLASH_ATM_MAN_ID_PUYA     0x85
#define FLASH_ATM_MAN_ID_MACRONIX 0xc2
#define FLASH_ATM_MAN_ID_GIANTEC  0xc4
#define FLASH_ATM_MAN_ID_GIGA     0xc8
#define FLASH_ATM_MAN_ID_FUDAN    0xa1
#define FLASH_ATM_MAN_ID_WINBOND  0xef

struct flash_atm_ex_op_man_id_out {
	uint8_t man_id;
};
#endif

struct flash_atm_ex_op_latency_lock_in {
	bool get;	// true to acquire, false to release
};

#endif // CONFIG_FLASH_EX_OP_ENABLED
