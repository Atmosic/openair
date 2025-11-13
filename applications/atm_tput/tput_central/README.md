# ATM BLE Throughput Central Test Application

## Overview

The ATM BLE Throughput Central Test Application is a Bluetooth Low Energy (BLE) central device application designed to measure throughput performance between a central and peripheral device. This application automatically scans for and connects to a compatible peripheral device, then performs bidirectional throughput measurements.

## Features

- **Automatic Device Discovery**: Scans for and connects to devices advertising as "ATM_TPUTP Periph"
- **Bidirectional Throughput Testing**: Measures both Client-to-Server (C2S) and Server-to-Client (S2C) throughput
- **Configurable PHY Modes**: Supports 1M, 2M, and Coded PHY (S2 and S8) modes
- **Connection Parameter Optimization**: Configurable connection intervals for optimal performance
- **Data Length Extension**: Supports extended data length for improved throughput
- **MTU Exchange**: Automatic MTU negotiation for larger packet sizes
- **RSSI Filtering**: Configurable RSSI threshold for device filtering
- **Shell Interface**: Interactive shell commands for runtime configuration and testing

## Hardware Requirements

### UART Configuration

This application uses **UART0** for both the console output and the interactive shell interface. Ensure that UART0 is properly configured and connected to your terminal/console for:
- Application status messages and throughput results
- Interactive shell command input and output
- Debug and error messages

## Configuration

### Kconfig Options

| Option | Description | Default |
|--------|-------------|---------|
| `CONFIG_ATM_BT_RSSI_THRESHOLD` | RSSI threshold for device filtering (dBm) | -40 |
| `CONFIG_ATM_TPUT_TEST_CONN_INTERVAL_MIN` | Minimum connection interval (1.25ms units) | 20 |
| `CONFIG_ATM_TPUT_TEST_CONN_INTERVAL_MAX` | Maximum connection interval (1.25ms units) | 20 |
| `CONFIG_ATM_TPUT_TEST_PHY_MODE` | PHY mode (0=1M, 1=2M, 2=CODED_S2, 3=CODED_S8) | 1 |

## Custom Shell Commands

The application provides several shell commands for interactive testing and configuration:

### `start_test`
Starts the throughput test sequence.
```
start_test
```
- Initiates connection parameter updates if configured
- Runs tests based on configured test direction (C2S, S2C, or both)
- Requires an active connection to a peripheral device

### `ack <on|off>`
Configures the acknowledgment policy for throughput testing.
```
ack on    # Use ACK mode (indications/write-with-response)
ack off   # Use NO-ACK mode (notifications/write-without-response)
```
- `on`: Uses GATT indications and write-with-response for reliable data transfer
- `off`: Uses GATT notifications and write-without-response for maximum throughput

### `set_phy <1M|2M|CODED_S2|CODED_S8>`
Sets the BLE PHY mode for the connection.
```
set_phy 1M        # Use 1 Mbps PHY
set_phy 2M        # Use 2 Mbps PHY
set_phy CODED_S2  # Use Coded PHY with S=2
set_phy CODED_S8  # Use Coded PHY with S=8
```
- Changes take effect on the next connection or when `start_test` is called
- Both devices must support the selected PHY mode

### `set_conn_interval <interval>`
Sets the connection interval for optimal throughput.
```
set_conn_interval <interval>
```
- `interval`: Connection interval in 1.25ms units (range: 6-3200)
- Example: `set_conn_interval 20` sets 25ms interval (20 × 1.25ms)
- Lower intervals generally provide higher throughput but consume more power
- **Note**: The supervision timeout is automatically adjusted based on the connection interval to meet BLE specification requirements. For intervals ≥400, the timeout will be increased accordingly.

### `set_payload_size <size>`
Sets the payload size for both C2S and S2C transactions.
```
set_payload_size <size>
```
- `size`: Payload size in bytes (range: 1-244)
- Example: `set_payload_size 100` sets 100-byte payloads for both directions
- Larger payloads generally provide higher throughput but may be limited by MTU

### `show_payload_size`
Displays the current payload size configuration.
```
show_payload_size
```
- Shows the current payload size in bytes for both C2S and S2C transactions

### `set_packet_count <count>`
Sets the number of packets to send during throughput tests.
```
set_packet_count <count>
```
- `count`: Number of packets to send (range: 1-65535)
- Example: `set_packet_count 500` sends 500 packets per test
- Total data transferred = packet_count × payload_size
- Default: 1000 packets

### `show_packet_count`
Displays the current packet count configuration.
```
show_packet_count
```
- Shows the current number of packets that will be sent during tests

### `set_tx_power <power>` (Atmosic Vendor Command)
Sets the TX power for both central and peripheral devices using Atmosic vendor API.
```
set_tx_power <power>
```
- `power`: TX power level in dBm
- Supported levels: -20, -10, -8, -4, -2, 0, 2, 4, 6, 8, 10 dBm
- Example: `set_tx_power 6` sets TX power to 6 dBm on both devices
- Requires an active BLE connection
- Automatically synchronizes TX power between central and peripheral
- Only available when `CONFIG_VND_API_SET_CON_TX_POWER` is enabled

### `show_tx_power`
Displays the current TX power setting.
```
show_tx_power
```
- Shows the current TX power level in dBm

### `show_tx_power_info`
Displays TX power control information and supported levels.
```
show_tx_power_info
```
- Shows supported TX power levels
- Displays current TX power setting
- Displays connection status
- Provides usage information

### `set_test_direction <direction>`
Configures which tests to run during throughput testing.
```
set_test_direction c2s    # Run C2S (Client-to-Server) test only
set_test_direction s2c    # Run S2C (Server-to-Client) test only
set_test_direction both   # Run both C2S and S2C tests (default)
```
- `c2s`: Only measures central-to-peripheral throughput
- `s2c`: Only measures peripheral-to-central throughput
- `both`: Runs C2S test followed by S2C test (default behavior)

### `show_test_direction`
Displays the current test direction configuration.
```
show_test_direction
```
- Shows whether tests will run C2S only, S2C only, or both

## Usage

### Test Procedure

1. **Start peripheral device**: Ensure a compatible peripheral device is running and advertising
2. **Monitor connection**: The central will automatically scan and connect to the peripheral
3. **Configure test parameters** (optional):
   ```
   set_phy 2M
   set_conn_interval 20
   set_payload_size 200
   set_packet_count 500
   set_tx_power 6
   set_test_direction both
   ack off
   show_payload_size
   show_packet_count
   show_tx_power
   show_test_direction
   ```
4. **Run throughput test**:
   ```
   start_test
   ```
5. **View results**: Throughput measurements will be displayed in the console
