.. _i2s_output:

Drivers: i2s_output
###################

Overview
********

This sample demonstrates how to use an I2S driver to send an output stream of audio data. Currently,
no codec is used with this sample. The I2S output can be verified with a signal analyzer.

The sample will send a short burst of audio data, consisting of a sine wave. The I2S TX queue will
then be drained, and audio output will stop.

Requirements
************

The I2S device to be used by the sample is specified by defining a devicetree alias named ``i2s_tx``

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/drivers/i2s/output``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/samples/drivers/i2s/output --sysbuild -T samples.drivers.i2s.output.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]
