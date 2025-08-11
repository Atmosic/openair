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
 * @brief Enables, bias currents, ATB definitions.
 * @{
 */
#ifndef __GADC_GADC_CTRL_MACRO__
#define __GADC_GADC_CTRL_MACRO__

/* macros for field bias_en */
/**
 * @defgroup pmu_gadc_regs_core_bias_en_field bias_en_field
 * @brief macros for field bias_en
 * @details enable GADC top bias generator, which includes PTAT voltage, ic1u currents, buffered 0.6V reference
 * @{
 */
#define GADC_GADC_CTRL__BIAS_EN__SHIFT                                        0
#define GADC_GADC_CTRL__BIAS_EN__WIDTH                                        1
#define GADC_GADC_CTRL__BIAS_EN__MASK                               0x00000001U
#define GADC_GADC_CTRL__BIAS_EN__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define GADC_GADC_CTRL__BIAS_EN__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define GADC_GADC_CTRL__BIAS_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define GADC_GADC_CTRL__BIAS_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define GADC_GADC_CTRL__BIAS_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define GADC_GADC_CTRL__BIAS_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define GADC_GADC_CTRL__BIAS_EN__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pga_en */
/**
 * @defgroup pmu_gadc_regs_core_pga_en_field pga_en_field
 * @brief macros for field pga_en
 * @details enable programmable-gain input buffer
 * @{
 */
#define GADC_GADC_CTRL__PGA_EN__SHIFT                                         1
#define GADC_GADC_CTRL__PGA_EN__WIDTH                                         1
#define GADC_GADC_CTRL__PGA_EN__MASK                                0x00000002U
#define GADC_GADC_CTRL__PGA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define GADC_GADC_CTRL__PGA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define GADC_GADC_CTRL__PGA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define GADC_GADC_CTRL__PGA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define GADC_GADC_CTRL__PGA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define GADC_GADC_CTRL__PGA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define GADC_GADC_CTRL__PGA_EN__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field core_en */
/**
 * @defgroup pmu_gadc_regs_core_core_en_field core_en_field
 * @brief macros for field core_en
 * @details enable ADC core
 * @{
 */
#define GADC_GADC_CTRL__CORE_EN__SHIFT                                        2
#define GADC_GADC_CTRL__CORE_EN__WIDTH                                        1
#define GADC_GADC_CTRL__CORE_EN__MASK                               0x00000004U
#define GADC_GADC_CTRL__CORE_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define GADC_GADC_CTRL__CORE_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define GADC_GADC_CTRL__CORE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define GADC_GADC_CTRL__CORE_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define GADC_GADC_CTRL__CORE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define GADC_GADC_CTRL__CORE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define GADC_GADC_CTRL__CORE_EN__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field reset_df_ovr */
/**
 * @defgroup pmu_gadc_regs_core_reset_df_ovr_field reset_df_ovr_field
 * @brief macros for field reset_df_ovr
 * @details when =1, overrides gadc_reset_df from SOC with value of reset_df_ovr_val
 * @{
 */
#define GADC_GADC_CTRL__RESET_DF_OVR__SHIFT                                   3
#define GADC_GADC_CTRL__RESET_DF_OVR__WIDTH                                   1
#define GADC_GADC_CTRL__RESET_DF_OVR__MASK                          0x00000008U
#define GADC_GADC_CTRL__RESET_DF_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define GADC_GADC_CTRL__RESET_DF_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define GADC_GADC_CTRL__RESET_DF_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define GADC_GADC_CTRL__RESET_DF_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define GADC_GADC_CTRL__RESET_DF_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define GADC_GADC_CTRL__RESET_DF_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define GADC_GADC_CTRL__RESET_DF_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field reset_df_ovr_val */
/**
 * @defgroup pmu_gadc_regs_core_reset_df_ovr_val_field reset_df_ovr_val_field
 * @brief macros for field reset_df_ovr_val
 * @details value of reset_df when reset_df_ovr = 1
 * @{
 */
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__SHIFT                               4
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__WIDTH                               1
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__MASK                      0x00000010U
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define GADC_GADC_CTRL__RESET_DF_OVR_VAL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field gain_ovr */
/**
 * @defgroup pmu_gadc_regs_core_gain_ovr_field gain_ovr_field
 * @brief macros for field gain_ovr
 * @details when =1, overrides gadc_gain[2:0] from SOC with value of gain_ovr_val[2:0]
 * @{
 */
#define GADC_GADC_CTRL__GAIN_OVR__SHIFT                                       5
#define GADC_GADC_CTRL__GAIN_OVR__WIDTH                                       1
#define GADC_GADC_CTRL__GAIN_OVR__MASK                              0x00000020U
#define GADC_GADC_CTRL__GAIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define GADC_GADC_CTRL__GAIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define GADC_GADC_CTRL__GAIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define GADC_GADC_CTRL__GAIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define GADC_GADC_CTRL__GAIN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define GADC_GADC_CTRL__GAIN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define GADC_GADC_CTRL__GAIN_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field gain_ovr_val */
/**
 * @defgroup pmu_gadc_regs_core_gain_ovr_val_field gain_ovr_val_field
 * @brief macros for field gain_ovr_val
 * @details value of gain[2:0] when gain_ovr = 1
 * @{
 */
#define GADC_GADC_CTRL__GAIN_OVR_VAL__SHIFT                                   6
#define GADC_GADC_CTRL__GAIN_OVR_VAL__WIDTH                                   3
#define GADC_GADC_CTRL__GAIN_OVR_VAL__MASK                          0x000001c0U
#define GADC_GADC_CTRL__GAIN_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define GADC_GADC_CTRL__GAIN_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define GADC_GADC_CTRL__GAIN_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define GADC_GADC_CTRL__GAIN_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define GADC_GADC_CTRL__GAIN_OVR_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field li_en */
/**
 * @defgroup pmu_gadc_regs_core_li_en_field li_en_field
 * @brief macros for field li_en
 * @details enable Li-ion 1/6 input attenuator; SW writes this bit whenever Li-ion channel is selected
 * @{
 */
#define GADC_GADC_CTRL__LI_EN__SHIFT                                          9
#define GADC_GADC_CTRL__LI_EN__WIDTH                                          1
#define GADC_GADC_CTRL__LI_EN__MASK                                 0x00000200U
#define GADC_GADC_CTRL__LI_EN__READ(src) (((uint32_t)(src) & 0x00000200U) >> 9)
#define GADC_GADC_CTRL__LI_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define GADC_GADC_CTRL__LI_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define GADC_GADC_CTRL__LI_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define GADC_GADC_CTRL__LI_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define GADC_GADC_CTRL__LI_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define GADC_GADC_CTRL__LI_EN__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field sel_icgadc1 */
/**
 * @defgroup pmu_gadc_regs_core_sel_icgadc1_field sel_icgadc1_field
 * @brief macros for field sel_icgadc1
 * @details bias current control; i = 0.25uA + 0.25uA*sel_icgadc1[2:0]
 * @{
 */
#define GADC_GADC_CTRL__SEL_ICGADC1__SHIFT                                   10
#define GADC_GADC_CTRL__SEL_ICGADC1__WIDTH                                    3
#define GADC_GADC_CTRL__SEL_ICGADC1__MASK                           0x00001c00U
#define GADC_GADC_CTRL__SEL_ICGADC1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define GADC_GADC_CTRL__SEL_ICGADC1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define GADC_GADC_CTRL__SEL_ICGADC1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define GADC_GADC_CTRL__SEL_ICGADC1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define GADC_GADC_CTRL__SEL_ICGADC1__RESET_VALUE                    0x00000003U
/** @} */

/* macros for field sel_icgadc2 */
/**
 * @defgroup pmu_gadc_regs_core_sel_icgadc2_field sel_icgadc2_field
 * @brief macros for field sel_icgadc2
 * @details bias current control; i = 0.25uA + 0.25uA*sel_icgadc2[2:0]
 * @{
 */
#define GADC_GADC_CTRL__SEL_ICGADC2__SHIFT                                   13
#define GADC_GADC_CTRL__SEL_ICGADC2__WIDTH                                    3
#define GADC_GADC_CTRL__SEL_ICGADC2__MASK                           0x0000e000U
#define GADC_GADC_CTRL__SEL_ICGADC2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define GADC_GADC_CTRL__SEL_ICGADC2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define GADC_GADC_CTRL__SEL_ICGADC2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define GADC_GADC_CTRL__SEL_ICGADC2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define GADC_GADC_CTRL__SEL_ICGADC2__RESET_VALUE                    0x00000003U
/** @} */

/* macros for field sel_icrefbuf */
/**
 * @defgroup pmu_gadc_regs_core_sel_icrefbuf_field sel_icrefbuf_field
 * @brief macros for field sel_icrefbuf
 * @details bias current control; i = 0.25uA + 0.25uA*sel_icrefbuf[2:0]
 * @{
 */
#define GADC_GADC_CTRL__SEL_ICREFBUF__SHIFT                                  16
#define GADC_GADC_CTRL__SEL_ICREFBUF__WIDTH                                   3
#define GADC_GADC_CTRL__SEL_ICREFBUF__MASK                          0x00070000U
#define GADC_GADC_CTRL__SEL_ICREFBUF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define GADC_GADC_CTRL__SEL_ICREFBUF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define GADC_GADC_CTRL__SEL_ICREFBUF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define GADC_GADC_CTRL__SEL_ICREFBUF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define GADC_GADC_CTRL__SEL_ICREFBUF__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field bypass_pga */
/**
 * @defgroup pmu_gadc_regs_core_bypass_pga_field bypass_pga_field
 * @brief macros for field bypass_pga
 * @details when =1, bypass PGA stage
 * @{
 */
#define GADC_GADC_CTRL__BYPASS_PGA__SHIFT                                    19
#define GADC_GADC_CTRL__BYPASS_PGA__WIDTH                                     1
#define GADC_GADC_CTRL__BYPASS_PGA__MASK                            0x00080000U
#define GADC_GADC_CTRL__BYPASS_PGA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define GADC_GADC_CTRL__BYPASS_PGA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define GADC_GADC_CTRL__BYPASS_PGA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define GADC_GADC_CTRL__BYPASS_PGA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define GADC_GADC_CTRL__BYPASS_PGA__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define GADC_GADC_CTRL__BYPASS_PGA__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define GADC_GADC_CTRL__BYPASS_PGA__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field atbH_sel */
/**
 * @defgroup pmu_gadc_regs_core_atbH_sel_field atbH_sel_field
 * @brief macros for field atbH_sel
 * @details atbH control  0: No connect  1: ADC core enable - digital vdd1  2: vdd_hsw  3: vptat  4: vref0p6_buf  5: ic1u_gadc1  6: ic1u_gadc2  7: vcm0p5v  8: vcm0p7v  9: pbiasmain  10: pcasbias
 * @{
 */
#define GADC_GADC_CTRL__ATBH_SEL__SHIFT                                      20
#define GADC_GADC_CTRL__ATBH_SEL__WIDTH                                       4
#define GADC_GADC_CTRL__ATBH_SEL__MASK                              0x00f00000U
#define GADC_GADC_CTRL__ATBH_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define GADC_GADC_CTRL__ATBH_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define GADC_GADC_CTRL__ATBH_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define GADC_GADC_CTRL__ATBH_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define GADC_GADC_CTRL__ATBH_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field enable2x_pga_curr_ovr_val */
/**
 * @defgroup pmu_gadc_regs_core_enable2x_pga_curr_ovr_val_field enable2x_pga_curr_ovr_val_field
 * @brief macros for field enable2x_pga_curr_ovr_val
 * @details spare bits 0: enable_2x_pga_curr_ovr_val - set to 1 to manually double PGA current if override is set 1: enable_2x_pga_curr_ovr - if set, override PGA current setting with enable_2x_pga_current_ovr_val value 2: ext_vbat_sel - if set, vbat channel selected to external GPIO P9 3: ext_vstor_sel - if set, vstor channel selected to external GPIO P8 4: ext_vdd1_sel - if set, vdd1 channel selected to external GPIO P3
 * @{
 */
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__SHIFT                     24
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__WIDTH                      1
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__MASK             0x01000000U
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field enable2x_pga_curr_ovr */
/**
 * @defgroup pmu_gadc_regs_core_enable2x_pga_curr_ovr_field enable2x_pga_curr_ovr_field
 * @brief macros for field enable2x_pga_curr_ovr
 * @details spare bits 0: enable_2x_pga_curr_ovr_val - set to 1 to manually double PGA current if override is set 1: enable_2x_pga_curr_ovr - if set, override PGA current setting with enable_2x_pga_current_ovr_val value 2: ext_vbat_sel - if set, vbat channel selected to external GPIO P9 3: ext_vstor_sel - if set, vstor channel selected to external GPIO P8 4: ext_vdd1_sel - if set, vdd1 channel selected to external GPIO P3
 * @{
 */
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__SHIFT                         25
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__WIDTH                          1
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__MASK                 0x02000000U
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define GADC_GADC_CTRL__ENABLE2X_PGA_CURR_OVR__RESET_VALUE          0x00000000U
/** @} */

/* macros for field ext_vbat_sel */
/**
 * @defgroup pmu_gadc_regs_core_ext_vbat_sel_field ext_vbat_sel_field
 * @brief macros for field ext_vbat_sel
 * @details spare bits 0: enable_2x_pga_curr_ovr_val - set to 1 to manually double PGA current if override is set 1: enable_2x_pga_curr_ovr - if set, override PGA current setting with enable_2x_pga_current_ovr_val value 2: ext_vbat_sel - if set, vbat channel selected to external GPIO P9 3: ext_vstor_sel - if set, vstor channel selected to external GPIO P8 4: ext_vdd1_sel - if set, vdd1 channel selected to external GPIO P3
 * @{
 */
#define GADC_GADC_CTRL__EXT_VBAT_SEL__SHIFT                                  26
#define GADC_GADC_CTRL__EXT_VBAT_SEL__WIDTH                                   1
#define GADC_GADC_CTRL__EXT_VBAT_SEL__MASK                          0x04000000U
#define GADC_GADC_CTRL__EXT_VBAT_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define GADC_GADC_CTRL__EXT_VBAT_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define GADC_GADC_CTRL__EXT_VBAT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define GADC_GADC_CTRL__EXT_VBAT_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define GADC_GADC_CTRL__EXT_VBAT_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define GADC_GADC_CTRL__EXT_VBAT_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define GADC_GADC_CTRL__EXT_VBAT_SEL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ext_vstor_sel */
/**
 * @defgroup pmu_gadc_regs_core_ext_vstor_sel_field ext_vstor_sel_field
 * @brief macros for field ext_vstor_sel
 * @details spare bits 0: enable_2x_pga_curr_ovr_val - set to 1 to manually double PGA current if override is set 1: enable_2x_pga_curr_ovr - if set, override PGA current setting with enable_2x_pga_current_ovr_val value 2: ext_vbat_sel - if set, vbat channel selected to external GPIO P9 3: ext_vstor_sel - if set, vstor channel selected to external GPIO P8 4: ext_vdd1_sel - if set, vdd1 channel selected to external GPIO P3
 * @{
 */
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__SHIFT                                 27
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__WIDTH                                  1
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__MASK                         0x08000000U
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define GADC_GADC_CTRL__EXT_VSTOR_SEL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field ext_vdd1_sel */
/**
 * @defgroup pmu_gadc_regs_core_ext_vdd1_sel_field ext_vdd1_sel_field
 * @brief macros for field ext_vdd1_sel
 * @details spare bits 0: enable_2x_pga_curr_ovr_val - set to 1 to manually double PGA current if override is set 1: enable_2x_pga_curr_ovr - if set, override PGA current setting with enable_2x_pga_current_ovr_val value 2: ext_vbat_sel - if set, vbat channel selected to external GPIO P9 3: ext_vstor_sel - if set, vstor channel selected to external GPIO P8 4: ext_vdd1_sel - if set, vdd1 channel selected to external GPIO P3
 * @{
 */
#define GADC_GADC_CTRL__EXT_VDD1_SEL__SHIFT                                  28
#define GADC_GADC_CTRL__EXT_VDD1_SEL__WIDTH                                   1
#define GADC_GADC_CTRL__EXT_VDD1_SEL__MASK                          0x10000000U
#define GADC_GADC_CTRL__EXT_VDD1_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define GADC_GADC_CTRL__EXT_VDD1_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define GADC_GADC_CTRL__EXT_VDD1_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define GADC_GADC_CTRL__EXT_VDD1_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define GADC_GADC_CTRL__EXT_VDD1_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define GADC_GADC_CTRL__EXT_VDD1_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define GADC_GADC_CTRL__EXT_VDD1_SEL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field sparebits */
/**
 * @defgroup pmu_gadc_regs_core_sparebits_field sparebits_field
 * @brief macros for field sparebits
 * @details spare bits 0: enable_2x_pga_curr_ovr_val - set to 1 to manually double PGA current if override is set 1: enable_2x_pga_curr_ovr - if set, override PGA current setting with enable_2x_pga_current_ovr_val value 2: ext_vbat_sel - if set, vbat channel selected to external GPIO P9 3: ext_vstor_sel - if set, vstor channel selected to external GPIO P8 4: ext_vdd1_sel - if set, vdd1 channel selected to external GPIO P3
 * @{
 */
#define GADC_GADC_CTRL__SPAREBITS__SHIFT                                     29
#define GADC_GADC_CTRL__SPAREBITS__WIDTH                                      3
#define GADC_GADC_CTRL__SPAREBITS__MASK                             0xe0000000U
#define GADC_GADC_CTRL__SPAREBITS__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define GADC_GADC_CTRL__SPAREBITS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define GADC_GADC_CTRL__SPAREBITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define GADC_GADC_CTRL__SPAREBITS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
#define GADC_GADC_CTRL__SPAREBITS__RESET_VALUE                      0x00000000U
/** @} */
#define GADC_GADC_CTRL__TYPE                                           uint32_t
#define GADC_GADC_CTRL__READ                                        0xffffffffU
#define GADC_GADC_CTRL__WRITE                                       0xffffffffU
#define GADC_GADC_CTRL__PRESERVED                                   0x00000000U
#define GADC_GADC_CTRL__RESET_VALUE                                 0x00036c07U

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
