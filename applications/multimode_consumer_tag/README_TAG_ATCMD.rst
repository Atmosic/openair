.. _tag_atcmd_guide:

================================================
Tag AT Command Guide
================================================

Tag-related AT commands for UART control and status queries. Supports FMNA, FHN, and STF modes.

Build Command
=============

Use sysbuild to enable AT command support:

.. code-block:: bash

   west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
       -T applications.multimode_consumer_tag.atm.mcuboot.flash_xip.at_cmd

Configuration
==============

.. code-block:: kconfig

   CONFIG_ATM_AT_CMD=y
   CONFIG_AT_CMD_SET=y
   CONFIG_AT_CMD_TAG_SET=y
   CONFIG_FAST_PAIR_FMDN_V2=y

Commands
========

**Device:** ``AT+TAGINFO`` ``AT+TAGMODE`` ``AT+TAGADDR``

**Control:** ``AT+TAGSTART`` ``AT+TAGRESET`` ``AT+TAGBATTERY``

**FHN:** ``AT+TAGGFPIND``

**FMNA:** ``AT+TAGFMNASN`` ``AT+TAGFMNAMFI``

**Sensor/Protocol:** ``AT+TAGMOTIONRPT`` ``AT+TAGSTFIND`` ``AT+TAGCSUNPAIR``

Events
======

**State:** ``+EVTTAGSTATE`` — Tag state machine transitions

**Control:** ``+EVTTAGMOTIONCTL`` — Motion detection enable/disable

**Audio:** ``+EVTTAGBUZZER`` — Buzzer action notification

**GFP:** ``+EVTTAGGFPREVERSERING`` — Reverse ringing status

**Error:** ``+EVTTAGERROR`` — Tag error notification

Usage Flow
==========

**1. Initialize & Configure**

Tag Modes: 0x01 (FMNA), 0x02 (FHN), 0x04 (STF), 0x07 (all)

.. code-block:: text

   AT+TAGINFO?
   +TAGINFO:1.0.0,7
   OK

   AT+TAGMODE=7
   OK
   AT+TAGMODE?
   +TAGMODE:7
   OK

**2. Operate**

.. warning::

   AT+TAGSTART=1 blocks set/exec: AT+TAGMODE=x

   Query allowed: AT+TAGINFO?, AT+TAGMODE?, AT+TAGBATTERY?

   Exec allowed: AT+TAGRESET, AT+TAGFMNASN, AT+TAGMOTIONRPT, etc.

.. code-block:: text

   AT+TAGBATTERY?
   +TAGBATTERY:85
   OK

   AT+TAGSTART=1
   OK
   +EVTTAGSTATE:7,1

   [Waiting for phone to connect...]

   +EVTTAGSTATE:7,4

**3. Events**

Tag Events Explanation and Examples:

Events are asynchronous notifications sent by the tag to the host without solicitation.
They indicate state changes, errors, or actions that require host handling.

.. code-block:: text

   1. State Transition Event
   +EVTTAGSTATE:7,1
      ↓ Tag initialized and ready (protocol=7, state=INIT_DONE), sent automatically after AT+TAGSTART=1

   2. Motion Detection Enabled Event
   +EVTTAGMOTIONCTL:1
      ↓ Host should start reporting motion data if available

   3. Host Sends Motion Data (Host-Initiated)
   AT+TAGMOTIONRPT=100,200,300
   OK
      ↓ Host reports XYZ acceleration values (cm/s²) to tag

   4. Buzzer Action Event (Tag-Initiated)
   +EVTTAGBUZZER:0x50,5,100
      ↓ Host must handle buzzer:
        - evt=0x50 (buzzer action type)
        - ring_vol=5 (volume level)
        - duration_ds=100 (100 deciseconds = 10 seconds)

Event Reference:

**+EVTTAGSTATE** — Tag State Transitions

   ``Format: +EVTTAGSTATE:<protocol>,<state>``

   ``<protocol>`` is the active protocol bitmask (same as ``AT+TAGMODE``).

   - ``0`` — BOOTED
   - ``1`` — INIT_DONE
   - ``2`` — UNPAIRED
   - ``3`` — PAIRING
   - ``4`` — PAIRED

**+EVTTAGERROR** — Tag Error Notification

   ``Format: +EVTTAGERROR:<protocol>,<error_code>``

   ``<protocol>`` is the protocol that triggered the error.

**+EVTTAGBUZZER** — Buzzer Action

   ``Format: +EVTTAGBUZZER:<evt>,<ring_vol>,<duration_ds>``

   Host handles buzzer when ``CONFIG_TAG_BUZZER=n``

**+EVTTAGMOTIONCTL** — Motion Detection Control

   ``Format: +EVTTAGMOTIONCTL:<enable>``

   - ``0`` — disabled
   - ``1`` — enabled

**+EVTTAGGFPREVERSERING** — GFP Reverse Ringing Status

   ``Format: +EVTTAGGFPREVERSERING:<evt>``

   - ``0`` — CONNECTED (phone ringing; Seeker connected via RR advertisement)
   - ``1`` — STARTED (phone confirmed ringing started via GATT)
   - ``2`` — STOPPED (phone stopped ringing; any reason)
   - ``3`` — ADV_STARTED (tag advertising for adv-based reverse ringing; no connection yet)
   - ``4`` — ADV_TIMEOUT (ADV window expired; phone never connected, never rang)
   - ``5`` — PHONE_FAILED (phone reported it could not start ringing)
   - ``6`` — TIMEOUT_LOCAL (provider-side ringing timeout after seeker connected)
   - ``7`` — PHONE_TIMEOUT (phone's own ring session timed out)
   - ``8`` — START_CONFIRMED (START indication ACKed; persistent path fast feedback)
   - ``9`` — STOP_CONFIRMED (STOP indication ACKed; persistent path fast feedback)
   - ``10`` — PHONE_STOPPED_DISCONNECTED (BLE connection dropped while phone was ringing)
   - ``11`` — PHONE_START_TIMEOUT (persistent path 60s timeout after START indication)

**4. Device Firmware Upgrade (DFU) via AT Command**

.. note::

   **IMPORTANT**: AT command DFU and the tag AT command layer share the same UART.
   During DFU, the UART is exclusively used for binary RDP (Raw Data Protocol) packet streaming,
   so **no TAG AT events will be received** until DFU is complete and the device reboots.

   **Recommended**: Before initiating DFU, execute::

      AT+TAGRESET=0

   This cold reboot clears the AT command state and ensures the UART is in a clean state
   for DFU. This is strongly recommended to avoid potential state conflicts, though not strictly required.

Serial firmware upgrade using RDP (Raw Data Protocol) binary framing:

.. code-block:: text

   Step 1: (Recommended) Clean AT Command State with Cold Reboot
   AT+TAGRESET=0
   OK
   [Device performs cold reboot, AT command layer restarts in clean state]
   [No events will be received until DFU completes]

   Step 2: Initiate DFU
   AT+SYSDFU=0,131072,0
   OK
   [Device enters binary-receive mode, UART now exclusive to DFU]

   <Binary RDP packet stream follows>
   [Host streams firmware image data as RDP packets]
   [Tag events are NOT received during DFU]

   Step 3: Apply Staged Firmware and Reboot
   AT+SYSSWITCHBANK=
   OK
   [Device applies new firmware and reboots]
   [Tag events resume after boot]

   Step 4: Confirm New Image
   AT+SYSMKBANKGOOD=
   OK
   [Firmware confirmed as permanent]

For detailed DFU protocol specifications and command formats, see the
:ref:`sys_dfu_command_reference`.

Implementation Details
======================

**Command Dependencies**

This application supports the following tag AT commands when configured appropriately:

- **Universal Commands** (always available with ``CONFIG_AT_CMD_TAG_SET=y``):
  - ``AT+TAGINFO`` — Returns application version and enabled protocols
  - ``AT+TAGMODE`` — Manages protocol selection (FMNA, FHN, STF)
  - ``AT+TAGADDR`` — Returns advertising BT address for a given protocol
  - ``AT+TAGSTART`` — Initiates tag BLE stack
  - ``AT+TAGRESET`` — Performs cold reboot or factory reset
  - ``AT+TAGBATTERY`` — Queries battery status
  - ``AT+TAGMOTIONRPT`` — Accepts host acceleration data

- **Protocol-Specific Commands**:
  - ``AT+TAGSTFIND`` — STF button simulation (requires ``CONFIG_STF_TAG``)
  - ``AT+TAGFMNASN``, ``AT+TAGFMNAMFI`` — FMNA operations (requires ``CONFIG_FMNA_TAG``)
  - ``AT+TAGGFPIND`` — GFP button simulation (requires ``CONFIG_FHN_TAG`` or ``CONFIG_FMDN_REVERSE_RINGING``)
  - ``AT+TAGCSUNPAIR`` — Channel Sounding unpair (requires ``CONFIG_ATM_CS``)

See :ref:`at_cmd_tag` for the complete command reference and error codes.

**Event Handling**

Events are asynchronous notifications sent by the tag when state changes occur:

- ``+EVTTAGSTATE`` — Tag state machine transitions (boot, init, unpaired, pairing, paired)
- ``+EVTTAGMOTIONCTL`` — Motion detection enabled/disabled
- ``+EVTTAGBUZZER`` — Buzzer action required (when ``CONFIG_TAG_BUZZER=n``)
- ``+EVTTAGGFPREVERSERING`` — GFP reverse ringing status changes (0=CONNECTED, 1=STARTED, 2=STOPPED, 3=ADV_STARTED, 4=ADV_TIMEOUT, 5=PHONE_FAILED, 6=TIMEOUT_LOCAL, 7=PHONE_TIMEOUT, 8=START_CONFIRMED, 9=STOP_CONFIRMED, 10=PHONE_STOPPED_DISCONNECTED, 11=PHONE_START_TIMEOUT)
- ``+EVTTAGERROR`` — Tag-side error notifications

**Firmware Updates**

For serial firmware updates via AT commands, use ``AT+SYSDFU``:

.. code-block:: text

   AT+TAGRESET=0
   OK
   AT+SYSDFU=0,<firmware_size>,0
   OK
   [Binary RDP packet stream follows]

See :ref:`sys_dfu_command_reference` for details.

References
==========
* ``README.rst``
* ``README_FHN_RANGING_OOB.rst``
* :ref:`at_cmd_tag` — System-level AT Command Tag reference
* :ref:`sys_dfu_command_reference` — Serial DFU Commands
