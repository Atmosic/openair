.. _at_cmd_ble_events:

BLE Events
##########

Events are emitted asynchronously from BT callbacks. They require no polling.
See :ref:`at_cmd_format` for response format.

Central Events
**************

+EVTBLEGAPADVRPT — Advertisement Report
========================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGAPADVRPT``
:Depends:  ``CONFIG_AT_CMD_BLESCANENABLE``
:Role:     Central
:Format:   ``+EVTBLEGAPADVRPT:<evt_type>,<addr_type>,<addr>,<rssi>,<data_len>,<data_hex>``

``evt_type``: ``0`` = legacy adv, ``1`` = legacy scan rsp, ``2`` = extended adv, ``3`` = extended scan rsp.

.. code-block:: text

   +EVTBLEGAPADVRPT:0,1,C00102030405,-55,3,020180

Common Events (Peripheral and Central)
***************************************

+EVTBLEGAPCONN — Connection Established
========================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGAPCONN``
:Role:     Peripheral and Central
:Format:   ``+EVTBLEGAPCONN:<conn_idx>,<addr_type>,<addr>``

Emitted after ``AT+BLEGAPCREATECONN`` completes (central) or an incoming connection is accepted (peripheral).

.. code-block:: text

   +EVTBLEGAPCONN:0,1,C00102030405

+EVTBLEGAPDISCONN — Disconnection
===================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGAPDISCONN``
:Role:     Peripheral and Central
:Format:   ``+EVTBLEGAPDISCONN:<conn_idx>,<reason>``

``reason`` is the HCI disconnect reason code in decimal (e.g. ``22`` = remote user terminated).

.. code-block:: text

   +EVTBLEGAPDISCONN:0,22

+EVTBLEGAPLINKINFO — Remote LE Features
=========================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGAPLINKINFO``
:Role:     Peripheral and Central
:Format:   ``+EVTBLEGAPLINKINFO:<conn_idx>,<features_8B_hex>``

Fired once per connection when the mandatory LE feature exchange completes.

.. code-block:: text

   +EVTBLEGAPLINKINFO:0,2F49010580010000

+EVTBLEGAPPAR — Connection Parameter Update
=============================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGAPPAR``
:Role:     Peripheral and Central
:Format:   ``+EVTBLEGAPPAR:<conn_idx>,<interval>,<latency>,<timeout>``

``interval`` in units of 1.25 ms. Fired when the LL connection parameter update procedure completes.

.. code-block:: text

   +EVTBLEGAPPAR:0,24,0,42

+EVTBLEGATTMTUEXCHANGE — GATT MTU Exchange
==========================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGATTMTUEXCHANGE``
:Depends:  ``CONFIG_AT_CMD_SET_CONN_TRACKING``
:Role:     Peripheral and Central
:Format:   ``+EVTBLEGATTMTUEXCHANGE:<conn_idx>,<mtu>``

``mtu`` is the negotiated TX ATT MTU in bytes. Fired whenever the ATT MTU for an active
connection is updated (i.e. after an MTU exchange completes on either side).
Typically triggered by ``AT+BLEGATTMTUEXCHGREQ``.

.. code-block:: text

   +EVTBLEGATTMTUEXCHANGE:0,247

+EVTBLEGATTMTUEXCHGREQ — GATT MTU Exchange Request Result
==========================================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGATTMTUEXCHGREQ``
:Depends:  ``CONFIG_AT_CMD_BLEGATTMTUEXCHGREQ``
:Role:     Peripheral and Central
:Format:   ``+EVTBLEGATTMTUEXCHGREQ:<conn_idx>,<err>``

Fired when the ATT MTU exchange procedure initiated by ``AT+BLEGATTMTUEXCHGREQ``
completes. ``err`` is ``0`` on success or an ATT/HCI error code on failure.
This event is always emitted regardless of outcome, allowing the host to detect
silent failures where ``+EVTBLEGATTMTUEXCHANGE`` is not emitted (e.g. peer rejected
the exchange or the connection dropped mid-procedure).

.. code-block:: text

   +EVTBLEGATTMTUEXCHGREQ:0,0

BLE GATT Events
***************

+EVTBLEGATTFROMBLE — Client Read / Write Event
===============================================

:Kconfig:  ``CONFIG_AT_EVT_BLEGATTFROMBLE``
:Depends:  ``CONFIG_AT_CMD_GATT_DFT_SERVER``
:Role:     Peripheral
:Format:   ``+EVTBLEGATTFROMBLE:<conidx>,<attidx(2B)>,<action>,<data>``

Emitted when a connected client reads or writes a characteristic.  ``attidx`` is
big-endian (2 bytes).  ``action``: ``0`` = READ (``data`` is empty),
``1`` = WRITE (``data`` = bytes written by client).

.. code-block:: text

   +EVTBLEGATTFROMBLE:0,0002,01,CAFEBABE
