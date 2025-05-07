/**
 *******************************************************************************
 *
 * @file fp_fmdn_gatt.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) extention
 * Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/logging/log.h>
#include "fp_common.h"
#include "fp_fmdn.h"
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
