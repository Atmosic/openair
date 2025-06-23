/**
 *******************************************************************************
 *
 * @file sec_reset.c
 *
 * @brief Secure reset driver implementation
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#include "arch.h"
#include "sec_service.h"
#include "sec_reset.h"

#if (!defined(SECURE_MODE) && !defined(CFG_NO_SPE))
#error "sec_reset is a secure-only driver"
#endif

#if (defined(MCUBOOT) || defined(CONFIG_MCUBOOT))
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "pseq_status.h"
#endif

static uint32_t get_and_clear_reset_syndrome(bool clear)
{
    static uint32_t reset_syndrome_check;
    if (!reset_syndrome_check) {
	reset_syndrome_check = SYS_CTRL_REG->RESET_SYNDROME;
	if (clear) {
	    SYS_CTRL_REG->RESET_SYNDROME = 0;
	}
    }
    return reset_syndrome_check;
}

#if (defined(MCUBOOT) || defined(CONFIG_MCUBOOT))

#define PSEQ_STATUS_TRIGGER_ALLOW_MASK \
    (PSEQ_STATUS__TIMER_TRIGGERED__MASK | PSEQ_STATUS__GPIO_TRIGGERED__MASK | \
	PSEQ_STATUS__WURX0_TRIGGERED__MASK | \
	PSEQ_STATUS__WURX1_TRIGGERED__MASK | \
	PSEQ_STATUS__QDEC_TRIGGERED__MASK | PSEQ_STATUS__KSM_TRIGGERED__MASK | \
	PSEQ_STATUS__SHUB_TRIGGERED__MASK | PSEQ_STATUS__SPI_TRIGGERED__MASK | \
	PSEQ_STATUS__I2C_TRIGGERED__MASK | PSEQ_STATUS__WURX_TRIGGERED__MASK)

#define SYS_WARM_RESET_MASK \
    (SYS_CTRL_REG_SSE200_RESET_SYNDROME_NSWD_Msk | \
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWD_Msk | \
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_RESETREQ_Msk | \
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWRESETREQ_Msk | \
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ0_Msk | \
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ1_Msk | \
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP0_Msk | \
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP1_Msk)

uint32_t secure_reset_get_syndrome(void)
{
    return get_and_clear_reset_syndrome(false);
}

secure_reset_type secure_reset_get_type(void)
{
    if (secure_reset_get_syndrome() & SYS_WARM_RESET_MASK) {
	return SECURE_RESET_TYPE_WARM;
    }

    static uint32_t pseq_po_reason;
    static bool check_pseq_po;
    if (!check_pseq_po) {
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
	    pseq_po_reason = CMSDK_PSEQ->STATUS & PSEQ_STATUS__POWER_ON_REASONS;
	}
	WRPR_CTRL_POP();
	check_pseq_po = true;
    }

    if (pseq_po_reason & PSEQ_STATUS_TRIGGER_ALLOW_MASK) {
	return SECURE_RESET_TYPE_HIB_ALLOW_IMG_SKIP;
    }

    if (pseq_po_reason) {
	return SECURE_RESET_TYPE_HIB;
    }

    // treat everything else from a security prespective as power-on
    return SECURE_RESET_TYPE_POR;
}

#else
__SPE_NSC
uint32_t secure_rclr_reset_syndrome(void)
{
    return get_and_clear_reset_syndrome(true);
}
#endif // MCUBOOT