/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/ztest.h>
#include "arch.h"
#include "atm_bthci_utils.h"

/*
 * atm_bthci_dump_hci_pkt() emits decoded HCI traffic via printk() for
 * debug purposes; call the dump functions with an HCI packet
 *
 */

/* --- HCI CMD --- */

ZTEST(atm_bthci_utils, test_dump_cmd_unknown_opcode)
{
	/* opcode 0x1234 (no registered decoder), param_len 2, params {0xAA, 0xBB} */
	uint8_t const buf[] = {0x34, 0x12, 0x02, 0xAA, 0xBB};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_CMD, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_cmd_reset)
{
	/* HCI_Reset opcode 0x0C03, no params -- exercises decode_hci_reset_cmd() */
	uint8_t const buf[] = {0x03, 0x0C, 0x00};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_CMD, buf, sizeof(buf));
}

/* --- HCI EVT --- */

ZTEST(atm_bthci_utils, test_dump_evt_cmd_complete_reset)
{
	/* Command Complete: num_pkts=1, opcode=0x0C03 (reset), status=0 */
	uint8_t const buf[] = {0x0E, 0x04, 0x01, 0x03, 0x0C, 0x00};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_cmd_complete_failed_status)
{
	/* Command Complete: num_pkts=2, opcode=0x1234, status=0x01 (failure) */
	uint8_t const buf[] = {0x0E, 0x04, 0x02, 0x34, 0x12, 0x01};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_cmd_status)
{
	/* Command Status: status=0, num_pkts=3, opcode=0x0102 */
	uint8_t const buf[] = {0x0F, 0x04, 0x00, 0x03, 0x02, 0x01};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_num_completed_packets)
{
	/* handles=1, handle=0x0040, pkts=5 */
	uint8_t const buf[] = {0x13, 0x05, 0x01, 0x40, 0x00, 0x05, 0x00};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_num_completed_packets_zero_handles)
{
	/* handles=0 -- exercises the "if (handles)" false branch */
	uint8_t const buf[] = {0x13, 0x01, 0x00};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_le_meta_non_adv)
{
	/* LE Meta Event, sub-event 0x01 (Connection Complete) */
	uint8_t const buf[] = {0x3E, 0x01, 0x01};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_le_meta_adv_report_filtered)
{
	/* LE Meta Event, sub-event 0x02 (Advertising Report) is dropped before decode */
	uint8_t const buf[] = {0x3E, 0x01, 0x02};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_le_meta_ext_adv_report_filtered)
{
	/* LE Meta Event, sub-event 0x0d (Extended Advertising Report) is
	 * also dropped before decode -- exercises the second half of the
	 * is_hci_adv_report_evt() OR condition.
	 */
	uint8_t const buf[] = {0x3E, 0x01, 0x0D};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_evt_unknown_event)
{
	/* event 0xFF has no registered decoder */
	uint8_t const buf[] = {0xFF, 0x00};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_EVT, buf, sizeof(buf));
}

/* --- HCI ACL --- */

ZTEST(atm_bthci_utils, test_dump_acl_out)
{
	/* handle/flags word 0x2001, data_len 0x0010 */
	uint8_t const buf[] = {0x01, 0x20, 0x10, 0x00};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_ACL_OUT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_acl_in)
{
	uint8_t const buf[] = {0x01, 0x20, 0x10, 0x00};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_ACL_IN, buf, sizeof(buf));
}

/* --- HCI ISO (no decoder, must not crash) --- */

ZTEST(atm_bthci_utils, test_dump_iso_out)
{
	uint8_t const buf[] = {0x01, 0x02};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_ISO_OUT, buf, sizeof(buf));
}

ZTEST(atm_bthci_utils, test_dump_iso_in)
{
	uint8_t const buf[] = {0x01, 0x02};

	atm_bthci_dump_hci_pkt(ATM_HCI_DUMP_ISO_IN, buf, sizeof(buf));
}

ZTEST_SUITE(atm_bthci_utils, NULL, NULL, NULL, NULL, NULL);
