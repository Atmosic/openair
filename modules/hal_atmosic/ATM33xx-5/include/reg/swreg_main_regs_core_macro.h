/*                                                                           */
/* File:       swreg_main_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic swreg_main_regs_core.rdl           */
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


#ifndef __REG_SWREG_MAIN_REGS_CORE_H__
#define __REG_SWREG_MAIN_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup SWREG_MAIN_REGS_CORE swreg_main_regs_core
 * @ingroup AT_REG
 * @brief swreg_main_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main0 */
/**
 * @defgroup swreg_main_regs_core_main0 main0
 * @brief main swreg registers For fields that refer to the sources the order is: 2: BATT 1: STORE 0: HARV For fields that refer to the destinations the order is: 4: STORE 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD For fields that refer to the supplies the order is: 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD For fields that refer to the power transfer modes the order is: 14: STORE -> BATT13: BATT -> STORE12: HARV -> STORE11: HARV -> AVDD10: HARV -> VDDIO9: HARV -> VDDAUX8: HARV -> DVDD7: STORE -> AVDD6: STORE -> VDDIO5: STORE -> VDDAUX4: STORE -> DVDD3: BATT -> AVDD2: BATT -> VDDIO1: BATT -> VDDAUX0: BATT -> DVDD definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN0_MACRO__
#define __SWREG_MAIN_MAIN0_MACRO__

/* macros for field enableGear_SH */
/**
 * @defgroup swreg_main_regs_core_enableGear_SH_field enableGear_SH_field
 * @brief macros for field enableGear_SH
 * @details enable using gears for the corresponding mode. Gears for (STORE -> BATT) are disabled.
 * @{
 */
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__SHIFT                                0
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__WIDTH                               14
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__MASK                       0x00003fffU
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00003fffU)
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00003fffU)
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define SWREG_MAIN_MAIN0__ENABLEGEAR_SH__RESET_VALUE                0x000020ffU
/** @} */

/* macros for field timeStepMax_SH */
/**
 * @defgroup swreg_main_regs_core_timeStepMax_SH_field timeStepMax_SH_field
 * @brief macros for field timeStepMax_SH
 * @details maximum time step used in steady state (x4+3)
 * @{
 */
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__SHIFT                              14
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__WIDTH                               3
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__MASK                      0x0001c000U
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define SWREG_MAIN_MAIN0__TIMESTEPMAX_SH__RESET_VALUE               0x00000007U
/** @} */

/* macros for field timeStepExitFullySettled_SH */
/**
 * @defgroup swreg_main_regs_core_timeStepExitFullySettled_SH_field timeStepExitFullySettled_SH_field
 * @brief macros for field timeStepExitFullySettled_SH
 * @details if the time step becomes higher than this value the fullySettled flag resets (x4+3)
 * @{
 */
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__SHIFT                 17
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__WIDTH                  3
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__MASK         0x000e0000U
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000e0000U) >> 17)
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x000e0000U)
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000e0000U) | (((uint32_t)(src) <<\
                    17) & 0x000e0000U)
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x000e0000U)))
#define SWREG_MAIN_MAIN0__TIMESTEPEXITFULLYSETTLED_SH__RESET_VALUE  0x00000004U
/** @} */

/* macros for field timePlanShort_SH */
/**
 * @defgroup swreg_main_regs_core_timePlanShort_SH_field timePlanShort_SH_field
 * @brief macros for field timePlanShort_SH
 * @details length of a short plan state
 * @{
 */
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__SHIFT                            20
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__WIDTH                             2
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__MASK                    0x00300000U
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define SWREG_MAIN_MAIN0__TIMEPLANSHORT_SH__RESET_VALUE             0x00000000U
/** @} */

/* macros for field attemptIncrGear_SH */
/**
 * @defgroup swreg_main_regs_core_attemptIncrGear_SH_field attemptIncrGear_SH_field
 * @brief macros for field attemptIncrGear_SH
 * @details number of attempts after which if the request is not satisfied the gear increases
 * @{
 */
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__SHIFT                          22
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__WIDTH                           3
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__MASK                  0x01c00000U
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01c00000U) >> 22)
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x01c00000U)
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01c00000U) | (((uint32_t)(src) <<\
                    22) & 0x01c00000U)
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x01c00000U)))
#define SWREG_MAIN_MAIN0__ATTEMPTINCRGEAR_SH__RESET_VALUE           0x00000000U
/** @} */

/* macros for field attemptHopIncrGear_SH */
/**
 * @defgroup swreg_main_regs_core_attemptHopIncrGear_SH_field attemptHopIncrGear_SH_field
 * @brief macros for field attemptHopIncrGear_SH
 * @details number of attempts after which if the request is not satisfied the gear increases when the frequency has hopped
 * @{
 */
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__SHIFT                       25
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__WIDTH                        3
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__MASK               0x0e000000U
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0e000000U) >> 25)
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x0e000000U)
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0e000000U) | (((uint32_t)(src) <<\
                    25) & 0x0e000000U)
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x0e000000U)))
#define SWREG_MAIN_MAIN0__ATTEMPTHOPINCRGEAR_SH__RESET_VALUE        0x00000000U
/** @} */
#define SWREG_MAIN_MAIN0__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN0__READ                                      0x0fffffffU
#define SWREG_MAIN_MAIN0__WRITE                                     0x0fffffffU
#define SWREG_MAIN_MAIN0__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN0__RESET_VALUE                               0x0009e0ffU

#endif /* __SWREG_MAIN_MAIN0_MACRO__ */

/** @} end of main0 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main1 */
/**
 * @defgroup swreg_main_regs_core_main1 main1
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN1_MACRO__
#define __SWREG_MAIN_MAIN1_MACRO__

/* macros for field timeTargetCharge_SH */
/**
 * @defgroup swreg_main_regs_core_timeTargetCharge_SH_field timeTargetCharge_SH_field
 * @brief macros for field timeTargetCharge_SH
 * @details target time for charging store from battery and battery from store
 * @{
 */
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__SHIFT                          0
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__WIDTH                          7
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__MASK                 0x0000007fU
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define SWREG_MAIN_MAIN1__TIMETARGETCHARGE_SH__RESET_VALUE          0x0000001eU
/** @} */

/* macros for field targetIsDumpCharge_SH */
/**
 * @defgroup swreg_main_regs_core_targetIsDumpCharge_SH_field targetIsDumpCharge_SH_field
 * @brief macros for field targetIsDumpCharge_SH
 * @details if 1 the target for the battery to store or store to battery mode is the dump time, otherwise it is the energize time
 * @{
 */
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__SHIFT                        7
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__WIDTH                        1
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__MASK               0x00000080U
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define SWREG_MAIN_MAIN1__TARGETISDUMPCHARGE_SH__RESET_VALUE        0x00000000U
/** @} */

/* macros for field chargeStoreLimit_SH */
/**
 * @defgroup swreg_main_regs_core_chargeStoreLimit_SH_field chargeStoreLimit_SH_field
 * @brief macros for field chargeStoreLimit_SH
 * @details max number of charging cycles from battery or harvest to store per RTC period. 6'd63 is interpreted as no limit.
 * @{
 */
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__SHIFT                          8
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__WIDTH                          6
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__MASK                 0x00003f00U
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))
#define SWREG_MAIN_MAIN1__CHARGESTORELIMIT_SH__RESET_VALUE          0x0000003fU
/** @} */

/* macros for field chargeBattLimit_SH */
/**
 * @defgroup swreg_main_regs_core_chargeBattLimit_SH_field chargeBattLimit_SH_field
 * @brief macros for field chargeBattLimit_SH
 * @details max number of charging cycles from store or battery per RTC period. 6'd63 is interpreted as no limit.
 * @{
 */
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__SHIFT                          14
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__WIDTH                           6
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__MASK                  0x000fc000U
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000fc000U) >> 14)
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x000fc000U)
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fc000U) | (((uint32_t)(src) <<\
                    14) & 0x000fc000U)
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x000fc000U)))
#define SWREG_MAIN_MAIN1__CHARGEBATTLIMIT_SH__RESET_VALUE           0x0000003fU
/** @} */

/* macros for field timeMax_SH */
/**
 * @defgroup swreg_main_regs_core_timeMax_SH_field timeMax_SH_field
 * @brief macros for field timeMax_SH
 * @details The max energize or dump time allowed for zero gear (x2+1)
 * @{
 */
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__SHIFT                                  20
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__WIDTH                                   7
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__MASK                          0x07f00000U
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07f00000U) >> 20)
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x07f00000U)
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07f00000U) | (((uint32_t)(src) <<\
                    20) & 0x07f00000U)
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x07f00000U)))
#define SWREG_MAIN_MAIN1__TIMEMAX_SH__RESET_VALUE                   0x0000007fU
/** @} */

/* macros for field gearMax_vstore_SH */
/**
 * @defgroup swreg_main_regs_core_gearMax_vstore_SH_field gearMax_vstore_SH_field
 * @brief macros for field gearMax_vstore_SH
 * @details max gear when the destination is store
 * @{
 */
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__SHIFT                           27
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__WIDTH                            4
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__MASK                   0x78000000U
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x78000000U) >> 27)
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x78000000U)
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x78000000U) | (((uint32_t)(src) <<\
                    27) & 0x78000000U)
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x78000000U)))
#define SWREG_MAIN_MAIN1__GEARMAX_VSTORE_SH__RESET_VALUE            0x0000000fU
/** @} */
#define SWREG_MAIN_MAIN1__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN1__READ                                      0x7fffffffU
#define SWREG_MAIN_MAIN1__WRITE                                     0x7fffffffU
#define SWREG_MAIN_MAIN1__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN1__RESET_VALUE                               0x7fffff1eU

#endif /* __SWREG_MAIN_MAIN1_MACRO__ */

/** @} end of main1 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main2 */
/**
 * @defgroup swreg_main_regs_core_main2 main2
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN2_MACRO__
#define __SWREG_MAIN_MAIN2_MACRO__

/* macros for field gearUpMax_vstore_SH */
/**
 * @defgroup swreg_main_regs_core_gearUpMax_vstore_SH_field gearUpMax_vstore_SH_field
 * @brief macros for field gearUpMax_vstore_SH
 * @details max gear up when the destination is store
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__SHIFT                          0
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__WIDTH                          4
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__MASK                 0x0000000fU
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define SWREG_MAIN_MAIN2__GEARUPMAX_VSTORE_SH__RESET_VALUE          0x00000006U
/** @} */

/* macros for field gearMax_avdd_SH */
/**
 * @defgroup swreg_main_regs_core_gearMax_avdd_SH_field gearMax_avdd_SH_field
 * @brief macros for field gearMax_avdd_SH
 * @details max gear when the destination is avdd
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__SHIFT                              4
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__WIDTH                              4
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__MASK                     0x000000f0U
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define SWREG_MAIN_MAIN2__GEARMAX_AVDD_SH__RESET_VALUE              0x0000000fU
/** @} */

/* macros for field gearUpMax_avdd_SH */
/**
 * @defgroup swreg_main_regs_core_gearUpMax_avdd_SH_field gearUpMax_avdd_SH_field
 * @brief macros for field gearUpMax_avdd_SH
 * @details max gear up when the destination is avdd
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__SHIFT                            8
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__WIDTH                            4
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__MASK                   0x00000f00U
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define SWREG_MAIN_MAIN2__GEARUPMAX_AVDD_SH__RESET_VALUE            0x00000006U
/** @} */

/* macros for field gearMax_vddio_SH */
/**
 * @defgroup swreg_main_regs_core_gearMax_vddio_SH_field gearMax_vddio_SH_field
 * @brief macros for field gearMax_vddio_SH
 * @details max gear when the destination is vddio
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__SHIFT                            12
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__WIDTH                             4
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__MASK                    0x0000f000U
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define SWREG_MAIN_MAIN2__GEARMAX_VDDIO_SH__RESET_VALUE             0x0000000fU
/** @} */

/* macros for field gearUpMax_vddio_SH */
/**
 * @defgroup swreg_main_regs_core_gearUpMax_vddio_SH_field gearUpMax_vddio_SH_field
 * @brief macros for field gearUpMax_vddio_SH
 * @details max gear up when the destination is vddio
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__SHIFT                          16
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__WIDTH                           4
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__MASK                  0x000f0000U
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define SWREG_MAIN_MAIN2__GEARUPMAX_VDDIO_SH__RESET_VALUE           0x00000006U
/** @} */

/* macros for field gearMax_vaux_SH */
/**
 * @defgroup swreg_main_regs_core_gearMax_vaux_SH_field gearMax_vaux_SH_field
 * @brief macros for field gearMax_vaux_SH
 * @details max gear when the destination is vaux
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__SHIFT                             20
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__WIDTH                              4
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__MASK                     0x00f00000U
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define SWREG_MAIN_MAIN2__GEARMAX_VAUX_SH__RESET_VALUE              0x0000000fU
/** @} */

/* macros for field gearUpMax_vaux_SH */
/**
 * @defgroup swreg_main_regs_core_gearUpMax_vaux_SH_field gearUpMax_vaux_SH_field
 * @brief macros for field gearUpMax_vaux_SH
 * @details max gear up when the destination is vaux
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__SHIFT                           24
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__WIDTH                            4
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__MASK                   0x0f000000U
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define SWREG_MAIN_MAIN2__GEARUPMAX_VAUX_SH__RESET_VALUE            0x00000006U
/** @} */

/* macros for field gearMax_dvdd_SH */
/**
 * @defgroup swreg_main_regs_core_gearMax_dvdd_SH_field gearMax_dvdd_SH_field
 * @brief macros for field gearMax_dvdd_SH
 * @details max gear when the destination is dvdd
 * @{
 */
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__SHIFT                             28
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__WIDTH                              4
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__MASK                     0xf0000000U
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define SWREG_MAIN_MAIN2__GEARMAX_DVDD_SH__RESET_VALUE              0x0000000fU
/** @} */
#define SWREG_MAIN_MAIN2__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN2__READ                                      0xffffffffU
#define SWREG_MAIN_MAIN2__WRITE                                     0xffffffffU
#define SWREG_MAIN_MAIN2__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN2__RESET_VALUE                               0xf6f6f6f6U

#endif /* __SWREG_MAIN_MAIN2_MACRO__ */

/** @} end of main2 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main3 */
/**
 * @defgroup swreg_main_regs_core_main3 main3
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN3_MACRO__
#define __SWREG_MAIN_MAIN3_MACRO__

/* macros for field gearUpMax_dvdd_SH */
/**
 * @defgroup swreg_main_regs_core_gearUpMax_dvdd_SH_field gearUpMax_dvdd_SH_field
 * @brief macros for field gearUpMax_dvdd_SH
 * @details max gear up when the destination is dvdd
 * @{
 */
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__SHIFT                            0
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__WIDTH                            4
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__MASK                   0x0000000fU
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define SWREG_MAIN_MAIN3__GEARUPMAX_DVDD_SH__RESET_VALUE            0x00000006U
/** @} */

/* macros for field gearIncrThrToDecr_SH */
/**
 * @defgroup swreg_main_regs_core_gearIncrThrToDecr_SH_field gearIncrThrToDecr_SH_field
 * @brief macros for field gearIncrThrToDecr_SH
 * @details after so many gear sucessive increases it will attemp a decrease
 * @{
 */
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__SHIFT                         4
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__WIDTH                         2
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__MASK                0x00000030U
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define SWREG_MAIN_MAIN3__GEARINCRTHRTODECR_SH__RESET_VALUE         0x00000002U
/** @} */

/* macros for field gearIncrAdditional_SH */
/**
 * @defgroup swreg_main_regs_core_gearIncrAdditional_SH_field gearIncrAdditional_SH_field
 * @brief macros for field gearIncrAdditional_SH
 * @details additional gear increase after decrease and bouncing back up
 * @{
 */
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__SHIFT                        6
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__WIDTH                        2
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__MASK               0x000000c0U
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define SWREG_MAIN_MAIN3__GEARINCRADDITIONAL_SH__RESET_VALUE        0x00000000U
/** @} */

/* macros for field disableFastGearDecr_SH */
/**
 * @defgroup swreg_main_regs_core_disableFastGearDecr_SH_field disableFastGearDecr_SH_field
 * @brief macros for field disableFastGearDecr_SH
 * @details disable fast gear decrease
 * @{
 */
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__SHIFT                       8
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__WIDTH                       1
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__MASK              0x00000100U
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define SWREG_MAIN_MAIN3__DISABLEFASTGEARDECR_SH__RESET_VALUE       0x00000000U
/** @} */

/* macros for field rtcCountMax_SH */
/**
 * @defgroup swreg_main_regs_core_rtcCountMax_SH_field rtcCountMax_SH_field
 * @brief macros for field rtcCountMax_SH
 * @details when disableFastGearDecr_SH=1, all gears are decreased by 1 every 4*(rtcCountMax_SH+1) rtc clock periods.the rtc clock period is 32KHz divided by (divCk32+1). 7 with divCk32=0 provides ~1 ms intervals.
 * @{
 */
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__SHIFT                               9
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__WIDTH                               4
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__MASK                      0x00001e00U
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00001e00U)
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001e00U) | (((uint32_t)(src) <<\
                    9) & 0x00001e00U)
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00001e00U)))
#define SWREG_MAIN_MAIN3__RTCCOUNTMAX_SH__RESET_VALUE               0x00000007U
/** @} */

/* macros for field historyPeriods_SH */
/**
 * @defgroup swreg_main_regs_core_historyPeriods_SH_field historyPeriods_SH_field
 * @brief macros for field historyPeriods_SH
 * @details The sum of switching events (freqCountSum) per destination is counted for historyPeriods_SH periods of the RTC clock. Max valid value is 4. freqCountSum is used for frequency hoping and fast gear decrease.
 * @{
 */
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__SHIFT                           13
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__WIDTH                            3
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__MASK                   0x0000e000U
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define SWREG_MAIN_MAIN3__HISTORYPERIODS_SH__RESET_VALUE            0x00000003U
/** @} */

/* macros for field hopEnable_SH */
/**
 * @defgroup swreg_main_regs_core_hopEnable_SH_field hopEnable_SH_field
 * @brief macros for field hopEnable_SH
 * @details enable frequency hopping
 * @{
 */
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__SHIFT                                16
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__WIDTH                                 1
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__MASK                        0x00010000U
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define SWREG_MAIN_MAIN3__HOPENABLE_SH__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field hopConditionRepeat_SH */
/**
 * @defgroup swreg_main_regs_core_hopConditionRepeat_SH_field hopConditionRepeat_SH_field
 * @brief macros for field hopConditionRepeat_SH
 * @details the condition [abs(freqcountsum - freqcountsumtoavoid) <= hopFreqCountTol] has to be met for so many successive RTC clock periods to trigger frequency hopping
 * @{
 */
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__SHIFT                       17
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__WIDTH                        3
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__MASK               0x000e0000U
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000e0000U) >> 17)
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x000e0000U)
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000e0000U) | (((uint32_t)(src) <<\
                    17) & 0x000e0000U)
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x000e0000U)))
#define SWREG_MAIN_MAIN3__HOPCONDITIONREPEAT_SH__RESET_VALUE        0x00000004U
/** @} */

/* macros for field hopGearMaxIncr_SH */
/**
 * @defgroup swreg_main_regs_core_hopGearMaxIncr_SH_field hopGearMaxIncr_SH_field
 * @brief macros for field hopGearMaxIncr_SH
 * @details if the gear increases so many times after the frequency has hopped, it exits frequency hopping
 * @{
 */
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__SHIFT                           20
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__WIDTH                            2
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__MASK                   0x00300000U
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define SWREG_MAIN_MAIN3__HOPGEARMAXINCR_SH__RESET_VALUE            0x00000002U
/** @} */

/* macros for field freqCountSumToAvoid_0_SH */
/**
 * @defgroup swreg_main_regs_core_freqCountSumToAvoid_0_SH_field freqCountSumToAvoid_0_SH_field
 * @brief macros for field freqCountSumToAvoid_0_SH
 * @details freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__SHIFT                    22
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__WIDTH                     8
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__MASK            0x3fc00000U
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3fc00000U) >> 22)
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x3fc00000U)
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3fc00000U) | (((uint32_t)(src) <<\
                    22) & 0x3fc00000U)
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x3fc00000U)))
#define SWREG_MAIN_MAIN3__FREQCOUNTSUMTOAVOID_0_SH__RESET_VALUE     0x00000000U
/** @} */
#define SWREG_MAIN_MAIN3__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN3__READ                                      0x3fffffffU
#define SWREG_MAIN_MAIN3__WRITE                                     0x3fffffffU
#define SWREG_MAIN_MAIN3__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN3__RESET_VALUE                               0x00286e26U

#endif /* __SWREG_MAIN_MAIN3_MACRO__ */

/** @} end of main3 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main4 */
/**
 * @defgroup swreg_main_regs_core_main4 main4
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN4_MACRO__
#define __SWREG_MAIN_MAIN4_MACRO__

/* macros for field freqCountSumToAvoid_1_SH */
/**
 * @defgroup swreg_main_regs_core_freqCountSumToAvoid_1_SH_field freqCountSumToAvoid_1_SH_field
 * @brief macros for field freqCountSumToAvoid_1_SH
 * @details freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__SHIFT                     0
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__WIDTH                     8
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__MASK            0x000000ffU
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_1_SH__RESET_VALUE     0x00000000U
/** @} */

/* macros for field freqCountSumToAvoid_2_SH */
/**
 * @defgroup swreg_main_regs_core_freqCountSumToAvoid_2_SH_field freqCountSumToAvoid_2_SH_field
 * @brief macros for field freqCountSumToAvoid_2_SH
 * @details freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__SHIFT                     8
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__WIDTH                     8
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__MASK            0x0000ff00U
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define SWREG_MAIN_MAIN4__FREQCOUNTSUMTOAVOID_2_SH__RESET_VALUE     0x00000000U
/** @} */

/* macros for field hopFreqCountTol_0_SH */
/**
 * @defgroup swreg_main_regs_core_hopFreqCountTol_0_SH_field hopFreqCountTol_0_SH_field
 * @brief macros for field hopFreqCountTol_0_SH
 * @details tolerance in freqCountSum to trigger frequency hopping
 * @{
 */
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__SHIFT                        16
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__WIDTH                         3
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__MASK                0x00070000U
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_0_SH__RESET_VALUE         0x00000002U
/** @} */

/* macros for field hopFreqCountTol_1_SH */
/**
 * @defgroup swreg_main_regs_core_hopFreqCountTol_1_SH_field hopFreqCountTol_1_SH_field
 * @brief macros for field hopFreqCountTol_1_SH
 * @details tolerance in freqCountSum to trigger frequency hopping
 * @{
 */
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__SHIFT                        19
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__WIDTH                         3
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__MASK                0x00380000U
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00380000U) >> 19)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00380000U)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_1_SH__RESET_VALUE         0x00000002U
/** @} */

/* macros for field hopFreqCountTol_2_SH */
/**
 * @defgroup swreg_main_regs_core_hopFreqCountTol_2_SH_field hopFreqCountTol_2_SH_field
 * @brief macros for field hopFreqCountTol_2_SH
 * @details tolerance in freqCountSum to trigger frequency hopping
 * @{
 */
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__SHIFT                        22
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__WIDTH                         3
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__MASK                0x01c00000U
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01c00000U) >> 22)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x01c00000U)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01c00000U) | (((uint32_t)(src) <<\
                    22) & 0x01c00000U)
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x01c00000U)))
#define SWREG_MAIN_MAIN4__HOPFREQCOUNTTOL_2_SH__RESET_VALUE         0x00000002U
/** @} */

/* macros for field hopDestFreqMatrix_vstore_SH */
/**
 * @defgroup swreg_main_regs_core_hopDestFreqMatrix_vstore_SH_field hopDestFreqMatrix_vstore_SH_field
 * @brief macros for field hopDestFreqMatrix_vstore_SH
 * @details enable frequency hopping for store (or vddpa), and the three freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__SHIFT                 25
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__WIDTH                  3
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__MASK         0x0e000000U
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0e000000U) >> 25)
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x0e000000U)
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0e000000U) | (((uint32_t)(src) <<\
                    25) & 0x0e000000U)
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x0e000000U)))
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_VSTORE_SH__RESET_VALUE  0x00000000U
/** @} */

/* macros for field hopDestFreqMatrix_avdd_SH */
/**
 * @defgroup swreg_main_regs_core_hopDestFreqMatrix_avdd_SH_field hopDestFreqMatrix_avdd_SH_field
 * @brief macros for field hopDestFreqMatrix_avdd_SH
 * @details enable frequency hopping for avdd, and the three freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__SHIFT                   28
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__WIDTH                    3
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__MASK           0x70000000U
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x70000000U) >> 28)
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x70000000U)
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x70000000U) | (((uint32_t)(src) <<\
                    28) & 0x70000000U)
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x70000000U)))
#define SWREG_MAIN_MAIN4__HOPDESTFREQMATRIX_AVDD_SH__RESET_VALUE    0x00000000U
/** @} */
#define SWREG_MAIN_MAIN4__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN4__READ                                      0x7fffffffU
#define SWREG_MAIN_MAIN4__WRITE                                     0x7fffffffU
#define SWREG_MAIN_MAIN4__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN4__RESET_VALUE                               0x00920000U

#endif /* __SWREG_MAIN_MAIN4_MACRO__ */

/** @} end of main4 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main5 */
/**
 * @defgroup swreg_main_regs_core_main5 main5
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN5_MACRO__
#define __SWREG_MAIN_MAIN5_MACRO__

/* macros for field hopDestFreqMatrix_vddio_SH */
/**
 * @defgroup swreg_main_regs_core_hopDestFreqMatrix_vddio_SH_field hopDestFreqMatrix_vddio_SH_field
 * @brief macros for field hopDestFreqMatrix_vddio_SH
 * @details enable frequency hopping for vddio, and the three freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__SHIFT                   0
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__WIDTH                   3
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__MASK          0x00000007U
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VDDIO_SH__RESET_VALUE   0x00000000U
/** @} */

/* macros for field hopDestFreqMatrix_vaux_SH */
/**
 * @defgroup swreg_main_regs_core_hopDestFreqMatrix_vaux_SH_field hopDestFreqMatrix_vaux_SH_field
 * @brief macros for field hopDestFreqMatrix_vaux_SH
 * @details enable frequency hopping for vaux, and the three freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__SHIFT                    3
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__WIDTH                    3
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__MASK           0x00000038U
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_VAUX_SH__RESET_VALUE    0x00000000U
/** @} */

/* macros for field hopDestFreqMatrix_dvdd_SH */
/**
 * @defgroup swreg_main_regs_core_hopDestFreqMatrix_dvdd_SH_field hopDestFreqMatrix_dvdd_SH_field
 * @brief macros for field hopDestFreqMatrix_dvdd_SH
 * @details enable frequency hopping for dvdd, and the three freqCountSum to avoid
 * @{
 */
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__SHIFT                    6
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__WIDTH                    3
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__MASK           0x000001c0U
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define SWREG_MAIN_MAIN5__HOPDESTFREQMATRIX_DVDD_SH__RESET_VALUE    0x00000000U
/** @} */

/* macros for field hopJumpTime_vstore_SH */
/**
 * @defgroup swreg_main_regs_core_hopJumpTime_vstore_SH_field hopJumpTime_vstore_SH_field
 * @brief macros for field hopJumpTime_vstore_SH
 * @details when frequency hopping for store is activated, the target dump time increases by this number (x2)
 * @{
 */
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__SHIFT                        9
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__WIDTH                        6
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__MASK               0x00007e00U
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007e00U) >> 9)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00007e00U)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007e00U) | (((uint32_t)(src) <<\
                    9) & 0x00007e00U)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00007e00U)))
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VSTORE_SH__RESET_VALUE        0x00000004U
/** @} */

/* macros for field hopJumpTime_avdd_SH */
/**
 * @defgroup swreg_main_regs_core_hopJumpTime_avdd_SH_field hopJumpTime_avdd_SH_field
 * @brief macros for field hopJumpTime_avdd_SH
 * @details when frequency hopping for avdd is activated, the target dump time increases by this number (x2)
 * @{
 */
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__SHIFT                         15
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__WIDTH                          6
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__MASK                 0x001f8000U
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f8000U) >> 15)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x001f8000U)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f8000U) | (((uint32_t)(src) <<\
                    15) & 0x001f8000U)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x001f8000U)))
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_AVDD_SH__RESET_VALUE          0x00000004U
/** @} */

/* macros for field hopJumpTime_vddio_SH */
/**
 * @defgroup swreg_main_regs_core_hopJumpTime_vddio_SH_field hopJumpTime_vddio_SH_field
 * @brief macros for field hopJumpTime_vddio_SH
 * @details when frequency hopping for vddio is activated, the target dump time increases by this number (x2)
 * @{
 */
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__SHIFT                        21
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__WIDTH                         6
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__MASK                0x07e00000U
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07e00000U) >> 21)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x07e00000U)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07e00000U) | (((uint32_t)(src) <<\
                    21) & 0x07e00000U)
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x07e00000U)))
#define SWREG_MAIN_MAIN5__HOPJUMPTIME_VDDIO_SH__RESET_VALUE         0x00000004U
/** @} */
#define SWREG_MAIN_MAIN5__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN5__READ                                      0x07ffffffU
#define SWREG_MAIN_MAIN5__WRITE                                     0x07ffffffU
#define SWREG_MAIN_MAIN5__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN5__RESET_VALUE                               0x00820800U

#endif /* __SWREG_MAIN_MAIN5_MACRO__ */

/** @} end of main5 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main6 */
/**
 * @defgroup swreg_main_regs_core_main6 main6
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN6_MACRO__
#define __SWREG_MAIN_MAIN6_MACRO__

/* macros for field hopJumpTime_vaux_SH */
/**
 * @defgroup swreg_main_regs_core_hopJumpTime_vaux_SH_field hopJumpTime_vaux_SH_field
 * @brief macros for field hopJumpTime_vaux_SH
 * @details when frequency hopping for vaux is activated, the target dump time increases by this number (x2)
 * @{
 */
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__SHIFT                          0
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__WIDTH                          6
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__MASK                 0x0000003fU
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_VAUX_SH__RESET_VALUE          0x00000004U
/** @} */

/* macros for field hopJumpTime_dvdd_SH */
/**
 * @defgroup swreg_main_regs_core_hopJumpTime_dvdd_SH_field hopJumpTime_dvdd_SH_field
 * @brief macros for field hopJumpTime_dvdd_SH
 * @details when frequency hopping for dvdd is activated, the target dump time increases by this number (x2)
 * @{
 */
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__SHIFT                          6
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__WIDTH                          6
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__MASK                 0x00000fc0U
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define SWREG_MAIN_MAIN6__HOPJUMPTIME_DVDD_SH__RESET_VALUE          0x00000004U
/** @} */

/* macros for field legacyStart */
/**
 * @defgroup swreg_main_regs_core_legacyStart_field legacyStart_field
 * @brief macros for field legacyStart
 * @details legacy start with constant energize time before supply is ready //start
 * @{
 */
#define SWREG_MAIN_MAIN6__LEGACYSTART__SHIFT                                 12
#define SWREG_MAIN_MAIN6__LEGACYSTART__WIDTH                                  1
#define SWREG_MAIN_MAIN6__LEGACYSTART__MASK                         0x00001000U
#define SWREG_MAIN_MAIN6__LEGACYSTART__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define SWREG_MAIN_MAIN6__LEGACYSTART__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define SWREG_MAIN_MAIN6__LEGACYSTART__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define SWREG_MAIN_MAIN6__LEGACYSTART__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define SWREG_MAIN_MAIN6__LEGACYSTART__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define SWREG_MAIN_MAIN6__LEGACYSTART__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define SWREG_MAIN_MAIN6__LEGACYSTART__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field loadRegMain */
/**
 * @defgroup swreg_main_regs_core_loadRegMain_field loadRegMain_field
 * @brief macros for field loadRegMain
 * @details load the Main shadow register
 * @{
 */
#define SWREG_MAIN_MAIN6__LOADREGMAIN__SHIFT                                 13
#define SWREG_MAIN_MAIN6__LOADREGMAIN__WIDTH                                  1
#define SWREG_MAIN_MAIN6__LOADREGMAIN__MASK                         0x00002000U
#define SWREG_MAIN_MAIN6__LOADREGMAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define SWREG_MAIN_MAIN6__LOADREGMAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define SWREG_MAIN_MAIN6__LOADREGMAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define SWREG_MAIN_MAIN6__LOADREGMAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define SWREG_MAIN_MAIN6__LOADREGMAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define SWREG_MAIN_MAIN6__LOADREGMAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define SWREG_MAIN_MAIN6__LOADREGMAIN__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field divCk32 */
/**
 * @defgroup swreg_main_regs_core_divCk32_field divCk32_field
 * @brief macros for field divCk32
 * @details divide the 32KHz clock by (divCk32+1). Zero means no division
 * @{
 */
#define SWREG_MAIN_MAIN6__DIVCK32__SHIFT                                     14
#define SWREG_MAIN_MAIN6__DIVCK32__WIDTH                                      3
#define SWREG_MAIN_MAIN6__DIVCK32__MASK                             0x0001c000U
#define SWREG_MAIN_MAIN6__DIVCK32__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define SWREG_MAIN_MAIN6__DIVCK32__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define SWREG_MAIN_MAIN6__DIVCK32__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define SWREG_MAIN_MAIN6__DIVCK32__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define SWREG_MAIN_MAIN6__DIVCK32__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field divCk32Mppt */
/**
 * @defgroup swreg_main_regs_core_divCk32Mppt_field divCk32Mppt_field
 * @brief macros for field divCk32Mppt
 * @details divide the 32KHz clock by (divCk32Mppt+1) for mppt purposes. Zero means no division
 * @{
 */
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__SHIFT                                 17
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__WIDTH                                  5
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__MASK                         0x003e0000U
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003e0000U) >> 17)
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x003e0000U)
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003e0000U) | (((uint32_t)(src) <<\
                    17) & 0x003e0000U)
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x003e0000U)))
#define SWREG_MAIN_MAIN6__DIVCK32MPPT__RESET_VALUE                  0x00000007U
/** @} */

/* macros for field scaleEnerg_ovr */
/**
 * @defgroup swreg_main_regs_core_scaleEnerg_ovr_field scaleEnerg_ovr_field
 * @brief macros for field scaleEnerg_ovr
 * @details override scaling of energize time
 * @{
 */
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__SHIFT                              22
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__WIDTH                               1
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__MASK                      0x00400000U
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field scaleEnerg_ovrVal */
/**
 * @defgroup swreg_main_regs_core_scaleEnerg_ovrVal_field scaleEnerg_ovrVal_field
 * @brief macros for field scaleEnerg_ovrVal
 * @details override value for scaling of energize time, 3 bits for each source: setting of (0:7) corresponds to scaling of (1, 1.125, 1.375, 1.625, 2, 3, 4, 8)
 * @{
 */
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__SHIFT                           23
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__WIDTH                            9
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__MASK                   0xff800000U
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff800000U) >> 23)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0xff800000U)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff800000U) | (((uint32_t)(src) <<\
                    23) & 0xff800000U)
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0xff800000U)))
#define SWREG_MAIN_MAIN6__SCALEENERG_OVRVAL__RESET_VALUE            0x00000000U
/** @} */
#define SWREG_MAIN_MAIN6__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN6__READ                                      0xffffffffU
#define SWREG_MAIN_MAIN6__WRITE                                     0xffffffffU
#define SWREG_MAIN_MAIN6__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN6__RESET_VALUE                               0x000e0104U

#endif /* __SWREG_MAIN_MAIN6_MACRO__ */

/** @} end of main6 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main7 */
/**
 * @defgroup swreg_main_regs_core_main7 main7
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN7_MACRO__
#define __SWREG_MAIN_MAIN7_MACRO__

/* macros for field enableHarv2Sup_ovr */
/**
 * @defgroup swreg_main_regs_core_enableHarv2Sup_ovr_field enableHarv2Sup_ovr_field
 * @brief macros for field enableHarv2Sup_ovr
 * @details override enable for harvest to supplies modes
 * @{
 */
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__SHIFT                           0
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__WIDTH                           1
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__MASK                  0x00000001U
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVR__RESET_VALUE           0x00000000U
/** @} */

/* macros for field enableHarv2Sup_ovrVal */
/**
 * @defgroup swreg_main_regs_core_enableHarv2Sup_ovrVal_field enableHarv2Sup_ovrVal_field
 * @brief macros for field enableHarv2Sup_ovrVal
 * @details override value of the enable for harvest to supplies modes
 * @{
 */
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__SHIFT                        1
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__WIDTH                        1
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__MASK               0x00000002U
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWREG_MAIN_MAIN7__ENABLEHARV2SUP_OVRVAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field fixHarvEnerg_ovr */
/**
 * @defgroup swreg_main_regs_core_fixHarvEnerg_ovr_field fixHarvEnerg_ovr_field
 * @brief macros for field fixHarvEnerg_ovr
 * @details override fixing the energize time (fixHarvEnerg) for all destinations when the source is the harvester if fixHarvEnerg=1 the target for the harvest to supply modes is the energize time, otherwise it is the dump time if set, timeTargetHarv2Store_SH is used as the energize time
 * @{
 */
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__SHIFT                             2
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__WIDTH                             1
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__MASK                    0x00000004U
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field fixHarvEnerg_ovrVal */
/**
 * @defgroup swreg_main_regs_core_fixHarvEnerg_ovrVal_field fixHarvEnerg_ovrVal_field
 * @brief macros for field fixHarvEnerg_ovrVal
 * @details override value for fixing the energize time for all destinations when the source is the harvester
 * @{
 */
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__SHIFT                          3
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__WIDTH                          1
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__MASK                 0x00000008U
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SWREG_MAIN_MAIN7__FIXHARVENERG_OVRVAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field discardCanHarvest */
/**
 * @defgroup swreg_main_regs_core_discardCanHarvest_field discardCanHarvest_field
 * @brief macros for field discardCanHarvest
 * @details Discard the canHarvest comparator output and use mustHarvest instead
 * @{
 */
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__SHIFT                            4
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__WIDTH                            1
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__MASK                   0x00000010U
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define SWREG_MAIN_MAIN7__DISCARDCANHARVEST__RESET_VALUE            0x00000000U
/** @} */

/* macros for field buckBoost_ovr */
/**
 * @defgroup swreg_main_regs_core_buckBoost_ovr_field buckBoost_ovr_field
 * @brief macros for field buckBoost_ovr
 * @details override the buck or boost mode
 * @{
 */
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__SHIFT                                5
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__WIDTH                               15
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__MASK                       0x000fffe0U
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000fffe0U) >> 5)
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000fffe0U)
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffe0U) | (((uint32_t)(src) <<\
                    5) & 0x000fffe0U)
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000fffe0U)))
#define SWREG_MAIN_MAIN7__BUCKBOOST_OVR__RESET_VALUE                0x00000000U
/** @} */
#define SWREG_MAIN_MAIN7__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN7__READ                                      0x000fffffU
#define SWREG_MAIN_MAIN7__WRITE                                     0x000fffffU
#define SWREG_MAIN_MAIN7__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN7__RESET_VALUE                               0x00000000U

#endif /* __SWREG_MAIN_MAIN7_MACRO__ */

/** @} end of main7 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main8 */
/**
 * @defgroup swreg_main_regs_core_main8 main8
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN8_MACRO__
#define __SWREG_MAIN_MAIN8_MACRO__

/* macros for field buck_ovrVal */
/**
 * @defgroup swreg_main_regs_core_buck_ovrVal_field buck_ovrVal_field
 * @brief macros for field buck_ovrVal
 * @details if set when the corresponding buckBoost_ovr bit is one, buck mode will be used for this power transfer mode
 * @{
 */
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__SHIFT                                  0
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__WIDTH                                 15
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__MASK                         0x00007fffU
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00007fffU)
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00007fffU)
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007fffU) | ((uint32_t)(src) &\
                    0x00007fffU)
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00007fffU)))
#define SWREG_MAIN_MAIN8__BUCK_OVRVAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field boost_ovrVal */
/**
 * @defgroup swreg_main_regs_core_boost_ovrVal_field boost_ovrVal_field
 * @brief macros for field boost_ovrVal
 * @details if set when the corresponding buckBoost_ovr bit is one and buck_ovrVal is zero, boost mode will be used for this power transfer mode.if both buck_ovrVal and boost_ovrVal are zero buck-boost mode will be used.
 * @{
 */
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__SHIFT                                15
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__WIDTH                                15
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__MASK                        0x3fff8000U
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3fff8000U) >> 15)
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x3fff8000U)
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3fff8000U) | (((uint32_t)(src) <<\
                    15) & 0x3fff8000U)
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x3fff8000U)))
#define SWREG_MAIN_MAIN8__BOOST_OVRVAL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field readyForTinyLevel */
/**
 * @defgroup swreg_main_regs_core_readyForTinyLevel_field readyForTinyLevel_field
 * @brief macros for field readyForTinyLevel
 * @details transition to the tiny FSM is delayed until the main FSM has settled according to this setting:0: no wait1: wait until all enabled supplies are ready2: wait until all enabled supplies are ready and the targets have settled3: wait until all enabled supplies have fully settled
 * @{
 */
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__SHIFT                           30
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__WIDTH                            2
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__MASK                   0xc0000000U
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define SWREG_MAIN_MAIN8__READYFORTINYLEVEL__RESET_VALUE            0x00000002U
/** @} */
#define SWREG_MAIN_MAIN8__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN8__READ                                      0xffffffffU
#define SWREG_MAIN_MAIN8__WRITE                                     0xffffffffU
#define SWREG_MAIN_MAIN8__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN8__RESET_VALUE                               0x80000000U

#endif /* __SWREG_MAIN_MAIN8_MACRO__ */

/** @} end of main8 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main9 */
/**
 * @defgroup swreg_main_regs_core_main9 main9
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN9_MACRO__
#define __SWREG_MAIN_MAIN9_MACRO__

/* macros for field chargeStore_ovr */
/**
 * @defgroup swreg_main_regs_core_chargeStore_ovr_field chargeStore_ovr_field
 * @brief macros for field chargeStore_ovr
 * @details override enable for charging store from the battery
 * @{
 */
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__SHIFT                              0
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__WIDTH                              1
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__MASK                     0x00000001U
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field chargeStore_ovrVal */
/**
 * @defgroup swreg_main_regs_core_chargeStore_ovrVal_field chargeStore_ovrVal_field
 * @brief macros for field chargeStore_ovrVal
 * @details override value of the enable for charging store from the battery
 * @{
 */
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__SHIFT                           1
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__WIDTH                           1
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__MASK                  0x00000002U
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWREG_MAIN_MAIN9__CHARGESTORE_OVRVAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field chargeBatt_ovr */
/**
 * @defgroup swreg_main_regs_core_chargeBatt_ovr_field chargeBatt_ovr_field
 * @brief macros for field chargeBatt_ovr
 * @details override enable for charging battery from the store
 * @{
 */
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__SHIFT                               2
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__WIDTH                               1
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__MASK                      0x00000004U
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field chargeBatt_ovrVal */
/**
 * @defgroup swreg_main_regs_core_chargeBatt_ovrVal_field chargeBatt_ovrVal_field
 * @brief macros for field chargeBatt_ovrVal
 * @details override value of the enable for charging battery from the store
 * @{
 */
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__SHIFT                            3
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__WIDTH                            1
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__MASK                   0x00000008U
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SWREG_MAIN_MAIN9__CHARGEBATT_OVRVAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field storeIsSup_ovr */
/**
 * @defgroup swreg_main_regs_core_storeIsSup_ovr_field storeIsSup_ovr_field
 * @brief macros for field storeIsSup_ovr
 * @details override storeIsSup, which repurposes store to be a the PA supply (vddpa)
 * @{
 */
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__SHIFT                               4
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__WIDTH                               1
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__MASK                      0x00000010U
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field storeIsSup_ovrVal */
/**
 * @defgroup swreg_main_regs_core_storeIsSup_ovrVal_field storeIsSup_ovrVal_field
 * @brief macros for field storeIsSup_ovrVal
 * @details override value of storeIsSup
 * @{
 */
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__SHIFT                            5
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__WIDTH                            1
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__MASK                   0x00000020U
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define SWREG_MAIN_MAIN9__STOREISSUP_OVRVAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field mppt_ovr */
/**
 * @defgroup swreg_main_regs_core_mppt_ovr_field mppt_ovr_field
 * @brief macros for field mppt_ovr
 * @details override mppt controls
 * @{
 */
#define SWREG_MAIN_MAIN9__MPPT_OVR__SHIFT                                     6
#define SWREG_MAIN_MAIN9__MPPT_OVR__WIDTH                                     1
#define SWREG_MAIN_MAIN9__MPPT_OVR__MASK                            0x00000040U
#define SWREG_MAIN_MAIN9__MPPT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define SWREG_MAIN_MAIN9__MPPT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define SWREG_MAIN_MAIN9__MPPT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define SWREG_MAIN_MAIN9__MPPT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define SWREG_MAIN_MAIN9__MPPT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define SWREG_MAIN_MAIN9__MPPT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define SWREG_MAIN_MAIN9__MPPT_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field mpptStart_ovrVal */
/**
 * @defgroup swreg_main_regs_core_mpptStart_ovrVal_field mpptStart_ovrVal_field
 * @brief macros for field mpptStart_ovrVal
 * @details start mppt measurement in override mode. Needs to stay high until mpptDone becomes 1.
 * @{
 */
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__SHIFT                             7
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__WIDTH                             1
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__MASK                    0x00000080U
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define SWREG_MAIN_MAIN9__MPPTSTART_OVRVAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field mpptTargetIsPeriods_ovrVal */
/**
 * @defgroup swreg_main_regs_core_mpptTargetIsPeriods_ovrVal_field mpptTargetIsPeriods_ovrVal_field
 * @brief macros for field mpptTargetIsPeriods_ovrVal
 * @details if 1 the target number of periods, otherwise it is number of events in mppt override mode
 * @{
 */
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__SHIFT                   8
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__WIDTH                   1
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__MASK          0x00000100U
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define SWREG_MAIN_MAIN9__MPPTTARGETISPERIODS_OVRVAL__RESET_VALUE   0x00000000U
/** @} */

/* macros for field mpptPeriodsTarget_ovrVal */
/**
 * @defgroup swreg_main_regs_core_mpptPeriodsTarget_ovrVal_field mpptPeriodsTarget_ovrVal_field
 * @brief macros for field mpptPeriodsTarget_ovrVal
 * @details the target number of rtc clock periods in mppt override mode
 * @{
 */
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__SHIFT                     9
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__WIDTH                     9
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__MASK            0x0003fe00U
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))
#define SWREG_MAIN_MAIN9__MPPTPERIODSTARGET_OVRVAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field mpptEventsTarget_ovrVal */
/**
 * @defgroup swreg_main_regs_core_mpptEventsTarget_ovrVal_field mpptEventsTarget_ovrVal_field
 * @brief macros for field mpptEventsTarget_ovrVal
 * @details the target number of switching events in mppt override mode
 * @{
 */
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__SHIFT                     18
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__WIDTH                     10
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__MASK             0x0ffc0000U
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0ffc0000U) >> 18)
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x0ffc0000U)
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0ffc0000U) | (((uint32_t)(src) <<\
                    18) & 0x0ffc0000U)
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x0ffc0000U)))
#define SWREG_MAIN_MAIN9__MPPTEVENTSTARGET_OVRVAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ateSampleIndCurrent */
/**
 * @defgroup swreg_main_regs_core_ateSampleIndCurrent_field ateSampleIndCurrent_field
 * @brief macros for field ateSampleIndCurrent
 * @details sample inductor current sign in ate testing. To test the Zero Current Crossing comparator     Activate a mode with ateModeSel, ateBuck in dump configuration with ateDump=1. It can be buck-boost or buck, but not boost. Set ateSampleIndCurrent=1.    Apply a small positive/negative current to the source terminal of the inductor, which is grounded during dump.    Terminate the mode by setting ateModeSel=5'd18, which will make the current flow through the internal sense resistor   Read the indCurrentSign bit in the readout register, it should be 0/1
 * @{
 */
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__SHIFT                         28
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__WIDTH                          1
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__MASK                 0x10000000U
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define SWREG_MAIN_MAIN9__ATESAMPLEINDCURRENT__RESET_VALUE          0x00000000U
/** @} */

/* macros for field ateDump */
/**
 * @defgroup swreg_main_regs_core_ateDump_field ateDump_field
 * @brief macros for field ateDump
 * @details dump in ate testing
 * @{
 */
#define SWREG_MAIN_MAIN9__ATEDUMP__SHIFT                                     29
#define SWREG_MAIN_MAIN9__ATEDUMP__WIDTH                                      1
#define SWREG_MAIN_MAIN9__ATEDUMP__MASK                             0x20000000U
#define SWREG_MAIN_MAIN9__ATEDUMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define SWREG_MAIN_MAIN9__ATEDUMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define SWREG_MAIN_MAIN9__ATEDUMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define SWREG_MAIN_MAIN9__ATEDUMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define SWREG_MAIN_MAIN9__ATEDUMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define SWREG_MAIN_MAIN9__ATEDUMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define SWREG_MAIN_MAIN9__ATEDUMP__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field ateBoost */
/**
 * @defgroup swreg_main_regs_core_ateBoost_field ateBoost_field
 * @brief macros for field ateBoost
 * @details boost mode in ate testing
 * @{
 */
#define SWREG_MAIN_MAIN9__ATEBOOST__SHIFT                                    30
#define SWREG_MAIN_MAIN9__ATEBOOST__WIDTH                                     1
#define SWREG_MAIN_MAIN9__ATEBOOST__MASK                            0x40000000U
#define SWREG_MAIN_MAIN9__ATEBOOST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SWREG_MAIN_MAIN9__ATEBOOST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SWREG_MAIN_MAIN9__ATEBOOST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SWREG_MAIN_MAIN9__ATEBOOST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SWREG_MAIN_MAIN9__ATEBOOST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SWREG_MAIN_MAIN9__ATEBOOST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SWREG_MAIN_MAIN9__ATEBOOST__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field ateBuck */
/**
 * @defgroup swreg_main_regs_core_ateBuck_field ateBuck_field
 * @brief macros for field ateBuck
 * @details buck mode in ate testing
 * @{
 */
#define SWREG_MAIN_MAIN9__ATEBUCK__SHIFT                                     31
#define SWREG_MAIN_MAIN9__ATEBUCK__WIDTH                                      1
#define SWREG_MAIN_MAIN9__ATEBUCK__MASK                             0x80000000U
#define SWREG_MAIN_MAIN9__ATEBUCK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SWREG_MAIN_MAIN9__ATEBUCK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SWREG_MAIN_MAIN9__ATEBUCK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SWREG_MAIN_MAIN9__ATEBUCK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SWREG_MAIN_MAIN9__ATEBUCK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SWREG_MAIN_MAIN9__ATEBUCK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SWREG_MAIN_MAIN9__ATEBUCK__RESET_VALUE                      0x00000000U
/** @} */
#define SWREG_MAIN_MAIN9__TYPE                                         uint32_t
#define SWREG_MAIN_MAIN9__READ                                      0xffffffffU
#define SWREG_MAIN_MAIN9__WRITE                                     0xffffffffU
#define SWREG_MAIN_MAIN9__PRESERVED                                 0x00000000U
#define SWREG_MAIN_MAIN9__RESET_VALUE                               0x00000000U

#endif /* __SWREG_MAIN_MAIN9_MACRO__ */

/** @} end of main9 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_main10 */
/**
 * @defgroup swreg_main_regs_core_main10 main10
 * @brief main swreg registers definitions.
 * @{
 */
#ifndef __SWREG_MAIN_MAIN10_MACRO__
#define __SWREG_MAIN_MAIN10_MACRO__

/* macros for field ateModeSel */
/**
 * @defgroup swreg_main_regs_core_ateModeSel_field ateModeSel_field
 * @brief macros for field ateModeSel
 * @details the power transfer mode activated in ate testing
 * @{
 */
#define SWREG_MAIN_MAIN10__ATEMODESEL__SHIFT                                  0
#define SWREG_MAIN_MAIN10__ATEMODESEL__WIDTH                                  5
#define SWREG_MAIN_MAIN10__ATEMODESEL__MASK                         0x0000001fU
#define SWREG_MAIN_MAIN10__ATEMODESEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SWREG_MAIN_MAIN10__ATEMODESEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SWREG_MAIN_MAIN10__ATEMODESEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SWREG_MAIN_MAIN10__ATEMODESEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SWREG_MAIN_MAIN10__ATEMODESEL__RESET_VALUE                  0x00000012U
/** @} */

/* macros for field clkFixedCal */
/**
 * @defgroup swreg_main_regs_core_clkFixedCal_field clkFixedCal_field
 * @brief macros for field clkFixedCal
 * @details fixed time of the clock during calibration
 * @{
 */
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__SHIFT                                 5
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__WIDTH                                 4
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__MASK                        0x000001e0U
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001e0U) >> 5)
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000001e0U)
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001e0U) | (((uint32_t)(src) <<\
                    5) & 0x000001e0U)
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000001e0U)))
#define SWREG_MAIN_MAIN10__CLKFIXEDCAL__RESET_VALUE                 0x00000003U
/** @} */

/* macros for field skipClkCal */
/**
 * @defgroup swreg_main_regs_core_skipClkCal_field skipClkCal_field
 * @brief macros for field skipClkCal
 * @details if set, the clock cal will not be performed and clkUnitDelReg will be used instead
 * @{
 */
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__SHIFT                                  9
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__WIDTH                                  1
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__MASK                         0x00000200U
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define SWREG_MAIN_MAIN10__SKIPCLKCAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field clkCalCountTarget */
/**
 * @defgroup swreg_main_regs_core_clkCalCountTarget_field clkCalCountTarget_field
 * @brief macros for field clkCalCountTarget
 * @details the target count for the clock cal (550*32.768KHz ~= 18MHz)
 * @{
 */
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__SHIFT                          10
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__WIDTH                          10
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__MASK                  0x000ffc00U
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define SWREG_MAIN_MAIN10__CLKCALCOUNTTARGET__RESET_VALUE           0x00000226U
/** @} */

/* macros for field spare */
/**
 * @defgroup swreg_main_regs_core_spare_field spare_field
 * @brief macros for field spare
 * @details spare
 * @{
 */
#define SWREG_MAIN_MAIN10__SPARE__SHIFT                                      20
#define SWREG_MAIN_MAIN10__SPARE__WIDTH                                       8
#define SWREG_MAIN_MAIN10__SPARE__MASK                              0x0ff00000U
#define SWREG_MAIN_MAIN10__SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0ff00000U) >> 20)
#define SWREG_MAIN_MAIN10__SPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x0ff00000U)
#define SWREG_MAIN_MAIN10__SPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x0ff00000U)
#define SWREG_MAIN_MAIN10__SPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x0ff00000U)))
#define SWREG_MAIN_MAIN10__SPARE__RESET_VALUE                       0x00000000U
/** @} */
#define SWREG_MAIN_MAIN10__TYPE                                        uint32_t
#define SWREG_MAIN_MAIN10__READ                                     0x0fffffffU
#define SWREG_MAIN_MAIN10__WRITE                                    0x0fffffffU
#define SWREG_MAIN_MAIN10__PRESERVED                                0x00000000U
#define SWREG_MAIN_MAIN10__RESET_VALUE                              0x00089872U

#endif /* __SWREG_MAIN_MAIN10_MACRO__ */

/** @} end of main10 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_readout0 */
/**
 * @defgroup swreg_main_regs_core_readout0 readout0
 * @brief main readout bits definitions.
 * @{
 */
#ifndef __SWREG_MAIN_READOUT0_MACRO__
#define __SWREG_MAIN_READOUT0_MACRO__

/* macros for field request */
/**
 * @defgroup swreg_main_regs_core_request_field request_field
 * @brief macros for field request
 * @details supply sensing comparators for the 5 supplies
 * @{
 */
#define SWREG_MAIN_READOUT0__REQUEST__SHIFT                                   0
#define SWREG_MAIN_READOUT0__REQUEST__WIDTH                                   5
#define SWREG_MAIN_READOUT0__REQUEST__MASK                          0x0000001fU
#define SWREG_MAIN_READOUT0__REQUEST__READ(src) ((uint32_t)(src) & 0x0000001fU)
#define SWREG_MAIN_READOUT0__REQUEST__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field vbattGood */
/**
 * @defgroup swreg_main_regs_core_vbattGood_field vbattGood_field
 * @brief macros for field vbattGood
 * @details vbatt good comparator
 * @{
 */
#define SWREG_MAIN_READOUT0__VBATTGOOD__SHIFT                                 5
#define SWREG_MAIN_READOUT0__VBATTGOOD__WIDTH                                 1
#define SWREG_MAIN_READOUT0__VBATTGOOD__MASK                        0x00000020U
#define SWREG_MAIN_READOUT0__VBATTGOOD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define SWREG_MAIN_READOUT0__VBATTGOOD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define SWREG_MAIN_READOUT0__VBATTGOOD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define SWREG_MAIN_READOUT0__VBATTGOOD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field vstoreGood */
/**
 * @defgroup swreg_main_regs_core_vstoreGood_field vstoreGood_field
 * @brief macros for field vstoreGood
 * @details vstore good comparator
 * @{
 */
#define SWREG_MAIN_READOUT0__VSTOREGOOD__SHIFT                                6
#define SWREG_MAIN_READOUT0__VSTOREGOOD__WIDTH                                1
#define SWREG_MAIN_READOUT0__VSTOREGOOD__MASK                       0x00000040U
#define SWREG_MAIN_READOUT0__VSTOREGOOD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define SWREG_MAIN_READOUT0__VSTOREGOOD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define SWREG_MAIN_READOUT0__VSTOREGOOD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define SWREG_MAIN_READOUT0__VSTOREGOOD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field canHarvest */
/**
 * @defgroup swreg_main_regs_core_canHarvest_field canHarvest_field
 * @brief macros for field canHarvest
 * @details canharvest comparator
 * @{
 */
#define SWREG_MAIN_READOUT0__CANHARVEST__SHIFT                                7
#define SWREG_MAIN_READOUT0__CANHARVEST__WIDTH                                1
#define SWREG_MAIN_READOUT0__CANHARVEST__MASK                       0x00000080U
#define SWREG_MAIN_READOUT0__CANHARVEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SWREG_MAIN_READOUT0__CANHARVEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SWREG_MAIN_READOUT0__CANHARVEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define SWREG_MAIN_READOUT0__CANHARVEST__RESET_VALUE                0x00000000U
/** @} */

/* macros for field mustHarvest */
/**
 * @defgroup swreg_main_regs_core_mustHarvest_field mustHarvest_field
 * @brief macros for field mustHarvest
 * @details mustharvest comparator
 * @{
 */
#define SWREG_MAIN_READOUT0__MUSTHARVEST__SHIFT                               8
#define SWREG_MAIN_READOUT0__MUSTHARVEST__WIDTH                               1
#define SWREG_MAIN_READOUT0__MUSTHARVEST__MASK                      0x00000100U
#define SWREG_MAIN_READOUT0__MUSTHARVEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define SWREG_MAIN_READOUT0__MUSTHARVEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define SWREG_MAIN_READOUT0__MUSTHARVEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define SWREG_MAIN_READOUT0__MUSTHARVEST__RESET_VALUE               0x00000000U
/** @} */

/* macros for field indCurrentSign */
/**
 * @defgroup swreg_main_regs_core_indCurrentSign_field indCurrentSign_field
 * @brief macros for field indCurrentSign
 * @details inductor current sign comparator
 * @{
 */
#define SWREG_MAIN_READOUT0__INDCURRENTSIGN__SHIFT                            9
#define SWREG_MAIN_READOUT0__INDCURRENTSIGN__WIDTH                            1
#define SWREG_MAIN_READOUT0__INDCURRENTSIGN__MASK                   0x00000200U
#define SWREG_MAIN_READOUT0__INDCURRENTSIGN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define SWREG_MAIN_READOUT0__INDCURRENTSIGN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define SWREG_MAIN_READOUT0__INDCURRENTSIGN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define SWREG_MAIN_READOUT0__INDCURRENTSIGN__RESET_VALUE            0x00000000U
/** @} */

/* macros for field hop */
/**
 * @defgroup swreg_main_regs_core_hop_field hop_field
 * @brief macros for field hop
 * @details hop indicators for the 5 supplies
 * @{
 */
#define SWREG_MAIN_READOUT0__HOP__SHIFT                                      10
#define SWREG_MAIN_READOUT0__HOP__WIDTH                                       5
#define SWREG_MAIN_READOUT0__HOP__MASK                              0x00007c00U
#define SWREG_MAIN_READOUT0__HOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define SWREG_MAIN_READOUT0__HOP__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field freqCountSum_dvdd */
/**
 * @defgroup swreg_main_regs_core_freqCountSum_dvdd_field freqCountSum_dvdd_field
 * @brief macros for field freqCountSum_dvdd
 * @details dvdd switching event count in recent history window
 * @{
 */
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_DVDD__SHIFT                        15
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_DVDD__WIDTH                         8
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_DVDD__MASK                0x007f8000U
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007f8000U) >> 15)
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_DVDD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field freqCountSum_vaux */
/**
 * @defgroup swreg_main_regs_core_freqCountSum_vaux_field freqCountSum_vaux_field
 * @brief macros for field freqCountSum_vaux
 * @details vaux switching event count in recent history window
 * @{
 */
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_VAUX__SHIFT                        23
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_VAUX__WIDTH                         8
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_VAUX__MASK                0x7f800000U
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_VAUX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7f800000U) >> 23)
#define SWREG_MAIN_READOUT0__FREQCOUNTSUM_VAUX__RESET_VALUE         0x00000000U
/** @} */
#define SWREG_MAIN_READOUT0__TYPE                                      uint32_t
#define SWREG_MAIN_READOUT0__READ                                   0x7fffffffU
#define SWREG_MAIN_READOUT0__PRESERVED                              0x00000000U
#define SWREG_MAIN_READOUT0__RESET_VALUE                            0x00000000U

#endif /* __SWREG_MAIN_READOUT0_MACRO__ */

/** @} end of readout0 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_readout1 */
/**
 * @defgroup swreg_main_regs_core_readout1 readout1
 * @brief main readout bits definitions.
 * @{
 */
#ifndef __SWREG_MAIN_READOUT1_MACRO__
#define __SWREG_MAIN_READOUT1_MACRO__

/* macros for field freqCountSum_vddio */
/**
 * @defgroup swreg_main_regs_core_freqCountSum_vddio_field freqCountSum_vddio_field
 * @brief macros for field freqCountSum_vddio
 * @details vddio switching event count in recent history window
 * @{
 */
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VDDIO__SHIFT                        0
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VDDIO__WIDTH                        8
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VDDIO__MASK               0x000000ffU
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VDDIO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VDDIO__RESET_VALUE        0x00000000U
/** @} */

/* macros for field freqCountSum_avdd */
/**
 * @defgroup swreg_main_regs_core_freqCountSum_avdd_field freqCountSum_avdd_field
 * @brief macros for field freqCountSum_avdd
 * @details avdd switching event count in recent history window
 * @{
 */
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_AVDD__SHIFT                         8
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_AVDD__WIDTH                         8
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_AVDD__MASK                0x0000ff00U
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_AVDD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field freqCountSum_vstore */
/**
 * @defgroup swreg_main_regs_core_freqCountSum_vstore_field freqCountSum_vstore_field
 * @brief macros for field freqCountSum_vstore
 * @details vstore switching event count in recent history window
 * @{
 */
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VSTORE__SHIFT                      16
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VSTORE__WIDTH                       8
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VSTORE__MASK              0x00ff0000U
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VSTORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define SWREG_MAIN_READOUT1__FREQCOUNTSUM_VSTORE__RESET_VALUE       0x00000000U
/** @} */

/* macros for field mpptDone */
/**
 * @defgroup swreg_main_regs_core_mpptDone_field mpptDone_field
 * @brief macros for field mpptDone
 * @details if 1 the mppt the target number of periods or events is reached
 * @{
 */
#define SWREG_MAIN_READOUT1__MPPTDONE__SHIFT                                 24
#define SWREG_MAIN_READOUT1__MPPTDONE__WIDTH                                  1
#define SWREG_MAIN_READOUT1__MPPTDONE__MASK                         0x01000000U
#define SWREG_MAIN_READOUT1__MPPTDONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SWREG_MAIN_READOUT1__MPPTDONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SWREG_MAIN_READOUT1__MPPTDONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SWREG_MAIN_READOUT1__MPPTDONE__RESET_VALUE                  0x00000000U
/** @} */
#define SWREG_MAIN_READOUT1__TYPE                                      uint32_t
#define SWREG_MAIN_READOUT1__READ                                   0x01ffffffU
#define SWREG_MAIN_READOUT1__PRESERVED                              0x00000000U
#define SWREG_MAIN_READOUT1__RESET_VALUE                            0x00000000U

#endif /* __SWREG_MAIN_READOUT1_MACRO__ */

/** @} end of readout1 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_readout2 */
/**
 * @defgroup swreg_main_regs_core_readout2 readout2
 * @brief main readout bits definitions.
 * @{
 */
#ifndef __SWREG_MAIN_READOUT2_MACRO__
#define __SWREG_MAIN_READOUT2_MACRO__

/* macros for field mpptPeriodCount */
/**
 * @defgroup swreg_main_regs_core_mpptPeriodCount_field mpptPeriodCount_field
 * @brief macros for field mpptPeriodCount
 * @details the measured number of periods when mpptTargetIsPeriods=0
 * @{
 */
#define SWREG_MAIN_READOUT2__MPPTPERIODCOUNT__SHIFT                           0
#define SWREG_MAIN_READOUT2__MPPTPERIODCOUNT__WIDTH                           9
#define SWREG_MAIN_READOUT2__MPPTPERIODCOUNT__MASK                  0x000001ffU
#define SWREG_MAIN_READOUT2__MPPTPERIODCOUNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define SWREG_MAIN_READOUT2__MPPTPERIODCOUNT__RESET_VALUE           0x00000000U
/** @} */

/* macros for field mpptEventCount */
/**
 * @defgroup swreg_main_regs_core_mpptEventCount_field mpptEventCount_field
 * @brief macros for field mpptEventCount
 * @details the measured number of events when mpptTargetIsPeriods=1. Also the exact number of events when mpptTargetIsPeriods=0.
 * @{
 */
#define SWREG_MAIN_READOUT2__MPPTEVENTCOUNT__SHIFT                            9
#define SWREG_MAIN_READOUT2__MPPTEVENTCOUNT__WIDTH                           10
#define SWREG_MAIN_READOUT2__MPPTEVENTCOUNT__MASK                   0x0007fe00U
#define SWREG_MAIN_READOUT2__MPPTEVENTCOUNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007fe00U) >> 9)
#define SWREG_MAIN_READOUT2__MPPTEVENTCOUNT__RESET_VALUE            0x00000000U
/** @} */

/* macros for field gear_batt_dvdd */
/**
 * @defgroup swreg_main_regs_core_gear_batt_dvdd_field gear_batt_dvdd_field
 * @brief macros for field gear_batt_dvdd
 * @details gear for battery to dvdd mode
 * @{
 */
#define SWREG_MAIN_READOUT2__GEAR_BATT_DVDD__SHIFT                           19
#define SWREG_MAIN_READOUT2__GEAR_BATT_DVDD__WIDTH                            4
#define SWREG_MAIN_READOUT2__GEAR_BATT_DVDD__MASK                   0x00780000U
#define SWREG_MAIN_READOUT2__GEAR_BATT_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00780000U) >> 19)
#define SWREG_MAIN_READOUT2__GEAR_BATT_DVDD__RESET_VALUE            0x00000000U
/** @} */

/* macros for field gear_batt_vaux */
/**
 * @defgroup swreg_main_regs_core_gear_batt_vaux_field gear_batt_vaux_field
 * @brief macros for field gear_batt_vaux
 * @details gear for battery to vaux mode
 * @{
 */
#define SWREG_MAIN_READOUT2__GEAR_BATT_VAUX__SHIFT                           23
#define SWREG_MAIN_READOUT2__GEAR_BATT_VAUX__WIDTH                            4
#define SWREG_MAIN_READOUT2__GEAR_BATT_VAUX__MASK                   0x07800000U
#define SWREG_MAIN_READOUT2__GEAR_BATT_VAUX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07800000U) >> 23)
#define SWREG_MAIN_READOUT2__GEAR_BATT_VAUX__RESET_VALUE            0x00000000U
/** @} */

/* macros for field gear_batt_vddio */
/**
 * @defgroup swreg_main_regs_core_gear_batt_vddio_field gear_batt_vddio_field
 * @brief macros for field gear_batt_vddio
 * @details gear for battery to vddio mode
 * @{
 */
#define SWREG_MAIN_READOUT2__GEAR_BATT_VDDIO__SHIFT                          27
#define SWREG_MAIN_READOUT2__GEAR_BATT_VDDIO__WIDTH                           4
#define SWREG_MAIN_READOUT2__GEAR_BATT_VDDIO__MASK                  0x78000000U
#define SWREG_MAIN_READOUT2__GEAR_BATT_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x78000000U) >> 27)
#define SWREG_MAIN_READOUT2__GEAR_BATT_VDDIO__RESET_VALUE           0x00000000U
/** @} */
#define SWREG_MAIN_READOUT2__TYPE                                      uint32_t
#define SWREG_MAIN_READOUT2__READ                                   0x7fffffffU
#define SWREG_MAIN_READOUT2__PRESERVED                              0x00000000U
#define SWREG_MAIN_READOUT2__RESET_VALUE                            0x00000000U

#endif /* __SWREG_MAIN_READOUT2_MACRO__ */

/** @} end of readout2 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_readout3 */
/**
 * @defgroup swreg_main_regs_core_readout3 readout3
 * @brief main readout bits definitions.
 * @{
 */
#ifndef __SWREG_MAIN_READOUT3_MACRO__
#define __SWREG_MAIN_READOUT3_MACRO__

/* macros for field gear_batt_avdd */
/**
 * @defgroup swreg_main_regs_core_gear_batt_avdd_field gear_batt_avdd_field
 * @brief macros for field gear_batt_avdd
 * @details gear for battery to avdd mode
 * @{
 */
#define SWREG_MAIN_READOUT3__GEAR_BATT_AVDD__SHIFT                            0
#define SWREG_MAIN_READOUT3__GEAR_BATT_AVDD__WIDTH                            4
#define SWREG_MAIN_READOUT3__GEAR_BATT_AVDD__MASK                   0x0000000fU
#define SWREG_MAIN_READOUT3__GEAR_BATT_AVDD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_MAIN_READOUT3__GEAR_BATT_AVDD__RESET_VALUE            0x00000000U
/** @} */

/* macros for field gear_batt_store */
/**
 * @defgroup swreg_main_regs_core_gear_batt_store_field gear_batt_store_field
 * @brief macros for field gear_batt_store
 * @details gear for battery to store mode
 * @{
 */
#define SWREG_MAIN_READOUT3__GEAR_BATT_STORE__SHIFT                           4
#define SWREG_MAIN_READOUT3__GEAR_BATT_STORE__WIDTH                           4
#define SWREG_MAIN_READOUT3__GEAR_BATT_STORE__MASK                  0x000000f0U
#define SWREG_MAIN_READOUT3__GEAR_BATT_STORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define SWREG_MAIN_READOUT3__GEAR_BATT_STORE__RESET_VALUE           0x00000000U
/** @} */
#define SWREG_MAIN_READOUT3__TYPE                                      uint32_t
#define SWREG_MAIN_READOUT3__READ                                   0x000000ffU
#define SWREG_MAIN_READOUT3__PRESERVED                              0x00000000U
#define SWREG_MAIN_READOUT3__RESET_VALUE                            0x00000000U

#endif /* __SWREG_MAIN_READOUT3_MACRO__ */

/** @} end of readout3 */

/* macros for BlueprintGlobalNameSpace::SWREG_MAIN_core_id */
/**
 * @defgroup swreg_main_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __SWREG_MAIN_CORE_ID_MACRO__
#define __SWREG_MAIN_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup swreg_main_regs_core_id_field id_field
 * @brief macros for field id
 * @details SWRM in ASCII
 * @{
 */
#define SWREG_MAIN_CORE_ID__ID__SHIFT                                         0
#define SWREG_MAIN_CORE_ID__ID__WIDTH                                        32
#define SWREG_MAIN_CORE_ID__ID__MASK                                0xffffffffU
#define SWREG_MAIN_CORE_ID__ID__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define SWREG_MAIN_CORE_ID__ID__RESET_VALUE                         0x5357524dU
/** @} */
#define SWREG_MAIN_CORE_ID__TYPE                                       uint32_t
#define SWREG_MAIN_CORE_ID__READ                                    0xffffffffU
#define SWREG_MAIN_CORE_ID__PRESERVED                               0x00000000U
#define SWREG_MAIN_CORE_ID__RESET_VALUE                             0x5357524dU

#endif /* __SWREG_MAIN_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of SWREG_MAIN_REGS_CORE */
#endif /* __REG_SWREG_MAIN_REGS_CORE_H__ */
