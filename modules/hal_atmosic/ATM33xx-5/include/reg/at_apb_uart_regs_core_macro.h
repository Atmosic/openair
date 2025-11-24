/*                                                                           */
/* File:       at_apb_uart_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_uart_regs_core.rdl          */
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


#ifndef __REG_AT_APB_UART_REGS_CORE_H__
#define __REG_AT_APB_UART_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_UART_REGS_CORE at_apb_uart_regs_core
 * @ingroup AT_REG
 * @brief at_apb_uart_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_DATA */
/**
 * @defgroup at_apb_uart_regs_core_DATA DATA
 * @brief Contains register fields associated with DATA. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_DATA_MACRO__
#define __CMSDK_AT_UART_DATA_MACRO__

/* macros for field Data */
/**
 * @defgroup at_apb_uart_regs_core_Data_field Data_field
 * @brief macros for field Data
 * @details Read Received data. Write Transmit data.
 * @{
 */
#define CMSDK_AT_UART_DATA__DATA__SHIFT                                       0
#define CMSDK_AT_UART_DATA__DATA__WIDTH                                       8
#define CMSDK_AT_UART_DATA__DATA__MASK                              0x000000ffU
#define CMSDK_AT_UART_DATA_Pos                  CMSDK_AT_UART_DATA__DATA__SHIFT
#define CMSDK_AT_UART_DATA_Msk                   CMSDK_AT_UART_DATA__DATA__MASK
#define CMSDK_UART_DATA_Pos                     CMSDK_AT_UART_DATA__DATA__SHIFT
#define CMSDK_UART_DATA_Msk                      CMSDK_AT_UART_DATA__DATA__MASK
#define CMSDK_AT_UART_DATA__DATA__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_DATA__DATA__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_DATA__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define CMSDK_AT_UART_DATA__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define CMSDK_AT_UART_DATA__DATA__RESET_VALUE                       0x00000000U
/** @} */
#define CMSDK_AT_UART_DATA__TYPE                                       uint32_t
#define CMSDK_AT_UART_DATA__READ                                    0x000000ffU
#define CMSDK_AT_UART_DATA__WRITE                                   0x000000ffU
#define CMSDK_AT_UART_DATA__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_DATA__RESET_VALUE                             0x00000000U

#endif /* __CMSDK_AT_UART_DATA_MACRO__ */

/** @} end of DATA */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_STATE */
/**
 * @defgroup at_apb_uart_regs_core_STATE STATE
 * @brief Contains register fields associated with STATE. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_STATE_MACRO__
#define __CMSDK_AT_UART_STATE_MACRO__

/* macros for field tx_buf_full */
/**
 * @defgroup at_apb_uart_regs_core_tx_buf_full_field tx_buf_full_field
 * @brief macros for field tx_buf_full
 * @details TX buffer full, read-only.
 * @{
 */
#define CMSDK_AT_UART_STATE__TXBF__SHIFT                                      0
#define CMSDK_AT_UART_STATE__TXBF__WIDTH                                      1
#define CMSDK_AT_UART_STATE__TXBF__MASK                             0x00000001U
#define CMSDK_AT_UART_STATE_TXBF_Pos           CMSDK_AT_UART_STATE__TXBF__SHIFT
#define CMSDK_AT_UART_STATE_TXBF_Msk            CMSDK_AT_UART_STATE__TXBF__MASK
#define CMSDK_UART_STATE_TXBF_Pos              CMSDK_AT_UART_STATE__TXBF__SHIFT
#define CMSDK_UART_STATE_TXBF_Msk               CMSDK_AT_UART_STATE__TXBF__MASK
#define CMSDK_AT_UART_STATE__TXBF__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define CMSDK_AT_UART_STATE__TXBF__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define CMSDK_AT_UART_STATE__TXBF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CMSDK_AT_UART_STATE__TXBF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CMSDK_AT_UART_STATE__TXBF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_STATE__TXBF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_STATE__TXBF__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field rx_buf_full */
/**
 * @defgroup at_apb_uart_regs_core_rx_buf_full_field rx_buf_full_field
 * @brief macros for field rx_buf_full
 * @details 1=RX buffer is not empty, 0= RX buffer is empty read-only.
 * @{
 */
#define CMSDK_AT_UART_STATE__RXBF__SHIFT                                      1
#define CMSDK_AT_UART_STATE__RXBF__WIDTH                                      1
#define CMSDK_AT_UART_STATE__RXBF__MASK                             0x00000002U
#define CMSDK_AT_UART_STATE_RXBF_Pos           CMSDK_AT_UART_STATE__RXBF__SHIFT
#define CMSDK_AT_UART_STATE_RXBF_Msk            CMSDK_AT_UART_STATE__RXBF__MASK
#define CMSDK_UART_STATE_RXBF_Pos              CMSDK_AT_UART_STATE__RXBF__SHIFT
#define CMSDK_UART_STATE_RXBF_Msk               CMSDK_AT_UART_STATE__RXBF__MASK
#define CMSDK_AT_UART_STATE__RXBF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CMSDK_AT_UART_STATE__RXBF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CMSDK_AT_UART_STATE__RXBF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CMSDK_AT_UART_STATE__RXBF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CMSDK_AT_UART_STATE__RXBF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CMSDK_AT_UART_STATE__RXBF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CMSDK_AT_UART_STATE__RXBF__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field tx_overrun */
/**
 * @defgroup at_apb_uart_regs_core_tx_overrun_field tx_overrun_field
 * @brief macros for field tx_overrun
 * @details TX buffer overrun, write 1 to clear.
 * @{
 */
#define CMSDK_AT_UART_STATE__TXOR__SHIFT                                      2
#define CMSDK_AT_UART_STATE__TXOR__WIDTH                                      1
#define CMSDK_AT_UART_STATE__TXOR__MASK                             0x00000004U
#define CMSDK_AT_UART_STATE_TXOR_Pos           CMSDK_AT_UART_STATE__TXOR__SHIFT
#define CMSDK_AT_UART_STATE_TXOR_Msk            CMSDK_AT_UART_STATE__TXOR__MASK
#define CMSDK_UART_STATE_TXOR_Pos              CMSDK_AT_UART_STATE__TXOR__SHIFT
#define CMSDK_UART_STATE_TXOR_Msk               CMSDK_AT_UART_STATE__TXOR__MASK
#define CMSDK_AT_UART_STATE__TXOR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CMSDK_AT_UART_STATE__TXOR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CMSDK_AT_UART_STATE__TXOR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CMSDK_AT_UART_STATE__TXOR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CMSDK_AT_UART_STATE__TXOR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CMSDK_AT_UART_STATE__TXOR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CMSDK_AT_UART_STATE__TXOR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field rx_overrun */
/**
 * @defgroup at_apb_uart_regs_core_rx_overrun_field rx_overrun_field
 * @brief macros for field rx_overrun
 * @details RX buffer overrun, write 1 to clear.
 * @{
 */
#define CMSDK_AT_UART_STATE__RXOR__SHIFT                                      3
#define CMSDK_AT_UART_STATE__RXOR__WIDTH                                      1
#define CMSDK_AT_UART_STATE__RXOR__MASK                             0x00000008U
#define CMSDK_AT_UART_STATE_RXOR_Pos           CMSDK_AT_UART_STATE__RXOR__SHIFT
#define CMSDK_AT_UART_STATE_RXOR_Msk            CMSDK_AT_UART_STATE__RXOR__MASK
#define CMSDK_UART_STATE_RXOR_Pos              CMSDK_AT_UART_STATE__RXOR__SHIFT
#define CMSDK_UART_STATE_RXOR_Msk               CMSDK_AT_UART_STATE__RXOR__MASK
#define CMSDK_AT_UART_STATE__RXOR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CMSDK_AT_UART_STATE__RXOR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CMSDK_AT_UART_STATE__RXOR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CMSDK_AT_UART_STATE__RXOR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CMSDK_AT_UART_STATE__RXOR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CMSDK_AT_UART_STATE__RXOR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CMSDK_AT_UART_STATE__RXOR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nUARTRTS */
/**
 * @defgroup at_apb_uart_regs_core_nUARTRTS_field nUARTRTS_field
 * @brief macros for field nUARTRTS
 * @details current status of nUARTRTS (Read only) // (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_STATE__NRTS__SHIFT                                      4
#define CMSDK_AT_UART_STATE__NRTS__WIDTH                                      1
#define CMSDK_AT_UART_STATE__NRTS__MASK                             0x00000010U
#define CMSDK_AT_UART_STATE_NRTS_Pos           CMSDK_AT_UART_STATE__NRTS__SHIFT
#define CMSDK_AT_UART_STATE_NRTS_Msk            CMSDK_AT_UART_STATE__NRTS__MASK
#define CMSDK_UART_STATE_NRTS_Pos              CMSDK_AT_UART_STATE__NRTS__SHIFT
#define CMSDK_UART_STATE_NRTS_Msk               CMSDK_AT_UART_STATE__NRTS__MASK
#define CMSDK_AT_UART_STATE__NRTS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CMSDK_AT_UART_STATE__NRTS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define CMSDK_AT_UART_STATE__NRTS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define CMSDK_AT_UART_STATE__NRTS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define CMSDK_AT_UART_STATE__NRTS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CMSDK_AT_UART_STATE__NRTS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CMSDK_AT_UART_STATE__NRTS__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field nUARTCTS */
/**
 * @defgroup at_apb_uart_regs_core_nUARTCTS_field nUARTCTS_field
 * @brief macros for field nUARTCTS
 * @details current status of nUARTCTS (Read only) // (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_STATE__NCTS__SHIFT                                      5
#define CMSDK_AT_UART_STATE__NCTS__WIDTH                                      1
#define CMSDK_AT_UART_STATE__NCTS__MASK                             0x00000020U
#define CMSDK_AT_UART_STATE_NCTS_Pos           CMSDK_AT_UART_STATE__NCTS__SHIFT
#define CMSDK_AT_UART_STATE_NCTS_Msk            CMSDK_AT_UART_STATE__NCTS__MASK
#define CMSDK_UART_STATE_NCTS_Pos              CMSDK_AT_UART_STATE__NCTS__SHIFT
#define CMSDK_UART_STATE_NCTS_Msk               CMSDK_AT_UART_STATE__NCTS__MASK
#define CMSDK_AT_UART_STATE__NCTS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define CMSDK_AT_UART_STATE__NCTS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define CMSDK_AT_UART_STATE__NCTS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define CMSDK_AT_UART_STATE__NCTS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define CMSDK_AT_UART_STATE__NCTS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define CMSDK_AT_UART_STATE__NCTS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define CMSDK_AT_UART_STATE__NCTS__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field stop_bit_err */
/**
 * @defgroup at_apb_uart_regs_core_stop_bit_err_field stop_bit_err_field
 * @brief macros for field stop_bit_err
 * @details 1=stop_bit err (Read only) // (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__SHIFT                              6
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__WIDTH                              1
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__MASK                     0x00000040U
#define CMSDK_AT_UART_STATE_STOP_BIT_ERR_Pos \
                    CMSDK_AT_UART_STATE__STOP_BIT_ERR__SHIFT
#define CMSDK_AT_UART_STATE_STOP_BIT_ERR_Msk \
                    CMSDK_AT_UART_STATE__STOP_BIT_ERR__MASK
#define CMSDK_UART_STATE_STOP_BIT_ERR_Pos \
                    CMSDK_AT_UART_STATE__STOP_BIT_ERR__SHIFT
#define CMSDK_UART_STATE_STOP_BIT_ERR_Msk \
                    CMSDK_AT_UART_STATE__STOP_BIT_ERR__MASK
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define CMSDK_AT_UART_STATE__STOP_BIT_ERR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field tx_idle */
/**
 * @defgroup at_apb_uart_regs_core_tx_idle_field tx_idle_field
 * @brief macros for field tx_idle
 * @details 1=tx state is idle (Read only) // (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_STATE__TX_IDLE__SHIFT                                   7
#define CMSDK_AT_UART_STATE__TX_IDLE__WIDTH                                   1
#define CMSDK_AT_UART_STATE__TX_IDLE__MASK                          0x00000080U
#define CMSDK_AT_UART_STATE_TX_IDLE_Pos     CMSDK_AT_UART_STATE__TX_IDLE__SHIFT
#define CMSDK_AT_UART_STATE_TX_IDLE_Msk      CMSDK_AT_UART_STATE__TX_IDLE__MASK
#define CMSDK_UART_STATE_TX_IDLE_Pos        CMSDK_AT_UART_STATE__TX_IDLE__SHIFT
#define CMSDK_UART_STATE_TX_IDLE_Msk         CMSDK_AT_UART_STATE__TX_IDLE__MASK
#define CMSDK_AT_UART_STATE__TX_IDLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define CMSDK_AT_UART_STATE__TX_IDLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define CMSDK_AT_UART_STATE__TX_IDLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define CMSDK_AT_UART_STATE__TX_IDLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define CMSDK_AT_UART_STATE__TX_IDLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define CMSDK_AT_UART_STATE__TX_IDLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define CMSDK_AT_UART_STATE__TX_IDLE__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field tx_locked_stat */
/**
 * @defgroup at_apb_uart_regs_core_tx_locked_stat_field tx_locked_stat_field
 * @brief macros for field tx_locked_stat
 * @details 1=(Sticky) indicates whether tx is locked. Once locked, it remains locked until a system reset. (Read only) // (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__SHIFT                            8
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__WIDTH                            1
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__MASK                   0x00000100U
#define CMSDK_AT_UART_STATE_TX_LOCKED_STAT_Pos \
                    CMSDK_AT_UART_STATE__TX_LOCKED_STAT__SHIFT
#define CMSDK_AT_UART_STATE_TX_LOCKED_STAT_Msk \
                    CMSDK_AT_UART_STATE__TX_LOCKED_STAT__MASK
#define CMSDK_UART_STATE_TX_LOCKED_STAT_Pos \
                    CMSDK_AT_UART_STATE__TX_LOCKED_STAT__SHIFT
#define CMSDK_UART_STATE_TX_LOCKED_STAT_Msk \
                    CMSDK_AT_UART_STATE__TX_LOCKED_STAT__MASK
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define CMSDK_AT_UART_STATE__TX_LOCKED_STAT__RESET_VALUE            0x00000000U
/** @} */
#define CMSDK_AT_UART_STATE__TYPE                                      uint32_t
#define CMSDK_AT_UART_STATE__READ                                   0x000001ffU
#define CMSDK_AT_UART_STATE__WRITE                                  0x000001ffU
#define CMSDK_AT_UART_STATE__PRESERVED                              0x00000000U
#define CMSDK_AT_UART_STATE__RESET_VALUE                            0x00000000U

#endif /* __CMSDK_AT_UART_STATE_MACRO__ */

/** @} end of STATE */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_CTRL */
/**
 * @defgroup at_apb_uart_regs_core_CTRL CTRL
 * @brief Contains register fields associated with CTRL. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_CTRL_MACRO__
#define __CMSDK_AT_UART_CTRL_MACRO__

/* macros for field TxEn */
/**
 * @defgroup at_apb_uart_regs_core_TxEn_field TxEn_field
 * @brief macros for field TxEn
 * @details TX enable.
 * @{
 */
#define CMSDK_AT_UART_CTRL__TXEN__SHIFT                                       0
#define CMSDK_AT_UART_CTRL__TXEN__WIDTH                                       1
#define CMSDK_AT_UART_CTRL__TXEN__MASK                              0x00000001U
#define CMSDK_AT_UART_CTRL_TXEN_Pos             CMSDK_AT_UART_CTRL__TXEN__SHIFT
#define CMSDK_AT_UART_CTRL_TXEN_Msk              CMSDK_AT_UART_CTRL__TXEN__MASK
#define CMSDK_UART_CTRL_TXEN_Pos                CMSDK_AT_UART_CTRL__TXEN__SHIFT
#define CMSDK_UART_CTRL_TXEN_Msk                 CMSDK_AT_UART_CTRL__TXEN__MASK
#define CMSDK_AT_UART_CTRL__TXEN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define CMSDK_AT_UART_CTRL__TXEN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define CMSDK_AT_UART_CTRL__TXEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CMSDK_AT_UART_CTRL__TXEN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CMSDK_AT_UART_CTRL__TXEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_CTRL__TXEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_CTRL__TXEN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field RxEn */
/**
 * @defgroup at_apb_uart_regs_core_RxEn_field RxEn_field
 * @brief macros for field RxEn
 * @details RX enable.
 * @{
 */
#define CMSDK_AT_UART_CTRL__RXEN__SHIFT                                       1
#define CMSDK_AT_UART_CTRL__RXEN__WIDTH                                       1
#define CMSDK_AT_UART_CTRL__RXEN__MASK                              0x00000002U
#define CMSDK_AT_UART_CTRL_RXEN_Pos             CMSDK_AT_UART_CTRL__RXEN__SHIFT
#define CMSDK_AT_UART_CTRL_RXEN_Msk              CMSDK_AT_UART_CTRL__RXEN__MASK
#define CMSDK_UART_CTRL_RXEN_Pos                CMSDK_AT_UART_CTRL__RXEN__SHIFT
#define CMSDK_UART_CTRL_RXEN_Msk                 CMSDK_AT_UART_CTRL__RXEN__MASK
#define CMSDK_AT_UART_CTRL__RXEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CMSDK_AT_UART_CTRL__RXEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CMSDK_AT_UART_CTRL__RXEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CMSDK_AT_UART_CTRL__RXEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CMSDK_AT_UART_CTRL__RXEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CMSDK_AT_UART_CTRL__RXEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CMSDK_AT_UART_CTRL__RXEN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field TxIntEn */
/**
 * @defgroup at_apb_uart_regs_core_TxIntEn_field TxIntEn_field
 * @brief macros for field TxIntEn
 * @details TX interrupt enable.
 * @{
 */
#define CMSDK_AT_UART_CTRL__TXIRQEN__SHIFT                                    2
#define CMSDK_AT_UART_CTRL__TXIRQEN__WIDTH                                    1
#define CMSDK_AT_UART_CTRL__TXIRQEN__MASK                           0x00000004U
#define CMSDK_AT_UART_CTRL_TXIRQEN_Pos       CMSDK_AT_UART_CTRL__TXIRQEN__SHIFT
#define CMSDK_AT_UART_CTRL_TXIRQEN_Msk        CMSDK_AT_UART_CTRL__TXIRQEN__MASK
#define CMSDK_UART_CTRL_TXIRQEN_Pos          CMSDK_AT_UART_CTRL__TXIRQEN__SHIFT
#define CMSDK_UART_CTRL_TXIRQEN_Msk           CMSDK_AT_UART_CTRL__TXIRQEN__MASK
#define CMSDK_AT_UART_CTRL__TXIRQEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CMSDK_AT_UART_CTRL__TXIRQEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CMSDK_AT_UART_CTRL__TXIRQEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CMSDK_AT_UART_CTRL__TXIRQEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CMSDK_AT_UART_CTRL__TXIRQEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CMSDK_AT_UART_CTRL__TXIRQEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CMSDK_AT_UART_CTRL__TXIRQEN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field RxIntEn */
/**
 * @defgroup at_apb_uart_regs_core_RxIntEn_field RxIntEn_field
 * @brief macros for field RxIntEn
 * @details RX interrupt enable.
 * @{
 */
#define CMSDK_AT_UART_CTRL__RXIRQEN__SHIFT                                    3
#define CMSDK_AT_UART_CTRL__RXIRQEN__WIDTH                                    1
#define CMSDK_AT_UART_CTRL__RXIRQEN__MASK                           0x00000008U
#define CMSDK_AT_UART_CTRL_RXIRQEN_Pos       CMSDK_AT_UART_CTRL__RXIRQEN__SHIFT
#define CMSDK_AT_UART_CTRL_RXIRQEN_Msk        CMSDK_AT_UART_CTRL__RXIRQEN__MASK
#define CMSDK_UART_CTRL_RXIRQEN_Pos          CMSDK_AT_UART_CTRL__RXIRQEN__SHIFT
#define CMSDK_UART_CTRL_RXIRQEN_Msk           CMSDK_AT_UART_CTRL__RXIRQEN__MASK
#define CMSDK_AT_UART_CTRL__RXIRQEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CMSDK_AT_UART_CTRL__RXIRQEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CMSDK_AT_UART_CTRL__RXIRQEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CMSDK_AT_UART_CTRL__RXIRQEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CMSDK_AT_UART_CTRL__RXIRQEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CMSDK_AT_UART_CTRL__RXIRQEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CMSDK_AT_UART_CTRL__RXIRQEN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field tx_overrun_int_en */
/**
 * @defgroup at_apb_uart_regs_core_tx_overrun_int_en_field tx_overrun_int_en_field
 * @brief macros for field tx_overrun_int_en
 * @details TX overrun interrupt enable.
 * @{
 */
#define CMSDK_AT_UART_CTRL__TXORIRQEN__SHIFT                                  4
#define CMSDK_AT_UART_CTRL__TXORIRQEN__WIDTH                                  1
#define CMSDK_AT_UART_CTRL__TXORIRQEN__MASK                         0x00000010U
#define CMSDK_AT_UART_CTRL_TXORIRQEN_Pos   CMSDK_AT_UART_CTRL__TXORIRQEN__SHIFT
#define CMSDK_AT_UART_CTRL_TXORIRQEN_Msk    CMSDK_AT_UART_CTRL__TXORIRQEN__MASK
#define CMSDK_UART_CTRL_TXORIRQEN_Pos      CMSDK_AT_UART_CTRL__TXORIRQEN__SHIFT
#define CMSDK_UART_CTRL_TXORIRQEN_Msk       CMSDK_AT_UART_CTRL__TXORIRQEN__MASK
#define CMSDK_AT_UART_CTRL__TXORIRQEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define CMSDK_AT_UART_CTRL__TXORIRQEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define CMSDK_AT_UART_CTRL__TXORIRQEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define CMSDK_AT_UART_CTRL__TXORIRQEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define CMSDK_AT_UART_CTRL__TXORIRQEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define CMSDK_AT_UART_CTRL__TXORIRQEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define CMSDK_AT_UART_CTRL__TXORIRQEN__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field rx_overrun_int_en */
/**
 * @defgroup at_apb_uart_regs_core_rx_overrun_int_en_field rx_overrun_int_en_field
 * @brief macros for field rx_overrun_int_en
 * @details RX overrun interrupt enable.
 * @{
 */
#define CMSDK_AT_UART_CTRL__RXORIRQEN__SHIFT                                  5
#define CMSDK_AT_UART_CTRL__RXORIRQEN__WIDTH                                  1
#define CMSDK_AT_UART_CTRL__RXORIRQEN__MASK                         0x00000020U
#define CMSDK_AT_UART_CTRL_RXORIRQEN_Pos   CMSDK_AT_UART_CTRL__RXORIRQEN__SHIFT
#define CMSDK_AT_UART_CTRL_RXORIRQEN_Msk    CMSDK_AT_UART_CTRL__RXORIRQEN__MASK
#define CMSDK_UART_CTRL_RXORIRQEN_Pos      CMSDK_AT_UART_CTRL__RXORIRQEN__SHIFT
#define CMSDK_UART_CTRL_RXORIRQEN_Msk       CMSDK_AT_UART_CTRL__RXORIRQEN__MASK
#define CMSDK_AT_UART_CTRL__RXORIRQEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define CMSDK_AT_UART_CTRL__RXORIRQEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define CMSDK_AT_UART_CTRL__RXORIRQEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define CMSDK_AT_UART_CTRL__RXORIRQEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define CMSDK_AT_UART_CTRL__RXORIRQEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define CMSDK_AT_UART_CTRL__RXORIRQEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define CMSDK_AT_UART_CTRL__RXORIRQEN__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field hs_testmode */
/**
 * @defgroup at_apb_uart_regs_core_hs_testmode_field hs_testmode_field
 * @brief macros for field hs_testmode
 * @details High-speed test mode for TX only.
 * @{
 */
#define CMSDK_AT_UART_CTRL__HSTM__SHIFT                                       6
#define CMSDK_AT_UART_CTRL__HSTM__WIDTH                                       1
#define CMSDK_AT_UART_CTRL__HSTM__MASK                              0x00000040U
#define CMSDK_AT_UART_CTRL_HSTM_Pos             CMSDK_AT_UART_CTRL__HSTM__SHIFT
#define CMSDK_AT_UART_CTRL_HSTM_Msk              CMSDK_AT_UART_CTRL__HSTM__MASK
#define CMSDK_UART_CTRL_HSTM_Pos                CMSDK_AT_UART_CTRL__HSTM__SHIFT
#define CMSDK_UART_CTRL_HSTM_Msk                 CMSDK_AT_UART_CTRL__HSTM__MASK
#define CMSDK_AT_UART_CTRL__HSTM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define CMSDK_AT_UART_CTRL__HSTM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define CMSDK_AT_UART_CTRL__HSTM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define CMSDK_AT_UART_CTRL__HSTM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define CMSDK_AT_UART_CTRL__HSTM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define CMSDK_AT_UART_CTRL__HSTM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define CMSDK_AT_UART_CTRL__HSTM__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field dma_mode_tx */
/**
 * @defgroup at_apb_uart_regs_core_dma_mode_tx_field dma_mode_tx_field
 * @brief macros for field dma_mode_tx
 * @details 1= dma can fill the tx fifo and the tx_intr is cleared when full or done.
 * @{
 */
#define CMSDK_AT_UART_CTRL__DMAMTX__SHIFT                                     7
#define CMSDK_AT_UART_CTRL__DMAMTX__WIDTH                                     1
#define CMSDK_AT_UART_CTRL__DMAMTX__MASK                            0x00000080U
#define CMSDK_AT_UART_CTRL_DMAMTX_Pos         CMSDK_AT_UART_CTRL__DMAMTX__SHIFT
#define CMSDK_AT_UART_CTRL_DMAMTX_Msk          CMSDK_AT_UART_CTRL__DMAMTX__MASK
#define CMSDK_UART_CTRL_DMAMTX_Pos            CMSDK_AT_UART_CTRL__DMAMTX__SHIFT
#define CMSDK_UART_CTRL_DMAMTX_Msk             CMSDK_AT_UART_CTRL__DMAMTX__MASK
#define CMSDK_AT_UART_CTRL__DMAMTX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define CMSDK_AT_UART_CTRL__DMAMTX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define CMSDK_AT_UART_CTRL__DMAMTX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define CMSDK_AT_UART_CTRL__DMAMTX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define CMSDK_AT_UART_CTRL__DMAMTX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define CMSDK_AT_UART_CTRL__DMAMTX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define CMSDK_AT_UART_CTRL__DMAMTX__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field dma_mode_rx */
/**
 * @defgroup at_apb_uart_regs_core_dma_mode_rx_field dma_mode_rx_field
 * @brief macros for field dma_mode_rx
 * @details 1= dma can drain the rx fifo and the rx_intr is cleared when empty
 * @{
 */
#define CMSDK_AT_UART_CTRL__DMAMRX__SHIFT                                     8
#define CMSDK_AT_UART_CTRL__DMAMRX__WIDTH                                     1
#define CMSDK_AT_UART_CTRL__DMAMRX__MASK                            0x00000100U
#define CMSDK_AT_UART_CTRL_DMAMRX_Pos         CMSDK_AT_UART_CTRL__DMAMRX__SHIFT
#define CMSDK_AT_UART_CTRL_DMAMRX_Msk          CMSDK_AT_UART_CTRL__DMAMRX__MASK
#define CMSDK_UART_CTRL_DMAMRX_Pos            CMSDK_AT_UART_CTRL__DMAMRX__SHIFT
#define CMSDK_UART_CTRL_DMAMRX_Msk             CMSDK_AT_UART_CTRL__DMAMRX__MASK
#define CMSDK_AT_UART_CTRL__DMAMRX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define CMSDK_AT_UART_CTRL__DMAMRX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define CMSDK_AT_UART_CTRL__DMAMRX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define CMSDK_AT_UART_CTRL__DMAMRX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define CMSDK_AT_UART_CTRL__DMAMRX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define CMSDK_AT_UART_CTRL__DMAMRX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define CMSDK_AT_UART_CTRL__DMAMRX__RESET_VALUE                     0x00000000U
/** @} */
#define CMSDK_AT_UART_CTRL__TYPE                                       uint32_t
#define CMSDK_AT_UART_CTRL__READ                                    0x000001ffU
#define CMSDK_AT_UART_CTRL__WRITE                                   0x000001ffU
#define CMSDK_AT_UART_CTRL__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_CTRL__RESET_VALUE                             0x00000000U

#endif /* __CMSDK_AT_UART_CTRL_MACRO__ */

/** @} end of CTRL */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_INTSTATUS_CLEAR */
/**
 * @defgroup at_apb_uart_regs_core_INTSTATUS_CLEAR INTSTATUS_CLEAR
 * @brief Contains register fields associated with INTSTATUS_CLEAR. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_INTSTATUS_MACRO__
#define __CMSDK_AT_UART_INTSTATUS_MACRO__

/* macros for field txintr */
/**
 * @defgroup at_apb_uart_regs_core_txintr_field txintr_field
 * @brief macros for field txintr
 * @details TX interrupt. Write 1 to clear.
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__SHIFT                                 0
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__WIDTH                                 1
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__MASK                        0x00000001U
#define CMSDK_AT_UART_INTSTATUS_TXIRQ_Pos CMSDK_AT_UART_INTSTATUS__TXIRQ__SHIFT
#define CMSDK_AT_UART_INTSTATUS_TXIRQ_Msk  CMSDK_AT_UART_INTSTATUS__TXIRQ__MASK
#define CMSDK_UART_INTSTATUS_TXIRQ_Pos    CMSDK_AT_UART_INTSTATUS__TXIRQ__SHIFT
#define CMSDK_UART_INTSTATUS_TXIRQ_Msk     CMSDK_AT_UART_INTSTATUS__TXIRQ__MASK
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_INTSTATUS__TXIRQ__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field rxintr */
/**
 * @defgroup at_apb_uart_regs_core_rxintr_field rxintr_field
 * @brief macros for field rxintr
 * @details RX interrupt. Write 1 to clear.
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__SHIFT                                 1
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__WIDTH                                 1
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__MASK                        0x00000002U
#define CMSDK_AT_UART_INTSTATUS_RXIRQ_Pos CMSDK_AT_UART_INTSTATUS__RXIRQ__SHIFT
#define CMSDK_AT_UART_INTSTATUS_RXIRQ_Msk  CMSDK_AT_UART_INTSTATUS__RXIRQ__MASK
#define CMSDK_UART_INTSTATUS_RXIRQ_Pos    CMSDK_AT_UART_INTSTATUS__RXIRQ__SHIFT
#define CMSDK_UART_INTSTATUS_RXIRQ_Msk     CMSDK_AT_UART_INTSTATUS__RXIRQ__MASK
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CMSDK_AT_UART_INTSTATUS__RXIRQ__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field tx_overflow_intr */
/**
 * @defgroup at_apb_uart_regs_core_tx_overflow_intr_field tx_overflow_intr_field
 * @brief macros for field tx_overflow_intr
 * @details TX overrun interrupt. Write 1 to clear.
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__SHIFT                               2
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__WIDTH                               1
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__MASK                      0x00000004U
#define CMSDK_AT_UART_INTSTATUS_TXORIRQ_Pos \
                    CMSDK_AT_UART_INTSTATUS__TXORIRQ__SHIFT
#define CMSDK_AT_UART_INTSTATUS_TXORIRQ_Msk \
                    CMSDK_AT_UART_INTSTATUS__TXORIRQ__MASK
#define CMSDK_UART_INTSTATUS_TXORIRQ_Pos \
                    CMSDK_AT_UART_INTSTATUS__TXORIRQ__SHIFT
#define CMSDK_UART_INTSTATUS_TXORIRQ_Msk CMSDK_AT_UART_INTSTATUS__TXORIRQ__MASK
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CMSDK_AT_UART_INTSTATUS__TXORIRQ__RESET_VALUE               0x00000000U
/** @} */

/* macros for field rx_overflow_intr */
/**
 * @defgroup at_apb_uart_regs_core_rx_overflow_intr_field rx_overflow_intr_field
 * @brief macros for field rx_overflow_intr
 * @details RX overrun interrupt. Write 1 to clear.
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__SHIFT                               3
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__WIDTH                               1
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__MASK                      0x00000008U
#define CMSDK_AT_UART_INTSTATUS_RXORIRQ_Pos \
                    CMSDK_AT_UART_INTSTATUS__RXORIRQ__SHIFT
#define CMSDK_AT_UART_INTSTATUS_RXORIRQ_Msk \
                    CMSDK_AT_UART_INTSTATUS__RXORIRQ__MASK
#define CMSDK_UART_INTSTATUS_RXORIRQ_Pos \
                    CMSDK_AT_UART_INTSTATUS__RXORIRQ__SHIFT
#define CMSDK_UART_INTSTATUS_RXORIRQ_Msk CMSDK_AT_UART_INTSTATUS__RXORIRQ__MASK
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CMSDK_AT_UART_INTSTATUS__RXORIRQ__RESET_VALUE               0x00000000U
/** @} */
#define CMSDK_AT_UART_INTSTATUS__TYPE                                  uint32_t
#define CMSDK_AT_UART_INTSTATUS__READ                               0x0000000fU
#define CMSDK_AT_UART_INTSTATUS__WRITE                              0x0000000fU
#define CMSDK_AT_UART_INTSTATUS__PRESERVED                          0x00000000U
#define CMSDK_AT_UART_INTSTATUS__RESET_VALUE                        0x00000000U

#endif /* __CMSDK_AT_UART_INTSTATUS_MACRO__ */

/** @} end of INTSTATUS_CLEAR */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_BAUDDIV */
/**
 * @defgroup at_apb_uart_regs_core_BAUDDIV BAUDDIV
 * @brief Contains register fields associated with BAUDDIV. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_BAUDDIV_MACRO__
#define __CMSDK_AT_UART_BAUDDIV_MACRO__

/* macros for field baud_div */
/**
 * @defgroup at_apb_uart_regs_core_baud_div_field baud_div_field
 * @brief macros for field baud_div
 * @details Baud rate divider. The minimum number is 8.
 * @{
 */
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__SHIFT                                0
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__WIDTH                               20
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__MASK                       0x000fffffU
#define CMSDK_AT_UART_BAUDDIV_Pos        CMSDK_AT_UART_BAUDDIV__BAUD_DIV__SHIFT
#define CMSDK_AT_UART_BAUDDIV_Msk         CMSDK_AT_UART_BAUDDIV__BAUD_DIV__MASK
#define CMSDK_UART_BAUDDIV_Pos           CMSDK_AT_UART_BAUDDIV__BAUD_DIV__SHIFT
#define CMSDK_UART_BAUDDIV_Msk            CMSDK_AT_UART_BAUDDIV__BAUD_DIV__MASK
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define CMSDK_AT_UART_BAUDDIV__BAUD_DIV__RESET_VALUE                0x00000000U
/** @} */
#define CMSDK_AT_UART_BAUDDIV__TYPE                                    uint32_t
#define CMSDK_AT_UART_BAUDDIV__READ                                 0x000fffffU
#define CMSDK_AT_UART_BAUDDIV__WRITE                                0x000fffffU
#define CMSDK_AT_UART_BAUDDIV__PRESERVED                            0x00000000U
#define CMSDK_AT_UART_BAUDDIV__RESET_VALUE                          0x00000000U

#endif /* __CMSDK_AT_UART_BAUDDIV_MACRO__ */

/** @} end of BAUDDIV */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_RX_LWM */
/**
 * @defgroup at_apb_uart_regs_core_RX_LWM RX_LWM
 * @brief Contains register fields associated with RX_LWM. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_RX_LWM_MACRO__
#define __CMSDK_AT_UART_RX_LWM_MACRO__

/* macros for field Rx_LWM */
/**
 * @defgroup at_apb_uart_regs_core_Rx_LWM_field Rx_LWM_field
 * @brief macros for field Rx_LWM
 * @details low water mark of RX FIFO; a trigger is issued when (Atmosic) RX FIFO has waited long enough to have received these many items, starting from the first item. Constraint: ( 1<= RX_LWM <= 14)
 * @{
 */
#define CMSDK_AT_UART_RX_LWM__RX_LWM__SHIFT                                   0
#define CMSDK_AT_UART_RX_LWM__RX_LWM__WIDTH                                   5
#define CMSDK_AT_UART_RX_LWM__RX_LWM__MASK                          0x0000001fU
#define CMSDK_AT_UART_RX_LWM_Pos            CMSDK_AT_UART_RX_LWM__RX_LWM__SHIFT
#define CMSDK_AT_UART_RX_LWM_Msk             CMSDK_AT_UART_RX_LWM__RX_LWM__MASK
#define CMSDK_UART_RX_LWM_Pos               CMSDK_AT_UART_RX_LWM__RX_LWM__SHIFT
#define CMSDK_UART_RX_LWM_Msk                CMSDK_AT_UART_RX_LWM__RX_LWM__MASK
#define CMSDK_AT_UART_RX_LWM__RX_LWM__READ(src) ((uint32_t)(src) & 0x0000001fU)
#define CMSDK_AT_UART_RX_LWM__RX_LWM__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define CMSDK_AT_UART_RX_LWM__RX_LWM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define CMSDK_AT_UART_RX_LWM__RX_LWM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define CMSDK_AT_UART_RX_LWM__RX_LWM__RESET_VALUE                   0x00000001U
/** @} */
#define CMSDK_AT_UART_RX_LWM__TYPE                                     uint32_t
#define CMSDK_AT_UART_RX_LWM__READ                                  0x0000001fU
#define CMSDK_AT_UART_RX_LWM__WRITE                                 0x0000001fU
#define CMSDK_AT_UART_RX_LWM__PRESERVED                             0x00000000U
#define CMSDK_AT_UART_RX_LWM__RESET_VALUE                           0x00000001U

#endif /* __CMSDK_AT_UART_RX_LWM_MACRO__ */

/** @} end of RX_LWM */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_TX_LWM */
/**
 * @defgroup at_apb_uart_regs_core_TX_LWM TX_LWM
 * @brief Contains register fields associated with TX_LWM. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_TX_LWM_MACRO__
#define __CMSDK_AT_UART_TX_LWM_MACRO__

/* macros for field Tx_LWM */
/**
 * @defgroup at_apb_uart_regs_core_Tx_LWM_field Tx_LWM_field
 * @brief macros for field Tx_LWM
 * @details low water mark of TX FIF0; a trigger is issued when (Atmosic) tX FIFO is drained to these many unoccupied slots. Constraint (1<= TX_LWM <= 16) 
 * @{
 */
#define CMSDK_AT_UART_TX_LWM__TX_LWM__SHIFT                                   0
#define CMSDK_AT_UART_TX_LWM__TX_LWM__WIDTH                                   5
#define CMSDK_AT_UART_TX_LWM__TX_LWM__MASK                          0x0000001fU
#define CMSDK_AT_UART_TX_LWM_Pos            CMSDK_AT_UART_TX_LWM__TX_LWM__SHIFT
#define CMSDK_AT_UART_TX_LWM_Msk             CMSDK_AT_UART_TX_LWM__TX_LWM__MASK
#define CMSDK_UART_TX_LWM_Pos               CMSDK_AT_UART_TX_LWM__TX_LWM__SHIFT
#define CMSDK_UART_TX_LWM_Msk                CMSDK_AT_UART_TX_LWM__TX_LWM__MASK
#define CMSDK_AT_UART_TX_LWM__TX_LWM__READ(src) ((uint32_t)(src) & 0x0000001fU)
#define CMSDK_AT_UART_TX_LWM__TX_LWM__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define CMSDK_AT_UART_TX_LWM__TX_LWM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define CMSDK_AT_UART_TX_LWM__TX_LWM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define CMSDK_AT_UART_TX_LWM__TX_LWM__RESET_VALUE                   0x00000010U
/** @} */
#define CMSDK_AT_UART_TX_LWM__TYPE                                     uint32_t
#define CMSDK_AT_UART_TX_LWM__READ                                  0x0000001fU
#define CMSDK_AT_UART_TX_LWM__WRITE                                 0x0000001fU
#define CMSDK_AT_UART_TX_LWM__PRESERVED                             0x00000000U
#define CMSDK_AT_UART_TX_LWM__RESET_VALUE                           0x00000010U

#endif /* __CMSDK_AT_UART_TX_LWM_MACRO__ */

/** @} end of TX_LWM */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_RX_FIFO_SPACES */
/**
 * @defgroup at_apb_uart_regs_core_RX_FIFO_SPACES RX_FIFO_SPACES
 * @brief Contains register fields associated with RX_FIFO_SPACES. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_RX_FIFO_SPACES_MACRO__
#define __CMSDK_AT_UART_RX_FIFO_SPACES_MACRO__

/* macros for field rx_fifo_spaces */
/**
 * @defgroup at_apb_uart_regs_core_rx_fifo_spaces_field rx_fifo_spaces_field
 * @brief macros for field rx_fifo_spaces
 * @details number of unoccupied spaces in RX_FIFO (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__SHIFT                   0
#define CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__WIDTH                   5
#define CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__MASK          0x0000001fU
#define CMSDK_AT_UART_RX_FIFO_SPACES_Pos \
                    CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__SHIFT
#define CMSDK_AT_UART_RX_FIFO_SPACES_Msk \
                    CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__MASK
#define CMSDK_UART_RX_FIFO_SPACES_Pos \
                    CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__SHIFT
#define CMSDK_UART_RX_FIFO_SPACES_Msk \
                    CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__MASK
#define CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define CMSDK_AT_UART_RX_FIFO_SPACES__RX_FIFO_SPACES__RESET_VALUE   0x00000010U
/** @} */
#define CMSDK_AT_UART_RX_FIFO_SPACES__TYPE                             uint32_t
#define CMSDK_AT_UART_RX_FIFO_SPACES__READ                          0x0000001fU
#define CMSDK_AT_UART_RX_FIFO_SPACES__PRESERVED                     0x00000000U
#define CMSDK_AT_UART_RX_FIFO_SPACES__RESET_VALUE                   0x00000010U

#endif /* __CMSDK_AT_UART_RX_FIFO_SPACES_MACRO__ */

/** @} end of RX_FIFO_SPACES */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_TX_FIFO_SPACES */
/**
 * @defgroup at_apb_uart_regs_core_TX_FIFO_SPACES TX_FIFO_SPACES
 * @brief Contains register fields associated with TX_FIFO_SPACES. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_TX_FIFO_SPACES_MACRO__
#define __CMSDK_AT_UART_TX_FIFO_SPACES_MACRO__

/* macros for field tx_fifo_spaces */
/**
 * @defgroup at_apb_uart_regs_core_tx_fifo_spaces_field tx_fifo_spaces_field
 * @brief macros for field tx_fifo_spaces
 * @details number of unoccupied spaces in TX_FIFO (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__SHIFT                   0
#define CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__WIDTH                   5
#define CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__MASK          0x0000001fU
#define CMSDK_AT_UART_TX_FIFO_SPACES_Pos \
                    CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__SHIFT
#define CMSDK_AT_UART_TX_FIFO_SPACES_Msk \
                    CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__MASK
#define CMSDK_UART_TX_FIFO_SPACES_Pos \
                    CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__SHIFT
#define CMSDK_UART_TX_FIFO_SPACES_Msk \
                    CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__MASK
#define CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define CMSDK_AT_UART_TX_FIFO_SPACES__TX_FIFO_SPACES__RESET_VALUE   0x00000010U
/** @} */
#define CMSDK_AT_UART_TX_FIFO_SPACES__TYPE                             uint32_t
#define CMSDK_AT_UART_TX_FIFO_SPACES__READ                          0x0000001fU
#define CMSDK_AT_UART_TX_FIFO_SPACES__PRESERVED                     0x00000000U
#define CMSDK_AT_UART_TX_FIFO_SPACES__RESET_VALUE                   0x00000010U

#endif /* __CMSDK_AT_UART_TX_FIFO_SPACES_MACRO__ */

/** @} end of TX_FIFO_SPACES */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_HW_FLOW_OVRD */
/**
 * @defgroup at_apb_uart_regs_core_HW_FLOW_OVRD HW_FLOW_OVRD
 * @brief Contains register fields associated with HW_FLOW_OVRD. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_HW_FLOW_OVRD_MACRO__
#define __CMSDK_AT_UART_HW_FLOW_OVRD_MACRO__

/* macros for field nRTS_VAL */
/**
 * @defgroup at_apb_uart_regs_core_nRTS_VAL_field nRTS_VAL_field
 * @brief macros for field nRTS_VAL
 * @details 0(default) = nRTS is asserted to enable external TX; 1= nRTS is deasserted
 * @{
 */
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__SHIFT                           0
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__WIDTH                           1
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__MASK                  0x00000001U
#define CMSDK_AT_UART_HW_FLOW_OVRD_NRTS_VAL_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__SHIFT
#define CMSDK_AT_UART_HW_FLOW_OVRD_NRTS_VAL_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__MASK
#define CMSDK_UART_HW_FLOW_OVRD_NRTS_VAL_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__SHIFT
#define CMSDK_UART_HW_FLOW_OVRD_NRTS_VAL_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__MASK
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field nRTS_OVRD */
/**
 * @defgroup at_apb_uart_regs_core_nRTS_OVRD_field nRTS_OVRD_field
 * @brief macros for field nRTS_OVRD
 * @details 0= nUARTRTS override override disabled; 1(default)= nUARTRTS override enabled ;(Atmosic)
 * @{
 */
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__SHIFT                          1
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__WIDTH                          1
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__MASK                 0x00000002U
#define CMSDK_AT_UART_HW_FLOW_OVRD_NRTS_OVRD_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__SHIFT
#define CMSDK_AT_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__MASK
#define CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__SHIFT
#define CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__MASK
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NRTS_OVRD__RESET_VALUE          0x00000001U
/** @} */

/* macros for field nCTS_VAL */
/**
 * @defgroup at_apb_uart_regs_core_nCTS_VAL_field nCTS_VAL_field
 * @brief macros for field nCTS_VAL
 * @details 0(default) = nCTS is asserted to enable TX; 1= nCTS is deasserted
 * @{
 */
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__SHIFT                           2
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__WIDTH                           1
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__MASK                  0x00000004U
#define CMSDK_AT_UART_HW_FLOW_OVRD_NCTS_VAL_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__SHIFT
#define CMSDK_AT_UART_HW_FLOW_OVRD_NCTS_VAL_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__MASK
#define CMSDK_UART_HW_FLOW_OVRD_NCTS_VAL_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__SHIFT
#define CMSDK_UART_HW_FLOW_OVRD_NCTS_VAL_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__MASK
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_VAL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field nCTS_OVRD */
/**
 * @defgroup at_apb_uart_regs_core_nCTS_OVRD_field nCTS_OVRD_field
 * @brief macros for field nCTS_OVRD
 * @details 0= nUARTCTS override override disabled; 1(default)= nUARTCTS override enabled (Atmosic)
 * @{
 */
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__SHIFT                          3
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__WIDTH                          1
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__MASK                 0x00000008U
#define CMSDK_AT_UART_HW_FLOW_OVRD_NCTS_OVRD_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__SHIFT
#define CMSDK_AT_UART_HW_FLOW_OVRD_NCTS_OVRD_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__MASK
#define CMSDK_UART_HW_FLOW_OVRD_NCTS_OVRD_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__SHIFT
#define CMSDK_UART_HW_FLOW_OVRD_NCTS_OVRD_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__MASK
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CMSDK_AT_UART_HW_FLOW_OVRD__NCTS_OVRD__RESET_VALUE          0x00000001U
/** @} */

/* macros for field RTS_TRIG_LVL */
/**
 * @defgroup at_apb_uart_regs_core_RTS_TRIG_LVL_field RTS_TRIG_LVL_field
 * @brief macros for field RTS_TRIG_LVL
 * @details threshold of rx fifo to de-assert nRTS. The value corresponds to the number of open spaces in RX fifo. minimum programmable value is 2.
 * @{
 */
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__SHIFT                       4
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__WIDTH                       3
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__MASK              0x00000070U
#define CMSDK_AT_UART_HW_FLOW_OVRD_RTS_TRIG_LVL_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__SHIFT
#define CMSDK_AT_UART_HW_FLOW_OVRD_RTS_TRIG_LVL_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__MASK
#define CMSDK_UART_HW_FLOW_OVRD_RTS_TRIG_LVL_Pos \
                    CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__SHIFT
#define CMSDK_UART_HW_FLOW_OVRD_RTS_TRIG_LVL_Msk \
                    CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__MASK
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define CMSDK_AT_UART_HW_FLOW_OVRD__RTS_TRIG_LVL__RESET_VALUE       0x00000002U
/** @} */
#define CMSDK_AT_UART_HW_FLOW_OVRD__TYPE                               uint32_t
#define CMSDK_AT_UART_HW_FLOW_OVRD__READ                            0x0000007fU
#define CMSDK_AT_UART_HW_FLOW_OVRD__WRITE                           0x0000007fU
#define CMSDK_AT_UART_HW_FLOW_OVRD__PRESERVED                       0x00000000U
#define CMSDK_AT_UART_HW_FLOW_OVRD__RESET_VALUE                     0x0000002aU

#endif /* __CMSDK_AT_UART_HW_FLOW_OVRD_MACRO__ */

/** @} end of HW_FLOW_OVRD */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_BAUD_RATE_DETECT */
/**
 * @defgroup at_apb_uart_regs_core_BAUD_RATE_DETECT BAUD_RATE_DETECT
 * @brief Contains register fields associated with BAUD_RATE_DETECT. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_BAUD_RATE_DETECT_MACRO__
#define __CMSDK_AT_UART_BAUD_RATE_DETECT_MACRO__

/* macros for field brd */
/**
 * @defgroup at_apb_uart_regs_core_brd_field brd_field
 * @brief macros for field brd
 * @details 1=set by SW, HW treat the next frame/s as baud  rate detection byte, cleared by HW once baud rate is  detected. 0=normal mode
 * @{
 */
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__SHIFT                            0
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__WIDTH                            1
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__MASK                   0x00000001U
#define CMSDK_AT_UART_BAUD_RATE_DETECT_Pos \
                    CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__SHIFT
#define CMSDK_AT_UART_BAUD_RATE_DETECT_Msk \
                    CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__MASK
#define CMSDK_UART_BAUD_RATE_DETECT_Pos \
                    CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__SHIFT
#define CMSDK_UART_BAUD_RATE_DETECT_Msk \
                    CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__MASK
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_BAUD_RATE_DETECT__BRD__RESET_VALUE            0x00000000U
/** @} */
#define CMSDK_AT_UART_BAUD_RATE_DETECT__TYPE                           uint32_t
#define CMSDK_AT_UART_BAUD_RATE_DETECT__READ                        0x00000001U
#define CMSDK_AT_UART_BAUD_RATE_DETECT__WRITE                       0x00000001U
#define CMSDK_AT_UART_BAUD_RATE_DETECT__PRESERVED                   0x00000000U
#define CMSDK_AT_UART_BAUD_RATE_DETECT__RESET_VALUE                 0x00000000U

#endif /* __CMSDK_AT_UART_BAUD_RATE_DETECT_MACRO__ */

/** @} end of BAUD_RATE_DETECT */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_BAUD_DIV_CEIL */
/**
 * @defgroup at_apb_uart_regs_core_BAUD_DIV_CEIL BAUD_DIV_CEIL
 * @brief Contains register fields associated with BAUD_DIV_CEIL. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_BAUD_DIV_CEIL_MACRO__
#define __CMSDK_AT_UART_BAUD_DIV_CEIL_MACRO__

/* macros for field bauddiv_ceil */
/**
 * @defgroup at_apb_uart_regs_core_bauddiv_ceil_field bauddiv_ceil_field
 * @brief macros for field bauddiv_ceil
 * @details sets max reference for baud rate in auto detection. Auto detection restarts if start bit is not detected within this window.
 * @{
 */
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__SHIFT                      0
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__WIDTH                     20
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__MASK             0x000fffffU
#define CMSDK_AT_UART_BAUD_DIV_CEIL_Pos \
                    CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__SHIFT
#define CMSDK_AT_UART_BAUD_DIV_CEIL_Msk \
                    CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__MASK
#define CMSDK_UART_BAUD_DIV_CEIL_Pos \
                    CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__SHIFT
#define CMSDK_UART_BAUD_DIV_CEIL_Msk \
                    CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__MASK
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define CMSDK_AT_UART_BAUD_DIV_CEIL__BAUDDIV_CEIL__RESET_VALUE      0x000fffffU
/** @} */
#define CMSDK_AT_UART_BAUD_DIV_CEIL__TYPE                              uint32_t
#define CMSDK_AT_UART_BAUD_DIV_CEIL__READ                           0x000fffffU
#define CMSDK_AT_UART_BAUD_DIV_CEIL__WRITE                          0x000fffffU
#define CMSDK_AT_UART_BAUD_DIV_CEIL__PRESERVED                      0x00000000U
#define CMSDK_AT_UART_BAUD_DIV_CEIL__RESET_VALUE                    0x000fffffU

#endif /* __CMSDK_AT_UART_BAUD_DIV_CEIL_MACRO__ */

/** @} end of BAUD_DIV_CEIL */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_BRD_STAT */
/**
 * @defgroup at_apb_uart_regs_core_BRD_STAT BRD_STAT
 * @brief Contains register fields associated with BRD_STAT. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_BRD_STAT_MACRO__
#define __CMSDK_AT_UART_BRD_STAT_MACRO__

/* macros for field on_going */
/**
 * @defgroup at_apb_uart_regs_core_on_going_field on_going_field
 * @brief macros for field on_going
 * @details auto detection is on going
 * @{
 */
#define CMSDK_AT_UART_BRD_STAT__ON_GOING__SHIFT                               0
#define CMSDK_AT_UART_BRD_STAT__ON_GOING__WIDTH                               1
#define CMSDK_AT_UART_BRD_STAT__ON_GOING__MASK                      0x00000001U
#define CMSDK_AT_UART_BRD_STAT_ON_GOING_Pos \
                    CMSDK_AT_UART_BRD_STAT__ON_GOING__SHIFT
#define CMSDK_AT_UART_BRD_STAT_ON_GOING_Msk \
                    CMSDK_AT_UART_BRD_STAT__ON_GOING__MASK
#define CMSDK_UART_BRD_STAT_ON_GOING_Pos \
                    CMSDK_AT_UART_BRD_STAT__ON_GOING__SHIFT
#define CMSDK_UART_BRD_STAT_ON_GOING_Msk CMSDK_AT_UART_BRD_STAT__ON_GOING__MASK
#define CMSDK_AT_UART_BRD_STAT__ON_GOING__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_BRD_STAT__ON_GOING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_BRD_STAT__ON_GOING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_BRD_STAT__ON_GOING__RESET_VALUE               0x00000000U
/** @} */

/* macros for field start_bit_timeout */
/**
 * @defgroup at_apb_uart_regs_core_start_bit_timeout_field start_bit_timeout_field
 * @brief macros for field start_bit_timeout
 * @details Previous synch bit too long. The calibration restarts after timeout.
 * @{
 */
#define CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__SHIFT                      1
#define CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__WIDTH                      1
#define CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__MASK             0x00000002U
#define CMSDK_AT_UART_BRD_STAT_START_BIT_TIMEOUT_Pos \
                    CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__SHIFT
#define CMSDK_AT_UART_BRD_STAT_START_BIT_TIMEOUT_Msk \
                    CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__MASK
#define CMSDK_UART_BRD_STAT_START_BIT_TIMEOUT_Pos \
                    CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__SHIFT
#define CMSDK_UART_BRD_STAT_START_BIT_TIMEOUT_Msk \
                    CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__MASK
#define CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CMSDK_AT_UART_BRD_STAT__START_BIT_TIMEOUT__RESET_VALUE      0x00000000U
/** @} */
#define CMSDK_AT_UART_BRD_STAT__TYPE                                   uint32_t
#define CMSDK_AT_UART_BRD_STAT__READ                                0x00000003U
#define CMSDK_AT_UART_BRD_STAT__PRESERVED                           0x00000000U
#define CMSDK_AT_UART_BRD_STAT__RESET_VALUE                         0x00000000U

#endif /* __CMSDK_AT_UART_BRD_STAT_MACRO__ */

/** @} end of BRD_STAT */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_INTMASK */
/**
 * @defgroup at_apb_uart_regs_core_INTMASK INTMASK
 * @brief Contains register fields associated with INTMASK. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_INTMASK_MACRO__
#define __CMSDK_AT_UART_INTMASK_MACRO__

/* macros for field txint_en */
/**
 * @defgroup at_apb_uart_regs_core_txint_en_field txint_en_field
 * @brief macros for field txint_en
 * @details mask enable for TX interrupt.
 * @{
 */
#define CMSDK_AT_UART_INTMASK__TXINT_EN__SHIFT                                0
#define CMSDK_AT_UART_INTMASK__TXINT_EN__WIDTH                                1
#define CMSDK_AT_UART_INTMASK__TXINT_EN__MASK                       0x00000001U
#define CMSDK_AT_UART_INTMASK_TXINT_EN_Pos \
                    CMSDK_AT_UART_INTMASK__TXINT_EN__SHIFT
#define CMSDK_AT_UART_INTMASK_TXINT_EN_Msk \
                    CMSDK_AT_UART_INTMASK__TXINT_EN__MASK
#define CMSDK_UART_INTMASK_TXINT_EN_Pos  CMSDK_AT_UART_INTMASK__TXINT_EN__SHIFT
#define CMSDK_UART_INTMASK_TXINT_EN_Msk   CMSDK_AT_UART_INTMASK__TXINT_EN__MASK
#define CMSDK_AT_UART_INTMASK__TXINT_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_INTMASK__TXINT_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_INTMASK__TXINT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CMSDK_AT_UART_INTMASK__TXINT_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CMSDK_AT_UART_INTMASK__TXINT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_INTMASK__TXINT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_INTMASK__TXINT_EN__RESET_VALUE                0x00000001U
/** @} */

/* macros for field rxint_en */
/**
 * @defgroup at_apb_uart_regs_core_rxint_en_field rxint_en_field
 * @brief macros for field rxint_en
 * @details mask enable for RX interrupt.
 * @{
 */
#define CMSDK_AT_UART_INTMASK__RXINT_EN__SHIFT                                1
#define CMSDK_AT_UART_INTMASK__RXINT_EN__WIDTH                                1
#define CMSDK_AT_UART_INTMASK__RXINT_EN__MASK                       0x00000002U
#define CMSDK_AT_UART_INTMASK_RXINT_EN_Pos \
                    CMSDK_AT_UART_INTMASK__RXINT_EN__SHIFT
#define CMSDK_AT_UART_INTMASK_RXINT_EN_Msk \
                    CMSDK_AT_UART_INTMASK__RXINT_EN__MASK
#define CMSDK_UART_INTMASK_RXINT_EN_Pos  CMSDK_AT_UART_INTMASK__RXINT_EN__SHIFT
#define CMSDK_UART_INTMASK_RXINT_EN_Msk   CMSDK_AT_UART_INTMASK__RXINT_EN__MASK
#define CMSDK_AT_UART_INTMASK__RXINT_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CMSDK_AT_UART_INTMASK__RXINT_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CMSDK_AT_UART_INTMASK__RXINT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CMSDK_AT_UART_INTMASK__RXINT_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CMSDK_AT_UART_INTMASK__RXINT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CMSDK_AT_UART_INTMASK__RXINT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CMSDK_AT_UART_INTMASK__RXINT_EN__RESET_VALUE                0x00000001U
/** @} */

/* macros for field tx_overflow_int_en */
/**
 * @defgroup at_apb_uart_regs_core_tx_overflow_int_en_field tx_overflow_int_en_field
 * @brief macros for field tx_overflow_int_en
 * @details mask enable for TX overflow interrupt.
 * @{
 */
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__SHIFT                      2
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__WIDTH                      1
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__MASK             0x00000004U
#define CMSDK_AT_UART_INTMASK_TX_OVERFLOW_INT_EN_Pos \
                    CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__SHIFT
#define CMSDK_AT_UART_INTMASK_TX_OVERFLOW_INT_EN_Msk \
                    CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__MASK
#define CMSDK_UART_INTMASK_TX_OVERFLOW_INT_EN_Pos \
                    CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__SHIFT
#define CMSDK_UART_INTMASK_TX_OVERFLOW_INT_EN_Msk \
                    CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__MASK
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CMSDK_AT_UART_INTMASK__TX_OVERFLOW_INT_EN__RESET_VALUE      0x00000001U
/** @} */

/* macros for field rx_overflow_int_en */
/**
 * @defgroup at_apb_uart_regs_core_rx_overflow_int_en_field rx_overflow_int_en_field
 * @brief macros for field rx_overflow_int_en
 * @details mask enable for RX overflow interrupt.
 * @{
 */
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__SHIFT                      3
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__WIDTH                      1
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__MASK             0x00000008U
#define CMSDK_AT_UART_INTMASK_RX_OVERFLOW_INT_EN_Pos \
                    CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__SHIFT
#define CMSDK_AT_UART_INTMASK_RX_OVERFLOW_INT_EN_Msk \
                    CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__MASK
#define CMSDK_UART_INTMASK_RX_OVERFLOW_INT_EN_Pos \
                    CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__SHIFT
#define CMSDK_UART_INTMASK_RX_OVERFLOW_INT_EN_Msk \
                    CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__MASK
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CMSDK_AT_UART_INTMASK__RX_OVERFLOW_INT_EN__RESET_VALUE      0x00000001U
/** @} */
#define CMSDK_AT_UART_INTMASK__TYPE                                    uint32_t
#define CMSDK_AT_UART_INTMASK__READ                                 0x0000000fU
#define CMSDK_AT_UART_INTMASK__WRITE                                0x0000000fU
#define CMSDK_AT_UART_INTMASK__PRESERVED                            0x00000000U
#define CMSDK_AT_UART_INTMASK__RESET_VALUE                          0x0000000fU

#endif /* __CMSDK_AT_UART_INTMASK_MACRO__ */

/** @} end of INTMASK */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_RX_FIFO_ENTRIES */
/**
 * @defgroup at_apb_uart_regs_core_RX_FIFO_ENTRIES RX_FIFO_ENTRIES
 * @brief Contains register fields associated with RX_FIFO_ENTRIES. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_RX_FIFO_ENTRIES_MACRO__
#define __CMSDK_AT_UART_RX_FIFO_ENTRIES_MACRO__

/* macros for field rx_fifo_entries */
/**
 * @defgroup at_apb_uart_regs_core_rx_fifo_entries_field rx_fifo_entries_field
 * @brief macros for field rx_fifo_entries
 * @details number of occupied spaces in RX_FIFO. DMA reads this value to determine how many reads to do in each round.
 * @{
 */
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__SHIFT                 0
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__WIDTH                 5
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__MASK        0x0000001fU
#define CMSDK_AT_UART_RX_FIFO_ENTRIES_Pos \
                    CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__SHIFT
#define CMSDK_AT_UART_RX_FIFO_ENTRIES_Msk \
                    CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__MASK
#define CMSDK_UART_RX_FIFO_ENTRIES_Pos \
                    CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__SHIFT
#define CMSDK_UART_RX_FIFO_ENTRIES_Msk \
                    CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__MASK
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__RX_FIFO_ENTRIES__RESET_VALUE 0x00000000U
/** @} */
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__TYPE                            uint32_t
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__READ                         0x0000001fU
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__PRESERVED                    0x00000000U
#define CMSDK_AT_UART_RX_FIFO_ENTRIES__RESET_VALUE                  0x00000000U

#endif /* __CMSDK_AT_UART_RX_FIFO_ENTRIES_MACRO__ */

/** @} end of RX_FIFO_ENTRIES */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_INTSTATUS_SET */
/**
 * @defgroup at_apb_uart_regs_core_INTSTATUS_SET INTSTATUS_SET
 * @brief Contains register fields associated with INTSTATUS_SET. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_INTSTATUS_SET_MACRO__
#define __CMSDK_AT_UART_INTSTATUS_SET_MACRO__

/* macros for field txintr_set */
/**
 * @defgroup at_apb_uart_regs_core_txintr_set_field txintr_set_field
 * @brief macros for field txintr_set
 * @details TX interrupt. Write 1 to set. (self-clearing)
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__SHIFT                        0
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__WIDTH                        1
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__MASK               0x00000001U
#define CMSDK_AT_UART_INTSTATUS_SET_TXINTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__SHIFT
#define CMSDK_AT_UART_INTSTATUS_SET_TXINTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__MASK
#define CMSDK_UART_INTSTATUS_SET_TXINTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__SHIFT
#define CMSDK_UART_INTSTATUS_SET_TXINTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__MASK
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define CMSDK_AT_UART_INTSTATUS_SET__TXINTR_SET__RESET_VALUE        0x00000000U
/** @} */

/* macros for field rxintr_set */
/**
 * @defgroup at_apb_uart_regs_core_rxintr_set_field rxintr_set_field
 * @brief macros for field rxintr_set
 * @details RX interrupt. Write 1 to set. (self-clearing)
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__SHIFT                        1
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__WIDTH                        1
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__MASK               0x00000002U
#define CMSDK_AT_UART_INTSTATUS_SET_RXINTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__SHIFT
#define CMSDK_AT_UART_INTSTATUS_SET_RXINTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__MASK
#define CMSDK_UART_INTSTATUS_SET_RXINTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__SHIFT
#define CMSDK_UART_INTSTATUS_SET_RXINTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__MASK
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define CMSDK_AT_UART_INTSTATUS_SET__RXINTR_SET__RESET_VALUE        0x00000000U
/** @} */

/* macros for field tx_overflow_intr_set */
/**
 * @defgroup at_apb_uart_regs_core_tx_overflow_intr_set_field tx_overflow_intr_set_field
 * @brief macros for field tx_overflow_intr_set
 * @details TX overrun interrupt. Write 1 to set. (self-clearing)
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__SHIFT              2
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__WIDTH              1
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__MASK     0x00000004U
#define CMSDK_AT_UART_INTSTATUS_SET_TX_OVERFLOW_INTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__SHIFT
#define CMSDK_AT_UART_INTSTATUS_SET_TX_OVERFLOW_INTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__MASK
#define CMSDK_UART_INTSTATUS_SET_TX_OVERFLOW_INTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__SHIFT
#define CMSDK_UART_INTSTATUS_SET_TX_OVERFLOW_INTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__MASK
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define CMSDK_AT_UART_INTSTATUS_SET__TX_OVERFLOW_INTR_SET__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field rx_overflow_intr_set */
/**
 * @defgroup at_apb_uart_regs_core_rx_overflow_intr_set_field rx_overflow_intr_set_field
 * @brief macros for field rx_overflow_intr_set
 * @details RX overrun interrupt. Write 1 to set. (self-clearing)
 * @{
 */
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__SHIFT              3
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__WIDTH              1
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__MASK     0x00000008U
#define CMSDK_AT_UART_INTSTATUS_SET_RX_OVERFLOW_INTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__SHIFT
#define CMSDK_AT_UART_INTSTATUS_SET_RX_OVERFLOW_INTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__MASK
#define CMSDK_UART_INTSTATUS_SET_RX_OVERFLOW_INTR_SET_Pos \
                    CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__SHIFT
#define CMSDK_UART_INTSTATUS_SET_RX_OVERFLOW_INTR_SET_Msk \
                    CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__MASK
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CMSDK_AT_UART_INTSTATUS_SET__RX_OVERFLOW_INTR_SET__RESET_VALUE \
                    0x00000000U
/** @} */
#define CMSDK_AT_UART_INTSTATUS_SET__TYPE                              uint32_t
#define CMSDK_AT_UART_INTSTATUS_SET__READ                           0x0000000fU
#define CMSDK_AT_UART_INTSTATUS_SET__WRITE                          0x0000000fU
#define CMSDK_AT_UART_INTSTATUS_SET__PRESERVED                      0x00000000U
#define CMSDK_AT_UART_INTSTATUS_SET__RESET_VALUE                    0x00000000U

#endif /* __CMSDK_AT_UART_INTSTATUS_SET_MACRO__ */

/** @} end of INTSTATUS_SET */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID4 */
/**
 * @defgroup at_apb_uart_regs_core_PID4 PID4
 * @brief Contains register fields associated with PID4. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID4_MACRO__
#define __CMSDK_AT_UART_PID4_MACRO__

/* macros for field jep106_c_code */
/**
 * @defgroup at_apb_uart_regs_core_jep106_c_code_field jep106_c_code_field
 * @brief macros for field jep106_c_code
 * @details jep106_c_code
 * @{
 */
#define CMSDK_AT_UART_PID4__JEP106_C_CODE__SHIFT                              0
#define CMSDK_AT_UART_PID4__JEP106_C_CODE__WIDTH                              4
#define CMSDK_AT_UART_PID4__JEP106_C_CODE__MASK                     0x0000000fU
#define CMSDK_AT_UART_PID4_JEP106_C_CODE_Pos \
                    CMSDK_AT_UART_PID4__JEP106_C_CODE__SHIFT
#define CMSDK_AT_UART_PID4_JEP106_C_CODE_Msk \
                    CMSDK_AT_UART_PID4__JEP106_C_CODE__MASK
#define CMSDK_UART_PID4_JEP106_C_CODE_Pos \
                    CMSDK_AT_UART_PID4__JEP106_C_CODE__SHIFT
#define CMSDK_UART_PID4_JEP106_C_CODE_Msk \
                    CMSDK_AT_UART_PID4__JEP106_C_CODE__MASK
#define CMSDK_AT_UART_PID4__JEP106_C_CODE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define CMSDK_AT_UART_PID4__JEP106_C_CODE__RESET_VALUE              0x00000004U
/** @} */

/* macros for field block_count */
/**
 * @defgroup at_apb_uart_regs_core_block_count_field block_count_field
 * @brief macros for field block_count
 * @details Block count
 * @{
 */
#define CMSDK_AT_UART_PID4__BLOCK_COUNT__SHIFT                                4
#define CMSDK_AT_UART_PID4__BLOCK_COUNT__WIDTH                                4
#define CMSDK_AT_UART_PID4__BLOCK_COUNT__MASK                       0x000000f0U
#define CMSDK_AT_UART_PID4_BLOCK_COUNT_Pos \
                    CMSDK_AT_UART_PID4__BLOCK_COUNT__SHIFT
#define CMSDK_AT_UART_PID4_BLOCK_COUNT_Msk \
                    CMSDK_AT_UART_PID4__BLOCK_COUNT__MASK
#define CMSDK_UART_PID4_BLOCK_COUNT_Pos  CMSDK_AT_UART_PID4__BLOCK_COUNT__SHIFT
#define CMSDK_UART_PID4_BLOCK_COUNT_Msk   CMSDK_AT_UART_PID4__BLOCK_COUNT__MASK
#define CMSDK_AT_UART_PID4__BLOCK_COUNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define CMSDK_AT_UART_PID4__BLOCK_COUNT__RESET_VALUE                0x00000000U
/** @} */
#define CMSDK_AT_UART_PID4__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID4__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID4__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID4__RESET_VALUE                             0x00000004U

#endif /* __CMSDK_AT_UART_PID4_MACRO__ */

/** @} end of PID4 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID5 */
/**
 * @defgroup at_apb_uart_regs_core_PID5 PID5
 * @brief Contains register fields associated with PID5. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID5_MACRO__
#define __CMSDK_AT_UART_PID5_MACRO__

/* macros for field pid5 */
/**
 * @defgroup at_apb_uart_regs_core_pid5_field pid5_field
 * @brief macros for field pid5
 * @details Peripheral ID Register 5.
 * @{
 */
#define CMSDK_AT_UART_PID5__PID5__SHIFT                                       0
#define CMSDK_AT_UART_PID5__PID5__WIDTH                                       8
#define CMSDK_AT_UART_PID5__PID5__MASK                              0x000000ffU
#define CMSDK_AT_UART_PID5_Pos                  CMSDK_AT_UART_PID5__PID5__SHIFT
#define CMSDK_AT_UART_PID5_Msk                   CMSDK_AT_UART_PID5__PID5__MASK
#define CMSDK_UART_PID5_Pos                     CMSDK_AT_UART_PID5__PID5__SHIFT
#define CMSDK_UART_PID5_Msk                      CMSDK_AT_UART_PID5__PID5__MASK
#define CMSDK_AT_UART_PID5__PID5__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_PID5__PID5__RESET_VALUE                       0x00000000U
/** @} */
#define CMSDK_AT_UART_PID5__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID5__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID5__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID5__RESET_VALUE                             0x00000000U

#endif /* __CMSDK_AT_UART_PID5_MACRO__ */

/** @} end of PID5 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID6 */
/**
 * @defgroup at_apb_uart_regs_core_PID6 PID6
 * @brief Contains register fields associated with PID6. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID6_MACRO__
#define __CMSDK_AT_UART_PID6_MACRO__

/* macros for field pid6 */
/**
 * @defgroup at_apb_uart_regs_core_pid6_field pid6_field
 * @brief macros for field pid6
 * @details Peripheral ID Register 6.
 * @{
 */
#define CMSDK_AT_UART_PID6__PID6__SHIFT                                       0
#define CMSDK_AT_UART_PID6__PID6__WIDTH                                       8
#define CMSDK_AT_UART_PID6__PID6__MASK                              0x000000ffU
#define CMSDK_AT_UART_PID6_Pos                  CMSDK_AT_UART_PID6__PID6__SHIFT
#define CMSDK_AT_UART_PID6_Msk                   CMSDK_AT_UART_PID6__PID6__MASK
#define CMSDK_UART_PID6_Pos                     CMSDK_AT_UART_PID6__PID6__SHIFT
#define CMSDK_UART_PID6_Msk                      CMSDK_AT_UART_PID6__PID6__MASK
#define CMSDK_AT_UART_PID6__PID6__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_PID6__PID6__RESET_VALUE                       0x00000000U
/** @} */
#define CMSDK_AT_UART_PID6__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID6__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID6__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID6__RESET_VALUE                             0x00000000U

#endif /* __CMSDK_AT_UART_PID6_MACRO__ */

/** @} end of PID6 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID7 */
/**
 * @defgroup at_apb_uart_regs_core_PID7 PID7
 * @brief Contains register fields associated with PID7. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID7_MACRO__
#define __CMSDK_AT_UART_PID7_MACRO__

/* macros for field pid7 */
/**
 * @defgroup at_apb_uart_regs_core_pid7_field pid7_field
 * @brief macros for field pid7
 * @details Peripheral ID Register 7.
 * @{
 */
#define CMSDK_AT_UART_PID7__PID7__SHIFT                                       0
#define CMSDK_AT_UART_PID7__PID7__WIDTH                                       8
#define CMSDK_AT_UART_PID7__PID7__MASK                              0x000000ffU
#define CMSDK_AT_UART_PID7_Pos                  CMSDK_AT_UART_PID7__PID7__SHIFT
#define CMSDK_AT_UART_PID7_Msk                   CMSDK_AT_UART_PID7__PID7__MASK
#define CMSDK_UART_PID7_Pos                     CMSDK_AT_UART_PID7__PID7__SHIFT
#define CMSDK_UART_PID7_Msk                      CMSDK_AT_UART_PID7__PID7__MASK
#define CMSDK_AT_UART_PID7__PID7__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_PID7__PID7__RESET_VALUE                       0x00000000U
/** @} */
#define CMSDK_AT_UART_PID7__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID7__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID7__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID7__RESET_VALUE                             0x00000000U

#endif /* __CMSDK_AT_UART_PID7_MACRO__ */

/** @} end of PID7 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID0 */
/**
 * @defgroup at_apb_uart_regs_core_PID0 PID0
 * @brief Contains register fields associated with PID0. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID0_MACRO__
#define __CMSDK_AT_UART_PID0_MACRO__

/* macros for field part_num */
/**
 * @defgroup at_apb_uart_regs_core_part_num_field part_num_field
 * @brief macros for field part_num
 * @details Part number[7:0].
 * @{
 */
#define CMSDK_AT_UART_PID0__PART_NUM__SHIFT                                   0
#define CMSDK_AT_UART_PID0__PART_NUM__WIDTH                                   8
#define CMSDK_AT_UART_PID0__PART_NUM__MASK                          0x000000ffU
#define CMSDK_AT_UART_PID0_Pos              CMSDK_AT_UART_PID0__PART_NUM__SHIFT
#define CMSDK_AT_UART_PID0_Msk               CMSDK_AT_UART_PID0__PART_NUM__MASK
#define CMSDK_UART_PID0_Pos                 CMSDK_AT_UART_PID0__PART_NUM__SHIFT
#define CMSDK_UART_PID0_Msk                  CMSDK_AT_UART_PID0__PART_NUM__MASK
#define CMSDK_AT_UART_PID0__PART_NUM__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_PID0__PART_NUM__RESET_VALUE                   0x00000021U
/** @} */
#define CMSDK_AT_UART_PID0__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID0__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID0__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID0__RESET_VALUE                             0x00000021U

#endif /* __CMSDK_AT_UART_PID0_MACRO__ */

/** @} end of PID0 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID1 */
/**
 * @defgroup at_apb_uart_regs_core_PID1 PID1
 * @brief Contains register fields associated with PID1. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID1_MACRO__
#define __CMSDK_AT_UART_PID1_MACRO__

/* macros for field part_num */
/**
 * @defgroup at_apb_uart_regs_core_part_num_field part_num_field
 * @brief macros for field part_num
 * @details Part number[11:8].
 * @{
 */
#define CMSDK_AT_UART_PID1__PART_NUM__SHIFT                                   0
#define CMSDK_AT_UART_PID1__PART_NUM__WIDTH                                   4
#define CMSDK_AT_UART_PID1__PART_NUM__MASK                          0x0000000fU
#define CMSDK_AT_UART_PID1_PART_NUM_Pos     CMSDK_AT_UART_PID1__PART_NUM__SHIFT
#define CMSDK_AT_UART_PID1_PART_NUM_Msk      CMSDK_AT_UART_PID1__PART_NUM__MASK
#define CMSDK_UART_PID1_PART_NUM_Pos        CMSDK_AT_UART_PID1__PART_NUM__SHIFT
#define CMSDK_UART_PID1_PART_NUM_Msk         CMSDK_AT_UART_PID1__PART_NUM__MASK
#define CMSDK_AT_UART_PID1__PART_NUM__READ(src) ((uint32_t)(src) & 0x0000000fU)
#define CMSDK_AT_UART_PID1__PART_NUM__RESET_VALUE                   0x00000008U
/** @} */

/* macros for field jep106_id_3_0 */
/**
 * @defgroup at_apb_uart_regs_core_jep106_id_3_0_field jep106_id_3_0_field
 * @brief macros for field jep106_id_3_0
 * @details jep106_id_3_0
 * @{
 */
#define CMSDK_AT_UART_PID1__JEP106_ID_3_0__SHIFT                              4
#define CMSDK_AT_UART_PID1__JEP106_ID_3_0__WIDTH                              4
#define CMSDK_AT_UART_PID1__JEP106_ID_3_0__MASK                     0x000000f0U
#define CMSDK_AT_UART_PID1_JEP106_ID_3_0_Pos \
                    CMSDK_AT_UART_PID1__JEP106_ID_3_0__SHIFT
#define CMSDK_AT_UART_PID1_JEP106_ID_3_0_Msk \
                    CMSDK_AT_UART_PID1__JEP106_ID_3_0__MASK
#define CMSDK_UART_PID1_JEP106_ID_3_0_Pos \
                    CMSDK_AT_UART_PID1__JEP106_ID_3_0__SHIFT
#define CMSDK_UART_PID1_JEP106_ID_3_0_Msk \
                    CMSDK_AT_UART_PID1__JEP106_ID_3_0__MASK
#define CMSDK_AT_UART_PID1__JEP106_ID_3_0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define CMSDK_AT_UART_PID1__JEP106_ID_3_0__RESET_VALUE              0x0000000bU
/** @} */
#define CMSDK_AT_UART_PID1__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID1__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID1__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID1__RESET_VALUE                             0x000000b8U

#endif /* __CMSDK_AT_UART_PID1_MACRO__ */

/** @} end of PID1 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID2 */
/**
 * @defgroup at_apb_uart_regs_core_PID2 PID2
 * @brief Contains register fields associated with PID2. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID2_MACRO__
#define __CMSDK_AT_UART_PID2_MACRO__

/* macros for field jep106_id_6_4 */
/**
 * @defgroup at_apb_uart_regs_core_jep106_id_6_4_field jep106_id_6_4_field
 * @brief macros for field jep106_id_6_4
 * @details jep106_id_6_4
 * @{
 */
#define CMSDK_AT_UART_PID2__JEP106_ID_6_4__SHIFT                              0
#define CMSDK_AT_UART_PID2__JEP106_ID_6_4__WIDTH                              3
#define CMSDK_AT_UART_PID2__JEP106_ID_6_4__MASK                     0x00000007U
#define CMSDK_AT_UART_PID2_JEP106_ID_6_4_Pos \
                    CMSDK_AT_UART_PID2__JEP106_ID_6_4__SHIFT
#define CMSDK_AT_UART_PID2_JEP106_ID_6_4_Msk \
                    CMSDK_AT_UART_PID2__JEP106_ID_6_4__MASK
#define CMSDK_UART_PID2_JEP106_ID_6_4_Pos \
                    CMSDK_AT_UART_PID2__JEP106_ID_6_4__SHIFT
#define CMSDK_UART_PID2_JEP106_ID_6_4_Msk \
                    CMSDK_AT_UART_PID2__JEP106_ID_6_4__MASK
#define CMSDK_AT_UART_PID2__JEP106_ID_6_4__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define CMSDK_AT_UART_PID2__JEP106_ID_6_4__RESET_VALUE              0x00000003U
/** @} */

/* macros for field jedec_used */
/**
 * @defgroup at_apb_uart_regs_core_jedec_used_field jedec_used_field
 * @brief macros for field jedec_used
 * @details jedec_used
 * @{
 */
#define CMSDK_AT_UART_PID2__JEDEC_USED__SHIFT                                 3
#define CMSDK_AT_UART_PID2__JEDEC_USED__WIDTH                                 1
#define CMSDK_AT_UART_PID2__JEDEC_USED__MASK                        0x00000008U
#define CMSDK_AT_UART_PID2_JEDEC_USED_Pos CMSDK_AT_UART_PID2__JEDEC_USED__SHIFT
#define CMSDK_AT_UART_PID2_JEDEC_USED_Msk  CMSDK_AT_UART_PID2__JEDEC_USED__MASK
#define CMSDK_UART_PID2_JEDEC_USED_Pos    CMSDK_AT_UART_PID2__JEDEC_USED__SHIFT
#define CMSDK_UART_PID2_JEDEC_USED_Msk     CMSDK_AT_UART_PID2__JEDEC_USED__MASK
#define CMSDK_AT_UART_PID2__JEDEC_USED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define CMSDK_AT_UART_PID2__JEDEC_USED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define CMSDK_AT_UART_PID2__JEDEC_USED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define CMSDK_AT_UART_PID2__JEDEC_USED__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field rev */
/**
 * @defgroup at_apb_uart_regs_core_rev_field rev_field
 * @brief macros for field rev
 * @details Revision
 * @{
 */
#define CMSDK_AT_UART_PID2__REV__SHIFT                                        4
#define CMSDK_AT_UART_PID2__REV__WIDTH                                        4
#define CMSDK_AT_UART_PID2__REV__MASK                               0x000000f0U
#define CMSDK_AT_UART_PID2_REV_Pos               CMSDK_AT_UART_PID2__REV__SHIFT
#define CMSDK_AT_UART_PID2_REV_Msk                CMSDK_AT_UART_PID2__REV__MASK
#define CMSDK_UART_PID2_REV_Pos                  CMSDK_AT_UART_PID2__REV__SHIFT
#define CMSDK_UART_PID2_REV_Msk                   CMSDK_AT_UART_PID2__REV__MASK
#define CMSDK_AT_UART_PID2__REV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define CMSDK_AT_UART_PID2__REV__RESET_VALUE                        0x00000001U
/** @} */
#define CMSDK_AT_UART_PID2__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID2__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID2__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID2__RESET_VALUE                             0x0000001bU

#endif /* __CMSDK_AT_UART_PID2_MACRO__ */

/** @} end of PID2 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_PID3 */
/**
 * @defgroup at_apb_uart_regs_core_PID3 PID3
 * @brief Contains register fields associated with PID3. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_PID3_MACRO__
#define __CMSDK_AT_UART_PID3_MACRO__

/* macros for field mod_num */
/**
 * @defgroup at_apb_uart_regs_core_mod_num_field mod_num_field
 * @brief macros for field mod_num
 * @details modification number.
 * @{
 */
#define CMSDK_AT_UART_PID3__MOD_NUM__SHIFT                                    0
#define CMSDK_AT_UART_PID3__MOD_NUM__WIDTH                                    4
#define CMSDK_AT_UART_PID3__MOD_NUM__MASK                           0x0000000fU
#define CMSDK_AT_UART_PID3_MOD_NUM_Pos       CMSDK_AT_UART_PID3__MOD_NUM__SHIFT
#define CMSDK_AT_UART_PID3_MOD_NUM_Msk        CMSDK_AT_UART_PID3__MOD_NUM__MASK
#define CMSDK_UART_PID3_MOD_NUM_Pos          CMSDK_AT_UART_PID3__MOD_NUM__SHIFT
#define CMSDK_UART_PID3_MOD_NUM_Msk           CMSDK_AT_UART_PID3__MOD_NUM__MASK
#define CMSDK_AT_UART_PID3__MOD_NUM__READ(src)  ((uint32_t)(src) & 0x0000000fU)
#define CMSDK_AT_UART_PID3__MOD_NUM__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ecorevnum */
/**
 * @defgroup at_apb_uart_regs_core_ecorevnum_field ecorevnum_field
 * @brief macros for field ecorevnum
 * @details ECO revision number.
 * @{
 */
#define CMSDK_AT_UART_PID3__ECOREVNUM__SHIFT                                  4
#define CMSDK_AT_UART_PID3__ECOREVNUM__WIDTH                                  4
#define CMSDK_AT_UART_PID3__ECOREVNUM__MASK                         0x000000f0U
#define CMSDK_AT_UART_PID3_ECOREVNUM_Pos   CMSDK_AT_UART_PID3__ECOREVNUM__SHIFT
#define CMSDK_AT_UART_PID3_ECOREVNUM_Msk    CMSDK_AT_UART_PID3__ECOREVNUM__MASK
#define CMSDK_UART_PID3_ECOREVNUM_Pos      CMSDK_AT_UART_PID3__ECOREVNUM__SHIFT
#define CMSDK_UART_PID3_ECOREVNUM_Msk       CMSDK_AT_UART_PID3__ECOREVNUM__MASK
#define CMSDK_AT_UART_PID3__ECOREVNUM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define CMSDK_AT_UART_PID3__ECOREVNUM__RESET_VALUE                  0x00000000U
/** @} */
#define CMSDK_AT_UART_PID3__TYPE                                       uint32_t
#define CMSDK_AT_UART_PID3__READ                                    0x000000ffU
#define CMSDK_AT_UART_PID3__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_PID3__RESET_VALUE                             0x00000000U

#endif /* __CMSDK_AT_UART_PID3_MACRO__ */

/** @} end of PID3 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_CID0 */
/**
 * @defgroup at_apb_uart_regs_core_CID0 CID0
 * @brief Contains register fields associated with CID0. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_CID0_MACRO__
#define __CMSDK_AT_UART_CID0_MACRO__

/* macros for field cid0 */
/**
 * @defgroup at_apb_uart_regs_core_cid0_field cid0_field
 * @brief macros for field cid0
 * @details Component ID Register 0
 * @{
 */
#define CMSDK_AT_UART_CID0__CID0__SHIFT                                       0
#define CMSDK_AT_UART_CID0__CID0__WIDTH                                       8
#define CMSDK_AT_UART_CID0__CID0__MASK                              0x000000ffU
#define CMSDK_AT_UART_CID0_Pos                  CMSDK_AT_UART_CID0__CID0__SHIFT
#define CMSDK_AT_UART_CID0_Msk                   CMSDK_AT_UART_CID0__CID0__MASK
#define CMSDK_UART_CID0_Pos                     CMSDK_AT_UART_CID0__CID0__SHIFT
#define CMSDK_UART_CID0_Msk                      CMSDK_AT_UART_CID0__CID0__MASK
#define CMSDK_AT_UART_CID0__CID0__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_CID0__CID0__RESET_VALUE                       0x0000000dU
/** @} */
#define CMSDK_AT_UART_CID0__TYPE                                       uint32_t
#define CMSDK_AT_UART_CID0__READ                                    0x000000ffU
#define CMSDK_AT_UART_CID0__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_CID0__RESET_VALUE                             0x0000000dU

#endif /* __CMSDK_AT_UART_CID0_MACRO__ */

/** @} end of CID0 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_CID1 */
/**
 * @defgroup at_apb_uart_regs_core_CID1 CID1
 * @brief Contains register fields associated with CID1. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_CID1_MACRO__
#define __CMSDK_AT_UART_CID1_MACRO__

/* macros for field cid1 */
/**
 * @defgroup at_apb_uart_regs_core_cid1_field cid1_field
 * @brief macros for field cid1
 * @details Component ID Register 1
 * @{
 */
#define CMSDK_AT_UART_CID1__CID1__SHIFT                                       0
#define CMSDK_AT_UART_CID1__CID1__WIDTH                                       8
#define CMSDK_AT_UART_CID1__CID1__MASK                              0x000000ffU
#define CMSDK_AT_UART_CID1_Pos                  CMSDK_AT_UART_CID1__CID1__SHIFT
#define CMSDK_AT_UART_CID1_Msk                   CMSDK_AT_UART_CID1__CID1__MASK
#define CMSDK_UART_CID1_Pos                     CMSDK_AT_UART_CID1__CID1__SHIFT
#define CMSDK_UART_CID1_Msk                      CMSDK_AT_UART_CID1__CID1__MASK
#define CMSDK_AT_UART_CID1__CID1__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_CID1__CID1__RESET_VALUE                       0x000000f0U
/** @} */
#define CMSDK_AT_UART_CID1__TYPE                                       uint32_t
#define CMSDK_AT_UART_CID1__READ                                    0x000000ffU
#define CMSDK_AT_UART_CID1__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_CID1__RESET_VALUE                             0x000000f0U

#endif /* __CMSDK_AT_UART_CID1_MACRO__ */

/** @} end of CID1 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_CID2 */
/**
 * @defgroup at_apb_uart_regs_core_CID2 CID2
 * @brief Contains register fields associated with CID2. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_CID2_MACRO__
#define __CMSDK_AT_UART_CID2_MACRO__

/* macros for field cid2 */
/**
 * @defgroup at_apb_uart_regs_core_cid2_field cid2_field
 * @brief macros for field cid2
 * @details Component ID Register 2
 * @{
 */
#define CMSDK_AT_UART_CID2__CID2__SHIFT                                       0
#define CMSDK_AT_UART_CID2__CID2__WIDTH                                       8
#define CMSDK_AT_UART_CID2__CID2__MASK                              0x000000ffU
#define CMSDK_AT_UART_CID2_Pos                  CMSDK_AT_UART_CID2__CID2__SHIFT
#define CMSDK_AT_UART_CID2_Msk                   CMSDK_AT_UART_CID2__CID2__MASK
#define CMSDK_UART_CID2_Pos                     CMSDK_AT_UART_CID2__CID2__SHIFT
#define CMSDK_UART_CID2_Msk                      CMSDK_AT_UART_CID2__CID2__MASK
#define CMSDK_AT_UART_CID2__CID2__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_CID2__CID2__RESET_VALUE                       0x00000005U
/** @} */
#define CMSDK_AT_UART_CID2__TYPE                                       uint32_t
#define CMSDK_AT_UART_CID2__READ                                    0x000000ffU
#define CMSDK_AT_UART_CID2__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_CID2__RESET_VALUE                             0x00000005U

#endif /* __CMSDK_AT_UART_CID2_MACRO__ */

/** @} end of CID2 */

/* macros for BlueprintGlobalNameSpace::CMSDK_AT_UART_CID3 */
/**
 * @defgroup at_apb_uart_regs_core_CID3 CID3
 * @brief Contains register fields associated with CID3. definitions.
 * @{
 */
#ifndef __CMSDK_AT_UART_CID3_MACRO__
#define __CMSDK_AT_UART_CID3_MACRO__

/* macros for field cid3 */
/**
 * @defgroup at_apb_uart_regs_core_cid3_field cid3_field
 * @brief macros for field cid3
 * @details Component ID Register 3
 * @{
 */
#define CMSDK_AT_UART_CID3__CID3__SHIFT                                       0
#define CMSDK_AT_UART_CID3__CID3__WIDTH                                       8
#define CMSDK_AT_UART_CID3__CID3__MASK                              0x000000ffU
#define CMSDK_AT_UART_CID3_Pos                  CMSDK_AT_UART_CID3__CID3__SHIFT
#define CMSDK_AT_UART_CID3_Msk                   CMSDK_AT_UART_CID3__CID3__MASK
#define CMSDK_UART_CID3_Pos                     CMSDK_AT_UART_CID3__CID3__SHIFT
#define CMSDK_UART_CID3_Msk                      CMSDK_AT_UART_CID3__CID3__MASK
#define CMSDK_AT_UART_CID3__CID3__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define CMSDK_AT_UART_CID3__CID3__RESET_VALUE                       0x000000b1U
/** @} */
#define CMSDK_AT_UART_CID3__TYPE                                       uint32_t
#define CMSDK_AT_UART_CID3__READ                                    0x000000ffU
#define CMSDK_AT_UART_CID3__PRESERVED                               0x00000000U
#define CMSDK_AT_UART_CID3__RESET_VALUE                             0x000000b1U

#endif /* __CMSDK_AT_UART_CID3_MACRO__ */

/** @} end of CID3 */

/** @} end of AT_APB_UART_REGS_CORE */
#endif /* __REG_AT_APB_UART_REGS_CORE_H__ */
