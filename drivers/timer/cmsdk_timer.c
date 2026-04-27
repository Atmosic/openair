/*
 * Copyright (c) 2018 Intel Corporation
 * Copyright (c) 2026 Atmosic Technologies, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * CMSDK Timer driver for Zephyr system clock.
 * Based on cortex_m_systick.c but adapted for CMSDK_TIMER_TypeDef registers.
 *
 * Key differences from SysTick:
 * - CMSDK_TIMER has 32-bit counter (vs 24-bit SysTick)
 * - Register layout: CTRL, VALUE, RELOAD, INTSTATUS/INTCLEAR
 *   (vs SysTick: CTRL, LOAD, VAL, CALIB)
 * - INTSTATUS must be explicitly cleared via INTCLEAR write
 *   (vs SysTick COUNTFLAG auto-clears on CTRL read)
 * - Writing to VALUE sets counter directly
 *   (vs SysTick VAL write resets counter to LOAD)
 */

#define DT_DRV_COMPAT arm_cmsdk_systimer

#include <zephyr/init.h>
#include <zephyr/drivers/timer/system_timer.h>
#include <zephyr/sys_clock.h>
#include <zephyr/spinlock.h>
#include <zephyr/irq.h>
#include <zephyr/sys/util.h>

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) == 1,
	     "Exactly one arm,cmsdk-systimer node must be enabled");

/* CMSDK Timer register structure */
struct cmsdk_timer_regs {
	volatile uint32_t ctrl;      /* 0x000: Control Register */
	volatile uint32_t value;     /* 0x004: Current Value Register */
	volatile uint32_t reload;    /* 0x008: Reload Value Register */
	volatile uint32_t intstatus; /* 0x00C: Interrupt Status / Clear Register */
};

/* CMSDK Timer CTRL register bits */
#define CMSDK_TIMER_CTRL_EN_Msk        (1UL << 0)
#define CMSDK_TIMER_CTRL_SELEXTEN_Msk  (1UL << 1)
#define CMSDK_TIMER_CTRL_SELEXTCLK_Msk (1UL << 2)
#define CMSDK_TIMER_CTRL_IRQEN_Msk     (1UL << 3)

/* CMSDK Timer INTSTATUS/INTCLEAR register bits */
#define CMSDK_TIMER_INTSTATUS_Msk (1UL << 0)
#define CMSDK_TIMER_INTCLEAR_Msk  (1UL << 0)

/* Timer base address and IRQ from devicetree */
#define TIMER_BASE     ((struct cmsdk_timer_regs *)DT_INST_REG_ADDR(0))
#define TIMER_IRQ      DT_INST_IRQN(0)
#define TIMER_IRQ_PRIO DT_INST_IRQ(0, priority)

/* 32-bit counter max (vs 24-bit for SysTick) */
#define COUNTER_MAX 0xffffffffUL

#if defined(CONFIG_TIMER_READS_ITS_FREQUENCY_AT_RUNTIME)
extern unsigned int z_clock_hw_cycles_per_sec;
#define CYC_PER_TICK (z_clock_hw_cycles_per_sec / CONFIG_SYS_CLOCK_TICKS_PER_SEC)
#else
#define CYC_PER_TICK (CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC / CONFIG_SYS_CLOCK_TICKS_PER_SEC)
#endif

/* add MAX_TICKS protection - use unsigned to avoid overflow with 32-bit counter */
#define _MAX_TICKS (uint32_t)((COUNTER_MAX / CYC_PER_TICK) - 1)
#define MAX_TICKS  ((_MAX_TICKS > 0) ? _MAX_TICKS : 1)
#define MAX_CYCLES (MAX_TICKS * (uint32_t)CYC_PER_TICK)

/*
 * Minimum cycles in the future to try to program.
 * This is the minimum value of the RELOAD register.
 */
#define MIN_DELAY MAX(1024U, ((uint32_t)CYC_PER_TICK / 16U))

static struct k_spinlock lock;
static uint32_t last_load;
static bool timer_stopped;

#ifdef CONFIG_CMSDK_TIMER_64BIT_CYCLE_COUNTER
typedef uint64_t cycle_t;
#else
typedef uint32_t cycle_t;
#endif

/*
 * This local variable holds the amount of CMSDK Timer HW cycles elapsed
 * and it is updated in the ISR and sys_clock_set_timeout().
 */
static cycle_t cycle_count;

/*
 * This local variable holds the amount of elapsed HW cycles
 * that have been announced to the kernel.
 */
static cycle_t announced_cycles;

/*
 * This local variable holds the amount of elapsed HW cycles due to
 * timer wraps ('overflows').
 */
static volatile uint32_t overflow_cyc;

/*
 * Calculate the amount of HW cycles that have elapsed since the last
 * time the absolute HW cycles counter has been updated.
 *
 * Key difference from SysTick: CMSDK_TIMER's INTSTATUS does NOT auto-clear.
 * We must explicitly write to INTCLEAR to acknowledge the interrupt.
 */
static uint32_t elapsed(void)
{
	struct cmsdk_timer_regs *timer = TIMER_BASE;
	uint32_t val1 = timer->value;
	uint32_t sts = timer->intstatus;
	uint32_t val2 = timer->value;

	/*
	 * CMSDK Timer behavior: The counter counts down from RELOAD to 0.
	 * When it reaches 0, it sets INTSTATUS and reloads from RELOAD.
	 *
	 * Wrap/realign val1 and val2 from [0:last_load-1] to [1:last_load].
	 */
	if (val1 == 0) {
		val1 = last_load;
	}
	if (val2 == 0) {
		val2 = last_load;
	}

	if ((sts & CMSDK_TIMER_INTSTATUS_Msk) || (val1 < val2)) {
		overflow_cyc += last_load;
		/* Clear the interrupt status - explicit write required */
		timer->intstatus = CMSDK_TIMER_INTCLEAR_Msk;
	}

	return (last_load - val2) + overflow_cyc;
}

static void cmsdk_timer_isr(void)
{
	uint32_t dcycles;
	uint32_t dticks;

	/* Update overflow_cyc and clear INTSTATUS by invoking elapsed() */
	elapsed();

	/* Increment the amount of HW cycles elapsed and announce to kernel */
	cycle_count += overflow_cyc;
	overflow_cyc = 0;

	if (IS_ENABLED(CONFIG_TICKLESS_KERNEL)) {
		dcycles = cycle_count - announced_cycles;
		dticks = dcycles / CYC_PER_TICK;
		announced_cycles += dticks * CYC_PER_TICK;
		sys_clock_announce(dticks);
	} else {
		sys_clock_announce(1);
	}
}

void sys_clock_set_timeout(int32_t ticks, bool idle)
{
	struct cmsdk_timer_regs *timer = TIMER_BASE;

	/*
	 * If the kernel allows us to miss tick announcements in idle,
	 * then shut off the counter.
	 */
	if (IS_ENABLED(CONFIG_TICKLESS_KERNEL) && idle && ticks == K_TICKS_FOREVER) {
		timer->ctrl &= ~CMSDK_TIMER_CTRL_EN_Msk;
		timer_stopped = true;
		return;
	}

#if defined(CONFIG_TICKLESS_KERNEL)
	uint32_t delay;
	uint32_t val1, val2;
	uint32_t last_load_ = last_load;

	ticks = (ticks == K_TICKS_FOREVER) ? MAX_TICKS : ticks;
	ticks = CLAMP(ticks - 1, 0, (int32_t)MAX_TICKS);

	k_spinlock_key_t key = k_spin_lock(&lock);

	uint32_t pending = elapsed();

	val1 = timer->value;

	cycle_count += pending;
	overflow_cyc = 0U;

	uint32_t unannounced = cycle_count - announced_cycles;

	if ((int32_t)unannounced < 0) {
		/*
		 * We haven't announced for more than half the 32-bit
		 * wrap duration. Force an announce to avoid loss of
		 * a wrap event.
		 */
		last_load = MIN_DELAY;
	} else {
		/* Desired delay in the future */
		delay = ticks * CYC_PER_TICK;

		/* Round delay up to next tick boundary */
		delay += unannounced;
		delay = DIV_ROUND_UP(delay, CYC_PER_TICK) * CYC_PER_TICK;
		delay -= unannounced;
		delay = MAX(delay, MIN_DELAY);
		if (delay > MAX_CYCLES) {
			last_load = MAX_CYCLES;
		} else {
			last_load = delay;
		}
	}

	val2 = timer->value;

	/*
	 * Program the new reload value and reset the counter.
	 * CMSDK Timer counts RELOAD+1 cycles (RELOAD down to 0),
	 * so subtract 1 like SysTick does with LOAD.
	 */
	timer->reload = last_load - 1;
	timer->value = last_load - 1;

	/*
	 * Add elapsed cycles while computing the new load to cycle_count.
	 */
	if (val1 < val2) {
		cycle_count += (val1 + (last_load_ - val2));
	} else {
		cycle_count += (val1 - val2);
	}
	k_spin_unlock(&lock, key);
#endif
}

uint32_t sys_clock_elapsed(void)
{
	if (!IS_ENABLED(CONFIG_TICKLESS_KERNEL)) {
		return 0;
	}

	k_spinlock_key_t key = k_spin_lock(&lock);
	uint32_t unannounced = cycle_count - announced_cycles;
	uint32_t cyc = elapsed() + unannounced;

	k_spin_unlock(&lock, key);
	return cyc / CYC_PER_TICK;
}

uint32_t sys_clock_cycle_get_32(void)
{
	k_spinlock_key_t key = k_spin_lock(&lock);
	uint32_t ret = cycle_count;

	ret += elapsed();
	k_spin_unlock(&lock, key);
	return ret;
}

#ifdef CONFIG_CMSDK_TIMER_64BIT_CYCLE_COUNTER
uint64_t sys_clock_cycle_get_64(void)
{
	k_spinlock_key_t key = k_spin_lock(&lock);
	uint64_t ret = cycle_count + elapsed();

	k_spin_unlock(&lock, key);
	return ret;
}
#endif

void sys_clock_idle_exit(void)
{
	struct cmsdk_timer_regs *timer = TIMER_BASE;

	if (timer_stopped) {
		/* Timer was stopped. Restart from scratch. */
		timer_stopped = false;
		K_SPINLOCK(&lock) {
			last_load = CYC_PER_TICK;
			timer->reload = last_load - 1;
			timer->value = last_load - 1;
			timer->ctrl |= CMSDK_TIMER_CTRL_EN_Msk;
		}
	}
}

void sys_clock_disable(void)
{
	struct cmsdk_timer_regs *timer = TIMER_BASE;

	timer->ctrl &= ~CMSDK_TIMER_CTRL_EN_Msk;
}

static int sys_clock_driver_init(void)
{
	struct cmsdk_timer_regs *timer = TIMER_BASE;

	IRQ_CONNECT(TIMER_IRQ, TIMER_IRQ_PRIO, cmsdk_timer_isr, 0, 0);

	last_load = CYC_PER_TICK;
	overflow_cyc = 0U;

	/*
	 * Program reload value and set current value.
	 * CMSDK Timer counts RELOAD+1 cycles, so subtract 1.
	 */
	timer->reload = last_load - 1;
	timer->value = last_load - 1;

	/* Clear any pending interrupt */
	timer->intstatus = CMSDK_TIMER_INTCLEAR_Msk;

	/* Enable timer with interrupt */
	timer->ctrl = CMSDK_TIMER_CTRL_EN_Msk | CMSDK_TIMER_CTRL_IRQEN_Msk;

	irq_enable(TIMER_IRQ);

	return 0;
}

SYS_INIT(sys_clock_driver_init, PRE_KERNEL_2, CONFIG_SYSTEM_CLOCK_INIT_PRIORITY);
