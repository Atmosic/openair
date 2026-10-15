/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stddef.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/pm/policy.h>

#include "atm_vendor_internal.h"

extern struct vendor_handler const *test_find_handler(uint8_t ocf, uint8_t ogf);

/* Balance vendor_psm_config()'s policy-lock release in this minimal test. */
static void hold_psm_pm_lock(uint8_t mode)
{
#if defined(CONFIG_SOC_FAMILY_ATM) && defined(CONFIG_PM) && !defined(CONFIG_COVERAGE)
	switch (mode) {
	case PSM_DEEP:
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_IDLE, PM_ALL_SUBSTATES);
		break;
	case PSM_RETAIN:
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		break;
	case PSM_HIBERNATE:
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, 0);
		break;
	case PSM_SOC_OFF:
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, 1);
		break;
	default:
		break;
	}
#else
	ARG_UNUSED(mode);
#endif
}

/* Drive one PSM command end-to-end:
 *   psm_handler(mode)  -> stores dat.psm_cmd.psm_mode
 *   psm_cmp_handler()  -> emits HCI event and calls vendor_psm_config()
 * Returns the HCI status byte from the emitted event.
 */
static uint8_t drive_psm(uint8_t mode, uint8_t **out_evt, uint32_t *out_size)
{
	struct vendor_handler const *hdlr = test_find_handler(PSM_CMD_OCF, PSM_CMD_OGF);

	zassert_not_null(hdlr, "PSM vendor handler not registered (CFG_VND_PSM off?)");
	zassert_not_null(hdlr->cmd_hdlr, "PSM cmd_hdlr is NULL");
	zassert_not_null(hdlr->cmd_cmp_hdlr, "PSM cmd_cmp_hdlr is NULL");
	zassert_equal(hdlr->cmd_len, PSM_CMD_LEN, "PSM cmd_len mismatch");

	uint8_t payload[PSM_CMD_LEN] = {mode};

	hdlr->cmd_hdlr(payload);

	uint8_t *bufptr = NULL;
	uint32_t size = 0;

	/* vendor_psm_config(), called from cmd_cmp_hdlr(), balances the lock acquired
	 * here (if any) for this mode with a pm_policy_state_lock_put().
	 */
	hold_psm_pm_lock(mode);
	hdlr->cmd_cmp_hdlr(&bufptr, &size);
	zassert_not_null(bufptr, "psm_cmp_handler returned NULL event buffer");
	zassert_true(size >= BASIC_HCI_EVT_CMD_LEN, "psm event size %u too small", size);

	if (out_evt) {
		*out_evt = bufptr;
	}
	if (out_size) {
		*out_size = size;
	}

	return bufptr[HCI_EVT_STATUS_POS];
}

/**
 * @brief PSM_NONE is accepted; vendor_psm_config() takes the NONE branch.
 */
ZTEST(atm_vendor_psm, test_psm_none)
{
	uint8_t *evt = NULL;
	uint32_t size = 0;
	uint8_t status = drive_psm(PSM_NONE, &evt, &size);

	zassert_equal(status, HCI_EVT_SUCCESS, "PSM_NONE must return HCI_EVT_SUCCESS, got 0x%02x",
		      status);
	zassert_equal(evt[4], PSM_CMD_OCF, "OCF byte mismatch");
	zassert_equal(evt[5], PSM_CMD_OGF, "OGF byte mismatch");
}

/**
 * @brief PSM_DEEP is accepted; vendor_psm_config() locks PM_STATE_SUSPEND_TO_IDLE.
 */
ZTEST(atm_vendor_psm, test_psm_deep)
{
	uint8_t status = drive_psm(PSM_DEEP, NULL, NULL);

	zassert_equal(status, HCI_EVT_SUCCESS, "PSM_DEEP must return HCI_EVT_SUCCESS, got 0x%02x",
		      status);
}

/**
 * @brief PSM_RETAIN is accepted; vendor_psm_config() targets PM_STATE_SUSPEND_TO_RAM.
 */
ZTEST(atm_vendor_psm, test_psm_retain)
{
	uint8_t status = drive_psm(PSM_RETAIN, NULL, NULL);

	zassert_equal(status, HCI_EVT_SUCCESS, "PSM_RETAIN must return HCI_EVT_SUCCESS, got 0x%02x",
		      status);
}

/**
 * @brief PSM_HIBERNATE is accepted; vendor_psm_config() targets PM_STATE_SOFT_OFF (substate 0).
 *
 * The actual pm_policy_state_lock_put() call is compiled out under
 * CONFIG_COVERAGE to keep the DUT recoverable during gcov runs, but the case
 * label itself is still executed here.
 */
ZTEST(atm_vendor_psm, test_psm_hibernate)
{
	uint8_t status = drive_psm(PSM_HIBERNATE, NULL, NULL);

	zassert_equal(status, HCI_EVT_SUCCESS,
		      "PSM_HIBERNATE must return HCI_EVT_SUCCESS, got 0x%02x", status);
}

/**
 * @brief PSM_SOC_OFF is accepted; vendor_psm_config() targets PM_STATE_SOFT_OFF (substate 1).
 */
ZTEST(atm_vendor_psm, test_psm_soc_off)
{
	uint8_t status = drive_psm(PSM_SOC_OFF, NULL, NULL);

	zassert_equal(status, HCI_EVT_SUCCESS,
		      "PSM_SOC_OFF must return HCI_EVT_SUCCESS, got 0x%02x", status);
}

/**
 * @brief Undefined PSM modes must fall through to the default branch and be
 * rejected with HCI_EVT_ERROR. vendor_psm_config() must not act on them.
 */
ZTEST(atm_vendor_psm, test_psm_invalid_mode_rejected)
{
	const uint8_t invalid_modes[] = {3, 6, 0x7F, 0xFF};

	for (size_t i = 0; i < ARRAY_SIZE(invalid_modes); i++) {
		uint8_t status = drive_psm(invalid_modes[i], NULL, NULL);

		zassert_equal(status, HCI_EVT_ERROR, "PSM mode 0x%02x must be rejected, got 0x%02x",
			      invalid_modes[i], status);
	}
}

/**
 * @brief Every valid PSM mode is accepted when driven in sequence, exercising
 * all case labels of vendor_psm_config() in one run.
 */
ZTEST(atm_vendor_psm, test_psm_all_valid_modes_sequence)
{
	const uint8_t valid[] = {PSM_NONE, PSM_DEEP, PSM_RETAIN, PSM_HIBERNATE, PSM_SOC_OFF};

	for (size_t i = 0; i < ARRAY_SIZE(valid); i++) {
		uint8_t status = drive_psm(valid[i], NULL, NULL);

		zassert_equal(status, HCI_EVT_SUCCESS,
			      "PSM mode 0x%02x expected SUCCESS, got 0x%02x", valid[i], status);
	}
}

/**
 * @brief The emitted HCI event conforms to a Command Complete event carrying
 * the PSM opcode and one status byte payload.
 */
ZTEST(atm_vendor_psm, test_psm_hci_event_layout)
{
	uint8_t *evt = NULL;
	uint32_t size = 0;

	(void)drive_psm(PSM_NONE, &evt, &size);

	zassert_equal(evt[0], 0x04, "event should be H4 HCI EVT (0x04)");
	zassert_equal(evt[1], HCI_EVT_CMD_CPM, "event code should be CommandComplete");
	zassert_equal(evt[3], HCI_EVT_NOC, "num-of-cmd-packets byte mismatch");
	zassert_equal(evt[4], PSM_CMD_OCF, "OCF byte mismatch");
	zassert_equal(evt[5], PSM_CMD_OGF, "OGF byte mismatch");
}
