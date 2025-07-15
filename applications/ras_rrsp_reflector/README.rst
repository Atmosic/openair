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

Building and Running
********************

This application is built from ``openair/applications/ras_rrsp_reflector``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm

Build with MCUboot command:
Run the following command to build the MCUboot, SPE, application with ``CONFIG_ATMWSTK_PD50=y``

.. code-block:: bash

   west build -p always -b <board>@mcuboot//ns openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm.mcuboot.atmwstklib.pd50

Build with OTA command:
Run the following command to build the SPE, application and MCUboot with ``-DEXTRA_CONF_FILE="basic_ota_bt.conf"`` to enable OTA function

.. code-block:: bash

   west build -p always -b <board>@mcuboot//ns openair/applications/ras_rrsp_reflector --sysbuild -T applications.ras_rrsp_reflector.atm.mcuboot.ota

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_all]
