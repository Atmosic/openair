/**
 ****************************************************************************************
 *
 * @file hci.h
 *
 * @brief This file contains definitions related to the HCI module.
 *
 * Copyright (C) RivieraWaves 2009-2024
 * Release Identifier: dc6acdca
 *
 *
 ****************************************************************************************
 */

#ifndef HCI_H_
#define HCI_H_

/**
 ****************************************************************************************
 * @addtogroup HCI Host Controller Interface
 * @ingroup ROOT
 * @brief HCI module handling communication between lower and higher layers in split
 * architecture.
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"       // SW configuration

#if (HCI_PRESENT)

#include <stddef.h>          // standard definition
#include <stdint.h>          // standard integer
#include "co_bt.h"           // BT standard definitions
#include "co_list.h"         // List definitions
#include "rwtl.h"            // Message Transport layer
#include "rwip_task.h"       // Task definitions

/*
 * DEFINES
 ****************************************************************************************
 */

#if (BLE_EMB_PRESENT || BLE_HOST_PRESENT)
#if (BLE_CENTRAL || BLE_PERIPHERAL)
#define HCI_BLE_CON_SUPPORT   (1u)
#else // (BLE_CENTRAL || BLE_PERIPHERAL)
#define HCI_BLE_CON_SUPPORT   (0u)
#endif // (BLE_CENTRAL || BLE_PERIPHERAL)
#else //(BLE_EMB_PRESENT || BLE_HOST_PRESENT)
#define HCI_BLE_CON_SUPPORT   (0u)
#endif //(BLE_EMB_PRESENT || BLE_HOST_PRESENT)

#if (HOST_PRESENT && !EMB_PRESENT)
/// Buffer header for Host HCI messages
#define HCI_HOST_BUF_HEAD_LEN       (16u)
#endif // (HOST_PRESENT && !EMB_PRESENT)

/// Length of HCI Reset Message
#define HCI_RESET_MSG_LEN     (4u)


/// Message API of the HCI task
/*@TRACE*/
enum hci_msg_id
{
    HCI_CMD_CMP_EVENT = TASK_FIRST_MSG(TASK_ID_HCI),
    HCI_CMD_STAT_EVENT,
    HCI_EVENT,
    HCI_LE_EVENT,
    HCI_VS_EVT,
    HCI_COMMAND,

    // Message with possible host flow control
    HCI_ISO_DATA,
    HCI_ACL_DATA,
    HCI_SYNC_DATA,
};

/// Possible transport layer destination for a message to transmit to host
enum HCI_MSG_HOST_TL_DEST
{
    HOST_NONE,   // Can be ignored
    HOST_TL_UPK,    // Push to host in unpacked format (direct transport layer)
    HOST_TL_PK,     // Push to host in packed format (virtual transport layer)
    HOST_UNDEF,  // Destination transport layer must be computed according to message parameters
};

/// Status of HCI command header processing
enum hci_cmd_hdr_status
{
    /// Header is correct
    HCI_CMD_HDR_STATUS_OK,
    /// Opcode is unknown
    HCI_CMD_HDR_STATUS_UNKNOWN,
    /// Header is not correct
    HCI_CMD_HDR_STATUS_FAIL
};

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

/// ISO SDU Buffer structure
typedef struct
{
    /// used to put buffer in a queue
    co_list_hdr_t hdr;
    /// Time stamp in us
    uint32_t time_stamp;
    /// Packet Sequence Number
    uint16_t pkt_seq_nb;
    /// Length of the ISO SDU (in bytes) + status flag
    uint16_t sdu_len_status_flag;
    /// Length of the ISO SDU data already received (in bytes)
    uint16_t rx_sdu_len;
    /// Number of HCI ISO data packets in the SDU (used only for input direction - from Host to Controller)
    uint8_t hci_iso_data_pkt_nb;
    /// Reception on-going
    bool rx_pending;
    /// Used to know if time stamp information was present in HCI packet
    bool time_stamp_present;
    /// Pointer to SDU data
    /// Note: HCI_ISO_DATA_LOAD_HDR_LEN_MAX bytes must be reserved before SDU pointer to receive extended header
    uint8_t* p_sdu;
} hci_iso_buf_t;

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
****************************************************************************************
 * @brief Initialize HCI (including transport)
 *
 * @param[in] is_reset  True if reset is requested, false for an initialization
*****************************************************************************************
*/
void hci_initialize(bool is_reset);

#if (EMB_PRESENT)

/**
 ****************************************************************************************
 * @brief Send HCI_NB_CMP_PKTS_EVT to host to inform that TX buffer are available
 *
 * @param[in] link_id    Link identifier
 * @param[in] nb_of_pkt  Number of buffer available
 ****************************************************************************************
 */
void hci_nb_cmp_pkts_evt_send(uint16_t conhdl, uint8_t nb_of_pkt);

/**
 ****************************************************************************************
 * @brief Send HCI_HW_ERR_EVT to host to inform that a critical error has been detected that require a reset
 *
 * @param[in] hw_code    Error Code
 ****************************************************************************************
 */
void hci_hw_err_evt_send(uint8_t hw_code);

/**
 ****************************************************************************************
 * @brief Function called when an internal task needs to send a HCI message to Host
 *
 * This function decides whether the message is sent externally onto HCI Transport Layer
 * or redirected into an internal task of the other side of the HCI.
 *
 * The input message ID, length and parameters must be filled.
 * In case the message is an HCI command or event, the source ID must be filled with the
 * command opcode or event code.
 * In case the message concerns a particular BT or BLE link, the destination ID must be
 * filled with the associated link ID.
 *
 * @param[in]  param   Pointer to the parameters of the Kernel message carrying the HCI message
 *****************************************************************************************
 */
void hci_send_2_host(void *p_param);
#endif // (EMB_PRESENT)

#if (HOST_PRESENT)
/**
 ****************************************************************************************
 * @brief Function called when upper layer needs to send a HCI message to Controller
 *
 * This function decides whether the message is sent externally onto HCI Transport Layer
 * or redirected into an internal task of the other side of the HCI.
 *
 * The input message ID, length and parameters must be filled.
 * In case the message is an HCI command or event, the source ID must be filled with the
 * command opcode or event code.
 * In case the message concerns a particular BT or BLE link, the destination ID must be
 * filled with the associated link ID.
 *****************************************************************************************
 */
void hci_tl_send_2_controller(rwtl_itf_t* p_itf, void *param);

#endif // (HOST_PRESENT)

#if (BLE_EMB_PRESENT && HCI_BLE_CON_SUPPORT)
/**
 ****************************************************************************************
 * @brief Register connection handle for a BLE connection
 *
 * @param[in]  link_id  BLE connection link ID
 *****************************************************************************************
 */
void hci_ble_conhdl_register(uint8_t link_id);

/**
 ****************************************************************************************
 * @brief Unregister a BLE connection
 *
 * @param[in]  link_id  BLE connection link ID
 *****************************************************************************************
 */
void hci_ble_conhdl_unregister(uint8_t link_id);
#endif //(BLE_EMB_PRESENT && !BLE_HOST_PRESENT && HCI_BLE_CON_SUPPORT)

#if (BT_EMB_PRESENT)
/**
 ****************************************************************************************
 * @brief Register BD address for a BT ACL connection
 *
 * @param[in]  link_id  BT ACL connection link ID
 * @param[in]  bd_addr  Pointer to the device BD address associated to the connection
 *****************************************************************************************
 */
void hci_bt_acl_bdaddr_register(uint8_t link_id, struct bd_addr* bd_addr);
/**
 ****************************************************************************************
 * @brief Register connection handle for a BT ACL connection
 *
 * @param[in]  link_id  BT ACL connection link ID
 *****************************************************************************************
 */
void hci_bt_acl_conhdl_register(uint8_t link_id);

/**
 ****************************************************************************************
 * @brief Unregister a BT ACL connection
 *
 * @param[in]  link_id  BT ACL connection link ID
 *****************************************************************************************
 */
void hci_bt_acl_bdaddr_unregister(uint8_t link_id);

#endif //(BT_EMB_PRESENT)

/**
 ****************************************************************************************
 * @brief Set the event mask
 *
 * @param[in] evt_msk Pointer to the new event mask
 * @param[in] page indicate which event page should be changed
 *
 * @return The status of the event mask saving
 *****************************************************************************************
 */
uint8_t hci_evt_mask_set(struct evt_mask const *evt_msk, uint8_t page);

/**
 ****************************************************************************************
 * @brief Set the connection accept timeout
 *
 * @param[in] con_accept_to Connection accept timeout (in BT slots)
 *****************************************************************************************
 */
void hci_con_accept_to_set(uint16_t con_accept_to);

/**
 ****************************************************************************************
 * @brief Get the connection accept timeout
 *
 * @return Connection accept timeout (in BT slots)
 *****************************************************************************************
 */
uint16_t hci_con_accept_to_get(void);

#if (BT_EMB_PRESENT)
/**
 ****************************************************************************************
 * @brief Add an event filter according to the parameters of the HCI command
 *
 * Note: the consistency of the parameters according to the input has already been checked by HCI during the special
 * unpacking.
 *
 * @param[in] param      Pointer to the HCI parameter
 *
 * @return The status of the filter addition
 *****************************************************************************************
 */
uint8_t hci_evt_filter_add(struct hci_set_evt_filter_cmd const *param);

#if (MAX_NB_SYNC > 0)
/**
 ****************************************************************************************
 * @brief Get voice setting (for SCO auto-accept via event filter)
 *
 * @return   Voice settings
 *****************************************************************************************
 */
uint16_t hci_voice_settings_get(void);

/**
 ****************************************************************************************
 * @brief Set voice setting (for SCO auto-accept via event filter)
 *
 * @param[in]   voice_settings    Voice settings
 *
 * @return   Status (0: Success | Others: failure)
 *****************************************************************************************
 */
uint8_t hci_voice_settings_set(uint16_t voice_settings);
#endif // (MAX_NB_SYNC > 0)
#endif //(BT_EMB_PRESENT)

#if (EMB_PRESENT && HOST_PRESENT && HCI_TL_SUPPORT)
/**
 ****************************************************************************************
 * @brief Indicate if HCI is used by external Host, or internal Host.
 *
 * Used in Full mode only. By default HCI is used by internal Host.
 * HCI switches to external host as soon as an HCI command is received.
 *
 * @return  True: external Host, False: internal Host
 *****************************************************************************************
 */
bool hci_is_ext_host(void);
#endif // (EMB_PRESENT && HOST_PRESENT && HCI_TL_SUPPORT)

#if (BLE_EMB_PRESENT)
/**
 ****************************************************************************************
 * @brief Check if the LE event to be sent to the host is masked or not
 *
 * @param[in] evt_code  LE event code
 *
 * @return true id the event is masked, false otherwise
 *****************************************************************************************
 */
bool hci_le_evt_mask_check(uint8_t evt_code);
#endif //(BLE_EMB_PRESENT)

//common for both BLE & BT
/**
 ****************************************************************************************
 * @brief  process HostBufferSize
 *
 * @param[in] acl_pkt_len     ACL packet length
 * @param[in] nb_acl_pkts     Number of ACL packets
 *
 * @return status
 *****************************************************************************************
 */
uint8_t hci_fc_acl_buf_size_set(uint16_t acl_pkt_len, uint16_t nb_acl_pkts);
/**
 ****************************************************************************************
 * @brief  process HostBufferSize
 *
 * @param[in] sync_pkt_len    SYNC packet length
 * @param[in] nb_sync_pkts    Number of SYNC packets
 *
 * @return status
 *****************************************************************************************
 */
uint8_t hci_fc_sync_buf_size_set(uint8_t sync_pkt_len, uint16_t nb_sync_pkts);

/**
 ****************************************************************************************
 * @brief set the state of the ACL flow control
 *
 * @param[in] flow_enable   boolean state of control
 *
 * @return status
 *****************************************************************************************
 */
uint8_t hci_fc_acl_en(bool flow_enable);

/**
 ****************************************************************************************
 * @brief set the state of the SYNC flow control
 *
 * @param[in] flow_enable   boolean state of control
 *****************************************************************************************
 */
void hci_fc_sync_en(bool flow_enable);

/**
 ****************************************************************************************
 * @brief update data packet counters according to HostNumberOfCompletePackets
 *
 * @param[in] acl_pkt_nb     accumulated number for ACL handles
 ***************************************************************************************a**
 */
void hci_fc_host_nb_acl_pkts_complete(uint16_t acl_pkt_nb);

/**
 ****************************************************************************************
 * @brief update data packet counters according to HostNumberOfCompletePackets
 *
 * @param[in] sync_pkt_nb    accumulated number for SCO handles
 ***************************************************************************************a**
 */
void hci_fc_host_nb_sync_pkts_complete(uint16_t sync_pkt_nb);

#endif //HCI_PRESENT

/// @} HCI

#endif // HCI_H_
