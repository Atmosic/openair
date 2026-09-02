/**
 *******************************************************************************
 *
 * @file power.h
 *
 * @brief Power mode api
 *
 * Copyright (C) Atmosic 2024-2026
 *
 *******************************************************************************
 */

#pragma once

#include <zephyr/sys/iterable_sections.h>
#include "compiler.h"

/**
 * @defgroup POWER POWER
 * @ingroup DRIVERS
 * @brief Power mode interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_SYSTEM_CLOCK_SLOPPY_IDLE
#define IDLE_FOREVER K_TICKS_FOREVER
#else
#define IDLE_FOREVER INT_MAX
#endif

#define PM_SUBSTATE_HIBERNATE DT_PROP(DT_NODELABEL(hibernate), substate_id)
#define PM_SUBSTATE_SOC_OFF DT_PROP(DT_NODELABEL(soc_off), substate_id)

/**
 * @brief Which forced power-down method is being entered.
 *
 * Passed to prep hooks alongside the urgency so a hook can vary its behavior by
 * method. This will eventually let the rwip/ATLC forced sleep (which applies to
 * hibernate) migrate out of the power driver and into a prep hook.
 */
enum atm_pd_method {
    /** Hibernate (RAM retained). */
    ATM_PD_METHOD_HIBERNATE,
    /** SoC off (deepest; RAM not retained). */
    ATM_PD_METHOD_SOC_OFF,
};

/**
 * @brief Urgency of a forced power-down entry (hibernate or soc_off).
 *
 * Forced power-down bypasses Zephyr's readiness-gated PM entry, so peripherals
 * cannot rely on pm_notifier callbacks running. Instead they register a prep
 * hook (see ATM_PD_PREP_DEFINE) which is passed this urgency so it can decide
 * how much (if any) optional work to do before the device latches its pads.
 */
enum atm_pd_urgency {
    /** Time permits: drain/flush hardware before entry. */
    ATM_PD_URGENCY_GRACEFUL,
    /** Power is failing: enter ASAP, skip optional waits. */
    ATM_PD_URGENCY_URGENT,
};

#ifdef CONFIG_ATM_PD
/**
 * @brief A peripheral's "prepare for forced power-down" hook.
 *
 * Hooks run with interrupts disabled, in the order given by the priority
 * encoded in their ATM_PD_PREP_DEFINE name. They must be bounded and must not
 * block indefinitely.
 */
struct atm_pd_prep {
    void (*prep)(enum atm_pd_method method, enum atm_pd_urgency urgency);
};

/**
 * @brief Register a forced-power-down prep hook.
 *
 * @param _name Unique token identifying the hook (e.g. driver/instance name).
 * @param _prio Two-digit ordering priority; lower runs first (flash should be
 *              late so other peripherals quiesce before flash is armed off).
 * @param _fn   void (*)(enum atm_pd_method, enum atm_pd_urgency) hook function.
 */
#define ATM_PD_PREP_DEFINE(_name, _prio, _fn) \
    static const STRUCT_SECTION_ITERABLE(atm_pd_prep, \
	atm_pd_prep_##_prio##_##_name) = {.prep = (_fn)}

/**
 * @brief Run all registered forced-power-down prep hooks.
 *
 * Call this on a forced power-down path (hibernate or soc_off) before the PSEQ
 * latches the pads, while flash is still powered (hooks are read from the
 * ROM-resident registry).
 *
 * @param[in] method  Power-down method being entered (hibernate or soc_off).
 * @param[in] urgency Urgency of this power-down entry.
 */
static inline void atm_pd_prep_run(enum atm_pd_method method,
    enum atm_pd_urgency urgency)
{
    STRUCT_SECTION_FOREACH(atm_pd_prep, _hp)
    {
	_hp->prep(method, urgency);
    }
}
#endif /* CONFIG_ATM_PD */

#ifdef CONFIG_ATM_PD_POST
/**
 * @brief A peripheral's "final forced-power-down" hook.
 *
 * Post hooks run with interrupts disabled as the very last step of a forced
 * power-down: after the PSEQ is armed for hibernate/soc_off and after every
 * prep hook, immediately before flash is powered off and the core stops. Unlike
 * prep hooks they take no method/urgency and do no optional work -- they perform
 * only the bounded teardown that must happen last (e.g. the software flash
 * deep-power-down on SoCs without PSEQ flash-control hardware). The hook
 * functions must be __ramfunc, and the registry is not const (kept in RAM),
 * because a hook in this pass may power flash off before the run loop ends.
 */
struct atm_pd_post {
    void (*post)(void);
};

/**
 * @brief Register a final forced-power-down hook.
 *
 * @param _name Unique token identifying the hook (e.g. driver/instance name).
 * @param _prio Two-digit ordering priority; lower runs first (flash should be
 *              late so it is the last thing powered off).
 * @param _fn   void (*)(void) hook function (must be __ramfunc).
 */
#define ATM_PD_POST_DEFINE(_name, _prio, _fn) \
    static STRUCT_SECTION_ITERABLE(atm_pd_post, \
	atm_pd_post_##_prio##_##_name) = {.post = (_fn)}

/**
 * @brief Run all registered final forced-power-down hooks.
 *
 * Call this as the last step of a forced power-down path (hibernate or
 * soc_off), after the PSEQ is armed and after atm_pd_prep_run(), immediately
 * before flash is powered off. Hooks run from RAM and must not assume flash is
 * accessible.
 */
__STATIC_FORCEINLINE void atm_pd_post_run(void)
{
    STRUCT_SECTION_FOREACH(atm_pd_post, _hp)
    {
	_hp->post();
    }
}
#endif // CONFIG_ATM_PD_POST

#ifdef CONFIG_ATM_PD
/**
 * @brief Move the device to 'SOC off' state for specified duration
 * @param[in] lpc Duration in low-power cycles (32768 Hz); 0 for an
 *                indefinite stay
 * @param[in] urgency Urgency of this forced-power-down entry
 */
void atm_pseq_soc_off(uint32_t lpc, enum atm_pd_urgency urgency);

/**
 * @brief Move the device to 'Hibernate' state for specified duration
 * @param[in] lpc Duration in low-power cycles (32768 Hz); 0 for an
 *                indefinite stay
 * @param[in] urgency Urgency of this forced-power-down entry
 */
void atm_pseq_hibernate(uint32_t lpc, enum atm_pd_urgency urgency);
#endif // CONFIG_ATM_PD

/**
 * @brief Set GPIO wakeup from SOC off state
 *
 * Uses GPIO pin 5 which is the only supported GPIO wakeup pin.
 * The pin will be configured for high-level wakeup when enabled.
 *
 * @param enable true to enable GPIO wakeup, false to disable
 */
void atm_socoff_wakeup_gpio_set(bool enable);

/**
 * @brief PSEQ hibernation latch identifiers.
 */
enum atm_pseq_hib_latch {
    /** GPIO output latch. */
    ATM_PSEQ_HIB_LATCH_GPIO,
    /** Pin pull-up/pull-down latch. */
    ATM_PSEQ_HIB_LATCH_PINPU,
    /** Pin select latch. */
    ATM_PSEQ_HIB_LATCH_PINSEL,
    /** I2C pull-up latch. */
    ATM_PSEQ_HIB_LATCH_I2C,
    /** SPI latch. */
    ATM_PSEQ_HIB_LATCH_SPI,
    /** Key scan matrix latch. */
    ATM_PSEQ_HIB_LATCH_KSM,
    /** PWM latch. */
    ATM_PSEQ_HIB_LATCH_PWM,
    /** UART latch. */
    ATM_PSEQ_HIB_LATCH_UART,

    ATM_PSEQ_HIB_LATCH_COUNT,
};

/**
 * @brief Release a PSEQ pad latch held since hibernation entry.
 *
 * Optional API for applications that need to change pin state after
 * hibernation wake-up.  Call after restoring the desired pin
 * configuration.  Unsupported latches are silently ignored.
 *
 * @param[in] latch  Which latch group to release.
 */
void atm_power_pseq_release_latch(enum atm_pseq_hib_latch latch);

/**
 * @brief WuRx algorithm enable state global variables
 *
 * These global variables control the WuRx algorithm enable state that is used
 * by the power management system during hibernation and retention modes. The
 * power management system reads these states to configure wake-up sources when
 * entering low-power modes.
 *
 * wurx0_enabled: true to enable WuRx algorithm 0 for wake-up, false to disable
 * wurx1_enabled: true to enable WuRx algorithm 1 for wake-up, false to disable
 */
extern bool wurx0_enabled, wurx1_enabled;

#ifdef __cplusplus
}
#endif

/// @} POWER
