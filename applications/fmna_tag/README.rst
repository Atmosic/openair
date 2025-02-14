.. zephyr:code-sample:: fmna_tag
   :name: Apple Find My Network Tag

   Demonstrates the Apple Find My Network Tag functionality.

Overview
========

This sample demonstrates the **Apple Find My Network Tag** functionality,
designed for use with any boards_.

.. _boards:


Boards
======

- **ATMEVK-3330e-QN-5**
- **ATMEVK-3325-LQK**
- **ATMEVK-3430e-WQN-2**


Directory Structure and Substitutions
=====================================

Before proceeding, understand the following directory structure:

+-------------------+--------------------------------------+--------------------------------------------+
| Placeholder       | Description                          | Corresponding Value                        |
+===================+======================================+============================================+
| ``<WEST_TOPDIR>`` | Top-level directory of the Zephyr    | ``/absolute/path/to/zephyrproject``        |
+-------------------+--------------------------------------+--------------------------------------------+
| ``<APP>``         | Application directory                | ``openair/applications/fmna_tag``          |
+-------------------+--------------------------------------+--------------------------------------------+
| ``<BOARD>``       | Target board                         | ``ATMEVK-3330-QN-5``                       |
+-------------------+--------------------------------------+--------------------------------------------+

Replace ``<BOARD>`` with any supported board listed above.


ADK Integration Guide
=====================

1. Download **Find My Network ADK 1.0.zip** from the Apple MFi Content Center and place it under <WEST_TOPDIR>.
2. Contact Atmosic to obtain the Atmosic integrated patch **atmosic_ADK.patch** and place it under <WEST_TOPDIR>.
3. Execute the following command under <WEST_TOPDIR> to extract the ADK and apply the Atmosic integrated patch into the FMNA library:

.. code-block:: bash

    ./<APP>/atmosic_ADK_apply.sh


Device Manufacturer Settings
============================

Edit <APP>/tag_data/factory.yml to configure device factory data:

- **serial_number**: Unique identifier for the device.
- **auth_uuid**: Authentication UUID.
- **auth_token**: First token for device authentication.
- **bdaddr**: Bluetooth device address.

.. note::
    **serial_number**, **auth_uuid** and **auth_token** are provided by the Apple MFi Program.


Steps to Build
==============

.. note::
    Use atmwstk for best memory optimization. However, atm34xx series boards only support atmstklib.


without UARP support
--------------------

Run the following command to build the SPE, application and factory data:

.. code-block:: bash

    west build -p always <APP> --sysbuild -b <BOARD>//ns -T applications.fmna_tag.atm

or

.. code-block:: bash

    west build -p always <APP> --sysbuild -b <BOARD>//ns -T applications.fmna_tag.atm.atmwstk.pd50ll


with UARP support
-----------------

Run the following command to build the mcuboot, SPE, application and factory data:

.. code-block:: bash

    west build -p always <APP> --sysbuild -b <BOARD>@mcuboot//ns -T applications.fmna_tag.atm.mcuboot.uarp.atmwstklib.pd50

or

.. code-block:: bash

    west build -p always <APP> --sysbuild -b <BOARD>@mcuboot//ns -T applications.fmna_tag.atm.mcuboot.uarp.atmwstk.pd50ll


Steps to Program
================

Run the following command to program all the built images:

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device=${JLINK_SN} --jlink --fast_load

.. note::
    - The `--erase_flash` option can be used to erase the entire RRAM and flash of the EVK.
    - Use the `--erase_flash` option cautiously, as it may erase critical updated token information.


Button Functions
================

- Press and hold button1 on EVK for 3 seconds during reboot to unpair and enter pairing mode.


PWM Buzzer
==========

- To enable the PWM Buzzer for FMNA sound implementation, please add **CONFIG_PWM_BUZZER=y** to the <APP>/prj.conf file.
- Since our EVK does not include an onboard buzzer, kindly refine the overlay file at <APP>/boards/<BOARD>_ns.overlay to map the corresponding pin and PWM channel.


Mobile Applications
===================

- Use **Find My** app from the Apple App Store to add and locate the FMNA Tag.
- Use **Find My Certification Asst** app to perform tests: https://apps.apple.com/us/app/find-my-certification-asst/id1532296125


Limitations
===========

- The FMNA Tag application is designed to work with the Apple Find My Network.
- Motion sensor implementation is not included.

By following these steps, you can successfully build, program, and run the **Apple Find My Network Tag** application.
