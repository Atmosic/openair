/**
 ******************************************************************************
 *
 * @file sec_service.c
 *
 * @brief Secure services
 *
 * Copyright (C) Atmosic 2022-2024
 *
 ******************************************************************************
 */
#ifdef CFG_NO_SPE
#define SECURE_MODE
#endif
#include "arch.h"
#include "compiler.h"
#include <inttypes.h>
#include <arm_cmse.h>
#include <stdbool.h>
#include "sec_service.h"
#include "at_tz_ppc.h"
#if VERIFY_ATMWSTK
#include <string.h>
#include "atm_sha2.h"
#define _STR(s) #s
#define STR(s) _STR(s)
#include STR(ATMWSTK_SHA_H)
#endif

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

void sec_lockdown(void)
{
#ifdef MCUBOOT_RD_PROTECT
    rd_protect_mcuboot();
#endif
}

// Default PPC configuration function
static void __sec_ppc_cfg(void)
{
    at_tz_ppc_init_ns_cfg();
}

void sec_ppc_cfg(void) __attribute__ ((weak, alias("__sec_ppc_cfg")));
