.. _atm_ble_sample:

ATM BLE Central and Peripheral Sample
#####################################

Overview
********

This sample demonstrates a complete BLE test application featuring bidirectional communication between a Central and a Peripheral device using custom GATT characteristics.

The sample can be built in two modes:

- **Default mode**: Connection-oriented communication with GATT services
- **Periodic advertising mode**: Connectionless broadcast communication

Applications Included
*********************

- **atm_ble_peripheral**: Acts as a GATT server that advertises, accepts connections, and communicates with a central device.
- **atm_ble_central**: Scans for nearby peripherals, establishes connections, and interacts with the server for data exchange and control.

Features
********

Default Mode
============

The sample implements the following BLE features when built in default mode:

- **Dynamic TX Power Control**
  - TX power is dynamically adjusted during both advertising and active connections based on application logic and signal strength.

- **Connection PHY Management**
  - Supports BLE PHY modes including 1M, 2M, and Coded PHY (S2 and S8 submodes).
  - Automatic and manual PHY updates are handled during runtime.

- **MTU Exchange**
  - Devices perform MTU negotiation to maximize payload capacity and improve throughput.

- **Connection Subrating**
  - BLE 5.3 connection subrating is supported and configured, enabling efficient low-duty-cycle communication for power-sensitive use cases.

  .. note::
     ATM33xx does not support connection subrating since it uses BLE 5.2.

Periodic Advertising Mode
=========================

When built with periodic advertising configuration, the sample operates in a **connectionless broadcast mode**:

- **Peripheral**: Broadcasts periodic advertising data at fixed intervals using extended advertising
- **Central**: Scans for and synchronizes with periodic advertising trains to receive broadcast data

.. note::
   In periodic advertising mode, the following connection-oriented features are **not available**:

   - MTU exchange
   - PHY updates
   - Connection TX power control
   - Connection subrating

Expected Behavior
*****************

Default Mode
============

- The peripheral device starts advertising.
- The central scans and connects based on RSSI and advertisement content.
- Upon connection, the devices:

  - Negotiate MTU size
  - Update PHY settings
  - Exchange data using write/notify mechanisms
  - Adjust TX power dynamically
  - Apply BLE subrating configurations

Periodic Advertising Mode
==========================

- The peripheral device starts extended non-connectable advertising with periodic advertising train.
- The central scans for periodic advertisers and synchronizes to the advertising train.
- The peripheral periodically updates broadcast data.
- The central receives and logs the broadcast data.
- No connection is established between devices.

Build Options
*************

You can configure the build to enable specific Bluetooth LE periodic advertising or
synchronization modes by passing an extra configuration file during compilation.

**Available modes:**

1. **Periodic Advertisement Mode (Peripheral)**

   This mode configures the device to periodically broadcast advertising data at fixed intervals.
   It can be useful for applications such as beaconing or broadcast-based data transmission.

   To enable this mode, build the peripheral with:

   .. code-block:: bash

      -DEXTRA_CONF_FILE="periodic_adv.conf"

   .. note::
      In this mode, the peripheral does **not** accept connections and does **not** provide GATT services.
      Connection-oriented features (MTU exchange, PHY updates, connection TX power control, subrating) are not available.

2. **Periodic Sync Mode (Central)**

   This mode configures the central device to scan for and synchronize with other devices that are
   periodically advertising. It is useful for receiving broadcast information in sync with the
   advertiser's schedule.

   To enable this mode, build the central with:

   .. code-block:: bash

      -DEXTRA_CONF_FILE="periodic_sync.conf"

   .. note::
      In this mode, the central does **not** establish connections and does **not** use GATT client features.
      Connection-oriented features (MTU exchange, PHY updates, connection TX power control, subrating) are not available.

Configurable Options
********************

Several settings are configurable via Kconfig (`prj.conf`) to suit different test conditions.

.. note::
   These options apply only to **default mode**. In periodic advertising mode, connection-oriented
   features are not available.

- **BLE PHY Options** (default mode only)
  - `CONFIG_ATM_BT_PHY_1M`
  - `CONFIG_ATM_BT_PHY_2M`
  - `CONFIG_ATM_BT_PHY_CODED_S2`
  - `CONFIG_ATM_BT_PHY_CODED_S8`

- **TX Power Settings**
  - `CONFIG_ATM_ADV_TX_POWER_DBM` – Initial advertising TX power in dBm (default mode only, ATM34 only. ATM33 uses `CONFIG_MAX_TX_PWR` for advertising.)
  - `CONFIG_ATM_CONN_TX_POWER_DBM` – Initial connection TX power in dBm (default mode only)
  - `CONFIG_ATM_DYN_TX_POWER_DBM` – Dynamic TX power in dBm used during connection for runtime power adjustment (default mode only)

  .. note::
     On ATM33, advertising TX power control works differently than on ATM34:

     - **ATM33**: Does not support ``atm_vendor_set_adv_tx_power()``. The advertising TX power is
       controlled by ``CONFIG_MAX_TX_PWR`` and cannot be adjusted independently at runtime.
       Connection TX power can be adjusted using ``atm_vendor_set_con_tx_power()``.

     - **ATM34**: Supports independent control of advertising and connection TX power.
       Both ``atm_vendor_set_adv_tx_power()`` and ``atm_vendor_set_con_tx_power()`` work as expected.

Console Output
**************

Default Mode
============

Sample logs observed during a successful run in default (connection-oriented) mode:

**Peripheral Log:**

.. code-block:: console

   *** Booting Zephyr OS build v4.2.0-114074-g2c490fe1a553 ***
   *** OpenAir v25.09.0 (CPD200) ***
   [00:00:00.019,000] <inf> bt_hci_core: HCI transport: Atmosic BLE
   [00:00:00.019,000] <inf> bt_hci_core: Identity: AE:DA:D6:41:FF:35 (public)
   [00:00:00.019,000] <inf> bt_hci_core: HCI: version 6.0 (0x0e) revision 0x86d0, manufacturer 0x0a24
   [00:00:00.019,000] <inf> bt_hci_core: LMP: version 6.0 (0x0e) subver 0x86d0
   [00:00:00.019,000] <inf> atm_vendor_api: Set adv TX pwr:4
   [00:00:00.019,000] <inf> atm_ble_peripheral: Successfully set adv TX power level to 4
   [00:00:00.023,000] <inf> atm_ble_peripheral: Advertising successfully started
   [00:00:03.218,000] <inf> atm_ble_peripheral: Updated MTU: TX: 23 RX: 23 bytes
   [00:00:03.218,000] <inf> atm_vendor_api: Set con TX pwr:4
   [00:00:03.218,000] <inf> atm_ble_peripheral: Successfully set conn TX power level 4
   [00:00:03.218,000] <inf> atm_ble_peripheral: connection parameters: type = 1, role = 1, id = 0
   [00:00:03.219,000] <inf> atm_ble_peripheral: interval = 24, latency = 0, timeout = 400
   [00:00:03.219,000] <inf> atm_ble_peripheral: Connected: 26:FF:C1:E2:32:FA (public)
   [00:00:03.309,000] <inf> atm_ble_peripheral: Subrate changed:
   [00:00:03.309,000] <inf> atm_ble_peripheral: status = 0, factor = 2, continuation_number = 1, peri_latency = 0, sup_timeout = 400
   [00:00:03.369,000] <inf> atm_ble_peripheral: Updated MTU: TX: 147 RX: 147 bytes
   [00:00:03.549,000] <inf> atm_ble_peripheral: MTU Test Update: notifications enabled
   [00:00:03.759,000] <inf> atm_ble_peripheral: PHY UPDATED RX PHY 2, TX PHY 2
   [00:00:03.789,000] <inf> atm_ble_peripheral: Received from central:Atmosic --central to peripheral
   [00:00:03.789,000] <inf> atm_ble_peripheral: Change the TX power in peripheral...
   [00:00:03.789,000] <inf> atm_vendor_api: Set con TX pwr:6
   [00:00:03.789,000] <inf> atm_ble_peripheral: Successfully set connection TX power level 6
   [00:00:03.849,000] <inf> atm_ble_peripheral: Received from central:ATM BLE Test completed
   [00:00:03.849,000] <inf> atm_ble_peripheral: All process are done...

**Central Log:**

.. code-block:: console

   *** Booting Zephyr OS build v4.2.0-114074-g2c490fe1a553 ***
   *** OpenAir v25.09.0 (CPD200) ***
   [00:00:00.019,000] <inf> bt_hci_core: HCI transport: Atmosic BLE
   [00:00:00.019,000] <inf> bt_hci_core: Identity: 26:FF:C1:E2:32:FA (public)
   [00:00:00.019,000] <inf> bt_hci_core: HCI: version 6.0 (0x0e) revision 0x86d0, manufacturer 0x0a24
   [00:00:00.019,000] <inf> bt_hci_core: LMP: version 6.0 (0x0e) subver 0x86d0
   [00:00:00.019,000] <inf> atm_ble_central: Bluetooth initialized
   [00:00:00.023,000] <inf> atm_ble_central: Scanning successfully started
   [00:00:00.026,000] <inf> atm_ble_central: Device found: AE:DA:D6:41:FF:35 (public) (RSSI -20)
   [00:00:00.060,000] <inf> atm_ble_central: Updated MTU: TX: 23 RX: 23 bytes
   [00:00:00.061,000] <inf> atm_ble_central: mtu_exchange: Current MTU = 23
   [00:00:00.061,000] <inf> atm_ble_central: mtu_exchange: Exchange MTU...
   [00:00:00.061,000] <inf> atm_vendor_api: Set con TX pwr:4
   [00:00:00.061,000] <inf> atm_ble_central: Successfully set conn TX power level 4
   [00:00:00.063,000] <inf> atm_ble_central: Connection parameters: type = 1, role = 0, id = 0
   [00:00:00.063,000] <inf> atm_ble_central: interval = 24, latency = 0, timeout = 400
   [00:00:00.065,000] <inf> atm_ble_central: Success in setting subrate params
   [00:00:00.065,000] <inf> atm_ble_central: Connected to AE:DA:D6:41:FF:35 (public) successfully
   [00:00:00.152,000] <inf> atm_ble_central: Subrate changed:
   [00:00:00.152,000] <inf> atm_ble_central: status = 0, factor = 2, continuation_number = 1, peri_latency = 0, sup_timeout = 400
   [00:00:00.242,000] <inf> atm_ble_central: Updated MTU: TX: 147 RX: 147 bytes
   [00:00:00.242,000] <inf> atm_ble_central: mtu_exchange_cb: MTU exchange successful (147)
   [00:00:00.362,000] <inf> atm_ble_central: Subscribed to notification
   [00:00:00.601,000] <inf> atm_ble_central: PHY UPDATED RX PHY 2, TX PHY 2
   [00:00:00.602,000] <inf> atm_ble_central: Write function call...
   [00:00:00.602,000] <inf> atm_ble_central: Write operation...
   [00:00:00.602,000] <inf> atm_ble_central: Send data successfully: Atmosic --central to peripheral
   [00:00:00.662,000] <inf> atm_ble_central: [NOTIFICATION] data: In peripheral Tx power set successfully
   [00:00:00.662,000] <inf> atm_ble_central: Change the TX power in central...
   [00:00:00.663,000] <inf> atm_vendor_api: Set con TX pwr:8
   [00:00:00.663,000] <inf> atm_ble_central: Successfully set connection TX power level 8
   [00:00:00.663,000] <inf> atm_ble_central: Write operation...
   [00:00:00.663,000] <inf> atm_ble_central: Send data successfully: ATM BLE Test completed
   [00:00:00.663,000] <inf> atm_ble_central: Write callback: success
   [00:00:00.721,000] <inf> atm_ble_central: Write callback: success
