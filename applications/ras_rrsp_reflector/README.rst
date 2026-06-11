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

Building and Running
********************

This application is built from ``openair/applications/ras_rrsp_reflector``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm

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

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]
