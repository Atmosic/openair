/**
 *******************************************************************************
 *
 * @file gfps.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#ifdef CONFIG_FAST_PAIR_FMDN_DULT
#include "dult.h"
#endif
#include "gfps.h"
#include "fp_adv.h"
#ifdef CONFIG_FAST_PAIR_FMDN
#include "fp_fmdn_adv.h"
#include "fp_fmdn_gatt.h"
#endif
#include "fp_gatt.h"
#include "fp_common.h"
#include "fp_conn.h"
#include "fp_storage.h"

LOG_MODULE_REGISTER(gfps, CONFIG_ATM_GFPS_LOG_LEVEL);

void gfps_handlers_register(gfps_hdlrs_t const *hdlrs)
{
#if (defined(CONFIG_FAST_PAIR_FMDN) && defined(CONFIG_FAST_PAIR_FMDN_DULT))
	if (hdlrs->utp_mode_cb) {
		fp_fmdn_gatt_utp_mode_reg(hdlrs->utp_mode_cb);
	}
	if (hdlrs->ring_action_cb) {
		fp_fmdn_gatt_ring_action_reg(hdlrs->ring_action_cb);
	}
	if (hdlrs->update_id_cb) {
		fp_fmdn_gatt_update_id_reg(hdlrs->update_id_cb);
	}
	if (hdlrs->utp_owner_conn_cb) {
		fp_fmdn_gatt_utp_owner_conn_reg(hdlrs->utp_owner_conn_cb);
	}
	if (hdlrs->battery_status_cb) {
		fp_fmdn_key_battery_reg(hdlrs->battery_status_cb);
	}
#endif // CONFIG_FAST_PAIR_FMDN && CONFIG_FAST_PAIR_FMDN_DULT
}

void gfps_button_notify(void)
{
	fp_mode_t mode = fp_mode_get();
	if (mode <= FP_MODE_PAIRED) {
#ifndef CONFIG_ATM_GFP_MUTLIMODE_TAG
		gfps_fp_pairing_adv();
#endif
	} else if (mode == FP_MODE_PROVISIONED) {
		fp_fmdn_button_notify();
	}
}

static void gfps_init_service(void)
{
	fp_conn_init();
	fp_mode_init();
	fp_gatt_init();
	fp_adv_recreate();
	fp_fmdn_adv_recreate(true, false);
}

int gfps_init(void)
{
	if (fp_storage_init()) {
		LOG_ERR("fp_storage_init returned error");
		return -EALREADY;
	}
	gfps_init_service();
	return 0;
}

void gfps_deinit(void)
{
	fp_conn_disconnect_all();
	fp_gatt_deinit();
}

void gfps_reset(void)
{
	gfps_deinit();
	fp_storage_reset();
}

void gfps_fp_pairing_adv(void)
{
	fp_mode_t mode = fp_mode_get();
	if (mode <= FP_MODE_PAIRED) {
		fp_mode_update(FP_MODE_PAIRING);
		fp_adv_recreate();
	}
}

#ifdef CONFIG_ATM_GFP_MUTLIMODE_TAG
bool gfps_fp_is_provisioned(void)
{
	return fp_storage_eid_key_valid();
}
#endif
