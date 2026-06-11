/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/crc.h>
#include "at_cmd.h"
#include "at_cmd_rawproto.h"
#include "at_cmd_sysdfu_proc.h"
#include "atm_vendor_dfu.h"

LOG_MODULE_REGISTER(sysdfu_proc, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Per-packet error codes returned in the RDP ACK status byte */
#define DFU_ERR_NO_ERROR 0x00
#define DFU_ERR_SN       0x01
#define DFU_ERR_HDR      0x02
#define DFU_ERR_CRC      0x03
#define DFU_ERR_WRITE    0x04

typedef struct {
	at_cmd_ch_t ch;
	uint32_t bytes_remaining;
	bool crc_en;
	bool active;
	bool switch_bank_en;
	/* Expected SN: initialised to 0xFF so first ++sn wraps to 0x00. */
	uint8_t sn;
	/* Packet flag state machine (IDLE/START/CONT/END/CONT_END). */
	uint8_t curr_type;
} sysdfu_ctx_t;

static sysdfu_ctx_t ctx;
static uint8_t dfu_ack[AT_CMD_RDP_ACK_LEN];

/*
 * One-packet staging area.  The RDP protocol is strictly ACK-before-next, so
 * there is at most one packet in flight.  The ISR-safe path copies the
 * assembled packet here and submits proc_work; the work handler does the
 * (blocking) flash write and sends the ACK from thread context.
 */
static uint8_t pending_pkt[AT_CMD_RDP_PACKET_LEN];
static uint16_t pending_pkt_len;
static struct k_work proc_work;

static uint8_t hdr_validate(const at_cmd_rdp_hdr_t *hdr)
{
	uint8_t flag = hdr->flag & AT_CMD_RDP_FLAG_MASK;

	switch (ctx.curr_type) {
	case AT_CMD_RDP_PACKET_IDLE:
		if (flag == AT_CMD_RDP_PACKET_START || flag == AT_CMD_RDP_PACKET_END) {
			ctx.curr_type = flag;
			return DFU_ERR_NO_ERROR;
		}
		break;
	case AT_CMD_RDP_PACKET_START:
		if (flag == AT_CMD_RDP_PACKET_CONT || flag == AT_CMD_RDP_PACKET_END) {
			ctx.curr_type = flag;
			return DFU_ERR_NO_ERROR;
		}
		break;
	case AT_CMD_RDP_PACKET_CONT:
		if (flag == AT_CMD_RDP_PACKET_CONT || flag == AT_CMD_RDP_PACKET_CONT_END) {
			ctx.curr_type = flag;
			return DFU_ERR_NO_ERROR;
		}
		break;
	default:
		break;
	}
	return DFU_ERR_HDR;
}

/*
 * success=true only on clean END/CONT_END.  Error paths pass false so that
 * AT+SYSSWITCHBANK is NOT permitted after an aborted transfer.
 */
static void proc_end(bool success)
{
	ctx.active = false;
	ctx.switch_bank_en = success;
	ctx.sn = 0xFF;
	ctx.curr_type = AT_CMD_RDP_PACKET_IDLE;
	if (success) {
		LOG_INF("DFU transfer complete");
	} else {
		LOG_ERR("DFU transfer aborted");
	}
}

static uint8_t proc_data(void const *pkt, uint16_t len)
{
	const at_cmd_rdp_hdr_t *hdr = pkt;
	const uint8_t *ptr = pkt;

	/* Sequence number check: expected SN = previous + 1 (wraps at 0xFF). */
	uint8_t expected_sn = (uint8_t)(ctx.sn + 1U);

	if (hdr->sn != expected_sn) {
		LOG_ERR("Wrong SN: got 0x%02x expected 0x%02x", hdr->sn, expected_sn);
		at_cmd_rdp_ack(hdr, DFU_ERR_SN, dfu_ack);
		at_cmd_send_raw(ctx.ch, dfu_ack, AT_CMD_RDP_ACK_LEN);
		proc_end(false);
		return DFU_ERR_SN;
	}
	ctx.sn = hdr->sn;

	/* Packet flag state machine. */
	if (hdr_validate(hdr) != DFU_ERR_NO_ERROR) {
		LOG_ERR("Wrong packet flag: 0x%02x", hdr->flag);
		at_cmd_rdp_ack(hdr, DFU_ERR_HDR, dfu_ack);
		at_cmd_send_raw(ctx.ch, dfu_ack, AT_CMD_RDP_ACK_LEN);
		proc_end(false);
		return DFU_ERR_HDR;
	}

	/* Guard: CRC mode requires at least one CRC byte in the payload. */
	if (ctx.crc_en && hdr->len < AT_CMD_RDP_CRC_LEN) {
		LOG_ERR("Packet too short for CRC: len=%u", hdr->len);
		at_cmd_rdp_ack(hdr, DFU_ERR_HDR, dfu_ack);
		at_cmd_send_raw(ctx.ch, dfu_ack, AT_CMD_RDP_ACK_LEN);
		proc_end(false);
		return DFU_ERR_HDR;
	}

	/* Actual payload length (CRC byte, if present, is not firmware data). */
	uint8_t dlen = ctx.crc_en ? (hdr->len - (uint8_t)AT_CMD_RDP_CRC_LEN) : hdr->len;

	/* CRC-8/CCITT check over header + payload (all bytes except last CRC byte). */
	if (ctx.crc_en) {
		uint16_t crc_pos = len - AT_CMD_RDP_CRC_LEN;
		uint8_t crc = crc8(ptr, crc_pos, 0x07, 0x00, false);

		if (crc != ptr[crc_pos]) {
			LOG_ERR("CRC mismatch: got 0x%02x expected 0x%02x", ptr[crc_pos], crc);
			at_cmd_rdp_ack(hdr, DFU_ERR_CRC, dfu_ack);
			at_cmd_send_raw(ctx.ch, dfu_ack, AT_CMD_RDP_ACK_LEN);
			proc_end(false);
			return DFU_ERR_CRC;
		}
	}

	/* Write chunk directly — atm_vendor_dfu handles alignment internally. */
	int err = atm_vendor_dfu_write(&ptr[AT_CMD_RDP_DATA_IDX], dlen);

	if (err) {
		LOG_ERR("atm_vendor_dfu_write failed: %d", err);
		at_cmd_rdp_ack(hdr, DFU_ERR_WRITE, dfu_ack);
		at_cmd_send_raw(ctx.ch, dfu_ack, AT_CMD_RDP_ACK_LEN);
		proc_end(false);
		return DFU_ERR_WRITE;
	}

	ctx.bytes_remaining = (ctx.bytes_remaining > dlen) ? ctx.bytes_remaining - dlen : 0;

	at_cmd_rdp_ack(hdr, AT_CMD_RDP_ERR_NO_ERROR, dfu_ack);
	at_cmd_send_raw(ctx.ch, dfu_ack, AT_CMD_RDP_ACK_LEN);

	bool last_pkt = (ctx.curr_type == AT_CMD_RDP_PACKET_END ||
			 ctx.curr_type == AT_CMD_RDP_PACKET_CONT_END);

	if (last_pkt || !ctx.bytes_remaining) {
		ctx.curr_type = AT_CMD_RDP_PACKET_IDLE;
		proc_end(true);
	}

	return DFU_ERR_NO_ERROR;
}

/*
 * Called from ISR context (UART RX interrupt) when a complete RDP packet has
 * been assembled.  Only copy + work-submit here; no flash or kernel ops.
 */
static uint8_t rdp_pkt_isr(void const *pkt, uint16_t len)
{
	memcpy(pending_pkt, pkt, len);
	pending_pkt_len = len;
	k_work_submit(&proc_work);
	return AT_CMD_RDP_ERR_NO_ERROR;
}

static void proc_work_fn(struct k_work *work)
{
	ARG_UNUSED(work);
	proc_data(pending_pkt, pending_pkt_len);
}

static const at_cmd_rdp_cb_t rdp_cb = {
	.pkt_proc = rdp_pkt_isr,
};

int at_cmd_sysdfu_proc_start(at_cmd_ch_t ch, uint32_t total_len, bool crc_en)
{
	ctx.ch = ch;
	ctx.bytes_remaining = total_len;
	ctx.crc_en = crc_en;
	ctx.active = true;
	ctx.switch_bank_en = false;
	ctx.sn = 0xFF;
	ctx.curr_type = AT_CMD_RDP_PACKET_IDLE;

	k_work_init(&proc_work, proc_work_fn);
	at_cmd_rdp_reg_cbs(&rdp_cb);
	at_cmd_rdp_init();

	LOG_INF("DFU session started: len=%u crc=%d", total_len, (int)crc_en);
	return 0;
}

bool at_cmd_sysdfu_is_active(void)
{
	return ctx.active;
}

bool at_cmd_sysdfu_switch_bank_en(void)
{
	return ctx.switch_bank_en;
}

void at_cmd_sysdfu_feed_byte(uint8_t byte)
{
	at_cmd_rdp_recv(&byte, 1);
}
