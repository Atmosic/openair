.. _fmna_tag-application:

Apple Find My Network Tag
#########################


Overview
********

Demonstrates the Apple Find My Network Tag functionality.


Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

.. note::
    Currently, only the **ATM33/e** and **ATM34/e** series of Atmosic devices are supported.


ADK Integration Guide
*********************

The ADK core is provided as the binary library ``libatm_fmna.a``, making it easy for users to integrate the Apple FindMy function into their applications without needing the source code.
For access to the Atmosic ADK Zephyr source code, please contact Atmosic and provide the MFi Program ID.

Once access to the private Atmosic Zephyr ADK GitHub repository is granted, follow the instructions in the repository's README to include the ADK source in the project build.

Device Manufacturer Settings
****************************

Edit ``tag_data/factory.yml`` to configure device factory data:

- **serial_number**: Unique identifier for the device.
- **auth_uuid**: Authentication UUID.
- **auth_token**: First token for device authentication.

.. note::
    These values are used to authenticate the device and provided by the Apple MFi Program.


FMNA Configuration Settings
***************************

Below are the FMNA device configuration. Please add these settings to the ``prj.conf`` file according to the requirements.


Custom Bluetooth Device Address
===============================

`Enable custom Bluetooth device address for testing or development purposes. Otherwise, the device's EUI-48 MAC address will be used.`

Example::

  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR=y
  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR_VALUE="ED:15:48:87:6E:EF"


FMNA Accessory Information
==========================

Example::

  CONFIG_FMNA_PRODUCT_DATA="DFECEFF1E1FF54DB"
  CONFIG_FMNA_ACCESSORY_CATEGORY=129
  CONFIG_FMNA_ACCESSORY_CAPABILITY=31
  CONFIG_FMNA_BATTERY_TYPE=1
  CONFIG_FMNA_PID=51966
  CONFIG_FMNA_MANUFACTURER_NAME="Osprey"
  CONFIG_FMNA_MODEL_NAME="Bike"
  CONFIG_FMNA_HARDWARE_VERSION="1"


FMNA Firmware Version
=====================

Example::

  CONFIG_FMNA_VERSION_MAJOR=1
  CONFIG_FMNA_VERSION_MINOR=0
  CONFIG_FMNA_VERSION_REVISION=18


Building and Running
********************

This application is built from ``openair/applications/fmna_tag``.


Without UARP Support
====================

Run the following command to build the SPE, application and factory data:

.. code-block:: bash

    west build -p always -b <board>//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm


With UARP Support
=================

Run the following command to build the mcuboot, SPE, application and factory data:

.. code-block:: bash

    west build -p always -b <board>@mcuboot//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm.mcuboot.uarp.atmwstklib.pd50


Run the following command to program all the built images and run the application:

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device=<serial> --jlink --fast_load [--erase_all]

.. note::
    - Use the ``--erase_all`` option cautiously, as it may erase critical updated token information.


Button Functions
****************

In order for the button to work, jumpers JP25 and JP27 need to be installed on the EVK.

- Press and hold button2 on EVK for 3 seconds during reboot to unpair and enter pairing mode.


PWM Buzzer
**********

- To enable the PWM Buzzer for FMNA sound implementation, please add **CONFIG_PWM_BUZZER=y** to the prj.conf file.
- Since Atmosic EVK does not include an onboard buzzer, kindly refine the overlay file at boards/<board>_ns.overlay to map the corresponding pin and PWM channel.


Mobile Applications
*******************

- Use **Find My** app from the Apple App Store to add and locate the FMNA Tag.
- Use **Find My Certification Asst** app to perform tests: https://apps.apple.com/us/app/find-my-certification-asst/id1532296125


Limitations
***********

- The FMNA Tag application is designed to work with the Apple Find My Network.
- Motion sensor implementation is not included.
