/**
 ******************************************************************************
 *
 * @file timer.h
 *
 * @brief Atmosic Timer Driver
 *
 * Copyright (C) Atmosic 2019-2025
 *
 ******************************************************************************
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#include "at_wrpr.h"

/**
 * @defgroup TIMER HW Timer APIs
 * @ingroup DRIVERS
 * @brief User driver for application to use HW timers
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Number of centisecond per second
#define CS_PER_SEC 100

/// Number of millisecond per second
#define MS_PER_SEC 1000

/// Number of millisecond per centisecond
#define MS_PER_CS 10

/// Number of microsecond per millisecond
#define US_PER_MS 1000

/// Number of second per minute
#ifndef SEC_PER_MIN
#define SEC_PER_MIN 60
#endif

/// Number of minute per hour
#ifndef MIN_PER_HOUR
#define MIN_PER_HOUR 60
#endif

/// Number of centisecond per minute
#define CS_PER_MINUTE (CS_PER_SEC * SEC_PER_MIN)

typedef enum {
    ATM_TIMER0 = 0,
    ATM_TIMER1 = 1,
    ATM_DUALTIMER1 = 2,
    ATM_DUALTIMER2 = 3,
    ATM_SYSTICK = 4,
    ATM_SLWTIMER = 5,   // Runs off 32Khz clock
    ATM_TIMERS_MAX = 6
} atm_timer_id_t;

typedef enum {
    ATM_TIMER_MODE_SINGLE_SHOT = 0,
    ATM_TIMER_MODE_PERIODIC = 1,
    ATM_TIMER_MODE_MAX = 2
} atm_timer_mode_t;

typedef enum {
   ATM_TIMER_SUCCESS = 0,
   ATM_TIMER_INVALID_PARAM = 1,
   ATM_TIMER_RESOURCE_BUSY = 2,
   ATM_TIMER_GENERIC_ERROR = 3
} atm_timer_error_t;

typedef void (*atm_timer_callback_t) (void *app_context);

/**
 * @brief Setup timer.
 * @param[in] id                Timer ID
 * @param[in] mode              SingleShot vs Periodic
 * @param[in] timeout_handler   Application layer callback handler
 *                              (called from interrupt context)
 * @return                      Success or Error status
 */
atm_timer_error_t atm_timer_setup(atm_timer_id_t id, atm_timer_mode_t mode,
                       atm_timer_callback_t timeout_handler);

/**
 * @brief Start timer.
 * @param[in] id                Timer ID
 * @param[in] timeout_us        Timer value in micro seconds
 * @param[in] app_context       Application specific context
 * @return                      Success or Error status
 */
atm_timer_error_t atm_timer_start(atm_timer_id_t id, uint32_t timeout_us,
                       void *app_context);

/**
 * @brief Start dual timer with more accurate unit.(Only for single shot mode)
 * @param[in] id                Dual timer ID
 * @param[in] timeout_cycles    Timer value in cycles
 */
void atm_dual_timer_single_shot_quick_start(atm_timer_id_t id,
    uint32_t timeout_cycles);

/**
 * @brief Stop timer.
 * @param[in] id                Timer ID
 * @return                      Success or Error status
 */
atm_timer_error_t atm_timer_stop(atm_timer_id_t id);

/**
 * @brief Busy wait using PSEQ CURRENT_REAL_TIME.
 * @param[in] msec  Delay value in milliseconds
 * @return          Success or Error status
 */
atm_timer_error_t atm_timer_mdelay(uint32_t msec);

/**
 * @brief Busy wait using the Cortex-M0 SysTick.
 * @param[in] usec  Delay value in microseconds
 * @return          Success or Error status
 */
atm_timer_error_t atm_timer_udelay(uint32_t usec);

/**
 * @brief Sleep in WFI using a timer.
 * @param[in] id    Timer ID
 * @param[in] usec  Timer value in microseconds
 * @return          Success or Error status
 */
atm_timer_error_t atm_timer_usleep(atm_timer_id_t id, uint32_t usec);

// Permit customization for restrictive calling contexts
// or to analyze rt{,1,2,3} locals
#ifndef TIMER_ASSERT_ERR
#define TIMER_ASSERT_ERR ASSERT_ERR
#endif

/**
 * @brief Get the current system time based on the 32kHz clock
 */
__STATIC_FORCEINLINE uint32_t atm_get_sys_time(void)
{
#ifdef __WRPRPINS_PSEQ_CURRENT_REAL_TIME_MACRO__
    return CMSDK_WRPR0_NONSECURE->PSEQ_CURRENT_REAL_TIME;
#else
    // The high clock domain latch low clock domain signal directly
    // would probably get bad value due to metastability. Considering
    // the combinations, it could have 3 conditions:
    // 1. bad -> good -> good
    // 2. good -> good
    // 3. good -> bad -> good -> good

    uint32_t rt;
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	GLOBAL_INT_DISABLE();
	uint32_t rt1 = CMSDK_PSEQ->CURRENT_REAL_TIME;
	rt = CMSDK_PSEQ->CURRENT_REAL_TIME;
	if (rt != rt1) {
	    uint32_t rt3 = CMSDK_PSEQ->CURRENT_REAL_TIME;
	    if (rt != rt3) {
		__UNUSED uint32_t rt2 = rt;
		rt = CMSDK_PSEQ->CURRENT_REAL_TIME;
		TIMER_ASSERT_ERR(rt == rt3);
	    }
	}
	GLOBAL_INT_RESTORE();
    } WRPR_CTRL_POP();
    return rt;
#endif
}

/**
 * @brief Fetch LP clock frequency
 *
 * @return Value in Hz
 */
__attribute__((weak)) uint32_t lpc_rcos_hz(void);

/*
 * Repeat an operation for a finite period of time.
 * Macros mimic do/while syntax:
 *
 * ATM_TIMER_DO {
 *     ...;
 * } ATM_TIMER_WHILE_LPC_DELAY(ticks);
 */
#define ATM_TIMER_DO \
    do { \
	uint32_t then = atm_get_sys_time(); \
	do {

#define ATM_TIMER_WHILE_LPC_DELAY(ticks) \
	    YIELD(); \
	} while (atm_get_sys_time() - then < (ticks)); \
    } while (0)

/**
 * @brief Busy wait using PSEQ CURRENT_REAL_TIME.
 * @param[in] ticks Delay value in counts of PSEQ CURRENT_REAL_TIME.
 * @return Success or Error status
 */
__STATIC_FORCEINLINE void atm_timer_lpc_delay(uint32_t ticks)
{
    uint32_t then = atm_get_sys_time();
    while (atm_get_sys_time() - then < ticks) {
	YIELD();
    }
}

/**
 * @brief Translate duration to LPC cycles
 * @param[in] freq In Hertz
 * @param[in] cnt Number of cycles at freq
 * @return LPC cycles
 */
static inline uint64_t atm_to_lpc(uint32_t freq, uint64_t cnt)
{
    if (lpc_rcos_hz) {
        return (cnt * lpc_rcos_hz()) / freq;
    } else {
        return (cnt * 32768) / freq;
    }
}

/**
 * @brief Translate duration to LPC cycles while rounding to nearest integer
 * @param[in] freq In Hertz
 * @param[in] cnt Number of cycles at freq
 * @return LPC cycles
 */
static inline uint64_t atm_to_lpc_round(uint32_t freq, uint64_t cnt)
{
    if (lpc_rcos_hz) {
	return ((cnt * lpc_rcos_hz()) + (freq / 2)) / freq;
    } else {
	return ((cnt * 32768) + (freq / 2)) / freq;
    }
}

/**
 * @brief Translate duration to LPC cycles while rounding up
 * @param[in] freq In Hertz
 * @param[in] cnt Number of cycles at freq
 * @return LPC cycles
 */
static inline uint64_t atm_to_lpc_round_up(uint32_t freq, uint64_t cnt)
{
    if (lpc_rcos_hz) {
	return ((cnt * lpc_rcos_hz()) + (freq - 1)) / freq;
    } else {
	return ((cnt * 32768) + (freq - 1)) / freq;
    }
}

/**
 * @brief Translate centiseconds to LPC cycles
 * @param[in] cs Number of centiseconds
 * @return LPC cycles
 */
static inline uint32_t atm_cs_to_lpc(uint32_t cs)
{
    return atm_to_lpc(CS_PER_SEC, cs);
}

/**
 * @brief Translate milliseconds to LPC cycles
 * @param[in] ms Number of milliseconds
 * @return LPC cycles
 */
static inline uint32_t atm_ms_to_lpc(uint32_t ms)
{
    return atm_to_lpc(MS_PER_SEC, ms);
}

/**
 * @brief Translate microseconds to LPC cycles
 * @param[in] us Number of microseconds
 * @return LPC cycles
 */
static inline uint32_t atm_us_to_lpc(uint64_t us)
{
    return atm_to_lpc(US_PER_MS * MS_PER_SEC, us);
}

/**
 * @brief Translate LPC cycles to duration
 * @param[in] freq In Hertz
 * @param[in] lpc Number of LPC cycles
 * @return Number of cycles at freq
 */
static inline uint64_t atm_lpc_to(uint32_t freq, uint64_t lpc)
{
    if (lpc_rcos_hz) {
        return (lpc * freq) / lpc_rcos_hz();
    } else {
        return (lpc * freq) / 32768;
    }
}

/**
 * @brief Translate LPC cycles to centiseconds
 * @param[in] lpc Number of LPC cycles
 * @return Number of centiseconds
 */
static inline uint32_t atm_lpc_to_cs(uint32_t lpc)
{
    return atm_lpc_to(CS_PER_SEC, lpc);
}

/**
 * @brief Translate LPC cycles to milliseconds
 * @param[in] lpc Number of LPC cycles
 * @return Number of milliseconds
 */
static inline uint32_t atm_lpc_to_ms(uint32_t lpc)
{
    return atm_lpc_to(MS_PER_SEC, lpc);
}

/**
 * @brief Translate LPC cycles to microseconds
 * @param[in] lpc Number of LPC cycles
 * @return Number of microseconds
 */
static inline uint64_t atm_lpc_to_us(uint32_t lpc)
{
    return atm_lpc_to(US_PER_MS * MS_PER_SEC, lpc);
}


#ifdef __cplusplus
}
#endif

/// @} TIMER

#endif // __TIMER_H__
