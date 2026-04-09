.. _led_pwm-sample:

Basic: LED PWM
##############

Overview
********

This sample is used to test the led-pwm driver.

.. note::

   The PWM device supports a frequency range of 123 Hz to 8 MHz. The minimum
   frequency of 123 Hz is significantly higher than the flicker fusion threshold
   (typically 50-60 Hz for human vision), which means the PWM output will not
   blink slow enough for the human eye to discern individual on/off cycles. The
   LED will appear to be continuously lit at varying brightness levels rather
   than visibly blinking.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/drivers/led/pwm``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/drivers/led/pwm --sysbuild -T samples.drivers.led.pwm.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]
