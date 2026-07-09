.. _at_cmd_set-sample:

Subsys: AT Command Set
######################

Overview
********

This sample demonstrates a UART-based BLE AT command interface on Atmosic
devices. The device receives ``AT+<COMMAND>`` strings over ``uart0``, processes
them in a work-queue thread, and sends responses back over the same port.

On startup the sample initializes Bluetooth, restores persistent identity
settings from NVS, and prints a ready banner on the console (``uart1``).
A host — serial terminal or automated test script — can then control BLE
advertising, system settings, and (optionally) scanning and connections by
issuing AT commands.

Three AT command types are supported:

- **Query** (``AT+CMD?``) — read the current value or state.
- **Exec** (``AT+CMD=<params>``) — set a value or trigger an action.
- **Test** (``AT+CMD=?``) — display the command's parameter format string.

The default configuration (``prj.conf``) enables the peripheral-role command
bundle (``CONFIG_AT_CMD_PERIPHERAL=y``), which covers advertising control and
system commands. Central-role commands (scan, connection management) are
available by adding ``CONFIG_AT_CMD_CENTRAL=y``.

See :ref:`at_cmd_set` for the full AT command reference.

Requirements
************

Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

Building and Running
********************

This sample is built from ``openair/samples/subsys/at_cmd_set``.

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/subsys/at_cmd_set --sysbuild -T samples.subsys.at_cmd_set.atm

Build with MCUBoot:

.. code-block:: bash

   west build -p always -b <BOARD> openair/samples/subsys/at_cmd_set --sysbuild -T samples.subsys.at_cmd_set.atm.mcuboot

Flash command:

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_flash]

Configuration
*************

Key Kconfig options:

.. list-table::
   :header-rows: 1
   :widths: 40 60

   * - Option
     - Description
   * - ``CONFIG_ATM_AT_CMD=y``
     - Enable the Atmosic AT command library (required).
   * - ``CONFIG_AT_CMD_SET=y``
     - Enable the built-in advertising and system command set.
   * - ``CONFIG_AT_CMD_PERIPHERAL=y``
     - Enable peripheral-role (advertising) commands.
   * - ``CONFIG_AT_CMD_CENTRAL=y``
     - Enable central-role (scan and connection) commands.
   * - ``CONFIG_ATM_AT_CMDTEST=y``
     - Enable the ``AT+TESTCMD`` echo-back test command (for automated testing).

Hardware Configuration
======================

The sample uses two UARTs:

- **uart0** — AT command input/output at 115 200 baud (configured in ``app.overlay``).
- **uart1** — Console/debug output (board default).

When a single serial port is used (e.g. on boards that expose one CDC-ACM
port), both channels share the same port.

Testing
*******

The sample ships with a Pytest harness under ``pytest/``.  Four test groups
are defined:

.. list-table::
   :header-rows: 1
   :widths: 20 25 55

   * - Marker
     - Twister target
     - Description
   * - ``basic``
     - ``samples.subsys.at_cmd_set.atm.pytest``
     - Boot-ready check, ``AT+LISTCMDS?``, and invalid-command handling.
   * - ``adv``
     - ``samples.subsys.at_cmd_set.atm.pytest.adv``
     - Advertising enable/disable, TX power, adv data, scan response, adv set ID.
   * - ``system``
     - ``samples.subsys.at_cmd_set.atm.pytest.system``
     - BD address query/set, NVS storage save/get, and ``AT+SYSRESET``.
   * - ``scan_conn``
     - ``samples.subsys.at_cmd_set.atm.pytest.scan_conn``
     - BLE scanning, RSSI/MAC filter exclusivity, and connection-slot commands.

Single-port mode (console and AT commands on the same port):

.. code-block:: bash

   west twister -p <BOARD> -T openair/samples/subsys/at_cmd_set \
     -s samples.subsys.at_cmd_set.atm.pytest \
     --device-testing --device-serial <PORT> \
     --device-flash-timeout=240 \
     --west-flash="--device=<DEVICE_ID>,--jlink,--erase_flash,--fast_load" \
     -c -v

Two-port mode (separate port for AT commands):

.. code-block:: bash

   west twister -p <BOARD> -T openair/samples/subsys/at_cmd_set \
     -s samples.subsys.at_cmd_set.atm.pytest \
     --device-testing --device-serial <CONSOLE_PORT> \
     --device-flash-timeout=240 \
     --west-flash="--device=<DEVICE_ID>,--jlink,--erase_flash,--fast_load" \
     --pytest-args="--at-cmd-serial=<AT_CMD_PORT>" \
     -c -v

Pytest command-line options:

.. list-table::
   :header-rows: 1
   :widths: 35 15 50

   * - Option
     - Default
     - Description
   * - ``--cmd-timeout <sec>``
     - ``5.0``
     - Timeout for individual AT command responses.
   * - ``--at-cmd-serial <port>``
     - (none)
     - Separate serial port for AT commands (two-port mode).
   * - ``--at-cmd-baud <rate>``
     - ``115200``
     - Baud rate for the AT command serial port.
   * - ``-T`` / ``--adv-timeout <sec>``
     - ``60``
     - Time to wait while advertising before disabling (adv tests).

On a successful boot the console prints:

.. code-block:: none

   BLE AT Command Sample
   Bluetooth initialized
   Ready for AT commands (use AT+LISTCMDS? to list commands)
