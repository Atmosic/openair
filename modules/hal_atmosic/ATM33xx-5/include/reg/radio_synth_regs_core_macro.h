/*                                                                           */
/* File:       radio_synth_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic radio_synth_regs_core.rdl          */
/*                                                                           */
/* Blueprint:   3.7.5 (Wed Feb 1 23:58:40 PST 2012)                          */
/* Machine:    gull                                                          */
/* OS:         Linux 2.6.32-696.13.2.el6.x86_64                              */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/* Copyright (C) 2025 Atmosic Technologies.  All rights reserved             */
/*                                                                           */


#ifndef __REG_RADIO_SYNTH_REGS_CORE_H__
#define __REG_RADIO_SYNTH_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup RADIO_SYNTH_REGS_CORE radio_synth_regs_core
 * @ingroup AT_REG
 * @brief radio_synth_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::radio_synth_synth_ctrl_0 */
/**
 * @defgroup radio_synth_regs_core_synth_ctrl_0 synth_ctrl_0
 * @brief Synth over-rides and analog adjustments definitions.
 * @{
 */
#ifndef __RADIO_SYNTH_SYNTH_CTRL_0_MACRO__
#define __RADIO_SYNTH_SYNTH_CTRL_0_MACRO__

/* macros for field disableSynthAnalog */
/**
 * @defgroup radio_synth_regs_core_disableSynthAnalog_field disableSynthAnalog_field
 * @brief macros for field disableSynthAnalog
 * @details disables the analog part of the Synthesizer
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__SHIFT                   0
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__WIDTH                   1
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__MASK          0x00000001U
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESYNTHANALOG__RESET_VALUE   0x00000000U
/** @} */

/* macros for field disableVco */
/**
 * @defgroup radio_synth_regs_core_disableVco_field disableVco_field
 * @brief macros for field disableVco
 * @details disables the VCO
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__SHIFT                           1
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__WIDTH                           1
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__MASK                  0x00000002U
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLEVCO__RESET_VALUE           0x00000000U
/** @} */

/* macros for field disableCp */
/**
 * @defgroup radio_synth_regs_core_disableCp_field disableCp_field
 * @brief macros for field disableCp
 * @details disables the Charge Pump
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__SHIFT                            2
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__WIDTH                            1
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__MASK                   0x00000004U
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLECP__RESET_VALUE            0x00000000U
/** @} */

/* macros for field disableTxmodHF */
/**
 * @defgroup radio_synth_regs_core_disableTxmodHF_field disableTxmodHF_field
 * @brief macros for field disableTxmodHF
 * @details disables the High Frequency Tx Modulation
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__SHIFT                       3
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__WIDTH                       1
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__MASK              0x00000008U
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODHF__RESET_VALUE       0x00000000U
/** @} */

/* macros for field disableTxmodLF */
/**
 * @defgroup radio_synth_regs_core_disableTxmodLF_field disableTxmodLF_field
 * @brief macros for field disableTxmodLF
 * @details disables the Low Frequency Tx Modulation
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__SHIFT                       4
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__WIDTH                       1
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__MASK              0x00000010U
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLETXMODLF__RESET_VALUE       0x00000000U
/** @} */

/* macros for field disableSDM */
/**
 * @defgroup radio_synth_regs_core_disableSDM_field disableSDM_field
 * @brief macros for field disableSDM
 * @details disables the Sigma-Delta Modulator
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__SHIFT                           5
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__WIDTH                           1
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__MASK                  0x00000020U
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define RADIO_SYNTH_SYNTH_CTRL_0__DISABLESDM__RESET_VALUE           0x00000000U
/** @} */

/* macros for field chanovr */
/**
 * @defgroup radio_synth_regs_core_chanovr_field chanovr_field
 * @brief macros for field chanovr
 * @details Enables channel override
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__SHIFT                              6
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__WIDTH                              1
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__MASK                     0x00000040U
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANOVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field chanint_8MHz */
/**
 * @defgroup radio_synth_regs_core_chanint_8MHz_field chanint_8MHz_field
 * @brief macros for field chanint_8MHz
 * @details Channel override integer part, for 8 MHz reference
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__SHIFT                         7
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__WIDTH                         9
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__MASK                0x0000ff80U
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff80U) >> 7)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x0000ff80U)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff80U) | (((uint32_t)(src) <<\
                    7) & 0x0000ff80U)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x0000ff80U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANINT_8MHZ__RESET_VALUE         0x00000096U
/** @} */

/* macros for field chanfrac_8MHz */
/**
 * @defgroup radio_synth_regs_core_chanfrac_8MHz_field chanfrac_8MHz_field
 * @brief macros for field chanfrac_8MHz
 * @details Channel override fractional part, for 8 MHz reference
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__SHIFT                       16
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__WIDTH                       15
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__MASK               0x7fff0000U
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7fff0000U) >> 16)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x7fff0000U)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fff0000U) | (((uint32_t)(src) <<\
                    16) & 0x7fff0000U)
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x7fff0000U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__CHANFRAC_8MHZ__RESET_VALUE        0x00000000U
/** @} */

/* macros for field alwaysShortR */
/**
 * @defgroup radio_synth_regs_core_alwaysShortR_field alwaysShortR_field
 * @brief macros for field alwaysShortR
 * @details always short large resistors
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__SHIFT                        31
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__WIDTH                         1
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__MASK                0x80000000U
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define RADIO_SYNTH_SYNTH_CTRL_0__ALWAYSSHORTR__RESET_VALUE         0x00000000U
/** @} */
#define RADIO_SYNTH_SYNTH_CTRL_0__TYPE                                 uint32_t
#define RADIO_SYNTH_SYNTH_CTRL_0__READ                              0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_0__WRITE                             0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_0__PRESERVED                         0x00000000U
#define RADIO_SYNTH_SYNTH_CTRL_0__RESET_VALUE                       0x00004b00U

#endif /* __RADIO_SYNTH_SYNTH_CTRL_0_MACRO__ */

/** @} end of synth_ctrl_0 */

/* macros for BlueprintGlobalNameSpace::radio_synth_synth_ctrl_1 */
/**
 * @defgroup radio_synth_regs_core_synth_ctrl_1 synth_ctrl_1
 * @brief Synth monitor and override modes definitions.
 * @{
 */
#ifndef __RADIO_SYNTH_SYNTH_CTRL_1_MACRO__
#define __RADIO_SYNTH_SYNTH_CTRL_1_MACRO__

/* macros for field atbsel */
/**
 * @defgroup radio_synth_regs_core_atbsel_field atbsel_field
 * @brief macros for field atbsel
 * @details analog test bus select. 0->Disconnect. 1->Control voltage. 2->VCO current source gate voltage, set by AGC. 3->VCO inductor center tap. 4->VCO core top (PMOS sources). 5->vdd_vco. 6->mod varactor gate bias. 7->mod RDAC top IR voltage. 8->mod voltage. 9-15->gnd
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__SHIFT                               0
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__WIDTH                               4
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__MASK                      0x0000000fU
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define RADIO_SYNTH_SYNTH_CTRL_1__ATBSEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field monitorVc */
/**
 * @defgroup radio_synth_regs_core_monitorVc_field monitorVc_field
 * @brief macros for field monitorVc
 * @details modify the FSM to monitor the control voltage
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__SHIFT                            4
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__WIDTH                            1
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__MASK                   0x00000010U
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONITORVC__RESET_VALUE            0x00000000U
/** @} */

/* macros for field monAlarmCountMax */
/**
 * @defgroup radio_synth_regs_core_monAlarmCountMax_field monAlarmCountMax_field
 * @brief macros for field monAlarmCountMax
 * @details in FSM monitor Vc mode, max number of alarm events before it takes action
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__SHIFT                     5
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__WIDTH                     2
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__MASK            0x00000060U
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000060U) >> 5)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000060U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__MONALARMCOUNTMAX__RESET_VALUE     0x00000002U
/** @} */

/* macros for field monStateLength_SteadyState_x4u */
/**
 * @defgroup radio_synth_regs_core_monStateLength_SteadyState_x4u_field monStateLength_SteadyState_x4u_field
 * @brief macros for field monStateLength_SteadyState_x4u
 * @details in FSM monitor Vc mode, time interval between successive Vc checks
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__SHIFT       7
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__WIDTH       3
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__MASK \
                    0x00000380U
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__MONSTATELENGTH_STEADYSTATE_X4U__RESET_VALUE \
                    0x00000004U
/** @} */

/* macros for field monVcrefHi */
/**
 * @defgroup radio_synth_regs_core_monVcrefHi_field monVcrefHi_field
 * @brief macros for field monVcrefHi
 * @details in FSM monitor Vc mode, adjusts the high threshold of the control voltage. 0 is the lowest threshold
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__SHIFT                          10
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__WIDTH                           2
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__MASK                  0x00000c00U
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFHI__RESET_VALUE           0x00000002U
/** @} */

/* macros for field monVcrefLo */
/**
 * @defgroup radio_synth_regs_core_monVcrefLo_field monVcrefLo_field
 * @brief macros for field monVcrefLo
 * @details in FSM monitor Vc mode, adjusts the low threshold of the control voltage. 0 is the lowest threshold. 2 is the voltage in the inductor center tap.
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__SHIFT                          12
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__WIDTH                           2
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__MASK                  0x00003000U
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__MONVCREFLO__RESET_VALUE           0x00000002U
/** @} */

/* macros for field overrideFsm */
/**
 * @defgroup radio_synth_regs_core_overrideFsm_field overrideFsm_field
 * @brief macros for field overrideFsm
 * @details override the FSM
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__SHIFT                         14
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__WIDTH                          1
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__MASK                 0x00004000U
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define RADIO_SYNTH_SYNTH_CTRL_1__OVERRIDEFSM__RESET_VALUE          0x00000000U
/** @} */

/* macros for field vcoCaps_ov */
/**
 * @defgroup radio_synth_regs_core_vcoCaps_ov_field vcoCaps_ov_field
 * @brief macros for field vcoCaps_ov
 * @details in override mode, the VCO capacitor setting
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__SHIFT                          15
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__WIDTH                           7
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__MASK                  0x003f8000U
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f8000U) >> 15)
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x003f8000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f8000U) | (((uint32_t)(src) <<\
                    15) & 0x003f8000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x003f8000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__VCOCAPS_OV__RESET_VALUE           0x00000040U
/** @} */

/* macros for field pinVc_ov */
/**
 * @defgroup radio_synth_regs_core_pinVc_ov_field pinVc_ov_field
 * @brief macros for field pinVc_ov
 * @details in override mode, pinVc
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__SHIFT                            22
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__WIDTH                             1
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__MASK                    0x00400000U
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define RADIO_SYNTH_SYNTH_CTRL_1__PINVC_OV__RESET_VALUE             0x00000000U
/** @} */

/* macros for field shortR_ov */
/**
 * @defgroup radio_synth_regs_core_shortR_ov_field shortR_ov_field
 * @brief macros for field shortR_ov
 * @details in override mode, short the large resistors
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__SHIFT                           23
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__WIDTH                            1
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__MASK                   0x00800000U
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define RADIO_SYNTH_SYNTH_CTRL_1__SHORTR_OV__RESET_VALUE            0x00000000U
/** @} */

/* macros for field divRst_ov */
/**
 * @defgroup radio_synth_regs_core_divRst_ov_field divRst_ov_field
 * @brief macros for field divRst_ov
 * @details in override mode, divider Reset
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__SHIFT                           24
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__WIDTH                            1
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__MASK                   0x01000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVRST_OV__RESET_VALUE            0x00000000U
/** @} */

/* macros for field pfdRst_ov */
/**
 * @defgroup radio_synth_regs_core_pfdRst_ov_field pfdRst_ov_field
 * @brief macros for field pfdRst_ov
 * @details in override mode, reset pfd
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__SHIFT                           25
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__WIDTH                            1
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__MASK                   0x02000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define RADIO_SYNTH_SYNTH_CTRL_1__PFDRST_OV__RESET_VALUE            0x00000000U
/** @} */

/* macros for field enSd_ov */
/**
 * @defgroup radio_synth_regs_core_enSd_ov_field enSd_ov_field
 * @brief macros for field enSd_ov
 * @details in override mode, enable Sigma-Delta Modulator
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__SHIFT                             26
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__WIDTH                              1
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__MASK                     0x04000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define RADIO_SYNTH_SYNTH_CTRL_1__ENSD_OV__RESET_VALUE              0x00000000U
/** @} */

/* macros for field divEnForce */
/**
 * @defgroup radio_synth_regs_core_divEnForce_field divEnForce_field
 * @brief macros for field divEnForce
 * @details Forces the divider to be always enabled
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__SHIFT                          27
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__WIDTH                           1
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__MASK                  0x08000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define RADIO_SYNTH_SYNTH_CTRL_1__DIVENFORCE__RESET_VALUE           0x00000000U
/** @} */

/* macros for field synthonForce */
/**
 * @defgroup radio_synth_regs_core_synthonForce_field synthonForce_field
 * @brief macros for field synthonForce
 * @details Forces synthon high. Used for testing
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__SHIFT                        28
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__WIDTH                         1
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__MASK                0x10000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define RADIO_SYNTH_SYNTH_CTRL_1__SYNTHONFORCE__RESET_VALUE         0x00000000U
/** @} */

/* macros for field openLoopSS */
/**
 * @defgroup radio_synth_regs_core_openLoopSS_field openLoopSS_field
 * @brief macros for field openLoopSS
 * @details open loop in steady state after locking during TX, primarily intended for testing HF modulation path
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__SHIFT                          29
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__WIDTH                           1
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__MASK                  0x20000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define RADIO_SYNTH_SYNTH_CTRL_1__OPENLOOPSS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field spareExt */
/**
 * @defgroup radio_synth_regs_core_spareExt_field spareExt_field
 * @brief macros for field spareExt
 * @details synth local register internal spare bits taken out as pins to synthDigital
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__SHIFT                            30
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__WIDTH                             2
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__MASK                    0xc0000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_1__SPAREEXT__RESET_VALUE             0x00000000U
/** @} */
#define RADIO_SYNTH_SYNTH_CTRL_1__TYPE                                 uint32_t
#define RADIO_SYNTH_SYNTH_CTRL_1__READ                              0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_1__WRITE                             0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_1__PRESERVED                         0x00000000U
#define RADIO_SYNTH_SYNTH_CTRL_1__RESET_VALUE                       0x00202a40U

#endif /* __RADIO_SYNTH_SYNTH_CTRL_1_MACRO__ */

/** @} end of synth_ctrl_1 */

/* macros for BlueprintGlobalNameSpace::radio_synth_synth_ctrl_2 */
/**
 * @defgroup radio_synth_regs_core_synth_ctrl_2 synth_ctrl_2
 * @brief Synth txmod data override, RX LOGen, PA and PA LDO enable controls and overrides, TX cal options definitions.
 * @{
 */
#ifndef __RADIO_SYNTH_SYNTH_CTRL_2_MACRO__
#define __RADIO_SYNTH_SYNTH_CTRL_2_MACRO__

/* macros for field txmodDataOvr */
/**
 * @defgroup radio_synth_regs_core_txmodDataOvr_field txmodDataOvr_field
 * @brief macros for field txmodDataOvr
 * @details set to override the txmodData used in the HF modulation path (VCO)
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__SHIFT                         0
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__WIDTH                         1
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__MASK                0x00000001U
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATAOVR__RESET_VALUE         0x00000000U
/** @} */

/* macros for field txmodData */
/**
 * @defgroup radio_synth_regs_core_txmodData_field txmodData_field
 * @brief macros for field txmodData
 * @details txmodData static bits, effective in the HF modulatin path when txmodDataOvr=1
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__SHIFT                            1
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__WIDTH                            7
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__MASK                   0x000000feU
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000feU) >> 1)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000000feU)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000feU) | (((uint32_t)(src) <<\
                    1) & 0x000000feU)
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000000feU)))
#define RADIO_SYNTH_SYNTH_CTRL_2__TXMODDATA__RESET_VALUE            0x00000020U
/** @} */

/* macros for field lockTestEn */
/**
 * @defgroup radio_synth_regs_core_lockTestEn_field lockTestEn_field
 * @brief macros for field lockTestEn
 * @details enables the lock detector
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__SHIFT                           8
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__WIDTH                           1
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__MASK                  0x00000100U
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define RADIO_SYNTH_SYNTH_CTRL_2__LOCKTESTEN__RESET_VALUE           0x00000000U
/** @} */

/* macros for field disableVcoModClk */
/**
 * @defgroup radio_synth_regs_core_disableVcoModClk_field disableVcoModClk_field
 * @brief macros for field disableVcoModClk
 * @details disables the VCO modulation clock, which retimes the data in the HF modulation path
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__SHIFT                     9
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__WIDTH                     1
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__MASK            0x00000200U
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLEVCOMODCLK__RESET_VALUE     0x00000000U
/** @} */

/* macros for field rxlo_combineIQ */
/**
 * @defgroup radio_synth_regs_core_rxlo_combineIQ_field rxlo_combineIQ_field
 * @brief macros for field rxlo_combineIQ
 * @details if =1, when in low-power dual-conversion mode, keeps both I & Q paths enabled in RXLO
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__SHIFT                      10
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__WIDTH                       1
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__MASK              0x00000400U
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_COMBINEIQ__RESET_VALUE       0x00000000U
/** @} */

/* macros for field overrideRxLOgen */
/**
 * @defgroup radio_synth_regs_core_overrideRxLOgen_field overrideRxLOgen_field
 * @brief macros for field overrideRxLOgen
 * @details if set, overrides the enable control bits of RXLOgen
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__SHIFT                     11
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__WIDTH                      1
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__MASK             0x00000800U
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define RADIO_SYNTH_SYNTH_CTRL_2__OVERRIDERXLOGEN__RESET_VALUE      0x00000000U
/** @} */

/* macros for field rxlo_enIdual_ov */
/**
 * @defgroup radio_synth_regs_core_rxlo_enIdual_ov_field rxlo_enIdual_ov_field
 * @brief macros for field rxlo_enIdual_ov
 * @details in RXLOgen override mode, the setting for enIdual
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__SHIFT                     12
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__WIDTH                      1
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__MASK             0x00001000U
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENIDUAL_OV__RESET_VALUE      0x00000000U
/** @} */

/* macros for field rxlo_enQdual_ov */
/**
 * @defgroup radio_synth_regs_core_rxlo_enQdual_ov_field rxlo_enQdual_ov_field
 * @brief macros for field rxlo_enQdual_ov
 * @details in RXLOgen override mode, the setting for enQdual
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__SHIFT                     13
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__WIDTH                      1
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__MASK             0x00002000U
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENQDUAL_OV__RESET_VALUE      0x00000000U
/** @} */

/* macros for field rxlo_ensinglelp_ov */
/**
 * @defgroup radio_synth_regs_core_rxlo_ensinglelp_ov_field rxlo_ensinglelp_ov_field
 * @brief macros for field rxlo_ensinglelp_ov
 * @details in RXLOgen override mode, the setting for ensinglelp
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__SHIFT                  14
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__WIDTH                   1
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__MASK          0x00004000U
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLELP_OV__RESET_VALUE   0x00000000U
/** @} */

/* macros for field rxlo_ensingle_ov */
/**
 * @defgroup radio_synth_regs_core_rxlo_ensingle_ov_field rxlo_ensingle_ov_field
 * @brief macros for field rxlo_ensingle_ov
 * @details in RXLOgen override mode, the setting for ensingle
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__SHIFT                    15
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__WIDTH                     1
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__MASK            0x00008000U
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define RADIO_SYNTH_SYNTH_CTRL_2__RXLO_ENSINGLE_OV__RESET_VALUE     0x00000000U
/** @} */

/* macros for field disableRxLOBuf */
/**
 * @defgroup radio_synth_regs_core_disableRxLOBuf_field disableRxLOBuf_field
 * @brief macros for field disableRxLOBuf
 * @details Disables RX LO buffer
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__SHIFT                      16
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__WIDTH                       1
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__MASK              0x00010000U
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define RADIO_SYNTH_SYNTH_CTRL_2__DISABLERXLOBUF__RESET_VALUE       0x00000000U
/** @} */

/* macros for field pa_bypassDuty */
/**
 * @defgroup radio_synth_regs_core_pa_bypassDuty_field pa_bypassDuty_field
 * @brief macros for field pa_bypassDuty
 * @details if set, bypasses the duty cycle control in PA
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__SHIFT                       17
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__WIDTH                        1
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__MASK               0x00020000U
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define RADIO_SYNTH_SYNTH_CTRL_2__PA_BYPASSDUTY__RESET_VALUE        0x00000000U
/** @} */

/* macros for field enPAdriverOvrValue */
/**
 * @defgroup radio_synth_regs_core_enPAdriverOvrValue_field enPAdriverOvrValue_field
 * @brief macros for field enPAdriverOvrValue
 * @details Enable PA driver override value when enPAdriver_sel = 3
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__SHIFT                  18
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__WIDTH                   1
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__MASK          0x00040000U
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVEROVRVALUE__RESET_VALUE   0x00000000U
/** @} */

/* macros for field enPAdriver_sel */
/**
 * @defgroup radio_synth_regs_core_enPAdriver_sel_field enPAdriver_sel_field
 * @brief macros for field enPAdriver_sel
 * @details Select how PA driver is controlled, 0 - txon, 1 - synthon, 2 - paon, 3 - use enPAdriverOvrValue
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__SHIFT                      19
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__WIDTH                       2
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__MASK              0x00180000U
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPADRIVER_SEL__RESET_VALUE       0x00000002U
/** @} */

/* macros for field enPAOvrValue */
/**
 * @defgroup radio_synth_regs_core_enPAOvrValue_field enPAOvrValue_field
 * @brief macros for field enPAOvrValue
 * @details Enable PA output stage override value when enPA_sel = 3
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__SHIFT                        21
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__WIDTH                         1
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__MASK                0x00200000U
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPAOVRVALUE__RESET_VALUE         0x00000000U
/** @} */

/* macros for field enPA_sel */
/**
 * @defgroup radio_synth_regs_core_enPA_sel_field enPA_sel_field
 * @brief macros for field enPA_sel
 * @details Select how PA output stage is controlled, 0 - txon, 1 - synthon, 2 - paon, 3 - use enPAOvrValue
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__SHIFT                            22
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__WIDTH                             2
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__MASK                    0x00c00000U
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPA_SEL__RESET_VALUE             0x00000002U
/** @} */

/* macros for field enPAldoOvrValue */
/**
 * @defgroup radio_synth_regs_core_enPAldoOvrValue_field enPAldoOvrValue_field
 * @brief macros for field enPAldoOvrValue
 * @details Enable PA output stage LDO override value when enPAldo_sel = 3
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__SHIFT                     24
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__WIDTH                      1
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__MASK             0x01000000U
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDOOVRVALUE__RESET_VALUE      0x00000000U
/** @} */

/* macros for field enPAldo_sel */
/**
 * @defgroup radio_synth_regs_core_enPAldo_sel_field enPAldo_sel_field
 * @brief macros for field enPAldo_sel
 * @details Select how PA output stage LDO is controlled, 0 - txon, 1 - synthon, 2 - paon, 3 - use enPAldoValue
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__SHIFT                         25
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__WIDTH                          2
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__MASK                 0x06000000U
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x06000000U) >> 25)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x06000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x06000000U) | (((uint32_t)(src) <<\
                    25) & 0x06000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x06000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__ENPALDO_SEL__RESET_VALUE          0x00000002U
/** @} */

/* macros for field vcoTuneMargin_x16M */
/**
 * @defgroup radio_synth_regs_core_vcoTuneMargin_x16M_field vcoTuneMargin_x16M_field
 * @brief macros for field vcoTuneMargin_x16M
 * @details Set target frequency for coarse bank search to (2480 + 16x) for TX and (2835 + 16x) for RX, where x is the value of this register
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__SHIFT                  27
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__WIDTH                   3
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__MASK          0x38000000U
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x38000000U) >> 27)
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x38000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x38000000U) | (((uint32_t)(src) <<\
                    27) & 0x38000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x38000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__VCOTUNEMARGIN_X16M__RESET_VALUE   0x00000004U
/** @} */

/* macros for field dontRoundUp_modGainCal */
/**
 * @defgroup radio_synth_regs_core_dontRoundUp_modGainCal_field dontRoundUp_modGainCal_field
 * @brief macros for field dontRoundUp_modGainCal
 * @details if set, state machine will not round-up when making final calculation of modGain_cal_result
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__SHIFT              30
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__WIDTH               1
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__MASK      0x40000000U
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_MODGAINCAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field dontRoundUp_vcoCapsCal */
/**
 * @defgroup radio_synth_regs_core_dontRoundUp_vcoCapsCal_field dontRoundUp_vcoCapsCal_field
 * @brief macros for field dontRoundUp_vcoCapsCal
 * @details if set, state machine will not round-up when making final calculation of Bx and Cx values during VCO cap calibration
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__SHIFT              31
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__WIDTH               1
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__MASK      0x80000000U
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define RADIO_SYNTH_SYNTH_CTRL_2__DONTROUNDUP_VCOCAPSCAL__RESET_VALUE \
                    0x00000001U
/** @} */
#define RADIO_SYNTH_SYNTH_CTRL_2__TYPE                                 uint32_t
#define RADIO_SYNTH_SYNTH_CTRL_2__READ                              0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_2__WRITE                             0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_2__PRESERVED                         0x00000000U
#define RADIO_SYNTH_SYNTH_CTRL_2__RESET_VALUE                       0xa4900040U

#endif /* __RADIO_SYNTH_SYNTH_CTRL_2_MACRO__ */

/** @} end of synth_ctrl_2 */

/* macros for BlueprintGlobalNameSpace::radio_synth_synth_ctrl_3 */
/**
 * @defgroup radio_synth_regs_core_synth_ctrl_3 synth_ctrl_3
 * @brief Synth txmod static bits definitions.
 * @{
 */
#ifndef __RADIO_SYNTH_SYNTH_CTRL_3_MACRO__
#define __RADIO_SYNTH_SYNTH_CTRL_3_MACRO__

/* macros for field modVarSize_cal */
/**
 * @defgroup radio_synth_regs_core_modVarSize_cal_field modVarSize_cal_field
 * @brief macros for field modVarSize_cal
 * @details modulation varactor size to be used during modGain calibration
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__SHIFT                       0
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__WIDTH                       4
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__MASK              0x0000000fU
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARSIZE_CAL__RESET_VALUE       0x0000000fU
/** @} */

/* macros for field modVarBias_1M */
/**
 * @defgroup radio_synth_regs_core_modVarBias_1M_field modVarBias_1M_field
 * @brief macros for field modVarBias_1M
 * @details modulation varactor gate bias voltage for 1Mbps rate
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__SHIFT                        4
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__WIDTH                        4
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__MASK               0x000000f0U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_1M__RESET_VALUE        0x00000008U
/** @} */

/* macros for field modBucketSize_1M */
/**
 * @defgroup radio_synth_regs_core_modBucketSize_1M_field modBucketSize_1M_field
 * @brief macros for field modBucketSize_1M
 * @details frequency bin size in 4MHz steps for modgain adjustment for 1Mbps rate
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__SHIFT                     8
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__WIDTH                     5
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__MASK            0x00001f00U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00001f00U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f00U) | (((uint32_t)(src) <<\
                    8) & 0x00001f00U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00001f00U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_1M__RESET_VALUE     0x00000007U
/** @} */

/* macros for field modDelayHF_1M */
/**
 * @defgroup radio_synth_regs_core_modDelayHF_1M_field modDelayHF_1M_field
 * @brief macros for field modDelayHF_1M
 * @details if set, the data to the HF modulation path is delayed, otherwise the data to the LF modulation path is delayed
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__SHIFT                       13
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__WIDTH                        1
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__MASK               0x00002000U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_1M__RESET_VALUE        0x00000000U
/** @} */

/* macros for field modRelPathDelay_1M */
/**
 * @defgroup radio_synth_regs_core_modRelPathDelay_1M_field modRelPathDelay_1M_field
 * @brief macros for field modRelPathDelay_1M
 * @details relative delay in cycles of the 16M clock, in the path determined by modDelayHF_1M
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__SHIFT                  14
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__WIDTH                   3
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__MASK          0x0001c000U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_1M__RESET_VALUE   0x00000000U
/** @} */

/* macros for field modVarBias_2M */
/**
 * @defgroup radio_synth_regs_core_modVarBias_2M_field modVarBias_2M_field
 * @brief macros for field modVarBias_2M
 * @details modulation varactor gate bias voltage for 2Mbps rate
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__SHIFT                       17
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__WIDTH                        4
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__MASK               0x001e0000U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001e0000U) >> 17)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x001e0000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001e0000U) | (((uint32_t)(src) <<\
                    17) & 0x001e0000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x001e0000U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODVARBIAS_2M__RESET_VALUE        0x00000008U
/** @} */

/* macros for field modBucketSize_2M */
/**
 * @defgroup radio_synth_regs_core_modBucketSize_2M_field modBucketSize_2M_field
 * @brief macros for field modBucketSize_2M
 * @details frequency bin size in 4MHz steps for modgain adjustment for 2Mbps rate
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__SHIFT                    21
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__WIDTH                     5
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__MASK            0x03e00000U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03e00000U) >> 21)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x03e00000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03e00000U) | (((uint32_t)(src) <<\
                    21) & 0x03e00000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x03e00000U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODBUCKETSIZE_2M__RESET_VALUE     0x00000007U
/** @} */

/* macros for field modDelayHF_2M */
/**
 * @defgroup radio_synth_regs_core_modDelayHF_2M_field modDelayHF_2M_field
 * @brief macros for field modDelayHF_2M
 * @details if set, the data to the HF modulation path is delayed, otherwise the data to the LF modulation path is delayed
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__SHIFT                       26
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__WIDTH                        1
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__MASK               0x04000000U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODDELAYHF_2M__RESET_VALUE        0x00000000U
/** @} */

/* macros for field modRelPathDelay_2M */
/**
 * @defgroup radio_synth_regs_core_modRelPathDelay_2M_field modRelPathDelay_2M_field
 * @brief macros for field modRelPathDelay_2M
 * @details relative delay in cycles of the 16M clock, in the path determined by modDelayHF_2M
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__SHIFT                  27
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__WIDTH                   3
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__MASK          0x38000000U
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x38000000U) >> 27)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x38000000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x38000000U) | (((uint32_t)(src) <<\
                    27) & 0x38000000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x38000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__MODRELPATHDELAY_2M__RESET_VALUE   0x00000000U
/** @} */

/* macros for field txRate_hadm */
/**
 * @defgroup radio_synth_regs_core_txRate_hadm_field txRate_hadm_field
 * @brief macros for field txRate_hadm
 * @details value of txRate when in HADM mode; default is 2M rate
 * @{
 */
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__SHIFT                         30
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__WIDTH                          2
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__MASK                 0xc0000000U
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define RADIO_SYNTH_SYNTH_CTRL_3__TXRATE_HADM__RESET_VALUE          0x00000001U
/** @} */
#define RADIO_SYNTH_SYNTH_CTRL_3__TYPE                                 uint32_t
#define RADIO_SYNTH_SYNTH_CTRL_3__READ                              0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_3__WRITE                             0xffffffffU
#define RADIO_SYNTH_SYNTH_CTRL_3__PRESERVED                         0x00000000U
#define RADIO_SYNTH_SYNTH_CTRL_3__RESET_VALUE                       0x40f0078fU

#endif /* __RADIO_SYNTH_SYNTH_CTRL_3_MACRO__ */

/** @} end of synth_ctrl_3 */

/* macros for BlueprintGlobalNameSpace::radio_synth_synth_readout */
/**
 * @defgroup radio_synth_regs_core_synth_readout synth_readout
 * @brief Synth read-out bits definitions.
 * @{
 */
#ifndef __RADIO_SYNTH_SYNTH_READOUT_MACRO__
#define __RADIO_SYNTH_SYNTH_READOUT_MACRO__

/* macros for field fsm_state */
/**
 * @defgroup radio_synth_regs_core_fsm_state_field fsm_state_field
 * @brief macros for field fsm_state
 * @details FSM output, the state
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_STATE__SHIFT                           0
#define RADIO_SYNTH_SYNTH_READOUT__FSM_STATE__WIDTH                           5
#define RADIO_SYNTH_SYNTH_READOUT__FSM_STATE__MASK                  0x0000001fU
#define RADIO_SYNTH_SYNTH_READOUT__FSM_STATE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_STATE__RESET_VALUE           0x00000000U
/** @} */

/* macros for field fsm_vcoCaps */
/**
 * @defgroup radio_synth_regs_core_fsm_vcoCaps_field fsm_vcoCaps_field
 * @brief macros for field fsm_vcoCaps
 * @details FSM output, the VCO cap setting
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VCOCAPS__SHIFT                         5
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VCOCAPS__WIDTH                         7
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VCOCAPS__MASK                0x00000fe0U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VCOCAPS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fe0U) >> 5)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VCOCAPS__RESET_VALUE         0x00000000U
/** @} */

/* macros for field fsm_divCapSearch */
/**
 * @defgroup radio_synth_regs_core_fsm_divCapSearch_field fsm_divCapSearch_field
 * @brief macros for field fsm_divCapSearch
 * @details FSM output, the divCapSearch signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVCAPSEARCH__SHIFT                   12
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVCAPSEARCH__WIDTH                    1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVCAPSEARCH__MASK           0x00001000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVCAPSEARCH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVCAPSEARCH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVCAPSEARCH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVCAPSEARCH__RESET_VALUE    0x00000000U
/** @} */

/* macros for field fsm_enSynthAnalog */
/**
 * @defgroup radio_synth_regs_core_fsm_enSynthAnalog_field fsm_enSynthAnalog_field
 * @brief macros for field fsm_enSynthAnalog
 * @details FSM output, enSynthAnalog signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSYNTHANALOG__SHIFT                  13
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSYNTHANALOG__WIDTH                   1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSYNTHANALOG__MASK          0x00002000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSYNTHANALOG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSYNTHANALOG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSYNTHANALOG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSYNTHANALOG__RESET_VALUE   0x00000000U
/** @} */

/* macros for field fsm_pinVc */
/**
 * @defgroup radio_synth_regs_core_fsm_pinVc_field fsm_pinVc_field
 * @brief macros for field fsm_pinVc
 * @details FSM output, pinVc signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PINVC__SHIFT                          14
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PINVC__WIDTH                           1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PINVC__MASK                  0x00004000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PINVC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PINVC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PINVC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PINVC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field fsm_shortR */
/**
 * @defgroup radio_synth_regs_core_fsm_shortR_field fsm_shortR_field
 * @brief macros for field fsm_shortR
 * @details FSM output, shortR signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_SHORTR__SHIFT                         15
#define RADIO_SYNTH_SYNTH_READOUT__FSM_SHORTR__WIDTH                          1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_SHORTR__MASK                 0x00008000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_SHORTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_SHORTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_SHORTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_SHORTR__RESET_VALUE          0x00000000U
/** @} */

/* macros for field fsm_divRst */
/**
 * @defgroup radio_synth_regs_core_fsm_divRst_field fsm_divRst_field
 * @brief macros for field fsm_divRst
 * @details FSM output, divRst signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVRST__SHIFT                         16
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVRST__WIDTH                          1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVRST__MASK                 0x00010000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVRST__RESET_VALUE          0x00000000U
/** @} */

/* macros for field fsm_divEnToggle */
/**
 * @defgroup radio_synth_regs_core_fsm_divEnToggle_field fsm_divEnToggle_field
 * @brief macros for field fsm_divEnToggle
 * @details FSM output, divEnToggle signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVENTOGGLE__SHIFT                    17
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVENTOGGLE__WIDTH                     1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVENTOGGLE__MASK            0x00020000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVENTOGGLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVENTOGGLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVENTOGGLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_DIVENTOGGLE__RESET_VALUE     0x00000000U
/** @} */

/* macros for field fsm_pfdRst */
/**
 * @defgroup radio_synth_regs_core_fsm_pfdRst_field fsm_pfdRst_field
 * @brief macros for field fsm_pfdRst
 * @details FSM output, pfdRst signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PFDRST__SHIFT                         18
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PFDRST__WIDTH                          1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PFDRST__MASK                 0x00040000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PFDRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PFDRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PFDRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_PFDRST__RESET_VALUE          0x00000000U
/** @} */

/* macros for field fsm_enSd */
/**
 * @defgroup radio_synth_regs_core_fsm_enSd_field fsm_enSd_field
 * @brief macros for field fsm_enSd
 * @details FSM output, enSd signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSD__SHIFT                           19
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSD__WIDTH                            1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSD__MASK                   0x00080000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_ENSD__RESET_VALUE            0x00000000U
/** @} */

/* macros for field fsm_vc2hi_Sync */
/**
 * @defgroup radio_synth_regs_core_fsm_vc2hi_Sync_field fsm_vc2hi_Sync_field
 * @brief macros for field fsm_vc2hi_Sync
 * @details FSM output, vc2hi_Sync signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2HI_SYNC__SHIFT                     20
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2HI_SYNC__WIDTH                      1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2HI_SYNC__MASK             0x00100000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2HI_SYNC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2HI_SYNC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2HI_SYNC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2HI_SYNC__RESET_VALUE      0x00000000U
/** @} */

/* macros for field fsm_vc2lo_Sync */
/**
 * @defgroup radio_synth_regs_core_fsm_vc2lo_Sync_field fsm_vc2lo_Sync_field
 * @brief macros for field fsm_vc2lo_Sync
 * @details FSM output, vc2lo_Sync signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2LO_SYNC__SHIFT                     21
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2LO_SYNC__WIDTH                      1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2LO_SYNC__MASK             0x00200000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2LO_SYNC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2LO_SYNC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2LO_SYNC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_VC2LO_SYNC__RESET_VALUE      0x00000000U
/** @} */

/* macros for field fsm_nolock_Sync */
/**
 * @defgroup radio_synth_regs_core_fsm_nolock_Sync_field fsm_nolock_Sync_field
 * @brief macros for field fsm_nolock_Sync
 * @details FSM output, nolock_Sync signal
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__FSM_NOLOCK_SYNC__SHIFT                    22
#define RADIO_SYNTH_SYNTH_READOUT__FSM_NOLOCK_SYNC__WIDTH                     1
#define RADIO_SYNTH_SYNTH_READOUT__FSM_NOLOCK_SYNC__MASK            0x00400000U
#define RADIO_SYNTH_SYNTH_READOUT__FSM_NOLOCK_SYNC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_NOLOCK_SYNC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_NOLOCK_SYNC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define RADIO_SYNTH_SYNTH_READOUT__FSM_NOLOCK_SYNC__RESET_VALUE     0x00000000U
/** @} */

/* macros for field txmodGain */
/**
 * @defgroup radio_synth_regs_core_txmodGain_field txmodGain_field
 * @brief macros for field txmodGain
 * @details calculated modGain output based on rate and channel
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__TXMODGAIN__SHIFT                          23
#define RADIO_SYNTH_SYNTH_READOUT__TXMODGAIN__WIDTH                           5
#define RADIO_SYNTH_SYNTH_READOUT__TXMODGAIN__MASK                  0x0f800000U
#define RADIO_SYNTH_SYNTH_READOUT__TXMODGAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f800000U) >> 23)
#define RADIO_SYNTH_SYNTH_READOUT__TXMODGAIN__RESET_VALUE           0x00000000U
/** @} */

/* macros for field vcoCapsCoarse */
/**
 * @defgroup radio_synth_regs_core_vcoCapsCoarse_field vcoCapsCoarse_field
 * @brief macros for field vcoCapsCoarse
 * @details VCO coarse bank setting
 * @{
 */
#define RADIO_SYNTH_SYNTH_READOUT__VCOCAPSCOARSE__SHIFT                      28
#define RADIO_SYNTH_SYNTH_READOUT__VCOCAPSCOARSE__WIDTH                       3
#define RADIO_SYNTH_SYNTH_READOUT__VCOCAPSCOARSE__MASK              0x70000000U
#define RADIO_SYNTH_SYNTH_READOUT__VCOCAPSCOARSE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x70000000U) >> 28)
#define RADIO_SYNTH_SYNTH_READOUT__VCOCAPSCOARSE__RESET_VALUE       0x00000000U
/** @} */
#define RADIO_SYNTH_SYNTH_READOUT__TYPE                                uint32_t
#define RADIO_SYNTH_SYNTH_READOUT__READ                             0x7fffffffU
#define RADIO_SYNTH_SYNTH_READOUT__PRESERVED                        0x00000000U
#define RADIO_SYNTH_SYNTH_READOUT__RESET_VALUE                      0x00000000U

#endif /* __RADIO_SYNTH_SYNTH_READOUT_MACRO__ */

/** @} end of synth_readout */

/* macros for BlueprintGlobalNameSpace::radio_synth_core_id */
/**
 * @defgroup radio_synth_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __RADIO_SYNTH_CORE_ID_MACRO__
#define __RADIO_SYNTH_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup radio_synth_regs_core_id_field id_field
 * @brief macros for field id
 * @details SYNT in ASCII
 * @{
 */
#define RADIO_SYNTH_CORE_ID__ID__SHIFT                                        0
#define RADIO_SYNTH_CORE_ID__ID__WIDTH                                       32
#define RADIO_SYNTH_CORE_ID__ID__MASK                               0xffffffffU
#define RADIO_SYNTH_CORE_ID__ID__READ(src)      ((uint32_t)(src) & 0xffffffffU)
#define RADIO_SYNTH_CORE_ID__ID__RESET_VALUE                        0x53594e54U
/** @} */
#define RADIO_SYNTH_CORE_ID__TYPE                                      uint32_t
#define RADIO_SYNTH_CORE_ID__READ                                   0xffffffffU
#define RADIO_SYNTH_CORE_ID__PRESERVED                              0x00000000U
#define RADIO_SYNTH_CORE_ID__RESET_VALUE                            0x53594e54U

#endif /* __RADIO_SYNTH_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of RADIO_SYNTH_REGS_CORE */
#endif /* __REG_RADIO_SYNTH_REGS_CORE_H__ */
