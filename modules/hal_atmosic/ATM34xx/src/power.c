/*
 * Copyright (c) 2021-2025 Atmosic
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
#include "at_clkrstgen.h"
#include "atm_bp_clock.h"
#include "rram.h"
#include "sec_cache.h"
#include "sec_reset.h"
#ifdef SECURE_PROC_ENV
#include "sec_service.h"
#endif
#include "power.h"
#ifdef CONFIG_ATM_ATLC
#include "at_lc_regs_core_macro.h"
#endif

#define PSEQ_INTERNAL_DIRECT_INCLUDE_GUARD
#include "pseq_internal.h"

/* WURX support */
bool wurx0_enabled, wurx1_enabled;

/* Debugs - to enable, change undef to define */
#undef DEBUG_HIBERNATE
#undef DEBUG_WAKE_MASK

#define XTAL_FORCE \
	(PSEQ_OVERRIDES__FORCE_PRECISION_VAL__MASK | PSEQ_OVERRIDES__FORCE_PRECISION_REQ__MASK)

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

#ifdef CONFIG_PM
#include "hw_cfg.h"
#include "pmu.h"

#ifdef CONFIG_SYSTEM_CLOCK_SLOPPY_IDLE
#define IDLE_FOREVER K_TICKS_FOREVER
#else
#define IDLE_FOREVER INT_MAX
#endif

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

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, retain))
static void atm_power_mode_retain(uint32_t idle, uint32_t *int_set)
{
	uint32_t duration;
	if (idle != IDLE_FOREVER) {
		idle -= k_us_to_ticks_ceil32(DT_PROP_OR(DT_NODELABEL(retain), exit_latency_us, 0));
		/* Convert ticks to lpcycles */
		duration = atm_to_lpc(Z_HZ_ticks, idle);
#ifdef PSEQ_TEST_TORTURE_RETAIN
		if (duration > 0x100) {
			duration = 0x100;
		}
#endif
	} else {
		duration = 0;
	}

#ifdef CONFIG_POWER_OFF_SBRK
	uint32_t block_sysram = RAM_BANK2MASK(RAM_ADDR2BANK((uintptr_t)sbrk(0) - 1));
#else
	// Retain all RAM
	uint32_t block_sysram = ~0;
#endif

#define MAX_TIME_IN_RETAIN (UINT32_MAX / Z_HZ_cyc) * 32000
	duration = MIN(duration, MAX_TIME_IN_RETAIN);

	pseq_core_config_retain(duration, block_sysram, wurx0_enabled, wurx1_enabled);

#ifdef CONFIG_DETECT_PULSE_IN_RETENTION
	if (SHOULD_DETECT_GPIO_PULSE()) {
		pseq_core_gpio_data_snapshot();
	}
#endif
	pseq_core_enter_retain(wurx0_enabled, wurx1_enabled);
}
#endif // power_states/retain

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, hibernate))
static void atm_power_mode_hibernate(uint32_t idle, uint32_t *int_set)
{
	uint32_t duration;
	if (idle != IDLE_FOREVER) {
		idle -= k_us_to_ticks_ceil32(DT_PROP_OR(DT_NODELABEL(hibernate), exit_latency_us,
							0));
		/* Convert ticks to lpcycles */
		duration = atm_to_lpc(Z_HZ_ticks, idle);

	} else {
		duration = 0;
	}

	__UNUSED uint32_t wake_mask =
		pseq_core_config_hibernate(duration, wurx0_enabled, wurx1_enabled);

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

	pseq_core_enter_hibernation(wurx0_enabled, wurx1_enabled);
}
#endif // power_states/hibernate

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, soc_off))
static void atm_power_mode_soc_off(uint32_t idle, uint32_t *int_set)
{
	uint64_t duration;

	if (idle != IDLE_FOREVER) {
		idle -= k_us_to_ticks_ceil32(DT_PROP_OR(DT_NODELABEL(soc_off), exit_latency_us, 0));
		/* Convert ticks to lpcycles */
		duration = atm_to_lpc(Z_HZ_ticks, idle);
#if CONFIG_ATM_SOCOFF_MAX_DURATION_SEC
		/* Apply maximum duration cap if configured */
		uint64_t max_duration = atm_to_lpc(Z_HZ_sec, CONFIG_ATM_SOCOFF_MAX_DURATION_SEC);
		if (duration > max_duration) {
			duration = max_duration;
		}
#endif
	} else {
#if CONFIG_ATM_SOCOFF_MAX_DURATION_SEC
		duration = atm_to_lpc(Z_HZ_sec, CONFIG_ATM_SOCOFF_MAX_DURATION_SEC);
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

	pmu_set_pmu_wdog_reset(true);
#ifdef DEBUG_HIBERNATE
	printk("soc_off duration %llu\n", duration);
#endif /* DEBUG_HIBERNATE */

	pseq_core_enter_soc_off();
}
#endif // power_states/soc_off

#ifdef CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
#define PSEQ_USE_FSM
#define BP_SLEEP_FREQ   2000000U
#define BP_DOUBLER_FREQ 32000000U

static void pseq_bp_throttle(uint32_t bp_freq, uint32_t *min_freq)
{
#ifdef PSEQ_TEST_MIN_FREQ
	if (*min_freq < PSEQ_TEST_MIN_FREQ) {
		*min_freq = PSEQ_TEST_MIN_FREQ;
	}
#endif
}

#ifdef PSEQ_USE_FSM
static uint32_t pseq_pending_fsm_bp_freq;
#endif

static uint32_t pseq_get_system_freq(void)
{
#ifdef PSEQ_USE_FSM
	if (pseq_pending_fsm_bp_freq) {
		return pseq_pending_fsm_bp_freq;
	}
#endif

	return atm_bp_clock_get();
}

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

/*
 * Locate in RAM - avoid waking RRAM from nap or shutdown
 */
__ramfunc static void pseq_at_clkrstgen_set_bp_hint(uint32_t freq, bool set, bool commit)
{
#ifdef PSEQ_USE_FSM
	while (CLKRSTGEN_FSM_STATUS__STATE__READ(CMSDK_CLKRSTGEN_NONSECURE->FSM_STATUS)) {
		CLKRSTGEN_FSM_CTRL__ABORT_FSM__MODIFY(CMSDK_CLKRSTGEN_NONSECURE->FSM_CTRL, 1);
		YIELD();
	}
	pseq_pending_fsm_bp_freq = 0;
#endif

	atm_bp_clock_set_hint(freq, set, commit);
}

/*
 * Get off PLL/doubler before xtal is powered down
 */
static void pseq_prep_for_xtal_pd(void)
{
	pseq_at_clkrstgen_set_bp_hint(ATM_BP_XTAL_FREQ, true, true);
	CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__CLR(CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC);
	CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__CLR(CMSDK_CLKRSTGEN_NONSECURE->XTAL_BITS1);
	CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL = 0;
}

__STATIC_FORCEINLINE void pseq_set_pll_when_ready(uint32_t bp_freq, bool fsm_used)
{
#ifdef PSEQ_USE_FSM
	if (fsm_used && (bp_freq == BP_DOUBLER_FREQ)) {
		pseq_pending_fsm_bp_freq = BP_DOUBLER_FREQ;
		return;
	}
#endif

	if (bp_freq <= BP_DOUBLER_FREQ) {
		return;
	}

	pseq_at_clkrstgen_set_bp_hint(bp_freq, true, true);
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

/*
 * Locate in RAM - avoid waking RRAM from nap or shutdown
 */
__ramfunc static void pseq_slow_wfi(uint32_t bp_freq, uint32_t slow_freq, bool radio_pd)
{
	if (bp_freq == slow_freq) {
		// Can't have doubler or pll running across xtal power transition
		ASSERT_INFO((!radio_pd) || (slow_freq <= ATM_BP_XTAL_FREQ) ||
			    ((CMSDK_PSEQ->OVERRIDES & XTAL_FORCE) == XTAL_FORCE), bp_freq,
			    slow_freq);
		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();
		return;
	}

	if (slow_freq > ATM_BP_XTAL_FREQ) {
		// Can't have doubler or pll running across xtal power transition
		ASSERT_INFO((!radio_pd) || ((CMSDK_PSEQ->OVERRIDES & XTAL_FORCE) == XTAL_FORCE),
			    bp_freq, slow_freq);
		// No need to mess with CLKRSTGEN_FSM - just do it
		pseq_at_clkrstgen_set_bp_hint(slow_freq, true, true);

		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();

		pseq_set_pll_when_ready(bp_freq, false);
		return;
	}

#ifdef PSEQ_USE_FSM
	// Use CLKRSTGEN_FSM to quickly drop/raise BP around WFI
	if (bp_freq > ATM_BP_XTAL_FREQ) {
		// FSM slow in, FSM doubler out
		CMSDK_CLKRSTGEN_NONSECURE->FSM_CTRL =
			(radio_pd ? (CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__MASK |
			CLKRSTGEN_FSM_CTRL__TURNOFF_DOUBLER__MASK) : 0) |
			CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__MASK |
			CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__MASK |
			CLKRSTGEN_FSM_CTRL__WAIT4XTAL__MASK |
			CLKRSTGEN_FSM_CTRL__TARGET_FREQ__MASK;

		if (bp_freq > BP_DOUBLER_FREQ) {
			// Get off PLL before CLKRSTGEN_FSM triggers
			pseq_at_clkrstgen_set_bp_hint(BP_DOUBLER_FREQ, true, true);
		}
	} else {
		ASSERT_ERR(bp_freq == ATM_BP_XTAL_FREQ);

		// FSM slow in, FSM xtal out
		CMSDK_CLKRSTGEN_NONSECURE->FSM_CTRL =
			CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP__MASK |
			CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__MASK;
	}

	// Set SLOW_CLUSTER_SEL for CLKRSTGEN_FSM.  Also works for ATM_BP_XTAL_FREQ.
	pseq_at_clkrstgen_set_bp_hint(slow_freq, true, false);

	__set_BASEPRI(0);
	__ISB();
	__DSB();
	__WFI();

	pseq_set_pll_when_ready(bp_freq, true);
	pseq_reset_fsm();
#else
	if (slow_freq < ATM_BP_XTAL_FREQ) {
		// Unrolled to minimize instructions run at CLUSTER_SEL__SLOW

		pseq_at_clkrstgen_set_bp_hint(slow_freq, true, false);
		uint32_t slow_cluster = CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL &
					CLKRSTGEN_CLK_BP_CTRL__SLOW_CLUSTER_SEL__MASK;

		// To prevent multiple bit transitions, take everything back to zero
		at_clkrstgen_set_clk16x(CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL_STAT);
		if (radio_pd) {
			CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__CLR(CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC);
			CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__CLR(CMSDK_CLKRSTGEN_NONSECURE->XTAL_BITS1);
		}

		CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL =
			slow_cluster | CLKRSTGEN_CLK_BP_CTRL__CLUSTER_SEL__WRITE(CLUSTER_SEL__SLOW);
		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();
		CMSDK_CLKRSTGEN_NONSECURE->CLK_BP_CTRL = slow_cluster;
	} else {
		// slow_freq is fast enough - just go for it
		pseq_at_clkrstgen_set_bp_hint(slow_freq, true, true);
		if (radio_pd) {
			CLKRSTGEN_CLKSYNC__CLK16_SRC_INNER__CLR(CMSDK_CLKRSTGEN_NONSECURE->CLKSYNC);
			CLKRSTGEN_XTAL_BITS1__CLKHPC_EN__CLR(CMSDK_CLKRSTGEN_NONSECURE->XTAL_BITS1);
		}
		__set_BASEPRI(0);
		__ISB();
		__DSB();
		__WFI();
	}

	if (bp_freq <= BP_DOUBLER_FREQ) {
		pseq_at_clkrstgen_set_bp_hint(bp_freq, true, true);
	} else {
		pseq_set_pll_when_ready(bp_freq, false);
	}
#endif
}

/*
 * Locate in RAM - avoid waking RRAM from nap
 */
__ramfunc static void pseq_rram_nap_slow_wfi(uint32_t bp_freq, uint32_t slow_freq, bool radio_pd)
{
	pseq_core_rram_nap();
	pseq_slow_wfi(bp_freq, slow_freq, radio_pd);

	if (ROM_VER_A0 == rom_version) {
		WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
		{
			CMSDK_PSEQ->OVERRIDES3 = 0;
		}
		WRPR_CTRL_POP();
	}
}
#endif // CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF

/*
 * Locate in RAM - avoid waking RRAM from nap
 */
__ramfunc static void atm_power_rram_nap_wfi(void)
{
	pseq_core_rram_nap();

	__set_BASEPRI(0);
	__ISB();
	__DSB();
	__WFI();

	if (ROM_VER_A0 == rom_version) {
		WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
		{
			CMSDK_PSEQ->OVERRIDES3 = 0;
		}
		WRPR_CTRL_POP();
	}
}

static void atm_power_pseq_setup(void (*mode)(uint32_t idle, uint32_t *int_set), uint32_t idle)
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
		mode(idle, int_set);
	}
	WRPR_CTRL_POP();

	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

#ifdef CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
	static uint32_t bp_freq;
	bp_freq = pseq_get_system_freq();
#endif

#ifndef PSEQ_RETAIN_ICACHE
	ICACHE_DISABLE();
#endif

#ifdef CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
	if (bp_freq > ATM_BP_XTAL_FREQ) {
#ifdef PSEQ_USE_FSM
		// SW in, FSM doubler out
		CMSDK_CLKRSTGEN_NONSECURE->FSM_CTRL =
			CLKRSTGEN_FSM_CTRL__CLK16_SRC_INNER_VAL__MASK |
			CLKRSTGEN_FSM_CTRL__GO_ON_CPU_SLEEP_WKUP__MASK |
			CLKRSTGEN_FSM_CTRL__WAIT4XTAL__MASK |
			CLKRSTGEN_FSM_CTRL__TARGET_FREQ__MASK;
#endif

		pseq_prep_for_xtal_pd();
	}
#else // CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
	uint32_t bp_freq = at_clkrstgen_get_bp();
	if (bp_freq > ATM_BP_XTAL_FREQ) {
		// Get off PLL/doubler before xtal is powered down
		at_clkrstgen_set_bp(ATM_BP_XTAL_FREQ);
		CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL = 0;
	}
#endif // CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF

	/*
	 * Hibernate and soc_off will die inside WFI and
	 * reset after wakeup (CPU or entire chip, respectively)
	 */
	__DSB();
	__WFI();
	/* Retain will continue here after wakeup */

	// Settle PLL while RRAM timing is restored
	if (bp_freq > BP_DOUBLER_FREQ) {
		CMSDK_CLKRSTGEN_NONSECURE->PLL_CTRL = CLKRSTGEN_PLL_CTRL__PLL_ENABLE__MASK;
	}

	// Retention powered down ROMC and reset RRAM config
	rram_adjust_timing(bp_freq / 1000000);

#ifdef CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
#ifdef PSEQ_USE_FSM
	pseq_set_pll_when_ready(bp_freq, true);
	pseq_reset_fsm();
#else
	if (bp_freq == BP_DOUBLER_FREQ) {
		atm_bp_clock_set(BP_DOUBLER_FREQ);
	} else {
		pseq_set_pll_when_ready(bp_freq, false);
	}
#endif
#else // CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
	if (bp_freq > ATM_BP_XTAL_FREQ) {
		at_clkrstgen_set_bp(bp_freq);
	}
#endif // CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF

#ifndef PSEQ_RETAIN_ICACHE
	ICACHE_ENABLE();
#endif

	SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_back_from_retain();
		pseq_core_back_from_retain_final();

#ifdef CONFIG_DETECT_PULSE_IN_RETENTION
		if (SHOULD_DETECT_GPIO_PULSE() && !pseq_core_gpio_pulse_restore()) {
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
}

static void atm_power_pseq_control(void (*mode)(uint32_t idle, uint32_t *int_set))
{
	atm_power_pseq_setup(mode, _kernel.idle);
}

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
void pm_state_set(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_RUNTIME_IDLE:
		__disable_irq();
		atm_power_rram_nap_wfi();
		break;
	case PM_STATE_SUSPEND_TO_IDLE:
		__disable_irq();
		SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
#ifdef CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
		uint32_t slow_freq = 0;
		uint32_t bp_freq = pseq_scale_back_bp(BP_SLEEP_FREQ, &slow_freq);
		pseq_rram_nap_slow_wfi(bp_freq, slow_freq, false);
#else
		atm_power_rram_nap_wfi();
#endif
		SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
		break;
#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, retain))
	case PM_STATE_SUSPEND_TO_RAM: {
		__disable_irq();
		extern void sys_clock_correct(uint32_t cycles);

		uint32_t start = atm_get_sys_time();
		uint32_t systick_ctrl = SysTick->CTRL;
		SysTick->CTRL = systick_ctrl & ~SysTick_CTRL_ENABLE_Msk;

		atm_power_pseq_control(atm_power_mode_retain);

#ifdef FIXED_PCRT_AFTER_RETENTION
		uint32_t elapsed = atm_get_sys_time() - start;
#else
		uint32_t rt;
		WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
			uint32_t rt1 = CMSDK_PSEQ->CURRENT_REAL_TIME;
			rt = CMSDK_PSEQ->CURRENT_REAL_TIME;
			if (rt != rt1) {
				uint32_t rt3 = CMSDK_PSEQ->CURRENT_REAL_TIME;
				if (rt != rt3) {
					__UNUSED uint32_t rt2 = rt;
					rt = CMSDK_PSEQ->CURRENT_REAL_TIME;
					TIMER_ASSERT_ERR(rt == rt3);
				}
			}
		} WRPR_CTRL_POP();
		uint32_t elapsed = rt - start;
#endif
		SysTick->CTRL = systick_ctrl;
		/* Convert lpcycles to hardware cycles */
		sys_clock_correct(atm_lpc_to(Z_HZ_cyc, elapsed));

		WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
		{
			if (PSEQ_STATUS__DBG_TRIGGERED__READ(CMSDK_PSEQ->STATUS)) {
				atm_power_swd_dbg_lock();
			}
		}
		WRPR_CTRL_POP();
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

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, soc_off))
void atm_pseq_soc_off(uint32_t ticks)
{
	__disable_irq();
	atm_power_pseq_setup(atm_power_mode_soc_off, ticks);
}
#endif // power_states/soc_off

#if DT_NODE_HAS_STATUS_OKAY(DT_PATH(power_states, hibernate))
void atm_pseq_hibernate(uint32_t ticks)
{
	__disable_irq();

#ifdef CONFIG_ATM_ATLC
	// Force ATLC to sleep
	ATLC_LC_LP_CTRL0__SW_WU_REQ__CLR(CMSDK_ATLC_NONSECURE->LC_LP_CTRL0);
	CMSDK_ATLC_NONSECURE->LC_LP_CTRL2 = ATLC_LC_LP_CTRL2__SLP_TM__WRITE(0);
	CMSDK_ATLC_NONSECURE->LC_LP_CTRL3 = ATLC_LC_LP_CTRL3__SLP__MASK;
#endif

	atm_power_pseq_setup(atm_power_mode_hibernate, ticks);
}
#endif // power_states/hibernate
#endif /* CONFIG_PM */

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

#ifndef CONFIG_CORTEX_M_SYSTICK_EXTERNAL_REF
	// SysTick is tied to BP frequency
	__UNUSED uint32_t bp_freq = at_clkrstgen_get_bp();
	ASSERT_INFO(bp_freq == CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC, bp_freq,
		    CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC);
#else
	ASSERT_INFO(CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC == 16000000,
		    CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC, 0);
#endif

#ifdef CONFIG_PM
	// IRQ_PRI_RT will break through irq_lock() to wake WFI in atm_power_pseq_control()
	NVIC_SetPriority(PSEQ_IRQn, IRQ_PRI_RT);

	// Don't let system reboot itself right away - application can decide later
	pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
	return 0;
}

SYS_INIT(atm_power_init, PRE_KERNEL_2, 0);
