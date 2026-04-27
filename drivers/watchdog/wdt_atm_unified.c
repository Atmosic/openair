/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Atmosic Unified Watchdog Wrapper Driver
 *
 * This driver wraps the upstream ARM CMSDK APB watchdog driver and adds
 * Atmosic PMU watchdog management. It presents a single unified watchdog
 * interface while internally managing both hardware watchdogs.
 *
 * Architecture:
 * - ARM watchdog operations are delegated to upstream Zephyr driver
 * - PMU watchdog is managed directly for active state operation
 * - Both watchdogs are fed simultaneously in active state
 *
 * Active State Behavior:
 * - Both ARM and PMU watchdogs are configured with the same timeout
 * - PMU watchdog timeout = ARM timeout + 100ms offset
 * - Both watchdogs fed simultaneously via wdt_feed()
 * - PMU watchdog warning interrupt fires if ARM watchdog hardware fails
 * - User callback invoked before system reset
 */

#include <zephyr/device.h>
#include <zephyr/drivers/watchdog.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/irq.h>

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
#include "pmu.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "timer.h"
#include "spi.h"     /* For PMU_TOP_READ macro */
#include "pmu_spi.h" /* For PMU register addresses */

#define PSEQ_INTERNAL_DIRECT_INCLUDE_GUARD
#include "pseq.ih"
#endif // CONFIG_ATM_PMU_WDT_ENABLE

LOG_MODULE_REGISTER(wdt_atm_unified, CONFIG_ATM_WDT_UNIFIED_LOG_LEVEL);

#define DT_DRV_COMPAT atmosic_unified_watchdog

/* Driver instance data */
struct wdt_atm_unified_data {
	const struct device *arm_wdt; /* Reference to ARM watchdog device */
	bool enabled;                 /* Unified watchdog enabled state */

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	bool pmu_enabled;    /* PMU watchdog enabled state */
	uint32_t timeout_ms; /* Configured timeout in milliseconds */
	wdt_callback_t user_callback;
#endif
};

/* Driver configuration (from device tree) */
struct wdt_atm_unified_config {
	const struct device *arm_wdt; /* ARM watchdog device reference */
};

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
/**
 * @brief ARM watchdog callback wrapper - feeds PMU watchdog before reset
 *
 * This callback is invoked by the ARM watchdog interrupt handler before
 * the system resets. It ensures the PMU watchdog is fed so that only
 * the ARM watchdog triggers the reset, not both watchdogs simultaneously.
 *
 * @param arm_dev ARM watchdog device (not used)
 * @param channel_id Watchdog channel ID
 */
static void wdt_atm_arm_callback(const struct device *arm_dev, int channel_id)
{
	ARG_UNUSED(arm_dev);

	/* Get unified watchdog device from DT instance */
	const struct device *dev = DEVICE_DT_INST_GET(0);
	struct wdt_atm_unified_data *data = dev->data;

	LOG_INF("ARM wdog handler: %d", data->pmu_enabled);

	/* Feed/Disable PMU watchdog to prevent it from also triggering */
	if (data->pmu_enabled) {
		pmu_set_pmu_wdog_reset(false);
	}

	/* Call user's callback if registered */
	if (data->user_callback) {
		data->user_callback(dev, channel_id);
	}
}

static void wdt_atm_pmu_wdog_warn_enable_intr(void)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		uint32_t pmu_intr_expan = CMSDK_PSEQ->PMU_INTERRUPT_EXPAN;

		/* Clear any pending edge detections first */
		/* Note: There are no clear bits for PMU_INTERRUPT_EXPAN,
		 * so we just configure the detection mode */

		/* Enable rising edge detection for PMU watchdog warning
		 * Rising edge = PMU watchdog warning signal goes high */
		PSEQ_PMU_INTERRUPT_EXPAN__PMU_WDOG_WARN_RISING__SET(pmu_intr_expan);
		CMSDK_PSEQ->PMU_INTERRUPT_EXPAN = pmu_intr_expan;

		LOG_DBG("PMU watchdog warning interrupt enabled (rising edge)");
	}
	WRPR_CTRL_POP();
}

/**
 * @brief Clear PMU watchdog warning interrupt
 *
 * This clears the PMU watchdog warning interrupt by disabling the
 * interrupt source in PMU_INTERRUPT_EXPAN register.
 */
static void wdt_atm_pmu_wdog_warn_clear_intr(void)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		/* Use the dedicated clear bit for rising edge interrupt */
		CMSDK_PSEQ->PMU_INTERRUPT_EXPAN =
			PSEQ_PMU_INTERRUPT_EXPAN__CLEAR_RE_PMU_WDOG_WARN__MASK;
	}
	WRPR_CTRL_POP();
}

/**
 * @brief PMU watchdog warning interrupt handler
 *
 * Called by central PMU_Handler() in pmu.c when PMU watchdog warning fires.
 * The interrupt source is cleared in pmu_isr_source() before this is called.
 *
 * If PMU watchdog warning fired during active state, it indicates that the
 * ARM watchdog hardware failed to trigger. The handler feeds the PMU watchdog
 * and invokes the user-registered callback to allow the application to decide
 * what action to take (e.g., log information, perform recovery, or initiate a
 * system reset).
 */
void wdt_pmu_handler(void)
{
	LOG_INF("PMU watchdog warning fired!");

	/* Feed/reset PMU watchdog by reading the PMU_WDOG register */
	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
		(void)PMU_TOP_READ(PMU_WDOG_REG_ADDR);
	}
	WRPR_CTRL_POP();

	/* Call user's callback if registered */
	const struct device *unified_dev = DEVICE_DT_INST_GET(0);
	struct wdt_atm_unified_data *data = unified_dev->data;
	if (data->user_callback) {
		LOG_DBG("Calling user callback from PMU warning handler");
		data->user_callback(unified_dev, 0);
	} else {
		sys_reboot(SYS_REBOOT_COLD);
	}
}
#endif

/**
 * @brief Setup and enable the unified watchdog
 *
 * This function enables both ARM and PMU watchdogs. The ARM watchdog is
 * configured via the upstream driver, and the PMU watchdog is enabled
 * directly.
 *
 * @param dev Unified watchdog device
 * @param options Watchdog options (passed to ARM watchdog)
 * @return 0 on success, negative errno on failure
 */
static int wdt_atm_setup(const struct device *dev, uint8_t options)
{
	const struct wdt_atm_unified_config *config = dev->config;
	struct wdt_atm_unified_data *data = dev->data;

	if (data->enabled) {
		LOG_ERR("Watchdog already enabled");
		return -EBUSY;
	}

	/* Setup ARM watchdog via upstream driver */
	int ret = wdt_setup(config->arm_wdt, options);
	if (ret < 0) {
		LOG_ERR("ARM watchdog setup failed: %d", ret);
		return ret;
	}

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	/* Setup PMU watchdog for active state */
	if (data->timeout_ms > 0) {
		/* Configure PMU watchdog timeout duration */
		uint64_t cycles;
		WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
		{
#define PMU_WARNING_OFFSET_MS (CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC * 1000)
			/* Convert timeout from milliseconds to 32 KHz clock cycles */
			cycles = atm_ms_to_lpc(data->timeout_ms + PMU_WARNING_OFFSET_MS);
			pseq_core_config_soc_off(cycles);
		}
		WRPR_CTRL_POP();

		/* Enable PMU watchdog */
		pmu_set_pmu_wdog_reset(true);
		data->pmu_enabled = true;

		/* Enable PMU watchdog warning interrupt */
		wdt_atm_pmu_wdog_warn_enable_intr();

		LOG_DBG("PMU watchdog enabled with timeout %u ms (%llu cycles)",
			data->timeout_ms + PMU_WARNING_OFFSET_MS, cycles);
	}
#endif

	data->enabled = true;
	LOG_INF("Unified watchdog enabled (ARM: yes, PMU: %s)",
		IS_ENABLED(CONFIG_ATM_PMU_WDT_ENABLE) ? "yes" : "no");

	return 0;
}

/**
 * @brief Disable the unified watchdog
 *
 * This function disables both ARM and PMU watchdogs.
 *
 * @param dev Unified watchdog device
 * @return 0 on success, negative errno on failure
 */
static int wdt_atm_disable(const struct device *dev)
{
	const struct wdt_atm_unified_config *config = dev->config;
	struct wdt_atm_unified_data *data = dev->data;

	if (!data->enabled) {
		return -EFAULT;
	}

	/* Disable ARM watchdog */
	int ret = wdt_disable(config->arm_wdt);
	if (ret < 0) {
		LOG_ERR("ARM watchdog disable failed: %d", ret);
		return ret;
	}

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	/* Disable PMU watchdog */
	if (data->pmu_enabled) {
		/* Clear PMU watchdog warning interrupt source */
		wdt_atm_pmu_wdog_warn_clear_intr();

		/* Disable PMU watchdog */
		pmu_set_pmu_wdog_reset(false);
		data->pmu_enabled = false;
	}
#endif

	data->enabled = false;
	LOG_INF("Unified watchdog disabled");

	return 0;
}

/**
 * @brief Install timeout configuration
 *
 * This function installs the timeout configuration on the ARM watchdog
 * and stores the timeout value for PMU watchdog configuration.
 *
 * @param dev Unified watchdog device
 * @param cfg Timeout configuration
 * @return Channel ID on success, negative errno on failure
 */
static int wdt_atm_install_timeout(const struct device *dev, const struct wdt_timeout_cfg *cfg)
{
	const struct wdt_atm_unified_config *config = dev->config;
	int ret;

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	struct wdt_atm_unified_data *data = dev->data;
	/* Save user's callback */
	data->user_callback = cfg->callback;

	/* Create modified config with our callback wrapper */
	struct wdt_timeout_cfg arm_cfg = *cfg;
	arm_cfg.callback = wdt_atm_arm_callback;

	/* Install timeout on ARM watchdog with our callback */
	ret = wdt_install_timeout(config->arm_wdt, &arm_cfg);
#else
	/* Install timeout on ARM watchdog directly */
	ret = wdt_install_timeout(config->arm_wdt, cfg);
#endif

	if (ret < 0) {
		LOG_ERR("ARM watchdog install_timeout failed: %d", ret);
		return ret;
	}

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	/* Store timeout for PMU watchdog configuration */
	data->timeout_ms = cfg->window.max;
	LOG_DBG("Timeout configured: %u ms (channel %d, user_cb: %s)", data->timeout_ms, ret,
		cfg->callback ? "yes" : "no");
#endif

	return ret;
}

/**
 * @brief Feed the watchdog
 *
 * This function feeds both ARM and PMU watchdogs. The ARM watchdog is
 * fed via the upstream driver, and the PMU watchdog is fed directly
 * (unless suspended during power state transitions).
 *
 * @param dev Unified watchdog device
 * @param channel_id Channel ID (from install_timeout)
 * @return 0 on success, negative errno on failure
 */
static int wdt_atm_feed(const struct device *dev, int channel_id)
{
	struct wdt_atm_unified_data *data = dev->data;

	if (!data->enabled) {
		return -EAGAIN;
	}

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	/* Feed PMU watchdog first */
	if (data->pmu_enabled) {
		/* Feed/reset PMU watchdog by reading the PMU_WDOG register */
		WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
		{
			(void)PMU_TOP_READ(PMU_WDOG_REG_ADDR);
		}
		WRPR_CTRL_POP();
		LOG_DBG("PMU watchdog fed");
	}
#endif

	/* Feed ARM watchdog */
	const struct wdt_atm_unified_config *config = dev->config;
	int ret = wdt_feed(config->arm_wdt, channel_id);
	if (ret < 0) {
		LOG_ERR("ARM watchdog feed failed: %d", ret);
		return ret;
	}

	LOG_DBG("Unified watchdog fed");
	return 0;
}

/* Watchdog API structure */
static const struct wdt_driver_api wdt_atm_api = {
	.setup = wdt_atm_setup,
	.disable = wdt_atm_disable,
	.install_timeout = wdt_atm_install_timeout,
	.feed = wdt_atm_feed,
};

/**
 * @brief Initialize the unified watchdog wrapper
 *
 * This function initializes the wrapper driver and verifies that the
 * ARM watchdog device is ready.
 *
 * @param dev Unified watchdog device
 * @return 0 on success, negative errno on failure
 */
static int wdt_atm_init(const struct device *dev)
{
	const struct wdt_atm_unified_config *config = dev->config;
	struct wdt_atm_unified_data *data = dev->data;

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	/* Clear any pending PMU interrupts before enabling the IRQ
	 * This is critical after hibernation wakeup where the PMU watchdog warning
	 * interrupt may still be pending. If we enable the IRQ without clearing,
	 * the interrupt will fire immediately and continuously.
	 */
	wdt_atm_pmu_wdog_warn_clear_intr();
#endif

	if (!config->arm_wdt) {
		LOG_ERR("ARM watchdog device pointer is NULL");
		return -ENODEV;
	}

	/* Verify ARM watchdog device is ready */
	if (!device_is_ready(config->arm_wdt)) {
		LOG_ERR("ARM watchdog device %s not ready", config->arm_wdt->name);
		return -ENODEV;
	}

	/* Initialize state */
	data->arm_wdt = config->arm_wdt;
	data->enabled = false;

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
	data->pmu_enabled = false;
	data->timeout_ms = 0;
	data->user_callback = NULL;
#endif

	LOG_INF("Atmosic unified watchdog wrapper initialized (ARM WDT: %s)",
		config->arm_wdt->name);

	return 0;
}

/*
 * PRE_KERNEL_2 is required to clear pending PMU watchdog interrupts before global interrupts are
 * enabled, preventing infinite interrupt loops after hibernation wakeup. Priority 8 ensures
 * initialization after SPI/hw_cfg (for PMU register access) but before PMU driver operations.
 */
#define WDT_ATM_UNIFIED_INIT(inst)                                                                 \
	static struct wdt_atm_unified_data wdt_atm_data_##inst;                                    \
                                                                                                   \
	static const struct wdt_atm_unified_config wdt_atm_config_##inst = {                       \
		.arm_wdt = DEVICE_DT_GET(DT_INST_PHANDLE(inst, arm_watchdog)),                     \
	};                                                                                         \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(inst, wdt_atm_init, NULL, &wdt_atm_data_##inst,                      \
			      &wdt_atm_config_##inst, PRE_KERNEL_2,                                \
			      CONFIG_ATM_WDT_UNIFIED_INIT_PRIORITY, &wdt_atm_api);

DT_INST_FOREACH_STATUS_OKAY(WDT_ATM_UNIFIED_INIT)
