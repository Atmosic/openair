/*                                                                           */
/* File:       at_apb_swd_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_swd_regs_core.rdl           */
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


#ifndef __REG_AT_APB_SWD_REGS_CORE_H__
#define __REG_AT_APB_SWD_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_SWD_REGS_CORE at_apb_swd_regs_core
 * @ingroup AT_REG
 * @brief at_apb_swd_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::SWD_dap_addr_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_dap_addr_ctrl dap_addr_ctrl
 * @brief Contains register fields associated with dap_addr_ctrl. definitions.
 * @{
 */
#ifndef __SWD_DAP_ADDR_CTRL_MACRO__
#define __SWD_DAP_ADDR_CTRL_MACRO__

/* macros for field dap_addr */
/**
 * @defgroup at_apb_swd_regs_core_dap_addr_field dap_addr_field
 * @brief macros for field dap_addr
 * @{
 */
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__SHIFT                                    0
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__WIDTH                                    2
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__MASK                           0x00000003U
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__READ(src)  ((uint32_t)(src) & 0x00000003U)
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__WRITE(src) ((uint32_t)(src) & 0x00000003U)
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define SWD_DAP_ADDR_CTRL__DAP_ADDR__RESET_VALUE                    0x00000000U
/** @} */
#define SWD_DAP_ADDR_CTRL__TYPE                                        uint32_t
#define SWD_DAP_ADDR_CTRL__READ                                     0x00000003U
#define SWD_DAP_ADDR_CTRL__WRITE                                    0x00000003U
#define SWD_DAP_ADDR_CTRL__PRESERVED                                0x00000000U
#define SWD_DAP_ADDR_CTRL__RESET_VALUE                              0x00000000U

#endif /* __SWD_DAP_ADDR_CTRL_MACRO__ */

/** @} end of dap_addr_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_dap_wdata_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_dap_wdata_ctrl dap_wdata_ctrl
 * @brief Contains register fields associated with dap_wdata_ctrl. definitions.
 * @{
 */
#ifndef __SWD_DAP_WDATA_CTRL_MACRO__
#define __SWD_DAP_WDATA_CTRL_MACRO__

/* macros for field dap_wdata */
/**
 * @defgroup at_apb_swd_regs_core_dap_wdata_field dap_wdata_field
 * @brief macros for field dap_wdata
 * @{
 */
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__SHIFT                                  0
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__WIDTH                                 32
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__MASK                         0xffffffffU
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DAP_WDATA_CTRL__DAP_WDATA__RESET_VALUE                  0x00000000U
/** @} */
#define SWD_DAP_WDATA_CTRL__TYPE                                       uint32_t
#define SWD_DAP_WDATA_CTRL__READ                                    0xffffffffU
#define SWD_DAP_WDATA_CTRL__WRITE                                   0xffffffffU
#define SWD_DAP_WDATA_CTRL__PRESERVED                               0x00000000U
#define SWD_DAP_WDATA_CTRL__RESET_VALUE                             0x00000000U

#endif /* __SWD_DAP_WDATA_CTRL_MACRO__ */

/** @} end of dap_wdata_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_swd_clk_div_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_swd_clk_div_ctrl swd_clk_div_ctrl
 * @brief Contains register fields associated with swd_clk_div_ctrl. definitions.
 * @{
 */
#ifndef __SWD_SWD_CLK_DIV_CTRL_MACRO__
#define __SWD_SWD_CLK_DIV_CTRL_MACRO__

/* macros for field swd_clk_div */
/**
 * @defgroup at_apb_swd_regs_core_swd_clk_div_field swd_clk_div_field
 * @brief macros for field swd_clk_div
 * @details clock divider = 2^(swd_clk_div)
 * @{
 */
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__SHIFT                              0
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__WIDTH                              3
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__MASK                     0x00000007U
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define SWD_SWD_CLK_DIV_CTRL__SWD_CLK_DIV__RESET_VALUE              0x00000003U
/** @} */
#define SWD_SWD_CLK_DIV_CTRL__TYPE                                     uint32_t
#define SWD_SWD_CLK_DIV_CTRL__READ                                  0x00000007U
#define SWD_SWD_CLK_DIV_CTRL__WRITE                                 0x00000007U
#define SWD_SWD_CLK_DIV_CTRL__PRESERVED                             0x00000000U
#define SWD_SWD_CLK_DIV_CTRL__RESET_VALUE                           0x00000003U

#endif /* __SWD_SWD_CLK_DIV_CTRL_MACRO__ */

/** @} end of swd_clk_div_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_pattern_upper_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_pattern_upper_ctrl pattern_upper_ctrl
 * @brief Contains register fields associated with pattern_upper_ctrl. definitions.
 * @{
 */
#ifndef __SWD_PATTERN_UPPER_CTRL_MACRO__
#define __SWD_PATTERN_UPPER_CTRL_MACRO__

/* macros for field pattern */
/**
 * @defgroup at_apb_swd_regs_core_pattern_field pattern_field
 * @brief macros for field pattern
 * @details pattern to switch from jtag to swd , lsb is shifted out first
 * @{
 */
#define SWD_PATTERN_UPPER_CTRL__PATTERN__SHIFT                                0
#define SWD_PATTERN_UPPER_CTRL__PATTERN__WIDTH                               32
#define SWD_PATTERN_UPPER_CTRL__PATTERN__MASK                       0xffffffffU
#define SWD_PATTERN_UPPER_CTRL__PATTERN__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_PATTERN_UPPER_CTRL__PATTERN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_PATTERN_UPPER_CTRL__PATTERN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_PATTERN_UPPER_CTRL__PATTERN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_PATTERN_UPPER_CTRL__PATTERN__RESET_VALUE                0xffffffffU
/** @} */
#define SWD_PATTERN_UPPER_CTRL__TYPE                                   uint32_t
#define SWD_PATTERN_UPPER_CTRL__READ                                0xffffffffU
#define SWD_PATTERN_UPPER_CTRL__WRITE                               0xffffffffU
#define SWD_PATTERN_UPPER_CTRL__PRESERVED                           0x00000000U
#define SWD_PATTERN_UPPER_CTRL__RESET_VALUE                         0xffffffffU

#endif /* __SWD_PATTERN_UPPER_CTRL_MACRO__ */

/** @} end of pattern_upper_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_pattern_lower_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_pattern_lower_ctrl pattern_lower_ctrl
 * @brief Contains register fields associated with pattern_lower_ctrl. definitions.
 * @{
 */
#ifndef __SWD_PATTERN_LOWER_CTRL_MACRO__
#define __SWD_PATTERN_LOWER_CTRL_MACRO__

/* macros for field pattern */
/**
 * @defgroup at_apb_swd_regs_core_pattern_field pattern_field
 * @brief macros for field pattern
 * @details pattern to switch from jtag to swd , lsb is shifted out first
 * @{
 */
#define SWD_PATTERN_LOWER_CTRL__PATTERN__SHIFT                                0
#define SWD_PATTERN_LOWER_CTRL__PATTERN__WIDTH                               32
#define SWD_PATTERN_LOWER_CTRL__PATTERN__MASK                       0xffffffffU
#define SWD_PATTERN_LOWER_CTRL__PATTERN__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_PATTERN_LOWER_CTRL__PATTERN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_PATTERN_LOWER_CTRL__PATTERN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_PATTERN_LOWER_CTRL__PATTERN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_PATTERN_LOWER_CTRL__PATTERN__RESET_VALUE                0xffffffffU
/** @} */
#define SWD_PATTERN_LOWER_CTRL__TYPE                                   uint32_t
#define SWD_PATTERN_LOWER_CTRL__READ                                0xffffffffU
#define SWD_PATTERN_LOWER_CTRL__WRITE                               0xffffffffU
#define SWD_PATTERN_LOWER_CTRL__PRESERVED                           0x00000000U
#define SWD_PATTERN_LOWER_CTRL__RESET_VALUE                         0xffffffffU

#endif /* __SWD_PATTERN_LOWER_CTRL_MACRO__ */

/** @} end of pattern_lower_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_tail_dur */
/**
 * @defgroup at_apb_swd_regs_core_tail_dur tail_dur
 * @brief Contains register fields associated with tail_dur. definitions.
 * @{
 */
#ifndef __SWD_TAIL_DUR_MACRO__
#define __SWD_TAIL_DUR_MACRO__

/* macros for field count */
/**
 * @defgroup at_apb_swd_regs_core_count_field count_field
 * @brief macros for field count
 * @details exact number of extra cycles after a packet. 0 means no tail. must be at least 5 cycles after a DAP packet
 * @{
 */
#define SWD_TAIL_DUR__COUNT__SHIFT                                            0
#define SWD_TAIL_DUR__COUNT__WIDTH                                            4
#define SWD_TAIL_DUR__COUNT__MASK                                   0x0000000fU
#define SWD_TAIL_DUR__COUNT__READ(src)          ((uint32_t)(src) & 0x0000000fU)
#define SWD_TAIL_DUR__COUNT__WRITE(src)         ((uint32_t)(src) & 0x0000000fU)
#define SWD_TAIL_DUR__COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define SWD_TAIL_DUR__COUNT__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000000fU)))
#define SWD_TAIL_DUR__COUNT__RESET_VALUE                            0x00000005U
/** @} */
#define SWD_TAIL_DUR__TYPE                                             uint32_t
#define SWD_TAIL_DUR__READ                                          0x0000000fU
#define SWD_TAIL_DUR__WRITE                                         0x0000000fU
#define SWD_TAIL_DUR__PRESERVED                                     0x00000000U
#define SWD_TAIL_DUR__RESET_VALUE                                   0x00000005U

#endif /* __SWD_TAIL_DUR_MACRO__ */

/** @} end of tail_dur */

/* macros for BlueprintGlobalNameSpace::SWD_pattern_dur */
/**
 * @defgroup at_apb_swd_regs_core_pattern_dur pattern_dur
 * @brief Contains register fields associated with pattern_dur. definitions.
 * @{
 */
#ifndef __SWD_PATTERN_DUR_MACRO__
#define __SWD_PATTERN_DUR_MACRO__

/* macros for field count */
/**
 * @defgroup at_apb_swd_regs_core_count_field count_field
 * @brief macros for field count
 * @details number cycles to drive the pattern MSB first is count + 1. e.g. 64 cycles by default
 * @{
 */
#define SWD_PATTERN_DUR__COUNT__SHIFT                                         0
#define SWD_PATTERN_DUR__COUNT__WIDTH                                         8
#define SWD_PATTERN_DUR__COUNT__MASK                                0x000000ffU
#define SWD_PATTERN_DUR__COUNT__READ(src)       ((uint32_t)(src) & 0x000000ffU)
#define SWD_PATTERN_DUR__COUNT__WRITE(src)      ((uint32_t)(src) & 0x000000ffU)
#define SWD_PATTERN_DUR__COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SWD_PATTERN_DUR__COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SWD_PATTERN_DUR__COUNT__RESET_VALUE                         0x0000003fU
/** @} */
#define SWD_PATTERN_DUR__TYPE                                          uint32_t
#define SWD_PATTERN_DUR__READ                                       0x000000ffU
#define SWD_PATTERN_DUR__WRITE                                      0x000000ffU
#define SWD_PATTERN_DUR__PRESERVED                                  0x00000000U
#define SWD_PATTERN_DUR__RESET_VALUE                                0x0000003fU

#endif /* __SWD_PATTERN_DUR_MACRO__ */

/** @} end of pattern_dur */

/* macros for BlueprintGlobalNameSpace::SWD_dap_bridge_status */
/**
 * @defgroup at_apb_swd_regs_core_dap_bridge_status dap_bridge_status
 * @brief Contains register fields associated with dap_bridge_status. definitions.
 * @{
 */
#ifndef __SWD_DAP_BRIDGE_STATUS_MACRO__
#define __SWD_DAP_BRIDGE_STATUS_MACRO__

/* macros for field busy */
/**
 * @defgroup at_apb_swd_regs_core_busy_field busy_field
 * @brief macros for field busy
 * @{
 */
#define SWD_DAP_BRIDGE_STATUS__BUSY__SHIFT                                    0
#define SWD_DAP_BRIDGE_STATUS__BUSY__WIDTH                                    1
#define SWD_DAP_BRIDGE_STATUS__BUSY__MASK                           0x00000001U
#define SWD_DAP_BRIDGE_STATUS__BUSY__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define SWD_DAP_BRIDGE_STATUS__BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_DAP_BRIDGE_STATUS__BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_DAP_BRIDGE_STATUS__BUSY__RESET_VALUE                    0x00000000U
/** @} */
#define SWD_DAP_BRIDGE_STATUS__TYPE                                    uint32_t
#define SWD_DAP_BRIDGE_STATUS__READ                                 0x00000001U
#define SWD_DAP_BRIDGE_STATUS__PRESERVED                            0x00000000U
#define SWD_DAP_BRIDGE_STATUS__RESET_VALUE                          0x00000000U

#endif /* __SWD_DAP_BRIDGE_STATUS_MACRO__ */

/** @} end of dap_bridge_status */

/* macros for BlueprintGlobalNameSpace::SWD_dap_resp_status */
/**
 * @defgroup at_apb_swd_regs_core_dap_resp_status dap_resp_status
 * @brief Contains register fields associated with dap_resp_status. definitions.
 * @{
 */
#ifndef __SWD_DAP_RESP_STATUS_MACRO__
#define __SWD_DAP_RESP_STATUS_MACRO__

/* macros for field dap_resp */
/**
 * @defgroup at_apb_swd_regs_core_dap_resp_field dap_resp_field
 * @brief macros for field dap_resp
 * @{
 */
#define SWD_DAP_RESP_STATUS__DAP_RESP__SHIFT                                  0
#define SWD_DAP_RESP_STATUS__DAP_RESP__WIDTH                                  3
#define SWD_DAP_RESP_STATUS__DAP_RESP__MASK                         0x00000007U
#define SWD_DAP_RESP_STATUS__DAP_RESP__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWD_DAP_RESP_STATUS__DAP_RESP__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field par_err */
/**
 * @defgroup at_apb_swd_regs_core_par_err_field par_err_field
 * @brief macros for field par_err
 * @details 1= RDATA has parity error, 0= otherwise
 * @{
 */
#define SWD_DAP_RESP_STATUS__PAR_ERR__SHIFT                                   3
#define SWD_DAP_RESP_STATUS__PAR_ERR__WIDTH                                   1
#define SWD_DAP_RESP_STATUS__PAR_ERR__MASK                          0x00000008U
#define SWD_DAP_RESP_STATUS__PAR_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define SWD_DAP_RESP_STATUS__PAR_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SWD_DAP_RESP_STATUS__PAR_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SWD_DAP_RESP_STATUS__PAR_ERR__RESET_VALUE                   0x00000000U
/** @} */
#define SWD_DAP_RESP_STATUS__TYPE                                      uint32_t
#define SWD_DAP_RESP_STATUS__READ                                   0x0000000fU
#define SWD_DAP_RESP_STATUS__PRESERVED                              0x00000000U
#define SWD_DAP_RESP_STATUS__RESET_VALUE                            0x00000000U

#endif /* __SWD_DAP_RESP_STATUS_MACRO__ */

/** @} end of dap_resp_status */

/* macros for BlueprintGlobalNameSpace::SWD_RW_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_RW_ctrl RW_ctrl
 * @brief Contains register fields associated with RW_ctrl. definitions.
 * @{
 */
#ifndef __SWD_RW_CTRL_MACRO__
#define __SWD_RW_CTRL_MACRO__

/* macros for field RnW */
/**
 * @defgroup at_apb_swd_regs_core_RnW_field RnW_field
 * @brief macros for field RnW
 * @details 1 for Read, 0 for Write
 * @{
 */
#define SWD_RW_CTRL__RNW__SHIFT                                               0
#define SWD_RW_CTRL__RNW__WIDTH                                               1
#define SWD_RW_CTRL__RNW__MASK                                      0x00000001U
#define SWD_RW_CTRL__RNW__READ(src)             ((uint32_t)(src) & 0x00000001U)
#define SWD_RW_CTRL__RNW__WRITE(src)            ((uint32_t)(src) & 0x00000001U)
#define SWD_RW_CTRL__RNW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_RW_CTRL__RNW__VERIFY(src)     (!(((uint32_t)(src) & ~0x00000001U)))
#define SWD_RW_CTRL__RNW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_RW_CTRL__RNW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_RW_CTRL__RNW__RESET_VALUE                               0x00000000U
/** @} */
#define SWD_RW_CTRL__TYPE                                              uint32_t
#define SWD_RW_CTRL__READ                                           0x00000001U
#define SWD_RW_CTRL__WRITE                                          0x00000001U
#define SWD_RW_CTRL__PRESERVED                                      0x00000000U
#define SWD_RW_CTRL__RESET_VALUE                                    0x00000000U

#endif /* __SWD_RW_CTRL_MACRO__ */

/** @} end of RW_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_apndp_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_apndp_ctrl apndp_ctrl
 * @brief Contains register fields associated with apndp_ctrl. definitions.
 * @{
 */
#ifndef __SWD_APNDP_CTRL_MACRO__
#define __SWD_APNDP_CTRL_MACRO__

/* macros for field APnDP */
/**
 * @defgroup at_apb_swd_regs_core_APnDP_field APnDP_field
 * @brief macros for field APnDP
 * @details 0 for DPACC, 1 for APACC
 * @{
 */
#define SWD_APNDP_CTRL__APNDP__SHIFT                                          0
#define SWD_APNDP_CTRL__APNDP__WIDTH                                          1
#define SWD_APNDP_CTRL__APNDP__MASK                                 0x00000001U
#define SWD_APNDP_CTRL__APNDP__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define SWD_APNDP_CTRL__APNDP__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define SWD_APNDP_CTRL__APNDP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_APNDP_CTRL__APNDP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_APNDP_CTRL__APNDP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_APNDP_CTRL__APNDP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_APNDP_CTRL__APNDP__RESET_VALUE                          0x00000000U
/** @} */
#define SWD_APNDP_CTRL__TYPE                                           uint32_t
#define SWD_APNDP_CTRL__READ                                        0x00000001U
#define SWD_APNDP_CTRL__WRITE                                       0x00000001U
#define SWD_APNDP_CTRL__PRESERVED                                   0x00000000U
#define SWD_APNDP_CTRL__RESET_VALUE                                 0x00000000U

#endif /* __SWD_APNDP_CTRL_MACRO__ */

/** @} end of apndp_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_trigger_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_trigger_ctrl trigger_ctrl
 * @brief Contains register fields associated with trigger_ctrl. definitions.
 * @{
 */
#ifndef __SWD_TRIGGER_CTRL_MACRO__
#define __SWD_TRIGGER_CTRL_MACRO__

/* macros for field go_packet */
/**
 * @defgroup at_apb_swd_regs_core_go_packet_field go_packet_field
 * @brief macros for field go_packet
 * @details 1 to start a dap packet , not self-resetting.  This trigger does not start a DAP reset. See go_pattern to for DAP reset.
 * @{
 */
#define SWD_TRIGGER_CTRL__GO_PACKET__SHIFT                                    0
#define SWD_TRIGGER_CTRL__GO_PACKET__WIDTH                                    1
#define SWD_TRIGGER_CTRL__GO_PACKET__MASK                           0x00000001U
#define SWD_TRIGGER_CTRL__GO_PACKET__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define SWD_TRIGGER_CTRL__GO_PACKET__WRITE(src) ((uint32_t)(src) & 0x00000001U)
#define SWD_TRIGGER_CTRL__GO_PACKET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_TRIGGER_CTRL__GO_PACKET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_TRIGGER_CTRL__GO_PACKET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_TRIGGER_CTRL__GO_PACKET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_TRIGGER_CTRL__GO_PACKET__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field go_pattern */
/**
 * @defgroup at_apb_swd_regs_core_go_pattern_field go_pattern_field
 * @brief macros for field go_pattern
 * @details 1 to start resetting by sending a pattern of bits as prescribed by pattern_upper_ctrl and pattern_lower_ctrl.  The length of the pattern is set by pattern_dur. not self-resetting.  The reset pattern is to bring the target DAP to an inital state.
 * @{
 */
#define SWD_TRIGGER_CTRL__GO_PATTERN__SHIFT                                   2
#define SWD_TRIGGER_CTRL__GO_PATTERN__WIDTH                                   1
#define SWD_TRIGGER_CTRL__GO_PATTERN__MASK                          0x00000004U
#define SWD_TRIGGER_CTRL__GO_PATTERN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SWD_TRIGGER_CTRL__GO_PATTERN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SWD_TRIGGER_CTRL__GO_PATTERN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SWD_TRIGGER_CTRL__GO_PATTERN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SWD_TRIGGER_CTRL__GO_PATTERN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SWD_TRIGGER_CTRL__GO_PATTERN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SWD_TRIGGER_CTRL__GO_PATTERN__RESET_VALUE                   0x00000000U
/** @} */
#define SWD_TRIGGER_CTRL__TYPE                                         uint32_t
#define SWD_TRIGGER_CTRL__READ                                      0x00000005U
#define SWD_TRIGGER_CTRL__WRITE                                     0x00000005U
#define SWD_TRIGGER_CTRL__PRESERVED                                 0x00000000U
#define SWD_TRIGGER_CTRL__RESET_VALUE                               0x00000000U

#endif /* __SWD_TRIGGER_CTRL_MACRO__ */

/** @} end of trigger_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_dap_rdata */
/**
 * @defgroup at_apb_swd_regs_core_dap_rdata dap_rdata
 * @brief Contains register fields associated with dap_rdata. definitions.
 * @{
 */
#ifndef __SWD_DAP_RDATA_MACRO__
#define __SWD_DAP_RDATA_MACRO__

/* macros for field dap_rdata */
/**
 * @defgroup at_apb_swd_regs_core_dap_rdata_field dap_rdata_field
 * @brief macros for field dap_rdata
 * @{
 */
#define SWD_DAP_RDATA__DAP_RDATA__SHIFT                                       0
#define SWD_DAP_RDATA__DAP_RDATA__WIDTH                                      32
#define SWD_DAP_RDATA__DAP_RDATA__MASK                              0xffffffffU
#define SWD_DAP_RDATA__DAP_RDATA__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define SWD_DAP_RDATA__DAP_RDATA__RESET_VALUE                       0x00000000U
/** @} */
#define SWD_DAP_RDATA__TYPE                                            uint32_t
#define SWD_DAP_RDATA__READ                                         0xffffffffU
#define SWD_DAP_RDATA__PRESERVED                                    0x00000000U
#define SWD_DAP_RDATA__RESET_VALUE                                  0x00000000U

#endif /* __SWD_DAP_RDATA_MACRO__ */

/** @} end of dap_rdata */

/* macros for BlueprintGlobalNameSpace::SWD_interrupt_mask */
/**
 * @defgroup at_apb_swd_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __SWD_INTERRUPT_MASK_MACRO__
#define __SWD_INTERRUPT_MASK_MACRO__

/* macros for field passthru0 */
/**
 * @defgroup at_apb_swd_regs_core_passthru0_field passthru0_field
 * @brief macros for field passthru0
 * @details 1=allow interrupt0 (read done) to be OR'ed into core interrupt
 * @{
 */
#define SWD_INTERRUPT_MASK__PASSTHRU0__SHIFT                                  0
#define SWD_INTERRUPT_MASK__PASSTHRU0__WIDTH                                  1
#define SWD_INTERRUPT_MASK__PASSTHRU0__MASK                         0x00000001U
#define SWD_INTERRUPT_MASK__PASSTHRU0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_INTERRUPT_MASK__PASSTHRU0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_INTERRUPT_MASK__PASSTHRU0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_INTERRUPT_MASK__PASSTHRU0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_INTERRUPT_MASK__PASSTHRU0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_INTERRUPT_MASK__PASSTHRU0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_INTERRUPT_MASK__PASSTHRU0__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field passthru1 */
/**
 * @defgroup at_apb_swd_regs_core_passthru1_field passthru1_field
 * @brief macros for field passthru1
 * @details 1=allow interrupt1 (par err on readback data) to be OR'ed into core interrupt
 * @{
 */
#define SWD_INTERRUPT_MASK__PASSTHRU1__SHIFT                                  1
#define SWD_INTERRUPT_MASK__PASSTHRU1__WIDTH                                  1
#define SWD_INTERRUPT_MASK__PASSTHRU1__MASK                         0x00000002U
#define SWD_INTERRUPT_MASK__PASSTHRU1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWD_INTERRUPT_MASK__PASSTHRU1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWD_INTERRUPT_MASK__PASSTHRU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWD_INTERRUPT_MASK__PASSTHRU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWD_INTERRUPT_MASK__PASSTHRU1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWD_INTERRUPT_MASK__PASSTHRU1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWD_INTERRUPT_MASK__PASSTHRU1__RESET_VALUE                  0x00000000U
/** @} */
#define SWD_INTERRUPT_MASK__TYPE                                       uint32_t
#define SWD_INTERRUPT_MASK__READ                                    0x00000003U
#define SWD_INTERRUPT_MASK__WRITE                                   0x00000003U
#define SWD_INTERRUPT_MASK__PRESERVED                               0x00000000U
#define SWD_INTERRUPT_MASK__RESET_VALUE                             0x00000000U

#endif /* __SWD_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::SWD_interrupt_status */
/**
 * @defgroup at_apb_swd_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __SWD_INTERRUPT_STATUS_MACRO__
#define __SWD_INTERRUPT_STATUS_MACRO__

/* macros for field interrupt0 */
/**
 * @defgroup at_apb_swd_regs_core_interrupt0_field interrupt0_field
 * @brief macros for field interrupt0
 * @details saw a rising edge on done; independent of mask
 * @{
 */
#define SWD_INTERRUPT_STATUS__INTERRUPT0__SHIFT                               0
#define SWD_INTERRUPT_STATUS__INTERRUPT0__WIDTH                               1
#define SWD_INTERRUPT_STATUS__INTERRUPT0__MASK                      0x00000001U
#define SWD_INTERRUPT_STATUS__INTERRUPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_INTERRUPT_STATUS__INTERRUPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_INTERRUPT_STATUS__INTERRUPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_INTERRUPT_STATUS__INTERRUPT0__RESET_VALUE               0x00000000U
/** @} */

/* macros for field interrupt1 */
/**
 * @defgroup at_apb_swd_regs_core_interrupt1_field interrupt1_field
 * @brief macros for field interrupt1
 * @details saw a rising edge on par_err; independent of mask
 * @{
 */
#define SWD_INTERRUPT_STATUS__INTERRUPT1__SHIFT                               1
#define SWD_INTERRUPT_STATUS__INTERRUPT1__WIDTH                               1
#define SWD_INTERRUPT_STATUS__INTERRUPT1__MASK                      0x00000002U
#define SWD_INTERRUPT_STATUS__INTERRUPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWD_INTERRUPT_STATUS__INTERRUPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWD_INTERRUPT_STATUS__INTERRUPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWD_INTERRUPT_STATUS__INTERRUPT1__RESET_VALUE               0x00000000U
/** @} */
#define SWD_INTERRUPT_STATUS__TYPE                                     uint32_t
#define SWD_INTERRUPT_STATUS__READ                                  0x00000003U
#define SWD_INTERRUPT_STATUS__PRESERVED                             0x00000000U
#define SWD_INTERRUPT_STATUS__RESET_VALUE                           0x00000000U

#endif /* __SWD_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::SWD_set_interrupt */
/**
 * @defgroup at_apb_swd_regs_core_set_interrupt set_interrupt
 * @brief not auto cleared definitions.
 * @{
 */
#ifndef __SWD_SET_INTERRUPT_MACRO__
#define __SWD_SET_INTERRUPT_MACRO__

/* macros for field set_interrupt0 */
/**
 * @defgroup at_apb_swd_regs_core_set_interrupt0_field set_interrupt0_field
 * @brief macros for field set_interrupt0
 * @details set interrupt 0
 * @{
 */
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__SHIFT                              0
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__WIDTH                              1
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__MASK                     0x00000001U
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_SET_INTERRUPT__SET_INTERRUPT0__RESET_VALUE              0x00000000U
/** @} */

/* macros for field set_interrupt1 */
/**
 * @defgroup at_apb_swd_regs_core_set_interrupt1_field set_interrupt1_field
 * @brief macros for field set_interrupt1
 * @details set interrupt 1
 * @{
 */
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__SHIFT                              1
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__WIDTH                              1
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__MASK                     0x00000002U
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWD_SET_INTERRUPT__SET_INTERRUPT1__RESET_VALUE              0x00000000U
/** @} */
#define SWD_SET_INTERRUPT__TYPE                                        uint32_t
#define SWD_SET_INTERRUPT__READ                                     0x00000003U
#define SWD_SET_INTERRUPT__WRITE                                    0x00000003U
#define SWD_SET_INTERRUPT__PRESERVED                                0x00000000U
#define SWD_SET_INTERRUPT__RESET_VALUE                              0x00000000U

#endif /* __SWD_SET_INTERRUPT_MACRO__ */

/** @} end of set_interrupt */

/* macros for BlueprintGlobalNameSpace::SWD_reset_interrupt */
/**
 * @defgroup at_apb_swd_regs_core_reset_interrupt reset_interrupt
 * @brief not auto cleared definitions.
 * @{
 */
#ifndef __SWD_RESET_INTERRUPT_MACRO__
#define __SWD_RESET_INTERRUPT_MACRO__

/* macros for field reset_interrupt0 */
/**
 * @defgroup at_apb_swd_regs_core_reset_interrupt0_field reset_interrupt0_field
 * @brief macros for field reset_interrupt0
 * @details reset interrupt 0
 * @{
 */
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__SHIFT                          0
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__WIDTH                          1
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__MASK                 0x00000001U
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT0__RESET_VALUE          0x00000000U
/** @} */

/* macros for field reset_interrupt1 */
/**
 * @defgroup at_apb_swd_regs_core_reset_interrupt1_field reset_interrupt1_field
 * @brief macros for field reset_interrupt1
 * @details reset interrupt 1
 * @{
 */
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__SHIFT                          1
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__WIDTH                          1
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__MASK                 0x00000002U
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWD_RESET_INTERRUPT__RESET_INTERRUPT1__RESET_VALUE          0x00000000U
/** @} */
#define SWD_RESET_INTERRUPT__TYPE                                      uint32_t
#define SWD_RESET_INTERRUPT__READ                                   0x00000003U
#define SWD_RESET_INTERRUPT__WRITE                                  0x00000003U
#define SWD_RESET_INTERRUPT__PRESERVED                              0x00000000U
#define SWD_RESET_INTERRUPT__RESET_VALUE                            0x00000000U

#endif /* __SWD_RESET_INTERRUPT_MACRO__ */

/** @} end of reset_interrupt */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_ctrl dtop_bypass_ctrl
 * @brief Contains register fields associated with dtop_bypass_ctrl. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_CTRL_MACRO__
#define __SWD_DTOP_BYPASS_CTRL_MACRO__

/* macros for field hw_own */
/**
 * @defgroup at_apb_swd_regs_core_hw_own_field hw_own_field
 * @brief macros for field hw_own
 * @details 1 to indicate hw own and sw control is disabled
 * @{
 */
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__SHIFT                                   0
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__WIDTH                                   1
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__MASK                          0x00000001U
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__READ(src) ((uint32_t)(src) & 0x00000001U)
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_DTOP_BYPASS_CTRL__HW_OWN__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field byp_rd */
/**
 * @defgroup at_apb_swd_regs_core_byp_rd_field byp_rd_field
 * @brief macros for field byp_rd
 * @details 1 to bypass read modify write
 * @{
 */
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__SHIFT                                   1
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__WIDTH                                   1
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__MASK                          0x00000002U
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWD_DTOP_BYPASS_CTRL__BYP_RD__RESET_VALUE                   0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_CTRL__TYPE                                     uint32_t
#define SWD_DTOP_BYPASS_CTRL__READ                                  0x00000003U
#define SWD_DTOP_BYPASS_CTRL__WRITE                                 0x00000003U
#define SWD_DTOP_BYPASS_CTRL__PRESERVED                             0x00000000U
#define SWD_DTOP_BYPASS_CTRL__RESET_VALUE                           0x00000000U

#endif /* __SWD_DTOP_BYPASS_CTRL_MACRO__ */

/** @} end of dtop_bypass_ctrl */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_stat */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_stat dtop_bypass_stat
 * @brief Contains register fields associated with dtop_bypass_stat. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_STAT_MACRO__
#define __SWD_DTOP_BYPASS_STAT_MACRO__

/* macros for field mode */
/**
 * @defgroup at_apb_swd_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details 1 if fpga is in dtop_bypass mode (built with FPGA_DTOP_BYP defined)
 * @{
 */
#define SWD_DTOP_BYPASS_STAT__MODE__SHIFT                                     0
#define SWD_DTOP_BYPASS_STAT__MODE__WIDTH                                     1
#define SWD_DTOP_BYPASS_STAT__MODE__MASK                            0x00000001U
#define SWD_DTOP_BYPASS_STAT__MODE__READ(src)   ((uint32_t)(src) & 0x00000001U)
#define SWD_DTOP_BYPASS_STAT__MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_DTOP_BYPASS_STAT__MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_DTOP_BYPASS_STAT__MODE__RESET_VALUE                     0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_STAT__TYPE                                     uint32_t
#define SWD_DTOP_BYPASS_STAT__READ                                  0x00000001U
#define SWD_DTOP_BYPASS_STAT__PRESERVED                             0x00000000U
#define SWD_DTOP_BYPASS_STAT__RESET_VALUE                           0x00000000U

#endif /* __SWD_DTOP_BYPASS_STAT_MACRO__ */

/** @} end of dtop_bypass_stat */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_gpo */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_gpo dtop_bypass_gpo
 * @brief Contains register fields associated with dtop_bypass_gpo. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_GPO_MACRO__
#define __SWD_DTOP_BYPASS_GPO_MACRO__

/* macros for field gpo */
/**
 * @defgroup at_apb_swd_regs_core_gpo_field gpo_field
 * @brief macros for field gpo
 * @details 1 selects ext clock as source in DTOP_BYPASS, 0 selects internal pll.
 * @{
 */
#define SWD_DTOP_BYPASS_GPO__GPO__SHIFT                                       0
#define SWD_DTOP_BYPASS_GPO__GPO__WIDTH                                      16
#define SWD_DTOP_BYPASS_GPO__GPO__MASK                              0x0000ffffU
#define SWD_DTOP_BYPASS_GPO__GPO__READ(src)     ((uint32_t)(src) & 0x0000ffffU)
#define SWD_DTOP_BYPASS_GPO__GPO__WRITE(src)    ((uint32_t)(src) & 0x0000ffffU)
#define SWD_DTOP_BYPASS_GPO__GPO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define SWD_DTOP_BYPASS_GPO__GPO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define SWD_DTOP_BYPASS_GPO__GPO__RESET_VALUE                       0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_GPO__TYPE                                      uint32_t
#define SWD_DTOP_BYPASS_GPO__READ                                   0x0000ffffU
#define SWD_DTOP_BYPASS_GPO__WRITE                                  0x0000ffffU
#define SWD_DTOP_BYPASS_GPO__PRESERVED                              0x00000000U
#define SWD_DTOP_BYPASS_GPO__RESET_VALUE                            0x00000000U

#endif /* __SWD_DTOP_BYPASS_GPO_MACRO__ */

/** @} end of dtop_bypass_gpo */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_mode_cntl */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_mode_cntl dtop_bypass_rif_mode_cntl
 * @brief Contains register fields associated with dtop_bypass_rif_mode_cntl. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_MODE_CNTL_MACRO__
#define __SWD_DTOP_BYPASS_RIF_MODE_CNTL_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details rif mode control address.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__SHIFT                            0
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__WIDTH                           32
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__MASK                   0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__ADDR__RESET_VALUE            0x500040acU
/** @} */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__TYPE                            uint32_t
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__READ                         0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__WRITE                        0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__PRESERVED                    0x00000000U
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL__RESET_VALUE                  0x500040acU

#endif /* __SWD_DTOP_BYPASS_RIF_MODE_CNTL_MACRO__ */

/** @} end of dtop_bypass_rif_mode_cntl */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_cal_cntl */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_cal_cntl dtop_bypass_rif_cal_cntl
 * @brief Contains register fields associated with dtop_bypass_rif_cal_cntl. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_CAL_CNTL_MACRO__
#define __SWD_DTOP_BYPASS_RIF_CAL_CNTL_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details rif cal control address.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__SHIFT                             0
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__WIDTH                            32
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__MASK                    0xffffffffU
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__ADDR__RESET_VALUE             0x500040b0U
/** @} */
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__TYPE                             uint32_t
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__READ                          0xffffffffU
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__WRITE                         0xffffffffU
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__PRESERVED                     0x00000000U
#define SWD_DTOP_BYPASS_RIF_CAL_CNTL__RESET_VALUE                   0x500040b0U

#endif /* __SWD_DTOP_BYPASS_RIF_CAL_CNTL_MACRO__ */

/** @} end of dtop_bypass_rif_cal_cntl */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_rxdc7 */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_rxdc7 dtop_bypass_rif_rxdc7
 * @brief Contains register fields associated with dtop_bypass_rif_rxdc7. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_RXDC7_MACRO__
#define __SWD_DTOP_BYPASS_RIF_RXDC7_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details rif rxdc7 address.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__SHIFT                                0
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__WIDTH                               32
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__MASK                       0xffffffffU
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_RXDC7__ADDR__RESET_VALUE                0x50004090U
/** @} */
#define SWD_DTOP_BYPASS_RIF_RXDC7__TYPE                                uint32_t
#define SWD_DTOP_BYPASS_RIF_RXDC7__READ                             0xffffffffU
#define SWD_DTOP_BYPASS_RIF_RXDC7__WRITE                            0xffffffffU
#define SWD_DTOP_BYPASS_RIF_RXDC7__PRESERVED                        0x00000000U
#define SWD_DTOP_BYPASS_RIF_RXDC7__RESET_VALUE                      0x50004090U

#endif /* __SWD_DTOP_BYPASS_RIF_RXDC7_MACRO__ */

/** @} end of dtop_bypass_rif_rxdc7 */

/* macros for BlueprintGlobalNameSpace::SWD_core_id */
/**
 * @defgroup at_apb_swd_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __SWD_CORE_ID_MACRO__
#define __SWD_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_swd_regs_core_id_field id_field
 * @brief macros for field id
 * @details SWD in ASCII
 * @{
 */
#define SWD_CORE_ID__ID__SHIFT                                                0
#define SWD_CORE_ID__ID__WIDTH                                               32
#define SWD_CORE_ID__ID__MASK                                       0xffffffffU
#define SWD_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define SWD_CORE_ID__ID__RESET_VALUE                                0x53574420U
/** @} */
#define SWD_CORE_ID__TYPE                                              uint32_t
#define SWD_CORE_ID__READ                                           0xffffffffU
#define SWD_CORE_ID__PRESERVED                                      0x00000000U
#define SWD_CORE_ID__RESET_VALUE                                    0x53574420U

#endif /* __SWD_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of AT_APB_SWD_REGS_CORE */
#endif /* __REG_AT_APB_SWD_REGS_CORE_H__ */
