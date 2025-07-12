.. _lis2dh-sample:

Sensor: lis2dh
##############

Overview
********

This sample application demonstrates how to read accelerometer data from a LIS2DH sensor using the Zephyr driver. It is also compatible with the LIS2DH12 and LIS3DH sensors.

The application periodically reads the sensor's X, Y, and Z axis values every 2 seconds and prints the data to the console.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample can be found under ``openair/samples/sensor/lis2dh``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/samples/sensor/lis2dh --sysbuild -T samples.sensor.lis2dh.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

References
**********

For more detailed information on the LIS2DH sensor and its driver, refer to the official Zephyr Project documentation:

* `LIS2DH Motion Sensor <https://docs.zephyrproject.org/latest/samples/sensor/lis2dh/README.html>`_.
