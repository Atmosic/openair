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
