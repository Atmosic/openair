.. _ras_rrsp_reflector_atmbtcstag_3405:

Channel Sounding Reflector on ATMBTCSTAG-3405
#############################################

Overview
********

This document describes the button behavior specific to the
**ATMBTCSTAG-3405** board when it is running the
``ras_rrsp_reflector`` application.

The board has one user button, Button1. The board-specific configuration enables
button power control and factory reset. The default Button2 unpair behavior
described in the main reflector README does not apply to this board.

Button Behavior
***************

Power On / Off
==============

- When the reflector is powered off, long-press Button1 for **2 seconds** to
  power it on.
- When the reflector is operating, long-press Button1 for **2 seconds** to
  power it off and enter the low-power off state.

Factory Reset
=============

To factory-reset and unpair the reflector, continue holding Button1 after the
2-second power-off action until the button has been held for **10 seconds**.
The reflector clears its Bluetooth pairing information and remains powered off.

Battery Level Report
********************

Quick-press Button1 **5 times** within 3 seconds to display the battery level
using the Battery Green LED:

.. list-table::
   :header-rows: 1
   :widths: 35 65

   * - Battery voltage
     - LED indication
   * - > 3.0 V
     - 5 GREEN blinks
   * - > 2.9 V
     - 4 GREEN blinks
   * - > 2.8 V
     - 3 GREEN blinks
   * - > 2.6 V
     - 2 GREEN blinks
   * - <= 2.6 V
     - 1 GREEN blink

LED Indication
**************

The board uses status LEDs to indicate the reflector state and button events:

.. list-table::
   :header-rows: 1
   :widths: 35 65

   * - State / Event
     - LED indication
   * - Power on
     - Green LED blinks 3 times
   * - Power off
     - Red LED blinks 3 times
   * - Pairing mode
     - Green blink followed by red blink, repeating every 5 seconds
   * - Operation mode
     - Green LED blinks every 20 seconds
   * - Channel Sounding operation
     - Green LED blinks every 1 second
   * - Battery level report
     - Battery Green LED blinks according to the battery level table above

Audio Feedback
**************

When a factory reset is triggered (Button1 held >= 10 s), the PWM buzzer
plays a tone for **1 s** before the reset is performed.