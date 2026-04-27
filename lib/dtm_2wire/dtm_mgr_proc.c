/**
 *******************************************************************************
 *
 * @file dtm_mgr_proc.c
 *
 * @brief DTM command processing for Zephyr
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/hci.h>
#include <string.h>

#include "ble_dtm.h"
#include "dtm_mgr.h"
#define DTM_MGR_INTERNAL_GUARD
#include "dtm_mgr.ih"
#include "dtm_hci_bridge.h"
#include "rf_api.h"

LOG_MODULE_REGISTER(dtm_mgr_proc, CONFIG_DTM_2WIRE_LOG_LEVEL);

#ifdef CONFIG_DTM_2WIRE_EXT
#define MAX_SUP_PHY_MODE DTM_PARAM_PHY_MODE_MAX
#else
#define MAX_SUP_PHY_MODE DTM_PARAM_PHY_MODE_LE_1M
#endif

// State for the DTM command processor
struct dtm_state {
	uint8_t length_ext; // current length extension bits
	uint8_t phy_mode;   // current PHY mode
	bool test_active;   // tx or rx test is active
	int8_t tx_pwr_lvl;  // transmitter power level in dBm
	uint16_t max_tx_octets;
	uint16_t max_tx_time;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	uint8_t rx_mod_idx; // current modulation index
	uint16_t max_rx_octets;
	uint16_t max_rx_time;
#endif
};

static struct dtm_state dtm_env = {
	.phy_mode = DTM_PARAM_PHY_MODE_LE_1M,
	.tx_pwr_lvl = BT_HCI_TX_TEST_POWER_MAX_SET, // Default to maximum power
	.max_tx_octets = BT_HCI_LE_MAX_TX_OCTETS_MAX,
	.max_tx_time = BT_HCI_LE_MAX_TX_TIME_MAX,
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	.rx_mod_idx = DTM_PARAM_RECV_ASSUME_STD,
	.max_rx_octets = BT_HCI_LE_MAX_RX_OCTETS_MAX,
	.max_rx_time = BT_HCI_LE_MAX_RX_TIME_MAX,
#endif
};

void dtm_set_data_len_caps(uint16_t max_tx_octets, uint16_t max_tx_time, uint16_t max_rx_octets,
			   uint16_t max_rx_time)
{
	dtm_env.max_tx_octets = max_tx_octets;
	dtm_env.max_tx_time = max_tx_time;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	dtm_env.max_rx_octets = max_rx_octets;
	dtm_env.max_rx_time = max_rx_time;
#endif
}

static uint8_t dtm_get_pdu_support_info(uint8_t type, uint16_t *value)
{
	switch (type) {
	case DTM_PARAM_READ_PDU_MAX_TX_OCTETS:
		*value = dtm_env.max_tx_octets;
		break;
	case DTM_PARAM_READ_PDU_MAX_TX_TIME:
		*value = dtm_env.max_tx_time / 2; /* per Part F 3.3.1: units are time/2 */
		break;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	case DTM_PARAM_READ_PDU_MAX_RX_OCTETS:
		*value = dtm_env.max_rx_octets;
		break;
	case DTM_PARAM_READ_PDU_MAX_RX_TIME:
		*value = dtm_env.max_rx_time / 2; /* per Part F 3.3.1: units are time/2 */
		break;
#else
	case DTM_PARAM_READ_PDU_MAX_RX_OCTETS:
		// fall through
	case DTM_PARAM_READ_PDU_MAX_RX_TIME:
		*value = 0;
		break;
#endif
	default:
		*value = 0;
		return BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
	}

	return BT_HCI_ERR_SUCCESS;
}

// Handle test setup command
static uint8_t dtm_test_setup_handler(uint8_t ctrl, uint8_t param, uint16_t *response,
				      bool *defer_status)
{
	uint8_t status = BT_HCI_ERR_SUCCESS;

	LOG_DBG("DTM ctl: 0x%x, param: 0x%x", ctrl, param);

	switch (ctrl) {
	case DTM_CTRL_RESET: {
		dtm_env.phy_mode = DTM_PARAM_PHY_MODE_LE_1M;
		dtm_env.length_ext = 0;
		dtm_env.tx_pwr_lvl = BT_HCI_TX_TEST_POWER_MAX_SET;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
		dtm_env.rx_mod_idx = DTM_PARAM_RECV_ASSUME_STD;
#endif
		dtm_hci_bridge_send_cmd(BT_HCI_OP_RESET, NULL, 0);
		// Need to defer status until command completion received
		*defer_status = true;
	} break;
#ifdef CONFIG_DTM_2WIRE_EXT
	case DTM_CTRL_SET_LEN_EXT: {
		dtm_env.length_ext = DTM_PARAM_GET_LEN_EXT(param);
	} break;
#endif
	case DTM_CTRL_SET_PHY_MODE: {
		if (DTM_PARAM_GET_PHY_MODE(param) > MAX_SUP_PHY_MODE) {
			status = BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
			break;
		}
		dtm_env.phy_mode = DTM_PARAM_GET_PHY_MODE(param);
	} break;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	case DTM_CTRL_SET_RECV_MODE: {
		if (DTM_PARAM_GET_RECV_MOD_IDX(param) > DTM_PARAM_RECV_ASSUME_STABLE) {
			status = BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
			break;
		}
		dtm_env.rx_mod_idx = DTM_PARAM_GET_RECV_MOD_IDX(param);
	} break;
#endif
	case DTM_CTRL_READ_TEST_FEAT: {
		if (DTM_PARAM_READ_TEST_FEAT_TEST_CASES ==
		    DTM_PARAM_GET_READ_TEST_FEAT_TYPE(param)) {
			*response = DTM_SUPPORT_TX_HAS_STD_MOD_IDX |
#ifdef CONFIG_DTM_2WIRE_EXT
				    DTM_SUPPORT_LENGTH_EXT_MASK | DTM_SUPPORT_LE_2M_PHY_MASK |
				    DTM_SUPPORT_LE_CODED_PHY_MASK |
#endif
				    0;
		} else {
			status = BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
		}
	} break;
	case DTM_CTRL_READ_PDU_SUPP: {
		status = dtm_get_pdu_support_info(DTM_PARAM_GET_PDU_SUP_TYPE(param), response);
	} break;
	case DTM_CTRL_SET_TX_PWR_LVL: {
		int8_t tx_pwr = DTM_PARAM_GET_TX_PWR_LVL(param);

		/* Validate TX power range */
		if (tx_pwr != DTM_TX_PWR_LVL_MIN_SET && tx_pwr != DTM_TX_PWR_LVL_MAX_SET &&
		    (tx_pwr < DTM_TX_PWR_LVL_MIN_DBM || tx_pwr > DTM_TX_PWR_LVL_MAX_DBM)) {
			status = BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
			break;
		}

		/* Convert special values to actual dBm */
		if (tx_pwr == DTM_TX_PWR_LVL_MIN_SET) {
			dtm_env.tx_pwr_lvl = DTM_TX_PWR_LVL_MIN_DBM;
		} else if (tx_pwr == DTM_TX_PWR_LVL_MAX_SET) {
			dtm_env.tx_pwr_lvl = DTM_TX_PWR_LVL_MAX_DBM;
		} else {
			dtm_env.tx_pwr_lvl = tx_pwr;
		}

		LOG_DBG("DTM TX power level set to: %d dBm", dtm_env.tx_pwr_lvl);
	} break;
	default: {
		status = BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
	} break;
	}

	if (status != BT_HCI_ERR_SUCCESS) {
		LOG_ERR("DTM error! ctrl, param: 0x%x, 0x%x", ctrl, param);
	}

	return status;
}

static uint8_t send_le_tx_test(struct bt_hci_cp_le_enh_tx_test *tx_params)
{
	LOG_DBG("DTM TX test chan:%d, len:%d, pk_type:%d, phy:%d, tx_pwr:%d dBm", tx_params->tx_ch,
		tx_params->test_data_len, tx_params->pkt_payload, tx_params->phy,
		dtm_env.tx_pwr_lvl);

	/* Set TX power using RF driver before starting TX test */
	rf_set_txpwr_override(dtm_env.tx_pwr_lvl);

	return dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_TX_TEST, (uint8_t *)tx_params,
				       sizeof(*tx_params));
}

#ifdef CONFIG_DTM_2WIRE_RX_TESTING
static uint8_t send_le_rx_test(struct bt_hci_cp_le_enh_rx_test *rx_params)
{
	LOG_DBG("DTM RX test chan:%d, phy:%d, mod_idx:%d", rx_params->rx_ch, rx_params->phy,
		rx_params->mod_index);
	return dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_ENH_RX_TEST, (uint8_t *)rx_params,
				       sizeof(*rx_params));
}
#endif

union le_txrx_test_params {
	struct bt_hci_cp_le_enh_tx_test tx;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	struct bt_hci_cp_le_enh_rx_test rx;
#endif
};

static uint8_t dtm_start_txrx_test(uint8_t chan, uint8_t length, uint8_t pkt_type, uint8_t phy_mode,
				   bool tx)
{
	union le_txrx_test_params test_params;
	uint8_t status = BT_HCI_ERR_SUCCESS;

	LOG_DBG("DTM txrx c:%d,l:%d,pk:%d,ph:%d,tx:%d", chan, length, pkt_type, phy_mode, tx);
	memset(&test_params, 0, sizeof(test_params));

	// From the DTM spec (vol F, 3.3.2) the PHY modes map directly to
	// the HCI enhanced LE RX/TX test PHY rates in sections 7.8.50
	// and 7.8.51. LLD's PHY mode setting is based on the HCI enhanced
	// LE test definitions. For RX, LE_S8 is equivalent to PHY_CODED in
	// the HCI enhanced RX test (see 7.8.50)
	if (tx) {
		test_params.tx.tx_ch = chan;
		test_params.tx.phy = phy_mode;
	}
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	else {
		test_params.rx.rx_ch = chan;
		test_params.rx.phy = phy_mode;
	}
#endif

#ifdef CONFIG_DTM_2WIRE_EXT
	if (phy_mode == DTM_PARAM_PHY_MODE_LE_S2 && !tx) {
		// for RX, S8/S2 are the same (LE CODED).  Host should not ask
		// for S2 in the RX test, but just in case map this PHY to S8
		// (legal value).
		test_params.rx.phy = DTM_PARAM_PHY_MODE_LE_S8;
	}
#endif

	if (tx) {
		uint8_t payload_type;
		test_params.tx.test_data_len = length;

		switch (pkt_type) {
		case DTM_PKT_TYPE_PRBS9: {
			payload_type = BT_HCI_TEST_PKT_PAYLOAD_PRBS9;
		} break;
		case DTM_PKT_TYPE_11110000: {
			payload_type = BT_HCI_TEST_PKT_PAYLOAD_11110000;
		} break;
		case DTM_PKT_TYPE_10101010: {
			payload_type = BT_HCI_TEST_PKT_PAYLOAD_10101010;
		} break;
		case DTM_PKT_TYPE_LEC_11111111: {
			payload_type = BT_HCI_TEST_PKT_PAYLOAD_11111111;
		} break;
		default: {
			payload_type = BT_HCI_TEST_PKT_PAYLOAD_PRBS9;
		} break;
		}
		test_params.tx.pkt_payload = payload_type;
	}
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	else {
		if (dtm_env.rx_mod_idx == DTM_PARAM_RECV_ASSUME_STD) {
			test_params.rx.mod_index = BT_HCI_LE_MOD_INDEX_STANDARD;
		} else {
			test_params.rx.mod_index = BT_HCI_LE_MOD_INDEX_STABLE;
		}
	}
#endif

	if (tx) {
		LOG_DBG("DTM starting TX test!");
		status = send_le_tx_test(&test_params.tx);
	}
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	else {
		LOG_DBG("DTM starting RX test!");
		status = send_le_rx_test(&test_params.rx);
	}
#endif
	return status;
}

static void dtm_send_test_status_evt(uint8_t status, uint16_t response)
{
	uint16_t message =
		DTM_ASSEMBLE_STATUS_RESPONSE((status == BT_HCI_ERR_SUCCESS) ? 0 : 1, response);
	LOG_DBG("DTM send status: 0x%x, resp: 0x%x => msg: 0x%x", status, response, message);
	dtm_mgr_send(message);
}

static void dtm_send_pkt_report_evt(uint16_t count)
{
	uint16_t message = DTM_ASSEMBLE_PKT_REPORT(count);
	LOG_DBG("DTM send pkt rpt: cnt: %d => msg: 0x%x", count, message);
	dtm_mgr_send(message);
}

void dtm_process_message(uint16_t message)
{
	uint8_t command;
	uint8_t status = BT_HCI_ERR_SUCCESS;
	uint16_t response = 0;
	bool defer_status = false;

	command = DTM_GET_CMD(message);

	LOG_DBG("DTM ++++");
	LOG_DBG("DTM rx msg: 0x%x, cmd:%d", message, command);

	switch (command) {
	case DTM_CMD_TEST_SETUP: {
		status = dtm_test_setup_handler(DTM_GET_CTRL(message), DTM_GET_PARAM(message),
						&response, &defer_status);
	} break;
#ifdef CONFIG_DTM_2WIRE_RX_TESTING
	case DTM_CMD_RX_TEST:
#endif
	case DTM_CMD_TX_TEST: {
		if (dtm_env.test_active) {
			status = BT_HCI_ERR_CONTROLLER_BUSY;
			break;
		}
		uint8_t pkt_length =
			DTM_GET_TXRX_LEN(message) | (dtm_env.length_ext << DTM_LEN_EXT_SHIFT);
		status = dtm_start_txrx_test(DTM_GET_TXRX_FREQ(message), pkt_length,
					     DTM_GET_TXRX_PKT(message), dtm_env.phy_mode,
					     (command == DTM_CMD_TX_TEST));
		if (status == BT_HCI_ERR_SUCCESS) {
			// defer until dtm_test_start_complete()
			defer_status = true;
		}
	} break;
	case DTM_CMD_TEST_END: {
		status = dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_TEST_END, NULL, 0);
		if (status == BT_HCI_ERR_SUCCESS) {
			// defer until dtm_test_end()
			defer_status = true;
		}
	} break;
	default: {
		status = BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
	} break;
	}

	if (!defer_status) {
		dtm_send_test_status_evt(status, response);
	} else {
		LOG_DBG("DTM cmd:%d, deferred", command);
	}

	LOG_DBG("DTM ----");
}

void dtm_reset_complete(uint8_t status)
{
	dtm_env.test_active = false;
	dtm_send_test_status_evt(status, 0);
}

void dtm_test_start_complete(uint8_t status)
{
	if (status == BT_HCI_ERR_SUCCESS) {
		dtm_env.test_active = true;
	}
	dtm_send_test_status_evt(status, 0);
}

void dtm_test_end(uint8_t status, uint16_t recv_count)
{
	LOG_DBG("DTM +- end: s:0x%x, c:%d", status, recv_count);
	dtm_env.test_active = false;
	if (status != BT_HCI_ERR_SUCCESS) {
		dtm_send_test_status_evt(status, 0);
	} else {
		dtm_send_pkt_report_evt(recv_count);
	}
}
