/**
 ****************************************************************************************
 *
 * @file gapc.h
 *
 * @brief Generic Access Profile Controller Header.
 *
 * Copyright (C) RivieraWaves 2009-2016
 *
 ****************************************************************************************
 */


#ifndef _GAPC_H_
#define _GAPC_H_

/**
 ****************************************************************************************
 * @addtogroup GAPC Generic Access Profile Controller
 * @ingroup GAP
 * @brief  Generic Access Profile Controller.
 *
 * The GAP Controller module is responsible for providing an API to the application in
 * to perform GAP action related to a BLE connection (pairing, update parameters,
 * disconnect ...). GAP controller is multi-instantiated, one task instance per BLE
 * connection.
 *
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "rwip_config.h"

#if (BLE_GAPC)

#include "ke_task.h"
#include "gap.h"
#include "smpc.h"



/*
 * DEFINES
 ****************************************************************************************
 */


/// Operation type
enum gapc_op_type
{
    /// Operation used to manage Link (update params, get peer info)
    GAPC_OP_LINK_INFO    = 0x00,

    /// Operation used to manage SMP
    GAPC_OP_SMP          = 0x01,

    /// Operation used to manage connection update
    GAPC_OP_LINK_UPD     = 0x02,

    /// Max number of operations
    GAPC_OP_MAX
};

/// Link security status. This status represents the authentication/authorization/bonding levels of the connection
enum gapc_lk_sec_req
{
    /// Link is bonded
    GAPC_LK_BONDED,
    /// Link is Encrypted
    GAPC_LK_ENCRYPTED,
    /// Link LTK Exchanged during pairing
    GAPC_LK_LTK_PRESENT,
};

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

#ifndef CFG_ROM // CEVA_CASE_14550
/// Connection update responder data
typedef struct gapc_le_con_up_rsp_data
{
    /// Connection interval minimum
    uint16_t         intv_min;
    /// Connection interval maximum
    uint16_t         intv_max;
    /// Latency
    uint16_t         latency;
    /// Supervision timeout
    uint16_t         time_out;
    /// SIG Packet identifier
    uint8_t          pkt_id;
    /// True for an L2CAP negotiation, False otherwise
    bool             l2cap_nego;
} gapc_le_con_up_rsp_data_t;
#endif
/// GAP controller environment variable structure.
struct gapc_env_tag
{
    /// Request operation Kernel message
    void* operation[GAPC_OP_MAX];
#ifndef CFG_ROM // CEVA_CASE_14550
    /// Pointer to parameters used to handle LE Connection update request initiated by peer
    gapc_le_con_up_rsp_data_t*  p_le_con_up_rsp_data;
#endif
    /// Source task id of requested disconnection
    ke_task_id_t disc_requester;
    /// Destination task ID for asynchronous events not linked to an operation
    ke_task_id_t dest_task_id;

    /* Connection parameters to keep */

    /// Security Management Protocol environment variables
    struct smpc_env smpc;

    /// connection handle
    uint16_t conhdl;

    /// Configuration fields (@see enum gapc_fields)
    uint8_t fields;

    /// BD Address used for the link that should be kept
    struct gap_bdaddr src[SMPC_INFO_MAX];

    /// Relevant information of peer LE features 8-byte array
    uint8_t features;
    /// Channel Selection Algorithm
    uint8_t chan_sel_algo;
};



/*
 * MACROS
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Retrieve connection index from connection handle.
 *
 * @param[in] conhdl Connection handle
 *
 * @return Return found connection index, GAP_INVALID_CONIDX if not found.
 ****************************************************************************************
 */
uint8_t gapc_get_conidx(uint16_t conhdl);

/**
 ****************************************************************************************
 * @brief Retrieve connection handle from connection index.
 *
 * @param[in] conidx Connection index
 *
 * @return Return found connection handle, GAP_INVALID_CONHDL if not found.
 ****************************************************************************************
 */
uint16_t gapc_get_conhdl(uint8_t conidx);

/**
 ****************************************************************************************
 * @brief Retrieve connection role from connection index.
 *
 * @param[in] conidx Connection index
 *
 * @return Return found connection role
 ****************************************************************************************
 */
uint8_t gapc_get_role(uint8_t conidx);

/**
 ****************************************************************************************
 * @brief Set resolvable address used for connection establishment as local address.
 * 
 * @brief conidx    Connection index
 * @brief p_addr    Pointer to the resolvable address used by either advertising activity or
 * resolvable activity.
 ****************************************************************************************
 */
void gapc_set_local_addr(uint8_t conidx, uint8_t *p_addr);

/**
 ****************************************************************************************
 * @brief Retrieve connection address information on current link.
 *
 * @param[in] conidx Connection index
 * @param[in] src    Connection information source
 *
 * @return Return found connection address
 ****************************************************************************************
 */
struct gap_bdaddr* gapc_get_bdaddr(uint8_t conidx, uint8_t src);

/**
 ****************************************************************************************
 * @brief Get destination task id for asynchronous event, meaning events that are not
 * linked to an operation.
 * Note the provided connection index shall be valid (gapc_env[conidx] is not NULL)
 *
 * @param[in] conidx        Connection Index
 *
 * @return ID of the destination task.
 ****************************************************************************************
 */
ke_task_id_t gapc_get_dest_task(uint8_t conidx);

/**
 ****************************************************************************************
 * @brief Check if current link support security requirements.
 *
 * @param[in] conidx  Connection index
 * @param[in] sec_req Link security requirement to test
 *
 * @return True if link requirement is supported, False else.
 ****************************************************************************************
 */
bool gapc_is_sec_set(uint8_t conidx, uint8_t sec_req);

/**
 ****************************************************************************************
 * @brief Retrieve Link Security level
 *
 * @param[in] conidx  Connection index
 *
 * @return Link Security level.
 ****************************************************************************************
 */
uint8_t gapc_lk_sec_lvl_get(uint8_t conidx);

/**
 ****************************************************************************************
 * @brief Retrieve the encryption key size of the connection
 *
 * @param[in] conidx Connection index
 *
 * @return encryption key size (size is 7 - 16 byte range)
 *
 ****************************************************************************************
 */
uint8_t gapc_enc_keysize_get(uint8_t conidx);

/**
 ****************************************************************************************
 * @brief Get Service Change Client Configuration
 *
 * @param[in] conidx Connection index
 *
 * @return Service Change Client Configuration
 ****************************************************************************************
 */
bool gapc_svc_chg_ccc_get(uint8_t conidx);

/**
 ****************************************************************************************
 * @brief Set Service Change Client Configuration
 *
 * @param[in] conidx Connection index
 * @param[in] enable True if CCC is enabled, False else
 *
 ****************************************************************************************
 */
void gapc_svc_chg_ccc_set(uint8_t conidx, bool enable);

/**
 ****************************************************************************************
 * Retrieve if current connection index is used for a discovery purpose such as
 * Name discovery
 *
 * @param conidx Index of the specific connection
 *
 * @return true if connection has a discovery purpose, False else
 ****************************************************************************************
 */
bool gapc_is_disc_connection(uint8_t conidx);

#endif // (BLE_GAPC)
/// @} GAPC

#endif /* _GAPC_H_ */
