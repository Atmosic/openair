/**
 *****************************************************************************
 *
 * @file pmu_spi.h
 *
 * @brief PMU SPI definitions
 *
 * Copyright (C) Atmosic 2022-2026
 *
 *****************************************************************************
 */

#pragma once

/**
 * @defgroup at_pmu_spi pmu_spi
 * @ingroup AT_REG
 * @brief pmu spi definitions.
 * @{
 */
#define PMU_SPI__DUMMY_CYCLES                             3

#define PMU_TOP__REG_BLADDR                               9
#define PMU_TOP__PMU0_REG_ADDR                            0x0
#define PMU_TOP__PMU1_REG_ADDR                            0x4
#define PMU_TOP__PMU1A_REG_ADDR                           0x8
#define PMU_TOP__PMU2_REG_ADDR                            0xc
#define PMU_TOP__PMU3_REG_ADDR                            0x10
#define PMU_TOP__PMU4_REG_ADDR                            0x14
#define PMU_TOP__PMU4A_REG_ADDR                           0x18
#define PMU_TOP__PMU5_REG_ADDR                            0x1c
#define PMU_TOP__PMU6_REG_ADDR                            0x20
#define PMU_TOP__PMU7_REG_ADDR                            0x24
#define PMU_TOP__PMU8_REG_ADDR                            0x28
#define PMU_TOP__PMU9_REG_ADDR                            0x2c
#define PMU_TOP__PMU10_REG_ADDR                           0x30
#define PMU_TOP__PMU11_REG_ADDR                           0x34
#define PMU_TOP__PMU12_REG_ADDR                           0x38
#define PMU_TOP__PMU13_REG_ADDR                           0x3c
#define PMU_TOP__PMU14_REG_ADDR                           0x40
#define PMU_TOP__PMU15_REG_ADDR                           0x44
#define PMU_TOP__PMU16_REG_ADDR                           0x48
#define PMU_TOP__PMU_RB0_REG_ADDR                         0x4c
#define PMU_TOP__PMU_RB1_REG_ADDR                         0x50
#define PMU_TOP__PMU_RB2_REG_ADDR                         0x54
#define PMU_TOP__PMU_RB3_REG_ADDR                         0x58
#define PMU_TOP__PMU_RB4_REG_ADDR                         0x5c
#define PMU_TOP__PMU_RB5_REG_ADDR                         0x60
#define PMU_TOP__CORE_ID_REG_ADDR                         0x64
#define PMU_TOP__PMU_WDOG_CTRL_REG_ADDR                   0x68
#define PMU_TOP__PMU_WDOG_REG_ADDR                        0x6c
#define PMU_TOP__PMU_WDOG_STATUS_REG_ADDR                 0x70
#define PMU_TOP__PMU_SWCNT_RB_REG_ADDR                    0x74

#define PMU_GADC__REG_BLADDR                              11
#define PMU_GADC__GADC_CTRL_REG_ADDR                      0x0
#define PMU_GADC__CORE_ID_REG_ADDR                        0x4

/** @} end of at_pmu_spi */
