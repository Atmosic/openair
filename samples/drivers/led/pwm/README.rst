.. _led_pwm-sample:

Basic: LED PWM
##############

Overview
********

This sample is used to test the led-pwm driver.

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

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]
