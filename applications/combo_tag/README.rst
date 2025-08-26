.. _combo_tag-application:

Find My Combo Tag: Apple & Google Compatible
############################################

Overview
********

This sample illustrates the functionality of a combo tag compatible with both **Apple Find My Network** and **Google Find My Device Network**.

Requirements
************

- Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

.. note::

   Currently, only the **ATM33/e** and **ATM34/e** series Atmosic devices are supported.


Device State Transitions
************************

.. note::
   This chapter highlights the key behavioral difference between the **combo_tag** and the single-mode **fp_tag** or **fmna_tag**.
   For detailed behavior, configuration, and instructions for **fp_tag** and **fmna_tag**, please refer to their respective documentation:
   <:ref:`Google Find My Device Network Tag <fp_tag-application>`> and <:ref:`Apple Find My Network Tag <fmna_tag-application>`>.

- **Step 1**: When the device is **unpaired**, it automatically enters pairing mode upon boot. In this mode, the device is discoverable and can be paired using either the **Apple Find My** or **Google Find My Device** app.
- **Step 2**: Once the device is successfully **paired** with either app, it switches to single-mode operation, functioning as either an **FMNA tag** (Apple) or **FP tag** (Google).
- **Step 3**: If the device is **unpaired** via the app or a physical button, it returns to the **unpaired** state and behaves as described in **Step 1**.


Custom Bluetooth Device Address
*******************************

Enable custom Bluetooth device address of fmna_tag or fp_tag for testing or development purposes. Otherwise, the device's EUI-48 MAC address will be used.
For detailed options, please refer to their respective documentation:
   <:ref:`Google Find My Device Network Tag <fp_tag-application>`> and <:ref:`Apple Find My Network Tag <fmna_tag-application>`>.

Example of fmna_tag::

  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR=y
  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR_VALUE="ED:15:48:87:6E:EF"

Example of fp_tag::

  CONFIG_FAST_PAIR_USER_PAIR_BT_ADDR=y
  CONFIG_FAST_PAIR_PAIR_BT_ADDR="ED:12:34:56:6E:EF"


PWM Buzzer
**********

- To enable the PWM Buzzer for FMNA sound implementation, please add **CONFIG_ATM_BUZZER=y** to the prj.conf file.
- Since Atmosic EVK does not include an onboard buzzer, kindly refine the overlay file at boards/<BOARD>_ns.overlay to map the corresponding pin and PWM channel.


Building and Running
********************

This application is built from ``openair/applications/combo_tag``.

Run the following command to build the SPE, application and factory data for the **ATM33/e** series:

.. code-block:: bash

    west build -p always -b <BOARD>//ns openair/applications/combo_tag --sysbuild -T applications.combo_tag.atm


Run the following command to build the SPE, application and factory data for the **ATM34/e** series:

.. code-block:: bash

    west build -p always -b <BOARD>//ns openair/applications/combo_tag --sysbuild -T applications.combo_tag.atm.atm34

Programming
===========

To flash the built images:

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load [--erase_all]

.. note::
    - Use the ``--erase_all`` option cautiously, as it may erase critical updated token information.
