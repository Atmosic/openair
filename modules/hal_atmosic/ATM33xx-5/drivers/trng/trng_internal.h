/**
 *******************************************************************************
 *
 * @file trng_internal.h
 *
 * @brief True Random Number Generator driver internal components
 *
 * Copyright (C) Atmosic 2018-2024
 *
 *******************************************************************************
 */

#pragma once

#ifndef TRNG_INTERNAL_DIRECT_INCLUDE_GUARD
#error "trng_internal.h should only be included in trng source files"
#endif

/**
 * @defgroup TRNG_INTERNAL TRNG_INTERNAL
 * @ingroup DRIVERS
 * @brief Internal components for TRNG drivers
 * @{
 */

#include "arch.h"
#include "timer.h"

#include "at_wrpr.h"
#include "rif_regs_core_macro.h"
#include "at_apb_trng_regs_core_macro.h"
#include "mdm_macro.h"
#include "at_clkrstgen.h"
#include "spi.h"
#include "radio_spi.h"
#include "at_apb_pseq_regs_core_macro.h"

#ifndef WRPR_CTRL__CLK_SEL
#define WRPR_CTRL__CLK_SEL 0
#endif

static bool is_fpga;
static bool sidet;

/**
 * @brief initializes the trng module.
 */
__STATIC_FORCEINLINE void trng_internal_constructor(void)
{
#ifdef PSEQ_PMU_STATUS__SI_DET__READ
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    {
	sidet = PSEQ_PMU_STATUS__SI_DET__READ(CMSDK_PSEQ->PMU_STATUS);
    }
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);
#endif

#ifdef __CLKRSTGEN_CONFIGURATION_MACRO__
    is_fpga = CLKRSTGEN_CONFIGURATION__INDEX__READ(
	CMSDK_CLKRSTGEN_NONSECURE->CONFIGURATION);
#endif

    WRPR_CTRL_SET(CMSDK_TRNG, WRPR_CTRL__SRESET);
}

/**
 * @brief Initiate DC calibration
 *
 * @return true if DC cal can be skipped
 */
#ifdef __MDM_DCCAL_CTRL_MACRO__
__STATIC_FORCEINLINE bool trng_internal_dccal_init(void)
{
    if (is_fpga) {
	// Skip DC offset calibration on FPGA
	return true;
    }
    WRPR_CTRL_SET(CMSDK_MDM, WRPR_CTRL__CLK_ENABLE);
    if (MDM_TIA_RETENT_DCCALRESULTS__DONE__READ(
	    CMSDK_MDM->TIA_RETENT_DCCALRESULTS)) {
	// No need to repeat dccal
	WRPR_CTRL_SET(CMSDK_MDM, WRPR_CTRL__CLK_DISABLE);
	return true;
    }

    WRPR_CTRL_SET(CMSDK_RIF, WRPR_CTRL__CLK_ENABLE);
    uint32_t mode_cntl = CMSDK_RIF->MODE_CNTL;
    RIF_MODE_CNTL__RX_EN__SET(mode_cntl);
    RIF_MODE_CNTL__RX_EN_OVR__SET(mode_cntl);
    RIF_MODE_CNTL__RXGAIN_OVR__SET(mode_cntl);
    CMSDK_RIF->MODE_CNTL = mode_cntl;
    RIF_RX0__LNA_PROTECT_OVR__MODIFY(CMSDK_RIF->RX0, 3);
    atm_timer_lpc_delay(3);

    MDM_DCCAL_CTRL__START__CLR(CMSDK_MDM->DCCAL_CTRL);
    MDM_DCCAL_CTRL__START__SET(CMSDK_MDM->DCCAL_CTRL);
    return false;
}

/**
 * @brief complete dc calibration
 */
__STATIC_FORCEINLINE void trng_internal_dccal_complete(void)
{
    MDM_DCCAL_CTRL__START__CLR(CMSDK_MDM->DCCAL_CTRL);
    WRPR_CTRL_SET(CMSDK_MDM, WRPR_CTRL__CLK_DISABLE);

    uint32_t mode_cntl = CMSDK_RIF->MODE_CNTL;
    RIF_MODE_CNTL__RX_EN__CLR(mode_cntl);
    RIF_MODE_CNTL__RX_EN_OVR__CLR(mode_cntl);
    RIF_MODE_CNTL__RXGAIN_OVR__CLR(mode_cntl);
    RIF_MODE_CNTL__RXGAIN__MODIFY(mode_cntl,
	45 + RIF_LNA__STEP1__READ(CMSDK_RIF->LNA));
    CMSDK_RIF->MODE_CNTL = mode_cntl;
    RIF_RX0__LNA_PROTECT_OVR__MODIFY(CMSDK_RIF->RX0, 0);
    WRPR_CTRL_SET(CMSDK_RIF, WRPR_CTRL__CLK_DISABLE);
}
#endif // __MDM_DCCAL_CTRL_MACRO__

#ifdef __RIF_TRNG_CONF_MACRO__
/**
 * @brief Check whether TRNG needs to be triggered
 */
__STATIC_FORCEINLINE bool trng_internal_go_pulse_needed(void)
{
    return (TRNG_CONTROL__LAUNCH_ON_RADIO_UP__READ(CMSDK_TRNG->CONTROL) &&
	!CMSDK_TRNG->STATUS &&
	ATLC_LC_LP_ST5__RADIO_EN__READ(CMSDK_ATLC_NONSECURE->LC_LP_ST5));
}
#endif

/**
 * @brief Set radio warmup cnt based on whether radio is already on
 */
__STATIC_FORCEINLINE void trng_internal_set_radio_warmup_cnt(bool radio_already_on)
{
    if (radio_already_on) {
#define TRNG_RADIO_SETTLING_TIME 800
	TRNG_CONTROL__RADIO_WARMUP_CNT__MODIFY(CMSDK_TRNG->CONTROL,
	    TRNG_RADIO_SETTLING_TIME);
    } else {
#ifdef __RIF_TRNG_CONF_MACRO__
	// use lower radio warmup time for FPGA
	CMSDK_TRNG->CONTROL = TRNG_CONTROL__RADIO_WARMUP_CNT__WRITE(
	    is_fpga ? 0x400 : TRNG_CONTROL__RADIO_WARMUP_CNT__RESET_VALUE);
#else
	// use default radio warmup time for FPGA
	CMSDK_TRNG->CONTROL = TRNG_CONTROL__RADIO_WARMUP_CNT__WRITE(
	    is_fpga ? TRNG_CONTROL__RADIO_WARMUP_CNT__RESET_VALUE : 0x7ff);
#endif
    }
}

/**
 * @brief (re)configure trng module
 */
__STATIC_FORCEINLINE void trng_internal_config(void)
{
    WRPR_CTRL_SET(CMSDK_TRNG, WRPR_CTRL__CLK_SEL | WRPR_CTRL__CLK_ENABLE);

    trng_internal_set_radio_warmup_cnt(false);

    // Enable interrupt
    CMSDK_TRNG->INTERRUPT_MASK = TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__MASK |
	TRNG_INTERRUPT_STATUS__TRNG_READY__MASK;
}

/**
 * @brief Collect a new random word immediately
 */
__STATIC_FORCEINLINE void trng_internal_force_go_pulse(void)
{
    TRNG_CONTROL__GO__CLR(CMSDK_TRNG->CONTROL);
    TRNG_CONTROL__GO__SET(CMSDK_TRNG->CONTROL);

    if (sidet) {
	return;
    }

    // Set synthesizer override
    WRPR_CTRL_PUSH(CMSDK_RADIO, WRPR_CTRL__CLK_ENABLE) {
	RADIO_TOP_WRITE(MODE_REG_ADDR, 0x3);
    } WRPR_CTRL_POP();
}

/**
 * @brief Clear synthesizer override set in trng_internal_force_go_pulse
 */
__STATIC_FORCEINLINE void trng_internal_clear_synth_override(void)
{
    if (!sidet) {
	// Clear synthesizer override
	WRPR_CTRL_PUSH(CMSDK_RADIO, WRPR_CTRL__CLK_ENABLE) {
	    RADIO_TOP_WRITE(MODE_REG_ADDR, 0x0);
	} WRPR_CTRL_POP();
    }
}

/// @} TRNG_INTERNAL
