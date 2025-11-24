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
#define CLKRSTGEN_CLK_BP_CTRL__TYPE                                    uint32_t
#define CLKRSTGEN_CLK_BP_CTRL__READ                                 0x000003ffU
#define CLKRSTGEN_CLK_BP_CTRL__WRITE                                0x000003ffU
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
#define CLKRSTGEN_CONFIGURATION__TYPE                                  uint32_t
#define CLKRSTGEN_CONFIGURATION__READ                               0x000001ffU
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
 * @details how much to divide the pll to get 16 MHz?
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
 * @details selects the source of the 16 MHz clock domain  0 = crystal  1 = divided down pll
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
#define CLKRSTGEN_CLKSYNC__TYPE                                        uint32_t
#define CLKRSTGEN_CLKSYNC__READ                                     0x0000001fU
#define CLKRSTGEN_CLKSYNC__WRITE                                    0x0000001fU
#define CLKRSTGEN_CLKSYNC__PRESERVED                                0x00000000U
#define CLKRSTGEN_CLKSYNC__RESET_VALUE                              0x00000000U

#endif /* __CLKRSTGEN_CLKSYNC_MACRO__ */

/** @} end of clksync */

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

/** @} end of AT_APB_CLKRSTGEN_REGS_CORE */
#endif /* __REG_AT_APB_CLKRSTGEN_REGS_CORE_H__ */
