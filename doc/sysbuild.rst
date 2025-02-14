.. _atmosic_sysbuild:

Atmosic Sysbuild
################

Overview
********
Leverage sysbuild of zephyr to build Atmosic multi-images with basic options to simply build commands.

The Atmosic test items in sample.yaml of examples will be named as '<APP_TEST_ITEM_BASE>.atm.' as prefix and all related basic config options to support west build.
<APP_TEST_ITEM_BASE> will be constructed as sample folder without repository root, ex: samples.sysbuild.hello_world.atm in openair\samples\sysbuild\hello_world\sample.yaml

- Item name with "mcuboot": supports mcuboot or not
- Item name ends with "atmx2": supports atmevk-02 only

When extra_configs includes CONFIG_ATM_SOC_ALLOW means the Atmosic SOC series supported. The value should be the value of SOC_SERIES, split with comma when multiplesoc support, ex: ATM33 or ATM33,ATM34. When CONFIG_ATM_SOC_ALLOW not specified or the value is empty, it means to support all Atmosic SOC series besides atmx2.

- CONFIG_ATM_SOC_ALLOW="ATM34": supports atm34 only
- CONFIG_ATM_SOC_ALLOW="ATM33,ATM34": supports both atm33 and atm34
- CONFIG_ATM_SOC_ALLOW="": supports all Atmosic SOC series besides atmx2

Refer to ``zephyrproject\openair\samples\sysbuild\hello_world`` for detail

.. _build_with_sysbuild:

Build with sysbuild
-------------------

west build command::

  cd zephyrproject
  west build -p always --sysbuild <APP> -b <BOARD>//ns -T <APP_TEST_ITEM>

  <APP>: sample folder path related to zephyrproject
  <BOARD>: Atmosic board, ex: ATMEVK-3330e-QN-5, ATMEVK-3405-PQK-2
  <APP_TEST_ITEM>: test item, ex: samples.sysbuild.hello_world.atm, samples.sysbuild.hello_world.atm.mcuboot

.. _flash_with_sysbuild:

Flash with sysbuild
-------------------

west flash command for atm33evk and atm34evk::

  cd zephyrproject
  west flash --skip-rebuild --verify --device=<JLINK_SN> --jlink
  <JLINK_SN>: jlink serial, ex: ``000900036843``

west flash command for atmevk-02::

  cd zephyrproject
  west flash --skip-rebuild --verify --device=<FTDI_SN>
  <FTDI_SN>: FTDI serial, ex: ``ATRDI1234``

.. note::
  * If the `west build` command does not specify a ``-d build_dir``, the default build directory will be the `build` folder under current directory. So that since the ``-d build_dir`` has been specified with `west build` command, the `west flash` command should specify the same build_dir with ``-d build_dir`` as well.

  * For atm33 and atm34, if ``-d build_dir`` has been specified, the CONFIG_SPE_PATH in `${BOARD_DIR}/sysbuild/app.conf` and `${BOARD_DIR}/sysbuild/app_mcuboot.conf` must be updated accordingly that used by sysbuild test item in sample.yaml.


Sysbuild Utility Script
***********************

The ``zephyrproject/openair/tools/scripts/sysbuild_utils.py`` script help to list all Atmosic test items information with repository folders and generate Atmosic test items to zephyr repository from known supported samples.

+---------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| command arguments   |  Description                                                                                                                                                          |
+=====================+=======================================================================================================================================================================+
| -d, --debug         |  debug enabled, default false                                                                                                                                         |
+---------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| -r, --repo_root     |  repository folder under zephyrproject, default: openair, atmosic-internal, atmosic-private, zephyr                                                                   |
+---------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| -t, --test_dir      |  sample folder path relative to repo_root, to search all sample.yaml under sample folder, default: samples of zephyr,  samples and application of other repositories  |
+---------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| -e, --exp_items     |  test items that could be found in sample.yaml , default: all                                                                                                         |
+---------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| list                |  list atm test item info                                                                                                                                              |
+---------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| gen                 |  generate atm test items from known support list                                                                                                                      |
+---------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+

To see more detail::

  cd zephyrproject
  python3 openair/tools/scripts/sysbuild_utils.py -h


.. _list_atmosic_test_items:

List Atmosic test items
-----------------------

Examples of list found Atmosic test items in test_dirs of repositories::

  cd zephyrproject
  python3 openair/tools/scripts/sysbuild_utils.py list
  python3 openair/tools/scripts/sysbuild_utils.py -r openair list
  python3 openair/tools/scripts/sysbuild_utils.py -r zephyr,openair list
  python3 openair/tools/scripts/sysbuild_utils.py -t samples/sysbuild/hello_world -r openair list
  python3 openair/tools/scripts/sysbuild_utils.py -e samples.sysbuild.hello_world.atm -t samples/sysbuild/hello_world -r openair list

Generate Atmosic test items
---------------------------

Atmosic test items can be generated to the zephyr repository according to known supported samples in ``zephyrproject/openair/tools/scripts/sysbuild/samples``. This appends Atmosic test items to ``zephyrproject/zephyr/samples``.

Examples of gen known Atmosic test items of samples to zephyr repository::

  cd zephyrproject
  python3 openair/tools/scripts/sysbuild_utils.py -r zephyr gen
  python3 openair/tools/scripts/sysbuild_utils.py -t samples/bluetooth/beacon -r zephyr gen
  python3 openair/tools/scripts/sysbuild_utils.py -e samples.bluetooth.beacon.atm.mcuboot -t samples/bluetooth/beacon -r zephyr gen

Refer to list_atmosic_test_items_ to check Atmosic test items after generated.
Refer to build_with_sysbuild_ and flash_with_sysbuild_ to build and flash Atmosic test items.
