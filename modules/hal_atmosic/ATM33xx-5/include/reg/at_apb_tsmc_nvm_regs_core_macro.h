/*                                                                           */
/* File:       at_apb_tsmc_nvm_regs_core_macro.h                             */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_tsmc_nvm_regs_core.rdl      */
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


#ifndef __REG_AT_APB_TSMC_NVM_REGS_CORE_H__
#define __REG_AT_APB_TSMC_NVM_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_TSMC_NVM_REGS_CORE at_apb_tsmc_nvm_regs_core
 * @ingroup AT_REG
 * @brief at_apb_tsmc_nvm_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::NVM_opmode */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_opmode opmode
 * @brief Contains register fields associated with opmode. definitions.
 * @{
 */
#ifndef __NVM_OPMODE_MACRO__
#define __NVM_OPMODE_MACRO__

/* macros for field read */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_read_field read_field
 * @brief macros for field read
 * @details read opcode
 * @{
 */
#define NVM_OPMODE__READ__SHIFT                                               0
#define NVM_OPMODE__READ__WIDTH                                               1
#define NVM_OPMODE__READ__MASK                                      0x00000001U
#define NVM_OPMODE__READ__READ(src)             ((uint32_t)(src) & 0x00000001U)
#define NVM_OPMODE__READ__WRITE(src)            ((uint32_t)(src) & 0x00000001U)
#define NVM_OPMODE__READ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define NVM_OPMODE__READ__VERIFY(src)     (!(((uint32_t)(src) & ~0x00000001U)))
#define NVM_OPMODE__READ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define NVM_OPMODE__READ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define NVM_OPMODE__READ__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field program */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_program_field program_field
 * @brief macros for field program
 * @details program opcode
 * @{
 */
#define NVM_OPMODE__PROGRAM__SHIFT                                            1
#define NVM_OPMODE__PROGRAM__WIDTH                                            1
#define NVM_OPMODE__PROGRAM__MASK                                   0x00000002U
#define NVM_OPMODE__PROGRAM__READ(src)   (((uint32_t)(src) & 0x00000002U) >> 1)
#define NVM_OPMODE__PROGRAM__WRITE(src)  (((uint32_t)(src) << 1) & 0x00000002U)
#define NVM_OPMODE__PROGRAM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define NVM_OPMODE__PROGRAM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define NVM_OPMODE__PROGRAM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define NVM_OPMODE__PROGRAM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define NVM_OPMODE__PROGRAM__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_go_field go_field
 * @brief macros for field go
 * @details opcode start when rising edge on 'go' is detected.
 * @{
 */
#define NVM_OPMODE__GO__SHIFT                                                31
#define NVM_OPMODE__GO__WIDTH                                                 1
#define NVM_OPMODE__GO__MASK                                        0x80000000U
#define NVM_OPMODE__GO__READ(src)       (((uint32_t)(src) & 0x80000000U) >> 31)
#define NVM_OPMODE__GO__WRITE(src)      (((uint32_t)(src) << 31) & 0x80000000U)
#define NVM_OPMODE__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define NVM_OPMODE__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define NVM_OPMODE__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define NVM_OPMODE__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define NVM_OPMODE__GO__RESET_VALUE                                 0x00000000U
/** @} */
#define NVM_OPMODE__TYPE                                               uint32_t
#define NVM_OPMODE__READ                                            0x80000003U
#define NVM_OPMODE__WRITE                                           0x80000003U
#define NVM_OPMODE__PRESERVED                                       0x00000000U
#define NVM_OPMODE__RESET_VALUE                                     0x00000000U

#endif /* __NVM_OPMODE_MACRO__ */

/** @} end of opmode */

/* macros for BlueprintGlobalNameSpace::NVM_ctrl */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_ctrl ctrl
 * @brief Contains register fields associated with ctrl. definitions.
 * @{
 */
#ifndef __NVM_CTRL_MACRO__
#define __NVM_CTRL_MACRO__

/* macros for field ser_dout_en */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_ser_dout_en_field ser_dout_en_field
 * @brief macros for field ser_dout_en
 * @details enable serial data out and allow soft repair during read
 * @{
 */
#define NVM_CTRL__SER_DOUT_EN__SHIFT                                          0
#define NVM_CTRL__SER_DOUT_EN__WIDTH                                          1
#define NVM_CTRL__SER_DOUT_EN__MASK                                 0x00000001U
#define NVM_CTRL__SER_DOUT_EN__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define NVM_CTRL__SER_DOUT_EN__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define NVM_CTRL__SER_DOUT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define NVM_CTRL__SER_DOUT_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define NVM_CTRL__SER_DOUT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define NVM_CTRL__SER_DOUT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define NVM_CTRL__SER_DOUT_EN__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field burst_mode */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_burst_mode_field burst_mode_field
 * @brief macros for field burst_mode
 * @details burst or single bit programming  1 = serial burst program bits starting at bit 0 up to specified bit number in num_pgm_bit register using specified input data from data0/data1 registers  0 = single program bit specified in num_pgm_bit register programming sets efuse bit to 1
 * @{
 */
#define NVM_CTRL__BURST_MODE__SHIFT                                           1
#define NVM_CTRL__BURST_MODE__WIDTH                                           1
#define NVM_CTRL__BURST_MODE__MASK                                  0x00000002U
#define NVM_CTRL__BURST_MODE__READ(src)  (((uint32_t)(src) & 0x00000002U) >> 1)
#define NVM_CTRL__BURST_MODE__WRITE(src) (((uint32_t)(src) << 1) & 0x00000002U)
#define NVM_CTRL__BURST_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define NVM_CTRL__BURST_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define NVM_CTRL__BURST_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define NVM_CTRL__BURST_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define NVM_CTRL__BURST_MODE__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field num_pgm_bit */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_num_pgm_bit_field num_pgm_bit_field
 * @brief macros for field num_pgm_bit
 * @details In single mode, specifies bit location to program; actual bit location is (programmed number - 1)  ex. to program bit 0; num_pgm_bit=1, to program bit 63; num_pgm_bit=64  In burst mode, program bits location from 0 up to (programmed number - 1).
 * @{
 */
#define NVM_CTRL__NUM_PGM_BIT__SHIFT                                          2
#define NVM_CTRL__NUM_PGM_BIT__WIDTH                                          7
#define NVM_CTRL__NUM_PGM_BIT__MASK                                 0x000001fcU
#define NVM_CTRL__NUM_PGM_BIT__READ(src) (((uint32_t)(src) & 0x000001fcU) >> 2)
#define NVM_CTRL__NUM_PGM_BIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x000001fcU)
#define NVM_CTRL__NUM_PGM_BIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001fcU) | (((uint32_t)(src) <<\
                    2) & 0x000001fcU)
#define NVM_CTRL__NUM_PGM_BIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x000001fcU)))
#define NVM_CTRL__NUM_PGM_BIT__RESET_VALUE                          0x00000040U
/** @} */
#define NVM_CTRL__TYPE                                                 uint32_t
#define NVM_CTRL__READ                                              0x000001ffU
#define NVM_CTRL__WRITE                                             0x000001ffU
#define NVM_CTRL__PRESERVED                                         0x00000000U
#define NVM_CTRL__RESET_VALUE                                       0x00000100U

#endif /* __NVM_CTRL_MACRO__ */

/** @} end of ctrl */

/* macros for BlueprintGlobalNameSpace::NVM_data0 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_data0 data0
 * @brief Contains register fields associated with data0. definitions.
 * @{
 */
#ifndef __NVM_DATA0_MACRO__
#define __NVM_DATA0_MACRO__

/* macros for field data0 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_data0_field data0_field
 * @brief macros for field data0
 * @details otp data word-0,  can be used for program or read data based on target operation
 * @{
 */
#define NVM_DATA0__DATA0__SHIFT                                               0
#define NVM_DATA0__DATA0__WIDTH                                              32
#define NVM_DATA0__DATA0__MASK                                      0xffffffffU
#define NVM_DATA0__DATA0__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define NVM_DATA0__DATA0__WRITE(src)            ((uint32_t)(src) & 0xffffffffU)
#define NVM_DATA0__DATA0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define NVM_DATA0__DATA0__VERIFY(src)     (!(((uint32_t)(src) & ~0xffffffffU)))
#define NVM_DATA0__DATA0__RESET_VALUE                               0x00000000U
/** @} */
#define NVM_DATA0__TYPE                                                uint32_t
#define NVM_DATA0__READ                                             0xffffffffU
#define NVM_DATA0__WRITE                                            0xffffffffU
#define NVM_DATA0__PRESERVED                                        0x00000000U
#define NVM_DATA0__RESET_VALUE                                      0x00000000U

#endif /* __NVM_DATA0_MACRO__ */

/** @} end of data0 */

/* macros for BlueprintGlobalNameSpace::NVM_data1 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_data1 data1
 * @brief Contains register fields associated with data1. definitions.
 * @{
 */
#ifndef __NVM_DATA1_MACRO__
#define __NVM_DATA1_MACRO__

/* macros for field data1 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_data1_field data1_field
 * @brief macros for field data1
 * @details otp data word-1,  can be used for program or read data based on target operation
 * @{
 */
#define NVM_DATA1__DATA1__SHIFT                                               0
#define NVM_DATA1__DATA1__WIDTH                                              32
#define NVM_DATA1__DATA1__MASK                                      0xffffffffU
#define NVM_DATA1__DATA1__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define NVM_DATA1__DATA1__WRITE(src)            ((uint32_t)(src) & 0xffffffffU)
#define NVM_DATA1__DATA1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define NVM_DATA1__DATA1__VERIFY(src)     (!(((uint32_t)(src) & ~0xffffffffU)))
#define NVM_DATA1__DATA1__RESET_VALUE                               0x00000000U
/** @} */
#define NVM_DATA1__TYPE                                                uint32_t
#define NVM_DATA1__READ                                             0xffffffffU
#define NVM_DATA1__WRITE                                            0xffffffffU
#define NVM_DATA1__PRESERVED                                        0x00000000U
#define NVM_DATA1__RESET_VALUE                                      0x00000000U

#endif /* __NVM_DATA1_MACRO__ */

/** @} end of data1 */

/* macros for BlueprintGlobalNameSpace::NVM_status */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_status status
 * @brief Contains register fields associated with status. definitions.
 * @{
 */
#ifndef __NVM_STATUS_MACRO__
#define __NVM_STATUS_MACRO__

/* macros for field read_done */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_read_done_field read_done_field
 * @brief macros for field read_done
 * @details read done
 * @{
 */
#define NVM_STATUS__READ_DONE__SHIFT                                          0
#define NVM_STATUS__READ_DONE__WIDTH                                          1
#define NVM_STATUS__READ_DONE__MASK                                 0x00000001U
#define NVM_STATUS__READ_DONE__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define NVM_STATUS__READ_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define NVM_STATUS__READ_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define NVM_STATUS__READ_DONE__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field program_done */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_program_done_field program_done_field
 * @brief macros for field program_done
 * @details programming done
 * @{
 */
#define NVM_STATUS__PROGRAM_DONE__SHIFT                                       1
#define NVM_STATUS__PROGRAM_DONE__WIDTH                                       1
#define NVM_STATUS__PROGRAM_DONE__MASK                              0x00000002U
#define NVM_STATUS__PROGRAM_DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define NVM_STATUS__PROGRAM_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define NVM_STATUS__PROGRAM_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define NVM_STATUS__PROGRAM_DONE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field running */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_running_field running_field
 * @brief macros for field running
 * @details read or program running
 * @{
 */
#define NVM_STATUS__RUNNING__SHIFT                                           31
#define NVM_STATUS__RUNNING__WIDTH                                            1
#define NVM_STATUS__RUNNING__MASK                                   0x80000000U
#define NVM_STATUS__RUNNING__READ(src)  (((uint32_t)(src) & 0x80000000U) >> 31)
#define NVM_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define NVM_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define NVM_STATUS__RUNNING__RESET_VALUE                            0x00000000U
/** @} */
#define NVM_STATUS__TYPE                                               uint32_t
#define NVM_STATUS__READ                                            0x80000003U
#define NVM_STATUS__PRESERVED                                       0x00000000U
#define NVM_STATUS__RESET_VALUE                                     0x00000000U

#endif /* __NVM_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::NVM_t_sp_vq */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_sp_vq t_sp_vq
 * @brief VDDQ to CSB setup time into program mode definitions.
 * @{
 */
#ifndef __NVM_T_SP_VQ_MACRO__
#define __NVM_T_SP_VQ_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 10 nsec;  each lsb accounts for 16usec, max when all bits programmed is around 500usec  default 16usec based on 16MHz system clock
 * @{
 */
#define NVM_T_SP_VQ__CYCLES__SHIFT                                            0
#define NVM_T_SP_VQ__CYCLES__WIDTH                                            5
#define NVM_T_SP_VQ__CYCLES__MASK                                   0x0000001fU
#define NVM_T_SP_VQ__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SP_VQ__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SP_VQ__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_SP_VQ__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_SP_VQ__CYCLES__RESET_VALUE                            0x00000001U
/** @} */
#define NVM_T_SP_VQ__TYPE                                              uint32_t
#define NVM_T_SP_VQ__READ                                           0x0000001fU
#define NVM_T_SP_VQ__WRITE                                          0x0000001fU
#define NVM_T_SP_VQ__PRESERVED                                      0x00000000U
#define NVM_T_SP_VQ__RESET_VALUE                                    0x00000001U

#endif /* __NVM_T_SP_VQ_MACRO__ */

/** @} end of t_sp_vq */

/* macros for BlueprintGlobalNameSpace::NVM_t_hp_vq */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_hp_vq t_hp_vq
 * @brief VDDQ to CSB hold time out of program mode definitions.
 * @{
 */
#ifndef __NVM_T_HP_VQ_MACRO__
#define __NVM_T_HP_VQ_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 10 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_HP_VQ__CYCLES__SHIFT                                            0
#define NVM_T_HP_VQ__CYCLES__WIDTH                                            5
#define NVM_T_HP_VQ__CYCLES__MASK                                   0x0000001fU
#define NVM_T_HP_VQ__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_HP_VQ__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_HP_VQ__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_HP_VQ__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_HP_VQ__CYCLES__RESET_VALUE                            0x00000000U
/** @} */
#define NVM_T_HP_VQ__TYPE                                              uint32_t
#define NVM_T_HP_VQ__READ                                           0x0000001fU
#define NVM_T_HP_VQ__WRITE                                          0x0000001fU
#define NVM_T_HP_VQ__PRESERVED                                      0x00000000U
#define NVM_T_HP_VQ__RESET_VALUE                                    0x00000000U

#endif /* __NVM_T_HP_VQ_MACRO__ */

/** @} end of t_hp_vq */

/* macros for BlueprintGlobalNameSpace::NVM_t_sp_pg */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_sp_pg t_sp_pg
 * @brief PGM to CSB setup time into program mode definitions.
 * @{
 */
#ifndef __NVM_T_SP_PG_MACRO__
#define __NVM_T_SP_PG_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 5 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_SP_PG__CYCLES__SHIFT                                            0
#define NVM_T_SP_PG__CYCLES__WIDTH                                            5
#define NVM_T_SP_PG__CYCLES__MASK                                   0x0000001fU
#define NVM_T_SP_PG__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SP_PG__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SP_PG__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_SP_PG__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_SP_PG__CYCLES__RESET_VALUE                            0x00000000U
/** @} */
#define NVM_T_SP_PG__TYPE                                              uint32_t
#define NVM_T_SP_PG__READ                                           0x0000001fU
#define NVM_T_SP_PG__WRITE                                          0x0000001fU
#define NVM_T_SP_PG__PRESERVED                                      0x00000000U
#define NVM_T_SP_PG__RESET_VALUE                                    0x00000000U

#endif /* __NVM_T_SP_PG_MACRO__ */

/** @} end of t_sp_pg */

/* macros for BlueprintGlobalNameSpace::NVM_t_hp_pg */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_hp_pg t_hp_pg
 * @brief PGM to CSB hold time into program mode definitions.
 * @{
 */
#ifndef __NVM_T_HP_PG_MACRO__
#define __NVM_T_HP_PG_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 5 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_HP_PG__CYCLES__SHIFT                                            0
#define NVM_T_HP_PG__CYCLES__WIDTH                                            5
#define NVM_T_HP_PG__CYCLES__MASK                                   0x0000001fU
#define NVM_T_HP_PG__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_HP_PG__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_HP_PG__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_HP_PG__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_HP_PG__CYCLES__RESET_VALUE                            0x00000000U
/** @} */
#define NVM_T_HP_PG__TYPE                                              uint32_t
#define NVM_T_HP_PG__READ                                           0x0000001fU
#define NVM_T_HP_PG__WRITE                                          0x0000001fU
#define NVM_T_HP_PG__PRESERVED                                      0x00000000U
#define NVM_T_HP_PG__RESET_VALUE                                    0x00000000U

#endif /* __NVM_T_HP_PG_MACRO__ */

/** @} end of t_hp_pg */

/* macros for BlueprintGlobalNameSpace::NVM_t_hp_ck */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_hp_ck t_hp_ck
 * @brief SCLK to CSB hold time into program mode definitions.
 * @{
 */
#ifndef __NVM_T_HP_CK_MACRO__
#define __NVM_T_HP_CK_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 31 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_HP_CK__CYCLES__SHIFT                                            0
#define NVM_T_HP_CK__CYCLES__WIDTH                                            5
#define NVM_T_HP_CK__CYCLES__MASK                                   0x0000001fU
#define NVM_T_HP_CK__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_HP_CK__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_HP_CK__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_HP_CK__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_HP_CK__CYCLES__RESET_VALUE                            0x00000001U
/** @} */
#define NVM_T_HP_CK__TYPE                                              uint32_t
#define NVM_T_HP_CK__READ                                           0x0000001fU
#define NVM_T_HP_CK__WRITE                                          0x0000001fU
#define NVM_T_HP_CK__PRESERVED                                      0x00000000U
#define NVM_T_HP_CK__RESET_VALUE                                    0x00000001U

#endif /* __NVM_T_HP_CK_MACRO__ */

/** @} end of t_hp_ck */

/* macros for BlueprintGlobalNameSpace::NVM_t_s_pgm */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_s_pgm t_s_pgm
 * @brief PGM to SCLK setup time to program bits definitions.
 * @{
 */
#ifndef __NVM_T_S_PGM_MACRO__
#define __NVM_T_S_PGM_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 8 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_S_PGM__CYCLES__SHIFT                                            0
#define NVM_T_S_PGM__CYCLES__WIDTH                                            6
#define NVM_T_S_PGM__CYCLES__MASK                                   0x0000003fU
#define NVM_T_S_PGM__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000003fU)
#define NVM_T_S_PGM__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000003fU)
#define NVM_T_S_PGM__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define NVM_T_S_PGM__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000003fU)))
#define NVM_T_S_PGM__CYCLES__RESET_VALUE                            0x00000000U
/** @} */
#define NVM_T_S_PGM__TYPE                                              uint32_t
#define NVM_T_S_PGM__READ                                           0x0000003fU
#define NVM_T_S_PGM__WRITE                                          0x0000003fU
#define NVM_T_S_PGM__PRESERVED                                      0x00000000U
#define NVM_T_S_PGM__RESET_VALUE                                    0x00000000U

#endif /* __NVM_T_S_PGM_MACRO__ */

/** @} end of t_s_pgm */

/* macros for BlueprintGlobalNameSpace::NVM_t_h_pgm */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_h_pgm t_h_pgm
 * @brief PGM to SCLK hold time to program bits definitions.
 * @{
 */
#ifndef __NVM_T_H_PGM_MACRO__
#define __NVM_T_H_PGM_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 8 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_H_PGM__CYCLES__SHIFT                                            0
#define NVM_T_H_PGM__CYCLES__WIDTH                                            6
#define NVM_T_H_PGM__CYCLES__MASK                                   0x0000003fU
#define NVM_T_H_PGM__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000003fU)
#define NVM_T_H_PGM__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000003fU)
#define NVM_T_H_PGM__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define NVM_T_H_PGM__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000003fU)))
#define NVM_T_H_PGM__CYCLES__RESET_VALUE                            0x00000000U
/** @} */
#define NVM_T_H_PGM__TYPE                                              uint32_t
#define NVM_T_H_PGM__READ                                           0x0000003fU
#define NVM_T_H_PGM__WRITE                                          0x0000003fU
#define NVM_T_H_PGM__PRESERVED                                      0x00000000U
#define NVM_T_H_PGM__RESET_VALUE                                    0x00000000U

#endif /* __NVM_T_H_PGM_MACRO__ */

/** @} end of t_h_pgm */

/* macros for BlueprintGlobalNameSpace::NVM_t_ckhp */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_ckhp t_ckhp
 * @brief SCLK high period for program definitions.
 * @{
 */
#ifndef __NVM_T_CKHP_MACRO__
#define __NVM_T_CKHP_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 9 usec and <= 11 usec; default for 10 usec  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_CKHP__CYCLES__SHIFT                                             0
#define NVM_T_CKHP__CYCLES__WIDTH                                            11
#define NVM_T_CKHP__CYCLES__MASK                                    0x000007ffU
#define NVM_T_CKHP__CYCLES__READ(src)           ((uint32_t)(src) & 0x000007ffU)
#define NVM_T_CKHP__CYCLES__WRITE(src)          ((uint32_t)(src) & 0x000007ffU)
#define NVM_T_CKHP__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define NVM_T_CKHP__CYCLES__VERIFY(src)   (!(((uint32_t)(src) & ~0x000007ffU)))
#define NVM_T_CKHP__CYCLES__RESET_VALUE                             0x000000a0U
/** @} */
#define NVM_T_CKHP__TYPE                                               uint32_t
#define NVM_T_CKHP__READ                                            0x000007ffU
#define NVM_T_CKHP__WRITE                                           0x000007ffU
#define NVM_T_CKHP__PRESERVED                                       0x00000000U
#define NVM_T_CKHP__RESET_VALUE                                     0x000000a0U

#endif /* __NVM_T_CKHP_MACRO__ */

/** @} end of t_ckhp */

/* macros for BlueprintGlobalNameSpace::NVM_t_cklp */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_cklp t_cklp
 * @brief SCLK low period for program definitions.
 * @{
 */
#ifndef __NVM_T_CKLP_MACRO__
#define __NVM_T_CKLP_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 10 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_CKLP__CYCLES__SHIFT                                             0
#define NVM_T_CKLP__CYCLES__WIDTH                                             5
#define NVM_T_CKLP__CYCLES__MASK                                    0x0000001fU
#define NVM_T_CKLP__CYCLES__READ(src)           ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_CKLP__CYCLES__WRITE(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_CKLP__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_CKLP__CYCLES__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_CKLP__CYCLES__RESET_VALUE                             0x00000000U
/** @} */
#define NVM_T_CKLP__TYPE                                               uint32_t
#define NVM_T_CKLP__READ                                            0x0000001fU
#define NVM_T_CKLP__WRITE                                           0x0000001fU
#define NVM_T_CKLP__PRESERVED                                       0x00000000U
#define NVM_T_CKLP__RESET_VALUE                                     0x00000000U

#endif /* __NVM_T_CKLP_MACRO__ */

/** @} end of t_cklp */

/* macros for BlueprintGlobalNameSpace::NVM_t_sps_ck */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_sps_ck t_sps_ck
 * @brief CSB to SCLK hold time out of program mode definitions.
 * @{
 */
#ifndef __NVM_T_SPS_CK_MACRO__
#define __NVM_T_SPS_CK_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 31 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_SPS_CK__CYCLES__SHIFT                                           0
#define NVM_T_SPS_CK__CYCLES__WIDTH                                           5
#define NVM_T_SPS_CK__CYCLES__MASK                                  0x0000001fU
#define NVM_T_SPS_CK__CYCLES__READ(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SPS_CK__CYCLES__WRITE(src)        ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SPS_CK__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_SPS_CK__CYCLES__VERIFY(src) (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_SPS_CK__CYCLES__RESET_VALUE                           0x00000001U
/** @} */
#define NVM_T_SPS_CK__TYPE                                             uint32_t
#define NVM_T_SPS_CK__READ                                          0x0000001fU
#define NVM_T_SPS_CK__WRITE                                         0x0000001fU
#define NVM_T_SPS_CK__PRESERVED                                     0x00000000U
#define NVM_T_SPS_CK__RESET_VALUE                                   0x00000001U

#endif /* __NVM_T_SPS_CK_MACRO__ */

/** @} end of t_sps_ck */

/* macros for BlueprintGlobalNameSpace::NVM_t_sr_ck */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_sr_ck t_sr_ck
 * @brief SCLK to CSB setup time into read mode definitions.
 * @{
 */
#ifndef __NVM_T_SR_CK_MACRO__
#define __NVM_T_SR_CK_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 6 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_SR_CK__CYCLES__SHIFT                                            0
#define NVM_T_SR_CK__CYCLES__WIDTH                                            5
#define NVM_T_SR_CK__CYCLES__MASK                                   0x0000001fU
#define NVM_T_SR_CK__CYCLES__READ(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SR_CK__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SR_CK__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_SR_CK__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_SR_CK__CYCLES__RESET_VALUE                            0x00000000U
/** @} */
#define NVM_T_SR_CK__TYPE                                              uint32_t
#define NVM_T_SR_CK__READ                                           0x0000001fU
#define NVM_T_SR_CK__WRITE                                          0x0000001fU
#define NVM_T_SR_CK__PRESERVED                                      0x00000000U
#define NVM_T_SR_CK__RESET_VALUE                                    0x00000000U

#endif /* __NVM_T_SR_CK_MACRO__ */

/** @} end of t_sr_ck */

/* macros for BlueprintGlobalNameSpace::NVM_t_hr_ck */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_hr_ck t_hr_ck
 * @brief SCLK to CSB hold time into read mode definitions.
 * @{
 */
#ifndef __NVM_T_HR_CK_MACRO__
#define __NVM_T_HR_CK_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 940 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_HR_CK__CYCLES__SHIFT                                            0
#define NVM_T_HR_CK__CYCLES__WIDTH                                           10
#define NVM_T_HR_CK__CYCLES__MASK                                   0x000003ffU
#define NVM_T_HR_CK__CYCLES__READ(src)          ((uint32_t)(src) & 0x000003ffU)
#define NVM_T_HR_CK__CYCLES__WRITE(src)         ((uint32_t)(src) & 0x000003ffU)
#define NVM_T_HR_CK__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define NVM_T_HR_CK__CYCLES__VERIFY(src)  (!(((uint32_t)(src) & ~0x000003ffU)))
#define NVM_T_HR_CK__CYCLES__RESET_VALUE                            0x0000000eU
/** @} */
#define NVM_T_HR_CK__TYPE                                              uint32_t
#define NVM_T_HR_CK__READ                                           0x000003ffU
#define NVM_T_HR_CK__WRITE                                          0x000003ffU
#define NVM_T_HR_CK__PRESERVED                                      0x00000000U
#define NVM_T_HR_CK__RESET_VALUE                                    0x0000000eU

#endif /* __NVM_T_HR_CK_MACRO__ */

/** @} end of t_hr_ck */

/* macros for BlueprintGlobalNameSpace::NVM_t_cklr */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_cklr t_cklr
 * @brief SCLK low period for read definitions.
 * @{
 */
#ifndef __NVM_T_CKLR_MACRO__
#define __NVM_T_CKLR_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 10 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_CKLR__CYCLES__SHIFT                                             0
#define NVM_T_CKLR__CYCLES__WIDTH                                             5
#define NVM_T_CKLR__CYCLES__MASK                                    0x0000001fU
#define NVM_T_CKLR__CYCLES__READ(src)           ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_CKLR__CYCLES__WRITE(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_CKLR__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_CKLR__CYCLES__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_CKLR__CYCLES__RESET_VALUE                             0x00000000U
/** @} */
#define NVM_T_CKLR__TYPE                                               uint32_t
#define NVM_T_CKLR__READ                                            0x0000001fU
#define NVM_T_CKLR__WRITE                                           0x0000001fU
#define NVM_T_CKLR__PRESERVED                                       0x00000000U
#define NVM_T_CKLR__RESET_VALUE                                     0x00000000U

#endif /* __NVM_T_CKLR_MACRO__ */

/** @} end of t_cklr */

/* macros for BlueprintGlobalNameSpace::NVM_t_ckhr */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_ckhr t_ckhr
 * @brief SCLK high period for read definitions.
 * @{
 */
#ifndef __NVM_T_CKHR_MACRO__
#define __NVM_T_CKHR_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 10 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_CKHR__CYCLES__SHIFT                                             0
#define NVM_T_CKHR__CYCLES__WIDTH                                             5
#define NVM_T_CKHR__CYCLES__MASK                                    0x0000001fU
#define NVM_T_CKHR__CYCLES__READ(src)           ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_CKHR__CYCLES__WRITE(src)          ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_CKHR__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_CKHR__CYCLES__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_CKHR__CYCLES__RESET_VALUE                             0x00000000U
/** @} */
#define NVM_T_CKHR__TYPE                                               uint32_t
#define NVM_T_CKHR__READ                                            0x0000001fU
#define NVM_T_CKHR__WRITE                                           0x0000001fU
#define NVM_T_CKHR__PRESERVED                                       0x00000000U
#define NVM_T_CKHR__RESET_VALUE                                     0x00000000U

#endif /* __NVM_T_CKHR_MACRO__ */

/** @} end of t_ckhr */

/* macros for BlueprintGlobalNameSpace::NVM_t_srs_ck */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_t_srs_ck t_srs_ck
 * @brief CSB to SCLK hold time out of read mode definitions.
 * @{
 */
#ifndef __NVM_T_SRS_CK_MACRO__
#define __NVM_T_SRS_CK_MACRO__

/* macros for field cycles */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_cycles_field cycles_field
 * @brief macros for field cycles
 * @details want >= 20 nsec;  actual delay is (programmed number + 1), default based on 16MHz system clock
 * @{
 */
#define NVM_T_SRS_CK__CYCLES__SHIFT                                           0
#define NVM_T_SRS_CK__CYCLES__WIDTH                                           5
#define NVM_T_SRS_CK__CYCLES__MASK                                  0x0000001fU
#define NVM_T_SRS_CK__CYCLES__READ(src)         ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SRS_CK__CYCLES__WRITE(src)        ((uint32_t)(src) & 0x0000001fU)
#define NVM_T_SRS_CK__CYCLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define NVM_T_SRS_CK__CYCLES__VERIFY(src) (!(((uint32_t)(src) & ~0x0000001fU)))
#define NVM_T_SRS_CK__CYCLES__RESET_VALUE                           0x00000000U
/** @} */
#define NVM_T_SRS_CK__TYPE                                             uint32_t
#define NVM_T_SRS_CK__READ                                          0x0000001fU
#define NVM_T_SRS_CK__WRITE                                         0x0000001fU
#define NVM_T_SRS_CK__PRESERVED                                     0x00000000U
#define NVM_T_SRS_CK__RESET_VALUE                                   0x00000000U

#endif /* __NVM_T_SRS_CK_MACRO__ */

/** @} end of t_srs_ck */

/* macros for BlueprintGlobalNameSpace::NVM_interrupt_status */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __NVM_INTERRUPT_STATUS_MACRO__
#define __NVM_INTERRUPT_STATUS_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details saw a rising edge on read or program done; independent of mask
 * @{
 */
#define NVM_INTERRUPT_STATUS__INTRPT0__SHIFT                                  0
#define NVM_INTERRUPT_STATUS__INTRPT0__WIDTH                                  1
#define NVM_INTERRUPT_STATUS__INTRPT0__MASK                         0x00000001U
#define NVM_INTERRUPT_STATUS__INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define NVM_INTERRUPT_STATUS__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define NVM_INTERRUPT_STATUS__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define NVM_INTERRUPT_STATUS__INTRPT0__RESET_VALUE                  0x00000000U
/** @} */
#define NVM_INTERRUPT_STATUS__TYPE                                     uint32_t
#define NVM_INTERRUPT_STATUS__READ                                  0x00000001U
#define NVM_INTERRUPT_STATUS__PRESERVED                             0x00000000U
#define NVM_INTERRUPT_STATUS__RESET_VALUE                           0x00000000U

#endif /* __NVM_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::NVM_interrupt_mask */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __NVM_INTERRUPT_MASK_MACRO__
#define __NVM_INTERRUPT_MASK_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details 1=allow intrpt0 to be OR'ed into core interrupt
 * @{
 */
#define NVM_INTERRUPT_MASK__INTRPT0__SHIFT                                    0
#define NVM_INTERRUPT_MASK__INTRPT0__WIDTH                                    1
#define NVM_INTERRUPT_MASK__INTRPT0__MASK                           0x00000001U
#define NVM_INTERRUPT_MASK__INTRPT0__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define NVM_INTERRUPT_MASK__INTRPT0__WRITE(src) ((uint32_t)(src) & 0x00000001U)
#define NVM_INTERRUPT_MASK__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define NVM_INTERRUPT_MASK__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define NVM_INTERRUPT_MASK__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define NVM_INTERRUPT_MASK__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define NVM_INTERRUPT_MASK__INTRPT0__RESET_VALUE                    0x00000000U
/** @} */
#define NVM_INTERRUPT_MASK__TYPE                                       uint32_t
#define NVM_INTERRUPT_MASK__READ                                    0x00000001U
#define NVM_INTERRUPT_MASK__WRITE                                   0x00000001U
#define NVM_INTERRUPT_MASK__PRESERVED                               0x00000000U
#define NVM_INTERRUPT_MASK__RESET_VALUE                             0x00000000U

#endif /* __NVM_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::NVM_interrupt_set */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_interrupt_set interrupt_set
 * @brief not auto cleared definitions.
 * @{
 */
#ifndef __NVM_INTERRUPT_SET_MACRO__
#define __NVM_INTERRUPT_SET_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @{
 */
#define NVM_INTERRUPT_SET__INTRPT0__SHIFT                                     0
#define NVM_INTERRUPT_SET__INTRPT0__WIDTH                                     1
#define NVM_INTERRUPT_SET__INTRPT0__MASK                            0x00000001U
#define NVM_INTERRUPT_SET__INTRPT0__READ(src)   ((uint32_t)(src) & 0x00000001U)
#define NVM_INTERRUPT_SET__INTRPT0__WRITE(src)  ((uint32_t)(src) & 0x00000001U)
#define NVM_INTERRUPT_SET__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define NVM_INTERRUPT_SET__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define NVM_INTERRUPT_SET__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define NVM_INTERRUPT_SET__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define NVM_INTERRUPT_SET__INTRPT0__RESET_VALUE                     0x00000000U
/** @} */
#define NVM_INTERRUPT_SET__TYPE                                        uint32_t
#define NVM_INTERRUPT_SET__READ                                     0x00000001U
#define NVM_INTERRUPT_SET__WRITE                                    0x00000001U
#define NVM_INTERRUPT_SET__PRESERVED                                0x00000000U
#define NVM_INTERRUPT_SET__RESET_VALUE                              0x00000000U

#endif /* __NVM_INTERRUPT_SET_MACRO__ */

/** @} end of interrupt_set */

/* macros for BlueprintGlobalNameSpace::NVM_interrupt_reset */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_interrupt_reset interrupt_reset
 * @brief not auto cleared definitions.
 * @{
 */
#ifndef __NVM_INTERRUPT_RESET_MACRO__
#define __NVM_INTERRUPT_RESET_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @{
 */
#define NVM_INTERRUPT_RESET__INTRPT0__SHIFT                                   0
#define NVM_INTERRUPT_RESET__INTRPT0__WIDTH                                   1
#define NVM_INTERRUPT_RESET__INTRPT0__MASK                          0x00000001U
#define NVM_INTERRUPT_RESET__INTRPT0__READ(src) ((uint32_t)(src) & 0x00000001U)
#define NVM_INTERRUPT_RESET__INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define NVM_INTERRUPT_RESET__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define NVM_INTERRUPT_RESET__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define NVM_INTERRUPT_RESET__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define NVM_INTERRUPT_RESET__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define NVM_INTERRUPT_RESET__INTRPT0__RESET_VALUE                   0x00000000U
/** @} */
#define NVM_INTERRUPT_RESET__TYPE                                      uint32_t
#define NVM_INTERRUPT_RESET__READ                                   0x00000001U
#define NVM_INTERRUPT_RESET__WRITE                                  0x00000001U
#define NVM_INTERRUPT_RESET__PRESERVED                              0x00000000U
#define NVM_INTERRUPT_RESET__RESET_VALUE                            0x00000000U

#endif /* __NVM_INTERRUPT_RESET_MACRO__ */

/** @} end of interrupt_reset */

/* macros for BlueprintGlobalNameSpace::NVM_core_id */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_core_id core_id
 * @brief CORE ID definitions.
 * @{
 */
#ifndef __NVM_CORE_ID_MACRO__
#define __NVM_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_tsmc_nvm_regs_core_id_field id_field
 * @brief macros for field id
 * @details NVM in ASCII
 * @{
 */
#define NVM_CORE_ID__ID__SHIFT                                                0
#define NVM_CORE_ID__ID__WIDTH                                               32
#define NVM_CORE_ID__ID__MASK                                       0xffffffffU
#define NVM_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define NVM_CORE_ID__ID__RESET_VALUE                                0x4e564d20U
/** @} */
#define NVM_CORE_ID__TYPE                                              uint32_t
#define NVM_CORE_ID__READ                                           0xffffffffU
#define NVM_CORE_ID__PRESERVED                                      0x00000000U
#define NVM_CORE_ID__RESET_VALUE                                    0x4e564d20U

#endif /* __NVM_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of AT_APB_TSMC_NVM_REGS_CORE */
#endif /* __REG_AT_APB_TSMC_NVM_REGS_CORE_H__ */
