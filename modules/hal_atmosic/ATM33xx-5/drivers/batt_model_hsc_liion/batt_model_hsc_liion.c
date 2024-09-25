/**
 ******************************************************************************
 *
 * @file batt_model_hsc_liion.c
 *
 * @brief Lithium Ion and Hybrid Supercap driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#endif

#include "arch.h"
#include <inttypes.h>
#include <math.h>
#include "calibration.h"
#include "at_wrpr.h"
#include "pmu_cfg.h"
#include "pmu.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "gadc.h"
#else
#include <zephyr/drivers/adc.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(batt_model_hsc_liion, CONFIG_BATT_MODEL_LOG_LEVEL);
#undef DEBUG_TRACE
#define DEBUG_TRACE(fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#endif
#include "batt_model.h"
#ifdef CFG_CABLE_CHARGE
#include "atm_gpio.h"
#include "pinmux.h"
#include "interrupt.h"
#endif

#ifdef BATT_MODEL_HSC
#ifndef VOLT_MAX
#define VOLT_MAX 3.8f
#endif

#ifndef VOLT_MIN
#define VOLT_MIN 2.8f
#endif

#ifndef VBAT_OV
#define VBAT_OV 3.8f
#endif

#ifndef VBAT_OV_HYS
#define VBAT_OV_HYS 3.75f
#endif

#ifdef BOOST_FROM_VHARV_TWO_DIODE
#error "BOOST_FROM_VHARV_TWO_DIODE is not avalible in BATT_MODEL_HSC"
#endif
#else // BATT_MODEL_HSC
#ifndef VBAT_UV
#define VBAT_UV 3.0f
#endif

#ifndef VBAT_OV
#define VBAT_OV 4.2f
#endif

#ifndef VBAT_OV_HYS
#define VBAT_OV_HYS 4.15f
#endif

#ifndef CAPA_T
#define CAPA_T 0.9f
#endif

#ifndef VBAT_T
#define VBAT_T (CAPA_T * VBAT_OV)
#endif

#endif // BATT_MODEL_HSC

#ifndef VBAT_BOOST
#define VBAT_BOOST 3.0f
#endif

#ifndef VBAT_BOOST_HYS
#define VBAT_BOOST_HYS 2.95f
#endif

#ifndef VBAT_BOOST_OFFSET
#define VBAT_BOOST_OFFSET 1.1f
#endif

#ifndef CANHARV_READ_COUNT
#define CANHARV_READ_COUNT 500
#endif

enum {
    VBAT_MAX_IDX,
    VBAT_BOOST_IDX,
    VBAT_IDX_MAX,
};

static batt_cbs const *fns;
static void (*lvl_cb)(uint8_t);
static bool batt_gadc_sampling;

#ifdef CONFIG_SOC_FAMILY_ATM
#define ADC_BUFFER_SIZE 1
#define ADC_RESOLUTION DT_PROP(DT_NODELABEL(adc), resolution)
#define ADC_CHANNEL ADC_CHANNEL_DT_NODE(DT_NODELABEL(adc), DT_PROP(DT_NODELABEL(adc), ch_batt))
#define ADC_CHANNEL_ID DT_REG_ADDR(ADC_CHANNEL)

struct device const *hsc_liion = DEVICE_DT_GET(DT_NODELABEL(adc));

static struct adc_channel_cfg const channel_cfg = ADC_CHANNEL_CFG_DT(ADC_CHANNEL);
#endif

static bool vbat_mem[VBAT_IDX_MAX] = {false, true};

static void batt_max_vbat_check(float vbat)
{
    if (vbat_mem[VBAT_MAX_IDX]) {
	if (vbat < VBAT_OV_HYS) {
	    vbat_mem[VBAT_MAX_IDX] = false;
	}
	return;
    }

    if (vbat >= VBAT_OV) {
	vbat_mem[VBAT_MAX_IDX] = true;
	vbat_mem[VBAT_BOOST_IDX] = true;
    }
}

#if !(defined(BOOST_FROM_VHARV_INDUCTOR) || defined(BOOST_FROM_VHARV_TWO_DIODE))
static void batt_boost_vbat_check(float vbat)
{
    if (vbat_mem[VBAT_BOOST_IDX]) {
	if (vbat < VBAT_BOOST_HYS) {
	    vbat_mem[VBAT_BOOST_IDX] = false;
	}
    } else {
	if (vbat >= VBAT_BOOST) {
	    vbat_mem[VBAT_BOOST_IDX] = true;
	}
    }
}
#endif

static uint8_t batt_capacity(float result)
{
#ifdef BATT_MODEL_HSC
    uint8_t bat_lvl;

    if (result <= VOLT_MIN) {
	bat_lvl = 0;
    } else if (result > VOLT_MAX) {
	bat_lvl = 100;
    } else {
	bat_lvl = (((result * result) - (VOLT_MIN * VOLT_MIN)) * 100) /
	    ((VOLT_MAX * VOLT_MAX) - (VOLT_MIN * VOLT_MIN));
    }

    __UNUSED int result_mv = result * 1000;
    DEBUG_TRACE("volt %dmV, Capacity %u%%", result_mv, bat_lvl);
#else
    // VBAT_OV > V > VBAT_T:
    // capacity (%) = (100-CAPA_T)/(VBAT_OV-VBAT_T) * (V-VBAT_OV) + 100
    // VBAT_T > V:
    // capacity (%) = (10^(4*V/VBAT_UV)-10^4) / (10^(4*VBAT_T/VBAT_UV)-10^4) *
    // CAPA_T
    float capacity;
    if (result >= VBAT_T) {
	capacity = (100.0f - CAPA_T) / (VBAT_OV - VBAT_T) * (result - VBAT_OV) +
	    100.0f;
    } else {
	capacity = (powf(10.0f, 4.0f * result / VBAT_UV) - powf(10.0f, 4.0f)) /
	    (powf(10.0f, 4.0f * VBAT_T / VBAT_UV) - powf(10.0f, 4.0f)) * CAPA_T;
    }

    uint8_t bat_lvl = lrintf(capacity);
    __UNUSED int result_mv = result * 1000;
    DEBUG_TRACE("Li-ion result %dmV, capacity %u%%", result_mv, bat_lvl);
#endif
    return bat_lvl;
}

#ifndef CONFIG_SOC_FAMILY_ATM
static void batt_process_vbat(float result, struct gadc_fifo_s raw_fifo,
    struct gadc_cal_s cal, gadc_cb_ctx_t const *ctx)
#else
static void batt_process_vbat(float result)
#endif
{
    __UNUSED int result_mv = result * 1000;
    DEBUG_TRACE("%s(begin): vbatli=%dmV, vbat_max=%d, vbat_boost=%d", __func__,
	result_mv, vbat_mem[VBAT_MAX_IDX], vbat_mem[VBAT_BOOST_IDX]);

    // Calculate the battery capacity based on the voltage level from gadc
    uint8_t bat_lvl = batt_capacity(result);

    batt_max_vbat_check(result);
#if defined(BOOST_FROM_VHARV_INDUCTOR) || defined(BOOST_FROM_VHARV_TWO_DIODE)
    vbat_mem[VBAT_BOOST_IDX] = true;
#else
    if (!vbat_mem[VBAT_MAX_IDX]) {
	batt_boost_vbat_check(result);
    }
#endif

    DEBUG_TRACE("%s(end): vbat_max=%d, vbat_boost=%d can_harv = %" PRIu32, __func__,
	vbat_mem[VBAT_MAX_IDX], vbat_mem[VBAT_BOOST_IDX],
	pmu_harv_get_harvcnt(CANHARV_READ_COUNT));

#ifdef BOOST_FROM_VHARV_INDUCTOR
    pmu_set_harv_indicator(!(vbat_mem[VBAT_MAX_IDX] &&
	vbat_mem[VBAT_BOOST_IDX]));
#else
#ifndef BOOST_FROM_VHARV_TWO_DIODE
    pmu_vstore_vbatli_bypass((!vbat_mem[VBAT_MAX_IDX]) &&
	(!vbat_mem[VBAT_BOOST_IDX]), false);
#endif // BOOST_FROM_VHARV_TWO_DIODE
    ASSERT_ERR(result >= VBAT_BOOST_OFFSET);
    pmu_set_charge_pump((!vbat_mem[VBAT_MAX_IDX]) &&
	(vbat_mem[VBAT_BOOST_IDX]), result - VBAT_BOOST_OFFSET, true);
#endif // BOOST_FROM_VHARV_INDUCTOR

    fns->flag.set(VBAT_MAX_IDX, vbat_mem[VBAT_MAX_IDX]);
    fns->flag.set(VBAT_BOOST_IDX, vbat_mem[VBAT_BOOST_IDX]);
#ifdef CFG_CABLE_CHARGE
    if (fns->cable &&
	fns->cable(atm_gpio_read_gpio(PIN_CHARGE_DET_IO), bat_lvl)) {
	fns->state.set(DEV_HIB);
    } else
#endif
    if (fns->state.get() != DEV_ACTV) {
	fns->state.set(DEV_ACTV);
    }

    if (lvl_cb) {
	lvl_cb(bat_lvl);
	lvl_cb = NULL;
    }

    batt_gadc_sampling = false;
}

static bool batt_gadc_sample(void (*cb)(uint8_t))
{
    if (batt_gadc_sampling) {
	return false;
    }

    lvl_cb = cb;
    batt_gadc_sampling = true;

#ifndef CONFIG_SOC_FAMILY_ATM
    gadc_sample_channel(LI_ION_BATT, batt_process_vbat,
	LI_ION_BATT_GEXT_DEFAULT, NULL);
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

    int ret = adc_read_async(hsc_liion, &sequence, &async_sig);
    ASSERT_INFO(ret == 0, ret, 0);

    ret = k_poll(&async_evt, 1, K_FOREVER);
    ASSERT_INFO(ret == 0, ret, 0);
    batt_process_vbat(m_sample_buffer[0] / 1000.0f);
#endif

    return true;
}

#ifdef CFG_CABLE_CHARGE
static void usb_det_intr(uint32_t mask)
{
    atm_gpio_clear_int_status(PIN_CHARGE_DET_IO);
    batt_gadc_sample(NULL);
}
#endif

static void batt_init(batt_cbs const *init)
{
    fns = init;
    if (fns->state.get() == DEV_HIB) {
	vbat_mem[VBAT_MAX_IDX] = fns->flag.get(VBAT_MAX_IDX);
	vbat_mem[VBAT_BOOST_IDX] = fns->flag.get(VBAT_BOOST_IDX);
    }

#ifdef CONFIG_SOC_FAMILY_ATM
    ASSERT_ERR(hsc_liion != NULL);

    int ret = adc_channel_setup(hsc_liion, &channel_cfg);
    ASSERT_INFO(ret == 0, ret, 0);
#endif

#ifdef CFG_CABLE_CHARGE
    atm_gpio_setup(PIN_CHARGE_DET_IO);
    atm_gpio_set_input(PIN_CHARGE_DET_IO);
    atm_gpio_int_set_falling(PIN_CHARGE_DET_IO);
    atm_gpio_clear_int_status(PIN_CHARGE_DET_IO);
    interrupt_install_gpio(PIN_CHARGE_DET_IO, IRQ_PRI_UI, usb_det_intr);
    atm_gpio_set_int_enable(PIN_CHARGE_DET_IO);
#endif
}

batt_fns const *batt_model(void)
{
    static batt_fns const model = {
	.init = batt_init,
	.sample = batt_gadc_sample,
    };
    return &model;
}
