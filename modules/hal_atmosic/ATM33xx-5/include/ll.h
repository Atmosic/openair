/**
 *******************************************************************************
 *
 * @file ll.h
 *
 * @brief Declaration of low level functions.
 *
 * Copyright (C) RivieraWaves 2009-2015
 * Copyright (C) Atmosic 2021
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup LL Low level
 * @ingroup ATMx3
 * @brief Low level functions
 * @{
 */

#if !defined(__GNUC__) && !defined(__ICCARM__)
#error "File only included with ARM GCC or IAR ANSI C/C++ Compiler for ARM"
#endif

#ifndef __ARM_FEATURE_DSP
#define __ARM_FEATURE_DSP 0
#endif
#include "cmsis_compiler.h"

#ifdef __ICCARM__
#include <intrinsics.h>
#endif

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Interrupt priorities
#define IRQ_PRI_RT	0	// Real time - highest priority
#define IRQ_PRI_VERY_HIGH 2
#define IRQ_PRI_HIGH	4
#define IRQ_PRI_MID	6
#define IRQ_PRI_NORMAL	8
#define IRQ_PRI_LOW	10
#define IRQ_PRI_UI	12	// User interface - lowest priority

/** @brief Enable interrupts globally in the system.
 * This macro must be used when the initialization phase is over and the interrupts
 * can start being handled by the system.
 */
#define GLOBAL_INT_START()                                                  \
do {                                                                        \
    __enable_irq();                                                         \
} while(0)

/** @brief Disable interrupts globally in the system.
 * This macro must be used when the system wants to disable all the interrupt
 * it could handle.
 */
#define GLOBAL_INT_STOP()                                                   \
do {                                                                        \
    __disable_irq();                                                        \
} while(0)

/** @brief Disable interrupts globally in the system.
 * This macro must be used in conjunction with the @ref GLOBAL_INT_RESTORE macro since this
 * last one will close the brace that the current macro opens.  This means that both
 * macros must be located at the same scope level.
 */
#define GLOBAL_INT_DISABLE()                                                \
do {                                                                        \
    uint32_t __PRIMASK_save = __get_PRIMASK();                              \
    __disable_irq()

#define STATIC_GLOBAL_INT_DISABLE()                                         \
do {                                                                        \
    static uint32_t __PRIMASK_save;                                         \
    __PRIMASK_save = __get_PRIMASK();                                       \
    __disable_irq()

/** @brief Restore interrupts from the previous global disable.
 * @sa GLOBAL_INT_DISABLE
 */
#define GLOBAL_INT_RESTORE()                                                \
    __set_PRIMASK(__PRIMASK_save);                                          \
} while(0)

/** @brief Invoke the wait for interrupt procedure of the processor.
 *
 * @warning It is suggested that this macro is called while the interrupts are disabled
 * to have performed the checks necessary to decide to move to sleep mode.
 *
 */
#define WFI() __WFI()

/**
 * @brief Wait for a condition to be made true by an interrupt handler.
 */
#define WFI_COND(__c) do { \
    bool done = false; \
    do { \
	GLOBAL_INT_DISABLE(); \
	if (__c) { \
	    done = true; \
	} else { \
	    WFI(); \
	} \
	GLOBAL_INT_RESTORE(); \
    } while (!done); \
} while(0)

/**
 * @brief Relax the running CPU thread, especially when spinning.
 */
#define YIELD() __ASM volatile ("yield")

#ifdef __cplusplus
}
#endif

/// @} LL
