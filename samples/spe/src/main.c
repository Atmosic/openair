/*
 * Copyright (c) 2022-2025 Atmosic
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
#include <zephyr/drivers/timer/system_timer.h>
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

#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
#include "calibration.h"
#include "sec_jrnl.h"
#endif

#ifdef CONFIG_ATM_SPE_DEBUG_TZ
#define TRACE_TZ_CFG printk
#else
#define TRACE_TZ_CFG(s, ...) \
    do { \
    } while (0)
#endif

extern irq_target_state_t irq_target_state_set(unsigned int irq,
    irq_target_state_t target_state);

#define PART_ADDR(label) ( \
    DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(label))) + \
    DT_REG_ADDR(DT_NODELABEL(label)) \
)

#define PART_OFFSET(label) (DT_REG_ADDR(DT_NODELABEL(label)))

// helper to get the address of a nested partition in a slot
#define PART_IN_SLOT_ADDR(slot_label, label) \
    (DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(slot_label))) + \
	DT_REG_ADDR(DT_NODELABEL(label)))

#ifndef CONFIG_BOOTLOADER_MCUBOOT
#define PART_SPE_ADDR() PART_ADDR(spe_partition)
#define PART_NSPE_ADDR() PART_ADDR(nspe_partition)
#define PART_FAST_CODE_ADDR() PART_ADDR(fast_code_partition)
#elif DT_NODE_EXISTS(DT_NODELABEL(slot2_partition)) && \
    DT_NODE_EXISTS(DT_NODELABEL(slot3_partition))
// This is an implicit MCUBOOT configuration
// the NSPE is now in slot2 with the OTA area in slot3
// for a signed image the start is after the image header
#define NSPE_APP_START_OFFSET CONFIG_ROM_START_OFFSET
#define PART_SPE_ADDR() PART_IN_SLOT_ADDR(slot0_partition, spe_partition)
#define PART_NSPE_ADDR() PART_IN_SLOT_ADDR(slot2_partition, nspe_partition)
// fast code is in slot 0
#define PART_FAST_CODE_ADDR() \
    PART_IN_SLOT_ADDR(slot0_partition, fast_code_partition)
#else // CONFIG_BOOTLOADER_MCUBOOT
#define PART_SPE_ADDR() PART_IN_SLOT_ADDR(slot0_partition, spe_partition)
#define PART_NSPE_ADDR() PART_IN_SLOT_ADDR(slot0_partition, nspe_partition)
#endif // CONFIG_BOOTLOADER_MCUBOOT

#ifndef NSPE_APP_START_OFFSET
#define NSPE_APP_START_OFFSET 0
#endif

#define PART_SPE_SIZE() DT_REG_SIZE(DT_NODELABEL(spe_partition))
#define PART_NSPE_SIZE() DT_REG_SIZE(DT_NODELABEL(nspe_partition))
#define PART_FAST_CODE_SIZE() DT_REG_SIZE(DT_NODELABEL(fast_code_partition))

#define PROG_MPC_PARTITION(part, base_partition) \
    do { \
	uint32_t part_baddr = \
	    DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(base_partition)) + \
	    DT_REG_ADDR(part); \
	uint32_t part_laddr = part_baddr + DT_REG_SIZE(part) - 1; \
	TRACE_TZ_CFG("MPC NS: [0x%08x - 0x%08x]\n", part_baddr, part_laddr); \
	at_tz_mpc_config_region(part_baddr, part_laddr, \
	    AT_TZ_MPC_ATTR_NONSECURE); \
    } while (0)

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
    at_tz_mpc_ret_t ret;

    // Configuring MPC of Flash
    ret = at_tz_mpc_enable_int(AT_TZ_MPC_DEV_FLASH);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);

#ifdef CONFIG_BOOTLOADER_MCUBOOT
#if CONFIG_ROM_START_OFFSET % AT_TZ_MPC_FLS_BLK_SIZE != 0
#error CONFIG_ROM_START_OFFSET must be aligned to 2k boundary
#endif
    // Allow mcumgr to read image header.
    uint32_t boot_hdr_baddr = PART_SPE_ADDR();
    uint32_t boot_hdr_laddr = boot_hdr_baddr + CONFIG_ROM_START_OFFSET - 1;
    TRACE_TZ_CFG("MPC BOOT hdr: [0x%08x - 0x%08x]\n", boot_hdr_baddr,
	boot_hdr_laddr);
    ret = at_tz_mpc_config_region(boot_hdr_baddr, boot_hdr_laddr,
	AT_TZ_MPC_ATTR_NONSECURE);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);
#endif // CONFIG_BOOTLOADER_MCUBOOT

#if !DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
    // FIXME, mark the region after the SPE up to the max. flash MPC
    // configurable region as non-secure
    uint32_t flash_ns_baddr =
	PART_SPE_ADDR() + DT_REG_SIZE(DT_NODELABEL(spe_partition));
    uint32_t flash_ns_laddr = DT_REG_ADDR(DT_NODELABEL(flash_controller)) +
	AT_TZ_MPC_EXT_FLASH_MPC_SIZE - 1;
    TRACE_TZ_CFG("MPC FLASH NS: [0x%08x - 0x%08x]\n", flash_ns_baddr,
	flash_ns_laddr);
    ret = at_tz_mpc_config_region(flash_ns_baddr, flash_ns_laddr,
	AT_TZ_MPC_ATTR_NONSECURE);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);
#endif

    // Configure remaining flash partitions.
    CONFIGURE_MPC_FLASH_PARTITIONS();
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
    // Permit access to RRAM registers
    ret = at_tz_mpc_config_region(ROM_RRAM_SIZE, ROM_RRAM_SIZE + 0x800 - 1,
	AT_TZ_MPC_ATTR_NONSECURE);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);
    // permit AT_PRRF_NONSECURE access and external Flash
    ret = at_tz_mpc_config_region(CMSDK_EXT_FLASH_NONSECURE_BASE - 0x800,
	CMSDK_EXT_FLASH_NONSECURE_BASE + AT_TZ_MPC_EXT_FLASH_MPC_SIZE - 1,
	AT_TZ_MPC_ATTR_NONSECURE);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);
#endif
    ret = at_tz_mpc_config_remaining_ext_flash(AT_TZ_MPC_ATTR_NONSECURE);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);

    // Configuring MPC of RAM
    ret = at_tz_mpc_enable_int(AT_TZ_MPC_DEV_RAM);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);
    ret = at_tz_mpc_config_region(DT_REG_ADDR(DT_NODELABEL(sram0)) +
	    DT_REG_SIZE(DT_NODELABEL(sram0)),
	DT_REG_ADDR(DT_NODELABEL(sram0)) + RAM_SIZE - 1,
	AT_TZ_MPC_ATTR_NONSECURE);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);
    ret = at_tz_mpc_enable_bus_fault(AT_TZ_MPC_DEV_FLASH);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);
    ret = at_tz_mpc_enable_bus_fault(AT_TZ_MPC_DEV_RAM);
    SEC_ASSERT(ret == AT_TZ_MPC_RET_OK);

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
    SEC_ASSERT(ret == AT_TZ_SAU_OK);
#endif

#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
    // Allocate RRAM, RRAM regs, prrf, and ext_flash as NS to save on SAU regions
    // Relies on NS region immediately following SPE.
    uint32_t rram_ns_start =
	PART_SPE_ADDR() + DT_REG_SIZE(DT_NODELABEL(spe_partition));
    uint32_t rram_flash_baddr = GET_PHYS_ADDR(rram_ns_start);
    uint32_t rram_flash_laddr =
#if DT_NODE_EXISTS(DT_NODELABEL(flash_controller))
	GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(flash_controller))) +
	DT_REG_SIZE(DT_NODELABEL(flash_controller)) - 1;
#else
	CMSDK_EXT_FLASH_NONSECURE_BASE - 1; // end just shy of ext_flash start
#endif
    TRACE_TZ_CFG("SAU RRAM NS: [0x%08x - 0x%08x]\n", rram_flash_baddr,
	rram_flash_laddr);
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(rram_flash_baddr),
	AT_TZ_SAU_LADDR_MASK(rram_flash_laddr), AT_TZ_SAU_NS);
    SEC_ASSERT(ret == AT_TZ_SAU_OK);
#else
    // flash (no RRAM) system
    // map everything after the SPE as non-secure to save on SAU entries
    uint32_t flash_ns_start =
	PART_SPE_ADDR() + DT_REG_SIZE(DT_NODELABEL(spe_partition));
    uint32_t flash_baddr = GET_PHYS_ADDR(flash_ns_start);
    // get the end of the flash address region (limited by the size of the
    // device)
    uint32_t flash_laddr =
	GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(flash_controller))) +
	DT_REG_SIZE(DT_NODELABEL(flash_controller)) - 1;
    TRACE_TZ_CFG("SAU FLASH NS: [0x%08x - 0x%08x]\n", flash_baddr, flash_laddr);
    ret =
	at_tz_sau_enable_region(sau_region++, AT_TZ_SAU_BADDR_MASK(flash_baddr),
	    AT_TZ_SAU_LADDR_MASK(flash_laddr), AT_TZ_SAU_NS);
    SEC_ASSERT(ret == AT_TZ_SAU_OK);
#endif //  DT_NODE_EXISTS(DT_NODELABEL(rram_controller))

    uint32_t ns_sram_baddr = GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(sram0))) +
	DT_REG_SIZE(DT_NODELABEL(sram0));
    uint32_t ns_sram_laddr =
	GET_PHYS_ADDR(DT_REG_ADDR(DT_NODELABEL(sram0))) + RAM_SIZE - 1;
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(ns_sram_baddr),
	AT_TZ_SAU_LADDR_MASK(ns_sram_laddr), AT_TZ_SAU_NS);
    SEC_ASSERT(ret == AT_TZ_SAU_OK);

    // Allocate non-secure callable region
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK((unsigned int)NSC_EN_REGION_START),
	AT_TZ_SAU_LADDR_MASK((unsigned int)NSC_EN_REGION_END), AT_TZ_SAU_NSC);
    SEC_ASSERT(ret == AT_TZ_SAU_OK);

    // Allocate peripheral region
    uint32_t peripheral_baddr = GET_PHYS_ADDR(
	DT_RANGES_PARENT_BUS_ADDRESS_BY_IDX(DT_PATH(soc, peripheral_50000000),
	    0));
    uint32_t peripheral_laddr = peripheral_baddr +
	DT_RANGES_LENGTH_BY_IDX(DT_PATH(soc, peripheral_50000000), 0) - 1;
    TRACE_TZ_CFG("SAU PERIPH NS: [0x%08x - 0x%08x]\n", peripheral_baddr,
	peripheral_laddr);
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(peripheral_baddr),
	AT_TZ_SAU_LADDR_MASK(peripheral_laddr), AT_TZ_SAU_NS);
    SEC_ASSERT(ret == AT_TZ_SAU_OK);

#ifdef CONFIG_BOOTLOADER_MCUBOOT
    // Allow mcumgr to read image header.
    uint32_t boot_hdr_baddr = GET_PHYS_ADDR(PART_SPE_ADDR());
    uint32_t boot_hdr_laddr = boot_hdr_baddr + CONFIG_ROM_START_OFFSET - 1;
    ret = at_tz_sau_enable_region(sau_region++,
	AT_TZ_SAU_BADDR_MASK(boot_hdr_baddr),
	AT_TZ_SAU_LADDR_MASK(boot_hdr_laddr), AT_TZ_SAU_NS);
    SEC_ASSERT(ret == AT_TZ_SAU_OK);
#endif // CONFIG_BOOTLOADER_MCUBOOT
#endif // CONFIG_ATM_SPE_DISABLE_SAU
    __DSB();
    __ISB();
    // SAU programming done early enough that only secure code has executed.
    // No need to invalidate the caches.
}

#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller)) && \
    !DT_SAME_NODE(DT_GPARENT(DT_NODELABEL(factory_partition)), \
	DT_NODELABEL(rram0))
#error "Factory partition is not in RRAM"
#endif

static bool check_factory_part_lock(void)
{
    uint8_t lock;
    sec_jrnl_tag_len_t lock_len = sizeof(lock);

    if ((sec_jrnl_get(ATM_TAG_LOCK_FACTORY_DATA, &lock_len, &lock) ==
	SEC_JRNL_OK) && lock) {
	return true;
    }

    return false;
}
#endif // factory_partition

// security lockdowns before the SAU is enabled
// At this stage all peripherals can be accessed by
// both their SECURE and NON-SECURE aliases
static void pre_sau_security_lockdown(void)
{
    bool sec_s;

#ifdef CONFIG_ATM_SPE_DISABLE_ROM_PATCH
    // lock out the ROM patch controller
    sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_ROM_P_CFG);
    SEC_ASSERT(sec_s);
#endif
#ifdef CONFIG_ATM_SPE_DISABLE_OTP
    // lock out the OTP controller's write capability
    sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_OTP_WR);
    SEC_ASSERT(sec_s);
#endif

#if SHUB_LOCKOUT_SUPPORT && defined(CONFIG_ATM_SPE_DISABLE_SHUB)
    // lock out shub
    sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_SHUB_DISABLE);
    SEC_ASSERT(sec_s);
    printk("SHUB disabled\n");
#endif

#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
    if (check_factory_part_lock()) {
	// write protect factory data partition
	uint32_t factory_offset = PART_OFFSET(factory_partition);
	uint32_t factory_size = DT_REG_SIZE(DT_NODELABEL(factory_partition));
	printk("factory data WP: 0x%x, 0x%x \n", factory_offset, factory_size);
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
	sec_s = rram_prot_sticky_write_disable(factory_offset, factory_size);
	SEC_ASSERT(sec_s);
#else
	// FIXME : flash write locks
#endif
    }
#endif // factory_partition

#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
#ifdef CONFIG_ATM_SPE_RP_BOOT_ROM
    // lock out the boot ROM
    uint32_t rom_offset = ROM_ADDR_TO_OFFSET(CMSDK_FLASH_BASE);
    printk("ROM RP: 0x%x, 0x%lx \n", rom_offset, ROM_SIZE);
    sec_s = rom_prot_sticky_read_disable(rom_offset, ROM_SIZE);
    SEC_ASSERT(sec_s);
#endif
#if DT_NODE_EXISTS(DT_NODELABEL(boot_partition)) && \
    defined(CONFIG_ATM_SPE_RP_MCUBOOT)
    // read/write protect MCUBOOT partition
    uint32_t mcuboot_offset = PART_OFFSET(boot_partition);
    uint32_t mcuboot_size = DT_REG_SIZE(DT_NODELABEL(boot_partition));
    printk("MCUBoot RWP: 0x%x, 0x%x \n", mcuboot_offset, mcuboot_size);
    sec_s = rram_prot_sticky_write_disable(mcuboot_offset, mcuboot_size);
    SEC_ASSERT(sec_s);
    sec_s = rram_prot_sticky_read_disable(mcuboot_offset, mcuboot_size);
    SEC_ASSERT(sec_s);
#endif

#if DT_NODE_EXISTS(DT_NODELABEL(slot2_partition)) && \
    !DT_NODE_EXISTS(DT_NODELABEL(slot3_partition)) && \
    defined(CONFIG_ATM_SPE_WP_ATMWSTK)
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
    printk("*** Zephyr SPE ***\n");
    printk("* SPE range: [0x%08x - 0x%08x]\n", (unsigned int)PART_SPE_ADDR(),
	(unsigned int)PART_SPE_ADDR() + (unsigned int)PART_SPE_SIZE() - 1);
#if DT_NODE_EXISTS(DT_NODELABEL(fast_code_partition))
    printk("* NSPE Fast Code range: [0x%08x - 0x%08x]\n",
	(unsigned int)PART_FAST_CODE_ADDR(),
	(unsigned int)PART_FAST_CODE_ADDR() +
	    (unsigned int)PART_FAST_CODE_SIZE() - 1);
#endif
    printk("* NSPE range: [0x%08x - 0x%08x]\n", (unsigned int)PART_NSPE_ADDR(),
	(unsigned int)PART_NSPE_ADDR() + (unsigned int)PART_NSPE_SIZE() - 1);
    uint32_t *application_addr = (uint32_t *)((
	(PART_NSPE_ADDR() + NSPE_APP_START_OFFSET) & ~0x10000000));
    printk("* NSPE non-sec start addr: %p \n", application_addr);
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

#ifdef CONFIG_ATM_SPE_DISABLE_SYSTICK
    // Disable secure SysTick
    sys_clock_disable();
#else
    NVIC_SetPriority(SysTick_IRQn, IRQ_PRI_MID);
#endif

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

    // // jump to application image.
    SCB_NS->VTOR = (uint32_t)application_addr;
    __TZ_set_MSP_NS(application_addr[0]);
    register uint32_t addr = application_addr[1] & ~0x1; // S->NS: clear LSB
    __ASM volatile("BXNS %0" : : "r"(addr));
    __builtin_unreachable();
}

#define CFSR_MMFSR_READ(cfsr) ((uint8_t)(cfsr & 0xff))
#define CFSR_BFSR_READ(cfsr) ((uint8_t)((cfsr >> 8) & 0xff))

void k_sys_fatal_error_handler(unsigned int reason, const struct arch_esf *pEsf)
{
    sec_switch_console();

    switch (reason) {
	case K_ERR_ARM_SECURE_ATTRIBUTION_UNIT: {
	    printk("**SecFault\n");
	    uint32_t sfar = SAU->SFAR;
	    if (sfar < ROM_SIZE) {
		// ROM starts at 0x0 - ROM_SIZE, this area is marked secure.
		// NS images will secure fault to here if it tries to access.
		// This could be a NULL pointer access or just accessing a
		// secured ROM location covered by the SAU
		printk("  NULL access to 0x%" PRIx32 "?\n", sfar);
	    }
	} break;
	default: {
	    printk("**Caught fatal system error -- reason %d\n", reason);
	} break;
    }

    printk("  xpsr: 0x%" PRIx32 "\n", pEsf->basic.xpsr);
    printk("  lr  : 0x%" PRIx32 "\n", pEsf->basic.lr);
    printk("  pc  : 0x%" PRIx32 "\n", pEsf->basic.pc);
    printk("  r0  : 0x%" PRIx32 "\n", pEsf->basic.r0);
    printk("  r1  : 0x%" PRIx32 "\n", pEsf->basic.r1);
    printk("  r2  : 0x%" PRIx32 "\n", pEsf->basic.r2);
    printk("  r3  : 0x%" PRIx32 "\n", pEsf->basic.r3);

    uint32_t _cfsr = SCB->CFSR;
    printk("  CFSR : 0x%" PRIx32 "\n", _cfsr);
    printk("  BFSR : 0x%x\n", CFSR_BFSR_READ(_cfsr));
    printk("  BFAR : 0x%" PRIx32 "\n", SCB->BFAR);
    printk("  MMFSR: 0x%x\n", CFSR_MMFSR_READ(_cfsr));
    printk("  MMFAR: 0x%" PRIx32 "\n", SCB->MMFAR);
    printk("  HFSR : 0x%" PRIx32 "\n", SCB->HFSR);
    printk("  SFSR : 0x%" PRIx32 "\n", SAU->SFSR);
    printk("  SFAR : 0x%" PRIx32 "\n", SAU->SFAR);

    // Some non-secure faults can be escalated to the secure side.
    // Dump non-secure status registers to help with debug.
    // Note:  the MMFSR may get cleared by the NS exception handler
    // before it escalates to the secure side.
    uint32_t _cfsr_ns = SCB_NS->CFSR;
    printk("  CFSR_NS : 0x%" PRIx32 "\n", _cfsr_ns);
    printk("  BFSR_NS : 0x%x\n", CFSR_BFSR_READ(_cfsr_ns));
    printk("  BFAR_NS : 0x%" PRIx32 "\n", SCB_NS->BFAR);
    printk("  MMFSR_NS: 0x%x\n", CFSR_MMFSR_READ(_cfsr_ns));
    printk("  MMFAR_NS: 0x%" PRIx32 "\n", SCB_NS->MMFAR);
    printk("  BFSR_NS : 0x%x\n", CFSR_BFSR_READ(_cfsr_ns));
    printk("  HFSR_NS : 0x%" PRIx32 "\n", SCB_NS->HFSR);

    printk("**Halting\n");
    k_fatal_halt(reason);
}

int main(void)
{
    spe_main();
    return 0;
}
