.. _peripheral_esl-application:

ESL (Electronic Shelf Label) Peripheral
#######################################

Overview
********

This application demonstrates the **BLE peripheral role in an ESL (Electronic Shelf Label)** system.
It can connect to a BLE central in the ESL role, receive image updates, and display them by sending
synchronization packets or by GATT ESL service control point write commands from the central.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

.. note::
    The following Atmosic EVK boards are supported:

    - ATM34: **ATMEVK-3405-YBV-5** and **ATMEVK-3430e-YQN-5**.
    - ATM5/e: **ATMEVK-5205-NQK-2** (ATM52) and **ATMEVK-5305-NQK-2** (ATM53/e).

.. note::
    - The factory data is used as manufacturer data in advertising, depending on the usage of the
      ESL AP role. By default, it is used for the ESL address, which can be configured by the ESL
      AP.

For Display Settings
====================

- The default setting of the application would enable **external VDDIO** for
  **pervasive epaper e2266qs0f1**.
- For optimized power consumption measurement, use
  ``CONFIG_ENS210_TEMPERATURE_SINGLE=y`` and
  ``CONFIG_ENS210_HUMIDITY_SINGLE=y``.
- To display an image on the electronic paper display (EPD), the board must be connected to an EPD.
  The following EPD shields are supported by Atmosic target devices.

  The default EPD setting is **pervasive_epaper_e2266qs0f1**.

    1. pervasive_epaper_e2266qs0f1
    #. pervasive_epaper_e2266cs0c2

For LED Settings
================

- **ATMEVK-3405-YBV-5** and **ATMEVK-3430e-YQN-5** support **2** LEDs and can be set by configuring
  ``CONFIG_BT_ESLS_LED_NUM=2``

.. note::
    - **ATMEVK-3430e-YQN-5** the EVK LED3 indicates the dc-gpios of pervasive_interface.

For Temperature Sensor
======================

- ATM5/e uses an external ENS210 temperature sensor and does not require an
  additional **JP25** jumper.
- For supported platforms with an onboard temperature sensor, install the
  **JP25** jumper to connect the sensor.

For Buttons
===========

- To disassociate from AP, toggle **button 1** and then press **reset** key.

Building and Running
********************

This application is built from ``openair/applications/peripheral_esl``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/peripheral_esl --sysbuild -T applications.peripheral_esl.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
