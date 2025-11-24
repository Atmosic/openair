BLE Link Controller Driver
###########################

Overview
--------

This document provides information on the BLE driver and link controller options available on the ATM33 platform.

The BLE driver forms the lower controller layer to the upper Bluetooth protocol stack (host stack layer) using Zephyr's host controller interface transport support.  The BLE controller has minimal configuration requirements and will obtain settings through the ``user_param_get()`` registered callback in the driver.  This includes getting the board address from the calibration data found in the secure journal and several run time configurations from Kconfig file:

CONFIG_ATM_SLEEP_ENABLE
```````````````````````

Configures the sleep option level.  Each level gets progressively better at reducing power consumption.
   * 0 - No sleep
   * 1 - Allow link controller to sleep
   * 2 - (Default) Allow system sleep while link controller is sleeping

Note that Zephyr has System level Sleep state adjustment and Device level sleep adjustment. The description above is for BLE device level sleep adjustment.

System level Sleep state adjustment is done automatically by Zephyr kernel if enabled via ``CONFIG_PM`` Kconfig option, and if device setting above allows it. For ATM33 platform, System level dts definition supports five sleep modes such as idle, sleep, retain, hibernate and soc_off. Look at ``zephyr/dts/atm/atmosic/ATM33.dtsi`` for power-states settings.

CONFIG_ATM_EXT_WAKEUP_ENABLE
````````````````````````````

Configures whether external wake up is enabled
    * 0 - no external wake up (do not use, only used for testing)
    * 1 - (Default) enable external wakeup

CONFIG_ATM_SLEEP_ADJ
````````````````````

Configures the default BLE link controller sleep adjustment. The default value should be used.  Do not adjust.


BLE Link Controller Options
---------------------------

There are two BLE Link Controller options: CPD200 Fixed Image and PD50 Statically-linked library. It is required to know which BLE Link Controller option the application is using before building. Refer to application's ``CONFIG_BT_*`` settings in ``prj.conf`` and ``openair/modules/hal_atmosic/ATM33xx-5/drivers/ble/Kconfig`` to check which BLE Link Controller option the application is requiring.

CPD200 Fixed BLE Link Controller Image
``````````````````````````````````````

This controller option utilizes a separately flashed BLE controller image.  This controller image is non-upgradeable and occupies a fixed region of code memory. CPD200 wireless stack is the only flavor supported for fixed controller image.
See the section below on Link Controller Flavors and section on DTS flags to partition memory to host the fixed BLE controller image.

CPD200 controller features less LE Audio. This flavor is selected by the configuration ``-DDTS_EXTRA_CPPFLAGS="-DFIXED_ATMWSTK=CPD200``.

Features:

* All roles (central/peripheral/observer/advertiser)
* BLE 4.2 support
* BLE 5.0 support for Extended and Periodic Advertising, including Periodic Sync
* BLE 5.0 support for Data Length extensions, 2M and CODED PHYs
* BLE 5.1 support for CTE (constant tone extensions)
* BLE 5.2 LE Power control
* No ISO (LE Audio) support.
* Up to 6 Advertisement sets
* Up to 6 Connections

PD50 Statically-linked BLE Link Controller Library
``````````````````````````````````````````````````

This option statically links a BLE controller library with the application image. This offers the ability to fully upgrade the link controller with the application. The use of static linkage and reduced feature sets can help reduce the total code memory footprint of the application. PD50 is the only flavor supported in the statically linked BLE Link Controller library configuration.

PD50 is a compact feature set, peripheral only. No extra CONFIG is needed when building with PD50.

Features:

* Peripheral/Advertiser roles only. No Scanner or Central functionality
* BLE 4.2 support
* BLE 5.0 support for Extended Advertising (No Periodic advertising)
* BLE 5.0 support for Data Length extensions, 2M and CODED PHYs
* No BLE 5.1 support for CTE (No AoA/AoD application support).
* No BLE 5.2 LE Power control
* No ISO (LE Audio) support.
* Up to 4 Advertisement sets
* Up to 3 connections


DTS Flags
---------


When using the statically linked BLE controller with PD50 wireless stack, there are no additional DTS settings.  Since the BLE stack is statically linked to the application it will reside in the same memory partition.

When using the fixed BLE controller image for CPD200 wireless stack, the DTSI configuration needs to create a partition to host the ATMWSTK image. This can be reserved using the following DTS flag:

  .. code-block::

    DTS_EXTRA_CPPFLAGS += -DFIXED_ATMWSTK=CPD200

The partition is sized appropriately for the stack flavor.

Using CPD200 fixed BLE controller image without setting the DTSI configuration will result in the following build error:

  .. code-block::

    fixed_atmwstk.c:32:2: error: #error "-DFIXED_ATMWSTK=<FLAVOR> has to be provided to the device tree generation step rather than the normal build step."
    32 | #error "-DFIXED_ATMWSTK=<FLAVOR> has to be provided to the device tree generation step rather than the normal build step."
       |  ^~~~~
