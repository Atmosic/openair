/*
 * Copyright (c) 2023-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/devicetree.h>

#if CONFIG_TRUSTED_EXECUTION_NONSECURE && DT_NODE_EXISTS(DT_NODELABEL(fast_code_partition))

#define PART_ADDR(label) ( \
    DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(label))) + \
    DT_REG_ADDR(DT_NODELABEL(label)) \
)

#ifndef CONFIG_ROMSTART_RELOCATION_ROM
#error "Split-Image ROM start region must be relocated to RRAM"
#endif

#define RRAM_START_ADDR DT_REG_ADDR(DT_NODELABEL(rram_controller))
#define RRAM_END_ADDR (RRAM_START_ADDR + DT_REG_SIZE(DT_NODELABEL(rram_controller)) - 1)

#if !((CONFIG_ROMSTART_REGION_ADDRESS >= RRAM_START_ADDR) && \
	(CONFIG_ROMSTART_REGION_ADDRESS <= RRAM_END_ADDR))
#error "Relocated ROM start region must be in RRAM"
#endif

// vector table is relocated to the beginning of the fast code section, code follows
#define VECTOR_TABLE_SIZE (CONFIG_ROMSTART_REGION_SIZE * 1K)
#define FAST_CODE_START_ADDR (CONFIG_ROMSTART_REGION_ADDRESS + VECTOR_TABLE_SIZE)
#define FAST_CODE_SIZE (DT_REG_SIZE(DT_NODELABEL(fast_code_partition)) - VECTOR_TABLE_SIZE)

MEMORY {
    RRAM (rx) : ORIGIN = FAST_CODE_START_ADDR, LENGTH = FAST_CODE_SIZE
}

SECTIONS {
    fast_code : {
	*/libarch*.a:(.text ".text.*" .rodata ".rodata.*")
	*/libblell*.a:(.text ".text.*" .rodata ".rodata.*")
	*/libc*.a:(.text ".text.*" .rodata ".rodata.*")
	*/libdrivers*.a:(.text ".text.*" .rodata ".rodata.*")
	*/libgcc.a:(.text ".text.*" .rodata ".rodata.*")
	*/libkernel.a:(.text ".text.*" .rodata ".rodata.*")
	*/libmbedTLS*.a:(.text ".text.*" .rodata ".rodata.*")
	*/lib*mbedtls.a:(.text ".text.*" .rodata ".rodata.*")
	*/lib*net_buf*.a:(.text ".text.*" .rodata ".rodata.*")
	*/libopenthread*.a:(.text ".text.*" .rodata ".rodata.*")
	*/libsubsys*.a:(.text ".text.*" .rodata ".rodata.*")
	*/libzephyr.a:(.text ".text.*" .rodata ".rodata.*")
	*_core.po(.text ".text.*" .rodata ".rodata.*")
	. = ALIGN(4);
    } > RRAM
}
#endif

#include <zephyr/arch/arm/cortex_m/scripts/linker.ld>
