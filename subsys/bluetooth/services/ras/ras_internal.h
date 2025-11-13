/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/// RAS Features: supported features of RAS Server
typedef enum ras_feat_e {
	RAS_FEAT_REALTIME_RD = BIT(0),
	RAS_FEAT_RETRIEVE_LOST_RD_SEG = BIT(1),
	RAS_FEAT_ABORT_OP = BIT(2),
	RAS_FEAT_FILTER_RD = BIT(3),
} ras_feat_t;

/// RAS Control Point Opcode Length
#define RAS_CP_OPCODE_LEN       1
/// RAS Control Point Opcode Offset
#define RAS_CP_OPCODE_OFFSET    0
/// RAS Control Point Parameter Offset
#define RAS_CP_PARAM_OFFSET     RAS_CP_OPCODE_LEN
/// Timeout to Receive ACK for Ranging Data Complete
#define RAS_CP_ACK_DATA_TIMEOUT K_SECONDS(5)

/// RAS Control Point for Segment Ranging Data
typedef struct {
	/// Ranging Counter
	uint16_t ranging_cnt;
	/// Start Segment
	uint8_t start_segmt;
	/// End Segment
	uint8_t end_segmt;
} ras_cp_rd_segment_t;

/// RAS Control Point filter command
typedef struct {
	/// Mode
	uint16_t mode: 2;
	/// Filter but mask
	uint16_t mask: 14;
} ras_cp_filter_t;

/// RAS Control Point Command and Response
typedef struct ras_cp_s {
	/// Operation Code
	uint8_t opcode;
	/// Parameter
	union ras_cp_para {
		/// Ranging Counter
		uint16_t ranging_cnt;
		/// Ranging Data Segment
		ras_cp_rd_segment_t rd_segmt;
		/// Filter Configuration
		ras_cp_filter_t rd_filter;
		/// Response Code Value
		uint8_t code_val;
	} para;
} __packed ras_cp_t;

/// RAS Control Point Command Opcode
enum ras_cp_cmd_opcode {
	RAS_CP_CMD_OPCODE_GET_RD,
	RAS_CP_CMD_OPCODE_ACK_RD,
	RAS_CP_CMD_OPCODE_RETRIEVE_LOST_RD_SEGMENTS,
	RAS_CP_CMD_OPCODE_ABORT_OP,
	RAS_CP_CMD_OPCODE_SET_FILTER,
};

/// RAS Control Point Response Opcode
enum ras_cp_rsp_opcode {
	RAS_CP_RSP_OPCODE_COMPLETE_RD_RSP,
	RAS_CP_RSP_OPCODE_COMPLETE_LOST_RD_SEG_RSP,
	RAS_CP_RSP_OPCODE_RSP_CODE,
};

/// RAS Control Point Response Code Value
enum ras_cp_rsp_code {
	RAS_CP_RSP_RESERVED,
	RAS_CP_RSP_SUCCESS,
	RAS_CP_RSP_OPCODE_NOT_SUPPORTED,
	RAS_CP_RSP_INVALID_PARAMETER,
	RAS_CP_RSP_SUCCESS_PERSISTED,
	RAS_CP_RSP_ABORT_UNSUCCESSFUL,
	RAS_CP_RSP_PROCEDURE_NOT_COMPLETED,
	RAS_CP_RSP_SERVER_BUSY,
	RAS_CP_RSP_NO_RECORDS_FOUND,
};

/// RAS Ranging Data Segmentation Header
typedef struct ras_seg_header_s {
	bool first_seg: 1;
	bool last_seg: 1;
	uint8_t seg_counter: 6;
} __packed ras_seg_header_t;

/// RAS Ranging Data Segment GATT Header Length
#define RAS_SEG_DATA_GATT_HDR 4
/// RAS Ranging Data Segment Max Data Len
#define RAS_SEG_DATA_MAX_LEN  (CONFIG_BT_L2CAP_TX_MTU - RAS_SEG_DATA_GATT_HDR)
/// RAS Ranging Data Segment
typedef struct ras_seg_data_s {
	struct ras_seg_header_s header;
	uint8_t seg_data[RAS_SEG_DATA_MAX_LEN];
} __packed ras_seg_data_t;

/// RAS Ranging Data Header
typedef struct ras_rd_header_s {
	uint16_t ranging_counter: 12;
	uint16_t cfg_id: 4;
	uint8_t tx_pwr;
	uint8_t antenna_path_masks;
} __packed ras_rd_header_t;

/// RAS Ranging Data Subvevent Header
typedef struct ras_rd_subevent_hdr_s {
	uint16_t acl_conn_evt;
	uint16_t freq_comp;
	uint8_t ranging_done: 4;
	uint8_t subevt_done: 4;
	uint8_t ranging_abrt_reason: 4;
	uint8_t subevt_abrt_reason: 4;
	uint8_t ref_pwr_lvl;
	uint8_t reported_step;
} __packed ras_rd_subevent_hdr_t;

/// RAS Ranging Data step data
typedef struct ras_rd_step_data_s {
	uint8_t mode;
	uint8_t data[];
} __packed ras_rd_step_data_t;

/// RAS Ranging Data Procedure Data
struct ras_rd_proc_data {
	struct ras_rd_header_s ranging_hdr;
	struct ras_rd_subevent_hdr_s subevt_hdr;
	struct ras_rd_step_data_s step_data[];
} __packed;

#ifdef __cplusplus
}
#endif
