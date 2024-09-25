/**
 *******************************************************************************
 *
 * @file batt_model_coin.c
 *
 * @brief Battery model for coin cell
 *
 * Copyright (C) Atmosic 2022-2023
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#endif

#include "arch.h"
#include "batt_model.h"
#define BATT_MODEL_COIN_INTERNAL_GUARD
#include "batt_model_coin_internal.h"

#ifndef CONFIG_SOC_FAMILY_ATM
#include "gadc.h"
#include "atm_log.h"
ATM_LOG_LOCAL_SETTING("batt_coin", V);
#else
#include <zephyr/drivers/adc.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(batt_model_coin, CONFIG_BATT_MODEL_LOG_LEVEL);
#define ATM_LOG(MSK, fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#endif

static batt_cbs const *fns;
static void (*lvl_cb)(uint8_t);

#ifdef CONFIG_SOC_FAMILY_ATM
#define ADC_BUFFER_SIZE 1
#define ADC_RESOLUTION DT_PROP(DT_NODELABEL(adc), resolution)
#define ADC_CHANNEL ADC_CHANNEL_DT_NODE(DT_NODELABEL(adc), DT_PROP(DT_NODELABEL(adc), ch_cell))
#define ADC_CHANNEL_ID DT_REG_ADDR(ADC_CHANNEL)

struct device const *coin = DEVICE_DT_GET(DT_NODELABEL(adc));

static struct adc_channel_cfg const channel_cfg = ADC_CHANNEL_CFG_DT(ADC_CHANNEL);
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
static void batt_coin_calc_lvl(float result, struct gadc_fifo_s raw_fifo,
    struct gadc_cal_s cal, gadc_cb_ctx_t const *ctx)
#else
static void batt_coin_calc_lvl(float result)
#endif
{
    uint8_t bat_lvl =
#ifdef CFG_FORMULA_OVERWRITE
	fns->volt_to_level(result);
#else
	batt_coin_volt_to_lvl(result);
#endif
    __UNUSED int result_mv = result * 1000;
    ATM_LOG(V, "result %dmV, Capacity %u%%", result_mv, bat_lvl);

    if (bat_lvl > 100) {
	ATM_LOG(D, "%s: Wrong battery level (%d)", __func__, bat_lvl);
	bat_lvl = 100;
    }

    if (fns && fns->state.get && fns->state.set) {
	// always boot in coin-cell
	if (fns->state.get() != DEV_ACTV) {
	    fns->state.set(DEV_ACTV);
	}
    }

    lvl_cb(bat_lvl);
    lvl_cb = NULL;
}

static bool batt_coin_gadc_sample(void (*cb)(uint8_t))
{
    if (lvl_cb) {
	return false;
    }

    lvl_cb = cb;
#ifndef CONFIG_SOC_FAMILY_ATM
    gadc_sample_channel(VBATT, batt_coin_calc_lvl, VBATT_GEXT_DEFAULT, NULL);
#else
    int16_t m_sample_buffer[ADC_BUFFER_SIZE];
    struct adc_sequence const sequence = {
	.channels = BIT(ADC_CHANNEL_ID),
	.buffer = m_sample_buffer,
	.buffer_size = sizeof(m_sample_buffer),
	.resolution = ADC_RESOLUTION,
    };
    struct k_poll_signal async_sig = K_POLL_SIGNAL_INITIALIZER(async_sig);
    struct k_poll_event async_evt = K_POLL_EVENT_INITIALIZER(K_POLL_TYPE_SIGNAL,
	K_POLL_MODE_NOTIFY_ONLY, &async_sig);

    int ret = adc_read_async(coin, &sequence, &async_sig);
    ASSERT_INFO(ret == 0, ret, 0);

    ret = k_poll(&async_evt, 1, K_FOREVER);
    ASSERT_INFO(ret == 0, ret, 0);
    batt_coin_calc_lvl(m_sample_buffer[0] / 1000.0f);
#endif
    return true;
}

static void batt_coin_init(batt_cbs const *init)
{
    fns = init;

#ifdef CONFIG_SOC_FAMILY_ATM
    ASSERT_ERR(coin != NULL);

    int ret = adc_channel_setup(coin, &channel_cfg);
    ASSERT_INFO(ret == 0, ret, 0);
#endif
}

batt_fns const *batt_model(void)
{
    static batt_fns const coin_model = {
	.init = batt_coin_init,
	.sample = batt_coin_gadc_sample,
    };
    return &coin_model;
}
