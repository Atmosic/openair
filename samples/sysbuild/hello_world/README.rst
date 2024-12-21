.. sysbuild:

Sysbuild Hello World
###############

Overview
********

The sample demonstrates how to build a Hello World application with MCUBOOT or
NO_MUCBOOT the :ref:`zephyr:sysbuild`. When building with Zephyr Sysbuild, the
build system adds spe and mcuboot images based on the options SB_CONFIG_SPE and
SB_CONFIG_BOOTLOADER_MCUBOOT selected in the project's additional basic spe,
mcuboot and application rerlated configuration and build files.

Both the application with or without MUCBOOT use the same :file:`main.c` that
prints the name of the DK on which the application is programmed.

Building and running
********************

.. |sample path| replace:: :file:`openair/samples/sysbuild/hello_world`

The sysbuild with or without mcuboot needs to be specified using
``SB_CONFIG_SPE` and `SB_CONFIG_BOOTLOADER_MCUBOOT``. It is recommended to use
configuration setups from :file:`sample.yaml` using the ``-T`` option to build
the sample and related configuration will be included.

Building and Running
********************

This sample relies on building application and spe with MCUBOOT support or
without MCUBOOT to build at the same time.

  You can build the sample for application and spe without MUCBOOT with sysbuild
  as follows:

  .. code-block:: console
     west build -p openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3325-LQK//ns -T samples.sysbuild.hello_world.atm
     west build -p openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3430e-WQN-2//ns -T samples.sysbuild.hello_world.atm


  You can build the sample for application and spe with MUCBOOT with sysbuild
  as follows:

  .. code-block:: console
     west build -p openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3325-LQK@mcuboot//ns -T samples.sysbuild.hello_world.atm.mcuboot
     west build -p openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-3430e-WQN-2@mcuboot//ns -T samples.sysbuild.hello_world.atm.mcuboot
     west build -p openair/samples/sysbuild/hello_world --sysbuild -b ATMEVK-M3202-02 -T samples.sysbuild.hello_world.atm.atmevk-02.mcuboot

  You can programming the all built images with sysbuild as follows:
  .. code-block:: console
     west flash --skip-rebuild --verify --device=${JLINK_SN} --jlink -d build
     west flash --skip-rebuild --verify --device=${$ATRDI_SN} -d build


Note: The west build ``-d` build_dir`` does not specify and the default will be
the `build` folder under current directory. So that once the ``-d` build_dir``
has been specified, it should to update the CONFIG_SPE_PATH in
${BOARD_DIR}/sysbuild/app.conf and ${BOARD_DIR}/sysbuild/app_mcuboot.conf
accordingly that used by sysbuild test item in sample.yaml.

Sample Output
=============

.. code-block:: console

  Atmosic Sysbuild Hello World of {BOARD_TARGET}

  ex:
    with MUCBOOT:
      Atmosic Sysbuild Hello World of ATMEVK-3325-LQK@mcuboot/ATM33xx-5/ns
      Atmosic Sysbuild Hello World of ATMEVK-3430e-WQN-2@mcuboot/ATM34xx-2/ns
      Atmosic Sysbuild Hello World of ATMEVK-M3202-02/ATMx2xx-x1x
    without MCUBOOT:
      Atmosic Sysbuild Hello World of ATMEVK-3325-LQK/ATM33xx-5/ns
      Atmosic Sysbuild Hello World of ATMEVK-3430e-WQN-2/ATM34xx-2/ns

