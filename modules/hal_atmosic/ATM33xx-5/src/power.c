/*
 * Copyright (c) 2021-2024 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/sys_clock.h>
#include <zephyr/linker/linker-defs.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(soc_power, CONFIG_SOC_LOG_LEVEL);

#define __CLKRSTGEN_SET_STATIC_INLINE __STATIC_FORCEINLINE
#include "arch.h"
#include "timer.h"
#include "at_wrpr.h"
#include "at_clkrstgen.h"
#include "atm_bp_clock.h"
#include "at_pinmux.h"
#include "sec_cache.h"
#include "sec_reset.h"
#include "power.h"
#include "calibration.h"
#include "atm_otp.h"

#define PSEQ_INTERNAL_DIRECT_INCLUDE_GUARD
#include "pseq_internal.h"

/* Debugs - to enable, change undef to define */
#undef DEBUG_HIBERNATE
#undef DEBUG_WAKE_MASK

unsigned int secure_irq_lock(void);
void secure_irq_unlock(unsigned int key);

#ifdef CONFIG_PM

#ifdef CONFIG_SYSTEM_CLOCK_SLOPPY_IDLE
#define IDLE_FOREVER K_TICKS_FOREVER
#else
#define IDLE_FOREVER INT_MAX
#endif

#ifdef FIXME_UART_GLITCH
static uint8_t save_uart0tx_psel;
static uint8_t save_uart1tx_psel;
#endif

static void atm_power_mode_retain(uint32_t idle, uint32_t *int_set)
{
	uint32_t duration;
	if (idle != IDLE_FOREVER) {
		idle -= k_us_to_ticks_ceil32(DT_PROP_OR(DT_NODELABEL(retain), exit_latency_us, 0));
		/* Convert ticks to lpcycles */
		duration = z_tmcvt(idle, Z_HZ_ticks, 32768, true, true, false, false);
#ifdef PSEQ_TEST_TORTURE_RETAIN
		if (duration > 0x100) {
		    duration = 0x100;
		}
#endif
	} else {
		duration = 0;
	}

	static uint32_t __noinit_named(ssrs_block) ssrs_block[PSEQ_SYSRAM_SSRS_BLOCK_SIZE];
	// Retain all RAM
	uint32_t block_sysram = ~0;
	pseq_core_config_retain(duration, block_sysram, (uintptr_t)ssrs_block, false, false);

#ifdef FIXME_UART_GLITCH
#define PIN_UART0_TX_REG CMSDK_WRPR0_NONSECURE->PIN2REG(PIN_UART0_TX)
#define PIN_UART1_TX_REG CMSDK_WRPR0_NONSECURE->PIN2REG(PIN_UART1_TX)
	save_uart0tx_psel = PIN_SEL(PIN_UART0_TX, READ)(PIN_UART0_TX_REG);
	save_uart1tx_psel = PIN_SEL(PIN_UART1_TX, READ)(PIN_UART1_TX_REG);
	if (save_uart0tx_psel == PINMUX_UART0_TX) {
		PIN_SELECT_GPIO_PULLUP(PIN_UART0_TX);
	}
	if (save_uart1tx_psel == PINMUX_UART1_TX) {
		PIN_SELECT_GPIO_PULLUP(PIN_UART1_TX);
	}
#endif

	pseq_core_enter_retain(false, false);
}

static void atm_power_mode_hibernate(uint32_t idle, uint32_t *int_set)
{
	uint32_t duration;
	if (idle != IDLE_FOREVER) {
		idle -= k_us_to_ticks_ceil32(DT_PROP_OR(DT_NODELABEL(hibernate), exit_latency_us,
							0));
		/* Convert ticks to lpcycles */
		duration = z_tmcvt(idle, Z_HZ_ticks, 32768, true, true, false, false);
	} else {
		duration = 0;
	}

	__UNUSED uint32_t wake_mask = pseq_core_config_hibernate(duration, false, false);

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

	pseq_core_enter_hibernation(false, false);
}

#if defined(CONFIG_NONRF_HARV) || defined(CONFIG_RF_HARV)
static bool harv_enabled(void)
{
	atm_otp_t otp = 0;
	bool __UNUSED otp_ok = nsc_atm_otp_read(&otp);
	ASSERT_ERR(otp_ok);
	return !(otp & ATM_OTP_MASK_HARV_DISABLED_LATCH);
}
#endif

static void atm_power_mode_soc_off(uint32_t idle, uint32_t *int_set)
{
	uint64_t duration;
	if (idle != IDLE_FOREVER) {
		idle -= k_us_to_ticks_ceil32(DT_PROP_OR(DT_NODELABEL(soc_off), exit_latency_us, 0));
		/* Convert ticks to lpcycles */
		duration = z_tmcvt(idle, Z_HZ_ticks, 32768, true, false, false, false);
	} else {
		duration = 0;
	}

	WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_config_soc_off(duration);

#if defined(CONFIG_NONRF_HARV) || defined(CONFIG_RF_HARV)
		// Disable harvesting in the SOC OFF mode
		if (harv_enabled()) {
			pseq_core_disable_harv();
		}
#endif
	}
	WRPR_CTRL_POP();

#ifdef DEBUG_HIBERNATE
	printk("soc_off duration %llu\n", duration);
#endif /* DEBUG_HIBERNATE */

	pseq_core_enter_soc_off();
}

/*
 * Locate in RAM - avoid waking RRAM from nap
 */
__ramfunc static void pseq_rram_nap_wfi(void)
{
	pseq_core_rram_nap();

	__set_BASEPRI(0);
	__ISB();
	__DSB();
	__WFI();
}

/*
 * Locate in RAM - avoid waking RRAM from shutdown
 */
__ramfunc static void atm_power_rram_sd_wfi(void)
{
	uint32_t bp_freq = at_clkrstgen_get_bp();
	if (bp_freq > ATM_BP_XTAL_FREQ) {
		pseq_rram_nap_wfi();
		return;
	}

	pseq_core_rram_sd();

	__set_BASEPRI(0);
	__ISB();
	__DSB();
	__WFI();

	// NOTE: RRAM shutdown wiped out RRAM_R config
}

static void atm_power_pseq_setup(void (*mode)(uint32_t idle, uint32_t *int_set), uint32_t idle)
{
	uint32_t int_set[INT_REG_NUM];

	// Make certain that no interrupt will disturb sleep
	for (int i = 0; i < INT_REG_NUM; i++) {
		NVIC->ICER[i] = int_set[i] = NVIC->ISER[i];
	}
	unsigned int sec_key = secure_irq_lock();

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		mode(idle, int_set);
	}
	WRPR_CTRL_POP();

	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

	ICACHE_DISABLE();

	uint32_t bp_freq = at_clkrstgen_get_bp();
	if (bp_freq > ATM_BP_XTAL_FREQ) {
		// Get off PLL/doubler before xtal is powered down
		at_clkrstgen_set_bp(ATM_BP_XTAL_FREQ);
	}

	/*
	 * Hibernate and soc_off will die inside WFI and
	 * reset after wakeup (CPU or entire chip, respectively)
	 */
	__DSB();
	__WFI();
	/* Retain will continue here after wakeup */

	// Retention powered down ROMC and reset RRAM config

	if (bp_freq > ATM_BP_XTAL_FREQ) {
		at_clkrstgen_set_bp(bp_freq);
	}

	ICACHE_ENABLE();

	SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

#ifdef FIXME_UART_GLITCH
	if (save_uart1tx_psel == PINMUX_UART1_TX) {
		PIN_SELECT(PIN_UART1_TX, UART1_TX);
	}
	if (save_uart0tx_psel == PINMUX_UART0_TX) {
		PIN_SELECT(PIN_UART0_TX, UART0_TX);
	}
#endif

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_back_from_retain();
		pseq_core_back_from_retain_final();
	}
	WRPR_CTRL_POP();

	// Restore interrupt set enables
	secure_irq_unlock(sec_key);
	for (int i = 0; i < INT_REG_NUM; i++) {
		NVIC->ISER[i] = int_set[i];
	}
	irq_unlock(0);
}

static void atm_power_pseq_control(void (*mode)(uint32_t idle, uint32_t *int_set))
{
	atm_power_pseq_setup(mode, _kernel.idle);
}

/* Invoke Low Power/System Off specific Tasks */
void pm_state_set(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_RUNTIME_IDLE:
		__disable_irq();
		atm_power_rram_sd_wfi();
		break;
	case PM_STATE_SUSPEND_TO_IDLE:
		__disable_irq();
		SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
		atm_power_rram_sd_wfi();
		SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
		break;
	case PM_STATE_SUSPEND_TO_RAM: {
		__disable_irq();
		extern void sys_clock_correct(uint32_t cycles);

		uint32_t start = atm_get_sys_time();
		uint32_t systick_ctrl = SysTick->CTRL;
		SysTick->CTRL = systick_ctrl & ~SysTick_CTRL_ENABLE_Msk;

		atm_power_pseq_control(atm_power_mode_retain);

		uint32_t elapsed = atm_get_sys_time() - start;
		SysTick->CTRL = systick_ctrl;
		/* Convert lpcycles to hardware cycles */
		sys_clock_correct(z_tmcvt(elapsed, 32768, Z_HZ_cyc, true, true, false, false));
		break;
	}
	case PM_STATE_SOFT_OFF:
		__disable_irq();
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
void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
{
	switch (state) {
	case PM_STATE_RUNTIME_IDLE:
	case PM_STATE_SUSPEND_TO_IDLE:
	case PM_STATE_SUSPEND_TO_RAM:
	case PM_STATE_SOFT_OFF:
		__enable_irq();
		break;
	default:
		LOG_DBG("Unsupported power state %u", state);
		irq_unlock(0);
		break;
	}
}

void atm_pseq_soc_off(uint32_t ticks)
{
	__disable_irq();
	atm_power_pseq_setup(atm_power_mode_soc_off, ticks);
}

void atm_pseq_hibernate(uint32_t ticks)
{
	__disable_irq();
	atm_power_pseq_setup(atm_power_mode_hibernate, ticks);
}

#endif /* CONFIG_PM */

#ifdef SECURE_PROC_ENV
#define __SPE_NSC __attribute__((cmse_nonsecure_entry)) __attribute__((used))
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

static int atm_power_init(void)
{
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		pseq_core_power_all_sysram();
		pseq_core_xtal_init();

#ifdef CONFIG_PM
		uint32_t status = pseq_core_init();
		printk("PSEQ STATUS=%#" PRIx32 "\n", status);
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

	at_clkrstgen_set_bp(DT_PROP(DT_NODELABEL(sysclk), clock_frequency));
	__UNUSED uint32_t bp_freq = at_clkrstgen_get_bp();
	// SysTick is tied to BP frequency
	__ASSERT(bp_freq == CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC,
		"Mismatched bp_freq to config");

#ifdef CONFIG_PM
	// IRQ_PRI_RT will break through irq_lock() to wake WFI in atm_power_pseq_control()
	NVIC_SetPriority(PSEQ_IRQn, IRQ_PRI_RT);

	// Don't let system reboot itself right away - application can decide later
	pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
#endif
	return 0;
}

SYS_INIT(atm_power_init, PRE_KERNEL_2, 0);
