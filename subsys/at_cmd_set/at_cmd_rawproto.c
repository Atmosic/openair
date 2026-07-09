/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <string.h>
#include <zephyr/logging/log.h>
#include "at_cmd_rawproto.h"

LOG_MODULE_REGISTER(at_cmd_rawproto, CONFIG_AT_CMD_SET_LOG_LEVEL);

static at_cmd_rdp_cb_t const *rdp_cbs;
static uint8_t rdp_buf[AT_CMD_RDP_PACKET_LEN];
static uint16_t rdp_idx;
static uint16_t rdp_plen; /* 0 = header not yet complete */

void at_cmd_rdp_init(void)
{
	rdp_idx = 0;
	rdp_plen = 0;
}

void at_cmd_rdp_reg_cbs(at_cmd_rdp_cb_t const *cbs)
{
	rdp_cbs = cbs;
}

void at_cmd_rdp_recv(const uint8_t *in, uint16_t len)
{
	if (!rdp_cbs || !rdp_cbs->pkt_proc) {
		LOG_ERR("No packet callback");
		return;
	}

	for (uint16_t i = 0; i < len; i++) {
		if (rdp_idx < AT_CMD_RDP_PACKET_LEN) {
			rdp_buf[rdp_idx++] = in[i];
		}

		/*
		 * Determine total packet length only once all 3 header bytes
		 * are in rdp_buf.  Reading hdr->len from the input pointer
		 * directly would be a buffer overread when called 1 byte at a
		 * time (e.g. from a UART ISR).
		 */
		if (rdp_idx == AT_CMD_RDP_HDR_LEN && !rdp_plen) {
			const at_cmd_rdp_hdr_t *hdr = (const at_cmd_rdp_hdr_t *)rdp_buf;

			/* Reject oversized packets before they stall the reassembler. */
			if (hdr->len > AT_CMD_RDP_DATA_LEN_NCRC) {
				LOG_ERR("Oversized packet len=%u (max %u)", hdr->len,
					AT_CMD_RDP_DATA_LEN_NCRC);
				rdp_idx = 0;
				rdp_plen = 0;
				return;
			}
			rdp_plen = AT_CMD_RDP_HDR_LEN + hdr->len;
			LOG_DBG("new pkt plen=%u", rdp_plen);
		}

		if (rdp_plen && rdp_idx >= rdp_plen) {
			uint16_t pkt_len = rdp_plen;

			rdp_idx = 0;
			rdp_plen = 0;
			if (rdp_cbs->pkt_proc(rdp_buf, pkt_len) != AT_CMD_RDP_ERR_NO_ERROR) {
				return;
			}
		}
	}
}

void at_cmd_rdp_ack(at_cmd_rdp_hdr_t const *hdr, uint8_t err, uint8_t *out)
{
	out[0] = hdr->flag | AT_CMD_RDP_FLAG_OP_ACK;
	out[1] = hdr->sn;
	out[2] = err;
}
