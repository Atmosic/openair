/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Override EXCEPTION_DUMP macro for SPE TrustZone environment.
 *
 * In TrustZone-M, UART is configured as Non-Secure after sec_switch_console().
 * If a fault occurs after this, the fault handler must not use printk, as
 * accessing Non-Secure UART from Secure state triggers another fault.
 *
 * This file must be force-included via compiler -include option to override
 * the original EXCEPTION_DUMP before fault.c includes exception.h.
 */

#ifndef ATM_SPE_EXCEPTION_OVERRIDE_H
#define ATM_SPE_EXCEPTION_OVERRIDE_H

/*
 * Pre-include the kernel headers required by <zephyr/arch/exception.h>
 * (specifically <zephyr/arch/arm/arm-m-switch.h>) in the same order used
 * by <zephyr/kernel_includes.h>. <zephyr/arch/cpu.h> must be included
 * before <zephyr/kernel/thread.h> so that arm-m-switch.h's own include
 * of <zephyr/kernel/thread.h> is the first visit and fully defines
 * struct k_thread before the inline arm_m_switch() body is parsed.
 *
 * <zephyr/kernel.h> is deliberately avoided so the generated
 * <zephyr/heap_constants.h> is not pulled into this force-included file;
 * see the Zephyr 4.4 migration guide.
 */
#include <zephyr/kernel_structs.h>
#include <zephyr/arch/cpu.h>

#include <zephyr/arch/exception.h>

#ifndef _ASMLANGUAGE

#ifdef EXCEPTION_DUMP
#undef EXCEPTION_DUMP
#endif

/* Helper to consume variadic arguments and avoid unused variable warnings */
static inline int __atm_exception_dump_unused(const char *fmt, ...)
{
	(void)fmt;
	return 0;
}

#define EXCEPTION_DUMP(fmt, ...) \
	do { \
		(void)__atm_exception_dump_unused(fmt, ##__VA_ARGS__); \
	} while (0)

#endif /* !_ASMLANGUAGE */

#endif /* ATM_SPE_EXCEPTION_OVERRIDE_H */
