/*                                                                           */
/* File:       at_apb_slwtimer_regs_core_macro.h                             */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_slwtimer_regs_core.rdl      */
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


#ifndef __REG_AT_APB_SLWTIMER_REGS_CORE_H__
#define __REG_AT_APB_SLWTIMER_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_SLWTIMER_REGS_CORE at_apb_slwtimer_regs_core
 * @ingroup AT_REG
 * @brief at_apb_slwtimer_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::SLW_control */
/**
 * @defgroup at_apb_slwtimer_regs_core_control control
 * @brief control definitions.
 * @{
 */
#ifndef __SLW_CONTROL_MACRO__
#define __SLW_CONTROL_MACRO__

/* macros for field clear */
/**
 * @defgroup at_apb_slwtimer_regs_core_clear_field clear_field
 * @brief macros for field clear
 * @details clear slow timer (__SELF_CLEARING__)
 * @{
 */
#define SLW_CONTROL__CLEAR__SHIFT                                             0
#define SLW_CONTROL__CLEAR__WIDTH                                             1
#define SLW_CONTROL__CLEAR__MASK                                    0x00000001U
#define SLW_CONTROL__CLEAR__READ(src)           ((uint32_t)(src) & 0x00000001U)
#define SLW_CONTROL__CLEAR__WRITE(src)          ((uint32_t)(src) & 0x00000001U)
#define SLW_CONTROL__CLEAR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SLW_CONTROL__CLEAR__VERIFY(src)   (!(((uint32_t)(src) & ~0x00000001U)))
#define SLW_CONTROL__CLEAR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SLW_CONTROL__CLEAR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SLW_CONTROL__CLEAR__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field load */
/**
 * @defgroup at_apb_slwtimer_regs_core_load_field load_field
 * @brief macros for field load
 * @details load slow timer (__SELF_CLEARING__)
 * @{
 */
#define SLW_CONTROL__LOAD__SHIFT                                              1
#define SLW_CONTROL__LOAD__WIDTH                                              1
#define SLW_CONTROL__LOAD__MASK                                     0x00000002U
#define SLW_CONTROL__LOAD__READ(src)     (((uint32_t)(src) & 0x00000002U) >> 1)
#define SLW_CONTROL__LOAD__WRITE(src)    (((uint32_t)(src) << 1) & 0x00000002U)
#define SLW_CONTROL__LOAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SLW_CONTROL__LOAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SLW_CONTROL__LOAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SLW_CONTROL__LOAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SLW_CONTROL__LOAD__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field reset_expired */
/**
 * @defgroup at_apb_slwtimer_regs_core_reset_expired_field reset_expired_field
 * @brief macros for field reset_expired
 * @details reset expired interrupt; (__SELF_CLEARING__)
 * @{
 */
#define SLW_CONTROL__RESET_EXPIRED__SHIFT                                     2
#define SLW_CONTROL__RESET_EXPIRED__WIDTH                                     1
#define SLW_CONTROL__RESET_EXPIRED__MASK                            0x00000004U
#define SLW_CONTROL__RESET_EXPIRED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SLW_CONTROL__RESET_EXPIRED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SLW_CONTROL__RESET_EXPIRED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SLW_CONTROL__RESET_EXPIRED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SLW_CONTROL__RESET_EXPIRED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SLW_CONTROL__RESET_EXPIRED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SLW_CONTROL__RESET_EXPIRED__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field reset_thres0 */
/**
 * @defgroup at_apb_slwtimer_regs_core_reset_thres0_field reset_thres0_field
 * @brief macros for field reset_thres0
 * @details reset thres0 interrupt; (__SELF_CLEARING__)
 * @{
 */
#define SLW_CONTROL__RESET_THRES0__SHIFT                                      3
#define SLW_CONTROL__RESET_THRES0__WIDTH                                      1
#define SLW_CONTROL__RESET_THRES0__MASK                             0x00000008U
#define SLW_CONTROL__RESET_THRES0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define SLW_CONTROL__RESET_THRES0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define SLW_CONTROL__RESET_THRES0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define SLW_CONTROL__RESET_THRES0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define SLW_CONTROL__RESET_THRES0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SLW_CONTROL__RESET_THRES0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SLW_CONTROL__RESET_THRES0__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field reset_thres1 */
/**
 * @defgroup at_apb_slwtimer_regs_core_reset_thres1_field reset_thres1_field
 * @brief macros for field reset_thres1
 * @details reset thres1 interrupt; (__SELF_CLEARING__)
 * @{
 */
#define SLW_CONTROL__RESET_THRES1__SHIFT                                      4
#define SLW_CONTROL__RESET_THRES1__WIDTH                                      1
#define SLW_CONTROL__RESET_THRES1__MASK                             0x00000010U
#define SLW_CONTROL__RESET_THRES1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define SLW_CONTROL__RESET_THRES1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define SLW_CONTROL__RESET_THRES1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define SLW_CONTROL__RESET_THRES1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define SLW_CONTROL__RESET_THRES1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define SLW_CONTROL__RESET_THRES1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define SLW_CONTROL__RESET_THRES1__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field reset_thres2 */
/**
 * @defgroup at_apb_slwtimer_regs_core_reset_thres2_field reset_thres2_field
 * @brief macros for field reset_thres2
 * @details reset thres2 interrupt; (__SELF_CLEARING__)
 * @{
 */
#define SLW_CONTROL__RESET_THRES2__SHIFT                                      5
#define SLW_CONTROL__RESET_THRES2__WIDTH                                      1
#define SLW_CONTROL__RESET_THRES2__MASK                             0x00000020U
#define SLW_CONTROL__RESET_THRES2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define SLW_CONTROL__RESET_THRES2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define SLW_CONTROL__RESET_THRES2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define SLW_CONTROL__RESET_THRES2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define SLW_CONTROL__RESET_THRES2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define SLW_CONTROL__RESET_THRES2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define SLW_CONTROL__RESET_THRES2__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field auto_reload */
/**
 * @defgroup at_apb_slwtimer_regs_core_auto_reload_field auto_reload_field
 * @brief macros for field auto_reload
 * @details auto reload slow timer with initial value after expiring
 * @{
 */
#define SLW_CONTROL__AUTO_RELOAD__SHIFT                                       8
#define SLW_CONTROL__AUTO_RELOAD__WIDTH                                       1
#define SLW_CONTROL__AUTO_RELOAD__MASK                              0x00000100U
#define SLW_CONTROL__AUTO_RELOAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define SLW_CONTROL__AUTO_RELOAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define SLW_CONTROL__AUTO_RELOAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define SLW_CONTROL__AUTO_RELOAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define SLW_CONTROL__AUTO_RELOAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define SLW_CONTROL__AUTO_RELOAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define SLW_CONTROL__AUTO_RELOAD__RESET_VALUE                       0x00000000U
/** @} */
#define SLW_CONTROL__TYPE                                              uint32_t
#define SLW_CONTROL__READ                                           0x0000013fU
#define SLW_CONTROL__WRITE                                          0x0000013fU
#define SLW_CONTROL__PRESERVED                                      0x00000000U
#define SLW_CONTROL__RESET_VALUE                                    0x00000000U

#endif /* __SLW_CONTROL_MACRO__ */

/** @} end of control */

/* macros for BlueprintGlobalNameSpace::SLW_init_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_init_low init_low
 * @brief initial count value definitions.
 * @{
 */
#ifndef __SLW_INIT_LOW_MACRO__
#define __SLW_INIT_LOW_MACRO__

/* macros for field init_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_init_low_field init_low_field
 * @brief macros for field init_low
 * @details lower 32b of the 40b initial count value
 * @{
 */
#define SLW_INIT_LOW__INIT_LOW__SHIFT                                         0
#define SLW_INIT_LOW__INIT_LOW__WIDTH                                        32
#define SLW_INIT_LOW__INIT_LOW__MASK                                0xffffffffU
#define SLW_INIT_LOW__INIT_LOW__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define SLW_INIT_LOW__INIT_LOW__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define SLW_INIT_LOW__INIT_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SLW_INIT_LOW__INIT_LOW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SLW_INIT_LOW__INIT_LOW__RESET_VALUE                         0x00000000U
/** @} */
#define SLW_INIT_LOW__TYPE                                             uint32_t
#define SLW_INIT_LOW__READ                                          0xffffffffU
#define SLW_INIT_LOW__WRITE                                         0xffffffffU
#define SLW_INIT_LOW__PRESERVED                                     0x00000000U
#define SLW_INIT_LOW__RESET_VALUE                                   0x00000000U

#endif /* __SLW_INIT_LOW_MACRO__ */

/** @} end of init_low */

/* macros for BlueprintGlobalNameSpace::SLW_init_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_init_high init_high
 * @brief initial count value definitions.
 * @{
 */
#ifndef __SLW_INIT_HIGH_MACRO__
#define __SLW_INIT_HIGH_MACRO__

/* macros for field init_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_init_high_field init_high_field
 * @brief macros for field init_high
 * @details upper 8b of the 40b initial count value
 * @{
 */
#define SLW_INIT_HIGH__INIT_HIGH__SHIFT                                       0
#define SLW_INIT_HIGH__INIT_HIGH__WIDTH                                       8
#define SLW_INIT_HIGH__INIT_HIGH__MASK                              0x000000ffU
#define SLW_INIT_HIGH__INIT_HIGH__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define SLW_INIT_HIGH__INIT_HIGH__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define SLW_INIT_HIGH__INIT_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SLW_INIT_HIGH__INIT_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SLW_INIT_HIGH__INIT_HIGH__RESET_VALUE                       0x00000000U
/** @} */
#define SLW_INIT_HIGH__TYPE                                            uint32_t
#define SLW_INIT_HIGH__READ                                         0x000000ffU
#define SLW_INIT_HIGH__WRITE                                        0x000000ffU
#define SLW_INIT_HIGH__PRESERVED                                    0x00000000U
#define SLW_INIT_HIGH__RESET_VALUE                                  0x00000000U

#endif /* __SLW_INIT_HIGH_MACRO__ */

/** @} end of init_high */

/* macros for BlueprintGlobalNameSpace::SLW_cnt_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_cnt_low cnt_low
 * @brief current count value definitions.
 * @{
 */
#ifndef __SLW_CNT_LOW_MACRO__
#define __SLW_CNT_LOW_MACRO__

/* macros for field cnt_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_cnt_low_field cnt_low_field
 * @brief macros for field cnt_low
 * @details lower 32b of the 40b current count value
 * @{
 */
#define SLW_CNT_LOW__CNT_LOW__SHIFT                                           0
#define SLW_CNT_LOW__CNT_LOW__WIDTH                                          32
#define SLW_CNT_LOW__CNT_LOW__MASK                                  0xffffffffU
#define SLW_CNT_LOW__CNT_LOW__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define SLW_CNT_LOW__CNT_LOW__RESET_VALUE                           0x00000000U
/** @} */
#define SLW_CNT_LOW__TYPE                                              uint32_t
#define SLW_CNT_LOW__READ                                           0xffffffffU
#define SLW_CNT_LOW__PRESERVED                                      0x00000000U
#define SLW_CNT_LOW__RESET_VALUE                                    0x00000000U

#endif /* __SLW_CNT_LOW_MACRO__ */

/** @} end of cnt_low */

/* macros for BlueprintGlobalNameSpace::SLW_cnt_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_cnt_high cnt_high
 * @brief current count value definitions.
 * @{
 */
#ifndef __SLW_CNT_HIGH_MACRO__
#define __SLW_CNT_HIGH_MACRO__

/* macros for field cnt_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_cnt_high_field cnt_high_field
 * @brief macros for field cnt_high
 * @details upper 8b of the 40b current count value
 * @{
 */
#define SLW_CNT_HIGH__CNT_HIGH__SHIFT                                         0
#define SLW_CNT_HIGH__CNT_HIGH__WIDTH                                         8
#define SLW_CNT_HIGH__CNT_HIGH__MASK                                0x000000ffU
#define SLW_CNT_HIGH__CNT_HIGH__READ(src)       ((uint32_t)(src) & 0x000000ffU)
#define SLW_CNT_HIGH__CNT_HIGH__RESET_VALUE                         0x00000000U
/** @} */
#define SLW_CNT_HIGH__TYPE                                             uint32_t
#define SLW_CNT_HIGH__READ                                          0x000000ffU
#define SLW_CNT_HIGH__PRESERVED                                     0x00000000U
#define SLW_CNT_HIGH__RESET_VALUE                                   0x00000000U

#endif /* __SLW_CNT_HIGH_MACRO__ */

/** @} end of cnt_high */

/* macros for BlueprintGlobalNameSpace::SLW_thres0_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres0_low thres0_low
 * @brief threshold 0 value definitions.
 * @{
 */
#ifndef __SLW_THRES0_LOW_MACRO__
#define __SLW_THRES0_LOW_MACRO__

/* macros for field thres0_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres0_low_field thres0_low_field
 * @brief macros for field thres0_low
 * @details lower 32b of the 40b threshold 0 value; when counter decrements from one above to this value, an optional interrupt triggers
 * @{
 */
#define SLW_THRES0_LOW__THRES0_LOW__SHIFT                                     0
#define SLW_THRES0_LOW__THRES0_LOW__WIDTH                                    32
#define SLW_THRES0_LOW__THRES0_LOW__MASK                            0xffffffffU
#define SLW_THRES0_LOW__THRES0_LOW__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define SLW_THRES0_LOW__THRES0_LOW__WRITE(src)  ((uint32_t)(src) & 0xffffffffU)
#define SLW_THRES0_LOW__THRES0_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SLW_THRES0_LOW__THRES0_LOW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SLW_THRES0_LOW__THRES0_LOW__RESET_VALUE                     0x00000000U
/** @} */
#define SLW_THRES0_LOW__TYPE                                           uint32_t
#define SLW_THRES0_LOW__READ                                        0xffffffffU
#define SLW_THRES0_LOW__WRITE                                       0xffffffffU
#define SLW_THRES0_LOW__PRESERVED                                   0x00000000U
#define SLW_THRES0_LOW__RESET_VALUE                                 0x00000000U

#endif /* __SLW_THRES0_LOW_MACRO__ */

/** @} end of thres0_low */

/* macros for BlueprintGlobalNameSpace::SLW_thres0_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres0_high thres0_high
 * @brief threshold 0 value definitions.
 * @{
 */
#ifndef __SLW_THRES0_HIGH_MACRO__
#define __SLW_THRES0_HIGH_MACRO__

/* macros for field thres0_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres0_high_field thres0_high_field
 * @brief macros for field thres0_high
 * @details upper 8b of the 40b theshold 0 value
 * @{
 */
#define SLW_THRES0_HIGH__THRES0_HIGH__SHIFT                                   0
#define SLW_THRES0_HIGH__THRES0_HIGH__WIDTH                                   8
#define SLW_THRES0_HIGH__THRES0_HIGH__MASK                          0x000000ffU
#define SLW_THRES0_HIGH__THRES0_HIGH__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define SLW_THRES0_HIGH__THRES0_HIGH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SLW_THRES0_HIGH__THRES0_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SLW_THRES0_HIGH__THRES0_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SLW_THRES0_HIGH__THRES0_HIGH__RESET_VALUE                   0x00000000U
/** @} */
#define SLW_THRES0_HIGH__TYPE                                          uint32_t
#define SLW_THRES0_HIGH__READ                                       0x000000ffU
#define SLW_THRES0_HIGH__WRITE                                      0x000000ffU
#define SLW_THRES0_HIGH__PRESERVED                                  0x00000000U
#define SLW_THRES0_HIGH__RESET_VALUE                                0x00000000U

#endif /* __SLW_THRES0_HIGH_MACRO__ */

/** @} end of thres0_high */

/* macros for BlueprintGlobalNameSpace::SLW_thres1_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres1_low thres1_low
 * @brief threshold 1 value definitions.
 * @{
 */
#ifndef __SLW_THRES1_LOW_MACRO__
#define __SLW_THRES1_LOW_MACRO__

/* macros for field thres1_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres1_low_field thres1_low_field
 * @brief macros for field thres1_low
 * @details lower 32b of the 40b threshold 1 value; when counter decrements from one above to this value, an optional interrupt triggers
 * @{
 */
#define SLW_THRES1_LOW__THRES1_LOW__SHIFT                                     0
#define SLW_THRES1_LOW__THRES1_LOW__WIDTH                                    32
#define SLW_THRES1_LOW__THRES1_LOW__MASK                            0xffffffffU
#define SLW_THRES1_LOW__THRES1_LOW__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define SLW_THRES1_LOW__THRES1_LOW__WRITE(src)  ((uint32_t)(src) & 0xffffffffU)
#define SLW_THRES1_LOW__THRES1_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SLW_THRES1_LOW__THRES1_LOW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SLW_THRES1_LOW__THRES1_LOW__RESET_VALUE                     0x00000000U
/** @} */
#define SLW_THRES1_LOW__TYPE                                           uint32_t
#define SLW_THRES1_LOW__READ                                        0xffffffffU
#define SLW_THRES1_LOW__WRITE                                       0xffffffffU
#define SLW_THRES1_LOW__PRESERVED                                   0x00000000U
#define SLW_THRES1_LOW__RESET_VALUE                                 0x00000000U

#endif /* __SLW_THRES1_LOW_MACRO__ */

/** @} end of thres1_low */

/* macros for BlueprintGlobalNameSpace::SLW_thres1_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres1_high thres1_high
 * @brief threshold 1 value definitions.
 * @{
 */
#ifndef __SLW_THRES1_HIGH_MACRO__
#define __SLW_THRES1_HIGH_MACRO__

/* macros for field thres1_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres1_high_field thres1_high_field
 * @brief macros for field thres1_high
 * @details upper 8b of the 40b theshold 1 value
 * @{
 */
#define SLW_THRES1_HIGH__THRES1_HIGH__SHIFT                                   0
#define SLW_THRES1_HIGH__THRES1_HIGH__WIDTH                                   8
#define SLW_THRES1_HIGH__THRES1_HIGH__MASK                          0x000000ffU
#define SLW_THRES1_HIGH__THRES1_HIGH__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define SLW_THRES1_HIGH__THRES1_HIGH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SLW_THRES1_HIGH__THRES1_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SLW_THRES1_HIGH__THRES1_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SLW_THRES1_HIGH__THRES1_HIGH__RESET_VALUE                   0x00000000U
/** @} */
#define SLW_THRES1_HIGH__TYPE                                          uint32_t
#define SLW_THRES1_HIGH__READ                                       0x000000ffU
#define SLW_THRES1_HIGH__WRITE                                      0x000000ffU
#define SLW_THRES1_HIGH__PRESERVED                                  0x00000000U
#define SLW_THRES1_HIGH__RESET_VALUE                                0x00000000U

#endif /* __SLW_THRES1_HIGH_MACRO__ */

/** @} end of thres1_high */

/* macros for BlueprintGlobalNameSpace::SLW_thres2_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres2_low thres2_low
 * @brief threshold 2 value definitions.
 * @{
 */
#ifndef __SLW_THRES2_LOW_MACRO__
#define __SLW_THRES2_LOW_MACRO__

/* macros for field thres2_low */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres2_low_field thres2_low_field
 * @brief macros for field thres2_low
 * @details lower 32b of the 40b threshold 2 value; when counter decrements from one above to this value, an optional interrupt triggers
 * @{
 */
#define SLW_THRES2_LOW__THRES2_LOW__SHIFT                                     0
#define SLW_THRES2_LOW__THRES2_LOW__WIDTH                                    32
#define SLW_THRES2_LOW__THRES2_LOW__MASK                            0xffffffffU
#define SLW_THRES2_LOW__THRES2_LOW__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define SLW_THRES2_LOW__THRES2_LOW__WRITE(src)  ((uint32_t)(src) & 0xffffffffU)
#define SLW_THRES2_LOW__THRES2_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SLW_THRES2_LOW__THRES2_LOW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SLW_THRES2_LOW__THRES2_LOW__RESET_VALUE                     0x00000000U
/** @} */
#define SLW_THRES2_LOW__TYPE                                           uint32_t
#define SLW_THRES2_LOW__READ                                        0xffffffffU
#define SLW_THRES2_LOW__WRITE                                       0xffffffffU
#define SLW_THRES2_LOW__PRESERVED                                   0x00000000U
#define SLW_THRES2_LOW__RESET_VALUE                                 0x00000000U

#endif /* __SLW_THRES2_LOW_MACRO__ */

/** @} end of thres2_low */

/* macros for BlueprintGlobalNameSpace::SLW_thres2_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres2_high thres2_high
 * @brief threshold 2 value definitions.
 * @{
 */
#ifndef __SLW_THRES2_HIGH_MACRO__
#define __SLW_THRES2_HIGH_MACRO__

/* macros for field thres2_high */
/**
 * @defgroup at_apb_slwtimer_regs_core_thres2_high_field thres2_high_field
 * @brief macros for field thres2_high
 * @details upper 8b of the 40b theshold 2 value
 * @{
 */
#define SLW_THRES2_HIGH__THRES2_HIGH__SHIFT                                   0
#define SLW_THRES2_HIGH__THRES2_HIGH__WIDTH                                   8
#define SLW_THRES2_HIGH__THRES2_HIGH__MASK                          0x000000ffU
#define SLW_THRES2_HIGH__THRES2_HIGH__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define SLW_THRES2_HIGH__THRES2_HIGH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SLW_THRES2_HIGH__THRES2_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SLW_THRES2_HIGH__THRES2_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SLW_THRES2_HIGH__THRES2_HIGH__RESET_VALUE                   0x00000000U
/** @} */
#define SLW_THRES2_HIGH__TYPE                                          uint32_t
#define SLW_THRES2_HIGH__READ                                       0x000000ffU
#define SLW_THRES2_HIGH__WRITE                                      0x000000ffU
#define SLW_THRES2_HIGH__PRESERVED                                  0x00000000U
#define SLW_THRES2_HIGH__RESET_VALUE                                0x00000000U

#endif /* __SLW_THRES2_HIGH_MACRO__ */

/** @} end of thres2_high */

/* macros for BlueprintGlobalNameSpace::SLW_status */
/**
 * @defgroup at_apb_slwtimer_regs_core_status status
 * @brief status information definitions.
 * @{
 */
#ifndef __SLW_STATUS_MACRO__
#define __SLW_STATUS_MACRO__

/* macros for field op_running */
/**
 * @defgroup at_apb_slwtimer_regs_core_op_running_field op_running_field
 * @brief macros for field op_running
 * @details the operation (either load or clear) is still running; handoff to 32kHz domain takes time
 * @{
 */
#define SLW_STATUS__OP_RUNNING__SHIFT                                         0
#define SLW_STATUS__OP_RUNNING__WIDTH                                         1
#define SLW_STATUS__OP_RUNNING__MASK                                0x00000001U
#define SLW_STATUS__OP_RUNNING__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define SLW_STATUS__OP_RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SLW_STATUS__OP_RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SLW_STATUS__OP_RUNNING__RESET_VALUE                         0x00000000U
/** @} */
#define SLW_STATUS__TYPE                                               uint32_t
#define SLW_STATUS__READ                                            0x00000001U
#define SLW_STATUS__PRESERVED                                       0x00000000U
#define SLW_STATUS__RESET_VALUE                                     0x00000000U

#endif /* __SLW_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::SLW_interrupt_status */
/**
 * @defgroup at_apb_slwtimer_regs_core_interrupt_status interrupt_status
 * @brief interrupt status definitions.
 * @{
 */
#ifndef __SLW_INTERRUPT_STATUS_MACRO__
#define __SLW_INTERRUPT_STATUS_MACRO__

/* macros for field expired */
/**
 * @defgroup at_apb_slwtimer_regs_core_expired_field expired_field
 * @brief macros for field expired
 * @details counter transitioned from 1 to 0
 * @{
 */
#define SLW_INTERRUPT_STATUS__EXPIRED__SHIFT                                  0
#define SLW_INTERRUPT_STATUS__EXPIRED__WIDTH                                  1
#define SLW_INTERRUPT_STATUS__EXPIRED__MASK                         0x00000001U
#define SLW_INTERRUPT_STATUS__EXPIRED__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SLW_INTERRUPT_STATUS__EXPIRED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SLW_INTERRUPT_STATUS__EXPIRED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SLW_INTERRUPT_STATUS__EXPIRED__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field hit_thres0 */
/**
 * @defgroup at_apb_slwtimer_regs_core_hit_thres0_field hit_thres0_field
 * @brief macros for field hit_thres0
 * @details threshold 0 interrupt triggered
 * @{
 */
#define SLW_INTERRUPT_STATUS__HIT_THRES0__SHIFT                               1
#define SLW_INTERRUPT_STATUS__HIT_THRES0__WIDTH                               1
#define SLW_INTERRUPT_STATUS__HIT_THRES0__MASK                      0x00000002U
#define SLW_INTERRUPT_STATUS__HIT_THRES0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SLW_INTERRUPT_STATUS__HIT_THRES0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SLW_INTERRUPT_STATUS__HIT_THRES0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SLW_INTERRUPT_STATUS__HIT_THRES0__RESET_VALUE               0x00000000U
/** @} */

/* macros for field hit_thres1 */
/**
 * @defgroup at_apb_slwtimer_regs_core_hit_thres1_field hit_thres1_field
 * @brief macros for field hit_thres1
 * @details threshold 1 interrupt triggered
 * @{
 */
#define SLW_INTERRUPT_STATUS__HIT_THRES1__SHIFT                               2
#define SLW_INTERRUPT_STATUS__HIT_THRES1__WIDTH                               1
#define SLW_INTERRUPT_STATUS__HIT_THRES1__MASK                      0x00000004U
#define SLW_INTERRUPT_STATUS__HIT_THRES1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SLW_INTERRUPT_STATUS__HIT_THRES1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SLW_INTERRUPT_STATUS__HIT_THRES1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SLW_INTERRUPT_STATUS__HIT_THRES1__RESET_VALUE               0x00000000U
/** @} */

/* macros for field hit_thres2 */
/**
 * @defgroup at_apb_slwtimer_regs_core_hit_thres2_field hit_thres2_field
 * @brief macros for field hit_thres2
 * @details threshold 2 interrupt triggered
 * @{
 */
#define SLW_INTERRUPT_STATUS__HIT_THRES2__SHIFT                               3
#define SLW_INTERRUPT_STATUS__HIT_THRES2__WIDTH                               1
#define SLW_INTERRUPT_STATUS__HIT_THRES2__MASK                      0x00000008U
#define SLW_INTERRUPT_STATUS__HIT_THRES2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define SLW_INTERRUPT_STATUS__HIT_THRES2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SLW_INTERRUPT_STATUS__HIT_THRES2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SLW_INTERRUPT_STATUS__HIT_THRES2__RESET_VALUE               0x00000000U
/** @} */
#define SLW_INTERRUPT_STATUS__TYPE                                     uint32_t
#define SLW_INTERRUPT_STATUS__READ                                  0x0000000fU
#define SLW_INTERRUPT_STATUS__PRESERVED                             0x00000000U
#define SLW_INTERRUPT_STATUS__RESET_VALUE                           0x00000000U

#endif /* __SLW_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::SLW_interrupt_mask */
/**
 * @defgroup at_apb_slwtimer_regs_core_interrupt_mask interrupt_mask
 * @brief interrupt mask definitions.
 * @{
 */
#ifndef __SLW_INTERRUPT_MASK_MACRO__
#define __SLW_INTERRUPT_MASK_MACRO__

/* macros for field passthru_expired */
/**
 * @defgroup at_apb_slwtimer_regs_core_passthru_expired_field passthru_expired_field
 * @brief macros for field passthru_expired
 * @details 1=allow counter expiring to be OR'd into core interrupt
 * @{
 */
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__SHIFT                           0
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__WIDTH                           1
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__MASK                  0x00000001U
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SLW_INTERRUPT_MASK__PASSTHRU_EXPIRED__RESET_VALUE           0x00000001U
/** @} */

/* macros for field passthru_hit_thres0 */
/**
 * @defgroup at_apb_slwtimer_regs_core_passthru_hit_thres0_field passthru_hit_thres0_field
 * @brief macros for field passthru_hit_thres0
 * @details 1=allow hit_thres0 to be OR'd into core interrupt
 * @{
 */
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__SHIFT                        1
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__WIDTH                        1
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__MASK               0x00000002U
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES0__RESET_VALUE        0x00000001U
/** @} */

/* macros for field passthru_hit_thres1 */
/**
 * @defgroup at_apb_slwtimer_regs_core_passthru_hit_thres1_field passthru_hit_thres1_field
 * @brief macros for field passthru_hit_thres1
 * @details 1=allow hit_thres1 to be OR'd into core interrupt
 * @{
 */
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__SHIFT                        2
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__WIDTH                        1
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__MASK               0x00000004U
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES1__RESET_VALUE        0x00000001U
/** @} */

/* macros for field passthru_hit_thres2 */
/**
 * @defgroup at_apb_slwtimer_regs_core_passthru_hit_thres2_field passthru_hit_thres2_field
 * @brief macros for field passthru_hit_thres2
 * @details 1=allow hit_thres2 to be OR'd into core interrupt
 * @{
 */
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__SHIFT                        3
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__WIDTH                        1
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__MASK               0x00000008U
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SLW_INTERRUPT_MASK__PASSTHRU_HIT_THRES2__RESET_VALUE        0x00000001U
/** @} */
#define SLW_INTERRUPT_MASK__TYPE                                       uint32_t
#define SLW_INTERRUPT_MASK__READ                                    0x0000000fU
#define SLW_INTERRUPT_MASK__WRITE                                   0x0000000fU
#define SLW_INTERRUPT_MASK__PRESERVED                               0x00000000U
#define SLW_INTERRUPT_MASK__RESET_VALUE                             0x0000000fU

#endif /* __SLW_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::SLW_core_id */
/**
 * @defgroup at_apb_slwtimer_regs_core_core_id core_id
 * @brief core ID definitions.
 * @{
 */
#ifndef __SLW_CORE_ID_MACRO__
#define __SLW_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_slwtimer_regs_core_id_field id_field
 * @brief macros for field id
 * @details 'STMR' in hex
 * @{
 */
#define SLW_CORE_ID__ID__SHIFT                                                0
#define SLW_CORE_ID__ID__WIDTH                                               32
#define SLW_CORE_ID__ID__MASK                                       0xffffffffU
#define SLW_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define SLW_CORE_ID__ID__RESET_VALUE                                0x53544d52U
/** @} */
#define SLW_CORE_ID__TYPE                                              uint32_t
#define SLW_CORE_ID__READ                                           0xffffffffU
#define SLW_CORE_ID__PRESERVED                                      0x00000000U
#define SLW_CORE_ID__RESET_VALUE                                    0x53544d52U

#endif /* __SLW_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::SLW_rev_hash */
/**
 * @defgroup at_apb_slwtimer_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __SLW_REV_HASH_MACRO__
#define __SLW_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_slwtimer_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define SLW_REV_HASH__ID__SHIFT                                               0
#define SLW_REV_HASH__ID__WIDTH                                              32
#define SLW_REV_HASH__ID__MASK                                      0xffffffffU
#define SLW_REV_HASH__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define SLW_REV_HASH__ID__RESET_VALUE                               0x5f4b0ff7U
/** @} */
#define SLW_REV_HASH__TYPE                                             uint32_t
#define SLW_REV_HASH__READ                                          0xffffffffU
#define SLW_REV_HASH__PRESERVED                                     0x00000000U
#define SLW_REV_HASH__RESET_VALUE                                   0x5f4b0ff7U

#endif /* __SLW_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::SLW_rev_key */
/**
 * @defgroup at_apb_slwtimer_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __SLW_REV_KEY_MACRO__
#define __SLW_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_slwtimer_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define SLW_REV_KEY__ID__SHIFT                                                0
#define SLW_REV_KEY__ID__WIDTH                                               32
#define SLW_REV_KEY__ID__MASK                                       0xffffffffU
#define SLW_REV_KEY__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define SLW_REV_KEY__ID__RESET_VALUE                                0x52455620U
/** @} */
#define SLW_REV_KEY__TYPE                                              uint32_t
#define SLW_REV_KEY__READ                                           0xffffffffU
#define SLW_REV_KEY__PRESERVED                                      0x00000000U
#define SLW_REV_KEY__RESET_VALUE                                    0x52455620U

#endif /* __SLW_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_SLWTIMER_REGS_CORE */
#endif /* __REG_AT_APB_SLWTIMER_REGS_CORE_H__ */
