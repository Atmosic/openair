/**
 *******************************************************************************
 *
 * @file dtm_hci_bridge.h
 *
 * @brief DTM HCI bridge interface definitions
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_DTM_HCI_BRIDGE  DTM HCI bridge
 * @ingroup ATM_DTM
 * @brief  DTM HCI bridge interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/bluetooth/hci.h>

/**
 * @brief Command Complete callback type.
 * @param[in] opcode HCI opcode.
 * @param[in] param_buf Pointer to Command Complete parameters (status first).
 * @param[in] len Length in bytes of param_buf.
 * @retval true  Response was handled (consumed/processed).
 */
typedef bool (*dtm_hci_cmd_cmpl_cb)(uint16_t opcode, const void *param_buf, uint8_t len);

/**
 * @brief Send an HCI command to the bridge
 * @param[in] opcode  HCI opcode
 * @param[in] param_buf  parameter buffer (can be NULL)
 * @param[in] param_len  length of parameters
 * @return BT_HCI_STATUS_SUCCESS on success
 */
uint8_t dtm_hci_bridge_send_cmd(uint16_t opcode, uint8_t *param_buf, uint8_t param_len);

/**
 * @brief set the command complete callback
 * @param[in] cb  call back to set
 */
void dtm_hci_bridge_set_cmd_complete_cb(dtm_hci_cmd_cmpl_cb cb);

#ifdef __cplusplus
}
#endif

/// @} ATM_DTM
