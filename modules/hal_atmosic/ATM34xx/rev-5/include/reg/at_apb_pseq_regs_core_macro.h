/*                                                                           */
/* File:       at_apb_pseq_perth_regs_core_macro.h                           */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_pseq_perth_regs_core.rdl    */
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


#ifndef __REG_AT_APB_PSEQ_PERTH_REGS_CORE_H__
#define __REG_AT_APB_PSEQ_PERTH_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_PSEQ_PERTH_REGS_CORE at_apb_pseq_perth_regs_core
 * @ingroup AT_REG
 * @brief at_apb_pseq_perth_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::PSEQ_ctrl0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ctrl0 ctrl0
 * @brief signals to prepare for and to request low power state definitions.
 * @{
 */
#ifndef __PSEQ_CTRL0_MACRO__
#define __PSEQ_CTRL0_MACRO__

/* macros for field manage_xtal */
/**
 * @defgroup at_apb_pseq_perth_regs_core_manage_xtal_field manage_xtal_field
 * @brief macros for field manage_xtal
 * @details If set, permits SOC to power down clk_mpc crystal circuit during low power mode.
 * @{
 */
#define PSEQ_CTRL0__MANAGE_XTAL__SHIFT                                        0
#define PSEQ_CTRL0__MANAGE_XTAL__WIDTH                                        1
#define PSEQ_CTRL0__MANAGE_XTAL__MASK                               0x00000001U
#define PSEQ_CTRL0__MANAGE_XTAL__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define PSEQ_CTRL0__MANAGE_XTAL__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define PSEQ_CTRL0__MANAGE_XTAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_CTRL0__MANAGE_XTAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_CTRL0__MANAGE_XTAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_CTRL0__MANAGE_XTAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_CTRL0__MANAGE_XTAL__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field req_ble_only_lp_state */
/**
 * @defgroup at_apb_pseq_perth_regs_core_req_ble_only_lp_state_field req_ble_only_lp_state_field
 * @brief macros for field req_ble_only_lp_state
 * @details If set, requests SOC to go to BLE Only low power state.
 * @{
 */
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__SHIFT                              1
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__WIDTH                              1
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__MASK                     0x00000002U
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_CTRL0__REQ_BLE_ONLY_LP_STATE__RESET_VALUE              0x00000000U
/** @} */

/* macros for field req_retain_all_state */
/**
 * @defgroup at_apb_pseq_perth_regs_core_req_retain_all_state_field req_retain_all_state_field
 * @brief macros for field req_retain_all_state
 * @details If set, requests SOC to go to Retain All low power state.
 * @{
 */
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__SHIFT                               2
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__WIDTH                               1
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__MASK                      0x00000004U
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_CTRL0__REQ_RETAIN_ALL_STATE__RESET_VALUE               0x00000000U
/** @} */

/* macros for field req_hibernate_state */
/**
 * @defgroup at_apb_pseq_perth_regs_core_req_hibernate_state_field req_hibernate_state_field
 * @brief macros for field req_hibernate_state
 * @details If set, requests SOC to go to Hibernate low power state.
 * @{
 */
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__SHIFT                                3
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__WIDTH                                1
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__MASK                       0x00000008U
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_CTRL0__REQ_HIBERNATE_STATE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field req_hib_to_act */
/**
 * @defgroup at_apb_pseq_perth_regs_core_req_hib_to_act_field req_hib_to_act_field
 * @brief macros for field req_hib_to_act
 * @details If set, requests SOC to go from hibernate state to active state
 * @{
 */
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__SHIFT                                     4
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__WIDTH                                     1
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__MASK                            0x00000010U
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_CTRL0__REQ_HIB_TO_ACT__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field enable_debug_bus */
/**
 * @defgroup at_apb_pseq_perth_regs_core_enable_debug_bus_field enable_debug_bus_field
 * @brief macros for field enable_debug_bus
 * @details If set, pseq debug bus will be enabled (e.g. allowed to start toggling at pinmux input).
 * @{
 */
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__SHIFT                                   5
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__WIDTH                                   1
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__MASK                          0x00000020U
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_CTRL0__ENABLE_DEBUG_BUS__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field req_ble_to_boot */
/**
 * @defgroup at_apb_pseq_perth_regs_core_req_ble_to_boot_field req_ble_to_boot_field
 * @brief macros for field req_ble_to_boot
 * @details If set, requests that ble powers up.
 * @{
 */
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__SHIFT                                    6
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__WIDTH                                    1
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__MASK                           0x00000040U
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_CTRL0__REQ_BLE_TO_BOOT__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field pwm_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pwm_latch_open_field pwm_latch_open_field
 * @brief macros for field pwm_latch_open
 * @details If set, opens all latches on pwm output prior to entering low power to hold pwm.
 * @{
 */
#define PSEQ_CTRL0__PWM_LATCH_OPEN__SHIFT                                     7
#define PSEQ_CTRL0__PWM_LATCH_OPEN__WIDTH                                     1
#define PSEQ_CTRL0__PWM_LATCH_OPEN__MASK                            0x00000080U
#define PSEQ_CTRL0__PWM_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_CTRL0__PWM_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_CTRL0__PWM_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_CTRL0__PWM_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_CTRL0__PWM_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_CTRL0__PWM_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_CTRL0__PWM_LATCH_OPEN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field fast_ret */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fast_ret_field fast_ret_field
 * @brief macros for field fast_ret
 * @details If set, primary and secondary retention switches for cpu subsystem are sequenced at the same time their source supply is changing.
 * @{
 */
#define PSEQ_CTRL0__FAST_RET__SHIFT                                           8
#define PSEQ_CTRL0__FAST_RET__WIDTH                                           1
#define PSEQ_CTRL0__FAST_RET__MASK                                  0x00000100U
#define PSEQ_CTRL0__FAST_RET__READ(src)  (((uint32_t)(src) & 0x00000100U) >> 8)
#define PSEQ_CTRL0__FAST_RET__WRITE(src) (((uint32_t)(src) << 8) & 0x00000100U)
#define PSEQ_CTRL0__FAST_RET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_CTRL0__FAST_RET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_CTRL0__FAST_RET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_CTRL0__FAST_RET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_CTRL0__FAST_RET__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field uart_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_uart_latch_open_field uart_latch_open_field
 * @brief macros for field uart_latch_open
 * @details If set, opens all latches on uart0/1 rts signals.
 * @{
 */
#define PSEQ_CTRL0__UART_LATCH_OPEN__SHIFT                                   10
#define PSEQ_CTRL0__UART_LATCH_OPEN__WIDTH                                    1
#define PSEQ_CTRL0__UART_LATCH_OPEN__MASK                           0x00000400U
#define PSEQ_CTRL0__UART_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_CTRL0__UART_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_CTRL0__UART_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_CTRL0__UART_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_CTRL0__UART_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_CTRL0__UART_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_CTRL0__UART_LATCH_OPEN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field xtal_waits_for_retv */
/**
 * @defgroup at_apb_pseq_perth_regs_core_xtal_waits_for_retv_field xtal_waits_for_retv_field
 * @brief macros for field xtal_waits_for_retv
 * @details If set, xtal will not be enabled until the retention voltage has been boosted back up to nominal value.
 * @{
 */
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__SHIFT                               16
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__WIDTH                                1
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__MASK                       0x00010000U
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_CTRL0__XTAL_WAITS_FOR_RETV__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ble_boosts_retv */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ble_boosts_retv_field ble_boosts_retv_field
 * @brief macros for field ble_boosts_retv
 * @details If set, any time ble requests the clk_mpc oscillator, the retention voltage is boosted back up to nominal value.
 * @{
 */
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__SHIFT                                   17
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__WIDTH                                    1
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__MASK                           0x00020000U
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_CTRL0__BLE_BOOSTS_RETV__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field block_dbg_wake */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_dbg_wake_field block_dbg_wake_field
 * @brief macros for field block_dbg_wake
 * @details If set, debugger cannot wake chip from low power state.
 * @{
 */
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__SHIFT                                    18
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__WIDTH                                     1
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__MASK                            0x00040000U
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_CTRL0__BLOCK_DBG_WAKE__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field wurx_det0_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_det0_sel_field wurx_det0_sel_field
 * @brief macros for field wurx_det0_sel
 * @details Is wurx0 detect level or edge?  0=level  1=rising  2,3=falling
 * @{
 */
#define PSEQ_CTRL0__WURX_DET0_SEL__SHIFT                                     19
#define PSEQ_CTRL0__WURX_DET0_SEL__WIDTH                                      2
#define PSEQ_CTRL0__WURX_DET0_SEL__MASK                             0x00180000U
#define PSEQ_CTRL0__WURX_DET0_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define PSEQ_CTRL0__WURX_DET0_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define PSEQ_CTRL0__WURX_DET0_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define PSEQ_CTRL0__WURX_DET0_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define PSEQ_CTRL0__WURX_DET0_SEL__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field wurx_det1_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_det1_sel_field wurx_det1_sel_field
 * @brief macros for field wurx_det1_sel
 * @details Is wurx1 detect level or edge?  0=level  1=rising  2,3=falling
 * @{
 */
#define PSEQ_CTRL0__WURX_DET1_SEL__SHIFT                                     21
#define PSEQ_CTRL0__WURX_DET1_SEL__WIDTH                                      2
#define PSEQ_CTRL0__WURX_DET1_SEL__MASK                             0x00600000U
#define PSEQ_CTRL0__WURX_DET1_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define PSEQ_CTRL0__WURX_DET1_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define PSEQ_CTRL0__WURX_DET1_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define PSEQ_CTRL0__WURX_DET1_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define PSEQ_CTRL0__WURX_DET1_SEL__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field radio_en_i_src */
/**
 * @defgroup at_apb_pseq_perth_regs_core_radio_en_i_src_field radio_en_i_src_field
 * @brief macros for field radio_en_i_src
 * @details Source of radio enable request signal.  0=direct/rw_cm_timing_gen_lp  1=indirect/rif
 * @{
 */
#define PSEQ_CTRL0__RADIO_EN_I_SRC__SHIFT                                    23
#define PSEQ_CTRL0__RADIO_EN_I_SRC__WIDTH                                     1
#define PSEQ_CTRL0__RADIO_EN_I_SRC__MASK                            0x00800000U
#define PSEQ_CTRL0__RADIO_EN_I_SRC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PSEQ_CTRL0__RADIO_EN_I_SRC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PSEQ_CTRL0__RADIO_EN_I_SRC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PSEQ_CTRL0__RADIO_EN_I_SRC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PSEQ_CTRL0__RADIO_EN_I_SRC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PSEQ_CTRL0__RADIO_EN_I_SRC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PSEQ_CTRL0__RADIO_EN_I_SRC__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field pinsel_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pinsel_latch_open_field pinsel_latch_open_field
 * @brief macros for field pinsel_latch_open
 * @details If set, opens all latches all pin select signals.
 * @{
 */
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__SHIFT                                 24
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__WIDTH                                  1
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__MASK                         0x01000000U
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PSEQ_CTRL0__PINSEL_LATCH_OPEN__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field ksm_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ksm_latch_open_field ksm_latch_open_field
 * @brief macros for field ksm_latch_open
 * @details If set, opens all latches on ksm control signals.
 * @{
 */
#define PSEQ_CTRL0__KSM_LATCH_OPEN__SHIFT                                    25
#define PSEQ_CTRL0__KSM_LATCH_OPEN__WIDTH                                     1
#define PSEQ_CTRL0__KSM_LATCH_OPEN__MASK                            0x02000000U
#define PSEQ_CTRL0__KSM_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PSEQ_CTRL0__KSM_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PSEQ_CTRL0__KSM_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PSEQ_CTRL0__KSM_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PSEQ_CTRL0__KSM_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PSEQ_CTRL0__KSM_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PSEQ_CTRL0__KSM_LATCH_OPEN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field gpio_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_latch_open_field gpio_latch_open_field
 * @brief macros for field gpio_latch_open
 * @details If set, opens all latches on gpio control signals.
 * @{
 */
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__SHIFT                                   26
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__WIDTH                                    1
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__MASK                           0x04000000U
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PSEQ_CTRL0__GPIO_LATCH_OPEN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field req_soc_off */
/**
 * @defgroup at_apb_pseq_perth_regs_core_req_soc_off_field req_soc_off_field
 * @brief macros for field req_soc_off
 * @details If set, requests SOC to go SOC Off state.
 * @{
 */
#define PSEQ_CTRL0__REQ_SOC_OFF__SHIFT                                       27
#define PSEQ_CTRL0__REQ_SOC_OFF__WIDTH                                        1
#define PSEQ_CTRL0__REQ_SOC_OFF__MASK                               0x08000000U
#define PSEQ_CTRL0__REQ_SOC_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PSEQ_CTRL0__REQ_SOC_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PSEQ_CTRL0__REQ_SOC_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PSEQ_CTRL0__REQ_SOC_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PSEQ_CTRL0__REQ_SOC_OFF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PSEQ_CTRL0__REQ_SOC_OFF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PSEQ_CTRL0__REQ_SOC_OFF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field pinpu_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pinpu_latch_open_field pinpu_latch_open_field
 * @brief macros for field pinpu_latch_open
 * @details If set, opens all latches on all pin pu signals.
 * @{
 */
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__SHIFT                                  28
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__WIDTH                                   1
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__MASK                          0x10000000U
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PSEQ_CTRL0__PINPU_LATCH_OPEN__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field i2c_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_i2c_latch_open_field i2c_latch_open_field
 * @brief macros for field i2c_latch_open
 * @details If set, opens all latches on i2c 0/1 sck/sda pu signals.
 * @{
 */
#define PSEQ_CTRL0__I2C_LATCH_OPEN__SHIFT                                    29
#define PSEQ_CTRL0__I2C_LATCH_OPEN__WIDTH                                     1
#define PSEQ_CTRL0__I2C_LATCH_OPEN__MASK                            0x20000000U
#define PSEQ_CTRL0__I2C_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PSEQ_CTRL0__I2C_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PSEQ_CTRL0__I2C_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PSEQ_CTRL0__I2C_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PSEQ_CTRL0__I2C_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PSEQ_CTRL0__I2C_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PSEQ_CTRL0__I2C_LATCH_OPEN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field spi_latch_open */
/**
 * @defgroup at_apb_pseq_perth_regs_core_spi_latch_open_field spi_latch_open_field
 * @brief macros for field spi_latch_open
 * @details If set, opens all latches on spi0 slave control signals.
 * @{
 */
#define PSEQ_CTRL0__SPI_LATCH_OPEN__SHIFT                                    30
#define PSEQ_CTRL0__SPI_LATCH_OPEN__WIDTH                                     1
#define PSEQ_CTRL0__SPI_LATCH_OPEN__MASK                            0x40000000U
#define PSEQ_CTRL0__SPI_LATCH_OPEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PSEQ_CTRL0__SPI_LATCH_OPEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PSEQ_CTRL0__SPI_LATCH_OPEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PSEQ_CTRL0__SPI_LATCH_OPEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PSEQ_CTRL0__SPI_LATCH_OPEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PSEQ_CTRL0__SPI_LATCH_OPEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PSEQ_CTRL0__SPI_LATCH_OPEN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field req_shub_adv */
/**
 * @defgroup at_apb_pseq_perth_regs_core_req_shub_adv_field req_shub_adv_field
 * @brief macros for field req_shub_adv
 * @details If set, requests SOC to go to do CPU-less adv.
 * @{
 */
#define PSEQ_CTRL0__REQ_SHUB_ADV__SHIFT                                      31
#define PSEQ_CTRL0__REQ_SHUB_ADV__WIDTH                                       1
#define PSEQ_CTRL0__REQ_SHUB_ADV__MASK                              0x80000000U
#define PSEQ_CTRL0__REQ_SHUB_ADV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PSEQ_CTRL0__REQ_SHUB_ADV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PSEQ_CTRL0__REQ_SHUB_ADV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PSEQ_CTRL0__REQ_SHUB_ADV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PSEQ_CTRL0__REQ_SHUB_ADV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PSEQ_CTRL0__REQ_SHUB_ADV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PSEQ_CTRL0__REQ_SHUB_ADV__RESET_VALUE                       0x00000000U
/** @} */
#define PSEQ_CTRL0__TYPE                                               uint32_t
#define PSEQ_CTRL0__READ                                            0xffff05ffU
#define PSEQ_CTRL0__WRITE                                           0xffff05ffU
#define PSEQ_CTRL0__PRESERVED                                       0x00000000U
#define PSEQ_CTRL0__RESET_VALUE                                     0x002a0000U

#endif /* __PSEQ_CTRL0_MACRO__ */

/** @} end of ctrl0 */

/* macros for BlueprintGlobalNameSpace::PSEQ_ctrl1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ctrl1 ctrl1
 * @brief signals to prepare for and to request low power state definitions.
 * @{
 */
#ifndef __PSEQ_CTRL1_MACRO__
#define __PSEQ_CTRL1_MACRO__

/* macros for field energy4CPU_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4CPU_sel_field energy4CPU_sel_field
 * @brief macros for field energy4CPU_sel
 * @details Is energy4CPU level or edge?  0=level  1=rising  2=falling  3=negate level
 * @{
 */
#define PSEQ_CTRL1__ENERGY4CPU_SEL__SHIFT                                     0
#define PSEQ_CTRL1__ENERGY4CPU_SEL__WIDTH                                     2
#define PSEQ_CTRL1__ENERGY4CPU_SEL__MASK                            0x00000003U
#define PSEQ_CTRL1__ENERGY4CPU_SEL__READ(src)   ((uint32_t)(src) & 0x00000003U)
#define PSEQ_CTRL1__ENERGY4CPU_SEL__WRITE(src)  ((uint32_t)(src) & 0x00000003U)
#define PSEQ_CTRL1__ENERGY4CPU_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_CTRL1__ENERGY4CPU_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_CTRL1__ENERGY4CPU_SEL__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field energy4TX_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4TX_sel_field energy4TX_sel_field
 * @brief macros for field energy4TX_sel
 * @details Is energy4TX level or edge?  0=level  1=rising  2=falling  3=negate level
 * @{
 */
#define PSEQ_CTRL1__ENERGY4TX_SEL__SHIFT                                      2
#define PSEQ_CTRL1__ENERGY4TX_SEL__WIDTH                                      2
#define PSEQ_CTRL1__ENERGY4TX_SEL__MASK                             0x0000000cU
#define PSEQ_CTRL1__ENERGY4TX_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define PSEQ_CTRL1__ENERGY4TX_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define PSEQ_CTRL1__ENERGY4TX_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define PSEQ_CTRL1__ENERGY4TX_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define PSEQ_CTRL1__ENERGY4TX_SEL__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field endoflife_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_endoflife_sel_field endoflife_sel_field
 * @brief macros for field endoflife_sel
 * @details Is endoflife level or edge?  0=level  1=rising  2=falling  3=negate level
 * @{
 */
#define PSEQ_CTRL1__ENDOFLIFE_SEL__SHIFT                                      4
#define PSEQ_CTRL1__ENDOFLIFE_SEL__WIDTH                                      2
#define PSEQ_CTRL1__ENDOFLIFE_SEL__MASK                             0x00000030U
#define PSEQ_CTRL1__ENDOFLIFE_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define PSEQ_CTRL1__ENDOFLIFE_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define PSEQ_CTRL1__ENDOFLIFE_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define PSEQ_CTRL1__ENDOFLIFE_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define PSEQ_CTRL1__ENDOFLIFE_SEL__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field brownout_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_brownout_sel_field brownout_sel_field
 * @brief macros for field brownout_sel
 * @details Is brownout level or edge?  0=level  1=rising  2=falling  3=negate level
 * @{
 */
#define PSEQ_CTRL1__BROWNOUT_SEL__SHIFT                                       6
#define PSEQ_CTRL1__BROWNOUT_SEL__WIDTH                                       2
#define PSEQ_CTRL1__BROWNOUT_SEL__MASK                              0x000000c0U
#define PSEQ_CTRL1__BROWNOUT_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000c0U) >> 6)
#define PSEQ_CTRL1__BROWNOUT_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000000c0U)
#define PSEQ_CTRL1__BROWNOUT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((uint32_t)(src) <<\
                    6) & 0x000000c0U)
#define PSEQ_CTRL1__BROWNOUT_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000000c0U)))
#define PSEQ_CTRL1__BROWNOUT_SEL__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field reset_wurx_spi_regs */
/**
 * @defgroup at_apb_pseq_perth_regs_core_reset_wurx_spi_regs_field reset_wurx_spi_regs_field
 * @brief macros for field reset_wurx_spi_regs
 * @{
 */
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__SHIFT                                8
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__WIDTH                                1
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__MASK                       0x00000100U
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_CTRL1__RESET_WURX_SPI_REGS__RESET_VALUE                0x00000000U
/** @} */

/* macros for field reset_radio_spi_regs */
/**
 * @defgroup at_apb_pseq_perth_regs_core_reset_radio_spi_regs_field reset_radio_spi_regs_field
 * @brief macros for field reset_radio_spi_regs
 * @{
 */
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__SHIFT                               9
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__WIDTH                               1
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__MASK                      0x00000200U
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_CTRL1__RESET_RADIO_SPI_REGS__RESET_VALUE               0x00000000U
/** @} */

/* macros for field reset_pmu_spi_regs */
/**
 * @defgroup at_apb_pseq_perth_regs_core_reset_pmu_spi_regs_field reset_pmu_spi_regs_field
 * @brief macros for field reset_pmu_spi_regs
 * @{
 */
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__SHIFT                                10
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__WIDTH                                 1
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__MASK                        0x00000400U
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_CTRL1__RESET_PMU_SPI_REGS__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field manage_rram_vddio */
/**
 * @defgroup at_apb_pseq_perth_regs_core_manage_rram_vddio_field manage_rram_vddio_field
 * @brief macros for field manage_rram_vddio
 * @details If set, the pseq will disable the rram vddio supply during hibernate and retain low power states.
 * @{
 */
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__SHIFT                                 11
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__WIDTH                                  1
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__MASK                         0x00000800U
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_CTRL1__MANAGE_RRAM_VDDIO__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field block_early_radio_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_early_radio_en_field block_early_radio_en_field
 * @brief macros for field block_early_radio_en
 * @{
 */
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__SHIFT                              12
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__WIDTH                               1
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__MASK                      0x00001000U
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_CTRL1__BLOCK_EARLY_RADIO_EN__RESET_VALUE               0x00000000U
/** @} */

/* macros for field block_mdm_rif_regs_reset */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_mdm_rif_regs_reset_field block_mdm_rif_regs_reset_field
 * @brief macros for field block_mdm_rif_regs_reset
 * @details If set, blocks resetting mdm/rif registers when returning from hibernate state.
 * @{
 */
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__SHIFT                          13
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__WIDTH                           1
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__MASK                  0x00002000U
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_CTRL1__BLOCK_MDM_RIF_REGS_RESET__RESET_VALUE           0x00000000U
/** @} */

/* macros for field en_clk_cp_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_en_clk_cp_sel_field en_clk_cp_sel_field
 * @brief macros for field en_clk_cp_sel
 * @{
 */
#define PSEQ_CTRL1__EN_CLK_CP_SEL__SHIFT                                     14
#define PSEQ_CTRL1__EN_CLK_CP_SEL__WIDTH                                      1
#define PSEQ_CTRL1__EN_CLK_CP_SEL__MASK                             0x00004000U
#define PSEQ_CTRL1__EN_CLK_CP_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_CTRL1__EN_CLK_CP_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_CTRL1__EN_CLK_CP_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_CTRL1__EN_CLK_CP_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_CTRL1__EN_CLK_CP_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_CTRL1__EN_CLK_CP_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_CTRL1__EN_CLK_CP_SEL__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field rram_nap_req */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rram_nap_req_field rram_nap_req_field
 * @brief macros for field rram_nap_req
 * @{
 */
#define PSEQ_CTRL1__RRAM_NAP_REQ__SHIFT                                      15
#define PSEQ_CTRL1__RRAM_NAP_REQ__WIDTH                                       1
#define PSEQ_CTRL1__RRAM_NAP_REQ__MASK                              0x00008000U
#define PSEQ_CTRL1__RRAM_NAP_REQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_CTRL1__RRAM_NAP_REQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_CTRL1__RRAM_NAP_REQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_CTRL1__RRAM_NAP_REQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_CTRL1__RRAM_NAP_REQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_CTRL1__RRAM_NAP_REQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_CTRL1__RRAM_NAP_REQ__RESET_VALUE                       0x00000000U
/** @} */
#define PSEQ_CTRL1__TYPE                                               uint32_t
#define PSEQ_CTRL1__READ                                            0x0000ffffU
#define PSEQ_CTRL1__WRITE                                           0x0000ffffU
#define PSEQ_CTRL1__PRESERVED                                       0x00000000U
#define PSEQ_CTRL1__RESET_VALUE                                     0x00000055U

#endif /* __PSEQ_CTRL1_MACRO__ */

/** @} end of ctrl1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_retain_all_wake_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_retain_all_wake_mask retain_all_wake_mask
 * @brief signals to select which events can generate a wake event while in Retain All definitions.
 * @{
 */
#ifndef __PSEQ_RETAIN_ALL_WAKE_MASK_MACRO__
#define __PSEQ_RETAIN_ALL_WAKE_MASK_MACRO__

/* macros for field watch_gpio */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_gpio_field watch_gpio_field
 * @brief macros for field watch_gpio
 * @details valid to wake on gpio activity
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__SHIFT                          0
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__WIDTH                          1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__MASK                 0x00000001U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_GPIO__RESET_VALUE          0x00000000U
/** @} */

/* macros for field watch_cntdown */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_cntdown_field watch_cntdown_field
 * @brief macros for field watch_cntdown
 * @details valid to wake on count down timer expiring
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__SHIFT                       1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__WIDTH                       1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__MASK              0x00000002U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_CNTDOWN__RESET_VALUE       0x00000000U
/** @} */

/* macros for field watch_wurx0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx0_field watch_wurx0_field
 * @brief macros for field watch_wurx0
 * @details valid to wake on wurx0 detect
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__SHIFT                         2
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__WIDTH                         1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__MASK                0x00000004U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX0__RESET_VALUE         0x00000000U
/** @} */

/* macros for field watch_wurx1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx1_field watch_wurx1_field
 * @brief macros for field watch_wurx1
 * @details valid to wake on wurx1 detect
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__SHIFT                         3
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__WIDTH                         1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__MASK                0x00000008U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX1__RESET_VALUE         0x00000000U
/** @} */

/* macros for field watch_qdec */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_qdec_field watch_qdec_field
 * @brief macros for field watch_qdec
 * @details valid to wake on qdec activity
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__SHIFT                          4
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__WIDTH                          1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__MASK                 0x00000010U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_QDEC__RESET_VALUE          0x00000000U
/** @} */

/* macros for field watch_ksm */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_ksm_field watch_ksm_field
 * @brief macros for field watch_ksm
 * @details valid to wake on keyboard activity
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__SHIFT                           5
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__WIDTH                           1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__MASK                  0x00000020U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_KSM__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_shub */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_shub_field watch_shub_field
 * @brief macros for field watch_shub
 * @details valid to wake on sensor hub trigger
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__SHIFT                          6
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__WIDTH                          1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__MASK                 0x00000040U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SHUB__RESET_VALUE          0x00000000U
/** @} */

/* macros for field watch_spi */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_spi_field watch_spi_field
 * @brief macros for field watch_spi
 * @details valid to wake on spi slave activity
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__SHIFT                           7
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__WIDTH                           1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__MASK                  0x00000080U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_SPI__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_i2c */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_i2c_field watch_i2c_field
 * @brief macros for field watch_i2c
 * @details valid to wake on i2c slave activity
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__SHIFT                           8
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__WIDTH                           1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__MASK                  0x00000100U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_I2C__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_pmu_lpcomp */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_lpcomp_field watch_pmu_lpcomp_field
 * @brief macros for field watch_pmu_lpcomp
 * @details valid to wake on pmu lpcomp threshold crossing
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__SHIFT                    9
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__WIDTH                    1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__MASK           0x00000200U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_LPCOMP__RESET_VALUE    0x00000000U
/** @} */

/* macros for field watch_pmu_timer */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_timer_field watch_pmu_timer_field
 * @brief macros for field watch_pmu_timer
 * @details valid to wake on pmu timer expiring
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__SHIFT                    10
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__WIDTH                     1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__MASK            0x00000400U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_TIMER__RESET_VALUE     0x00000000U
/** @} */

/* macros for field watch_energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_energy4CPU_field watch_energy4CPU_field
 * @brief macros for field watch_energy4CPU
 * @details valid to wake on pmu asserting energy4CPU
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__SHIFT                   11
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__WIDTH                    1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__MASK           0x00000800U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4CPU__RESET_VALUE    0x00000000U
/** @} */

/* macros for field watch_energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_energy4TX_field watch_energy4TX_field
 * @brief macros for field watch_energy4TX
 * @details valid to wake on pmu asserting energy4TX
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__SHIFT                    12
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__WIDTH                     1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__MASK            0x00001000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENERGY4TX__RESET_VALUE     0x00000000U
/** @} */

/* macros for field watch_endoflife */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_endoflife_field watch_endoflife_field
 * @brief macros for field watch_endoflife
 * @details valid to wake on pmu asserting endoflife
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__SHIFT                    13
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__WIDTH                     1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__MASK            0x00002000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_ENDOFLIFE__RESET_VALUE     0x00000000U
/** @} */

/* macros for field watch_brownout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_brownout_field watch_brownout_field
 * @brief macros for field watch_brownout
 * @details valid to wake on pmu asserting brownout
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__SHIFT                     14
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__WIDTH                      1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__MASK             0x00004000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BROWNOUT__RESET_VALUE      0x00000000U
/** @} */

/* macros for field watch_wurx */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx_field watch_wurx_field
 * @brief macros for field watch_wurx
 * @details valid to wake on multiple wurx detects in certain amount of time
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__SHIFT                         15
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__WIDTH                          1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__MASK                 0x00008000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_WURX__RESET_VALUE          0x00000000U
/** @} */

/* macros for field watch_ble_osc_on */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_ble_osc_on_field watch_ble_osc_on_field
 * @brief macros for field watch_ble_osc_on
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__SHIFT                   16
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__WIDTH                    1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__MASK           0x00010000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_BLE_OSC_ON__RESET_VALUE    0x00000000U
/** @} */

/* macros for field watch_frc_match0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_frc_match0_field watch_frc_match0_field
 * @brief macros for field watch_frc_match0
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__SHIFT                   17
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__WIDTH                    1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__MASK           0x00020000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH0__RESET_VALUE    0x00000000U
/** @} */

/* macros for field watch_frc_match1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_frc_match1_field watch_frc_match1_field
 * @brief macros for field watch_frc_match1
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__SHIFT                   18
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__WIDTH                    1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__MASK           0x00040000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_FRC_MATCH1__RESET_VALUE    0x00000000U
/** @} */

/* macros for field watch_pmu_wdog_warn */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_wdog_warn_field watch_pmu_wdog_warn_field
 * @brief macros for field watch_pmu_wdog_warn
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__SHIFT                19
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__WIDTH                 1
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__MASK        0x00080000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PSEQ_RETAIN_ALL_WAKE_MASK__WATCH_PMU_WDOG_WARN__RESET_VALUE 0x00000000U
/** @} */

/* macros for field qualify_on_energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_qualify_on_energy4TX_field qualify_on_energy4TX_field
 * @brief macros for field qualify_on_energy4TX
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__SHIFT               30
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__WIDTH                1
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__MASK       0x40000000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4TX__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field qualify_on_energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_qualify_on_energy4CPU_field qualify_on_energy4CPU_field
 * @brief macros for field qualify_on_energy4CPU
 * @{
 */
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__SHIFT              31
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__WIDTH               1
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__MASK      0x80000000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PSEQ_RETAIN_ALL_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RETAIN_ALL_WAKE_MASK__TYPE                                uint32_t
#define PSEQ_RETAIN_ALL_WAKE_MASK__READ                             0xc00fffffU
#define PSEQ_RETAIN_ALL_WAKE_MASK__WRITE                            0xc00fffffU
#define PSEQ_RETAIN_ALL_WAKE_MASK__PRESERVED                        0x00000000U
#define PSEQ_RETAIN_ALL_WAKE_MASK__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RETAIN_ALL_WAKE_MASK_MACRO__ */

/** @} end of retain_all_wake_mask */

/* macros for BlueprintGlobalNameSpace::PSEQ_hib_wake_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_hib_wake_mask hib_wake_mask
 * @brief signals to select which events can generate a wake event while in Hiberbate definitions.
 * @{
 */
#ifndef __PSEQ_HIB_WAKE_MASK_MACRO__
#define __PSEQ_HIB_WAKE_MASK_MACRO__

/* macros for field watch_gpio */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_gpio_field watch_gpio_field
 * @brief macros for field watch_gpio
 * @details valid to wake on gpio activity
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__SHIFT                                 0
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__WIDTH                                 1
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__MASK                        0x00000001U
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_HIB_WAKE_MASK__WATCH_GPIO__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field watch_cntdown */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_cntdown_field watch_cntdown_field
 * @brief macros for field watch_cntdown
 * @details valid to wake on count down timer expiring
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__SHIFT                              1
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__WIDTH                              1
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__MASK                     0x00000002U
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_HIB_WAKE_MASK__WATCH_CNTDOWN__RESET_VALUE              0x00000000U
/** @} */

/* macros for field watch_wurx0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx0_field watch_wurx0_field
 * @brief macros for field watch_wurx0
 * @details valid to wake on wurx0 detect
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__SHIFT                                2
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__WIDTH                                1
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__MASK                       0x00000004U
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX0__RESET_VALUE                0x00000000U
/** @} */

/* macros for field watch_wurx1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx1_field watch_wurx1_field
 * @brief macros for field watch_wurx1
 * @details valid to wake on wurx1 detect
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__SHIFT                                3
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__WIDTH                                1
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__MASK                       0x00000008U
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX1__RESET_VALUE                0x00000000U
/** @} */

/* macros for field watch_qdec */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_qdec_field watch_qdec_field
 * @brief macros for field watch_qdec
 * @details valid to wake on qdec activity
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__SHIFT                                 4
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__WIDTH                                 1
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__MASK                        0x00000010U
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_HIB_WAKE_MASK__WATCH_QDEC__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field watch_ksm */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_ksm_field watch_ksm_field
 * @brief macros for field watch_ksm
 * @details valid to wake on keyboard activity
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__SHIFT                                  5
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__WIDTH                                  1
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__MASK                         0x00000020U
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_HIB_WAKE_MASK__WATCH_KSM__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field watch_shub */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_shub_field watch_shub_field
 * @brief macros for field watch_shub
 * @details valid to wake on sensor hub trigger
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__SHIFT                                 6
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__WIDTH                                 1
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__MASK                        0x00000040U
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_HIB_WAKE_MASK__WATCH_SHUB__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field watch_spi */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_spi_field watch_spi_field
 * @brief macros for field watch_spi
 * @details valid to wake on spi slave activity
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__SHIFT                                  7
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__WIDTH                                  1
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__MASK                         0x00000080U
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_HIB_WAKE_MASK__WATCH_SPI__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field watch_i2c */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_i2c_field watch_i2c_field
 * @brief macros for field watch_i2c
 * @details valid to wake on i2c slave activity
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__SHIFT                                  8
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__WIDTH                                  1
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__MASK                         0x00000100U
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_HIB_WAKE_MASK__WATCH_I2C__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field watch_pmu_lpcomp */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_lpcomp_field watch_pmu_lpcomp_field
 * @brief macros for field watch_pmu_lpcomp
 * @details valid to wake on pmu lpcomp threshold crossing
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__SHIFT                           9
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__WIDTH                           1
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__MASK                  0x00000200U
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_LPCOMP__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_pmu_timer */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_timer_field watch_pmu_timer_field
 * @brief macros for field watch_pmu_timer
 * @details valid to wake on pmu timer expiring
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__SHIFT                           10
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__WIDTH                            1
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__MASK                   0x00000400U
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_TIMER__RESET_VALUE            0x00000000U
/** @} */

/* macros for field watch_energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_energy4CPU_field watch_energy4CPU_field
 * @brief macros for field watch_energy4CPU
 * @details valid to wake on pmu asserting energy4CPU
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__SHIFT                          11
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__WIDTH                           1
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__MASK                  0x00000800U
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4CPU__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_energy4TX_field watch_energy4TX_field
 * @brief macros for field watch_energy4TX
 * @details valid to wake on pmu asserting energy4TX
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__SHIFT                           12
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__WIDTH                            1
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__MASK                   0x00001000U
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENERGY4TX__RESET_VALUE            0x00000000U
/** @} */

/* macros for field watch_endoflife */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_endoflife_field watch_endoflife_field
 * @brief macros for field watch_endoflife
 * @details valid to wake on pmu asserting endoflife
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__SHIFT                           13
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__WIDTH                            1
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__MASK                   0x00002000U
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_HIB_WAKE_MASK__WATCH_ENDOFLIFE__RESET_VALUE            0x00000000U
/** @} */

/* macros for field watch_brownout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_brownout_field watch_brownout_field
 * @brief macros for field watch_brownout
 * @details valid to wake on pmu asserting brownout
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__SHIFT                            14
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__WIDTH                             1
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__MASK                    0x00004000U
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_HIB_WAKE_MASK__WATCH_BROWNOUT__RESET_VALUE             0x00000000U
/** @} */

/* macros for field watch_wurx */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx_field watch_wurx_field
 * @brief macros for field watch_wurx
 * @details valid to wake on multiple wurx detects in certain amount of time
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__SHIFT                                15
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__WIDTH                                 1
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__MASK                        0x00008000U
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_HIB_WAKE_MASK__WATCH_WURX__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field watch_ble_osc_on */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_ble_osc_on_field watch_ble_osc_on_field
 * @brief macros for field watch_ble_osc_on
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__SHIFT                          16
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__WIDTH                           1
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__MASK                  0x00010000U
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_HIB_WAKE_MASK__WATCH_BLE_OSC_ON__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_frc_match0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_frc_match0_field watch_frc_match0_field
 * @brief macros for field watch_frc_match0
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__SHIFT                          17
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__WIDTH                           1
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__MASK                  0x00020000U
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH0__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_frc_match1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_frc_match1_field watch_frc_match1_field
 * @brief macros for field watch_frc_match1
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__SHIFT                          18
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__WIDTH                           1
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__MASK                  0x00040000U
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_HIB_WAKE_MASK__WATCH_FRC_MATCH1__RESET_VALUE           0x00000000U
/** @} */

/* macros for field watch_pmu_wdog_warn */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_wdog_warn_field watch_pmu_wdog_warn_field
 * @brief macros for field watch_pmu_wdog_warn
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__SHIFT                       19
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__WIDTH                        1
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__MASK               0x00080000U
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PSEQ_HIB_WAKE_MASK__WATCH_PMU_WDOG_WARN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field qualify_on_energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_qualify_on_energy4TX_field qualify_on_energy4TX_field
 * @brief macros for field qualify_on_energy4TX
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__SHIFT                      30
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__WIDTH                       1
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__MASK              0x40000000U
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4TX__RESET_VALUE       0x00000000U
/** @} */

/* macros for field qualify_on_energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_qualify_on_energy4CPU_field qualify_on_energy4CPU_field
 * @brief macros for field qualify_on_energy4CPU
 * @{
 */
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__SHIFT                     31
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__WIDTH                      1
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__MASK             0x80000000U
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PSEQ_HIB_WAKE_MASK__QUALIFY_ON_ENERGY4CPU__RESET_VALUE      0x00000000U
/** @} */
#define PSEQ_HIB_WAKE_MASK__TYPE                                       uint32_t
#define PSEQ_HIB_WAKE_MASK__READ                                    0xc00fffffU
#define PSEQ_HIB_WAKE_MASK__WRITE                                   0xc00fffffU
#define PSEQ_HIB_WAKE_MASK__PRESERVED                               0x00000000U
#define PSEQ_HIB_WAKE_MASK__RESET_VALUE                             0x00000000U

#endif /* __PSEQ_HIB_WAKE_MASK_MACRO__ */

/** @} end of hib_wake_mask */

/* macros for BlueprintGlobalNameSpace::PSEQ_ble_ret_to_ble_act_wake_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ble_ret_to_ble_act_wake_mask ble_ret_to_ble_act_wake_mask
 * @brief signals to select which events can generate a wake event while in BLE Retain and go to BLE Act definitions.
 * @{
 */
#ifndef __PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK_MACRO__
#define __PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK_MACRO__

/* macros for field watch_gpio */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_gpio_field watch_gpio_field
 * @brief macros for field watch_gpio
 * @details valid to wake on gpio activity
 * @{
 */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__SHIFT                  0
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__WIDTH                  1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__MASK         0x00000001U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_GPIO__RESET_VALUE  0x00000000U
/** @} */

/* macros for field watch_cntdown */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_cntdown_field watch_cntdown_field
 * @brief macros for field watch_cntdown
 * @details valid to wake on count down timer expiring
 * @{
 */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__SHIFT               1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__WIDTH               1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__MASK      0x00000002U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_CNTDOWN__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field watch_wurx0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx0_field watch_wurx0_field
 * @brief macros for field watch_wurx0
 * @details valid to wake on wurx0 detect
 * @{
 */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__SHIFT                 2
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__WIDTH                 1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__MASK        0x00000004U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX0__RESET_VALUE 0x00000000U
/** @} */

/* macros for field watch_wurx1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx1_field watch_wurx1_field
 * @brief macros for field watch_wurx1
 * @details valid to wake on wurx1 detect
 * @{
 */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__SHIFT                 3
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__WIDTH                 1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__MASK        0x00000008U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_WURX1__RESET_VALUE 0x00000000U
/** @} */

/* macros for field watch_qdec */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_qdec_field watch_qdec_field
 * @brief macros for field watch_qdec
 * @details valid to wake on qdec activity
 * @{
 */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__SHIFT                  4
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__WIDTH                  1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__MASK         0x00000010U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_QDEC__RESET_VALUE  0x00000000U
/** @} */

/* macros for field watch_ksm */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_ksm_field watch_ksm_field
 * @brief macros for field watch_ksm
 * @details valid to wake on keyboard activity
 * @{
 */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__SHIFT                   5
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__WIDTH                   1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__MASK          0x00000020U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_KSM__RESET_VALUE   0x00000000U
/** @} */

/* macros for field watch_shub */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_shub_field watch_shub_field
 * @brief macros for field watch_shub
 * @details valid to wake on sensor hub trigger
 * @{
 */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__SHIFT                  6
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__WIDTH                  1
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__MASK         0x00000040U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WATCH_SHUB__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__TYPE                        uint32_t
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__READ                     0x0000007fU
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__WRITE                    0x0000007fU
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__PRESERVED                0x00000000U
#define PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK__RESET_VALUE              0x00000000U

#endif /* __PSEQ_BLE_RET_TO_BLE_ACT_WAKE_MASK_MACRO__ */

/** @} end of ble_ret_to_ble_act_wake_mask */

/* macros for BlueprintGlobalNameSpace::PSEQ_ble_ret_to_cpu_act_wake_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ble_ret_to_cpu_act_wake_mask ble_ret_to_cpu_act_wake_mask
 * @brief signals to select which events can generate a wake event while in BLE Retain and go to CPU Act definitions.
 * @{
 */
#ifndef __PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK_MACRO__
#define __PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK_MACRO__

/* macros for field watch_gpio */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_gpio_field watch_gpio_field
 * @brief macros for field watch_gpio
 * @details valid to wake on gpio activity
 * @{
 */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__SHIFT                  0
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__WIDTH                  1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__MASK         0x00000001U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_GPIO__RESET_VALUE  0x00000000U
/** @} */

/* macros for field watch_cntdown */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_cntdown_field watch_cntdown_field
 * @brief macros for field watch_cntdown
 * @details valid to wake on count down timer expiring
 * @{
 */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__SHIFT               1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__WIDTH               1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__MASK      0x00000002U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_CNTDOWN__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field watch_wurx0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx0_field watch_wurx0_field
 * @brief macros for field watch_wurx0
 * @details valid to wake on wurx0 detect
 * @{
 */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__SHIFT                 2
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__WIDTH                 1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__MASK        0x00000004U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX0__RESET_VALUE 0x00000000U
/** @} */

/* macros for field watch_wurx1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx1_field watch_wurx1_field
 * @brief macros for field watch_wurx1
 * @details valid to wake on wurx1 detect
 * @{
 */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__SHIFT                 3
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__WIDTH                 1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__MASK        0x00000008U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_WURX1__RESET_VALUE 0x00000000U
/** @} */

/* macros for field watch_qdec */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_qdec_field watch_qdec_field
 * @brief macros for field watch_qdec
 * @details valid to wake on qdec activity
 * @{
 */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__SHIFT                  4
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__WIDTH                  1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__MASK         0x00000010U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_QDEC__RESET_VALUE  0x00000000U
/** @} */

/* macros for field watch_ksm */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_ksm_field watch_ksm_field
 * @brief macros for field watch_ksm
 * @details valid to wake on keyboard activity
 * @{
 */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__SHIFT                   5
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__WIDTH                   1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__MASK          0x00000020U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_KSM__RESET_VALUE   0x00000000U
/** @} */

/* macros for field watch_shub */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_shub_field watch_shub_field
 * @brief macros for field watch_shub
 * @details valid to wake on sensor hub trigger
 * @{
 */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__SHIFT                  6
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__WIDTH                  1
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__MASK         0x00000040U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WATCH_SHUB__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__TYPE                        uint32_t
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__READ                     0x0000007fU
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__WRITE                    0x0000007fU
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__PRESERVED                0x00000000U
#define PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK__RESET_VALUE              0x00000000U

#endif /* __PSEQ_BLE_RET_TO_CPU_ACT_WAKE_MASK_MACRO__ */

/** @} end of ble_ret_to_cpu_act_wake_mask */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_mask gpio_wake_mask
 * @brief mask function to specify which gpio's can generate a gpio event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_MASK_MACRO__
#define __PSEQ_GPIO_WAKE_MASK_MACRO__

/* macros for field lower */
/**
 * @defgroup at_apb_pseq_perth_regs_core_lower_field lower_field
 * @brief macros for field lower
 * @details lower 16 gpio's (bank gpio0)
 * @{
 */
#define PSEQ_GPIO_WAKE_MASK__LOWER__SHIFT                                     0
#define PSEQ_GPIO_WAKE_MASK__LOWER__WIDTH                                    16
#define PSEQ_GPIO_WAKE_MASK__LOWER__MASK                            0x0000ffffU
#define PSEQ_GPIO_WAKE_MASK__LOWER__READ(src)   ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_MASK__LOWER__WRITE(src)  ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_MASK__LOWER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_MASK__LOWER__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_MASK__LOWER__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field upper */
/**
 * @defgroup at_apb_pseq_perth_regs_core_upper_field upper_field
 * @brief macros for field upper
 * @details upper 16 gpio's (bank gpio1)
 * @{
 */
#define PSEQ_GPIO_WAKE_MASK__UPPER__SHIFT                                    16
#define PSEQ_GPIO_WAKE_MASK__UPPER__WIDTH                                    16
#define PSEQ_GPIO_WAKE_MASK__UPPER__MASK                            0xffff0000U
#define PSEQ_GPIO_WAKE_MASK__UPPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_GPIO_WAKE_MASK__UPPER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_MASK__UPPER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_MASK__UPPER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_GPIO_WAKE_MASK__UPPER__RESET_VALUE                     0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_MASK__TYPE                                      uint32_t
#define PSEQ_GPIO_WAKE_MASK__READ                                   0xffffffffU
#define PSEQ_GPIO_WAKE_MASK__WRITE                                  0xffffffffU
#define PSEQ_GPIO_WAKE_MASK__PRESERVED                              0x00000000U
#define PSEQ_GPIO_WAKE_MASK__RESET_VALUE                            0x00000000U

#endif /* __PSEQ_GPIO_WAKE_MASK_MACRO__ */

/** @} end of gpio_wake_mask */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_mask1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_mask1 gpio_wake_mask1
 * @brief mask function to specify which gpio's can generate a gpio event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_MASK1_MACRO__
#define __PSEQ_GPIO_WAKE_MASK1_MACRO__

/* macros for field gpio2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio2_field gpio2_field
 * @brief macros for field gpio2
 * @details bank gpio2 16 gpio's
 * @{
 */
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__SHIFT                                    0
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__WIDTH                                   16
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__MASK                           0x0000ffffU
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__READ(src)  ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__WRITE(src) ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_MASK1__GPIO2__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field gpio3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio3_field gpio3_field
 * @brief macros for field gpio3
 * @details bank gpio3 6 gpio's
 * @{
 */
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__SHIFT                                   16
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__WIDTH                                    6
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__MASK                           0x003f0000U
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define PSEQ_GPIO_WAKE_MASK1__GPIO3__RESET_VALUE                    0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_MASK1__TYPE                                     uint32_t
#define PSEQ_GPIO_WAKE_MASK1__READ                                  0x003fffffU
#define PSEQ_GPIO_WAKE_MASK1__WRITE                                 0x003fffffU
#define PSEQ_GPIO_WAKE_MASK1__PRESERVED                             0x00000000U
#define PSEQ_GPIO_WAKE_MASK1__RESET_VALUE                           0x00000000U

#endif /* __PSEQ_GPIO_WAKE_MASK1_MACRO__ */

/** @} end of gpio_wake_mask1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_type */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_type gpio_wake_type
 * @brief specifies how a gpio generates an event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_TYPE_MACRO__
#define __PSEQ_GPIO_WAKE_TYPE_MACRO__

/* macros for field lower */
/**
 * @defgroup at_apb_pseq_perth_regs_core_lower_field lower_field
 * @brief macros for field lower
 * @details (per bit) 1 = edge sensitive , 0 = level
 * @{
 */
#define PSEQ_GPIO_WAKE_TYPE__LOWER__SHIFT                                     0
#define PSEQ_GPIO_WAKE_TYPE__LOWER__WIDTH                                    16
#define PSEQ_GPIO_WAKE_TYPE__LOWER__MASK                            0x0000ffffU
#define PSEQ_GPIO_WAKE_TYPE__LOWER__READ(src)   ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_TYPE__LOWER__WRITE(src)  ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_TYPE__LOWER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_TYPE__LOWER__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_TYPE__LOWER__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field upper */
/**
 * @defgroup at_apb_pseq_perth_regs_core_upper_field upper_field
 * @brief macros for field upper
 * @details (per bit) 1 = edge sensitive , 0 = level
 * @{
 */
#define PSEQ_GPIO_WAKE_TYPE__UPPER__SHIFT                                    16
#define PSEQ_GPIO_WAKE_TYPE__UPPER__WIDTH                                    16
#define PSEQ_GPIO_WAKE_TYPE__UPPER__MASK                            0xffff0000U
#define PSEQ_GPIO_WAKE_TYPE__UPPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_GPIO_WAKE_TYPE__UPPER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_TYPE__UPPER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_TYPE__UPPER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_GPIO_WAKE_TYPE__UPPER__RESET_VALUE                     0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_TYPE__TYPE                                      uint32_t
#define PSEQ_GPIO_WAKE_TYPE__READ                                   0xffffffffU
#define PSEQ_GPIO_WAKE_TYPE__WRITE                                  0xffffffffU
#define PSEQ_GPIO_WAKE_TYPE__PRESERVED                              0x00000000U
#define PSEQ_GPIO_WAKE_TYPE__RESET_VALUE                            0x00000000U

#endif /* __PSEQ_GPIO_WAKE_TYPE_MACRO__ */

/** @} end of gpio_wake_type */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_type1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_type1 gpio_wake_type1
 * @brief specifies how a gpio generates an event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_TYPE1_MACRO__
#define __PSEQ_GPIO_WAKE_TYPE1_MACRO__

/* macros for field gpio2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio2_field gpio2_field
 * @brief macros for field gpio2
 * @details (per bit) 1 = edge sensitive , 0 = level
 * @{
 */
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__SHIFT                                    0
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__WIDTH                                   16
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__MASK                           0x0000ffffU
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__READ(src)  ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__WRITE(src) ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_TYPE1__GPIO2__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field gpio3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio3_field gpio3_field
 * @brief macros for field gpio3
 * @details (per bit) 1 = edge sensitive , 0 = level
 * @{
 */
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__SHIFT                                   16
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__WIDTH                                    6
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__MASK                           0x003f0000U
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define PSEQ_GPIO_WAKE_TYPE1__GPIO3__RESET_VALUE                    0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_TYPE1__TYPE                                     uint32_t
#define PSEQ_GPIO_WAKE_TYPE1__READ                                  0x003fffffU
#define PSEQ_GPIO_WAKE_TYPE1__WRITE                                 0x003fffffU
#define PSEQ_GPIO_WAKE_TYPE1__PRESERVED                             0x00000000U
#define PSEQ_GPIO_WAKE_TYPE1__RESET_VALUE                           0x00000000U

#endif /* __PSEQ_GPIO_WAKE_TYPE1_MACRO__ */

/** @} end of gpio_wake_type1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_pol */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_pol gpio_wake_pol
 * @brief specifies how a gpio generates an event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_POL_MACRO__
#define __PSEQ_GPIO_WAKE_POL_MACRO__

/* macros for field lower */
/**
 * @defgroup at_apb_pseq_perth_regs_core_lower_field lower_field
 * @brief macros for field lower
 * @details (per bit) 1 = level high/rising edge , 0 = level low/falling edge
 * @{
 */
#define PSEQ_GPIO_WAKE_POL__LOWER__SHIFT                                      0
#define PSEQ_GPIO_WAKE_POL__LOWER__WIDTH                                     16
#define PSEQ_GPIO_WAKE_POL__LOWER__MASK                             0x0000ffffU
#define PSEQ_GPIO_WAKE_POL__LOWER__READ(src)    ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_POL__LOWER__WRITE(src)   ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_POL__LOWER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_POL__LOWER__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_POL__LOWER__RESET_VALUE                      0x0000ffffU
/** @} */

/* macros for field upper */
/**
 * @defgroup at_apb_pseq_perth_regs_core_upper_field upper_field
 * @brief macros for field upper
 * @details (per bit) 1 = level high/rising edge , 0 = level low/falling edge
 * @{
 */
#define PSEQ_GPIO_WAKE_POL__UPPER__SHIFT                                     16
#define PSEQ_GPIO_WAKE_POL__UPPER__WIDTH                                     16
#define PSEQ_GPIO_WAKE_POL__UPPER__MASK                             0xffff0000U
#define PSEQ_GPIO_WAKE_POL__UPPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_GPIO_WAKE_POL__UPPER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_POL__UPPER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_POL__UPPER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_GPIO_WAKE_POL__UPPER__RESET_VALUE                      0x0000ffffU
/** @} */
#define PSEQ_GPIO_WAKE_POL__TYPE                                       uint32_t
#define PSEQ_GPIO_WAKE_POL__READ                                    0xffffffffU
#define PSEQ_GPIO_WAKE_POL__WRITE                                   0xffffffffU
#define PSEQ_GPIO_WAKE_POL__PRESERVED                               0x00000000U
#define PSEQ_GPIO_WAKE_POL__RESET_VALUE                             0xffffffffU

#endif /* __PSEQ_GPIO_WAKE_POL_MACRO__ */

/** @} end of gpio_wake_pol */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_pol1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_pol1 gpio_wake_pol1
 * @brief specifies how a gpio generates an event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_POL1_MACRO__
#define __PSEQ_GPIO_WAKE_POL1_MACRO__

/* macros for field gpio2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio2_field gpio2_field
 * @brief macros for field gpio2
 * @details (per bit) 1 = level high/rising edge , 0 = level low/falling edge
 * @{
 */
#define PSEQ_GPIO_WAKE_POL1__GPIO2__SHIFT                                     0
#define PSEQ_GPIO_WAKE_POL1__GPIO2__WIDTH                                    16
#define PSEQ_GPIO_WAKE_POL1__GPIO2__MASK                            0x0000ffffU
#define PSEQ_GPIO_WAKE_POL1__GPIO2__READ(src)   ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_POL1__GPIO2__WRITE(src)  ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_POL1__GPIO2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_POL1__GPIO2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_POL1__GPIO2__RESET_VALUE                     0x0000ffffU
/** @} */

/* macros for field gpio3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio3_field gpio3_field
 * @brief macros for field gpio3
 * @details (per bit) 1 = level high/rising edge , 0 = level low/falling edge
 * @{
 */
#define PSEQ_GPIO_WAKE_POL1__GPIO3__SHIFT                                    16
#define PSEQ_GPIO_WAKE_POL1__GPIO3__WIDTH                                     6
#define PSEQ_GPIO_WAKE_POL1__GPIO3__MASK                            0x003f0000U
#define PSEQ_GPIO_WAKE_POL1__GPIO3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define PSEQ_GPIO_WAKE_POL1__GPIO3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_POL1__GPIO3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_POL1__GPIO3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define PSEQ_GPIO_WAKE_POL1__GPIO3__RESET_VALUE                     0x0000003fU
/** @} */
#define PSEQ_GPIO_WAKE_POL1__TYPE                                      uint32_t
#define PSEQ_GPIO_WAKE_POL1__READ                                   0x003fffffU
#define PSEQ_GPIO_WAKE_POL1__WRITE                                  0x003fffffU
#define PSEQ_GPIO_WAKE_POL1__PRESERVED                              0x00000000U
#define PSEQ_GPIO_WAKE_POL1__RESET_VALUE                            0x003fffffU

#endif /* __PSEQ_GPIO_WAKE_POL1_MACRO__ */

/** @} end of gpio_wake_pol1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_both_edges */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_both_edges gpio_wake_both_edges
 * @brief specifies how a gpio generates an event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_BOTH_EDGES_MACRO__
#define __PSEQ_GPIO_WAKE_BOTH_EDGES_MACRO__

/* macros for field lower */
/**
 * @defgroup at_apb_pseq_perth_regs_core_lower_field lower_field
 * @brief macros for field lower
 * @details (per bit) 1 = either edge will wake; higher precedence than gpio_wake_type and gpio_wake_pol
 * @{
 */
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__SHIFT                               0
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__WIDTH                              16
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__MASK                      0x0000ffffU
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_BOTH_EDGES__LOWER__RESET_VALUE               0x00000000U
/** @} */

/* macros for field upper */
/**
 * @defgroup at_apb_pseq_perth_regs_core_upper_field upper_field
 * @brief macros for field upper
 * @details (per bit) 1 = either edge will wake; higher precedence than gpio_wake_type and gpio_wake_pol
 * @{
 */
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__SHIFT                              16
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__WIDTH                              16
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__MASK                      0xffff0000U
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_GPIO_WAKE_BOTH_EDGES__UPPER__RESET_VALUE               0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_BOTH_EDGES__TYPE                                uint32_t
#define PSEQ_GPIO_WAKE_BOTH_EDGES__READ                             0xffffffffU
#define PSEQ_GPIO_WAKE_BOTH_EDGES__WRITE                            0xffffffffU
#define PSEQ_GPIO_WAKE_BOTH_EDGES__PRESERVED                        0x00000000U
#define PSEQ_GPIO_WAKE_BOTH_EDGES__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_GPIO_WAKE_BOTH_EDGES_MACRO__ */

/** @} end of gpio_wake_both_edges */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_both_edges1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_both_edges1 gpio_wake_both_edges1
 * @brief specifies how a gpio generates an event definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_BOTH_EDGES1_MACRO__
#define __PSEQ_GPIO_WAKE_BOTH_EDGES1_MACRO__

/* macros for field gpio2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio2_field gpio2_field
 * @brief macros for field gpio2
 * @details (per bit) 1 = either edge will wake; higher precedence than gpio_wake_type and gpio_wake_pol
 * @{
 */
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__SHIFT                              0
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__WIDTH                             16
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__MASK                     0x0000ffffU
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO2__RESET_VALUE              0x00000000U
/** @} */

/* macros for field gpio3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio3_field gpio3_field
 * @brief macros for field gpio3
 * @details (per bit) 1 = either edge will wake; higher precedence than gpio_wake_type and gpio_wake_pol
 * @{
 */
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__SHIFT                             16
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__WIDTH                              6
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__MASK                     0x003f0000U
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__GPIO3__RESET_VALUE              0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__TYPE                               uint32_t
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__READ                            0x003fffffU
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__WRITE                           0x003fffffU
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__PRESERVED                       0x00000000U
#define PSEQ_GPIO_WAKE_BOTH_EDGES1__RESET_VALUE                     0x00000000U

#endif /* __PSEQ_GPIO_WAKE_BOTH_EDGES1_MACRO__ */

/** @} end of gpio_wake_both_edges1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_status */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_status gpio_wake_status
 * @brief specifies which gpio caused the wake definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_STATUS_MACRO__
#define __PSEQ_GPIO_WAKE_STATUS_MACRO__

/* macros for field lower */
/**
 * @defgroup at_apb_pseq_perth_regs_core_lower_field lower_field
 * @brief macros for field lower
 * @{
 */
#define PSEQ_GPIO_WAKE_STATUS__LOWER__SHIFT                                   0
#define PSEQ_GPIO_WAKE_STATUS__LOWER__WIDTH                                  16
#define PSEQ_GPIO_WAKE_STATUS__LOWER__MASK                          0x0000ffffU
#define PSEQ_GPIO_WAKE_STATUS__LOWER__READ(src) ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_STATUS__LOWER__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field upper */
/**
 * @defgroup at_apb_pseq_perth_regs_core_upper_field upper_field
 * @brief macros for field upper
 * @{
 */
#define PSEQ_GPIO_WAKE_STATUS__UPPER__SHIFT                                  16
#define PSEQ_GPIO_WAKE_STATUS__UPPER__WIDTH                                  16
#define PSEQ_GPIO_WAKE_STATUS__UPPER__MASK                          0xffff0000U
#define PSEQ_GPIO_WAKE_STATUS__UPPER__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_GPIO_WAKE_STATUS__UPPER__RESET_VALUE                   0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_STATUS__TYPE                                    uint32_t
#define PSEQ_GPIO_WAKE_STATUS__READ                                 0xffffffffU
#define PSEQ_GPIO_WAKE_STATUS__PRESERVED                            0x00000000U
#define PSEQ_GPIO_WAKE_STATUS__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_GPIO_WAKE_STATUS_MACRO__ */

/** @} end of gpio_wake_status */

/* macros for BlueprintGlobalNameSpace::PSEQ_gpio_wake_status1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_wake_status1 gpio_wake_status1
 * @brief specifies which gpio caused the wake definitions.
 * @{
 */
#ifndef __PSEQ_GPIO_WAKE_STATUS1_MACRO__
#define __PSEQ_GPIO_WAKE_STATUS1_MACRO__

/* macros for field gpio2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio2_field gpio2_field
 * @brief macros for field gpio2
 * @{
 */
#define PSEQ_GPIO_WAKE_STATUS1__GPIO2__SHIFT                                  0
#define PSEQ_GPIO_WAKE_STATUS1__GPIO2__WIDTH                                 16
#define PSEQ_GPIO_WAKE_STATUS1__GPIO2__MASK                         0x0000ffffU
#define PSEQ_GPIO_WAKE_STATUS1__GPIO2__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_GPIO_WAKE_STATUS1__GPIO2__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field gpio3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio3_field gpio3_field
 * @brief macros for field gpio3
 * @{
 */
#define PSEQ_GPIO_WAKE_STATUS1__GPIO3__SHIFT                                 16
#define PSEQ_GPIO_WAKE_STATUS1__GPIO3__WIDTH                                  6
#define PSEQ_GPIO_WAKE_STATUS1__GPIO3__MASK                         0x003f0000U
#define PSEQ_GPIO_WAKE_STATUS1__GPIO3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define PSEQ_GPIO_WAKE_STATUS1__GPIO3__RESET_VALUE                  0x00000000U
/** @} */
#define PSEQ_GPIO_WAKE_STATUS1__TYPE                                   uint32_t
#define PSEQ_GPIO_WAKE_STATUS1__READ                                0x003fffffU
#define PSEQ_GPIO_WAKE_STATUS1__PRESERVED                           0x00000000U
#define PSEQ_GPIO_WAKE_STATUS1__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_GPIO_WAKE_STATUS1_MACRO__ */

/** @} end of gpio_wake_status1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_wurx_config */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_config wurx_config
 * @brief wurx configuration definitions.
 * @{
 */
#ifndef __PSEQ_WURX_CONFIG_MACRO__
#define __PSEQ_WURX_CONFIG_MACRO__

/* macros for field wurx_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_en_field wurx_en_field
 * @brief macros for field wurx_en
 * @details if low, disables wurx datapath
 * @{
 */
#define PSEQ_WURX_CONFIG__WURX_EN__SHIFT                                      0
#define PSEQ_WURX_CONFIG__WURX_EN__WIDTH                                      1
#define PSEQ_WURX_CONFIG__WURX_EN__MASK                             0x00000001U
#define PSEQ_WURX_CONFIG__WURX_EN__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define PSEQ_WURX_CONFIG__WURX_EN__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define PSEQ_WURX_CONFIG__WURX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_WURX_CONFIG__WURX_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_WURX_CONFIG__WURX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_WURX_CONFIG__WURX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_WURX_CONFIG__WURX_EN__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field wurx_rstb */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_rstb_field wurx_rstb_field
 * @brief macros for field wurx_rstb
 * @details if low, holds wurx in reset
 * @{
 */
#define PSEQ_WURX_CONFIG__WURX_RSTB__SHIFT                                    1
#define PSEQ_WURX_CONFIG__WURX_RSTB__WIDTH                                    1
#define PSEQ_WURX_CONFIG__WURX_RSTB__MASK                           0x00000002U
#define PSEQ_WURX_CONFIG__WURX_RSTB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_WURX_CONFIG__WURX_RSTB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_WURX_CONFIG__WURX_RSTB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_WURX_CONFIG__WURX_RSTB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_WURX_CONFIG__WURX_RSTB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_WURX_CONFIG__WURX_RSTB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_WURX_CONFIG__WURX_RSTB__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field wurx_cutvdd_b */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_cutvdd_b_field wurx_cutvdd_b_field
 * @brief macros for field wurx_cutvdd_b
 * @details if low, removes power from wurx
 * @{
 */
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__SHIFT                                2
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__WIDTH                                1
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__MASK                       0x00000004U
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_WURX_CONFIG__WURX_CUTVDD_B__RESET_VALUE                0x00000000U
/** @} */
#define PSEQ_WURX_CONFIG__TYPE                                         uint32_t
#define PSEQ_WURX_CONFIG__READ                                      0x00000007U
#define PSEQ_WURX_CONFIG__WRITE                                     0x00000007U
#define PSEQ_WURX_CONFIG__PRESERVED                                 0x00000000U
#define PSEQ_WURX_CONFIG__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_WURX_CONFIG_MACRO__ */

/** @} end of wurx_config */

/* macros for BlueprintGlobalNameSpace::PSEQ_wurx_config1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_config1 wurx_config1
 * @brief wurx configuration definitions.
 * @{
 */
#ifndef __PSEQ_WURX_CONFIG1_MACRO__
#define __PSEQ_WURX_CONFIG1_MACRO__

/* macros for field wurx_src_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_src_sel_field wurx_src_sel_field
 * @brief macros for field wurx_src_sel
 * @details which multiple wurx detect source to watch  0=wurx0  1=wurx1  2,3=wurx0 or wurx1
 * @{
 */
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__SHIFT                                0
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__WIDTH                                2
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__MASK                       0x00000003U
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_WURX_CONFIG1__WURX_SRC_SEL__RESET_VALUE                0x00000002U
/** @} */

/* macros for field num_wurx_event */
/**
 * @defgroup at_apb_pseq_perth_regs_core_num_wurx_event_field num_wurx_event_field
 * @brief macros for field num_wurx_event
 * @details Number of multiple wurx detect events to watch
 * @{
 */
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__SHIFT                              2
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__WIDTH                              4
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__MASK                     0x0000003cU
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000003cU) >> 2)
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000003cU)
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003cU) | (((uint32_t)(src) <<\
                    2) & 0x0000003cU)
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000003cU)))
#define PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__RESET_VALUE              0x00000008U
/** @} */
#define PSEQ_WURX_CONFIG1__TYPE                                        uint32_t
#define PSEQ_WURX_CONFIG1__READ                                     0x0000003fU
#define PSEQ_WURX_CONFIG1__WRITE                                    0x0000003fU
#define PSEQ_WURX_CONFIG1__PRESERVED                                0x00000000U
#define PSEQ_WURX_CONFIG1__RESET_VALUE                              0x00000022U

#endif /* __PSEQ_WURX_CONFIG1_MACRO__ */

/** @} end of wurx_config1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_wurx_config2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_config2 wurx_config2
 * @brief wurx configuration definitions.
 * @{
 */
#ifndef __PSEQ_WURX_CONFIG2_MACRO__
#define __PSEQ_WURX_CONFIG2_MACRO__

/* macros for field num_wurx_time0_cyc */
/**
 * @defgroup at_apb_pseq_perth_regs_core_num_wurx_time0_cyc_field num_wurx_time0_cyc_field
 * @brief macros for field num_wurx_time0_cyc
 * @details Full time window during multiple wurx detect events watching in 32KHz cycles, default 1sec window
 * @{
 */
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__SHIFT                          0
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__WIDTH                         17
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__MASK                 0x0001ffffU
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0001ffffU)
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0001ffffU)
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001ffffU) | ((uint32_t)(src) &\
                    0x0001ffffU)
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0001ffffU)))
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__RESET_VALUE          0x00008000U
/** @} */

/* macros for field num_wurx_time1_cyc */
/**
 * @defgroup at_apb_pseq_perth_regs_core_num_wurx_time1_cyc_field num_wurx_time1_cyc_field
 * @brief macros for field num_wurx_time1_cyc
 * @details Max time window between two consecutive wurx detect events in 32KHz cycles, default 500msec window
 * @{
 */
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__SHIFT                         17
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__WIDTH                         15
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__MASK                 0xfffe0000U
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffe0000U) >> 17)
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0xfffe0000U)
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffe0000U) | (((uint32_t)(src) <<\
                    17) & 0xfffe0000U)
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0xfffe0000U)))
#define PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__RESET_VALUE          0x00004000U
/** @} */
#define PSEQ_WURX_CONFIG2__TYPE                                        uint32_t
#define PSEQ_WURX_CONFIG2__READ                                     0xffffffffU
#define PSEQ_WURX_CONFIG2__WRITE                                    0xffffffffU
#define PSEQ_WURX_CONFIG2__PRESERVED                                0x00000000U
#define PSEQ_WURX_CONFIG2__RESET_VALUE                              0x80008000U

#endif /* __PSEQ_WURX_CONFIG2_MACRO__ */

/** @} end of wurx_config2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_gadc_config */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gadc_config gadc_config
 * @brief gadc configuration definitions.
 * @{
 */
#ifndef __PSEQ_GADC_CONFIG_MACRO__
#define __PSEQ_GADC_CONFIG_MACRO__

/* macros for field gadc_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gadc_en_field gadc_en_field
 * @brief macros for field gadc_en
 * @details if low, disables gadc datapath
 * @{
 */
#define PSEQ_GADC_CONFIG__GADC_EN__SHIFT                                      0
#define PSEQ_GADC_CONFIG__GADC_EN__WIDTH                                      1
#define PSEQ_GADC_CONFIG__GADC_EN__MASK                             0x00000001U
#define PSEQ_GADC_CONFIG__GADC_EN__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define PSEQ_GADC_CONFIG__GADC_EN__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define PSEQ_GADC_CONFIG__GADC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_GADC_CONFIG__GADC_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_GADC_CONFIG__GADC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_GADC_CONFIG__GADC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_GADC_CONFIG__GADC_EN__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field gadc_rstb */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gadc_rstb_field gadc_rstb_field
 * @brief macros for field gadc_rstb
 * @details if low, holds gadc in reset
 * @{
 */
#define PSEQ_GADC_CONFIG__GADC_RSTB__SHIFT                                    1
#define PSEQ_GADC_CONFIG__GADC_RSTB__WIDTH                                    1
#define PSEQ_GADC_CONFIG__GADC_RSTB__MASK                           0x00000002U
#define PSEQ_GADC_CONFIG__GADC_RSTB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_GADC_CONFIG__GADC_RSTB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_GADC_CONFIG__GADC_RSTB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_GADC_CONFIG__GADC_RSTB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_GADC_CONFIG__GADC_RSTB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_GADC_CONFIG__GADC_RSTB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_GADC_CONFIG__GADC_RSTB__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field gadc_cutvdd_b */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gadc_cutvdd_b_field gadc_cutvdd_b_field
 * @brief macros for field gadc_cutvdd_b
 * @details if low, removes power from gadc
 * @{
 */
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__SHIFT                                2
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__WIDTH                                1
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__MASK                       0x00000004U
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_GADC_CONFIG__GADC_CUTVDD_B__RESET_VALUE                0x00000000U
/** @} */
#define PSEQ_GADC_CONFIG__TYPE                                         uint32_t
#define PSEQ_GADC_CONFIG__READ                                      0x00000007U
#define PSEQ_GADC_CONFIG__WRITE                                     0x00000007U
#define PSEQ_GADC_CONFIG__PRESERVED                                 0x00000000U
#define PSEQ_GADC_CONFIG__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_GADC_CONFIG_MACRO__ */

/** @} end of gadc_config */

/* macros for BlueprintGlobalNameSpace::PSEQ_overrides */
/**
 * @defgroup at_apb_pseq_perth_regs_core_overrides overrides
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_OVERRIDES_MACRO__
#define __PSEQ_OVERRIDES_MACRO__

/* macros for field force_precision_req */
/**
 * @defgroup at_apb_pseq_perth_regs_core_force_precision_req_field force_precision_req_field
 * @brief macros for field force_precision_req
 * @details force the type of precision when clk_mpc is requested
 * @{
 */
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__SHIFT                            0
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__WIDTH                            1
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__MASK                   0x00000001U
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_OVERRIDES__FORCE_PRECISION_REQ__RESET_VALUE            0x00000000U
/** @} */

/* macros for field force_precision_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_force_precision_val_field force_precision_val_field
 * @brief macros for field force_precision_val
 * @details when type of precision for clk_mpc is forced, what should it be?  1=high/xtal  0=low/osc
 * @{
 */
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__SHIFT                            1
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__WIDTH                            1
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__MASK                   0x00000002U
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_OVERRIDES__FORCE_PRECISION_VAL__RESET_VALUE            0x00000000U
/** @} */

/* macros for field force_osc_on_req */
/**
 * @defgroup at_apb_pseq_perth_regs_core_force_osc_on_req_field force_osc_on_req_field
 * @brief macros for field force_osc_on_req
 * @details force that clk_mpc oscillator request always be on
 * @{
 */
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__SHIFT                               2
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__WIDTH                               1
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__MASK                      0x00000004U
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_OVERRIDES__FORCE_OSC_ON_REQ__RESET_VALUE               0x00000000U
/** @} */

/* macros for field block_ble_osc_on_req */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_ble_osc_on_req_field block_ble_osc_on_req_field
 * @brief macros for field block_ble_osc_on_req
 * @details if set, ble core cannot request clk_mpc oscillator to be enabled, mostly for debug and testing
 * @{
 */
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__SHIFT                           3
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__WIDTH                           1
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__MASK                  0x00000008U
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_OVERRIDES__BLOCK_BLE_OSC_ON_REQ__RESET_VALUE           0x00000000U
/** @} */

/* macros for field block_ble_high_precision_req */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_ble_high_precision_req_field block_ble_high_precision_req_field
 * @brief macros for field block_ble_high_precision_req
 * @details if set, ble core cannot request high precision clock, mostly for debug and testing
 * @{
 */
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__SHIFT                   4
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__WIDTH                   1
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__MASK          0x00000010U
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_OVERRIDES__BLOCK_BLE_HIGH_PRECISION_REQ__RESET_VALUE   0x00000000U
/** @} */
#define PSEQ_OVERRIDES__TYPE                                           uint32_t
#define PSEQ_OVERRIDES__READ                                        0x0000001fU
#define PSEQ_OVERRIDES__WRITE                                       0x0000001fU
#define PSEQ_OVERRIDES__PRESERVED                                   0x00000000U
#define PSEQ_OVERRIDES__RESET_VALUE                                 0x00000000U

#endif /* __PSEQ_OVERRIDES_MACRO__ */

/** @} end of overrides */

/* macros for BlueprintGlobalNameSpace::PSEQ_overrides2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_overrides2 overrides2
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_OVERRIDES2_MACRO__
#define __PSEQ_OVERRIDES2_MACRO__

/* macros for field block_sysrom_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_sysrom_vddcut_field block_sysrom_vddcut_field
 * @brief macros for field block_sysrom_vddcut
 * @details if set, this core's FSM cannot power down the ROM macros
 * @{
 */
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__SHIFT                           0
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__WIDTH                           1
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__MASK                  0x00000001U
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_OVERRIDES2__BLOCK_SYSROM_VDDCUT__RESET_VALUE           0x00000000U
/** @} */

/* macros for field block_rram_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_rram_vddcut_field block_rram_vddcut_field
 * @brief macros for field block_rram_vddcut
 * @details if set, this core's FSM cannot power down the rram macros
 * @{
 */
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__SHIFT                             1
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__WIDTH                             1
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__MASK                    0x00000002U
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDCUT__RESET_VALUE             0x00000000U
/** @} */

/* macros for field block_efuse_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_efuse_vddcut_field block_efuse_vddcut_field
 * @brief macros for field block_efuse_vddcut
 * @details if set, this core's FSM cannot power down the e-fuse macros
 * @{
 */
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__SHIFT                            2
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__WIDTH                            1
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__MASK                   0x00000004U
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_OVERRIDES2__BLOCK_EFUSE_VDDCUT__RESET_VALUE            0x00000000U
/** @} */

/* macros for field block_rram_vddiocut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_rram_vddiocut_field block_rram_vddiocut_field
 * @brief macros for field block_rram_vddiocut
 * @details if set, this core's FSM cannot power down the rram macro's high supply
 * @{
 */
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__SHIFT                           3
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__WIDTH                           1
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__MASK                  0x00000008U
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_OVERRIDES2__BLOCK_RRAM_VDDIOCUT__RESET_VALUE           0x00000000U
/** @} */
#define PSEQ_OVERRIDES2__TYPE                                          uint32_t
#define PSEQ_OVERRIDES2__READ                                       0x0000000fU
#define PSEQ_OVERRIDES2__WRITE                                      0x0000000fU
#define PSEQ_OVERRIDES2__PRESERVED                                  0x00000000U
#define PSEQ_OVERRIDES2__RESET_VALUE                                0x00000000U

#endif /* __PSEQ_OVERRIDES2_MACRO__ */

/** @} end of overrides2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_overrides3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_overrides3 overrides3
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_OVERRIDES3_MACRO__
#define __PSEQ_OVERRIDES3_MACRO__

/* macros for field override_sysrom_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_clken_val_field override_sysrom_clken_val_field
 * @brief macros for field override_sysrom_clken_val
 * @details if override is set, what value should be driven onto rom clock enable pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__SHIFT                     0
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__WIDTH                     1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__MASK            0x00000001U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field override_sysrom_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_clken_field override_sysrom_clken_field
 * @brief macros for field override_sysrom_clken
 * @details if set, software now has direct control of the rom clock enable pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__SHIFT                         1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__WIDTH                         1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__MASK                0x00000002U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_CLKEN__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_sysrom_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_iso_val_field override_sysrom_iso_val_field
 * @brief macros for field override_sysrom_iso_val
 * @details if override is set, what value should be driven onto rom ISO pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__SHIFT                       2
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__WIDTH                       1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__MASK              0x00000004U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field override_sysrom_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_iso_field override_sysrom_iso_field
 * @brief macros for field override_sysrom_iso
 * @details if set, software now has direct control of the rom ISO pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__SHIFT                           3
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__WIDTH                           1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__MASK                  0x00000008U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_ISO__RESET_VALUE           0x00000000U
/** @} */

/* macros for field override_sysrom_ls_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_ls_val_field override_sysrom_ls_val_field
 * @brief macros for field override_sysrom_ls_val
 * @details if override is set, what value should be driven onto rom LS pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__SHIFT                        4
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__WIDTH                        1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__MASK               0x00000010U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_sysrom_ls */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_ls_field override_sysrom_ls_field
 * @brief macros for field override_sysrom_ls
 * @details if set, software now has direct control of the rom LS pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__SHIFT                            5
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__WIDTH                            1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__MASK                   0x00000020U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_LS__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_sysrom_frst_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_frst_val_field override_sysrom_frst_val_field
 * @brief macros for field override_sysrom_frst_val
 * @details if override is set, what value should be driven onto the romc domain's forced reset signal?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__SHIFT                      6
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__WIDTH                      1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__MASK             0x00000040U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field override_sysrom_frst */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_frst_field override_sysrom_frst_field
 * @brief macros for field override_sysrom_frst
 * @details if set, software now has direct control of the romc domain forced reset signal
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__SHIFT                          7
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__WIDTH                          1
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__MASK                 0x00000080U
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_OVERRIDES3__OVERRIDE_SYSROM_FRST__RESET_VALUE          0x00000000U
/** @} */

/* macros for field override_rram_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_clken_val_field override_rram_clken_val_field
 * @brief macros for field override_rram_clken_val
 * @details if override is set, what value should be driven onto rram clock enable pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__SHIFT                       8
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__WIDTH                       1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__MASK              0x00000100U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field override_rram_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_clken_field override_rram_clken_field
 * @brief macros for field override_rram_clken
 * @details if set, software now has direct control of the rram clock enable pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__SHIFT                           9
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__WIDTH                           1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__MASK                  0x00000200U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_CLKEN__RESET_VALUE           0x00000000U
/** @} */

/* macros for field override_rram_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_iso_val_field override_rram_iso_val_field
 * @brief macros for field override_rram_iso_val
 * @details if override is set, what value should be driven onto rram ISO pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__SHIFT                        10
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__WIDTH                         1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__MASK                0x00000400U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_rram_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_iso_field override_rram_iso_field
 * @brief macros for field override_rram_iso
 * @details if set, software now has direct control of the rram ISO pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__SHIFT                            11
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__WIDTH                             1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__MASK                    0x00000800U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_ISO__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_rram_nap_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_nap_val_field override_rram_nap_val_field
 * @brief macros for field override_rram_nap_val
 * @details if override is set, what value should be driven onto rram NAP pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__SHIFT                        12
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__WIDTH                         1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__MASK                0x00001000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_rram_nap */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_nap_field override_rram_nap_field
 * @brief macros for field override_rram_nap
 * @details if set, software now has direct control of the rram NAP pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__SHIFT                            13
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__WIDTH                             1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__MASK                    0x00002000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_NAP__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_rram_poc_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_poc_val_field override_rram_poc_val_field
 * @brief macros for field override_rram_poc_val
 * @details if override is set, what value should be driven onto rram POC_H pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__SHIFT                        14
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__WIDTH                         1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__MASK                0x00004000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_rram_poc */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_poc_field override_rram_poc_field
 * @brief macros for field override_rram_poc
 * @details if set, software now has direct control of the rram POC_H pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__SHIFT                            15
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__WIDTH                             1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__MASK                    0x00008000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_POC__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_rram_rst_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_rst_val_field override_rram_rst_val_field
 * @brief macros for field override_rram_rst_val
 * @details if override is set, what value should be driven onto rram RST pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__SHIFT                        16
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__WIDTH                         1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__MASK                0x00010000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_rram_rst */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_rst_field override_rram_rst_field
 * @brief macros for field override_rram_rst
 * @details if set, software now has direct control of the rram RST pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__SHIFT                            17
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__WIDTH                             1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__MASK                    0x00020000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_RST__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_rram_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_vddcut_val_field override_rram_vddcut_val_field
 * @brief macros for field override_rram_vddcut_val
 * @details if override is set, should head switch on romc be open or close?  1=open  0=close
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__SHIFT                     18
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__WIDTH                      1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__MASK             0x00040000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field override_rram_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_vddcut_field override_rram_vddcut_field
 * @brief macros for field override_rram_vddcut
 * @details if set, head switch on romc (rom,rram) is now software controllable
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__SHIFT                         19
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__WIDTH                          1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__MASK                 0x00080000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDCUT__RESET_VALUE          0x00000000U
/** @} */

/* macros for field override_efuse_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_efuse_iso_val_field override_efuse_iso_val_field
 * @brief macros for field override_efuse_iso_val
 * @details if override is set, what value should be driven onto e-fuse ISO pin?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__SHIFT                       20
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__WIDTH                        1
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__MASK               0x00100000U
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_efuse_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_efuse_iso_field override_efuse_iso_field
 * @brief macros for field override_efuse_iso
 * @details if set, software now has direct control of the e-fuse ISO pin
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__SHIFT                           21
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__WIDTH                            1
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__MASK                   0x00200000U
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_ISO__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_efuse_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_efuse_vddcut_val_field override_efuse_vddcut_val_field
 * @brief macros for field override_efuse_vddcut_val
 * @details if override is set, should head switch on e-fuse be open or close?  1=open  0=close
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__SHIFT                    22
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__WIDTH                     1
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__MASK            0x00400000U
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field override_efuse_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_efuse_vddcut_field override_efuse_vddcut_field
 * @brief macros for field override_efuse_vddcut
 * @details if set, head switch on e-fuse is now software controllable
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__SHIFT                        23
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__WIDTH                         1
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__MASK                0x00800000U
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PSEQ_OVERRIDES3__OVERRIDE_EFUSE_VDDCUT__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_ram_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ram_iso_val_field override_ram_iso_val_field
 * @brief macros for field override_ram_iso_val
 * @details if override is set, what value should be driven onto pd_mem ISO pins?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__SHIFT                         24
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__WIDTH                          1
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__MASK                 0x01000000U
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field override_ram_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ram_iso_field override_ram_iso_field
 * @brief macros for field override_ram_iso
 * @details if set, software now has direct control of the pd_mem ISO pins
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__SHIFT                             25
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__WIDTH                              1
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__MASK                     0x02000000U
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PSEQ_OVERRIDES3__OVERRIDE_RAM_ISO__RESET_VALUE              0x00000000U
/** @} */

/* macros for field override_rram_vddiocut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_vddiocut_val_field override_rram_vddiocut_val_field
 * @brief macros for field override_rram_vddiocut_val
 * @details if override is set, should head switch on rram high supply be open or close?  1=open  0=close
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__SHIFT                   26
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__WIDTH                    1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__MASK           0x04000000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT_VAL__RESET_VALUE    0x00000000U
/** @} */

/* macros for field override_rram_vddiocut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rram_vddiocut_field override_rram_vddiocut_field
 * @brief macros for field override_rram_vddiocut
 * @details if set, head switch on rram high supply is now software controllable
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__SHIFT                       27
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__WIDTH                        1
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__MASK               0x08000000U
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PSEQ_OVERRIDES3__OVERRIDE_RRAM_VDDIOCUT__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_mbist_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_mbist_iso_val_field override_mbist_iso_val_field
 * @brief macros for field override_mbist_iso_val
 * @details if override is set, what value should be driven onto mbist ISO pins driving rams?
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__SHIFT                       28
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__WIDTH                        1
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__MASK               0x10000000U
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_mbist_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_mbist_iso_field override_mbist_iso_field
 * @brief macros for field override_mbist_iso
 * @details if set, software now has direct control of the mbist ISO pins driving rams
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__SHIFT                           29
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__WIDTH                            1
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__MASK                   0x20000000U
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_ISO__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_mbist_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_mbist_vddcut_val_field override_mbist_vddcut_val_field
 * @brief macros for field override_mbist_vddcut_val
 * @details if override is set, should head switch on mbist high supply be open or close?  1=open  0=close
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__SHIFT                    30
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__WIDTH                     1
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__MASK            0x40000000U
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field override_mbist_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_mbist_vddcut_field override_mbist_vddcut_field
 * @brief macros for field override_mbist_vddcut
 * @details if set, head switch on mbist high supply is now software controllable
 * @{
 */
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__SHIFT                        31
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__WIDTH                         1
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__MASK                0x80000000U
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PSEQ_OVERRIDES3__OVERRIDE_MBIST_VDDCUT__RESET_VALUE         0x00000000U
/** @} */
#define PSEQ_OVERRIDES3__TYPE                                          uint32_t
#define PSEQ_OVERRIDES3__READ                                       0xffffffffU
#define PSEQ_OVERRIDES3__WRITE                                      0xffffffffU
#define PSEQ_OVERRIDES3__PRESERVED                                  0x00000000U
#define PSEQ_OVERRIDES3__RESET_VALUE                                0x00000000U

#endif /* __PSEQ_OVERRIDES3_MACRO__ */

/** @} end of overrides3 */

/* macros for BlueprintGlobalNameSpace::PSEQ_overrides4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_overrides4 overrides4
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_OVERRIDES4_MACRO__
#define __PSEQ_OVERRIDES4_MACRO__

/* macros for field override_ble_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_clken_val_field override_ble_clken_val_field
 * @brief macros for field override_ble_clken_val
 * @details if override is set, what value should be driven onto the ble domain's clock enable signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__SHIFT                        0
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__WIDTH                        1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__MASK               0x00000001U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_ble_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_clken_field override_ble_clken_field
 * @brief macros for field override_ble_clken
 * @details if set, software now has direct control of the clock enable signal going to the ble domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__SHIFT                            1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__WIDTH                            1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__MASK                   0x00000002U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_CLKEN__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_ble_frst_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_frst_val_field override_ble_frst_val_field
 * @brief macros for field override_ble_frst_val
 * @details if override is set, what value should be driven onto the ble domain's forced reset signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__SHIFT                         2
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__MASK                0x00000004U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_ble_frst */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_frst_field override_ble_frst_field
 * @brief macros for field override_ble_frst
 * @details if set, software now has direct control of the forced reset signal going to the ble domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__SHIFT                             3
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__WIDTH                             1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__MASK                    0x00000008U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_FRST__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_ble_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_iso_val_field override_ble_iso_val_field
 * @brief macros for field override_ble_iso_val
 * @details if override is set, what value should be driven onto the ble domain's iso signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__SHIFT                          4
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__WIDTH                          1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__MASK                 0x00000010U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field override_ble_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_iso_field override_ble_iso_field
 * @brief macros for field override_ble_iso
 * @details if set, software now has direct control of the iso signal going to the ble domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__SHIFT                              5
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__WIDTH                              1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__MASK                     0x00000020U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_ISO__RESET_VALUE              0x00000000U
/** @} */

/* macros for field override_ble_kill_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_kill_val_field override_ble_kill_val_field
 * @brief macros for field override_ble_kill_val
 * @details if override is set, what value should be driven onto the ble domain's kill signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__SHIFT                         6
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__MASK                0x00000040U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_ble_kill */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_kill_field override_ble_kill_field
 * @brief macros for field override_ble_kill
 * @details if set, software now has direct control of the kill signal going to the ble domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__SHIFT                             7
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__WIDTH                             1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__MASK                    0x00000080U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_KILL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_ble_sleep_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_sleep_val_field override_ble_sleep_val_field
 * @brief macros for field override_ble_sleep_val
 * @details if override is set, what value should be driven onto the ble domain's sleep signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__SHIFT                        8
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__WIDTH                        1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__MASK               0x00000100U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_ble_sleep */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_sleep_field override_ble_sleep_field
 * @brief macros for field override_ble_sleep
 * @details if set, software now has direct control of the sleep signal going to the ble domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__SHIFT                            9
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__WIDTH                            1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__MASK                   0x00000200U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SLEEP__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_ble_nrestore_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_nrestore_val_field override_ble_nrestore_val_field
 * @brief macros for field override_ble_nrestore_val
 * @details if override is set, what value should be driven onto the ble domain's NRESTORE signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__SHIFT                    10
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__WIDTH                     1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__MASK            0x00000400U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field override_ble_nrestore */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_nrestore_field override_ble_nrestore_field
 * @brief macros for field override_ble_nrestore
 * @details if set, software now has direct control of the NRESTORE signal going to the ble domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__SHIFT                        11
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__MASK                0x00000800U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_NRESTORE__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_ble_save_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_save_val_field override_ble_save_val_field
 * @brief macros for field override_ble_save_val
 * @details if override is set, what value should be driven onto the ble domain's SAVE signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__SHIFT                        12
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__MASK                0x00001000U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_ble_save */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_save_field override_ble_save_field
 * @brief macros for field override_ble_save
 * @details if set, software now has direct control of the SAVE signal going to the ble domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__SHIFT                            13
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__WIDTH                             1
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__MASK                    0x00002000U
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_OVERRIDES4__OVERRIDE_BLE_SAVE__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_pnr_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_clken_val_field override_pnr_clken_val_field
 * @brief macros for field override_pnr_clken_val
 * @details if override is set, what value should be driven onto the cpu domain's clock enable signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__SHIFT                       14
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__WIDTH                        1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__MASK               0x00004000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_pnr_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_clken_field override_pnr_clken_field
 * @brief macros for field override_pnr_clken
 * @details if set, software now has direct control of the clock enable signal going to the cpu domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__SHIFT                           15
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__WIDTH                            1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__MASK                   0x00008000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_CLKEN__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_pnr_frst_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_frst_val_field override_pnr_frst_val_field
 * @brief macros for field override_pnr_frst_val
 * @details if override is set, what value should be driven onto the cpu domain's forced reset signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__SHIFT                        16
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__MASK                0x00010000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_pnr_frst */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_frst_field override_pnr_frst_field
 * @brief macros for field override_pnr_frst
 * @details if set, software now has direct control of the forced reset signal going to the cpu domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__SHIFT                            17
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__WIDTH                             1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__MASK                    0x00020000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_FRST__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_pnr_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_iso_val_field override_pnr_iso_val_field
 * @brief macros for field override_pnr_iso_val
 * @details if override is set, what value should be driven onto the cpu domain's iso signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__SHIFT                         18
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__WIDTH                          1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__MASK                 0x00040000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO_VAL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field override_pnr_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_iso_field override_pnr_iso_field
 * @brief macros for field override_pnr_iso
 * @details if set, software now has direct control of the iso signal going to the cpu domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__SHIFT                             19
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__WIDTH                              1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__MASK                     0x00080000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_ISO__RESET_VALUE              0x00000000U
/** @} */

/* macros for field override_pnr_kill_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_kill_val_field override_pnr_kill_val_field
 * @brief macros for field override_pnr_kill_val
 * @details if override is set, what value should be driven onto the cpu domain's kill signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__SHIFT                        20
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__MASK                0x00100000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_pnr_kill */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_kill_field override_pnr_kill_field
 * @brief macros for field override_pnr_kill
 * @details if set, software now has direct control of the kill signal going to the cpu domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__SHIFT                            21
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__WIDTH                             1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__MASK                    0x00200000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_KILL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_pnr_sleep_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_sleep_val_field override_pnr_sleep_val_field
 * @brief macros for field override_pnr_sleep_val
 * @details if override is set, what value should be driven onto the cpu domain's sleep signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__SHIFT                       22
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__WIDTH                        1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__MASK               0x00400000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_pnr_sleep */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_sleep_field override_pnr_sleep_field
 * @brief macros for field override_pnr_sleep
 * @details if set, software now has direct control of the sleep signal going to the cpu domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__SHIFT                           23
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__WIDTH                            1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__MASK                   0x00800000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SLEEP__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_pnr_nrestore_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_nrestore_val_field override_pnr_nrestore_val_field
 * @brief macros for field override_pnr_nrestore_val
 * @details if override is set, what value should be driven onto the cpu domain's NRESTORE signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__SHIFT                    24
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__WIDTH                     1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__MASK            0x01000000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field override_pnr_nrestore */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_nrestore_field override_pnr_nrestore_field
 * @brief macros for field override_pnr_nrestore
 * @details if set, software now has direct control of the NRESTORE signal going to the cpu domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__SHIFT                        25
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__MASK                0x02000000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_NRESTORE__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_pnr_save_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_save_val_field override_pnr_save_val_field
 * @brief macros for field override_pnr_save_val
 * @details if override is set, what value should be driven onto the cpu domain's SAVE signal?
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__SHIFT                        26
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__WIDTH                         1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__MASK                0x04000000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_pnr_save */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_save_field override_pnr_save_field
 * @brief macros for field override_pnr_save
 * @details if set, software now has direct control of the SAVE signal going to the cpu domain
 * @{
 */
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__SHIFT                            27
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__WIDTH                             1
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__MASK                    0x08000000U
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PSEQ_OVERRIDES4__OVERRIDE_PNR_SAVE__RESET_VALUE             0x00000000U
/** @} */
#define PSEQ_OVERRIDES4__TYPE                                          uint32_t
#define PSEQ_OVERRIDES4__READ                                       0x0fffffffU
#define PSEQ_OVERRIDES4__WRITE                                      0x0fffffffU
#define PSEQ_OVERRIDES4__PRESERVED                                  0x00000000U
#define PSEQ_OVERRIDES4__RESET_VALUE                                0x00000000U

#endif /* __PSEQ_OVERRIDES4_MACRO__ */

/** @} end of overrides4 */

/* macros for BlueprintGlobalNameSpace::PSEQ_overrides5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_overrides5 overrides5
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_OVERRIDES5_MACRO__
#define __PSEQ_OVERRIDES5_MACRO__

/* macros for field override_pnr_retsecon_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_retsecon_val_field override_pnr_retsecon_val_field
 * @brief macros for field override_pnr_retsecon_val
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__SHIFT                     8
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__WIDTH                     1
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__MASK            0x00000100U
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field override_pnr_retsecon */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_retsecon_field override_pnr_retsecon_field
 * @brief macros for field override_pnr_retsecon
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__SHIFT                         9
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__WIDTH                         1
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__MASK                0x00000200U
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETSECON__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_pnr_retprim_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_retprim_val_field override_pnr_retprim_val_field
 * @brief macros for field override_pnr_retprim_val
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__SHIFT                     10
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__WIDTH                      1
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__MASK             0x00000400U
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field override_pnr_retprim */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_retprim_field override_pnr_retprim_field
 * @brief macros for field override_pnr_retprim
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__SHIFT                         11
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__WIDTH                          1
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__MASK                 0x00000800U
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_RETPRIM__RESET_VALUE          0x00000000U
/** @} */

/* macros for field override_sysrom_frstdp_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_frstdp_val_field override_sysrom_frstdp_val_field
 * @brief macros for field override_sysrom_frstdp_val
 * @details If override is set, what value is the romc domain's datapath forced reset.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__SHIFT                   12
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__WIDTH                    1
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__MASK           0x00001000U
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP_VAL__RESET_VALUE    0x00000000U
/** @} */

/* macros for field override_sysrom_frstdp */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysrom_frstdp_field override_sysrom_frstdp_field
 * @brief macros for field override_sysrom_frstdp
 * @details If set, software now has direct control of romc domain's datapath forced reset.  Not all state is retained even in Retain All state.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__SHIFT                       13
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__WIDTH                        1
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__MASK               0x00002000U
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_OVERRIDES5__OVERRIDE_SYSROM_FRSTDP__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_pnr_frstdp_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_frstdp_val_field override_pnr_frstdp_val_field
 * @brief macros for field override_pnr_frstdp_val
 * @details If override is set, what value is the cpu domain's datapath forced reset.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__SHIFT                      14
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__WIDTH                       1
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__MASK              0x00004000U
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field override_pnr_frstdp */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_pnr_frstdp_field override_pnr_frstdp_field
 * @brief macros for field override_pnr_frstdp
 * @details If set, software now has direct control of cpu domain's datapath forced reset.  Not all state is retained even in Retain All state.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__SHIFT                          15
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__WIDTH                           1
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__MASK                  0x00008000U
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_OVERRIDES5__OVERRIDE_PNR_FRSTDP__RESET_VALUE           0x00000000U
/** @} */

/* macros for field override_ble_frstdp_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_frstdp_val_field override_ble_frstdp_val_field
 * @brief macros for field override_ble_frstdp_val
 * @details If override is set, what value is the ble domain's datapath forced reset.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__SHIFT                      16
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__WIDTH                       1
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__MASK              0x00010000U
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field override_ble_frstdp */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_ble_frstdp_field override_ble_frstdp_field
 * @brief macros for field override_ble_frstdp
 * @details If set, software now has direct control of ble domain's datapath forced reset.  Not all state is retained even in Retain All state.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__SHIFT                          17
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__WIDTH                           1
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__MASK                  0x00020000U
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_OVERRIDES5__OVERRIDE_BLE_FRSTDP__RESET_VALUE           0x00000000U
/** @} */

/* macros for field override_radio_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_radio_iso_val_field override_radio_iso_val_field
 * @brief macros for field override_radio_iso_val
 * @details If override is set, what value is the radio isolation signal?
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__SHIFT                       18
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__WIDTH                        1
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__MASK               0x00040000U
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field override_radio_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_radio_iso_field override_radio_iso_field
 * @brief macros for field override_radio_iso
 * @details If set, software now has direct control of radio isolation signal .
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__SHIFT                           19
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__WIDTH                            1
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__MASK                   0x00080000U
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_ISO__RESET_VALUE            0x00000000U
/** @} */

/* macros for field override_wreq_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_wreq_val_field override_wreq_val_field
 * @brief macros for field override_wreq_val
 * @details If override is set, what value is value of wake up request? Useful for debug/test of pseq interrupt.  0=no wake  1=wake
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__SHIFT                            20
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__WIDTH                             1
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__MASK                    0x00100000U
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_wreq */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_wreq_field override_wreq_field
 * @brief macros for field override_wreq
 * @details If set, software now has direct control of wake up request.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__SHIFT                                21
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__WIDTH                                 1
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__MASK                        0x00200000U
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PSEQ_OVERRIDES5__OVERRIDE_WREQ__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field override_radio_frst_b_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_radio_frst_b_val_field override_radio_frst_b_val_field
 * @brief macros for field override_radio_frst_b_val
 * @details If override is set, what value is the radio forced reset?  0=forced reset is enabled  1=forced reset is disabled
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__SHIFT                    22
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__WIDTH                     1
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__MASK            0x00400000U
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field override_radio_frst_b */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_radio_frst_b_field override_radio_frst_b_field
 * @brief macros for field override_radio_frst_b
 * @details If set, software now has direct control of radio forced reset .
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__SHIFT                        23
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__WIDTH                         1
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__MASK                0x00800000U
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_FRST_B__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_cutvdd_b_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_cutvdd_b_val_field override_cutvdd_b_val_field
 * @brief macros for field override_cutvdd_b_val
 * @details If override is set, what value is the radio enable?  0=head switches are open  1=head switches are closed
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__SHIFT                        24
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__WIDTH                         1
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__MASK                0x01000000U
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field override_cutvdd_b */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_cutvdd_b_field override_cutvdd_b_field
 * @brief macros for field override_cutvdd_b
 * @details If set, software now has direct control of radio head switches.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__SHIFT                            25
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__WIDTH                             1
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__MASK                    0x02000000U
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PSEQ_OVERRIDES5__OVERRIDE_CUTVDD_B__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_radio_en_o_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_radio_en_o_val_field override_radio_en_o_val_field
 * @brief macros for field override_radio_en_o_val
 * @details If override is set, what value is the radio enable?  0=off  1=on
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__SHIFT                      26
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__WIDTH                       1
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__MASK              0x04000000U
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O_VAL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field override_radio_en_o */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_radio_en_o_field override_radio_en_o_field
 * @brief macros for field override_radio_en_o
 * @details If set, software now has direct control of radio enable.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__SHIFT                          27
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__WIDTH                           1
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__MASK                  0x08000000U
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PSEQ_OVERRIDES5__OVERRIDE_RADIO_EN_O__RESET_VALUE           0x00000000U
/** @} */

/* macros for field override_retv_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_retv_val_field override_retv_val_field
 * @brief macros for field override_retv_val
 * @details If override is set, what value is the memory retention voltage?  0=nominal  1=ultra low
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__SHIFT                            28
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__WIDTH                             1
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__MASK                    0x10000000U
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_retv */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_retv_field override_retv_field
 * @brief macros for field override_retv
 * @details If set, software now has direct control of the memory retention voltage.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__SHIFT                                29
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__WIDTH                                 1
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__MASK                        0x20000000U
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PSEQ_OVERRIDES5__OVERRIDE_RETV__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field override_xtal_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_xtal_val_field override_xtal_val_field
 * @brief macros for field override_xtal_val
 * @details If override is set, what value is clk_mpc's cystal circuit enable?  0=off  1=on
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__SHIFT                            30
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__WIDTH                             1
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__MASK                    0x40000000U
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL_VAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field override_xtal */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_xtal_field override_xtal_field
 * @brief macros for field override_xtal
 * @details If set, software now has direct control of clk_mpc's crystal circuit enable.
 * @{
 */
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__SHIFT                                31
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__WIDTH                                 1
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__MASK                        0x80000000U
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PSEQ_OVERRIDES5__OVERRIDE_XTAL__RESET_VALUE                 0x00000000U
/** @} */
#define PSEQ_OVERRIDES5__TYPE                                          uint32_t
#define PSEQ_OVERRIDES5__READ                                       0xffffff00U
#define PSEQ_OVERRIDES5__WRITE                                      0xffffff00U
#define PSEQ_OVERRIDES5__PRESERVED                                  0x00000000U
#define PSEQ_OVERRIDES5__RESET_VALUE                                0x00000000U

#endif /* __PSEQ_OVERRIDES5_MACRO__ */

/** @} end of overrides5 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides sysram_overrides
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES_MACRO__

/* macros for field override_sysram_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_vddcut_val_field override_sysram_vddcut_val_field
 * @brief macros for field override_sysram_vddcut_val
 * @details If override is set, what is state of sysram's head switches?  [15] 16kB macro at high address space; [1] head switch open [0] head switch close  [14] 16kB macro; [1] head switch open [0] head switch close  [13] 16kB macro; [1] head switch open [0] head switch close  [12] 16kB macro; [1] head switch open [0] head switch close  [11] 16kB macro; [1] head switch open [0] head switch close  [10] 16kB macro; [1] head switch open [0] head switch close  [9] 16kB macro; [1] head switch open [0] head switch close  [8] 16kB macro; [1] head switch open [0] head switch close  [7] 16kB macro; [1] head switch open [0] head switch close  [6] 16kB macro; [1] head switch open [0] head switch close  [5] 16kB macro; [1] head switch open [0] head switch close  [4] 16kB macro; [1] head switch open [0] head switch close  [3] 16kB macro; [1] head switch open [0] head switch close  [2] 16kB macro; [1] head switch open [0] head switch close  [1] 16kB macro; [1] head switch open [0] head switch close  [0] 16kB macro at lowest address space; [1] head switch open [0] head switch close
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__SHIFT              0
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__WIDTH             16
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__MASK     0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_sysram_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_vddcut_field override_sysram_vddcut_field
 * @brief macros for field override_sysram_vddcut
 * @details If set, software now has direct control of sysram's head switches.  [31] 16kB macro at high address space  [30] 16kB macro; [1] head switch open [0] head switch close  [29] 16kB macro; [1] head switch open [0] head switch close  [28] 16kB macro; [1] head switch open [0] head switch close  [27] 16kB macro; [1] head switch open [0] head switch close  [26] 16kB macro; [1] head switch open [0] head switch close  [25] 16kB macro; [1] head switch open [0] head switch close  [24] 16kB macro; [1] head switch open [0] head switch close  [23] 16kB macro; [1] head switch open [0] head switch close  [22] 16kB macro; [1] head switch open [0] head switch close  [21] 16kB macro; [1] head switch open [0] head switch close  [20] 16kB macro; [1] head switch open [0] head switch close  [19] 16kB macro; [1] head switch open [0] head switch close  [18] 16kB macro; [1] head switch open [0] head switch close  [17] 16kB macro; [1] head switch open [0] head switch close  [16] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__SHIFT                 16
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__WIDTH                 16
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__MASK         0xffff0000U
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_SYSRAM_OVERRIDES__OVERRIDE_SYSRAM_VDDCUT__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES__TYPE                                    uint32_t
#define PSEQ_SYSRAM_OVERRIDES__READ                                 0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES__WRITE                                0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES__PRESERVED                            0x00000000U
#define PSEQ_SYSRAM_OVERRIDES__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES_MACRO__ */

/** @} end of sysram_overrides */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides2 sysram_overrides2
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES2_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES2_MACRO__

/* macros for field override_sysram_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_clken_val_field override_sysram_clken_val_field
 * @brief macros for field override_sysram_clken_val
 * @details If override is set, what is state of sysram's clock enable signals?  [15] 16kB macro at high address space  [14] 16kB macro  [13] 16kB macro  [12] 16kB macro  [11] 16kB macro  [10] 16kB macro  [9] 16kB macro  [8] 16kB macro  [7] 16kB macro  [6] 16kB macro  [5] 16kB macro  [4] 16kB macro  [3] 16kB macro  [2] 16kB macro  [1] 16kB macro  [0] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__SHIFT              0
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__WIDTH             16
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__MASK     0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_sysram_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_clken_field override_sysram_clken_field
 * @brief macros for field override_sysram_clken
 * @details If set, software now has direct control of sysram's clock enable signals.  [31] 16kB macro at high address space  [30] 16kB macro  [29] 16kB macro  [28] 16kB macro  [27] 16kB macro  [26] 16kB macro  [25] 16kB macro  [24] 16kB macro  [23] 16kB macro  [22] 16kB macro  [21] 16kB macro  [20] 16kB macro  [19] 16kB macro  [18] 16kB macro  [17] 16kB macro  [16] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__SHIFT                 16
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__WIDTH                 16
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__MASK         0xffff0000U
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_SYSRAM_OVERRIDES2__OVERRIDE_SYSRAM_CLKEN__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES2__TYPE                                   uint32_t
#define PSEQ_SYSRAM_OVERRIDES2__READ                                0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES2__WRITE                               0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES2__PRESERVED                           0x00000000U
#define PSEQ_SYSRAM_OVERRIDES2__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES2_MACRO__ */

/** @} end of sysram_overrides2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides3 sysram_overrides3
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES3_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES3_MACRO__

/* macros for field override_sysram_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_iso_val_field override_sysram_iso_val_field
 * @brief macros for field override_sysram_iso_val
 * @details If override is set, what is state of sysram's isolation signals?  [15] 16kB macro at high address space  [14] 16kB macro  [13] 16kB macro  [12] 16kB macro  [11] 16kB macro  [10] 16kB macro  [9] 16kB macro  [8] 16kB macro  [7] 16kB macro  [6] 16kB macro  [5] 16kB macro  [4] 16kB macro  [3] 16kB macro  [2] 16kB macro  [1] 16kB macro  [0] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__SHIFT                0
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__WIDTH               16
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__MASK       0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_sysram_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_iso_field override_sysram_iso_field
 * @brief macros for field override_sysram_iso
 * @details If set, software now has direct control of sysram's isolation signals.  [31] 16kB macro at high address space  [30] 16kB macro  [29] 16kB macro  [28] 16kB macro  [27] 16kB macro  [26] 16kB macro  [25] 16kB macro  [24] 16kB macro  [23] 16kB macro  [22] 16kB macro  [21] 16kB macro  [20] 16kB macro  [19] 16kB macro  [18] 16kB macro  [17] 16kB macro  [16] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__SHIFT                   16
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__WIDTH                   16
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__MASK           0xffff0000U
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_SYSRAM_OVERRIDES3__OVERRIDE_SYSRAM_ISO__RESET_VALUE    0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES3__TYPE                                   uint32_t
#define PSEQ_SYSRAM_OVERRIDES3__READ                                0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES3__WRITE                               0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES3__PRESERVED                           0x00000000U
#define PSEQ_SYSRAM_OVERRIDES3__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES3_MACRO__ */

/** @} end of sysram_overrides3 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides4 sysram_overrides4
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES4_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES4_MACRO__

/* macros for field override_sysram_ls_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_ls_val_field override_sysram_ls_val_field
 * @brief macros for field override_sysram_ls_val
 * @details If override is set, what is state of sysram's LS signals?  [15] 16kB macro at high address space  [14] 16kB macro  [13] 16kB macro  [12] 16kB macro  [11] 16kB macro  [10] 16kB macro  [9] 16kB macro  [8] 16kB macro  [7] 16kB macro  [6] 16kB macro  [5] 16kB macro  [4] 16kB macro  [3] 16kB macro  [2] 16kB macro  [1] 16kB macro  [0] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__SHIFT                 0
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__WIDTH                16
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__MASK        0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS_VAL__RESET_VALUE 0x00000000U
/** @} */

/* macros for field override_sysram_ls */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_ls_field override_sysram_ls_field
 * @brief macros for field override_sysram_ls
 * @details If set, software now has direct control of sysram's LS signals.  [31] 16kB macro at high address space  [30] 16kB macro  [29] 16kB macro  [28] 16kB macro  [27] 16kB macro  [26] 16kB macro  [25] 16kB macro  [24] 16kB macro  [23] 16kB macro  [22] 16kB macro  [21] 16kB macro  [20] 16kB macro  [19] 16kB macro  [18] 16kB macro  [17] 16kB macro  [16] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__SHIFT                    16
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__WIDTH                    16
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__MASK            0xffff0000U
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_SYSRAM_OVERRIDES4__OVERRIDE_SYSRAM_LS__RESET_VALUE     0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES4__TYPE                                   uint32_t
#define PSEQ_SYSRAM_OVERRIDES4__READ                                0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES4__WRITE                               0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES4__PRESERVED                           0x00000000U
#define PSEQ_SYSRAM_OVERRIDES4__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES4_MACRO__ */

/** @} end of sysram_overrides4 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides5 sysram_overrides5
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES5_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES5_MACRO__

/* macros for field override_sysram_ds_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_ds_val_field override_sysram_ds_val_field
 * @brief macros for field override_sysram_ds_val
 * @details If override is set, what is state of sysram's DS signals?  [15] 16kB macro at high address space  [14] 16kB macro  [13] 16kB macro  [12] 16kB macro  [11] 16kB macro  [10] 16kB macro  [9] 16kB macro  [8] 16kB macro  [7] 16kB macro  [6] 16kB macro  [5] 16kB macro  [4] 16kB macro  [3] 16kB macro  [2] 16kB macro  [1] 16kB macro  [0] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__SHIFT                 0
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__WIDTH                16
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__MASK        0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS_VAL__RESET_VALUE 0x00000000U
/** @} */

/* macros for field override_sysram_ds */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_ds_field override_sysram_ds_field
 * @brief macros for field override_sysram_ds
 * @details If set, software now has direct control of sysram's DS signals.  [31] 16kB macro at high address space  [30] 16kB macro  [29] 16kB macro  [28] 16kB macro  [27] 16kB macro  [26] 16kB macro  [25] 16kB macro  [24] 16kB macro  [23] 16kB macro  [22] 16kB macro  [21] 16kB macro  [20] 16kB macro  [19] 16kB macro  [18] 16kB macro  [17] 16kB macro  [16] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__SHIFT                    16
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__WIDTH                    16
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__MASK            0xffff0000U
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_SYSRAM_OVERRIDES5__OVERRIDE_SYSRAM_DS__RESET_VALUE     0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES5__TYPE                                   uint32_t
#define PSEQ_SYSRAM_OVERRIDES5__READ                                0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES5__WRITE                               0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES5__PRESERVED                           0x00000000U
#define PSEQ_SYSRAM_OVERRIDES5__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES5_MACRO__ */

/** @} end of sysram_overrides5 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides6 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides6 sysram_overrides6
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES6_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES6_MACRO__

/* macros for field override_sysram_sd_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_sd_val_field override_sysram_sd_val_field
 * @brief macros for field override_sysram_sd_val
 * @details If override is set, what is state of sysram's SD signals?  [15] 16kB macro at high address space  [14] 16kB macro  [13] 16kB macro  [12] 16kB macro  [11] 16kB macro  [10] 16kB macro  [9] 16kB macro  [8] 16kB macro  [7] 16kB macro  [6] 16kB macro  [5] 16kB macro  [4] 16kB macro  [3] 16kB macro  [2] 16kB macro  [1] 16kB macro  [0] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__SHIFT                 0
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__WIDTH                16
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__MASK        0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD_VAL__RESET_VALUE 0x00000000U
/** @} */

/* macros for field override_sysram_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_sysram_sd_field override_sysram_sd_field
 * @brief macros for field override_sysram_sd
 * @details If set, software now has direct control of sysram's SD signals.  [31] 16kB macro at high address space  [30] 16kB macro  [29] 16kB macro  [28] 16kB macro  [27] 16kB macro  [26] 16kB macro  [25] 16kB macro  [24] 16kB macro  [23] 16kB macro  [22] 16kB macro  [21] 16kB macro  [20] 16kB macro  [19] 16kB macro  [18] 16kB macro  [17] 16kB macro  [16] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__SHIFT                    16
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__WIDTH                    16
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__MASK            0xffff0000U
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PSEQ_SYSRAM_OVERRIDES6__OVERRIDE_SYSRAM_SD__RESET_VALUE     0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES6__TYPE                                   uint32_t
#define PSEQ_SYSRAM_OVERRIDES6__READ                                0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES6__WRITE                               0xffffffffU
#define PSEQ_SYSRAM_OVERRIDES6__PRESERVED                           0x00000000U
#define PSEQ_SYSRAM_OVERRIDES6__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES6_MACRO__ */

/** @} end of sysram_overrides6 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides7 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides7 sysram_overrides7
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES7_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES7_MACRO__

/* macros for field block_sysram_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_sysram_vddcut_field block_sysram_vddcut_field
 * @brief macros for field block_sysram_vddcut
 * @details Block core's FSM from cutting the vdd supplies to the sysram.  [15] 16kB macro at high address space  [14] 16kB macro  [13] 16kB macro  [12] 16kB macro  [11] 16kB macro  [10] 16kB macro  [9] 16kB macro  [8] 16kB macro  [7] 16kB macro  [6] 16kB macro  [5] 16kB macro  [4] 16kB macro  [3] 16kB macro  [2] 16kB macro  [1] 16kB macro  [0] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__SHIFT                    0
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__WIDTH                   16
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__MASK           0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__RESET_VALUE    0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES7__TYPE                                   uint32_t
#define PSEQ_SYSRAM_OVERRIDES7__READ                                0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES7__WRITE                               0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES7__PRESERVED                           0x00000000U
#define PSEQ_SYSRAM_OVERRIDES7__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES7_MACRO__ */

/** @} end of sysram_overrides7 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_overrides8 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_overrides8 sysram_overrides8
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_OVERRIDES8_MACRO__
#define __PSEQ_SYSRAM_OVERRIDES8_MACRO__

/* macros for field block_sysram_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_sysram_sd_field block_sysram_sd_field
 * @brief macros for field block_sysram_sd
 * @details Block core's FSM from setting the SD signal to the sysram.  [15] 16kB macro at high address space  [14] 16kB macro  [13] 16kB macro  [12] 16kB macro  [11] 16kB macro  [10] 16kB macro  [9] 16kB macro  [8] 16kB macro  [7] 16kB macro  [6] 16kB macro  [5] 16kB macro  [4] 16kB macro  [3] 16kB macro  [2] 16kB macro  [1] 16kB macro  [0] 16kB macro at lowest address space
 * @{
 */
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__SHIFT                        0
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__WIDTH                       16
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__MASK               0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PSEQ_SYSRAM_OVERRIDES8__BLOCK_SYSRAM_SD__RESET_VALUE        0x00000000U
/** @} */
#define PSEQ_SYSRAM_OVERRIDES8__TYPE                                   uint32_t
#define PSEQ_SYSRAM_OVERRIDES8__READ                                0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES8__WRITE                               0x0000ffffU
#define PSEQ_SYSRAM_OVERRIDES8__PRESERVED                           0x00000000U
#define PSEQ_SYSRAM_OVERRIDES8__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SYSRAM_OVERRIDES8_MACRO__ */

/** @} end of sysram_overrides8 */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides emram_overrides
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES_MACRO__
#define __PSEQ_EMRAM_OVERRIDES_MACRO__

/* macros for field override_emram_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_vddcut_val_field override_emram_vddcut_val_field
 * @brief macros for field override_emram_vddcut_val
 * @details If override is set, what are the states of exchange memory vddcut signals?
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__SHIFT                0
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__WIDTH                2
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__MASK       0x00000003U
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_emram_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_vddcut_field override_emram_vddcut_field
 * @brief macros for field override_emram_vddcut
 * @details If set, software now has direct control of exchange memory vddcut signals.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__SHIFT                   12
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__WIDTH                    2
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__MASK           0x00003000U
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PSEQ_EMRAM_OVERRIDES__OVERRIDE_EMRAM_VDDCUT__RESET_VALUE    0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES__TYPE                                     uint32_t
#define PSEQ_EMRAM_OVERRIDES__READ                                  0x00003003U
#define PSEQ_EMRAM_OVERRIDES__WRITE                                 0x00003003U
#define PSEQ_EMRAM_OVERRIDES__PRESERVED                             0x00000000U
#define PSEQ_EMRAM_OVERRIDES__RESET_VALUE                           0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES_MACRO__ */

/** @} end of emram_overrides */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides2 emram_overrides2
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES2_MACRO__
#define __PSEQ_EMRAM_OVERRIDES2_MACRO__

/* macros for field override_emram_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_clken_val_field override_emram_clken_val_field
 * @brief macros for field override_emram_clken_val
 * @details If override is set, what are the states of exchange memory clock enable signals?
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__SHIFT                0
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__WIDTH                2
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__MASK       0x00000003U
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_emram_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_clken_field override_emram_clken_field
 * @brief macros for field override_emram_clken
 * @details If set, software now has direct control of exchange memory clock enable signals.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__SHIFT                   12
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__WIDTH                    2
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__MASK           0x00003000U
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PSEQ_EMRAM_OVERRIDES2__OVERRIDE_EMRAM_CLKEN__RESET_VALUE    0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES2__TYPE                                    uint32_t
#define PSEQ_EMRAM_OVERRIDES2__READ                                 0x00003003U
#define PSEQ_EMRAM_OVERRIDES2__WRITE                                0x00003003U
#define PSEQ_EMRAM_OVERRIDES2__PRESERVED                            0x00000000U
#define PSEQ_EMRAM_OVERRIDES2__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES2_MACRO__ */

/** @} end of emram_overrides2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides3 emram_overrides3
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES3_MACRO__
#define __PSEQ_EMRAM_OVERRIDES3_MACRO__

/* macros for field override_emram_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_iso_val_field override_emram_iso_val_field
 * @brief macros for field override_emram_iso_val
 * @details If override is set, what are the states of exchange memory isolation signals?
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__SHIFT                  0
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__WIDTH                  2
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__MASK         0x00000003U
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO_VAL__RESET_VALUE  0x00000000U
/** @} */

/* macros for field override_emram_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_iso_field override_emram_iso_field
 * @brief macros for field override_emram_iso
 * @details If set, software now has direct control of exchange memory isolation signals.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__SHIFT                     12
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__WIDTH                      2
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__MASK             0x00003000U
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PSEQ_EMRAM_OVERRIDES3__OVERRIDE_EMRAM_ISO__RESET_VALUE      0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES3__TYPE                                    uint32_t
#define PSEQ_EMRAM_OVERRIDES3__READ                                 0x00003003U
#define PSEQ_EMRAM_OVERRIDES3__WRITE                                0x00003003U
#define PSEQ_EMRAM_OVERRIDES3__PRESERVED                            0x00000000U
#define PSEQ_EMRAM_OVERRIDES3__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES3_MACRO__ */

/** @} end of emram_overrides3 */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides4 emram_overrides4
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES4_MACRO__
#define __PSEQ_EMRAM_OVERRIDES4_MACRO__

/* macros for field override_emram_ls_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_ls_val_field override_emram_ls_val_field
 * @brief macros for field override_emram_ls_val
 * @details If override is set, what are the states of exchange memory LS signals?
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__SHIFT                   0
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__WIDTH                   2
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__MASK          0x00000003U
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS_VAL__RESET_VALUE   0x00000000U
/** @} */

/* macros for field override_emram_ls */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_ls_field override_emram_ls_field
 * @brief macros for field override_emram_ls
 * @details If set, software now has direct control of exchange memory LS signals.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__SHIFT                      12
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__WIDTH                       2
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__MASK              0x00003000U
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PSEQ_EMRAM_OVERRIDES4__OVERRIDE_EMRAM_LS__RESET_VALUE       0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES4__TYPE                                    uint32_t
#define PSEQ_EMRAM_OVERRIDES4__READ                                 0x00003003U
#define PSEQ_EMRAM_OVERRIDES4__WRITE                                0x00003003U
#define PSEQ_EMRAM_OVERRIDES4__PRESERVED                            0x00000000U
#define PSEQ_EMRAM_OVERRIDES4__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES4_MACRO__ */

/** @} end of emram_overrides4 */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides5 emram_overrides5
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES5_MACRO__
#define __PSEQ_EMRAM_OVERRIDES5_MACRO__

/* macros for field override_emram_ds_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_ds_val_field override_emram_ds_val_field
 * @brief macros for field override_emram_ds_val
 * @details If override is set, what are the states of exchange memory DS signals?
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__SHIFT                   0
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__WIDTH                   2
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__MASK          0x00000003U
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS_VAL__RESET_VALUE   0x00000000U
/** @} */

/* macros for field override_emram_ds */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_ds_field override_emram_ds_field
 * @brief macros for field override_emram_ds
 * @details If set, software now has direct control of exchange memory DS signals.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__SHIFT                      12
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__WIDTH                       2
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__MASK              0x00003000U
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PSEQ_EMRAM_OVERRIDES5__OVERRIDE_EMRAM_DS__RESET_VALUE       0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES5__TYPE                                    uint32_t
#define PSEQ_EMRAM_OVERRIDES5__READ                                 0x00003003U
#define PSEQ_EMRAM_OVERRIDES5__WRITE                                0x00003003U
#define PSEQ_EMRAM_OVERRIDES5__PRESERVED                            0x00000000U
#define PSEQ_EMRAM_OVERRIDES5__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES5_MACRO__ */

/** @} end of emram_overrides5 */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides6 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides6 emram_overrides6
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES6_MACRO__
#define __PSEQ_EMRAM_OVERRIDES6_MACRO__

/* macros for field override_emram_sd_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_sd_val_field override_emram_sd_val_field
 * @brief macros for field override_emram_sd_val
 * @details If override is set, what are the states of exchange memory SD signals?
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__SHIFT                   0
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__WIDTH                   2
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__MASK          0x00000003U
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD_VAL__RESET_VALUE   0x00000000U
/** @} */

/* macros for field override_emram_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_emram_sd_field override_emram_sd_field
 * @brief macros for field override_emram_sd
 * @details If set, software now has direct control of exchange memory SD signals.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__SHIFT                      12
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__WIDTH                       2
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__MASK              0x00003000U
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define PSEQ_EMRAM_OVERRIDES6__OVERRIDE_EMRAM_SD__RESET_VALUE       0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES6__TYPE                                    uint32_t
#define PSEQ_EMRAM_OVERRIDES6__READ                                 0x00003003U
#define PSEQ_EMRAM_OVERRIDES6__WRITE                                0x00003003U
#define PSEQ_EMRAM_OVERRIDES6__PRESERVED                            0x00000000U
#define PSEQ_EMRAM_OVERRIDES6__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES6_MACRO__ */

/** @} end of emram_overrides6 */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides7 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides7 emram_overrides7
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES7_MACRO__
#define __PSEQ_EMRAM_OVERRIDES7_MACRO__

/* macros for field block_emram_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_emram_vddcut_field block_emram_vddcut_field
 * @brief macros for field block_emram_vddcut
 * @details If set, core's FSM cannot open the exchange memory head switches.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__SHIFT                      0
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__WIDTH                      2
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__MASK             0x00000003U
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES7__BLOCK_EMRAM_VDDCUT__RESET_VALUE      0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES7__TYPE                                    uint32_t
#define PSEQ_EMRAM_OVERRIDES7__READ                                 0x00000003U
#define PSEQ_EMRAM_OVERRIDES7__WRITE                                0x00000003U
#define PSEQ_EMRAM_OVERRIDES7__PRESERVED                            0x00000000U
#define PSEQ_EMRAM_OVERRIDES7__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES7_MACRO__ */

/** @} end of emram_overrides7 */

/* macros for BlueprintGlobalNameSpace::PSEQ_emram_overrides8 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_emram_overrides8 emram_overrides8
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_EMRAM_OVERRIDES8_MACRO__
#define __PSEQ_EMRAM_OVERRIDES8_MACRO__

/* macros for field block_emram_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_emram_sd_field block_emram_sd_field
 * @brief macros for field block_emram_sd
 * @details If set, core's FSM cannot set the exchange memory SD signals.
 * @{
 */
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__SHIFT                          0
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__WIDTH                          2
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__MASK                 0x00000003U
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PSEQ_EMRAM_OVERRIDES8__BLOCK_EMRAM_SD__RESET_VALUE          0x00000000U
/** @} */
#define PSEQ_EMRAM_OVERRIDES8__TYPE                                    uint32_t
#define PSEQ_EMRAM_OVERRIDES8__READ                                 0x00000003U
#define PSEQ_EMRAM_OVERRIDES8__WRITE                                0x00000003U
#define PSEQ_EMRAM_OVERRIDES8__PRESERVED                            0x00000000U
#define PSEQ_EMRAM_OVERRIDES8__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_EMRAM_OVERRIDES8_MACRO__ */

/** @} end of emram_overrides8 */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides icache_overrides
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES_MACRO__
#define __PSEQ_ICACHE_OVERRIDES_MACRO__

/* macros for field override_icache_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_vddcut_val_field override_icache_vddcut_val_field
 * @brief macros for field override_icache_vddcut_val
 * @details If override is set, what is state of cpu icache's head switches?  [3] data1 macro; [1] head switch open [0] head switch close  [2] data0 macro; [1] head switch open [0] head switch close  [1] tag1 macro; [1] head switch open [0] head switch close  [0] tag0 macro; [1] head switch open [0] head switch close
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__SHIFT              0
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__WIDTH              4
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__MASK     0x0000000fU
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_icache_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_vddcut_field override_icache_vddcut_field
 * @brief macros for field override_icache_vddcut
 * @details If set, software now has direct control of cpu icache's head switches.  [15] data1 macro  [14] data0 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__SHIFT                 12
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__WIDTH                  4
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__MASK         0x0000f000U
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PSEQ_ICACHE_OVERRIDES__OVERRIDE_ICACHE_VDDCUT__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES__TYPE                                    uint32_t
#define PSEQ_ICACHE_OVERRIDES__READ                                 0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES__WRITE                                0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES__PRESERVED                            0x00000000U
#define PSEQ_ICACHE_OVERRIDES__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES_MACRO__ */

/** @} end of icache_overrides */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides2 icache_overrides2
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES2_MACRO__
#define __PSEQ_ICACHE_OVERRIDES2_MACRO__

/* macros for field override_icache_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_clken_val_field override_icache_clken_val_field
 * @brief macros for field override_icache_clken_val
 * @details If override is set, what is state of cpu icache's clock enable signals?  [3] data1 macro  [2] data0 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__SHIFT              0
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__WIDTH              4
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__MASK     0x0000000fU
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_icache_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_clken_field override_icache_clken_field
 * @brief macros for field override_icache_clken
 * @details If set, software now has direct control of cpu icache's clock enable signals.  [15] data1 macro  [14] data0 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__SHIFT                 12
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__WIDTH                  4
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__MASK         0x0000f000U
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PSEQ_ICACHE_OVERRIDES2__OVERRIDE_ICACHE_CLKEN__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES2__TYPE                                   uint32_t
#define PSEQ_ICACHE_OVERRIDES2__READ                                0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES2__WRITE                               0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES2__PRESERVED                           0x00000000U
#define PSEQ_ICACHE_OVERRIDES2__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES2_MACRO__ */

/** @} end of icache_overrides2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides3 icache_overrides3
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES3_MACRO__
#define __PSEQ_ICACHE_OVERRIDES3_MACRO__

/* macros for field override_icache_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_iso_val_field override_icache_iso_val_field
 * @brief macros for field override_icache_iso_val
 * @details If override is set, what is state of cpu icache's isolation signals?  [3] data1 macro  [2] data0 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__SHIFT                0
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__WIDTH                4
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__MASK       0x0000000fU
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_icache_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_iso_field override_icache_iso_field
 * @brief macros for field override_icache_iso
 * @details If set, software now has direct control of cpu icache's isolation signals.  [15] data1 macro  [14] data0 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__SHIFT                   12
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__WIDTH                    4
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__MASK           0x0000f000U
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PSEQ_ICACHE_OVERRIDES3__OVERRIDE_ICACHE_ISO__RESET_VALUE    0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES3__TYPE                                   uint32_t
#define PSEQ_ICACHE_OVERRIDES3__READ                                0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES3__WRITE                               0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES3__PRESERVED                           0x00000000U
#define PSEQ_ICACHE_OVERRIDES3__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES3_MACRO__ */

/** @} end of icache_overrides3 */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides4 icache_overrides4
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES4_MACRO__
#define __PSEQ_ICACHE_OVERRIDES4_MACRO__

/* macros for field override_icache_ls_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_ls_val_field override_icache_ls_val_field
 * @brief macros for field override_icache_ls_val
 * @details If override is set, what is state of cpu icache's LS signals?  [3] data1 macro  [2] data0 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__SHIFT                 0
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__WIDTH                 4
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__MASK        0x0000000fU
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS_VAL__RESET_VALUE 0x00000000U
/** @} */

/* macros for field override_icache_ls */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_ls_field override_icache_ls_field
 * @brief macros for field override_icache_ls
 * @details If set, software now has direct control of cpu icache's LS signals.  [15] data1 macro  [14] data0 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__SHIFT                    12
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__WIDTH                     4
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__MASK            0x0000f000U
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PSEQ_ICACHE_OVERRIDES4__OVERRIDE_ICACHE_LS__RESET_VALUE     0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES4__TYPE                                   uint32_t
#define PSEQ_ICACHE_OVERRIDES4__READ                                0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES4__WRITE                               0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES4__PRESERVED                           0x00000000U
#define PSEQ_ICACHE_OVERRIDES4__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES4_MACRO__ */

/** @} end of icache_overrides4 */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides5 icache_overrides5
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES5_MACRO__
#define __PSEQ_ICACHE_OVERRIDES5_MACRO__

/* macros for field override_icache_ds_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_ds_val_field override_icache_ds_val_field
 * @brief macros for field override_icache_ds_val
 * @details If override is set, what is state of cpu icache's DS signals?  [3] data1 macro  [2] data0 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__SHIFT                 0
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__WIDTH                 4
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__MASK        0x0000000fU
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS_VAL__RESET_VALUE 0x00000000U
/** @} */

/* macros for field override_icache_ds */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_ds_field override_icache_ds_field
 * @brief macros for field override_icache_ds
 * @details If set, software now has direct control of cpu icache's DS signals.  [15] data1 macro  [14] data0 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__SHIFT                    12
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__WIDTH                     4
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__MASK            0x0000f000U
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PSEQ_ICACHE_OVERRIDES5__OVERRIDE_ICACHE_DS__RESET_VALUE     0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES5__TYPE                                   uint32_t
#define PSEQ_ICACHE_OVERRIDES5__READ                                0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES5__WRITE                               0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES5__PRESERVED                           0x00000000U
#define PSEQ_ICACHE_OVERRIDES5__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES5_MACRO__ */

/** @} end of icache_overrides5 */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides6 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides6 icache_overrides6
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES6_MACRO__
#define __PSEQ_ICACHE_OVERRIDES6_MACRO__

/* macros for field override_icache_sd_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_sd_val_field override_icache_sd_val_field
 * @brief macros for field override_icache_sd_val
 * @details If override is set, what is state of cpu icache's SD signals?  [3] data1 macro  [2] data0 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__SHIFT                 0
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__WIDTH                 4
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__MASK        0x0000000fU
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD_VAL__RESET_VALUE 0x00000000U
/** @} */

/* macros for field override_icache_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_icache_sd_field override_icache_sd_field
 * @brief macros for field override_icache_sd
 * @details If set, software now has direct control of cpu icache's SD signals.  [15] data1 macro  [14] data0 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__SHIFT                    12
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__WIDTH                     4
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__MASK            0x0000f000U
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PSEQ_ICACHE_OVERRIDES6__OVERRIDE_ICACHE_SD__RESET_VALUE     0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES6__TYPE                                   uint32_t
#define PSEQ_ICACHE_OVERRIDES6__READ                                0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES6__WRITE                               0x0000f00fU
#define PSEQ_ICACHE_OVERRIDES6__PRESERVED                           0x00000000U
#define PSEQ_ICACHE_OVERRIDES6__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES6_MACRO__ */

/** @} end of icache_overrides6 */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides7 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides7 icache_overrides7
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES7_MACRO__
#define __PSEQ_ICACHE_OVERRIDES7_MACRO__

/* macros for field block_icache_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_icache_vddcut_field block_icache_vddcut_field
 * @brief macros for field block_icache_vddcut
 * @details Block core's FSM from cutting the vdd supplies to the icache.  [3] data1 macro  [2] data0 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__SHIFT                    0
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__WIDTH                    4
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__MASK           0x0000000fU
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES7__BLOCK_ICACHE_VDDCUT__RESET_VALUE    0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES7__TYPE                                   uint32_t
#define PSEQ_ICACHE_OVERRIDES7__READ                                0x0000000fU
#define PSEQ_ICACHE_OVERRIDES7__WRITE                               0x0000000fU
#define PSEQ_ICACHE_OVERRIDES7__PRESERVED                           0x00000000U
#define PSEQ_ICACHE_OVERRIDES7__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES7_MACRO__ */

/** @} end of icache_overrides7 */

/* macros for BlueprintGlobalNameSpace::PSEQ_icache_overrides8 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_icache_overrides8 icache_overrides8
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_ICACHE_OVERRIDES8_MACRO__
#define __PSEQ_ICACHE_OVERRIDES8_MACRO__

/* macros for field block_icache_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_icache_sd_field block_icache_sd_field
 * @brief macros for field block_icache_sd
 * @details Block core's FSM from setting the SD signal to the icache.  [3] data1 macro  [2] data0 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__SHIFT                        0
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__WIDTH                        4
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__MASK               0x0000000fU
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_ICACHE_OVERRIDES8__BLOCK_ICACHE_SD__RESET_VALUE        0x00000000U
/** @} */
#define PSEQ_ICACHE_OVERRIDES8__TYPE                                   uint32_t
#define PSEQ_ICACHE_OVERRIDES8__READ                                0x0000000fU
#define PSEQ_ICACHE_OVERRIDES8__WRITE                               0x0000000fU
#define PSEQ_ICACHE_OVERRIDES8__PRESERVED                           0x00000000U
#define PSEQ_ICACHE_OVERRIDES8__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_ICACHE_OVERRIDES8_MACRO__ */

/** @} end of icache_overrides8 */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides rramcache_overrides
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES_MACRO__

/* macros for field override_rramcache_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_vddcut_val_field override_rramcache_vddcut_val_field
 * @brief macros for field override_rramcache_vddcut_val
 * @details If override is set, what is state of cpu rram cache's's head switches?  [5] data1 macro; [1] head switch open [0] head switch close  [4] data0 macro; [1] head switch open [0] head switch close  [3] tag3 macro; [1] head switch open [0] head switch close  [2] tag2 macro; [1] head switch open [0] head switch close  [1] tag1 macro; [1] head switch open [0] head switch close  [0] tag0 macro; [1] head switch open [0] head switch close
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__SHIFT        0
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__WIDTH        6
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__MASK \
                    0x0000003fU
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_rramcache_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_vddcut_field override_rramcache_vddcut_field
 * @brief macros for field override_rramcache_vddcut
 * @details If set, software now has direct control of cpu rram cache's head switches.  [17] data1 macro  [16] data0 macro  [15] tag3 macro  [14] tag2 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__SHIFT           12
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__WIDTH            6
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__MASK   0x0003f000U
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define PSEQ_RRAMCACHE_OVERRIDES__OVERRIDE_RRAMCACHE_VDDCUT__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES__TYPE                                 uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES__READ                              0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES__WRITE                             0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES__PRESERVED                         0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES__RESET_VALUE                       0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES_MACRO__ */

/** @} end of rramcache_overrides */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides2 rramcache_overrides2
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES2_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES2_MACRO__

/* macros for field override_rramcache_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_clken_val_field override_rramcache_clken_val_field
 * @brief macros for field override_rramcache_clken_val
 * @details If override is set, what is state of cpu rram cache's clock enable signals?  [5] data1 macro  [4] data0 macro  [3] tag3 macro  [2] tag2 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__SHIFT        0
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__WIDTH        6
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__MASK \
                    0x0000003fU
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_rramcache_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_clken_field override_rramcache_clken_field
 * @brief macros for field override_rramcache_clken
 * @details If set, software now has direct control of cpu rram cache's clock enable signals.  [17] data1 macro  [16] data0 macro  [15] tag3 macro  [14] tag2 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__SHIFT           12
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__WIDTH            6
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__MASK   0x0003f000U
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define PSEQ_RRAMCACHE_OVERRIDES2__OVERRIDE_RRAMCACHE_CLKEN__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES2__TYPE                                uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES2__READ                             0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES2__WRITE                            0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES2__PRESERVED                        0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES2__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES2_MACRO__ */

/** @} end of rramcache_overrides2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides3 rramcache_overrides3
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES3_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES3_MACRO__

/* macros for field override_rramcache_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_iso_val_field override_rramcache_iso_val_field
 * @brief macros for field override_rramcache_iso_val
 * @details If override is set, what is state of cpu rram cache's isolation signals?  [5] data1 macro  [4] data0 macro  [3] tag3 macro  [2] tag2 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__SHIFT          0
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__WIDTH          6
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__MASK 0x0000003fU
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_rramcache_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_iso_field override_rramcache_iso_field
 * @brief macros for field override_rramcache_iso
 * @details If set, software now has direct control of cpu rram cache's isolation signals.  [17] data1 macro  [16] data0 macro  [15] tag3 macro  [14] tag2 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__SHIFT             12
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__WIDTH              6
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__MASK     0x0003f000U
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define PSEQ_RRAMCACHE_OVERRIDES3__OVERRIDE_RRAMCACHE_ISO__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES3__TYPE                                uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES3__READ                             0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES3__WRITE                            0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES3__PRESERVED                        0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES3__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES3_MACRO__ */

/** @} end of rramcache_overrides3 */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides4 rramcache_overrides4
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES4_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES4_MACRO__

/* macros for field override_rramcache_ls_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_ls_val_field override_rramcache_ls_val_field
 * @brief macros for field override_rramcache_ls_val
 * @details If override is set, what is state of cpu rram cache's LS signals?  [5] data1 macro  [4] data0 macro  [3] tag3 macro  [2] tag2 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__SHIFT           0
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__WIDTH           6
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__MASK  0x0000003fU
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_rramcache_ls */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_ls_field override_rramcache_ls_field
 * @brief macros for field override_rramcache_ls
 * @details If set, software now has direct control of cpu rram cache's LS signals.  [17] data1 macro  [16] data0 macro  [15] tag3 macro  [14] tag2 macro  [13] tag1 macro  [12] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__SHIFT              12
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__WIDTH               6
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__MASK      0x0003f000U
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define PSEQ_RRAMCACHE_OVERRIDES4__OVERRIDE_RRAMCACHE_LS__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES4__TYPE                                uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES4__READ                             0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES4__WRITE                            0x0003f03fU
#define PSEQ_RRAMCACHE_OVERRIDES4__PRESERVED                        0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES4__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES4_MACRO__ */

/** @} end of rramcache_overrides4 */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides5 rramcache_overrides5
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES5_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES5_MACRO__

/* macros for field override_rramcache_ds_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_ds_val_field override_rramcache_ds_val_field
 * @brief macros for field override_rramcache_ds_val
 * @details If override is set, what is state of cpu rram cache's DS signals?  [5] data1 macro  [4] data0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__SHIFT           4
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__WIDTH           2
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__MASK  0x00000030U
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_rramcache_ds */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_ds_field override_rramcache_ds_field
 * @brief macros for field override_rramcache_ds
 * @details If set, software now has direct control of cpu rram cache's DS signals.  [17] data1 macro  [16] data0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__SHIFT              16
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__WIDTH               2
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__MASK      0x00030000U
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define PSEQ_RRAMCACHE_OVERRIDES5__OVERRIDE_RRAMCACHE_DS__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES5__TYPE                                uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES5__READ                             0x00030030U
#define PSEQ_RRAMCACHE_OVERRIDES5__WRITE                            0x00030030U
#define PSEQ_RRAMCACHE_OVERRIDES5__PRESERVED                        0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES5__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES5_MACRO__ */

/** @} end of rramcache_overrides5 */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides6 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides6 rramcache_overrides6
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES6_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES6_MACRO__

/* macros for field override_rramcache_sd_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_sd_val_field override_rramcache_sd_val_field
 * @brief macros for field override_rramcache_sd_val
 * @details If override is set, what is state of cpu rram cache's SD signals?  [5] data1 macro  [4] data0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__SHIFT           4
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__WIDTH           2
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__MASK  0x00000030U
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_rramcache_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_rramcache_sd_field override_rramcache_sd_field
 * @brief macros for field override_rramcache_sd
 * @details If set, software now has direct control of cpu rram cache's SD signals.  [17] data1 macro  [16] data0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__SHIFT              16
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__WIDTH               2
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__MASK      0x00030000U
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define PSEQ_RRAMCACHE_OVERRIDES6__OVERRIDE_RRAMCACHE_SD__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES6__TYPE                                uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES6__READ                             0x00030030U
#define PSEQ_RRAMCACHE_OVERRIDES6__WRITE                            0x00030030U
#define PSEQ_RRAMCACHE_OVERRIDES6__PRESERVED                        0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES6__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES6_MACRO__ */

/** @} end of rramcache_overrides6 */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides7 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides7 rramcache_overrides7
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES7_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES7_MACRO__

/* macros for field block_rramcache_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_rramcache_vddcut_field block_rramcache_vddcut_field
 * @brief macros for field block_rramcache_vddcut
 * @details Block core's FSM from cutting the vdd supplies to the rram cache.  [5] data1 macro  [4] data0 macro  [3] tag3 macro  [2] tag2 macro  [1] tag1 macro  [0] tag0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__SHIFT              0
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__WIDTH              6
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__MASK     0x0000003fU
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define PSEQ_RRAMCACHE_OVERRIDES7__BLOCK_RRAMCACHE_VDDCUT__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES7__TYPE                                uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES7__READ                             0x0000003fU
#define PSEQ_RRAMCACHE_OVERRIDES7__WRITE                            0x0000003fU
#define PSEQ_RRAMCACHE_OVERRIDES7__PRESERVED                        0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES7__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES7_MACRO__ */

/** @} end of rramcache_overrides7 */

/* macros for BlueprintGlobalNameSpace::PSEQ_rramcache_overrides8 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rramcache_overrides8 rramcache_overrides8
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_RRAMCACHE_OVERRIDES8_MACRO__
#define __PSEQ_RRAMCACHE_OVERRIDES8_MACRO__

/* macros for field block_rramcache_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_rramcache_sd_field block_rramcache_sd_field
 * @brief macros for field block_rramcache_sd
 * @details Block core's FSM from setting the SD signal to the rram cache.  [5] data1 macro  [4] data0 macro
 * @{
 */
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__SHIFT                  4
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__WIDTH                  2
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__MASK         0x00000030U
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define PSEQ_RRAMCACHE_OVERRIDES8__BLOCK_RRAMCACHE_SD__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_RRAMCACHE_OVERRIDES8__TYPE                                uint32_t
#define PSEQ_RRAMCACHE_OVERRIDES8__READ                             0x00000030U
#define PSEQ_RRAMCACHE_OVERRIDES8__WRITE                            0x00000030U
#define PSEQ_RRAMCACHE_OVERRIDES8__PRESERVED                        0x00000000U
#define PSEQ_RRAMCACHE_OVERRIDES8__RESET_VALUE                      0x00000000U

#endif /* __PSEQ_RRAMCACHE_OVERRIDES8_MACRO__ */

/** @} end of rramcache_overrides8 */

/* macros for BlueprintGlobalNameSpace::PSEQ_qspicache_overrides */
/**
 * @defgroup at_apb_pseq_perth_regs_core_qspicache_overrides qspicache_overrides
 * @brief override portion of pmu control signals definitions.
 * @{
 */
#ifndef __PSEQ_QSPICACHE_OVERRIDES_MACRO__
#define __PSEQ_QSPICACHE_OVERRIDES_MACRO__

/* macros for field block_qspicache_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_qspicache_sd_field block_qspicache_sd_field
 * @brief macros for field block_qspicache_sd
 * @details if set, this core's FSM cannot assert the qspi cache SD pin
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__SHIFT                   0
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__WIDTH                   1
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__MASK          0x00000001U
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_SD__RESET_VALUE   0x00000000U
/** @} */

/* macros for field block_qspicache_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_block_qspicache_vddcut_field block_qspicache_vddcut_field
 * @brief macros for field block_qspicache_vddcut
 * @details if set, this core's FSM cannot power off the qspi cache
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__SHIFT               1
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__WIDTH               1
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__MASK      0x00000002U
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_QSPICACHE_OVERRIDES__BLOCK_QSPICACHE_VDDCUT__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_sd_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_sd_val_field override_qspicache_sd_val_field
 * @brief macros for field override_qspicache_sd_val
 * @details if override is set, what value should be driven onto qspi cache SD pin?
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__SHIFT            2
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__WIDTH            1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__MASK   0x00000004U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_sd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_sd_field override_qspicache_sd_field
 * @brief macros for field override_qspicache_sd
 * @details if set, software now has direct control of the qspi cache SD pin
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__SHIFT                3
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__WIDTH                1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__MASK       0x00000008U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_SD__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_ds_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_ds_val_field override_qspicache_ds_val_field
 * @brief macros for field override_qspicache_ds_val
 * @details if override is set, what value should be driven onto qspi cache DS pin?
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__SHIFT            4
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__WIDTH            1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__MASK   0x00000010U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_ds */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_ds_field override_qspicache_ds_field
 * @brief macros for field override_qspicache_ds
 * @details if set, software now has direct control of the qspi cache DS pin
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__SHIFT                5
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__WIDTH                1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__MASK       0x00000020U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_DS__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_ls_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_ls_val_field override_qspicache_ls_val_field
 * @brief macros for field override_qspicache_ls_val
 * @details if override is set, what value should be driven onto qspi cache LS pin?
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__SHIFT            6
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__WIDTH            1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__MASK   0x00000040U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_ls */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_ls_field override_qspicache_ls_field
 * @brief macros for field override_qspicache_ls
 * @details if set, software now has direct control of the qspi cache LS pin
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__SHIFT                7
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__WIDTH                1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__MASK       0x00000080U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_LS__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_iso_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_iso_val_field override_qspicache_iso_val_field
 * @brief macros for field override_qspicache_iso_val
 * @details if override is set, what value should be driven onto qspi cache ISO pin?
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__SHIFT           8
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__WIDTH           1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__MASK  0x00000100U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_iso_field override_qspicache_iso_field
 * @brief macros for field override_qspicache_iso
 * @details if set, software now has direct control of the qspi cache ISO pin
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__SHIFT               9
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__WIDTH               1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__MASK      0x00000200U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_ISO__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_clken_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_clken_val_field override_qspicache_clken_val_field
 * @brief macros for field override_qspicache_clken_val
 * @details if override is set, should the clock gate on the qspi cache be enabled?  1=clock running  0=clock gated off
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__SHIFT        10
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__WIDTH         1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__MASK \
                    0x00000400U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_clken_field override_qspicache_clken_field
 * @brief macros for field override_qspicache_clken
 * @details if set, clock gating to qspi cache is now under software control
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__SHIFT            11
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__WIDTH             1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__MASK    0x00000800U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_CLKEN__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_vddcut_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_vddcut_val_field override_qspicache_vddcut_val_field
 * @brief macros for field override_qspicache_vddcut_val
 * @details if override is set, should head switch on qspi cache be open or close?  1=open  0=close
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__SHIFT       12
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__WIDTH        1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__MASK \
                    0x00001000U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT_VAL__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field override_qspicache_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_override_qspicache_vddcut_field override_qspicache_vddcut_field
 * @brief macros for field override_qspicache_vddcut
 * @details if set, head switch on qspi cache is now software controllable
 * @{
 */
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__SHIFT           13
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__WIDTH            1
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__MASK   0x00002000U
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_QSPICACHE_OVERRIDES__OVERRIDE_QSPICACHE_VDDCUT__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_QSPICACHE_OVERRIDES__TYPE                                 uint32_t
#define PSEQ_QSPICACHE_OVERRIDES__READ                              0x00003fffU
#define PSEQ_QSPICACHE_OVERRIDES__WRITE                             0x00003fffU
#define PSEQ_QSPICACHE_OVERRIDES__PRESERVED                         0x00000000U
#define PSEQ_QSPICACHE_OVERRIDES__RESET_VALUE                       0x00000000U

#endif /* __PSEQ_QSPICACHE_OVERRIDES_MACRO__ */

/** @} end of qspicache_overrides */

/* macros for BlueprintGlobalNameSpace::PSEQ_counter_control */
/**
 * @defgroup at_apb_pseq_perth_regs_core_counter_control counter_control
 * @brief control signals for counters definitions.
 * @{
 */
#ifndef __PSEQ_COUNTER_CONTROL_MACRO__
#define __PSEQ_COUNTER_CONTROL_MACRO__

/* macros for field halt_real_time_counter */
/**
 * @defgroup at_apb_pseq_perth_regs_core_halt_real_time_counter_field halt_real_time_counter_field
 * @brief macros for field halt_real_time_counter
 * @details stop the real time counter from advancing
 * @{
 */
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__SHIFT                   0
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__WIDTH                   1
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__MASK          0x00000001U
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_COUNTER_CONTROL__HALT_REAL_TIME_COUNTER__RESET_VALUE   0x00000000U
/** @} */

/* macros for field load_count_down_timer */
/**
 * @defgroup at_apb_pseq_perth_regs_core_load_count_down_timer_field load_count_down_timer_field
 * @brief macros for field load_count_down_timer
 * @details loads on positive edge; hardware doesn't reset this bit (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__SHIFT                    1
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__WIDTH                    1
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__MASK           0x00000002U
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_COUNTER_CONTROL__LOAD_COUNT_DOWN_TIMER__RESET_VALUE    0x00000000U
/** @} */

/* macros for field frc_match1_cntr_force_reset */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_cntr_force_reset_field frc_match1_cntr_force_reset_field
 * @brief macros for field frc_match1_cntr_force_reset
 * @details forcing reset in frc matching counter 1. not self clearing
 * @{
 */
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__SHIFT              2
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__WIDTH              1
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__MASK     0x00000004U
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH1_CNTR_FORCE_RESET__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field frc_match0_cntr_force_reset */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_cntr_force_reset_field frc_match0_cntr_force_reset_field
 * @brief macros for field frc_match0_cntr_force_reset
 * @details forcing reset in frc matching counter 0. not self clearing
 * @{
 */
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__SHIFT              3
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__WIDTH              1
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__MASK     0x00000008U
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_COUNTER_CONTROL__FRC_MATCH0_CNTR_FORCE_RESET__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_COUNTER_CONTROL__TYPE                                     uint32_t
#define PSEQ_COUNTER_CONTROL__READ                                  0x0000000fU
#define PSEQ_COUNTER_CONTROL__WRITE                                 0x0000000fU
#define PSEQ_COUNTER_CONTROL__PRESERVED                             0x00000000U
#define PSEQ_COUNTER_CONTROL__RESET_VALUE                           0x00000000U

#endif /* __PSEQ_COUNTER_CONTROL_MACRO__ */

/** @} end of counter_control */

/* macros for BlueprintGlobalNameSpace::PSEQ_current_real_time */
/**
 * @defgroup at_apb_pseq_perth_regs_core_current_real_time current_real_time
 * @brief counter value definitions.
 * @{
 */
#ifndef __PSEQ_CURRENT_REAL_TIME_MACRO__
#define __PSEQ_CURRENT_REAL_TIME_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_val_field val_field
 * @brief macros for field val
 * @details real time in clk_lpc clock cycles
 * @{
 */
#define PSEQ_CURRENT_REAL_TIME__VAL__SHIFT                                    0
#define PSEQ_CURRENT_REAL_TIME__VAL__WIDTH                                   32
#define PSEQ_CURRENT_REAL_TIME__VAL__MASK                           0xffffffffU
#define PSEQ_CURRENT_REAL_TIME__VAL__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_CURRENT_REAL_TIME__VAL__RESET_VALUE                    0x00000000U
/** @} */
#define PSEQ_CURRENT_REAL_TIME__TYPE                                   uint32_t
#define PSEQ_CURRENT_REAL_TIME__READ                                0xffffffffU
#define PSEQ_CURRENT_REAL_TIME__PRESERVED                           0x00000000U
#define PSEQ_CURRENT_REAL_TIME__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_CURRENT_REAL_TIME_MACRO__ */

/** @} end of current_real_time */

/* macros for BlueprintGlobalNameSpace::PSEQ_current_count_down_time */
/**
 * @defgroup at_apb_pseq_perth_regs_core_current_count_down_time current_count_down_time
 * @brief counter value definitions.
 * @{
 */
#ifndef __PSEQ_CURRENT_COUNT_DOWN_TIME_MACRO__
#define __PSEQ_CURRENT_COUNT_DOWN_TIME_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_val_field val_field
 * @brief macros for field val
 * @details this value is on 32kHz domain; read twice and check value is the same; if it's not, reread
 * @{
 */
#define PSEQ_CURRENT_COUNT_DOWN_TIME__VAL__SHIFT                              0
#define PSEQ_CURRENT_COUNT_DOWN_TIME__VAL__WIDTH                             32
#define PSEQ_CURRENT_COUNT_DOWN_TIME__VAL__MASK                     0xffffffffU
#define PSEQ_CURRENT_COUNT_DOWN_TIME__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_CURRENT_COUNT_DOWN_TIME__VAL__RESET_VALUE              0x00000000U
/** @} */
#define PSEQ_CURRENT_COUNT_DOWN_TIME__TYPE                             uint32_t
#define PSEQ_CURRENT_COUNT_DOWN_TIME__READ                          0xffffffffU
#define PSEQ_CURRENT_COUNT_DOWN_TIME__PRESERVED                     0x00000000U
#define PSEQ_CURRENT_COUNT_DOWN_TIME__RESET_VALUE                   0x00000000U

#endif /* __PSEQ_CURRENT_COUNT_DOWN_TIME_MACRO__ */

/** @} end of current_count_down_time */

/* macros for BlueprintGlobalNameSpace::PSEQ_init_count_down */
/**
 * @defgroup at_apb_pseq_perth_regs_core_init_count_down init_count_down
 * @brief counter value definitions.
 * @{
 */
#ifndef __PSEQ_INIT_COUNT_DOWN_MACRO__
#define __PSEQ_INIT_COUNT_DOWN_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_val_field val_field
 * @brief macros for field val
 * @details initial value for count down timer
 * @{
 */
#define PSEQ_INIT_COUNT_DOWN__VAL__SHIFT                                      0
#define PSEQ_INIT_COUNT_DOWN__VAL__WIDTH                                     32
#define PSEQ_INIT_COUNT_DOWN__VAL__MASK                             0xffffffffU
#define PSEQ_INIT_COUNT_DOWN__VAL__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_INIT_COUNT_DOWN__VAL__WRITE(src)   ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_INIT_COUNT_DOWN__VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_INIT_COUNT_DOWN__VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_INIT_COUNT_DOWN__VAL__RESET_VALUE                      0x00000fffU
/** @} */
#define PSEQ_INIT_COUNT_DOWN__TYPE                                     uint32_t
#define PSEQ_INIT_COUNT_DOWN__READ                                  0xffffffffU
#define PSEQ_INIT_COUNT_DOWN__WRITE                                 0xffffffffU
#define PSEQ_INIT_COUNT_DOWN__PRESERVED                             0x00000000U
#define PSEQ_INIT_COUNT_DOWN__RESET_VALUE                           0x00000fffU

#endif /* __PSEQ_INIT_COUNT_DOWN_MACRO__ */

/** @} end of init_count_down */

/* macros for BlueprintGlobalNameSpace::PSEQ_counter_control_1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_counter_control_1 counter_control_1
 * @brief control signals for counters definitions.
 * @{
 */
#ifndef __PSEQ_COUNTER_CONTROL_1_MACRO__
#define __PSEQ_COUNTER_CONTROL_1_MACRO__

/* macros for field load_count_down_timer */
/**
 * @defgroup at_apb_pseq_perth_regs_core_load_count_down_timer_field load_count_down_timer_field
 * @brief macros for field load_count_down_timer
 * @details loads on positive edge; hardware doesn't reset this bit (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__SHIFT                  1
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__WIDTH                  1
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__MASK         0x00000002U
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_COUNTER_CONTROL_1__LOAD_COUNT_DOWN_TIMER__RESET_VALUE  0x00000000U
/** @} */
#define PSEQ_COUNTER_CONTROL_1__TYPE                                   uint32_t
#define PSEQ_COUNTER_CONTROL_1__READ                                0x00000002U
#define PSEQ_COUNTER_CONTROL_1__WRITE                               0x00000002U
#define PSEQ_COUNTER_CONTROL_1__PRESERVED                           0x00000000U
#define PSEQ_COUNTER_CONTROL_1__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_COUNTER_CONTROL_1_MACRO__ */

/** @} end of counter_control_1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_current_count_down_time_1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_current_count_down_time_1 current_count_down_time_1
 * @brief counter value definitions.
 * @{
 */
#ifndef __PSEQ_CURRENT_COUNT_DOWN_TIME_1_MACRO__
#define __PSEQ_CURRENT_COUNT_DOWN_TIME_1_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_val_field val_field
 * @brief macros for field val
 * @details this value is on 32kHz domain; read twice and check value is the same; if it's not, reread
 * @{
 */
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__VAL__SHIFT                            0
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__VAL__WIDTH                           32
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__VAL__MASK                   0xffffffffU
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__VAL__RESET_VALUE            0x00000000U
/** @} */
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__TYPE                           uint32_t
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__READ                        0xffffffffU
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__PRESERVED                   0x00000000U
#define PSEQ_CURRENT_COUNT_DOWN_TIME_1__RESET_VALUE                 0x00000000U

#endif /* __PSEQ_CURRENT_COUNT_DOWN_TIME_1_MACRO__ */

/** @} end of current_count_down_time_1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_init_count_down_1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_init_count_down_1 init_count_down_1
 * @brief counter value definitions.
 * @{
 */
#ifndef __PSEQ_INIT_COUNT_DOWN_1_MACRO__
#define __PSEQ_INIT_COUNT_DOWN_1_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_val_field val_field
 * @brief macros for field val
 * @details initial value for count down timer
 * @{
 */
#define PSEQ_INIT_COUNT_DOWN_1__VAL__SHIFT                                    0
#define PSEQ_INIT_COUNT_DOWN_1__VAL__WIDTH                                   32
#define PSEQ_INIT_COUNT_DOWN_1__VAL__MASK                           0xffffffffU
#define PSEQ_INIT_COUNT_DOWN_1__VAL__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_INIT_COUNT_DOWN_1__VAL__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_INIT_COUNT_DOWN_1__VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_INIT_COUNT_DOWN_1__VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_INIT_COUNT_DOWN_1__VAL__RESET_VALUE                    0x00000fffU
/** @} */
#define PSEQ_INIT_COUNT_DOWN_1__TYPE                                   uint32_t
#define PSEQ_INIT_COUNT_DOWN_1__READ                                0xffffffffU
#define PSEQ_INIT_COUNT_DOWN_1__WRITE                               0xffffffffU
#define PSEQ_INIT_COUNT_DOWN_1__PRESERVED                           0x00000000U
#define PSEQ_INIT_COUNT_DOWN_1__RESET_VALUE                         0x00000fffU

#endif /* __PSEQ_INIT_COUNT_DOWN_1_MACRO__ */

/** @} end of init_count_down_1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_frc_match0_ctrl */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_ctrl frc_match0_ctrl
 * @brief Contains register fields associated with frc_match0_ctrl. definitions.
 * @{
 */
#ifndef __PSEQ_FRC_MATCH0_CTRL_MACRO__
#define __PSEQ_FRC_MATCH0_CTRL_MACRO__

/* macros for field frc_match0_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_val_field frc_match0_val_field
 * @brief macros for field frc_match0_val
 * @details value to match real timer.
 * @{
 */
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__SHIFT                           0
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__WIDTH                          32
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__MASK                  0xffffffffU
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_FRC_MATCH0_CTRL__FRC_MATCH0_VAL__RESET_VALUE           0x00000000U
/** @} */
#define PSEQ_FRC_MATCH0_CTRL__TYPE                                     uint32_t
#define PSEQ_FRC_MATCH0_CTRL__READ                                  0xffffffffU
#define PSEQ_FRC_MATCH0_CTRL__WRITE                                 0xffffffffU
#define PSEQ_FRC_MATCH0_CTRL__PRESERVED                             0x00000000U
#define PSEQ_FRC_MATCH0_CTRL__RESET_VALUE                           0x00000000U

#endif /* __PSEQ_FRC_MATCH0_CTRL_MACRO__ */

/** @} end of frc_match0_ctrl */

/* macros for BlueprintGlobalNameSpace::PSEQ_frc_match1_ctrl */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_ctrl frc_match1_ctrl
 * @brief Contains register fields associated with frc_match1_ctrl. definitions.
 * @{
 */
#ifndef __PSEQ_FRC_MATCH1_CTRL_MACRO__
#define __PSEQ_FRC_MATCH1_CTRL_MACRO__

/* macros for field frc_match1_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_val_field frc_match1_val_field
 * @brief macros for field frc_match1_val
 * @details value to match real timer.
 * @{
 */
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__SHIFT                           0
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__WIDTH                          32
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__MASK                  0xffffffffU
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_FRC_MATCH1_CTRL__FRC_MATCH1_VAL__RESET_VALUE           0x00000000U
/** @} */
#define PSEQ_FRC_MATCH1_CTRL__TYPE                                     uint32_t
#define PSEQ_FRC_MATCH1_CTRL__READ                                  0xffffffffU
#define PSEQ_FRC_MATCH1_CTRL__WRITE                                 0xffffffffU
#define PSEQ_FRC_MATCH1_CTRL__PRESERVED                             0x00000000U
#define PSEQ_FRC_MATCH1_CTRL__RESET_VALUE                           0x00000000U

#endif /* __PSEQ_FRC_MATCH1_CTRL_MACRO__ */

/** @} end of frc_match1_ctrl */

/* macros for BlueprintGlobalNameSpace::PSEQ_inst_pending */
/**
 * @defgroup at_apb_pseq_perth_regs_core_inst_pending inst_pending
 * @brief instructions from clk_mpc to clk_lpc still pending definitions.
 * @{
 */
#ifndef __PSEQ_INST_PENDING_MACRO__
#define __PSEQ_INST_PENDING_MACRO__

/* macros for field wdog_timer_disable */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wdog_timer_disable_field wdog_timer_disable_field
 * @brief macros for field wdog_timer_disable
 * @details disable/enable of watchdog timer is still pending
 * @{
 */
#define PSEQ_INST_PENDING__WDOG_TIMER_DISABLE__SHIFT                          0
#define PSEQ_INST_PENDING__WDOG_TIMER_DISABLE__WIDTH                          1
#define PSEQ_INST_PENDING__WDOG_TIMER_DISABLE__MASK                 0x00000001U
#define PSEQ_INST_PENDING__WDOG_TIMER_DISABLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_INST_PENDING__WDOG_TIMER_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_INST_PENDING__WDOG_TIMER_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_INST_PENDING__WDOG_TIMER_DISABLE__RESET_VALUE          0x00000000U
/** @} */

/* macros for field cntdwn_timer_load */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cntdwn_timer_load_field cntdwn_timer_load_field
 * @brief macros for field cntdwn_timer_load
 * @details load of count down timer is still pending
 * @{
 */
#define PSEQ_INST_PENDING__CNTDWN_TIMER_LOAD__SHIFT                          16
#define PSEQ_INST_PENDING__CNTDWN_TIMER_LOAD__WIDTH                           1
#define PSEQ_INST_PENDING__CNTDWN_TIMER_LOAD__MASK                  0x00010000U
#define PSEQ_INST_PENDING__CNTDWN_TIMER_LOAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_INST_PENDING__CNTDWN_TIMER_LOAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_INST_PENDING__CNTDWN_TIMER_LOAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_INST_PENDING__CNTDWN_TIMER_LOAD__RESET_VALUE           0x00000000U
/** @} */

/* macros for field cntdwn_timer_1_load */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cntdwn_timer_1_load_field cntdwn_timer_1_load_field
 * @brief macros for field cntdwn_timer_1_load
 * @details load of count down timer is still pending
 * @{
 */
#define PSEQ_INST_PENDING__CNTDWN_TIMER_1_LOAD__SHIFT                        17
#define PSEQ_INST_PENDING__CNTDWN_TIMER_1_LOAD__WIDTH                         1
#define PSEQ_INST_PENDING__CNTDWN_TIMER_1_LOAD__MASK                0x00020000U
#define PSEQ_INST_PENDING__CNTDWN_TIMER_1_LOAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_INST_PENDING__CNTDWN_TIMER_1_LOAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_INST_PENDING__CNTDWN_TIMER_1_LOAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_INST_PENDING__CNTDWN_TIMER_1_LOAD__RESET_VALUE         0x00000000U
/** @} */
#define PSEQ_INST_PENDING__TYPE                                        uint32_t
#define PSEQ_INST_PENDING__READ                                     0x00030001U
#define PSEQ_INST_PENDING__PRESERVED                                0x00000000U
#define PSEQ_INST_PENDING__RESET_VALUE                              0x00000000U

#endif /* __PSEQ_INST_PENDING_MACRO__ */

/** @} end of inst_pending */

/* macros for BlueprintGlobalNameSpace::PSEQ_status */
/**
 * @defgroup at_apb_pseq_perth_regs_core_status status
 * @brief status signals definitions.
 * @{
 */
#ifndef __PSEQ_STATUS_MACRO__
#define __PSEQ_STATUS_MACRO__

/* macros for field in_active_state */
/**
 * @defgroup at_apb_pseq_perth_regs_core_in_active_state_field in_active_state_field
 * @brief macros for field in_active_state
 * @details pseq is currently in active state
 * @{
 */
#define PSEQ_STATUS__IN_ACTIVE_STATE__SHIFT                                   0
#define PSEQ_STATUS__IN_ACTIVE_STATE__WIDTH                                   1
#define PSEQ_STATUS__IN_ACTIVE_STATE__MASK                          0x00000001U
#define PSEQ_STATUS__IN_ACTIVE_STATE__READ(src) ((uint32_t)(src) & 0x00000001U)
#define PSEQ_STATUS__IN_ACTIVE_STATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_STATUS__IN_ACTIVE_STATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_STATUS__IN_ACTIVE_STATE__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field in_cpu_active_state */
/**
 * @defgroup at_apb_pseq_perth_regs_core_in_cpu_active_state_field in_cpu_active_state_field
 * @brief macros for field in_cpu_active_state
 * @details pseq is currently in cpu active state
 * @{
 */
#define PSEQ_STATUS__IN_CPU_ACTIVE_STATE__SHIFT                               1
#define PSEQ_STATUS__IN_CPU_ACTIVE_STATE__WIDTH                               1
#define PSEQ_STATUS__IN_CPU_ACTIVE_STATE__MASK                      0x00000002U
#define PSEQ_STATUS__IN_CPU_ACTIVE_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_STATUS__IN_CPU_ACTIVE_STATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_STATUS__IN_CPU_ACTIVE_STATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_STATUS__IN_CPU_ACTIVE_STATE__RESET_VALUE               0x00000000U
/** @} */

/* macros for field in_hibernate_state */
/**
 * @defgroup at_apb_pseq_perth_regs_core_in_hibernate_state_field in_hibernate_state_field
 * @brief macros for field in_hibernate_state
 * @details pseq is currently in hibernate state
 * @{
 */
#define PSEQ_STATUS__IN_HIBERNATE_STATE__SHIFT                                2
#define PSEQ_STATUS__IN_HIBERNATE_STATE__WIDTH                                1
#define PSEQ_STATUS__IN_HIBERNATE_STATE__MASK                       0x00000004U
#define PSEQ_STATUS__IN_HIBERNATE_STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_STATUS__IN_HIBERNATE_STATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_STATUS__IN_HIBERNATE_STATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_STATUS__IN_HIBERNATE_STATE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field timer_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_timer_triggered_field timer_triggered_field
 * @brief macros for field timer_triggered
 * @details wake triggered by count down timer
 * @{
 */
#define PSEQ_STATUS__TIMER_TRIGGERED__SHIFT                                   8
#define PSEQ_STATUS__TIMER_TRIGGERED__WIDTH                                   1
#define PSEQ_STATUS__TIMER_TRIGGERED__MASK                          0x00000100U
#define PSEQ_STATUS__TIMER_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_STATUS__TIMER_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_STATUS__TIMER_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_STATUS__TIMER_TRIGGERED__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field gpio_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_gpio_triggered_field gpio_triggered_field
 * @brief macros for field gpio_triggered
 * @details wake triggered by gpio
 * @{
 */
#define PSEQ_STATUS__GPIO_TRIGGERED__SHIFT                                    9
#define PSEQ_STATUS__GPIO_TRIGGERED__WIDTH                                    1
#define PSEQ_STATUS__GPIO_TRIGGERED__MASK                           0x00000200U
#define PSEQ_STATUS__GPIO_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_STATUS__GPIO_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_STATUS__GPIO_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_STATUS__GPIO_TRIGGERED__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field wurx0_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx0_triggered_field wurx0_triggered_field
 * @brief macros for field wurx0_triggered
 * @details wake triggered by wurx0
 * @{
 */
#define PSEQ_STATUS__WURX0_TRIGGERED__SHIFT                                  10
#define PSEQ_STATUS__WURX0_TRIGGERED__WIDTH                                   1
#define PSEQ_STATUS__WURX0_TRIGGERED__MASK                          0x00000400U
#define PSEQ_STATUS__WURX0_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_STATUS__WURX0_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_STATUS__WURX0_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_STATUS__WURX0_TRIGGERED__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field wurx1_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx1_triggered_field wurx1_triggered_field
 * @brief macros for field wurx1_triggered
 * @details wake triggered by wurx1
 * @{
 */
#define PSEQ_STATUS__WURX1_TRIGGERED__SHIFT                                  11
#define PSEQ_STATUS__WURX1_TRIGGERED__WIDTH                                   1
#define PSEQ_STATUS__WURX1_TRIGGERED__MASK                          0x00000800U
#define PSEQ_STATUS__WURX1_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_STATUS__WURX1_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_STATUS__WURX1_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_STATUS__WURX1_TRIGGERED__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field qdec_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_qdec_triggered_field qdec_triggered_field
 * @brief macros for field qdec_triggered
 * @details wake triggered by qdec activity
 * @{
 */
#define PSEQ_STATUS__QDEC_TRIGGERED__SHIFT                                   12
#define PSEQ_STATUS__QDEC_TRIGGERED__WIDTH                                    1
#define PSEQ_STATUS__QDEC_TRIGGERED__MASK                           0x00001000U
#define PSEQ_STATUS__QDEC_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_STATUS__QDEC_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_STATUS__QDEC_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_STATUS__QDEC_TRIGGERED__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ksm_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ksm_triggered_field ksm_triggered_field
 * @brief macros for field ksm_triggered
 * @details wake triggered by ksm activity
 * @{
 */
#define PSEQ_STATUS__KSM_TRIGGERED__SHIFT                                    13
#define PSEQ_STATUS__KSM_TRIGGERED__WIDTH                                     1
#define PSEQ_STATUS__KSM_TRIGGERED__MASK                            0x00002000U
#define PSEQ_STATUS__KSM_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_STATUS__KSM_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_STATUS__KSM_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_STATUS__KSM_TRIGGERED__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field dbg_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_dbg_triggered_field dbg_triggered_field
 * @brief macros for field dbg_triggered
 * @details wake triggered by debugger
 * @{
 */
#define PSEQ_STATUS__DBG_TRIGGERED__SHIFT                                    14
#define PSEQ_STATUS__DBG_TRIGGERED__WIDTH                                     1
#define PSEQ_STATUS__DBG_TRIGGERED__MASK                            0x00004000U
#define PSEQ_STATUS__DBG_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_STATUS__DBG_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_STATUS__DBG_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_STATUS__DBG_TRIGGERED__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field shub_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_triggered_field shub_triggered_field
 * @brief macros for field shub_triggered
 * @details wake triggered by sensor hub
 * @{
 */
#define PSEQ_STATUS__SHUB_TRIGGERED__SHIFT                                   15
#define PSEQ_STATUS__SHUB_TRIGGERED__WIDTH                                    1
#define PSEQ_STATUS__SHUB_TRIGGERED__MASK                           0x00008000U
#define PSEQ_STATUS__SHUB_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_STATUS__SHUB_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_STATUS__SHUB_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_STATUS__SHUB_TRIGGERED__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field spi_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_spi_triggered_field spi_triggered_field
 * @brief macros for field spi_triggered
 * @details wake triggered by spi slave activity
 * @{
 */
#define PSEQ_STATUS__SPI_TRIGGERED__SHIFT                                    16
#define PSEQ_STATUS__SPI_TRIGGERED__WIDTH                                     1
#define PSEQ_STATUS__SPI_TRIGGERED__MASK                            0x00010000U
#define PSEQ_STATUS__SPI_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_STATUS__SPI_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_STATUS__SPI_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_STATUS__SPI_TRIGGERED__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field i2c_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_i2c_triggered_field i2c_triggered_field
 * @brief macros for field i2c_triggered
 * @details wake triggered by i2c slave activity
 * @{
 */
#define PSEQ_STATUS__I2C_TRIGGERED__SHIFT                                    17
#define PSEQ_STATUS__I2C_TRIGGERED__WIDTH                                     1
#define PSEQ_STATUS__I2C_TRIGGERED__MASK                            0x00020000U
#define PSEQ_STATUS__I2C_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_STATUS__I2C_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_STATUS__I2C_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_STATUS__I2C_TRIGGERED__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field pmu_timer_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_timer_triggered_field pmu_timer_triggered_field
 * @brief macros for field pmu_timer_triggered
 * @details wake triggered by pmu timer expiring
 * @{
 */
#define PSEQ_STATUS__PMU_TIMER_TRIGGERED__SHIFT                              18
#define PSEQ_STATUS__PMU_TIMER_TRIGGERED__WIDTH                               1
#define PSEQ_STATUS__PMU_TIMER_TRIGGERED__MASK                      0x00040000U
#define PSEQ_STATUS__PMU_TIMER_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_STATUS__PMU_TIMER_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_STATUS__PMU_TIMER_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_STATUS__PMU_TIMER_TRIGGERED__RESET_VALUE               0x00000000U
/** @} */

/* macros for field pmu_lpcomp_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_lpcomp_triggered_field pmu_lpcomp_triggered_field
 * @brief macros for field pmu_lpcomp_triggered
 * @details wake triggered by pmu lpcomp threshold crossing
 * @{
 */
#define PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__SHIFT                             19
#define PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__WIDTH                              1
#define PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__MASK                     0x00080000U
#define PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__RESET_VALUE              0x00000000U
/** @} */

/* macros for field energy4CPU_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4CPU_triggered_field energy4CPU_triggered_field
 * @brief macros for field energy4CPU_triggered
 * @details wake triggered by pmu energy4CPU
 * @{
 */
#define PSEQ_STATUS__ENERGY4CPU_TRIGGERED__SHIFT                             20
#define PSEQ_STATUS__ENERGY4CPU_TRIGGERED__WIDTH                              1
#define PSEQ_STATUS__ENERGY4CPU_TRIGGERED__MASK                     0x00100000U
#define PSEQ_STATUS__ENERGY4CPU_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PSEQ_STATUS__ENERGY4CPU_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PSEQ_STATUS__ENERGY4CPU_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PSEQ_STATUS__ENERGY4CPU_TRIGGERED__RESET_VALUE              0x00000000U
/** @} */

/* macros for field energy4TX_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4TX_triggered_field energy4TX_triggered_field
 * @brief macros for field energy4TX_triggered
 * @details wake triggered by pmu energy4TX
 * @{
 */
#define PSEQ_STATUS__ENERGY4TX_TRIGGERED__SHIFT                              21
#define PSEQ_STATUS__ENERGY4TX_TRIGGERED__WIDTH                               1
#define PSEQ_STATUS__ENERGY4TX_TRIGGERED__MASK                      0x00200000U
#define PSEQ_STATUS__ENERGY4TX_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PSEQ_STATUS__ENERGY4TX_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PSEQ_STATUS__ENERGY4TX_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PSEQ_STATUS__ENERGY4TX_TRIGGERED__RESET_VALUE               0x00000000U
/** @} */

/* macros for field endoflife_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_endoflife_triggered_field endoflife_triggered_field
 * @brief macros for field endoflife_triggered
 * @details wake triggered by pmu endoflife
 * @{
 */
#define PSEQ_STATUS__ENDOFLIFE_TRIGGERED__SHIFT                              22
#define PSEQ_STATUS__ENDOFLIFE_TRIGGERED__WIDTH                               1
#define PSEQ_STATUS__ENDOFLIFE_TRIGGERED__MASK                      0x00400000U
#define PSEQ_STATUS__ENDOFLIFE_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PSEQ_STATUS__ENDOFLIFE_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PSEQ_STATUS__ENDOFLIFE_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PSEQ_STATUS__ENDOFLIFE_TRIGGERED__RESET_VALUE               0x00000000U
/** @} */

/* macros for field brownout_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_brownout_triggered_field brownout_triggered_field
 * @brief macros for field brownout_triggered
 * @details wake triggered by pmu brownout
 * @{
 */
#define PSEQ_STATUS__BROWNOUT_TRIGGERED__SHIFT                               23
#define PSEQ_STATUS__BROWNOUT_TRIGGERED__WIDTH                                1
#define PSEQ_STATUS__BROWNOUT_TRIGGERED__MASK                       0x00800000U
#define PSEQ_STATUS__BROWNOUT_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PSEQ_STATUS__BROWNOUT_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PSEQ_STATUS__BROWNOUT_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PSEQ_STATUS__BROWNOUT_TRIGGERED__RESET_VALUE                0x00000000U
/** @} */

/* macros for field wurx_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wurx_triggered_field wurx_triggered_field
 * @brief macros for field wurx_triggered
 * @details wake triggered by multiple events of wurx.
 * @{
 */
#define PSEQ_STATUS__WURX_TRIGGERED__SHIFT                                   24
#define PSEQ_STATUS__WURX_TRIGGERED__WIDTH                                    1
#define PSEQ_STATUS__WURX_TRIGGERED__MASK                           0x01000000U
#define PSEQ_STATUS__WURX_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PSEQ_STATUS__WURX_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PSEQ_STATUS__WURX_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PSEQ_STATUS__WURX_TRIGGERED__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field ble_osc_on_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ble_osc_on_triggered_field ble_osc_on_triggered_field
 * @brief macros for field ble_osc_on_triggered
 * @details wake triggered by ble_osc_on
 * @{
 */
#define PSEQ_STATUS__BLE_OSC_ON_TRIGGERED__SHIFT                             25
#define PSEQ_STATUS__BLE_OSC_ON_TRIGGERED__WIDTH                              1
#define PSEQ_STATUS__BLE_OSC_ON_TRIGGERED__MASK                     0x02000000U
#define PSEQ_STATUS__BLE_OSC_ON_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PSEQ_STATUS__BLE_OSC_ON_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PSEQ_STATUS__BLE_OSC_ON_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PSEQ_STATUS__BLE_OSC_ON_TRIGGERED__RESET_VALUE              0x00000000U
/** @} */

/* macros for field frc_match0_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_triggered_field frc_match0_triggered_field
 * @brief macros for field frc_match0_triggered
 * @details wake triggered by frc_match0
 * @{
 */
#define PSEQ_STATUS__FRC_MATCH0_TRIGGERED__SHIFT                             26
#define PSEQ_STATUS__FRC_MATCH0_TRIGGERED__WIDTH                              1
#define PSEQ_STATUS__FRC_MATCH0_TRIGGERED__MASK                     0x04000000U
#define PSEQ_STATUS__FRC_MATCH0_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PSEQ_STATUS__FRC_MATCH0_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PSEQ_STATUS__FRC_MATCH0_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PSEQ_STATUS__FRC_MATCH0_TRIGGERED__RESET_VALUE              0x00000000U
/** @} */

/* macros for field frc_match1_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_triggered_field frc_match1_triggered_field
 * @brief macros for field frc_match1_triggered
 * @details wake triggered by frc_match1
 * @{
 */
#define PSEQ_STATUS__FRC_MATCH1_TRIGGERED__SHIFT                             27
#define PSEQ_STATUS__FRC_MATCH1_TRIGGERED__WIDTH                              1
#define PSEQ_STATUS__FRC_MATCH1_TRIGGERED__MASK                     0x08000000U
#define PSEQ_STATUS__FRC_MATCH1_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PSEQ_STATUS__FRC_MATCH1_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PSEQ_STATUS__FRC_MATCH1_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PSEQ_STATUS__FRC_MATCH1_TRIGGERED__RESET_VALUE              0x00000000U
/** @} */

/* macros for field pmu_wdog_warn_triggered */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_wdog_warn_triggered_field pmu_wdog_warn_triggered_field
 * @brief macros for field pmu_wdog_warn_triggered
 * @{
 */
#define PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__SHIFT                          28
#define PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__WIDTH                           1
#define PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__MASK                  0x10000000U
#define PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__RESET_VALUE           0x00000000U
/** @} */

/* macros for field cdbgpwrupack */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cdbgpwrupack_field cdbgpwrupack_field
 * @brief macros for field cdbgpwrupack
 * @details debugger request status
 * @{
 */
#define PSEQ_STATUS__CDBGPWRUPACK__SHIFT                                     31
#define PSEQ_STATUS__CDBGPWRUPACK__WIDTH                                      1
#define PSEQ_STATUS__CDBGPWRUPACK__MASK                             0x80000000U
#define PSEQ_STATUS__CDBGPWRUPACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PSEQ_STATUS__CDBGPWRUPACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PSEQ_STATUS__CDBGPWRUPACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PSEQ_STATUS__CDBGPWRUPACK__RESET_VALUE                      0x00000000U
/** @} */
#define PSEQ_STATUS__TYPE                                              uint32_t
#define PSEQ_STATUS__READ                                           0x9fffff07U
#define PSEQ_STATUS__PRESERVED                                      0x00000000U
#define PSEQ_STATUS__RESET_VALUE                                    0x00000000U

#endif /* __PSEQ_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent0 persistent0
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT0_MACRO__
#define __PSEQ_PERSISTENT0_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT0__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT0__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT0__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT0__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT0__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT0__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT0__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT0__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT0__TYPE                                         uint32_t
#define PSEQ_PERSISTENT0__READ                                      0xffffffffU
#define PSEQ_PERSISTENT0__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT0__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT0__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT0_MACRO__ */

/** @} end of persistent0 */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent1 persistent1
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT1_MACRO__
#define __PSEQ_PERSISTENT1_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT1__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT1__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT1__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT1__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT1__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT1__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT1__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT1__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT1__TYPE                                         uint32_t
#define PSEQ_PERSISTENT1__READ                                      0xffffffffU
#define PSEQ_PERSISTENT1__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT1__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT1__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT1_MACRO__ */

/** @} end of persistent1 */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent2 persistent2
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT2_MACRO__
#define __PSEQ_PERSISTENT2_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT2__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT2__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT2__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT2__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT2__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT2__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT2__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT2__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT2__TYPE                                         uint32_t
#define PSEQ_PERSISTENT2__READ                                      0xffffffffU
#define PSEQ_PERSISTENT2__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT2__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT2__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT2_MACRO__ */

/** @} end of persistent2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent3 persistent3
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT3_MACRO__
#define __PSEQ_PERSISTENT3_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT3__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT3__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT3__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT3__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT3__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT3__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT3__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT3__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT3__TYPE                                         uint32_t
#define PSEQ_PERSISTENT3__READ                                      0xffffffffU
#define PSEQ_PERSISTENT3__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT3__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT3__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT3_MACRO__ */

/** @} end of persistent3 */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent4 persistent4
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT4_MACRO__
#define __PSEQ_PERSISTENT4_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT4__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT4__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT4__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT4__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT4__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT4__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT4__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT4__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT4__TYPE                                         uint32_t
#define PSEQ_PERSISTENT4__READ                                      0xffffffffU
#define PSEQ_PERSISTENT4__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT4__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT4__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT4_MACRO__ */

/** @} end of persistent4 */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent5 persistent5
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT5_MACRO__
#define __PSEQ_PERSISTENT5_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT5__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT5__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT5__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT5__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT5__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT5__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT5__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT5__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT5__TYPE                                         uint32_t
#define PSEQ_PERSISTENT5__READ                                      0xffffffffU
#define PSEQ_PERSISTENT5__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT5__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT5__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT5_MACRO__ */

/** @} end of persistent5 */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent6 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent6 persistent6
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT6_MACRO__
#define __PSEQ_PERSISTENT6_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT6__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT6__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT6__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT6__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT6__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT6__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT6__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT6__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT6__TYPE                                         uint32_t
#define PSEQ_PERSISTENT6__READ                                      0xffffffffU
#define PSEQ_PERSISTENT6__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT6__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT6__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT6_MACRO__ */

/** @} end of persistent6 */

/* macros for BlueprintGlobalNameSpace::PSEQ_persistent7 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_persistent7 persistent7
 * @brief persistent scratchpad register definitions.
 * @{
 */
#ifndef __PSEQ_PERSISTENT7_MACRO__
#define __PSEQ_PERSISTENT7_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pseq_perth_regs_core_data_field data_field
 * @brief macros for field data
 * @details holds persistent state; persists through hibernation; might be of use to sw
 * @{
 */
#define PSEQ_PERSISTENT7__DATA__SHIFT                                         0
#define PSEQ_PERSISTENT7__DATA__WIDTH                                        32
#define PSEQ_PERSISTENT7__DATA__MASK                                0xffffffffU
#define PSEQ_PERSISTENT7__DATA__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT7__DATA__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_PERSISTENT7__DATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PSEQ_PERSISTENT7__DATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PSEQ_PERSISTENT7__DATA__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_PERSISTENT7__TYPE                                         uint32_t
#define PSEQ_PERSISTENT7__READ                                      0xffffffffU
#define PSEQ_PERSISTENT7__WRITE                                     0xffffffffU
#define PSEQ_PERSISTENT7__PRESERVED                                 0x00000000U
#define PSEQ_PERSISTENT7__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_PERSISTENT7_MACRO__ */

/** @} end of persistent7 */

/* macros for BlueprintGlobalNameSpace::PSEQ_sensor_hub_control */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sensor_hub_control sensor_hub_control
 * @brief control signals for sensor hub definitions.
 * @{
 */
#ifndef __PSEQ_SENSOR_HUB_CONTROL_MACRO__
#define __PSEQ_SENSOR_HUB_CONTROL_MACRO__

/* macros for field enable_func */
/**
 * @defgroup at_apb_pseq_perth_regs_core_enable_func_field enable_func_field
 * @brief macros for field enable_func
 * @details 1= sensor hub can trigger pseq out of hibernation early due to a threshold crossing event in sensor hub. 0= sensor hub cannot trigger pseq out of hibernation. This bit does not disable the trigger signal to start the sensor functionality at the onset of hibernation.
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__SHIFT                           0
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__WIDTH                           1
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__MASK                  0x00000001U
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_SENSOR_HUB_CONTROL__ENABLE_FUNC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field shub_reset */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_reset_field shub_reset_field
 * @brief macros for field shub_reset
 * @details 1= keep shub in reset state; 0= release shub from reset
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__SHIFT                            1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__WIDTH                            1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__MASK                   0x00000002U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__RESET_VALUE            0x00000001U
/** @} */

/* macros for field shub_running_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_running_val_field shub_running_val_field
 * @brief macros for field shub_running_val
 * @details value fo shub_running when override is set
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__SHIFT                      2
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__WIDTH                      1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__MASK             0x00000004U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field shub_running_ovrd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_running_ovrd_field shub_running_ovrd_field
 * @brief macros for field shub_running_ovrd
 * @details 1= override
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__SHIFT                     3
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__WIDTH                     1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__MASK            0x00000008U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RUNNING_OVRD__RESET_VALUE     0x00000000U
/** @} */

/* macros for field shub_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_clken_field shub_clken_field
 * @brief macros for field shub_clken
 * @details sensor hub clock enable  0 = clock gated off  1 = clock running
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__SHIFT                            4
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__WIDTH                            1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__MASK                   0x00000010U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__RESET_VALUE            0x00000000U
/** @} */

/* macros for field shub_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_iso_field shub_iso_field
 * @brief macros for field shub_iso
 * @details sensor hub isolation; do not assert/deassert in same cycle as shub_clken  0 = not isolated  1 = isolated
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__SHIFT                              5
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__WIDTH                              1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__MASK                     0x00000020U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__RESET_VALUE              0x00000001U
/** @} */

/* macros for field shub_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_vddcut_field shub_vddcut_field
 * @brief macros for field shub_vddcut
 * @details sensor hub head switch control  0 = head switch is closed  1 = head switch is open
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__SHIFT                           6
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__WIDTH                           1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__MASK                  0x00000040U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__RESET_VALUE           0x00000001U
/** @} */

/* macros for field shub_reset_slow */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_reset_slow_field shub_reset_slow_field
 * @brief macros for field shub_reset_slow
 * @details for 32kHz portion; 1 = keep shub in reset state; 0 = release shub from reset
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__SHIFT                       7
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__WIDTH                       1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__MASK              0x00000080U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET_SLOW__RESET_VALUE       0x00000001U
/** @} */

/* macros for field shub_clken_slow */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_clken_slow_field shub_clken_slow_field
 * @brief macros for field shub_clken_slow
 * @details for 32kHz portion; sensor hub clock enable  0 = clock off  1 = clock running
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__SHIFT                       8
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__WIDTH                       1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__MASK              0x00000100U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN_SLOW__RESET_VALUE       0x00000000U
/** @} */

/* macros for field shub_start_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_start_val_field shub_start_val_field
 * @brief macros for field shub_start_val
 * @details value fo shub_start when override is set
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__SHIFT                        9
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__WIDTH                        1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__MASK               0x00000200U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_VAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field shub_start_ovrd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_start_ovrd_field shub_start_ovrd_field
 * @brief macros for field shub_start_ovrd
 * @details 1= override
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__SHIFT                      10
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__WIDTH                       1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__MASK              0x00000400U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_OVRD__RESET_VALUE       0x00000000U
/** @} */

/* macros for field shub_breakout_imm_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_breakout_imm_en_field shub_breakout_imm_en_field
 * @brief macros for field shub_breakout_imm_en
 * @details 1= breakout sensor asap when a valid out-of-HIB event is triggered. 0= wait for sensor hub wrap-up.
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__SHIFT                 11
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__WIDTH                  1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__MASK         0x00000800U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_BREAKOUT_IMM_EN__RESET_VALUE  0x00000000U
/** @} */

/* macros for field shub_adv_enable */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_adv_enable_field shub_adv_enable_field
 * @brief macros for field shub_adv_enable
 * @details 1= enable adv along with sensor hub.
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__SHIFT                      12
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__WIDTH                       1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__MASK              0x00001000U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_ENABLE__RESET_VALUE       0x00000000U
/** @} */

/* macros for field shub_start_adv_val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_start_adv_val_field shub_start_adv_val_field
 * @brief macros for field shub_start_adv_val
 * @details value fo shub_start_adv when override is set
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__SHIFT                   13
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__WIDTH                    1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__MASK           0x00002000U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_VAL__RESET_VALUE    0x00000000U
/** @} */

/* macros for field shub_start_adv_ovrd */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_start_adv_ovrd_field shub_start_adv_ovrd_field
 * @brief macros for field shub_start_adv_ovrd
 * @details 1= override
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__SHIFT                  14
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__WIDTH                   1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__MASK          0x00004000U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_START_ADV_OVRD__RESET_VALUE   0x00000000U
/** @} */

/* macros for field shub_hib_exit_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_hib_exit_en_field shub_hib_exit_en_field
 * @brief macros for field shub_hib_exit_en
 * @details 1= exit out of hib, 0=exit out of retain.
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__SHIFT                     15
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__WIDTH                      1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__MASK             0x00008000U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_HIB_EXIT_EN__RESET_VALUE      0x00000000U
/** @} */

/* macros for field shub_adv_as_hib */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_adv_as_hib_field shub_adv_as_hib_field
 * @brief macros for field shub_adv_as_hib
 * @details 1= assert in_hibernation of pseq_fsm_status throughout, 0= assert in_active of pseq_fsm_status during the adv phase.
 * @{
 */
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__SHIFT                      16
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__WIDTH                       1
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__MASK              0x00010000U
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_SENSOR_HUB_CONTROL__SHUB_ADV_AS_HIB__RESET_VALUE       0x00000000U
/** @} */
#define PSEQ_SENSOR_HUB_CONTROL__TYPE                                  uint32_t
#define PSEQ_SENSOR_HUB_CONTROL__READ                               0x0001ffffU
#define PSEQ_SENSOR_HUB_CONTROL__WRITE                              0x0001ffffU
#define PSEQ_SENSOR_HUB_CONTROL__PRESERVED                          0x00000000U
#define PSEQ_SENSOR_HUB_CONTROL__RESET_VALUE                        0x000000e2U

#endif /* __PSEQ_SENSOR_HUB_CONTROL_MACRO__ */

/** @} end of sensor_hub_control */

/* macros for BlueprintGlobalNameSpace::PSEQ_sensor_hub_sysram */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sensor_hub_sysram sensor_hub_sysram
 * @brief control signals for sensor hub definitions.
 * @{
 */
#ifndef __PSEQ_SENSOR_HUB_SYSRAM_MACRO__
#define __PSEQ_SENSOR_HUB_SYSRAM_MACRO__

/* macros for field shub_sram0_acc_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_sram0_acc_en_field shub_sram0_acc_en_field
 * @brief macros for field shub_sram0_acc_en
 * @details 1= allow shub access to sram0's underlying blocks
 * @{
 */
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__SHIFT                      0
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__WIDTH                      4
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__MASK             0x0000000fU
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM0_ACC_EN__RESET_VALUE      0x00000000U
/** @} */

/* macros for field shub_sram1_acc_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_sram1_acc_en_field shub_sram1_acc_en_field
 * @brief macros for field shub_sram1_acc_en
 * @details 1= allow shub access to sram1's underlying blocks
 * @{
 */
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__SHIFT                      4
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__WIDTH                      4
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__MASK             0x000000f0U
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM1_ACC_EN__RESET_VALUE      0x00000000U
/** @} */

/* macros for field shub_sram2_acc_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_sram2_acc_en_field shub_sram2_acc_en_field
 * @brief macros for field shub_sram2_acc_en
 * @details 1= allow shub access to sram2's underlying blocks
 * @{
 */
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__SHIFT                      8
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__WIDTH                      4
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__MASK             0x00000f00U
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM2_ACC_EN__RESET_VALUE      0x00000000U
/** @} */

/* macros for field shub_sram3_acc_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_shub_sram3_acc_en_field shub_sram3_acc_en_field
 * @brief macros for field shub_sram3_acc_en
 * @details 1= allow shub access to sram3's underlying blocks
 * @{
 */
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__SHIFT                     12
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__WIDTH                      4
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__MASK             0x0000f000U
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define PSEQ_SENSOR_HUB_SYSRAM__SHUB_SRAM3_ACC_EN__RESET_VALUE      0x00000000U
/** @} */
#define PSEQ_SENSOR_HUB_SYSRAM__TYPE                                   uint32_t
#define PSEQ_SENSOR_HUB_SYSRAM__READ                                0x0000ffffU
#define PSEQ_SENSOR_HUB_SYSRAM__WRITE                               0x0000ffffU
#define PSEQ_SENSOR_HUB_SYSRAM__PRESERVED                           0x00000000U
#define PSEQ_SENSOR_HUB_SYSRAM__RESET_VALUE                         0x00000000U

#endif /* __PSEQ_SENSOR_HUB_SYSRAM_MACRO__ */

/** @} end of sensor_hub_sysram */

/* macros for BlueprintGlobalNameSpace::PSEQ_ksmqdec_control */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ksmqdec_control ksmqdec_control
 * @brief keyboard and mouse power domain controls definitions.
 * @{
 */
#ifndef __PSEQ_KSMQDEC_CONTROL_MACRO__
#define __PSEQ_KSMQDEC_CONTROL_MACRO__

/* macros for field ksmqdec_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ksmqdec_clken_field ksmqdec_clken_field
 * @brief macros for field ksmqdec_clken
 * @details clock enable  0 = clock gated off  1 = clock running
 * @{
 */
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__SHIFT                            0
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__WIDTH                            1
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__MASK                   0x00000001U
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_CLKEN__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ksmqdec_frst */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ksmqdec_frst_field ksmqdec_frst_field
 * @brief macros for field ksmqdec_frst
 * @details forced reset  1 = reset  0 = not reset
 * @{
 */
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__SHIFT                             1
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__WIDTH                             1
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__MASK                    0x00000002U
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_FRST__RESET_VALUE             0x00000001U
/** @} */

/* macros for field ksmqdec_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ksmqdec_iso_field ksmqdec_iso_field
 * @brief macros for field ksmqdec_iso
 * @details isolation  0 = not isolated  1 = isolated
 * @{
 */
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__SHIFT                              2
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__WIDTH                              1
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__MASK                     0x00000004U
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_ISO__RESET_VALUE              0x00000001U
/** @} */

/* macros for field ksmqdec_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_ksmqdec_vddcut_field ksmqdec_vddcut_field
 * @brief macros for field ksmqdec_vddcut
 * @details head switch control  0 = head switch is closed  1 = head switch is open
 * @{
 */
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__SHIFT                           3
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__WIDTH                           1
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__MASK                  0x00000008U
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_KSMQDEC_CONTROL__KSMQDEC_VDDCUT__RESET_VALUE           0x00000001U
/** @} */
#define PSEQ_KSMQDEC_CONTROL__TYPE                                     uint32_t
#define PSEQ_KSMQDEC_CONTROL__READ                                  0x0000000fU
#define PSEQ_KSMQDEC_CONTROL__WRITE                                 0x0000000fU
#define PSEQ_KSMQDEC_CONTROL__PRESERVED                             0x00000000U
#define PSEQ_KSMQDEC_CONTROL__RESET_VALUE                           0x0000000eU

#endif /* __PSEQ_KSMQDEC_CONTROL_MACRO__ */

/** @} end of ksmqdec_control */

/* macros for BlueprintGlobalNameSpace::PSEQ_spii2c_control */
/**
 * @defgroup at_apb_pseq_perth_regs_core_spii2c_control spii2c_control
 * @brief spi and i2c power domain controls definitions.
 * @{
 */
#ifndef __PSEQ_SPII2C_CONTROL_MACRO__
#define __PSEQ_SPII2C_CONTROL_MACRO__

/* macros for field spii2c_clken */
/**
 * @defgroup at_apb_pseq_perth_regs_core_spii2c_clken_field spii2c_clken_field
 * @brief macros for field spii2c_clken
 * @details clock enable  0 = clock gated off  1 = clock running
 * @{
 */
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__SHIFT                              0
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__WIDTH                              1
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__MASK                     0x00000001U
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_SPII2C_CONTROL__SPII2C_CLKEN__RESET_VALUE              0x00000000U
/** @} */

/* macros for field spii2c_frst */
/**
 * @defgroup at_apb_pseq_perth_regs_core_spii2c_frst_field spii2c_frst_field
 * @brief macros for field spii2c_frst
 * @details forced reset  1 = reset  0 = not reset
 * @{
 */
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__SHIFT                               1
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__WIDTH                               1
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__MASK                      0x00000002U
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_SPII2C_CONTROL__SPII2C_FRST__RESET_VALUE               0x00000001U
/** @} */

/* macros for field spii2c_iso */
/**
 * @defgroup at_apb_pseq_perth_regs_core_spii2c_iso_field spii2c_iso_field
 * @brief macros for field spii2c_iso
 * @details isolation  0 = not isolated  1 = isolated
 * @{
 */
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__SHIFT                                2
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__WIDTH                                1
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__MASK                       0x00000004U
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_SPII2C_CONTROL__SPII2C_ISO__RESET_VALUE                0x00000001U
/** @} */

/* macros for field spii2c_vddcut */
/**
 * @defgroup at_apb_pseq_perth_regs_core_spii2c_vddcut_field spii2c_vddcut_field
 * @brief macros for field spii2c_vddcut
 * @details head switch control  0 = head switch is closed  1 = head switch is open
 * @{
 */
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__SHIFT                             3
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__WIDTH                             1
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__MASK                    0x00000008U
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_SPII2C_CONTROL__SPII2C_VDDCUT__RESET_VALUE             0x00000001U
/** @} */

/* macros for field i2c0_slv_id_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_i2c0_slv_id_sel_field i2c0_slv_id_sel_field
 * @brief macros for field i2c0_slv_id_sel
 * @details select secondary i2c device id for i2c0
 * @{
 */
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__SHIFT                           4
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__WIDTH                           1
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__MASK                  0x00000010U
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_SPII2C_CONTROL__I2C0_SLV_ID_SEL__RESET_VALUE           0x00000000U
/** @} */

/* macros for field i2c1_slv_id_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_i2c1_slv_id_sel_field i2c1_slv_id_sel_field
 * @brief macros for field i2c1_slv_id_sel
 * @details select secondary i2c device id for i2c1
 * @{
 */
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__SHIFT                           5
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__WIDTH                           1
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__MASK                  0x00000020U
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_SPII2C_CONTROL__I2C1_SLV_ID_SEL__RESET_VALUE           0x00000000U
/** @} */
#define PSEQ_SPII2C_CONTROL__TYPE                                      uint32_t
#define PSEQ_SPII2C_CONTROL__READ                                   0x0000003fU
#define PSEQ_SPII2C_CONTROL__WRITE                                  0x0000003fU
#define PSEQ_SPII2C_CONTROL__PRESERVED                              0x00000000U
#define PSEQ_SPII2C_CONTROL__RESET_VALUE                            0x0000000eU

#endif /* __PSEQ_SPII2C_CONTROL_MACRO__ */

/** @} end of spii2c_control */

/* macros for BlueprintGlobalNameSpace::PSEQ_flash_control */
/**
 * @defgroup at_apb_pseq_perth_regs_core_flash_control flash_control
 * @brief low power control of external flash needs definitions.
 * @{
 */
#ifndef __PSEQ_FLASH_CONTROL_MACRO__
#define __PSEQ_FLASH_CONTROL_MACRO__

/* macros for field power_cycle_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_power_cycle_en_field power_cycle_en_field
 * @brief macros for field power_cycle_en
 * @details 1=trigger command to release flash from power down when waking up  0= no action
 * @{
 */
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__SHIFT                             0
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__WIDTH                             1
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__MASK                    0x00000001U
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_FLASH_CONTROL__POWER_CYCLE_EN__RESET_VALUE             0x00000000U
/** @} */

/* macros for field rpd_has_clock */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rpd_has_clock_field rpd_has_clock_field
 * @brief macros for field rpd_has_clock
 * @details 1=flash requires opcode to wakeup  0=flash requires only CS to wakeup
 * @{
 */
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__SHIFT                              1
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__WIDTH                              1
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__MASK                     0x00000002U
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_FLASH_CONTROL__RPD_HAS_CLOCK__RESET_VALUE              0x00000001U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pseq_perth_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details defining interface bus width of opcode; 0,3=single 1=dual 2=quad  For Macronix, set it to 0 because opcode is always serialized;  For Micron, it depends on the pre-configured interface bus width on the flash device.
 * @{
 */
#define PSEQ_FLASH_CONTROL__MODE__SHIFT                                       2
#define PSEQ_FLASH_CONTROL__MODE__WIDTH                                       2
#define PSEQ_FLASH_CONTROL__MODE__MASK                              0x0000000cU
#define PSEQ_FLASH_CONTROL__MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define PSEQ_FLASH_CONTROL__MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define PSEQ_FLASH_CONTROL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define PSEQ_FLASH_CONTROL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define PSEQ_FLASH_CONTROL__MODE__RESET_VALUE                       0x00000002U
/** @} */

/* macros for field opcode */
/**
 * @defgroup at_apb_pseq_perth_regs_core_opcode_field opcode_field
 * @brief macros for field opcode
 * @details opcode that wakes up the external flash from deep power down mode
 * @{
 */
#define PSEQ_FLASH_CONTROL__OPCODE__SHIFT                                     4
#define PSEQ_FLASH_CONTROL__OPCODE__WIDTH                                     8
#define PSEQ_FLASH_CONTROL__OPCODE__MASK                            0x00000ff0U
#define PSEQ_FLASH_CONTROL__OPCODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000ff0U) >> 4)
#define PSEQ_FLASH_CONTROL__OPCODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000ff0U)
#define PSEQ_FLASH_CONTROL__OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000ff0U) | (((uint32_t)(src) <<\
                    4) & 0x00000ff0U)
#define PSEQ_FLASH_CONTROL__OPCODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000ff0U)))
#define PSEQ_FLASH_CONTROL__OPCODE__RESET_VALUE                     0x000000abU
/** @} */

/* macros for field pd_opcode */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pd_opcode_field pd_opcode_field
 * @brief macros for field pd_opcode
 * @details opcode that puts external flash into deep power down mode
 * @{
 */
#define PSEQ_FLASH_CONTROL__PD_OPCODE__SHIFT                                 12
#define PSEQ_FLASH_CONTROL__PD_OPCODE__WIDTH                                  8
#define PSEQ_FLASH_CONTROL__PD_OPCODE__MASK                         0x000ff000U
#define PSEQ_FLASH_CONTROL__PD_OPCODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ff000U) >> 12)
#define PSEQ_FLASH_CONTROL__PD_OPCODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x000ff000U)
#define PSEQ_FLASH_CONTROL__PD_OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ff000U) | (((uint32_t)(src) <<\
                    12) & 0x000ff000U)
#define PSEQ_FLASH_CONTROL__PD_OPCODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x000ff000U)))
#define PSEQ_FLASH_CONTROL__PD_OPCODE__RESET_VALUE                  0x000000b9U
/** @} */

/* macros for field expm_opcode */
/**
 * @defgroup at_apb_pseq_perth_regs_core_expm_opcode_field expm_opcode_field
 * @brief macros for field expm_opcode
 * @details opcode that takes flash out of performance mode
 * @{
 */
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__SHIFT                               20
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__WIDTH                                8
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__MASK                       0x0ff00000U
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0ff00000U) >> 20)
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x0ff00000U)
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x0ff00000U)
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x0ff00000U)))
#define PSEQ_FLASH_CONTROL__EXPM_OPCODE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field expm_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_expm_en_field expm_en_field
 * @brief macros for field expm_en
 * @details 1=exit performance mode before issuing pd_opcode  0=not in performance mode.
 * @{
 */
#define PSEQ_FLASH_CONTROL__EXPM_EN__SHIFT                                   28
#define PSEQ_FLASH_CONTROL__EXPM_EN__WIDTH                                    1
#define PSEQ_FLASH_CONTROL__EXPM_EN__MASK                           0x10000000U
#define PSEQ_FLASH_CONTROL__EXPM_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PSEQ_FLASH_CONTROL__EXPM_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PSEQ_FLASH_CONTROL__EXPM_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PSEQ_FLASH_CONTROL__EXPM_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PSEQ_FLASH_CONTROL__EXPM_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PSEQ_FLASH_CONTROL__EXPM_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PSEQ_FLASH_CONTROL__EXPM_EN__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field pd_b4_sleep */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pd_b4_sleep_field pd_b4_sleep_field
 * @brief macros for field pd_b4_sleep
 * @details 1=issue flash deep power down prior to low power mode  0=no command issue.
 * @{
 */
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__SHIFT                               29
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__WIDTH                                1
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__MASK                       0x20000000U
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PSEQ_FLASH_CONTROL__PD_B4_SLEEP__RESET_VALUE                0x00000000U
/** @} */
#define PSEQ_FLASH_CONTROL__TYPE                                       uint32_t
#define PSEQ_FLASH_CONTROL__READ                                    0x3fffffffU
#define PSEQ_FLASH_CONTROL__WRITE                                   0x3fffffffU
#define PSEQ_FLASH_CONTROL__PRESERVED                               0x00000000U
#define PSEQ_FLASH_CONTROL__RESET_VALUE                             0x100b9abaU

#endif /* __PSEQ_FLASH_CONTROL_MACRO__ */

/** @} end of flash_control */

/* macros for BlueprintGlobalNameSpace::PSEQ_flash_control2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_flash_control2 flash_control2
 * @brief low power control of external flash needs definitions.
 * @{
 */
#ifndef __PSEQ_FLASH_CONTROL2_MACRO__
#define __PSEQ_FLASH_CONTROL2_MACRO__

/* macros for field pseq_state_match */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pseq_state_match_field pseq_state_match_field
 * @brief macros for field pseq_state_match
 * @details pseq state to trigger flash deep power down.
 * @{
 */
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__SHIFT                          0
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__WIDTH                          8
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__MASK                 0x000000ffU
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PSEQ_FLASH_CONTROL2__PSEQ_STATE_MATCH__RESET_VALUE          0x0000007fU
/** @} */

/* macros for field expm_mode */
/**
 * @defgroup at_apb_pseq_perth_regs_core_expm_mode_field expm_mode_field
 * @brief macros for field expm_mode
 * @details defining interface bus width of performance exit command; 0,3=single 1=dual 2=quad  For Macronix, set it to 2 as it's the only interface bus width equipped with performance enhancement mode  For Micron, it depends on the pre-configured interface bus width on the flash device, likely quad.
 * @{
 */
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__SHIFT                                16
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__WIDTH                                 2
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__MASK                        0x00030000U
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define PSEQ_FLASH_CONTROL2__EXPM_MODE__RESET_VALUE                 0x00000002U
/** @} */

/* macros for field enpm_clr_en */
/**
 * @defgroup at_apb_pseq_perth_regs_core_enpm_clr_en_field enpm_clr_en_field
 * @brief macros for field enpm_clr_en
 * @details 1=clears enable_performance_mode bit in qspi_ahb too if expm_opcode is sent to flash.
 * @{
 */
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__SHIFT                              18
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__WIDTH                               1
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__MASK                      0x00040000U
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_FLASH_CONTROL2__ENPM_CLR_EN__RESET_VALUE               0x00000000U
/** @} */
#define PSEQ_FLASH_CONTROL2__TYPE                                      uint32_t
#define PSEQ_FLASH_CONTROL2__READ                                   0x000700ffU
#define PSEQ_FLASH_CONTROL2__WRITE                                  0x000700ffU
#define PSEQ_FLASH_CONTROL2__PRESERVED                              0x00000000U
#define PSEQ_FLASH_CONTROL2__RESET_VALUE                            0x0002007fU

#endif /* __PSEQ_FLASH_CONTROL2_MACRO__ */

/** @} end of flash_control2 */

/* macros for BlueprintGlobalNameSpace::PSEQ_pmu_status */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_status pmu_status
 * @brief pmu status information definitions.
 * @{
 */
#ifndef __PSEQ_PMU_STATUS_MACRO__
#define __PSEQ_PMU_STATUS_MACRO__

/* macros for field energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4CPU_field energy4CPU_field
 * @brief macros for field energy4CPU
 * @details enough energy is present to operation the CPU
 * @{
 */
#define PSEQ_PMU_STATUS__ENERGY4CPU__SHIFT                                    0
#define PSEQ_PMU_STATUS__ENERGY4CPU__WIDTH                                    1
#define PSEQ_PMU_STATUS__ENERGY4CPU__MASK                           0x00000001U
#define PSEQ_PMU_STATUS__ENERGY4CPU__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define PSEQ_PMU_STATUS__ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_PMU_STATUS__ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_PMU_STATUS__ENERGY4CPU__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4TX_field energy4TX_field
 * @brief macros for field energy4TX
 * @details enough energy is present to do a transmit
 * @{
 */
#define PSEQ_PMU_STATUS__ENERGY4TX__SHIFT                                     1
#define PSEQ_PMU_STATUS__ENERGY4TX__WIDTH                                     1
#define PSEQ_PMU_STATUS__ENERGY4TX__MASK                            0x00000002U
#define PSEQ_PMU_STATUS__ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_PMU_STATUS__ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_PMU_STATUS__ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_PMU_STATUS__ENERGY4TX__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field endoflife */
/**
 * @defgroup at_apb_pseq_perth_regs_core_endoflife_field endoflife_field
 * @brief macros for field endoflife
 * @details battery is detected to be at end of life; do not start flash writes or radio operation
 * @{
 */
#define PSEQ_PMU_STATUS__ENDOFLIFE__SHIFT                                     2
#define PSEQ_PMU_STATUS__ENDOFLIFE__WIDTH                                     1
#define PSEQ_PMU_STATUS__ENDOFLIFE__MASK                            0x00000004U
#define PSEQ_PMU_STATUS__ENDOFLIFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_PMU_STATUS__ENDOFLIFE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_PMU_STATUS__ENDOFLIFE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_PMU_STATUS__ENDOFLIFE__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field brownout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_brownout_field brownout_field
 * @brief macros for field brownout
 * @details brownout detected; go to low power state as quickly as possible
 * @{
 */
#define PSEQ_PMU_STATUS__BROWNOUT__SHIFT                                      3
#define PSEQ_PMU_STATUS__BROWNOUT__WIDTH                                      1
#define PSEQ_PMU_STATUS__BROWNOUT__MASK                             0x00000008U
#define PSEQ_PMU_STATUS__BROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_PMU_STATUS__BROWNOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_PMU_STATUS__BROWNOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_PMU_STATUS__BROWNOUT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field vbus5det */
/**
 * @defgroup at_apb_pseq_perth_regs_core_vbus5det_field vbus5det_field
 * @brief macros for field vbus5det
 * @details 5V USB detected; can be used to start charging operation from 5V USB.
 * @{
 */
#define PSEQ_PMU_STATUS__VBUS5DET__SHIFT                                      4
#define PSEQ_PMU_STATUS__VBUS5DET__WIDTH                                      1
#define PSEQ_PMU_STATUS__VBUS5DET__MASK                             0x00000010U
#define PSEQ_PMU_STATUS__VBUS5DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_PMU_STATUS__VBUS5DET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_PMU_STATUS__VBUS5DET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_PMU_STATUS__VBUS5DET__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field soc_off_wkup_det */
/**
 * @defgroup at_apb_pseq_perth_regs_core_soc_off_wkup_det_field soc_off_wkup_det_field
 * @brief macros for field soc_off_wkup_det
 * @details returned from SOC Off state
 * @{
 */
#define PSEQ_PMU_STATUS__SOC_OFF_WKUP_DET__SHIFT                              5
#define PSEQ_PMU_STATUS__SOC_OFF_WKUP_DET__WIDTH                              3
#define PSEQ_PMU_STATUS__SOC_OFF_WKUP_DET__MASK                     0x000000e0U
#define PSEQ_PMU_STATUS__SOC_OFF_WKUP_DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000e0U) >> 5)
#define PSEQ_PMU_STATUS__SOC_OFF_WKUP_DET__RESET_VALUE              0x00000000U
/** @} */

/* macros for field pmu_wdog_warn */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_wdog_warn_field pmu_wdog_warn_field
 * @brief macros for field pmu_wdog_warn
 * @{
 */
#define PSEQ_PMU_STATUS__PMU_WDOG_WARN__SHIFT                                 8
#define PSEQ_PMU_STATUS__PMU_WDOG_WARN__WIDTH                                 1
#define PSEQ_PMU_STATUS__PMU_WDOG_WARN__MASK                        0x00000100U
#define PSEQ_PMU_STATUS__PMU_WDOG_WARN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_PMU_STATUS__PMU_WDOG_WARN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_PMU_STATUS__PMU_WDOG_WARN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_PMU_STATUS__PMU_WDOG_WARN__RESET_VALUE                 0x00000000U
/** @} */
#define PSEQ_PMU_STATUS__TYPE                                          uint32_t
#define PSEQ_PMU_STATUS__READ                                       0x000001ffU
#define PSEQ_PMU_STATUS__PRESERVED                                  0x00000000U
#define PSEQ_PMU_STATUS__RESET_VALUE                                0x00000000U

#endif /* __PSEQ_PMU_STATUS_MACRO__ */

/** @} end of pmu_status */

/* macros for BlueprintGlobalNameSpace::PSEQ_pmu_interrupt */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_interrupt pmu_interrupt
 * @brief pmu interrupt source definitions.
 * @{
 */
#ifndef __PSEQ_PMU_INTERRUPT_MACRO__
#define __PSEQ_PMU_INTERRUPT_MACRO__

/* macros for field energy4CPU_high */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4CPU_high_field energy4CPU_high_field
 * @brief macros for field energy4CPU_high
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__SHIFT                            0
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__WIDTH                            1
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__MASK                   0x00000001U
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_HIGH__RESET_VALUE            0x00000000U
/** @} */

/* macros for field energy4CPU_low */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4CPU_low_field energy4CPU_low_field
 * @brief macros for field energy4CPU_low
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__SHIFT                             1
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__WIDTH                             1
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__MASK                    0x00000002U
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_LOW__RESET_VALUE             0x00000000U
/** @} */

/* macros for field energy4CPU_rising */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4CPU_rising_field energy4CPU_rising_field
 * @brief macros for field energy4CPU_rising
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__SHIFT                          2
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__WIDTH                          1
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__MASK                 0x00000004U
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_RISING__RESET_VALUE          0x00000000U
/** @} */

/* macros for field energy4CPU_falling */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4CPU_falling_field energy4CPU_falling_field
 * @brief macros for field energy4CPU_falling
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__SHIFT                         3
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__WIDTH                         1
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__MASK                0x00000008U
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_PMU_INTERRUPT__ENERGY4CPU_FALLING__RESET_VALUE         0x00000000U
/** @} */

/* macros for field energy4TX_high */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4TX_high_field energy4TX_high_field
 * @brief macros for field energy4TX_high
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__SHIFT                             4
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__WIDTH                             1
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__MASK                    0x00000010U
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_HIGH__RESET_VALUE             0x00000000U
/** @} */

/* macros for field energy4TX_low */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4TX_low_field energy4TX_low_field
 * @brief macros for field energy4TX_low
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__SHIFT                              5
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__WIDTH                              1
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__MASK                     0x00000020U
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_LOW__RESET_VALUE              0x00000000U
/** @} */

/* macros for field energy4TX_rising */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4TX_rising_field energy4TX_rising_field
 * @brief macros for field energy4TX_rising
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__SHIFT                           6
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__WIDTH                           1
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__MASK                  0x00000040U
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_RISING__RESET_VALUE           0x00000000U
/** @} */

/* macros for field energy4TX_falling */
/**
 * @defgroup at_apb_pseq_perth_regs_core_energy4TX_falling_field energy4TX_falling_field
 * @brief macros for field energy4TX_falling
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__SHIFT                          7
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__WIDTH                          1
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__MASK                 0x00000080U
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_PMU_INTERRUPT__ENERGY4TX_FALLING__RESET_VALUE          0x00000000U
/** @} */

/* macros for field endOfLife_high */
/**
 * @defgroup at_apb_pseq_perth_regs_core_endOfLife_high_field endOfLife_high_field
 * @brief macros for field endOfLife_high
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__SHIFT                             8
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__WIDTH                             1
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__MASK                    0x00000100U
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_HIGH__RESET_VALUE             0x00000000U
/** @} */

/* macros for field endOfLife_low */
/**
 * @defgroup at_apb_pseq_perth_regs_core_endOfLife_low_field endOfLife_low_field
 * @brief macros for field endOfLife_low
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__SHIFT                              9
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__WIDTH                              1
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__MASK                     0x00000200U
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_LOW__RESET_VALUE              0x00000000U
/** @} */

/* macros for field endOfLife_rising */
/**
 * @defgroup at_apb_pseq_perth_regs_core_endOfLife_rising_field endOfLife_rising_field
 * @brief macros for field endOfLife_rising
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__SHIFT                          10
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__WIDTH                           1
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__MASK                  0x00000400U
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_RISING__RESET_VALUE           0x00000000U
/** @} */

/* macros for field endOfLife_falling */
/**
 * @defgroup at_apb_pseq_perth_regs_core_endOfLife_falling_field endOfLife_falling_field
 * @brief macros for field endOfLife_falling
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__SHIFT                         11
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__WIDTH                          1
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__MASK                 0x00000800U
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_PMU_INTERRUPT__ENDOFLIFE_FALLING__RESET_VALUE          0x00000000U
/** @} */

/* macros for field brownout_high */
/**
 * @defgroup at_apb_pseq_perth_regs_core_brownout_high_field brownout_high_field
 * @brief macros for field brownout_high
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__SHIFT                             12
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__WIDTH                              1
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__MASK                     0x00001000U
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_HIGH__RESET_VALUE              0x00000000U
/** @} */

/* macros for field brownout_low */
/**
 * @defgroup at_apb_pseq_perth_regs_core_brownout_low_field brownout_low_field
 * @brief macros for field brownout_low
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__SHIFT                              13
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__WIDTH                               1
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__MASK                      0x00002000U
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_LOW__RESET_VALUE               0x00000000U
/** @} */

/* macros for field brownout_rising */
/**
 * @defgroup at_apb_pseq_perth_regs_core_brownout_rising_field brownout_rising_field
 * @brief macros for field brownout_rising
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__SHIFT                           14
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__WIDTH                            1
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__MASK                   0x00004000U
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_RISING__RESET_VALUE            0x00000000U
/** @} */

/* macros for field brownout_falling */
/**
 * @defgroup at_apb_pseq_perth_regs_core_brownout_falling_field brownout_falling_field
 * @brief macros for field brownout_falling
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__SHIFT                          15
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__WIDTH                           1
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__MASK                  0x00008000U
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_PMU_INTERRUPT__BROWNOUT_FALLING__RESET_VALUE           0x00000000U
/** @} */

/* macros for field vbus5det_high */
/**
 * @defgroup at_apb_pseq_perth_regs_core_vbus5det_high_field vbus5det_high_field
 * @brief macros for field vbus5det_high
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__SHIFT                             16
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__WIDTH                              1
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__MASK                     0x00010000U
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_HIGH__RESET_VALUE              0x00000000U
/** @} */

/* macros for field vbus5det_low */
/**
 * @defgroup at_apb_pseq_perth_regs_core_vbus5det_low_field vbus5det_low_field
 * @brief macros for field vbus5det_low
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__SHIFT                              17
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__WIDTH                               1
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__MASK                      0x00020000U
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_LOW__RESET_VALUE               0x00000000U
/** @} */

/* macros for field vbus5det_rising */
/**
 * @defgroup at_apb_pseq_perth_regs_core_vbus5det_rising_field vbus5det_rising_field
 * @brief macros for field vbus5det_rising
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__SHIFT                           18
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__WIDTH                            1
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__MASK                   0x00040000U
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_RISING__RESET_VALUE            0x00000000U
/** @} */

/* macros for field vbus5det_falling */
/**
 * @defgroup at_apb_pseq_perth_regs_core_vbus5det_falling_field vbus5det_falling_field
 * @brief macros for field vbus5det_falling
 * @details  0 = pmu_status_energy4CPU level  1 = pmu_status_energy4CPU negated level  2 = pmu_status_energy4CPU rising edge  3 = pmu_status_energy4CPU falling edge  4 = pmu_status_energy4TX level  5 = pmu_status_energy4TX negated level  6 = pmu_status_energy4TX rising edge  7 = pmu_status_energy4TX falling edge  8 = pmu_status_endOfLife level  9 = pmu_status_endOfLife negated level  10 = pmu_status_endOfLife rising edge  11 = pmu_status_endOfLife falling edge  12 = pmu_status_brownout level  13 = pmu_status_brownout negated level  14 = pmu_status_brownout rising edge  15 = pmu_status_brownout falling edge  16 = pmu_status_vbus5det level  17 = pmu_status_vbus5det negated level  18 = pmu_status_vbus5det rising edge  19 = pmu_status_vbus5det falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__SHIFT                          19
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__WIDTH                           1
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__MASK                  0x00080000U
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PSEQ_PMU_INTERRUPT__VBUS5DET_FALLING__RESET_VALUE           0x00000000U
/** @} */

/* macros for field clear_re_energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_re_energy4CPU_field clear_re_energy4CPU_field
 * @brief macros for field clear_re_energy4CPU
 * @details clear the falling edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__SHIFT                       20
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__WIDTH                        1
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__MASK               0x00100000U
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4CPU__RESET_VALUE        0x00000000U
/** @} */

/* macros for field clear_re_energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_re_energy4TX_field clear_re_energy4TX_field
 * @brief macros for field clear_re_energy4TX
 * @details clear the falling edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__SHIFT                        21
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__WIDTH                         1
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__MASK                0x00200000U
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENERGY4TX__RESET_VALUE         0x00000000U
/** @} */

/* macros for field clear_re_endOfLife */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_re_endOfLife_field clear_re_endOfLife_field
 * @brief macros for field clear_re_endOfLife
 * @details clear the falling edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__SHIFT                        22
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__WIDTH                         1
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__MASK                0x00400000U
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_ENDOFLIFE__RESET_VALUE         0x00000000U
/** @} */

/* macros for field clear_re_brownout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_re_brownout_field clear_re_brownout_field
 * @brief macros for field clear_re_brownout
 * @details clear the falling edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__SHIFT                         23
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__WIDTH                          1
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__MASK                 0x00800000U
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_BROWNOUT__RESET_VALUE          0x00000000U
/** @} */

/* macros for field clear_re_vbus5det */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_re_vbus5det_field clear_re_vbus5det_field
 * @brief macros for field clear_re_vbus5det
 * @details clear the falling edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__SHIFT                         24
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__WIDTH                          1
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__MASK                 0x01000000U
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define PSEQ_PMU_INTERRUPT__CLEAR_RE_VBUS5DET__RESET_VALUE          0x00000000U
/** @} */

/* macros for field clear_fe_energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_fe_energy4CPU_field clear_fe_energy4CPU_field
 * @brief macros for field clear_fe_energy4CPU
 * @details clear the rising edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__SHIFT                       25
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__WIDTH                        1
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__MASK               0x02000000U
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4CPU__RESET_VALUE        0x00000000U
/** @} */

/* macros for field clear_fe_energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_fe_energy4TX_field clear_fe_energy4TX_field
 * @brief macros for field clear_fe_energy4TX
 * @details clear the rising edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__SHIFT                        26
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__WIDTH                         1
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__MASK                0x04000000U
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENERGY4TX__RESET_VALUE         0x00000000U
/** @} */

/* macros for field clear_fe_endOfLife */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_fe_endOfLife_field clear_fe_endOfLife_field
 * @brief macros for field clear_fe_endOfLife
 * @details clear the rising edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__SHIFT                        27
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__WIDTH                         1
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__MASK                0x08000000U
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_ENDOFLIFE__RESET_VALUE         0x00000000U
/** @} */

/* macros for field clear_fe_brownout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_fe_brownout_field clear_fe_brownout_field
 * @brief macros for field clear_fe_brownout
 * @details clear the rising edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__SHIFT                         28
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__WIDTH                          1
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__MASK                 0x10000000U
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_BROWNOUT__RESET_VALUE          0x00000000U
/** @} */

/* macros for field clear_fe_vbus5det */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_fe_vbus5det_field clear_fe_vbus5det_field
 * @brief macros for field clear_fe_vbus5det
 * @details clear the rising edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__SHIFT                         29
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__WIDTH                          1
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__MASK                 0x20000000U
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PSEQ_PMU_INTERRUPT__CLEAR_FE_VBUS5DET__RESET_VALUE          0x00000000U
/** @} */
#define PSEQ_PMU_INTERRUPT__TYPE                                       uint32_t
#define PSEQ_PMU_INTERRUPT__READ                                    0x3fffffffU
#define PSEQ_PMU_INTERRUPT__WRITE                                   0x3fffffffU
#define PSEQ_PMU_INTERRUPT__PRESERVED                               0x00000000U
#define PSEQ_PMU_INTERRUPT__RESET_VALUE                             0x00000000U

#endif /* __PSEQ_PMU_INTERRUPT_MACRO__ */

/** @} end of pmu_interrupt */

/* macros for BlueprintGlobalNameSpace::PSEQ_pmu_interrupt_expan */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_interrupt_expan pmu_interrupt_expan
 * @brief pmu interrupt source definitions.
 * @{
 */
#ifndef __PSEQ_PMU_INTERRUPT_EXPAN_MACRO__
#define __PSEQ_PMU_INTERRUPT_EXPAN_MACRO__

/* macros for field pmu_wdog_warn_high */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_wdog_warn_high_field pmu_wdog_warn_high_field
 * @brief macros for field pmu_wdog_warn_high
 * @details  0 = pmu_wdog_warn level  1 = pmu_wdog_warn negated level  2 = pmu_wdog_warn rising edge  3 = pmu_wdog_warn falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__SHIFT                   0
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__WIDTH                   1
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__MASK          0x00000001U
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_HIGH__RESET_VALUE   0x00000000U
/** @} */

/* macros for field pmu_wdog_warn_low */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_wdog_warn_low_field pmu_wdog_warn_low_field
 * @brief macros for field pmu_wdog_warn_low
 * @details  0 = pmu_wdog_warn level  1 = pmu_wdog_warn negated level  2 = pmu_wdog_warn rising edge  3 = pmu_wdog_warn falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__SHIFT                    1
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__WIDTH                    1
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__MASK           0x00000002U
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_LOW__RESET_VALUE    0x00000000U
/** @} */

/* macros for field pmu_wdog_warn_rising */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_wdog_warn_rising_field pmu_wdog_warn_rising_field
 * @brief macros for field pmu_wdog_warn_rising
 * @details  0 = pmu_wdog_warn level  1 = pmu_wdog_warn negated level  2 = pmu_wdog_warn rising edge  3 = pmu_wdog_warn falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__SHIFT                 2
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__WIDTH                 1
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__MASK        0x00000004U
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__RESET_VALUE 0x00000000U
/** @} */

/* macros for field pmu_wdog_warn_falling */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pmu_wdog_warn_falling_field pmu_wdog_warn_falling_field
 * @brief macros for field pmu_wdog_warn_falling
 * @details  0 = pmu_wdog_warn level  1 = pmu_wdog_warn negated level  2 = pmu_wdog_warn rising edge  3 = pmu_wdog_warn falling edge
 * @{
 */
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__SHIFT                3
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__WIDTH                1
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__MASK       0x00000008U
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_FALLING__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field clear_re_pmu_wdog_warn */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_re_pmu_wdog_warn_field clear_re_pmu_wdog_warn_field
 * @brief macros for field clear_re_pmu_wdog_warn
 * @details clear the falling edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__SHIFT              20
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__WIDTH               1
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__MASK      0x00100000U
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field clear_fe_pmu_wdog_warn */
/**
 * @defgroup at_apb_pseq_perth_regs_core_clear_fe_pmu_wdog_warn_field clear_fe_pmu_wdog_warn_field
 * @brief macros for field clear_fe_pmu_wdog_warn
 * @details clear the rising edge capture blocks (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__SHIFT              25
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__WIDTH               1
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__MASK      0x02000000U
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_FE_PMU_WDOG_WARN__RESET_VALUE \
                    0x00000000U
/** @} */
#define PSEQ_PMU_INTERRUPT_EXPAN__TYPE                                 uint32_t
#define PSEQ_PMU_INTERRUPT_EXPAN__READ                              0x0210000fU
#define PSEQ_PMU_INTERRUPT_EXPAN__WRITE                             0x0210000fU
#define PSEQ_PMU_INTERRUPT_EXPAN__PRESERVED                         0x00000000U
#define PSEQ_PMU_INTERRUPT_EXPAN__RESET_VALUE                       0x00000000U

#endif /* __PSEQ_PMU_INTERRUPT_EXPAN_MACRO__ */

/** @} end of pmu_interrupt_expan */

/* macros for BlueprintGlobalNameSpace::PSEQ_sysram_write_block_cfg */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sysram_write_block_cfg sysram_write_block_cfg
 * @brief Contains register fields associated with sysram_write_block_cfg. definitions.
 * @{
 */
#ifndef __PSEQ_SYSRAM_WRITE_BLOCK_CFG_MACRO__
#define __PSEQ_SYSRAM_WRITE_BLOCK_CFG_MACRO__

/* macros for field a_lo */
/**
 * @defgroup at_apb_pseq_perth_regs_core_a_lo_field a_lo_field
 * @brief macros for field a_lo
 * @details low address on word boundary; any address from high address to low address is no longer writable once enable is set
 * @{
 */
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__SHIFT                              0
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__WIDTH                             14
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__MASK                     0x00003fffU
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00003fffU)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00003fffU)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_LO__RESET_VALUE              0x00000000U
/** @} */

/* macros for field a_hi */
/**
 * @defgroup at_apb_pseq_perth_regs_core_a_hi_field a_hi_field
 * @brief macros for field a_hi
 * @details high address on word boundary
 * @{
 */
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__SHIFT                             14
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__WIDTH                             14
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__MASK                     0x0fffc000U
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fffc000U) >> 14)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0fffc000U)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fffc000U) | (((uint32_t)(src) <<\
                    14) & 0x0fffc000U)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0fffc000U)))
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__A_HI__RESET_VALUE              0x00000000U
/** @} */

/* macros for field en_wrblk */
/**
 * @defgroup at_apb_pseq_perth_regs_core_en_wrblk_field en_wrblk_field
 * @brief macros for field en_wrblk
 * @details enable the sysram write lock; can't be undone unless a porst_soc is issued by pmu
 * @{
 */
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__SHIFT                         28
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__WIDTH                          1
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__MASK                 0x10000000U
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__EN_WRBLK__RESET_VALUE          0x00000000U
/** @} */
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__TYPE                              uint32_t
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__READ                           0x1fffffffU
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__WRITE                          0x1fffffffU
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__PRESERVED                      0x00000000U
#define PSEQ_SYSRAM_WRITE_BLOCK_CFG__RESET_VALUE                    0x00000000U

#endif /* __PSEQ_SYSRAM_WRITE_BLOCK_CFG_MACRO__ */

/** @} end of sysram_write_block_cfg */

/* macros for BlueprintGlobalNameSpace::PSEQ_interrupt_status */
/**
 * @defgroup at_apb_pseq_perth_regs_core_interrupt_status interrupt_status
 * @brief interrupt status definitions.
 * @{
 */
#ifndef __PSEQ_INTERRUPT_STATUS_MACRO__
#define __PSEQ_INTERRUPT_STATUS_MACRO__

/* macros for field returned_from_lp_state */
/**
 * @defgroup at_apb_pseq_perth_regs_core_returned_from_lp_state_field returned_from_lp_state_field
 * @brief macros for field returned_from_lp_state
 * @details indicates system returned from low power state (as oppposed to first power on)
 * @{
 */
#define PSEQ_INTERRUPT_STATUS__RETURNED_FROM_LP_STATE__SHIFT                  0
#define PSEQ_INTERRUPT_STATUS__RETURNED_FROM_LP_STATE__WIDTH                  1
#define PSEQ_INTERRUPT_STATUS__RETURNED_FROM_LP_STATE__MASK         0x00000001U
#define PSEQ_INTERRUPT_STATUS__RETURNED_FROM_LP_STATE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_INTERRUPT_STATUS__RETURNED_FROM_LP_STATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_INTERRUPT_STATUS__RETURNED_FROM_LP_STATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_INTERRUPT_STATUS__RETURNED_FROM_LP_STATE__RESET_VALUE  0x00000000U
/** @} */

/* macros for field cntdwn_timer_expired */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cntdwn_timer_expired_field cntdwn_timer_expired_field
 * @brief macros for field cntdwn_timer_expired
 * @details indicates count down timer is expired.
 * @{
 */
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_EXPIRED__SHIFT                    1
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_EXPIRED__WIDTH                    1
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_EXPIRED__MASK           0x00000002U
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_EXPIRED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_EXPIRED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_EXPIRED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_EXPIRED__RESET_VALUE    0x00000000U
/** @} */

/* macros for field cntdwn_timer_1_expired */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cntdwn_timer_1_expired_field cntdwn_timer_1_expired_field
 * @brief macros for field cntdwn_timer_1_expired
 * @details indicates count down timer1 is expired.
 * @{
 */
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_1_EXPIRED__SHIFT                  2
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_1_EXPIRED__WIDTH                  1
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_1_EXPIRED__MASK         0x00000004U
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_1_EXPIRED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_1_EXPIRED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_1_EXPIRED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_INTERRUPT_STATUS__CNTDWN_TIMER_1_EXPIRED__RESET_VALUE  0x00000000U
/** @} */

/* macros for field frc_match0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_field frc_match0_field
 * @brief macros for field frc_match0
 * @details indicates current_real_time matches frc_match0_val
 * @{
 */
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH0__SHIFT                              3
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH0__WIDTH                              1
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH0__MASK                     0x00000008U
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH0__RESET_VALUE              0x00000000U
/** @} */

/* macros for field frc_match1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_field frc_match1_field
 * @brief macros for field frc_match1
 * @details indicates current_real_time matches frc_match0_val
 * @{
 */
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH1__SHIFT                              4
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH1__WIDTH                              1
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH1__MASK                     0x00000010U
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_INTERRUPT_STATUS__FRC_MATCH1__RESET_VALUE              0x00000000U
/** @} */
#define PSEQ_INTERRUPT_STATUS__TYPE                                    uint32_t
#define PSEQ_INTERRUPT_STATUS__READ                                 0x0000001fU
#define PSEQ_INTERRUPT_STATUS__PRESERVED                            0x00000000U
#define PSEQ_INTERRUPT_STATUS__RESET_VALUE                          0x00000000U

#endif /* __PSEQ_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::PSEQ_interrupt_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_interrupt_mask interrupt_mask
 * @brief interrupt mask definitions.
 * @{
 */
#ifndef __PSEQ_INTERRUPT_MASK_MACRO__
#define __PSEQ_INTERRUPT_MASK_MACRO__

/* macros for field intrpt_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_intrpt_mask_field intrpt_mask_field
 * @brief macros for field intrpt_mask
 * @details if nth bit set, the nth interrupt source is allowed to propogate to core's interrupt
 * @{
 */
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__SHIFT                               0
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__WIDTH                               5
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__MASK                      0x0000001fU
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define PSEQ_INTERRUPT_MASK__INTRPT_MASK__RESET_VALUE               0x0000001fU
/** @} */
#define PSEQ_INTERRUPT_MASK__TYPE                                      uint32_t
#define PSEQ_INTERRUPT_MASK__READ                                   0x0000001fU
#define PSEQ_INTERRUPT_MASK__WRITE                                  0x0000001fU
#define PSEQ_INTERRUPT_MASK__PRESERVED                              0x00000000U
#define PSEQ_INTERRUPT_MASK__RESET_VALUE                            0x0000001fU

#endif /* __PSEQ_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::PSEQ_reset_interrupt */
/**
 * @defgroup at_apb_pseq_perth_regs_core_reset_interrupt reset_interrupt
 * @brief interrupt resets definitions.
 * @{
 */
#ifndef __PSEQ_RESET_INTERRUPT_MACRO__
#define __PSEQ_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_apb_pseq_perth_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details if nth bit set, the nth interrupt is reset. (__SELF_CLEARING__)
 * @{
 */
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__SHIFT                             0
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__WIDTH                             5
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__MASK                    0x0000001fU
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define PSEQ_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE             0x00000000U
/** @} */
#define PSEQ_RESET_INTERRUPT__TYPE                                     uint32_t
#define PSEQ_RESET_INTERRUPT__READ                                  0x0000001fU
#define PSEQ_RESET_INTERRUPT__WRITE                                 0x0000001fU
#define PSEQ_RESET_INTERRUPT__PRESERVED                             0x00000000U
#define PSEQ_RESET_INTERRUPT__RESET_VALUE                           0x00000000U

#endif /* __PSEQ_RESET_INTERRUPT_MACRO__ */

/** @} end of reset_interrupt */

/* macros for BlueprintGlobalNameSpace::PSEQ_fpga_cfg */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fpga_cfg fpga_cfg
 * @brief Contains register fields associated with fpga_cfg. definitions.
 * @{
 */
#ifndef __PSEQ_FPGA_CFG_MACRO__
#define __PSEQ_FPGA_CFG_MACRO__

/* macros for field cfg */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cfg_field cfg_field
 * @brief macros for field cfg
 * @{
 */
#define PSEQ_FPGA_CFG__CFG__SHIFT                                             0
#define PSEQ_FPGA_CFG__CFG__WIDTH                                            16
#define PSEQ_FPGA_CFG__CFG__MASK                                    0x0000ffffU
#define PSEQ_FPGA_CFG__CFG__READ(src)           ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_FPGA_CFG__CFG__WRITE(src)          ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_FPGA_CFG__CFG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PSEQ_FPGA_CFG__CFG__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PSEQ_FPGA_CFG__CFG__RESET_VALUE                             0x00000000U
/** @} */
#define PSEQ_FPGA_CFG__TYPE                                            uint32_t
#define PSEQ_FPGA_CFG__READ                                         0x0000ffffU
#define PSEQ_FPGA_CFG__WRITE                                        0x0000ffffU
#define PSEQ_FPGA_CFG__PRESERVED                                    0x00000000U
#define PSEQ_FPGA_CFG__RESET_VALUE                                  0x00000000U

#endif /* __PSEQ_FPGA_CFG_MACRO__ */

/** @} end of fpga_cfg */

/* macros for BlueprintGlobalNameSpace::PSEQ_pll */
/**
 * @defgroup at_apb_pseq_perth_regs_core_pll pll
 * @brief Contains register fields associated with pll. definitions.
 * @{
 */
#ifndef __PSEQ_PLL_MACRO__
#define __PSEQ_PLL_MACRO__

/* macros for field filtr */
/**
 * @defgroup at_apb_pseq_perth_regs_core_filtr_field filtr_field
 * @brief macros for field filtr
 * @{
 */
#define PSEQ_PLL__FILTR__SHIFT                                                4
#define PSEQ_PLL__FILTR__WIDTH                                                4
#define PSEQ_PLL__FILTR__MASK                                       0x000000f0U
#define PSEQ_PLL__FILTR__READ(src)       (((uint32_t)(src) & 0x000000f0U) >> 4)
#define PSEQ_PLL__FILTR__WRITE(src)      (((uint32_t)(src) << 4) & 0x000000f0U)
#define PSEQ_PLL__FILTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define PSEQ_PLL__FILTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define PSEQ_PLL__FILTR__RESET_VALUE                                0x00000000U
/** @} */

/* macros for field filtc */
/**
 * @defgroup at_apb_pseq_perth_regs_core_filtc_field filtc_field
 * @brief macros for field filtc
 * @{
 */
#define PSEQ_PLL__FILTC__SHIFT                                                8
#define PSEQ_PLL__FILTC__WIDTH                                                2
#define PSEQ_PLL__FILTC__MASK                                       0x00000300U
#define PSEQ_PLL__FILTC__READ(src)       (((uint32_t)(src) & 0x00000300U) >> 8)
#define PSEQ_PLL__FILTC__WRITE(src)      (((uint32_t)(src) << 8) & 0x00000300U)
#define PSEQ_PLL__FILTC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define PSEQ_PLL__FILTC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define PSEQ_PLL__FILTC__RESET_VALUE                                0x00000000U
/** @} */

/* macros for field cpcur */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cpcur_field cpcur_field
 * @brief macros for field cpcur
 * @{
 */
#define PSEQ_PLL__CPCUR__SHIFT                                               10
#define PSEQ_PLL__CPCUR__WIDTH                                                6
#define PSEQ_PLL__CPCUR__MASK                                       0x0000fc00U
#define PSEQ_PLL__CPCUR__READ(src)      (((uint32_t)(src) & 0x0000fc00U) >> 10)
#define PSEQ_PLL__CPCUR__WRITE(src)     (((uint32_t)(src) << 10) & 0x0000fc00U)
#define PSEQ_PLL__CPCUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define PSEQ_PLL__CPCUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define PSEQ_PLL__CPCUR__RESET_VALUE                                0x00000000U
/** @} */

/* macros for field div2out */
/**
 * @defgroup at_apb_pseq_perth_regs_core_div2out_field div2out_field
 * @brief macros for field div2out
 * @{
 */
#define PSEQ_PLL__DIV2OUT__SHIFT                                             16
#define PSEQ_PLL__DIV2OUT__WIDTH                                              1
#define PSEQ_PLL__DIV2OUT__MASK                                     0x00010000U
#define PSEQ_PLL__DIV2OUT__READ(src)    (((uint32_t)(src) & 0x00010000U) >> 16)
#define PSEQ_PLL__DIV2OUT__WRITE(src)   (((uint32_t)(src) << 16) & 0x00010000U)
#define PSEQ_PLL__DIV2OUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PSEQ_PLL__DIV2OUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PSEQ_PLL__DIV2OUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PSEQ_PLL__DIV2OUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PSEQ_PLL__DIV2OUT__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field divout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_divout_field divout_field
 * @brief macros for field divout
 * @{
 */
#define PSEQ_PLL__DIVOUT__SHIFT                                              17
#define PSEQ_PLL__DIVOUT__WIDTH                                               3
#define PSEQ_PLL__DIVOUT__MASK                                      0x000e0000U
#define PSEQ_PLL__DIVOUT__READ(src)     (((uint32_t)(src) & 0x000e0000U) >> 17)
#define PSEQ_PLL__DIVOUT__WRITE(src)    (((uint32_t)(src) << 17) & 0x000e0000U)
#define PSEQ_PLL__DIVOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000e0000U) | (((uint32_t)(src) <<\
                    17) & 0x000e0000U)
#define PSEQ_PLL__DIVOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x000e0000U)))
#define PSEQ_PLL__DIVOUT__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field divfb */
/**
 * @defgroup at_apb_pseq_perth_regs_core_divfb_field divfb_field
 * @brief macros for field divfb
 * @{
 */
#define PSEQ_PLL__DIVFB__SHIFT                                               20
#define PSEQ_PLL__DIVFB__WIDTH                                                6
#define PSEQ_PLL__DIVFB__MASK                                       0x03f00000U
#define PSEQ_PLL__DIVFB__READ(src)      (((uint32_t)(src) & 0x03f00000U) >> 20)
#define PSEQ_PLL__DIVFB__WRITE(src)     (((uint32_t)(src) << 20) & 0x03f00000U)
#define PSEQ_PLL__DIVFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03f00000U) | (((uint32_t)(src) <<\
                    20) & 0x03f00000U)
#define PSEQ_PLL__DIVFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x03f00000U)))
#define PSEQ_PLL__DIVFB__RESET_VALUE                                0x00000000U
/** @} */

/* macros for field divref */
/**
 * @defgroup at_apb_pseq_perth_regs_core_divref_field divref_field
 * @brief macros for field divref
 * @{
 */
#define PSEQ_PLL__DIVREF__SHIFT                                              26
#define PSEQ_PLL__DIVREF__WIDTH                                               3
#define PSEQ_PLL__DIVREF__MASK                                      0x1c000000U
#define PSEQ_PLL__DIVREF__READ(src)     (((uint32_t)(src) & 0x1c000000U) >> 26)
#define PSEQ_PLL__DIVREF__WRITE(src)    (((uint32_t)(src) << 26) & 0x1c000000U)
#define PSEQ_PLL__DIVREF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1c000000U) | (((uint32_t)(src) <<\
                    26) & 0x1c000000U)
#define PSEQ_PLL__DIVREF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x1c000000U)))
#define PSEQ_PLL__DIVREF__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field divaccess */
/**
 * @defgroup at_apb_pseq_perth_regs_core_divaccess_field divaccess_field
 * @brief macros for field divaccess
 * @{
 */
#define PSEQ_PLL__DIVACCESS__SHIFT                                           29
#define PSEQ_PLL__DIVACCESS__WIDTH                                            1
#define PSEQ_PLL__DIVACCESS__MASK                                   0x20000000U
#define PSEQ_PLL__DIVACCESS__READ(src)  (((uint32_t)(src) & 0x20000000U) >> 29)
#define PSEQ_PLL__DIVACCESS__WRITE(src) (((uint32_t)(src) << 29) & 0x20000000U)
#define PSEQ_PLL__DIVACCESS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PSEQ_PLL__DIVACCESS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PSEQ_PLL__DIVACCESS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PSEQ_PLL__DIVACCESS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PSEQ_PLL__DIVACCESS__RESET_VALUE                            0x00000000U
/** @} */
#define PSEQ_PLL__TYPE                                                 uint32_t
#define PSEQ_PLL__READ                                              0x3ffffff0U
#define PSEQ_PLL__WRITE                                             0x3ffffff0U
#define PSEQ_PLL__PRESERVED                                         0x00000000U
#define PSEQ_PLL__RESET_VALUE                                       0x00000000U

#endif /* __PSEQ_PLL_MACRO__ */

/** @} end of pll */

/* macros for BlueprintGlobalNameSpace::PSEQ_rram_read_config_lo */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rram_read_config_lo rram_read_config_lo
 * @brief Contains register fields associated with rram_read_config_lo. definitions.
 * @{
 */
#ifndef __PSEQ_RRAM_READ_CONFIG_LO_MACRO__
#define __PSEQ_RRAM_READ_CONFIG_LO_MACRO__

/* macros for field dout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_dout_field dout_field
 * @brief macros for field dout
 * @{
 */
#define PSEQ_RRAM_READ_CONFIG_LO__DOUT__SHIFT                                 0
#define PSEQ_RRAM_READ_CONFIG_LO__DOUT__WIDTH                                32
#define PSEQ_RRAM_READ_CONFIG_LO__DOUT__MASK                        0xffffffffU
#define PSEQ_RRAM_READ_CONFIG_LO__DOUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_RRAM_READ_CONFIG_LO__DOUT__RESET_VALUE                 0x00000000U
/** @} */
#define PSEQ_RRAM_READ_CONFIG_LO__TYPE                                 uint32_t
#define PSEQ_RRAM_READ_CONFIG_LO__READ                              0xffffffffU
#define PSEQ_RRAM_READ_CONFIG_LO__PRESERVED                         0x00000000U
#define PSEQ_RRAM_READ_CONFIG_LO__RESET_VALUE                       0x00000000U

#endif /* __PSEQ_RRAM_READ_CONFIG_LO_MACRO__ */

/** @} end of rram_read_config_lo */

/* macros for BlueprintGlobalNameSpace::PSEQ_rram_read_config_hi */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rram_read_config_hi rram_read_config_hi
 * @brief Contains register fields associated with rram_read_config_hi. definitions.
 * @{
 */
#ifndef __PSEQ_RRAM_READ_CONFIG_HI_MACRO__
#define __PSEQ_RRAM_READ_CONFIG_HI_MACRO__

/* macros for field dout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_dout_field dout_field
 * @brief macros for field dout
 * @{
 */
#define PSEQ_RRAM_READ_CONFIG_HI__DOUT__SHIFT                                 0
#define PSEQ_RRAM_READ_CONFIG_HI__DOUT__WIDTH                                32
#define PSEQ_RRAM_READ_CONFIG_HI__DOUT__MASK                        0xffffffffU
#define PSEQ_RRAM_READ_CONFIG_HI__DOUT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PSEQ_RRAM_READ_CONFIG_HI__DOUT__RESET_VALUE                 0x00000000U
/** @} */
#define PSEQ_RRAM_READ_CONFIG_HI__TYPE                                 uint32_t
#define PSEQ_RRAM_READ_CONFIG_HI__READ                              0xffffffffU
#define PSEQ_RRAM_READ_CONFIG_HI__PRESERVED                         0x00000000U
#define PSEQ_RRAM_READ_CONFIG_HI__RESET_VALUE                       0x00000000U

#endif /* __PSEQ_RRAM_READ_CONFIG_HI_MACRO__ */

/** @} end of rram_read_config_hi */

/* macros for BlueprintGlobalNameSpace::PSEQ_sensor_hub_imm_breakout_mask */
/**
 * @defgroup at_apb_pseq_perth_regs_core_sensor_hub_imm_breakout_mask sensor_hub_imm_breakout_mask
 * @brief control signals for sensor hub definitions.
 * @{
 */
#ifndef __PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK_MACRO__
#define __PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK_MACRO__

/* macros for field watch_gpio */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_gpio_field watch_gpio_field
 * @brief macros for field watch_gpio
 * @details valid to immediately breakout on gpio activity
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__SHIFT                  0
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__WIDTH                  1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__MASK         0x00000001U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_GPIO__RESET_VALUE  0x00000001U
/** @} */

/* macros for field watch_cntdown */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_cntdown_field watch_cntdown_field
 * @brief macros for field watch_cntdown
 * @details valid to immediately breakout on count down timer expiring
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__SHIFT               1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__WIDTH               1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__MASK      0x00000002U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_CNTDOWN__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field watch_wurx0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx0_field watch_wurx0_field
 * @brief macros for field watch_wurx0
 * @details valid to immediately breakout on wurx0 detect
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__SHIFT                 2
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__WIDTH                 1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__MASK        0x00000004U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX0__RESET_VALUE 0x00000001U
/** @} */

/* macros for field watch_wurx1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx1_field watch_wurx1_field
 * @brief macros for field watch_wurx1
 * @details valid to immediately breakout on wurx1 detect
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__SHIFT                 3
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__WIDTH                 1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__MASK        0x00000008U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX1__RESET_VALUE 0x00000001U
/** @} */

/* macros for field watch_qdec */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_qdec_field watch_qdec_field
 * @brief macros for field watch_qdec
 * @details valid to immediately breakout on qdec activity
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__SHIFT                  4
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__WIDTH                  1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__MASK         0x00000010U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_QDEC__RESET_VALUE  0x00000001U
/** @} */

/* macros for field watch_ksm */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_ksm_field watch_ksm_field
 * @brief macros for field watch_ksm
 * @details valid to immediately breakout on keyboard activity
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__SHIFT                   5
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__WIDTH                   1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__MASK          0x00000020U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_KSM__RESET_VALUE   0x00000001U
/** @} */

/* macros for field watch_shub */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_shub_field watch_shub_field
 * @brief macros for field watch_shub
 * @details valid to immediately breakout on sensor hub trigger
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__SHIFT                  6
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__WIDTH                  1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__MASK         0x00000040U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SHUB__RESET_VALUE  0x00000001U
/** @} */

/* macros for field watch_spi */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_spi_field watch_spi_field
 * @brief macros for field watch_spi
 * @details valid to immediately breakout on spi slave activity
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__SHIFT                   7
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__WIDTH                   1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__MASK          0x00000080U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_SPI__RESET_VALUE   0x00000001U
/** @} */

/* macros for field watch_i2c */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_i2c_field watch_i2c_field
 * @brief macros for field watch_i2c
 * @details valid to immediately breakout on i2c slave activity
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__SHIFT                   8
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__WIDTH                   1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__MASK          0x00000100U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_I2C__RESET_VALUE   0x00000001U
/** @} */

/* macros for field watch_pmu_lpcomp */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_lpcomp_field watch_pmu_lpcomp_field
 * @brief macros for field watch_pmu_lpcomp
 * @details valid to immediately breakout on pmu lpcomp threshold crossing
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__SHIFT            9
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__WIDTH            1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__MASK   0x00000200U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_LPCOMP__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field watch_pmu_timer */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_pmu_timer_field watch_pmu_timer_field
 * @brief macros for field watch_pmu_timer
 * @details valid to immediately breakout on pmu timer expiring
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__SHIFT            10
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__WIDTH             1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__MASK    0x00000400U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_PMU_TIMER__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field watch_energy4CPU */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_energy4CPU_field watch_energy4CPU_field
 * @brief macros for field watch_energy4CPU
 * @details valid to immediately breakout on pmu asserting energy4CPU
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__SHIFT           11
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__WIDTH            1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__MASK   0x00000800U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4CPU__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field watch_energy4TX */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_energy4TX_field watch_energy4TX_field
 * @brief macros for field watch_energy4TX
 * @details valid to immediately breakout on pmu asserting energy4TX
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__SHIFT            12
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__WIDTH             1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__MASK    0x00001000U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENERGY4TX__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field watch_endoflife */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_endoflife_field watch_endoflife_field
 * @brief macros for field watch_endoflife
 * @details valid to immediately breakout on pmu asserting endoflife
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__SHIFT            13
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__WIDTH             1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__MASK    0x00002000U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_ENDOFLIFE__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field watch_brownout */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_brownout_field watch_brownout_field
 * @brief macros for field watch_brownout
 * @details valid to immediately breakout on pmu asserting brownout
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__SHIFT             14
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__WIDTH              1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__MASK     0x00004000U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_BROWNOUT__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field watch_wurx */
/**
 * @defgroup at_apb_pseq_perth_regs_core_watch_wurx_field watch_wurx_field
 * @brief macros for field watch_wurx
 * @details valid to immediately breakout on multiple wurx detects in certain amount of time
 * @{
 */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__SHIFT                 15
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__WIDTH                  1
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__MASK         0x00008000U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WATCH_WURX__RESET_VALUE  0x00000001U
/** @} */
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__TYPE                        uint32_t
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__READ                     0x0000ffffU
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__WRITE                    0x0000ffffU
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__PRESERVED                0x00000000U
#define PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK__RESET_VALUE              0x0000ffffU

#endif /* __PSEQ_SENSOR_HUB_IMM_BREAKOUT_MASK_MACRO__ */

/** @} end of sensor_hub_imm_breakout_mask */

/* macros for BlueprintGlobalNameSpace::PSEQ_fsm_tuningA */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fsm_tuningA fsm_tuningA
 * @brief Contains register fields associated with fsm_tuningA. definitions.
 * @{
 */
#ifndef __PSEQ_FSM_TUNINGA_MACRO__
#define __PSEQ_FSM_TUNINGA_MACRO__

/* macros for field cnt0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt0_field cnt0_field
 * @brief macros for field cnt0
 * @details additional clk_lpc cycles to wait in states tied to cnt0
 * @{
 */
#define PSEQ_FSM_TUNINGA__CNT0__SHIFT                                         0
#define PSEQ_FSM_TUNINGA__CNT0__WIDTH                                         8
#define PSEQ_FSM_TUNINGA__CNT0__MASK                                0x000000ffU
#define PSEQ_FSM_TUNINGA__CNT0__READ(src)       ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGA__CNT0__WRITE(src)      ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGA__CNT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PSEQ_FSM_TUNINGA__CNT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PSEQ_FSM_TUNINGA__CNT0__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt1_field cnt1_field
 * @brief macros for field cnt1
 * @details additional clk_lpc cycles to wait in states tied to cnt1
 * @{
 */
#define PSEQ_FSM_TUNINGA__CNT1__SHIFT                                         8
#define PSEQ_FSM_TUNINGA__CNT1__WIDTH                                         8
#define PSEQ_FSM_TUNINGA__CNT1__MASK                                0x0000ff00U
#define PSEQ_FSM_TUNINGA__CNT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PSEQ_FSM_TUNINGA__CNT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGA__CNT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGA__CNT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PSEQ_FSM_TUNINGA__CNT1__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt2_field cnt2_field
 * @brief macros for field cnt2
 * @details additional clk_lpc cycles to wait in states tied to cnt2
 * @{
 */
#define PSEQ_FSM_TUNINGA__CNT2__SHIFT                                        16
#define PSEQ_FSM_TUNINGA__CNT2__WIDTH                                         8
#define PSEQ_FSM_TUNINGA__CNT2__MASK                                0x00ff0000U
#define PSEQ_FSM_TUNINGA__CNT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PSEQ_FSM_TUNINGA__CNT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGA__CNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGA__CNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define PSEQ_FSM_TUNINGA__CNT2__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt3_field cnt3_field
 * @brief macros for field cnt3
 * @details additional clk_lpc cycles to wait in states tied to cnt3
 * @{
 */
#define PSEQ_FSM_TUNINGA__CNT3__SHIFT                                        24
#define PSEQ_FSM_TUNINGA__CNT3__WIDTH                                         8
#define PSEQ_FSM_TUNINGA__CNT3__MASK                                0xff000000U
#define PSEQ_FSM_TUNINGA__CNT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define PSEQ_FSM_TUNINGA__CNT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define PSEQ_FSM_TUNINGA__CNT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define PSEQ_FSM_TUNINGA__CNT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define PSEQ_FSM_TUNINGA__CNT3__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_FSM_TUNINGA__TYPE                                         uint32_t
#define PSEQ_FSM_TUNINGA__READ                                      0xffffffffU
#define PSEQ_FSM_TUNINGA__WRITE                                     0xffffffffU
#define PSEQ_FSM_TUNINGA__PRESERVED                                 0x00000000U
#define PSEQ_FSM_TUNINGA__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_FSM_TUNINGA_MACRO__ */

/** @} end of fsm_tuningA */

/* macros for BlueprintGlobalNameSpace::PSEQ_fsm_tuningB */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fsm_tuningB fsm_tuningB
 * @brief Contains register fields associated with fsm_tuningB. definitions.
 * @{
 */
#ifndef __PSEQ_FSM_TUNINGB_MACRO__
#define __PSEQ_FSM_TUNINGB_MACRO__

/* macros for field cnt4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt4_field cnt4_field
 * @brief macros for field cnt4
 * @details additional clk_lpc cycles to wait in states tied to cnt4
 * @{
 */
#define PSEQ_FSM_TUNINGB__CNT4__SHIFT                                         0
#define PSEQ_FSM_TUNINGB__CNT4__WIDTH                                         8
#define PSEQ_FSM_TUNINGB__CNT4__MASK                                0x000000ffU
#define PSEQ_FSM_TUNINGB__CNT4__READ(src)       ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGB__CNT4__WRITE(src)      ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGB__CNT4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PSEQ_FSM_TUNINGB__CNT4__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PSEQ_FSM_TUNINGB__CNT4__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt5_field cnt5_field
 * @brief macros for field cnt5
 * @details additional clk_lpc cycles to wait in states tied to cnt5
 * @{
 */
#define PSEQ_FSM_TUNINGB__CNT5__SHIFT                                         8
#define PSEQ_FSM_TUNINGB__CNT5__WIDTH                                         8
#define PSEQ_FSM_TUNINGB__CNT5__MASK                                0x0000ff00U
#define PSEQ_FSM_TUNINGB__CNT5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PSEQ_FSM_TUNINGB__CNT5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGB__CNT5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGB__CNT5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PSEQ_FSM_TUNINGB__CNT5__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt6 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt6_field cnt6_field
 * @brief macros for field cnt6
 * @details additional clk_lpc cycles to wait in states tied to cnt6
 * @{
 */
#define PSEQ_FSM_TUNINGB__CNT6__SHIFT                                        16
#define PSEQ_FSM_TUNINGB__CNT6__WIDTH                                         8
#define PSEQ_FSM_TUNINGB__CNT6__MASK                                0x00ff0000U
#define PSEQ_FSM_TUNINGB__CNT6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PSEQ_FSM_TUNINGB__CNT6__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGB__CNT6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGB__CNT6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define PSEQ_FSM_TUNINGB__CNT6__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt7 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt7_field cnt7_field
 * @brief macros for field cnt7
 * @details additional clk_lpc cycles to wait in states tied to cnt7
 * @{
 */
#define PSEQ_FSM_TUNINGB__CNT7__SHIFT                                        24
#define PSEQ_FSM_TUNINGB__CNT7__WIDTH                                         8
#define PSEQ_FSM_TUNINGB__CNT7__MASK                                0xff000000U
#define PSEQ_FSM_TUNINGB__CNT7__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define PSEQ_FSM_TUNINGB__CNT7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define PSEQ_FSM_TUNINGB__CNT7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define PSEQ_FSM_TUNINGB__CNT7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define PSEQ_FSM_TUNINGB__CNT7__RESET_VALUE                         0x00000000U
/** @} */
#define PSEQ_FSM_TUNINGB__TYPE                                         uint32_t
#define PSEQ_FSM_TUNINGB__READ                                      0xffffffffU
#define PSEQ_FSM_TUNINGB__WRITE                                     0xffffffffU
#define PSEQ_FSM_TUNINGB__PRESERVED                                 0x00000000U
#define PSEQ_FSM_TUNINGB__RESET_VALUE                               0x00000000U

#endif /* __PSEQ_FSM_TUNINGB_MACRO__ */

/** @} end of fsm_tuningB */

/* macros for BlueprintGlobalNameSpace::PSEQ_fsm_tuningC */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fsm_tuningC fsm_tuningC
 * @brief Contains register fields associated with fsm_tuningC. definitions.
 * @{
 */
#ifndef __PSEQ_FSM_TUNINGC_MACRO__
#define __PSEQ_FSM_TUNINGC_MACRO__

/* macros for field cnt8 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt8_field cnt8_field
 * @brief macros for field cnt8
 * @details additional clk_lpc cycles to wait in states tied to cnt8
 * @{
 */
#define PSEQ_FSM_TUNINGC__CNT8__SHIFT                                         0
#define PSEQ_FSM_TUNINGC__CNT8__WIDTH                                         8
#define PSEQ_FSM_TUNINGC__CNT8__MASK                                0x000000ffU
#define PSEQ_FSM_TUNINGC__CNT8__READ(src)       ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGC__CNT8__WRITE(src)      ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGC__CNT8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PSEQ_FSM_TUNINGC__CNT8__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PSEQ_FSM_TUNINGC__CNT8__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt9 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt9_field cnt9_field
 * @brief macros for field cnt9
 * @details additional clk_lpc cycles to wait in states tied to cnt9
 * @{
 */
#define PSEQ_FSM_TUNINGC__CNT9__SHIFT                                         8
#define PSEQ_FSM_TUNINGC__CNT9__WIDTH                                         8
#define PSEQ_FSM_TUNINGC__CNT9__MASK                                0x0000ff00U
#define PSEQ_FSM_TUNINGC__CNT9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PSEQ_FSM_TUNINGC__CNT9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGC__CNT9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGC__CNT9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PSEQ_FSM_TUNINGC__CNT9__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field cnt10 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt10_field cnt10_field
 * @brief macros for field cnt10
 * @details additional clk_lpc cycles to wait in states tied to cnt10
 * @{
 */
#define PSEQ_FSM_TUNINGC__CNT10__SHIFT                                       16
#define PSEQ_FSM_TUNINGC__CNT10__WIDTH                                        8
#define PSEQ_FSM_TUNINGC__CNT10__MASK                               0x00ff0000U
#define PSEQ_FSM_TUNINGC__CNT10__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PSEQ_FSM_TUNINGC__CNT10__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGC__CNT10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGC__CNT10__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define PSEQ_FSM_TUNINGC__CNT10__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field cnt11 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_cnt11_field cnt11_field
 * @brief macros for field cnt11
 * @details additional clk_lpc cycles to wait in states tied to cnt11
 * @{
 */
#define PSEQ_FSM_TUNINGC__CNT11__SHIFT                                       24
#define PSEQ_FSM_TUNINGC__CNT11__WIDTH                                        8
#define PSEQ_FSM_TUNINGC__CNT11__MASK                               0xff000000U
#define PSEQ_FSM_TUNINGC__CNT11__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define PSEQ_FSM_TUNINGC__CNT11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define PSEQ_FSM_TUNINGC__CNT11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define PSEQ_FSM_TUNINGC__CNT11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define PSEQ_FSM_TUNINGC__CNT11__RESET_VALUE                        0x00000017U
/** @} */
#define PSEQ_FSM_TUNINGC__TYPE                                         uint32_t
#define PSEQ_FSM_TUNINGC__READ                                      0xffffffffU
#define PSEQ_FSM_TUNINGC__WRITE                                     0xffffffffU
#define PSEQ_FSM_TUNINGC__PRESERVED                                 0x00000000U
#define PSEQ_FSM_TUNINGC__RESET_VALUE                               0x17000000U

#endif /* __PSEQ_FSM_TUNINGC_MACRO__ */

/** @} end of fsm_tuningC */

/* macros for BlueprintGlobalNameSpace::PSEQ_fsm_tuningRA */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fsm_tuningRA fsm_tuningRA
 * @brief Contains register fields associated with fsm_tuningRA. definitions.
 * @{
 */
#ifndef __PSEQ_FSM_TUNINGRA_MACRO__
#define __PSEQ_FSM_TUNINGRA_MACRO__

/* macros for field rcnt0 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt0_field rcnt0_field
 * @brief macros for field rcnt0
 * @details additional clk_lpc cycles to wait in states tied to rcnt0
 * @{
 */
#define PSEQ_FSM_TUNINGRA__RCNT0__SHIFT                                       0
#define PSEQ_FSM_TUNINGRA__RCNT0__WIDTH                                       8
#define PSEQ_FSM_TUNINGRA__RCNT0__MASK                              0x000000ffU
#define PSEQ_FSM_TUNINGRA__RCNT0__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGRA__RCNT0__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGRA__RCNT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PSEQ_FSM_TUNINGRA__RCNT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PSEQ_FSM_TUNINGRA__RCNT0__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcnt1 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt1_field rcnt1_field
 * @brief macros for field rcnt1
 * @details additional clk_lpc cycles to wait in states tied to rcnt1
 * @{
 */
#define PSEQ_FSM_TUNINGRA__RCNT1__SHIFT                                       8
#define PSEQ_FSM_TUNINGRA__RCNT1__WIDTH                                       8
#define PSEQ_FSM_TUNINGRA__RCNT1__MASK                              0x0000ff00U
#define PSEQ_FSM_TUNINGRA__RCNT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PSEQ_FSM_TUNINGRA__RCNT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGRA__RCNT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGRA__RCNT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PSEQ_FSM_TUNINGRA__RCNT1__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcnt2 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt2_field rcnt2_field
 * @brief macros for field rcnt2
 * @details additional clk_lpc cycles to wait in states tied to rcnt2
 * @{
 */
#define PSEQ_FSM_TUNINGRA__RCNT2__SHIFT                                      16
#define PSEQ_FSM_TUNINGRA__RCNT2__WIDTH                                       8
#define PSEQ_FSM_TUNINGRA__RCNT2__MASK                              0x00ff0000U
#define PSEQ_FSM_TUNINGRA__RCNT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PSEQ_FSM_TUNINGRA__RCNT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGRA__RCNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGRA__RCNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define PSEQ_FSM_TUNINGRA__RCNT2__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcnt3 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt3_field rcnt3_field
 * @brief macros for field rcnt3
 * @details additional clk_lpc cycles to wait in states tied to rcnt3
 * @{
 */
#define PSEQ_FSM_TUNINGRA__RCNT3__SHIFT                                      24
#define PSEQ_FSM_TUNINGRA__RCNT3__WIDTH                                       8
#define PSEQ_FSM_TUNINGRA__RCNT3__MASK                              0xff000000U
#define PSEQ_FSM_TUNINGRA__RCNT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define PSEQ_FSM_TUNINGRA__RCNT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define PSEQ_FSM_TUNINGRA__RCNT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define PSEQ_FSM_TUNINGRA__RCNT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define PSEQ_FSM_TUNINGRA__RCNT3__RESET_VALUE                       0x00000000U
/** @} */
#define PSEQ_FSM_TUNINGRA__TYPE                                        uint32_t
#define PSEQ_FSM_TUNINGRA__READ                                     0xffffffffU
#define PSEQ_FSM_TUNINGRA__WRITE                                    0xffffffffU
#define PSEQ_FSM_TUNINGRA__PRESERVED                                0x00000000U
#define PSEQ_FSM_TUNINGRA__RESET_VALUE                              0x00000000U

#endif /* __PSEQ_FSM_TUNINGRA_MACRO__ */

/** @} end of fsm_tuningRA */

/* macros for BlueprintGlobalNameSpace::PSEQ_fsm_tuningRB */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fsm_tuningRB fsm_tuningRB
 * @brief Contains register fields associated with fsm_tuningRB. definitions.
 * @{
 */
#ifndef __PSEQ_FSM_TUNINGRB_MACRO__
#define __PSEQ_FSM_TUNINGRB_MACRO__

/* macros for field rcnt4 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt4_field rcnt4_field
 * @brief macros for field rcnt4
 * @details additional clk_lpc cycles to wait in states tied to rcnt4
 * @{
 */
#define PSEQ_FSM_TUNINGRB__RCNT4__SHIFT                                       0
#define PSEQ_FSM_TUNINGRB__RCNT4__WIDTH                                       8
#define PSEQ_FSM_TUNINGRB__RCNT4__MASK                              0x000000ffU
#define PSEQ_FSM_TUNINGRB__RCNT4__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGRB__RCNT4__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGRB__RCNT4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PSEQ_FSM_TUNINGRB__RCNT4__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PSEQ_FSM_TUNINGRB__RCNT4__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcnt5 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt5_field rcnt5_field
 * @brief macros for field rcnt5
 * @details additional clk_lpc cycles to wait in states tied to rcnt5
 * @{
 */
#define PSEQ_FSM_TUNINGRB__RCNT5__SHIFT                                       8
#define PSEQ_FSM_TUNINGRB__RCNT5__WIDTH                                       8
#define PSEQ_FSM_TUNINGRB__RCNT5__MASK                              0x0000ff00U
#define PSEQ_FSM_TUNINGRB__RCNT5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PSEQ_FSM_TUNINGRB__RCNT5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGRB__RCNT5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGRB__RCNT5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PSEQ_FSM_TUNINGRB__RCNT5__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcnt6 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt6_field rcnt6_field
 * @brief macros for field rcnt6
 * @details additional clk_lpc cycles to wait in states tied to rcnt6
 * @{
 */
#define PSEQ_FSM_TUNINGRB__RCNT6__SHIFT                                      16
#define PSEQ_FSM_TUNINGRB__RCNT6__WIDTH                                       8
#define PSEQ_FSM_TUNINGRB__RCNT6__MASK                              0x00ff0000U
#define PSEQ_FSM_TUNINGRB__RCNT6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PSEQ_FSM_TUNINGRB__RCNT6__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGRB__RCNT6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PSEQ_FSM_TUNINGRB__RCNT6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define PSEQ_FSM_TUNINGRB__RCNT6__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcnt7 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt7_field rcnt7_field
 * @brief macros for field rcnt7
 * @details additional clk_lpc cycles to wait in states tied to rcnt7
 * @{
 */
#define PSEQ_FSM_TUNINGRB__RCNT7__SHIFT                                      24
#define PSEQ_FSM_TUNINGRB__RCNT7__WIDTH                                       8
#define PSEQ_FSM_TUNINGRB__RCNT7__MASK                              0xff000000U
#define PSEQ_FSM_TUNINGRB__RCNT7__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define PSEQ_FSM_TUNINGRB__RCNT7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define PSEQ_FSM_TUNINGRB__RCNT7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define PSEQ_FSM_TUNINGRB__RCNT7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define PSEQ_FSM_TUNINGRB__RCNT7__RESET_VALUE                       0x00000000U
/** @} */
#define PSEQ_FSM_TUNINGRB__TYPE                                        uint32_t
#define PSEQ_FSM_TUNINGRB__READ                                     0xffffffffU
#define PSEQ_FSM_TUNINGRB__WRITE                                    0xffffffffU
#define PSEQ_FSM_TUNINGRB__PRESERVED                                0x00000000U
#define PSEQ_FSM_TUNINGRB__RESET_VALUE                              0x00000000U

#endif /* __PSEQ_FSM_TUNINGRB_MACRO__ */

/** @} end of fsm_tuningRB */

/* macros for BlueprintGlobalNameSpace::PSEQ_fsm_tuningRC */
/**
 * @defgroup at_apb_pseq_perth_regs_core_fsm_tuningRC fsm_tuningRC
 * @brief Contains register fields associated with fsm_tuningRC. definitions.
 * @{
 */
#ifndef __PSEQ_FSM_TUNINGRC_MACRO__
#define __PSEQ_FSM_TUNINGRC_MACRO__

/* macros for field rcnt8 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt8_field rcnt8_field
 * @brief macros for field rcnt8
 * @details additional clk_lpc cycles to wait in states tied to rcnt8
 * @{
 */
#define PSEQ_FSM_TUNINGRC__RCNT8__SHIFT                                       0
#define PSEQ_FSM_TUNINGRC__RCNT8__WIDTH                                       8
#define PSEQ_FSM_TUNINGRC__RCNT8__MASK                              0x000000ffU
#define PSEQ_FSM_TUNINGRC__RCNT8__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGRC__RCNT8__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define PSEQ_FSM_TUNINGRC__RCNT8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PSEQ_FSM_TUNINGRC__RCNT8__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PSEQ_FSM_TUNINGRC__RCNT8__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field rcnt9 */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rcnt9_field rcnt9_field
 * @brief macros for field rcnt9
 * @details additional clk_lpc cycles to wait in states tied to rcnt9
 * @{
 */
#define PSEQ_FSM_TUNINGRC__RCNT9__SHIFT                                       8
#define PSEQ_FSM_TUNINGRC__RCNT9__WIDTH                                       8
#define PSEQ_FSM_TUNINGRC__RCNT9__MASK                              0x0000ff00U
#define PSEQ_FSM_TUNINGRC__RCNT9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PSEQ_FSM_TUNINGRC__RCNT9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGRC__RCNT9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PSEQ_FSM_TUNINGRC__RCNT9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define PSEQ_FSM_TUNINGRC__RCNT9__RESET_VALUE                       0x00000000U
/** @} */
#define PSEQ_FSM_TUNINGRC__TYPE                                        uint32_t
#define PSEQ_FSM_TUNINGRC__READ                                     0x0000ffffU
#define PSEQ_FSM_TUNINGRC__WRITE                                    0x0000ffffU
#define PSEQ_FSM_TUNINGRC__PRESERVED                                0x00000000U
#define PSEQ_FSM_TUNINGRC__RESET_VALUE                              0x00000000U

#endif /* __PSEQ_FSM_TUNINGRC_MACRO__ */

/** @} end of fsm_tuningRC */

/* macros for BlueprintGlobalNameSpace::PSEQ_wdog_control */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wdog_control wdog_control
 * @brief control signals for 32KHz watchdog timer definitions.
 * @{
 */
#ifndef __PSEQ_WDOG_CONTROL_MACRO__
#define __PSEQ_WDOG_CONTROL_MACRO__

/* macros for field disable */
/**
 * @defgroup at_apb_pseq_perth_regs_core_disable_field disable_field
 * @brief macros for field disable
 * @details 1= disables wdog timer
 * @{
 */
#define PSEQ_WDOG_CONTROL__DISABLE__SHIFT                                     0
#define PSEQ_WDOG_CONTROL__DISABLE__WIDTH                                     1
#define PSEQ_WDOG_CONTROL__DISABLE__MASK                            0x00000001U
#define PSEQ_WDOG_CONTROL__DISABLE__READ(src)   ((uint32_t)(src) & 0x00000001U)
#define PSEQ_WDOG_CONTROL__DISABLE__WRITE(src)  ((uint32_t)(src) & 0x00000001U)
#define PSEQ_WDOG_CONTROL__DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_WDOG_CONTROL__DISABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_WDOG_CONTROL__DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_WDOG_CONTROL__DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_WDOG_CONTROL__DISABLE__RESET_VALUE                     0x00000001U
/** @} */

/* macros for field timer_val_sel */
/**
 * @defgroup at_apb_pseq_perth_regs_core_timer_val_sel_field timer_val_sel_field
 * @brief macros for field timer_val_sel
 * @details selects timer value to load  1= 1-sec 0= 100-msec in 32KHz cycles
 * @{
 */
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__SHIFT                               1
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__WIDTH                               1
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__MASK                      0x00000002U
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_WDOG_CONTROL__TIMER_VAL_SEL__RESET_VALUE               0x00000000U
/** @} */
#define PSEQ_WDOG_CONTROL__TYPE                                        uint32_t
#define PSEQ_WDOG_CONTROL__READ                                     0x00000003U
#define PSEQ_WDOG_CONTROL__WRITE                                    0x00000003U
#define PSEQ_WDOG_CONTROL__PRESERVED                                0x00000000U
#define PSEQ_WDOG_CONTROL__RESET_VALUE                              0x00000001U

#endif /* __PSEQ_WDOG_CONTROL_MACRO__ */

/** @} end of wdog_control */

/* macros for BlueprintGlobalNameSpace::PSEQ_wdog_timer */
/**
 * @defgroup at_apb_pseq_perth_regs_core_wdog_timer wdog_timer
 * @brief Read current 32KHz watchdog timer value definitions.
 * @{
 */
#ifndef __PSEQ_WDOG_TIMER_MACRO__
#define __PSEQ_WDOG_TIMER_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_pseq_perth_regs_core_val_field val_field
 * @brief macros for field val
 * @details this value is on 32kHz domain; read twice and check value is the same; if it's not, reread
 * @{
 */
#define PSEQ_WDOG_TIMER__VAL__SHIFT                                           0
#define PSEQ_WDOG_TIMER__VAL__WIDTH                                          16
#define PSEQ_WDOG_TIMER__VAL__MASK                                  0x0000ffffU
#define PSEQ_WDOG_TIMER__VAL__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PSEQ_WDOG_TIMER__VAL__RESET_VALUE                           0x00000000U
/** @} */
#define PSEQ_WDOG_TIMER__TYPE                                          uint32_t
#define PSEQ_WDOG_TIMER__READ                                       0x0000ffffU
#define PSEQ_WDOG_TIMER__PRESERVED                                  0x00000000U
#define PSEQ_WDOG_TIMER__RESET_VALUE                                0x00000000U

#endif /* __PSEQ_WDOG_TIMER_MACRO__ */

/** @} end of wdog_timer */

/* macros for BlueprintGlobalNameSpace::PSEQ_burnin_control */
/**
 * @defgroup at_apb_pseq_perth_regs_core_burnin_control burnin_control
 * @brief control signals for burnin definitions.
 * @{
 */
#ifndef __PSEQ_BURNIN_CONTROL_MACRO__
#define __PSEQ_BURNIN_CONTROL_MACRO__

/* macros for field internal_scan */
/**
 * @defgroup at_apb_pseq_perth_regs_core_internal_scan_field internal_scan_field
 * @brief macros for field internal_scan
 * @{
 */
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__SHIFT                             0
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__WIDTH                             1
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__MASK                    0x00000001U
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN__RESET_VALUE             0x00000000U
/** @} */

/* macros for field internal_scan_cfg */
/**
 * @defgroup at_apb_pseq_perth_regs_core_internal_scan_cfg_field internal_scan_cfg_field
 * @brief macros for field internal_scan_cfg
 * @details determines source of scan chains when in internal scan [5:4] scan chain 2: 0=off 1=toggle flop 2,3=prbs15 [3:2] scan chain 1: 0=off 1=toggle flop 2,3=prbs15 [1:0] scan chain 0: 0=off 1=toggle flop 2,3=prbs15
 * @{
 */
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__SHIFT                         1
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__WIDTH                         6
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__MASK                0x0000007eU
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000007eU) >> 1)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000007eU)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007eU) | (((uint32_t)(src) <<\
                    1) & 0x0000007eU)
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000007eU)))
#define PSEQ_BURNIN_CONTROL__INTERNAL_SCAN_CFG__RESET_VALUE         0x00000000U
/** @} */
#define PSEQ_BURNIN_CONTROL__TYPE                                      uint32_t
#define PSEQ_BURNIN_CONTROL__READ                                   0x0000007fU
#define PSEQ_BURNIN_CONTROL__WRITE                                  0x0000007fU
#define PSEQ_BURNIN_CONTROL__PRESERVED                              0x00000000U
#define PSEQ_BURNIN_CONTROL__RESET_VALUE                            0x00000000U

#endif /* __PSEQ_BURNIN_CONTROL_MACRO__ */

/** @} end of burnin_control */

/* macros for BlueprintGlobalNameSpace::PSEQ_frc_status */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_status frc_status
 * @brief Contains register fields associated with frc_status. definitions.
 * @{
 */
#ifndef __PSEQ_FRC_STATUS_MACRO__
#define __PSEQ_FRC_STATUS_MACRO__

/* macros for field frc_match0_enabled */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_enabled_field frc_match0_enabled_field
 * @brief macros for field frc_match0_enabled
 * @details indicates that frc_match0_val is being checked against current_real_time
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH0_ENABLED__SHIFT                            0
#define PSEQ_FRC_STATUS__FRC_MATCH0_ENABLED__WIDTH                            1
#define PSEQ_FRC_STATUS__FRC_MATCH0_ENABLED__MASK                   0x00000001U
#define PSEQ_FRC_STATUS__FRC_MATCH0_ENABLED__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PSEQ_FRC_STATUS__FRC_MATCH0_ENABLED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PSEQ_FRC_STATUS__FRC_MATCH0_ENABLED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PSEQ_FRC_STATUS__FRC_MATCH0_ENABLED__RESET_VALUE            0x00000000U
/** @} */

/* macros for field frc_match1_enabled */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_enabled_field frc_match1_enabled_field
 * @brief macros for field frc_match1_enabled
 * @details indicates that frc_match1_val is being checked against current_real_time
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH1_ENABLED__SHIFT                            1
#define PSEQ_FRC_STATUS__FRC_MATCH1_ENABLED__WIDTH                            1
#define PSEQ_FRC_STATUS__FRC_MATCH1_ENABLED__MASK                   0x00000002U
#define PSEQ_FRC_STATUS__FRC_MATCH1_ENABLED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PSEQ_FRC_STATUS__FRC_MATCH1_ENABLED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PSEQ_FRC_STATUS__FRC_MATCH1_ENABLED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PSEQ_FRC_STATUS__FRC_MATCH1_ENABLED__RESET_VALUE            0x00000000U
/** @} */

/* macros for field frc_match0_pending */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_pending_field frc_match0_pending_field
 * @brief macros for field frc_match0_pending
 * @details indicates that there is a pending request to wait for current_real_time to match frc_match1_val
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH0_PENDING__SHIFT                            2
#define PSEQ_FRC_STATUS__FRC_MATCH0_PENDING__WIDTH                            1
#define PSEQ_FRC_STATUS__FRC_MATCH0_PENDING__MASK                   0x00000004U
#define PSEQ_FRC_STATUS__FRC_MATCH0_PENDING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PSEQ_FRC_STATUS__FRC_MATCH0_PENDING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PSEQ_FRC_STATUS__FRC_MATCH0_PENDING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PSEQ_FRC_STATUS__FRC_MATCH0_PENDING__RESET_VALUE            0x00000000U
/** @} */

/* macros for field frc_match1_pending */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_pending_field frc_match1_pending_field
 * @brief macros for field frc_match1_pending
 * @details indicates that there is a pending request to wait for current_real_time to match frc_match0_val
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH1_PENDING__SHIFT                            3
#define PSEQ_FRC_STATUS__FRC_MATCH1_PENDING__WIDTH                            1
#define PSEQ_FRC_STATUS__FRC_MATCH1_PENDING__MASK                   0x00000008U
#define PSEQ_FRC_STATUS__FRC_MATCH1_PENDING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PSEQ_FRC_STATUS__FRC_MATCH1_PENDING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PSEQ_FRC_STATUS__FRC_MATCH1_PENDING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PSEQ_FRC_STATUS__FRC_MATCH1_PENDING__RESET_VALUE            0x00000000U
/** @} */

/* macros for field frc_match0_rstn_slow */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_rstn_slow_field frc_match0_rstn_slow_field
 * @brief macros for field frc_match0_rstn_slow
 * @details active low. 0=frc slow domain in reset. 1=otherwise
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_SLOW__SHIFT                          4
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_SLOW__WIDTH                          1
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_SLOW__MASK                 0x00000010U
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_SLOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_SLOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_SLOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_SLOW__RESET_VALUE          0x00000001U
/** @} */

/* macros for field frc_match1_rstn_slow */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_rstn_slow_field frc_match1_rstn_slow_field
 * @brief macros for field frc_match1_rstn_slow
 * @details active low. 0=frc slow domain in reset. 1=otherwise
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_SLOW__SHIFT                          5
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_SLOW__WIDTH                          1
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_SLOW__MASK                 0x00000020U
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_SLOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_SLOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_SLOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_SLOW__RESET_VALUE          0x00000001U
/** @} */

/* macros for field frc_match0_rstn_fast */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match0_rstn_fast_field frc_match0_rstn_fast_field
 * @brief macros for field frc_match0_rstn_fast
 * @details active low. 0=frc fast domain in reset. 1=otherwise
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_FAST__SHIFT                          6
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_FAST__WIDTH                          1
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_FAST__MASK                 0x00000040U
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_FAST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_FAST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_FAST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PSEQ_FRC_STATUS__FRC_MATCH0_RSTN_FAST__RESET_VALUE          0x00000001U
/** @} */

/* macros for field frc_match1_rstn_fast */
/**
 * @defgroup at_apb_pseq_perth_regs_core_frc_match1_rstn_fast_field frc_match1_rstn_fast_field
 * @brief macros for field frc_match1_rstn_fast
 * @details active low. 0=frc fast domain in reset. 1=otherwise
 * @{
 */
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_FAST__SHIFT                          7
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_FAST__WIDTH                          1
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_FAST__MASK                 0x00000080U
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_FAST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_FAST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_FAST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PSEQ_FRC_STATUS__FRC_MATCH1_RSTN_FAST__RESET_VALUE          0x00000001U
/** @} */
#define PSEQ_FRC_STATUS__TYPE                                          uint32_t
#define PSEQ_FRC_STATUS__READ                                       0x000000ffU
#define PSEQ_FRC_STATUS__PRESERVED                                  0x00000000U
#define PSEQ_FRC_STATUS__RESET_VALUE                                0x000000f0U

#endif /* __PSEQ_FRC_STATUS_MACRO__ */

/** @} end of frc_status */

/* macros for BlueprintGlobalNameSpace::PSEQ_core_id */
/**
 * @defgroup at_apb_pseq_perth_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __PSEQ_CORE_ID_MACRO__
#define __PSEQ_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pseq_perth_regs_core_id_field id_field
 * @brief macros for field id
 * @details PSEQ in ASCII
 * @{
 */
#define PSEQ_CORE_ID__ID__SHIFT                                               0
#define PSEQ_CORE_ID__ID__WIDTH                                              32
#define PSEQ_CORE_ID__ID__MASK                                      0xffffffffU
#define PSEQ_CORE_ID__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_CORE_ID__ID__RESET_VALUE                               0x50534551U
/** @} */
#define PSEQ_CORE_ID__TYPE                                             uint32_t
#define PSEQ_CORE_ID__READ                                          0xffffffffU
#define PSEQ_CORE_ID__PRESERVED                                     0x00000000U
#define PSEQ_CORE_ID__RESET_VALUE                                   0x50534551U

#endif /* __PSEQ_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::PSEQ_rev_hash */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __PSEQ_REV_HASH_MACRO__
#define __PSEQ_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pseq_perth_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define PSEQ_REV_HASH__ID__SHIFT                                              0
#define PSEQ_REV_HASH__ID__WIDTH                                             32
#define PSEQ_REV_HASH__ID__MASK                                     0xffffffffU
#define PSEQ_REV_HASH__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_REV_HASH__ID__RESET_VALUE                              0x53d54d1fU
/** @} */
#define PSEQ_REV_HASH__TYPE                                            uint32_t
#define PSEQ_REV_HASH__READ                                         0xffffffffU
#define PSEQ_REV_HASH__PRESERVED                                    0x00000000U
#define PSEQ_REV_HASH__RESET_VALUE                                  0x53d54d1fU

#endif /* __PSEQ_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::PSEQ_rev_key */
/**
 * @defgroup at_apb_pseq_perth_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __PSEQ_REV_KEY_MACRO__
#define __PSEQ_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pseq_perth_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define PSEQ_REV_KEY__ID__SHIFT                                               0
#define PSEQ_REV_KEY__ID__WIDTH                                              32
#define PSEQ_REV_KEY__ID__MASK                                      0xffffffffU
#define PSEQ_REV_KEY__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define PSEQ_REV_KEY__ID__RESET_VALUE                               0x52455620U
/** @} */
#define PSEQ_REV_KEY__TYPE                                             uint32_t
#define PSEQ_REV_KEY__READ                                          0xffffffffU
#define PSEQ_REV_KEY__PRESERVED                                     0x00000000U
#define PSEQ_REV_KEY__RESET_VALUE                                   0x52455620U

#endif /* __PSEQ_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_PSEQ_PERTH_REGS_CORE */
#endif /* __REG_AT_APB_PSEQ_PERTH_REGS_CORE_H__ */
