.. _beacon-sample:

Bluetooth: beacon
#################

Overview
********

A configurable beacon application that demonstrates GAP Broadcaster role
functionality by advertising Eddystone URL beacons (pointing to the Atmosic
website). The beacon sample supports multiple profiles with different power
management characteristics and runtime behavior selection via hardware buttons.

The application supports two base beacon profiles with optional runtime mode selection:

**Base Profiles (mutually exclusive):**

1. **Power Profile** (``REFBCN_POWER_PROFILE``): Sends 30 scannable beacons at
   1-second intervals, then hibernates for 30 seconds. Optimized for low power
   consumption measurement.

2. **SOC-Off Profile** (``REFBCN_SOCOFF_BEACON``): Advertises for 30 seconds,
   then enters SOC-off mode for 30 seconds.

**Runtime Mode Selection (optional):**

3. **Simple Beacon Mode** (``REFBCN_SIMPLE_BEACON``): When enabled, allows
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

This sample is built from ``openair/samples/bluetooth/beacon``.

Build command:

.. code-block:: bash

   west build -p always -b <board>//ns openair/samples/bluetooth/beacon --sysbuild -T samples.bluetooth.beacon.atm

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <serial> --jlink --fast_load [--erase_flash]

Configuration
*************

Beacon Profile Selection
========================

The beacon configuration uses a two-level approach:

**Base Profile (choose one):**

- ``CONFIG_REFBCN_POWER_PROFILE=y`` (default): Enable hibernation beacon demo
- ``CONFIG_REFBCN_SOCOFF_BEACON=y``: Enable SOC-off beacon demo

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
   * - Simple Beacon
     - 100ms
     - Unlimited
     - Continuous
     - Active

Hardware Requirements
=====================

For button functionality:

- BUTTON_1 (``button0`` device tree node). In order for the button to work, jumpers JP25 and JP27 need to be installed on the EVK.
- LED_1 (``led0`` device tree node) for power management indication

Both are optional - the application will adapt based on hardware availability.

Energy Harvesting Configuration
===============================

For energy harvesting support with Li-ion battery on a suitable board like
ATMEVK-3430e-YQN-5, additional configuration is required. The battery management
functionality is only enabled when both Li-ion battery type is configured AND
harvesting is enabled.

**Required Configuration in boards/ATMEVK-3430e-YQN-5_ns.conf:**

.. code-block:: kconfig

   # Battery monitoring support
   CONFIG_BATT_MODEL_HSC_LIION=y
   CONFIG_BATT_MODEL_HSC=y
   CONFIG_ADC=y
   CONFIG_RETAINED_MEM=y
   CONFIG_RETAINED_MEM_ATM_HIB=y

**Required Device Tree Configuration in boards/ATMEVK-3430e-YQN-5_ns.overlay:**

.. code-block:: devicetree

   &pmu {
       batt-type = <0>;
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
2. Look for "Atmosic" or "A0000c9" in the device list
3. The beacon should be scannable and contain Eddystone URL data pointing to http://www.atmosic.com
4. For power profiles, observe the 30-second on/off cycles
5. For simple beacon, advertising should be continuous
