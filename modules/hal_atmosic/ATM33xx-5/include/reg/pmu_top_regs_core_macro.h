/*                                                                           */
/* File:       pmu_top_regs_core_macro.h                                     */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic pmu_top_regs_core.rdl              */
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


#ifndef __REG_PMU_TOP_REGS_CORE_H__
#define __REG_PMU_TOP_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup PMU_TOP_REGS_CORE pmu_top_regs_core
 * @ingroup AT_REG
 * @brief pmu_top_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu0 */
/**
 * @defgroup pmu_top_regs_core_pmu0 pmu0
 * @brief timer_target_lsb - written by software definitions.
 * @{
 */
#ifndef __PMU_PMU0_MACRO__
#define __PMU_PMU0_MACRO__

/* macros for field timer_target_lsb */
/**
 * @defgroup pmu_top_regs_core_timer_target_lsb_field timer_target_lsb_field
 * @brief macros for field timer_target_lsb
 * @details written by software, target value to wake up from in soc-off mode  pmu starts from 0 and counts 32KHz clock cycles until it reaches this value to come out of soc-off mode if how2wkup reg is set to 1xx  31 lsb bits
 * @{
 */
#define PMU_PMU0__TIMER_TARGET_LSB__SHIFT                                     0
#define PMU_PMU0__TIMER_TARGET_LSB__WIDTH                                    32
#define PMU_PMU0__TIMER_TARGET_LSB__MASK                            0xffffffffU
#define PMU_PMU0__TIMER_TARGET_LSB__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define PMU_PMU0__TIMER_TARGET_LSB__WRITE(src)  ((uint32_t)(src) & 0xffffffffU)
#define PMU_PMU0__TIMER_TARGET_LSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PMU_PMU0__TIMER_TARGET_LSB__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PMU_PMU0__TIMER_TARGET_LSB__RESET_VALUE                     0x00000001U
/** @} */
#define PMU_PMU0__TYPE                                                 uint32_t
#define PMU_PMU0__READ                                              0xffffffffU
#define PMU_PMU0__WRITE                                             0xffffffffU
#define PMU_PMU0__PRESERVED                                         0x00000000U
#define PMU_PMU0__RESET_VALUE                                       0x00000001U

#endif /* __PMU_PMU0_MACRO__ */

/** @} end of pmu0 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu1 */
/**
 * @defgroup pmu_top_regs_core_pmu1 pmu1
 * @brief software controlled registers definitions.
 * @{
 */
#ifndef __PMU_PMU1_MACRO__
#define __PMU_PMU1_MACRO__

/* macros for field timer_target_msb */
/**
 * @defgroup pmu_top_regs_core_timer_target_msb_field timer_target_msb_field
 * @brief macros for field timer_target_msb
 * @details written by software, target value to wake up from in soc-off mode  pmu starts from 0 and counts 32KHz clock cycles until it reaches this value to come out of soc-off mode if how2wkup reg is set to 1xx  8 msb bits
 * @{
 */
#define PMU_PMU1__TIMER_TARGET_MSB__SHIFT                                     0
#define PMU_PMU1__TIMER_TARGET_MSB__WIDTH                                     8
#define PMU_PMU1__TIMER_TARGET_MSB__MASK                            0x000000ffU
#define PMU_PMU1__TIMER_TARGET_MSB__READ(src)   ((uint32_t)(src) & 0x000000ffU)
#define PMU_PMU1__TIMER_TARGET_MSB__WRITE(src)  ((uint32_t)(src) & 0x000000ffU)
#define PMU_PMU1__TIMER_TARGET_MSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PMU_PMU1__TIMER_TARGET_MSB__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PMU_PMU1__TIMER_TARGET_MSB__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field how2wkup_pin */
/**
 * @defgroup pmu_top_regs_core_how2wkup_pin_field how2wkup_pin_field
 * @brief macros for field how2wkup_pin
 * @details written by software - xx1: pin, x1x: lpcomp, 1xx: timer, write back to 0 after determining wake up cause to clear, write desired bits to 1 before entering low-power state, wait at least two 32KHz cycles between clearing and setting
 * @{
 */
#define PMU_PMU1__HOW2WKUP_PIN__SHIFT                                         8
#define PMU_PMU1__HOW2WKUP_PIN__WIDTH                                         1
#define PMU_PMU1__HOW2WKUP_PIN__MASK                                0x00000100U
#define PMU_PMU1__HOW2WKUP_PIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU1__HOW2WKUP_PIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU1__HOW2WKUP_PIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU1__HOW2WKUP_PIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU1__HOW2WKUP_PIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU1__HOW2WKUP_PIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU1__HOW2WKUP_PIN__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field how2wkup_lpcomp */
/**
 * @defgroup pmu_top_regs_core_how2wkup_lpcomp_field how2wkup_lpcomp_field
 * @brief macros for field how2wkup_lpcomp
 * @details written by software - xx1: pin, x1x: lpcomp, 1xx: timer, write back to 0 after determining wake up cause to clear, write desired bits to 1 before entering low-power state, wait at least two 32KHz cycles between clearing and setting
 * @{
 */
#define PMU_PMU1__HOW2WKUP_LPCOMP__SHIFT                                      9
#define PMU_PMU1__HOW2WKUP_LPCOMP__WIDTH                                      1
#define PMU_PMU1__HOW2WKUP_LPCOMP__MASK                             0x00000200U
#define PMU_PMU1__HOW2WKUP_LPCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU1__HOW2WKUP_LPCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU1__HOW2WKUP_LPCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU1__HOW2WKUP_LPCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU1__HOW2WKUP_LPCOMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU1__HOW2WKUP_LPCOMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU1__HOW2WKUP_LPCOMP__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field how2wkup_timer */
/**
 * @defgroup pmu_top_regs_core_how2wkup_timer_field how2wkup_timer_field
 * @brief macros for field how2wkup_timer
 * @details written by software - xx1: pin, x1x: lpcomp, 1xx: timer, write back to 0 after determining wake up cause to clear, write desired bits to 1 before entering low-power state, wait at least two 32KHz cycles between clearing and setting
 * @{
 */
#define PMU_PMU1__HOW2WKUP_TIMER__SHIFT                                      10
#define PMU_PMU1__HOW2WKUP_TIMER__WIDTH                                       1
#define PMU_PMU1__HOW2WKUP_TIMER__MASK                              0x00000400U
#define PMU_PMU1__HOW2WKUP_TIMER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU1__HOW2WKUP_TIMER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU1__HOW2WKUP_TIMER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU1__HOW2WKUP_TIMER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU1__HOW2WKUP_TIMER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU1__HOW2WKUP_TIMER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU1__HOW2WKUP_TIMER__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field lpcomp_in_sel */
/**
 * @defgroup pmu_top_regs_core_lpcomp_in_sel_field lpcomp_in_sel_field
 * @brief macros for field lpcomp_in_sel
 * @details 0: P3, 1: P4
 * @{
 */
#define PMU_PMU1__LPCOMP_IN_SEL__SHIFT                                       11
#define PMU_PMU1__LPCOMP_IN_SEL__WIDTH                                        1
#define PMU_PMU1__LPCOMP_IN_SEL__MASK                               0x00000800U
#define PMU_PMU1__LPCOMP_IN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU1__LPCOMP_IN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU1__LPCOMP_IN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU1__LPCOMP_IN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU1__LPCOMP_IN_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU1__LPCOMP_IN_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU1__LPCOMP_IN_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field compout_mux_sel */
/**
 * @defgroup pmu_top_regs_core_compout_mux_sel_field compout_mux_sel_field
 * @brief macros for field compout_mux_sel
 * @details select which test signal goes to pin_mux  3'b001: BrownOutVbat  3'b010: VstoreGoodtoEner  3'b011: VstoreHarvStop  3'b100: mpptstartvharv  3'b101: reconfharvstage  3'b110: lpcomp_out  3'b111: pinedge_det
 * @{
 */
#define PMU_PMU1__COMPOUT_MUX_SEL__SHIFT                                     12
#define PMU_PMU1__COMPOUT_MUX_SEL__WIDTH                                      3
#define PMU_PMU1__COMPOUT_MUX_SEL__MASK                             0x00007000U
#define PMU_PMU1__COMPOUT_MUX_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define PMU_PMU1__COMPOUT_MUX_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define PMU_PMU1__COMPOUT_MUX_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define PMU_PMU1__COMPOUT_MUX_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define PMU_PMU1__COMPOUT_MUX_SEL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field atb_pad_en */
/**
 * @defgroup pmu_top_regs_core_atb_pad_en_field atb_pad_en_field
 * @brief macros for field atb_pad_en
 * @details atb pad enable
 * @{
 */
#define PMU_PMU1__ATB_PAD_EN__SHIFT                                          15
#define PMU_PMU1__ATB_PAD_EN__WIDTH                                           1
#define PMU_PMU1__ATB_PAD_EN__MASK                                  0x00008000U
#define PMU_PMU1__ATB_PAD_EN__READ(src) (((uint32_t)(src) & 0x00008000U) >> 15)
#define PMU_PMU1__ATB_PAD_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU1__ATB_PAD_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU1__ATB_PAD_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU1__ATB_PAD_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU1__ATB_PAD_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU1__ATB_PAD_EN__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field xofaststart */
/**
 * @defgroup pmu_top_regs_core_xofaststart_field xofaststart_field
 * @brief macros for field xofaststart
 * @details enable fast start for xtal
 * @{
 */
#define PMU_PMU1__XOFASTSTART__SHIFT                                         16
#define PMU_PMU1__XOFASTSTART__WIDTH                                          3
#define PMU_PMU1__XOFASTSTART__MASK                                 0x00070000U
#define PMU_PMU1__XOFASTSTART__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define PMU_PMU1__XOFASTSTART__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define PMU_PMU1__XOFASTSTART__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define PMU_PMU1__XOFASTSTART__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define PMU_PMU1__XOFASTSTART__RESET_VALUE                          0x00000006U
/** @} */

/* macros for field xosettle */
/**
 * @defgroup pmu_top_regs_core_xosettle_field xosettle_field
 * @brief macros for field xosettle
 * @details settling time for xtal
 * @{
 */
#define PMU_PMU1__XOSETTLE__SHIFT                                            19
#define PMU_PMU1__XOSETTLE__WIDTH                                             6
#define PMU_PMU1__XOSETTLE__MASK                                    0x01f80000U
#define PMU_PMU1__XOSETTLE__READ(src)   (((uint32_t)(src) & 0x01f80000U) >> 19)
#define PMU_PMU1__XOSETTLE__WRITE(src)  (((uint32_t)(src) << 19) & 0x01f80000U)
#define PMU_PMU1__XOSETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f80000U) | (((uint32_t)(src) <<\
                    19) & 0x01f80000U)
#define PMU_PMU1__XOSETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x01f80000U)))
#define PMU_PMU1__XOSETTLE__RESET_VALUE                             0x00000010U
/** @} */

/* macros for field xtal_pwd */
/**
 * @defgroup pmu_top_regs_core_xtal_pwd_field xtal_pwd_field
 * @brief macros for field xtal_pwd
 * @details default is always on unless this is set or ext pwd is set
 * @{
 */
#define PMU_PMU1__XTAL_PWD__SHIFT                                            25
#define PMU_PMU1__XTAL_PWD__WIDTH                                             1
#define PMU_PMU1__XTAL_PWD__MASK                                    0x02000000U
#define PMU_PMU1__XTAL_PWD__READ(src)   (((uint32_t)(src) & 0x02000000U) >> 25)
#define PMU_PMU1__XTAL_PWD__WRITE(src)  (((uint32_t)(src) << 25) & 0x02000000U)
#define PMU_PMU1__XTAL_PWD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU1__XTAL_PWD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU1__XTAL_PWD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU1__XTAL_PWD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU1__XTAL_PWD__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field use16MforPSEQ */
/**
 * @defgroup pmu_top_regs_core_use16MforPSEQ_field use16MforPSEQ_field
 * @brief macros for field use16MforPSEQ
 * @details keep 16MHz on and use it as the clock source for 32KHz timers in PMU
 * @{
 */
#define PMU_PMU1__USE16MFORPSEQ__SHIFT                                       26
#define PMU_PMU1__USE16MFORPSEQ__WIDTH                                        1
#define PMU_PMU1__USE16MFORPSEQ__MASK                               0x04000000U
#define PMU_PMU1__USE16MFORPSEQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU1__USE16MFORPSEQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU1__USE16MFORPSEQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU1__USE16MFORPSEQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU1__USE16MFORPSEQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU1__USE16MFORPSEQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU1__USE16MFORPSEQ__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field doRCoscCal */
/**
 * @defgroup pmu_top_regs_core_doRCoscCal_field doRCoscCal_field
 * @brief macros for field doRCoscCal
 * @details set to 1 before entering low power state to do HW measurement in that state, clear after next wake up and read calCountRC value
 * @{
 */
#define PMU_PMU1__DORCOSCCAL__SHIFT                                          27
#define PMU_PMU1__DORCOSCCAL__WIDTH                                           1
#define PMU_PMU1__DORCOSCCAL__MASK                                  0x08000000U
#define PMU_PMU1__DORCOSCCAL__READ(src) (((uint32_t)(src) & 0x08000000U) >> 27)
#define PMU_PMU1__DORCOSCCAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU1__DORCOSCCAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU1__DORCOSCCAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU1__DORCOSCCAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU1__DORCOSCCAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU1__DORCOSCCAL__RESET_VALUE                           0x00000000U
/** @} */
#define PMU_PMU1__TYPE                                                 uint32_t
#define PMU_PMU1__READ                                              0x0fffffffU
#define PMU_PMU1__WRITE                                             0x0fffffffU
#define PMU_PMU1__PRESERVED                                         0x00000000U
#define PMU_PMU1__RESET_VALUE                                       0x00860400U

#endif /* __PMU_PMU1_MACRO__ */

/** @} end of pmu1 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu1a */
/**
 * @defgroup pmu_top_regs_core_pmu1a pmu1a
 * @brief software controlled xtal related definitions.
 * @{
 */
#ifndef __PMU_PMU1A_MACRO__
#define __PMU_PMU1A_MACRO__

/* macros for field RCoscCalPeriods */
/**
 * @defgroup pmu_top_regs_core_RCoscCalPeriods_field RCoscCalPeriods_field
 * @brief macros for field RCoscCalPeriods
 * @details how many RCosc periods to run calibration
 * @{
 */
#define PMU_PMU1A__RCOSCCALPERIODS__SHIFT                                     0
#define PMU_PMU1A__RCOSCCALPERIODS__WIDTH                                    11
#define PMU_PMU1A__RCOSCCALPERIODS__MASK                            0x000007ffU
#define PMU_PMU1A__RCOSCCALPERIODS__READ(src)   ((uint32_t)(src) & 0x000007ffU)
#define PMU_PMU1A__RCOSCCALPERIODS__WRITE(src)  ((uint32_t)(src) & 0x000007ffU)
#define PMU_PMU1A__RCOSCCALPERIODS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define PMU_PMU1A__RCOSCCALPERIODS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000007ffU)))
#define PMU_PMU1A__RCOSCCALPERIODS__RESET_VALUE                     0x00000040U
/** @} */

/* macros for field RCoscCalWait */
/**
 * @defgroup pmu_top_regs_core_RCoscCalWait_field RCoscCalWait_field
 * @brief macros for field RCoscCalWait
 * @details how long to wait for supply settling after entering low power state to start counting, ~1ms resolution
 * @{
 */
#define PMU_PMU1A__RCOSCCALWAIT__SHIFT                                       11
#define PMU_PMU1A__RCOSCCALWAIT__WIDTH                                        8
#define PMU_PMU1A__RCOSCCALWAIT__MASK                               0x0007f800U
#define PMU_PMU1A__RCOSCCALWAIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007f800U) >> 11)
#define PMU_PMU1A__RCOSCCALWAIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0007f800U)
#define PMU_PMU1A__RCOSCCALWAIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007f800U) | (((uint32_t)(src) <<\
                    11) & 0x0007f800U)
#define PMU_PMU1A__RCOSCCALWAIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0007f800U)))
#define PMU_PMU1A__RCOSCCALWAIT__RESET_VALUE                        0x00000004U
/** @} */

/* macros for field xohysn */
/**
 * @defgroup pmu_top_regs_core_xohysn_field xohysn_field
 * @brief macros for field xohysn
 * @details 32KHz RC buffer N-side hysteresis, tune to reduce frequency variation to supply sensitivity
 * @{
 */
#define PMU_PMU1A__XOHYSN__SHIFT                                             19
#define PMU_PMU1A__XOHYSN__WIDTH                                              3
#define PMU_PMU1A__XOHYSN__MASK                                     0x00380000U
#define PMU_PMU1A__XOHYSN__READ(src)    (((uint32_t)(src) & 0x00380000U) >> 19)
#define PMU_PMU1A__XOHYSN__WRITE(src)   (((uint32_t)(src) << 19) & 0x00380000U)
#define PMU_PMU1A__XOHYSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define PMU_PMU1A__XOHYSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define PMU_PMU1A__XOHYSN__RESET_VALUE                              0x00000003U
/** @} */

/* macros for field xohysp_b */
/**
 * @defgroup pmu_top_regs_core_xohysp_b_field xohysp_b_field
 * @brief macros for field xohysp_b
 * @details 32KHz RC buffer P-side hysteresis, tune to reduce frequency variation to supply sensitivity
 * @{
 */
#define PMU_PMU1A__XOHYSP_B__SHIFT                                           22
#define PMU_PMU1A__XOHYSP_B__WIDTH                                            3
#define PMU_PMU1A__XOHYSP_B__MASK                                   0x01c00000U
#define PMU_PMU1A__XOHYSP_B__READ(src)  (((uint32_t)(src) & 0x01c00000U) >> 22)
#define PMU_PMU1A__XOHYSP_B__WRITE(src) (((uint32_t)(src) << 22) & 0x01c00000U)
#define PMU_PMU1A__XOHYSP_B__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01c00000U) | (((uint32_t)(src) <<\
                    22) & 0x01c00000U)
#define PMU_PMU1A__XOHYSP_B__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x01c00000U)))
#define PMU_PMU1A__XOHYSP_B__RESET_VALUE                            0x00000004U
/** @} */
#define PMU_PMU1A__TYPE                                                uint32_t
#define PMU_PMU1A__READ                                             0x01ffffffU
#define PMU_PMU1A__WRITE                                            0x01ffffffU
#define PMU_PMU1A__PRESERVED                                        0x00000000U
#define PMU_PMU1A__RESET_VALUE                                      0x01182040U

#endif /* __PMU_PMU1A_MACRO__ */

/** @} end of pmu1a */

/* macros for BlueprintGlobalNameSpace::PMU_pmu2 */
/**
 * @defgroup pmu_top_regs_core_pmu2 pmu2
 * @brief customer writes definitions.
 * @{
 */
#ifndef __PMU_PMU2_MACRO__
#define __PMU_PMU2_MACRO__

/* macros for field xocapout */
/**
 * @defgroup pmu_top_regs_core_xocapout_field xocapout_field
 * @brief macros for field xocapout
 * @details cap on board
 * @{
 */
#define PMU_PMU2__XOCAPOUT__SHIFT                                             0
#define PMU_PMU2__XOCAPOUT__WIDTH                                             5
#define PMU_PMU2__XOCAPOUT__MASK                                    0x0000001fU
#define PMU_PMU2__XOCAPOUT__READ(src)           ((uint32_t)(src) & 0x0000001fU)
#define PMU_PMU2__XOCAPOUT__WRITE(src)          ((uint32_t)(src) & 0x0000001fU)
#define PMU_PMU2__XOCAPOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define PMU_PMU2__XOCAPOUT__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000001fU)))
#define PMU_PMU2__XOCAPOUT__RESET_VALUE                             0x0000001bU
/** @} */

/* macros for field xocapin */
/**
 * @defgroup pmu_top_regs_core_xocapin_field xocapin_field
 * @brief macros for field xocapin
 * @details cap on board
 * @{
 */
#define PMU_PMU2__XOCAPIN__SHIFT                                              5
#define PMU_PMU2__XOCAPIN__WIDTH                                              5
#define PMU_PMU2__XOCAPIN__MASK                                     0x000003e0U
#define PMU_PMU2__XOCAPIN__READ(src)     (((uint32_t)(src) & 0x000003e0U) >> 5)
#define PMU_PMU2__XOCAPIN__WRITE(src)    (((uint32_t)(src) << 5) & 0x000003e0U)
#define PMU_PMU2__XOCAPIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define PMU_PMU2__XOCAPIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define PMU_PMU2__XOCAPIN__RESET_VALUE                              0x0000001bU
/** @} */

/* macros for field RGuserconf */
/**
 * @defgroup pmu_top_regs_core_RGuserconf_field RGuserconf_field
 * @brief macros for field RGuserconf
 * @details unused
 * @{
 */
#define PMU_PMU2__RGUSERCONF__SHIFT                                          10
#define PMU_PMU2__RGUSERCONF__WIDTH                                           1
#define PMU_PMU2__RGUSERCONF__MASK                                  0x00000400U
#define PMU_PMU2__RGUSERCONF__READ(src) (((uint32_t)(src) & 0x00000400U) >> 10)
#define PMU_PMU2__RGUSERCONF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU2__RGUSERCONF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU2__RGUSERCONF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU2__RGUSERCONF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU2__RGUSERCONF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU2__RGUSERCONF__RESET_VALUE                           0x00000001U
/** @} */

/* macros for field rect_stage_default */
/**
 * @defgroup pmu_top_regs_core_rect_stage_default_field rect_stage_default_field
 * @brief macros for field rect_stage_default
 * @details default number of rectifier stages: 2^i, i=0:3
 * @{
 */
#define PMU_PMU2__RECT_STAGE_DEFAULT__SHIFT                                  11
#define PMU_PMU2__RECT_STAGE_DEFAULT__WIDTH                                   2
#define PMU_PMU2__RECT_STAGE_DEFAULT__MASK                          0x00001800U
#define PMU_PMU2__RECT_STAGE_DEFAULT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define PMU_PMU2__RECT_STAGE_DEFAULT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define PMU_PMU2__RECT_STAGE_DEFAULT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define PMU_PMU2__RECT_STAGE_DEFAULT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define PMU_PMU2__RECT_STAGE_DEFAULT__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field rect_counter_disable */
/**
 * @defgroup pmu_top_regs_core_rect_counter_disable_field rect_counter_disable_field
 * @brief macros for field rect_counter_disable
 * @details disable dynamic control of rectifier stages
 * @{
 */
#define PMU_PMU2__RECT_COUNTER_DISABLE__SHIFT                                13
#define PMU_PMU2__RECT_COUNTER_DISABLE__WIDTH                                 1
#define PMU_PMU2__RECT_COUNTER_DISABLE__MASK                        0x00002000U
#define PMU_PMU2__RECT_COUNTER_DISABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU2__RECT_COUNTER_DISABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU2__RECT_COUNTER_DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU2__RECT_COUNTER_DISABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU2__RECT_COUNTER_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU2__RECT_COUNTER_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU2__RECT_COUNTER_DISABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field disable_store */
/**
 * @defgroup pmu_top_regs_core_disable_store_field disable_store_field
 * @brief macros for field disable_store
 * @details disable store as a source
 * @{
 */
#define PMU_PMU2__DISABLE_STORE__SHIFT                                       14
#define PMU_PMU2__DISABLE_STORE__WIDTH                                        1
#define PMU_PMU2__DISABLE_STORE__MASK                               0x00004000U
#define PMU_PMU2__DISABLE_STORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU2__DISABLE_STORE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU2__DISABLE_STORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU2__DISABLE_STORE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU2__DISABLE_STORE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU2__DISABLE_STORE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU2__DISABLE_STORE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field use_ext32k */
/**
 * @defgroup pmu_top_regs_core_use_ext32k_field use_ext32k_field
 * @brief macros for field use_ext32k
 * @details use external 32K clock source
 * @{
 */
#define PMU_PMU2__USE_EXT32K__SHIFT                                          15
#define PMU_PMU2__USE_EXT32K__WIDTH                                           1
#define PMU_PMU2__USE_EXT32K__MASK                                  0x00008000U
#define PMU_PMU2__USE_EXT32K__READ(src) (((uint32_t)(src) & 0x00008000U) >> 15)
#define PMU_PMU2__USE_EXT32K__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU2__USE_EXT32K__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU2__USE_EXT32K__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU2__USE_EXT32K__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU2__USE_EXT32K__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU2__USE_EXT32K__RESET_VALUE                           0x00000000U
/** @} */
#define PMU_PMU2__TYPE                                                 uint32_t
#define PMU_PMU2__READ                                              0x0000ffffU
#define PMU_PMU2__WRITE                                             0x0000ffffU
#define PMU_PMU2__PRESERVED                                         0x00000000U
#define PMU_PMU2__RESET_VALUE                                       0x00001f7bU

#endif /* __PMU_PMU2_MACRO__ */

/** @} end of pmu2 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu2a */
/**
 * @defgroup pmu_top_regs_core_pmu2a pmu2a
 * @brief ate definitions.
 * @{
 */
#ifndef __PMU_PMU2A_MACRO__
#define __PMU_PMU2A_MACRO__

/* macros for field xoagc_en */
/**
 * @defgroup pmu_top_regs_core_xoagc_en_field xoagc_en_field
 * @brief macros for field xoagc_en
 * @details Enable 32KHz xtal AGC
 * @{
 */
#define PMU_PMU2A__XOAGC_EN__SHIFT                                            0
#define PMU_PMU2A__XOAGC_EN__WIDTH                                            1
#define PMU_PMU2A__XOAGC_EN__MASK                                   0x00000001U
#define PMU_PMU2A__XOAGC_EN__READ(src)          ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU2A__XOAGC_EN__WRITE(src)         ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU2A__XOAGC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU2A__XOAGC_EN__VERIFY(src)  (!(((uint32_t)(src) & ~0x00000001U)))
#define PMU_PMU2A__XOAGC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU2A__XOAGC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU2A__XOAGC_EN__RESET_VALUE                            0x00000001U
/** @} */

/* macros for field xobias */
/**
 * @defgroup pmu_top_regs_core_xobias_field xobias_field
 * @brief macros for field xobias
 * @details 32KHz xtal bias current or AGC target
 * @{
 */
#define PMU_PMU2A__XOBIAS__SHIFT                                              1
#define PMU_PMU2A__XOBIAS__WIDTH                                              4
#define PMU_PMU2A__XOBIAS__MASK                                     0x0000001eU
#define PMU_PMU2A__XOBIAS__READ(src)     (((uint32_t)(src) & 0x0000001eU) >> 1)
#define PMU_PMU2A__XOBIAS__WRITE(src)    (((uint32_t)(src) << 1) & 0x0000001eU)
#define PMU_PMU2A__XOBIAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001eU) | (((uint32_t)(src) <<\
                    1) & 0x0000001eU)
#define PMU_PMU2A__XOBIAS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000001eU)))
#define PMU_PMU2A__XOBIAS__RESET_VALUE                              0x0000000cU
/** @} */

/* macros for field rcosc32Kfreq */
/**
 * @defgroup pmu_top_regs_core_rcosc32Kfreq_field rcosc32Kfreq_field
 * @brief macros for field rcosc32Kfreq
 * @details 32KHz RC osc freq tuning
 * @{
 */
#define PMU_PMU2A__RCOSC32KFREQ__SHIFT                                        5
#define PMU_PMU2A__RCOSC32KFREQ__WIDTH                                        4
#define PMU_PMU2A__RCOSC32KFREQ__MASK                               0x000001e0U
#define PMU_PMU2A__RCOSC32KFREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001e0U) >> 5)
#define PMU_PMU2A__RCOSC32KFREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000001e0U)
#define PMU_PMU2A__RCOSC32KFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001e0U) | (((uint32_t)(src) <<\
                    5) & 0x000001e0U)
#define PMU_PMU2A__RCOSC32KFREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000001e0U)))
#define PMU_PMU2A__RCOSC32KFREQ__RESET_VALUE                        0x00000004U
/** @} */

/* macros for field rcosc32Kmode */
/**
 * @defgroup pmu_top_regs_core_rcosc32Kmode_field rcosc32Kmode_field
 * @brief macros for field rcosc32Kmode
 * @details 32KHz RC osc mode/topology select
 * @{
 */
#define PMU_PMU2A__RCOSC32KMODE__SHIFT                                        9
#define PMU_PMU2A__RCOSC32KMODE__WIDTH                                        1
#define PMU_PMU2A__RCOSC32KMODE__MASK                               0x00000200U
#define PMU_PMU2A__RCOSC32KMODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU2A__RCOSC32KMODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU2A__RCOSC32KMODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU2A__RCOSC32KMODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU2A__RCOSC32KMODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU2A__RCOSC32KMODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU2A__RCOSC32KMODE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field ctr_refBG_ldo */
/**
 * @defgroup pmu_top_regs_core_ctr_refBG_ldo_field ctr_refBG_ldo_field
 * @brief macros for field ctr_refBG_ldo
 * @details ref level for ldo: Vref=25*(24+i)mV, i=0:15
 * @{
 */
#define PMU_PMU2A__CTR_REFBG_LDO__SHIFT                                      10
#define PMU_PMU2A__CTR_REFBG_LDO__WIDTH                                       4
#define PMU_PMU2A__CTR_REFBG_LDO__MASK                              0x00003c00U
#define PMU_PMU2A__CTR_REFBG_LDO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003c00U) >> 10)
#define PMU_PMU2A__CTR_REFBG_LDO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define PMU_PMU2A__CTR_REFBG_LDO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define PMU_PMU2A__CTR_REFBG_LDO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define PMU_PMU2A__CTR_REFBG_LDO__RESET_VALUE                       0x00000007U
/** @} */

/* macros for field ctr_refldo */
/**
 * @defgroup pmu_top_regs_core_ctr_refldo_field ctr_refldo_field
 * @brief macros for field ctr_refldo
 * @details ref sel for ldo0: From refgen (BG/native). Use ctr_refBG_ldo to adjust1: From tracking reference
 * @{
 */
#define PMU_PMU2A__CTR_REFLDO__SHIFT                                         14
#define PMU_PMU2A__CTR_REFLDO__WIDTH                                          1
#define PMU_PMU2A__CTR_REFLDO__MASK                                 0x00004000U
#define PMU_PMU2A__CTR_REFLDO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU2A__CTR_REFLDO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU2A__CTR_REFLDO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU2A__CTR_REFLDO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU2A__CTR_REFLDO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU2A__CTR_REFLDO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU2A__CTR_REFLDO__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field ctr_refInsel_nat */
/**
 * @defgroup pmu_top_regs_core_ctr_refInsel_nat_field ctr_refInsel_nat_field
 * @brief macros for field ctr_refInsel_nat
 * @details refgen feedback tap select for native. For reference=600mV 3: 625mV reflad<25>2: 600mV reflad<24>1: 575mV reflad<23>0: 550mV reflad<22>
 * @{
 */
#define PMU_PMU2A__CTR_REFINSEL_NAT__SHIFT                                   15
#define PMU_PMU2A__CTR_REFINSEL_NAT__WIDTH                                    2
#define PMU_PMU2A__CTR_REFINSEL_NAT__MASK                           0x00018000U
#define PMU_PMU2A__CTR_REFINSEL_NAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00018000U) >> 15)
#define PMU_PMU2A__CTR_REFINSEL_NAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00018000U)
#define PMU_PMU2A__CTR_REFINSEL_NAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00018000U) | (((uint32_t)(src) <<\
                    15) & 0x00018000U)
#define PMU_PMU2A__CTR_REFINSEL_NAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00018000U)))
#define PMU_PMU2A__CTR_REFINSEL_NAT__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field ctr_refInsel_pmubg */
/**
 * @defgroup pmu_top_regs_core_ctr_refInsel_pmubg_field ctr_refInsel_pmubg_field
 * @brief macros for field ctr_refInsel_pmubg
 * @details refgen feedback tap select for main bg. For reference=600mV 3: 625mV reflad<25>2: 600mV reflad<24>1: 575mV reflad<23>0: 550mV reflad<22>
 * @{
 */
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__SHIFT                                 17
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__WIDTH                                  2
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__MASK                         0x00060000U
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define PMU_PMU2A__CTR_REFINSEL_PMUBG__RESET_VALUE                  0x00000002U
/** @} */

/* macros for field ctr_ref_vddioint */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_vddioint_field ctr_ref_vddioint_field
 * @brief macros for field ctr_ref_vddioint
 * @details internally generated vddio level. vddioint=25*(64+2*i)mV, i=0:7 for otp_vddio_range = 0, otp_noind=025*(86+2*i)mV, i=0:7 for otp_vddio_range = 1, otp_noind=025*(32+1*i)mV, i=0:7 for otp_vddio_range = 0, otp_noind=125*(43+1*i)mV, i=0:7 for otp_vddio_range = 1, otp_noind=1
 * @{
 */
#define PMU_PMU2A__CTR_REF_VDDIOINT__SHIFT                                   19
#define PMU_PMU2A__CTR_REF_VDDIOINT__WIDTH                                    3
#define PMU_PMU2A__CTR_REF_VDDIOINT__MASK                           0x00380000U
#define PMU_PMU2A__CTR_REF_VDDIOINT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00380000U) >> 19)
#define PMU_PMU2A__CTR_REF_VDDIOINT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00380000U)
#define PMU_PMU2A__CTR_REF_VDDIOINT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define PMU_PMU2A__CTR_REF_VDDIOINT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define PMU_PMU2A__CTR_REF_VDDIOINT__RESET_VALUE                    0x00000004U
/** @} */
#define PMU_PMU2A__TYPE                                                uint32_t
#define PMU_PMU2A__READ                                             0x003fffffU
#define PMU_PMU2A__WRITE                                            0x003fffffU
#define PMU_PMU2A__PRESERVED                                        0x00000000U
#define PMU_PMU2A__RESET_VALUE                                      0x00251c99U

#endif /* __PMU_PMU2A_MACRO__ */

/** @} end of pmu2a */

/* macros for BlueprintGlobalNameSpace::PMU_pmu3 */
/**
 * @defgroup pmu_top_regs_core_pmu3 pmu3
 * @brief more ate definitions.
 * @{
 */
#ifndef __PMU_PMU3_MACRO__
#define __PMU_PMU3_MACRO__

/* macros for field ctr_ref_vddaux */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_vddaux_field ctr_ref_vddaux_field
 * @brief macros for field ctr_ref_vddaux
 * @details level of aux supply. vddaux=2*25*(50+5*i)mV, i=0:22*25*66mV, i=3
 * @{
 */
#define PMU_PMU3__CTR_REF_VDDAUX__SHIFT                                       0
#define PMU_PMU3__CTR_REF_VDDAUX__WIDTH                                       2
#define PMU_PMU3__CTR_REF_VDDAUX__MASK                              0x00000003U
#define PMU_PMU3__CTR_REF_VDDAUX__READ(src)     ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU3__CTR_REF_VDDAUX__WRITE(src)    ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU3__CTR_REF_VDDAUX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PMU_PMU3__CTR_REF_VDDAUX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PMU_PMU3__CTR_REF_VDDAUX__RESET_VALUE                       0x00000003U
/** @} */

/* macros for field ctr_ref_avdd_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_avdd_active_field ctr_ref_avdd_active_field
 * @brief macros for field ctr_ref_avdd_active
 * @details avdd level active. avdd=25*(37+i)mV, i=1:725*36mV, i=0
 * @{
 */
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__SHIFT                                  2
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__WIDTH                                  3
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__MASK                         0x0000001cU
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define PMU_PMU3__CTR_REF_AVDD_ACTIVE__RESET_VALUE                  0x00000003U
/** @} */

/* macros for field ctr_ref_avdd_hibernate */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_avdd_hibernate_field ctr_ref_avdd_hibernate_field
 * @brief macros for field ctr_ref_avdd_hibernate
 * @details avdd level hibernate. avdd=25*(37+i)mV, i=1:725*36mV, i=0
 * @{
 */
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__SHIFT                               5
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__WIDTH                               3
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__MASK                      0x000000e0U
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000e0U) >> 5)
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000000e0U)
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000000e0U)))
#define PMU_PMU3__CTR_REF_AVDD_HIBERNATE__RESET_VALUE               0x00000003U
/** @} */

/* macros for field ctr_ref_avdd_retain */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_avdd_retain_field ctr_ref_avdd_retain_field
 * @brief macros for field ctr_ref_avdd_retain
 * @details avdd level retain. avdd=25*(37+i)mV, i=1:725*36mV, i=0
 * @{
 */
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__SHIFT                                  8
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__WIDTH                                  3
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__MASK                         0x00000700U
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define PMU_PMU3__CTR_REF_AVDD_RETAIN__RESET_VALUE                  0x00000003U
/** @} */

/* macros for field ctr_ref_avdd_socoff */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_avdd_socoff_field ctr_ref_avdd_socoff_field
 * @brief macros for field ctr_ref_avdd_socoff
 * @details avdd level socoff. avdd=25*(37+i)mV, i=1:725*36mV, i=0
 * @{
 */
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__SHIFT                                 11
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__WIDTH                                  3
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__MASK                         0x00003800U
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define PMU_PMU3__CTR_REF_AVDD_SOCOFF__RESET_VALUE                  0x00000003U
/** @} */

/* macros for field ctr_ref_avdd */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_avdd_field ctr_ref_avdd_field
 * @brief macros for field ctr_ref_avdd
 * @details avdd level for L2 ldo, 25*(43+i), i=0:7
 * @{
 */
#define PMU_PMU3__CTR_REF_AVDD__SHIFT                                        14
#define PMU_PMU3__CTR_REF_AVDD__WIDTH                                         3
#define PMU_PMU3__CTR_REF_AVDD__MASK                                0x0001c000U
#define PMU_PMU3__CTR_REF_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define PMU_PMU3__CTR_REF_AVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define PMU_PMU3__CTR_REF_AVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define PMU_PMU3__CTR_REF_AVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define PMU_PMU3__CTR_REF_AVDD__RESET_VALUE                         0x00000005U
/** @} */

/* macros for field ctr_ldoavdd_enftr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoavdd_enftr_field ctr_ldoavdd_enftr_field
 * @brief macros for field ctr_ldoavdd_enftr
 * @details enable fast settling for avdd L2 LDO
 * @{
 */
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__SHIFT                                   17
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__WIDTH                                    1
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__MASK                           0x00020000U
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU3__CTR_LDOAVDD_ENFTR__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field swResavdd_ctrcu */
/**
 * @defgroup pmu_top_regs_core_swResavdd_ctrcu_field swResavdd_ctrcu_field
 * @brief macros for field swResavdd_ctrcu
 * @details control swResavdd comparator current ctr_cuLow with <1:0>, ctr_cuMid with <3:2>, ctr_cuMidx2 with <4>
 * @{
 */
#define PMU_PMU3__SWRESAVDD_CTRCU__SHIFT                                     18
#define PMU_PMU3__SWRESAVDD_CTRCU__WIDTH                                      5
#define PMU_PMU3__SWRESAVDD_CTRCU__MASK                             0x007c0000U
#define PMU_PMU3__SWRESAVDD_CTRCU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007c0000U) >> 18)
#define PMU_PMU3__SWRESAVDD_CTRCU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x007c0000U)
#define PMU_PMU3__SWRESAVDD_CTRCU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007c0000U) | (((uint32_t)(src) <<\
                    18) & 0x007c0000U)
#define PMU_PMU3__SWRESAVDD_CTRCU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x007c0000U)))
#define PMU_PMU3__SWRESAVDD_CTRCU__RESET_VALUE                      0x0000001fU
/** @} */

/* macros for field swResavdd_ctrsamecurr */
/**
 * @defgroup pmu_top_regs_core_swResavdd_ctrsamecurr_field swResavdd_ctrsamecurr_field
 * @brief macros for field swResavdd_ctrsamecurr
 * @details control slow current in swResavdd comparator0: decrease the slow current1: keep the slow current equal to the fast
 * @{
 */
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__SHIFT                               23
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__WIDTH                                1
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__MASK                       0x00800000U
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU3__SWRESAVDD_CTRSAMECURR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field enampldoavdd_ovr */
/**
 * @defgroup pmu_top_regs_core_enampldoavdd_ovr_field enampldoavdd_ovr_field
 * @brief macros for field enampldoavdd_ovr
 * @details override enamp_ldoavdd
 * @{
 */
#define PMU_PMU3__ENAMPLDOAVDD_OVR__SHIFT                                    24
#define PMU_PMU3__ENAMPLDOAVDD_OVR__WIDTH                                     1
#define PMU_PMU3__ENAMPLDOAVDD_OVR__MASK                            0x01000000U
#define PMU_PMU3__ENAMPLDOAVDD_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU3__ENAMPLDOAVDD_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU3__ENAMPLDOAVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU3__ENAMPLDOAVDD_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU3__ENAMPLDOAVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU3__ENAMPLDOAVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU3__ENAMPLDOAVDD_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field enampldoavdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_enampldoavdd_ovr_val_field enampldoavdd_ovr_val_field
 * @brief macros for field enampldoavdd_ovr_val
 * @details override enamp_ldoavdd val: enable the L2 avdd LDO opamp
 * @{
 */
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__SHIFT                                25
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__WIDTH                                 1
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__MASK                        0x02000000U
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU3__ENAMPLDOAVDD_OVR_VAL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field en_ldoavdd_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldoavdd_ovr_field en_ldoavdd_ovr_field
 * @brief macros for field en_ldoavdd_ovr
 * @details override en_ldoavdd
 * @{
 */
#define PMU_PMU3__EN_LDOAVDD_OVR__SHIFT                                      26
#define PMU_PMU3__EN_LDOAVDD_OVR__WIDTH                                       1
#define PMU_PMU3__EN_LDOAVDD_OVR__MASK                              0x04000000U
#define PMU_PMU3__EN_LDOAVDD_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU3__EN_LDOAVDD_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU3__EN_LDOAVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU3__EN_LDOAVDD_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU3__EN_LDOAVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU3__EN_LDOAVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU3__EN_LDOAVDD_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field en_ldoavdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldoavdd_ovr_val_field en_ldoavdd_ovr_val_field
 * @brief macros for field en_ldoavdd_ovr_val
 * @details override en_ldoavdd val<0> enables the L2 avdd LDO output regulation<1> controls the L2 avdd LDO output current
 * @{
 */
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__SHIFT                                  27
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__WIDTH                                   2
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__MASK                          0x18000000U
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x18000000U) >> 27)
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x18000000U)
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x18000000U) | (((uint32_t)(src) <<\
                    27) & 0x18000000U)
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x18000000U)))
#define PMU_PMU3__EN_LDOAVDD_OVR_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field swResavdd_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_swResavdd_encomp_ovr_field swResavdd_encomp_ovr_field
 * @brief macros for field swResavdd_encomp_ovr
 * @details override swResavdd_encomp
 * @{
 */
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__SHIFT                                29
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__WIDTH                                 1
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__MASK                        0x20000000U
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field swResavdd_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_swResavdd_encomp_ovr_val_field swResavdd_encomp_ovr_val_field
 * @brief macros for field swResavdd_encomp_ovr_val
 * @details override swResavdd_encomp val: enable L2 avdd swres for idle modes
 * @{
 */
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__SHIFT                            30
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__WIDTH                             1
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__MASK                    0x40000000U
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU3__SWRESAVDD_ENCOMP_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */
#define PMU_PMU3__TYPE                                                 uint32_t
#define PMU_PMU3__READ                                              0x7fffffffU
#define PMU_PMU3__WRITE                                             0x7fffffffU
#define PMU_PMU3__PRESERVED                                         0x00000000U
#define PMU_PMU3__RESET_VALUE                                       0x007f5b6fU

#endif /* __PMU_PMU3_MACRO__ */

/** @} end of pmu3 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu4 */
/**
 * @defgroup pmu_top_regs_core_pmu4 pmu4
 * @brief more ate controls definitions.
 * @{
 */
#ifndef __PMU_PMU4_MACRO__
#define __PMU_PMU4_MACRO__

/* macros for field ctr_refBG_dvdd075 */
/**
 * @defgroup pmu_top_regs_core_ctr_refBG_dvdd075_field ctr_refBG_dvdd075_field
 * @brief macros for field ctr_refBG_dvdd075
 * @details dvdd ref from refgen startup. dvdd=25*(25+i)mV, i=0:3
 * @{
 */
#define PMU_PMU4__CTR_REFBG_DVDD075__SHIFT                                    0
#define PMU_PMU4__CTR_REFBG_DVDD075__WIDTH                                    2
#define PMU_PMU4__CTR_REFBG_DVDD075__MASK                           0x00000003U
#define PMU_PMU4__CTR_REFBG_DVDD075__READ(src)  ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU4__CTR_REFBG_DVDD075__WRITE(src) ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU4__CTR_REFBG_DVDD075__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PMU_PMU4__CTR_REFBG_DVDD075__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PMU_PMU4__CTR_REFBG_DVDD075__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field ctr_refBG_dvdd_active */
/**
 * @defgroup pmu_top_regs_core_ctr_refBG_dvdd_active_field ctr_refBG_dvdd_active_field
 * @brief macros for field ctr_refBG_dvdd_active
 * @details dvdd ref from refgen active. dvdd=25*(24+i)mV, i=0:24
 * @{
 */
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__SHIFT                                2
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__WIDTH                                5
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__MASK                       0x0000007cU
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000007cU) >> 2)
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000007cU)
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007cU) | (((uint32_t)(src) <<\
                    2) & 0x0000007cU)
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000007cU)))
#define PMU_PMU4__CTR_REFBG_DVDD_ACTIVE__RESET_VALUE                0x00000014U
/** @} */

/* macros for field ctr_refBG_dvdd_hibernate */
/**
 * @defgroup pmu_top_regs_core_ctr_refBG_dvdd_hibernate_field ctr_refBG_dvdd_hibernate_field
 * @brief macros for field ctr_refBG_dvdd_hibernate
 * @details dvdd ref from refgen hiberate. dvdd=25*(24+i)mV, i=0:24
 * @{
 */
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__SHIFT                             7
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__WIDTH                             5
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__MASK                    0x00000f80U
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f80U) >> 7)
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000f80U)
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f80U) | (((uint32_t)(src) <<\
                    7) & 0x00000f80U)
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000f80U)))
#define PMU_PMU4__CTR_REFBG_DVDD_HIBERNATE__RESET_VALUE             0x00000010U
/** @} */

/* macros for field ctr_refBG_dvdd_retain */
/**
 * @defgroup pmu_top_regs_core_ctr_refBG_dvdd_retain_field ctr_refBG_dvdd_retain_field
 * @brief macros for field ctr_refBG_dvdd_retain
 * @details dvdd ref from refgen retain. dvdd=25*(24+i)mV, i=0:24
 * @{
 */
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__SHIFT                               12
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__WIDTH                                5
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__MASK                       0x0001f000U
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001f000U) >> 12)
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0001f000U)
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001f000U) | (((uint32_t)(src) <<\
                    12) & 0x0001f000U)
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0001f000U)))
#define PMU_PMU4__CTR_REFBG_DVDD_RETAIN__RESET_VALUE                0x00000010U
/** @} */

/* macros for field ctr_refBG_dvdd_socoff */
/**
 * @defgroup pmu_top_regs_core_ctr_refBG_dvdd_socoff_field ctr_refBG_dvdd_socoff_field
 * @brief macros for field ctr_refBG_dvdd_socoff
 * @details dvdd ref from refgen socoff. dvdd=25*(24+i)mV, i=0:24
 * @{
 */
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__SHIFT                               17
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__WIDTH                                5
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__MASK                       0x003e0000U
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003e0000U) >> 17)
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x003e0000U)
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003e0000U) | (((uint32_t)(src) <<\
                    17) & 0x003e0000U)
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x003e0000U)))
#define PMU_PMU4__CTR_REFBG_DVDD_SOCOFF__RESET_VALUE                0x00000010U
/** @} */

/* macros for field ctr_cpuldo_lvl */
/**
 * @defgroup pmu_top_regs_core_ctr_cpuldo_lvl_field ctr_cpuldo_lvl_field
 * @brief macros for field ctr_cpuldo_lvl
 * @details control cpu LDO output level from 650mV to 1068mV through the fieldsctr_ldocpufbsel[2:0],ctr_refBG_cpuldo[0],ctr_ldocpu_finestp
 * @{
 */
#define PMU_PMU4__CTR_CPULDO_LVL__SHIFT                                      22
#define PMU_PMU4__CTR_CPULDO_LVL__WIDTH                                       5
#define PMU_PMU4__CTR_CPULDO_LVL__MASK                              0x07c00000U
#define PMU_PMU4__CTR_CPULDO_LVL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07c00000U) >> 22)
#define PMU_PMU4__CTR_CPULDO_LVL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x07c00000U)
#define PMU_PMU4__CTR_CPULDO_LVL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07c00000U) | (((uint32_t)(src) <<\
                    22) & 0x07c00000U)
#define PMU_PMU4__CTR_CPULDO_LVL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x07c00000U)))
#define PMU_PMU4__CTR_CPULDO_LVL__RESET_VALUE                       0x00000014U
/** @} */
#define PMU_PMU4__TYPE                                                 uint32_t
#define PMU_PMU4__READ                                              0x07ffffffU
#define PMU_PMU4__WRITE                                             0x07ffffffU
#define PMU_PMU4__PRESERVED                                         0x00000000U
#define PMU_PMU4__RESET_VALUE                                       0x05210852U

#endif /* __PMU_PMU4_MACRO__ */

/** @} end of pmu4 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu5 */
/**
 * @defgroup pmu_top_regs_core_pmu5 pmu5
 * @brief more pmu controls definitions.
 * @{
 */
#ifndef __PMU_PMU5_MACRO__
#define __PMU_PMU5_MACRO__

/* macros for field socoff_swon_vauxon_ovr */
/**
 * @defgroup pmu_top_regs_core_socoff_swon_vauxon_ovr_field socoff_swon_vauxon_ovr_field
 * @brief macros for field socoff_swon_vauxon_ovr
 * @details override socoff_swon_vauxon
 * @{
 */
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__SHIFT                               0
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__WIDTH                               1
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__MASK                      0x00000001U
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field socoff_swon_vauxon_ovr_val */
/**
 * @defgroup pmu_top_regs_core_socoff_swon_vauxon_ovr_val_field socoff_swon_vauxon_ovr_val_field
 * @brief macros for field socoff_swon_vauxon_ovr_val
 * @details override socoff_swon_vauxon val: maintain vaux with switcher in socoff
 * @{
 */
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__SHIFT                           1
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__WIDTH                           1
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__MASK                  0x00000002U
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU5__SOCOFF_SWON_VAUXON_OVR_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field socoff_swon_dvddonly_ovr */
/**
 * @defgroup pmu_top_regs_core_socoff_swon_dvddonly_ovr_field socoff_swon_dvddonly_ovr_field
 * @brief macros for field socoff_swon_dvddonly_ovr
 * @details override socoff_swon_dvddonly
 * @{
 */
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__SHIFT                             2
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__WIDTH                             1
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__MASK                    0x00000004U
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field socoff_swon_dvddonly_ovr_val */
/**
 * @defgroup pmu_top_regs_core_socoff_swon_dvddonly_ovr_val_field socoff_swon_dvddonly_ovr_val_field
 * @brief macros for field socoff_swon_dvddonly_ovr_val
 * @details override socoff_swon_dvddonly val: maintail only dvdd with switcher in socoff
 * @{
 */
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__SHIFT                         3
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__WIDTH                         1
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__MASK                0x00000008U
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU5__SOCOFF_SWON_DVDDONLY_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field reg_scaleEnerg */
/**
 * @defgroup pmu_top_regs_core_reg_scaleEnerg_field reg_scaleEnerg_field
 * @brief macros for field reg_scaleEnerg
 * @details control scaleEnerg of switcher when the pmuadc output is not available
 * @{
 */
#define PMU_PMU5__REG_SCALEENERG__SHIFT                                       4
#define PMU_PMU5__REG_SCALEENERG__WIDTH                                       9
#define PMU_PMU5__REG_SCALEENERG__MASK                              0x00001ff0U
#define PMU_PMU5__REG_SCALEENERG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001ff0U) >> 4)
#define PMU_PMU5__REG_SCALEENERG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00001ff0U)
#define PMU_PMU5__REG_SCALEENERG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001ff0U) | (((uint32_t)(src) <<\
                    4) & 0x00001ff0U)
#define PMU_PMU5__REG_SCALEENERG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00001ff0U)))
#define PMU_PMU5__REG_SCALEENERG__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field en_ldocpu_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldocpu_ovr_field en_ldocpu_ovr_field
 * @brief macros for field en_ldocpu_ovr
 * @details override CPU LDO enable
 * @{
 */
#define PMU_PMU5__EN_LDOCPU_OVR__SHIFT                                       13
#define PMU_PMU5__EN_LDOCPU_OVR__WIDTH                                        1
#define PMU_PMU5__EN_LDOCPU_OVR__MASK                               0x00002000U
#define PMU_PMU5__EN_LDOCPU_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU5__EN_LDOCPU_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU5__EN_LDOCPU_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU5__EN_LDOCPU_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU5__EN_LDOCPU_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU5__EN_LDOCPU_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU5__EN_LDOCPU_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field en_ldocpu_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldocpu_ovr_val_field en_ldocpu_ovr_val_field
 * @brief macros for field en_ldocpu_ovr_val
 * @details Use CPU LDO when SOC wants a CPU supply or used when override is set
 * @{
 */
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__SHIFT                                   14
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__WIDTH                                    1
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__MASK                           0x00004000U
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU5__EN_LDOCPU_OVR_VAL__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field ctr_ldocpu_bypass */
/**
 * @defgroup pmu_top_regs_core_ctr_ldocpu_bypass_field ctr_ldocpu_bypass_field
 * @brief macros for field ctr_ldocpu_bypass
 * @details Bypass CPU LDO to DVDDmain when SOC wants a CPU supply
 * @{
 */
#define PMU_PMU5__CTR_LDOCPU_BYPASS__SHIFT                                   15
#define PMU_PMU5__CTR_LDOCPU_BYPASS__WIDTH                                    1
#define PMU_PMU5__CTR_LDOCPU_BYPASS__MASK                           0x00008000U
#define PMU_PMU5__CTR_LDOCPU_BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU5__CTR_LDOCPU_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU5__CTR_LDOCPU_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU5__CTR_LDOCPU_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU5__CTR_LDOCPU_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU5__CTR_LDOCPU_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU5__CTR_LDOCPU_BYPASS__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_ldocpuhf */
/**
 * @defgroup pmu_top_regs_core_en_ldocpuhf_field en_ldocpuhf_field
 * @brief macros for field en_ldocpuhf
 * @details Enable fast transient response
 * @{
 */
#define PMU_PMU5__EN_LDOCPUHF__SHIFT                                         16
#define PMU_PMU5__EN_LDOCPUHF__WIDTH                                          1
#define PMU_PMU5__EN_LDOCPUHF__MASK                                 0x00010000U
#define PMU_PMU5__EN_LDOCPUHF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU5__EN_LDOCPUHF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU5__EN_LDOCPUHF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU5__EN_LDOCPUHF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU5__EN_LDOCPUHF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU5__EN_LDOCPUHF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU5__EN_LDOCPUHF__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field ctr_ldocpu_hfcurr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldocpu_hfcurr_field ctr_ldocpu_hfcurr_field
 * @brief macros for field ctr_ldocpu_hfcurr
 * @details Bias current for fast transient circuit
 * @{
 */
#define PMU_PMU5__CTR_LDOCPU_HFCURR__SHIFT                                   17
#define PMU_PMU5__CTR_LDOCPU_HFCURR__WIDTH                                    2
#define PMU_PMU5__CTR_LDOCPU_HFCURR__MASK                           0x00060000U
#define PMU_PMU5__CTR_LDOCPU_HFCURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define PMU_PMU5__CTR_LDOCPU_HFCURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define PMU_PMU5__CTR_LDOCPU_HFCURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define PMU_PMU5__CTR_LDOCPU_HFCURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define PMU_PMU5__CTR_LDOCPU_HFCURR__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field ctr_ldocpucuout */
/**
 * @defgroup pmu_top_regs_core_ctr_ldocpucuout_field ctr_ldocpucuout_field
 * @brief macros for field ctr_ldocpucuout
 * @details CPU LDO output stage bias current, 0 = 16uA, 1 = 60uA, 2 = 240uA, 3 = 466uA, need at least 70uA total = output stage bias + CPU leakage for stability
 * @{
 */
#define PMU_PMU5__CTR_LDOCPUCUOUT__SHIFT                                     19
#define PMU_PMU5__CTR_LDOCPUCUOUT__WIDTH                                      2
#define PMU_PMU5__CTR_LDOCPUCUOUT__MASK                             0x00180000U
#define PMU_PMU5__CTR_LDOCPUCUOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define PMU_PMU5__CTR_LDOCPUCUOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define PMU_PMU5__CTR_LDOCPUCUOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define PMU_PMU5__CTR_LDOCPUCUOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define PMU_PMU5__CTR_LDOCPUCUOUT__RESET_VALUE                      0x00000002U
/** @} */

/* macros for field ctr_ldocpulowcu */
/**
 * @defgroup pmu_top_regs_core_ctr_ldocpulowcu_field ctr_ldocpulowcu_field
 * @brief macros for field ctr_ldocpulowcu
 * @details Reduce CPU LDO amplifier current for PM, needed for values of ctr_ldocpucuout < 2
 * @{
 */
#define PMU_PMU5__CTR_LDOCPULOWCU__SHIFT                                     21
#define PMU_PMU5__CTR_LDOCPULOWCU__WIDTH                                      1
#define PMU_PMU5__CTR_LDOCPULOWCU__MASK                             0x00200000U
#define PMU_PMU5__CTR_LDOCPULOWCU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU5__CTR_LDOCPULOWCU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU5__CTR_LDOCPULOWCU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU5__CTR_LDOCPULOWCU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU5__CTR_LDOCPULOWCU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU5__CTR_LDOCPULOWCU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU5__CTR_LDOCPULOWCU__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field ctr_bypstorecpu */
/**
 * @defgroup pmu_top_regs_core_ctr_bypstorecpu_field ctr_bypstorecpu_field
 * @brief macros for field ctr_bypstorecpu
 * @details Bypass VSTORE to DVDDcpu
 * @{
 */
#define PMU_PMU5__CTR_BYPSTORECPU__SHIFT                                     22
#define PMU_PMU5__CTR_BYPSTORECPU__WIDTH                                      1
#define PMU_PMU5__CTR_BYPSTORECPU__MASK                             0x00400000U
#define PMU_PMU5__CTR_BYPSTORECPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU5__CTR_BYPSTORECPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU5__CTR_BYPSTORECPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU5__CTR_BYPSTORECPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU5__CTR_BYPSTORECPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU5__CTR_BYPSTORECPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU5__CTR_BYPSTORECPU__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field enable_mppt */
/**
 * @defgroup pmu_top_regs_core_enable_mppt_field enable_mppt_field
 * @brief macros for field enable_mppt
 * @details enable mppt
 * @{
 */
#define PMU_PMU5__ENABLE_MPPT__SHIFT                                         23
#define PMU_PMU5__ENABLE_MPPT__WIDTH                                          1
#define PMU_PMU5__ENABLE_MPPT__MASK                                 0x00800000U
#define PMU_PMU5__ENABLE_MPPT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU5__ENABLE_MPPT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU5__ENABLE_MPPT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU5__ENABLE_MPPT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU5__ENABLE_MPPT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU5__ENABLE_MPPT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU5__ENABLE_MPPT__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field use_pmuAdc_buckboost */
/**
 * @defgroup pmu_top_regs_core_use_pmuAdc_buckboost_field use_pmuAdc_buckboost_field
 * @brief macros for field use_pmuAdc_buckboost
 * @details pmu adc buck boost enable
 * @{
 */
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__SHIFT                                24
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__WIDTH                                 1
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__MASK                        0x01000000U
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU5__USE_PMUADC_BUCKBOOST__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field use_pmuAdc_ldoctrls */
/**
 * @defgroup pmu_top_regs_core_use_pmuAdc_ldoctrls_field use_pmuAdc_ldoctrls_field
 * @brief macros for field use_pmuAdc_ldoctrls
 * @details pmu adc ldo control enable
 * @{
 */
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__SHIFT                                 25
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__WIDTH                                  1
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__MASK                         0x02000000U
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU5__USE_PMUADC_LDOCTRLS__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field use_pmuAdc_chrg */
/**
 * @defgroup pmu_top_regs_core_use_pmuAdc_chrg_field use_pmuAdc_chrg_field
 * @brief macros for field use_pmuAdc_chrg
 * @details pmu adc charger control enable
 * @{
 */
#define PMU_PMU5__USE_PMUADC_CHRG__SHIFT                                     26
#define PMU_PMU5__USE_PMUADC_CHRG__WIDTH                                      1
#define PMU_PMU5__USE_PMUADC_CHRG__MASK                             0x04000000U
#define PMU_PMU5__USE_PMUADC_CHRG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU5__USE_PMUADC_CHRG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU5__USE_PMUADC_CHRG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU5__USE_PMUADC_CHRG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU5__USE_PMUADC_CHRG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU5__USE_PMUADC_CHRG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU5__USE_PMUADC_CHRG__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field use_pmuAdc_buckboostharv */
/**
 * @defgroup pmu_top_regs_core_use_pmuAdc_buckboostharv_field use_pmuAdc_buckboostharv_field
 * @brief macros for field use_pmuAdc_buckboostharv
 * @details pmu adc buck boost enable for harv
 * @{
 */
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__SHIFT                            27
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__WIDTH                             1
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__MASK                    0x08000000U
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU5__USE_PMUADC_BUCKBOOSTHARV__RESET_VALUE             0x00000001U
/** @} */

/* macros for field use_pmuAdc_pn */
/**
 * @defgroup pmu_top_regs_core_use_pmuAdc_pn_field use_pmuAdc_pn_field
 * @brief macros for field use_pmuAdc_pn
 * @details pmu adc pn control enable
 * @{
 */
#define PMU_PMU5__USE_PMUADC_PN__SHIFT                                       28
#define PMU_PMU5__USE_PMUADC_PN__WIDTH                                        1
#define PMU_PMU5__USE_PMUADC_PN__MASK                               0x10000000U
#define PMU_PMU5__USE_PMUADC_PN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU5__USE_PMUADC_PN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU5__USE_PMUADC_PN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU5__USE_PMUADC_PN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU5__USE_PMUADC_PN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU5__USE_PMUADC_PN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU5__USE_PMUADC_PN__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field force_pmuAdc_rst */
/**
 * @defgroup pmu_top_regs_core_force_pmuAdc_rst_field force_pmuAdc_rst_field
 * @brief macros for field force_pmuAdc_rst
 * @details 0: enable pmuadc, 1: disable pmuadc
 * @{
 */
#define PMU_PMU5__FORCE_PMUADC_RST__SHIFT                                    29
#define PMU_PMU5__FORCE_PMUADC_RST__WIDTH                                     1
#define PMU_PMU5__FORCE_PMUADC_RST__MASK                            0x20000000U
#define PMU_PMU5__FORCE_PMUADC_RST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU5__FORCE_PMUADC_RST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU5__FORCE_PMUADC_RST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU5__FORCE_PMUADC_RST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU5__FORCE_PMUADC_RST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU5__FORCE_PMUADC_RST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU5__FORCE_PMUADC_RST__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field boost_vbat_vaux_reg */
/**
 * @defgroup pmu_top_regs_core_boost_vbat_vaux_reg_field boost_vbat_vaux_reg_field
 * @brief macros for field boost_vbat_vaux_reg
 * @details keep disabled at startup. Software will enable after cold start
 * @{
 */
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__SHIFT                                 30
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__WIDTH                                  1
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__MASK                         0x40000000U
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU5__BOOST_VBAT_VAUX_REG__RESET_VALUE                  0x00000000U
/** @} */
#define PMU_PMU5__TYPE                                                 uint32_t
#define PMU_PMU5__READ                                              0x7fffffffU
#define PMU_PMU5__WRITE                                             0x7fffffffU
#define PMU_PMU5__PRESERVED                                         0x00000000U
#define PMU_PMU5__RESET_VALUE                                       0x3f934000U

#endif /* __PMU_PMU5_MACRO__ */

/** @} end of pmu5 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu6 */
/**
 * @defgroup pmu_top_regs_core_pmu6 pmu6
 * @brief comparator current controls definitions.
 * @{
 */
#ifndef __PMU_PMU6_MACRO__
#define __PMU_PMU6_MACRO__

/* macros for field ctrcuLow0 */
/**
 * @defgroup pmu_top_regs_core_ctrcuLow0_field ctrcuLow0_field
 * @brief macros for field ctrcuLow0
 * @details reset/vstore/vbat/vharv comp current for SOCOFF/HIBERNATE
 * @{
 */
#define PMU_PMU6__CTRCULOW0__SHIFT                                            0
#define PMU_PMU6__CTRCULOW0__WIDTH                                            2
#define PMU_PMU6__CTRCULOW0__MASK                                   0x00000003U
#define PMU_PMU6__CTRCULOW0__READ(src)          ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU6__CTRCULOW0__WRITE(src)         ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU6__CTRCULOW0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PMU_PMU6__CTRCULOW0__VERIFY(src)  (!(((uint32_t)(src) & ~0x00000003U)))
#define PMU_PMU6__CTRCULOW0__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field ctrcuLow1 */
/**
 * @defgroup pmu_top_regs_core_ctrcuLow1_field ctrcuLow1_field
 * @brief macros for field ctrcuLow1
 * @details reset/vstore/vbat/vharv comp current for RETAIN
 * @{
 */
#define PMU_PMU6__CTRCULOW1__SHIFT                                            2
#define PMU_PMU6__CTRCULOW1__WIDTH                                            2
#define PMU_PMU6__CTRCULOW1__MASK                                   0x0000000cU
#define PMU_PMU6__CTRCULOW1__READ(src)   (((uint32_t)(src) & 0x0000000cU) >> 2)
#define PMU_PMU6__CTRCULOW1__WRITE(src)  (((uint32_t)(src) << 2) & 0x0000000cU)
#define PMU_PMU6__CTRCULOW1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define PMU_PMU6__CTRCULOW1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define PMU_PMU6__CTRCULOW1__RESET_VALUE                            0x00000002U
/** @} */

/* macros for field ctrcuLow2 */
/**
 * @defgroup pmu_top_regs_core_ctrcuLow2_field ctrcuLow2_field
 * @brief macros for field ctrcuLow2
 * @details reset/vstore/vbat/vharv comp current for startup/ACTIVE
 * @{
 */
#define PMU_PMU6__CTRCULOW2__SHIFT                                            4
#define PMU_PMU6__CTRCULOW2__WIDTH                                            2
#define PMU_PMU6__CTRCULOW2__MASK                                   0x00000030U
#define PMU_PMU6__CTRCULOW2__READ(src)   (((uint32_t)(src) & 0x00000030U) >> 4)
#define PMU_PMU6__CTRCULOW2__WRITE(src)  (((uint32_t)(src) << 4) & 0x00000030U)
#define PMU_PMU6__CTRCULOW2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define PMU_PMU6__CTRCULOW2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define PMU_PMU6__CTRCULOW2__RESET_VALUE                            0x00000003U
/** @} */

/* macros for field swRes_ctrcu0 */
/**
 * @defgroup pmu_top_regs_core_swRes_ctrcu0_field swRes_ctrcu0_field
 * @brief macros for field swRes_ctrcu0
 * @details swres fast current for startup
 * @{
 */
#define PMU_PMU6__SWRES_CTRCU0__SHIFT                                         6
#define PMU_PMU6__SWRES_CTRCU0__WIDTH                                         5
#define PMU_PMU6__SWRES_CTRCU0__MASK                                0x000007c0U
#define PMU_PMU6__SWRES_CTRCU0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000007c0U) >> 6)
#define PMU_PMU6__SWRES_CTRCU0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000007c0U)
#define PMU_PMU6__SWRES_CTRCU0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007c0U) | (((uint32_t)(src) <<\
                    6) & 0x000007c0U)
#define PMU_PMU6__SWRES_CTRCU0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000007c0U)))
#define PMU_PMU6__SWRES_CTRCU0__RESET_VALUE                         0x00000017U
/** @} */

/* macros for field SwchReqDVDD_ctrcu2 */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_ctrcu2_field SwchReqDVDD_ctrcu2_field
 * @brief macros for field SwchReqDVDD_ctrcu2
 * @details SwchReqDVDD comp current for startup/ACTIVE
 * @{
 */
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__SHIFT                                  11
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__WIDTH                                   2
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__MASK                          0x00001800U
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define PMU_PMU6__SWCHREQDVDD_CTRCU2__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field SwchReqDVDD_ctrcu1 */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_ctrcu1_field SwchReqDVDD_ctrcu1_field
 * @brief macros for field SwchReqDVDD_ctrcu1
 * @details SwchReqDVDD comp current for RETAIN
 * @{
 */
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__SHIFT                                  13
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__WIDTH                                   3
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__MASK                          0x0000e000U
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define PMU_PMU6__SWCHREQDVDD_CTRCU1__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field SwchReqDVDD_ctrcu0 */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_ctrcu0_field SwchReqDVDD_ctrcu0_field
 * @brief macros for field SwchReqDVDD_ctrcu0
 * @details SwchReqDVDD comp current for SOCOFF/HIBERNATE
 * @{
 */
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__SHIFT                                  16
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__WIDTH                                   3
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__MASK                          0x00070000U
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define PMU_PMU6__SWCHREQDVDD_CTRCU0__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field SwchReqDVDD_ctrcures1 */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_ctrcures1_field SwchReqDVDD_ctrcures1_field
 * @brief macros for field SwchReqDVDD_ctrcures1
 * @details SwchReqDVDD comp current to control L1 dvdd swres for RETAIN
 * @{
 */
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__SHIFT                               19
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__WIDTH                                3
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__MASK                       0x00380000U
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00380000U) >> 19)
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00380000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define PMU_PMU6__SWCHREQDVDD_CTRCURES1__RESET_VALUE                0x00000001U
/** @} */

/* macros for field SwchReqDVDD_ctrcures0 */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_ctrcures0_field SwchReqDVDD_ctrcures0_field
 * @brief macros for field SwchReqDVDD_ctrcures0
 * @details SwchReqDVDD comp current to control L1 dvdd swres for SOCOFF/HIBERNATE
 * @{
 */
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__SHIFT                               22
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__WIDTH                                3
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__MASK                       0x01c00000U
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01c00000U) >> 22)
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x01c00000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01c00000U) | (((uint32_t)(src) <<\
                    22) & 0x01c00000U)
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x01c00000U)))
#define PMU_PMU6__SWCHREQDVDD_CTRCURES0__RESET_VALUE                0x00000001U
/** @} */

/* macros for field en_protect_avdd_reg */
/**
 * @defgroup pmu_top_regs_core_en_protect_avdd_reg_field en_protect_avdd_reg_field
 * @brief macros for field en_protect_avdd_reg
 * @details to enable leak path on avdd if too much input power
 * @{
 */
#define PMU_PMU6__EN_PROTECT_AVDD_REG__SHIFT                                 25
#define PMU_PMU6__EN_PROTECT_AVDD_REG__WIDTH                                  1
#define PMU_PMU6__EN_PROTECT_AVDD_REG__MASK                         0x02000000U
#define PMU_PMU6__EN_PROTECT_AVDD_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU6__EN_PROTECT_AVDD_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU6__EN_PROTECT_AVDD_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU6__EN_PROTECT_AVDD_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU6__EN_PROTECT_AVDD_REG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU6__EN_PROTECT_AVDD_REG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU6__EN_PROTECT_AVDD_REG__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field en_protect_dvdd_reg */
/**
 * @defgroup pmu_top_regs_core_en_protect_dvdd_reg_field en_protect_dvdd_reg_field
 * @brief macros for field en_protect_dvdd_reg
 * @details to enable leak path on dvdd if too much input power
 * @{
 */
#define PMU_PMU6__EN_PROTECT_DVDD_REG__SHIFT                                 26
#define PMU_PMU6__EN_PROTECT_DVDD_REG__WIDTH                                  1
#define PMU_PMU6__EN_PROTECT_DVDD_REG__MASK                         0x04000000U
#define PMU_PMU6__EN_PROTECT_DVDD_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU6__EN_PROTECT_DVDD_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU6__EN_PROTECT_DVDD_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU6__EN_PROTECT_DVDD_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU6__EN_PROTECT_DVDD_REG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU6__EN_PROTECT_DVDD_REG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU6__EN_PROTECT_DVDD_REG__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field en_protect_vddio_reg */
/**
 * @defgroup pmu_top_regs_core_en_protect_vddio_reg_field en_protect_vddio_reg_field
 * @brief macros for field en_protect_vddio_reg
 * @details to enable leak path on vddio if too much input power
 * @{
 */
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__SHIFT                                27
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__WIDTH                                 1
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__MASK                        0x08000000U
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU6__EN_PROTECT_VDDIO_REG__RESET_VALUE                 0x00000000U
/** @} */
#define PMU_PMU6__TYPE                                                 uint32_t
#define PMU_PMU6__READ                                              0x0fffffffU
#define PMU_PMU6__WRITE                                             0x0fffffffU
#define PMU_PMU6__PRESERVED                                         0x00000000U
#define PMU_PMU6__RESET_VALUE                                       0x004925f8U

#endif /* __PMU_PMU6_MACRO__ */

/** @} end of pmu6 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu7 */
/**
 * @defgroup pmu_top_regs_core_pmu7 pmu7
 * @brief more comparator_current controls definitions.
 * @{
 */
#ifndef __PMU_PMU7_MACRO__
#define __PMU_PMU7_MACRO__

/* macros for field SwchReqVDDIO_ctrcu2 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_ctrcu2_field SwchReqVDDIO_ctrcu2_field
 * @brief macros for field SwchReqVDDIO_ctrcu2
 * @details SwchReqVDDIO comp current for startup/ACTIVE
 * @{
 */
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__SHIFT                                  0
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__WIDTH                                  2
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__MASK                         0x00000003U
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PMU_PMU7__SWCHREQVDDIO_CTRCU2__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_ctrcu1 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_ctrcu1_field SwchReqVDDIO_ctrcu1_field
 * @brief macros for field SwchReqVDDIO_ctrcu1
 * @details SwchReqVDDIO comp current for RETAIN
 * @{
 */
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__SHIFT                                  2
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__WIDTH                                  3
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__MASK                         0x0000001cU
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define PMU_PMU7__SWCHREQVDDIO_CTRCU1__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field SwchReqVDDIO_ctrcu0 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_ctrcu0_field SwchReqVDDIO_ctrcu0_field
 * @brief macros for field SwchReqVDDIO_ctrcu0
 * @details SwchReqVDDIO comp current for SOCOFF/HIBERNATE
 * @{
 */
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__SHIFT                                  5
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__WIDTH                                  3
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__MASK                         0x000000e0U
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000e0U) >> 5)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000000e0U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000000e0U)))
#define PMU_PMU7__SWCHREQVDDIO_CTRCU0__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field SwchReqVDDIO_ctrcures1 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_ctrcures1_field SwchReqVDDIO_ctrcures1_field
 * @brief macros for field SwchReqVDDIO_ctrcures1
 * @details SwchReqVDDIO comp current to control L1 vddio swres for RETAIN
 * @{
 */
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__SHIFT                               8
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__WIDTH                               3
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__MASK                      0x00000700U
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES1__RESET_VALUE               0x00000001U
/** @} */

/* macros for field SwchReqVDDIO_ctrcures0 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_ctrcures0_field SwchReqVDDIO_ctrcures0_field
 * @brief macros for field SwchReqVDDIO_ctrcures0
 * @details SwchReqVDDIO comp current to control L1 vddio swres for SOCOFF/HIBERNATE
 * @{
 */
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__SHIFT                              11
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__WIDTH                               3
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__MASK                      0x00003800U
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define PMU_PMU7__SWCHREQVDDIO_CTRCURES0__RESET_VALUE               0x00000001U
/** @} */

/* macros for field SwchReqAVDD_ctrcu2 */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_ctrcu2_field SwchReqAVDD_ctrcu2_field
 * @brief macros for field SwchReqAVDD_ctrcu2
 * @details SwchReqAVDD comp current for startup/ACTIVE
 * @{
 */
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__SHIFT                                  14
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__WIDTH                                   2
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__MASK                          0x0000c000U
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000c000U) >> 14)
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0000c000U)
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define PMU_PMU7__SWCHREQAVDD_CTRCU2__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field SwchReqAVDD_ctrcu1 */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_ctrcu1_field SwchReqAVDD_ctrcu1_field
 * @brief macros for field SwchReqAVDD_ctrcu1
 * @details SwchReqAVDD comp current for RETAIN
 * @{
 */
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__SHIFT                                  16
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__WIDTH                                   3
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__MASK                          0x00070000U
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define PMU_PMU7__SWCHREQAVDD_CTRCU1__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field SwchReqAVDD_ctrcu0 */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_ctrcu0_field SwchReqAVDD_ctrcu0_field
 * @brief macros for field SwchReqAVDD_ctrcu0
 * @details SwchReqAVDD comp current for SOCOFF/HIBERNATE
 * @{
 */
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__SHIFT                                  19
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__WIDTH                                   3
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__MASK                          0x00380000U
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00380000U) >> 19)
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00380000U)
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define PMU_PMU7__SWCHREQAVDD_CTRCU0__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field SwchReqVAUX_ctrcu2 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVAUX_ctrcu2_field SwchReqVAUX_ctrcu2_field
 * @brief macros for field SwchReqVAUX_ctrcu2
 * @details SwchReqVAUX comp current for startup/ACTIVE
 * @{
 */
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__SHIFT                                  22
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__WIDTH                                   2
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__MASK                          0x00c00000U
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define PMU_PMU7__SWCHREQVAUX_CTRCU2__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field SwchReqVAUX_ctrcu1 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVAUX_ctrcu1_field SwchReqVAUX_ctrcu1_field
 * @brief macros for field SwchReqVAUX_ctrcu1
 * @details SwchReqVAUX comp current for RETAIN
 * @{
 */
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__SHIFT                                  24
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__WIDTH                                   3
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__MASK                          0x07000000U
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define PMU_PMU7__SWCHREQVAUX_CTRCU1__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field SwchReqVAUX_ctrcu0 */
/**
 * @defgroup pmu_top_regs_core_SwchReqVAUX_ctrcu0_field SwchReqVAUX_ctrcu0_field
 * @brief macros for field SwchReqVAUX_ctrcu0
 * @details SwchReqVAUX comp current for SOCOFF/HIBERNATE
 * @{
 */
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__SHIFT                                  27
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__WIDTH                                   3
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__MASK                          0x38000000U
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x38000000U) >> 27)
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x38000000U)
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x38000000U) | (((uint32_t)(src) <<\
                    27) & 0x38000000U)
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x38000000U)))
#define PMU_PMU7__SWCHREQVAUX_CTRCU0__RESET_VALUE                   0x00000001U
/** @} */
#define PMU_PMU7__TYPE                                                 uint32_t
#define PMU_PMU7__READ                                              0x3fffffffU
#define PMU_PMU7__WRITE                                             0x3fffffffU
#define PMU_PMU7__PRESERVED                                         0x00000000U
#define PMU_PMU7__RESET_VALUE                                       0x09090924U

#endif /* __PMU_PMU7_MACRO__ */

/** @} end of pmu7 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu8 */
/**
 * @defgroup pmu_top_regs_core_pmu8 pmu8
 * @brief comparator current controls/ other controls definitions.
 * @{
 */
#ifndef __PMU_PMU8_MACRO__
#define __PMU_PMU8_MACRO__

/* macros for field ctr_trackref1_active */
/**
 * @defgroup pmu_top_regs_core_ctr_trackref1_active_field ctr_trackref1_active_field
 * @brief macros for field ctr_trackref1_active
 * @details DVDD reference from trackref in active10:0.78V16:0.88V26:1V31:1.06V
 * @{
 */
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__SHIFT                                 0
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__WIDTH                                 5
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__MASK                        0x0000001fU
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define PMU_PMU8__CTR_TRACKREF1_ACTIVE__RESET_VALUE                 0x0000001cU
/** @} */

/* macros for field ctr_trackref1_hibernate */
/**
 * @defgroup pmu_top_regs_core_ctr_trackref1_hibernate_field ctr_trackref1_hibernate_field
 * @brief macros for field ctr_trackref1_hibernate
 * @details DVDD reference from trackref in TRACK1 hibernate10:0.78V16:0.88V26:1V31:1.06V
 * @{
 */
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__SHIFT                              5
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__WIDTH                              5
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__MASK                     0x000003e0U
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define PMU_PMU8__CTR_TRACKREF1_HIBERNATE__RESET_VALUE              0x0000001cU
/** @} */

/* macros for field ctr_trackref1_retain */
/**
 * @defgroup pmu_top_regs_core_ctr_trackref1_retain_field ctr_trackref1_retain_field
 * @brief macros for field ctr_trackref1_retain
 * @details DVDD reference from trackref in TRACK1 retain10:0.78V16:0.88V26:1V31:1.06V
 * @{
 */
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__SHIFT                                10
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__WIDTH                                 5
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__MASK                        0x00007c00U
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define PMU_PMU8__CTR_TRACKREF1_RETAIN__RESET_VALUE                 0x0000001cU
/** @} */

/* macros for field ctr_trackref1_socoff */
/**
 * @defgroup pmu_top_regs_core_ctr_trackref1_socoff_field ctr_trackref1_socoff_field
 * @brief macros for field ctr_trackref1_socoff
 * @details DVDD reference from trackref in TRACK1 socoff10:0.78V16:0.88V26:1V31:1.06V
 * @{
 */
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__SHIFT                                15
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__WIDTH                                 5
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__MASK                        0x000f8000U
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define PMU_PMU8__CTR_TRACKREF1_SOCOFF__RESET_VALUE                 0x0000001cU
/** @} */

/* macros for field ctr_trackref07 */
/**
 * @defgroup pmu_top_regs_core_ctr_trackref07_field ctr_trackref07_field
 * @brief macros for field ctr_trackref07
 * @details DVDD reference from trackref in TRACK07 hibernate12:0.7V16:0.74V19:0.78V31:0.89V
 * @{
 */
#define PMU_PMU8__CTR_TRACKREF07__SHIFT                                      20
#define PMU_PMU8__CTR_TRACKREF07__WIDTH                                       5
#define PMU_PMU8__CTR_TRACKREF07__MASK                              0x01f00000U
#define PMU_PMU8__CTR_TRACKREF07__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define PMU_PMU8__CTR_TRACKREF07__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define PMU_PMU8__CTR_TRACKREF07__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define PMU_PMU8__CTR_TRACKREF07__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define PMU_PMU8__CTR_TRACKREF07__RESET_VALUE                       0x0000000eU
/** @} */

/* macros for field ctr_Vrectrepl */
/**
 * @defgroup pmu_top_regs_core_ctr_Vrectrepl_field ctr_Vrectrepl_field
 * @brief macros for field ctr_Vrectrepl
 * @details Turn ON the resistive divider of the analog mppt ref generatorCan set it to zero if analog mppt is disabled.
 * @{
 */
#define PMU_PMU8__CTR_VRECTREPL__SHIFT                                       25
#define PMU_PMU8__CTR_VRECTREPL__WIDTH                                        1
#define PMU_PMU8__CTR_VRECTREPL__MASK                               0x02000000U
#define PMU_PMU8__CTR_VRECTREPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU8__CTR_VRECTREPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU8__CTR_VRECTREPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU8__CTR_VRECTREPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU8__CTR_VRECTREPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU8__CTR_VRECTREPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU8__CTR_VRECTREPL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field ctr_increctstreg1 */
/**
 * @defgroup pmu_top_regs_core_ctr_increctstreg1_field ctr_increctstreg1_field
 * @brief macros for field ctr_increctstreg1
 * @details control Vrefchpu_increctst for chpuhsw_increctstage comparator25*(29 + 5*i)mV, i=1:225* 19 mV, i=0
 * @{
 */
#define PMU_PMU8__CTR_INCRECTSTREG1__SHIFT                                   26
#define PMU_PMU8__CTR_INCRECTSTREG1__WIDTH                                    2
#define PMU_PMU8__CTR_INCRECTSTREG1__MASK                           0x0c000000U
#define PMU_PMU8__CTR_INCRECTSTREG1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define PMU_PMU8__CTR_INCRECTSTREG1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define PMU_PMU8__CTR_INCRECTSTREG1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define PMU_PMU8__CTR_INCRECTSTREG1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define PMU_PMU8__CTR_INCRECTSTREG1__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field ctr_increctstreg2 */
/**
 * @defgroup pmu_top_regs_core_ctr_increctstreg2_field ctr_increctstreg2_field
 * @brief macros for field ctr_increctstreg2
 * @details control Vrefchpu_increctst for chpuhsw_increctstage comparator25*(29 + 5*i)mV, i=1:225* 19 mV, i=0
 * @{
 */
#define PMU_PMU8__CTR_INCRECTSTREG2__SHIFT                                   28
#define PMU_PMU8__CTR_INCRECTSTREG2__WIDTH                                    2
#define PMU_PMU8__CTR_INCRECTSTREG2__MASK                           0x30000000U
#define PMU_PMU8__CTR_INCRECTSTREG2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define PMU_PMU8__CTR_INCRECTSTREG2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define PMU_PMU8__CTR_INCRECTSTREG2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define PMU_PMU8__CTR_INCRECTSTREG2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define PMU_PMU8__CTR_INCRECTSTREG2__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field boost_vsto_vaux_reg */
/**
 * @defgroup pmu_top_regs_core_boost_vsto_vaux_reg_field boost_vsto_vaux_reg_field
 * @brief macros for field boost_vsto_vaux_reg
 * @details Use software to enable boost in this mode
 * @{
 */
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__SHIFT                                 30
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__WIDTH                                  1
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__MASK                         0x40000000U
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU8__BOOST_VSTO_VAUX_REG__RESET_VALUE                  0x00000000U
/** @} */
#define PMU_PMU8__TYPE                                                 uint32_t
#define PMU_PMU8__READ                                              0x7fffffffU
#define PMU_PMU8__WRITE                                             0x7fffffffU
#define PMU_PMU8__PRESERVED                                         0x00000000U
#define PMU_PMU8__RESET_VALUE                                       0x0aee739cU

#endif /* __PMU_PMU8_MACRO__ */

/** @} end of pmu8 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu9 */
/**
 * @defgroup pmu_top_regs_core_pmu9 pmu9
 * @brief more pmu controls definitions.
 * @{
 */
#ifndef __PMU_PMU9_MACRO__
#define __PMU_PMU9_MACRO__

/* macros for field ctr_refenergbohy */
/**
 * @defgroup pmu_top_regs_core_ctr_refenergbohy_field ctr_refenergbohy_field
 * @brief macros for field ctr_refenergbohy
 * @details VrefstogoodtoEner hyst level. VSTOR=25*[56,39,32,26] for i=[3:0]
 * @{
 */
#define PMU_PMU9__CTR_REFENERGBOHY__SHIFT                                     0
#define PMU_PMU9__CTR_REFENERGBOHY__WIDTH                                     2
#define PMU_PMU9__CTR_REFENERGBOHY__MASK                            0x00000003U
#define PMU_PMU9__CTR_REFENERGBOHY__READ(src)   ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU9__CTR_REFENERGBOHY__WRITE(src)  ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU9__CTR_REFENERGBOHY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PMU_PMU9__CTR_REFENERGBOHY__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PMU_PMU9__CTR_REFENERGBOHY__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field ctr_mpptstartvharv */
/**
 * @defgroup pmu_top_regs_core_ctr_mpptstartvharv_field ctr_mpptstartvharv_field
 * @brief macros for field ctr_mpptstartvharv
 * @details unused
 * @{
 */
#define PMU_PMU9__CTR_MPPTSTARTVHARV__SHIFT                                   2
#define PMU_PMU9__CTR_MPPTSTARTVHARV__WIDTH                                   2
#define PMU_PMU9__CTR_MPPTSTARTVHARV__MASK                          0x0000000cU
#define PMU_PMU9__CTR_MPPTSTARTVHARV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define PMU_PMU9__CTR_MPPTSTARTVHARV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define PMU_PMU9__CTR_MPPTSTARTVHARV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define PMU_PMU9__CTR_MPPTSTARTVHARV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define PMU_PMU9__CTR_MPPTSTARTVHARV__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field ctr_rectreplmpp */
/**
 * @defgroup pmu_top_regs_core_ctr_rectreplmpp_field ctr_rectreplmpp_field
 * @brief macros for field ctr_rectreplmpp
 * @details mppt dynamic reference for SwchReqCanHarv comp
 * @{
 */
#define PMU_PMU9__CTR_RECTREPLMPP__SHIFT                                      4
#define PMU_PMU9__CTR_RECTREPLMPP__WIDTH                                      2
#define PMU_PMU9__CTR_RECTREPLMPP__MASK                             0x00000030U
#define PMU_PMU9__CTR_RECTREPLMPP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define PMU_PMU9__CTR_RECTREPLMPP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define PMU_PMU9__CTR_RECTREPLMPP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define PMU_PMU9__CTR_RECTREPLMPP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define PMU_PMU9__CTR_RECTREPLMPP__RESET_VALUE                      0x00000003U
/** @} */

/* macros for field ctr_rectreplmpp2 */
/**
 * @defgroup pmu_top_regs_core_ctr_rectreplmpp2_field ctr_rectreplmpp2_field
 * @brief macros for field ctr_rectreplmpp2
 * @details mppt dynamic reference for SwchReqMustHarv comp
 * @{
 */
#define PMU_PMU9__CTR_RECTREPLMPP2__SHIFT                                     6
#define PMU_PMU9__CTR_RECTREPLMPP2__WIDTH                                     2
#define PMU_PMU9__CTR_RECTREPLMPP2__MASK                            0x000000c0U
#define PMU_PMU9__CTR_RECTREPLMPP2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define PMU_PMU9__CTR_RECTREPLMPP2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define PMU_PMU9__CTR_RECTREPLMPP2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define PMU_PMU9__CTR_RECTREPLMPP2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define PMU_PMU9__CTR_RECTREPLMPP2__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field ctr_ldo_lowpow */
/**
 * @defgroup pmu_top_regs_core_ctr_ldo_lowpow_field ctr_ldo_lowpow_field
 * @brief macros for field ctr_ldo_lowpow
 * @details ctr_ldomem_lowref: enable the native amplifier for VrefBGdvddmem<700mV
 * @{
 */
#define PMU_PMU9__CTR_LDO_LOWPOW__SHIFT                                       8
#define PMU_PMU9__CTR_LDO_LOWPOW__WIDTH                                       1
#define PMU_PMU9__CTR_LDO_LOWPOW__MASK                              0x00000100U
#define PMU_PMU9__CTR_LDO_LOWPOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU9__CTR_LDO_LOWPOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU9__CTR_LDO_LOWPOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU9__CTR_LDO_LOWPOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU9__CTR_LDO_LOWPOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU9__CTR_LDO_LOWPOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU9__CTR_LDO_LOWPOW__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field ctr_ldo_smallPMOS */
/**
 * @defgroup pmu_top_regs_core_ctr_ldo_smallPMOS_field ctr_ldo_smallPMOS_field
 * @brief macros for field ctr_ldo_smallPMOS
 * @details ctr_ldomem_smallPMOS: enable the small PMOS output stage if leakage dominates at minimum DVDDmem load
 * @{
 */
#define PMU_PMU9__CTR_LDO_SMALLPMOS__SHIFT                                    9
#define PMU_PMU9__CTR_LDO_SMALLPMOS__WIDTH                                    1
#define PMU_PMU9__CTR_LDO_SMALLPMOS__MASK                           0x00000200U
#define PMU_PMU9__CTR_LDO_SMALLPMOS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU9__CTR_LDO_SMALLPMOS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU9__CTR_LDO_SMALLPMOS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU9__CTR_LDO_SMALLPMOS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU9__CTR_LDO_SMALLPMOS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU9__CTR_LDO_SMALLPMOS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU9__CTR_LDO_SMALLPMOS__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ctr_ldo_enftr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldo_enftr_field ctr_ldo_enftr_field
 * @brief macros for field ctr_ldo_enftr
 * @details ctr_ldomem_enftr: enable ldo_fast settling
 * @{
 */
#define PMU_PMU9__CTR_LDO_ENFTR__SHIFT                                       10
#define PMU_PMU9__CTR_LDO_ENFTR__WIDTH                                        1
#define PMU_PMU9__CTR_LDO_ENFTR__MASK                               0x00000400U
#define PMU_PMU9__CTR_LDO_ENFTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU9__CTR_LDO_ENFTR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU9__CTR_LDO_ENFTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU9__CTR_LDO_ENFTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU9__CTR_LDO_ENFTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU9__CTR_LDO_ENFTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU9__CTR_LDO_ENFTR__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field trans_wait_reg */
/**
 * @defgroup pmu_top_regs_core_trans_wait_reg_field trans_wait_reg_field
 * @brief macros for field trans_wait_reg
 * @details wait time in transient state when going from low power to active
 * @{
 */
#define PMU_PMU9__TRANS_WAIT_REG__SHIFT                                      11
#define PMU_PMU9__TRANS_WAIT_REG__WIDTH                                       7
#define PMU_PMU9__TRANS_WAIT_REG__MASK                              0x0003f800U
#define PMU_PMU9__TRANS_WAIT_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f800U) >> 11)
#define PMU_PMU9__TRANS_WAIT_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0003f800U)
#define PMU_PMU9__TRANS_WAIT_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f800U) | (((uint32_t)(src) <<\
                    11) & 0x0003f800U)
#define PMU_PMU9__TRANS_WAIT_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0003f800U)))
#define PMU_PMU9__TRANS_WAIT_REG__RESET_VALUE                       0x00000014U
/** @} */

/* macros for field ctr_swresdvdd_bypass_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_swresdvdd_bypass_ovr_field ctr_swresdvdd_bypass_ovr_field
 * @brief macros for field ctr_swresdvdd_bypass_ovr
 * @details override ctr_swresdvdd_bypass
 * @{
 */
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__SHIFT                            18
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__WIDTH                             1
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__MASK                    0x00040000U
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_swresdvdd_bypass_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_swresdvdd_bypass_ovr_val_field ctr_swresdvdd_bypass_ovr_val_field
 * @brief macros for field ctr_swresdvdd_bypass_ovr_val
 * @details override ctr_swresdvdd_bypass val: bypass L1 dvdd swres
 * @{
 */
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__SHIFT                        19
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__WIDTH                         1
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__MASK                0x00080000U
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU9__CTR_SWRESDVDD_BYPASS_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ctr_ldoL1avdd_bypass_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1avdd_bypass_ovr_field ctr_ldoL1avdd_bypass_ovr_field
 * @brief macros for field ctr_ldoL1avdd_bypass_ovr
 * @details override ctr_ldoL1avdd_bypass
 * @{
 */
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__SHIFT                            20
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__WIDTH                             1
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__MASK                    0x00100000U
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_ldoL1avdd_bypass_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1avdd_bypass_ovr_val_field ctr_ldoL1avdd_bypass_ovr_val_field
 * @brief macros for field ctr_ldoL1avdd_bypass_ovr_val
 * @details override ctr_ldoL1avdd_bypass val: bypass L1 avdd LDO
 * @{
 */
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__SHIFT                        21
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__WIDTH                         1
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__MASK                0x00200000U
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU9__CTR_LDOL1AVDD_BYPASS_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ctr_swresavdd_bypass_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_swresavdd_bypass_ovr_field ctr_swresavdd_bypass_ovr_field
 * @brief macros for field ctr_swresavdd_bypass_ovr
 * @details override ctr_swresavdd_bypass
 * @{
 */
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__SHIFT                            22
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__WIDTH                             1
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__MASK                    0x00400000U
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_swresavdd_bypass_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_swresavdd_bypass_ovr_val_field ctr_swresavdd_bypass_ovr_val_field
 * @brief macros for field ctr_swresavdd_bypass_ovr_val
 * @details override ctr_swresavdd_bypass val: bypass L1 avdd swres
 * @{
 */
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__SHIFT                        23
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__WIDTH                         1
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__MASK                0x00800000U
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU9__CTR_SWRESAVDD_BYPASS_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ctr_ldoL1dvdd_bypass_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1dvdd_bypass_ovr_field ctr_ldoL1dvdd_bypass_ovr_field
 * @brief macros for field ctr_ldoL1dvdd_bypass_ovr
 * @details override ctr_ldoL1dvdd_bypass
 * @{
 */
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__SHIFT                            24
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__WIDTH                             1
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__MASK                    0x01000000U
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_ldoL1dvdd_bypass_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1dvdd_bypass_ovr_val_field ctr_ldoL1dvdd_bypass_ovr_val_field
 * @brief macros for field ctr_ldoL1dvdd_bypass_ovr_val
 * @details override ctr_ldoL1dvdd_bypass val: bypass L1 dvdd LDO
 * @{
 */
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__SHIFT                        25
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__WIDTH                         1
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__MASK                0x02000000U
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU9__CTR_LDOL1DVDD_BYPASS_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ctr_ldoL1vddio_bypass_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1vddio_bypass_ovr_field ctr_ldoL1vddio_bypass_ovr_field
 * @brief macros for field ctr_ldoL1vddio_bypass_ovr
 * @details override ctr_ldoL1vddio_bypass
 * @{
 */
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__SHIFT                           26
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__WIDTH                            1
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__MASK                   0x04000000U
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ctr_ldoL1vddio_bypass_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1vddio_bypass_ovr_val_field ctr_ldoL1vddio_bypass_ovr_val_field
 * @brief macros for field ctr_ldoL1vddio_bypass_ovr_val
 * @details override ctr_ldoL1vddio_bypass val: bypass L1 vddio LDO
 * @{
 */
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__SHIFT                       27
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__WIDTH                        1
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__MASK               0x08000000U
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU9__CTR_LDOL1VDDIO_BYPASS_OVR_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ctr_swresvddio_bypass_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_swresvddio_bypass_ovr_field ctr_swresvddio_bypass_ovr_field
 * @brief macros for field ctr_swresvddio_bypass_ovr
 * @details override ctr_swresvddio_bypass
 * @{
 */
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__SHIFT                           28
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__WIDTH                            1
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__MASK                   0x10000000U
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ctr_swresvddio_bypass_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_swresvddio_bypass_ovr_val_field ctr_swresvddio_bypass_ovr_val_field
 * @brief macros for field ctr_swresvddio_bypass_ovr_val
 * @details override ctr_swresvddio_bypass val: bypass L1 vddio swres
 * @{
 */
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__SHIFT                       29
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__WIDTH                        1
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__MASK               0x20000000U
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU9__CTR_SWRESVDDIO_BYPASS_OVR_VAL__RESET_VALUE        0x00000000U
/** @} */
#define PMU_PMU9__TYPE                                                 uint32_t
#define PMU_PMU9__READ                                              0x3fffffffU
#define PMU_PMU9__WRITE                                             0x3fffffffU
#define PMU_PMU9__PRESERVED                                         0x00000000U
#define PMU_PMU9__RESET_VALUE                                       0x0000a4f5U

#endif /* __PMU_PMU9_MACRO__ */

/** @} end of pmu9 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu10 */
/**
 * @defgroup pmu_top_regs_core_pmu10 pmu10
 * @brief more pmu controls/ reference selects definitions.
 * @{
 */
#ifndef __PMU_PMU10_MACRO__
#define __PMU_PMU10_MACRO__

/* macros for field harv_ctrcu */
/**
 * @defgroup pmu_top_regs_core_harv_ctrcu_field harv_ctrcu_field
 * @brief macros for field harv_ctrcu
 * @details current control for can/mustharv comparators
 * @{
 */
#define PMU_PMU10__HARV_CTRCU__SHIFT                                          0
#define PMU_PMU10__HARV_CTRCU__WIDTH                                          7
#define PMU_PMU10__HARV_CTRCU__MASK                                 0x0000007fU
#define PMU_PMU10__HARV_CTRCU__READ(src)        ((uint32_t)(src) & 0x0000007fU)
#define PMU_PMU10__HARV_CTRCU__WRITE(src)       ((uint32_t)(src) & 0x0000007fU)
#define PMU_PMU10__HARV_CTRCU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define PMU_PMU10__HARV_CTRCU__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define PMU_PMU10__HARV_CTRCU__RESET_VALUE                          0x0000000bU
/** @} */

/* macros for field bg_active */
/**
 * @defgroup pmu_top_regs_core_bg_active_field bg_active_field
 * @brief macros for field bg_active
 * @details bandgap ref for active mode, 0 for NATIVE, 1 for PMUBG
 * @{
 */
#define PMU_PMU10__BG_ACTIVE__SHIFT                                           7
#define PMU_PMU10__BG_ACTIVE__WIDTH                                           1
#define PMU_PMU10__BG_ACTIVE__MASK                                  0x00000080U
#define PMU_PMU10__BG_ACTIVE__READ(src)  (((uint32_t)(src) & 0x00000080U) >> 7)
#define PMU_PMU10__BG_ACTIVE__WRITE(src) (((uint32_t)(src) << 7) & 0x00000080U)
#define PMU_PMU10__BG_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_PMU10__BG_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_PMU10__BG_ACTIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU10__BG_ACTIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU10__BG_ACTIVE__RESET_VALUE                           0x00000001U
/** @} */

/* macros for field bg_socoff */
/**
 * @defgroup pmu_top_regs_core_bg_socoff_field bg_socoff_field
 * @brief macros for field bg_socoff
 * @details bandgap ref for soc-off mode, 0 for NATIVE, 1 for PMUBG
 * @{
 */
#define PMU_PMU10__BG_SOCOFF__SHIFT                                           8
#define PMU_PMU10__BG_SOCOFF__WIDTH                                           1
#define PMU_PMU10__BG_SOCOFF__MASK                                  0x00000100U
#define PMU_PMU10__BG_SOCOFF__READ(src)  (((uint32_t)(src) & 0x00000100U) >> 8)
#define PMU_PMU10__BG_SOCOFF__WRITE(src) (((uint32_t)(src) << 8) & 0x00000100U)
#define PMU_PMU10__BG_SOCOFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU10__BG_SOCOFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU10__BG_SOCOFF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU10__BG_SOCOFF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU10__BG_SOCOFF__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field bg_hibernate */
/**
 * @defgroup pmu_top_regs_core_bg_hibernate_field bg_hibernate_field
 * @brief macros for field bg_hibernate
 * @details bandgap ref for hibernate mode, 0 for NATIVE, 1 for PMUBG
 * @{
 */
#define PMU_PMU10__BG_HIBERNATE__SHIFT                                        9
#define PMU_PMU10__BG_HIBERNATE__WIDTH                                        1
#define PMU_PMU10__BG_HIBERNATE__MASK                               0x00000200U
#define PMU_PMU10__BG_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU10__BG_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU10__BG_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU10__BG_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU10__BG_HIBERNATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU10__BG_HIBERNATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU10__BG_HIBERNATE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field bg_retain */
/**
 * @defgroup pmu_top_regs_core_bg_retain_field bg_retain_field
 * @brief macros for field bg_retain
 * @details bandgap ref for retention mode, 0 for NATIVE, 1 for PMUBG
 * @{
 */
#define PMU_PMU10__BG_RETAIN__SHIFT                                          10
#define PMU_PMU10__BG_RETAIN__WIDTH                                           1
#define PMU_PMU10__BG_RETAIN__MASK                                  0x00000400U
#define PMU_PMU10__BG_RETAIN__READ(src) (((uint32_t)(src) & 0x00000400U) >> 10)
#define PMU_PMU10__BG_RETAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU10__BG_RETAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU10__BG_RETAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU10__BG_RETAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU10__BG_RETAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU10__BG_RETAIN__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field vtrack_hibernate */
/**
 * @defgroup pmu_top_regs_core_vtrack_hibernate_field vtrack_hibernate_field
 * @brief macros for field vtrack_hibernate
 * @details tracking selected for hibernate , 0 for TRACK07, 1 for TRACK1
 * @{
 */
#define PMU_PMU10__VTRACK_HIBERNATE__SHIFT                                   11
#define PMU_PMU10__VTRACK_HIBERNATE__WIDTH                                    1
#define PMU_PMU10__VTRACK_HIBERNATE__MASK                           0x00000800U
#define PMU_PMU10__VTRACK_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU10__VTRACK_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU10__VTRACK_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU10__VTRACK_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU10__VTRACK_HIBERNATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU10__VTRACK_HIBERNATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU10__VTRACK_HIBERNATE__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field unused */
/**
 * @defgroup pmu_top_regs_core_unused_field unused_field
 * @brief macros for field unused
 * @details unused spare, pmu_spares[6]
 * @{
 */
#define PMU_PMU10__UNUSED__SHIFT                                             12
#define PMU_PMU10__UNUSED__WIDTH                                              1
#define PMU_PMU10__UNUSED__MASK                                     0x00001000U
#define PMU_PMU10__UNUSED__READ(src)    (((uint32_t)(src) & 0x00001000U) >> 12)
#define PMU_PMU10__UNUSED__WRITE(src)   (((uint32_t)(src) << 12) & 0x00001000U)
#define PMU_PMU10__UNUSED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU10__UNUSED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU10__UNUSED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU10__UNUSED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU10__UNUSED__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field dvddref_active */
/**
 * @defgroup pmu_top_regs_core_dvddref_active_field dvddref_active_field
 * @brief macros for field dvddref_active
 * @details which ref to be used in active mode, 1 for REFGEN, 0 for TRACK
 * @{
 */
#define PMU_PMU10__DVDDREF_ACTIVE__SHIFT                                     13
#define PMU_PMU10__DVDDREF_ACTIVE__WIDTH                                      1
#define PMU_PMU10__DVDDREF_ACTIVE__MASK                             0x00002000U
#define PMU_PMU10__DVDDREF_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU10__DVDDREF_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU10__DVDDREF_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU10__DVDDREF_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU10__DVDDREF_ACTIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU10__DVDDREF_ACTIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU10__DVDDREF_ACTIVE__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field dvddref_socoff */
/**
 * @defgroup pmu_top_regs_core_dvddref_socoff_field dvddref_socoff_field
 * @brief macros for field dvddref_socoff
 * @details which ref to be used in soc-off mode, 1 for REFGEN, 0 for TRACK
 * @{
 */
#define PMU_PMU10__DVDDREF_SOCOFF__SHIFT                                     14
#define PMU_PMU10__DVDDREF_SOCOFF__WIDTH                                      1
#define PMU_PMU10__DVDDREF_SOCOFF__MASK                             0x00004000U
#define PMU_PMU10__DVDDREF_SOCOFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU10__DVDDREF_SOCOFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU10__DVDDREF_SOCOFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU10__DVDDREF_SOCOFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU10__DVDDREF_SOCOFF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU10__DVDDREF_SOCOFF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU10__DVDDREF_SOCOFF__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field dvddref_hibernate */
/**
 * @defgroup pmu_top_regs_core_dvddref_hibernate_field dvddref_hibernate_field
 * @brief macros for field dvddref_hibernate
 * @details which ref to be used in hibernate mode, 1 for REFGEN, 0 for TRACK
 * @{
 */
#define PMU_PMU10__DVDDREF_HIBERNATE__SHIFT                                  15
#define PMU_PMU10__DVDDREF_HIBERNATE__WIDTH                                   1
#define PMU_PMU10__DVDDREF_HIBERNATE__MASK                          0x00008000U
#define PMU_PMU10__DVDDREF_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU10__DVDDREF_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU10__DVDDREF_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU10__DVDDREF_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU10__DVDDREF_HIBERNATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU10__DVDDREF_HIBERNATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU10__DVDDREF_HIBERNATE__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field dvddref_retain */
/**
 * @defgroup pmu_top_regs_core_dvddref_retain_field dvddref_retain_field
 * @brief macros for field dvddref_retain
 * @details which ref to be used in retain mode, 1 for REFGEN, 0 for TRACK
 * @{
 */
#define PMU_PMU10__DVDDREF_RETAIN__SHIFT                                     16
#define PMU_PMU10__DVDDREF_RETAIN__WIDTH                                      1
#define PMU_PMU10__DVDDREF_RETAIN__MASK                             0x00010000U
#define PMU_PMU10__DVDDREF_RETAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU10__DVDDREF_RETAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU10__DVDDREF_RETAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU10__DVDDREF_RETAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU10__DVDDREF_RETAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU10__DVDDREF_RETAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU10__DVDDREF_RETAIN__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field enableHarv2Sup_ovr */
/**
 * @defgroup pmu_top_regs_core_enableHarv2Sup_ovr_field enableHarv2Sup_ovr_field
 * @brief macros for field enableHarv2Sup_ovr
 * @details override enableHarv2Sup
 * @{
 */
#define PMU_PMU10__ENABLEHARV2SUP_OVR__SHIFT                                 17
#define PMU_PMU10__ENABLEHARV2SUP_OVR__WIDTH                                  1
#define PMU_PMU10__ENABLEHARV2SUP_OVR__MASK                         0x00020000U
#define PMU_PMU10__ENABLEHARV2SUP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU10__ENABLEHARV2SUP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU10__ENABLEHARV2SUP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU10__ENABLEHARV2SUP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU10__ENABLEHARV2SUP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU10__ENABLEHARV2SUP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU10__ENABLEHARV2SUP_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field enableHarv2Sup_ovr_val */
/**
 * @defgroup pmu_top_regs_core_enableHarv2Sup_ovr_val_field enableHarv2Sup_ovr_val_field
 * @brief macros for field enableHarv2Sup_ovr_val
 * @details override enableHarv2Sup val: enable harv to supply. If disabled it is only harv to vstore
 * @{
 */
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__SHIFT                             18
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__WIDTH                              1
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__MASK                     0x00040000U
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU10__ENABLEHARV2SUP_OVR_VAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field manual_harv_disable */
/**
 * @defgroup pmu_top_regs_core_manual_harv_disable_field manual_harv_disable_field
 * @brief macros for field manual_harv_disable
 * @details manually disable harvesters
 * @{
 */
#define PMU_PMU10__MANUAL_HARV_DISABLE__SHIFT                                19
#define PMU_PMU10__MANUAL_HARV_DISABLE__WIDTH                                 1
#define PMU_PMU10__MANUAL_HARV_DISABLE__MASK                        0x00080000U
#define PMU_PMU10__MANUAL_HARV_DISABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU10__MANUAL_HARV_DISABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU10__MANUAL_HARV_DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU10__MANUAL_HARV_DISABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU10__MANUAL_HARV_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU10__MANUAL_HARV_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU10__MANUAL_HARV_DISABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field dvddlow */
/**
 * @defgroup pmu_top_regs_core_dvddlow_field dvddlow_field
 * @brief macros for field dvddlow
 * @details connect DVDDmem and DVDDmain both to a lower dvdd
 * @{
 */
#define PMU_PMU10__DVDDLOW__SHIFT                                            20
#define PMU_PMU10__DVDDLOW__WIDTH                                             1
#define PMU_PMU10__DVDDLOW__MASK                                    0x00100000U
#define PMU_PMU10__DVDDLOW__READ(src)   (((uint32_t)(src) & 0x00100000U) >> 20)
#define PMU_PMU10__DVDDLOW__WRITE(src)  (((uint32_t)(src) << 20) & 0x00100000U)
#define PMU_PMU10__DVDDLOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU10__DVDDLOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU10__DVDDLOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU10__DVDDLOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU10__DVDDLOW__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field SwchReqDVDD_enswres_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_enswres_ovr_field SwchReqDVDD_enswres_ovr_field
 * @brief macros for field SwchReqDVDD_enswres_ovr
 * @details override SwchReqDVDD_enswres
 * @{
 */
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__SHIFT                            21
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__WIDTH                             1
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__MASK                    0x00200000U
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field SwchReqDVDD_enswres_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_enswres_ovr_val_field SwchReqDVDD_enswres_ovr_val_field
 * @brief macros for field SwchReqDVDD_enswres_ovr_val
 * @details override SwchReqDVDD_enswres val: dvdd request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__SHIFT                        22
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__WIDTH                         1
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__MASK                0x00400000U
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU10__SWCHREQDVDD_ENSWRES_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field SwchReqAVDD_enswres_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_enswres_ovr_field SwchReqAVDD_enswres_ovr_field
 * @brief macros for field SwchReqAVDD_enswres_ovr
 * @details override SwchReqAVDD_enswres
 * @{
 */
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__SHIFT                            23
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__WIDTH                             1
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__MASK                    0x00800000U
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field SwchReqAVDD_enswres_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_enswres_ovr_val_field SwchReqAVDD_enswres_ovr_val_field
 * @brief macros for field SwchReqAVDD_enswres_ovr_val
 * @details override SwchReqAVDD_enswres val: avdd request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__SHIFT                        24
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__WIDTH                         1
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__MASK                0x01000000U
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU10__SWCHREQAVDD_ENSWRES_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_enswres_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_enswres_ovr_field SwchReqVDDIO_enswres_ovr_field
 * @brief macros for field SwchReqVDDIO_enswres_ovr
 * @details override SwchReqVDDIO_enswres
 * @{
 */
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__SHIFT                           25
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__WIDTH                            1
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__MASK                   0x02000000U
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_enswres_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_enswres_ovr_val_field SwchReqVDDIO_enswres_ovr_val_field
 * @brief macros for field SwchReqVDDIO_enswres_ovr_val
 * @details override SwchReqVDDIO_enswres val: vddio request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__SHIFT                       26
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__WIDTH                        1
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__MASK               0x04000000U
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU10__SWCHREQVDDIO_ENSWRES_OVR_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field disableb_L1_ldos */
/**
 * @defgroup pmu_top_regs_core_disableb_L1_ldos_field disableb_L1_ldos_field
 * @brief macros for field disableb_L1_ldos
 * @details enable using the L1 LDOs based on pmuadc control
 * @{
 */
#define PMU_PMU10__DISABLEB_L1_LDOS__SHIFT                                   27
#define PMU_PMU10__DISABLEB_L1_LDOS__WIDTH                                    1
#define PMU_PMU10__DISABLEB_L1_LDOS__MASK                           0x08000000U
#define PMU_PMU10__DISABLEB_L1_LDOS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU10__DISABLEB_L1_LDOS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU10__DISABLEB_L1_LDOS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU10__DISABLEB_L1_LDOS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU10__DISABLEB_L1_LDOS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU10__DISABLEB_L1_LDOS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU10__DISABLEB_L1_LDOS__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field tinySourceStore_ovr */
/**
 * @defgroup pmu_top_regs_core_tinySourceStore_ovr_field tinySourceStore_ovr_field
 * @brief macros for field tinySourceStore_ovr
 * @details override and assert tinySourceStore, use store as source with tiny FSM
 * @{
 */
#define PMU_PMU10__TINYSOURCESTORE_OVR__SHIFT                                28
#define PMU_PMU10__TINYSOURCESTORE_OVR__WIDTH                                 1
#define PMU_PMU10__TINYSOURCESTORE_OVR__MASK                        0x10000000U
#define PMU_PMU10__TINYSOURCESTORE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU10__TINYSOURCESTORE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU10__TINYSOURCESTORE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU10__TINYSOURCESTORE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU10__TINYSOURCESTORE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU10__TINYSOURCESTORE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU10__TINYSOURCESTORE_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field increctst_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_increctst_encomp_ovr_field increctst_encomp_ovr_field
 * @brief macros for field increctst_encomp_ovr
 * @details override increctst_encomp
 * @{
 */
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__SHIFT                               29
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__WIDTH                                1
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__MASK                       0x20000000U
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field increctst_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_increctst_encomp_ovr_val_field increctst_encomp_ovr_val_field
 * @brief macros for field increctst_encomp_ovr_val
 * @details override increctst_encomp val: enable chpuhsw_increctstage comparator
 * @{
 */
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__SHIFT                           30
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__WIDTH                            1
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__MASK                   0x40000000U
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU10__INCRECTST_ENCOMP_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */
#define PMU_PMU10__TYPE                                                uint32_t
#define PMU_PMU10__READ                                             0x7fffffffU
#define PMU_PMU10__WRITE                                            0x7fffffffU
#define PMU_PMU10__PRESERVED                                        0x00000000U
#define PMU_PMU10__RESET_VALUE                                      0x0801a08bU

#endif /* __PMU_PMU10_MACRO__ */

/** @} end of pmu10 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu11 */
/**
 * @defgroup pmu_top_regs_core_pmu11 pmu11
 * @brief atb and clocks definitions.
 * @{
 */
#ifndef __PMU_PMU11_MACRO__
#define __PMU_PMU11_MACRO__

/* macros for field wurx_clk_en */
/**
 * @defgroup pmu_top_regs_core_wurx_clk_en_field wurx_clk_en_field
 * @brief macros for field wurx_clk_en
 * @details clk enable for wurx 32KHz clk
 * @{
 */
#define PMU_PMU11__WURX_CLK_EN__SHIFT                                         0
#define PMU_PMU11__WURX_CLK_EN__WIDTH                                         1
#define PMU_PMU11__WURX_CLK_EN__MASK                                0x00000001U
#define PMU_PMU11__WURX_CLK_EN__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU11__WURX_CLK_EN__WRITE(src)      ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU11__WURX_CLK_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU11__WURX_CLK_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU11__WURX_CLK_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU11__WURX_CLK_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU11__WURX_CLK_EN__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field dig_clk_en */
/**
 * @defgroup pmu_top_regs_core_dig_clk_en_field dig_clk_en_field
 * @brief macros for field dig_clk_en
 * @details clk enable for digital 32KHz clk
 * @{
 */
#define PMU_PMU11__DIG_CLK_EN__SHIFT                                          1
#define PMU_PMU11__DIG_CLK_EN__WIDTH                                          1
#define PMU_PMU11__DIG_CLK_EN__MASK                                 0x00000002U
#define PMU_PMU11__DIG_CLK_EN__READ(src) (((uint32_t)(src) & 0x00000002U) >> 1)
#define PMU_PMU11__DIG_CLK_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU11__DIG_CLK_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU11__DIG_CLK_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU11__DIG_CLK_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU11__DIG_CLK_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU11__DIG_CLK_EN__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field atb_en */
/**
 * @defgroup pmu_top_regs_core_atb_en_field atb_en_field
 * @brief macros for field atb_en
 * @details atb enable for pmu
 * @{
 */
#define PMU_PMU11__ATB_EN__SHIFT                                              2
#define PMU_PMU11__ATB_EN__WIDTH                                              1
#define PMU_PMU11__ATB_EN__MASK                                     0x00000004U
#define PMU_PMU11__ATB_EN__READ(src)     (((uint32_t)(src) & 0x00000004U) >> 2)
#define PMU_PMU11__ATB_EN__WRITE(src)    (((uint32_t)(src) << 2) & 0x00000004U)
#define PMU_PMU11__ATB_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU11__ATB_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU11__ATB_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU11__ATB_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU11__ATB_EN__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field atb_select */
/**
 * @defgroup pmu_top_regs_core_atb_select_field atb_select_field
 * @brief macros for field atb_select
 * @details atb selects for pmu11010 VBG600mT11001 vrefnat600T11000 vrefnat900T10111 refladT210110 refladT110101 refladT010100 refladfastT110011 refladfastT010010 VrefdvddmemT10001 VrefdvddcpuT10000 VrefBGdvddT01111 vrefporpmuT01110 VrefvbattgoodT01101 vrefstogoodtoEnerST01100 DVDDmem01011 DVDDcpu01010 avddldoint01001 VrefTRdvddTVrefTRdvddT01000 VrectstagerepldivlowT00111 VrectstagerepldivhighT00110 vrefcanharvT00101 vrefmustharvT00100 porb_vddpmu_HT00011 Vreflpc000010 Vreflpc100001 refi_reconfT00000 vrefcalpmuadcT
 * @{
 */
#define PMU_PMU11__ATB_SELECT__SHIFT                                          3
#define PMU_PMU11__ATB_SELECT__WIDTH                                          5
#define PMU_PMU11__ATB_SELECT__MASK                                 0x000000f8U
#define PMU_PMU11__ATB_SELECT__READ(src) (((uint32_t)(src) & 0x000000f8U) >> 3)
#define PMU_PMU11__ATB_SELECT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x000000f8U)
#define PMU_PMU11__ATB_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f8U) | (((uint32_t)(src) <<\
                    3) & 0x000000f8U)
#define PMU_PMU11__ATB_SELECT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x000000f8U)))
#define PMU_PMU11__ATB_SELECT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field lpcomp_ref_fall */
/**
 * @defgroup pmu_top_regs_core_lpcomp_ref_fall_field lpcomp_ref_fall_field
 * @brief macros for field lpcomp_ref_fall
 * @details falling edge reference select for lpcomp hysteresis, should be set lower than lpcomp_ref_rise25*[65,61,57,53,49,45,41,37,33,29,25,21,17,13,9,5] for i=[15:0]
 * @{
 */
#define PMU_PMU11__LPCOMP_REF_FALL__SHIFT                                     8
#define PMU_PMU11__LPCOMP_REF_FALL__WIDTH                                     4
#define PMU_PMU11__LPCOMP_REF_FALL__MASK                            0x00000f00U
#define PMU_PMU11__LPCOMP_REF_FALL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define PMU_PMU11__LPCOMP_REF_FALL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define PMU_PMU11__LPCOMP_REF_FALL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define PMU_PMU11__LPCOMP_REF_FALL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define PMU_PMU11__LPCOMP_REF_FALL__RESET_VALUE                     0x00000008U
/** @} */

/* macros for field lpcomp_ref */
/**
 * @defgroup pmu_top_regs_core_lpcomp_ref_field lpcomp_ref_field
 * @brief macros for field lpcomp_ref
 * @details rising edge reference select for lpcomp25*[66,62,58,54,50,46,42,38,34,30,26,22,18,14,10,6] for i=[15:0]
 * @{
 */
#define PMU_PMU11__LPCOMP_REF__SHIFT                                         12
#define PMU_PMU11__LPCOMP_REF__WIDTH                                          4
#define PMU_PMU11__LPCOMP_REF__MASK                                 0x0000f000U
#define PMU_PMU11__LPCOMP_REF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PMU_PMU11__LPCOMP_REF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PMU_PMU11__LPCOMP_REF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PMU_PMU11__LPCOMP_REF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PMU_PMU11__LPCOMP_REF__RESET_VALUE                          0x00000009U
/** @} */

/* macros for field lpcomp_atb_sel */
/**
 * @defgroup pmu_top_regs_core_lpcomp_atb_sel_field lpcomp_atb_sel_field
 * @brief macros for field lpcomp_atb_sel
 * @details atbselect for lpcomp
 * @{
 */
#define PMU_PMU11__LPCOMP_ATB_SEL__SHIFT                                     16
#define PMU_PMU11__LPCOMP_ATB_SEL__WIDTH                                      1
#define PMU_PMU11__LPCOMP_ATB_SEL__MASK                             0x00010000U
#define PMU_PMU11__LPCOMP_ATB_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU11__LPCOMP_ATB_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU11__LPCOMP_ATB_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU11__LPCOMP_ATB_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU11__LPCOMP_ATB_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU11__LPCOMP_ATB_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU11__LPCOMP_ATB_SEL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pmu_pin_mux_sel */
/**
 * @defgroup pmu_top_regs_core_pmu_pin_mux_sel_field pmu_pin_mux_sel_field
 * @brief macros for field pmu_pin_mux_sel
 * @details pin mux select from analog
 * @{
 */
#define PMU_PMU11__PMU_PIN_MUX_SEL__SHIFT                                    17
#define PMU_PMU11__PMU_PIN_MUX_SEL__WIDTH                                     2
#define PMU_PMU11__PMU_PIN_MUX_SEL__MASK                            0x00060000U
#define PMU_PMU11__PMU_PIN_MUX_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define PMU_PMU11__PMU_PIN_MUX_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define PMU_PMU11__PMU_PIN_MUX_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define PMU_PMU11__PMU_PIN_MUX_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define PMU_PMU11__PMU_PIN_MUX_SEL__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field ctr_ref_gadc */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_gadc_field ctr_ref_gadc_field
 * @brief macros for field ctr_ref_gadc
 * @details reference for gadc25*(24+i)mV, i=0:3
 * @{
 */
#define PMU_PMU11__CTR_REF_GADC__SHIFT                                       19
#define PMU_PMU11__CTR_REF_GADC__WIDTH                                        2
#define PMU_PMU11__CTR_REF_GADC__MASK                               0x00180000U
#define PMU_PMU11__CTR_REF_GADC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define PMU_PMU11__CTR_REF_GADC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define PMU_PMU11__CTR_REF_GADC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define PMU_PMU11__CTR_REF_GADC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define PMU_PMU11__CTR_REF_GADC__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field gadc_cutvdd_b_ovr */
/**
 * @defgroup pmu_top_regs_core_gadc_cutvdd_b_ovr_field gadc_cutvdd_b_ovr_field
 * @brief macros for field gadc_cutvdd_b_ovr
 * @details override gadc_cutvdd_b
 * @{
 */
#define PMU_PMU11__GADC_CUTVDD_B_OVR__SHIFT                                  21
#define PMU_PMU11__GADC_CUTVDD_B_OVR__WIDTH                                   1
#define PMU_PMU11__GADC_CUTVDD_B_OVR__MASK                          0x00200000U
#define PMU_PMU11__GADC_CUTVDD_B_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU11__GADC_CUTVDD_B_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU11__GADC_CUTVDD_B_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU11__GADC_CUTVDD_B_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU11__GADC_CUTVDD_B_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU11__GADC_CUTVDD_B_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU11__GADC_CUTVDD_B_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field gadc_cutvdd_b_ovr_val */
/**
 * @defgroup pmu_top_regs_core_gadc_cutvdd_b_ovr_val_field gadc_cutvdd_b_ovr_val_field
 * @brief macros for field gadc_cutvdd_b_ovr_val
 * @details override gadc_cutvdd_b val: Turn ON the gadc hsw
 * @{
 */
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__SHIFT                              22
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__WIDTH                               1
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__MASK                      0x00400000U
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU11__GADC_CUTVDD_B_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field otp_disable_xtal32K_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_disable_xtal32K_ovr_val_field otp_disable_xtal32K_ovr_val_field
 * @brief macros for field otp_disable_xtal32K_ovr_val
 * @details override for xtal32K
 * @{
 */
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__SHIFT                        23
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__WIDTH                         1
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__MASK                0x00800000U
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU11__OTP_DISABLE_XTAL32K_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field otp_spare_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_spare_ovr_val_field otp_spare_ovr_val_field
 * @brief macros for field otp_spare_ovr_val
 * @details new for paris
 * @{
 */
#define PMU_PMU11__OTP_SPARE_OVR_VAL__SHIFT                                  24
#define PMU_PMU11__OTP_SPARE_OVR_VAL__WIDTH                                   1
#define PMU_PMU11__OTP_SPARE_OVR_VAL__MASK                          0x01000000U
#define PMU_PMU11__OTP_SPARE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU11__OTP_SPARE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU11__OTP_SPARE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU11__OTP_SPARE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU11__OTP_SPARE_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU11__OTP_SPARE_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU11__OTP_SPARE_OVR_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field otp_ldo_ovr */
/**
 * @defgroup pmu_top_regs_core_otp_ldo_ovr_field otp_ldo_ovr_field
 * @brief macros for field otp_ldo_ovr
 * @details override otp_use_ldo
 * @{
 */
#define PMU_PMU11__OTP_LDO_OVR__SHIFT                                        25
#define PMU_PMU11__OTP_LDO_OVR__WIDTH                                         1
#define PMU_PMU11__OTP_LDO_OVR__MASK                                0x02000000U
#define PMU_PMU11__OTP_LDO_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU11__OTP_LDO_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU11__OTP_LDO_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU11__OTP_LDO_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU11__OTP_LDO_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU11__OTP_LDO_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU11__OTP_LDO_OVR__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field otp_brownout_ovr */
/**
 * @defgroup pmu_top_regs_core_otp_brownout_ovr_field otp_brownout_ovr_field
 * @brief macros for field otp_brownout_ovr
 * @details override otp_vbatt_brownout
 * @{
 */
#define PMU_PMU11__OTP_BROWNOUT_OVR__SHIFT                                   26
#define PMU_PMU11__OTP_BROWNOUT_OVR__WIDTH                                    1
#define PMU_PMU11__OTP_BROWNOUT_OVR__MASK                           0x04000000U
#define PMU_PMU11__OTP_BROWNOUT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU11__OTP_BROWNOUT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU11__OTP_BROWNOUT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU11__OTP_BROWNOUT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU11__OTP_BROWNOUT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU11__OTP_BROWNOUT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU11__OTP_BROWNOUT_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field otp_vddio_ovr */
/**
 * @defgroup pmu_top_regs_core_otp_vddio_ovr_field otp_vddio_ovr_field
 * @brief macros for field otp_vddio_ovr
 * @details override otp_vddio_range
 * @{
 */
#define PMU_PMU11__OTP_VDDIO_OVR__SHIFT                                      27
#define PMU_PMU11__OTP_VDDIO_OVR__WIDTH                                       1
#define PMU_PMU11__OTP_VDDIO_OVR__MASK                              0x08000000U
#define PMU_PMU11__OTP_VDDIO_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU11__OTP_VDDIO_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU11__OTP_VDDIO_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU11__OTP_VDDIO_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU11__OTP_VDDIO_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU11__OTP_VDDIO_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU11__OTP_VDDIO_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field en_mem_hsw_b_late_ovr */
/**
 * @defgroup pmu_top_regs_core_en_mem_hsw_b_late_ovr_field en_mem_hsw_b_late_ovr_field
 * @brief macros for field en_mem_hsw_b_late_ovr
 * @details override for en_mem_hsw_b_late
 * @{
 */
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__SHIFT                              28
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__WIDTH                               1
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__MASK                      0x10000000U
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field en_mem_hsw_b_late_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_mem_hsw_b_late_ovr_val_field en_mem_hsw_b_late_ovr_val_field
 * @brief macros for field en_mem_hsw_b_late_ovr_val
 * @details override for en_mem_hsw_b_late val: Turn OFF memory late hsw
 * @{
 */
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__SHIFT                          29
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__WIDTH                           1
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__MASK                  0x20000000U
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU11__EN_MEM_HSW_B_LATE_OVR_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field en_sw_hsw_b_late_ovr */
/**
 * @defgroup pmu_top_regs_core_en_sw_hsw_b_late_ovr_field en_sw_hsw_b_late_ovr_field
 * @brief macros for field en_sw_hsw_b_late_ovr
 * @details override en_sw_hsw_b_late
 * @{
 */
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__SHIFT                               30
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__WIDTH                                1
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__MASK                       0x40000000U
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field en_sw_hsw_b_late_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_sw_hsw_b_late_ovr_val_field en_sw_hsw_b_late_ovr_val_field
 * @brief macros for field en_sw_hsw_b_late_ovr_val
 * @details override en_sw_hsw_b_late val: Turn OFF switcher late hsw
 * @{
 */
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__SHIFT                           31
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__WIDTH                            1
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__MASK                   0x80000000U
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU11__EN_SW_HSW_B_LATE_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */
#define PMU_PMU11__TYPE                                                uint32_t
#define PMU_PMU11__READ                                             0xffffffffU
#define PMU_PMU11__WRITE                                            0xffffffffU
#define PMU_PMU11__PRESERVED                                        0x00000000U
#define PMU_PMU11__RESET_VALUE                                      0x00009802U

#endif /* __PMU_PMU11_MACRO__ */

/** @} end of pmu11 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu12 */
/**
 * @defgroup pmu_top_regs_core_pmu12 pmu12
 * @brief test registers and overrides definitions.
 * @{
 */
#ifndef __PMU_PMU12_MACRO__
#define __PMU_PMU12_MACRO__

/* macros for field otp_ovr */
/**
 * @defgroup pmu_top_regs_core_otp_ovr_field otp_ovr_field
 * @brief macros for field otp_ovr
 * @details 1: overriding otp values for test
 * @{
 */
#define PMU_PMU12__OTP_OVR__SHIFT                                             0
#define PMU_PMU12__OTP_OVR__WIDTH                                             1
#define PMU_PMU12__OTP_OVR__MASK                                    0x00000001U
#define PMU_PMU12__OTP_OVR__READ(src)           ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU12__OTP_OVR__WRITE(src)          ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU12__OTP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU12__OTP_OVR__VERIFY(src)   (!(((uint32_t)(src) & ~0x00000001U)))
#define PMU_PMU12__OTP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU12__OTP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU12__OTP_OVR__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field otp_batt_type_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_batt_type_ovr_val_field otp_batt_type_ovr_val_field
 * @brief macros for field otp_batt_type_ovr_val
 * @details 0: LiIon, 1: rechargeable, 2: no batt, 3: non-rechargable
 * @{
 */
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__SHIFT                               1
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__WIDTH                               2
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__MASK                      0x00000006U
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000006U) >> 1)
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000006U)
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PMU_PMU12__OTP_BATT_TYPE_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field otp_mppt_type_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_mppt_type_ovr_val_field otp_mppt_type_ovr_val_field
 * @brief macros for field otp_mppt_type_ovr_val
 * @details 0: digital mppt1: RF only+analog MPPT2: voltage regulation (all mppt disabled)
 * @{
 */
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__SHIFT                               3
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__WIDTH                               2
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__MASK                      0x00000018U
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000018U) >> 3)
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000018U)
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000018U) | (((uint32_t)(src) <<\
                    3) & 0x00000018U)
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000018U)))
#define PMU_PMU12__OTP_MPPT_TYPE_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field otp_disable_vddIO_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_disable_vddIO_ovr_val_field otp_disable_vddIO_ovr_val_field
 * @brief macros for field otp_disable_vddIO_ovr_val
 * @details 1: need to provide vddIO externally
 * @{
 */
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__SHIFT                           5
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__WIDTH                           1
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__MASK                  0x00000020U
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU12__OTP_DISABLE_VDDIO_OVR_VAL__RESET_VALUE           0x00000001U
/** @} */

/* macros for field otp_disable_vdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_disable_vdd_ovr_val_field otp_disable_vdd_ovr_val_field
 * @brief macros for field otp_disable_vdd_ovr_val
 * @details 1: need to provide vdd externally
 * @{
 */
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__SHIFT                             6
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__WIDTH                             1
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__MASK                    0x00000040U
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU12__OTP_DISABLE_VDD_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field otp_nabg_trim_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_nabg_trim_ovr_val_field otp_nabg_trim_ovr_val_field
 * @brief macros for field otp_nabg_trim_ovr_val
 * @details trimming bits for native bandgap
 * @{
 */
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__SHIFT                               7
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__WIDTH                               9
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__MASK                      0x0000ff80U
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff80U) >> 7)
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x0000ff80U)
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff80U) | (((uint32_t)(src) <<\
                    7) & 0x0000ff80U)
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x0000ff80U)))
#define PMU_PMU12__OTP_NABG_TRIM_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field unused */
/**
 * @defgroup pmu_top_regs_core_unused_field unused_field
 * @brief macros for field unused
 * @details unused spare, pmu_spares[7]
 * @{
 */
#define PMU_PMU12__UNUSED__SHIFT                                             16
#define PMU_PMU12__UNUSED__WIDTH                                              1
#define PMU_PMU12__UNUSED__MASK                                     0x00010000U
#define PMU_PMU12__UNUSED__READ(src)    (((uint32_t)(src) & 0x00010000U) >> 16)
#define PMU_PMU12__UNUSED__WRITE(src)   (((uint32_t)(src) << 16) & 0x00010000U)
#define PMU_PMU12__UNUSED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU12__UNUSED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU12__UNUSED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU12__UNUSED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU12__UNUSED__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field bypassLiion_ovr */
/**
 * @defgroup pmu_top_regs_core_bypassLiion_ovr_field bypassLiion_ovr_field
 * @brief macros for field bypassLiion_ovr
 * @details override bypassLiion
 * @{
 */
#define PMU_PMU12__BYPASSLIION_OVR__SHIFT                                    17
#define PMU_PMU12__BYPASSLIION_OVR__WIDTH                                     1
#define PMU_PMU12__BYPASSLIION_OVR__MASK                            0x00020000U
#define PMU_PMU12__BYPASSLIION_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU12__BYPASSLIION_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU12__BYPASSLIION_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU12__BYPASSLIION_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU12__BYPASSLIION_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU12__BYPASSLIION_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU12__BYPASSLIION_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field bypassLiion_ovr_val */
/**
 * @defgroup pmu_top_regs_core_bypassLiion_ovr_val_field bypassLiion_ovr_val_field
 * @brief macros for field bypassLiion_ovr_val
 * @details override bypassLiion val: 1 to bypass VBATLI to VBATT
 * @{
 */
#define PMU_PMU12__BYPASSLIION_OVR_VAL__SHIFT                                18
#define PMU_PMU12__BYPASSLIION_OVR_VAL__WIDTH                                 1
#define PMU_PMU12__BYPASSLIION_OVR_VAL__MASK                        0x00040000U
#define PMU_PMU12__BYPASSLIION_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU12__BYPASSLIION_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU12__BYPASSLIION_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU12__BYPASSLIION_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU12__BYPASSLIION_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU12__BYPASSLIION_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU12__BYPASSLIION_OVR_VAL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field disable_sw_timer */
/**
 * @defgroup pmu_top_regs_core_disable_sw_timer_field disable_sw_timer_field
 * @brief macros for field disable_sw_timer
 * @details disable sw timer and enable soc headswitch when sw is enabled
 * @{
 */
#define PMU_PMU12__DISABLE_SW_TIMER__SHIFT                                   19
#define PMU_PMU12__DISABLE_SW_TIMER__WIDTH                                    1
#define PMU_PMU12__DISABLE_SW_TIMER__MASK                           0x00080000U
#define PMU_PMU12__DISABLE_SW_TIMER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU12__DISABLE_SW_TIMER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU12__DISABLE_SW_TIMER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU12__DISABLE_SW_TIMER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU12__DISABLE_SW_TIMER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU12__DISABLE_SW_TIMER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU12__DISABLE_SW_TIMER__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_mem_hsw_b_ovr */
/**
 * @defgroup pmu_top_regs_core_en_mem_hsw_b_ovr_field en_mem_hsw_b_ovr_field
 * @brief macros for field en_mem_hsw_b_ovr
 * @details override en_mem_hsw_b
 * @{
 */
#define PMU_PMU12__EN_MEM_HSW_B_OVR__SHIFT                                   20
#define PMU_PMU12__EN_MEM_HSW_B_OVR__WIDTH                                    1
#define PMU_PMU12__EN_MEM_HSW_B_OVR__MASK                           0x00100000U
#define PMU_PMU12__EN_MEM_HSW_B_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU12__EN_MEM_HSW_B_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU12__EN_MEM_HSW_B_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU12__EN_MEM_HSW_B_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU12__EN_MEM_HSW_B_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU12__EN_MEM_HSW_B_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU12__EN_MEM_HSW_B_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_mem_hsw_b_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_mem_hsw_b_ovr_val_field en_mem_hsw_b_ovr_val_field
 * @brief macros for field en_mem_hsw_b_ovr_val
 * @details override en_mem_hsw_b val: Turn OFF mem hsw
 * @{
 */
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__SHIFT                               21
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__WIDTH                                1
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__MASK                       0x00200000U
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU12__EN_MEM_HSW_B_OVR_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field en_sw_hsw_b_ovr */
/**
 * @defgroup pmu_top_regs_core_en_sw_hsw_b_ovr_field en_sw_hsw_b_ovr_field
 * @brief macros for field en_sw_hsw_b_ovr
 * @details enable switcher headswitch override
 * @{
 */
#define PMU_PMU12__EN_SW_HSW_B_OVR__SHIFT                                    22
#define PMU_PMU12__EN_SW_HSW_B_OVR__WIDTH                                     1
#define PMU_PMU12__EN_SW_HSW_B_OVR__MASK                            0x00400000U
#define PMU_PMU12__EN_SW_HSW_B_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU12__EN_SW_HSW_B_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU12__EN_SW_HSW_B_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU12__EN_SW_HSW_B_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU12__EN_SW_HSW_B_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU12__EN_SW_HSW_B_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU12__EN_SW_HSW_B_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field en_sw_hsw_b_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_sw_hsw_b_ovr_val_field en_sw_hsw_b_ovr_val_field
 * @brief macros for field en_sw_hsw_b_ovr_val
 * @details override val for switcher head switch
 * @{
 */
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__SHIFT                                23
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__WIDTH                                 1
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__MASK                        0x00800000U
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU12__EN_SW_HSW_B_OVR_VAL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sw_rstb_ovr */
/**
 * @defgroup pmu_top_regs_core_sw_rstb_ovr_field sw_rstb_ovr_field
 * @brief macros for field sw_rstb_ovr
 * @details enable override for switcher rstb
 * @{
 */
#define PMU_PMU12__SW_RSTB_OVR__SHIFT                                        24
#define PMU_PMU12__SW_RSTB_OVR__WIDTH                                         1
#define PMU_PMU12__SW_RSTB_OVR__MASK                                0x01000000U
#define PMU_PMU12__SW_RSTB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU12__SW_RSTB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU12__SW_RSTB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU12__SW_RSTB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU12__SW_RSTB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU12__SW_RSTB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU12__SW_RSTB_OVR__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field sw_rstb_ovr_val */
/**
 * @defgroup pmu_top_regs_core_sw_rstb_ovr_val_field sw_rstb_ovr_val_field
 * @brief macros for field sw_rstb_ovr_val
 * @details override val for switcher rstb
 * @{
 */
#define PMU_PMU12__SW_RSTB_OVR_VAL__SHIFT                                    25
#define PMU_PMU12__SW_RSTB_OVR_VAL__WIDTH                                     1
#define PMU_PMU12__SW_RSTB_OVR_VAL__MASK                            0x02000000U
#define PMU_PMU12__SW_RSTB_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU12__SW_RSTB_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU12__SW_RSTB_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU12__SW_RSTB_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU12__SW_RSTB_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU12__SW_RSTB_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU12__SW_RSTB_OVR_VAL__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field en_soc_hsw_b_ovr */
/**
 * @defgroup pmu_top_regs_core_en_soc_hsw_b_ovr_field en_soc_hsw_b_ovr_field
 * @brief macros for field en_soc_hsw_b_ovr
 * @details enable soc headswitch override
 * @{
 */
#define PMU_PMU12__EN_SOC_HSW_B_OVR__SHIFT                                   26
#define PMU_PMU12__EN_SOC_HSW_B_OVR__WIDTH                                    1
#define PMU_PMU12__EN_SOC_HSW_B_OVR__MASK                           0x04000000U
#define PMU_PMU12__EN_SOC_HSW_B_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU12__EN_SOC_HSW_B_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU12__EN_SOC_HSW_B_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU12__EN_SOC_HSW_B_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU12__EN_SOC_HSW_B_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU12__EN_SOC_HSW_B_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU12__EN_SOC_HSW_B_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_soc_hsw_b_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_soc_hsw_b_ovr_val_field en_soc_hsw_b_ovr_val_field
 * @brief macros for field en_soc_hsw_b_ovr_val
 * @details override_val for soc headswitch
 * @{
 */
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__SHIFT                               27
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__WIDTH                                1
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__MASK                       0x08000000U
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU12__EN_SOC_HSW_B_OVR_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sel_avdd1_ovr */
/**
 * @defgroup pmu_top_regs_core_sel_avdd1_ovr_field sel_avdd1_ovr_field
 * @brief macros for field sel_avdd1_ovr
 * @details enable override for pmu avdd/dvdd switch
 * @{
 */
#define PMU_PMU12__SEL_AVDD1_OVR__SHIFT                                      28
#define PMU_PMU12__SEL_AVDD1_OVR__WIDTH                                       1
#define PMU_PMU12__SEL_AVDD1_OVR__MASK                              0x10000000U
#define PMU_PMU12__SEL_AVDD1_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU12__SEL_AVDD1_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU12__SEL_AVDD1_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU12__SEL_AVDD1_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU12__SEL_AVDD1_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU12__SEL_AVDD1_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU12__SEL_AVDD1_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field sel_avdd1_ovr_val */
/**
 * @defgroup pmu_top_regs_core_sel_avdd1_ovr_val_field sel_avdd1_ovr_val_field
 * @brief macros for field sel_avdd1_ovr_val
 * @details override_val for pmu avdd/dvdd switch
 * @{
 */
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__SHIFT                                  29
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__WIDTH                                   1
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__MASK                          0x20000000U
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU12__SEL_AVDD1_OVR_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field swRes_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_swRes_encomp_ovr_field swRes_encomp_ovr_field
 * @brief macros for field swRes_encomp_ovr
 * @details override swRes_encomp
 * @{
 */
#define PMU_PMU12__SWRES_ENCOMP_OVR__SHIFT                                   30
#define PMU_PMU12__SWRES_ENCOMP_OVR__WIDTH                                    1
#define PMU_PMU12__SWRES_ENCOMP_OVR__MASK                           0x40000000U
#define PMU_PMU12__SWRES_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU12__SWRES_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU12__SWRES_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU12__SWRES_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU12__SWRES_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU12__SWRES_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU12__SWRES_ENCOMP_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field swRes_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_swRes_encomp_ovr_val_field swRes_encomp_ovr_val_field
 * @brief macros for field swRes_encomp_ovr_val
 * @details override swRes_encomp val: Enable dvdd swRes
 * @{
 */
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__SHIFT                               31
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__WIDTH                                1
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__MASK                       0x80000000U
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU12__SWRES_ENCOMP_OVR_VAL__RESET_VALUE                0x00000000U
/** @} */
#define PMU_PMU12__TYPE                                                uint32_t
#define PMU_PMU12__READ                                             0xffffffffU
#define PMU_PMU12__WRITE                                            0xffffffffU
#define PMU_PMU12__PRESERVED                                        0x00000000U
#define PMU_PMU12__RESET_VALUE                                      0x00000020U

#endif /* __PMU_PMU12_MACRO__ */

/** @} end of pmu12 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu12a */
/**
 * @defgroup pmu_top_regs_core_pmu12a pmu12a
 * @brief more test registers and overrides definitions.
 * @{
 */
#ifndef __PMU_PMU12A_MACRO__
#define __PMU_PMU12A_MACRO__

/* macros for field otp_int_ovr */
/**
 * @defgroup pmu_top_regs_core_otp_int_ovr_field otp_int_ovr_field
 * @brief macros for field otp_int_ovr
 * @details enables override for native, charge pump, rect_ctune otp bits
 * @{
 */
#define PMU_PMU12A__OTP_INT_OVR__SHIFT                                        0
#define PMU_PMU12A__OTP_INT_OVR__WIDTH                                        1
#define PMU_PMU12A__OTP_INT_OVR__MASK                               0x00000001U
#define PMU_PMU12A__OTP_INT_OVR__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU12A__OTP_INT_OVR__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU12A__OTP_INT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU12A__OTP_INT_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU12A__OTP_INT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU12A__OTP_INT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU12A__OTP_INT_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field otp_use_ldo_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_use_ldo_ovr_val_field otp_use_ldo_ovr_val_field
 * @brief macros for field otp_use_ldo_ovr_val
 * @details override val for otp_use_ldo
 * @{
 */
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__SHIFT                                1
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__WIDTH                                1
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__MASK                       0x00000002U
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU12A__OTP_USE_LDO_OVR_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field otp_disable_chpu_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_disable_chpu_ovr_val_field otp_disable_chpu_ovr_val_field
 * @brief macros for field otp_disable_chpu_ovr_val
 * @details override val for otp_disable_chpu
 * @{
 */
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__SHIFT                           2
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__WIDTH                           1
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__MASK                  0x00000004U
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU12A__OTP_DISABLE_CHPU_OVR_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field otp_rect_ctune_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_rect_ctune_ovr_val_field otp_rect_ctune_ovr_val_field
 * @brief macros for field otp_rect_ctune_ovr_val
 * @details override val for otp_rect_ctune
 * @{
 */
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__SHIFT                             3
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__WIDTH                             3
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__MASK                    0x00000038U
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define PMU_PMU12A__OTP_RECT_CTUNE_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field otp_internal_spare_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_internal_spare_ovr_val_field otp_internal_spare_ovr_val_field
 * @brief macros for field otp_internal_spare_ovr_val
 * @details override val for otp_internal_spare
 * @{
 */
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__SHIFT                         6
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__WIDTH                         4
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__MASK                0x000003c0U
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define PMU_PMU12A__OTP_INTERNAL_SPARE_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field otp_noind_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_noind_ovr_val_field otp_noind_ovr_val_field
 * @brief macros for field otp_noind_ovr_val
 * @details override val for otp_noind
 * @{
 */
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__SHIFT                                 10
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__WIDTH                                  1
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__MASK                         0x00000400U
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU12A__OTP_NOIND_OVR_VAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field otp_disable_5v_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_disable_5v_ovr_val_field otp_disable_5v_ovr_val_field
 * @brief macros for field otp_disable_5v_ovr_val
 * @details override val for otp_disable_5v
 * @{
 */
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__SHIFT                            11
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__WIDTH                             1
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__MASK                    0x00000800U
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU12A__OTP_DISABLE_5V_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field otp_vbatt_level_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vbatt_level_ovr_val_field otp_vbatt_level_ovr_val_field
 * @brief macros for field otp_vbatt_level_ovr_val
 * @details override val for otp_vbatt_level
 * @{
 */
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__SHIFT                           12
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__WIDTH                            1
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__MASK                   0x00001000U
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU12A__OTP_VBATT_LEVEL_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field otp_vbatt_good_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vbatt_good_ovr_val_field otp_vbatt_good_ovr_val_field
 * @brief macros for field otp_vbatt_good_ovr_val
 * @details override val for otp_vbatt_good
 * @{
 */
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__SHIFT                            13
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__WIDTH                             3
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__MASK                    0x0000e000U
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define PMU_PMU12A__OTP_VBATT_GOOD_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field otp_vbatt_brownout_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vbatt_brownout_ovr_val_field otp_vbatt_brownout_ovr_val_field
 * @brief macros for field otp_vbatt_brownout_ovr_val
 * @details override val for otp_vbatt_brownout
 * @{
 */
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__SHIFT                        16
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__WIDTH                         5
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__MASK                0x001f0000U
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define PMU_PMU12A__OTP_VBATT_BROWNOUT_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field otp_vddio_range_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vddio_range_ovr_val_field otp_vddio_range_ovr_val_field
 * @brief macros for field otp_vddio_range_ovr_val
 * @details override val for otp_vddio_range
 * @{
 */
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__SHIFT                           21
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__WIDTH                            1
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__MASK                   0x00200000U
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU12A__OTP_VDDIO_RANGE_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field otp_reserved_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_reserved_ovr_val_field otp_reserved_ovr_val_field
 * @brief macros for field otp_reserved_ovr_val
 * @details override val for otp_reserved
 * @{
 */
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__SHIFT                              22
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__WIDTH                               1
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__MASK                      0x00400000U
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU12A__OTP_RESERVED_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field otp_disable_rfharv_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_disable_rfharv_ovr_val_field otp_disable_rfharv_ovr_val_field
 * @brief macros for field otp_disable_rfharv_ovr_val
 * @details override val for otp_disable_rfharv
 * @{
 */
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__SHIFT                        23
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__WIDTH                         1
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__MASK                0x00800000U
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU12A__OTP_DISABLE_RFHARV_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field otp_vharv_start_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vharv_start_ovr_val_field otp_vharv_start_ovr_val_field
 * @brief macros for field otp_vharv_start_ovr_val
 * @details override val for otp_vharv_start
 * @{
 */
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__SHIFT                           24
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__WIDTH                            2
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__MASK                   0x03000000U
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define PMU_PMU12A__OTP_VHARV_START_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field otp_vstore_good_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vstore_good_ovr_val_field otp_vstore_good_ovr_val_field
 * @brief macros for field otp_vstore_good_ovr_val
 * @details override val for otp_vstore_good
 * @{
 */
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__SHIFT                           26
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__WIDTH                            2
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__MASK                   0x0c000000U
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define PMU_PMU12A__OTP_VSTORE_GOOD_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field otp_vstore_max_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vstore_max_ovr_val_field otp_vstore_max_ovr_val_field
 * @brief macros for field otp_vstore_max_ovr_val
 * @details override val for otp_vstore_max
 * @{
 */
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__SHIFT                            28
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__WIDTH                             3
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__MASK                    0x70000000U
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x70000000U) >> 28)
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x70000000U)
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x70000000U) | (((uint32_t)(src) <<\
                    28) & 0x70000000U)
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x70000000U)))
#define PMU_PMU12A__OTP_VSTORE_MAX_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */
#define PMU_PMU12A__TYPE                                               uint32_t
#define PMU_PMU12A__READ                                            0x7fffffffU
#define PMU_PMU12A__WRITE                                           0x7fffffffU
#define PMU_PMU12A__PRESERVED                                       0x00000000U
#define PMU_PMU12A__RESET_VALUE                                     0x00000000U

#endif /* __PMU_PMU12A_MACRO__ */

/** @} end of pmu12a */

/* macros for BlueprintGlobalNameSpace::PMU_pmu13 */
/**
 * @defgroup pmu_top_regs_core_pmu13 pmu13
 * @brief test overrides definitions.
 * @{
 */
#ifndef __PMU_PMU13_MACRO__
#define __PMU_PMU13_MACRO__

/* macros for field SwchReqDVDD_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_encomp_ovr_field SwchReqDVDD_encomp_ovr_field
 * @brief macros for field SwchReqDVDD_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__SHIFT                              0
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__WIDTH                              1
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__MASK                     0x00000001U
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field SwchReqDVDD_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_encomp_ovr_val_field SwchReqDVDD_encomp_ovr_val_field
 * @brief macros for field SwchReqDVDD_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__SHIFT                          1
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__WIDTH                          1
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__MASK                 0x00000002U
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU13__SWCHREQDVDD_ENCOMP_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_encomp_ovr_field SwchReqVDDIO_encomp_ovr_field
 * @brief macros for field SwchReqVDDIO_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__SHIFT                             2
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__WIDTH                             1
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__MASK                    0x00000004U
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_encomp_ovr_val_field SwchReqVDDIO_encomp_ovr_val_field
 * @brief macros for field SwchReqVDDIO_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__SHIFT                         3
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__WIDTH                         1
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__MASK                0x00000008U
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU13__SWCHREQVDDIO_ENCOMP_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field SwchReqAVDD_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_encomp_ovr_field SwchReqAVDD_encomp_ovr_field
 * @brief macros for field SwchReqAVDD_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__SHIFT                              4
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__WIDTH                              1
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__MASK                     0x00000010U
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field SwchReqAVDD_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_encomp_ovr_val_field SwchReqAVDD_encomp_ovr_val_field
 * @brief macros for field SwchReqAVDD_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__SHIFT                          5
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__WIDTH                          1
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__MASK                 0x00000020U
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field SwchReqVAUX_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqVAUX_encomp_ovr_field SwchReqVAUX_encomp_ovr_field
 * @brief macros for field SwchReqVAUX_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__SHIFT                              6
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__WIDTH                              1
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__MASK                     0x00000040U
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field SwchReqVAUX_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVAUX_encomp_ovr_val_field SwchReqVAUX_encomp_ovr_val_field
 * @brief macros for field SwchReqVAUX_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__SHIFT                          7
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__WIDTH                          1
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__MASK                 0x00000080U
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU13__SWCHREQVAUX_ENCOMP_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field porbsocdvdd_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_porbsocdvdd_encomp_ovr_field porbsocdvdd_encomp_ovr_field
 * @brief macros for field porbsocdvdd_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__SHIFT                              8
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__WIDTH                              1
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__MASK                     0x00000100U
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field porbsocdvdd_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_porbsocdvdd_encomp_ovr_val_field porbsocdvdd_encomp_ovr_val_field
 * @brief macros for field porbsocdvdd_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__SHIFT                          9
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__WIDTH                          1
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__MASK                 0x00000200U
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU13__PORBSOCDVDD_ENCOMP_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field porbsocvddio_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_porbsocvddio_encomp_ovr_field porbsocvddio_encomp_ovr_field
 * @brief macros for field porbsocvddio_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__SHIFT                            10
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__WIDTH                             1
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__MASK                    0x00000400U
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field porbsocvddio_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_porbsocvddio_encomp_ovr_val_field porbsocvddio_encomp_ovr_val_field
 * @brief macros for field porbsocvddio_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__SHIFT                        11
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__WIDTH                         1
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__MASK                0x00000800U
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU13__PORBSOCVDDIO_ENCOMP_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field stoGoodtoEner_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_stoGoodtoEner_encomp_ovr_field stoGoodtoEner_encomp_ovr_field
 * @brief macros for field stoGoodtoEner_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__SHIFT                           12
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__WIDTH                            1
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__MASK                   0x00001000U
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field stoGoodtoEner_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_stoGoodtoEner_encomp_ovr_val_field stoGoodtoEner_encomp_ovr_val_field
 * @brief macros for field stoGoodtoEner_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__SHIFT                       13
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__WIDTH                        1
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__MASK               0x00002000U
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU13__STOGOODTOENER_ENCOMP_OVR_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field stoGoodtoTX_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_stoGoodtoTX_encomp_ovr_field stoGoodtoTX_encomp_ovr_field
 * @brief macros for field stoGoodtoTX_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__SHIFT                             14
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__WIDTH                              1
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__MASK                     0x00004000U
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field stoGoodtoTX_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_stoGoodtoTX_encomp_ovr_val_field stoGoodtoTX_encomp_ovr_val_field
 * @brief macros for field stoGoodtoTX_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__SHIFT                         15
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__WIDTH                          1
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__MASK                 0x00008000U
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU13__STOGOODTOTX_ENCOMP_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field srvevaux_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_srvevaux_encomp_ovr_field srvevaux_encomp_ovr_field
 * @brief macros for field srvevaux_encomp_ovr
 * @details unused
 * @{
 */
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__SHIFT                                16
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__WIDTH                                 1
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__MASK                        0x00010000U
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field srvevaux_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_srvevaux_encomp_ovr_val_field srvevaux_encomp_ovr_val_field
 * @brief macros for field srvevaux_encomp_ovr_val
 * @details unused
 * @{
 */
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__SHIFT                            17
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__WIDTH                             1
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__MASK                    0x00020000U
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU13__SRVEVAUX_ENCOMP_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field harvstop_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_harvstop_encomp_ovr_field harvstop_encomp_ovr_field
 * @brief macros for field harvstop_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__SHIFT                                18
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__WIDTH                                 1
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__MASK                        0x00040000U
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field harvstop_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_harvstop_encomp_ovr_val_field harvstop_encomp_ovr_val_field
 * @brief macros for field harvstop_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__SHIFT                            19
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__WIDTH                             1
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__MASK                    0x00080000U
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU13__HARVSTOP_ENCOMP_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field browovbat_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_browovbat_encomp_ovr_field browovbat_encomp_ovr_field
 * @brief macros for field browovbat_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__SHIFT                               20
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__WIDTH                                1
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__MASK                       0x00100000U
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field browovbat_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_browovbat_encomp_ovr_val_field browovbat_encomp_ovr_val_field
 * @brief macros for field browovbat_encomp_ovr_val
 * @details override_val
 * @{
 */
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__SHIFT                           21
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__WIDTH                            1
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__MASK                   0x00200000U
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU13__BROWOVBAT_ENCOMP_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field harv_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_harv_encomp_ovr_field harv_encomp_ovr_field
 * @brief macros for field harv_encomp_ovr
 * @details override
 * @{
 */
#define PMU_PMU13__HARV_ENCOMP_OVR__SHIFT                                    22
#define PMU_PMU13__HARV_ENCOMP_OVR__WIDTH                                     1
#define PMU_PMU13__HARV_ENCOMP_OVR__MASK                            0x00400000U
#define PMU_PMU13__HARV_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU13__HARV_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU13__HARV_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU13__HARV_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU13__HARV_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU13__HARV_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU13__HARV_ENCOMP_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field harv_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_harv_encomp_ovr_val_field harv_encomp_ovr_val_field
 * @brief macros for field harv_encomp_ovr_val
 * @details override_val: enable can/must harv enable comparators
 * @{
 */
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__SHIFT                                23
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__WIDTH                                 1
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__MASK                        0x00800000U
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU13__HARV_ENCOMP_OVR_VAL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field mpptstart_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_mpptstart_encomp_ovr_field mpptstart_encomp_ovr_field
 * @brief macros for field mpptstart_encomp_ovr
 * @details unused
 * @{
 */
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__SHIFT                               24
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__WIDTH                                1
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__MASK                       0x01000000U
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field mpptstart_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_mpptstart_encomp_ovr_val_field mpptstart_encomp_ovr_val_field
 * @brief macros for field mpptstart_encomp_ovr_val
 * @details unused
 * @{
 */
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__SHIFT                           25
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__WIDTH                            1
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__MASK                   0x02000000U
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU13__MPPTSTART_ENCOMP_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field reconfharv_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_reconfharv_encomp_ovr_field reconfharv_encomp_ovr_field
 * @brief macros for field reconfharv_encomp_ovr
 * @details override decrectst_encomp
 * @{
 */
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__SHIFT                              26
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__WIDTH                               1
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__MASK                      0x04000000U
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field reconfharv_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_reconfharv_encomp_ovr_val_field reconfharv_encomp_ovr_val_field
 * @brief macros for field reconfharv_encomp_ovr_val
 * @details override decrectst_encomp val: enable decrectstage_prtVharv comparator
 * @{
 */
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__SHIFT                          27
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__WIDTH                           1
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__MASK                  0x08000000U
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU13__RECONFHARV_ENCOMP_OVR_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field ctr_ldo_en_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldo_en_ovr_field ctr_ldo_en_ovr_field
 * @brief macros for field ctr_ldo_en_ovr
 * @details override ctr_ldomem_en
 * @{
 */
#define PMU_PMU13__CTR_LDO_EN_OVR__SHIFT                                     28
#define PMU_PMU13__CTR_LDO_EN_OVR__WIDTH                                      1
#define PMU_PMU13__CTR_LDO_EN_OVR__MASK                             0x10000000U
#define PMU_PMU13__CTR_LDO_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU13__CTR_LDO_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU13__CTR_LDO_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU13__CTR_LDO_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU13__CTR_LDO_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU13__CTR_LDO_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU13__CTR_LDO_EN_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field ctr_ldo_en_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_ldo_en_ovr_val_field ctr_ldo_en_ovr_val_field
 * @brief macros for field ctr_ldo_en_ovr_val
 * @details override ctr_ldomem_en val
 * @{
 */
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__SHIFT                                 29
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__WIDTH                                  1
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__MASK                         0x20000000U
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU13__CTR_LDO_EN_OVR_VAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field ctr_ldo_bypass_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_ldo_bypass_ovr_field ctr_ldo_bypass_ovr_field
 * @brief macros for field ctr_ldo_bypass_ovr
 * @details override ctr_ldomem_bypass
 * @{
 */
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__SHIFT                                 30
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__WIDTH                                  1
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__MASK                         0x40000000U
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field ctr_ldo_bypass_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_ldo_bypass_ovr_val_field ctr_ldo_bypass_ovr_val_field
 * @brief macros for field ctr_ldo_bypass_ovr_val
 * @details override ctr_ldomem_bypass val
 * @{
 */
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__SHIFT                             31
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__WIDTH                              1
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__MASK                     0x80000000U
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU13__CTR_LDO_BYPASS_OVR_VAL__RESET_VALUE              0x00000000U
/** @} */
#define PMU_PMU13__TYPE                                                uint32_t
#define PMU_PMU13__READ                                             0xffffffffU
#define PMU_PMU13__WRITE                                            0xffffffffU
#define PMU_PMU13__PRESERVED                                        0x00000000U
#define PMU_PMU13__RESET_VALUE                                      0x00000000U

#endif /* __PMU_PMU13_MACRO__ */

/** @} end of pmu13 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu14 */
/**
 * @defgroup pmu_top_regs_core_pmu14 pmu14
 * @brief source/destination overrides definitions.
 * @{
 */
#ifndef __PMU_PMU14_MACRO__
#define __PMU_PMU14_MACRO__

/* macros for field src2_ovr */
/**
 * @defgroup pmu_top_regs_core_src2_ovr_field src2_ovr_field
 * @brief macros for field src2_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__SRC2_OVR__SHIFT                                            0
#define PMU_PMU14__SRC2_OVR__WIDTH                                            1
#define PMU_PMU14__SRC2_OVR__MASK                                   0x00000001U
#define PMU_PMU14__SRC2_OVR__READ(src)          ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU14__SRC2_OVR__WRITE(src)         ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU14__SRC2_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU14__SRC2_OVR__VERIFY(src)  (!(((uint32_t)(src) & ~0x00000001U)))
#define PMU_PMU14__SRC2_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU14__SRC2_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU14__SRC2_OVR__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field src2_ovr_val */
/**
 * @defgroup pmu_top_regs_core_src2_ovr_val_field src2_ovr_val_field
 * @brief macros for field src2_ovr_val
 * @details override val
 * @{
 */
#define PMU_PMU14__SRC2_OVR_VAL__SHIFT                                        1
#define PMU_PMU14__SRC2_OVR_VAL__WIDTH                                        1
#define PMU_PMU14__SRC2_OVR_VAL__MASK                               0x00000002U
#define PMU_PMU14__SRC2_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU14__SRC2_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU14__SRC2_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU14__SRC2_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU14__SRC2_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU14__SRC2_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU14__SRC2_OVR_VAL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field dest1_ovr */
/**
 * @defgroup pmu_top_regs_core_dest1_ovr_field dest1_ovr_field
 * @brief macros for field dest1_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__DEST1_OVR__SHIFT                                           2
#define PMU_PMU14__DEST1_OVR__WIDTH                                           1
#define PMU_PMU14__DEST1_OVR__MASK                                  0x00000004U
#define PMU_PMU14__DEST1_OVR__READ(src)  (((uint32_t)(src) & 0x00000004U) >> 2)
#define PMU_PMU14__DEST1_OVR__WRITE(src) (((uint32_t)(src) << 2) & 0x00000004U)
#define PMU_PMU14__DEST1_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU14__DEST1_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU14__DEST1_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU14__DEST1_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU14__DEST1_OVR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field dest1_ovr_val */
/**
 * @defgroup pmu_top_regs_core_dest1_ovr_val_field dest1_ovr_val_field
 * @brief macros for field dest1_ovr_val
 * @details override val
 * @{
 */
#define PMU_PMU14__DEST1_OVR_VAL__SHIFT                                       3
#define PMU_PMU14__DEST1_OVR_VAL__WIDTH                                       1
#define PMU_PMU14__DEST1_OVR_VAL__MASK                              0x00000008U
#define PMU_PMU14__DEST1_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU14__DEST1_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU14__DEST1_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU14__DEST1_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU14__DEST1_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU14__DEST1_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU14__DEST1_OVR_VAL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field dest2_ovr */
/**
 * @defgroup pmu_top_regs_core_dest2_ovr_field dest2_ovr_field
 * @brief macros for field dest2_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__DEST2_OVR__SHIFT                                           4
#define PMU_PMU14__DEST2_OVR__WIDTH                                           1
#define PMU_PMU14__DEST2_OVR__MASK                                  0x00000010U
#define PMU_PMU14__DEST2_OVR__READ(src)  (((uint32_t)(src) & 0x00000010U) >> 4)
#define PMU_PMU14__DEST2_OVR__WRITE(src) (((uint32_t)(src) << 4) & 0x00000010U)
#define PMU_PMU14__DEST2_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU14__DEST2_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU14__DEST2_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU14__DEST2_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU14__DEST2_OVR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field dest2_ovr_val */
/**
 * @defgroup pmu_top_regs_core_dest2_ovr_val_field dest2_ovr_val_field
 * @brief macros for field dest2_ovr_val
 * @details override val
 * @{
 */
#define PMU_PMU14__DEST2_OVR_VAL__SHIFT                                       5
#define PMU_PMU14__DEST2_OVR_VAL__WIDTH                                       1
#define PMU_PMU14__DEST2_OVR_VAL__MASK                              0x00000020U
#define PMU_PMU14__DEST2_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU14__DEST2_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU14__DEST2_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU14__DEST2_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU14__DEST2_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU14__DEST2_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU14__DEST2_OVR_VAL__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field dest3_ovr */
/**
 * @defgroup pmu_top_regs_core_dest3_ovr_field dest3_ovr_field
 * @brief macros for field dest3_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__DEST3_OVR__SHIFT                                           6
#define PMU_PMU14__DEST3_OVR__WIDTH                                           1
#define PMU_PMU14__DEST3_OVR__MASK                                  0x00000040U
#define PMU_PMU14__DEST3_OVR__READ(src)  (((uint32_t)(src) & 0x00000040U) >> 6)
#define PMU_PMU14__DEST3_OVR__WRITE(src) (((uint32_t)(src) << 6) & 0x00000040U)
#define PMU_PMU14__DEST3_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU14__DEST3_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU14__DEST3_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU14__DEST3_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU14__DEST3_OVR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field dest3_ovr_val */
/**
 * @defgroup pmu_top_regs_core_dest3_ovr_val_field dest3_ovr_val_field
 * @brief macros for field dest3_ovr_val
 * @details override val
 * @{
 */
#define PMU_PMU14__DEST3_OVR_VAL__SHIFT                                       7
#define PMU_PMU14__DEST3_OVR_VAL__WIDTH                                       1
#define PMU_PMU14__DEST3_OVR_VAL__MASK                              0x00000080U
#define PMU_PMU14__DEST3_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PMU_PMU14__DEST3_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PMU_PMU14__DEST3_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_PMU14__DEST3_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_PMU14__DEST3_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU14__DEST3_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU14__DEST3_OVR_VAL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field dest4_ovr */
/**
 * @defgroup pmu_top_regs_core_dest4_ovr_field dest4_ovr_field
 * @brief macros for field dest4_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__DEST4_OVR__SHIFT                                           8
#define PMU_PMU14__DEST4_OVR__WIDTH                                           1
#define PMU_PMU14__DEST4_OVR__MASK                                  0x00000100U
#define PMU_PMU14__DEST4_OVR__READ(src)  (((uint32_t)(src) & 0x00000100U) >> 8)
#define PMU_PMU14__DEST4_OVR__WRITE(src) (((uint32_t)(src) << 8) & 0x00000100U)
#define PMU_PMU14__DEST4_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU14__DEST4_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU14__DEST4_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU14__DEST4_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU14__DEST4_OVR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field dest4_ovr_val */
/**
 * @defgroup pmu_top_regs_core_dest4_ovr_val_field dest4_ovr_val_field
 * @brief macros for field dest4_ovr_val
 * @details override val
 * @{
 */
#define PMU_PMU14__DEST4_OVR_VAL__SHIFT                                       9
#define PMU_PMU14__DEST4_OVR_VAL__WIDTH                                       1
#define PMU_PMU14__DEST4_OVR_VAL__MASK                              0x00000200U
#define PMU_PMU14__DEST4_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU14__DEST4_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU14__DEST4_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU14__DEST4_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU14__DEST4_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU14__DEST4_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU14__DEST4_OVR_VAL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field state_ovr */
/**
 * @defgroup pmu_top_regs_core_state_ovr_field state_ovr_field
 * @brief macros for field state_ovr
 * @details override pmu state for test
 * @{
 */
#define PMU_PMU14__STATE_OVR__SHIFT                                          10
#define PMU_PMU14__STATE_OVR__WIDTH                                           1
#define PMU_PMU14__STATE_OVR__MASK                                  0x00000400U
#define PMU_PMU14__STATE_OVR__READ(src) (((uint32_t)(src) & 0x00000400U) >> 10)
#define PMU_PMU14__STATE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU14__STATE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU14__STATE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU14__STATE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU14__STATE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU14__STATE_OVR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field test_state */
/**
 * @defgroup pmu_top_regs_core_test_state_field test_state_field
 * @brief macros for field test_state
 * @details force the pmu state to be this state
 * @{
 */
#define PMU_PMU14__TEST_STATE__SHIFT                                         11
#define PMU_PMU14__TEST_STATE__WIDTH                                          3
#define PMU_PMU14__TEST_STATE__MASK                                 0x00003800U
#define PMU_PMU14__TEST_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define PMU_PMU14__TEST_STATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define PMU_PMU14__TEST_STATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define PMU_PMU14__TEST_STATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define PMU_PMU14__TEST_STATE__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field pwr_mode_ovr */
/**
 * @defgroup pmu_top_regs_core_pwr_mode_ovr_field pwr_mode_ovr_field
 * @brief macros for field pwr_mode_ovr
 * @details override power mode for testing
 * @{
 */
#define PMU_PMU14__PWR_MODE_OVR__SHIFT                                       14
#define PMU_PMU14__PWR_MODE_OVR__WIDTH                                        1
#define PMU_PMU14__PWR_MODE_OVR__MASK                               0x00004000U
#define PMU_PMU14__PWR_MODE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU14__PWR_MODE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU14__PWR_MODE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU14__PWR_MODE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU14__PWR_MODE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU14__PWR_MODE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU14__PWR_MODE_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pwr_mode_val */
/**
 * @defgroup pmu_top_regs_core_pwr_mode_val_field pwr_mode_val_field
 * @brief macros for field pwr_mode_val
 * @details pwr_mode override value
 * @{
 */
#define PMU_PMU14__PWR_MODE_VAL__SHIFT                                       15
#define PMU_PMU14__PWR_MODE_VAL__WIDTH                                        3
#define PMU_PMU14__PWR_MODE_VAL__MASK                               0x00038000U
#define PMU_PMU14__PWR_MODE_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define PMU_PMU14__PWR_MODE_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define PMU_PMU14__PWR_MODE_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define PMU_PMU14__PWR_MODE_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
#define PMU_PMU14__PWR_MODE_VAL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field wkup_timer_en_ovr */
/**
 * @defgroup pmu_top_regs_core_wkup_timer_en_ovr_field wkup_timer_en_ovr_field
 * @brief macros for field wkup_timer_en_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__WKUP_TIMER_EN_OVR__SHIFT                                  18
#define PMU_PMU14__WKUP_TIMER_EN_OVR__WIDTH                                   1
#define PMU_PMU14__WKUP_TIMER_EN_OVR__MASK                          0x00040000U
#define PMU_PMU14__WKUP_TIMER_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU14__WKUP_TIMER_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU14__WKUP_TIMER_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU14__WKUP_TIMER_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU14__WKUP_TIMER_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU14__WKUP_TIMER_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU14__WKUP_TIMER_EN_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field wkup_timer_en_val */
/**
 * @defgroup pmu_top_regs_core_wkup_timer_en_val_field wkup_timer_en_val_field
 * @brief macros for field wkup_timer_en_val
 * @details override val
 * @{
 */
#define PMU_PMU14__WKUP_TIMER_EN_VAL__SHIFT                                  19
#define PMU_PMU14__WKUP_TIMER_EN_VAL__WIDTH                                   1
#define PMU_PMU14__WKUP_TIMER_EN_VAL__MASK                          0x00080000U
#define PMU_PMU14__WKUP_TIMER_EN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU14__WKUP_TIMER_EN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU14__WKUP_TIMER_EN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU14__WKUP_TIMER_EN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU14__WKUP_TIMER_EN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU14__WKUP_TIMER_EN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU14__WKUP_TIMER_EN_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field lpcomp_en_ovr */
/**
 * @defgroup pmu_top_regs_core_lpcomp_en_ovr_field lpcomp_en_ovr_field
 * @brief macros for field lpcomp_en_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__LPCOMP_EN_OVR__SHIFT                                      20
#define PMU_PMU14__LPCOMP_EN_OVR__WIDTH                                       1
#define PMU_PMU14__LPCOMP_EN_OVR__MASK                              0x00100000U
#define PMU_PMU14__LPCOMP_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU14__LPCOMP_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU14__LPCOMP_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU14__LPCOMP_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU14__LPCOMP_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU14__LPCOMP_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU14__LPCOMP_EN_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field lpcomp_en_ovr_val */
/**
 * @defgroup pmu_top_regs_core_lpcomp_en_ovr_val_field lpcomp_en_ovr_val_field
 * @brief macros for field lpcomp_en_ovr_val
 * @details override val
 * @{
 */
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__SHIFT                                  21
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__WIDTH                                   1
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__MASK                          0x00200000U
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU14__LPCOMP_EN_OVR_VAL__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field pinedge_en_ovr */
/**
 * @defgroup pmu_top_regs_core_pinedge_en_ovr_field pinedge_en_ovr_field
 * @brief macros for field pinedge_en_ovr
 * @details override
 * @{
 */
#define PMU_PMU14__PINEDGE_EN_OVR__SHIFT                                     22
#define PMU_PMU14__PINEDGE_EN_OVR__WIDTH                                      1
#define PMU_PMU14__PINEDGE_EN_OVR__MASK                             0x00400000U
#define PMU_PMU14__PINEDGE_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU14__PINEDGE_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU14__PINEDGE_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU14__PINEDGE_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU14__PINEDGE_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU14__PINEDGE_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU14__PINEDGE_EN_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pinedge_en_ovr_val */
/**
 * @defgroup pmu_top_regs_core_pinedge_en_ovr_val_field pinedge_en_ovr_val_field
 * @brief macros for field pinedge_en_ovr_val
 * @details override val
 * @{
 */
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__SHIFT                                 23
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__WIDTH                                  1
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__MASK                         0x00800000U
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU14__PINEDGE_EN_OVR_VAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field en_5Vldo_ovr */
/**
 * @defgroup pmu_top_regs_core_en_5Vldo_ovr_field en_5Vldo_ovr_field
 * @brief macros for field en_5Vldo_ovr
 * @details override en_5Vldo
 * @{
 */
#define PMU_PMU14__EN_5VLDO_OVR__SHIFT                                       24
#define PMU_PMU14__EN_5VLDO_OVR__WIDTH                                        1
#define PMU_PMU14__EN_5VLDO_OVR__MASK                               0x01000000U
#define PMU_PMU14__EN_5VLDO_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU14__EN_5VLDO_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU14__EN_5VLDO_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU14__EN_5VLDO_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU14__EN_5VLDO_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU14__EN_5VLDO_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU14__EN_5VLDO_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field en_5Vldo_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_5Vldo_ovr_val_field en_5Vldo_ovr_val_field
 * @brief macros for field en_5Vldo_ovr_val
 * @details override en_5Vldo val: Enable 5LI LDO
 * @{
 */
#define PMU_PMU14__EN_5VLDO_OVR_VAL__SHIFT                                   25
#define PMU_PMU14__EN_5VLDO_OVR_VAL__WIDTH                                    1
#define PMU_PMU14__EN_5VLDO_OVR_VAL__MASK                           0x02000000U
#define PMU_PMU14__EN_5VLDO_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU14__EN_5VLDO_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU14__EN_5VLDO_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU14__EN_5VLDO_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU14__EN_5VLDO_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU14__EN_5VLDO_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU14__EN_5VLDO_OVR_VAL__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_swResVbat_ovr */
/**
 * @defgroup pmu_top_regs_core_en_swResVbat_ovr_field en_swResVbat_ovr_field
 * @brief macros for field en_swResVbat_ovr
 * @details override en_swResVbat
 * @{
 */
#define PMU_PMU14__EN_SWRESVBAT_OVR__SHIFT                                   26
#define PMU_PMU14__EN_SWRESVBAT_OVR__WIDTH                                    1
#define PMU_PMU14__EN_SWRESVBAT_OVR__MASK                           0x04000000U
#define PMU_PMU14__EN_SWRESVBAT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU14__EN_SWRESVBAT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU14__EN_SWRESVBAT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU14__EN_SWRESVBAT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU14__EN_SWRESVBAT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU14__EN_SWRESVBAT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU14__EN_SWRESVBAT_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_swResVbat_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_swResVbat_ovr_val_field en_swResVbat_ovr_val_field
 * @brief macros for field en_swResVbat_ovr_val
 * @details override en_swResVbat val: Enable VBATLI to VBAT swres
 * @{
 */
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__SHIFT                               27
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__WIDTH                                1
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__MASK                       0x08000000U
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU14__EN_SWRESVBAT_OVR_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ctr_ref_5Vldo_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_5Vldo_ovr_field ctr_ref_5Vldo_ovr_field
 * @brief macros for field ctr_ref_5Vldo_ovr
 * @details override ctr_ref_5Vldo
 * @{
 */
#define PMU_PMU14__CTR_REF_5VLDO_OVR__SHIFT                                  28
#define PMU_PMU14__CTR_REF_5VLDO_OVR__WIDTH                                   1
#define PMU_PMU14__CTR_REF_5VLDO_OVR__MASK                          0x10000000U
#define PMU_PMU14__CTR_REF_5VLDO_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU14__CTR_REF_5VLDO_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU14__CTR_REF_5VLDO_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU14__CTR_REF_5VLDO_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU14__CTR_REF_5VLDO_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU14__CTR_REF_5VLDO_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU14__CTR_REF_5VLDO_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ctr_ref_5Vldo_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_5Vldo_ovr_val_field ctr_ref_5Vldo_ovr_val_field
 * @brief macros for field ctr_ref_5Vldo_ovr_val
 * @details override ctr_ref_5Vldo val0: Locally generated reference from 5LI domain1: refgen reference for 5LI VBAT LDO reference
 * @{
 */
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__SHIFT                              29
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__WIDTH                               1
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__MASK                      0x20000000U
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU14__CTR_REF_5VLDO_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field buck_store_batt */
/**
 * @defgroup pmu_top_regs_core_buck_store_batt_field buck_store_batt_field
 * @brief macros for field buck_store_batt
 * @details use sw to change to buck (paris2)
 * @{
 */
#define PMU_PMU14__BUCK_STORE_BATT__SHIFT                                    30
#define PMU_PMU14__BUCK_STORE_BATT__WIDTH                                     1
#define PMU_PMU14__BUCK_STORE_BATT__MASK                            0x40000000U
#define PMU_PMU14__BUCK_STORE_BATT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU14__BUCK_STORE_BATT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU14__BUCK_STORE_BATT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU14__BUCK_STORE_BATT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU14__BUCK_STORE_BATT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU14__BUCK_STORE_BATT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU14__BUCK_STORE_BATT__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field boost_store_batt */
/**
 * @defgroup pmu_top_regs_core_boost_store_batt_field boost_store_batt_field
 * @brief macros for field boost_store_batt
 * @details use sw to change to boost (paris2)
 * @{
 */
#define PMU_PMU14__BOOST_STORE_BATT__SHIFT                                   31
#define PMU_PMU14__BOOST_STORE_BATT__WIDTH                                    1
#define PMU_PMU14__BOOST_STORE_BATT__MASK                           0x80000000U
#define PMU_PMU14__BOOST_STORE_BATT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU14__BOOST_STORE_BATT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU14__BOOST_STORE_BATT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU14__BOOST_STORE_BATT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU14__BOOST_STORE_BATT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU14__BOOST_STORE_BATT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU14__BOOST_STORE_BATT__RESET_VALUE                    0x00000000U
/** @} */
#define PMU_PMU14__TYPE                                                uint32_t
#define PMU_PMU14__READ                                             0xffffffffU
#define PMU_PMU14__WRITE                                            0xffffffffU
#define PMU_PMU14__PRESERVED                                        0x00000000U
#define PMU_PMU14__RESET_VALUE                                      0x00200020U

#endif /* __PMU_PMU14_MACRO__ */

/** @} end of pmu14 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu14a */
/**
 * @defgroup pmu_top_regs_core_pmu14a pmu14a
 * @brief ldo overrides definitions.
 * @{
 */
#ifndef __PMU_PMU14A_MACRO__
#define __PMU_PMU14A_MACRO__

/* macros for field en_ldoL1dvdd_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1dvdd_ovr_field en_ldoL1dvdd_ovr_field
 * @brief macros for field en_ldoL1dvdd_ovr
 * @details override en_ldoL1dvdd
 * @{
 */
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__SHIFT                                   0
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__WIDTH                                   1
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__MASK                          0x00000001U
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__READ(src) ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field en_ldoL1dvdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1dvdd_ovr_val_field en_ldoL1dvdd_ovr_val_field
 * @brief macros for field en_ldoL1dvdd_ovr_val
 * @details override en_ldoL1dvdd val: Enable L1 dvdd LDO
 * @{
 */
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__SHIFT                               1
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__WIDTH                               1
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__MASK                      0x00000002U
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU14A__EN_LDOL1DVDD_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field en_ldoL1vddio_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1vddio_ovr_field en_ldoL1vddio_ovr_field
 * @brief macros for field en_ldoL1vddio_ovr
 * @details override en_ldoL1vddio
 * @{
 */
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__SHIFT                                  2
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__WIDTH                                  1
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__MASK                         0x00000004U
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field en_ldoL1vddio_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1vddio_ovr_val_field en_ldoL1vddio_ovr_val_field
 * @brief macros for field en_ldoL1vddio_ovr_val
 * @details override en_ldoL1vddio val: Enable L1 vddio LDO
 * @{
 */
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__SHIFT                              3
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__WIDTH                              1
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__MASK                     0x00000008U
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU14A__EN_LDOL1VDDIO_OVR_VAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field en_ldoL1avdd_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1avdd_ovr_field en_ldoL1avdd_ovr_field
 * @brief macros for field en_ldoL1avdd_ovr
 * @details override en_ldoL1avdd
 * @{
 */
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__SHIFT                                   4
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__WIDTH                                   1
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__MASK                          0x00000010U
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field en_ldoL1avdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1avdd_ovr_val_field en_ldoL1avdd_ovr_val_field
 * @brief macros for field en_ldoL1avdd_ovr_val
 * @details override en_ldoL1avdd val: Enable L1 avdd LDO
 * @{
 */
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__SHIFT                               5
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__WIDTH                               1
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__MASK                      0x00000020U
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU14A__EN_LDOL1AVDD_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field mppt_test_state_ovr_val */
/**
 * @defgroup pmu_top_regs_core_mppt_test_state_ovr_val_field mppt_test_state_ovr_val_field
 * @brief macros for field mppt_test_state_ovr_val
 * @details mppt test state
 * @{
 */
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__SHIFT                            6
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__WIDTH                            4
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__MASK                   0x000003c0U
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define PMU_PMU14A__MPPT_TEST_STATE_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field mppt_test_state_ovr */
/**
 * @defgroup pmu_top_regs_core_mppt_test_state_ovr_field mppt_test_state_ovr_field
 * @brief macros for field mppt_test_state_ovr
 * @details ovr value for mppt test state
 * @{
 */
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__SHIFT                               10
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__WIDTH                                1
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__MASK                       0x00000400U
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU14A__MPPT_TEST_STATE_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ctr_mustharvfa_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_mustharvfa_ovr_val_field ctr_mustharvfa_ovr_val_field
 * @brief macros for field ctr_mustharvfa_ovr_val
 * @details override ctr_mustharvfa val: fast refgen tap selection for mustharv regulation
 * @{
 */
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__SHIFT                            11
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__WIDTH                             4
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__MASK                    0x00007800U
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007800U) >> 11)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00007800U)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007800U) | (((uint32_t)(src) <<\
                    11) & 0x00007800U)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00007800U)))
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_mustharvfa_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_mustharvfa_ovr_field ctr_mustharvfa_ovr_field
 * @brief macros for field ctr_mustharvfa_ovr
 * @details override ctr_mustharvfa
 * @{
 */
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__SHIFT                                15
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__WIDTH                                 1
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__MASK                        0x00008000U
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU14A__CTR_MUSTHARVFA_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ctr_mustharvsl_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_mustharvsl_ovr_val_field ctr_mustharvsl_ovr_val_field
 * @brief macros for field ctr_mustharvsl_ovr_val
 * @details override ctr_mustharvsl val: refgen tap selection for mustharv regulation
 * @{
 */
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__SHIFT                            16
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__WIDTH                             4
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__MASK                    0x000f0000U
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_mustharvsl_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_mustharvsl_ovr_field ctr_mustharvsl_ovr_field
 * @brief macros for field ctr_mustharvsl_ovr
 * @details override ctr_mustharvsl
 * @{
 */
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__SHIFT                                20
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__WIDTH                                 1
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__MASK                        0x00100000U
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU14A__CTR_MUSTHARVSL_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ctr_mustharvfastsel_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_mustharvfastsel_ovr_val_field ctr_mustharvfastsel_ovr_val_field
 * @brief macros for field ctr_mustharvfastsel_ovr_val
 * @details override ctr_mustharvfastsel val: select fast refgen instead of refgen for mustharv regulation
 * @{
 */
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__SHIFT                       21
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__WIDTH                        1
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__MASK               0x00200000U
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ctr_mustharvfastsel_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_mustharvfastsel_ovr_field ctr_mustharvfastsel_ovr_field
 * @brief macros for field ctr_mustharvfastsel_ovr
 * @details override ctr_mustharvfastsel
 * @{
 */
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__SHIFT                           22
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__WIDTH                            1
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__MASK                   0x00400000U
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU14A__CTR_MUSTHARVFASTSEL_OVR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field en_refcurr1u_ovr */
/**
 * @defgroup pmu_top_regs_core_en_refcurr1u_ovr_field en_refcurr1u_ovr_field
 * @brief macros for field en_refcurr1u_ovr
 * @details override en_refcurr1u
 * @{
 */
#define PMU_PMU14A__EN_REFCURR1U_OVR__SHIFT                                  23
#define PMU_PMU14A__EN_REFCURR1U_OVR__WIDTH                                   1
#define PMU_PMU14A__EN_REFCURR1U_OVR__MASK                          0x00800000U
#define PMU_PMU14A__EN_REFCURR1U_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU14A__EN_REFCURR1U_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU14A__EN_REFCURR1U_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU14A__EN_REFCURR1U_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU14A__EN_REFCURR1U_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU14A__EN_REFCURR1U_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU14A__EN_REFCURR1U_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field en_refcurr1u_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_refcurr1u_ovr_val_field en_refcurr1u_ovr_val_field
 * @brief macros for field en_refcurr1u_ovr_val
 * @details override en_refcurr1u val: Enable the 1uA current reference
 * @{
 */
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__SHIFT                              24
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__WIDTH                               1
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__MASK                      0x01000000U
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU14A__EN_REFCURR1U_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ctr_harvst_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_harvst_ovr_field ctr_harvst_ovr_field
 * @brief macros for field ctr_harvst_ovr
 * @details override ctr_harvst
 * @{
 */
#define PMU_PMU14A__CTR_HARVST_OVR__SHIFT                                    25
#define PMU_PMU14A__CTR_HARVST_OVR__WIDTH                                     1
#define PMU_PMU14A__CTR_HARVST_OVR__MASK                            0x02000000U
#define PMU_PMU14A__CTR_HARVST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU14A__CTR_HARVST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU14A__CTR_HARVST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU14A__CTR_HARVST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU14A__CTR_HARVST_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU14A__CTR_HARVST_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU14A__CTR_HARVST_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field ctr_harvst_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_harvst_ovr_val_field ctr_harvst_ovr_val_field
 * @brief macros for field ctr_harvst_ovr_val
 * @details override ctr_harvst val: Select the mustharv regulation level at cold start while vaux ramps upSelects the Vrefharv075 referenceVharv regulated at: 25 * (48,29,21,14)/0.75
 * @{
 */
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__SHIFT                                26
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__WIDTH                                 2
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__MASK                        0x0c000000U
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define PMU_PMU14A__CTR_HARVST_OVR_VAL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field en_chrg_ovr */
/**
 * @defgroup pmu_top_regs_core_en_chrg_ovr_field en_chrg_ovr_field
 * @brief macros for field en_chrg_ovr
 * @details override en_chrg
 * @{
 */
#define PMU_PMU14A__EN_CHRG_OVR__SHIFT                                       28
#define PMU_PMU14A__EN_CHRG_OVR__WIDTH                                        1
#define PMU_PMU14A__EN_CHRG_OVR__MASK                               0x10000000U
#define PMU_PMU14A__EN_CHRG_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU14A__EN_CHRG_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU14A__EN_CHRG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU14A__EN_CHRG_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU14A__EN_CHRG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU14A__EN_CHRG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU14A__EN_CHRG_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field en_chrg_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_chrg_ovr_val_field en_chrg_ovr_val_field
 * @brief macros for field en_chrg_ovr_val
 * @details override en_chrg val: Enables the VSTO->VBAT charger
 * @{
 */
#define PMU_PMU14A__EN_CHRG_OVR_VAL__SHIFT                                   29
#define PMU_PMU14A__EN_CHRG_OVR_VAL__WIDTH                                    1
#define PMU_PMU14A__EN_CHRG_OVR_VAL__MASK                           0x20000000U
#define PMU_PMU14A__EN_CHRG_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU14A__EN_CHRG_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU14A__EN_CHRG_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU14A__EN_CHRG_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU14A__EN_CHRG_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU14A__EN_CHRG_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU14A__EN_CHRG_OVR_VAL__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field override_scaleEnerg */
/**
 * @defgroup pmu_top_regs_core_override_scaleEnerg_field override_scaleEnerg_field
 * @brief macros for field override_scaleEnerg
 * @details overrides the scaleEnerg from pmuadc with that of reg_scaleEnerg
 * @{
 */
#define PMU_PMU14A__OVERRIDE_SCALEENERG__SHIFT                               30
#define PMU_PMU14A__OVERRIDE_SCALEENERG__WIDTH                                1
#define PMU_PMU14A__OVERRIDE_SCALEENERG__MASK                       0x40000000U
#define PMU_PMU14A__OVERRIDE_SCALEENERG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU14A__OVERRIDE_SCALEENERG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU14A__OVERRIDE_SCALEENERG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU14A__OVERRIDE_SCALEENERG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU14A__OVERRIDE_SCALEENERG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU14A__OVERRIDE_SCALEENERG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU14A__OVERRIDE_SCALEENERG__RESET_VALUE                0x00000000U
/** @} */
#define PMU_PMU14A__TYPE                                               uint32_t
#define PMU_PMU14A__READ                                            0x7fffffffU
#define PMU_PMU14A__WRITE                                           0x7fffffffU
#define PMU_PMU14A__PRESERVED                                       0x00000000U
#define PMU_PMU14A__RESET_VALUE                                     0x00000000U

#endif /* __PMU_PMU14A_MACRO__ */

/** @} end of pmu14a */

/* macros for BlueprintGlobalNameSpace::PMU_pmu14b */
/**
 * @defgroup pmu_top_regs_core_pmu14b pmu14b
 * @brief mppt regs definitions.
 * @{
 */
#ifndef __PMU_PMU14B_MACRO__
#define __PMU_PMU14B_MACRO__

/* macros for field mpptEventsTarget_reg */
/**
 * @defgroup pmu_top_regs_core_mpptEventsTarget_reg_field mpptEventsTarget_reg_field
 * @brief macros for field mpptEventsTarget_reg
 * @details number of events within the measured number of periods during GET_PERIODCNT
 * @{
 */
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__SHIFT                               0
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__WIDTH                              10
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__MASK                      0x000003ffU
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define PMU_PMU14B__MPPTEVENTSTARGET_REG__RESET_VALUE               0x000000c8U
/** @} */

/* macros for field mpptPeriodCnt_max */
/**
 * @defgroup pmu_top_regs_core_mpptPeriodCnt_max_field mpptPeriodCnt_max_field
 * @brief macros for field mpptPeriodCnt_max
 * @details upper limit on measured number of periods during GET_PERIODCNT
 * @{
 */
#define PMU_PMU14B__MPPTPERIODCNT_MAX__SHIFT                                 10
#define PMU_PMU14B__MPPTPERIODCNT_MAX__WIDTH                                 10
#define PMU_PMU14B__MPPTPERIODCNT_MAX__MASK                         0x000ffc00U
#define PMU_PMU14B__MPPTPERIODCNT_MAX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PMU_PMU14B__MPPTPERIODCNT_MAX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PMU_PMU14B__MPPTPERIODCNT_MAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PMU_PMU14B__MPPTPERIODCNT_MAX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define PMU_PMU14B__MPPTPERIODCNT_MAX__RESET_VALUE                  0x00000320U
/** @} */

/* macros for field ref_settle_cnt */
/**
 * @defgroup pmu_top_regs_core_ref_settle_cnt_field ref_settle_cnt_field
 * @brief macros for field ref_settle_cnt
 * @details settling time of fast refgen when the reference is changed
 * @{
 */
#define PMU_PMU14B__REF_SETTLE_CNT__SHIFT                                    20
#define PMU_PMU14B__REF_SETTLE_CNT__WIDTH                                     3
#define PMU_PMU14B__REF_SETTLE_CNT__MASK                            0x00700000U
#define PMU_PMU14B__REF_SETTLE_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00700000U) >> 20)
#define PMU_PMU14B__REF_SETTLE_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00700000U)
#define PMU_PMU14B__REF_SETTLE_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00700000U) | (((uint32_t)(src) <<\
                    20) & 0x00700000U)
#define PMU_PMU14B__REF_SETTLE_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00700000U)))
#define PMU_PMU14B__REF_SETTLE_CNT__RESET_VALUE                     0x00000004U
/** @} */

/* macros for field EventsCnt_thr */
/**
 * @defgroup pmu_top_regs_core_EventsCnt_thr_field EventsCnt_thr_field
 * @brief macros for field EventsCnt_thr
 * @details event threshold to recalculate optimum Vharv during MPPT_TRACK
 * @{
 */
#define PMU_PMU14B__EVENTSCNT_THR__SHIFT                                     23
#define PMU_PMU14B__EVENTSCNT_THR__WIDTH                                      5
#define PMU_PMU14B__EVENTSCNT_THR__MASK                             0x0f800000U
#define PMU_PMU14B__EVENTSCNT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f800000U) >> 23)
#define PMU_PMU14B__EVENTSCNT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x0f800000U)
#define PMU_PMU14B__EVENTSCNT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f800000U) | (((uint32_t)(src) <<\
                    23) & 0x0f800000U)
#define PMU_PMU14B__EVENTSCNT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x0f800000U)))
#define PMU_PMU14B__EVENTSCNT_THR__RESET_VALUE                      0x00000014U
/** @} */

/* macros for field swResavddldo_ctr */
/**
 * @defgroup pmu_top_regs_core_swResavddldo_ctr_field swResavddldo_ctr_field
 * @brief macros for field swResavddldo_ctr
 * @details control L2 avdd swres resistance, 0:200k, 1:100k
 * @{
 */
#define PMU_PMU14B__SWRESAVDDLDO_CTR__SHIFT                                  28
#define PMU_PMU14B__SWRESAVDDLDO_CTR__WIDTH                                   1
#define PMU_PMU14B__SWRESAVDDLDO_CTR__MASK                          0x10000000U
#define PMU_PMU14B__SWRESAVDDLDO_CTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU14B__SWRESAVDDLDO_CTR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU14B__SWRESAVDDLDO_CTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU14B__SWRESAVDDLDO_CTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU14B__SWRESAVDDLDO_CTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU14B__SWRESAVDDLDO_CTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU14B__SWRESAVDDLDO_CTR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ovr_bypstop */
/**
 * @defgroup pmu_top_regs_core_ovr_bypstop_field ovr_bypstop_field
 * @brief macros for field ovr_bypstop
 * @details For L1 LDO bypass mode1: prevent disabling the bypass when a high load current is detected0: allow the high current protection disable the bypass
 * @{
 */
#define PMU_PMU14B__OVR_BYPSTOP__SHIFT                                       29
#define PMU_PMU14B__OVR_BYPSTOP__WIDTH                                        1
#define PMU_PMU14B__OVR_BYPSTOP__MASK                               0x20000000U
#define PMU_PMU14B__OVR_BYPSTOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU14B__OVR_BYPSTOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU14B__OVR_BYPSTOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU14B__OVR_BYPSTOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU14B__OVR_BYPSTOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU14B__OVR_BYPSTOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU14B__OVR_BYPSTOP__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field enableHarv2Sup_active_reg */
/**
 * @defgroup pmu_top_regs_core_enableHarv2Sup_active_reg_field enableHarv2Sup_active_reg_field
 * @brief macros for field enableHarv2Sup_active_reg
 * @details sw can program whether in active we disable harv2sup or not0: Allow only Vstore to load in active if the load is very high1: Allow also Vharv to load in active to avoid double conversion loss
 * @{
 */
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__SHIFT                         30
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__WIDTH                          1
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__MASK                 0x40000000U
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU14B__ENABLEHARV2SUP_ACTIVE_REG__RESET_VALUE          0x00000000U
/** @} */
#define PMU_PMU14B__TYPE                                               uint32_t
#define PMU_PMU14B__READ                                            0x7fffffffU
#define PMU_PMU14B__WRITE                                           0x7fffffffU
#define PMU_PMU14B__PRESERVED                                       0x00000000U
#define PMU_PMU14B__RESET_VALUE                                     0x0a4c80c8U

#endif /* __PMU_PMU14B_MACRO__ */

/** @} end of pmu14b */

/* macros for BlueprintGlobalNameSpace::PMU_pmu14c */
/**
 * @defgroup pmu_top_regs_core_pmu14c pmu14c
 * @brief more mppt regs definitions.
 * @{
 */
#ifndef __PMU_PMU14C_MACRO__
#define __PMU_PMU14C_MACRO__

/* macros for field idle_cnt */
/**
 * @defgroup pmu_top_regs_core_idle_cnt_field idle_cnt_field
 * @brief macros for field idle_cnt
 * @details how many cycles to wait in idle before running mppt tracking, {idle_cnt,8'd0}
 * @{
 */
#define PMU_PMU14C__IDLE_CNT__SHIFT                                           0
#define PMU_PMU14C__IDLE_CNT__WIDTH                                          10
#define PMU_PMU14C__IDLE_CNT__MASK                                  0x000003ffU
#define PMU_PMU14C__IDLE_CNT__READ(src)         ((uint32_t)(src) & 0x000003ffU)
#define PMU_PMU14C__IDLE_CNT__WRITE(src)        ((uint32_t)(src) & 0x000003ffU)
#define PMU_PMU14C__IDLE_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PMU_PMU14C__IDLE_CNT__VERIFY(src) (!(((uint32_t)(src) & ~0x000003ffU)))
#define PMU_PMU14C__IDLE_CNT__RESET_VALUE                           0x00000004U
/** @} */

/* macros for field chargeStore */
/**
 * @defgroup pmu_top_regs_core_chargeStore_field chargeStore_field
 * @brief macros for field chargeStore
 * @details charge store from the battery
 * @{
 */
#define PMU_PMU14C__CHARGESTORE__SHIFT                                       10
#define PMU_PMU14C__CHARGESTORE__WIDTH                                        1
#define PMU_PMU14C__CHARGESTORE__MASK                               0x00000400U
#define PMU_PMU14C__CHARGESTORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU14C__CHARGESTORE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU14C__CHARGESTORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU14C__CHARGESTORE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU14C__CHARGESTORE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU14C__CHARGESTORE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU14C__CHARGESTORE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field fixHarvEnerg_ovr */
/**
 * @defgroup pmu_top_regs_core_fixHarvEnerg_ovr_field fixHarvEnerg_ovr_field
 * @brief macros for field fixHarvEnerg_ovr
 * @details override fixHarvEnerg
 * @{
 */
#define PMU_PMU14C__FIXHARVENERG_OVR__SHIFT                                  11
#define PMU_PMU14C__FIXHARVENERG_OVR__WIDTH                                   1
#define PMU_PMU14C__FIXHARVENERG_OVR__MASK                          0x00000800U
#define PMU_PMU14C__FIXHARVENERG_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU14C__FIXHARVENERG_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU14C__FIXHARVENERG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU14C__FIXHARVENERG_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU14C__FIXHARVENERG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU14C__FIXHARVENERG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU14C__FIXHARVENERG_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field fixHarvEnerg_ovr_val */
/**
 * @defgroup pmu_top_regs_core_fixHarvEnerg_ovr_val_field fixHarvEnerg_ovr_val_field
 * @brief macros for field fixHarvEnerg_ovr_val
 * @details override fixHarvEnerg val: Fix the energize time for all destinations when the source is theharvester. If fixHarvEnerg=1 the target for the harvest to supply modes is the energize time(timeTargetHarv2Store_SH to set the energize time),otherwise it is the dump time.
 * @{
 */
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__SHIFT                              12
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__WIDTH                               1
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__MASK                      0x00001000U
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU14C__FIXHARVENERG_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field force_zerompptref_encomp_off_inv */
/**
 * @defgroup pmu_top_regs_core_force_zerompptref_encomp_off_inv_field force_zerompptref_encomp_off_inv_field
 * @brief macros for field force_zerompptref_encomp_off_inv
 * @details enable the zerompptref comparator, 1: zerompptref_encomp=1
 * @{
 */
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__SHIFT                  13
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__WIDTH                   1
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__MASK          0x00002000U
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU14C__FORCE_ZEROMPPTREF_ENCOMP_OFF_INV__RESET_VALUE   0x00000001U
/** @} */

/* macros for field force_ovr_encompb_zeromppt_off_inv */
/**
 * @defgroup pmu_top_regs_core_force_ovr_encompb_zeromppt_off_inv_field force_ovr_encompb_zeromppt_off_inv_field
 * @brief macros for field force_ovr_encompb_zeromppt_off_inv
 * @details same with ovr_encompb_zeromppt. When deasserted, zerompptref disables the can/mustharv comparators
 * @{
 */
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__SHIFT                14
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__WIDTH                 1
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__MASK        0x00004000U
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_ZEROMPPT_OFF_INV__RESET_VALUE 0x00000001U
/** @} */

/* macros for field force_ovr_encompb_increctst_off_inv */
/**
 * @defgroup pmu_top_regs_core_force_ovr_encompb_increctst_off_inv_field force_ovr_encompb_increctst_off_inv_field
 * @brief macros for field force_ovr_encompb_increctst_off_inv
 * @details same with ovr_encompb_increctst. When deasserted, chpuhswoff_increctst disables the can/mustharv comparators
 * @{
 */
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__SHIFT               15
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__WIDTH                1
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__MASK       0x00008000U
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU14C__FORCE_OVR_ENCOMPB_INCRECTST_OFF_INV__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field refbuf_ovr */
/**
 * @defgroup pmu_top_regs_core_refbuf_ovr_field refbuf_ovr_field
 * @brief macros for field refbuf_ovr
 * @details overrides the reference buffer enable and bypass
 * @{
 */
#define PMU_PMU14C__REFBUF_OVR__SHIFT                                        16
#define PMU_PMU14C__REFBUF_OVR__WIDTH                                         1
#define PMU_PMU14C__REFBUF_OVR__MASK                                0x00010000U
#define PMU_PMU14C__REFBUF_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU14C__REFBUF_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU14C__REFBUF_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU14C__REFBUF_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU14C__REFBUF_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU14C__REFBUF_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU14C__REFBUF_OVR__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field SwchReqDVDD_enrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_enrefbuf_ovr_val_field SwchReqDVDD_enrefbuf_ovr_val_field
 * @brief macros for field SwchReqDVDD_enrefbuf_ovr_val
 * @details override SwchReqDVDD_enrefbuf val: The corresponding reference is buffered at the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__SHIFT                      17
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__MASK              0x00020000U
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU14C__SWCHREQDVDD_ENREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field SwchReqvaux_enrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqvaux_enrefbuf_ovr_val_field SwchReqvaux_enrefbuf_ovr_val_field
 * @brief macros for field SwchReqvaux_enrefbuf_ovr_val
 * @details override SwchReqvaux_enrefbuf val: The corresponding reference is buffered at the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__SHIFT                      18
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__MASK              0x00040000U
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU14C__SWCHREQVAUX_ENREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field SwchReqAVDD_enrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_enrefbuf_ovr_val_field SwchReqAVDD_enrefbuf_ovr_val_field
 * @brief macros for field SwchReqAVDD_enrefbuf_ovr_val
 * @details override SwchReqAVDD_enrefbuf val: The corresponding reference is buffered at the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__SHIFT                      19
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__MASK              0x00080000U
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU14C__SWCHREQAVDD_ENREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field harvstop_enrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_harvstop_enrefbuf_ovr_val_field harvstop_enrefbuf_ovr_val_field
 * @brief macros for field harvstop_enrefbuf_ovr_val
 * @details override harvstop_enrefbuf val: The corresponding reference is buffered at the comparator input
 * @{
 */
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__SHIFT                         20
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__WIDTH                          1
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__MASK                 0x00100000U
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU14C__HARVSTOP_ENREFBUF_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field SwchReqVSTO_enrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVSTO_enrefbuf_ovr_val_field SwchReqVSTO_enrefbuf_ovr_val_field
 * @brief macros for field SwchReqVSTO_enrefbuf_ovr_val
 * @details override SwchReqVSTO_enrefbuf val: The corresponding reference is buffered at the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__SHIFT                      21
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__MASK              0x00200000U
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU14C__SWCHREQVSTO_ENREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field SwchReqDVDD_byrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_byrefbuf_ovr_val_field SwchReqDVDD_byrefbuf_ovr_val_field
 * @brief macros for field SwchReqDVDD_byrefbuf_ovr_val
 * @details override SwchReqDVDD_byrefbuf val: The corresponding reference is bypassed to the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__SHIFT                      22
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__MASK              0x00400000U
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU14C__SWCHREQDVDD_BYREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field SwchReqvaux_byrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqvaux_byrefbuf_ovr_val_field SwchReqvaux_byrefbuf_ovr_val_field
 * @brief macros for field SwchReqvaux_byrefbuf_ovr_val
 * @details override SwchReqvaux_byrefbuf val: The corresponding reference is bypassed to the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__SHIFT                      23
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__MASK              0x00800000U
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU14C__SWCHREQVAUX_BYREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field SwchReqAVDD_byrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_byrefbuf_ovr_val_field SwchReqAVDD_byrefbuf_ovr_val_field
 * @brief macros for field SwchReqAVDD_byrefbuf_ovr_val
 * @details override SwchReqAVDD_byrefbuf val: The corresponding reference is bypassed to the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__SHIFT                      24
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__MASK              0x01000000U
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU14C__SWCHREQAVDD_BYREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field harvstop_byrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_harvstop_byrefbuf_ovr_val_field harvstop_byrefbuf_ovr_val_field
 * @brief macros for field harvstop_byrefbuf_ovr_val
 * @details override harvstop_byrefbuf val: The corresponding reference is bypassed to the comparator input
 * @{
 */
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__SHIFT                         25
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__WIDTH                          1
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__MASK                 0x02000000U
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU14C__HARVSTOP_BYREFBUF_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field SwchReqVSTO_byrefbuf_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVSTO_byrefbuf_ovr_val_field SwchReqVSTO_byrefbuf_ovr_val_field
 * @brief macros for field SwchReqVSTO_byrefbuf_ovr_val
 * @details override SwchReqVSTO_byrefbuf val: The corresponding reference is bypassed to the comparator input
 * @{
 */
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__SHIFT                      26
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__WIDTH                       1
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__MASK              0x04000000U
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU14C__SWCHREQVSTO_BYREFBUF_OVR_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field ctr_prtsatcurr_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_prtsatcurr_ovr_field ctr_prtsatcurr_ovr_field
 * @brief macros for field ctr_prtsatcurr_ovr
 * @details override ctr_prtsatcurr
 * @{
 */
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__SHIFT                                27
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__WIDTH                                 1
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__MASK                        0x08000000U
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ctr_prtsatcurr_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_prtsatcurr_ovr_val_field ctr_prtsatcurr_ovr_val_field
 * @brief macros for field ctr_prtsatcurr_ovr_val
 * @details override ctr_prtsatcurr val: enables the L1 LDO current protection when in regulating mode. Enabled by default
 * @{
 */
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__SHIFT                            28
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__WIDTH                             1
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__MASK                    0x10000000U
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU14C__CTR_PRTSATCURR_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field reg_swreg_clkcal_ctrl */
/**
 * @defgroup pmu_top_regs_core_reg_swreg_clkcal_ctrl_field reg_swreg_clkcal_ctrl_field
 * @brief macros for field reg_swreg_clkcal_ctrl
 * @details when asserted can set reg_swreg_clkcal into updateUnitDel
 * @{
 */
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__SHIFT                             29
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__WIDTH                              1
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__MASK                     0x20000000U
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU14C__REG_SWREG_CLKCAL_CTRL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field reg_swreg_clkcal */
/**
 * @defgroup pmu_top_regs_core_reg_swreg_clkcal_field reg_swreg_clkcal_field
 * @brief macros for field reg_swreg_clkcal
 * @details set updateUnitDel
 * @{
 */
#define PMU_PMU14C__REG_SWREG_CLKCAL__SHIFT                                  30
#define PMU_PMU14C__REG_SWREG_CLKCAL__WIDTH                                   1
#define PMU_PMU14C__REG_SWREG_CLKCAL__MASK                          0x40000000U
#define PMU_PMU14C__REG_SWREG_CLKCAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU14C__REG_SWREG_CLKCAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU14C__REG_SWREG_CLKCAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU14C__REG_SWREG_CLKCAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU14C__REG_SWREG_CLKCAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU14C__REG_SWREG_CLKCAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU14C__REG_SWREG_CLKCAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field stoclamp_encomp */
/**
 * @defgroup pmu_top_regs_core_stoclamp_encomp_field stoclamp_encomp_field
 * @brief macros for field stoclamp_encomp
 * @details enable Vstore clamp comparator for Vstore overdrive protection
 * @{
 */
#define PMU_PMU14C__STOCLAMP_ENCOMP__SHIFT                                   31
#define PMU_PMU14C__STOCLAMP_ENCOMP__WIDTH                                    1
#define PMU_PMU14C__STOCLAMP_ENCOMP__MASK                           0x80000000U
#define PMU_PMU14C__STOCLAMP_ENCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU14C__STOCLAMP_ENCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU14C__STOCLAMP_ENCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU14C__STOCLAMP_ENCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU14C__STOCLAMP_ENCOMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU14C__STOCLAMP_ENCOMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU14C__STOCLAMP_ENCOMP__RESET_VALUE                    0x00000001U
/** @} */
#define PMU_PMU14C__TYPE                                               uint32_t
#define PMU_PMU14C__READ                                            0xffffffffU
#define PMU_PMU14C__WRITE                                           0xffffffffU
#define PMU_PMU14C__PRESERVED                                       0x00000000U
#define PMU_PMU14C__RESET_VALUE                                     0x8000e004U

#endif /* __PMU_PMU14C_MACRO__ */

/** @} end of pmu14c */

/* macros for BlueprintGlobalNameSpace::PMU_pmu15 */
/**
 * @defgroup pmu_top_regs_core_pmu15 pmu15
 * @brief more pmu controls definitions.
 * @{
 */
#ifndef __PMU_PMU15_MACRO__
#define __PMU_PMU15_MACRO__

/* macros for field ctr_reffstInsel */
/**
 * @defgroup pmu_top_regs_core_ctr_reffstInsel_field ctr_reffstInsel_field
 * @brief macros for field ctr_reffstInsel
 * @details fast refgen feedback tap select. For reference=600mV3: 625mV reflad<25>2: 600mV reflad<24>1: 575mV reflad<23>0: 550mV reflad<22>
 * @{
 */
#define PMU_PMU15__CTR_REFFSTINSEL__SHIFT                                     0
#define PMU_PMU15__CTR_REFFSTINSEL__WIDTH                                     2
#define PMU_PMU15__CTR_REFFSTINSEL__MASK                            0x00000003U
#define PMU_PMU15__CTR_REFFSTINSEL__READ(src)   ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU15__CTR_REFFSTINSEL__WRITE(src)  ((uint32_t)(src) & 0x00000003U)
#define PMU_PMU15__CTR_REFFSTINSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PMU_PMU15__CTR_REFFSTINSEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PMU_PMU15__CTR_REFFSTINSEL__RESET_VALUE                     0x00000002U
/** @} */

/* macros for field ctr_refgenfastcurr */
/**
 * @defgroup pmu_top_regs_core_ctr_refgenfastcurr_field ctr_refgenfastcurr_field
 * @brief macros for field ctr_refgenfastcurr
 * @details control current of fast refgen
 * @{
 */
#define PMU_PMU15__CTR_REFGENFASTCURR__SHIFT                                  2
#define PMU_PMU15__CTR_REFGENFASTCURR__WIDTH                                  1
#define PMU_PMU15__CTR_REFGENFASTCURR__MASK                         0x00000004U
#define PMU_PMU15__CTR_REFGENFASTCURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU15__CTR_REFGENFASTCURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU15__CTR_REFGENFASTCURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU15__CTR_REFGENFASTCURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU15__CTR_REFGENFASTCURR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU15__CTR_REFGENFASTCURR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU15__CTR_REFGENFASTCURR__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field ctr_refvstoreq */
/**
 * @defgroup pmu_top_regs_core_ctr_refvstoreq_field ctr_refvstoreq_field
 * @brief macros for field ctr_refvstoreq
 * @details control VrefvstoReq= 25*(16+i*8), i=7:0
 * @{
 */
#define PMU_PMU15__CTR_REFVSTOREQ__SHIFT                                      3
#define PMU_PMU15__CTR_REFVSTOREQ__WIDTH                                      3
#define PMU_PMU15__CTR_REFVSTOREQ__MASK                             0x00000038U
#define PMU_PMU15__CTR_REFVSTOREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define PMU_PMU15__CTR_REFVSTOREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define PMU_PMU15__CTR_REFVSTOREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define PMU_PMU15__CTR_REFVSTOREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define PMU_PMU15__CTR_REFVSTOREQ__RESET_VALUE                      0x00000003U
/** @} */

/* macros for field ctr_refvstoreq_lowR */
/**
 * @defgroup pmu_top_regs_core_ctr_refvstoreq_lowR_field ctr_refvstoreq_lowR_field
 * @brief macros for field ctr_refvstoreq_lowR
 * @details Selects different vstore comparator reference1: reference generated by the lowR resistor in the pmuparef0: reference generated by refgen
 * @{
 */
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__SHIFT                                 6
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__WIDTH                                 1
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__MASK                        0x00000040U
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU15__CTR_REFVSTOREQ_LOWR__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field ctr_zerompptref */
/**
 * @defgroup pmu_top_regs_core_ctr_zerompptref_field ctr_zerompptref_field
 * @brief macros for field ctr_zerompptref
 * @details control Vrefzerompptref used by the zerompptref comparator25*[9,8,6,4], i=3:0
 * @{
 */
#define PMU_PMU15__CTR_ZEROMPPTREF__SHIFT                                     7
#define PMU_PMU15__CTR_ZEROMPPTREF__WIDTH                                     2
#define PMU_PMU15__CTR_ZEROMPPTREF__MASK                            0x00000180U
#define PMU_PMU15__CTR_ZEROMPPTREF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000180U) >> 7)
#define PMU_PMU15__CTR_ZEROMPPTREF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000180U)
#define PMU_PMU15__CTR_ZEROMPPTREF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000180U) | (((uint32_t)(src) <<\
                    7) & 0x00000180U)
#define PMU_PMU15__CTR_ZEROMPPTREF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000180U)))
#define PMU_PMU15__CTR_ZEROMPPTREF__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field ctr_refshreg */
/**
 * @defgroup pmu_top_regs_core_ctr_refshreg_field ctr_refshreg_field
 * @brief macros for field ctr_refshreg
 * @details Control Vrefshreg used by the rectifier shunt regulator,25*(36+i*4), i=3:0
 * @{
 */
#define PMU_PMU15__CTR_REFSHREG__SHIFT                                        9
#define PMU_PMU15__CTR_REFSHREG__WIDTH                                        2
#define PMU_PMU15__CTR_REFSHREG__MASK                               0x00000600U
#define PMU_PMU15__CTR_REFSHREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000600U) >> 9)
#define PMU_PMU15__CTR_REFSHREG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000600U)
#define PMU_PMU15__CTR_REFSHREG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000600U) | (((uint32_t)(src) <<\
                    9) & 0x00000600U)
#define PMU_PMU15__CTR_REFSHREG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000600U)))
#define PMU_PMU15__CTR_REFSHREG__RESET_VALUE                        0x00000002U
/** @} */

/* macros for field ctr_pmuadcref */
/**
 * @defgroup pmu_top_regs_core_ctr_pmuadcref_field ctr_pmuadcref_field
 * @brief macros for field ctr_pmuadcref
 * @details Control pmuadcref, 25*(23+i-1) for i=3:1, vrefnat600 for i=0
 * @{
 */
#define PMU_PMU15__CTR_PMUADCREF__SHIFT                                      11
#define PMU_PMU15__CTR_PMUADCREF__WIDTH                                       2
#define PMU_PMU15__CTR_PMUADCREF__MASK                              0x00001800U
#define PMU_PMU15__CTR_PMUADCREF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define PMU_PMU15__CTR_PMUADCREF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define PMU_PMU15__CTR_PMUADCREF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define PMU_PMU15__CTR_PMUADCREF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define PMU_PMU15__CTR_PMUADCREF__RESET_VALUE                       0x00000002U
/** @} */

/* macros for field ctr_usevsto4avddreq */
/**
 * @defgroup pmu_top_regs_core_ctr_usevsto4avddreq_field ctr_usevsto4avddreq_field
 * @brief macros for field ctr_usevsto4avddreq
 * @details Use the Vstore request comparator to sense avdd and generate avdd requestsIt takes over the avdd request comparator thanks to its NMOS+PMOS full scale input.
 * @{
 */
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__SHIFT                                13
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__WIDTH                                 1
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__MASK                        0x00002000U
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU15__CTR_USEVSTO4AVDDREQ__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field decrectst_enhy */
/**
 * @defgroup pmu_top_regs_core_decrectst_enhy_field decrectst_enhy_field
 * @brief macros for field decrectst_enhy
 * @details enable hysteresis in the decrectstage_prtVharv comparator1: When used to protect Vharv at ~3V during solar harvesting0: During RF mppt that we want to regulate efficiently Vharv till the number of rectifier stages change
 * @{
 */
#define PMU_PMU15__DECRECTST_ENHY__SHIFT                                     14
#define PMU_PMU15__DECRECTST_ENHY__WIDTH                                      1
#define PMU_PMU15__DECRECTST_ENHY__MASK                             0x00004000U
#define PMU_PMU15__DECRECTST_ENHY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU15__DECRECTST_ENHY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU15__DECRECTST_ENHY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU15__DECRECTST_ENHY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU15__DECRECTST_ENHY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU15__DECRECTST_ENHY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU15__DECRECTST_ENHY__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field zerompptref_ctrcu */
/**
 * @defgroup pmu_top_regs_core_zerompptref_ctrcu_field zerompptref_ctrcu_field
 * @brief macros for field zerompptref_ctrcu
 * @details control the fast current of zerompptref comparator
 * @{
 */
#define PMU_PMU15__ZEROMPPTREF_CTRCU__SHIFT                                  15
#define PMU_PMU15__ZEROMPPTREF_CTRCU__WIDTH                                   5
#define PMU_PMU15__ZEROMPPTREF_CTRCU__MASK                          0x000f8000U
#define PMU_PMU15__ZEROMPPTREF_CTRCU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define PMU_PMU15__ZEROMPPTREF_CTRCU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define PMU_PMU15__ZEROMPPTREF_CTRCU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define PMU_PMU15__ZEROMPPTREF_CTRCU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define PMU_PMU15__ZEROMPPTREF_CTRCU__RESET_VALUE                   0x00000007U
/** @} */

/* macros for field en_compshreg */
/**
 * @defgroup pmu_top_regs_core_en_compshreg_field en_compshreg_field
 * @brief macros for field en_compshreg
 * @details Enable the shunt regulator on RFHARV input
 * @{
 */
#define PMU_PMU15__EN_COMPSHREG__SHIFT                                       20
#define PMU_PMU15__EN_COMPSHREG__WIDTH                                        1
#define PMU_PMU15__EN_COMPSHREG__MASK                               0x00100000U
#define PMU_PMU15__EN_COMPSHREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU15__EN_COMPSHREG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU15__EN_COMPSHREG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU15__EN_COMPSHREG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU15__EN_COMPSHREG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU15__EN_COMPSHREG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU15__EN_COMPSHREG__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field en_shuntrf */
/**
 * @defgroup pmu_top_regs_core_en_shuntrf_field en_shuntrf_field
 * @brief macros for field en_shuntrf
 * @details Shunt the RFHARV input to ground to check the maximum shunting ability of shunt regulator
 * @{
 */
#define PMU_PMU15__EN_SHUNTRF__SHIFT                                         21
#define PMU_PMU15__EN_SHUNTRF__WIDTH                                          1
#define PMU_PMU15__EN_SHUNTRF__MASK                                 0x00200000U
#define PMU_PMU15__EN_SHUNTRF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU15__EN_SHUNTRF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU15__EN_SHUNTRF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU15__EN_SHUNTRF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU15__EN_SHUNTRF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU15__EN_SHUNTRF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU15__EN_SHUNTRF__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field en_pmurectleakcu */
/**
 * @defgroup pmu_top_regs_core_en_pmurectleakcu_field en_pmurectleakcu_field
 * @brief macros for field en_pmurectleakcu
 * @details add an imbalance current into the RF harvesting rectifiers to make sure they latch when OFFto help prevent any stress issue in the rectifier core devices
 * @{
 */
#define PMU_PMU15__EN_PMURECTLEAKCU__SHIFT                                   22
#define PMU_PMU15__EN_PMURECTLEAKCU__WIDTH                                    1
#define PMU_PMU15__EN_PMURECTLEAKCU__MASK                           0x00400000U
#define PMU_PMU15__EN_PMURECTLEAKCU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU15__EN_PMURECTLEAKCU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU15__EN_PMURECTLEAKCU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU15__EN_PMURECTLEAKCU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU15__EN_PMURECTLEAKCU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU15__EN_PMURECTLEAKCU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU15__EN_PMURECTLEAKCU__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ctr_prtbypcurr_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_prtbypcurr_ovr_field ctr_prtbypcurr_ovr_field
 * @brief macros for field ctr_prtbypcurr_ovr
 * @details unused
 * @{
 */
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__SHIFT                                 23
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__WIDTH                                  1
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__MASK                         0x00800000U
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field ctr_prtbypcurr_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_prtbypcurr_ovr_val_field ctr_prtbypcurr_ovr_val_field
 * @brief macros for field ctr_prtbypcurr_ovr_val
 * @details unused
 * @{
 */
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__SHIFT                             24
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__WIDTH                              1
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__MASK                     0x01000000U
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU15__CTR_PRTBYPCURR_OVR_VAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field swResVbat_ctrcu */
/**
 * @defgroup pmu_top_regs_core_swResVbat_ctrcu_field swResVbat_ctrcu_field
 * @brief macros for field swResVbat_ctrcu
 * @details control the swResVbat comparator currentctr_cuLow with <1:0>, ctr_cuMid with <3:2>, ctr_cuMidx2 with <4>
 * @{
 */
#define PMU_PMU15__SWRESVBAT_CTRCU__SHIFT                                    25
#define PMU_PMU15__SWRESVBAT_CTRCU__WIDTH                                     5
#define PMU_PMU15__SWRESVBAT_CTRCU__MASK                            0x3e000000U
#define PMU_PMU15__SWRESVBAT_CTRCU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define PMU_PMU15__SWRESVBAT_CTRCU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define PMU_PMU15__SWRESVBAT_CTRCU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define PMU_PMU15__SWRESVBAT_CTRCU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define PMU_PMU15__SWRESVBAT_CTRCU__RESET_VALUE                     0x0000001fU
/** @} */

/* macros for field swResVbat_ctrsamecurr */
/**
 * @defgroup pmu_top_regs_core_swResVbat_ctrsamecurr_field swResVbat_ctrsamecurr_field
 * @brief macros for field swResVbat_ctrsamecurr
 * @details control slow current in swResVbat comparator0: decrease the slow current1: keep the slow current equal to the fast
 * @{
 */
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__SHIFT                              30
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__WIDTH                               1
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__MASK                      0x40000000U
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU15__SWRESVBAT_CTRSAMECURR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field swRes_ctrsamecurr */
/**
 * @defgroup pmu_top_regs_core_swRes_ctrsamecurr_field swRes_ctrsamecurr_field
 * @brief macros for field swRes_ctrsamecurr
 * @details control slow current in swRes comparator used in cold start0: decrease the slow current1: keep the slow current equal to the fast
 * @{
 */
#define PMU_PMU15__SWRES_CTRSAMECURR__SHIFT                                  31
#define PMU_PMU15__SWRES_CTRSAMECURR__WIDTH                                   1
#define PMU_PMU15__SWRES_CTRSAMECURR__MASK                          0x80000000U
#define PMU_PMU15__SWRES_CTRSAMECURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU15__SWRES_CTRSAMECURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU15__SWRES_CTRSAMECURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU15__SWRES_CTRSAMECURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU15__SWRES_CTRSAMECURR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU15__SWRES_CTRSAMECURR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU15__SWRES_CTRSAMECURR__RESET_VALUE                   0x00000000U
/** @} */
#define PMU_PMU15__TYPE                                                uint32_t
#define PMU_PMU15__READ                                             0xffffffffU
#define PMU_PMU15__WRITE                                            0xffffffffU
#define PMU_PMU15__PRESERVED                                        0x00000000U
#define PMU_PMU15__RESET_VALUE                                      0x3e13d4deU

#endif /* __PMU_PMU15_MACRO__ */

/** @} end of pmu15 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu16 */
/**
 * @defgroup pmu_top_regs_core_pmu16 pmu16
 * @brief more config bits definitions.
 * @{
 */
#ifndef __PMU_PMU16_MACRO__
#define __PMU_PMU16_MACRO__

/* macros for field paRef */
/**
 * @defgroup pmu_top_regs_core_paRef_field paRef_field
 * @brief macros for field paRef
 * @details control the pa supply ref
 * @{
 */
#define PMU_PMU16__PAREF__SHIFT                                               0
#define PMU_PMU16__PAREF__WIDTH                                               6
#define PMU_PMU16__PAREF__MASK                                      0x0000003fU
#define PMU_PMU16__PAREF__READ(src)             ((uint32_t)(src) & 0x0000003fU)
#define PMU_PMU16__PAREF__WRITE(src)            ((uint32_t)(src) & 0x0000003fU)
#define PMU_PMU16__PAREF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PMU_PMU16__PAREF__VERIFY(src)     (!(((uint32_t)(src) & ~0x0000003fU)))
#define PMU_PMU16__PAREF__RESET_VALUE                               0x00000039U
/** @} */

/* macros for field swreg_fsmToUse_ovr */
/**
 * @defgroup pmu_top_regs_core_swreg_fsmToUse_ovr_field swreg_fsmToUse_ovr_field
 * @brief macros for field swreg_fsmToUse_ovr
 * @details override swreg_fsmToUse
 * @{
 */
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__SHIFT                                  6
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__WIDTH                                  1
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__MASK                         0x00000040U
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field swreg_fsmToUse_ovr_val */
/**
 * @defgroup pmu_top_regs_core_swreg_fsmToUse_ovr_val_field swreg_fsmToUse_ovr_val_field
 * @brief macros for field swreg_fsmToUse_ovr_val
 * @details override swreg_fsmToUse val: can force the FSM to use
 * @{
 */
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__SHIFT                              7
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__WIDTH                              2
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__MASK                     0x00000180U
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000180U) >> 7)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000180U)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000180U) | (((uint32_t)(src) <<\
                    7) & 0x00000180U)
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000180U)))
#define PMU_PMU16__SWREG_FSMTOUSE_OVR_VAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field fsm_lp_harv_reg */
/**
 * @defgroup pmu_top_regs_core_fsm_lp_harv_reg_field fsm_lp_harv_reg_field
 * @brief macros for field fsm_lp_harv_reg
 * @details selects idle state FSM if no harvsting, 0: FSM is tiny, 1: FSM is simple
 * @{
 */
#define PMU_PMU16__FSM_LP_HARV_REG__SHIFT                                     9
#define PMU_PMU16__FSM_LP_HARV_REG__WIDTH                                     2
#define PMU_PMU16__FSM_LP_HARV_REG__MASK                            0x00000600U
#define PMU_PMU16__FSM_LP_HARV_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000600U) >> 9)
#define PMU_PMU16__FSM_LP_HARV_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000600U)
#define PMU_PMU16__FSM_LP_HARV_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000600U) | (((uint32_t)(src) <<\
                    9) & 0x00000600U)
#define PMU_PMU16__FSM_LP_HARV_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000600U)))
#define PMU_PMU16__FSM_LP_HARV_REG__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field storeIsSup */
/**
 * @defgroup pmu_top_regs_core_storeIsSup_field storeIsSup_field
 * @brief macros for field storeIsSup
 * @details When set the Vstore is a supply used ie for the PA.
 * @{
 */
#define PMU_PMU16__STOREISSUP__SHIFT                                         11
#define PMU_PMU16__STOREISSUP__WIDTH                                          1
#define PMU_PMU16__STOREISSUP__MASK                                 0x00000800U
#define PMU_PMU16__STOREISSUP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU16__STOREISSUP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU16__STOREISSUP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU16__STOREISSUP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU16__STOREISSUP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU16__STOREISSUP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU16__STOREISSUP__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field ovr_decrectstage_prtVharv_ovr */
/**
 * @defgroup pmu_top_regs_core_ovr_decrectstage_prtVharv_ovr_field ovr_decrectstage_prtVharv_ovr_field
 * @brief macros for field ovr_decrectstage_prtVharv_ovr
 * @details override ovr_decrectstage_prtVharv. The ovr_decrectstage_prtVharv is controlled by the analog mppt algorithm.
 * @{
 */
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__SHIFT                      12
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__WIDTH                       1
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__MASK              0x00001000U
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR__RESET_VALUE       0x00000000U
/** @} */

/* macros for field ovr_decrectstage_prtVharv_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ovr_decrectstage_prtVharv_ovr_val_field ovr_decrectstage_prtVharv_ovr_val_field
 * @brief macros for field ovr_decrectstage_prtVharv_ovr_val
 * @details override ovr_decrectstage_prtVharv val:0: the decrectstage_prtVharv forces can/mustharv to requestImportant to be applied right after the number of stages is decreased during analog mppt1: the decrectstage_prtVharv has no effect on can/mustharv
 * @{
 */
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__SHIFT                  13
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__WIDTH                   1
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__MASK          0x00002000U
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU16__OVR_DECRECTSTAGE_PRTVHARV_OVR_VAL__RESET_VALUE   0x00000000U
/** @} */

/* macros for field increctst_ctrcuMid0 */
/**
 * @defgroup pmu_top_regs_core_increctst_ctrcuMid0_field increctst_ctrcuMid0_field
 * @brief macros for field increctst_ctrcuMid0
 * @details Mid current setting of chpuhsw_increctstage comparator when churge pump is disabled.
 * @{
 */
#define PMU_PMU16__INCRECTST_CTRCUMID0__SHIFT                                14
#define PMU_PMU16__INCRECTST_CTRCUMID0__WIDTH                                 1
#define PMU_PMU16__INCRECTST_CTRCUMID0__MASK                        0x00004000U
#define PMU_PMU16__INCRECTST_CTRCUMID0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU16__INCRECTST_CTRCUMID0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU16__INCRECTST_CTRCUMID0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU16__INCRECTST_CTRCUMID0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU16__INCRECTST_CTRCUMID0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU16__INCRECTST_CTRCUMID0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU16__INCRECTST_CTRCUMID0__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field increctst_ctrcuMid1 */
/**
 * @defgroup pmu_top_regs_core_increctst_ctrcuMid1_field increctst_ctrcuMid1_field
 * @brief macros for field increctst_ctrcuMid1
 * @details Mid current setting of chpuhsw_increctstage comparator when churge pump is enabledNeed faster comparator response for Vharv protection.
 * @{
 */
#define PMU_PMU16__INCRECTST_CTRCUMID1__SHIFT                                15
#define PMU_PMU16__INCRECTST_CTRCUMID1__WIDTH                                 1
#define PMU_PMU16__INCRECTST_CTRCUMID1__MASK                        0x00008000U
#define PMU_PMU16__INCRECTST_CTRCUMID1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU16__INCRECTST_CTRCUMID1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU16__INCRECTST_CTRCUMID1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU16__INCRECTST_CTRCUMID1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU16__INCRECTST_CTRCUMID1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU16__INCRECTST_CTRCUMID1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU16__INCRECTST_CTRCUMID1__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field decrectst_ctrcuMid */
/**
 * @defgroup pmu_top_regs_core_decrectst_ctrcuMid_field decrectst_ctrcuMid_field
 * @brief macros for field decrectst_ctrcuMid
 * @details Mid current setting of decrectstage_prtVharv comparator
 * @{
 */
#define PMU_PMU16__DECRECTST_CTRCUMID__SHIFT                                 16
#define PMU_PMU16__DECRECTST_CTRCUMID__WIDTH                                  1
#define PMU_PMU16__DECRECTST_CTRCUMID__MASK                         0x00010000U
#define PMU_PMU16__DECRECTST_CTRCUMID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU16__DECRECTST_CTRCUMID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU16__DECRECTST_CTRCUMID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU16__DECRECTST_CTRCUMID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU16__DECRECTST_CTRCUMID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU16__DECRECTST_CTRCUMID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU16__DECRECTST_CTRCUMID__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field allowChrgInActive */
/**
 * @defgroup pmu_top_regs_core_allowChrgInActive_field allowChrgInActive_field
 * @brief macros for field allowChrgInActive
 * @details If set, the Vstore->Vbat charging can take place also in active state
 * @{
 */
#define PMU_PMU16__ALLOWCHRGINACTIVE__SHIFT                                  17
#define PMU_PMU16__ALLOWCHRGINACTIVE__WIDTH                                   1
#define PMU_PMU16__ALLOWCHRGINACTIVE__MASK                          0x00020000U
#define PMU_PMU16__ALLOWCHRGINACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU16__ALLOWCHRGINACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU16__ALLOWCHRGINACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU16__ALLOWCHRGINACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU16__ALLOWCHRGINACTIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU16__ALLOWCHRGINACTIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU16__ALLOWCHRGINACTIVE__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ovr_ReqCanMustHarvb_zeromppt_ovr */
/**
 * @defgroup pmu_top_regs_core_ovr_ReqCanMustHarvb_zeromppt_ovr_field ovr_ReqCanMustHarvb_zeromppt_ovr_field
 * @brief macros for field ovr_ReqCanMustHarvb_zeromppt_ovr
 * @details override ovr_ReqCanMustHarvb_zeromppt
 * @{
 */
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__SHIFT                   18
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__WIDTH                    1
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__MASK           0x00040000U
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ovr_ReqCanMustHarvb_zeromppt_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ovr_ReqCanMustHarvb_zeromppt_ovr_val_field ovr_ReqCanMustHarvb_zeromppt_ovr_val_field
 * @brief macros for field ovr_ReqCanMustHarvb_zeromppt_ovr_val
 * @details override ovr_ReqCanMustHarvb_zeromppt val0: When the zerompptref is high, it forces can/mustharv requests to zero1: zerompptref has no effect on an/mustharv requests
 * @{
 */
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__SHIFT               19
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__WIDTH                1
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__MASK       0x00080000U
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU16__OVR_REQCANMUSTHARVB_ZEROMPPT_OVR_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field ovr_ReqHarvb_increcst_ovr */
/**
 * @defgroup pmu_top_regs_core_ovr_ReqHarvb_increcst_ovr_field ovr_ReqHarvb_increcst_ovr_field
 * @brief macros for field ovr_ReqHarvb_increcst_ovr
 * @details override ovr_ReqCanMustHarvb_increctst
 * @{
 */
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__SHIFT                          20
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__WIDTH                           1
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__MASK                  0x00100000U
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU16__OVR_REQHARVB_INCRECST_OVR__RESET_VALUE           0x00000000U
/** @} */

/* macros for field ovr_ReqHarvb_increctst_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ovr_ReqHarvb_increctst_ovr_val_field ovr_ReqHarvb_increctst_ovr_val_field
 * @brief macros for field ovr_ReqHarvb_increctst_ovr_val
 * @details override ovr_ReqCanMustHarvb_increctst val0: When the chpuhswoff_increctstb is low, it forces can/mustharv requests to zero1: chpuhswoff_increctstb has no effect on an/mustharv requests
 * @{
 */
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__SHIFT                     21
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__WIDTH                      1
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__MASK             0x00200000U
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU16__OVR_REQHARVB_INCRECTST_OVR_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ctr_ref_vbatreg_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_vbatreg_ovr_field ctr_ref_vbatreg_ovr_field
 * @brief macros for field ctr_ref_vbatreg_ovr
 * @details override ctr_ref_vbatreg level
 * @{
 */
#define PMU_PMU16__CTR_REF_VBATREG_OVR__SHIFT                                22
#define PMU_PMU16__CTR_REF_VBATREG_OVR__WIDTH                                 1
#define PMU_PMU16__CTR_REF_VBATREG_OVR__MASK                        0x00400000U
#define PMU_PMU16__CTR_REF_VBATREG_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU16__CTR_REF_VBATREG_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU16__CTR_REF_VBATREG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU16__CTR_REF_VBATREG_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU16__CTR_REF_VBATREG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU16__CTR_REF_VBATREG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU16__CTR_REF_VBATREG_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ctr_ref_vbatreg_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_vbatreg_ovr_val_field ctr_ref_vbatreg_ovr_val_field
 * @brief macros for field ctr_ref_vbatreg_ovr_val
 * @details override value for VBATLI to VBATT LDO output level, 3.0V to 3.3V in 0.1V steps
 * @{
 */
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__SHIFT                            23
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__WIDTH                             2
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__MASK                    0x01800000U
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01800000U) >> 23)
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x01800000U)
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01800000U) | (((uint32_t)(src) <<\
                    23) & 0x01800000U)
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x01800000U)))
#define PMU_PMU16__CTR_REF_VBATREG_OVR_VAL__RESET_VALUE             0x00000001U
/** @} */

/* macros for field ctr_refcalpmuadc */
/**
 * @defgroup pmu_top_regs_core_ctr_refcalpmuadc_field ctr_refcalpmuadc_field
 * @brief macros for field ctr_refcalpmuadc
 * @details calibrate the output of the pmuadc reference buffer
 * @{
 */
#define PMU_PMU16__CTR_REFCALPMUADC__SHIFT                                   25
#define PMU_PMU16__CTR_REFCALPMUADC__WIDTH                                    4
#define PMU_PMU16__CTR_REFCALPMUADC__MASK                           0x1e000000U
#define PMU_PMU16__CTR_REFCALPMUADC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1e000000U) >> 25)
#define PMU_PMU16__CTR_REFCALPMUADC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x1e000000U)
#define PMU_PMU16__CTR_REFCALPMUADC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1e000000U) | (((uint32_t)(src) <<\
                    25) & 0x1e000000U)
#define PMU_PMU16__CTR_REFCALPMUADC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x1e000000U)))
#define PMU_PMU16__CTR_REFCALPMUADC__RESET_VALUE                    0x00000007U
/** @} */

/* macros for field pmuadc_enrefbuf */
/**
 * @defgroup pmu_top_regs_core_pmuadc_enrefbuf_field pmuadc_enrefbuf_field
 * @brief macros for field pmuadc_enrefbuf
 * @details enable the pmuadc reference buffer
 * @{
 */
#define PMU_PMU16__PMUADC_ENREFBUF__SHIFT                                    29
#define PMU_PMU16__PMUADC_ENREFBUF__WIDTH                                     1
#define PMU_PMU16__PMUADC_ENREFBUF__MASK                            0x20000000U
#define PMU_PMU16__PMUADC_ENREFBUF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU16__PMUADC_ENREFBUF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU16__PMUADC_ENREFBUF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU16__PMUADC_ENREFBUF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU16__PMUADC_ENREFBUF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU16__PMUADC_ENREFBUF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU16__PMUADC_ENREFBUF__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field pmuadc_byrefbuf */
/**
 * @defgroup pmu_top_regs_core_pmuadc_byrefbuf_field pmuadc_byrefbuf_field
 * @brief macros for field pmuadc_byrefbuf
 * @details bypass the pmuadc reference buffer
 * @{
 */
#define PMU_PMU16__PMUADC_BYREFBUF__SHIFT                                    30
#define PMU_PMU16__PMUADC_BYREFBUF__WIDTH                                     1
#define PMU_PMU16__PMUADC_BYREFBUF__MASK                            0x40000000U
#define PMU_PMU16__PMUADC_BYREFBUF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU16__PMUADC_BYREFBUF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU16__PMUADC_BYREFBUF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU16__PMUADC_BYREFBUF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU16__PMUADC_BYREFBUF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU16__PMUADC_BYREFBUF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU16__PMUADC_BYREFBUF__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field chargeBatt */
/**
 * @defgroup pmu_top_regs_core_chargeBatt_field chargeBatt_field
 * @brief macros for field chargeBatt
 * @details Enable the VSTO->VBAT mode. Also unmasks the pmuadc indicator to set buck, boost for VSTO->VBAT.
 * @{
 */
#define PMU_PMU16__CHARGEBATT__SHIFT                                         31
#define PMU_PMU16__CHARGEBATT__WIDTH                                          1
#define PMU_PMU16__CHARGEBATT__MASK                                 0x80000000U
#define PMU_PMU16__CHARGEBATT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU16__CHARGEBATT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU16__CHARGEBATT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU16__CHARGEBATT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU16__CHARGEBATT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU16__CHARGEBATT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU16__CHARGEBATT__RESET_VALUE                          0x00000000U
/** @} */
#define PMU_PMU16__TYPE                                                uint32_t
#define PMU_PMU16__READ                                             0xffffffffU
#define PMU_PMU16__WRITE                                            0xffffffffU
#define PMU_PMU16__PRESERVED                                        0x00000000U
#define PMU_PMU16__RESET_VALUE                                      0x4e808039U

#endif /* __PMU_PMU16_MACRO__ */

/** @} end of pmu16 */

/* macros for BlueprintGlobalNameSpace::PMU_chrg_ctrl */
/**
 * @defgroup pmu_top_regs_core_chrg_ctrl chrg_ctrl
 * @brief Charger control bits definitions.
 * @{
 */
#ifndef __PMU_CHRG_CTRL_MACRO__
#define __PMU_CHRG_CTRL_MACRO__

/* macros for field disable_chrg_ovr */
/**
 * @defgroup pmu_top_regs_core_disable_chrg_ovr_field disable_chrg_ovr_field
 * @brief macros for field disable_chrg_ovr
 * @details force disable all charging controls
 * @{
 */
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__SHIFT                                0
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__WIDTH                                1
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__MASK                       0x00000001U
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_CHRG_CTRL__DISABLE_CHRG_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field chrg_timer_start */
/**
 * @defgroup pmu_top_regs_core_chrg_timer_start_field chrg_timer_start_field
 * @brief macros for field chrg_timer_start
 * @details Set high for at least 50us and then clear to restart timeout counterThis will start charging and make the configuration settings below take effectSW needs to toggle this bit before charger timeout countdown timer expires to keep charging going
 * @{
 */
#define PMU_CHRG_CTRL__CHRG_TIMER_START__SHIFT                                1
#define PMU_CHRG_CTRL__CHRG_TIMER_START__WIDTH                                1
#define PMU_CHRG_CTRL__CHRG_TIMER_START__MASK                       0x00000002U
#define PMU_CHRG_CTRL__CHRG_TIMER_START__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_CHRG_CTRL__CHRG_TIMER_START__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_CHRG_CTRL__CHRG_TIMER_START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_CHRG_CTRL__CHRG_TIMER_START__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_CHRG_CTRL__CHRG_TIMER_START__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_CHRG_CTRL__CHRG_TIMER_START__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_CHRG_CTRL__CHRG_TIMER_START__RESET_VALUE                0x00000000U
/** @} */

/* macros for field chrg_timeout */
/**
 * @defgroup pmu_top_regs_core_chrg_timeout_field chrg_timeout_field
 * @brief macros for field chrg_timeout
 * @details Charger timeout countdown timer value in seconds, should be set longer than any battery measurement/charger settings update rate
 * @{
 */
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__SHIFT                                    2
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__WIDTH                                   11
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__MASK                           0x00001ffcU
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001ffcU) >> 2)
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00001ffcU)
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001ffcU) | (((uint32_t)(src) <<\
                    2) & 0x00001ffcU)
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00001ffcU)))
#define PMU_CHRG_CTRL__CHRG_TIMEOUT__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_chrg_curr */
/**
 * @defgroup pmu_top_regs_core_en_chrg_curr_field en_chrg_curr_field
 * @brief macros for field en_chrg_curr
 * @details Enable charger current source from VSTORE->VBATT
 * @{
 */
#define PMU_CHRG_CTRL__EN_CHRG_CURR__SHIFT                                   13
#define PMU_CHRG_CTRL__EN_CHRG_CURR__WIDTH                                    1
#define PMU_CHRG_CTRL__EN_CHRG_CURR__MASK                           0x00002000U
#define PMU_CHRG_CTRL__EN_CHRG_CURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_CHRG_CTRL__EN_CHRG_CURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_CHRG_CTRL__EN_CHRG_CURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_CHRG_CTRL__EN_CHRG_CURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_CHRG_CTRL__EN_CHRG_CURR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_CHRG_CTRL__EN_CHRG_CURR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_CHRG_CTRL__EN_CHRG_CURR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ctr_chrgcurr */
/**
 * @defgroup pmu_top_regs_core_ctr_chrgcurr_field ctr_chrgcurr_field
 * @brief macros for field ctr_chrgcurr
 * @details Charge current source value, approx 60uA to 15mA in 60uA steps for VSTORE->VBATT path
 * @{
 */
#define PMU_CHRG_CTRL__CTR_CHRGCURR__SHIFT                                   14
#define PMU_CHRG_CTRL__CTR_CHRGCURR__WIDTH                                    8
#define PMU_CHRG_CTRL__CTR_CHRGCURR__MASK                           0x003fc000U
#define PMU_CHRG_CTRL__CTR_CHRGCURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003fc000U) >> 14)
#define PMU_CHRG_CTRL__CTR_CHRGCURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x003fc000U)
#define PMU_CHRG_CTRL__CTR_CHRGCURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fc000U) | (((uint32_t)(src) <<\
                    14) & 0x003fc000U)
#define PMU_CHRG_CTRL__CTR_CHRGCURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x003fc000U)))
#define PMU_CHRG_CTRL__CTR_CHRGCURR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_VstoVbat */
/**
 * @defgroup pmu_top_regs_core_en_VstoVbat_field en_VstoVbat_field
 * @brief macros for field en_VstoVbat
 * @details Enable VSTORE->VBATT charger current source path
 * @{
 */
#define PMU_CHRG_CTRL__EN_VSTOVBAT__SHIFT                                    22
#define PMU_CHRG_CTRL__EN_VSTOVBAT__WIDTH                                     1
#define PMU_CHRG_CTRL__EN_VSTOVBAT__MASK                            0x00400000U
#define PMU_CHRG_CTRL__EN_VSTOVBAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_CHRG_CTRL__EN_VSTOVBAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_CHRG_CTRL__EN_VSTOVBAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_CHRG_CTRL__EN_VSTOVBAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_CHRG_CTRL__EN_VSTOVBAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_CHRG_CTRL__EN_VSTOVBAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_CHRG_CTRL__EN_VSTOVBAT__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field unused */
/**
 * @defgroup pmu_top_regs_core_unused_field unused_field
 * @brief macros for field unused
 * @details Unused
 * @{
 */
#define PMU_CHRG_CTRL__UNUSED__SHIFT                                         23
#define PMU_CHRG_CTRL__UNUSED__WIDTH                                          1
#define PMU_CHRG_CTRL__UNUSED__MASK                                 0x00800000U
#define PMU_CHRG_CTRL__UNUSED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_CHRG_CTRL__UNUSED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_CHRG_CTRL__UNUSED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_CHRG_CTRL__UNUSED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_CHRG_CTRL__UNUSED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_CHRG_CTRL__UNUSED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_CHRG_CTRL__UNUSED__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field enampchrg */
/**
 * @defgroup pmu_top_regs_core_enampchrg_field enampchrg_field
 * @brief macros for field enampchrg
 * @details Unused
 * @{
 */
#define PMU_CHRG_CTRL__ENAMPCHRG__SHIFT                                      24
#define PMU_CHRG_CTRL__ENAMPCHRG__WIDTH                                       1
#define PMU_CHRG_CTRL__ENAMPCHRG__MASK                              0x01000000U
#define PMU_CHRG_CTRL__ENAMPCHRG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_CHRG_CTRL__ENAMPCHRG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_CHRG_CTRL__ENAMPCHRG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_CHRG_CTRL__ENAMPCHRG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_CHRG_CTRL__ENAMPCHRG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_CHRG_CTRL__ENAMPCHRG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_CHRG_CTRL__ENAMPCHRG__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field bypvstovbatli */
/**
 * @defgroup pmu_top_regs_core_bypvstovbatli_field bypvstovbatli_field
 * @brief macros for field bypvstovbatli
 * @details Short VSTORE to VBATLI, should only be enabled if VBATLI is within OV and UV ranges
 * @{
 */
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__SHIFT                                  25
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__WIDTH                                   1
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__MASK                          0x02000000U
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_CHRG_CTRL__BYPVSTOVBATLI__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ctr_chrgpmosbyp */
/**
 * @defgroup pmu_top_regs_core_ctr_chrgpmosbyp_field ctr_chrgpmosbyp_field
 * @brief macros for field ctr_chrgpmosbyp
 * @details Short VSTORE to VBATT and bypass charger current source
 * @{
 */
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__SHIFT                                26
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__WIDTH                                 1
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__MASK                        0x04000000U
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_CHRG_CTRL__CTR_CHRGPMOSBYP__RESET_VALUE                 0x00000000U
/** @} */
#define PMU_CHRG_CTRL__TYPE                                            uint32_t
#define PMU_CHRG_CTRL__READ                                         0x07ffffffU
#define PMU_CHRG_CTRL__WRITE                                        0x07ffffffU
#define PMU_CHRG_CTRL__PRESERVED                                    0x00000000U
#define PMU_CHRG_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PMU_CHRG_CTRL_MACRO__ */

/** @} end of chrg_ctrl */

/* macros for BlueprintGlobalNameSpace::PMU_chrg_ctrl2 */
/**
 * @defgroup pmu_top_regs_core_chrg_ctrl2 chrg_ctrl2
 * @brief More charger control bits definitions.
 * @{
 */
#ifndef __PMU_CHRG_CTRL2_MACRO__
#define __PMU_CHRG_CTRL2_MACRO__

/* macros for field ctr_VrefstoGoodToChrg */
/**
 * @defgroup pmu_top_regs_core_ctr_VrefstoGoodToChrg_field ctr_VrefstoGoodToChrg_field
 * @brief macros for field ctr_VrefstoGoodToChrg
 * @details VSTORE level above which to enable external charge pump clock in pmuadc units, = round[(vstore voltage - 600mv)/25mv]There will be another 100mV rising hysteresis included in the comparisonDefault setting for VSTORE = 3.0V with 100mV hysteresis = charge pump turns on at 3.1V and shuts off at 3.0V
 * @{
 */
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__SHIFT                          0
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__WIDTH                          7
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__MASK                 0x0000007fU
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define PMU_CHRG_CTRL2__CTR_VREFSTOGOODTOCHRG__RESET_VALUE          0x00000060U
/** @} */

/* macros for field en_clk_cp */
/**
 * @defgroup pmu_top_regs_core_en_clk_cp_field en_clk_cp_field
 * @brief macros for field en_clk_cp
 * @details Enable clock to drive external charge pump, this clock needs to be separately brought out to a GPIO through pin mux settingClock only actually runs if VSTORE is above ctr_VrefstoGoodToChrg level when this bit is enabled
 * @{
 */
#define PMU_CHRG_CTRL2__EN_CLK_CP__SHIFT                                      7
#define PMU_CHRG_CTRL2__EN_CLK_CP__WIDTH                                      1
#define PMU_CHRG_CTRL2__EN_CLK_CP__MASK                             0x00000080U
#define PMU_CHRG_CTRL2__EN_CLK_CP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PMU_CHRG_CTRL2__EN_CLK_CP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PMU_CHRG_CTRL2__EN_CLK_CP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_CHRG_CTRL2__EN_CLK_CP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_CHRG_CTRL2__EN_CLK_CP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_CHRG_CTRL2__EN_CLK_CP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_CHRG_CTRL2__EN_CLK_CP__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field unused */
/**
 * @defgroup pmu_top_regs_core_unused_field unused_field
 * @brief macros for field unused
 * @details unused, pmu_spares[5:0]
 * @{
 */
#define PMU_CHRG_CTRL2__UNUSED__SHIFT                                         8
#define PMU_CHRG_CTRL2__UNUSED__WIDTH                                         6
#define PMU_CHRG_CTRL2__UNUSED__MASK                                0x00003f00U
#define PMU_CHRG_CTRL2__UNUSED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define PMU_CHRG_CTRL2__UNUSED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define PMU_CHRG_CTRL2__UNUSED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define PMU_CHRG_CTRL2__UNUSED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))
#define PMU_CHRG_CTRL2__UNUSED__RESET_VALUE                         0x00000000U
/** @} */
#define PMU_CHRG_CTRL2__TYPE                                           uint32_t
#define PMU_CHRG_CTRL2__READ                                        0x00003fffU
#define PMU_CHRG_CTRL2__WRITE                                       0x00003fffU
#define PMU_CHRG_CTRL2__PRESERVED                                   0x00000000U
#define PMU_CHRG_CTRL2__RESET_VALUE                                 0x00000060U

#endif /* __PMU_CHRG_CTRL2_MACRO__ */

/** @} end of chrg_ctrl2 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu17 */
/**
 * @defgroup pmu_top_regs_core_pmu17 pmu17
 * @brief spares definitions.
 * @{
 */
#ifndef __PMU_PMU17_MACRO__
#define __PMU_PMU17_MACRO__

/* macros for field off_trans_wait_reg */
/**
 * @defgroup pmu_top_regs_core_off_trans_wait_reg_field off_trans_wait_reg_field
 * @brief macros for field off_trans_wait_reg
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__OFF_TRANS_WAIT_REG__SHIFT                                  0
#define PMU_PMU17__OFF_TRANS_WAIT_REG__WIDTH                                  7
#define PMU_PMU17__OFF_TRANS_WAIT_REG__MASK                         0x0000007fU
#define PMU_PMU17__OFF_TRANS_WAIT_REG__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define PMU_PMU17__OFF_TRANS_WAIT_REG__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define PMU_PMU17__OFF_TRANS_WAIT_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define PMU_PMU17__OFF_TRANS_WAIT_REG__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define PMU_PMU17__OFF_TRANS_WAIT_REG__RESET_VALUE                  0x0000006eU
/** @} */

/* macros for field en_refgen_pre_ovr */
/**
 * @defgroup pmu_top_regs_core_en_refgen_pre_ovr_field en_refgen_pre_ovr_field
 * @brief macros for field en_refgen_pre_ovr
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__EN_REFGEN_PRE_OVR__SHIFT                                   7
#define PMU_PMU17__EN_REFGEN_PRE_OVR__WIDTH                                   1
#define PMU_PMU17__EN_REFGEN_PRE_OVR__MASK                          0x00000080U
#define PMU_PMU17__EN_REFGEN_PRE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PMU_PMU17__EN_REFGEN_PRE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PMU_PMU17__EN_REFGEN_PRE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_PMU17__EN_REFGEN_PRE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_PMU17__EN_REFGEN_PRE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU17__EN_REFGEN_PRE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU17__EN_REFGEN_PRE_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field en_refgen_pre_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_refgen_pre_ovr_val_field en_refgen_pre_ovr_val_field
 * @brief macros for field en_refgen_pre_ovr_val
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__SHIFT                               8
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__WIDTH                               1
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__MASK                      0x00000100U
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU17__EN_REFGEN_PRE_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field harv1_rect_en_ovr */
/**
 * @defgroup pmu_top_regs_core_harv1_rect_en_ovr_field harv1_rect_en_ovr_field
 * @brief macros for field harv1_rect_en_ovr
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__HARV1_RECT_EN_OVR__SHIFT                                   9
#define PMU_PMU17__HARV1_RECT_EN_OVR__WIDTH                                   1
#define PMU_PMU17__HARV1_RECT_EN_OVR__MASK                          0x00000200U
#define PMU_PMU17__HARV1_RECT_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU17__HARV1_RECT_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU17__HARV1_RECT_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU17__HARV1_RECT_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU17__HARV1_RECT_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU17__HARV1_RECT_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU17__HARV1_RECT_EN_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field harv1_rect_en_ovr_val */
/**
 * @defgroup pmu_top_regs_core_harv1_rect_en_ovr_val_field harv1_rect_en_ovr_val_field
 * @brief macros for field harv1_rect_en_ovr_val
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__SHIFT                              10
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__WIDTH                               1
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__MASK                      0x00000400U
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU17__HARV1_RECT_EN_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ctr_refextend_out_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_refextend_out_ovr_field ctr_refextend_out_ovr_field
 * @brief macros for field ctr_refextend_out_ovr
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__SHIFT                              11
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__WIDTH                               1
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__MASK                      0x00000800U
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ctr_refextend_out_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_refextend_out_ovr_val_field ctr_refextend_out_ovr_val_field
 * @brief macros for field ctr_refextend_out_ovr_val
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__SHIFT                          12
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__WIDTH                           1
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__MASK                  0x00001000U
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU17__CTR_REFEXTEND_OUT_OVR_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field force_isolate_b_pre */
/**
 * @defgroup pmu_top_regs_core_force_isolate_b_pre_field force_isolate_b_pre_field
 * @brief macros for field force_isolate_b_pre
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__SHIFT                                13
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__WIDTH                                 1
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__MASK                        0x00002000U
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU17__FORCE_ISOLATE_B_PRE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field wake_only_if_enough_energy */
/**
 * @defgroup pmu_top_regs_core_wake_only_if_enough_energy_field wake_only_if_enough_energy_field
 * @brief macros for field wake_only_if_enough_energy
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__SHIFT                         14
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__WIDTH                          1
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__MASK                 0x00004000U
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU17__WAKE_ONLY_IF_ENOUGH_ENERGY__RESET_VALUE          0x00000000U
/** @} */

/* macros for field force_energyGood_out1 */
/**
 * @defgroup pmu_top_regs_core_force_energyGood_out1_field force_energyGood_out1_field
 * @brief macros for field force_energyGood_out1
 * @details spare bits6..0 off_trans_wait_reg7 override en_refgen_pre8 override val for en_refgen_pre9 override Harvest 1 rectifier enable10 override val for Harvest 1 resctifier enable11 override ctr_refextend_out12 override val for ctr_refextend_out13 override for isolate_b_pre, not used on paris14 override for wake_only_if_enough_energy15 override for energyGood_out1, not used in paris
 * @{
 */
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__SHIFT                              15
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__WIDTH                               1
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__MASK                      0x00008000U
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU17__FORCE_ENERGYGOOD_OUT1__RESET_VALUE               0x00000000U
/** @} */

/* macros for field zerompptref_forceb */
/**
 * @defgroup pmu_top_regs_core_zerompptref_forceb_field zerompptref_forceb_field
 * @brief macros for field zerompptref_forceb
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__ZEROMPPTREF_FORCEB__SHIFT                                 16
#define PMU_PMU17__ZEROMPPTREF_FORCEB__WIDTH                                  1
#define PMU_PMU17__ZEROMPPTREF_FORCEB__MASK                         0x00010000U
#define PMU_PMU17__ZEROMPPTREF_FORCEB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU17__ZEROMPPTREF_FORCEB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU17__ZEROMPPTREF_FORCEB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU17__ZEROMPPTREF_FORCEB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU17__ZEROMPPTREF_FORCEB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU17__ZEROMPPTREF_FORCEB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU17__ZEROMPPTREF_FORCEB__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field ctr_maxref1v3_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_maxref1v3_ovr_field ctr_maxref1v3_ovr_field
 * @brief macros for field ctr_maxref1v3_ovr
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__CTR_MAXREF1V3_OVR__SHIFT                                  17
#define PMU_PMU17__CTR_MAXREF1V3_OVR__WIDTH                                   1
#define PMU_PMU17__CTR_MAXREF1V3_OVR__MASK                          0x00020000U
#define PMU_PMU17__CTR_MAXREF1V3_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU17__CTR_MAXREF1V3_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU17__CTR_MAXREF1V3_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU17__CTR_MAXREF1V3_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU17__CTR_MAXREF1V3_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU17__CTR_MAXREF1V3_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU17__CTR_MAXREF1V3_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ctr_maxref1v3_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_maxref1v3_ovr_val_field ctr_maxref1v3_ovr_val_field
 * @brief macros for field ctr_maxref1v3_ovr_val
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__SHIFT                              18
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__WIDTH                               1
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__MASK                      0x00040000U
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU17__CTR_MAXREF1V3_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field en_refgenfast_ovr */
/**
 * @defgroup pmu_top_regs_core_en_refgenfast_ovr_field en_refgenfast_ovr_field
 * @brief macros for field en_refgenfast_ovr
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__EN_REFGENFAST_OVR__SHIFT                                  19
#define PMU_PMU17__EN_REFGENFAST_OVR__WIDTH                                   1
#define PMU_PMU17__EN_REFGENFAST_OVR__MASK                          0x00080000U
#define PMU_PMU17__EN_REFGENFAST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU17__EN_REFGENFAST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU17__EN_REFGENFAST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU17__EN_REFGENFAST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU17__EN_REFGENFAST_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU17__EN_REFGENFAST_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU17__EN_REFGENFAST_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field en_refgenfast_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_refgenfast_ovr_val_field en_refgenfast_ovr_val_field
 * @brief macros for field en_refgenfast_ovr_val
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__SHIFT                              20
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__WIDTH                               1
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__MASK                      0x00100000U
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU17__EN_REFGENFAST_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field mppt_debug */
/**
 * @defgroup pmu_top_regs_core_mppt_debug_field mppt_debug_field
 * @brief macros for field mppt_debug
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__MPPT_DEBUG__SHIFT                                         21
#define PMU_PMU17__MPPT_DEBUG__WIDTH                                          2
#define PMU_PMU17__MPPT_DEBUG__MASK                                 0x00600000U
#define PMU_PMU17__MPPT_DEBUG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define PMU_PMU17__MPPT_DEBUG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define PMU_PMU17__MPPT_DEBUG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define PMU_PMU17__MPPT_DEBUG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define PMU_PMU17__MPPT_DEBUG__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field mpptStart_ovr */
/**
 * @defgroup pmu_top_regs_core_mpptStart_ovr_field mpptStart_ovr_field
 * @brief macros for field mpptStart_ovr
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__MPPTSTART_OVR__SHIFT                                      23
#define PMU_PMU17__MPPTSTART_OVR__WIDTH                                       1
#define PMU_PMU17__MPPTSTART_OVR__MASK                              0x00800000U
#define PMU_PMU17__MPPTSTART_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU17__MPPTSTART_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU17__MPPTSTART_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU17__MPPTSTART_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU17__MPPTSTART_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU17__MPPTSTART_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU17__MPPTSTART_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mpptStart_ovr_val */
/**
 * @defgroup pmu_top_regs_core_mpptStart_ovr_val_field mpptStart_ovr_val_field
 * @brief macros for field mpptStart_ovr_val
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__MPPTSTART_OVR_VAL__SHIFT                                  24
#define PMU_PMU17__MPPTSTART_OVR_VAL__WIDTH                                   1
#define PMU_PMU17__MPPTSTART_OVR_VAL__MASK                          0x01000000U
#define PMU_PMU17__MPPTSTART_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU17__MPPTSTART_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU17__MPPTSTART_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU17__MPPTSTART_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU17__MPPTSTART_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU17__MPPTSTART_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU17__MPPTSTART_OVR_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ctr_cuFast_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_cuFast_ovr_field ctr_cuFast_ovr_field
 * @brief macros for field ctr_cuFast_ovr
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__CTR_CUFAST_OVR__SHIFT                                     25
#define PMU_PMU17__CTR_CUFAST_OVR__WIDTH                                      1
#define PMU_PMU17__CTR_CUFAST_OVR__MASK                             0x02000000U
#define PMU_PMU17__CTR_CUFAST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU17__CTR_CUFAST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU17__CTR_CUFAST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU17__CTR_CUFAST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU17__CTR_CUFAST_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU17__CTR_CUFAST_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU17__CTR_CUFAST_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field ctr_cuFast_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_cuFast_ovr_val_field ctr_cuFast_ovr_val_field
 * @brief macros for field ctr_cuFast_ovr_val
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__SHIFT                                 26
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__WIDTH                                  2
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__MASK                         0x0c000000U
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define PMU_PMU17__CTR_CUFAST_OVR_VAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field sw_mpptEvent */
/**
 * @defgroup pmu_top_regs_core_sw_mpptEvent_field sw_mpptEvent_field
 * @brief macros for field sw_mpptEvent
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__SW_MPPTEVENT__SHIFT                                       28
#define PMU_PMU17__SW_MPPTEVENT__WIDTH                                        1
#define PMU_PMU17__SW_MPPTEVENT__MASK                               0x10000000U
#define PMU_PMU17__SW_MPPTEVENT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU17__SW_MPPTEVENT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU17__SW_MPPTEVENT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU17__SW_MPPTEVENT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU17__SW_MPPTEVENT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU17__SW_MPPTEVENT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU17__SW_MPPTEVENT__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field new_sparebits */
/**
 * @defgroup pmu_top_regs_core_new_sparebits_field new_sparebits_field
 * @brief macros for field new_sparebits
 * @details new sparebits0 zerompptref_forceb1 override ctr_maxref1v32 override val for ctr_maxref1v33 override en_refgenfast4 override val for en_refgenfast6:5 00 = mpptDone, 01 = mpptStart, 10 = zerompptref, 11 = mppt_freeze7 mpptStart_ovr8 mpptStart_ovr_val9 ctr_cuFast_ovr11:10 ctr_cuFast_ovr_val12 Software_mpptEvent
 * @{
 */
#define PMU_PMU17__NEW_SPAREBITS__SHIFT                                      29
#define PMU_PMU17__NEW_SPAREBITS__WIDTH                                       3
#define PMU_PMU17__NEW_SPAREBITS__MASK                              0xe0000000U
#define PMU_PMU17__NEW_SPAREBITS__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define PMU_PMU17__NEW_SPAREBITS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define PMU_PMU17__NEW_SPAREBITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define PMU_PMU17__NEW_SPAREBITS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
#define PMU_PMU17__NEW_SPAREBITS__RESET_VALUE                       0x00000000U
/** @} */
#define PMU_PMU17__TYPE                                                uint32_t
#define PMU_PMU17__READ                                             0xffffffffU
#define PMU_PMU17__WRITE                                            0xffffffffU
#define PMU_PMU17__PRESERVED                                        0x00000000U
#define PMU_PMU17__RESET_VALUE                                      0x0000006eU

#endif /* __PMU_PMU17_MACRO__ */

/** @} end of pmu17 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu18 */
/**
 * @defgroup pmu_top_regs_core_pmu18 pmu18
 * @brief more mppt regs definitions.
 * @{
 */
#ifndef __PMU_PMU18_MACRO__
#define __PMU_PMU18_MACRO__

/* macros for field mpptEventCount_max */
/**
 * @defgroup pmu_top_regs_core_mpptEventCount_max_field mpptEventCount_max_field
 * @brief macros for field mpptEventCount_max
 * @{
 */
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__SHIFT                                  0
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__WIDTH                                 11
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__MASK                         0x000007ffU
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000007ffU)))
#define PMU_PMU18__MPPTEVENTCOUNT_MAX__RESET_VALUE                  0x00000320U
/** @} */

/* macros for field maxMpptPeriods_sel */
/**
 * @defgroup pmu_top_regs_core_maxMpptPeriods_sel_field maxMpptPeriods_sel_field
 * @brief macros for field maxMpptPeriods_sel
 * @{
 */
#define PMU_PMU18__MAXMPPTPERIODS_SEL__SHIFT                                 11
#define PMU_PMU18__MAXMPPTPERIODS_SEL__WIDTH                                  2
#define PMU_PMU18__MAXMPPTPERIODS_SEL__MASK                         0x00001800U
#define PMU_PMU18__MAXMPPTPERIODS_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define PMU_PMU18__MAXMPPTPERIODS_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define PMU_PMU18__MAXMPPTPERIODS_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define PMU_PMU18__MAXMPPTPERIODS_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define PMU_PMU18__MAXMPPTPERIODS_SEL__RESET_VALUE                  0x00000001U
/** @} */
#define PMU_PMU18__TYPE                                                uint32_t
#define PMU_PMU18__READ                                             0x00001fffU
#define PMU_PMU18__WRITE                                            0x00001fffU
#define PMU_PMU18__PRESERVED                                        0x00000000U
#define PMU_PMU18__RESET_VALUE                                      0x00000b20U

#endif /* __PMU_PMU18_MACRO__ */

/** @} end of pmu18 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb0 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb0 pmu_rb0
 * @brief readback registers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB0_MACRO__
#define __PMU_PMU_RB0_MACRO__

/* macros for field timer_out_lsb */
/**
 * @defgroup pmu_top_regs_core_timer_out_lsb_field timer_out_lsb_field
 * @brief macros for field timer_out_lsb
 * @details 32 lsb bits of timer_(# of 32KHz clock cycles)
 * @{
 */
#define PMU_PMU_RB0__TIMER_OUT_LSB__SHIFT                                     0
#define PMU_PMU_RB0__TIMER_OUT_LSB__WIDTH                                    32
#define PMU_PMU_RB0__TIMER_OUT_LSB__MASK                            0xffffffffU
#define PMU_PMU_RB0__TIMER_OUT_LSB__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define PMU_PMU_RB0__TIMER_OUT_LSB__RESET_VALUE                     0x00000000U
/** @} */
#define PMU_PMU_RB0__TYPE                                              uint32_t
#define PMU_PMU_RB0__READ                                           0xffffffffU
#define PMU_PMU_RB0__PRESERVED                                      0x00000000U
#define PMU_PMU_RB0__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB0_MACRO__ */

/** @} end of pmu_rb0 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb1 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb1 pmu_rb1
 * @brief readback registers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB1_MACRO__
#define __PMU_PMU_RB1_MACRO__

/* macros for field timer_out_msb */
/**
 * @defgroup pmu_top_regs_core_timer_out_msb_field timer_out_msb_field
 * @brief macros for field timer_out_msb
 * @details 8 msb bits of timer_(# of 32KHz clock cycles)
 * @{
 */
#define PMU_PMU_RB1__TIMER_OUT_MSB__SHIFT                                     0
#define PMU_PMU_RB1__TIMER_OUT_MSB__WIDTH                                     8
#define PMU_PMU_RB1__TIMER_OUT_MSB__MASK                            0x000000ffU
#define PMU_PMU_RB1__TIMER_OUT_MSB__READ(src)   ((uint32_t)(src) & 0x000000ffU)
#define PMU_PMU_RB1__TIMER_OUT_MSB__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field wkup_det */
/**
 * @defgroup pmu_top_regs_core_wkup_det_field wkup_det_field
 * @brief macros for field wkup_det
 * @details determine how soc is waking up
 * @{
 */
#define PMU_PMU_RB1__WKUP_DET__SHIFT                                          8
#define PMU_PMU_RB1__WKUP_DET__WIDTH                                          3
#define PMU_PMU_RB1__WKUP_DET__MASK                                 0x00000700U
#define PMU_PMU_RB1__WKUP_DET__READ(src) (((uint32_t)(src) & 0x00000700U) >> 8)
#define PMU_PMU_RB1__WKUP_DET__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field pmu_state */
/**
 * @defgroup pmu_top_regs_core_pmu_state_field pmu_state_field
 * @brief macros for field pmu_state
 * @details readback pmu state
 * @{
 */
#define PMU_PMU_RB1__PMU_STATE__SHIFT                                        11
#define PMU_PMU_RB1__PMU_STATE__WIDTH                                         3
#define PMU_PMU_RB1__PMU_STATE__MASK                                0x00003800U
#define PMU_PMU_RB1__PMU_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define PMU_PMU_RB1__PMU_STATE__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field lpcomp_out */
/**
 * @defgroup pmu_top_regs_core_lpcomp_out_field lpcomp_out_field
 * @brief macros for field lpcomp_out
 * @details low power comparator output
 * @{
 */
#define PMU_PMU_RB1__LPCOMP_OUT__SHIFT                                       14
#define PMU_PMU_RB1__LPCOMP_OUT__WIDTH                                        1
#define PMU_PMU_RB1__LPCOMP_OUT__MASK                               0x00004000U
#define PMU_PMU_RB1__LPCOMP_OUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU_RB1__LPCOMP_OUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU_RB1__LPCOMP_OUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU_RB1__LPCOMP_OUT__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field enrc */
/**
 * @defgroup pmu_top_regs_core_enrc_field enrc_field
 * @brief macros for field enrc
 * @details readback for rc osc
 * @{
 */
#define PMU_PMU_RB1__ENRC__SHIFT                                             15
#define PMU_PMU_RB1__ENRC__WIDTH                                              1
#define PMU_PMU_RB1__ENRC__MASK                                     0x00008000U
#define PMU_PMU_RB1__ENRC__READ(src)    (((uint32_t)(src) & 0x00008000U) >> 15)
#define PMU_PMU_RB1__ENRC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU_RB1__ENRC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU_RB1__ENRC__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field enxtal */
/**
 * @defgroup pmu_top_regs_core_enxtal_field enxtal_field
 * @brief macros for field enxtal
 * @details readback for xtal osc
 * @{
 */
#define PMU_PMU_RB1__ENXTAL__SHIFT                                           16
#define PMU_PMU_RB1__ENXTAL__WIDTH                                            1
#define PMU_PMU_RB1__ENXTAL__MASK                                   0x00010000U
#define PMU_PMU_RB1__ENXTAL__READ(src)  (((uint32_t)(src) & 0x00010000U) >> 16)
#define PMU_PMU_RB1__ENXTAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU_RB1__ENXTAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU_RB1__ENXTAL__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field VstoreGoodtoTX */
/**
 * @defgroup pmu_top_regs_core_VstoreGoodtoTX_field VstoreGoodtoTX_field
 * @brief macros for field VstoreGoodtoTX
 * @details readback comp output
 * @{
 */
#define PMU_PMU_RB1__VSTOREGOODTOTX__SHIFT                                   17
#define PMU_PMU_RB1__VSTOREGOODTOTX__WIDTH                                    1
#define PMU_PMU_RB1__VSTOREGOODTOTX__MASK                           0x00020000U
#define PMU_PMU_RB1__VSTOREGOODTOTX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU_RB1__VSTOREGOODTOTX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU_RB1__VSTOREGOODTOTX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU_RB1__VSTOREGOODTOTX__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field BrownOutVbat */
/**
 * @defgroup pmu_top_regs_core_BrownOutVbat_field BrownOutVbat_field
 * @brief macros for field BrownOutVbat
 * @details readback comp output
 * @{
 */
#define PMU_PMU_RB1__BROWNOUTVBAT__SHIFT                                     18
#define PMU_PMU_RB1__BROWNOUTVBAT__WIDTH                                      1
#define PMU_PMU_RB1__BROWNOUTVBAT__MASK                             0x00040000U
#define PMU_PMU_RB1__BROWNOUTVBAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU_RB1__BROWNOUTVBAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU_RB1__BROWNOUTVBAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU_RB1__BROWNOUTVBAT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field VstoreGoodtoEner */
/**
 * @defgroup pmu_top_regs_core_VstoreGoodtoEner_field VstoreGoodtoEner_field
 * @brief macros for field VstoreGoodtoEner
 * @details readback comp output
 * @{
 */
#define PMU_PMU_RB1__VSTOREGOODTOENER__SHIFT                                 19
#define PMU_PMU_RB1__VSTOREGOODTOENER__WIDTH                                  1
#define PMU_PMU_RB1__VSTOREGOODTOENER__MASK                         0x00080000U
#define PMU_PMU_RB1__VSTOREGOODTOENER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU_RB1__VSTOREGOODTOENER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU_RB1__VSTOREGOODTOENER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU_RB1__VSTOREGOODTOENER__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field VstoreHarvStop */
/**
 * @defgroup pmu_top_regs_core_VstoreHarvStop_field VstoreHarvStop_field
 * @brief macros for field VstoreHarvStop
 * @details readback comp output
 * @{
 */
#define PMU_PMU_RB1__VSTOREHARVSTOP__SHIFT                                   20
#define PMU_PMU_RB1__VSTOREHARVSTOP__WIDTH                                    1
#define PMU_PMU_RB1__VSTOREHARVSTOP__MASK                           0x00100000U
#define PMU_PMU_RB1__VSTOREHARVSTOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PMU_PMU_RB1__VSTOREHARVSTOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU_RB1__VSTOREHARVSTOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU_RB1__VSTOREHARVSTOP__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field mpptstartvharv */
/**
 * @defgroup pmu_top_regs_core_mpptstartvharv_field mpptstartvharv_field
 * @brief macros for field mpptstartvharv
 * @details readback comp output
 * @{
 */
#define PMU_PMU_RB1__MPPTSTARTVHARV__SHIFT                                   21
#define PMU_PMU_RB1__MPPTSTARTVHARV__WIDTH                                    1
#define PMU_PMU_RB1__MPPTSTARTVHARV__MASK                           0x00200000U
#define PMU_PMU_RB1__MPPTSTARTVHARV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU_RB1__MPPTSTARTVHARV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU_RB1__MPPTSTARTVHARV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU_RB1__MPPTSTARTVHARV__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field reconfharvstage */
/**
 * @defgroup pmu_top_regs_core_reconfharvstage_field reconfharvstage_field
 * @brief macros for field reconfharvstage
 * @details readback comp output
 * @{
 */
#define PMU_PMU_RB1__RECONFHARVSTAGE__SHIFT                                  22
#define PMU_PMU_RB1__RECONFHARVSTAGE__WIDTH                                   1
#define PMU_PMU_RB1__RECONFHARVSTAGE__MASK                          0x00400000U
#define PMU_PMU_RB1__RECONFHARVSTAGE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU_RB1__RECONFHARVSTAGE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU_RB1__RECONFHARVSTAGE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU_RB1__RECONFHARVSTAGE__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field mppt_state */
/**
 * @defgroup pmu_top_regs_core_mppt_state_field mppt_state_field
 * @brief macros for field mppt_state
 * @details readback mppt state
 * @{
 */
#define PMU_PMU_RB1__MPPT_STATE__SHIFT                                       23
#define PMU_PMU_RB1__MPPT_STATE__WIDTH                                        4
#define PMU_PMU_RB1__MPPT_STATE__MASK                               0x07800000U
#define PMU_PMU_RB1__MPPT_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07800000U) >> 23)
#define PMU_PMU_RB1__MPPT_STATE__RESET_VALUE                        0x00000000U
/** @} */
#define PMU_PMU_RB1__TYPE                                              uint32_t
#define PMU_PMU_RB1__READ                                           0x07ffffffU
#define PMU_PMU_RB1__PRESERVED                                      0x00000000U
#define PMU_PMU_RB1__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB1_MACRO__ */

/** @} end of pmu_rb1 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb2 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb2 pmu_rb2
 * @brief readback registers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB2_MACRO__
#define __PMU_PMU_RB2_MACRO__

/* macros for field mppt_Pestimate */
/**
 * @defgroup pmu_top_regs_core_mppt_Pestimate_field mppt_Pestimate_field
 * @brief macros for field mppt_Pestimate
 * @details readback Pestimate value
 * @{
 */
#define PMU_PMU_RB2__MPPT_PESTIMATE__SHIFT                                    0
#define PMU_PMU_RB2__MPPT_PESTIMATE__WIDTH                                   20
#define PMU_PMU_RB2__MPPT_PESTIMATE__MASK                           0x000fffffU
#define PMU_PMU_RB2__MPPT_PESTIMATE__READ(src)  ((uint32_t)(src) & 0x000fffffU)
#define PMU_PMU_RB2__MPPT_PESTIMATE__RESET_VALUE                    0x00000000U
/** @} */
#define PMU_PMU_RB2__TYPE                                              uint32_t
#define PMU_PMU_RB2__READ                                           0x000fffffU
#define PMU_PMU_RB2__PRESERVED                                      0x00000000U
#define PMU_PMU_RB2__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB2_MACRO__ */

/** @} end of pmu_rb2 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb_mppt */
/**
 * @defgroup pmu_top_regs_core_pmu_rb_mppt pmu_rb_mppt
 * @brief readback registers for customers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB_MPPT_MACRO__
#define __PMU_PMU_RB_MPPT_MACRO__

/* macros for field mpptPeriodCount */
/**
 * @defgroup pmu_top_regs_core_mpptPeriodCount_field mpptPeriodCount_field
 * @brief macros for field mpptPeriodCount
 * @details readback mpptPeriodCount value
 * @{
 */
#define PMU_PMU_RB_MPPT__MPPTPERIODCOUNT__SHIFT                               0
#define PMU_PMU_RB_MPPT__MPPTPERIODCOUNT__WIDTH                               9
#define PMU_PMU_RB_MPPT__MPPTPERIODCOUNT__MASK                      0x000001ffU
#define PMU_PMU_RB_MPPT__MPPTPERIODCOUNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PMU_PMU_RB_MPPT__MPPTPERIODCOUNT__RESET_VALUE               0x00000000U
/** @} */

/* macros for field mpptEventCount */
/**
 * @defgroup pmu_top_regs_core_mpptEventCount_field mpptEventCount_field
 * @brief macros for field mpptEventCount
 * @details readback mpptEventCount value
 * @{
 */
#define PMU_PMU_RB_MPPT__MPPTEVENTCOUNT__SHIFT                                9
#define PMU_PMU_RB_MPPT__MPPTEVENTCOUNT__WIDTH                               10
#define PMU_PMU_RB_MPPT__MPPTEVENTCOUNT__MASK                       0x0007fe00U
#define PMU_PMU_RB_MPPT__MPPTEVENTCOUNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007fe00U) >> 9)
#define PMU_PMU_RB_MPPT__MPPTEVENTCOUNT__RESET_VALUE                0x00000000U
/** @} */

/* macros for field vstoreTooHigh_latch */
/**
 * @defgroup pmu_top_regs_core_vstoreTooHigh_latch_field vstoreTooHigh_latch_field
 * @brief macros for field vstoreTooHigh_latch
 * @details readback vstoreToohigh latched value
 * @{
 */
#define PMU_PMU_RB_MPPT__VSTORETOOHIGH_LATCH__SHIFT                          19
#define PMU_PMU_RB_MPPT__VSTORETOOHIGH_LATCH__WIDTH                           1
#define PMU_PMU_RB_MPPT__VSTORETOOHIGH_LATCH__MASK                  0x00080000U
#define PMU_PMU_RB_MPPT__VSTORETOOHIGH_LATCH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU_RB_MPPT__VSTORETOOHIGH_LATCH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU_RB_MPPT__VSTORETOOHIGH_LATCH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU_RB_MPPT__VSTORETOOHIGH_LATCH__RESET_VALUE           0x00000000U
/** @} */

/* macros for field ctr_mustharvfa */
/**
 * @defgroup pmu_top_regs_core_ctr_mustharvfa_field ctr_mustharvfa_field
 * @brief macros for field ctr_mustharvfa
 * @details readback vharv
 * @{
 */
#define PMU_PMU_RB_MPPT__CTR_MUSTHARVFA__SHIFT                               20
#define PMU_PMU_RB_MPPT__CTR_MUSTHARVFA__WIDTH                                4
#define PMU_PMU_RB_MPPT__CTR_MUSTHARVFA__MASK                       0x00f00000U
#define PMU_PMU_RB_MPPT__CTR_MUSTHARVFA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define PMU_PMU_RB_MPPT__CTR_MUSTHARVFA__RESET_VALUE                0x00000000U
/** @} */
#define PMU_PMU_RB_MPPT__TYPE                                          uint32_t
#define PMU_PMU_RB_MPPT__READ                                       0x00ffffffU
#define PMU_PMU_RB_MPPT__PRESERVED                                  0x00000000U
#define PMU_PMU_RB_MPPT__RESET_VALUE                                0x00000000U

#endif /* __PMU_PMU_RB_MPPT_MACRO__ */

/** @} end of pmu_rb_mppt */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb3 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb3 pmu_rb3
 * @brief internal OTP readback registers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB3_MACRO__
#define __PMU_PMU_RB3_MACRO__

/* macros for field otp_internal */
/**
 * @defgroup pmu_top_regs_core_otp_internal_field otp_internal_field
 * @brief macros for field otp_internal
 * @details {otp_internal_spare[3:0],otp_rect_ctune[2:0],otp_harv_disabled,otp_disable_chpu,otp_use_ldo,otp_nabg_trim[8:0]}
 * @{
 */
#define PMU_PMU_RB3__OTP_INTERNAL__SHIFT                                      0
#define PMU_PMU_RB3__OTP_INTERNAL__WIDTH                                     19
#define PMU_PMU_RB3__OTP_INTERNAL__MASK                             0x0007ffffU
#define PMU_PMU_RB3__OTP_INTERNAL__READ(src)    ((uint32_t)(src) & 0x0007ffffU)
#define PMU_PMU_RB3__OTP_INTERNAL__RESET_VALUE                      0x00000000U
/** @} */
#define PMU_PMU_RB3__TYPE                                              uint32_t
#define PMU_PMU_RB3__READ                                           0x0007ffffU
#define PMU_PMU_RB3__PRESERVED                                      0x00000000U
#define PMU_PMU_RB3__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB3_MACRO__ */

/** @} end of pmu_rb3 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb4 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb4 pmu_rb4
 * @brief external OTP readback registers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB4_MACRO__
#define __PMU_PMU_RB4_MACRO__

/* macros for field otp_disable_xtal32K */
/**
 * @defgroup pmu_top_regs_core_otp_disable_xtal32K_field otp_disable_xtal32K_field
 * @brief macros for field otp_disable_xtal32K
 * @{
 */
#define PMU_PMU_RB4__OTP_DISABLE_XTAL32K__SHIFT                               0
#define PMU_PMU_RB4__OTP_DISABLE_XTAL32K__WIDTH                               1
#define PMU_PMU_RB4__OTP_DISABLE_XTAL32K__MASK                      0x00000001U
#define PMU_PMU_RB4__OTP_DISABLE_XTAL32K__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_RB4__OTP_DISABLE_XTAL32K__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU_RB4__OTP_DISABLE_XTAL32K__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU_RB4__OTP_DISABLE_XTAL32K__RESET_VALUE               0x00000000U
/** @} */

/* macros for field otp_supply_cfg */
/**
 * @defgroup pmu_top_regs_core_otp_supply_cfg_field otp_supply_cfg_field
 * @brief macros for field otp_supply_cfg
 * @details {otp_disable_5v,otp_disable_vddgen,otp_disable_vddIOgen,otp_noind}
 * @{
 */
#define PMU_PMU_RB4__OTP_SUPPLY_CFG__SHIFT                                    1
#define PMU_PMU_RB4__OTP_SUPPLY_CFG__WIDTH                                    4
#define PMU_PMU_RB4__OTP_SUPPLY_CFG__MASK                           0x0000001eU
#define PMU_PMU_RB4__OTP_SUPPLY_CFG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001eU) >> 1)
#define PMU_PMU_RB4__OTP_SUPPLY_CFG__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field otp_batt_cfg */
/**
 * @defgroup pmu_top_regs_core_otp_batt_cfg_field otp_batt_cfg_field
 * @brief macros for field otp_batt_cfg
 * @details {otp_vbatt_brownout[4:0],otp_vbatt_good[2:0],otp_batt_type[1:0],otp_vbatt_level}
 * @{
 */
#define PMU_PMU_RB4__OTP_BATT_CFG__SHIFT                                      5
#define PMU_PMU_RB4__OTP_BATT_CFG__WIDTH                                     11
#define PMU_PMU_RB4__OTP_BATT_CFG__MASK                             0x0000ffe0U
#define PMU_PMU_RB4__OTP_BATT_CFG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ffe0U) >> 5)
#define PMU_PMU_RB4__OTP_BATT_CFG__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field otp_vddio_range */
/**
 * @defgroup pmu_top_regs_core_otp_vddio_range_field otp_vddio_range_field
 * @brief macros for field otp_vddio_range
 * @{
 */
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__SHIFT                                  16
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__WIDTH                                   1
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__MASK                          0x00010000U
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field otp_reserved */
/**
 * @defgroup pmu_top_regs_core_otp_reserved_field otp_reserved_field
 * @brief macros for field otp_reserved
 * @{
 */
#define PMU_PMU_RB4__OTP_RESERVED__SHIFT                                     17
#define PMU_PMU_RB4__OTP_RESERVED__WIDTH                                      1
#define PMU_PMU_RB4__OTP_RESERVED__MASK                             0x00020000U
#define PMU_PMU_RB4__OTP_RESERVED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU_RB4__OTP_RESERVED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU_RB4__OTP_RESERVED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU_RB4__OTP_RESERVED__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field otp_harv_cfg */
/**
 * @defgroup pmu_top_regs_core_otp_harv_cfg_field otp_harv_cfg_field
 * @brief macros for field otp_harv_cfg
 * @details {otp_vstore_max[2:0],otp_vstore_good[1:0],otp_vharv_start[1:0],otp_disable_rfharv,otp_mppt_type[1:0]}
 * @{
 */
#define PMU_PMU_RB4__OTP_HARV_CFG__SHIFT                                     18
#define PMU_PMU_RB4__OTP_HARV_CFG__WIDTH                                     10
#define PMU_PMU_RB4__OTP_HARV_CFG__MASK                             0x0ffc0000U
#define PMU_PMU_RB4__OTP_HARV_CFG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0ffc0000U) >> 18)
#define PMU_PMU_RB4__OTP_HARV_CFG__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field otp_spare */
/**
 * @defgroup pmu_top_regs_core_otp_spare_field otp_spare_field
 * @brief macros for field otp_spare
 * @{
 */
#define PMU_PMU_RB4__OTP_SPARE__SHIFT                                        28
#define PMU_PMU_RB4__OTP_SPARE__WIDTH                                         1
#define PMU_PMU_RB4__OTP_SPARE__MASK                                0x10000000U
#define PMU_PMU_RB4__OTP_SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU_RB4__OTP_SPARE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU_RB4__OTP_SPARE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU_RB4__OTP_SPARE__RESET_VALUE                         0x00000000U
/** @} */
#define PMU_PMU_RB4__TYPE                                              uint32_t
#define PMU_PMU_RB4__READ                                           0x1fffffffU
#define PMU_PMU_RB4__PRESERVED                                      0x00000000U
#define PMU_PMU_RB4__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB4_MACRO__ */

/** @} end of pmu_rb4 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb5 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb5 pmu_rb5
 * @brief external soc watchdog reset readback status register definitions.
 * @{
 */
#ifndef __PMU_PMU_RB5_MACRO__
#define __PMU_PMU_RB5_MACRO__

/* macros for field soc_wdog_reset */
/**
 * @defgroup pmu_top_regs_core_soc_wdog_reset_field soc_wdog_reset_field
 * @brief macros for field soc_wdog_reset
 * @details HW writes sets status when soc wdog reset is asserted. SW writes clears status only.
 * @{
 */
#define PMU_PMU_RB5__SOC_WDOG_RESET__SHIFT                                    0
#define PMU_PMU_RB5__SOC_WDOG_RESET__WIDTH                                    1
#define PMU_PMU_RB5__SOC_WDOG_RESET__MASK                           0x00000001U
#define PMU_PMU_RB5__SOC_WDOG_RESET__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU_RB5__SOC_WDOG_RESET__WRITE(src) ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU_RB5__SOC_WDOG_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU_RB5__SOC_WDOG_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU_RB5__SOC_WDOG_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU_RB5__SOC_WDOG_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU_RB5__SOC_WDOG_RESET__RESET_VALUE                    0x00000000U
/** @} */
#define PMU_PMU_RB5__TYPE                                              uint32_t
#define PMU_PMU_RB5__READ                                           0x00000001U
#define PMU_PMU_RB5__WRITE                                          0x00000001U
#define PMU_PMU_RB5__PRESERVED                                      0x00000000U
#define PMU_PMU_RB5__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB5_MACRO__ */

/** @} end of pmu_rb5 */

/* macros for BlueprintGlobalNameSpace::PMU_core_id */
/**
 * @defgroup pmu_top_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __PMU_CORE_ID_MACRO__
#define __PMU_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup pmu_top_regs_core_id_field id_field
 * @brief macros for field id
 * @details PMU in ASCII
 * @{
 */
#define PMU_CORE_ID__ID__SHIFT                                                0
#define PMU_CORE_ID__ID__WIDTH                                               32
#define PMU_CORE_ID__ID__MASK                                       0xffffffffU
#define PMU_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define PMU_CORE_ID__ID__RESET_VALUE                                0x504d5520U
/** @} */
#define PMU_CORE_ID__TYPE                                              uint32_t
#define PMU_CORE_ID__READ                                           0xffffffffU
#define PMU_CORE_ID__PRESERVED                                      0x00000000U
#define PMU_CORE_ID__RESET_VALUE                                    0x504d5520U

#endif /* __PMU_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of PMU_TOP_REGS_CORE */
#endif /* __REG_PMU_TOP_REGS_CORE_H__ */
