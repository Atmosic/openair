.. _multimode_consumer_tag_atmbtcstag_3405:

Multimode Consumer Tag on ATMBTCSTAG-3405
#########################################

Overview
********

This document supplements the main :ref:`multimode_consumer_tag-application`
README and describes **only** the user-visible behaviors that are specific to
the **ATMBTCSTAG-3405** board (the ATM3405 Tag, Board A of the
:ref:`atmbtcstag-iot-3405-applications` reference design).

These behaviors are enabled by the board overlay file
``boards/ATMBTCSTAG-3405.conf``, which sets the following Kconfig options on
top of the application defaults:

- ``CONFIG_TAG_BTN_POWER_CTRL``
- ``CONFIG_TAG_BTN_FACTORY_RESET``
- ``CONFIG_TAG_BTN_BATT_REPORT``
- ``CONFIG_TAG_LED_IND``
- ``CONFIG_TAG_AUDIO_FEEDBACK``

.. note::

   For all behaviors that are **not** specific to ATMBTCSTAG-3405 (FMNA / FHN /
   STF protocol behavior, AT command interface, OTA tap-count, FMNA SN lookup,
   MFi token logging, build target list, storage configuration, etc.), refer
   back to the main :ref:`multimode_consumer_tag-application` README.

Hardware
********

ATMBTCSTAG-3405 only exposes a single user button and routes LED / buzzer
output to dedicated GPIOs / PWM channels:

.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Resource
     - Mapping
   * - Button1 (only user button)
     - GPIO0_5 (alias ``sw0``); also the only pin able to wake the device from SOC OFF.
   * - Status Green LED (LED1 G)
     - GPIO1_14
   * - Status Red LED (LED1 R)
     - GPIO0_6
   * - Battery Green LED (LED2 G)
     - GPIO0_7
   * - Buzzer (PWM)
     - PWM1 channel 1 (P25), aliased as ``tag-pwm``

.. important::

   Because the board only has **one** physical button, every reference to
   "Button2" in the main README maps to **Button1** on ATMBTCSTAG-3405.
   The default "long-press Button2 during reboot to unpair" gesture from the
   main README is **replaced** by the power / factory-reset MMI described
   below.

Button Behavior
***************

Power On / Off (``CONFIG_TAG_BTN_POWER_CTRL``)
==============================================

- **Power on**: With the device powered off, long-press Button1 for **2 s**.
  The Green LED blinks 3 times to indicate power-on completion.
- **Power off**: While the device is in operation, long-press Button1 for
  **2 s**. The Red LED blinks 3 times to indicate power-off, and the device
  enters SOC OFF.
- **Pairing-mode timeout**: If the device stays in pairing mode for
  ``CONFIG_TAG_SOC_OFF_TIMEOUT`` seconds (default ``180`` s = 3 min) without
  being paired, the Red LED blinks 3 times and the device enters SOC OFF
  automatically.

Factory Reset (``CONFIG_TAG_BTN_FACTORY_RESET``)
================================================

- Continuing to hold Button1 past the 2 s power-off threshold up to **10 s**
  triggers a factory reset, then the device enters SOC OFF.
- During the factory reset, audio feedback is played (see
  :ref:`multimode_consumer_tag_atmbtcstag_3405_audio_feedback` below) and the
  LED indicates the factory-reset pattern.

.. _multimode_consumer_tag_atmbtcstag_3405_batt_report:

Battery Level Report (``CONFIG_TAG_BTN_BATT_REPORT``)
=====================================================

Quick-press Button1 **5 times** to display the current battery level via the
Battery Green LED:

.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Battery level
     - LED pattern
   * - > 90%
     - 5 GREEN blinks
   * - > 60%
     - 4 GREEN blinks
   * - > 30%
     - 3 GREEN blinks
   * - > 10%
     - 2 GREEN blinks
   * - <= 10%
     - 1 GREEN blink

LED Indication (``CONFIG_TAG_LED_IND``)
***************************************

The board uses the dedicated status LEDs to reflect the device state and
button events:

.. list-table::
   :header-rows: 1
   :widths: 35 65

   * - State / Event
     - LED pattern
   * - Power on
     - Green LED blinks 3 times (250 ms on / 250 ms off)
   * - Power off / pairing-mode timeout
     - Red LED blinks 3 times (250 ms on / 250 ms off)
   * - Pairing mode
     - Green blink -> Red blink, repeating every 5 s
   * - Operation mode (paired)
     - Green LED blinks every 20 s
   * - OTA mode
     - Red LED blinks every 1 s (100 ms on / 900 ms off)
   * - Battery report
     - Battery Green LED blinks N times (see
       :ref:`multimode_consumer_tag_atmbtcstag_3405_batt_report`)

.. _multimode_consumer_tag_atmbtcstag_3405_audio_feedback:

Audio Feedback (``CONFIG_TAG_AUDIO_FEEDBACK``)
**********************************************

When a factory reset is triggered (Button1 held >= 10 s), the PWM buzzer
plays a tone for **1 s** before the reset is performed. The buzzer is driven
by ``CONFIG_ATM_BUZZER`` through the ``tag-pwm`` device tree alias defined in
``boards/ATMBTCSTAG-3405.overlay``.

Behaviors Inherited From the Main README
****************************************

The following behaviors are **not** board-specific and apply unchanged on
ATMBTCSTAG-3405. Refer to the main :ref:`multimode_consumer_tag-application`
README for details:

- FMNA / FHN / STF protocol-specific button gestures (FP discoverable
  advertising, Play Sound stop, UTP enable, STF onboarding).
- FMNA SN lookup enable (Button1 short-press 6 times).
- MFi token logging (Button1 short-press 8 times).
- OTA mode entry (Button1 short-press 10 times) and OTA mode behavior.
- AT command interface (when ``CONFIG_AT_CMD_TAG_SET=y``).
- Build target list, sysbuild instructions and storage size configuration.
