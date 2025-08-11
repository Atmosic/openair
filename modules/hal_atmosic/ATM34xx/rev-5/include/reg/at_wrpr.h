/**
 ******************************************************************************
 *
 * @file at_wrpr.h
 *
 * @brief Peripheral module clock and reset control
 *
 * Copyright (C) Atmosic 2020-2025
 *
 ******************************************************************************
 */

#pragma once

#include "at_apb_wrpr_pins_regs_core_macro.h"
#include "at_apb_wrpr_short_regs_core_macro.h"

#define WRPR_CTRL__CLK_DISABLE	0x00000000U
#define WRPR_CTRL__CLK_ENABLE	0x00000001U
#define WRPR_CTRL__SRESET	0x00000002U
#define WRPR_CTRL__CLK_SEL	0x00000004U

#define PCLK_ALT_FREQ		16000000U

#define APB_MOD_SIZE		0x1000
#define APB0_NONSECURE_BASE	0x40140000
#define APB1_NONSECURE_BASE	0x40150000
#define APB2_NONSECURE_BASE	0x40160000
#define APB0_SECURE_BASE	0x50140000
#define APB1_SECURE_BASE	0x50150000
#define APB2_SECURE_BASE	0x50160000
#define APB0_NUM_MODULES	16
#define APB1_NUM_MODULES	15
#define APB2_NUM_MODULES	9

__STATIC_FORCEINLINE volatile uint32_t *
module_to_ctrl(volatile const void *addr)
{
    uintptr_t address = (uintptr_t)addr;

    if ((address >= APB0_NONSECURE_BASE) &&
	(address < APB0_NONSECURE_BASE + (APB_MOD_SIZE * APB0_NUM_MODULES))) {
	int i = (address - APB0_NONSECURE_BASE) / APB_MOD_SIZE;
	return ((&CMSDK_WRPR0_NONSECURE->APB0_CTRL) + i);
    }
    if ((address >= APB1_NONSECURE_BASE) &&
	(address < APB1_NONSECURE_BASE + (APB_MOD_SIZE * APB1_NUM_MODULES))) {
	int i = (address - APB1_NONSECURE_BASE) / APB_MOD_SIZE;
	return ((&CMSDK_WRPR1_NONSECURE->APB0_CTRL) + i);
    }
    if ((address >= APB2_NONSECURE_BASE) &&
	(address < APB2_NONSECURE_BASE + (APB_MOD_SIZE * APB2_NUM_MODULES))) {
	int i = (address - APB2_NONSECURE_BASE) / APB_MOD_SIZE;
	return ((&CMSDK_WRPR2_NONSECURE->APB0_CTRL) + i);
    }
    if ((address >= APB0_SECURE_BASE) &&
	(address < APB0_SECURE_BASE + (APB_MOD_SIZE * APB0_NUM_MODULES))) {
	int i = (address - APB0_SECURE_BASE) / APB_MOD_SIZE;
	return ((&CMSDK_WRPR0_SECURE->APB0_CTRL) + i);
    }
    if ((address >= APB1_SECURE_BASE) &&
	(address < APB1_SECURE_BASE + (APB_MOD_SIZE * APB1_NUM_MODULES))) {
	int i = (address - APB1_SECURE_BASE) / APB_MOD_SIZE;
	return ((&CMSDK_WRPR1_SECURE->APB0_CTRL) + i);
    }
    if ((address >= APB2_SECURE_BASE) &&
	(address < APB2_SECURE_BASE + (APB_MOD_SIZE * APB2_NUM_MODULES))) {
	int i = (address - APB2_SECURE_BASE) / APB_MOD_SIZE;
	return ((&CMSDK_WRPR2_SECURE->APB0_CTRL) + i);
    }
    return (NULL);
}

#define WRPR_CTRL_GET(__m) ({ \
    *module_to_ctrl(__m); \
})

#define WRPR_CTRL_SET(__m, __s) do { \
    *module_to_ctrl(__m) = (__s); \
} while (0)

#define WRPR_CTRL_GETSET(__m, __s) ({ \
    volatile uint32_t *_ctrl = module_to_ctrl(__m); \
    uint32_t _ret = *_ctrl; \
    *_ctrl = (__s); \
    _ret; \
})

/*
 * PUSH/POP macros mimic do/while syntax:
 *
 * WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
 *     ...;
 * } WRPR_CTRL_POP();
 */
#define WRPR_CTRL_PUSH(__m, __s) do { \
    volatile uint32_t *wrpr_ctrl_addr = module_to_ctrl(__m); \
    uint32_t wrpr_ctrl_save = *wrpr_ctrl_addr; \
    *wrpr_ctrl_addr = (__s); \
    do

#define WRPR_CTRL_POP() \
    while (0); \
    *wrpr_ctrl_addr = wrpr_ctrl_save; \
} while (0)

/*
 * Pin to selection register mapping
 */
#define PSEL_REG_P0	PSEL_A
#define PSEL_REG_P1	PSEL_A
#define PSEL_REG_P2	PSEL_A
#define PSEL_REG_P3	PSEL_A
#define PSEL_REG_P4	PSEL_B
#define PSEL_REG_P5	PSEL_B
#define PSEL_REG_P6	PSEL_B
#define PSEL_REG_P7	PSEL_B
#define PSEL_REG_P8	PSEL_C
#define PSEL_REG_P9	PSEL_C
#define PSEL_REG_P10	PSEL_C
#define PSEL_REG_P11	PSEL_C
#define PSEL_REG_P12	PSEL_D
#define PSEL_REG_P13	PSEL_D
#define PSEL_REG_P14	PSEL_D
#define PSEL_REG_P15	PSEL_D
#define PSEL_REG_P16	PSEL_E
#define PSEL_REG_P17	PSEL_E
#define PSEL_REG_P18	PSEL_E
#define PSEL_REG_P19	PSEL_E
#define PSEL_REG_P20	PSEL_F
#define PSEL_REG_P21	PSEL_F
#define PSEL_REG_P22	PSEL_F
#define PSEL_REG_P23	PSEL_F
#define PSEL_REG_P24	PSEL_G
#define PSEL_REG_P25	PSEL_G
#define PSEL_REG_P26	PSEL_G
#define PSEL_REG_P27	PSEL_G
#define PSEL_REG_P28	PSEL_H
#define PSEL_REG_P29	PSEL_H
#define PSEL_REG_P30	PSEL_H
#define PSEL_REG_P31	PSEL_H
#define PSEL_REG_P32	PSEL_J
#define PSEL_REG_P33	PSEL_J
#define PSEL_REG_P34	PSEL_J
#define PSEL_REG_P35	PSEL_J
#define PSEL_REG_P36	PSEL_K
#define PSEL_REG_P37	PSEL_K
#define PSEL_REG_P38	PSEL_K
#define PSEL_REG_P39	PSEL_K
#define PSEL_REG_P40	PSEL_L
#define PSEL_REG_P41	PSEL_L
#define PSEL_REG_P42	PSEL_L
#define PSEL_REG_P43	PSEL_L
#define PSEL_REG_P44	PSEL_M
#define PSEL_REG_P45	PSEL_M
#define PSEL_REG_P46	PSEL_M
#define PSEL_REG_P47	PSEL_M
#define PSEL_REG_P48	PSEL_N
#define PSEL_REG_P49	PSEL_N
#define PSEL_REG_P50	PSEL_N
#define PSEL_REG_P51	PSEL_N
#define PSEL_REG_P52	PSEL_O
#define PSEL_REG_P53	PSEL_O

#define PIN2REG(pin)	_PIN2REG(pin)
#define _PIN2REG(pin)	PSEL_REG_P ## pin

/*
 * Compute pin selection register core macro
 */
#define PIN_SEL(pin, sfx)	_PIN_SEL(PIN2REG(pin), pin, sfx)
#define _PIN_SEL(sel, pin, sfx)	__PIN_SEL(sel, pin, sfx)
#define __PIN_SEL(sel, pin, sfx) \
    WRPRPINS_ ## sel ## __P ## pin ## _SEL__ ## sfx

/*
 * Compute signal macro (see at_pinmux.h)
 */
#define PIN_SIG_PAR(pin, sig, par) ({ \
    STATIC_ASSERT((UINT64_C(1) << pin) & sig ## __MASK ## par, \
	"Pin does not support signal"); \
    PINMUX_ ## sig; \
})
#define PIN_SIG(pin, sig) PIN_SIG_PAR(pin, sig,)

/*
 * Assign signal to pin
 */
#define _PIN_SELECT(pin, sig, ...) PIN_SELECT_IMPL(pin, sig, ##__VA_ARGS__, 2, 1)
#define PIN_SELECT_IMPL(pin, sig, par, n, ...) PIN_SELECT_##n(pin, sig, par)
#define PIN_SELECT_1(pin, sig, par) \
    PIN_SEL(pin, MODIFY)(CMSDK_WRPR0_NONSECURE->PIN2REG(pin), PIN_SIG_PAR(pin, sig,))
#define PIN_SELECT_2(pin, sig, par) \
    PIN_SEL(pin, MODIFY)(CMSDK_WRPR0_NONSECURE->PIN2REG(pin), PIN_SIG_PAR(pin, sig, _ ## par))

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/devicetree.h>
#if DT_NODE_HAS_PROP(DT_PATH(zephyr_user), pin_arrangement)
#define PIN_SELECT(pin, sig) \
    _PIN_SELECT(pin, sig, DT_STRING_UPPER_TOKEN(DT_PATH(zephyr_user), pin_arrangement))
#else
#define PIN_SELECT(pin, sig) _PIN_SELECT(pin, sig)
#endif
#else // CONFIG_SOC_FAMILY_ATM
#ifdef CHIP_PAR
#define PIN_SELECT(pin, sig) _PIN_SELECT(pin, sig, CHIP_PAR)
#else
#define PIN_SELECT(pin, sig) _PIN_SELECT(pin, sig)
#endif // CHIP_PAR
#endif // CONFIG_SOC_FAMILY_ATM

/*
 * Set pin pullup
 */
#define PIN_PULLUP(pin) do { \
    STATIC_ASSERT((pin < 32) ? (WRPRPINS_PUPD_OVRD__WRITE & (1U << pin)) : \
	((pin < 54) ? (WRPRPINS_PUPD_OVRD2__WRITE & (1U << (pin % 32))) : 0), \
	"Pin does not support pull"); \
    uint32_t mask = (1U << (pin % 32)); \
    if (pin < 32) { \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD_VAL |= mask; \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD |= mask; \
    } else { \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD_VAL2 |= mask; \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD2 |= mask; \
    } \
} while(0)

/*
 * Set pin pulldown
 */
#define PIN_PULLDOWN(pin) do { \
    STATIC_ASSERT((pin < 32) ? (WRPRPINS_PUPD_OVRD__WRITE & (1U << pin)) : \
	((pin < 54) ? (WRPRPINS_PUPD_OVRD2__WRITE & (1U << (pin % 32))) : 0), \
	"Pin does not support pull"); \
    uint32_t mask = (1U << (pin % 32)); \
    if (pin < 32) { \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD_VAL &= ~mask; \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD |= mask; \
    } else { \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD_VAL2 &= ~mask; \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD2 |= mask; \
    } \
} while(0)

/*
 * Clear pin pull
 */
#define PIN_PULL_CLR(pin) do { \
    STATIC_ASSERT((pin < 32) ? (WRPRPINS_PUPD_OVRD__WRITE & (1U << pin)) : \
	((pin < 54) ? (WRPRPINS_PUPD_OVRD2__WRITE & (1U << (pin % 32))) : 0), \
	"Pin does not support pull"); \
    uint32_t mask = (1U << (pin % 32)); \
    if (pin < 32) { \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD &= ~mask; \
    } else { \
	CMSDK_WRPR0_NONSECURE->PUPD_OVRD2 &= ~mask; \
    } \
} while(0)

/*
 * Set pin drive strength
 */
#define PIN_PDSN_CFG(pin, val) do { \
    STATIC_ASSERT((pin < 16) ? (WRPRPINS_PDSN_A__WRITE & (3U << (2 * pin))) : \
	((pin < 32) ? (WRPRPINS_PDSN_B__WRITE & (3U << (2 * (pin % 16)))) : \
	((pin < 48) ? (WRPRPINS_PDSN_C__WRITE & (3U << (2 * (pin % 16)))) : \
	((pin < 54) ? (WRPRPINS_PDSN_D__WRITE & (3U << (2 * (pin % 16)))) : \
	0)), "Pin does not support drive strength"); \
    uint32_t mask = (3U << (2 * (pin % 16))); \
    if (pin < 16) { \
	CMSDK_WRPR0_NONSECURE->PDSN_A = \
	    (CMSDK_WRPR0_NONSECURE->PDSN_A & ~mask) | \
	    ((val << (2 * (pin % 16))) & mask); \
    } else if (pin < 32) { \
	CMSDK_WRPR0_NONSECURE->PDSN_B = \
	    (CMSDK_WRPR0_NONSECURE->PDSN_B & ~mask) | \
	    ((val << (2 * (pin % 16))) & mask); \
    } else if (pin < 48) { \
	CMSDK_WRPR0_NONSECURE->PDSN_C = \
	    (CMSDK_WRPR0_NONSECURE->PDSN_C & ~mask) | \
	    ((val << (2 * (pin % 16))) & mask); \
    } else { \
	CMSDK_WRPR0_NONSECURE->PDSN_D = \
	    (CMSDK_WRPR0_NONSECURE->PDSN_D & ~mask) | \
	    ((val << (2 * (pin % 16))) & mask); \
    } \
} while (0)

/*
 * Lookup GPIO bit from pin
 */
#define PIN2GPIO(pin) _PIN2GPIO(pin, GPIO)
#define _PIN2GPIO(pin, sig) P ## pin ## _ ## sig

/*
 * Module revision check
 */
#define REV_HASH_CHECK(__m, __n) do { \
    WRPR_CTRL_PUSH(__m, WRPR_CTRL__CLK_ENABLE) { \
	ASSERT_INFO((__m)->REV_HASH == __n ## _REV_HASH__RESET_VALUE, \
	    (__m)->REV_HASH, __n ## _REV_HASH__RESET_VALUE); \
    } WRPR_CTRL_POP(); \
} while (0)
