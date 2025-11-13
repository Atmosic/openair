/**
 *****************************************************************************
 *
 * @file pmu_spi.h
 *
 * @brief PMU SPI definitions
 *
 * Copyright (C) Atmosic 2022-2025
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

#define SWREG_AON__REG_BLADDR                             0
#define SWREG_AON__AON0_REG_ADDR                          0x0
#define SWREG_AON__AON1_REG_ADDR                          0x4
#define SWREG_AON__AON2_REG_ADDR                          0x8
#define SWREG_AON__AON3_REG_ADDR                          0xc
#define SWREG_AON__AON4_REG_ADDR                          0x10
#define SWREG_AON__AON5_REG_ADDR                          0x14
#define SWREG_AON__AON6_REG_ADDR                          0x18
#define SWREG_AON__READOUT_REG_ADDR                       0x1c
#define SWREG_AON__CORE_ID_REG_ADDR                       0x20

#define SWREG_SIMPLE__REG_BLADDR                          1
#define SWREG_SIMPLE__SIMPLE0_REG_ADDR                    0x0
#define SWREG_SIMPLE__SIMPLE1_REG_ADDR                    0x4
#define SWREG_SIMPLE__SIMPLE2_REG_ADDR                    0x8
#define SWREG_SIMPLE__CORE_ID_REG_ADDR                    0xc

#define SWREG_MAIN__REG_BLADDR                            2
#define SWREG_MAIN__MAIN0_REG_ADDR                        0x0
#define SWREG_MAIN__MAIN1_REG_ADDR                        0x4
#define SWREG_MAIN__MAIN2_REG_ADDR                        0x8
#define SWREG_MAIN__MAIN3_REG_ADDR                        0xc
#define SWREG_MAIN__MAIN4_REG_ADDR                        0x10
#define SWREG_MAIN__MAIN5_REG_ADDR                        0x14
#define SWREG_MAIN__MAIN6_REG_ADDR                        0x18
#define SWREG_MAIN__MAIN7_REG_ADDR                        0x1c
#define SWREG_MAIN__MAIN8_REG_ADDR                        0x20
#define SWREG_MAIN__MAIN9_REG_ADDR                        0x24
#define SWREG_MAIN__MAIN10_REG_ADDR                       0x28
#define SWREG_MAIN__READOUT0_REG_ADDR                     0x2c
#define SWREG_MAIN__READOUT1_REG_ADDR                     0x30
#define SWREG_MAIN__READOUT2_REG_ADDR                     0x34
#define SWREG_MAIN__READOUT3_REG_ADDR                     0x38
#define SWREG_MAIN__CORE_ID_REG_ADDR                      0x3c

#define PMU_TOP__REG_BLADDR                               9
#define PMU_TOP__PMU0_REG_ADDR                            0x0
#define PMU_TOP__PMU1_REG_ADDR                            0x4
#define PMU_TOP__PMU1A_REG_ADDR                           0x8
#define PMU_TOP__PMU2_REG_ADDR                            0xc
#define PMU_TOP__PMU2A_REG_ADDR                           0x10
#define PMU_TOP__PMU3_REG_ADDR                            0x14
#define PMU_TOP__PMU4_REG_ADDR                            0x18
#define PMU_TOP__PMU5_REG_ADDR                            0x1c
#define PMU_TOP__PMU6_REG_ADDR                            0x20
#define PMU_TOP__PMU7_REG_ADDR                            0x24
#define PMU_TOP__PMU8_REG_ADDR                            0x28
#define PMU_TOP__PMU9_REG_ADDR                            0x2c
#define PMU_TOP__PMU10_REG_ADDR                           0x30
#define PMU_TOP__PMU11_REG_ADDR                           0x34
#define PMU_TOP__PMU12_REG_ADDR                           0x38
#define PMU_TOP__PMU12A_REG_ADDR                          0x3c
#define PMU_TOP__PMU13_REG_ADDR                           0x40
#define PMU_TOP__PMU14_REG_ADDR                           0x44
#define PMU_TOP__PMU14A_REG_ADDR                          0x48
#define PMU_TOP__PMU14B_REG_ADDR                          0x4c
#define PMU_TOP__PMU14C_REG_ADDR                          0x50
#define PMU_TOP__PMU15_REG_ADDR                           0x54
#define PMU_TOP__PMU16_REG_ADDR                           0x58
#define PMU_TOP__CHRG_CTRL_REG_ADDR                       0x5c
#define PMU_TOP__CHRG_CTRL2_REG_ADDR                      0x60
#define PMU_TOP__PMU17_REG_ADDR                           0x64
#define PMU_TOP__PMU18_REG_ADDR                           0x68
#define PMU_TOP__PMU_RB0_REG_ADDR                         0x6c
#define PMU_TOP__PMU_RB1_REG_ADDR                         0x70
#define PMU_TOP__PMU_RB2_REG_ADDR                         0x74
#define PMU_TOP__PMU_RB_MPPT_REG_ADDR                     0x78
#define PMU_TOP__PMU_RB3_REG_ADDR                         0x7c
#define PMU_TOP__PMU_RB4_REG_ADDR                         0x80
#define PMU_TOP__PMU_RB5_REG_ADDR                         0x84
#define PMU_TOP__CORE_ID_REG_ADDR                         0x88

#define PMU_WURX__REG_BLADDR                              10
#define PMU_WURX__WURX_GENERAL_REG_ADDR                   0x0
#define PMU_WURX__WURX_GENERAL2_REG_ADDR                  0x4
#define PMU_WURX__WURX0_0_REG_ADDR                        0x8
#define PMU_WURX__WURX0_1_REG_ADDR                        0xc
#define PMU_WURX__WURX0_2_REG_ADDR                        0x10
#define PMU_WURX__WURX0_3_REG_ADDR                        0x14
#define PMU_WURX__WURX0_4_REG_ADDR                        0x18
#define PMU_WURX__WURX1_0_REG_ADDR                        0x1c
#define PMU_WURX__WURX1_1_REG_ADDR                        0x20
#define PMU_WURX__WURX1_2_REG_ADDR                        0x24
#define PMU_WURX__WURX1_3_REG_ADDR                        0x28
#define PMU_WURX__WURX1_4_REG_ADDR                        0x2c
#define PMU_WURX__WURX_RB0_REG_ADDR                       0x30
#define PMU_WURX__WURX_RB1_REG_ADDR                       0x34
#define PMU_WURX__WURX_RB2_REG_ADDR                       0x38
#define PMU_WURX__WURX_SPARE_REG_ADDR                     0x3c
#define PMU_WURX__CORE_ID_REG_ADDR                        0x40

#define PMU_GADC__REG_BLADDR                              11
#define PMU_GADC__GADC_CTRL_REG_ADDR                      0x0
#define PMU_GADC__CORE_ID_REG_ADDR                        0x4

#define PMU_PMUADC__REG_BLADDR                            13
#define PMU_PMUADC__REG0_REG_ADDR                         0x0
#define PMU_PMUADC__MAIN1_REG_ADDR                        0x4
#define PMU_PMUADC__PMUADC_CTRLR_REG_ADDR                 0x8
#define PMU_PMUADC__MEAS_PERIOD0_REG_ADDR                 0xc
#define PMU_PMUADC__MEAS_PERIOD1_REG_ADDR                 0x10
#define PMU_PMUADC__CMPOUT_PARAM_1_REG_ADDR               0x14
#define PMU_PMUADC__CMPOUT_PARAM_2_REG_ADDR               0x18
#define PMU_PMUADC__CMPOUT_PARAM_3_REG_ADDR               0x1c
#define PMU_PMUADC__CMPOUT_PARAM_4_REG_ADDR               0x20
#define PMU_PMUADC__PMUADC_READOUT0_REG_ADDR              0x24
#define PMU_PMUADC__PMUADC_READOUT1_REG_ADDR              0x28
#define PMU_PMUADC__CORE_ID_REG_ADDR                      0x2c

/** @} end of at_pmu_spi */
