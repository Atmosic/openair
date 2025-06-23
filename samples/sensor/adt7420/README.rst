.. _adt7420-sample:

Sensor: adt7420
###############

Overview
********

This sample application periodically (1Hz) measures the ambient temperature
in degrees Celsius. The result is written to the console.

When configured in trigger mode the update interval is 5 s, and the
sample maintains a |plusminus| 1 |deg| C window around a recent
temperature.  As soon as the temperature goes outside the window an
interrupt causes the application to display an event and update the
upper and lower window boundaries.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/sensor/adt7420``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/sensor/adt7420 --sysbuild -T samples.bluetooth.adt7420.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]
