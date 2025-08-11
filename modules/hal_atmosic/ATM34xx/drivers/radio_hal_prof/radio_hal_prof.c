/**
 *******************************************************************************
 *
 * @file radio_hal_prof.c
 *
 * @brief Radio Profile Driver Interface
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include "arch.h"
#include "radio_hal_log.h"
#include "radio_hal_prof.h"

void atm_mac_prof_latency_update(atm_mac_prof_t *prof, uint16_t latency)
{
    __UNUSED bool failure =
	prof->check_callback(latency) && !(latency <= prof->threshold);
#if RADIO_HAL_PROF_TRACKING
    bool changed = false;
    if (prof->max_latency < latency) {
	prof->max_latency = latency;
	changed = true;
    }
    if (prof->min_latency > latency) {
	prof->min_latency = latency;
	changed = true;
    }
    failure &= changed; // Don't print the same data multiple times
#endif
#ifdef CFG_PLF_DEBUG
    if (failure) {
	atm_mac_log(prof->log_type,
#if RADIO_HAL_PROF_TRACKING
	    prof->max_latency, prof->threshold, prof->min_latency);
#else
	    latency, prof->threshold, 0);
#endif
    }
#endif
}
