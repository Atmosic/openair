.. _wurx_documentation:

Wake-Up Receive (WuRx)
######################

Overview
********

The Wake-Up Receive (WuRx) is an ultra-low-power wake-up receiver available on select Atmosic chips. WuRx enables systems to remain in hibernation mode while monitoring for specific radio signals until a wake-up event is detected.

Supported Boards
================

WuRx is supported on the following boards:

* **ATMEVK-3430e-YQN-5** (ATM34)
* **ATMEVK-3330e-QN-6** (ATM33)
* **ATMEVK-3330-QN-6** (ATM33)

Wake-Up Patterns
================

WuRx supports three wake-up patterns:

* **Bluetooth inquiry** - Wake-up from Android mobile device Bluetooth scans
* **iBeacon advertisements** - Wake-up from iOS device iBeacon signals
* **High duty cycle BLE advertisements** - Wake-up from EVK-to-EVK communication

Wake-Up Pattern Overlays
************************

WuRx supports three wake-up patterns, each configured via a device tree overlay located in ``openair/doc/wurx/``.

To enable WuRx functionality, build with ``CONFIG_WURX=y`` and specify the appropriate overlay file using ``-DEXTRA_DTC_OVERLAY_FILE``.

Bluetooth Inquiry
=================

Configure WURX to detect Bluetooth inquiry scans (can be sent from an Android phone):

.. code-block:: bash

    -DCONFIG_WURX=y -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/bt_inquiry.overlay"

iBeacon
=======

Configure WURX to detect iBeacon advertisements (can be sent from an iPhone):

.. code-block:: bash

    -DCONFIG_WURX=y -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/ibeacon.overlay"

High Duty Cycle Advertisements
==============================

Configure WURX to detect high duty cycle advertisements:

.. code-block:: bash

    -DCONFIG_WURX=y -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/high_duty_adv.overlay"

The ``openair/samples/bluetooth/high_duty_adv`` example can be used to issue high duty cycle advertisements as a wake-up signal source.

Using WuRx in Applications
***************************

Sample Application
==================

A complete WuRx sample application is available at ``openair/samples/drivers/wurx``.
This sample demonstrates:

* WuRx device initialization
* Checking for wake-up events after hibernation
* Entering low-power mode with WuRx enabled

See :ref:`wurx_sample` for detailed information.

Sensor Beacon Application
==========================

The sensor beacon application (``openair/applications/sensor_beacon``) demonstrates WuRx integration in a real-world scenario. When built with ``CONFIG_WURX=y`` and a wake-up pattern overlay, the application:

1. Powers on and advertises sensor data for a fixed period
2. Enters deep hibernation with WuRx monitoring enabled
3. Wakes up when a configured radio signal is detected
4. Returns to step 1

The application is designed to work with the Atmosic DevTools mobile app for monitoring sensor data and triggering wake-up events.

See the sensor beacon documentation for detailed build instructions with WuRx overlays.

See Also
********

* :ref:`wurx_sample` - WuRx sample application
* :ref:`sensor_beacon-application` - Sensor beacon with WuRx support
