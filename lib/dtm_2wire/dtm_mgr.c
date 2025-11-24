/**
 *******************************************************************************
 *
 * @file dtm_mgr.c
 *
 * @brief DTM interface manager for Zephyr
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>

#include "dtm_mgr.h"
#include "dtm_hci_bridge.h"
#define DTM_MGR_INTERNAL_GUARD
#include "dtm_mgr_int.h"

LOG_MODULE_REGISTER(dtm_mgr, CONFIG_DTM_2WIRE_LOG_LEVEL);

struct dtm_message {
	uint16_t data;
} __packed;

/* Use devicetree chosen for DTM UART device */
#define DTM_UART_NODE DT_CHOSEN(zephyr_dtm_2wire_uart)

static const struct device *const uart_dev = DEVICE_DT_GET(DTM_UART_NODE);
static struct dtm_message rx_message;
static struct dtm_message tx_message;
static bool tx_pending;
static struct k_work rx_work;
static struct k_work tx_work;

// UART receive buffer and state
static uint8_t rx_buf[sizeof(struct dtm_message)];
static size_t rx_pos = 0;

static void log_uart_config(const struct uart_config *cfg);

static bool cmd_completion(uint16_t opcode, const void *buf, uint8_t len)
{
	bool handled = false;
	const uint8_t *param_buf = buf;

	switch (opcode) {
	case BT_HCI_OP_RESET: {
		if (len < HCI_STATUS_LEN) {
			break;
		}
		uint8_t status = param_buf[0];
		LOG_DBG("HCI reset complete: %d", status);
		dtm_reset_complete(status);
		handled = true;
	} break;
	case BT_HCI_OP_LE_ENH_TX_TEST:
	case BT_HCI_OP_LE_ENH_RX_TEST: {
		if (len < HCI_STATUS_LEN) {
			break;
		}
		uint8_t status = param_buf[0];
		LOG_DBG("HCI TX/RX (opcode: 0x%x) complete event, status: %d", opcode, status);
		dtm_test_start_complete(status);
		handled = true;
	} break;
	case BT_HCI_OP_LE_TEST_END: {
		if (len < sizeof(struct bt_hci_rp_le_test_end)) {
			break;
		}
		const struct bt_hci_rp_le_test_end *rp = (const void *)param_buf;
		uint8_t status = rp->status;
		uint16_t num_pkts = sys_le16_to_cpu(rp->rx_pkt_count);
		LOG_DBG("HCI test end, pkts: %d status %d", num_pkts, status);
		dtm_test_end(status, num_pkts);
		handled = true;
	} break;
	case BT_HCI_OP_LE_READ_MAX_DATA_LEN: {
		if (len < sizeof(struct bt_hci_rp_le_read_max_data_len)) {
			break;
		}
		const struct bt_hci_rp_le_read_max_data_len *rp = (const void *)param_buf;
		if (rp->status == BT_HCI_ERR_SUCCESS) {
			uint16_t max_tx_octets = sys_le16_to_cpu(rp->max_tx_octets);
			uint16_t max_tx_time = sys_le16_to_cpu(rp->max_tx_time);
			uint16_t max_rx_octets = sys_le16_to_cpu(rp->max_rx_octets);
			uint16_t max_rx_time = sys_le16_to_cpu(rp->max_rx_time);
			dtm_set_data_len_caps(max_tx_octets, max_tx_time, max_rx_octets,
					      max_rx_time);
			LOG_DBG("LE Read Max Data Len: tx(%u,%u) rx(%u,%u)", max_tx_octets,
				max_tx_time, max_rx_octets, max_rx_time);
		}
		handled = true;
	} break;
	default: {
		LOG_DBG("Unhandled opcode 0x%x param len: %d", opcode, len);
	} break;
	}

	return handled;
}

static void uart_rx_handler(const struct device *dev, void *user_data)
{
	uint8_t c;

	if (!uart_irq_rx_ready(uart_dev)) {
		return;
	}

	// Read available bytes
	while (uart_fifo_read(uart_dev, &c, 1) == 1) {
		rx_buf[rx_pos++] = c;

		// Check if we have a complete message
		if (rx_pos == sizeof(struct dtm_message)) {
			// Copy to rx_message and schedule processing
			memcpy(&rx_message, rx_buf, sizeof(rx_message));
			k_work_submit(&rx_work);
			rx_pos = 0; // Reset for next message
		}
	}
}

static void rx_work_handler(struct k_work *work)
{
	// Process received message (bytes received MSB, LSB)
	uint16_t message = sys_be16_to_cpu(rx_message.data);
	dtm_process_message(message);
}

static void tx_work_handler(struct k_work *work)
{
	// Send the message via UART
	const uint8_t *data = (const uint8_t *)&tx_message;
	for (size_t i = 0; i < sizeof(tx_message); i++) {
		uart_poll_out(uart_dev, data[i]);
	}
	tx_pending = false;
}

static void log_uart_config(const struct uart_config *cfg)
{
	// Convert enum values to actual numbers for display
	uint8_t data_bits;
	switch (cfg->data_bits) {
	case UART_CFG_DATA_BITS_5:
		data_bits = 5;
		break;
	case UART_CFG_DATA_BITS_6:
		data_bits = 6;
		break;
	case UART_CFG_DATA_BITS_7:
		data_bits = 7;
		break;
	case UART_CFG_DATA_BITS_8:
		data_bits = 8;
		break;
	case UART_CFG_DATA_BITS_9:
		data_bits = 9;
		break;
	default:
		data_bits = 0;
		break;
	}

	const char *stop_bits_str;
	switch (cfg->stop_bits) {
	case UART_CFG_STOP_BITS_0_5:
		stop_bits_str = "0.5";
		break;
	case UART_CFG_STOP_BITS_1:
		stop_bits_str = "1";
		break;
	case UART_CFG_STOP_BITS_1_5:
		stop_bits_str = "1.5";
		break;
	case UART_CFG_STOP_BITS_2:
		stop_bits_str = "2";
		break;
	default:
		stop_bits_str = "?";
		break;
	}

	LOG_INF("DTM UART configured: %d baud, %dN%s, flow_ctrl=%s", cfg->baudrate, data_bits,
		stop_bits_str,
		(cfg->flow_ctrl == UART_CFG_FLOW_CTRL_NONE) ? "disabled" : "enabled");
}

void dtmtl_send(uint16_t message)
{
	if (tx_pending) {
		LOG_ERR("TX pending, dropping message");
		return;
	}

	// Convert to big-endian for transmission (bytes sent MSB, LSB)
	tx_message.data = sys_cpu_to_be16(message);
	tx_pending = true;
	k_work_submit(&tx_work);
}

int dtm_mgr_init(void)
{
	int ret;

	LOG_INF("Initializing DTM manager");

	// Check UART device is ready
	if (!device_is_ready(uart_dev)) {
		LOG_ERR("DTM UART device not ready");
		return -ENODEV;
	}

	// Get and display current UART configuration
	struct uart_config uart_cfg;
	ret = uart_config_get(uart_dev, &uart_cfg);
	if (ret) {
		LOG_ERR("Failed to read UART configuration: %d", ret);
		return ret;
	}

	log_uart_config(&uart_cfg);

	// Initialize work items
	k_work_init(&rx_work, rx_work_handler);
	k_work_init(&tx_work, tx_work_handler);

	uart_irq_rx_disable(uart_dev);
	uart_irq_tx_disable(uart_dev);

	// Configure UART for interrupt-driven operation
	uart_irq_callback_user_data_set(uart_dev, uart_rx_handler, NULL);

	uart_irq_rx_enable(uart_dev);

	dtm_hci_bridge_set_cmd_complete_cb(cmd_completion);

	/* Prime controller capabilities: LE Read Max Data Length */
	dtm_hci_bridge_send_cmd(BT_HCI_OP_LE_READ_MAX_DATA_LEN, NULL, 0);

	LOG_INF("DTM manager initialized");
	return 0;
}
