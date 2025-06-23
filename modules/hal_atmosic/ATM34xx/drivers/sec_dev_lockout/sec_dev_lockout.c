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
#include "at_apb_qspi_regs_core_macro.h"
#include "at_apb_shub_regs_core_macro.h"
#include "at_apb_wrpr_pins_regs_core_macro.h"

static void sticky_clock_control(uint32_t enable)
{
    WRPR_CTRL_PUSH(CMSDK_CLKRSTGEN_NONSECURE, WRPR_CTRL__CLK_ENABLE)
    {
	CLKRSTGEN_USER_CLK_GATE_CTRL__STICKY_CLK__MODIFY(
	    CMSDK_CLKRSTGEN_NONSECURE->USER_CLK_GATE_CTRL, enable);
    }
    WRPR_CTRL_POP();
}

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
    sticky_clock_control(1);
    CMSDK_WRPR0_NONSECURE->PROT_BITS_SET1 |= mask;
    CMSDK_WRPR0_NONSECURE->PROT_BITS_SET1 = 0;
    sticky_clock_control(0);

    return true;
}

bool sec_device_disable_rram_remap(void)
{
    sticky_clock_control(1);
    CMSDK_WRPR0_NONSECURE->RRAM_REMAP0 = WRPRPINS_RRAM_REMAP0__RESET_VALUE;
    CMSDK_WRPR0_NONSECURE->RRAM_REMAP1 = WRPRPINS_RRAM_REMAP1__RESET_VALUE;
    CMSDK_WRPR0_NONSECURE->RRAM_REMAP2 = WRPRPINS_RRAM_REMAP2__RESET_VALUE;
    CMSDK_WRPR0_NONSECURE->RRAM_REMAP3 = WRPRPINS_RRAM_REMAP3__RESET_VALUE;
    CMSDK_WRPR0_NONSECURE->RRAM_REMAP4 = WRPRPINS_RRAM_REMAP4__RESET_VALUE;
    CMSDK_WRPR0_NONSECURE->RRAM_REMAP5 = WRPRPINS_RRAM_REMAP5__RESET_VALUE;
    sticky_clock_control(0);

    return true;
}

bool sec_device_disable_qspi_remap(void)
{
    WRPR_CTRL_PUSH(CMSDK_QSPI, WRPR_CTRL__CLK_ENABLE)
    {
	sticky_clock_control(1);

	CMSDK_QSPI_NONSECURE->REMOTE_AHB_SETUP_7 =
	    QSPI_REMOTE_AHB_SETUP_7__RESET_VALUE;

	sticky_clock_control(0);
    }
    WRPR_CTRL_POP();
    return true;
}
