/*
 * Copyright (c) 2024-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_SOC_ARM_ATMOSIC_ATM_PINCTRL_SOC_H
#define ZEPHYR_SOC_ARM_ATMOSIC_ATM_PINCTRL_SOC_H

#include <zephyr/devicetree.h>
#include <stdint.h>

#include <zephyr/dt-bindings/pinctrl/atmosic-pinctrl.h>

typedef struct pinctrl_soc_pin {
	uint8_t pin;
	uint8_t signal;
	uint8_t pupd;
} pinctrl_soc_pin_t;

#define Z_PINCTRL_ATM_PUPD_INIT(node_id)                                       \
	((ATM_NO_PULL * DT_PROP(node_id, bias_disable)) |                      \
	 (ATM_PULL_UP * DT_PROP(node_id, bias_pull_up)) |                      \
	 (ATM_PULL_DOWN * DT_PROP(node_id, bias_pull_down)))

#define ATM_DT_PIN(node_id)                                                    \
	{                                                                      \
		.pin = DT_PROP_BY_IDX(node_id, pinmux, 0),                     \
		.signal = DT_PROP_BY_IDX(node_id, pinmux, 1),                  \
		.pupd = Z_PINCTRL_ATM_PUPD_INIT(node_id),                      \
	},

#define Z_PINCTRL_STATE_PIN_INIT(node_id, prop, idx) \
	ATM_DT_PIN(DT_PROP_BY_IDX(node_id, prop, idx))

#define Z_PINCTRL_STATE_PINS_INIT(node_id, prop) \
	{ DT_FOREACH_PROP_ELEM(node_id, prop, Z_PINCTRL_STATE_PIN_INIT) }

#endif /* ZEPHYR_SOC_ARM_ATMOSIC_ATM_PINCTRL_SOC_H */
