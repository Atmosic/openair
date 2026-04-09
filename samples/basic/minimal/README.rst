.. _minimal-sample:

Basic: Minimal
##############

Overview
********

This sample provides the smallest possible Zephyr application. In the OpenAir
wrapper, the associated test configuration enables console output so the sample
prints ``Hello World from minimal!`` during automated runs.

For more details, refer to ``zephyr/samples/basic/minimal/README.rst``.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/basic/minimal``.
The source code can be found under ``zephyr/samples/basic/minimal``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/basic/minimal --sysbuild -T samples.basic.minimal.atm

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

Configuration
*************

The ``samples.basic.minimal.atm`` test target enables
``CONFIG_SAMPLE_DO_OUTPUT=y`` so the application emits a console banner for
test verification.