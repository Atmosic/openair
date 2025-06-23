/*                                                                           */
/* File:       at_apb_i2c_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_i2c_regs_core.rdl           */
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


#ifndef __REG_AT_APB_I2C_REGS_CORE_H__
#define __REG_AT_APB_I2C_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_I2C_REGS_CORE at_apb_i2c_regs_core
 * @ingroup AT_REG
 * @brief at_apb_i2c_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::I2C_transaction_setup */
/**
 * @defgroup at_apb_i2c_regs_core_transaction_setup transaction_setup
 * @brief Contains register fields associated with transaction_setup. definitions.
 * @{
 */
#ifndef __I2C_TRANSACTION_SETUP_MACRO__
#define __I2C_TRANSACTION_SETUP_MACRO__

/* macros for field head */
/**
 * @defgroup at_apb_i2c_regs_core_head_field head_field
 * @brief macros for field head
 * @details  - 0=start  - 1=stall
 * @{
 */
#define I2C_TRANSACTION_SETUP__HEAD__SHIFT                                    0
#define I2C_TRANSACTION_SETUP__HEAD__WIDTH                                    2
#define I2C_TRANSACTION_SETUP__HEAD__MASK                           0x00000003U
#define I2C_TRANSACTION_SETUP__HEAD__READ(src)  ((uint32_t)(src) & 0x00000003U)
#define I2C_TRANSACTION_SETUP__HEAD__WRITE(src) ((uint32_t)(src) & 0x00000003U)
#define I2C_TRANSACTION_SETUP__HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define I2C_TRANSACTION_SETUP__HEAD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define I2C_TRANSACTION_SETUP__HEAD__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field tail */
/**
 * @defgroup at_apb_i2c_regs_core_tail_field tail_field
 * @brief macros for field tail
 * @details  - 0=stop  - 1=stall  - 2=restart
 * @{
 */
#define I2C_TRANSACTION_SETUP__TAIL__SHIFT                                    4
#define I2C_TRANSACTION_SETUP__TAIL__WIDTH                                    2
#define I2C_TRANSACTION_SETUP__TAIL__MASK                           0x00000030U
#define I2C_TRANSACTION_SETUP__TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000030U) >> 4)
#define I2C_TRANSACTION_SETUP__TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000030U)
#define I2C_TRANSACTION_SETUP__TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((uint32_t)(src) <<\
                    4) & 0x00000030U)
#define I2C_TRANSACTION_SETUP__TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000030U)))
#define I2C_TRANSACTION_SETUP__TAIL__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field master_drives_ack */
/**
 * @defgroup at_apb_i2c_regs_core_master_drives_ack_field master_drives_ack_field
 * @brief macros for field master_drives_ack
 * @{
 */
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__SHIFT                      16
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__WIDTH                       1
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__MASK              0x00010000U
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define I2C_TRANSACTION_SETUP__MASTER_DRIVES_ACK__RESET_VALUE       0x00000000U
/** @} */

/* macros for field ack_value_to_drive */
/**
 * @defgroup at_apb_i2c_regs_core_ack_value_to_drive_field ack_value_to_drive_field
 * @brief macros for field ack_value_to_drive
 * @{
 */
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__SHIFT                     17
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__WIDTH                      1
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__MASK             0x00020000U
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define I2C_TRANSACTION_SETUP__ACK_VALUE_TO_DRIVE__RESET_VALUE      0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_apb_i2c_regs_core_go_field go_field
 * @brief macros for field go
 * @details transaction lauches on rising edge; not self reseting
 * @{
 */
#define I2C_TRANSACTION_SETUP__GO__SHIFT                                     20
#define I2C_TRANSACTION_SETUP__GO__WIDTH                                      1
#define I2C_TRANSACTION_SETUP__GO__MASK                             0x00100000U
#define I2C_TRANSACTION_SETUP__GO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define I2C_TRANSACTION_SETUP__GO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define I2C_TRANSACTION_SETUP__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define I2C_TRANSACTION_SETUP__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define I2C_TRANSACTION_SETUP__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define I2C_TRANSACTION_SETUP__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define I2C_TRANSACTION_SETUP__GO__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mstr */
/**
 * @defgroup at_apb_i2c_regs_core_mstr_field mstr_field
 * @brief macros for field mstr
 * @details  - 1=master interface  - 0=slave interface
 * @{
 */
#define I2C_TRANSACTION_SETUP__MSTR__SHIFT                                   21
#define I2C_TRANSACTION_SETUP__MSTR__WIDTH                                    1
#define I2C_TRANSACTION_SETUP__MSTR__MASK                           0x00200000U
#define I2C_TRANSACTION_SETUP__MSTR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define I2C_TRANSACTION_SETUP__MSTR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define I2C_TRANSACTION_SETUP__MSTR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define I2C_TRANSACTION_SETUP__MSTR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define I2C_TRANSACTION_SETUP__MSTR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define I2C_TRANSACTION_SETUP__MSTR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define I2C_TRANSACTION_SETUP__MSTR__RESET_VALUE                    0x00000001U
/** @} */
#define I2C_TRANSACTION_SETUP__TYPE                                    uint32_t
#define I2C_TRANSACTION_SETUP__READ                                 0x00330033U
#define I2C_TRANSACTION_SETUP__WRITE                                0x00330033U
#define I2C_TRANSACTION_SETUP__PRESERVED                            0x00000000U
#define I2C_TRANSACTION_SETUP__RESET_VALUE                          0x00200000U

#endif /* __I2C_TRANSACTION_SETUP_MACRO__ */

/** @} end of transaction_setup */

/* macros for BlueprintGlobalNameSpace::I2C_clock_control */
/**
 * @defgroup at_apb_i2c_regs_core_clock_control clock_control
 * @brief Contains register fields associated with clock_control. definitions.
 * @{
 */
#ifndef __I2C_CLOCK_CONTROL_MACRO__
#define __I2C_CLOCK_CONTROL_MACRO__

/* macros for field clkdiv */
/**
 * @defgroup at_apb_i2c_regs_core_clkdiv_field clkdiv_field
 * @brief macros for field clkdiv
 * @details freq_scl = f_pclk/(4*(clkdiv+1))
 * @{
 */
#define I2C_CLOCK_CONTROL__CLKDIV__SHIFT                                      0
#define I2C_CLOCK_CONTROL__CLKDIV__WIDTH                                     10
#define I2C_CLOCK_CONTROL__CLKDIV__MASK                             0x000003ffU
#define I2C_CLOCK_CONTROL__CLKDIV__READ(src)    ((uint32_t)(src) & 0x000003ffU)
#define I2C_CLOCK_CONTROL__CLKDIV__WRITE(src)   ((uint32_t)(src) & 0x000003ffU)
#define I2C_CLOCK_CONTROL__CLKDIV__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define I2C_CLOCK_CONTROL__CLKDIV__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define I2C_CLOCK_CONTROL__CLKDIV__RESET_VALUE                      0x00000007U
/** @} */

/* macros for field clk_oe */
/**
 * @defgroup at_apb_i2c_regs_core_clk_oe_field clk_oe_field
 * @brief macros for field clk_oe
 * @details scl pin output-enable control  0= scl pin is in open-drain mode  1= scl pin is in push-pull mode
 * @{
 */
#define I2C_CLOCK_CONTROL__CLK_OE__SHIFT                                     10
#define I2C_CLOCK_CONTROL__CLK_OE__WIDTH                                      1
#define I2C_CLOCK_CONTROL__CLK_OE__MASK                             0x00000400U
#define I2C_CLOCK_CONTROL__CLK_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define I2C_CLOCK_CONTROL__CLK_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define I2C_CLOCK_CONTROL__CLK_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define I2C_CLOCK_CONTROL__CLK_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define I2C_CLOCK_CONTROL__CLK_OE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define I2C_CLOCK_CONTROL__CLK_OE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define I2C_CLOCK_CONTROL__CLK_OE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field clk_pu */
/**
 * @defgroup at_apb_i2c_regs_core_clk_pu_field clk_pu_field
 * @brief macros for field clk_pu
 * @details scl pin pullup enable
 * @{
 */
#define I2C_CLOCK_CONTROL__CLK_PU__SHIFT                                     11
#define I2C_CLOCK_CONTROL__CLK_PU__WIDTH                                      1
#define I2C_CLOCK_CONTROL__CLK_PU__MASK                             0x00000800U
#define I2C_CLOCK_CONTROL__CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define I2C_CLOCK_CONTROL__CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define I2C_CLOCK_CONTROL__CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define I2C_CLOCK_CONTROL__CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define I2C_CLOCK_CONTROL__CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define I2C_CLOCK_CONTROL__CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define I2C_CLOCK_CONTROL__CLK_PU__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field clk_stretch_en */
/**
 * @defgroup at_apb_i2c_regs_core_clk_stretch_en_field clk_stretch_en_field
 * @brief macros for field clk_stretch_en
 * @details scl clock-stretching enable
 * @{
 */
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__SHIFT                             12
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__WIDTH                              1
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__MASK                     0x00001000U
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_EN__RESET_VALUE              0x00000000U
/** @} */

/* macros for field clk_stretch_dur */
/**
 * @defgroup at_apb_i2c_regs_core_clk_stretch_dur_field clk_stretch_dur_field
 * @brief macros for field clk_stretch_dur
 * @details scl clock-stretching wait duration. Insert wait states based on selection  0=wait for slave to release scl line  1=wait for 1-byte; time-out after  2=wait for 2-byte; time-out after  3=wait for 4-byte; time-out after
 * @{
 */
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__SHIFT                            13
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__WIDTH                             2
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__MASK                    0x00006000U
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00006000U) >> 13)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00006000U)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00006000U) | (((uint32_t)(src) <<\
                    13) & 0x00006000U)
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00006000U)))
#define I2C_CLOCK_CONTROL__CLK_STRETCH_DUR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clk_sync_en */
/**
 * @defgroup at_apb_i2c_regs_core_clk_sync_en_field clk_sync_en_field
 * @brief macros for field clk_sync_en
 * @details 1=enables synchronizers on scl input line during clock-stretching
 * @{
 */
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__SHIFT                                15
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__WIDTH                                 1
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__MASK                        0x00008000U
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define I2C_CLOCK_CONTROL__CLK_SYNC_EN__RESET_VALUE                 0x00000000U
/** @} */
#define I2C_CLOCK_CONTROL__TYPE                                        uint32_t
#define I2C_CLOCK_CONTROL__READ                                     0x0000ffffU
#define I2C_CLOCK_CONTROL__WRITE                                    0x0000ffffU
#define I2C_CLOCK_CONTROL__PRESERVED                                0x00000000U
#define I2C_CLOCK_CONTROL__RESET_VALUE                              0x00000807U

#endif /* __I2C_CLOCK_CONTROL_MACRO__ */

/** @} end of clock_control */

/* macros for BlueprintGlobalNameSpace::I2C_outgoing_data */
/**
 * @defgroup at_apb_i2c_regs_core_outgoing_data outgoing_data
 * @brief Contains register fields associated with outgoing_data. definitions.
 * @{
 */
#ifndef __I2C_OUTGOING_DATA_MACRO__
#define __I2C_OUTGOING_DATA_MACRO__

/* macros for field data_o */
/**
 * @defgroup at_apb_i2c_regs_core_data_o_field data_o_field
 * @brief macros for field data_o
 * @details can be device id, address within device, or write data; if it's device id, the LSB is the R/Wb indicator
 * @{
 */
#define I2C_OUTGOING_DATA__DATA_O__SHIFT                                      0
#define I2C_OUTGOING_DATA__DATA_O__WIDTH                                      8
#define I2C_OUTGOING_DATA__DATA_O__MASK                             0x000000ffU
#define I2C_OUTGOING_DATA__DATA_O__READ(src)    ((uint32_t)(src) & 0x000000ffU)
#define I2C_OUTGOING_DATA__DATA_O__WRITE(src)   ((uint32_t)(src) & 0x000000ffU)
#define I2C_OUTGOING_DATA__DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define I2C_OUTGOING_DATA__DATA_O__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define I2C_OUTGOING_DATA__DATA_O__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field data_oe */
/**
 * @defgroup at_apb_i2c_regs_core_data_oe_field data_oe_field
 * @brief macros for field data_oe
 * @details sda pin data output-enable control
 * @{
 */
#define I2C_OUTGOING_DATA__DATA_OE__SHIFT                                     8
#define I2C_OUTGOING_DATA__DATA_OE__WIDTH                                     8
#define I2C_OUTGOING_DATA__DATA_OE__MASK                            0x0000ff00U
#define I2C_OUTGOING_DATA__DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define I2C_OUTGOING_DATA__DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define I2C_OUTGOING_DATA__DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define I2C_OUTGOING_DATA__DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define I2C_OUTGOING_DATA__DATA_OE__RESET_VALUE                     0x000000ffU
/** @} */

/* macros for field data_pu */
/**
 * @defgroup at_apb_i2c_regs_core_data_pu_field data_pu_field
 * @brief macros for field data_pu
 * @details sda pin pullup enable
 * @{
 */
#define I2C_OUTGOING_DATA__DATA_PU__SHIFT                                    16
#define I2C_OUTGOING_DATA__DATA_PU__WIDTH                                     1
#define I2C_OUTGOING_DATA__DATA_PU__MASK                            0x00010000U
#define I2C_OUTGOING_DATA__DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define I2C_OUTGOING_DATA__DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define I2C_OUTGOING_DATA__DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define I2C_OUTGOING_DATA__DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define I2C_OUTGOING_DATA__DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define I2C_OUTGOING_DATA__DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define I2C_OUTGOING_DATA__DATA_PU__RESET_VALUE                     0x00000001U
/** @} */
#define I2C_OUTGOING_DATA__TYPE                                        uint32_t
#define I2C_OUTGOING_DATA__READ                                     0x0001ffffU
#define I2C_OUTGOING_DATA__WRITE                                    0x0001ffffU
#define I2C_OUTGOING_DATA__PRESERVED                                0x00000000U
#define I2C_OUTGOING_DATA__RESET_VALUE                              0x0001ff00U

#endif /* __I2C_OUTGOING_DATA_MACRO__ */

/** @} end of outgoing_data */

/* macros for BlueprintGlobalNameSpace::I2C_outgoing_data1 */
/**
 * @defgroup at_apb_i2c_regs_core_outgoing_data1 outgoing_data1
 * @brief stores outgoing read data definitions.
 * @{
 */
#ifndef __I2C_OUTGOING_DATA1_MACRO__
#define __I2C_OUTGOING_DATA1_MACRO__

/* macros for field data1_o */
/**
 * @defgroup at_apb_i2c_regs_core_data1_o_field data1_o_field
 * @brief macros for field data1_o
 * @details slave: stores outgoing read data
 * @{
 */
#define I2C_OUTGOING_DATA1__DATA1_O__SHIFT                                    0
#define I2C_OUTGOING_DATA1__DATA1_O__WIDTH                                   32
#define I2C_OUTGOING_DATA1__DATA1_O__MASK                           0xffffffffU
#define I2C_OUTGOING_DATA1__DATA1_O__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define I2C_OUTGOING_DATA1__DATA1_O__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define I2C_OUTGOING_DATA1__DATA1_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define I2C_OUTGOING_DATA1__DATA1_O__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define I2C_OUTGOING_DATA1__DATA1_O__RESET_VALUE                    0x00000000U
/** @} */
#define I2C_OUTGOING_DATA1__TYPE                                       uint32_t
#define I2C_OUTGOING_DATA1__READ                                    0xffffffffU
#define I2C_OUTGOING_DATA1__WRITE                                   0xffffffffU
#define I2C_OUTGOING_DATA1__PRESERVED                               0x00000000U
#define I2C_OUTGOING_DATA1__RESET_VALUE                             0x00000000U

#endif /* __I2C_OUTGOING_DATA1_MACRO__ */

/** @} end of outgoing_data1 */

/* macros for BlueprintGlobalNameSpace::I2C_io_ctrl */
/**
 * @defgroup at_apb_i2c_regs_core_io_ctrl io_ctrl
 * @brief Contains register fields associated with io_ctrl. definitions.
 * @{
 */
#ifndef __I2C_IO_CTRL_MACRO__
#define __I2C_IO_CTRL_MACRO__

/* macros for field data_ie_ovrd */
/**
 * @defgroup at_apb_i2c_regs_core_data_ie_ovrd_field data_ie_ovrd_field
 * @brief macros for field data_ie_ovrd
 * @details  - 1= ie is high  - 0= ie is ~oe
 * @{
 */
#define I2C_IO_CTRL__DATA_IE_OVRD__SHIFT                                      0
#define I2C_IO_CTRL__DATA_IE_OVRD__WIDTH                                      1
#define I2C_IO_CTRL__DATA_IE_OVRD__MASK                             0x00000001U
#define I2C_IO_CTRL__DATA_IE_OVRD__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define I2C_IO_CTRL__DATA_IE_OVRD__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define I2C_IO_CTRL__DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define I2C_IO_CTRL__DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define I2C_IO_CTRL__DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define I2C_IO_CTRL__DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define I2C_IO_CTRL__DATA_IE_OVRD__RESET_VALUE                      0x00000000U
/** @} */
#define I2C_IO_CTRL__TYPE                                              uint32_t
#define I2C_IO_CTRL__READ                                           0x00000001U
#define I2C_IO_CTRL__WRITE                                          0x00000001U
#define I2C_IO_CTRL__PRESERVED                                      0x00000000U
#define I2C_IO_CTRL__RESET_VALUE                                    0x00000000U

#endif /* __I2C_IO_CTRL_MACRO__ */

/** @} end of io_ctrl */

/* macros for BlueprintGlobalNameSpace::I2C_incoming_data */
/**
 * @defgroup at_apb_i2c_regs_core_incoming_data incoming_data
 * @brief stores incoming write data definitions.
 * @{
 */
#ifndef __I2C_INCOMING_DATA_MACRO__
#define __I2C_INCOMING_DATA_MACRO__

/* macros for field data_i */
/**
 * @defgroup at_apb_i2c_regs_core_data_i_field data_i_field
 * @brief macros for field data_i
 * @details master: only lsb byte used slave: all 4 bytes can be used
 * @{
 */
#define I2C_INCOMING_DATA__DATA_I__SHIFT                                      0
#define I2C_INCOMING_DATA__DATA_I__WIDTH                                     32
#define I2C_INCOMING_DATA__DATA_I__MASK                             0xffffffffU
#define I2C_INCOMING_DATA__DATA_I__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define I2C_INCOMING_DATA__DATA_I__RESET_VALUE                      0x00000000U
/** @} */
#define I2C_INCOMING_DATA__TYPE                                        uint32_t
#define I2C_INCOMING_DATA__READ                                     0xffffffffU
#define I2C_INCOMING_DATA__PRESERVED                                0x00000000U
#define I2C_INCOMING_DATA__RESET_VALUE                              0x00000000U

#endif /* __I2C_INCOMING_DATA_MACRO__ */

/** @} end of incoming_data */

/* macros for BlueprintGlobalNameSpace::I2C_incoming_data1 */
/**
 * @defgroup at_apb_i2c_regs_core_incoming_data1 incoming_data1
 * @brief stores read/write address definitions.
 * @{
 */
#ifndef __I2C_INCOMING_DATA1_MACRO__
#define __I2C_INCOMING_DATA1_MACRO__

/* macros for field data1_i */
/**
 * @defgroup at_apb_i2c_regs_core_data1_i_field data1_i_field
 * @brief macros for field data1_i
 * @details slave: stores read/write address
 * @{
 */
#define I2C_INCOMING_DATA1__DATA1_I__SHIFT                                    0
#define I2C_INCOMING_DATA1__DATA1_I__WIDTH                                   32
#define I2C_INCOMING_DATA1__DATA1_I__MASK                           0xffffffffU
#define I2C_INCOMING_DATA1__DATA1_I__READ(src)  ((uint32_t)(src) & 0xffffffffU)
#define I2C_INCOMING_DATA1__DATA1_I__RESET_VALUE                    0x00000000U
/** @} */
#define I2C_INCOMING_DATA1__TYPE                                       uint32_t
#define I2C_INCOMING_DATA1__READ                                    0xffffffffU
#define I2C_INCOMING_DATA1__PRESERVED                               0x00000000U
#define I2C_INCOMING_DATA1__RESET_VALUE                             0x00000000U

#endif /* __I2C_INCOMING_DATA1_MACRO__ */

/** @} end of incoming_data1 */

/* macros for BlueprintGlobalNameSpace::I2C_transaction_status */
/**
 * @defgroup at_apb_i2c_regs_core_transaction_status transaction_status
 * @brief Contains register fields associated with transaction_status. definitions.
 * @{
 */
#ifndef __I2C_TRANSACTION_STATUS_MACRO__
#define __I2C_TRANSACTION_STATUS_MACRO__

/* macros for field ack_value */
/**
 * @defgroup at_apb_i2c_regs_core_ack_value_field ack_value_field
 * @brief macros for field ack_value
 * @details useless if mast_drives_ack is set
 * @{
 */
#define I2C_TRANSACTION_STATUS__ACK_VALUE__SHIFT                              0
#define I2C_TRANSACTION_STATUS__ACK_VALUE__WIDTH                              1
#define I2C_TRANSACTION_STATUS__ACK_VALUE__MASK                     0x00000001U
#define I2C_TRANSACTION_STATUS__ACK_VALUE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_TRANSACTION_STATUS__ACK_VALUE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define I2C_TRANSACTION_STATUS__ACK_VALUE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define I2C_TRANSACTION_STATUS__ACK_VALUE__RESET_VALUE              0x00000000U
/** @} */

/* macros for field running */
/**
 * @defgroup at_apb_i2c_regs_core_running_field running_field
 * @brief macros for field running
 * @details 1=indicate master or slave running based on which interface selected by 'mstr' bit
 * @{
 */
#define I2C_TRANSACTION_STATUS__RUNNING__SHIFT                                1
#define I2C_TRANSACTION_STATUS__RUNNING__WIDTH                                1
#define I2C_TRANSACTION_STATUS__RUNNING__MASK                       0x00000002U
#define I2C_TRANSACTION_STATUS__RUNNING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define I2C_TRANSACTION_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define I2C_TRANSACTION_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define I2C_TRANSACTION_STATUS__RUNNING__RESET_VALUE                0x00000000U
/** @} */

/* macros for field s_rwb */
/**
 * @defgroup at_apb_i2c_regs_core_s_rwb_field s_rwb_field
 * @brief macros for field s_rwb
 * @details slave read/write status bit  - 0=write  - 1=read
 * @{
 */
#define I2C_TRANSACTION_STATUS__S_RWB__SHIFT                                  2
#define I2C_TRANSACTION_STATUS__S_RWB__WIDTH                                  1
#define I2C_TRANSACTION_STATUS__S_RWB__MASK                         0x00000004U
#define I2C_TRANSACTION_STATUS__S_RWB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define I2C_TRANSACTION_STATUS__S_RWB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define I2C_TRANSACTION_STATUS__S_RWB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define I2C_TRANSACTION_STATUS__S_RWB__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup at_apb_i2c_regs_core_done_field done_field
 * @brief macros for field done
 * @details 1=indicate master is done with current byte R/W or slave done with transaction capture, based on selected interface.
 * @{
 */
#define I2C_TRANSACTION_STATUS__DONE__SHIFT                                   3
#define I2C_TRANSACTION_STATUS__DONE__WIDTH                                   1
#define I2C_TRANSACTION_STATUS__DONE__MASK                          0x00000008U
#define I2C_TRANSACTION_STATUS__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define I2C_TRANSACTION_STATUS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define I2C_TRANSACTION_STATUS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define I2C_TRANSACTION_STATUS__DONE__RESET_VALUE                   0x00000000U
/** @} */
#define I2C_TRANSACTION_STATUS__TYPE                                   uint32_t
#define I2C_TRANSACTION_STATUS__READ                                0x0000000fU
#define I2C_TRANSACTION_STATUS__PRESERVED                           0x00000000U
#define I2C_TRANSACTION_STATUS__RESET_VALUE                         0x00000000U

#endif /* __I2C_TRANSACTION_STATUS_MACRO__ */

/** @} end of transaction_status */

/* macros for BlueprintGlobalNameSpace::I2C_interrupt_mask */
/**
 * @defgroup at_apb_i2c_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __I2C_INTERRUPT_MASK_MACRO__
#define __I2C_INTERRUPT_MASK_MACRO__

/* macros for field passthru0 */
/**
 * @defgroup at_apb_i2c_regs_core_passthru0_field passthru0_field
 * @brief macros for field passthru0
 * @details 1=allow interrupt0 to be OR'ed into core interrupt
 * @{
 */
#define I2C_INTERRUPT_MASK__PASSTHRU0__SHIFT                                  0
#define I2C_INTERRUPT_MASK__PASSTHRU0__WIDTH                                  1
#define I2C_INTERRUPT_MASK__PASSTHRU0__MASK                         0x00000001U
#define I2C_INTERRUPT_MASK__PASSTHRU0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_INTERRUPT_MASK__PASSTHRU0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_INTERRUPT_MASK__PASSTHRU0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define I2C_INTERRUPT_MASK__PASSTHRU0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define I2C_INTERRUPT_MASK__PASSTHRU0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define I2C_INTERRUPT_MASK__PASSTHRU0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define I2C_INTERRUPT_MASK__PASSTHRU0__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field passthru1 */
/**
 * @defgroup at_apb_i2c_regs_core_passthru1_field passthru1_field
 * @brief macros for field passthru1
 * @details 1=allow interrupt1 to be OR'ed into core interrupt
 * @{
 */
#define I2C_INTERRUPT_MASK__PASSTHRU1__SHIFT                                  1
#define I2C_INTERRUPT_MASK__PASSTHRU1__WIDTH                                  1
#define I2C_INTERRUPT_MASK__PASSTHRU1__MASK                         0x00000002U
#define I2C_INTERRUPT_MASK__PASSTHRU1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define I2C_INTERRUPT_MASK__PASSTHRU1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define I2C_INTERRUPT_MASK__PASSTHRU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define I2C_INTERRUPT_MASK__PASSTHRU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define I2C_INTERRUPT_MASK__PASSTHRU1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define I2C_INTERRUPT_MASK__PASSTHRU1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define I2C_INTERRUPT_MASK__PASSTHRU1__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field passthru2 */
/**
 * @defgroup at_apb_i2c_regs_core_passthru2_field passthru2_field
 * @brief macros for field passthru2
 * @details 1=allow interrupt2 to be OR'ed into core interrupt
 * @{
 */
#define I2C_INTERRUPT_MASK__PASSTHRU2__SHIFT                                  2
#define I2C_INTERRUPT_MASK__PASSTHRU2__WIDTH                                  1
#define I2C_INTERRUPT_MASK__PASSTHRU2__MASK                         0x00000004U
#define I2C_INTERRUPT_MASK__PASSTHRU2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define I2C_INTERRUPT_MASK__PASSTHRU2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define I2C_INTERRUPT_MASK__PASSTHRU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define I2C_INTERRUPT_MASK__PASSTHRU2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define I2C_INTERRUPT_MASK__PASSTHRU2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define I2C_INTERRUPT_MASK__PASSTHRU2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define I2C_INTERRUPT_MASK__PASSTHRU2__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field passthru3 */
/**
 * @defgroup at_apb_i2c_regs_core_passthru3_field passthru3_field
 * @brief macros for field passthru3
 * @details 1=allow interrupt3 to be OR'ed into core interrupt
 * @{
 */
#define I2C_INTERRUPT_MASK__PASSTHRU3__SHIFT                                  3
#define I2C_INTERRUPT_MASK__PASSTHRU3__WIDTH                                  1
#define I2C_INTERRUPT_MASK__PASSTHRU3__MASK                         0x00000008U
#define I2C_INTERRUPT_MASK__PASSTHRU3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define I2C_INTERRUPT_MASK__PASSTHRU3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define I2C_INTERRUPT_MASK__PASSTHRU3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define I2C_INTERRUPT_MASK__PASSTHRU3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define I2C_INTERRUPT_MASK__PASSTHRU3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define I2C_INTERRUPT_MASK__PASSTHRU3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define I2C_INTERRUPT_MASK__PASSTHRU3__RESET_VALUE                  0x00000000U
/** @} */
#define I2C_INTERRUPT_MASK__TYPE                                       uint32_t
#define I2C_INTERRUPT_MASK__READ                                    0x0000000fU
#define I2C_INTERRUPT_MASK__WRITE                                   0x0000000fU
#define I2C_INTERRUPT_MASK__PRESERVED                               0x00000000U
#define I2C_INTERRUPT_MASK__RESET_VALUE                             0x00000000U

#endif /* __I2C_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::I2C_interrupt_status */
/**
 * @defgroup at_apb_i2c_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __I2C_INTERRUPT_STATUS_MACRO__
#define __I2C_INTERRUPT_STATUS_MACRO__

/* macros for field interrupt0 */
/**
 * @defgroup at_apb_i2c_regs_core_interrupt0_field interrupt0_field
 * @brief macros for field interrupt0
 * @details from master, rising edge on done; independent of mask
 * @{
 */
#define I2C_INTERRUPT_STATUS__INTERRUPT0__SHIFT                               0
#define I2C_INTERRUPT_STATUS__INTERRUPT0__WIDTH                               1
#define I2C_INTERRUPT_STATUS__INTERRUPT0__MASK                      0x00000001U
#define I2C_INTERRUPT_STATUS__INTERRUPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_INTERRUPT_STATUS__INTERRUPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define I2C_INTERRUPT_STATUS__INTERRUPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define I2C_INTERRUPT_STATUS__INTERRUPT0__RESET_VALUE               0x00000000U
/** @} */

/* macros for field interrupt1 */
/**
 * @defgroup at_apb_i2c_regs_core_interrupt1_field interrupt1_field
 * @brief macros for field interrupt1
 * @details from slave, rising edge on done transaction capture; independent of mask
 * @{
 */
#define I2C_INTERRUPT_STATUS__INTERRUPT1__SHIFT                               1
#define I2C_INTERRUPT_STATUS__INTERRUPT1__WIDTH                               1
#define I2C_INTERRUPT_STATUS__INTERRUPT1__MASK                      0x00000002U
#define I2C_INTERRUPT_STATUS__INTERRUPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define I2C_INTERRUPT_STATUS__INTERRUPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define I2C_INTERRUPT_STATUS__INTERRUPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define I2C_INTERRUPT_STATUS__INTERRUPT1__RESET_VALUE               0x00000000U
/** @} */

/* macros for field interrupt2 */
/**
 * @defgroup at_apb_i2c_regs_core_interrupt2_field interrupt2_field
 * @brief macros for field interrupt2
 * @details from slave, rising edge on read data valid error; independent of mask
 * @{
 */
#define I2C_INTERRUPT_STATUS__INTERRUPT2__SHIFT                               2
#define I2C_INTERRUPT_STATUS__INTERRUPT2__WIDTH                               1
#define I2C_INTERRUPT_STATUS__INTERRUPT2__MASK                      0x00000004U
#define I2C_INTERRUPT_STATUS__INTERRUPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define I2C_INTERRUPT_STATUS__INTERRUPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define I2C_INTERRUPT_STATUS__INTERRUPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define I2C_INTERRUPT_STATUS__INTERRUPT2__RESET_VALUE               0x00000000U
/** @} */

/* macros for field interrupt3 */
/**
 * @defgroup at_apb_i2c_regs_core_interrupt3_field interrupt3_field
 * @brief macros for field interrupt3
 * @details from master, rising edge on scl release wait time-out error; independent of mask
 * @{
 */
#define I2C_INTERRUPT_STATUS__INTERRUPT3__SHIFT                               3
#define I2C_INTERRUPT_STATUS__INTERRUPT3__WIDTH                               1
#define I2C_INTERRUPT_STATUS__INTERRUPT3__MASK                      0x00000008U
#define I2C_INTERRUPT_STATUS__INTERRUPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define I2C_INTERRUPT_STATUS__INTERRUPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define I2C_INTERRUPT_STATUS__INTERRUPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define I2C_INTERRUPT_STATUS__INTERRUPT3__RESET_VALUE               0x00000000U
/** @} */
#define I2C_INTERRUPT_STATUS__TYPE                                     uint32_t
#define I2C_INTERRUPT_STATUS__READ                                  0x0000000fU
#define I2C_INTERRUPT_STATUS__PRESERVED                             0x00000000U
#define I2C_INTERRUPT_STATUS__RESET_VALUE                           0x00000000U

#endif /* __I2C_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::I2C_set_interrupt */
/**
 * @defgroup at_apb_i2c_regs_core_set_interrupt set_interrupt
 * @brief interrupt setting definitions.
 * @{
 */
#ifndef __I2C_SET_INTERRUPT_MACRO__
#define __I2C_SET_INTERRUPT_MACRO__

/* macros for field set_interrupt0 */
/**
 * @defgroup at_apb_i2c_regs_core_set_interrupt0_field set_interrupt0_field
 * @brief macros for field set_interrupt0
 * @details set interrupt0; (__SELF_CLEARING__)
 * @{
 */
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__SHIFT                              0
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__WIDTH                              1
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__MASK                     0x00000001U
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define I2C_SET_INTERRUPT__SET_INTERRUPT0__RESET_VALUE              0x00000000U
/** @} */

/* macros for field set_interrupt1 */
/**
 * @defgroup at_apb_i2c_regs_core_set_interrupt1_field set_interrupt1_field
 * @brief macros for field set_interrupt1
 * @details set interrupt1; (__SELF_CLEARING__)
 * @{
 */
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__SHIFT                              1
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__WIDTH                              1
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__MASK                     0x00000002U
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define I2C_SET_INTERRUPT__SET_INTERRUPT1__RESET_VALUE              0x00000000U
/** @} */

/* macros for field set_interrupt2 */
/**
 * @defgroup at_apb_i2c_regs_core_set_interrupt2_field set_interrupt2_field
 * @brief macros for field set_interrupt2
 * @details set interrupt2; (__SELF_CLEARING__)
 * @{
 */
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__SHIFT                              2
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__WIDTH                              1
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__MASK                     0x00000004U
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define I2C_SET_INTERRUPT__SET_INTERRUPT2__RESET_VALUE              0x00000000U
/** @} */

/* macros for field set_interrupt3 */
/**
 * @defgroup at_apb_i2c_regs_core_set_interrupt3_field set_interrupt3_field
 * @brief macros for field set_interrupt3
 * @details set interrupt3; (__SELF_CLEARING__)
 * @{
 */
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__SHIFT                              3
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__WIDTH                              1
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__MASK                     0x00000008U
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define I2C_SET_INTERRUPT__SET_INTERRUPT3__RESET_VALUE              0x00000000U
/** @} */
#define I2C_SET_INTERRUPT__TYPE                                        uint32_t
#define I2C_SET_INTERRUPT__READ                                     0x0000000fU
#define I2C_SET_INTERRUPT__WRITE                                    0x0000000fU
#define I2C_SET_INTERRUPT__PRESERVED                                0x00000000U
#define I2C_SET_INTERRUPT__RESET_VALUE                              0x00000000U

#endif /* __I2C_SET_INTERRUPT_MACRO__ */

/** @} end of set_interrupt */

/* macros for BlueprintGlobalNameSpace::I2C_reset_interrupt */
/**
 * @defgroup at_apb_i2c_regs_core_reset_interrupt reset_interrupt
 * @brief interrupt resetting definitions.
 * @{
 */
#ifndef __I2C_RESET_INTERRUPT_MACRO__
#define __I2C_RESET_INTERRUPT_MACRO__

/* macros for field reset_interrupt0 */
/**
 * @defgroup at_apb_i2c_regs_core_reset_interrupt0_field reset_interrupt0_field
 * @brief macros for field reset_interrupt0
 * @details clear interrupt0; (__SELF_CLEARING__)
 * @{
 */
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__SHIFT                          0
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__WIDTH                          1
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__MASK                 0x00000001U
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT0__RESET_VALUE          0x00000000U
/** @} */

/* macros for field reset_interrupt1 */
/**
 * @defgroup at_apb_i2c_regs_core_reset_interrupt1_field reset_interrupt1_field
 * @brief macros for field reset_interrupt1
 * @details clear interrupt1; (__SELF_CLEARING__)
 * @{
 */
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__SHIFT                          1
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__WIDTH                          1
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__MASK                 0x00000002U
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT1__RESET_VALUE          0x00000000U
/** @} */

/* macros for field reset_interrupt2 */
/**
 * @defgroup at_apb_i2c_regs_core_reset_interrupt2_field reset_interrupt2_field
 * @brief macros for field reset_interrupt2
 * @details clear interrupt2; (__SELF_CLEARING__)
 * @{
 */
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__SHIFT                          2
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__WIDTH                          1
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__MASK                 0x00000004U
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT2__RESET_VALUE          0x00000000U
/** @} */

/* macros for field reset_interrupt3 */
/**
 * @defgroup at_apb_i2c_regs_core_reset_interrupt3_field reset_interrupt3_field
 * @brief macros for field reset_interrupt3
 * @details clear interrupt3; (__SELF_CLEARING__)
 * @{
 */
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__SHIFT                          3
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__WIDTH                          1
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__MASK                 0x00000008U
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define I2C_RESET_INTERRUPT__RESET_INTERRUPT3__RESET_VALUE          0x00000000U
/** @} */
#define I2C_RESET_INTERRUPT__TYPE                                      uint32_t
#define I2C_RESET_INTERRUPT__READ                                   0x0000000fU
#define I2C_RESET_INTERRUPT__WRITE                                  0x0000000fU
#define I2C_RESET_INTERRUPT__PRESERVED                              0x00000000U
#define I2C_RESET_INTERRUPT__RESET_VALUE                            0x00000000U

#endif /* __I2C_RESET_INTERRUPT_MACRO__ */

/** @} end of reset_interrupt */

/* macros for BlueprintGlobalNameSpace::I2C_id */
/**
 * @defgroup at_apb_i2c_regs_core_id id
 * @brief Contains register fields associated with id. definitions.
 * @{
 */
#ifndef __I2C_ID_MACRO__
#define __I2C_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_i2c_regs_core_id_field id_field
 * @brief macros for field id
 * @details I2C in ASCII
 * @{
 */
#define I2C_ID__ID__SHIFT                                                     0
#define I2C_ID__ID__WIDTH                                                    32
#define I2C_ID__ID__MASK                                            0xffffffffU
#define I2C_ID__ID__READ(src)                   ((uint32_t)(src) & 0xffffffffU)
#define I2C_ID__ID__RESET_VALUE                                     0x49324320U
/** @} */
#define I2C_ID__TYPE                                                   uint32_t
#define I2C_ID__READ                                                0xffffffffU
#define I2C_ID__PRESERVED                                           0x00000000U
#define I2C_ID__RESET_VALUE                                         0x49324320U

#endif /* __I2C_ID_MACRO__ */

/** @} end of id */

/* macros for BlueprintGlobalNameSpace::I2C_rev_hash */
/**
 * @defgroup at_apb_i2c_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __I2C_REV_HASH_MACRO__
#define __I2C_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_i2c_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define I2C_REV_HASH__ID__SHIFT                                               0
#define I2C_REV_HASH__ID__WIDTH                                              32
#define I2C_REV_HASH__ID__MASK                                      0xffffffffU
#define I2C_REV_HASH__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define I2C_REV_HASH__ID__RESET_VALUE                               0x61841f03U
/** @} */
#define I2C_REV_HASH__TYPE                                             uint32_t
#define I2C_REV_HASH__READ                                          0xffffffffU
#define I2C_REV_HASH__PRESERVED                                     0x00000000U
#define I2C_REV_HASH__RESET_VALUE                                   0x61841f03U

#endif /* __I2C_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::I2C_rev_key */
/**
 * @defgroup at_apb_i2c_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __I2C_REV_KEY_MACRO__
#define __I2C_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_i2c_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define I2C_REV_KEY__ID__SHIFT                                                0
#define I2C_REV_KEY__ID__WIDTH                                               32
#define I2C_REV_KEY__ID__MASK                                       0xffffffffU
#define I2C_REV_KEY__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define I2C_REV_KEY__ID__RESET_VALUE                                0x52455620U
/** @} */
#define I2C_REV_KEY__TYPE                                              uint32_t
#define I2C_REV_KEY__READ                                           0xffffffffU
#define I2C_REV_KEY__PRESERVED                                      0x00000000U
#define I2C_REV_KEY__RESET_VALUE                                    0x52455620U

#endif /* __I2C_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_I2C_REGS_CORE */
#endif /* __REG_AT_APB_I2C_REGS_CORE_H__ */
