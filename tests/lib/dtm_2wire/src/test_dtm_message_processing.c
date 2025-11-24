/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/ztest.h>

#include "ble_dtm.h"

/* Test state tracking - no mock needed, just test the macros */
static volatile uint16_t test_message = 0;

/* Helper macros for testing - define locally to avoid modifying the module */
/* For TX/RX tests: CTRL field contains frequency (6 bits), PARAM field contains length+packet type
 */
#define TEST_DTM_TXRX_SET_FREQ(freq) ((uint8_t)(freq)) /* Frequency goes directly in CTRL field */
#define TEST_DTM_TXRX_SET_LEN_PKT(len, pkt)                                                        \
	((uint8_t)((((len) << DTM_TXRX_TEST_LEN_SHIFT) & DTM_TXRX_TEST_LEN_MASK) |                 \
		   (((pkt) << DTM_TXRX_TEST_PKT_SHIFT) & DTM_TXRX_TEST_PKT_MASK)))
#define TEST_DTM_PARAM_SET_PHY_MODE(phy)                                                           \
	((uint8_t)(((phy) << DTM_PARAM_FIELD_SHIFT) & DTM_PARAM_FIELD_MASK))
#define TEST_DTM_PARAM_SET_LEN_EXT(ext)                                                            \
	((uint8_t)(((ext) << DTM_PARAM_FIELD_SHIFT) & DTM_PARAM_FIELD_MASK))
#define TEST_DTM_ASSEMBLE_PKT_REPORT_RESPONSE(count) DTM_ASSEMBLE_PKT_REPORT(count)

/* Helper to create DTM messages */
static uint16_t create_dtm_message(uint8_t cmd, uint8_t ctrl, uint8_t param)
{
	return (cmd << DTM_CMD_SHIFT) | (ctrl << DTM_CTRL_SHIFT) | (param << DTM_PARAM_SHIFT);
}

/**
 * @brief Test DTM message parsing macros
 */
ZTEST(dtm_message_processing, test_message_parsing)
{
	uint16_t test_msg = create_dtm_message(DTM_CMD_TEST_SETUP, DTM_CTRL_RESET, 0x55);

	zassert_equal(DTM_GET_CMD(test_msg), DTM_CMD_TEST_SETUP, "Command extraction should work");
	zassert_equal(DTM_GET_CTRL(test_msg), DTM_CTRL_RESET, "Control extraction should work");
	zassert_equal(DTM_GET_PARAM(test_msg), 0x55, "Parameter extraction should work");
}

/**
 * @brief Test Test Setup Reset command
 */
ZTEST(dtm_message_processing, test_setup_reset)
{
	uint16_t reset_msg = create_dtm_message(DTM_CMD_TEST_SETUP, DTM_CTRL_RESET, 0x00);

	/* Test the message creation and parsing */
	zassert_equal(DTM_GET_CMD(reset_msg), DTM_CMD_TEST_SETUP, "Should be test setup command");
	zassert_equal(DTM_GET_CTRL(reset_msg), DTM_CTRL_RESET, "Should be reset control");
}

/**
 * @brief Test Test Setup PHY mode setting
 */
ZTEST(dtm_message_processing, test_setup_phy_mode)
{

	/* Test setting 1M PHY */
	uint16_t phy_1m_msg = create_dtm_message(DTM_CMD_TEST_SETUP, DTM_CTRL_SET_PHY_MODE,
						 DTM_PARAM_PHY_MODE_LE_1M);

	zassert_equal(DTM_GET_CMD(phy_1m_msg), DTM_CMD_TEST_SETUP, "Should be test setup command");
	zassert_equal(DTM_GET_CTRL(phy_1m_msg), DTM_CTRL_SET_PHY_MODE,
		      "Should be PHY mode control");
	zassert_equal(DTM_GET_PARAM(phy_1m_msg), DTM_PARAM_PHY_MODE_LE_1M, "Should be 1M PHY");

	/* Test setting 2M PHY */
	uint16_t phy_2m_msg = create_dtm_message(DTM_CMD_TEST_SETUP, DTM_CTRL_SET_PHY_MODE,
						 DTM_PARAM_PHY_MODE_LE_2M);

	zassert_equal(DTM_GET_PARAM(phy_2m_msg), DTM_PARAM_PHY_MODE_LE_2M, "Should be 2M PHY");

	/* Test setting Coded PHY S8 */
	uint16_t phy_s8_msg = create_dtm_message(DTM_CMD_TEST_SETUP, DTM_CTRL_SET_PHY_MODE,
						 DTM_PARAM_PHY_MODE_LE_S8);

	zassert_equal(DTM_GET_PARAM(phy_s8_msg), DTM_PARAM_PHY_MODE_LE_S8, "Should be S8 PHY");
}

/**
 * @brief Test TX Test command creation
 */
ZTEST(dtm_message_processing, test_tx_test_command)
{

	/* Create TX test message: channel 19, length 37, PRBS9 payload */
	uint8_t channel = 19;
	uint8_t length = 37;
	uint8_t packet_type = DTM_PKT_TYPE_PRBS9;

	uint16_t tx_msg = create_dtm_message(DTM_CMD_TX_TEST, TEST_DTM_TXRX_SET_FREQ(channel),
					     TEST_DTM_TXRX_SET_LEN_PKT(length, packet_type));

	zassert_equal(DTM_GET_CMD(tx_msg), DTM_CMD_TX_TEST, "Should be TX test command");
	zassert_equal(DTM_GET_TXRX_FREQ(tx_msg), channel, "Should extract correct channel");
	zassert_equal(DTM_GET_TXRX_LEN(tx_msg), length, "Should extract correct length");
	zassert_equal(DTM_GET_TXRX_PKT(tx_msg), packet_type, "Should extract correct packet type");
}

/**
 * @brief Test RX Test command creation
 */
ZTEST(dtm_message_processing, test_rx_test_command)
{

	/* Create RX test message: channel 19 */
	uint8_t channel = 19;

	uint16_t rx_msg =
		create_dtm_message(DTM_CMD_RX_TEST, TEST_DTM_TXRX_SET_FREQ(channel), 0x00);

	zassert_equal(DTM_GET_CMD(rx_msg), DTM_CMD_RX_TEST, "Should be RX test command");
	zassert_equal(DTM_GET_TXRX_FREQ(rx_msg), channel, "Should extract correct channel");
}

/**
 * @brief Test Test End command
 */
ZTEST(dtm_message_processing, test_end_command)
{

	uint16_t end_msg =
		create_dtm_message(DTM_CMD_TEST_END, DTM_END_CTRL_END, DTM_END_PARAM_END);

	zassert_equal(DTM_GET_CMD(end_msg), DTM_CMD_TEST_END, "Should be test end command");
	zassert_equal(DTM_GET_CTRL(end_msg), DTM_END_CTRL_END, "Should be end control");
	zassert_equal(DTM_GET_PARAM(end_msg), DTM_END_PARAM_END, "Should be end parameter");
}

/**
 * @brief Test status response assembly
 */
ZTEST(dtm_message_processing, test_status_response)
{

	/* Test success response - DTM_EVENT_TYPE_STATUS = 0, so bit 15 should be 0 */
	uint16_t success_response = DTM_ASSEMBLE_STATUS_RESPONSE(0, 0x1234);
	zassert_equal((success_response >> 15) & 0x1, 0,
		      "Status response should have event type bit 0");

	/* Test error response - still DTM_EVENT_TYPE_STATUS = 0, status is in bit 0 */
	uint16_t error_response = DTM_ASSEMBLE_STATUS_RESPONSE(1, 0x5678);
	zassert_equal((error_response >> 15) & 0x1, 0,
		      "Status response should have event type bit 0");
	zassert_equal(error_response & 0x1, 1, "Error should have status bit 1");
}

/**
 * @brief Test packet report assembly
 */
ZTEST(dtm_message_processing, test_packet_report)
{

	uint16_t packet_count = 1234;
	uint16_t report = TEST_DTM_ASSEMBLE_PKT_REPORT_RESPONSE(packet_count);

	/* Packet report should have event type bit 1 (DTM_EVENT_TYPE_PKT_REPORT = 1) */
	zassert_equal((report >> 15) & 0x1, 1, "Packet report should have event type bit 1");
	zassert_equal(report & 0x7FFF, packet_count, "Should contain correct packet count");
}

/**
 * @brief Test feature support bits
 */
ZTEST(dtm_message_processing, test_feature_support)
{
	/* Test individual feature bits */
	zassert_equal(DTM_SUPPORT_LENGTH_EXT_MASK, 0x0001, "Length extension bit should be 0x0001");
	zassert_equal(DTM_SUPPORT_LE_2M_PHY_MASK, 0x0002, "2M PHY bit should be 0x0002");
	zassert_equal(DTM_SUPPORT_TX_HAS_STD_MOD_IDX, 0, "Standard mod index bit should be 0");
	zassert_equal(DTM_SUPPORT_LE_CODED_PHY_MASK, 0x0008, "Coded PHY bit should be 0x0008");

	/* Test combined features */
	uint16_t all_features = DTM_SUPPORT_LENGTH_EXT_MASK | DTM_SUPPORT_LE_2M_PHY_MASK |
				DTM_SUPPORT_TX_HAS_STD_MOD_IDX | DTM_SUPPORT_LE_CODED_PHY_MASK;

	zassert_equal(all_features, 0x000B, "All features combined should be 0x000B");
}

/**
 * @brief Test parameter field extraction macros
 */
ZTEST(dtm_message_processing, test_parameter_extraction)
{
	/* Test PHY mode extraction */
	uint8_t param_with_phy = TEST_DTM_PARAM_SET_PHY_MODE(DTM_PARAM_PHY_MODE_LE_2M);
	zassert_equal(DTM_PARAM_GET_PHY_MODE(param_with_phy), DTM_PARAM_PHY_MODE_LE_2M,
		      "Should extract 2M PHY mode");

	/* Test length extension extraction */
	uint8_t param_with_len_ext = TEST_DTM_PARAM_SET_LEN_EXT(0x03);
	zassert_equal(DTM_PARAM_GET_LEN_EXT(param_with_len_ext), 0x03,
		      "Should extract length extension");
}
