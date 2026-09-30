/*                                                                           */
/* File:       at_ahb_prrf16_regs_core_macro.h                               */
/*                                                                           */
/*                                                              */
/*                                                                           */
/* Blueprint:   3.7.5-atm (reduced-path-a)                                   */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/* Copyright (C) 2026 Atmosic Technologies.  All rights reserved             */
/*                                                                           */


#ifndef __REG_AT_AHB_PRRF16_REGS_CORE_H__
#define __REG_AT_AHB_PRRF16_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_AHB_PRRF16_REGS_CORE at_ahb_prrf16_regs_core
 * @ingroup AT_REG
 * @brief at_ahb_prrf16_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag0 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag0 patch_tag0
 * @brief Contains register fields associated with patch_tag0. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG0_MACRO__
#define __AT_PRRF_PATCH_TAG0_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG0__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG0__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG0__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG0__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG0__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG0__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG0__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG0__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG0__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG0__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG0__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG0__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG0__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG0__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG0__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG0__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG0__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG0__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG0__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG0__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG0__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG0__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG0__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG0__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG0__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG0__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG0__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG0__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG0__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG0__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG0__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG0__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG0__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG0__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG0__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG0__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG0__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG0__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG0__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG0__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG0__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG0_MACRO__ */

/** @} end of patch_tag0 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag1 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag1 patch_tag1
 * @brief Contains register fields associated with patch_tag1. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG1_MACRO__
#define __AT_PRRF_PATCH_TAG1_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG1__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG1__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG1__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG1__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG1__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG1__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG1__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG1__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG1__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG1__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG1__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG1__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG1__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG1__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG1__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG1__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG1__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG1__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG1__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG1__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG1__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG1__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG1__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG1__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG1__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG1__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG1__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG1__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG1__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG1__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG1__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG1__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG1__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG1__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG1__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG1__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG1__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG1__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG1__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG1__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG1__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG1_MACRO__ */

/** @} end of patch_tag1 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag2 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag2 patch_tag2
 * @brief Contains register fields associated with patch_tag2. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG2_MACRO__
#define __AT_PRRF_PATCH_TAG2_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG2__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG2__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG2__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG2__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG2__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG2__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG2__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG2__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG2__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG2__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG2__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG2__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG2__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG2__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG2__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG2__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG2__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG2__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG2__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG2__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG2__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG2__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG2__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG2__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG2__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG2__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG2__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG2__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG2__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG2__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG2__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG2__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG2__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG2__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG2__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG2__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG2__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG2__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG2__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG2__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG2__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG2_MACRO__ */

/** @} end of patch_tag2 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag3 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag3 patch_tag3
 * @brief Contains register fields associated with patch_tag3. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG3_MACRO__
#define __AT_PRRF_PATCH_TAG3_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG3__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG3__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG3__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG3__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG3__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG3__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG3__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG3__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG3__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG3__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG3__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG3__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG3__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG3__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG3__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG3__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG3__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG3__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG3__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG3__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG3__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG3__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG3__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG3__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG3__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG3__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG3__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG3__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG3__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG3__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG3__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG3__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG3__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG3__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG3__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG3__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG3__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG3__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG3__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG3__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG3__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG3_MACRO__ */

/** @} end of patch_tag3 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag4 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag4 patch_tag4
 * @brief Contains register fields associated with patch_tag4. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG4_MACRO__
#define __AT_PRRF_PATCH_TAG4_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG4__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG4__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG4__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG4__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG4__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG4__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG4__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG4__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG4__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG4__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG4__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG4__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG4__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG4__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG4__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG4__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG4__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG4__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG4__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG4__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG4__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG4__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG4__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG4__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG4__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG4__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG4__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG4__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG4__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG4__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG4__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG4__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG4__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG4__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG4__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG4__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG4__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG4__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG4__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG4__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG4__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG4_MACRO__ */

/** @} end of patch_tag4 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag5 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag5 patch_tag5
 * @brief Contains register fields associated with patch_tag5. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG5_MACRO__
#define __AT_PRRF_PATCH_TAG5_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG5__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG5__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG5__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG5__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG5__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG5__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG5__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG5__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG5__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG5__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG5__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG5__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG5__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG5__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG5__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG5__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG5__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG5__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG5__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG5__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG5__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG5__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG5__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG5__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG5__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG5__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG5__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG5__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG5__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG5__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG5__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG5__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG5__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG5__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG5__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG5__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG5__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG5__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG5__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG5__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG5__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG5_MACRO__ */

/** @} end of patch_tag5 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag6 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag6 patch_tag6
 * @brief Contains register fields associated with patch_tag6. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG6_MACRO__
#define __AT_PRRF_PATCH_TAG6_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG6__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG6__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG6__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG6__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG6__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG6__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG6__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG6__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG6__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG6__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG6__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG6__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG6__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG6__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG6__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG6__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG6__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG6__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG6__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG6__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG6__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG6__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG6__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG6__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG6__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG6__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG6__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG6__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG6__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG6__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG6__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG6__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG6__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG6__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG6__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG6__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG6__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG6__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG6__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG6__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG6__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG6_MACRO__ */

/** @} end of patch_tag6 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag7 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag7 patch_tag7
 * @brief Contains register fields associated with patch_tag7. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG7_MACRO__
#define __AT_PRRF_PATCH_TAG7_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG7__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG7__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG7__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG7__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG7__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG7__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG7__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG7__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG7__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG7__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG7__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG7__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG7__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG7__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG7__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG7__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG7__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG7__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG7__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG7__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG7__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG7__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG7__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG7__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG7__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG7__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG7__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG7__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG7__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG7__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG7__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG7__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG7__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG7__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG7__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG7__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG7__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG7__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG7__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG7__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG7__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG7_MACRO__ */

/** @} end of patch_tag7 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag8 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag8 patch_tag8
 * @brief Contains register fields associated with patch_tag8. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG8_MACRO__
#define __AT_PRRF_PATCH_TAG8_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG8__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG8__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG8__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG8__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG8__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG8__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG8__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG8__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG8__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG8__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG8__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG8__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG8__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG8__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG8__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG8__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG8__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG8__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG8__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG8__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG8__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG8__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG8__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG8__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG8__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG8__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG8__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG8__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG8__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG8__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG8__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG8__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG8__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG8__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG8__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG8__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG8__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG8__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG8__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG8__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG8__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG8_MACRO__ */

/** @} end of patch_tag8 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag9 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag9 patch_tag9
 * @brief Contains register fields associated with patch_tag9. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG9_MACRO__
#define __AT_PRRF_PATCH_TAG9_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG9__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG9__ADDR__WIDTH                                      16
#define AT_PRRF_PATCH_TAG9__ADDR__MASK                              0x0000ffffU
#define AT_PRRF_PATCH_TAG9__ADDR__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG9__ADDR__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG9__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG9__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG9__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG9__INST__SHIFT                                      20
#define AT_PRRF_PATCH_TAG9__INST__WIDTH                                       4
#define AT_PRRF_PATCH_TAG9__INST__MASK                              0x00f00000U
#define AT_PRRF_PATCH_TAG9__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG9__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG9__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG9__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG9__INST__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG9__MODE__SHIFT                                      30
#define AT_PRRF_PATCH_TAG9__MODE__WIDTH                                       1
#define AT_PRRF_PATCH_TAG9__MODE__MASK                              0x40000000U
#define AT_PRRF_PATCH_TAG9__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG9__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG9__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG9__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG9__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG9__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG9__MODE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG9__VALID__SHIFT                                     31
#define AT_PRRF_PATCH_TAG9__VALID__WIDTH                                      1
#define AT_PRRF_PATCH_TAG9__VALID__MASK                             0x80000000U
#define AT_PRRF_PATCH_TAG9__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG9__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG9__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG9__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG9__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG9__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG9__VALID__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG9__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG9__READ                                    0xc0f0ffffU
#define AT_PRRF_PATCH_TAG9__WRITE                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG9__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG9__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG9_MACRO__ */

/** @} end of patch_tag9 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag10 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag10 patch_tag10
 * @brief Contains register fields associated with patch_tag10. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG10_MACRO__
#define __AT_PRRF_PATCH_TAG10_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG10__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG10__ADDR__WIDTH                                     16
#define AT_PRRF_PATCH_TAG10__ADDR__MASK                             0x0000ffffU
#define AT_PRRF_PATCH_TAG10__ADDR__READ(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG10__ADDR__WRITE(src)   ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG10__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG10__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG10__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG10__INST__SHIFT                                     20
#define AT_PRRF_PATCH_TAG10__INST__WIDTH                                      4
#define AT_PRRF_PATCH_TAG10__INST__MASK                             0x00f00000U
#define AT_PRRF_PATCH_TAG10__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG10__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG10__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG10__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG10__INST__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG10__MODE__SHIFT                                     30
#define AT_PRRF_PATCH_TAG10__MODE__WIDTH                                      1
#define AT_PRRF_PATCH_TAG10__MODE__MASK                             0x40000000U
#define AT_PRRF_PATCH_TAG10__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG10__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG10__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG10__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG10__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG10__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG10__MODE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG10__VALID__SHIFT                                    31
#define AT_PRRF_PATCH_TAG10__VALID__WIDTH                                     1
#define AT_PRRF_PATCH_TAG10__VALID__MASK                            0x80000000U
#define AT_PRRF_PATCH_TAG10__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG10__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG10__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG10__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG10__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG10__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG10__VALID__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG10__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG10__READ                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG10__WRITE                                  0xc0f0ffffU
#define AT_PRRF_PATCH_TAG10__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG10__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG10_MACRO__ */

/** @} end of patch_tag10 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag11 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag11 patch_tag11
 * @brief Contains register fields associated with patch_tag11. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG11_MACRO__
#define __AT_PRRF_PATCH_TAG11_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG11__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG11__ADDR__WIDTH                                     16
#define AT_PRRF_PATCH_TAG11__ADDR__MASK                             0x0000ffffU
#define AT_PRRF_PATCH_TAG11__ADDR__READ(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG11__ADDR__WRITE(src)   ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG11__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG11__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG11__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG11__INST__SHIFT                                     20
#define AT_PRRF_PATCH_TAG11__INST__WIDTH                                      4
#define AT_PRRF_PATCH_TAG11__INST__MASK                             0x00f00000U
#define AT_PRRF_PATCH_TAG11__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG11__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG11__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG11__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG11__INST__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG11__MODE__SHIFT                                     30
#define AT_PRRF_PATCH_TAG11__MODE__WIDTH                                      1
#define AT_PRRF_PATCH_TAG11__MODE__MASK                             0x40000000U
#define AT_PRRF_PATCH_TAG11__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG11__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG11__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG11__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG11__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG11__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG11__MODE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG11__VALID__SHIFT                                    31
#define AT_PRRF_PATCH_TAG11__VALID__WIDTH                                     1
#define AT_PRRF_PATCH_TAG11__VALID__MASK                            0x80000000U
#define AT_PRRF_PATCH_TAG11__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG11__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG11__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG11__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG11__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG11__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG11__VALID__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG11__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG11__READ                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG11__WRITE                                  0xc0f0ffffU
#define AT_PRRF_PATCH_TAG11__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG11__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG11_MACRO__ */

/** @} end of patch_tag11 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag12 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag12 patch_tag12
 * @brief Contains register fields associated with patch_tag12. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG12_MACRO__
#define __AT_PRRF_PATCH_TAG12_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG12__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG12__ADDR__WIDTH                                     16
#define AT_PRRF_PATCH_TAG12__ADDR__MASK                             0x0000ffffU
#define AT_PRRF_PATCH_TAG12__ADDR__READ(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG12__ADDR__WRITE(src)   ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG12__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG12__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG12__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG12__INST__SHIFT                                     20
#define AT_PRRF_PATCH_TAG12__INST__WIDTH                                      4
#define AT_PRRF_PATCH_TAG12__INST__MASK                             0x00f00000U
#define AT_PRRF_PATCH_TAG12__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG12__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG12__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG12__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG12__INST__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG12__MODE__SHIFT                                     30
#define AT_PRRF_PATCH_TAG12__MODE__WIDTH                                      1
#define AT_PRRF_PATCH_TAG12__MODE__MASK                             0x40000000U
#define AT_PRRF_PATCH_TAG12__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG12__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG12__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG12__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG12__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG12__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG12__MODE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG12__VALID__SHIFT                                    31
#define AT_PRRF_PATCH_TAG12__VALID__WIDTH                                     1
#define AT_PRRF_PATCH_TAG12__VALID__MASK                            0x80000000U
#define AT_PRRF_PATCH_TAG12__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG12__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG12__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG12__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG12__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG12__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG12__VALID__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG12__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG12__READ                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG12__WRITE                                  0xc0f0ffffU
#define AT_PRRF_PATCH_TAG12__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG12__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG12_MACRO__ */

/** @} end of patch_tag12 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag13 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag13 patch_tag13
 * @brief Contains register fields associated with patch_tag13. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG13_MACRO__
#define __AT_PRRF_PATCH_TAG13_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG13__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG13__ADDR__WIDTH                                     16
#define AT_PRRF_PATCH_TAG13__ADDR__MASK                             0x0000ffffU
#define AT_PRRF_PATCH_TAG13__ADDR__READ(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG13__ADDR__WRITE(src)   ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG13__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG13__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG13__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG13__INST__SHIFT                                     20
#define AT_PRRF_PATCH_TAG13__INST__WIDTH                                      4
#define AT_PRRF_PATCH_TAG13__INST__MASK                             0x00f00000U
#define AT_PRRF_PATCH_TAG13__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG13__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG13__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG13__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG13__INST__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG13__MODE__SHIFT                                     30
#define AT_PRRF_PATCH_TAG13__MODE__WIDTH                                      1
#define AT_PRRF_PATCH_TAG13__MODE__MASK                             0x40000000U
#define AT_PRRF_PATCH_TAG13__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG13__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG13__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG13__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG13__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG13__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG13__MODE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG13__VALID__SHIFT                                    31
#define AT_PRRF_PATCH_TAG13__VALID__WIDTH                                     1
#define AT_PRRF_PATCH_TAG13__VALID__MASK                            0x80000000U
#define AT_PRRF_PATCH_TAG13__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG13__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG13__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG13__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG13__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG13__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG13__VALID__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG13__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG13__READ                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG13__WRITE                                  0xc0f0ffffU
#define AT_PRRF_PATCH_TAG13__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG13__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG13_MACRO__ */

/** @} end of patch_tag13 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag14 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag14 patch_tag14
 * @brief Contains register fields associated with patch_tag14. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG14_MACRO__
#define __AT_PRRF_PATCH_TAG14_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG14__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG14__ADDR__WIDTH                                     16
#define AT_PRRF_PATCH_TAG14__ADDR__MASK                             0x0000ffffU
#define AT_PRRF_PATCH_TAG14__ADDR__READ(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG14__ADDR__WRITE(src)   ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG14__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG14__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG14__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG14__INST__SHIFT                                     20
#define AT_PRRF_PATCH_TAG14__INST__WIDTH                                      4
#define AT_PRRF_PATCH_TAG14__INST__MASK                             0x00f00000U
#define AT_PRRF_PATCH_TAG14__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG14__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG14__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG14__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG14__INST__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG14__MODE__SHIFT                                     30
#define AT_PRRF_PATCH_TAG14__MODE__WIDTH                                      1
#define AT_PRRF_PATCH_TAG14__MODE__MASK                             0x40000000U
#define AT_PRRF_PATCH_TAG14__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG14__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG14__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG14__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG14__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG14__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG14__MODE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG14__VALID__SHIFT                                    31
#define AT_PRRF_PATCH_TAG14__VALID__WIDTH                                     1
#define AT_PRRF_PATCH_TAG14__VALID__MASK                            0x80000000U
#define AT_PRRF_PATCH_TAG14__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG14__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG14__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG14__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG14__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG14__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG14__VALID__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG14__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG14__READ                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG14__WRITE                                  0xc0f0ffffU
#define AT_PRRF_PATCH_TAG14__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG14__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG14_MACRO__ */

/** @} end of patch_tag14 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag15 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch_tag15 patch_tag15
 * @brief Contains register fields associated with patch_tag15. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG15_MACRO__
#define __AT_PRRF_PATCH_TAG15_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf16_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ROM space HADDR[18:2]
 * @{
 */
#define AT_PRRF_PATCH_TAG15__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG15__ADDR__WIDTH                                     16
#define AT_PRRF_PATCH_TAG15__ADDR__MASK                             0x0000ffffU
#define AT_PRRF_PATCH_TAG15__ADDR__READ(src)    ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG15__ADDR__WRITE(src)   ((uint32_t)(src) & 0x0000ffffU)
#define AT_PRRF_PATCH_TAG15__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define AT_PRRF_PATCH_TAG15__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define AT_PRRF_PATCH_TAG15__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field inst */
/**
 * @defgroup at_ahb_prrf16_regs_core_inst_field inst_field
 * @brief macros for field inst
 * @details mode1 - Rd[3:0]
 * @{
 */
#define AT_PRRF_PATCH_TAG15__INST__SHIFT                                     20
#define AT_PRRF_PATCH_TAG15__INST__WIDTH                                      4
#define AT_PRRF_PATCH_TAG15__INST__MASK                             0x00f00000U
#define AT_PRRF_PATCH_TAG15__INST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define AT_PRRF_PATCH_TAG15__INST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG15__INST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define AT_PRRF_PATCH_TAG15__INST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
#define AT_PRRF_PATCH_TAG15__INST__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details ROM patch mode  1=new  0=legacy/original
 * @{
 */
#define AT_PRRF_PATCH_TAG15__MODE__SHIFT                                     30
#define AT_PRRF_PATCH_TAG15__MODE__WIDTH                                      1
#define AT_PRRF_PATCH_TAG15__MODE__MASK                             0x40000000U
#define AT_PRRF_PATCH_TAG15__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_PRRF_PATCH_TAG15__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG15__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_PRRF_PATCH_TAG15__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_PRRF_PATCH_TAG15__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_PRRF_PATCH_TAG15__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_PRRF_PATCH_TAG15__MODE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field valid */
/**
 * @defgroup at_ahb_prrf16_regs_core_valid_field valid_field
 * @brief macros for field valid
 * @details ROM patch entry valid (1=valid)
 * @{
 */
#define AT_PRRF_PATCH_TAG15__VALID__SHIFT                                    31
#define AT_PRRF_PATCH_TAG15__VALID__WIDTH                                     1
#define AT_PRRF_PATCH_TAG15__VALID__MASK                            0x80000000U
#define AT_PRRF_PATCH_TAG15__VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_PRRF_PATCH_TAG15__VALID__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG15__VALID__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_PRRF_PATCH_TAG15__VALID__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_PRRF_PATCH_TAG15__VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_PRRF_PATCH_TAG15__VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_PRRF_PATCH_TAG15__VALID__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG15__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG15__READ                                   0xc0f0ffffU
#define AT_PRRF_PATCH_TAG15__WRITE                                  0xc0f0ffffU
#define AT_PRRF_PATCH_TAG15__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG15__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG15_MACRO__ */

/** @} end of patch_tag15 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch0 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch0 patch0
 * @brief Contains register fields associated with patch0. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH0_MACRO__
#define __AT_PRRF_PATCH0_MACRO__

/* macros for field patch0 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch0_field patch0_field
 * @brief macros for field patch0
 * @{
 */
#define AT_PRRF_PATCH0__PATCH0__SHIFT                                         0
#define AT_PRRF_PATCH0__PATCH0__WIDTH                                        32
#define AT_PRRF_PATCH0__PATCH0__MASK                                0xffffffffU
#define AT_PRRF_PATCH0__PATCH0__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH0__PATCH0__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH0__PATCH0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH0__PATCH0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH0__PATCH0__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH0__TYPE                                           uint32_t
#define AT_PRRF_PATCH0__READ                                        0xffffffffU
#define AT_PRRF_PATCH0__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH0__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH0__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH0_MACRO__ */

/** @} end of patch0 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch1 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch1 patch1
 * @brief Contains register fields associated with patch1. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH1_MACRO__
#define __AT_PRRF_PATCH1_MACRO__

/* macros for field patch1 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch1_field patch1_field
 * @brief macros for field patch1
 * @{
 */
#define AT_PRRF_PATCH1__PATCH1__SHIFT                                         0
#define AT_PRRF_PATCH1__PATCH1__WIDTH                                        32
#define AT_PRRF_PATCH1__PATCH1__MASK                                0xffffffffU
#define AT_PRRF_PATCH1__PATCH1__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH1__PATCH1__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH1__PATCH1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH1__PATCH1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH1__PATCH1__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH1__TYPE                                           uint32_t
#define AT_PRRF_PATCH1__READ                                        0xffffffffU
#define AT_PRRF_PATCH1__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH1__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH1__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH1_MACRO__ */

/** @} end of patch1 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch2 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch2 patch2
 * @brief Contains register fields associated with patch2. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH2_MACRO__
#define __AT_PRRF_PATCH2_MACRO__

/* macros for field patch2 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch2_field patch2_field
 * @brief macros for field patch2
 * @{
 */
#define AT_PRRF_PATCH2__PATCH2__SHIFT                                         0
#define AT_PRRF_PATCH2__PATCH2__WIDTH                                        32
#define AT_PRRF_PATCH2__PATCH2__MASK                                0xffffffffU
#define AT_PRRF_PATCH2__PATCH2__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH2__PATCH2__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH2__PATCH2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH2__PATCH2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH2__PATCH2__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH2__TYPE                                           uint32_t
#define AT_PRRF_PATCH2__READ                                        0xffffffffU
#define AT_PRRF_PATCH2__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH2__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH2__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH2_MACRO__ */

/** @} end of patch2 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch3 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch3 patch3
 * @brief Contains register fields associated with patch3. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH3_MACRO__
#define __AT_PRRF_PATCH3_MACRO__

/* macros for field patch3 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch3_field patch3_field
 * @brief macros for field patch3
 * @{
 */
#define AT_PRRF_PATCH3__PATCH3__SHIFT                                         0
#define AT_PRRF_PATCH3__PATCH3__WIDTH                                        32
#define AT_PRRF_PATCH3__PATCH3__MASK                                0xffffffffU
#define AT_PRRF_PATCH3__PATCH3__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH3__PATCH3__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH3__PATCH3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH3__PATCH3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH3__PATCH3__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH3__TYPE                                           uint32_t
#define AT_PRRF_PATCH3__READ                                        0xffffffffU
#define AT_PRRF_PATCH3__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH3__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH3__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH3_MACRO__ */

/** @} end of patch3 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch4 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch4 patch4
 * @brief Contains register fields associated with patch4. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH4_MACRO__
#define __AT_PRRF_PATCH4_MACRO__

/* macros for field patch4 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch4_field patch4_field
 * @brief macros for field patch4
 * @{
 */
#define AT_PRRF_PATCH4__PATCH4__SHIFT                                         0
#define AT_PRRF_PATCH4__PATCH4__WIDTH                                        32
#define AT_PRRF_PATCH4__PATCH4__MASK                                0xffffffffU
#define AT_PRRF_PATCH4__PATCH4__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH4__PATCH4__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH4__PATCH4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH4__PATCH4__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH4__PATCH4__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH4__TYPE                                           uint32_t
#define AT_PRRF_PATCH4__READ                                        0xffffffffU
#define AT_PRRF_PATCH4__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH4__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH4__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH4_MACRO__ */

/** @} end of patch4 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch5 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch5 patch5
 * @brief Contains register fields associated with patch5. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH5_MACRO__
#define __AT_PRRF_PATCH5_MACRO__

/* macros for field patch5 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch5_field patch5_field
 * @brief macros for field patch5
 * @{
 */
#define AT_PRRF_PATCH5__PATCH5__SHIFT                                         0
#define AT_PRRF_PATCH5__PATCH5__WIDTH                                        32
#define AT_PRRF_PATCH5__PATCH5__MASK                                0xffffffffU
#define AT_PRRF_PATCH5__PATCH5__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH5__PATCH5__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH5__PATCH5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH5__PATCH5__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH5__PATCH5__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH5__TYPE                                           uint32_t
#define AT_PRRF_PATCH5__READ                                        0xffffffffU
#define AT_PRRF_PATCH5__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH5__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH5__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH5_MACRO__ */

/** @} end of patch5 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch6 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch6 patch6
 * @brief Contains register fields associated with patch6. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH6_MACRO__
#define __AT_PRRF_PATCH6_MACRO__

/* macros for field patch6 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch6_field patch6_field
 * @brief macros for field patch6
 * @{
 */
#define AT_PRRF_PATCH6__PATCH6__SHIFT                                         0
#define AT_PRRF_PATCH6__PATCH6__WIDTH                                        32
#define AT_PRRF_PATCH6__PATCH6__MASK                                0xffffffffU
#define AT_PRRF_PATCH6__PATCH6__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH6__PATCH6__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH6__PATCH6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH6__PATCH6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH6__PATCH6__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH6__TYPE                                           uint32_t
#define AT_PRRF_PATCH6__READ                                        0xffffffffU
#define AT_PRRF_PATCH6__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH6__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH6__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH6_MACRO__ */

/** @} end of patch6 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch7 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch7 patch7
 * @brief Contains register fields associated with patch7. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH7_MACRO__
#define __AT_PRRF_PATCH7_MACRO__

/* macros for field patch7 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch7_field patch7_field
 * @brief macros for field patch7
 * @{
 */
#define AT_PRRF_PATCH7__PATCH7__SHIFT                                         0
#define AT_PRRF_PATCH7__PATCH7__WIDTH                                        32
#define AT_PRRF_PATCH7__PATCH7__MASK                                0xffffffffU
#define AT_PRRF_PATCH7__PATCH7__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH7__PATCH7__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH7__PATCH7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH7__PATCH7__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH7__PATCH7__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH7__TYPE                                           uint32_t
#define AT_PRRF_PATCH7__READ                                        0xffffffffU
#define AT_PRRF_PATCH7__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH7__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH7__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH7_MACRO__ */

/** @} end of patch7 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch8 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch8 patch8
 * @brief Contains register fields associated with patch8. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH8_MACRO__
#define __AT_PRRF_PATCH8_MACRO__

/* macros for field patch8 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch8_field patch8_field
 * @brief macros for field patch8
 * @{
 */
#define AT_PRRF_PATCH8__PATCH8__SHIFT                                         0
#define AT_PRRF_PATCH8__PATCH8__WIDTH                                        32
#define AT_PRRF_PATCH8__PATCH8__MASK                                0xffffffffU
#define AT_PRRF_PATCH8__PATCH8__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH8__PATCH8__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH8__PATCH8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH8__PATCH8__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH8__PATCH8__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH8__TYPE                                           uint32_t
#define AT_PRRF_PATCH8__READ                                        0xffffffffU
#define AT_PRRF_PATCH8__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH8__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH8__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH8_MACRO__ */

/** @} end of patch8 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch9 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch9 patch9
 * @brief Contains register fields associated with patch9. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH9_MACRO__
#define __AT_PRRF_PATCH9_MACRO__

/* macros for field patch9 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch9_field patch9_field
 * @brief macros for field patch9
 * @{
 */
#define AT_PRRF_PATCH9__PATCH9__SHIFT                                         0
#define AT_PRRF_PATCH9__PATCH9__WIDTH                                        32
#define AT_PRRF_PATCH9__PATCH9__MASK                                0xffffffffU
#define AT_PRRF_PATCH9__PATCH9__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH9__PATCH9__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH9__PATCH9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH9__PATCH9__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH9__PATCH9__RESET_VALUE                         0x00000000U
/** @} */
#define AT_PRRF_PATCH9__TYPE                                           uint32_t
#define AT_PRRF_PATCH9__READ                                        0xffffffffU
#define AT_PRRF_PATCH9__WRITE                                       0xffffffffU
#define AT_PRRF_PATCH9__PRESERVED                                   0x00000000U
#define AT_PRRF_PATCH9__RESET_VALUE                                 0x00000000U

#endif /* __AT_PRRF_PATCH9_MACRO__ */

/** @} end of patch9 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch10 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch10 patch10
 * @brief Contains register fields associated with patch10. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH10_MACRO__
#define __AT_PRRF_PATCH10_MACRO__

/* macros for field patch10 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch10_field patch10_field
 * @brief macros for field patch10
 * @{
 */
#define AT_PRRF_PATCH10__PATCH10__SHIFT                                       0
#define AT_PRRF_PATCH10__PATCH10__WIDTH                                      32
#define AT_PRRF_PATCH10__PATCH10__MASK                              0xffffffffU
#define AT_PRRF_PATCH10__PATCH10__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH10__PATCH10__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH10__PATCH10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH10__PATCH10__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH10__PATCH10__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH10__TYPE                                          uint32_t
#define AT_PRRF_PATCH10__READ                                       0xffffffffU
#define AT_PRRF_PATCH10__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH10__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH10__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH10_MACRO__ */

/** @} end of patch10 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch11 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch11 patch11
 * @brief Contains register fields associated with patch11. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH11_MACRO__
#define __AT_PRRF_PATCH11_MACRO__

/* macros for field patch11 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch11_field patch11_field
 * @brief macros for field patch11
 * @{
 */
#define AT_PRRF_PATCH11__PATCH11__SHIFT                                       0
#define AT_PRRF_PATCH11__PATCH11__WIDTH                                      32
#define AT_PRRF_PATCH11__PATCH11__MASK                              0xffffffffU
#define AT_PRRF_PATCH11__PATCH11__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH11__PATCH11__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH11__PATCH11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH11__PATCH11__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH11__PATCH11__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH11__TYPE                                          uint32_t
#define AT_PRRF_PATCH11__READ                                       0xffffffffU
#define AT_PRRF_PATCH11__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH11__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH11__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH11_MACRO__ */

/** @} end of patch11 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch12 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch12 patch12
 * @brief Contains register fields associated with patch12. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH12_MACRO__
#define __AT_PRRF_PATCH12_MACRO__

/* macros for field patch12 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch12_field patch12_field
 * @brief macros for field patch12
 * @{
 */
#define AT_PRRF_PATCH12__PATCH12__SHIFT                                       0
#define AT_PRRF_PATCH12__PATCH12__WIDTH                                      32
#define AT_PRRF_PATCH12__PATCH12__MASK                              0xffffffffU
#define AT_PRRF_PATCH12__PATCH12__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH12__PATCH12__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH12__PATCH12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH12__PATCH12__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH12__PATCH12__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH12__TYPE                                          uint32_t
#define AT_PRRF_PATCH12__READ                                       0xffffffffU
#define AT_PRRF_PATCH12__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH12__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH12__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH12_MACRO__ */

/** @} end of patch12 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch13 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch13 patch13
 * @brief Contains register fields associated with patch13. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH13_MACRO__
#define __AT_PRRF_PATCH13_MACRO__

/* macros for field patch13 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch13_field patch13_field
 * @brief macros for field patch13
 * @{
 */
#define AT_PRRF_PATCH13__PATCH13__SHIFT                                       0
#define AT_PRRF_PATCH13__PATCH13__WIDTH                                      32
#define AT_PRRF_PATCH13__PATCH13__MASK                              0xffffffffU
#define AT_PRRF_PATCH13__PATCH13__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH13__PATCH13__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH13__PATCH13__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH13__PATCH13__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH13__PATCH13__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH13__TYPE                                          uint32_t
#define AT_PRRF_PATCH13__READ                                       0xffffffffU
#define AT_PRRF_PATCH13__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH13__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH13__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH13_MACRO__ */

/** @} end of patch13 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch14 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch14 patch14
 * @brief Contains register fields associated with patch14. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH14_MACRO__
#define __AT_PRRF_PATCH14_MACRO__

/* macros for field patch14 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch14_field patch14_field
 * @brief macros for field patch14
 * @{
 */
#define AT_PRRF_PATCH14__PATCH14__SHIFT                                       0
#define AT_PRRF_PATCH14__PATCH14__WIDTH                                      32
#define AT_PRRF_PATCH14__PATCH14__MASK                              0xffffffffU
#define AT_PRRF_PATCH14__PATCH14__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH14__PATCH14__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH14__PATCH14__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH14__PATCH14__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH14__PATCH14__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH14__TYPE                                          uint32_t
#define AT_PRRF_PATCH14__READ                                       0xffffffffU
#define AT_PRRF_PATCH14__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH14__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH14__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH14_MACRO__ */

/** @} end of patch14 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch15 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch15 patch15
 * @brief Contains register fields associated with patch15. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH15_MACRO__
#define __AT_PRRF_PATCH15_MACRO__

/* macros for field patch15 */
/**
 * @defgroup at_ahb_prrf16_regs_core_patch15_field patch15_field
 * @brief macros for field patch15
 * @{
 */
#define AT_PRRF_PATCH15__PATCH15__SHIFT                                       0
#define AT_PRRF_PATCH15__PATCH15__WIDTH                                      32
#define AT_PRRF_PATCH15__PATCH15__MASK                              0xffffffffU
#define AT_PRRF_PATCH15__PATCH15__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH15__PATCH15__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH15__PATCH15__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH15__PATCH15__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH15__PATCH15__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH15__TYPE                                          uint32_t
#define AT_PRRF_PATCH15__READ                                       0xffffffffU
#define AT_PRRF_PATCH15__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH15__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH15__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH15_MACRO__ */

/** @} end of patch15 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_wrt_config_lo */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_wrt_config_lo rram_wrt_config_lo
 * @brief Contains register fields associated with rram_wrt_config_lo. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_WRT_CONFIG_LO_MACRO__
#define __AT_PRRF_RRAM_WRT_CONFIG_LO_MACRO__

/* macros for field din */
/**
 * @defgroup at_ahb_prrf16_regs_core_din_field din_field
 * @brief macros for field din
 * @{
 */
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__SHIFT                                0
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__WIDTH                               32
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__MASK                       0xffffffffU
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_RRAM_WRT_CONFIG_LO__DIN__RESET_VALUE                0x00000000U
/** @} */
#define AT_PRRF_RRAM_WRT_CONFIG_LO__TYPE                               uint32_t
#define AT_PRRF_RRAM_WRT_CONFIG_LO__READ                            0xffffffffU
#define AT_PRRF_RRAM_WRT_CONFIG_LO__WRITE                           0xffffffffU
#define AT_PRRF_RRAM_WRT_CONFIG_LO__PRESERVED                       0x00000000U
#define AT_PRRF_RRAM_WRT_CONFIG_LO__RESET_VALUE                     0x00000000U

#endif /* __AT_PRRF_RRAM_WRT_CONFIG_LO_MACRO__ */

/** @} end of rram_wrt_config_lo */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_wrt_config_hi */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_wrt_config_hi rram_wrt_config_hi
 * @brief Contains register fields associated with rram_wrt_config_hi. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_WRT_CONFIG_HI_MACRO__
#define __AT_PRRF_RRAM_WRT_CONFIG_HI_MACRO__

/* macros for field din */
/**
 * @defgroup at_ahb_prrf16_regs_core_din_field din_field
 * @brief macros for field din
 * @{
 */
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__SHIFT                                0
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__WIDTH                               32
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__MASK                       0xffffffffU
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_RRAM_WRT_CONFIG_HI__DIN__RESET_VALUE                0x00000000U
/** @} */
#define AT_PRRF_RRAM_WRT_CONFIG_HI__TYPE                               uint32_t
#define AT_PRRF_RRAM_WRT_CONFIG_HI__READ                            0xffffffffU
#define AT_PRRF_RRAM_WRT_CONFIG_HI__WRITE                           0xffffffffU
#define AT_PRRF_RRAM_WRT_CONFIG_HI__PRESERVED                       0x00000000U
#define AT_PRRF_RRAM_WRT_CONFIG_HI__RESET_VALUE                     0x00000000U

#endif /* __AT_PRRF_RRAM_WRT_CONFIG_HI_MACRO__ */

/** @} end of rram_wrt_config_hi */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_read_config_lo */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_read_config_lo rram_read_config_lo
 * @brief Contains register fields associated with rram_read_config_lo. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_READ_CONFIG_LO_MACRO__
#define __AT_PRRF_RRAM_READ_CONFIG_LO_MACRO__

/* macros for field dout */
/**
 * @defgroup at_ahb_prrf16_regs_core_dout_field dout_field
 * @brief macros for field dout
 * @{
 */
#define AT_PRRF_RRAM_READ_CONFIG_LO__DOUT__SHIFT                              0
#define AT_PRRF_RRAM_READ_CONFIG_LO__DOUT__WIDTH                             32
#define AT_PRRF_RRAM_READ_CONFIG_LO__DOUT__MASK                     0xffffffffU
#define AT_PRRF_RRAM_READ_CONFIG_LO__DOUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_PRRF_RRAM_READ_CONFIG_LO__DOUT__RESET_VALUE              0x00000000U
/** @} */
#define AT_PRRF_RRAM_READ_CONFIG_LO__TYPE                              uint32_t
#define AT_PRRF_RRAM_READ_CONFIG_LO__READ                           0xffffffffU
#define AT_PRRF_RRAM_READ_CONFIG_LO__PRESERVED                      0x00000000U
#define AT_PRRF_RRAM_READ_CONFIG_LO__RESET_VALUE                    0x00000000U

#endif /* __AT_PRRF_RRAM_READ_CONFIG_LO_MACRO__ */

/** @} end of rram_read_config_lo */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_read_config_hi */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_read_config_hi rram_read_config_hi
 * @brief Contains register fields associated with rram_read_config_hi. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_READ_CONFIG_HI_MACRO__
#define __AT_PRRF_RRAM_READ_CONFIG_HI_MACRO__

/* macros for field dout */
/**
 * @defgroup at_ahb_prrf16_regs_core_dout_field dout_field
 * @brief macros for field dout
 * @{
 */
#define AT_PRRF_RRAM_READ_CONFIG_HI__DOUT__SHIFT                              0
#define AT_PRRF_RRAM_READ_CONFIG_HI__DOUT__WIDTH                             32
#define AT_PRRF_RRAM_READ_CONFIG_HI__DOUT__MASK                     0xffffffffU
#define AT_PRRF_RRAM_READ_CONFIG_HI__DOUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_PRRF_RRAM_READ_CONFIG_HI__DOUT__RESET_VALUE              0x00000000U
/** @} */
#define AT_PRRF_RRAM_READ_CONFIG_HI__TYPE                              uint32_t
#define AT_PRRF_RRAM_READ_CONFIG_HI__READ                           0xffffffffU
#define AT_PRRF_RRAM_READ_CONFIG_HI__PRESERVED                      0x00000000U
#define AT_PRRF_RRAM_READ_CONFIG_HI__RESET_VALUE                    0x00000000U

#endif /* __AT_PRRF_RRAM_READ_CONFIG_HI_MACRO__ */

/** @} end of rram_read_config_hi */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_cache_config */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_cache_config rram_cache_config
 * @brief this register is only meaningful if r-cache is instantiated (see rram_status register) definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_CACHE_CONFIG_MACRO__
#define __AT_PRRF_RRAM_CACHE_CONFIG_MACRO__

/* macros for field cache_mode */
/**
 * @defgroup at_ahb_prrf16_regs_core_cache_mode_field cache_mode_field
 * @brief macros for field cache_mode
 * @{
 */
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__SHIFT                          0
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__WIDTH                          1
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__MASK                 0x00000001U
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_PRRF_RRAM_CACHE_CONFIG__CACHE_MODE__RESET_VALUE          0x00000000U
/** @} */

/* macros for field enable_cache */
/**
 * @defgroup at_ahb_prrf16_regs_core_enable_cache_field enable_cache_field
 * @brief macros for field enable_cache
 * @{
 */
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__SHIFT                        1
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__WIDTH                        1
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__MASK               0x00000002U
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_CACHE__RESET_VALUE        0x00000000U
/** @} */

/* macros for field invalidate_cache */
/**
 * @defgroup at_ahb_prrf16_regs_core_invalidate_cache_field invalidate_cache_field
 * @brief macros for field invalidate_cache
 * @{
 */
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__SHIFT                    2
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__WIDTH                    1
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__MASK           0x00000004U
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_PRRF_RRAM_CACHE_CONFIG__INVALIDATE_CACHE__RESET_VALUE    0x00000000U
/** @} */

/* macros for field enable_fine_clock_gating */
/**
 * @defgroup at_ahb_prrf16_regs_core_enable_fine_clock_gating_field enable_fine_clock_gating_field
 * @brief macros for field enable_fine_clock_gating
 * @details secondary clock gating control (enable_cache is primary). 1=rram_cache clock is enabled only when access falls in rram region. 0=always-on.
 * @{
 */
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__SHIFT            3
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__WIDTH            1
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__MASK   0x00000008U
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_PRRF_RRAM_CACHE_CONFIG__ENABLE_FINE_CLOCK_GATING__RESET_VALUE \
                    0x00000000U
/** @} */
#define AT_PRRF_RRAM_CACHE_CONFIG__TYPE                                uint32_t
#define AT_PRRF_RRAM_CACHE_CONFIG__READ                             0x0000000fU
#define AT_PRRF_RRAM_CACHE_CONFIG__WRITE                            0x0000000fU
#define AT_PRRF_RRAM_CACHE_CONFIG__PRESERVED                        0x00000000U
#define AT_PRRF_RRAM_CACHE_CONFIG__RESET_VALUE                      0x00000000U

#endif /* __AT_PRRF_RRAM_CACHE_CONFIG_MACRO__ */

/** @} end of rram_cache_config */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_mem_config */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_mem_config rram_mem_config
 * @brief Contains register fields associated with rram_mem_config. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_MEM_CONFIG_MACRO__
#define __AT_PRRF_RRAM_MEM_CONFIG_MACRO__

/* macros for field rram_speedup_b */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_speedup_b_field rram_speedup_b_field
 * @brief macros for field rram_speedup_b
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__SHIFT                        0
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__WIDTH                        1
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__MASK               0x00000001U
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_PRRF_RRAM_MEM_CONFIG__RRAM_SPEEDUP_B__RESET_VALUE        0x00000000U
/** @} */

/* macros for field trc_info */
/**
 * @defgroup at_ahb_prrf16_regs_core_trc_info_field trc_info_field
 * @brief macros for field trc_info
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__SHIFT                              1
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__WIDTH                              1
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__MASK                     0x00000002U
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_INFO__RESET_VALUE              0x00000000U
/** @} */

/* macros for field trc_lven */
/**
 * @defgroup at_ahb_prrf16_regs_core_trc_lven_field trc_lven_field
 * @brief macros for field trc_lven
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__SHIFT                              2
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__WIDTH                              1
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__MASK                     0x00000004U
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_LVEN__RESET_VALUE              0x00000000U
/** @} */

/* macros for field trc_tin */
/**
 * @defgroup at_ahb_prrf16_regs_core_trc_tin_field trc_tin_field
 * @brief macros for field trc_tin
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__SHIFT                               3
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__WIDTH                              15
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__MASK                      0x0003fff8U
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fff8U) >> 3)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x0003fff8U)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fff8U) | (((uint32_t)(src) <<\
                    3) & 0x0003fff8U)
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x0003fff8U)))
#define AT_PRRF_RRAM_MEM_CONFIG__TRC_TIN__RESET_VALUE               0x00000000U
/** @} */

/* macros for field en_fine_ckg */
/**
 * @defgroup at_ahb_prrf16_regs_core_en_fine_ckg_field en_fine_ckg_field
 * @brief macros for field en_fine_ckg
 * @details enable fine clock gating to the rram macro
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__SHIFT                          18
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__WIDTH                           1
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__MASK                  0x00040000U
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define AT_PRRF_RRAM_MEM_CONFIG__EN_FINE_CKG__RESET_VALUE           0x00000000U
/** @} */

/* macros for field hresp_always_okay */
/**
 * @defgroup at_ahb_prrf16_regs_core_hresp_always_okay_field hresp_always_okay_field
 * @brief macros for field hresp_always_okay
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__SHIFT                    19
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__WIDTH                     1
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__MASK            0x00080000U
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define AT_PRRF_RRAM_MEM_CONFIG__HRESP_ALWAYS_OKAY__RESET_VALUE     0x00000000U
/** @} */

/* macros for field reduce_2cyc */
/**
 * @defgroup at_ahb_prrf16_regs_core_reduce_2cyc_field reduce_2cyc_field
 * @brief macros for field reduce_2cyc
 * @details Reduce rram read by 2 cycles (Only set this bit when reduce_1cyc is set too)
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__SHIFT                          20
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__WIDTH                           1
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__MASK                  0x00100000U
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_2CYC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field reduce_1cyc */
/**
 * @defgroup at_ahb_prrf16_regs_core_reduce_1cyc_field reduce_1cyc_field
 * @brief macros for field reduce_1cyc
 * @details Reduce rram read by 1 cycle
 * @{
 */
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__SHIFT                          21
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__WIDTH                           1
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__MASK                  0x00200000U
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define AT_PRRF_RRAM_MEM_CONFIG__REDUCE_1CYC__RESET_VALUE           0x00000000U
/** @} */
#define AT_PRRF_RRAM_MEM_CONFIG__TYPE                                  uint32_t
#define AT_PRRF_RRAM_MEM_CONFIG__READ                               0x003fffffU
#define AT_PRRF_RRAM_MEM_CONFIG__WRITE                              0x003fffffU
#define AT_PRRF_RRAM_MEM_CONFIG__PRESERVED                          0x00000000U
#define AT_PRRF_RRAM_MEM_CONFIG__RESET_VALUE                        0x00000000U

#endif /* __AT_PRRF_RRAM_MEM_CONFIG_MACRO__ */

/** @} end of rram_mem_config */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_status */
/**
 * @defgroup at_ahb_prrf16_regs_core_rram_status rram_status
 * @brief Contains register fields associated with rram_status. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_STATUS_MACRO__
#define __AT_PRRF_RRAM_STATUS_MACRO__

/* macros for field busy */
/**
 * @defgroup at_ahb_prrf16_regs_core_busy_field busy_field
 * @brief macros for field busy
 * @{
 */
#define AT_PRRF_RRAM_STATUS__BUSY__SHIFT                                      0
#define AT_PRRF_RRAM_STATUS__BUSY__WIDTH                                      1
#define AT_PRRF_RRAM_STATUS__BUSY__MASK                             0x00000001U
#define AT_PRRF_RRAM_STATUS__BUSY__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define AT_PRRF_RRAM_STATUS__BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_PRRF_RRAM_STATUS__BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_PRRF_RRAM_STATUS__BUSY__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field err */
/**
 * @defgroup at_ahb_prrf16_regs_core_err_field err_field
 * @brief macros for field err
 * @{
 */
#define AT_PRRF_RRAM_STATUS__ERR__SHIFT                                       1
#define AT_PRRF_RRAM_STATUS__ERR__WIDTH                                       1
#define AT_PRRF_RRAM_STATUS__ERR__MASK                              0x00000002U
#define AT_PRRF_RRAM_STATUS__ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_PRRF_RRAM_STATUS__ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_PRRF_RRAM_STATUS__ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_PRRF_RRAM_STATUS__ERR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcache_present */
/**
 * @defgroup at_ahb_prrf16_regs_core_rcache_present_field rcache_present_field
 * @brief macros for field rcache_present
 * @details r-cache is instantiated in the design; some projects may remove the r-cache to save area
 * @{
 */
#define AT_PRRF_RRAM_STATUS__RCACHE_PRESENT__SHIFT                            2
#define AT_PRRF_RRAM_STATUS__RCACHE_PRESENT__WIDTH                            1
#define AT_PRRF_RRAM_STATUS__RCACHE_PRESENT__MASK                   0x00000004U
#define AT_PRRF_RRAM_STATUS__RCACHE_PRESENT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_PRRF_RRAM_STATUS__RCACHE_PRESENT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_PRRF_RRAM_STATUS__RCACHE_PRESENT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_PRRF_RRAM_STATUS__RCACHE_PRESENT__RESET_VALUE            0x00000000U
/** @} */
#define AT_PRRF_RRAM_STATUS__TYPE                                      uint32_t
#define AT_PRRF_RRAM_STATUS__READ                                   0x00000007U
#define AT_PRRF_RRAM_STATUS__PRESERVED                              0x00000000U
#define AT_PRRF_RRAM_STATUS__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_RRAM_STATUS_MACRO__ */

/** @} end of rram_status */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_core_id */
/**
 * @defgroup at_ahb_prrf16_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __AT_PRRF_CORE_ID_MACRO__
#define __AT_PRRF_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_ahb_prrf16_regs_core_id_field id_field
 * @brief macros for field id
 * @details PRRF in ASCII
 * @{
 */
#define AT_PRRF_CORE_ID__ID__SHIFT                                            0
#define AT_PRRF_CORE_ID__ID__WIDTH                                           32
#define AT_PRRF_CORE_ID__ID__MASK                                   0xffffffffU
#define AT_PRRF_CORE_ID__ID__READ(src)          ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_CORE_ID__ID__RESET_VALUE                            0x50525246U
/** @} */
#define AT_PRRF_CORE_ID__TYPE                                          uint32_t
#define AT_PRRF_CORE_ID__READ                                       0xffffffffU
#define AT_PRRF_CORE_ID__PRESERVED                                  0x00000000U
#define AT_PRRF_CORE_ID__RESET_VALUE                                0x50525246U

#endif /* __AT_PRRF_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rev_hash */
/**
 * @defgroup at_ahb_prrf16_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __AT_PRRF_REV_HASH_MACRO__
#define __AT_PRRF_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_ahb_prrf16_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define AT_PRRF_REV_HASH__ID__SHIFT                                           0
#define AT_PRRF_REV_HASH__ID__WIDTH                                          32
#define AT_PRRF_REV_HASH__ID__MASK                                  0xffffffffU
#define AT_PRRF_REV_HASH__ID__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_REV_HASH__ID__RESET_VALUE                           0x30fa29f1U
/** @} */
#define AT_PRRF_REV_HASH__TYPE                                         uint32_t
#define AT_PRRF_REV_HASH__READ                                      0xffffffffU
#define AT_PRRF_REV_HASH__PRESERVED                                 0x00000000U
#define AT_PRRF_REV_HASH__RESET_VALUE                               0x30fa29f1U

#endif /* __AT_PRRF_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rev_key */
/**
 * @defgroup at_ahb_prrf16_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __AT_PRRF_REV_KEY_MACRO__
#define __AT_PRRF_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_ahb_prrf16_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define AT_PRRF_REV_KEY__ID__SHIFT                                            0
#define AT_PRRF_REV_KEY__ID__WIDTH                                           32
#define AT_PRRF_REV_KEY__ID__MASK                                   0xffffffffU
#define AT_PRRF_REV_KEY__ID__READ(src)          ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_REV_KEY__ID__RESET_VALUE                            0x52455620U
/** @} */
#define AT_PRRF_REV_KEY__TYPE                                          uint32_t
#define AT_PRRF_REV_KEY__READ                                       0xffffffffU
#define AT_PRRF_REV_KEY__PRESERVED                                  0x00000000U
#define AT_PRRF_REV_KEY__RESET_VALUE                                0x52455620U

#endif /* __AT_PRRF_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_AHB_PRRF16_REGS_CORE */
#endif /* __REG_AT_AHB_PRRF16_REGS_CORE_H__ */
