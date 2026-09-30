.. _at_cmd_ble_peripheral:

BLE Peripheral Commands
#######################

See :ref:`at_cmd_format` for command syntax.

AT+BLEGAPDEVNAME — GAP Device Name
***********************************

:Kconfig:   ``CONFIG_AT_CMD_BLEGAPDEVNAME``
:Execute:   ``AT+BLEGAPDEVNAME=<name>``
:Query:     ``AT+BLEGAPDEVNAME?``
:Response:  ``+BLEGAPDEVNAME:<name>``
:Callback:  ``devname_set_cb`` (``CONFIG_AT_CMD_BLEGAPDEVNAME_CB``)

Sets or queries the BLE GAP device name via ``bt_set_name()`` / ``bt_get_name()``.

.. list-table::
   :widths: 15 10 75
   :header-rows: 1

   * - Parameter
     - Type
     - Description
   * - ``name``
     - string
     - New device name. Max length: ``CONFIG_BT_DEVICE_NAME_MAX`` characters.
       Returns ``ERR`` if the length is exceeded.

.. code-block:: text

   AT+BLEGAPDEVNAME=MySensor
   OK
   AT+BLEGAPDEVNAME?
   +BLEGAPDEVNAME:MySensor
   OK

AT+BLEADVENABLE — Start / Stop Advertising
******************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEADVENABLE``
:Execute:   ``AT+BLEADVENABLE=<adv_idx>,<ON|OFF>``
:Query:     ``AT+BLEADVENABLE?``
:Response:  ``+BLEADVENABLE:<adv_idx>,<enabled>``

.. code-block:: text

   AT+BLEADVENABLE=0,ON
   OK
   AT+BLEADVENABLE?
   +BLEADVENABLE:0,1
   OK

AT+BLEADVSETID — Assign BT Identity to Advertising Instance
***********************************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEADVSETID``
:Execute:   ``AT+BLEADVSETID=<adv_idx>,<bt_id>``
:Query:     ``AT+BLEADVSETID?``

Must be called before ``AT+BLEADVENABLE`` when using a non-default identity.

.. code-block:: text

   AT+BLEADVSETID=0,1
   OK

AT+BLEADVLEGACYPARM — Legacy Advertising Parameters
***************************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEADVLEGACYPARM``
:Execute:   ``AT+BLEADVLEGACYPARM=<adv_idx>,<intv_min>,<intv_max>,<duration>``
:Query:     ``AT+BLEADVLEGACYPARM?``

Intervals are in units of 0.625 ms (range 32–16384). ``duration`` is in units of 10 ms; ``0`` = infinite.

.. code-block:: text

   AT+BLEADVLEGACYPARM=0,160,160,0
   OK

AT+BLEEXTADVPARM — Extended Advertising Parameters
**************************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEEXTADVPARM`` (requires ``CONFIG_BT_EXT_ADV``)
:Execute:   ``AT+BLEEXTADVPARM=<adv_idx>,<intv_min>,<intv_max>,<duration>,<primary_phy>``
:Query:     ``AT+BLEEXTADVPARM?``

``primary_phy``: ``1`` = 1M, ``2`` = 2M, ``3`` = Coded S=8, ``4`` = Coded S=2.

.. code-block:: text

   AT+BLEEXTADVPARM=0,160,160,0,1
   OK

AT+BLEADVDATA — Set Advertisement Payload
*****************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEADVDATA``
:Execute:   ``AT+BLEADVDATA=<adv_idx>,<data_hex>``
:Query:     ``AT+BLEADVDATA?``

.. code-block:: text

   AT+BLEADVDATA=0,020106
   OK

AT+BLESCANRSPDATA — Set Scan-Response Payload
*********************************************

:Kconfig:   ``CONFIG_AT_CMD_BLESCANRSPDATA``
:Execute:   ``AT+BLESCANRSPDATA=<adv_idx>,<data_hex>``
:Query:     ``AT+BLESCANRSPDATA?``

.. code-block:: text

   AT+BLESCANRSPDATA=0,020106
   OK

AT+BLEADVTXPWR — Advertising TX Power
**************************************

:Kconfig:   ``CONFIG_AT_CMD_BLEADVTXPWR``
:Execute:   not supported — returns ``ERR``
:Query:     ``AT+BLEADVTXPWR?``
:Response:  ``+BLEADVTXPWR:<adv_idx>,<tx_power_dBm>`` (one line per active advertising set)

.. note::
   Query requires ``CONFIG_BT_EXT_ADV``. Without it, returns ``ERR`` (not supported).

.. note::
   Query requires at least one advertising set to be created (``AT+BLEADVENABLE=<idx>,ON``).
   Returns ``ERR`` if no advertising set exists yet.

.. code-block:: text

   AT+BLEADVENABLE=0,ON
   OK
   AT+BLEADVTXPWR?
   +BLEADVTXPWR:0,-3
   OK
