/*                                                                           */
/* File:       at_apb_qdec_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_qdec_regs_core.rdl          */
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


#ifndef __REG_AT_APB_QDEC_REGS_CORE_H__
#define __REG_AT_APB_QDEC_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_QDEC_REGS_CORE at_apb_qdec_regs_core
 * @ingroup AT_REG
 * @brief at_apb_qdec_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::QDEC_setup_for_axis_0 */
/**
 * @defgroup at_apb_qdec_regs_core_setup_for_axis_0 setup_for_axis_0
 * @brief Contains register fields associated with setup_for_axis_0. definitions.
 * @{
 */
#ifndef __QDEC_SETUP_FOR_AXIS_0_MACRO__
#define __QDEC_SETUP_FOR_AXIS_0_MACRO__

/* macros for field enable_loopback */
/**
 * @defgroup at_apb_qdec_regs_core_enable_loopback_field enable_loopback_field
 * @brief macros for field enable_loopback
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__SHIFT                         0
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__WIDTH                         1
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__MASK                0x00000001U
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_SETUP_FOR_AXIS_0__ENABLE_LOOPBACK__RESET_VALUE         0x00000000U
/** @} */

/* macros for field qsig_b_loopback_val */
/**
 * @defgroup at_apb_qdec_regs_core_qsig_b_loopback_val_field qsig_b_loopback_val_field
 * @brief macros for field qsig_b_loopback_val
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__SHIFT                     1
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__MASK            0x00000002U
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_B_LOOPBACK_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field qsig_a_loopback_val */
/**
 * @defgroup at_apb_qdec_regs_core_qsig_a_loopback_val_field qsig_a_loopback_val_field
 * @brief macros for field qsig_a_loopback_val
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__SHIFT                     2
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__MASK            0x00000004U
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define QDEC_SETUP_FOR_AXIS_0__QSIG_A_LOOPBACK_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field reverse_polarity */
/**
 * @defgroup at_apb_qdec_regs_core_reverse_polarity_field reverse_polarity_field
 * @brief macros for field reverse_polarity
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__SHIFT                        3
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__WIDTH                        1
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__MASK               0x00000008U
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define QDEC_SETUP_FOR_AXIS_0__REVERSE_POLARITY__RESET_VALUE        0x00000000U
/** @} */

/* macros for field purge_accum_post_read */
/**
 * @defgroup at_apb_qdec_regs_core_purge_accum_post_read_field purge_accum_post_read_field
 * @brief macros for field purge_accum_post_read
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__SHIFT                   4
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__WIDTH                   1
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__MASK          0x00000010U
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ACCUM_POST_READ__RESET_VALUE   0x00000001U
/** @} */

/* macros for field purge_err_post_read */
/**
 * @defgroup at_apb_qdec_regs_core_purge_err_post_read_field purge_err_post_read_field
 * @brief macros for field purge_err_post_read
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__SHIFT                     5
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__MASK            0x00000020U
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define QDEC_SETUP_FOR_AXIS_0__PURGE_ERR_POST_READ__RESET_VALUE     0x00000001U
/** @} */
#define QDEC_SETUP_FOR_AXIS_0__TYPE                                    uint32_t
#define QDEC_SETUP_FOR_AXIS_0__READ                                 0x0000003fU
#define QDEC_SETUP_FOR_AXIS_0__WRITE                                0x0000003fU
#define QDEC_SETUP_FOR_AXIS_0__PRESERVED                            0x00000000U
#define QDEC_SETUP_FOR_AXIS_0__RESET_VALUE                          0x00000030U

#endif /* __QDEC_SETUP_FOR_AXIS_0_MACRO__ */

/** @} end of setup_for_axis_0 */

/* macros for BlueprintGlobalNameSpace::QDEC_accum_purge_status_for_axis_0 */
/**
 * @defgroup at_apb_qdec_regs_core_accum_purge_status_for_axis_0 accum_purge_status_for_axis_0
 * @brief Contains register fields associated with accum_purge_status_for_axis_0. definitions.
 * @{
 */
#ifndef __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0_MACRO__
#define __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0_MACRO__

/* macros for field accum_purge_sts */
/**
 * @defgroup at_apb_qdec_regs_core_accum_purge_sts_field accum_purge_sts_field
 * @brief macros for field accum_purge_sts
 * @{
 */
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__ACCUM_PURGE_STS__SHIFT            0
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__ACCUM_PURGE_STS__WIDTH            1
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__ACCUM_PURGE_STS__MASK   0x00000001U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__ACCUM_PURGE_STS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__ACCUM_PURGE_STS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__ACCUM_PURGE_STS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__ACCUM_PURGE_STS__RESET_VALUE \
                    0x00000000U
/** @} */
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__TYPE                       uint32_t
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__READ                    0x00000001U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__PRESERVED               0x00000000U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0__RESET_VALUE             0x00000000U

#endif /* __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_0_MACRO__ */

/** @} end of accum_purge_status_for_axis_0 */

/* macros for BlueprintGlobalNameSpace::QDEC_accumulator_value_for_axis_0 */
/**
 * @defgroup at_apb_qdec_regs_core_accumulator_value_for_axis_0 accumulator_value_for_axis_0
 * @brief Contains register fields associated with accumulator_value_for_axis_0. definitions.
 * @{
 */
#ifndef __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0_MACRO__
#define __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0_MACRO__

/* macros for field accum_val */
/**
 * @defgroup at_apb_qdec_regs_core_accum_val_field accum_val_field
 * @brief macros for field accum_val
 * @{
 */
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__ACCUM_VAL__SHIFT                   0
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__ACCUM_VAL__WIDTH                  32
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__ACCUM_VAL__MASK          0xffffffffU
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__ACCUM_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__ACCUM_VAL__RESET_VALUE   0x00000000U
/** @} */
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__TYPE                        uint32_t
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__READ                     0xffffffffU
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__PRESERVED                0x00000000U
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0__RESET_VALUE              0x00000000U

#endif /* __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_0_MACRO__ */

/** @} end of accumulator_value_for_axis_0 */

/* macros for BlueprintGlobalNameSpace::QDEC_err_purge_status_for_axis_0 */
/**
 * @defgroup at_apb_qdec_regs_core_err_purge_status_for_axis_0 err_purge_status_for_axis_0
 * @brief Contains register fields associated with err_purge_status_for_axis_0. definitions.
 * @{
 */
#ifndef __QDEC_ERR_PURGE_STATUS_FOR_AXIS_0_MACRO__
#define __QDEC_ERR_PURGE_STATUS_FOR_AXIS_0_MACRO__

/* macros for field err_purge_sts */
/**
 * @defgroup at_apb_qdec_regs_core_err_purge_sts_field err_purge_sts_field
 * @brief macros for field err_purge_sts
 * @{
 */
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__ERR_PURGE_STS__SHIFT                0
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__ERR_PURGE_STS__WIDTH                1
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__ERR_PURGE_STS__MASK       0x00000001U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__ERR_PURGE_STS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__ERR_PURGE_STS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__ERR_PURGE_STS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__ERR_PURGE_STS__RESET_VALUE \
                    0x00000000U
/** @} */
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__TYPE                         uint32_t
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__READ                      0x00000001U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__PRESERVED                 0x00000000U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_0__RESET_VALUE               0x00000000U

#endif /* __QDEC_ERR_PURGE_STATUS_FOR_AXIS_0_MACRO__ */

/** @} end of err_purge_status_for_axis_0 */

/* macros for BlueprintGlobalNameSpace::QDEC_error_count_for_axis_0 */
/**
 * @defgroup at_apb_qdec_regs_core_error_count_for_axis_0 error_count_for_axis_0
 * @brief Contains register fields associated with error_count_for_axis_0. definitions.
 * @{
 */
#ifndef __QDEC_ERROR_COUNT_FOR_AXIS_0_MACRO__
#define __QDEC_ERROR_COUNT_FOR_AXIS_0_MACRO__

/* macros for field err_cnt */
/**
 * @defgroup at_apb_qdec_regs_core_err_cnt_field err_cnt_field
 * @brief macros for field err_cnt
 * @{
 */
#define QDEC_ERROR_COUNT_FOR_AXIS_0__ERR_CNT__SHIFT                           0
#define QDEC_ERROR_COUNT_FOR_AXIS_0__ERR_CNT__WIDTH                          32
#define QDEC_ERROR_COUNT_FOR_AXIS_0__ERR_CNT__MASK                  0xffffffffU
#define QDEC_ERROR_COUNT_FOR_AXIS_0__ERR_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define QDEC_ERROR_COUNT_FOR_AXIS_0__ERR_CNT__RESET_VALUE           0x00000000U
/** @} */
#define QDEC_ERROR_COUNT_FOR_AXIS_0__TYPE                              uint32_t
#define QDEC_ERROR_COUNT_FOR_AXIS_0__READ                           0xffffffffU
#define QDEC_ERROR_COUNT_FOR_AXIS_0__PRESERVED                      0x00000000U
#define QDEC_ERROR_COUNT_FOR_AXIS_0__RESET_VALUE                    0x00000000U

#endif /* __QDEC_ERROR_COUNT_FOR_AXIS_0_MACRO__ */

/** @} end of error_count_for_axis_0 */

/* macros for BlueprintGlobalNameSpace::QDEC_setup_for_axis_1 */
/**
 * @defgroup at_apb_qdec_regs_core_setup_for_axis_1 setup_for_axis_1
 * @brief Contains register fields associated with setup_for_axis_1. definitions.
 * @{
 */
#ifndef __QDEC_SETUP_FOR_AXIS_1_MACRO__
#define __QDEC_SETUP_FOR_AXIS_1_MACRO__

/* macros for field enable_loopback */
/**
 * @defgroup at_apb_qdec_regs_core_enable_loopback_field enable_loopback_field
 * @brief macros for field enable_loopback
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__SHIFT                         0
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__WIDTH                         1
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__MASK                0x00000001U
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_SETUP_FOR_AXIS_1__ENABLE_LOOPBACK__RESET_VALUE         0x00000000U
/** @} */

/* macros for field qsig_b_loopback_val */
/**
 * @defgroup at_apb_qdec_regs_core_qsig_b_loopback_val_field qsig_b_loopback_val_field
 * @brief macros for field qsig_b_loopback_val
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__SHIFT                     1
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__MASK            0x00000002U
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_B_LOOPBACK_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field qsig_a_loopback_val */
/**
 * @defgroup at_apb_qdec_regs_core_qsig_a_loopback_val_field qsig_a_loopback_val_field
 * @brief macros for field qsig_a_loopback_val
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__SHIFT                     2
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__MASK            0x00000004U
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define QDEC_SETUP_FOR_AXIS_1__QSIG_A_LOOPBACK_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field reverse_polarity */
/**
 * @defgroup at_apb_qdec_regs_core_reverse_polarity_field reverse_polarity_field
 * @brief macros for field reverse_polarity
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__SHIFT                        3
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__WIDTH                        1
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__MASK               0x00000008U
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define QDEC_SETUP_FOR_AXIS_1__REVERSE_POLARITY__RESET_VALUE        0x00000000U
/** @} */

/* macros for field purge_accum_post_read */
/**
 * @defgroup at_apb_qdec_regs_core_purge_accum_post_read_field purge_accum_post_read_field
 * @brief macros for field purge_accum_post_read
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__SHIFT                   4
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__WIDTH                   1
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__MASK          0x00000010U
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ACCUM_POST_READ__RESET_VALUE   0x00000001U
/** @} */

/* macros for field purge_err_post_read */
/**
 * @defgroup at_apb_qdec_regs_core_purge_err_post_read_field purge_err_post_read_field
 * @brief macros for field purge_err_post_read
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__SHIFT                     5
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__MASK            0x00000020U
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define QDEC_SETUP_FOR_AXIS_1__PURGE_ERR_POST_READ__RESET_VALUE     0x00000001U
/** @} */
#define QDEC_SETUP_FOR_AXIS_1__TYPE                                    uint32_t
#define QDEC_SETUP_FOR_AXIS_1__READ                                 0x0000003fU
#define QDEC_SETUP_FOR_AXIS_1__WRITE                                0x0000003fU
#define QDEC_SETUP_FOR_AXIS_1__PRESERVED                            0x00000000U
#define QDEC_SETUP_FOR_AXIS_1__RESET_VALUE                          0x00000030U

#endif /* __QDEC_SETUP_FOR_AXIS_1_MACRO__ */

/** @} end of setup_for_axis_1 */

/* macros for BlueprintGlobalNameSpace::QDEC_accum_purge_status_for_axis_1 */
/**
 * @defgroup at_apb_qdec_regs_core_accum_purge_status_for_axis_1 accum_purge_status_for_axis_1
 * @brief Contains register fields associated with accum_purge_status_for_axis_1. definitions.
 * @{
 */
#ifndef __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1_MACRO__
#define __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1_MACRO__

/* macros for field accum_purge_sts */
/**
 * @defgroup at_apb_qdec_regs_core_accum_purge_sts_field accum_purge_sts_field
 * @brief macros for field accum_purge_sts
 * @{
 */
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__ACCUM_PURGE_STS__SHIFT            0
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__ACCUM_PURGE_STS__WIDTH            1
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__ACCUM_PURGE_STS__MASK   0x00000001U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__ACCUM_PURGE_STS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__ACCUM_PURGE_STS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__ACCUM_PURGE_STS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__ACCUM_PURGE_STS__RESET_VALUE \
                    0x00000000U
/** @} */
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__TYPE                       uint32_t
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__READ                    0x00000001U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__PRESERVED               0x00000000U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1__RESET_VALUE             0x00000000U

#endif /* __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_1_MACRO__ */

/** @} end of accum_purge_status_for_axis_1 */

/* macros for BlueprintGlobalNameSpace::QDEC_accumulator_value_for_axis_1 */
/**
 * @defgroup at_apb_qdec_regs_core_accumulator_value_for_axis_1 accumulator_value_for_axis_1
 * @brief Contains register fields associated with accumulator_value_for_axis_1. definitions.
 * @{
 */
#ifndef __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1_MACRO__
#define __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1_MACRO__

/* macros for field accum_val */
/**
 * @defgroup at_apb_qdec_regs_core_accum_val_field accum_val_field
 * @brief macros for field accum_val
 * @{
 */
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__ACCUM_VAL__SHIFT                   0
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__ACCUM_VAL__WIDTH                  32
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__ACCUM_VAL__MASK          0xffffffffU
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__ACCUM_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__ACCUM_VAL__RESET_VALUE   0x00000000U
/** @} */
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__TYPE                        uint32_t
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__READ                     0xffffffffU
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__PRESERVED                0x00000000U
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1__RESET_VALUE              0x00000000U

#endif /* __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_1_MACRO__ */

/** @} end of accumulator_value_for_axis_1 */

/* macros for BlueprintGlobalNameSpace::QDEC_err_purge_status_for_axis_1 */
/**
 * @defgroup at_apb_qdec_regs_core_err_purge_status_for_axis_1 err_purge_status_for_axis_1
 * @brief Contains register fields associated with err_purge_status_for_axis_1. definitions.
 * @{
 */
#ifndef __QDEC_ERR_PURGE_STATUS_FOR_AXIS_1_MACRO__
#define __QDEC_ERR_PURGE_STATUS_FOR_AXIS_1_MACRO__

/* macros for field err_purge_sts */
/**
 * @defgroup at_apb_qdec_regs_core_err_purge_sts_field err_purge_sts_field
 * @brief macros for field err_purge_sts
 * @{
 */
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__ERR_PURGE_STS__SHIFT                0
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__ERR_PURGE_STS__WIDTH                1
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__ERR_PURGE_STS__MASK       0x00000001U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__ERR_PURGE_STS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__ERR_PURGE_STS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__ERR_PURGE_STS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__ERR_PURGE_STS__RESET_VALUE \
                    0x00000000U
/** @} */
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__TYPE                         uint32_t
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__READ                      0x00000001U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__PRESERVED                 0x00000000U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_1__RESET_VALUE               0x00000000U

#endif /* __QDEC_ERR_PURGE_STATUS_FOR_AXIS_1_MACRO__ */

/** @} end of err_purge_status_for_axis_1 */

/* macros for BlueprintGlobalNameSpace::QDEC_error_count_for_axis_1 */
/**
 * @defgroup at_apb_qdec_regs_core_error_count_for_axis_1 error_count_for_axis_1
 * @brief Contains register fields associated with error_count_for_axis_1. definitions.
 * @{
 */
#ifndef __QDEC_ERROR_COUNT_FOR_AXIS_1_MACRO__
#define __QDEC_ERROR_COUNT_FOR_AXIS_1_MACRO__

/* macros for field err_cnt */
/**
 * @defgroup at_apb_qdec_regs_core_err_cnt_field err_cnt_field
 * @brief macros for field err_cnt
 * @{
 */
#define QDEC_ERROR_COUNT_FOR_AXIS_1__ERR_CNT__SHIFT                           0
#define QDEC_ERROR_COUNT_FOR_AXIS_1__ERR_CNT__WIDTH                          32
#define QDEC_ERROR_COUNT_FOR_AXIS_1__ERR_CNT__MASK                  0xffffffffU
#define QDEC_ERROR_COUNT_FOR_AXIS_1__ERR_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define QDEC_ERROR_COUNT_FOR_AXIS_1__ERR_CNT__RESET_VALUE           0x00000000U
/** @} */
#define QDEC_ERROR_COUNT_FOR_AXIS_1__TYPE                              uint32_t
#define QDEC_ERROR_COUNT_FOR_AXIS_1__READ                           0xffffffffU
#define QDEC_ERROR_COUNT_FOR_AXIS_1__PRESERVED                      0x00000000U
#define QDEC_ERROR_COUNT_FOR_AXIS_1__RESET_VALUE                    0x00000000U

#endif /* __QDEC_ERROR_COUNT_FOR_AXIS_1_MACRO__ */

/** @} end of error_count_for_axis_1 */

/* macros for BlueprintGlobalNameSpace::QDEC_setup_for_axis_2 */
/**
 * @defgroup at_apb_qdec_regs_core_setup_for_axis_2 setup_for_axis_2
 * @brief Contains register fields associated with setup_for_axis_2. definitions.
 * @{
 */
#ifndef __QDEC_SETUP_FOR_AXIS_2_MACRO__
#define __QDEC_SETUP_FOR_AXIS_2_MACRO__

/* macros for field enable_loopback */
/**
 * @defgroup at_apb_qdec_regs_core_enable_loopback_field enable_loopback_field
 * @brief macros for field enable_loopback
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__SHIFT                         0
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__WIDTH                         1
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__MASK                0x00000001U
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_SETUP_FOR_AXIS_2__ENABLE_LOOPBACK__RESET_VALUE         0x00000000U
/** @} */

/* macros for field qsig_b_loopback_val */
/**
 * @defgroup at_apb_qdec_regs_core_qsig_b_loopback_val_field qsig_b_loopback_val_field
 * @brief macros for field qsig_b_loopback_val
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__SHIFT                     1
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__MASK            0x00000002U
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_B_LOOPBACK_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field qsig_a_loopback_val */
/**
 * @defgroup at_apb_qdec_regs_core_qsig_a_loopback_val_field qsig_a_loopback_val_field
 * @brief macros for field qsig_a_loopback_val
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__SHIFT                     2
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__MASK            0x00000004U
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define QDEC_SETUP_FOR_AXIS_2__QSIG_A_LOOPBACK_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field reverse_polarity */
/**
 * @defgroup at_apb_qdec_regs_core_reverse_polarity_field reverse_polarity_field
 * @brief macros for field reverse_polarity
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__SHIFT                        3
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__WIDTH                        1
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__MASK               0x00000008U
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define QDEC_SETUP_FOR_AXIS_2__REVERSE_POLARITY__RESET_VALUE        0x00000000U
/** @} */

/* macros for field purge_accum_post_read */
/**
 * @defgroup at_apb_qdec_regs_core_purge_accum_post_read_field purge_accum_post_read_field
 * @brief macros for field purge_accum_post_read
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__SHIFT                   4
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__WIDTH                   1
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__MASK          0x00000010U
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ACCUM_POST_READ__RESET_VALUE   0x00000001U
/** @} */

/* macros for field purge_err_post_read */
/**
 * @defgroup at_apb_qdec_regs_core_purge_err_post_read_field purge_err_post_read_field
 * @brief macros for field purge_err_post_read
 * @{
 */
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__SHIFT                     5
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__WIDTH                     1
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__MASK            0x00000020U
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define QDEC_SETUP_FOR_AXIS_2__PURGE_ERR_POST_READ__RESET_VALUE     0x00000001U
/** @} */
#define QDEC_SETUP_FOR_AXIS_2__TYPE                                    uint32_t
#define QDEC_SETUP_FOR_AXIS_2__READ                                 0x0000003fU
#define QDEC_SETUP_FOR_AXIS_2__WRITE                                0x0000003fU
#define QDEC_SETUP_FOR_AXIS_2__PRESERVED                            0x00000000U
#define QDEC_SETUP_FOR_AXIS_2__RESET_VALUE                          0x00000030U

#endif /* __QDEC_SETUP_FOR_AXIS_2_MACRO__ */

/** @} end of setup_for_axis_2 */

/* macros for BlueprintGlobalNameSpace::QDEC_accum_purge_status_for_axis_2 */
/**
 * @defgroup at_apb_qdec_regs_core_accum_purge_status_for_axis_2 accum_purge_status_for_axis_2
 * @brief Contains register fields associated with accum_purge_status_for_axis_2. definitions.
 * @{
 */
#ifndef __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2_MACRO__
#define __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2_MACRO__

/* macros for field accum_purge_sts */
/**
 * @defgroup at_apb_qdec_regs_core_accum_purge_sts_field accum_purge_sts_field
 * @brief macros for field accum_purge_sts
 * @{
 */
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__ACCUM_PURGE_STS__SHIFT            0
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__ACCUM_PURGE_STS__WIDTH            1
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__ACCUM_PURGE_STS__MASK   0x00000001U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__ACCUM_PURGE_STS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__ACCUM_PURGE_STS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__ACCUM_PURGE_STS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__ACCUM_PURGE_STS__RESET_VALUE \
                    0x00000000U
/** @} */
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__TYPE                       uint32_t
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__READ                    0x00000001U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__PRESERVED               0x00000000U
#define QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2__RESET_VALUE             0x00000000U

#endif /* __QDEC_ACCUM_PURGE_STATUS_FOR_AXIS_2_MACRO__ */

/** @} end of accum_purge_status_for_axis_2 */

/* macros for BlueprintGlobalNameSpace::QDEC_accumulator_value_for_axis_2 */
/**
 * @defgroup at_apb_qdec_regs_core_accumulator_value_for_axis_2 accumulator_value_for_axis_2
 * @brief Contains register fields associated with accumulator_value_for_axis_2. definitions.
 * @{
 */
#ifndef __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2_MACRO__
#define __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2_MACRO__

/* macros for field accum_val */
/**
 * @defgroup at_apb_qdec_regs_core_accum_val_field accum_val_field
 * @brief macros for field accum_val
 * @{
 */
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__ACCUM_VAL__SHIFT                   0
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__ACCUM_VAL__WIDTH                  32
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__ACCUM_VAL__MASK          0xffffffffU
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__ACCUM_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__ACCUM_VAL__RESET_VALUE   0x00000000U
/** @} */
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__TYPE                        uint32_t
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__READ                     0xffffffffU
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__PRESERVED                0x00000000U
#define QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2__RESET_VALUE              0x00000000U

#endif /* __QDEC_ACCUMULATOR_VALUE_FOR_AXIS_2_MACRO__ */

/** @} end of accumulator_value_for_axis_2 */

/* macros for BlueprintGlobalNameSpace::QDEC_err_purge_status_for_axis_2 */
/**
 * @defgroup at_apb_qdec_regs_core_err_purge_status_for_axis_2 err_purge_status_for_axis_2
 * @brief Contains register fields associated with err_purge_status_for_axis_2. definitions.
 * @{
 */
#ifndef __QDEC_ERR_PURGE_STATUS_FOR_AXIS_2_MACRO__
#define __QDEC_ERR_PURGE_STATUS_FOR_AXIS_2_MACRO__

/* macros for field err_purge_sts */
/**
 * @defgroup at_apb_qdec_regs_core_err_purge_sts_field err_purge_sts_field
 * @brief macros for field err_purge_sts
 * @{
 */
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__ERR_PURGE_STS__SHIFT                0
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__ERR_PURGE_STS__WIDTH                1
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__ERR_PURGE_STS__MASK       0x00000001U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__ERR_PURGE_STS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__ERR_PURGE_STS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__ERR_PURGE_STS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__ERR_PURGE_STS__RESET_VALUE \
                    0x00000000U
/** @} */
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__TYPE                         uint32_t
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__READ                      0x00000001U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__PRESERVED                 0x00000000U
#define QDEC_ERR_PURGE_STATUS_FOR_AXIS_2__RESET_VALUE               0x00000000U

#endif /* __QDEC_ERR_PURGE_STATUS_FOR_AXIS_2_MACRO__ */

/** @} end of err_purge_status_for_axis_2 */

/* macros for BlueprintGlobalNameSpace::QDEC_error_count_for_axis_2 */
/**
 * @defgroup at_apb_qdec_regs_core_error_count_for_axis_2 error_count_for_axis_2
 * @brief Contains register fields associated with error_count_for_axis_2. definitions.
 * @{
 */
#ifndef __QDEC_ERROR_COUNT_FOR_AXIS_2_MACRO__
#define __QDEC_ERROR_COUNT_FOR_AXIS_2_MACRO__

/* macros for field err_cnt */
/**
 * @defgroup at_apb_qdec_regs_core_err_cnt_field err_cnt_field
 * @brief macros for field err_cnt
 * @{
 */
#define QDEC_ERROR_COUNT_FOR_AXIS_2__ERR_CNT__SHIFT                           0
#define QDEC_ERROR_COUNT_FOR_AXIS_2__ERR_CNT__WIDTH                          32
#define QDEC_ERROR_COUNT_FOR_AXIS_2__ERR_CNT__MASK                  0xffffffffU
#define QDEC_ERROR_COUNT_FOR_AXIS_2__ERR_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define QDEC_ERROR_COUNT_FOR_AXIS_2__ERR_CNT__RESET_VALUE           0x00000000U
/** @} */
#define QDEC_ERROR_COUNT_FOR_AXIS_2__TYPE                              uint32_t
#define QDEC_ERROR_COUNT_FOR_AXIS_2__READ                           0xffffffffU
#define QDEC_ERROR_COUNT_FOR_AXIS_2__PRESERVED                      0x00000000U
#define QDEC_ERROR_COUNT_FOR_AXIS_2__RESET_VALUE                    0x00000000U

#endif /* __QDEC_ERROR_COUNT_FOR_AXIS_2_MACRO__ */

/** @} end of error_count_for_axis_2 */

/* macros for BlueprintGlobalNameSpace::QDEC_core_id */
/**
 * @defgroup at_apb_qdec_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __QDEC_CORE_ID_MACRO__
#define __QDEC_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_qdec_regs_core_id_field id_field
 * @brief macros for field id
 * @details QDEC in ASCII
 * @{
 */
#define QDEC_CORE_ID__ID__SHIFT                                               0
#define QDEC_CORE_ID__ID__WIDTH                                              32
#define QDEC_CORE_ID__ID__MASK                                      0xffffffffU
#define QDEC_CORE_ID__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define QDEC_CORE_ID__ID__RESET_VALUE                               0x51444543U
/** @} */
#define QDEC_CORE_ID__TYPE                                             uint32_t
#define QDEC_CORE_ID__READ                                          0xffffffffU
#define QDEC_CORE_ID__PRESERVED                                     0x00000000U
#define QDEC_CORE_ID__RESET_VALUE                                   0x51444543U

#endif /* __QDEC_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of AT_APB_QDEC_REGS_CORE */
#endif /* __REG_AT_APB_QDEC_REGS_CORE_H__ */
