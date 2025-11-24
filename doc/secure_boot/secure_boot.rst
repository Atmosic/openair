.. _secure_boot:

MCUboot Secure Boot
###################

Overview
********

Secure Boot ensures that only authenticated firmware is executed by verifying digital signatures before booting. The ECDSA P-256 curves have been validated and optimized for Atmosic SoC for improved performance and security. By default, ECDSA P-256 is used when building for Atmosic EVKs.

Key Generation
**************

To generate a key file for signing firmware images, use ``bootloader/mcuboot/scripts/imgtool.py``, which is part of MCUboot. For example, to generate an ECDSA P-256 key:

.. code-block:: bash

   imgtool.py keygen -k my_ecdsa_p256_key.pem -t ecdsa-p256

Key Configuration
*****************

To specify the generated .pem key file for signing, set the ``-DCONFIG_BOOT_SIGNATURE_KEY_FILE=\"<key_file_path>\"`` option when building **both the MCUboot and the application** (not needed for the SPE). If a key file is not explicitly specified, MCUboot uses its default test keys, which should not be used in production for security reasons.

Building with Custom Keys
*************************

Building MCUboot
================

For example, to build MCUboot with the ECDSA P-256 key generated above:

.. code-block:: bash

   west build -p -s <MCUBOOT> -b <BOARD>@mcuboot_bl -d build/<BOARD>/<MCUBOOT> -- -DCONFIG_BOOT_SIGNATURE_KEY_FILE=\"<path_to_new_key_file>/my_ecdsa_p256_key.pem\"

Building the Application
========================

To build the application with the ECDSA P-256 key generated above (assuming the SPE is already built):

.. code-block:: bash

   west build -p -s <APP> -b <BOARD>@mcuboot -d build/<BOARD>/<APP> -- -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"<path_to_new_key_file>/my_ecdsa_p256_key.pem\"


Building with Sysbuild
======================

To build all images with the ECDSA P-256 key generated above using sysbuild:

.. code-block:: bash

   west build -p -s <APP> -b <BOARD>@mcuboot --sysbuild -T <test_item> -DSB_CONFIG_BOOT_SIGNATURE_KEY_FILE=\"<path_to_new_key_file>/my_ecdsa_p256_key.pem\"

.. note::

   The ``<test_item>`` is named with ``.mcuboot`` in sample.yaml of ``<APP>`` folder. Refer to the :ref:`Sysbuild and Flash <sys_build_and_flash>` for usage details of sysbuild.
