.. _ras_rreq_initiator-application:

Channel Sounding: Initiator with Ranging Requester
##################################################

Overview
********

Application demonstrates the **BLE requester role in an RAP (Ranging Profile)** system and the
**initiator role for Channel Sounding**. It can connect with a BLE responder application
(Refer to :ref:`ras_rrsp_reflector <ras_rrsp_reflector-application>`). And then gets channel
sounding ranging procedure indication and data using GATT Ranging service control point write
commands to the BLE Ranging Responser role.

Requirements
************

1. Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

.. note::
    - Currently, only the **ATM34/e** series of Atmosic devices are supported.

2. Button

   - Press Button2 to unpair the device.

   .. note::
     - The default pin for Button2 is P6.
     - Install the **JP27** and **JP25** jumpers to enable Button2.

3. Antenna_switch: connect IO to switch antenna as channel sounding enable

 - Need to connect external antenna switch board for EVK
 - For the related pin setting, please refer to the overlay file.
 - If there is no overlay file, the function is disabled.
 - Refer to ``atmosic,antenna.yaml`` for below properties.

   - e.g. P5 as antenna switch (**JP29** in EVK board).

     In the case, Button1 can not be used, since it is also used with P5.

    .. code-block:: bash

      / {
       aliases {
        sw0 = &button1;
       };
      };
      &atm_antenna {
       ant-out5-pin = <5>;
       mdm-ant-rx-3to0 = <0x00002000>;
       mdm-ant-tx-3to0 = <0x00002000>;
       mdm-ant-idle =<0>;
       status = "okay";
      };

   - e.g. P16 as antenna switch, and antenna0 with P16 high

    .. code-block:: bash

      &atm_antenna {
       ant-out0-pin = <16>;
       mdm-ant-rx-3to0 = <0x00000001>;
       mdm-ant-tx-3to0 = <0x00000001>;
       mdm-ant-idle =<0x01>;
       status = "okay";
      };

Configuration Options
*********************

Bluetooth Transmit Power Control
=================================

To enable Bluetooth transmit power control reporting functionality, add the following configuration option to your project configuration file (``prj.conf``):

.. code-block:: bash

   CONFIG_BT_TRANSMIT_POWER_CONTROL=y

This option enables:

- Transmit power control information reporting to the host
- Support for transmit power reporting procedures in BLE connections
- Power control status monitoring and feedback mechanisms
- Enhanced visibility into power control operations for channel sounding

.. note::
   This feature enables the reporting of power control information rather than direct power adjustment. It is useful for monitoring and debugging power control behavior in ranging applications.

RSSI Reading Support
====================

To enable RSSI (Received Signal Strength Indicator) reading functionality, add the following configuration option to your project configuration file (``prj.conf``):

.. code-block:: bash

   CONFIG_READ_RSSI=y

This option enables:

- RSSI measurement and reporting capabilities
- Signal strength monitoring for BLE connections

.. note::
   RSSI readings provide valuable signal strength information that can be used to improve connection quality assessment.

BLE PHY Mode Selection
======================

To enable BLE PHY mode selection and automatic PHY updates, add the following configuration options to your project configuration file (``prj.conf``):

.. code-block:: bash

   CONFIG_ATM_BT_PHY_UPDATE=y
   CONFIG_ATM_BT_PHY=0

These options enable:

- Flexible PHY mode selection (0=1M, 1=2M, 2=Coded)
- Automatic PHY update to the configured mode if a different PHY is detected during connection
- Retry mechanism for PHY update failures

Configuration Details

**CONFIG_ATM_BT_PHY_UPDATE**: Enable/disable automatic PHY updates

- When enabled, the system will automatically attempt to update the PHY to the configured mode if a different PHY is detected
- Up to 3 retry attempts are made if PHY update fails

**CONFIG_ATM_BT_PHY**: Select the preferred PHY mode

- ``0``: 1M PHY (default) - Enhanced range and signal penetration for long-distance testing
- ``1``: 2M PHY - Higher data rate for improved throughput
- ``2``: Coded PHY - Extended range with lower data rate

Example configurations:

.. code-block:: bash

   # For long-distance Channel Sounding with 1M PHY
   CONFIG_ATM_BT_PHY_UPDATE=y
   CONFIG_ATM_BT_PHY=0

   # For high-throughput scenarios with 2M PHY
   CONFIG_ATM_BT_PHY_UPDATE=y
   CONFIG_ATM_BT_PHY=1

   # For extended range with Coded PHY
   CONFIG_ATM_BT_PHY_UPDATE=y
   CONFIG_ATM_BT_PHY=2

.. note::
   This feature is specifically designed for Channel Sounding applications where PHY mode selection is critical for optimal performance. The automatic PHY management ensures consistent PHY usage throughout the connection lifecycle.

.. important::
   **Reflector Configuration Requirement**: When testing with a reflector device (e.g., :ref:`ras_rrsp_reflector <ras_rrsp_reflector-application>`), the reflector must disable auto phy ``CONFIG_BT_AUTO_PHY_UPDATE=n``. If not, PHY mismatches may occur during the connection, potentially affecting Channel Sounding performance and range measurements.

Building and Running
********************

This application is built from ``openair/applications/ras_rreq_initiator``.

Build with UART0 as console and shell command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rreq_initiator --sysbuild -T applications.ras_rreq_initiator.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]
