/*                                                                           */
/* File:       at_apb_rcos_cal_regs_core_macro.h                             */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_rcos_cal_regs_core.rdl      */
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


#ifndef __REG_AT_APB_RCOS_CAL_REGS_CORE_H__
#define __REG_AT_APB_RCOS_CAL_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_RCOS_CAL_REGS_CORE at_apb_rcos_cal_regs_core
 * @ingroup AT_REG
 * @brief at_apb_rcos_cal_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_cal_ctrl */
/**
 * @defgroup at_apb_rcos_cal_regs_core_cal_ctrl cal_ctrl
 * @brief Contains register fields associated with cal_ctrl. definitions.
 * @{
 */
#ifndef __RCOS_CAL_CAL_CTRL_MACRO__
#define __RCOS_CAL_CAL_CTRL_MACRO__

/* macros for field sw_cal */
/**
 * @defgroup at_apb_rcos_cal_regs_core_sw_cal_field sw_cal_field
 * @brief macros for field sw_cal
 * @details rising edge starts SW cal, falling edge terminates cal if cal is not done; best to leave it on once set.
 * @{
 */
#define RCOS_CAL_CAL_CTRL__SW_CAL__SHIFT                                      0
#define RCOS_CAL_CAL_CTRL__SW_CAL__WIDTH                                      1
#define RCOS_CAL_CAL_CTRL__SW_CAL__MASK                             0x00000001U
#define RCOS_CAL_CAL_CTRL__SW_CAL__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define RCOS_CAL_CAL_CTRL__SW_CAL__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define RCOS_CAL_CAL_CTRL__SW_CAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RCOS_CAL_CAL_CTRL__SW_CAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RCOS_CAL_CAL_CTRL__SW_CAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_CAL_CTRL__SW_CAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_CAL_CTRL__SW_CAL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field hw_cal_sel */
/**
 * @defgroup at_apb_rcos_cal_regs_core_hw_cal_sel_field hw_cal_sel_field
 * @brief macros for field hw_cal_sel
 * @details 1=choose cal from HW; 0=choose cal from SW
 * @{
 */
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__SHIFT                                  1
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__WIDTH                                  1
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__MASK                         0x00000002U
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RCOS_CAL_CAL_CTRL__HW_CAL_SEL__RESET_VALUE                  0x00000000U
/** @} */
#define RCOS_CAL_CAL_CTRL__TYPE                                        uint32_t
#define RCOS_CAL_CAL_CTRL__READ                                     0x00000003U
#define RCOS_CAL_CAL_CTRL__WRITE                                    0x00000003U
#define RCOS_CAL_CAL_CTRL__PRESERVED                                0x00000000U
#define RCOS_CAL_CAL_CTRL__RESET_VALUE                              0x00000000U

#endif /* __RCOS_CAL_CAL_CTRL_MACRO__ */

/** @} end of cal_ctrl */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_slow_clk_set */
/**
 * @defgroup at_apb_rcos_cal_regs_core_slow_clk_set slow_clk_set
 * @brief Contains register fields associated with slow_clk_set. definitions.
 * @{
 */
#ifndef __RCOS_CAL_SLOW_CLK_SET_MACRO__
#define __RCOS_CAL_SLOW_CLK_SET_MACRO__

/* macros for field slow_clk_set */
/**
 * @defgroup at_apb_rcos_cal_regs_core_slow_clk_set_field slow_clk_set_field
 * @brief macros for field slow_clk_set
 * @details set the number of cycles to run slow clock; counting stops when this number is reached or cal is pulled down. constraint: 1 <= slow_clk_set <= 63; if set 0, hardware will use 1.
 * @{
 */
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__SHIFT                            0
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__WIDTH                           12
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__MASK                   0x00000fffU
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000fffU)
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000fffU)
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((uint32_t)(src) &\
                    0x00000fffU)
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000fffU)))
#define RCOS_CAL_SLOW_CLK_SET__SLOW_CLK_SET__RESET_VALUE            0x00000064U
/** @} */
#define RCOS_CAL_SLOW_CLK_SET__TYPE                                    uint32_t
#define RCOS_CAL_SLOW_CLK_SET__READ                                 0x00000fffU
#define RCOS_CAL_SLOW_CLK_SET__WRITE                                0x00000fffU
#define RCOS_CAL_SLOW_CLK_SET__PRESERVED                            0x00000000U
#define RCOS_CAL_SLOW_CLK_SET__RESET_VALUE                          0x00000064U

#endif /* __RCOS_CAL_SLOW_CLK_SET_MACRO__ */

/** @} end of slow_clk_set */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_slow_clk_cnt */
/**
 * @defgroup at_apb_rcos_cal_regs_core_slow_clk_cnt slow_clk_cnt
 * @brief Contains register fields associated with slow_clk_cnt. definitions.
 * @{
 */
#ifndef __RCOS_CAL_SLOW_CLK_CNT_MACRO__
#define __RCOS_CAL_SLOW_CLK_CNT_MACRO__

/* macros for field slow_clk_cnt */
/**
 * @defgroup at_apb_rcos_cal_regs_core_slow_clk_cnt_field slow_clk_cnt_field
 * @brief macros for field slow_clk_cnt
 * @details number of cycles counted by slow clock.
 * @{
 */
#define RCOS_CAL_SLOW_CLK_CNT__SLOW_CLK_CNT__SHIFT                            0
#define RCOS_CAL_SLOW_CLK_CNT__SLOW_CLK_CNT__WIDTH                           12
#define RCOS_CAL_SLOW_CLK_CNT__SLOW_CLK_CNT__MASK                   0x00000fffU
#define RCOS_CAL_SLOW_CLK_CNT__SLOW_CLK_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000fffU)
#define RCOS_CAL_SLOW_CLK_CNT__SLOW_CLK_CNT__RESET_VALUE            0x00000000U
/** @} */
#define RCOS_CAL_SLOW_CLK_CNT__TYPE                                    uint32_t
#define RCOS_CAL_SLOW_CLK_CNT__READ                                 0x00000fffU
#define RCOS_CAL_SLOW_CLK_CNT__PRESERVED                            0x00000000U
#define RCOS_CAL_SLOW_CLK_CNT__RESET_VALUE                          0x00000000U

#endif /* __RCOS_CAL_SLOW_CLK_CNT_MACRO__ */

/** @} end of slow_clk_cnt */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_fast_clk_cnt */
/**
 * @defgroup at_apb_rcos_cal_regs_core_fast_clk_cnt fast_clk_cnt
 * @brief Contains register fields associated with fast_clk_cnt. definitions.
 * @{
 */
#ifndef __RCOS_CAL_FAST_CLK_CNT_MACRO__
#define __RCOS_CAL_FAST_CLK_CNT_MACRO__

/* macros for field fast_clk_cnt */
/**
 * @defgroup at_apb_rcos_cal_regs_core_fast_clk_cnt_field fast_clk_cnt_field
 * @brief macros for field fast_clk_cnt
 * @details number of cycles counted by fast clock. 10 bits more than slow_clk_cnt/set because fast clock is 1000 times faster.
 * @{
 */
#define RCOS_CAL_FAST_CLK_CNT__FAST_CLK_CNT__SHIFT                            0
#define RCOS_CAL_FAST_CLK_CNT__FAST_CLK_CNT__WIDTH                           22
#define RCOS_CAL_FAST_CLK_CNT__FAST_CLK_CNT__MASK                   0x003fffffU
#define RCOS_CAL_FAST_CLK_CNT__FAST_CLK_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x003fffffU)
#define RCOS_CAL_FAST_CLK_CNT__FAST_CLK_CNT__RESET_VALUE            0x00000000U
/** @} */
#define RCOS_CAL_FAST_CLK_CNT__TYPE                                    uint32_t
#define RCOS_CAL_FAST_CLK_CNT__READ                                 0x003fffffU
#define RCOS_CAL_FAST_CLK_CNT__PRESERVED                            0x00000000U
#define RCOS_CAL_FAST_CLK_CNT__RESET_VALUE                          0x00000000U

#endif /* __RCOS_CAL_FAST_CLK_CNT_MACRO__ */

/** @} end of fast_clk_cnt */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_source_clk_sel */
/**
 * @defgroup at_apb_rcos_cal_regs_core_source_clk_sel source_clk_sel
 * @brief Contains register fields associated with source_clk_sel. definitions.
 * @{
 */
#ifndef __RCOS_CAL_SOURCE_CLK_SEL_MACRO__
#define __RCOS_CAL_SOURCE_CLK_SEL_MACRO__

/* macros for field slow_clk_sel */
/**
 * @defgroup at_apb_rcos_cal_regs_core_slow_clk_sel_field slow_clk_sel_field
 * @brief macros for field slow_clk_sel
 * @details 0=slow clk source is clk_lpc;1=slow clk source is clk_calfc
 * @{
 */
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__SHIFT                          0
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__WIDTH                          1
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__MASK                 0x00000001U
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_SOURCE_CLK_SEL__SLOW_CLK_SEL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field fast_clk_sel */
/**
 * @defgroup at_apb_rcos_cal_regs_core_fast_clk_sel_field fast_clk_sel_field
 * @brief macros for field fast_clk_sel
 * @details 0=fast clk source is PCLk; 1=fast clk source is clk_calfc
 * @{
 */
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__SHIFT                          1
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__WIDTH                          1
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__MASK                 0x00000002U
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RCOS_CAL_SOURCE_CLK_SEL__FAST_CLK_SEL__RESET_VALUE          0x00000000U
/** @} */
#define RCOS_CAL_SOURCE_CLK_SEL__TYPE                                  uint32_t
#define RCOS_CAL_SOURCE_CLK_SEL__READ                               0x00000003U
#define RCOS_CAL_SOURCE_CLK_SEL__WRITE                              0x00000003U
#define RCOS_CAL_SOURCE_CLK_SEL__PRESERVED                          0x00000000U
#define RCOS_CAL_SOURCE_CLK_SEL__RESET_VALUE                        0x00000000U

#endif /* __RCOS_CAL_SOURCE_CLK_SEL_MACRO__ */

/** @} end of source_clk_sel */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_force_reset */
/**
 * @defgroup at_apb_rcos_cal_regs_core_force_reset force_reset
 * @brief Contains register fields associated with force_reset. definitions.
 * @{
 */
#ifndef __RCOS_CAL_FORCE_RESET_MACRO__
#define __RCOS_CAL_FORCE_RESET_MACRO__

/* macros for field force_reset */
/**
 * @defgroup at_apb_rcos_cal_regs_core_force_reset_field force_reset_field
 * @brief macros for field force_reset
 * @details 1=apply force reset to fast domain and slow domain.  0=release force reset.
 * @{
 */
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__SHIFT                              0
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__WIDTH                              1
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__MASK                     0x00000001U
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_FORCE_RESET__FORCE_RESET__RESET_VALUE              0x00000000U
/** @} */
#define RCOS_CAL_FORCE_RESET__TYPE                                     uint32_t
#define RCOS_CAL_FORCE_RESET__READ                                  0x00000001U
#define RCOS_CAL_FORCE_RESET__WRITE                                 0x00000001U
#define RCOS_CAL_FORCE_RESET__PRESERVED                             0x00000000U
#define RCOS_CAL_FORCE_RESET__RESET_VALUE                           0x00000000U

#endif /* __RCOS_CAL_FORCE_RESET_MACRO__ */

/** @} end of force_reset */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_stat */
/**
 * @defgroup at_apb_rcos_cal_regs_core_stat stat
 * @brief Contains register fields associated with stat. definitions.
 * @{
 */
#ifndef __RCOS_CAL_STAT_MACRO__
#define __RCOS_CAL_STAT_MACRO__

/* macros for field running */
/**
 * @defgroup at_apb_rcos_cal_regs_core_running_field running_field
 * @brief macros for field running
 * @{
 */
#define RCOS_CAL_STAT__RUNNING__SHIFT                                         0
#define RCOS_CAL_STAT__RUNNING__WIDTH                                         1
#define RCOS_CAL_STAT__RUNNING__MASK                                0x00000001U
#define RCOS_CAL_STAT__RUNNING__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define RCOS_CAL_STAT__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_STAT__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_STAT__RUNNING__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field high_precision_run */
/**
 * @defgroup at_apb_rcos_cal_regs_core_high_precision_run_field high_precision_run_field
 * @brief macros for field high_precision_run
 * @details 1=high-precisioned clock was used at the beginning of cal; 0=low precisioned clock
 * @{
 */
#define RCOS_CAL_STAT__HIGH_PRECISION_RUN__SHIFT                              1
#define RCOS_CAL_STAT__HIGH_PRECISION_RUN__WIDTH                              1
#define RCOS_CAL_STAT__HIGH_PRECISION_RUN__MASK                     0x00000002U
#define RCOS_CAL_STAT__HIGH_PRECISION_RUN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RCOS_CAL_STAT__HIGH_PRECISION_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RCOS_CAL_STAT__HIGH_PRECISION_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RCOS_CAL_STAT__HIGH_PRECISION_RUN__RESET_VALUE              0x00000000U
/** @} */

/* macros for field slow_domain_reset_stat */
/**
 * @defgroup at_apb_rcos_cal_regs_core_slow_domain_reset_stat_field slow_domain_reset_stat_field
 * @brief macros for field slow_domain_reset_stat
 * @details 1=slow_clk domain is still in reset; don't triger cal
 * @{
 */
#define RCOS_CAL_STAT__SLOW_DOMAIN_RESET_STAT__SHIFT                          2
#define RCOS_CAL_STAT__SLOW_DOMAIN_RESET_STAT__WIDTH                          1
#define RCOS_CAL_STAT__SLOW_DOMAIN_RESET_STAT__MASK                 0x00000004U
#define RCOS_CAL_STAT__SLOW_DOMAIN_RESET_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RCOS_CAL_STAT__SLOW_DOMAIN_RESET_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RCOS_CAL_STAT__SLOW_DOMAIN_RESET_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RCOS_CAL_STAT__SLOW_DOMAIN_RESET_STAT__RESET_VALUE          0x00000000U
/** @} */

/* macros for field fast_domain_reset_stat */
/**
 * @defgroup at_apb_rcos_cal_regs_core_fast_domain_reset_stat_field fast_domain_reset_stat_field
 * @brief macros for field fast_domain_reset_stat
 * @details 1=fast_clk domain is still in reset; don't triger cal
 * @{
 */
#define RCOS_CAL_STAT__FAST_DOMAIN_RESET_STAT__SHIFT                          3
#define RCOS_CAL_STAT__FAST_DOMAIN_RESET_STAT__WIDTH                          1
#define RCOS_CAL_STAT__FAST_DOMAIN_RESET_STAT__MASK                 0x00000008U
#define RCOS_CAL_STAT__FAST_DOMAIN_RESET_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RCOS_CAL_STAT__FAST_DOMAIN_RESET_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RCOS_CAL_STAT__FAST_DOMAIN_RESET_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RCOS_CAL_STAT__FAST_DOMAIN_RESET_STAT__RESET_VALUE          0x00000000U
/** @} */
#define RCOS_CAL_STAT__TYPE                                            uint32_t
#define RCOS_CAL_STAT__READ                                         0x0000000fU
#define RCOS_CAL_STAT__PRESERVED                                    0x00000000U
#define RCOS_CAL_STAT__RESET_VALUE                                  0x00000000U

#endif /* __RCOS_CAL_STAT_MACRO__ */

/** @} end of stat */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_interrupt_status */
/**
 * @defgroup at_apb_rcos_cal_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __RCOS_CAL_INTERRUPT_STATUS_MACRO__
#define __RCOS_CAL_INTERRUPT_STATUS_MACRO__

/* macros for field rcos_done */
/**
 * @defgroup at_apb_rcos_cal_regs_core_rcos_done_field rcos_done_field
 * @brief macros for field rcos_done
 * @{
 */
#define RCOS_CAL_INTERRUPT_STATUS__RCOS_DONE__SHIFT                           0
#define RCOS_CAL_INTERRUPT_STATUS__RCOS_DONE__WIDTH                           1
#define RCOS_CAL_INTERRUPT_STATUS__RCOS_DONE__MASK                  0x00000001U
#define RCOS_CAL_INTERRUPT_STATUS__RCOS_DONE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_INTERRUPT_STATUS__RCOS_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_INTERRUPT_STATUS__RCOS_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_INTERRUPT_STATUS__RCOS_DONE__RESET_VALUE           0x00000000U
/** @} */
#define RCOS_CAL_INTERRUPT_STATUS__TYPE                                uint32_t
#define RCOS_CAL_INTERRUPT_STATUS__READ                             0x00000001U
#define RCOS_CAL_INTERRUPT_STATUS__PRESERVED                        0x00000000U
#define RCOS_CAL_INTERRUPT_STATUS__RESET_VALUE                      0x00000000U

#endif /* __RCOS_CAL_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_interrupt_mask */
/**
 * @defgroup at_apb_rcos_cal_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __RCOS_CAL_INTERRUPT_MASK_MACRO__
#define __RCOS_CAL_INTERRUPT_MASK_MACRO__

/* macros for field intrpt_mask */
/**
 * @defgroup at_apb_rcos_cal_regs_core_intrpt_mask_field intrpt_mask_field
 * @brief macros for field intrpt_mask
 * @details if nth bit set, the nth interrupt source is allowed to propogate to core's interrupt
 * @{
 */
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__SHIFT                           0
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__WIDTH                           1
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__MASK                  0x00000001U
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_INTERRUPT_MASK__INTRPT_MASK__RESET_VALUE           0x00000001U
/** @} */
#define RCOS_CAL_INTERRUPT_MASK__TYPE                                  uint32_t
#define RCOS_CAL_INTERRUPT_MASK__READ                               0x00000001U
#define RCOS_CAL_INTERRUPT_MASK__WRITE                              0x00000001U
#define RCOS_CAL_INTERRUPT_MASK__PRESERVED                          0x00000000U
#define RCOS_CAL_INTERRUPT_MASK__RESET_VALUE                        0x00000001U

#endif /* __RCOS_CAL_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_set_interrupt */
/**
 * @defgroup at_apb_rcos_cal_regs_core_set_interrupt set_interrupt
 * @brief Contains register fields associated with set_interrupt. definitions.
 * @{
 */
#ifndef __RCOS_CAL_SET_INTERRUPT_MACRO__
#define __RCOS_CAL_SET_INTERRUPT_MACRO__

/* macros for field intrpt_set */
/**
 * @defgroup at_apb_rcos_cal_regs_core_intrpt_set_field intrpt_set_field
 * @brief macros for field intrpt_set
 * @details if nth bit set, the nth interrupt is set. (__SELF_CLEARING__)
 * @{
 */
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__SHIFT                             0
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__WIDTH                             1
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__MASK                    0x00000001U
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_SET_INTERRUPT__INTRPT_SET__RESET_VALUE             0x00000000U
/** @} */
#define RCOS_CAL_SET_INTERRUPT__TYPE                                   uint32_t
#define RCOS_CAL_SET_INTERRUPT__READ                                0x00000001U
#define RCOS_CAL_SET_INTERRUPT__WRITE                               0x00000001U
#define RCOS_CAL_SET_INTERRUPT__PRESERVED                           0x00000000U
#define RCOS_CAL_SET_INTERRUPT__RESET_VALUE                         0x00000000U

#endif /* __RCOS_CAL_SET_INTERRUPT_MACRO__ */

/** @} end of set_interrupt */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_reset_interrupt */
/**
 * @defgroup at_apb_rcos_cal_regs_core_reset_interrupt reset_interrupt
 * @brief Contains register fields associated with reset_interrupt. definitions.
 * @{
 */
#ifndef __RCOS_CAL_RESET_INTERRUPT_MACRO__
#define __RCOS_CAL_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_apb_rcos_cal_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details if nth bit set, the nth interrupt is reset. (__SELF_CLEARING__)
 * @{
 */
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__SHIFT                         0
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__WIDTH                         1
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__MASK                0x00000001U
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RCOS_CAL_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE         0x00000000U
/** @} */
#define RCOS_CAL_RESET_INTERRUPT__TYPE                                 uint32_t
#define RCOS_CAL_RESET_INTERRUPT__READ                              0x00000001U
#define RCOS_CAL_RESET_INTERRUPT__WRITE                             0x00000001U
#define RCOS_CAL_RESET_INTERRUPT__PRESERVED                         0x00000000U
#define RCOS_CAL_RESET_INTERRUPT__RESET_VALUE                       0x00000000U

#endif /* __RCOS_CAL_RESET_INTERRUPT_MACRO__ */

/** @} end of reset_interrupt */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_core_id */
/**
 * @defgroup at_apb_rcos_cal_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __RCOS_CAL_CORE_ID_MACRO__
#define __RCOS_CAL_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_rcos_cal_regs_core_id_field id_field
 * @brief macros for field id
 * @details RCOS in ASCII
 * @{
 */
#define RCOS_CAL_CORE_ID__ID__SHIFT                                           0
#define RCOS_CAL_CORE_ID__ID__WIDTH                                          32
#define RCOS_CAL_CORE_ID__ID__MASK                                  0xffffffffU
#define RCOS_CAL_CORE_ID__ID__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define RCOS_CAL_CORE_ID__ID__RESET_VALUE                           0x52434f53U
/** @} */
#define RCOS_CAL_CORE_ID__TYPE                                         uint32_t
#define RCOS_CAL_CORE_ID__READ                                      0xffffffffU
#define RCOS_CAL_CORE_ID__PRESERVED                                 0x00000000U
#define RCOS_CAL_CORE_ID__RESET_VALUE                               0x52434f53U

#endif /* __RCOS_CAL_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_rev_hash */
/**
 * @defgroup at_apb_rcos_cal_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __RCOS_CAL_REV_HASH_MACRO__
#define __RCOS_CAL_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_rcos_cal_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define RCOS_CAL_REV_HASH__ID__SHIFT                                          0
#define RCOS_CAL_REV_HASH__ID__WIDTH                                         32
#define RCOS_CAL_REV_HASH__ID__MASK                                 0xffffffffU
#define RCOS_CAL_REV_HASH__ID__READ(src)        ((uint32_t)(src) & 0xffffffffU)
#define RCOS_CAL_REV_HASH__ID__RESET_VALUE                          0xbc29cd62U
/** @} */
#define RCOS_CAL_REV_HASH__TYPE                                        uint32_t
#define RCOS_CAL_REV_HASH__READ                                     0xffffffffU
#define RCOS_CAL_REV_HASH__PRESERVED                                0x00000000U
#define RCOS_CAL_REV_HASH__RESET_VALUE                              0xbc29cd62U

#endif /* __RCOS_CAL_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::RCOS_CAL_rev_key */
/**
 * @defgroup at_apb_rcos_cal_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __RCOS_CAL_REV_KEY_MACRO__
#define __RCOS_CAL_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_rcos_cal_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define RCOS_CAL_REV_KEY__ID__SHIFT                                           0
#define RCOS_CAL_REV_KEY__ID__WIDTH                                          32
#define RCOS_CAL_REV_KEY__ID__MASK                                  0xffffffffU
#define RCOS_CAL_REV_KEY__ID__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define RCOS_CAL_REV_KEY__ID__RESET_VALUE                           0x52455620U
/** @} */
#define RCOS_CAL_REV_KEY__TYPE                                         uint32_t
#define RCOS_CAL_REV_KEY__READ                                      0xffffffffU
#define RCOS_CAL_REV_KEY__PRESERVED                                 0x00000000U
#define RCOS_CAL_REV_KEY__RESET_VALUE                               0x52455620U

#endif /* __RCOS_CAL_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_RCOS_CAL_REGS_CORE */
#endif /* __REG_AT_APB_RCOS_CAL_REGS_CORE_H__ */
