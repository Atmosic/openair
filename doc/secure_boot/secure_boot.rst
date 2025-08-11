MCUboot Secure Boot
###################

Secure Boot ensures that only authenticated firmware is executed by verifying digital signatures before booting. The ECDSA P-256 curves have been validated and optimized for Atmosic SoC for improved performance and security. By default, ECDSA P-256 is used when building for Atmosic EVKs.

To generate a key file for signing firmware images, use ``bootloader/mcuboot/scripts/imgtool.py``, which is part of MCUboot. For example, to generate an ECDSA P-256 key::

  imgtool.py keygen -k my_ecdsa_p256_key.pem -t ecdsa-p256

To specify the generated .pem key file for signing, set the ``-DCONFIG_BOOT_SIGNATURE_KEY_FILE=\"<key_file_path>\"`` option when building **both the MCUboot and the application** (not needed for the SPE). If a key file is not explicitly specified, MCUboot uses its default test keys, which should not be used in production for security reasons.

For example, to build MCUboot with the ECDSA P-256 key generated above::

  west build -p -s <MCUBOOT> -b <BOARD>@mcuboot_bl -d build/<BOARD>/<MCUBOOT> -- -DCONFIG_BOOT_SIGNATURE_KEY_FILE=\"<path_to_new_key_file>/my_ecdsa_p256_key.pem\""

To build the application with the ECDSA P-256 key generated above (assuming the SPE is already built)::

  west build -p -s <APP> -b <BOARD>@mcuboot//ns -d build/<BOARD>_ns/<APP> -- -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"<path_to_new_key_file>/my_ecdsa_p256_key.pem\" -DCONFIG_SPE_PATH=\"<WEST_TOPDIR>/build/<BOARD>/<SPE>\"
