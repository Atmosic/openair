/**
 *******************************************************************************
 *
 * @file sec_debug.c
 *
 * @brief Secure debug driver
 *
 * Copyright (C) Atmosic 2023
 *
 *******************************************************************************
 */

#include "arch.h"
#include "base_addr.h"
#include "sec_debug.h"
#include "at_apb_wrpr_pins_regs_core_macro.h"

sec_debug_status_t sec_debug_status(void)
{
    sec_debug_status_t status = CMSDK_WRPR0_NONSECURE->SECURE_DEBUG_STAT;
    if (status <= SEC_DEBUG_STATUS_MAX && status >= SEC_DEBUG_STATUS_MIN) {
	return status;
    }
    return SEC_DEBUG_UNKNOWN;
}

bool sec_debug_sticky_disable(void)
{
    if (sec_debug_status() == SEC_DEBUG_SOFT_DISABLED) {
	CMSDK_WRPR0_NONSECURE->SECURE_DEBUG_CTRL =
	    WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__MASK &
	    ~WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__MASK;
	if (sec_debug_status() == SEC_DEBUG_STICKY_DISABLED) {
	    return true;
	}
    }
    return false;
}

bool sec_debug_unlock(void)
{
    if (sec_debug_status() == SEC_DEBUG_SOFT_DISABLED) {
	CMSDK_WRPR0_NONSECURE->SECURE_DEBUG_CTRL =
	    ~WRPRPINS_SECURE_DEBUG_CTRL__STICKY_DISABLED__MASK &
	    ~WRPRPINS_SECURE_DEBUG_CTRL__SOFT_DISABLED__MASK;
	if (sec_debug_status() == SEC_DEBUG_ENABLED) {
	    return true;
	}
    }
    return false;
}