/**
 *******************************************************************************
 *
 * @file pinmux_x3xx.h
 *
 * @brief Pinmux driver interface for x3xx silicon
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup PINMUX_X3XX PINMUX_X3XX
 * @ingroup PINMUX
 * @brief Pinmux driver interface for x3xx silicon
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_GET_BASE(inst) GPIO_##inst##_BASE

#define GPIO_BIT_POS_MSK(inst) (1 << (inst % 16))

#define GPIO_SET_HIGHZ(inst) do { \
    GPIO_GET_BASE(inst)->OUTENCLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INENCLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->PUENCLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->PDENCLR = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_INPUT_PULLUP(inst) do { \
    GPIO_GET_BASE(inst)->OUTENCLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INENSET = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->PUENSET = GPIO_BIT_POS_MSK(inst); \
} while (0)

#define GPIO_SET_INPUT_PULLDOWN(inst) do { \
    GPIO_GET_BASE(inst)->OUTENCLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->INENSET = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->PDENSET = GPIO_BIT_POS_MSK(inst); \
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
    GPIO_GET_BASE(inst)->INENCLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->OUTENSET = GPIO_BIT_POS_MSK(inst); \
    GPIO_SET_HIGH(inst); \
} while (0)

#define GPIO_SET_OUTPUT_LOW(inst) do { \
    GPIO_GET_BASE(inst)->INENCLR = GPIO_BIT_POS_MSK(inst); \
    GPIO_GET_BASE(inst)->OUTENSET = GPIO_BIT_POS_MSK(inst); \
    GPIO_SET_LOW(inst); \
} while (0)

#define PIN_SELECT_GPIO(pin) PIN_SELECT(pin, GPIO)

#define PIN_SELECT_HIGHZ(pin) do { \
    GPIO_SET_HIGHZ(PIN2GPIO(pin)); \
    PIN_SELECT(pin, GPIO); \
} while (0)

#define PIN_SELECT_GPIO_PULLUP(pin) do { \
    GPIO_SET_INPUT_PULLUP(PIN2GPIO(pin)); \
    PIN_SELECT(pin, GPIO); \
} while (0)

#define PIN_SELECT_GPIO_PULLDOWN(pin) do { \
    GPIO_SET_INPUT_PULLDOWN(PIN2GPIO(pin)); \
    PIN_SELECT(pin, GPIO); \
} while (0)

#define PIN_SELECT_GPIO_HIGH(pin) do { \
    GPIO_SET_OUTPUT_HIGH(PIN2GPIO(pin)); \
    PIN_SELECT(pin, GPIO); \
} while (0)

#define PIN_SELECT_GPIO_LOW(pin) do { \
    GPIO_SET_OUTPUT_LOW(PIN2GPIO(pin)); \
    PIN_SELECT(pin, GPIO); \
} while (0)

#define PINMUX_I2C_CLR(inst) do { \
    PIN_SELECT_GPIO_PULLUP(PIN_I2C##inst##_SCL); \
    PIN_SELECT_GPIO_PULLUP(PIN_I2C##inst##_SDA); \
} while (0)

#define PINMUX_I2C_SET(inst) do { \
    PIN_SELECT(PIN_I2C##inst##_SCL, I2C##inst##_SCL); \
    PIN_SELECT(PIN_I2C##inst##_SDA, I2C##inst##_SDA); \
} while (0)

#define PINMUX_I2S_CLR(dir) do { \
    PIN_SELECT_GPIO_PULLUP(PIN_I2S0_SCK_##dir); \
    PIN_SELECT_GPIO_PULLUP(PIN_I2S0_WS_##dir); \
    PIN_SELECT_GPIO_PULLUP(PIN_I2S0_SD_##dir); \
} while (0)

#define PINMUX_I2S_SET(dir) do { \
    PIN_SELECT(PIN_I2S0_SCK_##dir, I2S0_SCK_##dir); \
    PIN_SELECT(PIN_I2S0_WS_##dir, I2S0_WS_##dir); \
    PIN_SELECT(PIN_I2S0_SD_##dir, I2S0_SD_##dir); \
} while (0)

#define _PINMUX_PDM_CLR(inst) do { \
    PIN_SELECT_GPIO_LOW(PIN_PDM##inst##_CLK); \
    PIN_SELECT_GPIO_LOW(PIN_PDM##inst##_IN); \
} while (0)

#define PINMUX_PDM_CLR(inst) _PINMUX_PDM_CLR(inst)

#define _PINMUX_PDM_SET(inst) do { \
    PIN_SELECT(PIN_PDM##inst##_CLK, PDM##inst##_CLK); \
    PIN_SELECT(PIN_PDM##inst##_IN, PDM##inst##_IN); \
} while (0)

#define PINMUX_PDM_SET(inst) _PINMUX_PDM_SET(inst)

#define PINMUX_GPIO_SET(inst) do { \
    PIN_SELECT(PIN_GPIO_##inst, GPIO); \
} while (0)

#define SHUB_SIG(intf, inst, sig) SHUB_##intf##inst##_##sig
#define SHUB_PIN(intf, inst, sig) PIN_SHUB_##intf##inst##_##sig
#define PINMUX_SHUB_SET(intf, inst, sig) do { \
    PIN_SELECT(SHUB_PIN(intf, inst, sig), SHUB_SIG(intf, inst, sig)); \
} while(0)

#define PINMUX_SHUB_CLR(intf, inst, sig) do { \
    PIN_SELECT(PIN_SHUB_##intf##inst##_##sig, GPIO); \
} while(0)

#define KSI_(x) KSI##x
#define KSI(x) KSI_(x)
#define PINMUX_KSI_SET(inst) do { \
    PIN_SELECT(PIN_ROW##inst, KSI(ROW##inst##_KSI)); \
} while (0)

#define KSO_(x) KSO##x
#define KSO(x) KSO_(x)
#define PINMUX_KSO_SET(inst) do { \
    PIN_SELECT(PIN_COL##inst, KSO(COL##inst##_KSO)); \
} while (0)

#define PWM_MASK(inst) SIG_TO_PINS_MASK(PWM##inst)
#define PINMUX_PWM_SET(inst) do { \
    ASSERT_INFO(((1 << PIN_PWM_##inst) & PWM_MASK(inst)), inst, PIN_PWM_##inst); \
    PIN_SELECT(PIN_PWM_##inst, PWM##inst); \
} while (0)

#define PINMUX_SPI_IDLE(inst) do { \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_CLK); \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_CS); \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_MOSI); \
    PIN_SELECT_GPIO_PULLUP(PIN_SPI##inst##_MISO); \
} while (0)

#define PINMUX_SPI_SET(inst) do { \
    PIN_SELECT(PIN_SPI##inst##_CLK, SPI##inst##_SCLK); \
    PIN_SELECT(PIN_SPI##inst##_CS, SPI##inst##_CSN); \
    PIN_SELECT(PIN_SPI##inst##_MOSI, SPI##inst##_MOSI); \
    PIN_SELECT(PIN_SPI##inst##_MISO, SPI##inst##_MISO); \
} while (0)

#ifndef QSPI_SINGLE_MODE
#define PINMUX_QSPI_SET() do { \
    PIN_SELECT(PIN_QSPI_CLK, QSPI_CLK); \
    PIN_SELECT(PIN_QSPI_CSN, QSPI_CSN); \
    PIN_SELECT(PIN_QSPI_D0, QSPI_D0); \
    PIN_SELECT(PIN_QSPI_D1, QSPI_D1); \
    PIN_SELECT(PIN_QSPI_D2, QSPI_D2); \
    PIN_SELECT(PIN_QSPI_D3, QSPI_D3); \
    PIN_PULLUP(PIN_QSPI_D0); \
    PIN_PULLUP(PIN_QSPI_D1); \
    PIN_PULLUP(PIN_QSPI_D2); \
    PIN_PULLUP(PIN_QSPI_D3); \
} while (0)
#else
#define PINMUX_QSPI_SET() do { \
    PIN_SELECT(PIN_QSPI_CLK, QSPI_CLK); \
    PIN_SELECT(PIN_QSPI_CSN, QSPI_CSN); \
    PIN_SELECT(PIN_QSPI_D0, QSPI_D0); \
    PIN_SELECT(PIN_QSPI_D1, QSPI_D1); \
    PIN_PULLUP(PIN_QSPI_D0); \
    PIN_PULLUP(PIN_QSPI_D1); \
    PIN_PULLUP(PIN_QSPI_D2); \
    PIN_PULLUP(PIN_QSPI_D3); \
} while (0)
#endif

#define PINMUX_GET_GADC_CHANNEL(p) (p + 3)

#define _P(p) PWM_PIN##p##_CH
#define PINMUX_GET_PWM_CHANNEL(p) _P(p)

#define PINMUX_QDEC_SET(inst) do { \
    PIN_SELECT(PIN_QDEC##inst##_A, QDEC##inst##_A); \
    PIN_SELECT(PIN_QDEC##inst##_B, QDEC##inst##_B); \
} while (0)

#define _DBG_SHIFT_SIG(p, s) P##p##_DBG_SHIFT_##s
#define DBG_SHIFT_SIG(p, s) _DBG_SHIFT_SIG(p, s)
#define _DBG_GRP_SIG(p, s) P##p##_DBG_GRP_##s
#define DBG_GRP_SIG(p, s) _DBG_GRP_SIG(p, s)
#define PINMUX_CFG_DBG_SIG(p, s) do { \
    uint32_t ctl = CMSDK_WRPR0_NONSECURE->DBG_CTRL; \
    WRPRPINS_DBG_CTRL__DBG_SEL__MODIFY(ctl, DBG_GRP_SIG(p, s)); \
    WRPRPINS_DBG_CTRL__DBG_ENABLE__MODIFY(ctl, 1); \
    WRPRPINS_DBG_CTRL__DBG_SHFT__MODIFY(ctl, DBG_SHIFT_SIG(p, s)); \
    CMSDK_WRPR0_NONSECURE->DBG_CTRL = ctl; \
    PIN_SELECT(p, DBG); \
} while(0)

#ifdef __cplusplus
}
#endif

/// @}
