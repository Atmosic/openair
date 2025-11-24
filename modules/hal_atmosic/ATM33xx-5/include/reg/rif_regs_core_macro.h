/*                                                                           */
/* File:       rif_regs_core_macro.h                                         */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic rif_regs_core.rdl                  */
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


#ifndef __REG_RIF_REGS_CORE_H__
#define __REG_RIF_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup RIF_REGS_CORE rif_regs_core
 * @ingroup AT_REG
 * @brief rif_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::RIF_bias */
/**
 * @defgroup rif_regs_core_bias bias
 * @brief Bias settings definitions.
 * @{
 */
#ifndef __RIF_BIAS_MACRO__
#define __RIF_BIAS_MACRO__

/* macros for field rbias */
/**
 * @defgroup rif_regs_core_rbias_field rbias_field
 * @brief macros for field rbias
 * @details RBIAS reference resistor trim
 * @{
 */
#define RIF_BIAS__RBIAS__SHIFT                                                0
#define RIF_BIAS__RBIAS__WIDTH                                                6
#define RIF_BIAS__RBIAS__MASK                                       0x0000003fU
#define RIF_BIAS__RBIAS__READ(src)              ((uint32_t)(src) & 0x0000003fU)
#define RIF_BIAS__RBIAS__WRITE(src)             ((uint32_t)(src) & 0x0000003fU)
#define RIF_BIAS__RBIAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RIF_BIAS__RBIAS__VERIFY(src)      (!(((uint32_t)(src) & ~0x0000003fU)))
#define RIF_BIAS__RBIAS__RESET_VALUE                                0x00000020U
/** @} */

/* macros for field ldo_top_trim */
/**
 * @defgroup rif_regs_core_ldo_top_trim_field ldo_top_trim_field
 * @brief macros for field ldo_top_trim
 * @details Output voltage trim for radio top LDO
 * @{
 */
#define RIF_BIAS__LDO_TOP_TRIM__SHIFT                                         6
#define RIF_BIAS__LDO_TOP_TRIM__WIDTH                                         4
#define RIF_BIAS__LDO_TOP_TRIM__MASK                                0x000003c0U
#define RIF_BIAS__LDO_TOP_TRIM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define RIF_BIAS__LDO_TOP_TRIM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define RIF_BIAS__LDO_TOP_TRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define RIF_BIAS__LDO_TOP_TRIM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define RIF_BIAS__LDO_TOP_TRIM__RESET_VALUE                         0x00000007U
/** @} */

/* macros for field ldo_trim */
/**
 * @defgroup rif_regs_core_ldo_trim_field ldo_trim_field
 * @brief macros for field ldo_trim
 * @details Output voltage trim for radio block LDOs
 * @{
 */
#define RIF_BIAS__LDO_TRIM__SHIFT                                            10
#define RIF_BIAS__LDO_TRIM__WIDTH                                             4
#define RIF_BIAS__LDO_TRIM__MASK                                    0x00003c00U
#define RIF_BIAS__LDO_TRIM__READ(src)   (((uint32_t)(src) & 0x00003c00U) >> 10)
#define RIF_BIAS__LDO_TRIM__WRITE(src)  (((uint32_t)(src) << 10) & 0x00003c00U)
#define RIF_BIAS__LDO_TRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define RIF_BIAS__LDO_TRIM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define RIF_BIAS__LDO_TRIM__RESET_VALUE                             0x00000007U
/** @} */

/* macros for field disable_sel_vddldo */
/**
 * @defgroup rif_regs_core_disable_sel_vddldo_field disable_sel_vddldo_field
 * @brief macros for field disable_sel_vddldo
 * @details Disable switching bandgap supply to LDO output
 * @{
 */
#define RIF_BIAS__DISABLE_SEL_VDDLDO__SHIFT                                  14
#define RIF_BIAS__DISABLE_SEL_VDDLDO__WIDTH                                   1
#define RIF_BIAS__DISABLE_SEL_VDDLDO__MASK                          0x00004000U
#define RIF_BIAS__DISABLE_SEL_VDDLDO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define RIF_BIAS__DISABLE_SEL_VDDLDO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define RIF_BIAS__DISABLE_SEL_VDDLDO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define RIF_BIAS__DISABLE_SEL_VDDLDO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define RIF_BIAS__DISABLE_SEL_VDDLDO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define RIF_BIAS__DISABLE_SEL_VDDLDO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define RIF_BIAS__DISABLE_SEL_VDDLDO__RESET_VALUE                   0x00000000U
/** @} */
#define RIF_BIAS__TYPE                                                 uint32_t
#define RIF_BIAS__READ                                              0x00007fffU
#define RIF_BIAS__WRITE                                             0x00007fffU
#define RIF_BIAS__PRESERVED                                         0x00000000U
#define RIF_BIAS__RESET_VALUE                                       0x00001de0U

#endif /* __RIF_BIAS_MACRO__ */

/** @} end of bias */

/* macros for BlueprintGlobalNameSpace::RIF_rxbbf */
/**
 * @defgroup rif_regs_core_rxbbf rxbbf
 * @brief RXBB filter bandwidth-independent settings definitions.
 * @{
 */
#ifndef __RIF_RXBBF_MACRO__
#define __RIF_RXBBF_MACRO__

/* macros for field tia_rtrim */
/**
 * @defgroup rif_regs_core_tia_rtrim_field tia_rtrim_field
 * @brief macros for field tia_rtrim
 * @details Resistor trim for TIA feedback, sets absolute TIA gain in 1M mode
 * @{
 */
#define RIF_RXBBF__TIA_RTRIM__SHIFT                                           0
#define RIF_RXBBF__TIA_RTRIM__WIDTH                                           4
#define RIF_RXBBF__TIA_RTRIM__MASK                                  0x0000000fU
#define RIF_RXBBF__TIA_RTRIM__READ(src)         ((uint32_t)(src) & 0x0000000fU)
#define RIF_RXBBF__TIA_RTRIM__WRITE(src)        ((uint32_t)(src) & 0x0000000fU)
#define RIF_RXBBF__TIA_RTRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RIF_RXBBF__TIA_RTRIM__VERIFY(src) (!(((uint32_t)(src) & ~0x0000000fU)))
#define RIF_RXBBF__TIA_RTRIM__RESET_VALUE                           0x00000008U
/** @} */

/* macros for field notch_ctune */
/**
 * @defgroup rif_regs_core_notch_ctune_field notch_ctune_field
 * @brief macros for field notch_ctune
 * @details Cap setting for twin-T notch when notch_ctune_ovr = 1, now driven from modem cal
 * @{
 */
#define RIF_RXBBF__NOTCH_CTUNE__SHIFT                                         4
#define RIF_RXBBF__NOTCH_CTUNE__WIDTH                                         6
#define RIF_RXBBF__NOTCH_CTUNE__MASK                                0x000003f0U
#define RIF_RXBBF__NOTCH_CTUNE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003f0U) >> 4)
#define RIF_RXBBF__NOTCH_CTUNE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000003f0U)
#define RIF_RXBBF__NOTCH_CTUNE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003f0U) | (((uint32_t)(src) <<\
                    4) & 0x000003f0U)
#define RIF_RXBBF__NOTCH_CTUNE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000003f0U)))
#define RIF_RXBBF__NOTCH_CTUNE__RESET_VALUE                         0x0000001dU
/** @} */

/* macros for field notch_ctune_ovr */
/**
 * @defgroup rif_regs_core_notch_ctune_ovr_field notch_ctune_ovr_field
 * @brief macros for field notch_ctune_ovr
 * @details Override notch_ctune value from modem
 * @{
 */
#define RIF_RXBBF__NOTCH_CTUNE_OVR__SHIFT                                    10
#define RIF_RXBBF__NOTCH_CTUNE_OVR__WIDTH                                     1
#define RIF_RXBBF__NOTCH_CTUNE_OVR__MASK                            0x00000400U
#define RIF_RXBBF__NOTCH_CTUNE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define RIF_RXBBF__NOTCH_CTUNE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define RIF_RXBBF__NOTCH_CTUNE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define RIF_RXBBF__NOTCH_CTUNE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define RIF_RXBBF__NOTCH_CTUNE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define RIF_RXBBF__NOTCH_CTUNE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define RIF_RXBBF__NOTCH_CTUNE_OVR__RESET_VALUE                     0x00000001U
/** @} */
#define RIF_RXBBF__TYPE                                                uint32_t
#define RIF_RXBBF__READ                                             0x000007ffU
#define RIF_RXBBF__WRITE                                            0x000007ffU
#define RIF_RXBBF__PRESERVED                                        0x00000000U
#define RIF_RXBBF__RESET_VALUE                                      0x000005d8U

#endif /* __RIF_RXBBF_MACRO__ */

/** @} end of rxbbf */

/* macros for BlueprintGlobalNameSpace::RIF_rxbbf_1M */
/**
 * @defgroup rif_regs_core_rxbbf_1M rxbbf_1M
 * @brief RXBB filter settings for 1M definitions.
 * @{
 */
#ifndef __RIF_RXBBF_1M_MACRO__
#define __RIF_RXBBF_1M_MACRO__

/* macros for field pga_ctune */
/**
 * @defgroup rif_regs_core_pga_ctune_field pga_ctune_field
 * @brief macros for field pga_ctune
 * @details Cap setting for PGA feedback in 1M mode
 * @{
 */
#define RIF_RXBBF_1M__PGA_CTUNE__SHIFT                                        0
#define RIF_RXBBF_1M__PGA_CTUNE__WIDTH                                        6
#define RIF_RXBBF_1M__PGA_CTUNE__MASK                               0x0000003fU
#define RIF_RXBBF_1M__PGA_CTUNE__READ(src)      ((uint32_t)(src) & 0x0000003fU)
#define RIF_RXBBF_1M__PGA_CTUNE__WRITE(src)     ((uint32_t)(src) & 0x0000003fU)
#define RIF_RXBBF_1M__PGA_CTUNE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RIF_RXBBF_1M__PGA_CTUNE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define RIF_RXBBF_1M__PGA_CTUNE__RESET_VALUE                        0x0000001fU
/** @} */

/* macros for field pga_ctune_lp */
/**
 * @defgroup rif_regs_core_pga_ctune_lp_field pga_ctune_lp_field
 * @brief macros for field pga_ctune_lp
 * @details Cap setting for PGA feedback in 1M low-power modes
 * @{
 */
#define RIF_RXBBF_1M__PGA_CTUNE_LP__SHIFT                                     6
#define RIF_RXBBF_1M__PGA_CTUNE_LP__WIDTH                                     6
#define RIF_RXBBF_1M__PGA_CTUNE_LP__MASK                            0x00000fc0U
#define RIF_RXBBF_1M__PGA_CTUNE_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define RIF_RXBBF_1M__PGA_CTUNE_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define RIF_RXBBF_1M__PGA_CTUNE_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define RIF_RXBBF_1M__PGA_CTUNE_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define RIF_RXBBF_1M__PGA_CTUNE_LP__RESET_VALUE                     0x00000002U
/** @} */

/* macros for field rcc_rtrim */
/**
 * @defgroup rif_regs_core_rcc_rtrim_field rcc_rtrim_field
 * @brief macros for field rcc_rtrim
 * @details Resistor trim for cross-coupling, sets low-IF frequency in 1M mode
 * @{
 */
#define RIF_RXBBF_1M__RCC_RTRIM__SHIFT                                       12
#define RIF_RXBBF_1M__RCC_RTRIM__WIDTH                                        4
#define RIF_RXBBF_1M__RCC_RTRIM__MASK                               0x0000f000U
#define RIF_RXBBF_1M__RCC_RTRIM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RIF_RXBBF_1M__RCC_RTRIM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RIF_RXBBF_1M__RCC_RTRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RIF_RXBBF_1M__RCC_RTRIM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define RIF_RXBBF_1M__RCC_RTRIM__RESET_VALUE                        0x00000008U
/** @} */

/* macros for field tia_ctune */
/**
 * @defgroup rif_regs_core_tia_ctune_field tia_ctune_field
 * @brief macros for field tia_ctune
 * @details Cap setting for TIA feedback in 1M mode
 * @{
 */
#define RIF_RXBBF_1M__TIA_CTUNE__SHIFT                                       16
#define RIF_RXBBF_1M__TIA_CTUNE__WIDTH                                        7
#define RIF_RXBBF_1M__TIA_CTUNE__MASK                               0x007f0000U
#define RIF_RXBBF_1M__TIA_CTUNE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007f0000U) >> 16)
#define RIF_RXBBF_1M__TIA_CTUNE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x007f0000U)
#define RIF_RXBBF_1M__TIA_CTUNE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007f0000U) | (((uint32_t)(src) <<\
                    16) & 0x007f0000U)
#define RIF_RXBBF_1M__TIA_CTUNE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x007f0000U)))
#define RIF_RXBBF_1M__TIA_CTUNE__RESET_VALUE                        0x0000002aU
/** @} */

/* macros for field tia_ctune_lp */
/**
 * @defgroup rif_regs_core_tia_ctune_lp_field tia_ctune_lp_field
 * @brief macros for field tia_ctune_lp
 * @details Cap setting for TIA feedback in 1M low-power modes
 * @{
 */
#define RIF_RXBBF_1M__TIA_CTUNE_LP__SHIFT                                    23
#define RIF_RXBBF_1M__TIA_CTUNE_LP__WIDTH                                     7
#define RIF_RXBBF_1M__TIA_CTUNE_LP__MASK                            0x3f800000U
#define RIF_RXBBF_1M__TIA_CTUNE_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f800000U) >> 23)
#define RIF_RXBBF_1M__TIA_CTUNE_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x3f800000U)
#define RIF_RXBBF_1M__TIA_CTUNE_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f800000U) | (((uint32_t)(src) <<\
                    23) & 0x3f800000U)
#define RIF_RXBBF_1M__TIA_CTUNE_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x3f800000U)))
#define RIF_RXBBF_1M__TIA_CTUNE_LP__RESET_VALUE                     0x00000004U
/** @} */
#define RIF_RXBBF_1M__TYPE                                             uint32_t
#define RIF_RXBBF_1M__READ                                          0x3fffffffU
#define RIF_RXBBF_1M__WRITE                                         0x3fffffffU
#define RIF_RXBBF_1M__PRESERVED                                     0x00000000U
#define RIF_RXBBF_1M__RESET_VALUE                                   0x022a809fU

#endif /* __RIF_RXBBF_1M_MACRO__ */

/** @} end of rxbbf_1M */

/* macros for BlueprintGlobalNameSpace::RIF_rxbbf_2M */
/**
 * @defgroup rif_regs_core_rxbbf_2M rxbbf_2M
 * @brief RXBB filter settings for 2M definitions.
 * @{
 */
#ifndef __RIF_RXBBF_2M_MACRO__
#define __RIF_RXBBF_2M_MACRO__

/* macros for field pga_ctune */
/**
 * @defgroup rif_regs_core_pga_ctune_field pga_ctune_field
 * @brief macros for field pga_ctune
 * @details Cap setting for PGA feedback in 2M mode
 * @{
 */
#define RIF_RXBBF_2M__PGA_CTUNE__SHIFT                                        0
#define RIF_RXBBF_2M__PGA_CTUNE__WIDTH                                        6
#define RIF_RXBBF_2M__PGA_CTUNE__MASK                               0x0000003fU
#define RIF_RXBBF_2M__PGA_CTUNE__READ(src)      ((uint32_t)(src) & 0x0000003fU)
#define RIF_RXBBF_2M__PGA_CTUNE__WRITE(src)     ((uint32_t)(src) & 0x0000003fU)
#define RIF_RXBBF_2M__PGA_CTUNE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RIF_RXBBF_2M__PGA_CTUNE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define RIF_RXBBF_2M__PGA_CTUNE__RESET_VALUE                        0x00000010U
/** @} */

/* macros for field pga_ctune_lp */
/**
 * @defgroup rif_regs_core_pga_ctune_lp_field pga_ctune_lp_field
 * @brief macros for field pga_ctune_lp
 * @details Cap setting for PGA feedback in 2M mode low-power modes
 * @{
 */
#define RIF_RXBBF_2M__PGA_CTUNE_LP__SHIFT                                     6
#define RIF_RXBBF_2M__PGA_CTUNE_LP__WIDTH                                     6
#define RIF_RXBBF_2M__PGA_CTUNE_LP__MASK                            0x00000fc0U
#define RIF_RXBBF_2M__PGA_CTUNE_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define RIF_RXBBF_2M__PGA_CTUNE_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define RIF_RXBBF_2M__PGA_CTUNE_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define RIF_RXBBF_2M__PGA_CTUNE_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define RIF_RXBBF_2M__PGA_CTUNE_LP__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field rcc_rtrim */
/**
 * @defgroup rif_regs_core_rcc_rtrim_field rcc_rtrim_field
 * @brief macros for field rcc_rtrim
 * @details Resistor trim for cross-coupling, sets low-IF frequency in 2M mode
 * @{
 */
#define RIF_RXBBF_2M__RCC_RTRIM__SHIFT                                       12
#define RIF_RXBBF_2M__RCC_RTRIM__WIDTH                                        4
#define RIF_RXBBF_2M__RCC_RTRIM__MASK                               0x0000f000U
#define RIF_RXBBF_2M__RCC_RTRIM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RIF_RXBBF_2M__RCC_RTRIM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RIF_RXBBF_2M__RCC_RTRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RIF_RXBBF_2M__RCC_RTRIM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define RIF_RXBBF_2M__RCC_RTRIM__RESET_VALUE                        0x00000008U
/** @} */

/* macros for field tia_ctune */
/**
 * @defgroup rif_regs_core_tia_ctune_field tia_ctune_field
 * @brief macros for field tia_ctune
 * @details Cap setting for TIA feedback in 2M mode
 * @{
 */
#define RIF_RXBBF_2M__TIA_CTUNE__SHIFT                                       16
#define RIF_RXBBF_2M__TIA_CTUNE__WIDTH                                        7
#define RIF_RXBBF_2M__TIA_CTUNE__MASK                               0x007f0000U
#define RIF_RXBBF_2M__TIA_CTUNE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007f0000U) >> 16)
#define RIF_RXBBF_2M__TIA_CTUNE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x007f0000U)
#define RIF_RXBBF_2M__TIA_CTUNE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007f0000U) | (((uint32_t)(src) <<\
                    16) & 0x007f0000U)
#define RIF_RXBBF_2M__TIA_CTUNE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x007f0000U)))
#define RIF_RXBBF_2M__TIA_CTUNE__RESET_VALUE                        0x00000015U
/** @} */

/* macros for field tia_ctune_lp */
/**
 * @defgroup rif_regs_core_tia_ctune_lp_field tia_ctune_lp_field
 * @brief macros for field tia_ctune_lp
 * @details Cap setting for TIA feedback in 2M low-power modes
 * @{
 */
#define RIF_RXBBF_2M__TIA_CTUNE_LP__SHIFT                                    23
#define RIF_RXBBF_2M__TIA_CTUNE_LP__WIDTH                                     7
#define RIF_RXBBF_2M__TIA_CTUNE_LP__MASK                            0x3f800000U
#define RIF_RXBBF_2M__TIA_CTUNE_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f800000U) >> 23)
#define RIF_RXBBF_2M__TIA_CTUNE_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x3f800000U)
#define RIF_RXBBF_2M__TIA_CTUNE_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f800000U) | (((uint32_t)(src) <<\
                    23) & 0x3f800000U)
#define RIF_RXBBF_2M__TIA_CTUNE_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x3f800000U)))
#define RIF_RXBBF_2M__TIA_CTUNE_LP__RESET_VALUE                     0x00000002U
/** @} */
#define RIF_RXBBF_2M__TYPE                                             uint32_t
#define RIF_RXBBF_2M__READ                                          0x3fffffffU
#define RIF_RXBBF_2M__WRITE                                         0x3fffffffU
#define RIF_RXBBF_2M__PRESERVED                                     0x00000000U
#define RIF_RXBBF_2M__RESET_VALUE                                   0x01158050U

#endif /* __RIF_RXBBF_2M_MACRO__ */

/** @} end of rxbbf_2M */

/* macros for BlueprintGlobalNameSpace::RIF_syntx_modgain */
/**
 * @defgroup rif_regs_core_syntx_modgain syntx_modgain
 * @brief Synth TX modgain calibration values definitions.
 * @{
 */
#ifndef __RIF_SYNTX_MODGAIN_MACRO__
#define __RIF_SYNTX_MODGAIN_MACRO__

/* macros for field txmodGain */
/**
 * @defgroup rif_regs_core_txmodGain_field txmodGain_field
 * @brief macros for field txmodGain
 * @details Sets full-scale gain of the high frequency modulation path in 1Mbps mode
 * @{
 */
#define RIF_SYNTX_MODGAIN__TXMODGAIN__SHIFT                                   0
#define RIF_SYNTX_MODGAIN__TXMODGAIN__WIDTH                                   5
#define RIF_SYNTX_MODGAIN__TXMODGAIN__MASK                          0x0000001fU
#define RIF_SYNTX_MODGAIN__TXMODGAIN__READ(src) ((uint32_t)(src) & 0x0000001fU)
#define RIF_SYNTX_MODGAIN__TXMODGAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define RIF_SYNTX_MODGAIN__TXMODGAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define RIF_SYNTX_MODGAIN__TXMODGAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define RIF_SYNTX_MODGAIN__TXMODGAIN__RESET_VALUE                   0x0000000fU
/** @} */
#define RIF_SYNTX_MODGAIN__TYPE                                        uint32_t
#define RIF_SYNTX_MODGAIN__READ                                     0x0000001fU
#define RIF_SYNTX_MODGAIN__WRITE                                    0x0000001fU
#define RIF_SYNTX_MODGAIN__PRESERVED                                0x00000000U
#define RIF_SYNTX_MODGAIN__RESET_VALUE                              0x0000000fU

#endif /* __RIF_SYNTX_MODGAIN_MACRO__ */

/** @} end of syntx_modgain */

/* macros for BlueprintGlobalNameSpace::RIF_syntx_vcocap */
/**
 * @defgroup rif_regs_core_syntx_vcocap syntx_vcocap
 * @brief Synth vcocap calibration values definitions.
 * @{
 */
#ifndef __RIF_SYNTX_VCOCAP_MACRO__
#define __RIF_SYNTX_VCOCAP_MACRO__

/* macros for field vcoCapsCoarse_tx */
/**
 * @defgroup rif_regs_core_vcoCapsCoarse_tx_field vcoCapsCoarse_tx_field
 * @brief macros for field vcoCapsCoarse_tx
 * @details VCO coarse cap setting that covers at least 2480MHz in TX mode
 * @{
 */
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__SHIFT                             0
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__WIDTH                             3
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__MASK                    0x00000007U
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_TX__RESET_VALUE             0x00000005U
/** @} */

/* macros for field vcoCapsCoarse_rx */
/**
 * @defgroup rif_regs_core_vcoCapsCoarse_rx_field vcoCapsCoarse_rx_field
 * @brief macros for field vcoCapsCoarse_rx
 * @details VCO coarse cap setting that covers at least 2835MHz (2480MHz RF) in RX mode
 * @{
 */
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__SHIFT                             3
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__WIDTH                             3
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__MASK                    0x00000038U
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define RIF_SYNTX_VCOCAP__VCOCAPSCOARSE_RX__RESET_VALUE             0x00000001U
/** @} */

/* macros for field vcoCapsB1_tx */
/**
 * @defgroup rif_regs_core_vcoCapsB1_tx_field vcoCapsB1_tx_field
 * @brief macros for field vcoCapsB1_tx
 * @details MSBs of vcocap setting that covers high end 2480MHz in TX mode
 * @{
 */
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__SHIFT                                 6
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__WIDTH                                 4
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__MASK                        0x000003c0U
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_TX__RESET_VALUE                 0x00000003U
/** @} */

/* macros for field vcoCapsB1_rx */
/**
 * @defgroup rif_regs_core_vcoCapsB1_rx_field vcoCapsB1_rx_field
 * @brief macros for field vcoCapsB1_rx
 * @details MSBs of vcocap setting that covers high end 2835MHz (2480MHz RF) in RX mode
 * @{
 */
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__SHIFT                                10
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__WIDTH                                 4
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__MASK                        0x00003c00U
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003c00U) >> 10)
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define RIF_SYNTX_VCOCAP__VCOCAPSB1_RX__RESET_VALUE                 0x00000003U
/** @} */

/* macros for field vcoCapsB0_tx */
/**
 * @defgroup rif_regs_core_vcoCapsB0_tx_field vcoCapsB0_tx_field
 * @brief macros for field vcoCapsB0_tx
 * @details MSBs of vcocap setting that covers low end 2400MHz in TX mode
 * @{
 */
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__SHIFT                                14
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__WIDTH                                 4
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__MASK                        0x0003c000U
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003c000U) >> 14)
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0003c000U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003c000U) | (((uint32_t)(src) <<\
                    14) & 0x0003c000U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0003c000U)))
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_TX__RESET_VALUE                 0x00000008U
/** @} */

/* macros for field vcoCapsB0_rx */
/**
 * @defgroup rif_regs_core_vcoCapsB0_rx_field vcoCapsB0_rx_field
 * @brief macros for field vcoCapsB0_rx
 * @details MSBs of vcocap setting that covers low end 2742MHz (2400MHz RF) in RX mode
 * @{
 */
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__SHIFT                                18
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__WIDTH                                 4
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__MASK                        0x003c0000U
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003c0000U) >> 18)
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x003c0000U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003c0000U) | (((uint32_t)(src) <<\
                    18) & 0x003c0000U)
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x003c0000U)))
#define RIF_SYNTX_VCOCAP__VCOCAPSB0_RX__RESET_VALUE                 0x00000008U
/** @} */
#define RIF_SYNTX_VCOCAP__TYPE                                         uint32_t
#define RIF_SYNTX_VCOCAP__READ                                      0x003fffffU
#define RIF_SYNTX_VCOCAP__WRITE                                     0x003fffffU
#define RIF_SYNTX_VCOCAP__PRESERVED                                 0x00000000U
#define RIF_SYNTX_VCOCAP__RESET_VALUE                               0x00220ccdU

#endif /* __RIF_SYNTX_VCOCAP_MACRO__ */

/** @} end of syntx_vcocap */

/* macros for BlueprintGlobalNameSpace::RIF_lna */
/**
 * @defgroup rif_regs_core_lna lna
 * @brief LNA step size from ATE cal definitions.
 * @{
 */
#ifndef __RIF_LNA_MACRO__
#define __RIF_LNA_MACRO__

/* macros for field step1 */
/**
 * @defgroup rif_regs_core_step1_field step1_field
 * @brief macros for field step1
 * @details Step size in dB from lnagain = 0 to minimum lnagain setting used other than 0 or 1
 * @{
 */
#define RIF_LNA__STEP1__SHIFT                                                 0
#define RIF_LNA__STEP1__WIDTH                                                 7
#define RIF_LNA__STEP1__MASK                                        0x0000007fU
#define RIF_LNA__STEP1__READ(src)               ((uint32_t)(src) & 0x0000007fU)
#define RIF_LNA__STEP1__WRITE(src)              ((uint32_t)(src) & 0x0000007fU)
#define RIF_LNA__STEP1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define RIF_LNA__STEP1__VERIFY(src)       (!(((uint32_t)(src) & ~0x0000007fU)))
#define RIF_LNA__STEP1__RESET_VALUE                                 0x00000016U
/** @} */

/* macros for field step2 */
/**
 * @defgroup rif_regs_core_step2_field step2_field
 * @brief macros for field step2
 * @details Step size in dB from lnagain = 1 to minimum lnagain setting used other than 0 or 1
 * @{
 */
#define RIF_LNA__STEP2__SHIFT                                                 7
#define RIF_LNA__STEP2__WIDTH                                                 7
#define RIF_LNA__STEP2__MASK                                        0x00003f80U
#define RIF_LNA__STEP2__READ(src)        (((uint32_t)(src) & 0x00003f80U) >> 7)
#define RIF_LNA__STEP2__WRITE(src)       (((uint32_t)(src) << 7) & 0x00003f80U)
#define RIF_LNA__STEP2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define RIF_LNA__STEP2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define RIF_LNA__STEP2__RESET_VALUE                                 0x00000011U
/** @} */
#define RIF_LNA__TYPE                                                  uint32_t
#define RIF_LNA__READ                                               0x00003fffU
#define RIF_LNA__WRITE                                              0x00003fffU
#define RIF_LNA__PRESERVED                                          0x00000000U
#define RIF_LNA__RESET_VALUE                                        0x00000896U

#endif /* __RIF_LNA_MACRO__ */

/** @} end of lna */

/* macros for BlueprintGlobalNameSpace::RIF_rgt */
/**
 * @defgroup rif_regs_core_rgt rgt
 * @brief Reduced Gain Table control definitions.
 * @{
 */
#ifndef __RIF_RGT_MACRO__
#define __RIF_RGT_MACRO__

/* macros for field use_lna_reduced_gain_table */
/**
 * @defgroup rif_regs_core_use_lna_reduced_gain_table_field use_lna_reduced_gain_table_field
 * @brief macros for field use_lna_reduced_gain_table
 * @{
 */
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__SHIFT                            0
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__WIDTH                            1
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__MASK                   0x00000001U
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RIF_RGT__USE_LNA_REDUCED_GAIN_TABLE__RESET_VALUE            0x00000001U
/** @} */

/* macros for field lna0_thresh */
/**
 * @defgroup rif_regs_core_lna0_thresh_field lna0_thresh_field
 * @brief macros for field lna0_thresh
 * @details RX gain index to switch between lnagain=0 and lnagain=1
 * @{
 */
#define RIF_RGT__LNA0_THRESH__SHIFT                                           1
#define RIF_RGT__LNA0_THRESH__WIDTH                                           7
#define RIF_RGT__LNA0_THRESH__MASK                                  0x000000feU
#define RIF_RGT__LNA0_THRESH__READ(src)  (((uint32_t)(src) & 0x000000feU) >> 1)
#define RIF_RGT__LNA0_THRESH__WRITE(src) (((uint32_t)(src) << 1) & 0x000000feU)
#define RIF_RGT__LNA0_THRESH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000feU) | (((uint32_t)(src) <<\
                    1) & 0x000000feU)
#define RIF_RGT__LNA0_THRESH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000000feU)))
#define RIF_RGT__LNA0_THRESH__RESET_VALUE                           0x0000000aU
/** @} */

/* macros for field lna1_thresh */
/**
 * @defgroup rif_regs_core_lna1_thresh_field lna1_thresh_field
 * @brief macros for field lna1_thresh
 * @details RX gain index to switch between lnagain=1 and which ever is chosen as the next highest lnagain setting
 * @{
 */
#define RIF_RGT__LNA1_THRESH__SHIFT                                           8
#define RIF_RGT__LNA1_THRESH__WIDTH                                           7
#define RIF_RGT__LNA1_THRESH__MASK                                  0x00007f00U
#define RIF_RGT__LNA1_THRESH__READ(src)  (((uint32_t)(src) & 0x00007f00U) >> 8)
#define RIF_RGT__LNA1_THRESH__WRITE(src) (((uint32_t)(src) << 8) & 0x00007f00U)
#define RIF_RGT__LNA1_THRESH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007f00U) | (((uint32_t)(src) <<\
                    8) & 0x00007f00U)
#define RIF_RGT__LNA1_THRESH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00007f00U)))
#define RIF_RGT__LNA1_THRESH__RESET_VALUE                           0x00000014U
/** @} */

/* macros for field lna_step_offset */
/**
 * @defgroup rif_regs_core_lna_step_offset_field lna_step_offset_field
 * @brief macros for field lna_step_offset
 * @details Signed. Offset to apply to lna_step1/2 (which come from ATE) depending on minimum lnagain setting used that is not 0 or 1
 * @{
 */
#define RIF_RGT__LNA_STEP_OFFSET__SHIFT                                      15
#define RIF_RGT__LNA_STEP_OFFSET__WIDTH                                       7
#define RIF_RGT__LNA_STEP_OFFSET__MASK                              0x003f8000U
#define RIF_RGT__LNA_STEP_OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f8000U) >> 15)
#define RIF_RGT__LNA_STEP_OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x003f8000U)
#define RIF_RGT__LNA_STEP_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f8000U) | (((uint32_t)(src) <<\
                    15) & 0x003f8000U)
#define RIF_RGT__LNA_STEP_OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x003f8000U)))
#define RIF_RGT__LNA_STEP_OFFSET__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field xlna_step */
/**
 * @defgroup rif_regs_core_xlna_step_field xlna_step_field
 * @brief macros for field xlna_step
 * @details Change in signal size between XLNA on and off, in dB
 * @{
 */
#define RIF_RGT__XLNA_STEP__SHIFT                                            22
#define RIF_RGT__XLNA_STEP__WIDTH                                             6
#define RIF_RGT__XLNA_STEP__MASK                                    0x0fc00000U
#define RIF_RGT__XLNA_STEP__READ(src)   (((uint32_t)(src) & 0x0fc00000U) >> 22)
#define RIF_RGT__XLNA_STEP__WRITE(src)  (((uint32_t)(src) << 22) & 0x0fc00000U)
#define RIF_RGT__XLNA_STEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fc00000U) | (((uint32_t)(src) <<\
                    22) & 0x0fc00000U)
#define RIF_RGT__XLNA_STEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x0fc00000U)))
#define RIF_RGT__XLNA_STEP__RESET_VALUE                             0x00000014U
/** @} */
#define RIF_RGT__TYPE                                                  uint32_t
#define RIF_RGT__READ                                               0x0fffffffU
#define RIF_RGT__WRITE                                              0x0fffffffU
#define RIF_RGT__PRESERVED                                          0x00000000U
#define RIF_RGT__RESET_VALUE                                        0x05001415U

#endif /* __RIF_RGT_MACRO__ */

/** @} end of rgt */

/* macros for BlueprintGlobalNameSpace::RIF_rgthw */
/**
 * @defgroup rif_regs_core_rgthw rgthw
 * @brief Reduced Gain Table HW-only registers for register management definitions.
 * @{
 */
#ifndef __RIF_RGTHW_MACRO__
#define __RIF_RGTHW_MACRO__

/* macros for field bb_table_offset */
/**
 * @defgroup rif_regs_core_bb_table_offset_field bb_table_offset_field
 * @brief macros for field bb_table_offset
 * @details RX gain index offset of bb-only table with respect to variable-LNA setting table.
 * @{
 */
#define RIF_RGTHW__BB_TABLE_OFFSET__SHIFT                                     0
#define RIF_RGTHW__BB_TABLE_OFFSET__WIDTH                                     7
#define RIF_RGTHW__BB_TABLE_OFFSET__MASK                            0x0000007fU
#define RIF_RGTHW__BB_TABLE_OFFSET__READ(src)   ((uint32_t)(src) & 0x0000007fU)
#define RIF_RGTHW__BB_TABLE_OFFSET__WRITE(src)  ((uint32_t)(src) & 0x0000007fU)
#define RIF_RGTHW__BB_TABLE_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define RIF_RGTHW__BB_TABLE_OFFSET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define RIF_RGTHW__BB_TABLE_OFFSET__RESET_VALUE                     0x0000003cU
/** @} */

/* macros for field max_bb_index */
/**
 * @defgroup rif_regs_core_max_bb_index_field max_bb_index_field
 * @brief macros for field max_bb_index
 * @details Maximum allowed index for bb-only table, relative to its base
 * @{
 */
#define RIF_RGTHW__MAX_BB_INDEX__SHIFT                                        7
#define RIF_RGTHW__MAX_BB_INDEX__WIDTH                                        7
#define RIF_RGTHW__MAX_BB_INDEX__MASK                               0x00003f80U
#define RIF_RGTHW__MAX_BB_INDEX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define RIF_RGTHW__MAX_BB_INDEX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define RIF_RGTHW__MAX_BB_INDEX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define RIF_RGTHW__MAX_BB_INDEX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define RIF_RGTHW__MAX_BB_INDEX__RESET_VALUE                        0x0000001eU
/** @} */

/* macros for field max_rgt_index */
/**
 * @defgroup rif_regs_core_max_rgt_index_field max_rgt_index_field
 * @brief macros for field max_rgt_index
 * @details Maximum allowed index for reduced gain table, for portion that includes LNA
 * @{
 */
#define RIF_RGTHW__MAX_RGT_INDEX__SHIFT                                      14
#define RIF_RGTHW__MAX_RGT_INDEX__WIDTH                                       7
#define RIF_RGTHW__MAX_RGT_INDEX__MASK                              0x001fc000U
#define RIF_RGTHW__MAX_RGT_INDEX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define RIF_RGTHW__MAX_RGT_INDEX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define RIF_RGTHW__MAX_RGT_INDEX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define RIF_RGTHW__MAX_RGT_INDEX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define RIF_RGTHW__MAX_RGT_INDEX__RESET_VALUE                       0x00000036U
/** @} */
#define RIF_RGTHW__TYPE                                                uint32_t
#define RIF_RGTHW__READ                                             0x001fffffU
#define RIF_RGTHW__WRITE                                            0x001fffffU
#define RIF_RGTHW__PRESERVED                                        0x00000000U
#define RIF_RGTHW__RESET_VALUE                                      0x000d8f3cU

#endif /* __RIF_RGTHW_MACRO__ */

/** @} end of rgthw */

/* macros for BlueprintGlobalNameSpace::RIF_txgain0 */
/**
 * @defgroup rif_regs_core_txgain0 txgain0
 * @brief TX power table entries 0 to 2, maps to pa_stages[2:0], pa_ref[5:0] definitions.
 * @{
 */
#ifndef __RIF_TXGAIN0_MACRO__
#define __RIF_TXGAIN0_MACRO__

/* macros for field entry0 */
/**
 * @defgroup rif_regs_core_entry0_field entry0_field
 * @brief macros for field entry0
 * @details TX power level entry 0, -20dBm
 * @{
 */
#define RIF_TXGAIN0__ENTRY0__SHIFT                                            0
#define RIF_TXGAIN0__ENTRY0__WIDTH                                            9
#define RIF_TXGAIN0__ENTRY0__MASK                                   0x000001ffU
#define RIF_TXGAIN0__ENTRY0__READ(src)          ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN0__ENTRY0__WRITE(src)         ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN0__ENTRY0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RIF_TXGAIN0__ENTRY0__VERIFY(src)  (!(((uint32_t)(src) & ~0x000001ffU)))
#define RIF_TXGAIN0__ENTRY0__RESET_VALUE                            0x00000010U
/** @} */

/* macros for field entry1 */
/**
 * @defgroup rif_regs_core_entry1_field entry1_field
 * @brief macros for field entry1
 * @details TX power level entry 1, -10dBm
 * @{
 */
#define RIF_TXGAIN0__ENTRY1__SHIFT                                            9
#define RIF_TXGAIN0__ENTRY1__WIDTH                                            9
#define RIF_TXGAIN0__ENTRY1__MASK                                   0x0003fe00U
#define RIF_TXGAIN0__ENTRY1__READ(src)   (((uint32_t)(src) & 0x0003fe00U) >> 9)
#define RIF_TXGAIN0__ENTRY1__WRITE(src)  (((uint32_t)(src) << 9) & 0x0003fe00U)
#define RIF_TXGAIN0__ENTRY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define RIF_TXGAIN0__ENTRY1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))
#define RIF_TXGAIN0__ENTRY1__RESET_VALUE                            0x00000027U
/** @} */

/* macros for field entry2 */
/**
 * @defgroup rif_regs_core_entry2_field entry2_field
 * @brief macros for field entry2
 * @details TX power level entry 2, -8dBm
 * @{
 */
#define RIF_TXGAIN0__ENTRY2__SHIFT                                           18
#define RIF_TXGAIN0__ENTRY2__WIDTH                                            9
#define RIF_TXGAIN0__ENTRY2__MASK                                   0x07fc0000U
#define RIF_TXGAIN0__ENTRY2__READ(src)  (((uint32_t)(src) & 0x07fc0000U) >> 18)
#define RIF_TXGAIN0__ENTRY2__WRITE(src) (((uint32_t)(src) << 18) & 0x07fc0000U)
#define RIF_TXGAIN0__ENTRY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define RIF_TXGAIN0__ENTRY2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define RIF_TXGAIN0__ENTRY2__RESET_VALUE                            0x00000030U
/** @} */

/* macros for field pa_supconf0 */
/**
 * @defgroup rif_regs_core_pa_supconf0_field pa_supconf0_field
 * @brief macros for field pa_supconf0
 * @details PA input supply configuration, 00: VDDPA passthrough with NMOS1 and PMOS, 01: AVDD with NMOS0, 10: VDDPA with NMOS1, 11: VDDPA with PMOS
 * @{
 */
#define RIF_TXGAIN0__PA_SUPCONF0__SHIFT                                      27
#define RIF_TXGAIN0__PA_SUPCONF0__WIDTH                                       2
#define RIF_TXGAIN0__PA_SUPCONF0__MASK                              0x18000000U
#define RIF_TXGAIN0__PA_SUPCONF0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x18000000U) >> 27)
#define RIF_TXGAIN0__PA_SUPCONF0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x18000000U)
#define RIF_TXGAIN0__PA_SUPCONF0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x18000000U) | (((uint32_t)(src) <<\
                    27) & 0x18000000U)
#define RIF_TXGAIN0__PA_SUPCONF0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x18000000U)))
#define RIF_TXGAIN0__PA_SUPCONF0__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field pa_refconf0 */
/**
 * @defgroup rif_regs_core_pa_refconf0_field pa_refconf0_field
 * @brief macros for field pa_refconf0
 * @details PA LDO reference configuration max voltage, 00: AVDD, 01: VDDPA, 10: IR 1.0V, 11: IR 1.8V
 * @{
 */
#define RIF_TXGAIN0__PA_REFCONF0__SHIFT                                      29
#define RIF_TXGAIN0__PA_REFCONF0__WIDTH                                       2
#define RIF_TXGAIN0__PA_REFCONF0__MASK                              0x60000000U
#define RIF_TXGAIN0__PA_REFCONF0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x60000000U) >> 29)
#define RIF_TXGAIN0__PA_REFCONF0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x60000000U)
#define RIF_TXGAIN0__PA_REFCONF0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x60000000U) | (((uint32_t)(src) <<\
                    29) & 0x60000000U)
#define RIF_TXGAIN0__PA_REFCONF0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x60000000U)))
#define RIF_TXGAIN0__PA_REFCONF0__RESET_VALUE                       0x00000000U
/** @} */
#define RIF_TXGAIN0__TYPE                                              uint32_t
#define RIF_TXGAIN0__READ                                           0x7fffffffU
#define RIF_TXGAIN0__WRITE                                          0x7fffffffU
#define RIF_TXGAIN0__PRESERVED                                      0x00000000U
#define RIF_TXGAIN0__RESET_VALUE                                    0x08c04e10U

#endif /* __RIF_TXGAIN0_MACRO__ */

/** @} end of txgain0 */

/* macros for BlueprintGlobalNameSpace::RIF_txgain1 */
/**
 * @defgroup rif_regs_core_txgain1 txgain1
 * @brief TX power table entries 3 to 5, maps to pa_stages[2:0], pa_ref[5:0] definitions.
 * @{
 */
#ifndef __RIF_TXGAIN1_MACRO__
#define __RIF_TXGAIN1_MACRO__

/* macros for field entry3 */
/**
 * @defgroup rif_regs_core_entry3_field entry3_field
 * @brief macros for field entry3
 * @details TX power level entry 3, -6dBm
 * @{
 */
#define RIF_TXGAIN1__ENTRY3__SHIFT                                            0
#define RIF_TXGAIN1__ENTRY3__WIDTH                                            9
#define RIF_TXGAIN1__ENTRY3__MASK                                   0x000001ffU
#define RIF_TXGAIN1__ENTRY3__READ(src)          ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN1__ENTRY3__WRITE(src)         ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN1__ENTRY3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RIF_TXGAIN1__ENTRY3__VERIFY(src)  (!(((uint32_t)(src) & ~0x000001ffU)))
#define RIF_TXGAIN1__ENTRY3__RESET_VALUE                            0x00000067U
/** @} */

/* macros for field entry4 */
/**
 * @defgroup rif_regs_core_entry4_field entry4_field
 * @brief macros for field entry4
 * @details TX power level entry 4, -4dBm
 * @{
 */
#define RIF_TXGAIN1__ENTRY4__SHIFT                                            9
#define RIF_TXGAIN1__ENTRY4__WIDTH                                            9
#define RIF_TXGAIN1__ENTRY4__MASK                                   0x0003fe00U
#define RIF_TXGAIN1__ENTRY4__READ(src)   (((uint32_t)(src) & 0x0003fe00U) >> 9)
#define RIF_TXGAIN1__ENTRY4__WRITE(src)  (((uint32_t)(src) << 9) & 0x0003fe00U)
#define RIF_TXGAIN1__ENTRY4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define RIF_TXGAIN1__ENTRY4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))
#define RIF_TXGAIN1__ENTRY4__RESET_VALUE                            0x0000006eU
/** @} */

/* macros for field entry5 */
/**
 * @defgroup rif_regs_core_entry5_field entry5_field
 * @brief macros for field entry5
 * @details TX power level entry 5, -2dBm
 * @{
 */
#define RIF_TXGAIN1__ENTRY5__SHIFT                                           18
#define RIF_TXGAIN1__ENTRY5__WIDTH                                            9
#define RIF_TXGAIN1__ENTRY5__MASK                                   0x07fc0000U
#define RIF_TXGAIN1__ENTRY5__READ(src)  (((uint32_t)(src) & 0x07fc0000U) >> 18)
#define RIF_TXGAIN1__ENTRY5__WRITE(src) (((uint32_t)(src) << 18) & 0x07fc0000U)
#define RIF_TXGAIN1__ENTRY5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define RIF_TXGAIN1__ENTRY5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define RIF_TXGAIN1__ENTRY5__RESET_VALUE                            0x00000079U
/** @} */

/* macros for field pa_supconf1 */
/**
 * @defgroup rif_regs_core_pa_supconf1_field pa_supconf1_field
 * @brief macros for field pa_supconf1
 * @details PA input supply configuration, 00: VDDPA passthrough with NMOS1 and PMOS, 01: AVDD with NMOS0, 10: VDDPA with NMOS1, 11: VDDPA with PMOS
 * @{
 */
#define RIF_TXGAIN1__PA_SUPCONF1__SHIFT                                      27
#define RIF_TXGAIN1__PA_SUPCONF1__WIDTH                                       2
#define RIF_TXGAIN1__PA_SUPCONF1__MASK                              0x18000000U
#define RIF_TXGAIN1__PA_SUPCONF1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x18000000U) >> 27)
#define RIF_TXGAIN1__PA_SUPCONF1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x18000000U)
#define RIF_TXGAIN1__PA_SUPCONF1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x18000000U) | (((uint32_t)(src) <<\
                    27) & 0x18000000U)
#define RIF_TXGAIN1__PA_SUPCONF1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x18000000U)))
#define RIF_TXGAIN1__PA_SUPCONF1__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field pa_refconf1 */
/**
 * @defgroup rif_regs_core_pa_refconf1_field pa_refconf1_field
 * @brief macros for field pa_refconf1
 * @details PA LDO reference configuration max voltage, 00: AVDD, 01: VDDPA, 10: IR 1.0V, 11: IR 1.8V
 * @{
 */
#define RIF_TXGAIN1__PA_REFCONF1__SHIFT                                      29
#define RIF_TXGAIN1__PA_REFCONF1__WIDTH                                       2
#define RIF_TXGAIN1__PA_REFCONF1__MASK                              0x60000000U
#define RIF_TXGAIN1__PA_REFCONF1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x60000000U) >> 29)
#define RIF_TXGAIN1__PA_REFCONF1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x60000000U)
#define RIF_TXGAIN1__PA_REFCONF1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x60000000U) | (((uint32_t)(src) <<\
                    29) & 0x60000000U)
#define RIF_TXGAIN1__PA_REFCONF1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x60000000U)))
#define RIF_TXGAIN1__PA_REFCONF1__RESET_VALUE                       0x00000000U
/** @} */
#define RIF_TXGAIN1__TYPE                                              uint32_t
#define RIF_TXGAIN1__READ                                           0x7fffffffU
#define RIF_TXGAIN1__WRITE                                          0x7fffffffU
#define RIF_TXGAIN1__PRESERVED                                      0x00000000U
#define RIF_TXGAIN1__RESET_VALUE                                    0x09e4dc67U

#endif /* __RIF_TXGAIN1_MACRO__ */

/** @} end of txgain1 */

/* macros for BlueprintGlobalNameSpace::RIF_txgain2 */
/**
 * @defgroup rif_regs_core_txgain2 txgain2
 * @brief TX power table entries 6 to 8, maps to pa_stages[2:0], pa_ref[5:0] definitions.
 * @{
 */
#ifndef __RIF_TXGAIN2_MACRO__
#define __RIF_TXGAIN2_MACRO__

/* macros for field entry6 */
/**
 * @defgroup rif_regs_core_entry6_field entry6_field
 * @brief macros for field entry6
 * @details TX power level entry 6, 0dBm
 * @{
 */
#define RIF_TXGAIN2__ENTRY6__SHIFT                                            0
#define RIF_TXGAIN2__ENTRY6__WIDTH                                            9
#define RIF_TXGAIN2__ENTRY6__MASK                                   0x000001ffU
#define RIF_TXGAIN2__ENTRY6__READ(src)          ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN2__ENTRY6__WRITE(src)         ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN2__ENTRY6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RIF_TXGAIN2__ENTRY6__VERIFY(src)  (!(((uint32_t)(src) & ~0x000001ffU)))
#define RIF_TXGAIN2__ENTRY6__RESET_VALUE                            0x000000b9U
/** @} */

/* macros for field entry7 */
/**
 * @defgroup rif_regs_core_entry7_field entry7_field
 * @brief macros for field entry7
 * @details TX power level entry 7, 2dBm
 * @{
 */
#define RIF_TXGAIN2__ENTRY7__SHIFT                                            9
#define RIF_TXGAIN2__ENTRY7__WIDTH                                            9
#define RIF_TXGAIN2__ENTRY7__MASK                                   0x0003fe00U
#define RIF_TXGAIN2__ENTRY7__READ(src)   (((uint32_t)(src) & 0x0003fe00U) >> 9)
#define RIF_TXGAIN2__ENTRY7__WRITE(src)  (((uint32_t)(src) << 9) & 0x0003fe00U)
#define RIF_TXGAIN2__ENTRY7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define RIF_TXGAIN2__ENTRY7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))
#define RIF_TXGAIN2__ENTRY7__RESET_VALUE                            0x000000f8U
/** @} */

/* macros for field entry8 */
/**
 * @defgroup rif_regs_core_entry8_field entry8_field
 * @brief macros for field entry8
 * @details TX power level entry 8, 4dBm
 * @{
 */
#define RIF_TXGAIN2__ENTRY8__SHIFT                                           18
#define RIF_TXGAIN2__ENTRY8__WIDTH                                            9
#define RIF_TXGAIN2__ENTRY8__MASK                                   0x07fc0000U
#define RIF_TXGAIN2__ENTRY8__READ(src)  (((uint32_t)(src) & 0x07fc0000U) >> 18)
#define RIF_TXGAIN2__ENTRY8__WRITE(src) (((uint32_t)(src) << 18) & 0x07fc0000U)
#define RIF_TXGAIN2__ENTRY8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define RIF_TXGAIN2__ENTRY8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define RIF_TXGAIN2__ENTRY8__RESET_VALUE                            0x0000013fU
/** @} */

/* macros for field pa_supconf2 */
/**
 * @defgroup rif_regs_core_pa_supconf2_field pa_supconf2_field
 * @brief macros for field pa_supconf2
 * @details PA input supply configuration, 00: VDDPA passthrough with NMOS1 and PMOS, 01: AVDD with NMOS0, 10: VDDPA with NMOS1, 11: VDDPA with PMOS
 * @{
 */
#define RIF_TXGAIN2__PA_SUPCONF2__SHIFT                                      27
#define RIF_TXGAIN2__PA_SUPCONF2__WIDTH                                       2
#define RIF_TXGAIN2__PA_SUPCONF2__MASK                              0x18000000U
#define RIF_TXGAIN2__PA_SUPCONF2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x18000000U) >> 27)
#define RIF_TXGAIN2__PA_SUPCONF2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x18000000U)
#define RIF_TXGAIN2__PA_SUPCONF2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x18000000U) | (((uint32_t)(src) <<\
                    27) & 0x18000000U)
#define RIF_TXGAIN2__PA_SUPCONF2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x18000000U)))
#define RIF_TXGAIN2__PA_SUPCONF2__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field pa_refconf2 */
/**
 * @defgroup rif_regs_core_pa_refconf2_field pa_refconf2_field
 * @brief macros for field pa_refconf2
 * @details PA LDO reference configuration max voltage, 00: AVDD, 01: VDDPA, 10: IR 1.0V, 11: IR 1.8V
 * @{
 */
#define RIF_TXGAIN2__PA_REFCONF2__SHIFT                                      29
#define RIF_TXGAIN2__PA_REFCONF2__WIDTH                                       2
#define RIF_TXGAIN2__PA_REFCONF2__MASK                              0x60000000U
#define RIF_TXGAIN2__PA_REFCONF2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x60000000U) >> 29)
#define RIF_TXGAIN2__PA_REFCONF2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x60000000U)
#define RIF_TXGAIN2__PA_REFCONF2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x60000000U) | (((uint32_t)(src) <<\
                    29) & 0x60000000U)
#define RIF_TXGAIN2__PA_REFCONF2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x60000000U)))
#define RIF_TXGAIN2__PA_REFCONF2__RESET_VALUE                       0x00000000U
/** @} */
#define RIF_TXGAIN2__TYPE                                              uint32_t
#define RIF_TXGAIN2__READ                                           0x7fffffffU
#define RIF_TXGAIN2__WRITE                                          0x7fffffffU
#define RIF_TXGAIN2__PRESERVED                                      0x00000000U
#define RIF_TXGAIN2__RESET_VALUE                                    0x0cfdf0b9U

#endif /* __RIF_TXGAIN2_MACRO__ */

/** @} end of txgain2 */

/* macros for BlueprintGlobalNameSpace::RIF_txgain3 */
/**
 * @defgroup rif_regs_core_txgain3 txgain3
 * @brief TX power table entries 9 to 11, maps to pa_stages[2:0], pa_ref[5:0] definitions.
 * @{
 */
#ifndef __RIF_TXGAIN3_MACRO__
#define __RIF_TXGAIN3_MACRO__

/* macros for field entry9 */
/**
 * @defgroup rif_regs_core_entry9_field entry9_field
 * @brief macros for field entry9
 * @details TX power level entry 9, 6dBm
 * @{
 */
#define RIF_TXGAIN3__ENTRY9__SHIFT                                            0
#define RIF_TXGAIN3__ENTRY9__WIDTH                                            9
#define RIF_TXGAIN3__ENTRY9__MASK                                   0x000001ffU
#define RIF_TXGAIN3__ENTRY9__READ(src)          ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN3__ENTRY9__WRITE(src)         ((uint32_t)(src) & 0x000001ffU)
#define RIF_TXGAIN3__ENTRY9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RIF_TXGAIN3__ENTRY9__VERIFY(src)  (!(((uint32_t)(src) & ~0x000001ffU)))
#define RIF_TXGAIN3__ENTRY9__RESET_VALUE                            0x000001aeU
/** @} */

/* macros for field entry10 */
/**
 * @defgroup rif_regs_core_entry10_field entry10_field
 * @brief macros for field entry10
 * @details TX power level entry 10, 8dBm
 * @{
 */
#define RIF_TXGAIN3__ENTRY10__SHIFT                                           9
#define RIF_TXGAIN3__ENTRY10__WIDTH                                           9
#define RIF_TXGAIN3__ENTRY10__MASK                                  0x0003fe00U
#define RIF_TXGAIN3__ENTRY10__READ(src)  (((uint32_t)(src) & 0x0003fe00U) >> 9)
#define RIF_TXGAIN3__ENTRY10__WRITE(src) (((uint32_t)(src) << 9) & 0x0003fe00U)
#define RIF_TXGAIN3__ENTRY10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define RIF_TXGAIN3__ENTRY10__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))
#define RIF_TXGAIN3__ENTRY10__RESET_VALUE                           0x000001b4U
/** @} */

/* macros for field entry11 */
/**
 * @defgroup rif_regs_core_entry11_field entry11_field
 * @brief macros for field entry11
 * @details TX power level entry 11, extra
 * @{
 */
#define RIF_TXGAIN3__ENTRY11__SHIFT                                          18
#define RIF_TXGAIN3__ENTRY11__WIDTH                                           9
#define RIF_TXGAIN3__ENTRY11__MASK                                  0x07fc0000U
#define RIF_TXGAIN3__ENTRY11__READ(src) (((uint32_t)(src) & 0x07fc0000U) >> 18)
#define RIF_TXGAIN3__ENTRY11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define RIF_TXGAIN3__ENTRY11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define RIF_TXGAIN3__ENTRY11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define RIF_TXGAIN3__ENTRY11__RESET_VALUE                           0x000001ffU
/** @} */

/* macros for field pa_supconf3 */
/**
 * @defgroup rif_regs_core_pa_supconf3_field pa_supconf3_field
 * @brief macros for field pa_supconf3
 * @details PA input supply configuration, 00: VDDPA passthrough with NMOS1 and PMOS, 01: AVDD with NMOS0, 10: VDDPA with NMOS1, 11: VDDPA with PMOS
 * @{
 */
#define RIF_TXGAIN3__PA_SUPCONF3__SHIFT                                      27
#define RIF_TXGAIN3__PA_SUPCONF3__WIDTH                                       2
#define RIF_TXGAIN3__PA_SUPCONF3__MASK                              0x18000000U
#define RIF_TXGAIN3__PA_SUPCONF3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x18000000U) >> 27)
#define RIF_TXGAIN3__PA_SUPCONF3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x18000000U)
#define RIF_TXGAIN3__PA_SUPCONF3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x18000000U) | (((uint32_t)(src) <<\
                    27) & 0x18000000U)
#define RIF_TXGAIN3__PA_SUPCONF3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x18000000U)))
#define RIF_TXGAIN3__PA_SUPCONF3__RESET_VALUE                       0x00000003U
/** @} */

/* macros for field pa_refconf3 */
/**
 * @defgroup rif_regs_core_pa_refconf3_field pa_refconf3_field
 * @brief macros for field pa_refconf3
 * @details PA LDO reference configuration max voltage, 00: AVDD, 01: VDDPA, 10: IR 1.0V, 11: IR 1.8V
 * @{
 */
#define RIF_TXGAIN3__PA_REFCONF3__SHIFT                                      29
#define RIF_TXGAIN3__PA_REFCONF3__WIDTH                                       2
#define RIF_TXGAIN3__PA_REFCONF3__MASK                              0x60000000U
#define RIF_TXGAIN3__PA_REFCONF3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x60000000U) >> 29)
#define RIF_TXGAIN3__PA_REFCONF3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x60000000U)
#define RIF_TXGAIN3__PA_REFCONF3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x60000000U) | (((uint32_t)(src) <<\
                    29) & 0x60000000U)
#define RIF_TXGAIN3__PA_REFCONF3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x60000000U)))
#define RIF_TXGAIN3__PA_REFCONF3__RESET_VALUE                       0x00000001U
/** @} */
#define RIF_TXGAIN3__TYPE                                              uint32_t
#define RIF_TXGAIN3__READ                                           0x7fffffffU
#define RIF_TXGAIN3__WRITE                                          0x7fffffffU
#define RIF_TXGAIN3__PRESERVED                                      0x00000000U
#define RIF_TXGAIN3__RESET_VALUE                                    0x3fff69aeU

#endif /* __RIF_TXGAIN3_MACRO__ */

/** @} end of txgain3 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain0 */
/**
 * @defgroup rif_regs_core_rxgain0 rxgain0
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN0_MACRO__
#define __RIF_RXGAIN0_MACRO__

/* macros for field entry0 */
/**
 * @defgroup rif_regs_core_entry0_field entry0_field
 * @brief macros for field entry0
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN0__ENTRY0__SHIFT                                            0
#define RIF_RXGAIN0__ENTRY0__WIDTH                                           10
#define RIF_RXGAIN0__ENTRY0__MASK                                   0x000003ffU
#define RIF_RXGAIN0__ENTRY0__READ(src)          ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN0__ENTRY0__WRITE(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN0__ENTRY0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN0__ENTRY0__VERIFY(src)  (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN0__ENTRY0__RESET_VALUE                            0x00000100U
/** @} */

/* macros for field entry1 */
/**
 * @defgroup rif_regs_core_entry1_field entry1_field
 * @brief macros for field entry1
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN0__ENTRY1__SHIFT                                           10
#define RIF_RXGAIN0__ENTRY1__WIDTH                                           10
#define RIF_RXGAIN0__ENTRY1__MASK                                   0x000ffc00U
#define RIF_RXGAIN0__ENTRY1__READ(src)  (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN0__ENTRY1__WRITE(src) (((uint32_t)(src) << 10) & 0x000ffc00U)
#define RIF_RXGAIN0__ENTRY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN0__ENTRY1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN0__ENTRY1__RESET_VALUE                            0x00000102U
/** @} */

/* macros for field entry2 */
/**
 * @defgroup rif_regs_core_entry2_field entry2_field
 * @brief macros for field entry2
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN0__ENTRY2__SHIFT                                           20
#define RIF_RXGAIN0__ENTRY2__WIDTH                                           10
#define RIF_RXGAIN0__ENTRY2__MASK                                   0x3ff00000U
#define RIF_RXGAIN0__ENTRY2__READ(src)  (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN0__ENTRY2__WRITE(src) (((uint32_t)(src) << 20) & 0x3ff00000U)
#define RIF_RXGAIN0__ENTRY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN0__ENTRY2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN0__ENTRY2__RESET_VALUE                            0x00000104U
/** @} */
#define RIF_RXGAIN0__TYPE                                              uint32_t
#define RIF_RXGAIN0__READ                                           0x3fffffffU
#define RIF_RXGAIN0__WRITE                                          0x3fffffffU
#define RIF_RXGAIN0__PRESERVED                                      0x00000000U
#define RIF_RXGAIN0__RESET_VALUE                                    0x10440900U

#endif /* __RIF_RXGAIN0_MACRO__ */

/** @} end of rxgain0 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain1 */
/**
 * @defgroup rif_regs_core_rxgain1 rxgain1
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN1_MACRO__
#define __RIF_RXGAIN1_MACRO__

/* macros for field entry3 */
/**
 * @defgroup rif_regs_core_entry3_field entry3_field
 * @brief macros for field entry3
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN1__ENTRY3__SHIFT                                            0
#define RIF_RXGAIN1__ENTRY3__WIDTH                                           10
#define RIF_RXGAIN1__ENTRY3__MASK                                   0x000003ffU
#define RIF_RXGAIN1__ENTRY3__READ(src)          ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN1__ENTRY3__WRITE(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN1__ENTRY3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN1__ENTRY3__VERIFY(src)  (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN1__ENTRY3__RESET_VALUE                            0x00000120U
/** @} */

/* macros for field entry4 */
/**
 * @defgroup rif_regs_core_entry4_field entry4_field
 * @brief macros for field entry4
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN1__ENTRY4__SHIFT                                           10
#define RIF_RXGAIN1__ENTRY4__WIDTH                                           10
#define RIF_RXGAIN1__ENTRY4__MASK                                   0x000ffc00U
#define RIF_RXGAIN1__ENTRY4__READ(src)  (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN1__ENTRY4__WRITE(src) (((uint32_t)(src) << 10) & 0x000ffc00U)
#define RIF_RXGAIN1__ENTRY4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN1__ENTRY4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN1__ENTRY4__RESET_VALUE                            0x00000122U
/** @} */

/* macros for field entry5 */
/**
 * @defgroup rif_regs_core_entry5_field entry5_field
 * @brief macros for field entry5
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN1__ENTRY5__SHIFT                                           20
#define RIF_RXGAIN1__ENTRY5__WIDTH                                           10
#define RIF_RXGAIN1__ENTRY5__MASK                                   0x3ff00000U
#define RIF_RXGAIN1__ENTRY5__READ(src)  (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN1__ENTRY5__WRITE(src) (((uint32_t)(src) << 20) & 0x3ff00000U)
#define RIF_RXGAIN1__ENTRY5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN1__ENTRY5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN1__ENTRY5__RESET_VALUE                            0x00000124U
/** @} */
#define RIF_RXGAIN1__TYPE                                              uint32_t
#define RIF_RXGAIN1__READ                                           0x3fffffffU
#define RIF_RXGAIN1__WRITE                                          0x3fffffffU
#define RIF_RXGAIN1__PRESERVED                                      0x00000000U
#define RIF_RXGAIN1__RESET_VALUE                                    0x12448920U

#endif /* __RIF_RXGAIN1_MACRO__ */

/** @} end of rxgain1 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain2 */
/**
 * @defgroup rif_regs_core_rxgain2 rxgain2
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN2_MACRO__
#define __RIF_RXGAIN2_MACRO__

/* macros for field entry6 */
/**
 * @defgroup rif_regs_core_entry6_field entry6_field
 * @brief macros for field entry6
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN2__ENTRY6__SHIFT                                            0
#define RIF_RXGAIN2__ENTRY6__WIDTH                                           10
#define RIF_RXGAIN2__ENTRY6__MASK                                   0x000003ffU
#define RIF_RXGAIN2__ENTRY6__READ(src)          ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN2__ENTRY6__WRITE(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN2__ENTRY6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN2__ENTRY6__VERIFY(src)  (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN2__ENTRY6__RESET_VALUE                            0x00000126U
/** @} */

/* macros for field entry7 */
/**
 * @defgroup rif_regs_core_entry7_field entry7_field
 * @brief macros for field entry7
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN2__ENTRY7__SHIFT                                           10
#define RIF_RXGAIN2__ENTRY7__WIDTH                                           10
#define RIF_RXGAIN2__ENTRY7__MASK                                   0x000ffc00U
#define RIF_RXGAIN2__ENTRY7__READ(src)  (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN2__ENTRY7__WRITE(src) (((uint32_t)(src) << 10) & 0x000ffc00U)
#define RIF_RXGAIN2__ENTRY7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN2__ENTRY7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN2__ENTRY7__RESET_VALUE                            0x00000128U
/** @} */

/* macros for field entry8 */
/**
 * @defgroup rif_regs_core_entry8_field entry8_field
 * @brief macros for field entry8
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN2__ENTRY8__SHIFT                                           20
#define RIF_RXGAIN2__ENTRY8__WIDTH                                           10
#define RIF_RXGAIN2__ENTRY8__MASK                                   0x3ff00000U
#define RIF_RXGAIN2__ENTRY8__READ(src)  (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN2__ENTRY8__WRITE(src) (((uint32_t)(src) << 20) & 0x3ff00000U)
#define RIF_RXGAIN2__ENTRY8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN2__ENTRY8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN2__ENTRY8__RESET_VALUE                            0x0000012aU
/** @} */
#define RIF_RXGAIN2__TYPE                                              uint32_t
#define RIF_RXGAIN2__READ                                           0x3fffffffU
#define RIF_RXGAIN2__WRITE                                          0x3fffffffU
#define RIF_RXGAIN2__PRESERVED                                      0x00000000U
#define RIF_RXGAIN2__RESET_VALUE                                    0x12a4a126U

#endif /* __RIF_RXGAIN2_MACRO__ */

/** @} end of rxgain2 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain3 */
/**
 * @defgroup rif_regs_core_rxgain3 rxgain3
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN3_MACRO__
#define __RIF_RXGAIN3_MACRO__

/* macros for field entry9 */
/**
 * @defgroup rif_regs_core_entry9_field entry9_field
 * @brief macros for field entry9
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN3__ENTRY9__SHIFT                                            0
#define RIF_RXGAIN3__ENTRY9__WIDTH                                           10
#define RIF_RXGAIN3__ENTRY9__MASK                                   0x000003ffU
#define RIF_RXGAIN3__ENTRY9__READ(src)          ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN3__ENTRY9__WRITE(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN3__ENTRY9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN3__ENTRY9__VERIFY(src)  (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN3__ENTRY9__RESET_VALUE                            0x0000012cU
/** @} */

/* macros for field entry10 */
/**
 * @defgroup rif_regs_core_entry10_field entry10_field
 * @brief macros for field entry10
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN3__ENTRY10__SHIFT                                          10
#define RIF_RXGAIN3__ENTRY10__WIDTH                                          10
#define RIF_RXGAIN3__ENTRY10__MASK                                  0x000ffc00U
#define RIF_RXGAIN3__ENTRY10__READ(src) (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN3__ENTRY10__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN3__ENTRY10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN3__ENTRY10__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN3__ENTRY10__RESET_VALUE                           0x0000012eU
/** @} */

/* macros for field entry11 */
/**
 * @defgroup rif_regs_core_entry11_field entry11_field
 * @brief macros for field entry11
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN3__ENTRY11__SHIFT                                          20
#define RIF_RXGAIN3__ENTRY11__WIDTH                                          10
#define RIF_RXGAIN3__ENTRY11__MASK                                  0x3ff00000U
#define RIF_RXGAIN3__ENTRY11__READ(src) (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN3__ENTRY11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN3__ENTRY11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN3__ENTRY11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN3__ENTRY11__RESET_VALUE                           0x00000130U
/** @} */
#define RIF_RXGAIN3__TYPE                                              uint32_t
#define RIF_RXGAIN3__READ                                           0x3fffffffU
#define RIF_RXGAIN3__WRITE                                          0x3fffffffU
#define RIF_RXGAIN3__PRESERVED                                      0x00000000U
#define RIF_RXGAIN3__RESET_VALUE                                    0x1304b92cU

#endif /* __RIF_RXGAIN3_MACRO__ */

/** @} end of rxgain3 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain4 */
/**
 * @defgroup rif_regs_core_rxgain4 rxgain4
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN4_MACRO__
#define __RIF_RXGAIN4_MACRO__

/* macros for field entry12 */
/**
 * @defgroup rif_regs_core_entry12_field entry12_field
 * @brief macros for field entry12
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN4__ENTRY12__SHIFT                                           0
#define RIF_RXGAIN4__ENTRY12__WIDTH                                          10
#define RIF_RXGAIN4__ENTRY12__MASK                                  0x000003ffU
#define RIF_RXGAIN4__ENTRY12__READ(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN4__ENTRY12__WRITE(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN4__ENTRY12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN4__ENTRY12__VERIFY(src) (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN4__ENTRY12__RESET_VALUE                           0x00000132U
/** @} */

/* macros for field entry13 */
/**
 * @defgroup rif_regs_core_entry13_field entry13_field
 * @brief macros for field entry13
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN4__ENTRY13__SHIFT                                          10
#define RIF_RXGAIN4__ENTRY13__WIDTH                                          10
#define RIF_RXGAIN4__ENTRY13__MASK                                  0x000ffc00U
#define RIF_RXGAIN4__ENTRY13__READ(src) (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN4__ENTRY13__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN4__ENTRY13__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN4__ENTRY13__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN4__ENTRY13__RESET_VALUE                           0x00000134U
/** @} */

/* macros for field entry14 */
/**
 * @defgroup rif_regs_core_entry14_field entry14_field
 * @brief macros for field entry14
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN4__ENTRY14__SHIFT                                          20
#define RIF_RXGAIN4__ENTRY14__WIDTH                                          10
#define RIF_RXGAIN4__ENTRY14__MASK                                  0x3ff00000U
#define RIF_RXGAIN4__ENTRY14__READ(src) (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN4__ENTRY14__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN4__ENTRY14__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN4__ENTRY14__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN4__ENTRY14__RESET_VALUE                           0x000001b1U
/** @} */
#define RIF_RXGAIN4__TYPE                                              uint32_t
#define RIF_RXGAIN4__READ                                           0x3fffffffU
#define RIF_RXGAIN4__WRITE                                          0x3fffffffU
#define RIF_RXGAIN4__PRESERVED                                      0x00000000U
#define RIF_RXGAIN4__RESET_VALUE                                    0x1b14d132U

#endif /* __RIF_RXGAIN4_MACRO__ */

/** @} end of rxgain4 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain5 */
/**
 * @defgroup rif_regs_core_rxgain5 rxgain5
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN5_MACRO__
#define __RIF_RXGAIN5_MACRO__

/* macros for field entry15 */
/**
 * @defgroup rif_regs_core_entry15_field entry15_field
 * @brief macros for field entry15
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN5__ENTRY15__SHIFT                                           0
#define RIF_RXGAIN5__ENTRY15__WIDTH                                          10
#define RIF_RXGAIN5__ENTRY15__MASK                                  0x000003ffU
#define RIF_RXGAIN5__ENTRY15__READ(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN5__ENTRY15__WRITE(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN5__ENTRY15__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN5__ENTRY15__VERIFY(src) (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN5__ENTRY15__RESET_VALUE                           0x000001b3U
/** @} */

/* macros for field entry16 */
/**
 * @defgroup rif_regs_core_entry16_field entry16_field
 * @brief macros for field entry16
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN5__ENTRY16__SHIFT                                          10
#define RIF_RXGAIN5__ENTRY16__WIDTH                                          10
#define RIF_RXGAIN5__ENTRY16__MASK                                  0x000ffc00U
#define RIF_RXGAIN5__ENTRY16__READ(src) (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN5__ENTRY16__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN5__ENTRY16__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN5__ENTRY16__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN5__ENTRY16__RESET_VALUE                           0x00000230U
/** @} */

/* macros for field entry17 */
/**
 * @defgroup rif_regs_core_entry17_field entry17_field
 * @brief macros for field entry17
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN5__ENTRY17__SHIFT                                          20
#define RIF_RXGAIN5__ENTRY17__WIDTH                                          10
#define RIF_RXGAIN5__ENTRY17__MASK                                  0x3ff00000U
#define RIF_RXGAIN5__ENTRY17__READ(src) (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN5__ENTRY17__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN5__ENTRY17__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN5__ENTRY17__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN5__ENTRY17__RESET_VALUE                           0x00000232U
/** @} */
#define RIF_RXGAIN5__TYPE                                              uint32_t
#define RIF_RXGAIN5__READ                                           0x3fffffffU
#define RIF_RXGAIN5__WRITE                                          0x3fffffffU
#define RIF_RXGAIN5__PRESERVED                                      0x00000000U
#define RIF_RXGAIN5__RESET_VALUE                                    0x2328c1b3U

#endif /* __RIF_RXGAIN5_MACRO__ */

/** @} end of rxgain5 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain6 */
/**
 * @defgroup rif_regs_core_rxgain6 rxgain6
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN6_MACRO__
#define __RIF_RXGAIN6_MACRO__

/* macros for field entry18 */
/**
 * @defgroup rif_regs_core_entry18_field entry18_field
 * @brief macros for field entry18
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN6__ENTRY18__SHIFT                                           0
#define RIF_RXGAIN6__ENTRY18__WIDTH                                          10
#define RIF_RXGAIN6__ENTRY18__MASK                                  0x000003ffU
#define RIF_RXGAIN6__ENTRY18__READ(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN6__ENTRY18__WRITE(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN6__ENTRY18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN6__ENTRY18__VERIFY(src) (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN6__ENTRY18__RESET_VALUE                           0x00000234U
/** @} */

/* macros for field entry19 */
/**
 * @defgroup rif_regs_core_entry19_field entry19_field
 * @brief macros for field entry19
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN6__ENTRY19__SHIFT                                          10
#define RIF_RXGAIN6__ENTRY19__WIDTH                                          10
#define RIF_RXGAIN6__ENTRY19__MASK                                  0x000ffc00U
#define RIF_RXGAIN6__ENTRY19__READ(src) (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN6__ENTRY19__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN6__ENTRY19__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN6__ENTRY19__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN6__ENTRY19__RESET_VALUE                           0x000002b1U
/** @} */

/* macros for field entry20 */
/**
 * @defgroup rif_regs_core_entry20_field entry20_field
 * @brief macros for field entry20
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN6__ENTRY20__SHIFT                                          20
#define RIF_RXGAIN6__ENTRY20__WIDTH                                          10
#define RIF_RXGAIN6__ENTRY20__MASK                                  0x3ff00000U
#define RIF_RXGAIN6__ENTRY20__READ(src) (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN6__ENTRY20__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN6__ENTRY20__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN6__ENTRY20__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN6__ENTRY20__RESET_VALUE                           0x000002b3U
/** @} */
#define RIF_RXGAIN6__TYPE                                              uint32_t
#define RIF_RXGAIN6__READ                                           0x3fffffffU
#define RIF_RXGAIN6__WRITE                                          0x3fffffffU
#define RIF_RXGAIN6__PRESERVED                                      0x00000000U
#define RIF_RXGAIN6__RESET_VALUE                                    0x2b3ac634U

#endif /* __RIF_RXGAIN6_MACRO__ */

/** @} end of rxgain6 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain7 */
/**
 * @defgroup rif_regs_core_rxgain7 rxgain7
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN7_MACRO__
#define __RIF_RXGAIN7_MACRO__

/* macros for field entry21 */
/**
 * @defgroup rif_regs_core_entry21_field entry21_field
 * @brief macros for field entry21
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN7__ENTRY21__SHIFT                                           0
#define RIF_RXGAIN7__ENTRY21__WIDTH                                          10
#define RIF_RXGAIN7__ENTRY21__MASK                                  0x000003ffU
#define RIF_RXGAIN7__ENTRY21__READ(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN7__ENTRY21__WRITE(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN7__ENTRY21__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN7__ENTRY21__VERIFY(src) (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN7__ENTRY21__RESET_VALUE                           0x000002b5U
/** @} */

/* macros for field entry22 */
/**
 * @defgroup rif_regs_core_entry22_field entry22_field
 * @brief macros for field entry22
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN7__ENTRY22__SHIFT                                          10
#define RIF_RXGAIN7__ENTRY22__WIDTH                                          10
#define RIF_RXGAIN7__ENTRY22__MASK                                  0x000ffc00U
#define RIF_RXGAIN7__ENTRY22__READ(src) (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN7__ENTRY22__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN7__ENTRY22__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN7__ENTRY22__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN7__ENTRY22__RESET_VALUE                           0x00000332U
/** @} */

/* macros for field entry23 */
/**
 * @defgroup rif_regs_core_entry23_field entry23_field
 * @brief macros for field entry23
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN7__ENTRY23__SHIFT                                          20
#define RIF_RXGAIN7__ENTRY23__WIDTH                                          10
#define RIF_RXGAIN7__ENTRY23__MASK                                  0x3ff00000U
#define RIF_RXGAIN7__ENTRY23__READ(src) (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN7__ENTRY23__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN7__ENTRY23__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN7__ENTRY23__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN7__ENTRY23__RESET_VALUE                           0x00000334U
/** @} */
#define RIF_RXGAIN7__TYPE                                              uint32_t
#define RIF_RXGAIN7__READ                                           0x3fffffffU
#define RIF_RXGAIN7__WRITE                                          0x3fffffffU
#define RIF_RXGAIN7__PRESERVED                                      0x00000000U
#define RIF_RXGAIN7__RESET_VALUE                                    0x334ccab5U

#endif /* __RIF_RXGAIN7_MACRO__ */

/** @} end of rxgain7 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain8 */
/**
 * @defgroup rif_regs_core_rxgain8 rxgain8
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN8_MACRO__
#define __RIF_RXGAIN8_MACRO__

/* macros for field entry24 */
/**
 * @defgroup rif_regs_core_entry24_field entry24_field
 * @brief macros for field entry24
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN8__ENTRY24__SHIFT                                           0
#define RIF_RXGAIN8__ENTRY24__WIDTH                                          10
#define RIF_RXGAIN8__ENTRY24__MASK                                  0x000003ffU
#define RIF_RXGAIN8__ENTRY24__READ(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN8__ENTRY24__WRITE(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN8__ENTRY24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN8__ENTRY24__VERIFY(src) (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN8__ENTRY24__RESET_VALUE                           0x00000336U
/** @} */

/* macros for field entry25 */
/**
 * @defgroup rif_regs_core_entry25_field entry25_field
 * @brief macros for field entry25
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN8__ENTRY25__SHIFT                                          10
#define RIF_RXGAIN8__ENTRY25__WIDTH                                          10
#define RIF_RXGAIN8__ENTRY25__MASK                                  0x000ffc00U
#define RIF_RXGAIN8__ENTRY25__READ(src) (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN8__ENTRY25__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN8__ENTRY25__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN8__ENTRY25__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN8__ENTRY25__RESET_VALUE                           0x000003b4U
/** @} */

/* macros for field entry26 */
/**
 * @defgroup rif_regs_core_entry26_field entry26_field
 * @brief macros for field entry26
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN8__ENTRY26__SHIFT                                          20
#define RIF_RXGAIN8__ENTRY26__WIDTH                                          10
#define RIF_RXGAIN8__ENTRY26__MASK                                  0x3ff00000U
#define RIF_RXGAIN8__ENTRY26__READ(src) (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN8__ENTRY26__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN8__ENTRY26__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN8__ENTRY26__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN8__ENTRY26__RESET_VALUE                           0x000003b6U
/** @} */
#define RIF_RXGAIN8__TYPE                                              uint32_t
#define RIF_RXGAIN8__READ                                           0x3fffffffU
#define RIF_RXGAIN8__WRITE                                          0x3fffffffU
#define RIF_RXGAIN8__PRESERVED                                      0x00000000U
#define RIF_RXGAIN8__RESET_VALUE                                    0x3b6ed336U

#endif /* __RIF_RXGAIN8_MACRO__ */

/** @} end of rxgain8 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain9 */
/**
 * @defgroup rif_regs_core_rxgain9 rxgain9
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN9_MACRO__
#define __RIF_RXGAIN9_MACRO__

/* macros for field entry27 */
/**
 * @defgroup rif_regs_core_entry27_field entry27_field
 * @brief macros for field entry27
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN9__ENTRY27__SHIFT                                           0
#define RIF_RXGAIN9__ENTRY27__WIDTH                                          10
#define RIF_RXGAIN9__ENTRY27__MASK                                  0x000003ffU
#define RIF_RXGAIN9__ENTRY27__READ(src)         ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN9__ENTRY27__WRITE(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN9__ENTRY27__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN9__ENTRY27__VERIFY(src) (!(((uint32_t)(src) & ~0x000003ffU)))
#define RIF_RXGAIN9__ENTRY27__RESET_VALUE                           0x000003b8U
/** @} */

/* macros for field entry28 */
/**
 * @defgroup rif_regs_core_entry28_field entry28_field
 * @brief macros for field entry28
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN9__ENTRY28__SHIFT                                          10
#define RIF_RXGAIN9__ENTRY28__WIDTH                                          10
#define RIF_RXGAIN9__ENTRY28__MASK                                  0x000ffc00U
#define RIF_RXGAIN9__ENTRY28__READ(src) (((uint32_t)(src) & 0x000ffc00U) >> 10)
#define RIF_RXGAIN9__ENTRY28__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN9__ENTRY28__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN9__ENTRY28__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN9__ENTRY28__RESET_VALUE                           0x000003b8U
/** @} */

/* macros for field entry29 */
/**
 * @defgroup rif_regs_core_entry29_field entry29_field
 * @brief macros for field entry29
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN9__ENTRY29__SHIFT                                          20
#define RIF_RXGAIN9__ENTRY29__WIDTH                                          10
#define RIF_RXGAIN9__ENTRY29__MASK                                  0x3ff00000U
#define RIF_RXGAIN9__ENTRY29__READ(src) (((uint32_t)(src) & 0x3ff00000U) >> 20)
#define RIF_RXGAIN9__ENTRY29__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN9__ENTRY29__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN9__ENTRY29__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN9__ENTRY29__RESET_VALUE                           0x000003b8U
/** @} */
#define RIF_RXGAIN9__TYPE                                              uint32_t
#define RIF_RXGAIN9__READ                                           0x3fffffffU
#define RIF_RXGAIN9__WRITE                                          0x3fffffffU
#define RIF_RXGAIN9__PRESERVED                                      0x00000000U
#define RIF_RXGAIN9__RESET_VALUE                                    0x3b8ee3b8U

#endif /* __RIF_RXGAIN9_MACRO__ */

/** @} end of rxgain9 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain10 */
/**
 * @defgroup rif_regs_core_rxgain10 rxgain10
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN10_MACRO__
#define __RIF_RXGAIN10_MACRO__

/* macros for field entry30 */
/**
 * @defgroup rif_regs_core_entry30_field entry30_field
 * @brief macros for field entry30
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN10__ENTRY30__SHIFT                                          0
#define RIF_RXGAIN10__ENTRY30__WIDTH                                         10
#define RIF_RXGAIN10__ENTRY30__MASK                                 0x000003ffU
#define RIF_RXGAIN10__ENTRY30__READ(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN10__ENTRY30__WRITE(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN10__ENTRY30__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN10__ENTRY30__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_RXGAIN10__ENTRY30__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field entry31 */
/**
 * @defgroup rif_regs_core_entry31_field entry31_field
 * @brief macros for field entry31
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN10__ENTRY31__SHIFT                                         10
#define RIF_RXGAIN10__ENTRY31__WIDTH                                         10
#define RIF_RXGAIN10__ENTRY31__MASK                                 0x000ffc00U
#define RIF_RXGAIN10__ENTRY31__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define RIF_RXGAIN10__ENTRY31__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN10__ENTRY31__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN10__ENTRY31__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN10__ENTRY31__RESET_VALUE                          0x00000002U
/** @} */

/* macros for field entry32 */
/**
 * @defgroup rif_regs_core_entry32_field entry32_field
 * @brief macros for field entry32
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN10__ENTRY32__SHIFT                                         20
#define RIF_RXGAIN10__ENTRY32__WIDTH                                         10
#define RIF_RXGAIN10__ENTRY32__MASK                                 0x3ff00000U
#define RIF_RXGAIN10__ENTRY32__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define RIF_RXGAIN10__ENTRY32__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN10__ENTRY32__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN10__ENTRY32__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN10__ENTRY32__RESET_VALUE                          0x00000004U
/** @} */
#define RIF_RXGAIN10__TYPE                                             uint32_t
#define RIF_RXGAIN10__READ                                          0x3fffffffU
#define RIF_RXGAIN10__WRITE                                         0x3fffffffU
#define RIF_RXGAIN10__PRESERVED                                     0x00000000U
#define RIF_RXGAIN10__RESET_VALUE                                   0x00400800U

#endif /* __RIF_RXGAIN10_MACRO__ */

/** @} end of rxgain10 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain11 */
/**
 * @defgroup rif_regs_core_rxgain11 rxgain11
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN11_MACRO__
#define __RIF_RXGAIN11_MACRO__

/* macros for field entry33 */
/**
 * @defgroup rif_regs_core_entry33_field entry33_field
 * @brief macros for field entry33
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN11__ENTRY33__SHIFT                                          0
#define RIF_RXGAIN11__ENTRY33__WIDTH                                         10
#define RIF_RXGAIN11__ENTRY33__MASK                                 0x000003ffU
#define RIF_RXGAIN11__ENTRY33__READ(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN11__ENTRY33__WRITE(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN11__ENTRY33__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN11__ENTRY33__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_RXGAIN11__ENTRY33__RESET_VALUE                          0x00000020U
/** @} */

/* macros for field entry34 */
/**
 * @defgroup rif_regs_core_entry34_field entry34_field
 * @brief macros for field entry34
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN11__ENTRY34__SHIFT                                         10
#define RIF_RXGAIN11__ENTRY34__WIDTH                                         10
#define RIF_RXGAIN11__ENTRY34__MASK                                 0x000ffc00U
#define RIF_RXGAIN11__ENTRY34__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define RIF_RXGAIN11__ENTRY34__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN11__ENTRY34__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN11__ENTRY34__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN11__ENTRY34__RESET_VALUE                          0x00000022U
/** @} */

/* macros for field entry35 */
/**
 * @defgroup rif_regs_core_entry35_field entry35_field
 * @brief macros for field entry35
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN11__ENTRY35__SHIFT                                         20
#define RIF_RXGAIN11__ENTRY35__WIDTH                                         10
#define RIF_RXGAIN11__ENTRY35__MASK                                 0x3ff00000U
#define RIF_RXGAIN11__ENTRY35__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define RIF_RXGAIN11__ENTRY35__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN11__ENTRY35__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN11__ENTRY35__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN11__ENTRY35__RESET_VALUE                          0x00000024U
/** @} */
#define RIF_RXGAIN11__TYPE                                             uint32_t
#define RIF_RXGAIN11__READ                                          0x3fffffffU
#define RIF_RXGAIN11__WRITE                                         0x3fffffffU
#define RIF_RXGAIN11__PRESERVED                                     0x00000000U
#define RIF_RXGAIN11__RESET_VALUE                                   0x02408820U

#endif /* __RIF_RXGAIN11_MACRO__ */

/** @} end of rxgain11 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain12 */
/**
 * @defgroup rif_regs_core_rxgain12 rxgain12
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN12_MACRO__
#define __RIF_RXGAIN12_MACRO__

/* macros for field entry36 */
/**
 * @defgroup rif_regs_core_entry36_field entry36_field
 * @brief macros for field entry36
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN12__ENTRY36__SHIFT                                          0
#define RIF_RXGAIN12__ENTRY36__WIDTH                                         10
#define RIF_RXGAIN12__ENTRY36__MASK                                 0x000003ffU
#define RIF_RXGAIN12__ENTRY36__READ(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN12__ENTRY36__WRITE(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN12__ENTRY36__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN12__ENTRY36__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_RXGAIN12__ENTRY36__RESET_VALUE                          0x00000026U
/** @} */

/* macros for field entry37 */
/**
 * @defgroup rif_regs_core_entry37_field entry37_field
 * @brief macros for field entry37
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN12__ENTRY37__SHIFT                                         10
#define RIF_RXGAIN12__ENTRY37__WIDTH                                         10
#define RIF_RXGAIN12__ENTRY37__MASK                                 0x000ffc00U
#define RIF_RXGAIN12__ENTRY37__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define RIF_RXGAIN12__ENTRY37__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN12__ENTRY37__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN12__ENTRY37__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN12__ENTRY37__RESET_VALUE                          0x00000028U
/** @} */

/* macros for field entry38 */
/**
 * @defgroup rif_regs_core_entry38_field entry38_field
 * @brief macros for field entry38
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN12__ENTRY38__SHIFT                                         20
#define RIF_RXGAIN12__ENTRY38__WIDTH                                         10
#define RIF_RXGAIN12__ENTRY38__MASK                                 0x3ff00000U
#define RIF_RXGAIN12__ENTRY38__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define RIF_RXGAIN12__ENTRY38__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN12__ENTRY38__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN12__ENTRY38__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN12__ENTRY38__RESET_VALUE                          0x0000002aU
/** @} */
#define RIF_RXGAIN12__TYPE                                             uint32_t
#define RIF_RXGAIN12__READ                                          0x3fffffffU
#define RIF_RXGAIN12__WRITE                                         0x3fffffffU
#define RIF_RXGAIN12__PRESERVED                                     0x00000000U
#define RIF_RXGAIN12__RESET_VALUE                                   0x02a0a026U

#endif /* __RIF_RXGAIN12_MACRO__ */

/** @} end of rxgain12 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain13 */
/**
 * @defgroup rif_regs_core_rxgain13 rxgain13
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN13_MACRO__
#define __RIF_RXGAIN13_MACRO__

/* macros for field entry39 */
/**
 * @defgroup rif_regs_core_entry39_field entry39_field
 * @brief macros for field entry39
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN13__ENTRY39__SHIFT                                          0
#define RIF_RXGAIN13__ENTRY39__WIDTH                                         10
#define RIF_RXGAIN13__ENTRY39__MASK                                 0x000003ffU
#define RIF_RXGAIN13__ENTRY39__READ(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN13__ENTRY39__WRITE(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN13__ENTRY39__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN13__ENTRY39__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_RXGAIN13__ENTRY39__RESET_VALUE                          0x0000002cU
/** @} */

/* macros for field entry40 */
/**
 * @defgroup rif_regs_core_entry40_field entry40_field
 * @brief macros for field entry40
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN13__ENTRY40__SHIFT                                         10
#define RIF_RXGAIN13__ENTRY40__WIDTH                                         10
#define RIF_RXGAIN13__ENTRY40__MASK                                 0x000ffc00U
#define RIF_RXGAIN13__ENTRY40__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define RIF_RXGAIN13__ENTRY40__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN13__ENTRY40__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN13__ENTRY40__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN13__ENTRY40__RESET_VALUE                          0x0000002eU
/** @} */

/* macros for field entry41 */
/**
 * @defgroup rif_regs_core_entry41_field entry41_field
 * @brief macros for field entry41
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN13__ENTRY41__SHIFT                                         20
#define RIF_RXGAIN13__ENTRY41__WIDTH                                         10
#define RIF_RXGAIN13__ENTRY41__MASK                                 0x3ff00000U
#define RIF_RXGAIN13__ENTRY41__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define RIF_RXGAIN13__ENTRY41__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN13__ENTRY41__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN13__ENTRY41__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN13__ENTRY41__RESET_VALUE                          0x00000030U
/** @} */
#define RIF_RXGAIN13__TYPE                                             uint32_t
#define RIF_RXGAIN13__READ                                          0x3fffffffU
#define RIF_RXGAIN13__WRITE                                         0x3fffffffU
#define RIF_RXGAIN13__PRESERVED                                     0x00000000U
#define RIF_RXGAIN13__RESET_VALUE                                   0x0300b82cU

#endif /* __RIF_RXGAIN13_MACRO__ */

/** @} end of rxgain13 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain14 */
/**
 * @defgroup rif_regs_core_rxgain14 rxgain14
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN14_MACRO__
#define __RIF_RXGAIN14_MACRO__

/* macros for field entry42 */
/**
 * @defgroup rif_regs_core_entry42_field entry42_field
 * @brief macros for field entry42
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN14__ENTRY42__SHIFT                                          0
#define RIF_RXGAIN14__ENTRY42__WIDTH                                         10
#define RIF_RXGAIN14__ENTRY42__MASK                                 0x000003ffU
#define RIF_RXGAIN14__ENTRY42__READ(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN14__ENTRY42__WRITE(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN14__ENTRY42__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN14__ENTRY42__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_RXGAIN14__ENTRY42__RESET_VALUE                          0x00000032U
/** @} */

/* macros for field entry43 */
/**
 * @defgroup rif_regs_core_entry43_field entry43_field
 * @brief macros for field entry43
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN14__ENTRY43__SHIFT                                         10
#define RIF_RXGAIN14__ENTRY43__WIDTH                                         10
#define RIF_RXGAIN14__ENTRY43__MASK                                 0x000ffc00U
#define RIF_RXGAIN14__ENTRY43__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define RIF_RXGAIN14__ENTRY43__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN14__ENTRY43__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN14__ENTRY43__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN14__ENTRY43__RESET_VALUE                          0x00000034U
/** @} */

/* macros for field entry44 */
/**
 * @defgroup rif_regs_core_entry44_field entry44_field
 * @brief macros for field entry44
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN14__ENTRY44__SHIFT                                         20
#define RIF_RXGAIN14__ENTRY44__WIDTH                                         10
#define RIF_RXGAIN14__ENTRY44__MASK                                 0x3ff00000U
#define RIF_RXGAIN14__ENTRY44__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define RIF_RXGAIN14__ENTRY44__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN14__ENTRY44__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN14__ENTRY44__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN14__ENTRY44__RESET_VALUE                          0x00000036U
/** @} */
#define RIF_RXGAIN14__TYPE                                             uint32_t
#define RIF_RXGAIN14__READ                                          0x3fffffffU
#define RIF_RXGAIN14__WRITE                                         0x3fffffffU
#define RIF_RXGAIN14__PRESERVED                                     0x00000000U
#define RIF_RXGAIN14__RESET_VALUE                                   0x0360d032U

#endif /* __RIF_RXGAIN14_MACRO__ */

/** @} end of rxgain14 */

/* macros for BlueprintGlobalNameSpace::RIF_rxgain15 */
/**
 * @defgroup rif_regs_core_rxgain15 rxgain15
 * @brief RX gain table, entries ordered lnagain[2:0], bb1gain[1:0], bb2gain[4:0] definitions.
 * @{
 */
#ifndef __RIF_RXGAIN15_MACRO__
#define __RIF_RXGAIN15_MACRO__

/* macros for field entry45 */
/**
 * @defgroup rif_regs_core_entry45_field entry45_field
 * @brief macros for field entry45
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN15__ENTRY45__SHIFT                                          0
#define RIF_RXGAIN15__ENTRY45__WIDTH                                         10
#define RIF_RXGAIN15__ENTRY45__MASK                                 0x000003ffU
#define RIF_RXGAIN15__ENTRY45__READ(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN15__ENTRY45__WRITE(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_RXGAIN15__ENTRY45__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_RXGAIN15__ENTRY45__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_RXGAIN15__ENTRY45__RESET_VALUE                          0x00000038U
/** @} */

/* macros for field entry46 */
/**
 * @defgroup rif_regs_core_entry46_field entry46_field
 * @brief macros for field entry46
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN15__ENTRY46__SHIFT                                         10
#define RIF_RXGAIN15__ENTRY46__WIDTH                                         10
#define RIF_RXGAIN15__ENTRY46__MASK                                 0x000ffc00U
#define RIF_RXGAIN15__ENTRY46__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define RIF_RXGAIN15__ENTRY46__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define RIF_RXGAIN15__ENTRY46__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define RIF_RXGAIN15__ENTRY46__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define RIF_RXGAIN15__ENTRY46__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field entry47 */
/**
 * @defgroup rif_regs_core_entry47_field entry47_field
 * @brief macros for field entry47
 * @details RX gain table entry
 * @{
 */
#define RIF_RXGAIN15__ENTRY47__SHIFT                                         20
#define RIF_RXGAIN15__ENTRY47__WIDTH                                         10
#define RIF_RXGAIN15__ENTRY47__MASK                                 0x3ff00000U
#define RIF_RXGAIN15__ENTRY47__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define RIF_RXGAIN15__ENTRY47__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define RIF_RXGAIN15__ENTRY47__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define RIF_RXGAIN15__ENTRY47__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define RIF_RXGAIN15__ENTRY47__RESET_VALUE                          0x00000000U
/** @} */
#define RIF_RXGAIN15__TYPE                                             uint32_t
#define RIF_RXGAIN15__READ                                          0x3fffffffU
#define RIF_RXGAIN15__WRITE                                         0x3fffffffU
#define RIF_RXGAIN15__PRESERVED                                     0x00000000U
#define RIF_RXGAIN15__RESET_VALUE                                   0x00000038U

#endif /* __RIF_RXGAIN15_MACRO__ */

/** @} end of rxgain15 */

/* macros for BlueprintGlobalNameSpace::RIF_syntx_cal */
/**
 * @defgroup rif_regs_core_syntx_cal syntx_cal
 * @brief Synth TX calibration settings definitions.
 * @{
 */
#ifndef __RIF_SYNTX_CAL_MACRO__
#define __RIF_SYNTX_CAL_MACRO__

/* macros for field txmodGain2M_delta */
/**
 * @defgroup rif_regs_core_txmodGain2M_delta_field txmodGain2M_delta_field
 * @brief macros for field txmodGain2M_delta
 * @details Signed delta offset from txmodGain value to set full-scale gain of the high frequency modulation path in 2Mbps mode
 * @{
 */
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__SHIFT                               0
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__WIDTH                               5
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__MASK                      0x0000001fU
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define RIF_SYNTX_CAL__TXMODGAIN2M_DELTA__RESET_VALUE               0x00000000U
/** @} */

/* macros for field deltaF_target */
/**
 * @defgroup rif_regs_core_deltaF_target_field deltaF_target_field
 * @brief macros for field deltaF_target
 * @details During modgain cal, normalized target freq deviation = 390.625KHz + (15.625KHz * deltaF_target) for 1Mbps
 * @{
 */
#define RIF_SYNTX_CAL__DELTAF_TARGET__SHIFT                                   5
#define RIF_SYNTX_CAL__DELTAF_TARGET__WIDTH                                   4
#define RIF_SYNTX_CAL__DELTAF_TARGET__MASK                          0x000001e0U
#define RIF_SYNTX_CAL__DELTAF_TARGET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001e0U) >> 5)
#define RIF_SYNTX_CAL__DELTAF_TARGET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000001e0U)
#define RIF_SYNTX_CAL__DELTAF_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001e0U) | (((uint32_t)(src) <<\
                    5) & 0x000001e0U)
#define RIF_SYNTX_CAL__DELTAF_TARGET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000001e0U)))
#define RIF_SYNTX_CAL__DELTAF_TARGET__RESET_VALUE                   0x00000007U
/** @} */

/* macros for field modVarSize_1M */
/**
 * @defgroup rif_regs_core_modVarSize_1M_field modVarSize_1M_field
 * @brief macros for field modVarSize_1M
 * @details modulation varactor size for 1Mbps rate
 * @{
 */
#define RIF_SYNTX_CAL__MODVARSIZE_1M__SHIFT                                   9
#define RIF_SYNTX_CAL__MODVARSIZE_1M__WIDTH                                   4
#define RIF_SYNTX_CAL__MODVARSIZE_1M__MASK                          0x00001e00U
#define RIF_SYNTX_CAL__MODVARSIZE_1M__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
#define RIF_SYNTX_CAL__MODVARSIZE_1M__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00001e00U)
#define RIF_SYNTX_CAL__MODVARSIZE_1M__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001e00U) | (((uint32_t)(src) <<\
                    9) & 0x00001e00U)
#define RIF_SYNTX_CAL__MODVARSIZE_1M__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00001e00U)))
#define RIF_SYNTX_CAL__MODVARSIZE_1M__RESET_VALUE                   0x00000003U
/** @} */
#define RIF_SYNTX_CAL__TYPE                                            uint32_t
#define RIF_SYNTX_CAL__READ                                         0x00001fffU
#define RIF_SYNTX_CAL__WRITE                                        0x00001fffU
#define RIF_SYNTX_CAL__PRESERVED                                    0x00000000U
#define RIF_SYNTX_CAL__RESET_VALUE                                  0x000006e0U

#endif /* __RIF_SYNTX_CAL_MACRO__ */

/** @} end of syntx_cal */

/* macros for BlueprintGlobalNameSpace::RIF_syntx0 */
/**
 * @defgroup rif_regs_core_syntx0 syntx0
 * @brief Synth state machine, misc settings, and VCO cap search algorithm definitions.
 * @{
 */
#ifndef __RIF_SYNTX0_MACRO__
#define __RIF_SYNTX0_MACRO__

/* macros for field stateLength_PowerOnWait_x4u */
/**
 * @defgroup rif_regs_core_stateLength_PowerOnWait_x4u_field stateLength_PowerOnWait_x4u_field
 * @brief macros for field stateLength_PowerOnWait_x4u
 * @details Length of POWER_ON_WAIT state is (stateLength_PowerOnWait_x4u+1)*4us
 * @{
 */
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__SHIFT                        0
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__WIDTH                        3
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__MASK               0x00000007U
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define RIF_SYNTX0__STATELENGTH_POWERONWAIT_X4U__RESET_VALUE        0x00000001U
/** @} */

/* macros for field stateLength_CapSearchGetReady_x250n */
/**
 * @defgroup rif_regs_core_stateLength_CapSearchGetReady_x250n_field stateLength_CapSearchGetReady_x250n_field
 * @brief macros for field stateLength_CapSearchGetReady_x250n
 * @details Length of CAPSEARCH_GETREADY state is (stateLength_CapSearchGetReady_x250n+1)*250n
 * @{
 */
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__SHIFT                3
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__WIDTH                3
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__MASK       0x00000038U
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHGETREADY_X250N__RESET_VALUE \
                    0x00000003U
/** @} */

/* macros for field stateLength_CapSearchCount_x1u */
/**
 * @defgroup rif_regs_core_stateLength_CapSearchCount_x1u_field stateLength_CapSearchCount_x1u_field
 * @brief macros for field stateLength_CapSearchCount_x1u
 * @details Length of CAPSEARCH_COUNT state is (stateLength_CapSearchCount_x1u+1)*1u
 * @{
 */
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__SHIFT                     6
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__WIDTH                     3
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__MASK            0x000001c0U
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define RIF_SYNTX0__STATELENGTH_CAPSEARCHCOUNT_X1U__RESET_VALUE     0x00000002U
/** @} */

/* macros for field stateLength_CloseLoop_x2u */
/**
 * @defgroup rif_regs_core_stateLength_CloseLoop_x2u_field stateLength_CloseLoop_x2u_field
 * @brief macros for field stateLength_CloseLoop_x2u
 * @details Length of CLOSE_LOOP state is (stateLength_CloseLoop_x2u+1)*2u
 * @{
 */
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__SHIFT                          9
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__WIDTH                          3
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__MASK                 0x00000e00U
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define RIF_SYNTX0__STATELENGTH_CLOSELOOP_X2U__RESET_VALUE          0x00000004U
/** @} */

/* macros for field stateLength_modGainCal_x64u */
/**
 * @defgroup rif_regs_core_stateLength_modGainCal_x64u_field stateLength_modGainCal_x64u_field
 * @brief macros for field stateLength_modGainCal_x64u
 * @details Length of STATE_MODCAL_COUNT* state is (stateLength_modGainCal_x64u+1)*64u
 * @{
 */
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__SHIFT                       12
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__WIDTH                        4
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__MASK               0x0000f000U
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define RIF_SYNTX0__STATELENGTH_MODGAINCAL_X64U__RESET_VALUE        0x00000001U
/** @} */

/* macros for field vcrefMi */
/**
 * @defgroup rif_regs_core_vcrefMi_field vcrefMi_field
 * @brief macros for field vcrefMi
 * @details Adjusts the voltage to which the control voltage is pinned during capacitor search. 0 is the lowest value
 * @{
 */
#define RIF_SYNTX0__VCREFMI__SHIFT                                           16
#define RIF_SYNTX0__VCREFMI__WIDTH                                            2
#define RIF_SYNTX0__VCREFMI__MASK                                   0x00030000U
#define RIF_SYNTX0__VCREFMI__READ(src)  (((uint32_t)(src) & 0x00030000U) >> 16)
#define RIF_SYNTX0__VCREFMI__WRITE(src) (((uint32_t)(src) << 16) & 0x00030000U)
#define RIF_SYNTX0__VCREFMI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define RIF_SYNTX0__VCREFMI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define RIF_SYNTX0__VCREFMI__RESET_VALUE                            0x00000002U
/** @} */

/* macros for field cpLkIntLow */
/**
 * @defgroup rif_regs_core_cpLkIntLow_field cpLkIntLow_field
 * @brief macros for field cpLkIntLow
 * @details If set, the charge pump leakage current is reduced in integer channels to reduce noise and spurs
 * @{
 */
#define RIF_SYNTX0__CPLKINTLOW__SHIFT                                        18
#define RIF_SYNTX0__CPLKINTLOW__WIDTH                                         1
#define RIF_SYNTX0__CPLKINTLOW__MASK                                0x00040000U
#define RIF_SYNTX0__CPLKINTLOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define RIF_SYNTX0__CPLKINTLOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define RIF_SYNTX0__CPLKINTLOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define RIF_SYNTX0__CPLKINTLOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define RIF_SYNTX0__CPLKINTLOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define RIF_SYNTX0__CPLKINTLOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define RIF_SYNTX0__CPLKINTLOW__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field alwaysCpHiBias */
/**
 * @defgroup rif_regs_core_alwaysCpHiBias_field alwaysCpHiBias_field
 * @brief macros for field alwaysCpHiBias
 * @details If set, the charge pump bias is forced to always be in high current mode
 * @{
 */
#define RIF_SYNTX0__ALWAYSCPHIBIAS__SHIFT                                    19
#define RIF_SYNTX0__ALWAYSCPHIBIAS__WIDTH                                     1
#define RIF_SYNTX0__ALWAYSCPHIBIAS__MASK                            0x00080000U
#define RIF_SYNTX0__ALWAYSCPHIBIAS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define RIF_SYNTX0__ALWAYSCPHIBIAS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define RIF_SYNTX0__ALWAYSCPHIBIAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define RIF_SYNTX0__ALWAYSCPHIBIAS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define RIF_SYNTX0__ALWAYSCPHIBIAS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define RIF_SYNTX0__ALWAYSCPHIBIAS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define RIF_SYNTX0__ALWAYSCPHIBIAS__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field enRXLObufEarly */
/**
 * @defgroup rif_regs_core_enRXLObufEarly_field enRXLObufEarly_field
 * @brief macros for field enRXLObufEarly
 * @details If set, RXLO buffers are enabled when (enSynthAnalog & ~txon), which is earlier than rxon
 * @{
 */
#define RIF_SYNTX0__ENRXLOBUFEARLY__SHIFT                                    20
#define RIF_SYNTX0__ENRXLOBUFEARLY__WIDTH                                     1
#define RIF_SYNTX0__ENRXLOBUFEARLY__MASK                            0x00100000U
#define RIF_SYNTX0__ENRXLOBUFEARLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define RIF_SYNTX0__ENRXLOBUFEARLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define RIF_SYNTX0__ENRXLOBUFEARLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define RIF_SYNTX0__ENRXLOBUFEARLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define RIF_SYNTX0__ENRXLOBUFEARLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define RIF_SYNTX0__ENRXLOBUFEARLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define RIF_SYNTX0__ENRXLOBUFEARLY__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field rxloSingleStartupAlwaysOn */
/**
 * @defgroup rif_regs_core_rxloSingleStartupAlwaysOn_field rxloSingleStartupAlwaysOn_field
 * @brief macros for field rxloSingleStartupAlwaysOn
 * @details if =1, forces enSingleStartup to always be high
 * @{
 */
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__SHIFT                         21
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__WIDTH                          1
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__MASK                 0x00200000U
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define RIF_SYNTX0__RXLOSINGLESTARTUPALWAYSON__RESET_VALUE          0x00000000U
/** @} */

/* macros for field useFullBinaryCapSearch_tx */
/**
 * @defgroup rif_regs_core_useFullBinaryCapSearch_tx_field useFullBinaryCapSearch_tx_field
 * @brief macros for field useFullBinaryCapSearch_tx
 * @details if =1, VCO cap search algorithm reverts to a full binary search at every channel change for TX mode
 * @{
 */
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__SHIFT                         22
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__WIDTH                          1
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__MASK                 0x00400000U
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_TX__RESET_VALUE          0x00000000U
/** @} */

/* macros for field useFullBinaryCapSearch_rx */
/**
 * @defgroup rif_regs_core_useFullBinaryCapSearch_rx_field useFullBinaryCapSearch_rx_field
 * @brief macros for field useFullBinaryCapSearch_rx
 * @details if =1, VCO cap search algorithm reverts to a full binary search at every channel change for RX mode
 * @{
 */
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__SHIFT                         23
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__WIDTH                          1
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__MASK                 0x00800000U
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define RIF_SYNTX0__USEFULLBINARYCAPSEARCH_RX__RESET_VALUE          0x00000000U
/** @} */

/* macros for field synth_spare */
/**
 * @defgroup rif_regs_core_synth_spare_field synth_spare_field
 * @brief macros for field synth_spare
 * @details spare bits
 * @{
 */
#define RIF_SYNTX0__SYNTH_SPARE__SHIFT                                       24
#define RIF_SYNTX0__SYNTH_SPARE__WIDTH                                        5
#define RIF_SYNTX0__SYNTH_SPARE__MASK                               0x1f000000U
#define RIF_SYNTX0__SYNTH_SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1f000000U) >> 24)
#define RIF_SYNTX0__SYNTH_SPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x1f000000U)
#define RIF_SYNTX0__SYNTH_SPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1f000000U) | (((uint32_t)(src) <<\
                    24) & 0x1f000000U)
#define RIF_SYNTX0__SYNTH_SPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x1f000000U)))
#define RIF_SYNTX0__SYNTH_SPARE__RESET_VALUE                        0x00000000U
/** @} */
#define RIF_SYNTX0__TYPE                                               uint32_t
#define RIF_SYNTX0__READ                                            0x1fffffffU
#define RIF_SYNTX0__WRITE                                           0x1fffffffU
#define RIF_SYNTX0__PRESERVED                                       0x00000000U
#define RIF_SYNTX0__RESET_VALUE                                     0x00061899U

#endif /* __RIF_SYNTX0_MACRO__ */

/** @} end of syntx0 */

/* macros for BlueprintGlobalNameSpace::RIF_syntx1 */
/**
 * @defgroup rif_regs_core_syntx1 syntx1
 * @brief Synth loop parameters for TX 1M mode definitions.
 * @{
 */
#ifndef __RIF_SYNTX1_MACRO__
#define __RIF_SYNTX1_MACRO__

/* macros for field loopReferenceFrequency_tx1 */
/**
 * @defgroup rif_regs_core_loopReferenceFrequency_tx1_field loopReferenceFrequency_tx1_field
 * @brief macros for field loopReferenceFrequency_tx1
 * @details Loop reference frequency, 0 -> 8MHz (only with 8MHz crystal), 1 -> 16MHz, 2 -> 32MHz (only with 16 MHz crystal), 3 -> unused
 * @{
 */
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__SHIFT                         0
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__WIDTH                         2
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__MASK                0x00000003U
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define RIF_SYNTX1__LOOPREFERENCEFREQUENCY_TX1__RESET_VALUE         0x00000002U
/** @} */

/* macros for field vcoAgcEn_tx1 */
/**
 * @defgroup rif_regs_core_vcoAgcEn_tx1_field vcoAgcEn_tx1_field
 * @brief macros for field vcoAgcEn_tx1
 * @details enables the vco AGC
 * @{
 */
#define RIF_SYNTX1__VCOAGCEN_TX1__SHIFT                                       2
#define RIF_SYNTX1__VCOAGCEN_TX1__WIDTH                                       1
#define RIF_SYNTX1__VCOAGCEN_TX1__MASK                              0x00000004U
#define RIF_SYNTX1__VCOAGCEN_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RIF_SYNTX1__VCOAGCEN_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RIF_SYNTX1__VCOAGCEN_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RIF_SYNTX1__VCOAGCEN_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RIF_SYNTX1__VCOAGCEN_TX1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RIF_SYNTX1__VCOAGCEN_TX1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RIF_SYNTX1__VCOAGCEN_TX1__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field vcoAgcEnGain_tx1 */
/**
 * @defgroup rif_regs_core_vcoAgcEnGain_tx1_field vcoAgcEnGain_tx1_field
 * @brief macros for field vcoAgcEnGain_tx1
 * @details vco AGC gain
 * @{
 */
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__SHIFT                                   3
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__WIDTH                                   3
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__MASK                          0x00000038U
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define RIF_SYNTX1__VCOAGCENGAIN_TX1__RESET_VALUE                   0x00000007U
/** @} */

/* macros for field vcoBias_tx1 */
/**
 * @defgroup rif_regs_core_vcoBias_tx1_field vcoBias_tx1_field
 * @brief macros for field vcoBias_tx1
 * @details vco bias, also the target value for the vco AGC when it is enabled
 * @{
 */
#define RIF_SYNTX1__VCOBIAS_TX1__SHIFT                                        6
#define RIF_SYNTX1__VCOBIAS_TX1__WIDTH                                        4
#define RIF_SYNTX1__VCOBIAS_TX1__MASK                               0x000003c0U
#define RIF_SYNTX1__VCOBIAS_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define RIF_SYNTX1__VCOBIAS_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define RIF_SYNTX1__VCOBIAS_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define RIF_SYNTX1__VCOBIAS_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define RIF_SYNTX1__VCOBIAS_TX1__RESET_VALUE                        0x00000008U
/** @} */

/* macros for field cpBias_tx1 */
/**
 * @defgroup rif_regs_core_cpBias_tx1_field cpBias_tx1_field
 * @brief macros for field cpBias_tx1
 * @details charge pump bias current
 * @{
 */
#define RIF_SYNTX1__CPBIAS_TX1__SHIFT                                        10
#define RIF_SYNTX1__CPBIAS_TX1__WIDTH                                         4
#define RIF_SYNTX1__CPBIAS_TX1__MASK                                0x00003c00U
#define RIF_SYNTX1__CPBIAS_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003c00U) >> 10)
#define RIF_SYNTX1__CPBIAS_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define RIF_SYNTX1__CPBIAS_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define RIF_SYNTX1__CPBIAS_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define RIF_SYNTX1__CPBIAS_TX1__RESET_VALUE                         0x00000009U
/** @} */

/* macros for field cpCur_tx1 */
/**
 * @defgroup rif_regs_core_cpCur_tx1_field cpCur_tx1_field
 * @brief macros for field cpCur_tx1
 * @details charge pump current (Icp = (1+cpBias<3:0>) * (1+cpCur<3:0>) * 1.5uA = (1+cpCur<3:0>) * 24uA (for cbBias<3:0>=0xf) = (1+cpBias<3:0>) * 24uA (for cpCur<3:0>=0xf) = 384uA max)
 * @{
 */
#define RIF_SYNTX1__CPCUR_TX1__SHIFT                                         14
#define RIF_SYNTX1__CPCUR_TX1__WIDTH                                          4
#define RIF_SYNTX1__CPCUR_TX1__MASK                                 0x0003c000U
#define RIF_SYNTX1__CPCUR_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003c000U) >> 14)
#define RIF_SYNTX1__CPCUR_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0003c000U)
#define RIF_SYNTX1__CPCUR_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003c000U) | (((uint32_t)(src) <<\
                    14) & 0x0003c000U)
#define RIF_SYNTX1__CPCUR_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0003c000U)))
#define RIF_SYNTX1__CPCUR_TX1__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field cpLk_tx1 */
/**
 * @defgroup rif_regs_core_cpLk_tx1_field cpLk_tx1_field
 * @brief macros for field cpLk_tx1
 * @details charge pump leakage current (Iup = 125nA * (1 + lk<3:0>) = 2uA max, DC = Iup/Idn*100% =(1 + lk<3:0>) * 0.52% = 8.32% max)
 * @{
 */
#define RIF_SYNTX1__CPLK_TX1__SHIFT                                          18
#define RIF_SYNTX1__CPLK_TX1__WIDTH                                           4
#define RIF_SYNTX1__CPLK_TX1__MASK                                  0x003c0000U
#define RIF_SYNTX1__CPLK_TX1__READ(src) (((uint32_t)(src) & 0x003c0000U) >> 18)
#define RIF_SYNTX1__CPLK_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x003c0000U)
#define RIF_SYNTX1__CPLK_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003c0000U) | (((uint32_t)(src) <<\
                    18) & 0x003c0000U)
#define RIF_SYNTX1__CPLK_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x003c0000U)))
#define RIF_SYNTX1__CPLK_TX1__RESET_VALUE                           0x0000000cU
/** @} */

/* macros for field filtC_tx1 */
/**
 * @defgroup rif_regs_core_filtC_tx1_field filtC_tx1_field
 * @brief macros for field filtC_tx1
 * @details Loop filter capacitor setting Cs = 100p*(0.5 + 0.5/3*filtC<1:0>) Cp = 2.28p(inside 3rd order filter) + 3.42p + 5.64p/3*filtC<1:0>
 * @{
 */
#define RIF_SYNTX1__FILTC_TX1__SHIFT                                         22
#define RIF_SYNTX1__FILTC_TX1__WIDTH                                          2
#define RIF_SYNTX1__FILTC_TX1__MASK                                 0x00c00000U
#define RIF_SYNTX1__FILTC_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define RIF_SYNTX1__FILTC_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define RIF_SYNTX1__FILTC_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define RIF_SYNTX1__FILTC_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define RIF_SYNTX1__FILTC_TX1__RESET_VALUE                          0x00000003U
/** @} */

/* macros for field filtRs_tx1 */
/**
 * @defgroup rif_regs_core_filtRs_tx1_field filtRs_tx1_field
 * @brief macros for field filtRs_tx1
 * @details Loop filter Rs setting (0..15) -> Rs=(13, 17, 21, 27, 33, 41, 49, 61, 73, 89, 109, 133, 161, 197, 241, 301)KOhms
 * @{
 */
#define RIF_SYNTX1__FILTRS_TX1__SHIFT                                        24
#define RIF_SYNTX1__FILTRS_TX1__WIDTH                                         4
#define RIF_SYNTX1__FILTRS_TX1__MASK                                0x0f000000U
#define RIF_SYNTX1__FILTRS_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RIF_SYNTX1__FILTRS_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RIF_SYNTX1__FILTRS_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RIF_SYNTX1__FILTRS_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define RIF_SYNTX1__FILTRS_TX1__RESET_VALUE                         0x00000004U
/** @} */

/* macros for field filtR3_tx1 */
/**
 * @defgroup rif_regs_core_filtR3_tx1_field filtR3_tx1_field
 * @brief macros for field filtR3_tx1
 * @details Loop filter resistor for 3rd pole (0..15) -> Rs=(13, 17, 21, 27, 33, 41, 49, 61, 73, 89, 109, 133, 161, 197, 241, 301)KOhms. (0..15) -> p3=(5.37, 4.11, 3.32, 2.58, 2.12, 1.70, 1.42, 1.14, 0.95, 0.78, 0.64, 0.52, 0.43, 0.35, 0.29, 0.23)MHz
 * @{
 */
#define RIF_SYNTX1__FILTR3_TX1__SHIFT                                        28
#define RIF_SYNTX1__FILTR3_TX1__WIDTH                                         4
#define RIF_SYNTX1__FILTR3_TX1__MASK                                0xf0000000U
#define RIF_SYNTX1__FILTR3_TX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RIF_SYNTX1__FILTR3_TX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RIF_SYNTX1__FILTR3_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RIF_SYNTX1__FILTR3_TX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RIF_SYNTX1__FILTR3_TX1__RESET_VALUE                         0x00000007U
/** @} */
#define RIF_SYNTX1__TYPE                                               uint32_t
#define RIF_SYNTX1__READ                                            0xffffffffU
#define RIF_SYNTX1__WRITE                                           0xffffffffU
#define RIF_SYNTX1__PRESERVED                                       0x00000000U
#define RIF_SYNTX1__RESET_VALUE                                     0x74f0663eU

#endif /* __RIF_SYNTX1_MACRO__ */

/** @} end of syntx1 */

/* macros for BlueprintGlobalNameSpace::RIF_syntx2 */
/**
 * @defgroup rif_regs_core_syntx2 syntx2
 * @brief Synth loop parameters for TX 2M mode 2Mbps definitions.
 * @{
 */
#ifndef __RIF_SYNTX2_MACRO__
#define __RIF_SYNTX2_MACRO__

/* macros for field loopReferenceFrequency_tx2 */
/**
 * @defgroup rif_regs_core_loopReferenceFrequency_tx2_field loopReferenceFrequency_tx2_field
 * @brief macros for field loopReferenceFrequency_tx2
 * @details Loop reference frequency, 0 -> 8MHz, 1 -> 16MHz, 2 = 32MHz
 * @{
 */
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__SHIFT                         0
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__WIDTH                         2
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__MASK                0x00000003U
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define RIF_SYNTX2__LOOPREFERENCEFREQUENCY_TX2__RESET_VALUE         0x00000002U
/** @} */

/* macros for field vcoAgcEn_tx2 */
/**
 * @defgroup rif_regs_core_vcoAgcEn_tx2_field vcoAgcEn_tx2_field
 * @brief macros for field vcoAgcEn_tx2
 * @details Enable VCO AGC
 * @{
 */
#define RIF_SYNTX2__VCOAGCEN_TX2__SHIFT                                       2
#define RIF_SYNTX2__VCOAGCEN_TX2__WIDTH                                       1
#define RIF_SYNTX2__VCOAGCEN_TX2__MASK                              0x00000004U
#define RIF_SYNTX2__VCOAGCEN_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RIF_SYNTX2__VCOAGCEN_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RIF_SYNTX2__VCOAGCEN_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RIF_SYNTX2__VCOAGCEN_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RIF_SYNTX2__VCOAGCEN_TX2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RIF_SYNTX2__VCOAGCEN_TX2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RIF_SYNTX2__VCOAGCEN_TX2__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field vcoAgcEnGain_tx2 */
/**
 * @defgroup rif_regs_core_vcoAgcEnGain_tx2_field vcoAgcEnGain_tx2_field
 * @brief macros for field vcoAgcEnGain_tx2
 * @details VCO AGC gain setting
 * @{
 */
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__SHIFT                                   3
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__WIDTH                                   3
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__MASK                          0x00000038U
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define RIF_SYNTX2__VCOAGCENGAIN_TX2__RESET_VALUE                   0x00000007U
/** @} */

/* macros for field vcoBias_tx2 */
/**
 * @defgroup rif_regs_core_vcoBias_tx2_field vcoBias_tx2_field
 * @brief macros for field vcoBias_tx2
 * @details VCO bias setting
 * @{
 */
#define RIF_SYNTX2__VCOBIAS_TX2__SHIFT                                        6
#define RIF_SYNTX2__VCOBIAS_TX2__WIDTH                                        4
#define RIF_SYNTX2__VCOBIAS_TX2__MASK                               0x000003c0U
#define RIF_SYNTX2__VCOBIAS_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define RIF_SYNTX2__VCOBIAS_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define RIF_SYNTX2__VCOBIAS_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define RIF_SYNTX2__VCOBIAS_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define RIF_SYNTX2__VCOBIAS_TX2__RESET_VALUE                        0x00000008U
/** @} */

/* macros for field cpBias_tx2 */
/**
 * @defgroup rif_regs_core_cpBias_tx2_field cpBias_tx2_field
 * @brief macros for field cpBias_tx2
 * @details CP bias setting
 * @{
 */
#define RIF_SYNTX2__CPBIAS_TX2__SHIFT                                        10
#define RIF_SYNTX2__CPBIAS_TX2__WIDTH                                         4
#define RIF_SYNTX2__CPBIAS_TX2__MASK                                0x00003c00U
#define RIF_SYNTX2__CPBIAS_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003c00U) >> 10)
#define RIF_SYNTX2__CPBIAS_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define RIF_SYNTX2__CPBIAS_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define RIF_SYNTX2__CPBIAS_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define RIF_SYNTX2__CPBIAS_TX2__RESET_VALUE                         0x0000000eU
/** @} */

/* macros for field cpCur_tx2 */
/**
 * @defgroup rif_regs_core_cpCur_tx2_field cpCur_tx2_field
 * @brief macros for field cpCur_tx2
 * @details CP current setting
 * @{
 */
#define RIF_SYNTX2__CPCUR_TX2__SHIFT                                         14
#define RIF_SYNTX2__CPCUR_TX2__WIDTH                                          4
#define RIF_SYNTX2__CPCUR_TX2__MASK                                 0x0003c000U
#define RIF_SYNTX2__CPCUR_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003c000U) >> 14)
#define RIF_SYNTX2__CPCUR_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0003c000U)
#define RIF_SYNTX2__CPCUR_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003c000U) | (((uint32_t)(src) <<\
                    14) & 0x0003c000U)
#define RIF_SYNTX2__CPCUR_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0003c000U)))
#define RIF_SYNTX2__CPCUR_TX2__RESET_VALUE                          0x00000005U
/** @} */

/* macros for field cpLk_tx2 */
/**
 * @defgroup rif_regs_core_cpLk_tx2_field cpLk_tx2_field
 * @brief macros for field cpLk_tx2
 * @details CP leakage setting
 * @{
 */
#define RIF_SYNTX2__CPLK_TX2__SHIFT                                          18
#define RIF_SYNTX2__CPLK_TX2__WIDTH                                           4
#define RIF_SYNTX2__CPLK_TX2__MASK                                  0x003c0000U
#define RIF_SYNTX2__CPLK_TX2__READ(src) (((uint32_t)(src) & 0x003c0000U) >> 18)
#define RIF_SYNTX2__CPLK_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x003c0000U)
#define RIF_SYNTX2__CPLK_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003c0000U) | (((uint32_t)(src) <<\
                    18) & 0x003c0000U)
#define RIF_SYNTX2__CPLK_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x003c0000U)))
#define RIF_SYNTX2__CPLK_TX2__RESET_VALUE                           0x0000000cU
/** @} */

/* macros for field filtC_tx2 */
/**
 * @defgroup rif_regs_core_filtC_tx2_field filtC_tx2_field
 * @brief macros for field filtC_tx2
 * @details Loop filter series big C setting
 * @{
 */
#define RIF_SYNTX2__FILTC_TX2__SHIFT                                         22
#define RIF_SYNTX2__FILTC_TX2__WIDTH                                          2
#define RIF_SYNTX2__FILTC_TX2__MASK                                 0x00c00000U
#define RIF_SYNTX2__FILTC_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define RIF_SYNTX2__FILTC_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define RIF_SYNTX2__FILTC_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define RIF_SYNTX2__FILTC_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define RIF_SYNTX2__FILTC_TX2__RESET_VALUE                          0x00000003U
/** @} */

/* macros for field filtRs_tx2 */
/**
 * @defgroup rif_regs_core_filtRs_tx2_field filtRs_tx2_field
 * @brief macros for field filtRs_tx2
 * @details Loop filter series R setting
 * @{
 */
#define RIF_SYNTX2__FILTRS_TX2__SHIFT                                        24
#define RIF_SYNTX2__FILTRS_TX2__WIDTH                                         4
#define RIF_SYNTX2__FILTRS_TX2__MASK                                0x0f000000U
#define RIF_SYNTX2__FILTRS_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RIF_SYNTX2__FILTRS_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RIF_SYNTX2__FILTRS_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RIF_SYNTX2__FILTRS_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define RIF_SYNTX2__FILTRS_TX2__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field filtR3_tx2 */
/**
 * @defgroup rif_regs_core_filtR3_tx2_field filtR3_tx2_field
 * @brief macros for field filtR3_tx2
 * @details Loop filter 3rd order R setting
 * @{
 */
#define RIF_SYNTX2__FILTR3_TX2__SHIFT                                        28
#define RIF_SYNTX2__FILTR3_TX2__WIDTH                                         4
#define RIF_SYNTX2__FILTR3_TX2__MASK                                0xf0000000U
#define RIF_SYNTX2__FILTR3_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RIF_SYNTX2__FILTR3_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RIF_SYNTX2__FILTR3_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RIF_SYNTX2__FILTR3_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RIF_SYNTX2__FILTR3_TX2__RESET_VALUE                         0x00000004U
/** @} */
#define RIF_SYNTX2__TYPE                                               uint32_t
#define RIF_SYNTX2__READ                                            0xffffffffU
#define RIF_SYNTX2__WRITE                                           0xffffffffU
#define RIF_SYNTX2__PRESERVED                                       0x00000000U
#define RIF_SYNTX2__RESET_VALUE                                     0x41f17a3eU

#endif /* __RIF_SYNTX2_MACRO__ */

/** @} end of syntx2 */

/* macros for BlueprintGlobalNameSpace::RIF_syntx3 */
/**
 * @defgroup rif_regs_core_syntx3 syntx3
 * @brief Synth loop parameters for RX mode definitions.
 * @{
 */
#ifndef __RIF_SYNTX3_MACRO__
#define __RIF_SYNTX3_MACRO__

/* macros for field loopReferenceFrequency_rx */
/**
 * @defgroup rif_regs_core_loopReferenceFrequency_rx_field loopReferenceFrequency_rx_field
 * @brief macros for field loopReferenceFrequency_rx
 * @details Loop reference frequency, 0 -> 8MHz, 1 -> 16MHz, 2 = 32MHz
 * @{
 */
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__SHIFT                          0
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__WIDTH                          2
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__MASK                 0x00000003U
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define RIF_SYNTX3__LOOPREFERENCEFREQUENCY_RX__RESET_VALUE          0x00000002U
/** @} */

/* macros for field vcoAgcEn_rx */
/**
 * @defgroup rif_regs_core_vcoAgcEn_rx_field vcoAgcEn_rx_field
 * @brief macros for field vcoAgcEn_rx
 * @details Enable VCO AGC
 * @{
 */
#define RIF_SYNTX3__VCOAGCEN_RX__SHIFT                                        2
#define RIF_SYNTX3__VCOAGCEN_RX__WIDTH                                        1
#define RIF_SYNTX3__VCOAGCEN_RX__MASK                               0x00000004U
#define RIF_SYNTX3__VCOAGCEN_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RIF_SYNTX3__VCOAGCEN_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RIF_SYNTX3__VCOAGCEN_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RIF_SYNTX3__VCOAGCEN_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RIF_SYNTX3__VCOAGCEN_RX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RIF_SYNTX3__VCOAGCEN_RX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RIF_SYNTX3__VCOAGCEN_RX__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field vcoAgcEnGain_rx */
/**
 * @defgroup rif_regs_core_vcoAgcEnGain_rx_field vcoAgcEnGain_rx_field
 * @brief macros for field vcoAgcEnGain_rx
 * @details VCO AGC gain setting
 * @{
 */
#define RIF_SYNTX3__VCOAGCENGAIN_RX__SHIFT                                    3
#define RIF_SYNTX3__VCOAGCENGAIN_RX__WIDTH                                    3
#define RIF_SYNTX3__VCOAGCENGAIN_RX__MASK                           0x00000038U
#define RIF_SYNTX3__VCOAGCENGAIN_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define RIF_SYNTX3__VCOAGCENGAIN_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define RIF_SYNTX3__VCOAGCENGAIN_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define RIF_SYNTX3__VCOAGCENGAIN_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define RIF_SYNTX3__VCOAGCENGAIN_RX__RESET_VALUE                    0x00000007U
/** @} */

/* macros for field vcoBias_rx */
/**
 * @defgroup rif_regs_core_vcoBias_rx_field vcoBias_rx_field
 * @brief macros for field vcoBias_rx
 * @details VCO bias setting
 * @{
 */
#define RIF_SYNTX3__VCOBIAS_RX__SHIFT                                         6
#define RIF_SYNTX3__VCOBIAS_RX__WIDTH                                         4
#define RIF_SYNTX3__VCOBIAS_RX__MASK                                0x000003c0U
#define RIF_SYNTX3__VCOBIAS_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define RIF_SYNTX3__VCOBIAS_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define RIF_SYNTX3__VCOBIAS_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define RIF_SYNTX3__VCOBIAS_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define RIF_SYNTX3__VCOBIAS_RX__RESET_VALUE                         0x00000008U
/** @} */

/* macros for field cpBias_rx */
/**
 * @defgroup rif_regs_core_cpBias_rx_field cpBias_rx_field
 * @brief macros for field cpBias_rx
 * @details CP bias setting
 * @{
 */
#define RIF_SYNTX3__CPBIAS_RX__SHIFT                                         10
#define RIF_SYNTX3__CPBIAS_RX__WIDTH                                          4
#define RIF_SYNTX3__CPBIAS_RX__MASK                                 0x00003c00U
#define RIF_SYNTX3__CPBIAS_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003c00U) >> 10)
#define RIF_SYNTX3__CPBIAS_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define RIF_SYNTX3__CPBIAS_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define RIF_SYNTX3__CPBIAS_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define RIF_SYNTX3__CPBIAS_RX__RESET_VALUE                          0x0000000bU
/** @} */

/* macros for field cpCur_rx */
/**
 * @defgroup rif_regs_core_cpCur_rx_field cpCur_rx_field
 * @brief macros for field cpCur_rx
 * @details CP current setting
 * @{
 */
#define RIF_SYNTX3__CPCUR_RX__SHIFT                                          14
#define RIF_SYNTX3__CPCUR_RX__WIDTH                                           4
#define RIF_SYNTX3__CPCUR_RX__MASK                                  0x0003c000U
#define RIF_SYNTX3__CPCUR_RX__READ(src) (((uint32_t)(src) & 0x0003c000U) >> 14)
#define RIF_SYNTX3__CPCUR_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0003c000U)
#define RIF_SYNTX3__CPCUR_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003c000U) | (((uint32_t)(src) <<\
                    14) & 0x0003c000U)
#define RIF_SYNTX3__CPCUR_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0003c000U)))
#define RIF_SYNTX3__CPCUR_RX__RESET_VALUE                           0x00000001U
/** @} */

/* macros for field cpLk_rx */
/**
 * @defgroup rif_regs_core_cpLk_rx_field cpLk_rx_field
 * @brief macros for field cpLk_rx
 * @details CP leakage setting
 * @{
 */
#define RIF_SYNTX3__CPLK_RX__SHIFT                                           18
#define RIF_SYNTX3__CPLK_RX__WIDTH                                            4
#define RIF_SYNTX3__CPLK_RX__MASK                                   0x003c0000U
#define RIF_SYNTX3__CPLK_RX__READ(src)  (((uint32_t)(src) & 0x003c0000U) >> 18)
#define RIF_SYNTX3__CPLK_RX__WRITE(src) (((uint32_t)(src) << 18) & 0x003c0000U)
#define RIF_SYNTX3__CPLK_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003c0000U) | (((uint32_t)(src) <<\
                    18) & 0x003c0000U)
#define RIF_SYNTX3__CPLK_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x003c0000U)))
#define RIF_SYNTX3__CPLK_RX__RESET_VALUE                            0x0000000bU
/** @} */

/* macros for field filtC_rx */
/**
 * @defgroup rif_regs_core_filtC_rx_field filtC_rx_field
 * @brief macros for field filtC_rx
 * @details Loop filter series big C setting
 * @{
 */
#define RIF_SYNTX3__FILTC_RX__SHIFT                                          22
#define RIF_SYNTX3__FILTC_RX__WIDTH                                           2
#define RIF_SYNTX3__FILTC_RX__MASK                                  0x00c00000U
#define RIF_SYNTX3__FILTC_RX__READ(src) (((uint32_t)(src) & 0x00c00000U) >> 22)
#define RIF_SYNTX3__FILTC_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define RIF_SYNTX3__FILTC_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define RIF_SYNTX3__FILTC_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define RIF_SYNTX3__FILTC_RX__RESET_VALUE                           0x00000003U
/** @} */

/* macros for field filtRs_rx */
/**
 * @defgroup rif_regs_core_filtRs_rx_field filtRs_rx_field
 * @brief macros for field filtRs_rx
 * @details Loop filter series R setting
 * @{
 */
#define RIF_SYNTX3__FILTRS_RX__SHIFT                                         24
#define RIF_SYNTX3__FILTRS_RX__WIDTH                                          4
#define RIF_SYNTX3__FILTRS_RX__MASK                                 0x0f000000U
#define RIF_SYNTX3__FILTRS_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RIF_SYNTX3__FILTRS_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RIF_SYNTX3__FILTRS_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RIF_SYNTX3__FILTRS_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define RIF_SYNTX3__FILTRS_RX__RESET_VALUE                          0x00000004U
/** @} */

/* macros for field filtR3_rx */
/**
 * @defgroup rif_regs_core_filtR3_rx_field filtR3_rx_field
 * @brief macros for field filtR3_rx
 * @details Loop filter 3rd order R setting
 * @{
 */
#define RIF_SYNTX3__FILTR3_RX__SHIFT                                         28
#define RIF_SYNTX3__FILTR3_RX__WIDTH                                          4
#define RIF_SYNTX3__FILTR3_RX__MASK                                 0xf0000000U
#define RIF_SYNTX3__FILTR3_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RIF_SYNTX3__FILTR3_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RIF_SYNTX3__FILTR3_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RIF_SYNTX3__FILTR3_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RIF_SYNTX3__FILTR3_RX__RESET_VALUE                          0x00000007U
/** @} */
#define RIF_SYNTX3__TYPE                                               uint32_t
#define RIF_SYNTX3__READ                                            0xffffffffU
#define RIF_SYNTX3__WRITE                                           0xffffffffU
#define RIF_SYNTX3__PRESERVED                                       0x00000000U
#define RIF_SYNTX3__RESET_VALUE                                     0x74ec6e3eU

#endif /* __RIF_SYNTX3_MACRO__ */

/** @} end of syntx3 */

/* macros for BlueprintGlobalNameSpace::RIF_syntx4 */
/**
 * @defgroup rif_regs_core_syntx4 syntx4
 * @brief Extra synth vcoGain loop parameter, modulation index and ramp controls definitions.
 * @{
 */
#ifndef __RIF_SYNTX4_MACRO__
#define __RIF_SYNTX4_MACRO__

/* macros for field vcoGain_tx1 */
/**
 * @defgroup rif_regs_core_vcoGain_tx1_field vcoGain_tx1_field
 * @brief macros for field vcoGain_tx1
 * @details VCO gain in 1Mbps TX mode. Kvco = (vcoGain<2:0> + 1)*13.9MHz/V, Kvcomax=111MHz/v
 * @{
 */
#define RIF_SYNTX4__VCOGAIN_TX1__SHIFT                                        0
#define RIF_SYNTX4__VCOGAIN_TX1__WIDTH                                        3
#define RIF_SYNTX4__VCOGAIN_TX1__MASK                               0x00000007U
#define RIF_SYNTX4__VCOGAIN_TX1__READ(src)      ((uint32_t)(src) & 0x00000007U)
#define RIF_SYNTX4__VCOGAIN_TX1__WRITE(src)     ((uint32_t)(src) & 0x00000007U)
#define RIF_SYNTX4__VCOGAIN_TX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define RIF_SYNTX4__VCOGAIN_TX1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define RIF_SYNTX4__VCOGAIN_TX1__RESET_VALUE                        0x00000005U
/** @} */

/* macros for field vcoGain_tx2 */
/**
 * @defgroup rif_regs_core_vcoGain_tx2_field vcoGain_tx2_field
 * @brief macros for field vcoGain_tx2
 * @details VCO gain in 2Mbps TX mode
 * @{
 */
#define RIF_SYNTX4__VCOGAIN_TX2__SHIFT                                        3
#define RIF_SYNTX4__VCOGAIN_TX2__WIDTH                                        3
#define RIF_SYNTX4__VCOGAIN_TX2__MASK                               0x00000038U
#define RIF_SYNTX4__VCOGAIN_TX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define RIF_SYNTX4__VCOGAIN_TX2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define RIF_SYNTX4__VCOGAIN_TX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define RIF_SYNTX4__VCOGAIN_TX2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define RIF_SYNTX4__VCOGAIN_TX2__RESET_VALUE                        0x00000004U
/** @} */

/* macros for field vcoGain_rx */
/**
 * @defgroup rif_regs_core_vcoGain_rx_field vcoGain_rx_field
 * @brief macros for field vcoGain_rx
 * @details VCO gain in RX mode. Kvco = (vcoGain<2:0> + 1)*20.8MHz/V, Kvcomax=166MHz/v
 * @{
 */
#define RIF_SYNTX4__VCOGAIN_RX__SHIFT                                         6
#define RIF_SYNTX4__VCOGAIN_RX__WIDTH                                         3
#define RIF_SYNTX4__VCOGAIN_RX__MASK                                0x000001c0U
#define RIF_SYNTX4__VCOGAIN_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define RIF_SYNTX4__VCOGAIN_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define RIF_SYNTX4__VCOGAIN_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define RIF_SYNTX4__VCOGAIN_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define RIF_SYNTX4__VCOGAIN_RX__RESET_VALUE                         0x00000003U
/** @} */

/* macros for field disableVcoGainInMinSS */
/**
 * @defgroup rif_regs_core_disableVcoGainInMinSS_field disableVcoGainInMinSS_field
 * @brief macros for field disableVcoGainInMinSS
 * @{
 */
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__SHIFT                              9
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__WIDTH                              1
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__MASK                     0x00000200U
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define RIF_SYNTX4__DISABLEVCOGAININMINSS__RESET_VALUE              0x00000000U
/** @} */

/* macros for field mod_idx */
/**
 * @defgroup rif_regs_core_mod_idx_field mod_idx_field
 * @brief macros for field mod_idx
 * @details MAX VALUE = 251, not 255
 * @{
 */
#define RIF_SYNTX4__MOD_IDX__SHIFT                                           10
#define RIF_SYNTX4__MOD_IDX__WIDTH                                            8
#define RIF_SYNTX4__MOD_IDX__MASK                                   0x0003fc00U
#define RIF_SYNTX4__MOD_IDX__READ(src)  (((uint32_t)(src) & 0x0003fc00U) >> 10)
#define RIF_SYNTX4__MOD_IDX__WRITE(src) (((uint32_t)(src) << 10) & 0x0003fc00U)
#define RIF_SYNTX4__MOD_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0003fc00U)
#define RIF_SYNTX4__MOD_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0003fc00U)))
#define RIF_SYNTX4__MOD_IDX__RESET_VALUE                            0x00000080U
/** @} */

/* macros for field fast_mod_ramp_down */
/**
 * @defgroup rif_regs_core_fast_mod_ramp_down_field fast_mod_ramp_down_field
 * @brief macros for field fast_mod_ramp_down
 * @details If set, instant frequency deviation step from last symbol back to carrier rather than smooth transition
 * @{
 */
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__SHIFT                                18
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__WIDTH                                 1
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__MASK                        0x00040000U
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define RIF_SYNTX4__FAST_MOD_RAMP_DOWN__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field fast_mod_ramp_up */
/**
 * @defgroup rif_regs_core_fast_mod_ramp_up_field fast_mod_ramp_up_field
 * @brief macros for field fast_mod_ramp_up
 * @details If set, instant frequency deviation step from carrier to first symbol rather than smooth transition
 * @{
 */
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__SHIFT                                  19
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__WIDTH                                   1
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__MASK                          0x00080000U
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define RIF_SYNTX4__FAST_MOD_RAMP_UP__RESET_VALUE                   0x00000001U
/** @} */
#define RIF_SYNTX4__TYPE                                               uint32_t
#define RIF_SYNTX4__READ                                            0x000fffffU
#define RIF_SYNTX4__WRITE                                           0x000fffffU
#define RIF_SYNTX4__PRESERVED                                       0x00000000U
#define RIF_SYNTX4__RESET_VALUE                                     0x000a00e5U

#endif /* __RIF_SYNTX4_MACRO__ */

/** @} end of syntx4 */

/* macros for BlueprintGlobalNameSpace::RIF_syntx5 */
/**
 * @defgroup rif_regs_core_syntx5 syntx5
 * @brief PA settings and more spares definitions.
 * @{
 */
#ifndef __RIF_SYNTX5_MACRO__
#define __RIF_SYNTX5_MACRO__

/* macros for field pa_cas */
/**
 * @defgroup rif_regs_core_pa_cas_field pa_cas_field
 * @brief macros for field pa_cas
 * @details PA cascode bias voltage
 * @{
 */
#define RIF_SYNTX5__PA_CAS__SHIFT                                             5
#define RIF_SYNTX5__PA_CAS__WIDTH                                             3
#define RIF_SYNTX5__PA_CAS__MASK                                    0x000000e0U
#define RIF_SYNTX5__PA_CAS__READ(src)    (((uint32_t)(src) & 0x000000e0U) >> 5)
#define RIF_SYNTX5__PA_CAS__WRITE(src)   (((uint32_t)(src) << 5) & 0x000000e0U)
#define RIF_SYNTX5__PA_CAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define RIF_SYNTX5__PA_CAS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000000e0U)))
#define RIF_SYNTX5__PA_CAS__RESET_VALUE                             0x00000004U
/** @} */

/* macros for field pa_ctx */
/**
 * @defgroup rif_regs_core_pa_ctx_field pa_ctx_field
 * @brief macros for field pa_ctx
 * @details 0 = ground cascode gates of unused PA devices during TX, could cause extra stress but improve efficiency, 1 = all devices stay biased at cascode voltage
 * @{
 */
#define RIF_SYNTX5__PA_CTX__SHIFT                                             8
#define RIF_SYNTX5__PA_CTX__WIDTH                                             1
#define RIF_SYNTX5__PA_CTX__MASK                                    0x00000100U
#define RIF_SYNTX5__PA_CTX__READ(src)    (((uint32_t)(src) & 0x00000100U) >> 8)
#define RIF_SYNTX5__PA_CTX__WRITE(src)   (((uint32_t)(src) << 8) & 0x00000100U)
#define RIF_SYNTX5__PA_CTX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define RIF_SYNTX5__PA_CTX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define RIF_SYNTX5__PA_CTX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define RIF_SYNTX5__PA_CTX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define RIF_SYNTX5__PA_CTX__RESET_VALUE                             0x00000001U
/** @} */

/* macros for field pa_ctune_rx */
/**
 * @defgroup rif_regs_core_pa_ctune_rx_field pa_ctune_rx_field
 * @brief macros for field pa_ctune_rx
 * @details Controls number of PA stages whose cascode gate is tied high to get programmable matching cap in RX
 * @{
 */
#define RIF_SYNTX5__PA_CTUNE_RX__SHIFT                                        9
#define RIF_SYNTX5__PA_CTUNE_RX__WIDTH                                        4
#define RIF_SYNTX5__PA_CTUNE_RX__MASK                               0x00001e00U
#define RIF_SYNTX5__PA_CTUNE_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
#define RIF_SYNTX5__PA_CTUNE_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00001e00U)
#define RIF_SYNTX5__PA_CTUNE_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001e00U) | (((uint32_t)(src) <<\
                    9) & 0x00001e00U)
#define RIF_SYNTX5__PA_CTUNE_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00001e00U)))
#define RIF_SYNTX5__PA_CTUNE_RX__RESET_VALUE                        0x00000000U
/** @} */
#define RIF_SYNTX5__TYPE                                               uint32_t
#define RIF_SYNTX5__READ                                            0x00001fe0U
#define RIF_SYNTX5__WRITE                                           0x00001fe0U
#define RIF_SYNTX5__PRESERVED                                       0x00000000U
#define RIF_SYNTX5__RESET_VALUE                                     0x00000180U

#endif /* __RIF_SYNTX5_MACRO__ */

/** @} end of syntx5 */

/* macros for BlueprintGlobalNameSpace::RIF_duty_cycle */
/**
 * @defgroup rif_regs_core_duty_cycle duty_cycle
 * @brief PA duty cycle definitions.
 * @{
 */
#ifndef __RIF_DUTY_CYCLE_MACRO__
#define __RIF_DUTY_CYCLE_MACRO__

/* macros for field tx_index0_to_6 */
/**
 * @defgroup rif_regs_core_tx_index0_to_6_field tx_index0_to_6_field
 * @brief macros for field tx_index0_to_6
 * @details duty cycle to use when tx_index is between 0 and 6, inclusive
 * @{
 */
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__SHIFT                                 0
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__WIDTH                                 4
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__MASK                        0x0000000fU
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define RIF_DUTY_CYCLE__TX_INDEX0_TO_6__RESET_VALUE                 0x0000000fU
/** @} */

/* macros for field tx_index7 */
/**
 * @defgroup rif_regs_core_tx_index7_field tx_index7_field
 * @brief macros for field tx_index7
 * @details duty cycle to use when tx_index is 7
 * @{
 */
#define RIF_DUTY_CYCLE__TX_INDEX7__SHIFT                                      4
#define RIF_DUTY_CYCLE__TX_INDEX7__WIDTH                                      4
#define RIF_DUTY_CYCLE__TX_INDEX7__MASK                             0x000000f0U
#define RIF_DUTY_CYCLE__TX_INDEX7__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RIF_DUTY_CYCLE__TX_INDEX7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RIF_DUTY_CYCLE__TX_INDEX7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RIF_DUTY_CYCLE__TX_INDEX7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define RIF_DUTY_CYCLE__TX_INDEX7__RESET_VALUE                      0x0000000bU
/** @} */

/* macros for field tx_index8 */
/**
 * @defgroup rif_regs_core_tx_index8_field tx_index8_field
 * @brief macros for field tx_index8
 * @details duty cycle to use when tx_index is 8
 * @{
 */
#define RIF_DUTY_CYCLE__TX_INDEX8__SHIFT                                      8
#define RIF_DUTY_CYCLE__TX_INDEX8__WIDTH                                      4
#define RIF_DUTY_CYCLE__TX_INDEX8__MASK                             0x00000f00U
#define RIF_DUTY_CYCLE__TX_INDEX8__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RIF_DUTY_CYCLE__TX_INDEX8__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RIF_DUTY_CYCLE__TX_INDEX8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RIF_DUTY_CYCLE__TX_INDEX8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define RIF_DUTY_CYCLE__TX_INDEX8__RESET_VALUE                      0x0000000cU
/** @} */

/* macros for field tx_index9 */
/**
 * @defgroup rif_regs_core_tx_index9_field tx_index9_field
 * @brief macros for field tx_index9
 * @details duty cycle to use when tx_index is 9
 * @{
 */
#define RIF_DUTY_CYCLE__TX_INDEX9__SHIFT                                     12
#define RIF_DUTY_CYCLE__TX_INDEX9__WIDTH                                      4
#define RIF_DUTY_CYCLE__TX_INDEX9__MASK                             0x0000f000U
#define RIF_DUTY_CYCLE__TX_INDEX9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RIF_DUTY_CYCLE__TX_INDEX9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RIF_DUTY_CYCLE__TX_INDEX9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RIF_DUTY_CYCLE__TX_INDEX9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define RIF_DUTY_CYCLE__TX_INDEX9__RESET_VALUE                      0x00000009U
/** @} */

/* macros for field tx_index10 */
/**
 * @defgroup rif_regs_core_tx_index10_field tx_index10_field
 * @brief macros for field tx_index10
 * @details duty cycle to use when tx_index is 10
 * @{
 */
#define RIF_DUTY_CYCLE__TX_INDEX10__SHIFT                                    16
#define RIF_DUTY_CYCLE__TX_INDEX10__WIDTH                                     4
#define RIF_DUTY_CYCLE__TX_INDEX10__MASK                            0x000f0000U
#define RIF_DUTY_CYCLE__TX_INDEX10__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RIF_DUTY_CYCLE__TX_INDEX10__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RIF_DUTY_CYCLE__TX_INDEX10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RIF_DUTY_CYCLE__TX_INDEX10__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define RIF_DUTY_CYCLE__TX_INDEX10__RESET_VALUE                     0x00000007U
/** @} */

/* macros for field tx_index11 */
/**
 * @defgroup rif_regs_core_tx_index11_field tx_index11_field
 * @brief macros for field tx_index11
 * @details duty cycle to use when tx_index is 11
 * @{
 */
#define RIF_DUTY_CYCLE__TX_INDEX11__SHIFT                                    20
#define RIF_DUTY_CYCLE__TX_INDEX11__WIDTH                                     4
#define RIF_DUTY_CYCLE__TX_INDEX11__MASK                            0x00f00000U
#define RIF_DUTY_CYCLE__TX_INDEX11__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RIF_DUTY_CYCLE__TX_INDEX11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RIF_DUTY_CYCLE__TX_INDEX11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RIF_DUTY_CYCLE__TX_INDEX11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define RIF_DUTY_CYCLE__TX_INDEX11__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field override_value */
/**
 * @defgroup rif_regs_core_override_value_field override_value_field
 * @brief macros for field override_value
 * @details if ovr is set, then use override_value and ignore tx_index from LC
 * @{
 */
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__SHIFT                                24
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__WIDTH                                 4
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__MASK                        0x0f000000U
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define RIF_DUTY_CYCLE__OVERRIDE_VALUE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ovr */
/**
 * @defgroup rif_regs_core_ovr_field ovr_field
 * @brief macros for field ovr
 * @details if ovr is set, then use override_value and ignore tx_index from LC
 * @{
 */
#define RIF_DUTY_CYCLE__OVR__SHIFT                                           28
#define RIF_DUTY_CYCLE__OVR__WIDTH                                            1
#define RIF_DUTY_CYCLE__OVR__MASK                                   0x10000000U
#define RIF_DUTY_CYCLE__OVR__READ(src)  (((uint32_t)(src) & 0x10000000U) >> 28)
#define RIF_DUTY_CYCLE__OVR__WRITE(src) (((uint32_t)(src) << 28) & 0x10000000U)
#define RIF_DUTY_CYCLE__OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define RIF_DUTY_CYCLE__OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define RIF_DUTY_CYCLE__OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define RIF_DUTY_CYCLE__OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define RIF_DUTY_CYCLE__OVR__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field pa_invert */
/**
 * @defgroup rif_regs_core_pa_invert_field pa_invert_field
 * @brief macros for field pa_invert
 * @details Invert PA to get duty cycles <50%
 * @{
 */
#define RIF_DUTY_CYCLE__PA_INVERT__SHIFT                                     29
#define RIF_DUTY_CYCLE__PA_INVERT__WIDTH                                      1
#define RIF_DUTY_CYCLE__PA_INVERT__MASK                             0x20000000U
#define RIF_DUTY_CYCLE__PA_INVERT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define RIF_DUTY_CYCLE__PA_INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define RIF_DUTY_CYCLE__PA_INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define RIF_DUTY_CYCLE__PA_INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define RIF_DUTY_CYCLE__PA_INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define RIF_DUTY_CYCLE__PA_INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define RIF_DUTY_CYCLE__PA_INVERT__RESET_VALUE                      0x00000000U
/** @} */
#define RIF_DUTY_CYCLE__TYPE                                           uint32_t
#define RIF_DUTY_CYCLE__READ                                        0x3fffffffU
#define RIF_DUTY_CYCLE__WRITE                                       0x3fffffffU
#define RIF_DUTY_CYCLE__PRESERVED                                   0x00000000U
#define RIF_DUTY_CYCLE__RESET_VALUE                                 0x00079cbfU

#endif /* __RIF_DUTY_CYCLE_MACRO__ */

/** @} end of duty_cycle */

/* macros for BlueprintGlobalNameSpace::RIF_txgain0_pmu */
/**
 * @defgroup rif_regs_core_txgain0_pmu txgain0_pmu
 * @brief TX power table for pmu using VSTORE as PA supply, entries 0 to 4, paRef[5:0] definitions.
 * @{
 */
#ifndef __RIF_TXGAIN0_PMU_MACRO__
#define __RIF_TXGAIN0_PMU_MACRO__

/* macros for field entry0 */
/**
 * @defgroup rif_regs_core_entry0_field entry0_field
 * @brief macros for field entry0
 * @details TX power level entry 0, -20dBm
 * @{
 */
#define RIF_TXGAIN0_PMU__ENTRY0__SHIFT                                        0
#define RIF_TXGAIN0_PMU__ENTRY0__WIDTH                                        6
#define RIF_TXGAIN0_PMU__ENTRY0__MASK                               0x0000003fU
#define RIF_TXGAIN0_PMU__ENTRY0__READ(src)      ((uint32_t)(src) & 0x0000003fU)
#define RIF_TXGAIN0_PMU__ENTRY0__WRITE(src)     ((uint32_t)(src) & 0x0000003fU)
#define RIF_TXGAIN0_PMU__ENTRY0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RIF_TXGAIN0_PMU__ENTRY0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define RIF_TXGAIN0_PMU__ENTRY0__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field entry1 */
/**
 * @defgroup rif_regs_core_entry1_field entry1_field
 * @brief macros for field entry1
 * @details TX power level entry 1, -10dBm
 * @{
 */
#define RIF_TXGAIN0_PMU__ENTRY1__SHIFT                                        6
#define RIF_TXGAIN0_PMU__ENTRY1__WIDTH                                        6
#define RIF_TXGAIN0_PMU__ENTRY1__MASK                               0x00000fc0U
#define RIF_TXGAIN0_PMU__ENTRY1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define RIF_TXGAIN0_PMU__ENTRY1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define RIF_TXGAIN0_PMU__ENTRY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define RIF_TXGAIN0_PMU__ENTRY1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define RIF_TXGAIN0_PMU__ENTRY1__RESET_VALUE                        0x0000000cU
/** @} */

/* macros for field entry2 */
/**
 * @defgroup rif_regs_core_entry2_field entry2_field
 * @brief macros for field entry2
 * @details TX power level entry 2, -8dBm
 * @{
 */
#define RIF_TXGAIN0_PMU__ENTRY2__SHIFT                                       12
#define RIF_TXGAIN0_PMU__ENTRY2__WIDTH                                        6
#define RIF_TXGAIN0_PMU__ENTRY2__MASK                               0x0003f000U
#define RIF_TXGAIN0_PMU__ENTRY2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define RIF_TXGAIN0_PMU__ENTRY2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define RIF_TXGAIN0_PMU__ENTRY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define RIF_TXGAIN0_PMU__ENTRY2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define RIF_TXGAIN0_PMU__ENTRY2__RESET_VALUE                        0x00000010U
/** @} */

/* macros for field entry3 */
/**
 * @defgroup rif_regs_core_entry3_field entry3_field
 * @brief macros for field entry3
 * @details TX power level entry 3, -6dBm
 * @{
 */
#define RIF_TXGAIN0_PMU__ENTRY3__SHIFT                                       18
#define RIF_TXGAIN0_PMU__ENTRY3__WIDTH                                        6
#define RIF_TXGAIN0_PMU__ENTRY3__MASK                               0x00fc0000U
#define RIF_TXGAIN0_PMU__ENTRY3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define RIF_TXGAIN0_PMU__ENTRY3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define RIF_TXGAIN0_PMU__ENTRY3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define RIF_TXGAIN0_PMU__ENTRY3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define RIF_TXGAIN0_PMU__ENTRY3__RESET_VALUE                        0x00000013U
/** @} */

/* macros for field entry4 */
/**
 * @defgroup rif_regs_core_entry4_field entry4_field
 * @brief macros for field entry4
 * @details TX power level entry 4, -4dBm
 * @{
 */
#define RIF_TXGAIN0_PMU__ENTRY4__SHIFT                                       24
#define RIF_TXGAIN0_PMU__ENTRY4__WIDTH                                        6
#define RIF_TXGAIN0_PMU__ENTRY4__MASK                               0x3f000000U
#define RIF_TXGAIN0_PMU__ENTRY4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RIF_TXGAIN0_PMU__ENTRY4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RIF_TXGAIN0_PMU__ENTRY4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RIF_TXGAIN0_PMU__ENTRY4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RIF_TXGAIN0_PMU__ENTRY4__RESET_VALUE                        0x00000017U
/** @} */
#define RIF_TXGAIN0_PMU__TYPE                                          uint32_t
#define RIF_TXGAIN0_PMU__READ                                       0x3fffffffU
#define RIF_TXGAIN0_PMU__WRITE                                      0x3fffffffU
#define RIF_TXGAIN0_PMU__PRESERVED                                  0x00000000U
#define RIF_TXGAIN0_PMU__RESET_VALUE                                0x174d0300U

#endif /* __RIF_TXGAIN0_PMU_MACRO__ */

/** @} end of txgain0_pmu */

/* macros for BlueprintGlobalNameSpace::RIF_txgain1_pmu */
/**
 * @defgroup rif_regs_core_txgain1_pmu txgain1_pmu
 * @brief TX power table for pmu using VSTORE as PA supply, entries 5 to 9, paRef[5:0] definitions.
 * @{
 */
#ifndef __RIF_TXGAIN1_PMU_MACRO__
#define __RIF_TXGAIN1_PMU_MACRO__

/* macros for field entry5 */
/**
 * @defgroup rif_regs_core_entry5_field entry5_field
 * @brief macros for field entry5
 * @details TX power level entry 5, -2dBm
 * @{
 */
#define RIF_TXGAIN1_PMU__ENTRY5__SHIFT                                        0
#define RIF_TXGAIN1_PMU__ENTRY5__WIDTH                                        6
#define RIF_TXGAIN1_PMU__ENTRY5__MASK                               0x0000003fU
#define RIF_TXGAIN1_PMU__ENTRY5__READ(src)      ((uint32_t)(src) & 0x0000003fU)
#define RIF_TXGAIN1_PMU__ENTRY5__WRITE(src)     ((uint32_t)(src) & 0x0000003fU)
#define RIF_TXGAIN1_PMU__ENTRY5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RIF_TXGAIN1_PMU__ENTRY5__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define RIF_TXGAIN1_PMU__ENTRY5__RESET_VALUE                        0x0000001bU
/** @} */

/* macros for field entry6 */
/**
 * @defgroup rif_regs_core_entry6_field entry6_field
 * @brief macros for field entry6
 * @details TX power level entry 6, 0dBm
 * @{
 */
#define RIF_TXGAIN1_PMU__ENTRY6__SHIFT                                        6
#define RIF_TXGAIN1_PMU__ENTRY6__WIDTH                                        6
#define RIF_TXGAIN1_PMU__ENTRY6__MASK                               0x00000fc0U
#define RIF_TXGAIN1_PMU__ENTRY6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define RIF_TXGAIN1_PMU__ENTRY6__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define RIF_TXGAIN1_PMU__ENTRY6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define RIF_TXGAIN1_PMU__ENTRY6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define RIF_TXGAIN1_PMU__ENTRY6__RESET_VALUE                        0x00000020U
/** @} */

/* macros for field entry7 */
/**
 * @defgroup rif_regs_core_entry7_field entry7_field
 * @brief macros for field entry7
 * @details TX power level entry 7, 2dBm
 * @{
 */
#define RIF_TXGAIN1_PMU__ENTRY7__SHIFT                                       12
#define RIF_TXGAIN1_PMU__ENTRY7__WIDTH                                        6
#define RIF_TXGAIN1_PMU__ENTRY7__MASK                               0x0003f000U
#define RIF_TXGAIN1_PMU__ENTRY7__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define RIF_TXGAIN1_PMU__ENTRY7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define RIF_TXGAIN1_PMU__ENTRY7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define RIF_TXGAIN1_PMU__ENTRY7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define RIF_TXGAIN1_PMU__ENTRY7__RESET_VALUE                        0x00000024U
/** @} */

/* macros for field entry8 */
/**
 * @defgroup rif_regs_core_entry8_field entry8_field
 * @brief macros for field entry8
 * @details TX power level entry 8, 4dBm
 * @{
 */
#define RIF_TXGAIN1_PMU__ENTRY8__SHIFT                                       18
#define RIF_TXGAIN1_PMU__ENTRY8__WIDTH                                        6
#define RIF_TXGAIN1_PMU__ENTRY8__MASK                               0x00fc0000U
#define RIF_TXGAIN1_PMU__ENTRY8__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define RIF_TXGAIN1_PMU__ENTRY8__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define RIF_TXGAIN1_PMU__ENTRY8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define RIF_TXGAIN1_PMU__ENTRY8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define RIF_TXGAIN1_PMU__ENTRY8__RESET_VALUE                        0x0000002aU
/** @} */

/* macros for field entry9 */
/**
 * @defgroup rif_regs_core_entry9_field entry9_field
 * @brief macros for field entry9
 * @details TX power level entry 9, 6dBm
 * @{
 */
#define RIF_TXGAIN1_PMU__ENTRY9__SHIFT                                       24
#define RIF_TXGAIN1_PMU__ENTRY9__WIDTH                                        6
#define RIF_TXGAIN1_PMU__ENTRY9__MASK                               0x3f000000U
#define RIF_TXGAIN1_PMU__ENTRY9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RIF_TXGAIN1_PMU__ENTRY9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RIF_TXGAIN1_PMU__ENTRY9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RIF_TXGAIN1_PMU__ENTRY9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RIF_TXGAIN1_PMU__ENTRY9__RESET_VALUE                        0x00000030U
/** @} */
#define RIF_TXGAIN1_PMU__TYPE                                          uint32_t
#define RIF_TXGAIN1_PMU__READ                                       0x3fffffffU
#define RIF_TXGAIN1_PMU__WRITE                                      0x3fffffffU
#define RIF_TXGAIN1_PMU__PRESERVED                                  0x00000000U
#define RIF_TXGAIN1_PMU__RESET_VALUE                                0x30aa481bU

#endif /* __RIF_TXGAIN1_PMU_MACRO__ */

/** @} end of txgain1_pmu */

/* macros for BlueprintGlobalNameSpace::RIF_txgain2_pmu */
/**
 * @defgroup rif_regs_core_txgain2_pmu txgain2_pmu
 * @brief TX power table for pmu using VSTORE as PA supply, entries 10 to 11, paRef[5:0] definitions.
 * @{
 */
#ifndef __RIF_TXGAIN2_PMU_MACRO__
#define __RIF_TXGAIN2_PMU_MACRO__

/* macros for field entry10 */
/**
 * @defgroup rif_regs_core_entry10_field entry10_field
 * @brief macros for field entry10
 * @details TX power level entry 10, 8dBm
 * @{
 */
#define RIF_TXGAIN2_PMU__ENTRY10__SHIFT                                       0
#define RIF_TXGAIN2_PMU__ENTRY10__WIDTH                                       6
#define RIF_TXGAIN2_PMU__ENTRY10__MASK                              0x0000003fU
#define RIF_TXGAIN2_PMU__ENTRY10__READ(src)     ((uint32_t)(src) & 0x0000003fU)
#define RIF_TXGAIN2_PMU__ENTRY10__WRITE(src)    ((uint32_t)(src) & 0x0000003fU)
#define RIF_TXGAIN2_PMU__ENTRY10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RIF_TXGAIN2_PMU__ENTRY10__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define RIF_TXGAIN2_PMU__ENTRY10__RESET_VALUE                       0x00000037U
/** @} */

/* macros for field entry11 */
/**
 * @defgroup rif_regs_core_entry11_field entry11_field
 * @brief macros for field entry11
 * @details TX power level entry 11, extra
 * @{
 */
#define RIF_TXGAIN2_PMU__ENTRY11__SHIFT                                       6
#define RIF_TXGAIN2_PMU__ENTRY11__WIDTH                                       6
#define RIF_TXGAIN2_PMU__ENTRY11__MASK                              0x00000fc0U
#define RIF_TXGAIN2_PMU__ENTRY11__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define RIF_TXGAIN2_PMU__ENTRY11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define RIF_TXGAIN2_PMU__ENTRY11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define RIF_TXGAIN2_PMU__ENTRY11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define RIF_TXGAIN2_PMU__ENTRY11__RESET_VALUE                       0x0000003fU
/** @} */

/* macros for field paRefLoDvdd */
/**
 * @defgroup rif_regs_core_paRefLoDvdd_field paRefLoDvdd_field
 * @brief macros for field paRefLoDvdd
 * @details Reference level from AVDD or DVDD
 * @{
 */
#define RIF_TXGAIN2_PMU__PAREFLODVDD__SHIFT                                  18
#define RIF_TXGAIN2_PMU__PAREFLODVDD__WIDTH                                   1
#define RIF_TXGAIN2_PMU__PAREFLODVDD__MASK                          0x00040000U
#define RIF_TXGAIN2_PMU__PAREFLODVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define RIF_TXGAIN2_PMU__PAREFLODVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define RIF_TXGAIN2_PMU__PAREFLODVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define RIF_TXGAIN2_PMU__PAREFLODVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define RIF_TXGAIN2_PMU__PAREFLODVDD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define RIF_TXGAIN2_PMU__PAREFLODVDD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define RIF_TXGAIN2_PMU__PAREFLODVDD__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field paRefHi */
/**
 * @defgroup rif_regs_core_paRefHi_field paRefHi_field
 * @brief macros for field paRefHi
 * @details Reference level from VDDIO
 * @{
 */
#define RIF_TXGAIN2_PMU__PAREFHI__SHIFT                                      19
#define RIF_TXGAIN2_PMU__PAREFHI__WIDTH                                       1
#define RIF_TXGAIN2_PMU__PAREFHI__MASK                              0x00080000U
#define RIF_TXGAIN2_PMU__PAREFHI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define RIF_TXGAIN2_PMU__PAREFHI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define RIF_TXGAIN2_PMU__PAREFHI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define RIF_TXGAIN2_PMU__PAREFHI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define RIF_TXGAIN2_PMU__PAREFHI__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define RIF_TXGAIN2_PMU__PAREFHI__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define RIF_TXGAIN2_PMU__PAREFHI__RESET_VALUE                       0x00000001U
/** @} */
#define RIF_TXGAIN2_PMU__TYPE                                          uint32_t
#define RIF_TXGAIN2_PMU__READ                                       0x000c0fffU
#define RIF_TXGAIN2_PMU__WRITE                                      0x000c0fffU
#define RIF_TXGAIN2_PMU__PRESERVED                                  0x00000000U
#define RIF_TXGAIN2_PMU__RESET_VALUE                                0x00080ff7U

#endif /* __RIF_TXGAIN2_PMU_MACRO__ */

/** @} end of txgain2_pmu */

/* macros for BlueprintGlobalNameSpace::RIF_rx0 */
/**
 * @defgroup rif_regs_core_rx0 rx0
 * @brief Contains register fields associated with rx0. definitions.
 * @{
 */
#ifndef __RIF_RX0_MACRO__
#define __RIF_RX0_MACRO__

/* macros for field lna_bias */
/**
 * @defgroup rif_regs_core_lna_bias_field lna_bias_field
 * @brief macros for field lna_bias
 * @details LNA bias current
 * @{
 */
#define RIF_RX0__LNA_BIAS__SHIFT                                              0
#define RIF_RX0__LNA_BIAS__WIDTH                                              5
#define RIF_RX0__LNA_BIAS__MASK                                     0x0000001fU
#define RIF_RX0__LNA_BIAS__READ(src)            ((uint32_t)(src) & 0x0000001fU)
#define RIF_RX0__LNA_BIAS__WRITE(src)           ((uint32_t)(src) & 0x0000001fU)
#define RIF_RX0__LNA_BIAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define RIF_RX0__LNA_BIAS__VERIFY(src)    (!(((uint32_t)(src) & ~0x0000001fU)))
#define RIF_RX0__LNA_BIAS__RESET_VALUE                              0x0000000fU
/** @} */

/* macros for field lnapd_gain */
/**
 * @defgroup rif_regs_core_lnapd_gain_field lnapd_gain_field
 * @brief macros for field lnapd_gain
 * @details LNA peak detector gain
 * @{
 */
#define RIF_RX0__LNAPD_GAIN__SHIFT                                            5
#define RIF_RX0__LNAPD_GAIN__WIDTH                                            2
#define RIF_RX0__LNAPD_GAIN__MASK                                   0x00000060U
#define RIF_RX0__LNAPD_GAIN__READ(src)   (((uint32_t)(src) & 0x00000060U) >> 5)
#define RIF_RX0__LNAPD_GAIN__WRITE(src)  (((uint32_t)(src) << 5) & 0x00000060U)
#define RIF_RX0__LNAPD_GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define RIF_RX0__LNAPD_GAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define RIF_RX0__LNAPD_GAIN__RESET_VALUE                            0x00000002U
/** @} */

/* macros for field lnapd_reflvl */
/**
 * @defgroup rif_regs_core_lnapd_reflvl_field lnapd_reflvl_field
 * @brief macros for field lnapd_reflvl
 * @details LNA peak detector reference level
 * @{
 */
#define RIF_RX0__LNAPD_REFLVL__SHIFT                                          7
#define RIF_RX0__LNAPD_REFLVL__WIDTH                                          4
#define RIF_RX0__LNAPD_REFLVL__MASK                                 0x00000780U
#define RIF_RX0__LNAPD_REFLVL__READ(src) (((uint32_t)(src) & 0x00000780U) >> 7)
#define RIF_RX0__LNAPD_REFLVL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define RIF_RX0__LNAPD_REFLVL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define RIF_RX0__LNAPD_REFLVL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define RIF_RX0__LNAPD_REFLVL__RESET_VALUE                          0x00000008U
/** @} */

/* macros for field lna_off_attn_in */
/**
 * @defgroup rif_regs_core_lna_off_attn_in_field lna_off_attn_in_field
 * @brief macros for field lna_off_attn_in
 * @details LNA off input attenuation setting
 * @{
 */
#define RIF_RX0__LNA_OFF_ATTN_IN__SHIFT                                      11
#define RIF_RX0__LNA_OFF_ATTN_IN__WIDTH                                       2
#define RIF_RX0__LNA_OFF_ATTN_IN__MASK                              0x00001800U
#define RIF_RX0__LNA_OFF_ATTN_IN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001800U) >> 11)
#define RIF_RX0__LNA_OFF_ATTN_IN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00001800U)
#define RIF_RX0__LNA_OFF_ATTN_IN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001800U) | (((uint32_t)(src) <<\
                    11) & 0x00001800U)
#define RIF_RX0__LNA_OFF_ATTN_IN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00001800U)))
#define RIF_RX0__LNA_OFF_ATTN_IN__RESET_VALUE                       0x00000002U
/** @} */

/* macros for field lna_off_attn_out */
/**
 * @defgroup rif_regs_core_lna_off_attn_out_field lna_off_attn_out_field
 * @brief macros for field lna_off_attn_out
 * @details LNA off output attenuation setting
 * @{
 */
#define RIF_RX0__LNA_OFF_ATTN_OUT__SHIFT                                     13
#define RIF_RX0__LNA_OFF_ATTN_OUT__WIDTH                                      1
#define RIF_RX0__LNA_OFF_ATTN_OUT__MASK                             0x00002000U
#define RIF_RX0__LNA_OFF_ATTN_OUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define RIF_RX0__LNA_OFF_ATTN_OUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define RIF_RX0__LNA_OFF_ATTN_OUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define RIF_RX0__LNA_OFF_ATTN_OUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define RIF_RX0__LNA_OFF_ATTN_OUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define RIF_RX0__LNA_OFF_ATTN_OUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define RIF_RX0__LNA_OFF_ATTN_OUT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field lna_on_attn_in */
/**
 * @defgroup rif_regs_core_lna_on_attn_in_field lna_on_attn_in_field
 * @brief macros for field lna_on_attn_in
 * @details LNA on min gain input attenuation setting
 * @{
 */
#define RIF_RX0__LNA_ON_ATTN_IN__SHIFT                                       14
#define RIF_RX0__LNA_ON_ATTN_IN__WIDTH                                        2
#define RIF_RX0__LNA_ON_ATTN_IN__MASK                               0x0000c000U
#define RIF_RX0__LNA_ON_ATTN_IN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000c000U) >> 14)
#define RIF_RX0__LNA_ON_ATTN_IN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0000c000U)
#define RIF_RX0__LNA_ON_ATTN_IN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define RIF_RX0__LNA_ON_ATTN_IN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define RIF_RX0__LNA_ON_ATTN_IN__RESET_VALUE                        0x00000003U
/** @} */

/* macros for field sel_icpga */
/**
 * @defgroup rif_regs_core_sel_icpga_field sel_icpga_field
 * @brief macros for field sel_icpga
 * @details PGA bias current
 * @{
 */
#define RIF_RX0__SEL_ICPGA__SHIFT                                            16
#define RIF_RX0__SEL_ICPGA__WIDTH                                             4
#define RIF_RX0__SEL_ICPGA__MASK                                    0x000f0000U
#define RIF_RX0__SEL_ICPGA__READ(src)   (((uint32_t)(src) & 0x000f0000U) >> 16)
#define RIF_RX0__SEL_ICPGA__WRITE(src)  (((uint32_t)(src) << 16) & 0x000f0000U)
#define RIF_RX0__SEL_ICPGA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RIF_RX0__SEL_ICPGA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define RIF_RX0__SEL_ICPGA__RESET_VALUE                             0x00000003U
/** @} */

/* macros for field vcm_ctrl */
/**
 * @defgroup rif_regs_core_vcm_ctrl_field vcm_ctrl_field
 * @brief macros for field vcm_ctrl
 * @details Adjusts the common-mode reference voltage to TIA and PGA op-amps, 0=510mV, 1=550mV, 2=590mV, 3=630mV, 4=650mV, 5=670mV, 6=690mV, 7=710mV
 * @{
 */
#define RIF_RX0__VCM_CTRL__SHIFT                                             20
#define RIF_RX0__VCM_CTRL__WIDTH                                              3
#define RIF_RX0__VCM_CTRL__MASK                                     0x00700000U
#define RIF_RX0__VCM_CTRL__READ(src)    (((uint32_t)(src) & 0x00700000U) >> 20)
#define RIF_RX0__VCM_CTRL__WRITE(src)   (((uint32_t)(src) << 20) & 0x00700000U)
#define RIF_RX0__VCM_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00700000U) | (((uint32_t)(src) <<\
                    20) & 0x00700000U)
#define RIF_RX0__VCM_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00700000U)))
#define RIF_RX0__VCM_CTRL__RESET_VALUE                              0x00000004U
/** @} */

/* macros for field bb1_dcoc_extra_en */
/**
 * @defgroup rif_regs_core_bb1_dcoc_extra_en_field bb1_dcoc_extra_en_field
 * @brief macros for field bb1_dcoc_extra_en
 * @details Enable extra TIA DC offset DAC MSBs, [0] = enable bit 6, [1] = enable bit 7
 * @{
 */
#define RIF_RX0__BB1_DCOC_EXTRA_EN__SHIFT                                    23
#define RIF_RX0__BB1_DCOC_EXTRA_EN__WIDTH                                     2
#define RIF_RX0__BB1_DCOC_EXTRA_EN__MASK                            0x01800000U
#define RIF_RX0__BB1_DCOC_EXTRA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01800000U) >> 23)
#define RIF_RX0__BB1_DCOC_EXTRA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x01800000U)
#define RIF_RX0__BB1_DCOC_EXTRA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01800000U) | (((uint32_t)(src) <<\
                    23) & 0x01800000U)
#define RIF_RX0__BB1_DCOC_EXTRA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x01800000U)))
#define RIF_RX0__BB1_DCOC_EXTRA_EN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field hadm_lp */
/**
 * @defgroup rif_regs_core_hadm_lp_field hadm_lp_field
 * @brief macros for field hadm_lp
 * @details Selects RXLO mode for HADM, 0=PMODE_SINGLE, 1=PMODE_LP_SINGLE
 * @{
 */
#define RIF_RX0__HADM_LP__SHIFT                                              25
#define RIF_RX0__HADM_LP__WIDTH                                               1
#define RIF_RX0__HADM_LP__MASK                                      0x02000000U
#define RIF_RX0__HADM_LP__READ(src)     (((uint32_t)(src) & 0x02000000U) >> 25)
#define RIF_RX0__HADM_LP__WRITE(src)    (((uint32_t)(src) << 25) & 0x02000000U)
#define RIF_RX0__HADM_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define RIF_RX0__HADM_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define RIF_RX0__HADM_LP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define RIF_RX0__HADM_LP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define RIF_RX0__HADM_LP__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field rx_sparebits */
/**
 * @defgroup rif_regs_core_rx_sparebits_field rx_sparebits_field
 * @brief macros for field rx_sparebits
 * @details spare bits
 * @{
 */
#define RIF_RX0__RX_SPAREBITS__SHIFT                                         26
#define RIF_RX0__RX_SPAREBITS__WIDTH                                          4
#define RIF_RX0__RX_SPAREBITS__MASK                                 0x3c000000U
#define RIF_RX0__RX_SPAREBITS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3c000000U) >> 26)
#define RIF_RX0__RX_SPAREBITS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x3c000000U)
#define RIF_RX0__RX_SPAREBITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3c000000U) | (((uint32_t)(src) <<\
                    26) & 0x3c000000U)
#define RIF_RX0__RX_SPAREBITS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x3c000000U)))
#define RIF_RX0__RX_SPAREBITS__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field lna_protect_ovr */
/**
 * @defgroup rif_regs_core_lna_protect_ovr_field lna_protect_ovr_field
 * @brief macros for field lna_protect_ovr
 * @details Force override of lna_protect signal, MSB is override control, LSB is override value
 * @{
 */
#define RIF_RX0__LNA_PROTECT_OVR__SHIFT                                      30
#define RIF_RX0__LNA_PROTECT_OVR__WIDTH                                       2
#define RIF_RX0__LNA_PROTECT_OVR__MASK                              0xc0000000U
#define RIF_RX0__LNA_PROTECT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define RIF_RX0__LNA_PROTECT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define RIF_RX0__LNA_PROTECT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define RIF_RX0__LNA_PROTECT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define RIF_RX0__LNA_PROTECT_OVR__RESET_VALUE                       0x00000000U
/** @} */
#define RIF_RX0__TYPE                                                  uint32_t
#define RIF_RX0__READ                                               0xffffffffU
#define RIF_RX0__WRITE                                              0xffffffffU
#define RIF_RX0__PRESERVED                                          0x00000000U
#define RIF_RX0__RESET_VALUE                                        0x0043d44fU

#endif /* __RIF_RX0_MACRO__ */

/** @} end of rx0 */

/* macros for BlueprintGlobalNameSpace::RIF_timer0 */
/**
 * @defgroup rif_regs_core_timer0 timer0
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_TIMER0_MACRO__
#define __RIF_TIMER0_MACRO__

/* macros for field synthon_time */
/**
 * @defgroup rif_regs_core_synthon_time_field synthon_time_field
 * @brief macros for field synthon_time
 * @details Triggered by rising tx_en or rx_en
 * @{
 */
#define RIF_TIMER0__SYNTHON_TIME__SHIFT                                       0
#define RIF_TIMER0__SYNTHON_TIME__WIDTH                                      10
#define RIF_TIMER0__SYNTHON_TIME__MASK                              0x000003ffU
#define RIF_TIMER0__SYNTHON_TIME__READ(src)     ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER0__SYNTHON_TIME__WRITE(src)    ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER0__SYNTHON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_TIMER0__SYNTHON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_TIMER0__SYNTHON_TIME__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field synthoff_time */
/**
 * @defgroup rif_regs_core_synthoff_time_field synthoff_time_field
 * @brief macros for field synthoff_time
 * @details Triggered by falling tx_en or rx_en
 * @{
 */
#define RIF_TIMER0__SYNTHOFF_TIME__SHIFT                                     10
#define RIF_TIMER0__SYNTHOFF_TIME__WIDTH                                      6
#define RIF_TIMER0__SYNTHOFF_TIME__MASK                             0x0000fc00U
#define RIF_TIMER0__SYNTHOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_TIMER0__SYNTHOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_TIMER0__SYNTHOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_TIMER0__SYNTHOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_TIMER0__SYNTHOFF_TIME__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field txon_time */
/**
 * @defgroup rif_regs_core_txon_time_field txon_time_field
 * @brief macros for field txon_time
 * @details Triggered by rising tx_en
 * @{
 */
#define RIF_TIMER0__TXON_TIME__SHIFT                                         16
#define RIF_TIMER0__TXON_TIME__WIDTH                                         10
#define RIF_TIMER0__TXON_TIME__MASK                                 0x03ff0000U
#define RIF_TIMER0__TXON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_TIMER0__TXON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_TIMER0__TXON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_TIMER0__TXON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_TIMER0__TXON_TIME__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field txoff_time */
/**
 * @defgroup rif_regs_core_txoff_time_field txoff_time_field
 * @brief macros for field txoff_time
 * @details Triggered by falling tx_en
 * @{
 */
#define RIF_TIMER0__TXOFF_TIME__SHIFT                                        26
#define RIF_TIMER0__TXOFF_TIME__WIDTH                                         6
#define RIF_TIMER0__TXOFF_TIME__MASK                                0xfc000000U
#define RIF_TIMER0__TXOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_TIMER0__TXOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_TIMER0__TXOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_TIMER0__TXOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_TIMER0__TXOFF_TIME__RESET_VALUE                         0x00000002U
/** @} */
#define RIF_TIMER0__TYPE                                               uint32_t
#define RIF_TIMER0__READ                                            0xffffffffU
#define RIF_TIMER0__WRITE                                           0xffffffffU
#define RIF_TIMER0__PRESERVED                                       0x00000000U
#define RIF_TIMER0__RESET_VALUE                                     0x08000401U

#endif /* __RIF_TIMER0_MACRO__ */

/** @} end of timer0 */

/* macros for BlueprintGlobalNameSpace::RIF_timer1 */
/**
 * @defgroup rif_regs_core_timer1 timer1
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_TIMER1_MACRO__
#define __RIF_TIMER1_MACRO__

/* macros for field paon_time */
/**
 * @defgroup rif_regs_core_paon_time_field paon_time_field
 * @brief macros for field paon_time
 * @details Triggered by rising tx_en
 * @{
 */
#define RIF_TIMER1__PAON_TIME__SHIFT                                          0
#define RIF_TIMER1__PAON_TIME__WIDTH                                         10
#define RIF_TIMER1__PAON_TIME__MASK                                 0x000003ffU
#define RIF_TIMER1__PAON_TIME__READ(src)        ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER1__PAON_TIME__WRITE(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER1__PAON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_TIMER1__PAON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_TIMER1__PAON_TIME__RESET_VALUE                          0x00000168U
/** @} */

/* macros for field paoff_time */
/**
 * @defgroup rif_regs_core_paoff_time_field paoff_time_field
 * @brief macros for field paoff_time
 * @details Triggered by falling tx_en
 * @{
 */
#define RIF_TIMER1__PAOFF_TIME__SHIFT                                        10
#define RIF_TIMER1__PAOFF_TIME__WIDTH                                         6
#define RIF_TIMER1__PAOFF_TIME__MASK                                0x0000fc00U
#define RIF_TIMER1__PAOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_TIMER1__PAOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_TIMER1__PAOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_TIMER1__PAOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_TIMER1__PAOFF_TIME__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field rxon_time */
/**
 * @defgroup rif_regs_core_rxon_time_field rxon_time_field
 * @brief macros for field rxon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_TIMER1__RXON_TIME__SHIFT                                         16
#define RIF_TIMER1__RXON_TIME__WIDTH                                         10
#define RIF_TIMER1__RXON_TIME__MASK                                 0x03ff0000U
#define RIF_TIMER1__RXON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_TIMER1__RXON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_TIMER1__RXON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_TIMER1__RXON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_TIMER1__RXON_TIME__RESET_VALUE                          0x00000190U
/** @} */

/* macros for field rxoff_time */
/**
 * @defgroup rif_regs_core_rxoff_time_field rxoff_time_field
 * @brief macros for field rxoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_TIMER1__RXOFF_TIME__SHIFT                                        26
#define RIF_TIMER1__RXOFF_TIME__WIDTH                                         6
#define RIF_TIMER1__RXOFF_TIME__MASK                                0xfc000000U
#define RIF_TIMER1__RXOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_TIMER1__RXOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_TIMER1__RXOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_TIMER1__RXOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_TIMER1__RXOFF_TIME__RESET_VALUE                         0x00000000U
/** @} */
#define RIF_TIMER1__TYPE                                               uint32_t
#define RIF_TIMER1__READ                                            0xffffffffU
#define RIF_TIMER1__WRITE                                           0xffffffffU
#define RIF_TIMER1__PRESERVED                                       0x00000000U
#define RIF_TIMER1__RESET_VALUE                                     0x01900168U

#endif /* __RIF_TIMER1_MACRO__ */

/** @} end of timer1 */

/* macros for BlueprintGlobalNameSpace::RIF_timer2 */
/**
 * @defgroup rif_regs_core_timer2 timer2
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_TIMER2_MACRO__
#define __RIF_TIMER2_MACRO__

/* macros for field adcon_time */
/**
 * @defgroup rif_regs_core_adcon_time_field adcon_time_field
 * @brief macros for field adcon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_TIMER2__ADCON_TIME__SHIFT                                         0
#define RIF_TIMER2__ADCON_TIME__WIDTH                                        10
#define RIF_TIMER2__ADCON_TIME__MASK                                0x000003ffU
#define RIF_TIMER2__ADCON_TIME__READ(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER2__ADCON_TIME__WRITE(src)      ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER2__ADCON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_TIMER2__ADCON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_TIMER2__ADCON_TIME__RESET_VALUE                         0x0000017cU
/** @} */

/* macros for field adcoff_time */
/**
 * @defgroup rif_regs_core_adcoff_time_field adcoff_time_field
 * @brief macros for field adcoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_TIMER2__ADCOFF_TIME__SHIFT                                       10
#define RIF_TIMER2__ADCOFF_TIME__WIDTH                                        6
#define RIF_TIMER2__ADCOFF_TIME__MASK                               0x0000fc00U
#define RIF_TIMER2__ADCOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_TIMER2__ADCOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_TIMER2__ADCOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_TIMER2__ADCOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_TIMER2__ADCOFF_TIME__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field adcearlyon_time */
/**
 * @defgroup rif_regs_core_adcearlyon_time_field adcearlyon_time_field
 * @brief macros for field adcearlyon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_TIMER2__ADCEARLYON_TIME__SHIFT                                   16
#define RIF_TIMER2__ADCEARLYON_TIME__WIDTH                                   10
#define RIF_TIMER2__ADCEARLYON_TIME__MASK                           0x03ff0000U
#define RIF_TIMER2__ADCEARLYON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_TIMER2__ADCEARLYON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_TIMER2__ADCEARLYON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_TIMER2__ADCEARLYON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_TIMER2__ADCEARLYON_TIME__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field adcearlyoff_time */
/**
 * @defgroup rif_regs_core_adcearlyoff_time_field adcearlyoff_time_field
 * @brief macros for field adcearlyoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_TIMER2__ADCEARLYOFF_TIME__SHIFT                                  26
#define RIF_TIMER2__ADCEARLYOFF_TIME__WIDTH                                   6
#define RIF_TIMER2__ADCEARLYOFF_TIME__MASK                          0xfc000000U
#define RIF_TIMER2__ADCEARLYOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_TIMER2__ADCEARLYOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_TIMER2__ADCEARLYOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_TIMER2__ADCEARLYOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_TIMER2__ADCEARLYOFF_TIME__RESET_VALUE                   0x00000000U
/** @} */
#define RIF_TIMER2__TYPE                                               uint32_t
#define RIF_TIMER2__READ                                            0xffffffffU
#define RIF_TIMER2__WRITE                                           0xffffffffU
#define RIF_TIMER2__PRESERVED                                       0x00000000U
#define RIF_TIMER2__RESET_VALUE                                     0x0000017cU

#endif /* __RIF_TIMER2_MACRO__ */

/** @} end of timer2 */

/* macros for BlueprintGlobalNameSpace::RIF_timer3 */
/**
 * @defgroup rif_regs_core_timer3 timer3
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_TIMER3_MACRO__
#define __RIF_TIMER3_MACRO__

/* macros for field xpaon_time */
/**
 * @defgroup rif_regs_core_xpaon_time_field xpaon_time_field
 * @brief macros for field xpaon_time
 * @details Triggered by rising tx_en
 * @{
 */
#define RIF_TIMER3__XPAON_TIME__SHIFT                                         0
#define RIF_TIMER3__XPAON_TIME__WIDTH                                        10
#define RIF_TIMER3__XPAON_TIME__MASK                                0x000003ffU
#define RIF_TIMER3__XPAON_TIME__READ(src)       ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER3__XPAON_TIME__WRITE(src)      ((uint32_t)(src) & 0x000003ffU)
#define RIF_TIMER3__XPAON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_TIMER3__XPAON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_TIMER3__XPAON_TIME__RESET_VALUE                         0x00000168U
/** @} */

/* macros for field xpaoff_time */
/**
 * @defgroup rif_regs_core_xpaoff_time_field xpaoff_time_field
 * @brief macros for field xpaoff_time
 * @details Triggered by falling tx_en
 * @{
 */
#define RIF_TIMER3__XPAOFF_TIME__SHIFT                                       10
#define RIF_TIMER3__XPAOFF_TIME__WIDTH                                        6
#define RIF_TIMER3__XPAOFF_TIME__MASK                               0x0000fc00U
#define RIF_TIMER3__XPAOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_TIMER3__XPAOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_TIMER3__XPAOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_TIMER3__XPAOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_TIMER3__XPAOFF_TIME__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field xlnaon_time */
/**
 * @defgroup rif_regs_core_xlnaon_time_field xlnaon_time_field
 * @brief macros for field xlnaon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_TIMER3__XLNAON_TIME__SHIFT                                       16
#define RIF_TIMER3__XLNAON_TIME__WIDTH                                       10
#define RIF_TIMER3__XLNAON_TIME__MASK                               0x03ff0000U
#define RIF_TIMER3__XLNAON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_TIMER3__XLNAON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_TIMER3__XLNAON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_TIMER3__XLNAON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_TIMER3__XLNAON_TIME__RESET_VALUE                        0x00000190U
/** @} */

/* macros for field xlnaoff_time */
/**
 * @defgroup rif_regs_core_xlnaoff_time_field xlnaoff_time_field
 * @brief macros for field xlnaoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_TIMER3__XLNAOFF_TIME__SHIFT                                      26
#define RIF_TIMER3__XLNAOFF_TIME__WIDTH                                       6
#define RIF_TIMER3__XLNAOFF_TIME__MASK                              0xfc000000U
#define RIF_TIMER3__XLNAOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_TIMER3__XLNAOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_TIMER3__XLNAOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_TIMER3__XLNAOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_TIMER3__XLNAOFF_TIME__RESET_VALUE                       0x00000000U
/** @} */
#define RIF_TIMER3__TYPE                                               uint32_t
#define RIF_TIMER3__READ                                            0xffffffffU
#define RIF_TIMER3__WRITE                                           0xffffffffU
#define RIF_TIMER3__PRESERVED                                       0x00000000U
#define RIF_TIMER3__RESET_VALUE                                     0x01900168U

#endif /* __RIF_TIMER3_MACRO__ */

/** @} end of timer3 */

/* macros for BlueprintGlobalNameSpace::RIF_hadm_timer0 */
/**
 * @defgroup rif_regs_core_hadm_timer0 hadm_timer0
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_HADM_TIMER0_MACRO__
#define __RIF_HADM_TIMER0_MACRO__

/* macros for field synthon_time */
/**
 * @defgroup rif_regs_core_synthon_time_field synthon_time_field
 * @brief macros for field synthon_time
 * @details Triggered by rising tx_en or rx_en
 * @{
 */
#define RIF_HADM_TIMER0__SYNTHON_TIME__SHIFT                                  0
#define RIF_HADM_TIMER0__SYNTHON_TIME__WIDTH                                 10
#define RIF_HADM_TIMER0__SYNTHON_TIME__MASK                         0x000003ffU
#define RIF_HADM_TIMER0__SYNTHON_TIME__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define RIF_HADM_TIMER0__SYNTHON_TIME__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define RIF_HADM_TIMER0__SYNTHON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_HADM_TIMER0__SYNTHON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_HADM_TIMER0__SYNTHON_TIME__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field synthoff_time */
/**
 * @defgroup rif_regs_core_synthoff_time_field synthoff_time_field
 * @brief macros for field synthoff_time
 * @details Triggered by falling tx_en or rx_en
 * @{
 */
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__SHIFT                                10
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__WIDTH                                 6
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__MASK                        0x0000fc00U
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_HADM_TIMER0__SYNTHOFF_TIME__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field txon_time */
/**
 * @defgroup rif_regs_core_txon_time_field txon_time_field
 * @brief macros for field txon_time
 * @details Triggered by rising tx_en
 * @{
 */
#define RIF_HADM_TIMER0__TXON_TIME__SHIFT                                    16
#define RIF_HADM_TIMER0__TXON_TIME__WIDTH                                    10
#define RIF_HADM_TIMER0__TXON_TIME__MASK                            0x03ff0000U
#define RIF_HADM_TIMER0__TXON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_HADM_TIMER0__TXON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_HADM_TIMER0__TXON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_HADM_TIMER0__TXON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_HADM_TIMER0__TXON_TIME__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field txoff_time */
/**
 * @defgroup rif_regs_core_txoff_time_field txoff_time_field
 * @brief macros for field txoff_time
 * @details Triggered by falling tx_en
 * @{
 */
#define RIF_HADM_TIMER0__TXOFF_TIME__SHIFT                                   26
#define RIF_HADM_TIMER0__TXOFF_TIME__WIDTH                                    6
#define RIF_HADM_TIMER0__TXOFF_TIME__MASK                           0xfc000000U
#define RIF_HADM_TIMER0__TXOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_HADM_TIMER0__TXOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_HADM_TIMER0__TXOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_HADM_TIMER0__TXOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_HADM_TIMER0__TXOFF_TIME__RESET_VALUE                    0x00000002U
/** @} */
#define RIF_HADM_TIMER0__TYPE                                          uint32_t
#define RIF_HADM_TIMER0__READ                                       0xffffffffU
#define RIF_HADM_TIMER0__WRITE                                      0xffffffffU
#define RIF_HADM_TIMER0__PRESERVED                                  0x00000000U
#define RIF_HADM_TIMER0__RESET_VALUE                                0x08000401U

#endif /* __RIF_HADM_TIMER0_MACRO__ */

/** @} end of hadm_timer0 */

/* macros for BlueprintGlobalNameSpace::RIF_hadm_timer1 */
/**
 * @defgroup rif_regs_core_hadm_timer1 hadm_timer1
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_HADM_TIMER1_MACRO__
#define __RIF_HADM_TIMER1_MACRO__

/* macros for field paon_time */
/**
 * @defgroup rif_regs_core_paon_time_field paon_time_field
 * @brief macros for field paon_time
 * @details Triggered by rising tx_en
 * @{
 */
#define RIF_HADM_TIMER1__PAON_TIME__SHIFT                                     0
#define RIF_HADM_TIMER1__PAON_TIME__WIDTH                                    10
#define RIF_HADM_TIMER1__PAON_TIME__MASK                            0x000003ffU
#define RIF_HADM_TIMER1__PAON_TIME__READ(src)   ((uint32_t)(src) & 0x000003ffU)
#define RIF_HADM_TIMER1__PAON_TIME__WRITE(src)  ((uint32_t)(src) & 0x000003ffU)
#define RIF_HADM_TIMER1__PAON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_HADM_TIMER1__PAON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_HADM_TIMER1__PAON_TIME__RESET_VALUE                     0x00000168U
/** @} */

/* macros for field paoff_time */
/**
 * @defgroup rif_regs_core_paoff_time_field paoff_time_field
 * @brief macros for field paoff_time
 * @details Triggered by falling tx_en
 * @{
 */
#define RIF_HADM_TIMER1__PAOFF_TIME__SHIFT                                   10
#define RIF_HADM_TIMER1__PAOFF_TIME__WIDTH                                    6
#define RIF_HADM_TIMER1__PAOFF_TIME__MASK                           0x0000fc00U
#define RIF_HADM_TIMER1__PAOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_HADM_TIMER1__PAOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_HADM_TIMER1__PAOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_HADM_TIMER1__PAOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_HADM_TIMER1__PAOFF_TIME__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field rxon_time */
/**
 * @defgroup rif_regs_core_rxon_time_field rxon_time_field
 * @brief macros for field rxon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_HADM_TIMER1__RXON_TIME__SHIFT                                    16
#define RIF_HADM_TIMER1__RXON_TIME__WIDTH                                    10
#define RIF_HADM_TIMER1__RXON_TIME__MASK                            0x03ff0000U
#define RIF_HADM_TIMER1__RXON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_HADM_TIMER1__RXON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_HADM_TIMER1__RXON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_HADM_TIMER1__RXON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_HADM_TIMER1__RXON_TIME__RESET_VALUE                     0x00000190U
/** @} */

/* macros for field rxoff_time */
/**
 * @defgroup rif_regs_core_rxoff_time_field rxoff_time_field
 * @brief macros for field rxoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_HADM_TIMER1__RXOFF_TIME__SHIFT                                   26
#define RIF_HADM_TIMER1__RXOFF_TIME__WIDTH                                    6
#define RIF_HADM_TIMER1__RXOFF_TIME__MASK                           0xfc000000U
#define RIF_HADM_TIMER1__RXOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_HADM_TIMER1__RXOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_HADM_TIMER1__RXOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_HADM_TIMER1__RXOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_HADM_TIMER1__RXOFF_TIME__RESET_VALUE                    0x00000000U
/** @} */
#define RIF_HADM_TIMER1__TYPE                                          uint32_t
#define RIF_HADM_TIMER1__READ                                       0xffffffffU
#define RIF_HADM_TIMER1__WRITE                                      0xffffffffU
#define RIF_HADM_TIMER1__PRESERVED                                  0x00000000U
#define RIF_HADM_TIMER1__RESET_VALUE                                0x01900168U

#endif /* __RIF_HADM_TIMER1_MACRO__ */

/** @} end of hadm_timer1 */

/* macros for BlueprintGlobalNameSpace::RIF_hadm_timer2 */
/**
 * @defgroup rif_regs_core_hadm_timer2 hadm_timer2
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_HADM_TIMER2_MACRO__
#define __RIF_HADM_TIMER2_MACRO__

/* macros for field adcon_time */
/**
 * @defgroup rif_regs_core_adcon_time_field adcon_time_field
 * @brief macros for field adcon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_HADM_TIMER2__ADCON_TIME__SHIFT                                    0
#define RIF_HADM_TIMER2__ADCON_TIME__WIDTH                                   10
#define RIF_HADM_TIMER2__ADCON_TIME__MASK                           0x000003ffU
#define RIF_HADM_TIMER2__ADCON_TIME__READ(src)  ((uint32_t)(src) & 0x000003ffU)
#define RIF_HADM_TIMER2__ADCON_TIME__WRITE(src) ((uint32_t)(src) & 0x000003ffU)
#define RIF_HADM_TIMER2__ADCON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_HADM_TIMER2__ADCON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_HADM_TIMER2__ADCON_TIME__RESET_VALUE                    0x0000017cU
/** @} */

/* macros for field adcoff_time */
/**
 * @defgroup rif_regs_core_adcoff_time_field adcoff_time_field
 * @brief macros for field adcoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_HADM_TIMER2__ADCOFF_TIME__SHIFT                                  10
#define RIF_HADM_TIMER2__ADCOFF_TIME__WIDTH                                   6
#define RIF_HADM_TIMER2__ADCOFF_TIME__MASK                          0x0000fc00U
#define RIF_HADM_TIMER2__ADCOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_HADM_TIMER2__ADCOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_HADM_TIMER2__ADCOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_HADM_TIMER2__ADCOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_HADM_TIMER2__ADCOFF_TIME__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field adcearlyon_time */
/**
 * @defgroup rif_regs_core_adcearlyon_time_field adcearlyon_time_field
 * @brief macros for field adcearlyon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__SHIFT                              16
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__WIDTH                              10
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__MASK                      0x03ff0000U
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_HADM_TIMER2__ADCEARLYON_TIME__RESET_VALUE               0x00000000U
/** @} */

/* macros for field adcearlyoff_time */
/**
 * @defgroup rif_regs_core_adcearlyoff_time_field adcearlyoff_time_field
 * @brief macros for field adcearlyoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__SHIFT                             26
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__WIDTH                              6
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__MASK                     0xfc000000U
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_HADM_TIMER2__ADCEARLYOFF_TIME__RESET_VALUE              0x00000000U
/** @} */
#define RIF_HADM_TIMER2__TYPE                                          uint32_t
#define RIF_HADM_TIMER2__READ                                       0xffffffffU
#define RIF_HADM_TIMER2__WRITE                                      0xffffffffU
#define RIF_HADM_TIMER2__PRESERVED                                  0x00000000U
#define RIF_HADM_TIMER2__RESET_VALUE                                0x0000017cU

#endif /* __RIF_HADM_TIMER2_MACRO__ */

/** @} end of hadm_timer2 */

/* macros for BlueprintGlobalNameSpace::RIF_hadm_timer3 */
/**
 * @defgroup rif_regs_core_hadm_timer3 hadm_timer3
 * @brief All timers in units of 8 MHz clocks definitions.
 * @{
 */
#ifndef __RIF_HADM_TIMER3_MACRO__
#define __RIF_HADM_TIMER3_MACRO__

/* macros for field xpaon_time */
/**
 * @defgroup rif_regs_core_xpaon_time_field xpaon_time_field
 * @brief macros for field xpaon_time
 * @details Triggered by rising tx_en
 * @{
 */
#define RIF_HADM_TIMER3__XPAON_TIME__SHIFT                                    0
#define RIF_HADM_TIMER3__XPAON_TIME__WIDTH                                   10
#define RIF_HADM_TIMER3__XPAON_TIME__MASK                           0x000003ffU
#define RIF_HADM_TIMER3__XPAON_TIME__READ(src)  ((uint32_t)(src) & 0x000003ffU)
#define RIF_HADM_TIMER3__XPAON_TIME__WRITE(src) ((uint32_t)(src) & 0x000003ffU)
#define RIF_HADM_TIMER3__XPAON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define RIF_HADM_TIMER3__XPAON_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define RIF_HADM_TIMER3__XPAON_TIME__RESET_VALUE                    0x00000168U
/** @} */

/* macros for field xpaoff_time */
/**
 * @defgroup rif_regs_core_xpaoff_time_field xpaoff_time_field
 * @brief macros for field xpaoff_time
 * @details Triggered by falling tx_en
 * @{
 */
#define RIF_HADM_TIMER3__XPAOFF_TIME__SHIFT                                  10
#define RIF_HADM_TIMER3__XPAOFF_TIME__WIDTH                                   6
#define RIF_HADM_TIMER3__XPAOFF_TIME__MASK                          0x0000fc00U
#define RIF_HADM_TIMER3__XPAOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define RIF_HADM_TIMER3__XPAOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define RIF_HADM_TIMER3__XPAOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define RIF_HADM_TIMER3__XPAOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define RIF_HADM_TIMER3__XPAOFF_TIME__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field xlnaon_time */
/**
 * @defgroup rif_regs_core_xlnaon_time_field xlnaon_time_field
 * @brief macros for field xlnaon_time
 * @details Triggered by rising rx_en
 * @{
 */
#define RIF_HADM_TIMER3__XLNAON_TIME__SHIFT                                  16
#define RIF_HADM_TIMER3__XLNAON_TIME__WIDTH                                  10
#define RIF_HADM_TIMER3__XLNAON_TIME__MASK                          0x03ff0000U
#define RIF_HADM_TIMER3__XLNAON_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define RIF_HADM_TIMER3__XLNAON_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define RIF_HADM_TIMER3__XLNAON_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define RIF_HADM_TIMER3__XLNAON_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define RIF_HADM_TIMER3__XLNAON_TIME__RESET_VALUE                   0x00000190U
/** @} */

/* macros for field xlnaoff_time */
/**
 * @defgroup rif_regs_core_xlnaoff_time_field xlnaoff_time_field
 * @brief macros for field xlnaoff_time
 * @details Triggered by falling rx_en
 * @{
 */
#define RIF_HADM_TIMER3__XLNAOFF_TIME__SHIFT                                 26
#define RIF_HADM_TIMER3__XLNAOFF_TIME__WIDTH                                  6
#define RIF_HADM_TIMER3__XLNAOFF_TIME__MASK                         0xfc000000U
#define RIF_HADM_TIMER3__XLNAOFF_TIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define RIF_HADM_TIMER3__XLNAOFF_TIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define RIF_HADM_TIMER3__XLNAOFF_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define RIF_HADM_TIMER3__XLNAOFF_TIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define RIF_HADM_TIMER3__XLNAOFF_TIME__RESET_VALUE                  0x00000000U
/** @} */
#define RIF_HADM_TIMER3__TYPE                                          uint32_t
#define RIF_HADM_TIMER3__READ                                       0xffffffffU
#define RIF_HADM_TIMER3__WRITE                                      0xffffffffU
#define RIF_HADM_TIMER3__PRESERVED                                  0x00000000U
#define RIF_HADM_TIMER3__RESET_VALUE                                0x01900168U

#endif /* __RIF_HADM_TIMER3_MACRO__ */

/** @} end of hadm_timer3 */

/* macros for BlueprintGlobalNameSpace::RIF_rxdc7 */
/**
 * @defgroup rif_regs_core_rxdc7 rxdc7
 * @brief RX DC offset for manual override for TIA and PGA definitions.
 * @{
 */
#ifndef __RIF_RXDC7_MACRO__
#define __RIF_RXDC7_MACRO__

/* macros for field bb1q_dcoc */
/**
 * @defgroup rif_regs_core_bb1q_dcoc_field bb1q_dcoc_field
 * @brief macros for field bb1q_dcoc
 * @details value of TIA Q offset DAC when bb1_dcoc_ovr = 1
 * @{
 */
#define RIF_RXDC7__BB1Q_DCOC__SHIFT                                           0
#define RIF_RXDC7__BB1Q_DCOC__WIDTH                                           8
#define RIF_RXDC7__BB1Q_DCOC__MASK                                  0x000000ffU
#define RIF_RXDC7__BB1Q_DCOC__READ(src)         ((uint32_t)(src) & 0x000000ffU)
#define RIF_RXDC7__BB1Q_DCOC__WRITE(src)        ((uint32_t)(src) & 0x000000ffU)
#define RIF_RXDC7__BB1Q_DCOC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define RIF_RXDC7__BB1Q_DCOC__VERIFY(src) (!(((uint32_t)(src) & ~0x000000ffU)))
#define RIF_RXDC7__BB1Q_DCOC__RESET_VALUE                           0x00000020U
/** @} */

/* macros for field bb1i_dcoc */
/**
 * @defgroup rif_regs_core_bb1i_dcoc_field bb1i_dcoc_field
 * @brief macros for field bb1i_dcoc
 * @details value of TIA I offset DAC when bb1_dcoc_ovr = 1
 * @{
 */
#define RIF_RXDC7__BB1I_DCOC__SHIFT                                           8
#define RIF_RXDC7__BB1I_DCOC__WIDTH                                           8
#define RIF_RXDC7__BB1I_DCOC__MASK                                  0x0000ff00U
#define RIF_RXDC7__BB1I_DCOC__READ(src)  (((uint32_t)(src) & 0x0000ff00U) >> 8)
#define RIF_RXDC7__BB1I_DCOC__WRITE(src) (((uint32_t)(src) << 8) & 0x0000ff00U)
#define RIF_RXDC7__BB1I_DCOC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define RIF_RXDC7__BB1I_DCOC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define RIF_RXDC7__BB1I_DCOC__RESET_VALUE                           0x00000020U
/** @} */

/* macros for field bb1_dcoc_ovr */
/**
 * @defgroup rif_regs_core_bb1_dcoc_ovr_field bb1_dcoc_ovr_field
 * @brief macros for field bb1_dcoc_ovr
 * @details override TIA offset DAC values from modem
 * @{
 */
#define RIF_RXDC7__BB1_DCOC_OVR__SHIFT                                       16
#define RIF_RXDC7__BB1_DCOC_OVR__WIDTH                                        1
#define RIF_RXDC7__BB1_DCOC_OVR__MASK                               0x00010000U
#define RIF_RXDC7__BB1_DCOC_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define RIF_RXDC7__BB1_DCOC_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define RIF_RXDC7__BB1_DCOC_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define RIF_RXDC7__BB1_DCOC_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define RIF_RXDC7__BB1_DCOC_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define RIF_RXDC7__BB1_DCOC_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define RIF_RXDC7__BB1_DCOC_OVR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field bb2q_dcoc */
/**
 * @defgroup rif_regs_core_bb2q_dcoc_field bb2q_dcoc_field
 * @brief macros for field bb2q_dcoc
 * @details value of PGA Q offset DAC when bb2_dcoc_ovr = 1
 * @{
 */
#define RIF_RXDC7__BB2Q_DCOC__SHIFT                                          17
#define RIF_RXDC7__BB2Q_DCOC__WIDTH                                           5
#define RIF_RXDC7__BB2Q_DCOC__MASK                                  0x003e0000U
#define RIF_RXDC7__BB2Q_DCOC__READ(src) (((uint32_t)(src) & 0x003e0000U) >> 17)
#define RIF_RXDC7__BB2Q_DCOC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x003e0000U)
#define RIF_RXDC7__BB2Q_DCOC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003e0000U) | (((uint32_t)(src) <<\
                    17) & 0x003e0000U)
#define RIF_RXDC7__BB2Q_DCOC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x003e0000U)))
#define RIF_RXDC7__BB2Q_DCOC__RESET_VALUE                           0x00000010U
/** @} */

/* macros for field bb2i_dcoc */
/**
 * @defgroup rif_regs_core_bb2i_dcoc_field bb2i_dcoc_field
 * @brief macros for field bb2i_dcoc
 * @details value of PGA I offset DAC when bb2_dcoc_ovr = 1
 * @{
 */
#define RIF_RXDC7__BB2I_DCOC__SHIFT                                          22
#define RIF_RXDC7__BB2I_DCOC__WIDTH                                           5
#define RIF_RXDC7__BB2I_DCOC__MASK                                  0x07c00000U
#define RIF_RXDC7__BB2I_DCOC__READ(src) (((uint32_t)(src) & 0x07c00000U) >> 22)
#define RIF_RXDC7__BB2I_DCOC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x07c00000U)
#define RIF_RXDC7__BB2I_DCOC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07c00000U) | (((uint32_t)(src) <<\
                    22) & 0x07c00000U)
#define RIF_RXDC7__BB2I_DCOC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x07c00000U)))
#define RIF_RXDC7__BB2I_DCOC__RESET_VALUE                           0x00000010U
/** @} */

/* macros for field bb2_dcoc_ovr */
/**
 * @defgroup rif_regs_core_bb2_dcoc_ovr_field bb2_dcoc_ovr_field
 * @brief macros for field bb2_dcoc_ovr
 * @details override PGA offset DAC values from modem
 * @{
 */
#define RIF_RXDC7__BB2_DCOC_OVR__SHIFT                                       27
#define RIF_RXDC7__BB2_DCOC_OVR__WIDTH                                        1
#define RIF_RXDC7__BB2_DCOC_OVR__MASK                               0x08000000U
#define RIF_RXDC7__BB2_DCOC_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define RIF_RXDC7__BB2_DCOC_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define RIF_RXDC7__BB2_DCOC_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define RIF_RXDC7__BB2_DCOC_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define RIF_RXDC7__BB2_DCOC_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define RIF_RXDC7__BB2_DCOC_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define RIF_RXDC7__BB2_DCOC_OVR__RESET_VALUE                        0x00000000U
/** @} */
#define RIF_RXDC7__TYPE                                                uint32_t
#define RIF_RXDC7__READ                                             0x0fffffffU
#define RIF_RXDC7__WRITE                                            0x0fffffffU
#define RIF_RXDC7__PRESERVED                                        0x00000000U
#define RIF_RXDC7__RESET_VALUE                                      0x04202020U

#endif /* __RIF_RXDC7_MACRO__ */

/** @} end of rxdc7 */

/* macros for BlueprintGlobalNameSpace::RIF_synth_chan0 */
/**
 * @defgroup rif_regs_core_synth_chan0 synth_chan0
 * @brief Synth channel programming definitions.
 * @{
 */
#ifndef __RIF_SYNTH_CHAN0_MACRO__
#define __RIF_SYNTH_CHAN0_MACRO__

/* macros for field chan_frac_rx_base */
/**
 * @defgroup rif_regs_core_chan_frac_rx_base_field chan_frac_rx_base_field
 * @brief macros for field chan_frac_rx_base
 * @details Fractional part divide ratio for RX at 2402MHz with 8MHz Fref, = (2402*sif_ratio/Fref - chan_int_rx_base)*2^15
 * @{
 */
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__SHIFT                             0
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__WIDTH                            15
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__MASK                    0x00007fffU
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00007fffU)
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00007fffU)
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007fffU) | ((uint32_t)(src) &\
                    0x00007fffU)
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00007fffU)))
#define RIF_SYNTH_CHAN0__CHAN_FRAC_RX_BASE__RESET_VALUE             0x00001249U
/** @} */

/* macros for field chan_int_rx_base */
/**
 * @defgroup rif_regs_core_chan_int_rx_base_field chan_int_rx_base_field
 * @brief macros for field chan_int_rx_base
 * @details Integer part divide ratio for RX at 2402MHz with 8MHz Fref, = int(2402*sif_ratio/Fref)
 * @{
 */
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__SHIFT                             15
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__WIDTH                              9
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__MASK                     0x00ff8000U
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff8000U) >> 15)
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00ff8000U)
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff8000U) | (((uint32_t)(src) <<\
                    15) & 0x00ff8000U)
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00ff8000U)))
#define RIF_SYNTH_CHAN0__CHAN_INT_RX_BASE__RESET_VALUE              0x00000157U
/** @} */
#define RIF_SYNTH_CHAN0__TYPE                                          uint32_t
#define RIF_SYNTH_CHAN0__READ                                       0x00ffffffU
#define RIF_SYNTH_CHAN0__WRITE                                      0x00ffffffU
#define RIF_SYNTH_CHAN0__PRESERVED                                  0x00000000U
#define RIF_SYNTH_CHAN0__RESET_VALUE                                0x00ab9249U

#endif /* __RIF_SYNTH_CHAN0_MACRO__ */

/** @} end of synth_chan0 */

/* macros for BlueprintGlobalNameSpace::RIF_synth_chan1 */
/**
 * @defgroup rif_regs_core_synth_chan1 synth_chan1
 * @brief Synth channel programming definitions.
 * @{
 */
#ifndef __RIF_SYNTH_CHAN1_MACRO__
#define __RIF_SYNTH_CHAN1_MACRO__

/* macros for field chan_frac_sif */
/**
 * @defgroup rif_regs_core_chan_frac_sif_field chan_frac_sif_field
 * @brief macros for field chan_frac_sif
 * @details Sliding-IF channel spacing in MHz in extended chan_frac units, = sif_ratio/Fref*2^21
 * @{
 */
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__SHIFT                                 0
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__WIDTH                                21
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__MASK                        0x001fffffU
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fffffU) | ((uint32_t)(src) &\
                    0x001fffffU)
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x001fffffU)))
#define RIF_SYNTH_CHAN1__CHAN_FRAC_SIF__RESET_VALUE                 0x00049249U
/** @} */
#define RIF_SYNTH_CHAN1__TYPE                                          uint32_t
#define RIF_SYNTH_CHAN1__READ                                       0x001fffffU
#define RIF_SYNTH_CHAN1__WRITE                                      0x001fffffU
#define RIF_SYNTH_CHAN1__PRESERVED                                  0x00000000U
#define RIF_SYNTH_CHAN1__RESET_VALUE                                0x00049249U

#endif /* __RIF_SYNTH_CHAN1_MACRO__ */

/** @} end of synth_chan1 */

/* macros for BlueprintGlobalNameSpace::RIF_synth_chan2 */
/**
 * @defgroup rif_regs_core_synth_chan2 synth_chan2
 * @brief Synth channel programming definitions.
 * @{
 */
#ifndef __RIF_SYNTH_CHAN2_MACRO__
#define __RIF_SYNTH_CHAN2_MACRO__

/* macros for field chan_frac_lif1 */
/**
 * @defgroup rif_regs_core_chan_frac_lif1_field chan_frac_lif1_field
 * @brief macros for field chan_frac_lif1
 * @details Low-IF offset in MHz for 1Mbps rate in extended chan_frac units, = lif_1M*sif_ratio/Fref*2^21, default 0.8MHz
 * @{
 */
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__SHIFT                                0
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__WIDTH                               21
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__MASK                       0x001fffffU
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__READ(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fffffU) | ((uint32_t)(src) &\
                    0x001fffffU)
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x001fffffU)))
#define RIF_SYNTH_CHAN2__CHAN_FRAC_LIF1__RESET_VALUE                0x0003a83aU
/** @} */
#define RIF_SYNTH_CHAN2__TYPE                                          uint32_t
#define RIF_SYNTH_CHAN2__READ                                       0x001fffffU
#define RIF_SYNTH_CHAN2__WRITE                                      0x001fffffU
#define RIF_SYNTH_CHAN2__PRESERVED                                  0x00000000U
#define RIF_SYNTH_CHAN2__RESET_VALUE                                0x0003a83aU

#endif /* __RIF_SYNTH_CHAN2_MACRO__ */

/** @} end of synth_chan2 */

/* macros for BlueprintGlobalNameSpace::RIF_synth_chan3 */
/**
 * @defgroup rif_regs_core_synth_chan3 synth_chan3
 * @brief Synth channel programming definitions.
 * @{
 */
#ifndef __RIF_SYNTH_CHAN3_MACRO__
#define __RIF_SYNTH_CHAN3_MACRO__

/* macros for field chan_frac_lif2 */
/**
 * @defgroup rif_regs_core_chan_frac_lif2_field chan_frac_lif2_field
 * @brief macros for field chan_frac_lif2
 * @details Low-IF offset in MHz for 2Mbps rate in extended chan_frac units, = lif_2M*sif_ratio/Fref*2^21, default 1.6MHz
 * @{
 */
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__SHIFT                                0
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__WIDTH                               21
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__MASK                       0x001fffffU
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__READ(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fffffU) | ((uint32_t)(src) &\
                    0x001fffffU)
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x001fffffU)))
#define RIF_SYNTH_CHAN3__CHAN_FRAC_LIF2__RESET_VALUE                0x00075074U
/** @} */
#define RIF_SYNTH_CHAN3__TYPE                                          uint32_t
#define RIF_SYNTH_CHAN3__READ                                       0x001fffffU
#define RIF_SYNTH_CHAN3__WRITE                                      0x001fffffU
#define RIF_SYNTH_CHAN3__PRESERVED                                  0x00000000U
#define RIF_SYNTH_CHAN3__RESET_VALUE                                0x00075074U

#endif /* __RIF_SYNTH_CHAN3_MACRO__ */

/** @} end of synth_chan3 */

/* macros for BlueprintGlobalNameSpace::RIF_synth_chan4 */
/**
 * @defgroup rif_regs_core_synth_chan4 synth_chan4
 * @brief Synth channel programming definitions.
 * @{
 */
#ifndef __RIF_SYNTH_CHAN4_MACRO__
#define __RIF_SYNTH_CHAN4_MACRO__

/* macros for field chan_frac_cfo */
/**
 * @defgroup rif_regs_core_chan_frac_cfo_field chan_frac_cfo_field
 * @brief macros for field chan_frac_cfo
 * @details RX carrier frequency offset in MHz in extended chan_frac units, = cfo*sif_ratio/Fref*2^21. Signed from -0.5MHz to 0.5MHz
 * @{
 */
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__SHIFT                                 0
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__WIDTH                                21
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__MASK                        0x001fffffU
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fffffU) | ((uint32_t)(src) &\
                    0x001fffffU)
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x001fffffU)))
#define RIF_SYNTH_CHAN4__CHAN_FRAC_CFO__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field chan_frac_tx_lsb */
/**
 * @defgroup rif_regs_core_chan_frac_tx_lsb_field chan_frac_tx_lsb_field
 * @brief macros for field chan_frac_tx_lsb
 * @details LSB shift to avoid fractional spurs in TX
 * @{
 */
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__SHIFT                             21
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__WIDTH                              4
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__MASK                     0x01e00000U
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01e00000U) >> 21)
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x01e00000U)
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01e00000U) | (((uint32_t)(src) <<\
                    21) & 0x01e00000U)
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x01e00000U)))
#define RIF_SYNTH_CHAN4__CHAN_FRAC_TX_LSB__RESET_VALUE              0x00000000U
/** @} */

/* macros for field sif_num */
/**
 * @defgroup rif_regs_core_sif_num_field sif_num_field
 * @brief macros for field sif_num
 * @details sif_num+1 is power of sliding-IF ratio numerator, ie. for 8/7, sif_num = 2
 * @{
 */
#define RIF_SYNTH_CHAN4__SIF_NUM__SHIFT                                      25
#define RIF_SYNTH_CHAN4__SIF_NUM__WIDTH                                       2
#define RIF_SYNTH_CHAN4__SIF_NUM__MASK                              0x06000000U
#define RIF_SYNTH_CHAN4__SIF_NUM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x06000000U) >> 25)
#define RIF_SYNTH_CHAN4__SIF_NUM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x06000000U)
#define RIF_SYNTH_CHAN4__SIF_NUM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x06000000U) | (((uint32_t)(src) <<\
                    25) & 0x06000000U)
#define RIF_SYNTH_CHAN4__SIF_NUM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x06000000U)))
#define RIF_SYNTH_CHAN4__SIF_NUM__RESET_VALUE                       0x00000002U
/** @} */

/* macros for field high_side_lo */
/**
 * @defgroup rif_regs_core_high_side_lo_field high_side_lo_field
 * @brief macros for field high_side_lo
 * @details Low-IF LO frequency side, 1 = LO is placed above desired signal, 0 = LO placed below desired signal
 * @{
 */
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__SHIFT                                 27
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__WIDTH                                  1
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__MASK                         0x08000000U
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define RIF_SYNTH_CHAN4__HIGH_SIDE_LO__RESET_VALUE                  0x00000000U
/** @} */
#define RIF_SYNTH_CHAN4__TYPE                                          uint32_t
#define RIF_SYNTH_CHAN4__READ                                       0x0fffffffU
#define RIF_SYNTH_CHAN4__WRITE                                      0x0fffffffU
#define RIF_SYNTH_CHAN4__PRESERVED                                  0x00000000U
#define RIF_SYNTH_CHAN4__RESET_VALUE                                0x04000000U

#endif /* __RIF_SYNTH_CHAN4_MACRO__ */

/** @} end of synth_chan4 */

/* macros for BlueprintGlobalNameSpace::RIF_synth_chan5 */
/**
 * @defgroup rif_regs_core_synth_chan5 synth_chan5
 * @brief Synth channel programming for HADM definitions.
 * @{
 */
#ifndef __RIF_SYNTH_CHAN5_MACRO__
#define __RIF_SYNTH_CHAN5_MACRO__

/* macros for field hadm_chan_frac_hlif */
/**
 * @defgroup rif_regs_core_hadm_chan_frac_hlif_field hadm_chan_frac_hlif_field
 * @brief macros for field hadm_chan_frac_hlif
 * @details Half low-IF offset in MHz in HADM mode in extended chan_frac units, = hadm_hlif/Fref*2^21, default 0.4MHz
 * @{
 */
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__SHIFT                           0
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__WIDTH                          21
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__MASK                  0x001fffffU
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x001fffffU)
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fffffU) | ((uint32_t)(src) &\
                    0x001fffffU)
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x001fffffU)))
#define RIF_SYNTH_CHAN5__HADM_CHAN_FRAC_HLIF__RESET_VALUE           0x00019999U
/** @} */

/* macros for field hadm_high_side_lo */
/**
 * @defgroup rif_regs_core_hadm_high_side_lo_field hadm_high_side_lo_field
 * @brief macros for field hadm_high_side_lo
 * @details Low-IF LO frequency side in HADM mode, 1 = LO is placed above desired signal, 0 = LO placed below desired signal
 * @{
 */
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__SHIFT                            21
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__WIDTH                             1
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__MASK                    0x00200000U
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define RIF_SYNTH_CHAN5__HADM_HIGH_SIDE_LO__RESET_VALUE             0x00000000U
/** @} */
#define RIF_SYNTH_CHAN5__TYPE                                          uint32_t
#define RIF_SYNTH_CHAN5__READ                                       0x003fffffU
#define RIF_SYNTH_CHAN5__WRITE                                      0x003fffffU
#define RIF_SYNTH_CHAN5__PRESERVED                                  0x00000000U
#define RIF_SYNTH_CHAN5__RESET_VALUE                                0x00019999U

#endif /* __RIF_SYNTH_CHAN5_MACRO__ */

/** @} end of synth_chan5 */

/* macros for BlueprintGlobalNameSpace::RIF_adc_cntl */
/**
 * @defgroup rif_regs_core_adc_cntl adc_cntl
 * @brief ADC controls definitions.
 * @{
 */
#ifndef __RIF_ADC_CNTL_MACRO__
#define __RIF_ADC_CNTL_MACRO__

/* macros for field invert_msb */
/**
 * @defgroup rif_regs_core_invert_msb_field invert_msb_field
 * @brief macros for field invert_msb
 * @details To convert from unsigned to signed
 * @{
 */
#define RIF_ADC_CNTL__INVERT_MSB__SHIFT                                       0
#define RIF_ADC_CNTL__INVERT_MSB__WIDTH                                       1
#define RIF_ADC_CNTL__INVERT_MSB__MASK                              0x00000001U
#define RIF_ADC_CNTL__INVERT_MSB__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define RIF_ADC_CNTL__INVERT_MSB__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define RIF_ADC_CNTL__INVERT_MSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RIF_ADC_CNTL__INVERT_MSB__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RIF_ADC_CNTL__INVERT_MSB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RIF_ADC_CNTL__INVERT_MSB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RIF_ADC_CNTL__INVERT_MSB__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field swap_iq */
/**
 * @defgroup rif_regs_core_swap_iq_field swap_iq_field
 * @brief macros for field swap_iq
 * @details Swap I and Q channels after ADC outputs
 * @{
 */
#define RIF_ADC_CNTL__SWAP_IQ__SHIFT                                          1
#define RIF_ADC_CNTL__SWAP_IQ__WIDTH                                          1
#define RIF_ADC_CNTL__SWAP_IQ__MASK                                 0x00000002U
#define RIF_ADC_CNTL__SWAP_IQ__READ(src) (((uint32_t)(src) & 0x00000002U) >> 1)
#define RIF_ADC_CNTL__SWAP_IQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RIF_ADC_CNTL__SWAP_IQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RIF_ADC_CNTL__SWAP_IQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RIF_ADC_CNTL__SWAP_IQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RIF_ADC_CNTL__SWAP_IQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RIF_ADC_CNTL__SWAP_IQ__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field invert_i */
/**
 * @defgroup rif_regs_core_invert_i_field invert_i_field
 * @brief macros for field invert_i
 * @details Invert I *before* possible iq swap
 * @{
 */
#define RIF_ADC_CNTL__INVERT_I__SHIFT                                         2
#define RIF_ADC_CNTL__INVERT_I__WIDTH                                         1
#define RIF_ADC_CNTL__INVERT_I__MASK                                0x00000004U
#define RIF_ADC_CNTL__INVERT_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RIF_ADC_CNTL__INVERT_I__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RIF_ADC_CNTL__INVERT_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RIF_ADC_CNTL__INVERT_I__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RIF_ADC_CNTL__INVERT_I__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RIF_ADC_CNTL__INVERT_I__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RIF_ADC_CNTL__INVERT_I__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field invert_q */
/**
 * @defgroup rif_regs_core_invert_q_field invert_q_field
 * @brief macros for field invert_q
 * @details Invert Q *before* possible iq swap
 * @{
 */
#define RIF_ADC_CNTL__INVERT_Q__SHIFT                                         3
#define RIF_ADC_CNTL__INVERT_Q__WIDTH                                         1
#define RIF_ADC_CNTL__INVERT_Q__MASK                                0x00000008U
#define RIF_ADC_CNTL__INVERT_Q__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RIF_ADC_CNTL__INVERT_Q__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define RIF_ADC_CNTL__INVERT_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define RIF_ADC_CNTL__INVERT_Q__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define RIF_ADC_CNTL__INVERT_Q__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RIF_ADC_CNTL__INVERT_Q__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RIF_ADC_CNTL__INVERT_Q__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field edge_sel */
/**
 * @defgroup rif_regs_core_edge_sel_field edge_sel_field
 * @brief macros for field edge_sel
 * @details 0 = launch ADC data on falling edge out of radio, 1 = launch ADC data on rising edge out of radio
 * @{
 */
#define RIF_ADC_CNTL__EDGE_SEL__SHIFT                                         4
#define RIF_ADC_CNTL__EDGE_SEL__WIDTH                                         1
#define RIF_ADC_CNTL__EDGE_SEL__MASK                                0x00000010U
#define RIF_ADC_CNTL__EDGE_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RIF_ADC_CNTL__EDGE_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RIF_ADC_CNTL__EDGE_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RIF_ADC_CNTL__EDGE_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RIF_ADC_CNTL__EDGE_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RIF_ADC_CNTL__EDGE_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RIF_ADC_CNTL__EDGE_SEL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field delay_ctrl */
/**
 * @defgroup rif_regs_core_delay_ctrl_field delay_ctrl_field
 * @brief macros for field delay_ctrl
 * @details SAR logic delay control, delay decreases as control increases
 * @{
 */
#define RIF_ADC_CNTL__DELAY_CTRL__SHIFT                                       5
#define RIF_ADC_CNTL__DELAY_CTRL__WIDTH                                       3
#define RIF_ADC_CNTL__DELAY_CTRL__MASK                              0x000000e0U
#define RIF_ADC_CNTL__DELAY_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000e0U) >> 5)
#define RIF_ADC_CNTL__DELAY_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000000e0U)
#define RIF_ADC_CNTL__DELAY_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define RIF_ADC_CNTL__DELAY_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000000e0U)))
#define RIF_ADC_CNTL__DELAY_CTRL__RESET_VALUE                       0x00000004U
/** @} */

/* macros for field ref_ctrl */
/**
 * @defgroup rif_regs_core_ref_ctrl_field ref_ctrl_field
 * @brief macros for field ref_ctrl
 * @details ADC reference voltage level = 0.8 + 0.1*(ref_ctrl[2:0] - 4)
 * @{
 */
#define RIF_ADC_CNTL__REF_CTRL__SHIFT                                         8
#define RIF_ADC_CNTL__REF_CTRL__WIDTH                                         3
#define RIF_ADC_CNTL__REF_CTRL__MASK                                0x00000700U
#define RIF_ADC_CNTL__REF_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define RIF_ADC_CNTL__REF_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define RIF_ADC_CNTL__REF_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define RIF_ADC_CNTL__REF_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define RIF_ADC_CNTL__REF_CTRL__RESET_VALUE                         0x00000004U
/** @} */

/* macros for field clksample_ext */
/**
 * @defgroup rif_regs_core_clksample_ext_field clksample_ext_field
 * @brief macros for field clksample_ext
 * @details Borrow time from sampling phase
 * @{
 */
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__SHIFT                                   11
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__WIDTH                                    1
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__MASK                           0x00000800U
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define RIF_ADC_CNTL__CLKSAMPLE_EXT__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field vcm_ctrl */
/**
 * @defgroup rif_regs_core_vcm_ctrl_field vcm_ctrl_field
 * @brief macros for field vcm_ctrl
 * @details ADC common-mode voltage level = 0.5 + 0.125*(vcm_ctrl[1:0] - 2)
 * @{
 */
#define RIF_ADC_CNTL__VCM_CTRL__SHIFT                                        12
#define RIF_ADC_CNTL__VCM_CTRL__WIDTH                                         2
#define RIF_ADC_CNTL__VCM_CTRL__MASK                                0x00003000U
#define RIF_ADC_CNTL__VCM_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define RIF_ADC_CNTL__VCM_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define RIF_ADC_CNTL__VCM_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define RIF_ADC_CNTL__VCM_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define RIF_ADC_CNTL__VCM_CTRL__RESET_VALUE                         0x00000002U
/** @} */
#define RIF_ADC_CNTL__TYPE                                             uint32_t
#define RIF_ADC_CNTL__READ                                          0x00003fffU
#define RIF_ADC_CNTL__WRITE                                         0x00003fffU
#define RIF_ADC_CNTL__PRESERVED                                     0x00000000U
#define RIF_ADC_CNTL__RESET_VALUE                                   0x00002c81U

#endif /* __RIF_ADC_CNTL_MACRO__ */

/** @} end of adc_cntl */

/* macros for BlueprintGlobalNameSpace::RIF_mode_cntl */
/**
 * @defgroup rif_regs_core_mode_cntl mode_cntl
 * @brief Radio mode controls definitions.
 * @{
 */
#ifndef __RIF_MODE_CNTL_MACRO__
#define __RIF_MODE_CNTL_MACRO__

/* macros for field tx_power */
/**
 * @defgroup rif_regs_core_tx_power_field tx_power_field
 * @brief macros for field tx_power
 * @details value in emulation mode or when tx_power_ovr = 1, this is the TX gain table index
 * @{
 */
#define RIF_MODE_CNTL__TX_POWER__SHIFT                                        0
#define RIF_MODE_CNTL__TX_POWER__WIDTH                                        4
#define RIF_MODE_CNTL__TX_POWER__MASK                               0x0000000fU
#define RIF_MODE_CNTL__TX_POWER__READ(src)      ((uint32_t)(src) & 0x0000000fU)
#define RIF_MODE_CNTL__TX_POWER__WRITE(src)     ((uint32_t)(src) & 0x0000000fU)
#define RIF_MODE_CNTL__TX_POWER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RIF_MODE_CNTL__TX_POWER__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define RIF_MODE_CNTL__TX_POWER__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field tx_power_ovr */
/**
 * @defgroup rif_regs_core_tx_power_ovr_field tx_power_ovr_field
 * @brief macros for field tx_power_ovr
 * @details override tx_power index value from LC
 * @{
 */
#define RIF_MODE_CNTL__TX_POWER_OVR__SHIFT                                    4
#define RIF_MODE_CNTL__TX_POWER_OVR__WIDTH                                    1
#define RIF_MODE_CNTL__TX_POWER_OVR__MASK                           0x00000010U
#define RIF_MODE_CNTL__TX_POWER_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RIF_MODE_CNTL__TX_POWER_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RIF_MODE_CNTL__TX_POWER_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RIF_MODE_CNTL__TX_POWER_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RIF_MODE_CNTL__TX_POWER_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RIF_MODE_CNTL__TX_POWER_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RIF_MODE_CNTL__TX_POWER_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field rxgain */
/**
 * @defgroup rif_regs_core_rxgain_field rxgain_field
 * @brief macros for field rxgain
 * @details value when rxgain_ovr = 1, this is the RX gain table index
 * @{
 */
#define RIF_MODE_CNTL__RXGAIN__SHIFT                                          5
#define RIF_MODE_CNTL__RXGAIN__WIDTH                                          7
#define RIF_MODE_CNTL__RXGAIN__MASK                                 0x00000fe0U
#define RIF_MODE_CNTL__RXGAIN__READ(src) (((uint32_t)(src) & 0x00000fe0U) >> 5)
#define RIF_MODE_CNTL__RXGAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000fe0U)
#define RIF_MODE_CNTL__RXGAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fe0U) | (((uint32_t)(src) <<\
                    5) & 0x00000fe0U)
#define RIF_MODE_CNTL__RXGAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000fe0U)))
#define RIF_MODE_CNTL__RXGAIN__RESET_VALUE                          0x0000007fU
/** @} */

/* macros for field rxgain_ovr */
/**
 * @defgroup rif_regs_core_rxgain_ovr_field rxgain_ovr_field
 * @brief macros for field rxgain_ovr
 * @details override rxgain index value from modem
 * @{
 */
#define RIF_MODE_CNTL__RXGAIN_OVR__SHIFT                                     12
#define RIF_MODE_CNTL__RXGAIN_OVR__WIDTH                                      1
#define RIF_MODE_CNTL__RXGAIN_OVR__MASK                             0x00001000U
#define RIF_MODE_CNTL__RXGAIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define RIF_MODE_CNTL__RXGAIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define RIF_MODE_CNTL__RXGAIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define RIF_MODE_CNTL__RXGAIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define RIF_MODE_CNTL__RXGAIN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define RIF_MODE_CNTL__RXGAIN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define RIF_MODE_CNTL__RXGAIN_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field chan_idx */
/**
 * @defgroup rif_regs_core_chan_idx_field chan_idx_field
 * @brief macros for field chan_idx
 * @details value in emulation mode, TRNG, or when chan_idx_ovr = 1
 * @{
 */
#define RIF_MODE_CNTL__CHAN_IDX__SHIFT                                       13
#define RIF_MODE_CNTL__CHAN_IDX__WIDTH                                        7
#define RIF_MODE_CNTL__CHAN_IDX__MASK                               0x000fe000U
#define RIF_MODE_CNTL__CHAN_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000fe000U) >> 13)
#define RIF_MODE_CNTL__CHAN_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x000fe000U)
#define RIF_MODE_CNTL__CHAN_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fe000U) | (((uint32_t)(src) <<\
                    13) & 0x000fe000U)
#define RIF_MODE_CNTL__CHAN_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x000fe000U)))
#define RIF_MODE_CNTL__CHAN_IDX__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field chan_idx_ovr */
/**
 * @defgroup rif_regs_core_chan_idx_ovr_field chan_idx_ovr_field
 * @brief macros for field chan_idx_ovr
 * @details override chan_idx value from LC
 * @{
 */
#define RIF_MODE_CNTL__CHAN_IDX_OVR__SHIFT                                   20
#define RIF_MODE_CNTL__CHAN_IDX_OVR__WIDTH                                    1
#define RIF_MODE_CNTL__CHAN_IDX_OVR__MASK                           0x00100000U
#define RIF_MODE_CNTL__CHAN_IDX_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define RIF_MODE_CNTL__CHAN_IDX_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define RIF_MODE_CNTL__CHAN_IDX_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define RIF_MODE_CNTL__CHAN_IDX_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define RIF_MODE_CNTL__CHAN_IDX_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define RIF_MODE_CNTL__CHAN_IDX_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define RIF_MODE_CNTL__CHAN_IDX_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field tx_en */
/**
 * @defgroup rif_regs_core_tx_en_field tx_en_field
 * @brief macros for field tx_en
 * @details value when tx_en_ovr = 1
 * @{
 */
#define RIF_MODE_CNTL__TX_EN__SHIFT                                          21
#define RIF_MODE_CNTL__TX_EN__WIDTH                                           1
#define RIF_MODE_CNTL__TX_EN__MASK                                  0x00200000U
#define RIF_MODE_CNTL__TX_EN__READ(src) (((uint32_t)(src) & 0x00200000U) >> 21)
#define RIF_MODE_CNTL__TX_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define RIF_MODE_CNTL__TX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define RIF_MODE_CNTL__TX_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define RIF_MODE_CNTL__TX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define RIF_MODE_CNTL__TX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define RIF_MODE_CNTL__TX_EN__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field tx_en_ovr */
/**
 * @defgroup rif_regs_core_tx_en_ovr_field tx_en_ovr_field
 * @brief macros for field tx_en_ovr
 * @details override tx_en value from LC
 * @{
 */
#define RIF_MODE_CNTL__TX_EN_OVR__SHIFT                                      22
#define RIF_MODE_CNTL__TX_EN_OVR__WIDTH                                       1
#define RIF_MODE_CNTL__TX_EN_OVR__MASK                              0x00400000U
#define RIF_MODE_CNTL__TX_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define RIF_MODE_CNTL__TX_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define RIF_MODE_CNTL__TX_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define RIF_MODE_CNTL__TX_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define RIF_MODE_CNTL__TX_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define RIF_MODE_CNTL__TX_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define RIF_MODE_CNTL__TX_EN_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rx_en */
/**
 * @defgroup rif_regs_core_rx_en_field rx_en_field
 * @brief macros for field rx_en
 * @details value when rx_en_ovr = 1
 * @{
 */
#define RIF_MODE_CNTL__RX_EN__SHIFT                                          23
#define RIF_MODE_CNTL__RX_EN__WIDTH                                           1
#define RIF_MODE_CNTL__RX_EN__MASK                                  0x00800000U
#define RIF_MODE_CNTL__RX_EN__READ(src) (((uint32_t)(src) & 0x00800000U) >> 23)
#define RIF_MODE_CNTL__RX_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define RIF_MODE_CNTL__RX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define RIF_MODE_CNTL__RX_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define RIF_MODE_CNTL__RX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define RIF_MODE_CNTL__RX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define RIF_MODE_CNTL__RX_EN__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field rx_en_ovr */
/**
 * @defgroup rif_regs_core_rx_en_ovr_field rx_en_ovr_field
 * @brief macros for field rx_en_ovr
 * @details override rx_en value from LC
 * @{
 */
#define RIF_MODE_CNTL__RX_EN_OVR__SHIFT                                      24
#define RIF_MODE_CNTL__RX_EN_OVR__WIDTH                                       1
#define RIF_MODE_CNTL__RX_EN_OVR__MASK                              0x01000000U
#define RIF_MODE_CNTL__RX_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define RIF_MODE_CNTL__RX_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define RIF_MODE_CNTL__RX_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define RIF_MODE_CNTL__RX_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define RIF_MODE_CNTL__RX_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define RIF_MODE_CNTL__RX_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define RIF_MODE_CNTL__RX_EN_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field radio_en */
/**
 * @defgroup rif_regs_core_radio_en_field radio_en_field
 * @brief macros for field radio_en
 * @details value when radio_en_ovr = 1
 * @{
 */
#define RIF_MODE_CNTL__RADIO_EN__SHIFT                                       25
#define RIF_MODE_CNTL__RADIO_EN__WIDTH                                        1
#define RIF_MODE_CNTL__RADIO_EN__MASK                               0x02000000U
#define RIF_MODE_CNTL__RADIO_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define RIF_MODE_CNTL__RADIO_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define RIF_MODE_CNTL__RADIO_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define RIF_MODE_CNTL__RADIO_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define RIF_MODE_CNTL__RADIO_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define RIF_MODE_CNTL__RADIO_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define RIF_MODE_CNTL__RADIO_EN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field radio_en_ovr */
/**
 * @defgroup rif_regs_core_radio_en_ovr_field radio_en_ovr_field
 * @brief macros for field radio_en_ovr
 * @details override radio_en value from LC
 * @{
 */
#define RIF_MODE_CNTL__RADIO_EN_OVR__SHIFT                                   26
#define RIF_MODE_CNTL__RADIO_EN_OVR__WIDTH                                    1
#define RIF_MODE_CNTL__RADIO_EN_OVR__MASK                           0x04000000U
#define RIF_MODE_CNTL__RADIO_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define RIF_MODE_CNTL__RADIO_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define RIF_MODE_CNTL__RADIO_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define RIF_MODE_CNTL__RADIO_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define RIF_MODE_CNTL__RADIO_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define RIF_MODE_CNTL__RADIO_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define RIF_MODE_CNTL__RADIO_EN_OVR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field select_ext */
/**
 * @defgroup rif_regs_core_select_ext_field select_ext_field
 * @brief macros for field select_ext
 * @details Enable external interface for radio emulation/dtop_bypass mode
 * @{
 */
#define RIF_MODE_CNTL__SELECT_EXT__SHIFT                                     27
#define RIF_MODE_CNTL__SELECT_EXT__WIDTH                                      1
#define RIF_MODE_CNTL__SELECT_EXT__MASK                             0x08000000U
#define RIF_MODE_CNTL__SELECT_EXT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define RIF_MODE_CNTL__SELECT_EXT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define RIF_MODE_CNTL__SELECT_EXT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define RIF_MODE_CNTL__SELECT_EXT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define RIF_MODE_CNTL__SELECT_EXT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define RIF_MODE_CNTL__SELECT_EXT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define RIF_MODE_CNTL__SELECT_EXT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field interleave_adc_iq */
/**
 * @defgroup rif_regs_core_interleave_adc_iq_field interleave_adc_iq_field
 * @brief macros for field interleave_adc_iq
 * @details Enable interleaving of ADC I/Q output bits for testing
 * @{
 */
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__SHIFT                              28
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__WIDTH                               1
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__MASK                      0x10000000U
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define RIF_MODE_CNTL__INTERLEAVE_ADC_IQ__RESET_VALUE               0x00000000U
/** @} */

/* macros for field adcon */
/**
 * @defgroup rif_regs_core_adcon_field adcon_field
 * @brief macros for field adcon
 * @details value when adcon_ovr = 1
 * @{
 */
#define RIF_MODE_CNTL__ADCON__SHIFT                                          29
#define RIF_MODE_CNTL__ADCON__WIDTH                                           1
#define RIF_MODE_CNTL__ADCON__MASK                                  0x20000000U
#define RIF_MODE_CNTL__ADCON__READ(src) (((uint32_t)(src) & 0x20000000U) >> 29)
#define RIF_MODE_CNTL__ADCON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define RIF_MODE_CNTL__ADCON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define RIF_MODE_CNTL__ADCON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define RIF_MODE_CNTL__ADCON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define RIF_MODE_CNTL__ADCON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define RIF_MODE_CNTL__ADCON__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field adcon_ovr */
/**
 * @defgroup rif_regs_core_adcon_ovr_field adcon_ovr_field
 * @brief macros for field adcon_ovr
 * @details override adcon value so ADC bits can be clocked out of RIF, also overrides adcon_early
 * @{
 */
#define RIF_MODE_CNTL__ADCON_OVR__SHIFT                                      30
#define RIF_MODE_CNTL__ADCON_OVR__WIDTH                                       1
#define RIF_MODE_CNTL__ADCON_OVR__MASK                              0x40000000U
#define RIF_MODE_CNTL__ADCON_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define RIF_MODE_CNTL__ADCON_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define RIF_MODE_CNTL__ADCON_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define RIF_MODE_CNTL__ADCON_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define RIF_MODE_CNTL__ADCON_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define RIF_MODE_CNTL__ADCON_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define RIF_MODE_CNTL__ADCON_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field flash_suppresses_paon */
/**
 * @defgroup rif_regs_core_flash_suppresses_paon_field flash_suppresses_paon_field
 * @brief macros for field flash_suppresses_paon
 * @details Should a flash write or erase block paon?
 * @{
 */
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__SHIFT                          31
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__WIDTH                           1
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__MASK                  0x80000000U
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define RIF_MODE_CNTL__FLASH_SUPPRESSES_PAON__RESET_VALUE           0x00000000U
/** @} */
#define RIF_MODE_CNTL__TYPE                                            uint32_t
#define RIF_MODE_CNTL__READ                                         0xffffffffU
#define RIF_MODE_CNTL__WRITE                                        0xffffffffU
#define RIF_MODE_CNTL__PRESERVED                                    0x00000000U
#define RIF_MODE_CNTL__RESET_VALUE                                  0x00000fe0U

#endif /* __RIF_MODE_CNTL_MACRO__ */

/** @} end of mode_cntl */

/* macros for BlueprintGlobalNameSpace::RIF_mode_cntl2 */
/**
 * @defgroup rif_regs_core_mode_cntl2 mode_cntl2
 * @brief Radio mode controls definitions.
 * @{
 */
#ifndef __RIF_MODE_CNTL2_MACRO__
#define __RIF_MODE_CNTL2_MACRO__

/* macros for field hadm_en */
/**
 * @defgroup rif_regs_core_hadm_en_field hadm_en_field
 * @brief macros for field hadm_en
 * @details 0: Normal BLE mode. 1: HADM mode
 * @{
 */
#define RIF_MODE_CNTL2__HADM_EN__SHIFT                                        0
#define RIF_MODE_CNTL2__HADM_EN__WIDTH                                        1
#define RIF_MODE_CNTL2__HADM_EN__MASK                               0x00000001U
#define RIF_MODE_CNTL2__HADM_EN__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define RIF_MODE_CNTL2__HADM_EN__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define RIF_MODE_CNTL2__HADM_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RIF_MODE_CNTL2__HADM_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RIF_MODE_CNTL2__HADM_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RIF_MODE_CNTL2__HADM_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RIF_MODE_CNTL2__HADM_EN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field full_packet_peakdet */
/**
 * @defgroup rif_regs_core_full_packet_peakdet_field full_packet_peakdet_field
 * @brief macros for field full_packet_peakdet
 * @details 0: Turn off peakdet after access_address_found, to save power 1: Keep peakdet on for full packet (in case of any phase disturbance if turning off mid-packet)
 * @{
 */
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__SHIFT                            1
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__WIDTH                            1
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__MASK                   0x00000002U
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RIF_MODE_CNTL2__FULL_PACKET_PEAKDET__RESET_VALUE            0x00000000U
/** @} */

/* macros for field force_txon_when_hadm_en */
/**
 * @defgroup rif_regs_core_force_txon_when_hadm_en_field force_txon_when_hadm_en_field
 * @brief macros for field force_txon_when_hadm_en
 * @details If bit is set, force txon high whenever hadm_en is set
 * @{
 */
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__SHIFT                        2
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__WIDTH                        1
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__MASK               0x00000004U
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RIF_MODE_CNTL2__FORCE_TXON_WHEN_HADM_EN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field force_synthon_when_hadm_en */
/**
 * @defgroup rif_regs_core_force_synthon_when_hadm_en_field force_synthon_when_hadm_en_field
 * @brief macros for field force_synthon_when_hadm_en
 * @details If bit is set, force synthon high whenever hadm_en is set
 * @{
 */
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__SHIFT                     3
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__WIDTH                     1
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__MASK            0x00000008U
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RIF_MODE_CNTL2__FORCE_SYNTHON_WHEN_HADM_EN__RESET_VALUE     0x00000000U
/** @} */

/* macros for field hadm_synth_bw2 */
/**
 * @defgroup rif_regs_core_hadm_synth_bw2_field hadm_synth_bw2_field
 * @brief macros for field hadm_synth_bw2
 * @details In HADM mode, 0 = use 1M synth loop bandwidth, 1 = use 2M synth loop bandwidth, same for TX and RX
 * @{
 */
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__SHIFT                                 4
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__WIDTH                                 1
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__MASK                        0x00000010U
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RIF_MODE_CNTL2__HADM_SYNTH_BW2__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field pmode */
/**
 * @defgroup rif_regs_core_pmode_field pmode_field
 * @brief macros for field pmode
 * @details value when pmode_ovr = 1
 * @{
 */
#define RIF_MODE_CNTL2__PMODE__SHIFT                                          5
#define RIF_MODE_CNTL2__PMODE__WIDTH                                          2
#define RIF_MODE_CNTL2__PMODE__MASK                                 0x00000060U
#define RIF_MODE_CNTL2__PMODE__READ(src) (((uint32_t)(src) & 0x00000060U) >> 5)
#define RIF_MODE_CNTL2__PMODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000060U)
#define RIF_MODE_CNTL2__PMODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define RIF_MODE_CNTL2__PMODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define RIF_MODE_CNTL2__PMODE__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field pmode_ovr */
/**
 * @defgroup rif_regs_core_pmode_ovr_field pmode_ovr_field
 * @brief macros for field pmode_ovr
 * @details ovrride pmode value from modem
 * @{
 */
#define RIF_MODE_CNTL2__PMODE_OVR__SHIFT                                      7
#define RIF_MODE_CNTL2__PMODE_OVR__WIDTH                                      1
#define RIF_MODE_CNTL2__PMODE_OVR__MASK                             0x00000080U
#define RIF_MODE_CNTL2__PMODE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define RIF_MODE_CNTL2__PMODE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define RIF_MODE_CNTL2__PMODE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define RIF_MODE_CNTL2__PMODE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define RIF_MODE_CNTL2__PMODE_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define RIF_MODE_CNTL2__PMODE_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define RIF_MODE_CNTL2__PMODE_OVR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field xpa_thresh */
/**
 * @defgroup rif_regs_core_xpa_thresh_field xpa_thresh_field
 * @brief macros for field xpa_thresh
 * @details Enable XPA if tx_power from LC is >= xpa_thresh
 * @{
 */
#define RIF_MODE_CNTL2__XPA_THRESH__SHIFT                                     8
#define RIF_MODE_CNTL2__XPA_THRESH__WIDTH                                     4
#define RIF_MODE_CNTL2__XPA_THRESH__MASK                            0x00000f00U
#define RIF_MODE_CNTL2__XPA_THRESH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RIF_MODE_CNTL2__XPA_THRESH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RIF_MODE_CNTL2__XPA_THRESH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RIF_MODE_CNTL2__XPA_THRESH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define RIF_MODE_CNTL2__XPA_THRESH__RESET_VALUE                     0x0000000fU
/** @} */

/* macros for field dbg_select */
/**
 * @defgroup rif_regs_core_dbg_select_field dbg_select_field
 * @brief macros for field dbg_select
 * @details 0 = {r_ext_mdm_xlnaon, r_ext_rxgain[6:0]} 1 = {r_ext_tx_data_valid, r_ext_tx_data[6:0]}
 * @{
 */
#define RIF_MODE_CNTL2__DBG_SELECT__SHIFT                                    12
#define RIF_MODE_CNTL2__DBG_SELECT__WIDTH                                     1
#define RIF_MODE_CNTL2__DBG_SELECT__MASK                            0x00001000U
#define RIF_MODE_CNTL2__DBG_SELECT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define RIF_MODE_CNTL2__DBG_SELECT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define RIF_MODE_CNTL2__DBG_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define RIF_MODE_CNTL2__DBG_SELECT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define RIF_MODE_CNTL2__DBG_SELECT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define RIF_MODE_CNTL2__DBG_SELECT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define RIF_MODE_CNTL2__DBG_SELECT__RESET_VALUE                     0x00000000U
/** @} */
#define RIF_MODE_CNTL2__TYPE                                           uint32_t
#define RIF_MODE_CNTL2__READ                                        0x00001fffU
#define RIF_MODE_CNTL2__WRITE                                       0x00001fffU
#define RIF_MODE_CNTL2__PRESERVED                                   0x00000000U
#define RIF_MODE_CNTL2__RESET_VALUE                                 0x00000f10U

#endif /* __RIF_MODE_CNTL2_MACRO__ */

/** @} end of mode_cntl2 */

/* macros for BlueprintGlobalNameSpace::RIF_xlna_xpa_cntl */
/**
 * @defgroup rif_regs_core_xlna_xpa_cntl xlna_xpa_cntl
 * @brief External LNA/PA control definitions.
 * @{
 */
#ifndef __RIF_XLNA_XPA_CNTL_MACRO__
#define __RIF_XLNA_XPA_CNTL_MACRO__

/* macros for field idle */
/**
 * @defgroup rif_regs_core_idle_field idle_field
 * @brief macros for field idle
 * @details No active transmit or receive
 * @{
 */
#define RIF_XLNA_XPA_CNTL__IDLE__SHIFT                                        0
#define RIF_XLNA_XPA_CNTL__IDLE__WIDTH                                        5
#define RIF_XLNA_XPA_CNTL__IDLE__MASK                               0x0000001fU
#define RIF_XLNA_XPA_CNTL__IDLE__READ(src)      ((uint32_t)(src) & 0x0000001fU)
#define RIF_XLNA_XPA_CNTL__IDLE__WRITE(src)     ((uint32_t)(src) & 0x0000001fU)
#define RIF_XLNA_XPA_CNTL__IDLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define RIF_XLNA_XPA_CNTL__IDLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define RIF_XLNA_XPA_CNTL__IDLE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field tx_xpa_off */
/**
 * @defgroup rif_regs_core_tx_xpa_off_field tx_xpa_off_field
 * @brief macros for field tx_xpa_off
 * @details Transmit with XPA off
 * @{
 */
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__SHIFT                                  5
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__WIDTH                                  5
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__MASK                         0x000003e0U
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define RIF_XLNA_XPA_CNTL__TX_XPA_OFF__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field tx_xpa_on */
/**
 * @defgroup rif_regs_core_tx_xpa_on_field tx_xpa_on_field
 * @brief macros for field tx_xpa_on
 * @details Transmit with XPA on
 * @{
 */
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__SHIFT                                  10
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__WIDTH                                   5
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__MASK                          0x00007c00U
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define RIF_XLNA_XPA_CNTL__TX_XPA_ON__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field rx_xlna_off */
/**
 * @defgroup rif_regs_core_rx_xlna_off_field rx_xlna_off_field
 * @brief macros for field rx_xlna_off
 * @details Receive with XLNA off
 * @{
 */
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__SHIFT                                15
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__WIDTH                                 5
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__MASK                        0x000f8000U
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define RIF_XLNA_XPA_CNTL__RX_XLNA_OFF__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field rx_xlna_on */
/**
 * @defgroup rif_regs_core_rx_xlna_on_field rx_xlna_on_field
 * @brief macros for field rx_xlna_on
 * @details Receive with XLNA on
 * @{
 */
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__SHIFT                                 20
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__WIDTH                                  5
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__MASK                         0x01f00000U
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define RIF_XLNA_XPA_CNTL__RX_XLNA_ON__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field rx_cal */
/**
 * @defgroup rif_regs_core_rx_cal_field rx_cal_field
 * @brief macros for field rx_cal
 * @details Receiver calibration. Expect to program the same as rx_xlna_off
 * @{
 */
#define RIF_XLNA_XPA_CNTL__RX_CAL__SHIFT                                     25
#define RIF_XLNA_XPA_CNTL__RX_CAL__WIDTH                                      5
#define RIF_XLNA_XPA_CNTL__RX_CAL__MASK                             0x3e000000U
#define RIF_XLNA_XPA_CNTL__RX_CAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define RIF_XLNA_XPA_CNTL__RX_CAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define RIF_XLNA_XPA_CNTL__RX_CAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define RIF_XLNA_XPA_CNTL__RX_CAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define RIF_XLNA_XPA_CNTL__RX_CAL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field register_outputs */
/**
 * @defgroup rif_regs_core_register_outputs_field register_outputs_field
 * @brief macros for field register_outputs
 * @details To prevent possible glitching (for example XPA control during RX) register outputs before driving to pins
 * @{
 */
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__SHIFT                           30
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__WIDTH                            1
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__MASK                   0x40000000U
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define RIF_XLNA_XPA_CNTL__REGISTER_OUTPUTS__RESET_VALUE            0x00000000U
/** @} */
#define RIF_XLNA_XPA_CNTL__TYPE                                        uint32_t
#define RIF_XLNA_XPA_CNTL__READ                                     0x7fffffffU
#define RIF_XLNA_XPA_CNTL__WRITE                                    0x7fffffffU
#define RIF_XLNA_XPA_CNTL__PRESERVED                                0x00000000U
#define RIF_XLNA_XPA_CNTL__RESET_VALUE                              0x00000000U

#endif /* __RIF_XLNA_XPA_CNTL_MACRO__ */

/** @} end of xlna_xpa_cntl */

/* macros for BlueprintGlobalNameSpace::RIF_cal_cntl */
/**
 * @defgroup rif_regs_core_cal_cntl cal_cntl
 * @brief Radio calibration signals definitions.
 * @{
 */
#ifndef __RIF_CAL_CNTL_MACRO__
#define __RIF_CAL_CNTL_MACRO__

/* macros for field caltx */
/**
 * @defgroup rif_regs_core_caltx_field caltx_field
 * @brief macros for field caltx
 * @details Set to 1 to configure radio for synth cals, MSB is modgain, LSB is vcocap
 * @{
 */
#define RIF_CAL_CNTL__CALTX__SHIFT                                            0
#define RIF_CAL_CNTL__CALTX__WIDTH                                            2
#define RIF_CAL_CNTL__CALTX__MASK                                   0x00000003U
#define RIF_CAL_CNTL__CALTX__READ(src)          ((uint32_t)(src) & 0x00000003U)
#define RIF_CAL_CNTL__CALTX__WRITE(src)         ((uint32_t)(src) & 0x00000003U)
#define RIF_CAL_CNTL__CALTX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define RIF_CAL_CNTL__CALTX__VERIFY(src)  (!(((uint32_t)(src) & ~0x00000003U)))
#define RIF_CAL_CNTL__CALTX__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field calrx */
/**
 * @defgroup rif_regs_core_calrx_field calrx_field
 * @brief macros for field calrx
 * @details Reserved for any other RX calibration modes (also used for TRNG)
 * @{
 */
#define RIF_CAL_CNTL__CALRX__SHIFT                                            2
#define RIF_CAL_CNTL__CALRX__WIDTH                                            1
#define RIF_CAL_CNTL__CALRX__MASK                                   0x00000004U
#define RIF_CAL_CNTL__CALRX__READ(src)   (((uint32_t)(src) & 0x00000004U) >> 2)
#define RIF_CAL_CNTL__CALRX__WRITE(src)  (((uint32_t)(src) << 2) & 0x00000004U)
#define RIF_CAL_CNTL__CALRX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RIF_CAL_CNTL__CALRX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RIF_CAL_CNTL__CALRX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RIF_CAL_CNTL__CALRX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RIF_CAL_CNTL__CALRX__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field caldc */
/**
 * @defgroup rif_regs_core_caldc_field caldc_field
 * @brief macros for field caldc
 * @details Set to 1 to configure radio for RX DC offset cal, MSB is TIA, LSB is PGA
 * @{
 */
#define RIF_CAL_CNTL__CALDC__SHIFT                                            3
#define RIF_CAL_CNTL__CALDC__WIDTH                                            2
#define RIF_CAL_CNTL__CALDC__MASK                                   0x00000018U
#define RIF_CAL_CNTL__CALDC__READ(src)   (((uint32_t)(src) & 0x00000018U) >> 3)
#define RIF_CAL_CNTL__CALDC__WRITE(src)  (((uint32_t)(src) << 3) & 0x00000018U)
#define RIF_CAL_CNTL__CALDC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000018U) | (((uint32_t)(src) <<\
                    3) & 0x00000018U)
#define RIF_CAL_CNTL__CALDC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000018U)))
#define RIF_CAL_CNTL__CALDC__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field calfc */
/**
 * @defgroup rif_regs_core_calfc_field calfc_field
 * @brief macros for field calfc
 * @details Set to 1 to configure radio for RXBB filter BW cal, MSB is TIA, LSB is PGA
 * @{
 */
#define RIF_CAL_CNTL__CALFC__SHIFT                                            5
#define RIF_CAL_CNTL__CALFC__WIDTH                                            2
#define RIF_CAL_CNTL__CALFC__MASK                                   0x00000060U
#define RIF_CAL_CNTL__CALFC__READ(src)   (((uint32_t)(src) & 0x00000060U) >> 5)
#define RIF_CAL_CNTL__CALFC__WRITE(src)  (((uint32_t)(src) << 5) & 0x00000060U)
#define RIF_CAL_CNTL__CALFC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define RIF_CAL_CNTL__CALFC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define RIF_CAL_CNTL__CALFC__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field caltx_chan_idx */
/**
 * @defgroup rif_regs_core_caltx_chan_idx_field caltx_chan_idx_field
 * @brief macros for field caltx_chan_idx
 * @details chan_idx value during modgain cal
 * @{
 */
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__SHIFT                                   7
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__WIDTH                                   7
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__MASK                          0x00003f80U
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define RIF_CAL_CNTL__CALTX_CHAN_IDX__RESET_VALUE                   0x00000026U
/** @} */
#define RIF_CAL_CNTL__TYPE                                             uint32_t
#define RIF_CAL_CNTL__READ                                          0x00003fffU
#define RIF_CAL_CNTL__WRITE                                         0x00003fffU
#define RIF_CAL_CNTL__PRESERVED                                     0x00000000U
#define RIF_CAL_CNTL__RESET_VALUE                                   0x00001300U

#endif /* __RIF_CAL_CNTL_MACRO__ */

/** @} end of cal_cntl */

/* macros for BlueprintGlobalNameSpace::RIF_cal_done */
/**
 * @defgroup rif_regs_core_cal_done cal_done
 * @brief Synth/TX calibration done indicator definitions.
 * @{
 */
#ifndef __RIF_CAL_DONE_MACRO__
#define __RIF_CAL_DONE_MACRO__

/* macros for field caltx_done */
/**
 * @defgroup rif_regs_core_caltx_done_field caltx_done_field
 * @brief macros for field caltx_done
 * @details Indicates calibration is finished, MSB is modgain, LSB is vcocap
 * @{
 */
#define RIF_CAL_DONE__CALTX_DONE__SHIFT                                       0
#define RIF_CAL_DONE__CALTX_DONE__WIDTH                                       2
#define RIF_CAL_DONE__CALTX_DONE__MASK                              0x00000003U
#define RIF_CAL_DONE__CALTX_DONE__READ(src)     ((uint32_t)(src) & 0x00000003U)
#define RIF_CAL_DONE__CALTX_DONE__RESET_VALUE                       0x00000000U
/** @} */
#define RIF_CAL_DONE__TYPE                                             uint32_t
#define RIF_CAL_DONE__READ                                          0x00000003U
#define RIF_CAL_DONE__PRESERVED                                     0x00000000U
#define RIF_CAL_DONE__RESET_VALUE                                   0x00000000U

#endif /* __RIF_CAL_DONE_MACRO__ */

/** @} end of cal_done */

/* macros for BlueprintGlobalNameSpace::RIF_id */
/**
 * @defgroup rif_regs_core_id id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __RIF_ID_MACRO__
#define __RIF_ID_MACRO__

/* macros for field id */
/**
 * @defgroup rif_regs_core_id_field id_field
 * @brief macros for field id
 * @details RIF+space in ASCII
 * @{
 */
#define RIF_ID__ID__SHIFT                                                     0
#define RIF_ID__ID__WIDTH                                                    32
#define RIF_ID__ID__MASK                                            0xffffffffU
#define RIF_ID__ID__READ(src)                   ((uint32_t)(src) & 0xffffffffU)
#define RIF_ID__ID__RESET_VALUE                                     0x52494620U
/** @} */
#define RIF_ID__TYPE                                                   uint32_t
#define RIF_ID__READ                                                0xffffffffU
#define RIF_ID__PRESERVED                                           0x00000000U
#define RIF_ID__RESET_VALUE                                         0x52494620U

#endif /* __RIF_ID_MACRO__ */

/** @} end of id */

/** @} end of RIF_REGS_CORE */
#endif /* __REG_RIF_REGS_CORE_H__ */
