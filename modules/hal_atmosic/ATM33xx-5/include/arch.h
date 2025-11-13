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
 * Copyright (C) Atmosic 2020-2025
 *
 ****************************************************************************************
 */


#ifndef _ARCH_H_
#define _ARCH_H_

/**
 ****************************************************************************************
 * @defgroup REFIP
 * @brief Reference IP Platform
 *
 * This module contains reference platform components - REFIP.
 *
 *
 * @{
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @defgroup DRIVERS
 * @ingroup REFIP
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
#if defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)
#include "rwip_config.h"       // SW configuration
#endif

#include <stdint.h>        // standard integer definition
#include <stdbool.h>       // standard boolean definition
#include "compiler.h"      // inline functions
#include "ll.h"
#include "ARMv8MBL.h"
#include "base_addr.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "retarget_uart.h"
#undef printf
#endif

#include "rep_vec.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * CPU WORD SIZE
 ****************************************************************************************
 */
/// ARM is a 32-bit CPU
#define CPU_WORD_SIZE   4

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


#if defined(CFG_PROFILING)
#define PLF_PROFILING      1
#else //CFG_DBG
#define PLF_PROFILING      0
#endif //CFG_PROFILING

#if defined(CFG_MEM_PROTECTION)
#define PLF_MEM_PROTECTION 1
#else //CFG_DBG
#define PLF_MEM_PROTECTION 0
#endif //CFG_PROFILING

/*
 * NVDS
 ****************************************************************************************
 */

/// NVDS
#ifdef CFG_NVDS
#define PLF_NVDS             1
#else // CFG_NVDS
#define PLF_NVDS             0
#endif // CFG_NVDS


/*
 * UART
 ****************************************************************************************
 */

/// UART
#define PLF_UART             1

/// UART 2
#define PLF_UART2            0

/*
 * DMA
 ****************************************************************************************
 */

/// DMA
#define PLF_DMA            (BLE_EMB_PRESENT && BLE_ISO_PRESENT)

/*
 * SBC
 ****************************************************************************************
 */

/// SBC Generator
#define PLF_SBCGEN         (defined(CFG_SBCGEN))
/// SBC Forwarder
#define PLF_SBCFWD         (defined(CFG_BLUEBUD_TWS_TX))
/// SBC Receiver
#define PLF_SBCRX          (defined(CFG_BLUEBUD_TWS_RX))

/*
 * DEFINES
 ****************************************************************************************
 */

/// Hardware compatibility
#define CMSDK_AES       CMSDK_AES_NONSECURE
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
#define CMSDK_SHUB	CMSDK_SHUB_NONSECURE
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
#define    RESET_MEM_ALLOC_FAIL   0xF2F2F2F2
#define    RESET_WATCHDOG_ERR     0xDEDEDEDE

/// Reset platform and stay in ROM
#define    RESET_TO_ROM           0xA5A5A5A5
/// Reset platform and reload FW
#define    RESET_AND_LOAD_FW      0xC3C3C3C3

#if defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)
/// Exchange memory size limit
#if (BT_DUAL_MODE)
#define    EM_SIZE_LIMIT          0x10000
#else
#define    EM_SIZE_LIMIT          0x8000
#endif
#endif // CFG_BLE_EMB || CFG_BLE_HOST


/**
 * EM Fetch time (in us)
 *  - EM fetch: 30us (worst case at 26Mhz)
 *  - HW logic: 10us (worst case at 26Mhz)
 */
#define PLF_EM_FETCH_TIME_US        40

/**
 * EM update time (in us):
 *    - HW CS Update is 18 access
 *    - HW Tx Desc Update is 1 access
 *    - HW Rx Desc Update is 5 access
 *        => EM update at 26MHz Tx, Rx and CS is (18+1+5)*0.04*4 = 4us
 *    - HW logic: 10us (worst case)
 */
#define PLF_EM_UPDATE_TIME_US       14


/// Power saving modes
#define SLEEP_ENABLE_NONE		0
#define SLEEP_ENABLE_DEEP		1
#define SLEEP_ENABLE_RETAIN		2
#define SLEEP_ENABLE_HIBERNATE		4
#define SLEEP_ENABLE_SOC_OFF		5
#define SLEEP_ENABLE_TEST_MASK		0x80

/*
 * EXPORTED FUNCTION DECLARATION
 ****************************************************************************************
 */

/**
 * @brief System was power on boot.
 * @return true when digital domain was reset before boot
 */
bool boot_was_cold(void);

#if defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)
#ifndef RWIP_CONFIG_H_

#if (RW_DEBUG_STACK_PROF)
/**
****************************************************************************************
* @brief Initialise stack memory area.
*
* This function initialises the stack memory with pattern for use in stack profiling.
****************************************************************************************
*/
void stack_init(void);

/**
 ****************************************************************************************
 * @brief Compute size of SW stack used.
 *
 * This function is compute the maximum size stack used by SW.
 *
 * @return Size of stack used (in bytes)
 ****************************************************************************************
 */
uint16_t get_stack_usage(void);
#endif //(RW_DEBUG_STACK_PROF)

#endif // RWIP_CONFIG_H_
#endif // CFG_BLE_EMB || CFG_BLE_HOST

/**
 ****************************************************************************************
 * @brief Re-boot FW.
 *
 * This function is used to re-boot the FW when error has been detected, it is the end of
 * the current FW execution.
 * After waiting transfers on UART to be finished, and storing the information that
 * FW has re-booted by itself in a non-loaded area, the FW restart by branching at FW
 * entry point.
 *
 * Note: when calling this function, the code after it will not be executed.
 *
 * @param[in] error      Error detected by FW
 ****************************************************************************************
 */
__NORETURN void platform_reset(uint32_t error);

/**
 * @brief User application main function
 * @returns nothing - ignored
 */
int user_main(void);

/**
 * @brief RW main function.
 *
 * This function is called right after user_main().
 */
void rw_main(void);

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
__PRINTF(1, 2) int debug_trace(const char *format, ...);

#if (defined(CFG_PROFILING))
/**
 ****************************************************************************************
 * @brief Trace enter into a function
 *
 * @param[in] p_func_ptr Pointer of the function
 * @param[in] p_func_name_ptr Pointer of the function name
 ****************************************************************************************
 */
void func_enter(const void* p_func_ptr, const void* p_func_name_ptr);

/**
 ****************************************************************************************
 * @brief Trace exit of a function
 *
 * @param[in] p_func_ptr      Pointer of the function
 * @param[in] p_func_name_ptr Pointer of the function name
 ****************************************************************************************
 */
void func_exit(const void* p_func_ptr, const void* p_func_name_ptr);

/**
 ****************************************************************************************
 * @brief Trace data into a VCD
 *
 * @param[in] p_ptr      Data pointer address
 * @param[in] p_name_ptr Data variable name pointer address
 * @param[in] data_size  Size of data to trace in bytes (8, 16 or 32 only)
 ****************************************************************************************
 */
void data_trace(const void* p_ptr, const void* p_name_ptr, uint8_t data_size);

#endif // (defined(CFG_PROFILING))

#if (defined(CFG_MEM_LEAK_DETECT))
/**
 ****************************************************************************************
 * @brief Trace data pointer allocation
 *
 * @param[in] p_ptr Data pointer address
 ****************************************************************************************
 */
void data_trace_alloc(const void* p_ptr, const char* filename, uint16_t line);

/**
 ****************************************************************************************
 * @brief Trace data pointer free
 *
 * @param[in] p_ptr Data pointer address
 ****************************************************************************************
 */
void data_trace_free(const void* p_ptr);

#endif // (defined(CFG_MEM_LEAK_DETECT))

#if (defined(CFG_MEM_PROTECTION))
/**
 ****************************************************************************************
 * @brief Control memory access
 *
 * @param[in] p_mem_ptr Pointer to memory block
 * @param[in] enable    True to grant complete access on memory block, False to flow memory permissions
 ****************************************************************************************
 */
void mem_grant_access_ctrl(const void* p_mem_ptr, bool enable);


/**
 ****************************************************************************************
 * @brief Set permission onto a specific memory block
 *
 * @param[in] p_mem_ptr Pointer to memory block
 * @param[in] size      Size of the memory block
 * @param[in] write_en  True to enable write permission, False to disable write
 * @param[in] read_en   True to enable read permission, False to disable read
 * @param[in] init_clr  True to mark memory block not initialized, False: no action
 ****************************************************************************************
 */
void mem_perm_set(const void* p_mem_ptr, uint16_t size, bool write_en, bool read_en, bool init_clr);

/**
 ****************************************************************************************
 * @brief Mark memory block initialized - without modifying memory data
 *
 * @param[in] p_mem_ptr Pointer to memory block
 * @param[in] size      Size of the memory block
 ****************************************************************************************
 */
void mem_init(const void* p_mem_ptr, uint16_t size);

/// Store memory protection grant context
void mem_grant_store_context(void);
/// Restore memory protection grant context
void mem_grant_restore_context(void);
#endif // (defined(CFG_MEM_PROTECTION))

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

/// DUMP HCI packet
#define DUMP_HCI(type, direction, data, length)\
    dump_hci(type, direction, (uint8_t*)data, length, NULL, 0)

/// DUMP HCI packet
#define DUMP_HCI_2(type, direction, hdr_data, hdr_length, data, length)\
    dump_hci(type, direction, (uint8_t*)data, length, (uint8_t*)hdr_data, hdr_length)

/// DUMP HCI packet in unpacked format
#define DUMP_UPK_HCI(evttype, direction, code, data, length)\
    dump_upk_hci(evttype, direction, code, (uint8_t*)data, length)

#define DEBUG_TRACE(fmt, ...)\
    debug_trace(fmt, ##__VA_ARGS__)
#define DEBUG_TRACE_COND(cond, fmt, ...)\
    do {\
	if (cond) {\
	    debug_trace(fmt, ##__VA_ARGS__);\
	}\
    } while(0)
#endif // CFG_PLF_DEBUG
#else // PLF_DEBUG
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_INFO(cond, param0, param1)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond, param0, param1)

/// DUMP HCI packet
#define DUMP_HCI(type, direction, data, length)
/// DUMP HCI packet
#define DUMP_HCI_2(type, direction, hdr_data, hdr_length, data, length)
/// DUMP HCI packet in unpacked format
#define DUMP_UPK_HCI(evttype, direction, code, data, length)

#define DEBUG_TRACE(fmt, ...) do { \
    if (0) { \
	debug_trace(fmt, ##__VA_ARGS__); \
    } \
} while(0)
#define DEBUG_TRACE_COND(cond, fmt, ...) do { \
    if (0) { \
	debug_trace(fmt, ##__VA_ARGS__); \
    } \
} while(0)

#endif //PLF_DEBUG

#if (defined(CFG_PROFILING))
/// Trace data into a VCD
#define DBG_DATA_TRACE(data, size) data_trace(&data, #data, size)

/// Trace Function Enter
#define DBG_FUNC_ENTER(func) func_enter(func, #func)

/// Trace Function Exit
#define DBG_FUNC_EXIT(func) func_exit(func, #func)
#else
/// Trace data into a VCD
#define DBG_DATA_TRACE(data, size)
/// Trace Function Enter
#define DBG_FUNC_ENTER(func)
/// Trace Function Exit
#define DBG_FUNC_EXIT(func)
#endif // (defined(CFG_PROFILING))

#if (defined(CFG_MEM_LEAK_DETECT))
/// Trace data allocation
#define DBG_DATA_ALLOC(data, filename, line) data_trace_alloc(data, filename, line)
/// Trace data free
#define DBG_DATA_FREE(data) data_trace_free(data)
#else
/// Trace data allocation
#define DBG_DATA_ALLOC(...)
/// Trace data free
#define DBG_DATA_FREE(data)
#endif // (defined(CFG_MEM_LEAK_DETECT))

#if (defined(CFG_MEM_PROTECTION))
/// Control memory access
#define DBG_MEM_GRANT_CTRL(mem_ptr, enable) mem_grant_access_ctrl(mem_ptr, enable)
/// Set permission onto a specific memory block
#define DBG_MEM_PERM_SET(mem_ptr, size, write_en, read_en, init_clr) mem_perm_set(mem_ptr, size, write_en, read_en, init_clr)
/// Mark memory initialized
#define DBG_MEM_INIT(mem_ptr, size) mem_init(mem_ptr, size)
/// Store grant context when executing ISR
#define DBG_MEM_ISR_ENTER() mem_grant_store_context()
/// Restore grant context when ISR execution is over
#define DBG_MEM_ISR_EXIT() mem_grant_restore_context()
#else // !(defined(CFG_MEM_PROTECTION))
/// Control memory access
#define DBG_MEM_GRANT_CTRL(mem_ptr, enable)
/// Set permission onto a specific memory block
#define DBG_MEM_PERM_SET(mem_ptr, size, write_en, read_en, init_clr)
/// Mark memory initialized
#define DBG_MEM_INIT(mem_ptr, size)
#define DBG_MEM_ISR_ENTER()
#define DBG_MEM_ISR_EXIT()
#endif // (defined(CFG_MEM_PROTECTION))

#ifdef __cplusplus
}
#endif

// required to define GLOBAL_INT_** macros as inline assembly. This file is included after
// definition of ASSERT macros as they are used inside ll.h
#include "ll.h"     // ll definitions
/// @} DRIVERS
#endif // _ARCH_H_
