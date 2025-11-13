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
 * @details Do 8 clocks cycle of warmup at beginning of round. No data sampled during this period.
 * @{
 */
#define DGADC_CTRL__WARMUP__SHIFT                                             2
#define DGADC_CTRL__WARMUP__WIDTH                                             1
#define DGADC_CTRL__WARMUP__MASK                                    0x00000004U
#define DGADC_CTRL__WARMUP__READ(src)    (((uint32_t)(src) & 0x00000004U) >> 2)
#define DGADC_CTRL__WARMUP__WRITE(src)   (((uint32_t)(src) << 2) & 0x00000004U)
#define DGADC_CTRL__WARMUP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define DGADC_CTRL__WARMUP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define DGADC_CTRL__WARMUP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define DGADC_CTRL__WARMUP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define DGADC_CTRL__WARMUP__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field code */
/**
 * @defgroup at_apb_gadc_regs_core_code_field code_field
 * @brief macros for field code
 * @details Specifies ADC input data code bit representation.  0 = MSB of input gadc data is inverted  1 = MSB of input gadc data is not inverted Data in pedestal format is converted to 2's complement.
 * @{
 */
#define DGADC_CTRL__CODE__SHIFT                                               3
#define DGADC_CTRL__CODE__WIDTH                                               1
#define DGADC_CTRL__CODE__MASK                                      0x00000008U
#define DGADC_CTRL__CODE__READ(src)      (((uint32_t)(src) & 0x00000008U) >> 3)
#define DGADC_CTRL__CODE__WRITE(src)     (((uint32_t)(src) << 3) & 0x00000008U)
#define DGADC_CTRL__CODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define DGADC_CTRL__CODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define DGADC_CTRL__CODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define DGADC_CTRL__CODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define DGADC_CTRL__CODE__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field clkdiv */
/**
 * @defgroup at_apb_gadc_regs_core_clkdiv_field clkdiv_field
 * @brief macros for field clkdiv
 * @details gadc clock frequency  0 = 2.00MHz  1 = 1.00MHz  2 = 0.50MHz  3 = 0.25MHz
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
#define DGADC_CTRL__WAIT_AMOUNT__RESET_VALUE                        0x00000004U
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
 * @details Which channels are active?  bit 0 = Not Used  bit 1 = Vbatt  bit 2 = Vstor  bit 3 = core supply  bit 4 = temperature  bit 5 = external port 1; differential  bit 6 = external port 0; differential  bit 7 = external port 1; single ended pos  bit 8 = external port 1; single ended neg  bit 9 = external port 0; single ended pos bit 10 = external port 0; single ended neg bit 11 = Vli-ion  bit 12-14 = input short  bit 15 = No-Connect
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
#define DGADC_CTRL__RESET_VALUE                                     0x00000100U

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
 * @details when override is set, what's the gadc channel to select.
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

/* macros for field ddr_en */
/**
 * @defgroup at_apb_gadc_regs_core_ddr_en_field ddr_en_field
 * @brief macros for field ddr_en
 * @details for debug; brings out gadc_out as a 6b wide ddr bus
 * @{
 */
#define DGADC_CTRL1__DDR_EN__SHIFT                                            5
#define DGADC_CTRL1__DDR_EN__WIDTH                                            1
#define DGADC_CTRL1__DDR_EN__MASK                                   0x00000020U
#define DGADC_CTRL1__DDR_EN__READ(src)   (((uint32_t)(src) & 0x00000020U) >> 5)
#define DGADC_CTRL1__DDR_EN__WRITE(src)  (((uint32_t)(src) << 5) & 0x00000020U)
#define DGADC_CTRL1__DDR_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define DGADC_CTRL1__DDR_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define DGADC_CTRL1__DDR_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define DGADC_CTRL1__DDR_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define DGADC_CTRL1__DDR_EN__RESET_VALUE                            0x00000000U
/** @} */
#define DGADC_CTRL1__TYPE                                              uint32_t
#define DGADC_CTRL1__READ                                           0x0000003fU
#define DGADC_CTRL1__WRITE                                          0x0000003fU
#define DGADC_CTRL1__PRESERVED                                      0x00000000U
#define DGADC_CTRL1__RESET_VALUE                                    0x00000000U

#endif /* __DGADC_CTRL1_MACRO__ */

/** @} end of ctrl1 */

/* macros for BlueprintGlobalNameSpace::DGADC_ch1_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch1_datapath_config ch1_datapath_config
 * @brief channel-1 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH1_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH1_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH1_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH1_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH1_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH1_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH1_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH1_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH1_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH1_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH1_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch1_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch2_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch2_datapath_config ch2_datapath_config
 * @brief channel-2 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH2_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH2_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH2_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH2_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH2_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH2_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH2_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH2_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH2_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH2_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH2_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch2_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch3_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch3_datapath_config ch3_datapath_config
 * @brief channel-3 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH3_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH3_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH3_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH3_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH3_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH3_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH3_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH3_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH3_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH3_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH3_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch3_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch4_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch4_datapath_config ch4_datapath_config
 * @brief channel-4 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH4_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH4_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH4_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH4_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH4_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH4_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH4_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH4_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH4_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH4_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH4_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch4_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch5_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch5_datapath_config ch5_datapath_config
 * @brief channel-5 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH5_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH5_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH5_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH5_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH5_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH5_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH5_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH5_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH5_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH5_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH5_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch5_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch6_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch6_datapath_config ch6_datapath_config
 * @brief channel-6 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH6_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH6_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH6_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH6_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH6_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH6_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH6_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH6_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH6_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH6_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH6_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch6_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch7_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch7_datapath_config ch7_datapath_config
 * @brief channel-7 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH7_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH7_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH7_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH7_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH7_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH7_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH7_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH7_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH7_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH7_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH7_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch7_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch8_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch8_datapath_config ch8_datapath_config
 * @brief channel-8 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH8_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH8_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH8_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH8_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH8_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH8_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH8_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH8_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH8_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH8_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH8_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch8_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch9_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch9_datapath_config ch9_datapath_config
 * @brief channel-9 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH9_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH9_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__SHIFT                                0
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__WIDTH                               13
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__MASK                       0x00001fffU
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH9_DATAPATH_CONFIG__GAIN__RESET_VALUE                0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__SHIFT                           13
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__WIDTH                            5
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__MASK                   0x0003e000U
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH9_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE            0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__SHIFT                             18
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__WIDTH                             14
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__MASK                     0xfffc0000U
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH9_DATAPATH_CONFIG__OFFSET__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_CH9_DATAPATH_CONFIG__TYPE                                uint32_t
#define DGADC_CH9_DATAPATH_CONFIG__READ                             0xffffffffU
#define DGADC_CH9_DATAPATH_CONFIG__WRITE                            0xffffffffU
#define DGADC_CH9_DATAPATH_CONFIG__PRESERVED                        0x00000000U
#define DGADC_CH9_DATAPATH_CONFIG__RESET_VALUE                      0x00002800U

#endif /* __DGADC_CH9_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch9_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch10_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch10_datapath_config ch10_datapath_config
 * @brief channel-10 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH10_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH10_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__SHIFT                               0
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__WIDTH                              13
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__MASK                      0x00001fffU
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH10_DATAPATH_CONFIG__GAIN__RESET_VALUE               0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__SHIFT                          13
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__WIDTH                           5
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__MASK                  0x0003e000U
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH10_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE           0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__SHIFT                            18
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__WIDTH                            14
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__MASK                    0xfffc0000U
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH10_DATAPATH_CONFIG__OFFSET__RESET_VALUE             0x00000000U
/** @} */
#define DGADC_CH10_DATAPATH_CONFIG__TYPE                               uint32_t
#define DGADC_CH10_DATAPATH_CONFIG__READ                            0xffffffffU
#define DGADC_CH10_DATAPATH_CONFIG__WRITE                           0xffffffffU
#define DGADC_CH10_DATAPATH_CONFIG__PRESERVED                       0x00000000U
#define DGADC_CH10_DATAPATH_CONFIG__RESET_VALUE                     0x00002800U

#endif /* __DGADC_CH10_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch10_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch11_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch11_datapath_config ch11_datapath_config
 * @brief channel-11 offset and gain datpath parameters definitions.
 * @{
 */
#ifndef __DGADC_CH11_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH11_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__SHIFT                               0
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__WIDTH                              13
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__MASK                      0x00001fffU
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH11_DATAPATH_CONFIG__GAIN__RESET_VALUE               0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__SHIFT                          13
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__WIDTH                           5
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__MASK                  0x0003e000U
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH11_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE           0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__SHIFT                            18
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__WIDTH                            14
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__MASK                    0xfffc0000U
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH11_DATAPATH_CONFIG__OFFSET__RESET_VALUE             0x00000000U
/** @} */
#define DGADC_CH11_DATAPATH_CONFIG__TYPE                               uint32_t
#define DGADC_CH11_DATAPATH_CONFIG__READ                            0xffffffffU
#define DGADC_CH11_DATAPATH_CONFIG__WRITE                           0xffffffffU
#define DGADC_CH11_DATAPATH_CONFIG__PRESERVED                       0x00000000U
#define DGADC_CH11_DATAPATH_CONFIG__RESET_VALUE                     0x00002800U

#endif /* __DGADC_CH11_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch11_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_ch12_datapath_config */
/**
 * @defgroup at_apb_gadc_regs_core_ch12_datapath_config ch12_datapath_config
 * @brief channel-12 offset and gain datpath parameters applied to unused channels 0,13,14 by defaults definitions.
 * @{
 */
#ifndef __DGADC_CH12_DATAPATH_CONFIG_MACRO__
#define __DGADC_CH12_DATAPATH_CONFIG_MACRO__

/* macros for field gain */
/**
 * @defgroup at_apb_gadc_regs_core_gain_field gain_field
 * @brief macros for field gain
 * @details Q<0,12> gain number
 * @{
 */
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__SHIFT                               0
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__WIDTH                              13
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__MASK                      0x00001fffU
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define DGADC_CH12_DATAPATH_CONFIG__GAIN__RESET_VALUE               0x00000800U
/** @} */

/* macros for field gain_exp */
/**
 * @defgroup at_apb_gadc_regs_core_gain_exp_field gain_exp_field
 * @brief macros for field gain_exp
 * @details Q<4,0> gain exponent
 * @{
 */
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__SHIFT                          13
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__WIDTH                           5
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__MASK                  0x0003e000U
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define DGADC_CH12_DATAPATH_CONFIG__GAIN_EXP__RESET_VALUE           0x00000001U
/** @} */

/* macros for field offset */
/**
 * @defgroup at_apb_gadc_regs_core_offset_field offset_field
 * @brief macros for field offset
 * @details Q<9,4> offset
 * @{
 */
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__SHIFT                            18
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__WIDTH                            14
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__MASK                    0xfffc0000U
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffc0000U) >> 18)
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0xfffc0000U)
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffc0000U) | (((uint32_t)(src) <<\
                    18) & 0xfffc0000U)
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0xfffc0000U)))
#define DGADC_CH12_DATAPATH_CONFIG__OFFSET__RESET_VALUE             0x00000000U
/** @} */
#define DGADC_CH12_DATAPATH_CONFIG__TYPE                               uint32_t
#define DGADC_CH12_DATAPATH_CONFIG__READ                            0xffffffffU
#define DGADC_CH12_DATAPATH_CONFIG__WRITE                           0xffffffffU
#define DGADC_CH12_DATAPATH_CONFIG__PRESERVED                       0x00000000U
#define DGADC_CH12_DATAPATH_CONFIG__RESET_VALUE                     0x00002800U

#endif /* __DGADC_CH12_DATAPATH_CONFIG_MACRO__ */

/** @} end of ch12_datapath_config */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_config0 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_config0 gain_config0
 * @brief channels 1-10 gain settings selection definitions.
 * @{
 */
#ifndef __DGADC_GAIN_CONFIG0_MACRO__
#define __DGADC_GAIN_CONFIG0_MACRO__

/* macros for field ch1_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch1_gain_sel_field ch1_gain_sel_field
 * @brief macros for field ch1_gain_sel
 * @details channel-1 gain settings
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
#define DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch2_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch2_gain_sel_field ch2_gain_sel_field
 * @brief macros for field ch2_gain_sel
 * @details channel-2 gain settings
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
#define DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch3_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch3_gain_sel_field ch3_gain_sel_field
 * @brief macros for field ch3_gain_sel
 * @details channel-3 gain settings
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
#define DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch4_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch4_gain_sel_field ch4_gain_sel_field
 * @brief macros for field ch4_gain_sel
 * @details channel-4 gain settings
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
 * @details channel-5 gain settings
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
#define DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch6_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch6_gain_sel_field ch6_gain_sel_field
 * @brief macros for field ch6_gain_sel
 * @details channel-6 gain settings
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
#define DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch7_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch7_gain_sel_field ch7_gain_sel_field
 * @brief macros for field ch7_gain_sel
 * @details channel-7 gain settings
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
#define DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch8_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch8_gain_sel_field ch8_gain_sel_field
 * @brief macros for field ch8_gain_sel
 * @details channel-8 gain settings
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
#define DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch9_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch9_gain_sel_field ch9_gain_sel_field
 * @brief macros for field ch9_gain_sel
 * @details channel-9 gain settings
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
#define DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ch10_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch10_gain_sel_field ch10_gain_sel_field
 * @brief macros for field ch10_gain_sel
 * @details channel-10 gain settings
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
#define DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__RESET_VALUE              0x00000000U
/** @} */
#define DGADC_GAIN_CONFIG0__TYPE                                       uint32_t
#define DGADC_GAIN_CONFIG0__READ                                    0x3fffffffU
#define DGADC_GAIN_CONFIG0__WRITE                                   0x3fffffffU
#define DGADC_GAIN_CONFIG0__PRESERVED                               0x00000000U
#define DGADC_GAIN_CONFIG0__RESET_VALUE                             0x00000000U

#endif /* __DGADC_GAIN_CONFIG0_MACRO__ */

/** @} end of gain_config0 */

/* macros for BlueprintGlobalNameSpace::DGADC_gain_config1 */
/**
 * @defgroup at_apb_gadc_regs_core_gain_config1 gain_config1
 * @brief channels 11-15 gain settings selection definitions.
 * @{
 */
#ifndef __DGADC_GAIN_CONFIG1_MACRO__
#define __DGADC_GAIN_CONFIG1_MACRO__

/* macros for field ch11_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch11_gain_sel_field ch11_gain_sel_field
 * @brief macros for field ch11_gain_sel
 * @details channel-11 gain settings
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
#define DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ch12_gain_sel */
/**
 * @defgroup at_apb_gadc_regs_core_ch12_gain_sel_field ch12_gain_sel_field
 * @brief macros for field ch12_gain_sel
 * @details channel-12 gain settings
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
#define DGADC_GAIN_CONFIG1__RESET_VALUE                             0x00000000U

#endif /* __DGADC_GAIN_CONFIG1_MACRO__ */

/** @} end of gain_config1 */

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
 * @details {4b channel id, 12b processed ADC sample Q<10,1>, 5b exponent}
 * @{
 */
#define DGADC_DATAPATH_OUTPUT__DATA__SHIFT                                    0
#define DGADC_DATAPATH_OUTPUT__DATA__WIDTH                                   21
#define DGADC_DATAPATH_OUTPUT__DATA__MASK                           0x001fffffU
#define DGADC_DATAPATH_OUTPUT__DATA__READ(src)  ((uint32_t)(src) & 0x001fffffU)
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
#define DGADC_DATAPATH_OUTPUT__READ                                 0x801fffffU
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
 * @details fifo overran
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
 * @details one shot or one round of continuous mode has completed
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
#define DGADC_INTERRUPTS__TYPE                                         uint32_t
#define DGADC_INTERRUPTS__READ                                      0x00000007U
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
#define DGADC_INTERRUPT_MASK__TYPE                                     uint32_t
#define DGADC_INTERRUPT_MASK__READ                                  0x00000007U
#define DGADC_INTERRUPT_MASK__WRITE                                 0x00000007U
#define DGADC_INTERRUPT_MASK__PRESERVED                             0x00000000U
#define DGADC_INTERRUPT_MASK__RESET_VALUE                           0x00000007U

#endif /* __DGADC_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::DGADC_interrupt_clear */
/**
 * @defgroup at_apb_gadc_regs_core_interrupt_clear interrupt_clear
 * @brief clear interrupts definitions.
 * @{
 */
#ifndef __DGADC_INTERRUPT_CLEAR_MACRO__
#define __DGADC_INTERRUPT_CLEAR_MACRO__

/* macros for field clear_intrpt0 */
/**
 * @defgroup at_apb_gadc_regs_core_clear_intrpt0_field clear_intrpt0_field
 * @brief macros for field clear_intrpt0
 * @details clear interrupt 0; not self reseting
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
 * @details clear interrupt 1; not self reseting
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
 * @details clear interrupt 2; not self reseting
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
#define DGADC_INTERRUPT_CLEAR__TYPE                                    uint32_t
#define DGADC_INTERRUPT_CLEAR__READ                                 0x00000007U
#define DGADC_INTERRUPT_CLEAR__WRITE                                0x00000007U
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
 * @details FIFO debug status
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

/** @} end of AT_APB_GADC_REGS_CORE */
#endif /* __REG_AT_APB_GADC_REGS_CORE_H__ */
