/*                                                                           */
/* File:       pmu_pmuadc_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic pmu_pmuadc_regs_core.rdl           */
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


#ifndef __REG_PMU_PMUADC_REGS_CORE_H__
#define __REG_PMU_PMUADC_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup PMU_PMUADC_REGS_CORE pmu_pmuadc_regs_core
 * @ingroup AT_REG
 * @brief pmu_pmuadc_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::PMUADC_reg0 */
/**
 * @defgroup pmu_pmuadc_regs_core_reg0 reg0
 * @brief reg0 pmuadc registers The order of the inputs is 5: Vharv 4: Vstore 3: Vbat 2: Vatb 1: VliIon 0: Vmax definitions.
 * @{
 */
#ifndef __PMUADC_REG0_MACRO__
#define __PMUADC_REG0_MACRO__

/* macros for field settlingTime */
/**
 * @defgroup pmu_pmuadc_regs_core_settlingTime_field settlingTime_field
 * @brief macros for field settlingTime
 * @details settling time
 * @{
 */
#define PMUADC_REG0__SETTLINGTIME__SHIFT                                      0
#define PMUADC_REG0__SETTLINGTIME__WIDTH                                      7
#define PMUADC_REG0__SETTLINGTIME__MASK                             0x0000007fU
#define PMUADC_REG0__SETTLINGTIME__READ(src)    ((uint32_t)(src) & 0x0000007fU)
#define PMUADC_REG0__SETTLINGTIME__WRITE(src)   ((uint32_t)(src) & 0x0000007fU)
#define PMUADC_REG0__SETTLINGTIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define PMUADC_REG0__SETTLINGTIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define PMUADC_REG0__SETTLINGTIME__RESET_VALUE                      0x00000007U
/** @} */

/* macros for field inputSettlingTime */
/**
 * @defgroup pmu_pmuadc_regs_core_inputSettlingTime_field inputSettlingTime_field
 * @brief macros for field inputSettlingTime
 * @details settling time
 * @{
 */
#define PMUADC_REG0__INPUTSETTLINGTIME__SHIFT                                 7
#define PMUADC_REG0__INPUTSETTLINGTIME__WIDTH                                 7
#define PMUADC_REG0__INPUTSETTLINGTIME__MASK                        0x00003f80U
#define PMUADC_REG0__INPUTSETTLINGTIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define PMUADC_REG0__INPUTSETTLINGTIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define PMUADC_REG0__INPUTSETTLINGTIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define PMUADC_REG0__INPUTSETTLINGTIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define PMUADC_REG0__INPUTSETTLINGTIME__RESET_VALUE                 0x00000009U
/** @} */

/* macros for field longSettlingTime */
/**
 * @defgroup pmu_pmuadc_regs_core_longSettlingTime_field longSettlingTime_field
 * @brief macros for field longSettlingTime
 * @details settling time
 * @{
 */
#define PMUADC_REG0__LONGSETTLINGTIME__SHIFT                                 14
#define PMUADC_REG0__LONGSETTLINGTIME__WIDTH                                  7
#define PMUADC_REG0__LONGSETTLINGTIME__MASK                         0x001fc000U
#define PMUADC_REG0__LONGSETTLINGTIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define PMUADC_REG0__LONGSETTLINGTIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define PMUADC_REG0__LONGSETTLINGTIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define PMUADC_REG0__LONGSETTLINGTIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define PMUADC_REG0__LONGSETTLINGTIME__RESET_VALUE                  0x0000000eU
/** @} */

/* macros for field longInputSettlingTime */
/**
 * @defgroup pmu_pmuadc_regs_core_longInputSettlingTime_field longInputSettlingTime_field
 * @brief macros for field longInputSettlingTime
 * @details settling time
 * @{
 */
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__SHIFT                            21
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__WIDTH                             7
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__MASK                    0x0fe00000U
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fe00000U) >> 21)
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x0fe00000U)
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fe00000U) | (((uint32_t)(src) <<\
                    21) & 0x0fe00000U)
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x0fe00000U)))
#define PMUADC_REG0__LONGINPUTSETTLINGTIME__RESET_VALUE             0x00000022U
/** @} */

/* macros for field clkFixed */
/**
 * @defgroup pmu_pmuadc_regs_core_clkFixed_field clkFixed_field
 * @brief macros for field clkFixed
 * @details clock fixed time
 * @{
 */
#define PMUADC_REG0__CLKFIXED__SHIFT                                         28
#define PMUADC_REG0__CLKFIXED__WIDTH                                          2
#define PMUADC_REG0__CLKFIXED__MASK                                 0x30000000U
#define PMUADC_REG0__CLKFIXED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define PMUADC_REG0__CLKFIXED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define PMUADC_REG0__CLKFIXED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define PMUADC_REG0__CLKFIXED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define PMUADC_REG0__CLKFIXED__RESET_VALUE                          0x00000001U
/** @} */
#define PMUADC_REG0__TYPE                                              uint32_t
#define PMUADC_REG0__READ                                           0x3fffffffU
#define PMUADC_REG0__WRITE                                          0x3fffffffU
#define PMUADC_REG0__PRESERVED                                      0x00000000U
#define PMUADC_REG0__RESET_VALUE                                    0x14438487U

#endif /* __PMUADC_REG0_MACRO__ */

/** @} end of reg0 */

/* macros for BlueprintGlobalNameSpace::PMUADC_main1 */
/**
 * @defgroup pmu_pmuadc_regs_core_main1 main1
 * @brief reg registers definitions.
 * @{
 */
#ifndef __PMUADC_MAIN1_MACRO__
#define __PMUADC_MAIN1_MACRO__

/* macros for field clkUnitDel1 */
/**
 * @defgroup pmu_pmuadc_regs_core_clkUnitDel1_field clkUnitDel1_field
 * @brief macros for field clkUnitDel1
 * @details delay used in the clock fixed time
 * @{
 */
#define PMUADC_MAIN1__CLKUNITDEL1__SHIFT                                      0
#define PMUADC_MAIN1__CLKUNITDEL1__WIDTH                                      3
#define PMUADC_MAIN1__CLKUNITDEL1__MASK                             0x00000007U
#define PMUADC_MAIN1__CLKUNITDEL1__READ(src)    ((uint32_t)(src) & 0x00000007U)
#define PMUADC_MAIN1__CLKUNITDEL1__WRITE(src)   ((uint32_t)(src) & 0x00000007U)
#define PMUADC_MAIN1__CLKUNITDEL1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define PMUADC_MAIN1__CLKUNITDEL1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define PMUADC_MAIN1__CLKUNITDEL1__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field clkUnitDel2 */
/**
 * @defgroup pmu_pmuadc_regs_core_clkUnitDel2_field clkUnitDel2_field
 * @brief macros for field clkUnitDel2
 * @details delay used in the clock extra high time
 * @{
 */
#define PMUADC_MAIN1__CLKUNITDEL2__SHIFT                                      3
#define PMUADC_MAIN1__CLKUNITDEL2__WIDTH                                      5
#define PMUADC_MAIN1__CLKUNITDEL2__MASK                             0x000000f8U
#define PMUADC_MAIN1__CLKUNITDEL2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f8U) >> 3)
#define PMUADC_MAIN1__CLKUNITDEL2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x000000f8U)
#define PMUADC_MAIN1__CLKUNITDEL2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f8U) | (((uint32_t)(src) <<\
                    3) & 0x000000f8U)
#define PMUADC_MAIN1__CLKUNITDEL2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x000000f8U)))
#define PMUADC_MAIN1__CLKUNITDEL2__RESET_VALUE                      0x0000000fU
/** @} */

/* macros for field clockTest */
/**
 * @defgroup pmu_pmuadc_regs_core_clockTest_field clockTest_field
 * @brief macros for field clockTest
 * @details connects the clock to the analog bus
 * @{
 */
#define PMUADC_MAIN1__CLOCKTEST__SHIFT                                        8
#define PMUADC_MAIN1__CLOCKTEST__WIDTH                                        1
#define PMUADC_MAIN1__CLOCKTEST__MASK                               0x00000100U
#define PMUADC_MAIN1__CLOCKTEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMUADC_MAIN1__CLOCKTEST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMUADC_MAIN1__CLOCKTEST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMUADC_MAIN1__CLOCKTEST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMUADC_MAIN1__CLOCKTEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMUADC_MAIN1__CLOCKTEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMUADC_MAIN1__CLOCKTEST__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field measEnable_ovr */
/**
 * @defgroup pmu_pmuadc_regs_core_measEnable_ovr_field measEnable_ovr_field
 * @brief macros for field measEnable_ovr
 * @details Enable measurement override
 * @{
 */
#define PMUADC_MAIN1__MEASENABLE_OVR__SHIFT                                   9
#define PMUADC_MAIN1__MEASENABLE_OVR__WIDTH                                   1
#define PMUADC_MAIN1__MEASENABLE_OVR__MASK                          0x00000200U
#define PMUADC_MAIN1__MEASENABLE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMUADC_MAIN1__MEASENABLE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMUADC_MAIN1__MEASENABLE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMUADC_MAIN1__MEASENABLE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMUADC_MAIN1__MEASENABLE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMUADC_MAIN1__MEASENABLE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMUADC_MAIN1__MEASENABLE_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field measEnable_ovrVal */
/**
 * @defgroup pmu_pmuadc_regs_core_measEnable_ovrVal_field measEnable_ovrVal_field
 * @brief macros for field measEnable_ovrVal
 * @details Enable measurement override values
 * @{
 */
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__SHIFT                               10
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__WIDTH                                6
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__MASK                       0x0000fc00U
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define PMUADC_MAIN1__MEASENABLE_OVRVAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field freeze */
/**
 * @defgroup pmu_pmuadc_regs_core_freeze_field freeze_field
 * @brief macros for field freeze
 * @details Freeze pmuadc operation
 * @{
 */
#define PMUADC_MAIN1__FREEZE__SHIFT                                          16
#define PMUADC_MAIN1__FREEZE__WIDTH                                           1
#define PMUADC_MAIN1__FREEZE__MASK                                  0x00010000U
#define PMUADC_MAIN1__FREEZE__READ(src) (((uint32_t)(src) & 0x00010000U) >> 16)
#define PMUADC_MAIN1__FREEZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMUADC_MAIN1__FREEZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMUADC_MAIN1__FREEZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMUADC_MAIN1__FREEZE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMUADC_MAIN1__FREEZE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMUADC_MAIN1__FREEZE__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field gate32K */
/**
 * @defgroup pmu_pmuadc_regs_core_gate32K_field gate32K_field
 * @brief macros for field gate32K
 * @details 32K input clock gating
 * @{
 */
#define PMUADC_MAIN1__GATE32K__SHIFT                                         17
#define PMUADC_MAIN1__GATE32K__WIDTH                                          1
#define PMUADC_MAIN1__GATE32K__MASK                                 0x00020000U
#define PMUADC_MAIN1__GATE32K__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMUADC_MAIN1__GATE32K__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMUADC_MAIN1__GATE32K__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMUADC_MAIN1__GATE32K__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMUADC_MAIN1__GATE32K__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMUADC_MAIN1__GATE32K__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMUADC_MAIN1__GATE32K__RESET_VALUE                          0x00000000U
/** @} */
#define PMUADC_MAIN1__TYPE                                             uint32_t
#define PMUADC_MAIN1__READ                                          0x0003ffffU
#define PMUADC_MAIN1__WRITE                                         0x0003ffffU
#define PMUADC_MAIN1__PRESERVED                                     0x00000000U
#define PMUADC_MAIN1__RESET_VALUE                                   0x00000079U

#endif /* __PMUADC_MAIN1_MACRO__ */

/** @} end of main1 */

/* macros for BlueprintGlobalNameSpace::PMUADC_pmuadc_ctrlr */
/**
 * @defgroup pmu_pmuadc_regs_core_pmuadc_ctrlr pmuadc_ctrlr
 * @brief pmuadc controller registers definitions.
 * @{
 */
#ifndef __PMUADC_PMUADC_CTRLR_MACRO__
#define __PMUADC_PMUADC_CTRLR_MACRO__

/* macros for field measEnableSet_ovr */
/**
 * @defgroup pmu_pmuadc_regs_core_measEnableSet_ovr_field measEnableSet_ovr_field
 * @brief macros for field measEnableSet_ovr
 * @details Enable measurement override for each channel
 * @{
 */
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__SHIFT                         0
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__WIDTH                         6
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__MASK                0x0000003fU
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVR__RESET_VALUE         0x00000000U
/** @} */

/* macros for field measEnableSet_ovrVal */
/**
 * @defgroup pmu_pmuadc_regs_core_measEnableSet_ovrVal_field measEnableSet_ovrVal_field
 * @brief macros for field measEnableSet_ovrVal
 * @details Enable measurement override values
 * @{
 */
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__SHIFT                      6
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__WIDTH                      6
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__MASK             0x00000fc0U
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define PMUADC_PMUADC_CTRLR__MEASENABLESET_OVRVAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field lowVmax_ovr */
/**
 * @defgroup pmu_pmuadc_regs_core_lowVmax_ovr_field lowVmax_ovr_field
 * @brief macros for field lowVmax_ovr
 * @details Override lowVmax control
 * @{
 */
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__SHIFT                              12
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__WIDTH                               1
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__MASK                      0x00001000U
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field lowVmax_ovrVal */
/**
 * @defgroup pmu_pmuadc_regs_core_lowVmax_ovrVal_field lowVmax_ovrVal_field
 * @brief macros for field lowVmax_ovrVal
 * @details Override value for lowVmax
 * @{
 */
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__SHIFT                           13
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__WIDTH                            1
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__MASK                   0x00002000U
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMUADC_PMUADC_CTRLR__LOWVMAX_OVRVAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field alwaysFinish */
/**
 * @defgroup pmu_pmuadc_regs_core_alwaysFinish_field alwaysFinish_field
 * @brief macros for field alwaysFinish
 * @details Extend clock cycle for slow processing
 * @{
 */
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__SHIFT                             14
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__WIDTH                              1
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__MASK                     0x00004000U
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMUADC_PMUADC_CTRLR__ALWAYSFINISH__RESET_VALUE              0x00000001U
/** @} */
#define PMUADC_PMUADC_CTRLR__TYPE                                      uint32_t
#define PMUADC_PMUADC_CTRLR__READ                                   0x00007fffU
#define PMUADC_PMUADC_CTRLR__WRITE                                  0x00007fffU
#define PMUADC_PMUADC_CTRLR__PRESERVED                              0x00000000U
#define PMUADC_PMUADC_CTRLR__RESET_VALUE                            0x00004000U

#endif /* __PMUADC_PMUADC_CTRLR_MACRO__ */

/** @} end of pmuadc_ctrlr */

/* macros for BlueprintGlobalNameSpace::PMUADC_meas_period0 */
/**
 * @defgroup pmu_pmuadc_regs_core_meas_period0 meas_period0
 * @brief pmuadc measurement period setting registers definitions.
 * @{
 */
#ifndef __PMUADC_MEAS_PERIOD0_MACRO__
#define __PMUADC_MEAS_PERIOD0_MACRO__

/* macros for field x32pstate_VMAX */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VMAX_field x32pstate_VMAX_field
 * @brief macros for field x32pstate_VMAX
 * @details VMAX measurement period setting, period = 31.25uS*2^(X+1)
 * @{
 */
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__SHIFT                            0
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__WIDTH                            8
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__MASK                   0x000000ffU
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VMAX__RESET_VALUE            0x0000000bU
/** @} */

/* macros for field x32pstate_VLI */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VLI_field x32pstate_VLI_field
 * @brief macros for field x32pstate_VLI
 * @details VLI measurement period setting, period = 31.25uS*2^(X+1)
 * @{
 */
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__SHIFT                             8
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__WIDTH                             8
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__MASK                    0x0000ff00U
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VLI__RESET_VALUE             0x00000008U
/** @} */

/* macros for field x32pstate_VATB */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VATB_field x32pstate_VATB_field
 * @brief macros for field x32pstate_VATB
 * @details VATB measurement period setting, no measurement in default when set to larger than 16
 * @{
 */
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__SHIFT                           16
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__WIDTH                            8
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__MASK                   0x00ff0000U
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VATB__RESET_VALUE            0x000000ffU
/** @} */

/* macros for field x32pstate_VBAT_0 */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VBAT_0_field x32pstate_VBAT_0_field
 * @brief macros for field x32pstate_VBAT_0
 * @details VBAT measurement period setting for active state, period = 31.25uS*2^(X+1)
 * @{
 */
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__SHIFT                         24
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__WIDTH                          8
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__MASK                 0xff000000U
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define PMUADC_MEAS_PERIOD0__X32PSTATE_VBAT_0__RESET_VALUE          0x00000001U
/** @} */
#define PMUADC_MEAS_PERIOD0__TYPE                                      uint32_t
#define PMUADC_MEAS_PERIOD0__READ                                   0xffffffffU
#define PMUADC_MEAS_PERIOD0__WRITE                                  0xffffffffU
#define PMUADC_MEAS_PERIOD0__PRESERVED                              0x00000000U
#define PMUADC_MEAS_PERIOD0__RESET_VALUE                            0x01ff080bU

#endif /* __PMUADC_MEAS_PERIOD0_MACRO__ */

/** @} end of meas_period0 */

/* macros for BlueprintGlobalNameSpace::PMUADC_meas_period1 */
/**
 * @defgroup pmu_pmuadc_regs_core_meas_period1 meas_period1
 * @brief pmuadc measurement period setting registers definitions.
 * @{
 */
#ifndef __PMUADC_MEAS_PERIOD1_MACRO__
#define __PMUADC_MEAS_PERIOD1_MACRO__

/* macros for field x32pstate_VBAT_1 */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VBAT_1_field x32pstate_VBAT_1_field
 * @brief macros for field x32pstate_VBAT_1
 * @details VBAT measurement period setting for non-active state, period = 31.25uS*2^(X+1)
 * @{
 */
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__SHIFT                          0
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__WIDTH                          8
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__MASK                 0x000000ffU
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VBAT_1__RESET_VALUE          0x0000000dU
/** @} */

/* macros for field x32pstate_VSTO_0 */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VSTO_0_field x32pstate_VSTO_0_field
 * @brief macros for field x32pstate_VSTO_0
 * @details VSTO measurement period setting for active state, period = 31.25uS*2^(X+1)
 * @{
 */
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__SHIFT                          8
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__WIDTH                          8
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__MASK                 0x0000ff00U
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_0__RESET_VALUE          0x00000004U
/** @} */

/* macros for field x32pstate_VSTO_1 */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VSTO_1_field x32pstate_VSTO_1_field
 * @brief macros for field x32pstate_VSTO_1
 * @details VSTO measurement period setting for non-active state, period = 31.25uS*2^(X+1)
 * @{
 */
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__SHIFT                         16
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__WIDTH                          8
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__MASK                 0x00ff0000U
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VSTO_1__RESET_VALUE          0x0000000bU
/** @} */

/* macros for field x32pstate_VHARV */
/**
 * @defgroup pmu_pmuadc_regs_core_x32pstate_VHARV_field x32pstate_VHARV_field
 * @brief macros for field x32pstate_VHARV
 * @details VHARV measurement period setting for active state, period = 31.25uS*2^(X+1)
 * @{
 */
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__SHIFT                          24
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__WIDTH                           8
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__MASK                  0xff000000U
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define PMUADC_MEAS_PERIOD1__X32PSTATE_VHARV__RESET_VALUE           0x00000008U
/** @} */
#define PMUADC_MEAS_PERIOD1__TYPE                                      uint32_t
#define PMUADC_MEAS_PERIOD1__READ                                   0xffffffffU
#define PMUADC_MEAS_PERIOD1__WRITE                                  0xffffffffU
#define PMUADC_MEAS_PERIOD1__PRESERVED                              0x00000000U
#define PMUADC_MEAS_PERIOD1__RESET_VALUE                            0x080b040dU

#endif /* __PMUADC_MEAS_PERIOD1_MACRO__ */

/** @} end of meas_period1 */

/* macros for BlueprintGlobalNameSpace::PMUADC_cmpout_param_1 */
/**
 * @defgroup pmu_pmuadc_regs_core_cmpout_param_1 cmpout_param_1
 * @brief pmuadc reference parameters for swreg mode definitions.
 * @{
 */
#ifndef __PMUADC_CMPOUT_PARAM_1_MACRO__
#define __PMUADC_CMPOUT_PARAM_1_MACRO__

/* macros for field c0_bit */
/**
 * @defgroup pmu_pmuadc_regs_core_c0_bit_field c0_bit_field
 * @brief macros for field c0_bit
 * @details c0 = c0_bit*50mV
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__SHIFT                                  0
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__WIDTH                                  4
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__MASK                         0x0000000fU
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PMUADC_CMPOUT_PARAM_1__C0_BIT__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field c1_bit */
/**
 * @defgroup pmu_pmuadc_regs_core_c1_bit_field c1_bit_field
 * @brief macros for field c1_bit
 * @details c1 = 1+c1_bit/16
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__SHIFT                                  4
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__WIDTH                                  4
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__MASK                         0x000000f0U
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define PMUADC_CMPOUT_PARAM_1__C1_BIT__RESET_VALUE                  0x00000008U
/** @} */

/* macros for field c1bo_bit */
/**
 * @defgroup pmu_pmuadc_regs_core_c1bo_bit_field c1bo_bit_field
 * @brief macros for field c1bo_bit
 * @details c1bo = 1+c1bo_bit/16
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__SHIFT                                8
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__WIDTH                                4
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__MASK                       0x00000f00U
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define PMUADC_CMPOUT_PARAM_1__C1BO_BIT__RESET_VALUE                0x00000008U
/** @} */

/* macros for field c2_bit */
/**
 * @defgroup pmu_pmuadc_regs_core_c2_bit_field c2_bit_field
 * @brief macros for field c2_bit
 * @details c2 = (11+c2_bit)/16
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__SHIFT                                 12
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__WIDTH                                  2
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__MASK                         0x00003000U
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PMUADC_CMPOUT_PARAM_1__C2_BIT__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field c3_bit */
/**
 * @defgroup pmu_pmuadc_regs_core_c3_bit_field c3_bit_field
 * @brief macros for field c3_bit
 * @details c3 = (8+c3_bit)*62.5
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__SHIFT                                 14
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__WIDTH                                  3
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__MASK                         0x0001c000U
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define PMUADC_CMPOUT_PARAM_1__C3_BIT__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field cbyavdd */
/**
 * @defgroup pmu_pmuadc_regs_core_cbyavdd_field cbyavdd_field
 * @brief macros for field cbyavdd
 * @details Bypass reference voltage
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__SHIFT                                17
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__WIDTH                                 2
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__MASK                        0x00060000U
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define PMUADC_CMPOUT_PARAM_1__CBYAVDD__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field cbydvdd */
/**
 * @defgroup pmu_pmuadc_regs_core_cbydvdd_field cbydvdd_field
 * @brief macros for field cbydvdd
 * @details Bypass reference voltage
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__SHIFT                                19
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__WIDTH                                 2
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__MASK                        0x00180000U
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define PMUADC_CMPOUT_PARAM_1__CBYDVDD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field cbyvddio */
/**
 * @defgroup pmu_pmuadc_regs_core_cbyvddio_field cbyvddio_field
 * @brief macros for field cbyvddio
 * @details Bypass reference voltage
 * @{
 */
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__SHIFT                               21
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__WIDTH                                2
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__MASK                       0x00600000U
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define PMUADC_CMPOUT_PARAM_1__CBYVDDIO__RESET_VALUE                0x00000001U
/** @} */
#define PMUADC_CMPOUT_PARAM_1__TYPE                                    uint32_t
#define PMUADC_CMPOUT_PARAM_1__READ                                 0x007fffffU
#define PMUADC_CMPOUT_PARAM_1__WRITE                                0x007fffffU
#define PMUADC_CMPOUT_PARAM_1__PRESERVED                            0x00000000U
#define PMUADC_CMPOUT_PARAM_1__RESET_VALUE                          0x00221881U

#endif /* __PMUADC_CMPOUT_PARAM_1_MACRO__ */

/** @} end of cmpout_param_1 */

/* macros for BlueprintGlobalNameSpace::PMUADC_cmpout_param_2 */
/**
 * @defgroup pmu_pmuadc_regs_core_cmpout_param_2 cmpout_param_2
 * @brief pmuadc reference parameter for comparator output definitions.
 * @{
 */
#ifndef __PMUADC_CMPOUT_PARAM_2_MACRO__
#define __PMUADC_CMPOUT_PARAM_2_MACRO__

/* macros for field ctr_VrefstoGoodToStart */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_VrefstoGoodToStart_field ctr_VrefstoGoodToStart_field
 * @brief macros for field ctr_VrefstoGoodToStart
 * @details Compares Vstore with VrefstoGoodToStart
 * @{
 */
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__SHIFT                  0
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__WIDTH                  2
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__MASK         0x00000003U
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFSTOGOODTOSTART__RESET_VALUE  0x00000001U
/** @} */

/* macros for field ctr_vbattovrvoltage */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_vbattovrvoltage_field ctr_vbattovrvoltage_field
 * @brief macros for field ctr_vbattovrvoltage
 * @details Compares Vbat with VrefBATovrvoltage
 * @{
 */
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__SHIFT                     7
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__WIDTH                     7
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__MASK            0x00003f80U
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define PMUADC_CMPOUT_PARAM_2__CTR_VBATTOVRVOLTAGE__RESET_VALUE     0x0000005cU
/** @} */

/* macros for field ctr_VrefVSTObrownOut */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_VrefVSTObrownOut_field ctr_VrefVSTObrownOut_field
 * @brief macros for field ctr_VrefVSTObrownOut
 * @details Comares Vstore with VrefVSTOBrownOut
 * @{
 */
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__SHIFT                   14
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__WIDTH                    5
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__MASK           0x0007c000U
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007c000U) >> 14)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0007c000U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007c000U) | (((uint32_t)(src) <<\
                    14) & 0x0007c000U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0007c000U)))
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOBROWNOUT__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ctr_VrefVSTOovrvoltage */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_VrefVSTOovrvoltage_field ctr_VrefVSTOovrvoltage_field
 * @brief macros for field ctr_VrefVSTOovrvoltage
 * @details Compares Vstore with VrefVSTOovrvoltage
 * @{
 */
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__SHIFT                 19
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__WIDTH                  5
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__MASK         0x00f80000U
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f80000U) >> 19)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00f80000U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f80000U) | (((uint32_t)(src) <<\
                    19) & 0x00f80000U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00f80000U)))
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVSTOOVRVOLTAGE__RESET_VALUE  0x0000001eU
/** @} */

/* macros for field ctr_VrefVBATLIbypass */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_VrefVBATLIbypass_field ctr_VrefVBATLIbypass_field
 * @brief macros for field ctr_VrefVBATLIbypass
 * @details VBATLI level at which to bypass VBATLI to VBATT, 3.25V to 3.4V in 50mV steps
 * @{
 */
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__SHIFT                   24
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__WIDTH                    2
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__MASK           0x03000000U
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define PMUADC_CMPOUT_PARAM_2__CTR_VREFVBATLIBYPASS__RESET_VALUE    0x00000001U
/** @} */
#define PMUADC_CMPOUT_PARAM_2__TYPE                                    uint32_t
#define PMUADC_CMPOUT_PARAM_2__READ                                 0x03ffff83U
#define PMUADC_CMPOUT_PARAM_2__WRITE                                0x03ffff83U
#define PMUADC_CMPOUT_PARAM_2__PRESERVED                            0x00000000U
#define PMUADC_CMPOUT_PARAM_2__RESET_VALUE                          0x01f02e01U

#endif /* __PMUADC_CMPOUT_PARAM_2_MACRO__ */

/** @} end of cmpout_param_2 */

/* macros for BlueprintGlobalNameSpace::PMUADC_cmpout_param_3 */
/**
 * @defgroup pmu_pmuadc_regs_core_cmpout_param_3 cmpout_param_3
 * @brief pmuadc reference parameter for comparator output definitions.
 * @{
 */
#ifndef __PMUADC_CMPOUT_PARAM_3_MACRO__
#define __PMUADC_CMPOUT_PARAM_3_MACRO__

/* macros for field ctr_vbatgoodtoTX */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_vbatgoodtoTX_field ctr_vbatgoodtoTX_field
 * @brief macros for field ctr_vbatgoodtoTX
 * @details Good to TX with vbat
 * @{
 */
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__SHIFT                        0
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__WIDTH                        3
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__MASK               0x00000007U
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODTOTX__RESET_VALUE        0x00000004U
/** @} */

/* macros for field ctr_vstogoodtoTX */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_vstogoodtoTX_field ctr_vstogoodtoTX_field
 * @brief macros for field ctr_vstogoodtoTX
 * @details Good to TX with vsto
 * @{
 */
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__SHIFT                        3
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__WIDTH                        3
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__MASK               0x00000038U
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODTOTX__RESET_VALUE        0x00000004U
/** @} */

/* macros for field ctr_vbatgoodforcpu */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_vbatgoodforcpu_field ctr_vbatgoodforcpu_field
 * @brief macros for field ctr_vbatgoodforcpu
 * @details Good for cpu with vbat
 * @{
 */
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__SHIFT                      6
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__WIDTH                      3
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__MASK             0x000001c0U
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATGOODFORCPU__RESET_VALUE      0x00000004U
/** @} */

/* macros for field ctr_vstogoodforcpu */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_vstogoodforcpu_field ctr_vstogoodforcpu_field
 * @brief macros for field ctr_vstogoodforcpu
 * @details Good for cpu with vsto
 * @{
 */
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__SHIFT                      9
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__WIDTH                      3
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__MASK             0x00000e00U
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define PMUADC_CMPOUT_PARAM_3__CTR_VSTOGOODFORCPU__RESET_VALUE      0x00000004U
/** @} */

/* macros for field ctr_atb_compthreshold */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_atb_compthreshold_field ctr_atb_compthreshold_field
 * @brief macros for field ctr_atb_compthreshold
 * @details Compares ATB with reference voltage
 * @{
 */
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__SHIFT                  12
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__WIDTH                   3
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__MASK          0x00007000U
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define PMUADC_CMPOUT_PARAM_3__CTR_ATB_COMPTHRESHOLD__RESET_VALUE   0x00000004U
/** @} */

/* macros for field c2socoff_bit */
/**
 * @defgroup pmu_pmuadc_regs_core_c2socoff_bit_field c2socoff_bit_field
 * @brief macros for field c2socoff_bit
 * @details vbat measure for soc off mode 1
 * @{
 */
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__SHIFT                           15
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__WIDTH                            2
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__MASK                   0x00018000U
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00018000U) >> 15)
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00018000U)
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00018000U) | (((uint32_t)(src) <<\
                    15) & 0x00018000U)
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00018000U)))
#define PMUADC_CMPOUT_PARAM_3__C2SOCOFF_BIT__RESET_VALUE            0x00000002U
/** @} */

/* macros for field ctr_vbatsocoff2 */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_vbatsocoff2_field ctr_vbatsocoff2_field
 * @brief macros for field ctr_vbatsocoff2
 * @details vbat measure for soc off mode 2
 * @{
 */
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__SHIFT                        17
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__WIDTH                         2
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__MASK                0x00060000U
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define PMUADC_CMPOUT_PARAM_3__CTR_VBATSOCOFF2__RESET_VALUE         0x00000002U
/** @} */
#define PMUADC_CMPOUT_PARAM_3__TYPE                                    uint32_t
#define PMUADC_CMPOUT_PARAM_3__READ                                 0x0007ffffU
#define PMUADC_CMPOUT_PARAM_3__WRITE                                0x0007ffffU
#define PMUADC_CMPOUT_PARAM_3__PRESERVED                            0x00000000U
#define PMUADC_CMPOUT_PARAM_3__RESET_VALUE                          0x00054924U

#endif /* __PMUADC_CMPOUT_PARAM_3_MACRO__ */

/** @} end of cmpout_param_3 */

/* macros for BlueprintGlobalNameSpace::PMUADC_cmpout_param_4 */
/**
 * @defgroup pmu_pmuadc_regs_core_cmpout_param_4 cmpout_param_4
 * @brief pmuadc reference parameter for comparator output definitions.
 * @{
 */
#ifndef __PMUADC_CMPOUT_PARAM_4_MACRO__
#define __PMUADC_CMPOUT_PARAM_4_MACRO__

/* macros for field ctr_dstSup1Pen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_dstSup1Pen_field ctr_dstSup1Pen_field
 * @brief macros for field ctr_dstSup1Pen
 * @details Compares vmax with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__SHIFT                          0
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__WIDTH                          3
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__MASK                 0x00000007U
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP1PEN__RESET_VALUE          0x00000004U
/** @} */

/* macros for field ctr_dstSup4Pen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_dstSup4Pen_field ctr_dstSup4Pen_field
 * @brief macros for field ctr_dstSup4Pen
 * @details Compares vmax with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__SHIFT                          3
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__WIDTH                          3
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__MASK                 0x00000038U
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSUP4PEN__RESET_VALUE          0x00000004U
/** @} */

/* macros for field ctr_dstStoreNen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_dstStoreNen_field ctr_dstStoreNen_field
 * @brief macros for field ctr_dstStoreNen
 * @details Compares Vstore with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__SHIFT                         6
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__WIDTH                         3
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__MASK                0x000001c0U
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTORENEN__RESET_VALUE         0x00000004U
/** @} */

/* macros for field ctr_dstStorePen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_dstStorePen_field ctr_dstStorePen_field
 * @brief macros for field ctr_dstStorePen
 * @details Compares Vstore with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__SHIFT                         9
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__WIDTH                         3
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__MASK                0x00000e00U
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_DSTSTOREPEN__RESET_VALUE         0x00000004U
/** @} */

/* macros for field ctr_srcHarvNen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_srcHarvNen_field ctr_srcHarvNen_field
 * @brief macros for field ctr_srcHarvNen
 * @details Compares Vharv with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__SHIFT                         12
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__WIDTH                          3
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__MASK                 0x00007000U
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVNEN__RESET_VALUE          0x00000004U
/** @} */

/* macros for field ctr_srcHarvPen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_srcHarvPen_field ctr_srcHarvPen_field
 * @brief macros for field ctr_srcHarvPen
 * @details Compares Vharv with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__SHIFT                         15
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__WIDTH                          3
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__MASK                 0x00038000U
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCHARVPEN__RESET_VALUE          0x00000004U
/** @} */

/* macros for field ctr_srcStoreNen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_srcStoreNen_field ctr_srcStoreNen_field
 * @brief macros for field ctr_srcStoreNen
 * @details Compares Vstore with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__SHIFT                        18
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__WIDTH                         3
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__MASK                0x001c0000U
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTORENEN__RESET_VALUE         0x00000004U
/** @} */

/* macros for field ctr_srcStorePen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_srcStorePen_field ctr_srcStorePen_field
 * @brief macros for field ctr_srcStorePen
 * @details Compares Vstore with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__SHIFT                        21
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__WIDTH                         3
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__MASK                0x00e00000U
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00e00000U) >> 21)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00e00000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00e00000U) | (((uint32_t)(src) <<\
                    21) & 0x00e00000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00e00000U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCSTOREPEN__RESET_VALUE         0x00000004U
/** @} */

/* macros for field ctr_srcBattNen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_srcBattNen_field ctr_srcBattNen_field
 * @brief macros for field ctr_srcBattNen
 * @details Compares Vbatt with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__SHIFT                         24
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__WIDTH                          3
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__MASK                 0x07000000U
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTNEN__RESET_VALUE          0x00000004U
/** @} */

/* macros for field ctr_srcBattPen */
/**
 * @defgroup pmu_pmuadc_regs_core_ctr_srcBattPen_field ctr_srcBattPen_field
 * @brief macros for field ctr_srcBattPen
 * @details Compares Vbatt with Vref
 * @{
 */
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__SHIFT                         27
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__WIDTH                          3
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__MASK                 0x38000000U
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x38000000U) >> 27)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x38000000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x38000000U) | (((uint32_t)(src) <<\
                    27) & 0x38000000U)
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x38000000U)))
#define PMUADC_CMPOUT_PARAM_4__CTR_SRCBATTPEN__RESET_VALUE          0x00000004U
/** @} */
#define PMUADC_CMPOUT_PARAM_4__TYPE                                    uint32_t
#define PMUADC_CMPOUT_PARAM_4__READ                                 0x3fffffffU
#define PMUADC_CMPOUT_PARAM_4__WRITE                                0x3fffffffU
#define PMUADC_CMPOUT_PARAM_4__PRESERVED                            0x00000000U
#define PMUADC_CMPOUT_PARAM_4__RESET_VALUE                          0x24924924U

#endif /* __PMUADC_CMPOUT_PARAM_4_MACRO__ */

/** @} end of cmpout_param_4 */

/* macros for BlueprintGlobalNameSpace::PMUADC_pmuadc_readout0 */
/**
 * @defgroup pmu_pmuadc_regs_core_pmuadc_readout0 pmuadc_readout0
 * @brief readback registers definitions.
 * @{
 */
#ifndef __PMUADC_PMUADC_READOUT0_MACRO__
#define __PMUADC_PMUADC_READOUT0_MACRO__

/* macros for field measComplete */
/**
 * @defgroup pmu_pmuadc_regs_core_measComplete_field measComplete_field
 * @brief macros for field measComplete
 * @details indicates which measurements where completed
 * @{
 */
#define PMUADC_PMUADC_READOUT0__MEASCOMPLETE__SHIFT                           0
#define PMUADC_PMUADC_READOUT0__MEASCOMPLETE__WIDTH                           6
#define PMUADC_PMUADC_READOUT0__MEASCOMPLETE__MASK                  0x0000003fU
#define PMUADC_PMUADC_READOUT0__MEASCOMPLETE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PMUADC_PMUADC_READOUT0__MEASCOMPLETE__RESET_VALUE           0x00000000U
/** @} */

/* macros for field finished */
/**
 * @defgroup pmu_pmuadc_regs_core_finished_field finished_field
 * @brief macros for field finished
 * @details 1 if all measurements were completed
 * @{
 */
#define PMUADC_PMUADC_READOUT0__FINISHED__SHIFT                               6
#define PMUADC_PMUADC_READOUT0__FINISHED__WIDTH                               1
#define PMUADC_PMUADC_READOUT0__FINISHED__MASK                      0x00000040U
#define PMUADC_PMUADC_READOUT0__FINISHED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMUADC_PMUADC_READOUT0__FINISHED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMUADC_PMUADC_READOUT0__FINISHED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMUADC_PMUADC_READOUT0__FINISHED__RESET_VALUE               0x00000001U
/** @} */

/* macros for field result_Vharv */
/**
 * @defgroup pmu_pmuadc_regs_core_result_Vharv_field result_Vharv_field
 * @brief macros for field result_Vharv
 * @details result Vharv
 * @{
 */
#define PMUADC_PMUADC_READOUT0__RESULT_VHARV__SHIFT                           7
#define PMUADC_PMUADC_READOUT0__RESULT_VHARV__WIDTH                           7
#define PMUADC_PMUADC_READOUT0__RESULT_VHARV__MASK                  0x00003f80U
#define PMUADC_PMUADC_READOUT0__RESULT_VHARV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define PMUADC_PMUADC_READOUT0__RESULT_VHARV__RESET_VALUE           0x00000000U
/** @} */

/* macros for field result_Vstore */
/**
 * @defgroup pmu_pmuadc_regs_core_result_Vstore_field result_Vstore_field
 * @brief macros for field result_Vstore
 * @details result Vstore
 * @{
 */
#define PMUADC_PMUADC_READOUT0__RESULT_VSTORE__SHIFT                         14
#define PMUADC_PMUADC_READOUT0__RESULT_VSTORE__WIDTH                          7
#define PMUADC_PMUADC_READOUT0__RESULT_VSTORE__MASK                 0x001fc000U
#define PMUADC_PMUADC_READOUT0__RESULT_VSTORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define PMUADC_PMUADC_READOUT0__RESULT_VSTORE__RESET_VALUE          0x00000000U
/** @} */

/* macros for field result_Vbat */
/**
 * @defgroup pmu_pmuadc_regs_core_result_Vbat_field result_Vbat_field
 * @brief macros for field result_Vbat
 * @details result Vbat
 * @{
 */
#define PMUADC_PMUADC_READOUT0__RESULT_VBAT__SHIFT                           21
#define PMUADC_PMUADC_READOUT0__RESULT_VBAT__WIDTH                            7
#define PMUADC_PMUADC_READOUT0__RESULT_VBAT__MASK                   0x0fe00000U
#define PMUADC_PMUADC_READOUT0__RESULT_VBAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fe00000U) >> 21)
#define PMUADC_PMUADC_READOUT0__RESULT_VBAT__RESET_VALUE            0x00000000U
/** @} */
#define PMUADC_PMUADC_READOUT0__TYPE                                   uint32_t
#define PMUADC_PMUADC_READOUT0__READ                                0x0fffffffU
#define PMUADC_PMUADC_READOUT0__PRESERVED                           0x00000000U
#define PMUADC_PMUADC_READOUT0__RESET_VALUE                         0x00000040U

#endif /* __PMUADC_PMUADC_READOUT0_MACRO__ */

/** @} end of pmuadc_readout0 */

/* macros for BlueprintGlobalNameSpace::PMUADC_pmuadc_readout1 */
/**
 * @defgroup pmu_pmuadc_regs_core_pmuadc_readout1 pmuadc_readout1
 * @brief pmuadc readout bits definitions.
 * @{
 */
#ifndef __PMUADC_PMUADC_READOUT1_MACRO__
#define __PMUADC_PMUADC_READOUT1_MACRO__

/* macros for field result_Vatb */
/**
 * @defgroup pmu_pmuadc_regs_core_result_Vatb_field result_Vatb_field
 * @brief macros for field result_Vatb
 * @details result Vatb
 * @{
 */
#define PMUADC_PMUADC_READOUT1__RESULT_VATB__SHIFT                            0
#define PMUADC_PMUADC_READOUT1__RESULT_VATB__WIDTH                            7
#define PMUADC_PMUADC_READOUT1__RESULT_VATB__MASK                   0x0000007fU
#define PMUADC_PMUADC_READOUT1__RESULT_VATB__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define PMUADC_PMUADC_READOUT1__RESULT_VATB__RESET_VALUE            0x00000000U
/** @} */

/* macros for field result_Vliion */
/**
 * @defgroup pmu_pmuadc_regs_core_result_Vliion_field result_Vliion_field
 * @brief macros for field result_Vliion
 * @details result Vliion
 * @{
 */
#define PMUADC_PMUADC_READOUT1__RESULT_VLIION__SHIFT                          7
#define PMUADC_PMUADC_READOUT1__RESULT_VLIION__WIDTH                          7
#define PMUADC_PMUADC_READOUT1__RESULT_VLIION__MASK                 0x00003f80U
#define PMUADC_PMUADC_READOUT1__RESULT_VLIION__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define PMUADC_PMUADC_READOUT1__RESULT_VLIION__RESET_VALUE          0x00000000U
/** @} */

/* macros for field result_Vmax */
/**
 * @defgroup pmu_pmuadc_regs_core_result_Vmax_field result_Vmax_field
 * @brief macros for field result_Vmax
 * @details result Vmax
 * @{
 */
#define PMUADC_PMUADC_READOUT1__RESULT_VMAX__SHIFT                           14
#define PMUADC_PMUADC_READOUT1__RESULT_VMAX__WIDTH                            7
#define PMUADC_PMUADC_READOUT1__RESULT_VMAX__MASK                   0x001fc000U
#define PMUADC_PMUADC_READOUT1__RESULT_VMAX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define PMUADC_PMUADC_READOUT1__RESULT_VMAX__RESET_VALUE            0x00000000U
/** @} */
#define PMUADC_PMUADC_READOUT1__TYPE                                   uint32_t
#define PMUADC_PMUADC_READOUT1__READ                                0x001fffffU
#define PMUADC_PMUADC_READOUT1__PRESERVED                           0x00000000U
#define PMUADC_PMUADC_READOUT1__RESET_VALUE                         0x00000000U

#endif /* __PMUADC_PMUADC_READOUT1_MACRO__ */

/** @} end of pmuadc_readout1 */

/* macros for BlueprintGlobalNameSpace::PMUADC_core_id */
/**
 * @defgroup pmu_pmuadc_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __PMUADC_CORE_ID_MACRO__
#define __PMUADC_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup pmu_pmuadc_regs_core_id_field id_field
 * @brief macros for field id
 * @details PADC in ASCII (PMU ADC)
 * @{
 */
#define PMUADC_CORE_ID__ID__SHIFT                                             0
#define PMUADC_CORE_ID__ID__WIDTH                                            32
#define PMUADC_CORE_ID__ID__MASK                                    0xffffffffU
#define PMUADC_CORE_ID__ID__READ(src)           ((uint32_t)(src) & 0xffffffffU)
#define PMUADC_CORE_ID__ID__RESET_VALUE                             0x50414443U
/** @} */
#define PMUADC_CORE_ID__TYPE                                           uint32_t
#define PMUADC_CORE_ID__READ                                        0xffffffffU
#define PMUADC_CORE_ID__PRESERVED                                   0x00000000U
#define PMUADC_CORE_ID__RESET_VALUE                                 0x50414443U

#endif /* __PMUADC_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of PMU_PMUADC_REGS_CORE */
#endif /* __REG_PMU_PMUADC_REGS_CORE_H__ */
