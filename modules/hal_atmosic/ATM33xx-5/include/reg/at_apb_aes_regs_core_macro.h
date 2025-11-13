/*                                                                           */
/* File:       at_apb_aes_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_aes_regs_core.rdl           */
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


#ifndef __REG_AT_APB_AES_REGS_CORE_H__
#define __REG_AT_APB_AES_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_AES_REGS_CORE at_apb_aes_regs_core
 * @ingroup AT_REG
 * @brief at_apb_aes_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::AES_alert_test */
/**
 * @defgroup at_apb_aes_regs_core_alert_test alert_test
 * @brief control signals for all aes subcores definitions.
 * @{
 */
#ifndef __AES_ALERT_TEST_MACRO__
#define __AES_ALERT_TEST_MACRO__

/* macros for field fatal_fault */
/**
 * @defgroup at_apb_aes_regs_core_fatal_fault_field fatal_fault_field
 * @brief macros for field fatal_fault
 * @details Write 1 to trigger one alert event of this kind
 * @{
 */
#define AES_ALERT_TEST__FATAL_FAULT__SHIFT                                    0
#define AES_ALERT_TEST__FATAL_FAULT__WIDTH                                    1
#define AES_ALERT_TEST__FATAL_FAULT__MASK                           0x00000001U
#define AES_ALERT_TEST__FATAL_FAULT__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define AES_ALERT_TEST__FATAL_FAULT__WRITE(src) ((uint32_t)(src) & 0x00000001U)
#define AES_ALERT_TEST__FATAL_FAULT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AES_ALERT_TEST__FATAL_FAULT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AES_ALERT_TEST__FATAL_FAULT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AES_ALERT_TEST__FATAL_FAULT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AES_ALERT_TEST__FATAL_FAULT__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field recov_ctrl_update_err */
/**
 * @defgroup at_apb_aes_regs_core_recov_ctrl_update_err_field recov_ctrl_update_err_field
 * @brief macros for field recov_ctrl_update_err
 * @details Write 1 to trigger one alert event of this kind
 * @{
 */
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__SHIFT                          1
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__WIDTH                          1
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__MASK                 0x00000002U
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AES_ALERT_TEST__RECOV_CTRL_UPDATE_ERR__RESET_VALUE          0x00000000U
/** @} */
#define AES_ALERT_TEST__TYPE                                           uint32_t
#define AES_ALERT_TEST__READ                                        0x00000003U
#define AES_ALERT_TEST__WRITE                                       0x00000003U
#define AES_ALERT_TEST__PRESERVED                                   0x00000000U
#define AES_ALERT_TEST__RESET_VALUE                                 0x00000000U

#endif /* __AES_ALERT_TEST_MACRO__ */

/** @} end of alert_test */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_0 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_0 KEY_SHARE0_0
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_0_MACRO__
#define __AES_KEY_SHARE0_0_MACRO__

/* macros for field key_share0_0 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_0_field key_share0_0_field
 * @brief macros for field key_share0_0
 * @details initial Key Share 0
 * @{
 */
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__SHIFT                                 0
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__WIDTH                                32
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__MASK                        0xffffffffU
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_0__KEY_SHARE0_0__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_0__TYPE                                         uint32_t
#define AES_KEY_SHARE0_0__READ                                      0xffffffffU
#define AES_KEY_SHARE0_0__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_0__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_0__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_0_MACRO__ */

/** @} end of KEY_SHARE0_0 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_1 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_1 KEY_SHARE0_1
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_1_MACRO__
#define __AES_KEY_SHARE0_1_MACRO__

/* macros for field key_share0_1 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_1_field key_share0_1_field
 * @brief macros for field key_share0_1
 * @details For KEY_SHARE01
 * @{
 */
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__SHIFT                                 0
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__WIDTH                                32
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__MASK                        0xffffffffU
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_1__KEY_SHARE0_1__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_1__TYPE                                         uint32_t
#define AES_KEY_SHARE0_1__READ                                      0xffffffffU
#define AES_KEY_SHARE0_1__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_1__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_1__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_1_MACRO__ */

/** @} end of KEY_SHARE0_1 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_2 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_2 KEY_SHARE0_2
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_2_MACRO__
#define __AES_KEY_SHARE0_2_MACRO__

/* macros for field key_share0_2 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_2_field key_share0_2_field
 * @brief macros for field key_share0_2
 * @details For KEY_SHARE02
 * @{
 */
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__SHIFT                                 0
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__WIDTH                                32
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__MASK                        0xffffffffU
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_2__KEY_SHARE0_2__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_2__TYPE                                         uint32_t
#define AES_KEY_SHARE0_2__READ                                      0xffffffffU
#define AES_KEY_SHARE0_2__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_2__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_2__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_2_MACRO__ */

/** @} end of KEY_SHARE0_2 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_3 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_3 KEY_SHARE0_3
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_3_MACRO__
#define __AES_KEY_SHARE0_3_MACRO__

/* macros for field key_share0_3 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_3_field key_share0_3_field
 * @brief macros for field key_share0_3
 * @details For KEY_SHARE03
 * @{
 */
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__SHIFT                                 0
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__WIDTH                                32
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__MASK                        0xffffffffU
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_3__KEY_SHARE0_3__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_3__TYPE                                         uint32_t
#define AES_KEY_SHARE0_3__READ                                      0xffffffffU
#define AES_KEY_SHARE0_3__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_3__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_3__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_3_MACRO__ */

/** @} end of KEY_SHARE0_3 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_4 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_4 KEY_SHARE0_4
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_4_MACRO__
#define __AES_KEY_SHARE0_4_MACRO__

/* macros for field key_share0_4 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_4_field key_share0_4_field
 * @brief macros for field key_share0_4
 * @details For KEY_SHARE04
 * @{
 */
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__SHIFT                                 0
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__WIDTH                                32
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__MASK                        0xffffffffU
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_4__KEY_SHARE0_4__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_4__TYPE                                         uint32_t
#define AES_KEY_SHARE0_4__READ                                      0xffffffffU
#define AES_KEY_SHARE0_4__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_4__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_4__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_4_MACRO__ */

/** @} end of KEY_SHARE0_4 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_5 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_5 KEY_SHARE0_5
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_5_MACRO__
#define __AES_KEY_SHARE0_5_MACRO__

/* macros for field key_share0_5 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_5_field key_share0_5_field
 * @brief macros for field key_share0_5
 * @details For KEY_SHARE05
 * @{
 */
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__SHIFT                                 0
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__WIDTH                                32
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__MASK                        0xffffffffU
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_5__KEY_SHARE0_5__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_5__TYPE                                         uint32_t
#define AES_KEY_SHARE0_5__READ                                      0xffffffffU
#define AES_KEY_SHARE0_5__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_5__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_5__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_5_MACRO__ */

/** @} end of KEY_SHARE0_5 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_6 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_6 KEY_SHARE0_6
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_6_MACRO__
#define __AES_KEY_SHARE0_6_MACRO__

/* macros for field key_share0_6 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_6_field key_share0_6_field
 * @brief macros for field key_share0_6
 * @details For KEY_SHARE06
 * @{
 */
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__SHIFT                                 0
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__WIDTH                                32
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__MASK                        0xffffffffU
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_6__KEY_SHARE0_6__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_6__TYPE                                         uint32_t
#define AES_KEY_SHARE0_6__READ                                      0xffffffffU
#define AES_KEY_SHARE0_6__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_6__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_6__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_6_MACRO__ */

/** @} end of KEY_SHARE0_6 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE0_7 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE0_7 KEY_SHARE0_7
 * @brief Initial Key Registers Share 0. The actual initial key corresponds to Initial Key Registers Share 0 XORed with Initial Key Registers Share 1. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE0_7_MACRO__
#define __AES_KEY_SHARE0_7_MACRO__

/* macros for field key_share0_7 */
/**
 * @defgroup at_apb_aes_regs_core_key_share0_7_field key_share0_7_field
 * @brief macros for field key_share0_7
 * @details For KEY_SHARE07
 * @{
 */
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__SHIFT                                 0
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__WIDTH                                32
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__MASK                        0xffffffffU
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE0_7__KEY_SHARE0_7__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE0_7__TYPE                                         uint32_t
#define AES_KEY_SHARE0_7__READ                                      0xffffffffU
#define AES_KEY_SHARE0_7__WRITE                                     0xffffffffU
#define AES_KEY_SHARE0_7__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE0_7__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE0_7_MACRO__ */

/** @} end of KEY_SHARE0_7 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_0 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_0 KEY_SHARE1_0
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_0_MACRO__
#define __AES_KEY_SHARE1_0_MACRO__

/* macros for field key_share1_0 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_0_field key_share1_0_field
 * @brief macros for field key_share1_0
 * @details initial Key Share 1
 * @{
 */
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__SHIFT                                 0
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__WIDTH                                32
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__MASK                        0xffffffffU
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_0__KEY_SHARE1_0__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_0__TYPE                                         uint32_t
#define AES_KEY_SHARE1_0__READ                                      0xffffffffU
#define AES_KEY_SHARE1_0__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_0__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_0__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_0_MACRO__ */

/** @} end of KEY_SHARE1_0 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_1 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_1 KEY_SHARE1_1
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_1_MACRO__
#define __AES_KEY_SHARE1_1_MACRO__

/* macros for field key_share1_1 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_1_field key_share1_1_field
 * @brief macros for field key_share1_1
 * @details For KEY_SHARE11
 * @{
 */
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__SHIFT                                 0
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__WIDTH                                32
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__MASK                        0xffffffffU
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_1__KEY_SHARE1_1__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_1__TYPE                                         uint32_t
#define AES_KEY_SHARE1_1__READ                                      0xffffffffU
#define AES_KEY_SHARE1_1__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_1__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_1__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_1_MACRO__ */

/** @} end of KEY_SHARE1_1 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_2 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_2 KEY_SHARE1_2
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_2_MACRO__
#define __AES_KEY_SHARE1_2_MACRO__

/* macros for field key_share1_2 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_2_field key_share1_2_field
 * @brief macros for field key_share1_2
 * @details For KEY_SHARE12
 * @{
 */
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__SHIFT                                 0
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__WIDTH                                32
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__MASK                        0xffffffffU
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_2__KEY_SHARE1_2__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_2__TYPE                                         uint32_t
#define AES_KEY_SHARE1_2__READ                                      0xffffffffU
#define AES_KEY_SHARE1_2__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_2__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_2__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_2_MACRO__ */

/** @} end of KEY_SHARE1_2 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_3 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_3 KEY_SHARE1_3
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_3_MACRO__
#define __AES_KEY_SHARE1_3_MACRO__

/* macros for field key_share1_3 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_3_field key_share1_3_field
 * @brief macros for field key_share1_3
 * @details For KEY_SHARE13
 * @{
 */
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__SHIFT                                 0
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__WIDTH                                32
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__MASK                        0xffffffffU
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_3__KEY_SHARE1_3__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_3__TYPE                                         uint32_t
#define AES_KEY_SHARE1_3__READ                                      0xffffffffU
#define AES_KEY_SHARE1_3__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_3__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_3__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_3_MACRO__ */

/** @} end of KEY_SHARE1_3 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_4 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_4 KEY_SHARE1_4
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_4_MACRO__
#define __AES_KEY_SHARE1_4_MACRO__

/* macros for field key_share1_4 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_4_field key_share1_4_field
 * @brief macros for field key_share1_4
 * @details For KEY_SHARE14
 * @{
 */
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__SHIFT                                 0
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__WIDTH                                32
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__MASK                        0xffffffffU
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_4__KEY_SHARE1_4__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_4__TYPE                                         uint32_t
#define AES_KEY_SHARE1_4__READ                                      0xffffffffU
#define AES_KEY_SHARE1_4__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_4__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_4__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_4_MACRO__ */

/** @} end of KEY_SHARE1_4 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_5 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_5 KEY_SHARE1_5
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_5_MACRO__
#define __AES_KEY_SHARE1_5_MACRO__

/* macros for field key_share1_5 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_5_field key_share1_5_field
 * @brief macros for field key_share1_5
 * @details For KEY_SHARE15
 * @{
 */
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__SHIFT                                 0
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__WIDTH                                32
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__MASK                        0xffffffffU
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_5__KEY_SHARE1_5__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_5__TYPE                                         uint32_t
#define AES_KEY_SHARE1_5__READ                                      0xffffffffU
#define AES_KEY_SHARE1_5__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_5__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_5__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_5_MACRO__ */

/** @} end of KEY_SHARE1_5 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_6 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_6 KEY_SHARE1_6
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_6_MACRO__
#define __AES_KEY_SHARE1_6_MACRO__

/* macros for field key_share1_6 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_6_field key_share1_6_field
 * @brief macros for field key_share1_6
 * @details For KEY_SHARE16
 * @{
 */
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__SHIFT                                 0
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__WIDTH                                32
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__MASK                        0xffffffffU
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_6__KEY_SHARE1_6__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_6__TYPE                                         uint32_t
#define AES_KEY_SHARE1_6__READ                                      0xffffffffU
#define AES_KEY_SHARE1_6__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_6__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_6__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_6_MACRO__ */

/** @} end of KEY_SHARE1_6 */

/* macros for BlueprintGlobalNameSpace::AES_KEY_SHARE1_7 */
/**
 * @defgroup at_apb_aes_regs_core_KEY_SHARE1_7 KEY_SHARE1_7
 * @brief Initial Key Registers Share 1. The actual initial key corresponds to Initial Key Registers Share 1 XORed with Initial Key Registers Share 0. Loaded into the internal Full Key register upon starting encryption/decryption of the next block. All key registers (Share 0 and Share 1) must be written at least once when the key is changed, regardless of key length (write random data for unused bits). The order in which the registers are updated does not matter. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to these registers are ignored. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_KEY_SHARE1_7_MACRO__
#define __AES_KEY_SHARE1_7_MACRO__

/* macros for field key_share1_7 */
/**
 * @defgroup at_apb_aes_regs_core_key_share1_7_field key_share1_7_field
 * @brief macros for field key_share1_7
 * @details For KEY_SHARE17
 * @{
 */
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__SHIFT                                 0
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__WIDTH                                32
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__MASK                        0xffffffffU
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_KEY_SHARE1_7__KEY_SHARE1_7__RESET_VALUE                 0x00000000U
/** @} */
#define AES_KEY_SHARE1_7__TYPE                                         uint32_t
#define AES_KEY_SHARE1_7__READ                                      0xffffffffU
#define AES_KEY_SHARE1_7__WRITE                                     0xffffffffU
#define AES_KEY_SHARE1_7__PRESERVED                                 0x00000000U
#define AES_KEY_SHARE1_7__RESET_VALUE                               0x00000000U

#endif /* __AES_KEY_SHARE1_7_MACRO__ */

/** @} end of KEY_SHARE1_7 */

/* macros for BlueprintGlobalNameSpace::AES_IV_0 */
/**
 * @defgroup at_apb_aes_regs_core_IV_0 IV_0
 * @brief Initialization Vector Registers. The initialization vector (IV) or initial counter value must be written to these registers when starting a new message in CBC or CTR mode (see Control Register), respectively. In CBC and CTR modes, the AES unit does not start encryption/decryption with a partially updated IV. Each register has to be written at least once. The order in which the registers are written does not matter. If the AES unit is non-idle, writes to these registers are ignored. Whenever starting a new message, the corresponding IV value must be provided by the processor. Once started, the AES unit automatically updates the contents of these registers. In ECB mode, the IV registers are not used and do not need to be configured. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_IV_0_MACRO__
#define __AES_IV_0_MACRO__

/* macros for field iv_0 */
/**
 * @defgroup at_apb_aes_regs_core_iv_0_field iv_0_field
 * @brief macros for field iv_0
 * @details Initialization Vector
 * @{
 */
#define AES_IV_0__IV_0__SHIFT                                                 0
#define AES_IV_0__IV_0__WIDTH                                                32
#define AES_IV_0__IV_0__MASK                                        0xffffffffU
#define AES_IV_0__IV_0__READ(src)               ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_0__IV_0__WRITE(src)              ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_0__IV_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_IV_0__IV_0__VERIFY(src)       (!(((uint32_t)(src) & ~0xffffffffU)))
#define AES_IV_0__IV_0__RESET_VALUE                                 0x00000000U
/** @} */
#define AES_IV_0__TYPE                                                 uint32_t
#define AES_IV_0__READ                                              0xffffffffU
#define AES_IV_0__WRITE                                             0xffffffffU
#define AES_IV_0__PRESERVED                                         0x00000000U
#define AES_IV_0__RESET_VALUE                                       0x00000000U

#endif /* __AES_IV_0_MACRO__ */

/** @} end of IV_0 */

/* macros for BlueprintGlobalNameSpace::AES_IV_1 */
/**
 * @defgroup at_apb_aes_regs_core_IV_1 IV_1
 * @brief Initialization Vector Registers. The initialization vector (IV) or initial counter value must be written to these registers when starting a new message in CBC or CTR mode (see Control Register), respectively. In CBC and CTR modes, the AES unit does not start encryption/decryption with a partially updated IV. Each register has to be written at least once. The order in which the registers are written does not matter. If the AES unit is non-idle, writes to these registers are ignored. Whenever starting a new message, the corresponding IV value must be provided by the processor. Once started, the AES unit automatically updates the contents of these registers. In ECB mode, the IV registers are not used and do not need to be configured. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_IV_1_MACRO__
#define __AES_IV_1_MACRO__

/* macros for field iv_1 */
/**
 * @defgroup at_apb_aes_regs_core_iv_1_field iv_1_field
 * @brief macros for field iv_1
 * @details For IV1
 * @{
 */
#define AES_IV_1__IV_1__SHIFT                                                 0
#define AES_IV_1__IV_1__WIDTH                                                32
#define AES_IV_1__IV_1__MASK                                        0xffffffffU
#define AES_IV_1__IV_1__READ(src)               ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_1__IV_1__WRITE(src)              ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_1__IV_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_IV_1__IV_1__VERIFY(src)       (!(((uint32_t)(src) & ~0xffffffffU)))
#define AES_IV_1__IV_1__RESET_VALUE                                 0x00000000U
/** @} */
#define AES_IV_1__TYPE                                                 uint32_t
#define AES_IV_1__READ                                              0xffffffffU
#define AES_IV_1__WRITE                                             0xffffffffU
#define AES_IV_1__PRESERVED                                         0x00000000U
#define AES_IV_1__RESET_VALUE                                       0x00000000U

#endif /* __AES_IV_1_MACRO__ */

/** @} end of IV_1 */

/* macros for BlueprintGlobalNameSpace::AES_IV_2 */
/**
 * @defgroup at_apb_aes_regs_core_IV_2 IV_2
 * @brief Initialization Vector Registers. The initialization vector (IV) or initial counter value must be written to these registers when starting a new message in CBC or CTR mode (see Control Register), respectively. In CBC and CTR modes, the AES unit does not start encryption/decryption with a partially updated IV. Each register has to be written at least once. The order in which the registers are written does not matter. If the AES unit is non-idle, writes to these registers are ignored. Whenever starting a new message, the corresponding IV value must be provided by the processor. Once started, the AES unit automatically updates the contents of these registers. In ECB mode, the IV registers are not used and do not need to be configured. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_IV_2_MACRO__
#define __AES_IV_2_MACRO__

/* macros for field iv_2 */
/**
 * @defgroup at_apb_aes_regs_core_iv_2_field iv_2_field
 * @brief macros for field iv_2
 * @details For IV2
 * @{
 */
#define AES_IV_2__IV_2__SHIFT                                                 0
#define AES_IV_2__IV_2__WIDTH                                                32
#define AES_IV_2__IV_2__MASK                                        0xffffffffU
#define AES_IV_2__IV_2__READ(src)               ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_2__IV_2__WRITE(src)              ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_2__IV_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_IV_2__IV_2__VERIFY(src)       (!(((uint32_t)(src) & ~0xffffffffU)))
#define AES_IV_2__IV_2__RESET_VALUE                                 0x00000000U
/** @} */
#define AES_IV_2__TYPE                                                 uint32_t
#define AES_IV_2__READ                                              0xffffffffU
#define AES_IV_2__WRITE                                             0xffffffffU
#define AES_IV_2__PRESERVED                                         0x00000000U
#define AES_IV_2__RESET_VALUE                                       0x00000000U

#endif /* __AES_IV_2_MACRO__ */

/** @} end of IV_2 */

/* macros for BlueprintGlobalNameSpace::AES_IV_3 */
/**
 * @defgroup at_apb_aes_regs_core_IV_3 IV_3
 * @brief Initialization Vector Registers. The initialization vector (IV) or initial counter value must be written to these registers when starting a new message in CBC or CTR mode (see Control Register), respectively. In CBC and CTR modes, the AES unit does not start encryption/decryption with a partially updated IV. Each register has to be written at least once. The order in which the registers are written does not matter. If the AES unit is non-idle, writes to these registers are ignored. Whenever starting a new message, the corresponding IV value must be provided by the processor. Once started, the AES unit automatically updates the contents of these registers. In ECB mode, the IV registers are not used and do not need to be configured. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_IV_3_MACRO__
#define __AES_IV_3_MACRO__

/* macros for field iv_3 */
/**
 * @defgroup at_apb_aes_regs_core_iv_3_field iv_3_field
 * @brief macros for field iv_3
 * @details For IV3
 * @{
 */
#define AES_IV_3__IV_3__SHIFT                                                 0
#define AES_IV_3__IV_3__WIDTH                                                32
#define AES_IV_3__IV_3__MASK                                        0xffffffffU
#define AES_IV_3__IV_3__READ(src)               ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_3__IV_3__WRITE(src)              ((uint32_t)(src) & 0xffffffffU)
#define AES_IV_3__IV_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_IV_3__IV_3__VERIFY(src)       (!(((uint32_t)(src) & ~0xffffffffU)))
#define AES_IV_3__IV_3__RESET_VALUE                                 0x00000000U
/** @} */
#define AES_IV_3__TYPE                                                 uint32_t
#define AES_IV_3__READ                                              0xffffffffU
#define AES_IV_3__WRITE                                             0xffffffffU
#define AES_IV_3__PRESERVED                                         0x00000000U
#define AES_IV_3__RESET_VALUE                                       0x00000000U

#endif /* __AES_IV_3_MACRO__ */

/** @} end of IV_3 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_IN_0 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_IN_0 DATA_IN_0
 * @brief Input Data Registers. If MANUAL_OPERATION=0 (see Control Register), the AES unit automatically starts encryption/decryption after all Input Data registers have been written. Each register has to be written at least once. The order in which the registers are written does not matter. Loaded into the internal State register upon starting encryption/decryption of the next block. After that, the processor can update the Input Data registers (See INPUT_READY field of Status Register). Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_IN_0_MACRO__
#define __AES_DATA_IN_0_MACRO__

/* macros for field data_in_0 */
/**
 * @defgroup at_apb_aes_regs_core_data_in_0_field data_in_0_field
 * @brief macros for field data_in_0
 * @details Input Data
 * @{
 */
#define AES_DATA_IN_0__DATA_IN_0__SHIFT                                       0
#define AES_DATA_IN_0__DATA_IN_0__WIDTH                                      32
#define AES_DATA_IN_0__DATA_IN_0__MASK                              0xffffffffU
#define AES_DATA_IN_0__DATA_IN_0__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_0__DATA_IN_0__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_0__DATA_IN_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_DATA_IN_0__DATA_IN_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_DATA_IN_0__DATA_IN_0__RESET_VALUE                       0x00000000U
/** @} */
#define AES_DATA_IN_0__TYPE                                            uint32_t
#define AES_DATA_IN_0__READ                                         0xffffffffU
#define AES_DATA_IN_0__WRITE                                        0xffffffffU
#define AES_DATA_IN_0__PRESERVED                                    0x00000000U
#define AES_DATA_IN_0__RESET_VALUE                                  0x00000000U

#endif /* __AES_DATA_IN_0_MACRO__ */

/** @} end of DATA_IN_0 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_IN_1 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_IN_1 DATA_IN_1
 * @brief Input Data Registers. If MANUAL_OPERATION=0 (see Control Register), the AES unit automatically starts encryption/decryption after all Input Data registers have been written. Each register has to be written at least once. The order in which the registers are written does not matter. Loaded into the internal State register upon starting encryption/decryption of the next block. After that, the processor can update the Input Data registers (See INPUT_READY field of Status Register). Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_IN_1_MACRO__
#define __AES_DATA_IN_1_MACRO__

/* macros for field data_in_1 */
/**
 * @defgroup at_apb_aes_regs_core_data_in_1_field data_in_1_field
 * @brief macros for field data_in_1
 * @details For DATA_IN1
 * @{
 */
#define AES_DATA_IN_1__DATA_IN_1__SHIFT                                       0
#define AES_DATA_IN_1__DATA_IN_1__WIDTH                                      32
#define AES_DATA_IN_1__DATA_IN_1__MASK                              0xffffffffU
#define AES_DATA_IN_1__DATA_IN_1__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_1__DATA_IN_1__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_1__DATA_IN_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_DATA_IN_1__DATA_IN_1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_DATA_IN_1__DATA_IN_1__RESET_VALUE                       0x00000000U
/** @} */
#define AES_DATA_IN_1__TYPE                                            uint32_t
#define AES_DATA_IN_1__READ                                         0xffffffffU
#define AES_DATA_IN_1__WRITE                                        0xffffffffU
#define AES_DATA_IN_1__PRESERVED                                    0x00000000U
#define AES_DATA_IN_1__RESET_VALUE                                  0x00000000U

#endif /* __AES_DATA_IN_1_MACRO__ */

/** @} end of DATA_IN_1 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_IN_2 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_IN_2 DATA_IN_2
 * @brief Input Data Registers. If MANUAL_OPERATION=0 (see Control Register), the AES unit automatically starts encryption/decryption after all Input Data registers have been written. Each register has to be written at least once. The order in which the registers are written does not matter. Loaded into the internal State register upon starting encryption/decryption of the next block. After that, the processor can update the Input Data registers (See INPUT_READY field of Status Register). Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_IN_2_MACRO__
#define __AES_DATA_IN_2_MACRO__

/* macros for field data_in_2 */
/**
 * @defgroup at_apb_aes_regs_core_data_in_2_field data_in_2_field
 * @brief macros for field data_in_2
 * @details For DATA_IN2
 * @{
 */
#define AES_DATA_IN_2__DATA_IN_2__SHIFT                                       0
#define AES_DATA_IN_2__DATA_IN_2__WIDTH                                      32
#define AES_DATA_IN_2__DATA_IN_2__MASK                              0xffffffffU
#define AES_DATA_IN_2__DATA_IN_2__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_2__DATA_IN_2__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_2__DATA_IN_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_DATA_IN_2__DATA_IN_2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_DATA_IN_2__DATA_IN_2__RESET_VALUE                       0x00000000U
/** @} */
#define AES_DATA_IN_2__TYPE                                            uint32_t
#define AES_DATA_IN_2__READ                                         0xffffffffU
#define AES_DATA_IN_2__WRITE                                        0xffffffffU
#define AES_DATA_IN_2__PRESERVED                                    0x00000000U
#define AES_DATA_IN_2__RESET_VALUE                                  0x00000000U

#endif /* __AES_DATA_IN_2_MACRO__ */

/** @} end of DATA_IN_2 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_IN_3 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_IN_3 DATA_IN_3
 * @brief Input Data Registers. If MANUAL_OPERATION=0 (see Control Register), the AES unit automatically starts encryption/decryption after all Input Data registers have been written. Each register has to be written at least once. The order in which the registers are written does not matter. Loaded into the internal State register upon starting encryption/decryption of the next block. After that, the processor can update the Input Data registers (See INPUT_READY field of Status Register). Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_IN_3_MACRO__
#define __AES_DATA_IN_3_MACRO__

/* macros for field data_in_3 */
/**
 * @defgroup at_apb_aes_regs_core_data_in_3_field data_in_3_field
 * @brief macros for field data_in_3
 * @details For DATA_IN3
 * @{
 */
#define AES_DATA_IN_3__DATA_IN_3__SHIFT                                       0
#define AES_DATA_IN_3__DATA_IN_3__WIDTH                                      32
#define AES_DATA_IN_3__DATA_IN_3__MASK                              0xffffffffU
#define AES_DATA_IN_3__DATA_IN_3__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_3__DATA_IN_3__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_IN_3__DATA_IN_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AES_DATA_IN_3__DATA_IN_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AES_DATA_IN_3__DATA_IN_3__RESET_VALUE                       0x00000000U
/** @} */
#define AES_DATA_IN_3__TYPE                                            uint32_t
#define AES_DATA_IN_3__READ                                         0xffffffffU
#define AES_DATA_IN_3__WRITE                                        0xffffffffU
#define AES_DATA_IN_3__PRESERVED                                    0x00000000U
#define AES_DATA_IN_3__RESET_VALUE                                  0x00000000U

#endif /* __AES_DATA_IN_3_MACRO__ */

/** @} end of DATA_IN_3 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_OUT_0 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_OUT_0 DATA_OUT_0
 * @brief Output Data Register. Holds the output data produced by the AES unit during the last encryption/decryption operation. If MANUAL_OPERATION=0 (see Control Register), the AES unit is stalled when the previous output data has not yet been read and is about to be overwritten. Each register has to be read at least once. The order in which the registers are read does not matter. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_OUT_0_MACRO__
#define __AES_DATA_OUT_0_MACRO__

/* macros for field data_out_0 */
/**
 * @defgroup at_apb_aes_regs_core_data_out_0_field data_out_0_field
 * @brief macros for field data_out_0
 * @details Output Data
 * @{
 */
#define AES_DATA_OUT_0__DATA_OUT_0__SHIFT                                     0
#define AES_DATA_OUT_0__DATA_OUT_0__WIDTH                                    32
#define AES_DATA_OUT_0__DATA_OUT_0__MASK                            0xffffffffU
#define AES_DATA_OUT_0__DATA_OUT_0__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_OUT_0__DATA_OUT_0__RESET_VALUE                     0x00000000U
/** @} */
#define AES_DATA_OUT_0__TYPE                                           uint32_t
#define AES_DATA_OUT_0__READ                                        0xffffffffU
#define AES_DATA_OUT_0__PRESERVED                                   0x00000000U
#define AES_DATA_OUT_0__RESET_VALUE                                 0x00000000U

#endif /* __AES_DATA_OUT_0_MACRO__ */

/** @} end of DATA_OUT_0 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_OUT_1 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_OUT_1 DATA_OUT_1
 * @brief Output Data Register. Holds the output data produced by the AES unit during the last encryption/decryption operation. If MANUAL_OPERATION=0 (see Control Register), the AES unit is stalled when the previous output data has not yet been read and is about to be overwritten. Each register has to be read at least once. The order in which the registers are read does not matter. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_OUT_1_MACRO__
#define __AES_DATA_OUT_1_MACRO__

/* macros for field data_out_1 */
/**
 * @defgroup at_apb_aes_regs_core_data_out_1_field data_out_1_field
 * @brief macros for field data_out_1
 * @details For DATA_OUT1
 * @{
 */
#define AES_DATA_OUT_1__DATA_OUT_1__SHIFT                                     0
#define AES_DATA_OUT_1__DATA_OUT_1__WIDTH                                    32
#define AES_DATA_OUT_1__DATA_OUT_1__MASK                            0xffffffffU
#define AES_DATA_OUT_1__DATA_OUT_1__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_OUT_1__DATA_OUT_1__RESET_VALUE                     0x00000000U
/** @} */
#define AES_DATA_OUT_1__TYPE                                           uint32_t
#define AES_DATA_OUT_1__READ                                        0xffffffffU
#define AES_DATA_OUT_1__PRESERVED                                   0x00000000U
#define AES_DATA_OUT_1__RESET_VALUE                                 0x00000000U

#endif /* __AES_DATA_OUT_1_MACRO__ */

/** @} end of DATA_OUT_1 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_OUT_2 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_OUT_2 DATA_OUT_2
 * @brief Output Data Register. Holds the output data produced by the AES unit during the last encryption/decryption operation. If MANUAL_OPERATION=0 (see Control Register), the AES unit is stalled when the previous output data has not yet been read and is about to be overwritten. Each register has to be read at least once. The order in which the registers are read does not matter. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_OUT_2_MACRO__
#define __AES_DATA_OUT_2_MACRO__

/* macros for field data_out_2 */
/**
 * @defgroup at_apb_aes_regs_core_data_out_2_field data_out_2_field
 * @brief macros for field data_out_2
 * @details For DATA_OUT2
 * @{
 */
#define AES_DATA_OUT_2__DATA_OUT_2__SHIFT                                     0
#define AES_DATA_OUT_2__DATA_OUT_2__WIDTH                                    32
#define AES_DATA_OUT_2__DATA_OUT_2__MASK                            0xffffffffU
#define AES_DATA_OUT_2__DATA_OUT_2__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_OUT_2__DATA_OUT_2__RESET_VALUE                     0x00000000U
/** @} */
#define AES_DATA_OUT_2__TYPE                                           uint32_t
#define AES_DATA_OUT_2__READ                                        0xffffffffU
#define AES_DATA_OUT_2__PRESERVED                                   0x00000000U
#define AES_DATA_OUT_2__RESET_VALUE                                 0x00000000U

#endif /* __AES_DATA_OUT_2_MACRO__ */

/** @} end of DATA_OUT_2 */

/* macros for BlueprintGlobalNameSpace::AES_DATA_OUT_3 */
/**
 * @defgroup at_apb_aes_regs_core_DATA_OUT_3 DATA_OUT_3
 * @brief Output Data Register. Holds the output data produced by the AES unit during the last encryption/decryption operation. If MANUAL_OPERATION=0 (see Control Register), the AES unit is stalled when the previous output data has not yet been read and is about to be overwritten. Each register has to be read at least once. The order in which the registers are read does not matter. Upon reset, these registers are cleared with pseudo-random data. definitions.
 * @{
 */
#ifndef __AES_DATA_OUT_3_MACRO__
#define __AES_DATA_OUT_3_MACRO__

/* macros for field data_out_3 */
/**
 * @defgroup at_apb_aes_regs_core_data_out_3_field data_out_3_field
 * @brief macros for field data_out_3
 * @details For DATA_OUT3
 * @{
 */
#define AES_DATA_OUT_3__DATA_OUT_3__SHIFT                                     0
#define AES_DATA_OUT_3__DATA_OUT_3__WIDTH                                    32
#define AES_DATA_OUT_3__DATA_OUT_3__MASK                            0xffffffffU
#define AES_DATA_OUT_3__DATA_OUT_3__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define AES_DATA_OUT_3__DATA_OUT_3__RESET_VALUE                     0x00000000U
/** @} */
#define AES_DATA_OUT_3__TYPE                                           uint32_t
#define AES_DATA_OUT_3__READ                                        0xffffffffU
#define AES_DATA_OUT_3__PRESERVED                                   0x00000000U
#define AES_DATA_OUT_3__RESET_VALUE                                 0x00000000U

#endif /* __AES_DATA_OUT_3_MACRO__ */

/** @} end of DATA_OUT_3 */

/* macros for BlueprintGlobalNameSpace::AES_CTRL_SHADOWED */
/**
 * @defgroup at_apb_aes_regs_core_CTRL_SHADOWED CTRL_SHADOWED
 * @brief Control Register. Can only be updated when the AES unit is idle. If the AES unit is non-idle, writes to this register are ignored. This register is shadowed, meaning two subsequent write operations are required to change its content. If the two write operations try to set a different value, a recoverable alert is triggered (See Status Register). A read operation clears the internal phase tracking: The next write operation is always considered a first write operation of an update sequence. Any write operation to this register will clear the status tracking required for automatic mode (See MANUAL_OPERATION field). A write to the Control Register is considered the start of a new message. Hence, software needs to provide new key, IV and input data afterwards. definitions.
 * @{
 */
#ifndef __AES_CTRL_SHADOWED_MACRO__
#define __AES_CTRL_SHADOWED_MACRO__

/* macros for field OPERATION */
/**
 * @defgroup at_apb_aes_regs_core_OPERATION_field OPERATION_field
 * @brief macros for field OPERATION
 * @details Select encryption(0) or decryption(1) operation of AES unit.
 * @{
 */
#define AES_CTRL_SHADOWED__OPERATION__SHIFT                                   0
#define AES_CTRL_SHADOWED__OPERATION__WIDTH                                   1
#define AES_CTRL_SHADOWED__OPERATION__MASK                          0x00000001U
#define AES_CTRL_SHADOWED__OPERATION__READ(src) ((uint32_t)(src) & 0x00000001U)
#define AES_CTRL_SHADOWED__OPERATION__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AES_CTRL_SHADOWED__OPERATION__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AES_CTRL_SHADOWED__OPERATION__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AES_CTRL_SHADOWED__OPERATION__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AES_CTRL_SHADOWED__OPERATION__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AES_CTRL_SHADOWED__OPERATION__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field MODE */
/**
 * @defgroup at_apb_aes_regs_core_MODE_field MODE_field
 * @brief macros for field MODE
 * @details 6-bit one-hot field to select AES block cipher mode. Invalid input values,  i.e., values with multiple bits set and value 6'b00_0000, are mapped to AES_NONE (6'b10_0000).  1 AES_ECB 6'b00_0001: Electronic Codebook (ECB) mode.  2 AES_CBC 6'b00_0010: Cipher Block Chaining (CBC) mode.  4 AES_CFB 6'b00_0100: Cipher Feedback (CFB) mode.  8 AES_OFB 6'b00_1000: Output Feedback (OFB) mode.  16 AES_CTR 6'b01_0000: Counter (CTR) mode.  32 AES_NONE 6'b10_0000: Invalid input values, i.e., value with multiple bits set and value 6'b00_0000, are mapped to AES_NONE.  Other values are reserved.
 * @{
 */
#define AES_CTRL_SHADOWED__MODE__SHIFT                                        1
#define AES_CTRL_SHADOWED__MODE__WIDTH                                        6
#define AES_CTRL_SHADOWED__MODE__MASK                               0x0000007eU
#define AES_CTRL_SHADOWED__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000007eU) >> 1)
#define AES_CTRL_SHADOWED__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000007eU)
#define AES_CTRL_SHADOWED__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007eU) | (((uint32_t)(src) <<\
                    1) & 0x0000007eU)
#define AES_CTRL_SHADOWED__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000007eU)))
#define AES_CTRL_SHADOWED__MODE__RESET_VALUE                        0x00000020U
/** @} */

/* macros for field KEY_LEN */
/**
 * @defgroup at_apb_aes_regs_core_KEY_LEN_field KEY_LEN_field
 * @brief macros for field KEY_LEN
 * @details 3-bit one-hot field to select AES key length.  Invalid input values, i.e., values with multiple bits set, value 3'b000,  and value 3'b010 in case 192-bit keys are not supported (because disabled at compile time) are mapped to AES_256 (3'b100).  1 AES_128 3'b001 128-bit key length.  2 AES_192 3'b010 192-bit key length.  In case support for 192-bit keys has been disabled at compile time,  setting this value results in configuring AES_256 (3'b100).  4 AES_256 3'b100 256-bit key length.  Invalid input values, i.e., values with multiple bits set, value 3'b000,  and value 3'b010 in case 192-bit keys are not supported (because disabled at compile time) are mapped to AES_256.
 * @{
 */
#define AES_CTRL_SHADOWED__KEY_LEN__SHIFT                                     7
#define AES_CTRL_SHADOWED__KEY_LEN__WIDTH                                     3
#define AES_CTRL_SHADOWED__KEY_LEN__MASK                            0x00000380U
#define AES_CTRL_SHADOWED__KEY_LEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define AES_CTRL_SHADOWED__KEY_LEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define AES_CTRL_SHADOWED__KEY_LEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define AES_CTRL_SHADOWED__KEY_LEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define AES_CTRL_SHADOWED__KEY_LEN__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field SIDELOAD */
/**
 * @defgroup at_apb_aes_regs_core_SIDELOAD_field SIDELOAD_field
 * @brief macros for field SIDELOAD
 * @details Controls whether the AES unit uses the key provided by the key manager via key sideload interface (1) or  the key provided by software via Initial Key Registers KEY_SHARE1_0 - KEY_SHARE1_7 (0).
 * @{
 */
#define AES_CTRL_SHADOWED__SIDELOAD__SHIFT                                   10
#define AES_CTRL_SHADOWED__SIDELOAD__WIDTH                                    1
#define AES_CTRL_SHADOWED__SIDELOAD__MASK                           0x00000400U
#define AES_CTRL_SHADOWED__SIDELOAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define AES_CTRL_SHADOWED__SIDELOAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define AES_CTRL_SHADOWED__SIDELOAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define AES_CTRL_SHADOWED__SIDELOAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define AES_CTRL_SHADOWED__SIDELOAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define AES_CTRL_SHADOWED__SIDELOAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define AES_CTRL_SHADOWED__SIDELOAD__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field MANUAL_OPERATION */
/**
 * @defgroup at_apb_aes_regs_core_MANUAL_OPERATION_field MANUAL_OPERATION_field
 * @brief macros for field MANUAL_OPERATION
 * @details Controls whether the AES unit is operated in normal/automatic mode (0) or fully manual mode (1). In automatic mode (0), the AES unit automatically i) starts to encrypt/decrypt when it receives new input data, and ii) stalls during the last encryption/decryption cycle if the previous output data has not yet been read. This is the most efficient mode to operate in. Note that the corresponding status tracking is automatically cleared upon a write to the Control Register. In manual mode (1), the AES unit i) only starts to encrypt/decrypt after receiving a start trigger (see Trigger Register), and ii) overwrites previous output data irrespective of whether it has been read out or not. This mode is useful if software needs full control over the AES unit.
 * @{
 */
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__SHIFT                           11
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__WIDTH                            1
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__MASK                   0x00000800U
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define AES_CTRL_SHADOWED__MANUAL_OPERATION__RESET_VALUE            0x00000000U
/** @} */

/* macros for field FORCE_ZERO_MASKS */
/**
 * @defgroup at_apb_aes_regs_core_FORCE_ZERO_MASKS_field FORCE_ZERO_MASKS_field
 * @brief macros for field FORCE_ZERO_MASKS
 * @details Use masks generated by internal masking PRNG (0) or force all masks constantly to zero (1). Setting all masks to constant zero can be useful when performing SCA. To completely disable the masking, the second key share (KEY_SHARE1_0 - KEY_SHARE1_7) must be zero as well. Only applicable if both the Masking parameter and the SecAllowForcingMasks parameter are set to one.
 * @{
 */
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__SHIFT                           12
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__WIDTH                            1
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__MASK                   0x00001000U
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define AES_CTRL_SHADOWED__FORCE_ZERO_MASKS__RESET_VALUE            0x00000000U
/** @} */
#define AES_CTRL_SHADOWED__TYPE                                        uint32_t
#define AES_CTRL_SHADOWED__READ                                     0x00001fffU
#define AES_CTRL_SHADOWED__WRITE                                    0x00001fffU
#define AES_CTRL_SHADOWED__PRESERVED                                0x00000000U
#define AES_CTRL_SHADOWED__RESET_VALUE                              0x000000c0U

#endif /* __AES_CTRL_SHADOWED_MACRO__ */

/** @} end of CTRL_SHADOWED */

/* macros for BlueprintGlobalNameSpace::AES_TRIGGER */
/**
 * @defgroup at_apb_aes_regs_core_TRIGGER TRIGGER
 * @brief Trigger Register. Each bit is individually cleared to zero when executing the corresponding trigger. While executing any of the triggered operations, the AES unit will set the IDLE bit in the Status Register to zero. The processor must check the Status Register before triggering further actions. For example, writes to Initial Key and IV Registers are ignored while the AES unit is busy. Writes to the Input Data Registers are not ignored but the data will be cleared if a KEY_IV_DATA_IN_CLEAR operation is pending. definitions.
 * @{
 */
#ifndef __AES_TRIGGER_MACRO__
#define __AES_TRIGGER_MACRO__

/* macros for field START */
/**
 * @defgroup at_apb_aes_regs_core_START_field START_field
 * @brief macros for field START
 * @details Keep AES unit paused (0) or trigger the encryption/decryption of one data block (1).  This trigger is ignored if MANUAL_OPERATION=0 (see Control Register).
 * @{
 */
#define AES_TRIGGER__START__SHIFT                                             0
#define AES_TRIGGER__START__WIDTH                                             1
#define AES_TRIGGER__START__MASK                                    0x00000001U
#define AES_TRIGGER__START__READ(src)           ((uint32_t)(src) & 0x00000001U)
#define AES_TRIGGER__START__WRITE(src)          ((uint32_t)(src) & 0x00000001U)
#define AES_TRIGGER__START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AES_TRIGGER__START__VERIFY(src)   (!(((uint32_t)(src) & ~0x00000001U)))
#define AES_TRIGGER__START__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AES_TRIGGER__START__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AES_TRIGGER__START__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field KEY_IV_DATA_IN_CLEAR */
/**
 * @defgroup at_apb_aes_regs_core_KEY_IV_DATA_IN_CLEAR_field KEY_IV_DATA_IN_CLEAR_field
 * @brief macros for field KEY_IV_DATA_IN_CLEAR
 * @details Keep current values in Initial Key, internal Full Key and Decryption Key registers,  IV registers and Input Data registers (0) or clear all those registers with pseudo-random data (1).
 * @{
 */
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__SHIFT                              1
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__WIDTH                              1
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__MASK                     0x00000002U
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AES_TRIGGER__KEY_IV_DATA_IN_CLEAR__RESET_VALUE              0x00000001U
/** @} */

/* macros for field DATA_OUT_CLEAR */
/**
 * @defgroup at_apb_aes_regs_core_DATA_OUT_CLEAR_field DATA_OUT_CLEAR_field
 * @brief macros for field DATA_OUT_CLEAR
 * @details Keep current values in Output Data registers (0) or clear those registers with pseudo-random data (1).
 * @{
 */
#define AES_TRIGGER__DATA_OUT_CLEAR__SHIFT                                    2
#define AES_TRIGGER__DATA_OUT_CLEAR__WIDTH                                    1
#define AES_TRIGGER__DATA_OUT_CLEAR__MASK                           0x00000004U
#define AES_TRIGGER__DATA_OUT_CLEAR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AES_TRIGGER__DATA_OUT_CLEAR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AES_TRIGGER__DATA_OUT_CLEAR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AES_TRIGGER__DATA_OUT_CLEAR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AES_TRIGGER__DATA_OUT_CLEAR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AES_TRIGGER__DATA_OUT_CLEAR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AES_TRIGGER__DATA_OUT_CLEAR__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field PRNG_RESEED */
/**
 * @defgroup at_apb_aes_regs_core_PRNG_RESEED_field PRNG_RESEED_field
 * @brief macros for field PRNG_RESEED
 * @details Keep continuing with the current internal state of the internal pseudo-random number generator  used for register clearing (0) or perform a reseed of the internal state from the connected entropy source (1).
 * @{
 */
#define AES_TRIGGER__PRNG_RESEED__SHIFT                                       3
#define AES_TRIGGER__PRNG_RESEED__WIDTH                                       1
#define AES_TRIGGER__PRNG_RESEED__MASK                              0x00000008U
#define AES_TRIGGER__PRNG_RESEED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AES_TRIGGER__PRNG_RESEED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AES_TRIGGER__PRNG_RESEED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AES_TRIGGER__PRNG_RESEED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AES_TRIGGER__PRNG_RESEED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AES_TRIGGER__PRNG_RESEED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AES_TRIGGER__PRNG_RESEED__RESET_VALUE                       0x00000001U
/** @} */
#define AES_TRIGGER__TYPE                                              uint32_t
#define AES_TRIGGER__READ                                           0x0000000fU
#define AES_TRIGGER__WRITE                                          0x0000000fU
#define AES_TRIGGER__PRESERVED                                      0x00000000U
#define AES_TRIGGER__RESET_VALUE                                    0x0000000eU

#endif /* __AES_TRIGGER_MACRO__ */

/** @} end of TRIGGER */

/* macros for BlueprintGlobalNameSpace::AES_STATUS */
/**
 * @defgroup at_apb_aes_regs_core_STATUS STATUS
 * @brief Status Register definitions.
 * @{
 */
#ifndef __AES_STATUS_MACRO__
#define __AES_STATUS_MACRO__

/* macros for field IDLE */
/**
 * @defgroup at_apb_aes_regs_core_IDLE_field IDLE_field
 * @brief macros for field IDLE
 * @details The AES unit is idle (1) or busy (0).  This flag is 0 if one of the following operations is currently running:  i) encryption/decryption, ii) register clearing or iii) PRNG reseeding.  This flag is also 0 if an encryption/decryption is running but the AES unit is stalled.
 * @{
 */
#define AES_STATUS__IDLE__SHIFT                                               0
#define AES_STATUS__IDLE__WIDTH                                               1
#define AES_STATUS__IDLE__MASK                                      0x00000001U
#define AES_STATUS__IDLE__READ(src)             ((uint32_t)(src) & 0x00000001U)
#define AES_STATUS__IDLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AES_STATUS__IDLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AES_STATUS__IDLE__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field STALL */
/**
 * @defgroup at_apb_aes_regs_core_STALL_field STALL_field
 * @brief macros for field STALL
 * @details The AES unit is not stalled (0) or stalled (1)  because there is previous output data that must be read by the processor before the AES unit can overwrite this data.  This flag is not meaningful if MANUAL_OPERATION=1 (see Control Register).
 * @{
 */
#define AES_STATUS__STALL__SHIFT                                              1
#define AES_STATUS__STALL__WIDTH                                              1
#define AES_STATUS__STALL__MASK                                     0x00000002U
#define AES_STATUS__STALL__READ(src)     (((uint32_t)(src) & 0x00000002U) >> 1)
#define AES_STATUS__STALL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AES_STATUS__STALL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AES_STATUS__STALL__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field OUTPUT_LOST */
/**
 * @defgroup at_apb_aes_regs_core_OUTPUT_LOST_field OUTPUT_LOST_field
 * @brief macros for field OUTPUT_LOST
 * @details All previous output data has been fully read by the processor (0)  or at least one previous output data block has been lost (1).  It has been overwritten by the AES unit before the processor could fully read it.  Once set to 1, this flag remains set until AES operation is restarted by re-writing the Control Register.  The primary use of this flag is for design verification.  This flag is not meaningful if MANUAL_OPERATION=0 (see Control Register).
 * @{
 */
#define AES_STATUS__OUTPUT_LOST__SHIFT                                        2
#define AES_STATUS__OUTPUT_LOST__WIDTH                                        1
#define AES_STATUS__OUTPUT_LOST__MASK                               0x00000004U
#define AES_STATUS__OUTPUT_LOST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AES_STATUS__OUTPUT_LOST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AES_STATUS__OUTPUT_LOST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AES_STATUS__OUTPUT_LOST__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field OUTPUT_VALID */
/**
 * @defgroup at_apb_aes_regs_core_OUTPUT_VALID_field OUTPUT_VALID_field
 * @brief macros for field OUTPUT_VALID
 * @details The AES unit has no valid output (0) or has valid output data (1).
 * @{
 */
#define AES_STATUS__OUTPUT_VALID__SHIFT                                       3
#define AES_STATUS__OUTPUT_VALID__WIDTH                                       1
#define AES_STATUS__OUTPUT_VALID__MASK                              0x00000008U
#define AES_STATUS__OUTPUT_VALID__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AES_STATUS__OUTPUT_VALID__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AES_STATUS__OUTPUT_VALID__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AES_STATUS__OUTPUT_VALID__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field INPUT_READY */
/**
 * @defgroup at_apb_aes_regs_core_INPUT_READY_field INPUT_READY_field
 * @brief macros for field INPUT_READY
 * @details The AES unit is ready (1) or not ready (0) to receive new data input via the DATA_IN registers.  If the present values in the DATA_IN registers have not yet been loaded into the module this flag is 0 (not ready).
 * @{
 */
#define AES_STATUS__INPUT_READY__SHIFT                                        4
#define AES_STATUS__INPUT_READY__WIDTH                                        1
#define AES_STATUS__INPUT_READY__MASK                               0x00000010U
#define AES_STATUS__INPUT_READY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define AES_STATUS__INPUT_READY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define AES_STATUS__INPUT_READY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define AES_STATUS__INPUT_READY__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field ALERT_RECOV_CTRL_UPDATE_ERR */
/**
 * @defgroup at_apb_aes_regs_core_ALERT_RECOV_CTRL_UPDATE_ERR_field ALERT_RECOV_CTRL_UPDATE_ERR_field
 * @brief macros for field ALERT_RECOV_CTRL_UPDATE_ERR
 * @details An update error has not occurred (0) or has occurred (1) in the shadowed Control Register.  AES operation needs to be restarted by re-writing the Control Register.
 * @{
 */
#define AES_STATUS__ALERT_RECOV_CTRL_UPDATE_ERR__SHIFT                        5
#define AES_STATUS__ALERT_RECOV_CTRL_UPDATE_ERR__WIDTH                        1
#define AES_STATUS__ALERT_RECOV_CTRL_UPDATE_ERR__MASK               0x00000020U
#define AES_STATUS__ALERT_RECOV_CTRL_UPDATE_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define AES_STATUS__ALERT_RECOV_CTRL_UPDATE_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define AES_STATUS__ALERT_RECOV_CTRL_UPDATE_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define AES_STATUS__ALERT_RECOV_CTRL_UPDATE_ERR__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ALERT_FATAL_FAULT */
/**
 * @defgroup at_apb_aes_regs_core_ALERT_FATAL_FAULT_field ALERT_FATAL_FAULT_field
 * @brief macros for field ALERT_FATAL_FAULT
 * @details No fatal fault has occurred inside the AES unit (0).  A fatal fault has occurred and the AES unit needs to be reset (1).  Examples for fatal faults include i) storage errors in the Control Register,  ii) if any internal FSM enters an invalid state,  iii) if any sparsely encoded signal takes on an invalid value,  iv) errors in the internal round counter,  v) escalations triggered by the life cycle controller, and  vi) fatal integrity failures on the TL-UL bus.
 * @{
 */
#define AES_STATUS__ALERT_FATAL_FAULT__SHIFT                                  6
#define AES_STATUS__ALERT_FATAL_FAULT__WIDTH                                  1
#define AES_STATUS__ALERT_FATAL_FAULT__MASK                         0x00000040U
#define AES_STATUS__ALERT_FATAL_FAULT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define AES_STATUS__ALERT_FATAL_FAULT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define AES_STATUS__ALERT_FATAL_FAULT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define AES_STATUS__ALERT_FATAL_FAULT__RESET_VALUE                  0x00000000U
/** @} */
#define AES_STATUS__TYPE                                               uint32_t
#define AES_STATUS__READ                                            0x0000007fU
#define AES_STATUS__PRESERVED                                       0x00000000U
#define AES_STATUS__RESET_VALUE                                     0x00000000U

#endif /* __AES_STATUS_MACRO__ */

/** @} end of STATUS */

/* macros for BlueprintGlobalNameSpace::AES_status1 */
/**
 * @defgroup at_apb_aes_regs_core_status1 status1
 * @brief Status Register definitions.
 * @{
 */
#ifndef __AES_STATUS1_MACRO__
#define __AES_STATUS1_MACRO__

/* macros for field sideload_wptr */
/**
 * @defgroup at_apb_aes_regs_core_sideload_wptr_field sideload_wptr_field
 * @brief macros for field sideload_wptr
 * @details The current value of the sideload key write pointer. This pointer shows the next slot the new word will be stored.
 * @{
 */
#define AES_STATUS1__SIDELOAD_WPTR__SHIFT                                     0
#define AES_STATUS1__SIDELOAD_WPTR__WIDTH                                     3
#define AES_STATUS1__SIDELOAD_WPTR__MASK                            0x00000007U
#define AES_STATUS1__SIDELOAD_WPTR__READ(src)   ((uint32_t)(src) & 0x00000007U)
#define AES_STATUS1__SIDELOAD_WPTR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field key_len_err */
/**
 * @defgroup at_apb_aes_regs_core_key_len_err_field key_len_err_field
 * @brief macros for field key_len_err
 * @details indicates meta key size error. Asserted by HW when sideload_val is written 1 while the meta key size does not match operation key size. cleared by core reset.
 * @{
 */
#define AES_STATUS1__KEY_LEN_ERR__SHIFT                                      31
#define AES_STATUS1__KEY_LEN_ERR__WIDTH                                       1
#define AES_STATUS1__KEY_LEN_ERR__MASK                              0x80000000U
#define AES_STATUS1__KEY_LEN_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AES_STATUS1__KEY_LEN_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AES_STATUS1__KEY_LEN_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AES_STATUS1__KEY_LEN_ERR__RESET_VALUE                       0x00000000U
/** @} */
#define AES_STATUS1__TYPE                                              uint32_t
#define AES_STATUS1__READ                                           0x80000007U
#define AES_STATUS1__PRESERVED                                      0x00000000U
#define AES_STATUS1__RESET_VALUE                                    0x00000000U

#endif /* __AES_STATUS1_MACRO__ */

/** @} end of status1 */

/* macros for BlueprintGlobalNameSpace::AES_sideload_ctrl */
/**
 * @defgroup at_apb_aes_regs_core_sideload_ctrl sideload_ctrl
 * @brief Contains register fields associated with sideload_ctrl. definitions.
 * @{
 */
#ifndef __AES_SIDELOAD_CTRL_MACRO__
#define __AES_SIDELOAD_CTRL_MACRO__

/* macros for field sideload_val */
/**
 * @defgroup at_apb_aes_regs_core_sideload_val_field sideload_val_field
 * @brief macros for field sideload_val
 * @details write 1 to assert that sideload key is valid. Write 0 to invalidate.  Write 1 will also clear the sideload key write pointer.  The sideload key is composed of 8 words, which are stored in a fifo like buffer.  A write pointer points to the next slot in the buffer in which a new word will be stored.
 * @{
 */
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__SHIFT                                0
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__WIDTH                                1
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__MASK                       0x00000001U
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AES_SIDELOAD_CTRL__SIDELOAD_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field sideload_update_en */
/**
 * @defgroup at_apb_aes_regs_core_sideload_update_en_field sideload_update_en_field
 * @brief macros for field sideload_update_en
 * @details write 1 to enable sideload buffer push.
 * @{
 */
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__SHIFT                          1
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__WIDTH                          1
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__MASK                 0x00000002U
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AES_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__RESET_VALUE          0x00000001U
/** @} */
#define AES_SIDELOAD_CTRL__TYPE                                        uint32_t
#define AES_SIDELOAD_CTRL__READ                                     0x00000003U
#define AES_SIDELOAD_CTRL__WRITE                                    0x00000003U
#define AES_SIDELOAD_CTRL__PRESERVED                                0x00000000U
#define AES_SIDELOAD_CTRL__RESET_VALUE                              0x00000002U

#endif /* __AES_SIDELOAD_CTRL_MACRO__ */

/** @} end of sideload_ctrl */

/* macros for BlueprintGlobalNameSpace::AES_id */
/**
 * @defgroup at_apb_aes_regs_core_id id
 * @brief Contains register fields associated with id. definitions.
 * @{
 */
#ifndef __AES_ID_MACRO__
#define __AES_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_aes_regs_core_id_field id_field
 * @brief macros for field id
 * @details AES in ASCII
 * @{
 */
#define AES_ID__ID__SHIFT                                                     0
#define AES_ID__ID__WIDTH                                                    32
#define AES_ID__ID__MASK                                            0xffffffffU
#define AES_ID__ID__READ(src)                   ((uint32_t)(src) & 0xffffffffU)
#define AES_ID__ID__RESET_VALUE                                     0x00414553U
/** @} */
#define AES_ID__TYPE                                                   uint32_t
#define AES_ID__READ                                                0xffffffffU
#define AES_ID__PRESERVED                                           0x00000000U
#define AES_ID__RESET_VALUE                                         0x00414553U

#endif /* __AES_ID_MACRO__ */

/** @} end of id */

/** @} end of AT_APB_AES_REGS_CORE */
#endif /* __REG_AT_APB_AES_REGS_CORE_H__ */
