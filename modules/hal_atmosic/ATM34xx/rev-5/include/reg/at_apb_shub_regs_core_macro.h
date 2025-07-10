/*                                                                           */
/* File:       at_apb_shub_regs_core_macro.h                                 */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_shub_regs_core.rdl          */
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


#ifndef __REG_AT_APB_SHUB_REGS_CORE_H__
#define __REG_AT_APB_SHUB_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_SHUB_REGS_CORE at_apb_shub_regs_core
 * @ingroup AT_REG
 * @brief at_apb_shub_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::SHUB_setup0 */
/**
 * @defgroup at_apb_shub_regs_core_setup0 setup0
 * @brief Contains register fields associated with setup0. definitions.
 * @{
 */
#ifndef __SHUB_SETUP0_MACRO__
#define __SHUB_SETUP0_MACRO__

/* macros for field go */
/**
 * @defgroup at_apb_shub_regs_core_go_field go_field
 * @brief macros for field go
 * @details not self reseting
 * @{
 */
#define SHUB_SETUP0__GO__SHIFT                                                0
#define SHUB_SETUP0__GO__WIDTH                                                1
#define SHUB_SETUP0__GO__MASK                                       0x00000001U
#define SHUB_SETUP0__GO__READ(src)              ((uint32_t)(src) & 0x00000001U)
#define SHUB_SETUP0__GO__WRITE(src)             ((uint32_t)(src) & 0x00000001U)
#define SHUB_SETUP0__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_SETUP0__GO__VERIFY(src)      (!(((uint32_t)(src) & ~0x00000001U)))
#define SHUB_SETUP0__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_SETUP0__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_SETUP0__GO__RESET_VALUE                                0x00000000U
/** @} */

/* macros for field breakout */
/**
 * @defgroup at_apb_shub_regs_core_breakout_field breakout_field
 * @brief macros for field breakout
 * @details useful for testing
 * @{
 */
#define SHUB_SETUP0__BREAKOUT__SHIFT                                          1
#define SHUB_SETUP0__BREAKOUT__WIDTH                                          1
#define SHUB_SETUP0__BREAKOUT__MASK                                 0x00000002U
#define SHUB_SETUP0__BREAKOUT__READ(src) (((uint32_t)(src) & 0x00000002U) >> 1)
#define SHUB_SETUP0__BREAKOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SHUB_SETUP0__BREAKOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SHUB_SETUP0__BREAKOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SHUB_SETUP0__BREAKOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SHUB_SETUP0__BREAKOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SHUB_SETUP0__BREAKOUT__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field store_in_sram */
/**
 * @defgroup at_apb_shub_regs_core_store_in_sram_field store_in_sram_field
 * @brief macros for field store_in_sram
 * @details 0=data gets stored in flash, 1=data gets stored in SRAM
 * @{
 */
#define SHUB_SETUP0__STORE_IN_SRAM__SHIFT                                     2
#define SHUB_SETUP0__STORE_IN_SRAM__WIDTH                                     1
#define SHUB_SETUP0__STORE_IN_SRAM__MASK                            0x00000004U
#define SHUB_SETUP0__STORE_IN_SRAM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define SHUB_SETUP0__STORE_IN_SRAM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define SHUB_SETUP0__STORE_IN_SRAM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define SHUB_SETUP0__STORE_IN_SRAM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define SHUB_SETUP0__STORE_IN_SRAM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define SHUB_SETUP0__STORE_IN_SRAM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define SHUB_SETUP0__STORE_IN_SRAM__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field adv_mode */
/**
 * @defgroup at_apb_shub_regs_core_adv_mode_field adv_mode_field
 * @brief macros for field adv_mode
 * @details 1=sensor hub's cpu enabled.
 * @{
 */
#define SHUB_SETUP0__ADV_MODE__SHIFT                                          3
#define SHUB_SETUP0__ADV_MODE__WIDTH                                          1
#define SHUB_SETUP0__ADV_MODE__MASK                                 0x00000008U
#define SHUB_SETUP0__ADV_MODE__READ(src) (((uint32_t)(src) & 0x00000008U) >> 3)
#define SHUB_SETUP0__ADV_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define SHUB_SETUP0__ADV_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define SHUB_SETUP0__ADV_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define SHUB_SETUP0__ADV_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define SHUB_SETUP0__ADV_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define SHUB_SETUP0__ADV_MODE__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field shub_trig_mode */
/**
 * @defgroup at_apb_shub_regs_core_shub_trig_mode_field shub_trig_mode_field
 * @brief macros for field shub_trig_mode
 * @details 0=continuous mode 1=trigger mode.
 * @{
 */
#define SHUB_SETUP0__SHUB_TRIG_MODE__SHIFT                                    4
#define SHUB_SETUP0__SHUB_TRIG_MODE__WIDTH                                    1
#define SHUB_SETUP0__SHUB_TRIG_MODE__MASK                           0x00000010U
#define SHUB_SETUP0__SHUB_TRIG_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define SHUB_SETUP0__SHUB_TRIG_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define SHUB_SETUP0__SHUB_TRIG_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define SHUB_SETUP0__SHUB_TRIG_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define SHUB_SETUP0__SHUB_TRIG_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define SHUB_SETUP0__SHUB_TRIG_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define SHUB_SETUP0__SHUB_TRIG_MODE__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field shub_disable */
/**
 * @defgroup at_apb_shub_regs_core_shub_disable_field shub_disable_field
 * @brief macros for field shub_disable
 * @details 0=enable sensor hub.
 * @{
 */
#define SHUB_SETUP0__SHUB_DISABLE__SHIFT                                      5
#define SHUB_SETUP0__SHUB_DISABLE__WIDTH                                      1
#define SHUB_SETUP0__SHUB_DISABLE__MASK                             0x00000020U
#define SHUB_SETUP0__SHUB_DISABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define SHUB_SETUP0__SHUB_DISABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define SHUB_SETUP0__SHUB_DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define SHUB_SETUP0__SHUB_DISABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define SHUB_SETUP0__SHUB_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define SHUB_SETUP0__SHUB_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define SHUB_SETUP0__SHUB_DISABLE__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field clr_sensor_cntr_mode */
/**
 * @defgroup at_apb_shub_regs_core_clr_sensor_cntr_mode_field clr_sensor_cntr_mode_field
 * @brief macros for field clr_sensor_cntr_mode
 * @details 1= clear internal sensor counters at each FSM restart. 0= the sensor counters is only cleared by core reset
 * @{
 */
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__SHIFT                              6
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__WIDTH                              1
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__MASK                     0x00000040U
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define SHUB_SETUP0__CLR_SENSOR_CNTR_MODE__RESET_VALUE              0x00000001U
/** @} */

/* macros for field enable_round_limit */
/**
 * @defgroup at_apb_shub_regs_core_enable_round_limit_field enable_round_limit_field
 * @brief macros for field enable_round_limit
 * @details 1=exit when the number of rounds is equal to round_limit
 * @{
 */
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__SHIFT                                7
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__WIDTH                                1
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__MASK                       0x00000080U
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define SHUB_SETUP0__ENABLE_ROUND_LIMIT__RESET_VALUE                0x00000000U
/** @} */
#define SHUB_SETUP0__TYPE                                              uint32_t
#define SHUB_SETUP0__READ                                           0x000000ffU
#define SHUB_SETUP0__WRITE                                          0x000000ffU
#define SHUB_SETUP0__PRESERVED                                      0x00000000U
#define SHUB_SETUP0__RESET_VALUE                                    0x00000040U

#endif /* __SHUB_SETUP0_MACRO__ */

/** @} end of setup0 */

/* macros for BlueprintGlobalNameSpace::SHUB_setup1 */
/**
 * @defgroup at_apb_shub_regs_core_setup1 setup1
 * @brief Contains register fields associated with setup1. definitions.
 * @{
 */
#ifndef __SHUB_SETUP1_MACRO__
#define __SHUB_SETUP1_MACRO__

/* macros for field loop_time */
/**
 * @defgroup at_apb_shub_regs_core_loop_time_field loop_time_field
 * @brief macros for field loop_time
 * @details how long should each iteration (sensor read and flash write) be ? (800 = wr_delay*2 + 16bytes read + overhead). The multiplier of 2 is needed beause when there are mulitple data bytes straddling the page boundary, the shub issues the page program twice. The first one sends all bytes up to the at the page boundary, and the second sends the rest of the data bytes.
 * @{
 */
#define SHUB_SETUP1__LOOP_TIME__SHIFT                                         0
#define SHUB_SETUP1__LOOP_TIME__WIDTH                                        32
#define SHUB_SETUP1__LOOP_TIME__MASK                                0xffffffffU
#define SHUB_SETUP1__LOOP_TIME__READ(src)       ((uint32_t)(src) & 0xffffffffU)
#define SHUB_SETUP1__LOOP_TIME__WRITE(src)      ((uint32_t)(src) & 0xffffffffU)
#define SHUB_SETUP1__LOOP_TIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_SETUP1__LOOP_TIME__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_SETUP1__LOOP_TIME__RESET_VALUE                         0x00003fffU
/** @} */
#define SHUB_SETUP1__TYPE                                              uint32_t
#define SHUB_SETUP1__READ                                           0xffffffffU
#define SHUB_SETUP1__WRITE                                          0xffffffffU
#define SHUB_SETUP1__PRESERVED                                      0xffffffffU
#define SHUB_SETUP1__RESET_VALUE                                    0x00003fffU

#endif /* __SHUB_SETUP1_MACRO__ */

/** @} end of setup1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_setup port0_setup
 * @brief Contains register fields associated with port0_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SETUP_MACRO__
#define __SHUB_PORT0_SETUP_MACRO__

/* macros for field port_en */
/**
 * @defgroup at_apb_shub_regs_core_port_en_field port_en_field
 * @brief macros for field port_en
 * @{
 */
#define SHUB_PORT0_SETUP__PORT_EN__SHIFT                                      0
#define SHUB_PORT0_SETUP__PORT_EN__WIDTH                                      1
#define SHUB_PORT0_SETUP__PORT_EN__MASK                             0x00000001U
#define SHUB_PORT0_SETUP__PORT_EN__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define SHUB_PORT0_SETUP__PORT_EN__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define SHUB_PORT0_SETUP__PORT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_SETUP__PORT_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_SETUP__PORT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_SETUP__PORT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_SETUP__PORT_EN__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field spi_n_i2c */
/**
 * @defgroup at_apb_shub_regs_core_spi_n_i2c_field spi_n_i2c_field
 * @brief macros for field spi_n_i2c
 * @details 1= use spi for port0, 0= use i2c
 * @{
 */
#define SHUB_PORT0_SETUP__SPI_N_I2C__SHIFT                                    1
#define SHUB_PORT0_SETUP__SPI_N_I2C__WIDTH                                    1
#define SHUB_PORT0_SETUP__SPI_N_I2C__MASK                           0x00000002U
#define SHUB_PORT0_SETUP__SPI_N_I2C__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SHUB_PORT0_SETUP__SPI_N_I2C__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SHUB_PORT0_SETUP__SPI_N_I2C__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SHUB_PORT0_SETUP__SPI_N_I2C__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SHUB_PORT0_SETUP__SPI_N_I2C__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SHUB_PORT0_SETUP__SPI_N_I2C__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SHUB_PORT0_SETUP__SPI_N_I2C__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field num_sensors */
/**
 * @defgroup at_apb_shub_regs_core_num_sensors_field num_sensors_field
 * @brief macros for field num_sensors
 * @details number of sensors connected to port = num_sensors + 1
 * @{
 */
#define SHUB_PORT0_SETUP__NUM_SENSORS__SHIFT                                  4
#define SHUB_PORT0_SETUP__NUM_SENSORS__WIDTH                                  3
#define SHUB_PORT0_SETUP__NUM_SENSORS__MASK                         0x00000070U
#define SHUB_PORT0_SETUP__NUM_SENSORS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define SHUB_PORT0_SETUP__NUM_SENSORS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define SHUB_PORT0_SETUP__NUM_SENSORS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define SHUB_PORT0_SETUP__NUM_SENSORS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define SHUB_PORT0_SETUP__NUM_SENSORS__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field trig_en */
/**
 * @defgroup at_apb_shub_regs_core_trig_en_field trig_en_field
 * @brief macros for field trig_en
 * @details 1= enable threshold comparison with measurement results.
 * @{
 */
#define SHUB_PORT0_SETUP__TRIG_EN__SHIFT                                     11
#define SHUB_PORT0_SETUP__TRIG_EN__WIDTH                                      1
#define SHUB_PORT0_SETUP__TRIG_EN__MASK                             0x00000800U
#define SHUB_PORT0_SETUP__TRIG_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define SHUB_PORT0_SETUP__TRIG_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define SHUB_PORT0_SETUP__TRIG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define SHUB_PORT0_SETUP__TRIG_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define SHUB_PORT0_SETUP__TRIG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define SHUB_PORT0_SETUP__TRIG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define SHUB_PORT0_SETUP__TRIG_EN__RESET_VALUE                      0x00000000U
/** @} */
#define SHUB_PORT0_SETUP__TYPE                                         uint32_t
#define SHUB_PORT0_SETUP__READ                                      0x00000873U
#define SHUB_PORT0_SETUP__WRITE                                     0x00000873U
#define SHUB_PORT0_SETUP__PRESERVED                                 0x00000873U
#define SHUB_PORT0_SETUP__RESET_VALUE                               0x00000000U

#endif /* __SHUB_PORT0_SETUP_MACRO__ */

/** @} end of port0_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor0_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor0_setup port0_sensor0_setup
 * @brief Contains register fields associated with port0_sensor0_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR0_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR0_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR0_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR0_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR0_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR0_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR0_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR0_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR0_SETUP_MACRO__ */

/** @} end of port0_sensor0_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor1_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor1_setup port0_sensor1_setup
 * @brief Contains register fields associated with port0_sensor1_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR1_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR1_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR1_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR1_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR1_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR1_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR1_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR1_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR1_SETUP_MACRO__ */

/** @} end of port0_sensor1_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor2_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor2_setup port0_sensor2_setup
 * @brief Contains register fields associated with port0_sensor2_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR2_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR2_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR2_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR2_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR2_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR2_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR2_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR2_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR2_SETUP_MACRO__ */

/** @} end of port0_sensor2_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor3_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor3_setup port0_sensor3_setup
 * @brief Contains register fields associated with port0_sensor3_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR3_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR3_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR3_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR3_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR3_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR3_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR3_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR3_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR3_SETUP_MACRO__ */

/** @} end of port0_sensor3_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor4_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor4_setup port0_sensor4_setup
 * @brief Contains register fields associated with port0_sensor4_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR4_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR4_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR4_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR4_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR4_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR4_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR4_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR4_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR4_SETUP_MACRO__ */

/** @} end of port0_sensor4_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor5_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor5_setup port0_sensor5_setup
 * @brief Contains register fields associated with port0_sensor5_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR5_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR5_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR5_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR5_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR5_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR5_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR5_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR5_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR5_SETUP_MACRO__ */

/** @} end of port0_sensor5_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor6_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor6_setup port0_sensor6_setup
 * @brief Contains register fields associated with port0_sensor6_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR6_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR6_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR6_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR6_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR6_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR6_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR6_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR6_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR6_SETUP_MACRO__ */

/** @} end of port0_sensor6_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_sensor7_setup */
/**
 * @defgroup at_apb_shub_regs_core_port0_sensor7_setup port0_sensor7_setup
 * @brief Contains register fields associated with port0_sensor7_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SENSOR7_SETUP_MACRO__
#define __SHUB_PORT0_SENSOR7_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_SENSOR7_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT0_SENSOR7_SETUP__TYPE                                 uint32_t
#define SHUB_PORT0_SENSOR7_SETUP__READ                              0x0000001fU
#define SHUB_PORT0_SENSOR7_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT0_SENSOR7_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT0_SENSOR7_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT0_SENSOR7_SETUP_MACRO__ */

/** @} end of port0_sensor7_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_spi_eng0_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port0_spi_eng0_ctrl port0_spi_eng0_ctrl
 * @brief Contains register fields associated with port0_spi_eng0_ctrl. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_SPI_ENG0_CTRL_MACRO__
#define __SHUB_PORT0_SPI_ENG0_CTRL_MACRO__

/* macros for field sensor_opcode */
/**
 * @defgroup at_apb_shub_regs_core_sensor_opcode_field sensor_opcode_field
 * @brief macros for field sensor_opcode
 * @details opcode used to communicate with sensor in spi mode
 * @{
 */
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__SHIFT                        0
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__WIDTH                        8
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__MASK               0x000000ffU
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SHUB_PORT0_SPI_ENG0_CTRL__SENSOR_OPCODE__RESET_VALUE        0x00000000U
/** @} */

/* macros for field cpha */
/**
 * @defgroup at_apb_shub_regs_core_cpha_field cpha_field
 * @brief macros for field cpha
 * @details spi clcok phase mode
 * @{
 */
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__SHIFT                                30
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__WIDTH                                 1
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__MASK                        0x40000000U
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPHA__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field cpol */
/**
 * @defgroup at_apb_shub_regs_core_cpol_field cpol_field
 * @brief macros for field cpol
 * @details spi clock polarity mode. 0 = posedge-sensitive, 1 = negedge
 * @{
 */
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__SHIFT                                31
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__WIDTH                                 1
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__MASK                        0x80000000U
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SHUB_PORT0_SPI_ENG0_CTRL__CPOL__RESET_VALUE                 0x00000000U
/** @} */
#define SHUB_PORT0_SPI_ENG0_CTRL__TYPE                                 uint32_t
#define SHUB_PORT0_SPI_ENG0_CTRL__READ                              0xc00000ffU
#define SHUB_PORT0_SPI_ENG0_CTRL__WRITE                             0xc00000ffU
#define SHUB_PORT0_SPI_ENG0_CTRL__PRESERVED                         0xc00000ffU
#define SHUB_PORT0_SPI_ENG0_CTRL__RESET_VALUE                       0x00000000U

#endif /* __SHUB_PORT0_SPI_ENG0_CTRL_MACRO__ */

/** @} end of port0_spi_eng0_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_0 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_0 port0_i2c_idw_0
 * @brief id(read) of sensor0 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_0_MACRO__
#define __SHUB_PORT0_I2C_IDW_0_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_0__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_0__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_0__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_0__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_0__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_0__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_0__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_0_MACRO__ */

/** @} end of port0_i2c_idw_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_1 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_1 port0_i2c_idw_1
 * @brief id(read) of sensor1 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_1_MACRO__
#define __SHUB_PORT0_I2C_IDW_1_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_1__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_1__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_1__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_1__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_1__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_1__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_1__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_1__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_1__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_1_MACRO__ */

/** @} end of port0_i2c_idw_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_2 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_2 port0_i2c_idw_2
 * @brief id(read) of sensor2 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_2_MACRO__
#define __SHUB_PORT0_I2C_IDW_2_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_2__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_2__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_2__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_2__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_2__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_2__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_2__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_2__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_2__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_2_MACRO__ */

/** @} end of port0_i2c_idw_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_3 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_3 port0_i2c_idw_3
 * @brief id(read) of sensor3 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_3_MACRO__
#define __SHUB_PORT0_I2C_IDW_3_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_3__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_3__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_3__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_3__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_3__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_3__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_3__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_3__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_3__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_3_MACRO__ */

/** @} end of port0_i2c_idw_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_4 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_4 port0_i2c_idw_4
 * @brief id(read) of sensor4 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_4_MACRO__
#define __SHUB_PORT0_I2C_IDW_4_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_4__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_4__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_4__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_4__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_4__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_4__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_4__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_4__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_4__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_4_MACRO__ */

/** @} end of port0_i2c_idw_4 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_5 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_5 port0_i2c_idw_5
 * @brief id(read) of sensor5 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_5_MACRO__
#define __SHUB_PORT0_I2C_IDW_5_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_5__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_5__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_5__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_5__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_5__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_5__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_5__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_5__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_5__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_5_MACRO__ */

/** @} end of port0_i2c_idw_5 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_6 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_6 port0_i2c_idw_6
 * @brief id(read) of sensor6 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_6_MACRO__
#define __SHUB_PORT0_I2C_IDW_6_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_6__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_6__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_6__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_6__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_6__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_6__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_6__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_6__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_6__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_6_MACRO__ */

/** @} end of port0_i2c_idw_6 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idw_7 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idw_7 port0_i2c_idw_7
 * @brief id(read) of sensor7 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDW_7_MACRO__
#define __SHUB_PORT0_I2C_IDW_7_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDW_7__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDW_7__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDW_7__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDW_7__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDW_7__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDW_7__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDW_7__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDW_7__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDW_7__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDW_7_MACRO__ */

/** @} end of port0_i2c_idw_7 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_0 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_0 port0_i2c_addr_0
 * @brief pointer addr of sensor0 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_0_MACRO__
#define __SHUB_PORT0_I2C_ADDR_0_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_0__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_0__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_0__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_0__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_0__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_0__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_0__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_0_MACRO__ */

/** @} end of port0_i2c_addr_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_1 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_1 port0_i2c_addr_1
 * @brief pointer addr of sensor1 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_1_MACRO__
#define __SHUB_PORT0_I2C_ADDR_1_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_1__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_1__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_1__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_1__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_1__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_1__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_1__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_1__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_1__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_1_MACRO__ */

/** @} end of port0_i2c_addr_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_2 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_2 port0_i2c_addr_2
 * @brief pointer addr of sensor2 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_2_MACRO__
#define __SHUB_PORT0_I2C_ADDR_2_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_2__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_2__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_2__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_2__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_2__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_2__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_2__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_2__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_2__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_2_MACRO__ */

/** @} end of port0_i2c_addr_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_3 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_3 port0_i2c_addr_3
 * @brief pointer addr of sensor3 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_3_MACRO__
#define __SHUB_PORT0_I2C_ADDR_3_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_3__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_3__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_3__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_3__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_3__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_3__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_3__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_3__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_3__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_3_MACRO__ */

/** @} end of port0_i2c_addr_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_4 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_4 port0_i2c_addr_4
 * @brief pointer addr of sensor4 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_4_MACRO__
#define __SHUB_PORT0_I2C_ADDR_4_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_4__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_4__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_4__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_4__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_4__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_4__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_4__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_4__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_4__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_4_MACRO__ */

/** @} end of port0_i2c_addr_4 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_5 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_5 port0_i2c_addr_5
 * @brief pointer addr of sensor5 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_5_MACRO__
#define __SHUB_PORT0_I2C_ADDR_5_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_5__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_5__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_5__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_5__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_5__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_5__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_5__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_5__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_5__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_5_MACRO__ */

/** @} end of port0_i2c_addr_5 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_6 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_6 port0_i2c_addr_6
 * @brief pointer addr of sensor6 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_6_MACRO__
#define __SHUB_PORT0_I2C_ADDR_6_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_6__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_6__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_6__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_6__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_6__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_6__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_6__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_6__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_6__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_6_MACRO__ */

/** @} end of port0_i2c_addr_6 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_addr_7 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_addr_7 port0_i2c_addr_7
 * @brief pointer addr of sensor7 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_ADDR_7_MACRO__
#define __SHUB_PORT0_I2C_ADDR_7_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_ADDR_7__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_ADDR_7__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__SHIFT                               19
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__SHIFT                               21
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__WIDTH                                2
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_ADDR_7__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_ADDR_7__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_I2C_ADDR_7__TYPE                                    uint32_t
#define SHUB_PORT0_I2C_ADDR_7__READ                                 0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_7__WRITE                                0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_7__PRESERVED                            0x01ffffffU
#define SHUB_PORT0_I2C_ADDR_7__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT0_I2C_ADDR_7_MACRO__ */

/** @} end of port0_i2c_addr_7 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_0 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_0 port0_i2c_idr_0
 * @brief id(read) of sensor0 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_0_MACRO__
#define __SHUB_PORT0_I2C_IDR_0_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_0__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_0__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_0__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_0__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_0__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_0__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_0__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_0_MACRO__ */

/** @} end of port0_i2c_idr_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_1 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_1 port0_i2c_idr_1
 * @brief id(read) of sensor1 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_1_MACRO__
#define __SHUB_PORT0_I2C_IDR_1_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_1__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_1__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_1__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_1__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_1__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_1__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_1__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_1__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_1__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_1_MACRO__ */

/** @} end of port0_i2c_idr_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_2 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_2 port0_i2c_idr_2
 * @brief id(read) of sensor2 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_2_MACRO__
#define __SHUB_PORT0_I2C_IDR_2_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_2__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_2__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_2__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_2__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_2__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_2__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_2__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_2__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_2__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_2_MACRO__ */

/** @} end of port0_i2c_idr_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_3 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_3 port0_i2c_idr_3
 * @brief id(read) of sensor3 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_3_MACRO__
#define __SHUB_PORT0_I2C_IDR_3_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_3__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_3__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_3__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_3__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_3__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_3__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_3__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_3__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_3__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_3_MACRO__ */

/** @} end of port0_i2c_idr_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_4 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_4 port0_i2c_idr_4
 * @brief id(read) of sensor4 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_4_MACRO__
#define __SHUB_PORT0_I2C_IDR_4_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_4__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_4__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_4__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_4__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_4__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_4__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_4__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_4__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_4__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_4_MACRO__ */

/** @} end of port0_i2c_idr_4 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_5 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_5 port0_i2c_idr_5
 * @brief id(read) of sensor5 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_5_MACRO__
#define __SHUB_PORT0_I2C_IDR_5_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_5__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_5__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_5__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_5__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_5__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_5__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_5__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_5__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_5__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_5_MACRO__ */

/** @} end of port0_i2c_idr_5 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_6 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_6 port0_i2c_idr_6
 * @brief id(read) of sensor6 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_6_MACRO__
#define __SHUB_PORT0_I2C_IDR_6_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_6__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_6__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_6__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_6__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_6__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_6__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_6__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_6__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_6__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_6_MACRO__ */

/** @} end of port0_i2c_idr_6 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_idr_7 */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_idr_7 port0_i2c_idr_7
 * @brief id(read) of sensor7 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_IDR_7_MACRO__
#define __SHUB_PORT0_I2C_IDR_7_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_IDR_7__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_IDR_7__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__SHIFT                                19
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__SHIFT                                21
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_IDR_7__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_IDR_7__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_I2C_IDR_7__TYPE                                     uint32_t
#define SHUB_PORT0_I2C_IDR_7__READ                                  0x01ffffffU
#define SHUB_PORT0_I2C_IDR_7__WRITE                                 0x01ffffffU
#define SHUB_PORT0_I2C_IDR_7__PRESERVED                             0x01ffffffU
#define SHUB_PORT0_I2C_IDR_7__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT0_I2C_IDR_7_MACRO__ */

/** @} end of port0_i2c_idr_7 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_dat_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_dat_ctrl port0_i2c_dat_ctrl
 * @brief slave(port0) data byte read (used in not the last byte) definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_DAT_CTRL_MACRO__
#define __SHUB_PORT0_I2C_DAT_CTRL_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__SHIFT                      0
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__WIDTH                      1
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__MASK             0x00000001U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__SHIFT                            1
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__WIDTH                            8
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__MASK                   0x000001feU
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_O__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__SHIFT                           9
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__WIDTH                           8
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__MASK                  0x0001fe00U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_OE__RESET_VALUE           0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__SHIFT                          17
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__WIDTH                           1
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__MASK                  0x00020000U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_DATA_PU__RESET_VALUE           0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__SHIFT                           18
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__WIDTH                            1
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__MASK                   0x00040000U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_CLK_PU__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__SHIFT                             19
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__WIDTH                              2
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__MASK                     0x00180000U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_HEAD__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__SHIFT                             21
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__WIDTH                              2
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__MASK                     0x00600000U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_TAIL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__SHIFT                23
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__WIDTH                 1
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__MASK        0x00800000U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__RESET_VALUE 0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__SHIFT               24
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__WIDTH                1
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__MASK       0x01000000U
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE \
                    0x00000000U
/** @} */
#define SHUB_PORT0_I2C_DAT_CTRL__TYPE                                  uint32_t
#define SHUB_PORT0_I2C_DAT_CTRL__READ                               0x01ffffffU
#define SHUB_PORT0_I2C_DAT_CTRL__WRITE                              0x01ffffffU
#define SHUB_PORT0_I2C_DAT_CTRL__PRESERVED                          0x01ffffffU
#define SHUB_PORT0_I2C_DAT_CTRL__RESET_VALUE                        0x0001fe00U

#endif /* __SHUB_PORT0_I2C_DAT_CTRL_MACRO__ */

/** @} end of port0_i2c_dat_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_i2c_dat_last_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port0_i2c_dat_last_ctrl port0_i2c_dat_last_ctrl
 * @brief slave(port0) data byte read (used in the last byte) definitions.
 * @{
 */
#ifndef __SHUB_PORT0_I2C_DAT_LAST_CTRL_MACRO__
#define __SHUB_PORT0_I2C_DAT_LAST_CTRL_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__SHIFT                 0
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__WIDTH                 1
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__MASK        0x00000001U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__RESET_VALUE 0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__SHIFT                       1
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__WIDTH                       8
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__MASK              0x000001feU
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_O__RESET_VALUE       0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__SHIFT                      9
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__WIDTH                      8
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__MASK             0x0001fe00U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_OE__RESET_VALUE      0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__SHIFT                     17
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__WIDTH                      1
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__MASK             0x00020000U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_DATA_PU__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__SHIFT                      18
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__WIDTH                       1
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__MASK              0x00040000U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_CLK_PU__RESET_VALUE       0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__SHIFT                        19
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__WIDTH                         2
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__MASK                0x00180000U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_HEAD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__SHIFT                        21
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__WIDTH                         2
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__MASK                0x00600000U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_TAIL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__SHIFT           23
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__WIDTH            1
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__MASK   0x00800000U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__SHIFT          24
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__WIDTH           1
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__MASK  0x01000000U
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE \
                    0x00000000U
/** @} */
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__TYPE                             uint32_t
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__READ                          0x01ffffffU
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__WRITE                         0x01ffffffU
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__PRESERVED                     0x01ffffffU
#define SHUB_PORT0_I2C_DAT_LAST_CTRL__RESET_VALUE                   0x0001fe00U

#endif /* __SHUB_PORT0_I2C_DAT_LAST_CTRL_MACRO__ */

/** @} end of port0_i2c_dat_last_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_quan_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_quan_ctrl port0_alm0_quan_ctrl
 * @brief alarm0 quantity's definition definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_QUAN_CTRL_MACRO__
#define __SHUB_PORT0_ALM0_QUAN_CTRL_MACRO__

/* macros for field quan0_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan0_pos_field quan0_pos_field
 * @brief macros for field quan0_pos
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__SHIFT                           0
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__WIDTH                           5
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__MASK                  0x0000001fU
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan1_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan1_pos_field quan1_pos_field
 * @brief macros for field quan1_pos
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__SHIFT                           5
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__WIDTH                           5
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__MASK                  0x000003e0U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan2_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan2_pos_field quan2_pos_field
 * @brief macros for field quan2_pos
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__SHIFT                          10
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__WIDTH                           5
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__MASK                  0x00007c00U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan3_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan3_pos_field quan3_pos_field
 * @brief macros for field quan3_pos
 * @details starting position of the quantity
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__SHIFT                          15
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__WIDTH                           5
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__MASK                  0x000f8000U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan0_size */
/**
 * @defgroup at_apb_shub_regs_core_quan0_size_field quan0_size_field
 * @brief macros for field quan0_size
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__SHIFT                         20
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__MASK                 0x00300000U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN0_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan1_size */
/**
 * @defgroup at_apb_shub_regs_core_quan1_size_field quan1_size_field
 * @brief macros for field quan1_size
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__SHIFT                         22
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__MASK                 0x00c00000U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN1_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan2_size */
/**
 * @defgroup at_apb_shub_regs_core_quan2_size_field quan2_size_field
 * @brief macros for field quan2_size
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__SHIFT                         24
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__MASK                 0x03000000U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN2_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan3_size */
/**
 * @defgroup at_apb_shub_regs_core_quan3_size_field quan3_size_field
 * @brief macros for field quan3_size
 * @details number of bytes making up the quantity data = programmed quan3_size + 1
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__SHIFT                         26
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__MASK                 0x0c000000U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN3_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field lsb_first */
/**
 * @defgroup at_apb_shub_regs_core_lsb_first_field lsb_first_field
 * @brief macros for field lsb_first
 * @details 1= quantity data is big endian ; 0= small endian
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__SHIFT                          30
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__WIDTH                           1
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__MASK                  0x40000000U
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SHUB_PORT0_ALM0_QUAN_CTRL__LSB_FIRST__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan_dat_is_signed */
/**
 * @defgroup at_apb_shub_regs_core_quan_dat_is_signed_field quan_dat_is_signed_field
 * @brief macros for field quan_dat_is_signed
 * @details quantity data is a signed data
 * @{
 */
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__SHIFT                 31
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__WIDTH                  1
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__MASK         0x80000000U
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SHUB_PORT0_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_ALM0_QUAN_CTRL__TYPE                                uint32_t
#define SHUB_PORT0_ALM0_QUAN_CTRL__READ                             0xcfffffffU
#define SHUB_PORT0_ALM0_QUAN_CTRL__WRITE                            0xcfffffffU
#define SHUB_PORT0_ALM0_QUAN_CTRL__PRESERVED                        0xcfffffffU
#define SHUB_PORT0_ALM0_QUAN_CTRL__RESET_VALUE                      0x05500000U

#endif /* __SHUB_PORT0_ALM0_QUAN_CTRL_MACRO__ */

/** @} end of port0_alm0_quan_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_quan_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_quan_ctrl port0_alm1_quan_ctrl
 * @brief alarm1 quantity's definition definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_QUAN_CTRL_MACRO__
#define __SHUB_PORT0_ALM1_QUAN_CTRL_MACRO__

/* macros for field quan0_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan0_pos_field quan0_pos_field
 * @brief macros for field quan0_pos
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__SHIFT                           0
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__WIDTH                           5
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__MASK                  0x0000001fU
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan1_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan1_pos_field quan1_pos_field
 * @brief macros for field quan1_pos
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__SHIFT                           5
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__WIDTH                           5
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__MASK                  0x000003e0U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan2_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan2_pos_field quan2_pos_field
 * @brief macros for field quan2_pos
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__SHIFT                          10
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__WIDTH                           5
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__MASK                  0x00007c00U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan3_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan3_pos_field quan3_pos_field
 * @brief macros for field quan3_pos
 * @details starting position of the quantity
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__SHIFT                          15
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__WIDTH                           5
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__MASK                  0x000f8000U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan0_size */
/**
 * @defgroup at_apb_shub_regs_core_quan0_size_field quan0_size_field
 * @brief macros for field quan0_size
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__SHIFT                         20
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__MASK                 0x00300000U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN0_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan1_size */
/**
 * @defgroup at_apb_shub_regs_core_quan1_size_field quan1_size_field
 * @brief macros for field quan1_size
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__SHIFT                         22
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__MASK                 0x00c00000U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN1_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan2_size */
/**
 * @defgroup at_apb_shub_regs_core_quan2_size_field quan2_size_field
 * @brief macros for field quan2_size
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__SHIFT                         24
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__MASK                 0x03000000U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN2_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan3_size */
/**
 * @defgroup at_apb_shub_regs_core_quan3_size_field quan3_size_field
 * @brief macros for field quan3_size
 * @details number of bytes making up the quantity data = programmed quan3_size + 1
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__SHIFT                         26
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__WIDTH                          2
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__MASK                 0x0c000000U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN3_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field lsb_first */
/**
 * @defgroup at_apb_shub_regs_core_lsb_first_field lsb_first_field
 * @brief macros for field lsb_first
 * @details 1= quantity data is big endian ; 0= small endian
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__SHIFT                          30
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__WIDTH                           1
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__MASK                  0x40000000U
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SHUB_PORT0_ALM1_QUAN_CTRL__LSB_FIRST__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan_dat_is_signed */
/**
 * @defgroup at_apb_shub_regs_core_quan_dat_is_signed_field quan_dat_is_signed_field
 * @brief macros for field quan_dat_is_signed
 * @details quantity data is a signed data
 * @{
 */
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__SHIFT                 31
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__WIDTH                  1
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__MASK         0x80000000U
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SHUB_PORT0_ALM1_QUAN_CTRL__QUAN_DAT_IS_SIGNED__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT0_ALM1_QUAN_CTRL__TYPE                                uint32_t
#define SHUB_PORT0_ALM1_QUAN_CTRL__READ                             0xcfffffffU
#define SHUB_PORT0_ALM1_QUAN_CTRL__WRITE                            0xcfffffffU
#define SHUB_PORT0_ALM1_QUAN_CTRL__PRESERVED                        0xcfffffffU
#define SHUB_PORT0_ALM1_QUAN_CTRL__RESET_VALUE                      0x05500000U

#endif /* __SHUB_PORT0_ALM1_QUAN_CTRL_MACRO__ */

/** @} end of port0_alm1_quan_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_trig_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_trig_ctrl port0_alm0_trig_ctrl
 * @brief alarm0 trigger function: trigger = trig_func_en( out_of_range(quan3), out_of_range(quan2),out_of_range(quan1),out_of_range(quan0)) definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_TRIG_CTRL_MACRO__
#define __SHUB_PORT0_ALM0_TRIG_CTRL_MACRO__

/* macros for field trig_func_en */
/**
 * @defgroup at_apb_shub_regs_core_trig_func_en_field trig_func_en_field
 * @brief macros for field trig_func_en
 * @{
 */
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__SHIFT                        0
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__WIDTH                       16
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__MASK               0x0000ffffU
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define SHUB_PORT0_ALM0_TRIG_CTRL__TRIG_FUNC_EN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field out_of_range_mask */
/**
 * @defgroup at_apb_shub_regs_core_out_of_range_mask_field out_of_range_mask_field
 * @brief macros for field out_of_range_mask
 * @details mask out out_of_range bits
 * @{
 */
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__SHIFT                  16
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__WIDTH                   4
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__MASK          0x000f0000U
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define SHUB_PORT0_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM0_TRIG_CTRL__TYPE                                uint32_t
#define SHUB_PORT0_ALM0_TRIG_CTRL__READ                             0x000fffffU
#define SHUB_PORT0_ALM0_TRIG_CTRL__WRITE                            0x000fffffU
#define SHUB_PORT0_ALM0_TRIG_CTRL__PRESERVED                        0x000fffffU
#define SHUB_PORT0_ALM0_TRIG_CTRL__RESET_VALUE                      0x00000000U

#endif /* __SHUB_PORT0_ALM0_TRIG_CTRL_MACRO__ */

/** @} end of port0_alm0_trig_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_trig_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_trig_ctrl port0_alm1_trig_ctrl
 * @brief alarm1 trigger function: trigger = trig_func_en( out_of_range(quan3), out_of_range(quan2),out_of_range(quan1),out_of_range(quan0)) definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_TRIG_CTRL_MACRO__
#define __SHUB_PORT0_ALM1_TRIG_CTRL_MACRO__

/* macros for field trig_func_en */
/**
 * @defgroup at_apb_shub_regs_core_trig_func_en_field trig_func_en_field
 * @brief macros for field trig_func_en
 * @{
 */
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__SHIFT                        0
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__WIDTH                       16
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__MASK               0x0000ffffU
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define SHUB_PORT0_ALM1_TRIG_CTRL__TRIG_FUNC_EN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field out_of_range_mask */
/**
 * @defgroup at_apb_shub_regs_core_out_of_range_mask_field out_of_range_mask_field
 * @brief macros for field out_of_range_mask
 * @details mask out out_of_range bits
 * @{
 */
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__SHIFT                  16
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__WIDTH                   4
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__MASK          0x000f0000U
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define SHUB_PORT0_ALM1_TRIG_CTRL__OUT_OF_RANGE_MASK__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM1_TRIG_CTRL__TYPE                                uint32_t
#define SHUB_PORT0_ALM1_TRIG_CTRL__READ                             0x000fffffU
#define SHUB_PORT0_ALM1_TRIG_CTRL__WRITE                            0x000fffffU
#define SHUB_PORT0_ALM1_TRIG_CTRL__PRESERVED                        0x000fffffU
#define SHUB_PORT0_ALM1_TRIG_CTRL__RESET_VALUE                      0x00000000U

#endif /* __SHUB_PORT0_ALM1_TRIG_CTRL_MACRO__ */

/** @} end of port0_alm1_trig_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_max_0 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_max_0 port0_alm0_thrhld_max_0
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MAX_0_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MAX_0_MACRO__

/* macros for field threshold_max0 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max0_field threshold_max0_field
 * @brief macros for field threshold_max0
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_0__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM0_THRHLD_MAX_0_MACRO__ */

/** @} end of port0_alm0_thrhld_max_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_max_1 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_max_1 port0_alm0_thrhld_max_1
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MAX_1_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MAX_1_MACRO__

/* macros for field threshold_max1 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max1_field threshold_max1_field
 * @brief macros for field threshold_max1
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_1__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM0_THRHLD_MAX_1_MACRO__ */

/** @} end of port0_alm0_thrhld_max_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_max_2 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_max_2 port0_alm0_thrhld_max_2
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MAX_2_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MAX_2_MACRO__

/* macros for field threshold_max2 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max2_field threshold_max2_field
 * @brief macros for field threshold_max2
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_2__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM0_THRHLD_MAX_2_MACRO__ */

/** @} end of port0_alm0_thrhld_max_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_max_3 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_max_3 port0_alm0_thrhld_max_3
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MAX_3_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MAX_3_MACRO__

/* macros for field threshold_max3 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max3_field threshold_max3_field
 * @brief macros for field threshold_max3
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MAX_3__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM0_THRHLD_MAX_3_MACRO__ */

/** @} end of port0_alm0_thrhld_max_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_min_0 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_min_0 port0_alm0_thrhld_min_0
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MIN_0_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MIN_0_MACRO__

/* macros for field threshold_min0 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min0_field threshold_min0_field
 * @brief macros for field threshold_min0
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_0__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM0_THRHLD_MIN_0_MACRO__ */

/** @} end of port0_alm0_thrhld_min_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_min_1 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_min_1 port0_alm0_thrhld_min_1
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MIN_1_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MIN_1_MACRO__

/* macros for field threshold_min1 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min1_field threshold_min1_field
 * @brief macros for field threshold_min1
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_1__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM0_THRHLD_MIN_1_MACRO__ */

/** @} end of port0_alm0_thrhld_min_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_min_2 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_min_2 port0_alm0_thrhld_min_2
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MIN_2_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MIN_2_MACRO__

/* macros for field threshold_min2 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min2_field threshold_min2_field
 * @brief macros for field threshold_min2
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_2__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM0_THRHLD_MIN_2_MACRO__ */

/** @} end of port0_alm0_thrhld_min_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm0_thrhld_min_3 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm0_thrhld_min_3 port0_alm0_thrhld_min_3
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM0_THRHLD_MIN_3_MACRO__
#define __SHUB_PORT0_ALM0_THRHLD_MIN_3_MACRO__

/* macros for field threshold_min3 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min3_field threshold_min3_field
 * @brief macros for field threshold_min3
 * @{
 */
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__SHIFT                   0
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__WIDTH                  32
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__MASK          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__TYPE                             uint32_t
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__READ                          0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM0_THRHLD_MIN_3__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM0_THRHLD_MIN_3_MACRO__ */

/** @} end of port0_alm0_thrhld_min_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_max_0 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_max_0 port0_alm1_thrhld_max_0
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MAX_0_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MAX_0_MACRO__

/* macros for field threshold_max0 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max0_field threshold_max0_field
 * @brief macros for field threshold_max0
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__THRESHOLD_MAX0__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_0__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM1_THRHLD_MAX_0_MACRO__ */

/** @} end of port0_alm1_thrhld_max_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_max_1 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_max_1 port0_alm1_thrhld_max_1
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MAX_1_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MAX_1_MACRO__

/* macros for field threshold_max1 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max1_field threshold_max1_field
 * @brief macros for field threshold_max1
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__THRESHOLD_MAX1__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_1__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM1_THRHLD_MAX_1_MACRO__ */

/** @} end of port0_alm1_thrhld_max_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_max_2 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_max_2 port0_alm1_thrhld_max_2
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MAX_2_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MAX_2_MACRO__

/* macros for field threshold_max2 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max2_field threshold_max2_field
 * @brief macros for field threshold_max2
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__THRESHOLD_MAX2__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_2__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM1_THRHLD_MAX_2_MACRO__ */

/** @} end of port0_alm1_thrhld_max_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_max_3 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_max_3 port0_alm1_thrhld_max_3
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MAX_3_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MAX_3_MACRO__

/* macros for field threshold_max3 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max3_field threshold_max3_field
 * @brief macros for field threshold_max3
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__THRESHOLD_MAX3__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MAX_3__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT0_ALM1_THRHLD_MAX_3_MACRO__ */

/** @} end of port0_alm1_thrhld_max_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_min_0 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_min_0 port0_alm1_thrhld_min_0
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MIN_0_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MIN_0_MACRO__

/* macros for field threshold_min0 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min0_field threshold_min0_field
 * @brief macros for field threshold_min0
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__THRESHOLD_MIN0__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_0__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM1_THRHLD_MIN_0_MACRO__ */

/** @} end of port0_alm1_thrhld_min_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_min_1 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_min_1 port0_alm1_thrhld_min_1
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MIN_1_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MIN_1_MACRO__

/* macros for field threshold_min1 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min1_field threshold_min1_field
 * @brief macros for field threshold_min1
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__THRESHOLD_MIN1__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_1__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM1_THRHLD_MIN_1_MACRO__ */

/** @} end of port0_alm1_thrhld_min_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_min_2 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_min_2 port0_alm1_thrhld_min_2
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MIN_2_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MIN_2_MACRO__

/* macros for field threshold_min2 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min2_field threshold_min2_field
 * @brief macros for field threshold_min2
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__THRESHOLD_MIN2__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_2__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM1_THRHLD_MIN_2_MACRO__ */

/** @} end of port0_alm1_thrhld_min_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_alm1_thrhld_min_3 */
/**
 * @defgroup at_apb_shub_regs_core_port0_alm1_thrhld_min_3 port0_alm1_thrhld_min_3
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT0_ALM1_THRHLD_MIN_3_MACRO__
#define __SHUB_PORT0_ALM1_THRHLD_MIN_3_MACRO__

/* macros for field threshold_min3 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min3_field threshold_min3_field
 * @brief macros for field threshold_min3
 * @{
 */
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__SHIFT                   0
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__WIDTH                  32
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__MASK          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__THRESHOLD_MIN3__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__TYPE                             uint32_t
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__READ                          0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__WRITE                         0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__PRESERVED                     0xffffffffU
#define SHUB_PORT0_ALM1_THRHLD_MIN_3__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT0_ALM1_THRHLD_MIN_3_MACRO__ */

/** @} end of port0_alm1_thrhld_min_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port0_status */
/**
 * @defgroup at_apb_shub_regs_core_port0_status port0_status
 * @brief Contains register fields associated with port0_status. definitions.
 * @{
 */
#ifndef __SHUB_PORT0_STATUS_MACRO__
#define __SHUB_PORT0_STATUS_MACRO__

/* macros for field out_of_range_stat_min */
/**
 * @defgroup at_apb_shub_regs_core_out_of_range_stat_min_field out_of_range_stat_min_field
 * @brief macros for field out_of_range_stat_min
 * @{
 */
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MIN__SHIFT                       0
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MIN__WIDTH                       4
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MIN__MASK              0x0000000fU
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MIN__RESET_VALUE       0x00000000U
/** @} */

/* macros for field out_of_range_stat_max */
/**
 * @defgroup at_apb_shub_regs_core_out_of_range_stat_max_field out_of_range_stat_max_field
 * @brief macros for field out_of_range_stat_max
 * @{
 */
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MAX__SHIFT                       4
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MAX__WIDTH                       4
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MAX__MASK              0x000000f0U
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MAX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define SHUB_PORT0_STATUS__OUT_OF_RANGE_STAT_MAX__RESET_VALUE       0x00000000U
/** @} */

/* macros for field triggered */
/**
 * @defgroup at_apb_shub_regs_core_triggered_field triggered_field
 * @brief macros for field triggered
 * @{
 */
#define SHUB_PORT0_STATUS__TRIGGERED__SHIFT                                  24
#define SHUB_PORT0_STATUS__TRIGGERED__WIDTH                                   1
#define SHUB_PORT0_STATUS__TRIGGERED__MASK                          0x01000000U
#define SHUB_PORT0_STATUS__TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT0_STATUS__TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT0_STATUS__TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT0_STATUS__TRIGGERED__RESET_VALUE                   0x00000000U
/** @} */
#define SHUB_PORT0_STATUS__TYPE                                        uint32_t
#define SHUB_PORT0_STATUS__READ                                     0x010000ffU
#define SHUB_PORT0_STATUS__PRESERVED                                0x00000000U
#define SHUB_PORT0_STATUS__RESET_VALUE                              0x00000000U

#endif /* __SHUB_PORT0_STATUS_MACRO__ */

/** @} end of port0_status */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_setup */
/**
 * @defgroup at_apb_shub_regs_core_port1_setup port1_setup
 * @brief Contains register fields associated with port1_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT1_SETUP_MACRO__
#define __SHUB_PORT1_SETUP_MACRO__

/* macros for field port_en */
/**
 * @defgroup at_apb_shub_regs_core_port_en_field port_en_field
 * @brief macros for field port_en
 * @{
 */
#define SHUB_PORT1_SETUP__PORT_EN__SHIFT                                      0
#define SHUB_PORT1_SETUP__PORT_EN__WIDTH                                      1
#define SHUB_PORT1_SETUP__PORT_EN__MASK                             0x00000001U
#define SHUB_PORT1_SETUP__PORT_EN__READ(src)    ((uint32_t)(src) & 0x00000001U)
#define SHUB_PORT1_SETUP__PORT_EN__WRITE(src)   ((uint32_t)(src) & 0x00000001U)
#define SHUB_PORT1_SETUP__PORT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT1_SETUP__PORT_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT1_SETUP__PORT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT1_SETUP__PORT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT1_SETUP__PORT_EN__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field spi_n_i2c */
/**
 * @defgroup at_apb_shub_regs_core_spi_n_i2c_field spi_n_i2c_field
 * @brief macros for field spi_n_i2c
 * @details 1= use spi for port0, 0= use i2c
 * @{
 */
#define SHUB_PORT1_SETUP__SPI_N_I2C__SHIFT                                    1
#define SHUB_PORT1_SETUP__SPI_N_I2C__WIDTH                                    1
#define SHUB_PORT1_SETUP__SPI_N_I2C__MASK                           0x00000002U
#define SHUB_PORT1_SETUP__SPI_N_I2C__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SHUB_PORT1_SETUP__SPI_N_I2C__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SHUB_PORT1_SETUP__SPI_N_I2C__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SHUB_PORT1_SETUP__SPI_N_I2C__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SHUB_PORT1_SETUP__SPI_N_I2C__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SHUB_PORT1_SETUP__SPI_N_I2C__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SHUB_PORT1_SETUP__SPI_N_I2C__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field num_sensors */
/**
 * @defgroup at_apb_shub_regs_core_num_sensors_field num_sensors_field
 * @brief macros for field num_sensors
 * @details number of sensors connected to port = num_sensors + 1
 * @{
 */
#define SHUB_PORT1_SETUP__NUM_SENSORS__SHIFT                                  4
#define SHUB_PORT1_SETUP__NUM_SENSORS__WIDTH                                  3
#define SHUB_PORT1_SETUP__NUM_SENSORS__MASK                         0x00000070U
#define SHUB_PORT1_SETUP__NUM_SENSORS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define SHUB_PORT1_SETUP__NUM_SENSORS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define SHUB_PORT1_SETUP__NUM_SENSORS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define SHUB_PORT1_SETUP__NUM_SENSORS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define SHUB_PORT1_SETUP__NUM_SENSORS__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field trig_en */
/**
 * @defgroup at_apb_shub_regs_core_trig_en_field trig_en_field
 * @brief macros for field trig_en
 * @details 1= enable threshold comparison with measurement results.
 * @{
 */
#define SHUB_PORT1_SETUP__TRIG_EN__SHIFT                                     11
#define SHUB_PORT1_SETUP__TRIG_EN__WIDTH                                      1
#define SHUB_PORT1_SETUP__TRIG_EN__MASK                             0x00000800U
#define SHUB_PORT1_SETUP__TRIG_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define SHUB_PORT1_SETUP__TRIG_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define SHUB_PORT1_SETUP__TRIG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define SHUB_PORT1_SETUP__TRIG_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define SHUB_PORT1_SETUP__TRIG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define SHUB_PORT1_SETUP__TRIG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define SHUB_PORT1_SETUP__TRIG_EN__RESET_VALUE                      0x00000000U
/** @} */
#define SHUB_PORT1_SETUP__TYPE                                         uint32_t
#define SHUB_PORT1_SETUP__READ                                      0x00000873U
#define SHUB_PORT1_SETUP__WRITE                                     0x00000873U
#define SHUB_PORT1_SETUP__PRESERVED                                 0x00000873U
#define SHUB_PORT1_SETUP__RESET_VALUE                               0x00000000U

#endif /* __SHUB_PORT1_SETUP_MACRO__ */

/** @} end of port1_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_sensor0_setup */
/**
 * @defgroup at_apb_shub_regs_core_port1_sensor0_setup port1_sensor0_setup
 * @brief Contains register fields associated with port1_sensor0_setup. definitions.
 * @{
 */
#ifndef __SHUB_PORT1_SENSOR0_SETUP_MACRO__
#define __SHUB_PORT1_SENSOR0_SETUP_MACRO__

/* macros for field num_bytes */
/**
 * @defgroup at_apb_shub_regs_core_num_bytes_field num_bytes_field
 * @brief macros for field num_bytes
 * @details total number of bytes in sensor data = num_bytes+1
 * @{
 */
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__SHIFT                            0
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__WIDTH                            5
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__MASK                   0x0000001fU
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT1_SENSOR0_SETUP__NUM_BYTES__RESET_VALUE            0x00000001U
/** @} */
#define SHUB_PORT1_SENSOR0_SETUP__TYPE                                 uint32_t
#define SHUB_PORT1_SENSOR0_SETUP__READ                              0x0000001fU
#define SHUB_PORT1_SENSOR0_SETUP__WRITE                             0x0000001fU
#define SHUB_PORT1_SENSOR0_SETUP__PRESERVED                         0x0000001fU
#define SHUB_PORT1_SENSOR0_SETUP__RESET_VALUE                       0x00000001U

#endif /* __SHUB_PORT1_SENSOR0_SETUP_MACRO__ */

/** @} end of port1_sensor0_setup */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_spi_eng0_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port1_spi_eng0_ctrl port1_spi_eng0_ctrl
 * @brief Contains register fields associated with port1_spi_eng0_ctrl. definitions.
 * @{
 */
#ifndef __SHUB_PORT1_SPI_ENG0_CTRL_MACRO__
#define __SHUB_PORT1_SPI_ENG0_CTRL_MACRO__

/* macros for field sensor_opcode */
/**
 * @defgroup at_apb_shub_regs_core_sensor_opcode_field sensor_opcode_field
 * @brief macros for field sensor_opcode
 * @details opcode used to communicate with sensor in spi mode
 * @{
 */
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__SHIFT                        0
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__WIDTH                        8
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__MASK               0x000000ffU
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SHUB_PORT1_SPI_ENG0_CTRL__SENSOR_OPCODE__RESET_VALUE        0x00000000U
/** @} */

/* macros for field cpha */
/**
 * @defgroup at_apb_shub_regs_core_cpha_field cpha_field
 * @brief macros for field cpha
 * @details spi clcok phase mode
 * @{
 */
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__SHIFT                                30
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__WIDTH                                 1
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__MASK                        0x40000000U
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPHA__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field cpol */
/**
 * @defgroup at_apb_shub_regs_core_cpol_field cpol_field
 * @brief macros for field cpol
 * @details spi clock polarity mode. 0 = posedge-sensitive, 1 = negedge
 * @{
 */
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__SHIFT                                31
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__WIDTH                                 1
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__MASK                        0x80000000U
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SHUB_PORT1_SPI_ENG0_CTRL__CPOL__RESET_VALUE                 0x00000000U
/** @} */
#define SHUB_PORT1_SPI_ENG0_CTRL__TYPE                                 uint32_t
#define SHUB_PORT1_SPI_ENG0_CTRL__READ                              0xc00000ffU
#define SHUB_PORT1_SPI_ENG0_CTRL__WRITE                             0xc00000ffU
#define SHUB_PORT1_SPI_ENG0_CTRL__PRESERVED                         0xc00000ffU
#define SHUB_PORT1_SPI_ENG0_CTRL__RESET_VALUE                       0x00000000U

#endif /* __SHUB_PORT1_SPI_ENG0_CTRL_MACRO__ */

/** @} end of port1_spi_eng0_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_i2c_idw_0 */
/**
 * @defgroup at_apb_shub_regs_core_port1_i2c_idw_0 port1_i2c_idw_0
 * @brief id(read) of sensor0 on port0 prior to pointer address write definitions.
 * @{
 */
#ifndef __SHUB_PORT1_I2C_IDW_0_MACRO__
#define __SHUB_PORT1_I2C_IDW_0_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT1_I2C_IDW_0__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT1_I2C_IDW_0__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__SHIFT                                19
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__SHIFT                                21
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT1_I2C_IDW_0__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT1_I2C_IDW_0__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT1_I2C_IDW_0__TYPE                                     uint32_t
#define SHUB_PORT1_I2C_IDW_0__READ                                  0x01ffffffU
#define SHUB_PORT1_I2C_IDW_0__WRITE                                 0x01ffffffU
#define SHUB_PORT1_I2C_IDW_0__PRESERVED                             0x01ffffffU
#define SHUB_PORT1_I2C_IDW_0__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT1_I2C_IDW_0_MACRO__ */

/** @} end of port1_i2c_idw_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_i2c_addr_0 */
/**
 * @defgroup at_apb_shub_regs_core_port1_i2c_addr_0 port1_i2c_addr_0
 * @brief pointer addr of sensor0 on port0 definitions.
 * @{
 */
#ifndef __SHUB_PORT1_I2C_ADDR_0_MACRO__
#define __SHUB_PORT1_I2C_ADDR_0_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__SHIFT                        0
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__WIDTH                        1
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__MASK               0x00000001U
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_IE_OVRD__RESET_VALUE        0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__SHIFT                              1
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__WIDTH                              8
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__MASK                     0x000001feU
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_O__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__SHIFT                             9
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__WIDTH                             8
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__MASK                    0x0001fe00U
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_OE__RESET_VALUE             0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__SHIFT                            17
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__WIDTH                             1
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__MASK                    0x00020000U
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT1_I2C_ADDR_0__EXT_DATA_PU__RESET_VALUE             0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__SHIFT                             18
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__WIDTH                              1
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__MASK                     0x00040000U
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT1_I2C_ADDR_0__EXT_CLK_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__SHIFT                               19
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__WIDTH                                2
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__MASK                       0x00180000U
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_HEAD__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__SHIFT                               21
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__WIDTH                                2
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__MASK                       0x00600000U
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_TAIL__RESET_VALUE                0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__SHIFT                  23
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__WIDTH                   1
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__MASK          0x00800000U
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT1_I2C_ADDR_0__EXT_MASTER_DRIVES_ACK__RESET_VALUE   0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__SHIFT                 24
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__WIDTH                  1
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__MASK         0x01000000U
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT1_I2C_ADDR_0__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT1_I2C_ADDR_0__TYPE                                    uint32_t
#define SHUB_PORT1_I2C_ADDR_0__READ                                 0x01ffffffU
#define SHUB_PORT1_I2C_ADDR_0__WRITE                                0x01ffffffU
#define SHUB_PORT1_I2C_ADDR_0__PRESERVED                            0x01ffffffU
#define SHUB_PORT1_I2C_ADDR_0__RESET_VALUE                          0x0001fe00U

#endif /* __SHUB_PORT1_I2C_ADDR_0_MACRO__ */

/** @} end of port1_i2c_addr_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_i2c_idr_0 */
/**
 * @defgroup at_apb_shub_regs_core_port1_i2c_idr_0 port1_i2c_idr_0
 * @brief id(read) of sensor0 on port0 prior to data read definitions.
 * @{
 */
#ifndef __SHUB_PORT1_I2C_IDR_0_MACRO__
#define __SHUB_PORT1_I2C_IDR_0_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__SHIFT                         0
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__WIDTH                         1
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__MASK                0x00000001U
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_IE_OVRD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__SHIFT                               1
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__WIDTH                               8
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__MASK                      0x000001feU
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_O__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__SHIFT                              9
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__WIDTH                              8
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__MASK                     0x0001fe00U
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_OE__RESET_VALUE              0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__SHIFT                             17
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__WIDTH                              1
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__MASK                     0x00020000U
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT1_I2C_IDR_0__EXT_DATA_PU__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__SHIFT                              18
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__WIDTH                               1
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__MASK                      0x00040000U
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT1_I2C_IDR_0__EXT_CLK_PU__RESET_VALUE               0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__SHIFT                                19
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__WIDTH                                 2
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__MASK                        0x00180000U
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_HEAD__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__SHIFT                                21
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__WIDTH                                 2
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__MASK                        0x00600000U
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_TAIL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__SHIFT                   23
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__WIDTH                    1
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__MASK           0x00800000U
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT1_I2C_IDR_0__EXT_MASTER_DRIVES_ACK__RESET_VALUE    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__SHIFT                  24
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__WIDTH                   1
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__MASK          0x01000000U
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT1_I2C_IDR_0__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT1_I2C_IDR_0__TYPE                                     uint32_t
#define SHUB_PORT1_I2C_IDR_0__READ                                  0x01ffffffU
#define SHUB_PORT1_I2C_IDR_0__WRITE                                 0x01ffffffU
#define SHUB_PORT1_I2C_IDR_0__PRESERVED                             0x01ffffffU
#define SHUB_PORT1_I2C_IDR_0__RESET_VALUE                           0x0001fe00U

#endif /* __SHUB_PORT1_I2C_IDR_0_MACRO__ */

/** @} end of port1_i2c_idr_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_i2c_dat_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port1_i2c_dat_ctrl port1_i2c_dat_ctrl
 * @brief slave(port0) data byte read (used in not the last byte) definitions.
 * @{
 */
#ifndef __SHUB_PORT1_I2C_DAT_CTRL_MACRO__
#define __SHUB_PORT1_I2C_DAT_CTRL_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__SHIFT                      0
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__WIDTH                      1
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__MASK             0x00000001U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_IE_OVRD__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__SHIFT                            1
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__WIDTH                            8
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__MASK                   0x000001feU
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_O__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__SHIFT                           9
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__WIDTH                           8
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__MASK                  0x0001fe00U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_OE__RESET_VALUE           0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__SHIFT                          17
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__WIDTH                           1
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__MASK                  0x00020000U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_DATA_PU__RESET_VALUE           0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__SHIFT                           18
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__WIDTH                            1
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__MASK                   0x00040000U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_CLK_PU__RESET_VALUE            0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__SHIFT                             19
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__WIDTH                              2
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__MASK                     0x00180000U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_HEAD__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__SHIFT                             21
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__WIDTH                              2
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__MASK                     0x00600000U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_TAIL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__SHIFT                23
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__WIDTH                 1
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__MASK        0x00800000U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_MASTER_DRIVES_ACK__RESET_VALUE 0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__SHIFT               24
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__WIDTH                1
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__MASK       0x01000000U
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT1_I2C_DAT_CTRL__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE \
                    0x00000000U
/** @} */
#define SHUB_PORT1_I2C_DAT_CTRL__TYPE                                  uint32_t
#define SHUB_PORT1_I2C_DAT_CTRL__READ                               0x01ffffffU
#define SHUB_PORT1_I2C_DAT_CTRL__WRITE                              0x01ffffffU
#define SHUB_PORT1_I2C_DAT_CTRL__PRESERVED                          0x01ffffffU
#define SHUB_PORT1_I2C_DAT_CTRL__RESET_VALUE                        0x0001fe00U

#endif /* __SHUB_PORT1_I2C_DAT_CTRL_MACRO__ */

/** @} end of port1_i2c_dat_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_i2c_dat_last_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port1_i2c_dat_last_ctrl port1_i2c_dat_last_ctrl
 * @brief slave(port0) data byte read (used in the last byte) definitions.
 * @{
 */
#ifndef __SHUB_PORT1_I2C_DAT_LAST_CTRL_MACRO__
#define __SHUB_PORT1_I2C_DAT_LAST_CTRL_MACRO__

/* macros for field ext_data_ie_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_ie_ovrd_field ext_data_ie_ovrd_field
 * @brief macros for field ext_data_ie_ovrd
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__SHIFT                 0
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__WIDTH                 1
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__MASK        0x00000001U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_IE_OVRD__RESET_VALUE 0x00000000U
/** @} */

/* macros for field ext_data_o */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_o_field ext_data_o_field
 * @brief macros for field ext_data_o
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__SHIFT                       1
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__WIDTH                       8
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__MASK              0x000001feU
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001feU) >> 1)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000001feU)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_O__RESET_VALUE       0x00000000U
/** @} */

/* macros for field ext_data_oe */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_oe_field ext_data_oe_field
 * @brief macros for field ext_data_oe
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__SHIFT                      9
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__WIDTH                      8
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__MASK             0x0001fe00U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_OE__RESET_VALUE      0x000000ffU
/** @} */

/* macros for field ext_data_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_data_pu_field ext_data_pu_field
 * @brief macros for field ext_data_pu
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__SHIFT                     17
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__WIDTH                      1
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__MASK             0x00020000U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_DATA_PU__RESET_VALUE      0x00000000U
/** @} */

/* macros for field ext_clk_pu */
/**
 * @defgroup at_apb_shub_regs_core_ext_clk_pu_field ext_clk_pu_field
 * @brief macros for field ext_clk_pu
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__SHIFT                      18
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__WIDTH                       1
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__MASK              0x00040000U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_CLK_PU__RESET_VALUE       0x00000000U
/** @} */

/* macros for field ext_head */
/**
 * @defgroup at_apb_shub_regs_core_ext_head_field ext_head_field
 * @brief macros for field ext_head
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__SHIFT                        19
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__WIDTH                         2
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__MASK                0x00180000U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_HEAD__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_tail */
/**
 * @defgroup at_apb_shub_regs_core_ext_tail_field ext_tail_field
 * @brief macros for field ext_tail
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__SHIFT                        21
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__WIDTH                         2
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__MASK                0x00600000U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_TAIL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field ext_master_drives_ack */
/**
 * @defgroup at_apb_shub_regs_core_ext_master_drives_ack_field ext_master_drives_ack_field
 * @brief macros for field ext_master_drives_ack
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__SHIFT           23
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__WIDTH            1
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__MASK   0x00800000U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_MASTER_DRIVES_ACK__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field ext_ack_value_to_drive */
/**
 * @defgroup at_apb_shub_regs_core_ext_ack_value_to_drive_field ext_ack_value_to_drive_field
 * @brief macros for field ext_ack_value_to_drive
 * @{
 */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__SHIFT          24
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__WIDTH           1
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__MASK  0x01000000U
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__EXT_ACK_VALUE_TO_DRIVE__RESET_VALUE \
                    0x00000000U
/** @} */
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__TYPE                             uint32_t
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__READ                          0x01ffffffU
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__WRITE                         0x01ffffffU
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__PRESERVED                     0x01ffffffU
#define SHUB_PORT1_I2C_DAT_LAST_CTRL__RESET_VALUE                   0x0001fe00U

#endif /* __SHUB_PORT1_I2C_DAT_LAST_CTRL_MACRO__ */

/** @} end of port1_i2c_dat_last_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_quan_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_quan_ctrl port1_alm0_quan_ctrl
 * @brief alarm0 quantity's definition definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_QUAN_CTRL_MACRO__
#define __SHUB_PORT1_ALM0_QUAN_CTRL_MACRO__

/* macros for field quan0_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan0_pos_field quan0_pos_field
 * @brief macros for field quan0_pos
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__SHIFT                           0
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__WIDTH                           5
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__MASK                  0x0000001fU
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan1_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan1_pos_field quan1_pos_field
 * @brief macros for field quan1_pos
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__SHIFT                           5
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__WIDTH                           5
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__MASK                  0x000003e0U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan2_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan2_pos_field quan2_pos_field
 * @brief macros for field quan2_pos
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__SHIFT                          10
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__WIDTH                           5
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__MASK                  0x00007c00U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan3_pos */
/**
 * @defgroup at_apb_shub_regs_core_quan3_pos_field quan3_pos_field
 * @brief macros for field quan3_pos
 * @details starting position of the quantity
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__SHIFT                          15
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__WIDTH                           5
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__MASK                  0x000f8000U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_POS__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan0_size */
/**
 * @defgroup at_apb_shub_regs_core_quan0_size_field quan0_size_field
 * @brief macros for field quan0_size
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__SHIFT                         20
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__WIDTH                          2
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__MASK                 0x00300000U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN0_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan1_size */
/**
 * @defgroup at_apb_shub_regs_core_quan1_size_field quan1_size_field
 * @brief macros for field quan1_size
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__SHIFT                         22
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__WIDTH                          2
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__MASK                 0x00c00000U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN1_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan2_size */
/**
 * @defgroup at_apb_shub_regs_core_quan2_size_field quan2_size_field
 * @brief macros for field quan2_size
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__SHIFT                         24
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__WIDTH                          2
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__MASK                 0x03000000U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN2_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field quan3_size */
/**
 * @defgroup at_apb_shub_regs_core_quan3_size_field quan3_size_field
 * @brief macros for field quan3_size
 * @details number of bytes making up the quantity data = programmed quan3_size + 1
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__SHIFT                         26
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__WIDTH                          2
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__MASK                 0x0c000000U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN3_SIZE__RESET_VALUE          0x00000001U
/** @} */

/* macros for field lsb_first */
/**
 * @defgroup at_apb_shub_regs_core_lsb_first_field lsb_first_field
 * @brief macros for field lsb_first
 * @details 1= quantity data is big endian ; 0= small endian
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__SHIFT                          30
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__WIDTH                           1
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__MASK                  0x40000000U
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define SHUB_PORT1_ALM0_QUAN_CTRL__LSB_FIRST__RESET_VALUE           0x00000000U
/** @} */

/* macros for field quan_dat_is_signed */
/**
 * @defgroup at_apb_shub_regs_core_quan_dat_is_signed_field quan_dat_is_signed_field
 * @brief macros for field quan_dat_is_signed
 * @details quantity data is a signed data
 * @{
 */
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__SHIFT                 31
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__WIDTH                  1
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__MASK         0x80000000U
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SHUB_PORT1_ALM0_QUAN_CTRL__QUAN_DAT_IS_SIGNED__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_PORT1_ALM0_QUAN_CTRL__TYPE                                uint32_t
#define SHUB_PORT1_ALM0_QUAN_CTRL__READ                             0xcfffffffU
#define SHUB_PORT1_ALM0_QUAN_CTRL__WRITE                            0xcfffffffU
#define SHUB_PORT1_ALM0_QUAN_CTRL__PRESERVED                        0xcfffffffU
#define SHUB_PORT1_ALM0_QUAN_CTRL__RESET_VALUE                      0x05500000U

#endif /* __SHUB_PORT1_ALM0_QUAN_CTRL_MACRO__ */

/** @} end of port1_alm0_quan_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_trig_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_trig_ctrl port1_alm0_trig_ctrl
 * @brief alarm0 trigger function: trigger = trig_func_en( out_of_range(quan3), out_of_range(quan2),out_of_range(quan1),out_of_range(quan0)) definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_TRIG_CTRL_MACRO__
#define __SHUB_PORT1_ALM0_TRIG_CTRL_MACRO__

/* macros for field trig_func_en */
/**
 * @defgroup at_apb_shub_regs_core_trig_func_en_field trig_func_en_field
 * @brief macros for field trig_func_en
 * @{
 */
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__SHIFT                        0
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__WIDTH                       16
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__MASK               0x0000ffffU
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000ffffU)
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ffffU) | ((uint32_t)(src) &\
                    0x0000ffffU)
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000ffffU)))
#define SHUB_PORT1_ALM0_TRIG_CTRL__TRIG_FUNC_EN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field out_of_range_mask */
/**
 * @defgroup at_apb_shub_regs_core_out_of_range_mask_field out_of_range_mask_field
 * @brief macros for field out_of_range_mask
 * @details mask out out_of_range bits
 * @{
 */
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__SHIFT                  16
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__WIDTH                   4
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__MASK          0x000f0000U
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define SHUB_PORT1_ALM0_TRIG_CTRL__OUT_OF_RANGE_MASK__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT1_ALM0_TRIG_CTRL__TYPE                                uint32_t
#define SHUB_PORT1_ALM0_TRIG_CTRL__READ                             0x000fffffU
#define SHUB_PORT1_ALM0_TRIG_CTRL__WRITE                            0x000fffffU
#define SHUB_PORT1_ALM0_TRIG_CTRL__PRESERVED                        0x000fffffU
#define SHUB_PORT1_ALM0_TRIG_CTRL__RESET_VALUE                      0x00000000U

#endif /* __SHUB_PORT1_ALM0_TRIG_CTRL_MACRO__ */

/** @} end of port1_alm0_trig_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_max_0 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_max_0 port1_alm0_thrhld_max_0
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MAX_0_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MAX_0_MACRO__

/* macros for field threshold_max0 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max0_field threshold_max0_field
 * @brief macros for field threshold_max0
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__THRESHOLD_MAX0__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_0__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT1_ALM0_THRHLD_MAX_0_MACRO__ */

/** @} end of port1_alm0_thrhld_max_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_max_1 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_max_1 port1_alm0_thrhld_max_1
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MAX_1_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MAX_1_MACRO__

/* macros for field threshold_max1 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max1_field threshold_max1_field
 * @brief macros for field threshold_max1
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__THRESHOLD_MAX1__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_1__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT1_ALM0_THRHLD_MAX_1_MACRO__ */

/** @} end of port1_alm0_thrhld_max_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_max_2 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_max_2 port1_alm0_thrhld_max_2
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MAX_2_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MAX_2_MACRO__

/* macros for field threshold_max2 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max2_field threshold_max2_field
 * @brief macros for field threshold_max2
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__THRESHOLD_MAX2__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_2__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT1_ALM0_THRHLD_MAX_2_MACRO__ */

/** @} end of port1_alm0_thrhld_max_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_max_3 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_max_3 port1_alm0_thrhld_max_3
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MAX_3_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MAX_3_MACRO__

/* macros for field threshold_max3 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_max3_field threshold_max3_field
 * @brief macros for field threshold_max3
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__THRESHOLD_MAX3__RESET_VALUE   0xffffffffU
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MAX_3__RESET_VALUE                   0xffffffffU

#endif /* __SHUB_PORT1_ALM0_THRHLD_MAX_3_MACRO__ */

/** @} end of port1_alm0_thrhld_max_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_min_0 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_min_0 port1_alm0_thrhld_min_0
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MIN_0_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MIN_0_MACRO__

/* macros for field threshold_min0 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min0_field threshold_min0_field
 * @brief macros for field threshold_min0
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__THRESHOLD_MIN0__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_0__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT1_ALM0_THRHLD_MIN_0_MACRO__ */

/** @} end of port1_alm0_thrhld_min_0 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_min_1 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_min_1 port1_alm0_thrhld_min_1
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MIN_1_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MIN_1_MACRO__

/* macros for field threshold_min1 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min1_field threshold_min1_field
 * @brief macros for field threshold_min1
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__THRESHOLD_MIN1__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_1__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT1_ALM0_THRHLD_MIN_1_MACRO__ */

/** @} end of port1_alm0_thrhld_min_1 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_min_2 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_min_2 port1_alm0_thrhld_min_2
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MIN_2_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MIN_2_MACRO__

/* macros for field threshold_min2 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min2_field threshold_min2_field
 * @brief macros for field threshold_min2
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__THRESHOLD_MIN2__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_2__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT1_ALM0_THRHLD_MIN_2_MACRO__ */

/** @} end of port1_alm0_thrhld_min_2 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_alm0_thrhld_min_3 */
/**
 * @defgroup at_apb_shub_regs_core_port1_alm0_thrhld_min_3 port1_alm0_thrhld_min_3
 * @brief threshold of sensor results definitions.
 * @{
 */
#ifndef __SHUB_PORT1_ALM0_THRHLD_MIN_3_MACRO__
#define __SHUB_PORT1_ALM0_THRHLD_MIN_3_MACRO__

/* macros for field threshold_min3 */
/**
 * @defgroup at_apb_shub_regs_core_threshold_min3_field threshold_min3_field
 * @brief macros for field threshold_min3
 * @{
 */
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__SHIFT                   0
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__WIDTH                  32
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__MASK          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__THRESHOLD_MIN3__RESET_VALUE   0x00000000U
/** @} */
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__TYPE                             uint32_t
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__READ                          0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__WRITE                         0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__PRESERVED                     0xffffffffU
#define SHUB_PORT1_ALM0_THRHLD_MIN_3__RESET_VALUE                   0x00000000U

#endif /* __SHUB_PORT1_ALM0_THRHLD_MIN_3_MACRO__ */

/** @} end of port1_alm0_thrhld_min_3 */

/* macros for BlueprintGlobalNameSpace::SHUB_port1_status */
/**
 * @defgroup at_apb_shub_regs_core_port1_status port1_status
 * @brief Contains register fields associated with port1_status. definitions.
 * @{
 */
#ifndef __SHUB_PORT1_STATUS_MACRO__
#define __SHUB_PORT1_STATUS_MACRO__

/* macros for field out_of_range_stat_min */
/**
 * @defgroup at_apb_shub_regs_core_out_of_range_stat_min_field out_of_range_stat_min_field
 * @brief macros for field out_of_range_stat_min
 * @{
 */
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MIN__SHIFT                       0
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MIN__WIDTH                       4
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MIN__MASK              0x0000000fU
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MIN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MIN__RESET_VALUE       0x00000000U
/** @} */

/* macros for field out_of_range_stat_max */
/**
 * @defgroup at_apb_shub_regs_core_out_of_range_stat_max_field out_of_range_stat_max_field
 * @brief macros for field out_of_range_stat_max
 * @{
 */
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MAX__SHIFT                       4
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MAX__WIDTH                       4
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MAX__MASK              0x000000f0U
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MAX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define SHUB_PORT1_STATUS__OUT_OF_RANGE_STAT_MAX__RESET_VALUE       0x00000000U
/** @} */

/* macros for field triggered */
/**
 * @defgroup at_apb_shub_regs_core_triggered_field triggered_field
 * @brief macros for field triggered
 * @{
 */
#define SHUB_PORT1_STATUS__TRIGGERED__SHIFT                                  24
#define SHUB_PORT1_STATUS__TRIGGERED__WIDTH                                   1
#define SHUB_PORT1_STATUS__TRIGGERED__MASK                          0x01000000U
#define SHUB_PORT1_STATUS__TRIGGERED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_PORT1_STATUS__TRIGGERED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_PORT1_STATUS__TRIGGERED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_PORT1_STATUS__TRIGGERED__RESET_VALUE                   0x00000000U
/** @} */
#define SHUB_PORT1_STATUS__TYPE                                        uint32_t
#define SHUB_PORT1_STATUS__READ                                     0x010000ffU
#define SHUB_PORT1_STATUS__PRESERVED                                0x00000000U
#define SHUB_PORT1_STATUS__RESET_VALUE                              0x00000000U

#endif /* __SHUB_PORT1_STATUS_MACRO__ */

/** @} end of port1_status */

/* macros for BlueprintGlobalNameSpace::SHUB_flash_ctrl0 */
/**
 * @defgroup at_apb_shub_regs_core_flash_ctrl0 flash_ctrl0
 * @brief Contains register fields associated with flash_ctrl0. definitions.
 * @{
 */
#ifndef __SHUB_FLASH_CTRL0_MACRO__
#define __SHUB_FLASH_CTRL0_MACRO__

/* macros for field opcode_wren */
/**
 * @defgroup at_apb_shub_regs_core_opcode_wren_field opcode_wren_field
 * @brief macros for field opcode_wren
 * @details write_enable opcode
 * @{
 */
#define SHUB_FLASH_CTRL0__OPCODE_WREN__SHIFT                                  0
#define SHUB_FLASH_CTRL0__OPCODE_WREN__WIDTH                                  8
#define SHUB_FLASH_CTRL0__OPCODE_WREN__MASK                         0x000000ffU
#define SHUB_FLASH_CTRL0__OPCODE_WREN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SHUB_FLASH_CTRL0__OPCODE_WREN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define SHUB_FLASH_CTRL0__OPCODE_WREN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define SHUB_FLASH_CTRL0__OPCODE_WREN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define SHUB_FLASH_CTRL0__OPCODE_WREN__RESET_VALUE                  0x00000006U
/** @} */

/* macros for field opcode_pp */
/**
 * @defgroup at_apb_shub_regs_core_opcode_pp_field opcode_pp_field
 * @brief macros for field opcode_pp
 * @details page program opcode
 * @{
 */
#define SHUB_FLASH_CTRL0__OPCODE_PP__SHIFT                                    8
#define SHUB_FLASH_CTRL0__OPCODE_PP__WIDTH                                    8
#define SHUB_FLASH_CTRL0__OPCODE_PP__MASK                           0x0000ff00U
#define SHUB_FLASH_CTRL0__OPCODE_PP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define SHUB_FLASH_CTRL0__OPCODE_PP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define SHUB_FLASH_CTRL0__OPCODE_PP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define SHUB_FLASH_CTRL0__OPCODE_PP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define SHUB_FLASH_CTRL0__OPCODE_PP__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field opcode_pd */
/**
 * @defgroup at_apb_shub_regs_core_opcode_pd_field opcode_pd_field
 * @brief macros for field opcode_pd
 * @details power down opcode
 * @{
 */
#define SHUB_FLASH_CTRL0__OPCODE_PD__SHIFT                                   16
#define SHUB_FLASH_CTRL0__OPCODE_PD__WIDTH                                    8
#define SHUB_FLASH_CTRL0__OPCODE_PD__MASK                           0x00ff0000U
#define SHUB_FLASH_CTRL0__OPCODE_PD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define SHUB_FLASH_CTRL0__OPCODE_PD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define SHUB_FLASH_CTRL0__OPCODE_PD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define SHUB_FLASH_CTRL0__OPCODE_PD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define SHUB_FLASH_CTRL0__OPCODE_PD__RESET_VALUE                    0x000000b9U
/** @} */

/* macros for field opcode_rpd */
/**
 * @defgroup at_apb_shub_regs_core_opcode_rpd_field opcode_rpd_field
 * @brief macros for field opcode_rpd
 * @details release_power_down (not needed for macronix)
 * @{
 */
#define SHUB_FLASH_CTRL0__OPCODE_RPD__SHIFT                                  24
#define SHUB_FLASH_CTRL0__OPCODE_RPD__WIDTH                                   8
#define SHUB_FLASH_CTRL0__OPCODE_RPD__MASK                          0xff000000U
#define SHUB_FLASH_CTRL0__OPCODE_RPD__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define SHUB_FLASH_CTRL0__OPCODE_RPD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define SHUB_FLASH_CTRL0__OPCODE_RPD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define SHUB_FLASH_CTRL0__OPCODE_RPD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define SHUB_FLASH_CTRL0__OPCODE_RPD__RESET_VALUE                   0x000000abU
/** @} */
#define SHUB_FLASH_CTRL0__TYPE                                         uint32_t
#define SHUB_FLASH_CTRL0__READ                                      0xffffffffU
#define SHUB_FLASH_CTRL0__WRITE                                     0xffffffffU
#define SHUB_FLASH_CTRL0__PRESERVED                                 0xffffffffU
#define SHUB_FLASH_CTRL0__RESET_VALUE                               0xabb90206U

#endif /* __SHUB_FLASH_CTRL0_MACRO__ */

/** @} end of flash_ctrl0 */

/* macros for BlueprintGlobalNameSpace::SHUB_flash_ctrl1 */
/**
 * @defgroup at_apb_shub_regs_core_flash_ctrl1 flash_ctrl1
 * @brief Contains register fields associated with flash_ctrl1. definitions.
 * @{
 */
#ifndef __SHUB_FLASH_CTRL1_MACRO__
#define __SHUB_FLASH_CTRL1_MACRO__

/* macros for field wr_start_address */
/**
 * @defgroup at_apb_shub_regs_core_wr_start_address_field wr_start_address_field
 * @brief macros for field wr_start_address
 * @{
 */
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__SHIFT                             0
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__WIDTH                            24
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__MASK                    0x00ffffffU
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00ffffffU)))
#define SHUB_FLASH_CTRL1__WR_START_ADDRESS__RESET_VALUE             0x00000001U
/** @} */
#define SHUB_FLASH_CTRL1__TYPE                                         uint32_t
#define SHUB_FLASH_CTRL1__READ                                      0x00ffffffU
#define SHUB_FLASH_CTRL1__WRITE                                     0x00ffffffU
#define SHUB_FLASH_CTRL1__PRESERVED                                 0x00ffffffU
#define SHUB_FLASH_CTRL1__RESET_VALUE                               0x00000001U

#endif /* __SHUB_FLASH_CTRL1_MACRO__ */

/** @} end of flash_ctrl1 */

/* macros for BlueprintGlobalNameSpace::SHUB_flash_ctrl2 */
/**
 * @defgroup at_apb_shub_regs_core_flash_ctrl2 flash_ctrl2
 * @brief Contains register fields associated with flash_ctrl2. definitions.
 * @{
 */
#ifndef __SHUB_FLASH_CTRL2_MACRO__
#define __SHUB_FLASH_CTRL2_MACRO__

/* macros for field wr_max_address */
/**
 * @defgroup at_apb_shub_regs_core_wr_max_address_field wr_max_address_field
 * @brief macros for field wr_max_address
 * @{
 */
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__SHIFT                               0
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__WIDTH                              24
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__MASK                      0x00ffffffU
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((uint32_t)(src) &\
                    0x00ffffffU)
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00ffffffU)))
#define SHUB_FLASH_CTRL2__WR_MAX_ADDRESS__RESET_VALUE               0x00000000U
/** @} */
#define SHUB_FLASH_CTRL2__TYPE                                         uint32_t
#define SHUB_FLASH_CTRL2__READ                                      0x00ffffffU
#define SHUB_FLASH_CTRL2__WRITE                                     0x00ffffffU
#define SHUB_FLASH_CTRL2__PRESERVED                                 0x00ffffffU
#define SHUB_FLASH_CTRL2__RESET_VALUE                               0x00000000U

#endif /* __SHUB_FLASH_CTRL2_MACRO__ */

/** @} end of flash_ctrl2 */

/* macros for BlueprintGlobalNameSpace::SHUB_flash_ctrl3 */
/**
 * @defgroup at_apb_shub_regs_core_flash_ctrl3 flash_ctrl3
 * @brief Contains register fields associated with flash_ctrl3. definitions.
 * @{
 */
#ifndef __SHUB_FLASH_CTRL3_MACRO__
#define __SHUB_FLASH_CTRL3_MACRO__

/* macros for field power_cycle_en */
/**
 * @defgroup at_apb_shub_regs_core_power_cycle_en_field power_cycle_en_field
 * @brief macros for field power_cycle_en
 * @details 1= cycle flash into and out of deep power down mode.
 * @{
 */
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__SHIFT                               0
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__WIDTH                               1
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__MASK                      0x00000001U
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_FLASH_CTRL3__POWER_CYCLE_EN__RESET_VALUE               0x00000000U
/** @} */

/* macros for field serialize_opcode */
/**
 * @defgroup at_apb_shub_regs_core_serialize_opcode_field serialize_opcode_field
 * @brief macros for field serialize_opcode
 * @details 1= opcode is serial even in quad mode.
 * @{
 */
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__SHIFT                             1
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__WIDTH                             1
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__MASK                    0x00000002U
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SHUB_FLASH_CTRL3__SERIALIZE_OPCODE__RESET_VALUE             0x00000001U
/** @} */

/* macros for field qspi_mode */
/**
 * @defgroup at_apb_shub_regs_core_qspi_mode_field qspi_mode_field
 * @brief macros for field qspi_mode
 * @details 0,1,3 = single spi mode; 2 = qspi mode
 * @{
 */
#define SHUB_FLASH_CTRL3__QSPI_MODE__SHIFT                                    2
#define SHUB_FLASH_CTRL3__QSPI_MODE__WIDTH                                    2
#define SHUB_FLASH_CTRL3__QSPI_MODE__MASK                           0x0000000cU
#define SHUB_FLASH_CTRL3__QSPI_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define SHUB_FLASH_CTRL3__QSPI_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define SHUB_FLASH_CTRL3__QSPI_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define SHUB_FLASH_CTRL3__QSPI_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define SHUB_FLASH_CTRL3__QSPI_MODE__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field clear_flash_overflow */
/**
 * @defgroup at_apb_shub_regs_core_clear_flash_overflow_field clear_flash_overflow_field
 * @brief macros for field clear_flash_overflow
 * @{
 */
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__SHIFT                         4
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__WIDTH                         1
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__MASK                0x00000010U
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define SHUB_FLASH_CTRL3__CLEAR_FLASH_OVERFLOW__RESET_VALUE         0x00000000U
/** @} */

/* macros for field clear_lost_write_cnt */
/**
 * @defgroup at_apb_shub_regs_core_clear_lost_write_cnt_field clear_lost_write_cnt_field
 * @brief macros for field clear_lost_write_cnt
 * @{
 */
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__SHIFT                         5
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__WIDTH                         1
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__MASK                0x00000020U
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define SHUB_FLASH_CTRL3__CLEAR_LOST_WRITE_CNT__RESET_VALUE         0x00000000U
/** @} */

/* macros for field serialize_pp_address */
/**
 * @defgroup at_apb_shub_regs_core_serialize_pp_address_field serialize_pp_address_field
 * @brief macros for field serialize_pp_address
 * @{
 */
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__SHIFT                         6
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__WIDTH                         1
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__MASK                0x00000040U
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define SHUB_FLASH_CTRL3__SERIALIZE_PP_ADDRESS__RESET_VALUE         0x00000000U
/** @} */

/* macros for field rpd_has_clock */
/**
 * @defgroup at_apb_shub_regs_core_rpd_has_clock_field rpd_has_clock_field
 * @brief macros for field rpd_has_clock
 * @details for Macronix flash, rpd has no clock
 * @{
 */
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__SHIFT                                7
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__WIDTH                                1
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__MASK                       0x00000080U
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define SHUB_FLASH_CTRL3__RPD_HAS_CLOCK__RESET_VALUE                0x00000001U
/** @} */
#define SHUB_FLASH_CTRL3__TYPE                                         uint32_t
#define SHUB_FLASH_CTRL3__READ                                      0x000000ffU
#define SHUB_FLASH_CTRL3__WRITE                                     0x000000ffU
#define SHUB_FLASH_CTRL3__PRESERVED                                 0x000000ffU
#define SHUB_FLASH_CTRL3__RESET_VALUE                               0x00000082U

#endif /* __SHUB_FLASH_CTRL3_MACRO__ */

/** @} end of flash_ctrl3 */

/* macros for BlueprintGlobalNameSpace::SHUB_flash_ctrl4 */
/**
 * @defgroup at_apb_shub_regs_core_flash_ctrl4 flash_ctrl4
 * @brief Contains register fields associated with flash_ctrl4. definitions.
 * @{
 */
#ifndef __SHUB_FLASH_CTRL4_MACRO__
#define __SHUB_FLASH_CTRL4_MACRO__

/* macros for field pp_delay */
/**
 * @defgroup at_apb_shub_regs_core_pp_delay_field pp_delay_field
 * @brief macros for field pp_delay
 * @details delay cycles (pp_delay+1) after flash write. (320 cycles of 32k clock = 10ms pp time from Macronix)
 * @{
 */
#define SHUB_FLASH_CTRL4__PP_DELAY__SHIFT                                     0
#define SHUB_FLASH_CTRL4__PP_DELAY__WIDTH                                    12
#define SHUB_FLASH_CTRL4__PP_DELAY__MASK                            0x00000fffU
#define SHUB_FLASH_CTRL4__PP_DELAY__READ(src)   ((uint32_t)(src) & 0x00000fffU)
#define SHUB_FLASH_CTRL4__PP_DELAY__WRITE(src)  ((uint32_t)(src) & 0x00000fffU)
#define SHUB_FLASH_CTRL4__PP_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((uint32_t)(src) &\
                    0x00000fffU)
#define SHUB_FLASH_CTRL4__PP_DELAY__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000fffU)))
#define SHUB_FLASH_CTRL4__PP_DELAY__RESET_VALUE                     0x00000140U
/** @} */

/* macros for field pd_delay */
/**
 * @defgroup at_apb_shub_regs_core_pd_delay_field pd_delay_field
 * @brief macros for field pd_delay
 * @details delay cycles (pd_delay+1) after flash power down / release from power down
 * @{
 */
#define SHUB_FLASH_CTRL4__PD_DELAY__SHIFT                                    20
#define SHUB_FLASH_CTRL4__PD_DELAY__WIDTH                                     8
#define SHUB_FLASH_CTRL4__PD_DELAY__MASK                            0x0ff00000U
#define SHUB_FLASH_CTRL4__PD_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0ff00000U) >> 20)
#define SHUB_FLASH_CTRL4__PD_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x0ff00000U)
#define SHUB_FLASH_CTRL4__PD_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x0ff00000U)
#define SHUB_FLASH_CTRL4__PD_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x0ff00000U)))
#define SHUB_FLASH_CTRL4__PD_DELAY__RESET_VALUE                     0x00000002U
/** @} */
#define SHUB_FLASH_CTRL4__TYPE                                         uint32_t
#define SHUB_FLASH_CTRL4__READ                                      0x0ff00fffU
#define SHUB_FLASH_CTRL4__WRITE                                     0x0ff00fffU
#define SHUB_FLASH_CTRL4__PRESERVED                                 0x0ff00fffU
#define SHUB_FLASH_CTRL4__RESET_VALUE                               0x00200140U

#endif /* __SHUB_FLASH_CTRL4_MACRO__ */

/** @} end of flash_ctrl4 */

/* macros for BlueprintGlobalNameSpace::SHUB_flash_status0 */
/**
 * @defgroup at_apb_shub_regs_core_flash_status0 flash_status0
 * @brief Contains register fields associated with flash_status0. definitions.
 * @{
 */
#ifndef __SHUB_FLASH_STATUS0_MACRO__
#define __SHUB_FLASH_STATUS0_MACRO__

/* macros for field wr_current_address */
/**
 * @defgroup at_apb_shub_regs_core_wr_current_address_field wr_current_address_field
 * @brief macros for field wr_current_address
 * @details the next address to write to. Number of bytes in storage = wr_current_address - wr_start_address.
 * @{
 */
#define SHUB_FLASH_STATUS0__WR_CURRENT_ADDRESS__SHIFT                         0
#define SHUB_FLASH_STATUS0__WR_CURRENT_ADDRESS__WIDTH                        24
#define SHUB_FLASH_STATUS0__WR_CURRENT_ADDRESS__MASK                0x00ffffffU
#define SHUB_FLASH_STATUS0__WR_CURRENT_ADDRESS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00ffffffU)
#define SHUB_FLASH_STATUS0__WR_CURRENT_ADDRESS__RESET_VALUE         0x00000000U
/** @} */

/* macros for field wr_saturated */
/**
 * @defgroup at_apb_shub_regs_core_wr_saturated_field wr_saturated_field
 * @brief macros for field wr_saturated
 * @details indicates overflow.
 * @{
 */
#define SHUB_FLASH_STATUS0__WR_SATURATED__SHIFT                              24
#define SHUB_FLASH_STATUS0__WR_SATURATED__WIDTH                               1
#define SHUB_FLASH_STATUS0__WR_SATURATED__MASK                      0x01000000U
#define SHUB_FLASH_STATUS0__WR_SATURATED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SHUB_FLASH_STATUS0__WR_SATURATED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SHUB_FLASH_STATUS0__WR_SATURATED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define SHUB_FLASH_STATUS0__WR_SATURATED__RESET_VALUE               0x00000000U
/** @} */
#define SHUB_FLASH_STATUS0__TYPE                                       uint32_t
#define SHUB_FLASH_STATUS0__READ                                    0x01ffffffU
#define SHUB_FLASH_STATUS0__PRESERVED                               0x00000000U
#define SHUB_FLASH_STATUS0__RESET_VALUE                             0x00000000U

#endif /* __SHUB_FLASH_STATUS0_MACRO__ */

/** @} end of flash_status0 */

/* macros for BlueprintGlobalNameSpace::SHUB_flash_status1 */
/**
 * @defgroup at_apb_shub_regs_core_flash_status1 flash_status1
 * @brief Contains register fields associated with flash_status1. definitions.
 * @{
 */
#ifndef __SHUB_FLASH_STATUS1_MACRO__
#define __SHUB_FLASH_STATUS1_MACRO__

/* macros for field lost_write_cnt */
/**
 * @defgroup at_apb_shub_regs_core_lost_write_cnt_field lost_write_cnt_field
 * @brief macros for field lost_write_cnt
 * @{
 */
#define SHUB_FLASH_STATUS1__LOST_WRITE_CNT__SHIFT                             0
#define SHUB_FLASH_STATUS1__LOST_WRITE_CNT__WIDTH                            32
#define SHUB_FLASH_STATUS1__LOST_WRITE_CNT__MASK                    0xffffffffU
#define SHUB_FLASH_STATUS1__LOST_WRITE_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_FLASH_STATUS1__LOST_WRITE_CNT__RESET_VALUE             0x00000000U
/** @} */
#define SHUB_FLASH_STATUS1__TYPE                                       uint32_t
#define SHUB_FLASH_STATUS1__READ                                    0xffffffffU
#define SHUB_FLASH_STATUS1__PRESERVED                               0x00000000U
#define SHUB_FLASH_STATUS1__RESET_VALUE                             0x00000000U

#endif /* __SHUB_FLASH_STATUS1_MACRO__ */

/** @} end of flash_status1 */

/* macros for BlueprintGlobalNameSpace::SHUB_shub_status0 */
/**
 * @defgroup at_apb_shub_regs_core_shub_status0 shub_status0
 * @brief Contains register fields associated with shub_status0. definitions.
 * @{
 */
#ifndef __SHUB_SHUB_STATUS0_MACRO__
#define __SHUB_SHUB_STATUS0_MACRO__

/* macros for field state */
/**
 * @defgroup at_apb_shub_regs_core_state_field state_field
 * @brief macros for field state
 * @details useful for testing
 * @{
 */
#define SHUB_SHUB_STATUS0__STATE__SHIFT                                       0
#define SHUB_SHUB_STATUS0__STATE__WIDTH                                       5
#define SHUB_SHUB_STATUS0__STATE__MASK                              0x0000001fU
#define SHUB_SHUB_STATUS0__STATE__READ(src)     ((uint32_t)(src) & 0x0000001fU)
#define SHUB_SHUB_STATUS0__STATE__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field cpu_running */
/**
 * @defgroup at_apb_shub_regs_core_cpu_running_field cpu_running_field
 * @brief macros for field cpu_running
 * @details useful for testing
 * @{
 */
#define SHUB_SHUB_STATUS0__CPU_RUNNING__SHIFT                                31
#define SHUB_SHUB_STATUS0__CPU_RUNNING__WIDTH                                 1
#define SHUB_SHUB_STATUS0__CPU_RUNNING__MASK                        0x80000000U
#define SHUB_SHUB_STATUS0__CPU_RUNNING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SHUB_SHUB_STATUS0__CPU_RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SHUB_SHUB_STATUS0__CPU_RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SHUB_SHUB_STATUS0__CPU_RUNNING__RESET_VALUE                 0x00000000U
/** @} */
#define SHUB_SHUB_STATUS0__TYPE                                        uint32_t
#define SHUB_SHUB_STATUS0__READ                                     0x8000001fU
#define SHUB_SHUB_STATUS0__PRESERVED                                0x00000000U
#define SHUB_SHUB_STATUS0__RESET_VALUE                              0x00000000U

#endif /* __SHUB_SHUB_STATUS0_MACRO__ */

/** @} end of shub_status0 */

/* macros for BlueprintGlobalNameSpace::SHUB_pc_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_pc_ctrl pc_ctrl
 * @brief Contains register fields associated with pc_ctrl. definitions.
 * @{
 */
#ifndef __SHUB_PC_CTRL_MACRO__
#define __SHUB_PC_CTRL_MACRO__

/* macros for field pc_init */
/**
 * @defgroup at_apb_shub_regs_core_pc_init_field pc_init_field
 * @brief macros for field pc_init
 * @details iniital pc value
 * @{
 */
#define SHUB_PC_CTRL__PC_INIT__SHIFT                                          0
#define SHUB_PC_CTRL__PC_INIT__WIDTH                                         32
#define SHUB_PC_CTRL__PC_INIT__MASK                                 0xffffffffU
#define SHUB_PC_CTRL__PC_INIT__READ(src)        ((uint32_t)(src) & 0xffffffffU)
#define SHUB_PC_CTRL__PC_INIT__WRITE(src)       ((uint32_t)(src) & 0xffffffffU)
#define SHUB_PC_CTRL__PC_INIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_PC_CTRL__PC_INIT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_PC_CTRL__PC_INIT__RESET_VALUE                          0x00000000U
/** @} */
#define SHUB_PC_CTRL__TYPE                                             uint32_t
#define SHUB_PC_CTRL__READ                                          0xffffffffU
#define SHUB_PC_CTRL__WRITE                                         0xffffffffU
#define SHUB_PC_CTRL__PRESERVED                                     0xffffffffU
#define SHUB_PC_CTRL__RESET_VALUE                                   0x00000000U

#endif /* __SHUB_PC_CTRL_MACRO__ */

/** @} end of pc_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_pc_ctrl2 */
/**
 * @defgroup at_apb_shub_regs_core_pc_ctrl2 pc_ctrl2
 * @brief Contains register fields associated with pc_ctrl2. definitions.
 * @{
 */
#ifndef __SHUB_PC_CTRL2_MACRO__
#define __SHUB_PC_CTRL2_MACRO__

/* macros for field pc_init_load */
/**
 * @defgroup at_apb_shub_regs_core_pc_init_load_field pc_init_load_field
 * @brief macros for field pc_init_load
 * @details iniital pc value load; not self-clearing
 * @{
 */
#define SHUB_PC_CTRL2__PC_INIT_LOAD__SHIFT                                    0
#define SHUB_PC_CTRL2__PC_INIT_LOAD__WIDTH                                    1
#define SHUB_PC_CTRL2__PC_INIT_LOAD__MASK                           0x00000001U
#define SHUB_PC_CTRL2__PC_INIT_LOAD__READ(src)  ((uint32_t)(src) & 0x00000001U)
#define SHUB_PC_CTRL2__PC_INIT_LOAD__WRITE(src) ((uint32_t)(src) & 0x00000001U)
#define SHUB_PC_CTRL2__PC_INIT_LOAD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_PC_CTRL2__PC_INIT_LOAD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_PC_CTRL2__PC_INIT_LOAD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_PC_CTRL2__PC_INIT_LOAD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_PC_CTRL2__PC_INIT_LOAD__RESET_VALUE                    0x00000000U
/** @} */
#define SHUB_PC_CTRL2__TYPE                                            uint32_t
#define SHUB_PC_CTRL2__READ                                         0x00000001U
#define SHUB_PC_CTRL2__WRITE                                        0x00000001U
#define SHUB_PC_CTRL2__PRESERVED                                    0x00000001U
#define SHUB_PC_CTRL2__RESET_VALUE                                  0x00000000U

#endif /* __SHUB_PC_CTRL2_MACRO__ */

/** @} end of pc_ctrl2 */

/* macros for BlueprintGlobalNameSpace::SHUB_reg7 */
/**
 * @defgroup at_apb_shub_regs_core_reg7 reg7
 * @brief Contains register fields associated with reg7. definitions.
 * @{
 */
#ifndef __SHUB_REG7_MACRO__
#define __SHUB_REG7_MACRO__

/* macros for field r7 */
/**
 * @defgroup at_apb_shub_regs_core_r7_field r7_field
 * @brief macros for field r7
 * @details value of reg7
 * @{
 */
#define SHUB_REG7__R7__SHIFT                                                  0
#define SHUB_REG7__R7__WIDTH                                                 32
#define SHUB_REG7__R7__MASK                                         0xffffffffU
#define SHUB_REG7__R7__READ(src)                ((uint32_t)(src) & 0xffffffffU)
#define SHUB_REG7__R7__RESET_VALUE                                  0x00000000U
/** @} */
#define SHUB_REG7__TYPE                                                uint32_t
#define SHUB_REG7__READ                                             0xffffffffU
#define SHUB_REG7__PRESERVED                                        0x00000000U
#define SHUB_REG7__RESET_VALUE                                      0x00000000U

#endif /* __SHUB_REG7_MACRO__ */

/** @} end of reg7 */

/* macros for BlueprintGlobalNameSpace::SHUB_shub_sram_clk_sel */
/**
 * @defgroup at_apb_shub_regs_core_shub_sram_clk_sel shub_sram_clk_sel
 * @brief clock selection between PCLK and clk_lpc as to drive SRAM. definitions.
 * @{
 */
#ifndef __SHUB_SHUB_SRAM_CLK_SEL_MACRO__
#define __SHUB_SHUB_SRAM_CLK_SEL_MACRO__

/* macros for field shub_sram_clk_sel_ovrd */
/**
 * @defgroup at_apb_shub_regs_core_shub_sram_clk_sel_ovrd_field shub_sram_clk_sel_ovrd_field
 * @brief macros for field shub_sram_clk_sel_ovrd
 * @details override bit to shub_sram_clk mux
 * @{
 */
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__SHIFT                 0
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__WIDTH                 1
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__MASK        0x00000001U
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_OVRD__RESET_VALUE 0x00000000U
/** @} */

/* macros for field shub_sram_clk_sel_val */
/**
 * @defgroup at_apb_shub_regs_core_shub_sram_clk_sel_val_field shub_sram_clk_sel_val_field
 * @brief macros for field shub_sram_clk_sel_val
 * @details override val to shub_sram_clk mux. 0=PCLK ; 1=clk_lpc
 * @{
 */
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__SHIFT                  1
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__WIDTH                  1
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__MASK         0x00000002U
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SHUB_SHUB_SRAM_CLK_SEL__SHUB_SRAM_CLK_SEL_VAL__RESET_VALUE  0x00000000U
/** @} */
#define SHUB_SHUB_SRAM_CLK_SEL__TYPE                                   uint32_t
#define SHUB_SHUB_SRAM_CLK_SEL__READ                                0x00000003U
#define SHUB_SHUB_SRAM_CLK_SEL__WRITE                               0x00000003U
#define SHUB_SHUB_SRAM_CLK_SEL__PRESERVED                           0x00000003U
#define SHUB_SHUB_SRAM_CLK_SEL__RESET_VALUE                         0x00000000U

#endif /* __SHUB_SHUB_SRAM_CLK_SEL_MACRO__ */

/** @} end of shub_sram_clk_sel */

/* macros for BlueprintGlobalNameSpace::SHUB_regfile_sel */
/**
 * @defgroup at_apb_shub_regs_core_regfile_sel regfile_sel
 * @brief Contains register fields associated with regfile_sel. definitions.
 * @{
 */
#ifndef __SHUB_REGFILE_SEL_MACRO__
#define __SHUB_REGFILE_SEL_MACRO__

/* macros for field sel */
/**
 * @defgroup at_apb_shub_regs_core_sel_field sel_field
 * @brief macros for field sel
 * @details select which reg in regfile to be connected to reg7
 * @{
 */
#define SHUB_REGFILE_SEL__SEL__SHIFT                                          0
#define SHUB_REGFILE_SEL__SEL__WIDTH                                          4
#define SHUB_REGFILE_SEL__SEL__MASK                                 0x0000000fU
#define SHUB_REGFILE_SEL__SEL__READ(src)        ((uint32_t)(src) & 0x0000000fU)
#define SHUB_REGFILE_SEL__SEL__WRITE(src)       ((uint32_t)(src) & 0x0000000fU)
#define SHUB_REGFILE_SEL__SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define SHUB_REGFILE_SEL__SEL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define SHUB_REGFILE_SEL__SEL__RESET_VALUE                          0x00000007U
/** @} */
#define SHUB_REGFILE_SEL__TYPE                                         uint32_t
#define SHUB_REGFILE_SEL__READ                                      0x0000000fU
#define SHUB_REGFILE_SEL__WRITE                                     0x0000000fU
#define SHUB_REGFILE_SEL__PRESERVED                                 0x00000000U
#define SHUB_REGFILE_SEL__RESET_VALUE                               0x00000007U

#endif /* __SHUB_REGFILE_SEL_MACRO__ */

/** @} end of regfile_sel */

/* macros for BlueprintGlobalNameSpace::SHUB_regfile_regw */
/**
 * @defgroup at_apb_shub_regs_core_regfile_regw regfile_regw
 * @brief Contains register fields associated with regfile_regw. definitions.
 * @{
 */
#ifndef __SHUB_REGFILE_REGW_MACRO__
#define __SHUB_REGFILE_REGW_MACRO__

/* macros for field regfile_wdata */
/**
 * @defgroup at_apb_shub_regs_core_regfile_wdata_field regfile_wdata_field
 * @brief macros for field regfile_wdata
 * @details write data to selected reg in regfile. The selection pointer is regfile_sel
 * @{
 */
#define SHUB_REGFILE_REGW__REGFILE_WDATA__SHIFT                               0
#define SHUB_REGFILE_REGW__REGFILE_WDATA__WIDTH                              32
#define SHUB_REGFILE_REGW__REGFILE_WDATA__MASK                      0xffffffffU
#define SHUB_REGFILE_REGW__REGFILE_WDATA__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_REGFILE_REGW__REGFILE_WDATA__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_REGFILE_REGW__REGFILE_WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_REGFILE_REGW__REGFILE_WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_REGFILE_REGW__REGFILE_WDATA__RESET_VALUE               0x00000000U
/** @} */
#define SHUB_REGFILE_REGW__TYPE                                        uint32_t
#define SHUB_REGFILE_REGW__READ                                     0xffffffffU
#define SHUB_REGFILE_REGW__WRITE                                    0xffffffffU
#define SHUB_REGFILE_REGW__PRESERVED                                0x00000000U
#define SHUB_REGFILE_REGW__RESET_VALUE                              0x00000000U

#endif /* __SHUB_REGFILE_REGW_MACRO__ */

/** @} end of regfile_regw */

/* macros for BlueprintGlobalNameSpace::SHUB_round_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_round_ctrl round_ctrl
 * @brief Contains register fields associated with round_ctrl. definitions.
 * @{
 */
#ifndef __SHUB_ROUND_CTRL_MACRO__
#define __SHUB_ROUND_CTRL_MACRO__

/* macros for field round_limit */
/**
 * @defgroup at_apb_shub_regs_core_round_limit_field round_limit_field
 * @brief macros for field round_limit
 * @details number of adv rounds to do before exiting. In non adv mode, this parameter sets the number of read/write rounds before exiting.
 * @{
 */
#define SHUB_ROUND_CTRL__ROUND_LIMIT__SHIFT                                   0
#define SHUB_ROUND_CTRL__ROUND_LIMIT__WIDTH                                  32
#define SHUB_ROUND_CTRL__ROUND_LIMIT__MASK                          0xffffffffU
#define SHUB_ROUND_CTRL__ROUND_LIMIT__READ(src) ((uint32_t)(src) & 0xffffffffU)
#define SHUB_ROUND_CTRL__ROUND_LIMIT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_ROUND_CTRL__ROUND_LIMIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SHUB_ROUND_CTRL__ROUND_LIMIT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SHUB_ROUND_CTRL__ROUND_LIMIT__RESET_VALUE                   0x00000003U
/** @} */
#define SHUB_ROUND_CTRL__TYPE                                          uint32_t
#define SHUB_ROUND_CTRL__READ                                       0xffffffffU
#define SHUB_ROUND_CTRL__WRITE                                      0xffffffffU
#define SHUB_ROUND_CTRL__PRESERVED                                  0x00000000U
#define SHUB_ROUND_CTRL__RESET_VALUE                                0x00000003U

#endif /* __SHUB_ROUND_CTRL_MACRO__ */

/** @} end of round_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_adv_round_stat */
/**
 * @defgroup at_apb_shub_regs_core_adv_round_stat adv_round_stat
 * @brief Contains register fields associated with adv_round_stat. definitions.
 * @{
 */
#ifndef __SHUB_ADV_ROUND_STAT_MACRO__
#define __SHUB_ADV_ROUND_STAT_MACRO__

/* macros for field adv_curr_round */
/**
 * @defgroup at_apb_shub_regs_core_adv_curr_round_field adv_curr_round_field
 * @brief macros for field adv_curr_round
 * @details current count of adv rounds.
 * @{
 */
#define SHUB_ADV_ROUND_STAT__ADV_CURR_ROUND__SHIFT                            0
#define SHUB_ADV_ROUND_STAT__ADV_CURR_ROUND__WIDTH                           32
#define SHUB_ADV_ROUND_STAT__ADV_CURR_ROUND__MASK                   0xffffffffU
#define SHUB_ADV_ROUND_STAT__ADV_CURR_ROUND__READ(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define SHUB_ADV_ROUND_STAT__ADV_CURR_ROUND__RESET_VALUE            0x00000000U
/** @} */
#define SHUB_ADV_ROUND_STAT__TYPE                                      uint32_t
#define SHUB_ADV_ROUND_STAT__READ                                   0xffffffffU
#define SHUB_ADV_ROUND_STAT__PRESERVED                              0x00000000U
#define SHUB_ADV_ROUND_STAT__RESET_VALUE                            0x00000000U

#endif /* __SHUB_ADV_ROUND_STAT_MACRO__ */

/** @} end of adv_round_stat */

/* macros for BlueprintGlobalNameSpace::SHUB_adv_dur_ctrl */
/**
 * @defgroup at_apb_shub_regs_core_adv_dur_ctrl adv_dur_ctrl
 * @brief Contains register fields associated with adv_dur_ctrl. definitions.
 * @{
 */
#ifndef __SHUB_ADV_DUR_CTRL_MACRO__
#define __SHUB_ADV_DUR_CTRL_MACRO__

/* macros for field adv_dur */
/**
 * @defgroup at_apb_shub_regs_core_adv_dur_field adv_dur_field
 * @brief macros for field adv_dur
 * @details duration of advertisment phase in low power clock cycles.
 * @{
 */
#define SHUB_ADV_DUR_CTRL__ADV_DUR__SHIFT                                     0
#define SHUB_ADV_DUR_CTRL__ADV_DUR__WIDTH                                    10
#define SHUB_ADV_DUR_CTRL__ADV_DUR__MASK                            0x000003ffU
#define SHUB_ADV_DUR_CTRL__ADV_DUR__READ(src)   ((uint32_t)(src) & 0x000003ffU)
#define SHUB_ADV_DUR_CTRL__ADV_DUR__WRITE(src)  ((uint32_t)(src) & 0x000003ffU)
#define SHUB_ADV_DUR_CTRL__ADV_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define SHUB_ADV_DUR_CTRL__ADV_DUR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define SHUB_ADV_DUR_CTRL__ADV_DUR__RESET_VALUE                     0x00000096U
/** @} */

/* macros for field adv_dur_en */
/**
 * @defgroup at_apb_shub_regs_core_adv_dur_en_field adv_dur_en_field
 * @brief macros for field adv_dur_en
 * @details enables adv_dur for the advertisement phase
 * @{
 */
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__SHIFT                                 31
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__WIDTH                                  1
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__MASK                         0x80000000U
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define SHUB_ADV_DUR_CTRL__ADV_DUR_EN__RESET_VALUE                  0x00000001U
/** @} */
#define SHUB_ADV_DUR_CTRL__TYPE                                        uint32_t
#define SHUB_ADV_DUR_CTRL__READ                                     0x800003ffU
#define SHUB_ADV_DUR_CTRL__WRITE                                    0x800003ffU
#define SHUB_ADV_DUR_CTRL__PRESERVED                                0x00000000U
#define SHUB_ADV_DUR_CTRL__RESET_VALUE                              0x80000096U

#endif /* __SHUB_ADV_DUR_CTRL_MACRO__ */

/** @} end of adv_dur_ctrl */

/* macros for BlueprintGlobalNameSpace::SHUB_id */
/**
 * @defgroup at_apb_shub_regs_core_id id
 * @brief Contains register fields associated with id. definitions.
 * @{
 */
#ifndef __SHUB_ID_MACRO__
#define __SHUB_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_shub_regs_core_id_field id_field
 * @brief macros for field id
 * @details SHUB in ASCII
 * @{
 */
#define SHUB_ID__ID__SHIFT                                                    0
#define SHUB_ID__ID__WIDTH                                                   32
#define SHUB_ID__ID__MASK                                           0xffffffffU
#define SHUB_ID__ID__READ(src)                  ((uint32_t)(src) & 0xffffffffU)
#define SHUB_ID__ID__RESET_VALUE                                    0x53485542U
/** @} */
#define SHUB_ID__TYPE                                                  uint32_t
#define SHUB_ID__READ                                               0xffffffffU
#define SHUB_ID__PRESERVED                                          0x00000000U
#define SHUB_ID__RESET_VALUE                                        0x53485542U

#endif /* __SHUB_ID_MACRO__ */

/** @} end of id */

/* macros for BlueprintGlobalNameSpace::SHUB_rev_hash */
/**
 * @defgroup at_apb_shub_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __SHUB_REV_HASH_MACRO__
#define __SHUB_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_shub_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define SHUB_REV_HASH__ID__SHIFT                                              0
#define SHUB_REV_HASH__ID__WIDTH                                             32
#define SHUB_REV_HASH__ID__MASK                                     0xffffffffU
#define SHUB_REV_HASH__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define SHUB_REV_HASH__ID__RESET_VALUE                              0x702042cfU
/** @} */
#define SHUB_REV_HASH__TYPE                                            uint32_t
#define SHUB_REV_HASH__READ                                         0xffffffffU
#define SHUB_REV_HASH__PRESERVED                                    0x00000000U
#define SHUB_REV_HASH__RESET_VALUE                                  0x702042cfU

#endif /* __SHUB_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::SHUB_rev_key */
/**
 * @defgroup at_apb_shub_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __SHUB_REV_KEY_MACRO__
#define __SHUB_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_shub_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define SHUB_REV_KEY__ID__SHIFT                                               0
#define SHUB_REV_KEY__ID__WIDTH                                              32
#define SHUB_REV_KEY__ID__MASK                                      0xffffffffU
#define SHUB_REV_KEY__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define SHUB_REV_KEY__ID__RESET_VALUE                               0x52455620U
/** @} */
#define SHUB_REV_KEY__TYPE                                             uint32_t
#define SHUB_REV_KEY__READ                                          0xffffffffU
#define SHUB_REV_KEY__PRESERVED                                     0x00000000U
#define SHUB_REV_KEY__RESET_VALUE                                   0x52455620U

#endif /* __SHUB_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_SHUB_REGS_CORE */
#endif /* __REG_AT_APB_SHUB_REGS_CORE_H__ */
