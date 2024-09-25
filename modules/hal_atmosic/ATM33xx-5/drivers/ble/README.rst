BLE Link Controller Driver
###########################

Overview
--------

This document provides information on the BLE driver and link controller options available on the ATM33 platform.

The BLE driver forms the lower controller layer to the upper Bluetooth protocol stack (host stack layer) using Zephyr's host controller interface transport support.  The BLE controller has minimal configuration requirements and will obtain settings through the user_param_get() registered callback in the driver.  This includes getting the board address from the calibration data found in the secure journal and several run time configurations from Kconfig file:

CONFIG_ATM_SLEEP_ENABLE
```````````````````````

Configures the sleep option level.  Each level gets progressively better at reducing power consumption.
   0 - No sleep
   1 - Allow link controller to sleep
   2 - (Default) Allow system sleep while link controller is sleeping

Note that Zephyr has System level Sleep state adjustment and Device level sleep adjustment. The descritpion above is for BLE device level sleep adjustment.

System level Sleep state adjustment is done automatically by Zephyr kernel if enabled via CONFIG_PM Kconfig option, and if device setting above allows it. For ATM33 platform, System level dts definition supports five sleep modes such as idle, sleep, retain, hibernate and soc_off. Look at zephyr/dts/atm/atmosic/ATM33.dtsi for power-states settings.

CONFIG_ATM_EXT_WAKEUP_ENABLE
````````````````````````````

Configures whether external wake up is enabled
    0 - no external wake up (do not use, only used for testing)
    1 - (Default) enable external wakeup

CONFIG_ATM_SLEEP_ADJ
````````````````````

Configures the default BLE link controller sleep adjustment. The default value should be used.  Do not adjust.


BLE Link Controller Options
---------------------------

Fixed BLE Link Controller image (ATMWSTK)
`````````````````````````````````````````

This controller option utilizes a separately flashed BLE controller image.  This controller image is non-upgradeable and occupies a fixed region of code memory. The use of the fixed BLE image is controlled by CONFIG_USE_ATMWSTK=y and CONFIG_ATMWSTK=<flavor> options.  The default flavor of ATMWSTK is "LL" representing a full controller with both central/peripheral and observer/advertiser role features.

Additional stack flavors may be available in the future with reduced feature sets in order to increase available memory to the user application.  See the section below on DTS flags to partition memory to host the fixed BLE controller image.

Statically linked BLE Link Controller library (ATMWSTKLIB)
``````````````````````````````````````````````````````````

This option statically links a BLE controller library with the application image. This offers the ability to fully upgrade the link controller with the application.  This option is controlled by: CONFIG_USE_ATMWSTK=n and CONFIG_ATMWSTKLIB=<flavor>.  The flavor defaults to "PD50" which is a designation of a peripheral-only device (PD) with a reduced feature set (50).  The PD50 controller offers basic BLE 4.2/5.0 features that can support most peripheral-only applications.  The use of static linkage and reduced feature sets can help reduce the total code memory footprint of the application.

Additional stack flavors may be available in the future that balance feature sets and code size. See section below on DTS flags.


BLE Link Controller Flavors
---------------------------

LL
``


Full controller features less LE Audio. This flavor is selected by the configuration CONFIG_ATMWSTK=LL

Features:

* All roles (central/peripheral/observer/advertiser)
* BLE 4.2 support
* BLE 5.0 support for Extended and Periodic Advertising, including Periodic Sync
* BLE 5.0 support for Data Length extensions, 2M and CODED PHYs
* BLE 5.1 support for CTE (constant tone extensions)
* BLE 5.2 LE Power control
* No ISO (LE Audio) support.


PD50 / PD50LL
`````````````


Compact feature set, peripheral only. This flavor is selected by the configurations CONFIG_ATMWSTKLIB=PD50 or CONFIG_ATMWSTK=PD50LL

Features:

* Peripheral/Advertiser roles only
* BLE 4.2 support
* BLE 5.0 support for Extended Advertising (No Periodic advertising)
* BLE 5.0 support for Data Length extensions, 2M and CODED PHYs
* No BLE 5.1 support for CTE (No AoA/AoD application support).
* No BLE 5.2 LE Power control
* No ISO (LE Audio) support.


DTS Flags
---------


When using the statically linked BLE controller (CONFIG_ATMWSTKLIB) there are no additional DTS settings.  Since the BLE stack is statically linked to the application it will reside in the same memory partition.

When using the fixed BLE controller image (CONFIG_ATMWSTK), the DTSI configuration needs to create a partition to host the ATMWSTK image. This can be reserved using the following DTS flag:

    DTS_EXTRA_CPPFLAGS += -DATMWSTK=LL

When using the "PD50LL" flavor set the following:

    DTS_EXTRA_CPPFLAGS += -DATMWSTK=PD50LL

The partition is sized appropriately for the stack flavor.
