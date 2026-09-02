/**
 *******************************************************************************
 *
 * @file pinmap_5xxx.h
 *
 * @brief Pin mappings that are identical across all the boards for a given chip
 *
 * Copyright (C) Atmosic 2023-2026
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup PINMAP_5XXX PINMAP_5XXX
 * @ingroup PINMUX_5XXX
 * @brief Chip specific pin definitions
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "pinmux_5xxx.h"
#ifdef PINMAP_5XXX_OVERLAY
#include STR(PINMAP_5XXX_OVERLAY)
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
#define PIN_GPIO_31 31
#define PIN_GPIO_32 32
#define PIN_GPIO_33 33
#define PIN_GPIO_34 34
#define PIN_GPIO_35 35
#define PIN_GPIO_36 36
#define PIN_GPIO_37 37
#define PIN_GPIO_38 38
#define PIN_GPIO_39 39
#define PIN_GPIO_40 40
#define PIN_GPIO_41 41
#define PIN_GPIO_42 42
#define PIN_GPIO_43 43
#define PIN_GPIO_44 44
#define PIN_GPIO_45 45
#define PIN_GPIO_46 46
#define PIN_GPIO_47 47

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
#define P31_GPIO 31
#define P32_GPIO 32
#define P33_GPIO 33
#define P34_GPIO 34
#define P35_GPIO 35
#define P36_GPIO 36
#define P37_GPIO 37
#define P38_GPIO 38
#define P39_GPIO 39
#define P40_GPIO 40
#define P41_GPIO 41
#define P42_GPIO 42
#define P43_GPIO 43
#define P44_GPIO 44
#define P45_GPIO 45
#define P46_GPIO 46
#define P47_GPIO 47

#define GPIO_VALID_PIN_MASK_COMMON \
    ((1ULL << P0_GPIO) | (1ULL << P1_GPIO) | (1ULL << P8_GPIO) | \
    (1ULL << P9_GPIO) | (1ULL << P10_GPIO) | (1ULL << P11_GPIO) | \
    (1ULL << P12_GPIO) | (1ULL << P13_GPIO) | (1ULL << P25_GPIO) | \
    (1ULL << P27_GPIO) | (1ULL << P37_GPIO) | (1ULL << P38_GPIO) | \
    (1ULL << P39_GPIO) | (1ULL << P41_GPIO))

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
#define P27_DBG_GRP_CLK_CP 5
#define P28_DBG_GRP_CLK_CP 5
#define P29_DBG_GRP_CLK_CP 5

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
#define P27_DBG_SHIFT_CLK_CP 2
#define P28_DBG_SHIFT_CLK_CP 1
#define P29_DBG_SHIFT_CLK_CP 0

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
#define GPIO_31_BASE CMSDK_GPIO1
#define GPIO_32_BASE CMSDK_GPIO2
#define GPIO_33_BASE CMSDK_GPIO2
#define GPIO_34_BASE CMSDK_GPIO2
#define GPIO_35_BASE CMSDK_GPIO2
#define GPIO_36_BASE CMSDK_GPIO2
#define GPIO_37_BASE CMSDK_GPIO2
#define GPIO_38_BASE CMSDK_GPIO2
#define GPIO_39_BASE CMSDK_GPIO2
#define GPIO_40_BASE CMSDK_GPIO2
#define GPIO_41_BASE CMSDK_GPIO2
#define GPIO_42_BASE CMSDK_GPIO2
#define GPIO_43_BASE CMSDK_GPIO2
#define GPIO_44_BASE CMSDK_GPIO2
#define GPIO_45_BASE CMSDK_GPIO2
#define GPIO_46_BASE CMSDK_GPIO2
#define GPIO_47_BASE CMSDK_GPIO2

/*
 * GPIO IRQ mapping
 */
#define GPIO_0_IRQ PORT0_0_IRQn
#define GPIO_1_IRQ PORT0_1_IRQn
#define GPIO_2_IRQ PORT0_2_IRQn
#define GPIO_3_IRQ PORT0_3_IRQn
#define GPIO_4_IRQ PORT0_4_IRQn
#define GPIO_5_IRQ PORT0_5_IRQn
#define GPIO_6_IRQ PORT0_6_IRQn
#define GPIO_7_IRQ PORT0_7_IRQn
#define GPIO_8_IRQ PORT0_8_IRQn
#define GPIO_9_IRQ PORT0_9_IRQn
#define GPIO_10_IRQ PORT0_10_IRQn
#define GPIO_11_IRQ PORT0_11_IRQn
#define GPIO_12_IRQ PORT0_12_IRQn
#define GPIO_13_IRQ PORT0_13_IRQn
#define GPIO_14_IRQ PORT0_14_IRQn
#define GPIO_15_IRQ PORT0_15_IRQn
#define GPIO_16_IRQ PORT1_0_IRQn
#define GPIO_17_IRQ PORT1_1_IRQn
#define GPIO_18_IRQ PORT1_2_IRQn
#define GPIO_19_IRQ PORT1_3_IRQn
#define GPIO_20_IRQ PORT1_4_IRQn
#define GPIO_21_IRQ PORT1_5_IRQn
#define GPIO_22_IRQ PORT1_6_IRQn
#define GPIO_23_IRQ PORT1_7_IRQn
#define GPIO_24_IRQ PORT1_8_IRQn
#define GPIO_25_IRQ PORT1_9_IRQn
#define GPIO_26_IRQ PORT1_10_IRQn
#define GPIO_27_IRQ PORT1_11_IRQn
#define GPIO_28_IRQ PORT1_12_IRQn
#define GPIO_29_IRQ PORT1_13_IRQn
#define GPIO_30_IRQ PORT1_14_IRQn
#define GPIO_31_IRQ PORT1_15_IRQn
#define GPIO_32_IRQ PORT2_0_IRQn
#define GPIO_33_IRQ PORT2_1_IRQn
#define GPIO_34_IRQ PORT2_2_IRQn
#define GPIO_35_IRQ PORT2_3_IRQn
#define GPIO_36_IRQ PORT2_4_IRQn
#define GPIO_37_IRQ PORT2_5_IRQn
#define GPIO_38_IRQ PORT2_6_IRQn
#define GPIO_39_IRQ PORT2_7_IRQn
#define GPIO_40_IRQ PORT2_8_IRQn
#define GPIO_41_IRQ PORT2_9_IRQn
#define GPIO_42_IRQ PORT2_10_IRQn
#define GPIO_43_IRQ PORT2_11_IRQn
#define GPIO_44_IRQ PORT2_12_IRQn
#define GPIO_45_IRQ PORT2_13_IRQn
#define GPIO_46_IRQ PORT2_14_IRQn
#define GPIO_47_IRQ PORT2_15_IRQn

#ifdef __cplusplus
}
#endif

/// @}
