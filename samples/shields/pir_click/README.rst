.. _pir-click-sample:

PIR Click
#########

Overview
********

This sample application demonstrates how to interface with a PIR Click sensor shield using the Atmosic ATMBTCSTAG-3405 development board. The PIR Click is a MikroElektronika Click board that features a passive infrared motion sensor with dual interface support for voltage monitoring.

The PIR Click board features the PL-N823-01 pyroelectric sensor, which generates a voltage when exposed to infrared radiation emitted by live bodies. It communicates with the ATM3405 SoC via both GADC/AN and I2C(MCP3221) interfaces.

Product page URL: https://www.mikroe.com/pir-click

Key features of this sample include:

* **Dual Interface Support**: Reads voltage from both internal ADC and external MCP3221 I2C ADC
* **Real-time Monitoring**: Continuous voltage monitoring with 500ms sampling interval
* **Shield Integration**: Uses mikroBUS connector for seamless hardware integration
* **Comparative Analysis**: Displays readings from both interfaces for validation and comparison

The sample is designed for PIR Click shield evaluation on the ATMBTCSTAG-3405 platform, providing voltage monitoring capabilities that can be used as a foundation for motion detection applications.

Requirements
************

* Atmosic ATMBTCSTAG-3405 Tag Reference Design (with IoT expansion board)
* PIR Click sensor shield (MikroElektronika) installed on the ATMBTCSTAG-3405's mikroBUS connector

Building and Running
********************

This sample can be found under ``openair/samples/shields/pir_click``.

Build command:

.. code-block:: bash

   west build -p always -b ATMBTCSTAG-3405 openair/samples/shields/pir_click --sysbuild -T samples.shields.pir_click.atm

Flash the application:

.. code-block:: bash

   west flash --skip-rebuild --verify --dl --device <DEVICE_ID> --fast_load

Sample Output
*************

When the PIR Click shield is connected and the application is running, the console output shows:

.. code-block:: console

   Sample interval: 500 ms

   ADC configured: channel 7
   MCP3221 device ready: PIR_I2C_ADC

   Starting PIR sensor voltage monitoring...

   [00:00:00.500,000] <inf> pir_click: ADC: 1580 mV, MCP3221: 1650 mV
   [00:00:01.000,000] <inf> pir_click: ADC: 1582 mV, MCP3221: 1648 mV
   [00:00:01.500,000] <inf> pir_click: ADC: 1579 mV, MCP3221: 1651 mV
   [00:00:02.000,000] <inf> pir_click: ADC: 1581 mV, MCP3221: 1649 mV

The voltage readings represent the analog output from the PIR sensor, which can be used as a foundation for motion detection applications.

References
**********

For more detailed information on the PIR Click, refer to the MikroElektronika official documentation:

* `PIR Click <https://www.mikroe.com/pir-click>`_
