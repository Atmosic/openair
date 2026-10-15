/*                                                                           */
/* File:       pmu_top_regs_core_macro.h                                     */
/*                                                                           */
/*                                                              */
/*                                                                           */
/* Blueprint:   3.7.5-atm (reduced-path-a)                                   */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/* Copyright (C) 2026 Atmosic Technologies.  All rights reserved             */
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
 * @details 2 Bit Selection for LP Comp Input 00 - PANA_0 01 - PANA_1 10 - DIV2 from MONITOR_VSTORE 11 - DIV4 from MONITOR VSTORE
 * @{
 */
#define PMU_PMU1__LPCOMP_IN_SEL__SHIFT                                       11
#define PMU_PMU1__LPCOMP_IN_SEL__WIDTH                                        2
#define PMU_PMU1__LPCOMP_IN_SEL__MASK                               0x00001800U
#define PMU_PMU1__LPCOMP_IN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define PMU_PMU1__LPCOMP_IN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define PMU_PMU1__LPCOMP_IN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define PMU_PMU1__LPCOMP_IN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define PMU_PMU1__LPCOMP_IN_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field xofaststart */
/**
 * @defgroup pmu_top_regs_core_xofaststart_field xofaststart_field
 * @brief macros for field xofaststart
 * @details enable fast start for xtal
 * @{
 */
#define PMU_PMU1__XOFASTSTART__SHIFT                                         13
#define PMU_PMU1__XOFASTSTART__WIDTH                                          3
#define PMU_PMU1__XOFASTSTART__MASK                                 0x0000e000U
#define PMU_PMU1__XOFASTSTART__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define PMU_PMU1__XOFASTSTART__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define PMU_PMU1__XOFASTSTART__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define PMU_PMU1__XOFASTSTART__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define PMU_PMU1__XOFASTSTART__RESET_VALUE                          0x00000006U
/** @} */

/* macros for field xosettle */
/**
 * @defgroup pmu_top_regs_core_xosettle_field xosettle_field
 * @brief macros for field xosettle
 * @details settling time for xtal
 * @{
 */
#define PMU_PMU1__XOSETTLE__SHIFT                                            16
#define PMU_PMU1__XOSETTLE__WIDTH                                             6
#define PMU_PMU1__XOSETTLE__MASK                                    0x003f0000U
#define PMU_PMU1__XOSETTLE__READ(src)   (((uint32_t)(src) & 0x003f0000U) >> 16)
#define PMU_PMU1__XOSETTLE__WRITE(src)  (((uint32_t)(src) << 16) & 0x003f0000U)
#define PMU_PMU1__XOSETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define PMU_PMU1__XOSETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define PMU_PMU1__XOSETTLE__RESET_VALUE                             0x00000010U
/** @} */

/* macros for field xtal_pwd */
/**
 * @defgroup pmu_top_regs_core_xtal_pwd_field xtal_pwd_field
 * @brief macros for field xtal_pwd
 * @details default is always on unless this is set or ext pwd is set
 * @{
 */
#define PMU_PMU1__XTAL_PWD__SHIFT                                            22
#define PMU_PMU1__XTAL_PWD__WIDTH                                             1
#define PMU_PMU1__XTAL_PWD__MASK                                    0x00400000U
#define PMU_PMU1__XTAL_PWD__READ(src)   (((uint32_t)(src) & 0x00400000U) >> 22)
#define PMU_PMU1__XTAL_PWD__WRITE(src)  (((uint32_t)(src) << 22) & 0x00400000U)
#define PMU_PMU1__XTAL_PWD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU1__XTAL_PWD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU1__XTAL_PWD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU1__XTAL_PWD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU1__XTAL_PWD__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field use16MforPSEQ */
/**
 * @defgroup pmu_top_regs_core_use16MforPSEQ_field use16MforPSEQ_field
 * @brief macros for field use16MforPSEQ
 * @details keep 16MHz on and use it as the clock source for 32KHz timers in PMU
 * @{
 */
#define PMU_PMU1__USE16MFORPSEQ__SHIFT                                       23
#define PMU_PMU1__USE16MFORPSEQ__WIDTH                                        1
#define PMU_PMU1__USE16MFORPSEQ__MASK                               0x00800000U
#define PMU_PMU1__USE16MFORPSEQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU1__USE16MFORPSEQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU1__USE16MFORPSEQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU1__USE16MFORPSEQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU1__USE16MFORPSEQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU1__USE16MFORPSEQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU1__USE16MFORPSEQ__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field doRCoscCal */
/**
 * @defgroup pmu_top_regs_core_doRCoscCal_field doRCoscCal_field
 * @brief macros for field doRCoscCal
 * @details set to 1 before entering low power state to do HW measurement in that state, clear after next wake up and read calCountRC value
 * @{
 */
#define PMU_PMU1__DORCOSCCAL__SHIFT                                          24
#define PMU_PMU1__DORCOSCCAL__WIDTH                                           1
#define PMU_PMU1__DORCOSCCAL__MASK                                  0x01000000U
#define PMU_PMU1__DORCOSCCAL__READ(src) (((uint32_t)(src) & 0x01000000U) >> 24)
#define PMU_PMU1__DORCOSCCAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU1__DORCOSCCAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU1__DORCOSCCAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU1__DORCOSCCAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU1__DORCOSCCAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU1__DORCOSCCAL__RESET_VALUE                           0x00000000U
/** @} */
#define PMU_PMU1__TYPE                                                 uint32_t
#define PMU_PMU1__READ                                              0x01ffffffU
#define PMU_PMU1__WRITE                                             0x01ffffffU
#define PMU_PMU1__PRESERVED                                         0x00000000U
#define PMU_PMU1__RESET_VALUE                                       0x0010c400U

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
#define PMU_PMU2__XOCAPOUT__RESET_VALUE                             0x00000015U
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
#define PMU_PMU2__XOCAPIN__RESET_VALUE                              0x00000015U
/** @} */

/* macros for field use_ext32k */
/**
 * @defgroup pmu_top_regs_core_use_ext32k_field use_ext32k_field
 * @brief macros for field use_ext32k
 * @details use external 32K clock source
 * @{
 */
#define PMU_PMU2__USE_EXT32K__SHIFT                                          10
#define PMU_PMU2__USE_EXT32K__WIDTH                                           1
#define PMU_PMU2__USE_EXT32K__MASK                                  0x00000400U
#define PMU_PMU2__USE_EXT32K__READ(src) (((uint32_t)(src) & 0x00000400U) >> 10)
#define PMU_PMU2__USE_EXT32K__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU2__USE_EXT32K__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU2__USE_EXT32K__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU2__USE_EXT32K__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU2__USE_EXT32K__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU2__USE_EXT32K__RESET_VALUE                           0x00000000U
/** @} */
#define PMU_PMU2__TYPE                                                 uint32_t
#define PMU_PMU2__READ                                              0x000007ffU
#define PMU_PMU2__WRITE                                             0x000007ffU
#define PMU_PMU2__PRESERVED                                         0x00000000U
#define PMU_PMU2__RESET_VALUE                                       0x000002b5U

#endif /* __PMU_PMU2_MACRO__ */

/** @} end of pmu2 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu3 */
/**
 * @defgroup pmu_top_regs_core_pmu3 pmu3
 * @brief XTAL, LPComp and Extbst definitions.
 * @{
 */
#ifndef __PMU_PMU3_MACRO__
#define __PMU_PMU3_MACRO__

/* macros for field xoagc_en */
/**
 * @defgroup pmu_top_regs_core_xoagc_en_field xoagc_en_field
 * @brief macros for field xoagc_en
 * @details Enable 32KHz xtal AGC
 * @{
 */
#define PMU_PMU3__XOAGC_EN__SHIFT                                             0
#define PMU_PMU3__XOAGC_EN__WIDTH                                             1
#define PMU_PMU3__XOAGC_EN__MASK                                    0x00000001U
#define PMU_PMU3__XOAGC_EN__READ(src)           ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU3__XOAGC_EN__WRITE(src)          ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU3__XOAGC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU3__XOAGC_EN__VERIFY(src)   (!(((uint32_t)(src) & ~0x00000001U)))
#define PMU_PMU3__XOAGC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU3__XOAGC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU3__XOAGC_EN__RESET_VALUE                             0x00000001U
/** @} */

/* macros for field xobias */
/**
 * @defgroup pmu_top_regs_core_xobias_field xobias_field
 * @brief macros for field xobias
 * @details 32KHz xtal bias current or AGC target
 * @{
 */
#define PMU_PMU3__XOBIAS__SHIFT                                               1
#define PMU_PMU3__XOBIAS__WIDTH                                               4
#define PMU_PMU3__XOBIAS__MASK                                      0x0000001eU
#define PMU_PMU3__XOBIAS__READ(src)      (((uint32_t)(src) & 0x0000001eU) >> 1)
#define PMU_PMU3__XOBIAS__WRITE(src)     (((uint32_t)(src) << 1) & 0x0000001eU)
#define PMU_PMU3__XOBIAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001eU) | (((uint32_t)(src) <<\
                    1) & 0x0000001eU)
#define PMU_PMU3__XOBIAS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000001eU)))
#define PMU_PMU3__XOBIAS__RESET_VALUE                               0x0000000cU
/** @} */

/* macros for field rcosc32Kfreq */
/**
 * @defgroup pmu_top_regs_core_rcosc32Kfreq_field rcosc32Kfreq_field
 * @brief macros for field rcosc32Kfreq
 * @details 32KHz RC osc freq tuning
 * @{
 */
#define PMU_PMU3__RCOSC32KFREQ__SHIFT                                         5
#define PMU_PMU3__RCOSC32KFREQ__WIDTH                                         4
#define PMU_PMU3__RCOSC32KFREQ__MASK                                0x000001e0U
#define PMU_PMU3__RCOSC32KFREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001e0U) >> 5)
#define PMU_PMU3__RCOSC32KFREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000001e0U)
#define PMU_PMU3__RCOSC32KFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001e0U) | (((uint32_t)(src) <<\
                    5) & 0x000001e0U)
#define PMU_PMU3__RCOSC32KFREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000001e0U)))
#define PMU_PMU3__RCOSC32KFREQ__RESET_VALUE                         0x00000004U
/** @} */

/* macros for field rcosc32Kmode */
/**
 * @defgroup pmu_top_regs_core_rcosc32Kmode_field rcosc32Kmode_field
 * @brief macros for field rcosc32Kmode
 * @details 32KHz RC osc mode/topology select
 * @{
 */
#define PMU_PMU3__RCOSC32KMODE__SHIFT                                         9
#define PMU_PMU3__RCOSC32KMODE__WIDTH                                         1
#define PMU_PMU3__RCOSC32KMODE__MASK                                0x00000200U
#define PMU_PMU3__RCOSC32KMODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU3__RCOSC32KMODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU3__RCOSC32KMODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU3__RCOSC32KMODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU3__RCOSC32KMODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU3__RCOSC32KMODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU3__RCOSC32KMODE__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field dc_ctrl */
/**
 * @defgroup pmu_top_regs_core_dc_ctrl_field dc_ctrl_field
 * @brief macros for field dc_ctrl
 * @details Duty cycle control for 32kHz doubler 0x0 - 0.77us Ontime 0x4 - 3.84us Ontime 0x7 - 6.34us Ontime
 * @{
 */
#define PMU_PMU3__DC_CTRL__SHIFT                                             10
#define PMU_PMU3__DC_CTRL__WIDTH                                              3
#define PMU_PMU3__DC_CTRL__MASK                                     0x00001c00U
#define PMU_PMU3__DC_CTRL__READ(src)    (((uint32_t)(src) & 0x00001c00U) >> 10)
#define PMU_PMU3__DC_CTRL__WRITE(src)   (((uint32_t)(src) << 10) & 0x00001c00U)
#define PMU_PMU3__DC_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define PMU_PMU3__DC_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define PMU_PMU3__DC_CTRL__RESET_VALUE                              0x00000003U
/** @} */

/* macros for field lpcomp_atbsel */
/**
 * @defgroup pmu_top_regs_core_lpcomp_atbsel_field lpcomp_atbsel_field
 * @brief macros for field lpcomp_atbsel
 * @details ATB Enable/Select for LPcomp
 * @{
 */
#define PMU_PMU3__LPCOMP_ATBSEL__SHIFT                                       13
#define PMU_PMU3__LPCOMP_ATBSEL__WIDTH                                        1
#define PMU_PMU3__LPCOMP_ATBSEL__MASK                               0x00002000U
#define PMU_PMU3__LPCOMP_ATBSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU3__LPCOMP_ATBSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU3__LPCOMP_ATBSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU3__LPCOMP_ATBSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU3__LPCOMP_ATBSEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU3__LPCOMP_ATBSEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU3__LPCOMP_ATBSEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field en_extbst */
/**
 * @defgroup pmu_top_regs_core_en_extbst_field en_extbst_field
 * @brief macros for field en_extbst
 * @details Enables external booster circuit 0 - Disable 1 - Enable analog portion of ext booster
 * @{
 */
#define PMU_PMU3__EN_EXTBST__SHIFT                                           14
#define PMU_PMU3__EN_EXTBST__WIDTH                                            1
#define PMU_PMU3__EN_EXTBST__MASK                                   0x00004000U
#define PMU_PMU3__EN_EXTBST__READ(src)  (((uint32_t)(src) & 0x00004000U) >> 14)
#define PMU_PMU3__EN_EXTBST__WRITE(src) (((uint32_t)(src) << 14) & 0x00004000U)
#define PMU_PMU3__EN_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU3__EN_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU3__EN_EXTBST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU3__EN_EXTBST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU3__EN_EXTBST__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field ctr_cuHigh_extbst */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHigh_extbst_field ctr_cuHigh_extbst_field
 * @brief macros for field ctr_cuHigh_extbst
 * @details Enables Fast current for Vharv comparator 0 - Disable (disable) 1 - Enable
 * @{
 */
#define PMU_PMU3__CTR_CUHIGH_EXTBST__SHIFT                                   15
#define PMU_PMU3__CTR_CUHIGH_EXTBST__WIDTH                                    1
#define PMU_PMU3__CTR_CUHIGH_EXTBST__MASK                           0x00008000U
#define PMU_PMU3__CTR_CUHIGH_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU3__CTR_CUHIGH_EXTBST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU3__CTR_CUHIGH_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU3__CTR_CUHIGH_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU3__CTR_CUHIGH_EXTBST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU3__CTR_CUHIGH_EXTBST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU3__CTR_CUHIGH_EXTBST__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ctr_cuHigheg_extbst */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHigheg_extbst_field ctr_cuHigheg_extbst_field
 * @brief macros for field ctr_cuHigheg_extbst
 * @details Selects Fast current settng for Vharv comparator 0 - 800nA 1 - 1.6uA
 * @{
 */
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__SHIFT                                 16
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__WIDTH                                  1
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__MASK                         0x00010000U
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU3__CTR_CUHIGHEG_EXTBST__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field ctr_cuLow_extbst */
/**
 * @defgroup pmu_top_regs_core_ctr_cuLow_extbst_field ctr_cuLow_extbst_field
 * @brief macros for field ctr_cuLow_extbst
 * @details Selects Slow current setting for Vharv Compartor (with ctr_cuMid_extbst = 100) 00 - 777pA 01 - 1.1nA 10 - 2.1nA 11 - 3.7nA (default)
 * @{
 */
#define PMU_PMU3__CTR_CULOW_EXTBST__SHIFT                                    17
#define PMU_PMU3__CTR_CULOW_EXTBST__WIDTH                                     2
#define PMU_PMU3__CTR_CULOW_EXTBST__MASK                            0x00060000U
#define PMU_PMU3__CTR_CULOW_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define PMU_PMU3__CTR_CULOW_EXTBST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define PMU_PMU3__CTR_CULOW_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define PMU_PMU3__CTR_CULOW_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define PMU_PMU3__CTR_CULOW_EXTBST__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field ctr_cuMid_extbst */
/**
 * @defgroup pmu_top_regs_core_ctr_cuMid_extbst_field ctr_cuMid_extbst_field
 * @brief macros for field ctr_cuMid_extbst
 * @details Selects Slow current setting for Vharv Compartor (with ctr_cuLow_extbst = 11) 0x0 - 1nA 0x1 - 3nA 0x2 - 5nA 0x3 - 7nA
 * @{
 */
#define PMU_PMU3__CTR_CUMID_EXTBST__SHIFT                                    19
#define PMU_PMU3__CTR_CUMID_EXTBST__WIDTH                                     3
#define PMU_PMU3__CTR_CUMID_EXTBST__MASK                            0x00380000U
#define PMU_PMU3__CTR_CUMID_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00380000U) >> 19)
#define PMU_PMU3__CTR_CUMID_EXTBST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00380000U)
#define PMU_PMU3__CTR_CUMID_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define PMU_PMU3__CTR_CUMID_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define PMU_PMU3__CTR_CUMID_EXTBST__RESET_VALUE                     0x00000004U
/** @} */

/* macros for field refHi_extbst */
/**
 * @defgroup pmu_top_regs_core_refHi_extbst_field refHi_extbst_field
 * @brief macros for field refHi_extbst
 * @details Selects VDDIO or AVDD for source of reference divider 0 - Use AVDD (1V) (default) 1 - Use VDDIO (1.8V)
 * @{
 */
#define PMU_PMU3__REFHI_EXTBST__SHIFT                                        22
#define PMU_PMU3__REFHI_EXTBST__WIDTH                                         1
#define PMU_PMU3__REFHI_EXTBST__MASK                                0x00400000U
#define PMU_PMU3__REFHI_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU3__REFHI_EXTBST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU3__REFHI_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU3__REFHI_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU3__REFHI_EXTBST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU3__REFHI_EXTBST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU3__REFHI_EXTBST__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field refLvl_extbst */
/**
 * @defgroup pmu_top_regs_core_refLvl_extbst_field refLvl_extbst_field
 * @brief macros for field refLvl_extbst
 * @details Selects reference level for VHARV (uses 1V AVDD), Mulitiply by 1.8 if using 1.8V VDDIO 0x00 - 0.04V (default) 0x10 - 0.13V 0x20 - 0.32V 0x30 - 0.62V 0x3f - 1.0V
 * @{
 */
#define PMU_PMU3__REFLVL_EXTBST__SHIFT                                       23
#define PMU_PMU3__REFLVL_EXTBST__WIDTH                                        6
#define PMU_PMU3__REFLVL_EXTBST__MASK                               0x1f800000U
#define PMU_PMU3__REFLVL_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1f800000U) >> 23)
#define PMU_PMU3__REFLVL_EXTBST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x1f800000U)
#define PMU_PMU3__REFLVL_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1f800000U) | (((uint32_t)(src) <<\
                    23) & 0x1f800000U)
#define PMU_PMU3__REFLVL_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x1f800000U)))
#define PMU_PMU3__REFLVL_EXTBST__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field en_lpcompgate_extbst */
/**
 * @defgroup pmu_top_regs_core_en_lpcompgate_extbst_field en_lpcompgate_extbst_field
 * @brief macros for field en_lpcompgate_extbst
 * @details Enables lpcomp gating with external booster circuit 0 - Normal Operation 1 - Disable external booster if lpcomp output=1
 * @{
 */
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__SHIFT                                29
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__WIDTH                                 1
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__MASK                        0x20000000U
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU3__EN_LPCOMPGATE_EXTBST__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field en_swCnt_active */
/**
 * @defgroup pmu_top_regs_core_en_swCnt_active_field en_swCnt_active_field
 * @brief macros for field en_swCnt_active
 * @details enables the counters that count switching activity in active mode
 * @{
 */
#define PMU_PMU3__EN_SWCNT_ACTIVE__SHIFT                                     30
#define PMU_PMU3__EN_SWCNT_ACTIVE__WIDTH                                      1
#define PMU_PMU3__EN_SWCNT_ACTIVE__MASK                             0x40000000U
#define PMU_PMU3__EN_SWCNT_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU3__EN_SWCNT_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU3__EN_SWCNT_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU3__EN_SWCNT_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU3__EN_SWCNT_ACTIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU3__EN_SWCNT_ACTIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU3__EN_SWCNT_ACTIVE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field en_swCnt_lp */
/**
 * @defgroup pmu_top_regs_core_en_swCnt_lp_field en_swCnt_lp_field
 * @brief macros for field en_swCnt_lp
 * @details enables the counters that count switchign activity in lp mode
 * @{
 */
#define PMU_PMU3__EN_SWCNT_LP__SHIFT                                         31
#define PMU_PMU3__EN_SWCNT_LP__WIDTH                                          1
#define PMU_PMU3__EN_SWCNT_LP__MASK                                 0x80000000U
#define PMU_PMU3__EN_SWCNT_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU3__EN_SWCNT_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU3__EN_SWCNT_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU3__EN_SWCNT_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU3__EN_SWCNT_LP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU3__EN_SWCNT_LP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU3__EN_SWCNT_LP__RESET_VALUE                          0x00000000U
/** @} */
#define PMU_PMU3__TYPE                                                 uint32_t
#define PMU_PMU3__READ                                              0xffffffffU
#define PMU_PMU3__WRITE                                             0xffffffffU
#define PMU_PMU3__PRESERVED                                         0x00000000U
#define PMU_PMU3__RESET_VALUE                                       0x00660c99U

#endif /* __PMU_PMU3_MACRO__ */

/** @} end of pmu3 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu4 */
/**
 * @defgroup pmu_top_regs_core_pmu4 pmu4
 * @brief Bias and Test Controls definitions.
 * @{
 */
#ifndef __PMU_PMU4_MACRO__
#define __PMU_PMU4_MACRO__

/* macros for field en_bgpmu_ovr */
/**
 * @defgroup pmu_top_regs_core_en_bgpmu_ovr_field en_bgpmu_ovr_field
 * @brief macros for field en_bgpmu_ovr
 * @details Override enable for Bandgap enable
 * @{
 */
#define PMU_PMU4__EN_BGPMU_OVR__SHIFT                                         0
#define PMU_PMU4__EN_BGPMU_OVR__WIDTH                                         1
#define PMU_PMU4__EN_BGPMU_OVR__MASK                                0x00000001U
#define PMU_PMU4__EN_BGPMU_OVR__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU4__EN_BGPMU_OVR__WRITE(src)      ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU4__EN_BGPMU_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU4__EN_BGPMU_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU4__EN_BGPMU_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU4__EN_BGPMU_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU4__EN_BGPMU_OVR__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field en_bgpmu_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_bgpmu_ovr_val_field en_bgpmu_ovr_val_field
 * @brief macros for field en_bgpmu_ovr_val
 * @details Override value for Bandgap enable
 * @{
 */
#define PMU_PMU4__EN_BGPMU_OVR_VAL__SHIFT                                     1
#define PMU_PMU4__EN_BGPMU_OVR_VAL__WIDTH                                     1
#define PMU_PMU4__EN_BGPMU_OVR_VAL__MASK                            0x00000002U
#define PMU_PMU4__EN_BGPMU_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU4__EN_BGPMU_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU4__EN_BGPMU_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU4__EN_BGPMU_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU4__EN_BGPMU_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU4__EN_BGPMU_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU4__EN_BGPMU_OVR_VAL__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field en_refcurr_ovr */
/**
 * @defgroup pmu_top_regs_core_en_refcurr_ovr_field en_refcurr_ovr_field
 * @brief macros for field en_refcurr_ovr
 * @details Override enable for uA Bias current enable
 * @{
 */
#define PMU_PMU4__EN_REFCURR_OVR__SHIFT                                       2
#define PMU_PMU4__EN_REFCURR_OVR__WIDTH                                       1
#define PMU_PMU4__EN_REFCURR_OVR__MASK                              0x00000004U
#define PMU_PMU4__EN_REFCURR_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU4__EN_REFCURR_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU4__EN_REFCURR_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU4__EN_REFCURR_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU4__EN_REFCURR_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU4__EN_REFCURR_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU4__EN_REFCURR_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field en_refcurr_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_refcurr_ovr_val_field en_refcurr_ovr_val_field
 * @brief macros for field en_refcurr_ovr_val
 * @details Override value for uA Bias current enable
 * @{
 */
#define PMU_PMU4__EN_REFCURR_OVR_VAL__SHIFT                                   3
#define PMU_PMU4__EN_REFCURR_OVR_VAL__WIDTH                                   1
#define PMU_PMU4__EN_REFCURR_OVR_VAL__MASK                          0x00000008U
#define PMU_PMU4__EN_REFCURR_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU4__EN_REFCURR_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU4__EN_REFCURR_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU4__EN_REFCURR_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU4__EN_REFCURR_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU4__EN_REFCURR_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU4__EN_REFCURR_OVR_VAL__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field en_refgen */
/**
 * @defgroup pmu_top_regs_core_en_refgen_field en_refgen_field
 * @brief macros for field en_refgen
 * @details Enables Refgen
 * @{
 */
#define PMU_PMU4__EN_REFGEN__SHIFT                                            4
#define PMU_PMU4__EN_REFGEN__WIDTH                                            1
#define PMU_PMU4__EN_REFGEN__MASK                                   0x00000010U
#define PMU_PMU4__EN_REFGEN__READ(src)   (((uint32_t)(src) & 0x00000010U) >> 4)
#define PMU_PMU4__EN_REFGEN__WRITE(src)  (((uint32_t)(src) << 4) & 0x00000010U)
#define PMU_PMU4__EN_REFGEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU4__EN_REFGEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU4__EN_REFGEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU4__EN_REFGEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU4__EN_REFGEN__RESET_VALUE                            0x00000001U
/** @} */

/* macros for field ctr_vrefnat_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_vrefnat_ovr_field ctr_vrefnat_ovr_field
 * @brief macros for field ctr_vrefnat_ovr
 * @details Override enable for Bandgap or Native selection
 * @{
 */
#define PMU_PMU4__CTR_VREFNAT_OVR__SHIFT                                      5
#define PMU_PMU4__CTR_VREFNAT_OVR__WIDTH                                      1
#define PMU_PMU4__CTR_VREFNAT_OVR__MASK                             0x00000020U
#define PMU_PMU4__CTR_VREFNAT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU4__CTR_VREFNAT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU4__CTR_VREFNAT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU4__CTR_VREFNAT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU4__CTR_VREFNAT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU4__CTR_VREFNAT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU4__CTR_VREFNAT_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field ctr_vrefnat_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_vrefnat_ovr_val_field ctr_vrefnat_ovr_val_field
 * @brief macros for field ctr_vrefnat_ovr_val
 * @details Override value for Bandgap or Native selection 0 - Use Main BG Reference 1 - Use Native Reference
 * @{
 */
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__SHIFT                                  6
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__WIDTH                                  1
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__MASK                         0x00000040U
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU4__CTR_VREFNAT_OVR_VAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field dis_pwd */
/**
 * @defgroup pmu_top_regs_core_dis_pwd_field dis_pwd_field
 * @brief macros for field dis_pwd
 * @details Disables PWD pin 0 - PWD pin operates normally (default) 1 - PWD signal is always low (chip is always enabled)
 * @{
 */
#define PMU_PMU4__DIS_PWD__SHIFT                                              7
#define PMU_PMU4__DIS_PWD__WIDTH                                              1
#define PMU_PMU4__DIS_PWD__MASK                                     0x00000080U
#define PMU_PMU4__DIS_PWD__READ(src)     (((uint32_t)(src) & 0x00000080U) >> 7)
#define PMU_PMU4__DIS_PWD__WRITE(src)    (((uint32_t)(src) << 7) & 0x00000080U)
#define PMU_PMU4__DIS_PWD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_PMU4__DIS_PWD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_PMU4__DIS_PWD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU4__DIS_PWD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU4__DIS_PWD__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field dis_vbatrdy */
/**
 * @defgroup pmu_top_regs_core_dis_vbatrdy_field dis_vbatrdy_field
 * @brief macros for field dis_vbatrdy
 * @details Disables Vbatrdy (Not used due to chicken/egg issue)
 * @{
 */
#define PMU_PMU4__DIS_VBATRDY__SHIFT                                          8
#define PMU_PMU4__DIS_VBATRDY__WIDTH                                          1
#define PMU_PMU4__DIS_VBATRDY__MASK                                 0x00000100U
#define PMU_PMU4__DIS_VBATRDY__READ(src) (((uint32_t)(src) & 0x00000100U) >> 8)
#define PMU_PMU4__DIS_VBATRDY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU4__DIS_VBATRDY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU4__DIS_VBATRDY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU4__DIS_VBATRDY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU4__DIS_VBATRDY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU4__DIS_VBATRDY__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field ctr_useVrefTR */
/**
 * @defgroup pmu_top_regs_core_ctr_useVrefTR_field ctr_useVrefTR_field
 * @brief macros for field ctr_useVrefTR
 * @details Selects Tracking Reference for AVDD0 - Use Vref from Refgen for AVDD (default)1 - Use trackinng reference VrefTR for AVDD
 * @{
 */
#define PMU_PMU4__CTR_USEVREFTR__SHIFT                                        9
#define PMU_PMU4__CTR_USEVREFTR__WIDTH                                        1
#define PMU_PMU4__CTR_USEVREFTR__MASK                               0x00000200U
#define PMU_PMU4__CTR_USEVREFTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU4__CTR_USEVREFTR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU4__CTR_USEVREFTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU4__CTR_USEVREFTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU4__CTR_USEVREFTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU4__CTR_USEVREFTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU4__CTR_USEVREFTR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field ctr_trackref */
/**
 * @defgroup pmu_top_regs_core_ctr_trackref_field ctr_trackref_field
 * @brief macros for field ctr_trackref
 * @details Sets Tracking Reference voltage 0x0 - TBD 0x1c - 1V (default) 0x1f - TBD
 * @{
 */
#define PMU_PMU4__CTR_TRACKREF__SHIFT                                        10
#define PMU_PMU4__CTR_TRACKREF__WIDTH                                         5
#define PMU_PMU4__CTR_TRACKREF__MASK                                0x00007c00U
#define PMU_PMU4__CTR_TRACKREF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define PMU_PMU4__CTR_TRACKREF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define PMU_PMU4__CTR_TRACKREF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define PMU_PMU4__CTR_TRACKREF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define PMU_PMU4__CTR_TRACKREF__RESET_VALUE                         0x0000001cU
/** @} */

/* macros for field ctr_trackrefhigh */
/**
 * @defgroup pmu_top_regs_core_ctr_trackrefhigh_field ctr_trackrefhigh_field
 * @brief macros for field ctr_trackrefhigh
 * @details Sets current of tracking reference bias 0 - Low current bias (1nA) 1 - High current bias (4nA)
 * @{
 */
#define PMU_PMU4__CTR_TRACKREFHIGH__SHIFT                                    15
#define PMU_PMU4__CTR_TRACKREFHIGH__WIDTH                                     1
#define PMU_PMU4__CTR_TRACKREFHIGH__MASK                            0x00008000U
#define PMU_PMU4__CTR_TRACKREFHIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU4__CTR_TRACKREFHIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU4__CTR_TRACKREFHIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU4__CTR_TRACKREFHIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU4__CTR_TRACKREFHIGH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU4__CTR_TRACKREFHIGH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU4__CTR_TRACKREFHIGH__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field ctr_refInsel */
/**
 * @defgroup pmu_top_regs_core_ctr_refInsel_field ctr_refInsel_field
 * @brief macros for field ctr_refInsel
 * @details Selects Max Voltage for Refgen (selects feedback point) 0x0 - 1.42V (27.3mV per step) 0x1 - 1.356V (26.1mV per step) 0x2 - 1.3V (25mV per step) (default) 0x3 - 1.248V (24mV per step)
 * @{
 */
#define PMU_PMU4__CTR_REFINSEL__SHIFT                                        16
#define PMU_PMU4__CTR_REFINSEL__WIDTH                                         2
#define PMU_PMU4__CTR_REFINSEL__MASK                                0x00030000U
#define PMU_PMU4__CTR_REFINSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define PMU_PMU4__CTR_REFINSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define PMU_PMU4__CTR_REFINSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define PMU_PMU4__CTR_REFINSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define PMU_PMU4__CTR_REFINSEL__RESET_VALUE                         0x00000002U
/** @} */

/* macros for field ctr_refgencurr */
/**
 * @defgroup pmu_top_regs_core_ctr_refgencurr_field ctr_refgencurr_field
 * @brief macros for field ctr_refgencurr
 * @details Controls current bias of Refgen Opamp 0 - 4nA 1 - 8nA (default)
 * @{
 */
#define PMU_PMU4__CTR_REFGENCURR__SHIFT                                      18
#define PMU_PMU4__CTR_REFGENCURR__WIDTH                                       1
#define PMU_PMU4__CTR_REFGENCURR__MASK                              0x00040000U
#define PMU_PMU4__CTR_REFGENCURR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU4__CTR_REFGENCURR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU4__CTR_REFGENCURR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU4__CTR_REFGENCURR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU4__CTR_REFGENCURR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU4__CTR_REFGENCURR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU4__CTR_REFGENCURR__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field rtrim_ic1u */
/**
 * @defgroup pmu_top_regs_core_rtrim_ic1u_field rtrim_ic1u_field
 * @brief macros for field rtrim_ic1u
 * @details Trim for 1uA current reference (4nA per step)0x00 - 0.88uA 0x20 - 1uA (default) 0x2F - 1.15uA
 * @{
 */
#define PMU_PMU4__RTRIM_IC1U__SHIFT                                          19
#define PMU_PMU4__RTRIM_IC1U__WIDTH                                           6
#define PMU_PMU4__RTRIM_IC1U__MASK                                  0x01f80000U
#define PMU_PMU4__RTRIM_IC1U__READ(src) (((uint32_t)(src) & 0x01f80000U) >> 19)
#define PMU_PMU4__RTRIM_IC1U__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x01f80000U)
#define PMU_PMU4__RTRIM_IC1U__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f80000U) | (((uint32_t)(src) <<\
                    19) & 0x01f80000U)
#define PMU_PMU4__RTRIM_IC1U__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x01f80000U)))
#define PMU_PMU4__RTRIM_IC1U__RESET_VALUE                           0x00000020U
/** @} */

/* macros for field en_refbuf_swreg */
/**
 * @defgroup pmu_top_regs_core_en_refbuf_swreg_field en_refbuf_swreg_field
 * @brief macros for field en_refbuf_swreg
 * @details Enables Reference Buffer for SWREG
 * @{
 */
#define PMU_PMU4__EN_REFBUF_SWREG__SHIFT                                     25
#define PMU_PMU4__EN_REFBUF_SWREG__WIDTH                                      1
#define PMU_PMU4__EN_REFBUF_SWREG__MASK                             0x02000000U
#define PMU_PMU4__EN_REFBUF_SWREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU4__EN_REFBUF_SWREG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU4__EN_REFBUF_SWREG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU4__EN_REFBUF_SWREG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU4__EN_REFBUF_SWREG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU4__EN_REFBUF_SWREG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU4__EN_REFBUF_SWREG__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field en_refbuf_vddio */
/**
 * @defgroup pmu_top_regs_core_en_refbuf_vddio_field en_refbuf_vddio_field
 * @brief macros for field en_refbuf_vddio
 * @details Enables Reference Buffer for VDDIO
 * @{
 */
#define PMU_PMU4__EN_REFBUF_VDDIO__SHIFT                                     26
#define PMU_PMU4__EN_REFBUF_VDDIO__WIDTH                                      1
#define PMU_PMU4__EN_REFBUF_VDDIO__MASK                             0x04000000U
#define PMU_PMU4__EN_REFBUF_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU4__EN_REFBUF_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU4__EN_REFBUF_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU4__EN_REFBUF_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU4__EN_REFBUF_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU4__EN_REFBUF_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU4__EN_REFBUF_VDDIO__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field en_refbuf_dvdd */
/**
 * @defgroup pmu_top_regs_core_en_refbuf_dvdd_field en_refbuf_dvdd_field
 * @brief macros for field en_refbuf_dvdd
 * @details Enables Reference Buffer for DVDD
 * @{
 */
#define PMU_PMU4__EN_REFBUF_DVDD__SHIFT                                      27
#define PMU_PMU4__EN_REFBUF_DVDD__WIDTH                                       1
#define PMU_PMU4__EN_REFBUF_DVDD__MASK                              0x08000000U
#define PMU_PMU4__EN_REFBUF_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU4__EN_REFBUF_DVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU4__EN_REFBUF_DVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU4__EN_REFBUF_DVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU4__EN_REFBUF_DVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU4__EN_REFBUF_DVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU4__EN_REFBUF_DVDD__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field byp_refbuf_swreg */
/**
 * @defgroup pmu_top_regs_core_byp_refbuf_swreg_field byp_refbuf_swreg_field
 * @brief macros for field byp_refbuf_swreg
 * @details Bypass Reference Buffer for SWREG
 * @{
 */
#define PMU_PMU4__BYP_REFBUF_SWREG__SHIFT                                    28
#define PMU_PMU4__BYP_REFBUF_SWREG__WIDTH                                     1
#define PMU_PMU4__BYP_REFBUF_SWREG__MASK                            0x10000000U
#define PMU_PMU4__BYP_REFBUF_SWREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU4__BYP_REFBUF_SWREG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU4__BYP_REFBUF_SWREG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU4__BYP_REFBUF_SWREG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU4__BYP_REFBUF_SWREG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU4__BYP_REFBUF_SWREG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU4__BYP_REFBUF_SWREG__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field byp_refbuf_vddio */
/**
 * @defgroup pmu_top_regs_core_byp_refbuf_vddio_field byp_refbuf_vddio_field
 * @brief macros for field byp_refbuf_vddio
 * @details Bypass Reference Buffer for VDDIO
 * @{
 */
#define PMU_PMU4__BYP_REFBUF_VDDIO__SHIFT                                    29
#define PMU_PMU4__BYP_REFBUF_VDDIO__WIDTH                                     1
#define PMU_PMU4__BYP_REFBUF_VDDIO__MASK                            0x20000000U
#define PMU_PMU4__BYP_REFBUF_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU4__BYP_REFBUF_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU4__BYP_REFBUF_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU4__BYP_REFBUF_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU4__BYP_REFBUF_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU4__BYP_REFBUF_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU4__BYP_REFBUF_VDDIO__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field byp_refbuf_dvdd */
/**
 * @defgroup pmu_top_regs_core_byp_refbuf_dvdd_field byp_refbuf_dvdd_field
 * @brief macros for field byp_refbuf_dvdd
 * @details Bypass Reference Buffer for DVDD
 * @{
 */
#define PMU_PMU4__BYP_REFBUF_DVDD__SHIFT                                     30
#define PMU_PMU4__BYP_REFBUF_DVDD__WIDTH                                      1
#define PMU_PMU4__BYP_REFBUF_DVDD__MASK                             0x40000000U
#define PMU_PMU4__BYP_REFBUF_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PMU_PMU4__BYP_REFBUF_DVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PMU_PMU4__BYP_REFBUF_DVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PMU_PMU4__BYP_REFBUF_DVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PMU_PMU4__BYP_REFBUF_DVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PMU_PMU4__BYP_REFBUF_DVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PMU_PMU4__BYP_REFBUF_DVDD__RESET_VALUE                      0x00000000U
/** @} */
#define PMU_PMU4__TYPE                                                 uint32_t
#define PMU_PMU4__READ                                              0x7fffffffU
#define PMU_PMU4__WRITE                                             0x7fffffffU
#define PMU_PMU4__PRESERVED                                         0x00000000U
#define PMU_PMU4__RESET_VALUE                                       0x0f06f01aU

#endif /* __PMU_PMU4_MACRO__ */

/** @} end of pmu4 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu4a */
/**
 * @defgroup pmu_top_regs_core_pmu4a pmu4a
 * @brief Bias and Test Controls definitions.
 * @{
 */
#ifndef __PMU_PMU4A_MACRO__
#define __PMU_PMU4A_MACRO__

/* macros for field pmu_ready_ovr */
/**
 * @defgroup pmu_top_regs_core_pmu_ready_ovr_field pmu_ready_ovr_field
 * @brief macros for field pmu_ready_ovr
 * @details Override enable for PMU ready
 * @{
 */
#define PMU_PMU4A__PMU_READY_OVR__SHIFT                                       0
#define PMU_PMU4A__PMU_READY_OVR__WIDTH                                       1
#define PMU_PMU4A__PMU_READY_OVR__MASK                              0x00000001U
#define PMU_PMU4A__PMU_READY_OVR__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU4A__PMU_READY_OVR__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU4A__PMU_READY_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU4A__PMU_READY_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU4A__PMU_READY_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU4A__PMU_READY_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU4A__PMU_READY_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field pmu_ready_ovr_val */
/**
 * @defgroup pmu_top_regs_core_pmu_ready_ovr_val_field pmu_ready_ovr_val_field
 * @brief macros for field pmu_ready_ovr_val
 * @details Override value for PMU ready
 * @{
 */
#define PMU_PMU4A__PMU_READY_OVR_VAL__SHIFT                                   1
#define PMU_PMU4A__PMU_READY_OVR_VAL__WIDTH                                   1
#define PMU_PMU4A__PMU_READY_OVR_VAL__MASK                          0x00000002U
#define PMU_PMU4A__PMU_READY_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU4A__PMU_READY_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU4A__PMU_READY_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU4A__PMU_READY_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU4A__PMU_READY_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU4A__PMU_READY_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU4A__PMU_READY_OVR_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field force_porb_ref */
/**
 * @defgroup pmu_top_regs_core_force_porb_ref_field force_porb_ref_field
 * @brief macros for field force_porb_ref
 * @details Forces porb for References to be always High (Test Only)
 * @{
 */
#define PMU_PMU4A__FORCE_PORB_REF__SHIFT                                      2
#define PMU_PMU4A__FORCE_PORB_REF__WIDTH                                      1
#define PMU_PMU4A__FORCE_PORB_REF__MASK                             0x00000004U
#define PMU_PMU4A__FORCE_PORB_REF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU4A__FORCE_PORB_REF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU4A__FORCE_PORB_REF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU4A__FORCE_PORB_REF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU4A__FORCE_PORB_REF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU4A__FORCE_PORB_REF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU4A__FORCE_PORB_REF__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field force_porb_swreg */
/**
 * @defgroup pmu_top_regs_core_force_porb_swreg_field force_porb_swreg_field
 * @brief macros for field force_porb_swreg
 * @details Forces porb for SWREG to be always High (Test Only)
 * @{
 */
#define PMU_PMU4A__FORCE_PORB_SWREG__SHIFT                                    3
#define PMU_PMU4A__FORCE_PORB_SWREG__WIDTH                                    1
#define PMU_PMU4A__FORCE_PORB_SWREG__MASK                           0x00000008U
#define PMU_PMU4A__FORCE_PORB_SWREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU4A__FORCE_PORB_SWREG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU4A__FORCE_PORB_SWREG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU4A__FORCE_PORB_SWREG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU4A__FORCE_PORB_SWREG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU4A__FORCE_PORB_SWREG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU4A__FORCE_PORB_SWREG__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field force_porb_vddio */
/**
 * @defgroup pmu_top_regs_core_force_porb_vddio_field force_porb_vddio_field
 * @brief macros for field force_porb_vddio
 * @details Forces porb for VDDIO to be always High (Test Only)
 * @{
 */
#define PMU_PMU4A__FORCE_PORB_VDDIO__SHIFT                                    4
#define PMU_PMU4A__FORCE_PORB_VDDIO__WIDTH                                    1
#define PMU_PMU4A__FORCE_PORB_VDDIO__MASK                           0x00000010U
#define PMU_PMU4A__FORCE_PORB_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU4A__FORCE_PORB_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU4A__FORCE_PORB_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU4A__FORCE_PORB_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU4A__FORCE_PORB_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU4A__FORCE_PORB_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU4A__FORCE_PORB_VDDIO__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field force_porb_dvdd */
/**
 * @defgroup pmu_top_regs_core_force_porb_dvdd_field force_porb_dvdd_field
 * @brief macros for field force_porb_dvdd
 * @details Forces porb for DVDD to be always High (Test Only)
 * @{
 */
#define PMU_PMU4A__FORCE_PORB_DVDD__SHIFT                                     5
#define PMU_PMU4A__FORCE_PORB_DVDD__WIDTH                                     1
#define PMU_PMU4A__FORCE_PORB_DVDD__MASK                            0x00000020U
#define PMU_PMU4A__FORCE_PORB_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU4A__FORCE_PORB_DVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU4A__FORCE_PORB_DVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU4A__FORCE_PORB_DVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU4A__FORCE_PORB_DVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU4A__FORCE_PORB_DVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU4A__FORCE_PORB_DVDD__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field force_porb_avdd */
/**
 * @defgroup pmu_top_regs_core_force_porb_avdd_field force_porb_avdd_field
 * @brief macros for field force_porb_avdd
 * @details Forces porb for AVDD to be always High (NOT USED - Chicken/Egg Issue with level shifters)
 * @{
 */
#define PMU_PMU4A__FORCE_PORB_AVDD__SHIFT                                     6
#define PMU_PMU4A__FORCE_PORB_AVDD__WIDTH                                     1
#define PMU_PMU4A__FORCE_PORB_AVDD__MASK                            0x00000040U
#define PMU_PMU4A__FORCE_PORB_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU4A__FORCE_PORB_AVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PMU_PMU4A__FORCE_PORB_AVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU4A__FORCE_PORB_AVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU4A__FORCE_PORB_AVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU4A__FORCE_PORB_AVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU4A__FORCE_PORB_AVDD__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field ctr_ref_brownout */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_brownout_field ctr_ref_brownout_field
 * @brief macros for field ctr_ref_brownout
 * @details Selects Vbat1/3 Brownout Reference Voltage in 25/50mV steps 0x0 - 900mV/1.8V (default) 0x4 - 1.075V/2.15V 0xe - 1.25V/2.5V (Highest Brownout setting) 0xf - 1.275V/2.55V (setting should not be used, reserved for hysteresis)
 * @{
 */
#define PMU_PMU4A__CTR_REF_BROWNOUT__SHIFT                                    7
#define PMU_PMU4A__CTR_REF_BROWNOUT__WIDTH                                    4
#define PMU_PMU4A__CTR_REF_BROWNOUT__MASK                           0x00000780U
#define PMU_PMU4A__CTR_REF_BROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000780U) >> 7)
#define PMU_PMU4A__CTR_REF_BROWNOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define PMU_PMU4A__CTR_REF_BROWNOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define PMU_PMU4A__CTR_REF_BROWNOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define PMU_PMU4A__CTR_REF_BROWNOUT__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ctr_ref_lpc0 */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_lpc0_field ctr_ref_lpc0_field
 * @brief macros for field ctr_ref_lpc0
 * @details Selects LPcomp Lower Voltage in 50mV (0x0 to 0x7) or 100mV steps (0x7 to 0xf) 0x0 - 475mV (default)0x8 - 675mV 0xf - 850mV
 * @{
 */
#define PMU_PMU4A__CTR_REF_LPC0__SHIFT                                       11
#define PMU_PMU4A__CTR_REF_LPC0__WIDTH                                        4
#define PMU_PMU4A__CTR_REF_LPC0__MASK                               0x00007800U
#define PMU_PMU4A__CTR_REF_LPC0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007800U) >> 11)
#define PMU_PMU4A__CTR_REF_LPC0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00007800U)
#define PMU_PMU4A__CTR_REF_LPC0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007800U) | (((uint32_t)(src) <<\
                    11) & 0x00007800U)
#define PMU_PMU4A__CTR_REF_LPC0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00007800U)))
#define PMU_PMU4A__CTR_REF_LPC0__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field ctr_ref_lpc1 */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_lpc1_field ctr_ref_lpc1_field
 * @brief macros for field ctr_ref_lpc1
 * @details Selects LPcomp Upper Voltage in 50mV (0x0 to 0x7) or 100mV steps (0x7 to 0xf) 0x0 - 500mV (default)0x8 - 700mV 0xf - 875mV
 * @{
 */
#define PMU_PMU4A__CTR_REF_LPC1__SHIFT                                       15
#define PMU_PMU4A__CTR_REF_LPC1__WIDTH                                        4
#define PMU_PMU4A__CTR_REF_LPC1__MASK                               0x00078000U
#define PMU_PMU4A__CTR_REF_LPC1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00078000U) >> 15)
#define PMU_PMU4A__CTR_REF_LPC1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00078000U)
#define PMU_PMU4A__CTR_REF_LPC1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00078000U) | (((uint32_t)(src) <<\
                    15) & 0x00078000U)
#define PMU_PMU4A__CTR_REF_LPC1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00078000U)))
#define PMU_PMU4A__CTR_REF_LPC1__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field ctr_ref_gadc */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_gadc_field ctr_ref_gadc_field
 * @brief macros for field ctr_ref_gadc
 * @details Selects GADC Reference Voltage in 25mV steps (0.6V) 0x0 - 525mV 0x3 - 600mV 0x7 - 700mV
 * @{
 */
#define PMU_PMU4A__CTR_REF_GADC__SHIFT                                       19
#define PMU_PMU4A__CTR_REF_GADC__WIDTH                                        3
#define PMU_PMU4A__CTR_REF_GADC__MASK                               0x00380000U
#define PMU_PMU4A__CTR_REF_GADC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00380000U) >> 19)
#define PMU_PMU4A__CTR_REF_GADC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00380000U)
#define PMU_PMU4A__CTR_REF_GADC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define PMU_PMU4A__CTR_REF_GADC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define PMU_PMU4A__CTR_REF_GADC__RESET_VALUE                        0x00000003U
/** @} */

/* macros for field ctr_ref_vddio_otp */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_vddio_otp_field ctr_ref_vddio_otp_field
 * @brief macros for field ctr_ref_vddio_otp
 * @details Selects OTP mode VDDIO Reference Voltage in 50mV steps (0x0 to 0x9) or 100mV steps (0x9 to 0xf) (2.5V) 0x0 - 1.55V (Vrefvddio=775mV) 0x9 - 2V (Vrefvddio=1V) 0xe - 2.5V (Vrefvddio=1.25V) 0xf - 2.6V (Vrefvddio=1.3V)
 * @{
 */
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__SHIFT                                  22
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__WIDTH                                   4
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__MASK                          0x03c00000U
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03c00000U) >> 22)
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x03c00000U)
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03c00000U) | (((uint32_t)(src) <<\
                    22) & 0x03c00000U)
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x03c00000U)))
#define PMU_PMU4A__CTR_REF_VDDIO_OTP__RESET_VALUE                   0x0000000eU
/** @} */

/* macros for field brownout_target */
/**
 * @defgroup pmu_top_regs_core_brownout_target_field brownout_target_field
 * @brief macros for field brownout_target
 * @details filter brownout if it is now low long enough
 * @{
 */
#define PMU_PMU4A__BROWNOUT_TARGET__SHIFT                                    26
#define PMU_PMU4A__BROWNOUT_TARGET__WIDTH                                     5
#define PMU_PMU4A__BROWNOUT_TARGET__MASK                            0x7c000000U
#define PMU_PMU4A__BROWNOUT_TARGET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7c000000U) >> 26)
#define PMU_PMU4A__BROWNOUT_TARGET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x7c000000U)
#define PMU_PMU4A__BROWNOUT_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7c000000U) | (((uint32_t)(src) <<\
                    26) & 0x7c000000U)
#define PMU_PMU4A__BROWNOUT_TARGET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x7c000000U)))
#define PMU_PMU4A__BROWNOUT_TARGET__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field wake_only_if_enough_energy */
/**
 * @defgroup pmu_top_regs_core_wake_only_if_enough_energy_field wake_only_if_enough_energy_field
 * @brief macros for field wake_only_if_enough_energy
 * @details if set come out of soc off when enough energy
 * @{
 */
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__SHIFT                         31
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__WIDTH                          1
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__MASK                 0x80000000U
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PMU_PMU4A__WAKE_ONLY_IF_ENOUGH_ENERGY__RESET_VALUE          0x00000000U
/** @} */
#define PMU_PMU4A__TYPE                                                uint32_t
#define PMU_PMU4A__READ                                             0xffffffffU
#define PMU_PMU4A__WRITE                                            0xffffffffU
#define PMU_PMU4A__PRESERVED                                        0x00000000U
#define PMU_PMU4A__RESET_VALUE                                      0x03980000U

#endif /* __PMU_PMU4A_MACRO__ */

/** @} end of pmu4a */

/* macros for BlueprintGlobalNameSpace::PMU_pmu5 */
/**
 * @defgroup pmu_top_regs_core_pmu5 pmu5
 * @brief Buck and Boost Reference Controls definitions.
 * @{
 */
#ifndef __PMU_PMU5_MACRO__
#define __PMU_PMU5_MACRO__

/* macros for field ctr_ref_buck_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_buck_active_field ctr_ref_buck_active_field
 * @brief macros for field ctr_ref_buck_active
 * @details Selects Active Mode Buck Reference Voltage in 25mV steps (1.1V) 0x00 - 750mV 0x10 - 1.15V (default) 0x16 - 1.3V (not allowed to go above 0x16)
 * @{
 */
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__SHIFT                                  0
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__WIDTH                                  5
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__MASK                         0x0000001fU
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define PMU_PMU5__CTR_REF_BUCK_ACTIVE__RESET_VALUE                  0x00000010U
/** @} */

/* macros for field ctr_ref_buck_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_buck_LP_field ctr_ref_buck_LP_field
 * @brief macros for field ctr_ref_buck_LP
 * @details Selects LP Mode Buck Reference Voltage in 25mV steps(1.05V) 0x00 - 750mV 0x0a - 1.00V (default) 0x16 - 1.3V (not allowed to go above 0x16)
 * @{
 */
#define PMU_PMU5__CTR_REF_BUCK_LP__SHIFT                                      5
#define PMU_PMU5__CTR_REF_BUCK_LP__WIDTH                                      5
#define PMU_PMU5__CTR_REF_BUCK_LP__MASK                             0x000003e0U
#define PMU_PMU5__CTR_REF_BUCK_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define PMU_PMU5__CTR_REF_BUCK_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define PMU_PMU5__CTR_REF_BUCK_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define PMU_PMU5__CTR_REF_BUCK_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define PMU_PMU5__CTR_REF_BUCK_LP__RESET_VALUE                      0x0000000aU
/** @} */

/* macros for field ctr_ref_por_buck_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_buck_active_field ctr_ref_por_buck_active_field
 * @brief macros for field ctr_ref_por_buck_active
 * @details Selects Active Mode Buck POR Reference Voltage in 50mV steps (0x0 to 0x5) or 100mV steps (0x5 to 0x7) (950mV) 0x0 - 700mV 0x3 - 850mV 0x5 - 950mV (default) 0x7 - 1.15V
 * @{
 */
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__SHIFT                             10
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__WIDTH                              3
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__MASK                     0x00001c00U
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define PMU_PMU5__CTR_REF_POR_BUCK_ACTIVE__RESET_VALUE              0x00000005U
/** @} */

/* macros for field ctr_ref_por_buck_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_buck_LP_field ctr_ref_por_buck_LP_field
 * @brief macros for field ctr_ref_por_buck_LP
 * @details Selects LP Mode Buck POR Reference Voltage in 50mV steps (0x0 to 0x5) or 100mV steps (0x5 to 0x7) (900mV) 0x0 - 700mV 0x3 - 850mV (default) 0x4 - 900mV 0x7 - 1.15V
 * @{
 */
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__SHIFT                                 13
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__WIDTH                                  3
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__MASK                         0x0000e000U
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define PMU_PMU5__CTR_REF_POR_BUCK_LP__RESET_VALUE                  0x00000003U
/** @} */

/* macros for field ctr_ref_boost_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_boost_active_field ctr_ref_boost_active_field
 * @brief macros for field ctr_ref_boost_active
 * @details Selects Active Mode Boost Reference Voltage in 50mV steps (DIV2) ot 75mV steps (DIV3) (1.9V if DIV2) 0x00 - 1.5V (DIV2) / 2.25V (DIV3) 0x08 - 1.9V (DIV2) / 2.85V (DIV3) (default) 0x16 - 2.6V (DIV2) / 3.9V (DIV3) (not allowed to go above 0x16)
 * @{
 */
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__SHIFT                                16
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__WIDTH                                 5
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__MASK                        0x001f0000U
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define PMU_PMU5__CTR_REF_BOOST_ACTIVE__RESET_VALUE                 0x00000008U
/** @} */

/* macros for field ctr_ref_boost_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_boost_LP_field ctr_ref_boost_LP_field
 * @brief macros for field ctr_ref_boost_LP
 * @details Selects LP Mode Boost Reference Voltage in 50mV steps (DIV2) ot 75mV steps (DIV3) (1.85V if DIV2) 0x00 - 1.5V (DIV2) / 2.25V (DIV3) 0x07 - 1.85V (DIV2) / 2.775V (DIV3) (default) 0x16 - 2.6V (DIV2) / 3.9V (DIV3) (not allowed to go above 0x16)
 * @{
 */
#define PMU_PMU5__CTR_REF_BOOST_LP__SHIFT                                    21
#define PMU_PMU5__CTR_REF_BOOST_LP__WIDTH                                     5
#define PMU_PMU5__CTR_REF_BOOST_LP__MASK                            0x03e00000U
#define PMU_PMU5__CTR_REF_BOOST_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03e00000U) >> 21)
#define PMU_PMU5__CTR_REF_BOOST_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x03e00000U)
#define PMU_PMU5__CTR_REF_BOOST_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03e00000U) | (((uint32_t)(src) <<\
                    21) & 0x03e00000U)
#define PMU_PMU5__CTR_REF_BOOST_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x03e00000U)))
#define PMU_PMU5__CTR_REF_BOOST_LP__RESET_VALUE                     0x00000007U
/** @} */

/* macros for field ctr_ref_por_boost_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_boost_active_field ctr_ref_por_boost_active_field
 * @brief macros for field ctr_ref_por_boost_active
 * @details Selects Active Mode Boost POR Reference Voltage in 100mV/150mV steps (0x0 to 0x5)(DIV2/DIV3) or 200mV/300mV steps (0x5 to 0x7) (DIV2/DIV3)(1.7V if DIV2) 0x0 - 1.4V/2.1V (Vrefpor=700mV) 0x3 - 1.7V/2.55V (Vrefpor=850mV) (default) 0x5 - 1.9V/2.85V (Vrefpor=950mV) 0x7 - 2.3V/3.45V (Vrefpor=1.15V)
 * @{
 */
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__SHIFT                            26
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__WIDTH                             3
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__MASK                    0x1c000000U
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1c000000U) >> 26)
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x1c000000U)
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1c000000U) | (((uint32_t)(src) <<\
                    26) & 0x1c000000U)
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x1c000000U)))
#define PMU_PMU5__CTR_REF_POR_BOOST_ACTIVE__RESET_VALUE             0x00000003U
/** @} */

/* macros for field ctr_ref_por_boost_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_boost_LP_field ctr_ref_por_boost_LP_field
 * @brief macros for field ctr_ref_por_boost_LP
 * @details Selects LP Mode Buck Boost Reference Voltage in 100mV/150mV steps (0x0 to 0x5)(DIV2/DIV3) or 200mV/300mV steps (0x5 to 0x7) (DIV2/DIV3) (1.65V if DIV2) 0x0 - 1.4V/2.1V (Vrefpor=700mV) 0x2 - 1.6V/2.4V (Vrefpor=800mV) (default) 0x5 - 1.9V/2.85V (Vrefpor=950mV) 0x7 - 2.3V/3.45V (Vrefpor=1.15V)
 * @{
 */
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__SHIFT                                29
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__WIDTH                                 3
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__MASK                        0xe0000000U
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
#define PMU_PMU5__CTR_REF_POR_BOOST_LP__RESET_VALUE                 0x00000002U
/** @} */
#define PMU_PMU5__TYPE                                                 uint32_t
#define PMU_PMU5__READ                                              0xffffffffU
#define PMU_PMU5__WRITE                                             0xffffffffU
#define PMU_PMU5__PRESERVED                                         0x00000000U
#define PMU_PMU5__RESET_VALUE                                       0x4ce87550U

#endif /* __PMU_PMU5_MACRO__ */

/** @} end of pmu5 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu6 */
/**
 * @defgroup pmu_top_regs_core_pmu6 pmu6
 * @brief VDDIO and DVDD Reference controls definitions.
 * @{
 */
#ifndef __PMU_PMU6_MACRO__
#define __PMU_PMU6_MACRO__

/* macros for field ctr_ref_vddio_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_vddio_active_field ctr_ref_vddio_active_field
 * @brief macros for field ctr_ref_vddio_active
 * @details Selects Active Mode VDDIO Reference Voltage in 50mV steps (0x0 to 0x9) or 100mV steps (0x9 to 0xf) (1.8V) 0x0 - 1.55V (Vrefvddio=775mV) 0x5 - 1.8V (Vrefvddio=900mV)(default) 0x9 - 2V (Vrefvddio=1V) 0xa - 2.1V (Vrefvddio=1.05V) 0xf - 2.6V (Vrefvddio=1.3V)
 * @{
 */
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__SHIFT                                 0
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__WIDTH                                 4
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__MASK                        0x0000000fU
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PMU_PMU6__CTR_REF_VDDIO_ACTIVE__RESET_VALUE                 0x00000005U
/** @} */

/* macros for field ctr_ref_vddio_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_vddio_LP_field ctr_ref_vddio_LP_field
 * @brief macros for field ctr_ref_vddio_LP
 * @details Selects LP Mode VDDIO Reference Voltage in 50mV steps (0x0 to 0x9) or 100mV steps (0x9 to 0xf) (1.8V) 0x0 - 1.55V (Vrefvddio=775mV)0x5 - 1.8V (Vrefvddio=900mV)(default) 0x9 - 2V (Vrefvddio=1V) 0xa - 2.1V (Vrefvddio=1.05V) 0xf - 2.6V (Vrefvddio=1.3V)
 * @{
 */
#define PMU_PMU6__CTR_REF_VDDIO_LP__SHIFT                                     4
#define PMU_PMU6__CTR_REF_VDDIO_LP__WIDTH                                     4
#define PMU_PMU6__CTR_REF_VDDIO_LP__MASK                            0x000000f0U
#define PMU_PMU6__CTR_REF_VDDIO_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define PMU_PMU6__CTR_REF_VDDIO_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define PMU_PMU6__CTR_REF_VDDIO_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define PMU_PMU6__CTR_REF_VDDIO_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define PMU_PMU6__CTR_REF_VDDIO_LP__RESET_VALUE                     0x00000005U
/** @} */

/* macros for field ctr_ref_por_vddio_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_vddio_active_field ctr_ref_por_vddio_active_field
 * @brief macros for field ctr_ref_por_vddio_active
 * @details Selects Active Mode VDDIO POR Reference Voltage in 100mV steps (1.6V) 0x0 - 1.2V (Vrefporvddio=600mV) 0x4 - 1.6V (Vrefporvddio=800mV)(default) 0x7 - 1.9V (Vrefporvddio=950mV)
 * @{
 */
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__SHIFT                             8
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__WIDTH                             3
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__MASK                    0x00000700U
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define PMU_PMU6__CTR_REF_POR_VDDIO_ACTIVE__RESET_VALUE             0x00000004U
/** @} */

/* macros for field ctr_ref_por_vddio_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_vddio_LP_field ctr_ref_por_vddio_LP_field
 * @brief macros for field ctr_ref_por_vddio_LP
 * @details Selects LP Mode VDDIO POR Reference Voltage in 100mV steps (1.6V) 0x0 - 1.2V (Vrefporvddio=600mV) 0x4 - 1.6V (Vrefporvddio=800mV)(default) 0x7 - 1.9V (Vrefporvddio=950mV)
 * @{
 */
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__SHIFT                                11
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__WIDTH                                 3
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__MASK                        0x00003800U
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define PMU_PMU6__CTR_REF_POR_VDDIO_LP__RESET_VALUE                 0x00000004U
/** @} */

/* macros for field ctr_ref_dvdd_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_dvdd_active_field ctr_ref_dvdd_active_field
 * @brief macros for field ctr_ref_dvdd_active
 * @details Selects Active Mode DVDD Reference Voltage in 25mV steps (1.0V) 0x00 - 600mV 0x14 - 1.1V (default) 0x1a - 1.25V
 * @{
 */
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__SHIFT                                 14
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__WIDTH                                  5
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__MASK                         0x0007c000U
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007c000U) >> 14)
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0007c000U)
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007c000U) | (((uint32_t)(src) <<\
                    14) & 0x0007c000U)
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0007c000U)))
#define PMU_PMU6__CTR_REF_DVDD_ACTIVE__RESET_VALUE                  0x00000014U
/** @} */

/* macros for field ctr_ref_dvdd_hibernate */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_dvdd_hibernate_field ctr_ref_dvdd_hibernate_field
 * @brief macros for field ctr_ref_dvdd_hibernate
 * @details Selects Hibernate Mode DVDD Reference Voltage in 25mV steps (0.8V) 0x00 - 600mV 0x10 - 800mV (default) 0x1a - 1.25V
 * @{
 */
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__SHIFT                              19
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__WIDTH                               5
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__MASK                      0x00f80000U
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f80000U) >> 19)
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00f80000U)
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f80000U) | (((uint32_t)(src) <<\
                    19) & 0x00f80000U)
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00f80000U)))
#define PMU_PMU6__CTR_REF_DVDD_HIBERNATE__RESET_VALUE               0x00000008U
/** @} */

/* macros for field ctr_ref_dvdd_retain */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_dvdd_retain_field ctr_ref_dvdd_retain_field
 * @brief macros for field ctr_ref_dvdd_retain
 * @details Selects Retain Mode DVDD Reference Voltage in 25mV steps (0.8V) 0x00 - 600mV 0x10 - 800mV (default) 0x1a - 1.25V
 * @{
 */
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__SHIFT                                 24
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__WIDTH                                  5
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__MASK                         0x1f000000U
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1f000000U) >> 24)
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x1f000000U)
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1f000000U) | (((uint32_t)(src) <<\
                    24) & 0x1f000000U)
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x1f000000U)))
#define PMU_PMU6__CTR_REF_DVDD_RETAIN__RESET_VALUE                  0x00000008U
/** @} */
#define PMU_PMU6__TYPE                                                 uint32_t
#define PMU_PMU6__READ                                              0x1fffffffU
#define PMU_PMU6__WRITE                                             0x1fffffffU
#define PMU_PMU6__PRESERVED                                         0x00000000U
#define PMU_PMU6__RESET_VALUE                                       0x08452455U

#endif /* __PMU_PMU6_MACRO__ */

/** @} end of pmu6 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu7 */
/**
 * @defgroup pmu_top_regs_core_pmu7 pmu7
 * @brief DVDD, AVDD, Brownout, LPComp and GADC Reference Controls definitions.
 * @{
 */
#ifndef __PMU_PMU7_MACRO__
#define __PMU_PMU7_MACRO__

/* macros for field ctr_ref_dvdd_socoff */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_dvdd_socoff_field ctr_ref_dvdd_socoff_field
 * @brief macros for field ctr_ref_dvdd_socoff
 * @details Selects SOC_OFF Mode DVDD Reference Voltage in 25mV steps (0.6V) -- Not used, DVDD off in this mode
 * @{
 */
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__SHIFT                                  0
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__WIDTH                                  5
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__MASK                         0x0000001fU
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define PMU_PMU7__CTR_REF_DVDD_SOCOFF__RESET_VALUE                  0x00000008U
/** @} */

/* macros for field ctr_ref_por_dvdd_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_dvdd_active_field ctr_ref_por_dvdd_active_field
 * @brief macros for field ctr_ref_por_dvdd_active
 * @details Selects Active Mode DVDD POR Reference Voltage in 100mV steps (0.85V) 0x0 - 450mV (default) 0x5 - 950mV 0x7 - 1.15V
 * @{
 */
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__SHIFT                              5
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__WIDTH                              3
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__MASK                     0x000000e0U
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000e0U) >> 5)
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000000e0U)
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000000e0U)))
#define PMU_PMU7__CTR_REF_POR_DVDD_ACTIVE__RESET_VALUE              0x00000005U
/** @} */

/* macros for field ctr_ref_por_dvdd_hibernate */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_dvdd_hibernate_field ctr_ref_por_dvdd_hibernate_field
 * @brief macros for field ctr_ref_por_dvdd_hibernate
 * @details Selects Hibernate Mode DVDD POR Reference Voltage in 100mV steps (0.55V) 0x0 - 450mV 0x2 - 650mV (default) 0x7 - 1.15V
 * @{
 */
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__SHIFT                           8
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__WIDTH                           3
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__MASK                  0x00000700U
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define PMU_PMU7__CTR_REF_POR_DVDD_HIBERNATE__RESET_VALUE           0x00000002U
/** @} */

/* macros for field ctr_ref_por_dvdd_retain */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_dvdd_retain_field ctr_ref_por_dvdd_retain_field
 * @brief macros for field ctr_ref_por_dvdd_retain
 * @details Selects Retain Mode DVDD POR Reference Voltage in 100mV steps (0.65V) 0x0 - 450mV 0x2 - 650mV (default) 0x7 - 1.15V
 * @{
 */
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__SHIFT                             11
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__WIDTH                              3
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__MASK                     0x00003800U
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define PMU_PMU7__CTR_REF_POR_DVDD_RETAIN__RESET_VALUE              0x00000002U
/** @} */

/* macros for field ctr_ref_por_dvdd_socoff */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_dvdd_socoff_field ctr_ref_por_dvdd_socoff_field
 * @brief macros for field ctr_ref_por_dvdd_socoff
 * @details Selects SOC OFF Mode DVDD POR Reference Voltage (0.85V) -- Not used, DVDD off in this mode
 * @{
 */
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__SHIFT                             14
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__WIDTH                              3
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__MASK                     0x0001c000U
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define PMU_PMU7__CTR_REF_POR_DVDD_SOCOFF__RESET_VALUE              0x00000004U
/** @} */

/* macros for field ctr_ref_avdd_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_avdd_active_field ctr_ref_avdd_active_field
 * @brief macros for field ctr_ref_avdd_active
 * @details Selects Active Mode AVDD Reference Voltage in 25mV steps(1.0V) 0x0 - 900mV 0x4 - 1.0V (default) 0x7 - 1.075V
 * @{
 */
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__SHIFT                                 17
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__WIDTH                                  3
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__MASK                         0x000e0000U
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000e0000U) >> 17)
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x000e0000U)
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000e0000U) | (((uint32_t)(src) <<\
                    17) & 0x000e0000U)
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x000e0000U)))
#define PMU_PMU7__CTR_REF_AVDD_ACTIVE__RESET_VALUE                  0x00000004U
/** @} */

/* macros for field ctr_ref_avdd_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_avdd_LP_field ctr_ref_avdd_LP_field
 * @brief macros for field ctr_ref_avdd_LP
 * @details Selects LP Mode AVDD Reference Voltage in 25mV steps (1.0V) 0x0 - 900mV 0x4 - 1.0V (default) 0x7 - 1.075V
 * @{
 */
#define PMU_PMU7__CTR_REF_AVDD_LP__SHIFT                                     20
#define PMU_PMU7__CTR_REF_AVDD_LP__WIDTH                                      3
#define PMU_PMU7__CTR_REF_AVDD_LP__MASK                             0x00700000U
#define PMU_PMU7__CTR_REF_AVDD_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00700000U) >> 20)
#define PMU_PMU7__CTR_REF_AVDD_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00700000U)
#define PMU_PMU7__CTR_REF_AVDD_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00700000U) | (((uint32_t)(src) <<\
                    20) & 0x00700000U)
#define PMU_PMU7__CTR_REF_AVDD_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00700000U)))
#define PMU_PMU7__CTR_REF_AVDD_LP__RESET_VALUE                      0x00000004U
/** @} */

/* macros for field ctr_ref_por_avdd_active */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_avdd_active_field ctr_ref_por_avdd_active_field
 * @brief macros for field ctr_ref_por_avdd_active
 * @details Selects Active Mode AVDD POR Reference Voltage in 25mV steps (0.85V) 0x0 - 750mV 0x4 - 850mV (default) 0x7 - 925mV
 * @{
 */
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__SHIFT                             23
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__WIDTH                              3
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__MASK                     0x03800000U
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03800000U) >> 23)
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x03800000U)
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03800000U) | (((uint32_t)(src) <<\
                    23) & 0x03800000U)
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x03800000U)))
#define PMU_PMU7__CTR_REF_POR_AVDD_ACTIVE__RESET_VALUE              0x00000004U
/** @} */

/* macros for field ctr_ref_por_avdd_LP */
/**
 * @defgroup pmu_top_regs_core_ctr_ref_por_avdd_LP_field ctr_ref_por_avdd_LP_field
 * @brief macros for field ctr_ref_por_avdd_LP
 * @details Selects LP Mode AVDD POR Reference Voltage in 25mV steps (0.85V) 0x0 - 750mV 0x4 - 850mV (default) 0x7 - 925mV
 * @{
 */
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__SHIFT                                 26
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__WIDTH                                  3
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__MASK                         0x1c000000U
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1c000000U) >> 26)
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x1c000000U)
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1c000000U) | (((uint32_t)(src) <<\
                    26) & 0x1c000000U)
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x1c000000U)))
#define PMU_PMU7__CTR_REF_POR_AVDD_LP__RESET_VALUE                  0x00000004U
/** @} */
#define PMU_PMU7__TYPE                                                 uint32_t
#define PMU_PMU7__READ                                              0x1fffffffU
#define PMU_PMU7__WRITE                                             0x1fffffffU
#define PMU_PMU7__PRESERVED                                         0x00000000U
#define PMU_PMU7__RESET_VALUE                                       0x124912a8U

#endif /* __PMU_PMU7_MACRO__ */

/** @} end of pmu7 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu8 */
/**
 * @defgroup pmu_top_regs_core_pmu8 pmu8
 * @brief Switcher swREG Control Signals_1 definitions.
 * @{
 */
#ifndef __PMU_PMU8_MACRO__
#define __PMU_PMU8_MACRO__

/* macros for field lowPwr_sw_ovr */
/**
 * @defgroup pmu_top_regs_core_lowPwr_sw_ovr_field lowPwr_sw_ovr_field
 * @brief macros for field lowPwr_sw_ovr
 * @details Switcher Low Power Override
 * @{
 */
#define PMU_PMU8__LOWPWR_SW_OVR__SHIFT                                        0
#define PMU_PMU8__LOWPWR_SW_OVR__WIDTH                                        1
#define PMU_PMU8__LOWPWR_SW_OVR__MASK                               0x00000001U
#define PMU_PMU8__LOWPWR_SW_OVR__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU8__LOWPWR_SW_OVR__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU8__LOWPWR_SW_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU8__LOWPWR_SW_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU8__LOWPWR_SW_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU8__LOWPWR_SW_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU8__LOWPWR_SW_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field lowPwr_sw_ovr_val */
/**
 * @defgroup pmu_top_regs_core_lowPwr_sw_ovr_val_field lowPwr_sw_ovr_val_field
 * @brief macros for field lowPwr_sw_ovr_val
 * @details Switcher Low Power Override Value
 * @{
 */
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__SHIFT                                    1
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__WIDTH                                    1
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__MASK                           0x00000002U
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU8__LOWPWR_SW_OVR_VAL__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field powerdownsys_sw */
/**
 * @defgroup pmu_top_regs_core_powerdownsys_sw_field powerdownsys_sw_field
 * @brief macros for field powerdownsys_sw
 * @details system power down pin thru the register, work with powerdownstartH
 * @{
 */
#define PMU_PMU8__POWERDOWNSYS_SW__SHIFT                                      2
#define PMU_PMU8__POWERDOWNSYS_SW__WIDTH                                      1
#define PMU_PMU8__POWERDOWNSYS_SW__MASK                             0x00000004U
#define PMU_PMU8__POWERDOWNSYS_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU8__POWERDOWNSYS_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU8__POWERDOWNSYS_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU8__POWERDOWNSYS_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU8__POWERDOWNSYS_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU8__POWERDOWNSYS_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU8__POWERDOWNSYS_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field div3en_sw */
/**
 * @defgroup pmu_top_regs_core_div3en_sw_field div3en_sw_field
 * @brief macros for field div3en_sw
 * @details Enable div3 ladder (boost mode only)
 * @{
 */
#define PMU_PMU8__DIV3EN_SW__SHIFT                                            3
#define PMU_PMU8__DIV3EN_SW__WIDTH                                            1
#define PMU_PMU8__DIV3EN_SW__MASK                                   0x00000008U
#define PMU_PMU8__DIV3EN_SW__READ(src)   (((uint32_t)(src) & 0x00000008U) >> 3)
#define PMU_PMU8__DIV3EN_SW__WRITE(src)  (((uint32_t)(src) << 3) & 0x00000008U)
#define PMU_PMU8__DIV3EN_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU8__DIV3EN_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU8__DIV3EN_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU8__DIV3EN_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU8__DIV3EN_SW__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field hpwrcompsEn_sw */
/**
 * @defgroup pmu_top_regs_core_hpwrcompsEn_sw_field hpwrcompsEn_sw_field
 * @brief macros for field hpwrcompsEn_sw
 * @details Enable the high pwr LCM/HCM comps
 * @{
 */
#define PMU_PMU8__HPWRCOMPSEN_SW__SHIFT                                       4
#define PMU_PMU8__HPWRCOMPSEN_SW__WIDTH                                       1
#define PMU_PMU8__HPWRCOMPSEN_SW__MASK                              0x00000010U
#define PMU_PMU8__HPWRCOMPSEN_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU8__HPWRCOMPSEN_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU8__HPWRCOMPSEN_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU8__HPWRCOMPSEN_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU8__HPWRCOMPSEN_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU8__HPWRCOMPSEN_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU8__HPWRCOMPSEN_SW__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field repBiasItuneBck_sw */
/**
 * @defgroup pmu_top_regs_core_repBiasItuneBck_sw_field repBiasItuneBck_sw_field
 * @brief macros for field repBiasItuneBck_sw
 * @details bias setting for peak current DAC in buck mode (cairo1u)
 * @{
 */
#define PMU_PMU8__REPBIASITUNEBCK_SW__SHIFT                                   5
#define PMU_PMU8__REPBIASITUNEBCK_SW__WIDTH                                   4
#define PMU_PMU8__REPBIASITUNEBCK_SW__MASK                          0x000001e0U
#define PMU_PMU8__REPBIASITUNEBCK_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001e0U) >> 5)
#define PMU_PMU8__REPBIASITUNEBCK_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000001e0U)
#define PMU_PMU8__REPBIASITUNEBCK_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001e0U) | (((uint32_t)(src) <<\
                    5) & 0x000001e0U)
#define PMU_PMU8__REPBIASITUNEBCK_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000001e0U)))
#define PMU_PMU8__REPBIASITUNEBCK_SW__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field repBiasItuneBst_sw */
/**
 * @defgroup pmu_top_regs_core_repBiasItuneBst_sw_field repBiasItuneBst_sw_field
 * @brief macros for field repBiasItuneBst_sw
 * @details bias setting for peak current DAC in bst mode (cairo1u)
 * @{
 */
#define PMU_PMU8__REPBIASITUNEBST_SW__SHIFT                                   9
#define PMU_PMU8__REPBIASITUNEBST_SW__WIDTH                                   4
#define PMU_PMU8__REPBIASITUNEBST_SW__MASK                          0x00001e00U
#define PMU_PMU8__REPBIASITUNEBST_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
#define PMU_PMU8__REPBIASITUNEBST_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00001e00U)
#define PMU_PMU8__REPBIASITUNEBST_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001e00U) | (((uint32_t)(src) <<\
                    9) & 0x00001e00U)
#define PMU_PMU8__REPBIASITUNEBST_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00001e00U)))
#define PMU_PMU8__REPBIASITUNEBST_SW__RESET_VALUE                   0x00000004U
/** @} */

/* macros for field swNonBtst */
/**
 * @defgroup pmu_top_regs_core_swNonBtst_field swNonBtst_field
 * @brief macros for field swNonBtst
 * @details test modes for Nswitch
 * @{
 */
#define PMU_PMU8__SWNONBTST__SHIFT                                           13
#define PMU_PMU8__SWNONBTST__WIDTH                                            2
#define PMU_PMU8__SWNONBTST__MASK                                   0x00006000U
#define PMU_PMU8__SWNONBTST__READ(src)  (((uint32_t)(src) & 0x00006000U) >> 13)
#define PMU_PMU8__SWNONBTST__WRITE(src) (((uint32_t)(src) << 13) & 0x00006000U)
#define PMU_PMU8__SWNONBTST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00006000U) | (((uint32_t)(src) <<\
                    13) & 0x00006000U)
#define PMU_PMU8__SWNONBTST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00006000U)))
#define PMU_PMU8__SWNONBTST__RESET_VALUE                            0x00000003U
/** @} */

/* macros for field swPonBtst */
/**
 * @defgroup pmu_top_regs_core_swPonBtst_field swPonBtst_field
 * @brief macros for field swPonBtst
 * @details test modes for Pswitch
 * @{
 */
#define PMU_PMU8__SWPONBTST__SHIFT                                           15
#define PMU_PMU8__SWPONBTST__WIDTH                                            2
#define PMU_PMU8__SWPONBTST__MASK                                   0x00018000U
#define PMU_PMU8__SWPONBTST__READ(src)  (((uint32_t)(src) & 0x00018000U) >> 15)
#define PMU_PMU8__SWPONBTST__WRITE(src) (((uint32_t)(src) << 15) & 0x00018000U)
#define PMU_PMU8__SWPONBTST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00018000U) | (((uint32_t)(src) <<\
                    15) & 0x00018000U)
#define PMU_PMU8__SWPONBTST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00018000U)))
#define PMU_PMU8__SWPONBTST__RESET_VALUE                            0x00000003U
/** @} */

/* macros for field swNonOverDelSel */
/**
 * @defgroup pmu_top_regs_core_swNonOverDelSel_field swNonOverDelSel_field
 * @brief macros for field swNonOverDelSel
 * @details setting for nonOverlap guard time between N/P switches
 * @{
 */
#define PMU_PMU8__SWNONOVERDELSEL__SHIFT                                     17
#define PMU_PMU8__SWNONOVERDELSEL__WIDTH                                      2
#define PMU_PMU8__SWNONOVERDELSEL__MASK                             0x00060000U
#define PMU_PMU8__SWNONOVERDELSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define PMU_PMU8__SWNONOVERDELSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define PMU_PMU8__SWNONOVERDELSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define PMU_PMU8__SWNONOVERDELSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define PMU_PMU8__SWNONOVERDELSEL__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field reqdwnTEn_startup_sw */
/**
 * @defgroup pmu_top_regs_core_reqdwnTEn_startup_sw_field reqdwnTEn_startup_sw_field
 * @brief macros for field reqdwnTEn_startup_sw
 * @details Enable down time between request to limit in-rush current during startup
 * @{
 */
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__SHIFT                                19
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__WIDTH                                 1
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__MASK                        0x00080000U
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU8__REQDWNTEN_STARTUP_SW__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field bstShortCmpBias_sw */
/**
 * @defgroup pmu_top_regs_core_bstShortCmpBias_sw_field bstShortCmpBias_sw_field
 * @brief macros for field bstShortCmpBias_sw
 * @details biasing setting for boost short sensing comparator
 * @{
 */
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__SHIFT                                  20
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__WIDTH                                   2
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__MASK                          0x00300000U
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define PMU_PMU8__BSTSHORTCMPBIAS_SW__RESET_VALUE                   0x00000002U
/** @} */

/* macros for field porCmpBias_sw */
/**
 * @defgroup pmu_top_regs_core_porCmpBias_sw_field porCmpBias_sw_field
 * @brief macros for field porCmpBias_sw
 * @details biasing setting for por comparator
 * @{
 */
#define PMU_PMU8__PORCMPBIAS_SW__SHIFT                                       22
#define PMU_PMU8__PORCMPBIAS_SW__WIDTH                                        2
#define PMU_PMU8__PORCMPBIAS_SW__MASK                               0x00c00000U
#define PMU_PMU8__PORCMPBIAS_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define PMU_PMU8__PORCMPBIAS_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define PMU_PMU8__PORCMPBIAS_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define PMU_PMU8__PORCMPBIAS_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define PMU_PMU8__PORCMPBIAS_SW__RESET_VALUE                        0x00000002U
/** @} */

/* macros for field hyst_vrefReq_sw */
/**
 * @defgroup pmu_top_regs_core_hyst_vrefReq_sw_field hyst_vrefReq_sw_field
 * @brief macros for field hyst_vrefReq_sw
 * @details enable hyst on Vref side for Request comparator
 * @{
 */
#define PMU_PMU8__HYST_VREFREQ_SW__SHIFT                                     24
#define PMU_PMU8__HYST_VREFREQ_SW__WIDTH                                      1
#define PMU_PMU8__HYST_VREFREQ_SW__MASK                             0x01000000U
#define PMU_PMU8__HYST_VREFREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU8__HYST_VREFREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PMU_PMU8__HYST_VREFREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PMU_PMU8__HYST_VREFREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PMU_PMU8__HYST_VREFREQ_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU8__HYST_VREFREQ_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU8__HYST_VREFREQ_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field hyst_vsenReq_sw */
/**
 * @defgroup pmu_top_regs_core_hyst_vsenReq_sw_field hyst_vsenReq_sw_field
 * @brief macros for field hyst_vsenReq_sw
 * @details enable hyst on Vsen side for Request comparator
 * @{
 */
#define PMU_PMU8__HYST_VSENREQ_SW__SHIFT                                     25
#define PMU_PMU8__HYST_VSENREQ_SW__WIDTH                                      1
#define PMU_PMU8__HYST_VSENREQ_SW__MASK                             0x02000000U
#define PMU_PMU8__HYST_VSENREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU8__HYST_VSENREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PMU_PMU8__HYST_VSENREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PMU_PMU8__HYST_VSENREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PMU_PMU8__HYST_VSENREQ_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU8__HYST_VSENREQ_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU8__HYST_VSENREQ_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field ctr_cuHiEnReq_sw_ovr */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHiEnReq_sw_ovr_field ctr_cuHiEnReq_sw_ovr_field
 * @brief macros for field ctr_cuHiEnReq_sw_ovr
 * @details Adjust the bias during highpwr DAC the slow state, 0 for default slow curent 1 for 0 slow current
 * @{
 */
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__SHIFT                                26
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__WIDTH                                 1
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__MASK                        0x04000000U
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ctr_cuHiEnReq_sw_ovr_val */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHiEnReq_sw_ovr_val_field ctr_cuHiEnReq_sw_ovr_val_field
 * @brief macros for field ctr_cuHiEnReq_sw_ovr_val
 * @details Add comment
 * @{
 */
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__SHIFT                            27
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__WIDTH                             1
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__MASK                    0x08000000U
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU8__CTR_CUHIENREQ_SW_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_cuLowReq_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuLowReq_sw_field ctr_cuLowReq_sw_field
 * @brief macros for field ctr_cuLowReq_sw
 * @details Slow bias setting for all high pwr comp (1/4nA-1nA)
 * @{
 */
#define PMU_PMU8__CTR_CULOWREQ_SW__SHIFT                                     28
#define PMU_PMU8__CTR_CULOWREQ_SW__WIDTH                                      2
#define PMU_PMU8__CTR_CULOWREQ_SW__MASK                             0x30000000U
#define PMU_PMU8__CTR_CULOWREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define PMU_PMU8__CTR_CULOWREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define PMU_PMU8__CTR_CULOWREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define PMU_PMU8__CTR_CULOWREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define PMU_PMU8__CTR_CULOWREQ_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field lp_del_val */
/**
 * @defgroup pmu_top_regs_core_lp_del_val_field lp_del_val_field
 * @brief macros for field lp_del_val
 * @details setting for delay used instead of peaksense in lp mode
 * @{
 */
#define PMU_PMU8__LP_DEL_VAL__SHIFT                                          30
#define PMU_PMU8__LP_DEL_VAL__WIDTH                                           2
#define PMU_PMU8__LP_DEL_VAL__MASK                                  0xc0000000U
#define PMU_PMU8__LP_DEL_VAL__READ(src) (((uint32_t)(src) & 0xc0000000U) >> 30)
#define PMU_PMU8__LP_DEL_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define PMU_PMU8__LP_DEL_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define PMU_PMU8__LP_DEL_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define PMU_PMU8__LP_DEL_VAL__RESET_VALUE                           0x00000001U
/** @} */
#define PMU_PMU8__TYPE                                                 uint32_t
#define PMU_PMU8__READ                                              0xffffffffU
#define PMU_PMU8__WRITE                                             0xffffffffU
#define PMU_PMU8__PRESERVED                                         0x00000000U
#define PMU_PMU8__RESET_VALUE                                       0x40a3e830U

#endif /* __PMU_PMU8_MACRO__ */

/** @} end of pmu8 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu9 */
/**
 * @defgroup pmu_top_regs_core_pmu9 pmu9
 * @brief Switcher swREG Control Signals_2 definitions.
 * @{
 */
#ifndef __PMU_PMU9_MACRO__
#define __PMU_PMU9_MACRO__

/* macros for field ctr_cuMidReq_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuMidReq_sw_field ctr_cuMidReq_sw_field
 * @brief macros for field ctr_cuMidReq_sw
 * @details Slow bias setting for all high pwr comp (1nA-20nA)
 * @{
 */
#define PMU_PMU9__CTR_CUMIDREQ_SW__SHIFT                                      0
#define PMU_PMU9__CTR_CUMIDREQ_SW__WIDTH                                      3
#define PMU_PMU9__CTR_CUMIDREQ_SW__MASK                             0x00000007U
#define PMU_PMU9__CTR_CUMIDREQ_SW__READ(src)    ((uint32_t)(src) & 0x00000007U)
#define PMU_PMU9__CTR_CUMIDREQ_SW__WRITE(src)   ((uint32_t)(src) & 0x00000007U)
#define PMU_PMU9__CTR_CUMIDREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define PMU_PMU9__CTR_CUMIDREQ_SW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define PMU_PMU9__CTR_CUMIDREQ_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field ctr_cuHighReq_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHighReq_sw_field ctr_cuHighReq_sw_field
 * @brief macros for field ctr_cuHighReq_sw
 * @details Fast Bias setting for Req comp (from resistor DAC)
 * @{
 */
#define PMU_PMU9__CTR_CUHIGHREQ_SW__SHIFT                                     3
#define PMU_PMU9__CTR_CUHIGHREQ_SW__WIDTH                                     2
#define PMU_PMU9__CTR_CUHIGHREQ_SW__MASK                            0x00000018U
#define PMU_PMU9__CTR_CUHIGHREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000018U) >> 3)
#define PMU_PMU9__CTR_CUHIGHREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000018U)
#define PMU_PMU9__CTR_CUHIGHREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000018U) | (((uint32_t)(src) <<\
                    3) & 0x00000018U)
#define PMU_PMU9__CTR_CUHIGHREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000018U)))
#define PMU_PMU9__CTR_CUHIGHREQ_SW__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field ctr_cuFastReq_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuFastReq_sw_field ctr_cuFastReq_sw_field
 * @brief macros for field ctr_cuFastReq_sw
 * @details Fast Bias setting for Req comp (from uA reference)
 * @{
 */
#define PMU_PMU9__CTR_CUFASTREQ_SW__SHIFT                                     5
#define PMU_PMU9__CTR_CUFASTREQ_SW__WIDTH                                     2
#define PMU_PMU9__CTR_CUFASTREQ_SW__MASK                            0x00000060U
#define PMU_PMU9__CTR_CUFASTREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000060U) >> 5)
#define PMU_PMU9__CTR_CUFASTREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000060U)
#define PMU_PMU9__CTR_CUFASTREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define PMU_PMU9__CTR_CUFASTREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define PMU_PMU9__CTR_CUFASTREQ_SW__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field zeroFastcu_bReq_sw */
/**
 * @defgroup pmu_top_regs_core_zeroFastcu_bReq_sw_field zeroFastcu_bReq_sw_field
 * @brief macros for field zeroFastcu_bReq_sw
 * @details Enable Fast bias setting for Req comp
 * @{
 */
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__SHIFT                                   7
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__WIDTH                                   1
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__MASK                          0x00000080U
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU9__ZEROFASTCU_BREQ_SW__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field ctr_decslowcuReq_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_decslowcuReq_sw_field ctr_decslowcuReq_sw_field
 * @brief macros for field ctr_decslowcuReq_sw
 * @details Enable the cuMid setting for Req comp for slow mode
 * @{
 */
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__SHIFT                                  8
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__WIDTH                                  1
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__MASK                         0x00000100U
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU9__CTR_DECSLOWCUREQ_SW__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field bypassCompReq_sw */
/**
 * @defgroup pmu_top_regs_core_bypassCompReq_sw_field bypassCompReq_sw_field
 * @brief macros for field bypassCompReq_sw
 * @details 0 Req comp output is valid, 1 comp's output is forced low
 * @{
 */
#define PMU_PMU9__BYPASSCOMPREQ_SW__SHIFT                                     9
#define PMU_PMU9__BYPASSCOMPREQ_SW__WIDTH                                     1
#define PMU_PMU9__BYPASSCOMPREQ_SW__MASK                            0x00000200U
#define PMU_PMU9__BYPASSCOMPREQ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU9__BYPASSCOMPREQ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU9__BYPASSCOMPREQ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU9__BYPASSCOMPREQ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU9__BYPASSCOMPREQ_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU9__BYPASSCOMPREQ_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU9__BYPASSCOMPREQ_SW__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field hpwrvbat1tst_sw */
/**
 * @defgroup pmu_top_regs_core_hpwrvbat1tst_sw_field hpwrvbat1tst_sw_field
 * @brief macros for field hpwrvbat1tst_sw
 * @details test control bit to gate off the fast current from resistor DAC for reqCmp
 * @{
 */
#define PMU_PMU9__HPWRVBAT1TST_SW__SHIFT                                     10
#define PMU_PMU9__HPWRVBAT1TST_SW__WIDTH                                      1
#define PMU_PMU9__HPWRVBAT1TST_SW__MASK                             0x00000400U
#define PMU_PMU9__HPWRVBAT1TST_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU9__HPWRVBAT1TST_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU9__HPWRVBAT1TST_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU9__HPWRVBAT1TST_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU9__HPWRVBAT1TST_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU9__HPWRVBAT1TST_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU9__HPWRVBAT1TST_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field calCmpEn_sw */
/**
 * @defgroup pmu_top_regs_core_calCmpEn_sw_field calCmpEn_sw_field
 * @brief macros for field calCmpEn_sw
 * @details To bypass the input of L/HCM comparator for calibation purpose, L->gnd, H->vmax
 * @{
 */
#define PMU_PMU9__CALCMPEN_SW__SHIFT                                         11
#define PMU_PMU9__CALCMPEN_SW__WIDTH                                          2
#define PMU_PMU9__CALCMPEN_SW__MASK                                 0x00001800U
#define PMU_PMU9__CALCMPEN_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define PMU_PMU9__CALCMPEN_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define PMU_PMU9__CALCMPEN_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define PMU_PMU9__CALCMPEN_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define PMU_PMU9__CALCMPEN_SW__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field calCmpOByp_sw */
/**
 * @defgroup pmu_top_regs_core_calCmpOByp_sw_field calCmpOByp_sw_field
 * @brief macros for field calCmpOByp_sw
 * @details To gate off the output of L/HCM comparator for calibration, breaking the loop
 * @{
 */
#define PMU_PMU9__CALCMPOBYP_SW__SHIFT                                       13
#define PMU_PMU9__CALCMPOBYP_SW__WIDTH                                        2
#define PMU_PMU9__CALCMPOBYP_SW__MASK                               0x00006000U
#define PMU_PMU9__CALCMPOBYP_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00006000U) >> 13)
#define PMU_PMU9__CALCMPOBYP_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00006000U)
#define PMU_PMU9__CALCMPOBYP_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00006000U) | (((uint32_t)(src) <<\
                    13) & 0x00006000U)
#define PMU_PMU9__CALCMPOBYP_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00006000U)))
#define PMU_PMU9__CALCMPOBYP_SW__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field resdivOff_sw_ovr */
/**
 * @defgroup pmu_top_regs_core_resdivOff_sw_ovr_field resdivOff_sw_ovr_field
 * @brief macros for field resdivOff_sw_ovr
 * @details Turn off the resistor divider override
 * @{
 */
#define PMU_PMU9__RESDIVOFF_SW_OVR__SHIFT                                    15
#define PMU_PMU9__RESDIVOFF_SW_OVR__WIDTH                                     1
#define PMU_PMU9__RESDIVOFF_SW_OVR__MASK                            0x00008000U
#define PMU_PMU9__RESDIVOFF_SW_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU9__RESDIVOFF_SW_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU9__RESDIVOFF_SW_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU9__RESDIVOFF_SW_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU9__RESDIVOFF_SW_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU9__RESDIVOFF_SW_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU9__RESDIVOFF_SW_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field resdivOff_sw_ovr_val */
/**
 * @defgroup pmu_top_regs_core_resdivOff_sw_ovr_val_field resdivOff_sw_ovr_val_field
 * @brief macros for field resdivOff_sw_ovr_val
 * @details turn off the resistor divider override val
 * @{
 */
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__SHIFT                                16
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__WIDTH                                 1
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__MASK                        0x00010000U
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU9__RESDIVOFF_SW_OVR_VAL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field resdivOffsw_sw_ovr */
/**
 * @defgroup pmu_top_regs_core_resdivOffsw_sw_ovr_field resdivOffsw_sw_ovr_field
 * @brief macros for field resdivOffsw_sw_ovr
 * @details Turn off the switches connected to the resistor divider override
 * @{
 */
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__SHIFT                                  17
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__WIDTH                                   1
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__MASK                          0x00020000U
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field resdivOffsw_sw_ovr_val */
/**
 * @defgroup pmu_top_regs_core_resdivOffsw_sw_ovr_val_field resdivOffsw_sw_ovr_val_field
 * @brief macros for field resdivOffsw_sw_ovr_val
 * @details Turn off the switches connected to the resistor divider override value
 * @{
 */
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__SHIFT                              18
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__WIDTH                               1
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__MASK                      0x00040000U
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU9__RESDIVOFFSW_SW_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field atb_sel_sw */
/**
 * @defgroup pmu_top_regs_core_atb_sel_sw_field atb_sel_sw_field
 * @brief macros for field atb_sel_sw
 * @details Analog testbus selection bit
 * @{
 */
#define PMU_PMU9__ATB_SEL_SW__SHIFT                                          19
#define PMU_PMU9__ATB_SEL_SW__WIDTH                                           4
#define PMU_PMU9__ATB_SEL_SW__MASK                                  0x00780000U
#define PMU_PMU9__ATB_SEL_SW__READ(src) (((uint32_t)(src) & 0x00780000U) >> 19)
#define PMU_PMU9__ATB_SEL_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00780000U)
#define PMU_PMU9__ATB_SEL_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00780000U) | (((uint32_t)(src) <<\
                    19) & 0x00780000U)
#define PMU_PMU9__ATB_SEL_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00780000U)))
#define PMU_PMU9__ATB_SEL_SW__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field delayPkEn_sw */
/**
 * @defgroup pmu_top_regs_core_delayPkEn_sw_field delayPkEn_sw_field
 * @brief macros for field delayPkEn_sw
 * @details Enable the delay watchdog
 * @{
 */
#define PMU_PMU9__DELAYPKEN_SW__SHIFT                                        23
#define PMU_PMU9__DELAYPKEN_SW__WIDTH                                         1
#define PMU_PMU9__DELAYPKEN_SW__MASK                                0x00800000U
#define PMU_PMU9__DELAYPKEN_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU9__DELAYPKEN_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU9__DELAYPKEN_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU9__DELAYPKEN_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU9__DELAYPKEN_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU9__DELAYPKEN_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU9__DELAYPKEN_SW__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field sizeSW */
/**
 * @defgroup pmu_top_regs_core_sizeSW_field sizeSW_field
 * @brief macros for field sizeSW
 * @details Adjust the size of switches
 * @{
 */
#define PMU_PMU9__SIZESW__SHIFT                                              24
#define PMU_PMU9__SIZESW__WIDTH                                               2
#define PMU_PMU9__SIZESW__MASK                                      0x03000000U
#define PMU_PMU9__SIZESW__READ(src)     (((uint32_t)(src) & 0x03000000U) >> 24)
#define PMU_PMU9__SIZESW__WRITE(src)    (((uint32_t)(src) << 24) & 0x03000000U)
#define PMU_PMU9__SIZESW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define PMU_PMU9__SIZESW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define PMU_PMU9__SIZESW__RESET_VALUE                               0x00000001U
/** @} */

/* macros for field delaybckAdj_sw */
/**
 * @defgroup pmu_top_regs_core_delaybckAdj_sw_field delaybckAdj_sw_field
 * @brief macros for field delaybckAdj_sw
 * @details Additional buck Delay setting for the delay watchdog, adjusted based on mode and inductor value
 * @{
 */
#define PMU_PMU9__DELAYBCKADJ_SW__SHIFT                                      26
#define PMU_PMU9__DELAYBCKADJ_SW__WIDTH                                       3
#define PMU_PMU9__DELAYBCKADJ_SW__MASK                              0x1c000000U
#define PMU_PMU9__DELAYBCKADJ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1c000000U) >> 26)
#define PMU_PMU9__DELAYBCKADJ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x1c000000U)
#define PMU_PMU9__DELAYBCKADJ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1c000000U) | (((uint32_t)(src) <<\
                    26) & 0x1c000000U)
#define PMU_PMU9__DELAYBCKADJ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x1c000000U)))
#define PMU_PMU9__DELAYBCKADJ_SW__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field delaybstAdj_sw */
/**
 * @defgroup pmu_top_regs_core_delaybstAdj_sw_field delaybstAdj_sw_field
 * @brief macros for field delaybstAdj_sw
 * @details Additional boost Delay setting for the delay watchdog, adjusted based on mode and inductor value
 * @{
 */
#define PMU_PMU9__DELAYBSTADJ_SW__SHIFT                                      29
#define PMU_PMU9__DELAYBSTADJ_SW__WIDTH                                       3
#define PMU_PMU9__DELAYBSTADJ_SW__MASK                              0xe0000000U
#define PMU_PMU9__DELAYBSTADJ_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define PMU_PMU9__DELAYBSTADJ_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define PMU_PMU9__DELAYBSTADJ_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define PMU_PMU9__DELAYBSTADJ_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
#define PMU_PMU9__DELAYBSTADJ_SW__RESET_VALUE                       0x00000004U
/** @} */
#define PMU_PMU9__TYPE                                                 uint32_t
#define PMU_PMU9__READ                                              0xffffffffU
#define PMU_PMU9__WRITE                                             0xffffffffU
#define PMU_PMU9__PRESERVED                                         0x00000000U
#define PMU_PMU9__RESET_VALUE                                       0x818000a0U

#endif /* __PMU_PMU9_MACRO__ */

/** @} end of pmu9 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu10 */
/**
 * @defgroup pmu_top_regs_core_pmu10 pmu10
 * @brief Switcher swREG Control Signals_3 definitions.
 * @{
 */
#ifndef __PMU_PMU10_MACRO__
#define __PMU_PMU10_MACRO__

/* macros for field delayLngEn_sw_ovr */
/**
 * @defgroup pmu_top_regs_core_delayLngEn_sw_ovr_field delayLngEn_sw_ovr_field
 * @brief macros for field delayLngEn_sw_ovr
 * @details Delay setting for the delay watchdog base cell, adjusted based on startup and lowpwr mode
 * @{
 */
#define PMU_PMU10__DELAYLNGEN_SW_OVR__SHIFT                                   0
#define PMU_PMU10__DELAYLNGEN_SW_OVR__WIDTH                                   1
#define PMU_PMU10__DELAYLNGEN_SW_OVR__MASK                          0x00000001U
#define PMU_PMU10__DELAYLNGEN_SW_OVR__READ(src) ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU10__DELAYLNGEN_SW_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU10__DELAYLNGEN_SW_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU10__DELAYLNGEN_SW_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU10__DELAYLNGEN_SW_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU10__DELAYLNGEN_SW_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU10__DELAYLNGEN_SW_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field delayLngEn_sw_ovr_val */
/**
 * @defgroup pmu_top_regs_core_delayLngEn_sw_ovr_val_field delayLngEn_sw_ovr_val_field
 * @brief macros for field delayLngEn_sw_ovr_val
 * @details Add comment
 * @{
 */
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__SHIFT                               1
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__WIDTH                               1
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__MASK                      0x00000002U
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU10__DELAYLNGEN_SW_OVR_VAL__RESET_VALUE               0x00000001U
/** @} */

/* macros for field hyst_vrefHcm_sw */
/**
 * @defgroup pmu_top_regs_core_hyst_vrefHcm_sw_field hyst_vrefHcm_sw_field
 * @brief macros for field hyst_vrefHcm_sw
 * @details enable hyst on Vref side for HCMcomparator
 * @{
 */
#define PMU_PMU10__HYST_VREFHCM_SW__SHIFT                                     2
#define PMU_PMU10__HYST_VREFHCM_SW__WIDTH                                     1
#define PMU_PMU10__HYST_VREFHCM_SW__MASK                            0x00000004U
#define PMU_PMU10__HYST_VREFHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU10__HYST_VREFHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU10__HYST_VREFHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU10__HYST_VREFHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU10__HYST_VREFHCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU10__HYST_VREFHCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU10__HYST_VREFHCM_SW__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field hyst_vsenHcm_sw */
/**
 * @defgroup pmu_top_regs_core_hyst_vsenHcm_sw_field hyst_vsenHcm_sw_field
 * @brief macros for field hyst_vsenHcm_sw
 * @details enable hyst on Vsen side for HCMcomparator
 * @{
 */
#define PMU_PMU10__HYST_VSENHCM_SW__SHIFT                                     3
#define PMU_PMU10__HYST_VSENHCM_SW__WIDTH                                     1
#define PMU_PMU10__HYST_VSENHCM_SW__MASK                            0x00000008U
#define PMU_PMU10__HYST_VSENHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU10__HYST_VSENHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU10__HYST_VSENHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU10__HYST_VSENHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU10__HYST_VSENHCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU10__HYST_VSENHCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU10__HYST_VSENHCM_SW__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field ctr_cuHiEnHcm_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHiEnHcm_sw_field ctr_cuHiEnHcm_sw_field
 * @brief macros for field ctr_cuHiEnHcm_sw
 * @details Adjust the bias during highpwr DAC the slow state, 0 for default slow curent 1 for 0 slow current
 * @{
 */
#define PMU_PMU10__CTR_CUHIENHCM_SW__SHIFT                                    4
#define PMU_PMU10__CTR_CUHIENHCM_SW__WIDTH                                    1
#define PMU_PMU10__CTR_CUHIENHCM_SW__MASK                           0x00000010U
#define PMU_PMU10__CTR_CUHIENHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU10__CTR_CUHIENHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU10__CTR_CUHIENHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU10__CTR_CUHIENHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU10__CTR_CUHIENHCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU10__CTR_CUHIENHCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU10__CTR_CUHIENHCM_SW__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field ctr_cuHighHcm_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHighHcm_sw_field ctr_cuHighHcm_sw_field
 * @brief macros for field ctr_cuHighHcm_sw
 * @details Fast Bias setting for Hcm comp (from resistor DAC)
 * @{
 */
#define PMU_PMU10__CTR_CUHIGHHCM_SW__SHIFT                                    5
#define PMU_PMU10__CTR_CUHIGHHCM_SW__WIDTH                                    2
#define PMU_PMU10__CTR_CUHIGHHCM_SW__MASK                           0x00000060U
#define PMU_PMU10__CTR_CUHIGHHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000060U) >> 5)
#define PMU_PMU10__CTR_CUHIGHHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000060U)
#define PMU_PMU10__CTR_CUHIGHHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define PMU_PMU10__CTR_CUHIGHHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define PMU_PMU10__CTR_CUHIGHHCM_SW__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ctr_cuFastHcm_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuFastHcm_sw_field ctr_cuFastHcm_sw_field
 * @brief macros for field ctr_cuFastHcm_sw
 * @details Fast Bias setting for Hcm comp (from uA reference)
 * @{
 */
#define PMU_PMU10__CTR_CUFASTHCM_SW__SHIFT                                    7
#define PMU_PMU10__CTR_CUFASTHCM_SW__WIDTH                                    2
#define PMU_PMU10__CTR_CUFASTHCM_SW__MASK                           0x00000180U
#define PMU_PMU10__CTR_CUFASTHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000180U) >> 7)
#define PMU_PMU10__CTR_CUFASTHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000180U)
#define PMU_PMU10__CTR_CUFASTHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000180U) | (((uint32_t)(src) <<\
                    7) & 0x00000180U)
#define PMU_PMU10__CTR_CUFASTHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000180U)))
#define PMU_PMU10__CTR_CUFASTHCM_SW__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field zeroFastcu_bHcm_sw */
/**
 * @defgroup pmu_top_regs_core_zeroFastcu_bHcm_sw_field zeroFastcu_bHcm_sw_field
 * @brief macros for field zeroFastcu_bHcm_sw
 * @details Enable Fast bias setting for HCM comp
 * @{
 */
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__SHIFT                                  9
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__WIDTH                                  1
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__MASK                         0x00000200U
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU10__ZEROFASTCU_BHCM_SW__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field ctr_decslowcuHcm_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_decslowcuHcm_sw_field ctr_decslowcuHcm_sw_field
 * @brief macros for field ctr_decslowcuHcm_sw
 * @details Disable the cuMid setting for HCM comp
 * @{
 */
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__SHIFT                                10
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__WIDTH                                 1
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__MASK                        0x00000400U
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU10__CTR_DECSLOWCUHCM_SW__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field hpwrvbat1tstHcm_sw */
/**
 * @defgroup pmu_top_regs_core_hpwrvbat1tstHcm_sw_field hpwrvbat1tstHcm_sw_field
 * @brief macros for field hpwrvbat1tstHcm_sw
 * @details test control bit to gate off the fast current from resistor DAC for HCM cmp
 * @{
 */
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__SHIFT                                 11
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__WIDTH                                  1
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__MASK                         0x00000800U
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU10__HPWRVBAT1TSTHCM_SW__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field rcalHcm_sw */
/**
 * @defgroup pmu_top_regs_core_rcalHcm_sw_field rcalHcm_sw_field
 * @brief macros for field rcalHcm_sw
 * @details offset cal DAC control for HCM comp
 * @{
 */
#define PMU_PMU10__RCALHCM_SW__SHIFT                                         12
#define PMU_PMU10__RCALHCM_SW__WIDTH                                          3
#define PMU_PMU10__RCALHCM_SW__MASK                                 0x00007000U
#define PMU_PMU10__RCALHCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define PMU_PMU10__RCALHCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define PMU_PMU10__RCALHCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define PMU_PMU10__RCALHCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define PMU_PMU10__RCALHCM_SW__RESET_VALUE                          0x00000003U
/** @} */

/* macros for field hystRefLcm_sw */
/**
 * @defgroup pmu_top_regs_core_hystRefLcm_sw_field hystRefLcm_sw_field
 * @brief macros for field hystRefLcm_sw
 * @details enable hyst on Vref side for LCMcomparator
 * @{
 */
#define PMU_PMU10__HYSTREFLCM_SW__SHIFT                                      15
#define PMU_PMU10__HYSTREFLCM_SW__WIDTH                                       1
#define PMU_PMU10__HYSTREFLCM_SW__MASK                              0x00008000U
#define PMU_PMU10__HYSTREFLCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU10__HYSTREFLCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU10__HYSTREFLCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU10__HYSTREFLCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU10__HYSTREFLCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU10__HYSTREFLCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU10__HYSTREFLCM_SW__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field hystSenLcm_sw */
/**
 * @defgroup pmu_top_regs_core_hystSenLcm_sw_field hystSenLcm_sw_field
 * @brief macros for field hystSenLcm_sw
 * @details enable hyst on Vsen side for LCMcomparator
 * @{
 */
#define PMU_PMU10__HYSTSENLCM_SW__SHIFT                                      16
#define PMU_PMU10__HYSTSENLCM_SW__WIDTH                                       1
#define PMU_PMU10__HYSTSENLCM_SW__MASK                              0x00010000U
#define PMU_PMU10__HYSTSENLCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU10__HYSTSENLCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU10__HYSTSENLCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU10__HYSTSENLCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU10__HYSTSENLCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU10__HYSTSENLCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU10__HYSTSENLCM_SW__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field refhystLcm_sw */
/**
 * @defgroup pmu_top_regs_core_refhystLcm_sw_field refhystLcm_sw_field
 * @brief macros for field refhystLcm_sw
 * @details Introduce hyst to LCM preamp
 * @{
 */
#define PMU_PMU10__REFHYSTLCM_SW__SHIFT                                      17
#define PMU_PMU10__REFHYSTLCM_SW__WIDTH                                       1
#define PMU_PMU10__REFHYSTLCM_SW__MASK                              0x00020000U
#define PMU_PMU10__REFHYSTLCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU10__REFHYSTLCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU10__REFHYSTLCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU10__REFHYSTLCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU10__REFHYSTLCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU10__REFHYSTLCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU10__REFHYSTLCM_SW__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field ctr_cuHiEnLcm_sw */
/**
 * @defgroup pmu_top_regs_core_ctr_cuHiEnLcm_sw_field ctr_cuHiEnLcm_sw_field
 * @brief macros for field ctr_cuHiEnLcm_sw
 * @details Adjust the bias during highpwr DAC the slow state, 0 for default slow curent 1 for 0 slow current
 * @{
 */
#define PMU_PMU10__CTR_CUHIENLCM_SW__SHIFT                                   18
#define PMU_PMU10__CTR_CUHIENLCM_SW__WIDTH                                    1
#define PMU_PMU10__CTR_CUHIENLCM_SW__MASK                           0x00040000U
#define PMU_PMU10__CTR_CUHIENLCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU10__CTR_CUHIENLCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU10__CTR_CUHIENLCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU10__CTR_CUHIENLCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU10__CTR_CUHIENLCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU10__CTR_CUHIENLCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU10__CTR_CUHIENLCM_SW__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field swregReserve */
/**
 * @defgroup pmu_top_regs_core_swregReserve_field swregReserve_field
 * @brief macros for field swregReserve
 * @details reserved (cairo1u)
 * @{
 */
#define PMU_PMU10__SWREGRESERVE__SHIFT                                       19
#define PMU_PMU10__SWREGRESERVE__WIDTH                                        2
#define PMU_PMU10__SWREGRESERVE__MASK                               0x00180000U
#define PMU_PMU10__SWREGRESERVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define PMU_PMU10__SWREGRESERVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define PMU_PMU10__SWREGRESERVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define PMU_PMU10__SWREGRESERVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define PMU_PMU10__SWREGRESERVE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field swRegPorEn */
/**
 * @defgroup pmu_top_regs_core_swRegPorEn_field swRegPorEn_field
 * @brief macros for field swRegPorEn
 * @details separate swReg POR from the swReg system pwd (cairo1u)
 * @{
 */
#define PMU_PMU10__SWREGPOREN__SHIFT                                         21
#define PMU_PMU10__SWREGPOREN__WIDTH                                          1
#define PMU_PMU10__SWREGPOREN__MASK                                 0x00200000U
#define PMU_PMU10__SWREGPOREN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU10__SWREGPOREN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PMU_PMU10__SWREGPOREN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PMU_PMU10__SWREGPOREN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PMU_PMU10__SWREGPOREN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU10__SWREGPOREN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU10__SWREGPOREN__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field softswRegpwd */
/**
 * @defgroup pmu_top_regs_core_softswRegpwd_field softswRegpwd_field
 * @brief macros for field softswRegpwd
 * @details soft power down for the swReg to avoid surge of current (cairo1u)
 * @{
 */
#define PMU_PMU10__SOFTSWREGPWD__SHIFT                                       22
#define PMU_PMU10__SOFTSWREGPWD__WIDTH                                        1
#define PMU_PMU10__SOFTSWREGPWD__MASK                               0x00400000U
#define PMU_PMU10__SOFTSWREGPWD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU10__SOFTSWREGPWD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PMU_PMU10__SOFTSWREGPWD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PMU_PMU10__SOFTSWREGPWD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PMU_PMU10__SOFTSWREGPWD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU10__SOFTSWREGPWD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU10__SOFTSWREGPWD__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field hpwrvbat1tstLcm_sw */
/**
 * @defgroup pmu_top_regs_core_hpwrvbat1tstLcm_sw_field hpwrvbat1tstLcm_sw_field
 * @brief macros for field hpwrvbat1tstLcm_sw
 * @details test control bit to gate off the fast current from resistor DAC for LCM cmp
 * @{
 */
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__SHIFT                                 23
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__WIDTH                                  1
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__MASK                         0x00800000U
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU10__HPWRVBAT1TSTLCM_SW__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field rcalLcm_sw */
/**
 * @defgroup pmu_top_regs_core_rcalLcm_sw_field rcalLcm_sw_field
 * @brief macros for field rcalLcm_sw
 * @details offset cal DAC control for lowCM comp
 * @{
 */
#define PMU_PMU10__RCALLCM_SW__SHIFT                                         24
#define PMU_PMU10__RCALLCM_SW__WIDTH                                          3
#define PMU_PMU10__RCALLCM_SW__MASK                                 0x07000000U
#define PMU_PMU10__RCALLCM_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define PMU_PMU10__RCALLCM_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define PMU_PMU10__RCALLCM_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define PMU_PMU10__RCALLCM_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define PMU_PMU10__RCALLCM_SW__RESET_VALUE                          0x00000003U
/** @} */

/* macros for field bstshortCmpReftst_sw */
/**
 * @defgroup pmu_top_regs_core_bstshortCmpReftst_sw_field bstshortCmpReftst_sw_field
 * @brief macros for field bstshortCmpReftst_sw
 * @details test control bit for boost short comp
 * @{
 */
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__SHIFT                               27
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__WIDTH                                1
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__MASK                       0x08000000U
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU10__BSTSHORTCMPREFTST_SW__RESET_VALUE                0x00000000U
/** @} */

/* macros for field pksenseEn_sw_ovr */
/**
 * @defgroup pmu_top_regs_core_pksenseEn_sw_ovr_field pksenseEn_sw_ovr_field
 * @brief macros for field pksenseEn_sw_ovr
 * @details Enable the replicaBias for pkSensing, and pass the output of peak Comp
 * @{
 */
#define PMU_PMU10__PKSENSEEN_SW_OVR__SHIFT                                   28
#define PMU_PMU10__PKSENSEEN_SW_OVR__WIDTH                                    1
#define PMU_PMU10__PKSENSEEN_SW_OVR__MASK                           0x10000000U
#define PMU_PMU10__PKSENSEEN_SW_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU10__PKSENSEEN_SW_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PMU_PMU10__PKSENSEEN_SW_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PMU_PMU10__PKSENSEEN_SW_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PMU_PMU10__PKSENSEEN_SW_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU10__PKSENSEEN_SW_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU10__PKSENSEEN_SW_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field pksenseEn_sw_ovr_val */
/**
 * @defgroup pmu_top_regs_core_pksenseEn_sw_ovr_val_field pksenseEn_sw_ovr_val_field
 * @brief macros for field pksenseEn_sw_ovr_val
 * @details Add comment
 * @{
 */
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__SHIFT                               29
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__WIDTH                                1
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__MASK                       0x20000000U
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU10__PKSENSEEN_SW_OVR_VAL__RESET_VALUE                0x00000001U
/** @} */
#define PMU_PMU10__TYPE                                                uint32_t
#define PMU_PMU10__READ                                             0x3fffffffU
#define PMU_PMU10__WRITE                                            0x3fffffffU
#define PMU_PMU10__PRESERVED                                        0x00000000U
#define PMU_PMU10__RESET_VALUE                                      0x2325b692U

#endif /* __PMU_PMU10_MACRO__ */

/** @} end of pmu10 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu11 */
/**
 * @defgroup pmu_top_regs_core_pmu11 pmu11
 * @brief VDDIO LDO Controls definitions.
 * @{
 */
#ifndef __PMU_PMU11_MACRO__
#define __PMU_PMU11_MACRO__

/* macros for field en_ldoLIvddio_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldoLIvddio_ovr_field en_ldoLIvddio_ovr_field
 * @brief macros for field en_ldoLIvddio_ovr
 * @details Enable VDDIO LDO override
 * @{
 */
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__SHIFT                                   0
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__WIDTH                                   1
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__MASK                          0x00000001U
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__READ(src) ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU11__EN_LDOLIVDDIO_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field en_ldoL1vddio_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1vddio_ovr_val_field en_ldoL1vddio_ovr_val_field
 * @brief macros for field en_ldoL1vddio_ovr_val
 * @details Enable VDDIO LDO value
 * @{
 */
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__SHIFT                               1
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__WIDTH                               1
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__MASK                      0x00000002U
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU11__EN_LDOL1VDDIO_OVR_VAL__RESET_VALUE               0x00000001U
/** @} */

/* macros for field ctr_ldoL1vddio_bypass */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1vddio_bypass_field ctr_ldoL1vddio_bypass_field
 * @brief macros for field ctr_ldoL1vddio_bypass
 * @details Bypass VDDIO LDO
 * @{
 */
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__SHIFT                               2
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__WIDTH                               1
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__MASK                      0x00000004U
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU11__CTR_LDOL1VDDIO_BYPASS__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ctr_prtbypcurr_vddio */
/**
 * @defgroup pmu_top_regs_core_ctr_prtbypcurr_vddio_field ctr_prtbypcurr_vddio_field
 * @brief macros for field ctr_prtbypcurr_vddio
 * @details enable short current protection for bypass LDO mode (disable sensing node)
 * @{
 */
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__SHIFT                                3
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__WIDTH                                1
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__MASK                       0x00000008U
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU11__CTR_PRTBYPCURR_VDDIO__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ctr_prtsatcurr_vddio */
/**
 * @defgroup pmu_top_regs_core_ctr_prtsatcurr_vddio_field ctr_prtsatcurr_vddio_field
 * @brief macros for field ctr_prtsatcurr_vddio
 * @details enable short current protection for active LDO mode
 * @{
 */
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__SHIFT                                4
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__WIDTH                                1
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__MASK                       0x00000010U
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU11__CTR_PRTSATCURR_VDDIO__RESET_VALUE                0x00000001U
/** @} */

/* macros for field ovr_bystop_vddio */
/**
 * @defgroup pmu_top_regs_core_ovr_bystop_vddio_field ovr_bystop_vddio_field
 * @brief macros for field ovr_bystop_vddio
 * @details bypass the short current protection in bypass mode (overide comparator)
 * @{
 */
#define PMU_PMU11__OVR_BYSTOP_VDDIO__SHIFT                                    5
#define PMU_PMU11__OVR_BYSTOP_VDDIO__WIDTH                                    1
#define PMU_PMU11__OVR_BYSTOP_VDDIO__MASK                           0x00000020U
#define PMU_PMU11__OVR_BYSTOP_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU11__OVR_BYSTOP_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU11__OVR_BYSTOP_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU11__OVR_BYSTOP_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU11__OVR_BYSTOP_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU11__OVR_BYSTOP_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU11__OVR_BYSTOP_VDDIO__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field porbsocvddio_ctrcuLow */
/**
 * @defgroup pmu_top_regs_core_porbsocvddio_ctrcuLow_field porbsocvddio_ctrcuLow_field
 * @brief macros for field porbsocvddio_ctrcuLow
 * @details por comparabor bias setting 200pA, 250pA 310pA 1nA
 * @{
 */
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__SHIFT                               6
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__WIDTH                               2
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__MASK                      0x000000c0U
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define PMU_PMU11__PORBSOCVDDIO_CTRCULOW__RESET_VALUE               0x00000002U
/** @} */

/* macros for field porbsocvddio_encomp */
/**
 * @defgroup pmu_top_regs_core_porbsocvddio_encomp_field porbsocvddio_encomp_field
 * @brief macros for field porbsocvddio_encomp
 * @details enable por comparator
 * @{
 */
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__SHIFT                                 8
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__WIDTH                                 1
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__MASK                        0x00000100U
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU11__PORBSOCVDDIO_ENCOMP__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field SwchReqVDDIO_DVDD_cuMid */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_DVDD_cuMid_field SwchReqVDDIO_DVDD_cuMid_field
 * @brief macros for field SwchReqVDDIO_DVDD_cuMid
 * @details bias setting for swRes comp from 1na to 20nA
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__SHIFT                             9
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__WIDTH                             3
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__MASK                    0x00000e00U
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define PMU_PMU11__SWCHREQVDDIO_DVDD_CUMID__RESET_VALUE             0x00000003U
/** @} */

/* macros for field SwchReqVDDIO_DVDD_decslowcu */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_DVDD_decslowcu_field SwchReqVDDIO_DVDD_decslowcu_field
 * @brief macros for field SwchReqVDDIO_DVDD_decslowcu
 * @details bias setting for swRes comp from 1na to 20nA
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__SHIFT                        12
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__WIDTH                         1
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__MASK                0x00001000U
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU11__SWCHREQVDDIO_DVDD_DECSLOWCU__RESET_VALUE         0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_encomp_ovr_field SwchReqVDDIO_encomp_ovr_field
 * @brief macros for field SwchReqVDDIO_encomp_ovr
 * @details enable the comp for swRes override SwchReqVDDIO_enswres
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__SHIFT                            13
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__WIDTH                             1
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__MASK                    0x00002000U
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_encomp_ovr_val_field SwchReqVDDIO_encomp_ovr_val_field
 * @brief macros for field SwchReqVDDIO_encomp_ovr_val
 * @details override SwchReqVDDIO_enswres val: avdd request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__SHIFT                        14
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__WIDTH                         1
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__MASK                0x00004000U
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU11__SWCHREQVDDIO_ENCOMP_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_enswres_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_enswres_ovr_field SwchReqVDDIO_enswres_ovr_field
 * @brief macros for field SwchReqVDDIO_enswres_ovr
 * @details relesse the swRes output, 0: force it down to low override SwchReqVDDIO_enswres
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__SHIFT                           15
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__WIDTH                            1
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__MASK                   0x00008000U
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_enswres_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_enswres_ovr_val_field SwchReqVDDIO_enswres_ovr_val_field
 * @brief macros for field SwchReqVDDIO_enswres_ovr_val
 * @details override SwchReqVDDIO_enswres val: avdd request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__SHIFT                       16
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__WIDTH                        1
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__MASK               0x00010000U
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU11__SWCHREQVDDIO_ENSWRES_OVR_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_ctr_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_ctr_ovr_field SwchReqVDDIO_ctr_ovr_field
 * @brief macros for field SwchReqVDDIO_ctr_ovr
 * @details turn on pmu_swRes (override)
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__SHIFT                               17
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__WIDTH                                1
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__MASK                       0x00020000U
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field SwchReqVDDIO_ctr_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqVDDIO_ctr_ovr_val_field SwchReqVDDIO_ctr_ovr_val_field
 * @brief macros for field SwchReqVDDIO_ctr_ovr_val
 * @details turn on pmu_swRes (override value)
 * @{
 */
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__SHIFT                           18
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__WIDTH                            1
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__MASK                   0x00040000U
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU11__SWCHREQVDDIO_CTR_OVR_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ctr_swresvddio_bypass */
/**
 * @defgroup pmu_top_regs_core_ctr_swresvddio_bypass_field ctr_swresvddio_bypass_field
 * @brief macros for field ctr_swresvddio_bypass
 * @details enable bypass sw in swRes
 * @{
 */
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__SHIFT                              19
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__WIDTH                               1
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__MASK                      0x00080000U
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU11__CTR_SWRESVDDIO_BYPASS__RESET_VALUE               0x00000000U
/** @} */
#define PMU_PMU11__TYPE                                                uint32_t
#define PMU_PMU11__READ                                             0x000fffffU
#define PMU_PMU11__WRITE                                            0x000fffffU
#define PMU_PMU11__PRESERVED                                        0x00000000U
#define PMU_PMU11__RESET_VALUE                                      0x00000792U

#endif /* __PMU_PMU11_MACRO__ */

/** @} end of pmu11 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu12 */
/**
 * @defgroup pmu_top_regs_core_pmu12 pmu12
 * @brief DVDD LDO controls definitions.
 * @{
 */
#ifndef __PMU_PMU12_MACRO__
#define __PMU_PMU12_MACRO__

/* macros for field en_ldoL1dvdd_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1dvdd_ovr_field en_ldoL1dvdd_ovr_field
 * @brief macros for field en_ldoL1dvdd_ovr
 * @details Enable DVDD LDO override
 * @{
 */
#define PMU_PMU12__EN_LDOL1DVDD_OVR__SHIFT                                    0
#define PMU_PMU12__EN_LDOL1DVDD_OVR__WIDTH                                    1
#define PMU_PMU12__EN_LDOL1DVDD_OVR__MASK                           0x00000001U
#define PMU_PMU12__EN_LDOL1DVDD_OVR__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU12__EN_LDOL1DVDD_OVR__WRITE(src) ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU12__EN_LDOL1DVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU12__EN_LDOL1DVDD_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU12__EN_LDOL1DVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU12__EN_LDOL1DVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU12__EN_LDOL1DVDD_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_ldoL1dvdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldoL1dvdd_ovr_val_field en_ldoL1dvdd_ovr_val_field
 * @brief macros for field en_ldoL1dvdd_ovr_val
 * @details Enable DVDD LDO
 * @{
 */
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__SHIFT                                1
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__WIDTH                                1
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__MASK                       0x00000002U
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU12__EN_LDOL1DVDD_OVR_VAL__RESET_VALUE                0x00000001U
/** @} */

/* macros for field ctr_ldoL1dvdd_bypass */
/**
 * @defgroup pmu_top_regs_core_ctr_ldoL1dvdd_bypass_field ctr_ldoL1dvdd_bypass_field
 * @brief macros for field ctr_ldoL1dvdd_bypass
 * @details Bypass DVDD LDO
 * @{
 */
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__SHIFT                                2
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__WIDTH                                1
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__MASK                       0x00000004U
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU12__CTR_LDOL1DVDD_BYPASS__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ctr_prtbypcurr_dvdd */
/**
 * @defgroup pmu_top_regs_core_ctr_prtbypcurr_dvdd_field ctr_prtbypcurr_dvdd_field
 * @brief macros for field ctr_prtbypcurr_dvdd
 * @details enable short current protection for bypass LDO mode (disable sensing node)
 * @{
 */
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__SHIFT                                 3
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__WIDTH                                 1
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__MASK                        0x00000008U
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU12__CTR_PRTBYPCURR_DVDD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ctr_prtsatcurr_dvdd */
/**
 * @defgroup pmu_top_regs_core_ctr_prtsatcurr_dvdd_field ctr_prtsatcurr_dvdd_field
 * @brief macros for field ctr_prtsatcurr_dvdd
 * @details enable short current protection for active LDO mode
 * @{
 */
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__SHIFT                                 4
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__WIDTH                                 1
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__MASK                        0x00000010U
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU12__CTR_PRTSATCURR_DVDD__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field ovr_bystop_dvdd */
/**
 * @defgroup pmu_top_regs_core_ovr_bystop_dvdd_field ovr_bystop_dvdd_field
 * @brief macros for field ovr_bystop_dvdd
 * @details bypass the short current protection in bypass mode (overide comparator)
 * @{
 */
#define PMU_PMU12__OVR_BYSTOP_DVDD__SHIFT                                     5
#define PMU_PMU12__OVR_BYSTOP_DVDD__WIDTH                                     1
#define PMU_PMU12__OVR_BYSTOP_DVDD__MASK                            0x00000020U
#define PMU_PMU12__OVR_BYSTOP_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU12__OVR_BYSTOP_DVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU12__OVR_BYSTOP_DVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU12__OVR_BYSTOP_DVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU12__OVR_BYSTOP_DVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU12__OVR_BYSTOP_DVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU12__OVR_BYSTOP_DVDD__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field porbsocdvdd_ctrcuLow */
/**
 * @defgroup pmu_top_regs_core_porbsocdvdd_ctrcuLow_field porbsocdvdd_ctrcuLow_field
 * @brief macros for field porbsocdvdd_ctrcuLow
 * @details bypass the short current protection in bypass mode (overide comparator)
 * @{
 */
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__SHIFT                                6
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__WIDTH                                2
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__MASK                       0x000000c0U
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define PMU_PMU12__PORBSOCDVDD_CTRCULOW__RESET_VALUE                0x00000002U
/** @} */

/* macros for field porbsocdvdd_encomp */
/**
 * @defgroup pmu_top_regs_core_porbsocdvdd_encomp_field porbsocdvdd_encomp_field
 * @brief macros for field porbsocdvdd_encomp
 * @details enable por comparator
 * @{
 */
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__SHIFT                                  8
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__WIDTH                                  1
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__MASK                         0x00000100U
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU12__PORBSOCDVDD_ENCOMP__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field SwchReqDVDD_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_encomp_ovr_field SwchReqDVDD_encomp_ovr_field
 * @brief macros for field SwchReqDVDD_encomp_ovr
 * @details enable the comp for swRes override SwchReqDVDD_enswres
 * @{
 */
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__SHIFT                              9
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__WIDTH                              1
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__MASK                     0x00000200U
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field SwchReqDVDD_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_encomp_ovr_val_field SwchReqDVDD_encomp_ovr_val_field
 * @brief macros for field SwchReqDVDD_encomp_ovr_val
 * @details override SwchReqDVDD_enswres val: avdd request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__SHIFT                         10
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__WIDTH                          1
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__MASK                 0x00000400U
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU12__SWCHREQDVDD_ENCOMP_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field SwchReqDVDD_enswres_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_enswres_ovr_field SwchReqDVDD_enswres_ovr_field
 * @brief macros for field SwchReqDVDD_enswres_ovr
 * @details relesse the swRes output, 0: force it down to low override SwchReqDVDD_enswres
 * @{
 */
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__SHIFT                            11
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__WIDTH                             1
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__MASK                    0x00000800U
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field SwchReqDVDD_enswres_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_enswres_ovr_val_field SwchReqDVDD_enswres_ovr_val_field
 * @brief macros for field SwchReqDVDD_enswres_ovr_val
 * @details override SwchReqDVDD_enswres val: avdd request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__SHIFT                        12
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__WIDTH                         1
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__MASK                0x00001000U
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU12__SWCHREQDVDD_ENSWRES_OVR_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field SwchReqDVDD_ctr_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_ctr_ovr_field SwchReqDVDD_ctr_ovr_field
 * @brief macros for field SwchReqDVDD_ctr_ovr
 * @details turn on pmu_swRes
 * @{
 */
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__SHIFT                                13
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__WIDTH                                 1
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__MASK                        0x00002000U
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field SwchReqDVDD_ctr_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqDVDD_ctr_ovr_val_field SwchReqDVDD_ctr_ovr_val_field
 * @brief macros for field SwchReqDVDD_ctr_ovr_val
 * @details Add comment
 * @{
 */
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__SHIFT                            14
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__WIDTH                             1
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__MASK                    0x00004000U
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU12__SWCHREQDVDD_CTR_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ctr_swresdvdd_bypass */
/**
 * @defgroup pmu_top_regs_core_ctr_swresdvdd_bypass_field ctr_swresdvdd_bypass_field
 * @brief macros for field ctr_swresdvdd_bypass
 * @details enable bypass sw in swRes
 * @{
 */
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__SHIFT                               15
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__WIDTH                                1
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__MASK                       0x00008000U
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU12__CTR_SWRESDVDD_BYPASS__RESET_VALUE                0x00000000U
/** @} */
#define PMU_PMU12__TYPE                                                uint32_t
#define PMU_PMU12__READ                                             0x0000ffffU
#define PMU_PMU12__WRITE                                            0x0000ffffU
#define PMU_PMU12__PRESERVED                                        0x00000000U
#define PMU_PMU12__RESET_VALUE                                      0x00000192U

#endif /* __PMU_PMU12_MACRO__ */

/** @} end of pmu12 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu13 */
/**
 * @defgroup pmu_top_regs_core_pmu13 pmu13
 * @brief AVDD LDO controls definitions.
 * @{
 */
#ifndef __PMU_PMU13_MACRO__
#define __PMU_PMU13_MACRO__

/* macros for field en_top_avdd_ovr */
/**
 * @defgroup pmu_top_regs_core_en_top_avdd_ovr_field en_top_avdd_ovr_field
 * @brief macros for field en_top_avdd_ovr
 * @details Enable AVDD LDO override
 * @{
 */
#define PMU_PMU13__EN_TOP_AVDD_OVR__SHIFT                                     0
#define PMU_PMU13__EN_TOP_AVDD_OVR__WIDTH                                     1
#define PMU_PMU13__EN_TOP_AVDD_OVR__MASK                            0x00000001U
#define PMU_PMU13__EN_TOP_AVDD_OVR__READ(src)   ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU13__EN_TOP_AVDD_OVR__WRITE(src)  ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU13__EN_TOP_AVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU13__EN_TOP_AVDD_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU13__EN_TOP_AVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU13__EN_TOP_AVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU13__EN_TOP_AVDD_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field en_top_avdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_top_avdd_ovr_val_field en_top_avdd_ovr_val_field
 * @brief macros for field en_top_avdd_ovr_val
 * @details Enable AVDD LDO override value
 * @{
 */
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__SHIFT                                 1
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__WIDTH                                 1
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__MASK                        0x00000002U
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU13__EN_TOP_AVDD_OVR_VAL__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field en_ldoBias_avdd_ovr */
/**
 * @defgroup pmu_top_regs_core_en_ldoBias_avdd_ovr_field en_ldoBias_avdd_ovr_field
 * @brief macros for field en_ldoBias_avdd_ovr
 * @details Enable AVDD LDO Bias override
 * @{
 */
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__SHIFT                                 2
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__WIDTH                                 1
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__MASK                        0x00000004U
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field en_ldoBias_avdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_en_ldoBias_avdd_ovr_val_field en_ldoBias_avdd_ovr_val_field
 * @brief macros for field en_ldoBias_avdd_ovr_val
 * @details Enable AVDD LDO Bias override value
 * @{
 */
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__SHIFT                             3
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__WIDTH                             1
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__MASK                    0x00000008U
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PMU_PMU13__EN_LDOBIAS_AVDD_OVR_VAL__RESET_VALUE             0x00000001U
/** @} */

/* macros for field bypass_avdd */
/**
 * @defgroup pmu_top_regs_core_bypass_avdd_field bypass_avdd_field
 * @brief macros for field bypass_avdd
 * @details Bypass AVDD LDO
 * @{
 */
#define PMU_PMU13__BYPASS_AVDD__SHIFT                                         4
#define PMU_PMU13__BYPASS_AVDD__WIDTH                                         1
#define PMU_PMU13__BYPASS_AVDD__MASK                                0x00000010U
#define PMU_PMU13__BYPASS_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU13__BYPASS_AVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU13__BYPASS_AVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU13__BYPASS_AVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU13__BYPASS_AVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU13__BYPASS_AVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU13__BYPASS_AVDD__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field bypass_dly_avdd_ovr */
/**
 * @defgroup pmu_top_regs_core_bypass_dly_avdd_ovr_field bypass_dly_avdd_ovr_field
 * @brief macros for field bypass_dly_avdd_ovr
 * @details Bypass AVDD LDO (delay)
 * @{
 */
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__SHIFT                                 5
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__WIDTH                                 1
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__MASK                        0x00000020U
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field bypass_dly_avdd_ovr_val */
/**
 * @defgroup pmu_top_regs_core_bypass_dly_avdd_ovr_val_field bypass_dly_avdd_ovr_val_field
 * @brief macros for field bypass_dly_avdd_ovr_val
 * @details Bypass AVDD LDO override value
 * @{
 */
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__SHIFT                             6
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__WIDTH                             1
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__MASK                    0x00000040U
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU13__BYPASS_DLY_AVDD_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field en_rload_top_avdd */
/**
 * @defgroup pmu_top_regs_core_en_rload_top_avdd_field en_rload_top_avdd_field
 * @brief macros for field en_rload_top_avdd
 * @details enable resistor load at LDO output
 * @{
 */
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__SHIFT                                   7
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__WIDTH                                   1
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__MASK                          0x00000080U
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU13__EN_RLOAD_TOP_AVDD__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ldo_folbias_avdd */
/**
 * @defgroup pmu_top_regs_core_ldo_folbias_avdd_field ldo_folbias_avdd_field
 * @brief macros for field ldo_folbias_avdd
 * @details follower bias adjustment
 * @{
 */
#define PMU_PMU13__LDO_FOLBIAS_AVDD__SHIFT                                    8
#define PMU_PMU13__LDO_FOLBIAS_AVDD__WIDTH                                    3
#define PMU_PMU13__LDO_FOLBIAS_AVDD__MASK                           0x00000700U
#define PMU_PMU13__LDO_FOLBIAS_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define PMU_PMU13__LDO_FOLBIAS_AVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define PMU_PMU13__LDO_FOLBIAS_AVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define PMU_PMU13__LDO_FOLBIAS_AVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define PMU_PMU13__LDO_FOLBIAS_AVDD__RESET_VALUE                    0x00000007U
/** @} */

/* macros for field ldo_highIq_avdd */
/**
 * @defgroup pmu_top_regs_core_ldo_highIq_avdd_field ldo_highIq_avdd_field
 * @brief macros for field ldo_highIq_avdd
 * @details enable a higher quiescent current to improve stability at low current load case
 * @{
 */
#define PMU_PMU13__LDO_HIGHIQ_AVDD__SHIFT                                    11
#define PMU_PMU13__LDO_HIGHIQ_AVDD__WIDTH                                     1
#define PMU_PMU13__LDO_HIGHIQ_AVDD__MASK                            0x00000800U
#define PMU_PMU13__LDO_HIGHIQ_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU13__LDO_HIGHIQ_AVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU13__LDO_HIGHIQ_AVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU13__LDO_HIGHIQ_AVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU13__LDO_HIGHIQ_AVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU13__LDO_HIGHIQ_AVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU13__LDO_HIGHIQ_AVDD__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field porbsocavdd_ctrcuLow */
/**
 * @defgroup pmu_top_regs_core_porbsocavdd_ctrcuLow_field porbsocavdd_ctrcuLow_field
 * @brief macros for field porbsocavdd_ctrcuLow
 * @details por comparabor bias setting 200pA, 250pA 310pA 1nA
 * @{
 */
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__SHIFT                               12
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__WIDTH                                2
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__MASK                       0x00003000U
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PMU_PMU13__PORBSOCAVDD_CTRCULOW__RESET_VALUE                0x00000002U
/** @} */

/* macros for field SwchReqAVDD_cuMid */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_cuMid_field SwchReqAVDD_cuMid_field
 * @brief macros for field SwchReqAVDD_cuMid
 * @details por comparabor bias setting 200pA, 250pA 310pA 1nA
 * @{
 */
#define PMU_PMU13__SWCHREQAVDD_CUMID__SHIFT                                  14
#define PMU_PMU13__SWCHREQAVDD_CUMID__WIDTH                                   3
#define PMU_PMU13__SWCHREQAVDD_CUMID__MASK                          0x0001c000U
#define PMU_PMU13__SWCHREQAVDD_CUMID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define PMU_PMU13__SWCHREQAVDD_CUMID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define PMU_PMU13__SWCHREQAVDD_CUMID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define PMU_PMU13__SWCHREQAVDD_CUMID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define PMU_PMU13__SWCHREQAVDD_CUMID__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field SwchReqAVDD_encomp_ovr */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_encomp_ovr_field SwchReqAVDD_encomp_ovr_field
 * @brief macros for field SwchReqAVDD_encomp_ovr
 * @details override SwchReqAVDD_enswres
 * @{
 */
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__SHIFT                             17
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__WIDTH                              1
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__MASK                     0x00020000U
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field SwchReqAVDD_encomp_ovr_val */
/**
 * @defgroup pmu_top_regs_core_SwchReqAVDD_encomp_ovr_val_field SwchReqAVDD_encomp_ovr_val_field
 * @brief macros for field SwchReqAVDD_encomp_ovr_val
 * @details override SwchReqAVDD_enswres val: avdd request comparator drives the swres instead of the switcher
 * @{
 */
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__SHIFT                         18
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__WIDTH                          1
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__MASK                 0x00040000U
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU13__SWCHREQAVDD_ENCOMP_OVR_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field lp_bypass */
/**
 * @defgroup pmu_top_regs_core_lp_bypass_field lp_bypass_field
 * @brief macros for field lp_bypass
 * @details if set turn avdd lp ldo off and bypass to vbat1v in buck mode
 * @{
 */
#define PMU_PMU13__LP_BYPASS__SHIFT                                          19
#define PMU_PMU13__LP_BYPASS__WIDTH                                           1
#define PMU_PMU13__LP_BYPASS__MASK                                  0x00080000U
#define PMU_PMU13__LP_BYPASS__READ(src) (((uint32_t)(src) & 0x00080000U) >> 19)
#define PMU_PMU13__LP_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PMU_PMU13__LP_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PMU_PMU13__LP_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PMU_PMU13__LP_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU13__LP_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU13__LP_BYPASS__RESET_VALUE                           0x00000000U
/** @} */
#define PMU_PMU13__TYPE                                                uint32_t
#define PMU_PMU13__READ                                             0x000fffffU
#define PMU_PMU13__WRITE                                            0x000fffffU
#define PMU_PMU13__PRESERVED                                        0x00000000U
#define PMU_PMU13__RESET_VALUE                                      0x0000e70aU

#endif /* __PMU_PMU13_MACRO__ */

/** @} end of pmu13 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu14 */
/**
 * @defgroup pmu_top_regs_core_pmu14 pmu14
 * @brief atb and clocks definitions.
 * @{
 */
#ifndef __PMU_PMU14_MACRO__
#define __PMU_PMU14_MACRO__

/* macros for field dig_clk_en */
/**
 * @defgroup pmu_top_regs_core_dig_clk_en_field dig_clk_en_field
 * @brief macros for field dig_clk_en
 * @details clk enable for digital 32KHz clk
 * @{
 */
#define PMU_PMU14__DIG_CLK_EN__SHIFT                                          0
#define PMU_PMU14__DIG_CLK_EN__WIDTH                                          1
#define PMU_PMU14__DIG_CLK_EN__MASK                                 0x00000001U
#define PMU_PMU14__DIG_CLK_EN__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU14__DIG_CLK_EN__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU14__DIG_CLK_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU14__DIG_CLK_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU14__DIG_CLK_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU14__DIG_CLK_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU14__DIG_CLK_EN__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field atb_pmubias_en */
/**
 * @defgroup pmu_top_regs_core_atb_pmubias_en_field atb_pmubias_en_field
 * @brief macros for field atb_pmubias_en
 * @details atb enable for PMU Bias 0 - Disable Analog Test buffer 1 - Enable Analog Test buffer
 * @{
 */
#define PMU_PMU14__ATB_PMUBIAS_EN__SHIFT                                      1
#define PMU_PMU14__ATB_PMUBIAS_EN__WIDTH                                      1
#define PMU_PMU14__ATB_PMUBIAS_EN__MASK                             0x00000002U
#define PMU_PMU14__ATB_PMUBIAS_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU14__ATB_PMUBIAS_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU14__ATB_PMUBIAS_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU14__ATB_PMUBIAS_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU14__ATB_PMUBIAS_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU14__ATB_PMUBIAS_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU14__ATB_PMUBIAS_EN__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field atb_pmubias_sel */
/**
 * @defgroup pmu_top_regs_core_atb_pmubias_sel_field atb_pmubias_sel_field
 * @brief macros for field atb_pmubias_sel
 * @details atb selects for pmu bias 0x0 - VBG600mT 0x1 - vrefnat600T 0x2 - vrefnat900T 0x3 - VrefTR 0x4 - VrefporTR 0x5 - vref1p3v 0x6 - Vrefporavdd 0x7 - Vrefpordvdd 0x8 - Vrefporvddio 0x9 - Vrefporswreg 0xa - Vrefavdd 0xb - Vrefdvdd 0xc - Vrefvddio 0xd - Vrefswreg 0xe - Vreflpc1 0xf - Vreflpc0 0x10 - Vrefgadc 0x11 - AVDD 0x12 - VBAT1V_A 0x13 - vref_extbst 0x14 to 0x1A - AVSS
 * @{
 */
#define PMU_PMU14__ATB_PMUBIAS_SEL__SHIFT                                     2
#define PMU_PMU14__ATB_PMUBIAS_SEL__WIDTH                                     5
#define PMU_PMU14__ATB_PMUBIAS_SEL__MASK                            0x0000007cU
#define PMU_PMU14__ATB_PMUBIAS_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000007cU) >> 2)
#define PMU_PMU14__ATB_PMUBIAS_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000007cU)
#define PMU_PMU14__ATB_PMUBIAS_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007cU) | (((uint32_t)(src) <<\
                    2) & 0x0000007cU)
#define PMU_PMU14__ATB_PMUBIAS_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000007cU)))
#define PMU_PMU14__ATB_PMUBIAS_SEL__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field atb_pmutop_sel */
/**
 * @defgroup pmu_top_regs_core_atb_pmutop_sel_field atb_pmutop_sel_field
 * @brief macros for field atb_pmutop_sel
 * @details Top Mux select for PMU ATB 0x0 - Disable (default) 0x1 - PMU Bias 0x2 - SWREG 0x3 - LPComp 0x4 - GADC 0x5 - AVDD 0x6 - 1uA test current 0x7 - 240uA test current (constant gm) or 96nA test current (native)
 * @{
 */
#define PMU_PMU14__ATB_PMUTOP_SEL__SHIFT                                      7
#define PMU_PMU14__ATB_PMUTOP_SEL__WIDTH                                      3
#define PMU_PMU14__ATB_PMUTOP_SEL__MASK                             0x00000380U
#define PMU_PMU14__ATB_PMUTOP_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define PMU_PMU14__ATB_PMUTOP_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define PMU_PMU14__ATB_PMUTOP_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define PMU_PMU14__ATB_PMUTOP_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define PMU_PMU14__ATB_PMUTOP_SEL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field atb_sel_IBnat */
/**
 * @defgroup pmu_top_regs_core_atb_sel_IBnat_field atb_sel_IBnat_field
 * @brief macros for field atb_sel_IBnat
 * @details Selects nA test current to be from constant gm reference of native reference 0x0 - 240 nA constant gm test current (default) 0x1 - 96nA native reference current
 * @{
 */
#define PMU_PMU14__ATB_SEL_IBNAT__SHIFT                                      10
#define PMU_PMU14__ATB_SEL_IBNAT__WIDTH                                       1
#define PMU_PMU14__ATB_SEL_IBNAT__MASK                              0x00000400U
#define PMU_PMU14__ATB_SEL_IBNAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU14__ATB_SEL_IBNAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU14__ATB_SEL_IBNAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU14__ATB_SEL_IBNAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU14__ATB_SEL_IBNAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU14__ATB_SEL_IBNAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU14__ATB_SEL_IBNAT__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field pmu_pin_mux_sel */
/**
 * @defgroup pmu_top_regs_core_pmu_pin_mux_sel_field pmu_pin_mux_sel_field
 * @brief macros for field pmu_pin_mux_sel
 * @details pin mux select from analog 00000 - uAreadyBOtb_sw 00001 - pkCompOtb_sw 00010 - reqCompOtb_sw 00011 - reqLatchedtb_sw 00100 - senseShortBtb_sw 00101 - shortCompOtb_sw 00110 - zoCompOtb_sw 00111 - nAreadyBOtb_sw 01000 - reqVddIOb 01001 - reqDVDDb 01010 - 1'b0 01011 - lpcomp_out 01100 - cmpout_extbst 01101 - vbrownout 01110 - vbrownout3 01111 - pwd_in 10000 - vbat1_rdy 10001 - vbat3_rdy 10010 - mode 10011 - porb_ref 10100 - porb_swreg 10101 - porb_vddIO 10110 - porb_dvdd 10111 - porb_avdd 11000 - porb_all 11001 to 11111 - 1'b0
 * @{
 */
#define PMU_PMU14__PMU_PIN_MUX_SEL__SHIFT                                    11
#define PMU_PMU14__PMU_PIN_MUX_SEL__WIDTH                                     5
#define PMU_PMU14__PMU_PIN_MUX_SEL__MASK                            0x0000f800U
#define PMU_PMU14__PMU_PIN_MUX_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f800U) >> 11)
#define PMU_PMU14__PMU_PIN_MUX_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0000f800U)
#define PMU_PMU14__PMU_PIN_MUX_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f800U) | (((uint32_t)(src) <<\
                    11) & 0x0000f800U)
#define PMU_PMU14__PMU_PIN_MUX_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0000f800U)))
#define PMU_PMU14__PMU_PIN_MUX_SEL__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field gadc_cutvdd_b_ovr */
/**
 * @defgroup pmu_top_regs_core_gadc_cutvdd_b_ovr_field gadc_cutvdd_b_ovr_field
 * @brief macros for field gadc_cutvdd_b_ovr
 * @details override gadc_cutvdd_b
 * @{
 */
#define PMU_PMU14__GADC_CUTVDD_B_OVR__SHIFT                                  16
#define PMU_PMU14__GADC_CUTVDD_B_OVR__WIDTH                                   1
#define PMU_PMU14__GADC_CUTVDD_B_OVR__MASK                          0x00010000U
#define PMU_PMU14__GADC_CUTVDD_B_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PMU_PMU14__GADC_CUTVDD_B_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU14__GADC_CUTVDD_B_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU14__GADC_CUTVDD_B_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU14__GADC_CUTVDD_B_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU14__GADC_CUTVDD_B_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU14__GADC_CUTVDD_B_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field gadc_cutvdd_b_ovr_val */
/**
 * @defgroup pmu_top_regs_core_gadc_cutvdd_b_ovr_val_field gadc_cutvdd_b_ovr_val_field
 * @brief macros for field gadc_cutvdd_b_ovr_val
 * @details override gadc_cutvdd_b val: Turn ON the gadc hsw
 * @{
 */
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__SHIFT                              17
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__WIDTH                               1
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__MASK                      0x00020000U
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU14__GADC_CUTVDD_B_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field disable_xtal32K */
/**
 * @defgroup pmu_top_regs_core_disable_xtal32K_field disable_xtal32K_field
 * @brief macros for field disable_xtal32K
 * @details override for xtal32K
 * @{
 */
#define PMU_PMU14__DISABLE_XTAL32K__SHIFT                                    18
#define PMU_PMU14__DISABLE_XTAL32K__WIDTH                                     1
#define PMU_PMU14__DISABLE_XTAL32K__MASK                            0x00040000U
#define PMU_PMU14__DISABLE_XTAL32K__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU14__DISABLE_XTAL32K__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PMU_PMU14__DISABLE_XTAL32K__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PMU_PMU14__DISABLE_XTAL32K__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PMU_PMU14__DISABLE_XTAL32K__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU14__DISABLE_XTAL32K__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU14__DISABLE_XTAL32K__RESET_VALUE                     0x00000000U
/** @} */
#define PMU_PMU14__TYPE                                                uint32_t
#define PMU_PMU14__READ                                             0x0007ffffU
#define PMU_PMU14__WRITE                                            0x0007ffffU
#define PMU_PMU14__PRESERVED                                        0x00000000U
#define PMU_PMU14__RESET_VALUE                                      0x00000001U

#endif /* __PMU_PMU14_MACRO__ */

/** @} end of pmu14 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu15 */
/**
 * @defgroup pmu_top_regs_core_pmu15 pmu15
 * @brief more test registers and overrides definitions.
 * @{
 */
#ifndef __PMU_PMU15_MACRO__
#define __PMU_PMU15_MACRO__

/* macros for field otp_int_ovr */
/**
 * @defgroup pmu_top_regs_core_otp_int_ovr_field otp_int_ovr_field
 * @brief macros for field otp_int_ovr
 * @details enables override for OTP bits
 * @{
 */
#define PMU_PMU15__OTP_INT_OVR__SHIFT                                         0
#define PMU_PMU15__OTP_INT_OVR__WIDTH                                         1
#define PMU_PMU15__OTP_INT_OVR__MASK                                0x00000001U
#define PMU_PMU15__OTP_INT_OVR__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU15__OTP_INT_OVR__WRITE(src)      ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU15__OTP_INT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU15__OTP_INT_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU15__OTP_INT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU15__OTP_INT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU15__OTP_INT_OVR__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field otp_nabg_trim_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_nabg_trim_ovr_val_field otp_nabg_trim_ovr_val_field
 * @brief macros for field otp_nabg_trim_ovr_val
 * @details override val for otp_nabg_trim [8:6] -> ctr_Wdio Selects number of units used in diode connected device 00x - 1 unit 01x - 3 units 10x - 5 units 11x - 7 units [5:4] -> ctr_Lnat: Selects effective length of 1x native 00 - 9.16um 01 - 12.56um 1x - 17.8um [3:2] -> ctr_Lnat2: Selects effective length of 2x native 00 - 9.16um 01 - 12.56um 1x - 17.8um [1:0] -> ctr_Lnat4: Selects effective length of 4x native 00 - 9.16um 01 - 12.56um 1x - 17.8um
 * @{
 */
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__SHIFT                               1
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__WIDTH                               9
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__MASK                      0x000003feU
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003feU) >> 1)
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000003feU)
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003feU) | (((uint32_t)(src) <<\
                    1) & 0x000003feU)
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000003feU)))
#define PMU_PMU15__OTP_NABG_TRIM_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field otp_harv_disabled_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_harv_disabled_ovr_val_field otp_harv_disabled_ovr_val_field
 * @brief macros for field otp_harv_disabled_ovr_val
 * @details override val for otp_harv_disabled 0
 * @{
 */
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__SHIFT                          10
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__WIDTH                           1
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__MASK                  0x00000400U
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU15__OTP_HARV_DISABLED_OVR_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field otp_vddio_range_ovr_val */
/**
 * @defgroup pmu_top_regs_core_otp_vddio_range_ovr_val_field otp_vddio_range_ovr_val_field
 * @brief macros for field otp_vddio_range_ovr_val
 * @details override val for otp_vddio_range 0: Normal operation 1: Uses ctr_ref_vddio_otp to set VDDIO voltage in all power modes
 * @{
 */
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__SHIFT                            11
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__WIDTH                             1
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__MASK                    0x00000800U
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU15__OTP_VDDIO_RANGE_OVR_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field disable_swreg */
/**
 * @defgroup pmu_top_regs_core_disable_swreg_field disable_swreg_field
 * @brief macros for field disable_swreg
 * @details Switching regulator disable
 * @{
 */
#define PMU_PMU15__DISABLE_SWREG__SHIFT                                      12
#define PMU_PMU15__DISABLE_SWREG__WIDTH                                       1
#define PMU_PMU15__DISABLE_SWREG__MASK                              0x00001000U
#define PMU_PMU15__DISABLE_SWREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU15__DISABLE_SWREG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU15__DISABLE_SWREG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU15__DISABLE_SWREG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU15__DISABLE_SWREG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU15__DISABLE_SWREG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU15__DISABLE_SWREG__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field disable_vddio */
/**
 * @defgroup pmu_top_regs_core_disable_vddio_field disable_vddio_field
 * @brief macros for field disable_vddio
 * @details VDDIO LDO disable
 * @{
 */
#define PMU_PMU15__DISABLE_VDDIO__SHIFT                                      13
#define PMU_PMU15__DISABLE_VDDIO__WIDTH                                       1
#define PMU_PMU15__DISABLE_VDDIO__MASK                              0x00002000U
#define PMU_PMU15__DISABLE_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU15__DISABLE_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU15__DISABLE_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU15__DISABLE_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU15__DISABLE_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU15__DISABLE_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU15__DISABLE_VDDIO__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field en_brownout_hys */
/**
 * @defgroup pmu_top_regs_core_en_brownout_hys_field en_brownout_hys_field
 * @brief macros for field en_brownout_hys
 * @details Enable voltage hysteresis for brownout
 * @{
 */
#define PMU_PMU15__EN_BROWNOUT_HYS__SHIFT                                    14
#define PMU_PMU15__EN_BROWNOUT_HYS__WIDTH                                     1
#define PMU_PMU15__EN_BROWNOUT_HYS__MASK                            0x00004000U
#define PMU_PMU15__EN_BROWNOUT_HYS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PMU_PMU15__EN_BROWNOUT_HYS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PMU_PMU15__EN_BROWNOUT_HYS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PMU_PMU15__EN_BROWNOUT_HYS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PMU_PMU15__EN_BROWNOUT_HYS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PMU_PMU15__EN_BROWNOUT_HYS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PMU_PMU15__EN_BROWNOUT_HYS__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field en_R1vbat */
/**
 * @defgroup pmu_top_regs_core_en_R1vbat_field en_R1vbat_field
 * @brief macros for field en_R1vbat
 * @details Enable 1st 3k resistor on VBAT
 * @{
 */
#define PMU_PMU15__EN_R1VBAT__SHIFT                                          15
#define PMU_PMU15__EN_R1VBAT__WIDTH                                           1
#define PMU_PMU15__EN_R1VBAT__MASK                                  0x00008000U
#define PMU_PMU15__EN_R1VBAT__READ(src) (((uint32_t)(src) & 0x00008000U) >> 15)
#define PMU_PMU15__EN_R1VBAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PMU_PMU15__EN_R1VBAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PMU_PMU15__EN_R1VBAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PMU_PMU15__EN_R1VBAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PMU_PMU15__EN_R1VBAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PMU_PMU15__EN_R1VBAT__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field en_R2vbat */
/**
 * @defgroup pmu_top_regs_core_en_R2vbat_field en_R2vbat_field
 * @brief macros for field en_R2vbat
 * @details Enable 2nd 2k resistor on VBAT
 * @{
 */
#define PMU_PMU15__EN_R2VBAT__SHIFT                                          16
#define PMU_PMU15__EN_R2VBAT__WIDTH                                           1
#define PMU_PMU15__EN_R2VBAT__MASK                                  0x00010000U
#define PMU_PMU15__EN_R2VBAT__READ(src) (((uint32_t)(src) & 0x00010000U) >> 16)
#define PMU_PMU15__EN_R2VBAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PMU_PMU15__EN_R2VBAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PMU_PMU15__EN_R2VBAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PMU_PMU15__EN_R2VBAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PMU_PMU15__EN_R2VBAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PMU_PMU15__EN_R2VBAT__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field pmu_spares */
/**
 * @defgroup pmu_top_regs_core_pmu_spares_field pmu_spares_field
 * @brief macros for field pmu_spares
 * @details Spare registers
 * @{
 */
#define PMU_PMU15__PMU_SPARES__SHIFT                                         17
#define PMU_PMU15__PMU_SPARES__WIDTH                                          8
#define PMU_PMU15__PMU_SPARES__MASK                                 0x01fe0000U
#define PMU_PMU15__PMU_SPARES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01fe0000U) >> 17)
#define PMU_PMU15__PMU_SPARES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x01fe0000U)
#define PMU_PMU15__PMU_SPARES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01fe0000U) | (((uint32_t)(src) <<\
                    17) & 0x01fe0000U)
#define PMU_PMU15__PMU_SPARES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x01fe0000U)))
#define PMU_PMU15__PMU_SPARES__RESET_VALUE                          0x00000000U
/** @} */
#define PMU_PMU15__TYPE                                                uint32_t
#define PMU_PMU15__READ                                             0x01ffffffU
#define PMU_PMU15__WRITE                                            0x01ffffffU
#define PMU_PMU15__PRESERVED                                        0x00000000U
#define PMU_PMU15__RESET_VALUE                                      0x00004000U

#endif /* __PMU_PMU15_MACRO__ */

/** @} end of pmu15 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu16 */
/**
 * @defgroup pmu_top_regs_core_pmu16 pmu16
 * @brief Overrides and ATB definitions.
 * @{
 */
#ifndef __PMU_PMU16_MACRO__
#define __PMU_PMU16_MACRO__

/* macros for field state_ovr */
/**
 * @defgroup pmu_top_regs_core_state_ovr_field state_ovr_field
 * @brief macros for field state_ovr
 * @details Override bit for state
 * @{
 */
#define PMU_PMU16__STATE_OVR__SHIFT                                           0
#define PMU_PMU16__STATE_OVR__WIDTH                                           1
#define PMU_PMU16__STATE_OVR__MASK                                  0x00000001U
#define PMU_PMU16__STATE_OVR__READ(src)         ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU16__STATE_OVR__WRITE(src)        ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU16__STATE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU16__STATE_OVR__VERIFY(src) (!(((uint32_t)(src) & ~0x00000001U)))
#define PMU_PMU16__STATE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU16__STATE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU16__STATE_OVR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field test_state */
/**
 * @defgroup pmu_top_regs_core_test_state_field test_state_field
 * @brief macros for field test_state
 * @details force the pmu state to be this state
 * @{
 */
#define PMU_PMU16__TEST_STATE__SHIFT                                          1
#define PMU_PMU16__TEST_STATE__WIDTH                                          3
#define PMU_PMU16__TEST_STATE__MASK                                 0x0000000eU
#define PMU_PMU16__TEST_STATE__READ(src) (((uint32_t)(src) & 0x0000000eU) >> 1)
#define PMU_PMU16__TEST_STATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000000eU)
#define PMU_PMU16__TEST_STATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000eU) | (((uint32_t)(src) <<\
                    1) & 0x0000000eU)
#define PMU_PMU16__TEST_STATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000000eU)))
#define PMU_PMU16__TEST_STATE__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field pwr_mode_ovr */
/**
 * @defgroup pmu_top_regs_core_pwr_mode_ovr_field pwr_mode_ovr_field
 * @brief macros for field pwr_mode_ovr
 * @details override power mode for testing
 * @{
 */
#define PMU_PMU16__PWR_MODE_OVR__SHIFT                                        4
#define PMU_PMU16__PWR_MODE_OVR__WIDTH                                        1
#define PMU_PMU16__PWR_MODE_OVR__MASK                               0x00000010U
#define PMU_PMU16__PWR_MODE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PMU_PMU16__PWR_MODE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PMU_PMU16__PWR_MODE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PMU_PMU16__PWR_MODE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PMU_PMU16__PWR_MODE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PMU_PMU16__PWR_MODE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PMU_PMU16__PWR_MODE_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pwr_mode_ovr_val_encode */
/**
 * @defgroup pmu_top_regs_core_pwr_mode_ovr_val_encode_field pwr_mode_ovr_val_encode_field
 * @brief macros for field pwr_mode_ovr_val_encode
 * @details pwr_mode override value
 * @{
 */
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__SHIFT                             5
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__WIDTH                             3
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__MASK                    0x000000e0U
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000e0U) >> 5)
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000000e0U)
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000000e0U)))
#define PMU_PMU16__PWR_MODE_OVR_VAL_ENCODE__RESET_VALUE             0x00000000U
/** @} */

/* macros for field wkup_timer_en_ovr */
/**
 * @defgroup pmu_top_regs_core_wkup_timer_en_ovr_field wkup_timer_en_ovr_field
 * @brief macros for field wkup_timer_en_ovr
 * @details override enable for Wakeup Timer enable
 * @{
 */
#define PMU_PMU16__WKUP_TIMER_EN_OVR__SHIFT                                   8
#define PMU_PMU16__WKUP_TIMER_EN_OVR__WIDTH                                   1
#define PMU_PMU16__WKUP_TIMER_EN_OVR__MASK                          0x00000100U
#define PMU_PMU16__WKUP_TIMER_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU16__WKUP_TIMER_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PMU_PMU16__WKUP_TIMER_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PMU_PMU16__WKUP_TIMER_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PMU_PMU16__WKUP_TIMER_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU16__WKUP_TIMER_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU16__WKUP_TIMER_EN_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field wkup_timer_en_val */
/**
 * @defgroup pmu_top_regs_core_wkup_timer_en_val_field wkup_timer_en_val_field
 * @brief macros for field wkup_timer_en_val
 * @details override val for Wakeup Timer enable
 * @{
 */
#define PMU_PMU16__WKUP_TIMER_EN_VAL__SHIFT                                   9
#define PMU_PMU16__WKUP_TIMER_EN_VAL__WIDTH                                   1
#define PMU_PMU16__WKUP_TIMER_EN_VAL__MASK                          0x00000200U
#define PMU_PMU16__WKUP_TIMER_EN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU16__WKUP_TIMER_EN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PMU_PMU16__WKUP_TIMER_EN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PMU_PMU16__WKUP_TIMER_EN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PMU_PMU16__WKUP_TIMER_EN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU16__WKUP_TIMER_EN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU16__WKUP_TIMER_EN_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field lpcomp_en_ovr */
/**
 * @defgroup pmu_top_regs_core_lpcomp_en_ovr_field lpcomp_en_ovr_field
 * @brief macros for field lpcomp_en_ovr
 * @details override enable for LP Comparator enable
 * @{
 */
#define PMU_PMU16__LPCOMP_EN_OVR__SHIFT                                      10
#define PMU_PMU16__LPCOMP_EN_OVR__WIDTH                                       1
#define PMU_PMU16__LPCOMP_EN_OVR__MASK                              0x00000400U
#define PMU_PMU16__LPCOMP_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU16__LPCOMP_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PMU_PMU16__LPCOMP_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PMU_PMU16__LPCOMP_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PMU_PMU16__LPCOMP_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU16__LPCOMP_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU16__LPCOMP_EN_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field lpcomp_en_ovr_val */
/**
 * @defgroup pmu_top_regs_core_lpcomp_en_ovr_val_field lpcomp_en_ovr_val_field
 * @brief macros for field lpcomp_en_ovr_val
 * @details override val for LP Comparator enable
 * @{
 */
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__SHIFT                                  11
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__WIDTH                                   1
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__MASK                          0x00000800U
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PMU_PMU16__LPCOMP_EN_OVR_VAL__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field pinedge_en_ovr */
/**
 * @defgroup pmu_top_regs_core_pinedge_en_ovr_field pinedge_en_ovr_field
 * @brief macros for field pinedge_en_ovr
 * @details override enable for pinedge enable
 * @{
 */
#define PMU_PMU16__PINEDGE_EN_OVR__SHIFT                                     12
#define PMU_PMU16__PINEDGE_EN_OVR__WIDTH                                      1
#define PMU_PMU16__PINEDGE_EN_OVR__MASK                             0x00001000U
#define PMU_PMU16__PINEDGE_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PMU_PMU16__PINEDGE_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PMU_PMU16__PINEDGE_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PMU_PMU16__PINEDGE_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PMU_PMU16__PINEDGE_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PMU_PMU16__PINEDGE_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PMU_PMU16__PINEDGE_EN_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pinedge_en_ovr_val */
/**
 * @defgroup pmu_top_regs_core_pinedge_en_ovr_val_field pinedge_en_ovr_val_field
 * @brief macros for field pinedge_en_ovr_val
 * @details override val for pinedge enable
 * @{
 */
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__SHIFT                                 13
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__WIDTH                                  1
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__MASK                         0x00002000U
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PMU_PMU16__PINEDGE_EN_OVR_VAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field trans_wait_reg */
/**
 * @defgroup pmu_top_regs_core_trans_wait_reg_field trans_wait_reg_field
 * @brief macros for field trans_wait_reg
 * @details wait time in transient state when going from low power to active
 * @{
 */
#define PMU_PMU16__TRANS_WAIT_REG__SHIFT                                     14
#define PMU_PMU16__TRANS_WAIT_REG__WIDTH                                      7
#define PMU_PMU16__TRANS_WAIT_REG__MASK                             0x001fc000U
#define PMU_PMU16__TRANS_WAIT_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define PMU_PMU16__TRANS_WAIT_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define PMU_PMU16__TRANS_WAIT_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define PMU_PMU16__TRANS_WAIT_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define PMU_PMU16__TRANS_WAIT_REG__RESET_VALUE                      0x00000014U
/** @} */

/* macros for field st_trans_wait_reg */
/**
 * @defgroup pmu_top_regs_core_st_trans_wait_reg_field st_trans_wait_reg_field
 * @brief macros for field st_trans_wait_reg
 * @details wait time in Start transient when going from low power to active
 * @{
 */
#define PMU_PMU16__ST_TRANS_WAIT_REG__SHIFT                                  21
#define PMU_PMU16__ST_TRANS_WAIT_REG__WIDTH                                   4
#define PMU_PMU16__ST_TRANS_WAIT_REG__MASK                          0x01e00000U
#define PMU_PMU16__ST_TRANS_WAIT_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01e00000U) >> 21)
#define PMU_PMU16__ST_TRANS_WAIT_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x01e00000U)
#define PMU_PMU16__ST_TRANS_WAIT_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01e00000U) | (((uint32_t)(src) <<\
                    21) & 0x01e00000U)
#define PMU_PMU16__ST_TRANS_WAIT_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x01e00000U)))
#define PMU_PMU16__ST_TRANS_WAIT_REG__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field cold_start_wait_reg */
/**
 * @defgroup pmu_top_regs_core_cold_start_wait_reg_field cold_start_wait_reg_field
 * @brief macros for field cold_start_wait_reg
 * @details wait time in Cold Start state going to active
 * @{
 */
#define PMU_PMU16__COLD_START_WAIT_REG__SHIFT                                25
#define PMU_PMU16__COLD_START_WAIT_REG__WIDTH                                 5
#define PMU_PMU16__COLD_START_WAIT_REG__MASK                        0x3e000000U
#define PMU_PMU16__COLD_START_WAIT_REG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define PMU_PMU16__COLD_START_WAIT_REG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define PMU_PMU16__COLD_START_WAIT_REG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define PMU_PMU16__COLD_START_WAIT_REG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define PMU_PMU16__COLD_START_WAIT_REG__RESET_VALUE                 0x00000010U
/** @} */
#define PMU_PMU16__TYPE                                                uint32_t
#define PMU_PMU16__READ                                             0x3fffffffU
#define PMU_PMU16__WRITE                                            0x3fffffffU
#define PMU_PMU16__PRESERVED                                        0x00000000U
#define PMU_PMU16__RESET_VALUE                                      0x20050800U

#endif /* __PMU_PMU16_MACRO__ */

/** @} end of pmu16 */

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

/* macros for field cmpout_extbst */
/**
 * @defgroup pmu_top_regs_core_cmpout_extbst_field cmpout_extbst_field
 * @brief macros for field cmpout_extbst
 * @details readback for Vharv comparator output
 * @{
 */
#define PMU_PMU_RB1__CMPOUT_EXTBST__SHIFT                                    17
#define PMU_PMU_RB1__CMPOUT_EXTBST__WIDTH                                     1
#define PMU_PMU_RB1__CMPOUT_EXTBST__MASK                            0x00020000U
#define PMU_PMU_RB1__CMPOUT_EXTBST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PMU_PMU_RB1__CMPOUT_EXTBST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PMU_PMU_RB1__CMPOUT_EXTBST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PMU_PMU_RB1__CMPOUT_EXTBST__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field vbrownout */
/**
 * @defgroup pmu_top_regs_core_vbrownout_field vbrownout_field
 * @brief macros for field vbrownout
 * @details readback for Brownout in Boost mode
 * @{
 */
#define PMU_PMU_RB1__VBROWNOUT__SHIFT                                        18
#define PMU_PMU_RB1__VBROWNOUT__WIDTH                                         1
#define PMU_PMU_RB1__VBROWNOUT__MASK                                0x00040000U
#define PMU_PMU_RB1__VBROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PMU_PMU_RB1__VBROWNOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PMU_PMU_RB1__VBROWNOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PMU_PMU_RB1__VBROWNOUT__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field vbrownout3 */
/**
 * @defgroup pmu_top_regs_core_vbrownout3_field vbrownout3_field
 * @brief macros for field vbrownout3
 * @details readback for Brownout in Buck/No Ind mode
 * @{
 */
#define PMU_PMU_RB1__VBROWNOUT3__SHIFT                                       19
#define PMU_PMU_RB1__VBROWNOUT3__WIDTH                                        1
#define PMU_PMU_RB1__VBROWNOUT3__MASK                               0x00080000U
#define PMU_PMU_RB1__VBROWNOUT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PMU_PMU_RB1__VBROWNOUT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PMU_PMU_RB1__VBROWNOUT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PMU_PMU_RB1__VBROWNOUT3__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pwd_in */
/**
 * @defgroup pmu_top_regs_core_pwd_in_field pwd_in_field
 * @brief macros for field pwd_in
 * @details readback for PWD pin comparator
 * @{
 */
#define PMU_PMU_RB1__PWD_IN__SHIFT                                           20
#define PMU_PMU_RB1__PWD_IN__WIDTH                                            1
#define PMU_PMU_RB1__PWD_IN__MASK                                   0x00100000U
#define PMU_PMU_RB1__PWD_IN__READ(src)  (((uint32_t)(src) & 0x00100000U) >> 20)
#define PMU_PMU_RB1__PWD_IN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PMU_PMU_RB1__PWD_IN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PMU_PMU_RB1__PWD_IN__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field vbat1_rdy */
/**
 * @defgroup pmu_top_regs_core_vbat1_rdy_field vbat1_rdy_field
 * @brief macros for field vbat1_rdy
 * @details readback for VBAT1V_RDY comparator
 * @{
 */
#define PMU_PMU_RB1__VBAT1_RDY__SHIFT                                        21
#define PMU_PMU_RB1__VBAT1_RDY__WIDTH                                         1
#define PMU_PMU_RB1__VBAT1_RDY__MASK                                0x00200000U
#define PMU_PMU_RB1__VBAT1_RDY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PMU_PMU_RB1__VBAT1_RDY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PMU_PMU_RB1__VBAT1_RDY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PMU_PMU_RB1__VBAT1_RDY__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field vbat3_rdy */
/**
 * @defgroup pmu_top_regs_core_vbat3_rdy_field vbat3_rdy_field
 * @brief macros for field vbat3_rdy
 * @details readback for VBAT3V_RDY comparator
 * @{
 */
#define PMU_PMU_RB1__VBAT3_RDY__SHIFT                                        22
#define PMU_PMU_RB1__VBAT3_RDY__WIDTH                                         1
#define PMU_PMU_RB1__VBAT3_RDY__MASK                                0x00400000U
#define PMU_PMU_RB1__VBAT3_RDY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PMU_PMU_RB1__VBAT3_RDY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PMU_PMU_RB1__VBAT3_RDY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PMU_PMU_RB1__VBAT3_RDY__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup pmu_top_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details readback for MODE pin
 * @{
 */
#define PMU_PMU_RB1__MODE__SHIFT                                             23
#define PMU_PMU_RB1__MODE__WIDTH                                              1
#define PMU_PMU_RB1__MODE__MASK                                     0x00800000U
#define PMU_PMU_RB1__MODE__READ(src)    (((uint32_t)(src) & 0x00800000U) >> 23)
#define PMU_PMU_RB1__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PMU_PMU_RB1__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PMU_PMU_RB1__MODE__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field porb_ref */
/**
 * @defgroup pmu_top_regs_core_porb_ref_field porb_ref_field
 * @brief macros for field porb_ref
 * @details readback for PORB_REF
 * @{
 */
#define PMU_PMU_RB1__PORB_REF__SHIFT                                         24
#define PMU_PMU_RB1__PORB_REF__WIDTH                                          1
#define PMU_PMU_RB1__PORB_REF__MASK                                 0x01000000U
#define PMU_PMU_RB1__PORB_REF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PMU_PMU_RB1__PORB_REF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PMU_PMU_RB1__PORB_REF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PMU_PMU_RB1__PORB_REF__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field porb_swreg */
/**
 * @defgroup pmu_top_regs_core_porb_swreg_field porb_swreg_field
 * @brief macros for field porb_swreg
 * @details readback for PORB_SWREG
 * @{
 */
#define PMU_PMU_RB1__PORB_SWREG__SHIFT                                       25
#define PMU_PMU_RB1__PORB_SWREG__WIDTH                                        1
#define PMU_PMU_RB1__PORB_SWREG__MASK                               0x02000000U
#define PMU_PMU_RB1__PORB_SWREG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PMU_PMU_RB1__PORB_SWREG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PMU_PMU_RB1__PORB_SWREG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PMU_PMU_RB1__PORB_SWREG__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field porb_vddio */
/**
 * @defgroup pmu_top_regs_core_porb_vddio_field porb_vddio_field
 * @brief macros for field porb_vddio
 * @details readback for PORB_VDDIO
 * @{
 */
#define PMU_PMU_RB1__PORB_VDDIO__SHIFT                                       26
#define PMU_PMU_RB1__PORB_VDDIO__WIDTH                                        1
#define PMU_PMU_RB1__PORB_VDDIO__MASK                               0x04000000U
#define PMU_PMU_RB1__PORB_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PMU_PMU_RB1__PORB_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PMU_PMU_RB1__PORB_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PMU_PMU_RB1__PORB_VDDIO__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field porb_dvdd */
/**
 * @defgroup pmu_top_regs_core_porb_dvdd_field porb_dvdd_field
 * @brief macros for field porb_dvdd
 * @details readback for PORB_DVDD
 * @{
 */
#define PMU_PMU_RB1__PORB_DVDD__SHIFT                                        27
#define PMU_PMU_RB1__PORB_DVDD__WIDTH                                         1
#define PMU_PMU_RB1__PORB_DVDD__MASK                                0x08000000U
#define PMU_PMU_RB1__PORB_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PMU_PMU_RB1__PORB_DVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PMU_PMU_RB1__PORB_DVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PMU_PMU_RB1__PORB_DVDD__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field porb_avdd */
/**
 * @defgroup pmu_top_regs_core_porb_avdd_field porb_avdd_field
 * @brief macros for field porb_avdd
 * @details readback for PORB_AVDD (should be 1)
 * @{
 */
#define PMU_PMU_RB1__PORB_AVDD__SHIFT                                        28
#define PMU_PMU_RB1__PORB_AVDD__WIDTH                                         1
#define PMU_PMU_RB1__PORB_AVDD__MASK                                0x10000000U
#define PMU_PMU_RB1__PORB_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PMU_PMU_RB1__PORB_AVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PMU_PMU_RB1__PORB_AVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PMU_PMU_RB1__PORB_AVDD__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field porb_all */
/**
 * @defgroup pmu_top_regs_core_porb_all_field porb_all_field
 * @brief macros for field porb_all
 * @details readback for PORB_ALL
 * @{
 */
#define PMU_PMU_RB1__PORB_ALL__SHIFT                                         29
#define PMU_PMU_RB1__PORB_ALL__WIDTH                                          1
#define PMU_PMU_RB1__PORB_ALL__MASK                                 0x20000000U
#define PMU_PMU_RB1__PORB_ALL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PMU_PMU_RB1__PORB_ALL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PMU_PMU_RB1__PORB_ALL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PMU_PMU_RB1__PORB_ALL__RESET_VALUE                          0x00000000U
/** @} */
#define PMU_PMU_RB1__TYPE                                              uint32_t
#define PMU_PMU_RB1__READ                                           0x3fffffffU
#define PMU_PMU_RB1__PRESERVED                                      0x00000000U
#define PMU_PMU_RB1__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB1_MACRO__ */

/** @} end of pmu_rb1 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb2 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb2 pmu_rb2
 * @brief Switcher and LDO readback registers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB2_MACRO__
#define __PMU_PMU_RB2_MACRO__

/* macros for field uAreadyBOtb_sw */
/**
 * @defgroup pmu_top_regs_core_uAreadyBOtb_sw_field uAreadyBOtb_sw_field
 * @brief macros for field uAreadyBOtb_sw
 * @details uA Bias Bar Ready
 * @{
 */
#define PMU_PMU_RB2__UAREADYBOTB_SW__SHIFT                                    0
#define PMU_PMU_RB2__UAREADYBOTB_SW__WIDTH                                    1
#define PMU_PMU_RB2__UAREADYBOTB_SW__MASK                           0x00000001U
#define PMU_PMU_RB2__UAREADYBOTB_SW__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define PMU_PMU_RB2__UAREADYBOTB_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU_RB2__UAREADYBOTB_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU_RB2__UAREADYBOTB_SW__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field pkCompOtb_sw */
/**
 * @defgroup pmu_top_regs_core_pkCompOtb_sw_field pkCompOtb_sw_field
 * @brief macros for field pkCompOtb_sw
 * @details peak current sensing output
 * @{
 */
#define PMU_PMU_RB2__PKCOMPOTB_SW__SHIFT                                      1
#define PMU_PMU_RB2__PKCOMPOTB_SW__WIDTH                                      1
#define PMU_PMU_RB2__PKCOMPOTB_SW__MASK                             0x00000002U
#define PMU_PMU_RB2__PKCOMPOTB_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU_RB2__PKCOMPOTB_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU_RB2__PKCOMPOTB_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU_RB2__PKCOMPOTB_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field reqCompOtb_sw */
/**
 * @defgroup pmu_top_regs_core_reqCompOtb_sw_field reqCompOtb_sw_field
 * @brief macros for field reqCompOtb_sw
 * @details req comparator output
 * @{
 */
#define PMU_PMU_RB2__REQCOMPOTB_SW__SHIFT                                     2
#define PMU_PMU_RB2__REQCOMPOTB_SW__WIDTH                                     1
#define PMU_PMU_RB2__REQCOMPOTB_SW__MASK                            0x00000004U
#define PMU_PMU_RB2__REQCOMPOTB_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PMU_PMU_RB2__REQCOMPOTB_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PMU_PMU_RB2__REQCOMPOTB_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PMU_PMU_RB2__REQCOMPOTB_SW__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field swState */
/**
 * @defgroup pmu_top_regs_core_swState_field swState_field
 * @brief macros for field swState
 * @details swMode,PeakCurb
 * @{
 */
#define PMU_PMU_RB2__SWSTATE__SHIFT                                           3
#define PMU_PMU_RB2__SWSTATE__WIDTH                                           2
#define PMU_PMU_RB2__SWSTATE__MASK                                  0x00000018U
#define PMU_PMU_RB2__SWSTATE__READ(src)  (((uint32_t)(src) & 0x00000018U) >> 3)
#define PMU_PMU_RB2__SWSTATE__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field senseShortBtb_sw */
/**
 * @defgroup pmu_top_regs_core_senseShortBtb_sw_field senseShortBtb_sw_field
 * @brief macros for field senseShortBtb_sw
 * @details short detection output (bst only)
 * @{
 */
#define PMU_PMU_RB2__SENSESHORTBTB_SW__SHIFT                                  5
#define PMU_PMU_RB2__SENSESHORTBTB_SW__WIDTH                                  1
#define PMU_PMU_RB2__SENSESHORTBTB_SW__MASK                         0x00000020U
#define PMU_PMU_RB2__SENSESHORTBTB_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PMU_PMU_RB2__SENSESHORTBTB_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PMU_PMU_RB2__SENSESHORTBTB_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PMU_PMU_RB2__SENSESHORTBTB_SW__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field shortCompOtb_sw */
/**
 * @defgroup pmu_top_regs_core_shortCompOtb_sw_field shortCompOtb_sw_field
 * @brief macros for field shortCompOtb_sw
 * @details check if output reach 1V in boost mode (below1Vb)
 * @{
 */
#define PMU_PMU_RB2__SHORTCOMPOTB_SW__SHIFT                                   6
#define PMU_PMU_RB2__SHORTCOMPOTB_SW__WIDTH                                   1
#define PMU_PMU_RB2__SHORTCOMPOTB_SW__MASK                          0x00000040U
#define PMU_PMU_RB2__SHORTCOMPOTB_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PMU_PMU_RB2__SHORTCOMPOTB_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PMU_PMU_RB2__SHORTCOMPOTB_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PMU_PMU_RB2__SHORTCOMPOTB_SW__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field zoCompOtb_sw */
/**
 * @defgroup pmu_top_regs_core_zoCompOtb_sw_field zoCompOtb_sw_field
 * @brief macros for field zoCompOtb_sw
 * @details zero current sensing output
 * @{
 */
#define PMU_PMU_RB2__ZOCOMPOTB_SW__SHIFT                                      7
#define PMU_PMU_RB2__ZOCOMPOTB_SW__WIDTH                                      1
#define PMU_PMU_RB2__ZOCOMPOTB_SW__MASK                             0x00000080U
#define PMU_PMU_RB2__ZOCOMPOTB_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PMU_PMU_RB2__ZOCOMPOTB_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PMU_PMU_RB2__ZOCOMPOTB_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PMU_PMU_RB2__ZOCOMPOTB_SW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nAreadyBOtb_sw */
/**
 * @defgroup pmu_top_regs_core_nAreadyBOtb_sw_field nAreadyBOtb_sw_field
 * @brief macros for field nAreadyBOtb_sw
 * @details nA Bias Bar Ready
 * @{
 */
#define PMU_PMU_RB2__NAREADYBOTB_SW__SHIFT                                    8
#define PMU_PMU_RB2__NAREADYBOTB_SW__WIDTH                                    1
#define PMU_PMU_RB2__NAREADYBOTB_SW__MASK                           0x00000100U
#define PMU_PMU_RB2__NAREADYBOTB_SW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PMU_PMU_RB2__NAREADYBOTB_SW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PMU_PMU_RB2__NAREADYBOTB_SW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PMU_PMU_RB2__NAREADYBOTB_SW__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field reqVddIOb */
/**
 * @defgroup pmu_top_regs_core_reqVddIOb_field reqVddIOb_field
 * @brief macros for field reqVddIOb
 * @details Add comment
 * @{
 */
#define PMU_PMU_RB2__REQVDDIOB__SHIFT                                         9
#define PMU_PMU_RB2__REQVDDIOB__WIDTH                                         1
#define PMU_PMU_RB2__REQVDDIOB__MASK                                0x00000200U
#define PMU_PMU_RB2__REQVDDIOB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PMU_PMU_RB2__REQVDDIOB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PMU_PMU_RB2__REQVDDIOB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PMU_PMU_RB2__REQVDDIOB__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field reqDVDDb */
/**
 * @defgroup pmu_top_regs_core_reqDVDDb_field reqDVDDb_field
 * @brief macros for field reqDVDDb
 * @details Add comment
 * @{
 */
#define PMU_PMU_RB2__REQDVDDB__SHIFT                                         10
#define PMU_PMU_RB2__REQDVDDB__WIDTH                                          1
#define PMU_PMU_RB2__REQDVDDB__MASK                                 0x00000400U
#define PMU_PMU_RB2__REQDVDDB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PMU_PMU_RB2__REQDVDDB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PMU_PMU_RB2__REQDVDDB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PMU_PMU_RB2__REQDVDDB__RESET_VALUE                          0x00000000U
/** @} */
#define PMU_PMU_RB2__TYPE                                              uint32_t
#define PMU_PMU_RB2__READ                                           0x000007ffU
#define PMU_PMU_RB2__PRESERVED                                      0x00000000U
#define PMU_PMU_RB2__RESET_VALUE                                    0x00000000U

#endif /* __PMU_PMU_RB2_MACRO__ */

/** @} end of pmu_rb2 */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_rb3 */
/**
 * @defgroup pmu_top_regs_core_pmu_rb3 pmu_rb3
 * @brief internal OTP readback registers definitions.
 * @{
 */
#ifndef __PMU_PMU_RB3_MACRO__
#define __PMU_PMU_RB3_MACRO__

/* macros for field otp_nabg_trim */
/**
 * @defgroup pmu_top_regs_core_otp_nabg_trim_field otp_nabg_trim_field
 * @brief macros for field otp_nabg_trim
 * @details Readback for bandgap trim
 * @{
 */
#define PMU_PMU_RB3__OTP_NABG_TRIM__SHIFT                                     0
#define PMU_PMU_RB3__OTP_NABG_TRIM__WIDTH                                     9
#define PMU_PMU_RB3__OTP_NABG_TRIM__MASK                            0x000001ffU
#define PMU_PMU_RB3__OTP_NABG_TRIM__READ(src)   ((uint32_t)(src) & 0x000001ffU)
#define PMU_PMU_RB3__OTP_NABG_TRIM__RESET_VALUE                     0x00000000U
/** @} */
#define PMU_PMU_RB3__TYPE                                              uint32_t
#define PMU_PMU_RB3__READ                                           0x000001ffU
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

/* macros for field otp_harv_disabled */
/**
 * @defgroup pmu_top_regs_core_otp_harv_disabled_field otp_harv_disabled_field
 * @brief macros for field otp_harv_disabled
 * @details Readback for harv disabled otp
 * @{
 */
#define PMU_PMU_RB4__OTP_HARV_DISABLED__SHIFT                                 0
#define PMU_PMU_RB4__OTP_HARV_DISABLED__WIDTH                                 1
#define PMU_PMU_RB4__OTP_HARV_DISABLED__MASK                        0x00000001U
#define PMU_PMU_RB4__OTP_HARV_DISABLED__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_RB4__OTP_HARV_DISABLED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU_RB4__OTP_HARV_DISABLED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU_RB4__OTP_HARV_DISABLED__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field otp_vddio_range */
/**
 * @defgroup pmu_top_regs_core_otp_vddio_range_field otp_vddio_range_field
 * @brief macros for field otp_vddio_range
 * @details Readback for vddio_range otp
 * @{
 */
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__SHIFT                                   1
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__WIDTH                                   1
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__MASK                          0x00000002U
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU_RB4__OTP_VDDIO_RANGE__RESET_VALUE                   0x00000000U
/** @} */
#define PMU_PMU_RB4__TYPE                                              uint32_t
#define PMU_PMU_RB4__READ                                           0x00000003U
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

/* macros for BlueprintGlobalNameSpace::PMU_pmu_wdog_ctrl */
/**
 * @defgroup pmu_top_regs_core_pmu_wdog_ctrl pmu_wdog_ctrl
 * @brief pmu watchdog control definitions.
 * @{
 */
#ifndef __PMU_PMU_WDOG_CTRL_MACRO__
#define __PMU_PMU_WDOG_CTRL_MACRO__

/* macros for field pmu_wdog_enable */
/**
 * @defgroup pmu_top_regs_core_pmu_wdog_enable_field pmu_wdog_enable_field
 * @brief macros for field pmu_wdog_enable
 * @details set to 1 to enable and start pmu watchdog, set to 0 to disable and reset Timer value is {pmu1.timer_target_msb,pmu0.timer_target_lsb} + pmu_wdog_timeout cycles of 32KHz, early warning indication or SOC_OFF wakeup happens at timer target value, leaving pmu_wdog_timeout time remaining. When pmu watchdog is in use, SW needs to ensure max valid SOC_OFF timer value is max timer_target - pmu_wdog_timeout
 * @{
 */
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__SHIFT                             0
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__WIDTH                             1
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__MASK                    0x00000001U
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_ENABLE__RESET_VALUE             0x00000000U
/** @} */

/* macros for field pmu_wdog_timeout */
/**
 * @defgroup pmu_top_regs_core_pmu_wdog_timeout_field pmu_wdog_timeout_field
 * @brief macros for field pmu_wdog_timeout
 * @details selects a fixed 1sec (set to 0) or 32sec (set to 1) timeout value added to timer target value
 * @{
 */
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__SHIFT                            1
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__WIDTH                            1
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__MASK                   0x00000002U
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PMU_PMU_WDOG_CTRL__PMU_WDOG_TIMEOUT__RESET_VALUE            0x00000001U
/** @} */
#define PMU_PMU_WDOG_CTRL__TYPE                                        uint32_t
#define PMU_PMU_WDOG_CTRL__READ                                     0x00000003U
#define PMU_PMU_WDOG_CTRL__WRITE                                    0x00000003U
#define PMU_PMU_WDOG_CTRL__PRESERVED                                0x00000000U
#define PMU_PMU_WDOG_CTRL__RESET_VALUE                              0x00000002U

#endif /* __PMU_PMU_WDOG_CTRL_MACRO__ */

/** @} end of pmu_wdog_ctrl */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_wdog */
/**
 * @defgroup pmu_top_regs_core_pmu_wdog pmu_wdog
 * @brief pmu watchdog keepalive register definitions.
 * @{
 */
#ifndef __PMU_PMU_WDOG_MACRO__
#define __PMU_PMU_WDOG_MACRO__

/* macros for field pmu_wdog_restart */
/**
 * @defgroup pmu_top_regs_core_pmu_wdog_restart_field pmu_wdog_restart_field
 * @brief macros for field pmu_wdog_restart
 * @details SW reads to this register will reset/restart pmu watchdog timer if enabled
 * @{
 */
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__SHIFT                                 0
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__WIDTH                                 1
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__MASK                        0x00000001U
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU_WDOG__PMU_WDOG_RESTART__RESET_VALUE                 0x00000000U
/** @} */
#define PMU_PMU_WDOG__TYPE                                             uint32_t
#define PMU_PMU_WDOG__READ                                          0x00000001U
#define PMU_PMU_WDOG__WRITE                                         0x00000001U
#define PMU_PMU_WDOG__PRESERVED                                     0x00000000U
#define PMU_PMU_WDOG__RESET_VALUE                                   0x00000000U

#endif /* __PMU_PMU_WDOG_MACRO__ */

/** @} end of pmu_wdog */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_wdog_status */
/**
 * @defgroup pmu_top_regs_core_pmu_wdog_status pmu_wdog_status
 * @brief external pmu watchdog reset readback status register definitions.
 * @{
 */
#ifndef __PMU_PMU_WDOG_STATUS_MACRO__
#define __PMU_PMU_WDOG_STATUS_MACRO__

/* macros for field pmu_wdog_status */
/**
 * @defgroup pmu_top_regs_core_pmu_wdog_status_field pmu_wdog_status_field
 * @brief macros for field pmu_wdog_status
 * @details HW write sets status when pmu wdog reset has been asserted, SW write clears status
 * @{
 */
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__SHIFT                           0
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__WIDTH                           1
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__MASK                  0x00000001U
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PMU_PMU_WDOG_STATUS__PMU_WDOG_STATUS__RESET_VALUE           0x00000000U
/** @} */
#define PMU_PMU_WDOG_STATUS__TYPE                                      uint32_t
#define PMU_PMU_WDOG_STATUS__READ                                   0x00000001U
#define PMU_PMU_WDOG_STATUS__WRITE                                  0x00000001U
#define PMU_PMU_WDOG_STATUS__PRESERVED                              0x00000000U
#define PMU_PMU_WDOG_STATUS__RESET_VALUE                            0x00000000U

#endif /* __PMU_PMU_WDOG_STATUS_MACRO__ */

/** @} end of pmu_wdog_status */

/* macros for BlueprintGlobalNameSpace::PMU_pmu_swCnt_rb */
/**
 * @defgroup pmu_top_regs_core_pmu_swCnt_rb pmu_swCnt_rb
 * @brief readback count values for software definitions.
 * @{
 */
#ifndef __PMU_PMU_SWCNT_RB_MACRO__
#define __PMU_PMU_SWCNT_RB_MACRO__

/* macros for field pmu_swCnt_active */
/**
 * @defgroup pmu_top_regs_core_pmu_swCnt_active_field pmu_swCnt_active_field
 * @brief macros for field pmu_swCnt_active
 * @details counter value for active
 * @{
 */
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_ACTIVE__SHIFT                             0
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_ACTIVE__WIDTH                            16
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_ACTIVE__MASK                    0x0000ffffU
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_ACTIVE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_ACTIVE__RESET_VALUE             0x00000000U
/** @} */

/* macros for field pmu_swCnt_lp */
/**
 * @defgroup pmu_top_regs_core_pmu_swCnt_lp_field pmu_swCnt_lp_field
 * @brief macros for field pmu_swCnt_lp
 * @details counter value for low power
 * @{
 */
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_LP__SHIFT                                16
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_LP__WIDTH                                16
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_LP__MASK                        0xffff0000U
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PMU_PMU_SWCNT_RB__PMU_SWCNT_LP__RESET_VALUE                 0x00000000U
/** @} */
#define PMU_PMU_SWCNT_RB__TYPE                                         uint32_t
#define PMU_PMU_SWCNT_RB__READ                                      0xffffffffU
#define PMU_PMU_SWCNT_RB__PRESERVED                                 0x00000000U
#define PMU_PMU_SWCNT_RB__RESET_VALUE                               0x00000000U

#endif /* __PMU_PMU_SWCNT_RB_MACRO__ */

/** @} end of pmu_swCnt_rb */

/** @} end of PMU_TOP_REGS_CORE */
#endif /* __REG_PMU_TOP_REGS_CORE_H__ */
