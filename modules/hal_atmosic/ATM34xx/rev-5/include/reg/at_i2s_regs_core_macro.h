/*                                                                           */
/* File:       at_i2s_regs_core_macro.h                                      */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_i2s_regs_core.rdl               */
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


#ifndef __REG_AT_I2S_REGS_CORE_H__
#define __REG_AT_I2S_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_I2S_REGS_CORE at_i2s_regs_core
 * @ingroup AT_REG
 * @brief at_i2s_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl0 */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl0 i2s_ctrl0
 * @brief Contains register fields associated with i2s_ctrl0. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL0_MACRO__
#define __ATI2S_I2S_CTRL0_MACRO__

/* macros for field sck_nedge_ws_rx */
/**
 * @defgroup at_i2s_regs_core_sck_nedge_ws_rx_field sck_nedge_ws_rx_field
 * @brief macros for field sck_nedge_ws_rx
 * @details 1 = drive/latch rx ws on negative edge of sck, 0 = drive/latch rx ws on positive edge of sck
 * @{
 */
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__SHIFT                               0
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__WIDTH                               1
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__MASK                      0x00000001U
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_RX__RESET_VALUE               0x00000000U
/** @} */

/* macros for field sck_nedge_ws_tx */
/**
 * @defgroup at_i2s_regs_core_sck_nedge_ws_tx_field sck_nedge_ws_tx_field
 * @brief macros for field sck_nedge_ws_tx
 * @details 1 = drive/latch tx ws on negative edge of sck, 0 = drive/latch tx ws on positive edge of sck
 * @{
 */
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__SHIFT                               1
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__WIDTH                               1
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__MASK                      0x00000002U
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_WS_TX__RESET_VALUE               0x00000000U
/** @} */

/* macros for field src_snk_en */
/**
 * @defgroup at_i2s_regs_core_src_snk_en_field src_snk_en_field
 * @brief macros for field src_snk_en
 * @details Enable tranceiver tx or rx or both After it's enabled, first data valid assertion initiates tx and first ws deassertion initiates rx  0 = i2s disabled  1 = source serial data  2 = sink serial data  3 = source serial data and sink serial data
 * @{
 */
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__SHIFT                                    2
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__WIDTH                                    2
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__MASK                           0x0000000cU
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define ATI2S_I2S_CTRL0__SRC_SNK_EN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field src_snk */
/**
 * @defgroup at_i2s_regs_core_src_snk_field src_snk_field
 * @brief macros for field src_snk
 * @details 0 = pcm (pdm2pcm processed data is transmitted), 1 = ahb (data in memory 0 is transmitted or data is received and stored in memory 0), 2 = ahb (data in memory 1 is transmitted or data is received and stored in memory 1) this is mainly used for rx to tx loop back simulation and eimulation
 * @{
 */
#define ATI2S_I2S_CTRL0__SRC_SNK__SHIFT                                       4
#define ATI2S_I2S_CTRL0__SRC_SNK__WIDTH                                       2
#define ATI2S_I2S_CTRL0__SRC_SNK__MASK                              0x00000030U
#define ATI2S_I2S_CTRL0__SRC_SNK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define ATI2S_I2S_CTRL0__SRC_SNK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define ATI2S_I2S_CTRL0__SRC_SNK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define ATI2S_I2S_CTRL0__SRC_SNK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define ATI2S_I2S_CTRL0__SRC_SNK__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mstr_sckws_rx */
/**
 * @defgroup at_i2s_regs_core_mstr_sckws_rx_field mstr_sckws_rx_field
 * @brief macros for field mstr_sckws_rx
 * @details 0 = slave sck and ws, 1 = master sck and ws
 * @{
 */
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__SHIFT                                 6
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__WIDTH                                 1
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__MASK                        0x00000040U
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_RX__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field mstr_sckws_tx */
/**
 * @defgroup at_i2s_regs_core_mstr_sckws_tx_field mstr_sckws_tx_field
 * @brief macros for field mstr_sckws_tx
 * @details 0 = slave sck and ws, 1 = master sck and ws
 * @{
 */
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__SHIFT                                 7
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__WIDTH                                 1
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__MASK                        0x00000080U
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_CTRL0__MSTR_SCKWS_TX__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field src_cnt */
/**
 * @defgroup at_i2s_regs_core_src_cnt_field src_cnt_field
 * @brief macros for field src_cnt
 * @details number of sources for i2s
 * @{
 */
#define ATI2S_I2S_CTRL0__SRC_CNT__SHIFT                                       8
#define ATI2S_I2S_CTRL0__SRC_CNT__WIDTH                                       3
#define ATI2S_I2S_CTRL0__SRC_CNT__MASK                              0x00000700U
#define ATI2S_I2S_CTRL0__SRC_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define ATI2S_I2S_CTRL0__SRC_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define ATI2S_I2S_CTRL0__SRC_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define ATI2S_I2S_CTRL0__SRC_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define ATI2S_I2S_CTRL0__SRC_CNT__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field snk_cnt */
/**
 * @defgroup at_i2s_regs_core_snk_cnt_field snk_cnt_field
 * @brief macros for field snk_cnt
 * @details number of sinks for i2s
 * @{
 */
#define ATI2S_I2S_CTRL0__SNK_CNT__SHIFT                                      11
#define ATI2S_I2S_CTRL0__SNK_CNT__WIDTH                                       3
#define ATI2S_I2S_CTRL0__SNK_CNT__MASK                              0x00003800U
#define ATI2S_I2S_CTRL0__SNK_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define ATI2S_I2S_CTRL0__SNK_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define ATI2S_I2S_CTRL0__SNK_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define ATI2S_I2S_CTRL0__SNK_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define ATI2S_I2S_CTRL0__SNK_CNT__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field sck_init_cnt */
/**
 * @defgroup at_i2s_regs_core_sck_init_cnt_field sck_init_cnt_field
 * @brief macros for field sck_init_cnt
 * @details initial number of sck before going to transmit or receive state
 * @{
 */
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__SHIFT                                 16
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__WIDTH                                  8
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__MASK                         0x00ff0000U
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define ATI2S_I2S_CTRL0__SCK_INIT_CNT__RESET_VALUE                  0x00000010U
/** @} */

/* macros for field dma_en */
/**
 * @defgroup at_i2s_regs_core_dma_en_field dma_en_field
 * @brief macros for field dma_en
 * @details dma is enabled to access ping pong buffer
 * @{
 */
#define ATI2S_I2S_CTRL0__DMA_EN__SHIFT                                       24
#define ATI2S_I2S_CTRL0__DMA_EN__WIDTH                                        1
#define ATI2S_I2S_CTRL0__DMA_EN__MASK                               0x01000000U
#define ATI2S_I2S_CTRL0__DMA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define ATI2S_I2S_CTRL0__DMA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define ATI2S_I2S_CTRL0__DMA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define ATI2S_I2S_CTRL0__DMA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define ATI2S_I2S_CTRL0__DMA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define ATI2S_I2S_CTRL0__DMA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define ATI2S_I2S_CTRL0__DMA_EN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field ws_init_rx */
/**
 * @defgroup at_i2s_regs_core_ws_init_rx_field ws_init_rx_field
 * @brief macros for field ws_init_rx
 * @details 0 = word select is deasserted at the starting half of justieid mode 1 = word select is asserted at the starting half of justieid mode this applies to right or left justified mode, ws_init should be set to 1 for PCM mode
 * @{
 */
#define ATI2S_I2S_CTRL0__WS_INIT_RX__SHIFT                                   25
#define ATI2S_I2S_CTRL0__WS_INIT_RX__WIDTH                                    1
#define ATI2S_I2S_CTRL0__WS_INIT_RX__MASK                           0x02000000U
#define ATI2S_I2S_CTRL0__WS_INIT_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define ATI2S_I2S_CTRL0__WS_INIT_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define ATI2S_I2S_CTRL0__WS_INIT_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define ATI2S_I2S_CTRL0__WS_INIT_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define ATI2S_I2S_CTRL0__WS_INIT_RX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define ATI2S_I2S_CTRL0__WS_INIT_RX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define ATI2S_I2S_CTRL0__WS_INIT_RX__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field ws_init_tx */
/**
 * @defgroup at_i2s_regs_core_ws_init_tx_field ws_init_tx_field
 * @brief macros for field ws_init_tx
 * @details 0 = word select is deasserted at the starting half of justieid mode 1 = word select is asserted at the starting half of justieid mode this applies to right or left justified mode, ws_init should be set to 1 for PCM mode
 * @{
 */
#define ATI2S_I2S_CTRL0__WS_INIT_TX__SHIFT                                   26
#define ATI2S_I2S_CTRL0__WS_INIT_TX__WIDTH                                    1
#define ATI2S_I2S_CTRL0__WS_INIT_TX__MASK                           0x04000000U
#define ATI2S_I2S_CTRL0__WS_INIT_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define ATI2S_I2S_CTRL0__WS_INIT_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define ATI2S_I2S_CTRL0__WS_INIT_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define ATI2S_I2S_CTRL0__WS_INIT_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define ATI2S_I2S_CTRL0__WS_INIT_TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define ATI2S_I2S_CTRL0__WS_INIT_TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define ATI2S_I2S_CTRL0__WS_INIT_TX__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field sck_nedge_sd_rx */
/**
 * @defgroup at_i2s_regs_core_sck_nedge_sd_rx_field sck_nedge_sd_rx_field
 * @brief macros for field sck_nedge_sd_rx
 * @details 1 = drive/latch rx sd on negative edge of sck, 0 = drive/latch rx sd on positive edge of sck
 * @{
 */
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__SHIFT                              27
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__WIDTH                               1
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__MASK                      0x08000000U
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_RX__RESET_VALUE               0x00000000U
/** @} */

/* macros for field sck_nedge_sd_tx */
/**
 * @defgroup at_i2s_regs_core_sck_nedge_sd_tx_field sck_nedge_sd_tx_field
 * @brief macros for field sck_nedge_sd_tx
 * @details 1 = drive/latch tx sd on negative edge of sck, 0 = drive/latch tx sd on positive edge of sck
 * @{
 */
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__SHIFT                              28
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__WIDTH                               1
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__MASK                      0x10000000U
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define ATI2S_I2S_CTRL0__SCK_NEDGE_SD_TX__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ws_nedge_st_rx */
/**
 * @defgroup at_i2s_regs_core_ws_nedge_st_rx_field ws_nedge_st_rx_field
 * @brief macros for field ws_nedge_st_rx
 * @details 1 = rx starts on negative edge of ws
 * @{
 */
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__SHIFT                               29
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__WIDTH                                1
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__MASK                       0x20000000U
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_RX__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ws_nedge_st_tx */
/**
 * @defgroup at_i2s_regs_core_ws_nedge_st_tx_field ws_nedge_st_tx_field
 * @brief macros for field ws_nedge_st_tx
 * @details 1 = tx starts on negative edge of ws
 * @{
 */
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__SHIFT                               30
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__WIDTH                                1
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__MASK                       0x40000000U
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define ATI2S_I2S_CTRL0__WS_NEDGE_ST_TX__RESET_VALUE                0x00000000U
/** @} */
#define ATI2S_I2S_CTRL0__TYPE                                          uint32_t
#define ATI2S_I2S_CTRL0__READ                                       0x7fff3fffU
#define ATI2S_I2S_CTRL0__WRITE                                      0x7fff3fffU
#define ATI2S_I2S_CTRL0__PRESERVED                                  0x00000000U
#define ATI2S_I2S_CTRL0__RESET_VALUE                                0x06100900U

#endif /* __ATI2S_I2S_CTRL0_MACRO__ */

/** @} end of i2s_ctrl0 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl1_tx */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl1_tx i2s_ctrl1_tx
 * @brief Contains register fields associated with i2s_ctrl1_tx. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL1_TX_MACRO__
#define __ATI2S_I2S_CTRL1_TX_MACRO__

/* macros for field ck2sck_rt */
/**
 * @defgroup at_i2s_regs_core_ck2sck_rt_field ck2sck_rt_field
 * @brief macros for field ck2sck_rt
 * @details clock to serial clock ratio - number of clocks per serial clock period
 * @{
 */
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__SHIFT                                  0
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__WIDTH                                 16
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__MASK                         0x0000ffffU
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define ATI2S_I2S_CTRL1_TX__CK2SCK_RT__RESET_VALUE                  0x00000010U
/** @} */

/* macros for field sck2ws_rt */
/**
 * @defgroup at_i2s_regs_core_sck2ws_rt_field sck2ws_rt_field
 * @brief macros for field sck2ws_rt
 * @details serial clock to word select ratio - number of serial clock per word select period
 * @{
 */
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__SHIFT                                 16
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__WIDTH                                 16
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__MASK                         0xffff0000U
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define ATI2S_I2S_CTRL1_TX__SCK2WS_RT__RESET_VALUE                  0x00000020U
/** @} */
#define ATI2S_I2S_CTRL1_TX__TYPE                                       uint32_t
#define ATI2S_I2S_CTRL1_TX__READ                                    0xffffffffU
#define ATI2S_I2S_CTRL1_TX__WRITE                                   0xffffffffU
#define ATI2S_I2S_CTRL1_TX__PRESERVED                               0x00000000U
#define ATI2S_I2S_CTRL1_TX__RESET_VALUE                             0x00200010U

#endif /* __ATI2S_I2S_CTRL1_TX_MACRO__ */

/** @} end of i2s_ctrl1_tx */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl1_rx */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl1_rx i2s_ctrl1_rx
 * @brief Contains register fields associated with i2s_ctrl1_rx. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL1_RX_MACRO__
#define __ATI2S_I2S_CTRL1_RX_MACRO__

/* macros for field ck2sck_rt */
/**
 * @defgroup at_i2s_regs_core_ck2sck_rt_field ck2sck_rt_field
 * @brief macros for field ck2sck_rt
 * @details clock to serial clock ratio - number of clocks per serial clock period
 * @{
 */
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__SHIFT                                  0
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__WIDTH                                 16
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__MASK                         0x0000ffffU
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define ATI2S_I2S_CTRL1_RX__CK2SCK_RT__RESET_VALUE                  0x00000010U
/** @} */

/* macros for field sck2ws_rt */
/**
 * @defgroup at_i2s_regs_core_sck2ws_rt_field sck2ws_rt_field
 * @brief macros for field sck2ws_rt
 * @details serial clock to word select ratio - number of serial clock per word select period
 * @{
 */
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__SHIFT                                 16
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__WIDTH                                 16
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__MASK                         0xffff0000U
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define ATI2S_I2S_CTRL1_RX__SCK2WS_RT__RESET_VALUE                  0x00000020U
/** @} */
#define ATI2S_I2S_CTRL1_RX__TYPE                                       uint32_t
#define ATI2S_I2S_CTRL1_RX__READ                                    0xffffffffU
#define ATI2S_I2S_CTRL1_RX__WRITE                                   0xffffffffU
#define ATI2S_I2S_CTRL1_RX__PRESERVED                               0x00000000U
#define ATI2S_I2S_CTRL1_RX__RESET_VALUE                             0x00200010U

#endif /* __ATI2S_I2S_CTRL1_RX_MACRO__ */

/** @} end of i2s_ctrl1_rx */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl2_tx */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl2_tx i2s_ctrl2_tx
 * @brief Contains register fields associated with i2s_ctrl2_tx. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL2_TX_MACRO__
#define __ATI2S_I2S_CTRL2_TX_MACRO__

/* macros for field wssd_md */
/**
 * @defgroup at_i2s_regs_core_wssd_md_field wssd_md_field
 * @brief macros for field wssd_md
 * @details word select serial data mode - specify the behavior of word select and serial data 0 = PCM mode, 1 = left justfied I2S, 2 = right justified I2S
 * @{
 */
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__SHIFT                                    0
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__WIDTH                                    4
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__MASK                           0x0000000fU
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__READ(src)  ((uint32_t)(src) & 0x0000000fU)
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__WRITE(src) ((uint32_t)(src) & 0x0000000fU)
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define ATI2S_I2S_CTRL2_TX__WSSD_MD__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field sd_offst */
/**
 * @defgroup at_i2s_regs_core_sd_offst_field sd_offst_field
 * @brief macros for field sd_offst
 * @details number of cycles after word select edge to wait before driving serial data - valid range is [0:15]
 * @{
 */
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__SHIFT                                   4
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__WIDTH                                   4
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__MASK                          0x000000f0U
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define ATI2S_I2S_CTRL2_TX__SD_OFFST__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field sdw */
/**
 * @defgroup at_i2s_regs_core_sdw_field sdw_field
 * @brief macros for field sdw
 * @details width of valid serial data - additioanl bits in a word beyond the width are either padded for tx or discarded for rx valid range is [1:32]
 * @{
 */
#define ATI2S_I2S_CTRL2_TX__SDW__SHIFT                                        8
#define ATI2S_I2S_CTRL2_TX__SDW__WIDTH                                        6
#define ATI2S_I2S_CTRL2_TX__SDW__MASK                               0x00003f00U
#define ATI2S_I2S_CTRL2_TX__SDW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define ATI2S_I2S_CTRL2_TX__SDW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define ATI2S_I2S_CTRL2_TX__SDW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define ATI2S_I2S_CTRL2_TX__SDW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))
#define ATI2S_I2S_CTRL2_TX__SDW__RESET_VALUE                        0x00000010U
/** @} */

/* macros for field pb_cnt */
/**
 * @defgroup at_i2s_regs_core_pb_cnt_field pb_cnt_field
 * @brief macros for field pb_cnt
 * @details number of zero padding bits - used in right justified mode.
 * @{
 */
#define ATI2S_I2S_CTRL2_TX__PB_CNT__SHIFT                                    16
#define ATI2S_I2S_CTRL2_TX__PB_CNT__WIDTH                                     6
#define ATI2S_I2S_CTRL2_TX__PB_CNT__MASK                            0x003f0000U
#define ATI2S_I2S_CTRL2_TX__PB_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define ATI2S_I2S_CTRL2_TX__PB_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define ATI2S_I2S_CTRL2_TX__PB_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define ATI2S_I2S_CTRL2_TX__PB_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define ATI2S_I2S_CTRL2_TX__PB_CNT__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field vld_extd_cnt */
/**
 * @defgroup at_i2s_regs_core_vld_extd_cnt_field vld_extd_cnt_field
 * @brief macros for field vld_extd_cnt
 * @details cycle count to extend vld to ensure it is latched by slow backplane clock
 * @{
 */
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__SHIFT                              24
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__WIDTH                               8
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__MASK                      0xff000000U
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define ATI2S_I2S_CTRL2_TX__VLD_EXTD_CNT__RESET_VALUE               0x00000040U
/** @} */
#define ATI2S_I2S_CTRL2_TX__TYPE                                       uint32_t
#define ATI2S_I2S_CTRL2_TX__READ                                    0xff3f3fffU
#define ATI2S_I2S_CTRL2_TX__WRITE                                   0xff3f3fffU
#define ATI2S_I2S_CTRL2_TX__PRESERVED                               0x00000000U
#define ATI2S_I2S_CTRL2_TX__RESET_VALUE                             0x40001000U

#endif /* __ATI2S_I2S_CTRL2_TX_MACRO__ */

/** @} end of i2s_ctrl2_tx */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl2_rx */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl2_rx i2s_ctrl2_rx
 * @brief Contains register fields associated with i2s_ctrl2_rx. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL2_RX_MACRO__
#define __ATI2S_I2S_CTRL2_RX_MACRO__

/* macros for field wssd_md */
/**
 * @defgroup at_i2s_regs_core_wssd_md_field wssd_md_field
 * @brief macros for field wssd_md
 * @details word select serial data mode - specify the behavior of word select and serial data 0 = PCM mode, 1 = left justfied I2S, 2 = right justified I2S
 * @{
 */
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__SHIFT                                    0
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__WIDTH                                    4
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__MASK                           0x0000000fU
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__READ(src)  ((uint32_t)(src) & 0x0000000fU)
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__WRITE(src) ((uint32_t)(src) & 0x0000000fU)
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define ATI2S_I2S_CTRL2_RX__WSSD_MD__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field sd_offst */
/**
 * @defgroup at_i2s_regs_core_sd_offst_field sd_offst_field
 * @brief macros for field sd_offst
 * @details number of cycles after word select edge to wait before driving serial data - valid range is [0:15]
 * @{
 */
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__SHIFT                                   4
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__WIDTH                                   4
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__MASK                          0x000000f0U
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define ATI2S_I2S_CTRL2_RX__SD_OFFST__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field sdw */
/**
 * @defgroup at_i2s_regs_core_sdw_field sdw_field
 * @brief macros for field sdw
 * @details width of valid serial data - additioanl bits in a word beyond the width are either padded for tx or discarded for rx valid range is [1:32]
 * @{
 */
#define ATI2S_I2S_CTRL2_RX__SDW__SHIFT                                        8
#define ATI2S_I2S_CTRL2_RX__SDW__WIDTH                                        6
#define ATI2S_I2S_CTRL2_RX__SDW__MASK                               0x00003f00U
#define ATI2S_I2S_CTRL2_RX__SDW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define ATI2S_I2S_CTRL2_RX__SDW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define ATI2S_I2S_CTRL2_RX__SDW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define ATI2S_I2S_CTRL2_RX__SDW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))
#define ATI2S_I2S_CTRL2_RX__SDW__RESET_VALUE                        0x00000010U
/** @} */

/* macros for field pb_cnt */
/**
 * @defgroup at_i2s_regs_core_pb_cnt_field pb_cnt_field
 * @brief macros for field pb_cnt
 * @details number of zero padding bits - used in right justified mode.
 * @{
 */
#define ATI2S_I2S_CTRL2_RX__PB_CNT__SHIFT                                    16
#define ATI2S_I2S_CTRL2_RX__PB_CNT__WIDTH                                     6
#define ATI2S_I2S_CTRL2_RX__PB_CNT__MASK                            0x003f0000U
#define ATI2S_I2S_CTRL2_RX__PB_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define ATI2S_I2S_CTRL2_RX__PB_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define ATI2S_I2S_CTRL2_RX__PB_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define ATI2S_I2S_CTRL2_RX__PB_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define ATI2S_I2S_CTRL2_RX__PB_CNT__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field vld_extd_cnt */
/**
 * @defgroup at_i2s_regs_core_vld_extd_cnt_field vld_extd_cnt_field
 * @brief macros for field vld_extd_cnt
 * @details cycle count to extend vld to ensure it is latched by slow backplane clock
 * @{
 */
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__SHIFT                              24
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__WIDTH                               8
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__MASK                      0xff000000U
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define ATI2S_I2S_CTRL2_RX__VLD_EXTD_CNT__RESET_VALUE               0x00000040U
/** @} */
#define ATI2S_I2S_CTRL2_RX__TYPE                                       uint32_t
#define ATI2S_I2S_CTRL2_RX__READ                                    0xff3f3fffU
#define ATI2S_I2S_CTRL2_RX__WRITE                                   0xff3f3fffU
#define ATI2S_I2S_CTRL2_RX__PRESERVED                               0x00000000U
#define ATI2S_I2S_CTRL2_RX__RESET_VALUE                             0x40001000U

#endif /* __ATI2S_I2S_CTRL2_RX_MACRO__ */

/** @} end of i2s_ctrl2_rx */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl3 */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl3 i2s_ctrl3
 * @brief Contains register fields associated with i2s_ctrl3. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL3_MACRO__
#define __ATI2S_I2S_CTRL3_MACRO__

/* macros for field swp_smpl */
/**
 * @defgroup at_i2s_regs_core_swp_smpl_field swp_smpl_field
 * @brief macros for field swp_smpl
 * @details swap packed samples in pingpong buffer location  default: former samples uses lsb bits and later samples uses msb bits  applies to 16bit samples only
 * @{
 */
#define ATI2S_I2S_CTRL3__SWP_SMPL__SHIFT                                      0
#define ATI2S_I2S_CTRL3__SWP_SMPL__WIDTH                                      1
#define ATI2S_I2S_CTRL3__SWP_SMPL__MASK                             0x00000001U
#define ATI2S_I2S_CTRL3__SWP_SMPL__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_CTRL3__SWP_SMPL__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_CTRL3__SWP_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_CTRL3__SWP_SMPL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_CTRL3__SWP_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_CTRL3__SWP_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_CTRL3__SWP_SMPL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pck_smpl */
/**
 * @defgroup at_i2s_regs_core_pck_smpl_field pck_smpl_field
 * @brief macros for field pck_smpl
 * @details pack samples in ping-pong buffer  default: samples are stored unpacked  applies to 20/24 bit samples only
 * @{
 */
#define ATI2S_I2S_CTRL3__PCK_SMPL__SHIFT                                      1
#define ATI2S_I2S_CTRL3__PCK_SMPL__WIDTH                                      1
#define ATI2S_I2S_CTRL3__PCK_SMPL__MASK                             0x00000002U
#define ATI2S_I2S_CTRL3__PCK_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_CTRL3__PCK_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_CTRL3__PCK_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_CTRL3__PCK_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_CTRL3__PCK_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_CTRL3__PCK_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_CTRL3__PCK_SMPL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field use_msb_smpl */
/**
 * @defgroup at_i2s_regs_core_use_msb_smpl_field use_msb_smpl_field
 * @brief macros for field use_msb_smpl
 * @details use msb of the samples
 * @{
 */
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__SHIFT                                  2
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__WIDTH                                  1
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__MASK                         0x00000004U
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_CTRL3__USE_MSB_SMPL__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field phs_idx */
/**
 * @defgroup at_i2s_regs_core_phs_idx_field phs_idx_field
 * @brief macros for field phs_idx
 * @details index into the coefficient table
 * @{
 */
#define ATI2S_I2S_CTRL3__PHS_IDX__SHIFT                                       8
#define ATI2S_I2S_CTRL3__PHS_IDX__WIDTH                                       8
#define ATI2S_I2S_CTRL3__PHS_IDX__MASK                              0x0000ff00U
#define ATI2S_I2S_CTRL3__PHS_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define ATI2S_I2S_CTRL3__PHS_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define ATI2S_I2S_CTRL3__PHS_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define ATI2S_I2S_CTRL3__PHS_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define ATI2S_I2S_CTRL3__PHS_IDX__RESET_VALUE                       0x0000007fU
/** @} */

/* macros for field phs_idx_add */
/**
 * @defgroup at_i2s_regs_core_phs_idx_add_field phs_idx_add_field
 * @brief macros for field phs_idx_add
 * @details index into the coefficient table for insert sample
 * @{
 */
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__SHIFT                                  16
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__WIDTH                                   8
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__MASK                          0x00ff0000U
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define ATI2S_I2S_CTRL3__PHS_IDX_ADD__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field intrp_use_msb_smpl */
/**
 * @defgroup at_i2s_regs_core_intrp_use_msb_smpl_field intrp_use_msb_smpl_field
 * @brief macros for field intrp_use_msb_smpl
 * @details Use top 24 bit of 32 bit sample for tx interpolator
 * @{
 */
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__SHIFT                           24
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__WIDTH                            1
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__MASK                   0x01000000U
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define ATI2S_I2S_CTRL3__INTRP_USE_MSB_SMPL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field intrp_byp */
/**
 * @defgroup at_i2s_regs_core_intrp_byp_field intrp_byp_field
 * @brief macros for field intrp_byp
 * @details bypass interpolator for cfo correction for tx
 * @{
 */
#define ATI2S_I2S_CTRL3__INTRP_BYP__SHIFT                                    31
#define ATI2S_I2S_CTRL3__INTRP_BYP__WIDTH                                     1
#define ATI2S_I2S_CTRL3__INTRP_BYP__MASK                            0x80000000U
#define ATI2S_I2S_CTRL3__INTRP_BYP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define ATI2S_I2S_CTRL3__INTRP_BYP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define ATI2S_I2S_CTRL3__INTRP_BYP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define ATI2S_I2S_CTRL3__INTRP_BYP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define ATI2S_I2S_CTRL3__INTRP_BYP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define ATI2S_I2S_CTRL3__INTRP_BYP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define ATI2S_I2S_CTRL3__INTRP_BYP__RESET_VALUE                     0x00000001U
/** @} */
#define ATI2S_I2S_CTRL3__TYPE                                          uint32_t
#define ATI2S_I2S_CTRL3__READ                                       0x81ffff07U
#define ATI2S_I2S_CTRL3__WRITE                                      0x81ffff07U
#define ATI2S_I2S_CTRL3__PRESERVED                                  0x00000000U
#define ATI2S_I2S_CTRL3__RESET_VALUE                                0x80007f04U

#endif /* __ATI2S_I2S_CTRL3_MACRO__ */

/** @} end of i2s_ctrl3 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl4 */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl4 i2s_ctrl4
 * @brief Contains register fields associated with i2s_ctrl4. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL4_MACRO__
#define __ATI2S_I2S_CTRL4_MACRO__

/* macros for field swp_smpl */
/**
 * @defgroup at_i2s_regs_core_swp_smpl_field swp_smpl_field
 * @brief macros for field swp_smpl
 * @details swap packed samples in pingpong buffer location  default: former samples uses lsb bits and later samples uses msb bits  applies to 16bit samples only
 * @{
 */
#define ATI2S_I2S_CTRL4__SWP_SMPL__SHIFT                                      0
#define ATI2S_I2S_CTRL4__SWP_SMPL__WIDTH                                      1
#define ATI2S_I2S_CTRL4__SWP_SMPL__MASK                             0x00000001U
#define ATI2S_I2S_CTRL4__SWP_SMPL__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_CTRL4__SWP_SMPL__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_CTRL4__SWP_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_CTRL4__SWP_SMPL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_CTRL4__SWP_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_CTRL4__SWP_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_CTRL4__SWP_SMPL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pck_smpl */
/**
 * @defgroup at_i2s_regs_core_pck_smpl_field pck_smpl_field
 * @brief macros for field pck_smpl
 * @details pack samples in ping-pong buffer  default: samples are stored unpacked  applies to 20/24 bit samples only
 * @{
 */
#define ATI2S_I2S_CTRL4__PCK_SMPL__SHIFT                                      1
#define ATI2S_I2S_CTRL4__PCK_SMPL__WIDTH                                      1
#define ATI2S_I2S_CTRL4__PCK_SMPL__MASK                             0x00000002U
#define ATI2S_I2S_CTRL4__PCK_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_CTRL4__PCK_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_CTRL4__PCK_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_CTRL4__PCK_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_CTRL4__PCK_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_CTRL4__PCK_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_CTRL4__PCK_SMPL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field use_msb_smpl */
/**
 * @defgroup at_i2s_regs_core_use_msb_smpl_field use_msb_smpl_field
 * @brief macros for field use_msb_smpl
 * @details use msb of the samples
 * @{
 */
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__SHIFT                                  2
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__WIDTH                                  1
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__MASK                         0x00000004U
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_CTRL4__USE_MSB_SMPL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field phs_idx */
/**
 * @defgroup at_i2s_regs_core_phs_idx_field phs_idx_field
 * @brief macros for field phs_idx
 * @details index into the coefficient table
 * @{
 */
#define ATI2S_I2S_CTRL4__PHS_IDX__SHIFT                                       8
#define ATI2S_I2S_CTRL4__PHS_IDX__WIDTH                                       8
#define ATI2S_I2S_CTRL4__PHS_IDX__MASK                              0x0000ff00U
#define ATI2S_I2S_CTRL4__PHS_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define ATI2S_I2S_CTRL4__PHS_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define ATI2S_I2S_CTRL4__PHS_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define ATI2S_I2S_CTRL4__PHS_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define ATI2S_I2S_CTRL4__PHS_IDX__RESET_VALUE                       0x0000007fU
/** @} */

/* macros for field phs_idx_add */
/**
 * @defgroup at_i2s_regs_core_phs_idx_add_field phs_idx_add_field
 * @brief macros for field phs_idx_add
 * @details index into the coefficient table for insert sample
 * @{
 */
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__SHIFT                                  16
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__WIDTH                                   8
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__MASK                          0x00ff0000U
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define ATI2S_I2S_CTRL4__PHS_IDX_ADD__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field intrp_use_msb_smpl */
/**
 * @defgroup at_i2s_regs_core_intrp_use_msb_smpl_field intrp_use_msb_smpl_field
 * @brief macros for field intrp_use_msb_smpl
 * @details Use top 24 bit of 32 bit sample for rx interpolator
 * @{
 */
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__SHIFT                           24
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__WIDTH                            1
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__MASK                   0x01000000U
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define ATI2S_I2S_CTRL4__INTRP_USE_MSB_SMPL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field intrp_byp */
/**
 * @defgroup at_i2s_regs_core_intrp_byp_field intrp_byp_field
 * @brief macros for field intrp_byp
 * @details bypass interpolator for cfo correction for rx
 * @{
 */
#define ATI2S_I2S_CTRL4__INTRP_BYP__SHIFT                                    31
#define ATI2S_I2S_CTRL4__INTRP_BYP__WIDTH                                     1
#define ATI2S_I2S_CTRL4__INTRP_BYP__MASK                            0x80000000U
#define ATI2S_I2S_CTRL4__INTRP_BYP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define ATI2S_I2S_CTRL4__INTRP_BYP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define ATI2S_I2S_CTRL4__INTRP_BYP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define ATI2S_I2S_CTRL4__INTRP_BYP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define ATI2S_I2S_CTRL4__INTRP_BYP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define ATI2S_I2S_CTRL4__INTRP_BYP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define ATI2S_I2S_CTRL4__INTRP_BYP__RESET_VALUE                     0x00000001U
/** @} */
#define ATI2S_I2S_CTRL4__TYPE                                          uint32_t
#define ATI2S_I2S_CTRL4__READ                                       0x81ffff07U
#define ATI2S_I2S_CTRL4__WRITE                                      0x81ffff07U
#define ATI2S_I2S_CTRL4__PRESERVED                                  0x00000000U
#define ATI2S_I2S_CTRL4__RESET_VALUE                                0x80007f00U

#endif /* __ATI2S_I2S_CTRL4_MACRO__ */

/** @} end of i2s_ctrl4 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl5_tx */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl5_tx i2s_ctrl5_tx
 * @brief Contains register fields associated with i2s_ctrl5_tx. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL5_TX_MACRO__
#define __ATI2S_I2S_CTRL5_TX_MACRO__

/* macros for field frq_drft_corr_en */
/**
 * @defgroup at_i2s_regs_core_frq_drft_corr_en_field frq_drft_corr_en_field
 * @brief macros for field frq_drft_corr_en
 * @details 0 = do not enable freq drift correction 1 = enable freq drift correction
 * @{
 */
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__SHIFT                           0
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__WIDTH                           1
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__MASK                  0x00000001U
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_CTRL5_TX__FRQ_DRFT_CORR_EN__RESET_VALUE           0x00000000U
/** @} */
#define ATI2S_I2S_CTRL5_TX__TYPE                                       uint32_t
#define ATI2S_I2S_CTRL5_TX__READ                                    0x00000001U
#define ATI2S_I2S_CTRL5_TX__WRITE                                   0x00000001U
#define ATI2S_I2S_CTRL5_TX__PRESERVED                               0x00000000U
#define ATI2S_I2S_CTRL5_TX__RESET_VALUE                             0x00000000U

#endif /* __ATI2S_I2S_CTRL5_TX_MACRO__ */

/** @} end of i2s_ctrl5_tx */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_ctrl5_rx */
/**
 * @defgroup at_i2s_regs_core_i2s_ctrl5_rx i2s_ctrl5_rx
 * @brief Contains register fields associated with i2s_ctrl5_rx. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_CTRL5_RX_MACRO__
#define __ATI2S_I2S_CTRL5_RX_MACRO__

/* macros for field frq_drft_corr_en */
/**
 * @defgroup at_i2s_regs_core_frq_drft_corr_en_field frq_drft_corr_en_field
 * @brief macros for field frq_drft_corr_en
 * @details 0 = do not enable freq drift correction 1 = enable freq drift correction
 * @{
 */
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__SHIFT                           0
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__WIDTH                           1
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__MASK                  0x00000001U
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_CTRL5_RX__FRQ_DRFT_CORR_EN__RESET_VALUE           0x00000000U
/** @} */
#define ATI2S_I2S_CTRL5_RX__TYPE                                       uint32_t
#define ATI2S_I2S_CTRL5_RX__READ                                    0x00000001U
#define ATI2S_I2S_CTRL5_RX__WRITE                                   0x00000001U
#define ATI2S_I2S_CTRL5_RX__PRESERVED                               0x00000000U
#define ATI2S_I2S_CTRL5_RX__RESET_VALUE                             0x00000000U

#endif /* __ATI2S_I2S_CTRL5_RX_MACRO__ */

/** @} end of i2s_ctrl5_rx */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_intrp_ctrl */
/**
 * @defgroup at_i2s_regs_core_i2s_intrp_ctrl i2s_intrp_ctrl
 * @brief Contains register fields associated with i2s_intrp_ctrl. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_INTRP_CTRL_MACRO__
#define __ATI2S_I2S_INTRP_CTRL_MACRO__

/* macros for field tx_skp_smpl */
/**
 * @defgroup at_i2s_regs_core_tx_skp_smpl_field tx_skp_smpl_field
 * @brief macros for field tx_skp_smpl
 * @details skip one sample to accomodate frequecy drift
 * @{
 */
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__SHIFT                              0
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__WIDTH                              1
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__MASK                     0x00000001U
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_INTRP_CTRL__TX_SKP_SMPL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field tx_add_smpl */
/**
 * @defgroup at_i2s_regs_core_tx_add_smpl_field tx_add_smpl_field
 * @brief macros for field tx_add_smpl
 * @details insert one sample to accomodate frequecy drift
 * @{
 */
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__SHIFT                              1
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__WIDTH                              1
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__MASK                     0x00000002U
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_INTRP_CTRL__TX_ADD_SMPL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field rx_skp_smpl */
/**
 * @defgroup at_i2s_regs_core_rx_skp_smpl_field rx_skp_smpl_field
 * @brief macros for field rx_skp_smpl
 * @details skip one sample to accomodate frequecy drift
 * @{
 */
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__SHIFT                              2
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__WIDTH                              1
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__MASK                     0x00000004U
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_INTRP_CTRL__RX_SKP_SMPL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field rx_add_smpl */
/**
 * @defgroup at_i2s_regs_core_rx_add_smpl_field rx_add_smpl_field
 * @brief macros for field rx_add_smpl
 * @details insert one sample to accomodate frequecy drift
 * @{
 */
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__SHIFT                              3
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__WIDTH                              1
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__MASK                     0x00000008U
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_INTRP_CTRL__RX_ADD_SMPL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field tx_updt_phs_idx */
/**
 * @defgroup at_i2s_regs_core_tx_updt_phs_idx_field tx_updt_phs_idx_field
 * @brief macros for field tx_updt_phs_idx
 * @details latch the phase index for tx interpolator
 * @{
 */
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__SHIFT                          4
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__WIDTH                          1
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__MASK                 0x00000010U
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_INTRP_CTRL__TX_UPDT_PHS_IDX__RESET_VALUE          0x00000000U
/** @} */

/* macros for field rx_updt_phs_idx */
/**
 * @defgroup at_i2s_regs_core_rx_updt_phs_idx_field rx_updt_phs_idx_field
 * @brief macros for field rx_updt_phs_idx
 * @details latch the phase index for rx interpolator
 * @{
 */
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__SHIFT                          5
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__WIDTH                          1
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__MASK                 0x00000020U
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_INTRP_CTRL__RX_UPDT_PHS_IDX__RESET_VALUE          0x00000000U
/** @} */
#define ATI2S_I2S_INTRP_CTRL__TYPE                                     uint32_t
#define ATI2S_I2S_INTRP_CTRL__READ                                  0x0000003fU
#define ATI2S_I2S_INTRP_CTRL__WRITE                                 0x0000003fU
#define ATI2S_I2S_INTRP_CTRL__PRESERVED                             0x00000000U
#define ATI2S_I2S_INTRP_CTRL__RESET_VALUE                           0x00000000U

#endif /* __ATI2S_I2S_INTRP_CTRL_MACRO__ */

/** @} end of i2s_intrp_ctrl */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_pp1_rdata */
/**
 * @defgroup at_i2s_regs_core_i2s_pp1_rdata i2s_pp1_rdata
 * @brief Contains register fields associated with i2s_pp1_rdata. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_PP1_RDATA_MACRO__
#define __ATI2S_I2S_PP1_RDATA_MACRO__

/* macros for field val */
/**
 * @defgroup at_i2s_regs_core_val_field val_field
 * @brief macros for field val
 * @details read data at the top of ping pong set 1 buffer 3
 * @{
 */
#define ATI2S_I2S_PP1_RDATA__VAL__SHIFT                                       0
#define ATI2S_I2S_PP1_RDATA__VAL__WIDTH                                      32
#define ATI2S_I2S_PP1_RDATA__VAL__MASK                              0xffffffffU
#define ATI2S_I2S_PP1_RDATA__VAL__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define ATI2S_I2S_PP1_RDATA__VAL__RESET_VALUE                       0x00000000U
/** @} */
#define ATI2S_I2S_PP1_RDATA__TYPE                                      uint32_t
#define ATI2S_I2S_PP1_RDATA__READ                                   0xffffffffU
#define ATI2S_I2S_PP1_RDATA__PRESERVED                              0x00000000U
#define ATI2S_I2S_PP1_RDATA__RESET_VALUE                            0x00000000U

#endif /* __ATI2S_I2S_PP1_RDATA_MACRO__ */

/** @} end of i2s_pp1_rdata */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_pp0_wdata */
/**
 * @defgroup at_i2s_regs_core_i2s_pp0_wdata i2s_pp0_wdata
 * @brief Contains register fields associated with i2s_pp0_wdata. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_PP0_WDATA_MACRO__
#define __ATI2S_I2S_PP0_WDATA_MACRO__

/* macros for field val */
/**
 * @defgroup at_i2s_regs_core_val_field val_field
 * @brief macros for field val
 * @details write data at the bottom of ping pong set 0 buffer 3
 * @{
 */
#define ATI2S_I2S_PP0_WDATA__VAL__SHIFT                                       0
#define ATI2S_I2S_PP0_WDATA__VAL__WIDTH                                      32
#define ATI2S_I2S_PP0_WDATA__VAL__MASK                              0xffffffffU
#define ATI2S_I2S_PP0_WDATA__VAL__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define ATI2S_I2S_PP0_WDATA__VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define ATI2S_I2S_PP0_WDATA__VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define ATI2S_I2S_PP0_WDATA__VAL__RESET_VALUE                       0x00000000U
/** @} */
#define ATI2S_I2S_PP0_WDATA__TYPE                                      uint32_t
#define ATI2S_I2S_PP0_WDATA__WRITE                                  0x00000000U
#define ATI2S_I2S_PP0_WDATA__PRESERVED                              0x00000000U
#define ATI2S_I2S_PP0_WDATA__RESET_VALUE                            0x00000000U

#endif /* __ATI2S_I2S_PP0_WDATA_MACRO__ */

/** @} end of i2s_pp0_wdata */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_pp1_ctrl */
/**
 * @defgroup at_i2s_regs_core_i2s_pp1_ctrl i2s_pp1_ctrl
 * @brief Contains register fields associated with i2s_pp1_ctrl. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_PP1_CTRL_MACRO__
#define __ATI2S_I2S_PP1_CTRL_MACRO__

/* macros for field thrshld */
/**
 * @defgroup at_i2s_regs_core_thrshld_field thrshld_field
 * @brief macros for field thrshld
 * @details number of available words that are empty and can be filled
 * @{
 */
#define ATI2S_I2S_PP1_CTRL__THRSHLD__SHIFT                                    0
#define ATI2S_I2S_PP1_CTRL__THRSHLD__WIDTH                                    7
#define ATI2S_I2S_PP1_CTRL__THRSHLD__MASK                           0x0000007fU
#define ATI2S_I2S_PP1_CTRL__THRSHLD__READ(src)  ((uint32_t)(src) & 0x0000007fU)
#define ATI2S_I2S_PP1_CTRL__THRSHLD__WRITE(src) ((uint32_t)(src) & 0x0000007fU)
#define ATI2S_I2S_PP1_CTRL__THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define ATI2S_I2S_PP1_CTRL__THRSHLD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define ATI2S_I2S_PP1_CTRL__THRSHLD__RESET_VALUE                    0x00000008U
/** @} */
#define ATI2S_I2S_PP1_CTRL__TYPE                                       uint32_t
#define ATI2S_I2S_PP1_CTRL__READ                                    0x0000007fU
#define ATI2S_I2S_PP1_CTRL__WRITE                                   0x0000007fU
#define ATI2S_I2S_PP1_CTRL__PRESERVED                               0x00000000U
#define ATI2S_I2S_PP1_CTRL__RESET_VALUE                             0x00000008U

#endif /* __ATI2S_I2S_PP1_CTRL_MACRO__ */

/** @} end of i2s_pp1_ctrl */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_pp0_ctrl */
/**
 * @defgroup at_i2s_regs_core_i2s_pp0_ctrl i2s_pp0_ctrl
 * @brief Contains register fields associated with i2s_pp0_ctrl. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_PP0_CTRL_MACRO__
#define __ATI2S_I2S_PP0_CTRL_MACRO__

/* macros for field thrshld */
/**
 * @defgroup at_i2s_regs_core_thrshld_field thrshld_field
 * @brief macros for field thrshld
 * @details number of available words that are empty and can be filled
 * @{
 */
#define ATI2S_I2S_PP0_CTRL__THRSHLD__SHIFT                                    0
#define ATI2S_I2S_PP0_CTRL__THRSHLD__WIDTH                                    7
#define ATI2S_I2S_PP0_CTRL__THRSHLD__MASK                           0x0000007fU
#define ATI2S_I2S_PP0_CTRL__THRSHLD__READ(src)  ((uint32_t)(src) & 0x0000007fU)
#define ATI2S_I2S_PP0_CTRL__THRSHLD__WRITE(src) ((uint32_t)(src) & 0x0000007fU)
#define ATI2S_I2S_PP0_CTRL__THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define ATI2S_I2S_PP0_CTRL__THRSHLD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define ATI2S_I2S_PP0_CTRL__THRSHLD__RESET_VALUE                    0x00000008U
/** @} */
#define ATI2S_I2S_PP0_CTRL__TYPE                                       uint32_t
#define ATI2S_I2S_PP0_CTRL__READ                                    0x0000007fU
#define ATI2S_I2S_PP0_CTRL__WRITE                                   0x0000007fU
#define ATI2S_I2S_PP0_CTRL__PRESERVED                               0x00000000U
#define ATI2S_I2S_PP0_CTRL__RESET_VALUE                             0x00000008U

#endif /* __ATI2S_I2S_PP0_CTRL_MACRO__ */

/** @} end of i2s_pp0_ctrl */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irq0 */
/**
 * @defgroup at_i2s_regs_core_i2s_irq0 i2s_irq0
 * @brief Contains register fields associated with i2s_irq0. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQ0_MACRO__
#define __ATI2S_I2S_IRQ0_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 0 buffer 0 full
 * @{
 */
#define ATI2S_I2S_IRQ0__PP0_FL__SHIFT                                         0
#define ATI2S_I2S_IRQ0__PP0_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP0_FL__MASK                                0x00000001U
#define ATI2S_I2S_IRQ0__PP0_FL__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQ0__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQ0__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQ0__PP0_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 0 buffer 1 full
 * @{
 */
#define ATI2S_I2S_IRQ0__PP1_FL__SHIFT                                         1
#define ATI2S_I2S_IRQ0__PP1_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP1_FL__MASK                                0x00000002U
#define ATI2S_I2S_IRQ0__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQ0__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQ0__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQ0__PP1_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 0 buffer 2 full
 * @{
 */
#define ATI2S_I2S_IRQ0__PP2_FL__SHIFT                                         2
#define ATI2S_I2S_IRQ0__PP2_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP2_FL__MASK                                0x00000004U
#define ATI2S_I2S_IRQ0__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQ0__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQ0__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQ0__PP2_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 0 buffer 3 full
 * @{
 */
#define ATI2S_I2S_IRQ0__PP3_FL__SHIFT                                         3
#define ATI2S_I2S_IRQ0__PP3_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP3_FL__MASK                                0x00000008U
#define ATI2S_I2S_IRQ0__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQ0__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQ0__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQ0__PP3_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 0 buffer 0 over flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP0_OF__SHIFT                                         4
#define ATI2S_I2S_IRQ0__PP0_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP0_OF__MASK                                0x00000010U
#define ATI2S_I2S_IRQ0__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQ0__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQ0__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQ0__PP0_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 0 buffer 1 over flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP1_OF__SHIFT                                         5
#define ATI2S_I2S_IRQ0__PP1_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP1_OF__MASK                                0x00000020U
#define ATI2S_I2S_IRQ0__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQ0__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQ0__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQ0__PP1_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 0 buffer 2 over flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP2_OF__SHIFT                                         6
#define ATI2S_I2S_IRQ0__PP2_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP2_OF__MASK                                0x00000040U
#define ATI2S_I2S_IRQ0__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQ0__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQ0__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQ0__PP2_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 0 buffer 3 over flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP3_OF__SHIFT                                         7
#define ATI2S_I2S_IRQ0__PP3_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP3_OF__MASK                                0x00000080U
#define ATI2S_I2S_IRQ0__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQ0__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQ0__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQ0__PP3_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 0 buffer 0 under flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP0_UF__SHIFT                                         8
#define ATI2S_I2S_IRQ0__PP0_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP0_UF__MASK                                0x00000100U
#define ATI2S_I2S_IRQ0__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQ0__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQ0__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQ0__PP0_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 0 buffer 1 under flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP1_UF__SHIFT                                         9
#define ATI2S_I2S_IRQ0__PP1_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP1_UF__MASK                                0x00000200U
#define ATI2S_I2S_IRQ0__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQ0__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQ0__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQ0__PP1_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 0 buffer 2 under flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP2_UF__SHIFT                                        10
#define ATI2S_I2S_IRQ0__PP2_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP2_UF__MASK                                0x00000400U
#define ATI2S_I2S_IRQ0__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQ0__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQ0__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQ0__PP2_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 0 buffer 3 under flow
 * @{
 */
#define ATI2S_I2S_IRQ0__PP3_UF__SHIFT                                        11
#define ATI2S_I2S_IRQ0__PP3_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ0__PP3_UF__MASK                                0x00000800U
#define ATI2S_I2S_IRQ0__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQ0__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQ0__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQ0__PP3_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit
 * @{
 */
#define ATI2S_I2S_IRQ0__PP_EP_THRSHLD__SHIFT                                 12
#define ATI2S_I2S_IRQ0__PP_EP_THRSHLD__WIDTH                                  1
#define ATI2S_I2S_IRQ0__PP_EP_THRSHLD__MASK                         0x00001000U
#define ATI2S_I2S_IRQ0__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQ0__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQ0__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQ0__PP_EP_THRSHLD__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid
 * @{
 */
#define ATI2S_I2S_IRQ0__INTRP_DOUT_VLD__SHIFT                                13
#define ATI2S_I2S_IRQ0__INTRP_DOUT_VLD__WIDTH                                 1
#define ATI2S_I2S_IRQ0__INTRP_DOUT_VLD__MASK                        0x00002000U
#define ATI2S_I2S_IRQ0__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQ0__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQ0__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQ0__INTRP_DOUT_VLD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field pdm_ufof */
/**
 * @defgroup at_i2s_regs_core_pdm_ufof_field pdm_ufof_field
 * @brief macros for field pdm_ufof
 * @details pdm underflow or overflow
 * @{
 */
#define ATI2S_I2S_IRQ0__PDM_UFOF__SHIFT                                      31
#define ATI2S_I2S_IRQ0__PDM_UFOF__WIDTH                                       1
#define ATI2S_I2S_IRQ0__PDM_UFOF__MASK                              0x80000000U
#define ATI2S_I2S_IRQ0__PDM_UFOF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define ATI2S_I2S_IRQ0__PDM_UFOF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define ATI2S_I2S_IRQ0__PDM_UFOF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define ATI2S_I2S_IRQ0__PDM_UFOF__RESET_VALUE                       0x00000000U
/** @} */
#define ATI2S_I2S_IRQ0__TYPE                                           uint32_t
#define ATI2S_I2S_IRQ0__READ                                        0x80003fffU
#define ATI2S_I2S_IRQ0__PRESERVED                                   0x00000000U
#define ATI2S_I2S_IRQ0__RESET_VALUE                                 0x00000000U

#endif /* __ATI2S_I2S_IRQ0_MACRO__ */

/** @} end of i2s_irq0 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irqm0 */
/**
 * @defgroup at_i2s_regs_core_i2s_irqm0 i2s_irqm0
 * @brief Contains register fields associated with i2s_irqm0. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQM0_MACRO__
#define __ATI2S_I2S_IRQM0_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 0 buffer 0 full mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP0_FL__SHIFT                                        0
#define ATI2S_I2S_IRQM0__PP0_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP0_FL__MASK                               0x00000001U
#define ATI2S_I2S_IRQM0__PP0_FL__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQM0__PP0_FL__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQM0__PP0_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_IRQM0__PP0_FL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_IRQM0__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQM0__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQM0__PP0_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 0 buffer 1 full mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP1_FL__SHIFT                                        1
#define ATI2S_I2S_IRQM0__PP1_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP1_FL__MASK                               0x00000002U
#define ATI2S_I2S_IRQM0__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQM0__PP1_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_IRQM0__PP1_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_IRQM0__PP1_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_IRQM0__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQM0__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQM0__PP1_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 0 buffer 2 full mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP2_FL__SHIFT                                        2
#define ATI2S_I2S_IRQM0__PP2_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP2_FL__MASK                               0x00000004U
#define ATI2S_I2S_IRQM0__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQM0__PP2_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_IRQM0__PP2_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_IRQM0__PP2_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_IRQM0__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQM0__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQM0__PP2_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 0 buffer 3 full mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP3_FL__SHIFT                                        3
#define ATI2S_I2S_IRQM0__PP3_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP3_FL__MASK                               0x00000008U
#define ATI2S_I2S_IRQM0__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQM0__PP3_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define ATI2S_I2S_IRQM0__PP3_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define ATI2S_I2S_IRQM0__PP3_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define ATI2S_I2S_IRQM0__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQM0__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQM0__PP3_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 0 buffer 0 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP0_OF__SHIFT                                        4
#define ATI2S_I2S_IRQM0__PP0_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP0_OF__MASK                               0x00000010U
#define ATI2S_I2S_IRQM0__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQM0__PP0_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define ATI2S_I2S_IRQM0__PP0_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define ATI2S_I2S_IRQM0__PP0_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define ATI2S_I2S_IRQM0__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQM0__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQM0__PP0_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 0 buffer 1 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP1_OF__SHIFT                                        5
#define ATI2S_I2S_IRQM0__PP1_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP1_OF__MASK                               0x00000020U
#define ATI2S_I2S_IRQM0__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQM0__PP1_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define ATI2S_I2S_IRQM0__PP1_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define ATI2S_I2S_IRQM0__PP1_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define ATI2S_I2S_IRQM0__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQM0__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQM0__PP1_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 0 buffer 2 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP2_OF__SHIFT                                        6
#define ATI2S_I2S_IRQM0__PP2_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP2_OF__MASK                               0x00000040U
#define ATI2S_I2S_IRQM0__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQM0__PP2_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define ATI2S_I2S_IRQM0__PP2_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define ATI2S_I2S_IRQM0__PP2_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define ATI2S_I2S_IRQM0__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQM0__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQM0__PP2_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 0 buffer 3 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP3_OF__SHIFT                                        7
#define ATI2S_I2S_IRQM0__PP3_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP3_OF__MASK                               0x00000080U
#define ATI2S_I2S_IRQM0__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQM0__PP3_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define ATI2S_I2S_IRQM0__PP3_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define ATI2S_I2S_IRQM0__PP3_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define ATI2S_I2S_IRQM0__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQM0__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQM0__PP3_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 0 buffer 0 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP0_UF__SHIFT                                        8
#define ATI2S_I2S_IRQM0__PP0_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP0_UF__MASK                               0x00000100U
#define ATI2S_I2S_IRQM0__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQM0__PP0_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define ATI2S_I2S_IRQM0__PP0_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define ATI2S_I2S_IRQM0__PP0_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define ATI2S_I2S_IRQM0__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQM0__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQM0__PP0_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 0 buffer 1 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP1_UF__SHIFT                                        9
#define ATI2S_I2S_IRQM0__PP1_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP1_UF__MASK                               0x00000200U
#define ATI2S_I2S_IRQM0__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQM0__PP1_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define ATI2S_I2S_IRQM0__PP1_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define ATI2S_I2S_IRQM0__PP1_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define ATI2S_I2S_IRQM0__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQM0__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQM0__PP1_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 0 buffer 2 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP2_UF__SHIFT                                       10
#define ATI2S_I2S_IRQM0__PP2_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP2_UF__MASK                               0x00000400U
#define ATI2S_I2S_IRQM0__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQM0__PP2_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define ATI2S_I2S_IRQM0__PP2_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define ATI2S_I2S_IRQM0__PP2_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define ATI2S_I2S_IRQM0__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQM0__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQM0__PP2_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 0 buffer 3 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP3_UF__SHIFT                                       11
#define ATI2S_I2S_IRQM0__PP3_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM0__PP3_UF__MASK                               0x00000800U
#define ATI2S_I2S_IRQM0__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQM0__PP3_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define ATI2S_I2S_IRQM0__PP3_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define ATI2S_I2S_IRQM0__PP3_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define ATI2S_I2S_IRQM0__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQM0__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQM0__PP3_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit mask
 * @{
 */
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__SHIFT                                12
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__WIDTH                                 1
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__MASK                        0x00001000U
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQM0__PP_EP_THRSHLD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid mask
 * @{
 */
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__SHIFT                               13
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__WIDTH                                1
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__MASK                       0x00002000U
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQM0__INTRP_DOUT_VLD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field pdm_ufof */
/**
 * @defgroup at_i2s_regs_core_pdm_ufof_field pdm_ufof_field
 * @brief macros for field pdm_ufof
 * @details pdm underflow or overflow
 * @{
 */
#define ATI2S_I2S_IRQM0__PDM_UFOF__SHIFT                                     31
#define ATI2S_I2S_IRQM0__PDM_UFOF__WIDTH                                      1
#define ATI2S_I2S_IRQM0__PDM_UFOF__MASK                             0x80000000U
#define ATI2S_I2S_IRQM0__PDM_UFOF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define ATI2S_I2S_IRQM0__PDM_UFOF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define ATI2S_I2S_IRQM0__PDM_UFOF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define ATI2S_I2S_IRQM0__PDM_UFOF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define ATI2S_I2S_IRQM0__PDM_UFOF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define ATI2S_I2S_IRQM0__PDM_UFOF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define ATI2S_I2S_IRQM0__PDM_UFOF__RESET_VALUE                      0x00000000U
/** @} */
#define ATI2S_I2S_IRQM0__TYPE                                          uint32_t
#define ATI2S_I2S_IRQM0__READ                                       0x80003fffU
#define ATI2S_I2S_IRQM0__WRITE                                      0x80003fffU
#define ATI2S_I2S_IRQM0__PRESERVED                                  0x00000000U
#define ATI2S_I2S_IRQM0__RESET_VALUE                                0x00000fffU

#endif /* __ATI2S_I2S_IRQM0_MACRO__ */

/** @} end of i2s_irqm0 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irqs0 */
/**
 * @defgroup at_i2s_regs_core_i2s_irqs0 i2s_irqs0
 * @brief Contains register fields associated with i2s_irqs0. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQS0_MACRO__
#define __ATI2S_I2S_IRQS0_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 0 buffer 0 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP0_FL__SHIFT                                        0
#define ATI2S_I2S_IRQS0__PP0_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP0_FL__MASK                               0x00000001U
#define ATI2S_I2S_IRQS0__PP0_FL__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQS0__PP0_FL__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQS0__PP0_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_IRQS0__PP0_FL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_IRQS0__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQS0__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQS0__PP0_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 0 buffer 1 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP1_FL__SHIFT                                        1
#define ATI2S_I2S_IRQS0__PP1_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP1_FL__MASK                               0x00000002U
#define ATI2S_I2S_IRQS0__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQS0__PP1_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_IRQS0__PP1_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_IRQS0__PP1_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_IRQS0__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQS0__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQS0__PP1_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 0 buffer 2 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP2_FL__SHIFT                                        2
#define ATI2S_I2S_IRQS0__PP2_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP2_FL__MASK                               0x00000004U
#define ATI2S_I2S_IRQS0__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQS0__PP2_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_IRQS0__PP2_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_IRQS0__PP2_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_IRQS0__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQS0__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQS0__PP2_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 0 buffer 3 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP3_FL__SHIFT                                        3
#define ATI2S_I2S_IRQS0__PP3_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP3_FL__MASK                               0x00000008U
#define ATI2S_I2S_IRQS0__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQS0__PP3_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define ATI2S_I2S_IRQS0__PP3_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define ATI2S_I2S_IRQS0__PP3_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define ATI2S_I2S_IRQS0__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQS0__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQS0__PP3_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 0 buffer 0 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP0_OF__SHIFT                                        4
#define ATI2S_I2S_IRQS0__PP0_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP0_OF__MASK                               0x00000010U
#define ATI2S_I2S_IRQS0__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQS0__PP0_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define ATI2S_I2S_IRQS0__PP0_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define ATI2S_I2S_IRQS0__PP0_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define ATI2S_I2S_IRQS0__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQS0__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQS0__PP0_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 0 buffer 1 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP1_OF__SHIFT                                        5
#define ATI2S_I2S_IRQS0__PP1_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP1_OF__MASK                               0x00000020U
#define ATI2S_I2S_IRQS0__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQS0__PP1_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define ATI2S_I2S_IRQS0__PP1_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define ATI2S_I2S_IRQS0__PP1_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define ATI2S_I2S_IRQS0__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQS0__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQS0__PP1_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 0 buffer 2 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP2_OF__SHIFT                                        6
#define ATI2S_I2S_IRQS0__PP2_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP2_OF__MASK                               0x00000040U
#define ATI2S_I2S_IRQS0__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQS0__PP2_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define ATI2S_I2S_IRQS0__PP2_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define ATI2S_I2S_IRQS0__PP2_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define ATI2S_I2S_IRQS0__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQS0__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQS0__PP2_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 0 buffer 3 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP3_OF__SHIFT                                        7
#define ATI2S_I2S_IRQS0__PP3_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP3_OF__MASK                               0x00000080U
#define ATI2S_I2S_IRQS0__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQS0__PP3_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define ATI2S_I2S_IRQS0__PP3_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define ATI2S_I2S_IRQS0__PP3_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define ATI2S_I2S_IRQS0__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQS0__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQS0__PP3_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 0 buffer 0 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP0_UF__SHIFT                                        8
#define ATI2S_I2S_IRQS0__PP0_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP0_UF__MASK                               0x00000100U
#define ATI2S_I2S_IRQS0__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQS0__PP0_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define ATI2S_I2S_IRQS0__PP0_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define ATI2S_I2S_IRQS0__PP0_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define ATI2S_I2S_IRQS0__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQS0__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQS0__PP0_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 0 buffer 1 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP1_UF__SHIFT                                        9
#define ATI2S_I2S_IRQS0__PP1_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP1_UF__MASK                               0x00000200U
#define ATI2S_I2S_IRQS0__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQS0__PP1_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define ATI2S_I2S_IRQS0__PP1_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define ATI2S_I2S_IRQS0__PP1_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define ATI2S_I2S_IRQS0__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQS0__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQS0__PP1_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 0 buffer 2 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP2_UF__SHIFT                                       10
#define ATI2S_I2S_IRQS0__PP2_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP2_UF__MASK                               0x00000400U
#define ATI2S_I2S_IRQS0__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQS0__PP2_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define ATI2S_I2S_IRQS0__PP2_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define ATI2S_I2S_IRQS0__PP2_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define ATI2S_I2S_IRQS0__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQS0__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQS0__PP2_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 0 buffer 3 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP3_UF__SHIFT                                       11
#define ATI2S_I2S_IRQS0__PP3_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS0__PP3_UF__MASK                               0x00000800U
#define ATI2S_I2S_IRQS0__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQS0__PP3_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define ATI2S_I2S_IRQS0__PP3_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define ATI2S_I2S_IRQS0__PP3_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define ATI2S_I2S_IRQS0__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQS0__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQS0__PP3_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__SHIFT                                12
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__WIDTH                                 1
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__MASK                        0x00001000U
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQS0__PP_EP_THRSHLD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__SHIFT                               13
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__WIDTH                                1
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__MASK                       0x00002000U
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQS0__INTRP_DOUT_VLD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field pdm_ufof */
/**
 * @defgroup at_i2s_regs_core_pdm_ufof_field pdm_ufof_field
 * @brief macros for field pdm_ufof
 * @details pdm underflow or overflow. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS0__PDM_UFOF__SHIFT                                     31
#define ATI2S_I2S_IRQS0__PDM_UFOF__WIDTH                                      1
#define ATI2S_I2S_IRQS0__PDM_UFOF__MASK                             0x80000000U
#define ATI2S_I2S_IRQS0__PDM_UFOF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define ATI2S_I2S_IRQS0__PDM_UFOF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define ATI2S_I2S_IRQS0__PDM_UFOF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define ATI2S_I2S_IRQS0__PDM_UFOF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define ATI2S_I2S_IRQS0__PDM_UFOF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define ATI2S_I2S_IRQS0__PDM_UFOF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define ATI2S_I2S_IRQS0__PDM_UFOF__RESET_VALUE                      0x00000000U
/** @} */
#define ATI2S_I2S_IRQS0__TYPE                                          uint32_t
#define ATI2S_I2S_IRQS0__READ                                       0x80003fffU
#define ATI2S_I2S_IRQS0__WRITE                                      0x80003fffU
#define ATI2S_I2S_IRQS0__PRESERVED                                  0x00000000U
#define ATI2S_I2S_IRQS0__RESET_VALUE                                0x00000000U

#endif /* __ATI2S_I2S_IRQS0_MACRO__ */

/** @} end of i2s_irqs0 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irqc0 */
/**
 * @defgroup at_i2s_regs_core_i2s_irqc0 i2s_irqc0
 * @brief Contains register fields associated with i2s_irqc0. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQC0_MACRO__
#define __ATI2S_I2S_IRQC0_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 0 buffer 0 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP0_FL__SHIFT                                        0
#define ATI2S_I2S_IRQC0__PP0_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP0_FL__MASK                               0x00000001U
#define ATI2S_I2S_IRQC0__PP0_FL__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQC0__PP0_FL__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQC0__PP0_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_IRQC0__PP0_FL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_IRQC0__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQC0__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQC0__PP0_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 0 buffer 1 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP1_FL__SHIFT                                        1
#define ATI2S_I2S_IRQC0__PP1_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP1_FL__MASK                               0x00000002U
#define ATI2S_I2S_IRQC0__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQC0__PP1_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_IRQC0__PP1_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_IRQC0__PP1_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_IRQC0__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQC0__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQC0__PP1_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 0 buffer 2 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP2_FL__SHIFT                                        2
#define ATI2S_I2S_IRQC0__PP2_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP2_FL__MASK                               0x00000004U
#define ATI2S_I2S_IRQC0__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQC0__PP2_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_IRQC0__PP2_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_IRQC0__PP2_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_IRQC0__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQC0__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQC0__PP2_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 0 buffer 3 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP3_FL__SHIFT                                        3
#define ATI2S_I2S_IRQC0__PP3_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP3_FL__MASK                               0x00000008U
#define ATI2S_I2S_IRQC0__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQC0__PP3_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define ATI2S_I2S_IRQC0__PP3_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define ATI2S_I2S_IRQC0__PP3_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define ATI2S_I2S_IRQC0__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQC0__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQC0__PP3_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 0 buffer 0 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP0_OF__SHIFT                                        4
#define ATI2S_I2S_IRQC0__PP0_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP0_OF__MASK                               0x00000010U
#define ATI2S_I2S_IRQC0__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQC0__PP0_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define ATI2S_I2S_IRQC0__PP0_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define ATI2S_I2S_IRQC0__PP0_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define ATI2S_I2S_IRQC0__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQC0__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQC0__PP0_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 0 buffer 1 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP1_OF__SHIFT                                        5
#define ATI2S_I2S_IRQC0__PP1_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP1_OF__MASK                               0x00000020U
#define ATI2S_I2S_IRQC0__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQC0__PP1_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define ATI2S_I2S_IRQC0__PP1_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define ATI2S_I2S_IRQC0__PP1_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define ATI2S_I2S_IRQC0__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQC0__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQC0__PP1_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 0 buffer 2 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP2_OF__SHIFT                                        6
#define ATI2S_I2S_IRQC0__PP2_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP2_OF__MASK                               0x00000040U
#define ATI2S_I2S_IRQC0__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQC0__PP2_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define ATI2S_I2S_IRQC0__PP2_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define ATI2S_I2S_IRQC0__PP2_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define ATI2S_I2S_IRQC0__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQC0__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQC0__PP2_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 0 buffer 3 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP3_OF__SHIFT                                        7
#define ATI2S_I2S_IRQC0__PP3_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP3_OF__MASK                               0x00000080U
#define ATI2S_I2S_IRQC0__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQC0__PP3_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define ATI2S_I2S_IRQC0__PP3_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define ATI2S_I2S_IRQC0__PP3_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define ATI2S_I2S_IRQC0__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQC0__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQC0__PP3_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 0 buffer 0 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP0_UF__SHIFT                                        8
#define ATI2S_I2S_IRQC0__PP0_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP0_UF__MASK                               0x00000100U
#define ATI2S_I2S_IRQC0__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQC0__PP0_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define ATI2S_I2S_IRQC0__PP0_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define ATI2S_I2S_IRQC0__PP0_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define ATI2S_I2S_IRQC0__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQC0__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQC0__PP0_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 0 buffer 1 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP1_UF__SHIFT                                        9
#define ATI2S_I2S_IRQC0__PP1_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP1_UF__MASK                               0x00000200U
#define ATI2S_I2S_IRQC0__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQC0__PP1_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define ATI2S_I2S_IRQC0__PP1_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define ATI2S_I2S_IRQC0__PP1_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define ATI2S_I2S_IRQC0__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQC0__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQC0__PP1_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 0 buffer 2 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP2_UF__SHIFT                                       10
#define ATI2S_I2S_IRQC0__PP2_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP2_UF__MASK                               0x00000400U
#define ATI2S_I2S_IRQC0__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQC0__PP2_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define ATI2S_I2S_IRQC0__PP2_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define ATI2S_I2S_IRQC0__PP2_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define ATI2S_I2S_IRQC0__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQC0__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQC0__PP2_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 0 buffer 3 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP3_UF__SHIFT                                       11
#define ATI2S_I2S_IRQC0__PP3_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC0__PP3_UF__MASK                               0x00000800U
#define ATI2S_I2S_IRQC0__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQC0__PP3_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define ATI2S_I2S_IRQC0__PP3_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define ATI2S_I2S_IRQC0__PP3_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define ATI2S_I2S_IRQC0__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQC0__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQC0__PP3_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__SHIFT                                12
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__WIDTH                                 1
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__MASK                        0x00001000U
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQC0__PP_EP_THRSHLD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__SHIFT                               13
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__WIDTH                                1
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__MASK                       0x00002000U
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQC0__INTRP_DOUT_VLD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field pdm_ufof */
/**
 * @defgroup at_i2s_regs_core_pdm_ufof_field pdm_ufof_field
 * @brief macros for field pdm_ufof
 * @details pdm underflow or overflow. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC0__PDM_UFOF__SHIFT                                     31
#define ATI2S_I2S_IRQC0__PDM_UFOF__WIDTH                                      1
#define ATI2S_I2S_IRQC0__PDM_UFOF__MASK                             0x80000000U
#define ATI2S_I2S_IRQC0__PDM_UFOF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define ATI2S_I2S_IRQC0__PDM_UFOF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define ATI2S_I2S_IRQC0__PDM_UFOF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define ATI2S_I2S_IRQC0__PDM_UFOF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define ATI2S_I2S_IRQC0__PDM_UFOF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define ATI2S_I2S_IRQC0__PDM_UFOF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define ATI2S_I2S_IRQC0__PDM_UFOF__RESET_VALUE                      0x00000000U
/** @} */
#define ATI2S_I2S_IRQC0__TYPE                                          uint32_t
#define ATI2S_I2S_IRQC0__READ                                       0x80003fffU
#define ATI2S_I2S_IRQC0__WRITE                                      0x80003fffU
#define ATI2S_I2S_IRQC0__PRESERVED                                  0x00000000U
#define ATI2S_I2S_IRQC0__RESET_VALUE                                0x00000000U

#endif /* __ATI2S_I2S_IRQC0_MACRO__ */

/** @} end of i2s_irqc0 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irq1 */
/**
 * @defgroup at_i2s_regs_core_i2s_irq1 i2s_irq1
 * @brief Contains register fields associated with i2s_irq1. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQ1_MACRO__
#define __ATI2S_I2S_IRQ1_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 1 buffer 0 full
 * @{
 */
#define ATI2S_I2S_IRQ1__PP0_FL__SHIFT                                         0
#define ATI2S_I2S_IRQ1__PP0_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP0_FL__MASK                                0x00000001U
#define ATI2S_I2S_IRQ1__PP0_FL__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQ1__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQ1__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQ1__PP0_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 1 buffer 1 full
 * @{
 */
#define ATI2S_I2S_IRQ1__PP1_FL__SHIFT                                         1
#define ATI2S_I2S_IRQ1__PP1_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP1_FL__MASK                                0x00000002U
#define ATI2S_I2S_IRQ1__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQ1__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQ1__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQ1__PP1_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 1 buffer 2 full
 * @{
 */
#define ATI2S_I2S_IRQ1__PP2_FL__SHIFT                                         2
#define ATI2S_I2S_IRQ1__PP2_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP2_FL__MASK                                0x00000004U
#define ATI2S_I2S_IRQ1__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQ1__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQ1__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQ1__PP2_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 1 buffer 3 full
 * @{
 */
#define ATI2S_I2S_IRQ1__PP3_FL__SHIFT                                         3
#define ATI2S_I2S_IRQ1__PP3_FL__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP3_FL__MASK                                0x00000008U
#define ATI2S_I2S_IRQ1__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQ1__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQ1__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQ1__PP3_FL__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 1 buffer 0 over flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP0_OF__SHIFT                                         4
#define ATI2S_I2S_IRQ1__PP0_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP0_OF__MASK                                0x00000010U
#define ATI2S_I2S_IRQ1__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQ1__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQ1__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQ1__PP0_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 1 buffer 1 over flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP1_OF__SHIFT                                         5
#define ATI2S_I2S_IRQ1__PP1_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP1_OF__MASK                                0x00000020U
#define ATI2S_I2S_IRQ1__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQ1__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQ1__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQ1__PP1_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 1 buffer 2 over flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP2_OF__SHIFT                                         6
#define ATI2S_I2S_IRQ1__PP2_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP2_OF__MASK                                0x00000040U
#define ATI2S_I2S_IRQ1__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQ1__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQ1__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQ1__PP2_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 1 buffer 3 over flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP3_OF__SHIFT                                         7
#define ATI2S_I2S_IRQ1__PP3_OF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP3_OF__MASK                                0x00000080U
#define ATI2S_I2S_IRQ1__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQ1__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQ1__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQ1__PP3_OF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 1 buffer 0 under flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP0_UF__SHIFT                                         8
#define ATI2S_I2S_IRQ1__PP0_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP0_UF__MASK                                0x00000100U
#define ATI2S_I2S_IRQ1__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQ1__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQ1__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQ1__PP0_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 1 buffer 1 under flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP1_UF__SHIFT                                         9
#define ATI2S_I2S_IRQ1__PP1_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP1_UF__MASK                                0x00000200U
#define ATI2S_I2S_IRQ1__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQ1__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQ1__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQ1__PP1_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 1 buffer 2 under flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP2_UF__SHIFT                                        10
#define ATI2S_I2S_IRQ1__PP2_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP2_UF__MASK                                0x00000400U
#define ATI2S_I2S_IRQ1__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQ1__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQ1__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQ1__PP2_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 1 buffer 3 under flow
 * @{
 */
#define ATI2S_I2S_IRQ1__PP3_UF__SHIFT                                        11
#define ATI2S_I2S_IRQ1__PP3_UF__WIDTH                                         1
#define ATI2S_I2S_IRQ1__PP3_UF__MASK                                0x00000800U
#define ATI2S_I2S_IRQ1__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQ1__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQ1__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQ1__PP3_UF__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit
 * @{
 */
#define ATI2S_I2S_IRQ1__PP_EP_THRSHLD__SHIFT                                 12
#define ATI2S_I2S_IRQ1__PP_EP_THRSHLD__WIDTH                                  1
#define ATI2S_I2S_IRQ1__PP_EP_THRSHLD__MASK                         0x00001000U
#define ATI2S_I2S_IRQ1__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQ1__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQ1__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQ1__PP_EP_THRSHLD__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid
 * @{
 */
#define ATI2S_I2S_IRQ1__INTRP_DOUT_VLD__SHIFT                                13
#define ATI2S_I2S_IRQ1__INTRP_DOUT_VLD__WIDTH                                 1
#define ATI2S_I2S_IRQ1__INTRP_DOUT_VLD__MASK                        0x00002000U
#define ATI2S_I2S_IRQ1__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQ1__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQ1__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQ1__INTRP_DOUT_VLD__RESET_VALUE                 0x00000000U
/** @} */
#define ATI2S_I2S_IRQ1__TYPE                                           uint32_t
#define ATI2S_I2S_IRQ1__READ                                        0x00003fffU
#define ATI2S_I2S_IRQ1__PRESERVED                                   0x00000000U
#define ATI2S_I2S_IRQ1__RESET_VALUE                                 0x00000000U

#endif /* __ATI2S_I2S_IRQ1_MACRO__ */

/** @} end of i2s_irq1 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irqm1 */
/**
 * @defgroup at_i2s_regs_core_i2s_irqm1 i2s_irqm1
 * @brief Contains register fields associated with i2s_irqm1. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQM1_MACRO__
#define __ATI2S_I2S_IRQM1_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 1 buffer 0 full mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP0_FL__SHIFT                                        0
#define ATI2S_I2S_IRQM1__PP0_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP0_FL__MASK                               0x00000001U
#define ATI2S_I2S_IRQM1__PP0_FL__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQM1__PP0_FL__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQM1__PP0_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_IRQM1__PP0_FL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_IRQM1__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQM1__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQM1__PP0_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 1 buffer 1 full mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP1_FL__SHIFT                                        1
#define ATI2S_I2S_IRQM1__PP1_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP1_FL__MASK                               0x00000002U
#define ATI2S_I2S_IRQM1__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQM1__PP1_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_IRQM1__PP1_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_IRQM1__PP1_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_IRQM1__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQM1__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQM1__PP1_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 1 buffer 2 full mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP2_FL__SHIFT                                        2
#define ATI2S_I2S_IRQM1__PP2_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP2_FL__MASK                               0x00000004U
#define ATI2S_I2S_IRQM1__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQM1__PP2_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_IRQM1__PP2_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_IRQM1__PP2_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_IRQM1__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQM1__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQM1__PP2_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 1 buffer 3 full mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP3_FL__SHIFT                                        3
#define ATI2S_I2S_IRQM1__PP3_FL__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP3_FL__MASK                               0x00000008U
#define ATI2S_I2S_IRQM1__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQM1__PP3_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define ATI2S_I2S_IRQM1__PP3_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define ATI2S_I2S_IRQM1__PP3_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define ATI2S_I2S_IRQM1__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQM1__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQM1__PP3_FL__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 1 buffer 0 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP0_OF__SHIFT                                        4
#define ATI2S_I2S_IRQM1__PP0_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP0_OF__MASK                               0x00000010U
#define ATI2S_I2S_IRQM1__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQM1__PP0_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define ATI2S_I2S_IRQM1__PP0_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define ATI2S_I2S_IRQM1__PP0_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define ATI2S_I2S_IRQM1__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQM1__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQM1__PP0_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 1 buffer 1 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP1_OF__SHIFT                                        5
#define ATI2S_I2S_IRQM1__PP1_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP1_OF__MASK                               0x00000020U
#define ATI2S_I2S_IRQM1__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQM1__PP1_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define ATI2S_I2S_IRQM1__PP1_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define ATI2S_I2S_IRQM1__PP1_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define ATI2S_I2S_IRQM1__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQM1__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQM1__PP1_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 1 buffer 2 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP2_OF__SHIFT                                        6
#define ATI2S_I2S_IRQM1__PP2_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP2_OF__MASK                               0x00000040U
#define ATI2S_I2S_IRQM1__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQM1__PP2_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define ATI2S_I2S_IRQM1__PP2_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define ATI2S_I2S_IRQM1__PP2_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define ATI2S_I2S_IRQM1__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQM1__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQM1__PP2_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 1 buffer 3 over flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP3_OF__SHIFT                                        7
#define ATI2S_I2S_IRQM1__PP3_OF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP3_OF__MASK                               0x00000080U
#define ATI2S_I2S_IRQM1__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQM1__PP3_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define ATI2S_I2S_IRQM1__PP3_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define ATI2S_I2S_IRQM1__PP3_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define ATI2S_I2S_IRQM1__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQM1__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQM1__PP3_OF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 1 buffer 0 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP0_UF__SHIFT                                        8
#define ATI2S_I2S_IRQM1__PP0_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP0_UF__MASK                               0x00000100U
#define ATI2S_I2S_IRQM1__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQM1__PP0_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define ATI2S_I2S_IRQM1__PP0_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define ATI2S_I2S_IRQM1__PP0_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define ATI2S_I2S_IRQM1__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQM1__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQM1__PP0_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 1 buffer 1 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP1_UF__SHIFT                                        9
#define ATI2S_I2S_IRQM1__PP1_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP1_UF__MASK                               0x00000200U
#define ATI2S_I2S_IRQM1__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQM1__PP1_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define ATI2S_I2S_IRQM1__PP1_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define ATI2S_I2S_IRQM1__PP1_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define ATI2S_I2S_IRQM1__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQM1__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQM1__PP1_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 1 buffer 2 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP2_UF__SHIFT                                       10
#define ATI2S_I2S_IRQM1__PP2_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP2_UF__MASK                               0x00000400U
#define ATI2S_I2S_IRQM1__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQM1__PP2_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define ATI2S_I2S_IRQM1__PP2_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define ATI2S_I2S_IRQM1__PP2_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define ATI2S_I2S_IRQM1__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQM1__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQM1__PP2_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 1 buffer 3 under flow mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP3_UF__SHIFT                                       11
#define ATI2S_I2S_IRQM1__PP3_UF__WIDTH                                        1
#define ATI2S_I2S_IRQM1__PP3_UF__MASK                               0x00000800U
#define ATI2S_I2S_IRQM1__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQM1__PP3_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define ATI2S_I2S_IRQM1__PP3_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define ATI2S_I2S_IRQM1__PP3_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define ATI2S_I2S_IRQM1__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQM1__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQM1__PP3_UF__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit mask
 * @{
 */
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__SHIFT                                12
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__WIDTH                                 1
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__MASK                        0x00001000U
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQM1__PP_EP_THRSHLD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid mask
 * @{
 */
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__SHIFT                               13
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__WIDTH                                1
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__MASK                       0x00002000U
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQM1__INTRP_DOUT_VLD__RESET_VALUE                0x00000000U
/** @} */
#define ATI2S_I2S_IRQM1__TYPE                                          uint32_t
#define ATI2S_I2S_IRQM1__READ                                       0x00003fffU
#define ATI2S_I2S_IRQM1__WRITE                                      0x00003fffU
#define ATI2S_I2S_IRQM1__PRESERVED                                  0x00000000U
#define ATI2S_I2S_IRQM1__RESET_VALUE                                0x00000fffU

#endif /* __ATI2S_I2S_IRQM1_MACRO__ */

/** @} end of i2s_irqm1 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irqs1 */
/**
 * @defgroup at_i2s_regs_core_i2s_irqs1 i2s_irqs1
 * @brief Contains register fields associated with i2s_irqs1. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQS1_MACRO__
#define __ATI2S_I2S_IRQS1_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 1 buffer 0 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP0_FL__SHIFT                                        0
#define ATI2S_I2S_IRQS1__PP0_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP0_FL__MASK                               0x00000001U
#define ATI2S_I2S_IRQS1__PP0_FL__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQS1__PP0_FL__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQS1__PP0_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_IRQS1__PP0_FL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_IRQS1__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQS1__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQS1__PP0_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 1 buffer 1 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP1_FL__SHIFT                                        1
#define ATI2S_I2S_IRQS1__PP1_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP1_FL__MASK                               0x00000002U
#define ATI2S_I2S_IRQS1__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQS1__PP1_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_IRQS1__PP1_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_IRQS1__PP1_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_IRQS1__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQS1__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQS1__PP1_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 1 buffer 2 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP2_FL__SHIFT                                        2
#define ATI2S_I2S_IRQS1__PP2_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP2_FL__MASK                               0x00000004U
#define ATI2S_I2S_IRQS1__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQS1__PP2_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_IRQS1__PP2_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_IRQS1__PP2_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_IRQS1__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQS1__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQS1__PP2_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 1 buffer 3 full set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP3_FL__SHIFT                                        3
#define ATI2S_I2S_IRQS1__PP3_FL__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP3_FL__MASK                               0x00000008U
#define ATI2S_I2S_IRQS1__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQS1__PP3_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define ATI2S_I2S_IRQS1__PP3_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define ATI2S_I2S_IRQS1__PP3_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define ATI2S_I2S_IRQS1__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQS1__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQS1__PP3_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 1 buffer 0 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP0_OF__SHIFT                                        4
#define ATI2S_I2S_IRQS1__PP0_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP0_OF__MASK                               0x00000010U
#define ATI2S_I2S_IRQS1__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQS1__PP0_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define ATI2S_I2S_IRQS1__PP0_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define ATI2S_I2S_IRQS1__PP0_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define ATI2S_I2S_IRQS1__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQS1__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQS1__PP0_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 1 buffer 1 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP1_OF__SHIFT                                        5
#define ATI2S_I2S_IRQS1__PP1_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP1_OF__MASK                               0x00000020U
#define ATI2S_I2S_IRQS1__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQS1__PP1_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define ATI2S_I2S_IRQS1__PP1_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define ATI2S_I2S_IRQS1__PP1_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define ATI2S_I2S_IRQS1__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQS1__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQS1__PP1_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 1 buffer 2 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP2_OF__SHIFT                                        6
#define ATI2S_I2S_IRQS1__PP2_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP2_OF__MASK                               0x00000040U
#define ATI2S_I2S_IRQS1__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQS1__PP2_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define ATI2S_I2S_IRQS1__PP2_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define ATI2S_I2S_IRQS1__PP2_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define ATI2S_I2S_IRQS1__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQS1__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQS1__PP2_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 1 buffer 3 over flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP3_OF__SHIFT                                        7
#define ATI2S_I2S_IRQS1__PP3_OF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP3_OF__MASK                               0x00000080U
#define ATI2S_I2S_IRQS1__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQS1__PP3_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define ATI2S_I2S_IRQS1__PP3_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define ATI2S_I2S_IRQS1__PP3_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define ATI2S_I2S_IRQS1__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQS1__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQS1__PP3_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 1 buffer 0 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP0_UF__SHIFT                                        8
#define ATI2S_I2S_IRQS1__PP0_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP0_UF__MASK                               0x00000100U
#define ATI2S_I2S_IRQS1__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQS1__PP0_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define ATI2S_I2S_IRQS1__PP0_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define ATI2S_I2S_IRQS1__PP0_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define ATI2S_I2S_IRQS1__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQS1__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQS1__PP0_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 1 buffer 1 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP1_UF__SHIFT                                        9
#define ATI2S_I2S_IRQS1__PP1_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP1_UF__MASK                               0x00000200U
#define ATI2S_I2S_IRQS1__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQS1__PP1_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define ATI2S_I2S_IRQS1__PP1_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define ATI2S_I2S_IRQS1__PP1_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define ATI2S_I2S_IRQS1__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQS1__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQS1__PP1_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 1 buffer 2 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP2_UF__SHIFT                                       10
#define ATI2S_I2S_IRQS1__PP2_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP2_UF__MASK                               0x00000400U
#define ATI2S_I2S_IRQS1__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQS1__PP2_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define ATI2S_I2S_IRQS1__PP2_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define ATI2S_I2S_IRQS1__PP2_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define ATI2S_I2S_IRQS1__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQS1__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQS1__PP2_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 1 buffer 3 under flow set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP3_UF__SHIFT                                       11
#define ATI2S_I2S_IRQS1__PP3_UF__WIDTH                                        1
#define ATI2S_I2S_IRQS1__PP3_UF__MASK                               0x00000800U
#define ATI2S_I2S_IRQS1__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQS1__PP3_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define ATI2S_I2S_IRQS1__PP3_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define ATI2S_I2S_IRQS1__PP3_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define ATI2S_I2S_IRQS1__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQS1__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQS1__PP3_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__SHIFT                                12
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__WIDTH                                 1
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__MASK                        0x00001000U
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQS1__PP_EP_THRSHLD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid set. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__SHIFT                               13
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__WIDTH                                1
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__MASK                       0x00002000U
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQS1__INTRP_DOUT_VLD__RESET_VALUE                0x00000000U
/** @} */
#define ATI2S_I2S_IRQS1__TYPE                                          uint32_t
#define ATI2S_I2S_IRQS1__READ                                       0x00003fffU
#define ATI2S_I2S_IRQS1__WRITE                                      0x00003fffU
#define ATI2S_I2S_IRQS1__PRESERVED                                  0x00000000U
#define ATI2S_I2S_IRQS1__RESET_VALUE                                0x00000000U

#endif /* __ATI2S_I2S_IRQS1_MACRO__ */

/** @} end of i2s_irqs1 */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_irqc1 */
/**
 * @defgroup at_i2s_regs_core_i2s_irqc1 i2s_irqc1
 * @brief Contains register fields associated with i2s_irqc1. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_IRQC1_MACRO__
#define __ATI2S_I2S_IRQC1_MACRO__

/* macros for field pp0_fl */
/**
 * @defgroup at_i2s_regs_core_pp0_fl_field pp0_fl_field
 * @brief macros for field pp0_fl
 * @details ping pong set 1 buffer 0 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP0_FL__SHIFT                                        0
#define ATI2S_I2S_IRQC1__PP0_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP0_FL__MASK                               0x00000001U
#define ATI2S_I2S_IRQC1__PP0_FL__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQC1__PP0_FL__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define ATI2S_I2S_IRQC1__PP0_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define ATI2S_I2S_IRQC1__PP0_FL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define ATI2S_I2S_IRQC1__PP0_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define ATI2S_I2S_IRQC1__PP0_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define ATI2S_I2S_IRQC1__PP0_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_fl */
/**
 * @defgroup at_i2s_regs_core_pp1_fl_field pp1_fl_field
 * @brief macros for field pp1_fl
 * @details ping pong set 1 buffer 1 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP1_FL__SHIFT                                        1
#define ATI2S_I2S_IRQC1__PP1_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP1_FL__MASK                               0x00000002U
#define ATI2S_I2S_IRQC1__PP1_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define ATI2S_I2S_IRQC1__PP1_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define ATI2S_I2S_IRQC1__PP1_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define ATI2S_I2S_IRQC1__PP1_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define ATI2S_I2S_IRQC1__PP1_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define ATI2S_I2S_IRQC1__PP1_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define ATI2S_I2S_IRQC1__PP1_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_fl */
/**
 * @defgroup at_i2s_regs_core_pp2_fl_field pp2_fl_field
 * @brief macros for field pp2_fl
 * @details ping pong set 1 buffer 2 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP2_FL__SHIFT                                        2
#define ATI2S_I2S_IRQC1__PP2_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP2_FL__MASK                               0x00000004U
#define ATI2S_I2S_IRQC1__PP2_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define ATI2S_I2S_IRQC1__PP2_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define ATI2S_I2S_IRQC1__PP2_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define ATI2S_I2S_IRQC1__PP2_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define ATI2S_I2S_IRQC1__PP2_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define ATI2S_I2S_IRQC1__PP2_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define ATI2S_I2S_IRQC1__PP2_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_fl */
/**
 * @defgroup at_i2s_regs_core_pp3_fl_field pp3_fl_field
 * @brief macros for field pp3_fl
 * @details ping pong set 1 buffer 3 full clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP3_FL__SHIFT                                        3
#define ATI2S_I2S_IRQC1__PP3_FL__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP3_FL__MASK                               0x00000008U
#define ATI2S_I2S_IRQC1__PP3_FL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define ATI2S_I2S_IRQC1__PP3_FL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define ATI2S_I2S_IRQC1__PP3_FL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define ATI2S_I2S_IRQC1__PP3_FL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define ATI2S_I2S_IRQC1__PP3_FL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define ATI2S_I2S_IRQC1__PP3_FL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define ATI2S_I2S_IRQC1__PP3_FL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_of */
/**
 * @defgroup at_i2s_regs_core_pp0_of_field pp0_of_field
 * @brief macros for field pp0_of
 * @details ping pong set 1 buffer 0 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP0_OF__SHIFT                                        4
#define ATI2S_I2S_IRQC1__PP0_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP0_OF__MASK                               0x00000010U
#define ATI2S_I2S_IRQC1__PP0_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define ATI2S_I2S_IRQC1__PP0_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define ATI2S_I2S_IRQC1__PP0_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define ATI2S_I2S_IRQC1__PP0_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define ATI2S_I2S_IRQC1__PP0_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define ATI2S_I2S_IRQC1__PP0_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define ATI2S_I2S_IRQC1__PP0_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_of */
/**
 * @defgroup at_i2s_regs_core_pp1_of_field pp1_of_field
 * @brief macros for field pp1_of
 * @details ping pong set 1 buffer 1 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP1_OF__SHIFT                                        5
#define ATI2S_I2S_IRQC1__PP1_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP1_OF__MASK                               0x00000020U
#define ATI2S_I2S_IRQC1__PP1_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define ATI2S_I2S_IRQC1__PP1_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define ATI2S_I2S_IRQC1__PP1_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define ATI2S_I2S_IRQC1__PP1_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define ATI2S_I2S_IRQC1__PP1_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define ATI2S_I2S_IRQC1__PP1_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define ATI2S_I2S_IRQC1__PP1_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_of */
/**
 * @defgroup at_i2s_regs_core_pp2_of_field pp2_of_field
 * @brief macros for field pp2_of
 * @details ping pong set 1 buffer 2 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP2_OF__SHIFT                                        6
#define ATI2S_I2S_IRQC1__PP2_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP2_OF__MASK                               0x00000040U
#define ATI2S_I2S_IRQC1__PP2_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define ATI2S_I2S_IRQC1__PP2_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define ATI2S_I2S_IRQC1__PP2_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define ATI2S_I2S_IRQC1__PP2_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define ATI2S_I2S_IRQC1__PP2_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define ATI2S_I2S_IRQC1__PP2_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define ATI2S_I2S_IRQC1__PP2_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_of */
/**
 * @defgroup at_i2s_regs_core_pp3_of_field pp3_of_field
 * @brief macros for field pp3_of
 * @details ping pong set 1 buffer 3 over flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP3_OF__SHIFT                                        7
#define ATI2S_I2S_IRQC1__PP3_OF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP3_OF__MASK                               0x00000080U
#define ATI2S_I2S_IRQC1__PP3_OF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define ATI2S_I2S_IRQC1__PP3_OF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define ATI2S_I2S_IRQC1__PP3_OF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define ATI2S_I2S_IRQC1__PP3_OF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define ATI2S_I2S_IRQC1__PP3_OF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define ATI2S_I2S_IRQC1__PP3_OF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define ATI2S_I2S_IRQC1__PP3_OF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp0_uf */
/**
 * @defgroup at_i2s_regs_core_pp0_uf_field pp0_uf_field
 * @brief macros for field pp0_uf
 * @details ping pong set 1 buffer 0 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP0_UF__SHIFT                                        8
#define ATI2S_I2S_IRQC1__PP0_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP0_UF__MASK                               0x00000100U
#define ATI2S_I2S_IRQC1__PP0_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define ATI2S_I2S_IRQC1__PP0_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define ATI2S_I2S_IRQC1__PP0_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define ATI2S_I2S_IRQC1__PP0_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define ATI2S_I2S_IRQC1__PP0_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define ATI2S_I2S_IRQC1__PP0_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define ATI2S_I2S_IRQC1__PP0_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp1_uf */
/**
 * @defgroup at_i2s_regs_core_pp1_uf_field pp1_uf_field
 * @brief macros for field pp1_uf
 * @details ping pong set 1 buffer 1 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP1_UF__SHIFT                                        9
#define ATI2S_I2S_IRQC1__PP1_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP1_UF__MASK                               0x00000200U
#define ATI2S_I2S_IRQC1__PP1_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define ATI2S_I2S_IRQC1__PP1_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define ATI2S_I2S_IRQC1__PP1_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define ATI2S_I2S_IRQC1__PP1_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define ATI2S_I2S_IRQC1__PP1_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define ATI2S_I2S_IRQC1__PP1_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define ATI2S_I2S_IRQC1__PP1_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp2_uf */
/**
 * @defgroup at_i2s_regs_core_pp2_uf_field pp2_uf_field
 * @brief macros for field pp2_uf
 * @details ping pong set 1 buffer 2 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP2_UF__SHIFT                                       10
#define ATI2S_I2S_IRQC1__PP2_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP2_UF__MASK                               0x00000400U
#define ATI2S_I2S_IRQC1__PP2_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define ATI2S_I2S_IRQC1__PP2_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define ATI2S_I2S_IRQC1__PP2_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define ATI2S_I2S_IRQC1__PP2_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define ATI2S_I2S_IRQC1__PP2_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define ATI2S_I2S_IRQC1__PP2_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define ATI2S_I2S_IRQC1__PP2_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp3_uf */
/**
 * @defgroup at_i2s_regs_core_pp3_uf_field pp3_uf_field
 * @brief macros for field pp3_uf
 * @details ping pong set 1 buffer 3 under flow clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP3_UF__SHIFT                                       11
#define ATI2S_I2S_IRQC1__PP3_UF__WIDTH                                        1
#define ATI2S_I2S_IRQC1__PP3_UF__MASK                               0x00000800U
#define ATI2S_I2S_IRQC1__PP3_UF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define ATI2S_I2S_IRQC1__PP3_UF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define ATI2S_I2S_IRQC1__PP3_UF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define ATI2S_I2S_IRQC1__PP3_UF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define ATI2S_I2S_IRQC1__PP3_UF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define ATI2S_I2S_IRQC1__PP3_UF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define ATI2S_I2S_IRQC1__PP3_UF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pp_ep_thrshld */
/**
 * @defgroup at_i2s_regs_core_pp_ep_thrshld_field pp_ep_thrshld_field
 * @brief macros for field pp_ep_thrshld
 * @details ping pong buffer empty threshold hit clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__SHIFT                                12
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__WIDTH                                 1
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__MASK                        0x00001000U
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define ATI2S_I2S_IRQC1__PP_EP_THRSHLD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field intrp_dout_vld */
/**
 * @defgroup at_i2s_regs_core_intrp_dout_vld_field intrp_dout_vld_field
 * @brief macros for field intrp_dout_vld
 * @details interpolator data valid clear. (__SELF_CLEARING__)
 * @{
 */
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__SHIFT                               13
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__WIDTH                                1
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__MASK                       0x00002000U
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define ATI2S_I2S_IRQC1__INTRP_DOUT_VLD__RESET_VALUE                0x00000000U
/** @} */
#define ATI2S_I2S_IRQC1__TYPE                                          uint32_t
#define ATI2S_I2S_IRQC1__READ                                       0x00003fffU
#define ATI2S_I2S_IRQC1__WRITE                                      0x00003fffU
#define ATI2S_I2S_IRQC1__PRESERVED                                  0x00000000U
#define ATI2S_I2S_IRQC1__RESET_VALUE                                0x00000000U

#endif /* __ATI2S_I2S_IRQC1_MACRO__ */

/** @} end of i2s_irqc1 */

/* macros for BlueprintGlobalNameSpace::ATI2S_buffer_depth */
/**
 * @defgroup at_i2s_regs_core_buffer_depth buffer_depth
 * @brief Contains register fields associated with buffer_depth. definitions.
 * @{
 */
#ifndef __ATI2S_BUFFER_DEPTH_MACRO__
#define __ATI2S_BUFFER_DEPTH_MACRO__

/* macros for field depth */
/**
 * @defgroup at_i2s_regs_core_depth_field depth_field
 * @brief macros for field depth
 * @details one buffer depth
 * @{
 */
#define ATI2S_BUFFER_DEPTH__DEPTH__SHIFT                                      0
#define ATI2S_BUFFER_DEPTH__DEPTH__WIDTH                                      5
#define ATI2S_BUFFER_DEPTH__DEPTH__MASK                             0x0000001fU
#define ATI2S_BUFFER_DEPTH__DEPTH__READ(src)    ((uint32_t)(src) & 0x0000001fU)
#define ATI2S_BUFFER_DEPTH__DEPTH__RESET_VALUE                      0x00000010U
/** @} */
#define ATI2S_BUFFER_DEPTH__TYPE                                       uint32_t
#define ATI2S_BUFFER_DEPTH__READ                                    0x0000001fU
#define ATI2S_BUFFER_DEPTH__PRESERVED                               0x00000000U
#define ATI2S_BUFFER_DEPTH__RESET_VALUE                             0x00000010U

#endif /* __ATI2S_BUFFER_DEPTH_MACRO__ */

/** @} end of buffer_depth */

/* macros for BlueprintGlobalNameSpace::ATI2S_pp_st */
/**
 * @defgroup at_i2s_regs_core_pp_st pp_st
 * @brief Contains register fields associated with pp_st. definitions.
 * @{
 */
#ifndef __ATI2S_PP_ST_MACRO__
#define __ATI2S_PP_ST_MACRO__

/* macros for field pp0_ep_cnt */
/**
 * @defgroup at_i2s_regs_core_pp0_ep_cnt_field pp0_ep_cnt_field
 * @brief macros for field pp0_ep_cnt
 * @details number of empty slot in ping pong set 0.
 * @{
 */
#define ATI2S_PP_ST__PP0_EP_CNT__SHIFT                                        0
#define ATI2S_PP_ST__PP0_EP_CNT__WIDTH                                        6
#define ATI2S_PP_ST__PP0_EP_CNT__MASK                               0x0000003fU
#define ATI2S_PP_ST__PP0_EP_CNT__READ(src)      ((uint32_t)(src) & 0x0000003fU)
#define ATI2S_PP_ST__PP0_EP_CNT__RESET_VALUE                        0x00000010U
/** @} */

/* macros for field pp1_ep_cnt */
/**
 * @defgroup at_i2s_regs_core_pp1_ep_cnt_field pp1_ep_cnt_field
 * @brief macros for field pp1_ep_cnt
 * @details number of empty slot in ping pong set 1.
 * @{
 */
#define ATI2S_PP_ST__PP1_EP_CNT__SHIFT                                        8
#define ATI2S_PP_ST__PP1_EP_CNT__WIDTH                                        6
#define ATI2S_PP_ST__PP1_EP_CNT__MASK                               0x00003f00U
#define ATI2S_PP_ST__PP1_EP_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define ATI2S_PP_ST__PP1_EP_CNT__RESET_VALUE                        0x00000010U
/** @} */
#define ATI2S_PP_ST__TYPE                                              uint32_t
#define ATI2S_PP_ST__READ                                           0x00003f3fU
#define ATI2S_PP_ST__PRESERVED                                      0x00000000U
#define ATI2S_PP_ST__RESET_VALUE                                    0x00001010U

#endif /* __ATI2S_PP_ST_MACRO__ */

/** @} end of pp_st */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_spare */
/**
 * @defgroup at_i2s_regs_core_i2s_spare i2s_spare
 * @brief Contains register fields associated with i2s_spare. definitions.
 * @{
 */
#ifndef __ATI2S_I2S_SPARE_MACRO__
#define __ATI2S_I2S_SPARE_MACRO__

/* macros for field val */
/**
 * @defgroup at_i2s_regs_core_val_field val_field
 * @brief macros for field val
 * @details spare bits
 * @{
 */
#define ATI2S_I2S_SPARE__VAL__SHIFT                                           0
#define ATI2S_I2S_SPARE__VAL__WIDTH                                          32
#define ATI2S_I2S_SPARE__VAL__MASK                                  0xffffffffU
#define ATI2S_I2S_SPARE__VAL__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define ATI2S_I2S_SPARE__VAL__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define ATI2S_I2S_SPARE__VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define ATI2S_I2S_SPARE__VAL__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define ATI2S_I2S_SPARE__VAL__RESET_VALUE                           0x00000000U
/** @} */
#define ATI2S_I2S_SPARE__TYPE                                          uint32_t
#define ATI2S_I2S_SPARE__READ                                       0xffffffffU
#define ATI2S_I2S_SPARE__WRITE                                      0xffffffffU
#define ATI2S_I2S_SPARE__PRESERVED                                  0x00000000U
#define ATI2S_I2S_SPARE__RESET_VALUE                                0x00000000U

#endif /* __ATI2S_I2S_SPARE_MACRO__ */

/** @} end of i2s_spare */

/* macros for BlueprintGlobalNameSpace::ATI2S_i2s_dbg */
/**
 * @defgroup at_i2s_regs_core_i2s_dbg i2s_dbg
 * @brief Expose debug signals on mdm_out definitions.
 * @{
 */
#ifndef __ATI2S_I2S_DBG_MACRO__
#define __ATI2S_I2S_DBG_MACRO__

/* macros for field sel */
/**
 * @defgroup at_i2s_regs_core_sel_field sel_field
 * @brief macros for field sel
 * @details 0123456
 * @{
 */
#define ATI2S_I2S_DBG__SEL__SHIFT                                             0
#define ATI2S_I2S_DBG__SEL__WIDTH                                             6
#define ATI2S_I2S_DBG__SEL__MASK                                    0x0000003fU
#define ATI2S_I2S_DBG__SEL__READ(src)           ((uint32_t)(src) & 0x0000003fU)
#define ATI2S_I2S_DBG__SEL__WRITE(src)          ((uint32_t)(src) & 0x0000003fU)
#define ATI2S_I2S_DBG__SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define ATI2S_I2S_DBG__SEL__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000003fU)))
#define ATI2S_I2S_DBG__SEL__RESET_VALUE                             0x00000000U
/** @} */
#define ATI2S_I2S_DBG__TYPE                                            uint32_t
#define ATI2S_I2S_DBG__READ                                         0x0000003fU
#define ATI2S_I2S_DBG__WRITE                                        0x0000003fU
#define ATI2S_I2S_DBG__PRESERVED                                    0x00000000U
#define ATI2S_I2S_DBG__RESET_VALUE                                  0x00000000U

#endif /* __ATI2S_I2S_DBG_MACRO__ */

/** @} end of i2s_dbg */

/* macros for BlueprintGlobalNameSpace::ATI2S_id */
/**
 * @defgroup at_i2s_regs_core_id id
 * @brief Contains register fields associated with id. definitions.
 * @{
 */
#ifndef __ATI2S_ID_MACRO__
#define __ATI2S_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_i2s_regs_core_id_field id_field
 * @brief macros for field id
 * @details 'I2S' in ASCII
 * @{
 */
#define ATI2S_ID__ID__SHIFT                                                   0
#define ATI2S_ID__ID__WIDTH                                                  32
#define ATI2S_ID__ID__MASK                                          0xffffffffU
#define ATI2S_ID__ID__READ(src)                 ((uint32_t)(src) & 0xffffffffU)
#define ATI2S_ID__ID__RESET_VALUE                                   0x49325320U
/** @} */
#define ATI2S_ID__TYPE                                                 uint32_t
#define ATI2S_ID__READ                                              0xffffffffU
#define ATI2S_ID__PRESERVED                                         0x00000000U
#define ATI2S_ID__RESET_VALUE                                       0x49325320U

#endif /* __ATI2S_ID_MACRO__ */

/** @} end of id */

/* macros for BlueprintGlobalNameSpace::ATI2S_rev_hash */
/**
 * @defgroup at_i2s_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __ATI2S_REV_HASH_MACRO__
#define __ATI2S_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_i2s_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define ATI2S_REV_HASH__ID__SHIFT                                             0
#define ATI2S_REV_HASH__ID__WIDTH                                            32
#define ATI2S_REV_HASH__ID__MASK                                    0xffffffffU
#define ATI2S_REV_HASH__ID__READ(src)           ((uint32_t)(src) & 0xffffffffU)
#define ATI2S_REV_HASH__ID__RESET_VALUE                             0xa0e2205cU
/** @} */
#define ATI2S_REV_HASH__TYPE                                           uint32_t
#define ATI2S_REV_HASH__READ                                        0xffffffffU
#define ATI2S_REV_HASH__PRESERVED                                   0x00000000U
#define ATI2S_REV_HASH__RESET_VALUE                                 0xa0e2205cU

#endif /* __ATI2S_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::ATI2S_rev_key */
/**
 * @defgroup at_i2s_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __ATI2S_REV_KEY_MACRO__
#define __ATI2S_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_i2s_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define ATI2S_REV_KEY__ID__SHIFT                                              0
#define ATI2S_REV_KEY__ID__WIDTH                                             32
#define ATI2S_REV_KEY__ID__MASK                                     0xffffffffU
#define ATI2S_REV_KEY__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define ATI2S_REV_KEY__ID__RESET_VALUE                              0x52455620U
/** @} */
#define ATI2S_REV_KEY__TYPE                                            uint32_t
#define ATI2S_REV_KEY__READ                                         0xffffffffU
#define ATI2S_REV_KEY__PRESERVED                                    0x00000000U
#define ATI2S_REV_KEY__RESET_VALUE                                  0x52455620U

#endif /* __ATI2S_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_I2S_REGS_CORE */
#endif /* __REG_AT_I2S_REGS_CORE_H__ */
