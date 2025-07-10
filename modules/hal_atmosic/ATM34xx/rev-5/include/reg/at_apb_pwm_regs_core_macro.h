/*                                                                           */
/* File:       at_apb_pwm_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_pwm_regs_core.rdl           */
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


#ifndef __REG_AT_APB_PWM_REGS_CORE_H__
#define __REG_AT_APB_PWM_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_PWM_REGS_CORE at_apb_pwm_regs_core
 * @ingroup AT_REG
 * @brief at_apb_pwm_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::PWM_pwm_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm_ctrl pwm_ctrl
 * @brief control signals for all pwm channels definitions.
 * @{
 */
#ifndef __PWM_PWM_CTRL_MACRO__
#define __PWM_PWM_CTRL_MACRO__

/* macros for field alt_ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_alt_ok_to_run_field alt_ok_to_run_field
 * @brief macros for field alt_ok_to_run
 * @details alternative mechanism to start pwm channels; useful if application requires all used pwm channels start together  [0] = start pwm0 channel  [1] = start pwm1 channel  [2] = start pwm2 channel  [3] = start pwm3 channel  [4] = start pwm4 channel  [5] = start pwm5 channel  [6] = start pwm6 channel  [7] = start pwm7 channel
 * @{
 */
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__SHIFT                                    0
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__WIDTH                                    8
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__MASK                           0x000000ffU
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__READ(src)  ((uint32_t)(src) & 0x000000ffU)
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__WRITE(src) ((uint32_t)(src) & 0x000000ffU)
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define PWM_PWM_CTRL__ALT_OK_TO_RUN__RESET_VALUE                    0x00000000U
/** @} */
#define PWM_PWM_CTRL__TYPE                                             uint32_t
#define PWM_PWM_CTRL__READ                                          0x000000ffU
#define PWM_PWM_CTRL__WRITE                                         0x000000ffU
#define PWM_PWM_CTRL__PRESERVED                                     0x00000000U
#define PWM_PWM_CTRL__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM_CTRL_MACRO__ */

/** @} end of pwm_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm0_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm0_ctrl pwm0_ctrl
 * @brief control signals for pwm0 channel definitions.
 * @{
 */
#ifndef __PWM_PWM0_CTRL_MACRO__
#define __PWM_PWM0_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM0_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM0_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM0_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM0_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM0_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM0_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM0_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM0_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM0_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM0_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM0_CTRL__MODE__SHIFT                                            1
#define PWM_PWM0_CTRL__MODE__WIDTH                                            2
#define PWM_PWM0_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM0_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM0_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM0_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM0_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM0_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM0_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM0_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM0_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM0_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM0_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM0_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM0_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM0_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM0_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM0_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM0_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM0_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM0_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM0_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM0_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM0_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM0_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM0_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM0_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM0_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM0_CTRL__TYPE                                            uint32_t
#define PWM_PWM0_CTRL__READ                                         0x0000001fU
#define PWM_PWM0_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM0_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM0_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM0_CTRL_MACRO__ */

/** @} end of pwm0_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm0_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm0_dur pwm0_dur
 * @brief durations config for pwm0 channel definitions.
 * @{
 */
#ifndef __PWM_PWM0_DUR_MACRO__
#define __PWM_PWM0_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM0_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM0_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM0_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM0_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM0_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM0_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM0_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM0_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM0_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM0_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM0_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM0_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM0_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM0_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM0_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM0_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM0_DUR__TYPE                                             uint32_t
#define PWM_PWM0_DUR__READ                                          0xffffffffU
#define PWM_PWM0_DUR__WRITE                                         0xffffffffU
#define PWM_PWM0_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM0_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM0_DUR_MACRO__ */

/** @} end of pwm0_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm0_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm0_cfg pwm0_cfg
 * @brief configuration for pwm0 channel definitions.
 * @{
 */
#ifndef __PWM_PWM0_CFG_MACRO__
#define __PWM_PWM0_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM0_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM0_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM0_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM0_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM0_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM0_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM0_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM0_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM0_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM0_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM0_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM0_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM0_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM0_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM0_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM0_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM0_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM0_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM0_CFG__TYPE                                             uint32_t
#define PWM_PWM0_CFG__READ                                          0x80003fffU
#define PWM_PWM0_CFG__WRITE                                         0x80003fffU
#define PWM_PWM0_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM0_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM0_CFG_MACRO__ */

/** @} end of pwm0_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_pwm1_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm1_ctrl pwm1_ctrl
 * @brief control signals for pwm1 channel definitions.
 * @{
 */
#ifndef __PWM_PWM1_CTRL_MACRO__
#define __PWM_PWM1_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM1_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM1_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM1_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM1_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM1_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM1_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM1_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM1_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM1_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM1_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM1_CTRL__MODE__SHIFT                                            1
#define PWM_PWM1_CTRL__MODE__WIDTH                                            2
#define PWM_PWM1_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM1_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM1_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM1_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM1_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM1_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM1_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM1_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM1_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM1_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM1_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM1_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM1_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM1_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM1_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM1_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM1_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM1_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM1_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM1_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM1_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM1_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM1_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM1_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM1_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM1_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM1_CTRL__TYPE                                            uint32_t
#define PWM_PWM1_CTRL__READ                                         0x0000001fU
#define PWM_PWM1_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM1_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM1_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM1_CTRL_MACRO__ */

/** @} end of pwm1_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm1_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm1_dur pwm1_dur
 * @brief durations config for pwm1 channel definitions.
 * @{
 */
#ifndef __PWM_PWM1_DUR_MACRO__
#define __PWM_PWM1_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM1_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM1_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM1_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM1_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM1_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM1_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM1_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM1_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM1_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM1_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM1_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM1_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM1_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM1_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM1_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM1_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM1_DUR__TYPE                                             uint32_t
#define PWM_PWM1_DUR__READ                                          0xffffffffU
#define PWM_PWM1_DUR__WRITE                                         0xffffffffU
#define PWM_PWM1_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM1_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM1_DUR_MACRO__ */

/** @} end of pwm1_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm1_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm1_cfg pwm1_cfg
 * @brief configuration for pwm1 channel definitions.
 * @{
 */
#ifndef __PWM_PWM1_CFG_MACRO__
#define __PWM_PWM1_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM1_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM1_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM1_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM1_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM1_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM1_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM1_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM1_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM1_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM1_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM1_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM1_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM1_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM1_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM1_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM1_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM1_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM1_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM1_CFG__TYPE                                             uint32_t
#define PWM_PWM1_CFG__READ                                          0x80003fffU
#define PWM_PWM1_CFG__WRITE                                         0x80003fffU
#define PWM_PWM1_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM1_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM1_CFG_MACRO__ */

/** @} end of pwm1_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_pwm2_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm2_ctrl pwm2_ctrl
 * @brief control signals for pwm2 channel definitions.
 * @{
 */
#ifndef __PWM_PWM2_CTRL_MACRO__
#define __PWM_PWM2_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM2_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM2_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM2_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM2_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM2_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM2_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM2_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM2_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM2_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM2_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM2_CTRL__MODE__SHIFT                                            1
#define PWM_PWM2_CTRL__MODE__WIDTH                                            2
#define PWM_PWM2_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM2_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM2_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM2_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM2_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM2_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM2_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM2_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM2_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM2_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM2_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM2_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM2_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM2_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM2_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM2_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM2_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM2_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM2_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM2_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM2_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM2_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM2_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM2_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM2_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM2_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM2_CTRL__TYPE                                            uint32_t
#define PWM_PWM2_CTRL__READ                                         0x0000001fU
#define PWM_PWM2_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM2_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM2_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM2_CTRL_MACRO__ */

/** @} end of pwm2_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm2_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm2_dur pwm2_dur
 * @brief durations config for pwm2 channel definitions.
 * @{
 */
#ifndef __PWM_PWM2_DUR_MACRO__
#define __PWM_PWM2_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM2_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM2_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM2_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM2_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM2_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM2_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM2_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM2_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM2_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM2_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM2_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM2_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM2_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM2_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM2_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM2_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM2_DUR__TYPE                                             uint32_t
#define PWM_PWM2_DUR__READ                                          0xffffffffU
#define PWM_PWM2_DUR__WRITE                                         0xffffffffU
#define PWM_PWM2_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM2_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM2_DUR_MACRO__ */

/** @} end of pwm2_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm2_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm2_cfg pwm2_cfg
 * @brief configuration for pwm2 channel definitions.
 * @{
 */
#ifndef __PWM_PWM2_CFG_MACRO__
#define __PWM_PWM2_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM2_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM2_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM2_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM2_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM2_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM2_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM2_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM2_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM2_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM2_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM2_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM2_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM2_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM2_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM2_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM2_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM2_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM2_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM2_CFG__TYPE                                             uint32_t
#define PWM_PWM2_CFG__READ                                          0x80003fffU
#define PWM_PWM2_CFG__WRITE                                         0x80003fffU
#define PWM_PWM2_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM2_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM2_CFG_MACRO__ */

/** @} end of pwm2_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_pwm3_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm3_ctrl pwm3_ctrl
 * @brief control signals for pwm3 channel definitions.
 * @{
 */
#ifndef __PWM_PWM3_CTRL_MACRO__
#define __PWM_PWM3_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM3_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM3_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM3_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM3_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM3_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM3_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM3_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM3_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM3_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM3_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM3_CTRL__MODE__SHIFT                                            1
#define PWM_PWM3_CTRL__MODE__WIDTH                                            2
#define PWM_PWM3_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM3_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM3_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM3_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM3_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM3_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM3_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM3_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM3_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM3_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM3_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM3_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM3_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM3_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM3_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM3_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM3_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM3_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM3_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM3_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM3_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM3_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM3_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM3_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM3_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM3_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM3_CTRL__TYPE                                            uint32_t
#define PWM_PWM3_CTRL__READ                                         0x0000001fU
#define PWM_PWM3_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM3_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM3_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM3_CTRL_MACRO__ */

/** @} end of pwm3_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm3_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm3_dur pwm3_dur
 * @brief durations config for pwm3 channel definitions.
 * @{
 */
#ifndef __PWM_PWM3_DUR_MACRO__
#define __PWM_PWM3_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM3_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM3_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM3_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM3_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM3_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM3_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM3_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM3_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM3_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM3_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM3_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM3_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM3_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM3_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM3_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM3_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM3_DUR__TYPE                                             uint32_t
#define PWM_PWM3_DUR__READ                                          0xffffffffU
#define PWM_PWM3_DUR__WRITE                                         0xffffffffU
#define PWM_PWM3_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM3_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM3_DUR_MACRO__ */

/** @} end of pwm3_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm3_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm3_cfg pwm3_cfg
 * @brief configuration for pwm3 channel definitions.
 * @{
 */
#ifndef __PWM_PWM3_CFG_MACRO__
#define __PWM_PWM3_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM3_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM3_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM3_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM3_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM3_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM3_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM3_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM3_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM3_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM3_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM3_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM3_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM3_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM3_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM3_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM3_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM3_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM3_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM3_CFG__TYPE                                             uint32_t
#define PWM_PWM3_CFG__READ                                          0x80003fffU
#define PWM_PWM3_CFG__WRITE                                         0x80003fffU
#define PWM_PWM3_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM3_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM3_CFG_MACRO__ */

/** @} end of pwm3_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_pwm4_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm4_ctrl pwm4_ctrl
 * @brief control signals for pwm4 channel definitions.
 * @{
 */
#ifndef __PWM_PWM4_CTRL_MACRO__
#define __PWM_PWM4_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM4_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM4_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM4_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM4_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM4_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM4_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM4_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM4_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM4_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM4_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM4_CTRL__MODE__SHIFT                                            1
#define PWM_PWM4_CTRL__MODE__WIDTH                                            2
#define PWM_PWM4_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM4_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM4_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM4_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM4_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM4_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM4_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM4_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM4_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM4_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM4_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM4_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM4_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM4_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM4_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM4_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM4_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM4_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM4_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM4_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM4_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM4_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM4_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM4_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM4_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM4_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM4_CTRL__TYPE                                            uint32_t
#define PWM_PWM4_CTRL__READ                                         0x0000001fU
#define PWM_PWM4_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM4_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM4_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM4_CTRL_MACRO__ */

/** @} end of pwm4_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm4_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm4_dur pwm4_dur
 * @brief durations config for pwm4 channel definitions.
 * @{
 */
#ifndef __PWM_PWM4_DUR_MACRO__
#define __PWM_PWM4_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM4_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM4_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM4_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM4_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM4_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM4_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM4_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM4_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM4_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM4_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM4_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM4_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM4_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM4_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM4_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM4_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM4_DUR__TYPE                                             uint32_t
#define PWM_PWM4_DUR__READ                                          0xffffffffU
#define PWM_PWM4_DUR__WRITE                                         0xffffffffU
#define PWM_PWM4_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM4_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM4_DUR_MACRO__ */

/** @} end of pwm4_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm4_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm4_cfg pwm4_cfg
 * @brief configuration for pwm4 channel definitions.
 * @{
 */
#ifndef __PWM_PWM4_CFG_MACRO__
#define __PWM_PWM4_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM4_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM4_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM4_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM4_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM4_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM4_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM4_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM4_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM4_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM4_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM4_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM4_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM4_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM4_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM4_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM4_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM4_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM4_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM4_CFG__TYPE                                             uint32_t
#define PWM_PWM4_CFG__READ                                          0x80003fffU
#define PWM_PWM4_CFG__WRITE                                         0x80003fffU
#define PWM_PWM4_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM4_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM4_CFG_MACRO__ */

/** @} end of pwm4_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_pwm5_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm5_ctrl pwm5_ctrl
 * @brief control signals for pwm5 channel definitions.
 * @{
 */
#ifndef __PWM_PWM5_CTRL_MACRO__
#define __PWM_PWM5_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM5_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM5_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM5_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM5_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM5_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM5_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM5_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM5_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM5_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM5_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM5_CTRL__MODE__SHIFT                                            1
#define PWM_PWM5_CTRL__MODE__WIDTH                                            2
#define PWM_PWM5_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM5_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM5_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM5_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM5_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM5_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM5_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM5_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM5_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM5_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM5_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM5_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM5_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM5_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM5_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM5_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM5_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM5_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM5_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM5_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM5_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM5_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM5_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM5_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM5_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM5_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM5_CTRL__TYPE                                            uint32_t
#define PWM_PWM5_CTRL__READ                                         0x0000001fU
#define PWM_PWM5_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM5_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM5_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM5_CTRL_MACRO__ */

/** @} end of pwm5_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm5_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm5_dur pwm5_dur
 * @brief durations config for pwm5 channel definitions.
 * @{
 */
#ifndef __PWM_PWM5_DUR_MACRO__
#define __PWM_PWM5_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM5_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM5_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM5_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM5_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM5_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM5_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM5_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM5_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM5_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM5_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM5_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM5_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM5_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM5_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM5_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM5_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM5_DUR__TYPE                                             uint32_t
#define PWM_PWM5_DUR__READ                                          0xffffffffU
#define PWM_PWM5_DUR__WRITE                                         0xffffffffU
#define PWM_PWM5_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM5_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM5_DUR_MACRO__ */

/** @} end of pwm5_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm5_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm5_cfg pwm5_cfg
 * @brief configuration for pwm5 channel definitions.
 * @{
 */
#ifndef __PWM_PWM5_CFG_MACRO__
#define __PWM_PWM5_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM5_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM5_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM5_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM5_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM5_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM5_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM5_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM5_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM5_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM5_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM5_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM5_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM5_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM5_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM5_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM5_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM5_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM5_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM5_CFG__TYPE                                             uint32_t
#define PWM_PWM5_CFG__READ                                          0x80003fffU
#define PWM_PWM5_CFG__WRITE                                         0x80003fffU
#define PWM_PWM5_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM5_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM5_CFG_MACRO__ */

/** @} end of pwm5_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_pwm6_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm6_ctrl pwm6_ctrl
 * @brief control signals for pwm6 channel definitions.
 * @{
 */
#ifndef __PWM_PWM6_CTRL_MACRO__
#define __PWM_PWM6_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM6_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM6_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM6_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM6_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM6_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM6_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM6_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM6_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM6_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM6_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM6_CTRL__MODE__SHIFT                                            1
#define PWM_PWM6_CTRL__MODE__WIDTH                                            2
#define PWM_PWM6_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM6_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM6_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM6_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM6_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM6_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM6_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM6_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM6_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM6_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM6_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM6_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM6_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM6_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM6_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM6_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM6_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM6_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM6_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM6_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM6_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM6_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM6_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM6_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM6_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM6_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM6_CTRL__TYPE                                            uint32_t
#define PWM_PWM6_CTRL__READ                                         0x0000001fU
#define PWM_PWM6_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM6_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM6_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM6_CTRL_MACRO__ */

/** @} end of pwm6_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm6_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm6_dur pwm6_dur
 * @brief durations config for pwm6 channel definitions.
 * @{
 */
#ifndef __PWM_PWM6_DUR_MACRO__
#define __PWM_PWM6_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM6_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM6_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM6_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM6_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM6_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM6_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM6_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM6_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM6_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM6_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM6_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM6_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM6_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM6_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM6_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM6_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM6_DUR__TYPE                                             uint32_t
#define PWM_PWM6_DUR__READ                                          0xffffffffU
#define PWM_PWM6_DUR__WRITE                                         0xffffffffU
#define PWM_PWM6_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM6_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM6_DUR_MACRO__ */

/** @} end of pwm6_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm6_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm6_cfg pwm6_cfg
 * @brief configuration for pwm6 channel definitions.
 * @{
 */
#ifndef __PWM_PWM6_CFG_MACRO__
#define __PWM_PWM6_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM6_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM6_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM6_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM6_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM6_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM6_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM6_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM6_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM6_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM6_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM6_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM6_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM6_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM6_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM6_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM6_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM6_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM6_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM6_CFG__TYPE                                             uint32_t
#define PWM_PWM6_CFG__READ                                          0x80003fffU
#define PWM_PWM6_CFG__WRITE                                         0x80003fffU
#define PWM_PWM6_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM6_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM6_CFG_MACRO__ */

/** @} end of pwm6_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_pwm7_ctrl */
/**
 * @defgroup at_apb_pwm_regs_core_pwm7_ctrl pwm7_ctrl
 * @brief control signals for pwm7 channel definitions.
 * @{
 */
#ifndef __PWM_PWM7_CTRL_MACRO__
#define __PWM_PWM7_CTRL_MACRO__

/* macros for field ok_to_run */
/**
 * @defgroup at_apb_pwm_regs_core_ok_to_run_field ok_to_run_field
 * @brief macros for field ok_to_run
 * @details start pwm channel with its rising edge. Its de-assertion stops the channel at the end of the next frame.
 * @{
 */
#define PWM_PWM7_CTRL__OK_TO_RUN__SHIFT                                       0
#define PWM_PWM7_CTRL__OK_TO_RUN__WIDTH                                       1
#define PWM_PWM7_CTRL__OK_TO_RUN__MASK                              0x00000001U
#define PWM_PWM7_CTRL__OK_TO_RUN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM7_CTRL__OK_TO_RUN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define PWM_PWM7_CTRL__OK_TO_RUN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_PWM7_CTRL__OK_TO_RUN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_PWM7_CTRL__OK_TO_RUN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_PWM7_CTRL__OK_TO_RUN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_PWM7_CTRL__OK_TO_RUN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup at_apb_pwm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details mode of operations:  00 = CONTINUOUS_MODE: each frame is repeated indefinately. hi_dur and lo_dur parameters are sampled once per frame.  01 = COUNTER_MODE: a group of frames is run once after ok_to_run is set. hi_dur and lo_dur parameters are sampled once at the start of the group.  10 = IR_MODE: a group of frames is run and repeated indefinitely after ok_to_run is set. hi_dur, lo_dur and frame_count paramters are sampled once before each group is run.  11 = IR_FIFO_MODE: the same IR_MODE but the group parameters are pulled from the fifo. The mode is reserved if the fifo is not assigned to the channel.
 * @{
 */
#define PWM_PWM7_CTRL__MODE__SHIFT                                            1
#define PWM_PWM7_CTRL__MODE__WIDTH                                            2
#define PWM_PWM7_CTRL__MODE__MASK                                   0x00000006U
#define PWM_PWM7_CTRL__MODE__READ(src)   (((uint32_t)(src) & 0x00000006U) >> 1)
#define PWM_PWM7_CTRL__MODE__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000006U)
#define PWM_PWM7_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define PWM_PWM7_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define PWM_PWM7_CTRL__MODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field invert */
/**
 * @defgroup at_apb_pwm_regs_core_invert_field invert_field
 * @brief macros for field invert
 * @details invert pwm output.
 * @{
 */
#define PWM_PWM7_CTRL__INVERT__SHIFT                                          3
#define PWM_PWM7_CTRL__INVERT__WIDTH                                          1
#define PWM_PWM7_CTRL__INVERT__MASK                                 0x00000008U
#define PWM_PWM7_CTRL__INVERT__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define PWM_PWM7_CTRL__INVERT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_PWM7_CTRL__INVERT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_PWM7_CTRL__INVERT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_PWM7_CTRL__INVERT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_PWM7_CTRL__INVERT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_PWM7_CTRL__INVERT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field idle_polarity */
/**
 * @defgroup at_apb_pwm_regs_core_idle_polarity_field idle_polarity_field
 * @brief macros for field idle_polarity
 * @details polarity in idle state
 * @{
 */
#define PWM_PWM7_CTRL__IDLE_POLARITY__SHIFT                                   4
#define PWM_PWM7_CTRL__IDLE_POLARITY__WIDTH                                   1
#define PWM_PWM7_CTRL__IDLE_POLARITY__MASK                          0x00000010U
#define PWM_PWM7_CTRL__IDLE_POLARITY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_PWM7_CTRL__IDLE_POLARITY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_PWM7_CTRL__IDLE_POLARITY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_PWM7_CTRL__IDLE_POLARITY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_PWM7_CTRL__IDLE_POLARITY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_PWM7_CTRL__IDLE_POLARITY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_PWM7_CTRL__IDLE_POLARITY__RESET_VALUE                   0x00000000U
/** @} */
#define PWM_PWM7_CTRL__TYPE                                            uint32_t
#define PWM_PWM7_CTRL__READ                                         0x0000001fU
#define PWM_PWM7_CTRL__WRITE                                        0x0000001fU
#define PWM_PWM7_CTRL__PRESERVED                                    0x00000000U
#define PWM_PWM7_CTRL__RESET_VALUE                                  0x00000000U

#endif /* __PWM_PWM7_CTRL_MACRO__ */

/** @} end of pwm7_ctrl */

/* macros for BlueprintGlobalNameSpace::PWM_pwm7_dur */
/**
 * @defgroup at_apb_pwm_regs_core_pwm7_dur pwm7_dur
 * @brief durations config for pwm7 channel definitions.
 * @{
 */
#ifndef __PWM_PWM7_DUR_MACRO__
#define __PWM_PWM7_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_PWM7_DUR__LO_DUR__SHIFT                                           0
#define PWM_PWM7_DUR__LO_DUR__WIDTH                                          16
#define PWM_PWM7_DUR__LO_DUR__MASK                                  0x0000ffffU
#define PWM_PWM7_DUR__LO_DUR__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM7_DUR__LO_DUR__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_PWM7_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_PWM7_DUR__LO_DUR__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_PWM7_DUR__LO_DUR__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur. (hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_PWM7_DUR__HI_DUR__SHIFT                                          16
#define PWM_PWM7_DUR__HI_DUR__WIDTH                                          16
#define PWM_PWM7_DUR__HI_DUR__MASK                                  0xffff0000U
#define PWM_PWM7_DUR__HI_DUR__READ(src) (((uint32_t)(src) & 0xffff0000U) >> 16)
#define PWM_PWM7_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_PWM7_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_PWM7_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_PWM7_DUR__HI_DUR__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM7_DUR__TYPE                                             uint32_t
#define PWM_PWM7_DUR__READ                                          0xffffffffU
#define PWM_PWM7_DUR__WRITE                                         0xffffffffU
#define PWM_PWM7_DUR__PRESERVED                                     0x00000000U
#define PWM_PWM7_DUR__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM7_DUR_MACRO__ */

/** @} end of pwm7_dur */

/* macros for BlueprintGlobalNameSpace::PWM_pwm7_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_pwm7_cfg pwm7_cfg
 * @brief configuration for pwm7 channel definitions.
 * @{
 */
#ifndef __PWM_PWM7_CFG_MACRO__
#define __PWM_PWM7_CFG_MACRO__

/* macros for field frame_count */
/**
 * @defgroup at_apb_pwm_regs_core_frame_count_field frame_count_field
 * @brief macros for field frame_count
 * @details number of frames in the group = frame_count + 1
 * @{
 */
#define PWM_PWM7_CFG__FRAME_COUNT__SHIFT                                      0
#define PWM_PWM7_CFG__FRAME_COUNT__WIDTH                                     14
#define PWM_PWM7_CFG__FRAME_COUNT__MASK                             0x00003fffU
#define PWM_PWM7_CFG__FRAME_COUNT__READ(src)    ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM7_CFG__FRAME_COUNT__WRITE(src)   ((uint32_t)(src) & 0x00003fffU)
#define PWM_PWM7_CFG__FRAME_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define PWM_PWM7_CFG__FRAME_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define PWM_PWM7_CFG__FRAME_COUNT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field update */
/**
 * @defgroup at_apb_pwm_regs_core_update_field update_field
 * @brief macros for field update
 * @details this bit synchronize channel parameters (lo/hi dur + frame count) update,  when set it triggers HW capture and it auto-cleares afterwards  during CONTINUOUS and IR_FIFO modes, this bit is don't care.
 * @{
 */
#define PWM_PWM7_CFG__UPDATE__SHIFT                                          31
#define PWM_PWM7_CFG__UPDATE__WIDTH                                           1
#define PWM_PWM7_CFG__UPDATE__MASK                                  0x80000000U
#define PWM_PWM7_CFG__UPDATE__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define PWM_PWM7_CFG__UPDATE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PWM_PWM7_CFG__UPDATE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PWM_PWM7_CFG__UPDATE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PWM_PWM7_CFG__UPDATE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PWM_PWM7_CFG__UPDATE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PWM_PWM7_CFG__UPDATE__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_PWM7_CFG__TYPE                                             uint32_t
#define PWM_PWM7_CFG__READ                                          0x80003fffU
#define PWM_PWM7_CFG__WRITE                                         0x80003fffU
#define PWM_PWM7_CFG__PRESERVED                                     0x00000000U
#define PWM_PWM7_CFG__RESET_VALUE                                   0x00000000U

#endif /* __PWM_PWM7_CFG_MACRO__ */

/** @} end of pwm7_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_fsm_state */
/**
 * @defgroup at_apb_pwm_regs_core_fsm_state fsm_state
 * @brief fsm state definitions.
 * @{
 */
#ifndef __PWM_FSM_STATE_MACRO__
#define __PWM_FSM_STATE_MACRO__

/* macros for field ch0 */
/**
 * @defgroup at_apb_pwm_regs_core_ch0_field ch0_field
 * @brief macros for field ch0
 * @details current state of pwm0 channel.
 * @{
 */
#define PWM_FSM_STATE__CH0__SHIFT                                             0
#define PWM_FSM_STATE__CH0__WIDTH                                             2
#define PWM_FSM_STATE__CH0__MASK                                    0x00000003U
#define PWM_FSM_STATE__CH0__READ(src)           ((uint32_t)(src) & 0x00000003U)
#define PWM_FSM_STATE__CH0__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field ch1 */
/**
 * @defgroup at_apb_pwm_regs_core_ch1_field ch1_field
 * @brief macros for field ch1
 * @details current state of pwm1 channel.
 * @{
 */
#define PWM_FSM_STATE__CH1__SHIFT                                             2
#define PWM_FSM_STATE__CH1__WIDTH                                             2
#define PWM_FSM_STATE__CH1__MASK                                    0x0000000cU
#define PWM_FSM_STATE__CH1__READ(src)    (((uint32_t)(src) & 0x0000000cU) >> 2)
#define PWM_FSM_STATE__CH1__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field ch2 */
/**
 * @defgroup at_apb_pwm_regs_core_ch2_field ch2_field
 * @brief macros for field ch2
 * @details current state of pwm2 channel.
 * @{
 */
#define PWM_FSM_STATE__CH2__SHIFT                                             4
#define PWM_FSM_STATE__CH2__WIDTH                                             2
#define PWM_FSM_STATE__CH2__MASK                                    0x00000030U
#define PWM_FSM_STATE__CH2__READ(src)    (((uint32_t)(src) & 0x00000030U) >> 4)
#define PWM_FSM_STATE__CH2__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field ch3 */
/**
 * @defgroup at_apb_pwm_regs_core_ch3_field ch3_field
 * @brief macros for field ch3
 * @details current state of pwm3 channel.
 * @{
 */
#define PWM_FSM_STATE__CH3__SHIFT                                             6
#define PWM_FSM_STATE__CH3__WIDTH                                             2
#define PWM_FSM_STATE__CH3__MASK                                    0x000000c0U
#define PWM_FSM_STATE__CH3__READ(src)    (((uint32_t)(src) & 0x000000c0U) >> 6)
#define PWM_FSM_STATE__CH3__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field ch4 */
/**
 * @defgroup at_apb_pwm_regs_core_ch4_field ch4_field
 * @brief macros for field ch4
 * @details current state of pwm4 channel.
 * @{
 */
#define PWM_FSM_STATE__CH4__SHIFT                                             8
#define PWM_FSM_STATE__CH4__WIDTH                                             2
#define PWM_FSM_STATE__CH4__MASK                                    0x00000300U
#define PWM_FSM_STATE__CH4__READ(src)    (((uint32_t)(src) & 0x00000300U) >> 8)
#define PWM_FSM_STATE__CH4__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field ch5 */
/**
 * @defgroup at_apb_pwm_regs_core_ch5_field ch5_field
 * @brief macros for field ch5
 * @details current state of pwm5 channel.
 * @{
 */
#define PWM_FSM_STATE__CH5__SHIFT                                            10
#define PWM_FSM_STATE__CH5__WIDTH                                             2
#define PWM_FSM_STATE__CH5__MASK                                    0x00000c00U
#define PWM_FSM_STATE__CH5__READ(src)   (((uint32_t)(src) & 0x00000c00U) >> 10)
#define PWM_FSM_STATE__CH5__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field ch6 */
/**
 * @defgroup at_apb_pwm_regs_core_ch6_field ch6_field
 * @brief macros for field ch6
 * @details current state of pwm6 channel.
 * @{
 */
#define PWM_FSM_STATE__CH6__SHIFT                                            12
#define PWM_FSM_STATE__CH6__WIDTH                                             2
#define PWM_FSM_STATE__CH6__MASK                                    0x00003000U
#define PWM_FSM_STATE__CH6__READ(src)   (((uint32_t)(src) & 0x00003000U) >> 12)
#define PWM_FSM_STATE__CH6__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field ch7 */
/**
 * @defgroup at_apb_pwm_regs_core_ch7_field ch7_field
 * @brief macros for field ch7
 * @details current state of pwm7 channel.
 * @{
 */
#define PWM_FSM_STATE__CH7__SHIFT                                            14
#define PWM_FSM_STATE__CH7__WIDTH                                             2
#define PWM_FSM_STATE__CH7__MASK                                    0x0000c000U
#define PWM_FSM_STATE__CH7__READ(src)   (((uint32_t)(src) & 0x0000c000U) >> 14)
#define PWM_FSM_STATE__CH7__RESET_VALUE                             0x00000000U
/** @} */
#define PWM_FSM_STATE__TYPE                                            uint32_t
#define PWM_FSM_STATE__READ                                         0x0000ffffU
#define PWM_FSM_STATE__PRESERVED                                    0x00000000U
#define PWM_FSM_STATE__RESET_VALUE                                  0x00000000U

#endif /* __PWM_FSM_STATE_MACRO__ */

/** @} end of fsm_state */

/* macros for BlueprintGlobalNameSpace::PWM_fifo_cfg */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_cfg fifo_cfg
 * @brief fifo configuration definitions.
 * @{
 */
#ifndef __PWM_FIFO_CFG_MACRO__
#define __PWM_FIFO_CFG_MACRO__

/* macros for field lwm */
/**
 * @defgroup at_apb_pwm_regs_core_lwm_field lwm_field
 * @brief macros for field lwm
 * @details low water mark (lwm) of FIF0; a trigger is issued when FIFO has been drained to these many open slots. Constraint (1<= LWM <= 16) triggers when the number of open slots changes from (lwm - 1) to (lwm). lwm = 15 means an interrupt is issued as the number of open slots changes from 14 to 15. In other words, the number of entries in the fifo changes from 2 to 1.
 * @{
 */
#define PWM_FIFO_CFG__LWM__SHIFT                                              0
#define PWM_FIFO_CFG__LWM__WIDTH                                              5
#define PWM_FIFO_CFG__LWM__MASK                                     0x0000001fU
#define PWM_FIFO_CFG__LWM__READ(src)            ((uint32_t)(src) & 0x0000001fU)
#define PWM_FIFO_CFG__LWM__WRITE(src)           ((uint32_t)(src) & 0x0000001fU)
#define PWM_FIFO_CFG__LWM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define PWM_FIFO_CFG__LWM__VERIFY(src)    (!(((uint32_t)(src) & ~0x0000001fU)))
#define PWM_FIFO_CFG__LWM__RESET_VALUE                              0x0000000fU
/** @} */

/* macros for field flush */
/**
 * @defgroup at_apb_pwm_regs_core_flush_field flush_field
 * @brief macros for field flush
 * @details Signal's rising edge clears out fifo. Not self-clearing
 * @{
 */
#define PWM_FIFO_CFG__FLUSH__SHIFT                                            6
#define PWM_FIFO_CFG__FLUSH__WIDTH                                            1
#define PWM_FIFO_CFG__FLUSH__MASK                                   0x00000040U
#define PWM_FIFO_CFG__FLUSH__READ(src)   (((uint32_t)(src) & 0x00000040U) >> 6)
#define PWM_FIFO_CFG__FLUSH__WRITE(src)  (((uint32_t)(src) << 6) & 0x00000040U)
#define PWM_FIFO_CFG__FLUSH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PWM_FIFO_CFG__FLUSH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PWM_FIFO_CFG__FLUSH__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PWM_FIFO_CFG__FLUSH__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PWM_FIFO_CFG__FLUSH__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field ch_stop */
/**
 * @defgroup at_apb_pwm_regs_core_ch_stop_field ch_stop_field
 * @brief macros for field ch_stop
 * @details when set, stops channel running in IR_FIFO_MODE after last fifo command is done. otherwise, the last command keeps repeating.
 * @{
 */
#define PWM_FIFO_CFG__CH_STOP__SHIFT                                          7
#define PWM_FIFO_CFG__CH_STOP__WIDTH                                          1
#define PWM_FIFO_CFG__CH_STOP__MASK                                 0x00000080U
#define PWM_FIFO_CFG__CH_STOP__READ(src) (((uint32_t)(src) & 0x00000080U) >> 7)
#define PWM_FIFO_CFG__CH_STOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PWM_FIFO_CFG__CH_STOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PWM_FIFO_CFG__CH_STOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PWM_FIFO_CFG__CH_STOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PWM_FIFO_CFG__CH_STOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PWM_FIFO_CFG__CH_STOP__RESET_VALUE                          0x00000000U
/** @} */
#define PWM_FIFO_CFG__TYPE                                             uint32_t
#define PWM_FIFO_CFG__READ                                          0x000000dfU
#define PWM_FIFO_CFG__WRITE                                         0x000000dfU
#define PWM_FIFO_CFG__PRESERVED                                     0x00000000U
#define PWM_FIFO_CFG__RESET_VALUE                                   0x0000000fU

#endif /* __PWM_FIFO_CFG_MACRO__ */

/** @} end of fifo_cfg */

/* macros for BlueprintGlobalNameSpace::PWM_fifo_carrier1_dur */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_carrier1_dur fifo_carrier1_dur
 * @brief carrier1 frequency durations for IR_FIFO_MODE definitions.
 * @{
 */
#ifndef __PWM_FIFO_CARRIER1_DUR_MACRO__
#define __PWM_FIFO_CARRIER1_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__SHIFT                                  0
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__WIDTH                                 16
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__MASK                         0x0000ffffU
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PWM_FIFO_CARRIER1_DUR__LO_DUR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur.(hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__SHIFT                                 16
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__WIDTH                                 16
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__MASK                         0xffff0000U
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_FIFO_CARRIER1_DUR__HI_DUR__RESET_VALUE                  0x00000000U
/** @} */
#define PWM_FIFO_CARRIER1_DUR__TYPE                                    uint32_t
#define PWM_FIFO_CARRIER1_DUR__READ                                 0xffffffffU
#define PWM_FIFO_CARRIER1_DUR__WRITE                                0xffffffffU
#define PWM_FIFO_CARRIER1_DUR__PRESERVED                            0x00000000U
#define PWM_FIFO_CARRIER1_DUR__RESET_VALUE                          0x00000000U

#endif /* __PWM_FIFO_CARRIER1_DUR_MACRO__ */

/** @} end of fifo_carrier1_dur */

/* macros for BlueprintGlobalNameSpace::PWM_fifo_carrier2_dur */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_carrier2_dur fifo_carrier2_dur
 * @brief carrier2 frequency durations for IR_FIFO_MODE definitions.
 * @{
 */
#ifndef __PWM_FIFO_CARRIER2_DUR_MACRO__
#define __PWM_FIFO_CARRIER2_DUR_MACRO__

/* macros for field lo_dur */
/**
 * @defgroup at_apb_pwm_regs_core_lo_dur_field lo_dur_field
 * @brief macros for field lo_dur
 * @details duration of low portion of period in clk_mpc clock cycles = lo_dur. (lo_dur=1/hi_dur=0 not supported)
 * @{
 */
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__SHIFT                                  0
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__WIDTH                                 16
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__MASK                         0x0000ffffU
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define PWM_FIFO_CARRIER2_DUR__LO_DUR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field hi_dur */
/**
 * @defgroup at_apb_pwm_regs_core_hi_dur_field hi_dur_field
 * @brief macros for field hi_dur
 * @details duration of high portion of period in clk_mpc clock cycles = hi_dur.(hi_dur=1/lo_dur=0 not supported)
 * @{
 */
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__SHIFT                                 16
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__WIDTH                                 16
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__MASK                         0xffff0000U
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define PWM_FIFO_CARRIER2_DUR__HI_DUR__RESET_VALUE                  0x00000000U
/** @} */
#define PWM_FIFO_CARRIER2_DUR__TYPE                                    uint32_t
#define PWM_FIFO_CARRIER2_DUR__READ                                 0xffffffffU
#define PWM_FIFO_CARRIER2_DUR__WRITE                                0xffffffffU
#define PWM_FIFO_CARRIER2_DUR__PRESERVED                            0x00000000U
#define PWM_FIFO_CARRIER2_DUR__RESET_VALUE                          0x00000000U

#endif /* __PWM_FIFO_CARRIER2_DUR_MACRO__ */

/** @} end of fifo_carrier2_dur */

/* macros for BlueprintGlobalNameSpace::PWM_fifo_stat */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_stat fifo_stat
 * @brief fifo status definitions.
 * @{
 */
#ifndef __PWM_FIFO_STAT_MACRO__
#define __PWM_FIFO_STAT_MACRO__

/* macros for field full */
/**
 * @defgroup at_apb_pwm_regs_core_full_field full_field
 * @brief macros for field full
 * @details fifo is full. APB is stalled if a write is requested.
 * @{
 */
#define PWM_FIFO_STAT__FULL__SHIFT                                            0
#define PWM_FIFO_STAT__FULL__WIDTH                                            1
#define PWM_FIFO_STAT__FULL__MASK                                   0x00000001U
#define PWM_FIFO_STAT__FULL__READ(src)          ((uint32_t)(src) & 0x00000001U)
#define PWM_FIFO_STAT__FULL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_FIFO_STAT__FULL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_FIFO_STAT__FULL__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field empty */
/**
 * @defgroup at_apb_pwm_regs_core_empty_field empty_field
 * @brief macros for field empty
 * @details fifo is empty.
 * @{
 */
#define PWM_FIFO_STAT__EMPTY__SHIFT                                           1
#define PWM_FIFO_STAT__EMPTY__WIDTH                                           1
#define PWM_FIFO_STAT__EMPTY__MASK                                  0x00000002U
#define PWM_FIFO_STAT__EMPTY__READ(src)  (((uint32_t)(src) & 0x00000002U) >> 1)
#define PWM_FIFO_STAT__EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PWM_FIFO_STAT__EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PWM_FIFO_STAT__EMPTY__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_FIFO_STAT__TYPE                                            uint32_t
#define PWM_FIFO_STAT__READ                                         0x00000003U
#define PWM_FIFO_STAT__PRESERVED                                    0x00000000U
#define PWM_FIFO_STAT__RESET_VALUE                                  0x00000000U

#endif /* __PWM_FIFO_STAT_MACRO__ */

/** @} end of fifo_stat */

/* macros for BlueprintGlobalNameSpace::PWM_fifo_stat1 */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_stat1 fifo_stat1
 * @brief fifo status definitions.
 * @{
 */
#ifndef __PWM_FIFO_STAT1_MACRO__
#define __PWM_FIFO_STAT1_MACRO__

/* macros for field num_open_slots */
/**
 * @defgroup at_apb_pwm_regs_core_num_open_slots_field num_open_slots_field
 * @brief macros for field num_open_slots
 * @details open slots in FIFO
 * @{
 */
#define PWM_FIFO_STAT1__NUM_OPEN_SLOTS__SHIFT                                 0
#define PWM_FIFO_STAT1__NUM_OPEN_SLOTS__WIDTH                                 5
#define PWM_FIFO_STAT1__NUM_OPEN_SLOTS__MASK                        0x0000001fU
#define PWM_FIFO_STAT1__NUM_OPEN_SLOTS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define PWM_FIFO_STAT1__NUM_OPEN_SLOTS__RESET_VALUE                 0x00000010U
/** @} */
#define PWM_FIFO_STAT1__TYPE                                           uint32_t
#define PWM_FIFO_STAT1__READ                                        0x0000001fU
#define PWM_FIFO_STAT1__PRESERVED                                   0x00000000U
#define PWM_FIFO_STAT1__RESET_VALUE                                 0x00000010U

#endif /* __PWM_FIFO_STAT1_MACRO__ */

/** @} end of fifo_stat1 */

/* macros for BlueprintGlobalNameSpace::PWM_fifo_sel_err_source */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_sel_err_source fifo_sel_err_source
 * @brief HW sets and SW write 0 to clear and 1 to set these bits. Set takes precedence. definitions.
 * @{
 */
#ifndef __PWM_FIFO_SEL_ERR_SOURCE_MACRO__
#define __PWM_FIFO_SEL_ERR_SOURCE_MACRO__

/* macros for field ch0_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch0_fifo_sel_err_field ch0_fifo_sel_err_field
 * @brief macros for field ch0_fifo_sel_err
 * @details pwm0 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__SHIFT                      0
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__MASK             0x00000001U
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_FIFO_SEL_ERR_SOURCE__CH0_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ch1_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch1_fifo_sel_err_field ch1_fifo_sel_err_field
 * @brief macros for field ch1_fifo_sel_err
 * @details pwm1 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__SHIFT                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__MASK             0x00000002U
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PWM_FIFO_SEL_ERR_SOURCE__CH1_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ch2_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch2_fifo_sel_err_field ch2_fifo_sel_err_field
 * @brief macros for field ch2_fifo_sel_err
 * @details pwm2 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__SHIFT                      2
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__MASK             0x00000004U
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PWM_FIFO_SEL_ERR_SOURCE__CH2_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ch3_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch3_fifo_sel_err_field ch3_fifo_sel_err_field
 * @brief macros for field ch3_fifo_sel_err
 * @details pwm3 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__SHIFT                      3
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__MASK             0x00000008U
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_FIFO_SEL_ERR_SOURCE__CH3_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ch4_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch4_fifo_sel_err_field ch4_fifo_sel_err_field
 * @brief macros for field ch4_fifo_sel_err
 * @details pwm4 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__SHIFT                      4
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__MASK             0x00000010U
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PWM_FIFO_SEL_ERR_SOURCE__CH4_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ch5_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch5_fifo_sel_err_field ch5_fifo_sel_err_field
 * @brief macros for field ch5_fifo_sel_err
 * @details pwm5 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__SHIFT                      5
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__MASK             0x00000020U
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PWM_FIFO_SEL_ERR_SOURCE__CH5_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ch6_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch6_fifo_sel_err_field ch6_fifo_sel_err_field
 * @brief macros for field ch6_fifo_sel_err
 * @details pwm6 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__SHIFT                      6
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__MASK             0x00000040U
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PWM_FIFO_SEL_ERR_SOURCE__CH6_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ch7_fifo_sel_err */
/**
 * @defgroup at_apb_pwm_regs_core_ch7_fifo_sel_err_field ch7_fifo_sel_err_field
 * @brief macros for field ch7_fifo_sel_err
 * @details pwm7 channel caused fifo_sel_err_intrpt;
 * @{
 */
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__SHIFT                      7
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__WIDTH                      1
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__MASK             0x00000080U
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PWM_FIFO_SEL_ERR_SOURCE__CH7_FIFO_SEL_ERR__RESET_VALUE      0x00000000U
/** @} */
#define PWM_FIFO_SEL_ERR_SOURCE__TYPE                                  uint32_t
#define PWM_FIFO_SEL_ERR_SOURCE__READ                               0x000000ffU
#define PWM_FIFO_SEL_ERR_SOURCE__WRITE                              0x000000ffU
#define PWM_FIFO_SEL_ERR_SOURCE__PRESERVED                          0x00000000U
#define PWM_FIFO_SEL_ERR_SOURCE__RESET_VALUE                        0x00000000U

#endif /* __PWM_FIFO_SEL_ERR_SOURCE_MACRO__ */

/** @} end of fifo_sel_err_source */

/* macros for BlueprintGlobalNameSpace::PWM_interrupts */
/**
 * @defgroup at_apb_pwm_regs_core_interrupts interrupts
 * @brief Contains register fields associated with interrupts. definitions.
 * @{
 */
#ifndef __PWM_INTERRUPTS_MACRO__
#define __PWM_INTERRUPTS_MACRO__

/* macros for field fifo_ovrflow_intrpt */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_ovrflow_intrpt_field fifo_ovrflow_intrpt_field
 * @brief macros for field fifo_ovrflow_intrpt
 * @details HW sets when a write to fifo happens when fifo is full.
 * @{
 */
#define PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__SHIFT                            0
#define PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__WIDTH                            1
#define PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__MASK                   0x00000001U
#define PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_INTERRUPTS__FIFO_OVRFLOW_INTRPT__RESET_VALUE            0x00000000U
/** @} */

/* macros for field fifo_lwm_hit_intrpt */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_lwm_hit_intrpt_field fifo_lwm_hit_intrpt_field
 * @brief macros for field fifo_lwm_hit_intrpt
 * @details HW sets when lwm condition is hit.
 * @{
 */
#define PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__SHIFT                            1
#define PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__WIDTH                            1
#define PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__MASK                   0x00000002U
#define PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PWM_INTERRUPTS__FIFO_LWM_HIT_INTRPT__RESET_VALUE            0x00000000U
/** @} */

/* macros for field fifo_sel_err_intrpt */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_sel_err_intrpt_field fifo_sel_err_intrpt_field
 * @brief macros for field fifo_sel_err_intrpt
 * @details HW sets when a channel is in IR_FIFO_MODE but not given the FIFO; FIFO being used by another channel.  With the conflict condition as described, an error assertion happens when  channel is in idle and ok_to_run is issued.  Consequently, the internal state registers of the channel revert to default values.
 * @{
 */
#define PWM_INTERRUPTS__FIFO_SEL_ERR_INTRPT__SHIFT                            2
#define PWM_INTERRUPTS__FIFO_SEL_ERR_INTRPT__WIDTH                            1
#define PWM_INTERRUPTS__FIFO_SEL_ERR_INTRPT__MASK                   0x00000004U
#define PWM_INTERRUPTS__FIFO_SEL_ERR_INTRPT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PWM_INTERRUPTS__FIFO_SEL_ERR_INTRPT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PWM_INTERRUPTS__FIFO_SEL_ERR_INTRPT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PWM_INTERRUPTS__FIFO_SEL_ERR_INTRPT__RESET_VALUE            0x00000000U
/** @} */

/* macros for field fifo_cmd_done_intrpt */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_cmd_done_intrpt_field fifo_cmd_done_intrpt_field
 * @brief macros for field fifo_cmd_done_intrpt
 * @details HW sets when a channel is in IR_FIFO_MODE and last cmmand in fifo is done.
 * @{
 */
#define PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__SHIFT                           3
#define PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__WIDTH                           1
#define PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__MASK                  0x00000008U
#define PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_INTERRUPTS__FIFO_CMD_DONE_INTRPT__RESET_VALUE           0x00000000U
/** @} */
#define PWM_INTERRUPTS__TYPE                                           uint32_t
#define PWM_INTERRUPTS__READ                                        0x0000000fU
#define PWM_INTERRUPTS__PRESERVED                                   0x00000000U
#define PWM_INTERRUPTS__RESET_VALUE                                 0x00000000U

#endif /* __PWM_INTERRUPTS_MACRO__ */

/** @} end of interrupts */

/* macros for BlueprintGlobalNameSpace::PWM_interrupts_mask */
/**
 * @defgroup at_apb_pwm_regs_core_interrupts_mask interrupts_mask
 * @brief Contains register fields associated with interrupts_mask. definitions.
 * @{
 */
#ifndef __PWM_INTERRUPTS_MASK_MACRO__
#define __PWM_INTERRUPTS_MASK_MACRO__

/* macros for field mask_intrpt0 */
/**
 * @defgroup at_apb_pwm_regs_core_mask_intrpt0_field mask_intrpt0_field
 * @brief macros for field mask_intrpt0
 * @details allows fifo_ovrflow_intrpt to propogate to channel's combined interrupt.
 * @{
 */
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__SHIFT                              0
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__WIDTH                              1
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__MASK                     0x00000001U
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT0__RESET_VALUE              0x00000001U
/** @} */

/* macros for field mask_intrpt1 */
/**
 * @defgroup at_apb_pwm_regs_core_mask_intrpt1_field mask_intrpt1_field
 * @brief macros for field mask_intrpt1
 * @details allows lwm_hit_intrpt to propogate to channel's combined interrupt.
 * @{
 */
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__SHIFT                              1
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__WIDTH                              1
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__MASK                     0x00000002U
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT1__RESET_VALUE              0x00000001U
/** @} */

/* macros for field mask_intrpt2 */
/**
 * @defgroup at_apb_pwm_regs_core_mask_intrpt2_field mask_intrpt2_field
 * @brief macros for field mask_intrpt2
 * @details allows fifo_sel_err_intrpt to propagate to channel's combined interrupt.
 * @{
 */
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__SHIFT                              2
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__WIDTH                              1
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__MASK                     0x00000004U
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT2__RESET_VALUE              0x00000000U
/** @} */

/* macros for field mask_intrpt3 */
/**
 * @defgroup at_apb_pwm_regs_core_mask_intrpt3_field mask_intrpt3_field
 * @brief macros for field mask_intrpt3
 * @details allows fifo_cmd_done_intrpt to propagate to channel's combined interrupt.
 * @{
 */
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__SHIFT                              3
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__WIDTH                              1
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__MASK                     0x00000008U
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_INTERRUPTS_MASK__MASK_INTRPT3__RESET_VALUE              0x00000000U
/** @} */
#define PWM_INTERRUPTS_MASK__TYPE                                      uint32_t
#define PWM_INTERRUPTS_MASK__READ                                   0x0000000fU
#define PWM_INTERRUPTS_MASK__WRITE                                  0x0000000fU
#define PWM_INTERRUPTS_MASK__PRESERVED                              0x00000000U
#define PWM_INTERRUPTS_MASK__RESET_VALUE                            0x00000003U

#endif /* __PWM_INTERRUPTS_MASK_MACRO__ */

/** @} end of interrupts_mask */

/* macros for BlueprintGlobalNameSpace::PWM_interrupts_clear */
/**
 * @defgroup at_apb_pwm_regs_core_interrupts_clear interrupts_clear
 * @brief Contains register fields associated with interrupts_clear. definitions.
 * @{
 */
#ifndef __PWM_INTERRUPTS_CLEAR_MACRO__
#define __PWM_INTERRUPTS_CLEAR_MACRO__

/* macros for field clear_intrpt0 */
/**
 * @defgroup at_apb_pwm_regs_core_clear_intrpt0_field clear_intrpt0_field
 * @brief macros for field clear_intrpt0
 * @details clears fifo_overflow_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__SHIFT                            0
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__WIDTH                            1
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__MASK                   0x00000001U
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT0__RESET_VALUE            0x00000000U
/** @} */

/* macros for field clear_intrpt1 */
/**
 * @defgroup at_apb_pwm_regs_core_clear_intrpt1_field clear_intrpt1_field
 * @brief macros for field clear_intrpt1
 * @details clears lwm_hit_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__SHIFT                            1
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__WIDTH                            1
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__MASK                   0x00000002U
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT1__RESET_VALUE            0x00000000U
/** @} */

/* macros for field clear_intrpt2 */
/**
 * @defgroup at_apb_pwm_regs_core_clear_intrpt2_field clear_intrpt2_field
 * @brief macros for field clear_intrpt2
 * @details clears fifo_sel_error_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__SHIFT                            2
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__WIDTH                            1
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__MASK                   0x00000004U
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT2__RESET_VALUE            0x00000000U
/** @} */

/* macros for field clear_intrpt3 */
/**
 * @defgroup at_apb_pwm_regs_core_clear_intrpt3_field clear_intrpt3_field
 * @brief macros for field clear_intrpt3
 * @details clears fifo_cmd_done_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__SHIFT                            3
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__WIDTH                            1
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__MASK                   0x00000008U
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_INTERRUPTS_CLEAR__CLEAR_INTRPT3__RESET_VALUE            0x00000000U
/** @} */
#define PWM_INTERRUPTS_CLEAR__TYPE                                     uint32_t
#define PWM_INTERRUPTS_CLEAR__READ                                  0x0000000fU
#define PWM_INTERRUPTS_CLEAR__WRITE                                 0x0000000fU
#define PWM_INTERRUPTS_CLEAR__PRESERVED                             0x00000000U
#define PWM_INTERRUPTS_CLEAR__RESET_VALUE                           0x00000000U

#endif /* __PWM_INTERRUPTS_CLEAR_MACRO__ */

/** @} end of interrupts_clear */

/* macros for BlueprintGlobalNameSpace::PWM_interrupts_set */
/**
 * @defgroup at_apb_pwm_regs_core_interrupts_set interrupts_set
 * @brief Contains register fields associated with interrupts_set. definitions.
 * @{
 */
#ifndef __PWM_INTERRUPTS_SET_MACRO__
#define __PWM_INTERRUPTS_SET_MACRO__

/* macros for field set_intrpt0 */
/**
 * @defgroup at_apb_pwm_regs_core_set_intrpt0_field set_intrpt0_field
 * @brief macros for field set_intrpt0
 * @details sets fifo_overflow_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_SET__SET_INTRPT0__SHIFT                                0
#define PWM_INTERRUPTS_SET__SET_INTRPT0__WIDTH                                1
#define PWM_INTERRUPTS_SET__SET_INTRPT0__MASK                       0x00000001U
#define PWM_INTERRUPTS_SET__SET_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_INTERRUPTS_SET__SET_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PWM_INTERRUPTS_SET__SET_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PWM_INTERRUPTS_SET__SET_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PWM_INTERRUPTS_SET__SET_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PWM_INTERRUPTS_SET__SET_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PWM_INTERRUPTS_SET__SET_INTRPT0__RESET_VALUE                0x00000000U
/** @} */

/* macros for field set_intrpt1 */
/**
 * @defgroup at_apb_pwm_regs_core_set_intrpt1_field set_intrpt1_field
 * @brief macros for field set_intrpt1
 * @details sets lwm_hit_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_SET__SET_INTRPT1__SHIFT                                1
#define PWM_INTERRUPTS_SET__SET_INTRPT1__WIDTH                                1
#define PWM_INTERRUPTS_SET__SET_INTRPT1__MASK                       0x00000002U
#define PWM_INTERRUPTS_SET__SET_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PWM_INTERRUPTS_SET__SET_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PWM_INTERRUPTS_SET__SET_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PWM_INTERRUPTS_SET__SET_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PWM_INTERRUPTS_SET__SET_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PWM_INTERRUPTS_SET__SET_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PWM_INTERRUPTS_SET__SET_INTRPT1__RESET_VALUE                0x00000000U
/** @} */

/* macros for field set_intrpt2 */
/**
 * @defgroup at_apb_pwm_regs_core_set_intrpt2_field set_intrpt2_field
 * @brief macros for field set_intrpt2
 * @details sets fifo_sel_error_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_SET__SET_INTRPT2__SHIFT                                2
#define PWM_INTERRUPTS_SET__SET_INTRPT2__WIDTH                                1
#define PWM_INTERRUPTS_SET__SET_INTRPT2__MASK                       0x00000004U
#define PWM_INTERRUPTS_SET__SET_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PWM_INTERRUPTS_SET__SET_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PWM_INTERRUPTS_SET__SET_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PWM_INTERRUPTS_SET__SET_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PWM_INTERRUPTS_SET__SET_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PWM_INTERRUPTS_SET__SET_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PWM_INTERRUPTS_SET__SET_INTRPT2__RESET_VALUE                0x00000000U
/** @} */

/* macros for field set_intrpt3 */
/**
 * @defgroup at_apb_pwm_regs_core_set_intrpt3_field set_intrpt3_field
 * @brief macros for field set_intrpt3
 * @details sets fifo_cmd_done_intrpt; (__SELF_CLEARING__)
 * @{
 */
#define PWM_INTERRUPTS_SET__SET_INTRPT3__SHIFT                                3
#define PWM_INTERRUPTS_SET__SET_INTRPT3__WIDTH                                1
#define PWM_INTERRUPTS_SET__SET_INTRPT3__MASK                       0x00000008U
#define PWM_INTERRUPTS_SET__SET_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PWM_INTERRUPTS_SET__SET_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PWM_INTERRUPTS_SET__SET_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PWM_INTERRUPTS_SET__SET_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PWM_INTERRUPTS_SET__SET_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PWM_INTERRUPTS_SET__SET_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PWM_INTERRUPTS_SET__SET_INTRPT3__RESET_VALUE                0x00000000U
/** @} */
#define PWM_INTERRUPTS_SET__TYPE                                       uint32_t
#define PWM_INTERRUPTS_SET__READ                                    0x0000000fU
#define PWM_INTERRUPTS_SET__WRITE                                   0x0000000fU
#define PWM_INTERRUPTS_SET__PRESERVED                               0x00000000U
#define PWM_INTERRUPTS_SET__RESET_VALUE                             0x00000000U

#endif /* __PWM_INTERRUPTS_SET_MACRO__ */

/** @} end of interrupts_set */

/* macros for BlueprintGlobalNameSpace::PWM_fifo_data */
/**
 * @defgroup at_apb_pwm_regs_core_fifo_data fifo_data
 * @brief write data to be stored in fifo definitions.
 * @{
 */
#ifndef __PWM_FIFO_DATA_MACRO__
#define __PWM_FIFO_DATA_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_pwm_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details [15] selects carrier frequency  0: use carrier frequency defined by fifo_carrier1_dur  1: use carrier frequency defined by fifo_carrier2_dur [14] selects between mark and space IR regions  0: output lo for the space region in IR.  space region frame: hi_dur=0, lo_dur= hi+lo dur of selected carrier frequency  max lo_dur is limited to 16bits.  1: output value defined by hi/lo dur for the mark region in IR [13:0]: frame_count
 * @{
 */
#define PWM_FIFO_DATA__WDATA__SHIFT                                           0
#define PWM_FIFO_DATA__WDATA__WIDTH                                          16
#define PWM_FIFO_DATA__WDATA__MASK                                  0x0000ffffU
#define PWM_FIFO_DATA__WDATA__READ(src)         ((uint32_t)(src) & 0x0000ffffU)
#define PWM_FIFO_DATA__WDATA__WRITE(src)        ((uint32_t)(src) & 0x0000ffffU)
#define PWM_FIFO_DATA__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define PWM_FIFO_DATA__WDATA__VERIFY(src) (!(((uint32_t)(src) & ~0x0000ffffU)))
#define PWM_FIFO_DATA__WDATA__RESET_VALUE                           0x00000000U
/** @} */
#define PWM_FIFO_DATA__TYPE                                            uint32_t
#define PWM_FIFO_DATA__READ                                         0x0000ffffU
#define PWM_FIFO_DATA__WRITE                                        0x0000ffffU
#define PWM_FIFO_DATA__PRESERVED                                    0x00000000U
#define PWM_FIFO_DATA__RESET_VALUE                                  0x00000000U

#endif /* __PWM_FIFO_DATA_MACRO__ */

/** @} end of fifo_data */

/* macros for BlueprintGlobalNameSpace::PWM_core_id */
/**
 * @defgroup at_apb_pwm_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __PWM_CORE_ID_MACRO__
#define __PWM_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pwm_regs_core_id_field id_field
 * @brief macros for field id
 * @details PWM in ASCII
 * @{
 */
#define PWM_CORE_ID__ID__SHIFT                                                0
#define PWM_CORE_ID__ID__WIDTH                                               32
#define PWM_CORE_ID__ID__MASK                                       0xffffffffU
#define PWM_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define PWM_CORE_ID__ID__RESET_VALUE                                0x50574d20U
/** @} */
#define PWM_CORE_ID__TYPE                                              uint32_t
#define PWM_CORE_ID__READ                                           0xffffffffU
#define PWM_CORE_ID__PRESERVED                                      0x00000000U
#define PWM_CORE_ID__RESET_VALUE                                    0x50574d20U

#endif /* __PWM_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::PWM_rev_hash */
/**
 * @defgroup at_apb_pwm_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __PWM_REV_HASH_MACRO__
#define __PWM_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pwm_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define PWM_REV_HASH__ID__SHIFT                                               0
#define PWM_REV_HASH__ID__WIDTH                                              32
#define PWM_REV_HASH__ID__MASK                                      0xffffffffU
#define PWM_REV_HASH__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define PWM_REV_HASH__ID__RESET_VALUE                               0x4da5cdb2U
/** @} */
#define PWM_REV_HASH__TYPE                                             uint32_t
#define PWM_REV_HASH__READ                                          0xffffffffU
#define PWM_REV_HASH__PRESERVED                                     0x00000000U
#define PWM_REV_HASH__RESET_VALUE                                   0x4da5cdb2U

#endif /* __PWM_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::PWM_rev_key */
/**
 * @defgroup at_apb_pwm_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __PWM_REV_KEY_MACRO__
#define __PWM_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pwm_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define PWM_REV_KEY__ID__SHIFT                                                0
#define PWM_REV_KEY__ID__WIDTH                                               32
#define PWM_REV_KEY__ID__MASK                                       0xffffffffU
#define PWM_REV_KEY__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define PWM_REV_KEY__ID__RESET_VALUE                                0x52455620U
/** @} */
#define PWM_REV_KEY__TYPE                                              uint32_t
#define PWM_REV_KEY__READ                                           0xffffffffU
#define PWM_REV_KEY__PRESERVED                                      0x00000000U
#define PWM_REV_KEY__RESET_VALUE                                    0x52455620U

#endif /* __PWM_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_PWM_REGS_CORE */
#endif /* __REG_AT_APB_PWM_REGS_CORE_H__ */
