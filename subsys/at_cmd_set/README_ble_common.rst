.. _at_cmd_ble_common:

BLE Common Commands
###################

See :ref:`at_cmd_format` for command syntax.

These commands are available to both peripheral and central roles.

AT+BLEGAPDISCONNECT — Disconnect
********************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGAPDISCONNECT``
:Execute:   ``AT+BLEGAPDISCONNECT=<conn_idx>``
:Query:     not supported

Initiates graceful disconnection. Result arrives as ``+EVTBLEGAPDISCONN:``.

.. code-block:: text

   AT+BLEGAPDISCONNECT=0
   OK
   +EVTBLEGAPDISCONN:0,22

AT+BLEGAPGETCONNSTAT — Connection Status
****************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGAPGETCONNSTAT``
:Execute:   ``AT+BLEGAPGETCONNSTAT=<conn_idx>``
:Query:     not supported
:Response:  ``+BLEGAPGETCONNSTAT:<role>,<addr_type>,<addr>,<interval>,<latency>,<timeout>``

``role``: ``0`` = central, ``1`` = peripheral. ``interval`` in units of 1.25 ms.

.. code-block:: text

   AT+BLEGAPGETCONNSTAT=0
   +BLEGAPGETCONNSTAT:0,1,C00102030405,24,0,42
   OK

AT+BLEGAPGETPEERINFO — Peer Identity
************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGAPGETPEERINFO``
:Execute:   ``AT+BLEGAPGETPEERINFO=<conn_idx>``
:Query:     not supported
:Response:  ``+BLEGAPGETPEERINFO:<id_addr_type>,<id_addr>,<sec_level>,<enc_key_size>``

.. code-block:: text

   AT+BLEGAPGETPEERINFO=0
   +BLEGAPGETPEERINFO:1,C00102030405,1,0
   OK

AT+BLEGAPGETRSSI — Connection RSSI
**********************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGAPGETRSSI``
:Execute:   ``AT+BLEGAPGETRSSI=<conn_idx>``
:Query:     not supported
:Response:  ``+BLEGAPGETRSSI:<rssi_dBm>``

.. code-block:: text

   AT+BLEGAPGETRSSI=0
   +BLEGAPGETRSSI:-55
   OK

AT+BLECONNTXPWR — Connection TX Power
*************************************

:Kconfig:   ``CONFIG_AT_CMD_BLECONNTXPWR``
:Execute:   ``AT+BLECONNTXPWR=<conn_idx>,<dBm>`` — range −20 to 10
:Query:     ``AT+BLECONNTXPWR?``
:Response:  ``+BLECONNTXPWR:<conn_idx>,<current_dBm>,<max_dBm>`` (one line per active connection)

Requires ``CONFIG_VND_API_SET_CON_TX_POWER`` for the set path.

.. code-block:: text

   AT+BLECONNTXPWR?
   +BLECONNTXPWR:0,0,20
   OK
   AT+BLECONNTXPWR=0,0
   OK

AT+BLEGATTMTUEXCHGREQ — GATT MTU Exchange Request
**************************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTMTUEXCHGREQ``
:Execute:   ``AT+BLEGATTMTUEXCHGREQ=<conn_idx>``
:Query:     not supported

Initiates a GATT ATT MTU exchange with the peer on the specified connection slot.
The negotiated MTU is reported asynchronously via ``+EVTBLEGATTMTUEXCHANGE`` when
``CONFIG_AT_EVT_BLEGATTMTUEXCHANGE`` is enabled. Returns ``AT_ERR_BLE_EALREADY``
if an MTU exchange has already been performed on this connection.

The negotiated MTU is bounded by ``min(local_rx_mtu, local_tx_mtu, peer_rx_mtu, peer_tx_mtu)``.
To negotiate an MTU larger than the default 23 bytes, both ``CONFIG_BT_L2CAP_TX_MTU`` and
``CONFIG_BT_BUF_ACL_RX_SIZE`` must be increased on **both** sides of the connection:

.. code-block:: kconfig

   # Allow negotiating up to 247-byte ATT MTU (ATT header = 3 bytes, so L2CAP PDU = 250)
   CONFIG_BT_L2CAP_TX_MTU=247
   # RX buffer must cover the L2CAP PDU plus the 4-byte HCI ACL header (247 + 4 = 251)
   CONFIG_BT_BUF_ACL_RX_SIZE=251

.. code-block:: text

   AT+BLEGATTMTUEXCHGREQ=0
   OK
   +EVTBLEGATTMTUEXCHANGE:0,247

AT+BLEGATTMTUGET — GATT MTU Query
**********************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGATTMTUGET``
:Execute:   ``AT+BLEGATTMTUGET=<conn_idx>``
:Query:     not supported
:Response:  ``+BLEGATTMTUGET:<mtu>``

Returns the current unenhanced ATT (UATT) MTU for the specified active connection slot.
The value reflects the MTU negotiated during the ATT MTU exchange procedure (default 23
bytes until an exchange is performed).

.. code-block:: text

   AT+BLEGATTMTUGET=0
   +BLEGATTMTUGET:247
   OK
