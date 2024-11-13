/**
 *******************************************************************************
 *
 * @file atm_mcuboot_ext_uart_auth.c
 *
 * @brief Secure UART debug authentication interface driver
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "arch.h"
#include "atm_debug_auth.h"
#include "atm_mcuboot_ext_uart_auth.h"
#include "sec_debug.h"
#include "sec_assert.h"

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/device.h>
#include <zephyr/drivers/timer/system_timer.h>
#include <zephyr/drivers/watchdog.h>
#include "mcuboot_config/mcuboot_config.h"

#define GET_SYS_TIME_MS() k_uptime_get_32()

#if DT_NODE_HAS_STATUS(DT_ALIAS(watchdog0), okay)
#define UART_AUTH_WATCHDOG_DISABLE() do { \
    const struct device* wdt = DEVICE_DT_GET(DT_ALIAS(watchdog0)); \
    if (device_is_ready(wdt)) { \
        wdt_disable(wdt); \
    } \
} while(0)

#else

#define UART_AUTH_WATCHDOG_DISABLE() do { } while(0)

#endif // DT_NODE_HAS_STATUS(DT_ALIAS(watchdog0), okay)

#define UART_AUTH_WATCHDOG_ENABLE() MCUBOOT_WATCHDOG_SETUP()
#define UART_AUTH_WATCHDOG_POKE() MCUBOOT_WATCHDOG_FEED()

#define ATM_DEBUG_AUTH_SERIAL_TIMEOUT_MS \
    (CONFIG_ATM_MCUBOOT_UART_DEBUG_AUTH_TIMEOUT_MS)

#else // CONFIG_SOC_FAMILY_ATM
#include "sec_watchdog.h"
#include "timer.h"
#define GET_SYS_TIME_MS() atm_lpc_to_ms(atm_get_sys_time())

#define UART_AUTH_WATCHDOG_DISABLE() do { \
	sec_watchdog_disable();\
} while(0)

#define UART_AUTH_WATCHDOG_ENABLE() do { \
	sec_watchdog_normal();\
} while(0)

#define UART_AUTH_WATCHDOG_POKE() do { \
	sec_watchdog_poke();\
} while(0)

#endif // CONFIG_SOC_FAMILY_ATM


#ifndef ATM_DEBUG_AUTH_SERIAL_TIMEOUT_MS
#define ATM_DEBUG_AUTH_SERIAL_TIMEOUT_MS 500
#endif

// Number of message failures before authentication is aborted
#define SECURE_DEBUG_MAX_FAILURES 3

#define UART_BUF_SIZE 150
static char uart_buf[UART_BUF_SIZE];
extern unsigned char const secure_debug_key_pub_key[];
extern unsigned int const secure_debug_key_pub_key_len;

void uart_debug_auth(const struct uart_debug_auth_intf *uart_interface)
{
    if (!uart_interface->init()) {
	// Error initializing UART
	return;
    }
    bool stay_in_serial = false;
    bool auth_complete = false;
    size_t offset = 0;
    int failure_count = 0;

    // stored key is in DER format. the actual public key is the final 64 bytes
    uint8_t const *debug_key =
	secure_debug_key_pub_key + secure_debug_key_pub_key_len - 64;

    atm_debug_auth_init(debug_key, uart_interface->write
#ifndef DEBUG_AUTH_STATIC_CHALLENGE
	, uart_interface->trng_get
#endif
    );
    // Start the session
    uint32_t tstart = GET_SYS_TIME_MS();
    while (!auth_complete &&
	(stay_in_serial ||
	    GET_SYS_TIME_MS() < tstart + ATM_DEBUG_AUTH_SERIAL_TIMEOUT_MS)) {
	atm_debug_auth_result_t auth_result;
	bool full_line;
	// attempt to read a line
	size_t bytes_read = uart_interface->read(uart_buf + offset,
	    UART_BUF_SIZE - offset, &full_line);
	if (bytes_read && full_line) {
	    // we have a command, process it
	    auth_result = atm_debug_auth_parse(uart_buf, offset + bytes_read);
	    switch (auth_result) {
		case ATM_DEBUG_AUTH_RESULT_AUTHENTICATED:
		    if (sec_debug_status() == SEC_DEBUG_SOFT_DISABLED) {
			sec_debug_unlock();
		    }
		    UART_AUTH_WATCHDOG_DISABLE();
		    // From this point forward we will go into a benign state.
		    // You can use SWD to poke around and resume from
		    // WFI (via debugger) and let the system boot normally.
		    auth_complete = true;
#ifdef CONFIG_SOC_FAMILY_ATM
		    sys_clock_disable();
		    // disable all interrupts while sitting in WFI
		    for (uint8_t i = 0; i < ARRAY_SIZE(NVIC->ICER); i++) {
			NVIC->ICER[i] = 0xFFFFFFFF;
		    }
		    __set_BASEPRI(0);
		    __ISB();
		    __DSB();
		    __WFI();
#else
		    WFI();
#endif
		    UART_AUTH_WATCHDOG_ENABLE();
		    break;
		case ATM_DEBUG_AUTH_RESULT_OK:
		case ATM_DEBUG_AUTH_RESULT_INTERNAL_FAILURE:
		    stay_in_serial = true;
		    break;
		case ATM_DEBUG_AUTH_RESULT_INVALID:
		    break;
		case ATM_DEBUG_AUTH_RESULT_FAILURE:
		    SEC_ASSERT(failure_count++ > SECURE_DEBUG_MAX_FAILURES);
		    break;
		default:
		    break;
	    }
	    offset = 0;
	} else {
	    offset += bytes_read;
	}
	UART_AUTH_WATCHDOG_POKE();
    }
    uart_interface->close();
    return;
}
