.. _bme280-sample:

Sensor: bme280
##############

Overview
********

This sample demonstrates how to read temperature, pressure, and humidity data
from a Bosch BME280 sensor using the Zephyr sensor driver.

The OpenAir wrapper is intended for Atmosic hardware and includes test targets
for MikroE Weather Click shield configurations over both I2C and SPI.

For more details, refer to ``zephyr/samples/sensor/bme280/README.rst``.

Requirements
************

* Atmosic ATMBTCSTAG-3405 Tag Reference Design
* MikroE Weather Click shield connected over I2C or SPI

Building and Running
********************

This sample is built from ``openair/samples/sensor/bme280``.
The source code can be found under ``zephyr/samples/sensor/bme280``.

Build command (I2C):

.. code-block:: bash

   west build -p always -b ATMBTCSTAG-3405 openair/samples/sensor/bme280 --sysbuild -T samples.sensor.bme280.atm

Build command (SPI):

.. code-block:: bash

   west build -p always -b ATMBTCSTAG-3405 openair/samples/sensor/bme280 --sysbuild -T samples.sensor.bme280.atm.spi

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink [--erase_flash]

Configuration
*************

The OpenAir sample provides a board overlay under ``boards/app.overlay`` for an
I2C-connected BME280, while the test targets select the appropriate shield
configuration for the MikroE Weather Click.