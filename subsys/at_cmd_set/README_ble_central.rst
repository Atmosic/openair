.. _at_cmd_ble_central:

BLE Central Commands
####################

See :ref:`at_cmd_format` for command syntax.

AT+BLESCANENABLE — Start / Stop Scanning
****************************************

:Kconfig:   ``CONFIG_AT_CMD_BLESCANENABLE``
:Execute:   ``AT+BLESCANENABLE=<ON|OFF>``
:Query:     ``AT+BLESCANENABLE?``
:Response:  ``+BLESCANENABLE:<ON|OFF>``

Active scan with duplicate filtering. Reports are delivered as ``+EVTBLEGAPADVRPT:`` events.
If ``CONFIG_AT_CMD_BLESCANFILMAC`` is enabled and a MAC filter is set, the controller
Filter Accept List is used so only the filtered device's advertisements reach the host.

.. code-block:: text

   AT+BLESCANENABLE=ON
   OK
   +EVTBLEGAPADVRPT:0,1,C00102030405,-55,3,020180
   AT+BLESCANENABLE=OFF
   OK

AT+BLESCANFILMAC — Controller MAC Address Filter
************************************************

:Kconfig:   ``CONFIG_AT_CMD_BLESCANFILMAC``
:Depends:   ``CONFIG_AT_CMD_BLESCANENABLE`` (selects ``CONFIG_BT_FILTER_ACCEPT_LIST``)
:Execute:   ``AT+BLESCANFILMAC=<ON|OFF>,<addr_type>,<addr>``
:Query:     ``AT+BLESCANFILMAC?``
:Response:  ``+BLESCANFILMAC:<ON|OFF>,<addr_type>,<addr>``

Programs the controller Filter Accept List.
``addr_type``: ``0`` = public, ``1`` = random static.

.. note::
   Cannot be set (execute) while scanning is active (``AT+BLESCANENABLE=ON``). Returns ``ERR``
   if attempted. Query (``AT+BLESCANFILMAC?``) is always allowed.

.. note::
   Mutually exclusive with the RSSI filter — enabling MAC automatically bypasses RSSI filtering.

.. code-block:: text

   AT+BLESCANFILMAC=ON,1,C00102030405
   OK
   AT+BLESCANENABLE=ON
   OK

AT+BLESCANFILRSSI — RSSI Threshold Filter
*****************************************

:Kconfig:   ``CONFIG_AT_CMD_BLESCANFILRSSI``
:Depends:   ``CONFIG_AT_CMD_BLESCANENABLE``
:Execute:   ``AT+BLESCANFILRSSI=<threshold_dBm>`` — range −90 to −40
:Query:     ``AT+BLESCANFILRSSI?``
:Response:  ``+BLESCANFILRSSI:<ON|OFF>,<threshold_dBm>``

Host-side RSSI filter applied to every scan report. ``ON`` = active; ``OFF`` = bypassed because
MAC filter is active. Default threshold is −90 dBm (most permissive).

.. note::
   Cannot be set (execute) while scanning is active (``AT+BLESCANENABLE=ON``). Returns ``ERR``
   if attempted. Query (``AT+BLESCANFILRSSI?``) is always allowed.

.. code-block:: text

   AT+BLESCANFILRSSI=-70
   OK
   AT+BLESCANFILRSSI?
   +BLESCANFILRSSI:ON,-70
   OK

AT+BLEGAPCREATECONN — Initiate Connection
*****************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGAPCREATECONN``
:Depends:   ``CONFIG_AT_CMD_BLESCANENABLE`` (auto-selects ``CONFIG_AT_CMD_BLEGAPCANCELCREATECONN``)
:Execute:   ``AT+BLEGAPCREATECONN=<addr_type>,<addr>,<timeout_sec>``
:Query:     not supported

``addr_type``: ``0`` = public, ``1`` = random. ``timeout_sec``: 1–255 s.
Returns ``OK`` immediately; connection result arrives as ``+EVTBLEGAPCONN:``.
Only one pending connection attempt is allowed at a time.

.. code-block:: text

   AT+BLEGAPCREATECONN=1,C00102030405,30
   OK
   +EVTBLEGAPCONN:0,1,C00102030405

AT+BLEGAPCANCELCREATECONN — Cancel Pending Connection
*****************************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGAPCANCELCREATECONN``
:Depends:   auto-selected by ``CONFIG_AT_CMD_BLEGAPCREATECONN``
:Execute:   ``AT+BLEGAPCANCELCREATECONN=``
:Query:     not supported

Cancels an in-progress ``AT+BLEGAPCREATECONN`` attempt.

.. note::
   Returns ``ERR`` if no connection creation is pending (``AT_ERR_BLE_EINVAL``).

.. code-block:: text

   AT+BLEGAPCREATECONN=1,C00102030405,30
   OK
   AT+BLEGAPCANCELCREATECONN=
   OK
