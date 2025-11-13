/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/bluetooth/hci.h>

#include "dtm_hci_bridge.h"

/* External references from main.c */
extern const struct device *test_get_uart_device(void);
extern bool test_uart_available(void);

/* Test callback tracking */
static volatile bool callback_called = false;
static volatile uint16_t last_opcode = 0;
static volatile uint8_t last_status = 0;

/* Test callback function */
static bool test_cmd_complete_cb(uint16_t opcode, const void *param_buf, uint8_t len)
{
	callback_called = true;
	last_opcode = opcode;

	if (len && param_buf) {
		last_status = *((uint8_t *)param_buf);
	}

	TC_PRINT("HCI Command Complete: opcode=0x%04x, status=0x%02x, len=%d\n", opcode,
		 last_status, len);

	return true; /* Handled */
}

/* Reset test state */
static void reset_test_state(void)
{
	callback_called = false;
	last_opcode = 0;
	last_status = 0;
}

/**
 * @brief Test callback registration
 */
ZTEST(dtm_hci_bridge, test_callback_registration)
{
	/* Test setting callback */
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);

	/* Test setting NULL callback */
	dtm_hci_bridge_set_cmd_complete_cb(NULL);

	/* Restore test callback */
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);
}

/**
 * @brief Test HCI Reset command
 */
ZTEST(dtm_hci_bridge, test_hci_reset_command)
{
	reset_test_state();
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);

	uint8_t ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_RESET, NULL, 0);
	zassert_equal(ret, BT_HCI_ERR_SUCCESS, "HCI Reset should succeed, got ret=0x%02x", ret);

	/* Give some time for callback */
	k_msleep(100);

	zassert_true(callback_called, "Command complete callback should be called");
	zassert_equal(last_opcode, BT_HCI_OP_RESET, "Callback should receive correct opcode");
	zassert_equal(last_status, BT_HCI_ERR_SUCCESS, "Reset should return success status");
}

/**
 * @brief Test LE Read Max Data Length command
 */
ZTEST(dtm_hci_bridge, test_le_read_max_data_len)
{
	reset_test_state();
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);

	uint8_t ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_READ_MAX_DATA_LEN, NULL, 0);
	zassert_equal(ret, BT_HCI_ERR_SUCCESS,
		      "LE Read Max Data Len should succeed, got ret=0x%02x", ret);

	/* Give some time for callback */
	k_msleep(100);

	zassert_true(callback_called, "Command complete callback should be called");
	zassert_equal(last_opcode, BT_HCI_OP_LE_READ_MAX_DATA_LEN,
		      "Callback should receive correct opcode");
}

/**
 * @brief Test LE Enhanced TX Test command
 */
ZTEST(dtm_hci_bridge, test_le_enh_tx_test)
{
	struct bt_hci_cp_le_enh_tx_test tx_params = {.tx_ch = 0x13, /* Channel 19 (2440 MHz) */
						     .test_data_len = 0x25, /* 37 bytes */
						     .pkt_payload = BT_HCI_TEST_PKT_PAYLOAD_PRBS9,
						     .phy = BT_HCI_LE_TX_PHY_1M};

	reset_test_state();
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);

	/* First ensure any previous test is ended */
	dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_TEST_END, NULL, 0);
	k_msleep(50);

	uint8_t ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_TX_TEST, (uint8_t *)&tx_params,
					      sizeof(tx_params));
	zassert_equal(ret, BT_HCI_ERR_SUCCESS, "LE Enhanced TX Test should succeed, got ret=0x%02x",
		      ret);

	/* Give some time for callback */
	k_msleep(100);

	zassert_true(callback_called, "Command complete callback should be called");
	zassert_equal(last_opcode, BT_HCI_OP_LE_ENH_TX_TEST,
		      "Callback should receive correct opcode");

	/* Clean up - end the test */
	dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_TEST_END, NULL, 0);
	k_msleep(50);
}

/**
 * @brief Test LE Enhanced RX Test command
 */
ZTEST(dtm_hci_bridge, test_le_enh_rx_test)
{
	struct bt_hci_cp_le_enh_rx_test rx_params = {.rx_ch = 0x13, /* Channel 19 (2440 MHz) */
						     .phy = BT_HCI_LE_RX_PHY_1M,
						     .mod_index = BT_HCI_LE_MOD_INDEX_STANDARD};

	reset_test_state();
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);

	uint8_t ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_RX_TEST, (uint8_t *)&rx_params,
					      sizeof(rx_params));
	zassert_equal(ret, BT_HCI_ERR_SUCCESS, "LE Enhanced RX Test should succeed, got ret=0x%02x",
		      ret);

	/* Give some time for callback */
	k_msleep(100);

	zassert_true(callback_called, "Command complete callback should be called");
	zassert_equal(last_opcode, BT_HCI_OP_LE_ENH_RX_TEST,
		      "Callback should receive correct opcode");
}

/**
 * @brief Test LE Test End command
 */
ZTEST(dtm_hci_bridge, test_le_test_end)
{
	reset_test_state();
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);

	/* Start a test first, then end it */
	struct bt_hci_cp_le_enh_rx_test rx_params = {.rx_ch = 0x13,
						     .phy = BT_HCI_LE_RX_PHY_1M,
						     .mod_index = BT_HCI_LE_MOD_INDEX_STANDARD};

	uint8_t ret_start = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_RX_TEST, (uint8_t *)&rx_params,
						    sizeof(rx_params));
	zassert_equal(ret_start, BT_HCI_ERR_SUCCESS, "RX test start should succeed");
	k_msleep(50);

	/* Now test the Test End command */
	uint8_t ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_TEST_END, NULL, 0);
	zassert_equal(ret, BT_HCI_ERR_SUCCESS, "LE Test End should succeed, got ret=0x%02x", ret);

	/* Give some time for callback */
	k_msleep(100);

	zassert_true(callback_called, "Command complete callback should be called");
	zassert_equal(last_opcode, BT_HCI_OP_LE_TEST_END, "Callback should receive correct opcode");
}

/**
 * @brief Test multiple consecutive commands
 */
ZTEST(dtm_hci_bridge, test_multiple_commands)
{
	reset_test_state();
	dtm_hci_bridge_set_cmd_complete_cb(test_cmd_complete_cb);

	/* Send multiple commands in sequence */
	uint8_t ret1 = dtm_hci_bridge_send_cmd(BT_HCI_OP_RESET, NULL, 0);
	zassert_equal(ret1, BT_HCI_ERR_SUCCESS, "First command should succeed");

	k_msleep(50);

	uint8_t ret2 = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_READ_MAX_DATA_LEN, NULL, 0);
	zassert_equal(ret2, BT_HCI_ERR_SUCCESS, "Second command should succeed");

	k_msleep(50);

	/* Start a test first, then end it (Test End without active test may fail) */
	struct bt_hci_cp_le_enh_rx_test rx_params = {.rx_ch = 0x13,
						     .phy = BT_HCI_LE_RX_PHY_1M,
						     .mod_index = BT_HCI_LE_MOD_INDEX_STANDARD};

	uint8_t ret_start = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_RX_TEST, (uint8_t *)&rx_params,
						    sizeof(rx_params));
	zassert_equal(ret_start, BT_HCI_ERR_SUCCESS, "RX test start should succeed");

	k_msleep(50);

	uint8_t ret3 = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_TEST_END, NULL, 0);
	zassert_equal(ret3, BT_HCI_ERR_SUCCESS, "Third command should succeed");
}
