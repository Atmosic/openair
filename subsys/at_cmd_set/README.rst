.. _at_cmd_set:

AT Command Set — Subsystem Reference
####################################

Overview
********

The ``at_cmd_set`` subsystem provides a collection of AT commands for controlling Bluetooth LE
operation on Atmosic SoCs running Zephyr RTOS. Each command is implemented in its own ``.c``
file and registered via the ``AT_COMMAND()`` macro. Commands are enabled individually through
Kconfig so unused commands are excluded from the binary.

Role-Based Command Bundles
==========================

Selecting a master role symbol automatically enables a suite of related commands as
``default y``. Individual commands can still be overridden in ``prj.conf``.

``CONFIG_AT_CMD_PERIPHERAL`` — Peripheral / advertiser role
-----------------------------------------------------------

.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Command
     - Description
   * - ``AT+BLEADVENABLE``
     - Start / stop advertising
   * - ``AT+BLEADVSETID``
     - Assign BT identity to an advertising instance
   * - ``AT+BLEADVLEGACYPARM``
     - Legacy advertising parameters
   * - ``AT+BLEEXTADVPARM``
     - Extended advertising parameters (requires ``CONFIG_BT_EXT_ADV``)
   * - ``AT+BLEADVDATA``
     - Set advertisement payload
   * - ``AT+BLESCANRSPDATA``
     - Set scan-response payload
   * - ``AT+BLEADVTXPWR``
     - Set advertising TX power


``CONFIG_AT_CMD_CENTRAL`` — Central / observer role
---------------------------------------------------

.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Command
     - Description
   * - ``AT+BLESCANENABLE``
     - Start / stop scanning
   * - ``AT+BLESCANFILMAC``
     - Controller MAC-address filter (Filter Accept List)
   * - ``AT+BLESCANFILRSSI``
     - RSSI threshold filter
   * - ``AT+BLEGAPCREATECONN``
     - Initiate a connection
   * - ``AT+BLEGAPCANCELCREATECONN``
     - Cancel a pending connection attempt
   * - ``+EVTBLEGAPADVRPT``
     - Advertisement report event

``CONFIG_AT_CMD_GATT_DFT_SERVER`` — Default GATT server (auto-selected by ``CONFIG_AT_CMD_PERIPHERAL``)
------------------------------------------------------------------------------------------------------

.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Command
     - Description
   * - ``AT+BLEGATTDFTSERVER``
     - Enable / disable the runtime-configurable default GATT server
   * - ``AT+BLEGATTDFTSERVICE``
     - Configure the default service UUID and security properties
   * - ``AT+BLEGATTDFTCHAR1``
     - Configure Characteristic 1 (TRX) UUID and security properties
   * - ``AT+BLEGATTDFTCHAR2``
     - Configure Characteristic 2 (TRX2) UUID and security properties
   * - ``AT+BLEGATTDFTCHAR1VAL``
     - Set / query Characteristic 1 pre-set read value
   * - ``AT+BLEGATTDFTCHAR2VAL``
     - Set / query Characteristic 2 pre-set read value
   * - ``AT+BLEGATTTOBLE``
     - Send notification or indication to a connected peer

``CONFIG_AT_CMD_GATT_CLIENT`` — GATT client (auto-selected by ``CONFIG_AT_CMD_CENTRAL``)
-----------------------------------------------------------------------------------------

.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Command
     - Description
   * - ``AT+BLEGATTDISCSVCS``
     - Discover all primary services by handle range
   * - ``AT+BLEGATTDISCSVC``
     - Discover service by UUID
   * - ``AT+BLEGATTDISCCHARS``
     - Discover all characteristics by handle range
   * - ``AT+BLEGATTDISCCHAR``
     - Discover characteristic by UUID
   * - ``AT+BLEGATTDISCDESCS``
     - Discover descriptors by handle range
   * - ``AT+BLEGATTRD``
     - Read characteristic value
   * - ``AT+BLEGATTWR``
     - Write characteristic value (with response)
   * - ``AT+BLEGATTWRWO``
     - Write characteristic value (without response)
   * - ``AT+BLEGATTWRCCCD``
     - Subscribe / unsubscribe via CCCD write
   * - ``+BLEGATTNOTI``
     - Notification received event
   * - ``+BLEGATTINDI``
     - Indication received event


Connection commands — enabled automatically when ``CONFIG_PERIPHERAL`` or ``CONFIG_CENTRAL`` is selected
------------------------------------------------------------------------------------------

.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Command
     - Description
   * - ``AT+BLEGAPDISCONNECT``
     - Gracefully disconnect
   * - ``AT+BLEGAPGETCONNSTAT``
     - Query connection parameters
   * - ``AT+BLEGAPGETPEERINFO``
     - Query peer identity and security level
   * - ``AT+BLEGAPGETRSSI``
     - Read link RSSI
   * - ``AT+BLECONNTXPWR``
     - Set / query connection TX power
   * - ``AT+BLEGATTMTUEXCHGREQ``
     - Initiate ATT MTU exchange
   * - ``AT+BLEGATTMTUGET``
     - Query current ATT MTU
   * - ``+EVTBLEGAPCONN``
     - Connection-established event
   * - ``+EVTBLEGAPDISCONN``
     - Disconnection event
   * - ``+EVTBLEGAPLINKINFO``
     - Remote LE features event
   * - ``+EVTBLEGAPPAR``
     - Connection parameter update event
   * - ``+EVTBLEGATTMTUEXCHANGE``
     - GATT MTU exchange event
   * - ``+EVTBLEGATTMTUEXCHGREQ``
     - GATT MTU exchange request result event

``CONFIG_AT_CMD_TAG_SET`` — Tracking tag role
---------------------------------------------

.. warning::
   ``CONFIG_AT_CMD_TAG_SET`` depends on ``CONFIG_STF_TAG`` || ``CONFIG_FMNA_TAG`` || ``CONFIG_FHN_TAG`` || ``CONFIG_ATM_AT_CMDTEST``.


.. list-table::
   :header-rows: 1
   :widths: 30 70

   * - Command
     - Description
   * - ``AT+TAGINFO``
     - Query firmware version and compiled-in protocols
   * - ``AT+TAGMODE``
     - Select active tracking protocol(s)
   * - ``AT+TAGBATTERY``
     - Query battery level
   * - ``AT+TAGSTART``
     - Start the tag BLE stack
   * - ``AT+TAGRESET``
     - Reboot or factory-reset
   * - ``+EVTTAGSTATE``
     - Report tag state event
   * - ``+EVTTAGERROR``
     - Tag error events

``AT+TAGSTFIND`` and ``AT+TAGDFU`` are opt-in; they require their own Kconfig symbols even
when ``CONFIG_AT_CMD_TAG_SET`` is enabled.

Command Groups
==============

.. list-table::
   :header-rows: 1
   :widths: 35 65

   * - Command Group
     - Reference
   * - AT Command Format
     - :ref:`at_cmd_format`
   * - System Commands
     - :ref:`at_cmd_sys`
   * - Serial DFU Commands
     - :ref:`at_cmd_sys_dfu`
   * - BLE Peripheral Commands
     - :ref:`at_cmd_ble_peripheral`
   * - BLE Central Commands
     - :ref:`at_cmd_ble_central`
   * - BLE Common Commands
     - :ref:`at_cmd_ble_common`
   * - BLE Events
     - :ref:`at_cmd_ble_events`
   * - BLE GATT Server Commands (Default + Dynamic)
     - :ref:`at_cmd_gatt`
   * - BLE GATT Client Commands
     - :ref:`at_cmd_gatt_client`
   * - Tag Commands
     - :ref:`at_cmd_tag`

Typical Two-Device Flow
***********************

A minimal central + peripheral exchange that exercises advertising, scanning, connection
and disconnection:

**Peripheral side** (``CONFIG_AT_CMD_PERIPHERAL=y``):

.. code-block:: text

   AT+BLEADVLEGACYPARM=0,160,160,0
   OK
   AT+BLEADVDATA=0,020106
   OK
   AT+BLEADVENABLE=0,ON
   OK
   +EVTBLEGAPCONN:0,1,A00102030405
   +EVTBLEGAPLINKINFO:0,2F49010580010000
   +EVTBLEGAPPAR:0,24,0,42
   +EVTBLEGAPDISCONN:0,22

**Central side** (``CONFIG_AT_CMD_CENTRAL=y``):

.. code-block:: text

   AT+BLESCANENABLE=ON
   OK
   +EVTBLEGAPADVRPT:0,1,C00102030405,-55,3,020106
   AT+BLESCANENABLE=OFF
   OK
   AT+BLEGAPCREATECONN=1,C00102030405,30
   OK
   +EVTBLEGAPCONN:0,1,C00102030405
   +EVTBLEGAPLINKINFO:0,2F49010580010000
   AT+BLEGAPGETRSSI=0
   +BLEGAPGETRSSI:-55
   OK
   AT+BLEGAPDISCONNECT=0
   OK
   +EVTBLEGAPDISCONN:0,22

Kconfig Summary
***************

.. list-table::
   :header-rows: 1
   :widths: 35 65

   * - Kconfig symbol
     - Purpose
   * - ``CONFIG_AT_CMD_SET``
     - Master enable for the AT command subsystem
   * - ``CONFIG_AT_CMD_PERIPHERAL``
     - Enable the peripheral/advertiser command bundle
   * - ``CONFIG_AT_CMD_CENTRAL``
     - Enable the central/observer command bundle
   * - ``CONFIG_AT_CMD_TAG_SET``
     - Enable the tracking-tag command bundle
   * - ``CONFIG_AT_CMD_SET_EVENTS``
     - Master enable for AT events
   * - ``CONFIG_AT_CMD_TAG_SET_EVENTS``
     - Enable tag-related AT events
   * - ``CONFIG_AT_CMD_SYSBDADDR``
     - ``AT+SYSBDADDR``
   * - ``CONFIG_AT_CMD_SYSRESET``
     - ``AT+SYSRESET``
   * - ``CONFIG_AT_CMD_SYSSTORAGE``
     - ``AT+SYSSTORAGE``
   * - ``CONFIG_AT_CMD_SYSDFU``
     - ``AT+SYSDFU``, ``AT+SYSSWITCHBANK`` (requires ``CONFIG_ATM_VENDOR_DFU``)
   * - ``CONFIG_AT_CMD_SYSMKBANKGOOD``
     - ``AT+SYSMKBANKGOOD`` (requires ``CONFIG_BOOTLOADER_MCUBOOT``)
   * - ``CONFIG_AT_CMD_BLEADVENABLE``
     - ``AT+BLEADVENABLE``
   * - ``CONFIG_AT_CMD_BLEADVSETID``
     - ``AT+BLEADVSETID``
   * - ``CONFIG_AT_CMD_BLEADVLEGACYPARM``
     - ``AT+BLEADVLEGACYPARM``
   * - ``CONFIG_AT_CMD_BLEEXTADVPARM``
     - ``AT+BLEEXTADVPARM`` (requires ``CONFIG_BT_EXT_ADV``)
   * - ``CONFIG_AT_CMD_BLEADVDATA``
     - ``AT+BLEADVDATA``
   * - ``CONFIG_AT_CMD_BLESCANRSPDATA``
     - ``AT+BLESCANRSPDATA``
   * - ``CONFIG_AT_CMD_BLEADVTXPWR``
     - ``AT+BLEADVTXPWR``
   * - ``CONFIG_AT_CMD_BLESCANENABLE``
     - ``AT+BLESCANENABLE``
   * - ``CONFIG_AT_CMD_BLESCANFILMAC``
     - ``AT+BLESCANFILMAC``
   * - ``CONFIG_AT_CMD_BLESCANFILRSSI``
     - ``AT+BLESCANFILRSSI``
   * - ``CONFIG_AT_CMD_BLEGAPCREATECONN``
     - ``AT+BLEGAPCREATECONN``
   * - ``CONFIG_AT_CMD_BLEGAPCANCELCREATECONN``
     - ``AT+BLEGAPCANCELCREATECONN``
   * - ``CONFIG_AT_CMD_BLEGAPDISCONNECT``
     - ``AT+BLEGAPDISCONNECT``
   * - ``CONFIG_AT_CMD_BLEGAPGETCONNSTAT``
     - ``AT+BLEGAPGETCONNSTAT``
   * - ``CONFIG_AT_CMD_BLEGAPGETPEERINFO``
     - ``AT+BLEGAPGETPEERINFO``
   * - ``CONFIG_AT_CMD_BLEGAPGETRSSI``
     - ``AT+BLEGAPGETRSSI``
   * - ``CONFIG_AT_CMD_BLECONNTXPWR``
     - ``AT+BLECONNTXPWR``
   * - ``CONFIG_AT_CMD_BLEGATTMTUEXCHGREQ``
     - ``AT+BLEGATTMTUEXCHGREQ``
   * - ``CONFIG_AT_CMD_BLEGATTMTUGET``
     - ``AT+BLEGATTMTUGET``
   * - ``CONFIG_AT_CMD_GATT_DFT_SERVER``
     - Default GATT server infrastructure (auto-selected by ``CONFIG_AT_CMD_PERIPHERAL``)
   * - ``CONFIG_AT_CMD_BLEGATTDFTSERVER``
     - ``AT+BLEGATTDFTSERVER``
   * - ``CONFIG_AT_CMD_BLEGATTDFTSERVICE``
     - ``AT+BLEGATTDFTSERVICE``
   * - ``CONFIG_AT_CMD_BLEGATTDFTCHAR1``
     - ``AT+BLEGATTDFTCHAR1``
   * - ``CONFIG_AT_CMD_BLEGATTDFTCHAR2``
     - ``AT+BLEGATTDFTCHAR2``
   * - ``CONFIG_AT_CMD_BLEGATTDFTCHAR1VAL``
     - ``AT+BLEGATTDFTCHAR1VAL``
   * - ``CONFIG_AT_CMD_BLEGATTDFTCHAR2VAL``
     - ``AT+BLEGATTDFTCHAR2VAL``
   * - ``CONFIG_AT_CMD_BLEGATTTOBLE``
     - ``AT+BLEGATTTOBLE``
   * - ``CONFIG_AT_CMD_GATT_CLIENT``
     - GATT client infrastructure (auto-selected by ``CONFIG_AT_CMD_CENTRAL``)
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
   * - ``CONFIG_AT_EVT_BLEGAPADVRPT``
     - ``+EVTBLEGAPADVRPT``
   * - ``CONFIG_AT_EVT_BLEGAPCONN``
     - ``+EVTBLEGAPCONN``
   * - ``CONFIG_AT_EVT_BLEGAPDISCONN``
     - ``+EVTBLEGAPDISCONN``
   * - ``CONFIG_AT_EVT_BLEGAPLINKINFO``
     - ``+EVTBLEGAPLINKINFO``
   * - ``CONFIG_AT_EVT_BLEGAPPAR``
     - ``+EVTBLEGAPPAR``
   * - ``CONFIG_AT_EVT_BLEGATTMTUEXCHANGE``
     - ``+EVTBLEGATTMTUEXCHANGE``
   * - ``CONFIG_AT_EVT_BLEGATTMTUEXCHGREQ``
     - ``+EVTBLEGATTMTUEXCHGREQ``
   * - ``CONFIG_AT_CMD_TAGINFO``
     - ``AT+TAGINFO``
   * - ``CONFIG_AT_CMD_TAGMODE``
     - ``AT+TAGMODE``
   * - ``CONFIG_AT_CMD_TAGBATTERY``
     - ``AT+TAGBATTERY``
   * - ``CONFIG_AT_CMD_TAGSTART``
     - ``AT+TAGSTART``
   * - ``CONFIG_AT_CMD_TAGRESET``
     - ``AT+TAGRESET``
   * - ``CONFIG_AT_CMD_TAGSTFIND``
     - ``AT+TAGSTFIND``
   * - ``CONFIG_AT_CMD_TAGDFU``
     - ``AT+TAGDFU``
   * - ``CONFIG_AT_EVT_TAGSTATE``
     - ``+EVTTAGSTATE``
