/**
 *******************************************************************************
 *
 * @file dtm_hci_bridge.c
 *
 * @brief DTM HCI bridge implementation for Zephyr
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/net_buf.h>
#include <zephyr/sys/byteorder.h>

#include "dtm_hci_bridge.h"

LOG_MODULE_REGISTER(dtm_hci_bridge, CONFIG_DTM_2WIRE_LOG_LEVEL);

#define H4_CMD     0x01
#define H4_ACL     0x02
#define H4_EVT     0x04
#define H4_HDR_LEN 1

#define HCI_EVENT_HDR_LEN     2 // 1 byte event code, 1 byte length
#define HCI_OPCODE_LEN        2
#define HCI_NUM_CMPL_PKTS_LEN 1
#define HCI_CMD_CMPL_EVENT    0x0E

static dtm_hci_cmd_cmpl_cb cmd_cmpl_cb;

#if defined(CONFIG_DTM_2WIRE_LOG_LEVEL_DBG)
#define DTM_HCI_DUMP(h, b, l) LOG_HEXDUMP_DBG(b, l, h)
#else
#define DTM_HCI_DUMP(h, b, l)                                                                      \
	do {                                                                                       \
	} while (0)
#endif

void dtm_hci_bridge_set_cmd_complete_cb(dtm_hci_cmd_cmpl_cb cb)
{
	cmd_cmpl_cb = cb;
}

uint8_t dtm_hci_bridge_send_cmd(uint16_t opcode, uint8_t *param_buf, uint8_t param_len)
{
	struct net_buf *buf;
	struct net_buf *rsp = NULL;
	int err;

	LOG_DBG("Sending HCI command: 0x%04x, len: %d", opcode, param_len);

	if (param_buf && param_len) {
		DTM_HCI_DUMP("HCI CMD PARAMS", param_buf, param_len);
	}

	buf = bt_hci_cmd_alloc(K_FOREVER);
	if (!buf) {
		LOG_ERR("Failed to allocate HCI command buffer");
		return BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
	}

	if (param_len && param_buf) {
		net_buf_add_mem(buf, param_buf, param_len);
	}

	err = bt_hci_cmd_send_sync(opcode, buf, &rsp);
	if (err) {
		LOG_ERR("Failed to send HCI command: %d", err);
		return BT_HCI_ERR_UNSUPP_REMOTE_FEATURE;
	}

	// Process the response if we have a callback
	if (rsp && cmd_cmpl_cb) {
		uint8_t *evt_data = rsp->data;
		uint8_t evt_len = rsp->len;

		LOG_DBG("Command complete for opcode: 0x%04x, param_len: %d", opcode, evt_len);
		cmd_cmpl_cb(opcode, evt_data, evt_len);
	}

	if (rsp) {
		net_buf_unref(rsp);
	}

	return BT_HCI_ERR_SUCCESS;
}
