/*                                                                           */
/* File:       at_ahb_dma_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_ahb_dma_regs_core.rdl           */
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


#ifndef __REG_AT_AHB_DMA_REGS_CORE_H__
#define __REG_AT_AHB_DMA_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_AHB_DMA_REGS_CORE at_ahb_dma_regs_core
 * @ingroup AT_REG
 * @brief at_ahb_dma_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::AT_DMA_opmode */
/**
 * @defgroup at_ahb_dma_regs_core_opmode opmode
 * @brief Contains register fields associated with opmode. definitions.
 * @{
 */
#ifndef __AT_DMA_OPMODE_MACRO__
#define __AT_DMA_OPMODE_MACRO__

/* macros for field const_trans */
/**
 * @defgroup at_ahb_dma_regs_core_const_trans_field const_trans_field
 * @brief macros for field const_trans
 * @details op code start when rising edge on 'go' is detected.
 * @{
 */
#define AT_DMA_OPMODE__CONST_TRANS__SHIFT                                     0
#define AT_DMA_OPMODE__CONST_TRANS__WIDTH                                     1
#define AT_DMA_OPMODE__CONST_TRANS__MASK                            0x00000001U
#define AT_DMA_OPMODE__CONST_TRANS__READ(src)   ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_OPMODE__CONST_TRANS__WRITE(src)  ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_OPMODE__CONST_TRANS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_OPMODE__CONST_TRANS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_OPMODE__CONST_TRANS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_OPMODE__CONST_TRANS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_OPMODE__CONST_TRANS__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field dat_inv */
/**
 * @defgroup at_ahb_dma_regs_core_dat_inv_field dat_inv_field
 * @brief macros for field dat_inv
 * @details 0= non-inverted write ; 1= inverted write (write data are bit-wise inverted)
 * @{
 */
#define AT_DMA_OPMODE__DAT_INV__SHIFT                                         1
#define AT_DMA_OPMODE__DAT_INV__WIDTH                                         1
#define AT_DMA_OPMODE__DAT_INV__MASK                                0x00000002U
#define AT_DMA_OPMODE__DAT_INV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_OPMODE__DAT_INV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_DMA_OPMODE__DAT_INV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_DMA_OPMODE__DAT_INV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_DMA_OPMODE__DAT_INV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_OPMODE__DAT_INV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_OPMODE__DAT_INV__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field const_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_tar_addr_field const_tar_addr_field
 * @brief macros for field const_tar_addr
 * @details 1= write address remains constant at tar_addr, which is required to be word-aligned in this mode.  0= write address increments as defined by the size parameter.
 * @{
 */
#define AT_DMA_OPMODE__CONST_TAR_ADDR__SHIFT                                  2
#define AT_DMA_OPMODE__CONST_TAR_ADDR__WIDTH                                  1
#define AT_DMA_OPMODE__CONST_TAR_ADDR__MASK                         0x00000004U
#define AT_DMA_OPMODE__CONST_TAR_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_OPMODE__CONST_TAR_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_DMA_OPMODE__CONST_TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_DMA_OPMODE__CONST_TAR_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_DMA_OPMODE__CONST_TAR_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_OPMODE__CONST_TAR_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_OPMODE__CONST_TAR_ADDR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field const_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_src_addr_field const_src_addr_field
 * @brief macros for field const_src_addr
 * @details 1= read address remains constant at src_addr, which is required to be word-aligned in this mode
 * @{
 */
#define AT_DMA_OPMODE__CONST_SRC_ADDR__SHIFT                                  3
#define AT_DMA_OPMODE__CONST_SRC_ADDR__WIDTH                                  1
#define AT_DMA_OPMODE__CONST_SRC_ADDR__MASK                         0x00000008U
#define AT_DMA_OPMODE__CONST_SRC_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_OPMODE__CONST_SRC_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AT_DMA_OPMODE__CONST_SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AT_DMA_OPMODE__CONST_SRC_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AT_DMA_OPMODE__CONST_SRC_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_OPMODE__CONST_SRC_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_OPMODE__CONST_SRC_ADDR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field burst_mode_n */
/**
 * @defgroup at_ahb_dma_regs_core_burst_mode_n_field burst_mode_n_field
 * @brief macros for field burst_mode_n
 * @details 0=burst mode enabled, 1=not burst mode
 * @{
 */
#define AT_DMA_OPMODE__BURST_MODE_N__SHIFT                                   29
#define AT_DMA_OPMODE__BURST_MODE_N__WIDTH                                    1
#define AT_DMA_OPMODE__BURST_MODE_N__MASK                           0x20000000U
#define AT_DMA_OPMODE__BURST_MODE_N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define AT_DMA_OPMODE__BURST_MODE_N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define AT_DMA_OPMODE__BURST_MODE_N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define AT_DMA_OPMODE__BURST_MODE_N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define AT_DMA_OPMODE__BURST_MODE_N__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define AT_DMA_OPMODE__BURST_MODE_N__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define AT_DMA_OPMODE__BURST_MODE_N__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field stop */
/**
 * @defgroup at_ahb_dma_regs_core_stop_field stop_field
 * @brief macros for field stop
 * @details to stop pending transaction . Not self clearing.
 * @{
 */
#define AT_DMA_OPMODE__STOP__SHIFT                                           30
#define AT_DMA_OPMODE__STOP__WIDTH                                            1
#define AT_DMA_OPMODE__STOP__MASK                                   0x40000000U
#define AT_DMA_OPMODE__STOP__READ(src)  (((uint32_t)(src) & 0x40000000U) >> 30)
#define AT_DMA_OPMODE__STOP__WRITE(src) (((uint32_t)(src) << 30) & 0x40000000U)
#define AT_DMA_OPMODE__STOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_DMA_OPMODE__STOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_DMA_OPMODE__STOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_DMA_OPMODE__STOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_DMA_OPMODE__STOP__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_ahb_dma_regs_core_go_field go_field
 * @brief macros for field go
 * @details op code start when rising edge on 'go' is detected. HW clears after.
 * @{
 */
#define AT_DMA_OPMODE__GO__SHIFT                                             31
#define AT_DMA_OPMODE__GO__WIDTH                                              1
#define AT_DMA_OPMODE__GO__MASK                                     0x80000000U
#define AT_DMA_OPMODE__GO__READ(src)    (((uint32_t)(src) & 0x80000000U) >> 31)
#define AT_DMA_OPMODE__GO__WRITE(src)   (((uint32_t)(src) << 31) & 0x80000000U)
#define AT_DMA_OPMODE__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_DMA_OPMODE__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_DMA_OPMODE__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_DMA_OPMODE__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_DMA_OPMODE__GO__RESET_VALUE                              0x00000000U
/** @} */
#define AT_DMA_OPMODE__TYPE                                            uint32_t
#define AT_DMA_OPMODE__READ                                         0xe000000fU
#define AT_DMA_OPMODE__WRITE                                        0xe000000fU
#define AT_DMA_OPMODE__PRESERVED                                    0x00000000U
#define AT_DMA_OPMODE__RESET_VALUE                                  0x00000000U

#endif /* __AT_DMA_OPMODE_MACRO__ */

/** @} end of opmode */

/* macros for BlueprintGlobalNameSpace::AT_DMA_const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_const_wdata const_wdata
 * @brief Contains register fields associated with const_wdata. definitions.
 * @{
 */
#ifndef __AT_DMA_CONST_WDATA_MACRO__
#define __AT_DMA_CONST_WDATA_MACRO__

/* macros for field const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_const_wdata_field const_wdata_field
 * @brief macros for field const_wdata
 * @details constant value to be written to target when the operation is in const_trans mode.
 * @{
 */
#define AT_DMA_CONST_WDATA__CONST_WDATA__SHIFT                                0
#define AT_DMA_CONST_WDATA__CONST_WDATA__WIDTH                               32
#define AT_DMA_CONST_WDATA__CONST_WDATA__MASK                       0xffffffffU
#define AT_DMA_CONST_WDATA__CONST_WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CONST_WDATA__CONST_WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CONST_WDATA__CONST_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CONST_WDATA__CONST_WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CONST_WDATA__CONST_WDATA__RESET_VALUE                0x00000000U
/** @} */
#define AT_DMA_CONST_WDATA__TYPE                                       uint32_t
#define AT_DMA_CONST_WDATA__READ                                    0xffffffffU
#define AT_DMA_CONST_WDATA__WRITE                                   0xffffffffU
#define AT_DMA_CONST_WDATA__PRESERVED                               0x00000000U
#define AT_DMA_CONST_WDATA__RESET_VALUE                             0x00000000U

#endif /* __AT_DMA_CONST_WDATA_MACRO__ */

/** @} end of const_wdata */

/* macros for BlueprintGlobalNameSpace::AT_DMA_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_src_addr src_addr
 * @brief Contains register fields associated with src_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_SRC_ADDR_MACRO__
#define __AT_DMA_SRC_ADDR_MACRO__

/* macros for field src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_src_addr_field src_addr_field
 * @brief macros for field src_addr
 * @details source address
 * @{
 */
#define AT_DMA_SRC_ADDR__SRC_ADDR__SHIFT                                      0
#define AT_DMA_SRC_ADDR__SRC_ADDR__WIDTH                                     32
#define AT_DMA_SRC_ADDR__SRC_ADDR__MASK                             0xffffffffU
#define AT_DMA_SRC_ADDR__SRC_ADDR__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_SRC_ADDR__SRC_ADDR__WRITE(src)   ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_SRC_ADDR__SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_SRC_ADDR__SRC_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_SRC_ADDR__SRC_ADDR__RESET_VALUE                      0x00000000U
/** @} */
#define AT_DMA_SRC_ADDR__TYPE                                          uint32_t
#define AT_DMA_SRC_ADDR__READ                                       0xffffffffU
#define AT_DMA_SRC_ADDR__WRITE                                      0xffffffffU
#define AT_DMA_SRC_ADDR__PRESERVED                                  0x00000000U
#define AT_DMA_SRC_ADDR__RESET_VALUE                                0x00000000U

#endif /* __AT_DMA_SRC_ADDR_MACRO__ */

/** @} end of src_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_tar_addr tar_addr
 * @brief Contains register fields associated with tar_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_TAR_ADDR_MACRO__
#define __AT_DMA_TAR_ADDR_MACRO__

/* macros for field tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_tar_addr_field tar_addr_field
 * @brief macros for field tar_addr
 * @details target address
 * @{
 */
#define AT_DMA_TAR_ADDR__TAR_ADDR__SHIFT                                      0
#define AT_DMA_TAR_ADDR__TAR_ADDR__WIDTH                                     32
#define AT_DMA_TAR_ADDR__TAR_ADDR__MASK                             0xffffffffU
#define AT_DMA_TAR_ADDR__TAR_ADDR__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_TAR_ADDR__TAR_ADDR__WRITE(src)   ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_TAR_ADDR__TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_TAR_ADDR__TAR_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_TAR_ADDR__TAR_ADDR__RESET_VALUE                      0x00000000U
/** @} */
#define AT_DMA_TAR_ADDR__TYPE                                          uint32_t
#define AT_DMA_TAR_ADDR__READ                                       0xffffffffU
#define AT_DMA_TAR_ADDR__WRITE                                      0xffffffffU
#define AT_DMA_TAR_ADDR__PRESERVED                                  0x00000000U
#define AT_DMA_TAR_ADDR__RESET_VALUE                                0x00000000U

#endif /* __AT_DMA_TAR_ADDR_MACRO__ */

/** @} end of tar_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_size */
/**
 * @defgroup at_ahb_dma_regs_core_size size
 * @brief Contains register fields associated with size. definitions.
 * @{
 */
#ifndef __AT_DMA_SIZE_MACRO__
#define __AT_DMA_SIZE_MACRO__

/* macros for field size */
/**
 * @defgroup at_ahb_dma_regs_core_size_field size_field
 * @brief macros for field size
 * @details payload size in bytes.
 * @{
 */
#define AT_DMA_SIZE__SIZE__SHIFT                                              0
#define AT_DMA_SIZE__SIZE__WIDTH                                             24
#define AT_DMA_SIZE__SIZE__MASK                                     0x00ffffffU
#define AT_DMA_SIZE__SIZE__READ(src)            ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_SIZE__SIZE__WRITE(src)           ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_SIZE__SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define AT_DMA_SIZE__SIZE__VERIFY(src)    (!(((uint32_t)(src) & ~0x00ffffffU)))
#define AT_DMA_SIZE__SIZE__RESET_VALUE                              0x00000000U
/** @} */
#define AT_DMA_SIZE__TYPE                                              uint32_t
#define AT_DMA_SIZE__READ                                           0x00ffffffU
#define AT_DMA_SIZE__WRITE                                          0x00ffffffU
#define AT_DMA_SIZE__PRESERVED                                      0x00000000U
#define AT_DMA_SIZE__RESET_VALUE                                    0x00000000U

#endif /* __AT_DMA_SIZE_MACRO__ */

/** @} end of size */

/* macros for BlueprintGlobalNameSpace::AT_DMA_src_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_src_ctrl src_ctrl
 * @brief Contains register fields associated with src_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_SRC_CTRL_MACRO__
#define __AT_DMA_SRC_CTRL_MACRO__

/* macros for field src_type */
/**
 * @defgroup at_ahb_dma_regs_core_src_type_field src_type_field
 * @brief macros for field src_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_SRC_CTRL__SRC_TYPE__SHIFT                                      0
#define AT_DMA_SRC_CTRL__SRC_TYPE__WIDTH                                      2
#define AT_DMA_SRC_CTRL__SRC_TYPE__MASK                             0x00000003U
#define AT_DMA_SRC_CTRL__SRC_TYPE__READ(src)    ((uint32_t)(src) & 0x00000003U)
#define AT_DMA_SRC_CTRL__SRC_TYPE__WRITE(src)   ((uint32_t)(src) & 0x00000003U)
#define AT_DMA_SRC_CTRL__SRC_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_SRC_CTRL__SRC_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_SRC_CTRL__SRC_TYPE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field src_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_src_bus_size_field src_bus_size_field
 * @brief macros for field src_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__SHIFT                                  2
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WIDTH                                  3
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__MASK                         0x0000001cU
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_SRC_CTRL__SRC_BUS_SIZE__RESET_VALUE                  0x00000001U
/** @} */
#define AT_DMA_SRC_CTRL__TYPE                                          uint32_t
#define AT_DMA_SRC_CTRL__READ                                       0x0000001fU
#define AT_DMA_SRC_CTRL__WRITE                                      0x0000001fU
#define AT_DMA_SRC_CTRL__PRESERVED                                  0x00000000U
#define AT_DMA_SRC_CTRL__RESET_VALUE                                0x00000004U

#endif /* __AT_DMA_SRC_CTRL_MACRO__ */

/** @} end of src_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_tar_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_tar_ctrl tar_ctrl
 * @brief Contains register fields associated with tar_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_TAR_CTRL_MACRO__
#define __AT_DMA_TAR_CTRL_MACRO__

/* macros for field tar_type */
/**
 * @defgroup at_ahb_dma_regs_core_tar_type_field tar_type_field
 * @brief macros for field tar_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_TAR_CTRL__TAR_TYPE__SHIFT                                      0
#define AT_DMA_TAR_CTRL__TAR_TYPE__WIDTH                                      2
#define AT_DMA_TAR_CTRL__TAR_TYPE__MASK                             0x00000003U
#define AT_DMA_TAR_CTRL__TAR_TYPE__READ(src)    ((uint32_t)(src) & 0x00000003U)
#define AT_DMA_TAR_CTRL__TAR_TYPE__WRITE(src)   ((uint32_t)(src) & 0x00000003U)
#define AT_DMA_TAR_CTRL__TAR_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_TAR_CTRL__TAR_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_TAR_CTRL__TAR_TYPE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field tar_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_tar_bus_size_field tar_bus_size_field
 * @brief macros for field tar_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__SHIFT                                  2
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WIDTH                                  3
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__MASK                         0x0000001cU
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_TAR_CTRL__TAR_BUS_SIZE__RESET_VALUE                  0x00000001U
/** @} */
#define AT_DMA_TAR_CTRL__TYPE                                          uint32_t
#define AT_DMA_TAR_CTRL__READ                                       0x0000001fU
#define AT_DMA_TAR_CTRL__WRITE                                      0x0000001fU
#define AT_DMA_TAR_CTRL__PRESERVED                                  0x00000000U
#define AT_DMA_TAR_CTRL__RESET_VALUE                                0x00000004U

#endif /* __AT_DMA_TAR_CTRL_MACRO__ */

/** @} end of tar_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_fifo_dpth_addr */
/**
 * @defgroup at_ahb_dma_regs_core_fifo_dpth_addr fifo_dpth_addr
 * @brief Contains register fields associated with fifo_dpth_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_FIFO_DPTH_ADDR_MACRO__
#define __AT_DMA_FIFO_DPTH_ADDR_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_dma_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details address of the external fifo depth.  Statemachine reads this to determine how many push/pull accesses to do per interrupt.
 * @{
 */
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__SHIFT                                    0
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__WIDTH                                   32
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__MASK                           0xffffffffU
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_FIFO_DPTH_ADDR__ADDR__RESET_VALUE                    0x00000000U
/** @} */
#define AT_DMA_FIFO_DPTH_ADDR__TYPE                                    uint32_t
#define AT_DMA_FIFO_DPTH_ADDR__READ                                 0xffffffffU
#define AT_DMA_FIFO_DPTH_ADDR__WRITE                                0xffffffffU
#define AT_DMA_FIFO_DPTH_ADDR__PRESERVED                            0x00000000U
#define AT_DMA_FIFO_DPTH_ADDR__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_FIFO_DPTH_ADDR_MACRO__ */

/** @} end of fifo_dpth_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_fifo_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_fifo_port_sel fifo_port_sel
 * @brief Contains register fields associated with fifo_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_FIFO_PORT_SEL_MACRO__
#define __AT_DMA_FIFO_PORT_SEL_MACRO__

/* macros for field src_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_src_port_sel_field src_port_sel_field
 * @brief macros for field src_port_sel
 * @details selecting the source fifo port;  6 = uart2 rx  5 = rsvd  4 = i2s fifo  3 = pdm1 fifo  2 = pdm0 fifo  1 = uart1 rx  0 = uart0 rx
 * @{
 */
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__SHIFT                             0
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__WIDTH                             3
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__MASK                    0x00000007U
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define AT_DMA_FIFO_PORT_SEL__SRC_PORT_SEL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field tar_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_tar_port_sel_field tar_port_sel_field
 * @brief macros for field tar_port_sel
 * @details selecting the target fifo port;  6 = uart2 tx  5 = pwd fifo  4 = i2s fifo  3 = rsvd  2 = rsvd  1 = uart1 tx  0 = uart0 tx
 * @{
 */
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__SHIFT                            16
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__WIDTH                             3
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__MASK                    0x00070000U
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define AT_DMA_FIFO_PORT_SEL__TAR_PORT_SEL__RESET_VALUE             0x00000000U
/** @} */
#define AT_DMA_FIFO_PORT_SEL__TYPE                                     uint32_t
#define AT_DMA_FIFO_PORT_SEL__READ                                  0x00070007U
#define AT_DMA_FIFO_PORT_SEL__WRITE                                 0x00070007U
#define AT_DMA_FIFO_PORT_SEL__PRESERVED                             0x00000000U
#define AT_DMA_FIFO_PORT_SEL__RESET_VALUE                           0x00000000U

#endif /* __AT_DMA_FIFO_PORT_SEL_MACRO__ */

/** @} end of fifo_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_spi_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_spi_port_sel spi_port_sel
 * @brief Contains register fields associated with spi_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_SPI_PORT_SEL_MACRO__
#define __AT_DMA_SPI_PORT_SEL_MACRO__

/* macros for field spi_sel */
/**
 * @defgroup at_ahb_dma_regs_core_spi_sel_field spi_sel_field
 * @brief macros for field spi_sel
 * @details 1=select spi1 for this channel, 0=select spi0 for this channel.
 * @{
 */
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__SHIFT                                   0
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__WIDTH                                   1
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__MASK                          0x00000001U
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__READ(src) ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_SPI_PORT_SEL__SPI_SEL__RESET_VALUE                   0x00000000U
/** @} */
#define AT_DMA_SPI_PORT_SEL__TYPE                                      uint32_t
#define AT_DMA_SPI_PORT_SEL__READ                                   0x00000001U
#define AT_DMA_SPI_PORT_SEL__WRITE                                  0x00000001U
#define AT_DMA_SPI_PORT_SEL__PRESERVED                              0x00000000U
#define AT_DMA_SPI_PORT_SEL__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_SPI_PORT_SEL_MACRO__ */

/** @} end of spi_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_err_stat */
/**
 * @defgroup at_ahb_dma_regs_core_err_stat err_stat
 * @brief The status is cleared when the err interrupt is cleared definitions.
 * @{
 */
#ifndef __AT_DMA_ERR_STAT_MACRO__
#define __AT_DMA_ERR_STAT_MACRO__

/* macros for field size_0 */
/**
 * @defgroup at_ahb_dma_regs_core_size_0_field size_0_field
 * @brief macros for field size_0
 * @details 0= size is not 0 when go is launched, 1= size is 0 when go is launched.
 * @{
 */
#define AT_DMA_ERR_STAT__SIZE_0__SHIFT                                        0
#define AT_DMA_ERR_STAT__SIZE_0__WIDTH                                        1
#define AT_DMA_ERR_STAT__SIZE_0__MASK                               0x00000001U
#define AT_DMA_ERR_STAT__SIZE_0__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_ERR_STAT__SIZE_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_ERR_STAT__SIZE_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_ERR_STAT__SIZE_0__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field addr_ovlp */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovlp_field addr_ovlp_field
 * @brief macros for field addr_ovlp
 * @details 0= no overlap between src and tar addr range, 1= there is an overlap
 * @{
 */
#define AT_DMA_ERR_STAT__ADDR_OVLP__SHIFT                                     1
#define AT_DMA_ERR_STAT__ADDR_OVLP__WIDTH                                     1
#define AT_DMA_ERR_STAT__ADDR_OVLP__MASK                            0x00000002U
#define AT_DMA_ERR_STAT__ADDR_OVLP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_ERR_STAT__ADDR_OVLP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_ERR_STAT__ADDR_OVLP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_ERR_STAT__ADDR_OVLP__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field bus_err */
/**
 * @defgroup at_ahb_dma_regs_core_bus_err_field bus_err_field
 * @brief macros for field bus_err
 * @details 0= no bus error, 1= a bus error occur during the transfer or at the launch of 'go'.
 * @{
 */
#define AT_DMA_ERR_STAT__BUS_ERR__SHIFT                                       2
#define AT_DMA_ERR_STAT__BUS_ERR__WIDTH                                       1
#define AT_DMA_ERR_STAT__BUS_ERR__MASK                              0x00000004U
#define AT_DMA_ERR_STAT__BUS_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_ERR_STAT__BUS_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_ERR_STAT__BUS_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_ERR_STAT__BUS_ERR__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field addr_ovfl */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovfl_field addr_ovfl_field
 * @brief macros for field addr_ovfl
 * @details 0= no error, 1= error due to size + src_addr/tar_addr > 32'hffff_ffff.
 * @{
 */
#define AT_DMA_ERR_STAT__ADDR_OVFL__SHIFT                                     3
#define AT_DMA_ERR_STAT__ADDR_OVFL__WIDTH                                     1
#define AT_DMA_ERR_STAT__ADDR_OVFL__MASK                            0x00000008U
#define AT_DMA_ERR_STAT__ADDR_OVFL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_ERR_STAT__ADDR_OVFL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_ERR_STAT__ADDR_OVFL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_ERR_STAT__ADDR_OVFL__RESET_VALUE                     0x00000000U
/** @} */
#define AT_DMA_ERR_STAT__TYPE                                          uint32_t
#define AT_DMA_ERR_STAT__READ                                       0x0000000fU
#define AT_DMA_ERR_STAT__PRESERVED                                  0x00000000U
#define AT_DMA_ERR_STAT__RESET_VALUE                                0x00000000U

#endif /* __AT_DMA_ERR_STAT_MACRO__ */

/** @} end of err_stat */

/* macros for BlueprintGlobalNameSpace::AT_DMA_status */
/**
 * @defgroup at_ahb_dma_regs_core_status status
 * @brief Contains register fields associated with status. definitions.
 * @{
 */
#ifndef __AT_DMA_STATUS_MACRO__
#define __AT_DMA_STATUS_MACRO__

/* macros for field running */
/**
 * @defgroup at_ahb_dma_regs_core_running_field running_field
 * @brief macros for field running
 * @details fsm is in an active state, not waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_STATUS__RUNNING__SHIFT                                         0
#define AT_DMA_STATUS__RUNNING__WIDTH                                         1
#define AT_DMA_STATUS__RUNNING__MASK                                0x00000001U
#define AT_DMA_STATUS__RUNNING__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_STATUS__RUNNING__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field busy */
/**
 * @defgroup at_ahb_dma_regs_core_busy_field busy_field
 * @brief macros for field busy
 * @details fsm is in some non-idle state including waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_STATUS__BUSY__SHIFT                                            1
#define AT_DMA_STATUS__BUSY__WIDTH                                            1
#define AT_DMA_STATUS__BUSY__MASK                                   0x00000002U
#define AT_DMA_STATUS__BUSY__READ(src)   (((uint32_t)(src) & 0x00000002U) >> 1)
#define AT_DMA_STATUS__BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_STATUS__BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_STATUS__BUSY__RESET_VALUE                            0x00000000U
/** @} */
#define AT_DMA_STATUS__TYPE                                            uint32_t
#define AT_DMA_STATUS__READ                                         0x00000003U
#define AT_DMA_STATUS__PRESERVED                                    0x00000000U
#define AT_DMA_STATUS__RESET_VALUE                                  0x00000000U

#endif /* __AT_DMA_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_total_write_remainder total_write_remainder
 * @brief Contains register fields associated with total_write_remainder. definitions.
 * @{
 */
#ifndef __AT_DMA_TOTAL_WRITE_REMAINDER_MACRO__
#define __AT_DMA_TOTAL_WRITE_REMAINDER_MACRO__

/* macros for field total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_total_write_remainder_field total_write_remainder_field
 * @brief macros for field total_write_remainder
 * @details number of bytes left to write at the time of stop
 * @{
 */
#define AT_DMA_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__SHIFT            0
#define AT_DMA_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__WIDTH           24
#define AT_DMA_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__MASK   0x00ffffffU
#define AT_DMA_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define AT_DMA_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__RESET_VALUE \
                    0x00000000U
/** @} */
#define AT_DMA_TOTAL_WRITE_REMAINDER__TYPE                             uint32_t
#define AT_DMA_TOTAL_WRITE_REMAINDER__READ                          0x00ffffffU
#define AT_DMA_TOTAL_WRITE_REMAINDER__PRESERVED                     0x00000000U
#define AT_DMA_TOTAL_WRITE_REMAINDER__RESET_VALUE                   0x00000000U

#endif /* __AT_DMA_TOTAL_WRITE_REMAINDER_MACRO__ */

/** @} end of total_write_remainder */

/* macros for BlueprintGlobalNameSpace::AT_DMA_interrupt_status */
/**
 * @defgroup at_ahb_dma_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __AT_DMA_INTERRUPT_STATUS_MACRO__
#define __AT_DMA_INTERRUPT_STATUS_MACRO__

/* macros for field dma_done */
/**
 * @defgroup at_ahb_dma_regs_core_dma_done_field dma_done_field
 * @brief macros for field dma_done
 * @details source of interrupt due to completion (chan0).
 * @{
 */
#define AT_DMA_INTERRUPT_STATUS__DMA_DONE__SHIFT                              0
#define AT_DMA_INTERRUPT_STATUS__DMA_DONE__WIDTH                              1
#define AT_DMA_INTERRUPT_STATUS__DMA_DONE__MASK                     0x00000001U
#define AT_DMA_INTERRUPT_STATUS__DMA_DONE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_INTERRUPT_STATUS__DMA_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_INTERRUPT_STATUS__DMA_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_INTERRUPT_STATUS__DMA_DONE__RESET_VALUE              0x00000000U
/** @} */

/* macros for field dma_err */
/**
 * @defgroup at_ahb_dma_regs_core_dma_err_field dma_err_field
 * @brief macros for field dma_err
 * @details source of interrupt due to an error (chan0).
 * @{
 */
#define AT_DMA_INTERRUPT_STATUS__DMA_ERR__SHIFT                               1
#define AT_DMA_INTERRUPT_STATUS__DMA_ERR__WIDTH                               1
#define AT_DMA_INTERRUPT_STATUS__DMA_ERR__MASK                      0x00000002U
#define AT_DMA_INTERRUPT_STATUS__DMA_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_INTERRUPT_STATUS__DMA_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_INTERRUPT_STATUS__DMA_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_INTERRUPT_STATUS__DMA_ERR__RESET_VALUE               0x00000000U
/** @} */
#define AT_DMA_INTERRUPT_STATUS__TYPE                                  uint32_t
#define AT_DMA_INTERRUPT_STATUS__READ                               0x00000003U
#define AT_DMA_INTERRUPT_STATUS__PRESERVED                          0x00000000U
#define AT_DMA_INTERRUPT_STATUS__RESET_VALUE                        0x00000000U

#endif /* __AT_DMA_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_interrupt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __AT_DMA_INTERRUPT_MASK_MACRO__
#define __AT_DMA_INTERRUPT_MASK_MACRO__

/* macros for field intrpt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_mask_field intrpt_mask_field
 * @brief macros for field intrpt_mask
 * @details if nth bit set, the nth interrupt is enabled
 * @{
 */
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__SHIFT                             0
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__WIDTH                             2
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__MASK                    0x00000003U
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_INTERRUPT_MASK__INTRPT_MASK__RESET_VALUE             0x00000001U
/** @} */
#define AT_DMA_INTERRUPT_MASK__TYPE                                    uint32_t
#define AT_DMA_INTERRUPT_MASK__READ                                 0x00000003U
#define AT_DMA_INTERRUPT_MASK__WRITE                                0x00000003U
#define AT_DMA_INTERRUPT_MASK__PRESERVED                            0x00000000U
#define AT_DMA_INTERRUPT_MASK__RESET_VALUE                          0x00000001U

#endif /* __AT_DMA_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::AT_DMA_set_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_set_interrupt set_interrupt
 * @brief Contains register fields associated with set_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_SET_INTERRUPT_MACRO__
#define __AT_DMA_SET_INTERRUPT_MACRO__

/* macros for field intrpt_set */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_set_field intrpt_set_field
 * @brief macros for field intrpt_set
 * @details if nth bit set, the nth interrupt is set; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__SHIFT                               0
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__WIDTH                               2
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__MASK                      0x00000003U
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_SET_INTERRUPT__INTRPT_SET__RESET_VALUE               0x00000000U
/** @} */
#define AT_DMA_SET_INTERRUPT__TYPE                                     uint32_t
#define AT_DMA_SET_INTERRUPT__READ                                  0x00000003U
#define AT_DMA_SET_INTERRUPT__WRITE                                 0x00000003U
#define AT_DMA_SET_INTERRUPT__PRESERVED                             0x00000000U
#define AT_DMA_SET_INTERRUPT__RESET_VALUE                           0x00000000U

#endif /* __AT_DMA_SET_INTERRUPT_MACRO__ */

/** @} end of set_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_reset_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_reset_interrupt reset_interrupt
 * @brief Contains register fields associated with reset_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_RESET_INTERRUPT_MACRO__
#define __AT_DMA_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details if nth bit set, the nth interrupt is reset; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__SHIFT                           0
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__WIDTH                           2
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__MASK                  0x00000003U
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE           0x00000000U
/** @} */
#define AT_DMA_RESET_INTERRUPT__TYPE                                   uint32_t
#define AT_DMA_RESET_INTERRUPT__READ                                0x00000003U
#define AT_DMA_RESET_INTERRUPT__WRITE                               0x00000003U
#define AT_DMA_RESET_INTERRUPT__PRESERVED                           0x00000000U
#define AT_DMA_RESET_INTERRUPT__RESET_VALUE                         0x00000000U

#endif /* __AT_DMA_RESET_INTERRUPT_MACRO__ */

/** @} end of reset_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_cfg_hnonsec cfg_hnonsec
 * @brief Contains register fields associated with cfg_hnonsec. definitions.
 * @{
 */
#ifndef __AT_DMA_CFG_HNONSEC_MACRO__
#define __AT_DMA_CFG_HNONSEC_MACRO__

/* macros for field cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_cfg_hnonsec_field cfg_hnonsec_field
 * @brief macros for field cfg_hnonsec
 * @details control HNONSEC output signal of this channel. This register is only Write-able by Secure program.
 * @{
 */
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__SHIFT                                0
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__WIDTH                                1
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__MASK                       0x00000001U
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CFG_HNONSEC__CFG_HNONSEC__RESET_VALUE                0x00000001U
/** @} */
#define AT_DMA_CFG_HNONSEC__TYPE                                       uint32_t
#define AT_DMA_CFG_HNONSEC__READ                                    0x00000001U
#define AT_DMA_CFG_HNONSEC__WRITE                                   0x00000001U
#define AT_DMA_CFG_HNONSEC__PRESERVED                               0x00000000U
#define AT_DMA_CFG_HNONSEC__RESET_VALUE                             0x00000001U

#endif /* __AT_DMA_CFG_HNONSEC_MACRO__ */

/** @} end of cfg_hnonsec */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_opmode */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_opmode chan1_opmode
 * @brief Contains register fields associated with chan1_opmode. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_OPMODE_MACRO__
#define __AT_DMA_CHAN1_OPMODE_MACRO__

/* macros for field const_trans */
/**
 * @defgroup at_ahb_dma_regs_core_const_trans_field const_trans_field
 * @brief macros for field const_trans
 * @details op code start when rising edge on 'go' is detected.
 * @{
 */
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__SHIFT                               0
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__WIDTH                               1
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__MASK                      0x00000001U
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN1_OPMODE__CONST_TRANS__RESET_VALUE               0x00000000U
/** @} */

/* macros for field dat_inv */
/**
 * @defgroup at_ahb_dma_regs_core_dat_inv_field dat_inv_field
 * @brief macros for field dat_inv
 * @details 0= non-inverted write ; 1= inverted write (write data are bit-wise inverted)
 * @{
 */
#define AT_DMA_CHAN1_OPMODE__DAT_INV__SHIFT                                   1
#define AT_DMA_CHAN1_OPMODE__DAT_INV__WIDTH                                   1
#define AT_DMA_CHAN1_OPMODE__DAT_INV__MASK                          0x00000002U
#define AT_DMA_CHAN1_OPMODE__DAT_INV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN1_OPMODE__DAT_INV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_DMA_CHAN1_OPMODE__DAT_INV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_DMA_CHAN1_OPMODE__DAT_INV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_DMA_CHAN1_OPMODE__DAT_INV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN1_OPMODE__DAT_INV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN1_OPMODE__DAT_INV__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field const_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_tar_addr_field const_tar_addr_field
 * @brief macros for field const_tar_addr
 * @details 1= write address remains constant at tar_addr, which is required to be word-aligned in this mode.  0= write address increments as defined by the size parameter.
 * @{
 */
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__SHIFT                            2
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__WIDTH                            1
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__MASK                   0x00000004U
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_CHAN1_OPMODE__CONST_TAR_ADDR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field const_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_src_addr_field const_src_addr_field
 * @brief macros for field const_src_addr
 * @details 1= read address remains constant at src_addr, which is required to be word-aligned in this mode
 * @{
 */
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__SHIFT                            3
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__WIDTH                            1
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__MASK                   0x00000008U
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_CHAN1_OPMODE__CONST_SRC_ADDR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field burst_mode_n */
/**
 * @defgroup at_ahb_dma_regs_core_burst_mode_n_field burst_mode_n_field
 * @brief macros for field burst_mode_n
 * @details 0=burst mode enabled, 1=not burst mode
 * @{
 */
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__SHIFT                             29
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__WIDTH                              1
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__MASK                     0x20000000U
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define AT_DMA_CHAN1_OPMODE__BURST_MODE_N__RESET_VALUE              0x00000000U
/** @} */

/* macros for field stop */
/**
 * @defgroup at_ahb_dma_regs_core_stop_field stop_field
 * @brief macros for field stop
 * @details to stop pending transaction . Not self clearing.
 * @{
 */
#define AT_DMA_CHAN1_OPMODE__STOP__SHIFT                                     30
#define AT_DMA_CHAN1_OPMODE__STOP__WIDTH                                      1
#define AT_DMA_CHAN1_OPMODE__STOP__MASK                             0x40000000U
#define AT_DMA_CHAN1_OPMODE__STOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_DMA_CHAN1_OPMODE__STOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_DMA_CHAN1_OPMODE__STOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_DMA_CHAN1_OPMODE__STOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_DMA_CHAN1_OPMODE__STOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_DMA_CHAN1_OPMODE__STOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_DMA_CHAN1_OPMODE__STOP__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_ahb_dma_regs_core_go_field go_field
 * @brief macros for field go
 * @details op code start when rising edge on 'go' is detected. HW clears after.
 * @{
 */
#define AT_DMA_CHAN1_OPMODE__GO__SHIFT                                       31
#define AT_DMA_CHAN1_OPMODE__GO__WIDTH                                        1
#define AT_DMA_CHAN1_OPMODE__GO__MASK                               0x80000000U
#define AT_DMA_CHAN1_OPMODE__GO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_DMA_CHAN1_OPMODE__GO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_DMA_CHAN1_OPMODE__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_DMA_CHAN1_OPMODE__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_DMA_CHAN1_OPMODE__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_DMA_CHAN1_OPMODE__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_DMA_CHAN1_OPMODE__GO__RESET_VALUE                        0x00000000U
/** @} */
#define AT_DMA_CHAN1_OPMODE__TYPE                                      uint32_t
#define AT_DMA_CHAN1_OPMODE__READ                                   0xe000000fU
#define AT_DMA_CHAN1_OPMODE__WRITE                                  0xe000000fU
#define AT_DMA_CHAN1_OPMODE__PRESERVED                              0x00000000U
#define AT_DMA_CHAN1_OPMODE__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_CHAN1_OPMODE_MACRO__ */

/** @} end of chan1_opmode */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_const_wdata chan1_const_wdata
 * @brief Contains register fields associated with chan1_const_wdata. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_CONST_WDATA_MACRO__
#define __AT_DMA_CHAN1_CONST_WDATA_MACRO__

/* macros for field const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_const_wdata_field const_wdata_field
 * @brief macros for field const_wdata
 * @details constant value to be written to target when the operation is in const_trans mode.
 * @{
 */
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__SHIFT                          0
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__WIDTH                         32
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__MASK                 0xffffffffU
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN1_CONST_WDATA__CONST_WDATA__RESET_VALUE          0x00000000U
/** @} */
#define AT_DMA_CHAN1_CONST_WDATA__TYPE                                 uint32_t
#define AT_DMA_CHAN1_CONST_WDATA__READ                              0xffffffffU
#define AT_DMA_CHAN1_CONST_WDATA__WRITE                             0xffffffffU
#define AT_DMA_CHAN1_CONST_WDATA__PRESERVED                         0x00000000U
#define AT_DMA_CHAN1_CONST_WDATA__RESET_VALUE                       0x00000000U

#endif /* __AT_DMA_CHAN1_CONST_WDATA_MACRO__ */

/** @} end of chan1_const_wdata */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_src_addr chan1_src_addr
 * @brief Contains register fields associated with chan1_src_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_SRC_ADDR_MACRO__
#define __AT_DMA_CHAN1_SRC_ADDR_MACRO__

/* macros for field src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_src_addr_field src_addr_field
 * @brief macros for field src_addr
 * @details source address
 * @{
 */
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__SHIFT                                0
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__WIDTH                               32
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__MASK                       0xffffffffU
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN1_SRC_ADDR__SRC_ADDR__RESET_VALUE                0x00000000U
/** @} */
#define AT_DMA_CHAN1_SRC_ADDR__TYPE                                    uint32_t
#define AT_DMA_CHAN1_SRC_ADDR__READ                                 0xffffffffU
#define AT_DMA_CHAN1_SRC_ADDR__WRITE                                0xffffffffU
#define AT_DMA_CHAN1_SRC_ADDR__PRESERVED                            0x00000000U
#define AT_DMA_CHAN1_SRC_ADDR__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN1_SRC_ADDR_MACRO__ */

/** @} end of chan1_src_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_tar_addr chan1_tar_addr
 * @brief Contains register fields associated with chan1_tar_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_TAR_ADDR_MACRO__
#define __AT_DMA_CHAN1_TAR_ADDR_MACRO__

/* macros for field tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_tar_addr_field tar_addr_field
 * @brief macros for field tar_addr
 * @details target address
 * @{
 */
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__SHIFT                                0
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__WIDTH                               32
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__MASK                       0xffffffffU
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN1_TAR_ADDR__TAR_ADDR__RESET_VALUE                0x00000000U
/** @} */
#define AT_DMA_CHAN1_TAR_ADDR__TYPE                                    uint32_t
#define AT_DMA_CHAN1_TAR_ADDR__READ                                 0xffffffffU
#define AT_DMA_CHAN1_TAR_ADDR__WRITE                                0xffffffffU
#define AT_DMA_CHAN1_TAR_ADDR__PRESERVED                            0x00000000U
#define AT_DMA_CHAN1_TAR_ADDR__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN1_TAR_ADDR_MACRO__ */

/** @} end of chan1_tar_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_size */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_size chan1_size
 * @brief Contains register fields associated with chan1_size. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_SIZE_MACRO__
#define __AT_DMA_CHAN1_SIZE_MACRO__

/* macros for field size */
/**
 * @defgroup at_ahb_dma_regs_core_size_field size_field
 * @brief macros for field size
 * @details payload size in bytes.
 * @{
 */
#define AT_DMA_CHAN1_SIZE__SIZE__SHIFT                                        0
#define AT_DMA_CHAN1_SIZE__SIZE__WIDTH                                       24
#define AT_DMA_CHAN1_SIZE__SIZE__MASK                               0x00ffffffU
#define AT_DMA_CHAN1_SIZE__SIZE__READ(src)      ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_CHAN1_SIZE__SIZE__WRITE(src)     ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_CHAN1_SIZE__SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define AT_DMA_CHAN1_SIZE__SIZE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00ffffffU)))
#define AT_DMA_CHAN1_SIZE__SIZE__RESET_VALUE                        0x00000000U
/** @} */
#define AT_DMA_CHAN1_SIZE__TYPE                                        uint32_t
#define AT_DMA_CHAN1_SIZE__READ                                     0x00ffffffU
#define AT_DMA_CHAN1_SIZE__WRITE                                    0x00ffffffU
#define AT_DMA_CHAN1_SIZE__PRESERVED                                0x00000000U
#define AT_DMA_CHAN1_SIZE__RESET_VALUE                              0x00000000U

#endif /* __AT_DMA_CHAN1_SIZE_MACRO__ */

/** @} end of chan1_size */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_src_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_src_ctrl chan1_src_ctrl
 * @brief Contains register fields associated with chan1_src_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_SRC_CTRL_MACRO__
#define __AT_DMA_CHAN1_SRC_CTRL_MACRO__

/* macros for field src_type */
/**
 * @defgroup at_ahb_dma_regs_core_src_type_field src_type_field
 * @brief macros for field src_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__SHIFT                                0
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__WIDTH                                2
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__MASK                       0x00000003U
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN1_SRC_CTRL__SRC_TYPE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field src_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_src_bus_size_field src_bus_size_field
 * @brief macros for field src_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__SHIFT                            2
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__WIDTH                            3
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__MASK                   0x0000001cU
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_CHAN1_SRC_CTRL__SRC_BUS_SIZE__RESET_VALUE            0x00000001U
/** @} */
#define AT_DMA_CHAN1_SRC_CTRL__TYPE                                    uint32_t
#define AT_DMA_CHAN1_SRC_CTRL__READ                                 0x0000001fU
#define AT_DMA_CHAN1_SRC_CTRL__WRITE                                0x0000001fU
#define AT_DMA_CHAN1_SRC_CTRL__PRESERVED                            0x00000000U
#define AT_DMA_CHAN1_SRC_CTRL__RESET_VALUE                          0x00000004U

#endif /* __AT_DMA_CHAN1_SRC_CTRL_MACRO__ */

/** @} end of chan1_src_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_tar_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_tar_ctrl chan1_tar_ctrl
 * @brief Contains register fields associated with chan1_tar_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_TAR_CTRL_MACRO__
#define __AT_DMA_CHAN1_TAR_CTRL_MACRO__

/* macros for field tar_type */
/**
 * @defgroup at_ahb_dma_regs_core_tar_type_field tar_type_field
 * @brief macros for field tar_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__SHIFT                                0
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__WIDTH                                2
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__MASK                       0x00000003U
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN1_TAR_CTRL__TAR_TYPE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field tar_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_tar_bus_size_field tar_bus_size_field
 * @brief macros for field tar_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__SHIFT                            2
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__WIDTH                            3
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__MASK                   0x0000001cU
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_CHAN1_TAR_CTRL__TAR_BUS_SIZE__RESET_VALUE            0x00000001U
/** @} */
#define AT_DMA_CHAN1_TAR_CTRL__TYPE                                    uint32_t
#define AT_DMA_CHAN1_TAR_CTRL__READ                                 0x0000001fU
#define AT_DMA_CHAN1_TAR_CTRL__WRITE                                0x0000001fU
#define AT_DMA_CHAN1_TAR_CTRL__PRESERVED                            0x00000000U
#define AT_DMA_CHAN1_TAR_CTRL__RESET_VALUE                          0x00000004U

#endif /* __AT_DMA_CHAN1_TAR_CTRL_MACRO__ */

/** @} end of chan1_tar_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_fifo_dpth_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_fifo_dpth_addr chan1_fifo_dpth_addr
 * @brief Contains register fields associated with chan1_fifo_dpth_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_FIFO_DPTH_ADDR_MACRO__
#define __AT_DMA_CHAN1_FIFO_DPTH_ADDR_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_dma_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details address of the external fifo depth.  Statemachine reads this to determine how many push/pull accesses to do per interrupt.
 * @{
 */
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__SHIFT                              0
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__WIDTH                             32
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__MASK                     0xffffffffU
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__ADDR__RESET_VALUE              0x00000000U
/** @} */
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__TYPE                              uint32_t
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__READ                           0xffffffffU
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__WRITE                          0xffffffffU
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__PRESERVED                      0x00000000U
#define AT_DMA_CHAN1_FIFO_DPTH_ADDR__RESET_VALUE                    0x00000000U

#endif /* __AT_DMA_CHAN1_FIFO_DPTH_ADDR_MACRO__ */

/** @} end of chan1_fifo_dpth_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_fifo_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_fifo_port_sel chan1_fifo_port_sel
 * @brief Contains register fields associated with chan1_fifo_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_FIFO_PORT_SEL_MACRO__
#define __AT_DMA_CHAN1_FIFO_PORT_SEL_MACRO__

/* macros for field src_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_src_port_sel_field src_port_sel_field
 * @brief macros for field src_port_sel
 * @details selecting the source fifo port;  6 = uart2 rx  5 = rsvd  4 = i2s fifo  3 = pdm1 fifo  2 = pdm0 fifo  1 = uart1 rx  0 = uart0 rx
 * @{
 */
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__SHIFT                       0
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__WIDTH                       3
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__MASK              0x00000007U
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define AT_DMA_CHAN1_FIFO_PORT_SEL__SRC_PORT_SEL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field tar_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_tar_port_sel_field tar_port_sel_field
 * @brief macros for field tar_port_sel
 * @details selecting the target fifo port;  6 = uart2 tx  5 = pwd fifo  4 = i2s fifo  3 = rsvd  2 = rsvd  1 = uart1 tx  0 = uart0 tx
 * @{
 */
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__SHIFT                      16
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__WIDTH                       3
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__MASK              0x00070000U
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TAR_PORT_SEL__RESET_VALUE       0x00000000U
/** @} */
#define AT_DMA_CHAN1_FIFO_PORT_SEL__TYPE                               uint32_t
#define AT_DMA_CHAN1_FIFO_PORT_SEL__READ                            0x00070007U
#define AT_DMA_CHAN1_FIFO_PORT_SEL__WRITE                           0x00070007U
#define AT_DMA_CHAN1_FIFO_PORT_SEL__PRESERVED                       0x00000000U
#define AT_DMA_CHAN1_FIFO_PORT_SEL__RESET_VALUE                     0x00000000U

#endif /* __AT_DMA_CHAN1_FIFO_PORT_SEL_MACRO__ */

/** @} end of chan1_fifo_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_spi_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_spi_port_sel chan1_spi_port_sel
 * @brief Contains register fields associated with chan1_spi_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_SPI_PORT_SEL_MACRO__
#define __AT_DMA_CHAN1_SPI_PORT_SEL_MACRO__

/* macros for field spi_sel */
/**
 * @defgroup at_ahb_dma_regs_core_spi_sel_field spi_sel_field
 * @brief macros for field spi_sel
 * @details 1=select spi1 for this channel, 0=select spi0 for this channel.
 * @{
 */
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__SHIFT                             0
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__WIDTH                             1
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__MASK                    0x00000001U
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN1_SPI_PORT_SEL__SPI_SEL__RESET_VALUE             0x00000000U
/** @} */
#define AT_DMA_CHAN1_SPI_PORT_SEL__TYPE                                uint32_t
#define AT_DMA_CHAN1_SPI_PORT_SEL__READ                             0x00000001U
#define AT_DMA_CHAN1_SPI_PORT_SEL__WRITE                            0x00000001U
#define AT_DMA_CHAN1_SPI_PORT_SEL__PRESERVED                        0x00000000U
#define AT_DMA_CHAN1_SPI_PORT_SEL__RESET_VALUE                      0x00000000U

#endif /* __AT_DMA_CHAN1_SPI_PORT_SEL_MACRO__ */

/** @} end of chan1_spi_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_err_stat */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_err_stat chan1_err_stat
 * @brief The status is cleared when the err interrupt is cleared definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_ERR_STAT_MACRO__
#define __AT_DMA_CHAN1_ERR_STAT_MACRO__

/* macros for field size_0 */
/**
 * @defgroup at_ahb_dma_regs_core_size_0_field size_0_field
 * @brief macros for field size_0
 * @details 0= size is not 0 when go is launched, 1= size is 0 when go is launched.
 * @{
 */
#define AT_DMA_CHAN1_ERR_STAT__SIZE_0__SHIFT                                  0
#define AT_DMA_CHAN1_ERR_STAT__SIZE_0__WIDTH                                  1
#define AT_DMA_CHAN1_ERR_STAT__SIZE_0__MASK                         0x00000001U
#define AT_DMA_CHAN1_ERR_STAT__SIZE_0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_ERR_STAT__SIZE_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN1_ERR_STAT__SIZE_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN1_ERR_STAT__SIZE_0__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field addr_ovlp */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovlp_field addr_ovlp_field
 * @brief macros for field addr_ovlp
 * @details 0= no overlap between src and tar addr range, 1= there is an overlap
 * @{
 */
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVLP__SHIFT                               1
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVLP__WIDTH                               1
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVLP__MASK                      0x00000002U
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVLP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVLP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVLP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVLP__RESET_VALUE               0x00000000U
/** @} */

/* macros for field bus_err */
/**
 * @defgroup at_ahb_dma_regs_core_bus_err_field bus_err_field
 * @brief macros for field bus_err
 * @details 0= no bus error, 1= a bus error occur during the transfer or at the launch of 'go'.
 * @{
 */
#define AT_DMA_CHAN1_ERR_STAT__BUS_ERR__SHIFT                                 2
#define AT_DMA_CHAN1_ERR_STAT__BUS_ERR__WIDTH                                 1
#define AT_DMA_CHAN1_ERR_STAT__BUS_ERR__MASK                        0x00000004U
#define AT_DMA_CHAN1_ERR_STAT__BUS_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_CHAN1_ERR_STAT__BUS_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_CHAN1_ERR_STAT__BUS_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_CHAN1_ERR_STAT__BUS_ERR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field addr_ovfl */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovfl_field addr_ovfl_field
 * @brief macros for field addr_ovfl
 * @details 0= no error, 1= error due to size + src_addr/tar_addr > 32'hffff_ffff.
 * @{
 */
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVFL__SHIFT                               3
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVFL__WIDTH                               1
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVFL__MASK                      0x00000008U
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVFL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVFL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVFL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_CHAN1_ERR_STAT__ADDR_OVFL__RESET_VALUE               0x00000000U
/** @} */
#define AT_DMA_CHAN1_ERR_STAT__TYPE                                    uint32_t
#define AT_DMA_CHAN1_ERR_STAT__READ                                 0x0000000fU
#define AT_DMA_CHAN1_ERR_STAT__PRESERVED                            0x00000000U
#define AT_DMA_CHAN1_ERR_STAT__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN1_ERR_STAT_MACRO__ */

/** @} end of chan1_err_stat */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_status */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_status chan1_status
 * @brief Contains register fields associated with chan1_status. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_STATUS_MACRO__
#define __AT_DMA_CHAN1_STATUS_MACRO__

/* macros for field running */
/**
 * @defgroup at_ahb_dma_regs_core_running_field running_field
 * @brief macros for field running
 * @details fsm is in an active state, not waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_CHAN1_STATUS__RUNNING__SHIFT                                   0
#define AT_DMA_CHAN1_STATUS__RUNNING__WIDTH                                   1
#define AT_DMA_CHAN1_STATUS__RUNNING__MASK                          0x00000001U
#define AT_DMA_CHAN1_STATUS__RUNNING__READ(src) ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_CHAN1_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN1_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN1_STATUS__RUNNING__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field busy */
/**
 * @defgroup at_ahb_dma_regs_core_busy_field busy_field
 * @brief macros for field busy
 * @details fsm is in some non-idle state including waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_CHAN1_STATUS__BUSY__SHIFT                                      1
#define AT_DMA_CHAN1_STATUS__BUSY__WIDTH                                      1
#define AT_DMA_CHAN1_STATUS__BUSY__MASK                             0x00000002U
#define AT_DMA_CHAN1_STATUS__BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN1_STATUS__BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN1_STATUS__BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN1_STATUS__BUSY__RESET_VALUE                      0x00000000U
/** @} */
#define AT_DMA_CHAN1_STATUS__TYPE                                      uint32_t
#define AT_DMA_CHAN1_STATUS__READ                                   0x00000003U
#define AT_DMA_CHAN1_STATUS__PRESERVED                              0x00000000U
#define AT_DMA_CHAN1_STATUS__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_CHAN1_STATUS_MACRO__ */

/** @} end of chan1_status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_total_write_remainder chan1_total_write_remainder
 * @brief Contains register fields associated with chan1_total_write_remainder. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER_MACRO__
#define __AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER_MACRO__

/* macros for field total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_total_write_remainder_field total_write_remainder_field
 * @brief macros for field total_write_remainder
 * @details number of bytes left to write at the time of stop
 * @{
 */
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__SHIFT      0
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__WIDTH     24
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__MASK \
                    0x00ffffffU
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__RESET_VALUE \
                    0x00000000U
/** @} */
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__TYPE                       uint32_t
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__READ                    0x00ffffffU
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__PRESERVED               0x00000000U
#define AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER__RESET_VALUE             0x00000000U

#endif /* __AT_DMA_CHAN1_TOTAL_WRITE_REMAINDER_MACRO__ */

/** @} end of chan1_total_write_remainder */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_interrupt_status */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_interrupt_status chan1_interrupt_status
 * @brief Contains register fields associated with chan1_interrupt_status. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_INTERRUPT_STATUS_MACRO__
#define __AT_DMA_CHAN1_INTERRUPT_STATUS_MACRO__

/* macros for field dma_done */
/**
 * @defgroup at_ahb_dma_regs_core_dma_done_field dma_done_field
 * @brief macros for field dma_done
 * @details source of interrupt due to completion (chan0).
 * @{
 */
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_DONE__SHIFT                        0
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_DONE__WIDTH                        1
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_DONE__MASK               0x00000001U
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_DONE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_DONE__RESET_VALUE        0x00000000U
/** @} */

/* macros for field dma_err */
/**
 * @defgroup at_ahb_dma_regs_core_dma_err_field dma_err_field
 * @brief macros for field dma_err
 * @details source of interrupt due to an error (chan0).
 * @{
 */
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__SHIFT                         1
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__WIDTH                         1
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__MASK                0x00000002U
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN1_INTERRUPT_STATUS__DMA_ERR__RESET_VALUE         0x00000000U
/** @} */
#define AT_DMA_CHAN1_INTERRUPT_STATUS__TYPE                            uint32_t
#define AT_DMA_CHAN1_INTERRUPT_STATUS__READ                         0x00000003U
#define AT_DMA_CHAN1_INTERRUPT_STATUS__PRESERVED                    0x00000000U
#define AT_DMA_CHAN1_INTERRUPT_STATUS__RESET_VALUE                  0x00000000U

#endif /* __AT_DMA_CHAN1_INTERRUPT_STATUS_MACRO__ */

/** @} end of chan1_interrupt_status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_interrupt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_interrupt_mask chan1_interrupt_mask
 * @brief Contains register fields associated with chan1_interrupt_mask. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_INTERRUPT_MASK_MACRO__
#define __AT_DMA_CHAN1_INTERRUPT_MASK_MACRO__

/* macros for field intrpt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_mask_field intrpt_mask_field
 * @brief macros for field intrpt_mask
 * @details if nth bit set, the nth interrupt is enabled
 * @{
 */
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__SHIFT                       0
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__WIDTH                       2
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__MASK              0x00000003U
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN1_INTERRUPT_MASK__INTRPT_MASK__RESET_VALUE       0x00000001U
/** @} */
#define AT_DMA_CHAN1_INTERRUPT_MASK__TYPE                              uint32_t
#define AT_DMA_CHAN1_INTERRUPT_MASK__READ                           0x00000003U
#define AT_DMA_CHAN1_INTERRUPT_MASK__WRITE                          0x00000003U
#define AT_DMA_CHAN1_INTERRUPT_MASK__PRESERVED                      0x00000000U
#define AT_DMA_CHAN1_INTERRUPT_MASK__RESET_VALUE                    0x00000001U

#endif /* __AT_DMA_CHAN1_INTERRUPT_MASK_MACRO__ */

/** @} end of chan1_interrupt_mask */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_set_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_set_interrupt chan1_set_interrupt
 * @brief Contains register fields associated with chan1_set_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_SET_INTERRUPT_MACRO__
#define __AT_DMA_CHAN1_SET_INTERRUPT_MACRO__

/* macros for field intrpt_set */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_set_field intrpt_set_field
 * @brief macros for field intrpt_set
 * @details if nth bit set, the nth interrupt is set; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__SHIFT                         0
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__WIDTH                         2
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__MASK                0x00000003U
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN1_SET_INTERRUPT__INTRPT_SET__RESET_VALUE         0x00000000U
/** @} */
#define AT_DMA_CHAN1_SET_INTERRUPT__TYPE                               uint32_t
#define AT_DMA_CHAN1_SET_INTERRUPT__READ                            0x00000003U
#define AT_DMA_CHAN1_SET_INTERRUPT__WRITE                           0x00000003U
#define AT_DMA_CHAN1_SET_INTERRUPT__PRESERVED                       0x00000000U
#define AT_DMA_CHAN1_SET_INTERRUPT__RESET_VALUE                     0x00000000U

#endif /* __AT_DMA_CHAN1_SET_INTERRUPT_MACRO__ */

/** @} end of chan1_set_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_reset_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_reset_interrupt chan1_reset_interrupt
 * @brief Contains register fields associated with chan1_reset_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_RESET_INTERRUPT_MACRO__
#define __AT_DMA_CHAN1_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details if nth bit set, the nth interrupt is reset; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__SHIFT                     0
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__WIDTH                     2
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__MASK            0x00000003U
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN1_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE     0x00000000U
/** @} */
#define AT_DMA_CHAN1_RESET_INTERRUPT__TYPE                             uint32_t
#define AT_DMA_CHAN1_RESET_INTERRUPT__READ                          0x00000003U
#define AT_DMA_CHAN1_RESET_INTERRUPT__WRITE                         0x00000003U
#define AT_DMA_CHAN1_RESET_INTERRUPT__PRESERVED                     0x00000000U
#define AT_DMA_CHAN1_RESET_INTERRUPT__RESET_VALUE                   0x00000000U

#endif /* __AT_DMA_CHAN1_RESET_INTERRUPT_MACRO__ */

/** @} end of chan1_reset_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan1_cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_chan1_cfg_hnonsec chan1_cfg_hnonsec
 * @brief Contains register fields associated with chan1_cfg_hnonsec. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN1_CFG_HNONSEC_MACRO__
#define __AT_DMA_CHAN1_CFG_HNONSEC_MACRO__

/* macros for field cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_cfg_hnonsec_field cfg_hnonsec_field
 * @brief macros for field cfg_hnonsec
 * @details control HNONSEC output signal of this channel. This register is only Write-able by Secure program.
 * @{
 */
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__SHIFT                          0
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__WIDTH                          1
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__MASK                 0x00000001U
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN1_CFG_HNONSEC__CFG_HNONSEC__RESET_VALUE          0x00000001U
/** @} */
#define AT_DMA_CHAN1_CFG_HNONSEC__TYPE                                 uint32_t
#define AT_DMA_CHAN1_CFG_HNONSEC__READ                              0x00000001U
#define AT_DMA_CHAN1_CFG_HNONSEC__WRITE                             0x00000001U
#define AT_DMA_CHAN1_CFG_HNONSEC__PRESERVED                         0x00000000U
#define AT_DMA_CHAN1_CFG_HNONSEC__RESET_VALUE                       0x00000001U

#endif /* __AT_DMA_CHAN1_CFG_HNONSEC_MACRO__ */

/** @} end of chan1_cfg_hnonsec */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_opmode */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_opmode chan2_opmode
 * @brief Contains register fields associated with chan2_opmode. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_OPMODE_MACRO__
#define __AT_DMA_CHAN2_OPMODE_MACRO__

/* macros for field const_trans */
/**
 * @defgroup at_ahb_dma_regs_core_const_trans_field const_trans_field
 * @brief macros for field const_trans
 * @details op code start when rising edge on 'go' is detected.
 * @{
 */
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__SHIFT                               0
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__WIDTH                               1
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__MASK                      0x00000001U
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN2_OPMODE__CONST_TRANS__RESET_VALUE               0x00000000U
/** @} */

/* macros for field dat_inv */
/**
 * @defgroup at_ahb_dma_regs_core_dat_inv_field dat_inv_field
 * @brief macros for field dat_inv
 * @details 0= non-inverted write ; 1= inverted write (write data are bit-wise inverted)
 * @{
 */
#define AT_DMA_CHAN2_OPMODE__DAT_INV__SHIFT                                   1
#define AT_DMA_CHAN2_OPMODE__DAT_INV__WIDTH                                   1
#define AT_DMA_CHAN2_OPMODE__DAT_INV__MASK                          0x00000002U
#define AT_DMA_CHAN2_OPMODE__DAT_INV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN2_OPMODE__DAT_INV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_DMA_CHAN2_OPMODE__DAT_INV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_DMA_CHAN2_OPMODE__DAT_INV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_DMA_CHAN2_OPMODE__DAT_INV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN2_OPMODE__DAT_INV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN2_OPMODE__DAT_INV__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field const_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_tar_addr_field const_tar_addr_field
 * @brief macros for field const_tar_addr
 * @details 1= write address remains constant at tar_addr, which is required to be word-aligned in this mode.  0= write address increments as defined by the size parameter.
 * @{
 */
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__SHIFT                            2
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__WIDTH                            1
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__MASK                   0x00000004U
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_CHAN2_OPMODE__CONST_TAR_ADDR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field const_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_src_addr_field const_src_addr_field
 * @brief macros for field const_src_addr
 * @details 1= read address remains constant at src_addr, which is required to be word-aligned in this mode
 * @{
 */
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__SHIFT                            3
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__WIDTH                            1
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__MASK                   0x00000008U
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_CHAN2_OPMODE__CONST_SRC_ADDR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field burst_mode_n */
/**
 * @defgroup at_ahb_dma_regs_core_burst_mode_n_field burst_mode_n_field
 * @brief macros for field burst_mode_n
 * @details 0=burst mode enabled, 1=not burst mode
 * @{
 */
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__SHIFT                             29
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__WIDTH                              1
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__MASK                     0x20000000U
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define AT_DMA_CHAN2_OPMODE__BURST_MODE_N__RESET_VALUE              0x00000000U
/** @} */

/* macros for field stop */
/**
 * @defgroup at_ahb_dma_regs_core_stop_field stop_field
 * @brief macros for field stop
 * @details to stop pending transaction . Not self clearing.
 * @{
 */
#define AT_DMA_CHAN2_OPMODE__STOP__SHIFT                                     30
#define AT_DMA_CHAN2_OPMODE__STOP__WIDTH                                      1
#define AT_DMA_CHAN2_OPMODE__STOP__MASK                             0x40000000U
#define AT_DMA_CHAN2_OPMODE__STOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_DMA_CHAN2_OPMODE__STOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_DMA_CHAN2_OPMODE__STOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_DMA_CHAN2_OPMODE__STOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_DMA_CHAN2_OPMODE__STOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_DMA_CHAN2_OPMODE__STOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_DMA_CHAN2_OPMODE__STOP__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_ahb_dma_regs_core_go_field go_field
 * @brief macros for field go
 * @details op code start when rising edge on 'go' is detected. HW clears after.
 * @{
 */
#define AT_DMA_CHAN2_OPMODE__GO__SHIFT                                       31
#define AT_DMA_CHAN2_OPMODE__GO__WIDTH                                        1
#define AT_DMA_CHAN2_OPMODE__GO__MASK                               0x80000000U
#define AT_DMA_CHAN2_OPMODE__GO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_DMA_CHAN2_OPMODE__GO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_DMA_CHAN2_OPMODE__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_DMA_CHAN2_OPMODE__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_DMA_CHAN2_OPMODE__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_DMA_CHAN2_OPMODE__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_DMA_CHAN2_OPMODE__GO__RESET_VALUE                        0x00000000U
/** @} */
#define AT_DMA_CHAN2_OPMODE__TYPE                                      uint32_t
#define AT_DMA_CHAN2_OPMODE__READ                                   0xe000000fU
#define AT_DMA_CHAN2_OPMODE__WRITE                                  0xe000000fU
#define AT_DMA_CHAN2_OPMODE__PRESERVED                              0x00000000U
#define AT_DMA_CHAN2_OPMODE__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_CHAN2_OPMODE_MACRO__ */

/** @} end of chan2_opmode */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_const_wdata chan2_const_wdata
 * @brief Contains register fields associated with chan2_const_wdata. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_CONST_WDATA_MACRO__
#define __AT_DMA_CHAN2_CONST_WDATA_MACRO__

/* macros for field const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_const_wdata_field const_wdata_field
 * @brief macros for field const_wdata
 * @details constant value to be written to target when the operation is in const_trans mode.
 * @{
 */
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__SHIFT                          0
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__WIDTH                         32
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__MASK                 0xffffffffU
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN2_CONST_WDATA__CONST_WDATA__RESET_VALUE          0x00000000U
/** @} */
#define AT_DMA_CHAN2_CONST_WDATA__TYPE                                 uint32_t
#define AT_DMA_CHAN2_CONST_WDATA__READ                              0xffffffffU
#define AT_DMA_CHAN2_CONST_WDATA__WRITE                             0xffffffffU
#define AT_DMA_CHAN2_CONST_WDATA__PRESERVED                         0x00000000U
#define AT_DMA_CHAN2_CONST_WDATA__RESET_VALUE                       0x00000000U

#endif /* __AT_DMA_CHAN2_CONST_WDATA_MACRO__ */

/** @} end of chan2_const_wdata */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_src_addr chan2_src_addr
 * @brief Contains register fields associated with chan2_src_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_SRC_ADDR_MACRO__
#define __AT_DMA_CHAN2_SRC_ADDR_MACRO__

/* macros for field src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_src_addr_field src_addr_field
 * @brief macros for field src_addr
 * @details source address
 * @{
 */
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__SHIFT                                0
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__WIDTH                               32
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__MASK                       0xffffffffU
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN2_SRC_ADDR__SRC_ADDR__RESET_VALUE                0x00000000U
/** @} */
#define AT_DMA_CHAN2_SRC_ADDR__TYPE                                    uint32_t
#define AT_DMA_CHAN2_SRC_ADDR__READ                                 0xffffffffU
#define AT_DMA_CHAN2_SRC_ADDR__WRITE                                0xffffffffU
#define AT_DMA_CHAN2_SRC_ADDR__PRESERVED                            0x00000000U
#define AT_DMA_CHAN2_SRC_ADDR__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN2_SRC_ADDR_MACRO__ */

/** @} end of chan2_src_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_tar_addr chan2_tar_addr
 * @brief Contains register fields associated with chan2_tar_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_TAR_ADDR_MACRO__
#define __AT_DMA_CHAN2_TAR_ADDR_MACRO__

/* macros for field tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_tar_addr_field tar_addr_field
 * @brief macros for field tar_addr
 * @details target address
 * @{
 */
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__SHIFT                                0
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__WIDTH                               32
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__MASK                       0xffffffffU
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN2_TAR_ADDR__TAR_ADDR__RESET_VALUE                0x00000000U
/** @} */
#define AT_DMA_CHAN2_TAR_ADDR__TYPE                                    uint32_t
#define AT_DMA_CHAN2_TAR_ADDR__READ                                 0xffffffffU
#define AT_DMA_CHAN2_TAR_ADDR__WRITE                                0xffffffffU
#define AT_DMA_CHAN2_TAR_ADDR__PRESERVED                            0x00000000U
#define AT_DMA_CHAN2_TAR_ADDR__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN2_TAR_ADDR_MACRO__ */

/** @} end of chan2_tar_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_size */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_size chan2_size
 * @brief Contains register fields associated with chan2_size. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_SIZE_MACRO__
#define __AT_DMA_CHAN2_SIZE_MACRO__

/* macros for field size */
/**
 * @defgroup at_ahb_dma_regs_core_size_field size_field
 * @brief macros for field size
 * @details payload size in bytes.
 * @{
 */
#define AT_DMA_CHAN2_SIZE__SIZE__SHIFT                                        0
#define AT_DMA_CHAN2_SIZE__SIZE__WIDTH                                       24
#define AT_DMA_CHAN2_SIZE__SIZE__MASK                               0x00ffffffU
#define AT_DMA_CHAN2_SIZE__SIZE__READ(src)      ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_CHAN2_SIZE__SIZE__WRITE(src)     ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_CHAN2_SIZE__SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define AT_DMA_CHAN2_SIZE__SIZE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00ffffffU)))
#define AT_DMA_CHAN2_SIZE__SIZE__RESET_VALUE                        0x00000000U
/** @} */
#define AT_DMA_CHAN2_SIZE__TYPE                                        uint32_t
#define AT_DMA_CHAN2_SIZE__READ                                     0x00ffffffU
#define AT_DMA_CHAN2_SIZE__WRITE                                    0x00ffffffU
#define AT_DMA_CHAN2_SIZE__PRESERVED                                0x00000000U
#define AT_DMA_CHAN2_SIZE__RESET_VALUE                              0x00000000U

#endif /* __AT_DMA_CHAN2_SIZE_MACRO__ */

/** @} end of chan2_size */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_src_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_src_ctrl chan2_src_ctrl
 * @brief Contains register fields associated with chan2_src_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_SRC_CTRL_MACRO__
#define __AT_DMA_CHAN2_SRC_CTRL_MACRO__

/* macros for field src_type */
/**
 * @defgroup at_ahb_dma_regs_core_src_type_field src_type_field
 * @brief macros for field src_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__SHIFT                                0
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__WIDTH                                2
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__MASK                       0x00000003U
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN2_SRC_CTRL__SRC_TYPE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field src_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_src_bus_size_field src_bus_size_field
 * @brief macros for field src_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__SHIFT                            2
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__WIDTH                            3
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__MASK                   0x0000001cU
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_CHAN2_SRC_CTRL__SRC_BUS_SIZE__RESET_VALUE            0x00000001U
/** @} */
#define AT_DMA_CHAN2_SRC_CTRL__TYPE                                    uint32_t
#define AT_DMA_CHAN2_SRC_CTRL__READ                                 0x0000001fU
#define AT_DMA_CHAN2_SRC_CTRL__WRITE                                0x0000001fU
#define AT_DMA_CHAN2_SRC_CTRL__PRESERVED                            0x00000000U
#define AT_DMA_CHAN2_SRC_CTRL__RESET_VALUE                          0x00000004U

#endif /* __AT_DMA_CHAN2_SRC_CTRL_MACRO__ */

/** @} end of chan2_src_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_tar_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_tar_ctrl chan2_tar_ctrl
 * @brief Contains register fields associated with chan2_tar_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_TAR_CTRL_MACRO__
#define __AT_DMA_CHAN2_TAR_CTRL_MACRO__

/* macros for field tar_type */
/**
 * @defgroup at_ahb_dma_regs_core_tar_type_field tar_type_field
 * @brief macros for field tar_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__SHIFT                                0
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__WIDTH                                2
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__MASK                       0x00000003U
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN2_TAR_CTRL__TAR_TYPE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field tar_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_tar_bus_size_field tar_bus_size_field
 * @brief macros for field tar_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__SHIFT                            2
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__WIDTH                            3
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__MASK                   0x0000001cU
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_CHAN2_TAR_CTRL__TAR_BUS_SIZE__RESET_VALUE            0x00000001U
/** @} */
#define AT_DMA_CHAN2_TAR_CTRL__TYPE                                    uint32_t
#define AT_DMA_CHAN2_TAR_CTRL__READ                                 0x0000001fU
#define AT_DMA_CHAN2_TAR_CTRL__WRITE                                0x0000001fU
#define AT_DMA_CHAN2_TAR_CTRL__PRESERVED                            0x00000000U
#define AT_DMA_CHAN2_TAR_CTRL__RESET_VALUE                          0x00000004U

#endif /* __AT_DMA_CHAN2_TAR_CTRL_MACRO__ */

/** @} end of chan2_tar_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_fifo_dpth_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_fifo_dpth_addr chan2_fifo_dpth_addr
 * @brief Contains register fields associated with chan2_fifo_dpth_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_FIFO_DPTH_ADDR_MACRO__
#define __AT_DMA_CHAN2_FIFO_DPTH_ADDR_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_dma_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details address of the external fifo depth.  Statemachine reads this to determine how many push/pull accesses to do per interrupt.
 * @{
 */
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__SHIFT                              0
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__WIDTH                             32
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__MASK                     0xffffffffU
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__ADDR__RESET_VALUE              0x00000000U
/** @} */
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__TYPE                              uint32_t
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__READ                           0xffffffffU
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__WRITE                          0xffffffffU
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__PRESERVED                      0x00000000U
#define AT_DMA_CHAN2_FIFO_DPTH_ADDR__RESET_VALUE                    0x00000000U

#endif /* __AT_DMA_CHAN2_FIFO_DPTH_ADDR_MACRO__ */

/** @} end of chan2_fifo_dpth_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_fifo_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_fifo_port_sel chan2_fifo_port_sel
 * @brief Contains register fields associated with chan2_fifo_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_FIFO_PORT_SEL_MACRO__
#define __AT_DMA_CHAN2_FIFO_PORT_SEL_MACRO__

/* macros for field src_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_src_port_sel_field src_port_sel_field
 * @brief macros for field src_port_sel
 * @details selecting the source fifo port;  6 = uart2 rx  5 = rsvd  4 = i2s fifo  3 = pdm1 fifo  2 = pdm0 fifo  1 = uart1 rx  0 = uart0 rx
 * @{
 */
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__SHIFT                       0
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__WIDTH                       3
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__MASK              0x00000007U
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define AT_DMA_CHAN2_FIFO_PORT_SEL__SRC_PORT_SEL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field tar_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_tar_port_sel_field tar_port_sel_field
 * @brief macros for field tar_port_sel
 * @details selecting the target fifo port;  6 = uart2 tx  5 = pwd fifo  4 = i2s fifo  3 = rsvd  2 = rsvd  1 = uart1 tx  0 = uart0 tx
 * @{
 */
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__SHIFT                      16
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__WIDTH                       3
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__MASK              0x00070000U
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TAR_PORT_SEL__RESET_VALUE       0x00000000U
/** @} */
#define AT_DMA_CHAN2_FIFO_PORT_SEL__TYPE                               uint32_t
#define AT_DMA_CHAN2_FIFO_PORT_SEL__READ                            0x00070007U
#define AT_DMA_CHAN2_FIFO_PORT_SEL__WRITE                           0x00070007U
#define AT_DMA_CHAN2_FIFO_PORT_SEL__PRESERVED                       0x00000000U
#define AT_DMA_CHAN2_FIFO_PORT_SEL__RESET_VALUE                     0x00000000U

#endif /* __AT_DMA_CHAN2_FIFO_PORT_SEL_MACRO__ */

/** @} end of chan2_fifo_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_spi_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_spi_port_sel chan2_spi_port_sel
 * @brief Contains register fields associated with chan2_spi_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_SPI_PORT_SEL_MACRO__
#define __AT_DMA_CHAN2_SPI_PORT_SEL_MACRO__

/* macros for field spi_sel */
/**
 * @defgroup at_ahb_dma_regs_core_spi_sel_field spi_sel_field
 * @brief macros for field spi_sel
 * @details 1=select spi1 for this channel, 0=select spi0 for this channel.
 * @{
 */
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__SHIFT                             0
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__WIDTH                             1
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__MASK                    0x00000001U
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN2_SPI_PORT_SEL__SPI_SEL__RESET_VALUE             0x00000000U
/** @} */
#define AT_DMA_CHAN2_SPI_PORT_SEL__TYPE                                uint32_t
#define AT_DMA_CHAN2_SPI_PORT_SEL__READ                             0x00000001U
#define AT_DMA_CHAN2_SPI_PORT_SEL__WRITE                            0x00000001U
#define AT_DMA_CHAN2_SPI_PORT_SEL__PRESERVED                        0x00000000U
#define AT_DMA_CHAN2_SPI_PORT_SEL__RESET_VALUE                      0x00000000U

#endif /* __AT_DMA_CHAN2_SPI_PORT_SEL_MACRO__ */

/** @} end of chan2_spi_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_err_stat */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_err_stat chan2_err_stat
 * @brief The status is cleared when the err interrupt is cleared definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_ERR_STAT_MACRO__
#define __AT_DMA_CHAN2_ERR_STAT_MACRO__

/* macros for field size_0 */
/**
 * @defgroup at_ahb_dma_regs_core_size_0_field size_0_field
 * @brief macros for field size_0
 * @details 0= size is not 0 when go is launched, 1= size is 0 when go is launched.
 * @{
 */
#define AT_DMA_CHAN2_ERR_STAT__SIZE_0__SHIFT                                  0
#define AT_DMA_CHAN2_ERR_STAT__SIZE_0__WIDTH                                  1
#define AT_DMA_CHAN2_ERR_STAT__SIZE_0__MASK                         0x00000001U
#define AT_DMA_CHAN2_ERR_STAT__SIZE_0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_ERR_STAT__SIZE_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN2_ERR_STAT__SIZE_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN2_ERR_STAT__SIZE_0__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field addr_ovlp */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovlp_field addr_ovlp_field
 * @brief macros for field addr_ovlp
 * @details 0= no overlap between src and tar addr range, 1= there is an overlap
 * @{
 */
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVLP__SHIFT                               1
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVLP__WIDTH                               1
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVLP__MASK                      0x00000002U
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVLP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVLP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVLP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVLP__RESET_VALUE               0x00000000U
/** @} */

/* macros for field bus_err */
/**
 * @defgroup at_ahb_dma_regs_core_bus_err_field bus_err_field
 * @brief macros for field bus_err
 * @details 0= no bus error, 1= a bus error occur during the transfer or at the launch of 'go'.
 * @{
 */
#define AT_DMA_CHAN2_ERR_STAT__BUS_ERR__SHIFT                                 2
#define AT_DMA_CHAN2_ERR_STAT__BUS_ERR__WIDTH                                 1
#define AT_DMA_CHAN2_ERR_STAT__BUS_ERR__MASK                        0x00000004U
#define AT_DMA_CHAN2_ERR_STAT__BUS_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_CHAN2_ERR_STAT__BUS_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_CHAN2_ERR_STAT__BUS_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_CHAN2_ERR_STAT__BUS_ERR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field addr_ovfl */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovfl_field addr_ovfl_field
 * @brief macros for field addr_ovfl
 * @details 0= no error, 1= error due to size + src_addr/tar_addr > 32'hffff_ffff.
 * @{
 */
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVFL__SHIFT                               3
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVFL__WIDTH                               1
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVFL__MASK                      0x00000008U
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVFL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVFL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVFL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_CHAN2_ERR_STAT__ADDR_OVFL__RESET_VALUE               0x00000000U
/** @} */
#define AT_DMA_CHAN2_ERR_STAT__TYPE                                    uint32_t
#define AT_DMA_CHAN2_ERR_STAT__READ                                 0x0000000fU
#define AT_DMA_CHAN2_ERR_STAT__PRESERVED                            0x00000000U
#define AT_DMA_CHAN2_ERR_STAT__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN2_ERR_STAT_MACRO__ */

/** @} end of chan2_err_stat */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_status */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_status chan2_status
 * @brief Contains register fields associated with chan2_status. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_STATUS_MACRO__
#define __AT_DMA_CHAN2_STATUS_MACRO__

/* macros for field running */
/**
 * @defgroup at_ahb_dma_regs_core_running_field running_field
 * @brief macros for field running
 * @details fsm is in an active state, not waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_CHAN2_STATUS__RUNNING__SHIFT                                   0
#define AT_DMA_CHAN2_STATUS__RUNNING__WIDTH                                   1
#define AT_DMA_CHAN2_STATUS__RUNNING__MASK                          0x00000001U
#define AT_DMA_CHAN2_STATUS__RUNNING__READ(src) ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_CHAN2_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN2_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN2_STATUS__RUNNING__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field busy */
/**
 * @defgroup at_ahb_dma_regs_core_busy_field busy_field
 * @brief macros for field busy
 * @details fsm is in some non-idle state including waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_CHAN2_STATUS__BUSY__SHIFT                                      1
#define AT_DMA_CHAN2_STATUS__BUSY__WIDTH                                      1
#define AT_DMA_CHAN2_STATUS__BUSY__MASK                             0x00000002U
#define AT_DMA_CHAN2_STATUS__BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN2_STATUS__BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN2_STATUS__BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN2_STATUS__BUSY__RESET_VALUE                      0x00000000U
/** @} */
#define AT_DMA_CHAN2_STATUS__TYPE                                      uint32_t
#define AT_DMA_CHAN2_STATUS__READ                                   0x00000003U
#define AT_DMA_CHAN2_STATUS__PRESERVED                              0x00000000U
#define AT_DMA_CHAN2_STATUS__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_CHAN2_STATUS_MACRO__ */

/** @} end of chan2_status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_total_write_remainder chan2_total_write_remainder
 * @brief Contains register fields associated with chan2_total_write_remainder. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER_MACRO__
#define __AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER_MACRO__

/* macros for field total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_total_write_remainder_field total_write_remainder_field
 * @brief macros for field total_write_remainder
 * @details number of bytes left to write at the time of stop
 * @{
 */
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__SHIFT      0
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__WIDTH     24
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__MASK \
                    0x00ffffffU
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__RESET_VALUE \
                    0x00000000U
/** @} */
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__TYPE                       uint32_t
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__READ                    0x00ffffffU
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__PRESERVED               0x00000000U
#define AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER__RESET_VALUE             0x00000000U

#endif /* __AT_DMA_CHAN2_TOTAL_WRITE_REMAINDER_MACRO__ */

/** @} end of chan2_total_write_remainder */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_interrupt_status */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_interrupt_status chan2_interrupt_status
 * @brief Contains register fields associated with chan2_interrupt_status. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_INTERRUPT_STATUS_MACRO__
#define __AT_DMA_CHAN2_INTERRUPT_STATUS_MACRO__

/* macros for field dma_done */
/**
 * @defgroup at_ahb_dma_regs_core_dma_done_field dma_done_field
 * @brief macros for field dma_done
 * @details source of interrupt due to completion (chan0).
 * @{
 */
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_DONE__SHIFT                        0
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_DONE__WIDTH                        1
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_DONE__MASK               0x00000001U
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_DONE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_DONE__RESET_VALUE        0x00000000U
/** @} */

/* macros for field dma_err */
/**
 * @defgroup at_ahb_dma_regs_core_dma_err_field dma_err_field
 * @brief macros for field dma_err
 * @details source of interrupt due to an error (chan0).
 * @{
 */
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__SHIFT                         1
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__WIDTH                         1
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__MASK                0x00000002U
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN2_INTERRUPT_STATUS__DMA_ERR__RESET_VALUE         0x00000000U
/** @} */
#define AT_DMA_CHAN2_INTERRUPT_STATUS__TYPE                            uint32_t
#define AT_DMA_CHAN2_INTERRUPT_STATUS__READ                         0x00000003U
#define AT_DMA_CHAN2_INTERRUPT_STATUS__PRESERVED                    0x00000000U
#define AT_DMA_CHAN2_INTERRUPT_STATUS__RESET_VALUE                  0x00000000U

#endif /* __AT_DMA_CHAN2_INTERRUPT_STATUS_MACRO__ */

/** @} end of chan2_interrupt_status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_interrupt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_interrupt_mask chan2_interrupt_mask
 * @brief Contains register fields associated with chan2_interrupt_mask. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_INTERRUPT_MASK_MACRO__
#define __AT_DMA_CHAN2_INTERRUPT_MASK_MACRO__

/* macros for field intrpt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_mask_field intrpt_mask_field
 * @brief macros for field intrpt_mask
 * @details if nth bit set, the nth interrupt is enabled
 * @{
 */
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__SHIFT                       0
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__WIDTH                       2
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__MASK              0x00000003U
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN2_INTERRUPT_MASK__INTRPT_MASK__RESET_VALUE       0x00000001U
/** @} */
#define AT_DMA_CHAN2_INTERRUPT_MASK__TYPE                              uint32_t
#define AT_DMA_CHAN2_INTERRUPT_MASK__READ                           0x00000003U
#define AT_DMA_CHAN2_INTERRUPT_MASK__WRITE                          0x00000003U
#define AT_DMA_CHAN2_INTERRUPT_MASK__PRESERVED                      0x00000000U
#define AT_DMA_CHAN2_INTERRUPT_MASK__RESET_VALUE                    0x00000001U

#endif /* __AT_DMA_CHAN2_INTERRUPT_MASK_MACRO__ */

/** @} end of chan2_interrupt_mask */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_set_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_set_interrupt chan2_set_interrupt
 * @brief Contains register fields associated with chan2_set_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_SET_INTERRUPT_MACRO__
#define __AT_DMA_CHAN2_SET_INTERRUPT_MACRO__

/* macros for field intrpt_set */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_set_field intrpt_set_field
 * @brief macros for field intrpt_set
 * @details if nth bit set, the nth interrupt is set; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__SHIFT                         0
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__WIDTH                         2
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__MASK                0x00000003U
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN2_SET_INTERRUPT__INTRPT_SET__RESET_VALUE         0x00000000U
/** @} */
#define AT_DMA_CHAN2_SET_INTERRUPT__TYPE                               uint32_t
#define AT_DMA_CHAN2_SET_INTERRUPT__READ                            0x00000003U
#define AT_DMA_CHAN2_SET_INTERRUPT__WRITE                           0x00000003U
#define AT_DMA_CHAN2_SET_INTERRUPT__PRESERVED                       0x00000000U
#define AT_DMA_CHAN2_SET_INTERRUPT__RESET_VALUE                     0x00000000U

#endif /* __AT_DMA_CHAN2_SET_INTERRUPT_MACRO__ */

/** @} end of chan2_set_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_reset_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_reset_interrupt chan2_reset_interrupt
 * @brief Contains register fields associated with chan2_reset_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_RESET_INTERRUPT_MACRO__
#define __AT_DMA_CHAN2_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details if nth bit set, the nth interrupt is reset; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__SHIFT                     0
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__WIDTH                     2
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__MASK            0x00000003U
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN2_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE     0x00000000U
/** @} */
#define AT_DMA_CHAN2_RESET_INTERRUPT__TYPE                             uint32_t
#define AT_DMA_CHAN2_RESET_INTERRUPT__READ                          0x00000003U
#define AT_DMA_CHAN2_RESET_INTERRUPT__WRITE                         0x00000003U
#define AT_DMA_CHAN2_RESET_INTERRUPT__PRESERVED                     0x00000000U
#define AT_DMA_CHAN2_RESET_INTERRUPT__RESET_VALUE                   0x00000000U

#endif /* __AT_DMA_CHAN2_RESET_INTERRUPT_MACRO__ */

/** @} end of chan2_reset_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan2_cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_chan2_cfg_hnonsec chan2_cfg_hnonsec
 * @brief Contains register fields associated with chan2_cfg_hnonsec. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN2_CFG_HNONSEC_MACRO__
#define __AT_DMA_CHAN2_CFG_HNONSEC_MACRO__

/* macros for field cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_cfg_hnonsec_field cfg_hnonsec_field
 * @brief macros for field cfg_hnonsec
 * @details control HNONSEC output signal of this channel. This register is only Write-able by Secure program.
 * @{
 */
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__SHIFT                          0
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__WIDTH                          1
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__MASK                 0x00000001U
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN2_CFG_HNONSEC__CFG_HNONSEC__RESET_VALUE          0x00000001U
/** @} */
#define AT_DMA_CHAN2_CFG_HNONSEC__TYPE                                 uint32_t
#define AT_DMA_CHAN2_CFG_HNONSEC__READ                              0x00000001U
#define AT_DMA_CHAN2_CFG_HNONSEC__WRITE                             0x00000001U
#define AT_DMA_CHAN2_CFG_HNONSEC__PRESERVED                         0x00000000U
#define AT_DMA_CHAN2_CFG_HNONSEC__RESET_VALUE                       0x00000001U

#endif /* __AT_DMA_CHAN2_CFG_HNONSEC_MACRO__ */

/** @} end of chan2_cfg_hnonsec */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_opmode */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_opmode chan3_opmode
 * @brief Contains register fields associated with chan3_opmode. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_OPMODE_MACRO__
#define __AT_DMA_CHAN3_OPMODE_MACRO__

/* macros for field const_trans */
/**
 * @defgroup at_ahb_dma_regs_core_const_trans_field const_trans_field
 * @brief macros for field const_trans
 * @details op code start when rising edge on 'go' is detected.
 * @{
 */
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__SHIFT                               0
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__WIDTH                               1
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__MASK                      0x00000001U
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN3_OPMODE__CONST_TRANS__RESET_VALUE               0x00000000U
/** @} */

/* macros for field dat_inv */
/**
 * @defgroup at_ahb_dma_regs_core_dat_inv_field dat_inv_field
 * @brief macros for field dat_inv
 * @details 0= non-inverted write ; 1= inverted write (write data are bit-wise inverted)
 * @{
 */
#define AT_DMA_CHAN3_OPMODE__DAT_INV__SHIFT                                   1
#define AT_DMA_CHAN3_OPMODE__DAT_INV__WIDTH                                   1
#define AT_DMA_CHAN3_OPMODE__DAT_INV__MASK                          0x00000002U
#define AT_DMA_CHAN3_OPMODE__DAT_INV__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN3_OPMODE__DAT_INV__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_DMA_CHAN3_OPMODE__DAT_INV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_DMA_CHAN3_OPMODE__DAT_INV__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_DMA_CHAN3_OPMODE__DAT_INV__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN3_OPMODE__DAT_INV__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN3_OPMODE__DAT_INV__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field const_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_tar_addr_field const_tar_addr_field
 * @brief macros for field const_tar_addr
 * @details 1= write address remains constant at tar_addr, which is required to be word-aligned in this mode.  0= write address increments as defined by the size parameter.
 * @{
 */
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__SHIFT                            2
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__WIDTH                            1
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__MASK                   0x00000004U
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_CHAN3_OPMODE__CONST_TAR_ADDR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field const_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_const_src_addr_field const_src_addr_field
 * @brief macros for field const_src_addr
 * @details 1= read address remains constant at src_addr, which is required to be word-aligned in this mode
 * @{
 */
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__SHIFT                            3
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__WIDTH                            1
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__MASK                   0x00000008U
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_CHAN3_OPMODE__CONST_SRC_ADDR__RESET_VALUE            0x00000000U
/** @} */

/* macros for field burst_mode_n */
/**
 * @defgroup at_ahb_dma_regs_core_burst_mode_n_field burst_mode_n_field
 * @brief macros for field burst_mode_n
 * @details 0=burst mode enabled, 1=not burst mode
 * @{
 */
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__SHIFT                             29
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__WIDTH                              1
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__MASK                     0x20000000U
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define AT_DMA_CHAN3_OPMODE__BURST_MODE_N__RESET_VALUE              0x00000000U
/** @} */

/* macros for field stop */
/**
 * @defgroup at_ahb_dma_regs_core_stop_field stop_field
 * @brief macros for field stop
 * @details to stop pending transaction . Not self clearing.
 * @{
 */
#define AT_DMA_CHAN3_OPMODE__STOP__SHIFT                                     30
#define AT_DMA_CHAN3_OPMODE__STOP__WIDTH                                      1
#define AT_DMA_CHAN3_OPMODE__STOP__MASK                             0x40000000U
#define AT_DMA_CHAN3_OPMODE__STOP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define AT_DMA_CHAN3_OPMODE__STOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define AT_DMA_CHAN3_OPMODE__STOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define AT_DMA_CHAN3_OPMODE__STOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define AT_DMA_CHAN3_OPMODE__STOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define AT_DMA_CHAN3_OPMODE__STOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define AT_DMA_CHAN3_OPMODE__STOP__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_ahb_dma_regs_core_go_field go_field
 * @brief macros for field go
 * @details op code start when rising edge on 'go' is detected. HW clears after.
 * @{
 */
#define AT_DMA_CHAN3_OPMODE__GO__SHIFT                                       31
#define AT_DMA_CHAN3_OPMODE__GO__WIDTH                                        1
#define AT_DMA_CHAN3_OPMODE__GO__MASK                               0x80000000U
#define AT_DMA_CHAN3_OPMODE__GO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define AT_DMA_CHAN3_OPMODE__GO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define AT_DMA_CHAN3_OPMODE__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define AT_DMA_CHAN3_OPMODE__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define AT_DMA_CHAN3_OPMODE__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define AT_DMA_CHAN3_OPMODE__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define AT_DMA_CHAN3_OPMODE__GO__RESET_VALUE                        0x00000000U
/** @} */
#define AT_DMA_CHAN3_OPMODE__TYPE                                      uint32_t
#define AT_DMA_CHAN3_OPMODE__READ                                   0xe000000fU
#define AT_DMA_CHAN3_OPMODE__WRITE                                  0xe000000fU
#define AT_DMA_CHAN3_OPMODE__PRESERVED                              0x00000000U
#define AT_DMA_CHAN3_OPMODE__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_CHAN3_OPMODE_MACRO__ */

/** @} end of chan3_opmode */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_const_wdata chan3_const_wdata
 * @brief Contains register fields associated with chan3_const_wdata. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_CONST_WDATA_MACRO__
#define __AT_DMA_CHAN3_CONST_WDATA_MACRO__

/* macros for field const_wdata */
/**
 * @defgroup at_ahb_dma_regs_core_const_wdata_field const_wdata_field
 * @brief macros for field const_wdata
 * @details constant value to be written to target when the operation is in const_trans mode.
 * @{
 */
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__SHIFT                          0
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__WIDTH                         32
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__MASK                 0xffffffffU
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN3_CONST_WDATA__CONST_WDATA__RESET_VALUE          0x00000000U
/** @} */
#define AT_DMA_CHAN3_CONST_WDATA__TYPE                                 uint32_t
#define AT_DMA_CHAN3_CONST_WDATA__READ                              0xffffffffU
#define AT_DMA_CHAN3_CONST_WDATA__WRITE                             0xffffffffU
#define AT_DMA_CHAN3_CONST_WDATA__PRESERVED                         0x00000000U
#define AT_DMA_CHAN3_CONST_WDATA__RESET_VALUE                       0x00000000U

#endif /* __AT_DMA_CHAN3_CONST_WDATA_MACRO__ */

/** @} end of chan3_const_wdata */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_src_addr chan3_src_addr
 * @brief Contains register fields associated with chan3_src_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_SRC_ADDR_MACRO__
#define __AT_DMA_CHAN3_SRC_ADDR_MACRO__

/* macros for field src_addr */
/**
 * @defgroup at_ahb_dma_regs_core_src_addr_field src_addr_field
 * @brief macros for field src_addr
 * @details source address
 * @{
 */
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__SHIFT                                0
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__WIDTH                               32
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__MASK                       0xffffffffU
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN3_SRC_ADDR__SRC_ADDR__RESET_VALUE                0x00000000U
/** @} */
#define AT_DMA_CHAN3_SRC_ADDR__TYPE                                    uint32_t
#define AT_DMA_CHAN3_SRC_ADDR__READ                                 0xffffffffU
#define AT_DMA_CHAN3_SRC_ADDR__WRITE                                0xffffffffU
#define AT_DMA_CHAN3_SRC_ADDR__PRESERVED                            0x00000000U
#define AT_DMA_CHAN3_SRC_ADDR__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN3_SRC_ADDR_MACRO__ */

/** @} end of chan3_src_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_tar_addr chan3_tar_addr
 * @brief Contains register fields associated with chan3_tar_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_TAR_ADDR_MACRO__
#define __AT_DMA_CHAN3_TAR_ADDR_MACRO__

/* macros for field tar_addr */
/**
 * @defgroup at_ahb_dma_regs_core_tar_addr_field tar_addr_field
 * @brief macros for field tar_addr
 * @details target address
 * @{
 */
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__SHIFT                                0
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__WIDTH                               32
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__MASK                       0xffffffffU
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN3_TAR_ADDR__TAR_ADDR__RESET_VALUE                0x00000000U
/** @} */
#define AT_DMA_CHAN3_TAR_ADDR__TYPE                                    uint32_t
#define AT_DMA_CHAN3_TAR_ADDR__READ                                 0xffffffffU
#define AT_DMA_CHAN3_TAR_ADDR__WRITE                                0xffffffffU
#define AT_DMA_CHAN3_TAR_ADDR__PRESERVED                            0x00000000U
#define AT_DMA_CHAN3_TAR_ADDR__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN3_TAR_ADDR_MACRO__ */

/** @} end of chan3_tar_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_size */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_size chan3_size
 * @brief Contains register fields associated with chan3_size. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_SIZE_MACRO__
#define __AT_DMA_CHAN3_SIZE_MACRO__

/* macros for field size */
/**
 * @defgroup at_ahb_dma_regs_core_size_field size_field
 * @brief macros for field size
 * @details payload size in bytes.
 * @{
 */
#define AT_DMA_CHAN3_SIZE__SIZE__SHIFT                                        0
#define AT_DMA_CHAN3_SIZE__SIZE__WIDTH                                       24
#define AT_DMA_CHAN3_SIZE__SIZE__MASK                               0x00ffffffU
#define AT_DMA_CHAN3_SIZE__SIZE__READ(src)      ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_CHAN3_SIZE__SIZE__WRITE(src)     ((uint32_t)(src) & 0x00ffffffU)
#define AT_DMA_CHAN3_SIZE__SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define AT_DMA_CHAN3_SIZE__SIZE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00ffffffU)))
#define AT_DMA_CHAN3_SIZE__SIZE__RESET_VALUE                        0x00000000U
/** @} */
#define AT_DMA_CHAN3_SIZE__TYPE                                        uint32_t
#define AT_DMA_CHAN3_SIZE__READ                                     0x00ffffffU
#define AT_DMA_CHAN3_SIZE__WRITE                                    0x00ffffffU
#define AT_DMA_CHAN3_SIZE__PRESERVED                                0x00000000U
#define AT_DMA_CHAN3_SIZE__RESET_VALUE                              0x00000000U

#endif /* __AT_DMA_CHAN3_SIZE_MACRO__ */

/** @} end of chan3_size */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_src_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_src_ctrl chan3_src_ctrl
 * @brief Contains register fields associated with chan3_src_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_SRC_CTRL_MACRO__
#define __AT_DMA_CHAN3_SRC_CTRL_MACRO__

/* macros for field src_type */
/**
 * @defgroup at_ahb_dma_regs_core_src_type_field src_type_field
 * @brief macros for field src_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__SHIFT                                0
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__WIDTH                                2
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__MASK                       0x00000003U
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN3_SRC_CTRL__SRC_TYPE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field src_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_src_bus_size_field src_bus_size_field
 * @brief macros for field src_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__SHIFT                            2
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__WIDTH                            3
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__MASK                   0x0000001cU
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_CHAN3_SRC_CTRL__SRC_BUS_SIZE__RESET_VALUE            0x00000001U
/** @} */
#define AT_DMA_CHAN3_SRC_CTRL__TYPE                                    uint32_t
#define AT_DMA_CHAN3_SRC_CTRL__READ                                 0x0000001fU
#define AT_DMA_CHAN3_SRC_CTRL__WRITE                                0x0000001fU
#define AT_DMA_CHAN3_SRC_CTRL__PRESERVED                            0x00000000U
#define AT_DMA_CHAN3_SRC_CTRL__RESET_VALUE                          0x00000004U

#endif /* __AT_DMA_CHAN3_SRC_CTRL_MACRO__ */

/** @} end of chan3_src_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_tar_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_tar_ctrl chan3_tar_ctrl
 * @brief Contains register fields associated with chan3_tar_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_TAR_CTRL_MACRO__
#define __AT_DMA_CHAN3_TAR_CTRL_MACRO__

/* macros for field tar_type */
/**
 * @defgroup at_ahb_dma_regs_core_tar_type_field tar_type_field
 * @brief macros for field tar_type
 * @details 0=mem, 1=fifo, 2=periph master, 3=periph slave
 * @{
 */
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__SHIFT                                0
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__WIDTH                                2
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__MASK                       0x00000003U
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN3_TAR_CTRL__TAR_TYPE__RESET_VALUE                0x00000000U
/** @} */

/* macros for field tar_bus_size */
/**
 * @defgroup at_ahb_dma_regs_core_tar_bus_size_field tar_bus_size_field
 * @brief macros for field tar_bus_size
 * @details the width of fifo. one byte to 4 bytes.
 * @{
 */
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__SHIFT                            2
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__WIDTH                            3
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__MASK                   0x0000001cU
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define AT_DMA_CHAN3_TAR_CTRL__TAR_BUS_SIZE__RESET_VALUE            0x00000001U
/** @} */
#define AT_DMA_CHAN3_TAR_CTRL__TYPE                                    uint32_t
#define AT_DMA_CHAN3_TAR_CTRL__READ                                 0x0000001fU
#define AT_DMA_CHAN3_TAR_CTRL__WRITE                                0x0000001fU
#define AT_DMA_CHAN3_TAR_CTRL__PRESERVED                            0x00000000U
#define AT_DMA_CHAN3_TAR_CTRL__RESET_VALUE                          0x00000004U

#endif /* __AT_DMA_CHAN3_TAR_CTRL_MACRO__ */

/** @} end of chan3_tar_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_fifo_dpth_addr */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_fifo_dpth_addr chan3_fifo_dpth_addr
 * @brief Contains register fields associated with chan3_fifo_dpth_addr. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_FIFO_DPTH_ADDR_MACRO__
#define __AT_DMA_CHAN3_FIFO_DPTH_ADDR_MACRO__

/* macros for field addr */
/**
 * @defgroup at_ahb_dma_regs_core_addr_field addr_field
 * @brief macros for field addr
 * @details address of the external fifo depth.  Statemachine reads this to determine how many push/pull accesses to do per interrupt.
 * @{
 */
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__SHIFT                              0
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__WIDTH                             32
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__MASK                     0xffffffffU
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__ADDR__RESET_VALUE              0x00000000U
/** @} */
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__TYPE                              uint32_t
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__READ                           0xffffffffU
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__WRITE                          0xffffffffU
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__PRESERVED                      0x00000000U
#define AT_DMA_CHAN3_FIFO_DPTH_ADDR__RESET_VALUE                    0x00000000U

#endif /* __AT_DMA_CHAN3_FIFO_DPTH_ADDR_MACRO__ */

/** @} end of chan3_fifo_dpth_addr */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_fifo_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_fifo_port_sel chan3_fifo_port_sel
 * @brief Contains register fields associated with chan3_fifo_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_FIFO_PORT_SEL_MACRO__
#define __AT_DMA_CHAN3_FIFO_PORT_SEL_MACRO__

/* macros for field src_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_src_port_sel_field src_port_sel_field
 * @brief macros for field src_port_sel
 * @details selecting the source fifo port;  6 = uart2 rx  5 = rsvd  4 = i2s fifo  3 = pdm1 fifo  2 = pdm0 fifo  1 = uart1 rx  0 = uart0 rx
 * @{
 */
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__SHIFT                       0
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__WIDTH                       3
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__MASK              0x00000007U
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define AT_DMA_CHAN3_FIFO_PORT_SEL__SRC_PORT_SEL__RESET_VALUE       0x00000000U
/** @} */

/* macros for field tar_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_tar_port_sel_field tar_port_sel_field
 * @brief macros for field tar_port_sel
 * @details selecting the target fifo port;  6 = uart2 tx  5 = pwd fifo  4 = i2s fifo  3 = rsvd  2 = rsvd  1 = uart1 tx  0 = uart0 tx
 * @{
 */
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__SHIFT                      16
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__WIDTH                       3
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__MASK              0x00070000U
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TAR_PORT_SEL__RESET_VALUE       0x00000000U
/** @} */
#define AT_DMA_CHAN3_FIFO_PORT_SEL__TYPE                               uint32_t
#define AT_DMA_CHAN3_FIFO_PORT_SEL__READ                            0x00070007U
#define AT_DMA_CHAN3_FIFO_PORT_SEL__WRITE                           0x00070007U
#define AT_DMA_CHAN3_FIFO_PORT_SEL__PRESERVED                       0x00000000U
#define AT_DMA_CHAN3_FIFO_PORT_SEL__RESET_VALUE                     0x00000000U

#endif /* __AT_DMA_CHAN3_FIFO_PORT_SEL_MACRO__ */

/** @} end of chan3_fifo_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_spi_port_sel */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_spi_port_sel chan3_spi_port_sel
 * @brief Contains register fields associated with chan3_spi_port_sel. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_SPI_PORT_SEL_MACRO__
#define __AT_DMA_CHAN3_SPI_PORT_SEL_MACRO__

/* macros for field spi_sel */
/**
 * @defgroup at_ahb_dma_regs_core_spi_sel_field spi_sel_field
 * @brief macros for field spi_sel
 * @details 1=select spi1 for this channel, 0=select spi0 for this channel.
 * @{
 */
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__SHIFT                             0
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__WIDTH                             1
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__MASK                    0x00000001U
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN3_SPI_PORT_SEL__SPI_SEL__RESET_VALUE             0x00000000U
/** @} */
#define AT_DMA_CHAN3_SPI_PORT_SEL__TYPE                                uint32_t
#define AT_DMA_CHAN3_SPI_PORT_SEL__READ                             0x00000001U
#define AT_DMA_CHAN3_SPI_PORT_SEL__WRITE                            0x00000001U
#define AT_DMA_CHAN3_SPI_PORT_SEL__PRESERVED                        0x00000000U
#define AT_DMA_CHAN3_SPI_PORT_SEL__RESET_VALUE                      0x00000000U

#endif /* __AT_DMA_CHAN3_SPI_PORT_SEL_MACRO__ */

/** @} end of chan3_spi_port_sel */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_err_stat */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_err_stat chan3_err_stat
 * @brief The status is cleared when the err interrupt is cleared definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_ERR_STAT_MACRO__
#define __AT_DMA_CHAN3_ERR_STAT_MACRO__

/* macros for field size_0 */
/**
 * @defgroup at_ahb_dma_regs_core_size_0_field size_0_field
 * @brief macros for field size_0
 * @details 0= size is not 0 when go is launched, 1= size is 0 when go is launched.
 * @{
 */
#define AT_DMA_CHAN3_ERR_STAT__SIZE_0__SHIFT                                  0
#define AT_DMA_CHAN3_ERR_STAT__SIZE_0__WIDTH                                  1
#define AT_DMA_CHAN3_ERR_STAT__SIZE_0__MASK                         0x00000001U
#define AT_DMA_CHAN3_ERR_STAT__SIZE_0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_ERR_STAT__SIZE_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN3_ERR_STAT__SIZE_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN3_ERR_STAT__SIZE_0__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field addr_ovlp */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovlp_field addr_ovlp_field
 * @brief macros for field addr_ovlp
 * @details 0= no overlap between src and tar addr range, 1= there is an overlap
 * @{
 */
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVLP__SHIFT                               1
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVLP__WIDTH                               1
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVLP__MASK                      0x00000002U
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVLP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVLP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVLP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVLP__RESET_VALUE               0x00000000U
/** @} */

/* macros for field bus_err */
/**
 * @defgroup at_ahb_dma_regs_core_bus_err_field bus_err_field
 * @brief macros for field bus_err
 * @details 0= no bus error, 1= a bus error occur during the transfer or at the launch of 'go'.
 * @{
 */
#define AT_DMA_CHAN3_ERR_STAT__BUS_ERR__SHIFT                                 2
#define AT_DMA_CHAN3_ERR_STAT__BUS_ERR__WIDTH                                 1
#define AT_DMA_CHAN3_ERR_STAT__BUS_ERR__MASK                        0x00000004U
#define AT_DMA_CHAN3_ERR_STAT__BUS_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define AT_DMA_CHAN3_ERR_STAT__BUS_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define AT_DMA_CHAN3_ERR_STAT__BUS_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define AT_DMA_CHAN3_ERR_STAT__BUS_ERR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field addr_ovfl */
/**
 * @defgroup at_ahb_dma_regs_core_addr_ovfl_field addr_ovfl_field
 * @brief macros for field addr_ovfl
 * @details 0= no error, 1= error due to size + src_addr/tar_addr > 32'hffff_ffff.
 * @{
 */
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVFL__SHIFT                               3
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVFL__WIDTH                               1
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVFL__MASK                      0x00000008U
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVFL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVFL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVFL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define AT_DMA_CHAN3_ERR_STAT__ADDR_OVFL__RESET_VALUE               0x00000000U
/** @} */
#define AT_DMA_CHAN3_ERR_STAT__TYPE                                    uint32_t
#define AT_DMA_CHAN3_ERR_STAT__READ                                 0x0000000fU
#define AT_DMA_CHAN3_ERR_STAT__PRESERVED                            0x00000000U
#define AT_DMA_CHAN3_ERR_STAT__RESET_VALUE                          0x00000000U

#endif /* __AT_DMA_CHAN3_ERR_STAT_MACRO__ */

/** @} end of chan3_err_stat */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_status */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_status chan3_status
 * @brief Contains register fields associated with chan3_status. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_STATUS_MACRO__
#define __AT_DMA_CHAN3_STATUS_MACRO__

/* macros for field running */
/**
 * @defgroup at_ahb_dma_regs_core_running_field running_field
 * @brief macros for field running
 * @details fsm is in an active state, not waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_CHAN3_STATUS__RUNNING__SHIFT                                   0
#define AT_DMA_CHAN3_STATUS__RUNNING__WIDTH                                   1
#define AT_DMA_CHAN3_STATUS__RUNNING__MASK                          0x00000001U
#define AT_DMA_CHAN3_STATUS__RUNNING__READ(src) ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_CHAN3_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN3_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN3_STATUS__RUNNING__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field busy */
/**
 * @defgroup at_ahb_dma_regs_core_busy_field busy_field
 * @brief macros for field busy
 * @details fsm is in some non-idle state including waiting for the bus or an interrupt.
 * @{
 */
#define AT_DMA_CHAN3_STATUS__BUSY__SHIFT                                      1
#define AT_DMA_CHAN3_STATUS__BUSY__WIDTH                                      1
#define AT_DMA_CHAN3_STATUS__BUSY__MASK                             0x00000002U
#define AT_DMA_CHAN3_STATUS__BUSY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN3_STATUS__BUSY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN3_STATUS__BUSY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN3_STATUS__BUSY__RESET_VALUE                      0x00000000U
/** @} */
#define AT_DMA_CHAN3_STATUS__TYPE                                      uint32_t
#define AT_DMA_CHAN3_STATUS__READ                                   0x00000003U
#define AT_DMA_CHAN3_STATUS__PRESERVED                              0x00000000U
#define AT_DMA_CHAN3_STATUS__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_CHAN3_STATUS_MACRO__ */

/** @} end of chan3_status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_total_write_remainder chan3_total_write_remainder
 * @brief Contains register fields associated with chan3_total_write_remainder. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER_MACRO__
#define __AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER_MACRO__

/* macros for field total_write_remainder */
/**
 * @defgroup at_ahb_dma_regs_core_total_write_remainder_field total_write_remainder_field
 * @brief macros for field total_write_remainder
 * @details number of bytes left to write at the time of stop
 * @{
 */
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__SHIFT      0
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__WIDTH     24
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__MASK \
                    0x00ffffffU
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__TOTAL_WRITE_REMAINDER__RESET_VALUE \
                    0x00000000U
/** @} */
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__TYPE                       uint32_t
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__READ                    0x00ffffffU
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__PRESERVED               0x00000000U
#define AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER__RESET_VALUE             0x00000000U

#endif /* __AT_DMA_CHAN3_TOTAL_WRITE_REMAINDER_MACRO__ */

/** @} end of chan3_total_write_remainder */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_interrupt_status */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_interrupt_status chan3_interrupt_status
 * @brief Contains register fields associated with chan3_interrupt_status. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_INTERRUPT_STATUS_MACRO__
#define __AT_DMA_CHAN3_INTERRUPT_STATUS_MACRO__

/* macros for field dma_done */
/**
 * @defgroup at_ahb_dma_regs_core_dma_done_field dma_done_field
 * @brief macros for field dma_done
 * @details source of interrupt due to completion (chan0).
 * @{
 */
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_DONE__SHIFT                        0
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_DONE__WIDTH                        1
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_DONE__MASK               0x00000001U
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_DONE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_DONE__RESET_VALUE        0x00000000U
/** @} */

/* macros for field dma_err */
/**
 * @defgroup at_ahb_dma_regs_core_dma_err_field dma_err_field
 * @brief macros for field dma_err
 * @details source of interrupt due to an error (chan0).
 * @{
 */
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__SHIFT                         1
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__WIDTH                         1
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__MASK                0x00000002U
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CHAN3_INTERRUPT_STATUS__DMA_ERR__RESET_VALUE         0x00000000U
/** @} */
#define AT_DMA_CHAN3_INTERRUPT_STATUS__TYPE                            uint32_t
#define AT_DMA_CHAN3_INTERRUPT_STATUS__READ                         0x00000003U
#define AT_DMA_CHAN3_INTERRUPT_STATUS__PRESERVED                    0x00000000U
#define AT_DMA_CHAN3_INTERRUPT_STATUS__RESET_VALUE                  0x00000000U

#endif /* __AT_DMA_CHAN3_INTERRUPT_STATUS_MACRO__ */

/** @} end of chan3_interrupt_status */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_interrupt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_interrupt_mask chan3_interrupt_mask
 * @brief Contains register fields associated with chan3_interrupt_mask. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_INTERRUPT_MASK_MACRO__
#define __AT_DMA_CHAN3_INTERRUPT_MASK_MACRO__

/* macros for field intrpt_mask */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_mask_field intrpt_mask_field
 * @brief macros for field intrpt_mask
 * @details if nth bit set, the nth interrupt is enabled
 * @{
 */
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__SHIFT                       0
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__WIDTH                       2
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__MASK              0x00000003U
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN3_INTERRUPT_MASK__INTRPT_MASK__RESET_VALUE       0x00000001U
/** @} */
#define AT_DMA_CHAN3_INTERRUPT_MASK__TYPE                              uint32_t
#define AT_DMA_CHAN3_INTERRUPT_MASK__READ                           0x00000003U
#define AT_DMA_CHAN3_INTERRUPT_MASK__WRITE                          0x00000003U
#define AT_DMA_CHAN3_INTERRUPT_MASK__PRESERVED                      0x00000000U
#define AT_DMA_CHAN3_INTERRUPT_MASK__RESET_VALUE                    0x00000001U

#endif /* __AT_DMA_CHAN3_INTERRUPT_MASK_MACRO__ */

/** @} end of chan3_interrupt_mask */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_set_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_set_interrupt chan3_set_interrupt
 * @brief Contains register fields associated with chan3_set_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_SET_INTERRUPT_MACRO__
#define __AT_DMA_CHAN3_SET_INTERRUPT_MACRO__

/* macros for field intrpt_set */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_set_field intrpt_set_field
 * @brief macros for field intrpt_set
 * @details if nth bit set, the nth interrupt is set; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__SHIFT                         0
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__WIDTH                         2
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__MASK                0x00000003U
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN3_SET_INTERRUPT__INTRPT_SET__RESET_VALUE         0x00000000U
/** @} */
#define AT_DMA_CHAN3_SET_INTERRUPT__TYPE                               uint32_t
#define AT_DMA_CHAN3_SET_INTERRUPT__READ                            0x00000003U
#define AT_DMA_CHAN3_SET_INTERRUPT__WRITE                           0x00000003U
#define AT_DMA_CHAN3_SET_INTERRUPT__PRESERVED                       0x00000000U
#define AT_DMA_CHAN3_SET_INTERRUPT__RESET_VALUE                     0x00000000U

#endif /* __AT_DMA_CHAN3_SET_INTERRUPT_MACRO__ */

/** @} end of chan3_set_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_reset_interrupt */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_reset_interrupt chan3_reset_interrupt
 * @brief Contains register fields associated with chan3_reset_interrupt. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_RESET_INTERRUPT_MACRO__
#define __AT_DMA_CHAN3_RESET_INTERRUPT_MACRO__

/* macros for field intrpt_reset */
/**
 * @defgroup at_ahb_dma_regs_core_intrpt_reset_field intrpt_reset_field
 * @brief macros for field intrpt_reset
 * @details if nth bit set, the nth interrupt is reset; HW clears all bits the next cycle.
 * @{
 */
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__SHIFT                     0
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__WIDTH                     2
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__MASK            0x00000003U
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_CHAN3_RESET_INTERRUPT__INTRPT_RESET__RESET_VALUE     0x00000000U
/** @} */
#define AT_DMA_CHAN3_RESET_INTERRUPT__TYPE                             uint32_t
#define AT_DMA_CHAN3_RESET_INTERRUPT__READ                          0x00000003U
#define AT_DMA_CHAN3_RESET_INTERRUPT__WRITE                         0x00000003U
#define AT_DMA_CHAN3_RESET_INTERRUPT__PRESERVED                     0x00000000U
#define AT_DMA_CHAN3_RESET_INTERRUPT__RESET_VALUE                   0x00000000U

#endif /* __AT_DMA_CHAN3_RESET_INTERRUPT_MACRO__ */

/** @} end of chan3_reset_interrupt */

/* macros for BlueprintGlobalNameSpace::AT_DMA_chan3_cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_chan3_cfg_hnonsec chan3_cfg_hnonsec
 * @brief Contains register fields associated with chan3_cfg_hnonsec. definitions.
 * @{
 */
#ifndef __AT_DMA_CHAN3_CFG_HNONSEC_MACRO__
#define __AT_DMA_CHAN3_CFG_HNONSEC_MACRO__

/* macros for field cfg_hnonsec */
/**
 * @defgroup at_ahb_dma_regs_core_cfg_hnonsec_field cfg_hnonsec_field
 * @brief macros for field cfg_hnonsec
 * @details control HNONSEC output signal of this channel. This register is only Write-able by Secure program.
 * @{
 */
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__SHIFT                          0
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__WIDTH                          1
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__MASK                 0x00000001U
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CHAN3_CFG_HNONSEC__CFG_HNONSEC__RESET_VALUE          0x00000001U
/** @} */
#define AT_DMA_CHAN3_CFG_HNONSEC__TYPE                                 uint32_t
#define AT_DMA_CHAN3_CFG_HNONSEC__READ                              0x00000001U
#define AT_DMA_CHAN3_CFG_HNONSEC__WRITE                             0x00000001U
#define AT_DMA_CHAN3_CFG_HNONSEC__PRESERVED                         0x00000000U
#define AT_DMA_CHAN3_CFG_HNONSEC__RESET_VALUE                       0x00000001U

#endif /* __AT_DMA_CHAN3_CFG_HNONSEC_MACRO__ */

/** @} end of chan3_cfg_hnonsec */

/* macros for BlueprintGlobalNameSpace::AT_DMA_err_interrupt_dly */
/**
 * @defgroup at_ahb_dma_regs_core_err_interrupt_dly err_interrupt_dly
 * @brief err interrupt delayed in cycles definitions.
 * @{
 */
#ifndef __AT_DMA_ERR_INTERRUPT_DLY_MACRO__
#define __AT_DMA_ERR_INTERRUPT_DLY_MACRO__

/* macros for field delay_amnt */
/**
 * @defgroup at_ahb_dma_regs_core_delay_amnt_field delay_amnt_field
 * @brief macros for field delay_amnt
 * @details number of cycles to delay the error interrupt event.  Without this delay the interrupt may come up immediately after the go trigger leaving CPU no time to go into WFI.
 * @{
 */
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__SHIFT                           0
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__WIDTH                           8
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__MASK                  0x000000ffU
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define AT_DMA_ERR_INTERRUPT_DLY__DELAY_AMNT__RESET_VALUE           0x0000000aU
/** @} */
#define AT_DMA_ERR_INTERRUPT_DLY__TYPE                                 uint32_t
#define AT_DMA_ERR_INTERRUPT_DLY__READ                              0x000000ffU
#define AT_DMA_ERR_INTERRUPT_DLY__WRITE                             0x000000ffU
#define AT_DMA_ERR_INTERRUPT_DLY__PRESERVED                         0x00000000U
#define AT_DMA_ERR_INTERRUPT_DLY__RESET_VALUE                       0x0000000aU

#endif /* __AT_DMA_ERR_INTERRUPT_DLY_MACRO__ */

/** @} end of err_interrupt_dly */

/* macros for BlueprintGlobalNameSpace::AT_DMA_arbiter_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_arbiter_ctrl arbiter_ctrl
 * @brief Contains register fields associated with arbiter_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_ARBITER_CTRL_MACRO__
#define __AT_DMA_ARBITER_CTRL_MACRO__

/* macros for field priority_en */
/**
 * @defgroup at_ahb_dma_regs_core_priority_en_field priority_en_field
 * @brief macros for field priority_en
 * @details 0= no priority 1=lower numbered channel has higher priority when the bus owernership is relinquished.
 * @{
 */
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__SHIFT                               0
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__WIDTH                               1
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__MASK                      0x00000001U
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_ARBITER_CTRL__PRIORITY_EN__RESET_VALUE               0x00000000U
/** @} */
#define AT_DMA_ARBITER_CTRL__TYPE                                      uint32_t
#define AT_DMA_ARBITER_CTRL__READ                                   0x00000001U
#define AT_DMA_ARBITER_CTRL__WRITE                                  0x00000001U
#define AT_DMA_ARBITER_CTRL__PRESERVED                              0x00000000U
#define AT_DMA_ARBITER_CTRL__RESET_VALUE                            0x00000000U

#endif /* __AT_DMA_ARBITER_CTRL_MACRO__ */

/** @} end of arbiter_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_arbiter_grant_stat */
/**
 * @defgroup at_ahb_dma_regs_core_arbiter_grant_stat arbiter_grant_stat
 * @brief Contains register fields associated with arbiter_grant_stat. definitions.
 * @{
 */
#ifndef __AT_DMA_ARBITER_GRANT_STAT_MACRO__
#define __AT_DMA_ARBITER_GRANT_STAT_MACRO__

/* macros for field chanx_bus_granted */
/**
 * @defgroup at_ahb_dma_regs_core_chanx_bus_granted_field chanx_bus_granted_field
 * @brief macros for field chanx_bus_granted
 * @details one-hot signal indicating channel with AHB bus ownership.
 * @{
 */
#define AT_DMA_ARBITER_GRANT_STAT__CHANX_BUS_GRANTED__SHIFT                   0
#define AT_DMA_ARBITER_GRANT_STAT__CHANX_BUS_GRANTED__WIDTH                   4
#define AT_DMA_ARBITER_GRANT_STAT__CHANX_BUS_GRANTED__MASK          0x0000000fU
#define AT_DMA_ARBITER_GRANT_STAT__CHANX_BUS_GRANTED__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define AT_DMA_ARBITER_GRANT_STAT__CHANX_BUS_GRANTED__RESET_VALUE   0x00000000U
/** @} */
#define AT_DMA_ARBITER_GRANT_STAT__TYPE                                uint32_t
#define AT_DMA_ARBITER_GRANT_STAT__READ                             0x0000000fU
#define AT_DMA_ARBITER_GRANT_STAT__PRESERVED                        0x00000000U
#define AT_DMA_ARBITER_GRANT_STAT__RESET_VALUE                      0x00000000U

#endif /* __AT_DMA_ARBITER_GRANT_STAT_MACRO__ */

/** @} end of arbiter_grant_stat */

/* macros for BlueprintGlobalNameSpace::AT_DMA_diagcntl */
/**
 * @defgroup at_ahb_dma_regs_core_diagcntl diagcntl
 * @brief Contains register fields associated with diagcntl. definitions.
 * @{
 */
#ifndef __AT_DMA_DIAGCNTL_MACRO__
#define __AT_DMA_DIAGCNTL_MACRO__

/* macros for field diag3 */
/**
 * @defgroup at_ahb_dma_regs_core_diag3_field diag3_field
 * @brief macros for field diag3
 * @details selects a group of signal to drive dbg[7:0].
 * @{
 */
#define AT_DMA_DIAGCNTL__DIAG3__SHIFT                                         0
#define AT_DMA_DIAGCNTL__DIAG3__WIDTH                                         2
#define AT_DMA_DIAGCNTL__DIAG3__MASK                                0x00000003U
#define AT_DMA_DIAGCNTL__DIAG3__READ(src)       ((uint32_t)(src) & 0x00000003U)
#define AT_DMA_DIAGCNTL__DIAG3__WRITE(src)      ((uint32_t)(src) & 0x00000003U)
#define AT_DMA_DIAGCNTL__DIAG3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define AT_DMA_DIAGCNTL__DIAG3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define AT_DMA_DIAGCNTL__DIAG3__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field diag2 */
/**
 * @defgroup at_ahb_dma_regs_core_diag2_field diag2_field
 * @brief macros for field diag2
 * @details selects a group of signal to drive dbg[15:8].
 * @{
 */
#define AT_DMA_DIAGCNTL__DIAG2__SHIFT                                         8
#define AT_DMA_DIAGCNTL__DIAG2__WIDTH                                         2
#define AT_DMA_DIAGCNTL__DIAG2__MASK                                0x00000300U
#define AT_DMA_DIAGCNTL__DIAG2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define AT_DMA_DIAGCNTL__DIAG2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define AT_DMA_DIAGCNTL__DIAG2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define AT_DMA_DIAGCNTL__DIAG2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define AT_DMA_DIAGCNTL__DIAG2__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field diag1 */
/**
 * @defgroup at_ahb_dma_regs_core_diag1_field diag1_field
 * @brief macros for field diag1
 * @details selects a group of signal to drive dbg[23:16].
 * @{
 */
#define AT_DMA_DIAGCNTL__DIAG1__SHIFT                                        16
#define AT_DMA_DIAGCNTL__DIAG1__WIDTH                                         2
#define AT_DMA_DIAGCNTL__DIAG1__MASK                                0x00030000U
#define AT_DMA_DIAGCNTL__DIAG1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define AT_DMA_DIAGCNTL__DIAG1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define AT_DMA_DIAGCNTL__DIAG1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define AT_DMA_DIAGCNTL__DIAG1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define AT_DMA_DIAGCNTL__DIAG1__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field diag0 */
/**
 * @defgroup at_ahb_dma_regs_core_diag0_field diag0_field
 * @brief macros for field diag0
 * @details selects a group of signal to drive dbg[31:24].
 * @{
 */
#define AT_DMA_DIAGCNTL__DIAG0__SHIFT                                        24
#define AT_DMA_DIAGCNTL__DIAG0__WIDTH                                         2
#define AT_DMA_DIAGCNTL__DIAG0__MASK                                0x03000000U
#define AT_DMA_DIAGCNTL__DIAG0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define AT_DMA_DIAGCNTL__DIAG0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define AT_DMA_DIAGCNTL__DIAG0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define AT_DMA_DIAGCNTL__DIAG0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define AT_DMA_DIAGCNTL__DIAG0__RESET_VALUE                         0x00000000U
/** @} */
#define AT_DMA_DIAGCNTL__TYPE                                          uint32_t
#define AT_DMA_DIAGCNTL__READ                                       0x03030303U
#define AT_DMA_DIAGCNTL__WRITE                                      0x03030303U
#define AT_DMA_DIAGCNTL__PRESERVED                                  0x00000000U
#define AT_DMA_DIAGCNTL__RESET_VALUE                                0x00000000U

#endif /* __AT_DMA_DIAGCNTL_MACRO__ */

/** @} end of diagcntl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_ccm_ctrl */
/**
 * @defgroup at_ahb_dma_regs_core_ccm_ctrl ccm_ctrl
 * @brief Contains register fields associated with ccm_ctrl. definitions.
 * @{
 */
#ifndef __AT_DMA_CCM_CTRL_MACRO__
#define __AT_DMA_CCM_CTRL_MACRO__

/* macros for field init */
/**
 * @defgroup at_ahb_dma_regs_core_init_field init_field
 * @brief macros for field init
 * @details initialize ccm channel.
 * @{
 */
#define AT_DMA_CCM_CTRL__INIT__SHIFT                                          0
#define AT_DMA_CCM_CTRL__INIT__WIDTH                                          1
#define AT_DMA_CCM_CTRL__INIT__MASK                                 0x00000001U
#define AT_DMA_CCM_CTRL__INIT__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_CCM_CTRL__INIT__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define AT_DMA_CCM_CTRL__INIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define AT_DMA_CCM_CTRL__INIT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define AT_DMA_CCM_CTRL__INIT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define AT_DMA_CCM_CTRL__INIT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define AT_DMA_CCM_CTRL__INIT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field stop */
/**
 * @defgroup at_ahb_dma_regs_core_stop_field stop_field
 * @brief macros for field stop
 * @details stop ccm
 * @{
 */
#define AT_DMA_CCM_CTRL__STOP__SHIFT                                          1
#define AT_DMA_CCM_CTRL__STOP__WIDTH                                          1
#define AT_DMA_CCM_CTRL__STOP__MASK                                 0x00000002U
#define AT_DMA_CCM_CTRL__STOP__READ(src) (((uint32_t)(src) & 0x00000002U) >> 1)
#define AT_DMA_CCM_CTRL__STOP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define AT_DMA_CCM_CTRL__STOP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define AT_DMA_CCM_CTRL__STOP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define AT_DMA_CCM_CTRL__STOP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define AT_DMA_CCM_CTRL__STOP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define AT_DMA_CCM_CTRL__STOP__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field ccm_channel */
/**
 * @defgroup at_ahb_dma_regs_core_ccm_channel_field ccm_channel_field
 * @brief macros for field ccm_channel
 * @details select channel.
 * @{
 */
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__SHIFT                                   2
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__WIDTH                                   2
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__MASK                          0x0000000cU
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define AT_DMA_CCM_CTRL__CCM_CHANNEL__RESET_VALUE                   0x00000000U
/** @} */
#define AT_DMA_CCM_CTRL__TYPE                                          uint32_t
#define AT_DMA_CCM_CTRL__READ                                       0x0000000fU
#define AT_DMA_CCM_CTRL__WRITE                                      0x0000000fU
#define AT_DMA_CCM_CTRL__PRESERVED                                  0x00000000U
#define AT_DMA_CCM_CTRL__RESET_VALUE                                0x00000000U

#endif /* __AT_DMA_CCM_CTRL_MACRO__ */

/** @} end of ccm_ctrl */

/* macros for BlueprintGlobalNameSpace::AT_DMA_id */
/**
 * @defgroup at_ahb_dma_regs_core_id id
 * @brief Contains register fields associated with id. definitions.
 * @{
 */
#ifndef __AT_DMA_ID_MACRO__
#define __AT_DMA_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_ahb_dma_regs_core_id_field id_field
 * @brief macros for field id
 * @details 'DMA '
 * @{
 */
#define AT_DMA_ID__ID__SHIFT                                                  0
#define AT_DMA_ID__ID__WIDTH                                                 32
#define AT_DMA_ID__ID__MASK                                         0xffffffffU
#define AT_DMA_ID__ID__READ(src)                ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_ID__ID__RESET_VALUE                                  0x444d4120U
/** @} */
#define AT_DMA_ID__TYPE                                                uint32_t
#define AT_DMA_ID__READ                                             0xffffffffU
#define AT_DMA_ID__PRESERVED                                        0x00000000U
#define AT_DMA_ID__RESET_VALUE                                      0x444d4120U

#endif /* __AT_DMA_ID_MACRO__ */

/** @} end of id */

/* macros for BlueprintGlobalNameSpace::AT_DMA_rev_hash */
/**
 * @defgroup at_ahb_dma_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __AT_DMA_REV_HASH_MACRO__
#define __AT_DMA_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_ahb_dma_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define AT_DMA_REV_HASH__ID__SHIFT                                            0
#define AT_DMA_REV_HASH__ID__WIDTH                                           32
#define AT_DMA_REV_HASH__ID__MASK                                   0xffffffffU
#define AT_DMA_REV_HASH__ID__READ(src)          ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_REV_HASH__ID__RESET_VALUE                            0xc1f7b3e4U
/** @} */
#define AT_DMA_REV_HASH__TYPE                                          uint32_t
#define AT_DMA_REV_HASH__READ                                       0xffffffffU
#define AT_DMA_REV_HASH__PRESERVED                                  0x00000000U
#define AT_DMA_REV_HASH__RESET_VALUE                                0xc1f7b3e4U

#endif /* __AT_DMA_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::AT_DMA_rev_key */
/**
 * @defgroup at_ahb_dma_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __AT_DMA_REV_KEY_MACRO__
#define __AT_DMA_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_ahb_dma_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define AT_DMA_REV_KEY__ID__SHIFT                                             0
#define AT_DMA_REV_KEY__ID__WIDTH                                            32
#define AT_DMA_REV_KEY__ID__MASK                                    0xffffffffU
#define AT_DMA_REV_KEY__ID__READ(src)           ((uint32_t)(src) & 0xffffffffU)
#define AT_DMA_REV_KEY__ID__RESET_VALUE                             0x52455620U
/** @} */
#define AT_DMA_REV_KEY__TYPE                                           uint32_t
#define AT_DMA_REV_KEY__READ                                        0xffffffffU
#define AT_DMA_REV_KEY__PRESERVED                                   0x00000000U
#define AT_DMA_REV_KEY__RESET_VALUE                                 0x52455620U

#endif /* __AT_DMA_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_AHB_DMA_REGS_CORE */
#endif /* __REG_AT_AHB_DMA_REGS_CORE_H__ */
