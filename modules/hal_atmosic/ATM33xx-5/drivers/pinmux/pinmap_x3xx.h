/**
 *******************************************************************************
 *
 * @file pinmap_x3xx.h
 *
 * @brief Pin mappings that are identical across all the boards for a given chip
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup PINMAP_X3XX PINMAP_X3XX
 * @ingroup PINMUX_X3XX
 * @brief Chip specific pin definitions
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "pinmux_x3xx.h"
#ifdef PINMAP_X3XX_OVERLAY
#include STR(PINMAP_X3XX_OVERLAY)
#endif

/* GPIO to pin mapping common across the released boards */
#define PIN_GPIO_0 0
#define PIN_GPIO_1 1
#define PIN_GPIO_2 2
#define PIN_GPIO_3 3
#define PIN_GPIO_4 4
#define PIN_GPIO_5 5
#define PIN_GPIO_6 6
#define PIN_GPIO_7 7
#define PIN_GPIO_8 8
#define PIN_GPIO_9 9
#define PIN_GPIO_10 10
#define PIN_GPIO_11 11
#define PIN_GPIO_12 12
#define PIN_GPIO_13 13
#define PIN_GPIO_14 14
#define PIN_GPIO_15 15
#define PIN_GPIO_16 16
#define PIN_GPIO_17 17
#define PIN_GPIO_18 18
#define PIN_GPIO_19 19
#define PIN_GPIO_20 20
#define PIN_GPIO_21 21
#define PIN_GPIO_22 22
#define PIN_GPIO_23 23
#define PIN_GPIO_24 24
#define PIN_GPIO_25 25
#define PIN_GPIO_26 26
#define PIN_GPIO_27 27
#define PIN_GPIO_28 28
#define PIN_GPIO_29 29
#define PIN_GPIO_30 30

/* Pin to GPIO bit mapping across the released boards */
#define P0_GPIO 0
#define P1_GPIO 1
#define P2_GPIO 2
#define P3_GPIO 3
#define P4_GPIO 4
#define P5_GPIO 5
#define P6_GPIO 6
#define P7_GPIO 7
#define P8_GPIO 8
#define P9_GPIO 9
#define P10_GPIO 10
#define P11_GPIO 11
#define P12_GPIO 12
#define P13_GPIO 13
#define P14_GPIO 14
#define P15_GPIO 15
#define P16_GPIO 16
#define P17_GPIO 17
#define P18_GPIO 18
#define P19_GPIO 19
#define P20_GPIO 20
#define P21_GPIO 21
#define P22_GPIO 22
#define P23_GPIO 23
#define P24_GPIO 24
#define P25_GPIO 25
#define P26_GPIO 26
#define P27_GPIO 27
#define P28_GPIO 28
#define P29_GPIO 29
#define P30_GPIO 30

#define GPIO_VALID_PIN_MASK_COMMON \
    ((1UL << P0_GPIO) | (1UL << P1_GPIO) | (1UL << P3_GPIO) | \
    (1UL << P4_GPIO) | (1UL << P5_GPIO) | (1UL << P6_GPIO) | \
    (1UL << P7_GPIO) | (1UL << P12_GPIO) | (1UL << P13_GPIO) | \
    (1UL << P14_GPIO) | (1UL << P15_GPIO) | (1UL << P17_GPIO) | \
    (1UL << P18_GPIO) | (1UL << P19_GPIO) | (1UL << P20_GPIO) | \
    (1UL << P21_GPIO) | (1UL << P22_GPIO) | (1UL << P25_GPIO) | \
    (1UL << P27_GPIO) | (1UL << P29_GPIO) | (1UL << P30_GPIO))

/* Pin to DBG_GRP and DBG_CLK_IO mapping */
#define P3_DBG_GRP_CLK_CP 4
#define P4_DBG_GRP_CLK_CP 15
#define P7_DBG_GRP_CLK_CP 4
#define P8_DBG_GRP_CLK_CP 15
#define P9_DBG_GRP_CLK_CP 4
#define P10_DBG_GRP_CLK_CP 4
#define P11_DBG_GRP_CLK_CP 4
#define P12_DBG_GRP_CLK_CP 15
#define P13_DBG_GRP_CLK_CP 5
#define P14_DBG_GRP_CLK_CP 4
#define P15_DBG_GRP_CLK_CP 4
#define P21_DBG_GRP_CLK_CP 5
#define P25_DBG_GRP_CLK_CP 5
#define P26_DBG_GRP_CLK_CP 4
#define P27_DBG_GRP_CLK_CP 5
#define P28_DBG_GRP_CLK_CP 5
#define P29_DBG_GRP_CLK_CP 5
#define P30_DBG_GRP_CLK_CP 4

#define P3_DBG_SHIFT_CLK_CP 4
#define P4_DBG_SHIFT_CLK_CP 4
#define P7_DBG_SHIFT_CLK_CP 3
#define P8_DBG_SHIFT_CLK_CP 3
#define P9_DBG_SHIFT_CLK_CP 2
#define P10_DBG_SHIFT_CLK_CP 1
#define P11_DBG_SHIFT_CLK_CP 0
#define P12_DBG_SHIFT_CLK_CP 0
#define P13_DBG_SHIFT_CLK_CP 5
#define P14_DBG_SHIFT_CLK_CP 1
#define P15_DBG_SHIFT_CLK_CP 0
#define P21_DBG_SHIFT_CLK_CP 4
#define P25_DBG_SHIFT_CLK_CP 3
#define P26_DBG_SHIFT_CLK_CP 5
#define P27_DBG_SHIFT_CLK_CP 2
#define P28_DBG_SHIFT_CLK_CP 1
#define P29_DBG_SHIFT_CLK_CP 0
#define P30_DBG_SHIFT_CLK_CP 5

#define P0_DBG_GRP_PMU_DIG_TEST_OUT 6
#define P8_DBG_GRP_PMU_DIG_TEST_OUT 6
#define P12_DBG_GRP_PMU_DIG_TEST_OUT 6
#define P14_DBG_GRP_PMU_DIG_TEST_OUT 6
#define P15_DBG_GRP_PMU_DIG_TEST_OUT 6
#define P16_DBG_GRP_PMU_DIG_TEST_OUT 6

#define P0_DBG_SHIFT_PMU_DIG_TEST_OUT 5
#define P8_DBG_SHIFT_PMU_DIG_TEST_OUT 4
#define P12_DBG_SHIFT_PMU_DIG_TEST_OUT 3
#define P14_DBG_SHIFT_PMU_DIG_TEST_OUT 2
#define P15_DBG_SHIFT_PMU_DIG_TEST_OUT 1
#define P16_DBG_SHIFT_PMU_DIG_TEST_OUT 0

/* PWM pin to channel mapping valid for all packages */
#define PWM_PIN0_CH 0
#define PWM_PIN1_CH 1
#define PWM_PIN4_CH 4
#define PWM_PIN5_CH 5
#define PWM_PIN15_CH 7
#define PWM_PIN17_CH 1
#define PWM_PIN18_CH 2
#define PWM_PIN19_CH 3
#define PWM_PIN20_CH 4
#define PWM_PIN21_CH 5
#define PWM_PIN22_CH 6
#define PWM_PIN25_CH 1
#define PWM_PIN27_CH 1
#define PWM_PIN29_CH 3
#define PWM_PIN30_CH 0

/*
 * GPIO reg base mapping
 */
#define GPIO_0_BASE CMSDK_GPIO0
#define GPIO_1_BASE CMSDK_GPIO0
#define GPIO_2_BASE CMSDK_GPIO0
#define GPIO_3_BASE CMSDK_GPIO0
#define GPIO_4_BASE CMSDK_GPIO0
#define GPIO_5_BASE CMSDK_GPIO0
#define GPIO_6_BASE CMSDK_GPIO0
#define GPIO_7_BASE CMSDK_GPIO0
#define GPIO_8_BASE CMSDK_GPIO0
#define GPIO_9_BASE CMSDK_GPIO0
#define GPIO_10_BASE CMSDK_GPIO0
#define GPIO_11_BASE CMSDK_GPIO0
#define GPIO_12_BASE CMSDK_GPIO0
#define GPIO_13_BASE CMSDK_GPIO0
#define GPIO_14_BASE CMSDK_GPIO0
#define GPIO_15_BASE CMSDK_GPIO0
#define GPIO_16_BASE CMSDK_GPIO1
#define GPIO_17_BASE CMSDK_GPIO1
#define GPIO_18_BASE CMSDK_GPIO1
#define GPIO_19_BASE CMSDK_GPIO1
#define GPIO_20_BASE CMSDK_GPIO1
#define GPIO_21_BASE CMSDK_GPIO1
#define GPIO_22_BASE CMSDK_GPIO1
#define GPIO_23_BASE CMSDK_GPIO1
#define GPIO_24_BASE CMSDK_GPIO1
#define GPIO_25_BASE CMSDK_GPIO1
#define GPIO_26_BASE CMSDK_GPIO1
#define GPIO_27_BASE CMSDK_GPIO1
#define GPIO_28_BASE CMSDK_GPIO1
#define GPIO_29_BASE CMSDK_GPIO1
#define GPIO_30_BASE CMSDK_GPIO1

#ifdef __cplusplus
}
#endif

/// @}
