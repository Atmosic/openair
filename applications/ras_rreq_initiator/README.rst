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

CS Reflector Inline PCT (IPT)
=============================

To enable CS (Channel Sounding) reflector Inline PCT (Phase Correction Term) support, add the following configuration option to your project configuration file (``prj.conf``):

.. code-block:: bash

   CONFIG_ENABLE_CS_REF_IPT=y

This option enables:

- Detection of CS Enhancement 1 (IPT) capability on the remote reflector by reading its extended feature pages
- Automatic activation of the Inline PCT flag (``cs_enhancements_1``) in the CS configuration when the reflector supports it
- Logging of IPT enablement status during CS configuration

The following dependencies are automatically selected when this option is enabled:

- ``BT_LE_EXTENDED_FEAT_SET`` — enables reading of extended LL feature pages from the remote peer
- ``ATM_ENA_LL_FEAT_CS_ENH1`` — enables local CS Enhancement 1 (IPT) support at the link layer

.. note::
   On **ATM34** devices, only a 1×1 antenna configuration is supported with CS reflector IPT. ``CONFIG_CS_PROC_ANT_CFG_SEL=0`` (1 TX / 1 RX antenna) is mandatory when using this feature on ATM34:

   .. code-block:: bash

      CONFIG_ENABLE_CS_REF_IPT=y
      CONFIG_CS_PROC_ANT_CFG_SEL=0

.. important::
   **Reflector Requirement**: The paired reflector device must also have CS Enhancement 1 support enabled (e.g., ``CONFIG_ATM_ENA_LL_FEAT_CS_ENH1=y`` on the reflector side). The initiator reads the reflector's extended features after connection and only enables IPT in the CS config if the reflector advertises support.

Reduce RAS Data from Reflector
==============================

Two configuration options are provided to reduce the amount of ranging data
reported by the reflector.

.. note::
   These options are particularly recommended when CS reflector Inline PCT (IPT)
   is enabled (``CONFIG_ENABLE_CS_REF_IPT=y``), because the Q (imaginary) part
   of the reflector's ranging data is always zero in that case and carrying it
   wastes bandwidth.

Disable Ranging Data Subscriptions
-----------------------------------

To skip all ranging data subscriptions and receive only the RAS Control Point
notifications, add the following option to your project configuration file
(``prj.conf``):

.. code-block:: bash

   CONFIG_RREQ_DISABLE_RD_SUB=y

When enabled, the initiator skips all ranging data subscriptions in the
``RREQ_SMF_RAS_SUBSCRIBE`` state. This covers:

- The real-time ranging data subscription (when ``RAS_CLIENT_REAL_TIME_RD`` is
  enabled)
- The on-demand ranging data subscriptions (ranging data overwritten, ranging
  data ready, and on-demand ranging data)

Only the RAS Control Point subscription is kept.

Set RAS Mode 2 Ranging Data Filter
------------------------------------

To filter out selected Mode 2 fields from ranging data reported by the
reflector, add the following options to your project configuration file
(``prj.conf``):

.. code-block:: bash

   CONFIG_RREQ_SET_RAS_FILTER=y
   CONFIG_RREQ_RAS_FILTER_MODE_2_MASK=0x3FF8

When ``CONFIG_RREQ_SET_RAS_FILTER`` is enabled, the initiator sends a **Set
Filter CP** command with Mode 2 and the mask value configured by
``CONFIG_RREQ_RAS_FILTER_MODE_2_MASK`` after subscribing to the RAS Control
Point and before subscribing to ranging data.

**CONFIG_RREQ_RAS_FILTER_MODE_2_MASK**: 14-bit mask (``0x0000``–``0x3FFF``)
that controls which Mode 2 fields are kept in the ranging data. A **set** bit
retains the corresponding field; a **cleared** bit filters it out.

.. list-table:: Mode 2 Mask Bit Assignments
   :header-rows: 1
   :widths: 15 85

   * - Bit(s)
     - Field
   * - 0
     - Antenna Permutation Index
   * - 1
     - Phase Correction Term
   * - 2
     - Quality Indicator and Extension Indicator
   * - 3–6
     - Antenna Path 1~3 unsupported indication

The default value ``0x3FF8`` clears all step data for Mode 2.

.. note::
   ``CONFIG_RREQ_RAS_FILTER_MODE_2_MASK`` depends on
   ``CONFIG_RREQ_SET_RAS_FILTER`` and has no effect unless the filter is
   enabled.

Testing
*******

The EVK running this application is the Channel Sounding initiator. Connect it to a compatible
reflector EVK running the :ref:`ras_rrsp_reflector <ras_rrsp_reflector-application>` application.
Connect UART0 from the initiator EVK to the **Atmosic CS Plot Tool** using a baud rate of
**2000000**. The distance result is displayed in the CS Plot Tool.

Default configuration (without Inline PCT)
===========================================

1. Build and flash this application using the default target below.
2. Build and flash a compatible reflector using its default target, then scan for
   **Atmosic_RRSP** and complete pairing.
3. Connect the initiator EVK UART0 to the **Atmosic CS Plot Tool** at **2000000 baud**.
4. Start a Channel Sounding session from the initiator application and verify the distance result
   in the CS Plot Tool.

Inline PCT (IPT) configuration
===============================

Build both peers with their Inline PCT targets: use
``applications.ras_rreq_initiator.atm.ipt`` for this application and
``applications.ras_rrsp_reflector.atm.ipt`` for the reflector.

Building and Running
********************

This application is built from ``openair/applications/ras_rreq_initiator``.

Build with UART0 as console and shell command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rreq_initiator --sysbuild -T applications.ras_rreq_initiator.atm

Build with Inline PCT (IPT) support:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rreq_initiator --sysbuild -T applications.ras_rreq_initiator.atm.ipt

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink [--erase_all]
