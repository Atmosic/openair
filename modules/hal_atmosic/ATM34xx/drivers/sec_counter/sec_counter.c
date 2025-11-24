/**
 ******************************************************************************
 *
 * @file sec_counter.c
 *
 * @brief Secure Counter Driver
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#include "arch.h"
#include "atm_otp.h"
#include "string.h"
#include <inttypes.h>
#include "sec_counter.h"
#include <stdint.h>
#include "stdio.h"
#include "rram_rom_prot.h"
#ifdef SECURE_PROC_ENV
#include "sec_service.h"
#endif

#include "at_wrpr.h"
#include "at_apb_tsmc_nvm_regs_core_macro.h"
#include "sec_cache.h"

#if (!defined(SECURE_MODE) && !defined(CFG_NO_SPE))
#error "sec_counter is a secure-only driver. Access APIs through NSC functions"
#endif

#define SEC_CNTR_OTP_BIT 53

#define SEC_CNTR_SC0_ADDR 0x1008FEF0

#define SEC_CNTR_VERIFY_CNTR_IDX(idx) \
    (((idx) >= 0) && ((idx) < SEC_CNTR_NUM_CNTR))

#define SEC_CNTR_ADDR_BY_IDX(idx) \
    (uint16_t volatile *)(SEC_CNTR_SC0_ADDR + sizeof(uint16_t) * (idx))

#define SET_BIT(n, k) ((n) | (1UL << (k)))
#define CLEAR_BIT(n, k) ((n) & (~(1UL << (k))));

#define WP7_SECURE_DATA_BIT 31U

static void rram_write_enable_counters(void)
{
    uint32_t wp7 = CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION7;
    CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION7 = CLEAR_BIT(wp7, WP7_SECURE_DATA_BIT);
}

static void rram_write_disable_counters(void)
{
    uint32_t wp7 = CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION7;
    CMSDK_WRPR0_NONSECURE->RRAM_WRITE_PROTECTION7 = SET_BIT(wp7, WP7_SECURE_DATA_BIT);
    ICACHE_FLUSH();
}

bool sec_counters_enabled(void)
{
    atm_otp_t otp;
    bool __UNUSED otp_ok = atm_otp_read(&otp);
    ASSERT_INFO(otp_ok, 0, 0);
    return otp & ATM_OTP_MASK_RRAM_WRITE_LOCK_SECURE_COUNTERS;
}


sec_counter_ret_status_t sec_counter_read(uint8_t counter_idx, uint16_t *out)
{
    if (!SEC_CNTR_VERIFY_CNTR_IDX(counter_idx)) {
	return SEC_CNTR_INVALID_CNTR;
    }
    *out = *SEC_CNTR_ADDR_BY_IDX(counter_idx);
    return SEC_CNTR_OK;
}

sec_counter_ret_status_t sec_counter_incr(uint8_t counter_idx, uint16_t *out)
{
    if (!SEC_CNTR_VERIFY_CNTR_IDX(counter_idx)) {
	return SEC_CNTR_INVALID_CNTR;
    }
    sec_counter_ret_status_t ret = SEC_CNTR_OK;
    uint16_t volatile *cntr = SEC_CNTR_ADDR_BY_IDX(counter_idx);
    uint16_t new_val;
    uint16_t current_val = *cntr;
    if (current_val == SEC_CNTR_SATURATION_VAL) {
	ret = SEC_CNTR_SATURATED;
	goto incr_out;
    }
    rram_write_enable_counters();
    if (!rram_write_section_allowed()) {
	ret = SEC_CNTR_INCR_FAILED;
	goto incr_out;
    }
    ENTER_RRAM_WRITE_SECTION();
    {
	*cntr = current_val + 1;
    }
    LEAVE_RRAM_WRITE_SECTION();
    rram_write_disable_counters();
    new_val = *cntr;
    if (new_val != current_val + 1) {
	ret = SEC_CNTR_INCR_FAILED;
	goto incr_out;
    }
    if (out != NULL) {
	*out = new_val;
    }
incr_out:
    return ret;
}

sec_counter_ret_status_t sec_counter_set(uint8_t counter_idx, uint16_t value)
{
    if (sec_counters_enabled()) {
	// if the counters are enabled, unabled to freely set counter values
	return SEC_CNTR_SET_FAILED;
    }
    if (!SEC_CNTR_VERIFY_CNTR_IDX(counter_idx)) {
	return SEC_CNTR_INVALID_CNTR;
    }
    if (value > SEC_CNTR_SATURATION_VAL) {
	return SEC_CNTR_INVALID_SET_VAL;
    }

    uint16_t volatile *cntr = SEC_CNTR_ADDR_BY_IDX(counter_idx);
    rram_write_enable_counters();
    if (!rram_write_section_allowed()) {
	return SEC_CNTR_SET_FAILED;
    }
    ENTER_RRAM_WRITE_SECTION();
    {
	*cntr = value;
    }
    LEAVE_RRAM_WRITE_SECTION();
    rram_write_disable_counters();
    uint16_t current_val = *cntr;
    if (current_val != value) {
	return SEC_CNTR_SET_FAILED;
    }

    return SEC_CNTR_OK;
}

#ifdef SECURE_PROC_ENV
__SPE_NSC
bool nsc_sec_counters_enabled(void)
{
    return sec_counters_enabled();
}

__SPE_NSC
sec_counter_ret_status_t nsc_sec_counter_read(uint8_t counter_idx, uint16_t *out)
{
    if (!mem_check_has_access(out, sizeof(uint16_t), true, true)) {
	return SEC_CNTR_NO_ACCESS;
    }
    return sec_counter_read(counter_idx, out);
}

__SPE_NSC
sec_counter_ret_status_t nsc_sec_counter_incr(uint8_t counter_idx, uint16_t *out)
{
    if (!mem_check_has_access(out, sizeof(uint16_t), true, true)) {
	return SEC_CNTR_NO_ACCESS;
    }
    return sec_counter_incr(counter_idx, out);
}

__SPE_NSC
sec_counter_ret_status_t nsc_sec_counter_set(uint8_t counter_idx,
    uint16_t value)
{
    return sec_counter_set(counter_idx, value);
}
#elif defined(CFG_NO_SPE)
bool nsc_sec_counters_enabled(void)
    __attribute__((alias("sec_counters_enabled")));

sec_counter_ret_status_t nsc_sec_counter_read(uint8_t counter_idx,
    uint16_t *out) __attribute__((alias("sec_counter_read")));

sec_counter_ret_status_t nsc_sec_counter_incr(uint8_t counter_idx,
    uint16_t *out) __attribute__((alias("sec_counter_incr")));

sec_counter_ret_status_t nsc_sec_counter_set(uint8_t counter_idx,
    uint16_t value) __attribute__((alias("sec_counter_set")));
#endif
