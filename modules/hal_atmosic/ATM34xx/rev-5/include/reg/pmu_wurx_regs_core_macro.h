/*                                                                           */
/* File:       pmu_wurx_regs_core_macro.h                                    */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic pmu_wurx_regs_core.rdl             */
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


#ifndef __REG_PMU_WURX_REGS_CORE_H__
#define __REG_PMU_WURX_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup PMU_WURX_REGS_CORE pmu_wurx_regs_core
 * @ingroup AT_REG
 * @brief pmu_wurx_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx_general */
/**
 * @defgroup pmu_wurx_regs_core_wurx_general wurx_general
 * @brief Wake-up RX overrides and bias definitions.
 * @{
 */
#ifndef __WURX_WURX_GENERAL_MACRO__
#define __WURX_WURX_GENERAL_MACRO__

/* macros for field wurx_select */
/**
 * @defgroup pmu_wurx_regs_core_wurx_select_field wurx_select_field
 * @brief macros for field wurx_select
 * @details which algorithm to use: 0: algorithm 0, 1: algorithm 1
 * @{
 */
#define WURX_WURX_GENERAL__WURX_SELECT__SHIFT                                 0
#define WURX_WURX_GENERAL__WURX_SELECT__WIDTH                                 1
#define WURX_WURX_GENERAL__WURX_SELECT__MASK                        0x00000001U
#define WURX_WURX_GENERAL__WURX_SELECT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WURX_WURX_GENERAL__WURX_SELECT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WURX_WURX_GENERAL__WURX_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WURX_WURX_GENERAL__WURX_SELECT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WURX_WURX_GENERAL__WURX_SELECT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WURX_WURX_GENERAL__WURX_SELECT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WURX_WURX_GENERAL__WURX_SELECT__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field wurx0_en_ovr */
/**
 * @defgroup pmu_wurx_regs_core_wurx0_en_ovr_field wurx0_en_ovr_field
 * @brief macros for field wurx0_en_ovr
 * @details override wurx0_en
 * @{
 */
#define WURX_WURX_GENERAL__WURX0_EN_OVR__SHIFT                                1
#define WURX_WURX_GENERAL__WURX0_EN_OVR__WIDTH                                1
#define WURX_WURX_GENERAL__WURX0_EN_OVR__MASK                       0x00000002U
#define WURX_WURX_GENERAL__WURX0_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WURX_WURX_GENERAL__WURX0_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WURX_WURX_GENERAL__WURX0_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WURX_WURX_GENERAL__WURX0_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WURX_WURX_GENERAL__WURX0_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WURX_WURX_GENERAL__WURX0_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WURX_WURX_GENERAL__WURX0_EN_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field wurx0_en_val */
/**
 * @defgroup pmu_wurx_regs_core_wurx0_en_val_field wurx0_en_val_field
 * @brief macros for field wurx0_en_val
 * @details override value for wurx0_en
 * @{
 */
#define WURX_WURX_GENERAL__WURX0_EN_VAL__SHIFT                                2
#define WURX_WURX_GENERAL__WURX0_EN_VAL__WIDTH                                1
#define WURX_WURX_GENERAL__WURX0_EN_VAL__MASK                       0x00000004U
#define WURX_WURX_GENERAL__WURX0_EN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WURX_WURX_GENERAL__WURX0_EN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WURX_WURX_GENERAL__WURX0_EN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WURX_WURX_GENERAL__WURX0_EN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WURX_WURX_GENERAL__WURX0_EN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WURX_WURX_GENERAL__WURX0_EN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WURX_WURX_GENERAL__WURX0_EN_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field wurx1_en_ovr */
/**
 * @defgroup pmu_wurx_regs_core_wurx1_en_ovr_field wurx1_en_ovr_field
 * @brief macros for field wurx1_en_ovr
 * @details override wurx1_en
 * @{
 */
#define WURX_WURX_GENERAL__WURX1_EN_OVR__SHIFT                                3
#define WURX_WURX_GENERAL__WURX1_EN_OVR__WIDTH                                1
#define WURX_WURX_GENERAL__WURX1_EN_OVR__MASK                       0x00000008U
#define WURX_WURX_GENERAL__WURX1_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define WURX_WURX_GENERAL__WURX1_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define WURX_WURX_GENERAL__WURX1_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define WURX_WURX_GENERAL__WURX1_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define WURX_WURX_GENERAL__WURX1_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define WURX_WURX_GENERAL__WURX1_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define WURX_WURX_GENERAL__WURX1_EN_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field wurx1_en_val */
/**
 * @defgroup pmu_wurx_regs_core_wurx1_en_val_field wurx1_en_val_field
 * @brief macros for field wurx1_en_val
 * @details override value for wurx1_en
 * @{
 */
#define WURX_WURX_GENERAL__WURX1_EN_VAL__SHIFT                                4
#define WURX_WURX_GENERAL__WURX1_EN_VAL__WIDTH                                1
#define WURX_WURX_GENERAL__WURX1_EN_VAL__MASK                       0x00000010U
#define WURX_WURX_GENERAL__WURX1_EN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define WURX_WURX_GENERAL__WURX1_EN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define WURX_WURX_GENERAL__WURX1_EN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define WURX_WURX_GENERAL__WURX1_EN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define WURX_WURX_GENERAL__WURX1_EN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define WURX_WURX_GENERAL__WURX1_EN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define WURX_WURX_GENERAL__WURX1_EN_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field wakeup0_ovr */
/**
 * @defgroup pmu_wurx_regs_core_wakeup0_ovr_field wakeup0_ovr_field
 * @brief macros for field wakeup0_ovr
 * @details wakeup0 override
 * @{
 */
#define WURX_WURX_GENERAL__WAKEUP0_OVR__SHIFT                                 5
#define WURX_WURX_GENERAL__WAKEUP0_OVR__WIDTH                                 1
#define WURX_WURX_GENERAL__WAKEUP0_OVR__MASK                        0x00000020U
#define WURX_WURX_GENERAL__WAKEUP0_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define WURX_WURX_GENERAL__WAKEUP0_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define WURX_WURX_GENERAL__WAKEUP0_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define WURX_WURX_GENERAL__WAKEUP0_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define WURX_WURX_GENERAL__WAKEUP0_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define WURX_WURX_GENERAL__WAKEUP0_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define WURX_WURX_GENERAL__WAKEUP0_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field wakeup0_ovr_val */
/**
 * @defgroup pmu_wurx_regs_core_wakeup0_ovr_val_field wakeup0_ovr_val_field
 * @brief macros for field wakeup0_ovr_val
 * @details wakeup0 override value
 * @{
 */
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__SHIFT                             6
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__WIDTH                             1
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__MASK                    0x00000040U
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define WURX_WURX_GENERAL__WAKEUP0_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field wakeup1_ovr */
/**
 * @defgroup pmu_wurx_regs_core_wakeup1_ovr_field wakeup1_ovr_field
 * @brief macros for field wakeup1_ovr
 * @details wakeup1 override
 * @{
 */
#define WURX_WURX_GENERAL__WAKEUP1_OVR__SHIFT                                 7
#define WURX_WURX_GENERAL__WAKEUP1_OVR__WIDTH                                 1
#define WURX_WURX_GENERAL__WAKEUP1_OVR__MASK                        0x00000080U
#define WURX_WURX_GENERAL__WAKEUP1_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define WURX_WURX_GENERAL__WAKEUP1_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define WURX_WURX_GENERAL__WAKEUP1_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define WURX_WURX_GENERAL__WAKEUP1_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define WURX_WURX_GENERAL__WAKEUP1_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define WURX_WURX_GENERAL__WAKEUP1_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define WURX_WURX_GENERAL__WAKEUP1_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field wakeup1_ovr_val */
/**
 * @defgroup pmu_wurx_regs_core_wakeup1_ovr_val_field wakeup1_ovr_val_field
 * @brief macros for field wakeup1_ovr_val
 * @details wakeup1 override value
 * @{
 */
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__SHIFT                             8
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__WIDTH                             1
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__MASK                    0x00000100U
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define WURX_WURX_GENERAL__WAKEUP1_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field init_cal_ovr */
/**
 * @defgroup pmu_wurx_regs_core_init_cal_ovr_field init_cal_ovr_field
 * @brief macros for field init_cal_ovr
 * @details ovrride for which cal to do
 * @{
 */
#define WURX_WURX_GENERAL__INIT_CAL_OVR__SHIFT                                9
#define WURX_WURX_GENERAL__INIT_CAL_OVR__WIDTH                                1
#define WURX_WURX_GENERAL__INIT_CAL_OVR__MASK                       0x00000200U
#define WURX_WURX_GENERAL__INIT_CAL_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define WURX_WURX_GENERAL__INIT_CAL_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define WURX_WURX_GENERAL__INIT_CAL_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define WURX_WURX_GENERAL__INIT_CAL_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define WURX_WURX_GENERAL__INIT_CAL_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define WURX_WURX_GENERAL__INIT_CAL_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define WURX_WURX_GENERAL__INIT_CAL_OVR__RESET_VALUE                0x00000001U
/** @} */

/* macros for field init_cal_ovr_val */
/**
 * @defgroup pmu_wurx_regs_core_init_cal_ovr_val_field init_cal_ovr_val_field
 * @brief macros for field init_cal_ovr_val
 * @details override value for which cal to do
 * @{
 */
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__SHIFT                           10
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__WIDTH                            1
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__MASK                   0x00000400U
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define WURX_WURX_GENERAL__INIT_CAL_OVR_VAL__RESET_VALUE            0x00000001U
/** @} */

/* macros for field bias */
/**
 * @defgroup pmu_wurx_regs_core_bias_field bias_field
 * @brief macros for field bias
 * @details ???
 * @{
 */
#define WURX_WURX_GENERAL__BIAS__SHIFT                                       11
#define WURX_WURX_GENERAL__BIAS__WIDTH                                        4
#define WURX_WURX_GENERAL__BIAS__MASK                               0x00007800U
#define WURX_WURX_GENERAL__BIAS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007800U) >> 11)
#define WURX_WURX_GENERAL__BIAS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00007800U)
#define WURX_WURX_GENERAL__BIAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007800U) | (((uint32_t)(src) <<\
                    11) & 0x00007800U)
#define WURX_WURX_GENERAL__BIAS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00007800U)))
#define WURX_WURX_GENERAL__BIAS__RESET_VALUE                        0x00000004U
/** @} */

/* macros for field atbsel */
/**
 * @defgroup pmu_wurx_regs_core_atbsel_field atbsel_field
 * @brief macros for field atbsel
 * @details atb select
 * @{
 */
#define WURX_WURX_GENERAL__ATBSEL__SHIFT                                     15
#define WURX_WURX_GENERAL__ATBSEL__WIDTH                                      4
#define WURX_WURX_GENERAL__ATBSEL__MASK                             0x00078000U
#define WURX_WURX_GENERAL__ATBSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00078000U) >> 15)
#define WURX_WURX_GENERAL__ATBSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00078000U)
#define WURX_WURX_GENERAL__ATBSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00078000U) | (((uint32_t)(src) <<\
                    15) & 0x00078000U)
#define WURX_WURX_GENERAL__ATBSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00078000U)))
#define WURX_WURX_GENERAL__ATBSEL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field attnIn_ovr */
/**
 * @defgroup pmu_wurx_regs_core_attnIn_ovr_field attnIn_ovr_field
 * @brief macros for field attnIn_ovr
 * @details attnIn ovr
 * @{
 */
#define WURX_WURX_GENERAL__ATTNIN_OVR__SHIFT                                 19
#define WURX_WURX_GENERAL__ATTNIN_OVR__WIDTH                                  1
#define WURX_WURX_GENERAL__ATTNIN_OVR__MASK                         0x00080000U
#define WURX_WURX_GENERAL__ATTNIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define WURX_WURX_GENERAL__ATTNIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define WURX_WURX_GENERAL__ATTNIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define WURX_WURX_GENERAL__ATTNIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define WURX_WURX_GENERAL__ATTNIN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define WURX_WURX_GENERAL__ATTNIN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define WURX_WURX_GENERAL__ATTNIN_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field attnIn_ovr_val */
/**
 * @defgroup pmu_wurx_regs_core_attnIn_ovr_val_field attnIn_ovr_val_field
 * @brief macros for field attnIn_ovr_val
 * @details ovrride val for attnIn
 * @{
 */
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__SHIFT                             20
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__WIDTH                              1
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__MASK                     0x00100000U
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define WURX_WURX_GENERAL__ATTNIN_OVR_VAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field thr_cal_en_reg */
/**
 * @defgroup pmu_wurx_regs_core_thr_cal_en_reg_field thr_cal_en_reg_field
 * @brief macros for field thr_cal_en_reg
 * @details if set to 0 disables calibration
 * @{
 */
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__SHIFT                             21
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__WIDTH                              1
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__MASK                     0x00200000U
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define WURX_WURX_GENERAL__THR_CAL_EN_REG__RESET_VALUE              0x00000001U
/** @} */
#define WURX_WURX_GENERAL__TYPE                                        uint32_t
#define WURX_WURX_GENERAL__READ                                     0x003fffffU
#define WURX_WURX_GENERAL__WRITE                                    0x003fffffU
#define WURX_WURX_GENERAL__PRESERVED                                0x00000000U
#define WURX_WURX_GENERAL__RESET_VALUE                              0x00202600U

#endif /* __WURX_WURX_GENERAL_MACRO__ */

/** @} end of wurx_general */

/* macros for BlueprintGlobalNameSpace::WURX_wurx_general2 */
/**
 * @defgroup pmu_wurx_regs_core_wurx_general2 wurx_general2
 * @brief Wake-up RX general registers definitions.
 * @{
 */
#ifndef __WURX_WURX_GENERAL2_MACRO__
#define __WURX_WURX_GENERAL2_MACRO__

/* macros for field load_ovr */
/**
 * @defgroup pmu_wurx_regs_core_load_ovr_field load_ovr_field
 * @brief macros for field load_ovr
 * @details ovrride load value
 * @{
 */
#define WURX_WURX_GENERAL2__LOAD_OVR__SHIFT                                   0
#define WURX_WURX_GENERAL2__LOAD_OVR__WIDTH                                   1
#define WURX_WURX_GENERAL2__LOAD_OVR__MASK                          0x00000001U
#define WURX_WURX_GENERAL2__LOAD_OVR__READ(src) ((uint32_t)(src) & 0x00000001U)
#define WURX_WURX_GENERAL2__LOAD_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WURX_WURX_GENERAL2__LOAD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WURX_WURX_GENERAL2__LOAD_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WURX_WURX_GENERAL2__LOAD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WURX_WURX_GENERAL2__LOAD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WURX_WURX_GENERAL2__LOAD_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field load_ovr_val */
/**
 * @defgroup pmu_wurx_regs_core_load_ovr_val_field load_ovr_val_field
 * @brief macros for field load_ovr_val
 * @details starting point for cal or override value
 * @{
 */
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__SHIFT                               1
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__WIDTH                               9
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__MASK                      0x000003feU
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003feU) >> 1)
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000003feU)
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003feU) | (((uint32_t)(src) <<\
                    1) & 0x000003feU)
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000003feU)))
#define WURX_WURX_GENERAL2__LOAD_OVR_VAL__RESET_VALUE               0x00000064U
/** @} */

/* macros for field offset_ovr */
/**
 * @defgroup pmu_wurx_regs_core_offset_ovr_field offset_ovr_field
 * @brief macros for field offset_ovr
 * @details override offset value
 * @{
 */
#define WURX_WURX_GENERAL2__OFFSET_OVR__SHIFT                                10
#define WURX_WURX_GENERAL2__OFFSET_OVR__WIDTH                                 1
#define WURX_WURX_GENERAL2__OFFSET_OVR__MASK                        0x00000400U
#define WURX_WURX_GENERAL2__OFFSET_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define WURX_WURX_GENERAL2__OFFSET_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define WURX_WURX_GENERAL2__OFFSET_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define WURX_WURX_GENERAL2__OFFSET_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define WURX_WURX_GENERAL2__OFFSET_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define WURX_WURX_GENERAL2__OFFSET_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define WURX_WURX_GENERAL2__OFFSET_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field offset_ovr_val */
/**
 * @defgroup pmu_wurx_regs_core_offset_ovr_val_field offset_ovr_val_field
 * @brief macros for field offset_ovr_val
 * @details starting point for cal or override value
 * @{
 */
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__SHIFT                            11
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__WIDTH                             8
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__MASK                    0x0007f800U
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007f800U) >> 11)
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0007f800U)
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007f800U) | (((uint32_t)(src) <<\
                    11) & 0x0007f800U)
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0007f800U)))
#define WURX_WURX_GENERAL2__OFFSET_OVR_VAL__RESET_VALUE             0x00000064U
/** @} */

/* macros for field offsImbalance */
/**
 * @defgroup pmu_wurx_regs_core_offsImbalance_field offsImbalance_field
 * @brief macros for field offsImbalance
 * @details offset imbalance
 * @{
 */
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__SHIFT                             19
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__WIDTH                              5
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__MASK                     0x00f80000U
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f80000U) >> 19)
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00f80000U)
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f80000U) | (((uint32_t)(src) <<\
                    19) & 0x00f80000U)
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00f80000U)))
#define WURX_WURX_GENERAL2__OFFSIMBALANCE__RESET_VALUE              0x00000000U
/** @} */

/* macros for field offsRange */
/**
 * @defgroup pmu_wurx_regs_core_offsRange_field offsRange_field
 * @brief macros for field offsRange
 * @details range for offset
 * @{
 */
#define WURX_WURX_GENERAL2__OFFSRANGE__SHIFT                                 24
#define WURX_WURX_GENERAL2__OFFSRANGE__WIDTH                                  3
#define WURX_WURX_GENERAL2__OFFSRANGE__MASK                         0x07000000U
#define WURX_WURX_GENERAL2__OFFSRANGE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define WURX_WURX_GENERAL2__OFFSRANGE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define WURX_WURX_GENERAL2__OFFSRANGE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define WURX_WURX_GENERAL2__OFFSRANGE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define WURX_WURX_GENERAL2__OFFSRANGE__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field thr */
/**
 * @defgroup pmu_wurx_regs_core_thr_field thr_field
 * @brief macros for field thr
 * @details select output vs reference
 * @{
 */
#define WURX_WURX_GENERAL2__THR__SHIFT                                       27
#define WURX_WURX_GENERAL2__THR__WIDTH                                        5
#define WURX_WURX_GENERAL2__THR__MASK                               0xf8000000U
#define WURX_WURX_GENERAL2__THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf8000000U) >> 27)
#define WURX_WURX_GENERAL2__THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0xf8000000U)
#define WURX_WURX_GENERAL2__THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf8000000U) | (((uint32_t)(src) <<\
                    27) & 0xf8000000U)
#define WURX_WURX_GENERAL2__THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0xf8000000U)))
#define WURX_WURX_GENERAL2__THR__RESET_VALUE                        0x00000000U
/** @} */
#define WURX_WURX_GENERAL2__TYPE                                       uint32_t
#define WURX_WURX_GENERAL2__READ                                    0xffffffffU
#define WURX_WURX_GENERAL2__WRITE                                   0xffffffffU
#define WURX_WURX_GENERAL2__PRESERVED                               0x00000000U
#define WURX_WURX_GENERAL2__RESET_VALUE                             0x000320c8U

#endif /* __WURX_WURX_GENERAL2_MACRO__ */

/** @} end of wurx_general2 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx0_0 */
/**
 * @defgroup pmu_wurx_regs_core_wurx0_0 wurx0_0
 * @brief Wake-up RX unique ID, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX0_0_MACRO__
#define __WURX_WURX0_0_MACRO__

/* macros for field uid */
/**
 * @defgroup pmu_wurx_regs_core_uid_field uid_field
 * @brief macros for field uid
 * @details User ID, upper 16 bits for group ID, lower 16 bits for user ID
 * @{
 */
#define WURX_WURX0_0__UID__SHIFT                                              0
#define WURX_WURX0_0__UID__WIDTH                                             32
#define WURX_WURX0_0__UID__MASK                                     0xffffffffU
#define WURX_WURX0_0__UID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX0_0__UID__WRITE(src)           ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX0_0__UID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WURX_WURX0_0__UID__VERIFY(src)    (!(((uint32_t)(src) & ~0xffffffffU)))
#define WURX_WURX0_0__UID__RESET_VALUE                              0xaaaaaaaaU
/** @} */
#define WURX_WURX0_0__TYPE                                             uint32_t
#define WURX_WURX0_0__READ                                          0xffffffffU
#define WURX_WURX0_0__WRITE                                         0xffffffffU
#define WURX_WURX0_0__PRESERVED                                     0x00000000U
#define WURX_WURX0_0__RESET_VALUE                                   0xaaaaaaaaU

#endif /* __WURX_WURX0_0_MACRO__ */

/** @} end of wurx0_0 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx0_1 */
/**
 * @defgroup pmu_wurx_regs_core_wurx0_1 wurx0_1
 * @brief Wake-up RX global ID, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX0_1_MACRO__
#define __WURX_WURX0_1_MACRO__

/* macros for field gid */
/**
 * @defgroup pmu_wurx_regs_core_gid_field gid_field
 * @brief macros for field gid
 * @details Global ID
 * @{
 */
#define WURX_WURX0_1__GID__SHIFT                                              0
#define WURX_WURX0_1__GID__WIDTH                                             32
#define WURX_WURX0_1__GID__MASK                                     0xffffffffU
#define WURX_WURX0_1__GID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX0_1__GID__WRITE(src)           ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX0_1__GID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WURX_WURX0_1__GID__VERIFY(src)    (!(((uint32_t)(src) & ~0xffffffffU)))
#define WURX_WURX0_1__GID__RESET_VALUE                              0xffffffffU
/** @} */
#define WURX_WURX0_1__TYPE                                             uint32_t
#define WURX_WURX0_1__READ                                          0xffffffffU
#define WURX_WURX0_1__WRITE                                         0xffffffffU
#define WURX_WURX0_1__PRESERVED                                     0x00000000U
#define WURX_WURX0_1__RESET_VALUE                                   0xffffffffU

#endif /* __WURX_WURX0_1_MACRO__ */

/** @} end of wurx0_1 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx0_2 */
/**
 * @defgroup pmu_wurx_regs_core_wurx0_2 wurx0_2
 * @brief Wake-up RX settings, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX0_2_MACRO__
#define __WURX_WURX0_2_MACRO__

/* macros for field err_threshold */
/**
 * @defgroup pmu_wurx_regs_core_err_threshold_field err_threshold_field
 * @brief macros for field err_threshold
 * @details number of bits of error between RX ID and detected ID
 * @{
 */
#define WURX_WURX0_2__ERR_THRESHOLD__SHIFT                                    0
#define WURX_WURX0_2__ERR_THRESHOLD__WIDTH                                    6
#define WURX_WURX0_2__ERR_THRESHOLD__MASK                           0x0000003fU
#define WURX_WURX0_2__ERR_THRESHOLD__READ(src)  ((uint32_t)(src) & 0x0000003fU)
#define WURX_WURX0_2__ERR_THRESHOLD__WRITE(src) ((uint32_t)(src) & 0x0000003fU)
#define WURX_WURX0_2__ERR_THRESHOLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define WURX_WURX0_2__ERR_THRESHOLD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define WURX_WURX0_2__ERR_THRESHOLD__RESET_VALUE                    0x0000001fU
/** @} */

/* macros for field too_lo1 */
/**
 * @defgroup pmu_wurx_regs_core_too_lo1_field too_lo1_field
 * @brief macros for field too_lo1
 * @details number of samples that threshold is too low before linear increase in cal
 * @{
 */
#define WURX_WURX0_2__TOO_LO1__SHIFT                                          6
#define WURX_WURX0_2__TOO_LO1__WIDTH                                          5
#define WURX_WURX0_2__TOO_LO1__MASK                                 0x000007c0U
#define WURX_WURX0_2__TOO_LO1__READ(src) (((uint32_t)(src) & 0x000007c0U) >> 6)
#define WURX_WURX0_2__TOO_LO1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000007c0U)
#define WURX_WURX0_2__TOO_LO1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007c0U) | (((uint32_t)(src) <<\
                    6) & 0x000007c0U)
#define WURX_WURX0_2__TOO_LO1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000007c0U)))
#define WURX_WURX0_2__TOO_LO1__RESET_VALUE                          0x00000005U
/** @} */

/* macros for field too_lo2 */
/**
 * @defgroup pmu_wurx_regs_core_too_lo2_field too_lo2_field
 * @brief macros for field too_lo2
 * @details number of samples that threshold is too low before binary cal
 * @{
 */
#define WURX_WURX0_2__TOO_LO2__SHIFT                                         11
#define WURX_WURX0_2__TOO_LO2__WIDTH                                          5
#define WURX_WURX0_2__TOO_LO2__MASK                                 0x0000f800U
#define WURX_WURX0_2__TOO_LO2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f800U) >> 11)
#define WURX_WURX0_2__TOO_LO2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0000f800U)
#define WURX_WURX0_2__TOO_LO2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f800U) | (((uint32_t)(src) <<\
                    11) & 0x0000f800U)
#define WURX_WURX0_2__TOO_LO2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0000f800U)))
#define WURX_WURX0_2__TOO_LO2__RESET_VALUE                          0x0000000aU
/** @} */

/* macros for field too_hi */
/**
 * @defgroup pmu_wurx_regs_core_too_hi_field too_hi_field
 * @brief macros for field too_hi
 * @details number of samples that threshold is too high before binary cal
 * @{
 */
#define WURX_WURX0_2__TOO_HI__SHIFT                                          16
#define WURX_WURX0_2__TOO_HI__WIDTH                                           5
#define WURX_WURX0_2__TOO_HI__MASK                                  0x001f0000U
#define WURX_WURX0_2__TOO_HI__READ(src) (((uint32_t)(src) & 0x001f0000U) >> 16)
#define WURX_WURX0_2__TOO_HI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define WURX_WURX0_2__TOO_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define WURX_WURX0_2__TOO_HI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define WURX_WURX0_2__TOO_HI__RESET_VALUE                           0x0000000aU
/** @} */

/* macros for field corr_length */
/**
 * @defgroup pmu_wurx_regs_core_corr_length_field corr_length_field
 * @brief macros for field corr_length
 * @details number of symbols in one ID
 * @{
 */
#define WURX_WURX0_2__CORR_LENGTH__SHIFT                                     21
#define WURX_WURX0_2__CORR_LENGTH__WIDTH                                      6
#define WURX_WURX0_2__CORR_LENGTH__MASK                             0x07e00000U
#define WURX_WURX0_2__CORR_LENGTH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07e00000U) >> 21)
#define WURX_WURX0_2__CORR_LENGTH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x07e00000U)
#define WURX_WURX0_2__CORR_LENGTH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07e00000U) | (((uint32_t)(src) <<\
                    21) & 0x07e00000U)
#define WURX_WURX0_2__CORR_LENGTH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x07e00000U)))
#define WURX_WURX0_2__CORR_LENGTH__RESET_VALUE                      0x00000020U
/** @} */

/* macros for field thr_length */
/**
 * @defgroup pmu_wurx_regs_core_thr_length_field thr_length_field
 * @brief macros for field thr_length
 * @details how many sybmols to adjust threshold on, thr_length = 1: 2 symbols
 * @{
 */
#define WURX_WURX0_2__THR_LENGTH__SHIFT                                      27
#define WURX_WURX0_2__THR_LENGTH__WIDTH                                       4
#define WURX_WURX0_2__THR_LENGTH__MASK                              0x78000000U
#define WURX_WURX0_2__THR_LENGTH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x78000000U) >> 27)
#define WURX_WURX0_2__THR_LENGTH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x78000000U)
#define WURX_WURX0_2__THR_LENGTH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x78000000U) | (((uint32_t)(src) <<\
                    27) & 0x78000000U)
#define WURX_WURX0_2__THR_LENGTH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x78000000U)))
#define WURX_WURX0_2__THR_LENGTH__RESET_VALUE                       0x00000001U
/** @} */
#define WURX_WURX0_2__TYPE                                             uint32_t
#define WURX_WURX0_2__READ                                          0x7fffffffU
#define WURX_WURX0_2__WRITE                                         0x7fffffffU
#define WURX_WURX0_2__PRESERVED                                     0x00000000U
#define WURX_WURX0_2__RESET_VALUE                                   0x0c0a515fU

#endif /* __WURX_WURX0_2_MACRO__ */

/** @} end of wurx0_2 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx0_3 */
/**
 * @defgroup pmu_wurx_regs_core_wurx0_3 wurx0_3
 * @brief Wake-up RX settings, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX0_3_MACRO__
#define __WURX_WURX0_3_MACRO__

/* macros for field energy_toolow */
/**
 * @defgroup pmu_wurx_regs_core_energy_toolow_field energy_toolow_field
 * @brief macros for field energy_toolow
 * @details received energy less than this --> decrease threshold
 * @{
 */
#define WURX_WURX0_3__ENERGY_TOOLOW__SHIFT                                    0
#define WURX_WURX0_3__ENERGY_TOOLOW__WIDTH                                    9
#define WURX_WURX0_3__ENERGY_TOOLOW__MASK                           0x000001ffU
#define WURX_WURX0_3__ENERGY_TOOLOW__READ(src)  ((uint32_t)(src) & 0x000001ffU)
#define WURX_WURX0_3__ENERGY_TOOLOW__WRITE(src) ((uint32_t)(src) & 0x000001ffU)
#define WURX_WURX0_3__ENERGY_TOOLOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define WURX_WURX0_3__ENERGY_TOOLOW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
#define WURX_WURX0_3__ENERGY_TOOLOW__RESET_VALUE                    0x00000004U
/** @} */

/* macros for field energy_toohigh */
/**
 * @defgroup pmu_wurx_regs_core_energy_toohigh_field energy_toohigh_field
 * @brief macros for field energy_toohigh
 * @details received energy more than this --> increase threshold
 * @{
 */
#define WURX_WURX0_3__ENERGY_TOOHIGH__SHIFT                                   9
#define WURX_WURX0_3__ENERGY_TOOHIGH__WIDTH                                  10
#define WURX_WURX0_3__ENERGY_TOOHIGH__MASK                          0x0007fe00U
#define WURX_WURX0_3__ENERGY_TOOHIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007fe00U) >> 9)
#define WURX_WURX0_3__ENERGY_TOOHIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0007fe00U)
#define WURX_WURX0_3__ENERGY_TOOHIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0007fe00U)
#define WURX_WURX0_3__ENERGY_TOOHIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0007fe00U)))
#define WURX_WURX0_3__ENERGY_TOOHIGH__RESET_VALUE                   0x00000006U
/** @} */

/* macros for field sym1_threshold */
/**
 * @defgroup pmu_wurx_regs_core_sym1_threshold_field sym1_threshold_field
 * @brief macros for field sym1_threshold
 * @details number of counts above this means symbol 1 is detected
 * @{
 */
#define WURX_WURX0_3__SYM1_THRESHOLD__SHIFT                                  19
#define WURX_WURX0_3__SYM1_THRESHOLD__WIDTH                                  10
#define WURX_WURX0_3__SYM1_THRESHOLD__MASK                          0x1ff80000U
#define WURX_WURX0_3__SYM1_THRESHOLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1ff80000U) >> 19)
#define WURX_WURX0_3__SYM1_THRESHOLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x1ff80000U)
#define WURX_WURX0_3__SYM1_THRESHOLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1ff80000U) | (((uint32_t)(src) <<\
                    19) & 0x1ff80000U)
#define WURX_WURX0_3__SYM1_THRESHOLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x1ff80000U)))
#define WURX_WURX0_3__SYM1_THRESHOLD__RESET_VALUE                   0x00000002U
/** @} */

/* macros for field clk_freq */
/**
 * @defgroup pmu_wurx_regs_core_clk_freq_field clk_freq_field
 * @brief macros for field clk_freq
 * @details 0 - 16KHz, 1- 32KHz
 * @{
 */
#define WURX_WURX0_3__CLK_FREQ__SHIFT                                        29
#define WURX_WURX0_3__CLK_FREQ__WIDTH                                         1
#define WURX_WURX0_3__CLK_FREQ__MASK                                0x20000000U
#define WURX_WURX0_3__CLK_FREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define WURX_WURX0_3__CLK_FREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define WURX_WURX0_3__CLK_FREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define WURX_WURX0_3__CLK_FREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define WURX_WURX0_3__CLK_FREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define WURX_WURX0_3__CLK_FREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define WURX_WURX0_3__CLK_FREQ__RESET_VALUE                         0x00000001U
/** @} */
#define WURX_WURX0_3__TYPE                                             uint32_t
#define WURX_WURX0_3__READ                                          0x3fffffffU
#define WURX_WURX0_3__WRITE                                         0x3fffffffU
#define WURX_WURX0_3__PRESERVED                                     0x00000000U
#define WURX_WURX0_3__RESET_VALUE                                   0x20100c04U

#endif /* __WURX_WURX0_3_MACRO__ */

/** @} end of wurx0_3 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx0_4 */
/**
 * @defgroup pmu_wurx_regs_core_wurx0_4 wurx0_4
 * @brief Wake-up RX settings, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX0_4_MACRO__
#define __WURX_WURX0_4_MACRO__

/* macros for field timer_max */
/**
 * @defgroup pmu_wurx_regs_core_timer_max_field timer_max_field
 * @brief macros for field timer_max
 * @details number of cycles in one symbol period - 1
 * @{
 */
#define WURX_WURX0_4__TIMER_MAX__SHIFT                                        0
#define WURX_WURX0_4__TIMER_MAX__WIDTH                                       10
#define WURX_WURX0_4__TIMER_MAX__MASK                               0x000003ffU
#define WURX_WURX0_4__TIMER_MAX__READ(src)      ((uint32_t)(src) & 0x000003ffU)
#define WURX_WURX0_4__TIMER_MAX__WRITE(src)     ((uint32_t)(src) & 0x000003ffU)
#define WURX_WURX0_4__TIMER_MAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define WURX_WURX0_4__TIMER_MAX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define WURX_WURX0_4__TIMER_MAX__RESET_VALUE                        0x0000000fU
/** @} */

/* macros for field sym_silent_thr */
/**
 * @defgroup pmu_wurx_regs_core_sym_silent_thr_field sym_silent_thr_field
 * @brief macros for field sym_silent_thr
 * @details number of consecutive 0's considered as noise in a sym window
 * @{
 */
#define WURX_WURX0_4__SYM_SILENT_THR__SHIFT                                  10
#define WURX_WURX0_4__SYM_SILENT_THR__WIDTH                                   5
#define WURX_WURX0_4__SYM_SILENT_THR__MASK                          0x00007c00U
#define WURX_WURX0_4__SYM_SILENT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WURX_WURX0_4__SYM_SILENT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WURX_WURX0_4__SYM_SILENT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WURX_WURX0_4__SYM_SILENT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WURX_WURX0_4__SYM_SILENT_THR__RESET_VALUE                   0x00000008U
/** @} */

/* macros for field init_cal_step */
/**
 * @defgroup pmu_wurx_regs_core_init_cal_step_field init_cal_step_field
 * @brief macros for field init_cal_step
 * @details initial cal step
 * @{
 */
#define WURX_WURX0_4__INIT_CAL_STEP__SHIFT                                   15
#define WURX_WURX0_4__INIT_CAL_STEP__WIDTH                                    9
#define WURX_WURX0_4__INIT_CAL_STEP__MASK                           0x00ff8000U
#define WURX_WURX0_4__INIT_CAL_STEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff8000U) >> 15)
#define WURX_WURX0_4__INIT_CAL_STEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00ff8000U)
#define WURX_WURX0_4__INIT_CAL_STEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff8000U) | (((uint32_t)(src) <<\
                    15) & 0x00ff8000U)
#define WURX_WURX0_4__INIT_CAL_STEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00ff8000U)))
#define WURX_WURX0_4__INIT_CAL_STEP__RESET_VALUE                    0x00000100U
/** @} */

/* macros for field cal_silent_thr */
/**
 * @defgroup pmu_wurx_regs_core_cal_silent_thr_field cal_silent_thr_field
 * @brief macros for field cal_silent_thr
 * @details number of consecutive 0's considered as noise in a thr window
 * @{
 */
#define WURX_WURX0_4__CAL_SILENT_THR__SHIFT                                  24
#define WURX_WURX0_4__CAL_SILENT_THR__WIDTH                                   7
#define WURX_WURX0_4__CAL_SILENT_THR__MASK                          0x7f000000U
#define WURX_WURX0_4__CAL_SILENT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7f000000U) >> 24)
#define WURX_WURX0_4__CAL_SILENT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x7f000000U)
#define WURX_WURX0_4__CAL_SILENT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7f000000U) | (((uint32_t)(src) <<\
                    24) & 0x7f000000U)
#define WURX_WURX0_4__CAL_SILENT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x7f000000U)))
#define WURX_WURX0_4__CAL_SILENT_THR__RESET_VALUE                   0x00000008U
/** @} */
#define WURX_WURX0_4__TYPE                                             uint32_t
#define WURX_WURX0_4__READ                                          0x7fffffffU
#define WURX_WURX0_4__WRITE                                         0x7fffffffU
#define WURX_WURX0_4__PRESERVED                                     0x00000000U
#define WURX_WURX0_4__RESET_VALUE                                   0x0880200fU

#endif /* __WURX_WURX0_4_MACRO__ */

/** @} end of wurx0_4 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx1_0 */
/**
 * @defgroup pmu_wurx_regs_core_wurx1_0 wurx1_0
 * @brief Wake-up RX unique ID, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX1_0_MACRO__
#define __WURX_WURX1_0_MACRO__

/* macros for field uid */
/**
 * @defgroup pmu_wurx_regs_core_uid_field uid_field
 * @brief macros for field uid
 * @details User ID, upper 16 bits for group ID, lower 16 bits for user ID
 * @{
 */
#define WURX_WURX1_0__UID__SHIFT                                              0
#define WURX_WURX1_0__UID__WIDTH                                             32
#define WURX_WURX1_0__UID__MASK                                     0xffffffffU
#define WURX_WURX1_0__UID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX1_0__UID__WRITE(src)           ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX1_0__UID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WURX_WURX1_0__UID__VERIFY(src)    (!(((uint32_t)(src) & ~0xffffffffU)))
#define WURX_WURX1_0__UID__RESET_VALUE                              0xaaaaaaaaU
/** @} */
#define WURX_WURX1_0__TYPE                                             uint32_t
#define WURX_WURX1_0__READ                                          0xffffffffU
#define WURX_WURX1_0__WRITE                                         0xffffffffU
#define WURX_WURX1_0__PRESERVED                                     0x00000000U
#define WURX_WURX1_0__RESET_VALUE                                   0xaaaaaaaaU

#endif /* __WURX_WURX1_0_MACRO__ */

/** @} end of wurx1_0 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx1_1 */
/**
 * @defgroup pmu_wurx_regs_core_wurx1_1 wurx1_1
 * @brief Wake-up RX global ID, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX1_1_MACRO__
#define __WURX_WURX1_1_MACRO__

/* macros for field gid */
/**
 * @defgroup pmu_wurx_regs_core_gid_field gid_field
 * @brief macros for field gid
 * @details Global ID
 * @{
 */
#define WURX_WURX1_1__GID__SHIFT                                              0
#define WURX_WURX1_1__GID__WIDTH                                             32
#define WURX_WURX1_1__GID__MASK                                     0xffffffffU
#define WURX_WURX1_1__GID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX1_1__GID__WRITE(src)           ((uint32_t)(src) & 0xffffffffU)
#define WURX_WURX1_1__GID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WURX_WURX1_1__GID__VERIFY(src)    (!(((uint32_t)(src) & ~0xffffffffU)))
#define WURX_WURX1_1__GID__RESET_VALUE                              0xffffffffU
/** @} */
#define WURX_WURX1_1__TYPE                                             uint32_t
#define WURX_WURX1_1__READ                                          0xffffffffU
#define WURX_WURX1_1__WRITE                                         0xffffffffU
#define WURX_WURX1_1__PRESERVED                                     0x00000000U
#define WURX_WURX1_1__RESET_VALUE                                   0xffffffffU

#endif /* __WURX_WURX1_1_MACRO__ */

/** @} end of wurx1_1 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx1_2 */
/**
 * @defgroup pmu_wurx_regs_core_wurx1_2 wurx1_2
 * @brief Wake-up RX settings, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX1_2_MACRO__
#define __WURX_WURX1_2_MACRO__

/* macros for field err_threshold */
/**
 * @defgroup pmu_wurx_regs_core_err_threshold_field err_threshold_field
 * @brief macros for field err_threshold
 * @details number of bits of error between RX ID and detected ID
 * @{
 */
#define WURX_WURX1_2__ERR_THRESHOLD__SHIFT                                    0
#define WURX_WURX1_2__ERR_THRESHOLD__WIDTH                                    6
#define WURX_WURX1_2__ERR_THRESHOLD__MASK                           0x0000003fU
#define WURX_WURX1_2__ERR_THRESHOLD__READ(src)  ((uint32_t)(src) & 0x0000003fU)
#define WURX_WURX1_2__ERR_THRESHOLD__WRITE(src) ((uint32_t)(src) & 0x0000003fU)
#define WURX_WURX1_2__ERR_THRESHOLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define WURX_WURX1_2__ERR_THRESHOLD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define WURX_WURX1_2__ERR_THRESHOLD__RESET_VALUE                    0x0000001fU
/** @} */

/* macros for field too_lo1 */
/**
 * @defgroup pmu_wurx_regs_core_too_lo1_field too_lo1_field
 * @brief macros for field too_lo1
 * @details number of samples that threshold is too low before linear increase in cal
 * @{
 */
#define WURX_WURX1_2__TOO_LO1__SHIFT                                          6
#define WURX_WURX1_2__TOO_LO1__WIDTH                                          5
#define WURX_WURX1_2__TOO_LO1__MASK                                 0x000007c0U
#define WURX_WURX1_2__TOO_LO1__READ(src) (((uint32_t)(src) & 0x000007c0U) >> 6)
#define WURX_WURX1_2__TOO_LO1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000007c0U)
#define WURX_WURX1_2__TOO_LO1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007c0U) | (((uint32_t)(src) <<\
                    6) & 0x000007c0U)
#define WURX_WURX1_2__TOO_LO1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000007c0U)))
#define WURX_WURX1_2__TOO_LO1__RESET_VALUE                          0x00000005U
/** @} */

/* macros for field too_lo2 */
/**
 * @defgroup pmu_wurx_regs_core_too_lo2_field too_lo2_field
 * @brief macros for field too_lo2
 * @details number of samples that threshold is too low before binary cal
 * @{
 */
#define WURX_WURX1_2__TOO_LO2__SHIFT                                         11
#define WURX_WURX1_2__TOO_LO2__WIDTH                                          5
#define WURX_WURX1_2__TOO_LO2__MASK                                 0x0000f800U
#define WURX_WURX1_2__TOO_LO2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f800U) >> 11)
#define WURX_WURX1_2__TOO_LO2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0000f800U)
#define WURX_WURX1_2__TOO_LO2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f800U) | (((uint32_t)(src) <<\
                    11) & 0x0000f800U)
#define WURX_WURX1_2__TOO_LO2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0000f800U)))
#define WURX_WURX1_2__TOO_LO2__RESET_VALUE                          0x0000000aU
/** @} */

/* macros for field too_hi */
/**
 * @defgroup pmu_wurx_regs_core_too_hi_field too_hi_field
 * @brief macros for field too_hi
 * @details number of samples that threshold is too high before binary cal
 * @{
 */
#define WURX_WURX1_2__TOO_HI__SHIFT                                          16
#define WURX_WURX1_2__TOO_HI__WIDTH                                           5
#define WURX_WURX1_2__TOO_HI__MASK                                  0x001f0000U
#define WURX_WURX1_2__TOO_HI__READ(src) (((uint32_t)(src) & 0x001f0000U) >> 16)
#define WURX_WURX1_2__TOO_HI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define WURX_WURX1_2__TOO_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define WURX_WURX1_2__TOO_HI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define WURX_WURX1_2__TOO_HI__RESET_VALUE                           0x0000000aU
/** @} */

/* macros for field corr_length */
/**
 * @defgroup pmu_wurx_regs_core_corr_length_field corr_length_field
 * @brief macros for field corr_length
 * @details number of symbols in one ID
 * @{
 */
#define WURX_WURX1_2__CORR_LENGTH__SHIFT                                     21
#define WURX_WURX1_2__CORR_LENGTH__WIDTH                                      6
#define WURX_WURX1_2__CORR_LENGTH__MASK                             0x07e00000U
#define WURX_WURX1_2__CORR_LENGTH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07e00000U) >> 21)
#define WURX_WURX1_2__CORR_LENGTH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x07e00000U)
#define WURX_WURX1_2__CORR_LENGTH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07e00000U) | (((uint32_t)(src) <<\
                    21) & 0x07e00000U)
#define WURX_WURX1_2__CORR_LENGTH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x07e00000U)))
#define WURX_WURX1_2__CORR_LENGTH__RESET_VALUE                      0x00000020U
/** @} */

/* macros for field thr_length */
/**
 * @defgroup pmu_wurx_regs_core_thr_length_field thr_length_field
 * @brief macros for field thr_length
 * @details how many sybmols to adjust threshold on, thr_length = 1: 2 symbols
 * @{
 */
#define WURX_WURX1_2__THR_LENGTH__SHIFT                                      27
#define WURX_WURX1_2__THR_LENGTH__WIDTH                                       4
#define WURX_WURX1_2__THR_LENGTH__MASK                              0x78000000U
#define WURX_WURX1_2__THR_LENGTH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x78000000U) >> 27)
#define WURX_WURX1_2__THR_LENGTH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x78000000U)
#define WURX_WURX1_2__THR_LENGTH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x78000000U) | (((uint32_t)(src) <<\
                    27) & 0x78000000U)
#define WURX_WURX1_2__THR_LENGTH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x78000000U)))
#define WURX_WURX1_2__THR_LENGTH__RESET_VALUE                       0x00000001U
/** @} */
#define WURX_WURX1_2__TYPE                                             uint32_t
#define WURX_WURX1_2__READ                                          0x7fffffffU
#define WURX_WURX1_2__WRITE                                         0x7fffffffU
#define WURX_WURX1_2__PRESERVED                                     0x00000000U
#define WURX_WURX1_2__RESET_VALUE                                   0x0c0a515fU

#endif /* __WURX_WURX1_2_MACRO__ */

/** @} end of wurx1_2 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx1_3 */
/**
 * @defgroup pmu_wurx_regs_core_wurx1_3 wurx1_3
 * @brief Wake-up RX settings, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX1_3_MACRO__
#define __WURX_WURX1_3_MACRO__

/* macros for field energy_toolow */
/**
 * @defgroup pmu_wurx_regs_core_energy_toolow_field energy_toolow_field
 * @brief macros for field energy_toolow
 * @details received energy less than this --> decrease threshold
 * @{
 */
#define WURX_WURX1_3__ENERGY_TOOLOW__SHIFT                                    0
#define WURX_WURX1_3__ENERGY_TOOLOW__WIDTH                                    9
#define WURX_WURX1_3__ENERGY_TOOLOW__MASK                           0x000001ffU
#define WURX_WURX1_3__ENERGY_TOOLOW__READ(src)  ((uint32_t)(src) & 0x000001ffU)
#define WURX_WURX1_3__ENERGY_TOOLOW__WRITE(src) ((uint32_t)(src) & 0x000001ffU)
#define WURX_WURX1_3__ENERGY_TOOLOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define WURX_WURX1_3__ENERGY_TOOLOW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
#define WURX_WURX1_3__ENERGY_TOOLOW__RESET_VALUE                    0x00000004U
/** @} */

/* macros for field energy_toohigh */
/**
 * @defgroup pmu_wurx_regs_core_energy_toohigh_field energy_toohigh_field
 * @brief macros for field energy_toohigh
 * @details received energy more than this --> increase threshold
 * @{
 */
#define WURX_WURX1_3__ENERGY_TOOHIGH__SHIFT                                   9
#define WURX_WURX1_3__ENERGY_TOOHIGH__WIDTH                                  10
#define WURX_WURX1_3__ENERGY_TOOHIGH__MASK                          0x0007fe00U
#define WURX_WURX1_3__ENERGY_TOOHIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007fe00U) >> 9)
#define WURX_WURX1_3__ENERGY_TOOHIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0007fe00U)
#define WURX_WURX1_3__ENERGY_TOOHIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0007fe00U)
#define WURX_WURX1_3__ENERGY_TOOHIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0007fe00U)))
#define WURX_WURX1_3__ENERGY_TOOHIGH__RESET_VALUE                   0x00000006U
/** @} */

/* macros for field sym1_threshold */
/**
 * @defgroup pmu_wurx_regs_core_sym1_threshold_field sym1_threshold_field
 * @brief macros for field sym1_threshold
 * @details number of counts above this means symbol 1 is detected
 * @{
 */
#define WURX_WURX1_3__SYM1_THRESHOLD__SHIFT                                  19
#define WURX_WURX1_3__SYM1_THRESHOLD__WIDTH                                  10
#define WURX_WURX1_3__SYM1_THRESHOLD__MASK                          0x1ff80000U
#define WURX_WURX1_3__SYM1_THRESHOLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1ff80000U) >> 19)
#define WURX_WURX1_3__SYM1_THRESHOLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x1ff80000U)
#define WURX_WURX1_3__SYM1_THRESHOLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1ff80000U) | (((uint32_t)(src) <<\
                    19) & 0x1ff80000U)
#define WURX_WURX1_3__SYM1_THRESHOLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x1ff80000U)))
#define WURX_WURX1_3__SYM1_THRESHOLD__RESET_VALUE                   0x00000002U
/** @} */

/* macros for field clk_freq */
/**
 * @defgroup pmu_wurx_regs_core_clk_freq_field clk_freq_field
 * @brief macros for field clk_freq
 * @details 0 - 16KHz, 1- 32KHz
 * @{
 */
#define WURX_WURX1_3__CLK_FREQ__SHIFT                                        29
#define WURX_WURX1_3__CLK_FREQ__WIDTH                                         1
#define WURX_WURX1_3__CLK_FREQ__MASK                                0x20000000U
#define WURX_WURX1_3__CLK_FREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define WURX_WURX1_3__CLK_FREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define WURX_WURX1_3__CLK_FREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define WURX_WURX1_3__CLK_FREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define WURX_WURX1_3__CLK_FREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define WURX_WURX1_3__CLK_FREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define WURX_WURX1_3__CLK_FREQ__RESET_VALUE                         0x00000001U
/** @} */
#define WURX_WURX1_3__TYPE                                             uint32_t
#define WURX_WURX1_3__READ                                          0x3fffffffU
#define WURX_WURX1_3__WRITE                                         0x3fffffffU
#define WURX_WURX1_3__PRESERVED                                     0x00000000U
#define WURX_WURX1_3__RESET_VALUE                                   0x20100c04U

#endif /* __WURX_WURX1_3_MACRO__ */

/** @} end of wurx1_3 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx1_4 */
/**
 * @defgroup pmu_wurx_regs_core_wurx1_4 wurx1_4
 * @brief Wake-up RX settings, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX1_4_MACRO__
#define __WURX_WURX1_4_MACRO__

/* macros for field timer_max */
/**
 * @defgroup pmu_wurx_regs_core_timer_max_field timer_max_field
 * @brief macros for field timer_max
 * @details number of cycles in one symbol period - 1
 * @{
 */
#define WURX_WURX1_4__TIMER_MAX__SHIFT                                        0
#define WURX_WURX1_4__TIMER_MAX__WIDTH                                       10
#define WURX_WURX1_4__TIMER_MAX__MASK                               0x000003ffU
#define WURX_WURX1_4__TIMER_MAX__READ(src)      ((uint32_t)(src) & 0x000003ffU)
#define WURX_WURX1_4__TIMER_MAX__WRITE(src)     ((uint32_t)(src) & 0x000003ffU)
#define WURX_WURX1_4__TIMER_MAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define WURX_WURX1_4__TIMER_MAX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define WURX_WURX1_4__TIMER_MAX__RESET_VALUE                        0x0000000fU
/** @} */

/* macros for field sym_silent_thr */
/**
 * @defgroup pmu_wurx_regs_core_sym_silent_thr_field sym_silent_thr_field
 * @brief macros for field sym_silent_thr
 * @details number of consecutive 0's considered as noise in a sym window
 * @{
 */
#define WURX_WURX1_4__SYM_SILENT_THR__SHIFT                                  10
#define WURX_WURX1_4__SYM_SILENT_THR__WIDTH                                   5
#define WURX_WURX1_4__SYM_SILENT_THR__MASK                          0x00007c00U
#define WURX_WURX1_4__SYM_SILENT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WURX_WURX1_4__SYM_SILENT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WURX_WURX1_4__SYM_SILENT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WURX_WURX1_4__SYM_SILENT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WURX_WURX1_4__SYM_SILENT_THR__RESET_VALUE                   0x00000008U
/** @} */

/* macros for field init_cal_step */
/**
 * @defgroup pmu_wurx_regs_core_init_cal_step_field init_cal_step_field
 * @brief macros for field init_cal_step
 * @details initial cal step
 * @{
 */
#define WURX_WURX1_4__INIT_CAL_STEP__SHIFT                                   15
#define WURX_WURX1_4__INIT_CAL_STEP__WIDTH                                    9
#define WURX_WURX1_4__INIT_CAL_STEP__MASK                           0x00ff8000U
#define WURX_WURX1_4__INIT_CAL_STEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff8000U) >> 15)
#define WURX_WURX1_4__INIT_CAL_STEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00ff8000U)
#define WURX_WURX1_4__INIT_CAL_STEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff8000U) | (((uint32_t)(src) <<\
                    15) & 0x00ff8000U)
#define WURX_WURX1_4__INIT_CAL_STEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00ff8000U)))
#define WURX_WURX1_4__INIT_CAL_STEP__RESET_VALUE                    0x00000100U
/** @} */

/* macros for field cal_silent_thr */
/**
 * @defgroup pmu_wurx_regs_core_cal_silent_thr_field cal_silent_thr_field
 * @brief macros for field cal_silent_thr
 * @details number of consecutive 0's considered as noise in a thr window
 * @{
 */
#define WURX_WURX1_4__CAL_SILENT_THR__SHIFT                                  24
#define WURX_WURX1_4__CAL_SILENT_THR__WIDTH                                   7
#define WURX_WURX1_4__CAL_SILENT_THR__MASK                          0x7f000000U
#define WURX_WURX1_4__CAL_SILENT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7f000000U) >> 24)
#define WURX_WURX1_4__CAL_SILENT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x7f000000U)
#define WURX_WURX1_4__CAL_SILENT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7f000000U) | (((uint32_t)(src) <<\
                    24) & 0x7f000000U)
#define WURX_WURX1_4__CAL_SILENT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x7f000000U)))
#define WURX_WURX1_4__CAL_SILENT_THR__RESET_VALUE                   0x00000008U
/** @} */
#define WURX_WURX1_4__TYPE                                             uint32_t
#define WURX_WURX1_4__READ                                          0x7fffffffU
#define WURX_WURX1_4__WRITE                                         0x7fffffffU
#define WURX_WURX1_4__PRESERVED                                     0x00000000U
#define WURX_WURX1_4__RESET_VALUE                                   0x0880200fU

#endif /* __WURX_WURX1_4_MACRO__ */

/** @} end of wurx1_4 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx_rb0 */
/**
 * @defgroup pmu_wurx_regs_core_wurx_rb0 wurx_rb0
 * @brief Wake-up RX read-out bits, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX_RB0_MACRO__
#define __WURX_WURX_RB0_MACRO__

/* macros for field state */
/**
 * @defgroup pmu_wurx_regs_core_state_field state_field
 * @brief macros for field state
 * @details FSM state
 * @{
 */
#define WURX_WURX_RB0__STATE__SHIFT                                           0
#define WURX_WURX_RB0__STATE__WIDTH                                           2
#define WURX_WURX_RB0__STATE__MASK                                  0x00000003U
#define WURX_WURX_RB0__STATE__READ(src)         ((uint32_t)(src) & 0x00000003U)
#define WURX_WURX_RB0__STATE__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field out_energy */
/**
 * @defgroup pmu_wurx_regs_core_out_energy_field out_energy_field
 * @brief macros for field out_energy
 * @details symbol energy
 * @{
 */
#define WURX_WURX_RB0__OUT_ENERGY__SHIFT                                      2
#define WURX_WURX_RB0__OUT_ENERGY__WIDTH                                     10
#define WURX_WURX_RB0__OUT_ENERGY__MASK                             0x00000ffcU
#define WURX_WURX_RB0__OUT_ENERGY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000ffcU) >> 2)
#define WURX_WURX_RB0__OUT_ENERGY__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field cal_step */
/**
 * @defgroup pmu_wurx_regs_core_cal_step_field cal_step_field
 * @brief macros for field cal_step
 * @details FSM binary cal step
 * @{
 */
#define WURX_WURX_RB0__CAL_STEP__SHIFT                                       12
#define WURX_WURX_RB0__CAL_STEP__WIDTH                                        9
#define WURX_WURX_RB0__CAL_STEP__MASK                               0x001ff000U
#define WURX_WURX_RB0__CAL_STEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001ff000U) >> 12)
#define WURX_WURX_RB0__CAL_STEP__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field monitor_2hi */
/**
 * @defgroup pmu_wurx_regs_core_monitor_2hi_field monitor_2hi_field
 * @brief macros for field monitor_2hi
 * @details number of consecutive symbols with too high energy
 * @{
 */
#define WURX_WURX_RB0__MONITOR_2HI__SHIFT                                    21
#define WURX_WURX_RB0__MONITOR_2HI__WIDTH                                     5
#define WURX_WURX_RB0__MONITOR_2HI__MASK                            0x03e00000U
#define WURX_WURX_RB0__MONITOR_2HI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03e00000U) >> 21)
#define WURX_WURX_RB0__MONITOR_2HI__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field monitor_2lo */
/**
 * @defgroup pmu_wurx_regs_core_monitor_2lo_field monitor_2lo_field
 * @brief macros for field monitor_2lo
 * @details number of consecutive symbols with too low energy
 * @{
 */
#define WURX_WURX_RB0__MONITOR_2LO__SHIFT                                    26
#define WURX_WURX_RB0__MONITOR_2LO__WIDTH                                     5
#define WURX_WURX_RB0__MONITOR_2LO__MASK                            0x7c000000U
#define WURX_WURX_RB0__MONITOR_2LO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7c000000U) >> 26)
#define WURX_WURX_RB0__MONITOR_2LO__RESET_VALUE                     0x00000000U
/** @} */
#define WURX_WURX_RB0__TYPE                                            uint32_t
#define WURX_WURX_RB0__READ                                         0x7fffffffU
#define WURX_WURX_RB0__PRESERVED                                    0x00000000U
#define WURX_WURX_RB0__RESET_VALUE                                  0x00000000U

#endif /* __WURX_WURX_RB0_MACRO__ */

/** @} end of wurx_rb0 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx_rb1 */
/**
 * @defgroup pmu_wurx_regs_core_wurx_rb1 wurx_rb1
 * @brief Wake-up RX read-out bits, algorithm 0 definitions.
 * @{
 */
#ifndef __WURX_WURX_RB1_MACRO__
#define __WURX_WURX_RB1_MACRO__

/* macros for field offset_cal */
/**
 * @defgroup pmu_wurx_regs_core_offset_cal_field offset_cal_field
 * @brief macros for field offset_cal
 * @details read back analog cal value --> make it common for both algorithms
 * @{
 */
#define WURX_WURX_RB1__OFFSET_CAL__SHIFT                                      0
#define WURX_WURX_RB1__OFFSET_CAL__WIDTH                                      8
#define WURX_WURX_RB1__OFFSET_CAL__MASK                             0x000000ffU
#define WURX_WURX_RB1__OFFSET_CAL__READ(src)    ((uint32_t)(src) & 0x000000ffU)
#define WURX_WURX_RB1__OFFSET_CAL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field analog_cal */
/**
 * @defgroup pmu_wurx_regs_core_analog_cal_field analog_cal_field
 * @brief macros for field analog_cal
 * @details readback
 * @{
 */
#define WURX_WURX_RB1__ANALOG_CAL__SHIFT                                      8
#define WURX_WURX_RB1__ANALOG_CAL__WIDTH                                      9
#define WURX_WURX_RB1__ANALOG_CAL__MASK                             0x0001ff00U
#define WURX_WURX_RB1__ANALOG_CAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001ff00U) >> 8)
#define WURX_WURX_RB1__ANALOG_CAL__RESET_VALUE                      0x00000000U
/** @} */
#define WURX_WURX_RB1__TYPE                                            uint32_t
#define WURX_WURX_RB1__READ                                         0x0001ffffU
#define WURX_WURX_RB1__PRESERVED                                    0x00000000U
#define WURX_WURX_RB1__RESET_VALUE                                  0x00000000U

#endif /* __WURX_WURX_RB1_MACRO__ */

/** @} end of wurx_rb1 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx_rb2 */
/**
 * @defgroup pmu_wurx_regs_core_wurx_rb2 wurx_rb2
 * @brief Wake-up RX read-out bits definitions.
 * @{
 */
#ifndef __WURX_WURX_RB2_MACRO__
#define __WURX_WURX_RB2_MACRO__

/* macros for field cnt_det0 */
/**
 * @defgroup pmu_wurx_regs_core_cnt_det0_field cnt_det0_field
 * @brief macros for field cnt_det0
 * @details number of wake_det[0]
 * @{
 */
#define WURX_WURX_RB2__CNT_DET0__SHIFT                                        0
#define WURX_WURX_RB2__CNT_DET0__WIDTH                                       10
#define WURX_WURX_RB2__CNT_DET0__MASK                               0x000003ffU
#define WURX_WURX_RB2__CNT_DET0__READ(src)      ((uint32_t)(src) & 0x000003ffU)
#define WURX_WURX_RB2__CNT_DET0__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field cnt_det1 */
/**
 * @defgroup pmu_wurx_regs_core_cnt_det1_field cnt_det1_field
 * @brief macros for field cnt_det1
 * @details number of wake_det[1]
 * @{
 */
#define WURX_WURX_RB2__CNT_DET1__SHIFT                                       10
#define WURX_WURX_RB2__CNT_DET1__WIDTH                                       10
#define WURX_WURX_RB2__CNT_DET1__MASK                               0x000ffc00U
#define WURX_WURX_RB2__CNT_DET1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define WURX_WURX_RB2__CNT_DET1__RESET_VALUE                        0x00000000U
/** @} */
#define WURX_WURX_RB2__TYPE                                            uint32_t
#define WURX_WURX_RB2__READ                                         0x000fffffU
#define WURX_WURX_RB2__PRESERVED                                    0x00000000U
#define WURX_WURX_RB2__RESET_VALUE                                  0x00000000U

#endif /* __WURX_WURX_RB2_MACRO__ */

/** @} end of wurx_rb2 */

/* macros for BlueprintGlobalNameSpace::WURX_wurx_spare */
/**
 * @defgroup pmu_wurx_regs_core_wurx_spare wurx_spare
 * @brief Wake-up RX spare bits definitions.
 * @{
 */
#ifndef __WURX_WURX_SPARE_MACRO__
#define __WURX_WURX_SPARE_MACRO__

/* macros for field wurx_dig_in_sel */
/**
 * @defgroup pmu_wurx_regs_core_wurx_dig_in_sel_field wurx_dig_in_sel_field
 * @brief macros for field wurx_dig_in_sel
 * @details select between wurx analog and rectifier output
 * @{
 */
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__SHIFT                               0
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__WIDTH                               1
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__MASK                      0x00000001U
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WURX_WURX_SPARE__WURX_DIG_IN_SEL__RESET_VALUE               0x00000001U
/** @} */

/* macros for field longRst */
/**
 * @defgroup pmu_wurx_regs_core_longRst_field longRst_field
 * @brief macros for field longRst
 * @details resets the output while the clock is low (same as sydney)
 * @{
 */
#define WURX_WURX_SPARE__LONGRST__SHIFT                                       1
#define WURX_WURX_SPARE__LONGRST__WIDTH                                       1
#define WURX_WURX_SPARE__LONGRST__MASK                              0x00000002U
#define WURX_WURX_SPARE__LONGRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WURX_WURX_SPARE__LONGRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WURX_WURX_SPARE__LONGRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WURX_WURX_SPARE__LONGRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WURX_WURX_SPARE__LONGRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WURX_WURX_SPARE__LONGRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WURX_WURX_SPARE__LONGRST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field delRst */
/**
 * @defgroup pmu_wurx_regs_core_delRst_field delRst_field
 * @brief macros for field delRst
 * @details adjusts output reset time
 * @{
 */
#define WURX_WURX_SPARE__DELRST__SHIFT                                        2
#define WURX_WURX_SPARE__DELRST__WIDTH                                        2
#define WURX_WURX_SPARE__DELRST__MASK                               0x0000000cU
#define WURX_WURX_SPARE__DELRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define WURX_WURX_SPARE__DELRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define WURX_WURX_SPARE__DELRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define WURX_WURX_SPARE__DELRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define WURX_WURX_SPARE__DELRST__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field bypassAmp */
/**
 * @defgroup pmu_wurx_regs_core_bypassAmp_field bypassAmp_field
 * @brief macros for field bypassAmp
 * @details do not use amp to bias source follower
 * @{
 */
#define WURX_WURX_SPARE__BYPASSAMP__SHIFT                                     4
#define WURX_WURX_SPARE__BYPASSAMP__WIDTH                                     1
#define WURX_WURX_SPARE__BYPASSAMP__MASK                            0x00000010U
#define WURX_WURX_SPARE__BYPASSAMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define WURX_WURX_SPARE__BYPASSAMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define WURX_WURX_SPARE__BYPASSAMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define WURX_WURX_SPARE__BYPASSAMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define WURX_WURX_SPARE__BYPASSAMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define WURX_WURX_SPARE__BYPASSAMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define WURX_WURX_SPARE__BYPASSAMP__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field settle1_reg */
/**
 * @defgroup pmu_wurx_regs_core_settle1_reg_field settle1_reg_field
 * @brief macros for field settle1_reg
 * @details wait time after power on for bias at max load
 * @{
 */
#define WURX_WURX_SPARE__SETTLE1_REG__SHIFT                                   5
#define WURX_WURX_SPARE__SETTLE1_REG__WIDTH                                   5
#define WURX_WURX_SPARE__SETTLE1_REG__MASK                          0x000003e0U
#define WURX_WURX_SPARE__SETTLE1_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define WURX_WURX_SPARE__SETTLE1_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define WURX_WURX_SPARE__SETTLE1_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define WURX_WURX_SPARE__SETTLE1_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define WURX_WURX_SPARE__SETTLE1_REG__RESET_VALUE                   0x0000000dU
/** @} */

/* macros for field settle2_reg */
/**
 * @defgroup pmu_wurx_regs_core_settle2_reg_field settle2_reg_field
 * @brief macros for field settle2_reg
 * @details wait time after power on with load and bias set to default
 * @{
 */
#define WURX_WURX_SPARE__SETTLE2_REG__SHIFT                                  10
#define WURX_WURX_SPARE__SETTLE2_REG__WIDTH                                   5
#define WURX_WURX_SPARE__SETTLE2_REG__MASK                          0x00007c00U
#define WURX_WURX_SPARE__SETTLE2_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WURX_WURX_SPARE__SETTLE2_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WURX_WURX_SPARE__SETTLE2_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WURX_WURX_SPARE__SETTLE2_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WURX_WURX_SPARE__SETTLE2_REG__RESET_VALUE                   0x00000011U
/** @} */

/* macros for field spares */
/**
 * @defgroup pmu_wurx_regs_core_spares_field spares_field
 * @brief macros for field spares
 * @details wurx local register spare bits
 * @{
 */
#define WURX_WURX_SPARE__SPARES__SHIFT                                       15
#define WURX_WURX_SPARE__SPARES__WIDTH                                       17
#define WURX_WURX_SPARE__SPARES__MASK                               0xffff8000U
#define WURX_WURX_SPARE__SPARES__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff8000U) >> 15)
#define WURX_WURX_SPARE__SPARES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0xffff8000U)
#define WURX_WURX_SPARE__SPARES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff8000U) | (((uint32_t)(src) <<\
                    15) & 0xffff8000U)
#define WURX_WURX_SPARE__SPARES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0xffff8000U)))
#define WURX_WURX_SPARE__SPARES__RESET_VALUE                        0x00000000U
/** @} */
#define WURX_WURX_SPARE__TYPE                                          uint32_t
#define WURX_WURX_SPARE__READ                                       0xffffffffU
#define WURX_WURX_SPARE__WRITE                                      0xffffffffU
#define WURX_WURX_SPARE__PRESERVED                                  0x00000000U
#define WURX_WURX_SPARE__RESET_VALUE                                0x000045a1U

#endif /* __WURX_WURX_SPARE_MACRO__ */

/** @} end of wurx_spare */

/* macros for BlueprintGlobalNameSpace::WURX_core_id */
/**
 * @defgroup pmu_wurx_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __WURX_CORE_ID_MACRO__
#define __WURX_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup pmu_wurx_regs_core_id_field id_field
 * @brief macros for field id
 * @details WURX in ASCII
 * @{
 */
#define WURX_CORE_ID__ID__SHIFT                                               0
#define WURX_CORE_ID__ID__WIDTH                                              32
#define WURX_CORE_ID__ID__MASK                                      0xffffffffU
#define WURX_CORE_ID__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define WURX_CORE_ID__ID__RESET_VALUE                               0x57555258U
/** @} */
#define WURX_CORE_ID__TYPE                                             uint32_t
#define WURX_CORE_ID__READ                                          0xffffffffU
#define WURX_CORE_ID__PRESERVED                                     0x00000000U
#define WURX_CORE_ID__RESET_VALUE                                   0x57555258U

#endif /* __WURX_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of PMU_WURX_REGS_CORE */
#endif /* __REG_PMU_WURX_REGS_CORE_H__ */
