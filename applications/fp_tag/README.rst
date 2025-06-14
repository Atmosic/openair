.. _fp_tag-application:

Google Find My Device Network Tag
#################################

Overview
********

This sample demonstrates the **Google Find My Device Network Tag** functionality, integrating the following GATT services:

- **Fast Pair (FP) Service**
- **Find My Device Network Extension (FMDN)**
- **Detecting Unwanted Location Trackers (DULT) Service**

The sample is compatible with the Android **Find My Device** app.

Requirements
************

- Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

.. note::

   Currently, only the **ATM33/e** and **ATM34/e** series of Atmosic devices are supported.

Pairing and Provisioning Procedure
**********************************

The device operates through multiple modes when interacting with the **Find My Device** app:

1. When an **unpaired** device boots, press :ref:`Button1 <Button1>` to start FP Discoverable Advertisement with the Model ID.
2. The **Find My Device** app will detect the device and display a pop-up. Tap the **Connect** icon to initiate Fast Pairing.
3. Upon successful **pairing**, the device starts FP Non-discoverable Advertisement, containing an encrypted account key list.
4. The user must press the **Agree** icon to initiate the FMDN **provisioning** process.
5. After successful **provisioning**, the device begins FMDN Advertisement with an encrypted EID and stops FP Non-discoverable Advertisement by default.
6. The device is then listed in the user's device list, and its location is displayed on the map.

.. note::

   After pairing, the **Agree** icon must be pressed within **5 minutes**. Otherwise, the device will revert to unpaired mode.

   To enable both FP and FMDN advertisements after provisioning, add the following build option:

  .. code-block:: console

     CONFIG_FP_FMDN_PROVISION_EN_FP_ADV=y

.. _Button1:

Button1
*******

:ref:`Button1` provides context-dependent functionality:

- **Unpaired mode**: Press to start FP Discoverable Advertisement.
- **Provisioned mode**: Press to stop "Play Sound" triggered by the **Find My Device** app.
- **UTP (Unwanted Tracker Protection) mode**: Press to enable "Identifier Read State" for DULT GATT write requests.

  .. note::

     The "Identifier Read State" must remain enabled for **5 minutes** after user action.

- **Resetting**: Press and hold for **3 seconds during reboot** to unpair and reset the device.

Build Options
*************

Fast Pair Discoverable Advertisement
====================================

By default, the advertisement uses a static address derived from the device's EUI-48.

To Enable custom Bluetooth device address for testing or development purposes. Otherwise, the device's EUI-48 MAC address will be used.

Example:

  .. code-block:: console

     CONFIG_FAST_PAIR_USER_PAIR_BT_ADDR=y
     CONFIG_FAST_PAIR_PAIR_BT_ADDR=<BD address>

If ``CONFIG_FAST_PAIR_PAIR_BT_ADDR`` not specified, the default custom Bluetooth device address is``E5:C4:11:11:11:11``

OTA Support via BLE
===================

- To enable OTA (Over-The-Air) updates via BLE, add the following build option:

  .. code-block:: console

     EXTRA_CONF_FILE="basic_ota_bt.conf"

This includes MCUmgr SMP services and enables OTA GATT services alongside FP and FMDN advertisements.

.. note::

   FP non-discoverable and FMDN advertisements use resolvable private addresses, which are **not configurable**.

PWM Buzzer Support
==================

- Enable the PWM Buzzer feature by adding the following to your application configuration:

  .. code-block:: console

     CONFIG_PWM_BUZZER=y

- Since the Atmosic EVK lacks an onboard buzzer, update the device tree overlay at:

  ``<application>/boards/<board>_ns.overlay`` to map the appropriate pin and PWM channel.

Building and Running
********************

This sample can be found under ``applications/fp_tag`` in the openair tree.

Build Without MCUboot
=====================

Build the Secure Processing Environment (SPE) and application:

.. code-block:: console

    west build -p always -b <board>//ns openair/applications/fp_tag --sysbuild -T applications.fp_tag.atm

Build With MCUboot
==================

Build MCUboot, SPE, and the application:

.. code-block:: console

    west build -p always -b <board>@mcuboot//ns openair/applications/fp_tag --sysbuild -T applications.fp_tag.atm.mcuboot

Specify User-Pair Bluetooth Address
===================================

Specify a static address for FP discoverable advertisements:

.. code-block:: console

    west build -p always -b <board>//ns openair/applications/fp_tag --sysbuild -T applications.fp_tag.atm -- -DCONFIG_FAST_PAIR_USER_PAIR_BT_ADDR=y -DCONFIG_FAST_PAIR_PAIR_BT_ADDR="E5:C4:12:12:12:12"

Build With OTA Support
======================

Enable OTA via BLE and build the full image:

.. code-block:: console

    west build -p always -b <board>@mcuboot//ns openair/applications/fp_tag --sysbuild -T applications.fp_tag.atm.mcuboot.ota

Programming
===========

To flash the built images:

.. code-block:: console

    west flash --skip-rebuild --verify --device=<serial> --jlink --fast_load [--erase_flash]
