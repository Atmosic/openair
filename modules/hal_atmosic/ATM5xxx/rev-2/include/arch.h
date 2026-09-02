/**
 ****************************************************************************************
 *
 * @file arch.h
 *
 * @brief This file contains the definitions of the macros and functions that are
 * architecture dependent.  The implementation of those is implemented in the
 * appropriate architecture directory.
 *
 * Copyright (C) RivieraWaves 2009-2015
 * Copyright (C) Atmosic 2025-2026
 *
 ****************************************************************************************
 */


#ifndef _ARCH_H_
#define _ARCH_H_

/**
 ****************************************************************************************
 * @defgroup DRIVERS
 * @brief Reference IP Platform Drivers
 *
 * This module contains the necessary drivers to run the platform with the
 * RW BT SW protocol stack.
 *
 * This has the declaration of the platform architecture API.
 *
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdint.h>        // standard integer definition
#include <stdbool.h>       // standard boolean definition
#include <inttypes.h>      // for PRI format specifiers
#include "compiler.h"      // inline functions
#include "ll.h"
#include "ARMv8MBL.h"
#include "base_addr.h"
#include "retarget_uart.h"
#undef printf

#include "rep_vec.h"

/* Macros for 64-bit integer printing */
#define PRI_UINT64_FMT(value) ((uint32_t)((value) >> 32)), ((uint32_t)(value))
#define PRI_INT64_FMT(value) ((uint32_t)((uint64_t)(value) >> 32)), ((uint32_t)(value))

/* Format strings for 64-bit integers (prints as two 32-bit hex values) */
#define PRI_UINT64 "0x%08" PRIx32 "%08" PRIx32
#define PRI_INT64  "0x%08" PRIx32 "%08" PRIx32

/*
 * CPU Endianness
 ****************************************************************************************
 */
/// ARM is little endian
#define CPU_LE          1

/*
 * Constructor ordering
 */
#define CONSTRUCTOR_WATCHDOG	101	// Very first constructor
#define CONSTRUCTOR_SPI		102	// Needed by reset driver
#define CONSTRUCTOR_PSEQ	103	// Power-on management
#define CONSTRUCTOR_RESET	104	// Reset reason
#define CONSTRUCTOR_HW_CFG	105	// HW calibration
#define CONSTRUCTOR_LED		106	// Before drivers configure pinmux
#define CONSTRUCTOR_DTOP_BYPASS	107	// Can change sysclk
#define CONSTRUCTOR_PINMUX	108	// After HW_CFG; check BOARD
#define CONSTRUCTOR_MAIN	198	// Main constructor
#define CONSTRUCTOR_USER_INIT	199	// Last numbered constructor
// Followed by unnumbered constructors

/*
 * DEBUG configuration
 ****************************************************************************************
 */
#if defined(CFG_DBG) || defined(CFG_PLF_DEBUG)
#define PLF_DEBUG          1
#else //CFG_DBG
#define PLF_DEBUG          0
#endif //CFG_DBG

/*
 * DEFINES
 ****************************************************************************************
 */

/// Hardware compatibility
#define CMSDK_AES	CMSDK_AES_NONSECURE
#define CMSDK_GADC	CMSDK_GADC_NONSECURE
#define CMSDK_I2C0	CMSDK_I2C0_NONSECURE
#define CMSDK_I2C1	CMSDK_I2C1_NONSECURE
#define CMSDK_I2S	CMSDK_I2S_NONSECURE
#define CMSDK_KSM	CMSDK_KSM_NONSECURE
#define CMSDK_MDM	CMSDK_MDM_NONSECURE
#define CMSDK_PDM	CMSDK_PDM0_NONSECURE
#define CMSDK_AHB_PDM_PP_BASE	CMSDK_PDM0_PP_NONSECURE_BASE
#define CMSDK_PMU	CMSDK_PMU_NONSECURE
#define CMSDK_PWM	CMSDK_PWM_NONSECURE
#define CMSDK_PSEQ	CMSDK_PSEQ_NONSECURE
#define CMSDK_QDEC	CMSDK_QDEC_NONSECURE
#define CMSDK_QSPI	CMSDK_QSPI_NONSECURE
#define CMSDK_RADIO	CMSDK_RADIO_NONSECURE
#define CMSDK_RIF	CMSDK_RIF_NONSECURE
#define CMSDK_SLWTIMER	CMSDK_SLWTIMER_NONSECURE
#define CMSDK_SPI0	CMSDK_SPI0_NONSECURE
#define CMSDK_SPI1	CMSDK_SPI1_NONSECURE
#define CMSDK_SPI2	CMSDK_SPI2_NONSECURE
#define CMSDK_SWD	CMSDK_SWD_NONSECURE
#define CMSDK_TRNG	CMSDK_TRNG_NONSECURE
#undef CMSDK_AT_UART0
#define CMSDK_AT_UART0	CMSDK_AT_UART0_NONSECURE
#undef CMSDK_UART1
#define CMSDK_UART1	CMSDK_AT_UART1_NONSECURE
#define UARTOVF0_IRQn	UART0_OVERFLOW_IRQn
#define UARTOVF1_IRQn	UART1_OVERFLOW_IRQn
#define CMSDK_WATCHDOG	NONSECURE_WATCHDOG

/// Possible errors detected by FW
#define    RESET_NO_ERROR         0x00000000

/*
 * EXPORTED FUNCTION DECLARATION
 ****************************************************************************************
 */

#if PLF_DEBUG
/**
 ****************************************************************************************
 * @brief Print the assertion error reason and loop forever.
 *
 * @param condition C string containing the condition.
 * @param file C string containing file where the assertion is located.
 * @param line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
#if defined(CFG_PLF_DEBUG) && (CFG_PLF_DEBUG == 0xc02cea1)
__attribute__((weak))
#endif
void assert_err(const char *condition, const char * file, int line);

/**
 ****************************************************************************************
 * @brief Print the assertion error reason and loop forever.
 * The parameter value that is causing the assertion will also be disclosed.
 *
 * @param param0 parameter value 0.
 * @param param1 parameter value 1.
 * @param file C string containing file where the assertion is located.
 * @param line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
#if defined(CFG_PLF_DEBUG) && (CFG_PLF_DEBUG == 0xc02cea1)
__attribute__((weak))
#endif
void assert_param(int param0, int param1, const char * file, int line);

/**
 ****************************************************************************************
 * @brief Print the assertion warning reason.
 *
 * @param param0 parameter value 0.
 * @param param1 parameter value 1.
 * @param file C string containing file where the assertion is located.
 * @param line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
#if defined(CFG_PLF_DEBUG) && (CFG_PLF_DEBUG == 0xc02cea1)
__attribute__((weak))
#endif
void assert_warn(int param0, int param1, const char * file, int line);


/**
 ****************************************************************************************
 * @brief Dump HCI data
 *
 * @param[in] type         HCI Packet type
 * @param[in] direction    0: Output, 1: Input
 * @param[in] p_data       Pointer to HCI data
 * @param[in] length       Length of HCI data
 * @param[in] p_hdr_data   Pointer to HCI Header data
 * @param[in] hdr_length   Length of HCI header data
 ****************************************************************************************
 */
#if defined(CFG_PLF_DEBUG) && (CFG_PLF_DEBUG == 0xc02cea1)
__attribute__((weak))
#endif
void dump_hci(uint8_t type, uint8_t direction, uint8_t* p_data, uint16_t length, uint8_t* p_hdr_data, uint16_t hdr_length);

/**
 ****************************************************************************************
 * @brief Dump HCI data in unpacked format
 *
 * @param[in] evttype      HCI Packet type (@see enum hl_hci_evt_type)
 * @param[in] direction    0: Output, 1: Input
 * @param[in] code         Event of Command Operation code
 * @param[in] p_data       Pointer to HCI data
 * @param[in] length       Length of HCI data
 ****************************************************************************************
 */
#if defined(CFG_PLF_DEBUG) && (CFG_PLF_DEBUG == 0xc02cea1)
__attribute__((weak))
#endif
void dump_upk_hci(uint8_t evttype, uint8_t direction, uint16_t code, uint8_t* p_data, uint16_t length);

#endif //PLF_DEBUG

/**
 * @brief Debug trace log with timestamp
 * @param[in] format Printf-style formatter
 * @param     ...    Arguments for formatter
 * @returns Number of characters logged
 */
#if defined(CFG_PLF_DEBUG) && (CFG_PLF_DEBUG == 0xc02cea1)
__attribute__((weak))
#endif
#if PLF_DEBUG
__PRINTF(1, 2) int debug_trace(const char *format, ...);
#else
__PRINTF(1, 2) int debug_trace_stub(const char *format, ...);
#endif

/*
 * ASSERTION CHECK
 ****************************************************************************************
 */
#if PLF_DEBUG
#if defined(CFG_PLF_DEBUG) && (CFG_PLF_DEBUG == 0xc02cea1)
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)                              \
    do {                                              \
        if (assert_err && !(cond)) {                  \
            assert_err(#cond, __MODULE__, __LINE__);  \
        }                                             \
    } while(0)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_INFO(cond, param0, param1)             \
    do {                                              \
        if (assert_param && !(cond)) {                \
            assert_param((int)param0, (int)param1, __MODULE__, __LINE__);  \
        }                                             \
    } while(0)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond, param0, param1)             \
    do {                                              \
        if (assert_warn && !(cond)) {                 \
            assert_warn((int)param0, (int)param1, __MODULE__, __LINE__); \
        }                                             \
    } while(0)

/// DUMP HCI packet
#define DUMP_HCI(type, direction, data, length)\
    do {\
	if (dump_hci) {\
	    dump_hci(type, direction, (uint8_t*)data, length, NULL, 0);\
	}\
    } while(0)

/// DUMP HCI packet
#define DUMP_HCI_2(type, direction, hdr_data, hdr_length, data, length)\
    do {\
	if (dump_hci) {\
	    dump_hci(type, direction, (uint8_t*)data, length, (uint8_t*)hdr_data, hdr_length);\
	}\
    } while(0)

/// DUMP HCI packet in unpacked format
#define DUMP_UPK_HCI(evttype, direction, code, data, length)\
    do {\
	if (dump_upk_hci) {\
	    dump_upk_hci(evttype, direction, code, (uint8_t*)data, length);\
	}\
    } while(0)

#define DEBUG_TRACE(fmt, ...)\
    do {\
	if (debug_trace) {\
	    debug_trace(fmt, ##__VA_ARGS__);\
	}\
    } while(0)
#define DEBUG_TRACE_COND(cond, fmt, ...)\
    do {\
	if (debug_trace && cond) {\
	    debug_trace(fmt, ##__VA_ARGS__);\
	}\
    } while(0)
#else // CFG_PLF_DEBUG
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)                              \
    do {                                              \
        if (!(cond)) {                                \
            assert_err(#cond, __MODULE__, __LINE__);  \
        }                                             \
    } while(0)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_INFO(cond, param0, param1)             \
    do {                                              \
        if (!(cond)) {                                \
            assert_param((int)param0, (int)param1, __MODULE__, __LINE__);  \
        }                                             \
    } while(0)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond, param0, param1)             \
    do {                                              \
        if (!(cond)) {                                \
            assert_warn((int)param0, (int)param1, __MODULE__, __LINE__); \
        }                                             \
    } while(0)

#define DEBUG_TRACE(fmt, ...) \
    debug_trace(fmt, ##__VA_ARGS__)
#define DEBUG_TRACE_COND(cond, fmt, ...) do { \
    if (cond) { \
	debug_trace(fmt, ##__VA_ARGS__); \
    } \
} while(0)

#endif // CFG_PLF_DEBUG
#else // PLF_DEBUG
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_INFO(cond, param0, param1)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond, param0, param1)

#define DEBUG_TRACE(fmt, ...) do { \
    if (0) { \
	debug_trace_stub(fmt, ##__VA_ARGS__); \
    } \
} while(0)
#define DEBUG_TRACE_COND(cond, fmt, ...) do { \
    if (0) { \
	debug_trace_stub(fmt, ##__VA_ARGS__); \
    } \
} while(0)

#endif //PLF_DEBUG

// required to define GLOBAL_INT_** macros as inline assembly. This file is included after
// definition of ASSERT macros as they are used inside ll.h
#include "ll.h"     // ll definitions
/// @} DRIVERS
#endif // _ARCH_H_
