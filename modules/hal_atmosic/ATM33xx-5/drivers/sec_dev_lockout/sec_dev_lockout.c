/**
 ******************************************************************************
 *
 * @file sec_dev_lockout.c
 *
 * @brief Secure device feature lockout driver
 *
 * Copyright (C) Atmosic 2022-2023
 *
 ******************************************************************************
 */

#include "arch.h"
#include <inttypes.h>
#include "sec_dev_lockout.h"
#include "at_wrpr.h"
#include "at_apb_clkrstgen_regs_core_macro.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "at_apb_shub_regs_core_macro.h"

bool sec_shutdown_shub(void)
{
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
    {
	// make sure we fully disable the SHUB by clock gating, reseting
	// AND cutting off VDD. the FLASH_CTRL1/FLASH_CTRL2 go to their
	// reset values when powered back on.
	// Once locked the reset value cannot be undone.
	uint32_t val = CMSDK_PSEQ_NONSECURE->SENSOR_HUB_CONTROL;
	PSEQ_SENSOR_HUB_CONTROL__SHUB_CLKEN__CLR(val);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_RESET__SET(val);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_ISO__SET(val);
	PSEQ_SENSOR_HUB_CONTROL__SHUB_VDDCUT__SET(val);
	CMSDK_PSEQ_NONSECURE->SENSOR_HUB_CONTROL = val;
    }
    WRPR_CTRL_POP();

    return true;
}

bool sec_device_pgm_lockout(uint32_t mask)
{
    WRPR_CTRL_PUSH(CMSDK_CLKRSTGEN_NONSECURE, WRPR_CTRL__CLK_ENABLE)
    {
	CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__MODIFY(
	    CMSDK_CLKRSTGEN_NONSECURE->USER_CLK_GATE_CTRL, 1);

	CMSDK_WRPR0_NONSECURE->PROT_BITS_SET1 |= mask;

	CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__MODIFY(
	    CMSDK_CLKRSTGEN_NONSECURE->USER_CLK_GATE_CTRL, 0);
    }
    WRPR_CTRL_POP();

    return true;
}
