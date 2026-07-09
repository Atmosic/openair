.. _at_cmd_gatt:

BLE GATT Server Commands
########################

See :ref:`at_cmd_format` for command syntax.

The AT command set supports two GATT server modes:

- **Default GATT Server** — Single pre-configured service with two characteristics; configuration persisted in Settings
- **Dynamic GATT Server** — Runtime composition of multiple services, characteristics, and descriptors; not persisted


BLE GATT Default Server Commands
=================================

The GATT default server provides a runtime-configurable BLE GATT service with two
characteristics (Char1 / Char2). Service UUID, characteristic UUIDs, and security
properties are set via AT commands and persisted in Settings storage.

**Persistence rules:**

- Service / characteristic UUID and ``sec_prop`` — persisted in Settings.
- Server enabled state (``AT+BLEGATTDFTSERVER``) — **not** persisted; always defaults to ``OFF`` at boot.
- Characteristic pre-set read value (``AT+BLEGATTDFTCHAR*VAL``) — **not** persisted; cleared on reboot.

**Compile-time defaults:**

.. list-table::
   :header-rows: 1
   :widths: 20 20 60

   * - Parameter
     - Default ``sec_prop``
     - Default UUID (big-endian hex)
   * - Service
     - ``0000``
     - ``123E4567E89B12D3A456426614174000``
   * - Char1 (TRX)
     - ``0202`` (WRITE + NOTIFY)
     - ``223E4567E89B12D3A456426614174000``
   * - Char2 (TRX2)
     - ``0602`` (WRITE + NOTIFY + INDICATE)
     - ``323E4567E89B12D3A456426614174000``

The attribute table is rebuilt on every ``AT+BLEGATTDFTSERVER=ON``.  Changes made
while a connection is active are deferred and applied automatically after all
connections are dropped.

sec_prop Reference
==================

``sec_prop`` is a 16-bit bitmask passed as a 2-byte big-endian hex string (e.g. ``0x0003``).
Multiple bits can be combined (OR) to enable multiple permissions simultaneously.

Bits 0-8 apply access restrictions to the attribute value.
Bits 9-10 are characteristic-only and control notification/indication support.

.. list-table::
   :header-rows: 1
   :widths: 10 12 18 60

   * - Bit
     - Hex
     - Name
     - Description
   * - 0
     - ``0x0001``
     - READ
     - Readable
   * - 1
     - ``0x0002``
     - WRITE
     - Writable
   * - 2
     - ``0x0004``
     - READ_ENCRYPT
     - Readable only over encrypted connection
   * - 3
     - ``0x0008``
     - WRITE_ENCRYPT
     - Writable only over encrypted connection
   * - 4
     - ``0x0010``
     - READ_AUTHEN
     - Readable only over authenticated connection
   * - 5
     - ``0x0020``
     - WRITE_AUTHEN
     - Writable only over authenticated connection
   * - 7
     - ``0x0080``
     - READ_LESC
     - Readable only over LE Secure Connection
   * - 8
     - ``0x0100``
     - WRITE_LESC
     - Writable only over LE Secure Connection
   * - 9
     - ``0x0200``
     - NOTIFY
     - Characteristic supports notification
   * - 10
     - ``0x0400``
     - INDICATE
     - Characteristic supports indication

.. note::
   For ``AT+BLEGATTDFTSERVICE``, only READ bits (0, 2, 4, 7) are accepted.
   Service declarations are read-only; WRITE bits are rejected.

Default Attribute Layout
========================

Default configuration: Char1 ``sec_prop=0x0202`` (WRITE+NOTIFY),
Char2 ``sec_prop=0x0602`` (WRITE+NOTIFY+INDICATE). Both have CCCD.

.. list-table::
   :header-rows: 1
   :widths: 10 35 55

   * - Array Index
     - Attribute
     - Note
   * - 0
     - Primary Service declaration
     - Service UUID
   * - 1
     - Char1 declaration (CHRC)
     - Properties derived from ``sec_prop``
   * - 2
     - Char1 value
     - Read/write callbacks; pre-set via ``AT+BLEGATTDFTCHAR1VAL``
   * - 3
     - Char1 CCCD
     - Present only when NOTIFY or INDICATE bit is set
   * - 4
     - Char2 declaration (CHRC)
     - Properties derived from ``sec_prop``
   * - 5
     - Char2 value
     - Read/write callbacks; pre-set via ``AT+BLEGATTDFTCHAR2VAL``
   * - 6
     - Char2 CCCD
     - Present only when NOTIFY or INDICATE bit is set

Removing NOTIFY/INDICATE from a characteristic eliminates its CCCD, shifting
the array index of all subsequent attributes.

AT+BLEGATTDFTSERVER — Enable / Disable Default GATT Server
-----------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTDFTSERVER``
:Execute:   ``AT+BLEGATTDFTSERVER=<ON|OFF>``
:Query:     ``AT+BLEGATTDFTSERVER?``
:Response:  ``+BLEGATTDFTSERVER:<ON|OFF>``

Registers (``ON``) or unregisters (``OFF``) the default GATT service with the
Bluetooth stack.  The service configuration is preserved; only the registration
state changes.  Not persisted — defaults to ``OFF`` at boot.

.. code-block:: text

   AT+BLEGATTDFTSERVER=ON
   OK
   AT+BLEGATTDFTSERVER?
   +BLEGATTDFTSERVER:ON
   OK

AT+BLEGATTDFTSERVICE — Default Service Configuration
-----------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTDFTSERVICE``
:Execute:   ``AT+BLEGATTDFTSERVICE=<sec_prop(2B)>,<uuid(16B)>``
:Query:     ``AT+BLEGATTDFTSERVICE?``
:Response:  ``+BLEGATTDFTSERVICE:<sec_prop(2B)>,<uuid(16B)>``

Sets the service UUID and read permission.  Both parameters are big-endian hex.
Only READ-type ``sec_prop`` bits are accepted; WRITE bits return ``ERR``.
Persisted in Settings; applied on next ``AT+BLEGATTDFTSERVER=ON``.

Default UUID (MSB-first): ``123E4567E89B12D3A456426614174000``

.. code-block:: text

   AT+BLEGATTDFTSERVICE=0001,123E4567E89B12D3A456426614174000
   OK
   AT+BLEGATTDFTSERVICE?
   +BLEGATTDFTSERVICE:0001,123E4567E89B12D3A456426614174000
   OK


AT+BLEGATTDFTCHAR1 — Characteristic 1 (TRX) Configuration
----------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTDFTCHAR1``
:Execute:   ``AT+BLEGATTDFTCHAR1=<sec_prop(2B)>,<uuid(16B)>``
:Query:     ``AT+BLEGATTDFTCHAR1?``
:Response:  ``+BLEGATTDFTCHAR1:<sec_prop(2B)>,<uuid(16B)>``

Sets the UUID and security properties for Characteristic 1 (TRX).
Persisted in Settings; applied on next ``AT+BLEGATTDFTSERVER=ON``.

Default: ``sec_prop=0x0202`` (WRITE + NOTIFY), UUID ``223E4567E89B12D3A456426614174000``

.. code-block:: text

   AT+BLEGATTDFTCHAR1=0202,223E4567E89B12D3A456426614174000
   OK
   AT+BLEGATTDFTCHAR1?
   +BLEGATTDFTCHAR1:0202,223E4567E89B12D3A456426614174000
   OK

AT+BLEGATTDFTCHAR2 — Characteristic 2 (TRX2) Configuration
-----------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTDFTCHAR2``
:Execute:   ``AT+BLEGATTDFTCHAR2=<sec_prop(2B)>,<uuid(16B)>``
:Query:     ``AT+BLEGATTDFTCHAR2?``
:Response:  ``+BLEGATTDFTCHAR2:<sec_prop(2B)>,<uuid(16B)>``

Sets the UUID and security properties for Characteristic 2 (TRX2).
Persisted in Settings; applied on next ``AT+BLEGATTDFTSERVER=ON``.

Default: ``sec_prop=0x0602`` (WRITE + NOTIFY + INDICATE), UUID ``323E4567E89B12D3A456426614174000``

.. code-block:: text

   AT+BLEGATTDFTCHAR2=0602,323E4567E89B12D3A456426614174000
   OK

AT+BLEGATTDFTCHAR1VAL — Characteristic 1 Pre-set Read Value
------------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTDFTCHAR1VAL``
:Execute:   ``AT+BLEGATTDFTCHAR1VAL=<data(0~512B)>``
:Query:     ``AT+BLEGATTDFTCHAR1VAL?``
:Response:  ``+BLEGATTDFTCHAR1VAL:<data>``

Pre-sets the value returned to a BLE client when it reads Characteristic 1.
Because Zephyr read callbacks are synchronous, a round-trip to the host is not
possible at read time; the host must stage the value in advance with this command.

Not persisted across reboot.  Empty ``<data>`` clears the buffer (returns zero bytes).

.. code-block:: text

   AT+BLEGATTDFTCHAR1VAL=DEADBEEF
   OK
   AT+BLEGATTDFTCHAR1VAL?
   +BLEGATTDFTCHAR1VAL:DEADBEEF
   OK

AT+BLEGATTDFTCHAR2VAL — Characteristic 2 Pre-set Read Value
------------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTDFTCHAR2VAL``
:Execute:   ``AT+BLEGATTDFTCHAR2VAL=<data(0~512B)>``
:Query:     ``AT+BLEGATTDFTCHAR2VAL?``
:Response:  ``+BLEGATTDFTCHAR2VAL:<data>``

Same as ``AT+BLEGATTDFTCHAR1VAL`` but for Characteristic 2.

.. code-block:: text

   AT+BLEGATTDFTCHAR2VAL=CAFEBABE
   OK

AT+BLEGATTTOBLE — Send Notification / Indication
-------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTTOBLE``
:Execute:   ``AT+BLEGATTTOBLE=<conidx>,<handle>,<action>,<data(0~1024B)>``
:Query:     not supported

Sends a GATT notification (unacknowledged) or indication (acknowledged) to a
connected peer.  ``conidx`` is the connection slot index.  ``handle`` is the
BT GATT attribute handle of the characteristic value.

``action`` values:

.. list-table::
   :header-rows: 1
   :widths: 10 15 75

   * - Value
     - Name
     - Description
   * - ``2``
     - ``NOTIFY``
     - Send notification; ``data`` may be empty (zero-length payload)
   * - ``3``
     - ``INDICATE``
     - Send indication; ``data`` may be empty (zero-length payload)

.. code-block:: text

   AT+BLEGATTTOBLE=0,2,2,DEADBEEF
   OK

   AT+BLEGATTTOBLE=0,5,3,DEADBEEF
   OK


BLE GATT Dynamic Server Commands
=================================

The GATT dynamic server allows runtime definition of BLE GATT services, characteristics,
and descriptors via AT commands. Multiple services can be staged and activated together.

**Key Differences from Default GATT Server:**

- Composition: Define multiple services, characteristics, and descriptors individually at runtime
- Persistence: All services are cleared on device reboot (not persisted to storage)
- Staging workflow: Commands build up a pending service definition until activation
- Multiple services: Create and activate multiple independent services in a single session

**Compile-time requirement:**

.. code-block:: cfg

   CONFIG_AT_CMD_PERIPHERAL=y

Basic Workflow
==============

Services are built in stages:

1. **Stage a service** — ``AT+BLEGATTADDSERVICE=<sec_prop>,<uuid>``
2. **Add characteristic(s)** — ``AT+BLEGATTADDCHAR=<sec_prop>,<uuid>,<size>`` (repeat as needed)
3. **Add descriptor(s)** — ``AT+BLEGATTADDDESC=<uuid>`` or ``AT+BLEGATTADDDESCUSERDFD=...`` (optional)
4. **Activate** — ``AT+BLEGATTSVCACTIVE=00`` to register the service

.. note::
   - After ``ADDSERVICE``, all subsequent ``ADDCHAR`` commands target that service until you call ``ADDSERVICE`` again
   - After ``ADDCHAR``, all subsequent ``ADDDESC`` commands target that characteristic until you add another character
   - If ``ADDCHAR`` sets NOTIFY or INDICATE bits (0x0200 or 0x0400), a CCCD is **automatically added**
   - Services are not registered with the Bluetooth stack until ``BLEGATTSVCACTIVE`` is called

**Error codes (app_err):**

.. list-table::
   :header-rows: 1
   :widths: 10 15 75

   * - Code
     - Name
     - Condition
   * - ``0x30``
     - ``PARAM_INVALID``
     - Parameter format error or invalid bit combination (e.g. NOTIFY on descriptor)
   * - ``0x80``
     - ``SVC_ACTIVE``
     - Attempted to add char/desc to an already-activated service
   * - ``0x83``
     - ``NO_SVC``
     - ``ADDCHAR``/``ADDDESC`` called before any ``ADDSERVICE``, or no staged service to activate
   * - ``0x84``
     - ``NO_CHAR``
     - ``ADDDESC`` called before any ``ADDCHAR``

AT+BLEGATTADDSERVICE — Stage a Primary Service
-----------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTADDSERVICE``
:Execute:   ``AT+BLEGATTADDSERVICE=<sec_prop(2B)>,<uuid(16B)>``

Stages a new Primary Service. The service will be registered with the Bluetooth
stack when ``AT+BLEGATTSVCACTIVE=00`` is called. ``sec_prop`` uses the same bit encoding as
``AT+BLEGATTDFTSERVICE``, but **only READ-type bits (0, 2, 4, 7) are accepted**. WRITE bits (1, 3, 5, 6) and
characteristic extension bits (9-10 NOTIFY/INDICATE) return error code ``0x30``.

**Parameters:**

- ``sec_prop`` — 16-bit bitmask (2 hex bytes, big-endian) of ``BT_GATT_PERM_*`` bits
- ``uuid`` — 128-bit UUID (16 hex bytes, big-endian / MSB-first)

**Example:**

.. code-block:: text

   AT+BLEGATTADDSERVICE=0000,D1A03E67E89B12D3A456426614174000
   OK

AT+BLEGATTADDCHAR — Add a Characteristic to Staged Service
-----------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTADDCHAR``
:Execute:   ``AT+BLEGATTADDCHAR=<sec_prop(2B)>,<uuid(16B)>,<max_size(2B)>``
:Query:     not supported

Adds a Characteristic to the current service (last service created by ``ADDSERVICE``).
Must be called after ``ADDSERVICE`` and before ``BLEGATTSVCACTIVE``.

**Parameters:**

- ``sec_prop`` — 16-bit bitmask; same bit encoding as ``AT+BLEGATTDFTCHAR*``
- ``uuid`` — 128-bit UUID (16 hex bytes, big-endian)
- ``max_size`` — Value buffer size in bytes; ``1–1024``

**Bits 9-10 (NOTIFY / INDICATE):**

Bits 9-10 in ``sec_prop`` control whether the characteristic supports notifications or indications.
When either bit is set, a **Client Characteristic Configuration Descriptor (CCCD) is automatically added**.
These bits are **exclusive to characteristics**; they are rejected on descriptors (returns error ``0x30``).

- Bit 9 (``0x0200``) — ``NOTIFY`` — Automatic CCCD + ``CHRC_NOTIFY`` property
- Bit 10 (``0x0400``) — ``INDICATE`` — Automatic CCCD + ``CHRC_INDICATE`` property
- Both bits (``0x0600``) — CCCD + both ``CHRC_NOTIFY`` and ``CHRC_INDICATE`` properties

**Example:**

.. code-block:: text

   AT+BLEGATTADDCHAR=0003,D1A03E67E89B12D3A456426614174001,16
   OK

AT+BLEGATTADDDESC — Add a Standard Descriptor (16-bit UUID)
-----------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTADDDESC``
:Execute:   ``AT+BLEGATTADDDESC=<uuid16(2B)>``
:Query:     not supported

Adds a read-only standard descriptor (using a 16-bit UUID) to the current characteristic.
Must be called after ``ADDCHAR``. The descriptor value is **read-only** and managed by the firmware.

.. warning::
   Do **NOT** call ``BLEGATTADDDESC=2902`` if NOTIFY or INDICATE is enabled in ``ADDCHAR``.

   When you set bit 9 or 10 (NOTIFY/INDICATE) in ``ADDCHAR`` sec_prop, a Client Characteristic
   Configuration Descriptor (CCCD, UUID ``2902``) is **automatically added** with full read/write
   capability. Manually calling ``BLEGATTADDDESC=2902`` will add a **duplicate**, read-only descriptor
   that does not function as a CCCD.

   This command is useful for adding other standard descriptors (not CCCD), such as CPFD (0x2904) or CUFD (0x2905).

**Parameters:**

- ``uuid16`` — 16-bit standard descriptor UUID (e.g. ``0x2904`` for CPFD, ``0x2905`` for CUFD)

**Example:**

.. code-block:: text

   AT+BLEGATTADDDESC=2904
   OK

AT+BLEGATTADDDESCUSERDFD — Add a User-Defined Descriptor
---------------------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTADDDESCUSERDFD``
:Execute:   ``AT+BLEGATTADDDESCUSERDFD=<sec_prop(2B)>,<uuid(16B)>,<max_size(2B)>``
:Query:     not supported

Adds a custom descriptor with a 128-bit UUID and read/write permissions to the current characteristic.
Must be called after ``ADDCHAR``. Unlike ``ADDDESC``, this allows you to define permissions and value size.

**Parameters:**

- ``sec_prop`` — 16-bit bitmask; **bits 9–10 must be 0**
- ``uuid`` — 128-bit UUID (16 hex bytes, big-endian)
- ``max_size`` — Value buffer size in bytes; ``1–1024``

**Example:**

.. code-block:: text

   AT+BLEGATTADDDESCUSERDFD=0001,D1A03E67E89B12D3A456426614174002,8
   OK

AT+BLEGATTSVCACTIVE — Activate Staged Services
-----------------------------------------------

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTADDSERVICE`` (as dependency)
:Execute:   ``AT+BLEGATTSVCACTIVE=<reason>``
:Query:     ``AT+BLEGATTSVCACTIVE?`` — returns ``00``

Registers all staged services with the Bluetooth stack. After activation, the services are live
and clients can connect and interact with them. Services remain active until the device reboots
or ``AT+SYSRESET`` is called.

**Parameters:**

- ``reason`` — Must be ``00``. Other values are rejected.

.. warning::
   **Not atomic**: If activation of multiple staged services fails mid-way (e.g., second service fails due to
   resource exhaustion), the first service(s) will remain registered in the GATT database. Only ``AT+SYSRESET=0``
   will clear all services; individual service deactivation is not supported.

**Common errors:**

- No service was staged (must call ``ADDSERVICE`` first)
- No pending service to activate (all staged services already active)

**Example:**

.. code-block:: text

   AT+BLEGATTSVCACTIVE=00
   OK

Typical Dynamic GATT Workflow
=============================

**Setup: Create a simple read-only service with one characteristic:**

.. code-block:: text

   AT+BLEGATTADDSERVICE=0000,D1A03E67E89B12D3A456426614174000
   OK
   AT+BLEGATTADDCHAR=0001,D1A03E67E89B12D3A456426614174001,16
   OK
   AT+BLEGATTSVCACTIVE=00
   OK

**Cleanup: Reboot to clear all staged and active services:**

.. code-block:: text

   AT+SYSRESET=0
   OK
   (Device reboots; wait 2 seconds for reconnection)

Events
======

When a BLE client reads or writes a GATT characteristic or descriptor, the device emits
the ``+EVTBLEGATTFROMBLE`` event. See :ref:`at_cmd_ble_events` for detailed event format
and behavior. Both default and dynamic GATT servers emit this event if
``CONFIG_AT_EVT_BLEGATTFROMBLE`` is enabled.

Troubleshooting
===============

**Q: I get ``ERR:5`` when calling ``AT+BLEGATTADDSERVICE``**

A: ``ERR:5`` is a low-level AT parser error, usually indicating a parameter format violation.
Check:

- UUID length must be exactly 32 hex characters (128 bits)
- ``sec_prop`` must be exactly 4 hex characters (16 bits)
- All parameters must be big-endian (MSB-first)

**Q: I get error ``0x80`` when calling ``AT+BLEGATTADDCHAR``**

A: The service has already been activated with ``BLEGATTSVCACTIVE``. You cannot add characteristics
to an activated service. Reboot the device to start fresh, or define a completely new service with a different UUID.

**Q: How do I define multiple services?**

A: Call ``ADDSERVICE`` for each service, add characteristics as needed, then activate all at once.
Services without characteristics are allowed (per BT Core Spec).

.. code-block:: text

   AT+BLEGATTADDSERVICE=0000,<uuid1>
   AT+BLEGATTADDCHAR=0001,<uuid1_char>,16

   AT+BLEGATTADDSERVICE=0000,<uuid2>           # OK even if uuid1 has no chars
   AT+BLEGATTADDCHAR=0001,<uuid2_char>,16

   AT+BLEGATTSVCACTIVE=00                      # Activate all staged services
