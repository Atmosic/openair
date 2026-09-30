/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/bluetooth/hci.h>

#include "ble_dtm.h"
#include "dtm_mgr.h"
#include "dtm_hci_bridge.h"

/*
 * Non-weak override of dtm_mgr_send.  The library declares this as __weak so
 * that applications (and tests) can intercept outbound DTM responses without
 * modifying library code.  This definition applies to the whole test binary.
 */
static volatile uint16_t g_last_sent;
static volatile int g_send_count;

void dtm_mgr_send(uint16_t message)
{
	g_last_sent = message;
	g_send_count++;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING_SIMULATED
	TC_PRINT("dtm_mgr_send: 0x%04x\n", message);
#endif
}

#ifdef CONFIG_DTM_2WIRE_RX_TESTING_SIMULATED

static void reset_capture(void)
{
	g_last_sent = 0;
	g_send_count = 0;
}

/* Helper: build a 16-bit DTM wire message */
static uint16_t make_msg(uint8_t cmd, uint8_t ctrl, uint8_t param)
{
	return ((uint16_t)cmd << DTM_CMD_SHIFT) | ((uint16_t)ctrl << DTM_CTRL_SHIFT) | param;
}

static void sim_rx_setup(void)
{
	int ret = dtm_mgr_init();
	zassert_equal(ret, 0, "DTM manager init should succeed");

	/* Reset the library state and discard the reset's response */
	uint16_t reset_msg = make_msg(DTM_CMD_TEST_SETUP, DTM_CTRL_RESET, 0);
	dtm_process_message(reset_msg);
	reset_capture();
}

/**
 * @brief Simulated RX mode: RX_TEST is accepted and immediately returns success
 *        without forwarding any command to the BT controller.
 */
ZTEST(dtm_simulated_rx, test_sim_rx_accepts_command)
{
	sim_rx_setup();

	uint16_t rx_msg = make_msg(DTM_CMD_RX_TEST, 19 /* channel */, 0);
	dtm_process_message(rx_msg);

	zassert_equal(g_send_count, 1, "Exactly one DTM response expected after RX_TEST");

	uint16_t expected = DTM_ASSEMBLE_STATUS_RESPONSE(0, 0);
	zassert_equal(g_last_sent, expected,
		      "Simulated RX start should send success (0x%04x), got 0x%04x", expected,
		      g_last_sent);

	/* Clean up - end the active test */
	uint16_t end_msg = make_msg(DTM_CMD_TEST_END, DTM_END_CTRL_END, DTM_END_PARAM_END);
	dtm_process_message(end_msg);
}

/**
 * @brief Simulated RX mode: TEST_END always reports 0 packets received.
 */
ZTEST(dtm_simulated_rx, test_sim_rx_test_end_zero_packets)
{
	sim_rx_setup();

	/* Start simulated RX */
	uint16_t rx_msg = make_msg(DTM_CMD_RX_TEST, 19, 0);
	dtm_process_message(rx_msg);

	/* Issue TEST_END and capture its response */
	reset_capture();
	uint16_t end_msg = make_msg(DTM_CMD_TEST_END, DTM_END_CTRL_END, DTM_END_PARAM_END);
	dtm_process_message(end_msg);

	zassert_equal(g_send_count, 1, "Exactly one DTM response expected after TEST_END");

	uint16_t expected = DTM_ASSEMBLE_PKT_REPORT(0);
	zassert_equal(g_last_sent, expected,
		      "Simulated RX end should report 0 packets (0x%04x), got 0x%04x", expected,
		      g_last_sent);
}

/**
 * @brief Simulated RX mode: a second test command while one is active returns
 *        CONTROLLER_BUSY.
 */
ZTEST(dtm_simulated_rx, test_sim_rx_controller_busy)
{
	sim_rx_setup();

	/* Start first simulated RX test */
	uint16_t rx_msg = make_msg(DTM_CMD_RX_TEST, 19, 0);
	dtm_process_message(rx_msg);

	/* Attempt to start a second RX test while the first is still active */
	reset_capture();
	dtm_process_message(rx_msg);

	zassert_equal(g_send_count, 1, "Expected one response for the busy rejection");

	/* Status response with the error bit set */
	uint16_t expected = DTM_ASSEMBLE_STATUS_RESPONSE(1, 0);
	zassert_equal(g_last_sent, expected,
		      "Second RX_TEST should return busy (0x%04x), got 0x%04x", expected,
		      g_last_sent);

	/* Clean up */
	uint16_t end_msg = make_msg(DTM_CMD_TEST_END, DTM_END_CTRL_END, DTM_END_PARAM_END);
	dtm_process_message(end_msg);
}

/**
 * @brief Simulated RX mode: multiple consecutive cycles each report success on
 *        start and 0 packets on end.
 */
ZTEST(dtm_simulated_rx, test_sim_rx_multiple_cycles)
{
	sim_rx_setup();

	uint16_t end_msg = make_msg(DTM_CMD_TEST_END, DTM_END_CTRL_END, DTM_END_PARAM_END);
	uint16_t expected_start = DTM_ASSEMBLE_STATUS_RESPONSE(0, 0);
	uint16_t expected_end = DTM_ASSEMBLE_PKT_REPORT(0);

	for (int cycle = 0; cycle < 3; cycle++) {
		TC_PRINT("Simulated RX cycle %d\n", cycle);

		/* Start */
		reset_capture();
		uint16_t rx_msg = make_msg(DTM_CMD_RX_TEST, 19 + cycle, 0);
		dtm_process_message(rx_msg);
		zassert_equal(g_send_count, 1, "Cycle %d: one response for RX_TEST", cycle);
		zassert_equal(g_last_sent, expected_start,
			      "Cycle %d: RX_TEST should return success", cycle);

		/* End */
		reset_capture();
		dtm_process_message(end_msg);
		zassert_equal(g_send_count, 1, "Cycle %d: one response for TEST_END", cycle);
		zassert_equal(g_last_sent, expected_end,
			      "Cycle %d: TEST_END should return 0-packet report", cycle);
	}
}

#endif /* CONFIG_DTM_2WIRE_RX_TESTING_SIMULATED */
