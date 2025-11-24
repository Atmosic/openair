/**
 *******************************************************************************
 *
 * @file ble_dtm.h
 *
 * @brief This file contains the Bluetooth LE DTM (Direct Test Mode) definitions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_DTM  DTM definitions
 * @brief  DTM definitions
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

// Command definitions, see: Part F 3.3
#define DTM_MESSAGE_MAX_LEN 2
#define DTM_CMD_SHIFT       14
#define DTM_CMD_MASK        (0x3 << DTM_CMD_SHIFT)
#define DTM_CMD_TEST_SETUP  0x00
#define DTM_CMD_RX_TEST     0x01
#define DTM_CMD_TX_TEST     0x02
#define DTM_CMD_TEST_END    0x03
#define DTM_GET_CMD(d)      (((d) & DTM_CMD_MASK) >> DTM_CMD_SHIFT)
#define DTM_CTRL_SHIFT      8
#define DTM_CTRL_MASK       (0x3F << DTM_CTRL_SHIFT)
#define DTM_PARAM_SHIFT     0
#define DTM_PARAM_MASK      (0xFF << DTM_PARAM_SHIFT)
#define DTM_GET_CTRL(d)     (((d) & DTM_CTRL_MASK) >> DTM_CTRL_SHIFT)
#define DTM_GET_PARAM(d)    (((d) & DTM_PARAM_MASK) >> DTM_PARAM_SHIFT)

// Test Setup: CTRL and PARAM field definitions, see: Part F 3.3.2
#define DTM_CTRL_RESET          0x00 // reset length extension and PHY rate settings
#define DTM_CTRL_SET_LEN_EXT    0x01 // set length extension bits
#define DTM_CTRL_SET_PHY_MODE   0x02 // set the test PHY rate
#define DTM_CTRL_SET_RECV_MODE  0x03 // receiver modulation
#define DTM_CTRL_READ_TEST_FEAT 0x04 // read test features
#define DTM_CTRL_READ_PDU_SUPP  0x05 // read PDU RX/TX supported values
#define DTM_CTRL_SET_TX_PWR_LVL 0x09 // set transmitter power level

// in the 4.2 and 5.0 spec, the param field starts at bit 2 (0..1 are don't
// cares) but in 5.1, they reclaimed bits 0..1 but kept the param values shifted
// by 2 bits to remain backwards compatible. these definitions follow
// the 4.2/5.0 spec but are fully compatible with 5.1 and 5.2
#define DTM_PARAM_FIELD_SHIFT  2
#define DTM_PARAM_FIELD_MASK   (0x3F << DTM_PARAM_FIELD_SHIFT)
#define DTM_PARAM_GET_FIELD(d) (((d) & DTM_PARAM_FIELD_MASK) >> DTM_PARAM_FIELD_SHIFT)

// CTRL : set length
#define DTM_PARAM_GET_LEN_EXT(d) DTM_PARAM_GET_FIELD(d)
#define DTM_LEN_EXT_SHIFT        6

// CTRL : set phy mode
#define DTM_PARAM_GET_PHY_MODE(d) DTM_PARAM_GET_FIELD(d)
#define DTM_PARAM_PHY_MODE_LE_1M  0x01
#define DTM_PARAM_PHY_MODE_LE_2M  0x02
#define DTM_PARAM_PHY_MODE_LE_S8  0x03
#define DTM_PARAM_PHY_MODE_LE_S2  0x04
#define DTM_PARAM_PHY_MODE_MAX    0x04

// CTRL : set expected transmitter modulation
#define DTM_PARAM_GET_RECV_MOD_IDX(d) DTM_PARAM_GET_FIELD(d)
#define DTM_PARAM_RECV_ASSUME_STD     0x00 // standard modulation
#define DTM_PARAM_RECV_ASSUME_STABLE  0x01 // stable modulation

// CTRL : read supported features
#define DTM_PARAM_GET_READ_TEST_FEAT_TYPE(d) DTM_PARAM_GET_FIELD(d)
#define DTM_PARAM_READ_TEST_FEAT_TEST_CASES  0x00
#define DTM_SUPPORT_LENGTH_EXT_MASK          (0x1 << 0) // note: the spec starts these at bit
#define DTM_SUPPORT_LE_2M_PHY_MASK           (0x1 << 1) // at 1 to jump over the status bit.
#define DTM_SUPPORT_TX_HAS_STABLE_MOD_IDX    (0x1 << 2) // here we are relative to bit 0.
#define DTM_SUPPORT_TX_HAS_STD_MOD_IDX       0
#define DTM_SUPPORT_LE_CODED_PHY_MASK        (0x1 << 3)

// CTRL :  Read PDU Supported Maximum Values
#define DTM_PARAM_GET_PDU_SUP_TYPE(d)    DTM_PARAM_GET_FIELD(d)
#define DTM_PARAM_READ_PDU_MAX_TX_OCTETS 0x00
#define DTM_PARAM_READ_PDU_MAX_TX_TIME   0x01
#define DTM_PARAM_READ_PDU_MAX_RX_OCTETS 0x02
#define DTM_PARAM_READ_PDU_MAX_RX_TIME   0x03

// CTRL : Get TX power level
#define DTM_PARAM_GET_TX_PWR_LVL(d) (d)

// Test End: CTRL and PARAM field definitions
#define DTM_END_CTRL_END  0x00
#define DTM_END_PARAM_END 0x00

// Status and Packet Report definitions, see: Part F 3.3.2
#define DTM_EVENT_TYPE_STATUS     0
#define DTM_EVENT_TYPE_PKT_REPORT 1
#define DTM_EVENT_TYPE_SHIFT      15
#define DTM_EVENT_STATUS_MASK     0x1
#define DTM_EVENT_RESP_MASK       0x3FFF // 14 bits
#define DTM_EVENT_RESP_SHIFT      1
#define DTM_EVENT_PKT_COUNT_MASK  0x7FFF // 15 bits
#define DTM_ASSEMBLE_STATUS_RESPONSE(status, resp)                                                 \
	((DTM_EVENT_TYPE_STATUS) << DTM_EVENT_TYPE_SHIFT) | ((status) & DTM_EVENT_STATUS_MASK) |   \
		(((resp) & DTM_EVENT_RESP_MASK) << DTM_EVENT_RESP_SHIFT)
#define DTM_ASSEMBLE_PKT_REPORT(count)                                                             \
	((DTM_EVENT_TYPE_PKT_REPORT) << DTM_EVENT_TYPE_SHIFT) | ((count) & DTM_EVENT_PKT_COUNT_MASK)

// Transmitter and Receiver Test Command, see: Part F 3.4
#define DTM_TXRX_TEST_FREQ_SHIFT 8
#define DTM_TXRX_TEST_FREQ_MASK  (0x3F << DTM_TXRX_TEST_FREQ_SHIFT)
#define DTM_GET_TXRX_FREQ(d)     (((d) & DTM_TXRX_TEST_FREQ_MASK) >> DTM_TXRX_TEST_FREQ_SHIFT)

#define DTM_TXRX_TEST_LEN_SHIFT 2
#define DTM_TXRX_TEST_LEN_MASK  (0x3F << DTM_TXRX_TEST_LEN_SHIFT)
#define DTM_GET_TXRX_LEN(d)     (((d) & DTM_TXRX_TEST_LEN_MASK) >> DTM_TXRX_TEST_LEN_SHIFT)

#define DTM_TXRX_TEST_PKT_SHIFT 0
#define DTM_TXRX_TEST_PKT_MASK  (0x3 << DTM_TXRX_TEST_PKT_SHIFT)
#define DTM_GET_TXRX_PKT(d)     (((d) & DTM_TXRX_TEST_PKT_MASK) >> DTM_TXRX_TEST_PKT_SHIFT)

#define DTM_PKT_TYPE_PRBS9        0x00
#define DTM_PKT_TYPE_11110000     0x01
#define DTM_PKT_TYPE_10101010     0x02
#define DTM_PKT_TYPE_LEC_11111111 0x03

#define DTM_TX_POWER_LVL_MIN 0x7E
#define DTM_TX_POWER_LVL_MAX 0x7F

#ifdef __cplusplus
}
#endif

/// @} ATM_DTM
