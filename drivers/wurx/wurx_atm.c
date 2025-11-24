/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Atmosic WuRx (Wake upon receive) driver implementation
 */

#define DT_DRV_COMPAT atmosic_wurx

#include "wurx.h"
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/pm/device.h>
#include <zephyr/pm/pm.h>
#include <zephyr/irq.h>
#include <soc.h>
#include <errno.h>
#include <inttypes.h>

#include "arch.h"
#include "spi.h"
#include "power.h"
#include "reset.h"
#include "timer.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "pmu_spi.h"
#include "pmu_top_regs_core_macro.h"

LOG_MODULE_REGISTER(wurx_atm, CONFIG_WURX_LOG_LEVEL);

/**
 * @brief PMU WURX register structure
 */
struct pmu_wurx_regs {
	uint32_t wurx_general;
	uint32_t wurx_general2;
	uint32_t wurx0_0;
	uint32_t wurx0_1;
	uint32_t wurx0_2;
	uint32_t wurx0_3;
	uint32_t wurx0_4;
	uint32_t wurx1_0;
	uint32_t wurx1_1;
	uint32_t wurx1_2;
	uint32_t wurx1_3;
	uint32_t wurx1_4;
};

/**
 * @brief WuRx timing configuration
 */
struct wurx_timing_config {
	uint32_t wake_timeout_ms;
	uint32_t consecutive_signals;
	uint32_t signal_spacing_ms;
};

/**
 * @brief WuRx device configuration (from device tree)
 */
struct wurx_atmosic_config {
	bool wurx0_enabled_default;
	bool wurx1_enabled_default;
	struct pmu_wurx_regs default_regs;
	struct wurx_timing_config defaults;
};

/**
 * @brief WuRx device runtime data
 */
struct wurx_atmosic_data {
	struct pmu_wurx_regs current_regs;
	struct k_mutex lock;
};

/**
 * @brief Configure PMU WuRx registers and timing parameters
 */
static int wurx_configure_hw(const struct device *dev)
{
	const struct wurx_atmosic_config *config = dev->config;
	struct wurx_atmosic_data *data = dev->data;

	LOG_DBG("Configuring PMU WuRx registers");
	struct pmu_wurx_regs wurx_regs = data->current_regs;
	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
		uint32_t pmu11 = PMU_TOP_READ(PMU11_REG_ADDR);
		PMU_PMU11__WURX_CLK_EN__SET(pmu11);
		PMU_TOP_WRITE(PMU11_REG_ADDR, pmu11);
	}
	WRPR_CTRL_POP();
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		CMSDK_PSEQ->WURX_CONFIG = PSEQ_WURX_CONFIG__WURX_CUTVDD_B__MASK;
		CMSDK_PSEQ->WURX_CONFIG =
			PSEQ_WURX_CONFIG__WURX_CUTVDD_B__MASK | PSEQ_WURX_CONFIG__WURX_RSTB__MASK;
		CMSDK_PSEQ->WURX_CONFIG = PSEQ_WURX_CONFIG__WURX_CUTVDD_B__MASK |
					  PSEQ_WURX_CONFIG__WURX_RSTB__MASK |
					  PSEQ_WURX_CONFIG__WURX_EN__MASK;
	}
	WRPR_CTRL_POP();
	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
		PMU_WURX_WRITE(WURX_GENERAL_REG_ADDR, wurx_regs.wurx_general);
		PMU_WURX_WRITE(WURX_GENERAL2_REG_ADDR, wurx_regs.wurx_general2);
		PMU_WURX_WRITE(WURX0_0_REG_ADDR, wurx_regs.wurx0_0);
		PMU_WURX_WRITE(WURX0_1_REG_ADDR, wurx_regs.wurx0_1);
		PMU_WURX_WRITE(WURX0_2_REG_ADDR, wurx_regs.wurx0_2);
		PMU_WURX_WRITE(WURX0_3_REG_ADDR, wurx_regs.wurx0_3);
		PMU_WURX_WRITE(WURX0_4_REG_ADDR, wurx_regs.wurx0_4);
		PMU_WURX_WRITE(WURX1_0_REG_ADDR, wurx_regs.wurx1_0);
		PMU_WURX_WRITE(WURX1_1_REG_ADDR, wurx_regs.wurx1_1);
		PMU_WURX_WRITE(WURX1_2_REG_ADDR, wurx_regs.wurx1_2);
		PMU_WURX_WRITE(WURX1_3_REG_ADDR, wurx_regs.wurx1_3);
		PMU_WURX_WRITE(WURX1_4_REG_ADDR, wurx_regs.wurx1_4);
	}
	WRPR_CTRL_POP();
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		/* Determine wurx_src_sel based on which algorithms are enabled:
		 * 0 = wurx0 only, 1 = wurx1 only, 2 = wurx0 OR wurx1
		 */
		uint32_t wurx_src_sel;
		if (wurx0_enabled && wurx1_enabled) {
			wurx_src_sel = 2; /* Both algorithms */
		} else if (wurx1_enabled) {
			wurx_src_sel = 1; /* wurx1 only */
		} else {
			wurx_src_sel = 0; /* wurx0 only (or neither) */
		}

		CMSDK_PSEQ->WURX_CONFIG1 = PSEQ_WURX_CONFIG1__WURX_SRC_SEL__WRITE(wurx_src_sel) |
					   PSEQ_WURX_CONFIG1__NUM_WURX_EVENT__WRITE(
						   config->defaults.consecutive_signals);

		/* Convert milliseconds to LPC cycles */
		uint32_t signal_spacing_lpc = atm_ms_to_lpc(config->defaults.signal_spacing_ms);
		uint32_t wake_timeout_lpc = atm_ms_to_lpc(config->defaults.wake_timeout_ms);

		CMSDK_PSEQ->WURX_CONFIG2 =
			PSEQ_WURX_CONFIG2__NUM_WURX_TIME1_CYC__WRITE(signal_spacing_lpc) |
			PSEQ_WURX_CONFIG2__NUM_WURX_TIME0_CYC__WRITE(wake_timeout_lpc);

		LOG_DBG("WuRx_CONFIG1=0x%08" PRIx32 " (wurx_src_sel=%" PRIu32 ", "
			"consecutive_signals=%" PRIu32 ")",
			CMSDK_PSEQ->WURX_CONFIG1, wurx_src_sel,
			config->defaults.consecutive_signals);
		LOG_DBG("WuRx_CONFIG2=0x%08" PRIx32 " (signal_spacing=%" PRIu32 " LPC, "
			"wake_timeout=%" PRIu32 " LPC)",
			CMSDK_PSEQ->WURX_CONFIG2, signal_spacing_lpc, wake_timeout_lpc);
	}
	WRPR_CTRL_POP();

	return 0;
}

/**
 * @brief Set WuRx algorithm enable state
 */
static int wurx_atmosic_set_algorithm(const struct device *dev, enum wurx_algorithm algorithm,
				      bool enabled)
{
	struct wurx_atmosic_data *data = dev->data;

	if (algorithm != WURX_ALGORITHM_0 && algorithm != WURX_ALGORITHM_1) {
		return -EINVAL;
	}

	k_mutex_lock(&data->lock, K_FOREVER);

	LOG_DBG("Setting WuRx algorithm %d: %s", algorithm, enabled ? "enabled" : "disabled");

	/* Use global variables directly from power.c */
	if (algorithm == WURX_ALGORITHM_0) {
		wurx0_enabled = enabled;
	} else {
		wurx1_enabled = enabled;
	}

	/* Update wurx_src_sel based on which algorithms are now enabled */
	uint32_t wurx_src_sel;
	if (wurx0_enabled && wurx1_enabled) {
		wurx_src_sel = 2; /* Both algorithms */
	} else if (wurx1_enabled) {
		wurx_src_sel = 1; /* wurx1 only */
	} else {
		wurx_src_sel = 0; /* wurx0 only (or neither) */
	}

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		PSEQ_WURX_CONFIG1__WURX_SRC_SEL__MODIFY(CMSDK_PSEQ->WURX_CONFIG1, wurx_src_sel);
		LOG_DBG("Updated WURX_CONFIG1 wurx_src_sel to %" PRIu32, wurx_src_sel);
	}
	WRPR_CTRL_POP();

	k_mutex_unlock(&data->lock);

	LOG_INF("WuRx algorithm %d %s", algorithm, enabled ? "enabled" : "disabled");
	return 0;
}

/**
 * @brief WuRx driver API structure
 */
static const struct wurx_driver_api wurx_atmosic_api = {
	.set_algorithm = wurx_atmosic_set_algorithm,
};

/**
 * @brief Initialize WuRx device
 */
static int wurx_atmosic_init(const struct device *dev)
{
	const struct wurx_atmosic_config *config = dev->config;
	struct wurx_atmosic_data *data = dev->data;

	LOG_INF("Initializing WuRx driver");

	int ret = k_mutex_init(&data->lock);
	if (ret < 0) {
		LOG_ERR("Failed to initialize mutex: %d", ret);
		return ret;
	}

	data->current_regs = config->default_regs;

	/* Initialize global variables directly from device tree configuration */
	wurx0_enabled = config->wurx0_enabled_default;
	wurx1_enabled = config->wurx1_enabled_default;

	/* Log all PMU WURX register values being configured */
	LOG_DBG("WuRx PMU register configuration:");
	LOG_DBG("  wurx_general:  0x%08" PRIx32, data->current_regs.wurx_general);
	LOG_DBG("  wurx_general2: 0x%08" PRIx32, data->current_regs.wurx_general2);
	LOG_DBG("WuRx0 algorithm registers:");
	LOG_DBG("  wurx0_0: 0x%08" PRIx32 " (UID pattern)", data->current_regs.wurx0_0);
	LOG_DBG("  wurx0_1: 0x%08" PRIx32 " (GID pattern)", data->current_regs.wurx0_1);
	LOG_DBG("  wurx0_2: 0x%08" PRIx32 " (correlation/threshold config)",
		data->current_regs.wurx0_2);
	LOG_DBG("  wurx0_3: 0x%08" PRIx32 " (energy thresholds/clock freq)",
		data->current_regs.wurx0_3);
	LOG_DBG("  wurx0_4: 0x%08" PRIx32 " (timer/algorithm control)", data->current_regs.wurx0_4);
	LOG_DBG("WuRx1 algorithm registers:");
	LOG_DBG("  wurx1_0: 0x%08" PRIx32 " (UID pattern)", data->current_regs.wurx1_0);
	LOG_DBG("  wurx1_1: 0x%08" PRIx32 " (GID pattern)", data->current_regs.wurx1_1);
	LOG_DBG("  wurx1_2: 0x%08" PRIx32 " (correlation/threshold config)",
		data->current_regs.wurx1_2);
	LOG_DBG("  wurx1_3: 0x%08" PRIx32 " (energy thresholds/clock freq)",
		data->current_regs.wurx1_3);
	LOG_DBG("  wurx1_4: 0x%08" PRIx32 " (timer/algorithm control)", data->current_regs.wurx1_4);
	LOG_DBG("Algorithm enable status: WuRx0=%s, WuRx1=%s",
		wurx0_enabled ? "enabled" : "disabled", wurx1_enabled ? "enabled" : "disabled");
	LOG_DBG("Timing configuration:");
	LOG_DBG("  wake_timeout_ms:     %" PRIu32 " ms", config->defaults.wake_timeout_ms);
	LOG_DBG("  consecutive_signals: %" PRIu32, config->defaults.consecutive_signals);
	LOG_DBG("  signal_spacing_ms:   %" PRIu32 " ms", config->defaults.signal_spacing_ms);

	ret = wurx_configure_hw(dev);
	if (ret < 0) {
		LOG_ERR("Failed to configure WuRx hardware: %d", ret);
		return ret;
	}

	LOG_INF("WuRx driver initialized successfully");

	return 0;
}

/**
 * @brief Device tree configuration extraction macros
 */
#define WURX_ATMOSIC_CONFIG()                                                                      \
	{                                                                                          \
		.wurx0_enabled_default = DT_PROP_OR(DT_NODELABEL(wurx), wurx0_enabled, false),     \
		.wurx1_enabled_default = DT_PROP_OR(DT_NODELABEL(wurx), wurx1_enabled, false),     \
		.default_regs =                                                                    \
			{                                                                          \
				.wurx_general = DT_PROP(DT_NODELABEL(wurx), wurx_general_default), \
				.wurx_general2 =                                                   \
					DT_PROP(DT_NODELABEL(wurx), wurx_general2_default),        \
				.wurx0_0 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx0_regs_default, 0), \
				.wurx0_1 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx0_regs_default, 1), \
				.wurx0_2 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx0_regs_default, 2), \
				.wurx0_3 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx0_regs_default, 3), \
				.wurx0_4 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx0_regs_default, 4), \
				.wurx1_0 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx1_regs_default, 0), \
				.wurx1_1 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx1_regs_default, 1), \
				.wurx1_2 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx1_regs_default, 2), \
				.wurx1_3 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx1_regs_default, 3), \
				.wurx1_4 =                                                         \
					DT_PROP_BY_IDX(DT_NODELABEL(wurx), wurx1_regs_default, 4), \
			},                                                                         \
		.defaults = {                                                                      \
			.wake_timeout_ms = DT_PROP(DT_NODELABEL(wurx), wake_timeout_ms),           \
			.consecutive_signals = DT_PROP(DT_NODELABEL(wurx), consecutive_signals),   \
			.signal_spacing_ms = DT_PROP(DT_NODELABEL(wurx), signal_spacing_ms),       \
		},                                                                                 \
	}

/**
 * @brief WuRx device instantiation
 *
 * Provides wake-up radio functionality with dual-algorithm detection,
 * configurable timing parameters, and power management integration.
 */
#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static const struct wurx_atmosic_config wurx_config = WURX_ATMOSIC_CONFIG();
static struct wurx_atmosic_data wurx_data;

DEVICE_DT_INST_DEFINE(0, wurx_atmosic_init, NULL, &wurx_data, &wurx_config, POST_KERNEL, 60,
		      &wurx_atmosic_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
