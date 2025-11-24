/*
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/pm.h>

#include "arch.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "mdm_regs_core_macro.h"

#define DT_DRV_COMPAT atmosic_antenna

LOG_MODULE_REGISTER(atm_antenna, CONFIG_ATM_ANTENNA_SWITCH_LOG_LEVEL);

#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out0_pin)
#define ANT_OUT0_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out0_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out1_pin)
#define ANT_OUT1_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out1_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out2_pin)
#define ANT_OUT2_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out2_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out3_pin)
#define ANT_OUT3_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out3_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out4_pin)
#define ANT_OUT4_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out4_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out5_pin)
#define ANT_OUT5_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out5_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out6_pin)
#define ANT_OUT6_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out6_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), ant_out7_pin)
#define ANT_OUT7_PIN DT_PROP(DT_NODELABEL(atm_antenna), ant_out7_pin)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), power_source_gpios)
#define HAS_POWER_GPIO
static const struct gpio_dt_spec power_source_gpio =
	GPIO_DT_SPEC_GET(DT_NODELABEL(atm_antenna), power_source_gpios);
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), mdm_ant_rx_3to0)
#define MDM_ANTRX3TO0_TABLE DT_PROP(DT_NODELABEL(atm_antenna), mdm_ant_rx_3to0)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), mdm_ant_tx_3to0)
#define MDM_ANTTX3TO0_TABLE DT_PROP(DT_NODELABEL(atm_antenna), mdm_ant_tx_3to0)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), mdm_ant_rx_7to4)
#define MDM_ANTRX7TO4_TABLE DT_PROP(DT_NODELABEL(atm_antenna), mdm_ant_rx_7to4)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), mdm_ant_tx_7to4)
#define MDM_ANTTX7TO4_TABLE DT_PROP(DT_NODELABEL(atm_antenna), mdm_ant_tx_7to4)
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(atm_antenna), mdm_ant_idle)
#define MDM_ANTIDLE_TABLE DT_PROP(DT_NODELABEL(atm_antenna), mdm_ant_idle)
#endif

#if defined(HAS_POWER_GPIO) && defined(CONFIG_PM)
static void atm_antenna_pm_notify_entry(enum pm_state state)
{
	if (state >= PM_STATE_SUSPEND_TO_RAM) {
		gpio_pin_set_dt(&power_source_gpio, 0);
	}
}

static void atm_antenna_pm_notify_exit(enum pm_state state)
{
	if (state >= PM_STATE_SUSPEND_TO_RAM) {
		gpio_pin_set_dt(&power_source_gpio, 1);
	}
}

static struct pm_notifier atm_antenna_pm_notifier = {
	.state_entry = atm_antenna_pm_notify_entry,
	.state_exit = atm_antenna_pm_notify_exit,
};
#endif

static int atm_antenna_init(const struct device *dev)
{
	LOG_INF("Initializing ATM Antenna Driver");
#if defined(ANT_OUT0_PIN)
	PIN_SELECT(ANT_OUT0_PIN, ANT_OUT0);
#endif
#if defined(ANT_OUT1_PIN)
	PIN_SELECT(ANT_OUT1_PIN, ANT_OUT1);
#endif
#if defined(ANT_OUT2_PIN)
	PIN_SELECT(ANT_OUT2_PIN, ANT_OUT2);
#endif
#if defined(ANT_OUT3_PIN)
	PIN_SELECT(ANT_OUT3_PIN, ANT_OUT3);
#endif
#if defined(ANT_OUT4_PIN)
	PIN_SELECT(ANT_OUT4_PIN, ANT_OUT4);
#endif
#if defined(ANT_OUT5_PIN)
	PIN_SELECT(ANT_OUT5_PIN, ANT_OUT5);
#endif
#if defined(ANT_OUT6_PIN)
	PIN_SELECT(ANT_OUT6_PIN, ANT_OUT6);
#endif
#if defined(ANT_OUT7_PIN)
	PIN_SELECT(ANT_OUT7_PIN, ANT_OUT7);
#endif
#if defined(HAS_POWER_GPIO)
	if (!gpio_is_ready_dt(&power_source_gpio)) {
		LOG_ERR("Power source GPIO device not ready");
		return -ENODEV;
	}

	int ret = gpio_pin_configure_dt(&power_source_gpio,
					GPIO_OUTPUT | GPIO_OUTPUT_INIT_HIGH);
	if (ret < 0) {
		LOG_ERR("Failed to configure power source GPIO: %d", ret);
		return ret;
	}
#endif

	WRPR_CTRL_PUSH(CMSDK_MDM, WRPR_CTRL__CLK_ENABLE)
	{
#if defined(MDM_ANTRX3TO0_TABLE)
		MDM_ANTRX3TO0__TABLE__MODIFY(CMSDK_MDM_NONSECURE->ANTRX3TO0, MDM_ANTRX3TO0_TABLE);
#endif
#if defined(MDM_ANTTX3TO0_TABLE)
		MDM_ANTTX3TO0__TABLE__MODIFY(CMSDK_MDM_NONSECURE->ANTTX3TO0, MDM_ANTTX3TO0_TABLE);
#endif
#if defined(MDM_ANTRX7TO4_TABLE)
		MDM_ANTRX7TO4__TABLE__MODIFY(CMSDK_MDM_NONSECURE->ANTRX7TO4, MDM_ANTRX7TO4_TABLE);
#endif
#if defined(MDM_ANTTX7TO4_TABLE)
		MDM_ANTTX7TO4__TABLE__MODIFY(CMSDK_MDM_NONSECURE->ANTTX7TO4, MDM_ANTTX7TO4_TABLE);
#endif
#if defined(MDM_ANTIDLE_TABLE)
		MDM_ANTIDLE__TABLE__MODIFY(CMSDK_MDM_NONSECURE->ANTIDLE, MDM_ANTIDLE_TABLE);
#endif
	}
	WRPR_CTRL_POP();

#if defined(HAS_POWER_GPIO) && defined(CONFIG_PM)
	pm_notifier_register(&atm_antenna_pm_notifier);
#endif

	return 0;
}

DEVICE_DT_INST_DEFINE(0, atm_antenna_init, NULL, NULL, NULL, POST_KERNEL,
		      CONFIG_KERNEL_INIT_PRIORITY_DEVICE, NULL);
