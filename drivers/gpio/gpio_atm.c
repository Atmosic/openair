/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Include the gpio_cmsdk_ahb.c implementation directly.
 * This allows us to access all static functions without code duplication.
 *
 * We temporarily change DT_DRV_COMPAT to prevent the original driver
 * from instantiating devices (DT_INST_FOREACH_STATUS_OKAY won't find any nodes).
 */
#include "../../zephyr/drivers/gpio/gpio_cmsdk_ahb.c"
#undef DT_DRV_COMPAT

/* Define DT_DRV_COMPAT for Atmosic GPIO driver */
#define DT_DRV_COMPAT atmosic_atm_gpio

#include <zephyr/logging/log.h>
#include "arch.h"
#include "at_pinmux.h"
#include "at_wrpr.h"
#ifdef GPIO_ATM_RESET_GPIOS_ON_WARM_RESET
#include "reset.h"
#endif

LOG_MODULE_REGISTER(gpio_atm, CONFIG_GPIO_LOG_LEVEL);

/* Get package-specific pin mask from devicetree pin-arrangement property. */
#define _GPIO_MASK_CONCAT(prefix, suffix) prefix##suffix
#define _GPIO_MASK_EXPAND(prefix, suffix) _GPIO_MASK_CONCAT(prefix, suffix)
#define GPIO_VALID_PIN_MASK _GPIO_MASK_EXPAND(GPIO__MASK_, _PIN_ARR)

/* Get number of pins from pinctrl node */
#define ATM_NUM_PINS DT_PROP(DT_NODELABEL(pinctrl), num_pins)

/* GPIO controller pin offsets - each controller manages 16 pins */
#define GPIO_PINS_PER_CONTROLLER 16
#define GPIO_CTLR_INVALID_OFFSET 0xFF

/*
 * Dynamically compute GPIO controller index by counting how many
 * GPIO controllers have a smaller register address than the target.
 */
#define GPIO_CTLR_COUNT_SMALLER(inst, target_addr) \
	((DT_INST_REG_ADDR(inst) < (target_addr)) ? 1 : 0) +

#define GPIO_CTLR_INDEX_FROM_ADDR(addr) \
	(DT_INST_FOREACH_STATUS_OKAY_VARGS(GPIO_CTLR_COUNT_SMALLER, addr) 0)

#define GPIO_CTLR_OFFSET_FROM_ADDR(addr) \
	(GPIO_CTLR_INDEX_FROM_ADDR(addr) * GPIO_PINS_PER_CONTROLLER)

static void atm_pin_select_gpio(gpio_pin_t absolute_pin)
{
#define PIN_CASE(pin) \
	case pin: \
		if (GPIO_VALID_PIN_MASK & (1ULL << (pin))) { \
			PIN_SEL(pin, MODIFY)(CMSDK_WRPR0_NONSECURE->PIN2REG(pin), PINMUX_GPIO); \
		} \
		break;
#define GET_NUMBER(n, _) n

	switch (absolute_pin) {
	FOR_EACH(PIN_CASE, (;), LISTIFY(ATM_NUM_PINS, GET_NUMBER, (,)))
	default:
		CODE_UNREACHABLE;
	}

#undef PIN_CASE
#undef GET_NUMBER
}

static int gpio_atm_config(const struct device *dev, gpio_pin_t pin, gpio_flags_t flags)
{
	const struct gpio_cmsdk_ahb_cfg *cfg = dev->config;
	gpio_pin_t offset = GPIO_CTLR_OFFSET_FROM_ADDR((uintptr_t)cfg->port);

	if (offset == GPIO_CTLR_INVALID_OFFSET) {
		LOG_ERR("Bad GPIO addr: %p", (void *)cfg->port);
		__ASSERT(false, "Bad GPIO addr: %p", (void *)cfg->port);
		return -EINVAL;
	}

	gpio_pin_t absolute_pin = pin + offset;

	/* Validate pin: bounds check and package-specific availability */
	if ((absolute_pin >= ATM_NUM_PINS) ||
	    !(GPIO_VALID_PIN_MASK & (1ULL << absolute_pin))) {
		LOG_ERR("P%d invalid", absolute_pin);
		__ASSERT(false, "P%d invalid", absolute_pin);
		return -EINVAL;
	}

	atm_pin_select_gpio(absolute_pin);
	return cmsdk_ahb_gpio_config(dev, BIT(pin), flags);
}

/* GPIO driver API - reuse most functions from gpio_cmsdk_ahb */
static DEVICE_API(gpio, gpio_atm_drv_api_funcs) = {
	.pin_configure = gpio_atm_config,
#ifdef CONFIG_GPIO_GET_CONFIG
	.pin_get_config = gpio_cmsdk_ahb_get_config,
#endif
	.port_get_raw = gpio_cmsdk_ahb_port_get_raw,
	.port_set_masked_raw = gpio_cmsdk_ahb_port_set_masked_raw,
	.port_set_bits_raw = gpio_cmsdk_ahb_port_set_bits_raw,
	.port_clear_bits_raw = gpio_cmsdk_ahb_port_clear_bits_raw,
	.port_toggle_bits = gpio_cmsdk_ahb_port_toggle_bits,
	.pin_interrupt_configure = gpio_cmsdk_ahb_pin_interrupt_configure,
	.manage_callback = gpio_cmsdk_ahb_manage_callback,
};

static int gpio_atm_cmsdk_ahb_init(const struct device *dev)
{
#ifdef GPIO_ATM_RESET_GPIOS_ON_WARM_RESET
	if (!(is_boot_type(TYPE_POWER_ON) || is_boot_type(TYPE_HIB))) {
		const struct gpio_cmsdk_ahb_cfg *cfg = dev->config;
		// Reset GPIO states
#define ALL_GPIO_MASK 0xFFFFUL
		cfg->port->pullup_enable_clr = ALL_GPIO_MASK;
		cfg->port->inenable_clr = ALL_GPIO_MASK;
		cfg->port->outenableclr = ALL_GPIO_MASK;
		cfg->port->altfuncclr = ALL_GPIO_MASK;
		cfg->port->intenclr = ALL_GPIO_MASK;
		cfg->port->inttypeclr = ALL_GPIO_MASK;
		cfg->port->intpolclr = ALL_GPIO_MASK;
		cfg->port->intclear = ALL_GPIO_MASK;
		cfg->port->pulldown_enable_clr = ALL_GPIO_MASK;
		cfg->port->dataout = ~ALL_GPIO_MASK;
	}
#endif
	return (gpio_cmsdk_ahb_init(dev));
}

/* Device instantiation macro - similar to CMSDK_AHB_GPIO_DEVICE */
#define ATM_GPIO_DEVICE(n)							\
	static void gpio_atm_port_##n##_config_func(const struct device *dev);	\
										\
	static const struct gpio_cmsdk_ahb_cfg gpio_atm_port_##n##_config = {	\
		.common = {							\
			.port_pin_mask = GPIO_PORT_PIN_MASK_FROM_DT_INST(n),	\
		},								\
		.port = ((volatile struct gpio_cmsdk_ahb *)DT_INST_REG_ADDR(n)),\
		.gpio_config_func = gpio_atm_port_##n##_config_func,		\
		.gpio_cc_as = {.bus = CMSDK_AHB, .state = SOC_ACTIVE,		\
			       .device = DT_INST_REG_ADDR(n),},			\
		.gpio_cc_ss = {.bus = CMSDK_AHB, .state = SOC_SLEEP,		\
			       .device = DT_INST_REG_ADDR(n),},			\
		.gpio_cc_dss = {.bus = CMSDK_AHB, .state = SOC_DEEPSLEEP,	\
				.device = DT_INST_REG_ADDR(n),},		\
	};									\
										\
	static struct gpio_cmsdk_ahb_dev_data gpio_atm_port_##n##_data;	\
										\
	DEVICE_DT_INST_DEFINE(n,						\
			    gpio_atm_cmsdk_ahb_init,				\
			    NULL,						\
			    &gpio_atm_port_##n##_data,				\
			    &gpio_atm_port_##n##_config,			\
			    PRE_KERNEL_2, CONFIG_GPIO_INIT_PRIORITY,		\
			    &gpio_atm_drv_api_funcs);				\
										\
	static void gpio_atm_port_##n##_config_func(const struct device *dev)	\
	{									\
		IRQ_CONNECT(DT_INST_IRQN(n),					\
			    DT_INST_IRQ(n, priority),				\
			    gpio_cmsdk_ahb_isr,					\
			    DEVICE_DT_INST_GET(n), 0);				\
										\
		irq_enable(DT_INST_IRQN(n));					\
	}

DT_INST_FOREACH_STATUS_OKAY(ATM_GPIO_DEVICE)

/* Compile-time validation of GPIO pins against package pin mask */
/* Use register address to compute controller offset dynamically */
#define GPIO_CTLR_OFFSET_BY_NODE(ctlr) \
	GPIO_CTLR_OFFSET_FROM_ADDR(DT_REG_ADDR(ctlr))

#define GPIO_ABS_PIN(node, prop, idx) \
	(GPIO_CTLR_OFFSET_BY_NODE(DT_GPIO_CTLR_BY_IDX(node, prop, idx)) + \
	 DT_GPIO_PIN_BY_IDX(node, prop, idx))

/* Check if a GPIO controller is an ATM GPIO (not an external expander) */
#define IS_ATM_GPIO_CTLR(ctlr) DT_NODE_HAS_COMPAT(ctlr, atmosic_atm_gpio)

/* Validate a single GPIO pin against package pin mask.
 * Only validate pins from ATM GPIO controllers (atmosic,atm-gpio),
 * skip external GPIO expanders (e.g., I2C GPIO expanders).
 */
#define VALIDATE_GPIO(node, prop, idx) \
	IF_ENABLED(IS_ATM_GPIO_CTLR(DT_GPIO_CTLR_BY_IDX(node, prop, idx)), \
		(BUILD_ASSERT( \
			(GPIO_VALID_PIN_MASK & (1ULL << GPIO_ABS_PIN(node, prop, idx))) != 0, \
			"Invalid GPIO pin in " DT_NODE_PATH(node) \
			" property '" #prop "' index " #idx \
			": pin not available on this package");))

/* Validate all GPIO pins in a node's 'gpios' property */
#define VALIDATE_GPIOS(node) \
	COND_CODE_1(DT_NODE_HAS_PROP(node, gpios), \
		(DT_FOREACH_PROP_ELEM(node, gpios, VALIDATE_GPIO)), ())

/* Validate all GPIO pins in all devicetree nodes */
DT_FOREACH_STATUS_OKAY_NODE(VALIDATE_GPIOS)
