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

/* macros for field p31_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p31_sel_field p31_sel_field
 * @brief macros for field p31_sel
 * @{
 */
#define WRPRPINS_PSEL_H__P31_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_H__P31_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_H__P31_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_H__P31_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_H__P31_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_H__P31_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_H__P31_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_H__P31_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_H__TYPE                                          uint32_t
#define WRPRPINS_PSEL_H__READ                                       0xffffffffU
#define WRPRPINS_PSEL_H__WRITE                                      0xffffffffU
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

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_J */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_J psel_J
 * @brief Contains register fields associated with psel_J. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_J_MACRO__
#define __WRPRPINS_PSEL_J_MACRO__

/* macros for field p32_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p32_sel_field p32_sel_field
 * @brief macros for field p32_sel
 * @{
 */
#define WRPRPINS_PSEL_J__P32_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_J__P32_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_J__P32_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_J__P32_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_J__P32_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_J__P32_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_J__P32_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_J__P32_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p33_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p33_sel_field p33_sel_field
 * @brief macros for field p33_sel
 * @{
 */
#define WRPRPINS_PSEL_J__P33_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_J__P33_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_J__P33_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_J__P33_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_J__P33_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_J__P33_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_J__P33_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_J__P33_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p34_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p34_sel_field p34_sel_field
 * @brief macros for field p34_sel
 * @{
 */
#define WRPRPINS_PSEL_J__P34_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_J__P34_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_J__P34_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_J__P34_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_J__P34_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_J__P34_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_J__P34_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_J__P34_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p35_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p35_sel_field p35_sel_field
 * @brief macros for field p35_sel
 * @{
 */
#define WRPRPINS_PSEL_J__P35_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_J__P35_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_J__P35_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_J__P35_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_J__P35_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_J__P35_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_J__P35_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_J__P35_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_J__TYPE                                          uint32_t
#define WRPRPINS_PSEL_J__READ                                       0xffffffffU
#define WRPRPINS_PSEL_J__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_J__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_J__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_J_MACRO__ */

/** @} end of psel_J */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_K */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_K psel_K
 * @brief Contains register fields associated with psel_K. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_K_MACRO__
#define __WRPRPINS_PSEL_K_MACRO__

/* macros for field p36_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p36_sel_field p36_sel_field
 * @brief macros for field p36_sel
 * @{
 */
#define WRPRPINS_PSEL_K__P36_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_K__P36_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_K__P36_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_K__P36_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_K__P36_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_K__P36_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_K__P36_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_K__P36_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p37_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p37_sel_field p37_sel_field
 * @brief macros for field p37_sel
 * @{
 */
#define WRPRPINS_PSEL_K__P37_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_K__P37_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_K__P37_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_K__P37_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_K__P37_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_K__P37_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_K__P37_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_K__P37_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p38_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p38_sel_field p38_sel_field
 * @brief macros for field p38_sel
 * @{
 */
#define WRPRPINS_PSEL_K__P38_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_K__P38_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_K__P38_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_K__P38_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_K__P38_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_K__P38_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_K__P38_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_K__P38_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p39_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p39_sel_field p39_sel_field
 * @brief macros for field p39_sel
 * @{
 */
#define WRPRPINS_PSEL_K__P39_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_K__P39_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_K__P39_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_K__P39_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_K__P39_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_K__P39_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_K__P39_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_K__P39_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_K__TYPE                                          uint32_t
#define WRPRPINS_PSEL_K__READ                                       0xffffffffU
#define WRPRPINS_PSEL_K__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_K__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_K__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_K_MACRO__ */

/** @} end of psel_K */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_L */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_L psel_L
 * @brief Contains register fields associated with psel_L. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_L_MACRO__
#define __WRPRPINS_PSEL_L_MACRO__

/* macros for field p40_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p40_sel_field p40_sel_field
 * @brief macros for field p40_sel
 * @{
 */
#define WRPRPINS_PSEL_L__P40_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_L__P40_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_L__P40_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_L__P40_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_L__P40_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_L__P40_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_L__P40_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_L__P40_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p41_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p41_sel_field p41_sel_field
 * @brief macros for field p41_sel
 * @{
 */
#define WRPRPINS_PSEL_L__P41_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_L__P41_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_L__P41_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_L__P41_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_L__P41_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_L__P41_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_L__P41_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_L__P41_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p42_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p42_sel_field p42_sel_field
 * @brief macros for field p42_sel
 * @{
 */
#define WRPRPINS_PSEL_L__P42_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_L__P42_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_L__P42_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_L__P42_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_L__P42_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_L__P42_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_L__P42_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_L__P42_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p43_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p43_sel_field p43_sel_field
 * @brief macros for field p43_sel
 * @{
 */
#define WRPRPINS_PSEL_L__P43_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_L__P43_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_L__P43_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_L__P43_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_L__P43_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_L__P43_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_L__P43_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_L__P43_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_L__TYPE                                          uint32_t
#define WRPRPINS_PSEL_L__READ                                       0xffffffffU
#define WRPRPINS_PSEL_L__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_L__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_L__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_L_MACRO__ */

/** @} end of psel_L */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_M */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_M psel_M
 * @brief Contains register fields associated with psel_M. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_M_MACRO__
#define __WRPRPINS_PSEL_M_MACRO__

/* macros for field p44_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p44_sel_field p44_sel_field
 * @brief macros for field p44_sel
 * @{
 */
#define WRPRPINS_PSEL_M__P44_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_M__P44_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_M__P44_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_M__P44_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_M__P44_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_M__P44_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_M__P44_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_M__P44_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p45_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p45_sel_field p45_sel_field
 * @brief macros for field p45_sel
 * @{
 */
#define WRPRPINS_PSEL_M__P45_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_M__P45_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_M__P45_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_M__P45_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_M__P45_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_M__P45_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_M__P45_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_M__P45_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p46_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p46_sel_field p46_sel_field
 * @brief macros for field p46_sel
 * @{
 */
#define WRPRPINS_PSEL_M__P46_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_M__P46_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_M__P46_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_M__P46_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_M__P46_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_M__P46_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_M__P46_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_M__P46_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p47_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p47_sel_field p47_sel_field
 * @brief macros for field p47_sel
 * @{
 */
#define WRPRPINS_PSEL_M__P47_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_M__P47_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_M__P47_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_M__P47_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_M__P47_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_M__P47_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_M__P47_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_M__P47_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_M__TYPE                                          uint32_t
#define WRPRPINS_PSEL_M__READ                                       0xffffffffU
#define WRPRPINS_PSEL_M__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_M__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_M__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_M_MACRO__ */

/** @} end of psel_M */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_N */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_N psel_N
 * @brief Contains register fields associated with psel_N. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_N_MACRO__
#define __WRPRPINS_PSEL_N_MACRO__

/* macros for field p48_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p48_sel_field p48_sel_field
 * @brief macros for field p48_sel
 * @{
 */
#define WRPRPINS_PSEL_N__P48_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_N__P48_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_N__P48_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_N__P48_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_N__P48_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_N__P48_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_N__P48_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_N__P48_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p49_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p49_sel_field p49_sel_field
 * @brief macros for field p49_sel
 * @{
 */
#define WRPRPINS_PSEL_N__P49_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_N__P49_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_N__P49_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_N__P49_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_N__P49_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_N__P49_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_N__P49_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_N__P49_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p50_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p50_sel_field p50_sel_field
 * @brief macros for field p50_sel
 * @{
 */
#define WRPRPINS_PSEL_N__P50_SEL__SHIFT                                      16
#define WRPRPINS_PSEL_N__P50_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_N__P50_SEL__MASK                              0x00ff0000U
#define WRPRPINS_PSEL_N__P50_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_PSEL_N__P50_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define WRPRPINS_PSEL_N__P50_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define WRPRPINS_PSEL_N__P50_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define WRPRPINS_PSEL_N__P50_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p51_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p51_sel_field p51_sel_field
 * @brief macros for field p51_sel
 * @{
 */
#define WRPRPINS_PSEL_N__P51_SEL__SHIFT                                      24
#define WRPRPINS_PSEL_N__P51_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_N__P51_SEL__MASK                              0xff000000U
#define WRPRPINS_PSEL_N__P51_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_PSEL_N__P51_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define WRPRPINS_PSEL_N__P51_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define WRPRPINS_PSEL_N__P51_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define WRPRPINS_PSEL_N__P51_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_N__TYPE                                          uint32_t
#define WRPRPINS_PSEL_N__READ                                       0xffffffffU
#define WRPRPINS_PSEL_N__WRITE                                      0xffffffffU
#define WRPRPINS_PSEL_N__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_N__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_N_MACRO__ */

/** @} end of psel_N */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_psel_O */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_psel_O psel_O
 * @brief Contains register fields associated with psel_O. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEL_O_MACRO__
#define __WRPRPINS_PSEL_O_MACRO__

/* macros for field p52_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p52_sel_field p52_sel_field
 * @brief macros for field p52_sel
 * @{
 */
#define WRPRPINS_PSEL_O__P52_SEL__SHIFT                                       0
#define WRPRPINS_PSEL_O__P52_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_O__P52_SEL__MASK                              0x000000ffU
#define WRPRPINS_PSEL_O__P52_SEL__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_O__P52_SEL__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_PSEL_O__P52_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define WRPRPINS_PSEL_O__P52_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define WRPRPINS_PSEL_O__P52_SEL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p53_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p53_sel_field p53_sel_field
 * @brief macros for field p53_sel
 * @{
 */
#define WRPRPINS_PSEL_O__P53_SEL__SHIFT                                       8
#define WRPRPINS_PSEL_O__P53_SEL__WIDTH                                       8
#define WRPRPINS_PSEL_O__P53_SEL__MASK                              0x0000ff00U
#define WRPRPINS_PSEL_O__P53_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_PSEL_O__P53_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define WRPRPINS_PSEL_O__P53_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define WRPRPINS_PSEL_O__P53_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define WRPRPINS_PSEL_O__P53_SEL__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PSEL_O__TYPE                                          uint32_t
#define WRPRPINS_PSEL_O__READ                                       0x0000ffffU
#define WRPRPINS_PSEL_O__WRITE                                      0x0000ffffU
#define WRPRPINS_PSEL_O__PRESERVED                                  0x00000000U
#define WRPRPINS_PSEL_O__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PSEL_O_MACRO__ */

/** @} end of psel_O */

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
#define WRPRPINS_PUPD_OVRD__PIN__WIDTH                                       32
#define WRPRPINS_PUPD_OVRD__PIN__MASK                               0xffffffffU
#define WRPRPINS_PUPD_OVRD__PIN__READ(src)      ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_PUPD_OVRD__PIN__WRITE(src)     ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_PUPD_OVRD__PIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_PUPD_OVRD__PIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_PUPD_OVRD__PIN__RESET_VALUE                        0x80000000U
/** @} */
#define WRPRPINS_PUPD_OVRD__TYPE                                       uint32_t
#define WRPRPINS_PUPD_OVRD__READ                                    0xffffffffU
#define WRPRPINS_PUPD_OVRD__WRITE                                   0xffffffffU
#define WRPRPINS_PUPD_OVRD__PRESERVED                               0x00000000U
#define WRPRPINS_PUPD_OVRD__RESET_VALUE                             0x80000000U

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
#define WRPRPINS_PUPD_OVRD_VAL__PIN__WIDTH                                   32
#define WRPRPINS_PUPD_OVRD_VAL__PIN__MASK                           0xffffffffU
#define WRPRPINS_PUPD_OVRD_VAL__PIN__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_PUPD_OVRD_VAL__PIN__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_PUPD_OVRD_VAL__PIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define WRPRPINS_PUPD_OVRD_VAL__PIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define WRPRPINS_PUPD_OVRD_VAL__PIN__RESET_VALUE                    0x80000000U
/** @} */
#define WRPRPINS_PUPD_OVRD_VAL__TYPE                                   uint32_t
#define WRPRPINS_PUPD_OVRD_VAL__READ                                0xffffffffU
#define WRPRPINS_PUPD_OVRD_VAL__WRITE                               0xffffffffU
#define WRPRPINS_PUPD_OVRD_VAL__PRESERVED                           0x00000000U
#define WRPRPINS_PUPD_OVRD_VAL__RESET_VALUE                         0x80000000U

#endif /* __WRPRPINS_PUPD_OVRD_VAL_MACRO__ */

/** @} end of pupd_ovrd_val */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pupd_ovrd2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pupd_ovrd2 pupd_ovrd2
 * @brief pin 32-53 pull up/down override control definitions.
 * @{
 */
#ifndef __WRPRPINS_PUPD_OVRD2_MACRO__
#define __WRPRPINS_PUPD_OVRD2_MACRO__

/* macros for field pin */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pin_field pin_field
 * @brief macros for field pin
 * @details when set, overrides pull-up/pull-down from periphery
 * @{
 */
#define WRPRPINS_PUPD_OVRD2__PIN__SHIFT                                       0
#define WRPRPINS_PUPD_OVRD2__PIN__WIDTH                                      22
#define WRPRPINS_PUPD_OVRD2__PIN__MASK                              0x003fffffU
#define WRPRPINS_PUPD_OVRD2__PIN__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define WRPRPINS_PUPD_OVRD2__PIN__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define WRPRPINS_PUPD_OVRD2__PIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define WRPRPINS_PUPD_OVRD2__PIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define WRPRPINS_PUPD_OVRD2__PIN__RESET_VALUE                       0x0000001fU
/** @} */
#define WRPRPINS_PUPD_OVRD2__TYPE                                      uint32_t
#define WRPRPINS_PUPD_OVRD2__READ                                   0x003fffffU
#define WRPRPINS_PUPD_OVRD2__WRITE                                  0x003fffffU
#define WRPRPINS_PUPD_OVRD2__PRESERVED                              0x00000000U
#define WRPRPINS_PUPD_OVRD2__RESET_VALUE                            0x0000001fU

#endif /* __WRPRPINS_PUPD_OVRD2_MACRO__ */

/** @} end of pupd_ovrd2 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pupd_ovrd_val2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pupd_ovrd_val2 pupd_ovrd_val2
 * @brief pin 32-53 pull up/down override value definitions.
 * @{
 */
#ifndef __WRPRPINS_PUPD_OVRD_VAL2_MACRO__
#define __WRPRPINS_PUPD_OVRD_VAL2_MACRO__

/* macros for field pin */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pin_field pin_field
 * @brief macros for field pin
 * @details pull-up/pull_down override value  when pupd_ovrd is set:  1= pull-up override  0= pull-down override
 * @{
 */
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__SHIFT                                   0
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__WIDTH                                  22
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__MASK                          0x003fffffU
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__READ(src) ((uint32_t)(src) & 0x003fffffU)
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x003fffffU)
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define WRPRPINS_PUPD_OVRD_VAL2__PIN__RESET_VALUE                   0x0000001fU
/** @} */
#define WRPRPINS_PUPD_OVRD_VAL2__TYPE                                  uint32_t
#define WRPRPINS_PUPD_OVRD_VAL2__READ                               0x003fffffU
#define WRPRPINS_PUPD_OVRD_VAL2__WRITE                              0x003fffffU
#define WRPRPINS_PUPD_OVRD_VAL2__PRESERVED                          0x00000000U
#define WRPRPINS_PUPD_OVRD_VAL2__RESET_VALUE                        0x0000001fU

#endif /* __WRPRPINS_PUPD_OVRD_VAL2_MACRO__ */

/** @} end of pupd_ovrd_val2 */

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

/* macros for field rom_patch_lock_set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rom_patch_lock_set_field rom_patch_lock_set_field
 * @brief macros for field rom_patch_lock_set
 * @details sets sticky bit preventing ROM patch updates
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__SHIFT                    6
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__WIDTH                    1
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__MASK           0x00000040U
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__RESET_VALUE    0x00000000U
/** @} */

/* macros for field uart2_lock_set */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_uart2_lock_set_field uart2_lock_set_field
 * @brief macros for field uart2_lock_set
 * @details sets sticky bit disabling uart2_tx.
 * @{
 */
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__SHIFT                        7
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__WIDTH                        1
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__MASK               0x00000080U
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define WRPRPINS_PROT_BITS_SET1__UART2_LOCK_SET__RESET_VALUE        0x00000000U
/** @} */
#define WRPRPINS_PROT_BITS_SET1__TYPE                                  uint32_t
#define WRPRPINS_PROT_BITS_SET1__READ                               0x000000ffU
#define WRPRPINS_PROT_BITS_SET1__WRITE                              0x000000ffU
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

/* macros for field rom_patch_lock_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rom_patch_lock_stat_field rom_patch_lock_stat_field
 * @brief macros for field rom_patch_lock_stat
 * @details sticky bit preventing ROM patch updates
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__ROM_PATCH_LOCK_STAT__SHIFT                  6
#define WRPRPINS_PROT_BITS_STAT1__ROM_PATCH_LOCK_STAT__WIDTH                  1
#define WRPRPINS_PROT_BITS_STAT1__ROM_PATCH_LOCK_STAT__MASK         0x00000040U
#define WRPRPINS_PROT_BITS_STAT1__ROM_PATCH_LOCK_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define WRPRPINS_PROT_BITS_STAT1__ROM_PATCH_LOCK_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define WRPRPINS_PROT_BITS_STAT1__ROM_PATCH_LOCK_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define WRPRPINS_PROT_BITS_STAT1__ROM_PATCH_LOCK_STAT__RESET_VALUE  0x00000000U
/** @} */

/* macros for field uart2_lock_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_uart2_lock_stat_field uart2_lock_stat_field
 * @brief macros for field uart2_lock_stat
 * @details sticky bit disabling uart2_tx.
 * @{
 */
#define WRPRPINS_PROT_BITS_STAT1__UART2_LOCK_STAT__SHIFT                      7
#define WRPRPINS_PROT_BITS_STAT1__UART2_LOCK_STAT__WIDTH                      1
#define WRPRPINS_PROT_BITS_STAT1__UART2_LOCK_STAT__MASK             0x00000080U
#define WRPRPINS_PROT_BITS_STAT1__UART2_LOCK_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define WRPRPINS_PROT_BITS_STAT1__UART2_LOCK_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define WRPRPINS_PROT_BITS_STAT1__UART2_LOCK_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define WRPRPINS_PROT_BITS_STAT1__UART2_LOCK_STAT__RESET_VALUE      0x00000000U
/** @} */
#define WRPRPINS_PROT_BITS_STAT1__TYPE                                 uint32_t
#define WRPRPINS_PROT_BITS_STAT1__READ                              0x000000ffU
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

/* macros for field clear_uart1_rx_disable */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_clear_uart1_rx_disable_field clear_uart1_rx_disable_field
 * @brief macros for field clear_uart1_rx_disable
 * @details software writes 1 during bootload time to clear uart1 rx disable.  Read value reflects the state of the uart1 rx disable.  Note the setting of uart1_rx_disable is only done via OTP programming.
 * @{
 */
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__SHIFT             2
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__WIDTH             1
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__MASK    0x00000004U
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_SECURE_DEBUG_CTRL__CLEAR_UART1_RX_DISABLE__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_SECURE_DEBUG_CTRL__TYPE                               uint32_t
#define WRPRPINS_SECURE_DEBUG_CTRL__READ                            0x00000007U
#define WRPRPINS_SECURE_DEBUG_CTRL__WRITE                           0x00000007U
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

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pseq_current_real_time */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pseq_current_real_time pseq_current_real_time
 * @brief Contains register fields associated with pseq_current_real_time. definitions.
 * @{
 */
#ifndef __WRPRPINS_PSEQ_CURRENT_REAL_TIME_MACRO__
#define __WRPRPINS_PSEQ_CURRENT_REAL_TIME_MACRO__

/* macros for field frc */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_frc_field frc_field
 * @brief macros for field frc
 * @details shadow of the free running counter in pseq. In the PCLK domain.
 * @{
 */
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__FRC__SHIFT                           0
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__FRC__WIDTH                          32
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__FRC__MASK                  0xffffffffU
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__FRC__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__FRC__RESET_VALUE           0x00000000U
/** @} */
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__TYPE                          uint32_t
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__READ                       0xffffffffU
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__PRESERVED                  0x00000000U
#define WRPRPINS_PSEQ_CURRENT_REAL_TIME__RESET_VALUE                0x00000000U

#endif /* __WRPRPINS_PSEQ_CURRENT_REAL_TIME_MACRO__ */

/** @} end of pseq_current_real_time */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io0 glitchless_io0
 * @brief Contains register fields associated with glitchless_io0. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO0_MACRO__
#define __WRPRPINS_GLITCHLESS_IO0_MACRO__

/* macros for field P_ie_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_ie_alt_field P_ie_alt_field
 * @brief macros for field P_ie_alt
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__SHIFT                              0
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__WIDTH                             31
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__MASK                     0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_GLITCHLESS_IO0__P_IE_ALT__RESET_VALUE              0x00000000U
/** @} */

/* macros for field P_sel_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_sel_alt_field P_sel_alt_field
 * @brief macros for field P_sel_alt
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__SHIFT                            31
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__WIDTH                             1
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__MASK                    0x80000000U
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define WRPRPINS_GLITCHLESS_IO0__P_SEL_ALT__RESET_VALUE             0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO0__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO0__READ                               0xffffffffU
#define WRPRPINS_GLITCHLESS_IO0__WRITE                              0xffffffffU
#define WRPRPINS_GLITCHLESS_IO0__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO0__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO0_MACRO__ */

/** @} end of glitchless_io0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io1 glitchless_io1
 * @brief Contains register fields associated with glitchless_io1. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO1_MACRO__
#define __WRPRPINS_GLITCHLESS_IO1_MACRO__

/* macros for field P_pull_up_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_pull_up_alt_field P_pull_up_alt_field
 * @brief macros for field P_pull_up_alt
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__SHIFT                         0
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__WIDTH                        31
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__MASK                0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_GLITCHLESS_IO1__P_PULL_UP_ALT__RESET_VALUE         0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO1__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO1__READ                               0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO1__WRITE                              0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO1__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO1__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO1_MACRO__ */

/** @} end of glitchless_io1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io2 glitchless_io2
 * @brief Contains register fields associated with glitchless_io2. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO2_MACRO__
#define __WRPRPINS_GLITCHLESS_IO2_MACRO__

/* macros for field P_pull_dn_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_pull_dn_alt_field P_pull_dn_alt_field
 * @brief macros for field P_pull_dn_alt
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__SHIFT                         0
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__WIDTH                        31
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__MASK                0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_GLITCHLESS_IO2__P_PULL_DN_ALT__RESET_VALUE         0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO2__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO2__READ                               0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO2__WRITE                              0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO2__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO2__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO2_MACRO__ */

/** @} end of glitchless_io2 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io3 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io3 glitchless_io3
 * @brief Contains register fields associated with glitchless_io3. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO3_MACRO__
#define __WRPRPINS_GLITCHLESS_IO3_MACRO__

/* macros for field P_oen_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_oen_alt_field P_oen_alt_field
 * @brief macros for field P_oen_alt
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__SHIFT                             0
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__WIDTH                            31
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__MASK                    0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_GLITCHLESS_IO3__P_OEN_ALT__RESET_VALUE             0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO3__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO3__READ                               0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO3__WRITE                              0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO3__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO3__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO3_MACRO__ */

/** @} end of glitchless_io3 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io4 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io4 glitchless_io4
 * @brief Contains register fields associated with glitchless_io4. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO4_MACRO__
#define __WRPRPINS_GLITCHLESS_IO4_MACRO__

/* macros for field P_dout_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_dout_alt_field P_dout_alt_field
 * @brief macros for field P_dout_alt
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__SHIFT                            0
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__WIDTH                           31
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__MASK                   0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_GLITCHLESS_IO4__P_DOUT_ALT__RESET_VALUE            0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO4__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO4__READ                               0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO4__WRITE                              0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO4__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO4__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO4_MACRO__ */

/** @} end of glitchless_io4 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io5 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io5 glitchless_io5
 * @brief Contains register fields associated with glitchless_io5. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO5_MACRO__
#define __WRPRPINS_GLITCHLESS_IO5_MACRO__

/* macros for field P_din_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_din_alt_field P_din_alt_field
 * @brief macros for field P_din_alt
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__SHIFT                             0
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__WIDTH                            31
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__MASK                    0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7fffffffU) | ((uint32_t)(src) &\
                    0x7fffffffU)
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x7fffffffU)))
#define WRPRPINS_GLITCHLESS_IO5__P_DIN_ALT__RESET_VALUE             0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO5__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO5__READ                               0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO5__WRITE                              0x7fffffffU
#define WRPRPINS_GLITCHLESS_IO5__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO5__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO5_MACRO__ */

/** @} end of glitchless_io5 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io6 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io6 glitchless_io6
 * @brief Contains register fields associated with glitchless_io6. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO6_MACRO__
#define __WRPRPINS_GLITCHLESS_IO6_MACRO__

/* macros for field P_ie_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_ie_alt_field P_ie_alt_field
 * @brief macros for field P_ie_alt
 * @details for P53 to P31
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__SHIFT                              0
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__WIDTH                             23
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__MASK                     0x007fffffU
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define WRPRPINS_GLITCHLESS_IO6__P_IE_ALT__RESET_VALUE              0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO6__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO6__READ                               0x007fffffU
#define WRPRPINS_GLITCHLESS_IO6__WRITE                              0x007fffffU
#define WRPRPINS_GLITCHLESS_IO6__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO6__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO6_MACRO__ */

/** @} end of glitchless_io6 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io7 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io7 glitchless_io7
 * @brief Contains register fields associated with glitchless_io7. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO7_MACRO__
#define __WRPRPINS_GLITCHLESS_IO7_MACRO__

/* macros for field P_pull_up_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_pull_up_alt_field P_pull_up_alt_field
 * @brief macros for field P_pull_up_alt
 * @details for P53 to P31
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__SHIFT                         0
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__WIDTH                        23
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__MASK                0x007fffffU
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define WRPRPINS_GLITCHLESS_IO7__P_PULL_UP_ALT__RESET_VALUE         0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO7__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO7__READ                               0x007fffffU
#define WRPRPINS_GLITCHLESS_IO7__WRITE                              0x007fffffU
#define WRPRPINS_GLITCHLESS_IO7__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO7__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO7_MACRO__ */

/** @} end of glitchless_io7 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io8 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io8 glitchless_io8
 * @brief Contains register fields associated with glitchless_io8. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO8_MACRO__
#define __WRPRPINS_GLITCHLESS_IO8_MACRO__

/* macros for field P_pull_dn_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_pull_dn_alt_field P_pull_dn_alt_field
 * @brief macros for field P_pull_dn_alt
 * @details for P53 to P31
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__SHIFT                         0
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__WIDTH                        23
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__MASK                0x007fffffU
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define WRPRPINS_GLITCHLESS_IO8__P_PULL_DN_ALT__RESET_VALUE         0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO8__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO8__READ                               0x007fffffU
#define WRPRPINS_GLITCHLESS_IO8__WRITE                              0x007fffffU
#define WRPRPINS_GLITCHLESS_IO8__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO8__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO8_MACRO__ */

/** @} end of glitchless_io8 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io9 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io9 glitchless_io9
 * @brief Contains register fields associated with glitchless_io9. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO9_MACRO__
#define __WRPRPINS_GLITCHLESS_IO9_MACRO__

/* macros for field P_oen_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_oen_alt_field P_oen_alt_field
 * @brief macros for field P_oen_alt
 * @details for P53 to P31
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__SHIFT                             0
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__WIDTH                            23
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__MASK                    0x007fffffU
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define WRPRPINS_GLITCHLESS_IO9__P_OEN_ALT__RESET_VALUE             0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO9__TYPE                                  uint32_t
#define WRPRPINS_GLITCHLESS_IO9__READ                               0x007fffffU
#define WRPRPINS_GLITCHLESS_IO9__WRITE                              0x007fffffU
#define WRPRPINS_GLITCHLESS_IO9__PRESERVED                          0x00000000U
#define WRPRPINS_GLITCHLESS_IO9__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO9_MACRO__ */

/** @} end of glitchless_io9 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io10 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io10 glitchless_io10
 * @brief Contains register fields associated with glitchless_io10. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO10_MACRO__
#define __WRPRPINS_GLITCHLESS_IO10_MACRO__

/* macros for field P_dout_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_dout_alt_field P_dout_alt_field
 * @brief macros for field P_dout_alt
 * @details for P53 to P31
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__SHIFT                           0
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__WIDTH                          23
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__MASK                  0x007fffffU
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define WRPRPINS_GLITCHLESS_IO10__P_DOUT_ALT__RESET_VALUE           0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO10__TYPE                                 uint32_t
#define WRPRPINS_GLITCHLESS_IO10__READ                              0x007fffffU
#define WRPRPINS_GLITCHLESS_IO10__WRITE                             0x007fffffU
#define WRPRPINS_GLITCHLESS_IO10__PRESERVED                         0x00000000U
#define WRPRPINS_GLITCHLESS_IO10__RESET_VALUE                       0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO10_MACRO__ */

/** @} end of glitchless_io10 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_glitchless_io11 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_glitchless_io11 glitchless_io11
 * @brief Contains register fields associated with glitchless_io11. definitions.
 * @{
 */
#ifndef __WRPRPINS_GLITCHLESS_IO11_MACRO__
#define __WRPRPINS_GLITCHLESS_IO11_MACRO__

/* macros for field P_din_alt */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_P_din_alt_field P_din_alt_field
 * @brief macros for field P_din_alt
 * @details for P53 to P31
 * @{
 */
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__SHIFT                            0
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__WIDTH                           23
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__MASK                   0x007fffffU
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fffffU) | ((uint32_t)(src) &\
                    0x007fffffU)
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x007fffffU)))
#define WRPRPINS_GLITCHLESS_IO11__P_DIN_ALT__RESET_VALUE            0x00000000U
/** @} */
#define WRPRPINS_GLITCHLESS_IO11__TYPE                                 uint32_t
#define WRPRPINS_GLITCHLESS_IO11__READ                              0x007fffffU
#define WRPRPINS_GLITCHLESS_IO11__WRITE                             0x007fffffU
#define WRPRPINS_GLITCHLESS_IO11__PRESERVED                         0x00000000U
#define WRPRPINS_GLITCHLESS_IO11__RESET_VALUE                       0x00000000U

#endif /* __WRPRPINS_GLITCHLESS_IO11_MACRO__ */

/** @} end of glitchless_io11 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pdsn_a */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pdsn_a pdsn_a
 * @brief pin drive strength definitions.
 * @{
 */
#ifndef __WRPRPINS_PDSN_A_MACRO__
#define __WRPRPINS_PDSN_A_MACRO__

/* macros for field p0_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p0_dsn_field p0_dsn_field
 * @brief macros for field p0_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P0_DSN__SHIFT                                        0
#define WRPRPINS_PDSN_A__P0_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P0_DSN__MASK                               0x00000003U
#define WRPRPINS_PDSN_A__P0_DSN__READ(src)      ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_A__P0_DSN__WRITE(src)     ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_A__P0_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define WRPRPINS_PDSN_A__P0_DSN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define WRPRPINS_PDSN_A__P0_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p1_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p1_dsn_field p1_dsn_field
 * @brief macros for field p1_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P1_DSN__SHIFT                                        2
#define WRPRPINS_PDSN_A__P1_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P1_DSN__MASK                               0x0000000cU
#define WRPRPINS_PDSN_A__P1_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define WRPRPINS_PDSN_A__P1_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define WRPRPINS_PDSN_A__P1_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define WRPRPINS_PDSN_A__P1_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define WRPRPINS_PDSN_A__P1_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p2_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p2_dsn_field p2_dsn_field
 * @brief macros for field p2_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P2_DSN__SHIFT                                        4
#define WRPRPINS_PDSN_A__P2_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P2_DSN__MASK                               0x00000030U
#define WRPRPINS_PDSN_A__P2_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define WRPRPINS_PDSN_A__P2_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define WRPRPINS_PDSN_A__P2_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define WRPRPINS_PDSN_A__P2_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define WRPRPINS_PDSN_A__P2_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p3_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p3_dsn_field p3_dsn_field
 * @brief macros for field p3_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P3_DSN__SHIFT                                        6
#define WRPRPINS_PDSN_A__P3_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P3_DSN__MASK                               0x000000c0U
#define WRPRPINS_PDSN_A__P3_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define WRPRPINS_PDSN_A__P3_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define WRPRPINS_PDSN_A__P3_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define WRPRPINS_PDSN_A__P3_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define WRPRPINS_PDSN_A__P3_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p4_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p4_dsn_field p4_dsn_field
 * @brief macros for field p4_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P4_DSN__SHIFT                                        8
#define WRPRPINS_PDSN_A__P4_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P4_DSN__MASK                               0x00000300U
#define WRPRPINS_PDSN_A__P4_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define WRPRPINS_PDSN_A__P4_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define WRPRPINS_PDSN_A__P4_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define WRPRPINS_PDSN_A__P4_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define WRPRPINS_PDSN_A__P4_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p5_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p5_dsn_field p5_dsn_field
 * @brief macros for field p5_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P5_DSN__SHIFT                                       10
#define WRPRPINS_PDSN_A__P5_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P5_DSN__MASK                               0x00000c00U
#define WRPRPINS_PDSN_A__P5_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define WRPRPINS_PDSN_A__P5_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define WRPRPINS_PDSN_A__P5_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define WRPRPINS_PDSN_A__P5_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define WRPRPINS_PDSN_A__P5_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p6_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p6_dsn_field p6_dsn_field
 * @brief macros for field p6_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P6_DSN__SHIFT                                       12
#define WRPRPINS_PDSN_A__P6_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P6_DSN__MASK                               0x00003000U
#define WRPRPINS_PDSN_A__P6_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define WRPRPINS_PDSN_A__P6_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define WRPRPINS_PDSN_A__P6_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define WRPRPINS_PDSN_A__P6_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define WRPRPINS_PDSN_A__P6_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p7_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p7_dsn_field p7_dsn_field
 * @brief macros for field p7_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P7_DSN__SHIFT                                       14
#define WRPRPINS_PDSN_A__P7_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P7_DSN__MASK                               0x0000c000U
#define WRPRPINS_PDSN_A__P7_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000c000U) >> 14)
#define WRPRPINS_PDSN_A__P7_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0000c000U)
#define WRPRPINS_PDSN_A__P7_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define WRPRPINS_PDSN_A__P7_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define WRPRPINS_PDSN_A__P7_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p8_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p8_dsn_field p8_dsn_field
 * @brief macros for field p8_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P8_DSN__SHIFT                                       16
#define WRPRPINS_PDSN_A__P8_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P8_DSN__MASK                               0x00030000U
#define WRPRPINS_PDSN_A__P8_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define WRPRPINS_PDSN_A__P8_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define WRPRPINS_PDSN_A__P8_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define WRPRPINS_PDSN_A__P8_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define WRPRPINS_PDSN_A__P8_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p9_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p9_dsn_field p9_dsn_field
 * @brief macros for field p9_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P9_DSN__SHIFT                                       18
#define WRPRPINS_PDSN_A__P9_DSN__WIDTH                                        2
#define WRPRPINS_PDSN_A__P9_DSN__MASK                               0x000c0000U
#define WRPRPINS_PDSN_A__P9_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000c0000U) >> 18)
#define WRPRPINS_PDSN_A__P9_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x000c0000U)
#define WRPRPINS_PDSN_A__P9_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000c0000U) | (((uint32_t)(src) <<\
                    18) & 0x000c0000U)
#define WRPRPINS_PDSN_A__P9_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x000c0000U)))
#define WRPRPINS_PDSN_A__P9_DSN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field p10_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p10_dsn_field p10_dsn_field
 * @brief macros for field p10_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P10_DSN__SHIFT                                      20
#define WRPRPINS_PDSN_A__P10_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_A__P10_DSN__MASK                              0x00300000U
#define WRPRPINS_PDSN_A__P10_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define WRPRPINS_PDSN_A__P10_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define WRPRPINS_PDSN_A__P10_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define WRPRPINS_PDSN_A__P10_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define WRPRPINS_PDSN_A__P10_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p11_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p11_dsn_field p11_dsn_field
 * @brief macros for field p11_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P11_DSN__SHIFT                                      22
#define WRPRPINS_PDSN_A__P11_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_A__P11_DSN__MASK                              0x00c00000U
#define WRPRPINS_PDSN_A__P11_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define WRPRPINS_PDSN_A__P11_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define WRPRPINS_PDSN_A__P11_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define WRPRPINS_PDSN_A__P11_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define WRPRPINS_PDSN_A__P11_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p12_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p12_dsn_field p12_dsn_field
 * @brief macros for field p12_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P12_DSN__SHIFT                                      24
#define WRPRPINS_PDSN_A__P12_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_A__P12_DSN__MASK                              0x03000000U
#define WRPRPINS_PDSN_A__P12_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define WRPRPINS_PDSN_A__P12_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define WRPRPINS_PDSN_A__P12_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define WRPRPINS_PDSN_A__P12_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define WRPRPINS_PDSN_A__P12_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p13_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p13_dsn_field p13_dsn_field
 * @brief macros for field p13_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P13_DSN__SHIFT                                      26
#define WRPRPINS_PDSN_A__P13_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_A__P13_DSN__MASK                              0x0c000000U
#define WRPRPINS_PDSN_A__P13_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define WRPRPINS_PDSN_A__P13_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define WRPRPINS_PDSN_A__P13_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define WRPRPINS_PDSN_A__P13_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define WRPRPINS_PDSN_A__P13_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p14_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p14_dsn_field p14_dsn_field
 * @brief macros for field p14_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P14_DSN__SHIFT                                      28
#define WRPRPINS_PDSN_A__P14_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_A__P14_DSN__MASK                              0x30000000U
#define WRPRPINS_PDSN_A__P14_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define WRPRPINS_PDSN_A__P14_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define WRPRPINS_PDSN_A__P14_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define WRPRPINS_PDSN_A__P14_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define WRPRPINS_PDSN_A__P14_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p15_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p15_dsn_field p15_dsn_field
 * @brief macros for field p15_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_A__P15_DSN__SHIFT                                      30
#define WRPRPINS_PDSN_A__P15_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_A__P15_DSN__MASK                              0xc0000000U
#define WRPRPINS_PDSN_A__P15_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define WRPRPINS_PDSN_A__P15_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define WRPRPINS_PDSN_A__P15_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define WRPRPINS_PDSN_A__P15_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define WRPRPINS_PDSN_A__P15_DSN__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PDSN_A__TYPE                                          uint32_t
#define WRPRPINS_PDSN_A__READ                                       0xffffffffU
#define WRPRPINS_PDSN_A__WRITE                                      0xffffffffU
#define WRPRPINS_PDSN_A__PRESERVED                                  0x00000000U
#define WRPRPINS_PDSN_A__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PDSN_A_MACRO__ */

/** @} end of pdsn_a */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pdsn_b */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pdsn_b pdsn_b
 * @brief pin drive strength definitions.
 * @{
 */
#ifndef __WRPRPINS_PDSN_B_MACRO__
#define __WRPRPINS_PDSN_B_MACRO__

/* macros for field p16_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p16_dsn_field p16_dsn_field
 * @brief macros for field p16_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P16_DSN__SHIFT                                       0
#define WRPRPINS_PDSN_B__P16_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P16_DSN__MASK                              0x00000003U
#define WRPRPINS_PDSN_B__P16_DSN__READ(src)     ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_B__P16_DSN__WRITE(src)    ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_B__P16_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define WRPRPINS_PDSN_B__P16_DSN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define WRPRPINS_PDSN_B__P16_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p17_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p17_dsn_field p17_dsn_field
 * @brief macros for field p17_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P17_DSN__SHIFT                                       2
#define WRPRPINS_PDSN_B__P17_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P17_DSN__MASK                              0x0000000cU
#define WRPRPINS_PDSN_B__P17_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define WRPRPINS_PDSN_B__P17_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define WRPRPINS_PDSN_B__P17_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define WRPRPINS_PDSN_B__P17_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define WRPRPINS_PDSN_B__P17_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p18_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p18_dsn_field p18_dsn_field
 * @brief macros for field p18_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P18_DSN__SHIFT                                       4
#define WRPRPINS_PDSN_B__P18_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P18_DSN__MASK                              0x00000030U
#define WRPRPINS_PDSN_B__P18_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define WRPRPINS_PDSN_B__P18_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define WRPRPINS_PDSN_B__P18_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define WRPRPINS_PDSN_B__P18_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define WRPRPINS_PDSN_B__P18_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p19_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p19_dsn_field p19_dsn_field
 * @brief macros for field p19_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P19_DSN__SHIFT                                       6
#define WRPRPINS_PDSN_B__P19_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P19_DSN__MASK                              0x000000c0U
#define WRPRPINS_PDSN_B__P19_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define WRPRPINS_PDSN_B__P19_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define WRPRPINS_PDSN_B__P19_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define WRPRPINS_PDSN_B__P19_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define WRPRPINS_PDSN_B__P19_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p20_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p20_dsn_field p20_dsn_field
 * @brief macros for field p20_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P20_DSN__SHIFT                                       8
#define WRPRPINS_PDSN_B__P20_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P20_DSN__MASK                              0x00000300U
#define WRPRPINS_PDSN_B__P20_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define WRPRPINS_PDSN_B__P20_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define WRPRPINS_PDSN_B__P20_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define WRPRPINS_PDSN_B__P20_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define WRPRPINS_PDSN_B__P20_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p21_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p21_dsn_field p21_dsn_field
 * @brief macros for field p21_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P21_DSN__SHIFT                                      10
#define WRPRPINS_PDSN_B__P21_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P21_DSN__MASK                              0x00000c00U
#define WRPRPINS_PDSN_B__P21_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define WRPRPINS_PDSN_B__P21_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define WRPRPINS_PDSN_B__P21_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define WRPRPINS_PDSN_B__P21_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define WRPRPINS_PDSN_B__P21_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p22_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p22_dsn_field p22_dsn_field
 * @brief macros for field p22_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P22_DSN__SHIFT                                      12
#define WRPRPINS_PDSN_B__P22_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P22_DSN__MASK                              0x00003000U
#define WRPRPINS_PDSN_B__P22_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define WRPRPINS_PDSN_B__P22_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define WRPRPINS_PDSN_B__P22_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define WRPRPINS_PDSN_B__P22_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define WRPRPINS_PDSN_B__P22_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p23_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p23_dsn_field p23_dsn_field
 * @brief macros for field p23_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P23_DSN__SHIFT                                      14
#define WRPRPINS_PDSN_B__P23_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P23_DSN__MASK                              0x0000c000U
#define WRPRPINS_PDSN_B__P23_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000c000U) >> 14)
#define WRPRPINS_PDSN_B__P23_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0000c000U)
#define WRPRPINS_PDSN_B__P23_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define WRPRPINS_PDSN_B__P23_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define WRPRPINS_PDSN_B__P23_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p24_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p24_dsn_field p24_dsn_field
 * @brief macros for field p24_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P24_DSN__SHIFT                                      16
#define WRPRPINS_PDSN_B__P24_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P24_DSN__MASK                              0x00030000U
#define WRPRPINS_PDSN_B__P24_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define WRPRPINS_PDSN_B__P24_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define WRPRPINS_PDSN_B__P24_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define WRPRPINS_PDSN_B__P24_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define WRPRPINS_PDSN_B__P24_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p25_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p25_dsn_field p25_dsn_field
 * @brief macros for field p25_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P25_DSN__SHIFT                                      18
#define WRPRPINS_PDSN_B__P25_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P25_DSN__MASK                              0x000c0000U
#define WRPRPINS_PDSN_B__P25_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000c0000U) >> 18)
#define WRPRPINS_PDSN_B__P25_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x000c0000U)
#define WRPRPINS_PDSN_B__P25_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000c0000U) | (((uint32_t)(src) <<\
                    18) & 0x000c0000U)
#define WRPRPINS_PDSN_B__P25_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x000c0000U)))
#define WRPRPINS_PDSN_B__P25_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p26_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p26_dsn_field p26_dsn_field
 * @brief macros for field p26_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P26_DSN__SHIFT                                      20
#define WRPRPINS_PDSN_B__P26_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P26_DSN__MASK                              0x00300000U
#define WRPRPINS_PDSN_B__P26_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define WRPRPINS_PDSN_B__P26_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define WRPRPINS_PDSN_B__P26_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define WRPRPINS_PDSN_B__P26_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define WRPRPINS_PDSN_B__P26_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p27_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p27_dsn_field p27_dsn_field
 * @brief macros for field p27_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P27_DSN__SHIFT                                      22
#define WRPRPINS_PDSN_B__P27_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P27_DSN__MASK                              0x00c00000U
#define WRPRPINS_PDSN_B__P27_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define WRPRPINS_PDSN_B__P27_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define WRPRPINS_PDSN_B__P27_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define WRPRPINS_PDSN_B__P27_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define WRPRPINS_PDSN_B__P27_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p28_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p28_dsn_field p28_dsn_field
 * @brief macros for field p28_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P28_DSN__SHIFT                                      24
#define WRPRPINS_PDSN_B__P28_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P28_DSN__MASK                              0x03000000U
#define WRPRPINS_PDSN_B__P28_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define WRPRPINS_PDSN_B__P28_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define WRPRPINS_PDSN_B__P28_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define WRPRPINS_PDSN_B__P28_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define WRPRPINS_PDSN_B__P28_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p29_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p29_dsn_field p29_dsn_field
 * @brief macros for field p29_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P29_DSN__SHIFT                                      26
#define WRPRPINS_PDSN_B__P29_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P29_DSN__MASK                              0x0c000000U
#define WRPRPINS_PDSN_B__P29_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define WRPRPINS_PDSN_B__P29_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define WRPRPINS_PDSN_B__P29_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define WRPRPINS_PDSN_B__P29_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define WRPRPINS_PDSN_B__P29_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p30_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p30_dsn_field p30_dsn_field
 * @brief macros for field p30_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P30_DSN__SHIFT                                      28
#define WRPRPINS_PDSN_B__P30_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P30_DSN__MASK                              0x30000000U
#define WRPRPINS_PDSN_B__P30_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define WRPRPINS_PDSN_B__P30_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define WRPRPINS_PDSN_B__P30_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define WRPRPINS_PDSN_B__P30_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define WRPRPINS_PDSN_B__P30_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p31_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p31_dsn_field p31_dsn_field
 * @brief macros for field p31_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_B__P31_DSN__SHIFT                                      30
#define WRPRPINS_PDSN_B__P31_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_B__P31_DSN__MASK                              0xc0000000U
#define WRPRPINS_PDSN_B__P31_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define WRPRPINS_PDSN_B__P31_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define WRPRPINS_PDSN_B__P31_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define WRPRPINS_PDSN_B__P31_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define WRPRPINS_PDSN_B__P31_DSN__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PDSN_B__TYPE                                          uint32_t
#define WRPRPINS_PDSN_B__READ                                       0xffffffffU
#define WRPRPINS_PDSN_B__WRITE                                      0xffffffffU
#define WRPRPINS_PDSN_B__PRESERVED                                  0x00000000U
#define WRPRPINS_PDSN_B__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PDSN_B_MACRO__ */

/** @} end of pdsn_b */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pdsn_c */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pdsn_c pdsn_c
 * @brief pin drive strength definitions.
 * @{
 */
#ifndef __WRPRPINS_PDSN_C_MACRO__
#define __WRPRPINS_PDSN_C_MACRO__

/* macros for field p32_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p32_dsn_field p32_dsn_field
 * @brief macros for field p32_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P32_DSN__SHIFT                                       0
#define WRPRPINS_PDSN_C__P32_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P32_DSN__MASK                              0x00000003U
#define WRPRPINS_PDSN_C__P32_DSN__READ(src)     ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_C__P32_DSN__WRITE(src)    ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_C__P32_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define WRPRPINS_PDSN_C__P32_DSN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define WRPRPINS_PDSN_C__P32_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p33_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p33_dsn_field p33_dsn_field
 * @brief macros for field p33_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P33_DSN__SHIFT                                       2
#define WRPRPINS_PDSN_C__P33_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P33_DSN__MASK                              0x0000000cU
#define WRPRPINS_PDSN_C__P33_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define WRPRPINS_PDSN_C__P33_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define WRPRPINS_PDSN_C__P33_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define WRPRPINS_PDSN_C__P33_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define WRPRPINS_PDSN_C__P33_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p34_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p34_dsn_field p34_dsn_field
 * @brief macros for field p34_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P34_DSN__SHIFT                                       4
#define WRPRPINS_PDSN_C__P34_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P34_DSN__MASK                              0x00000030U
#define WRPRPINS_PDSN_C__P34_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define WRPRPINS_PDSN_C__P34_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define WRPRPINS_PDSN_C__P34_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define WRPRPINS_PDSN_C__P34_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define WRPRPINS_PDSN_C__P34_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p35_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p35_dsn_field p35_dsn_field
 * @brief macros for field p35_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P35_DSN__SHIFT                                       6
#define WRPRPINS_PDSN_C__P35_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P35_DSN__MASK                              0x000000c0U
#define WRPRPINS_PDSN_C__P35_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define WRPRPINS_PDSN_C__P35_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define WRPRPINS_PDSN_C__P35_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define WRPRPINS_PDSN_C__P35_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define WRPRPINS_PDSN_C__P35_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p36_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p36_dsn_field p36_dsn_field
 * @brief macros for field p36_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P36_DSN__SHIFT                                       8
#define WRPRPINS_PDSN_C__P36_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P36_DSN__MASK                              0x00000300U
#define WRPRPINS_PDSN_C__P36_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define WRPRPINS_PDSN_C__P36_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define WRPRPINS_PDSN_C__P36_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define WRPRPINS_PDSN_C__P36_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define WRPRPINS_PDSN_C__P36_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p37_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p37_dsn_field p37_dsn_field
 * @brief macros for field p37_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P37_DSN__SHIFT                                      10
#define WRPRPINS_PDSN_C__P37_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P37_DSN__MASK                              0x00000c00U
#define WRPRPINS_PDSN_C__P37_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define WRPRPINS_PDSN_C__P37_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define WRPRPINS_PDSN_C__P37_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define WRPRPINS_PDSN_C__P37_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define WRPRPINS_PDSN_C__P37_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p38_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p38_dsn_field p38_dsn_field
 * @brief macros for field p38_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P38_DSN__SHIFT                                      12
#define WRPRPINS_PDSN_C__P38_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P38_DSN__MASK                              0x00003000U
#define WRPRPINS_PDSN_C__P38_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define WRPRPINS_PDSN_C__P38_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define WRPRPINS_PDSN_C__P38_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define WRPRPINS_PDSN_C__P38_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define WRPRPINS_PDSN_C__P38_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p39_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p39_dsn_field p39_dsn_field
 * @brief macros for field p39_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P39_DSN__SHIFT                                      14
#define WRPRPINS_PDSN_C__P39_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P39_DSN__MASK                              0x0000c000U
#define WRPRPINS_PDSN_C__P39_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000c000U) >> 14)
#define WRPRPINS_PDSN_C__P39_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0000c000U)
#define WRPRPINS_PDSN_C__P39_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define WRPRPINS_PDSN_C__P39_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define WRPRPINS_PDSN_C__P39_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p40_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p40_dsn_field p40_dsn_field
 * @brief macros for field p40_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P40_DSN__SHIFT                                      16
#define WRPRPINS_PDSN_C__P40_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P40_DSN__MASK                              0x00030000U
#define WRPRPINS_PDSN_C__P40_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define WRPRPINS_PDSN_C__P40_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define WRPRPINS_PDSN_C__P40_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define WRPRPINS_PDSN_C__P40_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define WRPRPINS_PDSN_C__P40_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p41_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p41_dsn_field p41_dsn_field
 * @brief macros for field p41_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P41_DSN__SHIFT                                      18
#define WRPRPINS_PDSN_C__P41_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P41_DSN__MASK                              0x000c0000U
#define WRPRPINS_PDSN_C__P41_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000c0000U) >> 18)
#define WRPRPINS_PDSN_C__P41_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x000c0000U)
#define WRPRPINS_PDSN_C__P41_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000c0000U) | (((uint32_t)(src) <<\
                    18) & 0x000c0000U)
#define WRPRPINS_PDSN_C__P41_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x000c0000U)))
#define WRPRPINS_PDSN_C__P41_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p42_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p42_dsn_field p42_dsn_field
 * @brief macros for field p42_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P42_DSN__SHIFT                                      20
#define WRPRPINS_PDSN_C__P42_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P42_DSN__MASK                              0x00300000U
#define WRPRPINS_PDSN_C__P42_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define WRPRPINS_PDSN_C__P42_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define WRPRPINS_PDSN_C__P42_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define WRPRPINS_PDSN_C__P42_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define WRPRPINS_PDSN_C__P42_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p43_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p43_dsn_field p43_dsn_field
 * @brief macros for field p43_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P43_DSN__SHIFT                                      22
#define WRPRPINS_PDSN_C__P43_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P43_DSN__MASK                              0x00c00000U
#define WRPRPINS_PDSN_C__P43_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define WRPRPINS_PDSN_C__P43_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define WRPRPINS_PDSN_C__P43_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define WRPRPINS_PDSN_C__P43_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define WRPRPINS_PDSN_C__P43_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p44_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p44_dsn_field p44_dsn_field
 * @brief macros for field p44_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P44_DSN__SHIFT                                      24
#define WRPRPINS_PDSN_C__P44_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P44_DSN__MASK                              0x03000000U
#define WRPRPINS_PDSN_C__P44_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define WRPRPINS_PDSN_C__P44_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define WRPRPINS_PDSN_C__P44_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define WRPRPINS_PDSN_C__P44_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define WRPRPINS_PDSN_C__P44_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p45_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p45_dsn_field p45_dsn_field
 * @brief macros for field p45_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P45_DSN__SHIFT                                      26
#define WRPRPINS_PDSN_C__P45_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P45_DSN__MASK                              0x0c000000U
#define WRPRPINS_PDSN_C__P45_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define WRPRPINS_PDSN_C__P45_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define WRPRPINS_PDSN_C__P45_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define WRPRPINS_PDSN_C__P45_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define WRPRPINS_PDSN_C__P45_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p46_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p46_dsn_field p46_dsn_field
 * @brief macros for field p46_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P46_DSN__SHIFT                                      28
#define WRPRPINS_PDSN_C__P46_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P46_DSN__MASK                              0x30000000U
#define WRPRPINS_PDSN_C__P46_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define WRPRPINS_PDSN_C__P46_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define WRPRPINS_PDSN_C__P46_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define WRPRPINS_PDSN_C__P46_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define WRPRPINS_PDSN_C__P46_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p47_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p47_dsn_field p47_dsn_field
 * @brief macros for field p47_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_C__P47_DSN__SHIFT                                      30
#define WRPRPINS_PDSN_C__P47_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_C__P47_DSN__MASK                              0xc0000000U
#define WRPRPINS_PDSN_C__P47_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define WRPRPINS_PDSN_C__P47_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define WRPRPINS_PDSN_C__P47_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define WRPRPINS_PDSN_C__P47_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define WRPRPINS_PDSN_C__P47_DSN__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PDSN_C__TYPE                                          uint32_t
#define WRPRPINS_PDSN_C__READ                                       0xffffffffU
#define WRPRPINS_PDSN_C__WRITE                                      0xffffffffU
#define WRPRPINS_PDSN_C__PRESERVED                                  0x00000000U
#define WRPRPINS_PDSN_C__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PDSN_C_MACRO__ */

/** @} end of pdsn_c */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pdsn_d */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pdsn_d pdsn_d
 * @brief pin drive strength definitions.
 * @{
 */
#ifndef __WRPRPINS_PDSN_D_MACRO__
#define __WRPRPINS_PDSN_D_MACRO__

/* macros for field p48_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p48_dsn_field p48_dsn_field
 * @brief macros for field p48_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_D__P48_DSN__SHIFT                                       0
#define WRPRPINS_PDSN_D__P48_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_D__P48_DSN__MASK                              0x00000003U
#define WRPRPINS_PDSN_D__P48_DSN__READ(src)     ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_D__P48_DSN__WRITE(src)    ((uint32_t)(src) & 0x00000003U)
#define WRPRPINS_PDSN_D__P48_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define WRPRPINS_PDSN_D__P48_DSN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define WRPRPINS_PDSN_D__P48_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p49_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p49_dsn_field p49_dsn_field
 * @brief macros for field p49_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_D__P49_DSN__SHIFT                                       2
#define WRPRPINS_PDSN_D__P49_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_D__P49_DSN__MASK                              0x0000000cU
#define WRPRPINS_PDSN_D__P49_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define WRPRPINS_PDSN_D__P49_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define WRPRPINS_PDSN_D__P49_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define WRPRPINS_PDSN_D__P49_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define WRPRPINS_PDSN_D__P49_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p50_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p50_dsn_field p50_dsn_field
 * @brief macros for field p50_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_D__P50_DSN__SHIFT                                       4
#define WRPRPINS_PDSN_D__P50_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_D__P50_DSN__MASK                              0x00000030U
#define WRPRPINS_PDSN_D__P50_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define WRPRPINS_PDSN_D__P50_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define WRPRPINS_PDSN_D__P50_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define WRPRPINS_PDSN_D__P50_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define WRPRPINS_PDSN_D__P50_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p51_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p51_dsn_field p51_dsn_field
 * @brief macros for field p51_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_D__P51_DSN__SHIFT                                       6
#define WRPRPINS_PDSN_D__P51_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_D__P51_DSN__MASK                              0x000000c0U
#define WRPRPINS_PDSN_D__P51_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define WRPRPINS_PDSN_D__P51_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define WRPRPINS_PDSN_D__P51_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define WRPRPINS_PDSN_D__P51_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define WRPRPINS_PDSN_D__P51_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p52_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p52_dsn_field p52_dsn_field
 * @brief macros for field p52_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_D__P52_DSN__SHIFT                                       8
#define WRPRPINS_PDSN_D__P52_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_D__P52_DSN__MASK                              0x00000300U
#define WRPRPINS_PDSN_D__P52_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define WRPRPINS_PDSN_D__P52_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define WRPRPINS_PDSN_D__P52_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define WRPRPINS_PDSN_D__P52_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define WRPRPINS_PDSN_D__P52_DSN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field p53_dsn */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_p53_dsn_field p53_dsn_field
 * @brief macros for field p53_dsn
 * @details 00 = full strength, 01 = 3/4 strength, 10 = 1/2 strength, 11 = 1/4 (minimum) strength
 * @{
 */
#define WRPRPINS_PDSN_D__P53_DSN__SHIFT                                      10
#define WRPRPINS_PDSN_D__P53_DSN__WIDTH                                       2
#define WRPRPINS_PDSN_D__P53_DSN__MASK                              0x00000c00U
#define WRPRPINS_PDSN_D__P53_DSN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define WRPRPINS_PDSN_D__P53_DSN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define WRPRPINS_PDSN_D__P53_DSN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define WRPRPINS_PDSN_D__P53_DSN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define WRPRPINS_PDSN_D__P53_DSN__RESET_VALUE                       0x00000000U
/** @} */
#define WRPRPINS_PDSN_D__TYPE                                          uint32_t
#define WRPRPINS_PDSN_D__READ                                       0x00000fffU
#define WRPRPINS_PDSN_D__WRITE                                      0x00000fffU
#define WRPRPINS_PDSN_D__PRESERVED                                  0x00000000U
#define WRPRPINS_PDSN_D__RESET_VALUE                                0x00000000U

#endif /* __WRPRPINS_PDSN_D_MACRO__ */

/** @} end of pdsn_d */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pipe_line_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pipe_line_ctrl pipe_line_ctrl
 * @brief Contains register fields associated with pipe_line_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_PIPE_LINE_CTRL_MACRO__
#define __WRPRPINS_PIPE_LINE_CTRL_MACRO__

/* macros for field pipe_line_en */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pipe_line_en_field pipe_line_en_field
 * @brief macros for field pipe_line_en
 * @details add a cycle latency to master expansion port1 ahb.
 * @{
 */
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__SHIFT                          0
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__WIDTH                          1
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__MASK                 0x00000001U
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_PIPE_LINE_CTRL__PIPE_LINE_EN__RESET_VALUE          0x00000000U
/** @} */
#define WRPRPINS_PIPE_LINE_CTRL__TYPE                                  uint32_t
#define WRPRPINS_PIPE_LINE_CTRL__READ                               0x00000001U
#define WRPRPINS_PIPE_LINE_CTRL__WRITE                              0x00000001U
#define WRPRPINS_PIPE_LINE_CTRL__PRESERVED                          0x00000000U
#define WRPRPINS_PIPE_LINE_CTRL__RESET_VALUE                        0x00000000U

#endif /* __WRPRPINS_PIPE_LINE_CTRL_MACRO__ */

/** @} end of pipe_line_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_remap0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_remap0 rram_remap0
 * @brief Contains register fields associated with rram_remap0. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_REMAP0_MACRO__
#define __WRPRPINS_RRAM_REMAP0_MACRO__

/* macros for field blk0 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk0_field blk0_field
 * @brief macros for field blk0
 * @details if rram address is within the first 16kB, replace upper five address bits with the bits in this field [not used because in otp fuse range]
 * @{
 */
#define WRPRPINS_RRAM_REMAP0__BLK0__SHIFT                                     0
#define WRPRPINS_RRAM_REMAP0__BLK0__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP0__BLK0__MASK                            0x0000001fU
#define WRPRPINS_RRAM_REMAP0__BLK0__READ(src)   ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP0__BLK0__WRITE(src)  ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP0__BLK0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define WRPRPINS_RRAM_REMAP0__BLK0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define WRPRPINS_RRAM_REMAP0__BLK0__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field blk1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk1_field blk1_field
 * @brief macros for field blk1
 * @details if rram address is within the second 16kB, replace upper five address bits with the bits in this field [not used because in otp fuse range]
 * @{
 */
#define WRPRPINS_RRAM_REMAP0__BLK1__SHIFT                                     5
#define WRPRPINS_RRAM_REMAP0__BLK1__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP0__BLK1__MASK                            0x000003e0U
#define WRPRPINS_RRAM_REMAP0__BLK1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define WRPRPINS_RRAM_REMAP0__BLK1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP0__BLK1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP0__BLK1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define WRPRPINS_RRAM_REMAP0__BLK1__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field blk2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk2_field blk2_field
 * @brief macros for field blk2
 * @details if rram address is within the third 16kB, replace upper five address bits with the bits in this field [not used because in otp fuse range]
 * @{
 */
#define WRPRPINS_RRAM_REMAP0__BLK2__SHIFT                                    10
#define WRPRPINS_RRAM_REMAP0__BLK2__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP0__BLK2__MASK                            0x00007c00U
#define WRPRPINS_RRAM_REMAP0__BLK2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WRPRPINS_RRAM_REMAP0__BLK2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP0__BLK2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP0__BLK2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WRPRPINS_RRAM_REMAP0__BLK2__RESET_VALUE                     0x00000002U
/** @} */

/* macros for field blk3 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk3_field blk3_field
 * @brief macros for field blk3
 * @details if rram address is within the fourth 16kB, replace upper five address bits with the bits in this field [not used because in otp fuse range]
 * @{
 */
#define WRPRPINS_RRAM_REMAP0__BLK3__SHIFT                                    15
#define WRPRPINS_RRAM_REMAP0__BLK3__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP0__BLK3__MASK                            0x000f8000U
#define WRPRPINS_RRAM_REMAP0__BLK3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define WRPRPINS_RRAM_REMAP0__BLK3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP0__BLK3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP0__BLK3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define WRPRPINS_RRAM_REMAP0__BLK3__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field blk4 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk4_field blk4_field
 * @brief macros for field blk4
 * @details if rram address is within the fifth 16kB, replace upper five address bits with the bits in this field
 * @{
 */
#define WRPRPINS_RRAM_REMAP0__BLK4__SHIFT                                    20
#define WRPRPINS_RRAM_REMAP0__BLK4__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP0__BLK4__MASK                            0x01f00000U
#define WRPRPINS_RRAM_REMAP0__BLK4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define WRPRPINS_RRAM_REMAP0__BLK4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP0__BLK4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP0__BLK4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define WRPRPINS_RRAM_REMAP0__BLK4__RESET_VALUE                     0x00000004U
/** @} */

/* macros for field blk5 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk5_field blk5_field
 * @brief macros for field blk5
 * @details if rram address is within the sixth 16kB, replace upper five address bits with the bits in this field
 * @{
 */
#define WRPRPINS_RRAM_REMAP0__BLK5__SHIFT                                    25
#define WRPRPINS_RRAM_REMAP0__BLK5__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP0__BLK5__MASK                            0x3e000000U
#define WRPRPINS_RRAM_REMAP0__BLK5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define WRPRPINS_RRAM_REMAP0__BLK5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP0__BLK5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP0__BLK5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define WRPRPINS_RRAM_REMAP0__BLK5__RESET_VALUE                     0x00000005U
/** @} */
#define WRPRPINS_RRAM_REMAP0__TYPE                                     uint32_t
#define WRPRPINS_RRAM_REMAP0__READ                                  0x3fffffffU
#define WRPRPINS_RRAM_REMAP0__WRITE                                 0x3fffffffU
#define WRPRPINS_RRAM_REMAP0__PRESERVED                             0x00000000U
#define WRPRPINS_RRAM_REMAP0__RESET_VALUE                           0x0a418820U

#endif /* __WRPRPINS_RRAM_REMAP0_MACRO__ */

/** @} end of rram_remap0 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_remap1 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_remap1 rram_remap1
 * @brief Contains register fields associated with rram_remap1. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_REMAP1_MACRO__
#define __WRPRPINS_RRAM_REMAP1_MACRO__

/* macros for field blk6 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk6_field blk6_field
 * @brief macros for field blk6
 * @{
 */
#define WRPRPINS_RRAM_REMAP1__BLK6__SHIFT                                     0
#define WRPRPINS_RRAM_REMAP1__BLK6__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP1__BLK6__MASK                            0x0000001fU
#define WRPRPINS_RRAM_REMAP1__BLK6__READ(src)   ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP1__BLK6__WRITE(src)  ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP1__BLK6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define WRPRPINS_RRAM_REMAP1__BLK6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define WRPRPINS_RRAM_REMAP1__BLK6__RESET_VALUE                     0x00000006U
/** @} */

/* macros for field blk7 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk7_field blk7_field
 * @brief macros for field blk7
 * @{
 */
#define WRPRPINS_RRAM_REMAP1__BLK7__SHIFT                                     5
#define WRPRPINS_RRAM_REMAP1__BLK7__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP1__BLK7__MASK                            0x000003e0U
#define WRPRPINS_RRAM_REMAP1__BLK7__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define WRPRPINS_RRAM_REMAP1__BLK7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP1__BLK7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP1__BLK7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define WRPRPINS_RRAM_REMAP1__BLK7__RESET_VALUE                     0x00000007U
/** @} */

/* macros for field blk8 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk8_field blk8_field
 * @brief macros for field blk8
 * @{
 */
#define WRPRPINS_RRAM_REMAP1__BLK8__SHIFT                                    10
#define WRPRPINS_RRAM_REMAP1__BLK8__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP1__BLK8__MASK                            0x00007c00U
#define WRPRPINS_RRAM_REMAP1__BLK8__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WRPRPINS_RRAM_REMAP1__BLK8__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP1__BLK8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP1__BLK8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WRPRPINS_RRAM_REMAP1__BLK8__RESET_VALUE                     0x00000008U
/** @} */

/* macros for field blk9 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk9_field blk9_field
 * @brief macros for field blk9
 * @{
 */
#define WRPRPINS_RRAM_REMAP1__BLK9__SHIFT                                    15
#define WRPRPINS_RRAM_REMAP1__BLK9__WIDTH                                     5
#define WRPRPINS_RRAM_REMAP1__BLK9__MASK                            0x000f8000U
#define WRPRPINS_RRAM_REMAP1__BLK9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define WRPRPINS_RRAM_REMAP1__BLK9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP1__BLK9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP1__BLK9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define WRPRPINS_RRAM_REMAP1__BLK9__RESET_VALUE                     0x00000009U
/** @} */

/* macros for field blk10 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk10_field blk10_field
 * @brief macros for field blk10
 * @{
 */
#define WRPRPINS_RRAM_REMAP1__BLK10__SHIFT                                   20
#define WRPRPINS_RRAM_REMAP1__BLK10__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP1__BLK10__MASK                           0x01f00000U
#define WRPRPINS_RRAM_REMAP1__BLK10__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define WRPRPINS_RRAM_REMAP1__BLK10__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP1__BLK10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP1__BLK10__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define WRPRPINS_RRAM_REMAP1__BLK10__RESET_VALUE                    0x0000000aU
/** @} */

/* macros for field blk11 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk11_field blk11_field
 * @brief macros for field blk11
 * @{
 */
#define WRPRPINS_RRAM_REMAP1__BLK11__SHIFT                                   25
#define WRPRPINS_RRAM_REMAP1__BLK11__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP1__BLK11__MASK                           0x3e000000U
#define WRPRPINS_RRAM_REMAP1__BLK11__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define WRPRPINS_RRAM_REMAP1__BLK11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP1__BLK11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP1__BLK11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define WRPRPINS_RRAM_REMAP1__BLK11__RESET_VALUE                    0x0000000bU
/** @} */
#define WRPRPINS_RRAM_REMAP1__TYPE                                     uint32_t
#define WRPRPINS_RRAM_REMAP1__READ                                  0x3fffffffU
#define WRPRPINS_RRAM_REMAP1__WRITE                                 0x3fffffffU
#define WRPRPINS_RRAM_REMAP1__PRESERVED                             0x00000000U
#define WRPRPINS_RRAM_REMAP1__RESET_VALUE                           0x16a4a0e6U

#endif /* __WRPRPINS_RRAM_REMAP1_MACRO__ */

/** @} end of rram_remap1 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_remap2 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_remap2 rram_remap2
 * @brief Contains register fields associated with rram_remap2. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_REMAP2_MACRO__
#define __WRPRPINS_RRAM_REMAP2_MACRO__

/* macros for field blk12 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk12_field blk12_field
 * @brief macros for field blk12
 * @{
 */
#define WRPRPINS_RRAM_REMAP2__BLK12__SHIFT                                    0
#define WRPRPINS_RRAM_REMAP2__BLK12__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP2__BLK12__MASK                           0x0000001fU
#define WRPRPINS_RRAM_REMAP2__BLK12__READ(src)  ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP2__BLK12__WRITE(src) ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP2__BLK12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define WRPRPINS_RRAM_REMAP2__BLK12__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define WRPRPINS_RRAM_REMAP2__BLK12__RESET_VALUE                    0x0000000cU
/** @} */

/* macros for field blk13 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk13_field blk13_field
 * @brief macros for field blk13
 * @{
 */
#define WRPRPINS_RRAM_REMAP2__BLK13__SHIFT                                    5
#define WRPRPINS_RRAM_REMAP2__BLK13__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP2__BLK13__MASK                           0x000003e0U
#define WRPRPINS_RRAM_REMAP2__BLK13__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define WRPRPINS_RRAM_REMAP2__BLK13__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP2__BLK13__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP2__BLK13__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define WRPRPINS_RRAM_REMAP2__BLK13__RESET_VALUE                    0x0000000dU
/** @} */

/* macros for field blk14 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk14_field blk14_field
 * @brief macros for field blk14
 * @{
 */
#define WRPRPINS_RRAM_REMAP2__BLK14__SHIFT                                   10
#define WRPRPINS_RRAM_REMAP2__BLK14__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP2__BLK14__MASK                           0x00007c00U
#define WRPRPINS_RRAM_REMAP2__BLK14__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WRPRPINS_RRAM_REMAP2__BLK14__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP2__BLK14__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP2__BLK14__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WRPRPINS_RRAM_REMAP2__BLK14__RESET_VALUE                    0x0000000eU
/** @} */

/* macros for field blk15 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk15_field blk15_field
 * @brief macros for field blk15
 * @{
 */
#define WRPRPINS_RRAM_REMAP2__BLK15__SHIFT                                   15
#define WRPRPINS_RRAM_REMAP2__BLK15__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP2__BLK15__MASK                           0x000f8000U
#define WRPRPINS_RRAM_REMAP2__BLK15__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define WRPRPINS_RRAM_REMAP2__BLK15__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP2__BLK15__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP2__BLK15__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define WRPRPINS_RRAM_REMAP2__BLK15__RESET_VALUE                    0x0000000fU
/** @} */

/* macros for field blk16 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk16_field blk16_field
 * @brief macros for field blk16
 * @{
 */
#define WRPRPINS_RRAM_REMAP2__BLK16__SHIFT                                   20
#define WRPRPINS_RRAM_REMAP2__BLK16__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP2__BLK16__MASK                           0x01f00000U
#define WRPRPINS_RRAM_REMAP2__BLK16__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define WRPRPINS_RRAM_REMAP2__BLK16__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP2__BLK16__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP2__BLK16__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define WRPRPINS_RRAM_REMAP2__BLK16__RESET_VALUE                    0x00000010U
/** @} */

/* macros for field blk17 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk17_field blk17_field
 * @brief macros for field blk17
 * @{
 */
#define WRPRPINS_RRAM_REMAP2__BLK17__SHIFT                                   25
#define WRPRPINS_RRAM_REMAP2__BLK17__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP2__BLK17__MASK                           0x3e000000U
#define WRPRPINS_RRAM_REMAP2__BLK17__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define WRPRPINS_RRAM_REMAP2__BLK17__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP2__BLK17__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP2__BLK17__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define WRPRPINS_RRAM_REMAP2__BLK17__RESET_VALUE                    0x00000011U
/** @} */
#define WRPRPINS_RRAM_REMAP2__TYPE                                     uint32_t
#define WRPRPINS_RRAM_REMAP2__READ                                  0x3fffffffU
#define WRPRPINS_RRAM_REMAP2__WRITE                                 0x3fffffffU
#define WRPRPINS_RRAM_REMAP2__PRESERVED                             0x00000000U
#define WRPRPINS_RRAM_REMAP2__RESET_VALUE                           0x2307b9acU

#endif /* __WRPRPINS_RRAM_REMAP2_MACRO__ */

/** @} end of rram_remap2 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_remap3 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_remap3 rram_remap3
 * @brief Contains register fields associated with rram_remap3. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_REMAP3_MACRO__
#define __WRPRPINS_RRAM_REMAP3_MACRO__

/* macros for field blk18 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk18_field blk18_field
 * @brief macros for field blk18
 * @{
 */
#define WRPRPINS_RRAM_REMAP3__BLK18__SHIFT                                    0
#define WRPRPINS_RRAM_REMAP3__BLK18__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP3__BLK18__MASK                           0x0000001fU
#define WRPRPINS_RRAM_REMAP3__BLK18__READ(src)  ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP3__BLK18__WRITE(src) ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP3__BLK18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define WRPRPINS_RRAM_REMAP3__BLK18__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define WRPRPINS_RRAM_REMAP3__BLK18__RESET_VALUE                    0x00000012U
/** @} */

/* macros for field blk19 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk19_field blk19_field
 * @brief macros for field blk19
 * @{
 */
#define WRPRPINS_RRAM_REMAP3__BLK19__SHIFT                                    5
#define WRPRPINS_RRAM_REMAP3__BLK19__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP3__BLK19__MASK                           0x000003e0U
#define WRPRPINS_RRAM_REMAP3__BLK19__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define WRPRPINS_RRAM_REMAP3__BLK19__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP3__BLK19__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP3__BLK19__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define WRPRPINS_RRAM_REMAP3__BLK19__RESET_VALUE                    0x00000013U
/** @} */

/* macros for field blk20 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk20_field blk20_field
 * @brief macros for field blk20
 * @{
 */
#define WRPRPINS_RRAM_REMAP3__BLK20__SHIFT                                   10
#define WRPRPINS_RRAM_REMAP3__BLK20__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP3__BLK20__MASK                           0x00007c00U
#define WRPRPINS_RRAM_REMAP3__BLK20__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WRPRPINS_RRAM_REMAP3__BLK20__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP3__BLK20__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP3__BLK20__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WRPRPINS_RRAM_REMAP3__BLK20__RESET_VALUE                    0x00000014U
/** @} */

/* macros for field blk21 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk21_field blk21_field
 * @brief macros for field blk21
 * @{
 */
#define WRPRPINS_RRAM_REMAP3__BLK21__SHIFT                                   15
#define WRPRPINS_RRAM_REMAP3__BLK21__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP3__BLK21__MASK                           0x000f8000U
#define WRPRPINS_RRAM_REMAP3__BLK21__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define WRPRPINS_RRAM_REMAP3__BLK21__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP3__BLK21__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP3__BLK21__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define WRPRPINS_RRAM_REMAP3__BLK21__RESET_VALUE                    0x00000015U
/** @} */

/* macros for field blk22 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk22_field blk22_field
 * @brief macros for field blk22
 * @{
 */
#define WRPRPINS_RRAM_REMAP3__BLK22__SHIFT                                   20
#define WRPRPINS_RRAM_REMAP3__BLK22__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP3__BLK22__MASK                           0x01f00000U
#define WRPRPINS_RRAM_REMAP3__BLK22__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define WRPRPINS_RRAM_REMAP3__BLK22__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP3__BLK22__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP3__BLK22__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define WRPRPINS_RRAM_REMAP3__BLK22__RESET_VALUE                    0x00000016U
/** @} */

/* macros for field blk23 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk23_field blk23_field
 * @brief macros for field blk23
 * @{
 */
#define WRPRPINS_RRAM_REMAP3__BLK23__SHIFT                                   25
#define WRPRPINS_RRAM_REMAP3__BLK23__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP3__BLK23__MASK                           0x3e000000U
#define WRPRPINS_RRAM_REMAP3__BLK23__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define WRPRPINS_RRAM_REMAP3__BLK23__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP3__BLK23__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP3__BLK23__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define WRPRPINS_RRAM_REMAP3__BLK23__RESET_VALUE                    0x00000017U
/** @} */
#define WRPRPINS_RRAM_REMAP3__TYPE                                     uint32_t
#define WRPRPINS_RRAM_REMAP3__READ                                  0x3fffffffU
#define WRPRPINS_RRAM_REMAP3__WRITE                                 0x3fffffffU
#define WRPRPINS_RRAM_REMAP3__PRESERVED                             0x00000000U
#define WRPRPINS_RRAM_REMAP3__RESET_VALUE                           0x2f6ad272U

#endif /* __WRPRPINS_RRAM_REMAP3_MACRO__ */

/** @} end of rram_remap3 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_remap4 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_remap4 rram_remap4
 * @brief Contains register fields associated with rram_remap4. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_REMAP4_MACRO__
#define __WRPRPINS_RRAM_REMAP4_MACRO__

/* macros for field blk24 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk24_field blk24_field
 * @brief macros for field blk24
 * @{
 */
#define WRPRPINS_RRAM_REMAP4__BLK24__SHIFT                                    0
#define WRPRPINS_RRAM_REMAP4__BLK24__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP4__BLK24__MASK                           0x0000001fU
#define WRPRPINS_RRAM_REMAP4__BLK24__READ(src)  ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP4__BLK24__WRITE(src) ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP4__BLK24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define WRPRPINS_RRAM_REMAP4__BLK24__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define WRPRPINS_RRAM_REMAP4__BLK24__RESET_VALUE                    0x00000018U
/** @} */

/* macros for field blk25 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk25_field blk25_field
 * @brief macros for field blk25
 * @{
 */
#define WRPRPINS_RRAM_REMAP4__BLK25__SHIFT                                    5
#define WRPRPINS_RRAM_REMAP4__BLK25__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP4__BLK25__MASK                           0x000003e0U
#define WRPRPINS_RRAM_REMAP4__BLK25__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define WRPRPINS_RRAM_REMAP4__BLK25__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP4__BLK25__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP4__BLK25__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define WRPRPINS_RRAM_REMAP4__BLK25__RESET_VALUE                    0x00000019U
/** @} */

/* macros for field blk26 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk26_field blk26_field
 * @brief macros for field blk26
 * @{
 */
#define WRPRPINS_RRAM_REMAP4__BLK26__SHIFT                                   10
#define WRPRPINS_RRAM_REMAP4__BLK26__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP4__BLK26__MASK                           0x00007c00U
#define WRPRPINS_RRAM_REMAP4__BLK26__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define WRPRPINS_RRAM_REMAP4__BLK26__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP4__BLK26__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define WRPRPINS_RRAM_REMAP4__BLK26__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define WRPRPINS_RRAM_REMAP4__BLK26__RESET_VALUE                    0x0000001aU
/** @} */

/* macros for field blk27 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk27_field blk27_field
 * @brief macros for field blk27
 * @{
 */
#define WRPRPINS_RRAM_REMAP4__BLK27__SHIFT                                   15
#define WRPRPINS_RRAM_REMAP4__BLK27__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP4__BLK27__MASK                           0x000f8000U
#define WRPRPINS_RRAM_REMAP4__BLK27__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define WRPRPINS_RRAM_REMAP4__BLK27__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP4__BLK27__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define WRPRPINS_RRAM_REMAP4__BLK27__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define WRPRPINS_RRAM_REMAP4__BLK27__RESET_VALUE                    0x0000001bU
/** @} */

/* macros for field blk28 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk28_field blk28_field
 * @brief macros for field blk28
 * @{
 */
#define WRPRPINS_RRAM_REMAP4__BLK28__SHIFT                                   20
#define WRPRPINS_RRAM_REMAP4__BLK28__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP4__BLK28__MASK                           0x01f00000U
#define WRPRPINS_RRAM_REMAP4__BLK28__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define WRPRPINS_RRAM_REMAP4__BLK28__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP4__BLK28__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define WRPRPINS_RRAM_REMAP4__BLK28__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define WRPRPINS_RRAM_REMAP4__BLK28__RESET_VALUE                    0x0000001cU
/** @} */

/* macros for field blk29 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk29_field blk29_field
 * @brief macros for field blk29
 * @{
 */
#define WRPRPINS_RRAM_REMAP4__BLK29__SHIFT                                   25
#define WRPRPINS_RRAM_REMAP4__BLK29__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP4__BLK29__MASK                           0x3e000000U
#define WRPRPINS_RRAM_REMAP4__BLK29__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define WRPRPINS_RRAM_REMAP4__BLK29__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP4__BLK29__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define WRPRPINS_RRAM_REMAP4__BLK29__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define WRPRPINS_RRAM_REMAP4__BLK29__RESET_VALUE                    0x0000001dU
/** @} */
#define WRPRPINS_RRAM_REMAP4__TYPE                                     uint32_t
#define WRPRPINS_RRAM_REMAP4__READ                                  0x3fffffffU
#define WRPRPINS_RRAM_REMAP4__WRITE                                 0x3fffffffU
#define WRPRPINS_RRAM_REMAP4__PRESERVED                             0x00000000U
#define WRPRPINS_RRAM_REMAP4__RESET_VALUE                           0x3bcdeb38U

#endif /* __WRPRPINS_RRAM_REMAP4_MACRO__ */

/** @} end of rram_remap4 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rram_remap5 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rram_remap5 rram_remap5
 * @brief A write to this register will sticky lock registers rram_remap[0,1,2,3,4,5]. definitions.
 * @{
 */
#ifndef __WRPRPINS_RRAM_REMAP5_MACRO__
#define __WRPRPINS_RRAM_REMAP5_MACRO__

/* macros for field blk30 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk30_field blk30_field
 * @brief macros for field blk30
 * @details if rram address is within the 31st 16kB, replace upper five address bits with the bits in this field
 * @{
 */
#define WRPRPINS_RRAM_REMAP5__BLK30__SHIFT                                    0
#define WRPRPINS_RRAM_REMAP5__BLK30__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP5__BLK30__MASK                           0x0000001fU
#define WRPRPINS_RRAM_REMAP5__BLK30__READ(src)  ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP5__BLK30__WRITE(src) ((uint32_t)(src) & 0x0000001fU)
#define WRPRPINS_RRAM_REMAP5__BLK30__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define WRPRPINS_RRAM_REMAP5__BLK30__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define WRPRPINS_RRAM_REMAP5__BLK30__RESET_VALUE                    0x0000001eU
/** @} */

/* macros for field blk31 */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_blk31_field blk31_field
 * @brief macros for field blk31
 * @details if rram address is within the 32nd 16kB, replace upper five address bits with the bits in this field [not used because in otp fuse range]
 * @{
 */
#define WRPRPINS_RRAM_REMAP5__BLK31__SHIFT                                    5
#define WRPRPINS_RRAM_REMAP5__BLK31__WIDTH                                    5
#define WRPRPINS_RRAM_REMAP5__BLK31__MASK                           0x000003e0U
#define WRPRPINS_RRAM_REMAP5__BLK31__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define WRPRPINS_RRAM_REMAP5__BLK31__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP5__BLK31__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define WRPRPINS_RRAM_REMAP5__BLK31__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define WRPRPINS_RRAM_REMAP5__BLK31__RESET_VALUE                    0x0000001fU
/** @} */
#define WRPRPINS_RRAM_REMAP5__TYPE                                     uint32_t
#define WRPRPINS_RRAM_REMAP5__READ                                  0x000003ffU
#define WRPRPINS_RRAM_REMAP5__WRITE                                 0x000003ffU
#define WRPRPINS_RRAM_REMAP5__PRESERVED                             0x00000000U
#define WRPRPINS_RRAM_REMAP5__RESET_VALUE                           0x000003feU

#endif /* __WRPRPINS_RRAM_REMAP5_MACRO__ */

/** @} end of rram_remap5 */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_soc_misc_ctrl */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_soc_misc_ctrl soc_misc_ctrl
 * @brief Contains register fields associated with soc_misc_ctrl. definitions.
 * @{
 */
#ifndef __WRPRPINS_SOC_MISC_CTRL_MACRO__
#define __WRPRPINS_SOC_MISC_CTRL_MACRO__

/* macros for field tclk_sel */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_tclk_sel_field tclk_sel_field
 * @brief macros for field tclk_sel
 * @details 0=clk16x runs arm timers, 1=bp_clk (backplane clock) runs arm timers
 * @{
 */
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__SHIFT                               0
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__WIDTH                               1
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__MASK                      0x00000001U
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define WRPRPINS_SOC_MISC_CTRL__TCLK_SEL__RESET_VALUE               0x00000000U
/** @} */

/* macros for field sha_reset */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_sha_reset_field sha_reset_field
 * @brief macros for field sha_reset
 * @details 1=force sha/hmac into reset
 * @{
 */
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__SHIFT                              1
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__WIDTH                              1
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__MASK                     0x00000002U
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define WRPRPINS_SOC_MISC_CTRL__SHA_RESET__RESET_VALUE              0x00000000U
/** @} */

/* macros for field pl_dbg_en */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pl_dbg_en_field pl_dbg_en_field
 * @brief macros for field pl_dbg_en
 * @details 1=force sha/hmac into reset
 * @{
 */
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__SHIFT                              2
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__WIDTH                              1
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__MASK                     0x00000004U
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define WRPRPINS_SOC_MISC_CTRL__PL_DBG_EN__RESET_VALUE              0x00000000U
/** @} */
#define WRPRPINS_SOC_MISC_CTRL__TYPE                                   uint32_t
#define WRPRPINS_SOC_MISC_CTRL__READ                                0x00000007U
#define WRPRPINS_SOC_MISC_CTRL__WRITE                               0x00000007U
#define WRPRPINS_SOC_MISC_CTRL__PRESERVED                           0x00000000U
#define WRPRPINS_SOC_MISC_CTRL__RESET_VALUE                         0x00000000U

#endif /* __WRPRPINS_SOC_MISC_CTRL_MACRO__ */

/** @} end of soc_misc_ctrl */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_pipe_line_en_stat */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pipe_line_en_stat pipe_line_en_stat
 * @brief Contains register fields associated with pipe_line_en_stat. definitions.
 * @{
 */
#ifndef __WRPRPINS_PIPE_LINE_EN_STAT_MACRO__
#define __WRPRPINS_PIPE_LINE_EN_STAT_MACRO__

/* macros for field pipe_line_en_sysram */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_pipe_line_en_sysram_field pipe_line_en_sysram_field
 * @brief macros for field pipe_line_en_sysram
 * @details pipe_line_en status of each sysram bank. Each actual pipe_line_en state does not go to 0 until there is a cycle break in sysram access.
 * @{
 */
#define WRPRPINS_PIPE_LINE_EN_STAT__PIPE_LINE_EN_SYSRAM__SHIFT                0
#define WRPRPINS_PIPE_LINE_EN_STAT__PIPE_LINE_EN_SYSRAM__WIDTH                4
#define WRPRPINS_PIPE_LINE_EN_STAT__PIPE_LINE_EN_SYSRAM__MASK       0x0000000fU
#define WRPRPINS_PIPE_LINE_EN_STAT__PIPE_LINE_EN_SYSRAM__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define WRPRPINS_PIPE_LINE_EN_STAT__PIPE_LINE_EN_SYSRAM__RESET_VALUE \
                    0x00000000U
/** @} */
#define WRPRPINS_PIPE_LINE_EN_STAT__TYPE                               uint32_t
#define WRPRPINS_PIPE_LINE_EN_STAT__READ                            0x0000000fU
#define WRPRPINS_PIPE_LINE_EN_STAT__PRESERVED                       0x00000000U
#define WRPRPINS_PIPE_LINE_EN_STAT__RESET_VALUE                     0x00000000U

#endif /* __WRPRPINS_PIPE_LINE_EN_STAT_MACRO__ */

/** @} end of pipe_line_en_stat */

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
 * @details t
 * @{
 */
#define WRPRPINS_CHIPID1__CHAR3__SHIFT                                        0
#define WRPRPINS_CHIPID1__CHAR3__WIDTH                                        8
#define WRPRPINS_CHIPID1__CHAR3__MASK                               0x000000ffU
#define WRPRPINS_CHIPID1__CHAR3__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define WRPRPINS_CHIPID1__CHAR3__RESET_VALUE                        0x00000074U
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
 * @details e
 * @{
 */
#define WRPRPINS_CHIPID1__CHAR1__SHIFT                                       16
#define WRPRPINS_CHIPID1__CHAR1__WIDTH                                        8
#define WRPRPINS_CHIPID1__CHAR1__MASK                               0x00ff0000U
#define WRPRPINS_CHIPID1__CHAR1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define WRPRPINS_CHIPID1__CHAR1__RESET_VALUE                        0x00000065U
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
#define WRPRPINS_CHIPID1__RESET_VALUE                               0x50657274U

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
 * @details h
 * @{
 */
#define WRPRPINS_CHIPID2__CHAR4__SHIFT                                       24
#define WRPRPINS_CHIPID2__CHAR4__WIDTH                                        8
#define WRPRPINS_CHIPID2__CHAR4__MASK                               0xff000000U
#define WRPRPINS_CHIPID2__CHAR4__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define WRPRPINS_CHIPID2__CHAR4__RESET_VALUE                        0x00000068U
/** @} */
#define WRPRPINS_CHIPID2__TYPE                                         uint32_t
#define WRPRPINS_CHIPID2__READ                                      0xffffffffU
#define WRPRPINS_CHIPID2__PRESERVED                                 0x00000000U
#define WRPRPINS_CHIPID2__RESET_VALUE                               0x68000000U

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
 * @details 2
 * @{
 */
#define WRPRPINS_CHIPREV__MAJOR__SHIFT                                        8
#define WRPRPINS_CHIPREV__MAJOR__WIDTH                                        8
#define WRPRPINS_CHIPREV__MAJOR__MASK                               0x0000ff00U
#define WRPRPINS_CHIPREV__MAJOR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define WRPRPINS_CHIPREV__MAJOR__RESET_VALUE                        0x00000002U
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
#define WRPRPINS_CHIPREV__RESET_VALUE                               0x00000200U

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

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rev_hash */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __WRPRPINS_REV_HASH_MACRO__
#define __WRPRPINS_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define WRPRPINS_REV_HASH__ID__SHIFT                                          0
#define WRPRPINS_REV_HASH__ID__WIDTH                                         32
#define WRPRPINS_REV_HASH__ID__MASK                                 0xffffffffU
#define WRPRPINS_REV_HASH__ID__READ(src)        ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_REV_HASH__ID__RESET_VALUE                          0x014e5517U
/** @} */
#define WRPRPINS_REV_HASH__TYPE                                        uint32_t
#define WRPRPINS_REV_HASH__READ                                     0xffffffffU
#define WRPRPINS_REV_HASH__PRESERVED                                0x00000000U
#define WRPRPINS_REV_HASH__RESET_VALUE                              0x014e5517U

#endif /* __WRPRPINS_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::WRPRPINS_rev_key */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __WRPRPINS_REV_KEY_MACRO__
#define __WRPRPINS_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_wrpr_pins_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define WRPRPINS_REV_KEY__ID__SHIFT                                           0
#define WRPRPINS_REV_KEY__ID__WIDTH                                          32
#define WRPRPINS_REV_KEY__ID__MASK                                  0xffffffffU
#define WRPRPINS_REV_KEY__ID__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define WRPRPINS_REV_KEY__ID__RESET_VALUE                           0x52455620U
/** @} */
#define WRPRPINS_REV_KEY__TYPE                                         uint32_t
#define WRPRPINS_REV_KEY__READ                                      0xffffffffU
#define WRPRPINS_REV_KEY__PRESERVED                                 0x00000000U
#define WRPRPINS_REV_KEY__RESET_VALUE                               0x52455620U

#endif /* __WRPRPINS_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_WRPR_PINS_REGS_CORE */
#endif /* __REG_AT_APB_WRPR_PINS_REGS_CORE_H__ */
