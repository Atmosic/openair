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

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(soc_power, CONFIG_SOC_LOG_LEVEL);

#include "arch.h"
#include "timer.h"
#include "at_wrpr.h"
#ifdef CONFIG_BT
#include "reg_ipcore.h"
#include "rwip.h"
#endif

#define PSEQ_INTERNAL_DIRECT_INCLUDE_GUARD
#include "pseq_internal.h"
#include "at_apb_pseq_regs_core_macro.h"

/* Debugs - to enable, change undef to define */
#undef DEBUG_HIBERNATE
#undef DEBUG_WAKE_MASK

#ifdef CONFIG_PM

#ifdef CONFIG_SYSTEM_CLOCK_SLOPPY_IDLE
#define IDLE_FOREVER K_TICKS_FOREVER
#else
#define IDLE_FOREVER INT_MAX
#endif

__ramfunc static void atm_power_mode_retain(uint32_t idle, uint32_t int_set)
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
	pseq_core_config_retain(duration, block_sysram, false, false);
	pseq_core_enter_retain(false, false);
}

static void atm_power_mode_hibernate(uint32_t idle, uint32_t int_set)
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

	__UNUSED uint32_t wake_mask = pseq_core_config_hibernate(duration, false, false);

#ifdef DEBUG_HIBERNATE
	printk("Hibernate duration %u, ise %#x\n", duration, int_set);
#ifdef DEBUG_WAKE_MASK
	printk("HWM %#x, GPWM %#x, GPWP %#x, GPWBE %#x, OV %#x, OV5 %#x\n", wake_mask,
	       CMSDK_PSEQ->GPIO_WAKE_MASK, CMSDK_PSEQ->GPIO_WAKE_POL,
	       CMSDK_PSEQ->GPIO_WAKE_BOTH_EDGES, CMSDK_PSEQ->OVERRIDES, CMSDK_PSEQ->OVERRIDES5);
#endif
	printk("****************\n");
#endif /* DEBUG_HIBERNATE */

	pseq_core_enter_hibernation(false, false);
}

static void atm_power_mode_soc_off(uint32_t idle, uint32_t int_set)
{
	uint64_t duration;
	if (idle != IDLE_FOREVER) {
		idle -= k_us_to_ticks_ceil32(DT_PROP_OR(DT_NODELABEL(soc_off), exit_latency_us, 0));
		/* Convert ticks to lpcycles */
		duration = atm_to_lpc(Z_HZ_ticks, idle);
	} else {
		duration = 0;
	}

	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE) {
		pseq_core_config_soc_off(duration);
	} WRPR_CTRL_POP();

#ifdef DEBUG_HIBERNATE
	printk("soc_off duration %llu\n", duration);
	printk("****************\n");
#endif /* DEBUG_HIBERNATE */

	pseq_core_enter_soc_off();
}

__ramfunc static void atm_power_pseq_setup(void (*mode)(uint32_t idle, uint32_t int_set),
					   uint32_t idle)
{
	/* Make certain that no interrupt will disturb sleep */
	uint32_t ise = NVIC->ISER[0];
	if (ise) {
		NVIC->ICER[0] = ise;
	}

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
		mode(idle, ise);
	} WRPR_CTRL_POP();

	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
	/*
	 * Hibernate and soc_off will die inside WFI and
	 * reset after wakeup (CPU or entire chip, respectively)
	 */
	__WFI();
	/* Retain will continue here after wakeup */
	SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
		pseq_core_back_from_retain();
	} WRPR_CTRL_POP();

	/* Restore interrupt enables */
	NVIC->ISER[0] = ise;
}

static void atm_power_pseq_control(void (*mode)(uint32_t idle, uint32_t int_set))
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
__ramfunc void pm_state_set(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_RUNTIME_IDLE:
		__WFI();
		break;
	case PM_STATE_SUSPEND_TO_IDLE:
		SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
		__WFI();
		SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
		break;
	case PM_STATE_SUSPEND_TO_RAM: {
		extern void sys_clock_correct(uint32_t cycles);

		uint32_t start = atm_get_sys_time();
		uint32_t systick_ctrl = SysTick->CTRL;
		SysTick->CTRL = systick_ctrl & ~SysTick_CTRL_ENABLE_Msk;

		atm_power_pseq_control(atm_power_mode_retain);

		uint32_t elapsed = atm_get_sys_time() - start;
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
	case PM_STATE_SOFT_OFF:
		if (!substate_id) {
			atm_power_pseq_control(atm_power_mode_hibernate);
		} else {
			atm_power_pseq_control(atm_power_mode_soc_off);
		}
		LOG_ERR("SOFT_OFF failed!");
		break;
	default:
		LOG_DBG("Unsupported power state %u", state);
		break;
	}
}

/* Handle SOC specific activity after Low Power Mode Exit */
__ramfunc void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_RUNTIME_IDLE:
	case PM_STATE_SUSPEND_TO_RAM:
	case PM_STATE_SOFT_OFF:
		/* Nothing to do. */
		break;
	default:
		LOG_DBG("Unsupported power state %u", state);
		break;
	}

	/*
	 * System is now in active mode. Reenable interrupts which were disabled
	 * when OS started idling code.
	 */
	irq_unlock(0);
}

void atm_pseq_soc_off(uint32_t ticks)
{
	__disable_irq();
	atm_power_pseq_setup(atm_power_mode_soc_off, ticks);
}

void atm_pseq_hibernate(uint32_t ticks)
{
	__disable_irq();

#ifdef CONFIG_BT
	// Force BLE to sleep
	ip_deepslwkup_set(0);
	rwip_rf.sleep();
#endif

	atm_power_pseq_setup(atm_power_mode_hibernate, ticks);
}

#endif /* CONFIG_PM */

static int atm_power_init(void)
{
	__UNUSED uint32_t status;
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
		pseq_core_power_all_sysram();
		pseq_core_xtal_init();
		status = CMSDK_PSEQ->STATUS;
	} WRPR_CTRL_POP();

#ifdef CONFIG_PM
	if (PSEQ_STATUS__DBG_TRIGGERED__READ(status)) {
		atm_power_swd_dbg_lock();
	}
	pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
	return 0;
}

SYS_INIT(atm_power_init, PRE_KERNEL_2, 0);
