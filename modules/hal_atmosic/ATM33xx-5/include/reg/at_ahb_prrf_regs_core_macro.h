/*                                                                           */
/* File:       at_ahb_prrf_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_ahb_prrf_regs_core.rdl          */
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


#ifndef __REG_AT_AHB_PRRF_REGS_CORE_H__
#define __REG_AT_AHB_PRRF_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_AHB_PRRF_REGS_CORE at_ahb_prrf_regs_core
 * @ingroup AT_REG
 * @brief at_ahb_prrf_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag0 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag0 patch_tag0
 * @brief Contains register fields associated with patch_tag0. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG0_MACRO__
#define __AT_PRRF_PATCH_TAG0_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG0__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG0__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG0__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG0__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG0__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG0__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG0__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG0__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG0__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG0__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG0__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG0__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG0__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG0__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG0__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG0__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG0__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG0__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG0__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG0__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG0__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG0_MACRO__ */

/** @} end of patch_tag0 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag1 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag1 patch_tag1
 * @brief Contains register fields associated with patch_tag1. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG1_MACRO__
#define __AT_PRRF_PATCH_TAG1_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG1__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG1__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG1__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG1__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG1__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG1__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG1__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG1__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG1__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG1__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG1__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG1__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG1__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG1__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG1__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG1__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG1__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG1__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG1__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG1__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG1__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG1_MACRO__ */

/** @} end of patch_tag1 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag2 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag2 patch_tag2
 * @brief Contains register fields associated with patch_tag2. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG2_MACRO__
#define __AT_PRRF_PATCH_TAG2_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG2__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG2__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG2__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG2__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG2__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG2__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG2__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG2__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG2__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG2__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG2__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG2__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG2__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG2__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG2__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG2__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG2__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG2__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG2__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG2__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG2__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG2_MACRO__ */

/** @} end of patch_tag2 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag3 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag3 patch_tag3
 * @brief Contains register fields associated with patch_tag3. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG3_MACRO__
#define __AT_PRRF_PATCH_TAG3_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG3__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG3__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG3__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG3__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG3__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG3__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG3__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG3__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG3__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG3__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG3__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG3__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG3__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG3__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG3__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG3__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG3__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG3__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG3__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG3__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG3__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG3_MACRO__ */

/** @} end of patch_tag3 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag4 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag4 patch_tag4
 * @brief Contains register fields associated with patch_tag4. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG4_MACRO__
#define __AT_PRRF_PATCH_TAG4_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG4__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG4__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG4__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG4__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG4__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG4__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG4__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG4__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG4__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG4__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG4__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG4__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG4__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG4__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG4__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG4__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG4__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG4__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG4__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG4__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG4__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG4_MACRO__ */

/** @} end of patch_tag4 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag5 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag5 patch_tag5
 * @brief Contains register fields associated with patch_tag5. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG5_MACRO__
#define __AT_PRRF_PATCH_TAG5_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG5__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG5__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG5__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG5__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG5__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG5__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG5__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG5__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG5__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG5__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG5__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG5__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG5__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG5__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG5__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG5__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG5__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG5__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG5__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG5__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG5__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG5_MACRO__ */

/** @} end of patch_tag5 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag6 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag6 patch_tag6
 * @brief Contains register fields associated with patch_tag6. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG6_MACRO__
#define __AT_PRRF_PATCH_TAG6_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG6__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG6__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG6__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG6__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG6__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG6__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG6__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG6__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG6__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG6__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG6__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG6__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG6__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG6__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG6__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG6__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG6__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG6__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG6__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG6__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG6__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG6_MACRO__ */

/** @} end of patch_tag6 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag7 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag7 patch_tag7
 * @brief Contains register fields associated with patch_tag7. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG7_MACRO__
#define __AT_PRRF_PATCH_TAG7_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG7__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG7__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG7__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG7__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG7__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG7__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG7__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG7__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG7__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG7__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG7__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG7__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG7__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG7__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG7__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG7__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG7__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG7__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG7__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG7__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG7__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG7_MACRO__ */

/** @} end of patch_tag7 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag8 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag8 patch_tag8
 * @brief Contains register fields associated with patch_tag8. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG8_MACRO__
#define __AT_PRRF_PATCH_TAG8_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG8__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG8__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG8__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG8__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG8__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG8__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG8__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG8__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG8__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG8__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG8__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG8__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG8__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG8__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG8__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG8__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG8__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG8__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG8__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG8__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG8__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG8_MACRO__ */

/** @} end of patch_tag8 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag9 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag9 patch_tag9
 * @brief Contains register fields associated with patch_tag9. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG9_MACRO__
#define __AT_PRRF_PATCH_TAG9_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG9__ADDR__SHIFT                                       0
#define AT_PRRF_PATCH_TAG9__ADDR__WIDTH                                      22
#define AT_PRRF_PATCH_TAG9__ADDR__MASK                              0x003fffffU
#define AT_PRRF_PATCH_TAG9__ADDR__READ(src)     ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG9__ADDR__WRITE(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG9__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG9__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG9__ADDR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG9__NWORD__SHIFT                                     30
#define AT_PRRF_PATCH_TAG9__NWORD__WIDTH                                      2
#define AT_PRRF_PATCH_TAG9__NWORD__MASK                             0xc0000000U
#define AT_PRRF_PATCH_TAG9__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG9__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG9__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG9__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG9__NWORD__RESET_VALUE                      0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG9__TYPE                                       uint32_t
#define AT_PRRF_PATCH_TAG9__READ                                    0xc03fffffU
#define AT_PRRF_PATCH_TAG9__WRITE                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG9__PRESERVED                               0x00000000U
#define AT_PRRF_PATCH_TAG9__RESET_VALUE                             0x00000000U

#endif /* __AT_PRRF_PATCH_TAG9_MACRO__ */

/** @} end of patch_tag9 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag10 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag10 patch_tag10
 * @brief Contains register fields associated with patch_tag10. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG10_MACRO__
#define __AT_PRRF_PATCH_TAG10_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG10__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG10__ADDR__WIDTH                                     22
#define AT_PRRF_PATCH_TAG10__ADDR__MASK                             0x003fffffU
#define AT_PRRF_PATCH_TAG10__ADDR__READ(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG10__ADDR__WRITE(src)   ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG10__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG10__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG10__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG10__NWORD__SHIFT                                    30
#define AT_PRRF_PATCH_TAG10__NWORD__WIDTH                                     2
#define AT_PRRF_PATCH_TAG10__NWORD__MASK                            0xc0000000U
#define AT_PRRF_PATCH_TAG10__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG10__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG10__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG10__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG10__NWORD__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG10__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG10__READ                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG10__WRITE                                  0xc03fffffU
#define AT_PRRF_PATCH_TAG10__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG10__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG10_MACRO__ */

/** @} end of patch_tag10 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag11 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag11 patch_tag11
 * @brief Contains register fields associated with patch_tag11. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG11_MACRO__
#define __AT_PRRF_PATCH_TAG11_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG11__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG11__ADDR__WIDTH                                     22
#define AT_PRRF_PATCH_TAG11__ADDR__MASK                             0x003fffffU
#define AT_PRRF_PATCH_TAG11__ADDR__READ(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG11__ADDR__WRITE(src)   ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG11__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG11__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG11__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG11__NWORD__SHIFT                                    30
#define AT_PRRF_PATCH_TAG11__NWORD__WIDTH                                     2
#define AT_PRRF_PATCH_TAG11__NWORD__MASK                            0xc0000000U
#define AT_PRRF_PATCH_TAG11__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG11__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG11__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG11__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG11__NWORD__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG11__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG11__READ                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG11__WRITE                                  0xc03fffffU
#define AT_PRRF_PATCH_TAG11__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG11__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG11_MACRO__ */

/** @} end of patch_tag11 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag12 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag12 patch_tag12
 * @brief Contains register fields associated with patch_tag12. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG12_MACRO__
#define __AT_PRRF_PATCH_TAG12_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG12__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG12__ADDR__WIDTH                                     22
#define AT_PRRF_PATCH_TAG12__ADDR__MASK                             0x003fffffU
#define AT_PRRF_PATCH_TAG12__ADDR__READ(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG12__ADDR__WRITE(src)   ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG12__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG12__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG12__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG12__NWORD__SHIFT                                    30
#define AT_PRRF_PATCH_TAG12__NWORD__WIDTH                                     2
#define AT_PRRF_PATCH_TAG12__NWORD__MASK                            0xc0000000U
#define AT_PRRF_PATCH_TAG12__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG12__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG12__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG12__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG12__NWORD__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG12__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG12__READ                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG12__WRITE                                  0xc03fffffU
#define AT_PRRF_PATCH_TAG12__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG12__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG12_MACRO__ */

/** @} end of patch_tag12 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag13 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag13 patch_tag13
 * @brief Contains register fields associated with patch_tag13. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG13_MACRO__
#define __AT_PRRF_PATCH_TAG13_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG13__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG13__ADDR__WIDTH                                     22
#define AT_PRRF_PATCH_TAG13__ADDR__MASK                             0x003fffffU
#define AT_PRRF_PATCH_TAG13__ADDR__READ(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG13__ADDR__WRITE(src)   ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG13__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG13__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG13__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG13__NWORD__SHIFT                                    30
#define AT_PRRF_PATCH_TAG13__NWORD__WIDTH                                     2
#define AT_PRRF_PATCH_TAG13__NWORD__MASK                            0xc0000000U
#define AT_PRRF_PATCH_TAG13__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG13__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG13__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG13__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG13__NWORD__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG13__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG13__READ                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG13__WRITE                                  0xc03fffffU
#define AT_PRRF_PATCH_TAG13__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG13__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG13_MACRO__ */

/** @} end of patch_tag13 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag14 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag14 patch_tag14
 * @brief Contains register fields associated with patch_tag14. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG14_MACRO__
#define __AT_PRRF_PATCH_TAG14_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG14__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG14__ADDR__WIDTH                                     22
#define AT_PRRF_PATCH_TAG14__ADDR__MASK                             0x003fffffU
#define AT_PRRF_PATCH_TAG14__ADDR__READ(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG14__ADDR__WRITE(src)   ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG14__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG14__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG14__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG14__NWORD__SHIFT                                    30
#define AT_PRRF_PATCH_TAG14__NWORD__WIDTH                                     2
#define AT_PRRF_PATCH_TAG14__NWORD__MASK                            0xc0000000U
#define AT_PRRF_PATCH_TAG14__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG14__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG14__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG14__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG14__NWORD__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG14__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG14__READ                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG14__WRITE                                  0xc03fffffU
#define AT_PRRF_PATCH_TAG14__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG14__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG14_MACRO__ */

/** @} end of patch_tag14 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch_tag15 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch_tag15 patch_tag15
 * @brief Contains register fields associated with patch_tag15. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH_TAG15_MACRO__
#define __AT_PRRF_PATCH_TAG15_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_prrf_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @{
 */
#define AT_PRRF_PATCH_TAG15__ADDR__SHIFT                                      0
#define AT_PRRF_PATCH_TAG15__ADDR__WIDTH                                     22
#define AT_PRRF_PATCH_TAG15__ADDR__MASK                             0x003fffffU
#define AT_PRRF_PATCH_TAG15__ADDR__READ(src)    ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG15__ADDR__WRITE(src)   ((uint32_t)(src) & 0x003fffffU)
#define AT_PRRF_PATCH_TAG15__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define AT_PRRF_PATCH_TAG15__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define AT_PRRF_PATCH_TAG15__ADDR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nword */
/**
 * @defgroup at_ahb_prrf_regs_core_nword_field nword_field
 * @brief macros for field nword
 * @{
 */
#define AT_PRRF_PATCH_TAG15__NWORD__SHIFT                                    30
#define AT_PRRF_PATCH_TAG15__NWORD__WIDTH                                     2
#define AT_PRRF_PATCH_TAG15__NWORD__MASK                            0xc0000000U
#define AT_PRRF_PATCH_TAG15__NWORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define AT_PRRF_PATCH_TAG15__NWORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG15__NWORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define AT_PRRF_PATCH_TAG15__NWORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define AT_PRRF_PATCH_TAG15__NWORD__RESET_VALUE                     0x00000000U
/** @} */
#define AT_PRRF_PATCH_TAG15__TYPE                                      uint32_t
#define AT_PRRF_PATCH_TAG15__READ                                   0xc03fffffU
#define AT_PRRF_PATCH_TAG15__WRITE                                  0xc03fffffU
#define AT_PRRF_PATCH_TAG15__PRESERVED                              0x00000000U
#define AT_PRRF_PATCH_TAG15__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_PATCH_TAG15_MACRO__ */

/** @} end of patch_tag15 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch0 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch0 patch0
 * @brief Contains register fields associated with patch0. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH0_MACRO__
#define __AT_PRRF_PATCH0_MACRO__

/* macros for field patch0 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch0_field patch0_field
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
 * @defgroup at_ahb_prrf_regs_core_patch1 patch1
 * @brief Contains register fields associated with patch1. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH1_MACRO__
#define __AT_PRRF_PATCH1_MACRO__

/* macros for field patch1 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch1_field patch1_field
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
 * @defgroup at_ahb_prrf_regs_core_patch2 patch2
 * @brief Contains register fields associated with patch2. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH2_MACRO__
#define __AT_PRRF_PATCH2_MACRO__

/* macros for field patch2 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch2_field patch2_field
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
 * @defgroup at_ahb_prrf_regs_core_patch3 patch3
 * @brief Contains register fields associated with patch3. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH3_MACRO__
#define __AT_PRRF_PATCH3_MACRO__

/* macros for field patch3 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch3_field patch3_field
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
 * @defgroup at_ahb_prrf_regs_core_patch4 patch4
 * @brief Contains register fields associated with patch4. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH4_MACRO__
#define __AT_PRRF_PATCH4_MACRO__

/* macros for field patch4 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch4_field patch4_field
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
 * @defgroup at_ahb_prrf_regs_core_patch5 patch5
 * @brief Contains register fields associated with patch5. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH5_MACRO__
#define __AT_PRRF_PATCH5_MACRO__

/* macros for field patch5 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch5_field patch5_field
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
 * @defgroup at_ahb_prrf_regs_core_patch6 patch6
 * @brief Contains register fields associated with patch6. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH6_MACRO__
#define __AT_PRRF_PATCH6_MACRO__

/* macros for field patch6 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch6_field patch6_field
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
 * @defgroup at_ahb_prrf_regs_core_patch7 patch7
 * @brief Contains register fields associated with patch7. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH7_MACRO__
#define __AT_PRRF_PATCH7_MACRO__

/* macros for field patch7 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch7_field patch7_field
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
 * @defgroup at_ahb_prrf_regs_core_patch8 patch8
 * @brief Contains register fields associated with patch8. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH8_MACRO__
#define __AT_PRRF_PATCH8_MACRO__

/* macros for field patch8 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch8_field patch8_field
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
 * @defgroup at_ahb_prrf_regs_core_patch9 patch9
 * @brief Contains register fields associated with patch9. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH9_MACRO__
#define __AT_PRRF_PATCH9_MACRO__

/* macros for field patch9 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch9_field patch9_field
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
 * @defgroup at_ahb_prrf_regs_core_patch10 patch10
 * @brief Contains register fields associated with patch10. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH10_MACRO__
#define __AT_PRRF_PATCH10_MACRO__

/* macros for field patch10 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch10_field patch10_field
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
 * @defgroup at_ahb_prrf_regs_core_patch11 patch11
 * @brief Contains register fields associated with patch11. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH11_MACRO__
#define __AT_PRRF_PATCH11_MACRO__

/* macros for field patch11 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch11_field patch11_field
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
 * @defgroup at_ahb_prrf_regs_core_patch12 patch12
 * @brief Contains register fields associated with patch12. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH12_MACRO__
#define __AT_PRRF_PATCH12_MACRO__

/* macros for field patch12 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch12_field patch12_field
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
 * @defgroup at_ahb_prrf_regs_core_patch13 patch13
 * @brief Contains register fields associated with patch13. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH13_MACRO__
#define __AT_PRRF_PATCH13_MACRO__

/* macros for field patch13 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch13_field patch13_field
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
 * @defgroup at_ahb_prrf_regs_core_patch14 patch14
 * @brief Contains register fields associated with patch14. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH14_MACRO__
#define __AT_PRRF_PATCH14_MACRO__

/* macros for field patch14 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch14_field patch14_field
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
 * @defgroup at_ahb_prrf_regs_core_patch15 patch15
 * @brief Contains register fields associated with patch15. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH15_MACRO__
#define __AT_PRRF_PATCH15_MACRO__

/* macros for field patch15 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch15_field patch15_field
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

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch16 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch16 patch16
 * @brief Contains register fields associated with patch16. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH16_MACRO__
#define __AT_PRRF_PATCH16_MACRO__

/* macros for field patch16 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch16_field patch16_field
 * @brief macros for field patch16
 * @{
 */
#define AT_PRRF_PATCH16__PATCH16__SHIFT                                       0
#define AT_PRRF_PATCH16__PATCH16__WIDTH                                      32
#define AT_PRRF_PATCH16__PATCH16__MASK                              0xffffffffU
#define AT_PRRF_PATCH16__PATCH16__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH16__PATCH16__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH16__PATCH16__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH16__PATCH16__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH16__PATCH16__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH16__TYPE                                          uint32_t
#define AT_PRRF_PATCH16__READ                                       0xffffffffU
#define AT_PRRF_PATCH16__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH16__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH16__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH16_MACRO__ */

/** @} end of patch16 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch17 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch17 patch17
 * @brief Contains register fields associated with patch17. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH17_MACRO__
#define __AT_PRRF_PATCH17_MACRO__

/* macros for field patch17 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch17_field patch17_field
 * @brief macros for field patch17
 * @{
 */
#define AT_PRRF_PATCH17__PATCH17__SHIFT                                       0
#define AT_PRRF_PATCH17__PATCH17__WIDTH                                      32
#define AT_PRRF_PATCH17__PATCH17__MASK                              0xffffffffU
#define AT_PRRF_PATCH17__PATCH17__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH17__PATCH17__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH17__PATCH17__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH17__PATCH17__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH17__PATCH17__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH17__TYPE                                          uint32_t
#define AT_PRRF_PATCH17__READ                                       0xffffffffU
#define AT_PRRF_PATCH17__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH17__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH17__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH17_MACRO__ */

/** @} end of patch17 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch18 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch18 patch18
 * @brief Contains register fields associated with patch18. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH18_MACRO__
#define __AT_PRRF_PATCH18_MACRO__

/* macros for field patch18 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch18_field patch18_field
 * @brief macros for field patch18
 * @{
 */
#define AT_PRRF_PATCH18__PATCH18__SHIFT                                       0
#define AT_PRRF_PATCH18__PATCH18__WIDTH                                      32
#define AT_PRRF_PATCH18__PATCH18__MASK                              0xffffffffU
#define AT_PRRF_PATCH18__PATCH18__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH18__PATCH18__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH18__PATCH18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH18__PATCH18__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH18__PATCH18__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH18__TYPE                                          uint32_t
#define AT_PRRF_PATCH18__READ                                       0xffffffffU
#define AT_PRRF_PATCH18__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH18__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH18__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH18_MACRO__ */

/** @} end of patch18 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch19 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch19 patch19
 * @brief Contains register fields associated with patch19. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH19_MACRO__
#define __AT_PRRF_PATCH19_MACRO__

/* macros for field patch19 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch19_field patch19_field
 * @brief macros for field patch19
 * @{
 */
#define AT_PRRF_PATCH19__PATCH19__SHIFT                                       0
#define AT_PRRF_PATCH19__PATCH19__WIDTH                                      32
#define AT_PRRF_PATCH19__PATCH19__MASK                              0xffffffffU
#define AT_PRRF_PATCH19__PATCH19__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH19__PATCH19__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH19__PATCH19__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH19__PATCH19__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH19__PATCH19__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH19__TYPE                                          uint32_t
#define AT_PRRF_PATCH19__READ                                       0xffffffffU
#define AT_PRRF_PATCH19__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH19__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH19__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH19_MACRO__ */

/** @} end of patch19 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch20 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch20 patch20
 * @brief Contains register fields associated with patch20. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH20_MACRO__
#define __AT_PRRF_PATCH20_MACRO__

/* macros for field patch20 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch20_field patch20_field
 * @brief macros for field patch20
 * @{
 */
#define AT_PRRF_PATCH20__PATCH20__SHIFT                                       0
#define AT_PRRF_PATCH20__PATCH20__WIDTH                                      32
#define AT_PRRF_PATCH20__PATCH20__MASK                              0xffffffffU
#define AT_PRRF_PATCH20__PATCH20__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH20__PATCH20__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH20__PATCH20__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH20__PATCH20__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH20__PATCH20__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH20__TYPE                                          uint32_t
#define AT_PRRF_PATCH20__READ                                       0xffffffffU
#define AT_PRRF_PATCH20__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH20__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH20__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH20_MACRO__ */

/** @} end of patch20 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch21 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch21 patch21
 * @brief Contains register fields associated with patch21. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH21_MACRO__
#define __AT_PRRF_PATCH21_MACRO__

/* macros for field patch21 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch21_field patch21_field
 * @brief macros for field patch21
 * @{
 */
#define AT_PRRF_PATCH21__PATCH21__SHIFT                                       0
#define AT_PRRF_PATCH21__PATCH21__WIDTH                                      32
#define AT_PRRF_PATCH21__PATCH21__MASK                              0xffffffffU
#define AT_PRRF_PATCH21__PATCH21__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH21__PATCH21__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH21__PATCH21__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH21__PATCH21__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH21__PATCH21__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH21__TYPE                                          uint32_t
#define AT_PRRF_PATCH21__READ                                       0xffffffffU
#define AT_PRRF_PATCH21__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH21__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH21__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH21_MACRO__ */

/** @} end of patch21 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch22 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch22 patch22
 * @brief Contains register fields associated with patch22. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH22_MACRO__
#define __AT_PRRF_PATCH22_MACRO__

/* macros for field patch22 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch22_field patch22_field
 * @brief macros for field patch22
 * @{
 */
#define AT_PRRF_PATCH22__PATCH22__SHIFT                                       0
#define AT_PRRF_PATCH22__PATCH22__WIDTH                                      32
#define AT_PRRF_PATCH22__PATCH22__MASK                              0xffffffffU
#define AT_PRRF_PATCH22__PATCH22__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH22__PATCH22__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH22__PATCH22__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH22__PATCH22__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH22__PATCH22__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH22__TYPE                                          uint32_t
#define AT_PRRF_PATCH22__READ                                       0xffffffffU
#define AT_PRRF_PATCH22__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH22__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH22__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH22_MACRO__ */

/** @} end of patch22 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch23 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch23 patch23
 * @brief Contains register fields associated with patch23. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH23_MACRO__
#define __AT_PRRF_PATCH23_MACRO__

/* macros for field patch23 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch23_field patch23_field
 * @brief macros for field patch23
 * @{
 */
#define AT_PRRF_PATCH23__PATCH23__SHIFT                                       0
#define AT_PRRF_PATCH23__PATCH23__WIDTH                                      32
#define AT_PRRF_PATCH23__PATCH23__MASK                              0xffffffffU
#define AT_PRRF_PATCH23__PATCH23__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH23__PATCH23__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH23__PATCH23__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH23__PATCH23__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH23__PATCH23__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH23__TYPE                                          uint32_t
#define AT_PRRF_PATCH23__READ                                       0xffffffffU
#define AT_PRRF_PATCH23__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH23__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH23__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH23_MACRO__ */

/** @} end of patch23 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch24 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch24 patch24
 * @brief Contains register fields associated with patch24. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH24_MACRO__
#define __AT_PRRF_PATCH24_MACRO__

/* macros for field patch24 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch24_field patch24_field
 * @brief macros for field patch24
 * @{
 */
#define AT_PRRF_PATCH24__PATCH24__SHIFT                                       0
#define AT_PRRF_PATCH24__PATCH24__WIDTH                                      32
#define AT_PRRF_PATCH24__PATCH24__MASK                              0xffffffffU
#define AT_PRRF_PATCH24__PATCH24__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH24__PATCH24__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH24__PATCH24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH24__PATCH24__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH24__PATCH24__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH24__TYPE                                          uint32_t
#define AT_PRRF_PATCH24__READ                                       0xffffffffU
#define AT_PRRF_PATCH24__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH24__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH24__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH24_MACRO__ */

/** @} end of patch24 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch25 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch25 patch25
 * @brief Contains register fields associated with patch25. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH25_MACRO__
#define __AT_PRRF_PATCH25_MACRO__

/* macros for field patch25 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch25_field patch25_field
 * @brief macros for field patch25
 * @{
 */
#define AT_PRRF_PATCH25__PATCH25__SHIFT                                       0
#define AT_PRRF_PATCH25__PATCH25__WIDTH                                      32
#define AT_PRRF_PATCH25__PATCH25__MASK                              0xffffffffU
#define AT_PRRF_PATCH25__PATCH25__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH25__PATCH25__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH25__PATCH25__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH25__PATCH25__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH25__PATCH25__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH25__TYPE                                          uint32_t
#define AT_PRRF_PATCH25__READ                                       0xffffffffU
#define AT_PRRF_PATCH25__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH25__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH25__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH25_MACRO__ */

/** @} end of patch25 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch26 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch26 patch26
 * @brief Contains register fields associated with patch26. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH26_MACRO__
#define __AT_PRRF_PATCH26_MACRO__

/* macros for field patch26 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch26_field patch26_field
 * @brief macros for field patch26
 * @{
 */
#define AT_PRRF_PATCH26__PATCH26__SHIFT                                       0
#define AT_PRRF_PATCH26__PATCH26__WIDTH                                      32
#define AT_PRRF_PATCH26__PATCH26__MASK                              0xffffffffU
#define AT_PRRF_PATCH26__PATCH26__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH26__PATCH26__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH26__PATCH26__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH26__PATCH26__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH26__PATCH26__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH26__TYPE                                          uint32_t
#define AT_PRRF_PATCH26__READ                                       0xffffffffU
#define AT_PRRF_PATCH26__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH26__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH26__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH26_MACRO__ */

/** @} end of patch26 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch27 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch27 patch27
 * @brief Contains register fields associated with patch27. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH27_MACRO__
#define __AT_PRRF_PATCH27_MACRO__

/* macros for field patch27 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch27_field patch27_field
 * @brief macros for field patch27
 * @{
 */
#define AT_PRRF_PATCH27__PATCH27__SHIFT                                       0
#define AT_PRRF_PATCH27__PATCH27__WIDTH                                      32
#define AT_PRRF_PATCH27__PATCH27__MASK                              0xffffffffU
#define AT_PRRF_PATCH27__PATCH27__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH27__PATCH27__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH27__PATCH27__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH27__PATCH27__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH27__PATCH27__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH27__TYPE                                          uint32_t
#define AT_PRRF_PATCH27__READ                                       0xffffffffU
#define AT_PRRF_PATCH27__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH27__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH27__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH27_MACRO__ */

/** @} end of patch27 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch28 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch28 patch28
 * @brief Contains register fields associated with patch28. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH28_MACRO__
#define __AT_PRRF_PATCH28_MACRO__

/* macros for field patch28 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch28_field patch28_field
 * @brief macros for field patch28
 * @{
 */
#define AT_PRRF_PATCH28__PATCH28__SHIFT                                       0
#define AT_PRRF_PATCH28__PATCH28__WIDTH                                      32
#define AT_PRRF_PATCH28__PATCH28__MASK                              0xffffffffU
#define AT_PRRF_PATCH28__PATCH28__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH28__PATCH28__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH28__PATCH28__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH28__PATCH28__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH28__PATCH28__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH28__TYPE                                          uint32_t
#define AT_PRRF_PATCH28__READ                                       0xffffffffU
#define AT_PRRF_PATCH28__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH28__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH28__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH28_MACRO__ */

/** @} end of patch28 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch29 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch29 patch29
 * @brief Contains register fields associated with patch29. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH29_MACRO__
#define __AT_PRRF_PATCH29_MACRO__

/* macros for field patch29 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch29_field patch29_field
 * @brief macros for field patch29
 * @{
 */
#define AT_PRRF_PATCH29__PATCH29__SHIFT                                       0
#define AT_PRRF_PATCH29__PATCH29__WIDTH                                      32
#define AT_PRRF_PATCH29__PATCH29__MASK                              0xffffffffU
#define AT_PRRF_PATCH29__PATCH29__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH29__PATCH29__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH29__PATCH29__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH29__PATCH29__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH29__PATCH29__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH29__TYPE                                          uint32_t
#define AT_PRRF_PATCH29__READ                                       0xffffffffU
#define AT_PRRF_PATCH29__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH29__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH29__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH29_MACRO__ */

/** @} end of patch29 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch30 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch30 patch30
 * @brief Contains register fields associated with patch30. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH30_MACRO__
#define __AT_PRRF_PATCH30_MACRO__

/* macros for field patch30 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch30_field patch30_field
 * @brief macros for field patch30
 * @{
 */
#define AT_PRRF_PATCH30__PATCH30__SHIFT                                       0
#define AT_PRRF_PATCH30__PATCH30__WIDTH                                      32
#define AT_PRRF_PATCH30__PATCH30__MASK                              0xffffffffU
#define AT_PRRF_PATCH30__PATCH30__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH30__PATCH30__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH30__PATCH30__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH30__PATCH30__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH30__PATCH30__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH30__TYPE                                          uint32_t
#define AT_PRRF_PATCH30__READ                                       0xffffffffU
#define AT_PRRF_PATCH30__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH30__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH30__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH30_MACRO__ */

/** @} end of patch30 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch31 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch31 patch31
 * @brief Contains register fields associated with patch31. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH31_MACRO__
#define __AT_PRRF_PATCH31_MACRO__

/* macros for field patch31 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch31_field patch31_field
 * @brief macros for field patch31
 * @{
 */
#define AT_PRRF_PATCH31__PATCH31__SHIFT                                       0
#define AT_PRRF_PATCH31__PATCH31__WIDTH                                      32
#define AT_PRRF_PATCH31__PATCH31__MASK                              0xffffffffU
#define AT_PRRF_PATCH31__PATCH31__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH31__PATCH31__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH31__PATCH31__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH31__PATCH31__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH31__PATCH31__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH31__TYPE                                          uint32_t
#define AT_PRRF_PATCH31__READ                                       0xffffffffU
#define AT_PRRF_PATCH31__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH31__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH31__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH31_MACRO__ */

/** @} end of patch31 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch32 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch32 patch32
 * @brief Contains register fields associated with patch32. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH32_MACRO__
#define __AT_PRRF_PATCH32_MACRO__

/* macros for field patch32 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch32_field patch32_field
 * @brief macros for field patch32
 * @{
 */
#define AT_PRRF_PATCH32__PATCH32__SHIFT                                       0
#define AT_PRRF_PATCH32__PATCH32__WIDTH                                      32
#define AT_PRRF_PATCH32__PATCH32__MASK                              0xffffffffU
#define AT_PRRF_PATCH32__PATCH32__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH32__PATCH32__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH32__PATCH32__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH32__PATCH32__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH32__PATCH32__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH32__TYPE                                          uint32_t
#define AT_PRRF_PATCH32__READ                                       0xffffffffU
#define AT_PRRF_PATCH32__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH32__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH32__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH32_MACRO__ */

/** @} end of patch32 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch33 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch33 patch33
 * @brief Contains register fields associated with patch33. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH33_MACRO__
#define __AT_PRRF_PATCH33_MACRO__

/* macros for field patch33 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch33_field patch33_field
 * @brief macros for field patch33
 * @{
 */
#define AT_PRRF_PATCH33__PATCH33__SHIFT                                       0
#define AT_PRRF_PATCH33__PATCH33__WIDTH                                      32
#define AT_PRRF_PATCH33__PATCH33__MASK                              0xffffffffU
#define AT_PRRF_PATCH33__PATCH33__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH33__PATCH33__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH33__PATCH33__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH33__PATCH33__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH33__PATCH33__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH33__TYPE                                          uint32_t
#define AT_PRRF_PATCH33__READ                                       0xffffffffU
#define AT_PRRF_PATCH33__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH33__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH33__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH33_MACRO__ */

/** @} end of patch33 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch34 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch34 patch34
 * @brief Contains register fields associated with patch34. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH34_MACRO__
#define __AT_PRRF_PATCH34_MACRO__

/* macros for field patch34 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch34_field patch34_field
 * @brief macros for field patch34
 * @{
 */
#define AT_PRRF_PATCH34__PATCH34__SHIFT                                       0
#define AT_PRRF_PATCH34__PATCH34__WIDTH                                      32
#define AT_PRRF_PATCH34__PATCH34__MASK                              0xffffffffU
#define AT_PRRF_PATCH34__PATCH34__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH34__PATCH34__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH34__PATCH34__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH34__PATCH34__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH34__PATCH34__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH34__TYPE                                          uint32_t
#define AT_PRRF_PATCH34__READ                                       0xffffffffU
#define AT_PRRF_PATCH34__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH34__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH34__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH34_MACRO__ */

/** @} end of patch34 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch35 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch35 patch35
 * @brief Contains register fields associated with patch35. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH35_MACRO__
#define __AT_PRRF_PATCH35_MACRO__

/* macros for field patch35 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch35_field patch35_field
 * @brief macros for field patch35
 * @{
 */
#define AT_PRRF_PATCH35__PATCH35__SHIFT                                       0
#define AT_PRRF_PATCH35__PATCH35__WIDTH                                      32
#define AT_PRRF_PATCH35__PATCH35__MASK                              0xffffffffU
#define AT_PRRF_PATCH35__PATCH35__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH35__PATCH35__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH35__PATCH35__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH35__PATCH35__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH35__PATCH35__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH35__TYPE                                          uint32_t
#define AT_PRRF_PATCH35__READ                                       0xffffffffU
#define AT_PRRF_PATCH35__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH35__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH35__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH35_MACRO__ */

/** @} end of patch35 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch36 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch36 patch36
 * @brief Contains register fields associated with patch36. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH36_MACRO__
#define __AT_PRRF_PATCH36_MACRO__

/* macros for field patch36 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch36_field patch36_field
 * @brief macros for field patch36
 * @{
 */
#define AT_PRRF_PATCH36__PATCH36__SHIFT                                       0
#define AT_PRRF_PATCH36__PATCH36__WIDTH                                      32
#define AT_PRRF_PATCH36__PATCH36__MASK                              0xffffffffU
#define AT_PRRF_PATCH36__PATCH36__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH36__PATCH36__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH36__PATCH36__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH36__PATCH36__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH36__PATCH36__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH36__TYPE                                          uint32_t
#define AT_PRRF_PATCH36__READ                                       0xffffffffU
#define AT_PRRF_PATCH36__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH36__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH36__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH36_MACRO__ */

/** @} end of patch36 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch37 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch37 patch37
 * @brief Contains register fields associated with patch37. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH37_MACRO__
#define __AT_PRRF_PATCH37_MACRO__

/* macros for field patch37 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch37_field patch37_field
 * @brief macros for field patch37
 * @{
 */
#define AT_PRRF_PATCH37__PATCH37__SHIFT                                       0
#define AT_PRRF_PATCH37__PATCH37__WIDTH                                      32
#define AT_PRRF_PATCH37__PATCH37__MASK                              0xffffffffU
#define AT_PRRF_PATCH37__PATCH37__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH37__PATCH37__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH37__PATCH37__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH37__PATCH37__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH37__PATCH37__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH37__TYPE                                          uint32_t
#define AT_PRRF_PATCH37__READ                                       0xffffffffU
#define AT_PRRF_PATCH37__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH37__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH37__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH37_MACRO__ */

/** @} end of patch37 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch38 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch38 patch38
 * @brief Contains register fields associated with patch38. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH38_MACRO__
#define __AT_PRRF_PATCH38_MACRO__

/* macros for field patch38 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch38_field patch38_field
 * @brief macros for field patch38
 * @{
 */
#define AT_PRRF_PATCH38__PATCH38__SHIFT                                       0
#define AT_PRRF_PATCH38__PATCH38__WIDTH                                      32
#define AT_PRRF_PATCH38__PATCH38__MASK                              0xffffffffU
#define AT_PRRF_PATCH38__PATCH38__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH38__PATCH38__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH38__PATCH38__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH38__PATCH38__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH38__PATCH38__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH38__TYPE                                          uint32_t
#define AT_PRRF_PATCH38__READ                                       0xffffffffU
#define AT_PRRF_PATCH38__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH38__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH38__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH38_MACRO__ */

/** @} end of patch38 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch39 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch39 patch39
 * @brief Contains register fields associated with patch39. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH39_MACRO__
#define __AT_PRRF_PATCH39_MACRO__

/* macros for field patch39 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch39_field patch39_field
 * @brief macros for field patch39
 * @{
 */
#define AT_PRRF_PATCH39__PATCH39__SHIFT                                       0
#define AT_PRRF_PATCH39__PATCH39__WIDTH                                      32
#define AT_PRRF_PATCH39__PATCH39__MASK                              0xffffffffU
#define AT_PRRF_PATCH39__PATCH39__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH39__PATCH39__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH39__PATCH39__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH39__PATCH39__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH39__PATCH39__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH39__TYPE                                          uint32_t
#define AT_PRRF_PATCH39__READ                                       0xffffffffU
#define AT_PRRF_PATCH39__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH39__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH39__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH39_MACRO__ */

/** @} end of patch39 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch40 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch40 patch40
 * @brief Contains register fields associated with patch40. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH40_MACRO__
#define __AT_PRRF_PATCH40_MACRO__

/* macros for field patch40 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch40_field patch40_field
 * @brief macros for field patch40
 * @{
 */
#define AT_PRRF_PATCH40__PATCH40__SHIFT                                       0
#define AT_PRRF_PATCH40__PATCH40__WIDTH                                      32
#define AT_PRRF_PATCH40__PATCH40__MASK                              0xffffffffU
#define AT_PRRF_PATCH40__PATCH40__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH40__PATCH40__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH40__PATCH40__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH40__PATCH40__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH40__PATCH40__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH40__TYPE                                          uint32_t
#define AT_PRRF_PATCH40__READ                                       0xffffffffU
#define AT_PRRF_PATCH40__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH40__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH40__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH40_MACRO__ */

/** @} end of patch40 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch41 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch41 patch41
 * @brief Contains register fields associated with patch41. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH41_MACRO__
#define __AT_PRRF_PATCH41_MACRO__

/* macros for field patch41 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch41_field patch41_field
 * @brief macros for field patch41
 * @{
 */
#define AT_PRRF_PATCH41__PATCH41__SHIFT                                       0
#define AT_PRRF_PATCH41__PATCH41__WIDTH                                      32
#define AT_PRRF_PATCH41__PATCH41__MASK                              0xffffffffU
#define AT_PRRF_PATCH41__PATCH41__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH41__PATCH41__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH41__PATCH41__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH41__PATCH41__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH41__PATCH41__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH41__TYPE                                          uint32_t
#define AT_PRRF_PATCH41__READ                                       0xffffffffU
#define AT_PRRF_PATCH41__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH41__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH41__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH41_MACRO__ */

/** @} end of patch41 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch42 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch42 patch42
 * @brief Contains register fields associated with patch42. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH42_MACRO__
#define __AT_PRRF_PATCH42_MACRO__

/* macros for field patch42 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch42_field patch42_field
 * @brief macros for field patch42
 * @{
 */
#define AT_PRRF_PATCH42__PATCH42__SHIFT                                       0
#define AT_PRRF_PATCH42__PATCH42__WIDTH                                      32
#define AT_PRRF_PATCH42__PATCH42__MASK                              0xffffffffU
#define AT_PRRF_PATCH42__PATCH42__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH42__PATCH42__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH42__PATCH42__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH42__PATCH42__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH42__PATCH42__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH42__TYPE                                          uint32_t
#define AT_PRRF_PATCH42__READ                                       0xffffffffU
#define AT_PRRF_PATCH42__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH42__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH42__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH42_MACRO__ */

/** @} end of patch42 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch43 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch43 patch43
 * @brief Contains register fields associated with patch43. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH43_MACRO__
#define __AT_PRRF_PATCH43_MACRO__

/* macros for field patch43 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch43_field patch43_field
 * @brief macros for field patch43
 * @{
 */
#define AT_PRRF_PATCH43__PATCH43__SHIFT                                       0
#define AT_PRRF_PATCH43__PATCH43__WIDTH                                      32
#define AT_PRRF_PATCH43__PATCH43__MASK                              0xffffffffU
#define AT_PRRF_PATCH43__PATCH43__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH43__PATCH43__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH43__PATCH43__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH43__PATCH43__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH43__PATCH43__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH43__TYPE                                          uint32_t
#define AT_PRRF_PATCH43__READ                                       0xffffffffU
#define AT_PRRF_PATCH43__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH43__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH43__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH43_MACRO__ */

/** @} end of patch43 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch44 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch44 patch44
 * @brief Contains register fields associated with patch44. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH44_MACRO__
#define __AT_PRRF_PATCH44_MACRO__

/* macros for field patch44 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch44_field patch44_field
 * @brief macros for field patch44
 * @{
 */
#define AT_PRRF_PATCH44__PATCH44__SHIFT                                       0
#define AT_PRRF_PATCH44__PATCH44__WIDTH                                      32
#define AT_PRRF_PATCH44__PATCH44__MASK                              0xffffffffU
#define AT_PRRF_PATCH44__PATCH44__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH44__PATCH44__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH44__PATCH44__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH44__PATCH44__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH44__PATCH44__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH44__TYPE                                          uint32_t
#define AT_PRRF_PATCH44__READ                                       0xffffffffU
#define AT_PRRF_PATCH44__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH44__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH44__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH44_MACRO__ */

/** @} end of patch44 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch45 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch45 patch45
 * @brief Contains register fields associated with patch45. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH45_MACRO__
#define __AT_PRRF_PATCH45_MACRO__

/* macros for field patch45 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch45_field patch45_field
 * @brief macros for field patch45
 * @{
 */
#define AT_PRRF_PATCH45__PATCH45__SHIFT                                       0
#define AT_PRRF_PATCH45__PATCH45__WIDTH                                      32
#define AT_PRRF_PATCH45__PATCH45__MASK                              0xffffffffU
#define AT_PRRF_PATCH45__PATCH45__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH45__PATCH45__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH45__PATCH45__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH45__PATCH45__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH45__PATCH45__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH45__TYPE                                          uint32_t
#define AT_PRRF_PATCH45__READ                                       0xffffffffU
#define AT_PRRF_PATCH45__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH45__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH45__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH45_MACRO__ */

/** @} end of patch45 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch46 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch46 patch46
 * @brief Contains register fields associated with patch46. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH46_MACRO__
#define __AT_PRRF_PATCH46_MACRO__

/* macros for field patch46 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch46_field patch46_field
 * @brief macros for field patch46
 * @{
 */
#define AT_PRRF_PATCH46__PATCH46__SHIFT                                       0
#define AT_PRRF_PATCH46__PATCH46__WIDTH                                      32
#define AT_PRRF_PATCH46__PATCH46__MASK                              0xffffffffU
#define AT_PRRF_PATCH46__PATCH46__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH46__PATCH46__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH46__PATCH46__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH46__PATCH46__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH46__PATCH46__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH46__TYPE                                          uint32_t
#define AT_PRRF_PATCH46__READ                                       0xffffffffU
#define AT_PRRF_PATCH46__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH46__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH46__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH46_MACRO__ */

/** @} end of patch46 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_patch47 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch47 patch47
 * @brief Contains register fields associated with patch47. definitions.
 * @{
 */
#ifndef __AT_PRRF_PATCH47_MACRO__
#define __AT_PRRF_PATCH47_MACRO__

/* macros for field patch47 */
/**
 * @defgroup at_ahb_prrf_regs_core_patch47_field patch47_field
 * @brief macros for field patch47
 * @{
 */
#define AT_PRRF_PATCH47__PATCH47__SHIFT                                       0
#define AT_PRRF_PATCH47__PATCH47__WIDTH                                      32
#define AT_PRRF_PATCH47__PATCH47__MASK                              0xffffffffU
#define AT_PRRF_PATCH47__PATCH47__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH47__PATCH47__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_PRRF_PATCH47__PATCH47__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_PRRF_PATCH47__PATCH47__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_PRRF_PATCH47__PATCH47__RESET_VALUE                       0x00000000U
/** @} */
#define AT_PRRF_PATCH47__TYPE                                          uint32_t
#define AT_PRRF_PATCH47__READ                                       0xffffffffU
#define AT_PRRF_PATCH47__WRITE                                      0xffffffffU
#define AT_PRRF_PATCH47__PRESERVED                                  0x00000000U
#define AT_PRRF_PATCH47__RESET_VALUE                                0x00000000U

#endif /* __AT_PRRF_PATCH47_MACRO__ */

/** @} end of patch47 */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_wrt_config_lo */
/**
 * @defgroup at_ahb_prrf_regs_core_rram_wrt_config_lo rram_wrt_config_lo
 * @brief Contains register fields associated with rram_wrt_config_lo. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_WRT_CONFIG_LO_MACRO__
#define __AT_PRRF_RRAM_WRT_CONFIG_LO_MACRO__

/* macros for field din */
/**
 * @defgroup at_ahb_prrf_regs_core_din_field din_field
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
 * @defgroup at_ahb_prrf_regs_core_rram_wrt_config_hi rram_wrt_config_hi
 * @brief Contains register fields associated with rram_wrt_config_hi. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_WRT_CONFIG_HI_MACRO__
#define __AT_PRRF_RRAM_WRT_CONFIG_HI_MACRO__

/* macros for field din */
/**
 * @defgroup at_ahb_prrf_regs_core_din_field din_field
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
 * @defgroup at_ahb_prrf_regs_core_rram_read_config_lo rram_read_config_lo
 * @brief Contains register fields associated with rram_read_config_lo. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_READ_CONFIG_LO_MACRO__
#define __AT_PRRF_RRAM_READ_CONFIG_LO_MACRO__

/* macros for field dout */
/**
 * @defgroup at_ahb_prrf_regs_core_dout_field dout_field
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
 * @defgroup at_ahb_prrf_regs_core_rram_read_config_hi rram_read_config_hi
 * @brief Contains register fields associated with rram_read_config_hi. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_READ_CONFIG_HI_MACRO__
#define __AT_PRRF_RRAM_READ_CONFIG_HI_MACRO__

/* macros for field dout */
/**
 * @defgroup at_ahb_prrf_regs_core_dout_field dout_field
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
 * @defgroup at_ahb_prrf_regs_core_rram_cache_config rram_cache_config
 * @brief Contains register fields associated with rram_cache_config. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_CACHE_CONFIG_MACRO__
#define __AT_PRRF_RRAM_CACHE_CONFIG_MACRO__

/* macros for field cache_mode */
/**
 * @defgroup at_ahb_prrf_regs_core_cache_mode_field cache_mode_field
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
 * @defgroup at_ahb_prrf_regs_core_enable_cache_field enable_cache_field
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
 * @defgroup at_ahb_prrf_regs_core_invalidate_cache_field invalidate_cache_field
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
 * @defgroup at_ahb_prrf_regs_core_enable_fine_clock_gating_field enable_fine_clock_gating_field
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
 * @defgroup at_ahb_prrf_regs_core_rram_mem_config rram_mem_config
 * @brief Contains register fields associated with rram_mem_config. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_MEM_CONFIG_MACRO__
#define __AT_PRRF_RRAM_MEM_CONFIG_MACRO__

/* macros for field rram_speedup_b */
/**
 * @defgroup at_ahb_prrf_regs_core_rram_speedup_b_field rram_speedup_b_field
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
 * @defgroup at_ahb_prrf_regs_core_trc_info_field trc_info_field
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
 * @defgroup at_ahb_prrf_regs_core_trc_lven_field trc_lven_field
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
 * @defgroup at_ahb_prrf_regs_core_trc_tin_field trc_tin_field
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
 * @defgroup at_ahb_prrf_regs_core_en_fine_ckg_field en_fine_ckg_field
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
#define AT_PRRF_RRAM_MEM_CONFIG__TYPE                                  uint32_t
#define AT_PRRF_RRAM_MEM_CONFIG__READ                               0x0007ffffU
#define AT_PRRF_RRAM_MEM_CONFIG__WRITE                              0x0007ffffU
#define AT_PRRF_RRAM_MEM_CONFIG__PRESERVED                          0x00000000U
#define AT_PRRF_RRAM_MEM_CONFIG__RESET_VALUE                        0x00000000U

#endif /* __AT_PRRF_RRAM_MEM_CONFIG_MACRO__ */

/** @} end of rram_mem_config */

/* macros for BlueprintGlobalNameSpace::AT_PRRF_rram_status */
/**
 * @defgroup at_ahb_prrf_regs_core_rram_status rram_status
 * @brief Contains register fields associated with rram_status. definitions.
 * @{
 */
#ifndef __AT_PRRF_RRAM_STATUS_MACRO__
#define __AT_PRRF_RRAM_STATUS_MACRO__

/* macros for field busy */
/**
 * @defgroup at_ahb_prrf_regs_core_busy_field busy_field
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
 * @defgroup at_ahb_prrf_regs_core_err_field err_field
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
#define AT_PRRF_RRAM_STATUS__TYPE                                      uint32_t
#define AT_PRRF_RRAM_STATUS__READ                                   0x00000003U
#define AT_PRRF_RRAM_STATUS__PRESERVED                              0x00000000U
#define AT_PRRF_RRAM_STATUS__RESET_VALUE                            0x00000000U

#endif /* __AT_PRRF_RRAM_STATUS_MACRO__ */

/** @} end of rram_status */

/** @} end of AT_AHB_PRRF_REGS_CORE */
#endif /* __REG_AT_AHB_PRRF_REGS_CORE_H__ */
