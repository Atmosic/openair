/*                                                                           */
/* File:       at_apb_gadc_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_gadc_regs_core.rdl          */
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


#ifndef __REG_AT_APB_GADC_REGS_CORE_H__
#define __REG_AT_APB_GADC_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_GADC_REGS_CORE at_apb_gadc_regs_core
 * @ingroup AT_REG
 * @brief at_apb_gadc_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::DGADC_ctrl */
/**
 * @defgroup at_apb_gadc_regs_core_ctrl ctrl
 * @brief control signals definitions.
 * @{
 */
#ifndef __DGADC_CTRL_MACRO__
#define __DGADC_CTRL_MACRO__

/* macros for field enable_dp */
/**
 * @defgroup at_apb_gadc_regs_core_enable_dp_field enable_dp_field
 * @brief macros for field enable_dp
 * @details Enables digital datapath.
 * @{
 */
#define DGADC_CTRL__ENABLE_DP__SHIFT                                          0
#define DGADC_CTRL__ENABLE_DP__WIDTH                                          1
#define DGADC_CTRL__ENABLE_DP__MASK                                 0x00000001U
#define DGADC_CTRL__ENABLE_DP__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define DGADC_CTRL__ENABLE_DP__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define DGADC_CTRL__ENABLE_DP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define DGADC_CTRL__ENABLE_DP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define DGADC_CTRL__ENABLE_DP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define DGADC_CTRL__ENABLE_DP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define DGADC_CTRL__ENABLE_DP__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_gadc_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details What is the mode of operation?  0 = continuous  1 = one-shot
 * @{
 */
#define DGADC_CTRL__MODE__SHIFT                                               1
#define DGADC_CTRL__MODE__WIDTH                                               1
#define DGADC_CTRL__MODE__MASK                                      0x00000002U
#define DGADC_CTRL__MODE__READ(src)      (((uint32_t)(src) & 0x00000002U) >> 1)
#define DGADC_CTRL__MODE__WRITE(src)     (((uint32_t)(src) << 1) & 0x00000002U)
#define DGADC_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define DGADC_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define DGADC_CTRL__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define DGADC_CTRL__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define DGADC_CTRL__MODE__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field warmup */
/**
 * @defgroup at_apb_gadc_regs_core_warmup_field warmup_field
 * @brief macros for field warmup
 * @details Specifies how many warmup cycles in 16MHz added at start of operation.  No data sampled during this period.  0 = 0  1 = 32  2 = 64  3 = 96
 * @{
 */
#define DGADC_CTRL__WARMUP__SHIFT                                             2
#define DGADC_CTRL__WARMUP__WIDTH                                             2
#define DGADC_CTRL__WARMUP__MASK                                    0x0000000cU
#define DGADC_CTRL__WARMUP__READ(src)    (((uint32_t)(src) & 0x0000000cU) >> 2)
#define DGADC_CTRL__WARMUP__WRITE(src)   (((uint32_t)(src) << 2) & 0x0000000cU)
#define DGADC_CTRL__WARMUP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define DGADC_CTRL__WARMUP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define DGADC_CTRL__WARMUP__RESET_VALUE                             0x00000002U
/** @} */

/* macros for field clkdiv */
/**
 * @defgroup at_apb_gadc_regs_core_clkdiv_field clkdiv_field
 * @brief macros for field clkdiv
 * @details gadc clock frequency  0 = 8MHz  1 = 4MHz  2 = 2MHz  3 = 1MHz
 * @{
 */
#define DGADC_CTRL__CLKDIV__SHIFT                                             4
#define DGADC_CTRL__CLKDIV__WIDTH                                             2
#define DGADC_CTRL__CLKDIV__MASK                                    0x00000030U
#define DGADC_CTRL__CLKDIV__READ(src)    (((uint32_t)(src) & 0x00000030U) >> 4)
#define DGADC_CTRL__CLKDIV__WRITE(src)   (((uint32_t)(src) << 4) & 0x00000030U)
#define DGADC_CTRL__CLKDIV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define DGADC_CTRL__CLKDIV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define DGADC_CTRL__CLKDIV__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field wait_amount */
/**
 * @defgroup at_apb_gadc_regs_core_wait_amount_field wait_amount_field
 * @brief macros for field wait_amount
 * @details Specifies how many wait cycles in gadc clock cycles.
 * @{
 */
#define DGADC_CTRL__WAIT_AMOUNT__SHIFT                                        6
#define DGADC_CTRL__WAIT_AMOUNT__WIDTH                                        7
#define DGADC_CTRL__WAIT_AMOUNT__MASK                               0x00001fc0U
#define DGADC_CTRL__WAIT_AMOUNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001fc0U) >> 6)
#define DGADC_CTRL__WAIT_AMOUNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00001fc0U)
#define DGADC_CTRL__WAIT_AMOUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00001fc0U)
#define DGADC_CTRL__WAIT_AMOUNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00001fc0U)))
#define DGADC_CTRL__WAIT_AMOUNT__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field averaging_amount */
/**
 * @defgroup at_apb_gadc_regs_core_averaging_amount_field averaging_amount_field
 * @brief macros for field averaging_amount
 * @details average 2^averaging_amount samples
 * @{
 */
#define DGADC_CTRL__AVERAGING_AMOUNT__SHIFT                                  13
#define DGADC_CTRL__AVERAGING_AMOUNT__WIDTH                                   3
#define DGADC_CTRL__AVERAGING_AMOUNT__MASK                          0x0000e000U
#define DGADC_CTRL__AVERAGING_AMOUNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define DGADC_CTRL__AVERAGING_AMOUNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define DGADC_CTRL__AVERAGING_AMOUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define DGADC_CTRL__AVERAGING_AMOUNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define DGADC_CTRL__AVERAGING_AMOUNT__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field watch_channels */
/**
 * @defgroup at_apb_gadc_regs_core_watch_channels_field watch_channels_field
 * @brief macros for field watch_channels
 * @details Which channels are active?  bit 0 = No-Connect  bit 1 = Vbatt  bit 2 = Vstor  bit 3 = core supply; avddldo (int)  bit 4 = temperature  bit 5 = external port 1; differential  bit 6 = external port 0; differential  bit 7 = external port 1; single ended pos  bit 8 = external port 1; single ended neg  bit 9 = external port 0; single ended pos bit 10 = external port 0; single ended neg bit 11 = Li-ion battery  bit 12 = ground both inputs  bit 13 = short inputs for offset cal  bit 14 = No-Connect  bit 15 = No-Connect
 * @{
 */
#define DGADC_CTRL__WATCH_CHANNELS__SHIFT                                    16
#define DGADC_CTRL__WATCH_CHANNELS__WIDTH                                    16
#define DGADC_CTRL__WATCH_CHANNELS__MASK                            0xffff0000U
#define DGADC_CTRL__WATCH_CHANNELS__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define DGADC_CTRL__WATCH_CHANNELS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define DGADC_CTRL__WATCH_CHANNELS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define DGADC_CTRL__WATCH_CHANNELS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define DGADC_CTRL__WATCH_CHANNELS__RESET_VALUE                     0x00000000U
/** @} */
#define DGADC_CTRL__TYPE                                               uint32_t
#define DGADC_CTRL__READ                                            0xffffffffU
#define DGADC_CTRL__WRITE                                           0xffffffffU
#define DGADC_CTRL__PRESERVED                                       0x00000000U
#define DGADC_CTRL__RESET_VALUE                                     0x00000008U

#endif /* __DGADC_CTRL_MACRO__ */

/** @} end of ctrl */

/* macros for BlueprintGlobalNameSpace::DGADC_ctrl1 */
/**
 * @defgroup at_apb_gadc_regs_core_ctrl1 ctrl1
 * @brief control signals definitions.
 * @{
 */
#ifndef __DGADC_CTRL1_MACRO__
#define __DGADC_CTRL1_MACRO__

/* macros for field ch_sel_ovrd */
/**
 * @defgroup at_apb_gadc_regs_core_ch_sel_ovrd_field ch_sel_ovrd_field
 * @brief macros for field ch_sel_ovrd
 * @details when set overrides gadc channel select.
 * @{
 */
#define DGADC_CTRL1__CH_SEL_OVRD__SHIFT                                       0
#define DGADC_CTRL1__CH_SEL_OVRD__WIDTH                                       1
#define DGADC_CTRL1__CH_SEL_OVRD__MASK                              0x00000001U
#define DGADC_CTRL1__CH_SEL_OVRD__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define DGADC_CTRL1__CH_SEL_OVRD__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define DGADC_CTRL1__CH_SEL_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define DGADC_CTRL1__CH_SEL_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define DGADC_CTRL1__CH_SEL_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define DGADC_CTRL1__CH_SEL_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define DGADC_CTRL1__CH_SEL_OVRD__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field ch_sel_ovrd_val */
/**
 * @defgroup at_apb_gadc_regs_core_ch_sel_ovrd_val_field ch_sel_ovrd_val_field
 * @brief macros for field ch_sel_ovrd_val
 * @details When override is set, what's the gadc channel to select.
 * @{
 */
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__SHIFT                                   1
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__WIDTH                                   4
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__MASK                          0x0000001eU
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001eU) >> 1)
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000001eU)
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001eU) | (((uint32_t)(src) <<\
                    1) & 0x0000001eU)
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000001eU)))
#define DGADC_CTRL1__CH_SEL_OVRD_VAL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field invert_ck */
/**
 * @defgroup at_apb_gadc_regs_core_invert_ck_field invert_ck_field
 * @brief macros for field invert_ck
 * @details When set inverts gadc clock going to analog.  Note: This option may not be functionally used as it skews the timings between analog and digital APB gadc.
 * @{
 */
#define DGADC_CTRL1__INVERT_CK__SHIFT                                         5
#define DGADC_CTRL1__INVERT_CK__WIDTH                                         1
#define DGADC_CTRL1__INVERT_CK__MASK                                0x00000020U
#define DGADC_CTRL1__INVERT_CK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define DGADC_CTRL1__INVERT_CK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define DGADC_CTRL1__INVERT_CK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define DGADC_CTRL1__INVERT_CK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define DGADC_CTRL1__INVERT_CK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define DGADC_CTRL1__INVERT_CK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define DGADC_CTRL1__INVERT_CK__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field mod_sel */
/**
 * @defgroup at_apb_gadc_regs_core_mod_sel_field mod_sel_field
 * @brief macros for field mod_sel
 * @details GADC modulator topology  0 = Mash 2-to-1 Modulation  1 = Single 2nd-order Modulation
 * @{
 */
#define DGADC_CTRL1__MOD_SEL__SHIFT                                           6
#define DGADC_CTRL1__MOD_SEL__WIDTH                                           1
#define DGADC_CTRL1__MOD_SEL__MASK                                  0x00000040U
#define DGADC_CTRL1__MOD_SEL__READ(src)  (((uint32_t)(src) & 0x00000040U) >> 6)
#define DGADC_CTRL1__MOD_SEL__WRITE(src) (((uint32_t)(src) << 6) & 0x00000040U)
#define DGADC_CTRL1__MOD_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define DGADC_CTRL1__MOD_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define DGADC_CTRL1__MOD_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define DGADC_CTRL1__MOD_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define DGADC_CTRL1__MOD_SEL__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field osr_sel */
/**
 * @defgroup at_apb_gadc_regs_core_osr_sel_field osr_sel_field
 * @brief macros for field osr_sel
 * @details Decimation filter osr selection  0 = 128  1 = 64  2 = 32  3 = 16
 * @{
 */
#define DGADC_CTRL1__OSR_SEL__SHIFT                                           7
#define DGADC_CTRL1__OSR_SEL__WIDTH                                           2
#define DGADC_CTRL1__OSR_SEL__MASK                                  0x00000180U
#define DGADC_CTRL1__OSR_SEL__READ(src)  (((uint32_t)(src) & 0x00000180U) >> 7)
#define DGADC_CTRL1__OSR_SEL__WRITE(src) (((uint32_t)(src) << 7) & 0x00000180U)
#define DGADC_CTRL1__OSR_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000180U) | (((uint32_t)(src) <<\
                    7) & 0x00000180U)
#define DGADC_CTRL1__OSR_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000180U)))
#define DGADC_CTRL1__OSR_SEL__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field offset_cal_en */
/**
 * @defgroup at_apb_gadc_regs_core_offset_cal_en_field offset_cal_en_field
 * @brief macros for field offset_cal_en
 * @details When set enables HW offset calibration
 * @{
 */
#define DGADC_CTRL1__OFFSET_CAL_EN__SHIFT                                     9
#define DGADC_CTRL1__OFFSET_CAL_EN__WIDTH                                     1
#define DGADC_CTRL1__OFFSET_CAL_EN__MASK                            0x00000200U
#define DGADC_CTRL1__OFFSET_CAL_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define DGADC_CTRL1__OFFSET_CAL_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define DGADC_CTRL1__OFFSET_CAL_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define DGADC_CTRL1__OFFSET_CAL_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define DGADC_CTRL1__OFFSET_CAL_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define DGADC_CTRL1__OFFSET_CAL_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define DGADC_CTRL1__OFFSET_CAL_EN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field rtrim_temp */
/**
 * @defgroup at_apb_gadc_regs_core_rtrim_temp_field rtrim_temp_field
 * @brief macros for field rtrim_temp
 * @details Calibration code for temperature measurement channel.
 * @{
 */
#define DGADC_CTRL1__RTRIM_TEMP__SHIFT                                       10
#define DGADC_CTRL1__RTRIM_TEMP__WIDTH                                        6
#define DGADC_CTRL1__RTRIM_TEMP__MASK                               0x0000fc00U
#define DGADC_CTRL1__RTRIM_TEMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define DGADC_CTRL1__RTRIM_TEMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define DGADC_CTRL1__RTRIM_TEMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define DGADC_CTRL1__RTRIM_TEMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define DGADC_CTRL1__RTRIM_TEMP__RESET_VALUE                        0x00000020U
/** @} */

/* macros for field rtrim_ic */
/**
 * @defgroup at_apb_gadc_regs_core_rtrim_ic_field rtrim_ic_field
 * @brief macros for field rtrim_ic
 * @details Calibration code for bais current.
 * @{
 */
#define DGADC_CTRL1__RTRIM_IC__SHIFT                                         16
#define DGADC_CTRL1__RTRIM_IC__WIDTH                                          6
#define DGADC_CTRL1__RTRIM_IC__MASK                                 0x003f0000U
#define DGADC_CTRL1__RTRIM_IC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define DGADC_CTRL1__RTRIM_IC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define DGADC_CTRL1__RTRIM_IC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define DGADC_CTRL1__RTRIM_IC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define DGADC_CTRL1__RTRIM_IC__RESET_VALUE                          0x00000020U
/** @} */
#define DGADC_CTRL1__TYPE                                              uint32_t
#define DGADC_CTRL1__READ                                           0x003fffffU
#define DGADC_CTRL1__WRITE                                          0x003fffffU
#define DGADC_CTRL1__PRESERVED                                      0x00000000U
#define DGADC_CTRL1__RESET_VALUE                                    0x00208000U

#endif /* __DGADC_CTRL1_MACRO__ */

/** @} end of ctrl1 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_config0 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_config0 gain_config0
 * @brief channels 1-10 analog gain attenuation settings selection, only four options are supported [0=>1, 1=>1/2, 2=>1/4, 3=>1/8] definitions.
 * @{
 */
#ifndef __DGADC_GAIN_CONFIG0_MACRO__
#define __DGADC_GAIN_CONFIG0_MACRO__

/* macros for field ch1_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch1_gain_sel_field ch1_gain_sel_field
 * @brief macros for field ch1_gain_sel
 * @details channel 1 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__SHIFT                               0
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__MASK                      0x00000007U
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__RESET_VALUE               0x00000003U
/** @} */

/* macros for field ch2_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch2_gain_sel_field ch2_gain_sel_field
 * @brief macros for field ch2_gain_sel
 * @details channel 2 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__SHIFT                               3
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__MASK                      0x00000038U
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__RESET_VALUE               0x00000003U
/** @} */

/* macros for field ch3_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch3_gain_sel_field ch3_gain_sel_field
 * @brief macros for field ch3_gain_sel
 * @details channel 3 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__SHIFT                               6
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__MASK                      0x000001c0U
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__RESET_VALUE               0x00000001U
/** @} */

/* macros for field ch4_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch4_gain_sel_field ch4_gain_sel_field
 * @brief macros for field ch4_gain_sel
 * @details channel 4 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__SHIFT                               9
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__MASK                      0x00000e00U
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch5_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch5_gain_sel_field ch5_gain_sel_field
 * @brief macros for field ch5_gain_sel
 * @details channel 5 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__SHIFT                              12
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__MASK                      0x00007000U
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__RESET_VALUE               0x00000002U
/** @} */

/* macros for field ch6_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch6_gain_sel_field ch6_gain_sel_field
 * @brief macros for field ch6_gain_sel
 * @details channel 6 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__SHIFT                              15
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__MASK                      0x00038000U
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__RESET_VALUE               0x00000002U
/** @} */

/* macros for field ch7_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch7_gain_sel_field ch7_gain_sel_field
 * @brief macros for field ch7_gain_sel
 * @details channel 7 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__SHIFT                              18
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__MASK                      0x001c0000U
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__RESET_VALUE               0x00000002U
/** @} */

/* macros for field ch8_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch8_gain_sel_field ch8_gain_sel_field
 * @brief macros for field ch8_gain_sel
 * @details channel 8 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__SHIFT                              21
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__MASK                      0x00e00000U
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00e00000U) >> 21)
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00e00000U)
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00e00000U) | (((uint32_t)(src) <<\
                    21) & 0x00e00000U)
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00e00000U)))
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__RESET_VALUE               0x00000002U
/** @} */

/* macros for field ch9_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch9_gain_sel_field ch9_gain_sel_field
 * @brief macros for field ch9_gain_sel
 * @details channel 9 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__SHIFT                              24
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__WIDTH                               3
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__MASK                      0x07000000U
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__RESET_VALUE               0x00000002U
/** @} */

/* macros for field ch10_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch10_gain_sel_field ch10_gain_sel_field
 * @brief macros for field ch10_gain_sel
 * @details channel 10 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__SHIFT                             27
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__WIDTH                              3
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__MASK                     0x38000000U
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x38000000U) >> 27)
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x38000000U)
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x38000000U) | (((uint32_t)(src) <<\
                    27) & 0x38000000U)
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x38000000U)))
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__RESET_VALUE              0x00000002U
/** @} */
#define DGADC_GAIN_CONFIG0__TYPE                                       uint32_t
#define DGADC_GAIN_CONFIG0__READ                                    0x3fffffffU
#define DGADC_GAIN_CONFIG0__WRITE                                   0x3fffffffU
#define DGADC_GAIN_CONFIG0__PRESERVED                               0x00000000U
#define DGADC_GAIN_CONFIG0__RESET_VALUE                             0x1249205bU

#endif /* __DGADC_GAIN_CONFIG0_MACRO__ */

/** @} end of gain_config0 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_config1 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_config1 gain_config1
 * @brief channels 11-13 gain attenuation settings selection, only four options are supported [0=>1, 1=>1/2, 2=>1/4, 3=>1/8] definitions.
 * @{
 */
#ifndef __DGADC_GAIN_CONFIG1_MACRO__
#define __DGADC_GAIN_CONFIG1_MACRO__

/* macros for field ch11_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch11_gain_sel_field ch11_gain_sel_field
 * @brief macros for field ch11_gain_sel
 * @details channel 11 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__SHIFT                              0
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__WIDTH                              3
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__MASK                     0x00000007U
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__RESET_VALUE              0x00000001U
/** @} */

/* macros for field ch12_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch12_gain_sel_field ch12_gain_sel_field
 * @brief macros for field ch12_gain_sel
 * @details channel 12/13 gain attenuation
 * @{
 */
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__SHIFT                              3
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__WIDTH                              3
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__MASK                     0x00000038U
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_GAIN_CONFIG1__TYPE                                       uint32_t
#define DGADC_GAIN_CONFIG1__READ                                    0x0000003fU
#define DGADC_GAIN_CONFIG1__WRITE                                   0x0000003fU
#define DGADC_GAIN_CONFIG1__PRESERVED                               0x00000000U
#define DGADC_GAIN_CONFIG1__RESET_VALUE                             0x00000001U

#endif /* __DGADC_GAIN_CONFIG1_MACRO__ */

/** @} end of gain_config1 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp0 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp0 gain_comp0
 * @brief Mash 2-1 Modulator gain compensation for osr=16 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP0_MACRO__
#define __DGADC_GAIN_COMP0_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP0__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP0__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP0__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP0__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP0__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP0__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP0__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP0__GAIN__RESET_VALUE                         0x0000c55eU
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP0__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP0__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP0__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP0__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP0__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP0__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP0__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP0__SHIFT__RESET_VALUE                        0x0000000aU
/** @} */
#define DGADC_GAIN_COMP0__TYPE                                         uint32_t
#define DGADC_GAIN_COMP0__READ                                      0x001fffffU
#define DGADC_GAIN_COMP0__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP0__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP0__RESET_VALUE                               0x000ac55eU

#endif /* __DGADC_GAIN_COMP0_MACRO__ */

/** @} end of gain_comp0 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp1 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp1 gain_comp1
 * @brief Mash 2-1 Modulator gain compensation for osr=32 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP1_MACRO__
#define __DGADC_GAIN_COMP1_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP1__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP1__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP1__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP1__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP1__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP1__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP1__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP1__GAIN__RESET_VALUE                         0x0000c157U
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP1__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP1__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP1__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP1__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP1__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP1__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP1__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP1__SHIFT__RESET_VALUE                        0x0000000dU
/** @} */
#define DGADC_GAIN_COMP1__TYPE                                         uint32_t
#define DGADC_GAIN_COMP1__READ                                      0x001fffffU
#define DGADC_GAIN_COMP1__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP1__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP1__RESET_VALUE                               0x000dc157U

#endif /* __DGADC_GAIN_COMP1_MACRO__ */

/** @} end of gain_comp1 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp2 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp2 gain_comp2
 * @brief Mash 2-1 Modulator gain compensation for osr=64 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP2_MACRO__
#define __DGADC_GAIN_COMP2_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP2__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP2__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP2__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP2__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP2__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP2__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP2__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP2__GAIN__RESET_VALUE                         0x0000c054U
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP2__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP2__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP2__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP2__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP2__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP2__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP2__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP2__SHIFT__RESET_VALUE                        0x00000010U
/** @} */
#define DGADC_GAIN_COMP2__TYPE                                         uint32_t
#define DGADC_GAIN_COMP2__READ                                      0x001fffffU
#define DGADC_GAIN_COMP2__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP2__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP2__RESET_VALUE                               0x0010c054U

#endif /* __DGADC_GAIN_COMP2_MACRO__ */

/** @} end of gain_comp2 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp3 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp3 gain_comp3
 * @brief Mash 2-1 Modulator gain compensation for osr=128 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP3_MACRO__
#define __DGADC_GAIN_COMP3_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP3__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP3__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP3__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP3__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP3__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP3__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP3__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP3__GAIN__RESET_VALUE                         0x0000c015U
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP3__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP3__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP3__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP3__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP3__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP3__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP3__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP3__SHIFT__RESET_VALUE                        0x00000013U
/** @} */
#define DGADC_GAIN_COMP3__TYPE                                         uint32_t
#define DGADC_GAIN_COMP3__READ                                      0x001fffffU
#define DGADC_GAIN_COMP3__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP3__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP3__RESET_VALUE                               0x0013c015U

#endif /* __DGADC_GAIN_COMP3_MACRO__ */

/** @} end of gain_comp3 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp4 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp4 gain_comp4
 * @brief Single Modulator gain compensation for osr=16 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP4_MACRO__
#define __DGADC_GAIN_COMP4_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP4__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP4__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP4__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP4__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP4__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP4__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP4__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP4__GAIN__RESET_VALUE                         0x0000c4e0U
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP4__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP4__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP4__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP4__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP4__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP4__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP4__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP4__SHIFT__RESET_VALUE                        0x0000000aU
/** @} */
#define DGADC_GAIN_COMP4__TYPE                                         uint32_t
#define DGADC_GAIN_COMP4__READ                                      0x001fffffU
#define DGADC_GAIN_COMP4__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP4__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP4__RESET_VALUE                               0x000ac4e0U

#endif /* __DGADC_GAIN_COMP4_MACRO__ */

/** @} end of gain_comp4 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp5 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp5 gain_comp5
 * @brief Single Modulator gain compensation for osr=32 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP5_MACRO__
#define __DGADC_GAIN_COMP5_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP5__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP5__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP5__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP5__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP5__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP5__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP5__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP5__GAIN__RESET_VALUE                         0x0000c125U
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP5__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP5__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP5__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP5__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP5__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP5__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP5__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP5__SHIFT__RESET_VALUE                        0x0000000dU
/** @} */
#define DGADC_GAIN_COMP5__TYPE                                         uint32_t
#define DGADC_GAIN_COMP5__READ                                      0x001fffffU
#define DGADC_GAIN_COMP5__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP5__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP5__RESET_VALUE                               0x000dc125U

#endif /* __DGADC_GAIN_COMP5_MACRO__ */

/** @} end of gain_comp5 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp6 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp6 gain_comp6
 * @brief Single Modulator gain compensation for osr=64 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP6_MACRO__
#define __DGADC_GAIN_COMP6_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP6__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP6__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP6__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP6__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP6__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP6__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP6__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP6__GAIN__RESET_VALUE                         0x0000c044U
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP6__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP6__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP6__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP6__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP6__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP6__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP6__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP6__SHIFT__RESET_VALUE                        0x00000010U
/** @} */
#define DGADC_GAIN_COMP6__TYPE                                         uint32_t
#define DGADC_GAIN_COMP6__READ                                      0x001fffffU
#define DGADC_GAIN_COMP6__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP6__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP6__RESET_VALUE                               0x0010c044U

#endif /* __DGADC_GAIN_COMP6_MACRO__ */

/** @} end of gain_comp6 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_comp7 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_comp7 gain_comp7
 * @brief Single Modulator gain compensation for osr=128 definitions.
 * @{
 */
#ifndef __DGADC_GAIN_COMP7_MACRO__
#define __DGADC_GAIN_COMP7_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details gain compensation value
 * @{
 */
#define DGADC_GAIN_COMP7__GAIN__SHIFT                                         0
#define DGADC_GAIN_COMP7__GAIN__WIDTH                                        16
#define DGADC_GAIN_COMP7__GAIN__MASK                                0x0000ffffU
#define DGADC_GAIN_COMP7__GAIN__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP7__GAIN__WRITE(src)      ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_GAIN_COMP7__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_GAIN_COMP7__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_GAIN_COMP7__GAIN__RESET_VALUE                         0x0000c011U
/** @} */

/* macros for field shift */
/**
 * @defgroup at_apb_gadc_regs_core_shift_field shift_field
 * @brief macros for field shift
 * @details gain right-shift amount
 * @{
 */
#define DGADC_GAIN_COMP7__SHIFT__SHIFT                                       16
#define DGADC_GAIN_COMP7__SHIFT__WIDTH                                        5
#define DGADC_GAIN_COMP7__SHIFT__MASK                               0x001f0000U
#define DGADC_GAIN_COMP7__SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define DGADC_GAIN_COMP7__SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define DGADC_GAIN_COMP7__SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define DGADC_GAIN_COMP7__SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define DGADC_GAIN_COMP7__SHIFT__RESET_VALUE                        0x00000013U
/** @} */
#define DGADC_GAIN_COMP7__TYPE                                         uint32_t
#define DGADC_GAIN_COMP7__READ                                      0x001fffffU
#define DGADC_GAIN_COMP7__WRITE                                     0x001fffffU
#define DGADC_GAIN_COMP7__PRESERVED                                 0x00000000U
#define DGADC_GAIN_COMP7__RESET_VALUE                               0x0013c011U

#endif /* __DGADC_GAIN_COMP7_MACRO__ */

/** @} end of gain_comp7 */

/* macros for BlueprintGlobalNameSpace::DGADC_offset_comp0 */
/**
 * @defgroup at_apb_gadc_regs_core_offset_comp0 offset_comp0
 * @brief Offset compensation for analog attenuation setting of 1 (gain_sel=0) definitions.
 * @{
 */
#ifndef __DGADC_OFFSET_COMP0_MACRO__
#define __DGADC_OFFSET_COMP0_MACRO__

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details offset compensation value
 * @{
 */
#define DGADC_OFFSET_COMP0__OFFSET__SHIFT                                     0
#define DGADC_OFFSET_COMP0__OFFSET__WIDTH                                    16
#define DGADC_OFFSET_COMP0__OFFSET__MASK                            0x0000ffffU
#define DGADC_OFFSET_COMP0__OFFSET__READ(src)   ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP0__OFFSET__WRITE(src)  ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP0__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_OFFSET_COMP0__OFFSET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_OFFSET_COMP0__OFFSET__RESET_VALUE                     0x00000000U
/** @} */
#define DGADC_OFFSET_COMP0__TYPE                                       uint32_t
#define DGADC_OFFSET_COMP0__READ                                    0x0000ffffU
#define DGADC_OFFSET_COMP0__WRITE                                   0x0000ffffU
#define DGADC_OFFSET_COMP0__PRESERVED                               0x00000000U
#define DGADC_OFFSET_COMP0__RESET_VALUE                             0x00000000U

#endif /* __DGADC_OFFSET_COMP0_MACRO__ */

/** @} end of offset_comp0 */

/* macros for BlueprintGlobalNameSpace::DGADC_offset_comp1 */
/**
 * @defgroup at_apb_gadc_regs_core_offset_comp1 offset_comp1
 * @brief Offset compensation for analog attenuation setting of 0.5 (gain_sel=1) definitions.
 * @{
 */
#ifndef __DGADC_OFFSET_COMP1_MACRO__
#define __DGADC_OFFSET_COMP1_MACRO__

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details offset compensation value
 * @{
 */
#define DGADC_OFFSET_COMP1__OFFSET__SHIFT                                     0
#define DGADC_OFFSET_COMP1__OFFSET__WIDTH                                    16
#define DGADC_OFFSET_COMP1__OFFSET__MASK                            0x0000ffffU
#define DGADC_OFFSET_COMP1__OFFSET__READ(src)   ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP1__OFFSET__WRITE(src)  ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP1__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_OFFSET_COMP1__OFFSET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_OFFSET_COMP1__OFFSET__RESET_VALUE                     0x00000000U
/** @} */
#define DGADC_OFFSET_COMP1__TYPE                                       uint32_t
#define DGADC_OFFSET_COMP1__READ                                    0x0000ffffU
#define DGADC_OFFSET_COMP1__WRITE                                   0x0000ffffU
#define DGADC_OFFSET_COMP1__PRESERVED                               0x00000000U
#define DGADC_OFFSET_COMP1__RESET_VALUE                             0x00000000U

#endif /* __DGADC_OFFSET_COMP1_MACRO__ */

/** @} end of offset_comp1 */

/* macros for BlueprintGlobalNameSpace::DGADC_offset_comp2 */
/**
 * @defgroup at_apb_gadc_regs_core_offset_comp2 offset_comp2
 * @brief Offset compensation for analog attenuation setting of 0.25 (gain_sel=2) definitions.
 * @{
 */
#ifndef __DGADC_OFFSET_COMP2_MACRO__
#define __DGADC_OFFSET_COMP2_MACRO__

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details offset compensation value
 * @{
 */
#define DGADC_OFFSET_COMP2__OFFSET__SHIFT                                     0
#define DGADC_OFFSET_COMP2__OFFSET__WIDTH                                    16
#define DGADC_OFFSET_COMP2__OFFSET__MASK                            0x0000ffffU
#define DGADC_OFFSET_COMP2__OFFSET__READ(src)   ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP2__OFFSET__WRITE(src)  ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP2__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_OFFSET_COMP2__OFFSET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_OFFSET_COMP2__OFFSET__RESET_VALUE                     0x00000000U
/** @} */
#define DGADC_OFFSET_COMP2__TYPE                                       uint32_t
#define DGADC_OFFSET_COMP2__READ                                    0x0000ffffU
#define DGADC_OFFSET_COMP2__WRITE                                   0x0000ffffU
#define DGADC_OFFSET_COMP2__PRESERVED                               0x00000000U
#define DGADC_OFFSET_COMP2__RESET_VALUE                             0x00000000U

#endif /* __DGADC_OFFSET_COMP2_MACRO__ */

/** @} end of offset_comp2 */

/* macros for BlueprintGlobalNameSpace::DGADC_offset_comp3 */
/**
 * @defgroup at_apb_gadc_regs_core_offset_comp3 offset_comp3
 * @brief Offset compensation for analog attenuation setting of 0.125 (gain_sel=3) definitions.
 * @{
 */
#ifndef __DGADC_OFFSET_COMP3_MACRO__
#define __DGADC_OFFSET_COMP3_MACRO__

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details offset compensation value
 * @{
 */
#define DGADC_OFFSET_COMP3__OFFSET__SHIFT                                     0
#define DGADC_OFFSET_COMP3__OFFSET__WIDTH                                    16
#define DGADC_OFFSET_COMP3__OFFSET__MASK                            0x0000ffffU
#define DGADC_OFFSET_COMP3__OFFSET__READ(src)   ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP3__OFFSET__WRITE(src)  ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_OFFSET_COMP3__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define DGADC_OFFSET_COMP3__OFFSET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define DGADC_OFFSET_COMP3__OFFSET__RESET_VALUE                     0x00000000U
/** @} */
#define DGADC_OFFSET_COMP3__TYPE                                       uint32_t
#define DGADC_OFFSET_COMP3__READ                                    0x0000ffffU
#define DGADC_OFFSET_COMP3__WRITE                                   0x0000ffffU
#define DGADC_OFFSET_COMP3__PRESERVED                               0x00000000U
#define DGADC_OFFSET_COMP3__RESET_VALUE                             0x00000000U

#endif /* __DGADC_OFFSET_COMP3_MACRO__ */

/** @} end of offset_comp3 */

/* macros for BlueprintGlobalNameSpace::DGADC_datapath_output */
/**
 * @defgroup at_apb_gadc_regs_core_datapath_output datapath_output
 * @brief a read of this register pops the data FIFO definitions.
 * @{
 */
#ifndef __DGADC_DATAPATH_OUTPUT_MACRO__
#define __DGADC_DATAPATH_OUTPUT_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_gadc_regs_core_data_field data_field
 * @brief macros for field data
 * @details {4b channel id, 16b processed ADC sample}
 * @{
 */
#define DGADC_DATAPATH_OUTPUT__DATA__SHIFT                                    0
#define DGADC_DATAPATH_OUTPUT__DATA__WIDTH                                   20
#define DGADC_DATAPATH_OUTPUT__DATA__MASK                           0x000fffffU
#define DGADC_DATAPATH_OUTPUT__DATA__READ(src)  ((uint32_t)(src) & 0x000fffffU)
#define DGADC_DATAPATH_OUTPUT__DATA__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field empty */
/**
 * @defgroup at_apb_gadc_regs_core_empty_field empty_field
 * @brief macros for field empty
 * @details if 1, ignore data sample because fifo has been drained
 * @{
 */
#define DGADC_DATAPATH_OUTPUT__EMPTY__SHIFT                                  31
#define DGADC_DATAPATH_OUTPUT__EMPTY__WIDTH                                   1
#define DGADC_DATAPATH_OUTPUT__EMPTY__MASK                          0x80000000U
#define DGADC_DATAPATH_OUTPUT__EMPTY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define DGADC_DATAPATH_OUTPUT__EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define DGADC_DATAPATH_OUTPUT__EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define DGADC_DATAPATH_OUTPUT__EMPTY__RESET_VALUE                   0x00000000U
/** @} */
#define DGADC_DATAPATH_OUTPUT__TYPE                                    uint32_t
#define DGADC_DATAPATH_OUTPUT__READ                                 0x800fffffU
#define DGADC_DATAPATH_OUTPUT__PRESERVED                            0x00000000U
#define DGADC_DATAPATH_OUTPUT__RESET_VALUE                          0x00000000U

#endif /* __DGADC_DATAPATH_OUTPUT_MACRO__ */

/** @} end of datapath_output */

/* macros for BlueprintGlobalNameSpace::DGADC_interrupts */
/**
 * @defgroup at_apb_gadc_regs_core_interrupts interrupts
 * @brief interrupt status definitions.
 * @{
 */
#ifndef __DGADC_INTERRUPTS_MACRO__
#define __DGADC_INTERRUPTS_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_gadc_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details hardware written to fifo
 * @{
 */
#define DGADC_INTERRUPTS__INTRPT0__SHIFT                                      0
#define DGADC_INTERRUPTS__INTRPT0__WIDTH                                      1
#define DGADC_INTERRUPTS__INTRPT0__MASK                             0x00000001U
#define DGADC_INTERRUPTS__INTRPT0__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define DGADC_INTERRUPTS__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define DGADC_INTERRUPTS__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define DGADC_INTERRUPTS__INTRPT0__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field intrpt1 */
/**
 * @defgroup at_apb_gadc_regs_core_intrpt1_field intrpt1_field
 * @brief macros for field intrpt1
 * @details fifo full
 * @{
 */
#define DGADC_INTERRUPTS__INTRPT1__SHIFT                                      1
#define DGADC_INTERRUPTS__INTRPT1__WIDTH                                      1
#define DGADC_INTERRUPTS__INTRPT1__MASK                             0x00000002U
#define DGADC_INTERRUPTS__INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define DGADC_INTERRUPTS__INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define DGADC_INTERRUPTS__INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define DGADC_INTERRUPTS__INTRPT1__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field intrpt2 */
/**
 * @defgroup at_apb_gadc_regs_core_intrpt2_field intrpt2_field
 * @brief macros for field intrpt2
 * @details one shot mode or one round of continuous mode has completed
 * @{
 */
#define DGADC_INTERRUPTS__INTRPT2__SHIFT                                      2
#define DGADC_INTERRUPTS__INTRPT2__WIDTH                                      1
#define DGADC_INTERRUPTS__INTRPT2__MASK                             0x00000004U
#define DGADC_INTERRUPTS__INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define DGADC_INTERRUPTS__INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define DGADC_INTERRUPTS__INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define DGADC_INTERRUPTS__INTRPT2__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field intrpt3 */
/**
 * @defgroup at_apb_gadc_regs_core_intrpt3_field intrpt3_field
 * @brief macros for field intrpt3
 * @details offset calibration done
 * @{
 */
#define DGADC_INTERRUPTS__INTRPT3__SHIFT                                      3
#define DGADC_INTERRUPTS__INTRPT3__WIDTH                                      1
#define DGADC_INTERRUPTS__INTRPT3__MASK                             0x00000008U
#define DGADC_INTERRUPTS__INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define DGADC_INTERRUPTS__INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define DGADC_INTERRUPTS__INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define DGADC_INTERRUPTS__INTRPT3__RESET_VALUE                      0x00000000U
/** @} */
#define DGADC_INTERRUPTS__TYPE                                         uint32_t
#define DGADC_INTERRUPTS__READ                                      0x0000000fU
#define DGADC_INTERRUPTS__PRESERVED                                 0x00000000U
#define DGADC_INTERRUPTS__RESET_VALUE                               0x00000000U

#endif /* __DGADC_INTERRUPTS_MACRO__ */

/** @} end of interrupts */

/* macros for BlueprintGlobalNameSpace::DGADC_interrupt_mask */
/**
 * @defgroup at_apb_gadc_regs_core_interrupt_mask interrupt_mask
 * @brief interrupt masking definitions.
 * @{
 */
#ifndef __DGADC_INTERRUPT_MASK_MACRO__
#define __DGADC_INTERRUPT_MASK_MACRO__

/* macros for field mask_intrpt0 */
/**
 * @defgroup at_apb_gadc_regs_core_mask_intrpt0_field mask_intrpt0_field
 * @brief macros for field mask_intrpt0
 * @details allow intrpt0 to propogate to core's single output interrupt
 * @{
 */
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__SHIFT                             0
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__WIDTH                             1
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__MASK                    0x00000001U
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT0__RESET_VALUE             0x00000001U
/** @} */

/* macros for field mask_intrpt1 */
/**
 * @defgroup at_apb_gadc_regs_core_mask_intrpt1_field mask_intrpt1_field
 * @brief macros for field mask_intrpt1
 * @details allow intrpt1 to propogate to core's single output interrupt
 * @{
 */
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__SHIFT                             1
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__WIDTH                             1
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__MASK                    0x00000002U
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT1__RESET_VALUE             0x00000001U
/** @} */

/* macros for field mask_intrpt2 */
/**
 * @defgroup at_apb_gadc_regs_core_mask_intrpt2_field mask_intrpt2_field
 * @brief macros for field mask_intrpt2
 * @details allow intrpt2 to propogate to core's single output interrupt
 * @{
 */
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__SHIFT                             2
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__WIDTH                             1
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__MASK                    0x00000004U
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT2__RESET_VALUE             0x00000001U
/** @} */

/* macros for field mask_intrpt3 */
/**
 * @defgroup at_apb_gadc_regs_core_mask_intrpt3_field mask_intrpt3_field
 * @brief macros for field mask_intrpt3
 * @details allow intrpt3 to propogate to core's single output interrupt
 * @{
 */
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__SHIFT                             3
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__WIDTH                             1
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__MASK                    0x00000008U
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define DGADC_INTERRUPT_MASK__MASK_INTRPT3__RESET_VALUE             0x00000001U
/** @} */
#define DGADC_INTERRUPT_MASK__TYPE                                     uint32_t
#define DGADC_INTERRUPT_MASK__READ                                  0x0000000fU
#define DGADC_INTERRUPT_MASK__WRITE                                 0x0000000fU
#define DGADC_INTERRUPT_MASK__PRESERVED                             0x00000000U
#define DGADC_INTERRUPT_MASK__RESET_VALUE                           0x0000000fU

#endif /* __DGADC_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::DGADC_interrupt_clear */
/**
 * @defgroup at_apb_gadc_regs_core_interrupt_clear interrupt_clear
 * @brief interrupt clearing definitions.
 * @{
 */
#ifndef __DGADC_INTERRUPT_CLEAR_MACRO__
#define __DGADC_INTERRUPT_CLEAR_MACRO__

/* macros for field clear_intrpt0 */
/**
 * @defgroup at_apb_gadc_regs_core_clear_intrpt0_field clear_intrpt0_field
 * @brief macros for field clear_intrpt0
 * @details clear intrpt0; (__SELF_CLEARING__)
 * @{
 */
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__SHIFT                           0
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__WIDTH                           1
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__MASK                  0x00000001U
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT0__RESET_VALUE           0x00000000U
/** @} */

/* macros for field clear_intrpt1 */
/**
 * @defgroup at_apb_gadc_regs_core_clear_intrpt1_field clear_intrpt1_field
 * @brief macros for field clear_intrpt1
 * @details clear intrpt1; (__SELF_CLEARING__)
 * @{
 */
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__SHIFT                           1
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__WIDTH                           1
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__MASK                  0x00000002U
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT1__RESET_VALUE           0x00000000U
/** @} */

/* macros for field clear_intrpt2 */
/**
 * @defgroup at_apb_gadc_regs_core_clear_intrpt2_field clear_intrpt2_field
 * @brief macros for field clear_intrpt2
 * @details clear intrpt2; (__SELF_CLEARING__)
 * @{
 */
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__SHIFT                           2
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__WIDTH                           1
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__MASK                  0x00000004U
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT2__RESET_VALUE           0x00000000U
/** @} */

/* macros for field clear_intrpt3 */
/**
 * @defgroup at_apb_gadc_regs_core_clear_intrpt3_field clear_intrpt3_field
 * @brief macros for field clear_intrpt3
 * @details clear intrpt3; (__SELF_CLEARING__)
 * @{
 */
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__SHIFT                           3
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__WIDTH                           1
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__MASK                  0x00000008U
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define DGADC_INTERRUPT_CLEAR__CLEAR_INTRPT3__RESET_VALUE           0x00000000U
/** @} */
#define DGADC_INTERRUPT_CLEAR__TYPE                                    uint32_t
#define DGADC_INTERRUPT_CLEAR__READ                                 0x0000000fU
#define DGADC_INTERRUPT_CLEAR__WRITE                                0x0000000fU
#define DGADC_INTERRUPT_CLEAR__PRESERVED                            0x00000000U
#define DGADC_INTERRUPT_CLEAR__RESET_VALUE                          0x00000000U

#endif /* __DGADC_INTERRUPT_CLEAR_MACRO__ */

/** @} end of interrupt_clear */

/* macros for BlueprintGlobalNameSpace::DGADC_fifo_dbg */
/**
 * @defgroup at_apb_gadc_regs_core_fifo_dbg fifo_dbg
 * @brief FIFO debug definitions.
 * @{
 */
#ifndef __DGADC_FIFO_DBG_MACRO__
#define __DGADC_FIFO_DBG_MACRO__

/* macros for field status */
/**
 * @defgroup at_apb_gadc_regs_core_status_field status_field
 * @brief macros for field status
 * @details FIFO debug status  [15] overrun  [14] underrun  [13] full  [12] empty  [7:4] rdaddr: read pointer  [3:0] wraddr: write pointer
 * @{
 */
#define DGADC_FIFO_DBG__STATUS__SHIFT                                         0
#define DGADC_FIFO_DBG__STATUS__WIDTH                                        16
#define DGADC_FIFO_DBG__STATUS__MASK                                0x0000ffffU
#define DGADC_FIFO_DBG__STATUS__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define DGADC_FIFO_DBG__STATUS__RESET_VALUE                         0x00000000U
/** @} */
#define DGADC_FIFO_DBG__TYPE                                           uint32_t
#define DGADC_FIFO_DBG__READ                                        0x0000ffffU
#define DGADC_FIFO_DBG__PRESERVED                                   0x00000000U
#define DGADC_FIFO_DBG__RESET_VALUE                                 0x00000000U

#endif /* __DGADC_FIFO_DBG_MACRO__ */

/** @} end of fifo_dbg */

/* macros for BlueprintGlobalNameSpace::DGADC_debug */
/**
 * @defgroup at_apb_gadc_regs_core_debug debug
 * @brief Exposes debug signals on gadc_dbg[4:0] definitions.
 * @{
 */
#ifndef __DGADC_DEBUG_MACRO__
#define __DGADC_DEBUG_MACRO__

/* macros for field select */
/**
 * @defgroup at_apb_gadc_regs_core_select_field select_field
 * @brief macros for field select
 * @details debug mux select  0: {ctrl fsm idle, dp dvalid, ch capture on, df osr done, df digital reset}  1: {ctrl fsm [4:0]}  2: {1'b0, gadc_ch_sel[3:0]}  3: {1'b0, offset cal done, offset cal fsm [1:0], offset cal on}
 * @{
 */
#define DGADC_DEBUG__SELECT__SHIFT                                            0
#define DGADC_DEBUG__SELECT__WIDTH                                            2
#define DGADC_DEBUG__SELECT__MASK                                   0x00000003U
#define DGADC_DEBUG__SELECT__READ(src)          ((uint32_t)(src) & 0x00000003U)
#define DGADC_DEBUG__SELECT__WRITE(src)         ((uint32_t)(src) & 0x00000003U)
#define DGADC_DEBUG__SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define DGADC_DEBUG__SELECT__VERIFY(src)  (!(((uint32_t)(src) & ~0x00000003U)))
#define DGADC_DEBUG__SELECT__RESET_VALUE                            0x00000000U
/** @} */
#define DGADC_DEBUG__TYPE                                              uint32_t
#define DGADC_DEBUG__READ                                           0x00000003U
#define DGADC_DEBUG__WRITE                                          0x00000003U
#define DGADC_DEBUG__PRESERVED                                      0x00000000U
#define DGADC_DEBUG__RESET_VALUE                                    0x00000000U

#endif /* __DGADC_DEBUG_MACRO__ */

/** @} end of debug */

/* macros for BlueprintGlobalNameSpace::DGADC_core_id */
/**
 * @defgroup at_apb_gadc_regs_core_core_id core_id
 * @brief core ID definitions.
 * @{
 */
#ifndef __DGADC_CORE_ID_MACRO__
#define __DGADC_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_gadc_regs_core_id_field id_field
 * @brief macros for field id
 * @details GADC in ASCII
 * @{
 */
#define DGADC_CORE_ID__ID__SHIFT                                              0
#define DGADC_CORE_ID__ID__WIDTH                                             32
#define DGADC_CORE_ID__ID__MASK                                     0xffffffffU
#define DGADC_CORE_ID__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define DGADC_CORE_ID__ID__RESET_VALUE                              0x47414443U
/** @} */
#define DGADC_CORE_ID__TYPE                                            uint32_t
#define DGADC_CORE_ID__READ                                         0xffffffffU
#define DGADC_CORE_ID__PRESERVED                                    0x00000000U
#define DGADC_CORE_ID__RESET_VALUE                                  0x47414443U

#endif /* __DGADC_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::DGADC_rev_hash */
/**
 * @defgroup at_apb_gadc_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __DGADC_REV_HASH_MACRO__
#define __DGADC_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_gadc_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define DGADC_REV_HASH__ID__SHIFT                                             0
#define DGADC_REV_HASH__ID__WIDTH                                            32
#define DGADC_REV_HASH__ID__MASK                                    0xffffffffU
#define DGADC_REV_HASH__ID__READ(src)           ((uint32_t)(src) & 0xffffffffU)
#define DGADC_REV_HASH__ID__RESET_VALUE                             0x98520728U
/** @} */
#define DGADC_REV_HASH__TYPE                                           uint32_t
#define DGADC_REV_HASH__READ                                        0xffffffffU
#define DGADC_REV_HASH__PRESERVED                                   0x00000000U
#define DGADC_REV_HASH__RESET_VALUE                                 0x98520728U

#endif /* __DGADC_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::DGADC_rev_key */
/**
 * @defgroup at_apb_gadc_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __DGADC_REV_KEY_MACRO__
#define __DGADC_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_gadc_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define DGADC_REV_KEY__ID__SHIFT                                              0
#define DGADC_REV_KEY__ID__WIDTH                                             32
#define DGADC_REV_KEY__ID__MASK                                     0xffffffffU
#define DGADC_REV_KEY__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define DGADC_REV_KEY__ID__RESET_VALUE                              0x52455620U
/** @} */
#define DGADC_REV_KEY__TYPE                                            uint32_t
#define DGADC_REV_KEY__READ                                         0xffffffffU
#define DGADC_REV_KEY__PRESERVED                                    0x00000000U
#define DGADC_REV_KEY__RESET_VALUE                                  0x52455620U

#endif /* __DGADC_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_GADC_REGS_CORE */
#endif /* __REG_AT_APB_GADC_REGS_CORE_H__ */
