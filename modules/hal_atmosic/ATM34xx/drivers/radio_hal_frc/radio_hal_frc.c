/**
 ******************************************************************************
 *
 * @file radio_hal_frc.c
 *
 * @brief Radio FRC Driver Interface
 *
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from Atmosic.
 *
 * Copyright (C) Atmosic 2022-2025
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from Atmosic.
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include <stdbool.h>
#include <stdint.h>

#include "base_addr.h"
#include "at_wrpr.h"
#include "at_lc_regs_core_macro.h"
#include "vectors.h"

#include "radio_hal_frc.h"
#include "radio_hal_prof.h"
#include "atm_utils_math.h"

static atm_mac_frc_callback_t frc_callbacks[ATM_MAC_FRC_NUM_TIMERS];
static atm_mac_prof_t frc_prof = ATM_MAC_PROF_WITH_THRESHOLD(50, LATENCY_FRC);

void ATLC_FRC_Handler(void)
{
    uint16_t latency =
	ATLC_LC_ST5__INTR_FRC_US_CNTR__READ(CMSDK_ATLC_NONSECURE->LC_ST5);

    if (ATLC_LC_FRC_IRQ__TO0__READ(CMSDK_ATLC_NONSECURE->LC_FRC_IRQ)) {
	// un-arm timeout
	ATLC_FRC_CTRL__TO0_ARM__CLR(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	// clear irq mask
	ATLC_LC_FRC_IRQM__TO0__CLR(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	// clear irq flag
	ATLC_LC_FRC_IRQC__TO0__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQC);
	// call callback
	if (frc_callbacks[ATM_MAC_FRC_TIMER0]) {
	    frc_callbacks[ATM_MAC_FRC_TIMER0]();
	}
    }
    if (ATLC_LC_FRC_IRQ__TO1__READ(CMSDK_ATLC_NONSECURE->LC_FRC_IRQ)) {
	// un-arm timeout
	ATLC_FRC_CTRL__TO1_ARM__CLR(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	// clear irq mask
	ATLC_LC_FRC_IRQM__TO1__CLR(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	// clear irq flag
	ATLC_LC_FRC_IRQC__TO1__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQC);
	// call callback
	if (frc_callbacks[ATM_MAC_FRC_TIMER1]) {
	    frc_callbacks[ATM_MAC_FRC_TIMER1]();
	}
    }
    if (ATLC_LC_FRC_IRQ__TO2__READ(CMSDK_ATLC_NONSECURE->LC_FRC_IRQ)) {
	// un-arm timeout
	ATLC_FRC_CTRL__TO2_ARM__CLR(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	// clear irq mask
	ATLC_LC_FRC_IRQM__TO2__CLR(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	// clear irq flag
	ATLC_LC_FRC_IRQC__TO2__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQC);
	// call callback
	if (frc_callbacks[ATM_MAC_FRC_TIMER2]) {
	    frc_callbacks[ATM_MAC_FRC_TIMER2]();
	}
    }
    atm_mac_prof_latency_update(&frc_prof, latency);
}

// asserts to ensure IRQ TOn bits are contiguous and start at bit 0
STATIC_ASSERT(ATLC_LC_FRC_IRQ__TO0__MASK == 0x1, "FRC_IRQ TO0 bit is not 0x1");
STATIC_ASSERT(ATLC_LC_FRC_IRQ__TO0__MASK << 1 == ATLC_LC_FRC_IRQ__TO1__MASK,
    "FRC_IRQ TO1 bit is not contiguous");
STATIC_ASSERT(ATLC_LC_FRC_IRQ__TO0__MASK << 2 == ATLC_LC_FRC_IRQ__TO2__MASK,
    "FRC_IRQ TO2 bit is not contiguous");
static bool atm_mac_frc_get_timer_pending(atm_mac_frc_timer_t timer)
{
    return (CMSDK_ATLC_NONSECURE->LC_FRC_IRQ) &
	(ATLC_LC_FRC_IRQ__TO0__MASK << timer);
}

static atm_mac_frc_error_t atm_mac_frc_get_next_timer(uint32_t *timeout_us,
    uint32_t current_time_us, atm_mac_frc_timer_t *timer)
{
    uint32_t timer_mask = CMSDK_ATLC_NONSECURE->FRC_CTRL &
	((1 << ATM_MAC_FRC_NUM_TIMERS) - 1);
    if (!timer_mask) {
	return ATM_MAC_FRC_ERROR_INACTIVE;
    }
    uint32_t frc_irq = CMSDK_ATLC_NONSECURE->LC_FRC_IRQ & timer_mask;
    if (frc_irq) {
	*timer = atm_ctz(frc_irq);
	if (timeout_us) {
	    *timeout_us = current_time_us;
	}
	return ATM_MAC_FRC_ERROR_EXPIRED;
    }
    int timer_idx = 0;
    uint32_t next_expiration = current_time_us - 1;
    uint32_t volatile *timeouts = &CMSDK_ATLC_NONSECURE->FRC_TO0;
    while (timer_mask) {
	if (timer_mask & ATLC_FRC_CTRL__TO0_ARM__MASK) {
	    uint32_t timeout = ATLC_FRC_TO0__VL__READ(timeouts[timer_idx]);
	    if (ATM_MAC_FRC_DELTA_US(current_time_us, timeout) <
		ATM_MAC_FRC_DELTA_US(current_time_us, next_expiration)) {
		next_expiration = timeout;
		*timer = timer_idx;
	    }
	}
	timer_mask >>= 1;
	timer_idx++;
    };
    if (timeout_us) {
	*timeout_us = next_expiration;
    }
    return ATM_MAC_FRC_ERROR_NONE;
}

uint32_t atm_mac_frc_get_current_time(void)
{
    // Not current when ATLC is asleep
    ASSERT_ERR(!ATLC_LC_LP_ST5__SLP_STATE__READ(
	CMSDK_ATLC_NONSECURE->LC_LP_ST5));
    return ATLC_LC_ST2__FR_US_CNTR__READ(CMSDK_ATLC_NONSECURE->LC_ST2);
}

atm_mac_frc_error_t atm_mac_frc_get_next_expiration(uint32_t current_time_us,
    uint32_t *timeout_us)
{
    atm_mac_frc_timer_t timer;
    return atm_mac_frc_get_next_timer(timeout_us, current_time_us, &timer);
}

// asserts to ensure TOn_ARM bits are contiguous and start at bit 0
STATIC_ASSERT(ATLC_FRC_CTRL__TO0_ARM__MASK == 0x1,
    "FRC_CTRL TO0_ARM bit is not 0x1");
STATIC_ASSERT(ATLC_FRC_CTRL__TO0_ARM__MASK << 1 == ATLC_FRC_CTRL__TO1_ARM__MASK,
    "FRC_CTRL TO1_ARM bit is not contiguous");
STATIC_ASSERT(ATLC_FRC_CTRL__TO0_ARM__MASK << 2 == ATLC_FRC_CTRL__TO2_ARM__MASK,
    "FRC_CTRL TO2_ARM bit is not contiguous");
static bool atm_mac_frc_get_timer_active(atm_mac_frc_timer_t timer)
{
    return (CMSDK_ATLC_NONSECURE->FRC_CTRL) &
	(ATLC_FRC_CTRL__TO0_ARM__MASK << timer);
}

atm_mac_frc_error_t atm_mac_frc_get_timer_expiration(atm_mac_frc_timer_t timer,
    uint32_t *timeout_us)
{
    if (timer >= ATM_MAC_FRC_NUM_TIMERS) {
	return ATM_MAC_FRC_ERROR_INVALID;
    }
    if (!atm_mac_frc_get_timer_active(timer)) {
	return ATM_MAC_FRC_ERROR_INACTIVE;
    }
    if (atm_mac_frc_get_timer_pending(timer)) {
	return ATM_MAC_FRC_ERROR_EXPIRED;
    }
    switch (timer) {
	case ATM_MAC_FRC_TIMER0:
	    *timeout_us = ATLC_FRC_TO0__VL__READ(CMSDK_ATLC_NONSECURE->FRC_TO0);
	    break;
	case ATM_MAC_FRC_TIMER1:
	    *timeout_us = ATLC_FRC_TO1__VL__READ(CMSDK_ATLC_NONSECURE->FRC_TO1);
	    break;
	case ATM_MAC_FRC_TIMER2:
	    *timeout_us = ATLC_FRC_TO2__VL__READ(CMSDK_ATLC_NONSECURE->FRC_TO2);
	    break;
	case ATM_MAC_FRC_NUM_TIMERS:
	default:
	    return ATM_MAC_FRC_ERROR_INVALID;
    }
    return ATM_MAC_FRC_ERROR_NONE;
}

atm_mac_frc_error_t atm_mac_frc_get_timer_remaining(atm_mac_frc_timer_t timer,
    uint32_t current_time_us, uint32_t *time_us)
{
    uint32_t timeout_us;
    atm_mac_frc_error_t error =
	atm_mac_frc_get_timer_expiration(timer, &timeout_us);
    *time_us = ATM_MAC_FRC_DELTA_US(current_time_us, timeout_us);
    return error;
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void atm_mac_frc_init(void)
{
    // Setup ATLC FRC IRQ
    NVIC_DisableIRQ(ATLC_FRC_IRQn);
    NVIC_ClearPendingIRQ(ATLC_FRC_IRQn);
    NVIC_SetPriority(ATLC_FRC_IRQn, IRQ_PRI_HIGH);
    NVIC_EnableIRQ(ATLC_FRC_IRQn);
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int atm_mac_frc_sys_init(void)
{
    atm_mac_frc_init();
    return 0;
}

SYS_INIT(atm_mac_frc_sys_init, PRE_KERNEL_2, 10);
#endif

atm_mac_frc_error_t atm_mac_frc_set_timer(atm_mac_frc_timer_t timer,
    uint32_t timeout_us, atm_mac_frc_callback_t callback)
{
    if (timer >= ATM_MAC_FRC_NUM_TIMERS) {
	return ATM_MAC_FRC_ERROR_INVALID;
    }
    // return immediately if timer is already active
    if (atm_mac_frc_get_timer_active(timer)) {
	return ATM_MAC_FRC_ERROR_BUSY;
    }

    frc_callbacks[timer] = callback;

    GLOBAL_INT_DISABLE();
    switch (timer) {
	case ATM_MAC_FRC_TIMER0:
	    ATLC_FRC_TO0__VL__MODIFY(CMSDK_ATLC_NONSECURE->FRC_TO0, timeout_us);
	    ATLC_FRC_CTRL__TO0_ARM__SET(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	    ATLC_LC_FRC_IRQM__TO0__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	    break;
	case ATM_MAC_FRC_TIMER1:
	    ATLC_FRC_TO1__VL__MODIFY(CMSDK_ATLC_NONSECURE->FRC_TO1, timeout_us);
	    ATLC_FRC_CTRL__TO1_ARM__SET(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	    ATLC_LC_FRC_IRQM__TO1__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	    break;
	case ATM_MAC_FRC_TIMER2:
	    ATLC_FRC_TO2__VL__MODIFY(CMSDK_ATLC_NONSECURE->FRC_TO2, timeout_us);
	    ATLC_FRC_CTRL__TO2_ARM__SET(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	    ATLC_LC_FRC_IRQM__TO2__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	    break;
	case ATM_MAC_FRC_NUM_TIMERS:
	default:
	    break;
    }
    // Trigger interrupt immediately if a timer was scheduled in the past
    uint32_t after_scheduling = atm_mac_frc_get_current_time();
    if (ATM_MAC_FRC_SIGNED_DELTA_US(after_scheduling, timeout_us) <= 0) {
	switch (timer) {
	    case ATM_MAC_FRC_TIMER0:
		ATLC_LC_FRC_IRQS__TO0__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQS);
		break;
	    case ATM_MAC_FRC_TIMER1:
		ATLC_LC_FRC_IRQS__TO1__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQS);
		break;
	    case ATM_MAC_FRC_TIMER2:
		ATLC_LC_FRC_IRQS__TO2__SET(CMSDK_ATLC_NONSECURE->LC_FRC_IRQS);
		break;
	    case ATM_MAC_FRC_NUM_TIMERS:
	    default:
		break;
	}
    }
    GLOBAL_INT_RESTORE();
    return ATM_MAC_FRC_ERROR_NONE;
}

void atm_mac_frc_stop_timer(atm_mac_frc_timer_t timer)
{
    switch (timer) {
	case ATM_MAC_FRC_TIMER0:
	    GLOBAL_INT_DISABLE();
	    ATLC_FRC_CTRL__TO0_ARM__CLR(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	    ATLC_LC_FRC_IRQM__TO0__CLR(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	    GLOBAL_INT_RESTORE();
	    break;
	case ATM_MAC_FRC_TIMER1:
	    GLOBAL_INT_DISABLE();
	    ATLC_FRC_CTRL__TO1_ARM__CLR(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	    ATLC_LC_FRC_IRQM__TO1__CLR(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	    GLOBAL_INT_RESTORE();
	    break;
	case ATM_MAC_FRC_TIMER2:
	    GLOBAL_INT_DISABLE();
	    ATLC_FRC_CTRL__TO2_ARM__CLR(CMSDK_ATLC_NONSECURE->FRC_CTRL);
	    ATLC_LC_FRC_IRQM__TO2__CLR(CMSDK_ATLC_NONSECURE->LC_FRC_IRQM);
	    GLOBAL_INT_RESTORE();
	    break;
	case ATM_MAC_FRC_NUM_TIMERS:
	default:
	    break;
    }
    if (timer < ATM_MAC_FRC_NUM_TIMERS) {
	frc_callbacks[timer] = NULL;
    }
}
