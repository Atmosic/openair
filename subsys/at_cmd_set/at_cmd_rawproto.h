/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * RDP packet format (host -> device):
 *   | HDR(1) | SN(1) | LEN(1) | DATA(0~252) | [CRC(1)] |
 *
 * RDP ACK format (device -> host):
 *   | HDR(1) | SN(1) | STS(1) |
 *
 * HDR op field (bits [7:5]):
 *   0x00 = START     (first packet of a transfer)
 *   0x80 = CONT      (continuation packet)
 *   0x20 = END       (last packet, no prior continuation)
 *   0xA0 = CONT_END  (last packet after one or more CONTs)
 *   0x40 = ACK       (device->host acknowledgment)
 *
 * LEN counts payload bytes; if CRC is enabled the CRC byte is included in LEN.
 */

#define AT_CMD_RDP_FLAG_OP_CONT 0x80
#define AT_CMD_RDP_FLAG_OP_ACK  0x40
#define AT_CMD_RDP_FLAG_OP_END  0x20

#define AT_CMD_RDP_FLAG_MASK       0xE0
#define AT_CMD_RDP_PACKET_IDLE     AT_CMD_RDP_FLAG_MASK
#define AT_CMD_RDP_PACKET_START    0x00
#define AT_CMD_RDP_PACKET_CONT     0x80
#define AT_CMD_RDP_PACKET_END      0x20
#define AT_CMD_RDP_PACKET_CONT_END 0xA0

/** Maximum total packet size (HDR + payload + optional CRC) */
#define AT_CMD_RDP_PACKET_LEN    256U
/** Header size: HDR(1) + SN(1) + LEN(1) */
#define AT_CMD_RDP_HDR_LEN       3U
#define AT_CMD_RDP_DATA_IDX      AT_CMD_RDP_HDR_LEN
#define AT_CMD_RDP_CRC_LEN       1U
#define AT_CMD_RDP_DATA_LEN_NCRC (AT_CMD_RDP_PACKET_LEN - AT_CMD_RDP_HDR_LEN)
#define AT_CMD_RDP_DATA_LEN_CRC  (AT_CMD_RDP_PACKET_LEN - AT_CMD_RDP_HDR_LEN - AT_CMD_RDP_CRC_LEN)
#define AT_CMD_RDP_ACK_LEN       3U

#define AT_CMD_RDP_ERR_NO_ERROR 0x00

/** RDP packet header */
typedef struct {
	union {
		uint8_t flag;
		struct {
			uint8_t type: 5;
			uint8_t op: 3;
		};
	};
	uint8_t sn;
	uint8_t len;
} at_cmd_rdp_hdr_t;

/**
 * @brief Callback invoked when a complete RDP packet has been reassembled.
 *
 * @param pkt  Pointer to the raw packet buffer (HDR + payload [+ CRC]).
 * @param len  Total packet length in bytes.
 * @return AT_CMD_RDP_ERR_NO_ERROR on success; non-zero aborts further processing.
 */
typedef uint8_t (*at_cmd_rdp_packet_t)(void const *pkt, uint16_t len);

typedef struct {
	at_cmd_rdp_packet_t pkt_proc;
} at_cmd_rdp_cb_t;

/** Reset the reassembly state (call before each new DFU session). */
void at_cmd_rdp_init(void);

/** Register the packet-complete callback. Must be called before at_cmd_rdp_recv(). */
void at_cmd_rdp_reg_cbs(at_cmd_rdp_cb_t const *cbs);

/**
 * @brief Feed raw UART bytes into the RDP reassembler.
 *
 * May be called with any number of bytes at a time; the reassembler handles
 * fragmentation transparently.
 */
void at_cmd_rdp_recv(const uint8_t *in, uint16_t len);

/**
 * @brief Build a 3-byte RDP ACK into @p out.
 *
 * @param hdr  Header of the packet being acknowledged.
 * @param err  Error code (AT_CMD_RDP_ERR_NO_ERROR = 0 for success).
 * @param out  Output buffer of at least AT_CMD_RDP_ACK_LEN bytes.
 */
void at_cmd_rdp_ack(at_cmd_rdp_hdr_t const *hdr, uint8_t err, uint8_t *out);

#ifdef __cplusplus
}
#endif
