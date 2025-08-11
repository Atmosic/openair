/*                                                                           */
/* File:       at_apb_clkrstgen_regs_core_macro.h                            */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_clkrstgen_regs_core.rdl     */
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


#ifndef __REG_AT_APB_CLKRSTGEN_REGS_CORE_H__
#define __REG_AT_APB_CLKRSTGEN_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_CLKRSTGEN_REGS_CORE at_apb_clkrstgen_regs_core
 * @ingroup AT_REG
 * @brief at_apb_clkrstgen_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_clk_bp_ctrl */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk_bp_ctrl clk_bp_ctrl
 * @brief Contains register fields associated with clk_bp_ctrl. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_CLK_BP_CTRL_MACRO__
#define __CLKRSTGEN_CLK_BP_CTRL_MACRO__

/* macros for field pll_cluster_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_cluster_sel_field pll_cluster_sel_field
 * @brief macros for field pll_cluster_sel
 * @details selects which clock is output by this cluster  0 = 16MHz  1 = selected pll frequency  always leave this cluster in 16MHz (0 setting) before leaving it
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__SHIFT                         0
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__WIDTH                         1
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__MASK                0x00000001U
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_CLUSTER_SEL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field pll_div2_cluster_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_div2_cluster_sel_field pll_div2_cluster_sel_field
 * @brief macros for field pll_div2_cluster_sel
 * @details selects which clock is output by this cluster  0 = 16MHz  1 = (selected pll frequency)/2  always leave this cluster in 16MHz (0 setting) before leaving it
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__SHIFT                    1
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__WIDTH                    1
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__MASK           0x00000002U
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_CLK_BP_CTRL__PLL_DIV2_CLUSTER_SEL__RESET_VALUE    0x00000000U
/** @} */

/* macros for field doubler_cluster_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_doubler_cluster_sel_field doubler_cluster_sel_field
 * @brief macros for field doubler_cluster_sel
 * @details selects which clock is output by this cluster  0 = 16MHz  1 = 32MHz  always leave this cluster in 16MHz (0 setting) before leaving it
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__SHIFT                     2
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__WIDTH                     1
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__MASK            0x00000004U
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_CLK_BP_CTRL__DOUBLER_CLUSTER_SEL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field slow_cluster_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_slow_cluster_sel_field slow_cluster_sel_field
 * @brief macros for field slow_cluster_sel
 * @details selects which clock is output by this cluster  0 = 16MHz  1 = 8MHz  3 = 4MHz  2 = 2MHz  6 = 1MHz  7 = 500kHz  notice the gray encoding; only change one bit per write  always leave this cluster in 16MHz (0 setting) before leaving it
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__SHIFT                        3
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__WIDTH                        3
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__MASK               0x00000038U
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field cluster_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_cluster_sel_field cluster_sel_field
 * @brief macros for field cluster_sel
 * @details selects which cluster is to drive the backplane clock  0 = clk16x  1 = slow clocks  2 = doubler cluster  4 = pll cluster  8 = pll div2 cluster  always cycle through 0 so that only one bits changes per write
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__SHIFT                             6
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WIDTH                             4
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__MASK                    0x000003c0U
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field div2_type */
/**
 * @defgroup at_apb_clkrstgen_regs_core_div2_type_field div2_type_field
 * @brief macros for field div2_type
 * @details selects additional properties of pll div2 cluster  0 = backplane clock is /2 and phase alignment is /6 relative to clk_pll  1 = backplane clock is /2 and phase alignment is /2 relative to clk_pll  2 = backplane clock is /4 and phase alignment is /4 relative to clk_pll  Only change this value when pll_div2_cluster_sel is set to 0.
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__SHIFT                              10
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__WIDTH                               2
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__MASK                      0x00000c00U
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define CLKRSTGEN_CLK_BP_CTRL__DIV2_TYPE__RESET_VALUE               0x00000000U
/** @} */

/* macros for field clear_div2_cntr */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clear_div2_cntr_field clear_div2_cntr_field
 * @brief macros for field clear_div2_cntr
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__SHIFT                        12
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__WIDTH                         1
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__MASK                0x00001000U
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define CLKRSTGEN_CLK_BP_CTRL__CLEAR_DIV2_CNTR__RESET_VALUE         0x00000000U
/** @} */
#define CLKRSTGEN_CLK_BP_CTRL__TYPE                                    uint32_t
#define CLKRSTGEN_CLK_BP_CTRL__READ                                 0x00001fffU
#define CLKRSTGEN_CLK_BP_CTRL__WRITE                                0x00001fffU
#define CLKRSTGEN_CLK_BP_CTRL__PRESERVED                            0x00000000U
#define CLKRSTGEN_CLK_BP_CTRL__RESET_VALUE                          0x00000000U

#endif /* __CLKRSTGEN_CLK_BP_CTRL_MACRO__ */

/** @} end of clk_bp_ctrl */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_clk_bp_ctrl_stat */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk_bp_ctrl_stat clk_bp_ctrl_stat
 * @brief status of clk_bp_ctrl. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_CLK_BP_CTRL_STAT_MACRO__
#define __CLKRSTGEN_CLK_BP_CTRL_STAT_MACRO__

/* macros for field pll_cluster_sel_stat */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_cluster_sel_stat_field pll_cluster_sel_stat_field
 * @brief macros for field pll_cluster_sel_stat
 * @details status of pll_cluster_sel
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_CLUSTER_SEL_STAT__SHIFT               0
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_CLUSTER_SEL_STAT__WIDTH               1
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_CLUSTER_SEL_STAT__MASK      0x00000001U
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_CLUSTER_SEL_STAT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_CLUSTER_SEL_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_CLUSTER_SEL_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_CLUSTER_SEL_STAT__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field pll_div2_cluster_sel_stat */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_div2_cluster_sel_stat_field pll_div2_cluster_sel_stat_field
 * @brief macros for field pll_div2_cluster_sel_stat
 * @details status of pll_div2_cluster_sel
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_DIV2_CLUSTER_SEL_STAT__SHIFT          1
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_DIV2_CLUSTER_SEL_STAT__WIDTH          1
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_DIV2_CLUSTER_SEL_STAT__MASK 0x00000002U
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_DIV2_CLUSTER_SEL_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_DIV2_CLUSTER_SEL_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_DIV2_CLUSTER_SEL_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PLL_DIV2_CLUSTER_SEL_STAT__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field doubler_cluster_sel_stat */
/**
 * @defgroup at_apb_clkrstgen_regs_core_doubler_cluster_sel_stat_field doubler_cluster_sel_stat_field
 * @brief macros for field doubler_cluster_sel_stat
 * @details status of doubler_cluster_sel
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL_STAT__DOUBLER_CLUSTER_SEL_STAT__SHIFT           2
#define CLKRSTGEN_CLK_BP_CTRL_STAT__DOUBLER_CLUSTER_SEL_STAT__WIDTH           1
#define CLKRSTGEN_CLK_BP_CTRL_STAT__DOUBLER_CLUSTER_SEL_STAT__MASK  0x00000004U
#define CLKRSTGEN_CLK_BP_CTRL_STAT__DOUBLER_CLUSTER_SEL_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__DOUBLER_CLUSTER_SEL_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__DOUBLER_CLUSTER_SEL_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__DOUBLER_CLUSTER_SEL_STAT__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field slow_cluster_sel_stat */
/**
 * @defgroup at_apb_clkrstgen_regs_core_slow_cluster_sel_stat_field slow_cluster_sel_stat_field
 * @brief macros for field slow_cluster_sel_stat
 * @details status of slow_cluster_sel
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL_STAT__SLOW_CLUSTER_SEL_STAT__SHIFT              3
#define CLKRSTGEN_CLK_BP_CTRL_STAT__SLOW_CLUSTER_SEL_STAT__WIDTH              3
#define CLKRSTGEN_CLK_BP_CTRL_STAT__SLOW_CLUSTER_SEL_STAT__MASK     0x00000038U
#define CLKRSTGEN_CLK_BP_CTRL_STAT__SLOW_CLUSTER_SEL_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__SLOW_CLUSTER_SEL_STAT__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field cluster_sel_stat */
/**
 * @defgroup at_apb_clkrstgen_regs_core_cluster_sel_stat_field cluster_sel_stat_field
 * @brief macros for field cluster_sel_stat
 * @details status of cluster_sel
 * @{
 */
#define CLKRSTGEN_CLK_BP_CTRL_STAT__CLUSTER_SEL_STAT__SHIFT                   6
#define CLKRSTGEN_CLK_BP_CTRL_STAT__CLUSTER_SEL_STAT__WIDTH                   4
#define CLKRSTGEN_CLK_BP_CTRL_STAT__CLUSTER_SEL_STAT__MASK          0x000003c0U
#define CLKRSTGEN_CLK_BP_CTRL_STAT__CLUSTER_SEL_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define CLKRSTGEN_CLK_BP_CTRL_STAT__CLUSTER_SEL_STAT__RESET_VALUE   0x00000000U
/** @} */
#define CLKRSTGEN_CLK_BP_CTRL_STAT__TYPE                               uint32_t
#define CLKRSTGEN_CLK_BP_CTRL_STAT__READ                            0x000003ffU
#define CLKRSTGEN_CLK_BP_CTRL_STAT__PRESERVED                       0x00000000U
#define CLKRSTGEN_CLK_BP_CTRL_STAT__RESET_VALUE                     0x00000000U

#endif /* __CLKRSTGEN_CLK_BP_CTRL_STAT_MACRO__ */

/** @} end of clk_bp_ctrl_stat */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_clk_aud_ctrl */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk_aud_ctrl clk_aud_ctrl
 * @brief Contains register fields associated with clk_aud_ctrl. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_CLK_AUD_CTRL_MACRO__
#define __CLKRSTGEN_CLK_AUD_CTRL_MACRO__

/* macros for field pdm_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pdm_sel_field pdm_sel_field
 * @brief macros for field pdm_sel
 * @details selects the pdm clock source  0 = i2s clock divided by 1  1 = i2s clock divided by 2
 * @{
 */
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__SHIFT                                0
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__WIDTH                                1
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__MASK                       0x00000001U
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_SEL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field pdm_clk_enable */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pdm_clk_enable_field pdm_clk_enable_field
 * @brief macros for field pdm_clk_enable
 * @details enable pdm clock; make frequency selection (pdm_sel) only when disabled
 * @{
 */
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__SHIFT                         4
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__WIDTH                         1
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__MASK                0x00000010U
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CLKRSTGEN_CLK_AUD_CTRL__PDM_CLK_ENABLE__RESET_VALUE         0x00000000U
/** @} */

/* macros for field i2s_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_i2s_sel_field i2s_sel_field
 * @brief macros for field i2s_sel
 * @details selects the i2s clock source  0 = 16MHz  1 = 32MHz  2 = (pll frequency/1)  3 = (pll frequency/2)  4 = (pll frequency/3)  5 = (pll frequency/4)  6 = (pll frequency/5)  7 = (pll frequency/6)  8 = (pll frequency/7)  9 = (pll frequency/8)
 * @{
 */
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__SHIFT                                5
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__WIDTH                                4
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__MASK                       0x000001e0U
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001e0U) >> 5)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000001e0U)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001e0U) | (((uint32_t)(src) <<\
                    5) & 0x000001e0U)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000001e0U)))
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_SEL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field i2s_clk_enable */
/**
 * @defgroup at_apb_clkrstgen_regs_core_i2s_clk_enable_field i2s_clk_enable_field
 * @brief macros for field i2s_clk_enable
 * @details enable i2s clock; make frequency selection (i2s_sel) only when disabled
 * @{
 */
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__SHIFT                         9
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__WIDTH                         1
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__MASK                0x00000200U
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define CLKRSTGEN_CLK_AUD_CTRL__I2S_CLK_ENABLE__RESET_VALUE         0x00000000U
/** @} */
#define CLKRSTGEN_CLK_AUD_CTRL__TYPE                                   uint32_t
#define CLKRSTGEN_CLK_AUD_CTRL__READ                                0x000003f1U
#define CLKRSTGEN_CLK_AUD_CTRL__WRITE                               0x000003f1U
#define CLKRSTGEN_CLK_AUD_CTRL__PRESERVED                           0x00000000U
#define CLKRSTGEN_CLK_AUD_CTRL__RESET_VALUE                         0x00000000U

#endif /* __CLKRSTGEN_CLK_AUD_CTRL_MACRO__ */

/** @} end of clk_aud_ctrl */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_pll_ctrl */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_ctrl pll_ctrl
 * @brief Contains register fields associated with pll_ctrl. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_PLL_CTRL_MACRO__
#define __CLKRSTGEN_PLL_CTRL_MACRO__

/* macros for field pll_freq_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_freq_sel_field pll_freq_sel_field
 * @brief macros for field pll_freq_sel
 * @details  0 = 48 MHz  1 = 56 MHz / reserved / don't use  2 = 64 MHz  3 = 72 MHz / reserved / don't use  4 = 80 MHz  5 = 88 MHz / reserved / don't use  6 = 96 MHz
 * @{
 */
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__SHIFT                               0
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__WIDTH                               4
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__MASK                      0x0000000fU
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define CLKRSTGEN_PLL_CTRL__PLL_FREQ_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field pll_enable */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_enable_field pll_enable_field
 * @brief macros for field pll_enable
 * @{
 */
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__SHIFT                                 4
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__WIDTH                                 1
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__MASK                        0x00000010U
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CLKRSTGEN_PLL_CTRL__PLL_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field pll_update */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_update_field pll_update_field
 * @brief macros for field pll_update
 * @{
 */
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__SHIFT                                 5
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__WIDTH                                 1
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__MASK                        0x00000020U
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define CLKRSTGEN_PLL_CTRL__PLL_UPDATE__RESET_VALUE                 0x00000000U
/** @} */
#define CLKRSTGEN_PLL_CTRL__TYPE                                       uint32_t
#define CLKRSTGEN_PLL_CTRL__READ                                    0x0000003fU
#define CLKRSTGEN_PLL_CTRL__WRITE                                   0x0000003fU
#define CLKRSTGEN_PLL_CTRL__PRESERVED                               0x00000000U
#define CLKRSTGEN_PLL_CTRL__RESET_VALUE                             0x00000000U

#endif /* __CLKRSTGEN_PLL_CTRL_MACRO__ */

/** @} end of pll_ctrl */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_user_resets */
/**
 * @defgroup at_apb_clkrstgen_regs_core_user_resets user_resets
 * @brief Contains register fields associated with user_resets. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_USER_RESETS_MACRO__
#define __CLKRSTGEN_USER_RESETS_MACRO__

/* macros for field ble_core */
/**
 * @defgroup at_apb_clkrstgen_regs_core_ble_core_field ble_core_field
 * @brief macros for field ble_core
 * @details forces reset into the LC core.
 * @{
 */
#define CLKRSTGEN_USER_RESETS__BLE_CORE__SHIFT                                0
#define CLKRSTGEN_USER_RESETS__BLE_CORE__WIDTH                                1
#define CLKRSTGEN_USER_RESETS__BLE_CORE__MASK                       0x00000001U
#define CLKRSTGEN_USER_RESETS__BLE_CORE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_USER_RESETS__BLE_CORE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_USER_RESETS__BLE_CORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_USER_RESETS__BLE_CORE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_USER_RESETS__BLE_CORE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_USER_RESETS__BLE_CORE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_USER_RESETS__BLE_CORE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ble_intf */
/**
 * @defgroup at_apb_clkrstgen_regs_core_ble_intf_field ble_intf_field
 * @brief macros for field ble_intf
 * @details forces reset into ahb register file.
 * @{
 */
#define CLKRSTGEN_USER_RESETS__BLE_INTF__SHIFT                                1
#define CLKRSTGEN_USER_RESETS__BLE_INTF__WIDTH                                1
#define CLKRSTGEN_USER_RESETS__BLE_INTF__MASK                       0x00000002U
#define CLKRSTGEN_USER_RESETS__BLE_INTF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_USER_RESETS__BLE_INTF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CLKRSTGEN_USER_RESETS__BLE_INTF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CLKRSTGEN_USER_RESETS__BLE_INTF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CLKRSTGEN_USER_RESETS__BLE_INTF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_USER_RESETS__BLE_INTF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_USER_RESETS__BLE_INTF__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ble_lowp */
/**
 * @defgroup at_apb_clkrstgen_regs_core_ble_lowp_field ble_lowp_field
 * @brief macros for field ble_lowp
 * @details forces reset into low power sleep FSM.
 * @{
 */
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__SHIFT                                2
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__WIDTH                                1
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__MASK                       0x00000004U
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_USER_RESETS__BLE_LOWP__RESET_VALUE                0x00000000U
/** @} */

/* macros for field mdm_rif */
/**
 * @defgroup at_apb_clkrstgen_regs_core_mdm_rif_field mdm_rif_field
 * @brief macros for field mdm_rif
 * @details forces a reset into both mdm and rif cores
 * @{
 */
#define CLKRSTGEN_USER_RESETS__MDM_RIF__SHIFT                                 3
#define CLKRSTGEN_USER_RESETS__MDM_RIF__WIDTH                                 1
#define CLKRSTGEN_USER_RESETS__MDM_RIF__MASK                        0x00000008U
#define CLKRSTGEN_USER_RESETS__MDM_RIF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CLKRSTGEN_USER_RESETS__MDM_RIF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CLKRSTGEN_USER_RESETS__MDM_RIF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CLKRSTGEN_USER_RESETS__MDM_RIF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CLKRSTGEN_USER_RESETS__MDM_RIF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CLKRSTGEN_USER_RESETS__MDM_RIF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CLKRSTGEN_USER_RESETS__MDM_RIF__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field use_arm_clkdivs */
/**
 * @defgroup at_apb_clkrstgen_regs_core_use_arm_clkdivs_field use_arm_clkdivs_field
 * @brief macros for field use_arm_clkdivs
 * @{
 */
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__SHIFT                        31
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__WIDTH                         1
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__MASK                0x80000000U
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define CLKRSTGEN_USER_RESETS__USE_ARM_CLKDIVS__RESET_VALUE         0x00000000U
/** @} */
#define CLKRSTGEN_USER_RESETS__TYPE                                    uint32_t
#define CLKRSTGEN_USER_RESETS__READ                                 0x8000000fU
#define CLKRSTGEN_USER_RESETS__WRITE                                0x8000000fU
#define CLKRSTGEN_USER_RESETS__PRESERVED                            0x00000000U
#define CLKRSTGEN_USER_RESETS__RESET_VALUE                          0x00000000U

#endif /* __CLKRSTGEN_USER_RESETS_MACRO__ */

/** @} end of user_resets */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_user_clk_disables */
/**
 * @defgroup at_apb_clkrstgen_regs_core_user_clk_disables user_clk_disables
 * @brief Contains register fields associated with user_clk_disables. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_USER_CLK_DISABLES_MACRO__
#define __CLKRSTGEN_USER_CLK_DISABLES_MACRO__

/* macros for field mdm_rif */
/**
 * @defgroup at_apb_clkrstgen_regs_core_mdm_rif_field mdm_rif_field
 * @brief macros for field mdm_rif
 * @details turns off 8MHz and 16MHz clocks going to mdm and rif cores
 * @{
 */
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__SHIFT                           0
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__WIDTH                           1
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__MASK                  0x00000001U
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_USER_CLK_DISABLES__MDM_RIF__RESET_VALUE           0x00000000U
/** @} */

/* macros for field pdm */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pdm_field pdm_field
 * @brief macros for field pdm
 * @{
 */
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__SHIFT                               1
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__WIDTH                               1
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__MASK                      0x00000002U
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_USER_CLK_DISABLES__PDM__RESET_VALUE               0x00000000U
/** @} */

/* macros for field i2s */
/**
 * @defgroup at_apb_clkrstgen_regs_core_i2s_field i2s_field
 * @brief macros for field i2s
 * @{
 */
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__SHIFT                               2
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__WIDTH                               1
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__MASK                      0x00000004U
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_USER_CLK_DISABLES__I2S__RESET_VALUE               0x00000000U
/** @} */

/* macros for field cpu_lpc */
/**
 * @defgroup at_apb_clkrstgen_regs_core_cpu_lpc_field cpu_lpc_field
 * @brief macros for field cpu_lpc
 * @{
 */
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__SHIFT                           3
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__WIDTH                           1
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__MASK                  0x00000008U
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CLKRSTGEN_USER_CLK_DISABLES__CPU_LPC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field hyper */
/**
 * @defgroup at_apb_clkrstgen_regs_core_hyper_field hyper_field
 * @brief macros for field hyper
 * @{
 */
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__SHIFT                             4
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__WIDTH                             1
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__MASK                    0x00000010U
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CLKRSTGEN_USER_CLK_DISABLES__HYPER__RESET_VALUE             0x00000000U
/** @} */

/* macros for field cal */
/**
 * @defgroup at_apb_clkrstgen_regs_core_cal_field cal_field
 * @brief macros for field cal
 * @details radio.calfc_out
 * @{
 */
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__SHIFT                               5
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__WIDTH                               1
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__MASK                      0x00000020U
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define CLKRSTGEN_USER_CLK_DISABLES__CAL__RESET_VALUE               0x00000001U
/** @} */
#define CLKRSTGEN_USER_CLK_DISABLES__TYPE                              uint32_t
#define CLKRSTGEN_USER_CLK_DISABLES__READ                           0x0000003fU
#define CLKRSTGEN_USER_CLK_DISABLES__WRITE                          0x0000003fU
#define CLKRSTGEN_USER_CLK_DISABLES__PRESERVED                      0x00000000U
#define CLKRSTGEN_USER_CLK_DISABLES__RESET_VALUE                    0x00000020U

#endif /* __CLKRSTGEN_USER_CLK_DISABLES_MACRO__ */

/** @} end of user_clk_disables */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_user_clk_gate_force_on */
/**
 * @defgroup at_apb_clkrstgen_regs_core_user_clk_gate_force_on user_clk_gate_force_on
 * @brief Contains register fields associated with user_clk_gate_force_on. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_USER_CLK_GATE_FORCE_ON_MACRO__
#define __CLKRSTGEN_USER_CLK_GATE_FORCE_ON_MACRO__

/* macros for field ble52_hgclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_ble52_hgclk_field ble52_hgclk_field
 * @brief macros for field ble52_hgclk
 * @details The hgclk port of ble52 is normally clock gated by the ble52 core itself. If you want this clock to always run (for instance, for debug) then assert this signal.
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__SHIFT                  0
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__WIDTH                  1
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__MASK         0x00000001U
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__BLE52_HGCLK__RESET_VALUE  0x00000001U
/** @} */
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__TYPE                         uint32_t
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__READ                      0x00000001U
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__WRITE                     0x00000001U
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__PRESERVED                 0x00000000U
#define CLKRSTGEN_USER_CLK_GATE_FORCE_ON__RESET_VALUE               0x00000001U

#endif /* __CLKRSTGEN_USER_CLK_GATE_FORCE_ON_MACRO__ */

/** @} end of user_clk_gate_force_on */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_user_clk_gate_ctrl */
/**
 * @defgroup at_apb_clkrstgen_regs_core_user_clk_gate_ctrl user_clk_gate_ctrl
 * @brief Contains register fields associated with user_clk_gate_ctrl. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_USER_CLK_GATE_CTRL_MACRO__
#define __CLKRSTGEN_USER_CLK_GATE_CTRL_MACRO__

/* macros for field apb0_hclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_apb0_hclk_field apb0_hclk_field
 * @brief macros for field apb0_hclk
 * @details 0,3=normal; 1=forced on; 2=forced off
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__SHIFT                        0
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__WIDTH                        2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__MASK               0x00000003U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB0_HCLK__RESET_VALUE        0x00000001U
/** @} */

/* macros for field apb1_hclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_apb1_hclk_field apb1_hclk_field
 * @brief macros for field apb1_hclk
 * @details 0,3=normal; 1=forced on; 2=forced off
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__SHIFT                        2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__WIDTH                        2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__MASK               0x0000000cU
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB1_HCLK__RESET_VALUE        0x00000001U
/** @} */

/* macros for field apb2_hclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_apb2_hclk_field apb2_hclk_field
 * @brief macros for field apb2_hclk
 * @details 0,3=normal; 1=forced on; 2=forced off
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__SHIFT                        4
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__WIDTH                        2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__MASK               0x00000030U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__APB2_HCLK__RESET_VALUE        0x00000001U
/** @} */

/* macros for field dma_hclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_dma_hclk_field dma_hclk_field
 * @brief macros for field dma_hclk
 * @details 0,3=normal; 1=forced on; 2=forced off
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__SHIFT                         6
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__WIDTH                         2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__MASK                0x000000c0U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__DMA_HCLK__RESET_VALUE         0x00000001U
/** @} */

/* macros for field sha_hclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_sha_hclk_field sha_hclk_field
 * @brief macros for field sha_hclk
 * @details 0,3=normal; 1=forced on; 2=forced off
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__SHIFT                         8
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__WIDTH                         2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__MASK                0x00000300U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__RESET_VALUE         0x00000002U
/** @} */

/* macros for field romc_hclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_romc_hclk_field romc_hclk_field
 * @brief macros for field romc_hclk
 * @details 0,3=normal; 1=forced on; 2=forced off
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__SHIFT                       10
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__WIDTH                        2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__MASK               0x00000c00U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__ROMC_HCLK__RESET_VALUE        0x00000001U
/** @} */

/* macros for field ble_hclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_ble_hclk_field ble_hclk_field
 * @brief macros for field ble_hclk
 * @details 0,3=normal; 1=forced on; 2=forced off
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__SHIFT                        12
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__WIDTH                         2
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__MASK                0x00003000U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__BLE_HCLK__RESET_VALUE         0x00000001U
/** @} */

/* macros for field sticky_clk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_sticky_clk_field sticky_clk_field
 * @brief macros for field sticky_clk
 * @details 0=forced off; 1=forced on; clock enable signal to sticky bits.
 * @{
 */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__SHIFT                      14
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__WIDTH                       1
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__MASK              0x00004000U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__RESET_VALUE       0x00000000U
/** @} */
#define CLKRSTGEN_USER_CLK_GATE_CTRL__TYPE                             uint32_t
#define CLKRSTGEN_USER_CLK_GATE_CTRL__READ                          0x00007fffU
#define CLKRSTGEN_USER_CLK_GATE_CTRL__WRITE                         0x00007fffU
#define CLKRSTGEN_USER_CLK_GATE_CTRL__PRESERVED                     0x00000000U
#define CLKRSTGEN_USER_CLK_GATE_CTRL__RESET_VALUE                   0x00001655U

#endif /* __CLKRSTGEN_USER_CLK_GATE_CTRL_MACRO__ */

/** @} end of user_clk_gate_ctrl */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_configuration */
/**
 * @defgroup at_apb_clkrstgen_regs_core_configuration configuration
 * @brief Contains register fields associated with configuration. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_CONFIGURATION_MACRO__
#define __CLKRSTGEN_CONFIGURATION_MACRO__

/* macros for field index */
/**
 * @defgroup at_apb_clkrstgen_regs_core_index_field index_field
 * @brief macros for field index
 * @details which fpga configuration?
 * @{
 */
#define CLKRSTGEN_CONFIGURATION__INDEX__SHIFT                                 0
#define CLKRSTGEN_CONFIGURATION__INDEX__WIDTH                                 8
#define CLKRSTGEN_CONFIGURATION__INDEX__MASK                        0x000000ffU
#define CLKRSTGEN_CONFIGURATION__INDEX__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define CLKRSTGEN_CONFIGURATION__INDEX__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field pll_ready */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_ready_field pll_ready_field
 * @brief macros for field pll_ready
 * @details indicates when PLL output is no longer being gated and PLL clock is available
 * @{
 */
#define CLKRSTGEN_CONFIGURATION__PLL_READY__SHIFT                             8
#define CLKRSTGEN_CONFIGURATION__PLL_READY__WIDTH                             1
#define CLKRSTGEN_CONFIGURATION__PLL_READY__MASK                    0x00000100U
#define CLKRSTGEN_CONFIGURATION__PLL_READY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define CLKRSTGEN_CONFIGURATION__PLL_READY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define CLKRSTGEN_CONFIGURATION__PLL_READY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define CLKRSTGEN_CONFIGURATION__PLL_READY__RESET_VALUE             0x00000000U
/** @} */

/* macros for field index2 */
/**
 * @defgroup at_apb_clkrstgen_regs_core_index2_field index2_field
 * @brief macros for field index2
 * @details which fpga configuration?
 * @{
 */
#define CLKRSTGEN_CONFIGURATION__INDEX2__SHIFT                               16
#define CLKRSTGEN_CONFIGURATION__INDEX2__WIDTH                                8
#define CLKRSTGEN_CONFIGURATION__INDEX2__MASK                       0x00ff0000U
#define CLKRSTGEN_CONFIGURATION__INDEX2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define CLKRSTGEN_CONFIGURATION__INDEX2__RESET_VALUE                0x00000000U
/** @} */
#define CLKRSTGEN_CONFIGURATION__TYPE                                  uint32_t
#define CLKRSTGEN_CONFIGURATION__READ                               0x00ff01ffU
#define CLKRSTGEN_CONFIGURATION__PRESERVED                          0x00000000U
#define CLKRSTGEN_CONFIGURATION__RESET_VALUE                        0x00000000U

#endif /* __CLKRSTGEN_CONFIGURATION_MACRO__ */

/** @} end of configuration */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_clksync */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clksync clksync
 * @brief Contains register fields associated with clksync. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_CLKSYNC_MACRO__
#define __CLKRSTGEN_CLKSYNC_MACRO__

/* macros for field div_val */
/**
 * @defgroup at_apb_clkrstgen_regs_core_div_val_field div_val_field
 * @brief macros for field div_val
 * @details how much to divide the pll to get 16 MHz? only gets updated by SW when pll_enable is 0.
 * @{
 */
#define CLKRSTGEN_CLKSYNC__DIV_VAL__SHIFT                                     0
#define CLKRSTGEN_CLKSYNC__DIV_VAL__WIDTH                                     4
#define CLKRSTGEN_CLKSYNC__DIV_VAL__MASK                            0x0000000fU
#define CLKRSTGEN_CLKSYNC__DIV_VAL__READ(src)   ((uint32_t)(src) & 0x0000000fU)
#define CLKRSTGEN_CLKSYNC__DIV_VAL__WRITE(src)  ((uint32_t)(src) & 0x0000000fU)
#define CLKRSTGEN_CLKSYNC__DIV_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define CLKRSTGEN_CLKSYNC__DIV_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define CLKRSTGEN_CLKSYNC__DIV_VAL__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field clk16_src */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk16_src_field clk16_src_field
 * @brief macros for field clk16_src
 * @details selects the source of the 16 MHz clock domain  0 = crystal or dbl  1 = divided down pll
 * @{
 */
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__SHIFT                                   4
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__WIDTH                                   1
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__MASK                          0x00000010U
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field clk16_src_inner */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk16_src_inner_field clk16_src_inner_field
 * @brief macros for field clk16_src_inner
 * @details first selection layer. selects the source of the 16 MHz clock domain  0 = crystal 1 = dbl divided by 2
 * @{
 */
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__SHIFT                             5
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__WIDTH                             1
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__MASK                    0x00000020U
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__RESET_VALUE             0x00000000U
/** @} */
#define CLKRSTGEN_CLKSYNC__TYPE                                        uint32_t
#define CLKRSTGEN_CLKSYNC__READ                                     0x0000003fU
#define CLKRSTGEN_CLKSYNC__WRITE                                    0x0000003fU
#define CLKRSTGEN_CLKSYNC__PRESERVED                                0x00000000U
#define CLKRSTGEN_CLKSYNC__RESET_VALUE                              0x00000000U

#endif /* __CLKRSTGEN_CLKSYNC_MACRO__ */

/** @} end of clksync */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_radio_status */
/**
 * @defgroup at_apb_clkrstgen_regs_core_radio_status radio_status
 * @brief Contains register fields associated with radio_status. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_RADIO_STATUS_MACRO__
#define __CLKRSTGEN_RADIO_STATUS_MACRO__

/* macros for field xtal_stable */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_stable_field xtal_stable_field
 * @brief macros for field xtal_stable
 * @{
 */
#define CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__SHIFT                            0
#define CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__WIDTH                            1
#define CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__MASK                   0x00000001U
#define CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__RESET_VALUE            0x00000000U
/** @} */

/* macros for field soc_info */
/**
 * @defgroup at_apb_clkrstgen_regs_core_soc_info_field soc_info_field
 * @brief macros for field soc_info
 * @{
 */
#define CLKRSTGEN_RADIO_STATUS__SOC_INFO__SHIFT                               8
#define CLKRSTGEN_RADIO_STATUS__SOC_INFO__WIDTH                              24
#define CLKRSTGEN_RADIO_STATUS__SOC_INFO__MASK                      0xffffff00U
#define CLKRSTGEN_RADIO_STATUS__SOC_INFO__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffffff00U) >> 8)
#define CLKRSTGEN_RADIO_STATUS__SOC_INFO__RESET_VALUE               0x00000000U
/** @} */
#define CLKRSTGEN_RADIO_STATUS__TYPE                                   uint32_t
#define CLKRSTGEN_RADIO_STATUS__READ                                0xffffff01U
#define CLKRSTGEN_RADIO_STATUS__PRESERVED                           0x00000000U
#define CLKRSTGEN_RADIO_STATUS__RESET_VALUE                         0x00000000U

#endif /* __CLKRSTGEN_RADIO_STATUS_MACRO__ */

/** @} end of radio_status */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_atlc_lp_ctrl_0 */
/**
 * @defgroup at_apb_clkrstgen_regs_core_atlc_lp_ctrl_0 atlc_lp_ctrl_0
 * @brief Contains register fields associated with atlc_lp_ctrl_0. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_ATLC_LP_CTRL_0_MACRO__
#define __CLKRSTGEN_ATLC_LP_CTRL_0_MACRO__

/* macros for field lpc_period_frac */
/**
 * @defgroup at_apb_clkrstgen_regs_core_lpc_period_frac_field lpc_period_frac_field
 * @brief macros for field lpc_period_frac
 * @details fractional part of lower power clock period in microseconds (us)
 * @{
 */
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__SHIFT                      0
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__WIDTH                     23
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__MASK             0x007fffffU
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_FRAC__RESET_VALUE      0x00000000U
/** @} */

/* macros for field lpc_period_intg */
/**
 * @defgroup at_apb_clkrstgen_regs_core_lpc_period_intg_field lpc_period_intg_field
 * @brief macros for field lpc_period_intg
 * @details integer part of lower power clock period in microseconds (us)
 * @{
 */
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__SHIFT                     23
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__WIDTH                      7
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__MASK             0x3f800000U
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f800000U) >> 23)
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x3f800000U)
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f800000U) | (((uint32_t)(src) <<\
                    23) & 0x3f800000U)
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x3f800000U)))
#define CLKRSTGEN_ATLC_LP_CTRL_0__LPC_PERIOD_INTG__RESET_VALUE      0x00000000U
/** @} */
#define CLKRSTGEN_ATLC_LP_CTRL_0__TYPE                                 uint32_t
#define CLKRSTGEN_ATLC_LP_CTRL_0__READ                              0x3fffffffU
#define CLKRSTGEN_ATLC_LP_CTRL_0__WRITE                             0x3fffffffU
#define CLKRSTGEN_ATLC_LP_CTRL_0__PRESERVED                         0x00000000U
#define CLKRSTGEN_ATLC_LP_CTRL_0__RESET_VALUE                       0x00000000U

#endif /* __CLKRSTGEN_ATLC_LP_CTRL_0_MACRO__ */

/** @} end of atlc_lp_ctrl_0 */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_atlc_lp_ctrl_1 */
/**
 * @defgroup at_apb_clkrstgen_regs_core_atlc_lp_ctrl_1 atlc_lp_ctrl_1
 * @brief Contains register fields associated with atlc_lp_ctrl_1. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_ATLC_LP_CTRL_1_MACRO__
#define __CLKRSTGEN_ATLC_LP_CTRL_1_MACRO__

/* macros for field slp_cntr_in_1us_frac_residue_load */
/**
 * @defgroup at_apb_clkrstgen_regs_core_slp_cntr_in_1us_frac_residue_load_field slp_cntr_in_1us_frac_residue_load_field
 * @brief macros for field slp_cntr_in_1us_frac_residue_load
 * @details 1= passed onto clk_lpc domain; to apply slp_cntr_in_1us_frac_residue_val to the running slp_cntr_in_1us_frac_residue at the start of ATLC sleep.
 * @{
 */
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__SHIFT    0
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__WIDTH    1
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__MASK \
                    0x00000001U
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_ATLC_LP_CTRL_1__SLP_CNTR_IN_1US_FRAC_RESIDUE_LOAD__RESET_VALUE \
                    0x00000000U
/** @} */
#define CLKRSTGEN_ATLC_LP_CTRL_1__TYPE                                 uint32_t
#define CLKRSTGEN_ATLC_LP_CTRL_1__READ                              0x00000001U
#define CLKRSTGEN_ATLC_LP_CTRL_1__WRITE                             0x00000001U
#define CLKRSTGEN_ATLC_LP_CTRL_1__PRESERVED                         0x00000000U
#define CLKRSTGEN_ATLC_LP_CTRL_1__RESET_VALUE                       0x00000000U

#endif /* __CLKRSTGEN_ATLC_LP_CTRL_1_MACRO__ */

/** @} end of atlc_lp_ctrl_1 */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_fsm_ctrl */
/**
 * @defgroup at_apb_clkrstgen_regs_core_fsm_ctrl fsm_ctrl
 * @brief Contains register fields associated with fsm_ctrl. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_FSM_CTRL_MACRO__
#define __CLKRSTGEN_FSM_CTRL_MACRO__

/* macros for field target_freq */
/**
 * @defgroup at_apb_clkrstgen_regs_core_target_freq_field target_freq_field
 * @brief macros for field target_freq
 * @details ramp-up target frequency 1= doubler cluster is requested; 0= 16M is requested.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__SHIFT                                0
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__WIDTH                                1
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__MASK                       0x00000001U
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_FSM_CTRL__TARGET_FREQ__RESET_VALUE                0x00000000U
/** @} */

/* macros for field clr_fsm */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clr_fsm_field clr_fsm_field
 * @brief macros for field clr_fsm
 * @details 1=keep fsm in IDLE
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__SHIFT                                    1
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__WIDTH                                    1
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__MASK                           0x00000002U
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_FSM_CTRL__CLR_FSM__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field wait4xtal */
/**
 * @defgroup at_apb_clkrstgen_regs_core_wait4xtal_field wait4xtal_field
 * @brief macros for field wait4xtal
 * @details 1=wait for xtal_stable before requesting clock doubler.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__SHIFT                                  2
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__WIDTH                                  1
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__MASK                         0x00000004U
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_FSM_CTRL__WAIT4XTAL__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field abort_fsm */
/**
 * @defgroup at_apb_clkrstgen_regs_core_abort_fsm_field abort_fsm_field
 * @brief macros for field abort_fsm
 * @details 1=abort fsm while waiting for xtal or doubler.(__SELF_CLEARING__).
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__SHIFT                                  3
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__WIDTH                                  1
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__MASK                         0x00000008U
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CLKRSTGEN_FSM_CTRL__ABORT_FSM__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field go_on_cpu_sleep_wkup */
/**
 * @defgroup at_apb_clkrstgen_regs_core_go_on_cpu_sleep_wkup_field go_on_cpu_sleep_wkup_field
 * @brief macros for field go_on_cpu_sleep_wkup
 * @details 1= start bp_clk ramp-up on falling edge of cpu_sleep.  If set, the clock ramp up will start on falling edge of cpu_sleep.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__SHIFT                      16
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__WIDTH                       1
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__MASK              0x00010000U
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__RESET_VALUE       0x00000000U
/** @} */

/* macros for field go_on_cpu_sleepdeep_wkup */
/**
 * @defgroup at_apb_clkrstgen_regs_core_go_on_cpu_sleepdeep_wkup_field go_on_cpu_sleepdeep_wkup_field
 * @brief macros for field go_on_cpu_sleepdeep_wkup
 * @details 1= start bp_clk ramp-up on falling edge of cpu_sleepdeep.  If set, the clock ramp up will start on falling edge of cpu_sleepdeep.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__SHIFT                  17
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__WIDTH                   1
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__MASK          0x00020000U
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP_WKUP__RESET_VALUE   0x00000000U
/** @} */

/* macros for field go_on_pseq_wkup */
/**
 * @defgroup at_apb_clkrstgen_regs_core_go_on_pseq_wkup_field go_on_pseq_wkup_field
 * @brief macros for field go_on_pseq_wkup
 * @details 1= start on pseq wakeup.  If set, the clock ramp up will start as part of the pseq power up sequence.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__SHIFT                           18
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__WIDTH                            1
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__MASK                   0x00040000U
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define CLKRSTGEN_FSM_CTRL__GO_ON_PSEQ_WKUP__RESET_VALUE            0x00000000U
/** @} */

/* macros for field go_on_cpu_sleep */
/**
 * @defgroup at_apb_clkrstgen_regs_core_go_on_cpu_sleep_field go_on_cpu_sleep_field
 * @brief macros for field go_on_cpu_sleep
 * @details 1= start bp_clk ramp-down on rising edge of cpu_sleep.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__SHIFT                           19
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__WIDTH                            1
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__MASK                   0x00080000U
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__RESET_VALUE            0x00000000U
/** @} */

/* macros for field go_on_cpu_sleepdeep */
/**
 * @defgroup at_apb_clkrstgen_regs_core_go_on_cpu_sleepdeep_field go_on_cpu_sleepdeep_field
 * @brief macros for field go_on_cpu_sleepdeep
 * @details 1= start bp_clk ramp-down on rising edge of cpu_sleepdeep.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__SHIFT                       20
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__WIDTH                        1
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__MASK               0x00100000U
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEPDEEP__RESET_VALUE        0x00000000U
/** @} */

/* macros for field turnoff_doubler */
/**
 * @defgroup at_apb_clkrstgen_regs_core_turnoff_doubler_field turnoff_doubler_field
 * @brief macros for field turnoff_doubler
 * @details 1= turn off doubler request in ramp-down.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__SHIFT                           21
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__WIDTH                            1
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__MASK                   0x00200000U
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__RESET_VALUE            0x00000000U
/** @} */

/* macros for field clk16_src_inner_val */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk16_src_inner_val_field clk16_src_inner_val_field
 * @brief macros for field clk16_src_inner_val
 * @details write value to clk16_src_inner in ramp-up.
 * @{
 */
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__SHIFT                       22
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__WIDTH                        1
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__MASK               0x00400000U
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__RESET_VALUE        0x00000001U
/** @} */
#define CLKRSTGEN_FSM_CTRL__TYPE                                       uint32_t
#define CLKRSTGEN_FSM_CTRL__READ                                    0x007f000fU
#define CLKRSTGEN_FSM_CTRL__WRITE                                   0x007f000fU
#define CLKRSTGEN_FSM_CTRL__PRESERVED                               0x00000000U
#define CLKRSTGEN_FSM_CTRL__RESET_VALUE                             0x00400004U

#endif /* __CLKRSTGEN_FSM_CTRL_MACRO__ */

/** @} end of fsm_ctrl */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_fsm_wait4doubler */
/**
 * @defgroup at_apb_clkrstgen_regs_core_fsm_wait4doubler fsm_wait4doubler
 * @brief Contains register fields associated with fsm_wait4doubler. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_FSM_WAIT4DOUBLER_MACRO__
#define __CLKRSTGEN_FSM_WAIT4DOUBLER_MACRO__

/* macros for field wait4doubler_dur */
/**
 * @defgroup at_apb_clkrstgen_regs_core_wait4doubler_dur_field wait4doubler_dur_field
 * @brief macros for field wait4doubler_dur
 * @details number of cycles (in clk16) to wait after asserting clkhpc_en
 * @{
 */
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__SHIFT                   0
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__WIDTH                   9
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__MASK          0x000001ffU
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WAIT4DOUBLER_DUR__RESET_VALUE   0x00000050U
/** @} */
#define CLKRSTGEN_FSM_WAIT4DOUBLER__TYPE                               uint32_t
#define CLKRSTGEN_FSM_WAIT4DOUBLER__READ                            0x000001ffU
#define CLKRSTGEN_FSM_WAIT4DOUBLER__WRITE                           0x000001ffU
#define CLKRSTGEN_FSM_WAIT4DOUBLER__PRESERVED                       0x00000000U
#define CLKRSTGEN_FSM_WAIT4DOUBLER__RESET_VALUE                     0x00000050U

#endif /* __CLKRSTGEN_FSM_WAIT4DOUBLER_MACRO__ */

/** @} end of fsm_wait4doubler */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_fsm_status */
/**
 * @defgroup at_apb_clkrstgen_regs_core_fsm_status fsm_status
 * @brief Contains register fields associated with fsm_status. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_FSM_STATUS_MACRO__
#define __CLKRSTGEN_FSM_STATUS_MACRO__

/* macros for field state */
/**
 * @defgroup at_apb_clkrstgen_regs_core_state_field state_field
 * @brief macros for field state
 * @{
 */
#define CLKRSTGEN_FSM_STATUS__STATE__SHIFT                                    0
#define CLKRSTGEN_FSM_STATUS__STATE__WIDTH                                   13
#define CLKRSTGEN_FSM_STATUS__STATE__MASK                           0x00001fffU
#define CLKRSTGEN_FSM_STATUS__STATE__READ(src)  ((uint32_t)(src) & 0x00001fffU)
#define CLKRSTGEN_FSM_STATUS__STATE__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field wait4doubler_ready */
/**
 * @defgroup at_apb_clkrstgen_regs_core_wait4doubler_ready_field wait4doubler_ready_field
 * @brief macros for field wait4doubler_ready
 * @details 1=if wait4doubler counter is 0.
 * @{
 */
#define CLKRSTGEN_FSM_STATUS__WAIT4DOUBLER_READY__SHIFT                      30
#define CLKRSTGEN_FSM_STATUS__WAIT4DOUBLER_READY__WIDTH                       1
#define CLKRSTGEN_FSM_STATUS__WAIT4DOUBLER_READY__MASK              0x40000000U
#define CLKRSTGEN_FSM_STATUS__WAIT4DOUBLER_READY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define CLKRSTGEN_FSM_STATUS__WAIT4DOUBLER_READY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define CLKRSTGEN_FSM_STATUS__WAIT4DOUBLER_READY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define CLKRSTGEN_FSM_STATUS__WAIT4DOUBLER_READY__RESET_VALUE       0x00000000U
/** @} */

/* macros for field up_down_req_done */
/**
 * @defgroup at_apb_clkrstgen_regs_core_up_down_req_done_field up_down_req_done_field
 * @brief macros for field up_down_req_done
 * @details 0=last request was ramp-down; 1= last request was ramp-up.
 * @{
 */
#define CLKRSTGEN_FSM_STATUS__UP_DOWN_REQ_DONE__SHIFT                        31
#define CLKRSTGEN_FSM_STATUS__UP_DOWN_REQ_DONE__WIDTH                         1
#define CLKRSTGEN_FSM_STATUS__UP_DOWN_REQ_DONE__MASK                0x80000000U
#define CLKRSTGEN_FSM_STATUS__UP_DOWN_REQ_DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define CLKRSTGEN_FSM_STATUS__UP_DOWN_REQ_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define CLKRSTGEN_FSM_STATUS__UP_DOWN_REQ_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define CLKRSTGEN_FSM_STATUS__UP_DOWN_REQ_DONE__RESET_VALUE         0x00000001U
/** @} */
#define CLKRSTGEN_FSM_STATUS__TYPE                                     uint32_t
#define CLKRSTGEN_FSM_STATUS__READ                                  0xc0001fffU
#define CLKRSTGEN_FSM_STATUS__PRESERVED                             0x00000000U
#define CLKRSTGEN_FSM_STATUS__RESET_VALUE                           0x80000000U

#endif /* __CLKRSTGEN_FSM_STATUS_MACRO__ */

/** @} end of fsm_status */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_xtal_bits0 */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_bits0 xtal_bits0
 * @brief Contains register fields associated with xtal_bits0. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_XTAL_BITS0_MACRO__
#define __CLKRSTGEN_XTAL_BITS0_MACRO__

/* macros for field xtalfreq */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtalfreq_field xtalfreq_field
 * @brief macros for field xtalfreq
 * @details 0=16MHz 1=8MHz
 * @{
 */
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__SHIFT                                 0
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__WIDTH                                 1
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__MASK                        0x00000001U
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_XTAL_BITS0__XTALFREQ__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field xocapin */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xocapin_field xocapin_field
 * @brief macros for field xocapin
 * @details 16MHz crystal tuning cap on XTALI_16M pin, typically set to same value as xocapout
 * @{
 */
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__SHIFT                                  1
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__WIDTH                                  8
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__MASK                         0x000001feU
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define CLKRSTGEN_XTAL_BITS0__XOCAPIN__RESET_VALUE                  0x000000b8U
/** @} */

/* macros for field xocapout */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xocapout_field xocapout_field
 * @brief macros for field xocapout
 * @details 16MHz crystal tuning cap on XTALO_16M pin, typically set to same value as xocapin
 * @{
 */
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__SHIFT                                 9
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__WIDTH                                 8
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__MASK                        0x0001fe00U
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define CLKRSTGEN_XTAL_BITS0__XOCAPOUT__RESET_VALUE                 0x000000b8U
/** @} */

/* macros for field xobufn */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xobufn_field xobufn_field
 * @brief macros for field xobufn
 * @{
 */
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__SHIFT                                  17
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__WIDTH                                   2
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__MASK                          0x00060000U
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define CLKRSTGEN_XTAL_BITS0__XOBUFN__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field xobufp */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xobufp_field xobufp_field
 * @brief macros for field xobufp
 * @{
 */
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__SHIFT                                  19
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__WIDTH                                   2
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__MASK                          0x00180000U
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define CLKRSTGEN_XTAL_BITS0__XOBUFP__RESET_VALUE                   0x00000001U
/** @} */
#define CLKRSTGEN_XTAL_BITS0__TYPE                                     uint32_t
#define CLKRSTGEN_XTAL_BITS0__READ                                  0x001fffffU
#define CLKRSTGEN_XTAL_BITS0__WRITE                                 0x001fffffU
#define CLKRSTGEN_XTAL_BITS0__PRESERVED                             0x00000000U
#define CLKRSTGEN_XTAL_BITS0__RESET_VALUE                           0x000b7170U

#endif /* __CLKRSTGEN_XTAL_BITS0_MACRO__ */

/** @} end of xtal_bits0 */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_xtal_bits1 */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_bits1 xtal_bits1
 * @brief Contains register fields associated with xtal_bits1. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_XTAL_BITS1_MACRO__
#define __CLKRSTGEN_XTAL_BITS1_MACRO__

/* macros for field xobias */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xobias_field xobias_field
 * @brief macros for field xobias
 * @details 16MHz bias current setting or AGC target value when AGC enabled
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__SHIFT                                   0
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__WIDTH                                   4
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__MASK                          0x0000000fU
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__READ(src) ((uint32_t)(src) & 0x0000000fU)
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define CLKRSTGEN_XTAL_BITS1__XOBIAS__RESET_VALUE                   0x0000000cU
/** @} */

/* macros for field xoagc_en */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xoagc_en_field xoagc_en_field
 * @brief macros for field xoagc_en
 * @details Enable AGC for 16MHz xtal
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__SHIFT                                 4
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__WIDTH                                 1
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__MASK                        0x00000010U
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CLKRSTGEN_XTAL_BITS1__XOAGC_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field xofaststart */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xofaststart_field xofaststart_field
 * @brief macros for field xofaststart
 * @details Speed up crystal settling, 7 - max
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__SHIFT                              5
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__WIDTH                              3
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__MASK                     0x000000e0U
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000e0U) >> 5)
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000000e0U)
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000000e0U)))
#define CLKRSTGEN_XTAL_BITS1__XOFASTSTART__RESET_VALUE              0x00000007U
/** @} */

/* macros for field xosettle */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xosettle_field xosettle_field
 * @brief macros for field xosettle
 * @details 16MHz xtal settling time after which clock source is switched to xtal, in 64us steps, min valid setting is 1, do not set to 0
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__SHIFT                                 8
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__WIDTH                                 6
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__MASK                        0x00003f00U
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))
#define CLKRSTGEN_XTAL_BITS1__XOSETTLE__RESET_VALUE                 0x00000012U
/** @} */

/* macros for field rcoscfreq */
/**
 * @defgroup at_apb_clkrstgen_regs_core_rcoscfreq_field rcoscfreq_field
 * @brief macros for field rcoscfreq
 * @details 16MHz RC oscillator frequency tuning, 0 - slowest, 15 - fastest
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__SHIFT                               14
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__WIDTH                                4
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__MASK                       0x0003c000U
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003c000U) >> 14)
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0003c000U)
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003c000U) | (((uint32_t)(src) <<\
                    14) & 0x0003c000U)
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0003c000U)))
#define CLKRSTGEN_XTAL_BITS1__RCOSCFREQ__RESET_VALUE                0x00000009U
/** @} */

/* macros for field doublerdcc_en */
/**
 * @defgroup at_apb_clkrstgen_regs_core_doublerdcc_en_field doublerdcc_en_field
 * @brief macros for field doublerdcc_en
 * @details enable duty cycle correction for clock doubler
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__SHIFT                           18
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__WIDTH                            1
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__MASK                   0x00040000U
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define CLKRSTGEN_XTAL_BITS1__DOUBLERDCC_EN__RESET_VALUE            0x00000001U
/** @} */

/* macros for field clkhpc_en */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clkhpc_en_field clkhpc_en_field
 * @brief macros for field clkhpc_en
 * @details enable root clk_hpc buffer
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__SHIFT                               19
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__WIDTH                                1
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__MASK                       0x00080000U
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__RESET_VALUE                0x00000000U
/** @} */

/* macros for field clkmpc_en */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clkmpc_en_field clkmpc_en_field
 * @brief macros for field clkmpc_en
 * @details enable root clk_mpc buffer; chip will not be operational if cleared
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__SHIFT                               20
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__WIDTH                                1
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__MASK                       0x00100000U
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define CLKRSTGEN_XTAL_BITS1__CLKMPC_EN__RESET_VALUE                0x00000001U
/** @} */

/* macros for field extclk */
/**
 * @defgroup at_apb_clkrstgen_regs_core_extclk_field extclk_field
 * @brief macros for field extclk
 * @details Set to 1 if supplying external clock source on XTALI_16M pin
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__SHIFT                                  21
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__WIDTH                                   1
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__MASK                          0x00200000U
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define CLKRSTGEN_XTAL_BITS1__EXTCLK__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field xtal_spare */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_spare_field xtal_spare_field
 * @brief macros for field xtal_spare
 * @details unused spare bits (Enable short current mirror, min tuning cap, fast start timer to 512us)
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__SHIFT                              22
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__WIDTH                               6
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__MASK                      0x0fc00000U
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fc00000U) >> 22)
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x0fc00000U)
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fc00000U) | (((uint32_t)(src) <<\
                    22) & 0x0fc00000U)
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x0fc00000U)))
#define CLKRSTGEN_XTAL_BITS1__XTAL_SPARE__RESET_VALUE               0x0000002cU
/** @} */

/* macros for field clk_lpc2x_sel */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk_lpc2x_sel_field clk_lpc2x_sel_field
 * @brief macros for field clk_lpc2x_sel
 * @details 1=selects lpcx2 0=selects lpc
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__SHIFT                           28
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__WIDTH                            1
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__MASK                   0x10000000U
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define CLKRSTGEN_XTAL_BITS1__CLK_LPC2X_SEL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field clk_cp_src */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk_cp_src_field clk_cp_src_field
 * @brief macros for field clk_cp_src
 * @details 0=32kHz 1=64kHz
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__SHIFT                              29
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__WIDTH                               1
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__MASK                      0x20000000U
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define CLKRSTGEN_XTAL_BITS1__CLK_CP_SRC__RESET_VALUE               0x00000000U
/** @} */

/* macros for field override_32kHz_doubler_enable_val */
/**
 * @defgroup at_apb_clkrstgen_regs_core_override_32kHz_doubler_enable_val_field override_32kHz_doubler_enable_val_field
 * @brief macros for field override_32kHz_doubler_enable_val
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__SHIFT       30
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__WIDTH        1
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__MASK \
                    0x40000000U
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_32kHz_doubler_enable */
/**
 * @defgroup at_apb_clkrstgen_regs_core_override_32kHz_doubler_enable_field override_32kHz_doubler_enable_field
 * @brief macros for field override_32kHz_doubler_enable
 * @{
 */
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__SHIFT           31
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__WIDTH            1
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__MASK   0x80000000U
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define CLKRSTGEN_XTAL_BITS1__OVERRIDE_32KHZ_DOUBLER_ENABLE__RESET_VALUE \
                    0x00000000U
/** @} */
#define CLKRSTGEN_XTAL_BITS1__TYPE                                     uint32_t
#define CLKRSTGEN_XTAL_BITS1__READ                                  0xffffffffU
#define CLKRSTGEN_XTAL_BITS1__WRITE                                 0xffffffffU
#define CLKRSTGEN_XTAL_BITS1__PRESERVED                             0x00000000U
#define CLKRSTGEN_XTAL_BITS1__RESET_VALUE                           0x0b1652fcU

#endif /* __CLKRSTGEN_XTAL_BITS1_MACRO__ */

/** @} end of xtal_bits1 */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_pll */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll pll
 * @brief Contains register fields associated with pll. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_PLL_MACRO__
#define __CLKRSTGEN_PLL_MACRO__

/* macros for field filtr */
/**
 * @defgroup at_apb_clkrstgen_regs_core_filtr_field filtr_field
 * @brief macros for field filtr
 * @{
 */
#define CLKRSTGEN_PLL__FILTR__SHIFT                                           4
#define CLKRSTGEN_PLL__FILTR__WIDTH                                           4
#define CLKRSTGEN_PLL__FILTR__MASK                                  0x000000f0U
#define CLKRSTGEN_PLL__FILTR__READ(src)  (((uint32_t)(src) & 0x000000f0U) >> 4)
#define CLKRSTGEN_PLL__FILTR__WRITE(src) (((uint32_t)(src) << 4) & 0x000000f0U)
#define CLKRSTGEN_PLL__FILTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define CLKRSTGEN_PLL__FILTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define CLKRSTGEN_PLL__FILTR__RESET_VALUE                           0x00000008U
/** @} */

/* macros for field filtc */
/**
 * @defgroup at_apb_clkrstgen_regs_core_filtc_field filtc_field
 * @brief macros for field filtc
 * @{
 */
#define CLKRSTGEN_PLL__FILTC__SHIFT                                           8
#define CLKRSTGEN_PLL__FILTC__WIDTH                                           2
#define CLKRSTGEN_PLL__FILTC__MASK                                  0x00000300U
#define CLKRSTGEN_PLL__FILTC__READ(src)  (((uint32_t)(src) & 0x00000300U) >> 8)
#define CLKRSTGEN_PLL__FILTC__WRITE(src) (((uint32_t)(src) << 8) & 0x00000300U)
#define CLKRSTGEN_PLL__FILTC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define CLKRSTGEN_PLL__FILTC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define CLKRSTGEN_PLL__FILTC__RESET_VALUE                           0x00000003U
/** @} */

/* macros for field cpcur */
/**
 * @defgroup at_apb_clkrstgen_regs_core_cpcur_field cpcur_field
 * @brief macros for field cpcur
 * @{
 */
#define CLKRSTGEN_PLL__CPCUR__SHIFT                                          10
#define CLKRSTGEN_PLL__CPCUR__WIDTH                                           6
#define CLKRSTGEN_PLL__CPCUR__MASK                                  0x0000fc00U
#define CLKRSTGEN_PLL__CPCUR__READ(src) (((uint32_t)(src) & 0x0000fc00U) >> 10)
#define CLKRSTGEN_PLL__CPCUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define CLKRSTGEN_PLL__CPCUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define CLKRSTGEN_PLL__CPCUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define CLKRSTGEN_PLL__CPCUR__RESET_VALUE                           0x0000000fU
/** @} */

/* macros for field div2out */
/**
 * @defgroup at_apb_clkrstgen_regs_core_div2out_field div2out_field
 * @brief macros for field div2out
 * @{
 */
#define CLKRSTGEN_PLL__DIV2OUT__SHIFT                                        16
#define CLKRSTGEN_PLL__DIV2OUT__WIDTH                                         1
#define CLKRSTGEN_PLL__DIV2OUT__MASK                                0x00010000U
#define CLKRSTGEN_PLL__DIV2OUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define CLKRSTGEN_PLL__DIV2OUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define CLKRSTGEN_PLL__DIV2OUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define CLKRSTGEN_PLL__DIV2OUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define CLKRSTGEN_PLL__DIV2OUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define CLKRSTGEN_PLL__DIV2OUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define CLKRSTGEN_PLL__DIV2OUT__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field divout */
/**
 * @defgroup at_apb_clkrstgen_regs_core_divout_field divout_field
 * @brief macros for field divout
 * @{
 */
#define CLKRSTGEN_PLL__DIVOUT__SHIFT                                         17
#define CLKRSTGEN_PLL__DIVOUT__WIDTH                                          3
#define CLKRSTGEN_PLL__DIVOUT__MASK                                 0x000e0000U
#define CLKRSTGEN_PLL__DIVOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000e0000U) >> 17)
#define CLKRSTGEN_PLL__DIVOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x000e0000U)
#define CLKRSTGEN_PLL__DIVOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000e0000U) | (((uint32_t)(src) <<\
                    17) & 0x000e0000U)
#define CLKRSTGEN_PLL__DIVOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x000e0000U)))
#define CLKRSTGEN_PLL__DIVOUT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field divfb */
/**
 * @defgroup at_apb_clkrstgen_regs_core_divfb_field divfb_field
 * @brief macros for field divfb
 * @{
 */
#define CLKRSTGEN_PLL__DIVFB__SHIFT                                          20
#define CLKRSTGEN_PLL__DIVFB__WIDTH                                           6
#define CLKRSTGEN_PLL__DIVFB__MASK                                  0x03f00000U
#define CLKRSTGEN_PLL__DIVFB__READ(src) (((uint32_t)(src) & 0x03f00000U) >> 20)
#define CLKRSTGEN_PLL__DIVFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x03f00000U)
#define CLKRSTGEN_PLL__DIVFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03f00000U) | (((uint32_t)(src) <<\
                    20) & 0x03f00000U)
#define CLKRSTGEN_PLL__DIVFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x03f00000U)))
#define CLKRSTGEN_PLL__DIVFB__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field divref */
/**
 * @defgroup at_apb_clkrstgen_regs_core_divref_field divref_field
 * @brief macros for field divref
 * @{
 */
#define CLKRSTGEN_PLL__DIVREF__SHIFT                                         26
#define CLKRSTGEN_PLL__DIVREF__WIDTH                                          3
#define CLKRSTGEN_PLL__DIVREF__MASK                                 0x1c000000U
#define CLKRSTGEN_PLL__DIVREF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1c000000U) >> 26)
#define CLKRSTGEN_PLL__DIVREF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x1c000000U)
#define CLKRSTGEN_PLL__DIVREF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1c000000U) | (((uint32_t)(src) <<\
                    26) & 0x1c000000U)
#define CLKRSTGEN_PLL__DIVREF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x1c000000U)))
#define CLKRSTGEN_PLL__DIVREF__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field divaccess */
/**
 * @defgroup at_apb_clkrstgen_regs_core_divaccess_field divaccess_field
 * @brief macros for field divaccess
 * @{
 */
#define CLKRSTGEN_PLL__DIVACCESS__SHIFT                                      29
#define CLKRSTGEN_PLL__DIVACCESS__WIDTH                                       1
#define CLKRSTGEN_PLL__DIVACCESS__MASK                              0x20000000U
#define CLKRSTGEN_PLL__DIVACCESS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define CLKRSTGEN_PLL__DIVACCESS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define CLKRSTGEN_PLL__DIVACCESS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define CLKRSTGEN_PLL__DIVACCESS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define CLKRSTGEN_PLL__DIVACCESS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define CLKRSTGEN_PLL__DIVACCESS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define CLKRSTGEN_PLL__DIVACCESS__RESET_VALUE                       0x00000000U
/** @} */
#define CLKRSTGEN_PLL__TYPE                                            uint32_t
#define CLKRSTGEN_PLL__READ                                         0x3ffffff0U
#define CLKRSTGEN_PLL__WRITE                                        0x3ffffff0U
#define CLKRSTGEN_PLL__PRESERVED                                    0x00000000U
#define CLKRSTGEN_PLL__RESET_VALUE                                  0x00003f80U

#endif /* __CLKRSTGEN_PLL_MACRO__ */

/** @} end of pll */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_irq_mask */
/**
 * @defgroup at_apb_clkrstgen_regs_core_irq_mask irq_mask
 * @brief Contains register fields associated with irq_mask. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_IRQ_MASK_MACRO__
#define __CLKRSTGEN_IRQ_MASK_MACRO__

/* macros for field pll_ready_irq_mask */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_ready_irq_mask_field pll_ready_irq_mask_field
 * @brief macros for field pll_ready_irq_mask
 * @details 1= enable irq
 * @{
 */
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__SHIFT                         0
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__WIDTH                         1
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__MASK                0x00000001U
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_IRQ_MASK__PLL_READY_IRQ_MASK__RESET_VALUE         0x00000001U
/** @} */

/* macros for field xtal_stable_irq_mask */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_stable_irq_mask_field xtal_stable_irq_mask_field
 * @brief macros for field xtal_stable_irq_mask
 * @details 1= enable irq
 * @{
 */
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__SHIFT                       1
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__WIDTH                       1
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__MASK              0x00000002U
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_IRQ_MASK__XTAL_STABLE_IRQ_MASK__RESET_VALUE       0x00000001U
/** @} */

/* macros for field wait4doubler_irq_mask */
/**
 * @defgroup at_apb_clkrstgen_regs_core_wait4doubler_irq_mask_field wait4doubler_irq_mask_field
 * @brief macros for field wait4doubler_irq_mask
 * @details 1= enable irq
 * @{
 */
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__SHIFT                      2
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__WIDTH                      1
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__MASK             0x00000004U
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_IRQ_MASK__WAIT4DOUBLER_IRQ_MASK__RESET_VALUE      0x00000001U
/** @} */
#define CLKRSTGEN_IRQ_MASK__TYPE                                       uint32_t
#define CLKRSTGEN_IRQ_MASK__READ                                    0x00000007U
#define CLKRSTGEN_IRQ_MASK__WRITE                                   0x00000007U
#define CLKRSTGEN_IRQ_MASK__PRESERVED                               0x00000000U
#define CLKRSTGEN_IRQ_MASK__RESET_VALUE                             0x00000007U

#endif /* __CLKRSTGEN_IRQ_MASK_MACRO__ */

/** @} end of irq_mask */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_irq_set */
/**
 * @defgroup at_apb_clkrstgen_regs_core_irq_set irq_set
 * @brief Contains register fields associated with irq_set. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_IRQ_SET_MACRO__
#define __CLKRSTGEN_IRQ_SET_MACRO__

/* macros for field pll_ready_irq_set */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_ready_irq_set_field pll_ready_irq_set_field
 * @brief macros for field pll_ready_irq_set
 * @details 1= assert irq (__SELF_CLEARING__)
 * @{
 */
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__SHIFT                           0
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__WIDTH                           1
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__MASK                  0x00000001U
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_IRQ_SET__PLL_READY_IRQ_SET__RESET_VALUE           0x00000000U
/** @} */

/* macros for field xtal_stable_irq_set */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_stable_irq_set_field xtal_stable_irq_set_field
 * @brief macros for field xtal_stable_irq_set
 * @details 1= assert irq (__SELF_CLEARING__)
 * @{
 */
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__SHIFT                         1
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__WIDTH                         1
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__MASK                0x00000002U
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_IRQ_SET__XTAL_STABLE_IRQ_SET__RESET_VALUE         0x00000000U
/** @} */

/* macros for field wait4doubler_irq_set */
/**
 * @defgroup at_apb_clkrstgen_regs_core_wait4doubler_irq_set_field wait4doubler_irq_set_field
 * @brief macros for field wait4doubler_irq_set
 * @details 1= assert irq (__SELF_CLEARING__)
 * @{
 */
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__SHIFT                        2
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__WIDTH                        1
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__MASK               0x00000004U
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_IRQ_SET__WAIT4DOUBLER_IRQ_SET__RESET_VALUE        0x00000000U
/** @} */
#define CLKRSTGEN_IRQ_SET__TYPE                                        uint32_t
#define CLKRSTGEN_IRQ_SET__READ                                     0x00000007U
#define CLKRSTGEN_IRQ_SET__WRITE                                    0x00000007U
#define CLKRSTGEN_IRQ_SET__PRESERVED                                0x00000000U
#define CLKRSTGEN_IRQ_SET__RESET_VALUE                              0x00000000U

#endif /* __CLKRSTGEN_IRQ_SET_MACRO__ */

/** @} end of irq_set */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_irq_clr */
/**
 * @defgroup at_apb_clkrstgen_regs_core_irq_clr irq_clr
 * @brief Contains register fields associated with irq_clr. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_IRQ_CLR_MACRO__
#define __CLKRSTGEN_IRQ_CLR_MACRO__

/* macros for field pll_ready_irq_clr */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_ready_irq_clr_field pll_ready_irq_clr_field
 * @brief macros for field pll_ready_irq_clr
 * @details 1= clear irq (__SELF_CLEARING__)
 * @{
 */
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__SHIFT                           0
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__WIDTH                           1
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__MASK                  0x00000001U
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_IRQ_CLR__PLL_READY_IRQ_CLR__RESET_VALUE           0x00000000U
/** @} */

/* macros for field xtal_stable_irq_clr */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_stable_irq_clr_field xtal_stable_irq_clr_field
 * @brief macros for field xtal_stable_irq_clr
 * @details 1= clear irq (__SELF_CLEARING__)
 * @{
 */
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__SHIFT                         1
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__WIDTH                         1
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__MASK                0x00000002U
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_IRQ_CLR__XTAL_STABLE_IRQ_CLR__RESET_VALUE         0x00000000U
/** @} */

/* macros for field wait4doubler_irq_clr */
/**
 * @defgroup at_apb_clkrstgen_regs_core_wait4doubler_irq_clr_field wait4doubler_irq_clr_field
 * @brief macros for field wait4doubler_irq_clr
 * @details 1= assert irq (__SELF_CLEARING__)
 * @{
 */
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__SHIFT                        2
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__WIDTH                        1
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__MASK               0x00000004U
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_IRQ_CLR__WAIT4DOUBLER_IRQ_CLR__RESET_VALUE        0x00000000U
/** @} */
#define CLKRSTGEN_IRQ_CLR__TYPE                                        uint32_t
#define CLKRSTGEN_IRQ_CLR__READ                                     0x00000007U
#define CLKRSTGEN_IRQ_CLR__WRITE                                    0x00000007U
#define CLKRSTGEN_IRQ_CLR__PRESERVED                                0x00000000U
#define CLKRSTGEN_IRQ_CLR__RESET_VALUE                              0x00000000U

#endif /* __CLKRSTGEN_IRQ_CLR_MACRO__ */

/** @} end of irq_clr */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_irq_status */
/**
 * @defgroup at_apb_clkrstgen_regs_core_irq_status irq_status
 * @brief Contains register fields associated with irq_status. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_IRQ_STATUS_MACRO__
#define __CLKRSTGEN_IRQ_STATUS_MACRO__

/* macros for field pll_ready_irq_status */
/**
 * @defgroup at_apb_clkrstgen_regs_core_pll_ready_irq_status_field pll_ready_irq_status_field
 * @brief macros for field pll_ready_irq_status
 * @details irq_status
 * @{
 */
#define CLKRSTGEN_IRQ_STATUS__PLL_READY_IRQ_STATUS__SHIFT                     0
#define CLKRSTGEN_IRQ_STATUS__PLL_READY_IRQ_STATUS__WIDTH                     1
#define CLKRSTGEN_IRQ_STATUS__PLL_READY_IRQ_STATUS__MASK            0x00000001U
#define CLKRSTGEN_IRQ_STATUS__PLL_READY_IRQ_STATUS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CLKRSTGEN_IRQ_STATUS__PLL_READY_IRQ_STATUS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CLKRSTGEN_IRQ_STATUS__PLL_READY_IRQ_STATUS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CLKRSTGEN_IRQ_STATUS__PLL_READY_IRQ_STATUS__RESET_VALUE     0x00000000U
/** @} */

/* macros for field xtal_stable_irq_status */
/**
 * @defgroup at_apb_clkrstgen_regs_core_xtal_stable_irq_status_field xtal_stable_irq_status_field
 * @brief macros for field xtal_stable_irq_status
 * @details irq_status
 * @{
 */
#define CLKRSTGEN_IRQ_STATUS__XTAL_STABLE_IRQ_STATUS__SHIFT                   1
#define CLKRSTGEN_IRQ_STATUS__XTAL_STABLE_IRQ_STATUS__WIDTH                   1
#define CLKRSTGEN_IRQ_STATUS__XTAL_STABLE_IRQ_STATUS__MASK          0x00000002U
#define CLKRSTGEN_IRQ_STATUS__XTAL_STABLE_IRQ_STATUS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CLKRSTGEN_IRQ_STATUS__XTAL_STABLE_IRQ_STATUS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CLKRSTGEN_IRQ_STATUS__XTAL_STABLE_IRQ_STATUS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CLKRSTGEN_IRQ_STATUS__XTAL_STABLE_IRQ_STATUS__RESET_VALUE   0x00000000U
/** @} */

/* macros for field wait4doubler_irq_status */
/**
 * @defgroup at_apb_clkrstgen_regs_core_wait4doubler_irq_status_field wait4doubler_irq_status_field
 * @brief macros for field wait4doubler_irq_status
 * @details irq_status
 * @{
 */
#define CLKRSTGEN_IRQ_STATUS__WAIT4DOUBLER_IRQ_STATUS__SHIFT                  2
#define CLKRSTGEN_IRQ_STATUS__WAIT4DOUBLER_IRQ_STATUS__WIDTH                  1
#define CLKRSTGEN_IRQ_STATUS__WAIT4DOUBLER_IRQ_STATUS__MASK         0x00000004U
#define CLKRSTGEN_IRQ_STATUS__WAIT4DOUBLER_IRQ_STATUS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CLKRSTGEN_IRQ_STATUS__WAIT4DOUBLER_IRQ_STATUS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CLKRSTGEN_IRQ_STATUS__WAIT4DOUBLER_IRQ_STATUS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CLKRSTGEN_IRQ_STATUS__WAIT4DOUBLER_IRQ_STATUS__RESET_VALUE  0x00000000U
/** @} */
#define CLKRSTGEN_IRQ_STATUS__TYPE                                     uint32_t
#define CLKRSTGEN_IRQ_STATUS__READ                                  0x00000007U
#define CLKRSTGEN_IRQ_STATUS__PRESERVED                             0x00000000U
#define CLKRSTGEN_IRQ_STATUS__RESET_VALUE                           0x00000000U

#endif /* __CLKRSTGEN_IRQ_STATUS_MACRO__ */

/** @} end of irq_status */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_atlc_lp_ctrl_2 */
/**
 * @defgroup at_apb_clkrstgen_regs_core_atlc_lp_ctrl_2 atlc_lp_ctrl_2
 * @brief Contains register fields associated with atlc_lp_ctrl_2. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_ATLC_LP_CTRL_2_MACRO__
#define __CLKRSTGEN_ATLC_LP_CTRL_2_MACRO__

/* macros for field slp_cntr_in_1us_frac_residue_wdata */
/**
 * @defgroup at_apb_clkrstgen_regs_core_slp_cntr_in_1us_frac_residue_wdata_field slp_cntr_in_1us_frac_residue_wdata_field
 * @brief macros for field slp_cntr_in_1us_frac_residue_wdata
 * @details SW-controlled residual fractional part. Read by HW at the start of ATLC sleep if slp_cntr_in_1us_frac_residue_write is high at the time.
 * @{
 */
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__SHIFT   0
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__WIDTH  23
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__MASK \
                    0x007fffffU
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define CLKRSTGEN_ATLC_LP_CTRL_2__SLP_CNTR_IN_1US_FRAC_RESIDUE_WDATA__RESET_VALUE \
                    0x00000000U
/** @} */
#define CLKRSTGEN_ATLC_LP_CTRL_2__TYPE                                 uint32_t
#define CLKRSTGEN_ATLC_LP_CTRL_2__READ                              0x007fffffU
#define CLKRSTGEN_ATLC_LP_CTRL_2__WRITE                             0x007fffffU
#define CLKRSTGEN_ATLC_LP_CTRL_2__PRESERVED                         0x00000000U
#define CLKRSTGEN_ATLC_LP_CTRL_2__RESET_VALUE                       0x00000000U

#endif /* __CLKRSTGEN_ATLC_LP_CTRL_2_MACRO__ */

/** @} end of atlc_lp_ctrl_2 */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_atlc_lp_frac_residue */
/**
 * @defgroup at_apb_clkrstgen_regs_core_atlc_lp_frac_residue atlc_lp_frac_residue
 * @brief Contains register fields associated with atlc_lp_frac_residue. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_ATLC_LP_FRAC_RESIDUE_MACRO__
#define __CLKRSTGEN_ATLC_LP_FRAC_RESIDUE_MACRO__

/* macros for field slp_cntr_in_1us_frac_residue */
/**
 * @defgroup at_apb_clkrstgen_regs_core_slp_cntr_in_1us_frac_residue_field slp_cntr_in_1us_frac_residue_field
 * @brief macros for field slp_cntr_in_1us_frac_residue
 * @details live value of the residual fractional part of the slp cntr in 1us time base.
 * @{
 */
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__SLP_CNTR_IN_1US_FRAC_RESIDUE__SHIFT   0
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__SLP_CNTR_IN_1US_FRAC_RESIDUE__WIDTH  23
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__SLP_CNTR_IN_1US_FRAC_RESIDUE__MASK \
                    0x007fffffU
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__SLP_CNTR_IN_1US_FRAC_RESIDUE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__SLP_CNTR_IN_1US_FRAC_RESIDUE__RESET_VALUE \
                    0x00000000U
/** @} */
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__TYPE                           uint32_t
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__READ                        0x007fffffU
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__PRESERVED                   0x00000000U
#define CLKRSTGEN_ATLC_LP_FRAC_RESIDUE__RESET_VALUE                 0x00000000U

#endif /* __CLKRSTGEN_ATLC_LP_FRAC_RESIDUE_MACRO__ */

/** @} end of atlc_lp_frac_residue */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_clksync_status */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clksync_status clksync_status
 * @brief status of clksync after SW bits have gone through HW synch definitions.
 * @{
 */
#ifndef __CLKRSTGEN_CLKSYNC_STATUS_MACRO__
#define __CLKRSTGEN_CLKSYNC_STATUS_MACRO__

/* macros for field div_val */
/**
 * @defgroup at_apb_clkrstgen_regs_core_div_val_field div_val_field
 * @brief macros for field div_val
 * @details how much to divide the pll to get 16 MHz? only gets updated by SW when pll_enable is 0.
 * @{
 */
#define CLKRSTGEN_CLKSYNC_STATUS__DIV_VAL__SHIFT                              0
#define CLKRSTGEN_CLKSYNC_STATUS__DIV_VAL__WIDTH                              4
#define CLKRSTGEN_CLKSYNC_STATUS__DIV_VAL__MASK                     0x0000000fU
#define CLKRSTGEN_CLKSYNC_STATUS__DIV_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define CLKRSTGEN_CLKSYNC_STATUS__DIV_VAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field clk16_src */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk16_src_field clk16_src_field
 * @brief macros for field clk16_src
 * @details selects the source of the 16 MHz clock domain  0 = crystal or dbl  1 = divided down pll
 * @{
 */
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC__SHIFT                            4
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC__WIDTH                            1
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC__MASK                   0x00000010U
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC__RESET_VALUE            0x00000000U
/** @} */

/* macros for field clk16_src_inner */
/**
 * @defgroup at_apb_clkrstgen_regs_core_clk16_src_inner_field clk16_src_inner_field
 * @brief macros for field clk16_src_inner
 * @details first selection layer. selects the source of the 16 MHz clock domain  0 = crystal 1 = dbl divided by 2
 * @{
 */
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC_INNER__SHIFT                      5
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC_INNER__WIDTH                      1
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC_INNER__MASK             0x00000020U
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC_INNER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC_INNER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC_INNER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define CLKRSTGEN_CLKSYNC_STATUS__CLK16_SRC_INNER__RESET_VALUE      0x00000000U
/** @} */
#define CLKRSTGEN_CLKSYNC_STATUS__TYPE                                 uint32_t
#define CLKRSTGEN_CLKSYNC_STATUS__READ                              0x0000003fU
#define CLKRSTGEN_CLKSYNC_STATUS__PRESERVED                         0x00000000U
#define CLKRSTGEN_CLKSYNC_STATUS__RESET_VALUE                       0x00000000U

#endif /* __CLKRSTGEN_CLKSYNC_STATUS_MACRO__ */

/** @} end of clksync_status */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_core_id */
/**
 * @defgroup at_apb_clkrstgen_regs_core_core_id core_id
 * @brief core id definitions.
 * @{
 */
#ifndef __CLKRSTGEN_CORE_ID_MACRO__
#define __CLKRSTGEN_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_clkrstgen_regs_core_id_field id_field
 * @brief macros for field id
 * @details CLKR in ASCII
 * @{
 */
#define CLKRSTGEN_CORE_ID__ID__SHIFT                                          0
#define CLKRSTGEN_CORE_ID__ID__WIDTH                                         32
#define CLKRSTGEN_CORE_ID__ID__MASK                                 0xffffffffU
#define CLKRSTGEN_CORE_ID__ID__READ(src)        ((uint32_t)(src) & 0xffffffffU)
#define CLKRSTGEN_CORE_ID__ID__RESET_VALUE                          0x434c4b52U
/** @} */
#define CLKRSTGEN_CORE_ID__TYPE                                        uint32_t
#define CLKRSTGEN_CORE_ID__READ                                     0xffffffffU
#define CLKRSTGEN_CORE_ID__PRESERVED                                0x00000000U
#define CLKRSTGEN_CORE_ID__RESET_VALUE                              0x434c4b52U

#endif /* __CLKRSTGEN_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_rev_hash */
/**
 * @defgroup at_apb_clkrstgen_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_REV_HASH_MACRO__
#define __CLKRSTGEN_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_clkrstgen_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define CLKRSTGEN_REV_HASH__ID__SHIFT                                         0
#define CLKRSTGEN_REV_HASH__ID__WIDTH                                        32
#define CLKRSTGEN_REV_HASH__ID__MASK                                0xffffffffU
#define CLKRSTGEN_REV_HASH__ID__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define CLKRSTGEN_REV_HASH__ID__RESET_VALUE                         0x4c0c8be3U
/** @} */
#define CLKRSTGEN_REV_HASH__TYPE                                       uint32_t
#define CLKRSTGEN_REV_HASH__READ                                    0xffffffffU
#define CLKRSTGEN_REV_HASH__PRESERVED                               0x00000000U
#define CLKRSTGEN_REV_HASH__RESET_VALUE                             0x4c0c8be3U

#endif /* __CLKRSTGEN_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::CLKRSTGEN_rev_key */
/**
 * @defgroup at_apb_clkrstgen_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __CLKRSTGEN_REV_KEY_MACRO__
#define __CLKRSTGEN_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_clkrstgen_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define CLKRSTGEN_REV_KEY__ID__SHIFT                                          0
#define CLKRSTGEN_REV_KEY__ID__WIDTH                                         32
#define CLKRSTGEN_REV_KEY__ID__MASK                                 0xffffffffU
#define CLKRSTGEN_REV_KEY__ID__READ(src)        ((uint32_t)(src) & 0xffffffffU)
#define CLKRSTGEN_REV_KEY__ID__RESET_VALUE                          0x52455620U
/** @} */
#define CLKRSTGEN_REV_KEY__TYPE                                        uint32_t
#define CLKRSTGEN_REV_KEY__READ                                     0xffffffffU
#define CLKRSTGEN_REV_KEY__PRESERVED                                0x00000000U
#define CLKRSTGEN_REV_KEY__RESET_VALUE                              0x52455620U

#endif /* __CLKRSTGEN_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_CLKRSTGEN_REGS_CORE */
#endif /* __REG_AT_APB_CLKRSTGEN_REGS_CORE_H__ */
