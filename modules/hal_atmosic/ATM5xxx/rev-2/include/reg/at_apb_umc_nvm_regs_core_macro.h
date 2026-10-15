/*                                                                           */
/* File:       at_apb_umc_nvm_regs_core_macro.h                              */
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


#ifndef __REG_AT_APB_UMC_NVM_REGS_CORE_H__
#define __REG_AT_APB_UMC_NVM_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_UMC_NVM_REGS_CORE at_apb_umc_nvm_regs_core
 * @ingroup AT_REG
 * @brief at_apb_umc_nvm_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::UNVM_opmode */
/**
 * @defgroup at_apb_umc_nvm_regs_core_opmode opmode
 * @brief Contains register fields associated with opmode. definitions.
 * @{
 */
#ifndef __UNVM_OPMODE_MACRO__
#define __UNVM_OPMODE_MACRO__

/* macros for field read */
/**
 * @defgroup at_apb_umc_nvm_regs_core_read_field read_field
 * @brief macros for field read
 * @details read opcode
 * @{
 */
#define UNVM_OPMODE__READ__SHIFT                                              0
#define UNVM_OPMODE__READ__WIDTH                                              1
#define UNVM_OPMODE__READ__MASK                                     0x00000001U
#define UNVM_OPMODE__READ__READ(src)            ((uint32_t)(src) & 0x00000001U)
#define UNVM_OPMODE__READ__WRITE(src)           ((uint32_t)(src) & 0x00000001U)
#define UNVM_OPMODE__READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define UNVM_OPMODE__READ__VERIFY(src)    (!(((uint32_t)(src) & ~0x00000001U)))
#define UNVM_OPMODE__READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define UNVM_OPMODE__READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define UNVM_OPMODE__READ__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field program */
/**
 * @defgroup at_apb_umc_nvm_regs_core_program_field program_field
 * @brief macros for field program
 * @details program opcode
 * @{
 */
#define UNVM_OPMODE__PROGRAM__SHIFT                                           1
#define UNVM_OPMODE__PROGRAM__WIDTH                                           1
#define UNVM_OPMODE__PROGRAM__MASK                                  0x00000002U
#define UNVM_OPMODE__PROGRAM__READ(src)  (((uint32_t)(src) & 0x00000002U) >> 1)
#define UNVM_OPMODE__PROGRAM__WRITE(src) (((uint32_t)(src) << 1) & 0x00000002U)
#define UNVM_OPMODE__PROGRAM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define UNVM_OPMODE__PROGRAM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define UNVM_OPMODE__PROGRAM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define UNVM_OPMODE__PROGRAM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define UNVM_OPMODE__PROGRAM__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_apb_umc_nvm_regs_core_go_field go_field
 * @brief macros for field go
 * @details opcode start when rising edge on 'go' is detected. self-clearing
 * @{
 */
#define UNVM_OPMODE__GO__SHIFT                                               31
#define UNVM_OPMODE__GO__WIDTH                                                1
#define UNVM_OPMODE__GO__MASK                                       0x80000000U
#define UNVM_OPMODE__GO__READ(src)      (((uint32_t)(src) & 0x80000000U) >> 31)
#define UNVM_OPMODE__GO__WRITE(src)     (((uint32_t)(src) << 31) & 0x80000000U)
#define UNVM_OPMODE__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define UNVM_OPMODE__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define UNVM_OPMODE__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define UNVM_OPMODE__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define UNVM_OPMODE__GO__RESET_VALUE                                0x00000000U
/** @} */
#define UNVM_OPMODE__TYPE                                              uint32_t
#define UNVM_OPMODE__READ                                           0x80000003U
#define UNVM_OPMODE__WRITE                                          0x80000003U
#define UNVM_OPMODE__PRESERVED                                      0x00000000U
#define UNVM_OPMODE__RESET_VALUE                                    0x00000000U

#endif /* __UNVM_OPMODE_MACRO__ */

/** @} end of opmode */

/* macros for BlueprintGlobalNameSpace::UNVM_opmode1 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_opmode1 opmode1
 * @brief Contains register fields associated with opmode1. definitions.
 * @{
 */
#ifndef __UNVM_OPMODE1_MACRO__
#define __UNVM_OPMODE1_MACRO__

/* macros for field otp_a */
/**
 * @defgroup at_apb_umc_nvm_regs_core_otp_a_field otp_a_field
 * @brief macros for field otp_a
 * @details address for otp_a[8:0]
 * @{
 */
#define UNVM_OPMODE1__OTP_A__SHIFT                                            0
#define UNVM_OPMODE1__OTP_A__WIDTH                                            9
#define UNVM_OPMODE1__OTP_A__MASK                                   0x000001ffU
#define UNVM_OPMODE1__OTP_A__READ(src)          ((uint32_t)(src) & 0x000001ffU)
#define UNVM_OPMODE1__OTP_A__WRITE(src)         ((uint32_t)(src) & 0x000001ffU)
#define UNVM_OPMODE1__OTP_A__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define UNVM_OPMODE1__OTP_A__VERIFY(src)  (!(((uint32_t)(src) & ~0x000001ffU)))
#define UNVM_OPMODE1__OTP_A__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field otp_a_map */
/**
 * @defgroup at_apb_umc_nvm_regs_core_otp_a_map_field otp_a_map_field
 * @brief macros for field otp_a_map
 * @details program data map for otp_a[9:7], each map to a otp_a[9:7]
 * @{
 */
#define UNVM_OPMODE1__OTP_A_MAP__SHIFT                                       16
#define UNVM_OPMODE1__OTP_A_MAP__WIDTH                                        8
#define UNVM_OPMODE1__OTP_A_MAP__MASK                               0x00ff0000U
#define UNVM_OPMODE1__OTP_A_MAP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define UNVM_OPMODE1__OTP_A_MAP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define UNVM_OPMODE1__OTP_A_MAP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define UNVM_OPMODE1__OTP_A_MAP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define UNVM_OPMODE1__OTP_A_MAP__RESET_VALUE                        0x00000000U
/** @} */
#define UNVM_OPMODE1__TYPE                                             uint32_t
#define UNVM_OPMODE1__READ                                          0x00ff01ffU
#define UNVM_OPMODE1__WRITE                                         0x00ff01ffU
#define UNVM_OPMODE1__PRESERVED                                     0x00000000U
#define UNVM_OPMODE1__RESET_VALUE                                   0x00000000U

#endif /* __UNVM_OPMODE1_MACRO__ */

/** @} end of opmode1 */

/* macros for BlueprintGlobalNameSpace::UNVM_status */
/**
 * @defgroup at_apb_umc_nvm_regs_core_status status
 * @brief Contains register fields associated with status. definitions.
 * @{
 */
#ifndef __UNVM_STATUS_MACRO__
#define __UNVM_STATUS_MACRO__

/* macros for field done */
/**
 * @defgroup at_apb_umc_nvm_regs_core_done_field done_field
 * @brief macros for field done
 * @details read/program done
 * @{
 */
#define UNVM_STATUS__DONE__SHIFT                                              0
#define UNVM_STATUS__DONE__WIDTH                                              1
#define UNVM_STATUS__DONE__MASK                                     0x00000001U
#define UNVM_STATUS__DONE__READ(src)            ((uint32_t)(src) & 0x00000001U)
#define UNVM_STATUS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define UNVM_STATUS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define UNVM_STATUS__DONE__RESET_VALUE                              0x00000000U
/** @} */

/* macros for field otp_q */
/**
 * @defgroup at_apb_umc_nvm_regs_core_otp_q_field otp_q_field
 * @brief macros for field otp_q
 * @details read data
 * @{
 */
#define UNVM_STATUS__OTP_Q__SHIFT                                            16
#define UNVM_STATUS__OTP_Q__WIDTH                                             8
#define UNVM_STATUS__OTP_Q__MASK                                    0x00ff0000U
#define UNVM_STATUS__OTP_Q__READ(src)   (((uint32_t)(src) & 0x00ff0000U) >> 16)
#define UNVM_STATUS__OTP_Q__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field running */
/**
 * @defgroup at_apb_umc_nvm_regs_core_running_field running_field
 * @brief macros for field running
 * @details read or program running
 * @{
 */
#define UNVM_STATUS__RUNNING__SHIFT                                          31
#define UNVM_STATUS__RUNNING__WIDTH                                           1
#define UNVM_STATUS__RUNNING__MASK                                  0x80000000U
#define UNVM_STATUS__RUNNING__READ(src) (((uint32_t)(src) & 0x80000000U) >> 31)
#define UNVM_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define UNVM_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define UNVM_STATUS__RUNNING__RESET_VALUE                           0x00000000U
/** @} */
#define UNVM_STATUS__TYPE                                              uint32_t
#define UNVM_STATUS__READ                                           0x80ff0001U
#define UNVM_STATUS__PRESERVED                                      0x00000000U
#define UNVM_STATUS__RESET_VALUE                                    0x00000000U

#endif /* __UNVM_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::UNVM_status1 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_status1 status1
 * @brief Contains register fields associated with status1. definitions.
 * @{
 */
#ifndef __UNVM_STATUS1_MACRO__
#define __UNVM_STATUS1_MACRO__

/* macros for field auto_read_busy */
/**
 * @defgroup at_apb_umc_nvm_regs_core_auto_read_busy_field auto_read_busy_field
 * @brief macros for field auto_read_busy
 * @details auto read is running
 * @{
 */
#define UNVM_STATUS1__AUTO_READ_BUSY__SHIFT                                   0
#define UNVM_STATUS1__AUTO_READ_BUSY__WIDTH                                   1
#define UNVM_STATUS1__AUTO_READ_BUSY__MASK                          0x00000001U
#define UNVM_STATUS1__AUTO_READ_BUSY__READ(src) ((uint32_t)(src) & 0x00000001U)
#define UNVM_STATUS1__AUTO_READ_BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define UNVM_STATUS1__AUTO_READ_BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define UNVM_STATUS1__AUTO_READ_BUSY__RESET_VALUE                   0x00000000U
/** @} */
#define UNVM_STATUS1__TYPE                                             uint32_t
#define UNVM_STATUS1__READ                                          0x00000001U
#define UNVM_STATUS1__PRESERVED                                     0x00000000U
#define UNVM_STATUS1__RESET_VALUE                                   0x00000000U

#endif /* __UNVM_STATUS1_MACRO__ */

/** @} end of status1 */

/* macros for BlueprintGlobalNameSpace::UNVM_otp_cfg_low */
/**
 * @defgroup at_apb_umc_nvm_regs_core_otp_cfg_low otp_cfg_low
 * @brief low 32 bits definitions.
 * @{
 */
#ifndef __UNVM_OTP_CFG_LOW_MACRO__
#define __UNVM_OTP_CFG_LOW_MACRO__

/* macros for field otp_cfg_low */
/**
 * @defgroup at_apb_umc_nvm_regs_core_otp_cfg_low_field otp_cfg_low_field
 * @brief macros for field otp_cfg_low
 * @details low 32 bits
 * @{
 */
#define UNVM_OTP_CFG_LOW__OTP_CFG_LOW__SHIFT                                  0
#define UNVM_OTP_CFG_LOW__OTP_CFG_LOW__WIDTH                                 32
#define UNVM_OTP_CFG_LOW__OTP_CFG_LOW__MASK                         0xffffffffU
#define UNVM_OTP_CFG_LOW__OTP_CFG_LOW__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define UNVM_OTP_CFG_LOW__OTP_CFG_LOW__RESET_VALUE                  0x00000000U
/** @} */
#define UNVM_OTP_CFG_LOW__TYPE                                         uint32_t
#define UNVM_OTP_CFG_LOW__READ                                      0xffffffffU
#define UNVM_OTP_CFG_LOW__PRESERVED                                 0x00000000U
#define UNVM_OTP_CFG_LOW__RESET_VALUE                               0x00000000U

#endif /* __UNVM_OTP_CFG_LOW_MACRO__ */

/** @} end of otp_cfg_low */

/* macros for BlueprintGlobalNameSpace::UNVM_otp_cfg_high */
/**
 * @defgroup at_apb_umc_nvm_regs_core_otp_cfg_high otp_cfg_high
 * @brief high 32 bits definitions.
 * @{
 */
#ifndef __UNVM_OTP_CFG_HIGH_MACRO__
#define __UNVM_OTP_CFG_HIGH_MACRO__

/* macros for field otp_cfg_high */
/**
 * @defgroup at_apb_umc_nvm_regs_core_otp_cfg_high_field otp_cfg_high_field
 * @brief macros for field otp_cfg_high
 * @details high 32 bits
 * @{
 */
#define UNVM_OTP_CFG_HIGH__OTP_CFG_HIGH__SHIFT                                0
#define UNVM_OTP_CFG_HIGH__OTP_CFG_HIGH__WIDTH                               32
#define UNVM_OTP_CFG_HIGH__OTP_CFG_HIGH__MASK                       0xffffffffU
#define UNVM_OTP_CFG_HIGH__OTP_CFG_HIGH__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define UNVM_OTP_CFG_HIGH__OTP_CFG_HIGH__RESET_VALUE                0x00000000U
/** @} */
#define UNVM_OTP_CFG_HIGH__TYPE                                        uint32_t
#define UNVM_OTP_CFG_HIGH__READ                                     0xffffffffU
#define UNVM_OTP_CFG_HIGH__PRESERVED                                0x00000000U
#define UNVM_OTP_CFG_HIGH__RESET_VALUE                              0x00000000U

#endif /* __UNVM_OTP_CFG_HIGH_MACRO__ */

/** @} end of otp_cfg_high */

/* macros for BlueprintGlobalNameSpace::UNVM_t_rd_time0 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_rd_time0 t_rd_time0
 * @brief READ mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_RD_TIME0_MACRO__
#define __UNVM_T_RD_TIME0_MACRO__

/* macros for field t_sur_pg */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_pg_field t_sur_pg_field
 * @brief macros for field t_sur_pg
 * @details want >= 5.9ns, setup time from PGENB to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME0__T_SUR_PG__SHIFT                                      0
#define UNVM_T_RD_TIME0__T_SUR_PG__WIDTH                                      2
#define UNVM_T_RD_TIME0__T_SUR_PG__MASK                             0x00000003U
#define UNVM_T_RD_TIME0__T_SUR_PG__READ(src)    ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME0__T_SUR_PG__WRITE(src)   ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME0__T_SUR_PG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_RD_TIME0__T_SUR_PG__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_RD_TIME0__T_SUR_PG__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field t_sur_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_cs_field t_sur_cs_field
 * @brief macros for field t_sur_cs
 * @details want >= 6.2ns, setup time from CSB to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME0__T_SUR_CS__SHIFT                                      8
#define UNVM_T_RD_TIME0__T_SUR_CS__WIDTH                                      2
#define UNVM_T_RD_TIME0__T_SUR_CS__MASK                             0x00000300U
#define UNVM_T_RD_TIME0__T_SUR_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define UNVM_T_RD_TIME0__T_SUR_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define UNVM_T_RD_TIME0__T_SUR_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define UNVM_T_RD_TIME0__T_SUR_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define UNVM_T_RD_TIME0__T_SUR_CS__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field t_sur_ps_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_ps_cs_field t_sur_ps_cs_field
 * @brief macros for field t_sur_ps_cs
 * @details want >= 50ns, setup time from PS to CSB.
 * @{
 */
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__SHIFT                                  16
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__WIDTH                                   2
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__MASK                          0x00030000U
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_RD_TIME0__T_SUR_PS_CS__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field t_sur_pd_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_pd_cs_field t_sur_pd_cs_field
 * @brief macros for field t_sur_pd_cs
 * @details want >= 500ns, setup time from PD to CSB.
 * @{
 */
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__SHIFT                                  24
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__WIDTH                                   4
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__MASK                          0x0f000000U
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define UNVM_T_RD_TIME0__T_SUR_PD_CS__RESET_VALUE                   0x00000009U
/** @} */
#define UNVM_T_RD_TIME0__TYPE                                          uint32_t
#define UNVM_T_RD_TIME0__READ                                       0x0f030303U
#define UNVM_T_RD_TIME0__WRITE                                      0x0f030303U
#define UNVM_T_RD_TIME0__PRESERVED                                  0x00000000U
#define UNVM_T_RD_TIME0__RESET_VALUE                                0x09010101U

#endif /* __UNVM_T_RD_TIME0_MACRO__ */

/** @} end of t_rd_time0 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_rd_time1 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_rd_time1 t_rd_time1
 * @brief READ mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_RD_TIME1_MACRO__
#define __UNVM_T_RD_TIME1_MACRO__

/* macros for field t_sur_ps */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_ps_field t_sur_ps_field
 * @brief macros for field t_sur_ps
 * @details want >= 56.6ns, t_sur_ps >= t_sur_ps_cs + t_sur_cs, setup time rom PS to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME1__T_SUR_PS__SHIFT                                      0
#define UNVM_T_RD_TIME1__T_SUR_PS__WIDTH                                      2
#define UNVM_T_RD_TIME1__T_SUR_PS__MASK                             0x00000003U
#define UNVM_T_RD_TIME1__T_SUR_PS__READ(src)    ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME1__T_SUR_PS__WRITE(src)   ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME1__T_SUR_PS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_RD_TIME1__T_SUR_PS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_RD_TIME1__T_SUR_PS__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field t_sur_pd */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_pd_field t_sur_pd_field
 * @brief macros for field t_sur_pd
 * @details want >= 506.6ns, t_sur_pd >= t_sur_pd_cs + t_sur_cs, setup time from PD to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME1__T_SUR_PD__SHIFT                                      8
#define UNVM_T_RD_TIME1__T_SUR_PD__WIDTH                                      4
#define UNVM_T_RD_TIME1__T_SUR_PD__MASK                             0x00000f00U
#define UNVM_T_RD_TIME1__T_SUR_PD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define UNVM_T_RD_TIME1__T_SUR_PD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define UNVM_T_RD_TIME1__T_SUR_PD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define UNVM_T_RD_TIME1__T_SUR_PD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define UNVM_T_RD_TIME1__T_SUR_PD__RESET_VALUE                      0x00000009U
/** @} */

/* macros for field t_sur_a */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_a_field t_sur_a_field
 * @brief macros for field t_sur_a
 * @details want >= 6ns, setup time from A to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME1__T_SUR_A__SHIFT                                      16
#define UNVM_T_RD_TIME1__T_SUR_A__WIDTH                                       2
#define UNVM_T_RD_TIME1__T_SUR_A__MASK                              0x00030000U
#define UNVM_T_RD_TIME1__T_SUR_A__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_RD_TIME1__T_SUR_A__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_RD_TIME1__T_SUR_A__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_RD_TIME1__T_SUR_A__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_RD_TIME1__T_SUR_A__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_sur_ld */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sur_ld_field t_sur_ld_field
 * @brief macros for field t_sur_ld
 * @details want >= 6.0ns, setup time from LOAD to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME1__T_SUR_LD__SHIFT                                     24
#define UNVM_T_RD_TIME1__T_SUR_LD__WIDTH                                      2
#define UNVM_T_RD_TIME1__T_SUR_LD__MASK                             0x03000000U
#define UNVM_T_RD_TIME1__T_SUR_LD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define UNVM_T_RD_TIME1__T_SUR_LD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define UNVM_T_RD_TIME1__T_SUR_LD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define UNVM_T_RD_TIME1__T_SUR_LD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define UNVM_T_RD_TIME1__T_SUR_LD__RESET_VALUE                      0x00000001U
/** @} */
#define UNVM_T_RD_TIME1__TYPE                                          uint32_t
#define UNVM_T_RD_TIME1__READ                                       0x03030f03U
#define UNVM_T_RD_TIME1__WRITE                                      0x03030f03U
#define UNVM_T_RD_TIME1__PRESERVED                                  0x00000000U
#define UNVM_T_RD_TIME1__RESET_VALUE                                0x01010901U

#endif /* __UNVM_T_RD_TIME1_MACRO__ */

/** @} end of t_rd_time1 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_rd_time2 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_rd_time2 t_rd_time2
 * @brief READ mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_RD_TIME2_MACRO__
#define __UNVM_T_RD_TIME2_MACRO__

/* macros for field t_hr_ps_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_ps_cs_field t_hr_ps_cs_field
 * @brief macros for field t_hr_ps_cs
 * @details want >= 50.0ns, hold time from PS to CSB.
 * @{
 */
#define UNVM_T_RD_TIME2__T_HR_PS_CS__SHIFT                                    0
#define UNVM_T_RD_TIME2__T_HR_PS_CS__WIDTH                                    2
#define UNVM_T_RD_TIME2__T_HR_PS_CS__MASK                           0x00000003U
#define UNVM_T_RD_TIME2__T_HR_PS_CS__READ(src)  ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME2__T_HR_PS_CS__WRITE(src) ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME2__T_HR_PS_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_RD_TIME2__T_HR_PS_CS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_RD_TIME2__T_HR_PS_CS__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field t_hr_ps */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_ps_field t_hr_ps_field
 * @brief macros for field t_hr_ps
 * @details want >= 56.2ns, hold time from PS to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME2__T_HR_PS__SHIFT                                       8
#define UNVM_T_RD_TIME2__T_HR_PS__WIDTH                                       2
#define UNVM_T_RD_TIME2__T_HR_PS__MASK                              0x00000300U
#define UNVM_T_RD_TIME2__T_HR_PS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define UNVM_T_RD_TIME2__T_HR_PS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define UNVM_T_RD_TIME2__T_HR_PS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define UNVM_T_RD_TIME2__T_HR_PS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define UNVM_T_RD_TIME2__T_HR_PS__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_hr_pd_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_pd_cs_field t_hr_pd_cs_field
 * @brief macros for field t_hr_pd_cs
 * @details want >= 1.0ns, hold time from PD to CSB.
 * @{
 */
#define UNVM_T_RD_TIME2__T_HR_PD_CS__SHIFT                                   16
#define UNVM_T_RD_TIME2__T_HR_PD_CS__WIDTH                                    2
#define UNVM_T_RD_TIME2__T_HR_PD_CS__MASK                           0x00030000U
#define UNVM_T_RD_TIME2__T_HR_PD_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_RD_TIME2__T_HR_PD_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_RD_TIME2__T_HR_PD_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_RD_TIME2__T_HR_PD_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_RD_TIME2__T_HR_PD_CS__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field t_hr_pd */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_pd_field t_hr_pd_field
 * @brief macros for field t_hr_pd
 * @details want >= 7.2ns, and t_hr_pd >= t_hr_pd_cs + t_hr_cs, hold time from PD to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME2__T_HR_PD__SHIFT                                      24
#define UNVM_T_RD_TIME2__T_HR_PD__WIDTH                                       2
#define UNVM_T_RD_TIME2__T_HR_PD__MASK                              0x03000000U
#define UNVM_T_RD_TIME2__T_HR_PD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define UNVM_T_RD_TIME2__T_HR_PD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define UNVM_T_RD_TIME2__T_HR_PD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define UNVM_T_RD_TIME2__T_HR_PD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define UNVM_T_RD_TIME2__T_HR_PD__RESET_VALUE                       0x00000002U
/** @} */
#define UNVM_T_RD_TIME2__TYPE                                          uint32_t
#define UNVM_T_RD_TIME2__READ                                       0x03030303U
#define UNVM_T_RD_TIME2__WRITE                                      0x03030303U
#define UNVM_T_RD_TIME2__PRESERVED                                  0x00000000U
#define UNVM_T_RD_TIME2__RESET_VALUE                                0x02010101U

#endif /* __UNVM_T_RD_TIME2_MACRO__ */

/** @} end of t_rd_time2 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_rd_time3 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_rd_time3 t_rd_time3
 * @brief READ mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_RD_TIME3_MACRO__
#define __UNVM_T_RD_TIME3_MACRO__

/* macros for field t_hr_a */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_a_field t_hr_a_field
 * @brief macros for field t_hr_a
 * @details want >= 6.0ns, hold time from A to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME3__T_HR_A__SHIFT                                        0
#define UNVM_T_RD_TIME3__T_HR_A__WIDTH                                        2
#define UNVM_T_RD_TIME3__T_HR_A__MASK                               0x00000003U
#define UNVM_T_RD_TIME3__T_HR_A__READ(src)      ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME3__T_HR_A__WRITE(src)     ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME3__T_HR_A__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_RD_TIME3__T_HR_A__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_RD_TIME3__T_HR_A__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field t_hr_ld */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_ld_field t_hr_ld_field
 * @brief macros for field t_hr_ld
 * @details want >= 6.0ns, hold time from LOAD to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME3__T_HR_LD__SHIFT                                       8
#define UNVM_T_RD_TIME3__T_HR_LD__WIDTH                                       2
#define UNVM_T_RD_TIME3__T_HR_LD__MASK                              0x00000300U
#define UNVM_T_RD_TIME3__T_HR_LD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define UNVM_T_RD_TIME3__T_HR_LD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define UNVM_T_RD_TIME3__T_HR_LD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define UNVM_T_RD_TIME3__T_HR_LD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define UNVM_T_RD_TIME3__T_HR_LD__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_hr_pg */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_pg_field t_hr_pg_field
 * @brief macros for field t_hr_pg
 * @details want >= 6.1ns, hold time from PGENB to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME3__T_HR_PG__SHIFT                                      16
#define UNVM_T_RD_TIME3__T_HR_PG__WIDTH                                       2
#define UNVM_T_RD_TIME3__T_HR_PG__MASK                              0x00030000U
#define UNVM_T_RD_TIME3__T_HR_PG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_RD_TIME3__T_HR_PG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_RD_TIME3__T_HR_PG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_RD_TIME3__T_HR_PG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_RD_TIME3__T_HR_PG__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_hr_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hr_cs_field t_hr_cs_field
 * @brief macros for field t_hr_cs
 * @details want >= 6.2ns, hold time from CSB to STROBE.
 * @{
 */
#define UNVM_T_RD_TIME3__T_HR_CS__SHIFT                                      24
#define UNVM_T_RD_TIME3__T_HR_CS__WIDTH                                       2
#define UNVM_T_RD_TIME3__T_HR_CS__MASK                              0x03000000U
#define UNVM_T_RD_TIME3__T_HR_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define UNVM_T_RD_TIME3__T_HR_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define UNVM_T_RD_TIME3__T_HR_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define UNVM_T_RD_TIME3__T_HR_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define UNVM_T_RD_TIME3__T_HR_CS__RESET_VALUE                       0x00000001U
/** @} */
#define UNVM_T_RD_TIME3__TYPE                                          uint32_t
#define UNVM_T_RD_TIME3__READ                                       0x03030303U
#define UNVM_T_RD_TIME3__WRITE                                      0x03030303U
#define UNVM_T_RD_TIME3__PRESERVED                                  0x00000000U
#define UNVM_T_RD_TIME3__RESET_VALUE                                0x01010101U

#endif /* __UNVM_T_RD_TIME3_MACRO__ */

/** @} end of t_rd_time3 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_rd_time4 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_rd_time4 t_rd_time4
 * @brief READ mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_RD_TIME4_MACRO__
#define __UNVM_T_RD_TIME4_MACRO__

/* macros for field t_rd */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_rd_field t_rd_field
 * @brief macros for field t_rd
 * @details want >= 30.3ns, STROBE pulse width.
 * @{
 */
#define UNVM_T_RD_TIME4__T_RD__SHIFT                                          0
#define UNVM_T_RD_TIME4__T_RD__WIDTH                                          2
#define UNVM_T_RD_TIME4__T_RD__MASK                                 0x00000003U
#define UNVM_T_RD_TIME4__T_RD__READ(src)        ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME4__T_RD__WRITE(src)       ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_RD_TIME4__T_RD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_RD_TIME4__T_RD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_RD_TIME4__T_RD__RESET_VALUE                          0x00000001U
/** @} */
#define UNVM_T_RD_TIME4__TYPE                                          uint32_t
#define UNVM_T_RD_TIME4__READ                                       0x00000003U
#define UNVM_T_RD_TIME4__WRITE                                      0x00000003U
#define UNVM_T_RD_TIME4__PRESERVED                                  0x00000000U
#define UNVM_T_RD_TIME4__RESET_VALUE                                0x00000001U

#endif /* __UNVM_T_RD_TIME4_MACRO__ */

/** @} end of t_rd_time4 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_pr_time0 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pr_time0 t_pr_time0
 * @brief PROGRAM mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_PR_TIME0_MACRO__
#define __UNVM_T_PR_TIME0_MACRO__

/* macros for field t_sup_pg */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_pg_field t_sup_pg_field
 * @brief macros for field t_sup_pg
 * @details want >= 6.0ns, setup time from PGENB to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME0__T_SUP_PG__SHIFT                                      0
#define UNVM_T_PR_TIME0__T_SUP_PG__WIDTH                                      2
#define UNVM_T_PR_TIME0__T_SUP_PG__MASK                             0x00000003U
#define UNVM_T_PR_TIME0__T_SUP_PG__READ(src)    ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME0__T_SUP_PG__WRITE(src)   ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME0__T_SUP_PG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_PR_TIME0__T_SUP_PG__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_PR_TIME0__T_SUP_PG__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field t_sup_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_cs_field t_sup_cs_field
 * @brief macros for field t_sup_cs
 * @details want >= 6.6ns, setup time from CSB to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME0__T_SUP_CS__SHIFT                                      8
#define UNVM_T_PR_TIME0__T_SUP_CS__WIDTH                                      2
#define UNVM_T_PR_TIME0__T_SUP_CS__MASK                             0x00000300U
#define UNVM_T_PR_TIME0__T_SUP_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define UNVM_T_PR_TIME0__T_SUP_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define UNVM_T_PR_TIME0__T_SUP_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define UNVM_T_PR_TIME0__T_SUP_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define UNVM_T_PR_TIME0__T_SUP_CS__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field t_sup_ps_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_ps_cs_field t_sup_ps_cs_field
 * @brief macros for field t_sup_ps_cs
 * @details want >= 50ns, setup time from PS to CSB.
 * @{
 */
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__SHIFT                                  16
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__WIDTH                                   2
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__MASK                          0x00030000U
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_PR_TIME0__T_SUP_PS_CS__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field t_sup_pd */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_pd_field t_sup_pd_field
 * @brief macros for field t_sup_pd
 * @details want >=556.6ns, t_sup_pd >= t_sup_pd_ps + t_sup_ps, setup time from PD to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME0__T_SUP_PD__SHIFT                                     24
#define UNVM_T_PR_TIME0__T_SUP_PD__WIDTH                                      4
#define UNVM_T_PR_TIME0__T_SUP_PD__MASK                             0x0f000000U
#define UNVM_T_PR_TIME0__T_SUP_PD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define UNVM_T_PR_TIME0__T_SUP_PD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define UNVM_T_PR_TIME0__T_SUP_PD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define UNVM_T_PR_TIME0__T_SUP_PD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))
#define UNVM_T_PR_TIME0__T_SUP_PD__RESET_VALUE                      0x00000009U
/** @} */
#define UNVM_T_PR_TIME0__TYPE                                          uint32_t
#define UNVM_T_PR_TIME0__READ                                       0x0f030303U
#define UNVM_T_PR_TIME0__WRITE                                      0x0f030303U
#define UNVM_T_PR_TIME0__PRESERVED                                  0x00000000U
#define UNVM_T_PR_TIME0__RESET_VALUE                                0x09010101U

#endif /* __UNVM_T_PR_TIME0_MACRO__ */

/** @} end of t_pr_time0 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_pr_time1 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pr_time1 t_pr_time1
 * @brief PROGRAM mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_PR_TIME1_MACRO__
#define __UNVM_T_PR_TIME1_MACRO__

/* macros for field t_sup_ps */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_ps_field t_sup_ps_field
 * @brief macros for field t_sup_ps
 * @details want >= 56.6ns, t_sup_ps >= t_sup_ps_cs + t_sup_cs, setup time from PS to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME1__T_SUP_PS__SHIFT                                      0
#define UNVM_T_PR_TIME1__T_SUP_PS__WIDTH                                      2
#define UNVM_T_PR_TIME1__T_SUP_PS__MASK                             0x00000003U
#define UNVM_T_PR_TIME1__T_SUP_PS__READ(src)    ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME1__T_SUP_PS__WRITE(src)   ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME1__T_SUP_PS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_PR_TIME1__T_SUP_PS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_PR_TIME1__T_SUP_PS__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field t_sup_pd_ps */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_pd_ps_field t_sup_pd_ps_field
 * @brief macros for field t_sup_pd_ps
 * @details want >= 500ns, setup time from PD to PS.
 * @{
 */
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__SHIFT                                   8
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__WIDTH                                   4
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__MASK                          0x00000f00U
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define UNVM_T_PR_TIME1__T_SUP_PD_PS__RESET_VALUE                   0x00000009U
/** @} */

/* macros for field t_sup_a */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_a_field t_sup_a_field
 * @brief macros for field t_sup_a
 * @details want >= 6.3ns, setup time from A to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME1__T_SUP_A__SHIFT                                      16
#define UNVM_T_PR_TIME1__T_SUP_A__WIDTH                                       2
#define UNVM_T_PR_TIME1__T_SUP_A__MASK                              0x00030000U
#define UNVM_T_PR_TIME1__T_SUP_A__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_PR_TIME1__T_SUP_A__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_PR_TIME1__T_SUP_A__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_PR_TIME1__T_SUP_A__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_PR_TIME1__T_SUP_A__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_sup_ld */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_ld_field t_sup_ld_field
 * @brief macros for field t_sup_ld
 * @details want >= 6.2ns, setup time from LOAD to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME1__T_SUP_LD__SHIFT                                     24
#define UNVM_T_PR_TIME1__T_SUP_LD__WIDTH                                      2
#define UNVM_T_PR_TIME1__T_SUP_LD__MASK                             0x03000000U
#define UNVM_T_PR_TIME1__T_SUP_LD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define UNVM_T_PR_TIME1__T_SUP_LD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define UNVM_T_PR_TIME1__T_SUP_LD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define UNVM_T_PR_TIME1__T_SUP_LD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define UNVM_T_PR_TIME1__T_SUP_LD__RESET_VALUE                      0x00000001U
/** @} */
#define UNVM_T_PR_TIME1__TYPE                                          uint32_t
#define UNVM_T_PR_TIME1__READ                                       0x03030f03U
#define UNVM_T_PR_TIME1__WRITE                                      0x03030f03U
#define UNVM_T_PR_TIME1__PRESERVED                                  0x00000000U
#define UNVM_T_PR_TIME1__RESET_VALUE                                0x01010901U

#endif /* __UNVM_T_PR_TIME1_MACRO__ */

/** @} end of t_pr_time1 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_pr_time2 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pr_time2 t_pr_time2
 * @brief PROGRAM mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_PR_TIME2_MACRO__
#define __UNVM_T_PR_TIME2_MACRO__

/* macros for field t_hp_ps_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_ps_cs_field t_hp_ps_cs_field
 * @brief macros for field t_hp_ps_cs
 * @details want >= 50.0ns, hold time from PS to CSB.
 * @{
 */
#define UNVM_T_PR_TIME2__T_HP_PS_CS__SHIFT                                    0
#define UNVM_T_PR_TIME2__T_HP_PS_CS__WIDTH                                    2
#define UNVM_T_PR_TIME2__T_HP_PS_CS__MASK                           0x00000003U
#define UNVM_T_PR_TIME2__T_HP_PS_CS__READ(src)  ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME2__T_HP_PS_CS__WRITE(src) ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME2__T_HP_PS_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_PR_TIME2__T_HP_PS_CS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_PR_TIME2__T_HP_PS_CS__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field t_hp_ps */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_ps_field t_hp_ps_field
 * @brief macros for field t_hp_ps
 * @details want >= 56.2ns, t_hp_ps >= t_hp_ps_cs + t_hp_cs, hold time from PS to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME2__T_HP_PS__SHIFT                                       8
#define UNVM_T_PR_TIME2__T_HP_PS__WIDTH                                       2
#define UNVM_T_PR_TIME2__T_HP_PS__MASK                              0x00000300U
#define UNVM_T_PR_TIME2__T_HP_PS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define UNVM_T_PR_TIME2__T_HP_PS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define UNVM_T_PR_TIME2__T_HP_PS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define UNVM_T_PR_TIME2__T_HP_PS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define UNVM_T_PR_TIME2__T_HP_PS__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_hp_pd_ps */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_pd_ps_field t_hp_pd_ps_field
 * @brief macros for field t_hp_pd_ps
 * @details want >= 1.0ns, hold time from PD to PS
 * @{
 */
#define UNVM_T_PR_TIME2__T_HP_PD_PS__SHIFT                                   16
#define UNVM_T_PR_TIME2__T_HP_PD_PS__WIDTH                                    2
#define UNVM_T_PR_TIME2__T_HP_PD_PS__MASK                           0x00030000U
#define UNVM_T_PR_TIME2__T_HP_PD_PS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_PR_TIME2__T_HP_PD_PS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_PR_TIME2__T_HP_PD_PS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_PR_TIME2__T_HP_PD_PS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_PR_TIME2__T_HP_PD_PS__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field t_hp_pd */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_pd_field t_hp_pd_field
 * @brief macros for field t_hp_pd
 * @details want >= 57.2ns, t_hp_pd >= t_hp_pd_ps + t_hp_ps, hold time from PD to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME2__T_HP_PD__SHIFT                                      24
#define UNVM_T_PR_TIME2__T_HP_PD__WIDTH                                       2
#define UNVM_T_PR_TIME2__T_HP_PD__MASK                              0x03000000U
#define UNVM_T_PR_TIME2__T_HP_PD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define UNVM_T_PR_TIME2__T_HP_PD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define UNVM_T_PR_TIME2__T_HP_PD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define UNVM_T_PR_TIME2__T_HP_PD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define UNVM_T_PR_TIME2__T_HP_PD__RESET_VALUE                       0x00000002U
/** @} */
#define UNVM_T_PR_TIME2__TYPE                                          uint32_t
#define UNVM_T_PR_TIME2__READ                                       0x03030303U
#define UNVM_T_PR_TIME2__WRITE                                      0x03030303U
#define UNVM_T_PR_TIME2__PRESERVED                                  0x00000000U
#define UNVM_T_PR_TIME2__RESET_VALUE                                0x02010101U

#endif /* __UNVM_T_PR_TIME2_MACRO__ */

/** @} end of t_pr_time2 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_pr_time3 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pr_time3 t_pr_time3
 * @brief PROGRAM mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_PR_TIME3_MACRO__
#define __UNVM_T_PR_TIME3_MACRO__

/* macros for field t_hp_a */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_a_field t_hp_a_field
 * @brief macros for field t_hp_a
 * @details want >= 6.0ns, hold time from A to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME3__T_HP_A__SHIFT                                        0
#define UNVM_T_PR_TIME3__T_HP_A__WIDTH                                        2
#define UNVM_T_PR_TIME3__T_HP_A__MASK                               0x00000003U
#define UNVM_T_PR_TIME3__T_HP_A__READ(src)      ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME3__T_HP_A__WRITE(src)     ((uint32_t)(src) & 0x00000003U)
#define UNVM_T_PR_TIME3__T_HP_A__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define UNVM_T_PR_TIME3__T_HP_A__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define UNVM_T_PR_TIME3__T_HP_A__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field t_hp_ld */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_ld_field t_hp_ld_field
 * @brief macros for field t_hp_ld
 * @details want >= 6.1ns, hold time from LOAD to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME3__T_HP_LD__SHIFT                                       8
#define UNVM_T_PR_TIME3__T_HP_LD__WIDTH                                       2
#define UNVM_T_PR_TIME3__T_HP_LD__MASK                              0x00000300U
#define UNVM_T_PR_TIME3__T_HP_LD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define UNVM_T_PR_TIME3__T_HP_LD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define UNVM_T_PR_TIME3__T_HP_LD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define UNVM_T_PR_TIME3__T_HP_LD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define UNVM_T_PR_TIME3__T_HP_LD__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_hp_pg */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_pg_field t_hp_pg_field
 * @brief macros for field t_hp_pg
 * @details want >= 6.1ns, hold time from PGENB to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME3__T_HP_PG__SHIFT                                      16
#define UNVM_T_PR_TIME3__T_HP_PG__WIDTH                                       2
#define UNVM_T_PR_TIME3__T_HP_PG__MASK                              0x00030000U
#define UNVM_T_PR_TIME3__T_HP_PG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define UNVM_T_PR_TIME3__T_HP_PG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define UNVM_T_PR_TIME3__T_HP_PG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define UNVM_T_PR_TIME3__T_HP_PG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define UNVM_T_PR_TIME3__T_HP_PG__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field t_hp_cs */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_cs_field t_hp_cs_field
 * @brief macros for field t_hp_cs
 * @details want >= 6.2ns, hold time from CSB to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME3__T_HP_CS__SHIFT                                      24
#define UNVM_T_PR_TIME3__T_HP_CS__WIDTH                                       2
#define UNVM_T_PR_TIME3__T_HP_CS__MASK                              0x03000000U
#define UNVM_T_PR_TIME3__T_HP_CS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define UNVM_T_PR_TIME3__T_HP_CS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define UNVM_T_PR_TIME3__T_HP_CS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define UNVM_T_PR_TIME3__T_HP_CS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define UNVM_T_PR_TIME3__T_HP_CS__RESET_VALUE                       0x00000001U
/** @} */
#define UNVM_T_PR_TIME3__TYPE                                          uint32_t
#define UNVM_T_PR_TIME3__READ                                       0x03030303U
#define UNVM_T_PR_TIME3__WRITE                                      0x03030303U
#define UNVM_T_PR_TIME3__PRESERVED                                  0x00000000U
#define UNVM_T_PR_TIME3__RESET_VALUE                                0x01010101U

#endif /* __UNVM_T_PR_TIME3_MACRO__ */

/** @} end of t_pr_time3 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_pr_time4 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pr_time4 t_pr_time4
 * @brief PROGRAM mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_PR_TIME4_MACRO__
#define __UNVM_T_PR_TIME4_MACRO__

/* macros for field t_hp_por */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_hp_por_field t_hp_por_field
 * @brief macros for field t_hp_por
 * @details t_hp_por_pd want >= 1000ns, t_hp_por = t_hp_por_pd + t_hp_pd, hold time from POR33 to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME4__T_HP_POR__SHIFT                                      0
#define UNVM_T_PR_TIME4__T_HP_POR__WIDTH                                      6
#define UNVM_T_PR_TIME4__T_HP_POR__MASK                             0x0000003fU
#define UNVM_T_PR_TIME4__T_HP_POR__READ(src)    ((uint32_t)(src) & 0x0000003fU)
#define UNVM_T_PR_TIME4__T_HP_POR__WRITE(src)   ((uint32_t)(src) & 0x0000003fU)
#define UNVM_T_PR_TIME4__T_HP_POR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define UNVM_T_PR_TIME4__T_HP_POR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define UNVM_T_PR_TIME4__T_HP_POR__RESET_VALUE                      0x00000012U
/** @} */

/* macros for field t_sup_por */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_sup_por_field t_sup_por_field
 * @brief macros for field t_sup_por
 * @details t_sup_por_pd want >= 1000ns, t_sup_por = t_sup_por_pd + t_sup_pd, setup time from POR33 to STROBE.
 * @{
 */
#define UNVM_T_PR_TIME4__T_SUP_POR__SHIFT                                    16
#define UNVM_T_PR_TIME4__T_SUP_POR__WIDTH                                     6
#define UNVM_T_PR_TIME4__T_SUP_POR__MASK                            0x003f0000U
#define UNVM_T_PR_TIME4__T_SUP_POR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define UNVM_T_PR_TIME4__T_SUP_POR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define UNVM_T_PR_TIME4__T_SUP_POR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define UNVM_T_PR_TIME4__T_SUP_POR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))
#define UNVM_T_PR_TIME4__T_SUP_POR__RESET_VALUE                     0x00000019U
/** @} */
#define UNVM_T_PR_TIME4__TYPE                                          uint32_t
#define UNVM_T_PR_TIME4__READ                                       0x003f003fU
#define UNVM_T_PR_TIME4__WRITE                                      0x003f003fU
#define UNVM_T_PR_TIME4__PRESERVED                                  0x00000000U
#define UNVM_T_PR_TIME4__RESET_VALUE                                0x00190012U

#endif /* __UNVM_T_PR_TIME4_MACRO__ */

/** @} end of t_pr_time4 */

/* macros for BlueprintGlobalNameSpace::UNVM_t_pr_time5 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pr_time5 t_pr_time5
 * @brief PROGRAM mode, default value based on 16MHz system clock definitions.
 * @{
 */
#ifndef __UNVM_T_PR_TIME5_MACRO__
#define __UNVM_T_PR_TIME5_MACRO__

/* macros for field t_pi */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pi_field t_pi_field
 * @brief macros for field t_pi
 * @details want >= 1000ns, STROBE pulse interval.
 * @{
 */
#define UNVM_T_PR_TIME5__T_PI__SHIFT                                          0
#define UNVM_T_PR_TIME5__T_PI__WIDTH                                          6
#define UNVM_T_PR_TIME5__T_PI__MASK                                 0x0000003fU
#define UNVM_T_PR_TIME5__T_PI__READ(src)        ((uint32_t)(src) & 0x0000003fU)
#define UNVM_T_PR_TIME5__T_PI__WRITE(src)       ((uint32_t)(src) & 0x0000003fU)
#define UNVM_T_PR_TIME5__T_PI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define UNVM_T_PR_TIME5__T_PI__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define UNVM_T_PR_TIME5__T_PI__RESET_VALUE                          0x00000010U
/** @} */

/* macros for field t_pp */
/**
 * @defgroup at_apb_umc_nvm_regs_core_t_pp_field t_pp_field
 * @brief macros for field t_pp
 * @details want > 3000ns and < 5000ns, typical 4000ns, STROBE pulse width.
 * @{
 */
#define UNVM_T_PR_TIME5__T_PP__SHIFT                                         16
#define UNVM_T_PR_TIME5__T_PP__WIDTH                                          8
#define UNVM_T_PR_TIME5__T_PP__MASK                                 0x00ff0000U
#define UNVM_T_PR_TIME5__T_PP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define UNVM_T_PR_TIME5__T_PP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define UNVM_T_PR_TIME5__T_PP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define UNVM_T_PR_TIME5__T_PP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define UNVM_T_PR_TIME5__T_PP__RESET_VALUE                          0x00000040U
/** @} */
#define UNVM_T_PR_TIME5__TYPE                                          uint32_t
#define UNVM_T_PR_TIME5__READ                                       0x00ff003fU
#define UNVM_T_PR_TIME5__WRITE                                      0x00ff003fU
#define UNVM_T_PR_TIME5__PRESERVED                                  0x00000000U
#define UNVM_T_PR_TIME5__RESET_VALUE                                0x00400010U

#endif /* __UNVM_T_PR_TIME5_MACRO__ */

/** @} end of t_pr_time5 */

/* macros for BlueprintGlobalNameSpace::UNVM_interrupt_status */
/**
 * @defgroup at_apb_umc_nvm_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __UNVM_INTERRUPT_STATUS_MACRO__
#define __UNVM_INTERRUPT_STATUS_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details saw a rising edge on read or program done; independent of mask
 * @{
 */
#define UNVM_INTERRUPT_STATUS__INTRPT0__SHIFT                                 0
#define UNVM_INTERRUPT_STATUS__INTRPT0__WIDTH                                 1
#define UNVM_INTERRUPT_STATUS__INTRPT0__MASK                        0x00000001U
#define UNVM_INTERRUPT_STATUS__INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define UNVM_INTERRUPT_STATUS__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define UNVM_INTERRUPT_STATUS__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define UNVM_INTERRUPT_STATUS__INTRPT0__RESET_VALUE                 0x00000000U
/** @} */
#define UNVM_INTERRUPT_STATUS__TYPE                                    uint32_t
#define UNVM_INTERRUPT_STATUS__READ                                 0x00000001U
#define UNVM_INTERRUPT_STATUS__PRESERVED                            0x00000000U
#define UNVM_INTERRUPT_STATUS__RESET_VALUE                          0x00000000U

#endif /* __UNVM_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::UNVM_interrupt_mask */
/**
 * @defgroup at_apb_umc_nvm_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __UNVM_INTERRUPT_MASK_MACRO__
#define __UNVM_INTERRUPT_MASK_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details 1=allow intrpt0 to be OR'ed into core interrupt
 * @{
 */
#define UNVM_INTERRUPT_MASK__INTRPT0__SHIFT                                   0
#define UNVM_INTERRUPT_MASK__INTRPT0__WIDTH                                   1
#define UNVM_INTERRUPT_MASK__INTRPT0__MASK                          0x00000001U
#define UNVM_INTERRUPT_MASK__INTRPT0__READ(src) ((uint32_t)(src) & 0x00000001U)
#define UNVM_INTERRUPT_MASK__INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define UNVM_INTERRUPT_MASK__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define UNVM_INTERRUPT_MASK__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define UNVM_INTERRUPT_MASK__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define UNVM_INTERRUPT_MASK__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define UNVM_INTERRUPT_MASK__INTRPT0__RESET_VALUE                   0x00000000U
/** @} */
#define UNVM_INTERRUPT_MASK__TYPE                                      uint32_t
#define UNVM_INTERRUPT_MASK__READ                                   0x00000001U
#define UNVM_INTERRUPT_MASK__WRITE                                  0x00000001U
#define UNVM_INTERRUPT_MASK__PRESERVED                              0x00000000U
#define UNVM_INTERRUPT_MASK__RESET_VALUE                            0x00000000U

#endif /* __UNVM_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::UNVM_interrupt_set */
/**
 * @defgroup at_apb_umc_nvm_regs_core_interrupt_set interrupt_set
 * @brief Contains register fields associated with interrupt_set. definitions.
 * @{
 */
#ifndef __UNVM_INTERRUPT_SET_MACRO__
#define __UNVM_INTERRUPT_SET_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details (__SELF_CLEARING__)
 * @{
 */
#define UNVM_INTERRUPT_SET__INTRPT0__SHIFT                                    0
#define UNVM_INTERRUPT_SET__INTRPT0__WIDTH                                    1
#define UNVM_INTERRUPT_SET__INTRPT0__MASK                           0x00000001U
#define UNVM_INTERRUPT_SET__INTRPT0__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define UNVM_INTERRUPT_SET__INTRPT0__WRITE(src) ((uint32_t)(src) & 0x00000001U)
#define UNVM_INTERRUPT_SET__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define UNVM_INTERRUPT_SET__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define UNVM_INTERRUPT_SET__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define UNVM_INTERRUPT_SET__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define UNVM_INTERRUPT_SET__INTRPT0__RESET_VALUE                    0x00000000U
/** @} */
#define UNVM_INTERRUPT_SET__TYPE                                       uint32_t
#define UNVM_INTERRUPT_SET__READ                                    0x00000001U
#define UNVM_INTERRUPT_SET__WRITE                                   0x00000001U
#define UNVM_INTERRUPT_SET__PRESERVED                               0x00000000U
#define UNVM_INTERRUPT_SET__RESET_VALUE                             0x00000000U

#endif /* __UNVM_INTERRUPT_SET_MACRO__ */

/** @} end of interrupt_set */

/* macros for BlueprintGlobalNameSpace::UNVM_interrupt_reset */
/**
 * @defgroup at_apb_umc_nvm_regs_core_interrupt_reset interrupt_reset
 * @brief Contains register fields associated with interrupt_reset. definitions.
 * @{
 */
#ifndef __UNVM_INTERRUPT_RESET_MACRO__
#define __UNVM_INTERRUPT_RESET_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_umc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details (__SELF_CLEARING__)
 * @{
 */
#define UNVM_INTERRUPT_RESET__INTRPT0__SHIFT                                  0
#define UNVM_INTERRUPT_RESET__INTRPT0__WIDTH                                  1
#define UNVM_INTERRUPT_RESET__INTRPT0__MASK                         0x00000001U
#define UNVM_INTERRUPT_RESET__INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define UNVM_INTERRUPT_RESET__INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define UNVM_INTERRUPT_RESET__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define UNVM_INTERRUPT_RESET__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define UNVM_INTERRUPT_RESET__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define UNVM_INTERRUPT_RESET__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define UNVM_INTERRUPT_RESET__INTRPT0__RESET_VALUE                  0x00000000U
/** @} */
#define UNVM_INTERRUPT_RESET__TYPE                                     uint32_t
#define UNVM_INTERRUPT_RESET__READ                                  0x00000001U
#define UNVM_INTERRUPT_RESET__WRITE                                 0x00000001U
#define UNVM_INTERRUPT_RESET__PRESERVED                             0x00000000U
#define UNVM_INTERRUPT_RESET__RESET_VALUE                           0x00000000U

#endif /* __UNVM_INTERRUPT_RESET_MACRO__ */

/** @} end of interrupt_reset */

/* macros for BlueprintGlobalNameSpace::UNVM_core_id */
/**
 * @defgroup at_apb_umc_nvm_regs_core_core_id core_id
 * @brief CORE ID definitions.
 * @{
 */
#ifndef __UNVM_CORE_ID_MACRO__
#define __UNVM_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_umc_nvm_regs_core_id_field id_field
 * @brief macros for field id
 * @details NVM in ASCII
 * @{
 */
#define UNVM_CORE_ID__ID__SHIFT                                               0
#define UNVM_CORE_ID__ID__WIDTH                                              32
#define UNVM_CORE_ID__ID__MASK                                      0xffffffffU
#define UNVM_CORE_ID__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define UNVM_CORE_ID__ID__RESET_VALUE                               0x554e564dU
/** @} */
#define UNVM_CORE_ID__TYPE                                             uint32_t
#define UNVM_CORE_ID__READ                                          0xffffffffU
#define UNVM_CORE_ID__PRESERVED                                     0x00000000U
#define UNVM_CORE_ID__RESET_VALUE                                   0x554e564dU

#endif /* __UNVM_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::UNVM_rev_hash */
/**
 * @defgroup at_apb_umc_nvm_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __UNVM_REV_HASH_MACRO__
#define __UNVM_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_umc_nvm_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define UNVM_REV_HASH__ID__SHIFT                                              0
#define UNVM_REV_HASH__ID__WIDTH                                             32
#define UNVM_REV_HASH__ID__MASK                                     0xffffffffU
#define UNVM_REV_HASH__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define UNVM_REV_HASH__ID__RESET_VALUE                              0x5879dcceU
/** @} */
#define UNVM_REV_HASH__TYPE                                            uint32_t
#define UNVM_REV_HASH__READ                                         0xffffffffU
#define UNVM_REV_HASH__PRESERVED                                    0x00000000U
#define UNVM_REV_HASH__RESET_VALUE                                  0x5879dcceU

#endif /* __UNVM_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::UNVM_rev_key */
/**
 * @defgroup at_apb_umc_nvm_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __UNVM_REV_KEY_MACRO__
#define __UNVM_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_umc_nvm_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define UNVM_REV_KEY__ID__SHIFT                                               0
#define UNVM_REV_KEY__ID__WIDTH                                              32
#define UNVM_REV_KEY__ID__MASK                                      0xffffffffU
#define UNVM_REV_KEY__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define UNVM_REV_KEY__ID__RESET_VALUE                               0x52455620U
/** @} */
#define UNVM_REV_KEY__TYPE                                             uint32_t
#define UNVM_REV_KEY__READ                                          0xffffffffU
#define UNVM_REV_KEY__PRESERVED                                     0x00000000U
#define UNVM_REV_KEY__RESET_VALUE                                   0x52455620U

#endif /* __UNVM_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_UMC_NVM_REGS_CORE */
#endif /* __REG_AT_APB_UMC_NVM_REGS_CORE_H__ */
