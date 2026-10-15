/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stddef.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>

#include "atm_vendor_internal.h"

extern struct vendor_handler const *test_find_handler(uint8_t ocf, uint8_t ogf);

/* An absolute pin number beyond every supported GPIO bank makes
 * atm_io_ctrl_get_dev() fail, so gpio_self_test() returns false and the
 * command is reported as failed. Deterministic without external wiring.
 */
#define GPIO_INVALID_PIN 0xFF

/* Drive one GPIO self test command end-to-end:
 *   gpio_self_test_handler(payload) -> runs gpio_self_test() over the pairs
 *   gpio_self_test_cmp_handler()    -> emits the HCI Command Complete event
 * Returns the HCI status byte from the emitted event.
 */
static uint8_t drive_gpio_self_test(uint8_t const *payload, uint8_t **out_evt, uint32_t *out_size)
{
	struct vendor_handler const *hdlr =
		test_find_handler(GPIO_SELF_TEST_CMD_OCF, GPIO_SELF_TEST_CMD_OGF);

	zassert_not_null(hdlr, "GPIO self test handler not registered (CFG_VND_GPIO_TEST off?)");
	zassert_not_null(hdlr->cmd_hdlr, "GPIO self test cmd_hdlr is NULL");
	zassert_not_null(hdlr->cmd_cmp_hdlr, "GPIO self test cmd_cmp_hdlr is NULL");

	hdlr->cmd_hdlr(payload);

	uint8_t *bufptr = NULL;
	uint32_t size = 0;

	hdlr->cmd_cmp_hdlr(&bufptr, &size);
	zassert_not_null(bufptr, "gpio_self_test_cmp_handler returned NULL event buffer");
	zassert_true(size >= BASIC_HCI_EVT_CMD_LEN, "gpio event size %u too small", size);

	if (out_evt) {
		*out_evt = bufptr;
	}
	if (out_size) {
		*out_size = size;
	}

	return bufptr[HCI_EVT_STATUS_POS];
}

/**
 * @brief The GPIO self test handler is registered with the expected opcode and
 * an unchecked command length (variable-length pair list).
 */
ZTEST(atm_vendor_gpio, test_gpio_self_test_handler_registered)
{
	struct vendor_handler const *hdlr =
		test_find_handler(GPIO_SELF_TEST_CMD_OCF, GPIO_SELF_TEST_CMD_OGF);

	zassert_not_null(hdlr, "GPIO self test handler must be registered");
	zassert_equal(hdlr->ocf, GPIO_SELF_TEST_CMD_OCF, "OCF mismatch");
	zassert_equal(hdlr->ogf, GPIO_SELF_TEST_CMD_OGF, "OGF mismatch");
	zassert_false(hdlr->check_cmd_len, "GPIO self test must not validate cmd_len");
	zassert_equal(hdlr->cmd_len, GPIO_SELF_TEST_CMD_LEN, "GPIO self test cmd_len mismatch");
}

/**
 * @brief Zero pairs performs no GPIO access and must return HCI_EVT_SUCCESS.
 */
ZTEST(atm_vendor_gpio, test_gpio_self_test_zero_pairs_success)
{
	const uint8_t payload[] = {0};
	uint8_t status = drive_gpio_self_test(payload, NULL, NULL);

	zassert_equal(status, HCI_EVT_SUCCESS,
		      "zero-pair GPIO self test must return HCI_EVT_SUCCESS, got 0x%02x", status);
}

/**
 * @brief A pin pair that cannot map to any GPIO bank makes gpio_self_test()
 * fail, so the command must be rejected with HCI_EVT_ERROR.
 */
ZTEST(atm_vendor_gpio, test_gpio_self_test_invalid_pin_rejected)
{
	const uint8_t payload[] = {1, GPIO_INVALID_PIN, GPIO_INVALID_PIN};
	uint8_t status = drive_gpio_self_test(payload, NULL, NULL);

	zassert_equal(status, HCI_EVT_ERROR,
		      "invalid-pin GPIO self test must return HCI_EVT_ERROR, got 0x%02x", status);
}

/**
 * @brief A valid pin pair exercises the full configure/drive/read path. The
 * pass/fail outcome depends on external wiring, so only a well-formed event
 * carrying a defined status is asserted.
 */
ZTEST(atm_vendor_gpio, test_gpio_self_test_valid_pins_wellformed)
{
	const uint8_t payload[] = {1, 0, 1};
	uint8_t *evt = NULL;
	uint32_t size = 0;
	uint8_t status = drive_gpio_self_test(payload, &evt, &size);

	zassert_true(status == HCI_EVT_SUCCESS || status == HCI_EVT_ERROR,
		     "GPIO self test status must be SUCCESS or ERROR, got 0x%02x", status);
	zassert_equal(evt[4], GPIO_SELF_TEST_CMD_OCF, "OCF byte mismatch");
	zassert_equal(evt[5], GPIO_SELF_TEST_CMD_OGF, "OGF byte mismatch");
}

/**
 * @brief The emitted HCI event conforms to a Command Complete event carrying
 * the GPIO self test opcode.
 */
ZTEST(atm_vendor_gpio, test_gpio_self_test_hci_event_layout)
{
	const uint8_t payload[] = {0};
	uint8_t *evt = NULL;
	uint32_t size = 0;

	(void)drive_gpio_self_test(payload, &evt, &size);

	zassert_equal(evt[0], 0x04, "event should be H4 HCI EVT (0x04)");
	zassert_equal(evt[1], HCI_EVT_CMD_CPM, "event code should be CommandComplete");
	zassert_equal(evt[3], HCI_EVT_NOC, "num-of-cmd-packets byte mismatch");
	zassert_equal(evt[4], GPIO_SELF_TEST_CMD_OCF, "OCF byte mismatch");
	zassert_equal(evt[5], GPIO_SELF_TEST_CMD_OGF, "OGF byte mismatch");
}
