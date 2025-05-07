.. _sysbuild-hello-world-sample:

Sysbuild: Hello World
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

This sample can be found under ``samples/sysbuild/hello_world`` in the openair tree.

Sysbuild with or without MCUboot is specified by setting
``SB_CONFIG_SPE`` and ``SB_CONFIG_BOOTLOADER_MCUBOOT``.
It is recommended to use the configuration setups from the test items defined in `sample.yaml` via the ``-T`` option,
so that the corresponding configurations are automatically included.

Build the sample using:

.. code-block:: bash

    west build -p always -b <board>//ns <application> --sysbuild -T <test_item>

- ``board`` Atmosic device. See :ref:`board <atmosic_evk>`.
- ``application`` Sample folder path.
- ``test_item`` Test item defined in `sample.yaml`.

This sample builds both the application and SPE images, with or without MCUboot.

Build command:

.. code-block:: bash

    west build -p always -b <board>//ns openair/samples/sysbuild/hello_world --sysbuild -T samples.sysbuild.hello_world.atm

Build with MCUboot command:

.. code-block:: bash

    west build -p always -b <board>@mcuboot//ns openair/samples/sysbuild/hello_world --sysbuild -T samples.sysbuild.hello_world.atm.mcuboot


Flash command:

.. code-block:: bash

    west flash --skip-rebuild --verify --device=<serial> [--jlink] --fast_load [--erase_flash]

.. note::
  * The default build directory is the `build` folder under the current directory.
  * If the ``-d build_dir`` option is specified with `west build`, the same ``-d build_dir`` must also be specified with `west flash`.
  * If a custom ``build_dir`` is specified, the `CONFIG_SPE_PATH` in `${BOARD_DIR}/sysbuild/app.conf` and `${BOARD_DIR}/sysbuild/app_mcuboot.conf` must be updated accordingly, since sysbuild test items defined in `sample.yaml` depend on them.


Sample Output
*************

When the device boots up, the console output shows:

.. code-block:: bash

    Atmosic Sysbuild Hello World of <BOARD_TARGET>

- ``BOARD_TARGET`` refers to a specific hardware platform or SoC-based configuration. The full syntax is typically <board>@<revision>/<soc>/<variant>, if applicable.
- ``soc`` ATM33/e and ATM34/e series of Atmosic devices are supported. See :ref:`soc <atmosic_evk>`.

Examples:

With MCUboot:

.. code-block:: bash

    Atmosic Sysbuild Hello World of <board>@mcuboot/<soc>/ns

Without MCUboot:

.. code-block:: bash

    Atmosic Sysbuild Hello World of <board>/<soc>/ns
