/**
 *******************************************************************************
 *
 * @file brwnout.c
 *
 * @brief ATM2/ATM3 Brownout Driver
 *
 * Copyright (C) Atmosic 2020-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/pm/pm.h>
#define DT_DRV_COMPAT atmosic_brownout
#endif

#include "arch.h"
#include "brwnout.h"
#include "pmu.h"

#ifndef CONFIG_SOC_FAMILY_ATM
#include "pseq.h"
#include "rep_vec.h"

#ifndef WAKE_DUR
#define WAKE_DUR 2000
#endif
#else // CONFIG_SOC_FAMILY_ATM
#include "power.h"
#endif

#define PMU_INTERNAL_GUARD
#include "pmu_internal.h"

static bool no_energy4tx;
static bool brwnout_disabled;
static bool brwnout_4ssocoff;

#ifdef CONFIG_SOC_FAMILY_ATM
static void user_init_check_brwnout(enum pm_state state);

static struct pm_notifier brownout_pm_notifier = {
	.state_entry = user_init_check_brwnout,
};
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
// Prototype declaration added to avoid dependency loop below
// brwnout_init() -> user_init_check_brwnout_hibernate() ->
// user_init_check_brwnout() -> check for user_init_check_brwnout_hibernate
static rep_vec_err_t user_init_check_brwnout_hibernate(bool *sleep,
    int32_t duration, uint32_t int_set);

__FAST static rep_vec_err_t
user_init_check_brwnout(bool *sleep, int32_t duration, uint32_t int_set,
    bool hibernate)
#else
__FAST static void user_init_check_brwnout(enum pm_state state)
#endif
{
#ifdef CONFIG_SOC_FAMILY_ATM
    if ((state != PM_STATE_SUSPEND_TO_RAM) && (state != PM_STATE_SOFT_OFF)) {
	return;
    }
#else
    if (brwnout_disabled) {
	return (RV_NEXT);
    }
#endif

    no_energy4tx = pmu_read_no_energy4tx();

    if (!no_energy4tx && !brwnout_4ssocoff) {
#ifndef CONFIG_SOC_FAMILY_ATM
	return (RV_NEXT);
#else
	return;
#endif
    }

    DEBUG_TRACE("Brownout Condition detected: Entering SOC_OFF");

    GLOBAL_INT_DISABLE();

    pmu_configure_brwnout();

#ifndef CONFIG_SOC_FAMILY_ATM
    rep_vec__ret_bool__int32_t__uint32_t__t *rv = rv_plf_hibernate;

    // When hibernate is true, there is already a call to
    // rep_vec__ret_bool__int32_t__uint32_t__invoke() on the stack walking
    // rv_plf_hibernate().  We need to finish that walk without re-running
    // any entries and prevent the default function from running at the end.
    // For retention (hibernate = false), we need to execute all the
    // hibernation vectors while skipping the user_init_check_brwnout_hibernate
    // and the default function.
    bool skip_already_called = hibernate;
    for (; rv; rv=rv->next) {
	if (rv->fn == user_init_check_brwnout_hibernate) {
	    skip_already_called = false;
	    continue;
	}
	if (skip_already_called) {
	    continue;
	}
	rep_vec_err_t err = rv->fn(sleep, duration, int_set);
	if (err == RV_DONE) {
	    break;
	}
    }
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
    if (!duration && !brwnout_4ssocoff) {
	duration = WAKE_DUR;
    }

    pseq_soc_off(duration);
#else
    atm_pseq_soc_off(CONFIG_BROWNOUT_WAKE_DURATION);
#endif

    GLOBAL_INT_RESTORE();

#ifndef CONFIG_SOC_FAMILY_ATM
    return (RV_DONE);
#endif
}

#ifndef CONFIG_SOC_FAMILY_ATM
__FAST static rep_vec_err_t
user_init_check_brwnout_retain_all(bool *sleep, int32_t duration, uint32_t int_set)
{
    return (user_init_check_brwnout(sleep, duration, int_set, false));
}

__FAST static rep_vec_err_t
user_init_check_brwnout_hibernate(bool *sleep, int32_t duration, uint32_t int_set)
{
    return (user_init_check_brwnout(sleep, duration, int_set, true));
}

__attribute__((constructor))
static void
brwnout_init(void)
{
    RV_PLF_RETAIN_ALL_ADD(user_init_check_brwnout_retain_all);
    RV_PLF_HIBERNATE_ADD(user_init_check_brwnout_hibernate);
}
#else
static int brwnout_driver_init(struct device const *dev)
{
    ARG_UNUSED(dev);

    pm_notifier_register(&brownout_pm_notifier);

    return 0;
}

DEVICE_DT_INST_DEFINE(0, brwnout_driver_init, NULL, NULL, NULL, POST_KERNEL,
		      CONFIG_KERNEL_INIT_PRIORITY_DEVICE, NULL);
#endif

void brwnout_force_socoff(void)
{
    brwnout_enable();
    brwnout_4ssocoff = true;
}

void brwnout_enable(void)
{
    if (brwnout_disabled) {
	brwnout_disabled = false;
#ifdef CONFIG_SOC_FAMILY_ATM
	pm_notifier_register(&brownout_pm_notifier);
#endif
    }
}

void brwnout_disable(void)
{
    if (!brwnout_disabled) {
	brwnout_disabled = true;
#ifdef CONFIG_SOC_FAMILY_ATM
	pm_notifier_unregister(&brownout_pm_notifier);
#endif
    }
}

bool brwnout_status(void)
{
    return no_energy4tx || brwnout_4ssocoff;
}
