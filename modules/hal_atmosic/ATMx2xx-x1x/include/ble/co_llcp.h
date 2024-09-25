/**
 ****************************************************************************************
 *
 * @file co_llcp.h
 *
 * @brief This file contains the LLCP Bluetooth defines, enumerations and structures
 *        definitions for use by all modules in RW stack.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 ****************************************************************************************
 */

#ifndef CO_LLCP_H_
#define CO_LLCP_H_

/**
 ****************************************************************************************
 * @addtogroup CO_BT
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "co_bt.h"
/*
 * DEFINES
 ****************************************************************************************
 */
#define LLCP_OPCODE_MASK      (0xFF)
#define LLCP_OPCODE_POS       (0)
/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */
/// Control packet op_code
/*@TRACE*/
enum co_llcp_op_code
{
    /// Connection update request
    LL_CONNECTION_UPDATE_IND_OPCODE,
    /// Channel map request
    LL_CHANNEL_MAP_IND_OPCODE,
    /// Termination indication
    LL_TERMINATE_IND_OPCODE,
    /// Encryption request
    LL_ENC_REQ_OPCODE,
    /// Encryption response
    LL_ENC_RSP_OPCODE,
    /// Start encryption request
    LL_START_ENC_REQ_OPCODE,
    /// Start encryption response
    LL_START_ENC_RSP_OPCODE,
    /// Unknown response
    LL_UNKNOWN_RSP_OPCODE,
    /// Feature request
    LL_FEATURE_REQ_OPCODE,
    /// Feature response
    LL_FEATURE_RSP_OPCODE,
    /// Pause encryption request
    LL_PAUSE_ENC_REQ_OPCODE,
    /// Pause encryption response
    LL_PAUSE_ENC_RSP_OPCODE,
    /// Version indication
    LL_VERSION_IND_OPCODE,
    /// Reject indication
    LL_REJECT_IND_OPCODE,
    /// Slave feature request
    LL_SLAVE_FEATURE_REQ_OPCODE,
    /// Connection parameters request
    LL_CONNECTION_PARAM_REQ_OPCODE,
    /// Connection parameters response
    LL_CONNECTION_PARAM_RSP_OPCODE,
    /// Reject indication extended
    LL_REJECT_EXT_IND_OPCODE,
    /// Ping request
    LL_PING_REQ_OPCODE,
    /// Ping response
    LL_PING_RSP_OPCODE,
    /// Ping request
    LL_LENGTH_REQ_OPCODE,
    /// Ping response
    LL_LENGTH_RSP_OPCODE,
    /// Phy request
    LL_PHY_REQ_OPCODE,
    /// Phy response
    LL_PHY_RSP_OPCODE,
    /// Phy update indication
    LL_PHY_UPDATE_IND_OPCODE,
    /// Min used channels indication
    LL_MIN_USED_CHANNELS_IND_OPCODE,

    /// Request creation of CIS
    LL_CIS_REQ_OPCODE = 0x1F,
    /// Response to CIS Request with Slave parameters
    LL_CIS_RSP_OPCODE = 0x21,
    /// Issued by the Master to establish the CIS with a Slave.
    LL_CIS_IND_OPCODE,
    /// Terminate the CIS channel associated with the Stream_ID and Channel_ID fields
    LL_CIS_TERMINATE_IND_OPCODE,

    /// Opcode length
    LL_OPCODE_MAX_OPCODE,
    LL_OPCODE_DEBUG = 0xFF,
};

/// LLCP PDU lengths (including op_code)
enum co_llcp_length
{
    LL_CONNECTION_UPDATE_IND_LEN     = 12,
    LL_CHANNEL_MAP_IND_LEN           = 8,
    LL_TERMINATE_IND_LEN             = 2,
    LL_ENC_REQ_LEN                   = 23,
    LL_ENC_RSP_LEN                   = 13,
    LL_START_ENC_REQ_LEN             = 1,
    LL_START_ENC_RSP_LEN             = 1,
    LL_UNKNOWN_RSP_LEN               = 2,
    LL_FEATURE_REQ_LEN               = 9,
    LL_FEATURE_RSP_LEN               = 9,
    LL_PAUSE_ENC_REQ_LEN             = 1,
    LL_PAUSE_ENC_RSP_LEN             = 1,
    LL_VERSION_IND_LEN               = 6,
    LL_REJECT_IND_LEN                = 2,
    LL_SLAVE_FEATURE_REQ_LEN         = 9,
    LL_REJECT_EXT_IND_LEN            = 3,
    LL_CONNECTION_PARAM_REQ_LEN      = 24,
    LL_CONNECTION_PARAM_RSP_LEN      = 24,
    LL_PING_REQ_LEN                  = 1,
    LL_PING_RSP_LEN                  = 1,
    LL_LENGTH_REQ_LEN                = 9,
    LL_LENGTH_RSP_LEN                = 9,
    LL_PHY_REQ_LEN                   = 3,
    LL_PHY_RSP_LEN                   = 3,
    LL_PHY_UPDATE_IND_LEN            = 5,
    LL_MIN_USED_CHANNELS_IND_LEN     = 3,

    LL_CIS_REQ_LEN                   = 24,
    LL_CIS_RSP_LEN                   = 9,
    LL_CIS_IND_LEN                   = 16,
    LL_CIS_TERMINATE_IND_LEN         = 4,

    LL_PDU_LENGTH_MAX                = 24
};


/// BIG Control packet op_code
/*@TRACE*/
enum co_big_op_code
{
    /// Channel map update
    BIG_CHANNEL_MAP_IND_OPCODE,
    /// Termination indication
    BIG_TERMINATE_IND_OPCODE,

    /// Opcode length
    BIG_OPCODE_MAX_OPCODE,
};

/// BIG PDU lengths (including op_code)
enum co_bis_length
{
    BIG_CHANNEL_MAP_IND_LEN           = 8,
    BIG_TERMINATE_IND_LEN             = 2,

    BIG_PDU_LENGTH_MAX                = 8
};


/// PDU lengths
enum co_pdu_length
{
    PDU_SCAN_REQ_LEN          = 12,
    PDU_CON_REQ_LEN           = 34,
    PDU_CON_RSP_LEN           = 14,
};

/// Bit field definitions for BN field sent over the air
///    7    6    5    4    3    2    1    0
/// +----+----+----+----+----+----+----+----+
/// |     BN_S2M     |     BN_M2S     |
/// +----+----+----+----+----+----+----+----+
enum co_llcp_cis_bn_field
{
    /// BN Master to Slave
    LLCP_CIS_BN_M2S_LSB     = 0,
    LLCP_CIS_BN_M2S_MASK    = (0x0F),

    /// BN Slave to Master
    LLCP_CIS_BN_S2M_LSB     = 4,
    LLCP_CIS_BN_S2M_MASK    = (0xF0),
};

/*
 * MESSAGES
 ****************************************************************************************
 */

/// LL_CONNECTION_UPDATE_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_connection_update_ind
{
    /// op_code
    uint8_t         op_code;
    /// window size (units of 1.25 ms)
    uint8_t         win_size;
    /// window offset (units of 1.25 ms)
    uint16_t        win_off;
    /// interval (units of 1.25 ms)
    uint16_t        interv;
    /// connection latency (unit of connection event)
    uint16_t        latency;
    /// link supervision timeout (unit of 10 ms)
    uint16_t        timeout;
    /// instant (unit of connection event)
    uint16_t        instant;
};

/// LL_CHANNEL_MAP_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_channel_map_ind
{
    /// op_code
    uint8_t            op_code;
    /// channel mapping
    struct le_chnl_map ch_map;
    /// instant
    uint16_t           instant;
};

/// LL_TERMINATE_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_terminate_ind
{
    /// op_code
    uint8_t         op_code;
    /// termination code
    uint8_t         err_code;
};

/// LL_ENC_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_enc_req
{
    /// op_code
    uint8_t               op_code;
    /// random value
    struct rand_nb        rand;
    /// ediv
    uint16_t              ediv;
    /// skdm
    struct sess_k_div_x   skdm;
    /// ivm
    struct init_vect      ivm;
};

/// LL_ENC_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_enc_rsp
{
    /// op_code
    uint8_t             op_code;
    /// skds
    struct sess_k_div_x   skds;
    /// ivs
    struct init_vect    ivs;
};

/// LL_START_ENC_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_start_enc_req
{
    /// op_code
    uint8_t             op_code;
};

/// LL_START_ENC_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_start_enc_rsp
{
    /// op_code
    uint8_t             op_code;
};

/// LL_UNKNOWN_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_unknown_rsp
{
    /// op_code
    uint8_t         op_code;
    /// unknown type
    uint8_t         unk_type;
};

/// LL_FEATURE_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_feature_req
{
    /// op_code
    uint8_t             op_code;
    /// le features
    struct le_features  feats;
};


/// LL_FEATURE_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_feature_rsp
{
    /// op_code
    uint8_t             op_code;
    /// le features
    struct le_features  feats;
};

/// LL_PAUSE_ENC_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_pause_enc_req
{
    /// op_code
    uint8_t             op_code;
};

/// LL_PAUSE_ENC_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_pause_enc_rsp
{
    /// op_code
    uint8_t             op_code;
};

/// LL_VERSION_IND structure
/*@TRACE
 * @NO_PAD
*/
struct ll_version_ind
{
    /// op_code
    uint8_t     op_code;
    /// version
    uint8_t     vers;
    /// company id
    uint16_t    compid;
    /// sub version
    uint16_t    subvers;
};

/// LL_REJECT_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_reject_ind
{
    /// op_code
    uint8_t         op_code;
    /// reject reason
    uint8_t         err_code;
};

/// LL_SLAVE_FEATURE_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_slave_feature_req
{
    /// op_code
    uint8_t             op_code;
    /// le features
    struct le_features  feats;
};

/// LL_CONNECTION_PARAM_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_connection_param_req
{
    /// op_code
    uint8_t         op_code;
    /// minimum value of connInterval (units of 1.25 ms)
    uint16_t        interval_min;
    /// maximum value of connInterval (units of 1.25 ms)
    uint16_t        interval_max;
    /// connSlaveLatency value (unit of connection event)
    uint16_t        latency;
    /// connSupervisionTimeout value (unit of 10 ms)
    uint16_t        timeout;
    /// preferred periodicity (units of 1.25 ms)
    uint8_t         pref_period;
    /// ReferenceConnEventCount (unit of connection event)
    uint16_t        ref_con_event_count;
    /// Offset0 (units of 1.25 ms)
    uint16_t        offset0;
    /// Offset1 (units of 1.25 ms)
    uint16_t        offset1;
    /// Offset2 (units of 1.25 ms)
    uint16_t        offset2;
    /// Offset3 (units of 1.25 ms)
    uint16_t        offset3;
    /// Offset4 (units of 1.25 ms)
    uint16_t        offset4;
    /// Offset5 (units of 1.25 ms)
    uint16_t        offset5;
};

/// LL_CONNECTION_PARAM_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_connection_param_rsp
{
    /// op_code
    uint8_t         op_code;
    /// minimum value of connInterval (units of 1.25 ms)
    uint16_t        interval_min;
    /// maximum value of connInterval (units of 1.25 ms)
    uint16_t        interval_max;
    /// connSlaveLatency value (unit of connection event)
    uint16_t        latency;
    /// connSupervisionTimeout value (unit of 10 ms)
    uint16_t        timeout;
    /// preferred periodicity (units of 1.25 ms)
    uint8_t         pref_period;
    /// ReferenceConnEventCount (unit of connection event)
    uint16_t        ref_con_event_count;
    /// Offset0 (units of 1.25 ms)
    uint16_t        offset0;
    /// Offset1 (units of 1.25 ms)
    uint16_t        offset1;
    /// Offset2 (units of 1.25 ms)
    uint16_t        offset2;
    /// Offset3 (units of 1.25 ms)
    uint16_t        offset3;
    /// Offset4 (units of 1.25 ms)
    uint16_t        offset4;
    /// Offset5 (units of 1.25 ms)
    uint16_t        offset5;
};

/// LL_REJECT_EXT_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_reject_ext_ind
{
    /// op_code
    uint8_t         op_code;
    /// rejected op_code
    uint8_t         rej_op_code;
    /// reject reason
    uint8_t         err_code;
};

/// LL_PING_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_ping_req
{
    /// op_code
    uint8_t         op_code;
};

/// LL_PING_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_ping_rsp
{
    /// op_code
    uint8_t         op_code;
};

/// LL_LENGTH_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_length_req
{
    /// op_code
    uint8_t     op_code;
    /// The max size in reception (unit of byte)
    uint16_t    max_rx_octets;
    /// The max time in reception (unit of microsecond)
    uint16_t    max_rx_time;
    /// The max size in transmission (unit of byte)
    uint16_t    max_tx_octets;
    /// The max time in transmission (unit of microsecond)
    uint16_t    max_tx_time;
};

/// LL_LENGTH_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_length_rsp
{
    /// op_code
    uint8_t     op_code;
    /// The max size in reception (unit of byte)
    uint16_t    max_rx_octets;
    /// The max time in reception (unit of microsecond)
    uint16_t    max_rx_time;
    /// The max size in transmission (unit of byte)
    uint16_t    max_tx_octets;
    /// The max time in transmission (unit of microsecond)
    uint16_t    max_tx_time;
};
/// LL_PHY_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_phy_req
{
    /// op_code
    uint8_t    op_code;
    /// Tx phy selection
    uint8_t    tx_phys;
    /// Rx phy selection
    uint8_t    rx_phys;
};

/// LL_PHY_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_phy_rsp
{
    /// op_code
    uint8_t    op_code;
    /// Tx phy selection
    uint8_t    tx_phys;
    /// Rx phy selection
    uint8_t    rx_phys;
};

/// LL_PHY_UPDATE_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_phy_update_ind
{
    /// op_code
    uint8_t    op_code;
    /// master to slave phy selected
    uint8_t    m_to_s_phy;
    /// slave to master phy selected
    uint8_t    s_to_m_phy;
    /// Instant
    uint16_t   instant;
};

/// LL_MIN_USED_CHANNELS_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_min_used_channels_ind
{
    /// op_code
    uint8_t    op_code;
    /// PHY(s) for which the slave has a minimum number of used channels requirement
    uint8_t    phys;
    /// minimum number of channels to be used on the specified PHY
    uint8_t    min_used_ch;
};

/// LL_CIS_REQ structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_cis_req
{
    /// op_code
    uint8_t         op_code;
    /// Identifier of the Connected Isochronous Group
    uint8_t         cig_id;
    /// Identifier of the Connected Isochronous Stream
    uint8_t         cis_id;
    /// Physical Channel Info Master to Slave PHY
    uint8_t         phy_m2s;
    /// Physical Channel Info Slave to Master PHY
    uint8_t         phy_s2m;
    /// Max Payload Size: Master to Slave (value between 0 and 251)
    uint8_t         max_pld_size_m2s;
    /// Max Payload Size: Slave to Master (value between 0 and 251)
    uint8_t         max_pld_size_s2m;
    /// Number of Sub Event (value between 1 and 31)
    uint8_t         nse;
    /// Sub interval in microseconds (Range 400us - Connection Interval)
    uint32_t        sub_interval;
    /// Burst number: Number of new packet per channel interval
    /// bit[0:3] : Master to Slave Burst number The range shall be 0 to 15
    /// bit[4:7] : Slave to Master Burst number The range shall be 0 to 15
    uint8_t         bn;
    /// Master to Slave Flush timeout (value between 1 and 255)
    uint8_t         ft_m2s;
    /// Slave to Master Flush timeout (value between 1 and 255)
    uint8_t         ft_s2m;
    /// Time between two consecutive Connected Isochronous Stream anchor points.
    /// The Iso_Interval field shall be between 4 and 3200 (i.e. 5ms to 4s).
    uint16_t        iso_interval;
    /// Minimum time in microseconds between the start of the connection event with the
    /// connection event counter = connEventCount and the first CIS anchor point.
    /// It shall have a value between 400µs and connInterval
    uint32_t        cis_offset_min;
    /// Maximum time in microseconds between the start of the connection event with the
    /// connection event counter = connEventCount and the first CIS anchor point.
    /// It shall have a value between CIS_Offset_Min and connInterval.
    uint32_t        cis_offset_max;

    /// Reference point where the Offset_Min and Offset_Max are applied to determine the first CIS anchor point.
    /// It be set to a connection event counter value that meets the requirement
    /// currEvent – 2^14 < connEventCount < currEvent + 2^14 (modulo 65536), where currEvent is the counter value for
    /// the connection event where the LL_CIS_REQ PDU is being transmitted (or retransmitted).
    uint16_t        conn_event_cnt;
};

/// LL_CIS_RSP structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_cis_rsp
{
    /// op_code
    uint8_t         op_code;
    /// Minimum time in microseconds between the start of the connection event with the
    /// connection event counter = connEventCount and the first CIS anchor point.
    /// It shall have a value between 400µs and connInterval
    uint32_t        cis_offset_min;
    /// Maximum time in microseconds between the start of the connection event with the
    /// connection event counter = connEventCount and the first CIS anchor point.
    /// It shall have a value between CIS_Offset_Min and connInterval.
    uint32_t        cis_offset_max;
    /// Event counter of the ACL event from which the Ch_Offset_Min and the Ch_Offset_Max are referenced
    uint16_t        conn_event_cnt;
};

/// LL_CIS_UPDATE_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_cis_ind
{
    /// op_code
    uint8_t         op_code;
    /// Access Address field is the number used to identify the CIS channel.
    uint32_t        access_addr;
    /// Time in microseconds from the start of the ACL connection event referenced by the connEventCount to the first
    /// CIS anchor point.
    uint32_t        cis_offset;
    /// Time in microseconds from the first anchor point of the Stream being set up to the CIG Synchronization point
    /// in the same isochronous interval. The CIS_Synchronization_Delay is calculated by the master for each CIS
    /// separately, and sent to the slave in the LL_CIS_IND when establishing the CIS.
    /// The slave uses the CIS_Synchronization_Delay parameter to determine the CIG Synchronization point.
    uint32_t        cig_sync_delay;
    /// Time reference when all CIS events are completed. The CIG Synchronization point is at the end of the last
    /// sub-event of the last CIS in the CIG in an Iso_Interval. The CIG_Synchronization_Delay is the time in
    /// microseconds between the start of the first subevent of the first CIS in the CIG and the
    /// CIG Synchronization point
    uint32_t        cis_sync_delay;
    /// Reference point where the CIS_Offset is applied to determine the first CIS anchor point.
    /// The connEventCount shall be set to a connection event counter value that meets the requirement
    /// currEvent – 2^14 < connEventCount < currEvent + 2^14 (modulo 65536), where currEvent is the counter value
    /// for the connection event where the LL_CIS_IND PDU is being transmitted (or retransmitted).
    uint16_t        conn_event_cnt;
};

/// LL_CIS_TERMINATE_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  ll_cis_terminate_ind
{
    /// op_code
    uint8_t         op_code;
    /// Identifier of the Connected Isochronous Group
    uint8_t         cig_id;
    /// Identifier of the Connected Isochronous Stream
    uint8_t         cis_id;
    /// Reason for CIS termination
    uint8_t         reason;
};


/// LLCP pdu format
/*@TRACE
 @trc_ref co_llcp_op_code
 */
union llcp_pdu
{
    /// op_code
    uint8_t  op_code;

    //@trc_union op_code == LL_CONNECTION_UPDATE_IND_OPCODE
    struct ll_connection_update_ind     con_update_ind;

    //@trc_union op_code == LL_CHANNEL_MAP_IND_OPCODE
    struct ll_channel_map_ind           channel_map_ind;

    //@trc_union op_code == LL_TERMINATE_IND_OPCODE
    struct ll_terminate_ind             terminate_ind;

    //@trc_union op_code == LL_ENC_REQ_OPCODE
    struct ll_enc_req                   enc_req;

    //@trc_union op_code == LL_ENC_RSP_OPCODE
    struct ll_enc_rsp                   enc_rsp;

    //@trc_union op_code == LL_START_ENC_REQ_OPCODE
    struct ll_start_enc_req             start_enc_req;

    //@trc_union op_code == LL_START_ENC_RSP_OPCODE
    struct ll_start_enc_rsp             start_enc_rsp;

    //@trc_union op_code == LL_UNKNOWN_RSP_OPCODE
    struct ll_unknown_rsp               unknown_rsp;

    //@trc_union op_code == LL_FEATURE_REQ_OPCODE
    struct ll_feature_req               feats_req;

    //@trc_union op_code == LL_FEATURE_RSP_OPCODE
    struct ll_feature_rsp               feats_rsp;

    //@trc_union op_code == LL_PAUSE_ENC_REQ_OPCODE
    struct ll_pause_enc_req             pause_enc_req;

    //@trc_union op_code == LL_PAUSE_ENC_RSP_OPCODE
    struct ll_pause_enc_rsp             pause_enc_rsp;

    //@trc_union op_code == LL_VERSION_IND_OPCODE
    struct ll_version_ind               vers_ind;

    //@trc_union op_code == LL_REJECT_IND_OPCODE
    struct ll_reject_ind                reject_ind;

    //@trc_union op_code == LL_SLAVE_FEATURE_REQ_OPCODE
    struct ll_slave_feature_req         slave_feature_req;

    //@trc_union op_code == LL_CONNECTION_PARAM_REQ_OPCODE
    struct ll_connection_param_req      con_param_req;

    //@trc_union op_code == LL_CONNECTION_PARAM_RSP_OPCODE
    struct ll_connection_param_rsp      con_param_rsp;

    //@trc_union op_code == LL_REJECT_EXT_IND_OPCODE
    struct ll_reject_ext_ind            reject_ind_ext;

    //@trc_union op_code == LL_PING_REQ_OPCODE
    struct ll_ping_req                  ping_req;

    //@trc_union op_code == LL_PING_RSP_OPCODE
    struct ll_ping_rsp                  ping_rsp;

    //@trc_union op_code == LL_LENGTH_REQ_OPCODE
    struct ll_length_req                length_req;

    //@trc_union op_code == LL_LENGTH_RSP_OPCODE
    struct ll_length_rsp                length_rsp;

    //@trc_union op_code == LL_PHY_REQ_OPCODE
    struct ll_phy_req                   phy_req;

    //@trc_union op_code == LL_PHY_RSP_OPCODE
    struct ll_phy_rsp                   phy_rsp;

    //@trc_union op_code == LL_PHY_UPDATE_IND_OPCODE
    struct ll_phy_update_ind            phy_upd_ind;

    //@trc_union op_code == LL_MIN_USED_CHANNELS_IND_OPCODE
    struct ll_min_used_channels_ind     min_used_channels_ind;

    //@trc_union op_code == LL_CIS_REQ_OPCODE
    struct  ll_cis_req                  cis_req;

    //@trc_union op_code == LL_CIS_RSP_OPCODE
    struct  ll_cis_rsp                  cis_rsp;

    //@trc_union op_code == LL_CIS_IND_OPCODE
    struct  ll_cis_ind                  cis_ind;

    //@trc_union op_code == LL_CIS_TERMINATE_IND_OPCODE
    struct  ll_cis_terminate_ind        cis_terminate_ind;
};


/// BIG_CHANNEL_MAP_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  big_channel_map_ind
{
    /// op_code
    uint8_t            op_code;
    /// channel mapping
    struct le_chnl_map ch_map;
    /// BIG Event Count
    uint16_t           evt_cnt;
};

/// BIG_TERMINATE_IND structure.
/*@TRACE
 * @NO_PAD
*/
struct  big_terminate_ind
{
    /// op_code
    uint8_t         op_code;
    /// termination code
    uint8_t         err_code;
};


/// BIS PDU format
/*@TRACE
 @trc_ref co_big_op_code
 */
union big_pdu
{
    /// op_code
    uint8_t  op_code;

    //@trc_union op_code == BIG_CHANNEL_MAP_IND_OPCODE
    struct big_channel_map_ind channel_map_ind;

    //@trc_union op_code == BIG_TERMINATE_IND_OPCODE
    struct big_terminate_ind   terminate_ind;
};

/// @} CO_BT
#endif // CO_LLCP_H_
