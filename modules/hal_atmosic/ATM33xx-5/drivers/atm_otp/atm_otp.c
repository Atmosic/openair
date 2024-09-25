/**
 *******************************************************************************
 *
 * @file atm_otp.c
 *
 * @brief Atmosic OTP driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/init.h>
#endif
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include "arch.h"
#include "atm_otp.h"
#include "at_wrpr.h"
#include "at_apb_tsmc_nvm_regs_core_macro.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "atm_bp_clock.h"
#ifdef SECURE_PROC_ENV
#include "sec_service.h"
#endif

#if (!defined(SECURE_MODE) && !defined(CFG_NO_SPE))
#error "atm_otp is a secure-only driver. Access APIs through NSC functions"
#endif

#define CMSDK_NVM CMSDK_NVM_NONSECURE

static atm_otp_t otp;
static bool otp_valid;

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_WATCHDOG)
#endif
static void atm_otp_init_constructor(void)
{
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
    {
	// unset efuse override to restore OTP
	PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__CLR(CMSDK_PSEQ->OVERRIDES3);
	PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__CLR(CMSDK_PSEQ->OVERRIDES3);
    }
    WRPR_CTRL_POP();
    // Read OTP on boot. OTP changing after boot is not supported
    WRPR_CTRL_SET(CMSDK_NVM, WRPR_CTRL__CLK_ENABLE);
#ifdef NVM_T_CKHP__CYCLES__RESET_VALUE
    uint32_t clock = atm_bp_clock_get();
    uint32_t multiplier = clock / PCLK_ALT_FREQ;
    if (multiplier > 1) {
	CMSDK_NVM->T_CKHP = NVM_T_CKHP__CYCLES__RESET_VALUE * multiplier;
	CMSDK_NVM->T_HR_CK = NVM_T_HR_CK__CYCLES__RESET_VALUE * multiplier;
    }
#endif
    CMSDK_NVM->OPMODE = NVM_OPMODE__GO__MASK | NVM_OPMODE__READ__MASK;
    while (NVM_STATUS__RUNNING__READ(CMSDK_NVM->STATUS)) {
	YIELD();
    }
    otp = CMSDK_NVM->DATA1;
    otp = otp << (sizeof(uint32_t) * CHAR_BIT) | CMSDK_NVM->DATA0;
    WRPR_CTRL_SET(CMSDK_NVM, WRPR_CTRL__CLK_DISABLE);
    otp_valid = true;
}

bool atm_otp_read(atm_otp_t *otp_value)
{
    if (otp_valid) {
	*otp_value = otp;
    }
    return otp_valid;
}

#ifdef SECURE_PROC_ENV
__attribute__((cmse_nonsecure_entry)) __attribute__((used)) bool
nsc_atm_otp_read(atm_otp_t *otp_value)
{
    if (mem_check_has_access(otp_value, sizeof(atm_otp_t), true, true)) {
	return atm_otp_read(otp_value);
    }
    return false;
}
#elif defined(CFG_NO_SPE)
bool nsc_atm_otp_read(atm_otp_t *otp_value)
    __attribute__((alias("atm_otp_read")));
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
static int atm_otp_sys_init(void)
{
    atm_otp_init_constructor();
    return 0;
}

SYS_INIT(atm_otp_sys_init, PRE_KERNEL_2, 1);
#endif
