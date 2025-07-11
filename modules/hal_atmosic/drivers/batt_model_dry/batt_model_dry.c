/**
 *******************************************************************************
 *
 * @file batt_model_dry.c
 *
 * @brief Battery model for dry cell
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#endif

#include "arch.h"
#include <math.h>
#include "batt_model.h"

#ifndef CONFIG_SOC_FAMILY_ATM
#include "gadc.h"
#include "atm_log.h"
ATM_LOG_LOCAL_SETTING("batt_dry", V);
#else
#include <zephyr/drivers/adc.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(batt_model_dry, CONFIG_BATT_MODEL_LOG_LEVEL);
#define ATM_LOG(MSK, fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#endif

#define BASIS_POINTS_MAX 10000

static batt_cbs const *fns;
static void (*lvl_cb)(uint16_t, int32_t);

#ifdef CONFIG_SOC_FAMILY_ATM
#define ADC_BUFFER_SIZE 1
#define ADC_RESOLUTION DT_PROP(DT_NODELABEL(adc), resolution)
#define ADC_CHANNEL ADC_CHANNEL_DT_NODE(DT_NODELABEL(adc), DT_PROP(DT_NODELABEL(adc), ch_p1single1))
#define ADC_CHANNEL_ID DT_REG_ADDR(ADC_CHANNEL)

struct device const *dry = DEVICE_DT_GET(DT_NODELABEL(adc));

static struct adc_channel_cfg const channel_cfg = ADC_CHANNEL_CFG_DT(ADC_CHANNEL);
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
static void batt_dry_calc_lvl(float result)
#elif defined(GADC_HAS_FIFO_S)
static void batt_dry_calc_lvl(float result, struct gadc_fifo_s raw_fifo,
    struct gadc_cal_s cal, gadc_cb_ctx_t const *ctx)
#else
static void batt_dry_calc_lvl(float result, int16_t raw, struct gadc_cal_s cal,
    gadc_cb_ctx_t const *ctx)
#endif
{
    // Capacity = (10^(V/v0) - 10^(vmin/v0))*100/(10^(vmax/v0) - 10^(vmin/v0))
    // vmin = 1, vmax = 1.5, v0 = 0.5
    //
    // Capacity = (10^(V/0.5) - 10^(1/0.5))*100/(10^(1.5/0.5) - 10^(1/0.5))
    // Capacity = (10^(V*2) - 10^2)*10^2/(10^3 - 10^2)
    // Capacity = (10^(V*2) - 10^2)/(10 - 1)
    // Capacity = (10^(V*2) - 100)/9
    float val_lim = (result > 1.5f) ? 1.5f : (result < 1.0f) ? 1.0f : result;
    float capacity = ((powf(expf(val_lim * 2), 2.30258512f)) - 100.0f) / 9.0f;
    capacity *= 100.0f; // convert to basis points

    // Update battery level
    uint16_t bat_lvl = lrintf(capacity);

    int result_mv = result * 1000;
    ATM_LOG(V, "result %dmV, Capacity %u basis points", result_mv, bat_lvl);

    if (bat_lvl > BASIS_POINTS_MAX) {
	ATM_LOG(D, "%s: Wrong battery level (%u)", __func__, bat_lvl);
	bat_lvl = BASIS_POINTS_MAX;
    }

    if (fns && fns->state.get && fns->state.set) {
	// always boot in dry-cell
	if (fns->state.get() != DEV_ACTV) {
	    fns->state.set(DEV_ACTV);
	}
    }

    if (lvl_cb) {
	lvl_cb(bat_lvl, result_mv);
	lvl_cb = NULL;
    }
}

static bool batt_dry_gadc_sample(void (*cb)(uint16_t, int32_t))
{
    if (lvl_cb) {
	ATM_LOG(W, "batt calc ongoing");
	return false;
    }

    lvl_cb = cb;
#ifndef CONFIG_SOC_FAMILY_ATM
    gadc_sample_channel(PORT1_SINGLE_ENDED_1, batt_dry_calc_lvl,
	PORT1_SINGLE_ENDED_1_GEXT_DEFAULT, NULL);
#else
    int32_t m_sample_buffer[ADC_BUFFER_SIZE];
    struct adc_sequence const sequence = {
	.channels = BIT(ADC_CHANNEL_ID),
	.buffer = m_sample_buffer,
	.buffer_size = sizeof(m_sample_buffer),
	.resolution = ADC_RESOLUTION,
    };
    struct k_poll_signal async_sig = K_POLL_SIGNAL_INITIALIZER(async_sig);
    struct k_poll_event async_evt = K_POLL_EVENT_INITIALIZER(K_POLL_TYPE_SIGNAL,
	K_POLL_MODE_NOTIFY_ONLY, &async_sig);

    int ret = adc_read_async(dry, &sequence, &async_sig);
    ASSERT_INFO(ret == 0, ret, 0);

    ret = k_poll(&async_evt, 1, K_FOREVER);
    ASSERT_INFO(ret == 0, ret, 0);

    /* Convert raw ADC value to millivolts, then to volts */
    int32_t mv = m_sample_buffer[0];
    uint16_t ref = adc_ref_internal(dry);
    ret = adc_raw_to_millivolts(ref, channel_cfg.gain, ADC_RESOLUTION, &mv);
    ASSERT_INFO(ret == 0, ret, 0);
    batt_dry_calc_lvl(mv / 1000.0f);
#endif
    return true;
}

static void batt_dry_init(batt_cbs const *init)
{
    fns = init;

#ifdef CONFIG_SOC_FAMILY_ATM
    ASSERT_ERR(dry != NULL);

    int ret = adc_channel_setup(dry, &channel_cfg);
    ASSERT_INFO(ret == 0, ret, 0);
#endif
}

batt_fns const *batt_model(void)
{
    static batt_fns const dry_model = {
	.init = batt_dry_init,
	.sample = batt_dry_gadc_sample,
    };
    return &dry_model;
}
