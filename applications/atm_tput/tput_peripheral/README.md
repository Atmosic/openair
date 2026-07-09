# ATM BLE Throughput Peripheral Test Application

## Overview

The ATM BLE Throughput Peripheral Test Application is a Bluetooth Low Energy (BLE) peripheral device application designed to work with the corresponding central application for throughput performance measurements. This application advertises as "ATM_TPUTP Periph" and provides a GATT service for bidirectional throughput testing.

## Features

- **Automatic Advertising**: Advertises with the name "ATM_TPUTP Periph" for easy discovery
- **GATT Throughput Service**: Provides custom GATT service for throughput measurements
- **Connection Parameter Negotiation**: Supports connection parameter updates from central
- **PHY Mode Support**: Supports 1M, 2M, and Coded PHY modes
- **Data Length Extension**: Supports extended data length for improved throughput
- **MTU Exchange**: Automatic MTU negotiation for larger packet sizes
- **Connection Monitoring**: Logs connection events and parameter changes
- **TX Power Control**: Supports TX power control from central

## Building and Running

This application is built from `openair/applications/atm_tput/tput_peripheral`.

### Standard Build

```bash
west build -p always -b <BOARD> openair/applications/atm_tput/tput_peripheral --sysbuild -T applications.atm_tput.tput_peripheral.atm
```

### Two-Device Auto-Test Build

Use this target when pairing with the matching central auto-test target:

```bash
west build -p always -b <BOARD> openair/applications/atm_tput/tput_peripheral --sysbuild -T applications.atm_tput.tput_peripheral.atm.two_dev
```

### MCUboot + Flash XIP Build

```bash
west build -p always -b <BOARD>@mcuboot openair/applications/atm_tput/tput_peripheral --sysbuild -T applications.atm_tput.tput_peripheral.atm.mcuboot.flash_xip
```

### MCUboot + Flash XIP Overwrite-Only Build

```bash
west build -p always -b <BOARD>@mcuboot openair/applications/atm_tput/tput_peripheral --sysbuild -T applications.atm_tput.tput_peripheral.atm.mcuboot.flash_xip.overwrite
```

### Flash Command

```bash
west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
```

## Usage

### Test Procedure

1. **Start the peripheral application**: The device will automatically begin advertising
2. **Wait for central connection**: Monitor logs for connection from central device
3. **Throughput testing**: The central device will initiate throughput measurements
4. **Monitor results**: View connection parameters and throughput data in logs

## Connection Events

The peripheral application logs the following connection events:

### Connection Establishment
- **Connected**: Logs when a central device connects
- **Connection Parameters**: Displays current connection interval, latency, and timeout
- **MTU Exchange**: Shows negotiated MTU sizes for TX and RX

### Parameter Updates
- **PHY Updates**: Logs changes to TX and RX PHY modes (1M, 2M, Coded)
- **Data Length Updates**: Shows extended data length parameters
- **Connection Parameter Updates**: Displays updated connection intervals and timeouts

### Disconnection
- **Disconnected**: Logs disconnection events with reason codes
- **Automatic Re-advertising**: Automatically restarts advertising after disconnect with retry logic
