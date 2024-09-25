/**
 ****************************************************************************************
 *
 * @file rwtl.h
 *
 * @brief RW Transport Layer header file. Defines a common interface for any transport layers
 *
 * Copyright (C) RivieraWaves 2009-2024
 * Release Identifier: dc6acdca
 *
 ****************************************************************************************
 */

#ifndef RWTL_H_
#define RWTL_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"  // stack configuration

#include "rwip.h"            // SW interface

#include <stdint.h>       // standard integer definition
#include <stdbool.h>      // standard boolean definition

/*
 * DEFINES
 ****************************************************************************************
 */

/// Event from message transport layer
enum rwtl_rx_event
{
    /// Message Header received.
    RWTL_HEADER,
    /// Message payload received
    RWTL_PAYLOAD,
    /// Complete message received.
    RWTL_COMPLETE_MSG,
};

/*
 * TYPES DEFINITIONS
 ****************************************************************************************
 */

typedef struct rwtl_itf_s rwtl_itf_t;
typedef struct rwtl_tx_client_s rwtl_tx_client_t;

/// Interface of RW transport layer interface
struct rwtl_itf_s
{
    /**
     ****************************************************************************************
     * @brief Callback executed by a transmitter client in order to send a message over transport layer
     *
     * @param[in] p_itf Pointer to transport layer interface used to send message
     * @param[in] p_client Pointer to client that expects message to be sent
     ****************************************************************************************
     */
    void (*cb_send)(rwtl_itf_t* p_itf, rwtl_tx_client_t* p_client);
};

/**
 ****************************************************************************************
 * @brief Callback executed when client message has been transmitted by message transport layer
 *
 * @param[in] p_client Pointer to client that can be used to retrieve context information
 ****************************************************************************************
 */
typedef void (*rwtl_tx_cb_sent)(rwtl_tx_client_t* p_client);

/// Interface that must be followed by a client expecting to receive message on a message transport layer
struct rwtl_tx_client_s
{
    /// Used to push client in a transmission queue
    co_list_hdr_t hdr;
    /// Callback executed when client message has been transmitted by message transport layer
    rwtl_tx_cb_sent cb_sent;

    /// Logical channel message of message to transmit
    uint8_t lc;
    /// Length of message to transmit
    uint16_t data_len;
    /// Pointer to message to transmit (1 byte must be available on top of buffer to add logical channel)
    uint8_t* p_data;
};

#if (RWTL_SUPPORT)

/// Reception information
typedef struct
{
    /// Length of message to receive
    int16_t data_len;
    /// Pointer where message should be filled
    uint8_t* p_data;
} rwtl_rx_next_t;

typedef struct rwtl_rx_client_s rwtl_rx_client_t;

/// Interface that must be followed by a client expecting to receive message on a transport layer
struct rwtl_rx_client_s
{
    /**
     ****************************************************************************************
     * @brief Callback executed when some data has been received from transport layer
     *
     * What to do when following event are received:
     * - #RWTL_HEADER: Message Header received, check if there is an error. If no error detected either wait
     *   for payload data or reception of new message.
     * - #RWTL_PAYLOAD: Payload data expected has been received.
     * - #RWTL_COMPLETE_MSG: A complete message has been received, returned information will be ignored, automatically
     *   transport layer will wait for a new message
     *
     * @param[in] p_itf    Pointer to transport layer interface that receive data
     * @param[in] event    Reception event (see #rwtl_rx_event enumeration)
     * @param[in] data_len Length of data received
     * @param[in] p_data   Pointer to buffer that contains received data
     *
     * @return What to do after reception if #RWTL_HEADER event is received:
     *          - Data length = 0: Wait for a new message
     *          - Data length > 0: If payload data expected. (p_data pointer shall be valid)
     *          - Data length < 0: An error has been detected, let transport layer handle it.
     *
     *         For other events, a new message is expected
     ****************************************************************************************
     */
    rwtl_rx_next_t (*cb_received)(rwtl_itf_t* p_itf, uint8_t event, const uint8_t* p_hdr, uint16_t data_len, const uint8_t* p_data);

    /// Logical channel message expected by client
    uint8_t lc;
    /// Size of message header
    uint8_t header_len;
    /// Length of expected message pattern used to exit from out of sync state (0 if not supported).
    uint8_t sync_pattern_len;
    /// Pointer to message pattern used to exit from out of sync state. This pattern must contain the logical channel.
    const uint8_t* p_sync_pattern;
};


/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initialize environment
 *****************************************************************************************
 */
void rwtl_init(bool reset);

/**
 ****************************************************************************************
 * @brief Allows a client to receive message on a specific logical channel
 *
 * @param[in] p_client Pointer to client structure that expects message reception over message transport layer
 *****************************************************************************************
 */
void rwtl_rx_client_subscribe(const rwtl_rx_client_t* p_client);

/// Prepare TX Client structure before requesting transmission
__INLINE void rwtl_tx_prepare(rwtl_tx_client_t* p_client, uint8_t lc, uint16_t data_len, uint8_t* p_data)
{
    p_client->lc = lc;
    p_client->data_len = data_len;
    p_client->p_data = p_data;
}

/**
 ****************************************************************************************
 * @brief Retrieve receive client using logical channel.
 *****************************************************************************************
 */
const rwtl_rx_client_t* rwtl_rx_client_get(uint8_t lc);

/**
 ****************************************************************************************
 * @brief Check if a synchronization message has been received.
 *
 *        Last byte of buffer correspond to last byte received.
 *        Synchronization message comparison must be perform in reverse order, starting from last received byte up to
 *        size of sync patterns (see #rwtl_rx_client_t.p_sync_pattern)
 *
 * @param[in] buf_len Size of buffer
 * @param[in] p_buf   Pointer to buffer that contains received data
 *
 * @return NULL if no sync message found; pointer to RX client that match sync pattern otherwise.
 *****************************************************************************************
 */
const rwtl_rx_client_t* rwtl_check_sync_msg(uint8_t buf_len, const uint8_t* p_buf);

#if (!EMB_PRESENT && HCI_TL_SUPPORT)
/**
 ****************************************************************************************
 * @brief Retrieve host to controller interface
 *
 * @return Pointer to transport layer interface used to communicate with external controller
 *****************************************************************************************
 */
rwtl_itf_t* rwtl_host_to_ctrl_itf_get(void);
#endif // (!EMB_PRESENT && HCI_TL_SUPPORT)

/**
 ****************************************************************************************
 * @brief Retrieve transport layer interface
 *
 * @return Pointer to transport layer interface
 *****************************************************************************************
 */
rwtl_itf_t* rwtl_itf_get(void);

/**
 ****************************************************************************************
 * @brief Start message transports layers input flow
 *
 *****************************************************************************************
 */
void rwtl_start(void);

/**
 ****************************************************************************************
 * @brief Try to stop message transports layers input flow
 *
 * @return true if flow was stopped, false otherwise
 *****************************************************************************************
 */
bool rwtl_stop(void);

#endif // (RWTL_SUPPORT)
#endif // RWTL_H_
