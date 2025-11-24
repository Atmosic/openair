/*                                                                           */
/* File:       at_apb_wrpr_pins_regs_core_macro.h                            */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_wrpr_pins_regs_core.rdl     */
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


#ifndef __REG_AT_APB_WRPR_PINS_REGS_CORE_H__
#define __REG_AT_APB_WRPR_PINS_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_WRPR_PINS_REGS_CORE at_apb_wrpr_pins_regs_core
 * @ingroup AT_REG
 * @brief at_apb_wrpr_pins_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb0_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb0_ctrl apb0_ctrl
 * @brief Contains register fields associated with apb0_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB0_CTRL_MACRO__
#define __WRPRPINS_APB0_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB0_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB0_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB0_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB0_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB0_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB0_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB0_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB0_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB0_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB0_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB0_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB0_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB0_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB0_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB0_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB0_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB0_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB0_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB0_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB0_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB0_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB0_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB0_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB0_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB0_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB0_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB0_CTRL_MACRO__ */

/** @} end of apb0_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb1_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb1_ctrl apb1_ctrl
 * @brief Contains register fields associated with apb1_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB1_CTRL_MACRO__
#define __WRPRPINS_APB1_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB1_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB1_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB1_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB1_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB1_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB1_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB1_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB1_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB1_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB1_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB1_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB1_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB1_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB1_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB1_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB1_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB1_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB1_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB1_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB1_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB1_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB1_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB1_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB1_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB1_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB1_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB1_CTRL_MACRO__ */

/** @} end of apb1_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb2_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb2_ctrl apb2_ctrl
 * @brief Contains register fields associated with apb2_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB2_CTRL_MACRO__
#define __WRPRPINS_APB2_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB2_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB2_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB2_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB2_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB2_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB2_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB2_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB2_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB2_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB2_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB2_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB2_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB2_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB2_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB2_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB2_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB2_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB2_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB2_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB2_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB2_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB2_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB2_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB2_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB2_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB2_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB2_CTRL_MACRO__ */

/** @} end of apb2_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb3_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb3_ctrl apb3_ctrl
 * @brief Contains register fields associated with apb3_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB3_CTRL_MACRO__
#define __WRPRPINS_APB3_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB3_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB3_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB3_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB3_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB3_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB3_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB3_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB3_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB3_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB3_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB3_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB3_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB3_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB3_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB3_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB3_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB3_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB3_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB3_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB3_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB3_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB3_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB3_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB3_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB3_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB3_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB3_CTRL_MACRO__ */

/** @} end of apb3_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb4_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb4_ctrl apb4_ctrl
 * @brief Contains register fields associated with apb4_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB4_CTRL_MACRO__
#define __WRPRPINS_APB4_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB4_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB4_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB4_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB4_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB4_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB4_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB4_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB4_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB4_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB4_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB4_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB4_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB4_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB4_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB4_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB4_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB4_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB4_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB4_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB4_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB4_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB4_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB4_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB4_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB4_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB4_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB4_CTRL_MACRO__ */

/** @} end of apb4_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb5_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb5_ctrl apb5_ctrl
 * @brief Contains register fields associated with apb5_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB5_CTRL_MACRO__
#define __WRPRPINS_APB5_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB5_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB5_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB5_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB5_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB5_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB5_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB5_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB5_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB5_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB5_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB5_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB5_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB5_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB5_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB5_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB5_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB5_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB5_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB5_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB5_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB5_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB5_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB5_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB5_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB5_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB5_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB5_CTRL_MACRO__ */

/** @} end of apb5_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb6_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb6_ctrl apb6_ctrl
 * @brief Contains register fields associated with apb6_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB6_CTRL_MACRO__
#define __WRPRPINS_APB6_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB6_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB6_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB6_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB6_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB6_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB6_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB6_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB6_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB6_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB6_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB6_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB6_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB6_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB6_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB6_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB6_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB6_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB6_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB6_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB6_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB6_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB6_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB6_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB6_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB6_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB6_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB6_CTRL_MACRO__ */

/** @} end of apb6_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb7_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb7_ctrl apb7_ctrl
 * @brief Contains register fields associated with apb7_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB7_CTRL_MACRO__
#define __WRPRPINS_APB7_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB7_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB7_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB7_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB7_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB7_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB7_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB7_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB7_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB7_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB7_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB7_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB7_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB7_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB7_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB7_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB7_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB7_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB7_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB7_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB7_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB7_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB7_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB7_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB7_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB7_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB7_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB7_CTRL_MACRO__ */

/** @} end of apb7_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb8_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb8_ctrl apb8_ctrl
 * @brief Contains register fields associated with apb8_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB8_CTRL_MACRO__
#define __WRPRPINS_APB8_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB8_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB8_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB8_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB8_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB8_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB8_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB8_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB8_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB8_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB8_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB8_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB8_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB8_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB8_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB8_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB8_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB8_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB8_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB8_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB8_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB8_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB8_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB8_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB8_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB8_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB8_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB8_CTRL_MACRO__ */

/** @} end of apb8_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb9_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb9_ctrl apb9_ctrl
 * @brief Contains register fields associated with apb9_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB9_CTRL_MACRO__
#define __WRPRPINS_APB9_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__SHIFT                                 0
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__WIDTH                                 1
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__MASK                        0x00000001U
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB9_CTRL__CLK_ENABLE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB9_CTRL__SRESET__SHIFT                                     1
#define WRPRPINS_APB9_CTRL__SRESET__WIDTH                                     1
#define WRPRPINS_APB9_CTRL__SRESET__MASK                            0x00000002U
#define WRPRPINS_APB9_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB9_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB9_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB9_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB9_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB9_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB9_CTRL__SRESET__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB9_CTRL__CLK_SEL__SHIFT                                    2
#define WRPRPINS_APB9_CTRL__CLK_SEL__WIDTH                                    1
#define WRPRPINS_APB9_CTRL__CLK_SEL__MASK                           0x00000004U
#define WRPRPINS_APB9_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB9_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB9_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB9_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB9_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB9_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB9_CTRL__CLK_SEL__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_APB9_CTRL__TYPE                                       uint32_t
#define WRPRPINS_APB9_CTRL__READ                                    0x00000007U
#define WRPRPINS_APB9_CTRL__WRITE                                   0x00000007U
#define WRPRPINS_APB9_CTRL__PRESERVED                               0x00000000U
#define WRPRPINS_APB9_CTRL__RESET_VALUE                             0x00000002U

#endif /* __WRPRPINS_APB9_CTRL_MACRO__ */

/** @} end of apb9_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb10_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb10_ctrl apb10_ctrl
 * @brief Contains register fields associated with apb10_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB10_CTRL_MACRO__
#define __WRPRPINS_APB10_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__SHIFT                                0
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__WIDTH                                1
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__MASK                       0x00000001U
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB10_CTRL__CLK_ENABLE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB10_CTRL__SRESET__SHIFT                                    1
#define WRPRPINS_APB10_CTRL__SRESET__WIDTH                                    1
#define WRPRPINS_APB10_CTRL__SRESET__MASK                           0x00000002U
#define WRPRPINS_APB10_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB10_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB10_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB10_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB10_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB10_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB10_CTRL__SRESET__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB10_CTRL__CLK_SEL__SHIFT                                   2
#define WRPRPINS_APB10_CTRL__CLK_SEL__WIDTH                                   1
#define WRPRPINS_APB10_CTRL__CLK_SEL__MASK                          0x00000004U
#define WRPRPINS_APB10_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB10_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB10_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB10_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB10_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB10_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB10_CTRL__CLK_SEL__RESET_VALUE                   0x00000000U
/** @} */
#define WRPRPINS_APB10_CTRL__TYPE                                      uint32_t
#define WRPRPINS_APB10_CTRL__READ                                   0x00000007U
#define WRPRPINS_APB10_CTRL__WRITE                                  0x00000007U
#define WRPRPINS_APB10_CTRL__PRESERVED                              0x00000000U
#define WRPRPINS_APB10_CTRL__RESET_VALUE                            0x00000002U

#endif /* __WRPRPINS_APB10_CTRL_MACRO__ */

/** @} end of apb10_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb11_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb11_ctrl apb11_ctrl
 * @brief Contains register fields associated with apb11_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB11_CTRL_MACRO__
#define __WRPRPINS_APB11_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__SHIFT                                0
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__WIDTH                                1
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__MASK                       0x00000001U
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB11_CTRL__CLK_ENABLE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB11_CTRL__SRESET__SHIFT                                    1
#define WRPRPINS_APB11_CTRL__SRESET__WIDTH                                    1
#define WRPRPINS_APB11_CTRL__SRESET__MASK                           0x00000002U
#define WRPRPINS_APB11_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB11_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB11_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB11_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB11_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB11_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB11_CTRL__SRESET__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB11_CTRL__CLK_SEL__SHIFT                                   2
#define WRPRPINS_APB11_CTRL__CLK_SEL__WIDTH                                   1
#define WRPRPINS_APB11_CTRL__CLK_SEL__MASK                          0x00000004U
#define WRPRPINS_APB11_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB11_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB11_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB11_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB11_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB11_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB11_CTRL__CLK_SEL__RESET_VALUE                   0x00000000U
/** @} */
#define WRPRPINS_APB11_CTRL__TYPE                                      uint32_t
#define WRPRPINS_APB11_CTRL__READ                                   0x00000007U
#define WRPRPINS_APB11_CTRL__WRITE                                  0x00000007U
#define WRPRPINS_APB11_CTRL__PRESERVED                              0x00000000U
#define WRPRPINS_APB11_CTRL__RESET_VALUE                            0x00000002U

#endif /* __WRPRPINS_APB11_CTRL_MACRO__ */

/** @} end of apb11_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb12_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb12_ctrl apb12_ctrl
 * @brief Contains register fields associated with apb12_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB12_CTRL_MACRO__
#define __WRPRPINS_APB12_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__SHIFT                                0
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__WIDTH                                1
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__MASK                       0x00000001U
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB12_CTRL__CLK_ENABLE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB12_CTRL__SRESET__SHIFT                                    1
#define WRPRPINS_APB12_CTRL__SRESET__WIDTH                                    1
#define WRPRPINS_APB12_CTRL__SRESET__MASK                           0x00000002U
#define WRPRPINS_APB12_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB12_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB12_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB12_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB12_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB12_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB12_CTRL__SRESET__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB12_CTRL__CLK_SEL__SHIFT                                   2
#define WRPRPINS_APB12_CTRL__CLK_SEL__WIDTH                                   1
#define WRPRPINS_APB12_CTRL__CLK_SEL__MASK                          0x00000004U
#define WRPRPINS_APB12_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB12_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB12_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB12_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB12_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB12_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB12_CTRL__CLK_SEL__RESET_VALUE                   0x00000000U
/** @} */
#define WRPRPINS_APB12_CTRL__TYPE                                      uint32_t
#define WRPRPINS_APB12_CTRL__READ                                   0x00000007U
#define WRPRPINS_APB12_CTRL__WRITE                                  0x00000007U
#define WRPRPINS_APB12_CTRL__PRESERVED                              0x00000000U
#define WRPRPINS_APB12_CTRL__RESET_VALUE                            0x00000002U

#endif /* __WRPRPINS_APB12_CTRL_MACRO__ */

/** @} end of apb12_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb13_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb13_ctrl apb13_ctrl
 * @brief Contains register fields associated with apb13_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB13_CTRL_MACRO__
#define __WRPRPINS_APB13_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__SHIFT                                0
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__WIDTH                                1
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__MASK                       0x00000001U
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB13_CTRL__CLK_ENABLE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB13_CTRL__SRESET__SHIFT                                    1
#define WRPRPINS_APB13_CTRL__SRESET__WIDTH                                    1
#define WRPRPINS_APB13_CTRL__SRESET__MASK                           0x00000002U
#define WRPRPINS_APB13_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB13_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB13_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB13_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB13_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB13_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB13_CTRL__SRESET__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB13_CTRL__CLK_SEL__SHIFT                                   2
#define WRPRPINS_APB13_CTRL__CLK_SEL__WIDTH                                   1
#define WRPRPINS_APB13_CTRL__CLK_SEL__MASK                          0x00000004U
#define WRPRPINS_APB13_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB13_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB13_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB13_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB13_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB13_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB13_CTRL__CLK_SEL__RESET_VALUE                   0x00000000U
/** @} */
#define WRPRPINS_APB13_CTRL__TYPE                                      uint32_t
#define WRPRPINS_APB13_CTRL__READ                                   0x00000007U
#define WRPRPINS_APB13_CTRL__WRITE                                  0x00000007U
#define WRPRPINS_APB13_CTRL__PRESERVED                              0x00000000U
#define WRPRPINS_APB13_CTRL__RESET_VALUE                            0x00000002U

#endif /* __WRPRPINS_APB13_CTRL_MACRO__ */

/** @} end of apb13_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb14_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb14_ctrl apb14_ctrl
 * @brief Contains register fields associated with apb14_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB14_CTRL_MACRO__
#define __WRPRPINS_APB14_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__SHIFT                                0
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__WIDTH                                1
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__MASK                       0x00000001U
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB14_CTRL__CLK_ENABLE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB14_CTRL__SRESET__SHIFT                                    1
#define WRPRPINS_APB14_CTRL__SRESET__WIDTH                                    1
#define WRPRPINS_APB14_CTRL__SRESET__MASK                           0x00000002U
#define WRPRPINS_APB14_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB14_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB14_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB14_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB14_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB14_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB14_CTRL__SRESET__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB14_CTRL__CLK_SEL__SHIFT                                   2
#define WRPRPINS_APB14_CTRL__CLK_SEL__WIDTH                                   1
#define WRPRPINS_APB14_CTRL__CLK_SEL__MASK                          0x00000004U
#define WRPRPINS_APB14_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB14_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB14_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB14_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB14_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB14_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB14_CTRL__CLK_SEL__RESET_VALUE                   0x00000000U
/** @} */
#define WRPRPINS_APB14_CTRL__TYPE                                      uint32_t
#define WRPRPINS_APB14_CTRL__READ                                   0x00000007U
#define WRPRPINS_APB14_CTRL__WRITE                                  0x00000007U
#define WRPRPINS_APB14_CTRL__PRESERVED                              0x00000000U
#define WRPRPINS_APB14_CTRL__RESET_VALUE                            0x00000002U

#endif /* __WRPRPINS_APB14_CTRL_MACRO__ */

/** @} end of apb14_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_apb15_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb15_ctrl apb15_ctrl
 * @brief Contains register fields associated with apb15_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_APB15_CTRL_MACRO__
#define __WRPRPINS_APB15_CTRL_MACRO__

/* macros for field clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_enable_field clk_enable_field
 * @brief macros for field clk_enable
 * @{
 */
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__SHIFT                                0
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__WIDTH                                1
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__MASK                       0x00000001U
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_APB15_CTRL__CLK_ENABLE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sreset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sreset_field sreset_field
 * @brief macros for field sreset
 * @{
 */
#define WRPRPINS_APB15_CTRL__SRESET__SHIFT                                    1
#define WRPRPINS_APB15_CTRL__SRESET__WIDTH                                    1
#define WRPRPINS_APB15_CTRL__SRESET__MASK                           0x00000002U
#define WRPRPINS_APB15_CTRL__SRESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_APB15_CTRL__SRESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_APB15_CTRL__SRESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_APB15_CTRL__SRESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_APB15_CTRL__SRESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_APB15_CTRL__SRESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_APB15_CTRL__SRESET__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field clk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_sel_field clk_sel_field
 * @brief macros for field clk_sel
 * @details [0]=PCLK [1]=PCLK_ALT
 * @{
 */
#define WRPRPINS_APB15_CTRL__CLK_SEL__SHIFT                                   2
#define WRPRPINS_APB15_CTRL__CLK_SEL__WIDTH                                   1
#define WRPRPINS_APB15_CTRL__CLK_SEL__MASK                          0x00000004U
#define WRPRPINS_APB15_CTRL__CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_APB15_CTRL__CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_APB15_CTRL__CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_APB15_CTRL__CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_APB15_CTRL__CLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_APB15_CTRL__CLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_APB15_CTRL__CLK_SEL__RESET_VALUE                   0x00000000U
/** @} */
#define WRPRPINS_APB15_CTRL__TYPE                                      uint32_t
#define WRPRPINS_APB15_CTRL__READ                                   0x00000007U
#define WRPRPINS_APB15_CTRL__WRITE                                  0x00000007U
#define WRPRPINS_APB15_CTRL__PRESERVED                              0x00000000U
#define WRPRPINS_APB15_CTRL__RESET_VALUE                            0x00000002U

#endif /* __WRPRPINS_APB15_CTRL_MACRO__ */

/** @} end of apb15_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_clk_hpc_pin_out_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_hpc_pin_out_ctrl clk_hpc_pin_out_ctrl
 * @brief Contains register fields associated with clk_hpc_pin_out_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_CLK_HPC_PIN_OUT_CTRL_MACRO__
#define __WRPRPINS_CLK_HPC_PIN_OUT_CTRL_MACRO__

/* macros for field clk_hpc_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_hpc_sel_field clk_hpc_sel_field
 * @brief macros for field clk_hpc_sel
 * @{
 */
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__SHIFT                     0
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__WIDTH                     2
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__MASK            0x00000003U
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__CLK_HPC_SEL__RESET_VALUE     0x00000000U
/** @} */
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__TYPE                            uint32_t
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__READ                         0x00000003U
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__WRITE                        0x00000003U
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__PRESERVED                    0x00000000U
#define WRPRPINS_CLK_HPC_PIN_OUT_CTRL__RESET_VALUE                  0x00000000U

#endif /* __WRPRPINS_CLK_HPC_PIN_OUT_CTRL_MACRO__ */

/** @} end of clk_hpc_pin_out_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_clk_mpc_pin_out_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_mpc_pin_out_ctrl clk_mpc_pin_out_ctrl
 * @brief Contains register fields associated with clk_mpc_pin_out_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_CLK_MPC_PIN_OUT_CTRL_MACRO__
#define __WRPRPINS_CLK_MPC_PIN_OUT_CTRL_MACRO__

/* macros for field clk_mpc_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_mpc_sel_field clk_mpc_sel_field
 * @brief macros for field clk_mpc_sel
 * @{
 */
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__SHIFT                     0
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__WIDTH                     2
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__MASK            0x00000003U
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__CLK_MPC_SEL__RESET_VALUE     0x00000000U
/** @} */
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__TYPE                            uint32_t
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__READ                         0x00000003U
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__WRITE                        0x00000003U
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__PRESERVED                    0x00000000U
#define WRPRPINS_CLK_MPC_PIN_OUT_CTRL__RESET_VALUE                  0x00000000U

#endif /* __WRPRPINS_CLK_MPC_PIN_OUT_CTRL_MACRO__ */

/** @} end of clk_mpc_pin_out_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_clk_lpc_pin_out_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_lpc_pin_out_ctrl clk_lpc_pin_out_ctrl
 * @brief Contains register fields associated with clk_lpc_pin_out_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_CLK_LPC_PIN_OUT_CTRL_MACRO__
#define __WRPRPINS_CLK_LPC_PIN_OUT_CTRL_MACRO__

/* macros for field clk_lpc_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clk_lpc_sel_field clk_lpc_sel_field
 * @brief macros for field clk_lpc_sel
 * @{
 */
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__SHIFT                     0
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__WIDTH                     1
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__MASK            0x00000001U
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__CLK_LPC_SEL__RESET_VALUE     0x00000000U
/** @} */
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__TYPE                            uint32_t
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__READ                         0x00000001U
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__WRITE                        0x00000001U
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__PRESERVED                    0x00000000U
#define WRPRPINS_CLK_LPC_PIN_OUT_CTRL__RESET_VALUE                  0x00000000U

#endif /* __WRPRPINS_CLK_LPC_PIN_OUT_CTRL_MACRO__ */

/** @} end of clk_lpc_pin_out_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_dbg_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_dbg_ctrl dbg_ctrl
 * @brief Contains register fields associated with dbg_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_DBG_CTRL_MACRO__
#define __WRPRPINS_DBG_CTRL_MACRO__

/* macros for field dbg_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_dbg_sel_field dbg_sel_field
 * @brief macros for field dbg_sel
 * @{
 */
#define WRPRPINS_DBG_CTRL__DBG_SEL__SHIFT                                     0
#define WRPRPINS_DBG_CTRL__DBG_SEL__WIDTH                                     4
#define WRPRPINS_DBG_CTRL__DBG_SEL__MASK                            0x0000000fU
#define WRPRPINS_DBG_CTRL__DBG_SEL__READ(src)   ((uint32_t)(src) & 0x0000000fU)
#define WRPRPINS_DBG_CTRL__DBG_SEL__WRITE(src)  ((uint32_t)(src) & 0x0000000fU)
#define WRPRPINS_DBG_CTRL__DBG_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define WRPRPINS_DBG_CTRL__DBG_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define WRPRPINS_DBG_CTRL__DBG_SEL__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field dbg_shft */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_dbg_shft_field dbg_shft_field
 * @brief macros for field dbg_shft
 * @{
 */
#define WRPRPINS_DBG_CTRL__DBG_SHFT__SHIFT                                    4
#define WRPRPINS_DBG_CTRL__DBG_SHFT__WIDTH                                    3
#define WRPRPINS_DBG_CTRL__DBG_SHFT__MASK                           0x00000070U
#define WRPRPINS_DBG_CTRL__DBG_SHFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define WRPRPINS_DBG_CTRL__DBG_SHFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define WRPRPINS_DBG_CTRL__DBG_SHFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define WRPRPINS_DBG_CTRL__DBG_SHFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define WRPRPINS_DBG_CTRL__DBG_SHFT__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field dbg_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_dbg_enable_field dbg_enable_field
 * @brief macros for field dbg_enable
 * @{
 */
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__SHIFT                                  7
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__WIDTH                                  1
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__MASK                         0x00000080U
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define WRPRPINS_DBG_CTRL__DBG_ENABLE__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field em_block_wdata */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_em_block_wdata_field em_block_wdata_field
 * @brief macros for field em_block_wdata
 * @details not intended to be used; helps with cpf isolation issues
 * @{
 */
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__SHIFT                              8
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__WIDTH                              1
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__MASK                     0x00000100U
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_WDATA__RESET_VALUE              0x00000000U
/** @} */

/* macros for field em_block_addr */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_em_block_addr_field em_block_addr_field
 * @brief macros for field em_block_addr
 * @details not intended to be used; helps with cpf isolation issues
 * @{
 */
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__SHIFT                               9
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__WIDTH                               1
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__MASK                      0x00000200U
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define WRPRPINS_DBG_CTRL__EM_BLOCK_ADDR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field sse200_certdisableext */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_certdisableext_field sse200_certdisableext_field
 * @brief macros for field sse200_certdisableext
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__SHIFT                      10
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__WIDTH                       1
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__MASK              0x00000400U
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define WRPRPINS_DBG_CTRL__SSE200_CERTDISABLEEXT__RESET_VALUE       0x00000000U
/** @} */

/* macros for field sse200_niden_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_niden_sel_field sse200_niden_sel_field
 * @brief macros for field sse200_niden_sel
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__SHIFT                           11
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__WIDTH                            1
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__MASK                   0x00000800U
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define WRPRPINS_DBG_CTRL__SSE200_NIDEN_SEL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field sse200_dbgen_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_dbgen_sel_field sse200_dbgen_sel_field
 * @brief macros for field sse200_dbgen_sel
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__SHIFT                           12
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__WIDTH                            1
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__MASK                   0x00001000U
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define WRPRPINS_DBG_CTRL__SSE200_DBGEN_SEL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field sse200_exp_mpc_g_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_exp_mpc_g_sel_field sse200_exp_mpc_g_sel_field
 * @brief macros for field sse200_exp_mpc_g_sel
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__SHIFT                       13
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__WIDTH                        1
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__MASK               0x00002000U
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_MPC_G_SEL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field sse200_sysfclkqactive */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_sysfclkqactive_field sse200_sysfclkqactive_field
 * @brief macros for field sse200_sysfclkqactive
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__SHIFT                      14
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__WIDTH                       1
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__MASK              0x00004000U
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define WRPRPINS_DBG_CTRL__SSE200_SYSFCLKQACTIVE__RESET_VALUE       0x00000001U
/** @} */

/* macros for field sse200_expclkreq_in */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_expclkreq_in_field sse200_expclkreq_in_field
 * @brief macros for field sse200_expclkreq_in
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__SHIFT                        15
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__WIDTH                         1
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__MASK                0x00008000U
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define WRPRPINS_DBG_CTRL__SSE200_EXPCLKREQ_IN__RESET_VALUE         0x00000001U
/** @} */

/* macros for field sse200_exp_nmi */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_exp_nmi_field sse200_exp_nmi_field
 * @brief macros for field sse200_exp_nmi
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__SHIFT                             16
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__WIDTH                              1
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__MASK                     0x00010000U
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define WRPRPINS_DBG_CTRL__SSE200_EXP_NMI__RESET_VALUE              0x00000000U
/** @} */

/* macros for field sse200_mstexp1_clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_mstexp1_clk_enable_field sse200_mstexp1_clk_enable_field
 * @brief macros for field sse200_mstexp1_clk_enable
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__SHIFT                  17
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__WIDTH                   1
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__MASK          0x00020000U
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP1_CLK_ENABLE__RESET_VALUE   0x00000001U
/** @} */

/* macros for field sse200_mstexp0_clk_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sse200_mstexp0_clk_enable_field sse200_mstexp0_clk_enable_field
 * @brief macros for field sse200_mstexp0_clk_enable
 * @{
 */
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__SHIFT                  18
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__WIDTH                   1
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__MASK          0x00040000U
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define WRPRPINS_DBG_CTRL__SSE200_MSTEXP0_CLK_ENABLE__RESET_VALUE   0x00000001U
/** @} */

/* macros for field trigger_soc_rst */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_trigger_soc_rst_field trigger_soc_rst_field
 * @brief macros for field trigger_soc_rst
 * @{
 */
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__SHIFT                            19
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__WIDTH                             1
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__MASK                    0x00080000U
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define WRPRPINS_DBG_CTRL__TRIGGER_SOC_RST__RESET_VALUE             0x00000000U
/** @} */

/* macros for field trace_is_ddr */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_trace_is_ddr_field trace_is_ddr_field
 * @brief macros for field trace_is_ddr
 * @{
 */
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__SHIFT                               20
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__WIDTH                                1
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__MASK                       0x00100000U
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define WRPRPINS_DBG_CTRL__TRACE_IS_DDR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field dbg_skip_6x6_holes */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_dbg_skip_6x6_holes_field dbg_skip_6x6_holes_field
 * @brief macros for field dbg_skip_6x6_holes
 * @{
 */
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__SHIFT                         21
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__WIDTH                          1
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__MASK                 0x00200000U
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define WRPRPINS_DBG_CTRL__DBG_SKIP_6X6_HOLES__RESET_VALUE          0x00000000U
/** @} */

/* macros for field dbg_cg */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_dbg_cg_field dbg_cg_field
 * @brief macros for field dbg_cg
 * @{
 */
#define WRPRPINS_DBG_CTRL__DBG_CG__SHIFT                                     22
#define WRPRPINS_DBG_CTRL__DBG_CG__WIDTH                                      1
#define WRPRPINS_DBG_CTRL__DBG_CG__MASK                             0x00400000U
#define WRPRPINS_DBG_CTRL__DBG_CG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define WRPRPINS_DBG_CTRL__DBG_CG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define WRPRPINS_DBG_CTRL__DBG_CG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define WRPRPINS_DBG_CTRL__DBG_CG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define WRPRPINS_DBG_CTRL__DBG_CG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define WRPRPINS_DBG_CTRL__DBG_CG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define WRPRPINS_DBG_CTRL__DBG_CG__RESET_VALUE                      0x00000000U
/** @} */
#define WRPRPINS_DBG_CTRL__TYPE                                        uint32_t
#define WRPRPINS_DBG_CTRL__READ                                     0x007fffffU
#define WRPRPINS_DBG_CTRL__WRITE                                    0x007fffffU
#define WRPRPINS_DBG_CTRL__PRESERVED                                0x00000000U
#define WRPRPINS_DBG_CTRL__RESET_VALUE                              0x0006c000U

#endif /* __WRPRPINS_DBG_CTRL_MACRO__ */

/** @} end of dbg_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_A */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_A psel_A
 * @brief Contains register fields associated with psel_A. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_A_MACRO__
#define __WRPRPINS_PSEL_A_MACRO__

/* macros for field p0_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p0_sel_field p0_sel_field
 * @brief macros for field p0_sel
 * @details by default P0 is SWDCLK
 * @{
 */
#define WRPRPINS_PSEL_A__P0_SEL__SHIFT                                        0
#define WRPRPINS_PSEL_A__P0_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_A__P0_SEL__MASK                               0x000000ffU
#define WRPRPINS_PSEL_A__P0_SEL__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_A__P0_SEL__WRITE(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_A__P0_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_A__P0_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_A__P0_SEL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field p1_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p1_sel_field p1_sel_field
 * @brief macros for field p1_sel
 * @details by default P1 is SWDIO
 * @{
 */
#define WRPRPINS_PSEL_A__P1_SEL__SHIFT                                        8
#define WRPRPINS_PSEL_A__P1_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_A__P1_SEL__MASK                               0x0000ff00U
#define WRPRPINS_PSEL_A__P1_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_A__P1_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_A__P1_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_A__P1_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_A__P1_SEL__RESET_VALUE                        0x00000002U
/** @} */

/* macros for field p2_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p2_sel_field p2_sel_field
 * @brief macros for field p2_sel
 * @{
 */
#define WRPRPINS_PSEL_A__P2_SEL__SHIFT                                       16
#define WRPRPINS_PSEL_A__P2_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_A__P2_SEL__MASK                               0x00ff0000U
#define WRPRPINS_PSEL_A__P2_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_A__P2_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_A__P2_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_A__P2_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_A__P2_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p3_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p3_sel_field p3_sel_field
 * @brief macros for field p3_sel
 * @{
 */
#define WRPRPINS_PSEL_A__P3_SEL__SHIFT                                       24
#define WRPRPINS_PSEL_A__P3_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_A__P3_SEL__MASK                               0xff000000U
#define WRPRPINS_PSEL_A__P3_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_A__P3_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_A__P3_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_A__P3_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_A__P3_SEL__RESET_VALUE                        0x00000000U
/** @} */
#define WRPRPINS_PSEL_A__TYPE                                          uint32_t
#define WRPRPINS_PSEL_A__READ                                       0xffffffffU
#define WRPRPINS_PSEL_A__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_A__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_A__RESET_VALUE                                0x00000201U

#endif /* __WRPRPINS_PSEL_A_MACRO__ */

/** @} end of psel_A */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_B */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_B psel_B
 * @brief Contains register fields associated with psel_B. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_B_MACRO__
#define __WRPRPINS_PSEL_B_MACRO__

/* macros for field p4_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p4_sel_field p4_sel_field
 * @brief macros for field p4_sel
 * @{
 */
#define WRPRPINS_PSEL_B__P4_SEL__SHIFT                                        0
#define WRPRPINS_PSEL_B__P4_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_B__P4_SEL__MASK                               0x000000ffU
#define WRPRPINS_PSEL_B__P4_SEL__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_B__P4_SEL__WRITE(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_B__P4_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_B__P4_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_B__P4_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p5_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p5_sel_field p5_sel_field
 * @brief macros for field p5_sel
 * @{
 */
#define WRPRPINS_PSEL_B__P5_SEL__SHIFT                                        8
#define WRPRPINS_PSEL_B__P5_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_B__P5_SEL__MASK                               0x0000ff00U
#define WRPRPINS_PSEL_B__P5_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_B__P5_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_B__P5_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_B__P5_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_B__P5_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p6_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p6_sel_field p6_sel_field
 * @brief macros for field p6_sel
 * @{
 */
#define WRPRPINS_PSEL_B__P6_SEL__SHIFT                                       16
#define WRPRPINS_PSEL_B__P6_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_B__P6_SEL__MASK                               0x00ff0000U
#define WRPRPINS_PSEL_B__P6_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_B__P6_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_B__P6_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_B__P6_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_B__P6_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p7_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p7_sel_field p7_sel_field
 * @brief macros for field p7_sel
 * @{
 */
#define WRPRPINS_PSEL_B__P7_SEL__SHIFT                                       24
#define WRPRPINS_PSEL_B__P7_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_B__P7_SEL__MASK                               0xff000000U
#define WRPRPINS_PSEL_B__P7_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_B__P7_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_B__P7_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_B__P7_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_B__P7_SEL__RESET_VALUE                        0x00000000U
/** @} */
#define WRPRPINS_PSEL_B__TYPE                                          uint32_t
#define WRPRPINS_PSEL_B__READ                                       0xffffffffU
#define WRPRPINS_PSEL_B__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_B__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_B__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_B_MACRO__ */

/** @} end of psel_B */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_C */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_C psel_C
 * @brief Contains register fields associated with psel_C. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_C_MACRO__
#define __WRPRPINS_PSEL_C_MACRO__

/* macros for field p8_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p8_sel_field p8_sel_field
 * @brief macros for field p8_sel
 * @{
 */
#define WRPRPINS_PSEL_C__P8_SEL__SHIFT                                        0
#define WRPRPINS_PSEL_C__P8_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_C__P8_SEL__MASK                               0x000000ffU
#define WRPRPINS_PSEL_C__P8_SEL__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_C__P8_SEL__WRITE(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_C__P8_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_C__P8_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_C__P8_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p9_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p9_sel_field p9_sel_field
 * @brief macros for field p9_sel
 * @{
 */
#define WRPRPINS_PSEL_C__P9_SEL__SHIFT                                        8
#define WRPRPINS_PSEL_C__P9_SEL__WIDTH                                        8
#define WRPRPINS_PSEL_C__P9_SEL__MASK                               0x0000ff00U
#define WRPRPINS_PSEL_C__P9_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_C__P9_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_C__P9_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_C__P9_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_C__P9_SEL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p10_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p10_sel_field p10_sel_field
 * @brief macros for field p10_sel
 * @{
 */
#define WRPRPINS_PSEL_C__P10_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_C__P10_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_C__P10_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_C__P10_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_C__P10_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_C__P10_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_C__P10_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_C__P10_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p11_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p11_sel_field p11_sel_field
 * @brief macros for field p11_sel
 * @{
 */
#define WRPRPINS_PSEL_C__P11_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_C__P11_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_C__P11_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_C__P11_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_C__P11_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_C__P11_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_C__P11_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_C__P11_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_C__TYPE                                          uint32_t
#define WRPRPINS_PSEL_C__READ                                       0xffffffffU
#define WRPRPINS_PSEL_C__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_C__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_C__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_C_MACRO__ */

/** @} end of psel_C */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_D */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_D psel_D
 * @brief Contains register fields associated with psel_D. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_D_MACRO__
#define __WRPRPINS_PSEL_D_MACRO__

/* macros for field p12_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p12_sel_field p12_sel_field
 * @brief macros for field p12_sel
 * @{
 */
#define WRPRPINS_PSEL_D__P12_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_D__P12_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_D__P12_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_D__P12_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_D__P12_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_D__P12_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_D__P12_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_D__P12_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p13_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p13_sel_field p13_sel_field
 * @brief macros for field p13_sel
 * @{
 */
#define WRPRPINS_PSEL_D__P13_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_D__P13_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_D__P13_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_D__P13_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_D__P13_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_D__P13_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_D__P13_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_D__P13_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p14_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p14_sel_field p14_sel_field
 * @brief macros for field p14_sel
 * @{
 */
#define WRPRPINS_PSEL_D__P14_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_D__P14_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_D__P14_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_D__P14_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_D__P14_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_D__P14_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_D__P14_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_D__P14_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p15_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p15_sel_field p15_sel_field
 * @brief macros for field p15_sel
 * @{
 */
#define WRPRPINS_PSEL_D__P15_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_D__P15_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_D__P15_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_D__P15_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_D__P15_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_D__P15_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_D__P15_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_D__P15_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_D__TYPE                                          uint32_t
#define WRPRPINS_PSEL_D__READ                                       0xffffffffU
#define WRPRPINS_PSEL_D__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_D__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_D__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_D_MACRO__ */

/** @} end of psel_D */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_E */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_E psel_E
 * @brief Contains register fields associated with psel_E. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_E_MACRO__
#define __WRPRPINS_PSEL_E_MACRO__

/* macros for field p16_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p16_sel_field p16_sel_field
 * @brief macros for field p16_sel
 * @{
 */
#define WRPRPINS_PSEL_E__P16_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_E__P16_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_E__P16_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_E__P16_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_E__P16_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_E__P16_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_E__P16_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_E__P16_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p17_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p17_sel_field p17_sel_field
 * @brief macros for field p17_sel
 * @{
 */
#define WRPRPINS_PSEL_E__P17_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_E__P17_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_E__P17_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_E__P17_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_E__P17_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_E__P17_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_E__P17_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_E__P17_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p18_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p18_sel_field p18_sel_field
 * @brief macros for field p18_sel
 * @{
 */
#define WRPRPINS_PSEL_E__P18_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_E__P18_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_E__P18_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_E__P18_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_E__P18_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_E__P18_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_E__P18_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_E__P18_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p19_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p19_sel_field p19_sel_field
 * @brief macros for field p19_sel
 * @{
 */
#define WRPRPINS_PSEL_E__P19_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_E__P19_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_E__P19_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_E__P19_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_E__P19_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_E__P19_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_E__P19_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_E__P19_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_E__TYPE                                          uint32_t
#define WRPRPINS_PSEL_E__READ                                       0xffffffffU
#define WRPRPINS_PSEL_E__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_E__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_E__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_E_MACRO__ */

/** @} end of psel_E */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_F */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_F psel_F
 * @brief Contains register fields associated with psel_F. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_F_MACRO__
#define __WRPRPINS_PSEL_F_MACRO__

/* macros for field p20_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p20_sel_field p20_sel_field
 * @brief macros for field p20_sel
 * @{
 */
#define WRPRPINS_PSEL_F__P20_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_F__P20_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_F__P20_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_F__P20_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_F__P20_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_F__P20_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_F__P20_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_F__P20_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p21_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p21_sel_field p21_sel_field
 * @brief macros for field p21_sel
 * @{
 */
#define WRPRPINS_PSEL_F__P21_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_F__P21_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_F__P21_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_F__P21_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_F__P21_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_F__P21_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_F__P21_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_F__P21_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p22_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p22_sel_field p22_sel_field
 * @brief macros for field p22_sel
 * @{
 */
#define WRPRPINS_PSEL_F__P22_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_F__P22_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_F__P22_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_F__P22_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_F__P22_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_F__P22_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_F__P22_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_F__P22_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p23_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p23_sel_field p23_sel_field
 * @brief macros for field p23_sel
 * @{
 */
#define WRPRPINS_PSEL_F__P23_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_F__P23_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_F__P23_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_F__P23_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_F__P23_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_F__P23_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_F__P23_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_F__P23_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_F__TYPE                                          uint32_t
#define WRPRPINS_PSEL_F__READ                                       0xffffffffU
#define WRPRPINS_PSEL_F__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_F__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_F__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_F_MACRO__ */

/** @} end of psel_F */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_G */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_G psel_G
 * @brief Contains register fields associated with psel_G. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_G_MACRO__
#define __WRPRPINS_PSEL_G_MACRO__

/* macros for field p24_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p24_sel_field p24_sel_field
 * @brief macros for field p24_sel
 * @{
 */
#define WRPRPINS_PSEL_G__P24_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_G__P24_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_G__P24_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_G__P24_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_G__P24_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_G__P24_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_G__P24_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_G__P24_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p25_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p25_sel_field p25_sel_field
 * @brief macros for field p25_sel
 * @{
 */
#define WRPRPINS_PSEL_G__P25_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_G__P25_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_G__P25_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_G__P25_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_G__P25_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_G__P25_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_G__P25_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_G__P25_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p26_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p26_sel_field p26_sel_field
 * @brief macros for field p26_sel
 * @{
 */
#define WRPRPINS_PSEL_G__P26_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_G__P26_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_G__P26_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_G__P26_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_G__P26_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_G__P26_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_G__P26_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_G__P26_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p27_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p27_sel_field p27_sel_field
 * @brief macros for field p27_sel
 * @{
 */
#define WRPRPINS_PSEL_G__P27_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_G__P27_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_G__P27_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_G__P27_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_G__P27_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_G__P27_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_G__P27_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_G__P27_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_G__TYPE                                          uint32_t
#define WRPRPINS_PSEL_G__READ                                       0xffffffffU
#define WRPRPINS_PSEL_G__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_G__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_G__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_G_MACRO__ */

/** @} end of psel_G */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_H */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_H psel_H
 * @brief Contains register fields associated with psel_H. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_H_MACRO__
#define __WRPRPINS_PSEL_H_MACRO__

/* macros for field p28_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p28_sel_field p28_sel_field
 * @brief macros for field p28_sel
 * @{
 */
#define WRPRPINS_PSEL_H__P28_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_H__P28_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_H__P28_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_H__P28_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_H__P28_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_H__P28_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_H__P28_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_H__P28_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p29_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p29_sel_field p29_sel_field
 * @brief macros for field p29_sel
 * @{
 */
#define WRPRPINS_PSEL_H__P29_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_H__P29_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_H__P29_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_H__P29_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_H__P29_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_H__P29_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_H__P29_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_H__P29_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p30_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p30_sel_field p30_sel_field
 * @brief macros for field p30_sel
 * @{
 */
#define WRPRPINS_PSEL_H__P30_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_H__P30_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_H__P30_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_H__P30_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_H__P30_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_H__P30_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_H__P30_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_H__P30_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_H__TYPE                                          uint32_t
#define WRPRPINS_PSEL_H__READ                                       0x00ffffffU
#define WRPRPINS_PSEL_H__WRITE                                      0x00ffffffU
#define WRPRPINS_PSEL_H__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_H__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_H_MACRO__ */

/** @} end of psel_H */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_I */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_I psel_I
 * @brief Contains register fields associated with psel_I. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_I_MACRO__
#define __WRPRPINS_PSEL_I_MACRO__

/* macros for field atb_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_atb_enable_field atb_enable_field
 * @brief macros for field atb_enable
 * @{
 */
#define WRPRPINS_PSEL_I__ATB_ENABLE__SHIFT                                    0
#define WRPRPINS_PSEL_I__ATB_ENABLE__WIDTH                                    5
#define WRPRPINS_PSEL_I__ATB_ENABLE__MASK                           0x0000001fU
#define WRPRPINS_PSEL_I__ATB_ENABLE__READ(src)  ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_PSEL_I__ATB_ENABLE__WRITE(src) ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_PSEL_I__ATB_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define WRPRPINS_PSEL_I__ATB_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define WRPRPINS_PSEL_I__ATB_ENABLE__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field jtag_interface */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_jtag_interface_field jtag_interface_field
 * @brief macros for field jtag_interface
 * @{
 */
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__SHIFT                               16
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__WIDTH                                1
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__MASK                       0x00010000U
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define WRPRPINS_PSEL_I__JTAG_INTERFACE__RESET_VALUE                0x00000000U
/** @} */
#define WRPRPINS_PSEL_I__TYPE                                          uint32_t
#define WRPRPINS_PSEL_I__READ                                       0x0001001fU
#define WRPRPINS_PSEL_I__WRITE                                      0x0001001fU
#define WRPRPINS_PSEL_I__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_I__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_I_MACRO__ */

/** @} end of psel_I */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pupd_ovrd */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pupd_ovrd pupd_ovrd
 * @brief pin 0-31 pull up/down override control definitions.
 * @{
 */
#ifndef __WRPRPINS_PUPD_OVRD_MACRO__
#define __WRPRPINS_PUPD_OVRD_MACRO__

/* macros for field pin */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pin_field pin_field
 * @brief macros for field pin
 * @details when set, overrides pull-up/pull-down from periphery
 * @{
 */
#define WRPRPINS_PUPD_OVRD__PIN__SHIFT                                        0
#define WRPRPINS_PUPD_OVRD__PIN__WIDTH                                       31
#define WRPRPINS_PUPD_OVRD__PIN__MASK                               0x7fffffffU
#define WRPRPINS_PUPD_OVRD__PIN__READ(src)      ((uint32_t)(src) & 0x7fffffffU)
#define WRPRPINS_PUPD_OVRD__PIN__WRITE(src)     ((uint32_t)(src) & 0x7fffffffU)
#define WRPRPINS_PUPD_OVRD__PIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_PUPD_OVRD__PIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_PUPD_OVRD__PIN__RESET_VALUE                        0x00000000U
/** @} */
#define WRPRPINS_PUPD_OVRD__TYPE                                       uint32_t
#define WRPRPINS_PUPD_OVRD__READ                                    0x7fffffffU
#define WRPRPINS_PUPD_OVRD__WRITE                                   0x7fffffffU
#define WRPRPINS_PUPD_OVRD__PRESERVED                               0x00000000U
#define WRPRPINS_PUPD_OVRD__RESET_VALUE                             0x00000000U

#endif /* __WRPRPINS_PUPD_OVRD_MACRO__ */

/** @} end of pupd_ovrd */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pupd_ovrd_val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pupd_ovrd_val pupd_ovrd_val
 * @brief pin 0-31 pull up/down override value definitions.
 * @{
 */
#ifndef __WRPRPINS_PUPD_OVRD_VAL_MACRO__
#define __WRPRPINS_PUPD_OVRD_VAL_MACRO__

/* macros for field pin */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pin_field pin_field
 * @brief macros for field pin
 * @details pull-up/pull_down override value  when pupd_ovrd is set:  1= pull-up override  0= pull-down override
 * @{
 */
#define WRPRPINS_PUPD_OVRD_VAL__PIN__SHIFT                                    0
#define WRPRPINS_PUPD_OVRD_VAL__PIN__WIDTH                                   31
#define WRPRPINS_PUPD_OVRD_VAL__PIN__MASK                           0x7fffffffU
#define WRPRPINS_PUPD_OVRD_VAL__PIN__READ(src)  ((uint32_t)(src) & 0x7fffffffU)
#define WRPRPINS_PUPD_OVRD_VAL__PIN__WRITE(src) ((uint32_t)(src) & 0x7fffffffU)
#define WRPRPINS_PUPD_OVRD_VAL__PIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_PUPD_OVRD_VAL__PIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_PUPD_OVRD_VAL__PIN__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_PUPD_OVRD_VAL__TYPE                                   uint32_t
#define WRPRPINS_PUPD_OVRD_VAL__READ                                0x7fffffffU
#define WRPRPINS_PUPD_OVRD_VAL__WRITE                               0x7fffffffU
#define WRPRPINS_PUPD_OVRD_VAL__PRESERVED                           0x00000000U
#define WRPRPINS_PUPD_OVRD_VAL__RESET_VALUE                         0x00000000U

#endif /* __WRPRPINS_PUPD_OVRD_VAL_MACRO__ */

/** @} end of pupd_ovrd_val */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_remap */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_remap remap
 * @brief Contains register fields associated with remap. definitions.
 * @{
 */
#ifndef __WRPRPINS_REMAP_MACRO__
#define __WRPRPINS_REMAP_MACRO__

/* macros for field qspi_drop */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_qspi_drop_field qspi_drop_field
 * @brief macros for field qspi_drop
 * @details drops the at_ahb_qspi address start from 0x10000000 to 0x0. No change in range.
 * @{
 */
#define WRPRPINS_REMAP__QSPI_DROP__SHIFT                                      0
#define WRPRPINS_REMAP__QSPI_DROP__WIDTH                                      1
#define WRPRPINS_REMAP__QSPI_DROP__MASK                             0x00000001U
#define WRPRPINS_REMAP__QSPI_DROP__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define WRPRPINS_REMAP__QSPI_DROP__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define WRPRPINS_REMAP__QSPI_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_REMAP__QSPI_DROP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_REMAP__QSPI_DROP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_REMAP__QSPI_DROP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_REMAP__QSPI_DROP__RESET_VALUE                      0x00000000U
/** @} */
#define WRPRPINS_REMAP__TYPE                                           uint32_t
#define WRPRPINS_REMAP__READ                                        0x00000001U
#define WRPRPINS_REMAP__WRITE                                       0x00000001U
#define WRPRPINS_REMAP__PRESERVED                                   0x00000000U
#define WRPRPINS_REMAP__RESET_VALUE                                 0x00000000U

#endif /* __WRPRPINS_REMAP_MACRO__ */

/** @} end of remap */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_ahb_interposers */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_ahb_interposers ahb_interposers
 * @brief Contains register fields associated with ahb_interposers. definitions.
 * @{
 */
#ifndef __WRPRPINS_AHB_INTERPOSERS_MACRO__
#define __WRPRPINS_AHB_INTERPOSERS_MACRO__

/* macros for field qspi_intp_enable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_qspi_intp_enable_field qspi_intp_enable_field
 * @brief macros for field qspi_intp_enable
 * @{
 */
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__SHIFT                     0
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__WIDTH                     1
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__MASK            0x00000001U
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_ENABLE__RESET_VALUE     0x00000001U
/** @} */

/* macros for field qspi_intp_low_ceiling */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_qspi_intp_low_ceiling_field qspi_intp_low_ceiling_field
 * @brief macros for field qspi_intp_low_ceiling
 * @{
 */
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__SHIFT                1
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__WIDTH                1
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__MASK       0x00000002U
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_AHB_INTERPOSERS__QSPI_INTP_LOW_CEILING__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_AHB_INTERPOSERS__TYPE                                 uint32_t
#define WRPRPINS_AHB_INTERPOSERS__READ                              0x00000003U
#define WRPRPINS_AHB_INTERPOSERS__WRITE                             0x00000003U
#define WRPRPINS_AHB_INTERPOSERS__PRESERVED                         0x00000000U
#define WRPRPINS_AHB_INTERPOSERS__RESET_VALUE                       0x00000001U

#endif /* __WRPRPINS_AHB_INTERPOSERS_MACRO__ */

/** @} end of ahb_interposers */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_scratchpad_A */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_scratchpad_A scratchpad_A
 * @brief Contains register fields associated with scratchpad_A. definitions.
 * @{
 */
#ifndef __WRPRPINS_SCRATCHPAD_A_MACRO__
#define __WRPRPINS_SCRATCHPAD_A_MACRO__

/* macros for field misc */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_misc_field misc_field
 * @brief macros for field misc
 * @details mostly likely will be used to inject random seed in sim
 * @{
 */
#define WRPRPINS_SCRATCHPAD_A__MISC__SHIFT                                    0
#define WRPRPINS_SCRATCHPAD_A__MISC__WIDTH                                   32
#define WRPRPINS_SCRATCHPAD_A__MISC__MASK                           0xffffffffU
#define WRPRPINS_SCRATCHPAD_A__MISC__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_A__MISC__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_A__MISC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_SCRATCHPAD_A__MISC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_SCRATCHPAD_A__MISC__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_SCRATCHPAD_A__TYPE                                    uint32_t
#define WRPRPINS_SCRATCHPAD_A__READ                                 0xffffffffU
#define WRPRPINS_SCRATCHPAD_A__WRITE                                0xffffffffU
#define WRPRPINS_SCRATCHPAD_A__PRESERVED                            0x00000000U
#define WRPRPINS_SCRATCHPAD_A__RESET_VALUE                          0x00000000U

#endif /* __WRPRPINS_SCRATCHPAD_A_MACRO__ */

/** @} end of scratchpad_A */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_scratchpad_B */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_scratchpad_B scratchpad_B
 * @brief Contains register fields associated with scratchpad_B. definitions.
 * @{
 */
#ifndef __WRPRPINS_SCRATCHPAD_B_MACRO__
#define __WRPRPINS_SCRATCHPAD_B_MACRO__

/* macros for field misc */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_misc_field misc_field
 * @brief macros for field misc
 * @details mostly likely will be used to inject random seed in sim
 * @{
 */
#define WRPRPINS_SCRATCHPAD_B__MISC__SHIFT                                    0
#define WRPRPINS_SCRATCHPAD_B__MISC__WIDTH                                   32
#define WRPRPINS_SCRATCHPAD_B__MISC__MASK                           0xffffffffU
#define WRPRPINS_SCRATCHPAD_B__MISC__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_B__MISC__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_B__MISC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_SCRATCHPAD_B__MISC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_SCRATCHPAD_B__MISC__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_SCRATCHPAD_B__TYPE                                    uint32_t
#define WRPRPINS_SCRATCHPAD_B__READ                                 0xffffffffU
#define WRPRPINS_SCRATCHPAD_B__WRITE                                0xffffffffU
#define WRPRPINS_SCRATCHPAD_B__PRESERVED                            0x00000000U
#define WRPRPINS_SCRATCHPAD_B__RESET_VALUE                          0x00000000U

#endif /* __WRPRPINS_SCRATCHPAD_B_MACRO__ */

/** @} end of scratchpad_B */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_scratchpad_C */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_scratchpad_C scratchpad_C
 * @brief Contains register fields associated with scratchpad_C. definitions.
 * @{
 */
#ifndef __WRPRPINS_SCRATCHPAD_C_MACRO__
#define __WRPRPINS_SCRATCHPAD_C_MACRO__

/* macros for field misc */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_misc_field misc_field
 * @brief macros for field misc
 * @details mostly likely will be used to inject random seed in sim
 * @{
 */
#define WRPRPINS_SCRATCHPAD_C__MISC__SHIFT                                    0
#define WRPRPINS_SCRATCHPAD_C__MISC__WIDTH                                   32
#define WRPRPINS_SCRATCHPAD_C__MISC__MASK                           0xffffffffU
#define WRPRPINS_SCRATCHPAD_C__MISC__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_C__MISC__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_C__MISC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_SCRATCHPAD_C__MISC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_SCRATCHPAD_C__MISC__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_SCRATCHPAD_C__TYPE                                    uint32_t
#define WRPRPINS_SCRATCHPAD_C__READ                                 0xffffffffU
#define WRPRPINS_SCRATCHPAD_C__WRITE                                0xffffffffU
#define WRPRPINS_SCRATCHPAD_C__PRESERVED                            0x00000000U
#define WRPRPINS_SCRATCHPAD_C__RESET_VALUE                          0x00000000U

#endif /* __WRPRPINS_SCRATCHPAD_C_MACRO__ */

/** @} end of scratchpad_C */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_scratchpad_D */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_scratchpad_D scratchpad_D
 * @brief Contains register fields associated with scratchpad_D. definitions.
 * @{
 */
#ifndef __WRPRPINS_SCRATCHPAD_D_MACRO__
#define __WRPRPINS_SCRATCHPAD_D_MACRO__

/* macros for field misc */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_misc_field misc_field
 * @brief macros for field misc
 * @details mostly likely will be used to inject random seed in sim
 * @{
 */
#define WRPRPINS_SCRATCHPAD_D__MISC__SHIFT                                    0
#define WRPRPINS_SCRATCHPAD_D__MISC__WIDTH                                   32
#define WRPRPINS_SCRATCHPAD_D__MISC__MASK                           0xffffffffU
#define WRPRPINS_SCRATCHPAD_D__MISC__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_D__MISC__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_SCRATCHPAD_D__MISC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_SCRATCHPAD_D__MISC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_SCRATCHPAD_D__MISC__RESET_VALUE                    0x00000000U
/** @} */
#define WRPRPINS_SCRATCHPAD_D__TYPE                                    uint32_t
#define WRPRPINS_SCRATCHPAD_D__READ                                 0xffffffffU
#define WRPRPINS_SCRATCHPAD_D__WRITE                                0xffffffffU
#define WRPRPINS_SCRATCHPAD_D__PRESERVED                            0x00000000U
#define WRPRPINS_SCRATCHPAD_D__RESET_VALUE                          0x00000000U

#endif /* __WRPRPINS_SCRATCHPAD_D_MACRO__ */

/** @} end of scratchpad_D */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection0 rram_write_protection0
 * @brief Contains register fields associated with rram_write_protection0. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION0_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION0_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @details if a bit is set, invalidates any writes to corresponding to 2kB block
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION0__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION0__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION0__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION0__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION0__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION0__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION0_MACRO__ */

/** @} end of rram_write_protection0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection1 rram_write_protection1
 * @brief Contains register fields associated with rram_write_protection1. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION1_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION1_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION1__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION1__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION1__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION1__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION1__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION1__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION1_MACRO__ */

/** @} end of rram_write_protection1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection2 rram_write_protection2
 * @brief Contains register fields associated with rram_write_protection2. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION2_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION2_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION2__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION2__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION2__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION2__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION2__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION2__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION2_MACRO__ */

/** @} end of rram_write_protection2 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection3 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection3 rram_write_protection3
 * @brief Contains register fields associated with rram_write_protection3. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION3_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION3_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION3__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION3__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION3__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION3__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION3__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION3__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION3_MACRO__ */

/** @} end of rram_write_protection3 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection4 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection4 rram_write_protection4
 * @brief Contains register fields associated with rram_write_protection4. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION4_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION4_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION4__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION4__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION4__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION4__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION4__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION4__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION4_MACRO__ */

/** @} end of rram_write_protection4 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection5 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection5 rram_write_protection5
 * @brief Contains register fields associated with rram_write_protection5. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION5_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION5_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION5__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION5__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION5__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION5__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION5__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION5__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION5_MACRO__ */

/** @} end of rram_write_protection5 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection6 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection6 rram_write_protection6
 * @brief Contains register fields associated with rram_write_protection6. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION6_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION6_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION6__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION6__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION6__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION6__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION6__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION6__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION6_MACRO__ */

/** @} end of rram_write_protection6 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_write_protection7 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_write_protection7 rram_write_protection7
 * @brief Contains register fields associated with rram_write_protection7. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_WRITE_PROTECTION7_MACRO__
#define __WRPRPINS_RRAM_WRITE_PROTECTION7_MACRO__

/* macros for field disable_bits */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_disable_bits_field disable_bits_field
 * @brief macros for field disable_bits
 * @{
 */
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__SHIFT                  0
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__WIDTH                 32
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__MASK         0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_WRITE_PROTECTION7__DISABLE_BITS__RESET_VALUE  0xffffffffU
/** @} */
#define WRPRPINS_RRAM_WRITE_PROTECTION7__TYPE                          uint32_t
#define WRPRPINS_RRAM_WRITE_PROTECTION7__READ                       0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION7__WRITE                      0xffffffffU
#define WRPRPINS_RRAM_WRITE_PROTECTION7__PRESERVED                  0x00000000U
#define WRPRPINS_RRAM_WRITE_PROTECTION7__RESET_VALUE                0xffffffffU

#endif /* __WRPRPINS_RRAM_WRITE_PROTECTION7_MACRO__ */

/** @} end of rram_write_protection7 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection0 rram_sticky_write_protection0
 * @brief Contains register fields associated with rram_sticky_write_protection0. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @details if a bit is set, invalidates any writes to the corresponding 2kB block, can only revert with cpu reset
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION0_MACRO__ */

/** @} end of rram_sticky_write_protection0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection1 rram_sticky_write_protection1
 * @brief Contains register fields associated with rram_sticky_write_protection1. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION1_MACRO__ */

/** @} end of rram_sticky_write_protection1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection2 rram_sticky_write_protection2
 * @brief Contains register fields associated with rram_sticky_write_protection2. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION2_MACRO__ */

/** @} end of rram_sticky_write_protection2 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection3 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection3 rram_sticky_write_protection3
 * @brief Contains register fields associated with rram_sticky_write_protection3. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION3_MACRO__ */

/** @} end of rram_sticky_write_protection3 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection4 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection4 rram_sticky_write_protection4
 * @brief Contains register fields associated with rram_sticky_write_protection4. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION4_MACRO__ */

/** @} end of rram_sticky_write_protection4 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection5 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection5 rram_sticky_write_protection5
 * @brief Contains register fields associated with rram_sticky_write_protection5. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION5_MACRO__ */

/** @} end of rram_sticky_write_protection5 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection6 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection6 rram_sticky_write_protection6
 * @brief Contains register fields associated with rram_sticky_write_protection6. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION6_MACRO__ */

/** @} end of rram_sticky_write_protection6 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection7 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection7 rram_sticky_write_protection7
 * @brief Contains register fields associated with rram_sticky_write_protection7. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__SHIFT                    0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__WIDTH                   32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__MASK           0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__TYPE                   uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__READ                0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__WRITE               0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__PRESERVED           0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION7_MACRO__ */

/** @} end of rram_sticky_write_protection7 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status0 rram_sticky_write_protection_status0
 * @brief Contains register fields associated with rram_sticky_write_protection_status0. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @details if read back value is 1, then the sticky bit has been set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS0_MACRO__ */

/** @} end of rram_sticky_write_protection_status0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status1 rram_sticky_write_protection_status1
 * @brief Contains register fields associated with rram_sticky_write_protection_status1. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS1_MACRO__ */

/** @} end of rram_sticky_write_protection_status1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status2 rram_sticky_write_protection_status2
 * @brief Contains register fields associated with rram_sticky_write_protection_status2. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS2_MACRO__ */

/** @} end of rram_sticky_write_protection_status2 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status3 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status3 rram_sticky_write_protection_status3
 * @brief Contains register fields associated with rram_sticky_write_protection_status3. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS3_MACRO__ */

/** @} end of rram_sticky_write_protection_status3 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status4 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status4 rram_sticky_write_protection_status4
 * @brief Contains register fields associated with rram_sticky_write_protection_status4. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS4_MACRO__ */

/** @} end of rram_sticky_write_protection_status4 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status5 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status5 rram_sticky_write_protection_status5
 * @brief Contains register fields associated with rram_sticky_write_protection_status5. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS5_MACRO__ */

/** @} end of rram_sticky_write_protection_status5 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status6 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status6 rram_sticky_write_protection_status6
 * @brief Contains register fields associated with rram_sticky_write_protection_status6. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS6_MACRO__ */

/** @} end of rram_sticky_write_protection_status6 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_write_protection_status7 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_write_protection_status7 rram_sticky_write_protection_status7
 * @brief Contains register fields associated with rram_sticky_write_protection_status7. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7_MACRO__
#define __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__VAL__SHIFT             0
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__VAL__WIDTH            32
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__VAL__MASK    0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__TYPE            uint32_t
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__READ         0xffffffffU
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__PRESERVED    0x00000000U
#define WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_WRITE_PROTECTION_STATUS7_MACRO__ */

/** @} end of rram_sticky_write_protection_status7 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_read_protection0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_read_protection0 rram_sticky_read_protection0
 * @brief Contains register fields associated with rram_sticky_read_protection0. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_READ_PROTECTION0_MACRO__
#define __WRPRPINS_RRAM_STICKY_READ_PROTECTION0_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @details if a bit is set, invalidates any reads to the corresponding 2kB block, can only revert with cpu reset
 * @{
 */
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__SHIFT                     0
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__WIDTH                    32
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__MASK            0xffffffffU
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__SET__RESET_VALUE     0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__TYPE                    uint32_t
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__READ                 0xffffffffU
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__WRITE                0xffffffffU
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__PRESERVED            0x00000000U
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION0__RESET_VALUE          0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_READ_PROTECTION0_MACRO__ */

/** @} end of rram_sticky_read_protection0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_sticky_read_protection_status0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_sticky_read_protection_status0 rram_sticky_read_protection_status0
 * @brief Contains register fields associated with rram_sticky_read_protection_status0. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0_MACRO__
#define __WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @details if read back value is 1, then the sticky bit has been set
 * @{
 */
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__VAL__SHIFT              0
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__VAL__WIDTH             32
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__VAL__MASK     0xffffffffU
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__TYPE             uint32_t
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__READ          0xffffffffU
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__PRESERVED     0x00000000U
#define WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0__RESET_VALUE   0x00000000U

#endif /* __WRPRPINS_RRAM_STICKY_READ_PROTECTION_STATUS0_MACRO__ */

/** @} end of rram_sticky_read_protection_status0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_prot_bits_set0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_prot_bits_set0 prot_bits_set0
 * @brief Contains register fields associated with prot_bits_set0. definitions.
 * @{
 */
#ifndef __WRPRPINS_PROT_BITS_SET0_MACRO__
#define __WRPRPINS_PROT_BITS_SET0_MACRO__

/* macros for field rom_read_locks_set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rom_read_locks_set_field rom_read_locks_set_field
 * @brief macros for field rom_read_locks_set
 * @details These bits go on to set sticky bits that lock up rom read. Each bit maps to one 2kB sector. Not self clearing
 * @{
 */
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__SHIFT                    0
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__WIDTH                   32
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__MASK           0xffffffffU
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_PROT_BITS_SET0__ROM_READ_LOCKS_SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_PROT_BITS_SET0__TYPE                                  uint32_t
#define WRPRPINS_PROT_BITS_SET0__READ                               0xffffffffU
#define WRPRPINS_PROT_BITS_SET0__WRITE                              0xffffffffU
#define WRPRPINS_PROT_BITS_SET0__PRESERVED                          0x00000000U
#define WRPRPINS_PROT_BITS_SET0__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_PROT_BITS_SET0_MACRO__ */

/** @} end of prot_bits_set0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_prot_bits_set1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_prot_bits_set1 prot_bits_set1
 * @brief Not self-clearing definitions.
 * @{
 */
#ifndef __WRPRPINS_PROT_BITS_SET1_MACRO__
#define __WRPRPINS_PROT_BITS_SET1_MACRO__

/* macros for field uart0_lock_set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_uart0_lock_set_field uart0_lock_set_field
 * @brief macros for field uart0_lock_set
 * @details sets sticky bit disabling uart0_tx.
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__SHIFT                        0
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__WIDTH                        1
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__MASK               0x00000001U
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_PROT_BITS_SET1__UART0_LOCK_SET__RESET_VALUE        0x00000000U
/** @} */

/* macros for field uart1_lock_set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_uart1_lock_set_field uart1_lock_set_field
 * @brief macros for field uart1_lock_set
 * @details sets sticky bit disabling uart1_tx.
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__SHIFT                        1
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__WIDTH                        1
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__MASK               0x00000002U
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_PROT_BITS_SET1__UART1_LOCK_SET__RESET_VALUE        0x00000000U
/** @} */

/* macros for field apb_qspi_lock_set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb_qspi_lock_set_field apb_qspi_lock_set_field
 * @brief macros for field apb_qspi_lock_set
 * @details sets sticky bit disabling APB cores accessing qspi.
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__SHIFT                     2
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__WIDTH                     1
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__MASK            0x00000004U
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_PROT_BITS_SET1__APB_QSPI_LOCK_SET__RESET_VALUE     0x00000000U
/** @} */

/* macros for field apb_shub_lock_set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb_shub_lock_set_field apb_shub_lock_set_field
 * @brief macros for field apb_shub_lock_set
 * @details sets sticky bit disabling the update of write address range.
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__SHIFT                     3
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__WIDTH                     1
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__MASK            0x00000008U
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define WRPRPINS_PROT_BITS_SET1__APB_SHUB_LOCK_SET__RESET_VALUE     0x00000000U
/** @} */

/* macros for field suppress_rom_patch */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_suppress_rom_patch_field suppress_rom_patch_field
 * @brief macros for field suppress_rom_patch
 * @details sets sticky bit preventing ROM patches from being applied
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__SHIFT                    4
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__WIDTH                    1
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__MASK           0x00000010U
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_ROM_PATCH__RESET_VALUE    0x00000000U
/** @} */

/* macros for field suppress_otp_writes */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_suppress_otp_writes_field suppress_otp_writes_field
 * @brief macros for field suppress_otp_writes
 * @details sets sticky bit preventing OTP writes
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__SHIFT                   5
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__WIDTH                   1
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__MASK          0x00000020U
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define WRPRPINS_PROT_BITS_SET1__SUPPRESS_OTP_WRITES__RESET_VALUE   0x00000000U
/** @} */
#define WRPRPINS_PROT_BITS_SET1__TYPE                                  uint32_t
#define WRPRPINS_PROT_BITS_SET1__READ                               0x0000003fU
#define WRPRPINS_PROT_BITS_SET1__WRITE                              0x0000003fU
#define WRPRPINS_PROT_BITS_SET1__PRESERVED                          0x00000000U
#define WRPRPINS_PROT_BITS_SET1__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_PROT_BITS_SET1_MACRO__ */

/** @} end of prot_bits_set1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_prot_bits_stat0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_prot_bits_stat0 prot_bits_stat0
 * @brief Contains register fields associated with prot_bits_stat0. definitions.
 * @{
 */
#ifndef __WRPRPINS_PROT_BITS_STAT0_MACRO__
#define __WRPRPINS_PROT_BITS_STAT0_MACRO__

/* macros for field rom_read_locks_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rom_read_locks_stat_field rom_read_locks_stat_field
 * @brief macros for field rom_read_locks_stat
 * @details sticky bits that lock up rom read. Each bit maps to one 2kB sector. Not self clearing
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT0__ROM_READ_LOCKS_STAT__SHIFT                  0
#define WRPRPINS_PROT_BITS_STAT0__ROM_READ_LOCKS_STAT__WIDTH                 32
#define WRPRPINS_PROT_BITS_STAT0__ROM_READ_LOCKS_STAT__MASK         0xffffffffU
#define WRPRPINS_PROT_BITS_STAT0__ROM_READ_LOCKS_STAT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_PROT_BITS_STAT0__ROM_READ_LOCKS_STAT__RESET_VALUE  0x00000000U
/** @} */
#define WRPRPINS_PROT_BITS_STAT0__TYPE                                 uint32_t
#define WRPRPINS_PROT_BITS_STAT0__READ                              0xffffffffU
#define WRPRPINS_PROT_BITS_STAT0__PRESERVED                         0x00000000U
#define WRPRPINS_PROT_BITS_STAT0__RESET_VALUE                       0x00000000U

#endif /* __WRPRPINS_PROT_BITS_STAT0_MACRO__ */

/** @} end of prot_bits_stat0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_prot_bits_stat1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_prot_bits_stat1 prot_bits_stat1
 * @brief Not self-clearing definitions.
 * @{
 */
#ifndef __WRPRPINS_PROT_BITS_STAT1_MACRO__
#define __WRPRPINS_PROT_BITS_STAT1_MACRO__

/* macros for field uart0_lock_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_uart0_lock_stat_field uart0_lock_stat_field
 * @brief macros for field uart0_lock_stat
 * @details sticky bit disabling uart0_tx.
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__UART0_LOCK_STAT__SHIFT                      0
#define WRPRPINS_PROT_BITS_STAT1__UART0_LOCK_STAT__WIDTH                      1
#define WRPRPINS_PROT_BITS_STAT1__UART0_LOCK_STAT__MASK             0x00000001U
#define WRPRPINS_PROT_BITS_STAT1__UART0_LOCK_STAT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_PROT_BITS_STAT1__UART0_LOCK_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_PROT_BITS_STAT1__UART0_LOCK_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_PROT_BITS_STAT1__UART0_LOCK_STAT__RESET_VALUE      0x00000000U
/** @} */

/* macros for field uart1_lock_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_uart1_lock_stat_field uart1_lock_stat_field
 * @brief macros for field uart1_lock_stat
 * @details sticky bit disabling uart1_tx.
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__UART1_LOCK_STAT__SHIFT                      1
#define WRPRPINS_PROT_BITS_STAT1__UART1_LOCK_STAT__WIDTH                      1
#define WRPRPINS_PROT_BITS_STAT1__UART1_LOCK_STAT__MASK             0x00000002U
#define WRPRPINS_PROT_BITS_STAT1__UART1_LOCK_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_PROT_BITS_STAT1__UART1_LOCK_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_PROT_BITS_STAT1__UART1_LOCK_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_PROT_BITS_STAT1__UART1_LOCK_STAT__RESET_VALUE      0x00000000U
/** @} */

/* macros for field apb_qspi_lock_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb_qspi_lock_stat_field apb_qspi_lock_stat_field
 * @brief macros for field apb_qspi_lock_stat
 * @details sticky bit disabling APB cores accessing qspi.
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__APB_QSPI_LOCK_STAT__SHIFT                   2
#define WRPRPINS_PROT_BITS_STAT1__APB_QSPI_LOCK_STAT__WIDTH                   1
#define WRPRPINS_PROT_BITS_STAT1__APB_QSPI_LOCK_STAT__MASK          0x00000004U
#define WRPRPINS_PROT_BITS_STAT1__APB_QSPI_LOCK_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_PROT_BITS_STAT1__APB_QSPI_LOCK_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_PROT_BITS_STAT1__APB_QSPI_LOCK_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_PROT_BITS_STAT1__APB_QSPI_LOCK_STAT__RESET_VALUE   0x00000000U
/** @} */

/* macros for field apb_shub_lock_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_apb_shub_lock_stat_field apb_shub_lock_stat_field
 * @brief macros for field apb_shub_lock_stat
 * @details sticky bit disabling shub write address range.
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__APB_SHUB_LOCK_STAT__SHIFT                   3
#define WRPRPINS_PROT_BITS_STAT1__APB_SHUB_LOCK_STAT__WIDTH                   1
#define WRPRPINS_PROT_BITS_STAT1__APB_SHUB_LOCK_STAT__MASK          0x00000008U
#define WRPRPINS_PROT_BITS_STAT1__APB_SHUB_LOCK_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define WRPRPINS_PROT_BITS_STAT1__APB_SHUB_LOCK_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define WRPRPINS_PROT_BITS_STAT1__APB_SHUB_LOCK_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define WRPRPINS_PROT_BITS_STAT1__APB_SHUB_LOCK_STAT__RESET_VALUE   0x00000000U
/** @} */

/* macros for field suppress_rom_patch_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_suppress_rom_patch_stat_field suppress_rom_patch_stat_field
 * @brief macros for field suppress_rom_patch_stat
 * @details sticky bit preventing ROM patches from being applied
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_ROM_PATCH_STAT__SHIFT              4
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_ROM_PATCH_STAT__WIDTH              1
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_ROM_PATCH_STAT__MASK     0x00000010U
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_ROM_PATCH_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_ROM_PATCH_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_ROM_PATCH_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_ROM_PATCH_STAT__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field suppress_otp_writes_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_suppress_otp_writes_stat_field suppress_otp_writes_stat_field
 * @brief macros for field suppress_otp_writes_stat
 * @details sticky bit preventing OTP writes
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_OTP_WRITES_STAT__SHIFT             5
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_OTP_WRITES_STAT__WIDTH             1
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_OTP_WRITES_STAT__MASK    0x00000020U
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_OTP_WRITES_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_OTP_WRITES_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_OTP_WRITES_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define WRPRPINS_PROT_BITS_STAT1__SUPPRESS_OTP_WRITES_STAT__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_PROT_BITS_STAT1__TYPE                                 uint32_t
#define WRPRPINS_PROT_BITS_STAT1__READ                              0x0000003fU
#define WRPRPINS_PROT_BITS_STAT1__PRESERVED                         0x00000000U
#define WRPRPINS_PROT_BITS_STAT1__RESET_VALUE                       0x00000000U

#endif /* __WRPRPINS_PROT_BITS_STAT1_MACRO__ */

/** @} end of prot_bits_stat1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_qspi_sticky_write_protection0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_qspi_sticky_write_protection0 qspi_sticky_write_protection0
 * @brief Contains register fields associated with qspi_sticky_write_protection0. definitions.
 * @{
 */
#ifndef __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0_MACRO__
#define __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @details if a bit is set, invalidates any writes to the corresponding 2kB block, can only revert with cpu reset
 * @{
 */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__SHIFT                    0
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__WIDTH                   32
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__MASK           0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__TYPE                   uint32_t
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__READ                0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__WRITE               0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__PRESERVED           0x00000000U
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION0_MACRO__ */

/** @} end of qspi_sticky_write_protection0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_qspi_sticky_write_protection1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_qspi_sticky_write_protection1 qspi_sticky_write_protection1
 * @brief Contains register fields associated with qspi_sticky_write_protection1. definitions.
 * @{
 */
#ifndef __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1_MACRO__
#define __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1_MACRO__

/* macros for field set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_set_field set_field
 * @brief macros for field set
 * @{
 */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__SHIFT                    0
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__WIDTH                   32
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__MASK           0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__SET__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__TYPE                   uint32_t
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__READ                0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__WRITE               0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__PRESERVED           0x00000000U
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1__RESET_VALUE         0x00000000U

#endif /* __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION1_MACRO__ */

/** @} end of qspi_sticky_write_protection1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_qspi_sticky_write_protection_status0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_qspi_sticky_write_protection_status0 qspi_sticky_write_protection_status0
 * @brief Contains register fields associated with qspi_sticky_write_protection_status0. definitions.
 * @{
 */
#ifndef __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0_MACRO__
#define __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @details if read back value is 1, then the sticky bit has been set
 * @{
 */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__VAL__SHIFT             0
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__VAL__WIDTH            32
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__VAL__MASK    0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__TYPE            uint32_t
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__READ         0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__PRESERVED    0x00000000U
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS0_MACRO__ */

/** @} end of qspi_sticky_write_protection_status0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_qspi_sticky_write_protection_status1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_qspi_sticky_write_protection_status1 qspi_sticky_write_protection_status1
 * @brief Contains register fields associated with qspi_sticky_write_protection_status1. definitions.
 * @{
 */
#ifndef __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1_MACRO__
#define __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__VAL__SHIFT             0
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__VAL__WIDTH            32
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__VAL__MASK    0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__VAL__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__TYPE            uint32_t
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__READ         0xffffffffU
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__PRESERVED    0x00000000U
#define WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1__RESET_VALUE  0x00000000U

#endif /* __WRPRPINS_QSPI_STICKY_WRITE_PROTECTION_STATUS1_MACRO__ */

/** @} end of qspi_sticky_write_protection_status1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pdsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pdsn pdsn
 * @brief pin drive strength definitions.
 * @{
 */
#ifndef __WRPRPINS_PDSN_MACRO__
#define __WRPRPINS_PDSN_MACRO__

/* macros for field is_high */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_is_high_field is_high_field
 * @brief macros for field is_high
 * @details 0=high drive stength/lower impedance  1=low drive strength/higher impedance
 * @{
 */
#define WRPRPINS_PDSN__IS_HIGH__SHIFT                                         0
#define WRPRPINS_PDSN__IS_HIGH__WIDTH                                        31
#define WRPRPINS_PDSN__IS_HIGH__MASK                                0x7fffffffU
#define WRPRPINS_PDSN__IS_HIGH__READ(src)       ((uint32_t)(src) & 0x7fffffffU)
#define WRPRPINS_PDSN__IS_HIGH__WRITE(src)      ((uint32_t)(src) & 0x7fffffffU)
#define WRPRPINS_PDSN__IS_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_PDSN__IS_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_PDSN__IS_HIGH__RESET_VALUE                         0x00000000U
/** @} */
#define WRPRPINS_PDSN__TYPE                                            uint32_t
#define WRPRPINS_PDSN__READ                                         0x7fffffffU
#define WRPRPINS_PDSN__WRITE                                        0x7fffffffU
#define WRPRPINS_PDSN__PRESERVED                                    0x00000000U
#define WRPRPINS_PDSN__RESET_VALUE                                  0x00000000U

#endif /* __WRPRPINS_PDSN_MACRO__ */

/** @} end of pdsn */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_calCountRC */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_calCountRC calCountRC
 * @brief Contains register fields associated with calCountRC. definitions.
 * @{
 */
#ifndef __WRPRPINS_CALCOUNTRC_MACRO__
#define __WRPRPINS_CALCOUNTRC_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_val_field val_field
 * @brief macros for field val
 * @{
 */
#define WRPRPINS_CALCOUNTRC__VAL__SHIFT                                       0
#define WRPRPINS_CALCOUNTRC__VAL__WIDTH                                      23
#define WRPRPINS_CALCOUNTRC__VAL__MASK                              0x007fffffU
#define WRPRPINS_CALCOUNTRC__VAL__READ(src)     ((uint32_t)(src) & 0x007fffffU)
#define WRPRPINS_CALCOUNTRC__VAL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_CALCOUNTRC__TYPE                                      uint32_t
#define WRPRPINS_CALCOUNTRC__READ                                   0x007fffffU
#define WRPRPINS_CALCOUNTRC__PRESERVED                              0x00000000U
#define WRPRPINS_CALCOUNTRC__RESET_VALUE                            0x00000000U

#endif /* __WRPRPINS_CALCOUNTRC_MACRO__ */

/** @} end of calCountRC */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_secure_debug_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_secure_debug_ctrl secure_debug_ctrl
 * @brief Contains register fields associated with secure_debug_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_SECURE_DEBUG_CTRL_MACRO__
#define __WRPRPINS_SECURE_DEBUG_CTRL_MACRO__

/* macros for field soft_disabled */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_soft_disabled_field soft_disabled_field
 * @brief macros for field soft_disabled
 * @details if sticky_disabled is 0, SW can write 0 to enable SWD interface.  Read value reflects the state of the secure debug FSM.
 * @{
 */
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__SHIFT                      0
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__WIDTH                      1
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__MASK             0x00000001U
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__RESET_VALUE      0x00000000U
/** @} */

/* macros for field sticky_disabled */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sticky_disabled_field sticky_disabled_field
 * @brief macros for field sticky_disabled
 * @details software writes 1 during bootload time to disable SWD interface.  Read value reflects the state of the secure debug FSM.
 * @{
 */
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__SHIFT                    1
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__WIDTH                    1
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__MASK           0x00000002U
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__RESET_VALUE    0x00000000U
/** @} */
#define WRPRPINS_SECURE_DEBUG_CTRL__TYPE                               uint32_t
#define WRPRPINS_SECURE_DEBUG_CTRL__READ                            0x00000003U
#define WRPRPINS_SECURE_DEBUG_CTRL__WRITE                           0x00000003U
#define WRPRPINS_SECURE_DEBUG_CTRL__PRESERVED                       0x00000000U
#define WRPRPINS_SECURE_DEBUG_CTRL__RESET_VALUE                     0x00000000U

#endif /* __WRPRPINS_SECURE_DEBUG_CTRL_MACRO__ */

/** @} end of secure_debug_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_secure_debug_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_secure_debug_stat secure_debug_stat
 * @brief Contains register fields associated with secure_debug_stat. definitions.
 * @{
 */
#ifndef __WRPRPINS_SECURE_DEBUG_STAT_MACRO__
#define __WRPRPINS_SECURE_DEBUG_STAT_MACRO__

/* macros for field sec_dbg_fsm */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sec_dbg_fsm_field sec_dbg_fsm_field
 * @brief macros for field sec_dbg_fsm
 * @details state of secure debug FSM.
 * @{
 */
#define WRPRPINS_SECURE_DEBUG_STAT__SEC_DBG_FSM__SHIFT                        0
#define WRPRPINS_SECURE_DEBUG_STAT__SEC_DBG_FSM__WIDTH                        3
#define WRPRPINS_SECURE_DEBUG_STAT__SEC_DBG_FSM__MASK               0x00000007U
#define WRPRPINS_SECURE_DEBUG_STAT__SEC_DBG_FSM__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define WRPRPINS_SECURE_DEBUG_STAT__SEC_DBG_FSM__RESET_VALUE        0x00000000U
/** @} */
#define WRPRPINS_SECURE_DEBUG_STAT__TYPE                               uint32_t
#define WRPRPINS_SECURE_DEBUG_STAT__READ                            0x00000007U
#define WRPRPINS_SECURE_DEBUG_STAT__PRESERVED                       0x00000000U
#define WRPRPINS_SECURE_DEBUG_STAT__RESET_VALUE                     0x00000000U

#endif /* __WRPRPINS_SECURE_DEBUG_STAT_MACRO__ */

/** @} end of secure_debug_stat */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_chipid1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_chipid1 chipid1
 * @brief Contains register fields associated with chipid1. definitions.
 * @{
 */
#ifndef __WRPRPINS_CHIPID1_MACRO__
#define __WRPRPINS_CHIPID1_MACRO__

/* macros for field char3 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char3_field char3_field
 * @brief macros for field char3
 * @details i
 * @{
 */
#define WRPRPINS_CHIPID1__CHAR3__SHIFT                                        0
#define WRPRPINS_CHIPID1__CHAR3__WIDTH                                        8
#define WRPRPINS_CHIPID1__CHAR3__MASK                               0x000000ffU
#define WRPRPINS_CHIPID1__CHAR3__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_CHIPID1__CHAR3__RESET_VALUE                        0x00000069U
/** @} */

/* macros for field char2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char2_field char2_field
 * @brief macros for field char2
 * @details r
 * @{
 */
#define WRPRPINS_CHIPID1__CHAR2__SHIFT                                        8
#define WRPRPINS_CHIPID1__CHAR2__WIDTH                                        8
#define WRPRPINS_CHIPID1__CHAR2__MASK                               0x0000ff00U
#define WRPRPINS_CHIPID1__CHAR2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_CHIPID1__CHAR2__RESET_VALUE                        0x00000072U
/** @} */

/* macros for field char1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char1_field char1_field
 * @brief macros for field char1
 * @details a
 * @{
 */
#define WRPRPINS_CHIPID1__CHAR1__SHIFT                                       16
#define WRPRPINS_CHIPID1__CHAR1__WIDTH                                        8
#define WRPRPINS_CHIPID1__CHAR1__MASK                               0x00ff0000U
#define WRPRPINS_CHIPID1__CHAR1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_CHIPID1__CHAR1__RESET_VALUE                        0x00000061U
/** @} */

/* macros for field char0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char0_field char0_field
 * @brief macros for field char0
 * @details P
 * @{
 */
#define WRPRPINS_CHIPID1__CHAR0__SHIFT                                       24
#define WRPRPINS_CHIPID1__CHAR0__WIDTH                                        8
#define WRPRPINS_CHIPID1__CHAR0__MASK                               0xff000000U
#define WRPRPINS_CHIPID1__CHAR0__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_CHIPID1__CHAR0__RESET_VALUE                        0x00000050U
/** @} */
#define WRPRPINS_CHIPID1__TYPE                                         uint32_t
#define WRPRPINS_CHIPID1__READ                                      0xffffffffU
#define WRPRPINS_CHIPID1__PRESERVED                                 0x00000000U
#define WRPRPINS_CHIPID1__RESET_VALUE                               0x50617269U

#endif /* __WRPRPINS_CHIPID1_MACRO__ */

/** @} end of chipid1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_chipid2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_chipid2 chipid2
 * @brief Contains register fields associated with chipid2. definitions.
 * @{
 */
#ifndef __WRPRPINS_CHIPID2_MACRO__
#define __WRPRPINS_CHIPID2_MACRO__

/* macros for field char7 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char7_field char7_field
 * @brief macros for field char7
 * @details nul
 * @{
 */
#define WRPRPINS_CHIPID2__CHAR7__SHIFT                                        0
#define WRPRPINS_CHIPID2__CHAR7__WIDTH                                        8
#define WRPRPINS_CHIPID2__CHAR7__MASK                               0x000000ffU
#define WRPRPINS_CHIPID2__CHAR7__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_CHIPID2__CHAR7__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field char6 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char6_field char6_field
 * @brief macros for field char6
 * @details nul
 * @{
 */
#define WRPRPINS_CHIPID2__CHAR6__SHIFT                                        8
#define WRPRPINS_CHIPID2__CHAR6__WIDTH                                        8
#define WRPRPINS_CHIPID2__CHAR6__MASK                               0x0000ff00U
#define WRPRPINS_CHIPID2__CHAR6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_CHIPID2__CHAR6__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field char5 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char5_field char5_field
 * @brief macros for field char5
 * @details nul
 * @{
 */
#define WRPRPINS_CHIPID2__CHAR5__SHIFT                                       16
#define WRPRPINS_CHIPID2__CHAR5__WIDTH                                        8
#define WRPRPINS_CHIPID2__CHAR5__MASK                               0x00ff0000U
#define WRPRPINS_CHIPID2__CHAR5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_CHIPID2__CHAR5__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field char4 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_char4_field char4_field
 * @brief macros for field char4
 * @details s
 * @{
 */
#define WRPRPINS_CHIPID2__CHAR4__SHIFT                                       24
#define WRPRPINS_CHIPID2__CHAR4__WIDTH                                        8
#define WRPRPINS_CHIPID2__CHAR4__MASK                               0xff000000U
#define WRPRPINS_CHIPID2__CHAR4__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_CHIPID2__CHAR4__RESET_VALUE                        0x00000073U
/** @} */
#define WRPRPINS_CHIPID2__TYPE                                         uint32_t
#define WRPRPINS_CHIPID2__READ                                      0xffffffffU
#define WRPRPINS_CHIPID2__PRESERVED                                 0x00000000U
#define WRPRPINS_CHIPID2__RESET_VALUE                               0x73000000U

#endif /* __WRPRPINS_CHIPID2_MACRO__ */

/** @} end of chipid2 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_chiprev */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_chiprev chiprev
 * @brief Contains register fields associated with chiprev. definitions.
 * @{
 */
#ifndef __WRPRPINS_CHIPREV_MACRO__
#define __WRPRPINS_CHIPREV_MACRO__

/* macros for field minor */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_minor_field minor_field
 * @brief macros for field minor
 * @{
 */
#define WRPRPINS_CHIPREV__MINOR__SHIFT                                        0
#define WRPRPINS_CHIPREV__MINOR__WIDTH                                        8
#define WRPRPINS_CHIPREV__MINOR__MASK                               0x000000ffU
#define WRPRPINS_CHIPREV__MINOR__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_CHIPREV__MINOR__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field major */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_major_field major_field
 * @brief macros for field major
 * @{
 */
#define WRPRPINS_CHIPREV__MAJOR__SHIFT                                        8
#define WRPRPINS_CHIPREV__MAJOR__WIDTH                                        8
#define WRPRPINS_CHIPREV__MAJOR__MASK                               0x0000ff00U
#define WRPRPINS_CHIPREV__MAJOR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_CHIPREV__MAJOR__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field running_off_32khz_xtal */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_running_off_32khz_xtal_field running_off_32khz_xtal_field
 * @brief macros for field running_off_32khz_xtal
 * @{
 */
#define WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__SHIFT                      16
#define WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__WIDTH                       1
#define WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__MASK              0x00010000U
#define WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define WRPRPINS_CHIPREV__RUNNING_OFF_32KHZ_XTAL__RESET_VALUE       0x00000000U
/** @} */
#define WRPRPINS_CHIPREV__TYPE                                         uint32_t
#define WRPRPINS_CHIPREV__READ                                      0x0001ffffU
#define WRPRPINS_CHIPREV__PRESERVED                                 0x00000000U
#define WRPRPINS_CHIPREV__RESET_VALUE                               0x00000100U

#endif /* __WRPRPINS_CHIPREV_MACRO__ */

/** @} end of chiprev */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_core_id */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __WRPRPINS_CORE_ID_MACRO__
#define __WRPRPINS_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_id_field id_field
 * @brief macros for field id
 * @details WRPR in ASCII
 * @{
 */
#define WRPRPINS_CORE_ID__ID__SHIFT                                           0
#define WRPRPINS_CORE_ID__ID__WIDTH                                          32
#define WRPRPINS_CORE_ID__ID__MASK                                  0xffffffffU
#define WRPRPINS_CORE_ID__ID__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_CORE_ID__ID__RESET_VALUE                           0x57525052U
/** @} */
#define WRPRPINS_CORE_ID__TYPE                                         uint32_t
#define WRPRPINS_CORE_ID__READ                                      0xffffffffU
#define WRPRPINS_CORE_ID__PRESERVED                                 0x00000000U
#define WRPRPINS_CORE_ID__RESET_VALUE                               0x57525052U

#endif /* __WRPRPINS_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of AT_APB_WRPR_PINS_REGS_CORE */
#endif /* __REG_AT_APB_WRPR_PINS_REGS_CORE_H__ */
