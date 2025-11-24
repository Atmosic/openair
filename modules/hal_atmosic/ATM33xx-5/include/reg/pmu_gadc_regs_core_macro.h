/*                                                                           */
/* File:       pmu_gadc_regs_core_macro.h                                    */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic pmu_gadc_regs_core.rdl             */
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


#ifndef __REG_PMU_GADC_REGS_CORE_H__
#define __REG_PMU_GADC_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup PMU_GADC_REGS_CORE pmu_gadc_regs_core
 * @ingroup AT_REG
 * @brief pmu_gadc_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::GADC_gadc_ctrl */
/**
 * @defgroup pmu_gadc_regs_core_gadc_ctrl gadc_ctrl
 * @brief Bias, reference voltage, sampling time settings, ATB definitions.
 * @{
 */
#ifndef __GADC_GADC_CTRL_MACRO__
#define __GADC_GADC_CTRL_MACRO__

/* macros for field bias_ctrl */
/**
 * @defgroup pmu_gadc_regs_core_bias_ctrl_field bias_ctrl_field
 * @brief macros for field bias_ctrl
 * @details Master bias, all the bias has scaling factor of bias/0.5, I = 0.5/(1+(bias_ctrl-3)/6) uA
 * @{
 */
#define GADC_GADC_CTRL__BIAS_CTRL__SHIFT                                      0
#define GADC_GADC_CTRL__BIAS_CTRL__WIDTH                                      3
#define GADC_GADC_CTRL__BIAS_CTRL__MASK                             0x00000007U
#define GADC_GADC_CTRL__BIAS_CTRL__READ(src)    ((uint32_t)(src) & 0x00000007U)
#define GADC_GADC_CTRL__BIAS_CTRL__WRITE(src)   ((uint32_t)(src) & 0x00000007U)
#define GADC_GADC_CTRL__BIAS_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define GADC_GADC_CTRL__BIAS_CTRL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define GADC_GADC_CTRL__BIAS_CTRL__RESET_VALUE                      0x00000003U
/** @} */

/* macros for field ir2u_ctrl */
/**
 * @defgroup pmu_gadc_regs_core_ir2u_ctrl_field ir2u_ctrl_field
 * @brief macros for field ir2u_ctrl
 * @details 2uA bias current for the adc driver opamp, I = 2 + 0.5*(ir2u_ctrl-2) uA
 * @{
 */
#define GADC_GADC_CTRL__IR2U_CTRL__SHIFT                                      3
#define GADC_GADC_CTRL__IR2U_CTRL__WIDTH                                      2
#define GADC_GADC_CTRL__IR2U_CTRL__MASK                             0x00000018U
#define GADC_GADC_CTRL__IR2U_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000018U) >> 3)
#define GADC_GADC_CTRL__IR2U_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000018U)
#define GADC_GADC_CTRL__IR2U_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000018U) | (((uint32_t)(src) <<\
                    3) & 0x00000018U)
#define GADC_GADC_CTRL__IR2U_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000018U)))
#define GADC_GADC_CTRL__IR2U_CTRL__RESET_VALUE                      0x00000002U
/** @} */

/* macros for field vcmbuf_ctrl */
/**
 * @defgroup pmu_gadc_regs_core_vcmbuf_ctrl_field vcmbuf_ctrl_field
 * @brief macros for field vcmbuf_ctrl
 * @details ADC driver output common mode control, V = 0.55+0.1375*(vcmbuf_ctrl-1) V
 * @{
 */
#define GADC_GADC_CTRL__VCMBUF_CTRL__SHIFT                                    5
#define GADC_GADC_CTRL__VCMBUF_CTRL__WIDTH                                    2
#define GADC_GADC_CTRL__VCMBUF_CTRL__MASK                           0x00000060U
#define GADC_GADC_CTRL__VCMBUF_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000060U) >> 5)
#define GADC_GADC_CTRL__VCMBUF_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000060U)
#define GADC_GADC_CTRL__VCMBUF_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define GADC_GADC_CTRL__VCMBUF_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define GADC_GADC_CTRL__VCMBUF_CTRL__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field vcmadc_ctrl */
/**
 * @defgroup pmu_gadc_regs_core_vcmadc_ctrl_field vcmadc_ctrl_field
 * @brief macros for field vcmadc_ctrl
 * @details ADC sampling common mode voltage, V=0.55+0.1375*(vcmadc_ctrl-2) V
 * @{
 */
#define GADC_GADC_CTRL__VCMADC_CTRL__SHIFT                                    7
#define GADC_GADC_CTRL__VCMADC_CTRL__WIDTH                                    2
#define GADC_GADC_CTRL__VCMADC_CTRL__MASK                           0x00000180U
#define GADC_GADC_CTRL__VCMADC_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000180U) >> 7)
#define GADC_GADC_CTRL__VCMADC_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000180U)
#define GADC_GADC_CTRL__VCMADC_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000180U) | (((uint32_t)(src) <<\
                    7) & 0x00000180U)
#define GADC_GADC_CTRL__VCMADC_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000180U)))
#define GADC_GADC_CTRL__VCMADC_CTRL__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field adcref_ctrl */
/**
 * @defgroup pmu_gadc_regs_core_adcref_ctrl_field adcref_ctrl_field
 * @brief macros for field adcref_ctrl
 * @details ADC core reference voltage, 0.84V - 1.4V, V = 1 + (-0.4)/(1+6/(adcref_ctrl-3)) V
 * @{
 */
#define GADC_GADC_CTRL__ADCREF_CTRL__SHIFT                                    9
#define GADC_GADC_CTRL__ADCREF_CTRL__WIDTH                                    3
#define GADC_GADC_CTRL__ADCREF_CTRL__MASK                           0x00000e00U
#define GADC_GADC_CTRL__ADCREF_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define GADC_GADC_CTRL__ADCREF_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define GADC_GADC_CTRL__ADCREF_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define GADC_GADC_CTRL__ADCREF_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define GADC_GADC_CTRL__ADCREF_CTRL__RESET_VALUE                    0x00000003U
/** @} */

/* macros for field delay_ctrl */
/**
 * @defgroup pmu_gadc_regs_core_delay_ctrl_field delay_ctrl_field
 * @brief macros for field delay_ctrl
 * @details SAR logic delay control bias current, high current is less delay, I = 2 + 0.25*(delay_ctrl-4) uA
 * @{
 */
#define GADC_GADC_CTRL__DELAY_CTRL__SHIFT                                    12
#define GADC_GADC_CTRL__DELAY_CTRL__WIDTH                                     3
#define GADC_GADC_CTRL__DELAY_CTRL__MASK                            0x00007000U
#define GADC_GADC_CTRL__DELAY_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define GADC_GADC_CTRL__DELAY_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define GADC_GADC_CTRL__DELAY_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define GADC_GADC_CTRL__DELAY_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define GADC_GADC_CTRL__DELAY_CTRL__RESET_VALUE                     0x00000004U
/** @} */

/* macros for field li_en */
/**
 * @defgroup pmu_gadc_regs_core_li_en_field li_en_field
 * @brief macros for field li_en
 * @details Enable lithium ion battery voltage measurement
 * @{
 */
#define GADC_GADC_CTRL__LI_EN__SHIFT                                         15
#define GADC_GADC_CTRL__LI_EN__WIDTH                                          1
#define GADC_GADC_CTRL__LI_EN__MASK                                 0x00008000U
#define GADC_GADC_CTRL__LI_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define GADC_GADC_CTRL__LI_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define GADC_GADC_CTRL__LI_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define GADC_GADC_CTRL__LI_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define GADC_GADC_CTRL__LI_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define GADC_GADC_CTRL__LI_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define GADC_GADC_CTRL__LI_EN__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field bypass */
/**
 * @defgroup pmu_gadc_regs_core_bypass_field bypass_field
 * @brief macros for field bypass
 * @details Bypass ADC driver
 * @{
 */
#define GADC_GADC_CTRL__BYPASS__SHIFT                                        16
#define GADC_GADC_CTRL__BYPASS__WIDTH                                         1
#define GADC_GADC_CTRL__BYPASS__MASK                                0x00010000U
#define GADC_GADC_CTRL__BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define GADC_GADC_CTRL__BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define GADC_GADC_CTRL__BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define GADC_GADC_CTRL__BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define GADC_GADC_CTRL__BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define GADC_GADC_CTRL__BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define GADC_GADC_CTRL__BYPASS__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field clamp */
/**
 * @defgroup pmu_gadc_regs_core_clamp_field clamp_field
 * @brief macros for field clamp
 * @details Core circuit protection clamp enable
 * @{
 */
#define GADC_GADC_CTRL__CLAMP__SHIFT                                         17
#define GADC_GADC_CTRL__CLAMP__WIDTH                                          1
#define GADC_GADC_CTRL__CLAMP__MASK                                 0x00020000U
#define GADC_GADC_CTRL__CLAMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define GADC_GADC_CTRL__CLAMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define GADC_GADC_CTRL__CLAMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define GADC_GADC_CTRL__CLAMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define GADC_GADC_CTRL__CLAMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define GADC_GADC_CTRL__CLAMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define GADC_GADC_CTRL__CLAMP__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field edge_sel */
/**
 * @defgroup pmu_gadc_regs_core_edge_sel_field edge_sel_field
 * @brief macros for field edge_sel
 * @details ADC digital output edge select, 1 for rising edge
 * @{
 */
#define GADC_GADC_CTRL__EDGE_SEL__SHIFT                                      18
#define GADC_GADC_CTRL__EDGE_SEL__WIDTH                                       1
#define GADC_GADC_CTRL__EDGE_SEL__MASK                              0x00040000U
#define GADC_GADC_CTRL__EDGE_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define GADC_GADC_CTRL__EDGE_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define GADC_GADC_CTRL__EDGE_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define GADC_GADC_CTRL__EDGE_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define GADC_GADC_CTRL__EDGE_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define GADC_GADC_CTRL__EDGE_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define GADC_GADC_CTRL__EDGE_SEL__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field atbH_sel */
/**
 * @defgroup pmu_gadc_regs_core_atbH_sel_field atbH_sel_field
 * @brief macros for field atbH_sel
 * @details atbH control  0: No connect  1: enable-digital 1V  2: iptat1u  3: refp-0.8V  4: nbias_ir2u  5: vcm_ir4u-0.55V  6: vcm_ir1u-0.55V  7: ir2u
 * @{
 */
#define GADC_GADC_CTRL__ATBH_SEL__SHIFT                                      19
#define GADC_GADC_CTRL__ATBH_SEL__WIDTH                                       4
#define GADC_GADC_CTRL__ATBH_SEL__MASK                              0x00780000U
#define GADC_GADC_CTRL__ATBH_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00780000U) >> 19)
#define GADC_GADC_CTRL__ATBH_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00780000U)
#define GADC_GADC_CTRL__ATBH_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00780000U) | (((uint32_t)(src) <<\
                    19) & 0x00780000U)
#define GADC_GADC_CTRL__ATBH_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00780000U)))
#define GADC_GADC_CTRL__ATBH_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field en_ref */
/**
 * @defgroup pmu_gadc_regs_core_en_ref_field en_ref_field
 * @brief macros for field en_ref
 * @details enable reference generation circuit
 * @{
 */
#define GADC_GADC_CTRL__EN_REF__SHIFT                                        23
#define GADC_GADC_CTRL__EN_REF__WIDTH                                         1
#define GADC_GADC_CTRL__EN_REF__MASK                                0x00800000U
#define GADC_GADC_CTRL__EN_REF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define GADC_GADC_CTRL__EN_REF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define GADC_GADC_CTRL__EN_REF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define GADC_GADC_CTRL__EN_REF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define GADC_GADC_CTRL__EN_REF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define GADC_GADC_CTRL__EN_REF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define GADC_GADC_CTRL__EN_REF__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field en_buffer */
/**
 * @defgroup pmu_gadc_regs_core_en_buffer_field en_buffer_field
 * @brief macros for field en_buffer
 * @details enable buffer
 * @{
 */
#define GADC_GADC_CTRL__EN_BUFFER__SHIFT                                     24
#define GADC_GADC_CTRL__EN_BUFFER__WIDTH                                      1
#define GADC_GADC_CTRL__EN_BUFFER__MASK                             0x01000000U
#define GADC_GADC_CTRL__EN_BUFFER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define GADC_GADC_CTRL__EN_BUFFER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define GADC_GADC_CTRL__EN_BUFFER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define GADC_GADC_CTRL__EN_BUFFER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define GADC_GADC_CTRL__EN_BUFFER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define GADC_GADC_CTRL__EN_BUFFER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define GADC_GADC_CTRL__EN_BUFFER__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field en_adc */
/**
 * @defgroup pmu_gadc_regs_core_en_adc_field en_adc_field
 * @brief macros for field en_adc
 * @details enable adc
 * @{
 */
#define GADC_GADC_CTRL__EN_ADC__SHIFT                                        25
#define GADC_GADC_CTRL__EN_ADC__WIDTH                                         1
#define GADC_GADC_CTRL__EN_ADC__MASK                                0x02000000U
#define GADC_GADC_CTRL__EN_ADC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define GADC_GADC_CTRL__EN_ADC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define GADC_GADC_CTRL__EN_ADC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define GADC_GADC_CTRL__EN_ADC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define GADC_GADC_CTRL__EN_ADC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define GADC_GADC_CTRL__EN_ADC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define GADC_GADC_CTRL__EN_ADC__RESET_VALUE                         0x00000001U
/** @} */
#define GADC_GADC_CTRL__TYPE                                           uint32_t
#define GADC_GADC_CTRL__READ                                        0x03ffffffU
#define GADC_GADC_CTRL__WRITE                                       0x03ffffffU
#define GADC_GADC_CTRL__PRESERVED                                   0x00000000U
#define GADC_GADC_CTRL__RESET_VALUE                                 0x03864733U

#endif /* __GADC_GADC_CTRL_MACRO__ */

/** @} end of gadc_ctrl */

/* macros for BlueprintGlobalNameSpace::GADC_core_id */
/**
 * @defgroup pmu_gadc_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __GADC_CORE_ID_MACRO__
#define __GADC_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup pmu_gadc_regs_core_id_field id_field
 * @brief macros for field id
 * @details GADC in ASCII (General ADC)
 * @{
 */
#define GADC_CORE_ID__ID__SHIFT                                               0
#define GADC_CORE_ID__ID__WIDTH                                              32
#define GADC_CORE_ID__ID__MASK                                      0xffffffffU
#define GADC_CORE_ID__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define GADC_CORE_ID__ID__RESET_VALUE                               0x474144c3U
/** @} */
#define GADC_CORE_ID__TYPE                                             uint32_t
#define GADC_CORE_ID__READ                                          0xffffffffU
#define GADC_CORE_ID__PRESERVED                                     0x00000000U
#define GADC_CORE_ID__RESET_VALUE                                   0x474144c3U

#endif /* __GADC_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of PMU_GADC_REGS_CORE */
#endif /* __REG_PMU_GADC_REGS_CORE_H__ */
