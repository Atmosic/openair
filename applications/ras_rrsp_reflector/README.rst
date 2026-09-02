.. _ras_rrsp_reflector-application:

Channel Sounding: Reflector with Ranging Responder
##################################################

Overview
********

Application demonstrates the **BLE responser role in an RAP (Ranging Profile)**
system and the **reflector role for Channel Sounding**. It can be connected with a BLE
requester application (Refer to :ref:`ras_rreq_initiator <ras_rreq_initiator-application>`).
And then indicates channel sounding ranging procedure or sends ranging procedure data
according GATT Ranging service control point write commands.

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

     On the **ATMBTCSTAG-3405** board, see
     :ref:`ras_rrsp_reflector_atmbtcstag_3405` for the board-specific Button1 power on/off
     and factory reset behavior.

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

Bluetooth Privacy
=================

Bluetooth privacy is enabled by default. When testing the reflector with an Android phone
running the Atmosic Dev Tool application, disable Bluetooth privacy in the build so that the
phone can connect to the reflector:

.. code-block:: bash

   CONFIG_BT_PRIVACY=n

CS Enhancement 1 (IPT) Support
===============================

To enable CS (Channel Sounding) Enhancement 1 support, which allows the reflector to advertise
Inline PCT (Phase Correction Term / IPT) capability to the initiator, add the following
configuration option to your project configuration file (``prj.conf``):

.. code-block:: bash

   CONFIG_ATM_ENA_LL_FEAT_CS_ENH1=y

This option enables CS Enhancement 1 (IPT) at the link layer, allowing the initiator to detect
and activate IPT in the CS configuration when both sides support it.

Filter Ranging Data
===================

To enable filtering of ranging data reported by the RAS server, add the following configuration
option to your project configuration file (``prj.conf``):

.. code-block:: bash

   CONFIG_RAS_FILTER_RD=y

This option enables:

- Support for the RAS Set Filter control point command
- Filtering of Mode 2 ranging data fields, including:

  - Antenna Permutation Index (bit 0)
  - Phase Correction Term (bit 1)
  - Quality Indicator and Extension Indicator (bit 2)

.. note::
   ``CONFIG_RAS_FILTER_RD=y`` is typically paired with ``CONFIG_ATM_ENA_LL_FEAT_CS_ENH1=y``
   when using CS reflector IPT, so that the initiator can request filtering of the Phase
   Correction Term from the ranging data:

   .. code-block:: bash

      CONFIG_ATM_ENA_LL_FEAT_CS_ENH1=y
      CONFIG_RAS_FILTER_RD=y

.. _ras_rrsp_reflector_testing:

Testing
*******

To test the reflector, connect it to an initiator. The initiator can be another compatible
EVK running the :ref:`ras_rreq_initiator <ras_rreq_initiator-application>` application or a
mobile phone with Channel Sounding initiator functionality. Use a phone and application that
support the required Channel Sounding functionality; phone capabilities and application
availability may vary by model and software version.

Connect the initiator EVK UART0 to the **Atmosic CS Plot Tool** at **2000000 baud** to view
the distance result. A mobile phone can also be used as the initiator for the phone-specific
flows described below.

Default configuration (without Inline PCT)
===========================================

1. Build and flash the reflector using the default target below.
2. Run the initiator on another compatible EVK and connect its UART0 to the **Atmosic CS Plot
   Tool** at **2000000 baud**.
3. Scan for **Atmosic_RRSP**, connect and pair with the reflector, and start a Channel Sounding
   session in the initiator application.
4. Verify the distance result in the **Atmosic CS Plot Tool**.

Android phone test
------------------

For testing without Inline PCT, an Android phone with initiator functionality can be used with
the **Atmosic Dev Tool** application. Build the reflector with Bluetooth privacy disabled so that
the phone can connect:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rrsp_reflector \
       --sysbuild -T applications.ras_rrsp_reflector.atm -- -DCONFIG_BT_PRIVACY=n

Scan for **Atmosic_RRSP**, connect and pair with the reflector, start a Channel Sounding session,
and verify the distance result in the phone application.

Inline PCT (IPT) configuration
===============================

For Inline PCT testing, build the reflector with the ``applications.ras_rrsp_reflector.atm.ipt``
target and build the initiator with its corresponding ``applications.ras_rreq_initiator.atm.ipt``
target. Run the initiator on another compatible EVK and connect its UART0 to the **Atmosic CS
Plot Tool** at **2000000 baud**. Alternatively, a compatible iPhone with initiator functionality
can be used with a **Core Bluetooth Channel Sounding** application.

Building and Running
********************

This application is built from ``openair/applications/ras_rrsp_reflector``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm

Build with Inline PCT (IPT) support:

.. code-block:: bash

   west build -p always -b <BOARD>@mcuboot openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm.ipt

Build with MCUboot command:
Run the following command to build the MCUboot and application

.. code-block:: bash

   west build -p always -b <BOARD>@mcuboot openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm.mcuboot

Build with OTA command:
Run the following command to build the application and MCUboot with ``-DEXTRA_CONF_FILE="basic_ota_bt.conf"`` to enable OTA function

.. code-block:: bash

   west build -p always -b <BOARD>@mcuboot openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm.mcuboot.ota

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink [--erase_all]
