/*                                                                           */
/* File:       at_apb_trng_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_trng_regs_core.rdl          */
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


#ifndef __REG_AT_APB_TRNG_REGS_CORE_H__
#define __REG_AT_APB_TRNG_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_TRNG_REGS_CORE at_apb_trng_regs_core
 * @ingroup AT_REG
 * @brief at_apb_trng_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::TRNG_control */
/**
 * @defgroup at_apb_trng_regs_core_control control
 * @brief Contains register fields associated with control. definitions.
 * @{
 */
#ifndef __TRNG_CONTROL_MACRO__
#define __TRNG_CONTROL_MACRO__

/* macros for field go */
/**
 * @defgroup at_apb_trng_regs_core_go_field go_field
 * @brief macros for field go
 * @details start the process of generating a true random number ; not self reseting
 * @{
 */
#define TRNG_CONTROL__GO__SHIFT                                               0
#define TRNG_CONTROL__GO__WIDTH                                               1
#define TRNG_CONTROL__GO__MASK                                      0x00000001U
#define TRNG_CONTROL__GO__READ(src)             ((uint32_t)(src) & 0x00000001U)
#define TRNG_CONTROL__GO__WRITE(src)            ((uint32_t)(src) & 0x00000001U)
#define TRNG_CONTROL__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define TRNG_CONTROL__GO__VERIFY(src)     (!(((uint32_t)(src) & ~0x00000001U)))
#define TRNG_CONTROL__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define TRNG_CONTROL__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define TRNG_CONTROL__GO__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field adc_capture_edge */
/**
 * @defgroup at_apb_trng_regs_core_adc_capture_edge_field adc_capture_edge_field
 * @brief macros for field adc_capture_edge
 * @details 0 = rising edge; 1 = falling edge
 * @{
 */
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__SHIFT                                 1
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__WIDTH                                 1
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__MASK                        0x00000002U
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define TRNG_CONTROL__ADC_CAPTURE_EDGE__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field lsb_source */
/**
 * @defgroup at_apb_trng_regs_core_lsb_source_field lsb_source_field
 * @brief macros for field lsb_source
 * @details 0 = rif.rif_i[0]; 1 = radio.adc_i[0]
 * @{
 */
#define TRNG_CONTROL__LSB_SOURCE__SHIFT                                       2
#define TRNG_CONTROL__LSB_SOURCE__WIDTH                                       1
#define TRNG_CONTROL__LSB_SOURCE__MASK                              0x00000004U
#define TRNG_CONTROL__LSB_SOURCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define TRNG_CONTROL__LSB_SOURCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define TRNG_CONTROL__LSB_SOURCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define TRNG_CONTROL__LSB_SOURCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define TRNG_CONTROL__LSB_SOURCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define TRNG_CONTROL__LSB_SOURCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define TRNG_CONTROL__LSB_SOURCE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field radio_gain_override */
/**
 * @defgroup at_apb_trng_regs_core_radio_gain_override_field radio_gain_override_field
 * @brief macros for field radio_gain_override
 * @{
 */
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__SHIFT                              3
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__WIDTH                              1
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__MASK                     0x00000008U
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define TRNG_CONTROL__RADIO_GAIN_OVERRIDE__RESET_VALUE              0x00000000U
/** @} */

/* macros for field launch_on_radio_up */
/**
 * @defgroup at_apb_trng_regs_core_launch_on_radio_up_field launch_on_radio_up_field
 * @brief macros for field launch_on_radio_up
 * @details when radio is first coming back from power down mode, generate automatically (without software intervension) a new random number; this core will assert the radio gain override pin, wait 50usec, and then start the bit gathering process
 * @{
 */
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__SHIFT                               4
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__WIDTH                               1
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__MASK                      0x00000010U
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define TRNG_CONTROL__LAUNCH_ON_RADIO_UP__RESET_VALUE               0x00000001U
/** @} */

/* macros for field block_force_radio_into_trng_mode */
/**
 * @defgroup at_apb_trng_regs_core_block_force_radio_into_trng_mode_field block_force_radio_into_trng_mode_field
 * @brief macros for field block_force_radio_into_trng_mode
 * @{
 */
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__SHIFT                 5
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__WIDTH                 1
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__MASK        0x00000020U
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define TRNG_CONTROL__BLOCK_FORCE_RADIO_INTO_TRNG_MODE__RESET_VALUE 0x00000000U
/** @} */

/* macros for field radio_warmup_cnt */
/**
 * @defgroup at_apb_trng_regs_core_radio_warmup_cnt_field radio_warmup_cnt_field
 * @brief macros for field radio_warmup_cnt
 * @details how long to wait for radio to warmup in clk_mpc cycles
 * @{
 */
#define TRNG_CONTROL__RADIO_WARMUP_CNT__SHIFT                                 6
#define TRNG_CONTROL__RADIO_WARMUP_CNT__WIDTH                                11
#define TRNG_CONTROL__RADIO_WARMUP_CNT__MASK                        0x0001ffc0U
#define TRNG_CONTROL__RADIO_WARMUP_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001ffc0U) >> 6)
#define TRNG_CONTROL__RADIO_WARMUP_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x0001ffc0U)
#define TRNG_CONTROL__RADIO_WARMUP_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001ffc0U) | (((uint32_t)(src) <<\
                    6) & 0x0001ffc0U)
#define TRNG_CONTROL__RADIO_WARMUP_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x0001ffc0U)))
#define TRNG_CONTROL__RADIO_WARMUP_CNT__RESET_VALUE                 0x00000400U
/** @} */
#define TRNG_CONTROL__TYPE                                             uint32_t
#define TRNG_CONTROL__READ                                          0x0001ffffU
#define TRNG_CONTROL__WRITE                                         0x0001ffffU
#define TRNG_CONTROL__PRESERVED                                     0x00000000U
#define TRNG_CONTROL__RESET_VALUE                                   0x00010010U

#endif /* __TRNG_CONTROL_MACRO__ */

/** @} end of control */

/* macros for BlueprintGlobalNameSpace::TRNG_status */
/**
 * @defgroup at_apb_trng_regs_core_status status
 * @brief Contains register fields associated with status. definitions.
 * @{
 */
#ifndef __TRNG_STATUS_MACRO__
#define __TRNG_STATUS_MACRO__

/* macros for field running */
/**
 * @defgroup at_apb_trng_regs_core_running_field running_field
 * @brief macros for field running
 * @details this status is asserted after RADIO warm-up
 * @{
 */
#define TRNG_STATUS__RUNNING__SHIFT                                           0
#define TRNG_STATUS__RUNNING__WIDTH                                           1
#define TRNG_STATUS__RUNNING__MASK                                  0x00000001U
#define TRNG_STATUS__RUNNING__READ(src)         ((uint32_t)(src) & 0x00000001U)
#define TRNG_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define TRNG_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define TRNG_STATUS__RUNNING__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field fsm_running */
/**
 * @defgroup at_apb_trng_regs_core_fsm_running_field fsm_running_field
 * @brief macros for field fsm_running
 * @details this status is asserted when the fsm gets out of ST_IDLE
 * @{
 */
#define TRNG_STATUS__FSM_RUNNING__SHIFT                                       1
#define TRNG_STATUS__FSM_RUNNING__WIDTH                                       1
#define TRNG_STATUS__FSM_RUNNING__MASK                              0x00000002U
#define TRNG_STATUS__FSM_RUNNING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define TRNG_STATUS__FSM_RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define TRNG_STATUS__FSM_RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define TRNG_STATUS__FSM_RUNNING__RESET_VALUE                       0x00000000U
/** @} */
#define TRNG_STATUS__TYPE                                              uint32_t
#define TRNG_STATUS__READ                                           0x00000003U
#define TRNG_STATUS__PRESERVED                                      0x00000000U
#define TRNG_STATUS__RESET_VALUE                                    0x00000000U

#endif /* __TRNG_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::TRNG_interrupt_status */
/**
 * @defgroup at_apb_trng_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __TRNG_INTERRUPT_STATUS_MACRO__
#define __TRNG_INTERRUPT_STATUS_MACRO__

/* macros for field trng_ready */
/**
 * @defgroup at_apb_trng_regs_core_trng_ready_field trng_ready_field
 * @brief macros for field trng_ready
 * @{
 */
#define TRNG_INTERRUPT_STATUS__TRNG_READY__SHIFT                              0
#define TRNG_INTERRUPT_STATUS__TRNG_READY__WIDTH                              1
#define TRNG_INTERRUPT_STATUS__TRNG_READY__MASK                     0x00000001U
#define TRNG_INTERRUPT_STATUS__TRNG_READY__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define TRNG_INTERRUPT_STATUS__TRNG_READY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define TRNG_INTERRUPT_STATUS__TRNG_READY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define TRNG_INTERRUPT_STATUS__TRNG_READY__RESET_VALUE              0x00000000U
/** @} */

/* macros for field trng_trouble */
/**
 * @defgroup at_apb_trng_regs_core_trng_trouble_field trng_trouble_field
 * @brief macros for field trng_trouble
 * @{
 */
#define TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__SHIFT                            1
#define TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__WIDTH                            1
#define TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__MASK                   0x00000002U
#define TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define TRNG_INTERRUPT_STATUS__TRNG_TROUBLE__RESET_VALUE            0x00000000U
/** @} */
#define TRNG_INTERRUPT_STATUS__TYPE                                    uint32_t
#define TRNG_INTERRUPT_STATUS__READ                                 0x00000003U
#define TRNG_INTERRUPT_STATUS__PRESERVED                            0x00000000U
#define TRNG_INTERRUPT_STATUS__RESET_VALUE                          0x00000000U

#endif /* __TRNG_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::TRNG_interrupt_mask */
/**
 * @defgroup at_apb_trng_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __TRNG_INTERRUPT_MASK_MACRO__
#define __TRNG_INTERRUPT_MASK_MACRO__

/* macros for field intrpt_mask */
/**
 * @defgroup at_apb_trng_regs_core_intrpt_mask_field intrpt_mask_field
 * @brief macros for field intrpt_mask
 * @details if nth bit set, the nth interrupt source is allowed to propogate to core's interrupt
 * @{
 */
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__SHIFT                               0
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__WIDTH                               2
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__MASK                      0x00000003U
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define TRNG_INTERRUPT_MASK__INTRPT_MASK__RESET_VALUE               0x00000003U
/** @} */
#define TRNG_INTERRUPT_MASK__TYPE                                      uint32_t
#define TRNG_INTERRUPT_MASK__READ                                   0x00000003U
#define TRNG_INTERRUPT_MASK__WRITE                                  0x00000003U
#define TRNG_INTERRUPT_MASK__PRESERVED                              0x00000000U
#define TRNG_INTERRUPT_MASK__RESET_VALUE                            0x00000003U

#endif /* __TRNG_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::TRNG_set_interrupt */
/**
 * @defgroup at_apb_trng_regs_core_set_interrupt set_interrupt
 * @brief Contains register fields associated with set_interrupt. definitions.
 * @{
 */
#ifndef __TRNG_SET_INTERRUPT_MACRO__
#define __TRNG_SET_INTERRUPT_MACRO__

/* macros for field intrpt_set */
/**
 * @defgroup at_apb_trng_regs_core_intrpt_set_field intrpt_set_field
 * @brief macros for field intrpt_set
 * @details not self clearing
 * @{
 */
#define TRNG_SET_INTERRUPT__INTRPT_SET__SHIFT                                 0
#define TRNG_SET_INTERRUPT__INTRPT_SET__WIDTH                                 2
#define TRNG_SET_INTERRUPT__INTRPT_SET__MASK                        0x00000003U
#define TRNG_SET_INTERRUPT__INTRPT_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define TRNG_SET_INTERRUPT__INTRPT_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define TRNG_SET_INTERRUPT__INTRPT_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define TRNG_SET_INTERRUPT__INTRPT_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define TRNG_SET_INTERRUPT__INTRPT_SET__RESET_VALUE                 0x00000000U
/** @} */
#define TRNG_SET_INTERRUPT__TYPE                                       uint32_t
#define TRNG_SET_INTERRUPT__READ                                    0x00000003U
#define TRNG_SET_INTERRUPT__WRITE                                   0x00000003U
#define TRNG_SET_INTERRUPT__PRESERVED                               0x00000000U
#define TRNG_SET_INTERRUPT__RESET_VALUE                             0x00000000U

#endif /* __TRNG_SET_INTERRUPT_MACRO__ */

/** @} end of set_interrupt */

/* macros for BlueprintGlobalNameSpace::TRNG_reset_interrupt */
/**
 * @defgroup at_apb_trng_regs_core_reset_interrupt reset_interrupt
 * @brief Contains register fields associated with reset_interrupt. definitions.
 * @{
 */
#ifndef __TRNG_RESET_INTERRUPT_MACRO__
#define __TRNG_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_apb_trng_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details not self clearing
 * @{
 */
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__SHIFT                             0
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__WIDTH                             2
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__MASK                    0x00000003U
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define TRNG_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE             0x00000000U
/** @} */
#define TRNG_RESET_INTERRUPT__TYPE                                     uint32_t
#define TRNG_RESET_INTERRUPT__READ                                  0x00000003U
#define TRNG_RESET_INTERRUPT__WRITE                                 0x00000003U
#define TRNG_RESET_INTERRUPT__PRESERVED                             0x00000000U
#define TRNG_RESET_INTERRUPT__RESET_VALUE                           0x00000000U

#endif /* __TRNG_RESET_INTERRUPT_MACRO__ */

/** @} end of reset_interrupt */

/* macros for BlueprintGlobalNameSpace::TRNG_trng */
/**
 * @defgroup at_apb_trng_regs_core_trng trng
 * @brief Contains register fields associated with trng. definitions.
 * @{
 */
#ifndef __TRNG_TRNG_MACRO__
#define __TRNG_TRNG_MACRO__

/* macros for field val */
/**
 * @defgroup at_apb_trng_regs_core_val_field val_field
 * @brief macros for field val
 * @details the generated true random number
 * @{
 */
#define TRNG_TRNG__VAL__SHIFT                                                 0
#define TRNG_TRNG__VAL__WIDTH                                                32
#define TRNG_TRNG__VAL__MASK                                        0xffffffffU
#define TRNG_TRNG__VAL__READ(src)               ((uint32_t)(src) & 0xffffffffU)
#define TRNG_TRNG__VAL__RESET_VALUE                                 0x00000000U
/** @} */
#define TRNG_TRNG__TYPE                                                uint32_t
#define TRNG_TRNG__READ                                             0xffffffffU
#define TRNG_TRNG__PRESERVED                                        0x00000000U
#define TRNG_TRNG__RESET_VALUE                                      0x00000000U

#endif /* __TRNG_TRNG_MACRO__ */

/** @} end of trng */

/* macros for BlueprintGlobalNameSpace::TRNG_core_id */
/**
 * @defgroup at_apb_trng_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __TRNG_CORE_ID_MACRO__
#define __TRNG_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_trng_regs_core_id_field id_field
 * @brief macros for field id
 * @details TRNG in ASCII
 * @{
 */
#define TRNG_CORE_ID__ID__SHIFT                                               0
#define TRNG_CORE_ID__ID__WIDTH                                              32
#define TRNG_CORE_ID__ID__MASK                                      0xffffffffU
#define TRNG_CORE_ID__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define TRNG_CORE_ID__ID__RESET_VALUE                               0x54524e47U
/** @} */
#define TRNG_CORE_ID__TYPE                                             uint32_t
#define TRNG_CORE_ID__READ                                          0xffffffffU
#define TRNG_CORE_ID__PRESERVED                                     0x00000000U
#define TRNG_CORE_ID__RESET_VALUE                                   0x54524e47U

#endif /* __TRNG_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of AT_APB_TRNG_REGS_CORE */
#endif /* __REG_AT_APB_TRNG_REGS_CORE_H__ */
