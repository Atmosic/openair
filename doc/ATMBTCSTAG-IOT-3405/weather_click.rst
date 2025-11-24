.. _weather-click:

Weather Click (bme280)
######################

Overview
********

This sample application provides a practical demonstration of how to read environmental data from a BME280 sensor using the Zephyr driver. The BME280 is a digital sensor from Bosch Sensotec that combines humidity, pressure, and temperature sensors into a single package.

Product page URL: https://www.mikroe.com/weather-click

Key features of this sample include:

* **Periodic Data Reading**: Fetches temperature, pressure, and humidity values from the sensor every second.
* **Console Output**: Prints the formatted sensor readings to the system console.
* **Interface Support**: Supports both I2C and SPI for communication with the sensor.

Requirements
************

* Atmosic ATMBTCSTAG-3405 Tag Reference Design (with IoT expansion board)
* MikroE Weather Click shield installed on the ATMBTCSTAG-3405's mikroBUS connector

Building and Running
********************

This sample is located in the ``openair/samples/sensor/bme280`` directory.

Build command:

**ATMBTCSTAG-3405 with MikroE Weather Click (I2C)**

.. code-block:: bash

   west build -p always -b ATMBTCSTAG-3405 openair/samples/sensor/bme280 --sysbuild -T samples.sensor.bme280.atm

**ATMBTCSTAG-3405 with MikroE Weather Click (SPI)**

.. code-block:: bash

   west build -p always -b ATMBTCSTAG-3405 openair/samples/sensor/bme280 --sysbuild -T samples.sensor.bme280.atm.spi

Flash the application:

.. code-block:: bash

   west flash --skip-rebuild --dl --device <DEVICE_ID> --fast_load [--erase_flash]

References
**********

For more detailed information, consult the official documentation:

* `BME280 humidity and pressure sensor (Zephyr Project) <https://docs.zephyrproject.org/latest/samples/sensor/bme280/README.html>`_
* `BME280 Sensor Datasheet (Bosch Sensotec) <https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme280-ds002.pdf>`_
