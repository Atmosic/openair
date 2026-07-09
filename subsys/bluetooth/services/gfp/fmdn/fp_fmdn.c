/**
 *******************************************************************************
 *
 * @file fp_fmdn_gatt.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
#include "fp_common.h"
#include "fp_fmdn.h"
#include "fp_fmdn_key.h"
#include "fp_storage.h"
#include "fp_mode.h"

LOG_MODULE_REGISTER(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

bool fp_fmdn_is_utp_en(void)
{
	if (fp_mode_is_provisioned() && (fp_storage_utp_mode_get() == FP_FMDN_UTP_MODE_ON)) {
		return true;
	}
	return false;
}

void fp_fmdn_clock_set(uint32_t clock_value)
{
	fp_fmdn_key_clock_set(clock_value);
}

uint32_t fp_fmdn_clock_get(void)
{
	return fp_fmdn_key_clock_read();
}

int fp_fmdn_clock_save(void)
{
	if (!fp_mode_is_provisioned()) {
		LOG_DBG("FMDN Clock: not provisioned, skip save");
		return -ENOENT; // "No such entity" - device not provisioned
	}
	return fp_fmdn_key_clock_save();
}

void fp_fmdn_clock_reset(void)
{
	fp_fmdn_key_clock_reset();
}
