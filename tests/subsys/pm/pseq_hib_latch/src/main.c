/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>

#include "arch.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "power.h"
#include "reset.h"

#define HIB_TEST_DURATION_MS 2000

/* Latch bits that pseq_core_enter_hibernation() sets */
#ifdef PSEQ_CTRL0__PWM_LATCH_OPEN__MASK
#define LATCH_PWM PSEQ_CTRL0__PWM_LATCH_OPEN__MASK
#else
#define LATCH_PWM 0
#endif
#ifdef PSEQ_CTRL0__UART_LATCH_OPEN__MASK
#define LATCH_UART PSEQ_CTRL0__UART_LATCH_OPEN__MASK
#else
#define LATCH_UART 0
#endif
#ifdef PSEQ_CTRL0__PINSEL_LATCH_OPEN__MASK
#define LATCH_PINSEL PSEQ_CTRL0__PINSEL_LATCH_OPEN__MASK
#else
#define LATCH_PINSEL 0
#endif
#ifdef PSEQ_CTRL0__KSM_LATCH_OPEN__MASK
#define LATCH_KSM PSEQ_CTRL0__KSM_LATCH_OPEN__MASK
#else
#define LATCH_KSM 0
#endif
#ifdef PSEQ_CTRL0__GPIO_LATCH_OPEN__MASK
#define LATCH_GPIO PSEQ_CTRL0__GPIO_LATCH_OPEN__MASK
#else
#define LATCH_GPIO 0
#endif
#ifdef PSEQ_CTRL0__PINPU_LATCH_OPEN__MASK
#define LATCH_PINPU PSEQ_CTRL0__PINPU_LATCH_OPEN__MASK
#else
#define LATCH_PINPU 0
#endif
#ifdef PSEQ_CTRL0__I2C_LATCH_OPEN__MASK
#define LATCH_I2C PSEQ_CTRL0__I2C_LATCH_OPEN__MASK
#else
#define LATCH_I2C 0
#endif
#ifdef PSEQ_CTRL0__SPI_LATCH_OPEN__MASK
#define LATCH_SPI PSEQ_CTRL0__SPI_LATCH_OPEN__MASK
#else
#define LATCH_SPI 0
#endif

#define ALL_HIB_LATCH_BITS                                                                         \
	(LATCH_PWM | LATCH_UART | LATCH_PINSEL | LATCH_KSM | LATCH_GPIO | LATCH_PINPU |            \
	 LATCH_I2C | LATCH_SPI)

static uint32_t pseq_ctrl0_read(void)
{
	uint32_t val;

	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		val = CMSDK_PSEQ->CTRL0;
	}
	WRPR_CTRL_POP();
	return val;
}

static void trigger_hibernation(void)
{
	/* Release PM policy locks to allow hibernation */
	if (pm_policy_state_lock_is_active(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES)) {
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
	k_sleep(K_MSEC(HIB_TEST_DURATION_MS));
}

/* On cold boot: verify no latch bits set, then enter hibernation */
ZTEST(pseq_hib_latch, test_01_cold_boot)
{
	if (!is_boot_type(TYPE_POWER_ON)) {
		ztest_test_skip();
	}

	/* All latch bits should be clear on cold boot */
	uint32_t ctrl0 = pseq_ctrl0_read();
	zassert_equal(ctrl0 & ALL_HIB_LATCH_BITS, 0, "Latch bits should be 0 on cold boot");

	/* Calling release on cold boot should be a safe no-op */
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_GPIO);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_PINPU);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_PINSEL);

	trigger_hibernation();
	zassert_true(false, "System should have hibernated");
}

/* After HIB wakeup: verify latches held, release them, verify cleared */
ZTEST(pseq_hib_latch, test_02_hib_wakeup_verify_latches)
{
	if (!is_boot_type(TYPE_HIB)) {
		ztest_test_skip();
	}

	uint32_t ctrl0 = pseq_ctrl0_read();
	uint32_t latched = ctrl0 & ALL_HIB_LATCH_BITS;

	/* pseq_core_enter_hibernation() sets all latch bits.
	 * After warm reset, PSEQ survives, so they should still be set.
	 */
	zassert_not_equal(latched, 0, "Expected latch bits set after HIB wake");
	TC_PRINT("CTRL0 latched bits: %#x\n", latched);

	/* Release GPIO latch */
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_GPIO);
	ctrl0 = pseq_ctrl0_read();
	zassert_equal(ctrl0 & LATCH_GPIO, 0, "GPIO latch should be cleared");

	/* Release PINPU latch */
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_PINPU);
	ctrl0 = pseq_ctrl0_read();
	zassert_equal(ctrl0 & LATCH_PINPU, 0, "PINPU latch should be cleared");

	/* Release PINSEL latch */
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_PINSEL);
	ctrl0 = pseq_ctrl0_read();
	zassert_equal(ctrl0 & LATCH_PINSEL, 0, "PINSEL latch should be cleared");
}

/* Verify idempotency and remaining latch release */
ZTEST(pseq_hib_latch, test_03_hib_release_remaining)
{
	if (!is_boot_type(TYPE_HIB)) {
		ztest_test_skip();
	}

	/* Re-release GPIO/PINPU/PINSEL -- should be idempotent */
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_GPIO);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_PINPU);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_PINSEL);

	uint32_t ctrl0 = pseq_ctrl0_read();
	zassert_equal(ctrl0 & (LATCH_GPIO | LATCH_PINPU | LATCH_PINSEL), 0,
		      "GPIO/PINPU/PINSEL should still be cleared");

	/* Release remaining latches */
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_I2C);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_SPI);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_KSM);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_PWM);
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_UART);

	ctrl0 = pseq_ctrl0_read();
	zassert_equal(ctrl0 & ALL_HIB_LATCH_BITS, 0, "All latch bits should be cleared");
}

/* Invalid latch value should be a no-op */
ZTEST(pseq_hib_latch, test_04_invalid_latch_noop)
{
	if (!is_boot_type(TYPE_HIB)) {
		ztest_test_skip();
	}

	uint32_t ctrl0_before = pseq_ctrl0_read();
	atm_power_pseq_release_latch(ATM_PSEQ_HIB_LATCH_COUNT);
	uint32_t ctrl0_after = pseq_ctrl0_read();

	zassert_equal(ctrl0_before, ctrl0_after, "Invalid latch should not modify CTRL0");
}

ZTEST_SUITE(pseq_hib_latch, NULL, NULL, NULL, NULL, NULL);
