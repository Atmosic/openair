/**
 *******************************************************************************
 *
 * @file armgcc/compiler.h
 *
 * @brief Definitions of compiler specific directives.
 *
 * Copyright (C) RivieraWaves 2009-2015
 * Copyright (C) Atmosic 2021
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup COMPILER Compiler
 * @ingroup ATMx3
 * @brief GNU gcc compiler interface
 * @{
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GNUC__
#error "File only included with ARM GCC"
#endif // __GNUC__

/// define the static keyword for this compiler
#define __RWIP_STATIC static
#define __RWIP_STATIC_VAR static

/// define the force inlining attribute for this compiler
#define __RWIP_INLINE __attribute__((__always_inline__)) static inline

/// define the IRQ handler attribute for this compiler
#define __RWIP_IRQ __attribute__((__interrupt__("IRQ")))

/// define the BLE IRQ handler attribute for this compiler
#define __RWIP_BTIRQ

/// define the BLE IRQ handler attribute for this compiler
#define __RWIP_BLEIRQ

/// define the FIQ handler attribute for this compiler
#define __RWIP_FIQ __attribute__((__interrupt__("FIQ")))

/// define size of an empty array (used to declare structure with an array size not defined)
#define __ARRAY_EMPTY

/// Function returns struct in registers (4 in rvds, var with gnuarm).
/// With Gnuarm, feature depends on command line options and
/// impacts ALL functions returning 2-words max structs
/// (check -freg-struct-return and -mabi=xxx)
#define __VIR

/// function has no side effect and return depends only on arguments
#define __PURE __attribute__((const))
#define __PUREISH __attribute__((pure))

/// Function never returns
#define __NORETURN __attribute__((noreturn))

/// Align instantiated lvalue or struct member on 4 bytes
#define __ALIGN4 __attribute__((aligned(4)))

/// __MODULE__ comes from the RVDS compiler that supports it
#ifndef __MODULE__
#define __MODULE__ __BASE_FILE__
#endif

/// Put a variable in a memory maintained during deep sleep
#define __LOWPOWER_SAVED

#ifndef _TOSTRING
#define _TOSTRING(x) #x
#endif
#define TOSTRING(x) _TOSTRING(x)
#define AT __MODULE__ ":" TOSTRING(__LINE__)

/// Do not initialize variable at startup
/// Create unique section header @file+line
#ifdef __ARMCC_VERSION
#define __UNINIT __attribute__((section(".bss.uninit." AT)))
#else
#define __UNINIT __attribute__((section(".uninit." AT)))
#endif

/// Locate code in high performance memory
#define __FAST

/// Not ROM, so keep private
#define __NR_STATIC static

/// Compile-time assertion
#define STATIC_ASSERT _Static_assert

/// Unused variable
#define __UNUSED __attribute__((unused))

/// Convert context pointer from const to non-const
#define CONTEXT_VOID_P(__p) ({ \
    __typeof__(__p) __tmp = (__p); \
    __builtin_choose_expr( \
	__builtin_types_compatible_p(__typeof__(__tmp), void const *), \
	(void *)(uintptr_t)__tmp, __tmp); \
})

/// Printf-like function
#define __PRINTF(...) __attribute__((format(printf, ##__VA_ARGS__)))

/// Arguments not permitting NULL value
#define __NONNULL_ALL __attribute__((nonnull))
#define __NONNULL(...) __attribute__((nonnull(__VA_ARGS__)))

/// Field position in compound object
#define __OFFSET(__s, __f) offsetof(__typeof__(__s), __f)

/// Constructor priority
#define __CONSTRUCTOR_PRIO(__p) __attribute__((constructor(__p)))

/// Convert structured struct with different type name
#define TYPE_CONVERT(src_type, var, dst_type) ({ \
    STATIC_ASSERT(__builtin_types_compatible_p(src_type, __typeof__(var)) && \
    (sizeof(src_type) == sizeof(dst_type)), "incompatable"); \
    *(dst_type const *)&var;})

/// Variables that may not be aligned
#ifdef __ARMCC_VERSION
#define __UNALIGNED __unaligned
#else
#define __UNALIGNED
#endif

#ifdef __cplusplus
}
#endif

/// @} COMPILER
