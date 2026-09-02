.. _at_cmd_tag:

Tag Commands and Events
#######################

See :ref:`at_cmd_format` for command syntax.

Tag commands require ``CONFIG_AT_CMD_TAG_SET=y`` and one of the underlying tag protocol
backends (``CONFIG_STF_TAG``, ``CONFIG_FMNA_TAG``, ``CONFIG_FHN_TAG``) or ``CONFIG_ATM_AT_CMDTEST`` for test builds.

Command Dependencies
====================

The following table shows which tag protocol or configuration each command depends on:

.. list-table::
   :header-rows: 1
   :widths: 20 60 20

   * - Command
     - Description
     - Requires
   * - ``AT+TAGINFO``
     - Query tag information (version, protocols)
     - ``CONFIG_AT_CMD_TAGINFO`` (default)
   * - ``AT+TAGMODE``
     - Select/query active tag protocols
     - ``CONFIG_AT_CMD_TAGMODE`` (default)
   * - ``AT+TAGSTART``
     - Start tag BLE stack
     - ``CONFIG_AT_CMD_TAGSTART`` (default)
   * - ``AT+TAGBATTERY``
     - Query battery level
     - ``CONFIG_AT_CMD_TAGBATTERY`` (default)
   * - ``AT+TAGRESET``
     - Cold reboot or factory reset
     - ``CONFIG_AT_CMD_TAGRESET`` (default)
   * - ``AT+TAGSTFIND``
     - Simulate STF button press
     - ``CONFIG_AT_CMD_TAGSTFIND``, ``CONFIG_STF_TAG``
   * - ``AT+TAGFMNASN``
     - Enable FMNA SN lookup window (5 min)
     - ``CONFIG_AT_CMD_TAGFMNASN``, ``CONFIG_FMNA_TAG``
   * - ``AT+TAGFMNAMFI``
     - Query/log FMNA MFI token
     - ``CONFIG_AT_CMD_TAGFMNAMFI``, ``CONFIG_FMNA_TAG``
   * - ``AT+TAGCSUNPAIR``
     - Unpair Channel Sounding peer
     - ``CONFIG_AT_CMD_TAGCSUNPAIR``, ``CONFIG_ATM_CS``
   * - ``AT+TAGGFPIND``
     - Simulate GFP button press (single/double)
     - ``CONFIG_AT_CMD_TAGGFPIND``, (``CONFIG_FHN_TAG`` or ``CONFIG_FMDN_REVERSE_RINGING``)
   * - ``AT+TAGMOTIONRPT``
     - Report XYZ acceleration from host
     - ``CONFIG_AT_CMD_TAGMOTIONRPT`` (default)
   * - ``AT+TAGADDR``
     - Query advertising BT address for a given protocol
     - ``CONFIG_AT_CMD_TAGADDR`` (default)

AT+TAGINFO — Tag Information
****************************

:Kconfig:   ``CONFIG_AT_CMD_TAGINFO``
:Execute:   not supported
:Query:     ``AT+TAGINFO?``
:Response:  ``+TAGINFO:<fw_version>,<protocols_bitmap>``

``protocols_bitmap`` is the OR of compiled-in tag protocols (bit 0 = FMNA, bit 1 = FHN, bit 2 = STF).

.. code-block:: text

   AT+TAGINFO?
   +TAGINFO:1.0.0,7
   OK

AT+TAGMODE — Tag Mode Select / Query
************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGMODE``
:Execute:   ``AT+TAGMODE=<mode_bitmap>``
:Query:     ``AT+TAGMODE?``
:Response:  ``+TAGMODE:<active_bitmap>``

Selects which tag protocols are active. ``<mode_bitmap>`` is a bitmask (range 1–7):

- ``0x01`` — FMNA
- ``0x02`` — FHN
- ``0x04`` — STF
- ``0x07`` — all protocols

.. code-block:: text

   AT+TAGMODE=1
   OK
   AT+TAGMODE?
   +TAGMODE:1
   OK

AT+TAGBATTERY — Battery Level
*****************************

:Kconfig:   ``CONFIG_AT_CMD_TAGBATTERY``
:Execute:   not supported
:Query:     ``AT+TAGBATTERY?``
:Response:  ``+TAGBATTERY:<percent>``

.. code-block:: text

   AT+TAGBATTERY?
   +TAGBATTERY:87
   OK

AT+TAGSTART — Start Tag BLE Stack
*********************************

:Kconfig:   ``CONFIG_AT_CMD_TAGSTART``
:Execute:   ``AT+TAGSTART=<1: start>`` — only valid value is ``1``
:Query:     not supported

Brings up the tag BLE stack using the currently selected ``AT+TAGMODE``. State transitions
are reported via ``+EVTTAGSTATE``.

.. code-block:: text

   AT+TAGSTART=1
   OK
   +EVTTAGSTATE:7,1

AT+TAGRESET — Reboot / Factory Reset
************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGRESET``
:Execute:   ``AT+TAGRESET=<type>`` — ``0`` = cold reboot, ``1`` = factory reset
:Query:     not supported

Factory reset clears all paired-owner data before rebooting.

.. code-block:: text

   AT+TAGRESET=1
   OK

AT+TAGSTFIND — STF Button Simulation
************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGSTFIND``
:Depends:   ``CONFIG_STF_TAG`` || ``CONFIG_ATM_AT_CMDTEST``
:Execute:   ``AT+TAGSTFIND=1`` — only valid value is ``1``
:Query:     not supported

Simulates a Samsung Find (STF) single button press. Behavior depends on current state:

- **If tag is ringing**: stops the ring immediately (priority). No further action taken.
- **If tag is not ringing**: confirms STF pairing (OOB onboarding).

.. code-block:: text

   AT+TAGSTFIND=1
   OK

AT+TAGFMNASN — FMNA Serial Number Lookup
*******************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGFMNASN`` (requires ``FMNA_TAG``)
:Execute:   ``AT+TAGFMNASN=<value>`` — enable 5-minute SN readout window (only ``1`` is valid)
:Query:     not supported

Enables a 5-minute window for FMNA paired-owner serial number readout.
Required by Apple FindMy certification test #8. After 5 minutes,
SN encryption is automatically re-enabled.

.. code-block:: text

   AT+TAGFMNASN=1
   OK

AT+TAGFMNAMFI — FMNA MFI Token Log
***********************************

:Kconfig:   ``CONFIG_AT_CMD_TAGFMNAMFI`` (requires ``FMNA_TAG``)
:Execute:   not supported
:Query:     ``AT+TAGFMNAMFI?`` — log/query current MFI token

Logs and displays the current FMNA MFI token for debugging purposes.

.. code-block:: text

   AT+TAGFMNAMFI?
   OK

AT+TAGCSUNPAIR — Channel Sounding Unpair
*****************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGCSUNPAIR`` (requires ``ATM_CS``)
:Execute:   ``AT+TAGCSUNPAIR=`` — trigger unpair (no parameters)
:Query:     not supported

Unpairs the tag from Channel Sounding (CS) service, clearing paired device info.

.. code-block:: text

   AT+TAGCSUNPAIR=
   OK

AT+TAGGFPIND — GFP Button Simulation
*************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGGFPIND`` (requires ``FHN_TAG`` or ``FMDN_REVERSE_RINGING``)
:Execute:   ``AT+TAGGFPIND=<action>`` — ``1`` = single press, ``2`` = double press
:Query:     not supported

Simulates a FHN (Google Find Hub Network) button press event. Used when ``CONFIG_TAG_BUTTON=n``.
Behavior varies depending on tag state:

**Single Press (action=1):**

- **Unpaired state:** Start FHN Discoverable advertising (Model ID)
- **Provisioned state:** Stop "Play Sound" triggered by phone app
- **Reverse Ringing active:** Stop reverse ringing

**Double Press (action=2):**

- **Unpaired state:** Not used
- **Provisioned state (no ringing):** Enable "Identifier Read State" for DULT GATT writes (5-minute window)
- **Reverse Ringing inactive:** Start reverse ringing (Find Phone)
- **Reverse Ringing active:** Stop reverse ringing

**Events:** Button actions trigger state changes reported via ``+EVTTAGSTATE``. Reverse ringing
status changes are reported via ``+EVTTAGGFPREVERSERING``.

.. code-block:: text

   AT+TAGGFPIND=1
   OK

   AT+TAGGFPIND=2
   OK

AT+TAGMOTIONRPT — Host Motion Acceleration Report
**************************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGMOTIONRPT``
:Execute:   ``AT+TAGMOTIONRPT=<x>,<y>,<z>`` — report XYZ acceleration from host sensor
:Query:     ``AT+TAGMOTIONRPT?``

Allows the host to report motion acceleration data (typically from a motion sensor) to the tag.
Each parameter is a signed 16-bit integer representing acceleration in **cm/s²**.

``<x>``, ``<y>``, ``<z>`` are X, Y, and Z-axis accelerations respectively. The tag internally
converts these values to the units required by each protocol (e.g., FHN Ranging classifies
tilt angle from horizontal magnitude).

.. code-block:: text

   AT+TAGMOTIONRPT=100,200,300
   OK

   AT+TAGMOTIONRPT?
   +TAGMOTIONRPT:100,200,300
   OK

+EVTTAGSTATE — Tag State
************************

:Kconfig:  ``CONFIG_AT_EVT_TAGSTATE``
:Format:   ``+EVTTAGSTATE:<protocol>,<state>``

``<protocol>`` is the active protocol bitmask (same encoding as ``AT+TAGMODE``).
``<state>`` is one of the following values (``tag_indication_state_t`` in ``platform_indicate.h``):

.. list-table::
   :header-rows: 1
   :widths: 15 35 50

   * - Value
     - Name
     - Description
   * - ``0``
     - ``BOOTED``
     - System booted
   * - ``1``
     - ``POWER_ON``
     - Tag powered on
   * - ``2``
     - ``POWER_OFF``
     - Tag powered off
   * - ``3``
     - ``INIT_DONE``
     - Tag initialized, ready for pairing
   * - ``4``
     - ``UNPAIRED``
     - Tag unpaired
   * - ``5``
     - ``PAIRING``
     - Tag in pairing mode
   * - ``6``
     - ``PAIRED``
     - Tag successfully paired with host
   * - ``0x60``
     - ``OTA_ACTIVE``
     - OTA mode detected, entering OTA flow
   * - ``0x61``
     - ``OTA_ADVERTISING``
     - OTA advertising started, ready for DFU
   * - ``0x62``
     - ``OTA_COMPLETE``
     - OTA DFU transfer complete, pending reboot
   * - ``0x63``
     - ``OTA_IMAGE_CONFIRMED``
     - OTA image confirmed, update complete

.. note::
   State values are aligned with ``tag_indication_state_t`` in ``platform_indicate.h``
   and passed directly via ``platform_indicate_state()``.

.. code-block:: text

   +EVTTAGSTATE:7,3

+EVTTAGERROR — Tag Error
************************

:Kconfig:  ``CONFIG_AT_EVT_TAGERROR``
:Format:   ``+EVTTAGERROR:<protocol>,<error_code>``

Asynchronous tag-side error notification. ``<protocol>`` is the protocol bitmask
that triggered the error. ``<error_code>`` is one of the values in ``at_cmd_tag_err_t``
(see `Tag AT Command Error Codes`_).

.. code-block:: text

   +EVTTAGERROR:1,3

+EVTTAGGFPREVERSERING — GFP Reverse Ringing Status
***************************************************

:Kconfig:  ``CONFIG_AT_EVT_TAGGFPREVERSERING``
:Format:   ``+EVTTAGGFPREVERSERING:<evt>``

Reports GFP reverse ringing phone status events. ``<evt>`` values:

.. list-table::
   :header-rows: 1
   :widths: 15 35 50

   * - Value
     - Name
     - Description
   * - ``0``
     - ``CONNECTED``
     - Phone ringing; tag connected via RR advertisement
   * - ``1``
     - ``STARTED``
     - Phone confirmed ringing started via GATT
   * - ``2``
     - ``STOPPED``
     - Phone stopped ringing (any reason)
   * - ``3``
     - ``ADV_STARTED``
     - Tag started advertising for adv-based reverse ringing; no connection yet
   * - ``4``
     - ``ADV_TIMEOUT``
     - ADV window expired; phone never connected, never rang
   * - ``5``
     - ``PHONE_FAILED``
     - Phone reported it could not start ringing
   * - ``6``
     - ``TIMEOUT_LOCAL``
     - Provider-side ringing timeout after seeker connected
   * - ``7``
     - ``PHONE_TIMEOUT``
     - Phone's own ring session timed out (Seeker WRITE 0x02)
   * - ``8``
     - ``START_CONFIRMED``
     - START indication ACKed at ATT layer; persistent path fast feedback only
   * - ``9``
     - ``STOP_CONFIRMED``
     - STOP indication ACKed at ATT layer; persistent path fast feedback only
   * - ``10``
     - ``PHONE_STOPPED_DISCONNECTED``
     - BLE connection dropped while phone was ringing
   * - ``11``
     - ``PHONE_START_TIMEOUT``
     - Persistent path 60s timeout after START indication ACKed

.. code-block:: text

   +EVTTAGGFPREVERSERING:0

+EVTTAGBUZZER — Tag Buzzer Action
**********************************

:Kconfig:  ``CONFIG_AT_EVT_TAGBUZZER``
:Format:   ``+EVTTAGBUZZER:<evt>,<ring_vol>,<duration_ds>``

Sent when ``CONFIG_TAG_BUZZER=n`` to notify the host that a buzzer action
is required. The host is responsible for producing the sound.

``<evt>`` encodes operation type (buzzer action), ``<ring_vol>`` is ring volume level,
and ``<duration_ds>`` is ring duration in deciseconds.

.. code-block:: text

   +EVTTAGBUZZER:0x50,5,100

+EVTTAGMOTIONCTL — Motion Sensor Control Event
***********************************************

:Kconfig:  ``CONFIG_AT_EVT_TAGMOTIONCTL``
:Format:   ``+EVTTAGMOTIONCTL:<enable>``

Notifies the host when motion detection is enabled or disabled on the tag.
Used to synchronize motion sensor control between tag and host.

``<enable>`` values:

- ``0`` — motion detection disabled
- ``1`` — motion detection enabled

.. code-block:: text

   +EVTTAGMOTIONCTL:1
   +EVTTAGMOTIONCTL:0

AT+TAGADDR — Query Advertising BT Address
******************************************

:Kconfig:   ``CONFIG_AT_CMD_TAGADDR``
:Execute:   ``AT+TAGADDR=<protocol>``
:Query:     not supported
:Response:  ``+TAGADDR:<protocol>,<adv_addr>``

Returns the live advertising Bluetooth address for the specified protocol.
Intended for debugging purposes. The tag must be started (``AT+TAGSTART=1``)
before advertising is active.

``<protocol>`` values (single protocol only):

- ``0x01`` — FMNA
- ``0x02`` — FHN
- ``0x04`` — STF (requires ``CONFIG_ATM_STF_MULTI_MODE``)

``<adv_addr>`` is the 6-byte BT address in big-endian (MSB first) hex format.

Returns ``AT_CMD_TAG_ERR_INTERNAL`` if the protocol is not advertising.

.. code-block:: text

   AT+TAGADDR=1
   +TAGADDR:1,C0:11:22:33:44:55
   OK

   AT+TAGADDR=2
   +TAGADDR:2,D1:AA:BB:CC:DD:EE
   OK

Tag AT Command Error Codes
===========================

When a tag AT command execution returns an error, the ``<app_err>`` value in the error response
(``ERR:<app_err>``) indicates the application-level error code. These are defined in ``at_cmd_tag_err_t``:

.. list-table::
   :header-rows: 1
   :widths: 15 60

   * - Error Code
     - Description
   * - ``0``
     - ``AT_CMD_TAG_NO_ERR`` — Operation completed successfully
   * - ``1``
     - ``AT_CMD_TAG_ERR_INVALID_PARAM`` — Invalid parameter (e.g., NULL pointer, out-of-range value)
   * - ``2``
     - ``AT_CMD_TAG_ERR_NOT_ALLOWED`` — Operation not allowed in current state (e.g., protocol not enabled)
   * - ``3``
     - ``AT_CMD_TAG_ERR_INTERNAL`` — Internal or platform-level error
   * - ``4``
     - ``AT_CMD_TAG_ERR_BLE_INIT`` — BLE stack initialization failed
   * - ``5``
     - ``AT_CMD_TAG_ERR_MOTION_SENSOR`` — Motion sensor error or not available
   * - ``6``
     - ``AT_CMD_TAG_ERR_BUTTON`` — Button configuration error
   * - ``7``
     - ``AT_CMD_TAG_ERR_WDOG`` — Watchdog configuration error
   * - ``8``
     - ``AT_CMD_TAG_ERR_BUZZER`` — Buzzer configuration error

**Example Error Response:**

.. code-block:: text

   AT+TAGSTFIND=1
   ERR:2
   (AT_CMD_TAG_ERR_NOT_ALLOWED: STF protocol not enabled)

Implementation Notes
====================

**Protocol Mode Checks:**

Most tag commands check if the required protocol is enabled via ``AT+TAGMODE`` before executing.
For example, ``AT+TAGSTFIND`` returns ``AT_CMD_TAG_ERR_NOT_ALLOWED`` if the STF protocol is not
in the active mode bitmap.

**State Dependencies:**

Commands like ``AT+TAGFMNASN`` and ``AT+TAGGFPIND`` depend on the tag state machine. Operations
may return ``AT_CMD_TAG_ERR_NOT_ALLOWED`` if the tag is not in the expected state (e.g., paired
for FMNA operations).

**Event Generation:**

Some commands trigger asynchronous events. For example:
- ``AT+TAGSTART=1`` triggers ``+EVTTAGSTATE`` events as state machine transitions occur
- ``AT+TAGGFPIND`` triggers ``+EVTTAGSTATE`` or ``+EVTTAGGFPREVERSERING`` events depending on action
- ``+EVTTAGMOTIONCTL`` is sent when motion detection is enabled/disabled by the tag

**Motion Reporting:**

The host must register motion acceleration values via ``AT+TAGMOTIONRPT`` for the tag to use
host-based motion data. The tag internally converts cm/s² values to protocol-specific units
(e.g., FHN Ranging calculates tilt angle from XYZ components).
