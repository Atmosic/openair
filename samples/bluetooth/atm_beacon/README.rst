.. _atm_beacon-sample:

Bluetooth: atm_beacon
#####################

Overview
********

A configurable beacon application that demonstrates GAP Broadcaster role
functionality by advertising Eddystone URL beacons (pointing to the Atmosic
website). The beacon sample supports multiple profiles with different power
management characteristics and runtime behavior selection via hardware buttons.

The application supports eleven base beacon profiles with optional runtime mode selection:

**Base Profiles (mutually exclusive):**

1. **Power Profile** (``REFBCN_POWER_PROFILE``): Sends 30 scannable beacons at
   1-second intervals, then hibernates for 30 seconds. Optimized for low power
   consumption measurement.

2. **SOC-Off Profile** (``REFBCN_SOCOFF_BEACON``): Advertises for 30 seconds,
   then enters SOC-off mode for 30 seconds.

3. **WURX Beacon Profile** (``REFBCN_WURX_BEACON``): Advertises for 30 seconds,
   then enters hibernation with Wake-Up Receiver (WURX) monitoring enabled.

4. **Simple Harvesting Beacon** (``REFBCN_SIMPLE_HARV_BEACON``): Sends scannable
   beacons continuously at 1-second intervals without hibernation. Device name:
   "Atmosic Harvesting".

5. **Extended Scannable Beacon** (``REFBCN_EXTENDED_SCN``): Sends extended
   scannable advertisements every 500ms. The extended scan response contains an
   Eddystone beacon. Uses retain with voltage drop power mode between beacons.

6. **iBeacon** (``REFBCN_IBEACON``): Apple iBeacon format beacon with
   manufacturer-specific data containing UUID, Major, Minor, and calibrated RSSI.
   Device name: "Atmosic iBeacon".

7. **Extended Advertising Beacon** (``REFBCN_EXTENDED_ADV``): Sends extended
   non-connectable non-scannable advertisements every 500ms with a large

8. **Extended Connectable Beacon** (``REFBCN_EXTENDED_CON``): Sends extended
   connectable non-scannable advertisements every 500ms with a large
   Eddystone URL payload. Uses retain with voltage drop power mode between beacons.

9. **Long Range Coded PHY** (``REFBCN_LR_CODED``): Sends extended scannable
   advertisements on LE Coded PHY for increased range. Uses Eddystone URL format
   with the trade-off of lower data rate and higher power consumption.
   Device name: "ATMxxxx Lowest - Power" (same as POWER_PROFILE and EXTENDED_SCN).

10. **2M Secondary Profile** (``REFBCN_2M_SECONDARY``): Uses Bluetooth 5.0 extended
   advertising with 2M PHY on secondary channel. Sends one extended advertisement
   with a 986-byte payload (Eddystone URL with padding), then hibernates for 1 second
   and repeats. Designed for testing extended advertising maximum payload capability.

11. **Long Range 500kbps Coded PHY** (``REFBCN_LR500_CODED``): Sends extended
    scannable advertisements on LE Coded PHY with S=2 coding for 500kbps data rate.
    Offers higher throughput than S=8 (125kbps) with a trade-off of reduced range.
    Device name: "ATMxxxx Lowest - Power".

**Runtime Mode Selection (optional):**

12. **Simple Beacon Mode** (``REFBCN_SIMPLE_BEACON``): When enabled, allows
   button-controlled runtime selection. If BUTTON_1 is not pressed (or not present),
   uses continuous advertising at 100ms intervals without hibernation. If button
   is pressed, falls back to the configured base profile.

Button Functionality
====================

When ``REFBCN_SIMPLE_BEACON`` is enabled, the application checks the state of
BUTTON_1 at boot time:

- **BUTTON_1 not pressed** (or not present): Uses the Simple Beacon Profile with
  continuous advertising
- **BUTTON_1 pressed**: Uses the configured base profile (Power or SOC-Off)

LED Indication
==============

When using the Simple Beacon mode with power management enabled, LED_1
(if available) toggles each time the system exits from suspend-to-RAM state,
providing visual feedback of power management activity.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/bluetooth/atm_beacon``.

Build command:

For default base power profile:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/atm_beacon --sysbuild -T samples.bluetooth.atm_beacon.atm

For button controlled simple beacon mode along with default base power profile:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/bluetooth/atm_beacon --sysbuild -T samples.bluetooth.atm_beacon.atm.sbcn

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

Look at sample.yaml for additional build targets

Configuration
*************

Beacon Profile Selection
========================

The beacon configuration uses a two-level approach:

**Base Profile (choose one):**

- ``CONFIG_REFBCN_POWER_PROFILE=y`` (default): Enable hibernation beacon demo
- ``CONFIG_REFBCN_SOCOFF_BEACON=y``: Enable SOC-off beacon demo
- ``CONFIG_REFBCN_WURX_BEACON=y``: Enable WURX beacon demo
- ``CONFIG_REFBCN_SIMPLE_HARV_BEACON=y``: Enable simple harvesting beacon demo
- ``CONFIG_REFBCN_EXTENDED_SCN=y``: Enable extended scannable beacon demo
- ``CONFIG_REFBCN_IBEACON=y``: Enable Apple iBeacon demo
- ``CONFIG_REFBCN_EXTENDED_ADV=y``: Enable extended advertising beacon demo
- ``CONFIG_REFBCN_EXTENDED_CON=y``: Enable extended connectable beacon demo
- ``CONFIG_REFBCN_LR_CODED=y``: Enable Long Range coded PHY beacon demo
- ``CONFIG_REFBCN_2M_SECONDARY=y``: Enable 2M PHY extended advertising beacon demo
- ``CONFIG_REFBCN_LR500_CODED=y``: Enable Long Range 500kbps coded PHY beacon demo

**Runtime Mode Selection (optional):**

- ``CONFIG_REFBCN_SIMPLE_BEACON=y``: Enable button-controlled simple beacon mode

The ``REFBCN_SIMPLE_BEACON`` option can be enabled alongside either base profile.
When enabled, BUTTON_1 state at boot determines the runtime behavior:

- BUTTON_1 not pressed (or absent): Use simple beacon (continuous 100ms advertising)
- BUTTON_1 pressed: Use the configured base profile

Advertising Parameters
======================

Key advertising parameters are automatically configured based on the selected profile:

.. list-table:: Profile Advertising Parameters
   :header-rows: 1
   :widths: 20 20 20 20 20

   * - Profile
     - Interval
     - Max Events
     - Duration
     - Power Mode
   * - Power Profile
     - 1000ms
     - 30
     - 30s active, 30s hibernate
     - Hibernate
   * - SOC-Off Profile
     - 1000ms
     - 30
     - 30s active, 30s soc-off
     - SOC-Off
   * - WURX Beacon
     - 1000ms
     - 30
     - 30s active, hibernate until WURX wake
     - Hibernate (WURX)
   * - Simple Harv Beacon
     - 1000ms
     - Unlimited
     - Continuous
     - Active
   * - Simple Beacon
     - 100ms
     - Unlimited
     - Continuous
     - Active
   * - Extended Scannable Beacon
     - 500ms
     - Unlimited
     - Continuous
     - Retain w/ voltage drop
   * - iBeacon
     - 32ms
     - Unlimited
     - Continuous
     - Active
   * - Extended Advertising Beacon
     - 500ms
     - Unlimited
     - Continuous
     - Retain w/ voltage drop
   * - Extended Connectable Beacon
     - 500ms
     - Unlimited
     - Continuous
     - Retain w/ voltage drop
   * - LR Coded PHY
     - 32ms
     - Unlimited
     - Continuous
     - Active
   * - 2M Secondary
     - 1000ms
     - 1
     - 1 event, 1s hibernate cycle
     - Hibernate
   * - LR500 Coded PHY
     - 32ms
     - Unlimited
     - Continuous
     - Active

Hardware Requirements
=====================

For button functionality:

- BUTTON_1 (``button0`` device tree node). In order for the button to work, jumpers JP25 and JP27 need to be installed on the EVK.
- LED_1 (``led0`` device tree node) for power management indication

Both are optional - the application will adapt based on hardware availability.

WURX Beacon Configuration
==========================

The WURX (Wake-Up Receiver) beacon profile enables ultra-low power operation by
entering hibernation with radio wake-up monitoring. The device advertises for a
configurable time, then hibernates until a wake-up signal
is detected.

On platforms without WURX hardware support (i.e., the device tree does not enable
the ``atmosic,wurx`` node), the WURX beacon profile still builds and advertises
the same payload. The device will enter hibernation after advertising completes,
but without WURX wake-up capability. This allows the same beacon configuration
to be used across different hardware platforms.

For detailed WURX documentation, build instructions, and configuration options,
see ``openair/doc/wurx/wurx.rst``.

Energy Harvesting Configuration
===============================

For energy harvesting support with Li-ion battery on a suitable board like
ATMEVK-3430e-YQN-5, additional configuration is required. The battery management
functionality is only enabled when both Li-ion battery type is configured AND
harvesting is enabled.

**Required Configuration in boards/ATMEVK-3430e-YQN-5.conf:**

.. code-block:: kconfig

   # Battery monitoring support
   CONFIG_BATT_MODEL_HSC_LIION=y
   CONFIG_ADC=y
   CONFIG_RETAINED_MEM=y
   CONFIG_RETAINED_MEM_ATM_HIB=y

**Required Device Tree Configuration in boards/ATMEVK-3430e-YQN-5.overlay:**

.. code-block:: devicetree

   &pmu {
       batt-type = <0>;
       hsc-mode;
       batt-level = <1>;
       vddio-type = <0>;
       vstore-max = <3300>;
       vddpa-src = <0>;
       nonrf-harv;
       vharv-range = <13>;
       boost-from-vharv-inductor;
       vharv-ul;
       dig-test-out-pin = <8>;
   };

   &adc {
       channel@b {
           reg = <11>;
           zephyr,gain = "ADC_GAIN_1_2";
           zephyr,reference = "ADC_REF_INTERNAL";
           zephyr,acquisition-time = <ADC_ACQ_TIME_DEFAULT>;
           zephyr,resolution = <16>;
       };
   };

Testing
*******

To verify beacon functionality:

1. Use a Bluetooth scanner app on a mobile device
2. Look for device names in the scan list:

   .. list-table::
      :header-rows: 1
      :widths: 40 30 30

      * - Profile
        - Complete Name
        - Shortened Name
      * - Power Profile
        - ATMxxxx Lowest - Power
        - A0000c9
      * - Extended Scannable
        - ATMxxxx Lowest - Power
        - (none)
      * - Extended Advertising
        - ATMxxxx Lowest - Power
        - (none)
      * - Extended Connectable
        - ATMxxxx Lowest - Power
        - (none)
      * - Long Range Coded
        - ATMxxxx Lowest - Power
        - (none)
      * - Long Range 500kbps Coded
        - ATMxxxx Lowest - Power
        - (none)
      * - 2M Secondary
        - ATMxxxx Lowest - Power
        - (none)
      * - SOC-Off / WuRx / Simple Beacon
        - Atmosic Beacon
        - Atmosic
      * - Simple Harvesting
        - Atmosic Harvesting
        - Atmosic
      * - iBeacon
        - Atmosic iBeacon
        - (none)

3. The beacon should be scannable and contain Eddystone URL data pointing to http://www.atmosic.com (or iBeacon manufacturer data)
4. For power profiles, observe the 30-second on/off cycles
5. For simple beacon and simple harvesting beacon, advertising should be continuous
