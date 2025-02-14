/**
 *******************************************************************************
 *
 * @file atm_bthci_utils_dump.c
 *
 * @brief HCI dump utilities
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */
#ifdef CONFIG_SOC_FAMILY_ATM
#include <assert.h>
#include <zephyr/kernel.h>
#define PRINTF printk
#else
#define PRINTF printf
#endif
#include "arch.h"
#include "atm_bthci_utils.h"

#define HCI_COMMAND_HDR_LEN 3
#define HCI_EVENT_HDR_LEN 2
#define HCI_CMD_CMPL_EVENT 0xE
#define HCI_LE_META_EVENT 0x3E
#define HCI_CMD_STATUS_EVENT 0x0F
#define HCI_NUM_PKT_CMP_EVENT 0x13
#define HCI_RESET_OPCODE 0x0C03
#define DECODE_PRINT(fmt, ...) PRINTF("    " fmt "\n", ##__VA_ARGS__)
#define TABLE_LENGTH(table) (sizeof(table) / sizeof((table)[0]))
#define HCI_EVT_LE_ADV_REPORT 0x02
#define HCI_EVT_LE_EXT_ADV_REPORT 0x0d

struct hci_evt_decoder {
    uint8_t event;
    void (*decode)(uint8_t const *params, uint32_t len);
};

struct hci_cmd_decoder {
    uint16_t opcode;
    void (*decode)(uint8_t const *params, uint32_t len);
};

static void decode_hci_cmd_cmpl_evt(uint8_t const *params, uint32_t len)
{
    ASSERT_INFO(len >= 4, len, 0);
    uint8_t num_pkts = *params;
    params++;
    len--;
    uint16_t opcode = ((uint16_t)params[1] << 8) | params[0];
    params += 2;
    len -= 2;
    // all command completions return a status in the next byte by convention
    uint8_t status = *params;
    DECODE_PRINT("CMD COMPL: op:0x%04x, S:0x%02x, PKTs:%d", opcode, status,
	num_pkts);
    if (opcode == HCI_RESET_OPCODE) {
	DECODE_PRINT("*** HCI RESET Complete **");
    }
    if (status) {
	DECODE_PRINT("*** Failed status: S:0x%02x **", status);
    }
}

static void decode_cmd_status_evt(uint8_t const *params, uint32_t len)
{
    ASSERT_INFO(len >= 4, len, 0);
    uint8_t status = *params;
    params++;
    len--;
    uint8_t num_pkts = *params;
    params++;
    len--;
    uint16_t opcode = ((uint16_t)params[1] << 8) | params[0];
    DECODE_PRINT("CMD STATUS: op:0x%04x, S:0x%02x, PKTs:%d", opcode, status,
	num_pkts);
    if (status) {
	DECODE_PRINT("*** Failed status: S:0x%02x **", status);
    }
}

static void decode_hci_le_meta_evt(uint8_t const *params, uint32_t len)
{
    uint8_t sub_event_code = params[0];
    DECODE_PRINT("LE Event: 0x%02x", sub_event_code);
}

static void decode_hci_num_pkt_cmp_evt(uint8_t const *params, uint32_t len)
{
    ASSERT_INFO(len, len, 0);
    uint8_t handles = *params;
    params++;
    len--;
    if (handles) {
	ASSERT_INFO(len >= (handles * 4), len, handles);
	// for now just print the first entry
	uint16_t handle = ((uint16_t)params[1] << 8) | params[0];
	params += 2;
	uint16_t pkts = ((uint16_t)params[1] << 8) | params[0];
	DECODE_PRINT("NUM PKT CMP: (cnt:%d), handle:0x%04x, pkts:%d", handles,
	    handle, pkts);
    }
}

static void decode_hci_reset_cmd(uint8_t const *params, uint32_t len)
{
    DECODE_PRINT("*** HCI RESET **");
}

static struct hci_evt_decoder const hci_evt_decode_handlers[] = {
    {HCI_LE_META_EVENT, decode_hci_le_meta_evt},
    {HCI_NUM_PKT_CMP_EVENT, decode_hci_num_pkt_cmp_evt},
    {HCI_CMD_CMPL_EVENT, decode_hci_cmd_cmpl_evt},
    {HCI_CMD_STATUS_EVENT, decode_cmd_status_evt},
};

static struct hci_cmd_decoder const hci_cmd_decode_handlers[] = {
    {HCI_RESET_OPCODE, decode_hci_reset_cmd},
};

static void dump_hci_evt(uint8_t const *buf, uint32_t len)
{
    ASSERT_INFO((len >= HCI_EVENT_HDR_LEN), len, 0);
    uint8_t event = buf[0];
    uint8_t param_len = buf[1];
    DECODE_PRINT("EVT: 0x%02x, p_len:%d", event, param_len);
    ASSERT_INFO(param_len <= (len - HCI_EVENT_HDR_LEN), param_len, len);
    buf += HCI_EVENT_HDR_LEN;
    for (int i = 0; i < TABLE_LENGTH(hci_evt_decode_handlers); i++) {
	if (hci_evt_decode_handlers[i].event == event) {
	    hci_evt_decode_handlers[i].decode(buf, param_len);
	    break;
	}
    }
}

static void dump_hci_cmd(uint8_t const *buf, uint32_t len)
{
    ASSERT_INFO((len >= HCI_COMMAND_HDR_LEN), len, 0);
    uint16_t opcode = ((uint16_t)buf[1] << 8) | buf[0];
    uint8_t param_len = buf[2];
    DECODE_PRINT("CMD_OP:0x%02x, p_len:%d", opcode, param_len);
    ASSERT_INFO(param_len <= (len - HCI_COMMAND_HDR_LEN), param_len, len);
    buf += HCI_COMMAND_HDR_LEN;
    for (int i = 0; i < TABLE_LENGTH(hci_cmd_decode_handlers); i++) {
	if (hci_cmd_decode_handlers[i].opcode == opcode) {
	    hci_cmd_decode_handlers[i].decode(buf, param_len);
	    break;
	}
    }
}

static void dump_hci_acl(uint8_t const *buf, uint32_t len)
{
    uint16_t handle = ((uint16_t)buf[1] << 8) | buf[0];
    uint8_t pb_flags = (handle >> 12) & 0x3;
    uint8_t bc_flags = (handle >> 14) & 0x3;
    handle &= 0xF000;
    uint16_t data_len = ((uint16_t)buf[3] << 8) | buf[2];
    DECODE_PRINT("ACL flags: pb:0x%02x, bc:0x%02x len:%d", pb_flags, bc_flags,
	data_len);
}

static char const *type_descr[ATM_HCI_DUMP_MAX] = {
    "HCI CMD",
    "HCI EVT",
    "HCI ACL OUT",
    "HCI ACL IN",
    "HCI ISO OUT",
    "HCI ISO IN",
};

static inline bool is_hci_adv_report_evt(uint8_t const *buf, uint32_t len)
{
    if ((buf[0] == HCI_LE_META_EVENT) && (len >= HCI_EVENT_HDR_LEN + 1)) {
	uint8_t evt_code = buf[HCI_EVENT_HDR_LEN];
	if ((evt_code == HCI_EVT_LE_ADV_REPORT) ||
	    (evt_code == HCI_EVT_LE_EXT_ADV_REPORT)) {
	    return true;
	}
    }
    return false;
}

void atm_bthci_dump_hci_pkt(uint8_t type, uint8_t const *buf, uint32_t len)
{
    if ((type == ATM_HCI_DUMP_EVT) && is_hci_adv_report_evt(buf, len)) {
	// drop ADV reports that flood in, they can be quite large.
	PRINTF("ADV!\n");
	return;
    }

    ASSERT_INFO(type < ATM_HCI_DUMP_MAX, type, 0);
    PRINTF("%s:", type_descr[type]);
    for (uint32_t i = 0; i < len; i++) {
	PRINTF(" %02x", buf[i]);
    }
    PRINTF("\n");

    switch (type) {
	case ATM_HCI_DUMP_CMD:
	    dump_hci_cmd(buf, len);
	    break;
	case ATM_HCI_DUMP_EVT:
	    dump_hci_evt(buf, len);
	    break;
	case ATM_HCI_DUMP_ACL_OUT:
	// fall through
	case ATM_HCI_DUMP_ACL_IN:
	    dump_hci_acl(buf, len);
	    break;
	case ATM_HCI_DUMP_ISO_OUT:
	// fall through
	case ATM_HCI_DUMP_ISO_IN:
	    // currently no decoder
	    break;
	default:
	    break;
    }
}
