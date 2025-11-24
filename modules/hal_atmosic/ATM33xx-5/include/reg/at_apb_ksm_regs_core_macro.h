/*                                                                           */
/* File:       at_apb_ksm_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_ksm_regs_core.rdl           */
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


#ifndef __REG_AT_APB_KSM_REGS_CORE_H__
#define __REG_AT_APB_KSM_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_KSM_REGS_CORE at_apb_ksm_regs_core
 * @ingroup AT_REG
 * @brief at_apb_ksm_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::KSM_ctrl0 */
/**
 * @defgroup at_apb_ksm_regs_core_ctrl0 ctrl0
 * @brief Contains register fields associated with ctrl0. definitions.
 * @{
 */
#ifndef __KSM_CTRL0_MACRO__
#define __KSM_CTRL0_MACRO__

/* macros for field go */
/**
 * @defgroup at_apb_ksm_regs_core_go_field go_field
 * @brief macros for field go
 * @details start the keyboard scanning; will scan while go is high; not self reseting
 * @{
 */
#define KSM_CTRL0__GO__SHIFT                                                  0
#define KSM_CTRL0__GO__WIDTH                                                  1
#define KSM_CTRL0__GO__MASK                                         0x00000001U
#define KSM_CTRL0__GO__READ(src)                ((uint32_t)(src) & 0x00000001U)
#define KSM_CTRL0__GO__WRITE(src)               ((uint32_t)(src) & 0x00000001U)
#define KSM_CTRL0__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define KSM_CTRL0__GO__VERIFY(src)        (!(((uint32_t)(src) & ~0x00000001U)))
#define KSM_CTRL0__GO__SET(dst)  (dst) = ((dst) & ~0x00000001U) | (uint32_t)(1)
#define KSM_CTRL0__GO__CLR(dst)  (dst) = ((dst) & ~0x00000001U) | (uint32_t)(0)
#define KSM_CTRL0__GO__RESET_VALUE                                  0x00000000U
/** @} */

/* macros for field loopback */
/**
 * @defgroup at_apb_ksm_regs_core_loopback_field loopback_field
 * @brief macros for field loopback
 * @details enable lpback_ksi (see below)
 * @{
 */
#define KSM_CTRL0__LOOPBACK__SHIFT                                            1
#define KSM_CTRL0__LOOPBACK__WIDTH                                            1
#define KSM_CTRL0__LOOPBACK__MASK                                   0x00000002U
#define KSM_CTRL0__LOOPBACK__READ(src)   (((uint32_t)(src) & 0x00000002U) >> 1)
#define KSM_CTRL0__LOOPBACK__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000002U)
#define KSM_CTRL0__LOOPBACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define KSM_CTRL0__LOOPBACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define KSM_CTRL0__LOOPBACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define KSM_CTRL0__LOOPBACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define KSM_CTRL0__LOOPBACK__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field pop */
/**
 * @defgroup at_apb_ksm_regs_core_pop_field pop_field
 * @brief macros for field pop
 * @details read from keyboard event fifo; not self reseting
 * @{
 */
#define KSM_CTRL0__POP__SHIFT                                                 2
#define KSM_CTRL0__POP__WIDTH                                                 1
#define KSM_CTRL0__POP__MASK                                        0x00000004U
#define KSM_CTRL0__POP__READ(src)        (((uint32_t)(src) & 0x00000004U) >> 2)
#define KSM_CTRL0__POP__WRITE(src)       (((uint32_t)(src) << 2) & 0x00000004U)
#define KSM_CTRL0__POP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define KSM_CTRL0__POP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define KSM_CTRL0__POP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define KSM_CTRL0__POP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define KSM_CTRL0__POP__RESET_VALUE                                 0x00000000U
/** @} */

/* macros for field flush */
/**
 * @defgroup at_apb_ksm_regs_core_flush_field flush_field
 * @brief macros for field flush
 * @details flushes the key packet fifo
 * @{
 */
#define KSM_CTRL0__FLUSH__SHIFT                                               3
#define KSM_CTRL0__FLUSH__WIDTH                                               1
#define KSM_CTRL0__FLUSH__MASK                                      0x00000008U
#define KSM_CTRL0__FLUSH__READ(src)      (((uint32_t)(src) & 0x00000008U) >> 3)
#define KSM_CTRL0__FLUSH__WRITE(src)     (((uint32_t)(src) << 3) & 0x00000008U)
#define KSM_CTRL0__FLUSH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define KSM_CTRL0__FLUSH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define KSM_CTRL0__FLUSH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define KSM_CTRL0__FLUSH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define KSM_CTRL0__FLUSH__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field consecscan */
/**
 * @defgroup at_apb_ksm_regs_core_consecscan_field consecscan_field
 * @brief macros for field consecscan
 * @details how many consecutive scans are needed before key press or key release event? (0 is INVALID)
 * @{
 */
#define KSM_CTRL0__CONSECSCAN__SHIFT                                          8
#define KSM_CTRL0__CONSECSCAN__WIDTH                                          4
#define KSM_CTRL0__CONSECSCAN__MASK                                 0x00000f00U
#define KSM_CTRL0__CONSECSCAN__READ(src) (((uint32_t)(src) & 0x00000f00U) >> 8)
#define KSM_CTRL0__CONSECSCAN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define KSM_CTRL0__CONSECSCAN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define KSM_CTRL0__CONSECSCAN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define KSM_CTRL0__CONSECSCAN__RESET_VALUE                          0x00000008U
/** @} */

/* macros for field ksm_not_empty_to_intrpt */
/**
 * @defgroup at_apb_ksm_regs_core_ksm_not_empty_to_intrpt_field ksm_not_empty_to_intrpt_field
 * @brief macros for field ksm_not_empty_to_intrpt
 * @details in addition to fifo_write, /not empty/ signal will also feed into setting intrpt[0]
 * @{
 */
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__SHIFT                            12
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__WIDTH                             1
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__MASK                    0x00001000U
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define KSM_CTRL0__KSM_NOT_EMPTY_TO_INTRPT__RESET_VALUE             0x00000000U
/** @} */
#define KSM_CTRL0__TYPE                                                uint32_t
#define KSM_CTRL0__READ                                             0x00001f0fU
#define KSM_CTRL0__WRITE                                            0x00001f0fU
#define KSM_CTRL0__PRESERVED                                        0x00000000U
#define KSM_CTRL0__RESET_VALUE                                      0x00000800U

#endif /* __KSM_CTRL0_MACRO__ */

/** @} end of ctrl0 */

/* macros for BlueprintGlobalNameSpace::KSM_time_param0 */
/**
 * @defgroup at_apb_ksm_regs_core_time_param0 time_param0
 * @brief Contains register fields associated with time_param0. definitions.
 * @{
 */
#ifndef __KSM_TIME_PARAM0_MACRO__
#define __KSM_TIME_PARAM0_MACRO__

/* macros for field t2 */
/**
 * @defgroup at_apb_ksm_regs_core_t2_field t2_field
 * @brief macros for field t2
 * @details from sampling last row to col rising
 * @{
 */
#define KSM_TIME_PARAM0__T2__SHIFT                                            0
#define KSM_TIME_PARAM0__T2__WIDTH                                           16
#define KSM_TIME_PARAM0__T2__MASK                                   0x0000ffffU
#define KSM_TIME_PARAM0__T2__READ(src)          ((uint32_t)(src) & 0x0000ffffU)
#define KSM_TIME_PARAM0__T2__WRITE(src)         ((uint32_t)(src) & 0x0000ffffU)
#define KSM_TIME_PARAM0__T2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define KSM_TIME_PARAM0__T2__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000ffffU)))
#define KSM_TIME_PARAM0__T2__RESET_VALUE                            0x00000010U
/** @} */

/* macros for field t1 */
/**
 * @defgroup at_apb_ksm_regs_core_t1_field t1_field
 * @brief macros for field t1
 * @details from col falling to sampling first row
 * @{
 */
#define KSM_TIME_PARAM0__T1__SHIFT                                           16
#define KSM_TIME_PARAM0__T1__WIDTH                                           16
#define KSM_TIME_PARAM0__T1__MASK                                   0xffff0000U
#define KSM_TIME_PARAM0__T1__READ(src)  (((uint32_t)(src) & 0xffff0000U) >> 16)
#define KSM_TIME_PARAM0__T1__WRITE(src) (((uint32_t)(src) << 16) & 0xffff0000U)
#define KSM_TIME_PARAM0__T1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define KSM_TIME_PARAM0__T1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define KSM_TIME_PARAM0__T1__RESET_VALUE                            0x00000010U
/** @} */
#define KSM_TIME_PARAM0__TYPE                                          uint32_t
#define KSM_TIME_PARAM0__READ                                       0xffffffffU
#define KSM_TIME_PARAM0__WRITE                                      0xffffffffU
#define KSM_TIME_PARAM0__PRESERVED                                  0x00000000U
#define KSM_TIME_PARAM0__RESET_VALUE                                0x00100010U

#endif /* __KSM_TIME_PARAM0_MACRO__ */

/** @} end of time_param0 */

/* macros for BlueprintGlobalNameSpace::KSM_time_param1 */
/**
 * @defgroup at_apb_ksm_regs_core_time_param1 time_param1
 * @brief Contains register fields associated with time_param1. definitions.
 * @{
 */
#ifndef __KSM_TIME_PARAM1_MACRO__
#define __KSM_TIME_PARAM1_MACRO__

/* macros for field t4 */
/**
 * @defgroup at_apb_ksm_regs_core_t4_field t4_field
 * @brief macros for field t4
 * @details gap between col rising and next col falling
 * @{
 */
#define KSM_TIME_PARAM1__T4__SHIFT                                            0
#define KSM_TIME_PARAM1__T4__WIDTH                                           16
#define KSM_TIME_PARAM1__T4__MASK                                   0x0000ffffU
#define KSM_TIME_PARAM1__T4__READ(src)          ((uint32_t)(src) & 0x0000ffffU)
#define KSM_TIME_PARAM1__T4__WRITE(src)         ((uint32_t)(src) & 0x0000ffffU)
#define KSM_TIME_PARAM1__T4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define KSM_TIME_PARAM1__T4__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000ffffU)))
#define KSM_TIME_PARAM1__T4__RESET_VALUE                            0x00000040U
/** @} */

/* macros for field t3 */
/**
 * @defgroup at_apb_ksm_regs_core_t3_field t3_field
 * @brief macros for field t3
 * @details gap between adjacent row samplings
 * @{
 */
#define KSM_TIME_PARAM1__T3__SHIFT                                           16
#define KSM_TIME_PARAM1__T3__WIDTH                                           16
#define KSM_TIME_PARAM1__T3__MASK                                   0xffff0000U
#define KSM_TIME_PARAM1__T3__READ(src)  (((uint32_t)(src) & 0xffff0000U) >> 16)
#define KSM_TIME_PARAM1__T3__WRITE(src) (((uint32_t)(src) << 16) & 0xffff0000U)
#define KSM_TIME_PARAM1__T3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define KSM_TIME_PARAM1__T3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define KSM_TIME_PARAM1__T3__RESET_VALUE                            0x00000008U
/** @} */
#define KSM_TIME_PARAM1__TYPE                                          uint32_t
#define KSM_TIME_PARAM1__READ                                       0xffffffffU
#define KSM_TIME_PARAM1__WRITE                                      0xffffffffU
#define KSM_TIME_PARAM1__PRESERVED                                  0x00000000U
#define KSM_TIME_PARAM1__RESET_VALUE                                0x00080040U

#endif /* __KSM_TIME_PARAM1_MACRO__ */

/** @} end of time_param1 */

/* macros for BlueprintGlobalNameSpace::KSM_matrix_size */
/**
 * @defgroup at_apb_ksm_regs_core_matrix_size matrix_size
 * @brief Contains register fields associated with matrix_size. definitions.
 * @{
 */
#ifndef __KSM_MATRIX_SIZE_MACRO__
#define __KSM_MATRIX_SIZE_MACRO__

/* macros for field num_col */
/**
 * @defgroup at_apb_ksm_regs_core_num_col_field num_col_field
 * @brief macros for field num_col
 * @details the actual number of cols is num_col + 1
 * @{
 */
#define KSM_MATRIX_SIZE__NUM_COL__SHIFT                                       0
#define KSM_MATRIX_SIZE__NUM_COL__WIDTH                                       5
#define KSM_MATRIX_SIZE__NUM_COL__MASK                              0x0000001fU
#define KSM_MATRIX_SIZE__NUM_COL__READ(src)     ((uint32_t)(src) & 0x0000001fU)
#define KSM_MATRIX_SIZE__NUM_COL__WRITE(src)    ((uint32_t)(src) & 0x0000001fU)
#define KSM_MATRIX_SIZE__NUM_COL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define KSM_MATRIX_SIZE__NUM_COL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define KSM_MATRIX_SIZE__NUM_COL__RESET_VALUE                       0x00000007U
/** @} */

/* macros for field num_row */
/**
 * @defgroup at_apb_ksm_regs_core_num_row_field num_row_field
 * @brief macros for field num_row
 * @details the actual number of rows is num_row + 1
 * @{
 */
#define KSM_MATRIX_SIZE__NUM_ROW__SHIFT                                       8
#define KSM_MATRIX_SIZE__NUM_ROW__WIDTH                                       5
#define KSM_MATRIX_SIZE__NUM_ROW__MASK                              0x00001f00U
#define KSM_MATRIX_SIZE__NUM_ROW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define KSM_MATRIX_SIZE__NUM_ROW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00001f00U)
#define KSM_MATRIX_SIZE__NUM_ROW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f00U) | (((uint32_t)(src) <<\
                    8) & 0x00001f00U)
#define KSM_MATRIX_SIZE__NUM_ROW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00001f00U)))
#define KSM_MATRIX_SIZE__NUM_ROW__RESET_VALUE                       0x00000013U
/** @} */
#define KSM_MATRIX_SIZE__TYPE                                          uint32_t
#define KSM_MATRIX_SIZE__READ                                       0x00001f1fU
#define KSM_MATRIX_SIZE__WRITE                                      0x00001f1fU
#define KSM_MATRIX_SIZE__PRESERVED                                  0x00000000U
#define KSM_MATRIX_SIZE__RESET_VALUE                                0x00001307U

#endif /* __KSM_MATRIX_SIZE_MACRO__ */

/** @} end of matrix_size */

/* macros for BlueprintGlobalNameSpace::KSM_keyboard_packet */
/**
 * @defgroup at_apb_ksm_regs_core_keyboard_packet keyboard_packet
 * @brief Contains register fields associated with keyboard_packet. definitions.
 * @{
 */
#ifndef __KSM_KEYBOARD_PACKET_MACRO__
#define __KSM_KEYBOARD_PACKET_MACRO__

/* macros for field row */
/**
 * @defgroup at_apb_ksm_regs_core_row_field row_field
 * @brief macros for field row
 * @details the row of the pressed or released key; 0-indexed
 * @{
 */
#define KSM_KEYBOARD_PACKET__ROW__SHIFT                                       0
#define KSM_KEYBOARD_PACKET__ROW__WIDTH                                       5
#define KSM_KEYBOARD_PACKET__ROW__MASK                              0x0000001fU
#define KSM_KEYBOARD_PACKET__ROW__READ(src)     ((uint32_t)(src) & 0x0000001fU)
#define KSM_KEYBOARD_PACKET__ROW__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field col */
/**
 * @defgroup at_apb_ksm_regs_core_col_field col_field
 * @brief macros for field col
 * @details the column of the pressed or released key; 0-indexed
 * @{
 */
#define KSM_KEYBOARD_PACKET__COL__SHIFT                                       5
#define KSM_KEYBOARD_PACKET__COL__WIDTH                                       5
#define KSM_KEYBOARD_PACKET__COL__MASK                              0x000003e0U
#define KSM_KEYBOARD_PACKET__COL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define KSM_KEYBOARD_PACKET__COL__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field pressed_released_n */
/**
 * @defgroup at_apb_ksm_regs_core_pressed_released_n_field pressed_released_n_field
 * @brief macros for field pressed_released_n
 * @details 1=pressed 0=released
 * @{
 */
#define KSM_KEYBOARD_PACKET__PRESSED_RELEASED_N__SHIFT                       10
#define KSM_KEYBOARD_PACKET__PRESSED_RELEASED_N__WIDTH                        1
#define KSM_KEYBOARD_PACKET__PRESSED_RELEASED_N__MASK               0x00000400U
#define KSM_KEYBOARD_PACKET__PRESSED_RELEASED_N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define KSM_KEYBOARD_PACKET__PRESSED_RELEASED_N__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define KSM_KEYBOARD_PACKET__PRESSED_RELEASED_N__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define KSM_KEYBOARD_PACKET__PRESSED_RELEASED_N__RESET_VALUE        0x00000000U
/** @} */

/* macros for field empty */
/**
 * @defgroup at_apb_ksm_regs_core_empty_field empty_field
 * @brief macros for field empty
 * @details if 1, ignore this pack et
 * @{
 */
#define KSM_KEYBOARD_PACKET__EMPTY__SHIFT                                    11
#define KSM_KEYBOARD_PACKET__EMPTY__WIDTH                                     1
#define KSM_KEYBOARD_PACKET__EMPTY__MASK                            0x00000800U
#define KSM_KEYBOARD_PACKET__EMPTY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define KSM_KEYBOARD_PACKET__EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define KSM_KEYBOARD_PACKET__EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define KSM_KEYBOARD_PACKET__EMPTY__RESET_VALUE                     0x00000000U
/** @} */
#define KSM_KEYBOARD_PACKET__TYPE                                      uint32_t
#define KSM_KEYBOARD_PACKET__READ                                   0x00000fffU
#define KSM_KEYBOARD_PACKET__PRESERVED                              0x00000000U
#define KSM_KEYBOARD_PACKET__RESET_VALUE                            0x00000000U

#endif /* __KSM_KEYBOARD_PACKET_MACRO__ */

/** @} end of keyboard_packet */

/* macros for BlueprintGlobalNameSpace::KSM_low_power */
/**
 * @defgroup at_apb_ksm_regs_core_low_power low_power
 * @brief Contains register fields associated with low_power. definitions.
 * @{
 */
#ifndef __KSM_LOW_POWER_MACRO__
#define __KSM_LOW_POWER_MACRO__

/* macros for field key */
/**
 * @defgroup at_apb_ksm_regs_core_key_field key_field
 * @brief macros for field key
 * @details this is the key press or release that woke the device
 * @{
 */
#define KSM_LOW_POWER__KEY__SHIFT                                             0
#define KSM_LOW_POWER__KEY__WIDTH                                            11
#define KSM_LOW_POWER__KEY__MASK                                    0x000007ffU
#define KSM_LOW_POWER__KEY__READ(src)           ((uint32_t)(src) & 0x000007ffU)
#define KSM_LOW_POWER__KEY__RESET_VALUE                             0x00000000U
/** @} */
#define KSM_LOW_POWER__TYPE                                            uint32_t
#define KSM_LOW_POWER__READ                                         0x000007ffU
#define KSM_LOW_POWER__PRESERVED                                    0x00000000U
#define KSM_LOW_POWER__RESET_VALUE                                  0x00000000U

#endif /* __KSM_LOW_POWER_MACRO__ */

/** @} end of low_power */

/* macros for BlueprintGlobalNameSpace::KSM_lpback_ksi */
/**
 * @defgroup at_apb_ksm_regs_core_lpback_ksi lpback_ksi
 * @brief Contains register fields associated with lpback_ksi. definitions.
 * @{
 */
#ifndef __KSM_LPBACK_KSI_MACRO__
#define __KSM_LPBACK_KSI_MACRO__

/* macros for field lpback_ksi */
/**
 * @defgroup at_apb_ksm_regs_core_lpback_ksi_field lpback_ksi_field
 * @brief macros for field lpback_ksi
 * @details the values to be driven on each of the ksi lines (while in loopback)
 * @{
 */
#define KSM_LPBACK_KSI__LPBACK_KSI__SHIFT                                     0
#define KSM_LPBACK_KSI__LPBACK_KSI__WIDTH                                    20
#define KSM_LPBACK_KSI__LPBACK_KSI__MASK                            0x000fffffU
#define KSM_LPBACK_KSI__LPBACK_KSI__READ(src)   ((uint32_t)(src) & 0x000fffffU)
#define KSM_LPBACK_KSI__LPBACK_KSI__WRITE(src)  ((uint32_t)(src) & 0x000fffffU)
#define KSM_LPBACK_KSI__LPBACK_KSI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define KSM_LPBACK_KSI__LPBACK_KSI__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define KSM_LPBACK_KSI__LPBACK_KSI__RESET_VALUE                     0x000fffffU
/** @} */
#define KSM_LPBACK_KSI__TYPE                                           uint32_t
#define KSM_LPBACK_KSI__READ                                        0x000fffffU
#define KSM_LPBACK_KSI__WRITE                                       0x000fffffU
#define KSM_LPBACK_KSI__PRESERVED                                   0x00000000U
#define KSM_LPBACK_KSI__RESET_VALUE                                 0x000fffffU

#endif /* __KSM_LPBACK_KSI_MACRO__ */

/** @} end of lpback_ksi */

/* macros for BlueprintGlobalNameSpace::KSM_status */
/**
 * @defgroup at_apb_ksm_regs_core_status status
 * @brief Contains register fields associated with status. definitions.
 * @{
 */
#ifndef __KSM_STATUS_MACRO__
#define __KSM_STATUS_MACRO__

/* macros for field command_taken */
/**
 * @defgroup at_apb_ksm_regs_core_command_taken_field command_taken_field
 * @brief macros for field command_taken
 * @details fsm in on 32kHz clock; it takes two 32kHz cycles for the command to be picked up
 * @{
 */
#define KSM_STATUS__COMMAND_TAKEN__SHIFT                                      0
#define KSM_STATUS__COMMAND_TAKEN__WIDTH                                      1
#define KSM_STATUS__COMMAND_TAKEN__MASK                             0x00000001U
#define KSM_STATUS__COMMAND_TAKEN__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define KSM_STATUS__COMMAND_TAKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define KSM_STATUS__COMMAND_TAKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define KSM_STATUS__COMMAND_TAKEN__RESET_VALUE                      0x00000000U
/** @} */
#define KSM_STATUS__TYPE                                               uint32_t
#define KSM_STATUS__READ                                            0x00000001U
#define KSM_STATUS__PRESERVED                                       0x00000000U
#define KSM_STATUS__RESET_VALUE                                     0x00000000U

#endif /* __KSM_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::KSM_interrupts */
/**
 * @defgroup at_apb_ksm_regs_core_interrupts interrupts
 * @brief Contains register fields associated with interrupts. definitions.
 * @{
 */
#ifndef __KSM_INTERRUPTS_MACRO__
#define __KSM_INTERRUPTS_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_ksm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details hardware wrote packet to keyboard event fifo
 * @{
 */
#define KSM_INTERRUPTS__INTRPT0__SHIFT                                        0
#define KSM_INTERRUPTS__INTRPT0__WIDTH                                        1
#define KSM_INTERRUPTS__INTRPT0__MASK                               0x00000001U
#define KSM_INTERRUPTS__INTRPT0__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define KSM_INTERRUPTS__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define KSM_INTERRUPTS__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define KSM_INTERRUPTS__INTRPT0__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt1 */
/**
 * @defgroup at_apb_ksm_regs_core_intrpt1_field intrpt1_field
 * @brief macros for field intrpt1
 * @details keyboard event fifo overran
 * @{
 */
#define KSM_INTERRUPTS__INTRPT1__SHIFT                                        1
#define KSM_INTERRUPTS__INTRPT1__WIDTH                                        1
#define KSM_INTERRUPTS__INTRPT1__MASK                               0x00000002U
#define KSM_INTERRUPTS__INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define KSM_INTERRUPTS__INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define KSM_INTERRUPTS__INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define KSM_INTERRUPTS__INTRPT1__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt2 */
/**
 * @defgroup at_apb_ksm_regs_core_intrpt2_field intrpt2_field
 * @brief macros for field intrpt2
 * @details pop read is done
 * @{
 */
#define KSM_INTERRUPTS__INTRPT2__SHIFT                                        2
#define KSM_INTERRUPTS__INTRPT2__WIDTH                                        1
#define KSM_INTERRUPTS__INTRPT2__MASK                               0x00000004U
#define KSM_INTERRUPTS__INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define KSM_INTERRUPTS__INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define KSM_INTERRUPTS__INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define KSM_INTERRUPTS__INTRPT2__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt3 */
/**
 * @defgroup at_apb_ksm_regs_core_intrpt3_field intrpt3_field
 * @brief macros for field intrpt3
 * @details flush read is done
 * @{
 */
#define KSM_INTERRUPTS__INTRPT3__SHIFT                                        3
#define KSM_INTERRUPTS__INTRPT3__WIDTH                                        1
#define KSM_INTERRUPTS__INTRPT3__MASK                               0x00000008U
#define KSM_INTERRUPTS__INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define KSM_INTERRUPTS__INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define KSM_INTERRUPTS__INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define KSM_INTERRUPTS__INTRPT3__RESET_VALUE                        0x00000000U
/** @} */
#define KSM_INTERRUPTS__TYPE                                           uint32_t
#define KSM_INTERRUPTS__READ                                        0x0000000fU
#define KSM_INTERRUPTS__PRESERVED                                   0x00000000U
#define KSM_INTERRUPTS__RESET_VALUE                                 0x00000000U

#endif /* __KSM_INTERRUPTS_MACRO__ */

/** @} end of interrupts */

/* macros for BlueprintGlobalNameSpace::KSM_interrupt_mask */
/**
 * @defgroup at_apb_ksm_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __KSM_INTERRUPT_MASK_MACRO__
#define __KSM_INTERRUPT_MASK_MACRO__

/* macros for field mask_intrpt0 */
/**
 * @defgroup at_apb_ksm_regs_core_mask_intrpt0_field mask_intrpt0_field
 * @brief macros for field mask_intrpt0
 * @details allow intrpt0 to propogate to core's single output interrupt
 * @{
 */
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__SHIFT                               0
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__WIDTH                               1
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__MASK                      0x00000001U
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define KSM_INTERRUPT_MASK__MASK_INTRPT0__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt1 */
/**
 * @defgroup at_apb_ksm_regs_core_mask_intrpt1_field mask_intrpt1_field
 * @brief macros for field mask_intrpt1
 * @details allow intrpt1 to propogate to core's single output interrupt
 * @{
 */
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__SHIFT                               1
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__WIDTH                               1
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__MASK                      0x00000002U
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define KSM_INTERRUPT_MASK__MASK_INTRPT1__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt2 */
/**
 * @defgroup at_apb_ksm_regs_core_mask_intrpt2_field mask_intrpt2_field
 * @brief macros for field mask_intrpt2
 * @details allow intrpt2 to propogate to core's single output interrupt
 * @{
 */
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__SHIFT                               2
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__WIDTH                               1
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__MASK                      0x00000004U
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define KSM_INTERRUPT_MASK__MASK_INTRPT2__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt3 */
/**
 * @defgroup at_apb_ksm_regs_core_mask_intrpt3_field mask_intrpt3_field
 * @brief macros for field mask_intrpt3
 * @details allow intrpt3 to propogate to core's single output interrupt
 * @{
 */
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__SHIFT                               3
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__WIDTH                               1
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__MASK                      0x00000008U
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define KSM_INTERRUPT_MASK__MASK_INTRPT3__RESET_VALUE               0x00000001U
/** @} */
#define KSM_INTERRUPT_MASK__TYPE                                       uint32_t
#define KSM_INTERRUPT_MASK__READ                                    0x0000000fU
#define KSM_INTERRUPT_MASK__WRITE                                   0x0000000fU
#define KSM_INTERRUPT_MASK__PRESERVED                               0x00000000U
#define KSM_INTERRUPT_MASK__RESET_VALUE                             0x0000000fU

#endif /* __KSM_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::KSM_interrupt_clear */
/**
 * @defgroup at_apb_ksm_regs_core_interrupt_clear interrupt_clear
 * @brief Contains register fields associated with interrupt_clear. definitions.
 * @{
 */
#ifndef __KSM_INTERRUPT_CLEAR_MACRO__
#define __KSM_INTERRUPT_CLEAR_MACRO__

/* macros for field clear_intrpt0 */
/**
 * @defgroup at_apb_ksm_regs_core_clear_intrpt0_field clear_intrpt0_field
 * @brief macros for field clear_intrpt0
 * @details clear interrupt 0; not self reseting
 * @{
 */
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__SHIFT                             0
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__WIDTH                             1
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__MASK                    0x00000001U
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT0__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt1 */
/**
 * @defgroup at_apb_ksm_regs_core_clear_intrpt1_field clear_intrpt1_field
 * @brief macros for field clear_intrpt1
 * @details clear interrupt 1; not self reseting
 * @{
 */
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__SHIFT                             1
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__WIDTH                             1
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__MASK                    0x00000002U
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT1__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt2 */
/**
 * @defgroup at_apb_ksm_regs_core_clear_intrpt2_field clear_intrpt2_field
 * @brief macros for field clear_intrpt2
 * @details clear interrupt 2; not self reseting
 * @{
 */
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__SHIFT                             2
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__WIDTH                             1
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__MASK                    0x00000004U
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT2__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt3 */
/**
 * @defgroup at_apb_ksm_regs_core_clear_intrpt3_field clear_intrpt3_field
 * @brief macros for field clear_intrpt3
 * @details clear interrupt 3; not self reseting
 * @{
 */
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__SHIFT                             3
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__WIDTH                             1
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__MASK                    0x00000008U
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define KSM_INTERRUPT_CLEAR__CLEAR_INTRPT3__RESET_VALUE             0x00000000U
/** @} */
#define KSM_INTERRUPT_CLEAR__TYPE                                      uint32_t
#define KSM_INTERRUPT_CLEAR__READ                                   0x0000000fU
#define KSM_INTERRUPT_CLEAR__WRITE                                  0x0000000fU
#define KSM_INTERRUPT_CLEAR__PRESERVED                              0x00000000U
#define KSM_INTERRUPT_CLEAR__RESET_VALUE                            0x00000000U

#endif /* __KSM_INTERRUPT_CLEAR_MACRO__ */

/** @} end of interrupt_clear */

/* macros for BlueprintGlobalNameSpace::KSM_debug */
/**
 * @defgroup at_apb_ksm_regs_core_debug debug
 * @brief Contains register fields associated with debug. definitions.
 * @{
 */
#ifndef __KSM_DEBUG_MACRO__
#define __KSM_DEBUG_MACRO__

/* macros for field kb */
/**
 * @defgroup at_apb_ksm_regs_core_kb_field kb_field
 * @brief macros for field kb
 * @details {4'b0, debounce_available(array of booleans; 12b)}
 * @{
 */
#define KSM_DEBUG__KB__SHIFT                                                  0
#define KSM_DEBUG__KB__WIDTH                                                 16
#define KSM_DEBUG__KB__MASK                                         0x0000ffffU
#define KSM_DEBUG__KB__READ(src)                ((uint32_t)(src) & 0x0000ffffU)
#define KSM_DEBUG__KB__RESET_VALUE                                  0x00000000U
/** @} */

/* macros for field fifo */
/**
 * @defgroup at_apb_ksm_regs_core_fifo_field fifo_field
 * @brief macros for field fifo
 * @details {overrun, underrun, full, empty, 4'd0, rdaddr(unsigned int; 4b), wraddr(unsigned int; 4b)}
 * @{
 */
#define KSM_DEBUG__FIFO__SHIFT                                               16
#define KSM_DEBUG__FIFO__WIDTH                                               16
#define KSM_DEBUG__FIFO__MASK                                       0xffff0000U
#define KSM_DEBUG__FIFO__READ(src)      (((uint32_t)(src) & 0xffff0000U) >> 16)
#define KSM_DEBUG__FIFO__RESET_VALUE                                0x00000000U
/** @} */
#define KSM_DEBUG__TYPE                                                uint32_t
#define KSM_DEBUG__READ                                             0xffffffffU
#define KSM_DEBUG__PRESERVED                                        0x00000000U
#define KSM_DEBUG__RESET_VALUE                                      0x00000000U

#endif /* __KSM_DEBUG_MACRO__ */

/** @} end of debug */

/* macros for BlueprintGlobalNameSpace::KSM_debug2 */
/**
 * @defgroup at_apb_ksm_regs_core_debug2 debug2
 * @brief Contains register fields associated with debug2. definitions.
 * @{
 */
#ifndef __KSM_DEBUG2_MACRO__
#define __KSM_DEBUG2_MACRO__

/* macros for field kr */
/**
 * @defgroup at_apb_ksm_regs_core_kr_field kr_field
 * @brief macros for field kr
 * @details how many keys have been released?
 * @{
 */
#define KSM_DEBUG2__KR__SHIFT                                                 0
#define KSM_DEBUG2__KR__WIDTH                                                16
#define KSM_DEBUG2__KR__MASK                                        0x0000ffffU
#define KSM_DEBUG2__KR__READ(src)               ((uint32_t)(src) & 0x0000ffffU)
#define KSM_DEBUG2__KR__RESET_VALUE                                 0x00000000U
/** @} */

/* macros for field kp */
/**
 * @defgroup at_apb_ksm_regs_core_kp_field kp_field
 * @brief macros for field kp
 * @details how many keys have been pressed?
 * @{
 */
#define KSM_DEBUG2__KP__SHIFT                                                16
#define KSM_DEBUG2__KP__WIDTH                                                16
#define KSM_DEBUG2__KP__MASK                                        0xffff0000U
#define KSM_DEBUG2__KP__READ(src)       (((uint32_t)(src) & 0xffff0000U) >> 16)
#define KSM_DEBUG2__KP__RESET_VALUE                                 0x00000000U
/** @} */
#define KSM_DEBUG2__TYPE                                               uint32_t
#define KSM_DEBUG2__READ                                            0xffffffffU
#define KSM_DEBUG2__PRESERVED                                       0x00000000U
#define KSM_DEBUG2__RESET_VALUE                                     0x00000000U

#endif /* __KSM_DEBUG2_MACRO__ */

/** @} end of debug2 */

/* macros for BlueprintGlobalNameSpace::KSM_core_id */
/**
 * @defgroup at_apb_ksm_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __KSM_CORE_ID_MACRO__
#define __KSM_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_ksm_regs_core_id_field id_field
 * @brief macros for field id
 * @details KSM in ASCII
 * @{
 */
#define KSM_CORE_ID__ID__SHIFT                                                0
#define KSM_CORE_ID__ID__WIDTH                                               32
#define KSM_CORE_ID__ID__MASK                                       0xffffffffU
#define KSM_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define KSM_CORE_ID__ID__RESET_VALUE                                0x4b534d20U
/** @} */
#define KSM_CORE_ID__TYPE                                              uint32_t
#define KSM_CORE_ID__READ                                           0xffffffffU
#define KSM_CORE_ID__PRESERVED                                      0x00000000U
#define KSM_CORE_ID__RESET_VALUE                                    0x4b534d20U

#endif /* __KSM_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of AT_APB_KSM_REGS_CORE */
#endif /* __REG_AT_APB_KSM_REGS_CORE_H__ */
