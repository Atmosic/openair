/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/sys/byteorder.h>

#include "dtm_mgr.h"
#include "dtm_hci_bridge.h"
#include "ble_dtm.h"

/* External function for testing DTM message processing */
extern void dtm_process_message(uint16_t message);

/* External references from main.c */
extern const struct device *test_get_uart_device(void);
extern bool test_uart_available(void);

/* Test state tracking */
static volatile bool reset_complete = false;
static volatile bool test_active = false;

/* Mock callback for command completion tracking */
static bool test_state_cmd_complete_cb(uint16_t opcode, const void *param_buf, uint8_t len)
{
	TC_PRINT("State test HCI Command Complete: opcode=0x%04x, len=%d\n", opcode, len);

	if (len && param_buf) {
		uint8_t status = *((uint8_t *)param_buf);
		TC_PRINT("Command status: 0x%02x\n", status);

		/* Track test state based on command completion */
		switch (opcode) {
		case BT_HCI_OP_RESET:
			if (status == BT_HCI_ERR_SUCCESS) {
				reset_complete = true;
			}
			break;
		case BT_HCI_OP_LE_ENH_TX_TEST:
		case BT_HCI_OP_LE_ENH_RX_TEST:
			if (status == BT_HCI_ERR_SUCCESS) {
				test_active = true;
			}
			break;
		case BT_HCI_OP_LE_TEST_END:
			test_active = false;
			break;
		}
	}

	return true;
}

/* Reset test state */
static void reset_state_test(void)
{
	reset_complete = false;
	test_active = false;

	/* Initialize DTM manager */
	int ret = dtm_mgr_init();
	zassert_equal(ret, 0, "DTM manager init should succeed");

	uint16_t reset_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
			     (DTM_CTRL_RESET << DTM_CTRL_SHIFT) | (0x00 << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM Reset message: 0x%04x\n", reset_msg);
	dtm_process_message(reset_msg);
}

/**
 * @brief Test HCI bridge state after initialization
 */
ZTEST(dtm_state_machine, test_hci_bridge_state)
{
	reset_state_test();

	/* Set callback */
	dtm_hci_bridge_set_cmd_complete_cb(test_state_cmd_complete_cb);

	/* Test basic HCI command */
	uint8_t cmd_ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_RESET, NULL, 0);
	zassert_equal(cmd_ret, BT_HCI_ERR_SUCCESS, "HCI Reset should succeed");
	zassert_true(reset_complete, "Reset should complete");

	/* Test Tx HCI command */
	struct bt_hci_cp_le_enh_tx_test tx_params = {.tx_ch = 0x13, /* Channel 19 (2440 MHz) */
						     .test_data_len = 0x25, /* 37 bytes */
						     .pkt_payload = BT_HCI_TEST_PKT_PAYLOAD_PRBS9,
						     .phy = BT_HCI_LE_TX_PHY_1M};

	cmd_ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_TX_TEST, (uint8_t *)&tx_params,
					  sizeof(tx_params));
	zassert_equal(cmd_ret, BT_HCI_ERR_SUCCESS, "LE Enhanced TX Test should succeed");
	zassert_true(test_active, "Test should be active after TX start");

	/* Test End HCI command */
	cmd_ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_TEST_END, NULL, 0);
	zassert_equal(cmd_ret, BT_HCI_ERR_SUCCESS, "LE Test End should succeed");
	zassert_false(test_active, "Test should be inactive after end");

	/* Test Rx HCI command */
	struct bt_hci_cp_le_enh_rx_test rx_params = {.rx_ch = 0x13, /* Channel 19 (2440 MHz) */
						     .phy = BT_HCI_LE_RX_PHY_1M,
						     .mod_index = BT_HCI_LE_MOD_INDEX_STANDARD};

	cmd_ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_RX_TEST, (uint8_t *)&rx_params,
					  sizeof(rx_params));
	zassert_equal(cmd_ret, BT_HCI_ERR_SUCCESS, "LE Enhanced RX Test should succeed");
	zassert_true(test_active, "Test should be active after RX start");

	/* Test End HCI command */
	cmd_ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_TEST_END, NULL, 0);
	zassert_equal(cmd_ret, BT_HCI_ERR_SUCCESS, "LE Test End should succeed");
	zassert_false(test_active, "Test should be inactive after end");
}

/**
 * @brief Test DTM test lifecycle - TX test with state tracking
 */
ZTEST(dtm_state_machine, test_tx_test_lifecycle)
{
	reset_state_test();

	/* Set callback for state tracking */
	dtm_hci_bridge_set_cmd_complete_cb(test_state_cmd_complete_cb);

	/* Start TX test using DTM message */
	uint8_t tx_channel = 19;
	uint8_t tx_length = 37;
	uint8_t tx_packet_type = DTM_PKT_TYPE_PRBS9;

	uint16_t tx_msg = (DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (tx_channel << DTM_CTRL_SHIFT) |
			  ((tx_length << DTM_TXRX_TEST_LEN_SHIFT) |
			   (tx_packet_type << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("Sending DTM TX Test message: 0x%04x (ch=%d, len=%d, pkt=%d)\n", tx_msg,
		 tx_channel, tx_length, tx_packet_type);
	dtm_process_message(tx_msg);

	/* Verify test is active */
	zassert_true(test_active, "Test should be active after TX start");

	/* End test using DTM message */
	uint16_t end_msg = (DTM_CMD_TEST_END << DTM_CMD_SHIFT) |
			   (DTM_END_CTRL_END << DTM_CTRL_SHIFT) |
			   (DTM_END_PARAM_END << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM Test End message: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	/* Verify test is inactive */
	zassert_false(test_active, "Test should be inactive after end");
}

/**
 * @brief Test DTM test lifecycle - RX test with state tracking
 */
ZTEST(dtm_state_machine, test_rx_test_lifecycle)
{
	reset_state_test();

	/* Set callback for state tracking */
	dtm_hci_bridge_set_cmd_complete_cb(test_state_cmd_complete_cb);

	/* Start RX test using DTM message */
	uint8_t rx_channel = 19;

	uint16_t rx_msg = (DTM_CMD_RX_TEST << DTM_CMD_SHIFT) | (rx_channel << DTM_CTRL_SHIFT) |
			  (0x00 << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM RX Test message: 0x%04x (ch=%d)\n", rx_msg, rx_channel);
	dtm_process_message(rx_msg);

	/* Verify test is active */
	zassert_true(test_active, "Test should be active after RX start");

	/* End test using DTM message */
	uint16_t end_msg = (DTM_CMD_TEST_END << DTM_CMD_SHIFT) |
			   (DTM_END_CTRL_END << DTM_CTRL_SHIFT) |
			   (DTM_END_PARAM_END << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM Test End message: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	/* Verify test is inactive */
	zassert_false(test_active, "Test should be inactive after end");
}

/**
 * @brief Test multiple test cycles using DTM messages
 */
ZTEST(dtm_state_machine, test_multiple_test_cycles)
{
	reset_state_test();

	/* End message (reused) */
	uint16_t end_msg = (DTM_CMD_TEST_END << DTM_CMD_SHIFT) |
			   (DTM_END_CTRL_END << DTM_CTRL_SHIFT) |
			   (DTM_END_PARAM_END << DTM_PARAM_SHIFT);

	/* Run multiple TX test cycles */
	for (int i = 0; i < 3; i++) {
		TC_PRINT("Test cycle %d\n", i);

		/* Start TX test with different channels */
		uint8_t channel = 19 + i; /* Channels 19, 20, 21 */
		uint16_t tx_msg = (DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (channel << DTM_CTRL_SHIFT) |
				  ((37 << DTM_TXRX_TEST_LEN_SHIFT) |
				   (DTM_PKT_TYPE_PRBS9 << DTM_TXRX_TEST_PKT_SHIFT));

		TC_PRINT("TX test cycle %d: 0x%04x (ch=%d)\n", i, tx_msg, channel);
		dtm_process_message(tx_msg);

		/* End test */
		TC_PRINT("End test cycle %d: 0x%04x\n", i, end_msg);
		dtm_process_message(end_msg);
	}
}

/**
 * @brief Test different PHY modes using DTM messages
 */
ZTEST(dtm_state_machine, test_different_phy_modes)
{
	reset_state_test();

	/* Test 1M PHY - Set PHY mode first */
	uint16_t phy_1m_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
			      (DTM_CTRL_SET_PHY_MODE << DTM_CTRL_SHIFT) |
			      (DTM_PARAM_PHY_MODE_LE_1M << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Setting 1M PHY mode: 0x%04x\n", phy_1m_msg);
	dtm_process_message(phy_1m_msg);

	/* TX test with 1M PHY */
	uint16_t tx_1m_msg =
		(DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (19 << DTM_CTRL_SHIFT) |
		((37 << DTM_TXRX_TEST_LEN_SHIFT) | (DTM_PKT_TYPE_PRBS9 << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("1M PHY TX test: 0x%04x\n", tx_1m_msg);
	dtm_process_message(tx_1m_msg);

	/* End 1M test */
	uint16_t end_msg = (DTM_CMD_TEST_END << DTM_CMD_SHIFT) |
			   (DTM_END_CTRL_END << DTM_CTRL_SHIFT) |
			   (DTM_END_PARAM_END << DTM_PARAM_SHIFT);

	TC_PRINT("End 1M test: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	/* Test 2M PHY - Set PHY mode */
	uint16_t phy_2m_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
			      (DTM_CTRL_SET_PHY_MODE << DTM_CTRL_SHIFT) |
			      (DTM_PARAM_PHY_MODE_LE_2M << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Setting 2M PHY mode: 0x%04x\n", phy_2m_msg);
	dtm_process_message(phy_2m_msg);

	/* TX test with 2M PHY */
	uint16_t tx_2m_msg =
		(DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (19 << DTM_CTRL_SHIFT) |
		((37 << DTM_TXRX_TEST_LEN_SHIFT) | (DTM_PKT_TYPE_PRBS9 << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("2M PHY TX test: 0x%04x\n", tx_2m_msg);
	dtm_process_message(tx_2m_msg);

	/* End 2M test */
	TC_PRINT("End 2M test: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	/* Test Coded PHY - Set PHY mode */
	uint16_t phy_coded_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				 (DTM_CTRL_SET_PHY_MODE << DTM_CTRL_SHIFT) |
				 (DTM_PARAM_PHY_MODE_LE_S2 << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Setting coded PHY mode: 0x%04x\n", phy_coded_msg);
	dtm_process_message(phy_coded_msg);

	/* RX test with coded PHY */
	uint16_t rx_coded_msg = (DTM_CMD_RX_TEST << DTM_CMD_SHIFT) | (19 << DTM_CTRL_SHIFT) |
				(0x00 << DTM_PARAM_SHIFT);

	TC_PRINT("Coded PHY RX test: 0x%04x\n", rx_coded_msg);
	dtm_process_message(rx_coded_msg);

	/* End coded test */
	TC_PRINT("End coded test: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);
}

/**
 * @brief Test error handling scenarios
 */
ZTEST(dtm_state_machine, test_error_handling)
{
	reset_state_test();

	/* Test invalid channel (> 39) */
	struct bt_hci_cp_le_enh_tx_test invalid_tx = {.tx_ch = 0xFF, /* Invalid channel */
						      .test_data_len = 0x25,
						      .pkt_payload = BT_HCI_TEST_PKT_PAYLOAD_PRBS9,
						      .phy = BT_HCI_LE_TX_PHY_1M};

	uint8_t cmd_ret = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_TX_TEST, (uint8_t *)&invalid_tx,
						  sizeof(invalid_tx));
	/* Command might succeed at HCI level but fail at controller level */
	/* The key is that it doesn't crash */
	TC_PRINT("Invalid channel TX test returned: 0x%02x\n", cmd_ret);
}

/**
 * @brief Test DTM message processing with native callback
 */
ZTEST(dtm_state_machine, test_dtm_message_processing)
{
	reset_state_test();

	/* Keep native callback - don't replace with test callback */
	/* This tests the actual DTM message processing and HCI command conversion */

	/* Step 1: Test Setup Reset - DTM message (0x00, 0x00, 0x00) */
	uint16_t reset_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
			     (DTM_CTRL_RESET << DTM_CTRL_SHIFT) | (0x00 << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM Reset message: 0x%04x\n", reset_msg);
	dtm_process_message(reset_msg);

	/* Step 2: TX Test - DTM message for channel 19, length 37, PRBS9 */
	uint8_t tx_channel = 19;
	uint8_t tx_length = 37;
	uint8_t tx_packet_type = DTM_PKT_TYPE_PRBS9;

	uint16_t tx_msg = (DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (tx_channel << DTM_CTRL_SHIFT) |
			  ((tx_length << DTM_TXRX_TEST_LEN_SHIFT) |
			   (tx_packet_type << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("Sending DTM TX Test message: 0x%04x (ch=%d, len=%d, pkt=%d)\n", tx_msg,
		 tx_channel, tx_length, tx_packet_type);
	dtm_process_message(tx_msg);

	/* Step 3: Test End to stop TX test */
	uint16_t end_msg = (DTM_CMD_TEST_END << DTM_CMD_SHIFT) |
			   (DTM_END_CTRL_END << DTM_CTRL_SHIFT) |
			   (DTM_END_PARAM_END << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM Test End message: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	/* Step 4: RX Test - DTM message for channel 19 */
	uint8_t rx_channel = 19;

	uint16_t rx_msg = (DTM_CMD_RX_TEST << DTM_CMD_SHIFT) | (rx_channel << DTM_CTRL_SHIFT) |
			  (0x00 << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM RX Test message: 0x%04x (ch=%d)\n", rx_msg, rx_channel);
	dtm_process_message(rx_msg);

	/* Step 5: Test End to stop RX test */
	TC_PRINT("Sending DTM Test End message: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	/* Step 6: Test Setup PHY mode - Set 2M PHY */
	uint16_t phy_2m_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
			      (DTM_CTRL_SET_PHY_MODE << DTM_CTRL_SHIFT) |
			      (DTM_PARAM_PHY_MODE_LE_2M << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Sending DTM Set 2M PHY message: 0x%04x\n", phy_2m_msg);
	dtm_process_message(phy_2m_msg);

	/* Step 7: TX Test with 2M PHY - different packet type */
	uint8_t tx_2m_packet_type = DTM_PKT_TYPE_11110000;

	uint16_t tx_2m_msg = (DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (tx_channel << DTM_CTRL_SHIFT) |
			     ((tx_length << DTM_TXRX_TEST_LEN_SHIFT) |
			      (tx_2m_packet_type << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("Sending DTM 2M TX Test message: 0x%04x (ch=%d, len=%d, pkt=%d)\n", tx_2m_msg,
		 tx_channel, tx_length, tx_2m_packet_type);
	dtm_process_message(tx_2m_msg);

	/* Step 8: Test End to stop 2M TX test */
	TC_PRINT("Sending final DTM Test End message: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	/* Step 9: Test Setup Receiver Mode - Set Stable Receiver Mode */
	uint16_t recv_mode_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				 (DTM_CTRL_SET_RECV_MODE << DTM_CTRL_SHIFT) |
				 (DTM_PARAM_RECV_ASSUME_STABLE << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Sending DTM Set Receiver Mode message: 0x%04x\n", recv_mode_msg);
	dtm_process_message(recv_mode_msg);

	/* Step 10: RX Test - Test Rx with Stable Receiver Mode */
	TC_PRINT("Sending DTM RX Test message: 0x%04x (ch=%d)\n", rx_msg, rx_channel);
	dtm_process_message(rx_msg);

	/* Step 11: Test End to stop RX test */
	TC_PRINT("Sending final DTM Test End message: 0x%04x\n", end_msg);
	dtm_process_message(end_msg);

	TC_PRINT("DTM message processing test completed\n");
	TC_PRINT("  Reset -> TX(1M,PRBS9) -> End -> RX(1M) -> End -> Set2M -> TX(2M,11110000) -> "
		 "End\n");
	TC_PRINT("  -> SetStableRx -> RX(2M,stable) -> End\n");
}

/**
 * @brief Test different packet types using DTM messages
 */
ZTEST(dtm_state_machine, test_packet_types)
{
	reset_state_test();

	uint8_t tx_channel = 19;
	uint8_t tx_length = 37;

	/* End message (reused) */
	uint16_t end_msg = (DTM_CMD_TEST_END << DTM_CMD_SHIFT) |
			   (DTM_END_CTRL_END << DTM_CTRL_SHIFT) |
			   (DTM_END_PARAM_END << DTM_PARAM_SHIFT);

	/* Test different packet types */
	uint8_t packet_types[] = {DTM_PKT_TYPE_PRBS9, DTM_PKT_TYPE_11110000, DTM_PKT_TYPE_10101010,
				  DTM_PKT_TYPE_LEC_11111111};

	const char *packet_names[] = {"PRBS9", "11110000", "10101010", "LEC_11111111"};

	for (int i = 0; i < ARRAY_SIZE(packet_types); i++) {
		TC_PRINT("Testing packet type: %s (0x%02x)\n", packet_names[i], packet_types[i]);

		/* TX test with specific packet type */
		uint16_t tx_msg = (DTM_CMD_TX_TEST << DTM_CMD_SHIFT) |
				  (tx_channel << DTM_CTRL_SHIFT) |
				  ((tx_length << DTM_TXRX_TEST_LEN_SHIFT) |
				   (packet_types[i] << DTM_TXRX_TEST_PKT_SHIFT));

		TC_PRINT("Sending DTM TX Test message: 0x%04x (ch=%d, len=%d, pkt=%s)\n", tx_msg,
			 tx_channel, tx_length, packet_names[i]);
		dtm_process_message(tx_msg);

		/* End test */
		TC_PRINT("Ending test for packet type: %s\n", packet_names[i]);
		dtm_process_message(end_msg);
	}

	TC_PRINT("All packet types tested successfully\n");
}

/**
 * @brief Test DTM control commands (Read features, PDU support, etc.)
 */
ZTEST(dtm_state_machine, test_control_commands)
{
	reset_state_test();

	/* Test different receiver modes */
	uint8_t recv_modes[] = {DTM_PARAM_RECV_ASSUME_STD, DTM_PARAM_RECV_ASSUME_STABLE};

	const char *recv_mode_names[] = {"Standard", "Stable"};

	for (int i = 0; i < ARRAY_SIZE(recv_modes); i++) {
		uint16_t recv_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				    (DTM_CTRL_SET_RECV_MODE << DTM_CTRL_SHIFT) |
				    (recv_modes[i] << DTM_PARAM_FIELD_SHIFT);

		TC_PRINT("Setting receiver mode: %s (0x%04x)\n", recv_mode_names[i], recv_msg);
		dtm_process_message(recv_msg);
	}

	/* Test Read Test Features */
	uint16_t read_feat_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				 (DTM_CTRL_READ_TEST_FEAT << DTM_CTRL_SHIFT) |
				 (DTM_PARAM_READ_TEST_FEAT_TEST_CASES << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Reading test features: 0x%04x\n", read_feat_msg);
	dtm_process_message(read_feat_msg);

	/* Test Set Length Extension */
	uint16_t set_len_ext_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				   (DTM_CTRL_SET_LEN_EXT << DTM_CTRL_SHIFT) |
				   (0x01 << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Setting length extension: 0x%04x\n", set_len_ext_msg);
	dtm_process_message(set_len_ext_msg);

	/* Test different PDU support queries */
	uint8_t pdu_types[] = {
		DTM_PARAM_READ_PDU_MAX_TX_OCTETS, DTM_PARAM_READ_PDU_MAX_TX_TIME,
		DTM_PARAM_READ_PDU_MAX_RX_OCTETS, DTM_PARAM_READ_PDU_MAX_RX_TIME,
		0x0F /* Unsupported PDU type (valid range but undefined) */
	};

	const char *pdu_type_names[] = {"Max TX Octets", "Max TX Time", "Max RX Octets",
					"Max RX Time", "Unsupported (0x0F)"};

	for (int i = 0; i < ARRAY_SIZE(pdu_types); i++) {
		uint16_t pdu_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				   (DTM_CTRL_READ_PDU_SUPP << DTM_CTRL_SHIFT) |
				   (pdu_types[i] << DTM_PARAM_FIELD_SHIFT);

		TC_PRINT("Reading PDU support: %s (0x%04x)\n", pdu_type_names[i], pdu_msg);
		dtm_process_message(pdu_msg);
	}

	TC_PRINT("All control commands tested successfully\n");
}

/**
 * @brief Test error handling with invalid DTM parameters
 */
ZTEST(dtm_state_machine, test_error_handling_invalid_params)
{
	reset_state_test();

	/* Test invalid control type for TEST_SETUP (valid range but unsupported) */
	uint16_t invalid_ctrl_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				    (0x07 << DTM_CTRL_SHIFT) | /* Invalid control (max 6-bit) */
				    (0x00 << DTM_PARAM_SHIFT);

	TC_PRINT("Testing invalid control type: 0x%04x\n", invalid_ctrl_msg);
	dtm_process_message(invalid_ctrl_msg);

	/* Test Read Test Features invalid parameter */
	uint16_t read_feat_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				 (DTM_CTRL_READ_TEST_FEAT << DTM_CTRL_SHIFT) |
				 (0x0F << DTM_PARAM_FIELD_SHIFT);

	TC_PRINT("Reading invalid test features: 0x%04x\n", read_feat_msg);
	dtm_process_message(read_feat_msg);

	/* Test invalid receiver mode parameter */
	uint16_t invalid_recv_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				    (DTM_CTRL_SET_RECV_MODE << DTM_CTRL_SHIFT) |
				    (0x0F << DTM_PARAM_FIELD_SHIFT); /* Invalid receiver mode */

	TC_PRINT("Testing invalid receiver mode: 0x%04x\n", invalid_recv_msg);
	dtm_process_message(invalid_recv_msg);

	/* Test invalid PHY mode */
	uint16_t invalid_phy_msg = (DTM_CMD_TEST_SETUP << DTM_CMD_SHIFT) |
				   (DTM_CTRL_SET_PHY_MODE << DTM_CTRL_SHIFT) |
				   (0x0F << DTM_PARAM_FIELD_SHIFT); /* Invalid PHY mode */

	TC_PRINT("Testing invalid PHY mode: 0x%04x\n", invalid_phy_msg);
	dtm_process_message(invalid_phy_msg);

	/* Test invalid channel (> 39) */
	uint16_t invalid_ch_msg =
		(DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (50 << DTM_CTRL_SHIFT) | /* Invalid channel */
		((37 << DTM_TXRX_TEST_LEN_SHIFT) | (DTM_PKT_TYPE_PRBS9 << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("Testing invalid channel: 0x%04x\n", invalid_ch_msg);
	dtm_process_message(invalid_ch_msg);

	/* Test invalid length (> 255) */
	uint16_t invalid_len_msg = (DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (19 << DTM_CTRL_SHIFT) |
				   ((0x3F << DTM_TXRX_TEST_LEN_SHIFT) | /* Max length field */
				    (DTM_PKT_TYPE_PRBS9 << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("Testing maximum length: 0x%04x\n", invalid_len_msg);
	dtm_process_message(invalid_len_msg);

	TC_PRINT("Error handling tests completed\n");
}

/**
 * @brief Test controller busy
 */
ZTEST(dtm_state_machine, test_controller_busy)
{
	reset_state_test();

	/* Test TX test with channel 19 */
	uint8_t tx_channel = 19;
	uint8_t tx_length = 37;

	uint16_t tx_msg = (DTM_CMD_TX_TEST << DTM_CMD_SHIFT) | (tx_channel << DTM_CTRL_SHIFT) |
			  ((tx_length << DTM_TXRX_TEST_LEN_SHIFT) |
			   (DTM_PKT_TYPE_PRBS9 << DTM_TXRX_TEST_PKT_SHIFT));

	TC_PRINT("Sending DTM TX Test message: 0x%04x (ch=%d, len=%d, pkt=%d)\n", tx_msg,
		 tx_channel, tx_length, DTM_PKT_TYPE_PRBS9);
	dtm_process_message(tx_msg);

	TC_PRINT("Skipping Test End to test controller busy\n");

	/* Test RX test with channel 19 */
	uint16_t rx_msg = (DTM_CMD_RX_TEST << DTM_CMD_SHIFT) | (tx_channel << DTM_CTRL_SHIFT) |
			  (0x00 << DTM_PARAM_SHIFT);

	TC_PRINT("Sending DTM RX Test message: 0x%04x (ch=%d)\n", rx_msg, tx_channel);
	dtm_process_message(rx_msg);

	TC_PRINT("Controller busy test completed\n");
}
