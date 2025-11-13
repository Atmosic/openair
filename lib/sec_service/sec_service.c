/**
 ******************************************************************************
 *
 * @file sec_service.c
 *
 * @brief Secure services
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */
#ifdef CFG_NO_SPE
#ifndef SECURE_MODE
#define SECURE_MODE
#endif
#endif // CFG_NO_SPE
#include "arch.h"
#include "compiler.h"
#include <inttypes.h>
#include <arm_cmse.h>
#include <stdbool.h>
#include "sec_service.h"
#ifdef SECURE_PROC_ENV
#include "at_tz_ppc.h"
#endif
#if VERIFY_ATMWSTK
#include <string.h>
#include "atm_sha2.h"
#define _STR(s) #s
#define STR(s) _STR(s)
#include STR(ATMWSTK_SHA_H)
#endif

#ifdef CONFIG_ATM_PROT
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include "sec_assert.h"
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
#include "rram_rom_prot.h"
#endif
#ifdef CONFIG_DT_HAS_ATMOSIC_SEC_NV_MEM_FLASH_PROT_ENABLED
#include "flash_prot.h"
#endif
#include "sec_dev_lockout.h"
#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
#include "calibration.h"
#include "sec_jrnl.h"
#endif
#endif // CONFIG_ATM_PROT

#ifdef MCUBOOT_RD_PROTECT
#include "sec_assert.h"
#include "rram_rom_prot.h"
#include "mcuboot_slot_partitions.h"
#ifdef DEBUG_MCUBOOT_RD_PROTECT
#include "sec_cache.h"
#endif
#endif

#if (!defined(SECURE_MODE) && !defined(CFG_NO_SPE))
#error "sec_service is a secure-only library."
#endif

#ifdef SECURE_PROC_ENV
bool mem_check_has_access(void const *ptr, uint32_t len, bool ns_caller,
    bool write)
{
    int flags = (write) ? CMSE_MPU_READWRITE : CMSE_MPU_READ;

    if (ns_caller) {
	CONTROL_Type ctrl;
	ctrl.w = __TZ_get_CONTROL_NS();
	if (ctrl.b.nPRIV) {
	    flags |= CMSE_MPU_UNPRIV;
	}
	flags |= CMSE_NONSECURE;
    }

    return cmse_check_address_range(CONTEXT_VOID_P(ptr), len, flags);
}

// Default PPC configuration function
static void __sec_ppc_cfg(void)
{
	at_tz_ppc_init_ns_cfg();
}

void sec_ppc_cfg(void) __attribute__((weak, alias("__sec_ppc_cfg")));
#endif

#if VERIFY_ATMWSTK
bool verify_atmwstk(void)
{
    static uint32_t const atmwstk_sha[SHA256_DIG_WORDS] = ATMWSTK_SHA;
    uint8_t digest[SHA256_DIG_LEN];
    atm_sha256_params_t const sha256_params = {
	.mode = ATM_SHA256_SHA_MODE,
	.byte_endianess = ATM_SHA256_ENDIANESS_BIG,
	.digest_endianess = ATM_SHA256_ENDIANESS_LITTLE,
    };
    if (atm_sha256_init(&sha256_params) != ATM_SHA256_RES_SUCCESS) {
	return false;
    }

    if (atm_sha256_update_pio((void *)ATMWSTK_START, ATMWSTK_SIZE) !=
	ATM_SHA256_RES_SUCCESS) {
	atm_sha256_disable();
	return false;
    }
    atm_sha256_final(digest);
    atm_sha256_disable();
    if (memcmp(digest, atmwstk_sha, SHA256_DIG_LEN)) {
	return false;
    }
    return true;
}
#endif

#ifdef MCUBOOT_RD_PROTECT
// read protect MCUBOOT image partition
static void rd_protect_mcuboot(void)
{
#ifdef DEBUG_MCUBOOT_RD_PROTECT
    ICACHE_FLUSH();
    uint32_t mcuboot0 = *(uint32_t *)MCUBOOT_START_ADDRESS;
    uint32_t mcuboot1 = *(uint32_t *)(MCUBOOT_START_ADDRESS + 4);
    printf("MCUBOOT data 0x%" PRIx32 " 0:0x%" PRIx32 " 1:0x%" PRIx32 "\n",
	(uint32_t)MCUBOOT_START_ADDRESS, mcuboot0, mcuboot1);
#endif // DEBUG_MCUBOOT_RD_PROTECT
    uint32_t mcuboot_addr =
	RRAM_ADDR_TO_OFFSET((uint32_t)MCUBOOT_START_ADDRESS);
    uint32_t mcuboot_size = MCUBOOT_SIZE;
    bool rdprot_s = rram_prot_sticky_read_disable(mcuboot_addr, mcuboot_size);
    SEC_ASSERT(rdprot_s);
#ifdef DEBUG_MCUBOOT_RD_PROTECT
    printf("Rd lock MCUBOOT: 0x%" PRIx32 " l:0x%" PRIx32 "\n", mcuboot_addr,
	mcuboot_size);
#endif
#ifdef DEBUG_MCUBOOT_RD_PROTECT
    ICACHE_FLUSH();
    // these should not match
    uint32_t mcuboot_prot0 = *(uint32_t *)MCUBOOT_START_ADDRESS;
    uint32_t mcuboot_prot1 = *(uint32_t *)(MCUBOOT_START_ADDRESS + 4);
    printf("AFTER LOCK data 0x%" PRIx32 " 0:0x%" PRIx32 " 1:0x%" PRIx32 "\n",
	(uint32_t)MCUBOOT_START_ADDRESS, mcuboot_prot0, mcuboot_prot1);
    SEC_ASSERT(mcuboot_prot0 != mcuboot0);
    SEC_ASSERT(mcuboot_prot1 != mcuboot1);
#endif // DEBUG_MCUBOOT_RD_PROTECT
}
#endif // MCUBOOT_RD_PROTECT

#ifdef CONFIG_ATM_PROT
#define PART_ADDR(label)                                                                           \
	(DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(label))) +                           \
	 DT_REG_ADDR(DT_NODELABEL(label)))
#define PART_OFFSET(label) (DT_REG_ADDR(DT_NODELABEL(label)))
#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller)) &&                                               \
	!DT_SAME_NODE(DT_GPARENT(DT_NODELABEL(factory_partition)), DT_NODELABEL(rram0))
#error "Factory partition is not in RRAM"
#endif

static bool check_factory_part_lock(void)
{
	uint8_t lock;
	sec_jrnl_tag_len_t lock_len = sizeof(lock);

	if ((sec_jrnl_get(ATM_TAG_LOCK_FACTORY_DATA, &lock_len, &lock) == SEC_JRNL_OK) && lock) {
		return true;
	}

	return false;
}
#endif // factory_partition
#endif // CONFIG_ATM_PROT

void sec_lockdown(void)
{
#ifdef CONFIG_ATM_PROT
	__unused bool sec_s;

#ifdef CONFIG_ATM_PROT_DISABLE_ROM_PATCH
	// lock out the ROM patch controller
	sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_ROM_P_CFG);
	SEC_ASSERT(sec_s);
#endif

#ifdef CONFIG_ATM_PROT_DISABLE_OTP
	// lock out the OTP controller's write capability
	sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_OTP_WR);
	SEC_ASSERT(sec_s);
#endif

#if SHUB_LOCKOUT_SUPPORT && defined(CONFIG_ATM_PROT_DISABLE_SHUB)
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
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
		printk("factory data WP: 0x%x, 0x%x \n", factory_offset, factory_size);
		sec_s = rram_prot_sticky_write_disable(factory_offset, factory_size);
		SEC_ASSERT(sec_s);
#elif CONFIG_DT_HAS_ATMOSIC_SEC_NV_MEM_FLASH_PROT_ENABLED
		printk("factory data WP: 0x%x, 0x%x \n", factory_offset, factory_size);
		sec_s = flash_prot_sticky_write_disable(factory_offset, factory_size);
		SEC_ASSERT(sec_s);
#endif
	}
#endif // factory_partition

#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
#ifdef CONFIG_ATM_PROT_RP_BOOT_ROM
	// lock out the boot ROM
	uint32_t rom_offset = ROM_ADDR_TO_OFFSET(CMSDK_FLASH_BASE);
	printk("ROM RP: 0x%x, 0x%lx \n", rom_offset, ROM_SIZE);
	sec_s = rom_prot_sticky_read_disable(rom_offset, ROM_SIZE);
	SEC_ASSERT(sec_s);
#endif
#if DT_NODE_EXISTS(DT_NODELABEL(boot_partition)) && defined(CONFIG_ATM_PROT_RP_MCUBOOT)
	// read/write protect MCUBOOT partition
	uint32_t mcuboot_offset = PART_OFFSET(boot_partition);
	uint32_t mcuboot_size = DT_REG_SIZE(DT_NODELABEL(boot_partition));
	printk("MCUBoot RWP: 0x%x, 0x%x \n", mcuboot_offset, mcuboot_size);
	sec_s = rram_prot_sticky_write_disable(mcuboot_offset, mcuboot_size);
	SEC_ASSERT(sec_s);
	sec_s = rram_prot_sticky_read_disable(mcuboot_offset, mcuboot_size);
	SEC_ASSERT(sec_s);
#endif
#if DT_NODE_EXISTS(DT_NODELABEL(slot2_partition)) &&                                               \
	!DT_NODE_EXISTS(DT_NODELABEL(slot3_partition)) && defined(CONFIG_ATM_PROT_WP_ATMWSTK)
	// sticky lock atmwstk
	uint32_t atmwstk_offset = PART_OFFSET(slot2_partition);
	uint32_t atmwstk_size = DT_REG_SIZE(DT_NODELABEL(slot2_partition));
	printk("ATMWSTK WP: 0x%x, 0x%x \n", atmwstk_offset, atmwstk_size);
	sec_s = rram_prot_sticky_write_disable(atmwstk_offset, atmwstk_size);
	SEC_ASSERT(sec_s);
#endif
#ifdef WRPRPINS_RRAM_REMAP2__RESET_VALUE
	// lockout RRAM remapper
	sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_RRAM_REMAP);
	SEC_ASSERT(sec_s);
#endif // WRPRPINS_RRAM_REMAP2__RESET_VALUE
#endif // rram_controller

#if defined(WRPRPINS_RRAM_REMAP2__RESET_VALUE) ||                                                  \
	defined(__WRPRPINS_QSPI_STICKY_WRITE_PROTECTION3_MACRO__)
	// lockout FLASH remapper
	sec_s = sec_device_set_lockout(SEC_DEV_LOCKOUT_QSPI_REMAP);
	SEC_ASSERT(sec_s);
#endif // WRPRPINS_RRAM_REMAP2__RESET_VALUE || __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION3_MACRO__

#else
// NOTE: Baremetal handles the lockouts in the reference MCUBOOT and SPE apps as needed.
#ifdef MCUBOOT_RD_PROTECT
    rd_protect_mcuboot();
#endif
#endif // CONFIG_ATM_PROT
}

#ifdef CONFIG_ATM_PROT_AUTO
// in the absence of the SPE, lockdown the platform early
static int atm_prot_auto_lockdown(void)
{
	sec_lockdown();
	return 0;
}
SYS_INIT(atm_prot_auto_lockdown, POST_KERNEL, 0);
#endif
