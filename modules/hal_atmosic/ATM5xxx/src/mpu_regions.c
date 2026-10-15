/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <soc.h>
#include <zephyr/arch/arm/mpu/arm_mpu.h>

#ifdef CONFIG_ATM_LCROM_IFACE
#include "libblell.h"
#endif

#define REGION_RAM_RO_ATTR(base, size) \
	{\
		.rbar = NOT_EXEC | \
			P_RO_U_RO_Msk | NON_SHAREABLE_Msk, /* AP, XN, SH */ \
		/* Cache-ability */ \
		.mair_idx = MPU_MAIR_INDEX_SRAM, \
		.r_limit = REGION_LIMIT_ADDR(base, size),  /* Region Limit */ \
	}

static struct arm_mpu_region const mpu_regions[] = {
	MPU_REGION_ENTRY("FLASH",
			 CONFIG_FLASH_BASE_ADDRESS,
			 REGION_FLASH_ATTR(CONFIG_FLASH_BASE_ADDRESS,
					   KB(CONFIG_FLASH_SIZE))),
	MPU_REGION_ENTRY("SRAM",
			 CONFIG_SRAM_BASE_ADDRESS,
			 REGION_RAM_ATTR(CONFIG_SRAM_BASE_ADDRESS,
					 KB(CONFIG_SRAM_SIZE))),
#ifdef CONFIG_ATM_LCROM_IFACE
	MPU_REGION_ENTRY("LCROM GOT",
			 LCROM_GOT_BASE,
			 REGION_RAM_RO_ATTR(LCROM_GOT_BASE,
					    LCROM_GOT_END - LCROM_GOT_BASE)),
#endif
};

struct arm_mpu_config const mpu_config = {
	.num_regions = ARRAY_SIZE(mpu_regions),
	.mpu_regions = mpu_regions,
};
