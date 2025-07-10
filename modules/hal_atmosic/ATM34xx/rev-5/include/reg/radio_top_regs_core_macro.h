/*                                                                           */
/* File:       radio_top_regs_core_macro.h                                   */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic radio_top_regs_core.rdl            */
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


#ifndef __REG_RADIO_TOP_REGS_CORE_H__
#define __REG_RADIO_TOP_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup RADIO_TOP_REGS_CORE radio_top_regs_core
 * @ingroup AT_REG
 * @brief radio_top_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::radio_top_mode */
/**
 * @defgroup radio_top_regs_core_mode mode
 * @brief Mode control overrides (mostly from RIF) definitions.
 * @{
 */
#ifndef __RADIO_TOP_MODE_MACRO__
#define __RADIO_TOP_MODE_MACRO__

/* macros for field synthon_ovr */
/**
 * @defgroup radio_top_regs_core_synthon_ovr_field synthon_ovr_field
 * @brief macros for field synthon_ovr
 * @details synthon override
 * @{
 */
#define RADIO_TOP_MODE__SYNTHON_OVR__SHIFT                                    0
#define RADIO_TOP_MODE__SYNTHON_OVR__WIDTH                                    2
#define RADIO_TOP_MODE__SYNTHON_OVR__MASK                           0x00000003U
#define RADIO_TOP_MODE__SYNTHON_OVR__READ(src)  ((uint32_t)(src) & 0x00000003U)
#define RADIO_TOP_MODE__SYNTHON_OVR__WRITE(src) ((uint32_t)(src) & 0x00000003U)
#define RADIO_TOP_MODE__SYNTHON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define RADIO_TOP_MODE__SYNTHON_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define RADIO_TOP_MODE__SYNTHON_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field txon_ovr */
/**
 * @defgroup radio_top_regs_core_txon_ovr_field txon_ovr_field
 * @brief macros for field txon_ovr
 * @details txon override
 * @{
 */
#define RADIO_TOP_MODE__TXON_OVR__SHIFT                                       2
#define RADIO_TOP_MODE__TXON_OVR__WIDTH                                       2
#define RADIO_TOP_MODE__TXON_OVR__MASK                              0x0000000cU
#define RADIO_TOP_MODE__TXON_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define RADIO_TOP_MODE__TXON_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define RADIO_TOP_MODE__TXON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define RADIO_TOP_MODE__TXON_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define RADIO_TOP_MODE__TXON_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field paon_ovr */
/**
 * @defgroup radio_top_regs_core_paon_ovr_field paon_ovr_field
 * @brief macros for field paon_ovr
 * @details paon override
 * @{
 */
#define RADIO_TOP_MODE__PAON_OVR__SHIFT                                       4
#define RADIO_TOP_MODE__PAON_OVR__WIDTH                                       2
#define RADIO_TOP_MODE__PAON_OVR__MASK                              0x00000030U
#define RADIO_TOP_MODE__PAON_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define RADIO_TOP_MODE__PAON_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define RADIO_TOP_MODE__PAON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define RADIO_TOP_MODE__PAON_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define RADIO_TOP_MODE__PAON_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rxon_ovr */
/**
 * @defgroup radio_top_regs_core_rxon_ovr_field rxon_ovr_field
 * @brief macros for field rxon_ovr
 * @details rxon override
 * @{
 */
#define RADIO_TOP_MODE__RXON_OVR__SHIFT                                       6
#define RADIO_TOP_MODE__RXON_OVR__WIDTH                                       2
#define RADIO_TOP_MODE__RXON_OVR__MASK                              0x000000c0U
#define RADIO_TOP_MODE__RXON_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define RADIO_TOP_MODE__RXON_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define RADIO_TOP_MODE__RXON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define RADIO_TOP_MODE__RXON_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define RADIO_TOP_MODE__RXON_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field adcon_ovr */
/**
 * @defgroup radio_top_regs_core_adcon_ovr_field adcon_ovr_field
 * @brief macros for field adcon_ovr
 * @details adcon override
 * @{
 */
#define RADIO_TOP_MODE__ADCON_OVR__SHIFT                                      8
#define RADIO_TOP_MODE__ADCON_OVR__WIDTH                                      2
#define RADIO_TOP_MODE__ADCON_OVR__MASK                             0x00000300U
#define RADIO_TOP_MODE__ADCON_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define RADIO_TOP_MODE__ADCON_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define RADIO_TOP_MODE__ADCON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define RADIO_TOP_MODE__ADCON_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define RADIO_TOP_MODE__ADCON_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field adcon_early_ovr */
/**
 * @defgroup radio_top_regs_core_adcon_early_ovr_field adcon_early_ovr_field
 * @brief macros for field adcon_early_ovr
 * @details adcon_early override
 * @{
 */
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__SHIFT                               10
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__WIDTH                                2
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__MASK                       0x00000c00U
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define RADIO_TOP_MODE__ADCON_EARLY_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field clkrf_en_ovr */
/**
 * @defgroup radio_top_regs_core_clkrf_en_ovr_field clkrf_en_ovr_field
 * @brief macros for field clkrf_en_ovr
 * @details Synth XTAL clock buffer enable override
 * @{
 */
#define RADIO_TOP_MODE__CLKRF_EN_OVR__SHIFT                                  12
#define RADIO_TOP_MODE__CLKRF_EN_OVR__WIDTH                                   2
#define RADIO_TOP_MODE__CLKRF_EN_OVR__MASK                          0x00003000U
#define RADIO_TOP_MODE__CLKRF_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define RADIO_TOP_MODE__CLKRF_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define RADIO_TOP_MODE__CLKRF_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define RADIO_TOP_MODE__CLKRF_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define RADIO_TOP_MODE__CLKRF_EN_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field clkadc_en_ovr */
/**
 * @defgroup radio_top_regs_core_clkadc_en_ovr_field clkadc_en_ovr_field
 * @brief macros for field clkadc_en_ovr
 * @details ADC XTAL clock buffer enable override
 * @{
 */
#define RADIO_TOP_MODE__CLKADC_EN_OVR__SHIFT                                 14
#define RADIO_TOP_MODE__CLKADC_EN_OVR__WIDTH                                  2
#define RADIO_TOP_MODE__CLKADC_EN_OVR__MASK                         0x0000c000U
#define RADIO_TOP_MODE__CLKADC_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000c000U) >> 14)
#define RADIO_TOP_MODE__CLKADC_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0000c000U)
#define RADIO_TOP_MODE__CLKADC_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define RADIO_TOP_MODE__CLKADC_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define RADIO_TOP_MODE__CLKADC_EN_OVR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field sel_clkadc */
/**
 * @defgroup radio_top_regs_core_sel_clkadc_field sel_clkadc_field
 * @brief macros for field sel_clkadc
 * @details ADC clock frequency selection, 2'b00 = xtal, 2'b01 = xtal*2, 2'b10 = xtal/2
 * @{
 */
#define RADIO_TOP_MODE__SEL_CLKADC__SHIFT                                    16
#define RADIO_TOP_MODE__SEL_CLKADC__WIDTH                                     2
#define RADIO_TOP_MODE__SEL_CLKADC__MASK                            0x00030000U
#define RADIO_TOP_MODE__SEL_CLKADC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define RADIO_TOP_MODE__SEL_CLKADC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define RADIO_TOP_MODE__SEL_CLKADC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define RADIO_TOP_MODE__SEL_CLKADC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define RADIO_TOP_MODE__SEL_CLKADC__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field clkpm_en */
/**
 * @defgroup radio_top_regs_core_clkpm_en_field clkpm_en_field
 * @brief macros for field clkpm_en
 * @details Process monitor clock buffer enable
 * @{
 */
#define RADIO_TOP_MODE__CLKPM_EN__SHIFT                                      18
#define RADIO_TOP_MODE__CLKPM_EN__WIDTH                                       1
#define RADIO_TOP_MODE__CLKPM_EN__MASK                              0x00040000U
#define RADIO_TOP_MODE__CLKPM_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define RADIO_TOP_MODE__CLKPM_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define RADIO_TOP_MODE__CLKPM_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define RADIO_TOP_MODE__CLKPM_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define RADIO_TOP_MODE__CLKPM_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define RADIO_TOP_MODE__CLKPM_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define RADIO_TOP_MODE__CLKPM_EN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field sparebits */
/**
 * @defgroup radio_top_regs_core_sparebits_field sparebits_field
 * @brief macros for field sparebits
 * @details spares
 * @{
 */
#define RADIO_TOP_MODE__SPAREBITS__SHIFT                                     19
#define RADIO_TOP_MODE__SPAREBITS__WIDTH                                      5
#define RADIO_TOP_MODE__SPAREBITS__MASK                             0x00f80000U
#define RADIO_TOP_MODE__SPAREBITS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f80000U) >> 19)
#define RADIO_TOP_MODE__SPAREBITS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00f80000U)
#define RADIO_TOP_MODE__SPAREBITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f80000U) | (((uint32_t)(src) <<\
                    19) & 0x00f80000U)
#define RADIO_TOP_MODE__SPAREBITS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00f80000U)))
#define RADIO_TOP_MODE__SPAREBITS__RESET_VALUE                      0x00000000U
/** @} */
#define RADIO_TOP_MODE__TYPE                                           uint32_t
#define RADIO_TOP_MODE__READ                                        0x00ffffffU
#define RADIO_TOP_MODE__WRITE                                       0x00ffffffU
#define RADIO_TOP_MODE__PRESERVED                                   0x00000000U
#define RADIO_TOP_MODE__RESET_VALUE                                 0x00000000U

#endif /* __RADIO_TOP_MODE_MACRO__ */

/** @} end of mode */

/* macros for BlueprintGlobalNameSpace::radio_top_bias */
/**
 * @defgroup radio_top_regs_core_bias bias
 * @brief Bandgap and LDO settings definitions.
 * @{
 */
#ifndef __RADIO_TOP_BIAS_MACRO__
#define __RADIO_TOP_BIAS_MACRO__

/* macros for field bgtrim */
/**
 * @defgroup radio_top_regs_core_bgtrim_field bgtrim_field
 * @brief macros for field bgtrim
 * @details Bandgap tempco trim
 * @{
 */
#define RADIO_TOP_BIAS__BGTRIM__SHIFT                                         0
#define RADIO_TOP_BIAS__BGTRIM__WIDTH                                         4
#define RADIO_TOP_BIAS__BGTRIM__MASK                                0x0000000fU
#define RADIO_TOP_BIAS__BGTRIM__READ(src)       ((uint32_t)(src) & 0x0000000fU)
#define RADIO_TOP_BIAS__BGTRIM__WRITE(src)      ((uint32_t)(src) & 0x0000000fU)
#define RADIO_TOP_BIAS__BGTRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RADIO_TOP_BIAS__BGTRIM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define RADIO_TOP_BIAS__BGTRIM__RESET_VALUE                         0x00000008U
/** @} */

/* macros for field irtrim */
/**
 * @defgroup radio_top_regs_core_irtrim_field irtrim_field
 * @brief macros for field irtrim
 * @details IR resistor trim, ie. global IR resistor adjustment
 * @{
 */
#define RADIO_TOP_BIAS__IRTRIM__SHIFT                                         4
#define RADIO_TOP_BIAS__IRTRIM__WIDTH                                         6
#define RADIO_TOP_BIAS__IRTRIM__MASK                                0x000003f0U
#define RADIO_TOP_BIAS__IRTRIM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003f0U) >> 4)
#define RADIO_TOP_BIAS__IRTRIM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000003f0U)
#define RADIO_TOP_BIAS__IRTRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003f0U) | (((uint32_t)(src) <<\
                    4) & 0x000003f0U)
#define RADIO_TOP_BIAS__IRTRIM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000003f0U)))
#define RADIO_TOP_BIAS__IRTRIM__RESET_VALUE                         0x00000020U
/** @} */

/* macros for field bg_shrb_ovr */
/**
 * @defgroup radio_top_regs_core_bg_shrb_ovr_field bg_shrb_ovr_field
 * @brief macros for field bg_shrb_ovr
 * @details Force shorting of filter resistor in bandgap
 * @{
 */
#define RADIO_TOP_BIAS__BG_SHRB_OVR__SHIFT                                   10
#define RADIO_TOP_BIAS__BG_SHRB_OVR__WIDTH                                    1
#define RADIO_TOP_BIAS__BG_SHRB_OVR__MASK                           0x00000400U
#define RADIO_TOP_BIAS__BG_SHRB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define RADIO_TOP_BIAS__BG_SHRB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define RADIO_TOP_BIAS__BG_SHRB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define RADIO_TOP_BIAS__BG_SHRB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define RADIO_TOP_BIAS__BG_SHRB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define RADIO_TOP_BIAS__BG_SHRB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define RADIO_TOP_BIAS__BG_SHRB_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_ldo_top_ovr */
/**
 * @defgroup radio_top_regs_core_en_ldo_top_ovr_field en_ldo_top_ovr_field
 * @brief macros for field en_ldo_top_ovr
 * @details Top LDO enable override, MSB enables override, LSB is override value
 * @{
 */
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__SHIFT                                11
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__WIDTH                                 2
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__MASK                        0x00001800U
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define RADIO_TOP_BIAS__EN_LDO_TOP_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field en_ldo_ovr */
/**
 * @defgroup radio_top_regs_core_en_ldo_ovr_field en_ldo_ovr_field
 * @brief macros for field en_ldo_ovr
 * @details Block LDO enable override, MSB enables override, LSB {RXFE, synthA, synthB, RXBB} is override value
 * @{
 */
#define RADIO_TOP_BIAS__EN_LDO_OVR__SHIFT                                    13
#define RADIO_TOP_BIAS__EN_LDO_OVR__WIDTH                                     5
#define RADIO_TOP_BIAS__EN_LDO_OVR__MASK                            0x0003e000U
#define RADIO_TOP_BIAS__EN_LDO_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003e000U) >> 13)
#define RADIO_TOP_BIAS__EN_LDO_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0003e000U)
#define RADIO_TOP_BIAS__EN_LDO_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003e000U) | (((uint32_t)(src) <<\
                    13) & 0x0003e000U)
#define RADIO_TOP_BIAS__EN_LDO_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0003e000U)))
#define RADIO_TOP_BIAS__EN_LDO_OVR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field ldo_bypass_top_ovr */
/**
 * @defgroup radio_top_regs_core_ldo_bypass_top_ovr_field ldo_bypass_top_ovr_field
 * @brief macros for field ldo_bypass_top_ovr
 * @details Top LDO bypass override; deprecated on Paris B0 and Perth
 * @{
 */
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__SHIFT                            18
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__WIDTH                             2
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__MASK                    0x000c0000U
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000c0000U) >> 18)
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x000c0000U)
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000c0000U) | (((uint32_t)(src) <<\
                    18) & 0x000c0000U)
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x000c0000U)))
#define RADIO_TOP_BIAS__LDO_BYPASS_TOP_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ldo_bypass_ovr */
/**
 * @defgroup radio_top_regs_core_ldo_bypass_ovr_field ldo_bypass_ovr_field
 * @brief macros for field ldo_bypass_ovr
 * @details Block LDO bypass override, MSB enables override, LSB is override value, overrides all LDOs, bits [4:1] unused
 * @{
 */
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__SHIFT                                20
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__WIDTH                                 5
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__MASK                        0x01f00000U
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define RADIO_TOP_BIAS__LDO_BYPASS_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ldo_shrb_top_ovr */
/**
 * @defgroup radio_top_regs_core_ldo_shrb_top_ovr_field ldo_shrb_top_ovr_field
 * @brief macros for field ldo_shrb_top_ovr
 * @details Force shorting of vref filter resistor for top LDO
 * @{
 */
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__SHIFT                              25
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__WIDTH                               1
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__MASK                      0x02000000U
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define RADIO_TOP_BIAS__LDO_SHRB_TOP_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ldo_shrb_ovr */
/**
 * @defgroup radio_top_regs_core_ldo_shrb_ovr_field ldo_shrb_ovr_field
 * @brief macros for field ldo_shrb_ovr
 * @details Force shorting of vref filter resistor for block LDOs
 * @{
 */
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__SHIFT                                  26
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__WIDTH                                   1
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__MASK                          0x04000000U
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define RADIO_TOP_BIAS__LDO_SHRB_OVR__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field cnt_shortres_b */
/**
 * @defgroup radio_top_regs_core_cnt_shortres_b_field cnt_shortres_b_field
 * @brief macros for field cnt_shortres_b
 * @details Time after radio reset deassertion to unshort bandgap and LDO filter resistors, 9us to 40us in 1us step, default 25us
 * @{
 */
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__SHIFT                                27
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__WIDTH                                 5
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__MASK                        0xf8000000U
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf8000000U) >> 27)
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0xf8000000U)
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf8000000U) | (((uint32_t)(src) <<\
                    27) & 0xf8000000U)
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0xf8000000U)))
#define RADIO_TOP_BIAS__CNT_SHORTRES_B__RESET_VALUE                 0x00000010U
/** @} */
#define RADIO_TOP_BIAS__TYPE                                           uint32_t
#define RADIO_TOP_BIAS__READ                                        0xffffffffU
#define RADIO_TOP_BIAS__WRITE                                       0xffffffffU
#define RADIO_TOP_BIAS__PRESERVED                                   0x00000000U
#define RADIO_TOP_BIAS__RESET_VALUE                                 0x80000208U

#endif /* __RADIO_TOP_BIAS_MACRO__ */

/** @} end of bias */

/* macros for BlueprintGlobalNameSpace::radio_top_test */
/**
 * @defgroup radio_top_regs_core_test test
 * @brief Test controls definitions.
 * @{
 */
#ifndef __RADIO_TOP_TEST_MACRO__
#define __RADIO_TOP_TEST_MACRO__

/* macros for field testiq_buf_en */
/**
 * @defgroup radio_top_regs_core_testiq_buf_en_field testiq_buf_en_field
 * @brief macros for field testiq_buf_en
 * @details Enable test I/Q buffers
 * @{
 */
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__SHIFT                                  0
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__WIDTH                                  1
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__MASK                         0x00000001U
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_TOP_TEST__TESTIQ_BUF_EN__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field testiq_buf_bypass */
/**
 * @defgroup radio_top_regs_core_testiq_buf_bypass_field testiq_buf_bypass_field
 * @brief macros for field testiq_buf_bypass
 * @details Bypass test I/Q buffers so analog test signals can be driven in
 * @{
 */
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__SHIFT                              1
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__WIDTH                              1
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__MASK                     0x00000002U
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RADIO_TOP_TEST__TESTIQ_BUF_BYPASS__RESET_VALUE              0x00000000U
/** @} */

/* macros for field testiq_pad_en */
/**
 * @defgroup radio_top_regs_core_testiq_pad_en_field testiq_pad_en_field
 * @brief macros for field testiq_pad_en
 * @details Deprecated on Paris/Perth; testIQ pad enable controls are in SOC pinmux
 * @{
 */
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__SHIFT                                  2
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__WIDTH                                  1
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__MASK                         0x00000004U
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RADIO_TOP_TEST__TESTIQ_PAD_EN__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field atb_pad_en */
/**
 * @defgroup radio_top_regs_core_atb_pad_en_field atb_pad_en_field
 * @brief macros for field atb_pad_en
 * @details Deprecated on Paris/Perth; ATB pad enable controls are in SOC pinmux
 * @{
 */
#define RADIO_TOP_TEST__ATB_PAD_EN__SHIFT                                     3
#define RADIO_TOP_TEST__ATB_PAD_EN__WIDTH                                     1
#define RADIO_TOP_TEST__ATB_PAD_EN__MASK                            0x00000008U
#define RADIO_TOP_TEST__ATB_PAD_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RADIO_TOP_TEST__ATB_PAD_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define RADIO_TOP_TEST__ATB_PAD_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define RADIO_TOP_TEST__ATB_PAD_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define RADIO_TOP_TEST__ATB_PAD_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RADIO_TOP_TEST__ATB_PAD_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RADIO_TOP_TEST__ATB_PAD_EN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field atb_sel */
/**
 * @defgroup radio_top_regs_core_atb_sel_field atb_sel_field
 * @brief macros for field atb_sel
 * @details Top-level ATB mux select, 0 = high-Z, 1 = bias, 2 = synth/TX, 3 = RX, 4 = LDO, 5 = PLL, 6,7 = reserved
 * @{
 */
#define RADIO_TOP_TEST__ATB_SEL__SHIFT                                        4
#define RADIO_TOP_TEST__ATB_SEL__WIDTH                                        3
#define RADIO_TOP_TEST__ATB_SEL__MASK                               0x00000070U
#define RADIO_TOP_TEST__ATB_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define RADIO_TOP_TEST__ATB_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define RADIO_TOP_TEST__ATB_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define RADIO_TOP_TEST__ATB_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define RADIO_TOP_TEST__ATB_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field dig_sel */
/**
 * @defgroup radio_top_regs_core_dig_sel_field dig_sel_field
 * @brief macros for field dig_sel
 * @details Select digital signals to put onto dig_test_out, 0 = tielo, 1 = xtal_stable, 2 = tia_peakdet, 3 = rfin_peakdet, 4 = wurx_comp_out, 5~7 = tielo
 * @{
 */
#define RADIO_TOP_TEST__DIG_SEL__SHIFT                                        7
#define RADIO_TOP_TEST__DIG_SEL__WIDTH                                        3
#define RADIO_TOP_TEST__DIG_SEL__MASK                               0x00000380U
#define RADIO_TOP_TEST__DIG_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define RADIO_TOP_TEST__DIG_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define RADIO_TOP_TEST__DIG_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define RADIO_TOP_TEST__DIG_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define RADIO_TOP_TEST__DIG_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field bias_atb_sel */
/**
 * @defgroup radio_top_regs_core_bias_atb_sel_field bias_atb_sel_field
 * @brief macros for field bias_atb_sel
 * @details Bias block ATB, 0 = high-Z, 1 = pcas, 2 = vc, 3 = vr, 4 = pcur, 5 = gnd, 6 = ir3_1uA, 7 = ic2_4uA
 * @{
 */
#define RADIO_TOP_TEST__BIAS_ATB_SEL__SHIFT                                  10
#define RADIO_TOP_TEST__BIAS_ATB_SEL__WIDTH                                   3
#define RADIO_TOP_TEST__BIAS_ATB_SEL__MASK                          0x00001c00U
#define RADIO_TOP_TEST__BIAS_ATB_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define RADIO_TOP_TEST__BIAS_ATB_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define RADIO_TOP_TEST__BIAS_ATB_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define RADIO_TOP_TEST__BIAS_ATB_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define RADIO_TOP_TEST__BIAS_ATB_SEL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ldo_atb_sel */
/**
 * @defgroup radio_top_regs_core_ldo_atb_sel_field ldo_atb_sel_field
 * @brief macros for field ldo_atb_sel
 * @details LDO ATB, 0 = high-Z, 1 = synthB vout/2, 2 = RXBB vout/2, 3 = top vout/2, 4 = block vref800mV, 5 = top vref800mV, 6 = block ir2u, 7 = top ir2u
 * @{
 */
#define RADIO_TOP_TEST__LDO_ATB_SEL__SHIFT                                   13
#define RADIO_TOP_TEST__LDO_ATB_SEL__WIDTH                                    3
#define RADIO_TOP_TEST__LDO_ATB_SEL__MASK                           0x0000e000U
#define RADIO_TOP_TEST__LDO_ATB_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define RADIO_TOP_TEST__LDO_ATB_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define RADIO_TOP_TEST__LDO_ATB_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define RADIO_TOP_TEST__LDO_ATB_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define RADIO_TOP_TEST__LDO_ATB_SEL__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field en_rload_top */
/**
 * @defgroup radio_top_regs_core_en_rload_top_field en_rload_top_field
 * @brief macros for field en_rload_top
 * @details Enable load resistor divider and vout/2 voltage for top LDO
 * @{
 */
#define RADIO_TOP_TEST__EN_RLOAD_TOP__SHIFT                                  16
#define RADIO_TOP_TEST__EN_RLOAD_TOP__WIDTH                                   1
#define RADIO_TOP_TEST__EN_RLOAD_TOP__MASK                          0x00010000U
#define RADIO_TOP_TEST__EN_RLOAD_TOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define RADIO_TOP_TEST__EN_RLOAD_TOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define RADIO_TOP_TEST__EN_RLOAD_TOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define RADIO_TOP_TEST__EN_RLOAD_TOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define RADIO_TOP_TEST__EN_RLOAD_TOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define RADIO_TOP_TEST__EN_RLOAD_TOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define RADIO_TOP_TEST__EN_RLOAD_TOP__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field en_rload */
/**
 * @defgroup radio_top_regs_core_en_rload_field en_rload_field
 * @brief macros for field en_rload
 * @details Enable load resistor divider and vout/2 voltages for block LDOs, {RXFE, synthA, synthB, RXBB}
 * @{
 */
#define RADIO_TOP_TEST__EN_RLOAD__SHIFT                                      17
#define RADIO_TOP_TEST__EN_RLOAD__WIDTH                                       4
#define RADIO_TOP_TEST__EN_RLOAD__MASK                              0x001e0000U
#define RADIO_TOP_TEST__EN_RLOAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001e0000U) >> 17)
#define RADIO_TOP_TEST__EN_RLOAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x001e0000U)
#define RADIO_TOP_TEST__EN_RLOAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001e0000U) | (((uint32_t)(src) <<\
                    17) & 0x001e0000U)
#define RADIO_TOP_TEST__EN_RLOAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x001e0000U)))
#define RADIO_TOP_TEST__EN_RLOAD__RESET_VALUE                       0x00000000U
/** @} */
#define RADIO_TOP_TEST__TYPE                                           uint32_t
#define RADIO_TOP_TEST__READ                                        0x001fffffU
#define RADIO_TOP_TEST__WRITE                                       0x001fffffU
#define RADIO_TOP_TEST__PRESERVED                                   0x00000000U
#define RADIO_TOP_TEST__RESET_VALUE                                 0x00000000U

#endif /* __RADIO_TOP_TEST_MACRO__ */

/** @} end of test */

/* macros for BlueprintGlobalNameSpace::radio_top_status */
/**
 * @defgroup radio_top_regs_core_status status
 * @brief Applied mode controls and dig_test_in readback definitions.
 * @{
 */
#ifndef __RADIO_TOP_STATUS_MACRO__
#define __RADIO_TOP_STATUS_MACRO__

/* macros for field synthon */
/**
 * @defgroup radio_top_regs_core_synthon_field synthon_field
 * @brief macros for field synthon
 * @details synthon status
 * @{
 */
#define RADIO_TOP_STATUS__SYNTHON__SHIFT                                      0
#define RADIO_TOP_STATUS__SYNTHON__WIDTH                                      1
#define RADIO_TOP_STATUS__SYNTHON__MASK                             0x00000001U
#define RADIO_TOP_STATUS__SYNTHON__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define RADIO_TOP_STATUS__SYNTHON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_TOP_STATUS__SYNTHON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_TOP_STATUS__SYNTHON__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field txon */
/**
 * @defgroup radio_top_regs_core_txon_field txon_field
 * @brief macros for field txon
 * @details txon status
 * @{
 */
#define RADIO_TOP_STATUS__TXON__SHIFT                                         1
#define RADIO_TOP_STATUS__TXON__WIDTH                                         1
#define RADIO_TOP_STATUS__TXON__MASK                                0x00000002U
#define RADIO_TOP_STATUS__TXON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RADIO_TOP_STATUS__TXON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RADIO_TOP_STATUS__TXON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RADIO_TOP_STATUS__TXON__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field paon */
/**
 * @defgroup radio_top_regs_core_paon_field paon_field
 * @brief macros for field paon
 * @details paon status
 * @{
 */
#define RADIO_TOP_STATUS__PAON__SHIFT                                         2
#define RADIO_TOP_STATUS__PAON__WIDTH                                         1
#define RADIO_TOP_STATUS__PAON__MASK                                0x00000004U
#define RADIO_TOP_STATUS__PAON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RADIO_TOP_STATUS__PAON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RADIO_TOP_STATUS__PAON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RADIO_TOP_STATUS__PAON__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field rxon */
/**
 * @defgroup radio_top_regs_core_rxon_field rxon_field
 * @brief macros for field rxon
 * @details rxon status
 * @{
 */
#define RADIO_TOP_STATUS__RXON__SHIFT                                         3
#define RADIO_TOP_STATUS__RXON__WIDTH                                         1
#define RADIO_TOP_STATUS__RXON__MASK                                0x00000008U
#define RADIO_TOP_STATUS__RXON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RADIO_TOP_STATUS__RXON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RADIO_TOP_STATUS__RXON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RADIO_TOP_STATUS__RXON__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field adcon */
/**
 * @defgroup radio_top_regs_core_adcon_field adcon_field
 * @brief macros for field adcon
 * @details adcon status
 * @{
 */
#define RADIO_TOP_STATUS__ADCON__SHIFT                                        4
#define RADIO_TOP_STATUS__ADCON__WIDTH                                        1
#define RADIO_TOP_STATUS__ADCON__MASK                               0x00000010U
#define RADIO_TOP_STATUS__ADCON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_TOP_STATUS__ADCON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_TOP_STATUS__ADCON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_TOP_STATUS__ADCON__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field adcon_early */
/**
 * @defgroup radio_top_regs_core_adcon_early_field adcon_early_field
 * @brief macros for field adcon_early
 * @details adcon_early status
 * @{
 */
#define RADIO_TOP_STATUS__ADCON_EARLY__SHIFT                                  5
#define RADIO_TOP_STATUS__ADCON_EARLY__WIDTH                                  1
#define RADIO_TOP_STATUS__ADCON_EARLY__MASK                         0x00000020U
#define RADIO_TOP_STATUS__ADCON_EARLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define RADIO_TOP_STATUS__ADCON_EARLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define RADIO_TOP_STATUS__ADCON_EARLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define RADIO_TOP_STATUS__ADCON_EARLY__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field dig_test_in_xtal_stable */
/**
 * @defgroup radio_top_regs_core_dig_test_in_xtal_stable_field dig_test_in_xtal_stable_field
 * @brief macros for field dig_test_in_xtal_stable
 * @details digital test inputs, bit 0 = xtal_stable, bit 1 = tia_peakdet, bit 2 = lna_peakdet, bits 3-6 TBD
 * @{
 */
#define RADIO_TOP_STATUS__DIG_TEST_IN_XTAL_STABLE__SHIFT                      6
#define RADIO_TOP_STATUS__DIG_TEST_IN_XTAL_STABLE__WIDTH                      1
#define RADIO_TOP_STATUS__DIG_TEST_IN_XTAL_STABLE__MASK             0x00000040U
#define RADIO_TOP_STATUS__DIG_TEST_IN_XTAL_STABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define RADIO_TOP_STATUS__DIG_TEST_IN_XTAL_STABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define RADIO_TOP_STATUS__DIG_TEST_IN_XTAL_STABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define RADIO_TOP_STATUS__DIG_TEST_IN_XTAL_STABLE__RESET_VALUE      0x00000000U
/** @} */

/* macros for field dig_test_in_tia_peakdet */
/**
 * @defgroup radio_top_regs_core_dig_test_in_tia_peakdet_field dig_test_in_tia_peakdet_field
 * @brief macros for field dig_test_in_tia_peakdet
 * @details digital test inputs, bit 0 = xtal_stable, bit 1 = tia_peakdet, bit 2 = lna_peakdet, bits 3-6 TBD
 * @{
 */
#define RADIO_TOP_STATUS__DIG_TEST_IN_TIA_PEAKDET__SHIFT                      7
#define RADIO_TOP_STATUS__DIG_TEST_IN_TIA_PEAKDET__WIDTH                      1
#define RADIO_TOP_STATUS__DIG_TEST_IN_TIA_PEAKDET__MASK             0x00000080U
#define RADIO_TOP_STATUS__DIG_TEST_IN_TIA_PEAKDET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define RADIO_TOP_STATUS__DIG_TEST_IN_TIA_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define RADIO_TOP_STATUS__DIG_TEST_IN_TIA_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define RADIO_TOP_STATUS__DIG_TEST_IN_TIA_PEAKDET__RESET_VALUE      0x00000000U
/** @} */

/* macros for field dig_test_in_lna_peakdet */
/**
 * @defgroup radio_top_regs_core_dig_test_in_lna_peakdet_field dig_test_in_lna_peakdet_field
 * @brief macros for field dig_test_in_lna_peakdet
 * @details digital test inputs, bit 0 = xtal_stable, bit 1 = tia_peakdet, bit 2 = lna_peakdet, bits 3-6 TBD
 * @{
 */
#define RADIO_TOP_STATUS__DIG_TEST_IN_LNA_PEAKDET__SHIFT                      8
#define RADIO_TOP_STATUS__DIG_TEST_IN_LNA_PEAKDET__WIDTH                      1
#define RADIO_TOP_STATUS__DIG_TEST_IN_LNA_PEAKDET__MASK             0x00000100U
#define RADIO_TOP_STATUS__DIG_TEST_IN_LNA_PEAKDET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define RADIO_TOP_STATUS__DIG_TEST_IN_LNA_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define RADIO_TOP_STATUS__DIG_TEST_IN_LNA_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define RADIO_TOP_STATUS__DIG_TEST_IN_LNA_PEAKDET__RESET_VALUE      0x00000000U
/** @} */

/* macros for field dig_test_in_TBD */
/**
 * @defgroup radio_top_regs_core_dig_test_in_TBD_field dig_test_in_TBD_field
 * @brief macros for field dig_test_in_TBD
 * @details digital test inputs, bit 0 = xtal_stable, bit 1 = tia_peakdet, bit 2 = lna_peakdet, bits 3-6 TBD
 * @{
 */
#define RADIO_TOP_STATUS__DIG_TEST_IN_TBD__SHIFT                              9
#define RADIO_TOP_STATUS__DIG_TEST_IN_TBD__WIDTH                              4
#define RADIO_TOP_STATUS__DIG_TEST_IN_TBD__MASK                     0x00001e00U
#define RADIO_TOP_STATUS__DIG_TEST_IN_TBD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
#define RADIO_TOP_STATUS__DIG_TEST_IN_TBD__RESET_VALUE              0x00000000U
/** @} */
#define RADIO_TOP_STATUS__TYPE                                         uint32_t
#define RADIO_TOP_STATUS__READ                                      0x00001fffU
#define RADIO_TOP_STATUS__PRESERVED                                 0x00000000U
#define RADIO_TOP_STATUS__RESET_VALUE                               0x00000000U

#endif /* __RADIO_TOP_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::radio_top_version */
/**
 * @defgroup radio_top_regs_core_version version
 * @brief Radio version definitions.
 * @{
 */
#ifndef __RADIO_TOP_VERSION_MACRO__
#define __RADIO_TOP_VERSION_MACRO__

/* macros for field rev_id */
/**
 * @defgroup radio_top_regs_core_rev_id_field rev_id_field
 * @brief macros for field rev_id
 * @details revision ID, upper 4-bits major version, lower 4-bits minor version
 * @{
 */
#define RADIO_TOP_VERSION__REV_ID__SHIFT                                      0
#define RADIO_TOP_VERSION__REV_ID__WIDTH                                      8
#define RADIO_TOP_VERSION__REV_ID__MASK                             0x000000ffU
#define RADIO_TOP_VERSION__REV_ID__READ(src)    ((uint32_t)(src) & 0x000000ffU)
#define RADIO_TOP_VERSION__REV_ID__RESET_VALUE                      0x00000020U
/** @} */

/* macros for field prod_id */
/**
 * @defgroup radio_top_regs_core_prod_id_field prod_id_field
 * @brief macros for field prod_id
 * @details product ID, 3 = perth
 * @{
 */
#define RADIO_TOP_VERSION__PROD_ID__SHIFT                                     8
#define RADIO_TOP_VERSION__PROD_ID__WIDTH                                     8
#define RADIO_TOP_VERSION__PROD_ID__MASK                            0x0000ff00U
#define RADIO_TOP_VERSION__PROD_ID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define RADIO_TOP_VERSION__PROD_ID__RESET_VALUE                     0x00000003U
/** @} */
#define RADIO_TOP_VERSION__TYPE                                        uint32_t
#define RADIO_TOP_VERSION__READ                                     0x0000ffffU
#define RADIO_TOP_VERSION__PRESERVED                                0x00000000U
#define RADIO_TOP_VERSION__RESET_VALUE                              0x00000320U

#endif /* __RADIO_TOP_VERSION_MACRO__ */

/** @} end of version */

/* macros for BlueprintGlobalNameSpace::radio_top_procmon */
/**
 * @defgroup radio_top_regs_core_procmon procmon
 * @brief Process monitor control and settings definitions.
 * @{
 */
#ifndef __RADIO_TOP_PROCMON_MACRO__
#define __RADIO_TOP_PROCMON_MACRO__

/* macros for field ro_cnt_en */
/**
 * @defgroup radio_top_regs_core_ro_cnt_en_field ro_cnt_en_field
 * @brief macros for field ro_cnt_en
 * @details Enable ring oscillator counter
 * @{
 */
#define RADIO_TOP_PROCMON__RO_CNT_EN__SHIFT                                   0
#define RADIO_TOP_PROCMON__RO_CNT_EN__WIDTH                                   1
#define RADIO_TOP_PROCMON__RO_CNT_EN__MASK                          0x00000001U
#define RADIO_TOP_PROCMON__RO_CNT_EN__READ(src) ((uint32_t)(src) & 0x00000001U)
#define RADIO_TOP_PROCMON__RO_CNT_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_TOP_PROCMON__RO_CNT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RADIO_TOP_PROCMON__RO_CNT_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RADIO_TOP_PROCMON__RO_CNT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_TOP_PROCMON__RO_CNT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_TOP_PROCMON__RO_CNT_EN__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field ro_cnt_rst */
/**
 * @defgroup radio_top_regs_core_ro_cnt_rst_field ro_cnt_rst_field
 * @brief macros for field ro_cnt_rst
 * @details Reset ring oscillator counter
 * @{
 */
#define RADIO_TOP_PROCMON__RO_CNT_RST__SHIFT                                  1
#define RADIO_TOP_PROCMON__RO_CNT_RST__WIDTH                                  1
#define RADIO_TOP_PROCMON__RO_CNT_RST__MASK                         0x00000002U
#define RADIO_TOP_PROCMON__RO_CNT_RST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RADIO_TOP_PROCMON__RO_CNT_RST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RADIO_TOP_PROCMON__RO_CNT_RST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RADIO_TOP_PROCMON__RO_CNT_RST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RADIO_TOP_PROCMON__RO_CNT_RST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RADIO_TOP_PROCMON__RO_CNT_RST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RADIO_TOP_PROCMON__RO_CNT_RST__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field ro_sel */
/**
 * @defgroup radio_top_regs_core_ro_sel_field ro_sel_field
 * @brief macros for field ro_sel
 * @details Ring oscillator type select, one-hot, 0: all off, 1: EHVT, 2: SVT, 4: ELVT, 8: GND
 * @{
 */
#define RADIO_TOP_PROCMON__RO_SEL__SHIFT                                      2
#define RADIO_TOP_PROCMON__RO_SEL__WIDTH                                      4
#define RADIO_TOP_PROCMON__RO_SEL__MASK                             0x0000003cU
#define RADIO_TOP_PROCMON__RO_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000003cU) >> 2)
#define RADIO_TOP_PROCMON__RO_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000003cU)
#define RADIO_TOP_PROCMON__RO_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003cU) | (((uint32_t)(src) <<\
                    2) & 0x0000003cU)
#define RADIO_TOP_PROCMON__RO_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000003cU)))
#define RADIO_TOP_PROCMON__RO_SEL__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field N_refclk */
/**
 * @defgroup radio_top_regs_core_N_refclk_field N_refclk_field
 * @brief macros for field N_refclk
 * @details Number of refclk cycles to run ring oscillator counter
 * @{
 */
#define RADIO_TOP_PROCMON__N_REFCLK__SHIFT                                    6
#define RADIO_TOP_PROCMON__N_REFCLK__WIDTH                                    4
#define RADIO_TOP_PROCMON__N_REFCLK__MASK                           0x000003c0U
#define RADIO_TOP_PROCMON__N_REFCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define RADIO_TOP_PROCMON__N_REFCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define RADIO_TOP_PROCMON__N_REFCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define RADIO_TOP_PROCMON__N_REFCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define RADIO_TOP_PROCMON__N_REFCLK__RESET_VALUE                    0x00000008U
/** @} */

/* macros for field cosc_en */
/**
 * @defgroup radio_top_regs_core_cosc_en_field cosc_en_field
 * @brief macros for field cosc_en
 * @details Enable C-based oscillator; removed on Paris/Perth
 * @{
 */
#define RADIO_TOP_PROCMON__COSC_EN__SHIFT                                    10
#define RADIO_TOP_PROCMON__COSC_EN__WIDTH                                     1
#define RADIO_TOP_PROCMON__COSC_EN__MASK                            0x00000400U
#define RADIO_TOP_PROCMON__COSC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define RADIO_TOP_PROCMON__COSC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define RADIO_TOP_PROCMON__COSC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define RADIO_TOP_PROCMON__COSC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define RADIO_TOP_PROCMON__COSC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define RADIO_TOP_PROCMON__COSC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define RADIO_TOP_PROCMON__COSC_EN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field rcosc_en */
/**
 * @defgroup radio_top_regs_core_rcosc_en_field rcosc_en_field
 * @brief macros for field rcosc_en
 * @details Enable RC-based oscillator; removed on Paris/Perth
 * @{
 */
#define RADIO_TOP_PROCMON__RCOSC_EN__SHIFT                                   11
#define RADIO_TOP_PROCMON__RCOSC_EN__WIDTH                                    1
#define RADIO_TOP_PROCMON__RCOSC_EN__MASK                           0x00000800U
#define RADIO_TOP_PROCMON__RCOSC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define RADIO_TOP_PROCMON__RCOSC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define RADIO_TOP_PROCMON__RCOSC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define RADIO_TOP_PROCMON__RCOSC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define RADIO_TOP_PROCMON__RCOSC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define RADIO_TOP_PROCMON__RCOSC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define RADIO_TOP_PROCMON__RCOSC_EN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field sel_icchg */
/**
 * @defgroup radio_top_regs_core_sel_icchg_field sel_icchg_field
 * @brief macros for field sel_icchg
 * @details C-based oscillator charging current; removed on Paris/Perth
 * @{
 */
#define RADIO_TOP_PROCMON__SEL_ICCHG__SHIFT                                  12
#define RADIO_TOP_PROCMON__SEL_ICCHG__WIDTH                                   3
#define RADIO_TOP_PROCMON__SEL_ICCHG__MASK                          0x00007000U
#define RADIO_TOP_PROCMON__SEL_ICCHG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define RADIO_TOP_PROCMON__SEL_ICCHG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define RADIO_TOP_PROCMON__SEL_ICCHG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define RADIO_TOP_PROCMON__SEL_ICCHG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define RADIO_TOP_PROCMON__SEL_ICCHG__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field sel_icdisch */
/**
 * @defgroup radio_top_regs_core_sel_icdisch_field sel_icdisch_field
 * @brief macros for field sel_icdisch
 * @details C-based oscillator discharge current; removed on Paris/Perth
 * @{
 */
#define RADIO_TOP_PROCMON__SEL_ICDISCH__SHIFT                                15
#define RADIO_TOP_PROCMON__SEL_ICDISCH__WIDTH                                 3
#define RADIO_TOP_PROCMON__SEL_ICDISCH__MASK                        0x00038000U
#define RADIO_TOP_PROCMON__SEL_ICDISCH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define RADIO_TOP_PROCMON__SEL_ICDISCH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define RADIO_TOP_PROCMON__SEL_ICDISCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define RADIO_TOP_PROCMON__SEL_ICDISCH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
#define RADIO_TOP_PROCMON__SEL_ICDISCH__RESET_VALUE                 0x00000003U
/** @} */

/* macros for field sel_iccomp */
/**
 * @defgroup radio_top_regs_core_sel_iccomp_field sel_iccomp_field
 * @brief macros for field sel_iccomp
 * @details C-based oscillator comparator bias current; removed on Paris/Perth
 * @{
 */
#define RADIO_TOP_PROCMON__SEL_ICCOMP__SHIFT                                 18
#define RADIO_TOP_PROCMON__SEL_ICCOMP__WIDTH                                  3
#define RADIO_TOP_PROCMON__SEL_ICCOMP__MASK                         0x001c0000U
#define RADIO_TOP_PROCMON__SEL_ICCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define RADIO_TOP_PROCMON__SEL_ICCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define RADIO_TOP_PROCMON__SEL_ICCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define RADIO_TOP_PROCMON__SEL_ICCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
#define RADIO_TOP_PROCMON__SEL_ICCOMP__RESET_VALUE                  0x00000003U
/** @} */

/* macros for field pm_spare */
/**
 * @defgroup radio_top_regs_core_pm_spare_field pm_spare_field
 * @brief macros for field pm_spare
 * @details spares
 * @{
 */
#define RADIO_TOP_PROCMON__PM_SPARE__SHIFT                                   21
#define RADIO_TOP_PROCMON__PM_SPARE__WIDTH                                    3
#define RADIO_TOP_PROCMON__PM_SPARE__MASK                           0x00e00000U
#define RADIO_TOP_PROCMON__PM_SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00e00000U) >> 21)
#define RADIO_TOP_PROCMON__PM_SPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00e00000U)
#define RADIO_TOP_PROCMON__PM_SPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00e00000U) | (((uint32_t)(src) <<\
                    21) & 0x00e00000U)
#define RADIO_TOP_PROCMON__PM_SPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00e00000U)))
#define RADIO_TOP_PROCMON__PM_SPARE__RESET_VALUE                    0x00000000U
/** @} */
#define RADIO_TOP_PROCMON__TYPE                                        uint32_t
#define RADIO_TOP_PROCMON__READ                                     0x00ffffffU
#define RADIO_TOP_PROCMON__WRITE                                    0x00ffffffU
#define RADIO_TOP_PROCMON__PRESERVED                                0x00000000U
#define RADIO_TOP_PROCMON__RESET_VALUE                              0x000db206U

#endif /* __RADIO_TOP_PROCMON_MACRO__ */

/** @} end of procmon */

/* macros for BlueprintGlobalNameSpace::radio_top_procmon_result */
/**
 * @defgroup radio_top_regs_core_procmon_result procmon_result
 * @brief Process monitor results definitions.
 * @{
 */
#ifndef __RADIO_TOP_PROCMON_RESULT_MACRO__
#define __RADIO_TOP_PROCMON_RESULT_MACRO__

/* macros for field ro_count */
/**
 * @defgroup radio_top_regs_core_ro_count_field ro_count_field
 * @brief macros for field ro_count
 * @details Ring oscillator counter value
 * @{
 */
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT__SHIFT                             0
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT__WIDTH                            16
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT__MASK                    0x0000ffffU
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ro_count_done */
/**
 * @defgroup radio_top_regs_core_ro_count_done_field ro_count_done_field
 * @brief macros for field ro_count_done
 * @details Indicates ring osc counter is finished
 * @{
 */
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT_DONE__SHIFT                       16
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT_DONE__WIDTH                        1
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT_DONE__MASK               0x00010000U
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT_DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define RADIO_TOP_PROCMON_RESULT__RO_COUNT_DONE__RESET_VALUE        0x00000000U
/** @} */
#define RADIO_TOP_PROCMON_RESULT__TYPE                                 uint32_t
#define RADIO_TOP_PROCMON_RESULT__READ                              0x0001ffffU
#define RADIO_TOP_PROCMON_RESULT__PRESERVED                         0x00000000U
#define RADIO_TOP_PROCMON_RESULT__RESET_VALUE                       0x00000000U

#endif /* __RADIO_TOP_PROCMON_RESULT_MACRO__ */

/** @} end of procmon_result */

/* macros for BlueprintGlobalNameSpace::radio_top_core_id */
/**
 * @defgroup radio_top_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __RADIO_TOP_CORE_ID_MACRO__
#define __RADIO_TOP_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup radio_top_regs_core_id_field id_field
 * @brief macros for field id
 * @details RTOP in ASCII
 * @{
 */
#define RADIO_TOP_CORE_ID__ID__SHIFT                                          0
#define RADIO_TOP_CORE_ID__ID__WIDTH                                         32
#define RADIO_TOP_CORE_ID__ID__MASK                                 0xffffffffU
#define RADIO_TOP_CORE_ID__ID__READ(src)        ((uint32_t)(src) & 0xffffffffU)
#define RADIO_TOP_CORE_ID__ID__RESET_VALUE                          0x52544f50U
/** @} */
#define RADIO_TOP_CORE_ID__TYPE                                        uint32_t
#define RADIO_TOP_CORE_ID__READ                                     0xffffffffU
#define RADIO_TOP_CORE_ID__PRESERVED                                0x00000000U
#define RADIO_TOP_CORE_ID__RESET_VALUE                              0x52544f50U

#endif /* __RADIO_TOP_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of RADIO_TOP_REGS_CORE */
#endif /* __REG_RADIO_TOP_REGS_CORE_H__ */
