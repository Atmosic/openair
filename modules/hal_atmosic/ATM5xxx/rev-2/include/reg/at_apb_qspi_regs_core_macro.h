/*                                                                           */
/* File:       at_apb_qspi_regs_core_macro.h                                 */
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


#ifndef __REG_AT_APB_QSPI_REGS_CORE_H__
#define __REG_AT_APB_QSPI_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_QSPI_REGS_CORE at_apb_qspi_regs_core
 * @ingroup AT_REG
 * @brief at_apb_qspi_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::QSPI_transaction_setup */
/**
 * @defgroup at_apb_qspi_regs_core_transaction_setup transaction_setup
 * @brief Contains register fields associated with transaction_setup. definitions.
 * @{
 */
#ifndef __QSPI_TRANSACTION_SETUP_MACRO__
#define __QSPI_TRANSACTION_SETUP_MACRO__

/* macros for field sample_din */
/**
 * @defgroup at_apb_qspi_regs_core_sample_din_field sample_din_field
 * @brief macros for field sample_din
 * @{
 */
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__SHIFT                             0
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__WIDTH                             8
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__MASK                    0x000000ffU
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define QSPI_TRANSACTION_SETUP__SAMPLE_DIN__RESET_VALUE             0x00000000U
/** @} */

/* macros for field dout_0_ctrl */
/**
 * @defgroup at_apb_qspi_regs_core_dout_0_ctrl_field dout_0_ctrl_field
 * @brief macros for field dout_0_ctrl
 * @details {oe val, drive val}
 * @{
 */
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__SHIFT                            8
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__WIDTH                            2
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__MASK                   0x00000300U
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define QSPI_TRANSACTION_SETUP__DOUT_0_CTRL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field dout_1_ctrl */
/**
 * @defgroup at_apb_qspi_regs_core_dout_1_ctrl_field dout_1_ctrl_field
 * @brief macros for field dout_1_ctrl
 * @details {oe val, drive val}
 * @{
 */
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__SHIFT                           12
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__WIDTH                            2
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__MASK                   0x00003000U
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define QSPI_TRANSACTION_SETUP__DOUT_1_CTRL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field dout_2_ctrl */
/**
 * @defgroup at_apb_qspi_regs_core_dout_2_ctrl_field dout_2_ctrl_field
 * @brief macros for field dout_2_ctrl
 * @details {oe val, drive val}
 * @{
 */
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__SHIFT                           16
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__WIDTH                            2
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__MASK                   0x00030000U
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define QSPI_TRANSACTION_SETUP__DOUT_2_CTRL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field dout_3_ctrl */
/**
 * @defgroup at_apb_qspi_regs_core_dout_3_ctrl_field dout_3_ctrl_field
 * @brief macros for field dout_3_ctrl
 * @details {oe val, drive val}
 * @{
 */
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__SHIFT                           20
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__WIDTH                            2
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__MASK                   0x00300000U
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define QSPI_TRANSACTION_SETUP__DOUT_3_CTRL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field clk_val */
/**
 * @defgroup at_apb_qspi_regs_core_clk_val_field clk_val_field
 * @brief macros for field clk_val
 * @{
 */
#define QSPI_TRANSACTION_SETUP__CLK_VAL__SHIFT                               24
#define QSPI_TRANSACTION_SETUP__CLK_VAL__WIDTH                                1
#define QSPI_TRANSACTION_SETUP__CLK_VAL__MASK                       0x01000000U
#define QSPI_TRANSACTION_SETUP__CLK_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define QSPI_TRANSACTION_SETUP__CLK_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define QSPI_TRANSACTION_SETUP__CLK_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define QSPI_TRANSACTION_SETUP__CLK_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define QSPI_TRANSACTION_SETUP__CLK_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define QSPI_TRANSACTION_SETUP__CLK_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define QSPI_TRANSACTION_SETUP__CLK_VAL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field csn_val */
/**
 * @defgroup at_apb_qspi_regs_core_csn_val_field csn_val_field
 * @brief macros for field csn_val
 * @{
 */
#define QSPI_TRANSACTION_SETUP__CSN_VAL__SHIFT                               25
#define QSPI_TRANSACTION_SETUP__CSN_VAL__WIDTH                                1
#define QSPI_TRANSACTION_SETUP__CSN_VAL__MASK                       0x02000000U
#define QSPI_TRANSACTION_SETUP__CSN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define QSPI_TRANSACTION_SETUP__CSN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define QSPI_TRANSACTION_SETUP__CSN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define QSPI_TRANSACTION_SETUP__CSN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define QSPI_TRANSACTION_SETUP__CSN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define QSPI_TRANSACTION_SETUP__CSN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define QSPI_TRANSACTION_SETUP__CSN_VAL__RESET_VALUE                0x00000001U
/** @} */

/* macros for field remote_ahb_qspi_has_control */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_qspi_has_control_field remote_ahb_qspi_has_control_field
 * @brief macros for field remote_ahb_qspi_has_control
 * @{
 */
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__SHIFT           28
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__WIDTH            1
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__MASK   0x10000000U
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define QSPI_TRANSACTION_SETUP__REMOTE_AHB_QSPI_HAS_CONTROL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field remote_spi_has_control */
/**
 * @defgroup at_apb_qspi_regs_core_remote_spi_has_control_field remote_spi_has_control_field
 * @brief macros for field remote_spi_has_control
 * @{
 */
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__SHIFT                29
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__WIDTH                 1
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__MASK        0x20000000U
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define QSPI_TRANSACTION_SETUP__REMOTE_SPI_HAS_CONTROL__RESET_VALUE 0x00000001U
/** @} */
#define QSPI_TRANSACTION_SETUP__TYPE                                   uint32_t
#define QSPI_TRANSACTION_SETUP__READ                                0x333333ffU
#define QSPI_TRANSACTION_SETUP__WRITE                               0x333333ffU
#define QSPI_TRANSACTION_SETUP__PRESERVED                           0x00000000U
#define QSPI_TRANSACTION_SETUP__RESET_VALUE                         0x22000000U

#endif /* __QSPI_TRANSACTION_SETUP_MACRO__ */

/** @} end of transaction_setup */

/* macros for BlueprintGlobalNameSpace::QSPI_read_data */
/**
 * @defgroup at_apb_qspi_regs_core_read_data read_data
 * @brief Contains register fields associated with read_data. definitions.
 * @{
 */
#ifndef __QSPI_READ_DATA_MACRO__
#define __QSPI_READ_DATA_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_qspi_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define QSPI_READ_DATA__RDATA__SHIFT                                          0
#define QSPI_READ_DATA__RDATA__WIDTH                                          8
#define QSPI_READ_DATA__RDATA__MASK                                 0x000000ffU
#define QSPI_READ_DATA__RDATA__READ(src)        ((uint32_t)(src) & 0x000000ffU)
#define QSPI_READ_DATA__RDATA__RESET_VALUE                          0x00000000U
/** @} */
#define QSPI_READ_DATA__TYPE                                           uint32_t
#define QSPI_READ_DATA__READ                                        0x000000ffU
#define QSPI_READ_DATA__PRESERVED                                   0x00000000U
#define QSPI_READ_DATA__RESET_VALUE                                 0x00000000U

#endif /* __QSPI_READ_DATA_MACRO__ */

/** @} end of read_data */

/* macros for BlueprintGlobalNameSpace::QSPI_override_din */
/**
 * @defgroup at_apb_qspi_regs_core_override_din override_din
 * @brief Contains register fields associated with override_din. definitions.
 * @{
 */
#ifndef __QSPI_OVERRIDE_DIN_MACRO__
#define __QSPI_OVERRIDE_DIN_MACRO__

/* macros for field din_override_val */
/**
 * @defgroup at_apb_qspi_regs_core_din_override_val_field din_override_val_field
 * @brief macros for field din_override_val
 * @{
 */
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__SHIFT                            0
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__WIDTH                            4
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__MASK                   0x0000000fU
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define QSPI_OVERRIDE_DIN__DIN_OVERRIDE_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_din */
/**
 * @defgroup at_apb_qspi_regs_core_override_din_field override_din_field
 * @brief macros for field override_din
 * @{
 */
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__SHIFT                                4
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__WIDTH                                1
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__MASK                       0x00000010U
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define QSPI_OVERRIDE_DIN__OVERRIDE_DIN__RESET_VALUE                0x00000000U
/** @} */
#define QSPI_OVERRIDE_DIN__TYPE                                        uint32_t
#define QSPI_OVERRIDE_DIN__READ                                     0x0000001fU
#define QSPI_OVERRIDE_DIN__WRITE                                    0x0000001fU
#define QSPI_OVERRIDE_DIN__PRESERVED                                0x00000000U
#define QSPI_OVERRIDE_DIN__RESET_VALUE                              0x00000000U

#endif /* __QSPI_OVERRIDE_DIN_MACRO__ */

/** @} end of override_din */

/* macros for BlueprintGlobalNameSpace::QSPI_mode */
/**
 * @defgroup at_apb_qspi_regs_core_mode mode
 * @brief Contains register fields associated with mode. definitions.
 * @{
 */
#ifndef __QSPI_MODE_MACRO__
#define __QSPI_MODE_MACRO__

/* macros for field is_dual */
/**
 * @defgroup at_apb_qspi_regs_core_is_dual_field is_dual_field
 * @brief macros for field is_dual
 * @details for debug
 * @{
 */
#define QSPI_MODE__IS_DUAL__SHIFT                                             0
#define QSPI_MODE__IS_DUAL__WIDTH                                             1
#define QSPI_MODE__IS_DUAL__MASK                                    0x00000001U
#define QSPI_MODE__IS_DUAL__READ(src)           ((uint32_t)(src) & 0x00000001U)
#define QSPI_MODE__IS_DUAL__WRITE(src)          ((uint32_t)(src) & 0x00000001U)
#define QSPI_MODE__IS_DUAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define QSPI_MODE__IS_DUAL__VERIFY(src)   (!(((uint32_t)(src) & ~0x00000001U)))
#define QSPI_MODE__IS_DUAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QSPI_MODE__IS_DUAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QSPI_MODE__IS_DUAL__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field is_quad */
/**
 * @defgroup at_apb_qspi_regs_core_is_quad_field is_quad_field
 * @brief macros for field is_quad
 * @details high priority than is_dual
 * @{
 */
#define QSPI_MODE__IS_QUAD__SHIFT                                             1
#define QSPI_MODE__IS_QUAD__WIDTH                                             1
#define QSPI_MODE__IS_QUAD__MASK                                    0x00000002U
#define QSPI_MODE__IS_QUAD__READ(src)    (((uint32_t)(src) & 0x00000002U) >> 1)
#define QSPI_MODE__IS_QUAD__WRITE(src)   (((uint32_t)(src) << 1) & 0x00000002U)
#define QSPI_MODE__IS_QUAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define QSPI_MODE__IS_QUAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define QSPI_MODE__IS_QUAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define QSPI_MODE__IS_QUAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define QSPI_MODE__IS_QUAD__RESET_VALUE                             0x00000001U
/** @} */
#define QSPI_MODE__TYPE                                                uint32_t
#define QSPI_MODE__READ                                             0x00000003U
#define QSPI_MODE__WRITE                                            0x00000003U
#define QSPI_MODE__PRESERVED                                        0x00000000U
#define QSPI_MODE__RESET_VALUE                                      0x00000002U

#endif /* __QSPI_MODE_MACRO__ */

/** @} end of mode */

/* macros for BlueprintGlobalNameSpace::QSPI_scratchpad */
/**
 * @defgroup at_apb_qspi_regs_core_scratchpad scratchpad
 * @brief Contains register fields associated with scratchpad. definitions.
 * @{
 */
#ifndef __QSPI_SCRATCHPAD_MACRO__
#define __QSPI_SCRATCHPAD_MACRO__

/* macros for field scratchpad */
/**
 * @defgroup at_apb_qspi_regs_core_scratchpad_field scratchpad_field
 * @brief macros for field scratchpad
 * @{
 */
#define QSPI_SCRATCHPAD__SCRATCHPAD__SHIFT                                    0
#define QSPI_SCRATCHPAD__SCRATCHPAD__WIDTH                                   32
#define QSPI_SCRATCHPAD__SCRATCHPAD__MASK                           0xffffffffU
#define QSPI_SCRATCHPAD__SCRATCHPAD__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define QSPI_SCRATCHPAD__SCRATCHPAD__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define QSPI_SCRATCHPAD__SCRATCHPAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define QSPI_SCRATCHPAD__SCRATCHPAD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define QSPI_SCRATCHPAD__SCRATCHPAD__RESET_VALUE                    0x00000000U
/** @} */
#define QSPI_SCRATCHPAD__TYPE                                          uint32_t
#define QSPI_SCRATCHPAD__READ                                       0xffffffffU
#define QSPI_SCRATCHPAD__WRITE                                      0xffffffffU
#define QSPI_SCRATCHPAD__PRESERVED                                  0x00000000U
#define QSPI_SCRATCHPAD__RESET_VALUE                                0x00000000U

#endif /* __QSPI_SCRATCHPAD_MACRO__ */

/** @} end of scratchpad */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup remote_ahb_setup
 * @brief Contains register fields associated with remote_ahb_setup. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_MACRO__

/* macros for field dummy_cycles */
/**
 * @defgroup at_apb_qspi_regs_core_dummy_cycles_field dummy_cycles_field
 * @brief macros for field dummy_cycles
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__SHIFT                            0
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__WIDTH                            4
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__MASK                   0x0000000fU
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define QSPI_REMOTE_AHB_SETUP__DUMMY_CYCLES__RESET_VALUE            0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_qspi_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details 0,3=single 1=dual 2=quad
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__MODE__SHIFT                                    4
#define QSPI_REMOTE_AHB_SETUP__MODE__WIDTH                                    2
#define QSPI_REMOTE_AHB_SETUP__MODE__MASK                           0x00000030U
#define QSPI_REMOTE_AHB_SETUP__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define QSPI_REMOTE_AHB_SETUP__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define QSPI_REMOTE_AHB_SETUP__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define QSPI_REMOTE_AHB_SETUP__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define QSPI_REMOTE_AHB_SETUP__MODE__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field is_opcode */
/**
 * @defgroup at_apb_qspi_regs_core_is_opcode_field is_opcode_field
 * @brief macros for field is_opcode
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__SHIFT                               6
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__WIDTH                               1
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__MASK                      0x00000040U
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define QSPI_REMOTE_AHB_SETUP__IS_OPCODE__RESET_VALUE               0x00000000U
/** @} */

/* macros for field opcode */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_field opcode_field
 * @brief macros for field opcode
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__OPCODE__SHIFT                                  8
#define QSPI_REMOTE_AHB_SETUP__OPCODE__WIDTH                                  8
#define QSPI_REMOTE_AHB_SETUP__OPCODE__MASK                         0x0000ff00U
#define QSPI_REMOTE_AHB_SETUP__OPCODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define QSPI_REMOTE_AHB_SETUP__OPCODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define QSPI_REMOTE_AHB_SETUP__OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define QSPI_REMOTE_AHB_SETUP__OPCODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define QSPI_REMOTE_AHB_SETUP__OPCODE__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field clkdivsel */
/**
 * @defgroup at_apb_qspi_regs_core_clkdivsel_field clkdivsel_field
 * @brief macros for field clkdivsel
 * @details 0=1x 1=2x 2=4x 3=8x
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__SHIFT                              16
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__WIDTH                               2
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__MASK                      0x00030000U
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define QSPI_REMOTE_AHB_SETUP__CLKDIVSEL__RESET_VALUE               0x00000003U
/** @} */

/* macros for field rdata_byte_swap */
/**
 * @defgroup at_apb_qspi_regs_core_rdata_byte_swap_field rdata_byte_swap_field
 * @brief macros for field rdata_byte_swap
 * @details does a byte swap before passing rdata to backplane
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__SHIFT                        18
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__WIDTH                         1
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__MASK                0x00040000U
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define QSPI_REMOTE_AHB_SETUP__RDATA_BYTE_SWAP__RESET_VALUE         0x00000000U
/** @} */

/* macros for field quad_overhead */
/**
 * @defgroup at_apb_qspi_regs_core_quad_overhead_field quad_overhead_field
 * @brief macros for field quad_overhead
 * @details adds overhead cycles during quad I/O read mode  1 = opcode is fully serial (8-cycles), adds two cycles for performance enhance; (macronix, gigadev, winbond)  0 = opcode is parallelized (2-cycles); no performance enhance cycles needed (micron)
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__SHIFT                          19
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__WIDTH                           1
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__MASK                  0x00080000U
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define QSPI_REMOTE_AHB_SETUP__QUAD_OVERHEAD__RESET_VALUE           0x00000000U
/** @} */

/* macros for field wdata_byte_swap */
/**
 * @defgroup at_apb_qspi_regs_core_wdata_byte_swap_field wdata_byte_swap_field
 * @brief macros for field wdata_byte_swap
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__SHIFT                        20
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__WIDTH                         1
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__MASK                0x00100000U
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define QSPI_REMOTE_AHB_SETUP__WDATA_BYTE_SWAP__RESET_VALUE         0x00000000U
/** @} */

/* macros for field wdata_halfword_swap */
/**
 * @defgroup at_apb_qspi_regs_core_wdata_halfword_swap_field wdata_halfword_swap_field
 * @brief macros for field wdata_halfword_swap
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__SHIFT                    21
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__WIDTH                     1
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__MASK            0x00200000U
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define QSPI_REMOTE_AHB_SETUP__WDATA_HALFWORD_SWAP__RESET_VALUE     0x00000000U
/** @} */

/* macros for field wdata_word_swap */
/**
 * @defgroup at_apb_qspi_regs_core_wdata_word_swap_field wdata_word_swap_field
 * @brief macros for field wdata_word_swap
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__SHIFT                        22
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__WIDTH                         1
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__MASK                0x00400000U
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define QSPI_REMOTE_AHB_SETUP__WDATA_WORD_SWAP__RESET_VALUE         0x00000000U
/** @} */

/* macros for field enable_clocks */
/**
 * @defgroup at_apb_qspi_regs_core_enable_clocks_field enable_clocks_field
 * @brief macros for field enable_clocks
 * @details for the core clocks not the qspi interface clock
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__SHIFT                          23
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__WIDTH                           1
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__MASK                  0x00800000U
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CLOCKS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field enable_cache */
/**
 * @defgroup at_apb_qspi_regs_core_enable_cache_field enable_cache_field
 * @brief macros for field enable_cache
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__SHIFT                           24
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__WIDTH                            1
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__MASK                   0x01000000U
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_CACHE__RESET_VALUE            0x00000000U
/** @} */

/* macros for field enable_fine_clock_gating */
/**
 * @defgroup at_apb_qspi_regs_core_enable_fine_clock_gating_field enable_fine_clock_gating_field
 * @brief macros for field enable_fine_clock_gating
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__SHIFT               25
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__WIDTH                1
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__MASK       0x02000000U
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define QSPI_REMOTE_AHB_SETUP__ENABLE_FINE_CLOCK_GATING__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field invalidate_entire_cache */
/**
 * @defgroup at_apb_qspi_regs_core_invalidate_entire_cache_field invalidate_entire_cache_field
 * @brief macros for field invalidate_entire_cache
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__SHIFT                26
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__WIDTH                 1
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__MASK        0x04000000U
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define QSPI_REMOTE_AHB_SETUP__INVALIDATE_ENTIRE_CACHE__RESET_VALUE 0x00000000U
/** @} */

/* macros for field serialize_pp_address */
/**
 * @defgroup at_apb_qspi_regs_core_serialize_pp_address_field serialize_pp_address_field
 * @brief macros for field serialize_pp_address
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__SHIFT                   27
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__WIDTH                    1
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__MASK           0x08000000U
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define QSPI_REMOTE_AHB_SETUP__SERIALIZE_PP_ADDRESS__RESET_VALUE    0x00000000U
/** @} */

/* macros for field skew_csn_act_wen */
/**
 * @defgroup at_apb_qspi_regs_core_skew_csn_act_wen_field skew_csn_act_wen_field
 * @brief macros for field skew_csn_act_wen
 * @details in a write sequence, controller stalls the start of the sequence; set if div-by-1
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__SHIFT                       28
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__WIDTH                        1
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__MASK               0x10000000U
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define QSPI_REMOTE_AHB_SETUP__SKEW_CSN_ACT_WEN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field hyper */
/**
 * @defgroup at_apb_qspi_regs_core_hyper_field hyper_field
 * @brief macros for field hyper
 * @details core runs at 32MHz instead of 16MHz
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__HYPER__SHIFT                                  29
#define QSPI_REMOTE_AHB_SETUP__HYPER__WIDTH                                   1
#define QSPI_REMOTE_AHB_SETUP__HYPER__MASK                          0x20000000U
#define QSPI_REMOTE_AHB_SETUP__HYPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define QSPI_REMOTE_AHB_SETUP__HYPER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define QSPI_REMOTE_AHB_SETUP__HYPER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define QSPI_REMOTE_AHB_SETUP__HYPER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define QSPI_REMOTE_AHB_SETUP__HYPER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define QSPI_REMOTE_AHB_SETUP__HYPER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define QSPI_REMOTE_AHB_SETUP__HYPER__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field slip_half_cycle */
/**
 * @defgroup at_apb_qspi_regs_core_slip_half_cycle_field slip_half_cycle_field
 * @brief macros for field slip_half_cycle
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__SHIFT                        30
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__WIDTH                         1
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__MASK                0x40000000U
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define QSPI_REMOTE_AHB_SETUP__SLIP_HALF_CYCLE__RESET_VALUE         0x00000001U
/** @} */

/* macros for field dual_overhead */
/**
 * @defgroup at_apb_qspi_regs_core_dual_overhead_field dual_overhead_field
 * @brief macros for field dual_overhead
 * @details add overhead cycle during dual I/O read mode  1 = add four cycles for performace enhance; (gigadev, winbond)  0 = add two cycle ,no performance enhance cycle (macronix)
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__SHIFT                          31
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__WIDTH                           1
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__MASK                  0x80000000U
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define QSPI_REMOTE_AHB_SETUP__DUAL_OVERHEAD__RESET_VALUE           0x00000000U
/** @} */
#define QSPI_REMOTE_AHB_SETUP__TYPE                                    uint32_t
#define QSPI_REMOTE_AHB_SETUP__READ                                 0xffffff7fU
#define QSPI_REMOTE_AHB_SETUP__WRITE                                0xffffff7fU
#define QSPI_REMOTE_AHB_SETUP__PRESERVED                            0x00000000U
#define QSPI_REMOTE_AHB_SETUP__RESET_VALUE                          0x42030000U

#endif /* __QSPI_REMOTE_AHB_SETUP_MACRO__ */

/** @} end of remote_ahb_setup */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_2 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_2 remote_ahb_setup_2
 * @brief Contains register fields associated with remote_ahb_setup_2. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_2_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_2_MACRO__

/* macros for field opcode_we */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_we_field opcode_we_field
 * @brief macros for field opcode_we
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__SHIFT                             0
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__WIDTH                             8
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__MASK                    0x000000ffU
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WE__RESET_VALUE             0x00000006U
/** @} */

/* macros for field opcode_pp */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_pp_field opcode_pp_field
 * @brief macros for field opcode_pp
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__SHIFT                             8
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__WIDTH                             8
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__MASK                    0x0000ff00U
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_PP__RESET_VALUE             0x00000002U
/** @} */

/* macros for field opcode_wip */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_wip_field opcode_wip_field
 * @brief macros for field opcode_wip
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__SHIFT                           16
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__WIDTH                            8
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__MASK                   0x00ff0000U
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_WIP__RESET_VALUE            0x00000005U
/** @} */

/* macros for field opcode_se */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_se_field opcode_se_field
 * @brief macros for field opcode_se
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__SHIFT                            24
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__WIDTH                             8
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__MASK                    0xff000000U
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define QSPI_REMOTE_AHB_SETUP_2__OPCODE_SE__RESET_VALUE             0x00000020U
/** @} */
#define QSPI_REMOTE_AHB_SETUP_2__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_2__READ                               0xffffffffU
#define QSPI_REMOTE_AHB_SETUP_2__WRITE                              0xffffffffU
#define QSPI_REMOTE_AHB_SETUP_2__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_2__RESET_VALUE                        0x20050206U

#endif /* __QSPI_REMOTE_AHB_SETUP_2_MACRO__ */

/** @} end of remote_ahb_setup_2 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_3 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_3 remote_ahb_setup_3
 * @brief Contains register fields associated with remote_ahb_setup_3. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_3_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_3_MACRO__

/* macros for field opcode_performance_mode */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_performance_mode_field opcode_performance_mode_field
 * @brief macros for field opcode_performance_mode
 * @details performance enhance mode opcode  macronix = 8'h5A  gigadev = 8'hAx  winbond = 8'h20
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__SHIFT              14
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__WIDTH               8
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__MASK      0x003fc000U
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003fc000U) >> 14)
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x003fc000U)
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fc000U) | (((uint32_t)(src) <<\
                    14) & 0x003fc000U)
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x003fc000U)))
#define QSPI_REMOTE_AHB_SETUP_3__OPCODE_PERFORMANCE_MODE__RESET_VALUE \
                    0x0000005aU
/** @} */

/* macros for field enable_performance_mode */
/**
 * @defgroup at_apb_qspi_regs_core_enable_performance_mode_field enable_performance_mode_field
 * @brief macros for field enable_performance_mode
 * @details enable performace enhance mode for supported flash
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__SHIFT              22
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__WIDTH               1
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__MASK      0x00400000U
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define QSPI_REMOTE_AHB_SETUP_3__ENABLE_PERFORMANCE_MODE__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field wle_polarity */
/**
 * @defgroup at_apb_qspi_regs_core_wle_polarity_field wle_polarity_field
 * @brief macros for field wle_polarity
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__SHIFT                         23
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__WIDTH                          1
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__MASK                 0x00800000U
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_POLARITY__RESET_VALUE          0x00000001U
/** @} */

/* macros for field wle_bit */
/**
 * @defgroup at_apb_qspi_regs_core_wle_bit_field wle_bit_field
 * @brief macros for field wle_bit
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__SHIFT                              24
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__WIDTH                               3
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__MASK                      0x07000000U
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define QSPI_REMOTE_AHB_SETUP_3__WLE_BIT__RESET_VALUE               0x00000001U
/** @} */

/* macros for field wip_polarity */
/**
 * @defgroup at_apb_qspi_regs_core_wip_polarity_field wip_polarity_field
 * @brief macros for field wip_polarity
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__SHIFT                         27
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__WIDTH                          1
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__MASK                 0x08000000U
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_POLARITY__RESET_VALUE          0x00000001U
/** @} */

/* macros for field wip_bit */
/**
 * @defgroup at_apb_qspi_regs_core_wip_bit_field wip_bit_field
 * @brief macros for field wip_bit
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__SHIFT                              28
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__WIDTH                               3
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__MASK                      0x70000000U
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x70000000U) >> 28)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x70000000U)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x70000000U) | (((uint32_t)(src) <<\
                    28) & 0x70000000U)
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x70000000U)))
#define QSPI_REMOTE_AHB_SETUP_3__WIP_BIT__RESET_VALUE               0x00000000U
/** @} */

/* macros for field check_wle */
/**
 * @defgroup at_apb_qspi_regs_core_check_wle_field check_wle_field
 * @brief macros for field check_wle
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__SHIFT                            31
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__WIDTH                             1
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__MASK                    0x80000000U
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define QSPI_REMOTE_AHB_SETUP_3__CHECK_WLE__RESET_VALUE             0x00000000U
/** @} */
#define QSPI_REMOTE_AHB_SETUP_3__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_3__READ                               0xffffc000U
#define QSPI_REMOTE_AHB_SETUP_3__WRITE                              0xffffc000U
#define QSPI_REMOTE_AHB_SETUP_3__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_3__RESET_VALUE                        0x09968000U

#endif /* __QSPI_REMOTE_AHB_SETUP_3_MACRO__ */

/** @} end of remote_ahb_setup_3 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_4 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_4 remote_ahb_setup_4
 * @brief Contains register fields associated with remote_ahb_setup_4. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_4_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_4_MACRO__

/* macros for field invert_addr */
/**
 * @defgroup at_apb_qspi_regs_core_invert_addr_field invert_addr_field
 * @brief macros for field invert_addr
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__SHIFT                           0
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__WIDTH                          24
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__MASK                  0x00ffffffU
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00ffffffU)))
#define QSPI_REMOTE_AHB_SETUP_4__INVERT_ADDR__RESET_VALUE           0x00000000U
/** @} */

/* macros for field set_intrp */
/**
 * @defgroup at_apb_qspi_regs_core_set_intrp_field set_intrp_field
 * @brief macros for field set_intrp
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__SHIFT                            24
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__WIDTH                             1
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__MASK                    0x01000000U
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define QSPI_REMOTE_AHB_SETUP_4__SET_INTRP__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrp */
/**
 * @defgroup at_apb_qspi_regs_core_clear_intrp_field clear_intrp_field
 * @brief macros for field clear_intrp
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__SHIFT                          25
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__WIDTH                           1
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__MASK                  0x02000000U
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define QSPI_REMOTE_AHB_SETUP_4__CLEAR_INTRP__RESET_VALUE           0x00000000U
/** @} */

/* macros for field mask_intrp */
/**
 * @defgroup at_apb_qspi_regs_core_mask_intrp_field mask_intrp_field
 * @brief macros for field mask_intrp
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__SHIFT                           26
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__WIDTH                            1
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__MASK                   0x04000000U
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define QSPI_REMOTE_AHB_SETUP_4__MASK_INTRP__RESET_VALUE            0x00000000U
/** @} */

/* macros for field to_intrp_en */
/**
 * @defgroup at_apb_qspi_regs_core_to_intrp_en_field to_intrp_en_field
 * @brief macros for field to_intrp_en
 * @details wel_to and wip_to interrupt
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__SHIFT                          27
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__WIDTH                           1
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__MASK                  0x08000000U
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define QSPI_REMOTE_AHB_SETUP_4__TO_INTRP_EN__RESET_VALUE           0x00000000U
/** @} */

/* macros for field allow_reads_during_write */
/**
 * @defgroup at_apb_qspi_regs_core_allow_reads_during_write_field allow_reads_during_write_field
 * @brief macros for field allow_reads_during_write
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__SHIFT             28
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__WIDTH              1
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__MASK     0x10000000U
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define QSPI_REMOTE_AHB_SETUP_4__ALLOW_READS_DURING_WRITE__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field next_csn_guard */
/**
 * @defgroup at_apb_qspi_regs_core_next_csn_guard_field next_csn_guard_field
 * @brief macros for field next_csn_guard
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__SHIFT                       29
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__WIDTH                        2
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__MASK               0x60000000U
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x60000000U) >> 29)
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x60000000U)
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x60000000U) | (((uint32_t)(src) <<\
                    29) & 0x60000000U)
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x60000000U)))
#define QSPI_REMOTE_AHB_SETUP_4__NEXT_CSN_GUARD__RESET_VALUE        0x00000000U
/** @} */
#define QSPI_REMOTE_AHB_SETUP_4__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_4__READ                               0x7fffffffU
#define QSPI_REMOTE_AHB_SETUP_4__WRITE                              0x7fffffffU
#define QSPI_REMOTE_AHB_SETUP_4__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_4__RESET_VALUE                        0x00000000U

#endif /* __QSPI_REMOTE_AHB_SETUP_4_MACRO__ */

/** @} end of remote_ahb_setup_4 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_5 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_5 remote_ahb_setup_5
 * @brief Contains register fields associated with remote_ahb_setup_5. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_5_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_5_MACRO__

/* macros for field pp_stall_wip */
/**
 * @defgroup at_apb_qspi_regs_core_pp_stall_wip_field pp_stall_wip_field
 * @brief macros for field pp_stall_wip
 * @details interval between two check of WIP
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__SHIFT                          0
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__WIDTH                         10
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__MASK                 0x000003ffU
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define QSPI_REMOTE_AHB_SETUP_5__PP_STALL_WIP__RESET_VALUE          0x00000200U
/** @} */

/* macros for field stall_wle */
/**
 * @defgroup at_apb_qspi_regs_core_stall_wle_field stall_wle_field
 * @brief macros for field stall_wle
 * @details interval between WEN and check for WEL
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__SHIFT                            10
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__WIDTH                            10
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__MASK                    0x000ffc00U
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WLE__RESET_VALUE             0x00000002U
/** @} */

/* macros for field stall_we2pp */
/**
 * @defgroup at_apb_qspi_regs_core_stall_we2pp_field stall_we2pp_field
 * @brief macros for field stall_we2pp
 * @details wen or wle to pp depending on check_wle setting
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__SHIFT                          20
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__WIDTH                          10
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__MASK                  0x3ff00000U
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define QSPI_REMOTE_AHB_SETUP_5__STALL_WE2PP__RESET_VALUE           0x00000002U
/** @} */
#define QSPI_REMOTE_AHB_SETUP_5__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_5__READ                               0x3fffffffU
#define QSPI_REMOTE_AHB_SETUP_5__WRITE                              0x3fffffffU
#define QSPI_REMOTE_AHB_SETUP_5__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_5__RESET_VALUE                        0x00200a00U

#endif /* __QSPI_REMOTE_AHB_SETUP_5_MACRO__ */

/** @} end of remote_ahb_setup_5 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_6 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_6 remote_ahb_setup_6
 * @brief Contains register fields associated with remote_ahb_setup_6. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_6_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_6_MACRO__

/* macros for field se_stall_wip */
/**
 * @defgroup at_apb_qspi_regs_core_se_stall_wip_field se_stall_wip_field
 * @brief macros for field se_stall_wip
 * @details interval between two check of WIP
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__SHIFT                          0
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__WIDTH                         16
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__MASK                 0x0000ffffU
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define QSPI_REMOTE_AHB_SETUP_6__SE_STALL_WIP__RESET_VALUE          0x00001fffU
/** @} */

/* macros for field opcode_suspend */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_suspend_field opcode_suspend_field
 * @brief macros for field opcode_suspend
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__SHIFT                       16
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__WIDTH                        8
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__MASK               0x00ff0000U
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_SUSPEND__RESET_VALUE        0x00000075U
/** @} */

/* macros for field opcode_resume */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_resume_field opcode_resume_field
 * @brief macros for field opcode_resume
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__SHIFT                        24
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__WIDTH                         8
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__MASK                0xff000000U
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define QSPI_REMOTE_AHB_SETUP_6__OPCODE_RESUME__RESET_VALUE         0x0000007aU
/** @} */
#define QSPI_REMOTE_AHB_SETUP_6__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_6__READ                               0xffffffffU
#define QSPI_REMOTE_AHB_SETUP_6__WRITE                              0xffffffffU
#define QSPI_REMOTE_AHB_SETUP_6__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_6__RESET_VALUE                        0x7a751fffU

#endif /* __QSPI_REMOTE_AHB_SETUP_6_MACRO__ */

/** @} end of remote_ahb_setup_6 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_7 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_7 remote_ahb_setup_7
 * @brief Contains register fields associated with remote_ahb_setup_7. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_7_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_7_MACRO__

/* macros for field remap_table */
/**
 * @defgroup at_apb_qspi_regs_core_remap_table_field remap_table_field
 * @brief macros for field remap_table
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__SHIFT                           0
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__WIDTH                          24
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__MASK                  0x00ffffffU
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00ffffffU)))
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_TABLE__RESET_VALUE           0x00000000U
/** @} */

/* macros for field remap_msb_loc_sub2 */
/**
 * @defgroup at_apb_qspi_regs_core_remap_msb_loc_sub2_field remap_msb_loc_sub2_field
 * @brief macros for field remap_msb_loc_sub2
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__SHIFT                   24
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__WIDTH                    5
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__MASK           0x1f000000U
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1f000000U) >> 24)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x1f000000U)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1f000000U) | (((uint32_t)(src) <<\
                    24) & 0x1f000000U)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x1f000000U)))
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_MSB_LOC_SUB2__RESET_VALUE    0x00000015U
/** @} */

/* macros for field remap_legacy */
/**
 * @defgroup at_apb_qspi_regs_core_remap_legacy_field remap_legacy_field
 * @brief macros for field remap_legacy
 * @details Not used and tie to 0 in Cairo
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__SHIFT                         29
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__WIDTH                          1
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__MASK                 0x20000000U
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define QSPI_REMOTE_AHB_SETUP_7__REMAP_LEGACY__RESET_VALUE          0x00000000U
/** @} */
#define QSPI_REMOTE_AHB_SETUP_7__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_7__READ                               0x3fffffffU
#define QSPI_REMOTE_AHB_SETUP_7__WRITE                              0x3fffffffU
#define QSPI_REMOTE_AHB_SETUP_7__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_7__RESET_VALUE                        0x15000000U

#endif /* __QSPI_REMOTE_AHB_SETUP_7_MACRO__ */

/** @} end of remote_ahb_setup_7 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_8 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_8 remote_ahb_setup_8
 * @brief Contains register fields associated with remote_ahb_setup_8. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_8_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_8_MACRO__

/* macros for field pp_stall_wip_msb */
/**
 * @defgroup at_apb_qspi_regs_core_pp_stall_wip_msb_field pp_stall_wip_msb_field
 * @brief macros for field pp_stall_wip_msb
 * @details extends the wip check time by 6 bits
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__SHIFT                      0
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__WIDTH                      6
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__MASK             0x0000003fU
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define QSPI_REMOTE_AHB_SETUP_8__PP_STALL_WIP_MSB__RESET_VALUE      0x00000000U
/** @} */

/* macros for field enb_debug_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_enb_debug_cnt_field enb_debug_cnt_field
 * @brief macros for field enb_debug_cnt
 * @details 1 switch on debug counter, 0 switch off debug counter
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__SHIFT                         6
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__WIDTH                         1
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__MASK                0x00000040U
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define QSPI_REMOTE_AHB_SETUP_8__ENB_DEBUG_CNT__RESET_VALUE         0x00000000U
/** @} */

/* macros for field opcode_dualread */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_dualread_field opcode_dualread_field
 * @brief macros for field opcode_dualread
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__SHIFT                       8
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__WIDTH                       8
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__MASK              0x0000ff00U
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_DUALREAD__RESET_VALUE       0x0000003bU
/** @} */

/* macros for field opcode_quadread */
/**
 * @defgroup at_apb_qspi_regs_core_opcode_quadread_field opcode_quadread_field
 * @brief macros for field opcode_quadread
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__SHIFT                      16
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__WIDTH                       8
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__MASK              0x00ff0000U
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define QSPI_REMOTE_AHB_SETUP_8__OPCODE_QUADREAD__RESET_VALUE       0x0000006bU
/** @} */
#define QSPI_REMOTE_AHB_SETUP_8__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_8__READ                               0x00ffff7fU
#define QSPI_REMOTE_AHB_SETUP_8__WRITE                              0x00ffff7fU
#define QSPI_REMOTE_AHB_SETUP_8__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_8__RESET_VALUE                        0x006b3b00U

#endif /* __QSPI_REMOTE_AHB_SETUP_8_MACRO__ */

/** @} end of remote_ahb_setup_8 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_9 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_9 remote_ahb_setup_9
 * @brief Contains register fields associated with remote_ahb_setup_9. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_9_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_9_MACRO__

/* macros for field psl */
/**
 * @defgroup at_apb_qspi_regs_core_psl_field psl_field
 * @brief macros for field psl
 * @details program suspend latency; how long after suspending of program can a read take place? (number of cycles in clk_backplane)
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_9__PSL__SHIFT                                   0
#define QSPI_REMOTE_AHB_SETUP_9__PSL__WIDTH                                  16
#define QSPI_REMOTE_AHB_SETUP_9__PSL__MASK                          0x0000ffffU
#define QSPI_REMOTE_AHB_SETUP_9__PSL__READ(src) ((uint32_t)(src) & 0x0000ffffU)
#define QSPI_REMOTE_AHB_SETUP_9__PSL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define QSPI_REMOTE_AHB_SETUP_9__PSL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define QSPI_REMOTE_AHB_SETUP_9__PSL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define QSPI_REMOTE_AHB_SETUP_9__PSL__RESET_VALUE                   0x000007d0U
/** @} */

/* macros for field esl */
/**
 * @defgroup at_apb_qspi_regs_core_esl_field esl_field
 * @brief macros for field esl
 * @details erase suspend latency; how long after suspending of erase can a read take place? (number of cycles in clk_backplane)
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_9__ESL__SHIFT                                  16
#define QSPI_REMOTE_AHB_SETUP_9__ESL__WIDTH                                  16
#define QSPI_REMOTE_AHB_SETUP_9__ESL__MASK                          0xffff0000U
#define QSPI_REMOTE_AHB_SETUP_9__ESL__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define QSPI_REMOTE_AHB_SETUP_9__ESL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define QSPI_REMOTE_AHB_SETUP_9__ESL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define QSPI_REMOTE_AHB_SETUP_9__ESL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define QSPI_REMOTE_AHB_SETUP_9__ESL__RESET_VALUE                   0x000007d0U
/** @} */
#define QSPI_REMOTE_AHB_SETUP_9__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_SETUP_9__READ                               0xffffffffU
#define QSPI_REMOTE_AHB_SETUP_9__WRITE                              0xffffffffU
#define QSPI_REMOTE_AHB_SETUP_9__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_SETUP_9__RESET_VALUE                        0x07d007d0U

#endif /* __QSPI_REMOTE_AHB_SETUP_9_MACRO__ */

/** @} end of remote_ahb_setup_9 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_10 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_10 remote_ahb_setup_10
 * @brief Contains register fields associated with remote_ahb_setup_10. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_10_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_10_MACRO__

/* macros for field trs */
/**
 * @defgroup at_apb_qspi_regs_core_trs_field trs_field
 * @brief macros for field trs
 * @details Latency between Program/Erase Resume and next Suspend (in the unit of 64 HCLK cycles i.e. 2us @ 32M HCLK)
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_10__TRS__SHIFT                                  0
#define QSPI_REMOTE_AHB_SETUP_10__TRS__WIDTH                                  8
#define QSPI_REMOTE_AHB_SETUP_10__TRS__MASK                         0x000000ffU
#define QSPI_REMOTE_AHB_SETUP_10__TRS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define QSPI_REMOTE_AHB_SETUP_10__TRS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define QSPI_REMOTE_AHB_SETUP_10__TRS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define QSPI_REMOTE_AHB_SETUP_10__TRS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define QSPI_REMOTE_AHB_SETUP_10__TRS__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field max_cnt_twel */
/**
 * @defgroup at_apb_qspi_regs_core_max_cnt_twel_field max_cnt_twel_field
 * @brief macros for field max_cnt_twel
 * @details max polling count from write enable to wel=1
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__SHIFT                         8
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__WIDTH                        10
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__MASK                0x0003ff00U
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003ff00U) >> 8)
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0003ff00U)
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0003ff00U)
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0003ff00U)))
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_TWEL__RESET_VALUE         0x000003ffU
/** @} */

/* macros for field max_cnt_wip */
/**
 * @defgroup at_apb_qspi_regs_core_max_cnt_wip_field max_cnt_wip_field
 * @brief macros for field max_cnt_wip
 * @details max polling count for wip to finish
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__SHIFT                         20
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__WIDTH                         10
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__MASK                 0x3ff00000U
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define QSPI_REMOTE_AHB_SETUP_10__MAX_CNT_WIP__RESET_VALUE          0x000003ffU
/** @} */
#define QSPI_REMOTE_AHB_SETUP_10__TYPE                                 uint32_t
#define QSPI_REMOTE_AHB_SETUP_10__READ                              0x3ff3ffffU
#define QSPI_REMOTE_AHB_SETUP_10__WRITE                             0x3ff3ffffU
#define QSPI_REMOTE_AHB_SETUP_10__PRESERVED                         0x00000000U
#define QSPI_REMOTE_AHB_SETUP_10__RESET_VALUE                       0x3ff3ff00U

#endif /* __QSPI_REMOTE_AHB_SETUP_10_MACRO__ */

/** @} end of remote_ahb_setup_10 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_setup_11 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_setup_11 remote_ahb_setup_11
 * @brief Contains register fields associated with remote_ahb_setup_11. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_SETUP_11_MACRO__
#define __QSPI_REMOTE_AHB_SETUP_11_MACRO__

/* macros for field slip_one_cycle */
/**
 * @defgroup at_apb_qspi_regs_core_slip_one_cycle_field slip_one_cycle_field
 * @brief macros for field slip_one_cycle
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__SHIFT                       0
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__WIDTH                       1
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__MASK              0x00000001U
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QSPI_REMOTE_AHB_SETUP_11__SLIP_ONE_CYCLE__RESET_VALUE       0x00000000U
/** @} */

/* macros for field turbo */
/**
 * @defgroup at_apb_qspi_regs_core_turbo_field turbo_field
 * @brief macros for field turbo
 * @details enable turbo mode
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__SHIFT                                3
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__WIDTH                                1
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__MASK                       0x00000008U
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO__RESET_VALUE                0x00000000U
/** @} */

/* macros for field turbo_multiplier */
/**
 * @defgroup at_apb_qspi_regs_core_turbo_multiplier_field turbo_multiplier_field
 * @brief macros for field turbo_multiplier
 * @details turbo mode clock freq multiplier
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__SHIFT                     4
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__WIDTH                     3
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__MASK            0x00000070U
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define QSPI_REMOTE_AHB_SETUP_11__TURBO_MULTIPLIER__RESET_VALUE     0x00000001U
/** @} */

/* macros for field allow_early_terminate0 */
/**
 * @defgroup at_apb_qspi_regs_core_allow_early_terminate0_field allow_early_terminate0_field
 * @brief macros for field allow_early_terminate0
 * @details when set, a read to flash can be terminated in adress phase
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__SHIFT               7
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__WIDTH               1
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__MASK      0x00000080U
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE0__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field allow_early_terminate1 */
/**
 * @defgroup at_apb_qspi_regs_core_allow_early_terminate1_field allow_early_terminate1_field
 * @brief macros for field allow_early_terminate1
 * @details when set, a read to flash can be terminated in opcode, and dummy phase
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__SHIFT               8
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__WIDTH               1
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__MASK      0x00000100U
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define QSPI_REMOTE_AHB_SETUP_11__ALLOW_EARLY_TERMINATE1__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field halt_read */
/**
 * @defgroup at_apb_qspi_regs_core_halt_read_field halt_read_field
 * @brief macros for field halt_read
 * @details halt read operation
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__SHIFT                            9
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__WIDTH                            1
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__MASK                   0x00000200U
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_READ__RESET_VALUE            0x00000000U
/** @} */

/* macros for field halt_write */
/**
 * @defgroup at_apb_qspi_regs_core_halt_write_field halt_write_field
 * @brief macros for field halt_write
 * @details halt write or sector erase operation
 * @{
 */
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__SHIFT                          10
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__WIDTH                           1
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__MASK                  0x00000400U
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define QSPI_REMOTE_AHB_SETUP_11__HALT_WRITE__RESET_VALUE           0x00000000U
/** @} */
#define QSPI_REMOTE_AHB_SETUP_11__TYPE                                 uint32_t
#define QSPI_REMOTE_AHB_SETUP_11__READ                              0x000007f9U
#define QSPI_REMOTE_AHB_SETUP_11__WRITE                             0x000007f9U
#define QSPI_REMOTE_AHB_SETUP_11__PRESERVED                         0x00000000U
#define QSPI_REMOTE_AHB_SETUP_11__RESET_VALUE                       0x00000010U

#endif /* __QSPI_REMOTE_AHB_SETUP_11_MACRO__ */

/** @} end of remote_ahb_setup_11 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_prefetch_setup */
/**
 * @defgroup at_apb_qspi_regs_core_remote_prefetch_setup remote_prefetch_setup
 * @brief Contains register fields associated with remote_prefetch_setup. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_PREFETCH_SETUP_MACRO__
#define __QSPI_REMOTE_PREFETCH_SETUP_MACRO__

/* macros for field cl_size */
/**
 * @defgroup at_apb_qspi_regs_core_cl_size_field cl_size_field
 * @brief macros for field cl_size
 * @details cache line length. Only support 4 words now. 00: 2 words 01: 4 words 10/11: Reserved
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__SHIFT                            0
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__WIDTH                            2
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__MASK                   0x00000003U
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define QSPI_REMOTE_PREFETCH_SETUP__CL_SIZE__RESET_VALUE            0x00000001U
/** @} */

/* macros for field cl_mode_en */
/**
 * @defgroup at_apb_qspi_regs_core_cl_mode_en_field cl_mode_en_field
 * @brief macros for field cl_mode_en
 * @details cache line mode enable. Prefetch will always fetch from start of cache line
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__SHIFT                         2
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__WIDTH                         1
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__MASK                0x00000004U
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define QSPI_REMOTE_PREFETCH_SETUP__CL_MODE_EN__RESET_VALUE         0x00000000U
/** @} */

/* macros for field csn_ext_val */
/**
 * @defgroup at_apb_qspi_regs_core_csn_ext_val_field csn_ext_val_field
 * @brief macros for field csn_ext_val
 * @details Keep csn asserted for this number of cycles If later reads are continuous, opcode and address cycles can be saved
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__SHIFT                        4
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__WIDTH                       10
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__MASK               0x00003ff0U
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003ff0U) >> 4)
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00003ff0U)
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003ff0U) | (((uint32_t)(src) <<\
                    4) & 0x00003ff0U)
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00003ff0U)))
#define QSPI_REMOTE_PREFETCH_SETUP__CSN_EXT_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field soft_en_def_bfull */
/**
 * @defgroup at_apb_qspi_regs_core_soft_en_def_bfull_field soft_en_def_bfull_field
 * @brief macros for field soft_en_def_bfull
 * @details software enable its own prefetch buffer full definement
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__SHIFT                 14
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__WIDTH                  1
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__MASK         0x00004000U
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_EN_DEF_BFULL__RESET_VALUE  0x00000000U
/** @} */

/* macros for field soft_defnum_of_bfull */
/**
 * @defgroup at_apb_qspi_regs_core_soft_defnum_of_bfull_field soft_defnum_of_bfull_field
 * @brief macros for field soft_defnum_of_bfull
 * @details if soft_endef_bfull is 1 , this field represent number of buffer full
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__SHIFT              16
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__WIDTH               4
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__MASK      0x000f0000U
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define QSPI_REMOTE_PREFETCH_SETUP__SOFT_DEFNUM_OF_BFULL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field enable_prefetch */
/**
 * @defgroup at_apb_qspi_regs_core_enable_prefetch_field enable_prefetch_field
 * @brief macros for field enable_prefetch
 * @details prefetch enable ,1 is enable
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__SHIFT                   20
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__WIDTH                    1
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__MASK           0x00100000U
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define QSPI_REMOTE_PREFETCH_SETUP__ENABLE_PREFETCH__RESET_VALUE    0x00000000U
/** @} */

/* macros for field reset_prefetch */
/**
 * @defgroup at_apb_qspi_regs_core_reset_prefetch_field reset_prefetch_field
 * @brief macros for field reset_prefetch
 * @details write 1 to reset prefetch.
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__SHIFT                    21
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__WIDTH                     1
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__MASK            0x00200000U
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_PREFETCH__RESET_VALUE     0x00000000U
/** @} */

/* macros for field wait_ongoing_thld */
/**
 * @defgroup at_apb_qspi_regs_core_wait_ongoing_thld_field wait_ongoing_thld_field
 * @brief macros for field wait_ongoing_thld
 * @details threshold of wait for onging fetches
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__SHIFT                 24
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__WIDTH                  3
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__MASK         0x07000000U
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_THLD__RESET_VALUE  0x00000007U
/** @} */

/* macros for field wait_ongoing_fetch_en */
/**
 * @defgroup at_apb_qspi_regs_core_wait_ongoing_fetch_en_field wait_ongoing_fetch_en_field
 * @brief macros for field wait_ongoing_fetch_en
 * @details enable bit for wait for onging fetches
 * @{
 */
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__SHIFT             28
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__WIDTH              1
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__MASK     0x10000000U
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define QSPI_REMOTE_PREFETCH_SETUP__WAIT_ONGOING_FETCH_EN__RESET_VALUE \
                    0x00000001U
/** @} */
#define QSPI_REMOTE_PREFETCH_SETUP__TYPE                               uint32_t
#define QSPI_REMOTE_PREFETCH_SETUP__READ                            0x173f7ff7U
#define QSPI_REMOTE_PREFETCH_SETUP__WRITE                           0x173f7ff7U
#define QSPI_REMOTE_PREFETCH_SETUP__PRESERVED                       0x00000000U
#define QSPI_REMOTE_PREFETCH_SETUP__RESET_VALUE                     0x17000001U

#endif /* __QSPI_REMOTE_PREFETCH_SETUP_MACRO__ */

/** @} end of remote_prefetch_setup */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_cache_setup */
/**
 * @defgroup at_apb_qspi_regs_core_remote_cache_setup remote_cache_setup
 * @brief Contains register fields associated with remote_cache_setup. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_CACHE_SETUP_MACRO__
#define __QSPI_REMOTE_CACHE_SETUP_MACRO__

/* macros for field cacheable_low */
/**
 * @defgroup at_apb_qspi_regs_core_cacheable_low_field cacheable_low_field
 * @brief macros for field cacheable_low
 * @details lower limit of cacheable region (this is the 12 MSBs; the 12 LSBs are all 0s)
 * @{
 */
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__SHIFT                         0
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__WIDTH                        12
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__MASK                0x00000fffU
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000fffU)
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000fffU)
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((uint32_t)(src) &\
                    0x00000fffU)
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000fffU)))
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_LOW__RESET_VALUE         0x00000000U
/** @} */

/* macros for field cacheable_upper */
/**
 * @defgroup at_apb_qspi_regs_core_cacheable_upper_field cacheable_upper_field
 * @brief macros for field cacheable_upper
 * @details upper limit of cacheable region (this is the 12 MSBs; the 12 LSBs are all 1s)
 * @{
 */
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__SHIFT                      16
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__WIDTH                      12
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__MASK              0x0fff0000U
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fff0000U) >> 16)
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x0fff0000U)
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fff0000U) | (((uint32_t)(src) <<\
                    16) & 0x0fff0000U)
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x0fff0000U)))
#define QSPI_REMOTE_CACHE_SETUP__CACHEABLE_UPPER__RESET_VALUE       0x00000fffU
/** @} */

/* macros for field cache_on_write_en */
/**
 * @defgroup at_apb_qspi_regs_core_cache_on_write_en_field cache_on_write_en_field
 * @brief macros for field cache_on_write_en
 * @details enable bit of cache on write
 * @{
 */
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__SHIFT                    31
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__WIDTH                     1
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__MASK            0x80000000U
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define QSPI_REMOTE_CACHE_SETUP__CACHE_ON_WRITE_EN__RESET_VALUE     0x00000000U
/** @} */
#define QSPI_REMOTE_CACHE_SETUP__TYPE                                  uint32_t
#define QSPI_REMOTE_CACHE_SETUP__READ                               0x8fff0fffU
#define QSPI_REMOTE_CACHE_SETUP__WRITE                              0x8fff0fffU
#define QSPI_REMOTE_CACHE_SETUP__PRESERVED                          0x00000000U
#define QSPI_REMOTE_CACHE_SETUP__RESET_VALUE                        0x0fff0000U

#endif /* __QSPI_REMOTE_CACHE_SETUP_MACRO__ */

/** @} end of remote_cache_setup */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_status */
/**
 * @defgroup at_apb_qspi_regs_core_remote_status remote_status
 * @brief Contains register fields associated with remote_status. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_STATUS_MACRO__
#define __QSPI_REMOTE_STATUS_MACRO__

/* macros for field prefetch_busy */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_busy_field prefetch_busy_field
 * @brief macros for field prefetch_busy
 * @details prefetch busy
 * @{
 */
#define QSPI_REMOTE_STATUS__PREFETCH_BUSY__SHIFT                              0
#define QSPI_REMOTE_STATUS__PREFETCH_BUSY__WIDTH                              1
#define QSPI_REMOTE_STATUS__PREFETCH_BUSY__MASK                     0x00000001U
#define QSPI_REMOTE_STATUS__PREFETCH_BUSY__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_STATUS__PREFETCH_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QSPI_REMOTE_STATUS__PREFETCH_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QSPI_REMOTE_STATUS__PREFETCH_BUSY__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ahb_busy */
/**
 * @defgroup at_apb_qspi_regs_core_ahb_busy_field ahb_busy_field
 * @brief macros for field ahb_busy
 * @details an AHB transaction is ongoing (not idle or halted)
 * @{
 */
#define QSPI_REMOTE_STATUS__AHB_BUSY__SHIFT                                   1
#define QSPI_REMOTE_STATUS__AHB_BUSY__WIDTH                                   1
#define QSPI_REMOTE_STATUS__AHB_BUSY__MASK                          0x00000002U
#define QSPI_REMOTE_STATUS__AHB_BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define QSPI_REMOTE_STATUS__AHB_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define QSPI_REMOTE_STATUS__AHB_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define QSPI_REMOTE_STATUS__AHB_BUSY__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field read_busy */
/**
 * @defgroup at_apb_qspi_regs_core_read_busy_field read_busy_field
 * @brief macros for field read_busy
 * @details read busy (not idle or halted)
 * @{
 */
#define QSPI_REMOTE_STATUS__READ_BUSY__SHIFT                                  2
#define QSPI_REMOTE_STATUS__READ_BUSY__WIDTH                                  1
#define QSPI_REMOTE_STATUS__READ_BUSY__MASK                         0x00000004U
#define QSPI_REMOTE_STATUS__READ_BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define QSPI_REMOTE_STATUS__READ_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define QSPI_REMOTE_STATUS__READ_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define QSPI_REMOTE_STATUS__READ_BUSY__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field se_busy */
/**
 * @defgroup at_apb_qspi_regs_core_se_busy_field se_busy_field
 * @brief macros for field se_busy
 * @details SE busy (not idle or halted)
 * @{
 */
#define QSPI_REMOTE_STATUS__SE_BUSY__SHIFT                                    3
#define QSPI_REMOTE_STATUS__SE_BUSY__WIDTH                                    1
#define QSPI_REMOTE_STATUS__SE_BUSY__MASK                           0x00000008U
#define QSPI_REMOTE_STATUS__SE_BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define QSPI_REMOTE_STATUS__SE_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define QSPI_REMOTE_STATUS__SE_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define QSPI_REMOTE_STATUS__SE_BUSY__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field wr_busy */
/**
 * @defgroup at_apb_qspi_regs_core_wr_busy_field wr_busy_field
 * @brief macros for field wr_busy
 * @details PP busy (not idle or halted)
 * @{
 */
#define QSPI_REMOTE_STATUS__WR_BUSY__SHIFT                                    4
#define QSPI_REMOTE_STATUS__WR_BUSY__WIDTH                                    1
#define QSPI_REMOTE_STATUS__WR_BUSY__MASK                           0x00000010U
#define QSPI_REMOTE_STATUS__WR_BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define QSPI_REMOTE_STATUS__WR_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define QSPI_REMOTE_STATUS__WR_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define QSPI_REMOTE_STATUS__WR_BUSY__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field read_fsm_state */
/**
 * @defgroup at_apb_qspi_regs_core_read_fsm_state_field read_fsm_state_field
 * @brief macros for field read_fsm_state
 * @details read erase fsm status
 * @{
 */
#define QSPI_REMOTE_STATUS__READ_FSM_STATE__SHIFT                             8
#define QSPI_REMOTE_STATUS__READ_FSM_STATE__WIDTH                             4
#define QSPI_REMOTE_STATUS__READ_FSM_STATE__MASK                    0x00000f00U
#define QSPI_REMOTE_STATUS__READ_FSM_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define QSPI_REMOTE_STATUS__READ_FSM_STATE__RESET_VALUE             0x00000000U
/** @} */

/* macros for field se_fsm_state */
/**
 * @defgroup at_apb_qspi_regs_core_se_fsm_state_field se_fsm_state_field
 * @brief macros for field se_fsm_state
 * @details sector erase fsm status
 * @{
 */
#define QSPI_REMOTE_STATUS__SE_FSM_STATE__SHIFT                              16
#define QSPI_REMOTE_STATUS__SE_FSM_STATE__WIDTH                               5
#define QSPI_REMOTE_STATUS__SE_FSM_STATE__MASK                      0x001f0000U
#define QSPI_REMOTE_STATUS__SE_FSM_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define QSPI_REMOTE_STATUS__SE_FSM_STATE__RESET_VALUE               0x00000000U
/** @} */

/* macros for field wr_fsm_state */
/**
 * @defgroup at_apb_qspi_regs_core_wr_fsm_state_field wr_fsm_state_field
 * @brief macros for field wr_fsm_state
 * @details write (page program) fsm status
 * @{
 */
#define QSPI_REMOTE_STATUS__WR_FSM_STATE__SHIFT                              24
#define QSPI_REMOTE_STATUS__WR_FSM_STATE__WIDTH                               5
#define QSPI_REMOTE_STATUS__WR_FSM_STATE__MASK                      0x1f000000U
#define QSPI_REMOTE_STATUS__WR_FSM_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1f000000U) >> 24)
#define QSPI_REMOTE_STATUS__WR_FSM_STATE__RESET_VALUE               0x00000000U
/** @} */
#define QSPI_REMOTE_STATUS__TYPE                                       uint32_t
#define QSPI_REMOTE_STATUS__READ                                    0x1f1f0f1fU
#define QSPI_REMOTE_STATUS__PRESERVED                               0x00000000U
#define QSPI_REMOTE_STATUS__RESET_VALUE                             0x00000000U

#endif /* __QSPI_REMOTE_STATUS_MACRO__ */

/** @} end of remote_status */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_prefetch_status */
/**
 * @defgroup at_apb_qspi_regs_core_remote_prefetch_status remote_prefetch_status
 * @brief Contains register fields associated with remote_prefetch_status. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_PREFETCH_STATUS_MACRO__
#define __QSPI_REMOTE_PREFETCH_STATUS_MACRO__

/* macros for field prefetch_busy */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_busy_field prefetch_busy_field
 * @brief macros for field prefetch_busy
 * @details prefetch busy
 * @{
 */
#define QSPI_REMOTE_PREFETCH_STATUS__PREFETCH_BUSY__SHIFT                     0
#define QSPI_REMOTE_PREFETCH_STATUS__PREFETCH_BUSY__WIDTH                     1
#define QSPI_REMOTE_PREFETCH_STATUS__PREFETCH_BUSY__MASK            0x00000001U
#define QSPI_REMOTE_PREFETCH_STATUS__PREFETCH_BUSY__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_PREFETCH_STATUS__PREFETCH_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QSPI_REMOTE_PREFETCH_STATUS__PREFETCH_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QSPI_REMOTE_PREFETCH_STATUS__PREFETCH_BUSY__RESET_VALUE     0x00000000U
/** @} */
#define QSPI_REMOTE_PREFETCH_STATUS__TYPE                              uint32_t
#define QSPI_REMOTE_PREFETCH_STATUS__READ                           0x00000001U
#define QSPI_REMOTE_PREFETCH_STATUS__PRESERVED                      0x00000000U
#define QSPI_REMOTE_PREFETCH_STATUS__RESET_VALUE                    0x00000000U

#endif /* __QSPI_REMOTE_PREFETCH_STATUS_MACRO__ */

/** @} end of remote_prefetch_status */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_wle_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_wle_cnt remote_ahb_wle_cnt
 * @brief Contains register fields associated with remote_ahb_wle_cnt. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_WLE_CNT_MACRO__
#define __QSPI_REMOTE_AHB_WLE_CNT_MACRO__

/* macros for field wle_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_wle_cnt_field wle_cnt_field
 * @brief macros for field wle_cnt
 * @details number of wle checks before it is true.
 * @{
 */
#define QSPI_REMOTE_AHB_WLE_CNT__WLE_CNT__SHIFT                               0
#define QSPI_REMOTE_AHB_WLE_CNT__WLE_CNT__WIDTH                              10
#define QSPI_REMOTE_AHB_WLE_CNT__WLE_CNT__MASK                      0x000003ffU
#define QSPI_REMOTE_AHB_WLE_CNT__WLE_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define QSPI_REMOTE_AHB_WLE_CNT__WLE_CNT__RESET_VALUE               0x00000000U
/** @} */

/* macros for field intrp_status */
/**
 * @defgroup at_apb_qspi_regs_core_intrp_status_field intrp_status_field
 * @brief macros for field intrp_status
 * @details nonmaskable
 * @{
 */
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP_STATUS__SHIFT                         10
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP_STATUS__WIDTH                          1
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP_STATUS__MASK                 0x00000400U
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP_STATUS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP_STATUS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP_STATUS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP_STATUS__RESET_VALUE          0x00000000U
/** @} */

/* macros for field intrp */
/**
 * @defgroup at_apb_qspi_regs_core_intrp_field intrp_field
 * @brief macros for field intrp
 * @details maskable by mask_intrup
 * @{
 */
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP__SHIFT                                11
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP__WIDTH                                 1
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP__MASK                        0x00000800U
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define QSPI_REMOTE_AHB_WLE_CNT__INTRP__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field wel_to */
/**
 * @defgroup at_apb_qspi_regs_core_wel_to_field wel_to_field
 * @brief macros for field wel_to
 * @details wait for wel=1 times out (cleared when intrp is cleared)
 * @{
 */
#define QSPI_REMOTE_AHB_WLE_CNT__WEL_TO__SHIFT                               12
#define QSPI_REMOTE_AHB_WLE_CNT__WEL_TO__WIDTH                                1
#define QSPI_REMOTE_AHB_WLE_CNT__WEL_TO__MASK                       0x00001000U
#define QSPI_REMOTE_AHB_WLE_CNT__WEL_TO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define QSPI_REMOTE_AHB_WLE_CNT__WEL_TO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define QSPI_REMOTE_AHB_WLE_CNT__WEL_TO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define QSPI_REMOTE_AHB_WLE_CNT__WEL_TO__RESET_VALUE                0x00000000U
/** @} */

/* macros for field wip_to */
/**
 * @defgroup at_apb_qspi_regs_core_wip_to_field wip_to_field
 * @brief macros for field wip_to
 * @details wait for wip=0 times out (cleared when intrp is cleared)
 * @{
 */
#define QSPI_REMOTE_AHB_WLE_CNT__WIP_TO__SHIFT                               13
#define QSPI_REMOTE_AHB_WLE_CNT__WIP_TO__WIDTH                                1
#define QSPI_REMOTE_AHB_WLE_CNT__WIP_TO__MASK                       0x00002000U
#define QSPI_REMOTE_AHB_WLE_CNT__WIP_TO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define QSPI_REMOTE_AHB_WLE_CNT__WIP_TO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define QSPI_REMOTE_AHB_WLE_CNT__WIP_TO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define QSPI_REMOTE_AHB_WLE_CNT__WIP_TO__RESET_VALUE                0x00000000U
/** @} */
#define QSPI_REMOTE_AHB_WLE_CNT__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_WLE_CNT__READ                               0x00003fffU
#define QSPI_REMOTE_AHB_WLE_CNT__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_WLE_CNT__RESET_VALUE                        0x00000000U

#endif /* __QSPI_REMOTE_AHB_WLE_CNT_MACRO__ */

/** @} end of remote_ahb_wle_cnt */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_ahb_wip_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_remote_ahb_wip_cnt remote_ahb_wip_cnt
 * @brief Contains register fields associated with remote_ahb_wip_cnt. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_AHB_WIP_CNT_MACRO__
#define __QSPI_REMOTE_AHB_WIP_CNT_MACRO__

/* macros for field wip_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_wip_cnt_field wip_cnt_field
 * @brief macros for field wip_cnt
 * @details number of wip checks before it is over.
 * @{
 */
#define QSPI_REMOTE_AHB_WIP_CNT__WIP_CNT__SHIFT                               0
#define QSPI_REMOTE_AHB_WIP_CNT__WIP_CNT__WIDTH                              10
#define QSPI_REMOTE_AHB_WIP_CNT__WIP_CNT__MASK                      0x000003ffU
#define QSPI_REMOTE_AHB_WIP_CNT__WIP_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define QSPI_REMOTE_AHB_WIP_CNT__WIP_CNT__RESET_VALUE               0x00000000U
/** @} */
#define QSPI_REMOTE_AHB_WIP_CNT__TYPE                                  uint32_t
#define QSPI_REMOTE_AHB_WIP_CNT__READ                               0x000003ffU
#define QSPI_REMOTE_AHB_WIP_CNT__PRESERVED                          0x00000000U
#define QSPI_REMOTE_AHB_WIP_CNT__RESET_VALUE                        0x00000000U

#endif /* __QSPI_REMOTE_AHB_WIP_CNT_MACRO__ */

/** @} end of remote_ahb_wip_cnt */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_sts_ctrl0 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_sts_ctrl0 remote_sts_ctrl0
 * @brief Contains register fields associated with remote_sts_ctrl0. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_STS_CTRL0_MACRO__
#define __QSPI_REMOTE_STS_CTRL0_MACRO__

/* macros for field prefetch_sts_enable */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_enable_field prefetch_sts_enable_field
 * @brief macros for field prefetch_sts_enable
 * @details enable prefetch statistics counters
 * @{
 */
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__SHIFT                     0
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__WIDTH                     1
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__MASK            0x00000001U
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QSPI_REMOTE_STS_CTRL0__PREFETCH_STS_ENABLE__RESET_VALUE     0x00000000U
/** @} */

/* macros for field cache_sts_enable */
/**
 * @defgroup at_apb_qspi_regs_core_cache_sts_enable_field cache_sts_enable_field
 * @brief macros for field cache_sts_enable
 * @details enable cache statistics counters
 * @{
 */
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__SHIFT                        1
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__WIDTH                        1
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__MASK               0x00000002U
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define QSPI_REMOTE_STS_CTRL0__CACHE_STS_ENABLE__RESET_VALUE        0x00000000U
/** @} */
#define QSPI_REMOTE_STS_CTRL0__TYPE                                    uint32_t
#define QSPI_REMOTE_STS_CTRL0__READ                                 0x00000003U
#define QSPI_REMOTE_STS_CTRL0__WRITE                                0x00000003U
#define QSPI_REMOTE_STS_CTRL0__PRESERVED                            0x00000000U
#define QSPI_REMOTE_STS_CTRL0__RESET_VALUE                          0x00000000U

#endif /* __QSPI_REMOTE_STS_CTRL0_MACRO__ */

/** @} end of remote_sts_ctrl0 */

/* macros for BlueprintGlobalNameSpace::QSPI_remote_sts_ctrl1 */
/**
 * @defgroup at_apb_qspi_regs_core_remote_sts_ctrl1 remote_sts_ctrl1
 * @brief Contains register fields associated with remote_sts_ctrl1. definitions.
 * @{
 */
#ifndef __QSPI_REMOTE_STS_CTRL1_MACRO__
#define __QSPI_REMOTE_STS_CTRL1_MACRO__

/* macros for field prefetch_sts_clear */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_clear_field prefetch_sts_clear_field
 * @brief macros for field prefetch_sts_clear
 * @details clear all prefetch statistics counters (__SELF_CLEARING__)
 * @{
 */
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__SHIFT                      0
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__WIDTH                      1
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__MASK             0x00000001U
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define QSPI_REMOTE_STS_CTRL1__PREFETCH_STS_CLEAR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field cache_sts_clear */
/**
 * @defgroup at_apb_qspi_regs_core_cache_sts_clear_field cache_sts_clear_field
 * @brief macros for field cache_sts_clear
 * @details clear all cache statistics counters (__SELF_CLEARING__)
 * @{
 */
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__SHIFT                         1
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__WIDTH                         1
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__MASK                0x00000002U
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define QSPI_REMOTE_STS_CTRL1__CACHE_STS_CLEAR__RESET_VALUE         0x00000000U
/** @} */
#define QSPI_REMOTE_STS_CTRL1__TYPE                                    uint32_t
#define QSPI_REMOTE_STS_CTRL1__READ                                 0x00000003U
#define QSPI_REMOTE_STS_CTRL1__WRITE                                0x00000003U
#define QSPI_REMOTE_STS_CTRL1__PRESERVED                            0x00000000U
#define QSPI_REMOTE_STS_CTRL1__RESET_VALUE                          0x00000000U

#endif /* __QSPI_REMOTE_STS_CTRL1_MACRO__ */

/** @} end of remote_sts_ctrl1 */

/* macros for BlueprintGlobalNameSpace::QSPI_prefetch_sts_cnt0 */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_cnt0 prefetch_sts_cnt0
 * @brief Contains register fields associated with prefetch_sts_cnt0. definitions.
 * @{
 */
#ifndef __QSPI_PREFETCH_STS_CNT0_MACRO__
#define __QSPI_PREFETCH_STS_CNT0_MACRO__

/* macros for field prefetch_event_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_event_cnt_field prefetch_event_cnt_field
 * @brief macros for field prefetch_event_cnt
 * @details number of prefetch event
 * @{
 */
#define QSPI_PREFETCH_STS_CNT0__PREFETCH_EVENT_CNT__SHIFT                     0
#define QSPI_PREFETCH_STS_CNT0__PREFETCH_EVENT_CNT__WIDTH                    24
#define QSPI_PREFETCH_STS_CNT0__PREFETCH_EVENT_CNT__MASK            0x00ffffffU
#define QSPI_PREFETCH_STS_CNT0__PREFETCH_EVENT_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_PREFETCH_STS_CNT0__PREFETCH_EVENT_CNT__RESET_VALUE     0x00000000U
/** @} */
#define QSPI_PREFETCH_STS_CNT0__TYPE                                   uint32_t
#define QSPI_PREFETCH_STS_CNT0__READ                                0x00ffffffU
#define QSPI_PREFETCH_STS_CNT0__PRESERVED                           0x00000000U
#define QSPI_PREFETCH_STS_CNT0__RESET_VALUE                         0x00000000U

#endif /* __QSPI_PREFETCH_STS_CNT0_MACRO__ */

/** @} end of prefetch_sts_cnt0 */

/* macros for BlueprintGlobalNameSpace::QSPI_prefetch_sts_cnt1 */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_cnt1 prefetch_sts_cnt1
 * @brief Contains register fields associated with prefetch_sts_cnt1. definitions.
 * @{
 */
#ifndef __QSPI_PREFETCH_STS_CNT1_MACRO__
#define __QSPI_PREFETCH_STS_CNT1_MACRO__

/* macros for field prefetch_hit_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_hit_cnt_field prefetch_hit_cnt_field
 * @brief macros for field prefetch_hit_cnt
 * @details number of words hit in prefetch
 * @{
 */
#define QSPI_PREFETCH_STS_CNT1__PREFETCH_HIT_CNT__SHIFT                       0
#define QSPI_PREFETCH_STS_CNT1__PREFETCH_HIT_CNT__WIDTH                      24
#define QSPI_PREFETCH_STS_CNT1__PREFETCH_HIT_CNT__MASK              0x00ffffffU
#define QSPI_PREFETCH_STS_CNT1__PREFETCH_HIT_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_PREFETCH_STS_CNT1__PREFETCH_HIT_CNT__RESET_VALUE       0x00000000U
/** @} */
#define QSPI_PREFETCH_STS_CNT1__TYPE                                   uint32_t
#define QSPI_PREFETCH_STS_CNT1__READ                                0x00ffffffU
#define QSPI_PREFETCH_STS_CNT1__PRESERVED                           0x00000000U
#define QSPI_PREFETCH_STS_CNT1__RESET_VALUE                         0x00000000U

#endif /* __QSPI_PREFETCH_STS_CNT1_MACRO__ */

/** @} end of prefetch_sts_cnt1 */

/* macros for BlueprintGlobalNameSpace::QSPI_prefetch_sts_cnt2 */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_cnt2 prefetch_sts_cnt2
 * @brief Contains register fields associated with prefetch_sts_cnt2. definitions.
 * @{
 */
#ifndef __QSPI_PREFETCH_STS_CNT2_MACRO__
#define __QSPI_PREFETCH_STS_CNT2_MACRO__

/* macros for field prefetch_flush_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_flush_cnt_field prefetch_flush_cnt_field
 * @brief macros for field prefetch_flush_cnt
 * @details number of flushes
 * @{
 */
#define QSPI_PREFETCH_STS_CNT2__PREFETCH_FLUSH_CNT__SHIFT                     0
#define QSPI_PREFETCH_STS_CNT2__PREFETCH_FLUSH_CNT__WIDTH                    24
#define QSPI_PREFETCH_STS_CNT2__PREFETCH_FLUSH_CNT__MASK            0x00ffffffU
#define QSPI_PREFETCH_STS_CNT2__PREFETCH_FLUSH_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_PREFETCH_STS_CNT2__PREFETCH_FLUSH_CNT__RESET_VALUE     0x00000000U
/** @} */
#define QSPI_PREFETCH_STS_CNT2__TYPE                                   uint32_t
#define QSPI_PREFETCH_STS_CNT2__READ                                0x00ffffffU
#define QSPI_PREFETCH_STS_CNT2__PRESERVED                           0x00000000U
#define QSPI_PREFETCH_STS_CNT2__RESET_VALUE                         0x00000000U

#endif /* __QSPI_PREFETCH_STS_CNT2_MACRO__ */

/** @} end of prefetch_sts_cnt2 */

/* macros for BlueprintGlobalNameSpace::QSPI_prefetch_sts_cnt3 */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_cnt3 prefetch_sts_cnt3
 * @brief Contains register fields associated with prefetch_sts_cnt3. definitions.
 * @{
 */
#ifndef __QSPI_PREFETCH_STS_CNT3_MACRO__
#define __QSPI_PREFETCH_STS_CNT3_MACRO__

/* macros for field prefetch_flush_wrd_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_flush_wrd_cnt_field prefetch_flush_wrd_cnt_field
 * @brief macros for field prefetch_flush_wrd_cnt
 * @details number of words being flushed
 * @{
 */
#define QSPI_PREFETCH_STS_CNT3__PREFETCH_FLUSH_WRD_CNT__SHIFT                 0
#define QSPI_PREFETCH_STS_CNT3__PREFETCH_FLUSH_WRD_CNT__WIDTH                24
#define QSPI_PREFETCH_STS_CNT3__PREFETCH_FLUSH_WRD_CNT__MASK        0x00ffffffU
#define QSPI_PREFETCH_STS_CNT3__PREFETCH_FLUSH_WRD_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_PREFETCH_STS_CNT3__PREFETCH_FLUSH_WRD_CNT__RESET_VALUE 0x00000000U
/** @} */
#define QSPI_PREFETCH_STS_CNT3__TYPE                                   uint32_t
#define QSPI_PREFETCH_STS_CNT3__READ                                0x00ffffffU
#define QSPI_PREFETCH_STS_CNT3__PRESERVED                           0x00000000U
#define QSPI_PREFETCH_STS_CNT3__RESET_VALUE                         0x00000000U

#endif /* __QSPI_PREFETCH_STS_CNT3_MACRO__ */

/** @} end of prefetch_sts_cnt3 */

/* macros for BlueprintGlobalNameSpace::QSPI_prefetch_sts_cnt4 */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_cnt4 prefetch_sts_cnt4
 * @brief Contains register fields associated with prefetch_sts_cnt4. definitions.
 * @{
 */
#ifndef __QSPI_PREFETCH_STS_CNT4_MACRO__
#define __QSPI_PREFETCH_STS_CNT4_MACRO__

/* macros for field prefetch_word_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_word_cnt_field prefetch_word_cnt_field
 * @brief macros for field prefetch_word_cnt
 * @details number of prefetched words
 * @{
 */
#define QSPI_PREFETCH_STS_CNT4__PREFETCH_WORD_CNT__SHIFT                      0
#define QSPI_PREFETCH_STS_CNT4__PREFETCH_WORD_CNT__WIDTH                     24
#define QSPI_PREFETCH_STS_CNT4__PREFETCH_WORD_CNT__MASK             0x00ffffffU
#define QSPI_PREFETCH_STS_CNT4__PREFETCH_WORD_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_PREFETCH_STS_CNT4__PREFETCH_WORD_CNT__RESET_VALUE      0x00000000U
/** @} */
#define QSPI_PREFETCH_STS_CNT4__TYPE                                   uint32_t
#define QSPI_PREFETCH_STS_CNT4__READ                                0x00ffffffU
#define QSPI_PREFETCH_STS_CNT4__PRESERVED                           0x00000000U
#define QSPI_PREFETCH_STS_CNT4__RESET_VALUE                         0x00000000U

#endif /* __QSPI_PREFETCH_STS_CNT4_MACRO__ */

/** @} end of prefetch_sts_cnt4 */

/* macros for BlueprintGlobalNameSpace::QSPI_prefetch_sts_cnt5 */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_sts_cnt5 prefetch_sts_cnt5
 * @brief Contains register fields associated with prefetch_sts_cnt5. definitions.
 * @{
 */
#ifndef __QSPI_PREFETCH_STS_CNT5_MACRO__
#define __QSPI_PREFETCH_STS_CNT5_MACRO__

/* macros for field prefetch_f2nf_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_prefetch_f2nf_cnt_field prefetch_f2nf_cnt_field
 * @brief macros for field prefetch_f2nf_cnt
 * @details number of full to non-full (trigger prefetch internally)
 * @{
 */
#define QSPI_PREFETCH_STS_CNT5__PREFETCH_F2NF_CNT__SHIFT                      0
#define QSPI_PREFETCH_STS_CNT5__PREFETCH_F2NF_CNT__WIDTH                     24
#define QSPI_PREFETCH_STS_CNT5__PREFETCH_F2NF_CNT__MASK             0x00ffffffU
#define QSPI_PREFETCH_STS_CNT5__PREFETCH_F2NF_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_PREFETCH_STS_CNT5__PREFETCH_F2NF_CNT__RESET_VALUE      0x00000000U
/** @} */
#define QSPI_PREFETCH_STS_CNT5__TYPE                                   uint32_t
#define QSPI_PREFETCH_STS_CNT5__READ                                0x00ffffffU
#define QSPI_PREFETCH_STS_CNT5__PRESERVED                           0x00000000U
#define QSPI_PREFETCH_STS_CNT5__RESET_VALUE                         0x00000000U

#endif /* __QSPI_PREFETCH_STS_CNT5_MACRO__ */

/** @} end of prefetch_sts_cnt5 */

/* macros for BlueprintGlobalNameSpace::QSPI_cache_sts_cnt0 */
/**
 * @defgroup at_apb_qspi_regs_core_cache_sts_cnt0 cache_sts_cnt0
 * @brief Contains register fields associated with cache_sts_cnt0. definitions.
 * @{
 */
#ifndef __QSPI_CACHE_STS_CNT0_MACRO__
#define __QSPI_CACHE_STS_CNT0_MACRO__

/* macros for field cache_req_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_cache_req_cnt_field cache_req_cnt_field
 * @brief macros for field cache_req_cnt
 * @details number of read requests seen by qspi cache
 * @{
 */
#define QSPI_CACHE_STS_CNT0__CACHE_REQ_CNT__SHIFT                             0
#define QSPI_CACHE_STS_CNT0__CACHE_REQ_CNT__WIDTH                            24
#define QSPI_CACHE_STS_CNT0__CACHE_REQ_CNT__MASK                    0x00ffffffU
#define QSPI_CACHE_STS_CNT0__CACHE_REQ_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_CACHE_STS_CNT0__CACHE_REQ_CNT__RESET_VALUE             0x00000000U
/** @} */
#define QSPI_CACHE_STS_CNT0__TYPE                                      uint32_t
#define QSPI_CACHE_STS_CNT0__READ                                   0x00ffffffU
#define QSPI_CACHE_STS_CNT0__PRESERVED                              0x00000000U
#define QSPI_CACHE_STS_CNT0__RESET_VALUE                            0x00000000U

#endif /* __QSPI_CACHE_STS_CNT0_MACRO__ */

/** @} end of cache_sts_cnt0 */

/* macros for BlueprintGlobalNameSpace::QSPI_cache_sts_cnt1 */
/**
 * @defgroup at_apb_qspi_regs_core_cache_sts_cnt1 cache_sts_cnt1
 * @brief Contains register fields associated with cache_sts_cnt1. definitions.
 * @{
 */
#ifndef __QSPI_CACHE_STS_CNT1_MACRO__
#define __QSPI_CACHE_STS_CNT1_MACRO__

/* macros for field cache_hit_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_cache_hit_cnt_field cache_hit_cnt_field
 * @brief macros for field cache_hit_cnt
 * @details number of hits in cache
 * @{
 */
#define QSPI_CACHE_STS_CNT1__CACHE_HIT_CNT__SHIFT                             0
#define QSPI_CACHE_STS_CNT1__CACHE_HIT_CNT__WIDTH                            24
#define QSPI_CACHE_STS_CNT1__CACHE_HIT_CNT__MASK                    0x00ffffffU
#define QSPI_CACHE_STS_CNT1__CACHE_HIT_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define QSPI_CACHE_STS_CNT1__CACHE_HIT_CNT__RESET_VALUE             0x00000000U
/** @} */
#define QSPI_CACHE_STS_CNT1__TYPE                                      uint32_t
#define QSPI_CACHE_STS_CNT1__READ                                   0x00ffffffU
#define QSPI_CACHE_STS_CNT1__PRESERVED                              0x00000000U
#define QSPI_CACHE_STS_CNT1__RESET_VALUE                            0x00000000U

#endif /* __QSPI_CACHE_STS_CNT1_MACRO__ */

/** @} end of cache_sts_cnt1 */

/* macros for BlueprintGlobalNameSpace::QSPI_burst_pp_ctrl */
/**
 * @defgroup at_apb_qspi_regs_core_burst_pp_ctrl burst_pp_ctrl
 * @brief Contains register fields associated with burst_pp_ctrl. definitions.
 * @{
 */
#ifndef __QSPI_BURST_PP_CTRL_MACRO__
#define __QSPI_BURST_PP_CTRL_MACRO__

/* macros for field byte_cnt */
/**
 * @defgroup at_apb_qspi_regs_core_byte_cnt_field byte_cnt_field
 * @brief macros for field byte_cnt
 * @details number of words to be written to the flash
 * @{
 */
#define QSPI_BURST_PP_CTRL__BYTE_CNT__SHIFT                                   0
#define QSPI_BURST_PP_CTRL__BYTE_CNT__WIDTH                                   8
#define QSPI_BURST_PP_CTRL__BYTE_CNT__MASK                          0x000000ffU
#define QSPI_BURST_PP_CTRL__BYTE_CNT__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define QSPI_BURST_PP_CTRL__BYTE_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define QSPI_BURST_PP_CTRL__BYTE_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define QSPI_BURST_PP_CTRL__BYTE_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define QSPI_BURST_PP_CTRL__BYTE_CNT__RESET_VALUE                   0x00000000U
/** @} */
#define QSPI_BURST_PP_CTRL__TYPE                                       uint32_t
#define QSPI_BURST_PP_CTRL__READ                                    0x000000ffU
#define QSPI_BURST_PP_CTRL__WRITE                                   0x000000ffU
#define QSPI_BURST_PP_CTRL__PRESERVED                               0x00000000U
#define QSPI_BURST_PP_CTRL__RESET_VALUE                             0x00000000U

#endif /* __QSPI_BURST_PP_CTRL_MACRO__ */

/** @} end of burst_pp_ctrl */

/* macros for BlueprintGlobalNameSpace::QSPI_core_id */
/**
 * @defgroup at_apb_qspi_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __QSPI_CORE_ID_MACRO__
#define __QSPI_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_qspi_regs_core_id_field id_field
 * @brief macros for field id
 * @details QSPI in ASCII
 * @{
 */
#define QSPI_CORE_ID__ID__SHIFT                                               0
#define QSPI_CORE_ID__ID__WIDTH                                              32
#define QSPI_CORE_ID__ID__MASK                                      0xffffffffU
#define QSPI_CORE_ID__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define QSPI_CORE_ID__ID__RESET_VALUE                               0x51535049U
/** @} */
#define QSPI_CORE_ID__TYPE                                             uint32_t
#define QSPI_CORE_ID__READ                                          0xffffffffU
#define QSPI_CORE_ID__PRESERVED                                     0x00000000U
#define QSPI_CORE_ID__RESET_VALUE                                   0x51535049U

#endif /* __QSPI_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::QSPI_rev_hash */
/**
 * @defgroup at_apb_qspi_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __QSPI_REV_HASH_MACRO__
#define __QSPI_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_qspi_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define QSPI_REV_HASH__ID__SHIFT                                              0
#define QSPI_REV_HASH__ID__WIDTH                                             32
#define QSPI_REV_HASH__ID__MASK                                     0xffffffffU
#define QSPI_REV_HASH__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define QSPI_REV_HASH__ID__RESET_VALUE                              0x66668f76U
/** @} */
#define QSPI_REV_HASH__TYPE                                            uint32_t
#define QSPI_REV_HASH__READ                                         0xffffffffU
#define QSPI_REV_HASH__PRESERVED                                    0x00000000U
#define QSPI_REV_HASH__RESET_VALUE                                  0x66668f76U

#endif /* __QSPI_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::QSPI_rev_key */
/**
 * @defgroup at_apb_qspi_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __QSPI_REV_KEY_MACRO__
#define __QSPI_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_qspi_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define QSPI_REV_KEY__ID__SHIFT                                               0
#define QSPI_REV_KEY__ID__WIDTH                                              32
#define QSPI_REV_KEY__ID__MASK                                      0xffffffffU
#define QSPI_REV_KEY__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define QSPI_REV_KEY__ID__RESET_VALUE                               0x52455620U
/** @} */
#define QSPI_REV_KEY__TYPE                                             uint32_t
#define QSPI_REV_KEY__READ                                          0xffffffffU
#define QSPI_REV_KEY__PRESERVED                                     0x00000000U
#define QSPI_REV_KEY__RESET_VALUE                                   0x52455620U

#endif /* __QSPI_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_QSPI_REGS_CORE */
#endif /* __REG_AT_APB_QSPI_REGS_CORE_H__ */
