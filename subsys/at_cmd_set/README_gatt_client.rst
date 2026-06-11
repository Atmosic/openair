.. _at_cmd_gatt_client:

BLE GATT Client Commands
#########################

See :ref:`at_cmd_format` for command syntax.

The GATT client provides AT commands for discovering, reading, writing, and subscribing to
characteristics on a remote BLE GATT server.  Enable with ``CONFIG_AT_CMD_CENTRAL=y``, which
selects ``CONFIG_AT_CMD_GATT_CLIENT`` by default.

All discovery and read commands are **asynchronous**: the firmware responds with ``OK``
immediately and emits one ``+CMD:`` event per discovered attribute.  A new discovery command
cannot be issued on the same connection while another is in progress (returns ``ERR``).

Discovery Commands
==================

AT+BLEGATTDISCSVCS — Discover All Primary Services
---------------------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTDISCSVCS``
:Execute:  ``AT+BLEGATTDISCSVCS=<conn_idx>,<start_handle>,<end_handle>,<max_number>``
:Event:    ``+BLEGATTDISCSVCS:<conn_idx>,<start_handle>,<end_handle>,<uuid>``

Discovers all primary services within the handle range.  ``max_number=0`` means unlimited.
One event is emitted per service; UUID is 4-byte (16-bit) or 32-byte (128-bit) hex string.

.. code-block:: text

   AT+BLEGATTDISCSVCS=0,1,65535,0
   OK
   +BLEGATTDISCSVCS:0,0001,0007,123E4567E89B12D3A456426614174000

AT+BLEGATTDISCSVC — Discover Service by UUID
--------------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTDISCSVC``
:Execute:  ``AT+BLEGATTDISCSVC=<conn_idx>,<uuid>``
:Event:    ``+BLEGATTDISCSVC:<conn_idx>,<start_handle>,<end_handle>,<uuid>``

Discovers all instances of a service identified by UUID across the full attribute range.

.. code-block:: text

   AT+BLEGATTDISCSVC=0,123E4567E89B12D3A456426614174000
   OK
   +BLEGATTDISCSVC:0,0001,0007,123E4567E89B12D3A456426614174000

AT+BLEGATTDISCCHARS — Discover All Characteristics
---------------------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTDISCCHARS``
:Execute:  ``AT+BLEGATTDISCCHARS=<conn_idx>,<start_handle>,<end_handle>,<max_number>``
:Event:    ``+BLEGATTDISCCHARS:<conn_idx>,<decl_handle>,<val_handle>,<properties>,<uuid>``

Discovers all characteristics within the given service handle range.
``properties`` is a 1-byte hex bitmask (BT GATT characteristic properties).

.. code-block:: text

   AT+BLEGATTDISCCHARS=0,0001,0007,0
   OK
   +BLEGATTDISCCHARS:0,0002,0003,12,223E4567E89B12D3A456426614174000
   +BLEGATTDISCCHARS:0,0005,0006,36,323E4567E89B12D3A456426614174000

AT+BLEGATTDISCCHAR — Discover Characteristic by UUID
-----------------------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTDISCCHAR``
:Execute:  ``AT+BLEGATTDISCCHAR=<conn_idx>,<uuid>``
:Event:    ``+BLEGATTDISCCHAR:<conn_idx>,<decl_handle>,<val_handle>,<properties>,<uuid>``

Discovers all instances of a characteristic UUID across the full attribute range.

.. code-block:: text

   AT+BLEGATTDISCCHAR=0,223E4567E89B12D3A456426614174000
   OK
   +BLEGATTDISCCHAR:0,0002,0003,12,223E4567E89B12D3A456426614174000

AT+BLEGATTDISCDESCS — Discover Descriptors
------------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTDISCDESCS``
:Execute:  ``AT+BLEGATTDISCDESCS=<conn_idx>,<start_handle>,<end_handle>,<max_number>``
:Event:    ``+BLEGATTDISCDESCS:<conn_idx>,<handle>,<uuid>``

Discovers all descriptors within the given handle range.  Typically used to locate the CCCD
(UUID ``2902``) of a characteristic.

.. code-block:: text

   AT+BLEGATTDISCDESCS=0,0003,0004,0
   OK
   +BLEGATTDISCDESCS:0,0004,2902

Read / Write Commands
=====================

AT+BLEGATTRD — Read Characteristic Value
-----------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTRD``
:Execute:  ``AT+BLEGATTRD=<conn_idx>,<handle>,<offset>``
:Event:    ``+BLEGATTRD:<conn_idx>,<handle>,<data>``

Reads a characteristic value at the given ATT handle.  Use ``offset=0`` for a standard read.
Response data is a hex string capped at ``CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN`` bytes.

.. code-block:: text

   AT+BLEGATTRD=0,0006,0
   OK
   +BLEGATTRD:0,0006,DEADBEEF

AT+BLEGATTWR — Write With Response
------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTWR``
:Execute:  ``AT+BLEGATTWR=<conn_idx>,<handle>,<data_array>``
:Event:    ``+BLEGATTWR:<conn_idx>,<handle>,<status>``

Sends a Write Request (ATT opcode 0x12).  ``status=0`` in the response event means success.

.. code-block:: text

   AT+BLEGATTWR=0,0003,CAFEBABE
   OK
   +BLEGATTWR:0,0003,0

AT+BLEGATTWRWO — Write Without Response
-----------------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTWRWO``
:Execute:  ``AT+BLEGATTWRWO=<conn_idx>,<handle>,<data_array>``

Sends a Write Command (ATT opcode 0x52, no acknowledgement).  No response event is generated.

.. code-block:: text

   AT+BLEGATTWRWO=0,0003,CAFEBABE
   OK

Subscribe / Unsubscribe
=======================

AT+BLEGATTWRCCCD — Write CCCD
------------------------------

:Kconfig:  ``CONFIG_AT_CMD_BLEGATTWRCCCD``
:Execute:  ``AT+BLEGATTWRCCCD=<conn_idx>,<value_handle>,<ccc_handle>,<ccc_value>``
:Event:    ``+BLEGATTWRCCCD:<conn_idx>,<ccc_handle>,<status>``

Writes the Client Characteristic Configuration Descriptor to subscribe or unsubscribe.
Both ``value_handle`` and ``ccc_handle`` are required to correlate incoming events.

.. list-table::
   :header-rows: 1
   :widths: 10 90

   * - ``ccc_value``
     - Description
   * - ``0``
     - Disable (unsubscribe)
   * - ``1``
     - Enable notifications
   * - ``2``
     - Enable indications

.. code-block:: text

   AT+BLEGATTWRCCCD=0,0003,0004,1
   OK
   +BLEGATTWRCCCD:0,0004,0

Events
======

+BLEGATTNOTI — Notification Received
--------------------------------------

:Kconfig:  ``CONFIG_AT_EVT_BLEGATTNOTI``
:Format:   ``+BLEGATTNOTI:<conn_idx>,<handle>,<data>``

Emitted when the peer sends a GATT notification to a subscribed characteristic.
``data`` is a hex string capped at ``CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN`` bytes.

+BLEGATTINDI — Indication Received
------------------------------------

:Kconfig:  ``CONFIG_AT_EVT_BLEGATTINDI``
:Format:   ``+BLEGATTINDI:<conn_idx>,<handle>,<data>``

Emitted when the peer sends a GATT indication.  The stack automatically confirms the indication
before this event is raised.

Typical Two-Device Flow
***********************

**devB (peripheral / server)** — enable DFT GATT server and advertise:

.. code-block:: text

   AT+BLEGATTDFTSERVER=ON
   OK
   AT+BLEADVENABLE=0,ON
   OK
   +EVTBLEGAPCONN:0,1,A00102030405

**devA (central / client)**:

.. code-block:: text

   AT+BLEGAPCREATECONN=1,A00102030405,30
   OK
   +EVTBLEGAPCONN:0,1,A00102030405

   AT+BLEGATTDISCSVCS=0,1,65535,0
   OK
   +BLEGATTDISCSVCS:0,0001,0007,123E4567E89B12D3A456426614174000

   AT+BLEGATTDISCCHARS=0,0001,0007,0
   OK
   +BLEGATTDISCCHARS:0,0002,0003,12,223E4567E89B12D3A456426614174000
   +BLEGATTDISCCHARS:0,0005,0006,36,323E4567E89B12D3A456426614174000

   AT+BLEGATTDISCDESCS=0,0003,0004,0
   OK
   +BLEGATTDISCDESCS:0,0004,2902

   AT+BLEGATTRD=0,0006,0
   OK
   +BLEGATTRD:0,0006,DEADBEEF

   AT+BLEGATTWRCCCD=0,0003,0004,1
   OK
   +BLEGATTWRCCCD:0,0004,0

   (devB: AT+BLEGATTTOBLE=0,0002,02,AABBCCDD)
   +BLEGATTNOTI:0,0003,AABBCCDD

   AT+BLEGAPDISCONNECT=0
   OK
   +EVTBLEGAPDISCONN:0,22

Kconfig Summary
***************

.. list-table::
   :header-rows: 1
   :widths: 42 58

   * - Kconfig symbol
     - Purpose
   * - ``CONFIG_AT_CMD_GATT_CLIENT``
     - Master enable; selected automatically by ``CONFIG_AT_CMD_CENTRAL``
   * - ``CONFIG_AT_CMD_GATT_CLIENT_RD_MAX_LEN``
     - Maximum bytes for read / notify / indicate data (default: 244)
   * - ``CONFIG_AT_CMD_GATT_CLIENT_SUBS_MAX``
     - Subscribe slots per connection (default: 4)
   * - ``CONFIG_AT_CMD_BLEGATTDISCSVCS``
     - ``AT+BLEGATTDISCSVCS``
   * - ``CONFIG_AT_CMD_BLEGATTDISCSVC``
     - ``AT+BLEGATTDISCSVC``
   * - ``CONFIG_AT_CMD_BLEGATTDISCCHARS``
     - ``AT+BLEGATTDISCCHARS``
   * - ``CONFIG_AT_CMD_BLEGATTDISCCHAR``
     - ``AT+BLEGATTDISCCHAR``
   * - ``CONFIG_AT_CMD_BLEGATTDISCDESCS``
     - ``AT+BLEGATTDISCDESCS``
   * - ``CONFIG_AT_CMD_BLEGATTRD``
     - ``AT+BLEGATTRD``
   * - ``CONFIG_AT_CMD_BLEGATTWR``
     - ``AT+BLEGATTWR``
   * - ``CONFIG_AT_CMD_BLEGATTWRWO``
     - ``AT+BLEGATTWRWO``
   * - ``CONFIG_AT_CMD_BLEGATTWRCCCD``
     - ``AT+BLEGATTWRCCCD``
   * - ``CONFIG_AT_EVT_BLEGATTNOTI``
     - ``+BLEGATTNOTI``
   * - ``CONFIG_AT_EVT_BLEGATTINDI``
     - ``+BLEGATTINDI``
