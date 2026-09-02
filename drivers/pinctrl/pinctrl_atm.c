/**
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/drivers/pinctrl.h>
#include <zephyr/sys/util_macro.h>
#include <zephyr/dt-bindings/pinctrl/atmosic-pinctrl.h>

#define PINMUX_ASSERT(expr, _) ASSERT_ERR(expr)

#include "arch.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "pinmux.h"

/*
 * PIN_LATCH_OPEN / PIN_LATCH_CLOSE are defined in at_wrpr.h for chips that
 * replace the glitchless mux with software-controlled per-GPIO latches
 */
#ifndef PIN_LATCH_OPEN
#define PIN_LATCH_OPEN(pin)  ((void)(pin))
#define PIN_LATCH_CLOSE(pin) ((void)(pin))
#endif

static int pinctrl_configure_pin(uint8_t pin, uint8_t signal, uint8_t pupd, uint8_t pdsn)
{
	// TODO: check if pin is valid for signal (at_pinmux.h, __MASK macros?)

	// Ensure only 1 Pull option is set
	bool pull_clear = pupd & ATM_NO_PULL;
	bool pull_up = pupd & ATM_PULL_UP;
	bool pull_down = pupd & ATM_PULL_DOWN;
	if ((int)pull_clear + (int)pull_up + (int)pull_down > 1) {
		return -EINVAL;
	}

#define WRPR_REG CMSDK_WRPR0_NONSECURE

	/* Drive Strength */
	PIN_PDSN_CFG(pin, pdsn);

	/* Pinmux Assingment */
#ifdef CONFIG_ATM_PINCTRL_CLEAR_PUPD_OVRD_ON_GPIO
#define PIN_PUPD_OVRD_CLR(pin)                                                                     \
	if ((WRPRPINS_PUPD_OVRD__WRITE & (1ULL << (pin))) != 0) {                                  \
		PIN_PULL_CLR(pin);                                                                 \
	}
#else
#define PIN_PUPD_OVRD_CLR(pin)
#endif

#define PIN_CASE(pin)                                                                              \
	case pin: {                                                                                \
		if (signal == PINMUX_GPIO) {                                                       \
			/* Clear any WRPR PUPD_OVRD override before applying GPIO                  \
			 * controller pull settings; WRPR overrides take priority over             \
			 * the GPIO controller pull registers, so the GPIO-level                   \
			 * bias-pull-up/down would be ineffective without clearing it first.       \
			 * Guard with the write mask so PIN_PULL_CLR is only called on             \
			 * pins that actually support the PUPD_OVRD register bit.                  \
			 */                                                                        \
			PIN_PUPD_OVRD_CLR(pin)                                                     \
			if (pull_clear) {                                                          \
				GPIO_SET_HIGHZ(PIN2GPIO(pin));                                     \
			} else if (pull_up) {                                                      \
				GPIO_SET_INPUT_PULLUP(PIN2GPIO(pin));                              \
			} else if (pull_down) {                                                    \
				GPIO_SET_INPUT_PULLDOWN(PIN2GPIO(pin));                            \
			}                                                                          \
		} else {                                                                           \
			if (pull_clear) {                                                          \
				PIN_PULL_CLR(pin);                                                 \
			} else if (pull_up) {                                                      \
				PIN_PULLUP(pin);                                                   \
			} else if (pull_down) {                                                    \
				PIN_PULLDOWN(pin);                                                 \
			}                                                                          \
		}                                                                                  \
		PIN_LATCH_OPEN(pin);                                                               \
		PIN_SEL(pin, MODIFY)(WRPR_REG->PIN2REG(pin), signal);                              \
		PIN_LATCH_CLOSE(pin);                                                              \
	} break;

#define GET_NUMBER(n, _) n
	switch (pin) {
	FOR_EACH(PIN_CASE, (;), LISTIFY(DT_PROP(DT_NODELABEL(pinctrl), num_pins), GET_NUMBER, (,)));
	default:
		return -EINVAL;
	}

	return 0;
}

int pinctrl_configure_pins(const pinctrl_soc_pin_t *pins, uint8_t pin_cnt, uintptr_t reg)
{
	ARG_UNUSED(reg);

	int err;
	for (int i = 0; i < pin_cnt; i++) {
		err = pinctrl_configure_pin(pins[i].pin, pins[i].signal, pins[i].pupd,
					    pins[i].pdsn);
		if (err) {
			return err;
		}
	}

	return 0;
}
