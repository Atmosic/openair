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
#include "at_lc_regs_core_macro.h"

#ifndef WRPR_CTRL__CLK_SEL
#define WRPR_CTRL__CLK_SEL 0
#endif

#ifdef __RIF_TRNG_CONF_MACRO__
#define TIA_PGA_GAIN_MASK 0x7f
#endif

static bool is_fpga;

/**
 * @brief initializes the trng module.
 */
__INLINE void trng_internal_constructor(void)
{
#ifdef __CLKRSTGEN_CONFIGURATION_MACRO__
    is_fpga = CLKRSTGEN_CONFIGURATION__INDEX__READ(
	CMSDK_CLKRSTGEN_NONSECURE->CONFIGURATION);
#endif

    WRPR_CTRL_SET(CMSDK_TRNG, WRPR_CTRL__SRESET);
    REV_HASH_CHECK(CMSDK_TRNG, TRNG);
}

/**
 * @brief Initiate DC calibration
 *
 * @return true if DC cal can be skipped
 */
#ifdef __MDM_DCCAL_CTRL_MACRO__
__INLINE bool trng_internal_dccal_init(void)
{
    if (is_fpga) {
	// Skip DC offset calibration on FPGA
	return true;
    }
    WRPR_CTRL_SET(CMSDK_MDM, WRPR_CTRL__CLK_ENABLE);
#ifdef __RIF_TRNG_CONF_MACRO__
    if ((MDM_DCCAL2__BB1I_DCOC_TRNG__READ(CMSDK_MDM->DCCAL2) !=
	MDM_DCCAL2__BB1I_DCOC_TRNG__RESET_VALUE) &&
	(MDM_DCCAL2__BB1Q_DCOC_TRNG__READ(CMSDK_MDM->DCCAL2) !=
	MDM_DCCAL2__BB1Q_DCOC_TRNG__RESET_VALUE)) {
#else
    if (MDM_TIA_RETENT_DCCALRESULTS__DONE__READ(
	    CMSDK_MDM->TIA_RETENT_DCCALRESULTS)) {
#endif
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

#ifdef __RIF_TRNG_CONF_MACRO__
    // adjust TIA and PGA gain for calibration
    uint16_t max_entry = RIF_RXGAIN9__ENTRY28__READ(CMSDK_RIF->RXGAIN9);
#define CAL_TIA_PGA_GAIN	0x45
    max_entry = (max_entry & ~TIA_PGA_GAIN_MASK) | CAL_TIA_PGA_GAIN;
    RIF_RXGAIN9__ENTRY28__MODIFY(CMSDK_RIF->RXGAIN9, max_entry);
    RIF_RGTHW__MAX_RGT_INDEX__MODIFY(CMSDK_RIF->RGTHW, 56);
#else
    RIF_RX0__LNA_PROTECT_OVR__MODIFY(CMSDK_RIF->RX0, 3);
#endif

    atm_timer_lpc_delay(3);

#ifdef __RIF_TRNG_CONF_MACRO__
    MDM_TIA_DCCAL__AVG_CNT_EXP__MODIFY(CMSDK_MDM->TIA_DCCAL, 7);
    MDM_DCCAL_CTRL__MODE__MODIFY(CMSDK_MDM->DCCAL_CTRL, 0);
    MDM_DCCAL_CTRL__BYP__CLR(CMSDK_MDM->DCCAL_CTRL);
#endif
    MDM_DCCAL_CTRL__START__CLR(CMSDK_MDM->DCCAL_CTRL);
    MDM_DCCAL_CTRL__START__SET(CMSDK_MDM->DCCAL_CTRL);
    return false;
}

/**
 * @brief complete dc calibration
 */
__INLINE void trng_internal_dccal_complete(void)
{
    MDM_DCCAL_CTRL__START__CLR(CMSDK_MDM->DCCAL_CTRL);
#ifdef __RIF_TRNG_CONF_MACRO__
    MDM_DCCAL_CTRL__BYP__SET(CMSDK_MDM->DCCAL_CTRL);
    MDM_DCCAL_CTRL__MODE__MODIFY(CMSDK_MDM->DCCAL_CTRL, 3);

    uint32_t results = CMSDK_MDM->TIA_RETENT_DCCALRESULTS;
    MDM_DCCAL2__BB1I_DCOC_TRNG__MODIFY(CMSDK_MDM->DCCAL2,
	MDM_TIA_RETENT_DCCALRESULTS__I_OFF__READ(results));
    MDM_DCCAL2__BB1Q_DCOC_TRNG__MODIFY(CMSDK_MDM->DCCAL2,
	MDM_TIA_RETENT_DCCALRESULTS__Q_OFF__READ(results));
#endif
    WRPR_CTRL_SET(CMSDK_MDM, WRPR_CTRL__CLK_DISABLE);

#ifdef __RIF_TRNG_CONF_MACRO__
    // restore reset value for override register
    CMSDK_RIF->MODE_CNTL = RIF_MODE_CNTL__RESET_VALUE;

    // restore TIA and PGA gain
    uint16_t max_entry = RIF_RXGAIN9__ENTRY28__READ(CMSDK_RIF->RXGAIN9);
#define DFLT_TIA_PGA_GAIN	0x38
    max_entry = (max_entry & ~TIA_PGA_GAIN_MASK) | DFLT_TIA_PGA_GAIN;
    RIF_RXGAIN9__ENTRY28__MODIFY(CMSDK_RIF->RXGAIN9, max_entry);
#else
    uint32_t mode_cntl = CMSDK_RIF->MODE_CNTL;
    RIF_MODE_CNTL__RX_EN__CLR(mode_cntl);
    RIF_MODE_CNTL__RX_EN_OVR__CLR(mode_cntl);
    RIF_MODE_CNTL__RXGAIN_OVR__CLR(mode_cntl);
    RIF_MODE_CNTL__RXGAIN__MODIFY(mode_cntl,
	45 + RIF_LNA__STEP1__READ(CMSDK_RIF->LNA));
    CMSDK_RIF->MODE_CNTL = mode_cntl;
    RIF_RX0__LNA_PROTECT_OVR__MODIFY(CMSDK_RIF->RX0, 0);
#endif
    WRPR_CTRL_SET(CMSDK_RIF, WRPR_CTRL__CLK_DISABLE);
}
#endif // __MDM_DCCAL_CTRL_MACRO__

#ifdef __RIF_TRNG_CONF_MACRO__
/**
 * @brief Check whether TRNG needs to be triggered
 */
__INLINE bool trng_internal_go_pulse_needed(void)
{
    return (TRNG_CONTROL__LAUNCH_ON_RADIO_UP__READ(CMSDK_TRNG->CONTROL) &&
	!CMSDK_TRNG->STATUS &&
	ATLC_LC_LP_ST5__RADIO_EN__READ(CMSDK_ATLC_NONSECURE->LC_LP_ST5));
}
#endif

/**
 * @brief Set radio warmup cnt based on whether radio is already on
 */
__INLINE void trng_internal_set_radio_warmup_cnt(bool radio_already_on)
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
__INLINE void trng_internal_config(void)
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
__INLINE void trng_internal_force_go_pulse(void)
{
    TRNG_CONTROL__GO__CLR(CMSDK_TRNG->CONTROL);
    TRNG_CONTROL__GO__SET(CMSDK_TRNG->CONTROL);
}

/// @} TRNG_INTERNAL
