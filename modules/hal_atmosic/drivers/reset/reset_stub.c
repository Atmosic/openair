/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 ******************************************************************************
 *
 * @file reset_stub.h
 *
 * @brief Reset Driver Test Stubs
 *
 ******************************************************************************
 */

#include "arch.h"
#include "reset.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "pseq_status.h"

static struct reset_test_inputs const *test_inputs;

#if defined(CMSDK_SYSCON) || defined(SYS_CTRL_REG)
static uint32_t reset_syndrome_saved;
#endif

void reset_test_set_inputs(struct reset_test_inputs const *inputs)
{
    test_inputs = inputs;
#if defined(CMSDK_SYSCON) || defined(SYS_CTRL_REG)
    if (inputs) {
	*reset_get_cached_boot_status_ptr() = 0;
	reset_syndrome_saved = *reset_get_syndrome_ptr();
	*reset_get_syndrome_ptr() = inputs->syndrome;
    } else {
	*reset_get_syndrome_ptr() = reset_syndrome_saved;
    }
#endif
}

/**
 * @brief Override PSEQ status values from test inputs after hardware reads.
 *
 * @param pseq_boot_status Pointer to the boot status read from hardware.
 * @param pseq_wdog_status Pointer to the wdog status read from hardware,
 *                         or NULL if not applicable on this platform.
 */
void reset_stub_override_pseq_status(uint32_t *pseq_boot_status,
    uint32_t *pseq_wdog_status)
{
    if (!test_inputs) {
	return;
    }
    *pseq_boot_status =
	test_inputs->pseq_status & PSEQ_STATUS__POWER_ON_REASONS;
#ifdef __PSEQ_WDOG_STATUS_MACRO__
    if (pseq_wdog_status) {
	*pseq_wdog_status = test_inputs->pseq_wdog_status;
    }
#endif
}

/**
 * @brief Override PMU wakeup detect value from test inputs.
 *
 * @param hw_val Value read from hardware.
 * @return Stubbed value if test inputs active, otherwise hw_val.
 */
uint8_t reset_stub_pmu_wkup_det(uint8_t hw_val)
{
    return test_inputs ? test_inputs->pmu_wkup_det : hw_val;
}

/**
 * @brief Override PMU SOC wdog reset flag from test inputs.
 *
 * @param hw_val Value read from hardware.
 * @return Stubbed value if test inputs active, otherwise hw_val.
 */
bool reset_stub_pmu_soc_wdog_reset(bool hw_val)
{
    return test_inputs ? test_inputs->pmu_soc_wdog_reset : hw_val;
}

/**
 * @brief Override PMU PMU wdog reset flag from test inputs.
 *
 * @param hw_val Value read from hardware.
 * @return Stubbed value if test inputs active, otherwise hw_val.
 */
bool reset_stub_pmu_pmu_wdog_reset(bool hw_val)
{
    return test_inputs ? test_inputs->pmu_pmu_wdog_reset : hw_val;
}
