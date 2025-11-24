# DTM 2-Wire Library Unit Tests

This test suite provides comprehensive unit test coverage for the DTM (Direct Test Mode) 2-wire library implementation. The tests validate HCI bridge functionality, DTM message processing, and state machine behavior.

## Background

The DTM 2-wire library provides a Bluetooth Low Energy Direct Test Mode implementation that communicates with test equipment via a 2-wire UART interface. It includes:

- HCI bridge for sending LE test commands to the Bluetooth controller
- DTM message processing for parsing and handling DTM protocol messages
- State machine management for test lifecycle

## Test Coverage

### HCI Bridge Tests (`test_dtm_hci_bridge.c`)
- HCI bridge initialization
- Command callback registration
- HCI command execution (Reset, LE Read Max Data Length, LE Enhanced TX/RX Test, LE Test End)
- Multiple consecutive commands
- Error handling scenarios

### Message Processing Tests (`test_dtm_message_processing.c`)
- DTM message parsing and creation
- Test Setup commands (Reset, PHY mode setting)
- TX/RX Test command creation and parsing
- Test End command handling
- Status and packet report response assembly
- Feature support validation
- Parameter field extraction

### State Machine Tests (`test_dtm_state_machine.c`)
- DTM manager initialization
- HCI bridge state management
- Test lifecycle (TX and RX tests)
- Multiple test cycles
- Different PHY mode support (1M, 2M, Coded)
- Error handling scenarios

## Testing Approach

The test suite tests the real DTM 2-wire library implementation by:

### Real Implementation Testing
- Tests the actual DTM library functions and state machine logic
- Uses device tree configuration for UART devices
- Gracefully handles missing hardware by skipping tests when devices are unavailable
- Focuses on API behavior and protocol compliance

### Mock Components
- Mock transport layer (`dtmtl_send`) for message processing tests
- Test callbacks for tracking HCI command completion
- State tracking for validating test lifecycle

## Running the Tests

```bash
west twister -p <BOARD>@normal/<SOC_SERIES>/ns -T openair/tests/lib/dtm_2wire -s tests.lib.dtm_2wire.atm --device-testing --device-serial /dev/ttyACM1 --device-flash-timeout=210 --west-flash="--device=<DEVICE_ID>,--jlink,--erase_all,--fast_load" -c --extra-args=CONFIG_ATM_EUI_ALLOW_RANDOM=y -v
```

## Test Structure

```
dtm_2wire/
├── CMakeLists.txt              # Build configuration
├── prj.conf                   # Project configuration
├── testcase.yaml              # Test case metadata
├── boards/
│   └── common.overlay         # Device tree overlay
├── src/
│   ├── main.c                 # Test suite setup
│   ├── test_dtm_hci_bridge.c  # HCI bridge tests
│   ├── test_dtm_message_processing.c  # Message processing tests
│   └── test_dtm_state_machine.c       # State machine tests
└── README.md                  # This file
```

## Test Cases

### HCI Bridge Tests
1. **test_hci_bridge_init** - HCI bridge initialization
2. **test_callback_registration** - Command completion callback setup
3. **test_hci_reset_command** - HCI Reset command execution
4. **test_le_read_max_data_len** - LE Read Max Data Length command
5. **test_le_enh_tx_test** - LE Enhanced TX Test command
6. **test_le_enh_rx_test** - LE Enhanced RX Test command
7. **test_le_test_end** - LE Test End command
8. **test_multiple_commands** - Multiple consecutive command execution

### Message Processing Tests
1. **test_message_parsing** - DTM message parsing macros
2. **test_setup_reset** - Test Setup Reset command
3. **test_setup_phy_mode** - PHY mode setting commands
4. **test_tx_test_command** - TX Test command creation
5. **test_rx_test_command** - RX Test command creation
6. **test_end_command** - Test End command
7. **test_status_response** - Status response assembly
8. **test_packet_report** - Packet report assembly
9. **test_feature_support** - Feature support validation
10. **test_parameter_extraction** - Parameter field extraction

### State Machine Tests
1. **test_dtm_mgr_init** - DTM manager initialization
2. **test_dtm_mgr_init_no_uart** - Initialization without UART
3. **test_hci_bridge_state** - HCI bridge state validation
4. **test_tx_test_lifecycle** - TX test lifecycle management
5. **test_rx_test_lifecycle** - RX test lifecycle management
6. **test_multiple_test_cycles** - Multiple test cycles
7. **test_different_phy_modes** - Different PHY mode support
8. **test_error_handling** - Error handling scenarios

## Validation Criteria

The tests validate:
- ✅ DTM 2-wire library integration with Zephyr
- ✅ HCI bridge functionality and command execution
- ✅ DTM message protocol compliance
- ✅ State machine transitions and lifecycle management
- ✅ Error handling and edge cases
- ✅ Multi-PHY support (1M, 2M, Coded)
- ✅ Hardware abstraction and graceful degradation

## Dependencies

- Zephyr RTOS with Bluetooth support
- DTM 2-wire library (`CONFIG_DTM_2WIRE=y`)
- UART driver for 2-wire interface
- Bluetooth HCI controller support
