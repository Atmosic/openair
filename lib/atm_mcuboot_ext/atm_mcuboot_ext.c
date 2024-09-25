/**
 *******************************************************************************
 *
 * @file atm_mcuboot_ext.c
 *
 * @brief  Atmosic MCUBOOT extensions
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */
#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include <inttypes.h>
#include "mcuboot_config/mcuboot_config.h"
#include "atm_mcuboot_ext.h"
#include "at_apb_wrpr_pins_regs_core_macro.h"
#include "bootutil/bootutil.h"
#include "rram_rom_prot.h"
#include "sec_assert.h"

#if (defined(MCUBOOT_LOCK_PRIMARY_SLOT) && \
    !defined(WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__MASK))
// earlier SOCs require reset trampoline when slot is locked
#define MCUBOOT_RESET_TRAMPOLINE
#endif

#if (defined(MCUBOOT_SKIP_PRIMARY_VALIDATE_HIBER) || \
    defined(MCUBOOT_RESET_TRAMPOLINE))
#include "sec_reset.h"
#endif

#if (defined(MCUBOOT_RESET_TRAMPOLINE) || \
    defined(MCUBOOT_SKIP_PRIMARY_VALIDATE_HIBER))
static uint32_t get_swap_state(void)
{
    static uint32_t saved_swap_state; // non-zero when fetched

    if (!saved_swap_state) {
	saved_swap_state = boot_swap_type_multi(0);
	SEC_ASSERT(saved_swap_state);
    }
    return saved_swap_state;
}
#endif

#ifdef MCUBOOT_SKIP_PRIMARY_VALIDATE_HIBER

#ifndef DBG_IMG_VAL_HIB
#define DBG_IMG_VAL_HIB 0
#endif

static bool skip_img_validate;

static void check_skip_img_validation(void)
{
    DEBUG_TRACE_COND(DBG_IMG_VAL_HIB, "Reset Syn 0x%" PRIx32,
	secure_reset_get_syndrome());

    // check if the reset type allows for skip
    if (secure_reset_get_type() == SECURE_RESET_TYPE_HIB_ALLOW_IMG_SKIP) {
	// check that we did not have a pending upgrade comming out of hib.
	uint32_t swap_state = get_swap_state();
	if (swap_state != BOOT_SWAP_TYPE_NONE) {
	    DEBUG_TRACE("SKIP with inval swap : 0x%" PRIx32, swap_state);
	    // only allow skip if we are running normally (no upgrades)
	    goto img_validate;
	}
	DEBUG_TRACE_COND(DBG_IMG_VAL_HIB, "SKIP IMG Validate");
	skip_img_validate = true;
	return;
    }

img_validate:
    DEBUG_TRACE_COND(DBG_IMG_VAL_HIB, "IMG Validate required");
}
#endif

#ifdef MCUBOOT_RESET_TRAMPOLINE
#ifndef MCUBOOT_DBG_RST_TRAMP
#define MCUBOOT_DBG_RST_TRAMP 0
#endif

// Unlock RRAM sticky write locks
// The following resets will need a trampoline to clear sticky locks
//    -) Any watchdog reset
//    -) Any CPU or SW triggered reset
// Note: SOC, PoR, HIB resets will clear locks
static void check_reset_trampoline(void)
{
    // check if the reset cause may require the
    // trampoline
    DEBUG_TRACE_COND(MCUBOOT_DBG_RST_TRAMP, "Reset Syn 0x%" PRIx32,
	secure_reset_get_syndrome());
    if (secure_reset_get_type() != SECURE_RESET_TYPE_WARM) {
	// nothing to do, any sticky locks would be cleared
	return;
    }

    // now check img-0 swap state
    uint32_t swap_state = get_swap_state();
    DEBUG_TRACE_COND(MCUBOOT_DBG_RST_TRAMP, "Swap state %" PRIu32, swap_state);
    if ((swap_state != BOOT_SWAP_TYPE_PERM) &&
	(swap_state != BOOT_SWAP_TYPE_TEST) &&
	(swap_state != BOOT_SWAP_TYPE_REVERT)) {
	// note: if FAIL or PANIC is encountered we just return and let the
	// main body handle it
	return;
    }

    // An upgrade needs to be swapped, reverted or permanently applied.
    // Issue Soc Reset to clear any sticky locks
    // This will appear as a power-on-reset to the SSE200
    SYS_CTRL_REG->RESET_SYNDROME = 0;
    DEBUG_TRACE_COND(MCUBOOT_DBG_RST_TRAMP, "Soc Reset");
    WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__SET(CMSDK_WRPR0_NONSECURE->DBG_CTRL);
}
#endif // MCUBOOT_RESET_TRAMPOLINE

void atm_mcuboot_ext_startup(void)
{
#ifdef MCUBOOT_RESET_TRAMPOLINE
    check_reset_trampoline();
#endif
#ifdef MCUBOOT_SKIP_PRIMARY_VALIDATE_HIBER
    check_skip_img_validation();
#endif
}

bool atm_mcuboot_ext_skip_img_validation(void)
{
#ifdef MCUBOOT_SKIP_PRIMARY_VALIDATE_HIBER
    return skip_img_validate;
#else
    return false;
#endif
}

void atm_mcuboot_ext_lock_img_slots(sec_slot_desc_t const *desc)
{
    uint32_t s_protect_sz = desc->slot0_size;
    // keep a portion of the slot unlocked for the trailer
    s_protect_sz -= desc->slot0_trailer_unlock_size;
    bool pri_s =
	rram_prot_sticky_write_disable(desc->slot0_offset, s_protect_sz);
    SEC_ASSERT(pri_s);
    DEBUG_TRACE("Slot0 WR-Lock: 0x%" PRIx32 ":0x%" PRIx32 ",0x%" PRIx32,
	desc->slot0_offset, s_protect_sz, desc->slot0_size);
}
