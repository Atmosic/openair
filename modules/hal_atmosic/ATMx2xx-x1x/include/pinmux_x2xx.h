/**
 *******************************************************************************
 *
 * @file pinmux_x2xx.h
 *
 * @brief Pinmux driver interface for x2xx silicon
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup PINMUX_X2XX PINMUX_X2XX
 * @ingroup PINMUX
 * @brief Pinmux driver interface for x2xx silicon
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_GET_BASE(inst) GPIO_##inst##_BASE

#define GPIO_BIT_POS_MSK(inst) (1 << (inst % 16))

#define GPIO_SET_HIGHZ(inst) do { \
    GPIO_GET_BASE(inst)->OUTENABLECLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INENABLE_SET = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->PULLUP_ENABLE_CLR = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_INPUT_PULLUP(inst) do { \
    GPIO_GET_BASE(inst)->OUTENABLECLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INENABLE_SET = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->PULLUP_ENABLE_SET = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_INPUT_FLOATING(inst) do { \
    GPIO_GET_BASE(inst)->OUTENABLECLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INENABLE_SET = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->PULLUP_ENABLE_CLR = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_LOW(inst) do { \
    if (GPIO_BIT_POS_MSK(inst) & 0xff) { \
	GPIO_GET_BASE(inst)->LB_MASKED[GPIO_BIT_POS_MSK(inst) & 0xff] = 0; \
    } else { \
	GPIO_GET_BASE(inst)->UB_MASKED[GPIO_BIT_POS_MSK(inst) >> 8] = 0; \
    } \
} while (0)

#define GPIO_SET_HIGH(inst) do { \
    if (GPIO_BIT_POS_MSK(inst) & 0xff) { \
	GPIO_GET_BASE(inst)->LB_MASKED[GPIO_BIT_POS_MSK(inst) & 0xff] = \
	    GPIO_BIT_POS_MSK(inst); \
    } else { \
	GPIO_GET_BASE(inst)->UB_MASKED[GPIO_BIT_POS_MSK(inst) >> 8] = \
	    GPIO_BIT_POS_MSK(inst); \
    } \
} while (0)

#define GPIO_SET_OUTPUT_HIGH(inst) do { \
    GPIO_GET_BASE(inst)->INENABLE_CLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->OUTENABLESET = GPIO_BIT_POS_MSK(inst); \
    GPIO_SET_HIGH(inst); \
} while (0)

#define GPIO_SET_OUTPUT_LOW(inst) do { \
    GPIO_GET_BASE(inst)->INENABLE_CLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->OUTENABLESET = GPIO_BIT_POS_MSK(inst); \
    GPIO_SET_LOW(inst); \
} while (0)

#define GPIO_SET_INT_HIGH(inst) do { \
    GPIO_GET_BASE(inst)->INTTYPECLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INTPOLSET = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_INT_RISING(inst) do { \
    GPIO_GET_BASE(inst)->INTTYPESET = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INTPOLSET = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_INT_LOW(inst) do { \
    GPIO_GET_BASE(inst)->INTTYPECLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INTPOLCLR = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_INT_FALLING(inst) do { \
    GPIO_GET_BASE(inst)->INTTYPESET = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INTPOLCLR = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define PIN_SELECT_GPIO(pin) PIN_SELECT(pin, SIG_GPIO(PIN2GPIO(pin)))

#define PIN_SELECT_HIGHZ(pin) do { \
    GPIO_SET_HIGHZ(PIN2GPIO(pin)); \
    PIN_SELECT(pin, SIG_GPIO(PIN2GPIO(pin))); \
} while (0)

#define PIN_SELECT_GPIO_PULLUP(pin) do { \
    GPIO_SET_INPUT_PULLUP(PIN2GPIO(pin)); \
    PIN_SELECT(pin, SIG_GPIO(PIN2GPIO(pin))); \
} while (0)

#define PIN_SELECT_GPIO_FLOATING(pin) do { \
    GPIO_SET_INPUT_FLOATING(PIN2GPIO(pin)); \
    PIN_SELECT(pin, SIG_GPIO(PIN2GPIO(pin))); \
} while (0)

#define PIN_SELECT_GPIO_HIGH(pin) do { \
    GPIO_SET_OUTPUT_HIGH(PIN2GPIO(pin)); \
    PIN_SELECT(pin, SIG_GPIO(PIN2GPIO(pin))); \
} while (0)

#define PIN_SELECT_GPIO_LOW(pin) do { \
    GPIO_SET_OUTPUT_LOW(PIN2GPIO(pin)); \
    PIN_SELECT(pin, SIG_GPIO(PIN2GPIO(pin))); \
} while (0)

#define PINMUX_I2C_CLR(inst) do { \
    PIN_SELECT_GPIO_PULLUP(PIN_I2C##inst##_SCL); \
    PIN_SELECT_GPIO_PULLUP(PIN_I2C##inst##_SDA); \
} while (0)

#define PINMUX_I2C_SET(inst) do { \
    PIN_SELECT(PIN_I2C##inst##_SCL, I2C##inst##_SCL); \
    PIN_SELECT(PIN_I2C##inst##_SDA, I2C##inst##_SDA); \
} while(0)

#define SHUB_SIG(intf, inst, sig) SHUB##inst##_##sig
#define SHUB_PIN(intf, inst, sig) PIN_SHUB_##intf##inst##_##sig
#define PINMUX_SHUB_SET(intf, inst, sig) do { \
    PIN_SELECT(SHUB_PIN(intf, inst, sig), SHUB_SIG(intf, inst, sig)); \
} while (0)

#define PINMUX_SHUB_CLR(intf, inst, sig) do { \
    PIN_SELECT(PIN_SHUB_##intf##inst, GPIO); \
} while (0)

#define PINMUX_PDM_CLR(inst) do { \
    STATIC_ASSERT(inst == 0, "invalid PDM instance"); \
    PIN_SELECT_GPIO_LOW(PIN_PDM_CLK); \
    PIN_SELECT_GPIO_LOW(PIN_PDM_IN); \
} while(0)

#define PINMUX_PDM_SET(inst) do { \
    STATIC_ASSERT(inst == 0, "invalid PDM instance"); \
    PIN_SELECT(PIN_PDM_CLK, PDM_CLK); \
    PIN_SELECT(PIN_PDM_IN, PDM_IN); \
} while(0)

#define PINMUX_GPIO_SET(inst) do { \
    PIN_SELECT(PIN_GPIO_##inst, GPIO_##inst##_); \
} while(0)

#define KSI_(x) KSI_##x##_
#define KSI(x) KSI_(x)
#define PINMUX_KSI_SET(inst) do { \
    PIN_SELECT(PIN_ROW##inst, KSI(ROW##inst##_KSI)); \
} while(0)

#define KSO_(x) KSO_##x##_
#define KSO(x) KSO_(x)
#define PINMUX_KSO_SET(inst) do { \
    PIN_SELECT(PIN_COL##inst, KSO(COL##inst##_KSO)); \
} while(0)

#define PINMUX_PWM_SET(inst) do { \
    PIN_SELECT(PIN_PWM_##inst, PWM_##inst##_); \
} while(0)

#define SIG_GPIO(x) _SIG_GPIO(GPIO_,x,_)
#define _SIG_GPIO(x,y,z) x ## y ## z

#define PINMUX_SPI_IDLE_PULLUP(inst) do { \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_CLK); \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_CS); \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_MOSI); \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_MISO); \
} while(0)

#define PINMUX_SPI_IDLE_FLOATING(inst) do { \
    PIN_SELECT_GPIO_FLOATING(PIN_SPI##inst##_CLK); \
    PIN_SELECT_GPIO_FLOATING(PIN_SPI##inst##_CS); \
    PIN_SELECT_GPIO_FLOATING(PIN_SPI##inst##_MOSI); \
    PIN_SELECT_GPIO_FLOATING(PIN_SPI##inst##_MISO); \
} while(0)

#define PINMUX_SPI_SET(inst) do { \
    PIN_SELECT(PIN_SPI##inst##_CLK, SPI##inst##_CLK); \
    PIN_SELECT(PIN_SPI##inst##_CS, SPI##inst##_CS); \
    PIN_SELECT(PIN_SPI##inst##_MOSI, SPI##inst##_MOSI); \
    PIN_SELECT(PIN_SPI##inst##_MISO, SPI##inst##_MISO); \
} while(0)

#define PINMUX_GET_GADC_CHANNEL(p) \
    ((((p) == 10) || ((p) == 11)) ? (p - 4) : PORT1_SINGLE_ENDED_1)

#define QDEC0_A QDX_0_
#define QDEC0_B QDX_1_
#define QDEC1_A QDY_0_
#define QDEC1_B QDY_1_
#define QDEC2_A QDZ_0_
#define QDEC2_B QDZ_1_

#define PINMUX_QDEC_IDLE(inst) _PINMUX_QDEC_IDLE(inst)
#define _PINMUX_QDEC_IDLE(inst) do { \
    PIN_SELECT_GPIO_FLOATING(PIN_QDEC##inst##_A); \
    PIN_SELECT_GPIO_FLOATING(PIN_QDEC##inst##_B); \
} while(0)

#define PINMUX_QDEC_SET(inst) _PINMUX_QDEC_SET(inst)
#define _PINMUX_QDEC_SET(inst) do { \
    PIN_SELECT(PIN_QDEC##inst##_A, QDEC##inst##_A); \
    PIN_SELECT(PIN_QDEC##inst##_B, QDEC##inst##_B); \
} while(0)

#define PINMUX_XPAON_SET() do { \
    PIN_SELECT(PIN_XPAON, XPAON); \
} while(0)

#define PINMUX_XPARX_SET(B, G) do { \
    PIN_SELECT(PIN_XPARX, B##_##G##_); \
} while(0)

#ifdef __cplusplus
}
#endif

/// @}
