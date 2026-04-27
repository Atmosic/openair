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

Trigger mode is not enabled with ``CONFIG_ADT7420_TRIGGER`` directly.
Instead, enable one of the ADT7420 driver trigger options:

- ``CONFIG_ADT7420_TRIGGER_GLOBAL_THREAD=y`` to handle interrupts using the
  global work queue.
- ``CONFIG_ADT7420_TRIGGER_OWN_THREAD=y`` to create a dedicated thread for
  ADT7420 interrupt handling.

If the measured temperature stays within the current window, log messages such
as ``Wait for trigger...timed-out`` are expected until the threshold is crossed.

Requirements
************

- Atmosic EVK <:ref:`board | serial <atmosic_evk>`>
- ADT7420 sensor connected on I2C
- For trigger mode, connect the ADT7420 ``INT`` pin to an interrupt-capable GPIO

Building and Running
********************

This sample is built from ``openair/samples/sensor/adt7420``.

Standard build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/sensor/adt7420 --sysbuild -T samples.sensor.adt7420.atm

Trigger mode build commands:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/sensor/adt7420 --sysbuild -T samples.sensor.adt7420.atm -- -DCONFIG_ADT7420_TRIGGER_GLOBAL_THREAD=y

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/sensor/adt7420 --sysbuild -T samples.sensor.adt7420.atm -- -DCONFIG_ADT7420_TRIGGER_OWN_THREAD=y

Trigger mode also requires the ADT7420 devicetree node to define
``int-gpios``. The sample ``app.overlay`` does not currently include this
property, so add a board-specific overlay or update the local overlay before
building in trigger mode.

Example overlay addition:

.. code-block:: dts

   &arduino_i2c {
       adt7420@4b {
           int-gpios = <&gpio1 5 GPIO_ACTIVE_HIGH>;
       };
   };

Update the GPIO controller, pin number, and flags to match the board and the
way the ADT7420 ``INT`` pin is wired.

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
