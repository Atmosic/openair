/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Device name used for BLE advertising */
#define DEVICE_NAME CONFIG_BT_DEVICE_NAME

/** @brief Length of device name string (excluding null terminator) */
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)

/**
 * @brief Callback function type for throughput measurement completion
 *
 * This callback is invoked when a throughput measurement (C2S or S2C) completes.
 *
 * @param conn Bluetooth connection handle
 * @param throughput Measured throughput in bits per second (bps)
 */
typedef void (*atm_tput_measurement_cb)(struct bt_conn *conn, double throughput);

/**
 * @brief Callback function type for service ready notification
 *
 * This callback is invoked when the throughput service is ready for testing
 * after successful connection and service discovery.
 */
typedef void (*atm_tput_service_ready_cb)(void);

/**
 * @brief Connect to throughput service and register ready callback
 *
 * Initiates connection to the BLE throughput service on the specified connection.
 * The ready callback will be invoked when service discovery is complete and
 * the service is ready for throughput testing.
 *
 * @param conn Bluetooth connection handle
 * @param cb Callback to invoke when service is ready (can be NULL)
 */
void atm_tput_service_connect(struct bt_conn *conn, atm_tput_service_ready_cb cb);

/**
 * @brief Start Client-to-Server (C2S) throughput measurement
 *
 * Initiates a throughput test where the central device writes data to the
 * peripheral device. The measurement callback will be invoked with the
 * calculated throughput when the test completes.
 *
 * @param conn Bluetooth connection handle
 * @param cb Callback to invoke when measurement completes
 */
void atm_tput_measure_c2s(struct bt_conn *conn, atm_tput_measurement_cb cb);

/**
 * @brief Start Server-to-Client (S2C) throughput measurement
 *
 * Initiates a throughput test where the peripheral device sends notifications
 * or indications to the central device. The measurement callback will be
 * invoked with the calculated throughput when the test completes.
 *
 * @param conn Bluetooth connection handle
 * @param cb Callback to invoke when measurement completes
 */
void atm_tput_measure_s2c(struct bt_conn *conn, atm_tput_measurement_cb cb);

/**
 * @brief Send echo test data
 *
 * Sends test data to the connected device for echo testing purposes.
 *
 * @param conn Bluetooth connection handle
 * @param data Null-terminated string data to send
 */
void atm_echo_test(struct bt_conn *conn, char *data);

/**
 * @brief Set payload size for throughput tests
 *
 * Configures the payload size (in bytes) used for each packet during
 * throughput measurements. This affects both C2S and S2C tests.
 *
 * @param payload_size Payload size in bytes
 */
void atm_tput_set_payload_size(uint32_t payload_size);

/**
 * @brief Get current payload size configuration
 *
 * @return Current payload size in bytes
 */
uint32_t atm_tput_get_payload_size(void);

/**
 * @brief Set packet count for throughput tests
 *
 * Configures the number of packets to send during throughput measurements.
 * This affects both C2S and S2C tests.
 *
 * @param packet_count Number of packets to send
 */
void atm_tput_set_packet_count(uint16_t packet_count);

/**
 * @brief Get current packet count configuration
 *
 * @return Current packet count
 */
uint16_t atm_tput_get_packet_count(void);

/**
 * @brief Set TX power for the connection
 *
 * Configures the transmission power for the specified connection using
 * the Atmosic vendor API (if available). This affects signal strength
 * and potentially throughput performance.
 *
 * @param conn Bluetooth connection handle
 * @param tx_power TX power in dBm
 */
void atm_tput_set_tx_power(struct bt_conn *conn, int8_t tx_power);

/**
 * @brief Get current TX power configuration
 *
 * @return Current TX power in dBm
 */
int8_t atm_tput_get_tx_power(void);

#ifdef CONFIG_AUTO_TEST
/**
 * @brief Command value for automatic test termination
 *
 * This command is sent to signal the end of automated testing when
 * CONFIG_AUTO_TEST is enabled. Used in CI/CD and automated test environments.
 */
#define ATM_TPUT_END_TEST_CMD 0xFF

/**
 * @brief Signal test completion to connected device
 *
 * Sends an end-test command to the connected device to signal that
 * automated testing is complete. Only available when CONFIG_AUTO_TEST
 * is enabled.
 *
 * @param conn Bluetooth connection handle
 */
void atm_tput_client_done(struct bt_conn *conn);
#endif

/**
 * @brief Global flag controlling acknowledgment mode for S2C tests
 *
 * When true, S2C tests use indications (with acknowledgments).
 * When false, S2C tests use notifications (without acknowledgments).
 * This affects throughput performance and reliability characteristics.
 */
extern bool use_ack_mode;

#ifdef __cplusplus
}
#endif
