.. _sysbuild-hello-world-sample:

Sysbuild: hello_world
#####################

Overview
********

This sample demonstrates how to build a Hello World application with or without
MCUboot using Zephyr's sysbuild.
When building with Zephyr sysbuild, the build system adds
SPE and MCUboot images based on the options ``SB_CONFIG_SPE`` and
``SB_CONFIG_BOOTLOADER_MCUBOOT``, selected in the project's additional basic SPE,
MCUboot, and application-related configuration and build files.

- ``SB_CONFIG_BOOTLOADER_MCUBOOT`` Enable sysbuild to build with a bootloader image.
- ``SB_CONFIG_SPE`` Enable sysbuild to build with an SPE image.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/sysbuild/hello_world``.

Sysbuild with or without MCUboot is specified by setting
``SB_CONFIG_SPE`` and ``SB_CONFIG_BOOTLOADER_MCUBOOT``.
It is recommended to use the configuration setups from the test items defined in `sample.yaml` via the ``-T`` option,
so that the corresponding configurations are automatically included.

Build the sample using:

.. code-block:: bash

    west build -p always -b <BOARD> <APP> --sysbuild -T <test_item>

- ``BOARD`` Atmosic device. See :ref:`board <atmosic_evk>`.
- ``APP`` Sample folder path.
- ``test_item`` Test item defined in `sample.yaml`.

Build command:

.. code-block:: bash

    west build -p always -b <BOARD> openair/samples/sysbuild/hello_world --sysbuild -T samples.sysbuild.hello_world.atm

Build with MCUboot command:

.. code-block:: bash

    west build -p always -b <BOARD>@mcuboot openair/samples/sysbuild/hello_world --sysbuild -T samples.sysbuild.hello_world.atm.mcuboot


Flash command:

.. code-block:: bash

    west flash --skip-rebuild --verify --device <DEVICE_ID> [--jlink] --fast_load [--erase_flash]

.. note::
  * The default build directory is the `build` folder under the current directory.
  * If the ``-d build_dir`` option is specified with `west build`, the same ``-d build_dir`` must also be specified with `west flash`.


Sample Output
*************

When the device boots up, the console output shows:

.. code-block:: bash

    Atmosic Sysbuild Hello World of <BOARD_TARGET>

- ``BOARD_TARGET`` refers to a specific hardware platform or SoC-based configuration. The full syntax is typically <BOARD>@<revision>/<soc>, if applicable.
- ``soc`` ATM33/e and ATM34/e series of Atmosic devices are supported. See :ref:`soc <atmosic_evk>`.

Examples:

With MCUboot:

.. code-block:: bash

    Atmosic Sysbuild Hello World of <BOARD>@mcuboot/<soc>

Without MCUboot:

.. code-block:: bash

    Atmosic Sysbuild Hello World of <BOARD>/<soc>
