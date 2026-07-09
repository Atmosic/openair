.. _at_cmd_sys:

System Commands
###############

See :ref:`at_cmd_format` for command syntax.

AT+SYSFUNCPIN — GPIO Function Pin Control
*****************************************

:Kconfig:   ``CONFIG_AT_CMD_SYSFUNCPIN``
:Depends:   ``CONFIG_GPIO``
:Execute:   ``AT+SYSFUNCPIN=<io>,<direction>,<signal>``
:Query:     ``AT+SYSFUNCPIN?``
:Response:  ``+SYSFUNCPIN:<io>,<direction>,<signal>``
:Event:     ``+EVTSYSFUNCPIN:<io>,<reason>`` — emitted when an input interrupt fires

Configures a GPIO pin (on ``gpio0``) as a driven output or a monitored input with
interrupt-based event notification.

.. list-table::
   :widths: 15 10 75
   :header-rows: 1

   * - Parameter
     - Range
     - Description
   * - ``io``
     - 0–255
     - GPIO pin number on ``gpio0``.
   * - ``direction``
     - 0–1
     - ``0`` = input, ``1`` = output.
   * - ``signal``
     - 0–4
     - For **output**: ``0`` = drive low, ``1`` = drive high.
       For **input**: ``0`` = interrupt on level-low, ``1`` = level-high,
       ``2`` = rising edge, ``3`` = falling edge, ``4`` = pull-up (no interrupt).

.. note::
   ``signal=4`` (pull-up) is **input only**. Combining ``direction=1`` with
   ``signal=4`` is rejected with ``ERR``.

.. note::
   When an input interrupt fires, a ``+EVTSYSFUNCPIN:<io>,<reason>`` unsolicited
   event is emitted asynchronously. The interrupt is automatically disabled after
   firing; re-issue the execute command to re-arm it.

.. note::
   The ``<reason>`` field in ``+EVTSYSFUNCPIN`` carries the trigger cause as defined
   by ``at_cmd_sysfuncpin_reason_t`` in ``at_cmd_set.h``:

   .. list-table::
      :widths: 10 90
      :header-rows: 1

      * - Value
        - Meaning
      * - ``4``
        - ``AT_SYSFUNCPIN_REASON_INTR`` — GPIO interrupt fired.

.. code-block:: text

   AT+SYSFUNCPIN=10,1,0
   OK
   AT+SYSFUNCPIN=10,1,1
   OK
   AT+SYSFUNCPIN=9,0,2
   OK
   # <rising edge on P9 fires>
   +EVTSYSFUNCPIN:9,4
   AT+SYSFUNCPIN?
   +SYSFUNCPIN:9,0,2
   OK

AT+SYSPM — System Power Mode
*****************************

:Kconfig:   ``CONFIG_AT_CMD_SYSPM``
:Depends:   ``CONFIG_PM``, ``CONFIG_GPIO``
:Execute:   ``AT+SYSPM=<mode>,<io>,<wakeup_level>``
:Query:     ``AT+SYSPM?``
:Response:  ``+SYSPM:<mode>,<io>,<wakeup_level>``

Enters the device into a low-power state. Currently only hibernation
(``mode=1``) is supported. The device does **not return** from this call — it
resets on wakeup via the specified GPIO pin.

.. list-table::
   :widths: 15 10 75
   :header-rows: 1

   * - Parameter
     - Range
     - Description
   * - ``mode``
     - 1
     - Power mode. ``1`` = hibernation (only value currently accepted).
   * - ``io``
     - 0–255
     - GPIO pin number (on ``gpio0``) used as the wakeup source.
   * - ``wakeup_level``
     - 0–1
     - ``0`` = wake on level-low, ``1`` = wake on level-high.

.. warning::
   ``AT+SYSPM=1,...`` places the device into deep hibernation immediately after
   returning ``OK``. The firmware does not resume from the point of the call —
   the device performs a cold reset on wakeup. Do **not** issue this command
   during automated testing unless hardware recovery is available.

.. code-block:: text

   AT+SYSPM=1,5,1
   OK
   # <device hibernates; press Button0 / P5 HIGH to wake>
   # <device cold-resets on wakeup>

AT+SYSUARTBR — UART Baud Rate
******************************

:Kconfig:   ``CONFIG_AT_CMD_SYSUARTBR``
:Depends:   ``CONFIG_UART_USE_RUNTIME_CONFIGURE``
:Execute:   ``AT+SYSUARTBR=<baud_rate>,<defer_apply_cs>``
:Query:     ``AT+SYSUARTBR?``
:Response:  ``+SYSUARTBR:<baud_rate>``

Changes the baud rate of the console UART at runtime. ``OK`` is sent at the
**current** baud rate before the change is applied, giving the host time to
switch its serial port within the defer window.

.. list-table::
   :widths: 20 15 65
   :header-rows: 1

   * - Parameter
     - Type
     - Description
   * - ``baud_rate``
     - decimal
     - New baud rate. Must be one of: ``19200``, ``38400``, ``57600``,
       ``115200``, ``230400``, ``460800``. Any other value returns ``ERR``.
   * - ``defer_apply_cs``
     - 1–255
     - Delay before the baud rate is applied, in **centiseconds** (1 cs = 10 ms).
       The host must switch its own serial port to the new baud rate within
       this window.

.. note::
   Query returns the currently active baud rate, not the pending one.
   On power-up, the baud rate is read from the hardware UART configuration;
   if unavailable, it defaults to ``115200``.

.. code-block:: text

   AT+SYSUARTBR=115200,10
   OK
   # <switch host serial port to 115200 within 100 ms>

AT+SYSUARTFC — UART Flow Control
*********************************

:Kconfig:   ``CONFIG_AT_CMD_SYSUARTFC``
:Depends:   ``CONFIG_UART_USE_RUNTIME_CONFIGURE``
:Execute:   ``AT+SYSUARTFC=<action>``
:Query:     ``AT+SYSUARTFC?``
:Response:  ``+SYSUARTFC:<action>``

Enables or disables RTS/CTS hardware flow control on the console UART at
runtime.

.. list-table::
   :widths: 15 10 75
   :header-rows: 1

   * - Parameter
     - Range
     - Description
   * - ``action``
     - 0–1
     - ``0`` = disable flow control (``UART_CFG_FLOW_CTRL_NONE``),
       ``1`` = enable RTS/CTS (``UART_CFG_FLOW_CTRL_RTS_CTS``).

.. warning::
   Enabling RTS/CTS (``action=1``) requires the CTS and RTS lines to be
   physically wired on the board. Sending ``AT+SYSUARTFC=1`` on a board without
   those lines connected will stall UART TX indefinitely.

.. code-block:: text

   AT+SYSUARTFC=0
   OK
   AT+SYSUARTFC?
   +SYSUARTFC:0
   OK

System Command Error Codes
**************************

The following application error codes (returned in the ``ERR`` response payload)
are defined in ``at_cmd_set.h`` and may be returned by the system commands above.

.. list-table::
   :widths: 12 20 68
   :header-rows: 1

   * - Code
     - Constant
     - Description
   * - ``0x50``
     - ``AT_ERR_GPIO_NOT_READY``
     - GPIO device (``gpio0``) is not ready. Used by ``SYSFUNCPIN`` and ``SYSPM``.
   * - ``0x51``
     - ``AT_ERR_GPIO_CONFIG``
     - ``gpio_pin_configure()`` or ``gpio_pin_interrupt_configure()`` failed.
       Used by ``SYSFUNCPIN`` and ``SYSPM``.
   * - ``0x62``
     - ``AT_ERR_SYS_UART_NOT_READY``
     - Console UART device is not ready. Used by ``SYSUARTBR`` and ``SYSUARTFC``.
   * - ``0x63``
     - ``AT_ERR_SYS_UART_CONFIG``
     - ``uart_configure()`` or ``uart_config_get()`` failed. Used by ``SYSUARTFC``.

AT+SYSBDADDR — Bluetooth Device Address
****************************************

:Kconfig:   ``CONFIG_AT_CMD_SYSBDADDR``
:Execute:   ``AT+SYSBDADDR=<bt_id>,<addr(6B)>`` — ``bt_id`` range: 1 to ``CONFIG_BT_ID_MAX`` − 1
:Query:     ``AT+SYSBDADDR?``
:Response:  ``+SYSBDADDR:<bt_id0>,<addr0>,<bt_id1>,<addr1>,...`` (all identities in one response)

Sets the random static identity address for a non-default BT identity.
Query returns all configured identities.

.. note::
   ``bt_id = 0`` (default identity) is **not supported** for execute — returns ``ERR``.
   Valid range is 1 to ``CONFIG_BT_ID_MAX`` − 1. Requires ``CONFIG_BT_ID_MAX > 1``.

.. note::
   ``<addr>`` must be a valid random static identity address. Non-identity addresses
   are rejected with ``ERR``.

.. note::
   Cannot be set (execute) while advertising is active for the given ``bt_id`` or while
   any connection is active — returns ``ERR``. Query is always allowed.

.. code-block:: text

   AT+SYSBDADDR=1,C21122334455
   OK
   AT+SYSBDADDR?
   +SYSBDADDR:0,FFFFFFFFFFFF,1,C21122334455
   OK

AT+SYSRESET — System Reset
**************************

:Kconfig:   ``CONFIG_AT_CMD_SYSRESET``
:Execute:   ``AT+SYSRESET=<type>`` — ``0`` = warm, ``1`` = cold
:Query:     not supported

.. code-block:: text

   AT+SYSRESET=0
   OK

AT+SYSSTORAGE — NVS Key-Value Storage
*************************************

:Kconfig:   ``CONFIG_AT_CMD_SYSSTORAGE``
:Depends:   ``CONFIG_SETTINGS`` (application must provide a settings backend)
:Execute:   ``AT+SYSSTORAGE=<GET|SAVE|DEL>,<key>,<value>``
:Query:     ``AT+SYSSTORAGE?``
:Response:  ``+SYSSTORAGE:<READY|NOT_READY>`` (query); ``+SYSSTORAGE:<key>,<value>`` (GET)

Query reports whether the settings backend is ready. Execute returns ``ERR`` if the
backend is not ready — use the query to check readiness before issuing GET/SAVE/DEL.

.. code-block:: text

   AT+SYSSTORAGE?
   +SYSSTORAGE:READY
   OK
   AT+SYSSTORAGE=SAVE,mykey,hello
   OK
   AT+SYSSTORAGE=GET,mykey,
   +SYSSTORAGE:mykey,hello
   OK
   AT+SYSSTORAGE=DEL,mykey,
   OK

AT+SYSUARTRAW — Bounded UART/BLE Raw Data Transfer
****************************************************

:Kconfig:   ``CONFIG_AT_CMD_SYSUARTRAW``
:Depends:   ``CONFIG_BT_GATT_DYNAMIC_DB``, active BLE connection
:Execute:   ``AT+SYSUARTRAW=<conn_idx>,<att_idx>,<direction>,<length>``
:Query:     ``AT+SYSUARTRAW?``
:Response:  ``+SYSUARTRAW:<conn_idx>,<att_idx>,<direction>,<length>``

Initiates a single-shot bounded raw data transfer between the UART channel and a
connected BLE peer. The system leaves AT command mode for exactly ``<length>`` bytes,
then automatically returns to AT command mode.

A built-in GATT service (UUID ``9E940001-E8D4-4AB3-8A03-F012DFD53BA0``) is
dynamically registered on execute and unregistered when the transfer completes.

**Parameters**

.. list-table::
   :widths: 15 10 75
   :header-rows: 1

   * - Parameter
     - Type
     - Description
   * - ``conn_idx``
     - decimal
     - BLE connection index (0 to ``CONFIG_BT_MAX_CONN`` − 1).
       Returns ``ERR`` if no active connection exists at this index.
   * - ``att_idx``
     - decimal
     - GATT attribute index within the built-in bridge service used as the
       data endpoint (write target / notify source).
   * - ``direction``
     - decimal
     - ``0`` = Host → Atmosic: UART bytes are collected and forwarded to the
       BLE peer via GATT notifications (UART→BLE).
       ``1`` = Atmosic → Host: data written by the BLE peer to the data
       characteristic is forwarded out on the UART (BLE→UART).
   * - ``length``
     - decimal
     - Number of bytes to transfer before automatically returning to AT mode.

**Direction 0 — UART → BLE**

After ``OK``, the UART channel captures raw bytes instead of AT commands.
Each byte (or batch, up to ATT MTU − 3) is forwarded to the BLE peer via
GATT notification. The peer must have subscribed to notifications on the data
characteristic (CCCD enabled) before data is sent; bytes received while the
peer is not subscribed are discarded. After exactly ``<length>`` bytes have been
sent, the system unregisters the GATT service and returns to AT mode.

**Direction 1 — BLE → UART**

After ``OK``, the AT command parser remains active on the UART. Data written by
the BLE peer to the GATT data characteristic is forwarded byte-for-byte to the
UART output. After exactly ``<length>`` bytes have been received from the peer,
the GATT service is unregistered and the transfer is complete.

.. note::
   A valid active BLE connection at ``conn_idx`` is required. The command returns
   ``ERR`` immediately if no connection exists at that index.

.. note::
   For direction ``0``, the BLE peer must enable notifications on the data
   characteristic (CCCD) before the transfer begins, or UART bytes will be dropped.

.. note::
   **ISR integration required for direction 0.** The UART driver's interrupt service
   routine must forward received bytes into the raw bridge. Two public APIs are
   provided in ``at_cmd_set.h`` (guarded by ``CONFIG_AT_CMD_SYSUARTRAW``):

   - ``bool at_cmd_sysuartraw_is_active(void)`` — returns ``true`` while a
     direction-0 transfer is in progress. Poll this in the UART RX ISR.
   - ``void at_cmd_sysuartraw_rx_byte(uint8_t byte)`` — enqueues the byte into
     the internal ring buffer and schedules BLE notification via the system work
     queue. Call only when ``at_cmd_sysuartraw_is_active()`` is ``true``.

   Without this hook, UART bytes are processed by the AT command parser instead
   of being forwarded over BLE.

.. code-block:: text

   # Direction 0: send 12 bytes from UART to BLE peer
   AT+SYSUARTRAW=0,0,0,12
   OK
   # <host sends 12 raw bytes on UART>
   # <system automatically returns to AT mode after 12 bytes>

   # Direction 1: receive 8 bytes from BLE peer to UART
   AT+SYSUARTRAW=0,0,1,8
   OK
   # <BLE peer writes 8 bytes to the data characteristic>
   # <bytes appear on UART; system returns to AT mode after 8 bytes>

   # Query current transfer state
   AT+SYSUARTRAW?
   +SYSUARTRAW:0,0,0,12
   OK
