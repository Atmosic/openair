/**
 *******************************************************************************
 *
 * @file fp_mode.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Mode Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include "fp_adv.h"
#include "fp_fmdn_adv.h"
#include "fp_mode.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(gfps, CONFIG_ATM_GFPS_LOG_LEVEL);

fp_mode_t cur_mode;
static fp_mode_switch_cb mode_switch_cb;

void fp_mode_init(void)
{
	fp_mode_t update_mode;
	if (fp_storage_eid_key_valid()) {
		update_mode = FP_MODE_PROVISIONED;
	} else if (fp_storage_owner_key_valid()) {
		update_mode = FP_MODE_PAIRED;
	} else {
		update_mode = FP_MODE_NONE;
	}
	if (update_mode == FP_MODE_PAIRED) {
		LOG_INF("Update mode %u should not be happened, rollback to FP_MODE_NONE",
			update_mode);
		fp_storage_reset();
		update_mode = FP_MODE_NONE;
	}
	fp_mode_update(update_mode);
}

fp_mode_t fp_mode_get(void)
{
	return cur_mode;
}

void fp_mode_update(fp_mode_t mode)
{
	if (cur_mode != mode) {
		LOG_DBG("Update mode from %u to %u", cur_mode, mode);
		cur_mode = mode;
		if (mode_switch_cb) {
			mode_switch_cb(mode);
		}
#ifdef CONFIG_FAST_PAIR_RECREATE_ADV_ON_MODE_SWITCH
		LOG_DBG("Update mode switch to %u to recreate adv immediately", cur_mode);
		fp_adv_recreate();
		fp_fmdn_adv_recreate(false, false);
#endif
	}
}

bool fp_mode_is_provisioned(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN
	return (cur_mode == FP_MODE_PROVISIONED);
#else
	return false;
#endif
}

bool fp_mode_is_paired(void)
{
	return (cur_mode == FP_MODE_PAIRED);
}

bool fp_mode_is_pairing(void)
{
	return ((cur_mode > FP_MODE_NONE) && (cur_mode < FP_MODE_PAIRED));
}

void fp_mode_switch_reg(fp_mode_switch_cb const hdlr)
{
	if (!mode_switch_cb) {
		mode_switch_cb = hdlr;
	}
}

uint16_t fp_mode_rpa_timeout(void)
{
#define FP_FMDN_ROTATE_PERIOD 1024
#define FP_RANDOM_FACTOR      204
#define FP_ROTATE_PERIOD      (15 * 60)
	// uint16_t rpa_timeout = fp_mode_is_provisioned() ? FP_FMDN_ROTATE_PERIOD :
	// FP_ROTATE_PERIOD; rpa_timeout += (sys_rand16_get() % FP_RANDOM_FACTOR) + 1;
	return (fp_mode_is_provisioned() ? FP_FMDN_ROTATE_PERIOD : FP_ROTATE_PERIOD) +
	       ((sys_rand16_get() % FP_RANDOM_FACTOR) + 1);
}
