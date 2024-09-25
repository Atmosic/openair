/**
 *******************************************************************************
 *
 * @file pinmap_x2xx.h
 *
 * @brief Pin mappings that are identical across all the boards for a given chip
 *
 * Copyright (C) Atmosic 2022
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup PINMAP_X2XX PINMAP_X2XX
 * @ingroup PINMUX_X2XX
 * @brief Chip specific pin definitions
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "pinmux_x2xx.h"
#ifdef PINMAP_X2XX_OVERLAY
#include STR(PINMAP_X2XX_OVERLAY)
#endif

/* GPIO to pin mapping common across the released boards */
#define PIN_GPIO_9 9
#define PIN_GPIO_10 10
#define PIN_GPIO_11 11
#define PIN_GPIO_13 13
#define PIN_GPIO_16 20
#define PIN_GPIO_18 22
#define PIN_GPIO_19 23
#define PIN_GPIO_20 24
#define PIN_GPIO_21 25
#define PIN_GPIO_26 30
#define PIN_GPIO_28 32
#define PIN_GPIO_29 33

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

/*
 * Pin to GPIO bit mapping commong across the released boards
 */
#define INVALID_GPIO 255
#define P9_GPIO 9
#define P10_GPIO 10
#define P11_GPIO 11
#define P13_GPIO 13
#define P14_GPIO INVALID_GPIO
#define P15_GPIO INVALID_GPIO
#define P16_GPIO INVALID_GPIO
#define P17_GPIO INVALID_GPIO
#define P20_GPIO 16
#define P22_GPIO 18
#define P23_GPIO 19
#define P24_GPIO 20
#define P25_GPIO 21
#define P30_GPIO 26
#define P32_GPIO 28
#define P33_GPIO 29

#define GPIO_VALID_PIN_MASK_COMMON \
    ((1UL << P9_GPIO) | (1UL << P10_GPIO) | (1UL << P11_GPIO) | \
    (1UL << P13_GPIO) | (1UL << P20_GPIO) | (1UL << P22_GPIO) | \
    (1UL << P23_GPIO) | (1UL << P24_GPIO) | (1UL << P25_GPIO) | \
    (1UL << P30_GPIO) | (1UL << P32_GPIO) | (1UL << P33_GPIO))

/*
 * Lookup GPIO bit from pin
 */
#define PIN2GPIO(pin) PIN_SIG(pin, GPIO)

/* Default UART1 TX PIN*/
#define PIN_UART1_TX_DEFAULT 33

/*
 * Supported KSM bit mapping for 5x5 package
 * Valid pin [P0, P1, P2], P9, P10, P11, P13, (P20, P22, P23, P24), P25, P30, P32
 */
#define SUPPORTED_KSM_5x5_COMMON_PINS ((1ULL << 9) | (1ULL << 10) | (1ULL << 11) | \
    (1ULL << 13) | (1ULL << 25) | (1ULL << 30) | (1ULL << 32))

#ifdef __cplusplus
}
#endif

/// @}
