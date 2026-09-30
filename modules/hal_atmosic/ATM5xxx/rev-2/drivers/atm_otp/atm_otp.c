/**
 *******************************************************************************
 *
 * @file atm_otp.c
 *
 * @brief Atmosic OTP driver
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <zephyr/init.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include "arch.h"
#include "atm_otp.h"
#include "at_wrpr.h"
#include "at_apb_umc_nvm_regs_core_macro.h"
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

static void atm_otp_init_constructor(void)
{
	// Read OTP on boot. OTP changing after boot is not supported
	WRPR_CTRL_SET(CMSDK_NVM, WRPR_CTRL__CLK_ENABLE);
	{
		UNVM_T_RD_TIME0__T_SUR_PD_CS__MODIFY(CMSDK_NVM->T_RD_TIME0, 12);
		UNVM_T_RD_TIME1__T_SUR_PD__MODIFY(CMSDK_NVM->T_RD_TIME1, 12);
		otp = CMSDK_NVM->OTP_CFG_HIGH;
		otp = otp << (sizeof(uint32_t) * CHAR_BIT) | CMSDK_NVM->OTP_CFG_LOW;
	}
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

void atm_otp_read_address(uint32_t const address, uint32_t const length, uint8_t *buf,
			  bool invertbit)
{
	WRPR_CTRL_PUSH(CMSDK_NVM, WRPR_CTRL__CLK_ENABLE)
	{
		for (uint16_t i = 0; i < length; i++) {
			CMSDK_NVM->OPMODE1 = UNVM_OPMODE1__OTP_A__WRITE(address + i);
			CMSDK_NVM->OPMODE = UNVM_OPMODE__GO__WRITE(1) | UNVM_OPMODE__READ__WRITE(1);

			while (!(CMSDK_NVM->STATUS & UNVM_STATUS__DONE__MASK)) {
				YIELD();
			}
			if (invertbit) {
				buf[i] = ~UNVM_STATUS__OTP_Q__READ(CMSDK_NVM->STATUS);
			} else {
				buf[i] = UNVM_STATUS__OTP_Q__READ(CMSDK_NVM->STATUS);
			}
		}
	}
	WRPR_CTRL_POP();
}

#ifdef SECURE_PROC_ENV
__SPE_NSC bool nsc_atm_otp_read(atm_otp_t *otp_value)
{
	if (mem_check_has_access(otp_value, sizeof(atm_otp_t), true, true)) {
		return atm_otp_read(otp_value);
	}
	return false;
}
#elif defined(CFG_NO_SPE)
bool nsc_atm_otp_read(atm_otp_t *otp_value) __attribute__((alias("atm_otp_read")));
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
static int atm_otp_sys_init(void)
{
	atm_otp_init_constructor();
	return 0;
}

SYS_INIT(atm_otp_sys_init, PRE_KERNEL_2, 1);
#endif
