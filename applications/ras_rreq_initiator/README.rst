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

Building and Running
********************

This application is built from ``openair/applications/ras_rreq_initiator``.

Build with UART0 as console and shell command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/applications/ras_rreq_initiator --sysbuild -T applications.ras_rreq_initiator.atm.atmwstklib.full

Build with UART1 as console and shell command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/applications/ras_rreq_initiator --sysbuild -T applications.ras_rreq_initiator.atm.atmwstklib.full.uart1

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]

Notes and Recommendations
*************************

- This application uses the BLE central role and requires the full BLE stack.
