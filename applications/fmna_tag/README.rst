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

Once you have access to git@github.com:Atmosic/fmna.git, run ``west config manifest.group-filter -- +fmna`` to add the fmna project group to the west manifest, then execute ``west update`` to fetch the project;
To build the application using the ADK source code instead of the precompiled library, disable the Kconfig option ``-DCONFIG_ATM_FMNA_LIB=n``.

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

This sample can be found under ``applications/fmna_tag`` in the OpenAir tree.

.. note::
    Use atmwstk for best memory optimization. However, atm34xx series boards only support atmstklib.


Without UARP Support
====================

Run the following command to build the SPE, application and factory data:

.. code-block:: bash

    west build -p always -b <board>//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm

or

.. code-block:: bash

    west build -p always -b <board>//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm.atmwstk.pd50ll


With UARP Support
=================

Run the following command to build the mcuboot, SPE, application and factory data:

.. code-block:: bash

    west build -p always -b <board>@mcuboot//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm.mcuboot.uarp.atmwstklib.pd50

or

.. code-block:: bash

    west build -p always -b <board>@mcuboot//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm.mcuboot.uarp.atmwstk.pd50ll


Run the following command to program all the built images and run the application:

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device=<serial> --jlink --fast_load [--erase_flash]

.. note::
    - Use the ``--erase_flash`` option cautiously, as it may erase critical updated token information.


Button Functions
****************

- Press and hold button1 on EVK for 3 seconds during reboot to unpair and enter pairing mode.


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
