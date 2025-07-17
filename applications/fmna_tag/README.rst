.. _fmna_tag-application:

Apple Find My Network Tag
#########################


Overview
********

Demonstrates the Apple Find My Network Tag functionality.


Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

.. note::
    Currently, only the **ATM33/e** and **ATM34/e** series of Atmosic devices are supported.


ADK Integration Guide
*********************

Option1 (recommended)
=====================

The Atmosic Zephyr ADK core is provided as the binary library ``libatm_fmna.a`` and included in the public release, so no additional effort or ADK source code is required to build the example.
Customization can still be performed through configuration settings or application-level modifications, such as button behavior and buzzer customization.

Option2
=======

If modification of the ADK source code is truly required, please contact Atmosic and provide the MFi Program ID. Atmosic will provide a patch to apply the Atmosic Zephyr porting changes to the ADK source code.

Follow the steps as below:

1. Download the ADK source code archive ``Find My network ADK 1.0.zip`` from the Apple MFi Content Center.
2. Extract it and place the ``findmy_network_adk`` directory under ``zephyrproject/vendor``.
3. Place the Atmosic patch file (e.g., ``<patch_name>.diff``) into ``zephyrproject/vendor/findmy_network_adk``.
4. Navigate to ``zephyrproject/vendor/findmy_network_adk`` and execute the following command:

   .. code-block:: bash

      patch -p1 < <patch_name>.diff

5. Add the following entry to the ``projects`` section of ``openair/west.yml``:

   .. code-block:: yaml

      - name: fmna
        url: "ignore://local-only"
        revision: <revision>  # e.g. rc/25.05.0
        path: vendor/findmy_network_adk

6. **Do not run** ``west update`` when using this local source approach.

7. Build the application with the following Kconfig option disabled to compile the ADK source code instead of linking the binary library:

   .. code-block:: bash

      CONFIG_ATM_FMNA_LIB=n


Device Manufacturer Settings
****************************

Edit ``tag_data/factory.yml`` to configure device factory data:

- **serial_number**: Unique identifier for the device.
- **auth_uuid**: Authentication UUID.
- **auth_token**: First token for device authentication.

.. note::
    These values are used to authenticate the device and provided by the Apple MFi Program.

.. warning::
    The latest updated **auth_token** can be found in the boot-up console log.
    It is recommended to **back up** this value before erasing RRAM or flash,
    especially when the token is intended to be reused for development purposes.
    To reuse the token, overwrite the **auth_token** field with the previously backed-up value.

    Example log:
    [00:00:00.762,000] <inf> fmna: auth_token
    tag_value: 0x0027E41A26AA24549ACD43B0DC051A9AB9100401010267010219E7...


FMNA Configuration Settings
***************************

Below are the FMNA device configurations. These settings can be added to ``prj.conf`` based on FMNA customization or development requirements;
otherwise, default parameters will be used.


Custom Bluetooth Device Address
===============================

`Enable custom Bluetooth device address for testing or development purposes. Otherwise, the device's EUI-48 MAC address will be used.`

Example::

  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR=y
  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR_VALUE="ED:15:48:87:6E:EF"


FMNA Accessory Information
==========================

Example::

  CONFIG_FMNA_PRODUCT_DATA="DFECEFF1E1FF54DB"
  CONFIG_FMNA_ACCESSORY_CATEGORY=129
  CONFIG_FMNA_ACCESSORY_CAPABILITY=31
  CONFIG_FMNA_BATTERY_TYPE=1
  CONFIG_FMNA_PID=51966
  CONFIG_FMNA_MANUFACTURER_NAME="Osprey"
  CONFIG_FMNA_MODEL_NAME="Bike"
  CONFIG_FMNA_HARDWARE_VERSION="1"


FMNA Firmware Version
=====================

Example::

  CONFIG_FMNA_VERSION_MAJOR=1
  CONFIG_FMNA_VERSION_MINOR=0
  CONFIG_FMNA_VERSION_REVISION=18


Building and Running
********************

This application is built from ``openair/applications/fmna_tag``.


Without UARP Support
====================

Without UARP Support there will be more memory available for the application, but it will not support the UARP protocol.
Run the following command to build the SPE, application and factory data:

.. code-block:: bash

    west build -p always -b <BOARD>//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm


With UARP Support
=================

Run the following command to build the mcuboot, SPE, application and factory data:

.. code-block:: bash

    west build -p always -b <BOARD>@mcuboot//ns openair/applications/fmna_tag --sysbuild -T applications.fmna_tag.atm.mcuboot.uarp.atmwstk.pd50


Programming
===========

To flash the built images:

.. code-block:: bash

    west flash --skip-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load [--erase_all]

.. note::
    - Use the ``--erase_all`` option cautiously, as it may erase critical updated token information.


Button Functions
****************

In order for the button to work, jumpers JP25 and JP27 need to be installed on the EVK.

- Press and hold button2 on EVK for 3 seconds during reboot to unpair and enter pairing mode.


PWM Buzzer
**********

- To enable the PWM Buzzer for FMNA sound implementation, please add **CONFIG_PWM_BUZZER=y** to the prj.conf file.
- Since Atmosic EVK does not include an onboard buzzer, kindly refine the overlay file at boards/<BOARD>_ns.overlay to map the corresponding pin and PWM channel.
- By default, the PWM pin is mapped to LED1 on the EVK, allowing LED1 to light up while playing sound for evaluation purposes.

.. code-block:: dts

    / {
	buzzer: buzzer {
		compatible = "pwm-buzzer";
		pwms = <&pwm3 3 PWM_USEC(1000) PWM_POLARITY_NORMAL>;
		pulse = <PWM_USEC(500)>;
	};
    };

    &pwm3 {
	pin = <29>;
	status = "okay";
    };


Mobile Applications
*******************

- Use **Find My** app from the Apple App Store to add and locate the FMNA Tag.
- Use **Find My Certification Asst** app to perform tests: https://apps.apple.com/us/app/find-my-certification-asst/id1532296125


Limitations
***********

- The FMNA Tag application is designed to work with the Apple Find My Network.
- Motion sensor implementation is not included.
