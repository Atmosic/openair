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

/* macros for field seq_skip_en */
/**
 * @defgroup at_apb_swd_regs_core_seq_skip_en_field seq_skip_en_field
 * @brief macros for field seq_skip_en
 * @details  If seq_skip_en[0] is set, output seq_skip[0] will pulse and {addr0,wdata0} states will be skipped in the four register write sequence burst.  Control bit seq_skip_en[1] is not presently used.  Control bit seq_skip_en[2] is not presently used.  If seq_skip_en[3] is set, output seq_skip[3] will pulse and {addr3,wdata3} states will be skipped in the four register write sequence burst.
 * @{
 */
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__SHIFT                              2
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__WIDTH                              4
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__MASK                     0x0000003cU
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000003cU) >> 2)
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000003cU)
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003cU) | (((uint32_t)(src) <<\
                    2) & 0x0000003cU)
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000003cU)))
#define SWD_DTOP_BYPASS_CTRL__SEQ_SKIP_EN__RESET_VALUE              0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_CTRL__TYPE                                     uint32_t
#define SWD_DTOP_BYPASS_CTRL__READ                                  0x0000003fU
#define SWD_DTOP_BYPASS_CTRL__WRITE                                 0x0000003fU
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

/* macros for field bb1_dcoc_msb */
/**
 * @defgroup at_apb_swd_regs_core_bb1_dcoc_msb_field bb1_dcoc_msb_field
 * @brief macros for field bb1_dcoc_msb
 * @details caldc_remap  0 = remap caldc from 3 to 2 for Paris radio  1 = pass through caldc for Perth radio bb1_dcoc_msb  0 = invert MSB's for bb1i_dcoc and bb1q_dcoc for Paris 1.x radio  1 = pass through bb1i_dcoc and bb1q_dcoc for Paris 2.x radio ignore_bb1_dcoc  0 = allow SWD to write bb1i_dcoc and bb1q_dcoc updates to radio  1 = block SWD from writing bb1i_dcoc and bb1q_dcoc updates to radio
 * @{
 */
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__SHIFT                              0
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__WIDTH                              1
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__MASK                     0x00000001U
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_DTOP_BYPASS_GPO__BB1_DCOC_MSB__RESET_VALUE              0x00000000U
/** @} */

/* macros for field caldc_remap */
/**
 * @defgroup at_apb_swd_regs_core_caldc_remap_field caldc_remap_field
 * @brief macros for field caldc_remap
 * @details caldc_remap  0 = remap caldc from 3 to 2 for Paris radio  1 = pass through caldc for Perth radio bb1_dcoc_msb  0 = invert MSB's for bb1i_dcoc and bb1q_dcoc for Paris 1.x radio  1 = pass through bb1i_dcoc and bb1q_dcoc for Paris 2.x radio ignore_bb1_dcoc  0 = allow SWD to write bb1i_dcoc and bb1q_dcoc updates to radio  1 = block SWD from writing bb1i_dcoc and bb1q_dcoc updates to radio
 * @{
 */
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__SHIFT                               1
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__WIDTH                               1
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__MASK                      0x00000002U
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWD_DTOP_BYPASS_GPO__CALDC_REMAP__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ignore_bb1_dcoc */
/**
 * @defgroup at_apb_swd_regs_core_ignore_bb1_dcoc_field ignore_bb1_dcoc_field
 * @brief macros for field ignore_bb1_dcoc
 * @details caldc_remap  0 = remap caldc from 3 to 2 for Paris radio  1 = pass through caldc for Perth radio bb1_dcoc_msb  0 = invert MSB's for bb1i_dcoc and bb1q_dcoc for Paris 1.x radio  1 = pass through bb1i_dcoc and bb1q_dcoc for Paris 2.x radio ignore_bb1_dcoc  0 = allow SWD to write bb1i_dcoc and bb1q_dcoc updates to radio  1 = block SWD from writing bb1i_dcoc and bb1q_dcoc updates to radio
 * @{
 */
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__SHIFT                           2
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__WIDTH                           1
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__MASK                  0x00000004U
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SWD_DTOP_BYPASS_GPO__IGNORE_BB1_DCOC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field spare */
/**
 * @defgroup at_apb_swd_regs_core_spare_field spare_field
 * @brief macros for field spare
 * @details caldc_remap  0 = remap caldc from 3 to 2 for Paris radio  1 = pass through caldc for Perth radio bb1_dcoc_msb  0 = invert MSB's for bb1i_dcoc and bb1q_dcoc for Paris 1.x radio  1 = pass through bb1i_dcoc and bb1q_dcoc for Paris 2.x radio ignore_bb1_dcoc  0 = allow SWD to write bb1i_dcoc and bb1q_dcoc updates to radio  1 = block SWD from writing bb1i_dcoc and bb1q_dcoc updates to radio
 * @{
 */
#define SWD_DTOP_BYPASS_GPO__SPARE__SHIFT                                     3
#define SWD_DTOP_BYPASS_GPO__SPARE__WIDTH                                    13
#define SWD_DTOP_BYPASS_GPO__SPARE__MASK                            0x0000fff8U
#define SWD_DTOP_BYPASS_GPO__SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fff8U) >> 3)
#define SWD_DTOP_BYPASS_GPO__SPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x0000fff8U)
#define SWD_DTOP_BYPASS_GPO__SPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fff8U) | (((uint32_t)(src) <<\
                    3) & 0x0000fff8U)
#define SWD_DTOP_BYPASS_GPO__SPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x0000fff8U)))
#define SWD_DTOP_BYPASS_GPO__SPARE__RESET_VALUE                     0x00000000U
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

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_mode_cntl2 */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_mode_cntl2 dtop_bypass_rif_mode_cntl2
 * @brief Contains register fields associated with dtop_bypass_rif_mode_cntl2. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_MACRO__
#define __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details rif mode control2 address.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__SHIFT                           0
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__WIDTH                          32
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__MASK                  0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__ADDR__RESET_VALUE           0x401540f8U
/** @} */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__TYPE                           uint32_t
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__READ                        0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__WRITE                       0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__PRESERVED                   0x00000000U
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2__RESET_VALUE                 0x401540f8U

#endif /* __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_MACRO__ */

/** @} end of dtop_bypass_rif_mode_cntl2 */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_mode_cntl2_p */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_mode_cntl2_p dtop_bypass_rif_mode_cntl2_p
 * @brief Contains register fields associated with dtop_bypass_rif_mode_cntl2_p. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P_MACRO__
#define __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif mode control2 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__SHIFT                        0
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__WIDTH                       32
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__MASK               0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WDATA__RESET_VALUE        0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__TYPE                         uint32_t
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__READ                      0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__WRITE                     0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__PRESERVED                 0x00000000U
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P__RESET_VALUE               0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_P_MACRO__ */

/** @} end of dtop_bypass_rif_mode_cntl2_p */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_mode_cntl2_n */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_mode_cntl2_n dtop_bypass_rif_mode_cntl2_n
 * @brief Contains register fields associated with dtop_bypass_rif_mode_cntl2_n. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N_MACRO__
#define __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif mode control2 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__SHIFT                        0
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__WIDTH                       32
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__MASK               0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WDATA__RESET_VALUE        0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__TYPE                         uint32_t
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__READ                      0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__WRITE                     0xffffffffU
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__PRESERVED                 0x00000000U
#define SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N__RESET_VALUE               0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_MODE_CNTL2_N_MACRO__ */

/** @} end of dtop_bypass_rif_mode_cntl2_n */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_syntx_154 */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_syntx_154 dtop_bypass_rif_syntx_154
 * @brief Contains register fields associated with dtop_bypass_rif_syntx_154. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_SYNTX_154_MACRO__
#define __SWD_DTOP_BYPASS_RIF_SYNTX_154_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details rif syntx_154 address.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__SHIFT                            0
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__WIDTH                           32
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__MASK                   0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__ADDR__RESET_VALUE            0x5015407cU
/** @} */
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__TYPE                            uint32_t
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__READ                         0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__WRITE                        0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__PRESERVED                    0x00000000U
#define SWD_DTOP_BYPASS_RIF_SYNTX_154__RESET_VALUE                  0x5015407cU

#endif /* __SWD_DTOP_BYPASS_RIF_SYNTX_154_MACRO__ */

/** @} end of dtop_bypass_rif_syntx_154 */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_syntx_154_p */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_syntx_154_p dtop_bypass_rif_syntx_154_p
 * @brief Contains register fields associated with dtop_bypass_rif_syntx_154_p. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_SYNTX_154_P_MACRO__
#define __SWD_DTOP_BYPASS_RIF_SYNTX_154_P_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif syntx_154 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__SHIFT                         0
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__WIDTH                        32
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__MASK                0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WDATA__RESET_VALUE         0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__TYPE                          uint32_t
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__READ                       0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__WRITE                      0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__PRESERVED                  0x00000000U
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_P__RESET_VALUE                0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_SYNTX_154_P_MACRO__ */

/** @} end of dtop_bypass_rif_syntx_154_p */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_syntx_154_n */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_syntx_154_n dtop_bypass_rif_syntx_154_n
 * @brief Contains register fields associated with dtop_bypass_rif_syntx_154_n. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_SYNTX_154_N_MACRO__
#define __SWD_DTOP_BYPASS_RIF_SYNTX_154_N_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif syntx_154 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__SHIFT                         0
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__WIDTH                        32
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__MASK                0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WDATA__RESET_VALUE         0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__TYPE                          uint32_t
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__READ                       0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__WRITE                      0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__PRESERVED                  0x00000000U
#define SWD_DTOP_BYPASS_RIF_SYNTX_154_N__RESET_VALUE                0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_SYNTX_154_N_MACRO__ */

/** @} end of dtop_bypass_rif_syntx_154_n */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_synth_chan5 */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_synth_chan5 dtop_bypass_rif_synth_chan5
 * @brief Contains register fields associated with dtop_bypass_rif_synth_chan5. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_MACRO__
#define __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details rif synth_chan5 address.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__SHIFT                          0
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__WIDTH                         32
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__MASK                 0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__ADDR__RESET_VALUE          0x501540ecU
/** @} */
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__TYPE                          uint32_t
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__READ                       0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__WRITE                      0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__PRESERVED                  0x00000000U
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5__RESET_VALUE                0x501540ecU

#endif /* __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_MACRO__ */

/** @} end of dtop_bypass_rif_synth_chan5 */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_synth_chan5_p */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_synth_chan5_p dtop_bypass_rif_synth_chan5_p
 * @brief Contains register fields associated with dtop_bypass_rif_synth_chan5_p. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P_MACRO__
#define __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif synth_chan5 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__SHIFT                       0
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__WIDTH                      32
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__MASK              0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WDATA__RESET_VALUE       0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__TYPE                        uint32_t
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__READ                     0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__WRITE                    0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__PRESERVED                0x00000000U
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P__RESET_VALUE              0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_P_MACRO__ */

/** @} end of dtop_bypass_rif_synth_chan5_p */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_synth_chan5_n */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_synth_chan5_n dtop_bypass_rif_synth_chan5_n
 * @brief Contains register fields associated with dtop_bypass_rif_synth_chan5_n. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N_MACRO__
#define __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif synth_chan5 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__SHIFT                       0
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__WIDTH                      32
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__MASK              0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WDATA__RESET_VALUE       0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__TYPE                        uint32_t
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__READ                     0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__WRITE                    0xffffffffU
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__PRESERVED                0x00000000U
#define SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N__RESET_VALUE              0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_SYNTH_CHAN5_N_MACRO__ */

/** @} end of dtop_bypass_rif_synth_chan5_n */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_reg4 */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_reg4 dtop_bypass_rif_reg4
 * @brief Contains register fields associated with dtop_bypass_rif_reg4. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_REG4_MACRO__
#define __SWD_DTOP_BYPASS_RIF_REG4_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details rif register 4 address.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__SHIFT                                 0
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__WIDTH                                32
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__MASK                        0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_REG4__ADDR__RESET_VALUE                 0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_REG4__TYPE                                 uint32_t
#define SWD_DTOP_BYPASS_RIF_REG4__READ                              0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4__WRITE                             0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4__PRESERVED                         0x00000000U
#define SWD_DTOP_BYPASS_RIF_REG4__RESET_VALUE                       0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_REG4_MACRO__ */

/** @} end of dtop_bypass_rif_reg4 */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_reg4_p */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_reg4_p dtop_bypass_rif_reg4_p
 * @brief Contains register fields associated with dtop_bypass_rif_reg4_p. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_REG4_P_MACRO__
#define __SWD_DTOP_BYPASS_RIF_REG4_P_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif register 4 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__SHIFT                              0
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__WIDTH                             32
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__MASK                     0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_REG4_P__WDATA__RESET_VALUE              0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_REG4_P__TYPE                               uint32_t
#define SWD_DTOP_BYPASS_RIF_REG4_P__READ                            0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4_P__WRITE                           0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4_P__PRESERVED                       0x00000000U
#define SWD_DTOP_BYPASS_RIF_REG4_P__RESET_VALUE                     0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_REG4_P_MACRO__ */

/** @} end of dtop_bypass_rif_reg4_p */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_rif_reg4_n */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_rif_reg4_n dtop_bypass_rif_reg4_n
 * @brief Contains register fields associated with dtop_bypass_rif_reg4_n. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_RIF_REG4_N_MACRO__
#define __SWD_DTOP_BYPASS_RIF_REG4_N_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_swd_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details rif register 4 write data.
 * @{
 */
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__SHIFT                              0
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__WIDTH                             32
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__MASK                     0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_RIF_REG4_N__WDATA__RESET_VALUE              0x00000000U
/** @} */
#define SWD_DTOP_BYPASS_RIF_REG4_N__TYPE                               uint32_t
#define SWD_DTOP_BYPASS_RIF_REG4_N__READ                            0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4_N__WRITE                           0xffffffffU
#define SWD_DTOP_BYPASS_RIF_REG4_N__PRESERVED                       0x00000000U
#define SWD_DTOP_BYPASS_RIF_REG4_N__RESET_VALUE                     0x00000000U

#endif /* __SWD_DTOP_BYPASS_RIF_REG4_N_MACRO__ */

/** @} end of dtop_bypass_rif_reg4_n */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_bypass_atlc_channel */
/**
 * @defgroup at_apb_swd_regs_core_dtop_bypass_atlc_channel dtop_bypass_atlc_channel
 * @brief Contains register fields associated with dtop_bypass_atlc_channel. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BYPASS_ATLC_CHANNEL_MACRO__
#define __SWD_DTOP_BYPASS_ATLC_CHANNEL_MACRO__

/* macros for field addr */
/**
 * @defgroup at_apb_swd_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details ATLC register address to set channel
 * @{
 */
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__SHIFT                             0
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__WIDTH                            32
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__MASK                    0xffffffffU
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__ADDR__RESET_VALUE             0x40120050U
/** @} */
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__TYPE                             uint32_t
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__READ                          0xffffffffU
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__WRITE                         0xffffffffU
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__PRESERVED                     0x00000000U
#define SWD_DTOP_BYPASS_ATLC_CHANNEL__RESET_VALUE                   0x40120050U

#endif /* __SWD_DTOP_BYPASS_ATLC_CHANNEL_MACRO__ */

/** @} end of dtop_bypass_atlc_channel */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_ble_st */
/**
 * @defgroup at_apb_swd_regs_core_dtop_ble_st dtop_ble_st
 * @brief Contains register fields associated with dtop_ble_st. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BLE_ST_MACRO__
#define __SWD_DTOP_BLE_ST_MACRO__

/* macros for field vl */
/**
 * @defgroup at_apb_swd_regs_core_vl_field vl_field
 * @brief macros for field vl
 * @{
 */
#define SWD_DTOP_BLE_ST__VL__SHIFT                                            0
#define SWD_DTOP_BLE_ST__VL__WIDTH                                           32
#define SWD_DTOP_BLE_ST__VL__MASK                                   0xffffffffU
#define SWD_DTOP_BLE_ST__VL__READ(src)          ((uint32_t)(src) & 0xffffffffU)
#define SWD_DTOP_BLE_ST__VL__RESET_VALUE                            0x00000000U
/** @} */
#define SWD_DTOP_BLE_ST__TYPE                                          uint32_t
#define SWD_DTOP_BLE_ST__READ                                       0xffffffffU
#define SWD_DTOP_BLE_ST__PRESERVED                                  0x00000000U
#define SWD_DTOP_BLE_ST__RESET_VALUE                                0x00000000U

#endif /* __SWD_DTOP_BLE_ST_MACRO__ */

/** @} end of dtop_ble_st */

/* macros for BlueprintGlobalNameSpace::SWD_dtop_ble_ctrl */
/**
 * @defgroup at_apb_swd_regs_core_dtop_ble_ctrl dtop_ble_ctrl
 * @brief Contains register fields associated with dtop_ble_ctrl. definitions.
 * @{
 */
#ifndef __SWD_DTOP_BLE_CTRL_MACRO__
#define __SWD_DTOP_BLE_CTRL_MACRO__

/* macros for field rstn */
/**
 * @defgroup at_apb_swd_regs_core_rstn_field rstn_field
 * @brief macros for field rstn
 * @details 0 to reset ble hw own control
 * @{
 */
#define SWD_DTOP_BLE_CTRL__RSTN__SHIFT                                        0
#define SWD_DTOP_BLE_CTRL__RSTN__WIDTH                                        1
#define SWD_DTOP_BLE_CTRL__RSTN__MASK                               0x00000001U
#define SWD_DTOP_BLE_CTRL__RSTN__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define SWD_DTOP_BLE_CTRL__RSTN__WRITE(src)     ((uint32_t)(src) & 0x00000001U)
#define SWD_DTOP_BLE_CTRL__RSTN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWD_DTOP_BLE_CTRL__RSTN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWD_DTOP_BLE_CTRL__RSTN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWD_DTOP_BLE_CTRL__RSTN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWD_DTOP_BLE_CTRL__RSTN__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field dbg_sel */
/**
 * @defgroup at_apb_swd_regs_core_dbg_sel_field dbg_sel_field
 * @brief macros for field dbg_sel
 * @details debug bus select
 * @{
 */
#define SWD_DTOP_BLE_CTRL__DBG_SEL__SHIFT                                     1
#define SWD_DTOP_BLE_CTRL__DBG_SEL__WIDTH                                     2
#define SWD_DTOP_BLE_CTRL__DBG_SEL__MASK                            0x00000006U
#define SWD_DTOP_BLE_CTRL__DBG_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000006U) >> 1)
#define SWD_DTOP_BLE_CTRL__DBG_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000006U)
#define SWD_DTOP_BLE_CTRL__DBG_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000006U) | (((uint32_t)(src) <<\
                    1) & 0x00000006U)
#define SWD_DTOP_BLE_CTRL__DBG_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000006U)))
#define SWD_DTOP_BLE_CTRL__DBG_SEL__RESET_VALUE                     0x00000000U
/** @} */
#define SWD_DTOP_BLE_CTRL__TYPE                                        uint32_t
#define SWD_DTOP_BLE_CTRL__READ                                     0x00000007U
#define SWD_DTOP_BLE_CTRL__WRITE                                    0x00000007U
#define SWD_DTOP_BLE_CTRL__PRESERVED                                0x00000000U
#define SWD_DTOP_BLE_CTRL__RESET_VALUE                              0x00000001U

#endif /* __SWD_DTOP_BLE_CTRL_MACRO__ */

/** @} end of dtop_ble_ctrl */

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
