/*                                                                           */
/* File:       at_ahb_sha2_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_ahb_sha2_regs_core.rdl          */
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


#ifndef __REG_AT_AHB_SHA2_REGS_CORE_H__
#define __REG_AT_AHB_SHA2_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_AHB_SHA2_REGS_CORE at_ahb_sha2_regs_core
 * @ingroup AT_REG
 * @brief at_ahb_sha2_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_control */
/**
 * @defgroup at_ahb_sha2_regs_core_control control
 * @brief Contains register fields associated with control. definitions.
 * @{
 */
#ifndef __AT_SHA2_CONTROL_MACRO__
#define __AT_SHA2_CONTROL_MACRO__

/* macros for field sha_en */
/**
 * @defgroup at_ahb_sha2_regs_core_sha_en_field sha_en_field
 * @brief macros for field sha_en
 * @details SHA256 enable. If 0, SHA engine won't initiate compression,  this is used to stop operation of the SHA engine until configuration has been done.  When the SHA engine is disabled the digest is cleared.
 * @{
 */
#define AT_SHA2_CONTROL__SHA_EN__SHIFT                                        0
#define AT_SHA2_CONTROL__SHA_EN__WIDTH                                        1
#define AT_SHA2_CONTROL__SHA_EN__MASK                               0x00000001U
#define AT_SHA2_CONTROL__SHA_EN__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define AT_SHA2_CONTROL__SHA_EN__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define AT_SHA2_CONTROL__SHA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_SHA2_CONTROL__SHA_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_SHA2_CONTROL__SHA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_SHA2_CONTROL__SHA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_SHA2_CONTROL__SHA_EN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field hmac_en */
/**
 * @defgroup at_ahb_sha2_regs_core_hmac_en_field hmac_en_field
 * @brief macros for field hmac_en
 * @details HMAC datapath enable. If this bit is 1, HMAC operates when hash_start toggles
 * @{
 */
#define AT_SHA2_CONTROL__HMAC_EN__SHIFT                                       1
#define AT_SHA2_CONTROL__HMAC_EN__WIDTH                                       1
#define AT_SHA2_CONTROL__HMAC_EN__MASK                              0x00000002U
#define AT_SHA2_CONTROL__HMAC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_SHA2_CONTROL__HMAC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_SHA2_CONTROL__HMAC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_SHA2_CONTROL__HMAC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_SHA2_CONTROL__HMAC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_SHA2_CONTROL__HMAC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_SHA2_CONTROL__HMAC_EN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field byte_swizzle */
/**
 * @defgroup at_ahb_sha2_regs_core_byte_swizzle_field byte_swizzle_field
 * @brief macros for field byte_swizzle
 * @details message word byte swizzle
 * @{
 */
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__SHIFT                                  2
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__WIDTH                                  1
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__MASK                         0x00000004U
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_SHA2_CONTROL__BYTE_SWIZZLE__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field digest_swizzle */
/**
 * @defgroup at_ahb_sha2_regs_core_digest_swizzle_field digest_swizzle_field
 * @brief macros for field digest_swizzle
 * @details digest word's byte swizzle
 * @{
 */
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__SHIFT                                3
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__WIDTH                                1
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__MASK                       0x00000008U
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_SHA2_CONTROL__DIGEST_SWIZZLE__RESET_VALUE                0x00000000U
/** @} */
#define AT_SHA2_CONTROL__TYPE                                          uint32_t
#define AT_SHA2_CONTROL__READ                                       0x0000000fU
#define AT_SHA2_CONTROL__WRITE                                      0x0000000fU
#define AT_SHA2_CONTROL__PRESERVED                                  0x00000000U
#define AT_SHA2_CONTROL__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_CONTROL_MACRO__ */

/** @} end of control */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_sideload_ctrl */
/**
 * @defgroup at_ahb_sha2_regs_core_sideload_ctrl sideload_ctrl
 * @brief Contains register fields associated with sideload_ctrl. definitions.
 * @{
 */
#ifndef __AT_SHA2_SIDELOAD_CTRL_MACRO__
#define __AT_SHA2_SIDELOAD_CTRL_MACRO__

/* macros for field sideload_ptr_clr */
/**
 * @defgroup at_ahb_sha2_regs_core_sideload_ptr_clr_field sideload_ptr_clr_field
 * @brief macros for field sideload_ptr_clr
 * @details write 1 to clear the write pointer. (__SELF_CLEARING__)
 * @{
 */
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__SHIFT                        0
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__WIDTH                        1
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__MASK               0x00000001U
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_PTR_CLR__RESET_VALUE        0x00000000U
/** @} */

/* macros for field sideload_update_en */
/**
 * @defgroup at_ahb_sha2_regs_core_sideload_update_en_field sideload_update_en_field
 * @brief macros for field sideload_update_en
 * @details write 1 to enable sideload buffer push.
 * @{
 */
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__SHIFT                      1
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__WIDTH                      1
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__MASK             0x00000002U
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__RESET_VALUE      0x00000000U
/** @} */
#define AT_SHA2_SIDELOAD_CTRL__TYPE                                    uint32_t
#define AT_SHA2_SIDELOAD_CTRL__READ                                 0x00000003U
#define AT_SHA2_SIDELOAD_CTRL__WRITE                                0x00000003U
#define AT_SHA2_SIDELOAD_CTRL__PRESERVED                            0x00000000U
#define AT_SHA2_SIDELOAD_CTRL__RESET_VALUE                          0x00000000U

#endif /* __AT_SHA2_SIDELOAD_CTRL_MACRO__ */

/** @} end of sideload_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_cmd */
/**
 * @defgroup at_ahb_sha2_regs_core_cmd cmd
 * @brief Contains register fields associated with cmd. definitions.
 * @{
 */
#ifndef __AT_SHA2_CMD_MACRO__
#define __AT_SHA2_CMD_MACRO__

/* macros for field hash_start */
/**
 * @defgroup at_ahb_sha2_regs_core_hash_start_field hash_start_field
 * @brief macros for field hash_start
 * @details Write 1 to start the SHA256 or HMAC operation.  CPU should configure relative information first, such as message_length, secret_key. self clearing
 * @{
 */
#define AT_SHA2_CMD__HASH_START__SHIFT                                        0
#define AT_SHA2_CMD__HASH_START__WIDTH                                        1
#define AT_SHA2_CMD__HASH_START__MASK                               0x00000001U
#define AT_SHA2_CMD__HASH_START__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define AT_SHA2_CMD__HASH_START__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define AT_SHA2_CMD__HASH_START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_SHA2_CMD__HASH_START__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_SHA2_CMD__HASH_START__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_SHA2_CMD__HASH_START__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_SHA2_CMD__HASH_START__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field hash_process */
/**
 * @defgroup at_ahb_sha2_regs_core_hash_process_field hash_process_field
 * @brief macros for field hash_process
 * @details Write 1 to process the final SHA256 digest or calculate the HMAC message hash. self clearing
 * @{
 */
#define AT_SHA2_CMD__HASH_PROCESS__SHIFT                                      1
#define AT_SHA2_CMD__HASH_PROCESS__WIDTH                                      1
#define AT_SHA2_CMD__HASH_PROCESS__MASK                             0x00000002U
#define AT_SHA2_CMD__HASH_PROCESS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_SHA2_CMD__HASH_PROCESS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_SHA2_CMD__HASH_PROCESS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_SHA2_CMD__HASH_PROCESS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_SHA2_CMD__HASH_PROCESS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_SHA2_CMD__HASH_PROCESS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_SHA2_CMD__HASH_PROCESS__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field hash_continue */
/**
 * @defgroup at_ahb_sha2_regs_core_hash_continue_field hash_continue_field
 * @brief macros for field hash_continue
 * @details this is a side-band information of hash_start. It indicates that the current hash_start is a continuation from a previous computation. (__SELF_CLEARING__)
 * @{
 */
#define AT_SHA2_CMD__HASH_CONTINUE__SHIFT                                     2
#define AT_SHA2_CMD__HASH_CONTINUE__WIDTH                                     1
#define AT_SHA2_CMD__HASH_CONTINUE__MASK                            0x00000004U
#define AT_SHA2_CMD__HASH_CONTINUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_SHA2_CMD__HASH_CONTINUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_SHA2_CMD__HASH_CONTINUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_SHA2_CMD__HASH_CONTINUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_SHA2_CMD__HASH_CONTINUE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_SHA2_CMD__HASH_CONTINUE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_SHA2_CMD__HASH_CONTINUE__RESET_VALUE                     0x00000000U
/** @} */
#define AT_SHA2_CMD__TYPE                                              uint32_t
#define AT_SHA2_CMD__READ                                           0x00000007U
#define AT_SHA2_CMD__WRITE                                          0x00000007U
#define AT_SHA2_CMD__PRESERVED                                      0x00000000U
#define AT_SHA2_CMD__RESET_VALUE                                    0x00000000U

#endif /* __AT_SHA2_CMD_MACRO__ */

/** @} end of cmd */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_message_length_lo */
/**
 * @defgroup at_ahb_sha2_regs_core_message_length_lo message_length_lo
 * @brief Contains register fields associated with message_length_lo. definitions.
 * @{
 */
#ifndef __AT_SHA2_MESSAGE_LENGTH_LO_MACRO__
#define __AT_SHA2_MESSAGE_LENGTH_LO_MACRO__

/* macros for field length_lo */
/**
 * @defgroup at_ahb_sha2_regs_core_length_lo_field length_lo_field
 * @brief macros for field length_lo
 * @details Received Message Length calculated by the HMAC in bits [31:0]  Message is byte granularity. lower 3bits [2:0] are ignored.
 * @{
 */
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__SHIFT                           0
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__WIDTH                          32
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__MASK                  0xffffffffU
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_MESSAGE_LENGTH_LO__LENGTH_LO__RESET_VALUE           0x00000000U
/** @} */
#define AT_SHA2_MESSAGE_LENGTH_LO__TYPE                                uint32_t
#define AT_SHA2_MESSAGE_LENGTH_LO__READ                             0xffffffffU
#define AT_SHA2_MESSAGE_LENGTH_LO__WRITE                            0xffffffffU
#define AT_SHA2_MESSAGE_LENGTH_LO__PRESERVED                        0x00000000U
#define AT_SHA2_MESSAGE_LENGTH_LO__RESET_VALUE                      0x00000000U

#endif /* __AT_SHA2_MESSAGE_LENGTH_LO_MACRO__ */

/** @} end of message_length_lo */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_message_length_hi */
/**
 * @defgroup at_ahb_sha2_regs_core_message_length_hi message_length_hi
 * @brief Contains register fields associated with message_length_hi. definitions.
 * @{
 */
#ifndef __AT_SHA2_MESSAGE_LENGTH_HI_MACRO__
#define __AT_SHA2_MESSAGE_LENGTH_HI_MACRO__

/* macros for field length_hi */
/**
 * @defgroup at_ahb_sha2_regs_core_length_hi_field length_hi_field
 * @brief macros for field length_hi
 * @details Received Message Length calculated by the HMAC in bits [63:32]  Message is byte granularity. lower 3bits [2:0] are ignored.
 * @{
 */
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__SHIFT                           0
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__WIDTH                          32
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__MASK                  0xffffffffU
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_MESSAGE_LENGTH_HI__LENGTH_HI__RESET_VALUE           0x00000000U
/** @} */
#define AT_SHA2_MESSAGE_LENGTH_HI__TYPE                                uint32_t
#define AT_SHA2_MESSAGE_LENGTH_HI__READ                             0xffffffffU
#define AT_SHA2_MESSAGE_LENGTH_HI__WRITE                            0xffffffffU
#define AT_SHA2_MESSAGE_LENGTH_HI__PRESERVED                        0x00000000U
#define AT_SHA2_MESSAGE_LENGTH_HI__RESET_VALUE                      0x00000000U

#endif /* __AT_SHA2_MESSAGE_LENGTH_HI_MACRO__ */

/** @} end of message_length_hi */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_wipe_v */
/**
 * @defgroup at_ahb_sha2_regs_core_wipe_v wipe_v
 * @brief Contains register fields associated with wipe_v. definitions.
 * @{
 */
#ifndef __AT_SHA2_WIPE_V_MACRO__
#define __AT_SHA2_WIPE_V_MACRO__

/* macros for field wipe_v */
/**
 * @defgroup at_ahb_sha2_regs_core_wipe_v_field wipe_v_field
 * @brief macros for field wipe_v
 * @details a write to this register triggers a wipe_secret action.
 * @{
 */
#define AT_SHA2_WIPE_V__WIPE_V__SHIFT                                         0
#define AT_SHA2_WIPE_V__WIPE_V__WIDTH                                        32
#define AT_SHA2_WIPE_V__WIPE_V__MASK                                0xffffffffU
#define AT_SHA2_WIPE_V__WIPE_V__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_WIPE_V__WIPE_V__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_WIPE_V__WIPE_V__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_WIPE_V__WIPE_V__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_WIPE_V__WIPE_V__RESET_VALUE                         0x00000000U
/** @} */
#define AT_SHA2_WIPE_V__TYPE                                           uint32_t
#define AT_SHA2_WIPE_V__READ                                        0xffffffffU
#define AT_SHA2_WIPE_V__WRITE                                       0xffffffffU
#define AT_SHA2_WIPE_V__PRESERVED                                   0x00000000U
#define AT_SHA2_WIPE_V__RESET_VALUE                                 0x00000000U

#endif /* __AT_SHA2_WIPE_V_MACRO__ */

/** @} end of wipe_v */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_fifo_push */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_push fifo_push
 * @brief Contains register fields associated with fifo_push. definitions.
 * @{
 */
#ifndef __AT_SHA2_FIFO_PUSH_MACRO__
#define __AT_SHA2_FIFO_PUSH_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_ahb_sha2_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details Message FIFO input port. Byte writes are supported
 * @{
 */
#define AT_SHA2_FIFO_PUSH__WDATA__SHIFT                                       0
#define AT_SHA2_FIFO_PUSH__WDATA__WIDTH                                      32
#define AT_SHA2_FIFO_PUSH__WDATA__MASK                              0xffffffffU
#define AT_SHA2_FIFO_PUSH__WDATA__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_FIFO_PUSH__WDATA__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_FIFO_PUSH__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_FIFO_PUSH__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_FIFO_PUSH__WDATA__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_FIFO_PUSH__TYPE                                        uint32_t
#define AT_SHA2_FIFO_PUSH__READ                                     0xffffffffU
#define AT_SHA2_FIFO_PUSH__WRITE                                    0xffffffffU
#define AT_SHA2_FIFO_PUSH__PRESERVED                                0x00000000U
#define AT_SHA2_FIFO_PUSH__RESET_VALUE                              0x00000000U

#endif /* __AT_SHA2_FIFO_PUSH_MACRO__ */

/** @} end of fifo_push */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest0 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest0 digest0
 * @brief Contains register fields associated with digest0. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST0_MACRO__
#define __AT_SHA2_DIGEST0_MACRO__

/* macros for field digest0 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest0_field digest0_field
 * @brief macros for field digest0
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST0__DIGEST0__SHIFT                                       0
#define AT_SHA2_DIGEST0__DIGEST0__WIDTH                                      32
#define AT_SHA2_DIGEST0__DIGEST0__MASK                              0xffffffffU
#define AT_SHA2_DIGEST0__DIGEST0__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST0__DIGEST0__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST0__DIGEST0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST0__DIGEST0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST0__DIGEST0__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST0__TYPE                                          uint32_t
#define AT_SHA2_DIGEST0__READ                                       0xffffffffU
#define AT_SHA2_DIGEST0__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST0__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST0__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST0_MACRO__ */

/** @} end of digest0 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest1 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest1 digest1
 * @brief Contains register fields associated with digest1. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST1_MACRO__
#define __AT_SHA2_DIGEST1_MACRO__

/* macros for field digest1 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest1_field digest1_field
 * @brief macros for field digest1
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST1__DIGEST1__SHIFT                                       0
#define AT_SHA2_DIGEST1__DIGEST1__WIDTH                                      32
#define AT_SHA2_DIGEST1__DIGEST1__MASK                              0xffffffffU
#define AT_SHA2_DIGEST1__DIGEST1__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST1__DIGEST1__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST1__DIGEST1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST1__DIGEST1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST1__DIGEST1__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST1__TYPE                                          uint32_t
#define AT_SHA2_DIGEST1__READ                                       0xffffffffU
#define AT_SHA2_DIGEST1__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST1__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST1__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST1_MACRO__ */

/** @} end of digest1 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest2 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest2 digest2
 * @brief Contains register fields associated with digest2. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST2_MACRO__
#define __AT_SHA2_DIGEST2_MACRO__

/* macros for field digest2 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest2_field digest2_field
 * @brief macros for field digest2
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST2__DIGEST2__SHIFT                                       0
#define AT_SHA2_DIGEST2__DIGEST2__WIDTH                                      32
#define AT_SHA2_DIGEST2__DIGEST2__MASK                              0xffffffffU
#define AT_SHA2_DIGEST2__DIGEST2__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST2__DIGEST2__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST2__DIGEST2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST2__DIGEST2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST2__DIGEST2__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST2__TYPE                                          uint32_t
#define AT_SHA2_DIGEST2__READ                                       0xffffffffU
#define AT_SHA2_DIGEST2__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST2__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST2__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST2_MACRO__ */

/** @} end of digest2 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest3 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest3 digest3
 * @brief Contains register fields associated with digest3. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST3_MACRO__
#define __AT_SHA2_DIGEST3_MACRO__

/* macros for field digest3 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest3_field digest3_field
 * @brief macros for field digest3
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST3__DIGEST3__SHIFT                                       0
#define AT_SHA2_DIGEST3__DIGEST3__WIDTH                                      32
#define AT_SHA2_DIGEST3__DIGEST3__MASK                              0xffffffffU
#define AT_SHA2_DIGEST3__DIGEST3__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST3__DIGEST3__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST3__DIGEST3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST3__DIGEST3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST3__DIGEST3__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST3__TYPE                                          uint32_t
#define AT_SHA2_DIGEST3__READ                                       0xffffffffU
#define AT_SHA2_DIGEST3__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST3__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST3__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST3_MACRO__ */

/** @} end of digest3 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest4 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest4 digest4
 * @brief Contains register fields associated with digest4. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST4_MACRO__
#define __AT_SHA2_DIGEST4_MACRO__

/* macros for field digest4 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest4_field digest4_field
 * @brief macros for field digest4
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST4__DIGEST4__SHIFT                                       0
#define AT_SHA2_DIGEST4__DIGEST4__WIDTH                                      32
#define AT_SHA2_DIGEST4__DIGEST4__MASK                              0xffffffffU
#define AT_SHA2_DIGEST4__DIGEST4__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST4__DIGEST4__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST4__DIGEST4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST4__DIGEST4__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST4__DIGEST4__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST4__TYPE                                          uint32_t
#define AT_SHA2_DIGEST4__READ                                       0xffffffffU
#define AT_SHA2_DIGEST4__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST4__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST4__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST4_MACRO__ */

/** @} end of digest4 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest5 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest5 digest5
 * @brief Contains register fields associated with digest5. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST5_MACRO__
#define __AT_SHA2_DIGEST5_MACRO__

/* macros for field digest5 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest5_field digest5_field
 * @brief macros for field digest5
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST5__DIGEST5__SHIFT                                       0
#define AT_SHA2_DIGEST5__DIGEST5__WIDTH                                      32
#define AT_SHA2_DIGEST5__DIGEST5__MASK                              0xffffffffU
#define AT_SHA2_DIGEST5__DIGEST5__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST5__DIGEST5__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST5__DIGEST5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST5__DIGEST5__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST5__DIGEST5__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST5__TYPE                                          uint32_t
#define AT_SHA2_DIGEST5__READ                                       0xffffffffU
#define AT_SHA2_DIGEST5__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST5__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST5__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST5_MACRO__ */

/** @} end of digest5 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest6 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest6 digest6
 * @brief Contains register fields associated with digest6. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST6_MACRO__
#define __AT_SHA2_DIGEST6_MACRO__

/* macros for field digest6 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest6_field digest6_field
 * @brief macros for field digest6
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST6__DIGEST6__SHIFT                                       0
#define AT_SHA2_DIGEST6__DIGEST6__WIDTH                                      32
#define AT_SHA2_DIGEST6__DIGEST6__MASK                              0xffffffffU
#define AT_SHA2_DIGEST6__DIGEST6__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST6__DIGEST6__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST6__DIGEST6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST6__DIGEST6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST6__DIGEST6__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST6__TYPE                                          uint32_t
#define AT_SHA2_DIGEST6__READ                                       0xffffffffU
#define AT_SHA2_DIGEST6__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST6__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST6__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST6_MACRO__ */

/** @} end of digest6 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_digest7 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest7 digest7
 * @brief Contains register fields associated with digest7. definitions.
 * @{
 */
#ifndef __AT_SHA2_DIGEST7_MACRO__
#define __AT_SHA2_DIGEST7_MACRO__

/* macros for field digest7 */
/**
 * @defgroup at_ahb_sha2_regs_core_digest7_field digest7_field
 * @brief macros for field digest7
 * @details Digest output. If HMAC is disabled, the register shows result of SHA256  Order of the digest is: digest[255:0] = {DIGEST0, DIGEST1, DIGEST2, ... , DIGEST7};
 * @{
 */
#define AT_SHA2_DIGEST7__DIGEST7__SHIFT                                       0
#define AT_SHA2_DIGEST7__DIGEST7__WIDTH                                      32
#define AT_SHA2_DIGEST7__DIGEST7__MASK                              0xffffffffU
#define AT_SHA2_DIGEST7__DIGEST7__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST7__DIGEST7__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_DIGEST7__DIGEST7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_DIGEST7__DIGEST7__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_DIGEST7__DIGEST7__RESET_VALUE                       0x00000000U
/** @} */
#define AT_SHA2_DIGEST7__TYPE                                          uint32_t
#define AT_SHA2_DIGEST7__READ                                       0xffffffffU
#define AT_SHA2_DIGEST7__WRITE                                      0xffffffffU
#define AT_SHA2_DIGEST7__PRESERVED                                  0x00000000U
#define AT_SHA2_DIGEST7__RESET_VALUE                                0x00000000U

#endif /* __AT_SHA2_DIGEST7_MACRO__ */

/** @} end of digest7 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_0 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_0 key_0
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_0_MACRO__
#define __AT_SHA2_KEY_0_MACRO__

/* macros for field key_0 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_0_field key_0_field
 * @brief macros for field key_0
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_0__KEY_0__SHIFT                                           0
#define AT_SHA2_KEY_0__KEY_0__WIDTH                                          32
#define AT_SHA2_KEY_0__KEY_0__MASK                                  0xffffffffU
#define AT_SHA2_KEY_0__KEY_0__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_0__KEY_0__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_0__KEY_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_0__KEY_0__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_0__KEY_0__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_0__TYPE                                            uint32_t
#define AT_SHA2_KEY_0__READ                                         0xffffffffU
#define AT_SHA2_KEY_0__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_0__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_0__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_0_MACRO__ */

/** @} end of key_0 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_1 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_1 key_1
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_1_MACRO__
#define __AT_SHA2_KEY_1_MACRO__

/* macros for field key_1 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_1_field key_1_field
 * @brief macros for field key_1
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_1__KEY_1__SHIFT                                           0
#define AT_SHA2_KEY_1__KEY_1__WIDTH                                          32
#define AT_SHA2_KEY_1__KEY_1__MASK                                  0xffffffffU
#define AT_SHA2_KEY_1__KEY_1__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_1__KEY_1__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_1__KEY_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_1__KEY_1__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_1__KEY_1__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_1__TYPE                                            uint32_t
#define AT_SHA2_KEY_1__READ                                         0xffffffffU
#define AT_SHA2_KEY_1__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_1__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_1__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_1_MACRO__ */

/** @} end of key_1 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_2 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_2 key_2
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_2_MACRO__
#define __AT_SHA2_KEY_2_MACRO__

/* macros for field key_2 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_2_field key_2_field
 * @brief macros for field key_2
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_2__KEY_2__SHIFT                                           0
#define AT_SHA2_KEY_2__KEY_2__WIDTH                                          32
#define AT_SHA2_KEY_2__KEY_2__MASK                                  0xffffffffU
#define AT_SHA2_KEY_2__KEY_2__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_2__KEY_2__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_2__KEY_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_2__KEY_2__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_2__KEY_2__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_2__TYPE                                            uint32_t
#define AT_SHA2_KEY_2__READ                                         0xffffffffU
#define AT_SHA2_KEY_2__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_2__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_2__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_2_MACRO__ */

/** @} end of key_2 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_3 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_3 key_3
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_3_MACRO__
#define __AT_SHA2_KEY_3_MACRO__

/* macros for field key_3 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_3_field key_3_field
 * @brief macros for field key_3
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_3__KEY_3__SHIFT                                           0
#define AT_SHA2_KEY_3__KEY_3__WIDTH                                          32
#define AT_SHA2_KEY_3__KEY_3__MASK                                  0xffffffffU
#define AT_SHA2_KEY_3__KEY_3__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_3__KEY_3__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_3__KEY_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_3__KEY_3__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_3__KEY_3__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_3__TYPE                                            uint32_t
#define AT_SHA2_KEY_3__READ                                         0xffffffffU
#define AT_SHA2_KEY_3__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_3__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_3__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_3_MACRO__ */

/** @} end of key_3 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_4 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_4 key_4
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_4_MACRO__
#define __AT_SHA2_KEY_4_MACRO__

/* macros for field key_4 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_4_field key_4_field
 * @brief macros for field key_4
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_4__KEY_4__SHIFT                                           0
#define AT_SHA2_KEY_4__KEY_4__WIDTH                                          32
#define AT_SHA2_KEY_4__KEY_4__MASK                                  0xffffffffU
#define AT_SHA2_KEY_4__KEY_4__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_4__KEY_4__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_4__KEY_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_4__KEY_4__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_4__KEY_4__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_4__TYPE                                            uint32_t
#define AT_SHA2_KEY_4__READ                                         0xffffffffU
#define AT_SHA2_KEY_4__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_4__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_4__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_4_MACRO__ */

/** @} end of key_4 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_5 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_5 key_5
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_5_MACRO__
#define __AT_SHA2_KEY_5_MACRO__

/* macros for field key_5 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_5_field key_5_field
 * @brief macros for field key_5
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_5__KEY_5__SHIFT                                           0
#define AT_SHA2_KEY_5__KEY_5__WIDTH                                          32
#define AT_SHA2_KEY_5__KEY_5__MASK                                  0xffffffffU
#define AT_SHA2_KEY_5__KEY_5__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_5__KEY_5__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_5__KEY_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_5__KEY_5__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_5__KEY_5__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_5__TYPE                                            uint32_t
#define AT_SHA2_KEY_5__READ                                         0xffffffffU
#define AT_SHA2_KEY_5__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_5__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_5__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_5_MACRO__ */

/** @} end of key_5 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_6 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_6 key_6
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_6_MACRO__
#define __AT_SHA2_KEY_6_MACRO__

/* macros for field key_6 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_6_field key_6_field
 * @brief macros for field key_6
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_6__KEY_6__SHIFT                                           0
#define AT_SHA2_KEY_6__KEY_6__WIDTH                                          32
#define AT_SHA2_KEY_6__KEY_6__MASK                                  0xffffffffU
#define AT_SHA2_KEY_6__KEY_6__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_6__KEY_6__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_6__KEY_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_6__KEY_6__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_6__KEY_6__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_6__TYPE                                            uint32_t
#define AT_SHA2_KEY_6__READ                                         0xffffffffU
#define AT_SHA2_KEY_6__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_6__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_6__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_6_MACRO__ */

/** @} end of key_6 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_key_7 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_7 key_7
 * @brief SHA256 assumes secret key is hashed 256bit key. Order of the secret key is: key[255:0] = {KEY0, KEY1, KEY2, ... , KEY7}; definitions.
 * @{
 */
#ifndef __AT_SHA2_KEY_7_MACRO__
#define __AT_SHA2_KEY_7_MACRO__

/* macros for field key_7 */
/**
 * @defgroup at_ahb_sha2_regs_core_key_7_field key_7_field
 * @brief macros for field key_7
 * @details 32-bit chunk of 256-bit Secret Key.
 * @{
 */
#define AT_SHA2_KEY_7__KEY_7__SHIFT                                           0
#define AT_SHA2_KEY_7__KEY_7__WIDTH                                          32
#define AT_SHA2_KEY_7__KEY_7__MASK                                  0xffffffffU
#define AT_SHA2_KEY_7__KEY_7__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_7__KEY_7__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_KEY_7__KEY_7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_KEY_7__KEY_7__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define AT_SHA2_KEY_7__KEY_7__RESET_VALUE                           0x00000000U
/** @} */
#define AT_SHA2_KEY_7__TYPE                                            uint32_t
#define AT_SHA2_KEY_7__READ                                         0xffffffffU
#define AT_SHA2_KEY_7__WRITE                                        0xffffffffU
#define AT_SHA2_KEY_7__PRESERVED                                    0x00000000U
#define AT_SHA2_KEY_7__RESET_VALUE                                  0x00000000U

#endif /* __AT_SHA2_KEY_7_MACRO__ */

/** @} end of key_7 */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_status */
/**
 * @defgroup at_ahb_sha2_regs_core_status status
 * @brief Contains register fields associated with status. definitions.
 * @{
 */
#ifndef __AT_SHA2_STATUS_MACRO__
#define __AT_SHA2_STATUS_MACRO__

/* macros for field fifo_empty */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_empty_field fifo_empty_field
 * @brief macros for field fifo_empty
 * @details FIFO empty
 * @{
 */
#define AT_SHA2_STATUS__FIFO_EMPTY__SHIFT                                     0
#define AT_SHA2_STATUS__FIFO_EMPTY__WIDTH                                     1
#define AT_SHA2_STATUS__FIFO_EMPTY__MASK                            0x00000001U
#define AT_SHA2_STATUS__FIFO_EMPTY__READ(src)   ((uint32_t)(src) & 0x00000001U)
#define AT_SHA2_STATUS__FIFO_EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_SHA2_STATUS__FIFO_EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_SHA2_STATUS__FIFO_EMPTY__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field fifo_full */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_full_field fifo_full_field
 * @brief macros for field fifo_full
 * @details FIFO full. Data written to the FIFO whilst it is full will cause back-pressure on the interconnect
 * @{
 */
#define AT_SHA2_STATUS__FIFO_FULL__SHIFT                                      1
#define AT_SHA2_STATUS__FIFO_FULL__WIDTH                                      1
#define AT_SHA2_STATUS__FIFO_FULL__MASK                             0x00000002U
#define AT_SHA2_STATUS__FIFO_FULL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_SHA2_STATUS__FIFO_FULL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_SHA2_STATUS__FIFO_FULL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_SHA2_STATUS__FIFO_FULL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field reserved */
/**
 * @defgroup at_ahb_sha2_regs_core_reserved_field reserved_field
 * @brief macros for field reserved
 * @{
 */
#define AT_SHA2_STATUS__RESERVED__SHIFT                                       2
#define AT_SHA2_STATUS__RESERVED__WIDTH                                       2
#define AT_SHA2_STATUS__RESERVED__MASK                              0x0000000cU
#define AT_SHA2_STATUS__RESERVED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define AT_SHA2_STATUS__RESERVED__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field fifo_depth */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_depth_field fifo_depth_field
 * @brief macros for field fifo_depth
 * @details FIFO entry count
 * @{
 */
#define AT_SHA2_STATUS__FIFO_DEPTH__SHIFT                                     4
#define AT_SHA2_STATUS__FIFO_DEPTH__WIDTH                                     5
#define AT_SHA2_STATUS__FIFO_DEPTH__MASK                            0x000001f0U
#define AT_SHA2_STATUS__FIFO_DEPTH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001f0U) >> 4)
#define AT_SHA2_STATUS__FIFO_DEPTH__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field pop_count */
/**
 * @defgroup at_ahb_sha2_regs_core_pop_count_field pop_count_field
 * @brief macros for field pop_count
 * @details number of fifo pops by HW. The SHA core pops the FIFO when it is nots empty and computes a new digest when the counter changes from 0xf to 0x0. If SW decides to pause the current computation at a quiescent point while this number is not 0, SW needs to adjust the input message pointer backwards by this number when SW decides to resume.
 * @{
 */
#define AT_SHA2_STATUS__POP_COUNT__SHIFT                                      9
#define AT_SHA2_STATUS__POP_COUNT__WIDTH                                      4
#define AT_SHA2_STATUS__POP_COUNT__MASK                             0x00001e00U
#define AT_SHA2_STATUS__POP_COUNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
#define AT_SHA2_STATUS__POP_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field hash_compute_busy */
/**
 * @defgroup at_ahb_sha2_regs_core_hash_compute_busy_field hash_compute_busy_field
 * @brief macros for field hash_compute_busy
 * @details if 1, indicates the sha/hmac operation is busy computing a digest.
 * @{
 */
#define AT_SHA2_STATUS__HASH_COMPUTE_BUSY__SHIFT                             13
#define AT_SHA2_STATUS__HASH_COMPUTE_BUSY__WIDTH                              1
#define AT_SHA2_STATUS__HASH_COMPUTE_BUSY__MASK                     0x00002000U
#define AT_SHA2_STATUS__HASH_COMPUTE_BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define AT_SHA2_STATUS__HASH_COMPUTE_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define AT_SHA2_STATUS__HASH_COMPUTE_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define AT_SHA2_STATUS__HASH_COMPUTE_BUSY__RESET_VALUE              0x00000000U
/** @} */
#define AT_SHA2_STATUS__TYPE                                           uint32_t
#define AT_SHA2_STATUS__READ                                        0x00003fffU
#define AT_SHA2_STATUS__PRESERVED                                   0x00000000U
#define AT_SHA2_STATUS__RESET_VALUE                                 0x00000001U

#endif /* __AT_SHA2_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_interrupt_status */
/**
 * @defgroup at_ahb_sha2_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __AT_SHA2_INTERRUPT_STATUS_MACRO__
#define __AT_SHA2_INTERRUPT_STATUS_MACRO__

/* macros for field fifo_empty */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_empty_field fifo_empty_field
 * @brief macros for field fifo_empty
 * @details Message FIFO empty condition
 * @{
 */
#define AT_SHA2_INTERRUPT_STATUS__FIFO_EMPTY__SHIFT                           0
#define AT_SHA2_INTERRUPT_STATUS__FIFO_EMPTY__WIDTH                           1
#define AT_SHA2_INTERRUPT_STATUS__FIFO_EMPTY__MASK                  0x00000001U
#define AT_SHA2_INTERRUPT_STATUS__FIFO_EMPTY__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_SHA2_INTERRUPT_STATUS__FIFO_EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_SHA2_INTERRUPT_STATUS__FIFO_EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_SHA2_INTERRUPT_STATUS__FIFO_EMPTY__RESET_VALUE           0x00000000U
/** @} */

/* macros for field fifo_full */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_full_field fifo_full_field
 * @brief macros for field fifo_full
 * @details Message FIFO full condition
 * @{
 */
#define AT_SHA2_INTERRUPT_STATUS__FIFO_FULL__SHIFT                            1
#define AT_SHA2_INTERRUPT_STATUS__FIFO_FULL__WIDTH                            1
#define AT_SHA2_INTERRUPT_STATUS__FIFO_FULL__MASK                   0x00000002U
#define AT_SHA2_INTERRUPT_STATUS__FIFO_FULL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_SHA2_INTERRUPT_STATUS__FIFO_FULL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_SHA2_INTERRUPT_STATUS__FIFO_FULL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_SHA2_INTERRUPT_STATUS__FIFO_FULL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field chunk_done */
/**
 * @defgroup at_ahb_sha2_regs_core_chunk_done_field chunk_done_field
 * @brief macros for field chunk_done
 * @details one chunk of message done. (512 bits of message and padded bits)
 * @{
 */
#define AT_SHA2_INTERRUPT_STATUS__CHUNK_DONE__SHIFT                           2
#define AT_SHA2_INTERRUPT_STATUS__CHUNK_DONE__WIDTH                           1
#define AT_SHA2_INTERRUPT_STATUS__CHUNK_DONE__MASK                  0x00000004U
#define AT_SHA2_INTERRUPT_STATUS__CHUNK_DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_SHA2_INTERRUPT_STATUS__CHUNK_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_SHA2_INTERRUPT_STATUS__CHUNK_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_SHA2_INTERRUPT_STATUS__CHUNK_DONE__RESET_VALUE           0x00000000U
/** @} */

/* macros for field hmac_done */
/**
 * @defgroup at_ahb_sha2_regs_core_hmac_done_field hmac_done_field
 * @brief macros for field hmac_done
 * @details HMAC-256 completes a message with key
 * @{
 */
#define AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__SHIFT                            3
#define AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__WIDTH                            1
#define AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__MASK                   0x00000008U
#define AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__RESET_VALUE            0x00000000U
/** @} */

/* macros for field push_when_full */
/**
 * @defgroup at_ahb_sha2_regs_core_push_when_full_field push_when_full_field
 * @brief macros for field push_when_full
 * @details push when Message FIFO empty condition
 * @{
 */
#define AT_SHA2_INTERRUPT_STATUS__PUSH_WHEN_FULL__SHIFT                       4
#define AT_SHA2_INTERRUPT_STATUS__PUSH_WHEN_FULL__WIDTH                       1
#define AT_SHA2_INTERRUPT_STATUS__PUSH_WHEN_FULL__MASK              0x00000010U
#define AT_SHA2_INTERRUPT_STATUS__PUSH_WHEN_FULL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define AT_SHA2_INTERRUPT_STATUS__PUSH_WHEN_FULL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define AT_SHA2_INTERRUPT_STATUS__PUSH_WHEN_FULL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define AT_SHA2_INTERRUPT_STATUS__PUSH_WHEN_FULL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field pop_when_empty */
/**
 * @defgroup at_ahb_sha2_regs_core_pop_when_empty_field pop_when_empty_field
 * @brief macros for field pop_when_empty
 * @details pop when Message FIFO is full condition
 * @{
 */
#define AT_SHA2_INTERRUPT_STATUS__POP_WHEN_EMPTY__SHIFT                       5
#define AT_SHA2_INTERRUPT_STATUS__POP_WHEN_EMPTY__WIDTH                       1
#define AT_SHA2_INTERRUPT_STATUS__POP_WHEN_EMPTY__MASK              0x00000020U
#define AT_SHA2_INTERRUPT_STATUS__POP_WHEN_EMPTY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define AT_SHA2_INTERRUPT_STATUS__POP_WHEN_EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define AT_SHA2_INTERRUPT_STATUS__POP_WHEN_EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define AT_SHA2_INTERRUPT_STATUS__POP_WHEN_EMPTY__RESET_VALUE       0x00000000U
/** @} */

/* macros for field hmac_err */
/**
 * @defgroup at_ahb_sha2_regs_core_hmac_err_field hmac_err_field
 * @brief macros for field hmac_err
 * @details HMAC error occurred. ERR_CODE register shows which error occurred
 * @{
 */
#define AT_SHA2_INTERRUPT_STATUS__HMAC_ERR__SHIFT                             6
#define AT_SHA2_INTERRUPT_STATUS__HMAC_ERR__WIDTH                             1
#define AT_SHA2_INTERRUPT_STATUS__HMAC_ERR__MASK                    0x00000040U
#define AT_SHA2_INTERRUPT_STATUS__HMAC_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define AT_SHA2_INTERRUPT_STATUS__HMAC_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define AT_SHA2_INTERRUPT_STATUS__HMAC_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define AT_SHA2_INTERRUPT_STATUS__HMAC_ERR__RESET_VALUE             0x00000000U
/** @} */
#define AT_SHA2_INTERRUPT_STATUS__TYPE                                 uint32_t
#define AT_SHA2_INTERRUPT_STATUS__READ                              0x0000007fU
#define AT_SHA2_INTERRUPT_STATUS__PRESERVED                         0x00000000U
#define AT_SHA2_INTERRUPT_STATUS__RESET_VALUE                       0x00000000U

#endif /* __AT_SHA2_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_interrupt_mask */
/**
 * @defgroup at_ahb_sha2_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __AT_SHA2_INTERRUPT_MASK_MACRO__
#define __AT_SHA2_INTERRUPT_MASK_MACRO__

/* macros for field fifo_empty */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_empty_field fifo_empty_field
 * @brief macros for field fifo_empty
 * @details interrupt mask bit
 * @{
 */
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__SHIFT                             0
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__WIDTH                             1
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__MASK                    0x00000001U
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_SHA2_INTERRUPT_MASK__FIFO_EMPTY__RESET_VALUE             0x00000000U
/** @} */

/* macros for field fifo_full */
/**
 * @defgroup at_ahb_sha2_regs_core_fifo_full_field fifo_full_field
 * @brief macros for field fifo_full
 * @details interrupt mask bit
 * @{
 */
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__SHIFT                              1
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__WIDTH                              1
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__MASK                     0x00000002U
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_SHA2_INTERRUPT_MASK__FIFO_FULL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field chunk_done */
/**
 * @defgroup at_ahb_sha2_regs_core_chunk_done_field chunk_done_field
 * @brief macros for field chunk_done
 * @details interrupt mask bit
 * @{
 */
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__SHIFT                             2
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__WIDTH                             1
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__MASK                    0x00000004U
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_SHA2_INTERRUPT_MASK__CHUNK_DONE__RESET_VALUE             0x00000000U
/** @} */

/* macros for field hmac_done */
/**
 * @defgroup at_ahb_sha2_regs_core_hmac_done_field hmac_done_field
 * @brief macros for field hmac_done
 * @details interrupt mask bit
 * @{
 */
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__SHIFT                              3
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__WIDTH                              1
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__MASK                     0x00000008U
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_SHA2_INTERRUPT_MASK__HMAC_DONE__RESET_VALUE              0x00000000U
/** @} */

/* macros for field push_when_full */
/**
 * @defgroup at_ahb_sha2_regs_core_push_when_full_field push_when_full_field
 * @brief macros for field push_when_full
 * @details interrupt mask bit
 * @{
 */
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__SHIFT                         4
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__WIDTH                         1
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__MASK                0x00000010U
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define AT_SHA2_INTERRUPT_MASK__PUSH_WHEN_FULL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field pop_when_empty */
/**
 * @defgroup at_ahb_sha2_regs_core_pop_when_empty_field pop_when_empty_field
 * @brief macros for field pop_when_empty
 * @details interrupt mask bit
 * @{
 */
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__SHIFT                         5
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__WIDTH                         1
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__MASK                0x00000020U
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define AT_SHA2_INTERRUPT_MASK__POP_WHEN_EMPTY__RESET_VALUE         0x00000000U
/** @} */

/* macros for field hmac_err */
/**
 * @defgroup at_ahb_sha2_regs_core_hmac_err_field hmac_err_field
 * @brief macros for field hmac_err
 * @details interrupt mask bit
 * @{
 */
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__SHIFT                               6
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__WIDTH                               1
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__MASK                      0x00000040U
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define AT_SHA2_INTERRUPT_MASK__HMAC_ERR__RESET_VALUE               0x00000000U
/** @} */
#define AT_SHA2_INTERRUPT_MASK__TYPE                                   uint32_t
#define AT_SHA2_INTERRUPT_MASK__READ                                0x0000007fU
#define AT_SHA2_INTERRUPT_MASK__WRITE                               0x0000007fU
#define AT_SHA2_INTERRUPT_MASK__PRESERVED                           0x00000000U
#define AT_SHA2_INTERRUPT_MASK__RESET_VALUE                         0x00000000U

#endif /* __AT_SHA2_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_set_interrupt */
/**
 * @defgroup at_ahb_sha2_regs_core_set_interrupt set_interrupt
 * @brief Contains register fields associated with set_interrupt. definitions.
 * @{
 */
#ifndef __AT_SHA2_SET_INTERRUPT_MACRO__
#define __AT_SHA2_SET_INTERRUPT_MACRO__

/* macros for field intrpt_set */
/**
 * @defgroup at_ahb_sha2_regs_core_intrpt_set_field intrpt_set_field
 * @brief macros for field intrpt_set
 * @details if nth bit set, the nth interrupt is set; self clearing
 * @{
 */
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__SHIFT                              0
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__WIDTH                              7
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__MASK                     0x0000007fU
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define AT_SHA2_SET_INTERRUPT__INTRPT_SET__RESET_VALUE              0x00000000U
/** @} */
#define AT_SHA2_SET_INTERRUPT__TYPE                                    uint32_t
#define AT_SHA2_SET_INTERRUPT__READ                                 0x0000007fU
#define AT_SHA2_SET_INTERRUPT__WRITE                                0x0000007fU
#define AT_SHA2_SET_INTERRUPT__PRESERVED                            0x00000000U
#define AT_SHA2_SET_INTERRUPT__RESET_VALUE                          0x00000000U

#endif /* __AT_SHA2_SET_INTERRUPT_MACRO__ */

/** @} end of set_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_reset_interrupt */
/**
 * @defgroup at_ahb_sha2_regs_core_reset_interrupt reset_interrupt
 * @brief Contains register fields associated with reset_interrupt. definitions.
 * @{
 */
#ifndef __AT_SHA2_RESET_INTERRUPT_MACRO__
#define __AT_SHA2_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_ahb_sha2_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details if nth bit set, the nth interrupt is reset; self clearing
 * @{
 */
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__SHIFT                          0
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__WIDTH                          7
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__MASK                 0x0000007fU
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE          0x00000000U
/** @} */
#define AT_SHA2_RESET_INTERRUPT__TYPE                                  uint32_t
#define AT_SHA2_RESET_INTERRUPT__READ                               0x0000007fU
#define AT_SHA2_RESET_INTERRUPT__WRITE                              0x0000007fU
#define AT_SHA2_RESET_INTERRUPT__PRESERVED                          0x00000000U
#define AT_SHA2_RESET_INTERRUPT__RESET_VALUE                        0x00000000U

#endif /* __AT_SHA2_RESET_INTERRUPT_MACRO__ */

/** @} end of reset_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_err_code */
/**
 * @defgroup at_ahb_sha2_regs_core_err_code err_code
 * @brief Contains register fields associated with err_code. definitions.
 * @{
 */
#ifndef __AT_SHA2_ERR_CODE_MACRO__
#define __AT_SHA2_ERR_CODE_MACRO__

/* macros for field err_code */
/**
 * @defgroup at_ahb_sha2_regs_core_err_code_field err_code_field
 * @brief macros for field err_code
 * @details NoError = 32'h 0000_0000,  SwPushMsgWhenShaDisabled = 32'h 0000_0001,  SwHashStartWhenShaDisabled = 32'h 0000_0002,  SwUpdateSecretKeyInProcess = 32'h 0000_0003,  SwHashStartWhenActive = 32'h 0000_0004,  SwPushMsgWhenDisallowed = 32'h 0000_0005
 * @{
 */
#define AT_SHA2_ERR_CODE__ERR_CODE__SHIFT                                     0
#define AT_SHA2_ERR_CODE__ERR_CODE__WIDTH                                    32
#define AT_SHA2_ERR_CODE__ERR_CODE__MASK                            0xffffffffU
#define AT_SHA2_ERR_CODE__ERR_CODE__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_ERR_CODE__ERR_CODE__RESET_VALUE                     0x00000000U
/** @} */
#define AT_SHA2_ERR_CODE__TYPE                                         uint32_t
#define AT_SHA2_ERR_CODE__READ                                      0xffffffffU
#define AT_SHA2_ERR_CODE__PRESERVED                                 0x00000000U
#define AT_SHA2_ERR_CODE__RESET_VALUE                               0x00000000U

#endif /* __AT_SHA2_ERR_CODE_MACRO__ */

/** @} end of err_code */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_txcount_lo */
/**
 * @defgroup at_ahb_sha2_regs_core_txcount_lo txcount_lo
 * @brief Contains register fields associated with txcount_lo. definitions.
 * @{
 */
#ifndef __AT_SHA2_TXCOUNT_LO_MACRO__
#define __AT_SHA2_TXCOUNT_LO_MACRO__

/* macros for field count_lo */
/**
 * @defgroup at_ahb_sha2_regs_core_count_lo_field count_lo_field
 * @brief macros for field count_lo
 * @details an internal counter (in bits) in hmac. SW has to save and restore this parameter when switching context.
 * @{
 */
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__SHIFT                                   0
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__WIDTH                                  32
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__MASK                          0xffffffffU
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__READ(src) ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_TXCOUNT_LO__COUNT_LO__RESET_VALUE                   0x00000000U
/** @} */
#define AT_SHA2_TXCOUNT_LO__TYPE                                       uint32_t
#define AT_SHA2_TXCOUNT_LO__READ                                    0xffffffffU
#define AT_SHA2_TXCOUNT_LO__WRITE                                   0xffffffffU
#define AT_SHA2_TXCOUNT_LO__PRESERVED                               0x00000000U
#define AT_SHA2_TXCOUNT_LO__RESET_VALUE                             0x00000000U

#endif /* __AT_SHA2_TXCOUNT_LO_MACRO__ */

/** @} end of txcount_lo */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_txcount_hi */
/**
 * @defgroup at_ahb_sha2_regs_core_txcount_hi txcount_hi
 * @brief Contains register fields associated with txcount_hi. definitions.
 * @{
 */
#ifndef __AT_SHA2_TXCOUNT_HI_MACRO__
#define __AT_SHA2_TXCOUNT_HI_MACRO__

/* macros for field count_hi */
/**
 * @defgroup at_ahb_sha2_regs_core_count_hi_field count_hi_field
 * @brief macros for field count_hi
 * @details an internal counter (in bits) in hmac. SW has to save and restore this parameter when switching context.
 * @{
 */
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__SHIFT                                   0
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__WIDTH                                  32
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__MASK                          0xffffffffU
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__READ(src) ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_TXCOUNT_HI__COUNT_HI__RESET_VALUE                   0x00000000U
/** @} */
#define AT_SHA2_TXCOUNT_HI__TYPE                                       uint32_t
#define AT_SHA2_TXCOUNT_HI__READ                                    0xffffffffU
#define AT_SHA2_TXCOUNT_HI__WRITE                                   0xffffffffU
#define AT_SHA2_TXCOUNT_HI__PRESERVED                               0x00000000U
#define AT_SHA2_TXCOUNT_HI__RESET_VALUE                             0x00000000U

#endif /* __AT_SHA2_TXCOUNT_HI_MACRO__ */

/** @} end of txcount_hi */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_sha_txcount_lo */
/**
 * @defgroup at_ahb_sha2_regs_core_sha_txcount_lo sha_txcount_lo
 * @brief Contains register fields associated with sha_txcount_lo. definitions.
 * @{
 */
#ifndef __AT_SHA2_SHA_TXCOUNT_LO_MACRO__
#define __AT_SHA2_SHA_TXCOUNT_LO_MACRO__

/* macros for field count_lo */
/**
 * @defgroup at_ahb_sha2_regs_core_count_lo_field count_lo_field
 * @brief macros for field count_lo
 * @details an internal counter (in bits) in sha. SW has to save and restore this parameter when switching context.
 * @{
 */
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__SHIFT                               0
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__WIDTH                              32
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__MASK                      0xffffffffU
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_SHA_TXCOUNT_LO__COUNT_LO__RESET_VALUE               0x00000000U
/** @} */
#define AT_SHA2_SHA_TXCOUNT_LO__TYPE                                   uint32_t
#define AT_SHA2_SHA_TXCOUNT_LO__READ                                0xffffffffU
#define AT_SHA2_SHA_TXCOUNT_LO__WRITE                               0xffffffffU
#define AT_SHA2_SHA_TXCOUNT_LO__PRESERVED                           0x00000000U
#define AT_SHA2_SHA_TXCOUNT_LO__RESET_VALUE                         0x00000000U

#endif /* __AT_SHA2_SHA_TXCOUNT_LO_MACRO__ */

/** @} end of sha_txcount_lo */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_sha_txcount_hi */
/**
 * @defgroup at_ahb_sha2_regs_core_sha_txcount_hi sha_txcount_hi
 * @brief Contains register fields associated with sha_txcount_hi. definitions.
 * @{
 */
#ifndef __AT_SHA2_SHA_TXCOUNT_HI_MACRO__
#define __AT_SHA2_SHA_TXCOUNT_HI_MACRO__

/* macros for field count_hi */
/**
 * @defgroup at_ahb_sha2_regs_core_count_hi_field count_hi_field
 * @brief macros for field count_hi
 * @details an internal counter (in bits) in sha. SW has to save and restore this parameter when switching context.
 * @{
 */
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__SHIFT                               0
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__WIDTH                              32
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__MASK                      0xffffffffU
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_SHA2_SHA_TXCOUNT_HI__COUNT_HI__RESET_VALUE               0x00000000U
/** @} */
#define AT_SHA2_SHA_TXCOUNT_HI__TYPE                                   uint32_t
#define AT_SHA2_SHA_TXCOUNT_HI__READ                                0xffffffffU
#define AT_SHA2_SHA_TXCOUNT_HI__WRITE                               0xffffffffU
#define AT_SHA2_SHA_TXCOUNT_HI__PRESERVED                           0x00000000U
#define AT_SHA2_SHA_TXCOUNT_HI__RESET_VALUE                         0x00000000U

#endif /* __AT_SHA2_SHA_TXCOUNT_HI_MACRO__ */

/** @} end of sha_txcount_hi */

/* macros for BlueprintGlobalNameSpace::AT_SHA2_id */
/**
 * @defgroup at_ahb_sha2_regs_core_id id
 * @brief Contains register fields associated with id. definitions.
 * @{
 */
#ifndef __AT_SHA2_ID_MACRO__
#define __AT_SHA2_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_ahb_sha2_regs_core_id_field id_field
 * @brief macros for field id
 * @details 'SHA2'
 * @{
 */
#define AT_SHA2_ID__ID__SHIFT                                                 0
#define AT_SHA2_ID__ID__WIDTH                                                32
#define AT_SHA2_ID__ID__MASK                                        0xffffffffU
#define AT_SHA2_ID__ID__READ(src)               ((uint32_t)(src) & 0xffffffffU)
#define AT_SHA2_ID__ID__RESET_VALUE                                 0x53484132U
/** @} */
#define AT_SHA2_ID__TYPE                                               uint32_t
#define AT_SHA2_ID__READ                                            0xffffffffU
#define AT_SHA2_ID__PRESERVED                                       0x00000000U
#define AT_SHA2_ID__RESET_VALUE                                     0x53484132U

#endif /* __AT_SHA2_ID_MACRO__ */

/** @} end of id */

/** @} end of AT_AHB_SHA2_REGS_CORE */
#endif /* __REG_AT_AHB_SHA2_REGS_CORE_H__ */
