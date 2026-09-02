/*
 * Copyright (c) 2022-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 ******************************************************************************
 *
 * @file reset.h
 *
 * @brief Reset Driver
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup RESET RESET
 * @ingroup DRIVERS
 * @brief Reset driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Boot type
typedef enum {
    /// Power on.
    TYPE_POWER_ON,
    /// SOC Reset.
    TYPE_SOC_RESET,
    /// Wake from SOC off.
    TYPE_SOCOFF,
    /// Wake from Hibernation.
    TYPE_HIB,
    /// CPU Reset.
    TYPE_RESET,
} boot_type_t;

/// Power on reason
typedef enum {
    /// Power on.
    POWER_ON_RESET,
    /// Power on triggered by RF wake.
    POWER_ON_RFWAKE,
} boot_power_on_reason_t;

/// Reset reason
typedef enum {
    /// System reset.
    RESET_SYS,
    /// Reset by watchdog.
    RESET_WDOG,
    /// Reset by secure watchdog.
    RESET_SWDOG,
    /// Reset by LOCKUP cases.
    RESET_LOCKUP,
    /// Reset by software
    RESET_SW,
    /// External reset.
    RESET_EXT,
} boot_reset_reason_t;

/// Hibernation wakeup reason
typedef enum {
    /// Wake up from hibernation by timer.
    HIB_TIMER,
    /// Wake up from hibernation by GPIO.
    HIB_GPIO,
    /// Wake up from hibernation by WURX0.
    HIB_WURX0,
    /// Wake up from hibernation by WURX1.
    HIB_WURX1,
    /// Wake up from hibernation by QDEC.
    HIB_QDEC,
    /// Wake up from hibernation by key scan matrix.
    HIB_KSM,
    /// Wake up from hibernation by debugger.
    HIB_DBG,
    /// Wake up from hibernation by sensor hub.
    HIB_SHUB,
    /// Boot from hibernation which is triggered by SPI.
    HIB_SPI,
    /// Boot from hibernation which is triggered by I2C.
    HIB_I2C,
    /// Boot from hibernation which is triggered by PMU_TIMER.
    HIB_PMU_TIMER,
    /// Boot from hibernation which is triggered by PMU_LPCOMP.
    HIB_PMU_LPCOMP,
    /// Boot from hibernation which is triggered by ENERGY4CPU.
    HIB_ENERGY4CPU,
    /// Boot from hibernation which is triggered by ENERGY4TX.
    HIB_ENERGY4TX,
    /// Boot from hibernation which is triggered by ENDOFLIFE.
    HIB_ENDOFLIFE,
    /// Boot from hibernation which is triggered by BROWNOUT.
    HIB_BROWNOUT,
    /// Boot from hibernation which is triggered by WURX.
    HIB_WURX,
    /// Boot from hibernation which is triggered by PMU watchdog warning.
    HIB_PMU_WDOG_WARN,
    /// Boot from hibernation by BROWNOUT rising edge (brownout asserted).
    HIB_BROWNOUT_RISING,
    /// Boot from hibernation by BROWNOUT falling edge (brownout cleared).
    HIB_BROWNOUT_FALLING,
    /// Boot from hibernation by RF wake
    HIB_RFWAKE,
} boot_hib_reason_t;

/// SOC off wakeup reason
typedef enum {
    /// Wake up from SOC off by pin.
    SOCOFF_PIN,
    /// Wake up from SOC off by low power comparator.
    SOCOFF_LPCOMP,
    /// Wake up from SOC off by timer.
    SOCOFF_TIMER,
} boot_socoff_reason_t;

/// SOC reset reason
typedef enum {
    /// SOC reset by PSEQ watchdog
    SOC_RESET_PSEQ_WDOG,
    /// SOC reset by PMU watchdog
    SOC_RESET_PMU_WDOG,
    /// SOC reset by watchdog
    SOC_RESET_WDOG,
    /// SOC reset by SW request
    SOC_RESET_SW,
} boot_soc_reset_reason_t;

/// Generate reason mask
#define BOOT_MASK(reason) ((1 << (reason)) & 0xffffff)

/// Generate boot status from boot type and reason
#define BOOT_STATUS(type, mask) ((1 << (24 + (type))) + (mask))

/// Boot status: highest 8 bit is mask of boot_type_t and lowest 24 bit is mask
/// of boot_*_reason_t.
typedef enum {
    /// Reset was cold
    BOOT_STATUS_POWER_ON = BOOT_STATUS(TYPE_POWER_ON,
	BOOT_MASK(POWER_ON_RESET)),
    /// Power on triggered by RF wake
    BOOT_STATUS_POWER_ON_RFWAKE = BOOT_STATUS(TYPE_POWER_ON,
	BOOT_MASK(POWER_ON_RFWAKE)),
    /// SOC reset by PSEQ watchdog
    BOOT_STATUS_SOC_RESET_PSEQ_WDOG = BOOT_STATUS(TYPE_SOC_RESET,
	BOOT_MASK(SOC_RESET_PSEQ_WDOG)),
    /// SOC reset by PMU watchdog
    BOOT_STATUS_SOC_RESET_PMU_WDOG = BOOT_STATUS(TYPE_SOC_RESET,
	BOOT_MASK(SOC_RESET_PMU_WDOG)),
    /// SOC reset by watchdog
    BOOT_STATUS_SOC_RESET_WDOG = BOOT_STATUS(TYPE_SOC_RESET,
	BOOT_MASK(SOC_RESET_WDOG)),
    /// SOC reset by SW
    BOOT_STATUS_SOC_RESET_SW = BOOT_STATUS(TYPE_SOC_RESET,
	BOOT_MASK(SOC_RESET_SW)),
    /// System reset.
    BOOT_STATUS_RESET_SYS = BOOT_STATUS(TYPE_RESET, BOOT_MASK(RESET_SYS)),
    /// Reset by watchdog.
    BOOT_STATUS_RESET_WDOG = BOOT_STATUS(TYPE_RESET, BOOT_MASK(RESET_WDOG)),
    /// Reset by secure watchdog.
    BOOT_STATUS_RESET_SWDOG = BOOT_STATUS(TYPE_RESET, BOOT_MASK(RESET_SWDOG)),
    /// Reset by LOCKUP cases.
    BOOT_STATUS_RESET_LOCKUP = BOOT_STATUS(TYPE_RESET, BOOT_MASK(RESET_LOCKUP)),
    /// Reset by SW request.
    BOOT_STATUS_RESET_SW = BOOT_STATUS(TYPE_RESET, BOOT_MASK(RESET_SW)),
    /// Reset by external request.
    BOOT_STATUS_RESET_EXT = BOOT_STATUS(TYPE_RESET, BOOT_MASK(RESET_EXT)),
    /// Wake up from SOC off by pin.
    BOOT_STATUS_SOCOFF_WKUP_PIN = BOOT_STATUS(TYPE_SOCOFF,
	BOOT_MASK(SOCOFF_PIN)),
    /// Wake up from SOC off by low power comparator.
    BOOT_STATUS_SOCOFF_WKUP_LPCOMP = BOOT_STATUS(TYPE_SOCOFF,
	BOOT_MASK(SOCOFF_LPCOMP)),
    /// Wake up from SOC off by timer.
    BOOT_STATUS_SOCOFF_WKUP_TIMER = BOOT_STATUS(TYPE_SOCOFF,
	BOOT_MASK(SOCOFF_TIMER)),
    /// Wake up from hibernation by timer.
    BOOT_STATUS_HIB_WKUP_TIMER = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_TIMER)),
    /// Wake up from hibernation by GPIO.
    BOOT_STATUS_HIB_WKUP_GPIO = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_GPIO)),
    /// Wake up from hibernation by WURX0.
    BOOT_STATUS_HIB_WKUP_WURX0 = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_WURX0)),
    /// Wake up from hibernation by WURX1.
    BOOT_STATUS_HIB_WKUP_WURX1 = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_WURX1)),
    /// Wake up from hibernation by QDEC.
    BOOT_STATUS_HIB_WKUP_QDEC = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_QDEC)),
    /// Wake up from hibernation by key scan matrix.
    BOOT_STATUS_HIB_WKUP_KSM = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_KSM)),
    /// Wake up from hibernation by debugger.
    BOOT_STATUS_HIB_WKUP_DBG = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_DBG)),
    /// Wake up from hibernation by sensor hub.
    BOOT_STATUS_HIB_WKUP_SHUB = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_SHUB)),
    /// Boot from hibernation which is triggered by SPI
    BOOT_STATUS_HIB_WKUP_SPI = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_SPI)),
    /// Boot from hibernation which is triggered by I2C
    BOOT_STATUS_HIB_WKUP_I2C = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_I2C)),
    /// Boot from hibernation which is triggered by PMU_TIMER
    BOOT_STATUS_HIB_WKUP_PMU_TIMER =
	BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_PMU_TIMER)),
    /// Boot from hibernation which is triggered by PMU_LPCOMP
    BOOT_STATUS_HIB_WKUP_PMU_LPCOMP =
	BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_PMU_LPCOMP)),
    /// Boot from hibernation which is triggered by ENERGY4CPU
    BOOT_STATUS_HIB_WKUP_ENERGY4CPU =
	BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_ENERGY4CPU)),
    /// Boot from hibernation which is triggered by ENERGY4TX
    BOOT_STATUS_HIB_WKUP_ENERGY4TX =
	BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_ENERGY4TX)),
    /// Boot from hibernation which is triggered by ENDOFLIFE
    BOOT_STATUS_HIB_WKUP_ENDOFLIFE =
	BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_ENDOFLIFE)),
    /// Boot from hibernation which is triggered by BROWNOUT
    BOOT_STATUS_HIB_WKUP_BROWNOUT = BOOT_STATUS(TYPE_HIB,
	BOOT_MASK(HIB_BROWNOUT)),
    /// Boot from hibernation which is triggered by WURX
    BOOT_STATUS_HIB_WKUP_WURX = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_WURX)),
    /// Boot from hibernation which is triggered by PMU watchdog warning
    BOOT_STATUS_HIB_WKUP_PMU_WDOG_WARN =
	BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_PMU_WDOG_WARN)),
    /// Boot from hibernation by BROWNOUT rising edge (brownout asserted)
    BOOT_STATUS_HIB_WKUP_BROWNOUT_RISING = BOOT_STATUS(TYPE_HIB,
	BOOT_MASK(HIB_BROWNOUT_RISING)),
    /// Boot from hibernation by BROWNOUT falling edge (brownout cleared)
    BOOT_STATUS_HIB_WKUP_BROWNOUT_FALLING = BOOT_STATUS(TYPE_HIB,
	BOOT_MASK(HIB_BROWNOUT_FALLING)),
    /// Boot from hibernation by RF wake
    BOOT_STATUS_HIB_WKUP_RF = BOOT_STATUS(TYPE_HIB, BOOT_MASK(HIB_RFWAKE)),
} boot_status_t;

#ifdef CONFIG_RESET_TEST_STUB
/**
 * @brief Boot status test inputs for mocking hardware registers.
 */
struct reset_test_inputs {
    uint32_t syndrome;
    uint32_t pseq_status;
    uint32_t pseq_wdog_status;
    uint8_t pmu_wkup_det;
    bool pmu_soc_wdog_reset;
    bool pmu_pmu_wdog_reset;
};

/**
 * @brief Set the test inputs for the reset driver.
 *
 * @param inputs Pointer to the test inputs, or NULL to use real hardware.
 */
void reset_test_set_inputs(struct reset_test_inputs const *inputs);

void reset_stub_override_pseq_status(uint32_t *pseq_boot_status,
    uint32_t *pseq_wdog_status);
uint8_t reset_stub_pmu_wkup_det(uint8_t hw_val);
bool reset_stub_pmu_soc_wdog_reset(bool hw_val);
bool reset_stub_pmu_pmu_wdog_reset(bool hw_val);
#if defined(CMSDK_SYSCON) || defined(SYS_CTRL_REG)
uint32_t *reset_get_syndrome_ptr(void);
#endif
void (*reset_get_print_fn(void))(void);
uint32_t *reset_get_cached_boot_status_ptr(void);
#endif // CONFIG_RESET_TEST_STUB

/**
 * @brief Get boot status
 *
 * @return Boot status
 */
boot_status_t boot_status(void);

/**
 * @brief Judge if boot is a kind of type.
 *
 * @param[in] typ The type to be matched.
 * @return True if the type is matched.
 */
__STATIC_FORCEINLINE bool is_boot_type(boot_type_t typ)
{
    return (boot_status() & BOOT_STATUS(typ, 0));
}

/**
 * @brief Judge if boot is a kind of reason.
 *
 * @param[in] sts The reason to be matched.
 * @return True if the reason is matched.
 */
__STATIC_FORCEINLINE bool is_boot_reason(boot_status_t sts)
{
    return ((boot_status() & sts) == sts);
}

/**
 * @brief Determine if the system is booting from a state where memory is
 * unretained.
 *
 * @return True if unretained boot.
 */
__STATIC_FORCEINLINE bool is_boot_unretained(void)
{
    return (is_boot_type(TYPE_POWER_ON) || is_boot_type(TYPE_SOCOFF) ||
	is_boot_type(TYPE_RESET));
}

/**
 * @brief Determine if the variables located in the .uninit section need to be
 * assigned values due to the lost of values during boot process.
 *
 * @return True if the assignment is needed.
 */
__STATIC_FORCEINLINE bool is_boot_uninit(void)
{
    return (is_boot_type(TYPE_POWER_ON) || is_boot_type(TYPE_SOCOFF) ||
	is_boot_type(TYPE_SOC_RESET) || is_boot_type(TYPE_HIB));
}

#ifdef __cplusplus
}
#endif

/// @}
