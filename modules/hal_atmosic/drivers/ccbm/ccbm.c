/**
 *******************************************************************************
 *
 * @file ccbm.c
 *
 * @brief Coin Cell Battery Management (CCBM) Implementation
 *
 * This module implements high current generation for coin cell battery
 * management.
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/adc.h>
#include <soc.h>
#include <errno.h>

#include "arch.h"
#include "at_wrpr.h"
#include "rif_regs_core_macro.h"
#include "radio_spi.h"
#include "radio_synth_regs_core_macro.h"
#include "spi.h"

#include "radio_hal_frc.h"
#include "radio_hal_mgr.h"
#include "ble_driver.h"

#include "pmu.h"
#include "pmu_cfg.h"
#include "atm_adc.h"
#include "ccbm.h"
#include "hw_cfg.h"

LOG_MODULE_REGISTER(ccbm, CONFIG_CCBM_LOG_LEVEL);

/* CCBM driver only works with coin cell (non-rechargeable) batteries */
BUILD_ASSERT(BATT_TYPE == BATT_TYPE_NON_RECHARGEABLE,
    "CCBM driver requires BATT_TYPE_NON_RECHARGEABLE (coin cell battery)");

/* Base expected duration for radio manager scheduling (microseconds)
 * This covers the ADC measurement and register operations overhead.
 * The settling delay (duration_ms) is added to this value.
 */
#define CCBM_BASE_DURATION_US 5000

/* ADC configuration */
#define ADC_RESOLUTION DT_PROP(DT_NODELABEL(adc), resolution)
#define ADC_CHANNEL_VBATT \
    ADC_CHANNEL_DT_NODE(DT_NODELABEL(adc), DT_PROP(DT_NODELABEL(adc), ch_cell))
#define ADC_CHANNEL_VBATT_ID DT_REG_ADDR(ADC_CHANNEL_VBATT)

static const struct device *const adc_dev = DEVICE_DT_GET(DT_NODELABEL(adc));
static const struct adc_channel_cfg adc_channel_cfg =
    ADC_CHANNEL_CFG_DT(ADC_CHANNEL_VBATT);

/* Driver state */
static K_SEM_DEFINE(ccbm_start_sem, 0, 1);
static K_MUTEX_DEFINE(ccbm_mutex);

/* Async operation context */
static struct {
    ccbm_check_callback_t check_cb;
    ccbm_callback_t callback;
    void *user_data;
    uint32_t duration_ms;
    struct k_work work;
    bool busy;
    ccbm_result_t result;
} ccbm_async_ctx;

static bool ccbm_driver_give(void)
{
    k_sem_give(&ccbm_start_sem);
    return true;
}

/**
 * @brief Measure battery voltage using GADC
 *
 * @param[out] vbatt_mv Pointer to store battery voltage in millivolts
 * @return 0 on success, negative error code on failure
 */
static int ccbm_measure_vbatt(int32_t *vbatt_mv)
{
    int32_t sample_buffer;

    const struct adc_sequence sequence = {
	.channels = BIT(ADC_CHANNEL_VBATT_ID),
	.buffer = &sample_buffer,
	.buffer_size = sizeof(sample_buffer),
	.resolution = ADC_RESOLUTION,
    };

    /* Perform synchronous ADC read */
    int ret = adc_read(adc_dev, &sequence);
    if (ret) {
	LOG_ERR("ADC read failed: %d", ret);
	return ret;
    }

    /* Convert raw ADC value to millivolts */
    uint16_t ref = adc_ref_internal(adc_dev);
    int32_t mv = sample_buffer;
    ret = atm_adc_raw_to_millivolts(ref, adc_channel_cfg.gain, ADC_RESOLUTION,
	&mv);
    if (ret) {
	LOG_ERR("ADC conversion failed: %d", ret);
	return ret;
    }

    *vbatt_mv = mv;
    return 0;
}

/**
 * @brief Measure battery voltage with constant load applied
 *
 * This function performs the actual register writes to enable load,
 * measures battery voltage, and then disables the load.
 * It should be called while holding exclusive radio access.
 *
 * @param[in] settling_delay_ms Delay after enabling load before measuring ADC
 * (0 is valid)
 * @param[out] vbatt_with_load_mv Pointer to store with-load voltage (must not
 * be NULL)
 * @return 0 on success, negative error code on ADC failure
 */
static int ccbm_measure_vbatt_with_load(uint32_t settling_delay_ms,
    int32_t *vbatt_with_load_mv)
{
    hw_cfg_lna_atten(true);

    /* Wait for settling delay before measuring (0 is valid) */
    if (settling_delay_ms > 0) {
	k_msleep(settling_delay_ms);
    }

    /* Measure battery voltage under load condition */
    int ret = ccbm_measure_vbatt(vbatt_with_load_mv);

    hw_cfg_lna_atten(false);

    return ret;
}

/**
 * @brief Internal function to execute CCBM operation with radio manager
 *
 * All ADC measurements (no-load and with-load) are performed while holding
 * exclusive radio access through the radio HAL manager.
 *
 * @param[in] duration_ms Settling delay after enabling load before ADC
 * measurement
 * @param[in] check_cb Optional authorization callback invoked after radio idle
 * is acquired. Return true to proceed, false to abort. May be NULL.
 * @param[in] user_data User-provided context pointer passed to check_cb
 * @param[out] result Pointer to store measurement results
 * @return CCBM_STATUS_SUCCESS on success, CCBM_STATUS_ABORTED if check_cb
 * denied the measurement, or another negative status on error
 */
static ccbm_status_t ccbm_execute(uint32_t duration_ms,
    ccbm_check_callback_t check_cb, void *user_data, ccbm_result_t *result)
{
    int32_t vbatt_no_load_mv;
    int32_t vbatt_with_load_mv;

    atm_mac_lock_sync();

    /* Initialize results */
    result->impedance = 0;
    result->vbatt_no_load_mv = 0;
    result->vbatt_with_load_mv = 0;

    /* Schedule operation with radio manager */
    uint32_t now_us = atm_mac_frc_get_current_time();
    atm_mac_mgr_priority_t priority = 0;
    PRIORITY_CRITICAL_SET(priority);
    PRIORITY_PROTOCOL_MODIFY(priority, ATM_MAC_MGR_PROT_CAL);

    uint32_t expected_duration_us =
	(duration_ms * 1000) + CCBM_BASE_DURATION_US;

    atm_mac_mgr_op_data_t op = {
	.start_time = now_us,
	// Allow maximum delay before starting (35 mins)
	.latest_start_time = now_us + 0x7FFFFFFF,
	.expected_duration = expected_duration_us,
	.priority = priority,
	.protocol = ATM_MAC_MGR_PROT_CAL,
    };

    k_sem_reset(&ccbm_start_sem);
    atm_mac_mgr_schedule_op(atm_mac_mgr_get_iface(), &op);
    k_sem_take(&ccbm_start_sem, K_FOREVER);

    /* Now holding exclusive radio access */

    /* Invoke authorization callback before starting measurements */
    if (check_cb && !check_cb(user_data)) {
	LOG_INF("CCBM measurement aborted by check callback");
	atm_mac_mgr_complete_op(atm_mac_mgr_get_iface(), ATM_MAC_MGR_PROT_CAL);
	atm_mac_unlock();
	return CCBM_STATUS_ABORTED;
    }

    /* Measure battery voltage before applying load (no-load condition) */
    int ret = ccbm_measure_vbatt(&vbatt_no_load_mv);
    if (ret) {
	LOG_ERR("No-load voltage measurement failed: %d", ret);
	atm_mac_mgr_complete_op(atm_mac_mgr_get_iface(), ATM_MAC_MGR_PROT_CAL);
	atm_mac_unlock();
	return CCBM_STATUS_ADC_ERROR;
    }

    /* Execute recipe and measure voltage with load */
    ret = ccbm_measure_vbatt_with_load(duration_ms, &vbatt_with_load_mv);

    atm_mac_mgr_complete_op(atm_mac_mgr_get_iface(), ATM_MAC_MGR_PROT_CAL);
    atm_mac_unlock();

    if (ret) {
	LOG_ERR("With-load voltage measurement failed: %d", ret);
	return CCBM_STATUS_ADC_ERROR;
    }

    LOG_INF("VBATT no-load: %d mV", vbatt_no_load_mv);
    LOG_INF("VBATT with-load: %d mV", vbatt_with_load_mv);

#ifdef CONFIG_BATT_MODEL
    /* Known battery model: internal resistance causes voltage sag under load,
     * so no-load must always be >= with-load. */
    ASSERT_ERR(vbatt_no_load_mv >= vbatt_with_load_mv);
#else
    /* No battery model configured (e.g. USB-powered CI board): near-zero
     * source impedance means no sag is expected; clamp any ADC-noise inversion.
     */
    if (vbatt_with_load_mv > vbatt_no_load_mv) {
	LOG_WRN(
	    "No batt model: with-load (%d mV) > no-load (%d mV); clamping delta to 0",
	    vbatt_with_load_mv, vbatt_no_load_mv);
	vbatt_with_load_mv = vbatt_no_load_mv;
    }
#endif

    uint32_t lna_atten_curr = hw_cfg_get_lna_curr(vbatt_with_load_mv);

    /* Compute impedance measurement in mOhm */
    result->impedance =
	(vbatt_no_load_mv - vbatt_with_load_mv) * 1000000 / lna_atten_curr;

    /* Store voltage measurements in result */
    result->vbatt_no_load_mv = vbatt_no_load_mv;
    result->vbatt_with_load_mv = vbatt_with_load_mv;

    return CCBM_STATUS_SUCCESS;
}

/**
 * @brief Work handler for async CCBM operation
 */
static void ccbm_async_work_handler(struct k_work *work)
{
    ccbm_status_t status;
    ccbm_callback_t callback;
    void *user_data;
    ccbm_result_t result;

    LOG_INF(
	"Initiating impedance and voltage measurement (settling delay: %u ms)",
	ccbm_async_ctx.duration_ms);

    status = ccbm_execute(ccbm_async_ctx.duration_ms, ccbm_async_ctx.check_cb,
	ccbm_async_ctx.user_data, &result);

    LOG_INF("CCBM operation complete, status: %d", status);

    /* Save callback info before clearing busy flag */
    callback = ccbm_async_ctx.callback;
    user_data = ccbm_async_ctx.user_data;

    /* Store results in context only if measurement succeeded */
    if (status == CCBM_STATUS_SUCCESS) {
	ccbm_async_ctx.result = result;
    }

    /* Clear busy flag */
    k_mutex_lock(&ccbm_mutex, K_FOREVER);
    ccbm_async_ctx.busy = false;
    k_mutex_unlock(&ccbm_mutex);

    /* Invoke done callback only if measurement was not aborted */
    if (callback && status != CCBM_STATUS_ABORTED) {
	callback(status, (status == CCBM_STATUS_SUCCESS) ? &result : NULL,
	    user_data);
    }
}

int ccbm_measure_impedance(uint32_t duration_ms, ccbm_check_callback_t check_cb,
    ccbm_callback_t done_cb, void *user_data)
{
    if (done_cb == NULL) {
	LOG_ERR("Callback is required");
	return CCBM_STATUS_INVALID;
    }

    k_mutex_lock(&ccbm_mutex, K_FOREVER);
    if (ccbm_async_ctx.busy) {
	k_mutex_unlock(&ccbm_mutex);
	LOG_ERR("CCBM driver is busy");
	return CCBM_STATUS_BUSY;
    }

    /* Set up async context */
    ccbm_async_ctx.busy = true;
    ccbm_async_ctx.duration_ms = duration_ms;
    ccbm_async_ctx.check_cb = check_cb;
    ccbm_async_ctx.callback = done_cb;
    ccbm_async_ctx.user_data = user_data;
    k_mutex_unlock(&ccbm_mutex);

    /* Submit work to system workqueue */
    k_work_submit(&ccbm_async_ctx.work);

    LOG_DBG("CCBM operation scheduled");
    return CCBM_STATUS_SUCCESS;
}

int ccbm_init(void)
{
    int ret;

    /* Verify ADC device is ready */
    if (!device_is_ready(adc_dev)) {
	LOG_ERR("ADC device not ready");
	return -ENODEV;
    }

    /* Set up ADC channel for battery voltage measurement */
    ret = adc_channel_setup(adc_dev, &adc_channel_cfg);
    if (ret) {
	LOG_ERR("ADC channel setup failed: %d", ret);
	return ret;
    }
    LOG_DBG("ADC channel %d configured for VBATT", ADC_CHANNEL_VBATT_ID);

    /* Initialize async work */
    k_work_init(&ccbm_async_ctx.work, ccbm_async_work_handler);

    /* Register with radio manager */
    atm_mac_mgr_register_deferred_api(atm_mac_mgr_get_iface(),
	ATM_MAC_MGR_PROT_CAL, ccbm_driver_give);
    LOG_DBG("CCBM driver registered with radio manager");
    return 0;
}

#ifdef CONFIG_ATM_CCBM_AUTO_INIT
static int ccbm_sys_init(void)
{
    return ccbm_init();
}

SYS_INIT(ccbm_sys_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
#endif
