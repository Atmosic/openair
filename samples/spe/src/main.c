/*
 * Copyright (c) 2022-2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <errno.h>
#include <zephyr/kernel.h>
#include <assert.h>
#include "arch.h"
#include <zephyr/devicetree.h>
#include <zephyr/arch/cpu.h>
#include <zephyr/init.h>
#include <soc.h>
#include <zephyr/storage/flash_map.h>
#include "vectors.h"
#include <zephyr/irq.h>
#include "at_tz_sau.h"
#include "at_tz_ppc.h"
#include "at_tz_mpc.h"

#include "at_wrpr.h"
#include "at_pinmux.h"
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
#include "rram_rom_prot.h"
#endif
#include "sec_dev_lockout.h"
#include "sec_assert.h"

extern irq_target_state_t irq_target_state_set(unsigned int irq,
    irq_target_state_t target_state);

#define PART_ADDR(label) ( \
    DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(label))) + \
    DT_REG_ADDR(DT_NODELABEL(label)) \
)

#define PART_OFFSET(label) (DT_REG_ADDR(DT_NODELABEL(label)))

#ifdef CONFIG_BOOTLOADER_MCUBOOT
// the merged SPE/NSPE slot needs the physical base address of the parent of
// slot0_partition
#define PART_SPE_NSPE_ADDR(label) \
    (DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(slot0_partition))) + \
	DT_REG_ADDR(DT_NODELABEL(label)))
#else
#define PART_SPE_NSPE_ADDR(label) PART_ADDR(label)
#endif

#define PROG_MPC_PARTITION(part, base_partition) do { \
	uint32_t part_baddr = \
	    DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(base_partition)) + \
	    DT_REG_ADDR(part); \
	uint32_t part_laddr = part_baddr + DT_REG_SIZE(part) - 1; \
	at_tz_mpc_config_region(part_baddr, part_laddr, AT_TZ_MPC_ATTR_NONSECURE); \
} while(0)

#define PROG_MPC_PARTITION_ENTRY(part, base_partition)  \
COND_CODE_1(DT_PROP(part, secure), (), ( \
	PROG_MPC_PARTITION(part, base_partition); \
 )) // !secure

#define MPC_PARTITION_ENTRY(part) \
COND_CODE_0(DT_CHILD_NUM(part),( \
        PROG_MPC_PARTITION_ENTRY(part, part) \
    ),( \
        DT_FOREACH_CHILD_VARGS( \
	    DT_CAT(part, _S_partitions), PROG_MPC_PARTITION_ENTRY, part \
	) \
    )) \

#define FIXED_PARTS_CHILDS(n) DT_FOREACH_CHILD(n, MPC_PARTITION_ENTRY)

#define CONFIGURE_MPC_FLASH_PARTITIONS() do { \
    DT_FOREACH_STATUS_OKAY(atmosic_tz_fixed_partitions, FIXED_PARTS_CHILDS) \
} while(0)

static void mpc_cfg(void)
{
    // Configuring MPC of Flash
    at_tz_mpc_enable_int(AT_TZ_MPC_DEV_FLASH);

#ifdef CONFIG_BOOTLOADER_MCUBOOT
#if CONFIG_ROM_START_OFFSET % AT_TZ_MPC_FLS_BLK_SIZE != 0
#error CONFIG_ROM_START_OFFSET must be aligned to 2k boundary
#endif
    // Allow mcumgr to read image header.
    uint32_t boot_hdr_baddr = PART_SPE_NSPE_ADDR(spe_partition);
    uint32_t boot_hdr_laddr = boot_hdr_baddr + CONFIG_ROM_START_OFFSET - 1;
    at_tz_mpc_config_region(boot_hdr_baddr, boot_hdr_laddr,
	AT_TZ_MPC_ATTR_NONSECURE);
#endif // CONFIG_BOOTLOADER_MCUBOOT

    // Configure remaining flash partitions.
    CONFIGURE_MPC_FLASH_PARTITIONS();
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
    // Permit access to RRAM registers
    at_tz_mpc_config_region(ROM_RRAM_SIZE, ROM_RRAM_SIZE + 0x800 - 1,
	AT_TZ_MPC_ATTR_NONSECURE);
    // permit AT_PRRF_NONSECURE access and external Flash
    at_tz_mpc_config_region(CMSDK_EXT_FLASH_NONSECURE_BASE - 0x800,
	CMSDK_EXT_FLASH_NONSECURE_BASE + AT_TZ_MPC_EXT_FLASH_MPC_SIZE - 1,
	AT_TZ_MPC_ATTR_NONSECURE);
#endif
    at_tz_mpc_config_remaining_ext_flash(AT_TZ_MPC_ATTR_NONSECURE);

    // Configuring MPC of RAM
    at_tz_mpc_enable_int(AT_TZ_MPC_DEV_RAM);
    at_tz_mpc_config_region(DT_REG_ADDR(DT_NODELABEL(sram0)) +
	    DT_REG_SIZE(DT_NODELABEL(sram0)),
	DT_REG_ADDR(DT_NODELABEL(sram0)) + RAM_SIZE - 1,
	AT_TZ_MPC_ATTR_NONSECURE);
    at_tz_mpc_enable_bus_fault(AT_TZ_MPC_DEV_FLASH);
    at_tz_mpc_enable_bus_fault(AT_TZ_MPC_DEV_RAM);

    return;
}

// Strip off IDAU bit to get physical address
#define GET_PHYS_ADDR(addr) ((addr) & ~0x10000000)

extern uint32_t __sg_start;
extern uint32_t __sg_end;
#define NSC_EN_REGION_START ((uint32_t)&__sg_start)
#define NSC_EN_REGION_END ((uint32_t)&__sg_end - 1)

static void sau_cfg(void)
{
#ifdef CONFIG_ATM_SPE_DISABLE_SAU
    at_tz_sau_disable();
#else
    at_tz_sau_enable();

    uint8_t sau_region = 0;
    at_tz_sau_ret_t ret;

#if DT_NODE_EXISTS(DT_NODELABEL(lc_partition))
    uint32_t phys_lc_baddr = GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(rom0))) +
	DT_REG_ADDR(DT_NODELABEL(lc_partition));
    uint32_t phys_lc_laddr = phys_lc_baddr +
	DT_REG_SIZE(DT_NODELABEL(lc_partition)) - 1;
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(phys_lc_baddr),
	AT_TZ_SAU_LADDR_MASK(phys_lc_laddr), AT_TZ_SAU_NS);
#endif

    // Allocate RRAM, RRAM regs, prrf, and ext_flash as NS to save on SAU regions
    // Relies on NS region immediately following SPE.
    uint32_t rram_ns_start = PART_SPE_NSPE_ADDR(spe_partition) +
	DT_REG_SIZE(DT_NODELABEL(spe_partition));
    uint32_t rram_flash_baddr = GET_PHYS_ADDR(rram_ns_start);
    uint32_t rram_flash_laddr =
	GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(flash_controller))) +
	DT_REG_SIZE(DT_NODELABEL(flash_controller)) - 1;
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(rram_flash_baddr),
	AT_TZ_SAU_LADDR_MASK(rram_flash_laddr), AT_TZ_SAU_NS);

    uint32_t ns_sram_baddr = GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(sram0))) +
	DT_REG_SIZE(DT_NODELABEL(sram0));
    uint32_t ns_sram_laddr =
	GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(sram0))) + RAM_SIZE - 1;
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(ns_sram_baddr),
	AT_TZ_SAU_LADDR_MASK(ns_sram_laddr), AT_TZ_SAU_NS);

    // Allocate non-secure callable region
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK((unsigned int)NSC_EN_REGION_START),
	AT_TZ_SAU_LADDR_MASK((unsigned int)NSC_EN_REGION_END), AT_TZ_SAU_NSC);

    // Allocate peripheral region
    uint32_t peripheral_baddr = GET_PHYS_ADDR(
	DT_RANGES_PARENT_BUS_ADDRESS_BY_IDX(DT_PATH(soc, peripheral_50000000),
	    0));
    uint32_t peripheral_laddr = peripheral_baddr +
	DT_RANGES_LENGTH_BY_IDX(DT_PATH(soc, peripheral_50000000), 0) - 1;
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(peripheral_baddr),
	AT_TZ_SAU_LADDR_MASK(peripheral_laddr), AT_TZ_SAU_NS);

#ifdef CONFIG_BOOTLOADER_MCUBOOT
    // Allow mcumgr to read image header.
    uint32_t boot_hdr_baddr = GET_PHYS_ADDR(PART_SPE_NSPE_ADDR(spe_partition));
    uint32_t boot_hdr_laddr = boot_hdr_baddr + CONFIG_ROM_START_OFFSET - 1;
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(boot_hdr_baddr),
	AT_TZ_SAU_LADDR_MASK(boot_hdr_laddr), AT_TZ_SAU_NS);
#endif // CONFIG_BOOTLOADER_MCUBOOT
#endif // CONFIG_ATM_SPE_DISABLE_SAU
    __DSB();
    __ISB();
    // SAU programming done early enough that only secure code has executed.
    // No need to invalidate the caches.
}

// security lockdowns before the SAU is enabled
// At this stage all peripherals can be accessed by
// both their SECURE and NON-SECURE aliases
static void pre_sau_security_lockdown(void)
{
    bool sec_s;

    // lock out the ROM patch controller
    sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_ROM_P_CFG);
    SEC_ASSERT(sec_s);
    // lock out the OTP controller's write capability
    sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_OTP_WR);
    SEC_ASSERT(sec_s);

#if SHUB_LOCKOUT_SUPPORT && defined(CONFIG_ATM_SPE_DISABLE_SHUB)
    // lock out shub
    sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_SHUB_DISABLE);
    SEC_ASSERT(sec_s);
    printk("SHUB disabled\n");
#endif

#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
    // lock out the ROM
    uint32_t rom_offset = ROM_ADDR_TO_OFFSET(CMSDK_FLASH_BASE);
    printk("ROM RP: 0x%x, 0x%lx \n", rom_offset, ROM_SIZE);
    sec_s = rom_prot_sticky_read_disable(rom_offset, ROM_SIZE);
    SEC_ASSERT(sec_s);

#if DT_NODE_EXISTS(DT_NODELABEL(boot_partition))
    // read/write protect MCUBOOT partition
    uint32_t mcuboot_offset = PART_OFFSET(boot_partition);
    uint32_t mcuboot_size = DT_REG_SIZE(DT_NODELABEL(boot_partition));
    printk("MCUBoot RWP: 0x%x, 0x%x \n", mcuboot_offset, mcuboot_size);
    sec_s = rram_prot_sticky_write_disable(mcuboot_offset, mcuboot_size);
    SEC_ASSERT(sec_s);
    sec_s = rram_prot_sticky_read_disable(mcuboot_offset, mcuboot_size);
    SEC_ASSERT(sec_s);
#endif

#if DT_NODE_EXISTS(DT_NODELABEL(slot2_partition))
    // sticky lock atmwstk
    uint32_t atmwstk_offset = PART_OFFSET(slot2_partition);
    uint32_t atmwstk_size = DT_REG_SIZE(DT_NODELABEL(slot2_partition));
    printk("ATMWSTK WP: 0x%x, 0x%x \n", atmwstk_offset, atmwstk_size);
    sec_s = rram_prot_sticky_write_disable(atmwstk_offset, atmwstk_size);
    SEC_ASSERT(sec_s);
#endif
#endif // rram_controller

    // NOTE: primary slot locking happens in MCUBOOT
}

// Perform any post-SAU security lock down.
// At this point memory/peripherals have been assigned to secure or non-secure.
static void post_sau_security_lockdown(void)
{
}

FUNC_NORETURN void spe_main(void)
{
    ICACHE->ICCTRL = ICACHE_ICCTRL_CACHEEN_Msk;

    printk("*** Zephyr SPE ***\n");
    printk("* SPE range: [0x%08x - 0x%08x]\n",
	(unsigned int)PART_SPE_NSPE_ADDR(spe_partition),
	(unsigned int)PART_SPE_NSPE_ADDR(spe_partition) +
	    (unsigned int)DT_REG_SIZE(DT_NODELABEL(spe_partition)));
    printk("* NSPE range: [0x%08x - 0x%08x]\n",
	(unsigned int)PART_SPE_NSPE_ADDR(nspe_partition),
	(unsigned int)PART_SPE_NSPE_ADDR(nspe_partition) +
	    (unsigned int)DT_REG_SIZE(DT_NODELABEL(nspe_partition)));
    printk("***\n");

    // Enables BusFault, MemFault, UsageFault and SecureFault
    SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_MEMFAULTENA_Msk |
	SCB_SHCSR_BUSFAULTENA_Msk | SCB_SHCSR_SECUREFAULTENA_Msk;

    // Allow fpu access in nonsecure mode.
    SCB->NSACR |= (1UL << SCB_NSACR_CP10_Pos) | (1UL << SCB_NSACR_CP11_Pos);

    // TODO: Handle Watchdog.

    // Permit NS Watchdog to reset system
    SYS_CTRL_REG->RESET_MASK |= SYS_CTRL_REG_SSE200_RESET_MASK_NSWD_EN_Msk;

    pre_sau_security_lockdown();

    // Enable and configure security controllers (SAU and MPC)
    sau_cfg();
    mpc_cfg();

    // Redirect interrupts to non-secure handlers
    IRQn_Type irq;
    for (irq = NSECUREWDOG_RESETREQ_IRQn; irq <= DUALTIMER_IRQn; irq++) {
	irq_target_state_set(irq, IRQ_TARGET_STATE_NON_SECURE);
    }
    for (irq = RESERVED_14_IRQn; irq <= PORT1_15_IRQn; irq++) {
	irq_target_state_set(irq, IRQ_TARGET_STATE_NON_SECURE);
    }
    // configure PPC to set peripherals to NS space.
    at_tz_ppc_init_ns_cfg();

    post_sau_security_lockdown();

    uint32_t *application_addr =
	(uint32_t *)(PART_SPE_NSPE_ADDR(nspe_partition) & ~0x10000000);
    // // jump to application image.
    SCB_NS->VTOR = (uint32_t)application_addr;
    __TZ_set_MSP_NS(application_addr[0]);
    register uint32_t addr = application_addr[1] & ~0x1; // S->NS: clear LSB
    __ASM volatile("BXNS %0" : : "r"(addr));
    __builtin_unreachable();
}

int main(void)
{
    spe_main();
    return 0;
}
