.. _dtm_2wire:

Bluetooth: DTM 2-wire
#####################

Overview
********

The DTM 2-wire sample is an implementation of the Bluetooth Direct Test Mode
specified in the Bluetooth Core Specification Volume 6, Part F. This sample supports
the non-HCI mode of operation. If the tester supports DTM over HCI, refer
to the HCI UART sample, as this is fully compliant with the HCI specification.

Direct test mode 2-wire non-HCI is a lightweight BTLE radio testing protocol over
a 2-wire (RX/TX) serial (UART) that uses a simple 2-byte (16 bit) framing protocol.
This protocol is used when DTM over HCI (4 or 2-wires) is not available.

DTM is intended for systems (typically hostless) that can be tested without a host controller
interface stack (HCI). The DTM test commands map to HCI-based BTLE radio test commands in the
following way:

- HCI LE_TRANSMITTER_TEST (ENH version support) -----> DTM LE Transmitter Test
- HCI LE_RECEIVER_TEST (ENH version support)    -----> DTM LE Receiver Test
- HCI LE_TEST_END                               -----> DTM LE Test End

Where HCI uses command completion events, DTM uses TEST status and packet report messages.

Requirements
************

* Atmosic EVK board with Bluetooth LE support
* RF test equipment supporting DTM 2-wire protocol (e.g., Tescom TC-3000C)
* UART connection between board and test equipment

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/dtm_2wire``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/dtm_2wire --sysbuild -T samples.bluetooth.dtm_2wire.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]


Configuration
*************

**UART Configuration**

DTM 2-wire UART device and settings are configured via devicetree overlay. Edit ``app.overlay``:

.. code-block:: dts

   / {
       chosen {
           zephyr,dtm-2wire-uart = &uart0;  /* or &uart1, &uart2, etc. */
       };
   };

   &uart0 {
       status = "okay";
       current-speed = <115200>;  /* Change baudrate: 115200, 57600, 38400, etc. */
       /delete-property/ hw-flow-control;  /* Disable flow control for DTM 2-wire */
   };

   &uart1 {
       status = "okay";
       current-speed = <115200>;  /* Change baudrate: 115200, 57600, 38400, etc. */
       /delete-property/ hw-flow-control;  /* Disable hardware flow control for DTM 2-wire */
   };

Connection to the Tester
************************

The following signals should be connected to the RF tester:

- DTM UART RX  --> Tester UART TX
- DTM UART TX  --> Tester UART RX
- GND          --> GND

The tester UART settings should be configured to match the devicetree configuration:

- **Baud rate**: As configured (default 115200 bps)
- **Data bits**: 8
- **Stop bits**: 1
- **Parity**: None
- **Flow control**: None (RTS/CTS disabled)

Testing
*******

After flashing the sample to the board, the following message should appear:

.. code-block:: console

   *** Booting Zephyr OS build v3.x.x ***
   [00:00:00.xxx,xxx] <inf> dtm_mgr: Initializing DTM manager
   [00:00:00.xxx,xxx] <inf> dtm_mgr: DTM 2-wire NON-HCI Ready
   [00:00:00.xxx,xxx] <inf> dtm_2wire_main: DTM 2-wire application started

**Verification Steps:**

1. **Feature Query**: Most testers provide an option to query the device's supported features.
   Use this to verify communication. The device should report support for:

   - Data length extension
   - 2M PHY
   - Coded PHY (S2/S8)

2. **Basic Test**: Try a simple RX or TX test to verify the DTM interface is working.

3. **TRP/TIS Testing**: Proceed with the planned TRP/TIS test procedures.

Compatibility
*************

DTM 2-wire non-HCI has been tested with the following RF testers:

- **Tescom TC-3000C**

However, DTM should be compatible with any BT5.0+ compliant tester that supports DTM
2-wire non-HCI mode.

Troubleshooting
***************

**Common Issues:**

- **No response from device**: Check UART connections and baud rate settings
- **Invalid commands**: Ensure tester is configured for DTM 2-wire mode (not HCI mode)
- **Test failures**: Verify antenna connections and RF environment
