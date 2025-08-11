/**
 *******************************************************************************
 *
 * @file compiler.h
 *
 * @brief Definitions of compiler specific directives.
 *
 * Copyright (C) Atmosic 2021
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup COMPILER Compiler
 * @ingroup ATMx3
 * @brief IAR ANSI C/C++ compiler interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ICCARM__
#error "File only included with IAR ANSI C/C++ Compiler for ARM"
#endif

/// define the static keyword for this compiler
#define __STATIC static

/// define the force inlining attribute for this compiler
#define __INLINE _Pragma("inline=forced") static inline

/// define the IRQ handler attribute for this compiler
#define __IRQ __irq

/// define the BLE IRQ handler attribute for this compiler
#define __BTIRQ

/// define the BLE IRQ handler attribute for this compiler
#define __BLEIRQ

/// define the FIQ handler attribute for this compiler
#define __FIQ __fiq

/// define size of an empty array (used to declare structure with an array size not defined)
#define __ARRAY_EMPTY

/// Function returns struct in registers (4 in rvds, var with gnuarm).
/// With Gnuarm, feature depends on command line options and
/// impacts ALL functions returning 2-words max structs
/// (check -freg-struct-return and -mabi=xxx)
#define __VIR

/// function has no side effect and return depends only on arguments
#define __PURE
#define __PUREISH

/// Function never returns
#define __NORETURN __noreturn

/// Align instantiated lvalue or struct member on 4 bytes
#define __ALIGN4 __attribute__((aligned(4)))

/// __MODULE__ comes from the RVDS compiler that supports it
#ifndef __MODULE__
#define __MODULE__ __BASE_FILE__
#endif

/// Pack a structure field
#define __PACKED __attribute__ ((__packed__))

/// Put a variable in a memory maintained during deep sleep
#define __LOWPOWER_SAVED

/// Do not initialize variable at startup
/// Create unique section header @file+line
#define __UNINIT __no_init

/// Locate code in high performance memory
#define __FAST

/// Not ROM, so keep private
#define __NR_STATIC static

/// Compile-time assertion
#define STATIC_ASSERT _Static_assert

/// Unused variable
#define __UNUSED __attribute__((unused))

/// Convert context pointer from const to non-const
#define CONTEXT_VOID_P(__p) ((void *)(uintptr_t)(__p))

/// Printf-like function
#define __PRINTF(...)

/// Arguments not permitting NULL value
#define __NONNULL_ALL
#define __NONNULL(...)

/// Field position in compound object
#define __OFFSET(__s, __f) (((char *)&(__s.__f)) - (char *)&(__s))

/// Constructor priority not supported - must be managed by linker script
#define __CONSTRUCTOR_PRIO(__p) __attribute__((constructor))

/// Convert structured struct with different type name
#define TYPE_CONVERT(src_type, var, dst_type) ({ \
    STATIC_ASSERT(sizeof(src_type) == sizeof(dst_type), "incompatable"); \
    *(dst_type const *)&var;})

/// Variables that may not be aligned
#define __UNALIGNED

#ifdef __cplusplus
}
#endif

/// @} COMPILER
