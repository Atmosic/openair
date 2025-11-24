/*                                                                           */
/* File:       pll_regs_core_macro.h                                         */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic pll_regs_core.rdl                  */
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


#ifndef __REG_PLL_REGS_CORE_H__
#define __REG_PLL_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup PLL_REGS_CORE pll_regs_core
 * @ingroup AT_REG
 * @brief pll_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::pll_pll */
/**
 * @defgroup pll_regs_core_pll pll
 * @brief State machine timing parameters and VCO adjustment definitions.
 * @{
 */
#ifndef __PLL_PLL_MACRO__
#define __PLL_PLL_MACRO__

/* macros for field time_powerOnWait_x500n */
/**
 * @defgroup pll_regs_core_time_powerOnWait_x500n_field time_powerOnWait_x500n_field
 * @brief macros for field time_powerOnWait_x500n
 * @details Power-on settling time, min 500ns
 * @{
 */
#define PLL_PLL__TIME_POWERONWAIT_X500N__SHIFT                                0
#define PLL_PLL__TIME_POWERONWAIT_X500N__WIDTH                                3
#define PLL_PLL__TIME_POWERONWAIT_X500N__MASK                       0x00000007U
#define PLL_PLL__TIME_POWERONWAIT_X500N__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define PLL_PLL__TIME_POWERONWAIT_X500N__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define PLL_PLL__TIME_POWERONWAIT_X500N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define PLL_PLL__TIME_POWERONWAIT_X500N__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define PLL_PLL__TIME_POWERONWAIT_X500N__RESET_VALUE                0x00000001U
/** @} */

/* macros for field time_vcoSettling_x250n */
/**
 * @defgroup pll_regs_core_time_vcoSettling_x250n_field time_vcoSettling_x250n_field
 * @brief macros for field time_vcoSettling_x250n
 * @details VCO settling time, min 250ns
 * @{
 */
#define PLL_PLL__TIME_VCOSETTLING_X250N__SHIFT                                3
#define PLL_PLL__TIME_VCOSETTLING_X250N__WIDTH                                3
#define PLL_PLL__TIME_VCOSETTLING_X250N__MASK                       0x00000038U
#define PLL_PLL__TIME_VCOSETTLING_X250N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define PLL_PLL__TIME_VCOSETTLING_X250N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define PLL_PLL__TIME_VCOSETTLING_X250N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define PLL_PLL__TIME_VCOSETTLING_X250N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define PLL_PLL__TIME_VCOSETTLING_X250N__RESET_VALUE                0x00000001U
/** @} */

/* macros for field time_vcoCount_x250n */
/**
 * @defgroup pll_regs_core_time_vcoCount_x250n_field time_vcoCount_x250n_field
 * @brief macros for field time_vcoCount_x250n
 * @details Counting time of VCO cycles during locking, min 250ns
 * @{
 */
#define PLL_PLL__TIME_VCOCOUNT_X250N__SHIFT                                   6
#define PLL_PLL__TIME_VCOCOUNT_X250N__WIDTH                                   3
#define PLL_PLL__TIME_VCOCOUNT_X250N__MASK                          0x000001c0U
#define PLL_PLL__TIME_VCOCOUNT_X250N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define PLL_PLL__TIME_VCOCOUNT_X250N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define PLL_PLL__TIME_VCOCOUNT_X250N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define PLL_PLL__TIME_VCOCOUNT_X250N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define PLL_PLL__TIME_VCOCOUNT_X250N__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field time_closeLoop_x500n */
/**
 * @defgroup pll_regs_core_time_closeLoop_x500n_field time_closeLoop_x500n_field
 * @brief macros for field time_closeLoop_x500n
 * @details Settling time after closing loop, min 500ns
 * @{
 */
#define PLL_PLL__TIME_CLOSELOOP_X500N__SHIFT                                  9
#define PLL_PLL__TIME_CLOSELOOP_X500N__WIDTH                                  3
#define PLL_PLL__TIME_CLOSELOOP_X500N__MASK                         0x00000e00U
#define PLL_PLL__TIME_CLOSELOOP_X500N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PLL_PLL__TIME_CLOSELOOP_X500N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define PLL_PLL__TIME_CLOSELOOP_X500N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define PLL_PLL__TIME_CLOSELOOP_X500N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define PLL_PLL__TIME_CLOSELOOP_X500N__RESET_VALUE                  0x00000003U
/** @} */

/* macros for field vcoGm */
/**
 * @defgroup pll_regs_core_vcoGm_field vcoGm_field
 * @brief macros for field vcoGm
 * @details VCO Gm adjustment
 * @{
 */
#define PLL_PLL__VCOGM__SHIFT                                                12
#define PLL_PLL__VCOGM__WIDTH                                                 4
#define PLL_PLL__VCOGM__MASK                                        0x0000f000U
#define PLL_PLL__VCOGM__READ(src)       (((uint32_t)(src) & 0x0000f000U) >> 12)
#define PLL_PLL__VCOGM__WRITE(src)      (((uint32_t)(src) << 12) & 0x0000f000U)
#define PLL_PLL__VCOGM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PLL_PLL__VCOGM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PLL_PLL__VCOGM__RESET_VALUE                                 0x00000004U
/** @} */

/* macros for field vcoLpfR */
/**
 * @defgroup pll_regs_core_vcoLpfR_field vcoLpfR_field
 * @brief macros for field vcoLpfR
 * @details Corner freq of noise filter in VCO, trade off between period and cycle-cycle jitter
 * @{
 */
#define PLL_PLL__VCOLPFR__SHIFT                                              16
#define PLL_PLL__VCOLPFR__WIDTH                                               4
#define PLL_PLL__VCOLPFR__MASK                                      0x000f0000U
#define PLL_PLL__VCOLPFR__READ(src)     (((uint32_t)(src) & 0x000f0000U) >> 16)
#define PLL_PLL__VCOLPFR__WRITE(src)    (((uint32_t)(src) << 16) & 0x000f0000U)
#define PLL_PLL__VCOLPFR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define PLL_PLL__VCOLPFR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define PLL_PLL__VCOLPFR__RESET_VALUE                               0x00000008U
/** @} */

/* macros for field vcoKvf */
/**
 * @defgroup pll_regs_core_vcoKvf_field vcoKvf_field
 * @brief macros for field vcoKvf
 * @details Pin Vc voltage used during locking
 * @{
 */
#define PLL_PLL__VCOKVF__SHIFT                                               20
#define PLL_PLL__VCOKVF__WIDTH                                                2
#define PLL_PLL__VCOKVF__MASK                                       0x00300000U
#define PLL_PLL__VCOKVF__READ(src)      (((uint32_t)(src) & 0x00300000U) >> 20)
#define PLL_PLL__VCOKVF__WRITE(src)     (((uint32_t)(src) << 20) & 0x00300000U)
#define PLL_PLL__VCOKVF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define PLL_PLL__VCOKVF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define PLL_PLL__VCOKVF__RESET_VALUE                                0x00000002U
/** @} */

/* macros for field sparebits */
/**
 * @defgroup pll_regs_core_sparebits_field sparebits_field
 * @brief macros for field sparebits
 * @details spares
 * @{
 */
#define PLL_PLL__SPAREBITS__SHIFT                                            22
#define PLL_PLL__SPAREBITS__WIDTH                                             4
#define PLL_PLL__SPAREBITS__MASK                                    0x03c00000U
#define PLL_PLL__SPAREBITS__READ(src)   (((uint32_t)(src) & 0x03c00000U) >> 22)
#define PLL_PLL__SPAREBITS__WRITE(src)  (((uint32_t)(src) << 22) & 0x03c00000U)
#define PLL_PLL__SPAREBITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03c00000U) | (((uint32_t)(src) <<\
                    22) & 0x03c00000U)
#define PLL_PLL__SPAREBITS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x03c00000U)))
#define PLL_PLL__SPAREBITS__RESET_VALUE                             0x00000000U
/** @} */
#define PLL_PLL__TYPE                                                  uint32_t
#define PLL_PLL__READ                                               0x03ffffffU
#define PLL_PLL__WRITE                                              0x03ffffffU
#define PLL_PLL__PRESERVED                                          0x00000000U
#define PLL_PLL__RESET_VALUE                                        0x002846c9U

#endif /* __PLL_PLL_MACRO__ */

/** @} end of pll */

/* macros for BlueprintGlobalNameSpace::pll_test */
/**
 * @defgroup pll_regs_core_test test
 * @brief Debug and testing definitions.
 * @{
 */
#ifndef __PLL_TEST_MACRO__
#define __PLL_TEST_MACRO__

/* macros for field rstPfdB_ovr */
/**
 * @defgroup pll_regs_core_rstPfdB_ovr_field rstPfdB_ovr_field
 * @brief macros for field rstPfdB_ovr
 * @details Force PFD in reset
 * @{
 */
#define PLL_TEST__RSTPFDB_OVR__SHIFT                                          0
#define PLL_TEST__RSTPFDB_OVR__WIDTH                                          1
#define PLL_TEST__RSTPFDB_OVR__MASK                                 0x00000001U
#define PLL_TEST__RSTPFDB_OVR__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define PLL_TEST__RSTPFDB_OVR__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define PLL_TEST__RSTPFDB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PLL_TEST__RSTPFDB_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PLL_TEST__RSTPFDB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PLL_TEST__RSTPFDB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PLL_TEST__RSTPFDB_OVR__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field rstDivRefB_ovr */
/**
 * @defgroup pll_regs_core_rstDivRefB_ovr_field rstDivRefB_ovr_field
 * @brief macros for field rstDivRefB_ovr
 * @details Force reference divider in reset if 0
 * @{
 */
#define PLL_TEST__RSTDIVREFB_OVR__SHIFT                                       1
#define PLL_TEST__RSTDIVREFB_OVR__WIDTH                                       1
#define PLL_TEST__RSTDIVREFB_OVR__MASK                              0x00000002U
#define PLL_TEST__RSTDIVREFB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PLL_TEST__RSTDIVREFB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PLL_TEST__RSTDIVREFB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PLL_TEST__RSTDIVREFB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PLL_TEST__RSTDIVREFB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PLL_TEST__RSTDIVREFB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PLL_TEST__RSTDIVREFB_OVR__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field rstDivOutB_ovr */
/**
 * @defgroup pll_regs_core_rstDivOutB_ovr_field rstDivOutB_ovr_field
 * @brief macros for field rstDivOutB_ovr
 * @details Force output divider in reset if 0
 * @{
 */
#define PLL_TEST__RSTDIVOUTB_OVR__SHIFT                                       2
#define PLL_TEST__RSTDIVOUTB_OVR__WIDTH                                       1
#define PLL_TEST__RSTDIVOUTB_OVR__MASK                              0x00000004U
#define PLL_TEST__RSTDIVOUTB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PLL_TEST__RSTDIVOUTB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PLL_TEST__RSTDIVOUTB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PLL_TEST__RSTDIVOUTB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PLL_TEST__RSTDIVOUTB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PLL_TEST__RSTDIVOUTB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PLL_TEST__RSTDIVOUTB_OVR__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field rstDivFbB_ovr */
/**
 * @defgroup pll_regs_core_rstDivFbB_ovr_field rstDivFbB_ovr_field
 * @brief macros for field rstDivFbB_ovr
 * @details Force feedback divider in reset if 0
 * @{
 */
#define PLL_TEST__RSTDIVFBB_OVR__SHIFT                                        3
#define PLL_TEST__RSTDIVFBB_OVR__WIDTH                                        1
#define PLL_TEST__RSTDIVFBB_OVR__MASK                               0x00000008U
#define PLL_TEST__RSTDIVFBB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PLL_TEST__RSTDIVFBB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PLL_TEST__RSTDIVFBB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PLL_TEST__RSTDIVFBB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PLL_TEST__RSTDIVFBB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PLL_TEST__RSTDIVFBB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PLL_TEST__RSTDIVFBB_OVR__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field enDivRef_ovr */
/**
 * @defgroup pll_regs_core_enDivRef_ovr_field enDivRef_ovr_field
 * @brief macros for field enDivRef_ovr
 * @details Force reference divider off if 0
 * @{
 */
#define PLL_TEST__ENDIVREF_OVR__SHIFT                                         4
#define PLL_TEST__ENDIVREF_OVR__WIDTH                                         1
#define PLL_TEST__ENDIVREF_OVR__MASK                                0x00000010U
#define PLL_TEST__ENDIVREF_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PLL_TEST__ENDIVREF_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PLL_TEST__ENDIVREF_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PLL_TEST__ENDIVREF_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PLL_TEST__ENDIVREF_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PLL_TEST__ENDIVREF_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PLL_TEST__ENDIVREF_OVR__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field enDivOut_ovr */
/**
 * @defgroup pll_regs_core_enDivOut_ovr_field enDivOut_ovr_field
 * @brief macros for field enDivOut_ovr
 * @details Force output divider off if 0
 * @{
 */
#define PLL_TEST__ENDIVOUT_OVR__SHIFT                                         5
#define PLL_TEST__ENDIVOUT_OVR__WIDTH                                         1
#define PLL_TEST__ENDIVOUT_OVR__MASK                                0x00000020U
#define PLL_TEST__ENDIVOUT_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PLL_TEST__ENDIVOUT_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PLL_TEST__ENDIVOUT_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PLL_TEST__ENDIVOUT_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PLL_TEST__ENDIVOUT_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PLL_TEST__ENDIVOUT_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PLL_TEST__ENDIVOUT_OVR__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field enDivFb_ovr */
/**
 * @defgroup pll_regs_core_enDivFb_ovr_field enDivFb_ovr_field
 * @brief macros for field enDivFb_ovr
 * @details Force feedback divider off if 0
 * @{
 */
#define PLL_TEST__ENDIVFB_OVR__SHIFT                                          6
#define PLL_TEST__ENDIVFB_OVR__WIDTH                                          1
#define PLL_TEST__ENDIVFB_OVR__MASK                                 0x00000040U
#define PLL_TEST__ENDIVFB_OVR__READ(src) (((uint32_t)(src) & 0x00000040U) >> 6)
#define PLL_TEST__ENDIVFB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PLL_TEST__ENDIVFB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PLL_TEST__ENDIVFB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PLL_TEST__ENDIVFB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PLL_TEST__ENDIVFB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PLL_TEST__ENDIVFB_OVR__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field gateOutB_en_ov */
/**
 * @defgroup pll_regs_core_gateOutB_en_ov_field gateOutB_en_ov_field
 * @brief macros for field gateOutB_en_ov
 * @details Enable override for output clock gating during settling, if 1, use gateOutB_ovr value
 * @{
 */
#define PLL_TEST__GATEOUTB_EN_OV__SHIFT                                       7
#define PLL_TEST__GATEOUTB_EN_OV__WIDTH                                       1
#define PLL_TEST__GATEOUTB_EN_OV__MASK                              0x00000080U
#define PLL_TEST__GATEOUTB_EN_OV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PLL_TEST__GATEOUTB_EN_OV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PLL_TEST__GATEOUTB_EN_OV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PLL_TEST__GATEOUTB_EN_OV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PLL_TEST__GATEOUTB_EN_OV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PLL_TEST__GATEOUTB_EN_OV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PLL_TEST__GATEOUTB_EN_OV__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field gateOutB_ovr */
/**
 * @defgroup pll_regs_core_gateOutB_ovr_field gateOutB_ovr_field
 * @brief macros for field gateOutB_ovr
 * @details Value for gateOutB if gateOutB_en_ov is set
 * @{
 */
#define PLL_TEST__GATEOUTB_OVR__SHIFT                                         8
#define PLL_TEST__GATEOUTB_OVR__WIDTH                                         1
#define PLL_TEST__GATEOUTB_OVR__MASK                                0x00000100U
#define PLL_TEST__GATEOUTB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PLL_TEST__GATEOUTB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PLL_TEST__GATEOUTB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PLL_TEST__GATEOUTB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PLL_TEST__GATEOUTB_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PLL_TEST__GATEOUTB_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PLL_TEST__GATEOUTB_OVR__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field atbsel */
/**
 * @defgroup pll_regs_core_atbsel_field atbsel_field
 * @brief macros for field atbsel
 * @details ATB selection, 0: high-Z, 1: Cstop, 2: VCO supply (vddx), 3: Core supply (vdd)
 * @{
 */
#define PLL_TEST__ATBSEL__SHIFT                                               9
#define PLL_TEST__ATBSEL__WIDTH                                               2
#define PLL_TEST__ATBSEL__MASK                                      0x00000600U
#define PLL_TEST__ATBSEL__READ(src)      (((uint32_t)(src) & 0x00000600U) >> 9)
#define PLL_TEST__ATBSEL__WRITE(src)     (((uint32_t)(src) << 9) & 0x00000600U)
#define PLL_TEST__ATBSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000600U) | (((uint32_t)(src) <<\
                    9) & 0x00000600U)
#define PLL_TEST__ATBSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000600U)))
#define PLL_TEST__ATBSEL__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field forcePinVc */
/**
 * @defgroup pll_regs_core_forcePinVc_field forcePinVc_field
 * @brief macros for field forcePinVc
 * @details Force pinVc
 * @{
 */
#define PLL_TEST__FORCEPINVC__SHIFT                                          11
#define PLL_TEST__FORCEPINVC__WIDTH                                           1
#define PLL_TEST__FORCEPINVC__MASK                                  0x00000800U
#define PLL_TEST__FORCEPINVC__READ(src) (((uint32_t)(src) & 0x00000800U) >> 11)
#define PLL_TEST__FORCEPINVC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PLL_TEST__FORCEPINVC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PLL_TEST__FORCEPINVC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PLL_TEST__FORCEPINVC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PLL_TEST__FORCEPINVC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PLL_TEST__FORCEPINVC__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field vcoSetting_ovr */
/**
 * @defgroup pll_regs_core_vcoSetting_ovr_field vcoSetting_ovr_field
 * @brief macros for field vcoSetting_ovr
 * @details override vcoSetting
 * @{
 */
#define PLL_TEST__VCOSETTING_OVR__SHIFT                                      12
#define PLL_TEST__VCOSETTING_OVR__WIDTH                                       1
#define PLL_TEST__VCOSETTING_OVR__MASK                              0x00001000U
#define PLL_TEST__VCOSETTING_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PLL_TEST__VCOSETTING_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PLL_TEST__VCOSETTING_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PLL_TEST__VCOSETTING_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PLL_TEST__VCOSETTING_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PLL_TEST__VCOSETTING_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PLL_TEST__VCOSETTING_OVR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field vcoSetting_ovrVal */
/**
 * @defgroup pll_regs_core_vcoSetting_ovrVal_field vcoSetting_ovrVal_field
 * @brief macros for field vcoSetting_ovrVal
 * @details vcoSetting value when vcoSetting_ovr=1
 * @{
 */
#define PLL_TEST__VCOSETTING_OVRVAL__SHIFT                                   13
#define PLL_TEST__VCOSETTING_OVRVAL__WIDTH                                    4
#define PLL_TEST__VCOSETTING_OVRVAL__MASK                           0x0001e000U
#define PLL_TEST__VCOSETTING_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001e000U) >> 13)
#define PLL_TEST__VCOSETTING_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0001e000U)
#define PLL_TEST__VCOSETTING_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001e000U) | (((uint32_t)(src) <<\
                    13) & 0x0001e000U)
#define PLL_TEST__VCOSETTING_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0001e000U)))
#define PLL_TEST__VCOSETTING_OVRVAL__RESET_VALUE                    0x00000008U
/** @} */
#define PLL_TEST__TYPE                                                 uint32_t
#define PLL_TEST__READ                                              0x0001ffffU
#define PLL_TEST__WRITE                                             0x0001ffffU
#define PLL_TEST__PRESERVED                                         0x00000000U
#define PLL_TEST__RESET_VALUE                                       0x0001007fU

#endif /* __PLL_TEST_MACRO__ */

/** @} end of test */

/* macros for BlueprintGlobalNameSpace::pll_readout */
/**
 * @defgroup pll_regs_core_readout readout
 * @brief readout bits definitions.
 * @{
 */
#ifndef __PLL_READOUT_MACRO__
#define __PLL_READOUT_MACRO__

/* macros for field vcoSetting */
/**
 * @defgroup pll_regs_core_vcoSetting_field vcoSetting_field
 * @brief macros for field vcoSetting
 * @details the vcoSetting currently applied
 * @{
 */
#define PLL_READOUT__VCOSETTING__SHIFT                                        0
#define PLL_READOUT__VCOSETTING__WIDTH                                        4
#define PLL_READOUT__VCOSETTING__MASK                               0x0000000fU
#define PLL_READOUT__VCOSETTING__READ(src)      ((uint32_t)(src) & 0x0000000fU)
#define PLL_READOUT__VCOSETTING__RESET_VALUE                        0x00000000U
/** @} */
#define PLL_READOUT__TYPE                                              uint32_t
#define PLL_READOUT__READ                                           0x0000000fU
#define PLL_READOUT__PRESERVED                                      0x00000000U
#define PLL_READOUT__RESET_VALUE                                    0x00000000U

#endif /* __PLL_READOUT_MACRO__ */

/** @} end of readout */

/* macros for BlueprintGlobalNameSpace::pll_core_id */
/**
 * @defgroup pll_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __PLL_CORE_ID_MACRO__
#define __PLL_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup pll_regs_core_id_field id_field
 * @brief macros for field id
 * @details CPLL in ASCII, for CPU PLL
 * @{
 */
#define PLL_CORE_ID__ID__SHIFT                                                0
#define PLL_CORE_ID__ID__WIDTH                                               32
#define PLL_CORE_ID__ID__MASK                                       0xffffffffU
#define PLL_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define PLL_CORE_ID__ID__RESET_VALUE                                0x43504c4cU
/** @} */
#define PLL_CORE_ID__TYPE                                              uint32_t
#define PLL_CORE_ID__READ                                           0xffffffffU
#define PLL_CORE_ID__PRESERVED                                      0x00000000U
#define PLL_CORE_ID__RESET_VALUE                                    0x43504c4cU

#endif /* __PLL_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of PLL_REGS_CORE */
#endif /* __REG_PLL_REGS_CORE_H__ */
