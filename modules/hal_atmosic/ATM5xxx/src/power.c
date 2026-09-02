/*
 * Copyright (c) 2021-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifdef CONFIG_POWER_OFF_SBRK
#define _GNU_SOURCE
#include <unistd.h>
#endif

#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/sys_clock.h>
#include <zephyr/linker/linker-defs.h>
#include <zephyr/devicetree.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(soc_power, CONFIG_SOC_LOG_LEVEL);

#include "arch.h"
#include "timer.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "pmu_top_regs_core_macro.h"
#include "spi.h"
#include "pmu_spi.h"
#include "at_clkrstgen.h"
#include "atm_bp_clock.h"
#include "sec_cache.h"
#include "sec_reset.h"
#ifdef SECURE_PROC_ENV
#include "sec_service.h"
#endif
#include "power.h"
#include "vectors.h"
#if defined(CONFIG_PM) && defined(CONFIG_PM_CUSTOM_TICKS_HOOK) && defined(CONFIG_ATM_ATLC)
#include "ble_driver.h"
#endif

#define PSEQ_INTERNAL_DIRECT_INCLUDE_GUARD
#include "pseq.ih"

/* Debugs - to enable, change undef to define */
#undef DEBUG_HIBERNATE
#undef DEBUG_WAKE_MASK

/* PMU node for SOC off wakeup configuration */
#define PMU_NODE DT_NODELABEL(pmu)

/* Runtime wakeup source enable/disable state */
static bool gpio_wakeup_enabled = false;
#if DT_NODE_HAS_PROP(PMU_NODE, soc_off_lpcomp_wakeup_pin)
#define DT_LPCOMP_WAKEUP_PIN  DT_PROP(PMU_NODE, soc_off_lpcomp_wakeup_pin)
#define DT_LPCOMP_REF_LEVEL   DT_PROP(PMU_NODE, soc_off_lpcomp_ref_level)
#endif
#ifndef CONFIG_ATM_NO_SPE
unsigned int secure_irq_lock(void);
void secure_irq_unlock(unsigned int key);
#endif

#if defined(CONFIG_PM) || defined(CONFIG_ATM_PD)
#include "hw_cfg.h"
#include "pmu.h"

BUILD_ASSERT(DT_PROP(DT_NODELABEL(systick), external_clock_source), "Fixed SysTick clock required");

#ifdef CONFIG_DETECT_PULSE_IN_RETENTION
#ifdef CONFIG_ZTEST
static bool gpio_pulse_detect_disabled;

void pseq_enable_gpio_pulse_detection(bool enable)
{
	gpio_pulse_detect_disabled = !enable;
}

#define SHOULD_DETECT_GPIO_PULSE() (!gpio_pulse_detect_disabled)
#else
#define SHOULD_DETECT_GPIO_PULSE() (true)
#endif
#endif /* CONFIG_DETECT_PULSE_IN_RETENTION */

#ifdef CONFIG_PM
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, retain))
__ramfunc static void atm_power_mode_retain(uint32_t lpc, uint32_t *int_set)
{
	uint32_t duration;
	if (lpc) {
		uint32_t latency =
			atm_us_to_lpc(DT_PROP_OR(DT_NODELABEL(retain), exit_latency_us, 0));
		/* Never bottom out at 0: that means an indefinite stay */
		duration = (lpc > latency) ? (lpc - latency) : 1;
#ifdef PSEQ_TEST_TORTURE_RETAIN
		if (duration > 0x100) {
			duration = 0x100;
		}
#endif
#if CONFIG_PM_MAX_SLEEP_DURATION_SEC
		/* Apply maximum duration cap if configured */
		uint64_t max_duration = atm_to_lpc(Z_HZ_sec, CONFIG_PM_MAX_SLEEP_DURATION_SEC);
		if (duration > max_duration) {
			duration = max_duration;
		}
#endif
	} else {
#if CONFIG_PM_MAX_SLEEP_DURATION_SEC
		duration = atm_to_lpc(Z_HZ_sec, CONFIG_PM_MAX_SLEEP_DURATION_SEC);
#else
		duration = 0;
#endif
	}

#ifdef CONFIG_POWER_OFF_SBRK
	uint32_t block_sysram = RAM_BANK2MASK(RAM_ADDR2BANK((uintptr_t)sbrk(0) - 1));
#else
	// Retain all RAM
	uint32_t block_sysram = ~0;
#endif

#define MAX_TIME_IN_RETAIN (UINT32_MAX / Z_HZ_cyc) * 32000
	duration = MIN(duration, MAX_TIME_IN_RETAIN);

#if defined(CONFIG_ATM_PMU_WDT_ENABLE) && CONFIG_PM_MAX_SLEEP_DURATION_SEC
	/* Set PMU warning timer relative to actual sleep duration */
	int64_t offset_lpcycles = atm_to_lpc(Z_HZ_sec, CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC);
	uint64_t pmu_wdog_duration = (int64_t)duration + offset_lpcycles;
	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_config_soc_off(pmu_wdog_duration);
	}
	WRPR_CTRL_POP();
	pmu_set_pmu_wdog_reset(true);
#endif
	pseq_core_config_retain(duration, block_sysram, IS_ENABLED(CONFIG_ATM_PMU_WDT_ENABLE));

#ifdef CONFIG_DETECT_PULSE_IN_RETENTION
	if (SHOULD_DETECT_GPIO_PULSE()) {
		pseq_core_gpio_data_snapshot();
	}
#endif
	pseq_core_enter_retain();
}
#endif // power_states/retain
#endif // CONFIG_PM

/*
 * SRAM bank retention during hibernation.
 *
 * SYSRAM_OVERRIDES7 (VDDCUT) and SYSRAM_OVERRIDES8 (SD) each carry a field
 * where bit N blocks power-off of the N-th 16 KB bank (bank 0 is the start of
 * the SRAM aperture). The optional "atmosic,hib-saved-sram" chosen entry
 * selects the SRAM sub-region whose banks must survive hibernation so
 * application state in __noinit persists without an OTP reload on wake.
 * CONFIG_ATM_HIB_SAVED_SRAM_BASE_ADDRESS / _SIZE are derived from that chosen
 * node (0 when it is absent, leaving the mask empty). Partial trailing banks
 * are rounded up.
 *
 * RAM_ADDR2BANK()/RAM_BANK2MASK() (from pseq.ih) key off CMSDK_SRAM_BASE, the
 * alias-correct physical bank-0 base, so the mask tracks the chosen window
 * across Secure/Non-Secure memory configurations.
 */
#if (CONFIG_ATM_HIB_SAVED_SRAM_SIZE > 0)
#define ATM_HIB_FIRST_BANK RAM_ADDR2BANK(CONFIG_ATM_HIB_SAVED_SRAM_BASE_ADDRESS)
#define ATM_HIB_LAST_BANK                                                                          \
	RAM_ADDR2BANK(CONFIG_ATM_HIB_SAVED_SRAM_BASE_ADDRESS + CONFIG_ATM_HIB_SAVED_SRAM_SIZE - 1U)
#define ATM_HIB_SRAM_MASK (RAM_BANK2MASK(ATM_HIB_LAST_BANK) & ~((1U << ATM_HIB_FIRST_BANK) - 1U))
BUILD_ASSERT(ATM_HIB_LAST_BANK < PSEQ_SYSRAM_OVERRIDES7__BLOCK_SYSRAM_VDDCUT__WIDTH,
	     "ATM5: atmosic,hib-saved-sram window exceeds the bank count of the "
	     "PSEQ SYSRAM_OVERRIDES7/8 fields — check the chosen region's reg.");
#else
#define ATM_HIB_SRAM_MASK 0U
#endif

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, hibernate))
static void atm_power_mode_hibernate(uint32_t lpc, uint32_t *int_set)
{
	uint32_t duration;
	if (lpc) {
		uint32_t latency =
			atm_us_to_lpc(DT_PROP_OR(DT_NODELABEL(hibernate), exit_latency_us, 0));
		/* Never bottom out at 0: that means an indefinite stay */
		duration = (lpc > latency) ? (lpc - latency) : 1;

#if CONFIG_PM_MAX_SLEEP_DURATION_SEC
		/* Apply maximum duration cap if configured */
		uint64_t max_duration = atm_to_lpc(Z_HZ_sec, CONFIG_PM_MAX_SLEEP_DURATION_SEC);
		if (duration > max_duration) {
			duration = max_duration;
		}
#endif
	} else {
#if CONFIG_PM_MAX_SLEEP_DURATION_SEC
		duration = atm_to_lpc(Z_HZ_sec, CONFIG_PM_MAX_SLEEP_DURATION_SEC);
#else
		duration = 0;
#endif
	}

#if defined(CONFIG_ATM_PMU_WDT_ENABLE) && CONFIG_PM_MAX_SLEEP_DURATION_SEC
	/* Set PMU warning timer relative to actual sleep duration */
	int64_t offset_lpcycles = atm_to_lpc(Z_HZ_sec, CONFIG_ATM_WDT_PMU_WARN_OFFSET_SEC);
	uint64_t pmu_wdog_duration = (int64_t)duration + offset_lpcycles;
	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_config_soc_off(pmu_wdog_duration);
	}
	WRPR_CTRL_POP();
	pmu_set_pmu_wdog_reset(true);
#endif
	__UNUSED uint32_t wake_mask = pseq_core_config_hibernate(
		duration, ATM_HIB_SRAM_MASK, IS_ENABLED(CONFIG_ATM_PMU_WDT_ENABLE));

#ifdef DEBUG_HIBERNATE
	printk("Hibernate duration %" PRId32 ", ise 0x%08" PRIx32 "_%08" PRIx32 "_%08" PRIx32
	       "_%08" PRIx32 "\n",
	       duration, int_set[3], int_set[2], int_set[1], int_set[0]);
#ifdef DEBUG_WAKE_MASK
	printk("HWM %#" PRIx32 ", GPWM %#" PRIx32 ", GPWP %#" PRIx32 ", GPWBE %#" PRIx32
	       ", OV %#" PRIx32 ", OV5 %#" PRIx32 "\n",
	       wake_mask, CMSDK_PSEQ->GPIO_WAKE_MASK, CMSDK_PSEQ->GPIO_WAKE_POL,
	       CMSDK_PSEQ->GPIO_WAKE_BOTH_EDGES, CMSDK_PSEQ->OVERRIDES, CMSDK_PSEQ->OVERRIDES5);
#endif // DEBUG_WAKE_MASK
#endif // DEBUG_HIBERNATE

	pseq_core_enter_hibernation();
}
#endif // power_states/hibernate

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, soc_off))
static void atm_power_mode_soc_off(uint32_t lpc, uint32_t *int_set)
{
	uint64_t duration;

	if (lpc) {
		uint32_t latency =
			atm_us_to_lpc(DT_PROP_OR(DT_NODELABEL(soc_off), exit_latency_us, 0));
		/* Never bottom out at 0: that means an indefinite stay */
		duration = (lpc > latency) ? (lpc - latency) : 1;

#if CONFIG_PM_MAX_SLEEP_DURATION_SEC
		/* Apply maximum duration cap if configured */
		uint64_t max_duration = atm_to_lpc(Z_HZ_sec, CONFIG_PM_MAX_SLEEP_DURATION_SEC);
		if (duration > max_duration) {
			duration = max_duration;
		}
#endif
	} else {
#if CONFIG_PM_MAX_SLEEP_DURATION_SEC
		duration = atm_to_lpc(Z_HZ_sec, CONFIG_PM_MAX_SLEEP_DURATION_SEC);
#else
		duration = 0;
#endif
	}

	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_config_soc_off(duration);
	}
	WRPR_CTRL_POP();

	/* Configure additional wakeup sources based on runtime enable state */
	if (gpio_wakeup_enabled) {
		pmu_socoff_wakeup_gpio(true);
	}

#if DT_NODE_HAS_PROP(PMU_NODE, soc_off_lpcomp_wakeup_pin)
	pmu_socoff_wakeup_lpcomp(true, DT_LPCOMP_WAKEUP_PIN, DT_LPCOMP_REF_LEVEL);
#endif

#if defined(CONFIG_ATM_PMU_WDT_ENABLE) && CONFIG_PM_MAX_SLEEP_DURATION_SEC
	pmu_set_pmu_wdog_reset(true);
#endif

#ifdef DEBUG_HIBERNATE
	printk("soc_off duration %llu\n", duration);
#endif /* DEBUG_HIBERNATE */

	pseq_core_enter_soc_off();
}
#endif // power_states/soc_off

#define PSEQ_USE_FSM
#define BP_SLEEP_FREQ	1000000U

#define FSM_TARGET_FREQ_XTAL	0
#define FSM_TARGET_FREQ_DOUBLER	1
#define FSM_TARGET_FREQ_PLL	2

#ifdef CONFIG_PM
static void pseq_bp_throttle(uint32_t bp_freq, uint32_t *min_freq)
{
#ifdef PSEQ_TEST_MIN_FREQ
	if (*min_freq < PSEQ_TEST_MIN_FREQ) {
		*min_freq = PSEQ_TEST_MIN_FREQ;
	}
#endif
}
#endif // CONFIG_PM

__ramfunc static uint32_t pseq_get_system_freq(void)
{
	return at_clkrstgen_get_bp();
}

#ifdef CONFIG_PM
static uint32_t pseq_scale_back_bp(uint32_t min_freq, uint32_t *slow_freq)
{
	uint32_t bp_freq = pseq_get_system_freq();
	rep_vec__uint32_t__uint32_t_p__invoke(rv_plf_bp_throttle, pseq_bp_throttle, bp_freq,
					      &min_freq);
	if (bp_freq > min_freq) {
		*slow_freq = min_freq;
	} else {
		*slow_freq = bp_freq;
	}
	return bp_freq;
}
#endif // CONFIG_PM

/*
 * Locate in RAM - avoid using flash
 */
__ramfunc static void pseq_at_clkrstgen_set_bp_hint(uint32_t freq, bool set, bool commit)
{
#ifdef PSEQ_USE_FSM
	while (CLKRSTGEN_FSM_STATUS__STATE__READ(CMSDK_CLKRSTGEN_NONSECURE->FSM_STATUS)) {
		CLKRSTGEN_FSM_CTRL__ABORT_FSM__SET(CMSDK_CLKRSTGEN_NONSECURE->FSM_CTRL);
		YIELD();
	}
#endif

	atm_bp_clock_set_hint(freq, set, commit);
}

/*
 * Get off PLL/doubler before xtal is powered down
 */
__ramfunc static void pseq_prep_for_xtal_pd(void)
{
	at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);
	CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__CLR(CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC);
#ifdef REAL_DOUBLER
	CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__CLR(CMSDK_CLKRSTGEN_NONSECURE->XTAL_BITS1);
#endif
	CLKRSTGEN_CLKSYNC__CLK16_SRC__CLR(CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC);
	CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL = 0;
}

#ifdef PSEQ_USE_FSM
__STATIC_FORCEINLINE void pseq_reset_fsm(void)
{
	// Wait for FSM in case WFI was super short
	for (uint32_t idle = 0;;) {
	       if (CLKRSTGEN_FSM_STATUS__STATE__READ(CMSDK_CLKRSTGEN_NONSECURE->FSM_STATUS)) {
		       idle = 0;
		       YIELD();
		       continue;
	       }

	       if (idle) {
		       break;
	       }
	       idle++;
	}

	CMSDK_CLKRSTGEN_NONSECURE->FSM_CTRL = CLKRSTGEN_FSM_CTRL__RESET_VALUE;
}
#endif

#ifdef CONFIG_PM
/*
 * Locate in RAM - avoid using flash
 */
__ramfunc static void pseq_slow_wfi(uint32_t bp_freq, uint32_t slow_freq)
{
	if (bp_freq == slow_freq) {
		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();
		return;
	}

	if (slow_freq > ATM_BP_XTAL_FREQ) {
		// No need to mess with CLKRSTGEN_FSM - just do it
		pseq_at_clkrstgen_set_bp_hint(slow_freq, true, true);

		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();

		pseq_at_clkrstgen_set_bp_hint(bp_freq, true, true);
		return;
	}

#ifdef PSEQ_USE_FSM
	// Use CLKRSTGEN_FSM to quickly drop/raise BP around WFI
	// FSM slow in, FSM PLL out
	CMSDK_CLKRSTGEN_NONSECURE->FSM_CTRL =
		CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__MASK |
		CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__MASK |
		CLKRSTGEN_FSM_CTRL__WAIT4XTAL__MASK |
		CLKRSTGEN_FSM_CTRL__TARGET_FREQ__WRITE(FSM_TARGET_FREQ_PLL);

	// Set SLOW_CLUSTER_SEL for CLKRSTGEN_FSM.  Also works for ATM_BP_XTAL_FREQ.
	pseq_at_clkrstgen_set_bp_hint(slow_freq, true, false);

	__set_BASEPRI(0);
	__ISB();
	__DSB();
	__WFI();

	pseq_reset_fsm();
#else
	if (slow_freq < ATM_BP_XTAL_FREQ) {
		// Unrolled to minimize instructions run at CLUSTER_SEL__SLOW

		pseq_at_clkrstgen_set_bp_hint(slow_freq, true, false);
		uint32_t slow_cluster = CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL &
					CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__MASK;

		// To prevent multiple bit transitions, take everything back to zero
		at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);

		CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL =
			slow_cluster | CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(CLUSTER_SEL__SLOW);
		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();
		CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL = slow_cluster;
		pseq_at_clkrstgen_set_bp_hint(bp_freq, false, true);
	} else {
		// slow_freq is fast enough - just go for it
		pseq_at_clkrstgen_set_bp_hint(slow_freq, true, true);
		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();
		pseq_at_clkrstgen_set_bp_hint(bp_freq, true, true);
	}
#endif
}

/*
 * Locate in RAM - avoid using flash
 */
__ramfunc static void atm_power_wfi(void)
{
	__set_BASEPRI(0);
	__ISB();
	__DSB();
	__WFI();
}
#endif // CONFIG_PM

__ramfunc static bool atm_power_pseq_setup(void (*mode)(uint32_t lpc, uint32_t *int_set),
					   uint32_t lpc)
{
	uint32_t int_set[INT_REG_NUM];

	// Make certain that no interrupt will disturb sleep
	for (int i = 0; i < INT_REG_NUM; i++) {
		NVIC->ICER[i] = int_set[i] = NVIC->ISER[i];
	}
#ifndef CONFIG_ATM_NO_SPE
	unsigned int sec_key = secure_irq_lock();
#endif

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		mode(lpc, int_set);
	}
	WRPR_CTRL_POP();

	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

	static uint32_t bp_freq;
	bp_freq = pseq_get_system_freq();

#ifndef PSEQ_RETAIN_ICACHE
	ICACHE_DISABLE();
#endif

	pseq_prep_for_xtal_pd();

	/*
	 * Hibernate and soc_off will die inside WFI and
	 * reset after wakeup (CPU or entire chip, respectively)
	 */
	__DSB();
	__WFI();
	/* Retain will continue here after wakeup */

	// Retention powered down ROMC

	pseq_at_clkrstgen_set_bp_hint(bp_freq, true, true);

#ifndef PSEQ_RETAIN_ICACHE
	ICACHE_ENABLE();
#endif

	SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

	bool pseq_abort;
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_back_from_retain();
		pseq_core_back_from_retain_final();

		pseq_abort = PSEQ_INTERRUPT_STATUS__LP_ABORT__READ(CMSDK_PSEQ->INTERRUPT_STATUS);

#ifdef CONFIG_DETECT_PULSE_IN_RETENTION
		if (!pseq_abort && SHOULD_DETECT_GPIO_PULSE() && !pseq_core_gpio_pulse_restore()) {
			ASSERT_ERR(0);
		}
#endif
	}
	WRPR_CTRL_POP();

	// Restore interrupt set enables
#ifndef CONFIG_ATM_NO_SPE
	secure_irq_unlock(sec_key);
#endif
	for (int i = 0; i < INT_REG_NUM; i++) {
		NVIC->ISER[i] = int_set[i];
	}
	irq_unlock(0);

	return !pseq_abort;
}

#ifdef CONFIG_PM
__ramfunc static bool atm_power_pseq_control(void (*mode)(uint32_t lpc, uint32_t *int_set))
{
	uint32_t idle = _kernel.idle;
	/* Convert Zephyr idle ticks to lpcycles; IDLE_FOREVER maps to 0 (indefinite) */
	uint32_t lpc = (idle == IDLE_FOREVER) ? 0 : atm_to_lpc(Z_HZ_ticks, idle);
	return atm_power_pseq_setup(mode, lpc);
}

#ifdef CONFIG_PM_CUSTOM_TICKS_HOOK
int64_t pm_policy_next_custom_ticks(void)
{
#ifdef CONFIG_ATM_ATLC
	return atm_ble_sleep_remaining_ticks();
#else
	return K_TICKS_FOREVER;
#endif
}
#endif /* CONFIG_PM_CUSTOM_TICKS_HOOK */

/**
 * @brief Prevent reentering retention/hibernation after a wakeup
 * triggered by a SWD debugger.
 */
static void atm_power_swd_dbg_lock(void)
{
	static bool swd_dbg_locked;

	if (swd_dbg_locked) {
		return;
	}

	swd_dbg_locked = true;
	pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
	pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
}

/* Invoke Low Power/System Off specific Tasks */
__ramfunc void pm_state_set(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_RUNTIME_IDLE:
		__disable_irq();
		atm_power_wfi();
		break;
	case PM_STATE_SUSPEND_TO_IDLE:
		__disable_irq();
		SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
		uint32_t slow_freq = 0;
		uint32_t bp_freq = pseq_scale_back_bp(BP_SLEEP_FREQ, &slow_freq);
		pseq_slow_wfi(bp_freq, slow_freq);
		SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
		break;
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, retain))
	case PM_STATE_SUSPEND_TO_RAM: {
		__disable_irq();
		extern void sys_clock_correct(uint32_t cycles);

		uint32_t start = atm_sync_get_sys_time();
		uint32_t systick_ctrl = SysTick->CTRL;
		SysTick->CTRL = systick_ctrl & ~SysTick_CTRL_ENABLE_Msk;

		bool retain_good = atm_power_pseq_control(atm_power_mode_retain);

		uint32_t elapsed = atm_sync_get_sys_time() - start;
		SysTick->CTRL = systick_ctrl;
		/* Convert lpcycles to hardware cycles */
		sys_clock_correct(atm_lpc_to(Z_HZ_cyc, elapsed));

#ifdef CONFIG_ATM_PMU_WDT_ENABLE
		pmu_set_pmu_wdog_reset(false);

		// Check and process any wakeup due to PMU interrupt
		PMU_Handler();
#endif

		WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
		{
			if (PSEQ_STATUS__DBG_TRIGGERED__READ(CMSDK_PSEQ->STATUS)) {
				atm_power_swd_dbg_lock();
			}
		}
		WRPR_CTRL_POP();

		if (!retain_good) {
			LOG_ERR("SUSPEND_TO_RAM failed!");
		}
		break;
	}
#endif // power_states/retain
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, hibernate)) ||                                   \
	DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, soc_off))
	case PM_STATE_SOFT_OFF:
		__disable_irq();
		if (!substate_id) {
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, hibernate))
			atm_power_pseq_control(atm_power_mode_hibernate);
#endif
		} else {
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, soc_off))
			atm_power_pseq_control(atm_power_mode_soc_off);
#endif
		}
		LOG_ERR("SOFT_OFF failed!");
		break;
#endif // power_states/hibernate || power_states/soc_off
	default:
		LOG_DBG("Unsupported power state %u", state);
		break;
	}
}

/* Handle SOC specific activity after Low Power Mode Exit */
void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_RUNTIME_IDLE:
	case PM_STATE_SUSPEND_TO_IDLE:
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, retain))
	case PM_STATE_SUSPEND_TO_RAM:
#endif
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, hibernate)) ||                                   \
	DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, soc_off))
	case PM_STATE_SOFT_OFF:
#endif
		__enable_irq();
		break;
	default:
		LOG_DBG("Unsupported power state %u", state);
		irq_unlock(0);
		break;
	}
}
#endif // CONFIG_PM

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, soc_off))
void atm_pseq_soc_off(uint32_t lpc, enum atm_pd_urgency urgency)
{
	__disable_irq();

	atm_pd_prep_run(ATM_PD_METHOD_SOC_OFF, urgency);

	atm_power_pseq_setup(atm_power_mode_soc_off, lpc);
}
#endif // power_states/soc_off

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, hibernate))
void atm_pseq_hibernate(uint32_t lpc, enum atm_pd_urgency urgency)
{
	__disable_irq();

	atm_pd_prep_run(ATM_PD_METHOD_HIBERNATE, urgency);

	atm_power_pseq_setup(atm_power_mode_hibernate, lpc);
}
#endif // power_states/hibernate
#endif /* CONFIG_PM || CONFIG_ATM_PD */

#ifdef SECURE_PROC_ENV
__SPE_NSC
unsigned int secure_irq_lock(void)
{
	return irq_lock();
}

__SPE_NSC
void secure_irq_unlock(unsigned int key)
{
	irq_unlock(key);
}
#endif

void atm_socoff_wakeup_gpio_set(bool enable)
{
	gpio_wakeup_enabled = enable;
}

void atm_power_pseq_release_latch(enum atm_pseq_hib_latch latch)
{
	uint32_t ctrl0_mask;

	switch (latch) {
#ifdef PSEQ_CTRL0__GPIO_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_GPIO:
		ctrl0_mask = PSEQ_CTRL0__GPIO_LATCH_OPEN__MASK;
		break;
#endif
#ifdef PSEQ_CTRL0__PINPU_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_PINPU:
		ctrl0_mask = PSEQ_CTRL0__PINPU_LATCH_OPEN__MASK;
		break;
#endif
#ifdef PSEQ_CTRL0__PINSEL_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_PINSEL:
		ctrl0_mask = PSEQ_CTRL0__PINSEL_LATCH_OPEN__MASK;
		break;
#endif
#ifdef PSEQ_CTRL0__I2C_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_I2C:
		ctrl0_mask = PSEQ_CTRL0__I2C_LATCH_OPEN__MASK;
		break;
#endif
#ifdef PSEQ_CTRL0__SPI_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_SPI:
		ctrl0_mask = PSEQ_CTRL0__SPI_LATCH_OPEN__MASK;
		break;
#endif
#ifdef PSEQ_CTRL0__KSM_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_KSM:
		ctrl0_mask = PSEQ_CTRL0__KSM_LATCH_OPEN__MASK;
		break;
#endif
#ifdef PSEQ_CTRL0__PWM_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_PWM:
		ctrl0_mask = PSEQ_CTRL0__PWM_LATCH_OPEN__MASK;
		break;
#endif
#ifdef PSEQ_CTRL0__UART_LATCH_OPEN__MASK
	case ATM_PSEQ_HIB_LATCH_UART:
		ctrl0_mask = PSEQ_CTRL0__UART_LATCH_OPEN__MASK;
		break;
#endif
	default:
		return;
	}

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		CMSDK_PSEQ->CTRL0 &= ~ctrl0_mask;
	}
	WRPR_CTRL_POP();
}

static int atm_power_init(void)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_power_all_sysram();
		pseq_core_xtal_init();

#ifdef CONFIG_PM
		uint32_t status = pseq_core_init();
		printk("PSEQ STATUS=%#" PRIx32 "\n", status);
		if (PSEQ_STATUS__DBG_TRIGGERED__READ(status)) {
			atm_power_swd_dbg_lock();
		}
#endif /* CONFIG_PM */

#ifndef CONFIG_MCUBOOT
		uint32_t reset_syndrome = secure_rclr_reset_syndrome();
		printk("RESET_SYNDROME=%#" PRIx32 "\n", reset_syndrome);

		if (reset_syndrome & ~SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Msk) {
			pseq_core_reset_radio_controller();
		}
#endif /* CONFIG_MCUBOOT */
	}
	WRPR_CTRL_POP();

#ifdef CONFIG_PM
	// IRQ_PRI_RT will break through irq_lock() to wake WFI in atm_power_pseq_control()
	NVIC_SetPriority(PSEQ_IRQn, IRQ_PRI_RT);

	// Don't let system reboot itself right away - application can decide later
	pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
	return 0;
}

SYS_INIT(atm_power_init, PRE_KERNEL_2, 0);
