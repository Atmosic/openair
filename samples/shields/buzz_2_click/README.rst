.. _buzz-2-click-sample:

Buzz 2 Click
############

Overview
********

This sample application demonstrates how to use the Buzz 2 Click buzzer shield with the Atmosic ATMBTCSTAG-3405 development board. The Buzz 2 Click is a MikroElektronika Click board that features a PWM-driven buzzer for generating audio tones.

The Buzz 2 Click features a piezoelectric buzzer driven by a PWM signal, allowing the ATM3405 SoC to generate sound signals such as beeps, tones, and alerts. It communicates with the MCU through a PWM pin and can produce a wide range of audible frequencies depending on the configured duty cycle and period.

By default, the Buzz 2 Click board’s VCCIO SEL resistor is set for 5 V operation.

If the external 5 V input described in Section 3.1 is not available, the resistor must be switched to the 3.3 V position to ensure proper buzzer operation.

Product page URL: https://www.mikroe.com/buzz-2-click

Key features of this sample include:

* **PWM-Based Buzzer Control**: Uses the Atmosic PWM buzzer driver to generate tones
* **Continuous Frequency Loop**: Cycles through low, medium, and high frequencies continuously
* **Automatic Timing Control**: Uses ``atm_buzzer_beep_time()`` for precise timing control
* **Easy-to-Use API**: Demonstrates the ``atm_buzzer_beep_time()`` function from the ``atm_buzzer`` driver
* **Configurable Parameters**: Shows how to adjust frequency, duty cycle, and timing
* **Timeout Functionality**: Requires ``CONFIG_ATM_BUZZER_TIMEOUT`` for automatic buzzer stop

The sample runs a continuous loop that plays three musical notes in sequence: C3 (131 Hz) for 300ms, C4 (262 Hz) for 200ms, and E5 (659 Hz) for 100ms, with automatic stops and pauses between each beep. This provides a simple demonstration of the buzzer's frequency range and precise timing capabilities.

Requirements
************

* Atmosic ATMBTCSTAG-3405 Tag Reference Design (with IoT expansion board)
* Buzz 2 Click buzzer shield (MikroElektronika) installed on the ATMBTCSTAG-3405's mikroBUS connector

Power Supply Selection
**********************

By default, the Buzz 2 Click board’s VCCIO SEL resistor is set for 5 V operation.

If the external 5 V input is not available, the resistor must be switched to the 3.3 V position to ensure proper buzzer operation.

Building and Running
********************

This sample can be found under ``openair/samples/shields/buzz_2_click``.

Build command:

.. code-block:: bash

   west build -p always -b ATMBTCSTAG-3405 openair/samples/shields/buzz_2_click --sysbuild -T samples.shields.buzz_2_click.atm

Flash the application:

.. code-block:: bash

   west flash --skip-rebuild --verify --dl --device <DEVICE_ID> --fast_load

Sample Output
*************

When the Buzz 2 Click shield is connected and the application is running, the console output shows:

.. code-block:: console

   *** Booting Zephyr OS build v3.x.x ***
   [00:00:00.006,000] <inf> buzz_2_click: Buzz 2 Click Sample - PWM Buzzer Demo
   [00:00:00.006,000] <inf> buzz_2_click: Buzzer PWM period: 1000000 ns, pulse: 500000 ns
   [00:00:00.006,000] <inf> buzz_2_click: Frequency range: 123 Hz - 8000000 Hz
   [00:00:00.006,000] <inf> buzz_2_click: PWM device ready: pwm@14604c
   [00:00:00.006,000] <inf> buzz_2_click: Buzzer timeout functionality initialized
   [00:00:00.006,000] <inf> buzz_2_click: Starting continuous frequency loop...

   [00:00:28.817,000] <inf> buzz_2_click: Playing C3 frequency: 131 Hz for 300 ms
   [00:00:29.317,000] <inf> buzz_2_click: Playing C4 frequency: 262 Hz for 200 ms
   [00:00:29.718,000] <inf> buzz_2_click: Playing E5 frequency: 659 Hz for 100 ms
   [00:00:30.018,000] <inf> buzz_2_click: Melody complete. Pausing before repeat...
   [00:00:32.018,000] <inf> buzz_2_click: Playing C3 frequency: 131 Hz for 300 ms
   [00:00:32.518,000] <inf> buzz_2_click: Playing C4 frequency: 262 Hz for 200 ms
   [00:00:32.919,000] <inf> buzz_2_click: Playing E5 frequency: 659 Hz for 100 ms
   [00:00:33.219,000] <inf> buzz_2_click: Melody complete. Pausing before repeat...
   ...

The sample runs a continuous loop that cycles through three musical notes: C3 (131 Hz) for 300ms, C4 (262 Hz) for 200ms, and E5 (659 Hz) for 100ms. Each beep plays for its specified duration followed by a 200ms pause before the next note. After completing the sequence, there is a 2-second pause before repeating. The loop continues indefinitely, demonstrating the ``atm_buzzer_beep_time()`` function's precise automatic timing control.

Customization
*************

You can easily customize the sample to use different musical notes or timing:

**Change the musical notes:**

Modify the ``frequencies[]`` array in ``main.c`` to use different musical notes. Available note constants are defined in ``atm_buzzer.h`` (e.g., ``NOTE_C3`` through ``NOTE_B7``).

**Adjust timing:**

* ``durations[]`` array: Individual duration for each note (current: 300ms, 200ms, 100ms)
* ``PAUSE_DURATION_MS``: Pause between notes (default: 200ms)
* ``DUTY_CYCLE``: PWM duty cycle percentage (default: 50%)

**Play a single musical note:**

.. code-block:: c

   /* Play a single note using atm_buzzer_beep_time() */
   atm_buzzer_beep_time(&buzzer_cfg, NOTE_A4, 50, 1000); /* Play A4 (440 Hz) for 1000ms */
   k_msleep(1000 + 200); /* Wait for note duration plus pause */

**Use the atm_buzzer_beep_time() function:**

The sample demonstrates the recommended approach for timed musical notes:

.. code-block:: c

   /* atm_buzzer_beep_time() - automatic timeout (requires CONFIG_ATM_BUZZER_TIMEOUT=y) */
   atm_buzzer_beep_time(&buzzer_cfg, NOTE_C4, 50, 500); /* Play C4 (262 Hz) for 500ms then auto-stop */
   k_msleep(500 + 200); /* Wait for note duration plus pause */

API Reference
*************

The sample primarily uses the following ``atm_buzzer`` driver function:

* ``atm_buzzer_beep_time()``: Play a tone for a specific duration with automatic timeout

The sample demonstrates automatic timeout functionality using ``atm_buzzer_beep_time()``. This function requires the timeout feature to be enabled with ``CONFIG_ATM_BUZZER_TIMEOUT``.

References
**********

For more detailed information on the Buzz 2 Click, refer to the MikroElektronika official documentation:

* `Buzz 2 Click <https://www.mikroe.com/buzz-2-click>`_
