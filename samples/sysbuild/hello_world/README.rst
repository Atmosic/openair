.. sysbuild:

Sysbuild Hello World
####################

Overview
********

The sample demonstrates how to build a Hello World application with MCUBOOT or
NO_MUCBOOT with sysbuild. When building with Zephyr Sysbuild, the build system
adds spe and mcuboot images based on the options SB_CONFIG_SPE and
SB_CONFIG_BOOTLOADER_MCUBOOT selected in the project's additional basic spe,
mcuboot and application rerlated configuration and build files.

Both the application with or without MUCBOOT use the same `main.c` that
prints the name of the DK on which the application is programmed.

Building and running
********************

.. |sample path| replace:: `openair/samples/sysbuild/hello_world`

The sysbuild with or without mcuboot needs to be specified using
``SB_CONFIG_SPE`` and ``SB_CONFIG_BOOTLOADER_MCUBOOT``. It is recommended to use
configuration setups from `sample.yaml` using the ``-T`` option to build
the sample and related configuration will be included.

This sample relies on building application and spe with MCUBOOT or without
MCUBOOT to build at the same time.

  To build the sample for application and spe without MUCBOOT that support atm33 and atm34 only:

  .. code-block:: bash

    west build -p always openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3325-LQK//ns -T samples.sysbuild.hello_world.atm

    west build -p always openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3430e-WQN-2//ns -T samples.sysbuild.hello_world.atm

  To build the sample for application and spe with MUCBOOT that support all atmosic EVKs:

  .. code-block:: bash

    west build -p always openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3325-LQK@mcuboot//ns -T samples.sysbuild.hello_world.atm.mcuboot

    west build -p always openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3430e-WQN-2@mcuboot//ns -T samples.sysbuild.hello_world.atm.mcuboot

    west build -p always openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-M3202-02 -T samples.sysbuild.hello_world.atm.mcuboot.atmx2

  To Program all the built images with sysbuild as follows:

  For atmx2:

  .. code-block:: bash

    west flash --skip-rebuild --verify --device=${ATRDI_SN}

  For atm33 and atm34:

  .. code-block:: bash

    west flash --skip-rebuild --verify --device=${JLINK_SN} --jlink

.. note::
  * If the `west build` command does not specify a ``-d build_dir``, the default build directory will be the `build` folder under current directory. So that since the ``-d build_dir`` has been specified with `west build` command, the `west flash` command should specify the same build_dir with ``-d build_dir`` as well.

  * For atm33 and atm34, if ``-d build_dir`` has been specified, the CONFIG_SPE_PATH in `${BOARD_DIR}/sysbuild/app.conf` and `${BOARD_DIR}/sysbuild/app_mcuboot.conf` must be updated accordingly that used by sysbuild test item in sample.yaml.


Sample Output
=============

  When device bootup, the device console will show with ``Atmosic Sysbuild Hello World of <BOARD_TARGET>``

  ex:
    with MUCBOOT that support all atmosic EVKs:

    .. code-block:: bash

      Atmosic Sysbuild Hello World of ATMEVK-3325-LQK@mcuboot/ATM33xx-5/ns

      Atmosic Sysbuild Hello World of ATMEVK-3430e-WQN-2@mcuboot/ATM34xx-2/ns

      Atmosic Sysbuild Hello World of ATMEVK-M3202-02/ATMx2xx-x1x

    without MCUBOOT that support atm33 and atm34 only:

    .. code-block:: bash

      Atmosic Sysbuild Hello World of ATMEVK-3325-LQK/ATM33xx-5/ns

      Atmosic Sysbuild Hello World of ATMEVK-3430e-WQN-2/ATM34xx-2/ns
