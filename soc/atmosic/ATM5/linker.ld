/*
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#if defined(CONFIG_TRUSTED_EXECUTION_NONSECURE) || defined(CONFIG_ATM_NO_SPE)

#include <zephyr/devicetree.h>

#define PART_ADDR(label) ( \
    DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(label))) + \
    DT_REG_ADDR(DT_NODELABEL(label)) \
)

#define LCROM_START_ADDR PART_ADDR(lc_partition)
#define LCROM_SIZE DT_REG_SIZE(DT_NODELABEL(lc_partition))
#define LCRAM_START_ADDR DT_REG_ADDR(DT_NODELABEL(sram_lc))
#define LCRAM_SIZE DT_REG_SIZE(DT_NODELABEL(sram_lc))

MEMORY {
    ROM_LC (rx) : ORIGIN = LCROM_START_ADDR, LENGTH = LCROM_SIZE
    RAM_LC (rx) : ORIGIN = LCRAM_START_ADDR, LENGTH = LCRAM_SIZE
}
#endif // CONFIG_TRUSTED_EXECUTION_NONSECURE) || ATM_NO_SPE

#include <zephyr/arch/arm/cortex_m/scripts/linker.ld>
