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

1M PHY for Long-Distance Testing
================================

To enable 1M PHY mode for improved range and signal penetration in long-distance testing scenarios, add the following configuration option to your project configuration file (``prj.conf``):

.. code-block:: bash

   CONFIG_ATM_BT_PHY_1M=y

This option enables:

- 1M PHY mode for enhanced range and signal penetration capabilities
- Automatic enabling of BT_USER_PHY_UPDATE for PHY management functionality
- Automatic disabling of BT_AUTO_PHY_UPDATE to ensure consistent 1M PHY usage
- Forced PHY update to 1M if non-1M PHY is detected during connection
- Optimized Channel Sounding procedure intervals (16 vs 12) for 1M PHY operation

When this option is enabled:

- The system will automatically attempt to update the PHY to 1M if a different PHY is detected
- Channel Sounding procedure intervals are adjusted from 12 to 16 for optimal 1M PHY performance
- Up to 3 retry attempts are made if PHY update to 1M fails
- PHY update status is logged for monitoring and debugging purposes

.. note::
   This feature is specifically designed for long-distance Channel Sounding applications where 1M PHY provides better range and signal penetration compared to higher data rate PHYs. The automatic PHY management ensures consistent 1M PHY usage throughout the connection lifecycle.

.. important::
   **Reflector Configuration Requirement**: When testing with a reflector device (e.g., :ref:`ras_rrsp_reflector <ras_rrsp_reflector-application>`), the reflector must also have ``CONFIG_BT_AUTO_PHY_UPDATE=n`` disabled to ensure both devices maintain consistent 1M PHY usage. Without this configuration on the reflector side, PHY mismatches may occur during the connection, potentially affecting Channel Sounding performance and range measurements.

Building and Running
********************

This application is built from ``openair/applications/ras_rreq_initiator``.

Build with UART0 as console and shell command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rreq_initiator --sysbuild -T applications.ras_rreq_initiator.atm

Build with UART1 as console and shell command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rreq_initiator --sysbuild -T applications.ras_rreq_initiator.atm.uart1

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]
