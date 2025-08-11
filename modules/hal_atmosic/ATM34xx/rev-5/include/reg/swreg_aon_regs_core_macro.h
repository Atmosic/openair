/*                                                                           */
/* File:       swreg_aon_regs_core_macro.h                                   */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic swreg_aon_regs_core.rdl            */
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


#ifndef __REG_SWREG_AON_REGS_CORE_H__
#define __REG_SWREG_AON_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup SWREG_AON_REGS_CORE swreg_aon_regs_core
 * @ingroup AT_REG
 * @brief swreg_aon_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_aon0 */
/**
 * @defgroup swreg_aon_regs_core_aon0 aon0
 * @brief swreg aon regs For fields that refer to the FSMs the order is: 3: None 2: Main 1: Simple 0: Tiny For fields that refer to the sources the order is: 2: Battery 1: Store 0: Harvester For fields that refer to the destinations the order is: 4: Store 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD For fields that refer to the supplies the order is: 4: Store 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD definitions.
 * @{
 */
#ifndef __SWREG_AON_AON0_MACRO__
#define __SWREG_AON_AON0_MACRO__

/* macros for field clkFixedMain_SH */
/**
 * @defgroup swreg_aon_regs_core_clkFixedMain_SH_field clkFixedMain_SH_field
 * @brief macros for field clkFixedMain_SH
 * @details fixed time for the clock of the main FSM (shadowed in main)
 * @{
 */
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__SHIFT                                0
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__WIDTH                                4
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__MASK                       0x0000000fU
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define SWREG_AON_AON0__CLKFIXEDMAIN_SH__RESET_VALUE                0x00000003U
/** @} */

/* macros for field clkFixedSimple_SH */
/**
 * @defgroup swreg_aon_regs_core_clkFixedSimple_SH_field clkFixedSimple_SH_field
 * @brief macros for field clkFixedSimple_SH
 * @details fixed time for the clock of the simple FSM (shadowed in simple)
 * @{
 */
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__SHIFT                              4
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__WIDTH                              4
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__MASK                     0x000000f0U
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define SWREG_AON_AON0__CLKFIXEDSIMPLE_SH__RESET_VALUE              0x00000003U
/** @} */

/* macros for field clkFixedTiny_SH */
/**
 * @defgroup swreg_aon_regs_core_clkFixedTiny_SH_field clkFixedTiny_SH_field
 * @brief macros for field clkFixedTiny_SH
 * @details fixed time for the clock of the tiny FSM (shadowed in aon)
 * @{
 */
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__SHIFT                                8
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__WIDTH                                4
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__MASK                       0x00000f00U
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define SWREG_AON_AON0__CLKFIXEDTINY_SH__RESET_VALUE                0x00000003U
/** @} */

/* macros for field resetOnBBchangeMain_SH */
/**
 * @defgroup swreg_aon_regs_core_resetOnBBchangeMain_SH_field resetOnBBchangeMain_SH_field
 * @brief macros for field resetOnBBchangeMain_SH
 * @details controls the behavior on the change among BB, Buck and Boost modes. 1 resets internal parameters and 0 makes a bad prediction of the new state. In both cases resettling is needed. (shadowed in main)
 * @{
 */
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__SHIFT                        12
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__WIDTH                         1
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__MASK                0x00001000U
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define SWREG_AON_AON0__RESETONBBCHANGEMAIN_SH__RESET_VALUE         0x00000000U
/** @} */

/* macros for field resetOnBBchangeSimple_SH */
/**
 * @defgroup swreg_aon_regs_core_resetOnBBchangeSimple_SH_field resetOnBBchangeSimple_SH_field
 * @brief macros for field resetOnBBchangeSimple_SH
 * @details controls the behavior on the change among BB, Buck and Boost modes. 1 resets internal parameters and 0 makes a bad prediction of the new state. In both cases resettling is needed. (shadowed in simple)
 * @{
 */
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__SHIFT                      13
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__WIDTH                       1
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__MASK              0x00002000U
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define SWREG_AON_AON0__RESETONBBCHANGESIMPLE_SH__RESET_VALUE       0x00000001U
/** @} */

/* macros for field skipSample_SH */
/**
 * @defgroup swreg_aon_regs_core_skipSample_SH_field skipSample_SH_field
 * @brief macros for field skipSample_SH
 * @details skip the sample state after dump. A sample state allows more time for the request comparators to respond. (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON0__SKIPSAMPLE_SH__SHIFT                                 14
#define SWREG_AON_AON0__SKIPSAMPLE_SH__WIDTH                                  1
#define SWREG_AON_AON0__SKIPSAMPLE_SH__MASK                         0x00004000U
#define SWREG_AON_AON0__SKIPSAMPLE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define SWREG_AON_AON0__SKIPSAMPLE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define SWREG_AON_AON0__SKIPSAMPLE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define SWREG_AON_AON0__SKIPSAMPLE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define SWREG_AON_AON0__SKIPSAMPLE_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define SWREG_AON_AON0__SKIPSAMPLE_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define SWREG_AON_AON0__SKIPSAMPLE_SH__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field timeStepSettleTarget_SH */
/**
 * @defgroup swreg_aon_regs_core_timeStepSettleTarget_SH_field timeStepSettleTarget_SH_field
 * @brief macros for field timeStepSettleTarget_SH
 * @details step size used for the settling targets (0 is step of 1) (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__SHIFT                       15
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__WIDTH                        3
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__MASK               0x00038000U
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
#define SWREG_AON_AON0__TIMESTEPSETTLETARGET_SH__RESET_VALUE        0x00000001U
/** @} */

/* macros for field timeStepStepUp_SH */
/**
 * @defgroup swreg_aon_regs_core_timeStepStepUp_SH_field timeStepStepUp_SH_field
 * @brief macros for field timeStepStepUp_SH
 * @details step with which the timestep increases when the ZCD result is repeatedly negative (the supply discharges). 0 corresponds to step of 1 (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__SHIFT                             18
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__WIDTH                              3
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__MASK                     0x001c0000U
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
#define SWREG_AON_AON0__TIMESTEPSTEPUP_SH__RESET_VALUE              0x00000003U
/** @} */

/* macros for field timeStepStepDn_SH */
/**
 * @defgroup swreg_aon_regs_core_timeStepStepDn_SH_field timeStepStepDn_SH_field
 * @brief macros for field timeStepStepDn_SH
 * @details step with which the timestep decreases, or increases when ZCD result is repeatedly positive. 0 corresponds to step of 1 (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__SHIFT                             21
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__WIDTH                              3
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__MASK                     0x00e00000U
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00e00000U) >> 21)
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00e00000U)
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00e00000U) | (((uint32_t)(src) <<\
                    21) & 0x00e00000U)
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00e00000U)))
#define SWREG_AON_AON0__TIMESTEPSTEPDN_SH__RESET_VALUE              0x00000000U
/** @} */

/* macros for field timeAfterDump_SH */
/**
 * @defgroup swreg_aon_regs_core_timeAfterDump_SH_field timeAfterDump_SH_field
 * @brief macros for field timeAfterDump_SH
 * @details length of state after dump. The remaining inductor current is dissipated during this state (x4+3) (shadowed in simple and main and used directly in tiny)
 * @{
 */
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__SHIFT                              24
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__WIDTH                               4
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__MASK                      0x0f000000U
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define SWREG_AON_AON0__TIMEAFTERDUMP_SH__RESET_VALUE               0x00000001U
/** @} */

/* macros for field indCurrentHistoryLength_SH */
/**
 * @defgroup swreg_aon_regs_core_indCurrentHistoryLength_SH_field indCurrentHistoryLength_SH_field
 * @brief macros for field indCurrentHistoryLength_SH
 * @details length of inductor current history, max is 2 (n means acting after the inductor current sign is the same n+2 times) (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__SHIFT                    28
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__WIDTH                     2
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__MASK            0x30000000U
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define SWREG_AON_AON0__INDCURRENTHISTORYLENGTH_SH__RESET_VALUE     0x00000002U
/** @} */

/* macros for field enableHarv2SupFirst_SH */
/**
 * @defgroup swreg_aon_regs_core_enableHarv2SupFirst_SH_field enableHarv2SupFirst_SH_field
 * @brief macros for field enableHarv2SupFirst_SH
 * @details enables the use of the harvester as a source before the battery and the store. If set to zero but enableHarv2Sup=1 the harvest is used as a source if the battery and store are not available. must be set for mppt if enableHarv2Sup=1(shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__SHIFT                        30
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__WIDTH                         1
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__MASK                0x40000000U
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SWREG_AON_AON0__ENABLEHARV2SUPFIRST_SH__RESET_VALUE         0x00000001U
/** @} */

/* macros for field mpptFullSettling_SH */
/**
 * @defgroup swreg_aon_regs_core_mpptFullSettling_SH_field mpptFullSettling_SH_field
 * @brief macros for field mpptFullSettling_SH
 * @details wait for full dump time settling, before starting counting switching events for mppt. Normally this should not be necessary (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__SHIFT                           31
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__WIDTH                            1
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__MASK                   0x80000000U
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SWREG_AON_AON0__MPPTFULLSETTLING_SH__RESET_VALUE            0x00000000U
/** @} */
#define SWREG_AON_AON0__TYPE                                           uint32_t
#define SWREG_AON_AON0__READ                                        0xffffffffU
#define SWREG_AON_AON0__WRITE                                       0xffffffffU
#define SWREG_AON_AON0__PRESERVED                                   0x00000000U
#define SWREG_AON_AON0__RESET_VALUE                                 0x610ce333U

#endif /* __SWREG_AON_AON0_MACRO__ */

/** @} end of aon0 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_aon1 */
/**
 * @defgroup swreg_aon_regs_core_aon1 aon1
 * @brief swreg aon regs definitions.
 * @{
 */
#ifndef __SWREG_AON_AON1_MACRO__
#define __SWREG_AON_AON1_MACRO__

/* macros for field timeDumpTarget_dvdd_SH */
/**
 * @defgroup swreg_aon_regs_core_timeDumpTarget_dvdd_SH_field timeDumpTarget_dvdd_SH_field
 * @brief macros for field timeDumpTarget_dvdd_SH
 * @details target dump time for dvdd (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__SHIFT                         0
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__WIDTH                         7
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__MASK                0x0000007fU
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define SWREG_AON_AON1__TIMEDUMPTARGET_DVDD_SH__RESET_VALUE         0x00000028U
/** @} */

/* macros for field timeDumpTarget_vaux_SH */
/**
 * @defgroup swreg_aon_regs_core_timeDumpTarget_vaux_SH_field timeDumpTarget_vaux_SH_field
 * @brief macros for field timeDumpTarget_vaux_SH
 * @details target dump time for vaux (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__SHIFT                         7
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__WIDTH                         7
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__MASK                0x00003f80U
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define SWREG_AON_AON1__TIMEDUMPTARGET_VAUX_SH__RESET_VALUE         0x00000008U
/** @} */

/* macros for field timeDumpTarget_vddio_SH */
/**
 * @defgroup swreg_aon_regs_core_timeDumpTarget_vddio_SH_field timeDumpTarget_vddio_SH_field
 * @brief macros for field timeDumpTarget_vddio_SH
 * @details target dump time for vddio (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__SHIFT                       14
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__WIDTH                        7
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__MASK               0x001fc000U
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define SWREG_AON_AON1__TIMEDUMPTARGET_VDDIO_SH__RESET_VALUE        0x0000000cU
/** @} */

/* macros for field timeDumpTarget_avdd_SH */
/**
 * @defgroup swreg_aon_regs_core_timeDumpTarget_avdd_SH_field timeDumpTarget_avdd_SH_field
 * @brief macros for field timeDumpTarget_avdd_SH
 * @details target dump time for avdd (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__SHIFT                        21
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__WIDTH                         7
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__MASK                0x0fe00000U
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fe00000U) >> 21)
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x0fe00000U)
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fe00000U) | (((uint32_t)(src) <<\
                    21) & 0x0fe00000U)
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x0fe00000U)))
#define SWREG_AON_AON1__TIMEDUMPTARGET_AVDD_SH__RESET_VALUE         0x00000024U
/** @} */
#define SWREG_AON_AON1__TYPE                                           uint32_t
#define SWREG_AON_AON1__READ                                        0x0fffffffU
#define SWREG_AON_AON1__WRITE                                       0x0fffffffU
#define SWREG_AON_AON1__PRESERVED                                   0x00000000U
#define SWREG_AON_AON1__RESET_VALUE                                 0x04830428U

#endif /* __SWREG_AON_AON1_MACRO__ */

/** @} end of aon1 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_aon2 */
/**
 * @defgroup swreg_aon_regs_core_aon2 aon2
 * @brief swreg aon regs definitions.
 * @{
 */
#ifndef __SWREG_AON_AON2_MACRO__
#define __SWREG_AON_AON2_MACRO__

/* macros for field timeTargetHarv2Store_SH */
/**
 * @defgroup swreg_aon_regs_core_timeTargetHarv2Store_SH_field timeTargetHarv2Store_SH_field
 * @brief macros for field timeTargetHarv2Store_SH
 * @details target time for the harvest to store mode, also target dump time for vddpa (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__SHIFT                        0
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__WIDTH                        7
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__MASK               0x0000007fU
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define SWREG_AON_AON2__TIMETARGETHARV2STORE_SH__RESET_VALUE        0x0000001eU
/** @} */

/* macros for field targetIsDumpHarv2Store_SH */
/**
 * @defgroup swreg_aon_regs_core_targetIsDumpHarv2Store_SH_field targetIsDumpHarv2Store_SH_field
 * @brief macros for field targetIsDumpHarv2Store_SH
 * @details if 1 the target for the harvest to store mode is the dump time, otherwise it is the energize time (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__SHIFT                      7
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__WIDTH                      1
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__MASK             0x00000080U
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define SWREG_AON_AON2__TARGETISDUMPHARV2STORE_SH__RESET_VALUE      0x00000000U
/** @} */

/* macros for field chargeStartingReady_SH */
/**
 * @defgroup swreg_aon_regs_core_chargeStartingReady_SH_field chargeStartingReady_SH_field
 * @brief macros for field chargeStartingReady_SH
 * @details It affects charging STORE from VHARV and BATT, and charging VBATT from STORE. In these modes when the target time is dump we startwith constant energize time until the destination is ready (vstoreGood or vbattGood becomes 1). When the target time is energize we are always in constant energize mode. In this case, if chargeStartingReady_SH=0 before the supply is ready we are in startup mode, in which the energize time is constant regargless of if the dump time is maximized. If chargeStartingReady_SH=1 the supply is always ready and we start charging in steady state mode in which while energize is set, if the dump time is maximized, the energize time is reduced to satisfy ZCD (shadowed in simple and main)
 * @{
 */
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__SHIFT                         8
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__WIDTH                         1
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__MASK                0x00000100U
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define SWREG_AON_AON2__CHARGESTARTINGREADY_SH__RESET_VALUE         0x00000000U
/** @} */

/* macros for field timeEnergStart_battery */
/**
 * @defgroup swreg_aon_regs_core_timeEnergStart_battery_field timeEnergStart_battery_field
 * @brief macros for field timeEnergStart_battery
 * @details target energize time for battery, used before the supply is ready (used in simple and main)
 * @{
 */
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__SHIFT                         9
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__WIDTH                         5
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__MASK                0x00003e00U
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003e00U) >> 9)
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00003e00U)
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003e00U) | (((uint32_t)(src) <<\
                    9) & 0x00003e00U)
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00003e00U)))
#define SWREG_AON_AON2__TIMEENERGSTART_BATTERY__RESET_VALUE         0x00000008U
/** @} */

/* macros for field timeEnergStart_store */
/**
 * @defgroup swreg_aon_regs_core_timeEnergStart_store_field timeEnergStart_store_field
 * @brief macros for field timeEnergStart_store
 * @details target energize time for store, used before the supply is ready (used in simple and main) timeEnergStart_harvest was removed and timeTargetHarv2Store_SH is used instead. Better to keep targetIsDumpHarv2Store_SH 0, because if targetIsDumpHarv2Store_SH=1, timeTargetHarv2Store_SH is energize time for harv->supplies and harv->store at startup and dump time for harv->store after store is ready.
 * @{
 */
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__SHIFT                          14
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__WIDTH                           5
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__MASK                  0x0007c000U
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007c000U) >> 14)
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0007c000U)
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007c000U) | (((uint32_t)(src) <<\
                    14) & 0x0007c000U)
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0007c000U)))
#define SWREG_AON_AON2__TIMEENERGSTART_STORE__RESET_VALUE           0x0000000cU
/** @} */

/* macros for field timeAfterDump_Start */
/**
 * @defgroup swreg_aon_regs_core_timeAfterDump_Start_field timeAfterDump_Start_field
 * @brief macros for field timeAfterDump_Start
 * @details length of state after dump at startup (normally plan state), during supply rampup and also before Vaux is ready. The higher the value the lower the startup current. Setting greater than zero is safer for timing, although should be OK. (x8 + 7)(used in simple and main)
 * @{
 */
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__SHIFT                           19
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__WIDTH                            4
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__MASK                   0x00780000U
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00780000U) >> 19)
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00780000U)
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00780000U) | (((uint32_t)(src) <<\
                    19) & 0x00780000U)
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00780000U)))
#define SWREG_AON_AON2__TIMEAFTERDUMP_START__RESET_VALUE            0x00000007U
/** @} */

/* macros for field loadRegAon */
/**
 * @defgroup swreg_aon_regs_core_loadRegAon_field loadRegAon_field
 * @brief macros for field loadRegAon
 * @details load the Aon shadow register
 * @{
 */
#define SWREG_AON_AON2__LOADREGAON__SHIFT                                    23
#define SWREG_AON_AON2__LOADREGAON__WIDTH                                     1
#define SWREG_AON_AON2__LOADREGAON__MASK                            0x00800000U
#define SWREG_AON_AON2__LOADREGAON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SWREG_AON_AON2__LOADREGAON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SWREG_AON_AON2__LOADREGAON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SWREG_AON_AON2__LOADREGAON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SWREG_AON_AON2__LOADREGAON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SWREG_AON_AON2__LOADREGAON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SWREG_AON_AON2__LOADREGAON__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field changeFsm_ovr */
/**
 * @defgroup swreg_aon_regs_core_changeFsm_ovr_field changeFsm_ovr_field
 * @brief macros for field changeFsm_ovr
 * @details override changeFsm and fsmToUse
 * @{
 */
#define SWREG_AON_AON2__CHANGEFSM_OVR__SHIFT                                 24
#define SWREG_AON_AON2__CHANGEFSM_OVR__WIDTH                                  1
#define SWREG_AON_AON2__CHANGEFSM_OVR__MASK                         0x01000000U
#define SWREG_AON_AON2__CHANGEFSM_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SWREG_AON_AON2__CHANGEFSM_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SWREG_AON_AON2__CHANGEFSM_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SWREG_AON_AON2__CHANGEFSM_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SWREG_AON_AON2__CHANGEFSM_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SWREG_AON_AON2__CHANGEFSM_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SWREG_AON_AON2__CHANGEFSM_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field changeFsm_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_changeFsm_ovrVal_field changeFsm_ovrVal_field
 * @brief macros for field changeFsm_ovrVal
 * @details override value of changeFsm
 * @{
 */
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__SHIFT                              25
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__WIDTH                               1
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__MASK                      0x02000000U
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define SWREG_AON_AON2__CHANGEFSM_OVRVAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field fsmToUse_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_fsmToUse_ovrVal_field fsmToUse_ovrVal_field
 * @brief macros for field fsmToUse_ovrVal
 * @details override value of fsmToUse. Must be set before changeFsm_ovrVal posedge
 * @{
 */
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__SHIFT                               26
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__WIDTH                                2
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__MASK                       0x0c000000U
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define SWREG_AON_AON2__FSMTOUSE_OVRVAL__RESET_VALUE                0x00000003U
/** @} */

/* macros for field rstStoreUnavailable */
/**
 * @defgroup swreg_aon_regs_core_rstStoreUnavailable_field rstStoreUnavailable_field
 * @brief macros for field rstStoreUnavailable
 * @details reset the energize and dump time of all the modes whose source is store, when store becomes unavailable as a source (vstoreGood=0)
 * @{
 */
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__SHIFT                           28
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__WIDTH                            1
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__MASK                   0x10000000U
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define SWREG_AON_AON2__RSTSTOREUNAVAILABLE__RESET_VALUE            0x00000001U
/** @} */

/* macros for field useHotStart */
/**
 * @defgroup swreg_aon_regs_core_useHotStart_field useHotStart_field
 * @brief macros for field useHotStart
 * @details use hot start to assume enabled supplies are ready when switching to a new fsm (destReady is immediately asserted)
 * @{
 */
#define SWREG_AON_AON2__USEHOTSTART__SHIFT                                   29
#define SWREG_AON_AON2__USEHOTSTART__WIDTH                                    1
#define SWREG_AON_AON2__USEHOTSTART__MASK                           0x20000000U
#define SWREG_AON_AON2__USEHOTSTART__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define SWREG_AON_AON2__USEHOTSTART__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define SWREG_AON_AON2__USEHOTSTART__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define SWREG_AON_AON2__USEHOTSTART__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define SWREG_AON_AON2__USEHOTSTART__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define SWREG_AON_AON2__USEHOTSTART__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define SWREG_AON_AON2__USEHOTSTART__RESET_VALUE                    0x00000001U
/** @} */
#define SWREG_AON_AON2__TYPE                                           uint32_t
#define SWREG_AON_AON2__READ                                        0x3fffffffU
#define SWREG_AON_AON2__WRITE                                       0x3fffffffU
#define SWREG_AON_AON2__PRESERVED                                   0x00000000U
#define SWREG_AON_AON2__RESET_VALUE                                 0x3c3b101eU

#endif /* __SWREG_AON_AON2_MACRO__ */

/** @} end of aon2 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_aon3 */
/**
 * @defgroup swreg_aon_regs_core_aon3 aon3
 * @brief swreg aon regs definitions.
 * @{
 */
#ifndef __SWREG_AON_AON3_MACRO__
#define __SWREG_AON_AON3_MACRO__

/* macros for field clkUnitDelTop */
/**
 * @defgroup swreg_aon_regs_core_clkUnitDelTop_field clkUnitDelTop_field
 * @brief macros for field clkUnitDelTop
 * @details unit delay for the clock of the top FSM.
 * @{
 */
#define SWREG_AON_AON3__CLKUNITDELTOP__SHIFT                                  0
#define SWREG_AON_AON3__CLKUNITDELTOP__WIDTH                                  3
#define SWREG_AON_AON3__CLKUNITDELTOP__MASK                         0x00000007U
#define SWREG_AON_AON3__CLKUNITDELTOP__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWREG_AON_AON3__CLKUNITDELTOP__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWREG_AON_AON3__CLKUNITDELTOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define SWREG_AON_AON3__CLKUNITDELTOP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define SWREG_AON_AON3__CLKUNITDELTOP__RESET_VALUE                  0x00000004U
/** @} */

/* macros for field clkFixedTop */
/**
 * @defgroup swreg_aon_regs_core_clkFixedTop_field clkFixedTop_field
 * @brief macros for field clkFixedTop
 * @details fixed time for the clock of the top FSM. clkFixedTop=3 and clkUnitDelTop=4 provides a ~6.4 MHz clock in typical corner.
 * @{
 */
#define SWREG_AON_AON3__CLKFIXEDTOP__SHIFT                                    3
#define SWREG_AON_AON3__CLKFIXEDTOP__WIDTH                                    3
#define SWREG_AON_AON3__CLKFIXEDTOP__MASK                           0x00000038U
#define SWREG_AON_AON3__CLKFIXEDTOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define SWREG_AON_AON3__CLKFIXEDTOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define SWREG_AON_AON3__CLKFIXEDTOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define SWREG_AON_AON3__CLKFIXEDTOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define SWREG_AON_AON3__CLKFIXEDTOP__RESET_VALUE                    0x00000003U
/** @} */

/* macros for field enableSource_ovr */
/**
 * @defgroup swreg_aon_regs_core_enableSource_ovr_field enableSource_ovr_field
 * @brief macros for field enableSource_ovr
 * @details override enables for the 3 sources
 * @{
 */
#define SWREG_AON_AON3__ENABLESOURCE_OVR__SHIFT                               6
#define SWREG_AON_AON3__ENABLESOURCE_OVR__WIDTH                               3
#define SWREG_AON_AON3__ENABLESOURCE_OVR__MASK                      0x000001c0U
#define SWREG_AON_AON3__ENABLESOURCE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define SWREG_AON_AON3__ENABLESOURCE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define SWREG_AON_AON3__ENABLESOURCE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define SWREG_AON_AON3__ENABLESOURCE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define SWREG_AON_AON3__ENABLESOURCE_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field enableSource_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_enableSource_ovrVal_field enableSource_ovrVal_field
 * @brief macros for field enableSource_ovrVal
 * @details override values of the enables for the 3 sources
 * @{
 */
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__SHIFT                            9
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__WIDTH                            3
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__MASK                   0x00000e00U
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define SWREG_AON_AON3__ENABLESOURCE_OVRVAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field enableDest_ovr */
/**
 * @defgroup swreg_aon_regs_core_enableDest_ovr_field enableDest_ovr_field
 * @brief macros for field enableDest_ovr
 * @details override enables for the 5 destinations
 * @{
 */
#define SWREG_AON_AON3__ENABLEDEST_OVR__SHIFT                                12
#define SWREG_AON_AON3__ENABLEDEST_OVR__WIDTH                                 5
#define SWREG_AON_AON3__ENABLEDEST_OVR__MASK                        0x0001f000U
#define SWREG_AON_AON3__ENABLEDEST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001f000U) >> 12)
#define SWREG_AON_AON3__ENABLEDEST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0001f000U)
#define SWREG_AON_AON3__ENABLEDEST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001f000U) | (((uint32_t)(src) <<\
                    12) & 0x0001f000U)
#define SWREG_AON_AON3__ENABLEDEST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0001f000U)))
#define SWREG_AON_AON3__ENABLEDEST_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field enableDest_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_enableDest_ovrVal_field enableDest_ovrVal_field
 * @brief macros for field enableDest_ovrVal
 * @details override values of the enables for the 5 destinations
 * @{
 */
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__SHIFT                             17
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__WIDTH                              5
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__MASK                     0x003e0000U
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003e0000U) >> 17)
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x003e0000U)
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003e0000U) | (((uint32_t)(src) <<\
                    17) & 0x003e0000U)
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x003e0000U)))
#define SWREG_AON_AON3__ENABLEDEST_OVRVAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field poweronSimple */
/**
 * @defgroup swreg_aon_regs_core_poweronSimple_field poweronSimple_field
 * @brief macros for field poweronSimple
 * @details force power on the simple FSM
 * @{
 */
#define SWREG_AON_AON3__POWERONSIMPLE__SHIFT                                 22
#define SWREG_AON_AON3__POWERONSIMPLE__WIDTH                                  1
#define SWREG_AON_AON3__POWERONSIMPLE__MASK                         0x00400000U
#define SWREG_AON_AON3__POWERONSIMPLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define SWREG_AON_AON3__POWERONSIMPLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define SWREG_AON_AON3__POWERONSIMPLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define SWREG_AON_AON3__POWERONSIMPLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define SWREG_AON_AON3__POWERONSIMPLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define SWREG_AON_AON3__POWERONSIMPLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define SWREG_AON_AON3__POWERONSIMPLE__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field poweronMain */
/**
 * @defgroup swreg_aon_regs_core_poweronMain_field poweronMain_field
 * @brief macros for field poweronMain
 * @details force power on the main FSM
 * @{
 */
#define SWREG_AON_AON3__POWERONMAIN__SHIFT                                   23
#define SWREG_AON_AON3__POWERONMAIN__WIDTH                                    1
#define SWREG_AON_AON3__POWERONMAIN__MASK                           0x00800000U
#define SWREG_AON_AON3__POWERONMAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SWREG_AON_AON3__POWERONMAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SWREG_AON_AON3__POWERONMAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SWREG_AON_AON3__POWERONMAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SWREG_AON_AON3__POWERONMAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SWREG_AON_AON3__POWERONMAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SWREG_AON_AON3__POWERONMAIN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field resetPreviousFsm */
/**
 * @defgroup swreg_aon_regs_core_resetPreviousFsm_field resetPreviousFsm_field
 * @brief macros for field resetPreviousFsm
 * @details reset the previous FSM, even if its power domain remains established. By default the previous FSM maintains its state if its supply does not collapse.
 * @{
 */
#define SWREG_AON_AON3__RESETPREVIOUSFSM__SHIFT                              24
#define SWREG_AON_AON3__RESETPREVIOUSFSM__WIDTH                               1
#define SWREG_AON_AON3__RESETPREVIOUSFSM__MASK                      0x01000000U
#define SWREG_AON_AON3__RESETPREVIOUSFSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SWREG_AON_AON3__RESETPREVIOUSFSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SWREG_AON_AON3__RESETPREVIOUSFSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SWREG_AON_AON3__RESETPREVIOUSFSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SWREG_AON_AON3__RESETPREVIOUSFSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SWREG_AON_AON3__RESETPREVIOUSFSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SWREG_AON_AON3__RESETPREVIOUSFSM__RESET_VALUE               0x00000000U
/** @} */

/* macros for field hsTiny_ovr */
/**
 * @defgroup swreg_aon_regs_core_hsTiny_ovr_field hsTiny_ovr_field
 * @brief macros for field hsTiny_ovr
 * @details override of the vdd_tiny head switch control, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON3__HSTINY_OVR__SHIFT                                    25
#define SWREG_AON_AON3__HSTINY_OVR__WIDTH                                     1
#define SWREG_AON_AON3__HSTINY_OVR__MASK                            0x02000000U
#define SWREG_AON_AON3__HSTINY_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define SWREG_AON_AON3__HSTINY_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define SWREG_AON_AON3__HSTINY_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define SWREG_AON_AON3__HSTINY_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define SWREG_AON_AON3__HSTINY_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define SWREG_AON_AON3__HSTINY_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define SWREG_AON_AON3__HSTINY_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field hsTiny_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_hsTiny_ovrVal_field hsTiny_ovrVal_field
 * @brief macros for field hsTiny_ovrVal
 * @details override value of the vdd_tiny head switch control, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON3__HSTINY_OVRVAL__SHIFT                                 26
#define SWREG_AON_AON3__HSTINY_OVRVAL__WIDTH                                  1
#define SWREG_AON_AON3__HSTINY_OVRVAL__MASK                         0x04000000U
#define SWREG_AON_AON3__HSTINY_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define SWREG_AON_AON3__HSTINY_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define SWREG_AON_AON3__HSTINY_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define SWREG_AON_AON3__HSTINY_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define SWREG_AON_AON3__HSTINY_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define SWREG_AON_AON3__HSTINY_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define SWREG_AON_AON3__HSTINY_OVRVAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field hsSimple_ovr */
/**
 * @defgroup swreg_aon_regs_core_hsSimple_ovr_field hsSimple_ovr_field
 * @brief macros for field hsSimple_ovr
 * @details override of the vdd_simple head switch control, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON3__HSSIMPLE_OVR__SHIFT                                  27
#define SWREG_AON_AON3__HSSIMPLE_OVR__WIDTH                                   1
#define SWREG_AON_AON3__HSSIMPLE_OVR__MASK                          0x08000000U
#define SWREG_AON_AON3__HSSIMPLE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define SWREG_AON_AON3__HSSIMPLE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define SWREG_AON_AON3__HSSIMPLE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define SWREG_AON_AON3__HSSIMPLE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define SWREG_AON_AON3__HSSIMPLE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define SWREG_AON_AON3__HSSIMPLE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define SWREG_AON_AON3__HSSIMPLE_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field hsSimple_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_hsSimple_ovrVal_field hsSimple_ovrVal_field
 * @brief macros for field hsSimple_ovrVal
 * @details override value of the vdd_simple head switch control, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__SHIFT                               28
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__WIDTH                                1
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__MASK                       0x10000000U
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define SWREG_AON_AON3__HSSIMPLE_OVRVAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field hsMain_ovr */
/**
 * @defgroup swreg_aon_regs_core_hsMain_ovr_field hsMain_ovr_field
 * @brief macros for field hsMain_ovr
 * @details override of the vdd_main head switch control, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON3__HSMAIN_OVR__SHIFT                                    29
#define SWREG_AON_AON3__HSMAIN_OVR__WIDTH                                     1
#define SWREG_AON_AON3__HSMAIN_OVR__MASK                            0x20000000U
#define SWREG_AON_AON3__HSMAIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define SWREG_AON_AON3__HSMAIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define SWREG_AON_AON3__HSMAIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define SWREG_AON_AON3__HSMAIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define SWREG_AON_AON3__HSMAIN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define SWREG_AON_AON3__HSMAIN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define SWREG_AON_AON3__HSMAIN_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field hsMain_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_hsMain_ovrVal_field hsMain_ovrVal_field
 * @brief macros for field hsMain_ovrVal
 * @details override value of the vdd_main head switch control, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON3__HSMAIN_OVRVAL__SHIFT                                 30
#define SWREG_AON_AON3__HSMAIN_OVRVAL__WIDTH                                  1
#define SWREG_AON_AON3__HSMAIN_OVRVAL__MASK                         0x40000000U
#define SWREG_AON_AON3__HSMAIN_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SWREG_AON_AON3__HSMAIN_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SWREG_AON_AON3__HSMAIN_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SWREG_AON_AON3__HSMAIN_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SWREG_AON_AON3__HSMAIN_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SWREG_AON_AON3__HSMAIN_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SWREG_AON_AON3__HSMAIN_OVRVAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field dontUseAon_ovr */
/**
 * @defgroup swreg_aon_regs_core_dontUseAon_ovr_field dontUseAon_ovr_field
 * @brief macros for field dontUseAon_ovr
 * @details Don't use. Formerly known as loadShadowAon_ovr. Override of the load for the shadowAon register, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON3__DONTUSEAON_OVR__SHIFT                                31
#define SWREG_AON_AON3__DONTUSEAON_OVR__WIDTH                                 1
#define SWREG_AON_AON3__DONTUSEAON_OVR__MASK                        0x80000000U
#define SWREG_AON_AON3__DONTUSEAON_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SWREG_AON_AON3__DONTUSEAON_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SWREG_AON_AON3__DONTUSEAON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SWREG_AON_AON3__DONTUSEAON_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SWREG_AON_AON3__DONTUSEAON_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SWREG_AON_AON3__DONTUSEAON_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SWREG_AON_AON3__DONTUSEAON_OVR__RESET_VALUE                 0x00000000U
/** @} */
#define SWREG_AON_AON3__TYPE                                           uint32_t
#define SWREG_AON_AON3__READ                                        0xffffffffU
#define SWREG_AON_AON3__WRITE                                       0xffffffffU
#define SWREG_AON_AON3__PRESERVED                                   0x00000000U
#define SWREG_AON_AON3__RESET_VALUE                                 0x0000001cU

#endif /* __SWREG_AON_AON3_MACRO__ */

/** @} end of aon3 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_aon4 */
/**
 * @defgroup swreg_aon_regs_core_aon4 aon4
 * @brief swreg aon regs definitions.
 * @{
 */
#ifndef __SWREG_AON_AON4_MACRO__
#define __SWREG_AON_AON4_MACRO__

/* macros for field dontUseAon_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_dontUseAon_ovrVal_field dontUseAon_ovrVal_field
 * @brief macros for field dontUseAon_ovrVal
 * @details Don't use. FKA loadShadowAon_ovrVal. Override value of the load for the shadowAon register, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__SHIFT                              0
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__WIDTH                              1
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__MASK                     0x00000001U
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWREG_AON_AON4__DONTUSEAON_OVRVAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field dontUseSimple_ovr */
/**
 * @defgroup swreg_aon_regs_core_dontUseSimple_ovr_field dontUseSimple_ovr_field
 * @brief macros for field dontUseSimple_ovr
 * @details Don't use. FKA loadShadowSimple_ovr. Override of the load for the shadowSimple register, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__SHIFT                              1
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__WIDTH                              1
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__MASK                     0x00000002U
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field dontUseSimple_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_dontUseSimple_ovrVal_field dontUseSimple_ovrVal_field
 * @brief macros for field dontUseSimple_ovrVal
 * @details Don't use. FKA loadShadowSimple_ovrVal. Override value of the load for the shadowSimple register, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__SHIFT                           2
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__WIDTH                           1
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__MASK                  0x00000004U
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SWREG_AON_AON4__DONTUSESIMPLE_OVRVAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field dontUseMain_ovr */
/**
 * @defgroup swreg_aon_regs_core_dontUseMain_ovr_field dontUseMain_ovr_field
 * @brief macros for field dontUseMain_ovr
 * @details Don't use. FKA loadShadowMain_ovr. Override of the load for the shadowMain register, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__SHIFT                                3
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__WIDTH                                1
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__MASK                       0x00000008U
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SWREG_AON_AON4__DONTUSEMAIN_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field dontUseMain_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_dontUseMain_ovrVal_field dontUseMain_ovrVal_field
 * @brief macros for field dontUseMain_ovrVal
 * @details Don't use. FKA loadShadowMain_ovrVal. Override value of the load for the shadowMain register, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__SHIFT                             4
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__WIDTH                             1
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__MASK                    0x00000010U
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define SWREG_AON_AON4__DONTUSEMAIN_OVRVAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field dontUseUnitDel_ovr */
/**
 * @defgroup swreg_aon_regs_core_dontUseUnitDel_ovr_field dontUseUnitDel_ovr_field
 * @brief macros for field dontUseUnitDel_ovr
 * @details Don't use. FKA loadShadowUnitDel_ovr. Override of the load for shadowUnitDel, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__SHIFT                             5
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__WIDTH                             1
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__MASK                    0x00000020U
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field dontUseUnitDel_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_dontUseUnitDel_ovrVal_field dontUseUnitDel_ovrVal_field
 * @brief macros for field dontUseUnitDel_ovrVal
 * @details Don't use. FKA loadShadowUnitDel_ovrVal. Override value of the load for shadowUnitDel, bypassing fsmTop
 * @{
 */
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__SHIFT                          6
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__WIDTH                          1
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__MASK                 0x00000040U
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define SWREG_AON_AON4__DONTUSEUNITDEL_OVRVAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field updateUnitDel_ovr */
/**
 * @defgroup swreg_aon_regs_core_updateUnitDel_ovr_field updateUnitDel_ovr_field
 * @brief macros for field updateUnitDel_ovr
 * @details override updateUnitDel
 * @{
 */
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__SHIFT                              7
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__WIDTH                              1
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__MASK                     0x00000080U
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field updateUnitDel_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_updateUnitDel_ovrVal_field updateUnitDel_ovrVal_field
 * @brief macros for field updateUnitDel_ovrVal
 * @details override value of updateUnitDel At the posedge it updates the unit delay for the clock used by the active FSM (tiny, simple or active)If the main FSM is used (or powered) and skipClkCal=1'b0, it performs a clock cal. Otherwise it loads clkUnitDelReg
 * @{
 */
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__SHIFT                           8
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__WIDTH                           1
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__MASK                  0x00000100U
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define SWREG_AON_AON4__UPDATEUNITDEL_OVRVAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field clkUnitDelReg */
/**
 * @defgroup swreg_aon_regs_core_clkUnitDelReg_field clkUnitDelReg_field
 * @brief macros for field clkUnitDelReg
 * @details unit delay for the active clock, to be used at the posedge of updateUnitDel if the main Fsm is powered down or skipClkCal=1'b1. Also the value coming out of reset.
 * @{
 */
#define SWREG_AON_AON4__CLKUNITDELREG__SHIFT                                  9
#define SWREG_AON_AON4__CLKUNITDELREG__WIDTH                                  5
#define SWREG_AON_AON4__CLKUNITDELREG__MASK                         0x00003e00U
#define SWREG_AON_AON4__CLKUNITDELREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003e00U) >> 9)
#define SWREG_AON_AON4__CLKUNITDELREG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00003e00U)
#define SWREG_AON_AON4__CLKUNITDELREG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003e00U) | (((uint32_t)(src) <<\
                    9) & 0x00003e00U)
#define SWREG_AON_AON4__CLKUNITDELREG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00003e00U)))
#define SWREG_AON_AON4__CLKUNITDELREG__RESET_VALUE                  0x00000009U
/** @} */

/* macros for field tinySourceStore_ovr */
/**
 * @defgroup swreg_aon_regs_core_tinySourceStore_ovr_field tinySourceStore_ovr_field
 * @brief macros for field tinySourceStore_ovr
 * @details override tinySourceStore
 * @{
 */
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__SHIFT                           14
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__WIDTH                            1
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__MASK                   0x00004000U
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field tinySourceStore_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_tinySourceStore_ovrVal_field tinySourceStore_ovrVal_field
 * @brief macros for field tinySourceStore_ovrVal
 * @details override value of tinySourceStore. If 1, the source during the tiny FSM will be the STORE, otherwise it will be the BATT
 * @{
 */
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__SHIFT                        15
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__WIDTH                         1
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__MASK                0x00008000U
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define SWREG_AON_AON4__TINYSOURCESTORE_OVRVAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field pn_ovr */
/**
 * @defgroup swreg_aon_regs_core_pn_ovr_field pn_ovr_field
 * @brief macros for field pn_ovr
 * @details override enables for the N and P parts of the switches. Switch order:battP, battN, storeSrcP, storeSrcN, harvP, harvN, storeDstP, storeDstN, avddP, dvddP
 * @{
 */
#define SWREG_AON_AON4__PN_OVR__SHIFT                                        16
#define SWREG_AON_AON4__PN_OVR__WIDTH                                        10
#define SWREG_AON_AON4__PN_OVR__MASK                                0x03ff0000U
#define SWREG_AON_AON4__PN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define SWREG_AON_AON4__PN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define SWREG_AON_AON4__PN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define SWREG_AON_AON4__PN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define SWREG_AON_AON4__PN_OVR__RESET_VALUE                         0x00000000U
/** @} */
#define SWREG_AON_AON4__TYPE                                           uint32_t
#define SWREG_AON_AON4__READ                                        0x03ffffffU
#define SWREG_AON_AON4__WRITE                                       0x03ffffffU
#define SWREG_AON_AON4__PRESERVED                                   0x00000000U
#define SWREG_AON_AON4__RESET_VALUE                                 0x00001200U

#endif /* __SWREG_AON_AON4_MACRO__ */

/** @} end of aon4 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_aon5 */
/**
 * @defgroup swreg_aon_regs_core_aon5 aon5
 * @brief swreg aon regs definitions.
 * @{
 */
#ifndef __SWREG_AON_AON5_MACRO__
#define __SWREG_AON_AON5_MACRO__

/* macros for field pn_ovrVal */
/**
 * @defgroup swreg_aon_regs_core_pn_ovrVal_field pn_ovrVal_field
 * @brief macros for field pn_ovrVal
 * @details override values of the enables for the N and P parts of the switches
 * @{
 */
#define SWREG_AON_AON5__PN_OVRVAL__SHIFT                                      0
#define SWREG_AON_AON5__PN_OVRVAL__WIDTH                                     10
#define SWREG_AON_AON5__PN_OVRVAL__MASK                             0x000003ffU
#define SWREG_AON_AON5__PN_OVRVAL__READ(src)    ((uint32_t)(src) & 0x000003ffU)
#define SWREG_AON_AON5__PN_OVRVAL__WRITE(src)   ((uint32_t)(src) & 0x000003ffU)
#define SWREG_AON_AON5__PN_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define SWREG_AON_AON5__PN_OVRVAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define SWREG_AON_AON5__PN_OVRVAL__RESET_VALUE                      0x000003ffU
/** @} */

/* macros for field size */
/**
 * @defgroup swreg_aon_regs_core_size_field size_field
 * @brief macros for field size
 * @details switch size, with the following order:[19:18] battery [17:16] store, source side [15:14] harvest [13:12] ground, source side [11:10] store, destination side [9:8] avdd [7:6] vddio [5:4] vaux [3:2] dvdd [1:0] ground, destination side
 * @{
 */
#define SWREG_AON_AON5__SIZE__SHIFT                                          10
#define SWREG_AON_AON5__SIZE__WIDTH                                          20
#define SWREG_AON_AON5__SIZE__MASK                                  0x3ffffc00U
#define SWREG_AON_AON5__SIZE__READ(src) (((uint32_t)(src) & 0x3ffffc00U) >> 10)
#define SWREG_AON_AON5__SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x3ffffc00U)
#define SWREG_AON_AON5__SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ffffc00U) | (((uint32_t)(src) <<\
                    10) & 0x3ffffc00U)
#define SWREG_AON_AON5__SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x3ffffc00U)))
#define SWREG_AON_AON5__SIZE__RESET_VALUE                           0x000fffffU
/** @} */

/* macros for field delZCD1 */
/**
 * @defgroup swreg_aon_regs_core_delZCD1_field delZCD1_field
 * @brief macros for field delZCD1
 * @details delay1 for ZCD
 * @{
 */
#define SWREG_AON_AON5__DELZCD1__SHIFT                                       30
#define SWREG_AON_AON5__DELZCD1__WIDTH                                        2
#define SWREG_AON_AON5__DELZCD1__MASK                               0xc0000000U
#define SWREG_AON_AON5__DELZCD1__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define SWREG_AON_AON5__DELZCD1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define SWREG_AON_AON5__DELZCD1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define SWREG_AON_AON5__DELZCD1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define SWREG_AON_AON5__DELZCD1__RESET_VALUE                        0x00000001U
/** @} */
#define SWREG_AON_AON5__TYPE                                           uint32_t
#define SWREG_AON_AON5__READ                                        0xffffffffU
#define SWREG_AON_AON5__WRITE                                       0xffffffffU
#define SWREG_AON_AON5__PRESERVED                                   0x00000000U
#define SWREG_AON_AON5__RESET_VALUE                                 0x7fffffffU

#endif /* __SWREG_AON_AON5_MACRO__ */

/** @} end of aon5 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_aon6 */
/**
 * @defgroup swreg_aon_regs_core_aon6 aon6
 * @brief swreg aon regs definitions.
 * @{
 */
#ifndef __SWREG_AON_AON6_MACRO__
#define __SWREG_AON_AON6_MACRO__

/* macros for field delZCD2 */
/**
 * @defgroup swreg_aon_regs_core_delZCD2_field delZCD2_field
 * @brief macros for field delZCD2
 * @details delay2 for ZCD
 * @{
 */
#define SWREG_AON_AON6__DELZCD2__SHIFT                                        0
#define SWREG_AON_AON6__DELZCD2__WIDTH                                        2
#define SWREG_AON_AON6__DELZCD2__MASK                               0x00000003U
#define SWREG_AON_AON6__DELZCD2__READ(src)      ((uint32_t)(src) & 0x00000003U)
#define SWREG_AON_AON6__DELZCD2__WRITE(src)     ((uint32_t)(src) & 0x00000003U)
#define SWREG_AON_AON6__DELZCD2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define SWREG_AON_AON6__DELZCD2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define SWREG_AON_AON6__DELZCD2__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field delEnergDump */
/**
 * @defgroup swreg_aon_regs_core_delEnergDump_field delEnergDump_field
 * @brief macros for field delEnergDump
 * @details delay to avoid overlap between energize and dump
 * @{
 */
#define SWREG_AON_AON6__DELENERGDUMP__SHIFT                                   2
#define SWREG_AON_AON6__DELENERGDUMP__WIDTH                                   4
#define SWREG_AON_AON6__DELENERGDUMP__MASK                          0x0000003cU
#define SWREG_AON_AON6__DELENERGDUMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000003cU) >> 2)
#define SWREG_AON_AON6__DELENERGDUMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000003cU)
#define SWREG_AON_AON6__DELENERGDUMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003cU) | (((uint32_t)(src) <<\
                    2) & 0x0000003cU)
#define SWREG_AON_AON6__DELENERGDUMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000003cU)))
#define SWREG_AON_AON6__DELENERGDUMP__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field ateTest */
/**
 * @defgroup swreg_aon_regs_core_ateTest_field ateTest_field
 * @brief macros for field ateTest
 * @details turn on ATE test mode
 * @{
 */
#define SWREG_AON_AON6__ATETEST__SHIFT                                        6
#define SWREG_AON_AON6__ATETEST__WIDTH                                        1
#define SWREG_AON_AON6__ATETEST__MASK                               0x00000040U
#define SWREG_AON_AON6__ATETEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define SWREG_AON_AON6__ATETEST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define SWREG_AON_AON6__ATETEST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define SWREG_AON_AON6__ATETEST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define SWREG_AON_AON6__ATETEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define SWREG_AON_AON6__ATETEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define SWREG_AON_AON6__ATETEST__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field digTestSel */
/**
 * @defgroup swreg_aon_regs_core_digTestSel_field digTestSel_field
 * @brief macros for field digTestSel
 * @details digital bus select signal, as follows:31-28: NC27: indCurrentSign26-22: request21: canHarvest20: mustHarvest19: vstoreGood18: vbattGood17: vstoreTooHigh16: vbattTooHigh15-11: supReady10: suppliesReady9: harvesting8: swDump7: swSampleIndCurrent6: mode: Battery -> VSUP0, BuckBoost 5: mode: Battery -> VSUP0, Buck 4: mode: Store -> VSUP0, Buck 3: 2nd active clock generator 2: 1st active clock generator 1: top clock generator 0: NC
 * @{
 */
#define SWREG_AON_AON6__DIGTESTSEL__SHIFT                                     7
#define SWREG_AON_AON6__DIGTESTSEL__WIDTH                                     5
#define SWREG_AON_AON6__DIGTESTSEL__MASK                            0x00000f80U
#define SWREG_AON_AON6__DIGTESTSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f80U) >> 7)
#define SWREG_AON_AON6__DIGTESTSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000f80U)
#define SWREG_AON_AON6__DIGTESTSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f80U) | (((uint32_t)(src) <<\
                    7) & 0x00000f80U)
#define SWREG_AON_AON6__DIGTESTSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000f80U)))
#define SWREG_AON_AON6__DIGTESTSEL__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field spare */
/**
 * @defgroup swreg_aon_regs_core_spare_field spare_field
 * @brief macros for field spare
 * @details spare[2] is harvesting_ovr and spare[3] is harvesting_ovr_val spare[1] is unused spare[0] is rstbFsmTop, if set to zero, it will assert reset to fsmTop and all other FSMs in swreg_dig
 * @{
 */
#define SWREG_AON_AON6__SPARE__SHIFT                                         12
#define SWREG_AON_AON6__SPARE__WIDTH                                          4
#define SWREG_AON_AON6__SPARE__MASK                                 0x0000f000U
#define SWREG_AON_AON6__SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define SWREG_AON_AON6__SPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define SWREG_AON_AON6__SPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define SWREG_AON_AON6__SPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define SWREG_AON_AON6__SPARE__RESET_VALUE                          0x00000003U
/** @} */
#define SWREG_AON_AON6__TYPE                                           uint32_t
#define SWREG_AON_AON6__READ                                        0x0000ffffU
#define SWREG_AON_AON6__WRITE                                       0x0000ffffU
#define SWREG_AON_AON6__PRESERVED                                   0x00000000U
#define SWREG_AON_AON6__RESET_VALUE                                 0x0000300dU

#endif /* __SWREG_AON_AON6_MACRO__ */

/** @} end of aon6 */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_readout */
/**
 * @defgroup swreg_aon_regs_core_readout readout
 * @brief aon readout bits definitions.
 * @{
 */
#ifndef __SWREG_AON_READOUT_MACRO__
#define __SWREG_AON_READOUT_MACRO__

/* macros for field stateTop */
/**
 * @defgroup swreg_aon_regs_core_stateTop_field stateTop_field
 * @brief macros for field stateTop
 * @details the fsmTop state
 * @{
 */
#define SWREG_AON_READOUT__STATETOP__SHIFT                                    0
#define SWREG_AON_READOUT__STATETOP__WIDTH                                    4
#define SWREG_AON_READOUT__STATETOP__MASK                           0x0000000fU
#define SWREG_AON_READOUT__STATETOP__READ(src)  ((uint32_t)(src) & 0x0000000fU)
#define SWREG_AON_READOUT__STATETOP__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field fsmCurrent */
/**
 * @defgroup swreg_aon_regs_core_fsmCurrent_field fsmCurrent_field
 * @brief macros for field fsmCurrent
 * @details the currently used fsm
 * @{
 */
#define SWREG_AON_READOUT__FSMCURRENT__SHIFT                                  4
#define SWREG_AON_READOUT__FSMCURRENT__WIDTH                                  2
#define SWREG_AON_READOUT__FSMCURRENT__MASK                         0x00000030U
#define SWREG_AON_READOUT__FSMCURRENT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define SWREG_AON_READOUT__FSMCURRENT__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field fsmPrevious */
/**
 * @defgroup swreg_aon_regs_core_fsmPrevious_field fsmPrevious_field
 * @brief macros for field fsmPrevious
 * @details the previously used fsm
 * @{
 */
#define SWREG_AON_READOUT__FSMPREVIOUS__SHIFT                                 6
#define SWREG_AON_READOUT__FSMPREVIOUS__WIDTH                                 2
#define SWREG_AON_READOUT__FSMPREVIOUS__MASK                        0x000000c0U
#define SWREG_AON_READOUT__FSMPREVIOUS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define SWREG_AON_READOUT__FSMPREVIOUS__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field supReady */
/**
 * @defgroup swreg_aon_regs_core_supReady_field supReady_field
 * @brief macros for field supReady
 * @details the 5 supply ready signals
 * @{
 */
#define SWREG_AON_READOUT__SUPREADY__SHIFT                                    8
#define SWREG_AON_READOUT__SUPREADY__WIDTH                                    5
#define SWREG_AON_READOUT__SUPREADY__MASK                           0x00001f00U
#define SWREG_AON_READOUT__SUPREADY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define SWREG_AON_READOUT__SUPREADY__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field suppliesReady */
/**
 * @defgroup swreg_aon_regs_core_suppliesReady_field suppliesReady_field
 * @brief macros for field suppliesReady
 * @details suppliesReady signal
 * @{
 */
#define SWREG_AON_READOUT__SUPPLIESREADY__SHIFT                              13
#define SWREG_AON_READOUT__SUPPLIESREADY__WIDTH                               1
#define SWREG_AON_READOUT__SUPPLIESREADY__MASK                      0x00002000U
#define SWREG_AON_READOUT__SUPPLIESREADY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define SWREG_AON_READOUT__SUPPLIESREADY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define SWREG_AON_READOUT__SUPPLIESREADY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define SWREG_AON_READOUT__SUPPLIESREADY__RESET_VALUE               0x00000000U
/** @} */

/* macros for field clkUnitDelActive */
/**
 * @defgroup swreg_aon_regs_core_clkUnitDelActive_field clkUnitDelActive_field
 * @brief macros for field clkUnitDelActive
 * @details the unit delay of the active clock, possibly the result of the clock cal
 * @{
 */
#define SWREG_AON_READOUT__CLKUNITDELACTIVE__SHIFT                           14
#define SWREG_AON_READOUT__CLKUNITDELACTIVE__WIDTH                            5
#define SWREG_AON_READOUT__CLKUNITDELACTIVE__MASK                   0x0007c000U
#define SWREG_AON_READOUT__CLKUNITDELACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007c000U) >> 14)
#define SWREG_AON_READOUT__CLKUNITDELACTIVE__RESET_VALUE            0x00000000U
/** @} */
#define SWREG_AON_READOUT__TYPE                                        uint32_t
#define SWREG_AON_READOUT__READ                                     0x0007ffffU
#define SWREG_AON_READOUT__PRESERVED                                0x00000000U
#define SWREG_AON_READOUT__RESET_VALUE                              0x00000000U

#endif /* __SWREG_AON_READOUT_MACRO__ */

/** @} end of readout */

/* macros for BlueprintGlobalNameSpace::SWREG_AON_core_id */
/**
 * @defgroup swreg_aon_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __SWREG_AON_CORE_ID_MACRO__
#define __SWREG_AON_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup swreg_aon_regs_core_id_field id_field
 * @brief macros for field id
 * @details SWRA in ASCII
 * @{
 */
#define SWREG_AON_CORE_ID__ID__SHIFT                                          0
#define SWREG_AON_CORE_ID__ID__WIDTH                                         32
#define SWREG_AON_CORE_ID__ID__MASK                                 0xffffffffU
#define SWREG_AON_CORE_ID__ID__READ(src)        ((uint32_t)(src) & 0xffffffffU)
#define SWREG_AON_CORE_ID__ID__RESET_VALUE                          0x53575241U
/** @} */
#define SWREG_AON_CORE_ID__TYPE                                        uint32_t
#define SWREG_AON_CORE_ID__READ                                     0xffffffffU
#define SWREG_AON_CORE_ID__PRESERVED                                0x00000000U
#define SWREG_AON_CORE_ID__RESET_VALUE                              0x53575241U

#endif /* __SWREG_AON_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of SWREG_AON_REGS_CORE */
#endif /* __REG_SWREG_AON_REGS_CORE_H__ */
